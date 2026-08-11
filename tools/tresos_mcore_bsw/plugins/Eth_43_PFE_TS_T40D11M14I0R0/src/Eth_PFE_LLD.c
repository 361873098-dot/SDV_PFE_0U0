/**
*   @file    Eth_PFE_LLD.c
*
*    @brief            Interface between MCAL Eth driver layers and common platform driver for PFE.
*
*   @addtogroup ETH_43_PFE_DRIVER
*   @{
*/
/*==================================================================================================
 *  Project              : AUTOSAR 4.4 MCAL
 *  Platform             : CORTEXM
 *  Peripheral           : PFE
 *  Dependencies         : none
 *
 *  Autosar Version      : 4.4.0
 *  Autosar Revision     : ASR_REL_4_4_REV_0000
 *  Autosar Conf.Variant :
 *  SW Version           : 1.4.0
 *  Build Version        : PFE-DRV_S32G_M7_MCAL_1.4.0_D2405_ASR_REL_4_4_REV_0000_20240528
 *
 *  (c) Copyright 2006-2016 Freescale Semiconductor, Inc.
 *      Copyright 2017-2024 NXP
 *
 *  NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only
 *  be used strictly in accordance with the applicable license terms. By
 *  expressly accepting such terms or by downloading, installing, activating
 *  and/or otherwise using the software, you are agreeing that you have read,
 *  and that you agree to comply with and are bound by, such license terms. If
 *  you do not agree to be bound by the applicable license terms, then you may
 *  not retain, install, activate or otherwise use the software.
 *  <<< PFE Restricted Software >>>
 *
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43140440

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "pfe_cfg.h"
#include "Eth_43_PFE.h" /* Includes also Eth_GeneralTypes.h, Eth_43_PFE_Cfg.h,
                    Eth_43_PFE_ComStack_Types.h, Dem.h, Det.h and Mcal.h */
#include "SchM_Eth_43_PFE.h" /* RTE module header for critical sections protection */

#include "oal.h"
#include "pfe_hif_drv.h"
#include "pfe_hif.h"
#include "pfe_idex.h"
#include "Eth_PFE_LLD.h" /* Own interface */

#include "pfe_platform_cfg.h"
#include "pfe_platform.h" /* Platform driver, includes also all other headers
                             needed for platform driver. */
/* Note Soc_Ips.h is included through Reg_eSys.h - Mcal.h - Eth_43_PFE_Cfg.h - Eth_43_PFE.h */
#include "EthIf_Cbk.h" /* EthIf callbacks to be called from Eth driver */
#include "pfe_hm.h"
#include "pfe_cbus.h"
#include "pfe_emac_csr.h"
#include "pfe_hif_csr.h"
#include "pfe_tmu_csr.h"
#include "pfe_gpi_csr.h"
#include "pfe_bmu_csr.h"
#include "pfe_global_wsp.h"

#if (STD_ON == ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API)
    #include "EthSwt.h"
#endif /* ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ETH_AR_RELEASE_MAJOR_VERSION_C       4
#define ETH_AR_RELEASE_MINOR_VERSION_C       4

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StdRegMacros header file are of the same version */
    #if ((ETH_AR_RELEASE_MAJOR_VERSION_C != ETHIF_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_AR_RELEASE_MINOR_VERSION_C != ETHIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Eth_PFE_LLD.c and EthIf_Cbk.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define DRIVER_COMMIT_HASH      "de2c81ee44965bc3e6b284051ea0c292aceadbb0"
#define PFE_DRIVER_VERSION      "1.4.0"

/*Size of a descriptor*/
#define HIF_HEADER_SIZE 16U
#define IS_POWER_OF_2(n) ((n) && !((n) & ((n) - 1U)))

/* S32 GPR registers*/
#define S32G_GPR_BASE                   (0x4007CA00U)
#define PFE_EMACX_INTF_SEL_OFF          (0x4U)
#define PFE_EMACX_SET(emac, intf)       ((intf) << (4U * (emac)))

#define PFE_EMAC_SGMII                  (0U)    /* GMII to Serdes PHY */
#define PFE_EMAC_MII                    (1U)    /* MII to PADs */
#define PFE_EMAC_RGMII                  (2U)    /* RGMII to PADs */
#define PFE_EMAC_RMII                   (9U)    /* RMII to PADs */
#define PFE_INGRESS_MAX_FRAME_SIZE      (1518U) /* Ingress max frame size without vlan tag */

#define HIF_INT_SRC_HIF_ERR_INT             (1UL << 16U)
#define HIF_INT_SRC_HIF_TX_FIFO_ERR_INT     (1UL << 17U)
#define HIF_INT_SRC_HIF_RX_FIFO_ERR_INT     (1UL << 18U)

/*Macros to access to the register MC_ME*/
#ifndef MC_ME_BASE
    #define MC_ME_BASE                0x40088000U
#endif

#ifndef MC_ME_PRTN2_STAT
    #define MC_ME_PRTN2_STAT          0x508U
#endif

#ifndef MC_ME_PRTN_STAT_PCS
    #define MC_ME_PRTN_STAT_PCS       (1U << 0)
#endif

#define MAX_Q_SIZE              (31U)
#define SCH0_ID                 (0U)
#define SCH1_ID                 (1U)
/* Position 9-16 correspond to input 0-7 of Scheduler 0 */
#define SHP_POS_COR_SCH0        {9U, 10U, 11U, 12U, 13U, 14U, 15U, 16U}
/* Position 1-8 correspond to input 0-7 of Scheduler 1 */
#define SHP_POS_COR_SCH1        {1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U}

#if (STD_ON == ETH_43_PFE_DEM_EVENT_DETECT)
#define MAX_DEM_FRAME_ERRORS    (ETH_43_PFE_NUMBER_OF_DEM_IDS)
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */

#if (STD_ON == ETH_43_PFE_ENABLE_USER_MODE_SUPPORT)
    #define Local_Macro_hal_ip_ready_set(on)    OsIf_Trusted_Call1param(hal_ip_ready_set, (on))
    #define Local_Macro_hal_ip_ready_get()      OsIf_Trusted_Call_Return(hal_ip_ready_get)
#else
    #define Local_Macro_hal_ip_ready_set(on)    hal_ip_ready_set(on)
    #define Local_Macro_hal_ip_ready_get()      hal_ip_ready_get()
#endif

#define INVALID_TX_INDEX 0xFFFFU

/* Buffer status, WAIT_CONF, WAIT_TS and TO_REPORT can be set simultaneously (as in bitfield) */
#define TX_BUF_FREE         0U
#define TX_BUF_PROVIDED     1U
#define TX_BUF_FAILED       2U
#define TX_BUF_WAIT_CONF    4U
#define TX_BUF_WAIT_TS      8U
#define TX_BUF_TO_REPORT    16U

/* Temporary workaround for AAVB-8200 until AAVB-4234 is implemented in FW */
#define IS_RECEIVE_MALFORMED_ALLOWED  ((ETH_43_PFE_ENABLE_OFFLOAD_CSUM_IPV4 != STD_ON) \
                                    || (ETH_43_PFE_ENABLE_OFFLOAD_CSUM_TCP  != STD_ON) \
                                    || (ETH_43_PFE_ENABLE_OFFLOAD_CSUM_UDP  != STD_ON) \
                                    || (ETH_43_PFE_ENABLE_OFFLOAD_CSUM_ICMP != STD_ON))

#define ETHERTYPE_IPV4 0x0800U
#define ETHERTYPE_IPV6 0x86DDU
#define ETH_FRAME_MACDST_IDX     0U
#define ETH_FRAME_MACSRC_IDX     6U
#define ETH_FRAME_ETHERTYPE_IDX 12U
#define ETH_FRAME_PAYLOAD_IDX   14U
#define ETH_FRAME_VLANTAG_LEN_MAX 8U
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#ifdef PFE_CFG_PFE_MASTER
/* data shared to ConfigureSchedulerAndShaper callees */
typedef struct 
{
    pfe_ct_phy_if_id_t emac_id;
    const Eth_43_PFE_CtrlCfgType *pcfg;
    boolean is_queue_used[TLITE_PHY_QUEUES_CNT];
    boolean is_input_used[TLITE_SCH_CNT][TLITE_SCH_INPUTS_CNT];
} ConfigureSchedulerAndShaper_StateType;
#endif

/*  This is the driver representation of PFE device */
typedef struct
{
    boolean                 bStarted;
    uint8                   u8CtrlIdx;
    pfe_platform_t          *prPlatform;
    pfe_hif_drv_t           *prHifDrv;
    pfe_hif_chnl_t          *prHifChnl;
    pfe_ct_phy_if_id_t      HifId;
    oal_irq_t               *prHifChnlIRQ;
    pfe_phy_if_t            *prPhyIf;
    pfe_hif_drv_client_t    *prClient;
    pfe_mac_addr_t          au8MacAddr;
    boolean                 bInterfacePrepared;
#if (STD_ON == ETH_43_PFE_GLOBALTIME_SUPPORT)
    Eth_BufIdxType          TSQueue[ETH_43_PFE_MAX_TXFIFO_CNT][ETH_43_PFE_MAX_FIFO_TX_BUF_CNT];
    uint16                  u16TSQueueRead[ETH_43_PFE_MAX_TXFIFO_CNT];
    uint16                  u16TSQueueWrite[ETH_43_PFE_MAX_TXFIFO_CNT];
#endif
} trPfeDev;

typedef struct
{
    addr_t Addr;           /* Where the pool starts in memory */
    uint32 u32Size;        /* Size of the pool in memory */
    uint32 u32BufSize;
    uint16 u16BufNumber;
    uint16 u16IndexOffset; /* Offset between index within this pool and index within controller */
    uint16 u16GetIdx;      /* Where to look for next free buffer (index within this pool) */
} trTxBufPool;

typedef struct
{
    addr_t                  BufAddr;
    uint8                   u8Status;
    uint8                   u8Fifo;
    trTxMeta                rMeta;
#if (STD_ON == ETH_43_PFE_GLOBALTIME_SUPPORT)
    Eth_PFE_LLD_trTxTsRef   rTsRef;
    Eth_TimeStampQualType   TimeQual;
    Eth_TimeStampType       TimeStamp;
#endif
} trTxBufControl;

#if (STD_ON == ETH_43_PFE_DEM_EVENT_DETECT)
typedef enum
{
    ETH_43_PFE_E_RX_FRAMES_LOST    = 0U,
    ETH_43_PFE_E_CRC               = 1U,
    ETH_43_PFE_E_UNDERSIZEFRAME    = 2U,
    ETH_43_PFE_E_OVERSIZEFRAME     = 3U,
    ETH_43_PFE_E_ALIGNMENT         = 4U,
    ETH_43_PFE_E_SINGLECOLLISION   = 5U,
    ETH_43_PFE_E_MULTIPLECOLLISION = 6U,
    ETH_43_PFE_E_LATECOLLISION     = 7U,
    ETH_43_PFE_NUMBER_OF_DEM_IDS   = 8U
} ErrorIdType;
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */

/*==================================================================================================
*                                     GLOBAL VARIABLES
==================================================================================================*/
#if ((TRUE == PFE_CFG_HIF_IRQ_ENABLED) || (TRUE == PFE_CFG_BMU_IRQ_ENABLED))
/*  Used in ISRs to check whether interrupts were initialized and can be executed.
    The value is based on driver init/deinint progress:
      - in single instance (or master) mode it is set when driver initialization is done
        (just before master-up flag is set),
      - in slave mode it is set after hif driver is initialized, before RPC is needed. 
      - In all modes the value is cleared before the hif driver is destroyed .*/
volatile boolean Eth_PFE_LLD_bIrqInitStatus = FALSE;
#endif

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#if (STD_ON == ETH_43_PFE_DEM_EVENT_DETECT)
#define ETH_43_PFE_START_SEC_CONST_32
#include "Eth_43_PFE_MemMap.h"
static const uint32 u32StatId[MAX_DEM_FRAME_ERRORS] =
{
    RX_FIFO_OVERFLOW_PACKETS,
    RX_CRC_ERROR_PACKETS,
    RX_UNDERSIZE_PACKETS_GOOD,
    RX_OVERSIZE_PACKETS_GOOD,
    RX_ALIGNMENT_ERROR_PACKETS,
    TX_SINGLE_COLLISION_GOOD_PACKETS,
    TX_MULTIPLE_COLLISION_GOOD_PACKETS,
    TX_LATE_COLLISION_PACKETS
};
#define ETH_43_PFE_STOP_SEC_CONST_32
#include "Eth_43_PFE_MemMap.h"
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */

/*==================================================================================================
*                                        LOCAL VARIABLES
==================================================================================================*/
#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED_BUF_MEM
#include "Eth_43_PFE_MemMap.h"

/*  It should be static, but it is not to avoid issues with memory mapping in some compilers */
VAR_ALIGN(uint8 auTxBufMem[ETH_43_PFE_MAX_TXBUF_POOLSZ], 8U)

#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_BUF_MEM
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

/*  Describes buffer memory split to fifos and buffers */
static trTxBufPool aarTxBufPool[ETH_43_PFE_MAXCTRLS_SUPPORTED][ETH_43_PFE_MAX_TXFIFO_CNT];

/*  All runtime information about buffers is collected in this table.
    It is indexed by controller index and buffer index.
    Function Eth_PFE_LLD_ProvideBufferDataArea should get buf index range
    from aarTxBufPool and then search this table for free buffer. */
static trTxBufControl aarTxBuf[ETH_43_PFE_MAXCTRLS_SUPPORTED][ETH_43_PFE_MAX_CTRL_TX_BUF_CNT];

/*  Written sequentially by Transmit, readed sequentially by TxConfirmation
    (releasing based on confirmation from BD, not waiting for timestamps).
    Transmit function will pass pointer to record from this queue as ref_ptr,
    that is why we need to store also the u8CtrlIdx here.  */
Eth_PFE_LLD_trTxRefData arTxReqQueue[ETH_43_PFE_MAXCTRLS_SUPPORTED][ETH_43_PFE_MAX_CTRL_TX_BUF_CNT];

#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_VAR_CLEARED_16
#include "Eth_43_PFE_MemMap.h"

uint16 u16TxQueueWrite[ETH_43_PFE_MAXCTRLS_SUPPORTED]; /* Increment only in Transmit */
uint16 u16TxQueueRead[ETH_43_PFE_MAXCTRLS_SUPPORTED];  /* Increment only in TxConf */

#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_16
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_VAR_INIT_32
#include "Eth_43_PFE_MemMap.h"

/*  Driver objects common for all interfaces (for all pfe_drv instances) */
static pfe_platform_t *ptrPlatform = NULL_PTR;

#define ETH_43_PFE_STOP_SEC_VAR_INIT_32
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

static pfe_platform_config_t rPlatformCfg =
{
    .cbus_base = PFE_CFG_CBUS_PHYS_BASE_ADDR_CPU,       /* PFE control bus base address */
    .cbus_len = PFE_CFG_CBUS_LENGTH,                    /* PFE control bus size */
    .fw_name = NULL_PTR,
    .fw = NULL_PTR,                                     /* Required firmware, embedded */
    .common_irq_mode = FALSE,                           /* True if FPGA specific common irq is used */
#if (TRUE == PFE_CFG_BMU_IRQ_ENABLED)
    .irq_vector_bmu = 194U,                             /* BMU IRQ number */
#endif /* PFE_CFG_BMU_IRQ_ENABLED */
#ifdef PFE_CFG_HIF_NOCPY_SUPPORT
    .hif_chnls_mask = (pfe_hif_chnl_id_t)HIF_CHNL_INVALID,
#else
    .hif_chnls_mask = (pfe_hif_chnl_id_t)(1U << (ETH_43_PFE_COMMON_HIF - PFE_PHY_IF_ID_HIF0)),
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
    .hif_fci_owner_chnls_mask = FCI_OWNER_HIF_INVALID,
    .master_if = PFE_CFG_MASTER_IF,
#endif
    .irq_vector_hif_chnls = {190U, 191U, 192U, 193U},   /* HIF channels IRQ number */
    .irq_vector_hif_nocpy = 195U,                       /* HIF nocopy channel IRQ number */
    .irq_vector_upe_gpt = 0U,
    .irq_vector_safety = 0U,
    .enable_util = FALSE,
    .disable_master_detect = FALSE,
    .local_hif = PFE_PHY_IF_ID_INVALID,                  /* Will be set at runtime */
#if defined(PFE_CFG_RTABLE_ENABLE)
    .rtable_hash_size = PFE_CFG_RT_HASH_SIZE,
    .rtable_collision_size = PFE_CFG_RT_COLLISION_SIZE,
#endif /* PFE_CFG_RTABLE_ENABLE */
    .vlan_id = 0U,
    .vlan_stats_size = 0U,
    .emac_mode = {EMAC_MODE_INVALID, EMAC_MODE_INVALID, EMAC_MODE_INVALID},
    .commit_hash = DRIVER_COMMIT_HASH,
    .driver_version = PFE_DRIVER_VERSION
};

#define ETH_43_PFE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_VAR_INIT_32
#include "Eth_43_PFE_MemMap.h"

static pfe_hif_chnl_t *prCommonHifChnl = NULL_PTR;
static oal_irq_t *prCommonChnlIRQ = NULL_PTR;
static pfe_hif_drv_t *prCommonHifDrv = NULL_PTR;

#ifdef PFE_CFG_RTABLE_ENABLE
/* usage scope: Eth_PFE_LLD_MainFunction */
/* Routing table timer ticks, used for rtable entries timeout update */
static uint32 u32RtrTimeoutTimeMs = 0U;
#endif /* PFE_CFG_RTABLE_ENABLE */

#define ETH_43_PFE_STOP_SEC_VAR_INIT_32
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

/*  All PFE driver interfaces */
static trPfeDev arPfeInterface[ETH_43_PFE_MAXCTRLS_SUPPORTED];

/**
* @brief         Mode of the ETH controllers
* @details       Stores the last known mode of the ETH controller.
*                Used in "Eth_MainFunction" to track mode changes and report them back to EthIf.
*                Only "Eth_SetControllerMode" can trigger mode changes.
*/
static Eth_ModeType eSavedMode[ETH_43_PFE_MAXCTRLS_SUPPORTED];

#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_VAR_INIT_BOOLEAN
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_STOP_SEC_VAR_INIT_BOOLEAN
#include "Eth_43_PFE_MemMap.h"

#if (STD_ON == ETH_43_PFE_DEM_EVENT_DETECT)
#define ETH_43_PFE_START_SEC_VAR_CLEARED_32
#include "Eth_43_PFE_MemMap.h"
static uint32 u32DemErrorCounters[ETH_43_PFE_MAXCTRLS_SUPPORTED][MAX_DEM_FRAME_ERRORS];
#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_32
#include "Eth_43_PFE_MemMap.h"
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

static Std_ReturnType UpdatePhysAddrFilter_AddBroad(const trPfeDev *prPfeDev);
static Std_ReturnType UpdatePhysAddrFilter_RemoveBroad(const trPfeDev *prPfeDev);
static Std_ReturnType UpdatePhysAddrFilter_Close(const trPfeDev *prPfeDev);
static Std_ReturnType UpdatePhysAddrFilter_AddMulti(const trPfeDev *prPfeDev, const uint8 * PhysAddrPtr);
static Std_ReturnType UpdatePhysAddrFilter_RemoveMulti(const trPfeDev *prPfeDev, const uint8 *PhysAddrPtr);

static uint8 ReportReception_GetBypassVLANTag(Eth_FrameType FrameType);
static void ReportReception_ProcessPacket(uint8 u8CtrlIdx, uint8 u8FifoIdx, const pfe_hif_pkt_t *RxPacket);
static boolean IsRxChecksumValidIpV4(const pfe_hif_pkt_t *RxPacket, uint8 Protocol);
static boolean IsRxChecksumValidIpV6(const pfe_hif_pkt_t *RxPacket, uint8 Protocol);
static boolean IsRxChecksumValid(const pfe_hif_pkt_t *RxPacket, const uint8 *pEtherType);

static void ClientEventHdlr_RX(uint8 u8ClientIdx, uint8 u8QueueIdx);
static void ClientEventHdlr_TX(uint8 u8ClientIdx, uint8 u8QueueIdx);
#if (STD_ON == ETH_43_PFE_GLOBALTIME_SUPPORT)
static void ClientEventHdlr_ETS(uint8 u8ClientIdx, uint8 u8QueueIdx);
#endif
static errno_t ClientEventHdlr
(
    pfe_hif_drv_client_t *prClient,
    void *pvArg,
    uint32 u32Event,
    uint32 u32QueueIdx
);
static void DestroyHifDrv(oal_irq_t *prIRQ, pfe_hif_drv_t *prHifDrv);
#if defined(PFE_CFG_PFE_MASTER) && IS_RECEIVE_MALFORMED_ALLOWED
static Std_ReturnType PlatformDrvPrepare_EnRxMalformed(void);
#endif
static Std_ReturnType PlatformDrvPrepare_EnablePhyIf(void);
static Std_ReturnType PlatformDrvPrepare_ShutdownConfigInit(void);

#if (STD_ON == ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API)
static Std_ReturnType TxReqSwt(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx, uint8 *dataPtr, uint16 *pLength);
#endif

#ifdef PFE_CFG_PFE_SLAVE
static Std_ReturnType PlatformDrvPrepare_SlaveWaitForIpReady(void);
#endif
static Std_ReturnType ConfigureTxBuffers(void);
#ifndef PFE_CFG_HIF_NOCPY_SUPPORT
static errno_t InitializeTxHeaders(const uint8 u8CtrlIdx, pfe_hif_drv_client_t *client);
#endif
static boolean GetTxBuffer(const uint8 u8CtrlIdx, const uint8 u8FifoIdx, Eth_BufIdxType * const pBufIdx);
static void ReleaseTxBuffer(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx);
static void ReleaseAllCtrlTxBuffers(const uint8 u8CtrlIdx);
static void *TxReqQueueWrite(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx);
static Eth_PFE_LLD_trTxRefData *TxReqQueueRead(const uint8 u8CtrlIdx);
static void TxReqQueueDelete(const uint8 u8CtrlIdx);
static errno_t TxReqTrigger(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx, uint16 Length);
static void TxReqFailed(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx);
#if (STD_ON == ETH_43_PFE_GLOBALTIME_SUPPORT)
static void TxReqTsQueueWrite(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx);
static void InterfacePrepare_InitTSQueue(trPfeDev *prPfeDev);
static Std_ReturnType EmacTsAdjustRatio(uint8 u8CtrlIdx, pfe_emac_t *prEmac, const Eth_RateRatioType *pRateRatioPtr);
static errno_t GetTxTimeStamp
(
    uint8 u8CtrlIdx,
    Eth_BufIdxType BufIdx,
    Eth_TimeStampQualType *timeQualPtr,
    Eth_TimeStampType *timeStampPtr
);
#endif
#if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
static bool_t  CommonHifChnlISR(void *arg);
#endif /* PFE_CFG_HIF_IRQ_ENABLED */
static boolean CreateHifDrv(pfe_ct_phy_if_id_t HifId, uint32 u32IrqVector, pfe_hif_chnl_t **pprHifChnl, oal_irq_t **pprIRQ, pfe_hif_drv_t **pprHifDrv);
static pfe_hif_drv_t* CreateHifDrv_Init(pfe_hif_chnl_t *prHifChnl, oal_irq_t * prIRQ);
#if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
static oal_irq_t* CreateHifDrv_Isr(uint32 u32IrqVector, pfe_hif_chnl_t *prHifChnl);
#endif
#ifdef PFE_CFG_PFE_MASTER
static errno_t ConfigureSchedulerAndShaper(uint8 u8CtrlIdx);
static errno_t ConfigureSchedulerAndShaper_MapUnusedInputs(ConfigureSchedulerAndShaper_StateType *pstate, uint8 u8SchIdx);
static errno_t ConfigureSchedulerAndShaper_SetRateModeAlgo(const ConfigureSchedulerAndShaper_StateType *pstate, uint8 u8SchIdx, const Eth_43_PFE_SchedulerCfgType *pSch);
static errno_t ConfigureSchedulerAndShaper_SetSchedulerInput(ConfigureSchedulerAndShaper_StateType *pstate, uint8 u8SchIdx, const Eth_43_PFE_SchedulerCfgType *pSch, const Eth_43_PFE_SchedulerInputInfoCfgType *pSchInput);
static errno_t ConfigureSchedulerAndShaper_SetShaper(ConfigureSchedulerAndShaper_StateType *pstate, uint8 u8SchIdx, const Eth_43_PFE_SchedulerInputInfoCfgType *pSchInput);
static errno_t ConfigureSchedulerAndShaper_SetFifo(ConfigureSchedulerAndShaper_StateType *pstate, uint8 u8SchIdx, const Eth_43_PFE_SchedulerInputInfoCfgType *pSchInput, uint8 u8FifoIdx);
static errno_t Eth_PFE_LLD_EMACPrepare_Config(const pfe_phy_if_t *prEmac, const Eth_43_PFE_EmacCfg *pEmacCfg);
static errno_t InterfacePrepare_MasterConfigEMAC(const trPfeDev *prPfeDev);
static errno_t InterfacePrepare_InitEmacMasterRx(const trPfeDev *prPfeDev);
static errno_t InterfacePrepare_InitEmacMasterLink(const trPfeDev *prPfeDev);
#else
static errno_t InterfacePrepare_SlaveConfigEMAC(const trPfeDev *prPfeDev);
#endif /* PFE_CFG_PFE_MASTER */
static boolean EnableController_Aux(trPfeDev *prPfeDev, pfe_hif_drv_client_rx_tx_count *pclient_queue, pfe_hif_drv_client_fifo_queue *pclient_fifo_queue);
static boolean EnableController_HifEmac(trPfeDev *prPfeDev, pfe_hif_drv_client_rx_tx_count *pclient_queue, pfe_hif_drv_client_fifo_queue *pclient_fifo_queue);
static boolean EnableController_Common(const trPfeDev *prPfeDev);

#if (STD_ON == ETH_43_PFE_DEM_EVENT_DETECT)
static boolean DetectErrorsAndLostFrame(uint8 u8CtrlIdx, ErrorIdType errorId);
static void CheckDemStatus(uint8 u8CtrlIdx, uint32 demConfig, ErrorIdType errorId, uint32 demId);
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */
static void Eth_PFE_LLD_ResetGlobalVar(void);
static boolean Eth_PFE_LLD_DetectHardReset(void);
static void Eth_PFE_LLD_ShutdownDriver(void);
#if (STD_ON == ETH_43_GET_COUNTER_API) || \
    (STD_ON == ETH_43_PFE_DEM_EVENT_DETECT) || \
    (STD_ON == ETH_43_GET_RXSTATS_API) || \
    (STD_ON == ETH_43_GET_TXSTATS_API) || \
    (STD_ON == ETH_43_GET_TXERROR_COUNTER_API)
static pfe_emac_t *Eth_PFE_LLD_GetEmacInstanceByControllerId(uint8 u8CtrlIdx);
#endif
#if (STD_ON == ETH_43_PFE_CHANNEL_BD_FLUSH_API) && defined(PFE_CFG_PFE_MASTER)
static Std_ReturnType ChannelBdFlushRxPrepare(pfe_ct_phy_if_id_t DestHifChnl);
static Std_ReturnType ChannelBdFlushRxExecute(pfe_ct_phy_if_id_t DestHifChnl);
#endif /*(STD_ON == ETH_43_PFE_CHANNEL_BD_FLUSH_API) && defined(PFE_CFG_PFE_MASTER)*/

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/

#if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
/**
 * @brief        Common HIF channel interrupt service routine
 * @details      Manage common HIF channel interrupt. Always runs in a thread context.
 * @details      See the oal_irq_handler_t
 */
static bool_t  CommonHifChnlISR(void *arg)
{
    pfe_hif_chnl_t *chnl = (pfe_hif_chnl_t *)arg;
    bool_t handled = FALSE;

    /*    Disable HIF channel interrupts */
    pfe_hif_chnl_irq_mask(chnl);

    /*    Call HIF channel ISR */
    if (EOK == pfe_hif_chnl_isr(chnl))
    {
        handled = TRUE;
    }

    /*    Re-enable HIF channel IRQ */
    pfe_hif_chnl_irq_unmask(chnl);

    return handled;
}
#endif /* PFE_CFG_HIF_IRQ_ENABLED */

/*  Auxiliary function to create and initialize HIF driver */
static pfe_hif_drv_t* CreateHifDrv_Init(pfe_hif_chnl_t *prHifChnl, oal_irq_t * prIRQ)
{
    pfe_hif_drv_t *result = NULL_PTR;
    pfe_hif_drv_t *prHifDrv = pfe_hif_drv_create(prHifChnl);

    if (NULL_PTR == prHifDrv)
    {
        NXP_LOG_ERROR("Could not get HIF driver instance\n");
    }
    else if (EOK != pfe_hif_drv_init(prHifDrv))
    {
        NXP_LOG_ERROR("pfe_hif_drv_init() failed\n");
    }
#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
#if (defined(PFE_CFG_PFE_SLAVE) && (TRUE == PFE_CFG_HIF_IRQ_ENABLED))
    else if(FALSE == (Eth_PFE_LLD_bIrqInitStatus = TRUE))
    {   /* ^^^ This is to keep the flow and set Eth_PFE_LLD_bIrqInitStatus=TRUE at the very last place just before issuing a very first IDEX RPC command */
        ;
    }
#endif
    /*  We need to start here to be able to configure master
        during initialization */
    else if (EOK != pfe_hif_drv_start(prHifDrv))
    {
        NXP_LOG_ERROR("HIF driver start failed\n");
    }
    else if (EOK != pfe_idex_init(prHifDrv, rPlatformCfg.master_if, ptrPlatform->hif, &pfe_platform_idex_rpc_cbk, (void *)ptrPlatform, NULL_PTR))
    {
        NXP_LOG_ERROR("Can't initialize IDEX\n");
    }
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */
    else
    {
        result = prHifDrv;
    }

    if(result == NULL_PTR) 
    {
        DestroyHifDrv(prIRQ, prHifDrv);
    }

    return result;
}

#if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
/*  Auxiliary function to register an ISR handler */
static oal_irq_t* CreateHifDrv_Isr(uint32 u32IrqVector, pfe_hif_chnl_t *prHifChnl)
{
    oal_irq_t * prIRQ;
    PfeDevAssert(u32IrqVector <= INT32_MAX);
    prIRQ = oal_irq_create(
                (int32_t)u32IrqVector,
                (oal_irq_flags_t)0,
                NULL_PTR /* irq name is unused in oal_irq_create */
                );

    if (NULL_PTR == prIRQ)
    {
        NXP_LOG_ERROR("Could not create HIF IRQ\n");
    }
    /*  Install IRQ handler */
    else
    {
        if (EOK != oal_irq_add_handler(prIRQ, (oal_irq_handler_t)&CommonHifChnlISR, prHifChnl, NULL_PTR))
        {
            NXP_LOG_ERROR("Could not add IRQ handler\n");
            oal_irq_destroy(prIRQ);
            prIRQ = NULL_PTR;
        }
    }

    return prIRQ;
}
#endif

/*  Auxiliary function to get hif chnl, interrupt and drv */
static boolean CreateHifDrv(pfe_ct_phy_if_id_t HifId, uint32 u32IrqVector, pfe_hif_chnl_t **pprHifChnl, oal_irq_t **pprIRQ, pfe_hif_drv_t **pprHifDrv)
{
    boolean bRetVal = FALSE;
    pfe_hif_chnl_t *prHifChnl;
    pfe_hif_drv_t *prHifDrv = NULL_PTR;
    oal_irq_t *prIRQ = NULL_PTR;

    /*  Get HIF channel. This one will be common for all logical interfaces. */
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
    if (HifId == PFE_PHY_IF_ID_HIF_NOCPY)
    {
        prHifChnl = pfe_hif_nocpy_get_channel(ptrPlatform->hif_nocpy, PFE_HIF_CHNL_NOCPY_ID);
    }
    else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
    {
        prHifChnl = pfe_hif_get_channel(ptrPlatform->hif, pfe_hif_chnl_from_phy_id(HifId));
    }

    if (NULL_PTR == prHifChnl)
    {
        NXP_LOG_ERROR("Can't get HIF channel instance\n");
    }
    else
    {
#if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
        prIRQ = CreateHifDrv_Isr(u32IrqVector, prHifChnl);
        if(NULL_PTR != prIRQ)
#else
        (void)u32IrqVector;
#endif /* PFE_CFG_HIF_IRQ_ENABLED */
        {
            /*  Create HIF driver for the channel */
            prHifDrv = CreateHifDrv_Init(prHifChnl, prIRQ);
            if(NULL_PTR != prHifDrv)
            {
                /*  Now particular channel interrupt source can be enabled */
                /*  Everything is OK */
#if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
                pfe_hif_chnl_irq_unmask(prHifChnl);
                *pprIRQ = prIRQ;
#else
                (void)pprIRQ;
#endif
                *pprHifChnl = prHifChnl;
                *pprHifDrv = prHifDrv;
                bRetVal = TRUE;
            }
        }
    }

    return bRetVal;
}

/*  Auxiliary function to destroy hif interrupt and drv */
static void DestroyHifDrv(oal_irq_t *prIRQ, pfe_hif_drv_t *prHifDrv)
{
    if (NULL_PTR != prHifDrv)
    {
#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
        pfe_idex_fini();
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */
        pfe_hif_drv_destroy(prHifDrv);
    }
#if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
    if (NULL_PTR != prIRQ)
    {
        oal_irq_destroy(prIRQ);
    }
#else
    (void)prIRQ;
#endif
    /* No need to destroy prHifChnl */
    return;
}

/*================================================================================================*/
/**
* @brief         Configures all transmit buffers
* @details       Based on selected configuration, this function splits the buffer memory
*                among all controllers and their Tx queues. It initializes one aarTxBufPool
*                structure for each queue, which can be used to get or return Tx buffers
*                and to calculate buffer address based on buffer index and vice versa.
*                The function initializes all aarTxBuf records as well.
*/
static Std_ReturnType ConfigureTxBuffers(void)
{
    Std_ReturnType RetVal = E_OK;
    trTxBufPool *prPool;
    addr_t Addr = (addr_t)&auTxBufMem;
    uint8 u8Ctrl;
    uint8 u8Fifo;
    uint16 u16Buff;
    uint8 u8NumFifo;
    uint16 u16IndexOffset;

    for (u8Ctrl = 0U; u8Ctrl < ETH_43_PFE_NUM_CONTROLLER_CFG; u8Ctrl++)
    {
        u16IndexOffset = 0U;
        u8NumFifo = Eth_43_PFE_InternalCfgPtr->pController[u8Ctrl]->EthCtrlEgressFifoCnt;
        for (u8Fifo = 0U; u8Fifo < u8NumFifo; u8Fifo++)
        {
            prPool = &aarTxBufPool[u8Ctrl][u8Fifo];
            prPool->Addr = Addr;
            prPool->u32BufSize =
                Eth_43_PFE_InternalCfgPtr->pController[u8Ctrl]->pEgressCfg[u8Fifo].EthCtrlConfigEgressFifoMemLenByte;
            prPool->u16BufNumber =
                Eth_43_PFE_InternalCfgPtr->pController[u8Ctrl]->pEgressCfg[u8Fifo].EthCtrlConfigEgressFifoBufTotal;
            prPool->u32Size = prPool->u32BufSize * prPool->u16BufNumber;
            prPool->u16IndexOffset = u16IndexOffset;
            prPool->u16GetIdx = 0U;
            PfeDevAssert(prPool->u32Size <= (UINT32_MAX - Addr));
            PfeDevAssert(prPool->u16BufNumber <= (UINT16_MAX - u16IndexOffset));
            /* Initialize aarTxBuf */
            for (u16Buff = 0U; u16Buff < prPool->u16BufNumber; u16Buff++)
            {
                aarTxBuf[u8Ctrl][u16Buff + u16IndexOffset].BufAddr = Addr + (prPool->u32BufSize * u16Buff);
                aarTxBuf[u8Ctrl][u16Buff + u16IndexOffset].u8Fifo = u8Fifo;
                aarTxBuf[u8Ctrl][u16Buff + u16IndexOffset].u8Status = TX_BUF_FREE;
            }
            Addr += prPool->u32Size;
            u16IndexOffset += prPool->u16BufNumber;
        }
        /* Initialize Tx request queue */
        for (u16Buff = 0U; u16Buff < ETH_43_PFE_MAX_CTRL_TX_BUF_CNT; u16Buff++)
        {
            arTxReqQueue[u8Ctrl][u16Buff].u8CtrlIdx = u8Ctrl;
            arTxReqQueue[u8Ctrl][u16Buff].u16BufIdx = INVALID_TX_INDEX;
        }
        u16TxQueueWrite[u8Ctrl] = 0U;
        u16TxQueueRead[u8Ctrl] = 0U;
    }
    return RetVal;
}

#ifndef PFE_CFG_HIF_NOCPY_SUPPORT
/**
* @brief         Configures all transmit Tx headers
* @details       This function initializes the Tx header at the beginning of each Tx buffer
* @param[in]     u8CtrlIdx Interface (controller) to be configured
* @param[in]     client Client Instance
* @retval        EOK if success, ENOENT otherwise
*/
static errno_t InitializeTxHeaders(const uint8 u8CtrlIdx, pfe_hif_drv_client_t *client)
{
    errno_t ret = EOK;
    boolean bFail = FALSE;
    trTxBufPool *prPool;
    uint8 u8Fifo;
    uint16 u16Buff;
    uint8 u8NumFifo;
    uint8 u8Queue;
    uint16 u16IndexOffset;
    pfe_ct_hif_tx_hdr_t *pTxHeader;

    u16IndexOffset = 0U;
    u8NumFifo = Eth_43_PFE_InternalCfgPtr->pController[u8CtrlIdx]->EthCtrlEgressFifoCnt;
    for (u8Fifo = 0U; u8Fifo < u8NumFifo; u8Fifo++)
    {
        prPool = &aarTxBufPool[u8CtrlIdx][u8Fifo];
        PfeDevAssert(u16IndexOffset <= (UINT16_MAX - prPool->u16BufNumber));
        for (u16Buff = 0U; u16Buff < prPool->u16BufNumber; u16Buff++)
        {
            pTxHeader = (pfe_ct_hif_tx_hdr_t *)aarTxBuf[u8CtrlIdx][u16Buff + u16IndexOffset].BufAddr;
            u8Queue = aarTxBuf[u8CtrlIdx][u16Buff + u16IndexOffset].u8Fifo;
            ret = pfe_hif_drv_init_tx_header(client, pTxHeader, u8Queue);
            if (EOK != ret)
            {
                bFail = TRUE;
            }
        }
        u16IndexOffset += prPool->u16BufNumber;
    }
    if (TRUE == bFail)
    {
        ret = ENOENT;
    }

    return ret;
}
#endif
/*================================================================================================*/
/* Searches one free buf control record (and for NOCPY also gets buffer from BMU) */
static boolean GetTxBuffer(const uint8 u8CtrlIdx, const uint8 u8FifoIdx, Eth_BufIdxType * const pBufIdx)
{
    boolean bFound = FALSE;
    trTxBufPool *const prBufPool = &aarTxBufPool[u8CtrlIdx][u8FifoIdx];
    const uint16 u16IdxOff = prBufPool->u16IndexOffset;
    const uint16 u16BufNum = prBufPool->u16BufNumber;
    uint16 u16Idx = prBufPool->u16GetIdx;
    PfeDevAssert(u16BufNum != 0u);

    do /* Search for a free buffer control record */
    {
        const Eth_BufIdxType bufIdx = (uint32)u16Idx + u16IdxOff;
        PfeDevAssert(bufIdx < ETH_43_PFE_MAX_CTRL_TX_BUF_CNT);
        if (TX_BUF_FREE == aarTxBuf[u8CtrlIdx][bufIdx].u8Status)
        {
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
            /* Try to get buffer from BMU */
            aarTxBuf[u8CtrlIdx][bufIdx].BufAddr =
                        (addr_t)pfe_hif_chnl_bmu_alloc_buf_va(arPfeInterface[u8CtrlIdx].prHifChnl);
            if (NULL_ADDR != aarTxBuf[u8CtrlIdx][bufIdx].BufAddr)
#endif
            {
                /* Success */
                aarTxBuf[u8CtrlIdx][bufIdx].u8Status = TX_BUF_PROVIDED;
                *pBufIdx = bufIdx;
                bFound = TRUE;
                /* Update GetIdx */
                if (prBufPool->u16GetIdx == u16Idx)
                {
                    oal_mutex_lock(PFE_TX_BUFFER_POOL_MUTEX);
                    if (prBufPool->u16GetIdx >= (u16BufNum-1U))
                    {   /* wrap */
                        prBufPool->u16GetIdx = 0U;
                    }
                    else
                    {
                        prBufPool->u16GetIdx++;
                    }
                    oal_mutex_unlock(PFE_TX_BUFFER_POOL_MUTEX);
                }
            }
            break;
        }
        /* Search backwards to minimize out-of-order allocations and search time in future */
        if (0U == u16Idx)
        {
            u16Idx = u16BufNum;
        }
        u16Idx--;
    } while (u16Idx != prBufPool->u16GetIdx);

    return bFound;
}

/*================================================================================================*/
static void ReleaseTxBuffer(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx)
{
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        if (TX_BUF_PROVIDED == aarTxBuf[u8CtrlIdx][BufIdx].u8Status)
        {
            addr_t BufAddr = aarTxBuf[u8CtrlIdx][BufIdx].BufAddr;
            (void)pfe_hif_chnl_bmu_free_buf(arPfeInterface[u8CtrlIdx].prHifChnl, BufAddr);
        }
#endif
        aarTxBuf[u8CtrlIdx][BufIdx].u8Status = TX_BUF_FREE;
}

/*================================================================================================*/
static void ReleaseAllCtrlTxBuffers(const uint8 u8CtrlIdx)
{
    for(Eth_BufIdxType BufIdx = 0U; BufIdx < ETH_43_PFE_MAX_CTRL_TX_BUF_CNT; BufIdx++)
    {
        ReleaseTxBuffer(u8CtrlIdx, BufIdx);
    }
}

#if (STD_ON == ETH_43_PFE_GLOBALTIME_SUPPORT)
/*================================================================================================*/
static void TxReqTsQueueWrite(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx)
{            
    trPfeDev *prPfeDev = &arPfeInterface[u8CtrlIdx];
    uint8 u8FifoIdx = Eth_43_PFE_LLD_GetTxFifoIdx(u8CtrlIdx, BufIdx);

    oal_mutex_lock(PFE_TS_QUEUE_WRITE_MUTEX);
    /* Add this buffer to TS queue (no need to check if queue is full, there is always enough space) */
    prPfeDev->TSQueue[u8FifoIdx][prPfeDev->u16TSQueueWrite[u8FifoIdx]] = BufIdx;
    if(prPfeDev->u16TSQueueWrite[u8FifoIdx] >= (ETH_43_PFE_MAX_FIFO_TX_BUF_CNT - 1U))
    {   /* Wrap */
        prPfeDev->u16TSQueueWrite[u8FifoIdx] = 0U;
    }
    else
    {
        prPfeDev->u16TSQueueWrite[u8FifoIdx]++;
    }

    oal_mutex_unlock(PFE_TS_QUEUE_WRITE_MUTEX);
}
#endif

#if (STD_ON == ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API)
/*================================================================================================*/
static Std_ReturnType TxReqSwt(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx, uint8* dataPtr, uint16 *pLength)
{
    /* dataPtr points to position of EtherType in Ethernet frame */
    Std_ReturnType u8FunctionSuccess = Eth_43_PFE_InternalCfgPtr->pController[u8CtrlIdx]->
        Eth_43_PFE_EthSwtDriverFunctionList.TxProcessFrameFunction(u8CtrlIdx, BufIdx, &dataPtr, pLength);
    if ((Std_ReturnType)E_OK == u8FunctionSuccess)
    {
        /* Finish to process frame */
        u8FunctionSuccess = Eth_43_PFE_InternalCfgPtr->pController[u8CtrlIdx]->
        Eth_43_PFE_EthSwtDriverFunctionList.TxFinishedIndicationFunction(u8CtrlIdx, BufIdx);
    }

    return u8FunctionSuccess;
}
#endif

/*================================================================================================*/
static errno_t TxReqTrigger(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx, uint16 Length)
{
    uint8 u8FifoIdx = Eth_43_PFE_LLD_GetTxFifoIdx(u8CtrlIdx, BufIdx);
    void *pvDataVA = (void *)aarTxBuf[u8CtrlIdx][BufIdx].BufAddr;
    void *pvRefPtr = TxReqQueueWrite(u8CtrlIdx, BufIdx);

    return  pfe_hif_drv_client_xmit_pkt(
                     arPfeInterface[u8CtrlIdx].prClient, 
                     u8FifoIdx, 
                     pvDataVA, 
                     pvDataVA,
                     (uint32_t)Length + (uint32_t)sizeof(pfe_ct_hif_tx_hdr_t),
                     pvRefPtr);
}

/*================================================================================================*/
static void TxReqFailed(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx)
{
    const trTxMeta *prTxMeta = NULL_PTR;
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
    /* Free the buffer */
    addr_t BufAddr = aarTxBuf[u8CtrlIdx][BufIdx].BufAddr;
    (void)pfe_hif_chnl_bmu_free_buf(arPfeInterface[u8CtrlIdx].prHifChnl, BufAddr);
#endif
#if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
    prTxMeta = Eth_PFE_LLD_GetTxBufMeta(u8CtrlIdx, BufIdx);
    /* Report the failure. There will be no interrupt generated, so it is reported here. */
    if(TRUE == prTxMeta->bDoTxIndication)
    {
        /*    Disable HIF channel interrupts */
        pfe_hif_chnl_irq_mask(arPfeInterface[u8CtrlIdx].prHifChnl);
        EthIf_TxConfirmation(ETH_43_PFE_CFG_CTRLIDXINETHIF(u8CtrlIdx), BufIdx, E_NOT_OK);
        /*    Re-enable HIF channel IRQ */
        pfe_hif_chnl_irq_unmask(arPfeInterface[u8CtrlIdx].prHifChnl);
    }
    aarTxBuf[u8CtrlIdx][BufIdx].u8Status = TX_BUF_FREE;
#else
    /* Failure will be reported when polling function is called */
    aarTxBuf[u8CtrlIdx][BufIdx].u8Status = TX_BUF_FAILED;
    (void)prTxMeta;
#endif /* interrupt_enabled */
}

/*================================================================================================*/
/* Adds BufIdx to Tx Request Queue (at write index) and returns pointer to the new record, which
   can be used as ref_ptr for pfe_hif_drv_client_xmit_pkt */
static void *TxReqQueueWrite(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx)
{
    PfeDevAssert(BufIdx < ETH_43_PFE_MAX_CTRL_TX_BUF_CNT);
    /* There is enough room in arTxReqQueue to fit all Tx buffers => no need to check if record is free */
    Eth_PFE_LLD_trTxRefData *prRefPtr = &arTxReqQueue[u8CtrlIdx][u16TxQueueWrite[u8CtrlIdx]];
    if (u16TxQueueWrite[u8CtrlIdx] >= (ETH_43_PFE_MAX_CTRL_TX_BUF_CNT - 1U))
    {
        u16TxQueueWrite[u8CtrlIdx] = 0U;
    }
    else
    {
        u16TxQueueWrite[u8CtrlIdx]++;
    }
    prRefPtr->u16BufIdx = (uint16)BufIdx;
    return (void *)prRefPtr;
}

/*================================================================================================*/
/* Provides record from Tx Request Queue at read index */
static Eth_PFE_LLD_trTxRefData *TxReqQueueRead(const uint8 u8CtrlIdx)
{
    Eth_PFE_LLD_trTxRefData *prRefPtr = &arTxReqQueue[u8CtrlIdx][u16TxQueueRead[u8CtrlIdx]];
    return prRefPtr;
}

/*================================================================================================*/
/* Deletes record from Tx Request Queue at read index */
static void TxReqQueueDelete(const uint8 u8CtrlIdx)
{
    arTxReqQueue[u8CtrlIdx][u16TxQueueRead[u8CtrlIdx]].u16BufIdx = INVALID_TX_INDEX;
    if (u16TxQueueRead[u8CtrlIdx] >= (ETH_43_PFE_MAX_CTRL_TX_BUF_CNT - 1U))
    {
        u16TxQueueRead[u8CtrlIdx] = 0U;
    }
    else
    {
        u16TxQueueRead[u8CtrlIdx]++;
    }
}

/*================================================================================================*/
static void ClientEventHdlr_RX(uint8 u8ClientIdx, uint8 u8QueueIdx)
{
    /* Only call the handler here if the interrupt mode is enabled */
    if(TRUE == ETH_43_PFE_CFG_ENABLERXINTERRUPT(u8ClientIdx))
    {
        if(ETH_STATE_INIT == Eth_43_PFE_CtrlState[u8ClientIdx])
        {
            /*  Return value is not needed in interrupt mode */
            (void)Eth_PFE_LLD_ReportReception(u8ClientIdx, u8QueueIdx, (boolean)TRUE);
        }
    }
}

/*================================================================================================*/
static void ClientEventHdlr_TX(uint8 u8ClientIdx, uint8 u8QueueIdx)
{
    /* Only call the handler here if the interrupt mode is enabled */
    if(TRUE == ETH_43_PFE_CFG_ENABLETXINTERRUPT(u8ClientIdx))
    {
        if(ETH_STATE_INIT == Eth_43_PFE_CtrlState[u8ClientIdx])
        {
            if(ETH_MODE_ACTIVE == Eth_PFE_LLD_CheckControllerIsActive(u8ClientIdx))
            {
                /*  Return value is not needed in interrupt mode */
                Eth_PFE_LLD_ReportTransmission(u8ClientIdx, u8QueueIdx);
            }
        }
    }
}

#if (STD_ON == ETH_43_PFE_GLOBALTIME_SUPPORT)
/*================================================================================================*/
static void ClientEventHdlr_ETS(uint8 u8ClientIdx, uint8 u8QueueIdx)
{
    /* Only call the handler here if the interrupt mode is enabled */
    if(TRUE == ETH_43_PFE_CFG_ENABLETXINTERRUPT(u8ClientIdx))
    {
        if(ETH_STATE_INIT == Eth_43_PFE_CtrlState[u8ClientIdx])
        {
            Eth_PFE_LLD_ReportTransmissionTS(u8ClientIdx, u8QueueIdx);
        }
    }
}
#endif

/*================================================================================================*/
/**
 * @brief       HIF client event handler
 * @details     Called by HIF when client-related event happens (packet received, packet
 *              transmitted).
 * @note        Running within context of HIF driver worker thread.
 */
static errno_t ClientEventHdlr(pfe_hif_drv_client_t *prClient, void *pvArg, uint32 u32Event, uint32 u32QueueIdx)
{
    errno_t RetValue = E_OK;
    const trPfeDev *prPfeDev = (const trPfeDev *)pvArg;
    uint8 u8ClientIdx = prPfeDev->u8CtrlIdx;
    PfeDevAssert(u32QueueIdx <= UINT8_MAX);

    (void)prClient;
    switch(u32Event)
    {
        case EVENT_RX_PKT_IND: /* New packet(s) received */
            ClientEventHdlr_RX(u8ClientIdx, (uint8)u32QueueIdx);
            break;
        case EVENT_TXDONE_IND: /* New Tx confirmation(s) */
            ClientEventHdlr_TX(u8ClientIdx, (uint8)u32QueueIdx);
            break;
#if (STD_ON == ETH_43_PFE_GLOBALTIME_SUPPORT)
        case EVENT_ETS: /* New egress timestamp(s) available, generate confirmation(s) for timestamped frames */
            ClientEventHdlr_ETS(u8ClientIdx, (uint8)u32QueueIdx);
            break;
#endif /*ETH_43_PFE_GLOBALTIME_SUPPORT*/
        default:
            /*Do Nothing*/
            break;
    }
    return RetValue;
}

#if (STD_ON == ETH_43_PFE_GLOBALTIME_SUPPORT)
/*================================================================================================*/
static errno_t GetTxTimeStamp(uint8 u8CtrlIdx, \
                              Eth_BufIdxType BufIdx, \
                              Eth_TimeStampQualType *timeQualPtr, \
                              Eth_TimeStampType *timeStampPtr \
                             )
{
    errno_t RetVal = ENOENT;
    const Eth_PFE_LLD_trTxTsRef *rTsRef;

    if (NULL_PTR != arPfeInterface[u8CtrlIdx].prClient)
    {
        rTsRef = Eth_PFE_LLD_GetTxBufTsRef(u8CtrlIdx, BufIdx);
        /* Get timestamp */
        RetVal = pfe_hif_drv_client_get_ts
        (
            arPfeInterface[u8CtrlIdx].prClient, FALSE,
            rTsRef->u8MessageType, rTsRef->u16SourcePortID, rTsRef->u16SequenceID,
            &(timeStampPtr->seconds), &(timeStampPtr->nanoseconds)
        );

        if (EOK == RetVal)
        {
            timeStampPtr->secondsHi = 0U;
            *timeQualPtr = ETH_VALID;
        }
        else
        {
            *timeQualPtr = ETH_INVALID; /* General failure */
        }
    }
    return RetVal;
}
#endif /* ETH_43_PFE_GLOBALTIME_SUPPORT */

#ifdef PFE_CFG_PFE_MASTER
/*================================================================================================*/
static errno_t ConfigureSchedulerAndShaper_SetFifo(ConfigureSchedulerAndShaper_StateType *pstate,
                                                   uint8 u8SchIdx,
                                                   const Eth_43_PFE_SchedulerInputInfoCfgType *pSchInput,
                                                   uint8 u8FifoIdx
                                                  )
{
    errno_t ret = EOK;

    /* Connect queue to scheduler input */
    ret = pfe_tmu_sch_bind_queue(ptrPlatform->tmu, pstate->emac_id, u8SchIdx, pSchInput->u8Input, u8FifoIdx);
    if(EOK != ret)
    {
        NXP_LOG_ERROR("Failed to connect queue to scheduler input\n");
    }
    else 
    {
        pstate->is_queue_used[u8FifoIdx] = TRUE;
    }

    return ret;
}

/*================================================================================================*/
static errno_t ConfigureSchedulerAndShaper_SetShaper(ConfigureSchedulerAndShaper_StateType *pstate,
                                                     uint8 u8SchIdx,
                                                     const Eth_43_PFE_SchedulerInputInfoCfgType *pSchInput
                                                    )
{
    /* shaper lookup */
    errno_t ret = ENODEV;
    const Eth_43_PFE_ShaperCfgType *pShp = NULL;
    for(uint8 u8Shp = 0u; u8Shp < pstate->pcfg->EthCtrlShaperCnt; u8Shp++) {
        if(pSchInput->u8InputIdx == pstate->pcfg->pShpCfg[u8Shp].u8ShpIdx) 
        {
            pShp = &pstate->pcfg->pShpCfg[u8Shp];
            ret = pfe_tmu_shp_enable(ptrPlatform->tmu, pstate->emac_id, pShp->u8ShpIdx);
            break;
        }
    }

    if(EOK != ret)
    {
        NXP_LOG_ERROR("Failed to enable shaper\n");
    }
    else 
    {
        const int64_t neg_min_credit = -(int64_t)pShp->s32MinCredit;
        PfeDevAssert(neg_min_credit <= 0);
        ret = pfe_tmu_shp_set_limits(ptrPlatform->tmu, pstate->emac_id, pShp->u8ShpIdx, pShp->s32MaxCredit, (int32_t)neg_min_credit);
        if(EOK != ret)
        {
            NXP_LOG_ERROR("Failed to set shaper credit limits\n");
        }
        else 
        {
            const uint8 aShpPos[TLITE_SCH_CNT][TLITE_SCH_INPUTS_CNT] = {SHP_POS_COR_SCH0, SHP_POS_COR_SCH1};
            uint8 u8TempShpPos = aShpPos[u8SchIdx][pSchInput->u8Input];
            ret = pfe_tmu_shp_set_position(ptrPlatform->tmu, pstate->emac_id, pShp->u8ShpIdx, u8TempShpPos);
            if(EOK != ret)
            {
                NXP_LOG_ERROR("Failed to set shaper position\n");
            }
            else 
            {
                ret = pfe_tmu_shp_set_idle_slope(ptrPlatform->tmu, pstate->emac_id, pShp->u8ShpIdx , pShp->u32IdleSlope);
                if(EOK != ret)
                {
                    NXP_LOG_ERROR("Failed to set shaper idle slope\n");
                }
                else {
                    ret = ConfigureSchedulerAndShaper_SetFifo(pstate, u8SchIdx, pSchInput, pShp->u8FifoIdx);
                }
            }
        }
    }

    return ret;
}

/*================================================================================================*/
static errno_t ConfigureSchedulerAndShaper_SetSchedulerInput(ConfigureSchedulerAndShaper_StateType *pstate,
                                                             uint8 u8SchIdx,
                                                             const Eth_43_PFE_SchedulerCfgType *pSch,
                                                             const Eth_43_PFE_SchedulerInputInfoCfgType *pSchInput
                                                            )
{
    errno_t ret = EOK;

    /* Set scheduler input weight */
    if ((SCHED_ALGO_WRR == pSch->SchAlgo) || (SCHED_ALGO_DWRR == pSch->SchAlgo))
    {
        ret = pfe_tmu_sch_set_input_weight(ptrPlatform->tmu, pstate->emac_id, u8SchIdx, pSchInput->u8Input, pSchInput->u32Weight);
        if(EOK != ret)
        {
            NXP_LOG_ERROR("Failed to set scheduler input weight\n");
        }
    }

    if(EOK == ret)
    {
        if (IS_FIFO == pSchInput->SchInputType)
        {
            /* Connect queue to scheduler input */
            ret = ConfigureSchedulerAndShaper_SetFifo(pstate, u8SchIdx, pSchInput, pSchInput->u8InputIdx);
        }
        else if (IS_SHAPER == pSchInput->SchInputType)
        {
            ret = ConfigureSchedulerAndShaper_SetShaper(pstate, u8SchIdx, pSchInput);
        }
        else /* IS_SHEDULER */
        {
            /* Bind scheduler 0 to scheduler 1 */
            ret = pfe_tmu_sch_bind_sch_output(ptrPlatform->tmu, pstate->emac_id, SCH0_ID, u8SchIdx, pSchInput->u8Input);
            if(EOK != ret)
            {
                NXP_LOG_ERROR("Failed to connect scheduler 0  to scheduler 1\n");
            }
        }
    }

    if(EOK == ret)
    {
        pstate->is_input_used[u8SchIdx][pSchInput->u8Input] = TRUE;
    }

    return ret;
}

/*================================================================================================*/
static errno_t ConfigureSchedulerAndShaper_SetRateModeAlgo(const ConfigureSchedulerAndShaper_StateType *pstate,
                                                           uint8 u8SchIdx,
                                                           const Eth_43_PFE_SchedulerCfgType *pSch
                                                          )
{
    errno_t ret = EOK;

    /* Set scheduler rate mode */
    ret = pfe_tmu_sch_set_rate_mode(ptrPlatform->tmu, pstate->emac_id, u8SchIdx, pSch->SchRateMode);
    if(EOK != ret)
    {
        NXP_LOG_ERROR("Failed to set scheduler rate mode\n");
    }
    else {
        /* Set scheduler algorithm */
        ret = pfe_tmu_sch_set_algo(ptrPlatform->tmu, pstate->emac_id, u8SchIdx, pSch->SchAlgo);
        if(EOK != ret)
        {
            NXP_LOG_ERROR("Failed to set scheduler algorithm\n");
        }
    }

    return ret;
}

/*================================================================================================*/
static errno_t ConfigureSchedulerAndShaper_MapUnusedInputs(ConfigureSchedulerAndShaper_StateType *pstate,
                                                           uint8 u8SchIdx
                                                          )
{
    errno_t ret = EOK;
#ifndef PFE_CFG_MULTI_INSTANCE_SUPPORT
    /* We only disable unused queues in single instance mode, because in multi-instance, 
        when EMACs are shared, all queues could be expected by slaves.
        For example, the SSH server on the Linux slave expects all queues to be enabled */
    uint8 u8Fifo = PFE_TMU_INVALID_QUEUE;
#else 
    uint8 u8Fifo = 0u;
#endif

    for (uint8 u8SchInput = 0U; u8SchInput < TLITE_SCH_INPUTS_CNT; u8SchInput++)
    {
        /* find unused scheduler input */
        if(!pstate->is_input_used[u8SchIdx][u8SchInput])
        {
            /* find an unused queue */
            while((u8Fifo < TLITE_PHY_QUEUES_CNT) && pstate->is_queue_used[u8Fifo]) 
            {
                u8Fifo++;
            }

            if(u8Fifo < TLITE_PHY_QUEUES_CNT)
            {
                pstate->is_queue_used[u8Fifo] = TRUE;
            }
            else {
                u8Fifo = PFE_TMU_INVALID_QUEUE;
            }

            ret = pfe_tmu_sch_bind_queue(ptrPlatform->tmu, pstate->emac_id, u8SchIdx, u8SchInput, u8Fifo);
            if(EOK != ret)
            {
                NXP_LOG_ERROR("Failed to connect queue to scheduler input\n");
                break;
            }
        }
    }

    return ret;
}

/*================================================================================================*/
static errno_t ConfigureSchedulerAndShaper(uint8 u8CtrlIdx)
{
    errno_t ret = EOK;
    ConfigureSchedulerAndShaper_StateType state = {
        .pcfg = Eth_43_PFE_InternalCfgPtr->pController[u8CtrlIdx],
        .emac_id = ETH_43_PFE_CFG_CTRLPHYIFID(u8CtrlIdx),
        .is_input_used = {{FALSE}},
        .is_queue_used = {FALSE}
    };

    for (uint8 u8Sch = 0U; (u8Sch < state.pcfg->EthCtrlSchedulerCnt) && (EOK == ret); u8Sch++)
    {
        const Eth_43_PFE_SchedulerCfgType *pSch = &state.pcfg->pSchCfg[u8Sch];
        uint8 sch_idx = pSch->IsLastSch ? SCH1_ID : SCH0_ID;
        const Eth_43_PFE_SchedulerInputInfoCfgType *pSchInput = pSch->pSchInputInfoCfg;
        uint8 u8SchInputCnt = pSch->SchInputCnt;

        ret = ConfigureSchedulerAndShaper_SetRateModeAlgo(&state, sch_idx, pSch);

        for (uint8 u8SchInput = 0U; (u8SchInput < u8SchInputCnt) && (EOK == ret); u8SchInput++)
        {
            ret = ConfigureSchedulerAndShaper_SetSchedulerInput(&state, sch_idx, pSch, &pSchInput[u8SchInput]);
        }
    }
    
    if(EOK == ret) 
    {
        ret = ConfigureSchedulerAndShaper_MapUnusedInputs(&state, SCH1_ID);
        if(EOK == ret) {
            ret = ConfigureSchedulerAndShaper_MapUnusedInputs(&state, SCH0_ID);
        }
    }

    return ret;
}
#endif /* PFE_CFG_PFE_SLAVE */

#if (STD_ON == ETH_43_PFE_DEM_EVENT_DETECT)
/**
* @brief         Detect controller errors and frame lost
* @param[in]     u8CtrlIdx Index of controller
* @param[in]     errorId error id
* @retval        TRUE Detect errors
* @retval        FALSE Not detect errors
*/
static boolean DetectErrorsAndLostFrame(uint8 u8CtrlIdx, ErrorIdType errorId)
{
    boolean ret = FALSE;
    uint32 u32OldCount = 0U;
    uint32 u32Stat = 0U;
    pfe_emac_t *prEmac = NULL_PTR;

    u32Stat = u32StatId[errorId];
    prEmac = Eth_PFE_LLD_GetEmacInstanceByControllerId(u8CtrlIdx);
    if (NULL_PTR != prEmac)
    {
        u32OldCount = u32DemErrorCounters[u8CtrlIdx][errorId];
        u32DemErrorCounters[u8CtrlIdx][errorId] = pfe_emac_get_stat_value(prEmac, u32Stat);
        if (u32DemErrorCounters[u8CtrlIdx][errorId] > u32OldCount)
        {
            ret = TRUE;
        }
    }

    return ret;
}

/**
* @brief         Check controller errors and frame lost
* @param[in]     u8CtrlIdx Index of controller
* @param[in]     demConfig enable/disable the DEM error
* @param[in]     errorId error id
* @param[in]     demId ID of DEM error
*/
static void CheckDemStatus(uint8 u8CtrlIdx, uint32 demConfig, ErrorIdType errorId, uint32 demId)
{
    /* Check Dem event ON or OFF */
    if ((uint32)STD_ON == demConfig)
    {
        PfeDevAssert(demId < UINT16_MAX);
        if (DetectErrorsAndLostFrame(u8CtrlIdx, errorId))
        {
            (void)Dem_SetEventStatus((Dem_EventIdType)demId, DEM_EVENT_STATUS_PREFAILED);
        }
        else
        {
            (void)Dem_SetEventStatus((Dem_EventIdType)demId, DEM_EVENT_STATUS_PREPASSED);
        }
    }
}
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */

/**
* @brief         Reset global variables used by the driver to the default values
*/
static void Eth_PFE_LLD_ResetGlobalVar(void)
{
#ifdef PFE_CFG_RTABLE_ENABLE
    /* usage scope: Eth_PFE_LLD_MainFunction */
    /* Routing table timer ticks, used for rtable entries timeout update */
    u32RtrTimeoutTimeMs = 0U;
#endif /* PFE_CFG_RTABLE_ENABLE */
}


/**
* @brief         Detect the hard reset
*/
static boolean Eth_PFE_LLD_DetectHardReset(void)
{
    errno_t ret;
    boolean bRetVal = FALSE;
    pfe_hif_chnl_t *prHifChnl;

    if (NULL_PTR != ptrPlatform)
    {
        /*  Get HIF channel */
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        if (PFE_CFG_LOCAL_IF == PFE_PHY_IF_ID_HIF_NOCPY)
        {
            prHifChnl = pfe_hif_nocpy_get_channel(ptrPlatform->hif_nocpy, PFE_HIF_CHNL_NOCPY_ID);
        }
        else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
        {
            prHifChnl = pfe_hif_get_channel(ptrPlatform->hif, pfe_hif_chnl_from_phy_id(PFE_CFG_LOCAL_IF));
        }

        if (NULL_PTR == prHifChnl)
        {
            NXP_LOG_WARNING("Can't get HIF channel instance\n");
        }
        else
        {
            ret = pfe_hif_chnl_inspect_hw_state(prHifChnl);
            if (EOK == ret)
            {
                bRetVal = TRUE;
            }
            else
            {
                /* Enable RX */
                if (EOK != pfe_hif_chnl_rx_enable(prHifChnl))
                {
                    NXP_LOG_WARNING("Couldn't enable RX\n");
                }
                /* Enable TX */
                if (EOK != pfe_hif_chnl_tx_enable(prHifChnl))
                {
                    NXP_LOG_WARNING("Couldn't enable TX\n");
                }
                /* Enable the channel interrupts */
                pfe_hif_chnl_rx_irq_unmask(prHifChnl);
                pfe_hif_chnl_tx_irq_unmask(prHifChnl);
            }
        }
    }

    return bRetVal;
}

/**
* @brief         Shutdown the driver if it was initialized before
*/
static void Eth_PFE_LLD_ShutdownDriver(void)
{
    uint8 u8Ctr;
    pfe_phy_if_t *prHif = NULL_PTR;
    boolean bDetectHardReset;
    
    bDetectHardReset = Eth_PFE_LLD_DetectHardReset();
    if (TRUE == bDetectHardReset)
    {
        /* Remove software components that need to be sync with HW status in ReInit/DeInit sequence */
#if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
        if (NULL_PTR != prCommonChnlIRQ)
        {
            oal_irq_destroy(prCommonChnlIRQ);
        }
#endif
        pfe_platform_remove_sw_if();

        if (EOK == pfe_platform_remove())
        {
            ptrPlatform = NULL_PTR;
        }
        else
        {
            NXP_LOG_WARNING("Unable to remove the PFE platform\n");
        }
    }
    else
    {
        /* Make sure the HW is shut down */
        /* In case it was previously initialized, it MUST be deinitialized */
        for (u8Ctr = 0U; u8Ctr < ETH_43_PFE_NUM_CONTROLLER_CFG; u8Ctr++)
        {
            if (NULL_PTR != arPfeInterface[u8Ctr].prClient)
            {
                if ((Std_ReturnType)E_OK != Eth_PFE_LLD_DisableController(u8Ctr))
                {
                    NXP_LOG_WARNING("Unable to disable controller %u\n", (uint_t)u8Ctr);
                }
            }
            eSavedMode[u8Ctr]  = ETH_MODE_DOWN;
        }
        if(NULL_PTR != ptrPlatform)
        {
            /* Get the physical interface for our HIF channel */
            prHif = pfe_platform_get_phy_if_by_id(ptrPlatform, PFE_CFG_LOCAL_IF);
            if (NULL_PTR != prHif)
            {
                /* Disable HIF physical interfaces, this is required to flush BDP RX FIFO */
                if(E_OK != pfe_phy_if_disable(prHif))
                {
                    NXP_LOG_WARNING("Failed to disable physical interface for the HIF\n");
                }
            }
        }
#ifdef PFE_CFG_PFE_SLAVE
        /* For slaves, the interface destroy process is done over RPC.
           It should be completed before destroying the hif driver */
        pfe_platform_destroy_ifaces();
#endif /* PFE_CFG_PFE_SLAVE */
#if ((TRUE == PFE_CFG_HIF_IRQ_ENABLED) || (TRUE == PFE_CFG_BMU_IRQ_ENABLED))
        /* In next called function we loose ability to process HIF interrupt */
        Eth_PFE_LLD_bIrqInitStatus = FALSE;
#endif
        DestroyHifDrv(prCommonChnlIRQ, prCommonHifDrv);
        prCommonHifDrv = NULL_PTR;
        if (NULL_PTR != ptrPlatform)
        {
            /* Shutdown the HW. Can be called multiple times. */
            if (EOK == pfe_platform_remove())
            {
                ptrPlatform = NULL_PTR;
            }
            else
            {
                NXP_LOG_WARNING("Unable to remove the PFE platform\n");
            }
        }
        Eth_PFE_LLD_ResetGlobalVar();
    }
}

/**
* @brief         Get EMAC instance associated to controller
*/
#if (STD_ON == ETH_43_GET_COUNTER_API) || \
    (STD_ON == ETH_43_PFE_DEM_EVENT_DETECT) || \
    (STD_ON == ETH_43_GET_RXSTATS_API) || \
    (STD_ON == ETH_43_GET_TXSTATS_API) || \
    (STD_ON == ETH_43_GET_TXERROR_COUNTER_API)
static pfe_emac_t *Eth_PFE_LLD_GetEmacInstanceByControllerId(uint8 u8CtrlIdx)
{
    pfe_emac_t *prEmac = NULL_PTR;
    pfe_ct_phy_if_id_t emac_id;

    /*assign interface*/
    if (PFE_CTRL_TYPE_EMAC == ETH_43_PFE_CFG_CTRLTYPE(u8CtrlIdx))
    {
        emac_id = ETH_43_PFE_CFG_CTRLPHYIFID(u8CtrlIdx);
        prEmac = ptrPlatform->emac[emac_id];
    }
    return prEmac;
}
#endif /* (STD_ON == ETH_43_GET_COUNTER_API) ||
        * (STD_ON == ETH_43_PFE_DEM_EVENT_DETECT) ||
        * (STD_ON == ETH_43_GET_RXSTATS_API) ||
        * (STD_ON == ETH_43_GET_TXSTATS_API) ||
        * (STD_ON == ETH_43_GET_TXERROR_COUNTER_API) */

#if (STD_ON == ETH_43_PFE_CHANNEL_BD_FLUSH_API) && defined(PFE_CFG_PFE_MASTER)
static Std_ReturnType ChannelBdFlushRxPrepare(pfe_ct_phy_if_id_t DestHifChnl)
{
    Std_ReturnType Ret = E_NOT_OK;

    if (NULL_PTR == ptrPlatform)
    {
        NXP_LOG_ERROR("ChannelBdFlushRx: Platform not available");
    }
#if (FALSE == PFE_CFG_HIF_IRQ_ENABLED)
    else if(NULL_PTR == prCommonHifDrv)
    {
        NXP_LOG_ERROR("ChannelBdFlushRx: Hif driver not available");
    }
#endif
    else
    {
        const pfe_hif_chnl_t *const chnl = pfe_hif_get_channel_phy(ptrPlatform->hif, DestHifChnl);
        pfe_phy_if_t *const pSlaveHifPhyIf = pfe_phy_if_get_phy(DestHifChnl);

        if(chnl == NULL_PTR)
        {
            NXP_LOG_ERROR("ChannelBdFlushRx: Not a HIF channel");
        }
        else if(NULL_PTR == pSlaveHifPhyIf)
        {
            NXP_LOG_ERROR("ChannelBdFlushRx: PhyIf instance not available");
        }
        else if(EOK != pfe_phy_if_disable(pSlaveHifPhyIf))
        {
            NXP_LOG_ERROR("ChannelBdFlushRx: Failed to disable PhyIf");
        }
        else
        {
            /* Unlock the if_db in case it was locked by slave driver on DestHifChnl */
            (void)pfe_if_db_unlock(DestHifChnl);
            /* Enable the Rx DMA in case it was disabled on DestHifChnl */
            pfe_hif_chnl_cfg_rx_enable(chnl->cbus_base_va, chnl->id);
#if (FALSE == PFE_CFG_HIF_IRQ_ENABLED)
            /* Release local Tx BDs - avoid failing due to them being full */
            pfe_hif_drv_tx_job(prCommonHifDrv);
#endif
            Ret = E_OK;
        }
    }
    return Ret;
}

static Std_ReturnType ChannelBdFlushRxExecute(pfe_ct_phy_if_id_t DestHifChnl)
{
    uint32_t u32BDpCnt;
    uint32_t u32BDpCntReal;
    uint32_t u32SafetyLoopCnt;
    Std_ReturnType Ret = E_OK;
    const pfe_hif_chnl_t *const chnl = pfe_hif_get_channel_phy(ptrPlatform->hif, DestHifChnl);
    PfeDevAssert(chnl != NULL_PTR);

    /* Read the number of BDs to be flushed */
    u32BDpCnt = pfe_hif_chnl_cfg_get_rx_bdp_rd_fifo_cnt(chnl->cbus_base_va, chnl->id);
    u32BDpCntReal = u32BDpCnt;
#if (ETH_43_PFE_CHANNEL_BD_FLUSH_MAX_TICK_COUNT > 0U)
    /* Apply user configured limit of frames to send in one function call */
    if (u32BDpCnt > ETH_43_PFE_CHANNEL_BD_FLUSH_MAX_TICK_COUNT)
    {
        u32BDpCnt = ETH_43_PFE_CHANNEL_BD_FLUSH_MAX_TICK_COUNT;
        Ret = ETH_43_PFE_E_AGAIN;
    }
#endif
    NXP_LOG_DEBUG("ChannelBdFlushRx: Sending %u dummy frames to HIF%u", (uint_t)u32BDpCnt, (uint_t)(chnl->id));
    while(0U != u32BDpCnt)
    {
        /* Flush an Rx BD from destination HIF */
        if(EOK == pfe_idex_send_dummy_frame(DestHifChnl))
        {
            u32BDpCnt--;
            u32BDpCntReal--;
#if (FALSE == PFE_CFG_HIF_IRQ_ENABLED)
            /* Release our Tx BDs (using the time we would otherwise spend waiting) */
            pfe_hif_drv_tx_job(prCommonHifDrv);
#endif
            /* Wait for the packet to be received on the slave HIF */
            u32SafetyLoopCnt = 0U;
            while(pfe_hif_chnl_cfg_get_rx_bdp_rd_fifo_cnt(chnl->cbus_base_va, chnl->id) > u32BDpCntReal)
            {
                if(u32SafetyLoopCnt > ETH_43_PFE_CHANNEL_BD_FLUSH_TIMEOUT_COUNTER)
                {   /* Safety timeout has been exceeded */
                    Ret = E_NOT_OK;
                    NXP_LOG_ERROR("ChannelBdFlushRx: Timeout. Pending %u frames", (uint_t)u32BDpCntReal);
                    u32BDpCnt = 0U; /* To exit all loops */
                    break;
                }
                u32SafetyLoopCnt++;
            }
        }
        else
        {
            Ret = E_NOT_OK;
            NXP_LOG_ERROR("ChannelBdFlushRx: Failed to send a frame");
            break;
        }
    }

    /* disable slave HIF after BD flush is finished */
    pfe_hif_chnl_cfg_rx_disable(chnl->cbus_base_va, chnl->id);
    pfe_hif_chnl_cfg_tx_disable(chnl->cbus_base_va, chnl->id);

    return Ret;
}
#endif /* (STD_ON == ETH_43_PFE_CHANNEL_BD_FLUSH_API) && defined(PFE_CFG_PFE_MASTER) */

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
trTxMeta *Eth_PFE_LLD_GetTxBufMeta(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx)
{
    return &aarTxBuf[u8CtrlIdx][BufIdx].rMeta;
}

#if (STD_ON == ETH_43_PFE_GLOBALTIME_SUPPORT)
/*================================================================================================*/
Eth_PFE_LLD_trTxTsRef *Eth_PFE_LLD_GetTxBufTsRef(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx)
{
    return &aarTxBuf[u8CtrlIdx][BufIdx].rTsRef;
}
#endif

/*================================================================================================*/
/**
* @brief         Configures PFE interface based on provided configuration structure
* @note          This function has to be called before first PFE clocks reach PFE IP or partition
*                reset has to be performed to sample the register.
*/
void Eth_PFE_LLD_InitInterfaces(const Eth_43_PFE_ConfigType *cfgPtr)
{
#ifdef PFE_CFG_PFE_SLAVE
    (void)cfgPtr;
#else
    uint8 u8CtrlCount;
    uint8 u8MiiMode = 0U;

    /* Clear the register in case there were some changes already */
    *(uint32 *)(uintptr_t)(S32G_GPR_BASE + PFE_EMACX_INTF_SEL_OFF) = 0U;

    /* Decode PFE cfg to g2 platform serdes */
    for (u8CtrlCount = 0U; u8CtrlCount < (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG; u8CtrlCount++)
    {
        const pfe_ct_phy_if_id_t PhyIf = cfgPtr->pController[u8CtrlCount]->EthCtrlPhyIfID;
        uint8_t u8EmacIdx;
        
        switch(PhyIf)
        {
            case PFE_PHY_IF_ID_EMAC0:
                u8EmacIdx = 0U;
                break;
            case PFE_PHY_IF_ID_EMAC1:
                u8EmacIdx = 1U;
                break;
            case PFE_PHY_IF_ID_EMAC2:
                u8EmacIdx = 2U;
                break;
            default:
                u8EmacIdx = 3U; /* Not EMAC, set invalid index */
                break;
        }

        if(u8EmacIdx < 3U) /* Only configure for EMACs, valid indexes */
        {
            switch (cfgPtr->pController[u8CtrlCount]->EthCtrlMiiType)
            {
                case EMAC_MODE_MII:
                {
                    u8MiiMode = PFE_EMAC_MII;
                    break;
                }
                case EMAC_MODE_RMII:
                {
                    u8MiiMode = PFE_EMAC_RMII;
                    break;
                }
                case EMAC_MODE_SGMII:
                {
                    u8MiiMode = PFE_EMAC_SGMII;
                    break;
                }
                case EMAC_MODE_RGMII:
                {
                    u8MiiMode = PFE_EMAC_RGMII;
                    break;
                }
                default:
                {
                    u8MiiMode = PFE_EMAC_SGMII; /* Same as register default */
                    break;
                }
            }

            *(uint32 *)(uintptr_t)(S32G_GPR_BASE + PFE_EMACX_INTF_SEL_OFF) |= (uint32)PFE_EMACX_SET(u8EmacIdx, (uint32)u8MiiMode);
        }
    }
#endif
}

/*================================================================================================*/
/**
* @brief         Configures EMAC based on provided configuration structure
* @note          This function has to be called before first PFE clocks reach PFE IP or partition
*                reset has to be performed to sample the register.
*/
void Eth_PFE_LLD_InitEMACs(const Eth_43_PFE_ConfigType * cfgPtr)
{
#ifdef PFE_CFG_PFE_SLAVE
    (void)cfgPtr;
#else
    uint8 u8EmacIdx = 0U;
    uint8 u8MiiMode = 0U;

        /* Set EthCtrlMiiType to corresponding EMACs */
        for (u8EmacIdx = 0U; u8EmacIdx < (uint8)ETH_43_PFE_NUM_EMAC; u8EmacIdx++)
        {
            switch (cfgPtr->emac[u8EmacIdx].EthCtrlMiiType)
            {
                case EMAC_MODE_MII:
                {
                    u8MiiMode = PFE_EMAC_MII;
                    *(uint32 *)(uintptr_t)(S32G_GPR_BASE + PFE_EMACX_INTF_SEL_OFF) |= (uint32)PFE_EMACX_SET(u8EmacIdx, (uint32)u8MiiMode);
                    break;
                }
                case EMAC_MODE_RMII:
                {
                    u8MiiMode = PFE_EMAC_RMII;
                    *(uint32 *)(uintptr_t)(S32G_GPR_BASE + PFE_EMACX_INTF_SEL_OFF) |= (uint32)PFE_EMACX_SET(u8EmacIdx, (uint32)u8MiiMode);
                    break;
                }
                case EMAC_MODE_SGMII:
                {
                    u8MiiMode = PFE_EMAC_SGMII;
                    *(uint32 *)(uintptr_t)(S32G_GPR_BASE + PFE_EMACX_INTF_SEL_OFF) |= (uint32)PFE_EMACX_SET(u8EmacIdx, (uint32)u8MiiMode);
                    break;
                }
                case EMAC_MODE_RGMII:
                {
                    u8MiiMode = PFE_EMAC_RGMII;
                    *(uint32 *)(uintptr_t)(S32G_GPR_BASE + PFE_EMACX_INTF_SEL_OFF) |= (uint32)PFE_EMACX_SET(u8EmacIdx, (uint32)u8MiiMode);
                    break;
                }
                default:
                {
                    /* Do nothing */
                    break;
                }
            }
        }
#endif
}

#ifdef PFE_CFG_PFE_SLAVE
/*================================================================================================*/
static Std_ReturnType PlatformDrvPrepare_SlaveWaitForIpReady(void)
{
    Std_ReturnType result = E_NOT_OK;
    uint32 slave_tmout = PFE_CFG_SLAVE_HIF_MASTER_UP_TMOUT;
    boolean is_ip_ready = Local_Macro_hal_ip_ready_get();

    NXP_LOG_INFO("Wait for IP-ready ...\n");
    while(!is_ip_ready)
    {
        oal_time_usleep(1000U);
        is_ip_ready = Local_Macro_hal_ip_ready_get();

        /* Decrement only for slave_tmout > 0 */
        if(slave_tmout != 0u)
        {
            slave_tmout--;
            if(slave_tmout == 0u)
            {
                break;
            }
        }
    }

    if(is_ip_ready)
    {
        NXP_LOG_INFO("Detected IP-ready\n");
        result = E_OK;
    }
    else
    {
        NXP_LOG_RAW_ERROR("Detection IP-ready timeouted\n");
        result = E_NOT_OK;
#if (STD_ON == ETH_43_PFE_DEM_EVENT_DETECT)
        (void)Dem_SetEventStatus((Dem_EventIdType)ETH_43_PFE_CFG_DEM_E_DRIVER_RUNTIME_ERR_IP_READY, DEM_EVENT_STATUS_PREFAILED);
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */
    }

    return result;
}
#endif /* PFE_CFG_PFE_SLAVE */

#if defined(PFE_CFG_PFE_MASTER) && IS_RECEIVE_MALFORMED_ALLOWED
/*================================================================================================*/
static Std_ReturnType PlatformDrvPrepare_EnRxMalformed(void)
{
    Std_ReturnType result = E_NOT_OK;
    pfe_fw_feature_t *receive_malformed;

    /* Get receive_malformed feature */
    if (EOK != pfe_class_get_feature(ptrPlatform->classifier, &receive_malformed, "receive_malformed"))
    {
        NXP_LOG_ERROR("Unable to get feature\n");
    }
    /* Enable receive_malformed feature */
    else if (EOK != pfe_fw_feature_set_val(receive_malformed, 1U))
    {
        NXP_LOG_ERROR("Enable receive_malformed feature failed\n");
    }
    else {
        result = E_OK;
    }

    return result;
}
#endif    /* master, receive malformed */

/*================================================================================================*/
static Std_ReturnType PlatformDrvPrepare_EnablePhyIf(void)
{
    Std_ReturnType result  = E_NOT_OK;
    /*  Get the physical interface for our HIF channel */
    pfe_phy_if_t *prHif = pfe_platform_get_phy_if_by_id(ptrPlatform, PFE_CFG_LOCAL_IF);

    if (NULL_PTR == prHif)
    {
        NXP_LOG_ERROR("Can't get physical interface for the HIF\n");
    }
    else
    {
        /* Enable HIF physical interfaces */
        if (E_OK != pfe_phy_if_enable(prHif))
        {
            NXP_LOG_ERROR("Failed to enable physical interface for the HIF\n");
        }
        else
        {
            result = E_OK;
        }
    }

    return result;
}

/*================================================================================================*/
static Std_ReturnType PlatformDrvPrepare_ShutdownConfigInit(void)
{
    Std_ReturnType retVal = E_OK;

#ifdef PFE_CFG_PFE_MASTER
    pfe_fw_t rFirmware;
    rFirmware.class_data = PFE_CLASS_FW_BINARY;
#endif /* PFE_CFG_PFE_MASTER */

    /* Shutdown the driver if it was initialized before */
    Eth_PFE_LLD_ShutdownDriver();
    
    /*  Initialize the platform driver */
#ifdef PFE_CFG_PFE_MASTER
    rPlatformCfg.fw = &rFirmware;
#endif

#ifdef ETH_43_PFE_COMMON_HIF
    rPlatformCfg.local_hif = ETH_43_PFE_COMMON_HIF;
#else
    rPlatformCfg.local_hif = ETH_43_PFE_CFG_CTRLHIF(0U);
#endif
#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
    /* Initialize fci onwership */
    rPlatformCfg.hif_fci_owner_chnls_mask = pfe_fci_owner_hif_from_phy_id(ETH_43_PFE_COMMON_HIF);
#ifdef PFE_CFG_HIF0_OWNERSHIP
    rPlatformCfg.hif_fci_owner_chnls_mask |= FCI_OWNER_HIF_0;
#endif /* PFE_CFG_HIF0_OWNERSHIP */
#ifdef PFE_CFG_HIF1_OWNERSHIP
    rPlatformCfg.hif_fci_owner_chnls_mask |= FCI_OWNER_HIF_1;
#endif /* PFE_CFG_HIF1_OWNERSHIP */
#ifdef PFE_CFG_HIF2_OWNERSHIP
    rPlatformCfg.hif_fci_owner_chnls_mask |= FCI_OWNER_HIF_2;
#endif /* PFE_CFG_HIF2_OWNERSHIP */
#ifdef PFE_CFG_HIF3_OWNERSHIP
    rPlatformCfg.hif_fci_owner_chnls_mask |= FCI_OWNER_HIF_3;
#endif /* PFE_CFG_HIF3_OWNERSHIP */
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */

#ifdef PFE_CFG_G2_ORDERED_CLASS_WRITES
    rPlatformCfg.g2_ordered_class_writes = TRUE;
#else
    rPlatformCfg.g2_ordered_class_writes = FALSE;
#endif

    /*  Initialize Tx buffer pools */
    retVal = ConfigureTxBuffers();

    if(retVal == (Std_ReturnType)E_OK)
    {
        if(EOK != pfe_platform_init(&rPlatformCfg)) {
            retVal = E_NOT_OK;
            NXP_LOG_ERROR("Unable to initialize the platform\n");
        }
        else
        {
#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
#ifdef PFE_CFG_PFE_MASTER
            /* Set IP-ready */
            Local_Macro_hal_ip_ready_set(TRUE);
#endif /* PFE_CFG_PFE_MASTER */
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */
            ptrPlatform = pfe_platform_get_instance();
            /*  Get the PFE instance pointer */
            if (NULL_PTR == ptrPlatform)
            {
                retVal = E_NOT_OK;
                NXP_LOG_ERROR("Could not get PFE platform instance\n");
            }
        }
    }

    return retVal;
}

/**
* @brief         Prepares and initializes common part of PFE drivers
* @details       Prepares cache, memory management, main mutex, loads firmware and initializes
*                platform driver, HIF driver and FCI driver.
* @retval        E_NOT_OK The Platform drivers are not prepared
* @retval        E_OK The Platform drivers are initialized successfully
*/
Std_ReturnType Eth_PFE_LLD_PlatformDrvPrepare(void)
{
    Std_ReturnType retVal = E_OK;

    NXP_LOG_INFO("Driver commit hash: %s\n", rPlatformCfg.commit_hash);
    NXP_LOG_INFO("Driver version: %s\n", rPlatformCfg.driver_version);

#ifdef PFE_CFG_PFE_MASTER
#if (TRUE == PFE_CFG_BMU_IRQ_ENABLED)
    bDetectBmuInit = FALSE;
#endif /* PFE_CFG_BMU_IRQ_ENABLED */
#endif /* PFE_CFG_PFE_MASTER */

#ifdef PFE_CFG_PFE_SLAVE
    retVal = PlatformDrvPrepare_SlaveWaitForIpReady();
    if (retVal != (Std_ReturnType)E_NOT_OK)
    {
        retVal = PlatformDrvPrepare_ShutdownConfigInit();
    }
#else 
    retVal = PlatformDrvPrepare_ShutdownConfigInit();
#endif /* PFE_CFG_PFE_SLAVE */

#if defined(PFE_CFG_PFE_MASTER) && IS_RECEIVE_MALFORMED_ALLOWED
    /* Get receive_malformed feature */
    if (retVal != (Std_ReturnType)E_NOT_OK)
    {
        retVal = PlatformDrvPrepare_EnRxMalformed();
    }
#endif /* PFE_CFG_PFE_MASTER, receive malformed */

    /*  Get HIF driver instance */
    if (retVal != (Std_ReturnType)E_NOT_OK)
    {
        if (FALSE == CreateHifDrv(  PFE_CFG_LOCAL_IF,
                                    (PFE_CFG_LOCAL_IF == PFE_PHY_IF_ID_HIF_NOCPY) 
                                    ? rPlatformCfg.irq_vector_hif_nocpy
                                    : rPlatformCfg.irq_vector_hif_chnls[ETH_43_PFE_COMMON_HIF - PFE_PHY_IF_ID_HIF0],
                                    &prCommonHifChnl,
                                    &prCommonChnlIRQ,
                                    &prCommonHifDrv
                                 )
        )
        {
            prCommonHifDrv = NULL_PTR;
            retVal = E_NOT_OK;
            NXP_LOG_ERROR("Failed to create hif driver\n");
        }
    }
    if(retVal != (Std_ReturnType)E_NOT_OK)
    {
        retVal = PlatformDrvPrepare_EnablePhyIf();
    }

    return retVal;
}

/*================================================================================================*/
/**
* @brief         Shutdown the driver gracefully 
*/
void Eth_PFE_LLD_DeInit(void)
{
    uint8 u8Ctr;
    boolean bDrvInitialized = FALSE;

    /* Check if the driver was initialized before */
    bDrvInitialized = Eth_PFE_LLD_Check_Driver_Init();
    if (FALSE == bDrvInitialized)
    {
        NXP_LOG_INFO("The driver instance has not been initialized. No action was taken to shut down the driver\n");
    }
    else
    {
        /* Set the state to ETH_STATE_UNINIT before doing any changes to
           ensure that any preempting function (interrupt handler) will
           correctly stop its execution even if the state had been
           ETH_43_PFE_STATE_ACTIVE when the Eth_43_PFE_DeInit was called. */
        for (u8Ctr = 0U; u8Ctr < ETH_43_PFE_NUM_CONTROLLER_CFG; u8Ctr++)
        {
            Eth_43_PFE_CtrlState[u8Ctr] = ETH_STATE_UNINIT;
        }

        /* Shutdown the driver */
        Eth_PFE_LLD_ShutdownDriver();
    }
}

#if (STD_ON == ETH_43_PFE_GLOBALTIME_SUPPORT)
/*================================================================================================*/
static void InterfacePrepare_InitTSQueue(trPfeDev *prPfeDev)
{
    uint8 u8FifoCnt;
    uint16 u16BufCnt;
    uint8 u8FifoNum = Eth_43_PFE_InternalCfgPtr->pController[prPfeDev->u8CtrlIdx]->EthCtrlEgressFifoCnt;
    
    for (u8FifoCnt = 0u; u8FifoCnt < u8FifoNum; u8FifoCnt++)
    {
        prPfeDev->u16TSQueueRead[u8FifoCnt] = 0U;
        prPfeDev->u16TSQueueWrite[u8FifoCnt] = 0U;
        for (u16BufCnt = 0U; u16BufCnt < ETH_43_PFE_MAX_FIFO_TX_BUF_CNT; u16BufCnt++)
        {
            prPfeDev->TSQueue[u8FifoCnt][u16BufCnt] = INVALID_TX_INDEX;
        }
    }
}
#endif

#ifdef PFE_CFG_PFE_MASTER
/*================================================================================================*/
static errno_t InterfacePrepare_InitEmacMasterRx(const trPfeDev *prPfeDev)
{
    errno_t res = EOK;

    /* Configure promiscuous mode */
    if(TRUE == ETH_43_PFE_CFG_PROMISCUOUS(prPfeDev->u8CtrlIdx))
    {
        if (EOK != pfe_phy_if_promisc_enable(prPfeDev->prPhyIf))
        {
            NXP_LOG_ERROR("Failed to enable promiscuous mode on EMAC\n");
            res = EINVAL;
        }
    }
    else
    {
        if (EOK != pfe_phy_if_promisc_disable(prPfeDev->prPhyIf))
        {
            NXP_LOG_ERROR("Failed to disable promiscuous mode on EMAC\n");
            res = EINVAL;
        }
    }
    /*  Add controller's configured MAC address */
    if (EOK == res)
    {
        res = pfe_phy_if_add_mac_addr(prPfeDev->prPhyIf, prPfeDev->au8MacAddr, rPlatformCfg.local_hif);
        if (EEXIST == res)
        {
            res = EOK;
        }
        if (EOK != res)
        {
            NXP_LOG_ERROR("Failed to set MAC address to EMAC%hhu\n", prPfeDev->u8CtrlIdx);
            res = EINVAL;
        }
    }
    /* Direct frames from EMAC to our HIF */
    if (EOK == res)
    {
        pfe_log_if_t *prLogIf = pfe_phy_if_get_default_log_if(prPfeDev->prPhyIf);
        
        if (NULL_PTR == prLogIf)
        {
            NXP_LOG_ERROR("Failed to get default log_if interface for (%s)\n", pfe_phy_if_get_name(prPfeDev->prPhyIf));
            res = EINVAL;
        }
        else if (EOK != pfe_log_if_set_egress_ifs(prLogIf, ((uint32)1U << (uint8)prPfeDev->HifId)))
        {
            NXP_LOG_ERROR("Can't set egress interface (%s)\n", pfe_log_if_get_name(prLogIf));
            res = EINVAL;
        }
        else
        {
            ; /* All done */
        }
    }
    return res;
}

/*================================================================================================*/
static errno_t InterfacePrepare_MasterConfigEMAC(const trPfeDev *prPfeDev)
{
    errno_t res;

    /* FIXME AAVB-9597 - delete this call of InterfacePrepare_InitEmacMasterLink */
    res = InterfacePrepare_InitEmacMasterLink(prPfeDev);
    /* Configure MAC addresses and direct Rx traffic to our HIF */
    if(EOK == res)
    {
        res = InterfacePrepare_InitEmacMasterRx(prPfeDev);
    }
    /* Optionally configure loopback mode on associated EMAC */
    if((EOK == res) && (TRUE == ETH_43_PFE_CFG_EMAC_LOOPBACK(prPfeDev->u8CtrlIdx)))
    {
        res = pfe_phy_if_loopback_enable(prPfeDev->prPhyIf);
        if (EOK != res)
        {
            NXP_LOG_ERROR("EMAC loopback enable failed\n");
        }
    }
    /* Configure traffic schedulling and shaping */
    if(EOK == res)
    {
        res = ConfigureSchedulerAndShaper(prPfeDev->u8CtrlIdx);
        if (EOK != res)
        {
            NXP_LOG_ERROR("Failed to configure scheduler and shaper");
        }
    }
    return res;
}

/*================================================================================================*/
static errno_t InterfacePrepare_InitEmacMasterLink(const trPfeDev *prPfeDev)
{
    /* FIXME AAVB-9597 - delete this function */
    errno_t res = EINVAL;
    const pfe_emac_t *prPfeEmac = pfe_phy_if_get_emac(prPfeDev->prPhyIf);

    if (NULL_PTR == prPfeEmac)
    {
        NXP_LOG_ERROR("Can't get EMAC instance from physical interface.\n");
    }
    else if (EOK != pfe_emac_set_link_speed(prPfeEmac, ETH_43_PFE_CFG_LINKSPEED(prPfeDev->u8CtrlIdx)))
    {
        NXP_LOG_ERROR("Could not set EMAC link speed.\n");
    }
    else if (EOK != pfe_emac_set_link_duplex(prPfeEmac, ETH_43_PFE_CFG_LINKDUPLEX(prPfeDev->u8CtrlIdx)))
    {
        NXP_LOG_ERROR("Could not set EMAC link duplex.\n");
    }
    else
    {
        res = EOK;
    }

    return res;
}
#else /* not PFE_CFG_PFE_MASTER */
/*================================================================================================*/
static errno_t InterfacePrepare_SlaveConfigEMAC(const trPfeDev *prPfeDev)
{
    errno_t res;

    /*  Add controller's configured MAC address */
    res = pfe_phy_if_add_mac_addr(prPfeDev->prPhyIf, prPfeDev->au8MacAddr, rPlatformCfg.local_hif);
    if (EEXIST == res)
    {
        res = EOK;
    }
    if (EOK != res)
    {
        NXP_LOG_ERROR("Failed to set MAC address to EMAC%hhu\n", prPfeDev->u8CtrlIdx);
        res = EINVAL;
    }

    return res;
}
#endif /* PFE_CFG_PFE_MASTER */

/*================================================================================================*/
/**
* @brief         Configuration of one instance of interface
* @details       Configures one interface (e.g. hardware Ethernet port), in MCAL known as
*                "controller instance" (here the situation is different than MCAL assumes,
*                there is one controller with multiple interfaces, while MCAL assumes multiple
*                controllers with one interface each).
* @param[in]     u8CtrlIdx Interface (controller) to be configured
*/
void Eth_PFE_LLD_InterfacePrepare(uint8 u8CtrlIdx)
{
    if (NULL_PTR == ptrPlatform)
    {
        NXP_LOG_ERROR("Platform driver not prepared\n");
    }
    else if (NULL_PTR == prCommonHifDrv)
    {
        NXP_LOG_ERROR("Common HIF driver not prepared\n");
    }
    else
    {   /* Basic checks passed */
        trPfeDev *prPfeDev = &(arPfeInterface[u8CtrlIdx]);
        prPfeDev->bInterfacePrepared = FALSE;

        (void)autolibc_memcpy(prPfeDev->au8MacAddr, ETH_43_PFE_CFG_MACADDRESS(u8CtrlIdx), 6U);

        prPfeDev->u8CtrlIdx = u8CtrlIdx;
        prPfeDev->bStarted = FALSE;
        prPfeDev->prClient = NULL_PTR; /* Always initialize as it is used for checks */
#if (STD_ON == ETH_43_PFE_GLOBALTIME_SUPPORT)
        InterfacePrepare_InitTSQueue(prPfeDev);
#endif
        /*  Get components */
        prPfeDev->prPlatform = ptrPlatform;
        prPfeDev->HifId = ETH_43_PFE_COMMON_HIF;
        prPfeDev->prHifChnl = prCommonHifChnl;
        prPfeDev->prHifChnlIRQ = prCommonChnlIRQ;
        prPfeDev->prHifDrv = prCommonHifDrv;

        if (PFE_CTRL_TYPE_AUX == ETH_43_PFE_CFG_CTRLTYPE(u8CtrlIdx))
        {   /* AUX interface */
            prPfeDev->prPhyIf = NULL_PTR;
            /* AUX done, the final result will be checked in next function */
            prPfeDev->bInterfacePrepared = TRUE;
        }
        else
        {   /* EMAC or HIF */
            pfe_ct_phy_if_id_t temp_phy_id = ETH_43_PFE_CFG_CTRLPHYIFID(u8CtrlIdx);

            /* Get EMAC/HIF to attach to this controller */
            prPfeDev->prPhyIf = pfe_platform_get_phy_if_by_id(ptrPlatform, temp_phy_id);
            if (NULL_PTR == prPfeDev->prPhyIf)
            {
                NXP_LOG_ERROR("Could not get EMAC/HIF %u\n", (uint_t)temp_phy_id);
            }
            else
            {
                if (PFE_CTRL_TYPE_HIF == ETH_43_PFE_CFG_CTRLTYPE(u8CtrlIdx))
                {   /* HIF interface (hif0-hif3, hifnocpy) */
                    /* HIF done, the final result will be checked in next function */
                    prPfeDev->bInterfacePrepared = TRUE;
                }
                else
                {   /* EMAC interface */
#ifdef PFE_CFG_PFE_MASTER
                    if (EOK == InterfacePrepare_MasterConfigEMAC(prPfeDev))
#else
                    if (EOK == InterfacePrepare_SlaveConfigEMAC(prPfeDev))
#endif
                    {
                        /* EMAC done, the final result will be checked in next function */
                        prPfeDev->bInterfacePrepared = TRUE;
                    }
                }
            }
        }
    }
}

#ifdef PFE_CFG_PFE_MASTER
/*================================================================================================*/
static errno_t Eth_PFE_LLD_EMACPrepare_Config(const pfe_phy_if_t *prEmac, const Eth_43_PFE_EmacCfg *pEmacCfg)
{
    errno_t res = EINVAL;
    const pfe_emac_t *prPfeEmac = pfe_phy_if_get_emac(prEmac);

    if (NULL_PTR == prPfeEmac)
    {
        NXP_LOG_ERROR("Can't get EMAC instance from physical interface.\n");
    }
    else if (EOK != pfe_emac_set_link_speed(prPfeEmac, pEmacCfg->EthCtrlSpeed))
    {
        NXP_LOG_ERROR("Could not set EMAC link speed.\n");
    }
    else if (EOK != pfe_emac_set_link_duplex(prPfeEmac, pEmacCfg->EthCtrlDuplex))
    {
        NXP_LOG_ERROR("Could not set EMAC link duplex.\n");
    }
    else 
    {
        res = EOK;
    }

    return res;
}

/*================================================================================================*/
/**
* @brief         General Configuration for all instances of EMAC
* @details       Configures all EMACs
*/
void Eth_PFE_LLD_EMACPrepare(void)
{
    uint8 u8EmacIdx;
    const pfe_phy_if_t *prEmac;
    const pfe_ct_phy_if_id_t emac_ids[] = {PFE_PHY_IF_ID_EMAC0, PFE_PHY_IF_ID_EMAC1, PFE_PHY_IF_ID_EMAC2};

    for (u8EmacIdx = 0U; u8EmacIdx < (uint8)ETH_43_PFE_NUM_EMAC; u8EmacIdx++)
    {
        if (EMAC_SPEED_INVALID != ((Eth_43_PFE_InternalCfgPtr->emac[u8EmacIdx])).EthCtrlSpeed)
        {
            /* Normal interface */
            prEmac = pfe_platform_get_phy_if_by_id(ptrPlatform, emac_ids[u8EmacIdx]);
            if (NULL_PTR == prEmac)
            {
                NXP_LOG_ERROR("Could not get EMAC %u\n", (uint_t)(u8EmacIdx));
            }
            else if(EOK == Eth_PFE_LLD_EMACPrepare_Config(prEmac, &Eth_43_PFE_InternalCfgPtr->emac[u8EmacIdx]))
            {
                break; /* config failed */
            }
            else 
            {
                /* ok */
            }
        }
    }
}
#endif

/*================================================================================================*/
/**
* @brief         Configures the controller
* @details       Function
*                -# enables/disables Received frame interrupts
*                -# enables/disables Transmitted frame interrupts
*                -# clears MAC addresses hash tables
*                -# configures the controller MAC address
*                -# configures the MII
*                -# configures RCR and TCR registers
*                -# configures the maximal received frame length
*                -# configures all other registers including unused ones
*                   to prevent corrupted values staying there forever
* @param[in]     u8CtrlIdx Index of controller which will be configured
* @note          The controller is ready for use after the function finishes
*                however the buffers configuration must be still done.
*/
Std_ReturnType Eth_PFE_LLD_ConfigureController(const uint8 u8CtrlIdx)
{
    Std_ReturnType Status = E_NOT_OK;
#if (STD_ON == ETH_43_PFE_DEM_EVENT_DETECT)
    uint32 u32Count;
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */

    /* Everything is done, just check initialization status */
    if (TRUE == arPfeInterface[u8CtrlIdx].bInterfacePrepared)
    {
        Status = E_OK;
    }

#if (STD_ON == ETH_43_PFE_DEM_EVENT_DETECT)
    if (PFE_CTRL_TYPE_EMAC == ETH_43_PFE_CFG_CTRLTYPE(u8CtrlIdx))
    {
        for (u32Count = 0U; u32Count < (uint32)MAX_DEM_FRAME_ERRORS; u32Count++)
        {
            u32DemErrorCounters[u8CtrlIdx][u32Count] = 0U;
        }
    }
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */

    return Status;
}

/*================================================================================================*/
/* Check whether the driver was initialized before */
/**
* @brief         Check whether the driver was initialized before
* @details       This function is intended to check whether the driver was initialized or not by reading Eth_43_PFE_CtrlState.
* @retval        TRUE Driver was initialized
* @retval        FALSE Driver was not initialized
*/
boolean Eth_PFE_LLD_Check_Driver_Init(void)
{
    uint8 u8CtrlIdx;
    boolean bDrvInitialized = FALSE;

    /* Check if the driver was initialized before */
    for (u8CtrlIdx = 0U; u8CtrlIdx < ETH_43_PFE_NUM_CONTROLLER_CFG; u8CtrlIdx++)
    {
        if (ETH_STATE_INIT == Eth_43_PFE_CtrlState[u8CtrlIdx])
        {
            bDrvInitialized = TRUE;
            break;
        }
    }
    return bDrvInitialized;
}

/*================================================================================================*/
/**
* @brief         Checks the access to the controller
* @details       This function is intended to check whether the controller can be accessed or not by reading clock partition enable bit (partition 2 for PFE),
                 the field PCS. The capability to access the controller will be similar to the return value.
* @return        Controller accessibility
* @retval        TRUE Controller is accessible
* @retval        FALSE Controller access failed
*/
boolean Eth_PFE_LLD_CheckAccessToController(void)
{
    boolean partitionStat = FALSE;

    if(MC_ME_PRTN_STAT_PCS == (hal_read32(MC_ME_BASE + MC_ME_PRTN2_STAT) & MC_ME_PRTN_STAT_PCS))
    {
        partitionStat = TRUE;
    }
    return partitionStat;
}

/*================================================================================================*/
/**
* @brief         Checks whether the interface was successfully connected to platform driver
* @details

* @param[in]     u8CtrlIdx Interface to be checked
* @return        Controller accessibility
* @retval        TRUE Interface is accessible.
* @retval        FALSE Interface access failed.
*/
boolean Eth_PFE_LLD_CheckInitializationStatus(const uint8 u8CtrlIdx)
{
    boolean bControllerAvailable = FALSE;

    if ((PFE_CTRL_TYPE_AUX == ETH_43_PFE_CFG_CTRLTYPE(u8CtrlIdx))
         || (PFE_CTRL_TYPE_HIF == ETH_43_PFE_CFG_CTRLTYPE(u8CtrlIdx)))
    {
        if (TRUE == arPfeInterface[u8CtrlIdx].bInterfacePrepared)
        {
            bControllerAvailable = TRUE;
        }
    }
    else  /* PFE_CTRL_TYPE_EMAC */
    {   
        if (NULL_PTR == arPfeInterface[u8CtrlIdx].prPhyIf)
        {
            NXP_LOG_ERROR("Physical interface not created, u8CtrlIdx=%hhu\n", u8CtrlIdx);
        }
        else if (FALSE == arPfeInterface[u8CtrlIdx].bInterfacePrepared)
        {
            NXP_LOG_ERROR("Function Eth_PFE_LLD_InterfacePrepare failed, u8CtrlIdx=%hhu\n", u8CtrlIdx);
        }
        else
        {
            bControllerAvailable = TRUE;
        }
    }

    return bControllerAvailable;
}

/*================================================================================================*/
static boolean EnableController_InitFifos(const Eth_43_PFE_CtrlCfgType *pCtrlCfg)
{
    boolean bResult = TRUE;
    uint32_t ii;
    uint32_t fifoDepth;
    fifo_t *tFifo;
    void **vpData;

    /* initialize TX FIFOs */
    tFifo = pCtrlCfg->pEgressCfg->EthCtrlConfigEgressFifo;
    vpData = pCtrlCfg->pEgressCfg->EthCtrlConfigEgressFifoData;
    fifoDepth = RXTX_FIFO_ALIGNED_DEPTH(pCtrlCfg->EthCtrlEgressFifoDepth);

    for (ii = 0U; ii < pCtrlCfg->EthCtrlEgressFifoCnt; ii++)
    {
        if (NULL_PTR == fifo_create(pCtrlCfg->EthCtrlEgressFifoDepth, tFifo, vpData))
        {
            bResult = FALSE;
            break;
        }
        tFifo++;
        vpData += fifoDepth;
    }

    /* initialize RX FIFOs */
    if(TRUE == bResult)
    {
        tFifo = pCtrlCfg->pIngressCfg->EthCtrlConfigIngressFifo;
        vpData = pCtrlCfg->pIngressCfg->EthCtrlConfigIngressFifoData;
        fifoDepth = RXTX_FIFO_ALIGNED_DEPTH(pCtrlCfg->EthCtrlIngressFifoDepth);

        for (ii = 0U; ii < ETH_43_PFE_MAX_RXFIFO_CONFIG; ii++)
        {
            if (NULL_PTR == fifo_create(pCtrlCfg->EthCtrlIngressFifoDepth, tFifo, vpData))
            {
                bResult = FALSE;
                break;
            }
            tFifo++;
            vpData += fifoDepth;
        }
    }

    return bResult;
}

/*================================================================================================*/
static boolean EnableController_Common(const trPfeDev *prPfeDev)
{
    boolean bResult = TRUE;
    (void)prPfeDev;
#ifndef PFE_CFG_MULTI_INSTANCE_SUPPORT
    if (EOK != pfe_hif_drv_start(prPfeDev->prHifDrv))
    {
        NXP_LOG_ERROR("HIF driver start failed\n");
        bResult = FALSE;
    }
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */

#ifndef PFE_CFG_HIF_NOCPY_SUPPORT
    if(TRUE == bResult)
    {
        if (EOK != InitializeTxHeaders(prPfeDev->u8CtrlIdx, prPfeDev->prClient))
        {
            NXP_LOG_ERROR("Initialize TX headers failed\n");
            bResult = FALSE;
        }
    }
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */

    return bResult;
}

/*================================================================================================*/
static boolean EnableController_Aux(trPfeDev *prPfeDev, pfe_hif_drv_client_rx_tx_count *pclient_queue, pfe_hif_drv_client_fifo_queue *pclient_fifo_queue)
{
    boolean bResult = FALSE;

    /*  Connect to HIF */
    prPfeDev->prClient = pfe_hif_drv_aux_client_register(
                                                    prPfeDev->prHifDrv,
                                                    pclient_queue,
                                                    pclient_fifo_queue,
                                                    &ClientEventHdlr,
                                                    (void *)prPfeDev
                                            );
    if(NULL_PTR != prPfeDev->prClient)
    {
        if(TRUE == EnableController_Common(prPfeDev))
        {
            bResult = TRUE;
            prPfeDev->bStarted = TRUE;
            NXP_LOG_INFO("AUX interface (Controller %hhu) was started\n", prPfeDev->u8CtrlIdx);
        }
    }

    return bResult;
}

/*================================================================================================*/
static boolean EnableController_HifEmac(trPfeDev *prPfeDev, pfe_hif_drv_client_rx_tx_count *pclient_queue, pfe_hif_drv_client_fifo_queue *pclient_fifo_queue)
{
    boolean bResult = FALSE;

    /*  Connect to HIF */
    prPfeDev->prClient = pfe_hif_drv_client_register(
                                                    prPfeDev->prHifDrv, /* HIF Driver instance */
                                                    pfe_phy_if_get_id(prPfeDev->prPhyIf),/* Physical interface */
                                                    pclient_queue,       /* TX/RX Queue Count */
                                                    pclient_fifo_queue,  /* TX/RX Queue FIFO */
                                                    (ETH_43_PFE_CFG_ACCEPTALLTRAFFIC(prPfeDev->u8CtrlIdx) != FALSE),
                                                    &ClientEventHdlr,   /* Client's event handler */
                                                    (void *)prPfeDev    /* Meta data */
                                                    );
    if(NULL_PTR != prPfeDev->prClient)
    {
        if(EOK != pfe_hif_drv_client_set_inject_if(prPfeDev->prClient, pfe_phy_if_get_id(prPfeDev->prPhyIf)))
        {
            NXP_LOG_ERROR("Can't set inject interface\n");
        }
        else
        {
            if(TRUE == EnableController_Common(prPfeDev))
            {
                bResult = TRUE;
                NXP_LOG_INFO("Controller %hhu was started\n", prPfeDev->u8CtrlIdx);
            }
        }
    }

    prPfeDev->bStarted = bResult;

    return bResult;
}
/*================================================================================================*/
/*================================================================================================*/
/**
* @brief         Starts the controller
* @param[in]     u8CtrlIdx Index of controller which will be enabled
* @details       Function enables the controller after that it activates receive
*                and transmit buffer descriptors rings.
* @retval        TRUE Successfully enabled
* @retval        FALSE Failed to enable
*/
boolean Eth_PFE_LLD_EnableController(const uint8 u8CtrlIdx)
{
    boolean bResult;
    trPfeDev *prPfeDev = &(arPfeInterface[u8CtrlIdx]);
    const Eth_43_PFE_CtrlCfgType *pCtrlCfg;

    /* Check initialization results */
    bResult = prPfeDev->bInterfacePrepared;

    if((TRUE == bResult) && (FALSE == prPfeDev->bStarted))
    {
        pCtrlCfg = Eth_43_PFE_InternalCfgPtr->pController[u8CtrlIdx];

        /* initialize FIFOs */
        bResult = EnableController_InitFifos(pCtrlCfg);

        if(TRUE == bResult)
        {
            pfe_hif_drv_client_rx_tx_count client_queue = {
                .txq_num = pCtrlCfg->EthCtrlEgressFifoCnt, /* Number of TX queues */
                .rxq_num = ETH_43_PFE_MAX_RXFIFO_CONFIG    /* Number of RX queues */
            };
            pfe_hif_drv_client_fifo_queue client_fifo_queue = {
                .txq_fifo = pCtrlCfg->pEgressCfg->EthCtrlConfigEgressFifo,  /* TX Queue FIFO */
                .rxq_fifo = pCtrlCfg->pIngressCfg->EthCtrlConfigIngressFifo /* RX Queue FIFO */
            };

            if(PFE_CTRL_TYPE_AUX == ETH_43_PFE_CFG_CTRLTYPE(u8CtrlIdx))
            {
                bResult = EnableController_Aux(prPfeDev, &client_queue, &client_fifo_queue);
            }
            else if(PFE_CTRL_TYPE_EMAC == ETH_43_PFE_CFG_CTRLTYPE(u8CtrlIdx))
            {
                if(FALSE == EnableController_HifEmac(prPfeDev, &client_queue, &client_fifo_queue))
                {
                    bResult = FALSE;
                }
                else
                {
                    bResult = (EOK == pfe_phy_if_enable(prPfeDev->prPhyIf)) ? TRUE : FALSE;
                }
            }
            else /* PFE_CTRL_TYPE_HIF */
            {
                bResult = EnableController_HifEmac(prPfeDev, &client_queue, &client_fifo_queue);
            }
        }
    }

    return bResult;
}

/*================================================================================================*/
/**
* @brief         Stops the controller
* @details       Stops receiver, disables transmit, processes remaining buffers from queues (if any).
*                All pending Tx confirmations are reported before this function returns.
* @param[in]     u8CtrlIdx Index of controller which will be disabled
*/
Std_ReturnType Eth_PFE_LLD_DisableController(const uint8 u8CtrlIdx)
{
    trPfeDev *prPfeDev = &(arPfeInterface[u8CtrlIdx]);
    Std_ReturnType RetVal = E_OK;

    prPfeDev->bStarted = FALSE;

    if(NULL_PTR != prPfeDev->prClient)
    {
        /* In polling mode do Rx job to release buffers from HIF ring */
#if (FALSE == PFE_CFG_HIF_IRQ_ENABLED)
        pfe_hif_drv_rx_job((void *)prPfeDev->prHifDrv);
        /*  Note that here is a race condition as new packet can be received now,
            but it does not matter as it will be discarded later anyway */
#endif /* PFE_CFG_HIF_IRQ_ENABLED */
        /* Automatically releases remaining Rx and Tx buffers in client queues: */
        pfe_hif_drv_client_unregister(prPfeDev->prClient);
        prPfeDev->prClient = NULL_PTR;
    }
    /* Release all remaining Tx buffers (previously provided but not sent) */
    ReleaseAllCtrlTxBuffers(u8CtrlIdx);

    return RetVal;
}

/*================================================================================================*/
/**
* @brief         Check whether the controller is running
* @details       Function checks the ECR[ETHER_EN] bit to determine whether
*                the controller has been stopped or whether it is running.
* @param[in]     u8CtrlIdx Index of controller which will be checked active Status
* @return        The current controller mode.
* @retval        ETH_MODE_ACTIVE The controller is running.
* @retval        ETH_MODE_DOWN The controller is stopped.
*/
Eth_ModeType Eth_PFE_LLD_CheckControllerIsActive(const uint8 u8CtrlIdx)
{
    Eth_ModeType eReturnValue; /* Return value holder */

    if(TRUE == arPfeInterface[u8CtrlIdx].bStarted)
    {
        eReturnValue = ETH_MODE_ACTIVE;
    }
    else
    {
        eReturnValue = ETH_MODE_DOWN;
    }
    return eReturnValue;
}
/*================================================================================================*/
/**
* @brief         Provides the controllers MAC address
* @param[in]     u8CtrlIdx Index of controller to get PhysAddress
* @param[out]    pu8PhysAddr Pointer to array where 6 bytes of physical address will be written
*/
void Eth_PFE_LLD_GetPhysicalAddress
(
    const uint8 u8CtrlIdx,
    uint8 * pu8PhysAddr
)
{
    (void)autolibc_memcpy(pu8PhysAddr, arPfeInterface[u8CtrlIdx].au8MacAddr, 6U);
}
/*================================================================================================*/
/**
* @brief         Update physical address of the controller.
* @param[in]     pPhysAddrPtr Pointer to MAC address which should set to
*                controller. The address in network byte order stored into 6
*                bytes of memory.
* @param[in]     u8CtrlIdx Index of controller to set the PhysAddr
* @caution       Call of function Eth_43_PFE_Init changes the MAC address
*                to the default (from config set) value!
*/
boolean Eth_PFE_LLD_SetPhysAddr ( \
                    const uint8 u8CtrlIdx, \
                    const uint8 * pPhysAddrPtr \
                                              )
{
    boolean bReturnStatus = FALSE;
    errno_t res;
    trPfeDev *prPfeDev = &(arPfeInterface[u8CtrlIdx]);

    if(0 == autolibc_memcmp(prPfeDev->au8MacAddr, pPhysAddrPtr, 6u))
    {
        /* If the new MAC address is the same as already set in PFE platform, no need to do anything */
        bReturnStatus = TRUE;
    }
    else
    {
        if((PFE_CTRL_TYPE_AUX == ETH_43_PFE_CFG_CTRLTYPE(u8CtrlIdx))
        || (PFE_CTRL_TYPE_HIF == ETH_43_PFE_CFG_CTRLTYPE(u8CtrlIdx)))
        {
            /* Just update in driver */
            (void)autolibc_memcpy(prPfeDev->au8MacAddr, pPhysAddrPtr, 6U);
            bReturnStatus = TRUE;
        }
        else /* PFE_CTRL_TYPE_EMAC */
        { 
            /* First, delete previous MAC address from PFE platform */
            /* Note: the function Eth_43_PFE_Init should have always set a MAC address if it succeeded */
            if(EOK == pfe_phy_if_del_mac_addr(prPfeDev->prPhyIf, prPfeDev->au8MacAddr, rPlatformCfg.local_hif))
            {
                /* Then, add the new MAC address to the PFE platform */
                res = pfe_phy_if_add_mac_addr(prPfeDev->prPhyIf, pPhysAddrPtr, rPlatformCfg.local_hif);
                if((EOK == res) || (EEXIST == res))
                {
                    /* If the MAC address is successfully added, update the local value au8MacAddr */
                    (void)autolibc_memcpy(prPfeDev->au8MacAddr, pPhysAddrPtr, 6U);
                    bReturnStatus = TRUE;
                }
                else
                {
                    bReturnStatus = FALSE;
                }
            }
            else
            {
                bReturnStatus = FALSE;
            }
        }
    }
    return bReturnStatus;
}

/*================================================================================================*/
static Std_ReturnType UpdatePhysAddrFilter_AddBroad(const trPfeDev *prPfeDev)
{
    Std_ReturnType u8ReturnStatus = E_NOT_OK;

    /* Enable ALLMULTI mode. */
    if (EOK != pfe_phy_if_allmulti_enable(prPfeDev->prPhyIf))
    {
        NXP_LOG_ERROR("Failed to enable ALLMULTI mode\n");
    }
    else
    {
        u8ReturnStatus = E_OK;
    }

    return u8ReturnStatus;
}

/*================================================================================================*/
static Std_ReturnType UpdatePhysAddrFilter_RemoveBroad(const trPfeDev *prPfeDev)
{
    Std_ReturnType u8ReturnStatus = E_NOT_OK;

    if (EOK != pfe_phy_if_allmulti_disable(prPfeDev->prPhyIf))
    {
        NXP_LOG_ERROR("Failed to disable ALLMULTI mode\n");
    }
    else
    {
        u8ReturnStatus = E_OK;
    }

    return u8ReturnStatus;
}

/*================================================================================================*/
static Std_ReturnType UpdatePhysAddrFilter_Close(const trPfeDev *prPfeDev)
{
    Std_ReturnType u8ReturnStatus = E_NOT_OK;

    if (EOK != pfe_phy_if_allmulti_disable(prPfeDev->prPhyIf))
    {
        NXP_LOG_ERROR("Failed to disable ALLMULTI mode\n");
    }
    else if (EOK != pfe_phy_if_flush_mac_addrs( prPfeDev->prPhyIf, MAC_DB_CRIT_BY_OWNER_AND_TYPE, 
                                                PFE_TYPE_MC, rPlatformCfg.local_hif ))
    {
        NXP_LOG_ERROR("Failed to remove multicast addresses from phy_if\n");
    }
    else
    {
        u8ReturnStatus = E_OK;
    }

    return u8ReturnStatus;
}

/*================================================================================================*/
static Std_ReturnType UpdatePhysAddrFilter_AddMulti(const trPfeDev *prPfeDev, const uint8 * PhysAddrPtr)
{
    Std_ReturnType u8ReturnStatus = E_OK;
    errno_t res;

    /* Add new MAC address */
    res = pfe_phy_if_add_mac_addr(prPfeDev->prPhyIf, PhysAddrPtr, rPlatformCfg.local_hif);
    if ((EOK != res) && (EEXIST != res))
    {
        NXP_LOG_ERROR("Failed to add new MAC address\n");
        u8ReturnStatus = E_NOT_OK;
    }

    return u8ReturnStatus;
}

/*================================================================================================*/
static Std_ReturnType UpdatePhysAddrFilter_RemoveMulti(const trPfeDev *prPfeDev, const uint8 *PhysAddrPtr)
{
    Std_ReturnType u8ReturnStatus = E_NOT_OK;

    /* Delete MAC address */
    if (EOK != pfe_phy_if_del_mac_addr(prPfeDev->prPhyIf, PhysAddrPtr, rPlatformCfg.local_hif))
    {
        NXP_LOG_ERROR("Failed to delete MAC address\n");
    }
    else
    {
        u8ReturnStatus = E_OK;
    }

    return u8ReturnStatus;
}

/*================================================================================================*/
/**
* @brief         Adds or removes the specified PhysAddrPtr address to or from
*                a multicast address pool in the controller specified by u8CtrlIdx.
* @param[in]     u8CtrlIdx Index of controller to be transferred (AUX and HIF are not supported)
* @param[in]     PhysAddrPtr Pointer to PHY address which shall be added
*                or removed to or from multicast pool.
*                The address in network byte order stored into 6 bytes of
*                memory.
* @param[in]     Action Determine whenever the defined address will be added
*                to the pool ETH_ADD_TO_FILTER or removed from it
*                ETH_REMOVE_FROM_FILTER.
*/
Std_ReturnType Eth_PFE_LLD_UpdatePhysAddrFilter ( \
                                    uint8 u8CtrlIdx, \
                                    const uint8 * PhysAddrPtr, \
                                    Eth_FilterActionType Action \
                                              )
{
    Std_ReturnType u8ReturnStatus = E_NOT_OK;
    trPfeDev *prPfeDev = &(arPfeInterface[u8CtrlIdx]);

    if (PFE_CTRL_TYPE_AUX == ETH_43_PFE_CFG_CTRLTYPE(u8CtrlIdx))
    {
        NXP_LOG_WARNING("AUX interface is not supported\n");
        u8ReturnStatus = E_NOT_OK;
    }
    else if (PFE_CTRL_TYPE_HIF == ETH_43_PFE_CFG_CTRLTYPE(u8CtrlIdx))
    {
        NXP_LOG_WARNING("HIF interface is not supported\n");
        u8ReturnStatus = E_NOT_OK;
    }
    else /* PFE_CTRL_TYPE_EMAC */
    {
        if (pfe_emac_is_broad(PhysAddrPtr))
        {
            /* Completely opens the physical address filter. */
            if (ETH_ADD_TO_FILTER == Action)
            {
                /* Enable ALLMULTI mode. */
                u8ReturnStatus = UpdatePhysAddrFilter_AddBroad(prPfeDev);
            }
            else /* Don't allow pass all multicast addresses. */
            {
                /* Disable ALLMULTI mode. */
                u8ReturnStatus = UpdatePhysAddrFilter_RemoveBroad(prPfeDev);
            }
        }
        else if (pfe_emac_is_zero(PhysAddrPtr))
        {
            /* Completely closes the physical address filter. */
            if (ETH_ADD_TO_FILTER == Action)
            {
                u8ReturnStatus = UpdatePhysAddrFilter_Close(prPfeDev);
            }
        }
        else if (pfe_emac_is_multi(PhysAddrPtr))
        {
            /* Adds a multicast address to the physical address filter. */
            if (ETH_ADD_TO_FILTER == Action)
            {
                u8ReturnStatus = UpdatePhysAddrFilter_AddMulti(prPfeDev, PhysAddrPtr);
            }
            else  /* Removes a multicast address from the physical address filter. */
            {
                u8ReturnStatus = UpdatePhysAddrFilter_RemoveMulti(prPfeDev, PhysAddrPtr);
            }
        }
        else
        {
            NXP_LOG_RAW_ERROR("The parameter is not a multicast address or a special address (all-0 or all-F)\n");
#if(STD_ON == ETH_43_PFE_DEV_ERROR_DETECT)
            (void)Det_ReportError((uint8)ETH_43_PFE_MODULE_ID, ETH_43_PFE_DRIVER_INSTANCE, (uint8)ETH_43_PFE_SID_UPDATEADDRFILTER, ETH_43_PFE_E_INV_PARAM);
#endif /* STD_ON == ETH_43_PFE_DEV_ERROR_DETECT */
        }
    }

    return u8ReturnStatus;
}

/*================================================================================================*/
/**
* @brief         Finds empty Tx buffer and prepares it for loading with data
* @param[in]     u8CtrlIdx Index of controller from which the buffer shall be provided
* @param[in]     u8QueuIdx Index of Tx queue from which the buffer shall be provided
* @param[out]    pBufIdx Pointer to variable, where the granted buffer index will be written.
* @param[out]    pData Pointer to variable, where the pointer to provided data buffer will be written.
* @param[in,out] pLength Buffer length
* @retval        TRUE An empty buffer was found and granted.
* @retval        FALSE There is no sufficiently big empty buffer available at the moment.
*/
boolean Eth_PFE_LLD_ProvideBufferDataArea \
( \
    const uint8 u8CtrlIdx, \
    const uint8 u8QueuIdx, \
    Eth_BufIdxType * const pBufIdx, \
    uint8 **pData, \
    uint16 * const pLength \
)
{
    uint8 *pBuffer = NULL;
    Eth_BufIdxType BufIdx;
    sint32 s32BufLen;
    boolean bRetVal = FALSE;
    trTxMeta *prTxMeta;
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
    pfe_ct_hif_tx_hdr_t *pTxHeader;
    uint8 u8Queue;
    errno_t ret;
    trPfeDev *prPfeDev = &(arPfeInterface[u8CtrlIdx]);
    uint16 lmem_header_size = pfe_hif_chnl_get_lmem_hdr_size(arPfeInterface[u8CtrlIdx].prHifChnl);
#else
    uint16 lmem_header_size = 0U;
#endif
    const uint32 tx_buffer_size = Eth_43_PFE_LLD_GetTxBufferSize(u8CtrlIdx, u8QueuIdx);
    PfeDevAssert(tx_buffer_size < (uint32)INT32_MAX);
    s32BufLen = (sint32)tx_buffer_size
              - (sint32)TX_BUF_FRAME_OFFSET - (sint32)lmem_header_size - (sint32)PFE_LLD_L2_HEADER_SIZE;
    if((sint32)(*pLength) <= s32BufLen)
    {
        if(TRUE == GetTxBuffer(u8CtrlIdx, u8QueuIdx, &BufIdx))
        {
            pBuffer = (uint8 *)aarTxBuf[u8CtrlIdx][BufIdx].BufAddr;
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
            /* Initialize Tx header after the tx buffer has been assigned by BMU */
            u8Queue = aarTxBuf[u8CtrlIdx][BufIdx].u8Fifo;
            pTxHeader = (pfe_ct_hif_tx_hdr_t *)&pBuffer[lmem_header_size + 256U];
            ret = pfe_hif_drv_init_tx_header(prPfeDev->prClient, pTxHeader, u8Queue);
            if (EOK != ret)
            {
                 NXP_LOG_ERROR("Failed to initialize tx header when using HIF_NOCPY\n");
            }
#endif
            *pData = &pBuffer[TX_BUF_FRAME_OFFSET + PFE_LLD_L2_HEADER_SIZE + lmem_header_size];
            /* TS request is disabled unless Eth_43_PFE_LLD_EnableEgressTimeStamp is called */
            prTxMeta = Eth_PFE_LLD_GetTxBufMeta(u8CtrlIdx, BufIdx);
            prTxMeta->bDoTS = FALSE;
            *pBufIdx = BufIdx;
            bRetVal = TRUE;
        }
    }
    /* Return available payload length */
    *pLength = (uint16)s32BufLen;

    return bRetVal;
}

/*================================================================================================*/
/**
* @brief         Get the value of LMEM Header size used by the HW.
* @param[in]     u8CtrlIdx Index of the controller.
* @retval        The size of LMEM Header.
*/
uint16 Eth_43_PFE_LLD_GetLmemHdrSize(const uint8 u8CtrlIdx)
{
    uint16 lmem_header_size;

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
    lmem_header_size = pfe_hif_chnl_get_lmem_hdr_size(arPfeInterface[u8CtrlIdx].prHifChnl);
#else
    lmem_header_size = 0U;
#endif

    (void)u8CtrlIdx;

    return lmem_header_size;
}

/*================================================================================================*/
/**
* @brief         Get Tx Fifo index of the given Tx buffer.
* @param[in]     u8CtrlIdx Index of the controller which the given Tx buffer is belong to.
* @param[in]     BufIdx Index of the Tx buffer.
* @retval        Fifo index of the given Tx buffer.
*/
uint8 Eth_43_PFE_LLD_GetTxFifoIdx(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx)
{
    return aarTxBuf[u8CtrlIdx][BufIdx].u8Fifo;
}

/*================================================================================================*/
/**
* @brief         Get Tx buffer size of the given Tx Fifo.
* @param[in]     u8CtrlIdx Index of the controller which the given Tx Fifo is belong to.
* @param[in]     u8FifoIdx Index of the Tx Fifo.
* @retval        Tx buffer size of the given Tx Fifo.
*/
uint32 Eth_43_PFE_LLD_GetTxBufferSize(const uint8 u8CtrlIdx, const uint8 u8FifoIdx)
{
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
    (void)u8CtrlIdx;
    (void)u8FifoIdx;
    return PFE_CFG_BMU2_BUF_SIZE;
#else
    return aarTxBufPool[u8CtrlIdx][u8FifoIdx].u32BufSize;
#endif
}

#if STD_ON == ETH_43_PFE_RELEASE_TX_BUFFER_API
/*================================================================================================*/
/**
* @brief         Release Tx buffer
* @param[in]     u8CtrlIdx Index of controller which will be relesed
* @param[in]     BufIdx DA Index of the buffer to be released
* @retval        TRUE - Buffer successfully released
* @retval        FALSE - Buffer was busy - not released
*/
boolean Eth_PFE_LLD_ReleaseTxBuffer(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx)
{
    boolean res = FALSE;
    const uint8 status = aarTxBuf[u8CtrlIdx][BufIdx].u8Status;

    if((status == TX_BUF_FREE) || (status == TX_BUF_PROVIDED))
    {
        ReleaseTxBuffer(u8CtrlIdx, BufIdx);
        res = TRUE;
    }
     
    return res;
}
#endif

/*================================================================================================*/
/**
* @brief         Triggers the transmission of the given buffer
* @param[in]     u8CtrlIdx Index of controller which will be triggered the transmission
* @param[in]     BufIdx DA Index of the buffer to be transmitted
* @param[in]     u16Type Type or length field value in the 802.3 frame header
* @param[in]     u16Length Payload length
* @param[in]     bConfirm Selects whether the frame transmission shall
*                be confirmed or not
* @param[in]     pDest Frame destination address
* @details       Function decrements the buffer address in the transmit buffer
*                descriptor assigned to the given DA by 14 bytes in order to get
*                the frame header beginning. The frame header is constructed
*                using the given destination address and type or length field
*                values. The source address is added by ENET natively.
*
*                - The Lock and bit is cleared if the transmission
*                  confirmation is disabled and buffer will become empty
*                  after the transmission.
*                - Transmitted bit (user bit 2) is set and Lock is bit left set
*                  if the transmission confirmation is enabled. Then the buffer
*                  will stay locked after the transmission but it can be
*                  recognized as already transmitted  because of the set
*                  Transmitted bit. Such buffer cannot be used until it is
*                  confirmed and bits are cleared.
*
*                The Ready bit is set to trigger the buffer transmission and the
*                controller is notified about the new buffer by a write into the
*                TDAR register.
*/
Std_ReturnType Eth_PFE_LLD_Transmit
(
    const uint8 u8CtrlIdx,
    const Eth_BufIdxType BufIdx,
    const Eth_FrameType u16Type,
    const uint16 u16Length,
    const boolean bConfirm,
    const uint8 *pDest
)
{
    Std_ReturnType RetVal = E_NOT_OK;
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
    const uint16 lmem_header_size = pfe_hif_chnl_get_lmem_hdr_size(arPfeInterface[u8CtrlIdx].prHifChnl);
#else
    const uint16 lmem_header_size = 0U;
#endif
    const uint8 *apu8MacAddr = arPfeInterface[u8CtrlIdx].au8MacAddr;
    trTxMeta *prTxMeta = Eth_PFE_LLD_GetTxBufMeta(u8CtrlIdx, BufIdx);
    uint8 u8NewBufStatus = TX_BUF_WAIT_CONF | TX_BUF_TO_REPORT;
    uint16 u16frameLength = (uint16)(((uint32)u16Length + PFE_LLD_L2_HEADER_SIZE) & UINT16_MAX);
    uint8  *framePtr = (uint8 *)(uint32)(((uint64)aarTxBuf[u8CtrlIdx][BufIdx].BufAddr + TX_BUF_FRAME_OFFSET + lmem_header_size) & UINT32_MAX);

    if (TX_BUF_PROVIDED != aarTxBuf[u8CtrlIdx][BufIdx].u8Status)
    {
        NXP_LOG_ERROR("Attempted to transmit buffer with wrong status\n");
        if(TRUE == bConfirm)
        {
            EthIf_TxConfirmation(ETH_43_PFE_CFG_CTRLIDXINETHIF(u8CtrlIdx), BufIdx, E_NOT_OK);
        }
    }
    else
    {
        /*  Update TX metadata */
        prTxMeta->bDoTxIndication = bConfirm;
        prTxMeta->bDoTS = prTxMeta->bDoTS && bConfirm; /* No way to report timestamp without confirnation enabled */

        /*  Fill in Ethernet header */
        (void)autolibc_memcpy(&framePtr[ETH_FRAME_MACDST_IDX], pDest, 6u);
        (void)autolibc_memcpy(&framePtr[ETH_FRAME_MACSRC_IDX], apu8MacAddr, 6u);
        framePtr[ETH_FRAME_ETHERTYPE_IDX]    = (uint8)(u16Type >> 8);
        framePtr[ETH_FRAME_ETHERTYPE_IDX+1u] = (uint8)(u16Type & 0xFFU);

#if (STD_ON == ETH_43_PFE_GLOBALTIME_SUPPORT)
        aarTxBuf[u8CtrlIdx][BufIdx].TimeQual = ETH_INVALID;
        /*  Check TS request */
        if (TRUE == prTxMeta->bDoTS)
        {
            TxReqTsQueueWrite(u8CtrlIdx, BufIdx);
            u8NewBufStatus |= TX_BUF_WAIT_TS;
        }
#endif /* ETH_43_PFE_GLOBALTIME_SUPPORT */

#if (STD_ON == ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API)
        if ((Std_ReturnType)E_OK == TxReqSwt(u8CtrlIdx, BufIdx, &framePtr[ETH_FRAME_ETHERTYPE_IDX], &u16frameLength))
#endif /* ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API*/
        {
            errno_t Status = EOK;
            /* MUST update BufStatus before writing to TxReqQueue */
            aarTxBuf[u8CtrlIdx][BufIdx].u8Status = u8NewBufStatus;
            Status = TxReqTrigger(u8CtrlIdx, BufIdx, u16frameLength);
            if(EOK != Status)
            {
                NXP_LOG_ERROR("Transmission has failed (%d)\n", Status);
                TxReqFailed(u8CtrlIdx, BufIdx);
            }
            else 
            {
                RetVal = E_OK;
            }
        }
    }

    return RetVal;
}

/*================================================================================================*/
static boolean IsRxChecksumValidIpV4(const pfe_hif_pkt_t *RxPacket, uint8 Protocol)
{
    boolean checksum_valid = TRUE;

#if (STD_ON == ETH_43_PFE_ENABLE_OFFLOAD_CSUM_IPV4)
    /* Check if IPv4 checksum has been verified and is valid */
    if (pfe_hif_pkt_ipv4_csum_valid(RxPacket) == FALSE)
    {   /* Checksum mismatch, shall be discarded */
        checksum_valid = FALSE;
    }
#endif /* ETH_43_PFE_ENABLE_OFFLOAD_CSUM_IPV4 */
    /* Check for Protocol */
#if (STD_ON == ETH_43_PFE_ENABLE_OFFLOAD_CSUM_UDP)
    /* Check if L4 Protocol of received frame is UDP */
    if(Protocol == 0x11U)
    {   /* Check if UDP checksum has been verified and is valid */
        if (pfe_hif_pkt_udpv4_csum_valid(RxPacket) == FALSE)
        {   /* Checksum mismatch, shall be discarded */
            checksum_valid = FALSE;
        }
    }
#endif /* ETH_43_PFE_ENABLE_OFFLOAD_CSUM_UDP */
#if (STD_ON == ETH_43_PFE_ENABLE_OFFLOAD_CSUM_TCP)
    /* Check if L4 Protocol of received frame is TCP */
    if(Protocol == 0x06U)
    {   /* Check if TCP checksum has been verified and is valid */
        if (pfe_hif_pkt_tcpv4_csum_valid(RxPacket) == FALSE)
        {   /* Checksum mismatch, shall be discarded */
            checksum_valid = FALSE;
        }
    }
#endif /* ETH_43_PFE_ENABLE_OFFLOAD_CSUM_TCP */
#if (STD_ON == ETH_43_PFE_ENABLE_OFFLOAD_CSUM_ICMP)
    if(Protocol == 0x01U)
    {   /* Check if ICMP checksum has been verified and is valid */
        if (pfe_hif_pkt_icmp_csum_valid(RxPacket) == FALSE)
        {   /* Checksum mismatch, shall be discarded */
            checksum_valid = FALSE;
        }
    }
#endif /* ETH_43_PFE_ENABLE_OFFLOAD_CSUM_ICMP */

    /* avoid 'unused' parameter warning */
    (void)RxPacket;
    (void)Protocol;

    return checksum_valid;
}

/*================================================================================================*/
static boolean IsRxChecksumValidIpV6(const pfe_hif_pkt_t *RxPacket, uint8 Protocol)
{
    boolean checksum_valid = TRUE;

    /* Check for Protocol */
#if (STD_ON == ETH_43_PFE_ENABLE_OFFLOAD_CSUM_UDP)
    /* Check if L4 Protocol of received frame is UDP */
    if(Protocol == 0x11U)
    {   /* Check if UDP checksum has been verified and is valid */
        if (pfe_hif_pkt_udpv6_csum_valid(RxPacket) == FALSE)
        {   /* Checksum mismatch, shall be discarded */
            checksum_valid = FALSE;
        }
    }
#endif /* ETH_43_PFE_ENABLE_OFFLOAD_CSUM_UDP */
#if (STD_ON == ETH_43_PFE_ENABLE_OFFLOAD_CSUM_TCP)
    /* Check if L4 Protocol of received frame is TCP */
    if(Protocol == 0x06U)
    {   /* Check if TCP checksum has been verified and is valid */
        if (pfe_hif_pkt_tcpv6_csum_valid(RxPacket) == FALSE)
        {   /* Checksum mismatch, shall be discarded */
            checksum_valid = FALSE;
        }
    }
#endif /* ETH_43_PFE_ENABLE_OFFLOAD_CSUM_TCP */
#if (STD_ON == ETH_43_PFE_ENABLE_OFFLOAD_CSUM_ICMP)
    if(Protocol == 0x3AU)
    {   /* Check if ICMP checksum has been verified and is valid */
        if (pfe_hif_pkt_icmp_csum_valid(RxPacket) == FALSE)
        {   /* Checksum mismatch, shall be discarded */
            checksum_valid = FALSE;
        }
    }
#endif /* ETH_43_PFE_ENABLE_OFFLOAD_CSUM_ICMP */

    /* avoid 'unused' parameter warning */
    (void)RxPacket;
    (void)Protocol;

    return checksum_valid;
}

/*================================================================================================*/
static boolean IsRxChecksumValid(const pfe_hif_pkt_t *RxPacket, const uint8 *pEtherType)
{
    boolean checksum_valid = TRUE;
    Eth_FrameType EtherType = (Eth_FrameType)pu8_to_be16(pEtherType);

    if(EtherType == ETHERTYPE_IPV4) 
    {
        const uint8 Protocol = pEtherType[11];
        checksum_valid = IsRxChecksumValidIpV4(RxPacket, Protocol);
    }
    else if(EtherType == ETHERTYPE_IPV6) 
    {
        const uint8 Protocol = pEtherType[8];
        checksum_valid = IsRxChecksumValidIpV6(RxPacket, Protocol);
    }
    else 
    {
        checksum_valid = TRUE;
    }

    return checksum_valid;
}

/*================================================================================================*/
static uint8 ReportReception_GetBypassVLANTag(Eth_FrameType FrameType)
{
    uint8 BypassVLANTag = 0; /* BypassVLANTag */

    if (FrameType == 0x88A8U)
    {   /*It's a VLAN Double-Tagged Frame. Look for frame type*/
        BypassVLANTag = 8U;
    }
    else if (FrameType == 0x8100U)
    {   /*It's a VLAN Tagged Frame. Look for frame type*/
        BypassVLANTag = 4U;
    }
    else
    {   /*Frame type acquired*/
        BypassVLANTag = 0U;
    }

    return BypassVLANTag;
}

/*================================================================================================*/
static void ReportReception_ProcessPacket(uint8 u8CtrlIdx, uint8 u8FifoIdx, const pfe_hif_pkt_t *RxPacket)
{
    uint8 *pFrame;
    uint32 u32DataLen;
    Eth_DataType * pPayloadPtr;
    Eth_FrameType FrameType; /* EtherType */
    uint8 BypassVLANTag = 0; /* BypassVLANTag */
    boolean IsBroadcast;
    uint8 * SrcAddrPtr; /* Pointer to source address */
    boolean IsMgmtFrameOnlyPtr = FALSE;
    uint16 FrameLength = 0;
#if (STD_ON == ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API)
    Eth_BufIdxType BufIdx = 0;
    uint8*  DataPtr;
#endif /* ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API */

    /* Suppress compiler warning for unused function parameter */
    (void) u8FifoIdx;

    /* Parse Ethernet frame and determine frame type */
    pFrame = (uint8 *)(uint32)(((uint64)pfe_hif_pkt_get_data(RxPacket) + HIF_HEADER_SIZE) & UINT32_MAX);
    FrameType = (Eth_FrameType)pu8_to_be16(&pFrame[ETH_FRAME_ETHERTYPE_IDX]);
    BypassVLANTag = ReportReception_GetBypassVLANTag(FrameType);

    if(TRUE == IsRxChecksumValid(RxPacket, &pFrame[ETH_FRAME_ETHERTYPE_IDX + BypassVLANTag]))
    {
        /* Whole packet successfully received */
        /* Get whole Ethernet frame without HIF header */
        FrameLength = (uint16)(pfe_hif_pkt_get_data_len(RxPacket) & 0xFFFFU);
        PfeDevAssert(FrameLength >= HIF_HEADER_SIZE);
        FrameLength -= HIF_HEADER_SIZE;

        /* Check if received frame is jumbo frame */
        if(FrameLength > (PFE_INGRESS_MAX_FRAME_SIZE + BypassVLANTag))
        {
            FrameLength = PFE_INGRESS_MAX_FRAME_SIZE + BypassVLANTag;
        }

#if (STD_ON == ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API)
        DataPtr = &pFrame[ETH_FRAME_ETHERTYPE_IDX + BypassVLANTag];
        (void)Eth_43_PFE_InternalCfgPtr->pController[u8CtrlIdx]->
        Eth_43_PFE_EthSwtDriverFunctionList.RxProcessFrameFunction( u8CtrlIdx, \
                                        BufIdx, \
                                        &DataPtr,\
                                        &FrameLength, \
                                        &IsMgmtFrameOnlyPtr\
                                        );
#endif /* ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API */
        /* Parse Ethernet header */
        static const uint8 mac_broadcast[6] = {0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU};
        IsBroadcast = (0 == autolibc_memcmp(&pFrame[ETH_FRAME_MACDST_IDX], mac_broadcast, sizeof(mac_broadcast)));
        SrcAddrPtr = &pFrame[ETH_FRAME_MACSRC_IDX];
        /* Get payload - strip Ethernet header and CRC */
        pPayloadPtr = (Eth_DataType *)&pFrame[PFE_LLD_L2_HEADER_SIZE];
        PfeDevAssert(FrameLength >= PFE_LLD_L2_HEADER_SIZE);
        u32DataLen = ((uint32)FrameLength - PFE_LLD_L2_HEADER_SIZE);
        /* Pass to upper layer */
        if (FALSE == IsMgmtFrameOnlyPtr)
        {
            EthIf_RxIndication( ETH_43_PFE_CFG_CTRLIDXINETHIF(u8CtrlIdx), \
                                FrameType, IsBroadcast, SrcAddrPtr, \
                                pPayloadPtr, (uint16)u32DataLen \
                            );
        }
#if (STD_ON == ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API)
        (void)Eth_43_PFE_InternalCfgPtr->pController[u8CtrlIdx]->
        Eth_43_PFE_EthSwtDriverFunctionList.RxFinishedIndicationFunction(u8CtrlIdx, u8FifoIdx);
#endif /* ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API */
    }
    pfe_hif_pkt_free(RxPacket);
}

/*================================================================================================*/
/**
* @brief         Reports received frames to the upper layer
* @param[in]     u8CtrlIdx Index of the controller to report receptions
* @param[in]     bIrq Selects between the poll driven and interrupt driven
*                mode (algorithm). The value TRUE means interrupt driven mode.
* @note          The function reports all found frames in the interrupt driven
*                mode. In the poll driven mode it reports only the first found
*                frame signals whether there is at least another frame to be
*                received (in the next call).
* @return        In the poll driven mode signalizes whether a frame has been
*                reported to the EthIf module and whether another frame is
*                available. It shall be ignored in the interrupt driven mode.
* @retval        ETH_RECEIVED Only one frame received
* @retval        ETH_NOT_RECEIVED No frame received
* @retval        ETH_RECEIVED_MORE_DATA_AVAILABLE More frames received
*                frame was discarded.
*/
Eth_RxStatusType Eth_PFE_LLD_ReportReception(const uint8 u8CtrlIdx, uint8 u8FifoIdx, const boolean bIrq)
{
    Eth_RxStatusType RetVal = ETH_NOT_RECEIVED;
    const pfe_hif_pkt_t *RxPacket;
    pfe_hif_drv_client_t *prClient = arPfeInterface[u8CtrlIdx].prClient;
#if (FALSE == PFE_CFG_HIF_IRQ_ENABLED)
    trPfeDev *prPfeDev = &arPfeInterface[u8CtrlIdx];
    /* Do Rx job in polling mode */
    pfe_hif_drv_rx_job((void *)prPfeDev->prHifDrv);
#endif /* PFE_CFG_HIF_IRQ_ENABLED */

    do
    {
        RxPacket = pfe_hif_drv_client_receive_pkt(prClient, u8FifoIdx);
        if(NULL_PTR != RxPacket)
        {   /* Process the packet */
            ReportReception_ProcessPacket(u8CtrlIdx, u8FifoIdx, RxPacket);
            RetVal = ETH_RECEIVED;
        }
    } while((TRUE == bIrq) && (NULL_PTR != RxPacket)); /* In IRQ mode process all */

    /* Re-enable interrupt + DMA */
    pfe_hif_drv_client_rx_done(prClient);

    /* In polling mode check if next Rx frame is available */
    if((FALSE == bIrq) && (ETH_RECEIVED == RetVal))
    {
        /* Only check if there is another one */
        if(TRUE == pfe_hif_drv_client_has_rx_pkt(prClient, u8FifoIdx))
        {
            RetVal = ETH_RECEIVED_MORE_DATA_AVAILABLE;
        }
    }


    return RetVal;
}

/*================================================================================================*/
/**
* @brief        Confirms transmission of all transmitted buffers that are not waiting for timestamp
* @param[in]    u8CtrlIdx Index of the controller to report transmissions
* @param[in]    u8FifoIdx Tx FIFO index
* @details      Function examines all transmit buffers whether some of them
*               have been already sent and whether they should be confirmed. EthIf_TxConfirmation 
*               is called for each such buffer except buffers waiting for timestamp.
*/
void Eth_PFE_LLD_ReportTransmission(const uint8 u8CtrlIdx, const uint8 u8FifoIdx)
{
    const pfe_hif_drv_client_t *prClient = arPfeInterface[u8CtrlIdx].prClient;
    const trTxMeta *prTxMeta;
    const Eth_PFE_LLD_trTxRefData *prRefData;
    Eth_BufIdxType BufIdx;
    uint8 u8BufStatus;
    Std_ReturnType Status;
    bool_t bStillSearching = TRUE;
#if (FALSE == PFE_CFG_HIF_IRQ_ENABLED)
    trPfeDev *prPfeDev = &arPfeInterface[u8CtrlIdx];
#endif /* PFE_CFG_HIF_IRQ_ENABLED */

#if (FALSE == PFE_CFG_HIF_IRQ_ENABLED)
    /* Do Tx job in polling mode */
    pfe_hif_drv_tx_job((void *)prPfeDev->prHifDrv);
#endif /* PFE_CFG_HIF_IRQ_ENABLED */

    /* Repeat as long as there is some confirmation */
    while(TRUE)
    {
        prRefData = (Eth_PFE_LLD_trTxRefData *)pfe_hif_drv_client_receive_tx_conf(prClient, u8FifoIdx);
        if (NULL_PTR == prRefData)
        {
            break;
        }
        else
        {
            BufIdx = prRefData->u16BufIdx;
            aarTxBuf[u8CtrlIdx][BufIdx].u8Status &= (uint8)(~TX_BUF_WAIT_CONF & 0xFFU);
        }
    }
    pfe_hif_drv_client_tx_done(prClient);

    /* Process Tx request queue */
    while(TRUE == bStillSearching)
    {
        prRefData = TxReqQueueRead(u8CtrlIdx);
        BufIdx = prRefData->u16BufIdx;
        if(INVALID_TX_INDEX == BufIdx)
        {
            /* Queue is empty */
            bStillSearching = FALSE;
        }
        else
        {
            u8BufStatus = aarTxBuf[u8CtrlIdx][BufIdx].u8Status;
            if(0U == (TX_BUF_WAIT_CONF & u8BufStatus))
            {
                /* Buffer confirmed or failed -> ready to be removed from TxReqQueue */
                TxReqQueueDelete(u8CtrlIdx);
                if((TX_BUF_TO_REPORT == u8BufStatus) || (TX_BUF_FAILED == u8BufStatus))
                {
                    /* Buffer also ready to be reported and released */
                    prTxMeta = Eth_PFE_LLD_GetTxBufMeta(u8CtrlIdx, BufIdx);
                    if(TRUE == prTxMeta->bDoTxIndication)
                    {
                        Status = (TX_BUF_FAILED == u8BufStatus) ? E_NOT_OK : E_OK;
                        oal_mutex_lock(PFE_ETHIF_TXCONFIR_API_MUTEX_00);
                        EthIf_TxConfirmation( ETH_43_PFE_CFG_CTRLIDXINETHIF(u8CtrlIdx), BufIdx, Status);
                        oal_mutex_unlock(PFE_ETHIF_TXCONFIR_API_MUTEX_00);
                    }
                    aarTxBuf[u8CtrlIdx][BufIdx].u8Status = TX_BUF_FREE;
                }
            }
            else
            {
                /* Buffer not confirmed yet */
                bStillSearching = FALSE;
            }
        }
    }
}

#if (STD_ON == ETH_43_PFE_GLOBALTIME_SUPPORT)
/*================================================================================================*/
/**
* @brief        Function gets all received Tx timestamps and confirms transmission of buffers
*               which were waiting only for timestamp
* @param[in]    u8CtrlIdx Index of the controller to report transmissions
* @param[in]    u8FifoIdx Tx FIFO index
* @details      The timestamps are stored in runtime buffer data structure. Buffer is not reported
*               if it still waits for Tx confirmation. In that case it will be reported in function
*               Eth_PFE_LLD_ReportTransmission.
*/
void Eth_PFE_LLD_ReportTransmissionTS(const uint8 u8CtrlIdx, const uint8 u8FifoIdx)
{
    Eth_BufIdxType BufIdx;
    uint8 u8BufStatus;
    errno_t Error;
    bool_t bContinue = TRUE;
#if (FALSE == PFE_CFG_HIF_IRQ_ENABLED)
    trPfeDev *prPfeDev = &arPfeInterface[u8CtrlIdx];
#endif /* PFE_CFG_HIF_IRQ_ENABLED */

#if (FALSE == PFE_CFG_HIF_IRQ_ENABLED)
    /* Do Rx job in polling mode */
    pfe_hif_drv_rx_job((void *)prPfeDev->prHifDrv);
#endif /* PFE_CFG_HIF_IRQ_ENABLED */

    do
    {
        /* Enter exclusive area to protect the read-out of the TS queue */
        oal_mutex_lock(PFE_TS_QUEUE_READ_MUTEX);

        /* Get next buffer index from TS queue */
        BufIdx = arPfeInterface[u8CtrlIdx].TSQueue[u8FifoIdx][arPfeInterface[u8CtrlIdx].u16TSQueueRead[u8FifoIdx]];
        if(INVALID_TX_INDEX == BufIdx)
        {   /* The queue is empty */
            bContinue = FALSE;
        }
        else
        {
            /* Try to get timestamp from database, store it to runtime buffer data */
            Error = GetTxTimeStamp(u8CtrlIdx, BufIdx, \
                                   &aarTxBuf[u8CtrlIdx][BufIdx].TimeQual, \
                                   &aarTxBuf[u8CtrlIdx][BufIdx].TimeStamp \
                                  );
            if (EAGAIN == Error)
            {   /* No more timestamps to process */
                bContinue = FALSE;
            }
            else
            {
                /* Remove the buffer from TS queue */
                arPfeInterface[u8CtrlIdx].TSQueue[u8FifoIdx][arPfeInterface[u8CtrlIdx].u16TSQueueRead[u8FifoIdx]] = INVALID_TX_INDEX;
                if(arPfeInterface[u8CtrlIdx].u16TSQueueRead[u8FifoIdx] >= (ETH_43_PFE_MAX_FIFO_TX_BUF_CNT - 1U))
                {   /* wrap */
                    arPfeInterface[u8CtrlIdx].u16TSQueueRead[u8FifoIdx] = 0U;
                }
                else
                {
                    arPfeInterface[u8CtrlIdx].u16TSQueueRead[u8FifoIdx]++;
                }

                if(ENOENT == Error)
                {
                    NXP_LOG_WARNING("Requested egress timestamp was not provided on controller %hhu\n", u8CtrlIdx);
                }
                
                /* Check if we should also report the buffer here */
                u8BufStatus = aarTxBuf[u8CtrlIdx][BufIdx].u8Status;
                if((TX_BUF_WAIT_TS | TX_BUF_TO_REPORT) == u8BufStatus)
                {
                    /* Yes, we were waiting only for the timestamp */
                    oal_mutex_lock(PFE_ETHIF_TXCONFIR_API_MUTEX_01);
                    EthIf_TxConfirmation(ETH_43_PFE_CFG_CTRLIDXINETHIF(u8CtrlIdx), BufIdx, E_OK);
                    oal_mutex_unlock(PFE_ETHIF_TXCONFIR_API_MUTEX_01);

                    /* Return buffer to pool */
                    aarTxBuf[u8CtrlIdx][BufIdx].u8Status = TX_BUF_FREE;
                }
                else
                {
                    /* Otherwise it will be reported when we get Tx confirmation */
                    aarTxBuf[u8CtrlIdx][BufIdx].u8Status &= (uint8)(~TX_BUF_WAIT_TS & 0xFFU);
                }
            }
        }
        oal_mutex_unlock(PFE_TS_QUEUE_READ_MUTEX);
    }
    while (TRUE == bContinue);
}
#endif /*ETH_43_PFE_GLOBALTIME_SUPPORT*/

#ifdef PFE_CFG_PFE_MASTER
/*================================================================================================*/
static void Eth_PFE_LLD_PollerFunction_ECC(void)
{
    if (NULL != ptrPlatform->ecc_err)
    {
        pfe_ecc_err_irq_mask(ptrPlatform->ecc_err);
        (void)pfe_ecc_err_isr(ptrPlatform->ecc_err);
        pfe_ecc_err_irq_unmask(ptrPlatform->ecc_err);
    }
}

/*================================================================================================*/
static void Eth_PFE_LLD_PollerFunction_WDG(void)
{
    if (NULL != ptrPlatform->wdt)
    {
        pfe_wdt_irq_mask(ptrPlatform->wdt);
        (void)pfe_wdt_isr(ptrPlatform->wdt);
        pfe_wdt_irq_unmask(ptrPlatform->wdt);
    }
}

/*================================================================================================*/
static void Eth_PFE_LLD_PollerFunction_EMAC(void)
{
    for (uint32 i = 0; i < ptrPlatform->emac_count; i++)
    {
        if (NULL != ptrPlatform->emac[i])
        {
            pfe_emac_irq_mask(ptrPlatform->emac[i]);
            (void)pfe_emac_isr(ptrPlatform->emac[i]);
            pfe_emac_irq_unmask(ptrPlatform->emac[i]);
        }
    }
}

/*================================================================================================*/
static void Eth_PFE_LLD_PollerFunction_BUS(void)
{
    if (NULL != ptrPlatform->bus_err)
    {
        pfe_bus_err_irq_mask(ptrPlatform->bus_err);
        (void)pfe_bus_err_isr(ptrPlatform->bus_err);
        pfe_bus_err_irq_unmask(ptrPlatform->bus_err);
    }
}

/*================================================================================================*/
static void Eth_PFE_LLD_PollerFunction_PARITY(void)
{
    if (NULL != ptrPlatform->parity)
    {
        pfe_parity_irq_mask(ptrPlatform->parity);
        (void)pfe_parity_isr(ptrPlatform->parity);
        pfe_parity_irq_unmask(ptrPlatform->parity);
    }
}

/*================================================================================================*/
static void Eth_PFE_LLD_PollerFunction_FAILSTOP(void)
{
    /* Fail Stop (HW)*/
    if (NULL != ptrPlatform->fail_stop)
    {
        pfe_fail_stop_irq_mask(ptrPlatform->fail_stop);
        (void)pfe_fail_stop_isr(ptrPlatform->fail_stop);
        pfe_fail_stop_irq_unmask(ptrPlatform->fail_stop);
    }

    /* Fail Stop (FW) */
    if (NULL != ptrPlatform->fw_fail_stop)
    {
        pfe_fw_fail_stop_irq_mask(ptrPlatform->fw_fail_stop);
        (void)pfe_fw_fail_stop_isr(ptrPlatform->fw_fail_stop);
        pfe_fw_fail_stop_irq_unmask(ptrPlatform->fw_fail_stop);
    }

    /* Fail Stop (SW) */
    if (NULL != ptrPlatform->host_fail_stop)
    {
        pfe_host_fail_stop_irq_mask(ptrPlatform->host_fail_stop);
        (void)pfe_host_fail_stop_isr(ptrPlatform->host_fail_stop);
        pfe_host_fail_stop_irq_unmask(ptrPlatform->host_fail_stop);
    }
}

/*================================================================================================*/
static void Eth_PFE_LLD_PollerFunction_BMU(void)
{
    for (uint32 i = 0; i < ptrPlatform->bmu_count; i++)
    {
        if (NULL != ptrPlatform->bmu[i])
        {
            pfe_bmu_irq_mask(ptrPlatform->bmu[i]);
            (void)pfe_bmu_isr(ptrPlatform->bmu[i]);
            pfe_bmu_irq_unmask(ptrPlatform->bmu[i]);
        }
    }
}

/*================================================================================================*/
static void Eth_PFE_LLD_PollerFunction_CLASS(void)
{
    if (NULL != ptrPlatform->classifier)
    {
        pfe_class_irq_mask(ptrPlatform->classifier);
        (void)pfe_class_isr(ptrPlatform->classifier);
        pfe_class_irq_unmask(ptrPlatform->classifier);
    }
}

/*================================================================================================*/
static void Eth_PFE_LLD_PollerFunction_UTIL(void)
{
    if (NULL != ptrPlatform->util)
    {
        pfe_util_irq_mask(ptrPlatform->util);
        (void)pfe_util_isr(ptrPlatform->util);
        pfe_util_irq_unmask(ptrPlatform->util);
    }
}

/*================================================================================================*/
static void Eth_PFE_LLD_PollerFunction_HIF(void)
{
    if (NULL != ptrPlatform->hif)
    {
        pfe_hif_irq_mask(ptrPlatform->hif);
        (void)pfe_hif_isr(ptrPlatform->hif);
        pfe_hif_irq_unmask(ptrPlatform->hif);
    }
}

/**
* @brief        Get errors from interrupt sources and report to Heath Monitor.
* @details      The function checks for errors by polling interrupt sources
*               and report to Health Monitor
* @return       N/A
*/
static void Eth_PFE_LLD_PollerFunction(void)
{
    /* Polling all interrupt sources and report errors to Health Monitor */

    /* PFE ECC */
    Eth_PFE_LLD_PollerFunction_ECC();

    /* PFE Watchdog */
    Eth_PFE_LLD_PollerFunction_WDG();

    /* EMAC */
    Eth_PFE_LLD_PollerFunction_EMAC();

    /* Bus */
    Eth_PFE_LLD_PollerFunction_BUS();

    /* Parity */
    Eth_PFE_LLD_PollerFunction_PARITY();

    /* Fail Stop (HW, FW, SW)*/
    Eth_PFE_LLD_PollerFunction_FAILSTOP();

    /* BMU */
    Eth_PFE_LLD_PollerFunction_BMU();

    /* Classifier */
    Eth_PFE_LLD_PollerFunction_CLASS();

    /* UTIL */
    Eth_PFE_LLD_PollerFunction_UTIL();

    /* HIF */
    Eth_PFE_LLD_PollerFunction_HIF();
}
#endif /* PFE_CFG_PFE_MASTER */

/*================================================================================================*/
/**
* @brief        Get errors and lost frames.
* @details      The function checks for controller errors and lost frames.
*               Used for polling state changes. Calls EthIf_CtrlModeIndication when
*               the controller mode changed.
*/
void Eth_PFE_LLD_MainFunction(void)
{
    if(NULL_PTR != ptrPlatform)
    {
        Eth_ModeType eCurrentMode;
        uint8 u8EthIfCtrlIdx;
        uint8 u8CtrlIdx;
    #if (STD_ON == ETH_43_PFE_GLOBALTIME_SUPPORT)
        uint8 u8FifoIdx;
        uint8 u8NumsFifo;
    #endif /* ETH_43_PFE_GLOBALTIME_SUPPORT */

    #ifdef PFE_CFG_RTABLE_ENABLE
        if (u32RtrTimeoutTimeMs < (PFE_RTABLE_CFG_TICK_PERIOD_SEC * 1000U - ETH_43_PFE_CFG_MAIN_FCN_PERIOD_MS))
        {
            u32RtrTimeoutTimeMs += ETH_43_PFE_CFG_MAIN_FCN_PERIOD_MS;
        }
        else
        {
            pfe_rtable_do_timeouts(ptrPlatform->rtable);
            u32RtrTimeoutTimeMs -= PFE_RTABLE_CFG_TICK_PERIOD_SEC * 1000U - ETH_43_PFE_CFG_MAIN_FCN_PERIOD_MS;
        }
    #endif /* PFE_CFG_RTABLE_ENABLE */

        for (u8CtrlIdx=0U; u8CtrlIdx<ETH_43_PFE_NUM_CONTROLLER_CFG; u8CtrlIdx++)
        {
            u8EthIfCtrlIdx = ETH_43_PFE_CFG_CTRLIDXINETHIF(u8CtrlIdx);
            eCurrentMode = Eth_PFE_LLD_CheckControllerIsActive(u8CtrlIdx);
            if (eSavedMode[u8CtrlIdx] != eCurrentMode)
            {
                eSavedMode[u8CtrlIdx] = eCurrentMode;
                EthIf_CtrlModeIndication(u8EthIfCtrlIdx, eCurrentMode);
            }

        #ifdef PFE_CFG_PFE_MASTER
        #if (STD_ON == ETH_43_PFE_DEM_EVENT_DETECT)
            if(FALSE == Eth_PFE_LLD_CheckAccessToController())
            {
                if((uint32)STD_ON == (uint32)ETH_43_PFE_CFG_DEM_E_ACCESS_ENABLED(u8CtrlIdx))
                {
                    (void)Dem_SetEventStatus   ( \
                            (Dem_EventIdType) \
                            ETH_43_PFE_CFG_DEM_E_ACCESS(u8CtrlIdx), \
                            DEM_EVENT_STATUS_PREFAILED \
                                                );
                }
            }
            else
            {
                if((uint32)STD_ON == (uint32)ETH_43_PFE_CFG_DEM_E_ACCESS_ENABLED(u8CtrlIdx))
                {
                    (void)Dem_SetEventStatus   ( \
                                        (Dem_EventIdType) \
                                        ETH_43_PFE_CFG_DEM_E_ACCESS(u8CtrlIdx), \
                                        DEM_EVENT_STATUS_PREPASSED \
                                                            );
                }
            }
        #endif /* ETH_43_PFE_DEM_EVENT_DETECT */
        #endif /*PFE_CFG_PFE_MASTER*/

        #if (STD_ON == ETH_43_PFE_DEM_EVENT_DETECT)
            CheckDemStatus(u8CtrlIdx, ETH_43_PFE_CFG_DEM_E_FRAMELOST_ENABLED(u8CtrlIdx), ETH_43_PFE_E_RX_FRAMES_LOST,    ETH_43_PFE_CFG_DEM_E_FRAMELOST(u8CtrlIdx));
            CheckDemStatus(u8CtrlIdx, ETH_43_PFE_CFG_DEM_E_CRC_ENABLED(u8CtrlIdx),       ETH_43_PFE_E_CRC,               ETH_43_PFE_CFG_DEM_E_CRC(u8CtrlIdx));
            CheckDemStatus(u8CtrlIdx, ETH_43_PFE_CFG_DEM_E_UNDERSIZE_ENABLED(u8CtrlIdx), ETH_43_PFE_E_UNDERSIZEFRAME,    ETH_43_PFE_CFG_DEM_E_UNDERSIZE(u8CtrlIdx));
            CheckDemStatus(u8CtrlIdx, ETH_43_PFE_CFG_DEM_E_OVERSIZE_ENABLED(u8CtrlIdx),  ETH_43_PFE_E_OVERSIZEFRAME,     ETH_43_PFE_CFG_DEM_E_OVERSIZE(u8CtrlIdx));
            CheckDemStatus(u8CtrlIdx, ETH_43_PFE_CFG_DEM_E_ALIGN_ENABLED(u8CtrlIdx),     ETH_43_PFE_E_ALIGNMENT,         ETH_43_PFE_CFG_DEM_E_ALIGN(u8CtrlIdx));
            CheckDemStatus(u8CtrlIdx, ETH_43_PFE_CFG_DEM_E_1COL_ENABLED(u8CtrlIdx),      ETH_43_PFE_E_SINGLECOLLISION,   ETH_43_PFE_CFG_DEM_E_1COL(u8CtrlIdx));
            CheckDemStatus(u8CtrlIdx, ETH_43_PFE_CFG_DEM_E_MCOL_ENABLED(u8CtrlIdx),      ETH_43_PFE_E_MULTIPLECOLLISION, ETH_43_PFE_CFG_DEM_E_MCOL(u8CtrlIdx));
            CheckDemStatus(u8CtrlIdx, ETH_43_PFE_CFG_DEM_E_LCOL_ENABLED(u8CtrlIdx),      ETH_43_PFE_E_LATECOLLISION,     ETH_43_PFE_CFG_DEM_E_LCOL(u8CtrlIdx));
        #endif /* ETH_43_PFE_DEM_EVENT_DETECT */
 
        #if (STD_ON == ETH_43_PFE_GLOBALTIME_SUPPORT)
            /* Only call the handler here if the interrupt mode is enabled */
            if(TRUE == ETH_43_PFE_CFG_ENABLETXINTERRUPT(u8CtrlIdx))
            {
                u8NumsFifo = Eth_43_PFE_InternalCfgPtr->pController[u8CtrlIdx]->EthCtrlEgressFifoCnt;
                for(u8FifoIdx = 0U; u8FifoIdx < u8NumsFifo; u8FifoIdx++)
                {
                    Eth_PFE_LLD_ReportTransmissionTS(u8CtrlIdx, u8FifoIdx);
                }
            }
            /* Check for lost egress timestamps */
            pfe_hif_drv_client_ptp_ts_db_tick_iteration(arPfeInterface[u8CtrlIdx].prClient);
        #endif /* ETH_43_PFE_GLOBALTIME_SUPPORT */

        #ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
        #if (FALSE == PFE_CFG_HIF_IRQ_ENABLED)
            pfe_hif_drv_tx_job((void *)arPfeInterface[u8CtrlIdx].prHifDrv);
            pfe_hif_drv_rx_job((void *)arPfeInterface[u8CtrlIdx].prHifDrv);
            pfe_idex_ihc_poll();
        #endif /* PFE_CFG_HIF_IRQ_ENABLED */
        #endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */
        }
        #ifdef PFE_CFG_PFE_MASTER
        /* Poll interrupt sources for errors and report to heath monitor */
        Eth_PFE_LLD_PollerFunction();
        #endif /* PFE_CFG_PFE_MASTER */
    }
}

#if STD_ON == ETH_43_PFE_CTRLENABLE_MII
/**
 * @brief       Write specified transceiver register through the MII (Clause 22)
 * @note        Not supported on AUX interface
 * @api
 * @param[in]   u8CtrlIdx Index of the controller withing the context of the Ethernet Driver
 * @param[in]   u8TrcvIdx Index of the transceiver on the MII
 * @param[in]   u8RegIdx Index of the transceiver register on the MII
 * @param[in]   u16RegVal Value to be written into the indexed register
 * @retval      E_OK Service accepted
 * @retval      E_NOT_OK Service denied
 */
Std_ReturnType Eth_43_PFE_LLD_WriteMii(uint8 u8CtrlIdx, \
                                            uint8 u8TrcvIdx, \
                                            uint8 u8RegIdx, \
                                            uint16 u16RegVal
                                        )
{
    Std_ReturnType RetVal = E_NOT_OK;
    pfe_emac_t *prEmac = NULL_PTR;
    uint32 u32Key = 0U;
    pfe_ct_phy_if_id_t emac_id;

    if (PFE_CTRL_TYPE_EMAC == ETH_43_PFE_CFG_CTRLTYPE(u8CtrlIdx))
    {
        emac_id = ETH_43_PFE_CFG_CTRLPHYIFID(u8CtrlIdx);
        prEmac = ptrPlatform->emac[emac_id];

#ifdef PFE_CFG_PFE_MASTER
        /* Lock the MDIO bus */
        if (EOK != pfe_emac_mdio_lock(prEmac, &u32Key))
        {
            NXP_LOG_ERROR("Lock the MDIO bus failed\n");
        }
#endif /* PFE_CFG_PFE_MASTER */
        /*  Clause 22 */
        if (EOK == pfe_emac_mdio_write22(prEmac, u8TrcvIdx, u8RegIdx, u16RegVal, u32Key))
        {
            RetVal = E_OK;
        }
#ifdef PFE_CFG_PFE_MASTER
        /* Unlock the locked MDIO bus */
        if (EOK != pfe_emac_mdio_unlock(prEmac, u32Key))
        {
            NXP_LOG_ERROR("Unlock the locked MDIO bus failed\n");
        }
#endif /* PFE_CFG_PFE_MASTER */
    }

    return RetVal;
}

/**
 * @brief       Read the specified transceiver register through the MII (Clause 22)
 * @note        Not supported on AUX interface
 * @api
 * @param[in]   u8CtrlIdx Index of the controller withing the context of the Ethernet Driver
 * @param[in]   u8TrcvIdx Index of the transceiver on the MII
 * @param[in]   u8RegIdx Index of the transceiver register on the MII
 * @param[out]  pu16RegValPtr Filled with the register content of the indexed register
 * @retval      E_OK Service accepted
 * @retval      E_NOT_OK Service denied
 */
Std_ReturnType Eth_43_PFE_LLD_ReadMii(uint8 u8CtrlIdx, \
                                            uint8 u8TrcvIdx, \
                                            uint8 u8RegIdx, \
                                            uint16 * pu16RegValPtr
                                        )
{
    Std_ReturnType RetVal = E_NOT_OK;
    pfe_emac_t *prEmac = NULL_PTR;
    uint32 u32Key = 0U;
    pfe_ct_phy_if_id_t emac_id;

    if (PFE_CTRL_TYPE_EMAC == ETH_43_PFE_CFG_CTRLTYPE(u8CtrlIdx))
    {
        emac_id = ETH_43_PFE_CFG_CTRLPHYIFID(u8CtrlIdx);
        prEmac = ptrPlatform->emac[emac_id];
#ifdef PFE_CFG_PFE_MASTER
        /* Lock the MDIO bus */
        if (EOK != pfe_emac_mdio_lock(prEmac, &u32Key))
        {
            NXP_LOG_ERROR("Lock the MDIO bus failed\n");
        }
#endif /* PFE_CFG_PFE_MASTER */
        /*  Clause 22 */
        if (EOK == pfe_emac_mdio_read22(prEmac, u8TrcvIdx, u8RegIdx, pu16RegValPtr, u32Key))
        {
            RetVal = E_OK;
        }
#ifdef PFE_CFG_PFE_MASTER
        /* Unlock the locked MDIO bus */
        if (EOK != pfe_emac_mdio_unlock(prEmac, u32Key))
        {
            NXP_LOG_ERROR("Unlock the locked MDIO bus failed\n");
        }
#endif /* PFE_CFG_PFE_MASTER */
    }

    return RetVal;
}

#if STD_ON == ETH_43_PFE_CTRL_USE_45_MDIO_API
/**
 * @brief       Write specified transceiver register through the MII (Clause 45)
 * @note        Not supported on AUX interface
 * @api
 * @param[in]   u8CtrlIdx Index of the controller withing the context of the Ethernet Driver
 * @param[in]   u8TrcvIdx Index of the transceiver (address)
 * @param[in]   u8DevIdx Index of the device within the transciever
 * @param[in]   u16RegIdx Index of the transciever register
 * @param[in]   u16RegVal Value to be written into the indexed register
 * @retval      E_OK Service accepted
 * @retval      E_NOT_OK Service denied
 */
Std_ReturnType Eth_43_PFE_LLD_WriteMii45(uint8 u8CtrlIdx, \
                                         uint8 u8TrcvIdx, \
                                         uint8 u8DevIdx, \
                                         uint16 u16RegIdx, \
                                         uint16 u16RegVal
                                        )
{
    Std_ReturnType RetVal = E_NOT_OK;
    pfe_emac_t *prEmac = NULL_PTR;
    uint32 u32Key = 0U;
    pfe_ct_phy_if_id_t emac_id;

    if (PFE_CTRL_TYPE_EMAC == ETH_43_PFE_CFG_CTRLTYPE(u8CtrlIdx))
    {
        emac_id = ETH_43_PFE_CFG_CTRLPHYIFID(u8CtrlIdx);
        prEmac = ptrPlatform->emac[emac_id];

#ifdef PFE_CFG_PFE_MASTER
        /* Lock the MDIO bus */
        if (EOK != pfe_emac_mdio_lock(prEmac, &u32Key))
        {
            NXP_LOG_ERROR("Lock the MDIO bus failed\n");
        }
#endif /* PFE_CFG_PFE_MASTER */
        /*  Clause 45 */
        if (EOK == pfe_emac_mdio_write45(prEmac, u8TrcvIdx, u8DevIdx, u16RegIdx, u16RegVal, u32Key))
        {
            RetVal = E_OK;
        }
#ifdef PFE_CFG_PFE_MASTER
        /* Unlock the locked MDIO bus */
        if (EOK != pfe_emac_mdio_unlock(prEmac, u32Key))
        {
            NXP_LOG_ERROR("Unlock the locked MDIO bus failed\n");
        }
#endif /* PFE_CFG_PFE_MASTER */
    }

    return RetVal;
}

/**
 * @brief       Read the specified transceiver register through the MII (Clause 45)
 * @note        Not supported on AUX interface
 * @api
 * @param[in]   u8CtrlIdx Index of the controller withing the context of the Ethernet Driver
 * @param[in]   u8TrcvIdx Index of the transceiver (address)
 * @param[in]   u8DevIdx Index of the device within the transciever
 * @param[in]   u16RegIdx Index of the transciever register
 * @param[out]  pu16RegValPtr Filled with the register content of the indexed register
 * @retval      E_OK Service accepted
 * @retval      E_NOT_OK Service denied
 */
Std_ReturnType Eth_43_PFE_LLD_ReadMii45(uint8 u8CtrlIdx, \
                                            uint8 u8TrcvIdx, \
                                            uint8 u8DevIdx, \
                                            uint16 u16RegIdx, \
                                            uint16 * pu16RegValPtr
                                        )
{
    Std_ReturnType RetVal = E_NOT_OK;
    pfe_emac_t *prEmac = NULL_PTR;
    uint32 u32Key = 0U;
    pfe_ct_phy_if_id_t emac_id;

    if (PFE_CTRL_TYPE_EMAC == ETH_43_PFE_CFG_CTRLTYPE(u8CtrlIdx))
    {
        emac_id = ETH_43_PFE_CFG_CTRLPHYIFID(u8CtrlIdx);
        prEmac = ptrPlatform->emac[emac_id];
#ifdef PFE_CFG_PFE_MASTER
        /* Lock the MDIO bus */
        if (EOK != pfe_emac_mdio_lock(prEmac, &u32Key))
        {
            NXP_LOG_ERROR("Lock the MDIO bus failed\n");
        }
#endif /* PFE_CFG_PFE_MASTER */
        /*  Clause 45 */
        if (EOK == pfe_emac_mdio_read45(prEmac, u8TrcvIdx, u8DevIdx, u16RegIdx, pu16RegValPtr, u32Key))
        {
            RetVal = E_OK;
        }
#ifdef PFE_CFG_PFE_MASTER
        /* Unlock the locked MDIO bus */
        if (EOK != pfe_emac_mdio_unlock(prEmac, u32Key))
        {
            NXP_LOG_ERROR("Unlock the locked MDIO bus failed\n");
        }
#endif /* PFE_CFG_PFE_MASTER */
    }

    return RetVal;
}
#endif /* STD_ON == ETH_43_PFE_CTRL_USE_45_MDIO_API*/
#endif /* STD_OFF == ETH_43_PFE_CTRLENABLE_MII */

#if STD_ON == ETH_43_PFE_GLOBALTIME_SUPPORT
/* Set Global Time  *******************************************************************************/
Std_ReturnType Eth_43_PFE_LLD_SetGlobalTime(uint8 u8CtrlIdx, const Eth_TimeStampType *pTimeStampPtr)
{
    Std_ReturnType RetVal = E_NOT_OK;
    pfe_emac_t *prEmac = NULL_PTR;
    pfe_ct_phy_if_id_t emac_id;

    if (PFE_CTRL_TYPE_EMAC == ETH_43_PFE_CFG_CTRLTYPE(u8CtrlIdx))
    {
        emac_id = ETH_43_PFE_CFG_CTRLPHYIFID(u8CtrlIdx);
        prEmac = ptrPlatform->emac[emac_id];
        if (EOK == pfe_emac_set_ts_time(prEmac, pTimeStampPtr->seconds, pTimeStampPtr->nanoseconds, pTimeStampPtr->secondsHi))
        {
#ifdef PFE_CFG_EMAC0_PPS0_ENABLE
            if(PFE_PHY_IF_ID_EMAC0 == emac_id)
            {
                pfe_emac_pps0_resync(prEmac);
            }
#endif
            RetVal = E_OK;
        }
    }

    return RetVal;
}

/* Get Current Time  *****************************************************************************/
void Eth_43_PFE_LLD_GetCurrentTime  (   uint8 u8CtrlIdx, \
                                        Eth_TimeStampQualType *timeQualPtr, \
                                        Eth_TimeStampType *timeStampPtr \
                                    )
{
    pfe_emac_t *prEmac = NULL_PTR;
    pfe_ct_phy_if_id_t emac_id;

    if (PFE_CTRL_TYPE_EMAC == ETH_43_PFE_CFG_CTRLTYPE(u8CtrlIdx))
    {
        emac_id = ETH_43_PFE_CFG_CTRLPHYIFID(u8CtrlIdx);
        prEmac = ptrPlatform->emac[emac_id];

        if (EOK == pfe_emac_get_ts_time (   prEmac, \
                                            &(timeStampPtr->seconds), \
                                            &(timeStampPtr->nanoseconds), \
                                            &(timeStampPtr->secondsHi) \
                                        ) \
           )
        {
            *timeQualPtr = ETH_VALID;
        }
    }
}


/* helper function to adjust frequency ratio  *******************************************************************/
static Std_ReturnType EmacTsAdjustRatio(uint8 u8CtrlIdx, pfe_emac_t *prEmac, const Eth_RateRatioType *pRateRatioPtr)
{
    Std_ReturnType RetVal = E_OK;

    const uint64 u64RemoteTime = ((uint64)pRateRatioPtr->OriginTimeStampDelta.diff.seconds * 1000000000ULL)
                    + pRateRatioPtr->OriginTimeStampDelta.diff.nanoseconds;

    const uint64 u64LocalTime  = ((uint64)pRateRatioPtr->IngressTimeStampDelta.diff.seconds * 1000000000ULL)
                    + pRateRatioPtr->IngressTimeStampDelta.diff.nanoseconds;

    if ((u64RemoteTime != 0ULL) && (u64LocalTime != 0ULL))
    {
        bool_t bIsPositive;
        uint64 u64Diff;
        uint64 u64ChngFreqPPB; /* Frequency change in part per billion */
        if (u64RemoteTime > u64LocalTime)
        {
            bIsPositive = TRUE;
            u64Diff = u64RemoteTime - u64LocalTime;
            u64ChngFreqPPB = u64Diff * 1000000000ULL / u64LocalTime;
        }
        else
        {
            bIsPositive = FALSE;
            u64Diff = u64LocalTime - u64RemoteTime;
            u64ChngFreqPPB = u64Diff * 1000000000ULL / u64RemoteTime;
        }

        if ((u64Diff > 18446744073ULL) || (u64ChngFreqPPB > 0xFFFFFFFFU))
        {
            NXP_LOG_ERROR("Global time rate correction is too big %hhu\n", u8CtrlIdx);
            RetVal = E_NOT_OK;
        }
        else 
        {
            if(EOK != pfe_emac_set_ts_freq_adjustment(prEmac, (uint32)u64ChngFreqPPB, bIsPositive))
            {
                RetVal = E_NOT_OK;
            }
        }

    }
    return RetVal;
}

/**
* @brief        Allows the Time Slave to adjust the local ETH Reference clock in HW.
* @details      Only use this function when this controller used as Time Slave.
*
* @param[in]    u8CtrlIdx         Index of the controller which time shall be corrected
* @param[in]    pTimeOffsetPtr Offset between time stamp grandmaster and time stamp by local
*               clock.
* @param[in]    pRateRatioPtr  Time elements to calculate and to modify the ratio of the frequency
*               of the grandmaster in relation to the frequency of the Local Clock
*/
Std_ReturnType Eth_43_PFE_LLD_SetCorrectionTime (   uint8 u8CtrlIdx, \
                                                    const Eth_TimeIntDiffType *pTimeOffsetPtr, \
                                                    const Eth_RateRatioType *pRateRatioPtr \
                                                )
{
    Std_ReturnType RetVal = E_OK;
    pfe_emac_t *prEmac = NULL_PTR;
    pfe_ct_phy_if_id_t emac_id;

    if (PFE_CTRL_TYPE_EMAC == ETH_43_PFE_CFG_CTRLTYPE(u8CtrlIdx))
    {
        emac_id = ETH_43_PFE_CFG_CTRLPHYIFID(u8CtrlIdx);
        prEmac = ptrPlatform->emac[emac_id];

        if ((pTimeOffsetPtr->diff.seconds != 0U) || (pTimeOffsetPtr->diff.nanoseconds != 0U))
        {
            if (EOK != pfe_emac_adjust_ts_time(prEmac, pTimeOffsetPtr->diff.seconds, pTimeOffsetPtr->diff.nanoseconds, (pTimeOffsetPtr->sign != FALSE)))
            {
                RetVal = E_NOT_OK;
            }
            else 
            {
                /* system time adjusted */
#ifdef PFE_CFG_EMAC0_PPS0_ENABLE
                if(PFE_PHY_IF_ID_EMAC0 == emac_id) {
                    pfe_emac_pps0_resync(prEmac);
                }
#endif
            }
        }

        if ((Std_ReturnType)E_OK == RetVal)
        {
            RetVal = EmacTsAdjustRatio(u8CtrlIdx, prEmac, pRateRatioPtr);
        }
    }
    else
    {
        RetVal = E_NOT_OK;
    }

    return RetVal;
}


/* Enable Egress Timestamp *****************************************************************/
void Eth_43_PFE_LLD_EnableEgressTimeStamp(uint8 u8CtrlIdx, Eth_BufIdxType BufIdx)
{
    trTxMeta *prTxMeta = Eth_PFE_LLD_GetTxBufMeta(u8CtrlIdx, BufIdx);

    prTxMeta->bDoTS = TRUE;
}

/*  Get the timestamp from pfe_hif_drv_client
    DataPtr points to Ethernet frame payload (buffer + 14 for header) */
errno_t Eth_43_PFE_LLD_GetRxTimeStamp(uint8 u8CtrlIdx, \
                                    const Eth_DataType *DataPtr, \
                                    Eth_TimeStampQualType *timeQualPtr, \
                                    Eth_TimeStampType *timeStampPtr \
                                )
{
    uint8 *pu8Packet = (uint8 *)DataPtr;
    oal_util_ptp_header_t *pu8PtpHead = NULL_PTR;
    errno_t RetVal = ENOENT;

    if (NULL_PTR != arPfeInterface[u8CtrlIdx].prClient)
    {
        /* Find PTP header */
        if(EOK != oal_util_parse_ptp(pu8Packet - 14U, 106U, &pu8PtpHead))
        {
            pu8PtpHead = NULL_PTR;
        }
        if(NULL_PTR == pu8PtpHead)
        {
            NXP_LOG_ERROR("Unrecognized PTP frame\n");
            *timeQualPtr = ETH_INVALID; /* General failure */
        }
        else
        {
            uint8 PtpMsgType;
            uint16 PtpSrcPortId;
            uint16 PtpSeqId;
            /* Parse PTP values */
            PtpMsgType = pu8PtpHead->byte1.messageType;
            PtpSrcPortId = oal_ntohs(pu8PtpHead->sourcePortID);
            PtpSeqId = oal_ntohs(pu8PtpHead->sequenceID);
            /* Get timestamp */
            RetVal = pfe_hif_drv_client_get_ts
            (
                arPfeInterface[u8CtrlIdx].prClient, TRUE,
                PtpMsgType, PtpSrcPortId, PtpSeqId,
                &(timeStampPtr->seconds), &(timeStampPtr->nanoseconds)
            );

            if (EOK == RetVal)
            {
                timeStampPtr->secondsHi = 0U;
                *timeQualPtr = ETH_VALID;
            }
            else
            {
                *timeQualPtr = ETH_INVALID; /* General failure */
            }
        }
    }
    return RetVal;
}

/* Callback to get Tx timestamp from function EthIf_TxConfirmation.
   The timestamp was already obtained from pfe_hif_drv_client and is temporarily available
   in arPfeInterface[u8CtrlIdx].TimeStamp */
void Eth_43_PFE_LLD_GetTxTimeStamp( uint8 u8CtrlIdx, \
                                    Eth_BufIdxType BufIdx, \
                                    Eth_TimeStampQualType *timeQualPtr, \
                                    Eth_TimeStampType *timeStampPtr \
                                  )
{
    *timeQualPtr = aarTxBuf[u8CtrlIdx][BufIdx].TimeQual;
    *timeStampPtr = aarTxBuf[u8CtrlIdx][BufIdx].TimeStamp;
}
#endif /* ETH_43_PFE_GLOBALTIME_SUPPORT */


/**
 * @brief       Can be used to export the platform instance, which might be needed by external HIF driver
 */
void * Eth_PFE_LLD_GetPlatform(void)
{
    return ptrPlatform;
}

#if STD_ON == ETH_43_GET_CLASS_STATISTIC_API
/**
 * @brief       Get class statistics from firmware
 * @api
 * @param[out]  stat Statistic structure
 * @retval      E_OK if possible to get statistics, otherwise E_NOT_OK
 */
Std_ReturnType Eth_43_PFE_LLD_GetClassStats(pfe_ct_classify_stats_t * stat)
{
    Std_ReturnType retVal = E_NOT_OK;

    if (NULL_PTR != ptrPlatform)
    {
        if(EOK == pfe_class_get_stats(ptrPlatform->classifier, stat))
        {
            retVal = E_OK;
        }
    }
    return retVal;
}
#endif /* ETH_43_GET_CLASS_STATISTIC_API */

#if STD_ON == ETH_43_GET_PFE_STATISTIC_API
/**
 * @brief       Get bmu statistics from firmware
 * @api
 * @param[in]   u8BmuIndex Bmu instance
 * @param[out]  stat Statistic structure
 * @retval      E_OK if possible to get statistics, otherwise E_NOT_OK
 */
Std_ReturnType Eth_43_PFE_LLD_GetBmuStats(uint8 u8BmuIndex, Eth_43_PFE_BmuStatsType * stat)
{
    Std_ReturnType retVal = E_NOT_OK;
    uint8 i;
    uint32 reg_value;
    pfe_bmu_stats_special_t special_stats = {0};

    if (NULL_PTR != ptrPlatform)
    {
        if (unlikely(PFE_BMU_INSTANCES <= u8BmuIndex))
        {
            NXP_LOG_ERROR("BMU index out of range\n");
        }
        else
        {
            stat->bmu_debug_bus = pfe_bmu_get_stat_value(ptrPlatform->bmu[u8BmuIndex], BMU_DEBUG_BUS);
            stat->buff_base = pfe_bmu_get_stat_value(ptrPlatform->bmu[u8BmuIndex], BMU_UCAST_BASEADDR);
            stat->buff_remain = pfe_bmu_get_stat_value(ptrPlatform->bmu[u8BmuIndex], BMU_REM_BUF_CNT);
            stat->buff_allocated = pfe_bmu_get_stat_value(ptrPlatform->bmu[u8BmuIndex], BMU_CURR_BUF_CNT);
            stat->low_watermark = pfe_bmu_get_stat_value(ptrPlatform->bmu[u8BmuIndex], BMU_LOW_WATERMARK);
            stat->high_watermark = pfe_bmu_get_stat_value(ptrPlatform->bmu[u8BmuIndex], BMU_HIGH_WATERMARK);
            stat->irq_threshold = pfe_bmu_get_stat_value(ptrPlatform->bmu[u8BmuIndex], BMU_THRES) & 0xFFFFU;
            stat->free_error_add = pfe_bmu_get_stat_value(ptrPlatform->bmu[u8BmuIndex], BMU_FREE_ERROR_ADDR);
            stat->irq_source = pfe_bmu_get_stat_value(ptrPlatform->bmu[u8BmuIndex], BMU_INT_SRC);
            stat->irq_enable = pfe_bmu_get_stat_value(ptrPlatform->bmu[u8BmuIndex], BMU_INT_ENABLE);

            for(i = 0; i < PFE_BMU_NUMBER_MAX_MAS_BUFF_CNT; i++)
            {
                reg_value =  pfe_bmu_get_stat_value(ptrPlatform->bmu[u8BmuIndex], (4UL*i) + BMU_MAS0_BUF_CNT);
                stat->master_buf_count[i] = reg_value;
            }

            if(EOK == pfe_bmu_get_special_stats(ptrPlatform->bmu[u8BmuIndex], &special_stats))
            {
                stat->revision = special_stats.revision;
                stat->version = special_stats.version;
                stat->id = special_stats.id;
                stat->free_error_cnt = special_stats.free_error_cnt;
                stat->active_buff = special_stats.active_buff;
                stat->buff_size = special_stats.buff_size;
            }
            else
            {
                stat->revision = PFE_INVALID_STAT;
                stat->version = PFE_INVALID_STAT;
                stat->id = PFE_INVALID_STAT;
                stat->free_error_cnt = PFE_INVALID_STAT;
                stat->active_buff = PFE_INVALID_STAT;
                stat->buff_size = PFE_INVALID_STAT;
            }
            retVal = E_OK;
        }
    }
    return retVal;
}

/**
 * @brief       Get Gpi statistics from firmware
 * @api
 * @param[out]  stat Statistic structure
 * @param[in]   u8GpiIndex Instance index GPI
 * @retval      E_OK if possible to get statistics, otherwise E_NOT_OK
 */
Std_ReturnType Eth_43_PFE_LLD_GetGpiStats(uint8 u8GpiIndex , Eth_43_PFE_GpiStatsType * stat)
{
    Std_ReturnType retVal = E_NOT_OK;
    pfe_gpi_special_stats_t special_stats = {0};

    if (NULL_PTR != ptrPlatform)
    {
        if (unlikely(PFE_GPI_INSTANCES <= u8GpiIndex))
        {
            NXP_LOG_ERROR("Gpi index out of range\n");
        }
        else
        {
            stat->fifo_debug = pfe_gpi_get_stat_value(ptrPlatform->gpi[u8GpiIndex],GPI_FIFO_DEBUG);
            stat->tx_debug_reg1 =  pfe_gpi_get_stat_value(ptrPlatform->gpi[u8GpiIndex],GPI_TX_DBUG_REG1);
            stat->tx_debug_reg2 =  pfe_gpi_get_stat_value(ptrPlatform->gpi[u8GpiIndex],GPI_TX_DBUG_REG2);
            stat->tx_debug_reg3 =  pfe_gpi_get_stat_value(ptrPlatform->gpi[u8GpiIndex],GPI_TX_DBUG_REG3);
            stat->tx_debug_reg4 =  pfe_gpi_get_stat_value(ptrPlatform->gpi[u8GpiIndex],GPI_TX_DBUG_REG4);
            stat->tx_debug_reg5 =  pfe_gpi_get_stat_value(ptrPlatform->gpi[u8GpiIndex],GPI_TX_DBUG_REG5);
            stat->tx_debug_reg6 =  pfe_gpi_get_stat_value(ptrPlatform->gpi[u8GpiIndex],GPI_TX_DBUG_REG6);
            stat->rx_debug_reg1 =  pfe_gpi_get_stat_value(ptrPlatform->gpi[u8GpiIndex],GPI_RX_DBUG_REG1);
            stat->rx_debug_reg2 =  pfe_gpi_get_stat_value(ptrPlatform->gpi[u8GpiIndex],GPI_RX_DBUG_REG2);

            stat->fifo_status =  pfe_gpi_get_stat_value(ptrPlatform->gpi[u8GpiIndex],GPI_FIFO_STATUS);

            stat->iqos_queue_status =  pfe_gpi_get_stat_value(ptrPlatform->gpi[u8GpiIndex],CSR_IGQOS_QUEUE_STATUS);
            stat->iqos_class_drop_cnt =  pfe_gpi_get_stat_value(ptrPlatform->gpi[u8GpiIndex],CSR_IGQOS_STAT_CLASS_DROP_CNT);
            stat->iqos_lmem_drop_cnt =  pfe_gpi_get_stat_value(ptrPlatform->gpi[u8GpiIndex],CSR_IGQOS_STAT_LMEM_QUEUE_DROP_CNT);
            stat->iqos_dmem_drop_cnt =  pfe_gpi_get_stat_value(ptrPlatform->gpi[u8GpiIndex],CSR_IGQOS_STAT_DMEM_QUEUE_DROP_CNT);
            stat->iqos_rxf_drop_cnt =  pfe_gpi_get_stat_value(ptrPlatform->gpi[u8GpiIndex],CSR_IGQOS_STAT_RXF_QUEUE_DROP_CNT);
            if(EOK != pfe_gpi_shp_get_drop_cnt(ptrPlatform->gpi[u8GpiIndex], 0, &stat->iqos_shp0_drop_cnt))
            {
                stat->iqos_shp0_drop_cnt = PFE_INVALID_STAT;
            }
            if(EOK != pfe_gpi_shp_get_drop_cnt(ptrPlatform->gpi[u8GpiIndex], 1, &stat->iqos_shp1_drop_cnt))
            {
                stat->iqos_shp1_drop_cnt = PFE_INVALID_STAT;
            } 
            stat->iqos_manage_pkts =  pfe_gpi_get_stat_value(ptrPlatform->gpi[u8GpiIndex],CSR_IGQOS_STAT_MANAGED_PACKET_CNT);
            stat->iqos_unmanage_pkts =  pfe_gpi_get_stat_value(ptrPlatform->gpi[u8GpiIndex],CSR_IGQOS_STAT_UNMANAGED_PACKET_CNT);
            stat->iqos_reserved_pkts =  pfe_gpi_get_stat_value(ptrPlatform->gpi[u8GpiIndex],CSR_IGQOS_STAT_RESERVED_PACKET_CNT);
            stat->tx_underrun =  pfe_gpi_get_stat_value(ptrPlatform->gpi[u8GpiIndex], GPI_FIFO_STATUS);

            stat->aseq_length =  pfe_gpi_get_stat_value(ptrPlatform->gpi[u8GpiIndex], GPI_DTX_ASEQ);
            stat->enable_reg_1588 =  pfe_gpi_get_stat_value(ptrPlatform->gpi[u8GpiIndex], GPI_EMAC_1588_TIMESTAMP_EN);
            stat->overrun_drop_cnt =  pfe_gpi_get_stat_value(ptrPlatform->gpi[u8GpiIndex], GPI_OVERRUN_DROPCNT);

            if(EOK == pfe_gpi_get_special_stats(ptrPlatform->gpi[u8GpiIndex], &special_stats))
            {
                stat->revision = special_stats.revision;
                stat->version = special_stats.version;
                stat->id = special_stats.id;
                stat->tx_fifo_packets = special_stats.tx_fifo_packets;
                stat->rx_fifo_packets = special_stats.rx_fifo_packets;
                stat->tx_fifo_level = special_stats.tx_fifo_level;
                stat->rx_fifo_level = special_stats.rx_fifo_level;
            }
            else
            {
                stat->revision = PFE_INVALID_STAT;
                stat->version = PFE_INVALID_STAT;
                stat->id = PFE_INVALID_STAT;
                stat->tx_fifo_packets = PFE_INVALID_STAT;
                stat->rx_fifo_packets = PFE_INVALID_STAT;
                stat->tx_fifo_level = PFE_INVALID_STAT;
                stat->rx_fifo_level = PFE_INVALID_STAT;
            }
            retVal = E_OK;
        }
    }
    return retVal;
}

/**
 * @brief       Get wdt statistics from firmware
 * @api
 * @param[out]  stat Statistic structure
 * @retval      E_OK if possible to get statistics, otherwise E_NOT_OK
 */
Std_ReturnType Eth_43_PFE_LLD_GetWdtStats(Eth_43_PFE_WdtStatsType * stat)
{
    Std_ReturnType retVal = E_NOT_OK;

    if (NULL_PTR != ptrPlatform)
    {
        stat->wdp_version = pfe_wdt_get_stat_value(ptrPlatform->wdt, WSP_VERSION);
        stat->wdt_int_en = pfe_wdt_get_stat_value(ptrPlatform->wdt, WDT_INT_EN);
        stat->class_wdt_int_en = pfe_wdt_get_stat_value(ptrPlatform->wdt, CLASS_WDT_INT_EN);
        stat->upe_wdt_int_en = pfe_wdt_get_stat_value(ptrPlatform->wdt, UPE_WDT_INT_EN);
        stat->hgpi_wdt_int_en = pfe_wdt_get_stat_value(ptrPlatform->wdt, HGPI_WDT_INT_EN);
        stat->hif_wdt_int_en = pfe_wdt_get_stat_value(ptrPlatform->wdt, HIF_WDT_INT_EN);
        stat->tlite_wdt_int_en = pfe_wdt_get_stat_value(ptrPlatform->wdt, TLITE_WDT_INT_EN);
        stat->hncpy_wdt_int_en = pfe_wdt_get_stat_value(ptrPlatform->wdt, HNCPY_WDT_INT_EN);
        stat->bmu1_wdt_int_en = pfe_wdt_get_stat_value(ptrPlatform->wdt, BMU1_WDT_INT_EN);
        stat->bmu2_wdt_int_en = pfe_wdt_get_stat_value(ptrPlatform->wdt, BMU2_WDT_INT_EN);
        stat->emac0_wdt_int_en = pfe_wdt_get_stat_value(ptrPlatform->wdt, EMAC0_WDT_INT_EN);
        stat->emac1_wdt_int_en = pfe_wdt_get_stat_value(ptrPlatform->wdt, EMAC1_WDT_INT_EN);
        stat->emac2_wdt_int_en = pfe_wdt_get_stat_value(ptrPlatform->wdt, EMAC2_WDT_INT_EN);
        stat->ext_gpt_wdt_int_en = pfe_wdt_get_stat_value(ptrPlatform->wdt, EXT_GPT_WDT_INT_EN);
        stat->lmem_wdt_int_en = pfe_wdt_get_stat_value(ptrPlatform->wdt, LMEM_WDT_INT_EN);
        stat->wdt_int_src = pfe_wdt_get_stat_value(ptrPlatform->wdt, WDT_INT_SRC);
        stat->wdt_timer_val_upe = pfe_wdt_get_stat_value(ptrPlatform->wdt, WDT_TIMER_VAL_UPE);
        stat->wdt_timer_val_bmu = pfe_wdt_get_stat_value(ptrPlatform->wdt, WDT_TIMER_VAL_BMU);
        stat->wdt_timer_val_hif = pfe_wdt_get_stat_value(ptrPlatform->wdt, WDT_TIMER_VAL_HIF);
        stat->wdt_timer_val_tlite = pfe_wdt_get_stat_value(ptrPlatform->wdt, WDT_TIMER_VAL_TLITE);
        stat->wdt_timer_val_hif_ncpy = pfe_wdt_get_stat_value(ptrPlatform->wdt, WDT_TIMER_VAL_HIF_NCPY);
        stat->wdt_timer_val_class = pfe_wdt_get_stat_value(ptrPlatform->wdt, WDT_TIMER_VAL_CLASS);
        stat->wdt_timer_val_gpi = pfe_wdt_get_stat_value(ptrPlatform->wdt, WDT_TIMER_VAL_GPI);
        stat->wdt_timer_val_gpt = pfe_wdt_get_stat_value(ptrPlatform->wdt, WDT_TIMER_VAL_GPT);
        stat->wdt_timer_val_lmem = pfe_wdt_get_stat_value(ptrPlatform->wdt, WDT_TIMER_VAL_LMEM);
        stat->wdt_timer_val_route_lmem = pfe_wdt_get_stat_value(ptrPlatform->wdt, WDT_TIMER_VAL_ROUTE_LMEM);
        stat->wsp_dbug_bus1_g3 = pfe_wdt_get_stat_value(ptrPlatform->wdt, WSP_DBUG_BUS1_G3);
        stat->wsp_dbug_bus1 = pfe_wdt_get_stat_value(ptrPlatform->wdt, WSP_DBUG_BUS1);
        retVal = E_OK;
    }
    return retVal;
}

/**
 * @brief       Get l2 bridge statistics from firmware
 * @api
 * @param[out]  stat Statistic structure
 * @param[in]   index_entry index of required entry
 * @retval      E_OK if possible to get statistics, otherwise E_NOT_OK
 */
Std_ReturnType Eth_43_PFE_LLD_GetL2BridgeStats(Eth_43_PFE_L2BridgeStatsType * stat, uint32 index_entry)
{
    Std_ReturnType retVal = E_NOT_OK;
#ifdef PFE_CFG_L2BRIDGE_ENABLE
    uint32 number_entry;

    if (NULL_PTR != ptrPlatform)
    {
        number_entry = pfe_l2br_get_number_entries(ptrPlatform->l2_bridge);
        if (unlikely(index_entry >= number_entry))
        {
            NXP_LOG_ERROR("Entry index out of range\n");
        }
        else
        {
            if(EOK == pfe_l2br_get_stats(ptrPlatform->l2_bridge, stat, index_entry))
            {
                retVal = E_OK;
            }
        }
    }
#else
    (void)stat;
    (void)index_entry;
#endif /* PFE_CFG_L2BRIDGE_ENABLE */

    return retVal;
}

/**
 * @brief       Get l2 bridge domain statistics from firmware
 * @api
 * @param[out]  stat Statistic structure
 * @param[in]   index_vlan index of VLAN
 * @retval      E_OK if possible to get statistics, otherwise E_NOT_OK
 */
Std_ReturnType Eth_43_PFE_LLD_GetL2BridgeDomainStats(pfe_ct_vlan_stats_t* stat, uint8 index_vlan)
{
    Std_ReturnType retVal = E_NOT_OK;

#ifdef PFE_CFG_L2BRIDGE_ENABLE
    if (NULL_PTR != ptrPlatform)
    {
        if(EOK == pfe_l2br_get_domain_stats(ptrPlatform->l2_bridge, stat, index_vlan))
        {
            retVal = E_OK;
        }
    }
#else
    (void)stat;
    (void)index_vlan;
#endif /* PFE_CFG_L2BRIDGE_ENABLE */
    
    return retVal;
}

/**
 * @brief       Get rtable statistics from firmware
 * @api
 * @param[out]  stat Statistic structure
 * @param[in]   conntrack_index index of conntrack stat
 * @retval      EOK if possible to get statistics, otherwise E_NOT_OK
 */
Std_ReturnType Eth_43_PFE_LLD_GetRtableStats(pfe_ct_conntrack_stats_t * stat, uint8 conntrack_index)
{
    Std_ReturnType retVal = E_NOT_OK;

#ifdef PFE_CFG_RTABLE_ENABLE
    if (NULL_PTR != ptrPlatform)
    {
        if (EOK == pfe_rtable_get_stats(ptrPlatform->rtable, stat, conntrack_index))
        {
            retVal = E_OK;
        }
    }
#else
    (void)stat;
    (void)conntrack_index;
#endif
        
    return retVal;
}

/**
 * @brief       Get tmu statistics from firmware
 * @api
 * @param[out]  stat Statistic structure
 * @retval      EOK if possible to get statistics, otherwise E_NOT_OK
 */
Std_ReturnType Eth_43_PFE_LLD_GetTmuStats(Eth_43_PFE_TmuStatsType * stat)
{
    uint32 i, j;
    Std_ReturnType retVal = E_NOT_OK;
    pfe_tmu_stats_special_t special_stats = {0};
    pfe_tmu_queue_stats queue_stats = {0};

    if (NULL_PTR != ptrPlatform)
    {
        stat->tmu_phy_inq_pktptr = pfe_tmu_get_stat_value(ptrPlatform->tmu, TMU_PHY_INQ_PKTPTR);
        stat->tmu_phy_inq_pktinfo = pfe_tmu_get_stat_value(ptrPlatform->tmu, TMU_PHY_INQ_PKTINFO);
        stat->tmu_phy_inq_stat = pfe_tmu_get_stat_value(ptrPlatform->tmu, TMU_PHY_INQ_STAT);
        stat->tmu_dbg_bus_stop = pfe_tmu_get_stat_value(ptrPlatform->tmu, TMU_DBG_BUS_TOP);
        stat->tmu_dbg_bus_pp0 = pfe_tmu_get_stat_value(ptrPlatform->tmu, TMU_DBG_BUS_PP0);
        stat->tmu_dbg_bus_pp1 = pfe_tmu_get_stat_value(ptrPlatform->tmu, TMU_DBG_BUS_PP1);
        stat->tmu_dbg_bus_pp2 = pfe_tmu_get_stat_value(ptrPlatform->tmu, TMU_DBG_BUS_PP2);
        stat->tmu_dbg_bus_pp3 = pfe_tmu_get_stat_value(ptrPlatform->tmu, TMU_DBG_BUS_PP3);
        stat->tmu_dbg_bus_pp4 = pfe_tmu_get_stat_value(ptrPlatform->tmu, TMU_DBG_BUS_PP4);
        stat->tmu_dbg_bus_pp5 = pfe_tmu_get_stat_value(ptrPlatform->tmu, TMU_DBG_BUS_PP5);
        stat->ctrl = pfe_tmu_get_stat_value(ptrPlatform->tmu, TMU_CTRL);

        if(EOK == pfe_tmu_get_special_stats(ptrPlatform->tmu, &special_stats))
        {
            stat->version = special_stats.version;
            stat->id = special_stats.id;
            stat->revision = special_stats.version;
        }
        else
        {
            stat->version = PFE_INVALID_STAT;
            stat->id = PFE_INVALID_STAT;
            stat->revision = PFE_INVALID_STAT;
        }
        
        for(i = 0; i < TLITE_PHYS_CNT; i++)
        {
            for(j = 0; j < TLITE_PHY_QUEUES_CNT; j++)
            {
                if (EOK == pfe_tmu_get_queue_stats(ptrPlatform->tmu, i, j, &queue_stats))
                {
                    stat->aQueue[i][j] = queue_stats;
                }
                else
                {
                    stat->aQueue[i][j].mode = PFE_INVALID_STAT;
                    stat->aQueue[i][j].min = PFE_INVALID_STAT;
                    stat->aQueue[i][j].max = PFE_INVALID_STAT;
                    stat->aQueue[i][j].level = PFE_INVALID_STAT;
                    stat->aQueue[i][j].drops = PFE_INVALID_STAT;
                    stat->aQueue[i][j].tx = PFE_INVALID_STAT;

                    (void)autolibc_memset(stat->aQueue[i][j].zprob, (int32_t)(PFE_INVALID_STAT & 0xFFU), sizeof(stat->aQueue[i][j].zprob)/sizeof(stat->aQueue[i][j].zprob[0]));
                }
            }
        }
        retVal = E_OK;
    }
    return retVal;
}
#endif /* ETH_43_GET_PFE_STATISTIC_API */

#if STD_ON == ETH_43_GET_COUNTER_API
/**
* @brief         Reads a list with drop counter values of the corresponding controller.
* @note          Not supported on AUX interface (returns structure filled by invalid values).
* @param[in]     u8CtrlIdx Index of controller within the context of the Ethernet Driver.
* @param[out]    CounterPtr Counter values according to IETF RFC 1757, RFC 1643 and RFC 2233.
* @details       Reads a list with drop counter values of the corresponding controller.
*                The meaning of these values is described at Eth_CounterType.
*/
Std_ReturnType Eth_PFE_LLD_GetCounterValues(uint8 u8CtrlIdx, \
                                            Eth_CounterType * CounterPtr
                                        )
{
    pfe_emac_t *prEmac = NULL_PTR;

    prEmac = Eth_PFE_LLD_GetEmacInstanceByControllerId(u8CtrlIdx);
    /* Only EMAC interfaces has statistics, return invalid values for other interfaces */
    if (NULL_PTR == prEmac)
    {
        CounterPtr->DropPktBufOverrun = 0xFFFFFFFFU;
        CounterPtr->DropPktCrc        = 0xFFFFFFFFU;
        CounterPtr->UndersizePkt      = 0xFFFFFFFFU;
        CounterPtr->OversizePkt       = 0xFFFFFFFFU;
        CounterPtr->AlgnmtErr         = 0xFFFFFFFFU;
        CounterPtr->SqeTestErr        = 0xFFFFFFFFU;
        CounterPtr->DiscInbdPkt       = 0xFFFFFFFFU;
        CounterPtr->ErrInbdPkt        = 0xFFFFFFFFU;
        CounterPtr->DiscOtbdPkt       = 0xFFFFFFFFU;
        CounterPtr->ErrOtbdPkt        = 0xFFFFFFFFU;
        CounterPtr->SnglCollPkt       = 0xFFFFFFFFU;
        CounterPtr->MultCollPkt       = 0xFFFFFFFFU;
        CounterPtr->DfrdPkt           = 0xFFFFFFFFU;
        CounterPtr->LatCollPkt        = 0xFFFFFFFFU;
        CounterPtr->HwDepCtr0         = 0xFFFFFFFFU;
        CounterPtr->HwDepCtr1         = 0xFFFFFFFFU;
        CounterPtr->HwDepCtr2         = 0xFFFFFFFFU;
        CounterPtr->HwDepCtr3         = 0xFFFFFFFFU; 
    }
    else
    {
        /* Maximal possible value shall denote an invalid value (e.g. counter not available) */
        const uint32_t tx_count_good_bad = pfe_emac_get_stat_value(prEmac, TX_PACKET_COUNT_GOOD_BAD);
        const uint32_t tx_count_good     = pfe_emac_get_stat_value(prEmac, TX_PACKET_COUNT_GOOD);
        PfeDevAssert(tx_count_good_bad >= tx_count_good);
        CounterPtr->ErrOtbdPkt        = tx_count_good_bad - tx_count_good;

        CounterPtr->DropPktBufOverrun = pfe_emac_get_stat_value(prEmac, RX_FIFO_OVERFLOW_PACKETS);
        CounterPtr->DropPktCrc        = pfe_emac_get_stat_value(prEmac, RX_CRC_ERROR_PACKETS);
        CounterPtr->UndersizePkt      = pfe_emac_get_stat_value(prEmac, RX_UNDERSIZE_PACKETS_GOOD);
        CounterPtr->OversizePkt       = pfe_emac_get_stat_value(prEmac, RX_OVERSIZE_PACKETS_GOOD);
        CounterPtr->AlgnmtErr         = pfe_emac_get_stat_value(prEmac, RX_ALIGNMENT_ERROR_PACKETS);
        CounterPtr->SqeTestErr        = 0xFFFFFFFFU;
        CounterPtr->DiscInbdPkt       = pfe_emac_get_stat_value(prEmac, RX_FIFO_OVERFLOW_PACKETS);
        CounterPtr->ErrInbdPkt        = 0xFFFFFFFFU;
        CounterPtr->DiscOtbdPkt       = pfe_emac_get_stat_value(prEmac, TX_UNDERFLOW_ERROR_PACKETS);
        CounterPtr->SnglCollPkt       = pfe_emac_get_stat_value(prEmac, TX_SINGLE_COLLISION_GOOD_PACKETS);
        CounterPtr->MultCollPkt       = pfe_emac_get_stat_value(prEmac, TX_MULTIPLE_COLLISION_GOOD_PACKETS);
        CounterPtr->DfrdPkt           = pfe_emac_get_stat_value(prEmac, TX_DEFERRED_PACKETS);
        CounterPtr->LatCollPkt        = pfe_emac_get_stat_value(prEmac, TX_LATE_COLLISION_PACKETS);
        CounterPtr->HwDepCtr0         = 0xFFFFFFFFU;
        CounterPtr->HwDepCtr1         = 0xFFFFFFFFU;
        CounterPtr->HwDepCtr2         = 0xFFFFFFFFU;
        CounterPtr->HwDepCtr3         = 0xFFFFFFFFU;
    }

    return E_OK;
}
#endif /* STD_ON == ETH_43_GET_COUNTER_API */

#if STD_ON == ETH_43_GET_RXSTATS_API
/**
* @brief         Return the list of Receive Statistics.
* @note          Not supported on AUX interface (returns structure filled by invalid values).
* @param[in]     u8CtrlIdx Index of controller within the context of the Ethernet Driver.
* @param[out]    RxStats List of values according to IETF RFC 2819.
* @details       RxStats List of values according to IETF RFC 2819, where the maximal possible value shall
*                denote an invalid value.
*                e.g. if this counter is not available.
*/
Std_ReturnType Eth_PFE_LLD_GetRxStats(uint8 u8CtrlIdx, \
                                            Eth_RxStatsType * RxStatsPtr
                                        )
{
    pfe_emac_t *prEmac = NULL_PTR;

    prEmac = Eth_PFE_LLD_GetEmacInstanceByControllerId(u8CtrlIdx);
    if (NULL_PTR == prEmac)
    {
        /* Only EMAC interfaces has statistics, return invalid values for other interfaces */
        RxStatsPtr->RxStatsDropEvents           = 0xFFFFFFFFU;
        RxStatsPtr->RxStatsOctets               = 0xFFFFFFFFU;
        RxStatsPtr->RxStatsPkts                 = 0xFFFFFFFFU;
        RxStatsPtr->RxStatsBroadcastPkts        = 0xFFFFFFFFU;
        RxStatsPtr->RxStatsMulticastPkts        = 0xFFFFFFFFU;
        RxStatsPtr->RxStatsCrcAlignErrors       = 0xFFFFFFFFU;
        RxStatsPtr->RxStatsUndersizePkts        = 0xFFFFFFFFU;
        RxStatsPtr->RxStatsOversizePkts         = 0xFFFFFFFFU;
        RxStatsPtr->RxStatsFragments            = 0xFFFFFFFFU;
        RxStatsPtr->RxStatsJabbers              = 0xFFFFFFFFU;
        RxStatsPtr->RxStatsCollisions           = 0xFFFFFFFFU;
        RxStatsPtr->RxStatsPkts64Octets         = 0xFFFFFFFFU;
        RxStatsPtr->RxStatsPkts65to127Octets    = 0xFFFFFFFFU;
        RxStatsPtr->RxStatsPkts128to255Octets   = 0xFFFFFFFFU;
        RxStatsPtr->RxStatsPkts256to511Octets   = 0xFFFFFFFFU;
        RxStatsPtr->RxStatsPkts512to1023Octets  = 0xFFFFFFFFU;
        RxStatsPtr->RxStatsPkts1024to1518Octets = 0xFFFFFFFFU;
        RxStatsPtr->RxUnicastFrames             = 0xFFFFFFFFU;
    }
    else
    {
        /* Maximal possible value shall denote an invalid value (e.g. counter not available) */
        const uint32_t rx_crc_err = pfe_emac_get_stat_value(prEmac, RX_CRC_ERROR_PACKETS);
        const uint32_t rx_align_err = pfe_emac_get_stat_value(prEmac, RX_ALIGNMENT_ERROR_PACKETS);
        RxStatsPtr->RxStatsCrcAlignErrors       = (rx_crc_err > (UINT32_MAX-rx_align_err)) ? UINT32_MAX : rx_align_err + rx_crc_err; /* saturated sum */

        RxStatsPtr->RxStatsDropEvents           = pfe_emac_get_stat_value(prEmac, RX_FIFO_OVERFLOW_PACKETS);
        RxStatsPtr->RxStatsOctets               = pfe_emac_get_stat_value(prEmac, RX_OCTET_COUNT_GOOD_BAD);
        RxStatsPtr->RxStatsPkts                 = pfe_emac_get_stat_value(prEmac, RX_PACKETS_COUNT_GOOD_BAD);
        RxStatsPtr->RxStatsBroadcastPkts        = pfe_emac_get_stat_value(prEmac, RX_BROADCAST_PACKETS_GOOD);
        RxStatsPtr->RxStatsMulticastPkts        = pfe_emac_get_stat_value(prEmac, RX_MULTICAST_PACKETS_GOOD);
        RxStatsPtr->RxStatsUndersizePkts        = pfe_emac_get_stat_value(prEmac, RX_UNDERSIZE_PACKETS_GOOD);
        RxStatsPtr->RxStatsOversizePkts         = pfe_emac_get_stat_value(prEmac, RX_OVERSIZE_PACKETS_GOOD);
        RxStatsPtr->RxStatsFragments            = pfe_emac_get_stat_value(prEmac, RX_RUNT_ERROR_PACKETS);
        RxStatsPtr->RxStatsJabbers              = pfe_emac_get_stat_value(prEmac, RX_JABBER_ERROR_PACKETS);
        RxStatsPtr->RxStatsCollisions           = 0xFFFFFFFFU;
        RxStatsPtr->RxStatsPkts64Octets         = pfe_emac_get_stat_value(prEmac, RX_64OCTETS_PACKETS_GOOD_BAD);
        RxStatsPtr->RxStatsPkts65to127Octets    = pfe_emac_get_stat_value(prEmac, RX_65TO127OCTETS_PACKETS_GOOD_BAD);
        RxStatsPtr->RxStatsPkts128to255Octets   = pfe_emac_get_stat_value(prEmac, RX_128TO255OCTETS_PACKETS_GOOD_BAD);
        RxStatsPtr->RxStatsPkts256to511Octets   = pfe_emac_get_stat_value(prEmac, RX_256TO511OCTETS_PACKETS_GOOD_BAD);
        RxStatsPtr->RxStatsPkts512to1023Octets  = pfe_emac_get_stat_value(prEmac, RX_512TO1023OCTETS_PACKETS_GOOD_BAD);
        RxStatsPtr->RxStatsPkts1024to1518Octets = pfe_emac_get_stat_value(prEmac, RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD);
        RxStatsPtr->RxUnicastFrames             = pfe_emac_get_stat_value(prEmac, RX_UNICAST_PACKETS_GOOD);
    }
    return E_OK;
}
#endif /* STD_ON == ETH_43_GET_RXSTATS_API */

#if STD_ON == ETH_43_GET_TXSTATS_API
/**
* @brief         Return the list of Transmission Statistics.
* @note          Not supported on AUX interface (returns structure filled by invalid values).
* @param[in]     u8CtrlIdx Index of controller within the context of the Ethernet Driver.
* @param[out]    TxStats List of the controller within the context of the Ethernet Driver.
* @details       Return the list of Transmission Sratistics out of IETF RFC1213
*                defined with Eth_TxStatsType, where the maximal possible value shall
*                denote an invalid value.
*                e.g. this counter is not available..
*/
Std_ReturnType Eth_PFE_LLD_GetTxStats(uint8 u8CtrlIdx, \
                                            Eth_TxStatsType * TxStatsPtr
                                        )
{
    pfe_emac_t *prEmac = NULL_PTR;

    prEmac = Eth_PFE_LLD_GetEmacInstanceByControllerId(u8CtrlIdx);
    /* Only EMAC interfaces has statistics, return invalid values for other interface */
    if (NULL_PTR == prEmac)
    {

        TxStatsPtr->TxNumberOfOctets  = 0xFFFFFFFFU;
        TxStatsPtr->TxNUcastPkts      = 0xFFFFFFFFU;
        TxStatsPtr->TxUniCastPkts     = 0xFFFFFFFFU;
    }
    else
    {
        const uint32_t tx_mc_good_bad = pfe_emac_get_stat_value(prEmac, TX_MULTICAST_PACKETS_GOOD_BAD);
        const uint32_t tx_bc_good_bad = pfe_emac_get_stat_value(prEmac, TX_BROADCAST_PACKETS_GOOD_BAD);
        TxStatsPtr->TxNUcastPkts      = (tx_bc_good_bad > (UINT32_MAX-tx_mc_good_bad)) ? UINT32_MAX : tx_mc_good_bad + tx_bc_good_bad; /* saturated sum */

        TxStatsPtr->TxNumberOfOctets  = pfe_emac_get_stat_value(prEmac, TX_OCTET_COUNT_GOOD_BAD);
        TxStatsPtr->TxUniCastPkts     = pfe_emac_get_stat_value(prEmac, TX_UNICAST_PACKETS_GOOD_BAD); 
    }
    return E_OK;
}
#endif /* STD_ON == ETH_43_GET_TXSTATS_API */

#if STD_ON == ETH_43_GET_TXERROR_COUNTER_API
/**
* @brief         Return the list of Transmission Statistics.
* @note          Not supported on AUX interface (returns structure filled by invalid values).
* @param[in]     u8CtrlIdx Index of controller within the context of the Ethernet Driver.
* @param[out]    Eth_TxErrorCounterValuesType List of values to read statistic error values for transmiision.
* @details       Return the list of Transmission Error Counters out of IETF RFC1213 and RFC1643
*                defined with Eth_TxErrorCounterValuesType, where the maximal possible value shall
*                denote an invalid value.
*                e.g. this counter is not available..
*/
Std_ReturnType Eth_PFE_LLD_GetTxErrorCounterValues(uint8 u8CtrlIdx, \
                                            Eth_TxErrorCounterValuesType * TxErrorCounterValuesPtr
                                        )
{
    pfe_emac_t *prEmac = NULL_PTR;

    prEmac = Eth_PFE_LLD_GetEmacInstanceByControllerId(u8CtrlIdx);
    /* Only EMAC interfaces has statistics, return invalid values for other interface */
    if (NULL_PTR == prEmac)
    {
        TxErrorCounterValuesPtr->TxDroppedNoErrorPkts = 0xFFFFFFFFU;
        TxErrorCounterValuesPtr->TxDroppedErrorPkts   = 0xFFFFFFFFU;
        TxErrorCounterValuesPtr->TxDeferredTrans      = 0xFFFFFFFFU;
        TxErrorCounterValuesPtr->TxSingleCollision    = 0xFFFFFFFFU;
        TxErrorCounterValuesPtr->TxMultipleCollision  = 0xFFFFFFFFU;
        TxErrorCounterValuesPtr->TxLateCollision      = 0xFFFFFFFFU;
        TxErrorCounterValuesPtr->TxExcessiveCollison  = 0xFFFFFFFFU;
    }
    else
    {
        const uint32_t tx_count_good_bad = pfe_emac_get_stat_value(prEmac, TX_PACKET_COUNT_GOOD_BAD);
        const uint32_t tx_count_good     = pfe_emac_get_stat_value(prEmac, TX_PACKET_COUNT_GOOD);
        PfeDevAssert(tx_count_good_bad >= tx_count_good);
        TxErrorCounterValuesPtr->TxDroppedErrorPkts   = tx_count_good_bad - tx_count_good;

        TxErrorCounterValuesPtr->TxDroppedNoErrorPkts = pfe_emac_get_stat_value(prEmac, TX_UNDERFLOW_ERROR_PACKETS);
        TxErrorCounterValuesPtr->TxDeferredTrans      = pfe_emac_get_stat_value(prEmac, TX_DEFERRED_PACKETS);
        TxErrorCounterValuesPtr->TxSingleCollision    = pfe_emac_get_stat_value(prEmac, TX_SINGLE_COLLISION_GOOD_PACKETS);
        TxErrorCounterValuesPtr->TxMultipleCollision  = pfe_emac_get_stat_value(prEmac, TX_MULTIPLE_COLLISION_GOOD_PACKETS);
        TxErrorCounterValuesPtr->TxLateCollision      = pfe_emac_get_stat_value(prEmac, TX_LATE_COLLISION_PACKETS);
        TxErrorCounterValuesPtr->TxExcessiveCollison  = pfe_emac_get_stat_value(prEmac, TX_EXCESSIVE_COLLISION_PACKETS);
    }
    return E_OK;
}
#endif /* STD_ON == ETH_43_GET_TXERROR_COUNTER_API */

#if (STD_ON == ETH_43_PFE_CHANNEL_BD_FLUSH_API) && defined(PFE_CFG_PFE_MASTER)
/*================================================================================================*/
Std_ReturnType Eth_PFE_LLD_ChannelBdFlushRx(pfe_ct_phy_if_id_t DestHifChnl)
{
    Std_ReturnType Ret = E_NOT_OK;

    if(E_OK == ChannelBdFlushRxPrepare(DestHifChnl))
    {
        Ret = ChannelBdFlushRxExecute(DestHifChnl);
    }

    return Ret;
}
#endif /* (STD_ON == ETH_43_PFE_CHANNEL_BD_FLUSH_API) && defined(PFE_CFG_PFE_MASTER) */

/*================================================================================================*/
#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
#ifdef PFE_CFG_PFE_MASTER
/**
* @brief         Set master detect flags in all HIF channels.
*/
void Eth_43_PFE_LLD_SetMasterUp(void)
{
    if (TRUE == pfe_hif_get_master_detect_cfg(ptrPlatform->hif))
    {
        /* Set Master detect flags for all HIF channels */
        pfe_hif_set_master_up(ptrPlatform->hif);
    }
}
#endif /* PFE_CFG_PFE_MASTER */
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */

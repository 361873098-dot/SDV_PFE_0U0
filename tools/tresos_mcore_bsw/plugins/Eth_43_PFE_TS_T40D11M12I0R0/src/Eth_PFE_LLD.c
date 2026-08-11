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
 *  SW Version           : 1.2.0
 *  Build Version        : PFE-DRV_S32G_M7_MCAL_1.2.0_D2307_ASR_REL_4_4_REV_0000_20230728
 *
 *  (c) Copyright 2006-2016 Freescale Semiconductor, Inc.
 *      Copyright 2017-2023 NXP
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
#define PFE_SRC_VERSION_CHECK 43120440

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "pfe_cfg.h"
#include "Eth_43_PFE.h" /* Includes also Eth_GeneralTypes.h, Eth_43_PFE_Cfg.h,
                    Eth_43_PFE_ComStack_Types.h, Dem.h, Det.h and Mcal.h */
#include "Eth_43_PFE_Irq.h" /* Interrupt handlers to be called from ClientEventHdlr */
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
#include "pfe_emac_csr.h"
#include "pfe_hm.h"
#include "pfe_tmu_csr.h"
#include "pfe_cbus.h"
#include "pfe_gpi_csr.h"
#include "pfe_bmu_csr.h"

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
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/**
 * @brief This enum describes PFE interface type
 */
typedef enum
{
    IF_TYPE_EMAC = 0,   /**< EMAC interface */
    IF_TYPE_AUX,        /**< AUX interface */
    IF_TYPE_HIF         /**< HIF interface */
} pfeIfType_t;

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
    pfe_log_if_t            *prLogIfEmac;
    pfe_log_if_t            *prLogIf;
    pfe_phy_if_t            *prPhyIf;
    pfe_hif_drv_client_t    *prClient;
    pfe_mac_addr_t          au8MacAddr;
    boolean                 bMacAddrValid;
    boolean                 bInterfacePrepared;
    pfeIfType_t             ifType;

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
*                                       LOCAL MACROS
==================================================================================================*/
#define DRIVER_COMMIT_HASH      "2938036ec1a8bdeeaefab4fdb2da43333aa11a4f"
#define PFE_DRIVER_VERSION      "1.2.0"

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

#define MAX_NUM_OF_SCH          (2U)
#define MAX_NUM_OF_SCH_INPUT    (8U)
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

/* Index of charater in EthCtrlHwPort used to identify PHY IF */
#define CTRL_HW_PORT_NAME_POS    3U


/* Temporary workaround for AAVB-8200 until AAVB-4234 is implemented in FW */
#define IS_RECEIVE_MALFORMED_ALLOWED  ((ETH_43_PFE_ENABLE_OFFLOAD_CSUM_IPV4 != STD_ON) \
                                    || (ETH_43_PFE_ENABLE_OFFLOAD_CSUM_TCP  != STD_ON) \
                                    || (ETH_43_PFE_ENABLE_OFFLOAD_CSUM_UDP  != STD_ON) \
                                    || (ETH_43_PFE_ENABLE_OFFLOAD_CSUM_ICMP != STD_ON))

/*==================================================================================================
*                                     GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#ifndef PFE_CFG_PFE_SLAVE
#define ETH_43_PFE_START_SEC_CONST_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

static const pfe_ct_phy_if_id_t emac_ids[] = {PFE_PHY_IF_ID_EMAC0, PFE_PHY_IF_ID_EMAC1, PFE_PHY_IF_ID_EMAC2};

#define ETH_43_PFE_STOP_SEC_CONST_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_PFE_SLAVE */

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
    that is why we need to store also the CtrlIdx here.  */
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

#ifdef PFE_CFG_PFE_SLAVE
/* usage scope: Eth_PFE_LLD_UpdatePhysAddrFilter*/
static uint32 u32CntName[ETH_43_PFE_MAXCTRLS_SUPPORTED] = {0U};
#endif /* PFE_CFG_PFE_SLAVE */

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
    .irq_vector_global = 198U, /*FIXME or 197?*/        /* Global IRQ number */
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

/*  Milti-buffer Rx frames management - for discarding multi-buffer frames */
static boolean abRxToDiscard[ETH_43_PFE_MAXCTRLS_SUPPORTED][ETH_43_PFE_MAX_RXFIFO_CONFIG] = {{ FALSE }};

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

static errno_t ClientEventHdlr
(
    pfe_hif_drv_client_t *prClient,
    void *pvArg,
    uint32 u32Event,
    uint32 u32QueueIdx
);
static void DestroyHifDrv(oal_irq_t *prIRQ, pfe_hif_drv_t *prHifDrv);
#ifdef PFE_CFG_PFE_SLAVE
static pfe_log_if_t *get_log_if_from_if_db_entry_by_mac_addr(const pfe_if_db_entry_t *entry, const uint8 *mac_addr, pfe_ct_phy_if_id_t phy_if_parent_id);
static pfe_log_if_t *get_log_if_by_mac_addr(const pfe_platform_t *platform, pfe_ct_phy_if_id_t owner, pfe_ct_phy_if_id_t phy_if_parent_id, const uint8 *mac_addr);
static errno_t delete_log_if_multicast(const pfe_platform_t *platform, pfe_if_db_entry_t *entry, pfe_ct_phy_if_id_t owner, pfe_ct_phy_if_id_t phy_if_parent_id, uint32 session_id);
static errno_t delete_all_log_if_multicast(const pfe_platform_t *platform, pfe_ct_phy_if_id_t owner, pfe_ct_phy_if_id_t phy_if_parent_id);
#endif
static Std_ReturnType ConfigureTxBuffers(void);
#ifndef PFE_CFG_HIF_NOCPY_SUPPORT
static errno_t InitializeTxHeaders(const uint8 u8CtrlIdx, pfe_hif_drv_client_t *client);
#endif
LOCAL_INLINE boolean GetTxBuffer(const uint8 u8CtrlIdx, const uint8 u8FifoIdx, Eth_BufIdxType * const pBufIdx);
LOCAL_INLINE addr_t GetTxBufAddr(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx);
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
LOCAL_INLINE uint8 GetTxBufFifoIndex(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx);
#endif
LOCAL_INLINE void SetTxBufStatus(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx, const uint8 u8Status);
LOCAL_INLINE void ClearTxBufStatusBits
(
    const uint8 u8CtrlIdx, 
    const Eth_BufIdxType BufIdx, 
    const uint8 u8BitsToClear
);
LOCAL_INLINE uint8 GetTxBufStatus(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx);
LOCAL_INLINE void ReleaseTxBuffer(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx);
LOCAL_INLINE void ReleaseAllCtrlTxBuffers(const uint8 u8CtrlIdx);
LOCAL_INLINE void *TxReqQueueWrite(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx);
LOCAL_INLINE Eth_PFE_LLD_trTxRefData *TxReqQueueRead(const uint8 u8CtrlIdx);
LOCAL_INLINE void TxReqQueueDelete(const uint8 u8CtrlIdx);
#if (STD_ON == ETH_43_PFE_GLOBALTIME_SUPPORT)
static errno_t GetTxTimeStamp
(
    uint8 CtrlIdx,
    Eth_BufIdxType BufIdx,
    Eth_TimeStampQualType *timeQualPtr,
    Eth_TimeStampType *timeStampPtr
);
#endif
#if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
static bool_t  CommonHifChnlISR(void *arg);
#endif /* PFE_CFG_HIF_IRQ_ENABLED */
static boolean CreateHifDrv(pfe_ct_phy_if_id_t HifId, uint32 u32IrqVector, pfe_hif_chnl_t **pprHifChnl, oal_irq_t **pprIRQ, pfe_hif_drv_t **pprHifDrv);
static Std_ReturnType GetPhyIfIdByCtrlHwPort(uint8 u8CtrlIdx, pfe_ct_phy_if_id_t *phy_if_id);
#ifndef PFE_CFG_PFE_SLAVE
static errno_t ConfigureSchedulerAndShaper(uint8 u8CtrlIdx);
#endif /* PFE_CFG_PFE_SLAVE */

#if (STD_ON == ETH_43_PFE_DEM_EVENT_DETECT)
static boolean DetectErrorsAndLostFrame(uint8 u8CtrlIdx, ErrorIdType errorId);
static void CheckDemStatus(uint8 u8CtrlIdx, uint32 demConfig, ErrorIdType errorId, Dem_EventIdType demId);
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */
static void Eth_PFE_LLD_ResetGlobalVar(void);
#ifdef PFE_CFG_PFE_MASTER
static boolean Eth_PFE_LLD_DetectHardReset(void);
#endif /* PFE_CFG_PFE_MASTER */
static void Eth_PFE_LLD_ShutdownDriver(void);
static pfe_emac_t *Eth_PFE_LLD_GetEmacInstanceByControllerId(uint8 u8CtrlIdx);

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

/*  Auxiliary function to get hif chnl, interrupt and drv */
static boolean CreateHifDrv(pfe_ct_phy_if_id_t HifId, uint32 u32IrqVector, pfe_hif_chnl_t **pprHifChnl, oal_irq_t **pprIRQ, pfe_hif_drv_t **pprHifDrv)
{
    boolean bRetVal = FALSE;
    pfe_hif_chnl_t *prHifChnl;
    pfe_hif_drv_t *prHifDrv = NULL_PTR;
#if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
    oal_irq_t *prIRQ = NULL_PTR;
#else
    (void)u32IrqVector;
    (void)pprIRQ;
#endif

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
        /*  Create interrupt */
        prIRQ = oal_irq_create(
                    (int32_t)u32IrqVector,
                    (oal_irq_flags_t)0,
                    NULL_PTR /* irq name is unused in oal_irq_create */
                    );
        if (NULL_PTR == prIRQ)
        {
            NXP_LOG_ERROR("Could not create HIF IRQ\n");
        }
        else
        {
            /*  Install IRQ handler */
            if (EOK != oal_irq_add_handler(prIRQ, (oal_irq_handler_t)&CommonHifChnlISR, prHifChnl, NULL_PTR))
            {
                NXP_LOG_ERROR("Could not add IRQ handler\n");
            }
            else
            {
#endif /* PFE_CFG_HIF_IRQ_ENABLED */
                /*  Create HIF driver for the channel */
                prHifDrv = pfe_hif_drv_create(prHifChnl);
                if (NULL_PTR == prHifDrv)
                {
                    NXP_LOG_ERROR("Could not get HIF driver instance\n");
                }
                else
                {
                    if (EOK != pfe_hif_drv_init(prHifDrv))
                    {
                        NXP_LOG_ERROR("pfe_hif_drv_init() failed\n");
                    }
                    else
                    {
#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
                        /*  We need to start here to be able to configure master
                            during initialization */
                        if (EOK != pfe_hif_drv_start(prHifDrv))
                        {
                            NXP_LOG_ERROR("HIF driver start failed\n");
                        }
                        else
                        {
                            if (EOK != pfe_idex_init(prHifDrv, rPlatformCfg.master_if, ptrPlatform->hif, &pfe_platform_idex_rpc_cbk, (void *)ptrPlatform, NULL_PTR))
                            {
                                NXP_LOG_ERROR("Can't initialize IDEX\n");
                            }
                            else
                            {
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */
                                /*  Now particular channel interrupt source can be enabled */
                                /*  Everything is OK */
                            #if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
                                pfe_hif_chnl_irq_unmask(prHifChnl);
                                *pprIRQ = prIRQ;
                            #endif
                                *pprHifChnl = prHifChnl;
                                *pprHifDrv = prHifDrv;
                                bRetVal = TRUE;
#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
                            }
                        }
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */
                    }
                }

#if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
            }
        }
#endif /* PFE_CFG_HIF_IRQ_ENABLED */
    }
    if (FALSE == bRetVal)
    {   /*  Some error, undo all steps */
#if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
        DestroyHifDrv(prIRQ, prHifDrv);
#else
        DestroyHifDrv(NULL_PTR, prHifDrv);
#endif
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

#ifdef PFE_CFG_PFE_SLAVE
/*  Auxiliary function to get logical interface instance from database entry by mac address */
static pfe_log_if_t *get_log_if_from_if_db_entry_by_mac_addr(const pfe_if_db_entry_t *entry, const uint8 *mac_addr, pfe_ct_phy_if_id_t phy_if_parent_id)
{
    pfe_log_if_t *log_if_ret = NULL_PTR;
    pfe_log_if_t *log_if_tmp = NULL_PTR;
    bool_t bFoundAddr = FALSE;
    pfe_ct_if_m_rules_t matchRules;
    pfe_ct_if_m_args_t rMatchArguments;
    pfe_phy_if_t *phy_if = NULL_PTR;
    pfe_ct_phy_if_id_t phy_if_id;

    /* Get logical interface instance from database entry */
    log_if_tmp = pfe_if_db_entry_get_log_if(entry);
    if (NULL_PTR != log_if_tmp)
    {
        /* Get match rules */
        if (EOK == pfe_log_if_get_match_rules(log_if_tmp, &matchRules, &rMatchArguments))
        {
            /* Check if associated MAC address matches the input mac address */
            if (0 == autolibc_memcmp(mac_addr, rMatchArguments.dmac, sizeof(pfe_mac_addr_t)))
            {
                bFoundAddr = TRUE;
            }
        }
    }

    if (TRUE == bFoundAddr)
    {
        /* Get parent physical interface */
        phy_if = pfe_log_if_get_parent(log_if_tmp);
        if (NULL_PTR != phy_if)
        {
            phy_if_id = pfe_phy_if_get_id(phy_if);
            if (phy_if_id == phy_if_parent_id)
            {
                log_if_ret = log_if_tmp;
            }
        }
    }

    return log_if_ret;
}

/*  Auxiliary function to get logical interface corresponding to mac address */
static pfe_log_if_t *get_log_if_by_mac_addr(const pfe_platform_t *platform, pfe_ct_phy_if_id_t owner, pfe_ct_phy_if_id_t phy_if_parent_id, const uint8 *mac_addr)
{
    pfe_log_if_t *log_if_ret = NULL_PTR;
    pfe_if_db_entry_t *entry = NULL_PTR;
    uint32 session_id = 0U;
    errno_t ret;

    if(EOK != pfe_if_db_lock(&session_id))
    {
        NXP_LOG_DEBUG("DB lock failed\n");
    }

    ret = pfe_if_db_get_first(platform->log_if_db, session_id, IF_DB_CRIT_BY_OWNER, (void *)owner, &entry);
    while ((EOK == ret) && (NULL_PTR != entry))
    {
        log_if_ret = get_log_if_from_if_db_entry_by_mac_addr(entry, mac_addr, phy_if_parent_id);
        if (NULL_PTR != log_if_ret)
        {
            break;
        }
        ret = pfe_if_db_get_next(platform->log_if_db, session_id, &entry);
    }

    if(EOK != pfe_if_db_unlock(session_id))
    {
        NXP_LOG_DEBUG("DB unlock failed\n");
    }

    return log_if_ret;
}

/*  Auxiliary function to delete logical interface with multicast address */
static errno_t delete_log_if_multicast(const pfe_platform_t *platform, pfe_if_db_entry_t *entry, pfe_ct_phy_if_id_t owner, pfe_ct_phy_if_id_t phy_if_parent_id, uint32 session_id)
{
    pfe_log_if_t *log_if_tmp = NULL_PTR;
    bool_t bMatchParent = FALSE;
    bool_t bFoundAddr = FALSE;
    pfe_ct_if_m_rules_t matchRules;
    pfe_ct_if_m_args_t rMatchArguments;
    pfe_phy_if_t *phy_if = NULL_PTR;
    pfe_ct_phy_if_id_t phy_if_id;
    errno_t err = EOK;

    /* Get logical interface instance from database entry */
    log_if_tmp = pfe_if_db_entry_get_log_if(entry);
    if (NULL_PTR != log_if_tmp)
    {
        /* Get parent physical interface */
        phy_if = pfe_log_if_get_parent(log_if_tmp);
        if (NULL_PTR != phy_if)
        {
            phy_if_id = pfe_phy_if_get_id(phy_if);
            if (phy_if_id == phy_if_parent_id)
            {
                bMatchParent = TRUE;
            }
        }
    }

    if (TRUE == bMatchParent)
    {
        /* Get match rules */
        if (EOK == pfe_log_if_get_match_rules(log_if_tmp, &matchRules, &rMatchArguments))
        {
            /* Check if associated MAC address is multicast */
            if (pfe_emac_is_multi(rMatchArguments.dmac))
            {
                bFoundAddr = TRUE;
            }
        }
    }

    if (TRUE == bFoundAddr)
    {
        /* Remove entry from DB */
        if (EOK != pfe_if_db_remove(platform->log_if_db, session_id, entry))
        {
            NXP_LOG_ERROR("Could not remove entry from DB\n");
            err = ENODEV;
        }
        /* Remove all multicast addresses associated with current log_if */
        else if (EOK != pfe_log_if_flush_mac_addrs(log_if_tmp, MAC_DB_CRIT_BY_OWNER_AND_TYPE, PFE_TYPE_MC, owner))
        {
            NXP_LOG_ERROR("Could not delete MAC addresses added by owner with defined type\n");
            err = ENODEV;
        }
        else
        {
            /* Destroy interface instance */
            pfe_log_if_destroy(log_if_tmp);
        }
    }

    return err;
}

/*  Auxiliary function to delete all logical interface with multicast address */
static errno_t delete_all_log_if_multicast(const pfe_platform_t *platform, pfe_ct_phy_if_id_t owner, pfe_ct_phy_if_id_t phy_if_parent_id)
{
    pfe_if_db_entry_t *entry = NULL_PTR;
    uint32 session_id = 0U;
    bool_t bFail = FALSE;
    errno_t ret;

    if(EOK != pfe_if_db_lock(&session_id))
    {
        NXP_LOG_DEBUG("DB lock failed\n");
    }

    ret = pfe_if_db_get_first(platform->log_if_db, session_id, IF_DB_CRIT_BY_OWNER, (void *)owner, &entry);
    while ((EOK == ret) && (NULL_PTR != entry))
    {
        ret = delete_log_if_multicast(platform, entry, owner, phy_if_parent_id, session_id);
        if (EOK != ret)
        {
            bFail = TRUE;
            break;
        }
        ret = pfe_if_db_get_next(platform->log_if_db, session_id, &entry);
    }

    if (TRUE == bFail)
    {
        ret = ENODEV;
    }
    else
    {
        ret = EOK;
    }

    if(EOK != pfe_if_db_unlock(session_id))
    {
        NXP_LOG_DEBUG("DB unlock failed\n");
    }

    return ret;
}
#endif

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
LOCAL_INLINE boolean GetTxBuffer(const uint8 u8CtrlIdx, const uint8 u8FifoIdx, Eth_BufIdxType * const pBufIdx)
{
    boolean bFound = FALSE;
    trTxBufPool *prBufPool = &aarTxBufPool[u8CtrlIdx][u8FifoIdx];
    uint16 u16IdxOff = prBufPool->u16IndexOffset;
    uint16 u16BufNum = prBufPool->u16BufNumber;
    uint16 u16Idx = prBufPool->u16GetIdx;

    do /* Search for a free buffer control record */
    {
        if (TX_BUF_FREE == GetTxBufStatus(u8CtrlIdx, (uint32)u16Idx + u16IdxOff))
        {
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
            /* Try to get buffer from BMU */
            aarTxBuf[u8CtrlIdx][u16Idx + u16IdxOff].BufAddr =
                        (addr_t)pfe_hif_chnl_bmu_alloc_buf_va(arPfeInterface[u8CtrlIdx].prHifChnl);
            if (NULL_ADDR != aarTxBuf[u8CtrlIdx][u16Idx + u16IdxOff].BufAddr)
#endif
            {
                /* Success */
                SetTxBufStatus(u8CtrlIdx, (uint32)u16Idx + u16IdxOff, TX_BUF_PROVIDED);
                *pBufIdx = (uint32)u16Idx + u16IdxOff;
                bFound = TRUE;
                /* Update GetIdx */
                if (prBufPool->u16GetIdx == u16Idx)
                {
                    oal_mutex_lock(PFE_TX_BUFFER_POOL_MUTEX);
                    prBufPool->u16GetIdx++;
                    if (prBufPool->u16GetIdx >= u16BufNum)
                    {
                        prBufPool->u16GetIdx = 0U;
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
LOCAL_INLINE addr_t GetTxBufAddr(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx)
{
    return aarTxBuf[u8CtrlIdx][BufIdx].BufAddr;
}

/*================================================================================================*/
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
LOCAL_INLINE uint8 GetTxBufFifoIndex(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx)
{
    return aarTxBuf[u8CtrlIdx][BufIdx].u8Fifo;
}
#endif

/*================================================================================================*/
LOCAL_INLINE void SetTxBufStatus(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx, const uint8 u8Status)
{
    aarTxBuf[u8CtrlIdx][BufIdx].u8Status = u8Status;
}

/*================================================================================================*/
LOCAL_INLINE void ClearTxBufStatusBits
(
    const uint8 u8CtrlIdx, 
    const Eth_BufIdxType BufIdx, 
    const uint8 u8BitsToClear
)
{
    aarTxBuf[u8CtrlIdx][BufIdx].u8Status &= ~u8BitsToClear;
}

/*================================================================================================*/
LOCAL_INLINE uint8 GetTxBufStatus(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx)
{
    return aarTxBuf[u8CtrlIdx][BufIdx].u8Status;
}

/*================================================================================================*/
LOCAL_INLINE void ReleaseTxBuffer(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx)
{
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        if (TX_BUF_PROVIDED == GetTxBufStatus(u8CtrlIdx, BufIdx))
        {
            addr_t BufAddr = GetTxBufAddr(u8CtrlIdx, BufIdx);
            (void)pfe_hif_chnl_bmu_free_buf(arPfeInterface[u8CtrlIdx].prHifChnl, BufAddr);
        }
#endif
        SetTxBufStatus(u8CtrlIdx, BufIdx, TX_BUF_FREE);
}

/*================================================================================================*/
LOCAL_INLINE void ReleaseAllCtrlTxBuffers(const uint8 u8CtrlIdx)
{
    for(Eth_BufIdxType BufIdx = 0U; BufIdx < ETH_43_PFE_MAX_CTRL_TX_BUF_CNT; BufIdx++)
    {
        ReleaseTxBuffer(u8CtrlIdx, BufIdx);
    }
}

/*================================================================================================*/
/* Adds BufIdx to Tx Request Queue (at write index) and returns pointer to the new record, which
   can be used as ref_ptr for pfe_hif_drv_client_xmit_pkt */
LOCAL_INLINE void *TxReqQueueWrite(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx)
{
    /* There is enough room in arTxReqQueue to fit all Tx buffers => no need to check if record is free */
    Eth_PFE_LLD_trTxRefData *prRefPtr = &arTxReqQueue[u8CtrlIdx][u16TxQueueWrite[u8CtrlIdx]];
    u16TxQueueWrite[u8CtrlIdx]++;
    if (u16TxQueueWrite[u8CtrlIdx] >= ETH_43_PFE_MAX_CTRL_TX_BUF_CNT)
    {
        u16TxQueueWrite[u8CtrlIdx] = 0U;
    }
    prRefPtr->u16BufIdx = (uint16)BufIdx;
    return (void *)prRefPtr;
}

/*================================================================================================*/
/* Provides record from Tx Request Queue at read index */
LOCAL_INLINE Eth_PFE_LLD_trTxRefData *TxReqQueueRead(const uint8 u8CtrlIdx)
{
    Eth_PFE_LLD_trTxRefData *prRefPtr = &arTxReqQueue[u8CtrlIdx][u16TxQueueRead[u8CtrlIdx]];
    return prRefPtr;
}

/*================================================================================================*/
/* Deletes record from Tx Request Queue at read index */
LOCAL_INLINE void TxReqQueueDelete(const uint8 u8CtrlIdx)
{
    arTxReqQueue[u8CtrlIdx][u16TxQueueRead[u8CtrlIdx]].u16BufIdx = INVALID_TX_INDEX;
    u16TxQueueRead[u8CtrlIdx]++;
    if (u16TxQueueRead[u8CtrlIdx] >= ETH_43_PFE_MAX_CTRL_TX_BUF_CNT)
    {
        u16TxQueueRead[u8CtrlIdx] = 0U;
    }
}

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

    (void)prClient;
    switch(u32Event)
    {
        case EVENT_HIGH_RX_WM: /* Rx queue has reached watermark level */
            ; /* FIXME implement */
            break;
        case EVENT_RX_PKT_IND: /* New packet(s) received */
            /* Only call the handler here if the interrupt mode is enabled */
            if(TRUE == ETH_43_PFE_CFG_ENABLERXINTERRUPT(u8ClientIdx))
            {
                if(ETH_STATE_INIT == Eth_43_PFE_CtrlState[u8ClientIdx])
                {
                    /*  Return value is not needed in interrupt mode */
                    (void)Eth_PFE_LLD_ReportReception(u8ClientIdx, (uint8)u32QueueIdx, (boolean)TRUE);
                }
            }
            break;
        case EVENT_TXDONE_IND: /* New Tx confirmation(s) */
            /* Only call the handler here if the interrupt mode is enabled */
            if(TRUE == ETH_43_PFE_CFG_ENABLETXINTERRUPT(u8ClientIdx))
            {
                if(ETH_STATE_INIT == Eth_43_PFE_CtrlState[u8ClientIdx])
                {
                    if(ETH_MODE_ACTIVE == Eth_PFE_LLD_CheckControllerIsActive(u8ClientIdx))
                    {
                        /*  Return value is not needed in interrupt mode */
                        Eth_PFE_LLD_ReportTransmission(u8ClientIdx, (uint8)u32QueueIdx);
                    }
                }
            }
            break;
#if (STD_ON == ETH_43_PFE_GLOBALTIME_SUPPORT)
        case EVENT_ETS: /* New egress timestamp(s) available, generate confirmation(s) for timestamped frames */
            /* Only call the handler here if the interrupt mode is enabled */
            if(TRUE == ETH_43_PFE_CFG_ENABLETXINTERRUPT(u8ClientIdx))
            {
                if(ETH_STATE_INIT == Eth_43_PFE_CtrlState[u8ClientIdx])
                {
                    Eth_PFE_LLD_ReportTransmissionTS(u8ClientIdx, (uint8)u32QueueIdx);
                }
            }
            break;
#endif /*ETH_43_PFE_GLOBALTIME_SUPPORT*/
        case EVENT_RX_OOB: /* Ran out of Rx buffers */
            ; /* FIXME implement */
            break;
        default:
            /*Do Nothing*/
            break;
    }
    return RetValue;
}

#if (STD_ON == ETH_43_PFE_GLOBALTIME_SUPPORT)
/*================================================================================================*/
static errno_t GetTxTimeStamp(uint8 CtrlIdx, \
                              Eth_BufIdxType BufIdx, \
                              Eth_TimeStampQualType *timeQualPtr, \
                              Eth_TimeStampType *timeStampPtr \
                             )
{
    errno_t RetVal = ENOENT;
    const Eth_PFE_LLD_trTxTsRef *rTsRef;

    if (NULL_PTR != arPfeInterface[CtrlIdx].prClient)
    {
        rTsRef = Eth_PFE_LLD_GetTxBufTsRef(CtrlIdx, BufIdx);
        /* Get timestamp */
        RetVal = pfe_hif_drv_client_get_ts
        (
            arPfeInterface[CtrlIdx].prClient, FALSE,
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

/*================================================================================================*/
/**
 * @brief      Get the PHY IF ID by EthCtrlHwPort object
 * @param[in]  u8CtrlIdx Index of controller
 * @param[out] phy_if_id Physical interface id which attached to controller
 * @return     ret Return E_OK if success, error code otherwise
 */
static Std_ReturnType GetPhyIfIdByCtrlHwPort(uint8 u8CtrlIdx, pfe_ct_phy_if_id_t *phy_if_id)
{
    Std_ReturnType ret = (Std_ReturnType)E_OK;
    const trPfeDev *prPfeDev;

    prPfeDev = &arPfeInterface[u8CtrlIdx];

    /* ETH_43_PFE_CFG_CTRLHWPORT(u8CtrlIdx) can be pfe0, pfe1, pfe2, hif0, hif1, hif2, hif3 or hifnocpy */
    if (IF_TYPE_EMAC == prPfeDev->ifType)
    {
        /* ETH_43_PFE_CFG_CTRLHWPORT(u8CtrlIdx) can be pfe0, pfe1, pfe2 */
        switch (ETH_43_PFE_CFG_CTRLHWPORT(u8CtrlIdx)[CTRL_HW_PORT_NAME_POS])
        {
            case '0':
            {
                *phy_if_id = PFE_PHY_IF_ID_EMAC0;
                break;
            }
            case '1':
            {
                *phy_if_id = PFE_PHY_IF_ID_EMAC1;
                break;
            }
            case '2':
            {
                *phy_if_id = PFE_PHY_IF_ID_EMAC2;
                break;
            }
            default:
            {
                *phy_if_id = PFE_PHY_IF_ID_INVALID;
                ret = (Std_ReturnType)E_NOT_OK;
                break;
            }
        }
    }
    else if (IF_TYPE_HIF == prPfeDev->ifType)
    {
        /* ETH_43_PFE_CFG_CTRLHWPORT(u8CtrlIdx) can be hif0, hif1, hif2, hif3 or hifnocpy */
        switch (ETH_43_PFE_CFG_CTRLHWPORT(u8CtrlIdx)[CTRL_HW_PORT_NAME_POS])
        {
            case '0':
            {
                *phy_if_id = PFE_PHY_IF_ID_HIF0;
                break;
            }
            case '1':
            {
                *phy_if_id = PFE_PHY_IF_ID_HIF1;
                break;
            }
            case '2':
            {
                *phy_if_id = PFE_PHY_IF_ID_HIF2;
                break;
            }
            case '3':
            {
                *phy_if_id = PFE_PHY_IF_ID_HIF3;
                break;
            }
            case 'n':
            {
                *phy_if_id = PFE_PHY_IF_ID_HIF_NOCPY;
                break;
            }
            default:
            {
                *phy_if_id = PFE_PHY_IF_ID_INVALID;
                ret = (Std_ReturnType)E_NOT_OK;
                break;
            }
        }
    }
    else
    {
        *phy_if_id = PFE_PHY_IF_ID_INVALID;
        ret = (Std_ReturnType)E_NOT_OK;
    }

    return ret;
}

/*================================================================================================*/
#ifndef PFE_CFG_PFE_SLAVE
static errno_t ConfigureSchedulerAndShaper(uint8 u8CtrlIdx)
{
    errno_t ret = EOK;
    uint8 u8SchCnt;
    uint8 u8FifoCnt;
    const Eth_43_PFE_SchedulerCfgType *pSch;
    const Eth_43_PFE_ShaperCfgType *pShp;
    uint8 u8Fifo;
    uint8 u8Sch;
    const Eth_43_PFE_SchedulerInputInfoCfgType *pSchInput;
    uint8 u8SchInputCnt;
    uint8 u8SchInput;
    uint8 u8SchInputIdx;
    boolean bUnusedSchInput = TRUE;
    uint8 u8ShpCnt;
    uint8 u8Shp;
    const uint8 aShpPos[MAX_NUM_OF_SCH][MAX_NUM_OF_SCH_INPUT] = {SHP_POS_COR_SCH0, SHP_POS_COR_SCH1};
    uint8 u8TempShpPos;
    pfe_ct_phy_if_id_t temp_emac_id;
    boolean bSchedulerChaining = FALSE;

    ret = (errno_t)GetPhyIfIdByCtrlHwPort(u8CtrlIdx, &temp_emac_id);
    if(EOK != ret)
    {
        NXP_LOG_ERROR("Could not get PHY IF ID for controller %u\n", (uint_t)u8CtrlIdx);
        return ret;
    }

    u8SchCnt = Eth_43_PFE_InternalCfgPtr->pController[u8CtrlIdx]->EthCtrlSchedulerCnt;
    u8ShpCnt = Eth_43_PFE_InternalCfgPtr->pController[u8CtrlIdx]->EthCtrlShaperCnt;
    u8FifoCnt = Eth_43_PFE_InternalCfgPtr->pController[u8CtrlIdx]->EthCtrlEgressFifoCnt;
    pSch = Eth_43_PFE_InternalCfgPtr->pController[u8CtrlIdx]->pSchCfg;
    pShp = Eth_43_PFE_InternalCfgPtr->pController[u8CtrlIdx]->pShpCfg;

    /* Set tail-drop mode for all queues */
    for (u8Fifo = 0U; u8Fifo < u8FifoCnt; u8Fifo++)
    {
        ret = pfe_tmu_queue_set_mode(ptrPlatform->tmu, temp_emac_id, u8Fifo, TMU_Q_MODE_TAIL_DROP, 0U, MAX_Q_SIZE);
        if(EOK != ret)
        {
            NXP_LOG_ERROR("Failed to set queue mode\n");
            return ret;
        }
    }

    for (u8Sch = 0U; u8Sch < u8SchCnt; u8Sch++)
    {
        if (TRUE == pSch[u8Sch].IsLastSch)
        {
            pSchInput = pSch[u8Sch].pSchInputInfoCfg;
            /* Set scheduler rate mode */
            ret = pfe_tmu_sch_set_rate_mode(ptrPlatform->tmu, temp_emac_id, SCH1_ID, pSch[u8Sch].SchRateMode);
            if(EOK != ret)
            {
                NXP_LOG_ERROR("Failed to set scheduler rate mode\n");
                return ret;
            }
            /* Set scheduler algorithm */
            ret = pfe_tmu_sch_set_algo(ptrPlatform->tmu, temp_emac_id, SCH1_ID, pSch[u8Sch].SchAlgo);
            if(EOK != ret)
            {
                NXP_LOG_ERROR("Failed to set scheduler algorithm\n");
                return ret;
            }

            u8SchInputCnt = pSch[u8Sch].SchInputCnt;
            for (u8SchInput = 0U; u8SchInput < u8SchInputCnt; u8SchInput++)
            {
                /* Set scheduler input weight */
                if ((SCHED_ALGO_WRR == pSch[u8Sch].SchAlgo) || (SCHED_ALGO_DWRR == pSch[u8Sch].SchAlgo))
                {
                    ret = pfe_tmu_sch_set_input_weight(ptrPlatform->tmu, temp_emac_id, SCH1_ID, pSchInput[u8SchInput].u8Input, pSchInput[u8SchInput].u32Weight);
                    if(EOK != ret)
                    {
                        NXP_LOG_ERROR("Failed to set scheduler input weight\n");
                        return ret;
                    }
                }

                if (IS_FIFO == pSchInput[u8SchInput].SchInputType)
                {
                    /* Connect queue to scheduler input */
                    ret = pfe_tmu_sch_bind_queue(ptrPlatform->tmu, temp_emac_id, SCH1_ID, pSchInput[u8SchInput].u8Input, pSchInput[u8SchInput].u8InputIdx);
                    if(EOK != ret)
                    {
                        NXP_LOG_ERROR("Failed to connect queue to scheduler input\n");
                        return ret;
                    }
                }
                else if (IS_SHAPER == pSchInput[u8SchInput].SchInputType)
                {
                    for (u8Shp = 0; u8Shp < u8ShpCnt; u8Shp++)
                    {
                        if (pShp[u8Shp].u8ShpIdx == pSchInput[u8SchInput].u8InputIdx)
                        {
                            ret = pfe_tmu_shp_enable(ptrPlatform->tmu, temp_emac_id, pShp[u8Shp].u8ShpIdx);
                            if(EOK != ret)
                            {
                                NXP_LOG_ERROR("Failed to enable shaper\n");
                                return ret;
                            }
                            ret = pfe_tmu_shp_set_limits(ptrPlatform->tmu, temp_emac_id, pShp[u8Shp].u8ShpIdx, pShp[u8Shp].s32MaxCredit, -(pShp[u8Shp].s32MinCredit));
                            if(EOK != ret)
                            {
                                NXP_LOG_ERROR("Failed to set shaper credit limits\n");
                                return ret;
                            }
                            u8TempShpPos = aShpPos[SCH1_ID][pSchInput[u8SchInput].u8Input];
                            ret = pfe_tmu_shp_set_position(ptrPlatform->tmu, temp_emac_id, pShp[u8Shp].u8ShpIdx, u8TempShpPos);
                            if(EOK != ret)
                            {
                                NXP_LOG_ERROR("Failed to set shaper position\n");
                                return ret;
                            }
                            ret = pfe_tmu_shp_set_idle_slope(ptrPlatform->tmu, temp_emac_id, pShp[u8Shp].u8ShpIdx , pShp[u8Shp].u32IdleSlope);
                            if(EOK != ret)
                            {
                                NXP_LOG_ERROR("Failed to set shaper idle slope\n");
                                return ret;
                            }
                            ret = pfe_tmu_sch_bind_queue(ptrPlatform->tmu, temp_emac_id, SCH1_ID, pSchInput[u8SchInput].u8Input, pShp[u8Shp].u8FifoIdx);
                            if(EOK != ret)
                            {
                                NXP_LOG_ERROR("Failed to connect queue to scheduler input\n");
                                return ret;
                            }
                        }
                    }
                }
                else /* IS_SHEDULER */
                {
                    bSchedulerChaining = TRUE;
                    /* Bind scheduler 0 to scheduler 1 */
                    ret = pfe_tmu_sch_bind_sch_output(ptrPlatform->tmu, temp_emac_id, SCH0_ID, SCH1_ID, pSchInput[u8SchInput].u8Input);
                    if(EOK != ret)
                    {
                        NXP_LOG_ERROR("Failed to connect scheduler 0  to scheduler 1\n");
                        return ret;
                    }
                }
            }

#ifndef PFE_CFG_MULTI_INSTANCE_SUPPORT
            /* We only disable unused queues in single instance mode, because in multi-instance, 
               when EMACs are shared, all queues could be expected by slaves.
               For example, the SSH server on the Linux slave expects all queues to be enabled */
            /* Invalidate all unused scheduler inputs */
            for (u8SchInputIdx = 0U; u8SchInputIdx < MAX_NUM_OF_SCH_INPUT; u8SchInputIdx++)
            {
                for (u8SchInput = 0U; u8SchInput < u8SchInputCnt; u8SchInput++)
                {
                    if (pSchInput[u8SchInput].u8Input == u8SchInputIdx)
                    {
                        bUnusedSchInput = FALSE;
                        break;
                    }
                }
                if (TRUE == bUnusedSchInput)
                {
                    ret = pfe_tmu_sch_bind_queue(ptrPlatform->tmu, temp_emac_id, SCH1_ID, u8SchInputIdx, PFE_TMU_INVALID_QUEUE);
                    if(EOK != ret)
                    {
                        NXP_LOG_ERROR("Failed to connect queue to scheduler input\n");
                        return ret;
                    }
                }
                else
                {
                    bUnusedSchInput = TRUE;
                }
            }
#endif
        }
    }

    bUnusedSchInput = TRUE;

    for (u8Sch = 0U; u8Sch < u8SchCnt; u8Sch++)
    {
        if(TRUE == bSchedulerChaining)
        {
            if (FALSE == pSch[u8Sch].IsLastSch)
            {
                pSchInput = pSch[u8Sch].pSchInputInfoCfg;
                /* Set scheduler rate mode */
                ret = pfe_tmu_sch_set_rate_mode(ptrPlatform->tmu, temp_emac_id, SCH0_ID, pSch[u8Sch].SchRateMode);
                if (EOK != ret)
                {
                    NXP_LOG_ERROR("Failed to set scheduler rate mode\n");
                    return ret;
                }
                /* Set scheduler algorithm */
                ret = pfe_tmu_sch_set_algo(ptrPlatform->tmu, temp_emac_id, SCH0_ID, pSch[u8Sch].SchAlgo);
                if (EOK != ret)
                {
                    NXP_LOG_ERROR("Failed to set scheduler algorithm\n");
                    return ret;
                }

                u8SchInputCnt = pSch[u8Sch].SchInputCnt;
                for (u8SchInput = 0U; u8SchInput < u8SchInputCnt; u8SchInput++)
                {
                    /* Set scheduler input weight */
                    if ((SCHED_ALGO_WRR == pSch[u8Sch].SchAlgo) || (SCHED_ALGO_DWRR == pSch[u8Sch].SchAlgo))
                    {
                        ret = pfe_tmu_sch_set_input_weight(ptrPlatform->tmu, temp_emac_id, SCH0_ID, pSchInput[u8SchInput].u8Input, pSchInput[u8SchInput].u32Weight);
                        if(EOK != ret)
                        {
                            NXP_LOG_ERROR("Failed to set scheduler input weight\n");
                            return ret;
                        }
                    }

                    if (IS_FIFO == pSchInput[u8SchInput].SchInputType)
                    {
                        /* Connect queue to scheduler input */
                        ret = pfe_tmu_sch_bind_queue(ptrPlatform->tmu, temp_emac_id, SCH0_ID, pSchInput[u8SchInput].u8Input, pSchInput[u8SchInput].u8InputIdx);
                        if(EOK != ret)
                        {
                            NXP_LOG_ERROR("Failed to connect queue to scheduler input\n");
                            return ret;
                        }
                    }
                    else /* IS_SHAPER */
                    {
                        for (u8Shp = 0; u8Shp < u8ShpCnt; u8Shp++)
                        {
                            if (pShp[u8Shp].u8ShpIdx == pSchInput[u8SchInput].u8InputIdx)
                            {
                                ret = pfe_tmu_shp_enable(ptrPlatform->tmu, temp_emac_id, pShp[u8Shp].u8ShpIdx);
                                if(EOK != ret)
                                {
                                    NXP_LOG_ERROR("Failed to enable shaper\n");
                                    return ret;
                                }
                                ret = pfe_tmu_shp_set_limits(ptrPlatform->tmu, temp_emac_id, pShp[u8Shp].u8ShpIdx, pShp[u8Shp].s32MaxCredit, -(pShp[u8Shp].s32MinCredit));
                                if(EOK != ret)
                                {
                                    NXP_LOG_ERROR("Failed to set shaper credit limits\n");
                                    return ret;
                                }
                                u8TempShpPos = aShpPos[SCH0_ID][pSchInput[u8SchInput].u8Input];
                                ret = pfe_tmu_shp_set_position(ptrPlatform->tmu, temp_emac_id, pShp[u8Shp].u8ShpIdx, u8TempShpPos);
                                if(EOK != ret)
                                {
                                    NXP_LOG_ERROR("Failed to set shaper position\n");
                                    return ret;
                                }
                                ret = pfe_tmu_shp_set_idle_slope(ptrPlatform->tmu, temp_emac_id, pShp[u8Shp].u8ShpIdx , pShp[u8Shp].u32IdleSlope);
                                if(EOK != ret)
                                {
                                    NXP_LOG_ERROR("Failed to set shaper idle slope\n");
                                    return ret;
                                }
                                ret = pfe_tmu_sch_bind_queue(ptrPlatform->tmu, temp_emac_id, SCH0_ID, pSchInput[u8SchInput].u8Input, pShp[u8Shp].u8FifoIdx);
                                if(EOK != ret)
                                {
                                    NXP_LOG_ERROR("Failed to connect queue to scheduler input\n");
                                    return ret;
                                }
                            }
                        }
                    }
                }

                /* Invalidate all unused scheduler inputs */
                for (u8SchInputIdx = 0U; u8SchInputIdx < MAX_NUM_OF_SCH_INPUT; u8SchInputIdx++)
                {
                    for (u8SchInput = 0U; u8SchInput < u8SchInputCnt; u8SchInput++)
                    {
                        if (pSchInput[u8SchInput].u8Input == u8SchInputIdx)
                        {
                            bUnusedSchInput = FALSE;
                            break;
                        }
                    }
                    if (TRUE == bUnusedSchInput)
                    {
                        ret = pfe_tmu_sch_bind_queue(ptrPlatform->tmu, temp_emac_id, SCH0_ID, u8SchInputIdx, PFE_TMU_INVALID_QUEUE);
                        if(EOK != ret)
                        {
                            NXP_LOG_ERROR("Failed to connect queue to scheduler input\n");
                            return ret;
                        }
                    }
                    else
                    {
                        bUnusedSchInput = TRUE;
                    }
                }
            }
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
static void CheckDemStatus(uint8 u8CtrlIdx, uint32 demConfig, ErrorIdType errorId, Dem_EventIdType demId)
{
    /* Check Dem event ON or OFF */
    if ((uint32)STD_ON == demConfig)
    {
        if (DetectErrorsAndLostFrame(u8CtrlIdx, errorId))
        {
            (void)Dem_SetEventStatus(demId, DEM_EVENT_STATUS_PREFAILED);
        }
        else
        {
            (void)Dem_SetEventStatus(demId, DEM_EVENT_STATUS_PREPASSED);
        }
    }
}
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */

/**
* @brief         Reset global variables used by the driver to the default values
*/
static void Eth_PFE_LLD_ResetGlobalVar(void)
{
#ifdef PFE_CFG_PFE_SLAVE
    uint8 u8Cnt = 0U;

    for (u8Cnt = 0U; u8Cnt < ETH_43_PFE_MAXCTRLS_SUPPORTED; u8Cnt++)
    {
        /* usage scope: Eth_PFE_LLD_UpdatePhysAddrFilter */
        u32CntName [u8Cnt] = 0U;
    }
#endif /* PFE_CFG_PFE_SLAVE */

#ifdef PFE_CFG_RTABLE_ENABLE
    /* usage scope: Eth_PFE_LLD_MainFunction */
    /* Routing table timer ticks, used for rtable entries timeout update */
    u32RtrTimeoutTimeMs = 0U;
#endif /* PFE_CFG_RTABLE_ENABLE */
}

#ifdef PFE_CFG_PFE_MASTER
/**
* @brief         Detect the hard reset
*/
static boolean Eth_PFE_LLD_DetectHardReset(void)
{
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
            bRetVal = pfe_hif_chnl_is_hw_reset_state(prHifChnl);
        }
    }

    return bRetVal;
}
#endif /* PFE_CFG_PFE_MASTER */

/**
* @brief         Shutdown the driver if it was initialized before
*/
static void Eth_PFE_LLD_ShutdownDriver(void)
{
    uint8 u8Ctr;
    pfe_phy_if_t *prHif = NULL_PTR;
#ifdef PFE_CFG_PFE_MASTER
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
#endif /* PFE_CFG_PFE_MASTER */
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
static pfe_emac_t *Eth_PFE_LLD_GetEmacInstanceByControllerId(uint8 u8CtrlIdx)
{
    pfe_emac_t *prEmac = NULL_PTR;
    pfe_ct_phy_if_id_t emac_id;
    const trPfeDev *prPfeDev;

    prPfeDev = &arPfeInterface[u8CtrlIdx];
    if (IF_TYPE_EMAC == prPfeDev->ifType)
    {
        if ((Std_ReturnType)E_OK != GetPhyIfIdByCtrlHwPort(u8CtrlIdx, &emac_id))
        {
            NXP_LOG_ERROR("Could not get EMAC ID associated to the controller %u\n", (uint_t)u8CtrlIdx);
        }
        else
        {
            prEmac = ptrPlatform->emac[emac_id];
        }
    }
    return prEmac;
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

trTxMeta *Eth_PFE_LLD_GetTxBufMeta(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx)
{
    return &aarTxBuf[u8CtrlIdx][BufIdx].rMeta;
}

/*================================================================================================*/
#if (STD_ON == ETH_43_PFE_GLOBALTIME_SUPPORT)
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
void Eth_PFE_LLD_InitInterfaces(const Eth_43_PFE_ConfigType * cfgPtr)
{
#ifdef PFE_CFG_PFE_SLAVE
    (void)cfgPtr;
#else
    uint8 u8CtrlCount = 0U;
    uint8 u8EmacIdx = 0U;
    uint8 u8MiiMode = 0U;

            /* Clear the register in case there were some changes already */
    *(uint32 *)(uintptr_t)(S32G_GPR_BASE + PFE_EMACX_INTF_SEL_OFF) = 0U;

    /* Decode PFE cfg to g2 platform serdes */
    for (u8CtrlCount = 0U; u8CtrlCount < (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG; u8CtrlCount++)
    {
        u8EmacIdx = cfgPtr->pController[u8CtrlCount]->EthCtrlHwPort[3U]-'0';

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

/**
* @brief         Prepares and initializes common part of PFE drivers
* @details       Prepares cache, memory management, main mutex, loads firmware and initializes
*                platform driver, HIF driver and FCI driver.
* @retval        E_NOT_OK The Platform drivers are not prepared
* @retval        E_OK The Platform drivers are initialized successfully
*/
Std_ReturnType Eth_PFE_LLD_PlatformDrvPrepare(void)
{
#ifdef PFE_CFG_PFE_SLAVE
    uint32 slave_tmout = PFE_CFG_SLAVE_HIF_MASTER_UP_TMOUT;
#endif /* PFE_CFG_PFE_SLAVE */
    boolean bFail = FALSE;
    pfe_phy_if_t *prHif = NULL_PTR;
    Std_ReturnType retVal = E_NOT_OK;

    NXP_LOG_INFO("Driver commit hash: %s\n", rPlatformCfg.commit_hash);
    NXP_LOG_INFO("Driver version: %s\n", rPlatformCfg.driver_version);

#ifdef PFE_CFG_PFE_MASTER
#if (TRUE == PFE_CFG_BMU_IRQ_ENABLED)
    bDetectBmuInit = FALSE;
#endif /* PFE_CFG_BMU_IRQ_ENABLED */
#endif /* PFE_CFG_PFE_MASTER */

#ifdef PFE_CFG_PFE_MASTER
#if IS_RECEIVE_MALFORMED_ALLOWED
    pfe_fw_feature_t *receive_malformed;
#endif    
    pfe_fw_t rFirmware;
    rFirmware.class_data = PFE_CLASS_FW_BINARY;
#endif /* PFE_CFG_PFE_MASTER */

#ifdef PFE_CFG_PFE_SLAVE
    NXP_LOG_INFO("Wait for IP-ready ...\n");
    while (TRUE)
    {
        if (TRUE == Local_Macro_hal_ip_ready_get())
        {
            NXP_LOG_INFO("Detected IP-ready\n");
            break;
        }

        oal_time_usleep(1000U);

        /* Decrement only for slave_tmout > 0 */
        if (0U < slave_tmout)
        {
            slave_tmout--;
            if (0U == slave_tmout)
            {
                retVal = E_NOT_OK;
                NXP_LOG_RAW_ERROR("Detection IP-ready timeouted\n");
#if (STD_ON == ETH_43_PFE_DEM_EVENT_DETECT)
                (void)Dem_SetEventStatus((Dem_EventIdType)ETH_43_PFE_CFG_DEM_E_DRIVER_RUNTIME_ERR_IP_READY, DEM_EVENT_STATUS_PREFAILED);
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */
                return retVal;
            }
        }
    }
#endif /* PFE_CFG_PFE_SLAVE */

    /* Shutdown the driver if it was initialized before */
    Eth_PFE_LLD_ShutdownDriver();

    /*  Initialize Tx buffer pools */
    if ((Std_ReturnType)E_NOT_OK == ConfigureTxBuffers())
    {
        bFail = TRUE;
    }
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

    if (FALSE == bFail)
    {
        if (EOK != pfe_platform_init(&rPlatformCfg))
        {
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
#if defined(PFE_CFG_PFE_MASTER) && IS_RECEIVE_MALFORMED_ALLOWED
            /* Get receive_malformed feature */
            else if (EOK != pfe_class_get_feature(ptrPlatform->classifier, &receive_malformed, "receive_malformed"))
            {
                retVal = E_NOT_OK;
                NXP_LOG_ERROR("Unable to get feature\n");
            }
            /* Enable receive_malformed feature */
            else if (EOK != pfe_fw_feature_set_val(receive_malformed, 1U))
            {
                retVal = E_NOT_OK;
                NXP_LOG_ERROR("Enable receive_malformed feature failed\n");
            }
#endif /* PFE_CFG_PFE_MASTER */
            /*  Get HIF driver instance */
            else if (FALSE == CreateHifDrv(  PFE_CFG_LOCAL_IF,
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
#ifdef PFE_CFG_PFE_SLAVE
            /*  Create platform-wide pool of interfaces. Must be done here where HIF channel
                is already initialized to allow slave driver create the instances via IDEX. */
            else if (EOK != pfe_platform_create_ifaces(ptrPlatform))
            {
                retVal = E_NOT_OK;
                NXP_LOG_ERROR("Can't create interfaces\n");
            }
#endif /* PFE_CFG_PFE_SLAVE */
            else
            {
                /*  Get the physical interface for our HIF channel */
                prHif = pfe_platform_get_phy_if_by_id(ptrPlatform, PFE_CFG_LOCAL_IF);
                if (NULL_PTR == prHif)
                {
                    retVal = E_NOT_OK;
                    NXP_LOG_ERROR("Can't get physical interface for the HIF\n");
                }
                else
                {
                    /* Enable HIF physical interfaces */
                    if (E_OK != pfe_phy_if_enable(prHif))
                    {
                        retVal = E_NOT_OK;
                        NXP_LOG_ERROR("Failed to enable physical interface for the HIF\n");
                    }
                    else
                    {
                        retVal = E_OK;
                    }
                }
            }
        }
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
    trPfeDev *prPfeDev;
    pfe_emac_t *prPfeEmac = NULL_PTR;
    pfe_ct_phy_if_id_t temp_phy_id;
    pfe_ct_if_m_args_t rMatchArguments; /* BIG endian here */
    pfe_ct_if_m_rules_t MatchRules = IF_MATCH_NONE;
#if defined(PFE_CFG_PFE_SLAVE)
    pfe_phy_if_t *prHif = NULL_PTR;
    (void)prPfeEmac;
#else
    pfe_log_if_t *prLogIf = NULL_PTR;
#endif

    abRxToDiscard[u8CtrlIdx][0U] = FALSE;
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
        prPfeDev = &(arPfeInterface[u8CtrlIdx]);
        prPfeDev->bInterfacePrepared = FALSE;

        (void)autolibc_memcpy(prPfeDev->au8MacAddr, ETH_43_PFE_CFG_MACADDRESS(u8CtrlIdx), 6U);

        prPfeDev->u8CtrlIdx = u8CtrlIdx;
        prPfeDev->bStarted = FALSE;
        prPfeDev->prClient = NULL_PTR; /* Always initialize as it is used for checks */
        prPfeDev->bMacAddrValid = FALSE;
#if (STD_ON == ETH_43_PFE_GLOBALTIME_SUPPORT)
        uint8 u8FifoCnt;
        uint16 u16BufCnt;
        uint8 u8FifoNum = Eth_43_PFE_InternalCfgPtr->pController[u8CtrlIdx]->EthCtrlEgressFifoCnt;
        
        for (u8FifoCnt = 0u; u8FifoCnt < u8FifoNum; u8FifoCnt++)
        {
            prPfeDev->u16TSQueueRead[u8FifoCnt] = 0U;
            prPfeDev->u16TSQueueWrite[u8FifoCnt] = 0U;
            for (u16BufCnt = 0U; u16BufCnt < ETH_43_PFE_MAX_FIFO_TX_BUF_CNT; u16BufCnt++)
            {
                prPfeDev->TSQueue[u8FifoCnt][u16BufCnt] = INVALID_TX_INDEX;
            }
        }
#endif
        /*  Get components */
        prPfeDev->prPlatform = ptrPlatform;
        prPfeDev->HifId = ETH_43_PFE_COMMON_HIF;
        prPfeDev->prHifChnl = prCommonHifChnl;
        prPfeDev->prHifChnlIRQ = prCommonChnlIRQ;
        prPfeDev->prHifDrv = prCommonHifDrv;

        if (0 == autolibc_strcmp("aux", ETH_43_PFE_CFG_CTRLHWPORT(u8CtrlIdx)))
        {   /* AUX interface */
            prPfeDev->ifType = IF_TYPE_AUX;
            prPfeDev->prPhyIf = NULL_PTR;
            prPfeDev->prLogIf = NULL_PTR;
            prPfeDev->bMacAddrValid = TRUE;
            /* All done, the final result will be checked in next function */
            prPfeDev->bInterfacePrepared = TRUE;
        }
        else if ('h' == ETH_43_PFE_CFG_CTRLHWPORT(u8CtrlIdx)[0])
        {   /* HIF interface (hif0-hif3, hifnocpy) */
            prPfeDev->ifType = IF_TYPE_HIF;
            if((Std_ReturnType)E_OK != GetPhyIfIdByCtrlHwPort(u8CtrlIdx, &temp_phy_id))
            {
                NXP_LOG_ERROR("Could not get PHY IF ID for controller %u\n", (uint_t)u8CtrlIdx);
                return;
            }
            /* Get HIF to attach to this controller */
            prPfeDev->prPhyIf = pfe_platform_get_phy_if_by_id(ptrPlatform, temp_phy_id);
            if (NULL_PTR == prPfeDev->prPhyIf)
            {
                NXP_LOG_ERROR("Could not get HIF phy if %u\n", (uint_t)temp_phy_id);
                return;
            }
            prPfeDev->prLogIf = NULL_PTR;
            prPfeDev->bMacAddrValid = TRUE;
            prPfeDev->bInterfacePrepared = TRUE;
        }
        else
        {   /* EMAC interface */
            prPfeDev->ifType = IF_TYPE_EMAC;
            if((Std_ReturnType)E_OK != GetPhyIfIdByCtrlHwPort(u8CtrlIdx, &temp_phy_id))
            {
                NXP_LOG_ERROR("Could not get PHY IF ID for controller %u\n", (uint_t)u8CtrlIdx);
                return;
            }
            /* Get EMAC to attach to this controller */
            prPfeDev->prPhyIf = pfe_platform_get_phy_if_by_id(ptrPlatform, temp_phy_id);
            if (NULL_PTR == prPfeDev->prPhyIf)
            {
                NXP_LOG_ERROR("Could not get EMAC %u\n", (uint_t)temp_phy_id);
                return;
            }
            /*  Create a logical interface that will be used to dispatch packets from the EMAC */
            prPfeDev->prLogIf = pfe_log_if_create(prPfeDev->prPhyIf, ETH_43_PFE_CFG_CTRLHWPORT(u8CtrlIdx));
            if (NULL_PTR == prPfeDev->prLogIf)
            {
                NXP_LOG_ERROR("Could not create logical interface\n");
                return;
            }
#if defined(PFE_CFG_PFE_SLAVE)
            /*  Get the physical interface for our HIF channel */
            prHif = pfe_platform_get_phy_if_by_id(ptrPlatform, prPfeDev->HifId);
            if (NULL_PTR == prHif)
            {
                NXP_LOG_ERROR("Can't get physical interface for the HIF\n");
                return;
            }
#endif
            /*  Send packets received via logical interface to the HIF channel */
    #ifdef PFE_CFG_PFE_SLAVE
            /*  Allows Rx packet dispatching based on logical interfaces, which is the approach used here */
            if (E_OK != pfe_phy_if_set_op_mode(prPfeDev->prPhyIf, IF_OP_FLEX_ROUTER))
            {
                NXP_LOG_ERROR("Failed to change op mode on EMAC\n");
                return;
            }
            /* Set destination MAC address and enable/disable broadcast for matching Rx traffic */
            (void)autolibc_memcpy(rMatchArguments.dmac, prPfeDev->au8MacAddr, 6U);
            MatchRules = IF_MATCH_DMAC;
            if(TRUE == ETH_43_PFE_CFG_BROADCAST(u8CtrlIdx)) /* Enable broadcast if enabled in configuration */
            {
                MatchRules |= IF_MATCH_TYPE_BCAST;
            }
            if (E_OK != pfe_log_if_set_match_rules(prPfeDev->prLogIf, MatchRules, &rMatchArguments))
            {
                NXP_LOG_ERROR("Failed to set match rule (MAC address)\n");
                return;
            }
            if (E_OK != pfe_log_if_set_match_or(prPfeDev->prLogIf))
            {
                NXP_LOG_ERROR("Failed to set match OR\n");
                return;
            }
            /*  Make sure that EMAC ingress traffic will be forwarded to our HIF channel(s) */
            if (EOK != pfe_log_if_add_egress_if(prPfeDev->prLogIf, prHif))
            {
                NXP_LOG_ERROR("Can't add egress interface (%s)\n", pfe_log_if_get_name(prPfeDev->prLogIf));
                return;
            }
    #else
            if(FALSE == ETH_43_PFE_CFG_BROADCAST(u8CtrlIdx)) /* Disable broadcast if disabled in configuration */
            {
                const uint8 au8MacAddr[6] = {0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU};
                /*  Allows Rx packet dispatching based on logical interfaces, which is the approach used here */
                if (E_OK != pfe_phy_if_set_op_mode(prPfeDev->prPhyIf, IF_OP_FLEX_ROUTER))
                {
                    NXP_LOG_ERROR("Failed to change op mode on EMAC\n");
                    return;
                }
                (void)autolibc_memcpy(rMatchArguments.dmac, au8MacAddr, 6U);
                MatchRules = IF_MATCH_DMAC;
                /*  Create a logical interface that will be used to dispatch packets from the EMAC */
                prLogIf = pfe_log_if_create(prPfeDev->prPhyIf, "log_if_dis_receive_broadcast");
                if (NULL_PTR == prLogIf)
                {
                    NXP_LOG_ERROR("Could not create logical interface\n");
                    return;
                }
                if (E_OK != pfe_log_if_set_match_rules(prLogIf, MatchRules, &rMatchArguments))
                {
                    NXP_LOG_ERROR("Failed to add match rule (IF_MATCH_TYPE_MCAST)\n");
                    return;
                }
                if (E_OK != pfe_log_if_set_match_or(prLogIf))
                {
                    NXP_LOG_ERROR("Failed to set match OR\n");
                    return;
                }
                if (E_OK != pfe_log_if_discard_enable(prLogIf))
                {
                    NXP_LOG_ERROR("Failed to set match OR\n");
                    return;
                }
                /*  Attach the logical interface to the EMAC */
                if (EOK != pfe_platform_register_log_if(ptrPlatform, prLogIf))
                {
                    NXP_LOG_ERROR("Could not register logical interface\n");
                    return;
                }
                /* Optionally configure loopback mode on associated EMAC */
                if(TRUE == ETH_43_PFE_CFG_EMAC_LOOPBACK(u8CtrlIdx))
                {
                    if(E_OK != pfe_log_if_loopback_enable(prLogIf))
                    {
                        NXP_LOG_ERROR("EMAC loopback enable failed\n");
                    }
                }
                /*  Configure MAC address on associated EMAC */
                if (EOK == pfe_log_if_add_mac_addr(prLogIf, au8MacAddr, rPlatformCfg.local_hif))
                {
                    prPfeDev->bMacAddrValid = TRUE;
                }
                else
                {
                    NXP_LOG_ERROR("Failed to set MAC address to EMAC%hhu\n", u8CtrlIdx);
                    return;
                }
                if (EOK != pfe_log_if_enable(prLogIf))
                {
                    NXP_LOG_ERROR("Failed to enable the logical interface\n");
                    return;
                }
            }

            if (EOK != pfe_log_if_set_egress_ifs(prPfeDev->prLogIf, ((uint32)1U << (uint8)prPfeDev->HifId)))
            {
                NXP_LOG_ERROR("Can't set egress interface (%s)\n", pfe_log_if_get_name(prPfeDev->prLogIf));
                return;
            }

            /* Makes the logical interface of master driver accept all frames by default, but attached physical
               EMAC interface will be configured based on configuration with promiscuous on/off */
            if (EOK != pfe_log_if_promisc_enable(prPfeDev->prLogIf))
            {
                NXP_LOG_ERROR("Failed to enable promiscuous mode on logical interface\n");
                return;
            }

            prPfeEmac = pfe_phy_if_get_emac(prPfeDev->prPhyIf);
            if (NULL_PTR == prPfeEmac)
            {
                NXP_LOG_ERROR("Can't get EMAC instance from physical interface.\n");
                return;
            }

            if (EOK != pfe_emac_set_link_speed(prPfeEmac, ETH_43_PFE_CFG_LINKSPEED(u8CtrlIdx)))
            {
                NXP_LOG_ERROR("Could not set EMAC link speed.\n");
                return;
            }

            if (EOK != pfe_emac_set_link_duplex(prPfeEmac, ETH_43_PFE_CFG_LINKDUPLEX(u8CtrlIdx)))
            {
                NXP_LOG_ERROR("Could not set EMAC link duplex.\n");
                return;
            }

            /* Optionally configure promiscuous mode */
            if(TRUE == ETH_43_PFE_CFG_PROMISCUOUS(u8CtrlIdx))
            {
                if (EOK != pfe_phy_if_promisc_enable(prPfeDev->prPhyIf))
                {
                    NXP_LOG_ERROR("Failed to enable promiscuous mode on EMAC\n");
                    return;
                }
            }
            else
            {
                if (EOK != pfe_phy_if_promisc_disable(prPfeDev->prPhyIf))
                {
                    NXP_LOG_ERROR("Failed to disable promiscuous mode on EMAC\n");
                    return;
                }
            }

    #endif /* PFE_CFG_PFE_SLAVE */

            /*  Attach the logical interface to the EMAC */
            if (EOK != pfe_platform_register_log_if(ptrPlatform, prPfeDev->prLogIf))
            {
                NXP_LOG_ERROR("Could not register logical interface\n");
                return;
            }

            /* Optionally configure loopback mode on associated EMAC */
            if(TRUE == ETH_43_PFE_CFG_EMAC_LOOPBACK(u8CtrlIdx))
            {
                if(E_OK != pfe_log_if_loopback_enable(prPfeDev->prLogIf))
                {
                    NXP_LOG_ERROR("EMAC loopback enable failed\n");
                }
            }
            /*  Configure MAC address on associated EMAC */
            if (EOK == pfe_log_if_add_mac_addr(prPfeDev->prLogIf, prPfeDev->au8MacAddr, rPlatformCfg.local_hif))
            {
                prPfeDev->bMacAddrValid = TRUE;
            }
            else
            {
                NXP_LOG_ERROR("Failed to set MAC address to EMAC%hhu\n", u8CtrlIdx);
                return;
            }

#ifndef PFE_CFG_PFE_SLAVE
            if (EOK != ConfigureSchedulerAndShaper(u8CtrlIdx))
            {
                NXP_LOG_ERROR("Failed to configure scheduler and shaper");
                return;
            }
#endif /* PFE_CFG_PFE_SLAVE */

            /* All done, the final result will be checked in next function */
            prPfeDev->bInterfacePrepared = TRUE;
        }
    }
}

/*================================================================================================*/
/**
* @brief         General Configuration for all instances of EMAC
* @details       Configures all EMACs
*/
#ifndef PFE_CFG_PFE_SLAVE
void Eth_PFE_LLD_EMACPrepare(void)
{
    uint8 u8CtrlIdx;
    pfe_emac_t *prPfeEmac = NULL_PTR;
    pfe_phy_if_t *prEmac;

    for (u8CtrlIdx = 0U; u8CtrlIdx < (uint8)ETH_43_PFE_NUM_EMAC; u8CtrlIdx++)
    {
        if (EMAC_SPEED_INVALID != ((Eth_43_PFE_InternalCfgPtr->emac[u8CtrlIdx])).EthCtrlSpeed)
        {
            /* Normal interface */
            prEmac = pfe_platform_get_phy_if_by_id(ptrPlatform, emac_ids[u8CtrlIdx]);
            if (NULL_PTR == prEmac)
            {
                NXP_LOG_ERROR("Could not get EMAC %u\n", (uint_t)(u8CtrlIdx));
                return;
            }

            prPfeEmac = pfe_phy_if_get_emac(prEmac);
            if (NULL_PTR == prPfeEmac)
            {
                NXP_LOG_ERROR("Can't get EMAC instance from physical interface.\n");
                return;
            }

            if (EOK != pfe_emac_set_link_speed(prPfeEmac, (((Eth_43_PFE_InternalCfgPtr->emac[u8CtrlIdx])).EthCtrlSpeed)))
            {
                NXP_LOG_ERROR("Could not set EMAC link speed.\n");
                return;
            }

            if (EOK != pfe_emac_set_link_duplex(prPfeEmac, (((Eth_43_PFE_InternalCfgPtr->emac[u8CtrlIdx])).EthCtrlDuplex)))
            {
                NXP_LOG_ERROR("Could not set EMAC link duplex.\n");
                return;
            }
        }
        else
        {
            /* Do nothing */
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
    if (IF_TYPE_EMAC == arPfeInterface[u8CtrlIdx].ifType)
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

    if ((IF_TYPE_AUX == arPfeInterface[u8CtrlIdx].ifType)
         || (IF_TYPE_HIF == arPfeInterface[u8CtrlIdx].ifType))
    {
        if (TRUE == arPfeInterface[u8CtrlIdx].bInterfacePrepared)
        {
            bControllerAvailable = TRUE;
        }
    }
    else
    {
        if (NULL_PTR == arPfeInterface[u8CtrlIdx].prLogIf)
        {
            NXP_LOG_ERROR("Logical interface not created, u8CtrlIdx=%hhu\n", u8CtrlIdx);
        }
        else if (NULL_PTR == arPfeInterface[u8CtrlIdx].prPhyIf)
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
    const Eth_43_PFE_CtrlCfgType *pCtrlCfgType;
    uint32_t ii;
    uint32_t fifoDepth;
    fifo_t *tFifo;
    void **vpData;
    pfe_hif_drv_client_rx_tx_count client_queue;
    pfe_hif_drv_client_fifo_queue client_fifo_queue;

    /* Check initialization results */
    bResult = prPfeDev->bInterfacePrepared;

    if(TRUE == bResult)
    {
        if (FALSE == prPfeDev->bStarted)
        {
            pCtrlCfgType = Eth_43_PFE_InternalCfgPtr->pController[u8CtrlIdx];

            /* initialize TX FIFOs */
            tFifo = pCtrlCfgType->pEgressCfg->EthCtrlConfigEgressFifo;
            vpData = pCtrlCfgType->pEgressCfg->EthCtrlConfigEgressFifoData;
            fifoDepth = RXTX_FIFO_ALIGNED_DEPTH(pCtrlCfgType->EthCtrlEgressFifoDepth);

            for (ii = 0U; ii < pCtrlCfgType->EthCtrlEgressFifoCnt; ii++)
            {
                if (NULL_PTR == fifo_create(pCtrlCfgType->EthCtrlEgressFifoDepth, tFifo, vpData))
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
                tFifo = pCtrlCfgType->pIngressCfg->EthCtrlConfigIngressFifo;
                vpData = pCtrlCfgType->pIngressCfg->EthCtrlConfigIngressFifoData;
                fifoDepth = RXTX_FIFO_ALIGNED_DEPTH(pCtrlCfgType->EthCtrlIngressFifoDepth);

                for (ii = 0U; ii < ETH_43_PFE_MAX_RXFIFO_CONFIG; ii++)
                {
                    if (NULL_PTR == fifo_create(pCtrlCfgType->EthCtrlIngressFifoDepth, tFifo, vpData))
                    {
                        bResult = FALSE;
                        break;
                    }
                    tFifo++;
                    vpData += fifoDepth;
                }

                if(TRUE == bResult)
                {
                    if(IF_TYPE_AUX == prPfeDev->ifType)
                    { 
                        client_queue.txq_num = pCtrlCfgType->EthCtrlEgressFifoCnt; /* Number of TX queues */
                        client_queue.rxq_num = ETH_43_PFE_MAX_RXFIFO_CONFIG;       /* Number of RX queues */
                        client_fifo_queue.txq_fifo = pCtrlCfgType->pEgressCfg->EthCtrlConfigEgressFifo;   /* TX Queue FIFO */
                        client_fifo_queue.rxq_fifo = pCtrlCfgType->pIngressCfg->EthCtrlConfigIngressFifo; /* RX Queue FIFO */
                        /*  Connect to HIF */
                        prPfeDev->prClient = pfe_hif_drv_aux_client_register(
                                                                        prPfeDev->prHifDrv,
                                                                        &client_queue,
                                                                        &client_fifo_queue,
                                                                        &ClientEventHdlr,
                                                                        (void *)prPfeDev
                                                                );
                        if(NULL_PTR == prPfeDev->prClient)
                        {
                            bResult = FALSE;
                        }
#ifndef PFE_CFG_MULTI_INSTANCE_SUPPORT
                        else if (EOK != pfe_hif_drv_start(prPfeDev->prHifDrv))
                        {
                            NXP_LOG_ERROR("HIF driver start failed\n");
                            bResult = FALSE;
                        }
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */
#ifndef PFE_CFG_HIF_NOCPY_SUPPORT
                        else if (EOK != InitializeTxHeaders(u8CtrlIdx, prPfeDev->prClient))
                        {
                            NXP_LOG_ERROR("Initialize TX headers failed\n");
                            bResult = FALSE;
                        }
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
                        else
                        {
                            prPfeDev->bStarted = TRUE;
                            NXP_LOG_INFO("AUX interface (Controller %hhu) was started\n", u8CtrlIdx);
                        }
                    }
                    else
                    {
                        client_queue.txq_num = pCtrlCfgType->EthCtrlEgressFifoCnt; /* TX Queue Count */
                        client_queue.rxq_num = ETH_43_PFE_MAX_RXFIFO_CONFIG;       /* RX Queue Count */
                        client_fifo_queue.txq_fifo = pCtrlCfgType->pEgressCfg->EthCtrlConfigEgressFifo;   /* TX Queue FIFO */
                        client_fifo_queue.rxq_fifo = pCtrlCfgType->pIngressCfg->EthCtrlConfigIngressFifo; /* RX Queue FIFO */
                        /*  Connect to HIF */
                        prPfeDev->prClient = pfe_hif_drv_client_register(
                                                                        prPfeDev->prHifDrv, /* HIF Driver instance */
                                                                        pfe_phy_if_get_id(prPfeDev->prPhyIf),/* Physical interface */
                                                                        &client_queue,       /* TX/RX Queue Count */
                                                                        &client_fifo_queue,  /* TX/RX Queue FIFO */
                                                                        ETH_43_PFE_CFG_ACCEPTALLTRAFFIC(u8CtrlIdx),
                                                                        &ClientEventHdlr,   /* Client's event handler */
                                                                        (void *)prPfeDev    /* Meta data */
                                                                        );
                        if(NULL_PTR == prPfeDev->prClient)
                        {
                            bResult = FALSE;
                        }
                        else if (EOK != pfe_hif_drv_client_set_inject_if(prPfeDev->prClient,
                                                                    pfe_phy_if_get_id(prPfeDev->prPhyIf)))
                        {
                            NXP_LOG_ERROR("Can't set inject interface\n");
                            bResult = FALSE;
                        }
#ifndef PFE_CFG_MULTI_INSTANCE_SUPPORT
                        else if (EOK != pfe_hif_drv_start(prPfeDev->prHifDrv))
                        {
                            NXP_LOG_ERROR("HIF driver start failed\n");
                            bResult = FALSE;
                        }
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */
#ifndef PFE_CFG_HIF_NOCPY_SUPPORT
                        else if (EOK != InitializeTxHeaders(u8CtrlIdx, prPfeDev->prClient))
                        {
                            NXP_LOG_ERROR("Initialize TX headers failed\n");
                            bResult = FALSE;
                        }
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
                        else if (IF_TYPE_HIF == prPfeDev->ifType)
                        {
                            prPfeDev->bStarted = TRUE;
                            NXP_LOG_INFO("Controller %hhu was started\n", u8CtrlIdx);
                        }
                        else
                        {
                            /*  Enable Rx on associated EMAC */
                            if (EOK != pfe_log_if_enable(prPfeDev->prLogIf))
                            {
                                bResult = FALSE;
                            }
                            else
                            {
                                prPfeDev->bStarted = TRUE;
                                NXP_LOG_INFO("Controller %hhu was started\n", u8CtrlIdx);
                            }
                        }
                    } /* end of (IF_TYPE_AUX == prPfeDev->ifType) */
                } /* end of (TRUE == bResult) */
            } /* end of (TRUE == bResult) */
        } /* end of (FALSE == prPfeDev->bStarted) */
    } /* end of (TRUE == bResult) */
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

    if(NULL_PTR != prPfeDev->prLogIf)
    {
        if(EOK != pfe_log_if_disable(prPfeDev->prLogIf))
        {
            NXP_LOG_ERROR("Unable to disable logical interface\n"); /* FIXME report to DEM */
            RetVal = E_NOT_OK;
        }
    }
    if(NULL_PTR != prPfeDev->prClient)
    {
#if (FALSE == PFE_CFG_HIF_IRQ_ENABLED)
        /* Do Rx job in polling mode */
        pfe_hif_drv_rx_job((void *)prPfeDev->prHifDrv);
#endif /* PFE_CFG_HIF_IRQ_ENABLED */
        pfe_hif_drv_client_unregister(prPfeDev->prClient);
        prPfeDev->prClient = NULL_PTR;
    }

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
    trPfeDev *prPfeDev = &(arPfeInterface[u8CtrlIdx]);


    if((prPfeDev->au8MacAddr[0] == pPhysAddrPtr[0]) && (prPfeDev->au8MacAddr[1] == pPhysAddrPtr[1])
    && (prPfeDev->au8MacAddr[2] == pPhysAddrPtr[2]) && (prPfeDev->au8MacAddr[3] == pPhysAddrPtr[3])
    && (prPfeDev->au8MacAddr[4] == pPhysAddrPtr[4]) && (prPfeDev->au8MacAddr[5] == pPhysAddrPtr[5]))
    {
        /* If the new MAC address is the same as already set in PFE platform, no need to do anything */
        bReturnStatus = TRUE;
    }
    else
    {
        if((IF_TYPE_AUX == prPfeDev->ifType)
            || (IF_TYPE_HIF == prPfeDev->ifType))
        {
            /* Just update in driver */
            (void)autolibc_memcpy(prPfeDev->au8MacAddr, pPhysAddrPtr, 6U);
            bReturnStatus = TRUE;
        }
        else
        {
            /* First, delete previous MAC address from PFE platform */
            /* Note: the function Eth_43_PFE_Init should have always set a MAC address if it succeeded */
            if(EOK == pfe_log_if_del_mac_addr(prPfeDev->prLogIf, prPfeDev->au8MacAddr, rPlatformCfg.local_hif))
            {
                /* Then, add the new MAC address to the PFE platform */
                if(EOK == pfe_log_if_add_mac_addr(prPfeDev->prLogIf, pPhysAddrPtr, rPlatformCfg.local_hif))
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
/**
* @brief         Adds or removes the specified PhysAddrPtr address to or from
*                a multicast address pool in the controller specified by CtrlIdx.
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
    Std_ReturnType u8ReturnStatus = (Std_ReturnType)E_NOT_OK;
    trPfeDev *prPfeDev = &(arPfeInterface[u8CtrlIdx]);
#ifdef PFE_CFG_PFE_SLAVE
    pfe_log_if_t *prLogIfSlave = NULL_PTR;
    pfe_ct_if_m_args_t rMatchArguments; /* BIG endian here */
    pfe_ct_if_m_rules_t MatchRules = IF_MATCH_NONE;
    pfe_phy_if_t *prHif = NULL_PTR;
    char_t sNameBuf[16];
#endif /* PFE_CFG_PFE_SLAVE */

    if (IF_TYPE_AUX == prPfeDev->ifType)
    {
        NXP_LOG_WARNING("AUX interface is not supported\n");
        u8ReturnStatus = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        if (IF_TYPE_HIF == prPfeDev->ifType)
        {
            NXP_LOG_WARNING("HIF interface is not supported\n");
            u8ReturnStatus = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            if (pfe_emac_is_broad(PhysAddrPtr))
            {
                /* Completely opens the physical address filter. */
                if (ETH_ADD_TO_FILTER == Action)
                {
                    /* Enable ALLMULTI mode. */
                    if (EOK != pfe_log_if_allmulti_enable(prPfeDev->prLogIf))
                    {
                        NXP_LOG_ERROR("Failed to enable ALLMULTI mode\n");
                    }
                    else
                    {
#ifdef PFE_CFG_PFE_MASTER
                        u8ReturnStatus = (Std_ReturnType)E_OK;
#else
                        /* Add rule for matching multicast packets */
                        MatchRules = IF_MATCH_TYPE_MCAST;
                        if (EOK != pfe_log_if_add_match_rule(prPfeDev->prLogIf, MatchRules, &rMatchArguments, 0UL))
                        {
                            NXP_LOG_ERROR("Failed to add match rule (IF_MATCH_TYPE_MCAST)\n");
                        }
                        else
                        {
                            u8ReturnStatus = (Std_ReturnType)E_OK;
                        }
#endif
                    }
                }
                else /* Don't allow pass all multicast addresses. */
                {
                    /* Disable ALLMULTI mode. */
                    if (EOK != pfe_log_if_allmulti_disable(prPfeDev->prLogIf))
                    {
                        NXP_LOG_ERROR("Failed to disable ALLMULTI mode\n");
                    }
                    else
                    {
#ifdef PFE_CFG_PFE_MASTER
                        u8ReturnStatus = (Std_ReturnType)E_OK;
#else
                        /* Delete match rule (matching multicast packets) */
                        MatchRules = IF_MATCH_TYPE_MCAST;
                        if (EOK != pfe_log_if_del_match_rule(prPfeDev->prLogIf, MatchRules))
                        {
                            NXP_LOG_ERROR("Failed to delete match rule (IF_MATCH_TYPE_MCAST)\n");
                        }
                        else
                        {
                            u8ReturnStatus = (Std_ReturnType)E_OK;
                        }
#endif
                    }
                }
            }
            else if (pfe_emac_is_zero(PhysAddrPtr))
            {
                /* Completely closes the physical address filter. */
                if (ETH_ADD_TO_FILTER == Action)
                {
                    if (EOK != pfe_log_if_allmulti_disable(prPfeDev->prLogIf))
                    {
                        NXP_LOG_ERROR("Failed to disable ALLMULTI mode\n");
                    }
                    else if (EOK != pfe_log_if_flush_mac_addrs(prPfeDev->prLogIf, MAC_DB_CRIT_BY_OWNER_AND_TYPE, PFE_TYPE_MC, rPlatformCfg.local_hif))
                    {
                        NXP_LOG_ERROR("Failed to remove all multicast addresses associated with current log_if\n");
                    }
                    else
                    {
#ifdef PFE_CFG_PFE_MASTER
                        u8ReturnStatus = (Std_ReturnType)E_OK;
#else
                        /* Delete match rule that matches all multicast packets on the 1st logical interface (slave)
                        And delete all logical interfaces with multicast address */
                        MatchRules = IF_MATCH_TYPE_MCAST;
                        if (EOK != pfe_log_if_del_match_rule(prPfeDev->prLogIf, MatchRules))
                        {
                            NXP_LOG_ERROR("Failed to delete match rule that matches all multicast packets\n");
                        }
                        else if (E_OK != delete_all_log_if_multicast(prPfeDev->prPlatform, rPlatformCfg.local_hif, pfe_phy_if_get_id(prPfeDev->prPhyIf)))
                        {
                            NXP_LOG_ERROR("Failed to delete all logical interface with multicast address\n");
                        }
                        else
                        {
                            u8ReturnStatus = (Std_ReturnType)E_OK;
                        }
#endif
                    }
                }
                else
                {
                    /* Do nothing */
                }
            }
            else if (pfe_emac_is_multi(PhysAddrPtr))
            {
                /* Adds a destination address to the physical address filter. */
                if (ETH_ADD_TO_FILTER == Action)
                {
#ifdef PFE_CFG_PFE_MASTER
                    /* Add new MAC address */
                    if (EOK != pfe_log_if_add_mac_addr(prPfeDev->prLogIf, PhysAddrPtr, rPlatformCfg.local_hif))
                    {
                        NXP_LOG_ERROR("Failed to add new MAC address\n");
                    }
                    else
                    {
                        u8ReturnStatus = (Std_ReturnType)E_OK;
                    }
#else
                    /* Check if the logical interface instance corresponding to mac address exists */
                    prLogIfSlave = get_log_if_by_mac_addr(prPfeDev->prPlatform, rPlatformCfg.local_hif, pfe_phy_if_get_id(prPfeDev->prPhyIf), PhysAddrPtr);
                    if (NULL_PTR == prLogIfSlave) /* The logical interface instance corresponding to mac address does not exist yet */
                    {
                        /* Get the physical interface for our HIF channel */
                        prHif = pfe_platform_get_phy_if_by_id(prPfeDev->prPlatform, prPfeDev->HifId);
                        if (NULL_PTR == prHif)
                        {
                            NXP_LOG_ERROR("Can't get physical interface for the HIF\n");
                            return u8ReturnStatus;
                        }
                        /* Generate the name for the logical interface, it would be 'u8CtrlIdx.u32CntName' */
                        sNameBuf[0U] = (char_t)u8CtrlIdx + 0x30U;
                        sNameBuf[1U] = '.';
                        sNameBuf[2U] = (char_t)u32CntName[u8CtrlIdx] + 0x30U;
                        sNameBuf[3U] = '\0';
                        u32CntName[u8CtrlIdx]++;
                        /* Create a logical interface that will be used to dispatch packets from the EMAC */
                        prLogIfSlave = pfe_log_if_create(prPfeDev->prPhyIf, sNameBuf);
                        if (NULL_PTR == prLogIfSlave)
                        {
                            NXP_LOG_ERROR("Could not create logical interface\n");
                        }
                        else
                        {
                            (void)autolibc_memcpy(rMatchArguments.dmac, PhysAddrPtr, 6U);
                            MatchRules = IF_MATCH_DMAC;
                            if (E_OK != pfe_log_if_set_match_rules(prLogIfSlave, MatchRules, &rMatchArguments))
                            {
                                NXP_LOG_ERROR("Failed to set match rule (MAC address)\n");
                            }
                            else if (E_OK != pfe_log_if_set_match_or(prLogIfSlave))
                            {
                                NXP_LOG_ERROR("Failed to set match OR\n");
                            }
                            else if (EOK != pfe_log_if_add_egress_if(prLogIfSlave, prHif))
                            {
                                NXP_LOG_ERROR("Can't add egress interface (%s)\n", pfe_log_if_get_name(prLogIfSlave));
                            }
                            else if (EOK != pfe_platform_register_log_if(prPfeDev->prPlatform, prLogIfSlave))
                            {
                                NXP_LOG_ERROR("Could not register logical interface\n");
                            }
                            else if (EOK != pfe_log_if_add_mac_addr(prLogIfSlave, PhysAddrPtr, rPlatformCfg.local_hif))
                            {
                                NXP_LOG_ERROR("Can't configure MAC address on associated EMAC\n");
                            }
                            else if (EOK != pfe_log_if_enable(prLogIfSlave))
                            {
                                NXP_LOG_ERROR("Failed to enable the logical interface\n");
                            }
                            else
                            {
                                u8ReturnStatus = (Std_ReturnType)E_OK;
                            }
                            /* Delete previously created log_if in case its configuration failed */
                            if ((Std_ReturnType)E_OK != u8ReturnStatus)
                            {
                                pfe_log_if_destroy(prLogIfSlave);
                            }
                        }
                    }
                    else
                    {
                        NXP_LOG_ERROR("Logical interface corresponding to mac address already exists\n");
                    }
#endif
                }
                else  /* Removes a destination address from the physical address filter. */
                {
#ifdef PFE_CFG_PFE_MASTER
                    /* Delete MAC address */
                    if (EOK != pfe_log_if_del_mac_addr(prPfeDev->prLogIf, PhysAddrPtr, rPlatformCfg.local_hif))
                    {
                        NXP_LOG_ERROR("Failed to delete MAC address\n");
                    }
                    else
                    {
                        u8ReturnStatus = (Std_ReturnType)E_OK;
                    }
#else
                    /* Check if the logical interface instance corresponding to mac address exists */
                    prLogIfSlave = get_log_if_by_mac_addr(prPfeDev->prPlatform, rPlatformCfg.local_hif, pfe_phy_if_get_id(prPfeDev->prPhyIf), PhysAddrPtr);
                    if (NULL_PTR != prLogIfSlave) /* Logical interface instance corresponding to mac address already exists */
                    {
                        /* Unregister logical interface */
                        if (EOK != pfe_platform_unregister_log_if(prPfeDev->prPlatform, prLogIfSlave))
                        {
                            NXP_LOG_ERROR("Could not unregister logical interface\n");
                        }
                        else if (EOK != pfe_log_if_del_mac_addr(prLogIfSlave, PhysAddrPtr, rPlatformCfg.local_hif)) /* Delete MAC address */
                        {
                            NXP_LOG_ERROR("Failed to delete MAC address\n");
                        }
                        else
                        {
                            /* Destroy interface instance */
                            pfe_log_if_destroy(prLogIfSlave);
                            u8ReturnStatus = (Std_ReturnType)E_OK;
                        }
                    }
                    else
                    {
                        NXP_LOG_ERROR("Logical interface instance corresponding to mac address does not exist\n");
                        u8ReturnStatus = (Std_ReturnType)E_NOT_OK;
                    }
#endif
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
    addr_t BufAddr = NULL_ADDR;
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

    s32BufLen = (sint32)Eth_43_PFE_LLD_GetTxBufferSize(u8CtrlIdx, u8QueuIdx)
              - (sint32)TX_BUF_FRAME_OFFSET - (sint32)lmem_header_size - (sint32)PFE_LLD_L2_HEADER_SIZE;
    if((sint32)(*pLength) <= s32BufLen)
    {
        if(TRUE == GetTxBuffer(u8CtrlIdx, u8QueuIdx, &BufIdx))
        {
            BufAddr = GetTxBufAddr(u8CtrlIdx, BufIdx);
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
            /* Initialize Tx header after the tx buffer has been assigned by BMU */
            u8Queue = GetTxBufFifoIndex(u8CtrlIdx, BufIdx);
            pTxHeader = (pfe_ct_hif_tx_hdr_t *)(BufAddr + lmem_header_size + 256U);
            ret = pfe_hif_drv_init_tx_header(prPfeDev->prClient, pTxHeader, u8Queue);
            if (EOK != ret)
            {
                 NXP_LOG_ERROR("Failed to initialize tx header when using HIF_NOCPY\n");
            }
#endif
            *pData = (uint8 *)(BufAddr + TX_BUF_FRAME_OFFSET + lmem_header_size + PFE_LLD_L2_HEADER_SIZE);
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
    const uint8 status = GetTxBufStatus(u8CtrlIdx, BufIdx);

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
    trPfeDev *prPfeDev = &arPfeInterface[u8CtrlIdx];
    const uint8 *apu8MacAddr = prPfeDev->au8MacAddr;
    trTxMeta *prTxMeta = Eth_PFE_LLD_GetTxBufMeta(u8CtrlIdx, BufIdx);
    uint8 u8FifoIdx = Eth_43_PFE_LLD_GetTxFifoIdx(u8CtrlIdx, BufIdx);
    addr_t BufAddr = GetTxBufAddr(u8CtrlIdx, BufIdx);
    void *pvDataVA = (void *)BufAddr;
    uint32 Length;
    errno_t Status = EOK;
    Std_ReturnType RetVal = E_OK;
    void *pvRefPtr;
    uint8 u8NewBufStatus = TX_BUF_WAIT_CONF | TX_BUF_TO_REPORT;

#if (STD_ON == ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API)
    Std_ReturnType u8FunctionSuccess = (Std_ReturnType)E_NOT_OK;
    uint8* dataPtr;
#endif /* ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API */
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
    uint16 lmem_header_size = pfe_hif_chnl_get_lmem_hdr_size(arPfeInterface[u8CtrlIdx].prHifChnl);
#else
    uint16 lmem_header_size = 0U;
#endif

    if (TX_BUF_PROVIDED != GetTxBufStatus(u8CtrlIdx, BufIdx))
    {
        NXP_LOG_ERROR("Attempted to transmit buffer with wrong status\n");
        if(TRUE == bConfirm)
        {
            EthIf_TxConfirmation(ETH_43_PFE_CFG_CTRLIDXINETHIF(u8CtrlIdx), BufIdx, E_NOT_OK);
        }
        RetVal = E_NOT_OK;
    }
    else
    {
        /*  Update TX metadata */
        prTxMeta->bDoTxIndication = bConfirm;
        prTxMeta->bDoTS = prTxMeta->bDoTS && bConfirm; /* No way to report timestamp without confirnation enabled */

        /*  Fill in Ethernet header */
        *(uint16 *)(BufAddr + TX_BUF_FRAME_OFFSET + lmem_header_size + 0U) = *(uint16 *)(pDest + 0U);
        *(uint16 *)(BufAddr + TX_BUF_FRAME_OFFSET + lmem_header_size + 2U) = *(uint16 *)(pDest + 2U);
        *(uint16 *)(BufAddr + TX_BUF_FRAME_OFFSET + lmem_header_size + 4U) = *(uint16 *)(pDest + 4U);
        *(uint16 *)(BufAddr + TX_BUF_FRAME_OFFSET + lmem_header_size + 6U) = *(uint16 *)(apu8MacAddr + 0U);
        *(uint16 *)(BufAddr + TX_BUF_FRAME_OFFSET + lmem_header_size + 8U) = *(uint16 *)(apu8MacAddr + 2U);
        *(uint16 *)(BufAddr + TX_BUF_FRAME_OFFSET + lmem_header_size + 10U)= *(uint16 *)(apu8MacAddr + 4U);
        *(uint16 *)(BufAddr + TX_BUF_FRAME_OFFSET + lmem_header_size + 12U)= cpu_to_be16(u16Type);

#if (STD_ON == ETH_43_PFE_GLOBALTIME_SUPPORT)
        aarTxBuf[u8CtrlIdx][BufIdx].TimeQual = ETH_INVALID;
        /*  Check TS request */
        if (TRUE == prTxMeta->bDoTS)
        {
            oal_mutex_lock(PFE_TS_QUEUE_WRITE_MUTEX);
            /* Add this buffer to TS queue (no need to check if queue is full, there is always enough space) */
            prPfeDev->TSQueue[u8FifoIdx][prPfeDev->u16TSQueueWrite[u8FifoIdx]] = BufIdx;
            prPfeDev->u16TSQueueWrite[u8FifoIdx]++;
            if(prPfeDev->u16TSQueueWrite[u8FifoIdx] >= ETH_43_PFE_MAX_FIFO_TX_BUF_CNT)
            {   /* Wrap */
                prPfeDev->u16TSQueueWrite[u8FifoIdx] = 0U;
            }
            oal_mutex_unlock(PFE_TS_QUEUE_WRITE_MUTEX);
            u8NewBufStatus |= TX_BUF_WAIT_TS;
        }
#endif /* ETH_43_PFE_GLOBALTIME_SUPPORT */

        Length = (uint32)u16Length + (uint32)PFE_LLD_L2_HEADER_SIZE;
#if (STD_ON == ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API)
        /* dataPtr points to position of EtherType in Ethernet frame */
        dataPtr = (uint8*)(BufAddr - 2U);
        u8FunctionSuccess = Eth_43_PFE_InternalCfgPtr->pController[u8CtrlIdx]->
        Eth_43_PFE_EthSwtDriverFunctionList.TxProcessFrameFunction
        (
            u8CtrlIdx, BufIdx, &dataPtr, (uint16*)&Length
        );
        if (E_OK == u8FunctionSuccess)
        {
            /* Finish to process frame */
            u8FunctionSuccess = Eth_43_PFE_InternalCfgPtr->pController[u8CtrlIdx]->
            Eth_43_PFE_EthSwtDriverFunctionList.TxFinishedIndicationFunction(u8CtrlIdx, BufIdx);
        }
        if (E_OK == u8FunctionSuccess)
#endif /* ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API*/
        {
            Length += (uint32)sizeof(pfe_ct_hif_tx_hdr_t);
            /* MUST update BufStatus before writing to TxReqQueue */
            SetTxBufStatus(u8CtrlIdx, BufIdx, u8NewBufStatus);
            pvRefPtr = TxReqQueueWrite(u8CtrlIdx, BufIdx);
            Status = pfe_hif_drv_client_xmit_pkt( prPfeDev->prClient, u8FifoIdx, pvDataVA, \
                                                pvDataVA, Length, pvRefPtr \
                                                );
        }
        if(EOK != Status)
        {
            NXP_LOG_ERROR("Transmission has failed (%d)\n", Status);
            RetVal = E_NOT_OK;
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
            /* Free the buffer */
            (void)pfe_hif_chnl_bmu_free_buf(arPfeInterface[u8CtrlIdx].prHifChnl, BufAddr);
#endif
#if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
            /* Report the failure. There will be no interrupt generated, so it is reported here. */
            if(TRUE == prTxMeta->bDoTxIndication)
            {
                /*    Disable HIF channel interrupts */
                pfe_hif_chnl_irq_mask(arPfeInterface[u8CtrlIdx].prHifChnl);
                EthIf_TxConfirmation(ETH_43_PFE_CFG_CTRLIDXINETHIF(u8CtrlIdx), BufIdx, E_NOT_OK);
                /*    Re-enable HIF channel IRQ */
                pfe_hif_chnl_irq_unmask(arPfeInterface[u8CtrlIdx].prHifChnl);
            }
            SetTxBufStatus(u8CtrlIdx, BufIdx, TX_BUF_FREE);
#else
            /* Failure will be reported when polling function is called */
            SetTxBufStatus(u8CtrlIdx, BufIdx, TX_BUF_FAILED);
#endif /* interrupt_enabled */
        }
    }
    return RetVal;
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
Eth_RxStatusType Eth_PFE_LLD_ReportReception( \
                                            const uint8 u8CtrlIdx, \
                                            uint8 u8FifoIdx,  \
                                            const boolean bIrq \
                                                        )
{
    Eth_RxStatusType RetVal = ETH_NOT_RECEIVED;
    addr_t DataAddr;
    uint32 u32DataLen;
    Eth_DataType * pPayloadPtr;
    Eth_FrameType FrameType; /* EtherType */
    Eth_FrameType EtherType; /* EtherType */
    uint8 Protocol = 0; /* Protocol */
    uint8 BypassVLANTag = 0; /* BypassVLANTag */
    boolean IsBroadcast;
    uint8 * SrcAddrPtr; /* Pointer to source address */
    const pfe_hif_pkt_t *RxPacket;
    pfe_hif_drv_client_t *prClient = arPfeInterface[u8CtrlIdx].prClient;
    boolean IsMgmtFrameOnlyPtr = FALSE;
    uint16 FrameLength = 0;
#if (STD_ON == ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API)
    Eth_BufIdxType BufIdx = 0;
    uint8*  DataPtr;
#endif /* ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API */

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
            if(TRUE == pfe_hif_pkt_is_last(RxPacket))
            {   /* Parse Ethernet frame and determine frame type */
                DataAddr = pfe_hif_pkt_get_data(RxPacket) + HIF_HEADER_SIZE;
                FrameType = be16_to_cpu(*(Eth_FrameType *)(DataAddr + 12U));
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
                EtherType = be16_to_cpu(*(Eth_FrameType *)(DataAddr + 12U + BypassVLANTag));

                /* Check if received frame is IPv4 */
                if (EtherType == 0x0800U)
                {
#if (STD_ON == ETH_43_PFE_ENABLE_OFFLOAD_CSUM_IPV4)
                    /* Check if IPv4 checksum has been verified and is valid */
                    if (pfe_hif_pkt_ipv4_csum_valid(RxPacket) == FALSE)
                    {   /* Checksum mismatch, shall be discarded */
                        abRxToDiscard[u8CtrlIdx][u8FifoIdx] = TRUE;
                    }
#endif /* ETH_43_PFE_ENABLE_OFFLOAD_CSUM_IPV4 */
                    /* Check for Protocol */
                    Protocol = (*(uint8 *)(DataAddr + 23U + BypassVLANTag)) & (uint8)0xFF;
#if (STD_ON == ETH_43_PFE_ENABLE_OFFLOAD_CSUM_UDP)
                    /* Check if L4 Protocol of received frame is UDP */
                    if(Protocol == 0x11U)
                    {   /* Check if UDP checksum has been verified and is valid */
                        if (pfe_hif_pkt_udpv4_csum_valid(RxPacket) == FALSE)
                        {   /* Checksum mismatch, shall be discarded */
                            abRxToDiscard[u8CtrlIdx][u8FifoIdx] = TRUE;
                        }
                    }
#endif /* ETH_43_PFE_ENABLE_OFFLOAD_CSUM_UDP */
#if (STD_ON == ETH_43_PFE_ENABLE_OFFLOAD_CSUM_TCP)
                    /* Check if L4 Protocol of received frame is TCP */
                    if(Protocol == 0x06U)
                    {   /* Check if TCP checksum has been verified and is valid */
                        if (pfe_hif_pkt_tcpv4_csum_valid(RxPacket) == FALSE)
                        {   /* Checksum mismatch, shall be discarded */
                            abRxToDiscard[u8CtrlIdx][u8FifoIdx] = TRUE;
                        }
                    }
#endif /* ETH_43_PFE_ENABLE_OFFLOAD_CSUM_TCP */
#if (STD_ON == ETH_43_PFE_ENABLE_OFFLOAD_CSUM_ICMP)
                    if(Protocol == 0x01U)
                    {   /* Check if ICMP checksum has been verified and is valid */
                        if (pfe_hif_pkt_icmp_csum_valid(RxPacket) == FALSE)
                        {   /* Checksum mismatch, shall be discarded */
                            abRxToDiscard[u8CtrlIdx][u8FifoIdx] = TRUE;
                        }
                    }
#endif /* ETH_43_PFE_ENABLE_OFFLOAD_CSUM_ICMP */
                }
                /* Check if received frame is IPv6 */
                else if (EtherType == 0x86DDU)
                {   /* Check for Next Header */
                    Protocol = (*(uint8 *)(DataAddr + 20U + BypassVLANTag)) & (uint8)0xFF;
#if (STD_ON == ETH_43_PFE_ENABLE_OFFLOAD_CSUM_UDP)
                    /* Check if L4 Protocol of received frame is UDP */
                    if(Protocol == 0x11U)
                    {   /* Check if UDP checksum has been verified and is valid */
                        if (pfe_hif_pkt_udpv6_csum_valid(RxPacket) == FALSE)
                        {   /* Checksum mismatch, shall be discarded */
                            abRxToDiscard[u8CtrlIdx][u8FifoIdx] = TRUE;
                        }
                    }
#endif /* ETH_43_PFE_ENABLE_OFFLOAD_CSUM_UDP */
#if (STD_ON == ETH_43_PFE_ENABLE_OFFLOAD_CSUM_TCP)
                    if(Protocol == 0x06U)
                    {   /* Check if TCP checksum has been verified and is valid */
                        if (pfe_hif_pkt_tcpv6_csum_valid(RxPacket) == FALSE)
                        {   /* Checksum mismatch, shall be discarded */
                            abRxToDiscard[u8CtrlIdx][u8FifoIdx] = TRUE;
                        }
                    }
#endif /* ETH_43_PFE_ENABLE_OFFLOAD_CSUM_TCP */
#if (STD_ON == ETH_43_PFE_ENABLE_OFFLOAD_CSUM_ICMP)
                    if(Protocol == 0x3AU)
                    {   /* Check if ICMP checksum has been verified and is valid */
                        if (pfe_hif_pkt_icmp_csum_valid(RxPacket) == FALSE)
                        {   /* Checksum mismatch, shall be discarded */
                            abRxToDiscard[u8CtrlIdx][u8FifoIdx] = TRUE;
                        }
                    }
#endif /* ETH_43_PFE_ENABLE_OFFLOAD_CSUM_ICMP */
                }
                /* to fix misra violation */
                else
                {
                    ; /* No action required */
                }
#if ((STD_OFF == ETH_43_PFE_ENABLE_OFFLOAD_CSUM_TCP) && (STD_OFF == ETH_43_PFE_ENABLE_OFFLOAD_CSUM_UDP) && (STD_OFF == ETH_43_PFE_ENABLE_OFFLOAD_CSUM_ICMP))
                (void)Protocol;
#endif
                /* Whole packet successfully received */
                if(FALSE == abRxToDiscard[u8CtrlIdx][u8FifoIdx])
                {
                    /* Get whole Ethernet frame without HIF header */
                    FrameLength = (uint16)pfe_hif_pkt_get_data_len(RxPacket) - HIF_HEADER_SIZE;

                    /* Check if received frame is jumbo frame */
                    if(FrameLength > (PFE_INGRESS_MAX_FRAME_SIZE + BypassVLANTag))
                    {
                        FrameLength = PFE_INGRESS_MAX_FRAME_SIZE + BypassVLANTag;
                    }

#if (STD_ON == ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API)
                    DataPtr = (uint8*)(DataAddr + 12U + BypassVLANTag);
                    (void)Eth_43_PFE_InternalCfgPtr->pController[u8CtrlIdx]->
                    Eth_43_PFE_EthSwtDriverFunctionList.RxProcessFrameFunction( u8CtrlIdx, \
                                                    BufIdx, \
                                                    &DataPtr,\
                                                    &FrameLength, \
                                                    &IsMgmtFrameOnlyPtr\
                                                   );
#endif /* ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API */
                    /* Parse Ethernet header */
                    IsBroadcast = ( (0xFFFFFFFFU == *(uint32*)(DataAddr     )) \
                                && (0xFFFFU     == *(uint16*)(DataAddr + 4U)) \
                                );
                    SrcAddrPtr = (uint8 *)(DataAddr + 6U);
                    /* Get payload - strip Ethernet header and CRC */
                    pPayloadPtr = (Eth_DataType *)(DataAddr + PFE_LLD_L2_HEADER_SIZE);
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
                else
                {   /* It was multi-buffer, shall be discarded */
                    abRxToDiscard[u8CtrlIdx][u8FifoIdx] = FALSE;
                }
            }
            else
            {
                abRxToDiscard[u8CtrlIdx][u8FifoIdx] = TRUE;
                NXP_LOG_ERROR("Multi-buffer frame detected, unsupported configuration, " \
                              "ctrl:%hhu, fifo:%hhu\n", u8CtrlIdx, u8FifoIdx \
                             );
            }
            pfe_hif_pkt_free(RxPacket);
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
            ClearTxBufStatusBits(u8CtrlIdx, BufIdx, TX_BUF_WAIT_CONF);
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
            u8BufStatus = GetTxBufStatus(u8CtrlIdx, BufIdx);
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
                    SetTxBufStatus(u8CtrlIdx, BufIdx, TX_BUF_FREE);
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
                arPfeInterface[u8CtrlIdx].TSQueue[u8FifoIdx][arPfeInterface[u8CtrlIdx].u16TSQueueRead[u8FifoIdx]] =
                                                                                                INVALID_TX_INDEX;
                arPfeInterface[u8CtrlIdx].u16TSQueueRead[u8FifoIdx]++;
                if(arPfeInterface[u8CtrlIdx].u16TSQueueRead[u8FifoIdx] >= ETH_43_PFE_MAX_FIFO_TX_BUF_CNT)
                {
                    arPfeInterface[u8CtrlIdx].u16TSQueueRead[u8FifoIdx] = 0U;
                }

                if(ENOENT == Error)
                {
                    NXP_LOG_WARNING("Requested egress timestamp was not provided on controller %hhu\n", u8CtrlIdx);
                }
                
                /* Check if we should also report the buffer here */
                u8BufStatus = GetTxBufStatus(u8CtrlIdx, BufIdx);
                if((TX_BUF_WAIT_TS | TX_BUF_TO_REPORT) == u8BufStatus)
                {
                    /* Yes, we were waiting only for the timestamp */
                    oal_mutex_lock(PFE_ETHIF_TXCONFIR_API_MUTEX_01);
                    EthIf_TxConfirmation(ETH_43_PFE_CFG_CTRLIDXINETHIF(u8CtrlIdx), BufIdx, E_OK);
                    oal_mutex_unlock(PFE_ETHIF_TXCONFIR_API_MUTEX_01);

                    /* Return buffer to pool */
                    SetTxBufStatus(u8CtrlIdx, BufIdx, TX_BUF_FREE);
                }
                else
                {
                    /* Otherwise it will be reported when we get Tx confirmation */
                    ClearTxBufStatusBits(u8CtrlIdx, BufIdx, TX_BUF_WAIT_TS);
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
/**
* @brief        Get errors from interrupt sources and report to Heath Monitor.
* @details      The function checks for errors by polling interrupt sources
*               and report to Health Monitor
* @return       N/A
*/
static void Eth_PFE_LLD_PollerFunction(void)
{
    /* Polling all interrupt sources and report errors to Health Monitor */
    uint32_t i;

    /* PFE ECC */
    if (NULL != ptrPlatform->ecc_err)
    {
        pfe_ecc_err_irq_mask(ptrPlatform->ecc_err);
        (void)pfe_ecc_err_isr(ptrPlatform->ecc_err);
        pfe_ecc_err_irq_unmask(ptrPlatform->ecc_err);
    }

    /* PFE Watchdog */
    if (NULL != ptrPlatform->wdt)
    {
        pfe_wdt_irq_mask(ptrPlatform->wdt);
        (void)pfe_wdt_isr(ptrPlatform->wdt);
        pfe_wdt_irq_unmask(ptrPlatform->wdt);
    }

    /* EMAC */
    for (i = 0; i < ptrPlatform->emac_count; i++)
    {
        if (NULL != ptrPlatform->emac[i])
        {
            pfe_emac_irq_mask(ptrPlatform->emac[i]);
            (void)pfe_emac_isr(ptrPlatform->emac[i]);
            pfe_emac_irq_unmask(ptrPlatform->emac[i]);
        }
    }

    /* Bus */
    if (NULL != ptrPlatform->bus_err)
    {
        pfe_bus_err_irq_mask(ptrPlatform->bus_err);
        (void)pfe_bus_err_isr(ptrPlatform->bus_err);
        pfe_bus_err_irq_unmask(ptrPlatform->bus_err);
    }

    /* Parity */
    if (NULL != ptrPlatform->parity)
    {
        pfe_parity_irq_mask(ptrPlatform->parity);
        (void)pfe_parity_isr(ptrPlatform->parity);
        pfe_parity_irq_unmask(ptrPlatform->parity);
    }

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

    /* BMU */
    for (i = 0; i < ptrPlatform->bmu_count; i++)
    {
        if (NULL != ptrPlatform->bmu[i])
        {
            pfe_bmu_irq_mask(ptrPlatform->bmu[i]);
            (void)pfe_bmu_isr(ptrPlatform->bmu[i]);
            pfe_bmu_irq_unmask(ptrPlatform->bmu[i]);
        }
    }

    /* Classifier */
    if (NULL != ptrPlatform->classifier)
    {
        pfe_class_irq_mask(ptrPlatform->classifier);
        (void)pfe_class_isr(ptrPlatform->classifier);
        pfe_class_irq_unmask(ptrPlatform->classifier);
    }

    /* UTIL */
    if (NULL != ptrPlatform->util)
    {
        pfe_util_irq_mask(ptrPlatform->util);
        (void)pfe_util_isr(ptrPlatform->util);
        pfe_util_irq_unmask(ptrPlatform->util);
    }

    /* HIF */
    if (NULL != ptrPlatform->hif)
    {
        pfe_hif_irq_mask(ptrPlatform->hif);
        (void)pfe_hif_isr(ptrPlatform->hif);
        pfe_hif_irq_unmask(ptrPlatform->hif);
    }
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
        u32RtrTimeoutTimeMs += ETH_43_PFE_CFG_MAIN_FCN_PERIOD_MS;
        if (u32RtrTimeoutTimeMs >= (PFE_RTABLE_CFG_TICK_PERIOD_SEC * 1000U))
        {
            pfe_rtable_do_timeouts(ptrPlatform->rtable);
            u32RtrTimeoutTimeMs -= PFE_RTABLE_CFG_TICK_PERIOD_SEC * 1000U;
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
            CheckDemStatus(u8CtrlIdx, ETH_43_PFE_CFG_DEM_E_FRAMELOST_ENABLED(u8CtrlIdx), ETH_43_PFE_E_RX_FRAMES_LOST, (Dem_EventIdType)ETH_43_PFE_CFG_DEM_E_FRAMELOST(u8CtrlIdx));
            CheckDemStatus(u8CtrlIdx, ETH_43_PFE_CFG_DEM_E_CRC_ENABLED(u8CtrlIdx), ETH_43_PFE_E_CRC, (Dem_EventIdType)ETH_43_PFE_CFG_DEM_E_CRC(u8CtrlIdx));
            CheckDemStatus(u8CtrlIdx, ETH_43_PFE_CFG_DEM_E_UNDERSIZE_ENABLED(u8CtrlIdx), ETH_43_PFE_E_UNDERSIZEFRAME, (Dem_EventIdType)ETH_43_PFE_CFG_DEM_E_UNDERSIZE(u8CtrlIdx));
            CheckDemStatus(u8CtrlIdx, ETH_43_PFE_CFG_DEM_E_OVERSIZE_ENABLED(u8CtrlIdx), ETH_43_PFE_E_OVERSIZEFRAME, (Dem_EventIdType)ETH_43_PFE_CFG_DEM_E_OVERSIZE(u8CtrlIdx));
            CheckDemStatus(u8CtrlIdx, ETH_43_PFE_CFG_DEM_E_ALIGN_ENABLED(u8CtrlIdx), ETH_43_PFE_E_ALIGNMENT, (Dem_EventIdType)ETH_43_PFE_CFG_DEM_E_ALIGN(u8CtrlIdx));
            CheckDemStatus(u8CtrlIdx, ETH_43_PFE_CFG_DEM_E_1COL_ENABLED(u8CtrlIdx), ETH_43_PFE_E_SINGLECOLLISION, (Dem_EventIdType)ETH_43_PFE_CFG_DEM_E_1COL(u8CtrlIdx));
            CheckDemStatus(u8CtrlIdx, ETH_43_PFE_CFG_DEM_E_MCOL_ENABLED(u8CtrlIdx), ETH_43_PFE_E_MULTIPLECOLLISION, (Dem_EventIdType)ETH_43_PFE_CFG_DEM_E_MCOL(u8CtrlIdx));
            CheckDemStatus(u8CtrlIdx, ETH_43_PFE_CFG_DEM_E_LCOL_ENABLED(u8CtrlIdx), ETH_43_PFE_E_LATECOLLISION, (Dem_EventIdType)ETH_43_PFE_CFG_DEM_E_LCOL(u8CtrlIdx));
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
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    const trPfeDev *prPfeDev;
    pfe_emac_t *prEmac = NULL_PTR;
    uint32 u32Key = 0U;
    pfe_ct_phy_if_id_t emac_id;

    prPfeDev = &arPfeInterface[u8CtrlIdx];

    if (IF_TYPE_EMAC == prPfeDev->ifType)
    {
        if ((Std_ReturnType)E_OK != GetPhyIfIdByCtrlHwPort(u8CtrlIdx, &emac_id))
        {
            NXP_LOG_ERROR("Could not get PHY IF ID for controller %u\n", (uint_t)u8CtrlIdx);
        }
        else
        {
            prEmac = ptrPlatform->emac[emac_id];
        }

        if (NULL_PTR == prEmac)
        {
            NXP_LOG_ERROR("EMAC instance not found\n");
        }
        else

        {
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
                RetVal = (Std_ReturnType)E_OK;
            }
#ifdef PFE_CFG_PFE_MASTER
            /* Unlock the locked MDIO bus */
            if (EOK != pfe_emac_mdio_unlock(prEmac, u32Key))
            {
                NXP_LOG_ERROR("Unlock the locked MDIO bus failed\n");
            }
#endif /* PFE_CFG_PFE_MASTER */
        }
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
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    const trPfeDev *prPfeDev;
    pfe_emac_t *prEmac = NULL_PTR;
    uint32 u32Key = 0U;
    pfe_ct_phy_if_id_t emac_id;

    prPfeDev = &arPfeInterface[u8CtrlIdx];

    if (IF_TYPE_EMAC == prPfeDev->ifType)
    {
        if ((Std_ReturnType)E_OK != GetPhyIfIdByCtrlHwPort(u8CtrlIdx, &emac_id))
        {
            NXP_LOG_ERROR("Could not get PHY IF ID for controller %u\n", (uint_t)u8CtrlIdx);
        }
        else
        {
            prEmac = ptrPlatform->emac[emac_id];
        }

        if(NULL_PTR == prEmac)
        {
            NXP_LOG_ERROR("EMAC instance not found\n");
        }
        else
        {
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
                RetVal = (Std_ReturnType)E_OK;
            }
#ifdef PFE_CFG_PFE_MASTER
            /* Unlock the locked MDIO bus */
            if (EOK != pfe_emac_mdio_unlock(prEmac, u32Key))
            {
                NXP_LOG_ERROR("Unlock the locked MDIO bus failed\n");
            }
#endif /* PFE_CFG_PFE_MASTER */
        }
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
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    const trPfeDev *prPfeDev;
    pfe_emac_t *prEmac = NULL_PTR;
    uint32 u32Key = 0U;
    pfe_ct_phy_if_id_t emac_id;

    prPfeDev = &arPfeInterface[u8CtrlIdx];

    if (IF_TYPE_EMAC == prPfeDev->ifType)
    {
        if ((Std_ReturnType)E_OK != GetPhyIfIdByCtrlHwPort(u8CtrlIdx, &emac_id))
        {
            NXP_LOG_ERROR("Could not get PHY IF ID for controller %u\n", (uint_t)u8CtrlIdx);
        }
        else
        {
            prEmac = ptrPlatform->emac[emac_id];
        }

        if(NULL_PTR == prEmac)
        {
            NXP_LOG_ERROR("EMAC instance not found\n");
        }
        else
        {
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
                RetVal = (Std_ReturnType)E_OK;
            }
#ifdef PFE_CFG_PFE_MASTER
            /* Unlock the locked MDIO bus */
            if (EOK != pfe_emac_mdio_unlock(prEmac, u32Key))
            {
                NXP_LOG_ERROR("Unlock the locked MDIO bus failed\n");
            }
#endif /* PFE_CFG_PFE_MASTER */
        }
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
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    const trPfeDev *prPfeDev;
    pfe_emac_t *prEmac = NULL_PTR;
    uint32 u32Key = 0U;
    pfe_ct_phy_if_id_t emac_id;

    prPfeDev = &arPfeInterface[u8CtrlIdx];

    if (IF_TYPE_EMAC == prPfeDev->ifType)
    {
        if ((Std_ReturnType)E_OK != GetPhyIfIdByCtrlHwPort(u8CtrlIdx, &emac_id))
        {
            NXP_LOG_ERROR("Could not get PHY IF ID for controller %u\n", (uint_t)u8CtrlIdx);
        }
        else
        {
            prEmac = ptrPlatform->emac[emac_id];
        }

        if(NULL_PTR == prEmac)
        {
            NXP_LOG_ERROR("EMAC instance not found\n");
        }
        else
        {
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
                RetVal = (Std_ReturnType)E_OK;
            }
#ifdef PFE_CFG_PFE_MASTER
            /* Unlock the locked MDIO bus */
            if (EOK != pfe_emac_mdio_unlock(prEmac, u32Key))
            {
                NXP_LOG_ERROR("Unlock the locked MDIO bus failed\n");
            }
#endif /* PFE_CFG_PFE_MASTER */
        }
    }

    return RetVal;
}
#endif /* STD_ON == ETH_43_PFE_CTRL_USE_45_MDIO_API*/
#endif /* STD_OFF == ETH_43_PFE_CTRLENABLE_MII */

#if STD_ON == ETH_43_PFE_GLOBALTIME_SUPPORT
Std_ReturnType Eth_43_PFE_LLD_SetGlobalTime(uint8 CtrlIdx, const Eth_TimeStampType *pTimeStampPtr)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    pfe_emac_t *prEmac = NULL_PTR;
    pfe_ct_phy_if_id_t emac_id;
    const trPfeDev *prPfeDev;

    prPfeDev = &arPfeInterface[CtrlIdx];

    if (IF_TYPE_EMAC == prPfeDev->ifType)
    {
        if ((Std_ReturnType)E_OK != GetPhyIfIdByCtrlHwPort(CtrlIdx, &emac_id))
        {
            NXP_LOG_ERROR("Could not get PHY IF ID for controller %u\n", (uint_t)CtrlIdx);
        }
        else
        {
            prEmac = ptrPlatform->emac[emac_id];
        }

        if (NULL_PTR != prEmac)
        {
            if (EOK == pfe_emac_set_ts_time(prEmac, pTimeStampPtr->seconds, pTimeStampPtr->nanoseconds, pTimeStampPtr->secondsHi))
            {
#ifdef PFE_CFG_EMAC0_PPS0_ENABLE
                if(PFE_PHY_IF_ID_EMAC0 == emac_id) {
                    pfe_emac_pps0_resync(prEmac);
                }
#endif
                RetVal = (Std_ReturnType)E_OK;
            }
        }
    }

    return RetVal;
}

void Eth_43_PFE_LLD_GetCurrentTime  (   uint8 CtrlIdx, \
                                        Eth_TimeStampQualType *timeQualPtr, \
                                        Eth_TimeStampType *timeStampPtr \
                                    )
{
    pfe_emac_t *prEmac = NULL_PTR;
    pfe_ct_phy_if_id_t emac_id;
    const trPfeDev *prPfeDev;

    prPfeDev = &arPfeInterface[CtrlIdx];

    if (IF_TYPE_EMAC == prPfeDev->ifType)
    {
        if ((Std_ReturnType)E_OK != GetPhyIfIdByCtrlHwPort(CtrlIdx, &emac_id))
        {
            NXP_LOG_ERROR("Could not get PHY IF ID for controller %u\n", (uint_t)CtrlIdx);
        }
        else
        {
            prEmac = ptrPlatform->emac[emac_id];
        }

        if (NULL_PTR != prEmac)
        {
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
}

/**
* @brief        Allows the Time Slave to adjust the local ETH Reference clock in HW.
* @details      Only use this function when this controller used as Time Slave.
*
* @param[in]    CtrlIdx         Index of the controller which time shall be corrected
* @param[in]    pTimeOffsetPtr Offset between time stamp grandmaster and time stamp by local
*               clock.
* @param[in]    pRateRatioPtr  Time elements to calculate and to modify the ratio of the frequency
*               of the grandmaster in relation to the frequency of the Local Clock
*/
Std_ReturnType Eth_43_PFE_LLD_SetCorrectionTime (   uint8 CtrlIdx, \
                                                    const Eth_TimeIntDiffType *pTimeOffsetPtr, \
                                                    const Eth_RateRatioType *pRateRatioPtr \
                                                )
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    pfe_emac_t *prEmac = NULL_PTR;
    uint64 u64RemoteTime;
    uint64 u64LocalTime;
    bool_t bIsPositive;
    uint64 u64Diff;
    uint64 u64ChngFreqPPB; /* Frequency change in part per billion */
    pfe_ct_phy_if_id_t emac_id;
    const trPfeDev *prPfeDev;

    prPfeDev = &arPfeInterface[CtrlIdx];

    if (IF_TYPE_EMAC == prPfeDev->ifType)
    {
        if ((Std_ReturnType)E_OK != GetPhyIfIdByCtrlHwPort(CtrlIdx, &emac_id))
        {
            NXP_LOG_ERROR("Could not get PHY IF ID for controller %u\n", (uint_t)CtrlIdx);
        }
        else
        {
            prEmac = ptrPlatform->emac[emac_id];
        }

        if (NULL_PTR == prEmac)
        {
            NXP_LOG_ERROR("No EMAC associated with controller index %hhu\n", CtrlIdx);
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {

            if ((pTimeOffsetPtr->diff.seconds != 0U) || (pTimeOffsetPtr->diff.nanoseconds != 0U))
            {
                if (EOK != pfe_emac_adjust_ts_time(prEmac, pTimeOffsetPtr->diff.seconds, pTimeOffsetPtr->diff.nanoseconds, pTimeOffsetPtr->sign))
                {
                    RetVal = (Std_ReturnType)E_NOT_OK;
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
                u64RemoteTime = ((uint64)pRateRatioPtr->OriginTimeStampDelta.diff.seconds * 1000000000ULL)
                                + pRateRatioPtr->OriginTimeStampDelta.diff.nanoseconds;

                u64LocalTime  = ((uint64)pRateRatioPtr->IngressTimeStampDelta.diff.seconds * 1000000000ULL)
                                + pRateRatioPtr->IngressTimeStampDelta.diff.nanoseconds;

                if ((u64RemoteTime != 0ULL) && (u64LocalTime != 0ULL))
                {
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
                        NXP_LOG_ERROR("Global time rate correction is too big %hhu\n", CtrlIdx);
                        RetVal = (Std_ReturnType)E_NOT_OK;
                    }
                    else
                    {
                        if(EOK != pfe_emac_set_ts_freq_adjustment(prEmac, (uint32)u64ChngFreqPPB, bIsPositive))
                        {
                            RetVal = (Std_ReturnType)E_NOT_OK;
                        }
                    }
                }
            }
        }
    }
    else
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

    return RetVal;
}

void Eth_43_PFE_LLD_EnableEgressTimeStamp(uint8 CtrlIdx, Eth_BufIdxType BufIdx)
{
    trTxMeta *prTxMeta = Eth_PFE_LLD_GetTxBufMeta(CtrlIdx, BufIdx);

    prTxMeta->bDoTS = TRUE;
}

/*  Get the timestamp from pfe_hif_drv_client
    DataPtr points to Ethernet frame payload (buffer + 14 for header) */
errno_t Eth_43_PFE_LLD_GetRxTimeStamp(uint8 CtrlIdx, \
                                    const Eth_DataType *DataPtr, \
                                    Eth_TimeStampQualType *timeQualPtr, \
                                    Eth_TimeStampType *timeStampPtr \
                                )
{
    uint8 *pu8Packet = (uint8 *)DataPtr;
    oal_util_ptp_header_t *pu8PtpHead = NULL_PTR;
    errno_t RetVal = ENOENT;

    if (NULL_PTR != arPfeInterface[CtrlIdx].prClient)
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
                arPfeInterface[CtrlIdx].prClient, TRUE,
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
void Eth_43_PFE_LLD_GetTxTimeStamp( uint8 CtrlIdx, \
                                    Eth_BufIdxType BufIdx, \
                                    Eth_TimeStampQualType *timeQualPtr, \
                                    Eth_TimeStampType *timeStampPtr \
                                  )
{
    *timeQualPtr = aarTxBuf[CtrlIdx][BufIdx].TimeQual;
    *timeStampPtr = aarTxBuf[CtrlIdx][BufIdx].TimeStamp;
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
    Std_ReturnType retVal = (Std_ReturnType)E_NOT_OK;

    if (NULL_PTR != ptrPlatform)
    {
        if(EOK == pfe_class_get_stats(ptrPlatform->classifier, stat))
        {
            retVal = (Std_ReturnType)E_OK;
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
    Std_ReturnType retVal = (Std_ReturnType)E_NOT_OK;
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
            retVal = (Std_ReturnType)E_OK;
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
    Std_ReturnType retVal = (Std_ReturnType)E_NOT_OK;
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
            retVal = (Std_ReturnType)E_OK;
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
    Std_ReturnType retVal = (Std_ReturnType)E_NOT_OK;

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
        retVal = (Std_ReturnType)E_OK;
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
    Std_ReturnType retVal = (Std_ReturnType)E_NOT_OK;
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
                retVal = (Std_ReturnType)E_OK;
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
    Std_ReturnType retVal = (Std_ReturnType)E_NOT_OK;

#ifdef PFE_CFG_L2BRIDGE_ENABLE
    if (NULL_PTR != ptrPlatform)
    {
        if(EOK == pfe_l2br_get_domain_stats(ptrPlatform->l2_bridge, stat, index_vlan))
        {
            retVal = (Std_ReturnType)E_OK;
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
    Std_ReturnType retVal = (Std_ReturnType)E_NOT_OK;

#ifdef PFE_CFG_RTABLE_ENABLE
    if (NULL_PTR != ptrPlatform)
    {
        if (EOK == pfe_rtable_get_stats(ptrPlatform->rtable, stat, conntrack_index))
        {
            retVal = (Std_ReturnType)E_OK;
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
    Std_ReturnType retVal = (Std_ReturnType)E_NOT_OK;
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

                    (void)autolibc_memset(stat->aQueue[i][j].zprob, PFE_INVALID_STAT, sizeof(stat->aQueue[i][j].zprob)/sizeof(stat->aQueue[i][j].zprob[0]));
                }
            }
        }
        retVal = (Std_ReturnType)E_OK;
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
        CounterPtr->DropPktBufOverrun = pfe_emac_get_stat_value(prEmac, RX_FIFO_OVERFLOW_PACKETS);
        CounterPtr->DropPktCrc        = pfe_emac_get_stat_value(prEmac, RX_CRC_ERROR_PACKETS);
        CounterPtr->UndersizePkt      = pfe_emac_get_stat_value(prEmac, RX_UNDERSIZE_PACKETS_GOOD);
        CounterPtr->OversizePkt       = pfe_emac_get_stat_value(prEmac, RX_OVERSIZE_PACKETS_GOOD);
        CounterPtr->AlgnmtErr         = pfe_emac_get_stat_value(prEmac, RX_ALIGNMENT_ERROR_PACKETS);
        CounterPtr->SqeTestErr        = 0xFFFFFFFFU;
        CounterPtr->DiscInbdPkt       = pfe_emac_get_stat_value(prEmac, RX_FIFO_OVERFLOW_PACKETS);
        CounterPtr->ErrInbdPkt        = 0xFFFFFFFFU;
        CounterPtr->DiscOtbdPkt       = pfe_emac_get_stat_value(prEmac, TX_UNDERFLOW_ERROR_PACKETS);
        CounterPtr->ErrOtbdPkt        = pfe_emac_get_stat_value(prEmac, TX_PACKET_COUNT_GOOD_BAD);
        CounterPtr->ErrOtbdPkt       -= pfe_emac_get_stat_value(prEmac, TX_PACKET_COUNT_GOOD);
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
        RxStatsPtr->RxStatsDropEvents           = pfe_emac_get_stat_value(prEmac, RX_FIFO_OVERFLOW_PACKETS);
        RxStatsPtr->RxStatsOctets               = pfe_emac_get_stat_value(prEmac, RX_OCTET_COUNT_GOOD_BAD);
        RxStatsPtr->RxStatsPkts                 = pfe_emac_get_stat_value(prEmac, RX_PACKETS_COUNT_GOOD_BAD);
        RxStatsPtr->RxStatsBroadcastPkts        = pfe_emac_get_stat_value(prEmac, RX_BROADCAST_PACKETS_GOOD);
        RxStatsPtr->RxStatsMulticastPkts        = pfe_emac_get_stat_value(prEmac, RX_MULTICAST_PACKETS_GOOD);
        RxStatsPtr->RxStatsCrcAlignErrors       = pfe_emac_get_stat_value(prEmac, RX_CRC_ERROR_PACKETS);
        RxStatsPtr->RxStatsCrcAlignErrors      += pfe_emac_get_stat_value(prEmac, RX_ALIGNMENT_ERROR_PACKETS);
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
        TxStatsPtr->TxNumberOfOctets  = pfe_emac_get_stat_value(prEmac, TX_OCTET_COUNT_GOOD_BAD);
        TxStatsPtr->TxNUcastPkts      = pfe_emac_get_stat_value(prEmac, TX_MULTICAST_PACKETS_GOOD_BAD);
        TxStatsPtr->TxNUcastPkts     += pfe_emac_get_stat_value(prEmac, TX_BROADCAST_PACKETS_GOOD_BAD);
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
        TxErrorCounterValuesPtr->TxDroppedNoErrorPkts = pfe_emac_get_stat_value(prEmac, TX_UNDERFLOW_ERROR_PACKETS);
        TxErrorCounterValuesPtr->TxDroppedErrorPkts   = pfe_emac_get_stat_value(prEmac, TX_PACKET_COUNT_GOOD_BAD);
        TxErrorCounterValuesPtr->TxDroppedErrorPkts  -= pfe_emac_get_stat_value(prEmac, TX_PACKET_COUNT_GOOD);
        TxErrorCounterValuesPtr->TxDeferredTrans      = pfe_emac_get_stat_value(prEmac, TX_DEFERRED_PACKETS);
        TxErrorCounterValuesPtr->TxSingleCollision    = pfe_emac_get_stat_value(prEmac, TX_SINGLE_COLLISION_GOOD_PACKETS);
        TxErrorCounterValuesPtr->TxMultipleCollision  = pfe_emac_get_stat_value(prEmac, TX_MULTIPLE_COLLISION_GOOD_PACKETS);
        TxErrorCounterValuesPtr->TxLateCollision      = pfe_emac_get_stat_value(prEmac, TX_LATE_COLLISION_PACKETS);
        TxErrorCounterValuesPtr->TxExcessiveCollison  = pfe_emac_get_stat_value(prEmac, TX_EXCESSIVE_COLLISION_PACKETS);
    }
    return E_OK;
}
#endif /* STD_ON == ETH_43_GET_TXERROR_COUNTER_API */

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

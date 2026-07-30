/**
*   @file       Eth_43_PFE.h
*
*   @brief   AUTOSAR Eth driver interface header file
*   @details Implementation of the AUTOSAR Ethernet driver
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

#ifndef ETH_43_PFE_H
#define ETH_43_PFE_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                     FILE VERSION CHECK
==================================================================================================*/
#ifdef PFE_SRC_VERSION_CHECK
    #if (PFE_SRC_VERSION_CHECK != 43120440)
        #error "This header file was included from incompatible source file (different SW version)"
    #endif
#else
    #define PFE_SRC_VERSION_CHECK 43120440
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Eth_GeneralTypes.h"  /* Mandatory include - see the SWS */
#include "pfe_cfg.h"
#include "oal_types.h"
#include "pfe_emac.h"
#include "pfe_tmu.h"
#include "Eth_43_PFE_Cfg.h" /* Mandatory include - see the SWS */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_43_PFE_VENDOR_ID                    43
#define ETH_43_PFE_MODULE_ID                    88
#define ETH_43_PFE_SW_MAJOR_VERSION             1
#define ETH_43_PFE_SW_MINOR_VERSION             2
#define ETH_43_PFE_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/* Service IDs definition */
#define ETH_43_PFE_SID_INIT                    0x01
#define ETH_43_PFE_SID_SETCONTROLLERMODE       0x03
#define ETH_43_PFE_SID_GETCONTROLLERMODE       0x04
#define ETH_43_PFE_SID_GETPHYSADDR             0x08
#define ETH_43_PFE_SID_WRITEMII                0x05
#define ETH_43_PFE_SID_READMII                 0x06
#define ETH_43_PFE_SID_PROVIDETXBUFFER         0x09
#define ETH_43_PFE_SID_TRANSMIT                0x0A
#define ETH_43_PFE_SID_RECEIVE                 0x0B
#define ETH_43_PFE_SID_TXCONFIRMATION          0x0C
#define ETH_43_PFE_SID_GETVERSIONINFO          0x0D
#define ETH_43_PFE_SID_SETPHYSADDR             0x13
#define ETH_43_PFE_SID_UPDATEADDRFILTER        0x12
#define ETH_43_PFE_SID_GETCOUNTERVALUE         0x14
#define ETH_43_PFE_SID_GETRXSTATS              0x15
#define ETH_43_PFE_SID_GETCURRENTTIME          0x16
#define ETH_43_PFE_SID_ENABLEEGRESSTIMESTAMP   0x17
#define ETH_43_PFE_SID_GETEGRESSTIMESTAMP      0x18
#define ETH_43_PFE_SID_GETINGRESSTIMESTAMP     0x19
#define ETH_43_PFE_SID_SETCORRECTIONTIME       0x1A
#define ETH_43_PFE_SID_SETGLOBALTIME           0x1B
#define ETH_43_PFE_SID_GETTXSTATS              0x1C
#define ETH_43_PFE_SID_GETTXERRORCOUNTERVALUE  0x1D
#if STD_ON == ETH_43_PFE_CTRL_USE_45_MDIO_API
    #define ETH_43_PFE_SID_WRITEMII45          0x1E
    #define ETH_43_PFE_SID_READMII45           0x1F
#endif /* STD_ON == ETH_43_PFE_CTRL_USE_45_MDIO_API */
#define ETH_43_PFE_SID_MAINFUNCTION            0x20
#define ETH_43_PFE_SID_PREINIT                 0x21
#define ETH_43_PFE_SID_GETPLATFORM             0x22
#define ETH_43_PFE_SID_GETCLASSSTATS           0x23
#define ETH_43_PFE_SID_GETBMUSTATS             0x24
#define ETH_43_PFE_SID_GETGPISTATS             0x25
#define ETH_43_PFE_SID_GETL2BRIDGESTATS        0x26
#define ETH_43_PFE_SID_GETL2BRIDGEDOMAINSTATS  0x27
#define ETH_43_PFE_SID_GETWDTSTATS             0x28
#define ETH_43_PFE_SID_GETRTABLESTATS          0x29
#define ETH_43_PFE_SID_GETTMUSTATS             0x2A
#define ETH_43_PFE_SID_DEINIT                  0x2B
#if STD_ON == ETH_43_PFE_RELEASE_TX_BUFFER_API
    #define ETH_43_PFE_SID_RELEASETXBUFFER     0x2C
#endif  /* STD_ON == ETH_43_PFE_RELEASE_TX_BUFFER_API */

/* DET error codes */
#if STD_ON == ETH_43_PFE_DEV_ERROR_DETECT
#define ETH_43_PFE_E_INV_CTRL_IDX      ((uint8)0x01)
#define ETH_43_PFE_E_UNINIT            ((uint8)0x02)
#define ETH_43_PFE_E_PARAM_POINTER     ((uint8)0x03)
#define ETH_43_PFE_E_INV_PARAM         ((uint8)0x04)
#define ETH_43_PFE_E_INV_MODE          ((uint8)0x05)
#endif
/* Define Specific Error code for Std_ReturnType */
#define ETH_43_PFE_E_NO_ACCESS         ((uint8)0x03U)

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define ETH_43_PFE_PHY_ADDR_MAX              0x1FU
#define ETH_43_PFE_PHY_REG_ADDR_MII22_MAX    0x1FU
#define ETH_43_PFE_PHY_DEV_MII45_MAX         0x1FU
#define PFE_INVALID_STAT                     0xFFFFFFFFU
#define PFE_BMU_NUMBER_MAX_MAS_BUFF_CNT      32U
#define PFE_TMU_PHY_CNT                      6U
#define PFE_TMU_PHY_QUEUE_CNT                8U

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef struct
{
    uint32_t bmu_debug_bus;
    uint32_t buff_base;
    uint32_t buff_remain;
    uint32_t buff_allocated;
    uint32_t low_watermark;
    uint32_t high_watermark;
    uint32_t irq_threshold;
    uint32_t free_error_add;
    uint32_t irq_source;
    uint32_t irq_enable;
    uint32_t master_buf_count[PFE_BMU_NUMBER_MAX_MAS_BUFF_CNT];
    uint32_t revision;
    uint32_t version;
    uint32_t id;
    uint32_t free_error_cnt;
    uint32_t active_buff;
    uint32_t buff_size;
}Eth_43_PFE_BmuStatsType;

typedef struct
{
    uint32_t fifo_debug;
    uint32_t tx_debug_reg1;
    uint32_t tx_debug_reg2;
    uint32_t tx_debug_reg3;
    uint32_t tx_debug_reg4;
    uint32_t tx_debug_reg5;
    uint32_t tx_debug_reg6;
    uint32_t rx_debug_reg1;
    uint32_t rx_debug_reg2;
    uint32_t fifo_status;
    uint32_t revision;
    uint32_t version;
    uint32_t id;
    uint32_t iqos_queue_status;
    uint32_t iqos_class_drop_cnt;
    uint32_t iqos_lmem_drop_cnt;
    uint32_t iqos_dmem_drop_cnt;
    uint32_t iqos_rxf_drop_cnt;
    uint32_t iqos_shp0_drop_cnt;
    uint32_t iqos_shp1_drop_cnt;
    uint32_t iqos_manage_pkts;
    uint32_t iqos_unmanage_pkts;
    uint32_t iqos_reserved_pkts;
    uint32_t tx_underrun;
    uint32_t tx_fifo_packets;
    uint32_t rx_fifo_packets;
    uint32_t tx_fifo_level;
    uint32_t rx_fifo_level;
    uint32_t aseq_length;
    uint32_t enable_reg_1588;
    uint32_t overrun_drop_cnt;
}Eth_43_PFE_GpiStatsType;

typedef struct
{
    uint32_t wdp_version;
    uint32_t wdt_int_en;
    uint32_t class_wdt_int_en;
    uint32_t upe_wdt_int_en;
    uint32_t hgpi_wdt_int_en;
    uint32_t hif_wdt_int_en;
    uint32_t tlite_wdt_int_en;
    uint32_t hncpy_wdt_int_en;
    uint32_t bmu1_wdt_int_en;
    uint32_t bmu2_wdt_int_en;
    uint32_t emac0_wdt_int_en;
    uint32_t emac1_wdt_int_en;
    uint32_t emac2_wdt_int_en;
    uint32_t ext_gpt_wdt_int_en;
    uint32_t lmem_wdt_int_en;
    uint32_t wdt_int_src;
    uint32_t wdt_timer_val_upe;
    uint32_t wdt_timer_val_bmu;
    uint32_t wdt_timer_val_hif;
    uint32_t wdt_timer_val_tlite;
    uint32_t wdt_timer_val_hif_ncpy;
    uint32_t wdt_timer_val_class;
    uint32_t wdt_timer_val_gpi;
    uint32_t wdt_timer_val_gpt;
    uint32_t wdt_timer_val_lmem;
    uint32_t wdt_timer_val_route_lmem;
    uint32_t wsp_dbug_bus1_g3;
    uint32_t wsp_dbug_bus1;
}Eth_43_PFE_WdtStatsType;

typedef struct
{
    uint8_t mac_address[6];
    uint32_t vlan;
    uint32_t action_data;
    uint32_t col_ptr;
    uint32_t flags;
    uint32_t mac_entries_count;
}Eth_43_PFE_L2BridgeStatsType;

typedef struct
{
    uint32_t tmu_phy_inq_pktptr;
    uint32_t tmu_phy_inq_pktinfo;
    uint32_t tmu_phy_inq_stat;
    uint32_t tmu_dbg_bus_stop;
    uint32_t tmu_dbg_bus_pp0;
    uint32_t tmu_dbg_bus_pp1;
    uint32_t tmu_dbg_bus_pp2;
    uint32_t tmu_dbg_bus_pp3;
    uint32_t tmu_dbg_bus_pp4;
    uint32_t tmu_dbg_bus_pp5;
    uint32_t revision;
    uint32_t version;
    uint32_t id;
    uint32_t ctrl;
    pfe_tmu_queue_stats aQueue[PFE_TMU_PHY_CNT][PFE_TMU_PHY_QUEUE_CNT]; 
}Eth_43_PFE_TmuStatsType;
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define ETH_43_PFE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

/* Eth_43_PFE_CtrlState: Used to store state of Eth controller(s). */
extern volatile Eth_StateType Eth_43_PFE_CtrlState[ETH_43_PFE_MAXCTRLS_SUPPORTED];

#define ETH_43_PFE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
extern const Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr;
#define ETH_43_PFE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

extern void Eth_43_PFE_PreInit(const Eth_43_PFE_ConfigType * CfgPtr);
extern void Eth_43_PFE_Init(const Eth_43_PFE_ConfigType * CfgPtr);
extern void Eth_43_PFE_DeInit(void);
extern Std_ReturnType Eth_43_PFE_SetControllerMode ( \
                                    uint8 u8CtrlIdx, \
                                    Eth_ModeType CtrlMode \
                                                            );
extern Std_ReturnType Eth_43_PFE_GetControllerMode ( \
                                    uint8 u8CtrlIdx, \
                                    Eth_ModeType * CtrlModePtr \
                                                            );
extern void Eth_43_PFE_GetPhysAddr ( \
                        uint8 u8CtrlIdx, \
                        uint8 * PhysAddrPtr \
                                            );
extern void Eth_43_PFE_SetPhysAddr(uint8 u8CtrlIdx, const uint8 * PhysAddrPtr);

extern Std_ReturnType Eth_43_PFE_UpdatePhysAddrFilter ( \
                                    uint8 u8CtrlIdx, \
                                    const uint8 * PhysAddrPtr, \
                                    Eth_FilterActionType Action \
                                                            );

extern BufReq_ReturnType Eth_43_PFE_ProvideTxBuffer( \
                                uint8 u8CtrlIdx, \
                                uint8 Priority, \
                                Eth_BufIdxType * BufIdxPtr, \
                                uint8 **BufPtr, \
                                uint16 * LenBytePtr \
                                                            );
extern Std_ReturnType Eth_43_PFE_Transmit  (
                            uint8 u8CtrlIdx,
                            Eth_BufIdxType BufIdx,
                            Eth_FrameType FrameType,
                            boolean TxConfirmation,
                            uint16 LenByte,
                            const uint8 * PhysAddrPtr
                                                    );
extern void Eth_43_PFE_Receive(uint8 u8CtrlIdx, \
                                    uint8 FifoIdx,  \
                                    Eth_RxStatusType * RxStatusPtr   \
                                 ) ;
extern void Eth_43_PFE_TxConfirmation(uint8 u8CtrlIdx);

#if STD_ON == ETH_43_PFE_RELEASE_TX_BUFFER_API
extern BufReq_ReturnType Eth_43_PFE_ReleaseTxBuffer(uint8 u8CtrlIdx, Eth_BufIdxType BufIdx);
#endif  /* STD_ON == ETH_43_PFE_RELEASE_TX_BUFFER_API */

#if STD_ON == ETH_43_PFE_CTRLENABLE_MII
extern Std_ReturnType Eth_43_PFE_WriteMii(uint8 u8CtrlIdx, \
                                            uint8 u8TrcvIdx, \
                                            uint8 u8RegIdx, \
                                            uint16 u16RegVal
                                        );

extern Std_ReturnType Eth_43_PFE_ReadMii(uint8 u8CtrlIdx, \
                                            uint8 u8TrcvIdx, \
                                            uint8 u8RegIdx, \
                                            uint16 * pu16RegValPtr
                                        );

#if STD_ON == ETH_43_PFE_CTRL_USE_45_MDIO_API
extern Std_ReturnType Eth_43_PFE_WriteMii45(uint8 u8CtrlIdx, \
                                            uint8 u8TrcvIdx, \
                                            uint8 u8DevIdx, \
                                            uint16 u16RegIdx, \
                                            uint16 u16RegVal
                                        );

extern Std_ReturnType Eth_43_PFE_ReadMii45(uint8 u8CtrlIdx, \
                                            uint8 u8TrcvIdx, \
                                            uint8 u8DevIdx, \
                                            uint16 u16RegIdx, \
                                            uint16 * pu16RegValPtr
                                        );
#endif /* STD_ON == ETH_43_PFE_CTRL_USE_45_MDIO_API */
#endif /* STD_OFF == ETH_43_PFE_CTRLENABLE_MII */

#if STD_ON == ETH_43_GET_CLASS_STATISTIC_API
extern Std_ReturnType Eth_43_PFE_GetClassStats(pfe_ct_classify_stats_t * stat);
#endif /* ETH_43_GET_CLASS_STATISTIC_API */

#if STD_ON == ETH_43_GET_PFE_STATISTIC_API
extern Std_ReturnType Eth_43_PFE_GetTmuStats(Eth_43_PFE_TmuStatsType * stat);
extern Std_ReturnType Eth_43_PFE_GetRtableStats(pfe_ct_conntrack_stats_t * stat, uint8 conntrack_index);
extern Std_ReturnType Eth_43_PFE_GetL2BridgeDomainStats(pfe_ct_vlan_stats_t* stat, uint32 index_vlan);
extern Std_ReturnType Eth_43_PFE_GetL2BridgeStats(Eth_43_PFE_L2BridgeStatsType * stat, uint32 index_entry);
extern Std_ReturnType Eth_43_PFE_GetWdtStats(Eth_43_PFE_WdtStatsType * stat);
extern Std_ReturnType Eth_43_PFE_GetGpiStats(uint8 u8GpiIndex, Eth_43_PFE_GpiStatsType * stat);
extern Std_ReturnType Eth_43_PFE_GetBmuStats(uint8 u8BmuIndex, Eth_43_PFE_BmuStatsType* stat);
#endif /* ETH_43_GET_PFE_STATISTIC_API */

#if STD_ON == ETH_43_GET_COUNTER_API
extern Std_ReturnType Eth_43_PFE_GetCounterValues(uint8 u8CtrlIdx, \
                                            Eth_CounterType * CounterPtr
                                        );
#endif /* STD_ON == ETH_43_GET_COUNTER_API */

#if STD_ON == ETH_43_GET_RXSTATS_API
extern Std_ReturnType Eth_43_PFE_GetRxStats(uint8 u8CtrlIdx, \
                                            Eth_RxStatsType * RxStatsPtr
                                        );
#endif /* STD_ON == ETH_43_GET_RXSTATS_API */

#if STD_ON == ETH_43_GET_TXSTATS_API
extern Std_ReturnType Eth_43_PFE_GetTxStats(uint8 u8CtrlIdx, \
                                            Eth_TxStatsType * TxStatsPtr
                                        );
#endif /* STD_ON == ETH_43_GET_TXSTATS_API */

#if STD_ON == ETH_43_GET_TXERROR_COUNTER_API
extern Std_ReturnType Eth_43_PFE_GetTxErrorCounterValues(uint8 u8CtrlIdx, \
                                            Eth_TxErrorCounterValuesType * TxErrorCounterValuesPtr
                                        );
#endif /* STD_ON == ETH_43_GET_TXERROR_COUNTER_API */

#if STD_ON == ETH_43_PFE_VERSION_INFO_API
    #if STD_OFF == ETH_43_PFE_VERSION_INFO_API_MACRO
        extern void Eth_43_PFE_GetVersionInfo(Std_VersionInfoType * VersionInfoPtr);
    #endif /* ETH_43_PFE_VERSION_INFO_API_MACRO */
#endif /* ETH_43_PFE_VERSION_INFO_API */
extern void Eth_43_PFE_MainFunction(void);
extern void * Eth_43_PFE_GetPlatform(void);

#if STD_ON == ETH_43_PFE_GLOBALTIME_SUPPORT
extern Std_ReturnType Eth_43_PFE_SetGlobalTime  (   uint8 u8CtrlIdx, \
                                                    const Eth_TimeStampType *timeStampPtr \
                                                );
extern Std_ReturnType Eth_43_PFE_SetCorrectionTime  (   uint8 u8CtrlIdx, \
                                                        const Eth_TimeIntDiffType *timeOffsetPtr, \
                                                        const Eth_RateRatioType *rateRatioPtr \
                                                    );
extern Std_ReturnType Eth_43_PFE_GetCurrentTime (   uint8 u8CtrlIdx, \
                                                    Eth_TimeStampQualType *timeQualPtr, \
                                                    Eth_TimeStampType *timeStampPtr \
                                                );
extern Std_ReturnType Eth_43_PFE_GetEgressTimeStamp (   uint8 u8CtrlIdx, \
                                                        Eth_BufIdxType BufIdx, \
                                                        Eth_TimeStampQualType *timeQualPtr, \
                                                        Eth_TimeStampType *timeStampPtr \
                                                    );
extern Std_ReturnType Eth_43_PFE_GetIngressTimeStamp(   uint8 u8CtrlIdx, \
                                                        const Eth_DataType *DataPtr, \
                                                        Eth_TimeStampQualType *timeQualPtr, \
                                                        Eth_TimeStampType *timeStampPtr \
                                                    );
extern void Eth_43_PFE_EnableEgressTimeStamp(uint8 u8CtrlIdx, Eth_BufIdxType BufIdx);
#endif /* ETH_43_PFE_GLOBALTIME_SUPPORT */

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* ETH_43_PFE_H */

/** @} */

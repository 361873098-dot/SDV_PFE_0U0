/**
*   @file    Eth_PFE_LLD.h
*
*   @brief   PFE controller interface header file
*   @details Implementation of the PFE controller interface for
*            the Ethernet driver
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
#ifndef ETH_PFE_LLD_H
#define ETH_PFE_LLD_H
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
#include "pfe_cfg.h"
#include "oal.h"
#include "pfe_platform.h"
#include "linked_list.h"
#include "pfe_hif_drv.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          TYPEDEFS
==================================================================================================*/
typedef  struct
{
    uint16 u16BufIdx;
    uint8  u8CtrlIdx;
} Eth_PFE_LLD_trTxRefData;

#if (STD_ON == ETH_43_PFE_GLOBALTIME_SUPPORT)
typedef struct
{
    uint8  u8MessageType;
    uint16 u16SourcePortID;
    uint16 u16SequenceID;
} Eth_PFE_LLD_trTxTsRef;
#endif

typedef struct
{
    boolean bDoTxIndication;
    boolean bDoTS; /* Used in pfe_hif_drv to request timestamp on demand */
} trTxMeta;

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define PFE_LLD_L2_HEADER_SIZE        14U
#define PFE_LLD_L2_CRC_SIZE           4U
#if (STD_ON == ETH_43_PFE_ENABLE_USER_MODE_SUPPORT)
    #define Local_Macro_hal_ip_ready_set(on)    OsIf_Trusted_Call1param(hal_ip_ready_set, (on))
    #define Local_Macro_hal_ip_ready_get()      OsIf_Trusted_Call_Return(hal_ip_ready_get)
#else
    #define Local_Macro_hal_ip_ready_set(on)    hal_ip_ready_set(on)
    #define Local_Macro_hal_ip_ready_get()      hal_ip_ready_get()
#endif

/*==================================================================================================
*                                       GLOBAL VARABLES
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
extern boolean Eth_PFE_LLD_Check_Driver_Init(void);
extern boolean Eth_PFE_LLD_CheckAccessToController(void);
extern void Eth_PFE_LLD_ReportTransmission
(
    const uint8 u8CtrlIdx, const uint8 u8FifoIdx
);

#if STD_ON == ETH_43_PFE_RELEASE_TX_BUFFER_API
boolean Eth_PFE_LLD_ReleaseTxBuffer(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx);
#endif

#if (STD_ON == ETH_43_PFE_GLOBALTIME_SUPPORT)
extern void Eth_PFE_LLD_ReportTransmissionTS(const uint8 u8CtrlIdx, const uint8 u8FifoIdx);
extern Eth_PFE_LLD_trTxTsRef *Eth_PFE_LLD_GetTxBufTsRef(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx);
#endif /* ETH_43_PFE_GLOBALTIME_SUPPORT */
extern Eth_ModeType Eth_PFE_LLD_CheckControllerIsActive(const uint8 u8CtrlIdx);
extern boolean Eth_PFE_LLD_EnableController(const uint8 u8CtrlIdx);
extern Std_ReturnType Eth_PFE_LLD_ConfigureController(const uint8 u8CtrlIdx);
extern boolean Eth_PFE_LLD_CheckInitializationStatus(const uint8 u8CtrlIdx);
extern Std_ReturnType Eth_PFE_LLD_DisableController(const uint8 u8CtrlIdx);
extern void Eth_PFE_LLD_InitInterfaces
(
    const Eth_43_PFE_ConfigType * cfgPtr
);
extern void Eth_PFE_LLD_InitEMACs
(
    const Eth_43_PFE_ConfigType * cfgPtr
);
extern void Eth_PFE_LLD_GetPhysicalAddress
(
    const uint8 u8CtrlIdx,
    uint8 * pu8PhysAddr
);
extern boolean Eth_PFE_LLD_SetPhysAddr
(
    const uint8 u8CtrlIdx,
    const uint8 * pPhysAddrPtr
);
extern Std_ReturnType Eth_PFE_LLD_UpdatePhysAddrFilter
(
    uint8 u8CtrlIdx,
    const uint8 * PhysAddrPtr,
    Eth_FilterActionType Action
);
extern Eth_RxStatusType Eth_PFE_LLD_ReportReception
(
    const uint8 u8CtrlIdx,
    uint8 u8FifoIdx,
    const boolean bIrq
);
extern uint16 Eth_43_PFE_LLD_GetLmemHdrSize(const uint8 u8CtrlIdx);
extern uint8 Eth_43_PFE_LLD_GetTxFifoIdx
(
    const uint8 u8CtrlIdx,
    const Eth_BufIdxType BufIdx
);
extern uint32 Eth_43_PFE_LLD_GetTxBufferSize
(
    const uint8 u8CtrlIdx,
    const uint8 u8FifoIdx
);
extern Std_ReturnType Eth_PFE_LLD_Transmit
(
    const uint8 u8CtrlIdx,
    const Eth_BufIdxType BufIdx,
    const Eth_FrameType u16Type,
    const uint16 u16Length,
    const boolean bConfirm,
    const uint8 * pDest
);
extern boolean Eth_PFE_LLD_ProvideBufferDataArea
(
    const uint8 u8CtrlIdx,
    const uint8 u8QueuIdx,
    Eth_BufIdxType * const pBufIdx,
    uint8 **pData,
    uint16 * const pLength
);
extern void Eth_PFE_LLD_MainFunction(void);
extern Std_ReturnType Eth_PFE_LLD_PlatformDrvPrepare(void);
extern void Eth_PFE_LLD_DeInit(void);
extern void Eth_PFE_LLD_InterfacePrepare(uint8 u8CtrlIdx);

#ifndef PFE_CFG_PFE_SLAVE
extern void Eth_PFE_LLD_EMACPrepare(void);
#endif

#if STD_ON == ETH_43_PFE_CTRLENABLE_MII
extern Std_ReturnType Eth_43_PFE_LLD_WriteMii
(
    uint8 u8CtrlIdx,
    uint8 u8TrcvIdx,
    uint8 u8RegIdx,
    uint16 u16RegVal
);

extern Std_ReturnType Eth_43_PFE_LLD_ReadMii
(
    uint8 u8CtrlIdx,
    uint8 u8TrcvIdx,
    uint8 u8RegIdx,
    uint16 * pu16RegValPtr
);

#if STD_ON == ETH_43_PFE_CTRL_USE_45_MDIO_API
extern Std_ReturnType Eth_43_PFE_LLD_WriteMii45
(
    uint8 u8CtrlIdx,
    uint8 u8TrcvIdx,
    uint8 u8DevIdx,
    uint16 u16RegIdx,
    uint16 u16RegVal
);

extern Std_ReturnType Eth_43_PFE_LLD_ReadMii45
(
    uint8 u8CtrlIdx,
    uint8 u8TrcvIdx,
    uint8 u8DevIdx,
    uint16 u16RegIdx,
    uint16 * pu16RegValPtr
);
#endif /* STD_ON == ETH_43_PFE_CTRL_USE_45_MDIO_API */
#endif /* STD_OFF == ETH_43_PFE_CTRLENABLE_MII */

#if STD_ON == ETH_43_PFE_GLOBALTIME_SUPPORT
extern Std_ReturnType Eth_43_PFE_LLD_SetGlobalTime  (   uint8 CtrlIdx, \
                                                        const Eth_TimeStampType *pTimeStampPtr \
                                                    );
extern Std_ReturnType Eth_43_PFE_LLD_SetCorrectionTime (   uint8 CtrlIdx, \
                                                           const Eth_TimeIntDiffType *pTimeOffsetPtr, \
                                                           const Eth_RateRatioType *pRateRatioPtr \
                                                        );
extern void Eth_43_PFE_LLD_GetCurrentTime   (   uint8 CtrlIdx, \
                                                Eth_TimeStampQualType *timeQualPtr, \
                                                Eth_TimeStampType *timeStampPtr \
                                            );
extern errno_t Eth_43_PFE_LLD_GetRxTimeStamp(  uint8 CtrlIdx, \
                                               const Eth_DataType *DataPtr, \
                                               Eth_TimeStampQualType *timeQualPtr, \
                                               Eth_TimeStampType *timeStampPtr \
                                            );
extern void Eth_43_PFE_LLD_GetTxTimeStamp( uint8 CtrlIdx, \
                                           Eth_BufIdxType BufIdx, \
                                           Eth_TimeStampQualType *timeQualPtr, \
                                           Eth_TimeStampType *timeStampPtr \
                                         );

extern void Eth_43_PFE_LLD_EnableEgressTimeStamp(uint8 CtrlIdx, Eth_BufIdxType BufIdx);
#endif /* ETH_43_PFE_GLOBALTIME_SUPPORT */

extern void * Eth_PFE_LLD_GetPlatform(void);

#if STD_ON == ETH_43_GET_CLASS_STATISTIC_API
extern Std_ReturnType Eth_43_PFE_LLD_GetClassStats(pfe_ct_classify_stats_t * stat);
#endif /* ETH_43_GET_CLASS_STATISTIC_API */

#if STD_ON == ETH_43_GET_PFE_STATISTIC_API
extern Std_ReturnType Eth_43_PFE_LLD_GetTmuStats(Eth_43_PFE_TmuStatsType * stat);
extern Std_ReturnType Eth_43_PFE_LLD_GetRtableStats(pfe_ct_conntrack_stats_t * stat, uint8 conntrack_index);
extern Std_ReturnType Eth_43_PFE_LLD_GetL2BridgeDomainStats(pfe_ct_vlan_stats_t * stat, uint8 index_vlan);
extern Std_ReturnType Eth_43_PFE_LLD_GetL2BridgeStats(Eth_43_PFE_L2BridgeStatsType * stat, uint32 index_entry);
extern Std_ReturnType Eth_43_PFE_LLD_GetWdtStats(Eth_43_PFE_WdtStatsType * stat);
extern Std_ReturnType Eth_43_PFE_LLD_GetGpiStats(uint8 u8GpiIndex, Eth_43_PFE_GpiStatsType * stat);
extern Std_ReturnType Eth_43_PFE_LLD_GetBmuStats(uint8 u8BmuIndex, Eth_43_PFE_BmuStatsType* stat);
#endif /* ETH_43_GET_PFE_STATISTIC_API */

#if STD_ON == ETH_43_GET_COUNTER_API
extern Std_ReturnType Eth_PFE_LLD_GetCounterValues(uint8 u8CtrlIdx, \
                                            Eth_CounterType * CounterPtr
                                        );
#endif /* STD_ON == ETH_43_GET_COUNTER_API */

#if STD_ON == ETH_43_GET_RXSTATS_API
extern Std_ReturnType Eth_PFE_LLD_GetRxStats(uint8 u8CtrlIdx, \
                                            Eth_RxStatsType * RxStatsPtr
                                        );
#endif /* STD_ON == ETH_43_GET_RXSTATS_API */

#if STD_ON == ETH_43_GET_TXSTATS_API
extern Std_ReturnType Eth_PFE_LLD_GetTxStats(uint8 u8CtrlIdx, \
                                            Eth_TxStatsType * TxStatsPtr
                                        );
#endif /* STD_ON == ETH_43_GET_TXSTATS_API */

#if STD_ON == ETH_43_GET_TXERROR_COUNTER_API
extern Std_ReturnType Eth_PFE_LLD_GetTxErrorCounterValues(uint8 u8CtrlIdx, \
                                            Eth_TxErrorCounterValuesType * TxErrorCounterValuesPtr
                                        );
#endif /* STD_ON == ETH_43_GET_TXERROR_COUNTER_API */
extern trTxMeta *Eth_PFE_LLD_GetTxBufMeta(const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx);

#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
#ifdef PFE_CFG_PFE_MASTER
extern void Eth_43_PFE_LLD_SetMasterUp(void);
#endif /* PFE_CFG_PFE_MASTER */
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* ETH_PFE_LLD_H */
/** @} */

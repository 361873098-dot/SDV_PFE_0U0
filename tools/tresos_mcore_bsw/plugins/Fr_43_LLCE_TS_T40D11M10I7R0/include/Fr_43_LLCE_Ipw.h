/**
*   @file    Fr_43_LLCE_Ipw.h
*   @version 1.0.7
*
*   @brief   AUTOSAR Fr_43_LLCE - module interface.
*   @details Main header file - fr include different IPV models.
*   @implements  Fr_Ipw.h_Artifact
*
*   @addtogroup FR_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : LLCE
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 1.0.7
*   Build Version        : S32_RTD_1_0_7_D2909_ASR_REL_4_4_REV_0000_20230630
*
*   (c) Copyright 2020-2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
#ifndef FR_43_LLCE_IPW_H
#define FR_43_LLCE_IPW_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fr_43_LLCE.h"
#include "Flexray_43_LLCE_Ip.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
 * @brief Parameters that shall be published within the driver header file and also in the
 *        module's description file
 */
#define FR_43_LLCE_IPW_MODULE_ID                        81
#define FR_43_LLCE_IPW_VENDOR_ID                        43
#define FR_43_LLCE_IPW_AR_RELEASE_MAJOR_VERSION         4
#define FR_43_LLCE_IPW_AR_RELEASE_MINOR_VERSION         4
#define FR_43_LLCE_IPW_AR_RELEASE_REVISION_VERSION      0
#define FR_43_LLCE_IPW_SW_MAJOR_VERSION                 1
#define FR_43_LLCE_IPW_SW_MINOR_VERSION                 0
#define FR_43_LLCE_IPW_SW_PATCH_VERSION                 7

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fr_43_LLCE.h header file are of the same vendor */
#if (FR_43_LLCE_IPW_VENDOR_ID != FR_43_LLCE_VENDOR_ID)
    #error "Fr_43_LLCE_Ipw.h and Fr_43_LLCE.h have different Vendor IDs"
#endif
/* Check if current file and Fr_43_LLCE.h header file are of the same Autosar version */
#if ((FR_43_LLCE_IPW_AR_RELEASE_MAJOR_VERSION    != FR_43_LLCE_AR_RELEASE_MAJOR_VERSION) || \
     (FR_43_LLCE_IPW_AR_RELEASE_MINOR_VERSION    != FR_43_LLCE_AR_RELEASE_MINOR_VERSION) || \
     (FR_43_LLCE_IPW_AR_RELEASE_REVISION_VERSION != FR_43_LLCE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fr_43_LLCE_Ipw.h and Fr_43_LLCE.h are different"
#endif
/* Check if current file and Fr_43_LLCE.h header file are of the same software version */
#if ((FR_43_LLCE_IPW_SW_MAJOR_VERSION != FR_43_LLCE_SW_MAJOR_VERSION) || \
     (FR_43_LLCE_IPW_SW_MINOR_VERSION != FR_43_LLCE_SW_MINOR_VERSION) || \
     (FR_43_LLCE_IPW_SW_PATCH_VERSION != FR_43_LLCE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fr_43_LLCE_Ipw.h and Fr_43_LLCE.h are different"
#endif

/* Check if current file and Flexray_43_LLCE_Ip.h header file are of the same vendor */
#if (FR_43_LLCE_IPW_VENDOR_ID != FLEXRAY_43_LLCE_IP_VENDOR_ID)
    #error "Fr_43_LLCE_Ipw.h and Flexray_Ip.h have different Vendor IDs"
#endif
/* Check if current file and Flexray_43_LLCE_Ip.h header file are of the same Autosar version */
#if ((FR_43_LLCE_IPW_AR_RELEASE_MAJOR_VERSION    != FLEXRAY_43_LLCE_IP_AR_RELEASE_MAJOR_VERSION) || \
     (FR_43_LLCE_IPW_AR_RELEASE_MINOR_VERSION    != FLEXRAY_43_LLCE_IP_AR_RELEASE_MINOR_VERSION) || \
     (FR_43_LLCE_IPW_AR_RELEASE_REVISION_VERSION != FLEXRAY_43_LLCE_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fr_43_LLCE_Ipw.h and Flexray_Ip.h are different"
#endif
/* Check if current file and Flexray_43_LLCE_Ip.h header file are of the same software version */
#if ((FR_43_LLCE_IPW_SW_MAJOR_VERSION != FLEXRAY_43_LLCE_IP_SW_MAJOR_VERSION) || \
     (FR_43_LLCE_IPW_SW_MINOR_VERSION != FLEXRAY_43_LLCE_IP_SW_MINOR_VERSION) || \
     (FR_43_LLCE_IPW_SW_PATCH_VERSION != FLEXRAY_43_LLCE_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fr_43_LLCE_Ipw.h and Flexray_Ip.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                   GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define FR_43_LLCE_START_SEC_CODE
#include "Fr_43_LLCE_MemMap.h"

uint16 Fr_43_LLCE_Ipw_GetgNumberOfStaticSlots(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg);

uint8 Fr_43_LLCE_Ipw_GetgChannel(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg);

uint8 Fr_43_LLCE_Ipw_GetgPayloadLengthStatic(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg);

boolean Fr_43_LLCE_Ipw_Gettimer2IsRelative(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg);

Std_ReturnType Fr_43_LLCE_Ipw_ControllerInit(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg);

Std_ReturnType Fr_43_LLCE_Ipw_CheckCCAccess(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                    const boolean Fr_CC_Enabled
                                                   );

Std_ReturnType Fr_43_LLCE_Ipw_ClearDisableIRQs(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg);

void Fr_43_LLCE_Ipw_DisableTimers(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg);

Fr_POCStateType Fr_43_LLCE_Ipw_GetPOCState(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg);

Std_ReturnType Fr_43_LLCE_Ipw_GetPOCStatus(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                   Fr_POCStatusType* POCStatusPtr
                                                  );

Std_ReturnType Fr_43_LLCE_Ipw_InvokeCHICommand(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                       Flexray_Ip_ChiCmdType ChiCommand
                                                      );

void Fr_43_LLCE_Ipw_AckAbsoluteTimerIRQ(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                uint8 u8TimerIdx
                                               );

void Fr_43_LLCE_Ipw_CancelAbsoluteTimer(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                uint8 u8TimerIdx
                                               );

void Fr_43_LLCE_Ipw_DisableAbsoluteTimerIRQ(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                    uint8 u8TimerIdx
                                                   );

void Fr_43_LLCE_Ipw_EnableAbsoluteTimerIRQ(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                   uint8 u8TimerIdx
                                                  );

boolean Fr_43_LLCE_Ipw_GetAbsoluteTimerIRQStatus(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                         uint8 u8TimerIdx
                                                        );

void Fr_43_LLCE_Ipw_SetAbsoluteTimer(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                             uint8 u8TimerIdx,
                                             uint8 u8Cycle,
                                             uint16 u16Offset
                                            );

Std_ReturnType Fr_43_LLCE_Ipw_SetWakeupChannel(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                       Fr_ChannelType ChnlIdx
                                                      );

Std_ReturnType Fr_43_LLCE_Ipw_GetGlobalTime(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                    uint8* CyclePtr,
                                                    uint16* MacroTickPtr
                                                   );

Std_ReturnType Fr_43_LLCE_Ipw_GetNmVector(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                  uint8* NmVectorPtr,
                                                  boolean* CheckLen
                                                 );

void Fr_43_LLCE_Ipw_GetChannelStatus(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                             uint16* ChannelAStatusPtr,
                                             uint16* ChannelBStatusPtr
                                            );

Std_ReturnType Fr_43_LLCE_Ipw_GetClockCorrection(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                         sint16* RateCorrectionPtr,
                                                         sint32* OffsetCorrectionPtr
                                                        );

Std_ReturnType Fr_43_LLCE_Ipw_GetSyncFrameList(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                       uint8 u8ListSize,
                                                       uint16* ChannelAEvenListPtr,
                                                       uint16* ChannelBEvenListPtr,
                                                       uint16* ChannelAOddListPtr,
                                                       uint16* ChannelBOddListPtr
                                                      );

Std_ReturnType Fr_43_LLCE_Ipw_GetWakeupRxStatus(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                        uint8* WakeupRxStatusPtr
                                                       );

Std_ReturnType Fr_43_LLCE_Ipw_ReadbackCCConfig(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg);

Std_ReturnType Fr_43_LLCE_Ipw_TransmitTxLPdu(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                     uint16 u16LPduIdx,
                                                     const uint8* LsduPtr,
                                                     uint8 u8LsduLength,
                                                     Fr_SlotAssignmentType* SlotAssignmentPtr
                                                    );

Std_ReturnType Fr_43_LLCE_Ipw_ReceiveRxLPdu(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                    uint16 u16LPduIdx,
                                                    uint8* LsduPtr,
                                                    Fr_RxLPduStatusType* LPduStatusPtr,
                                                    uint8* LsduLengthPtr,
                                                    Fr_SlotAssignmentType* SlotAssignmentPtr
                                                   );

void Fr_43_LLCE_Ipw_ReceiveFifo(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                        uint16 u16LPduIdx,
                                        uint8* LsduPtr,
                                        Fr_RxLPduStatusType* LPduStatusPtr,
                                        uint8* LsduLengthPtr,
                                        Fr_SlotAssignmentType* SlotAssignmentPtr
                                       );

Std_ReturnType Fr_43_LLCE_Ipw_CheckTxLPduStatus(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                        uint16 u16LPduIdx,
                                                        Fr_TxLPduStatusType* TxLPduStatusPtr,
                                                        Fr_SlotAssignmentType* SlotAssignmentPtr
                                                       );

Std_ReturnType Fr_43_LLCE_Ipw_CheckLpduLengthTransmitTX(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                                uint16 u16LPduIdx,
                                                                uint8 u8LsduLength
                                                               );

Std_ReturnType Fr_43_LLCE_Ipw_CheckTXLpdu(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                  uint16 u16LPduIdx
                                                 );

#if (FR_43_LLCE_PREPARE_LPDU_SUPPORT == STD_ON)
Std_ReturnType Fr_43_LLCE_Ipw_PrepareLPdu(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                  uint16 u16LPduIdx
                                                 );
#endif /* FR_43_LLCE_PREPARE_LPDU_SUPPORT == STD_ON */

Std_ReturnType Fr_43_LLCE_Ipw_CancelTxLPdu(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                   uint16 u16LPduIdx,
                                                   boolean* PendingStatus
                                                  );

#if (FR_43_LLCE_RECONFIG_LPDU_SUPPORT == STD_ON)
Std_ReturnType Fr_43_LLCE_Ipw_ReconfigLPdu(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                   uint16 u16LPduIdx,
                                                   uint16 FrameId,
                                                   Fr_ChannelType ChnlIdx,
                                                   uint8 CycleRepetition,
                                                   uint8 CycleOffset,
                                                   uint8 PayloadLength,
                                                   uint16 HeaderCRC
                                                  );
#endif /* FR_43_LLCE_RECONFIG_LPDU_SUPPORT == STD_ON */

#if (FR_43_LLCE_DISABLE_LPDU_SUPPORT == STD_ON)
Std_ReturnType Fr_43_LLCE_Ipw_DisableLPdu(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                  uint16 u16LPduIdx
                                                 );
#endif

Std_ReturnType Fr_43_LLCE_Ipw_GetNumOfStartupFrames(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg,
                                                             uint8* NumOfStartupFramesPtr
                                                           );

#if (FR_43_LLCE_DEINIT_API == STD_ON)
Std_ReturnType Fr_43_LLCE_Ipw_DeInit(const Fr_43_LLCE_CtrlCfgType* pCtrlCfg);
#endif

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define FR_43_LLCE_STOP_SEC_CODE
#include "Fr_43_LLCE_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FR_43_LLCE_IPW_H */

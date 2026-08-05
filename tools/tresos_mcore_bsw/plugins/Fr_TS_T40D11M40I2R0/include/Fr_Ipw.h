/**
*   @file    Fr_Ipw.h
*   @version 4.0.2
*
*   @brief   AUTOSAR Fr - module interface.
*   @details Main header file - fr include different IPV models.
*   @implements  Fr_Ipw.h_Artifact
*
*   @addtogroup FR_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : FLEXRAY
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
*   Copyright 2020-2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
#ifndef FR_IPW_H
#define FR_IPW_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fr.h"
#include "Flexray_Ip.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
 * @brief Parameters that shall be published within the driver header file and also in the
 *        module's description file
 */
#define FR_IPW_MODULE_ID                        81
#define FR_IPW_VENDOR_ID                        43
#define FR_IPW_AR_RELEASE_MAJOR_VERSION         4
#define FR_IPW_AR_RELEASE_MINOR_VERSION         4
#define FR_IPW_AR_RELEASE_REVISION_VERSION      0
#define FR_IPW_SW_MAJOR_VERSION                 4
#define FR_IPW_SW_MINOR_VERSION                 0
#define FR_IPW_SW_PATCH_VERSION                 2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fr.h header file are of the same vendor */
#if(FR_IPW_VENDOR_ID != FR_VENDOR_ID)
    #error "Fr_Ipw.h and Fr.h have different Vendor IDs"
#endif
/* Check if current file and Fr.h header file are of the same Autosar version */
#if((FR_IPW_AR_RELEASE_MAJOR_VERSION    != FR_AR_RELEASE_MAJOR_VERSION) || \
    (FR_IPW_AR_RELEASE_MINOR_VERSION    != FR_AR_RELEASE_MINOR_VERSION) || \
    (FR_IPW_AR_RELEASE_REVISION_VERSION != FR_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Fr_Ipw.h and Fr.h are different"
#endif
/* Check if current file and Fr.h header file are of the same software version */
#if((FR_IPW_SW_MAJOR_VERSION != FR_SW_MAJOR_VERSION) || \
    (FR_IPW_SW_MINOR_VERSION != FR_SW_MINOR_VERSION) || \
    (FR_IPW_SW_PATCH_VERSION != FR_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fr_Ipw.h and Fr.h are different"
#endif

/* Check if current file and Flexray_Ip.h header file are of the same vendor */
#if(FR_IPW_VENDOR_ID != FLEXRAY_IP_VENDOR_ID)
    #error "Fr_Ipw.h and Flexray_Ip.h have different Vendor IDs"
#endif
/* Check if current file and Flexray_Ip.h header file are of the same Autosar version */
#if((FR_IPW_AR_RELEASE_MAJOR_VERSION    != FLEXRAY_IP_AR_RELEASE_MAJOR_VERSION) || \
    (FR_IPW_AR_RELEASE_MINOR_VERSION    != FLEXRAY_IP_AR_RELEASE_MINOR_VERSION) || \
    (FR_IPW_AR_RELEASE_REVISION_VERSION != FLEXRAY_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Fr_Ipw.h and Flexray_Ip.h are different"
#endif
/* Check if current file and Flexray_Ip.h header file are of the same software version */
#if((FR_IPW_SW_MAJOR_VERSION != FLEXRAY_IP_SW_MAJOR_VERSION) || \
    (FR_IPW_SW_MINOR_VERSION != FLEXRAY_IP_SW_MINOR_VERSION) || \
    (FR_IPW_SW_PATCH_VERSION != FLEXRAY_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fr_Ipw.h and Flexray_Ip.h are different"
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
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"

uint16 Fr_Ipw_GetgNumberOfStaticSlots ( const Fr_CtrlCfgType* pCtrlCfg);
uint8 Fr_Ipw_GetgChannel( const Fr_CtrlCfgType* pCtrlCfg);
uint8 Fr_Ipw_GetgPayloadLengthStatic( const Fr_CtrlCfgType* pCtrlCfg);
boolean Fr_Ipw_Gettimer2IsRelative ( const Fr_CtrlCfgType* pCtrlCfg);

Std_ReturnType Fr_Ipw_ControllerInit(const Fr_CtrlCfgType* pCtrlCfg);

Std_ReturnType Fr_Ipw_CheckCCAccess(const Fr_CtrlCfgType* pCtrlCfg, const boolean Fr_CC_enabled);

Std_ReturnType Fr_Ipw_ClearDisableIRQs(const Fr_CtrlCfgType* pCtrlCfg);

void Fr_Ipw_DisableTimers(const Fr_CtrlCfgType* pCtrlCfg);

Fr_POCStateType Fr_Ipw_GetPOCState(const Fr_CtrlCfgType* pCtrlCfg);

Std_ReturnType Fr_Ipw_GetPOCStatus(const Fr_CtrlCfgType* pCtrlCfg, Fr_POCStatusType* pocStatusPtr);

Std_ReturnType Fr_Ipw_InvokeCHICommand(const Fr_CtrlCfgType* pCtrlCfg, Flexray_Ip_ChiCmdType chiCommand);

void Fr_Ipw_AckAbsoluteTimerIRQ(const Fr_CtrlCfgType* pCtrlCfg, uint8 timerIdx);

void Fr_Ipw_CancelAbsoluteTimer(const Fr_CtrlCfgType* pCtrlCfg, uint8 timerIdx);

void Fr_Ipw_DisableAbsoluteTimerIRQ(const Fr_CtrlCfgType* pCtrlCfg, uint8 timerIdx);

void Fr_Ipw_EnableAbsoluteTimerIRQ(const Fr_CtrlCfgType* pCtrlCfg, uint8 timerIdx);

boolean Fr_Ipw_GetAbsoluteTimerIRQStatus(const Fr_CtrlCfgType* pCtrlCfg, uint8 timerIdx);

void Fr_Ipw_SetAbsoluteTimer(const Fr_CtrlCfgType* pCtrlCfg, uint8 timerIdx, uint8 cycle, uint16 offset);

Std_ReturnType Fr_Ipw_SetWakeupChannel(const Fr_CtrlCfgType* pCtrlCfg, Fr_ChannelType chnlIdx);

Std_ReturnType Fr_Ipw_GetGlobalTime(const Fr_CtrlCfgType* pCtrlCfg, uint8* cyclePtr, uint16* macroTickPtr);

Std_ReturnType Fr_Ipw_GetNmVector(const Fr_CtrlCfgType* pCtrlCfg, uint8* nmVectorPtr, boolean* checkLen);

void Fr_Ipw_GetChannelStatus( const Fr_CtrlCfgType* pCtrlCfg, uint16* channelAStatusPtr, uint16* channelBStatusPtr);

Std_ReturnType Fr_Ipw_GetClockCorrection( const Fr_CtrlCfgType* pCtrlCfg,sint16* rateCorrectionPtr, sint32* offsetCorrectionPtr);

Std_ReturnType Fr_Ipw_GetSyncFrameList(const Fr_CtrlCfgType* pCtrlCfg, uint8 listSize, uint16* channelAEvenListPtr, uint16* channelBEvenListPtr, uint16* channelAOddListPtr, uint16* channelBOddListPtr);

Std_ReturnType Fr_Ipw_GetWakeupRxStatus( const Fr_CtrlCfgType* pCtrlCfg, uint8* wakeupRxStatusPtr );

Std_ReturnType Fr_Ipw_ReadbackCCConfig(const Fr_CtrlCfgType* pCtrlCfg);

Std_ReturnType Fr_Ipw_TransmitTxLPdu(const Fr_CtrlCfgType* pCtrlCfg, uint16 lpduIdx, const uint8* lsduPtr, uint8 lsduLength, Fr_SlotAssignmentType* slotAssignmentPtr);
Std_ReturnType Fr_Ipw_ReceiveRxLPdu(const Fr_CtrlCfgType* pCtrlCfg, uint16 lpduIdx, uint8* lsduPtr, Fr_RxLPduStatusType* lpduStatusPtr, uint8* lsduLengthPtr, Fr_SlotAssignmentType* slotAssignmentPtr);
void Fr_Ipw_ReceiveFifo(const Fr_CtrlCfgType* pCtrlCfg, uint16 lpduIdx, uint8* lsduPtr, Fr_RxLPduStatusType* lpduStatusPtr, uint8* lsduLengthPtr, Fr_SlotAssignmentType* slotAssignmentPtr);
Std_ReturnType Fr_Ipw_CheckTxLPduStatus(const Fr_CtrlCfgType* pCtrlCfg, uint16 lpduIdx, Fr_TxLPduStatusType* txLPduStatusPtr, Fr_SlotAssignmentType* slotAssignmentPtr);

Std_ReturnType Fr_Ipw_CheckLpduLengthTransmitTX( const Fr_CtrlCfgType* pCtrlCfg, uint16 lpduIdx, uint8 lsduLength);
Std_ReturnType Fr_Ipw_CheckTXLpdu(const Fr_CtrlCfgType* pCtrlCfg, uint16 lpduIdx);

#if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
Std_ReturnType Fr_Ipw_PrepareLPdu ( const Fr_CtrlCfgType* pCtrlCfg, uint16 lpduIdx);
#endif /* FR_PREPARE_LPDU_SUPPORT == STD_ON */

Std_ReturnType Fr_Ipw_CancelTxLPdu (const Fr_CtrlCfgType* pCtrlCfg, uint16 lpduIdx, boolean* pendingStatus);

#if(FR_RECONFIG_LPDU_SUPPORT == STD_ON)
Std_ReturnType Fr_Ipw_ReconfigLPdu (const Fr_CtrlCfgType* pCtrlCfg, uint16 lpduIdx, uint16 frameId, Fr_ChannelType chnlIdx, uint8 cycleRepetition, uint8 cycleOffset, uint8 payloadLength, uint16 headerCRC);
#endif /* FR_RECONFIG_LPDU_SUPPORT == STD_ON */

#if(FR_DISABLE_LPDU_SUPPORT == STD_ON)
Std_ReturnType Fr_Ipw_DisableLPdu (const Fr_CtrlCfgType* pCtrlCfg, uint16 lpduIdx);
#endif

Std_ReturnType Fr_Ipw_GetNumOfStartupFrames ( const Fr_CtrlCfgType* pCtrlCfg, uint8* numOfStartupFramesPtr);


#if(FR_DEINIT_API == STD_ON)
Std_ReturnType Fr_Ipw_DeInit (const Fr_CtrlCfgType* pCtrlCfg);
#endif

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* FR_IPW_H */
/** @} */
/* End of file */

/**
*   @file    Can_43_LLCE_Externals.h
*   @implements Can_Externals.h_Artifact
*   @version 1.0.7
*
*   @brief   AUTOSAR Can_43_LLCE - module interface.
*   @details API header for CAN driver.
*
*   @addtogroup CAN_LLCE
*   @{
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : LLCE
*   Dependencies         : 
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 1.0.7
*   Build Version        : S32_RTD_1_0_7_D2909_ASR_REL_4_4_REV_0000_20230630
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
#ifndef CAN_43_LLCE_EXTERNALS_H
#define CAN_43_LLCE_EXTERNALS_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define CAN_43_LLCE_EXTERNALS_VENDOR_ID_H                       43
#define CAN_43_LLCE_EXTERNALS_MODULE_ID_H                       80
#define CAN_43_LLCE_EXTERNALS_AR_RELEASE_MAJOR_VERSION_H        4
#define CAN_43_LLCE_EXTERNALS_AR_RELEASE_MINOR_VERSION_H        4
#define CAN_43_LLCE_EXTERNALS_AR_RELEASE_REVISION_VERSION_H     0
#define CAN_43_LLCE_EXTERNALS_SW_MAJOR_VERSION_H                1
#define CAN_43_LLCE_EXTERNALS_SW_MINOR_VERSION_H                0
#define CAN_43_LLCE_EXTERNALS_SW_PATCH_VERSION_H                7

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define CAN_43_LLCE_START_SEC_CODE
#include "Can_43_LLCE_MemMap.h"
[!NOCODE!][!INDENT "0"!]
[!SELECT "CanGeneral"!]
    [!IF "node:exists(./CanLPduReceiveCalloutFunction)"!]
        [!IF "(normalize-space(./CanLPduReceiveCalloutFunction) != 'NULL_PTR')"!]
            [!CODE!]
            [!IF "((node:exists(./LPDUCalloutExtension)) and (./LPDUCalloutExtension ='true'))"!]
                boolean [!"normalize-space(./CanLPduReceiveCalloutFunction)"!](uint16 Hrh, Can_IdType CanId, uint8 CanDataLength, const uint8* CanSduPtr);[!CR!]
            [!ELSE!]
                boolean [!"normalize-space(./CanLPduReceiveCalloutFunction)"!](uint8 Hrh, Can_IdType CanId, uint8 CanDataLength, const uint8* CanSduPtr);[!CR!]
            [!ENDIF!]            
            #define Can_43_LLCE_LPduReceiveCalloutFunction     ([!"normalize-space(CanLPduReceiveCalloutFunction)"!])
            [!ENDCODE!]
        [!ENDIF!]
    [!ENDIF!]

    [!IF "node:exists(./RxTimestampNotification)"!]
        [!IF "(normalize-space(./RxTimestampNotification) != 'NULL_PTR')"!]
            [!CODE!]
            void [!"normalize-space(./RxTimestampNotification)"!](Can_HwHandleType Hoh, uint32 u32TimestampVal);[!CR!]
            #define Can_43_LLCE_RxTimestampNotification     ([!"normalize-space(RxTimestampNotification)"!])
            [!ENDCODE!]
        [!ENDIF!]
    [!ENDIF!]

    [!IF "node:exists(./TxTimestampNotification)"!]
        [!IF "(normalize-space(./TxTimestampNotification) != 'NULL_PTR')"!]
            [!CODE!]
            void [!"normalize-space(./TxTimestampNotification)"!](Can_HwHandleType Hoh, PduIdType CanTxPduId, uint32 u32TimestampVal);[!CR!]
            #define Can_43_LLCE_TxTimestampNotification     ([!"normalize-space(TxTimestampNotification)"!])
            [!ENDCODE!]
        [!ENDIF!]
    [!ENDIF!]

    [!IF "node:exists(./CanCustomRxFunction)"!]
        [!IF "(normalize-space(./CanCustomRxFunction) != 'NULL_PTR')"!]
            [!CODE!]
            boolean [!"normalize-space(./CanCustomRxFunction)"!](uint8 Hrh, Can_IdType CanId, uint8 CanDataLength, uint8* CanSduPtr, uint16 u16RxMbDescIdx);[!CR!]
            #define Can_43_LLCE_CustomRxCallback        ([!"normalize-space(CanCustomRxFunction)"!])
            [!ENDCODE!]
        [!ENDIF!]
    [!ENDIF!]

    [!IF "node:exists(./CanWriteCustomCallback)"!]
        [!IF "(normalize-space(./CanWriteCustomCallback) != 'NULL_PTR')"!]
            [!CODE!]
            void [!"normalize-space(./CanWriteCustomCallback)"!](Can_HwHandleType Hoh, PduIdType CanTxPduId, uint16 u16TxMbDescIdx);[!CR!]
            #define Can_43_LLCE_CustomWriteCallback        ([!"normalize-space(CanWriteCustomCallback)"!])
            [!ENDCODE!]
        [!ENDIF!]
    [!ENDIF!]

    [!IF "node:exists(./CanTxConfirmationCustomCallback)"!]
        [!IF "(normalize-space(./CanTxConfirmationCustomCallback) != 'NULL_PTR')"!]
            [!CODE!]
            void [!"normalize-space(./CanTxConfirmationCustomCallback)"!](Can_HwHandleType Hoh, PduIdType CanTxPduId);[!CR!]
            #define Can_43_LLCE_CustomTxConfirmationCallback        ([!"normalize-space(CanTxConfirmationCustomCallback)"!])
            [!ENDCODE!]
        [!ENDIF!]
    [!ENDIF!]

    [!IF "node:exists(./CanAuxFilterCallback)"!]
        [!IF "(normalize-space(./CanAuxFilterCallback) != 'NULL_PTR')"!]
            [!CODE!]
            void [!"normalize-space(./CanAuxFilterCallback)"!](uint16 u16FilterId, uint16 u16AuxSearchResult);[!CR!]
            #define Can_43_LLCE_CanAuxFilterCallback        ([!"normalize-space(CanAuxFilterCallback)"!])
            [!ENDCODE!]
        [!ENDIF!]
    [!ENDIF!]

    [!IF "node:exists(./BusOffNotification)"!]
        [!IF "(normalize-space(./BusOffNotification) != 'NULL_PTR')"!]
            [!CODE!]
            void [!"normalize-space(./BusOffNotification)"!](uint8 u8CanIfCtrlId);[!CR!]
            #define Can_43_LLCE_ControllerBusOffCallback        ([!"normalize-space(BusOffNotification)"!])
            [!ENDCODE!]
        [!ENDIF!]
    [!ENDIF!]

[!ENDSELECT!]

[!SELECT "CanConfigSet/CanErrorReporting"!]
    [!IF "node:exists(./CanErrorNotif)"!]
        [!IF "(normalize-space(./CanErrorNotif) != 'NULL_PTR')"!]
            [!CODE!]
            void [!"normalize-space(./CanErrorNotif)"!](CanErrorNotificationType* error);[!CR!]
            #define Can_43_LLCE_ErrorNotificationCallback     ([!"normalize-space(CanErrorNotif)"!])
            [!ENDCODE!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDSELECT!]


[!ENDINDENT!][!ENDNOCODE!]
#define CAN_43_LLCE_STOP_SEC_CODE
#include "Can_43_LLCE_MemMap.h"
#ifdef __cplusplus
}
#endif
#endif /* CAN_43_LLCE_EXTERNALS_H */
/** @} */

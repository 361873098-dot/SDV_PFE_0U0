/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : FLEXCAN
*   Dependencies         : 
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

#ifndef CAN_43_FLEXCAN_H
#define CAN_43_FLEXCAN_H

/**
*   @file    Can_43_FLEXCAN.h
*   @version 4.0.2
*
*   @brief   AUTOSAR Can - module interface.
*   @details API header for CAN driver.
*
*   @addtogroup CAN_DRIVER
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Can.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CAN_43_FLEXCAN_VENDOR_ID                   43
#define CAN_43_FLEXCAN_MODULE_ID                   80
#define CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION    4
#define CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION    4
#define CAN_43_FLEXCAN_AR_RELEASE_REVISION_VERSION 0
#define CAN_43_FLEXCAN_SW_MAJOR_VERSION            4
#define CAN_43_FLEXCAN_SW_MINOR_VERSION            0
#define CAN_43_FLEXCAN_SW_PATCH_VERSION            2
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Can header file are of the same vendor */
#if (CAN_43_FLEXCAN_VENDOR_ID != CAN_VENDOR_ID)
    #error "Can_43_FLEXCAN.h and Can.h have different vendor ids"
#endif
/* Check if current file and Can header file are of the same Autosar version */
#if ((CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION) || \
     (CAN_43_FLEXCAN_AR_RELEASE_REVISION_VERSION != CAN_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Can_43_FLEXCAN.h and Can.h are different"
#endif

/* Check if current file and Can header file are of the same software version */
#if ((CAN_43_FLEXCAN_SW_MAJOR_VERSION != CAN_SW_MAJOR_VERSION) || \
     (CAN_43_FLEXCAN_SW_MINOR_VERSION != CAN_SW_MINOR_VERSION) || \
     (CAN_43_FLEXCAN_SW_PATCH_VERSION != CAN_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Can_43_FLEXCAN.h and Can.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#if (CAN_VERSION_INFO_API == STD_ON)
    #define Can_43_FLEXCAN_GetVersionInfo Can_GetVersionInfo
#endif /* CAN_VERSION_INFO_API == STD_ON */

#define Can_43_FLEXCAN_Init Can_Init

#define Can_43_FLEXCAN_DeInit Can_DeInit

#if (CAN_SET_BAUDRATE_API == STD_ON)
    #define Can_43_FLEXCAN_SetBaudrate Can_SetBaudrate
#endif /* CAN_SET_BAUDRATE_API == STD_ON */

#define Can_43_FLEXCAN_SetControllerMode Can_SetControllerMode

#if (CAN_LISTEN_ONLY_MODE == STD_ON)
#define Can_43_FLEXCAN_ListenOnlyMode Can_ListenOnlyMode
#endif /* (CAN_LISTEN_ONLY_MODE == STD_ON) */

#define Can_43_FLEXCAN_DisableControllerInterrupts Can_DisableControllerInterrupts

#define Can_43_FLEXCAN_EnableControllerInterrupts Can_EnableControllerInterrupts

#if (CAN_CHECK_WAKEUP_API == STD_ON)
    #define Can_43_FLEXCAN_CheckWakeup Can_CheckWakeup
#endif

#define Can_43_FLEXCAN_GetControllerErrorState Can_GetControllerErrorState

#define Can_43_FLEXCAN_GetControllerMode Can_GetControllerMode

#define Can_43_FLEXCAN_GetControllerRxErrorCounter Can_GetControllerRxErrorCounter

#define Can_43_FLEXCAN_GetControllerTxErrorCounter Can_GetControllerTxErrorCounter

#define Can_43_FLEXCAN_Write Can_Write

#if (CAN_ABORT_MB_API == STD_ON)
    #define Can_43_FLEXCAN_AbortMb Can_AbortMb
#endif /* CAN_ABORT_MB_API == STD_ON */

#if (CAN_DUAL_CLOCK_MODE == STD_ON)
    #define Can_43_FLEXCAN_SetClockMode Can_SetClockMode
#endif

#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
#define Can_43_FLEXCAN_SetIcomConfiguration Can_SetIcomConfiguration
#endif /* (CAN_PUBLIC_ICOM_SUPPORT == STD_ON) */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CAN_43_FLEXCAN_H */

/**
*   @file    Lin_43_LLCE_IPW.h
*   @version 1.0.7
*
*   @brief   AUTOSAR Lin_43_LLCE - Isolation level header file for LIN driver.
*   @details Header file for function definition on isolation level between high and low level driver.
*
*   @addtogroup LIN_LLCE
*   @{
*/
/*==================================================================================================
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
*   Copyright 2006-2016 Freescale Semiconductor, Inc.
*   Copyright 2020-2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly in
*   accordance with the applicable license terms.
*   By expressly accepting such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to comply with and are bound
*   by, such license terms.  If you do not agree to be bound by the applicable license terms, then you
*   may not retain, install, activate or otherwise use the software.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef LIN_43_LLCE_IPW_H
#define LIN_43_LLCE_IPW_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Lin_Llce.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LIN_43_LLCE_IPW_VENDOR_ID                    43
#define LIN_43_LLCE_IPW_AR_RELEASE_MAJOR_VERSION     4
#define LIN_43_LLCE_IPW_AR_RELEASE_MINOR_VERSION     4
#define LIN_43_LLCE_IPW_AR_RELEASE_REVISION_VERSION  0
#define LIN_43_LLCE_IPW_SW_MAJOR_VERSION             1
#define LIN_43_LLCE_IPW_SW_MINOR_VERSION             0
#define LIN_43_LLCE_IPW_SW_PATCH_VERSION             7
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Lin_Llce header file are of the same vendor */
#if (LIN_43_LLCE_IPW_VENDOR_ID != LIN_LLCE_VENDOR_ID)
    #error "Lin_43_LLCE_IPW.h and Lin_Llce.h have different vendor ids"
#endif
/* Check if current file and Lin_Llce header file are of the same Autosar version */
#if ((LIN_43_LLCE_IPW_AR_RELEASE_MAJOR_VERSION    != LIN_LLCE_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_43_LLCE_IPW_AR_RELEASE_MINOR_VERSION    != LIN_LLCE_AR_RELEASE_MINOR_VERSION) || \
     (LIN_43_LLCE_IPW_AR_RELEASE_REVISION_VERSION != LIN_LLCE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_43_LLCE_IPW.h and Lin_Llce.h are different"
#endif
/* Check if current file and Lin_Llce header file are of the same Software version */
#if ((LIN_43_LLCE_IPW_SW_MAJOR_VERSION != LIN_LLCE_SW_MAJOR_VERSION) || \
     (LIN_43_LLCE_IPW_SW_MINOR_VERSION != LIN_LLCE_SW_MINOR_VERSION) || \
     (LIN_43_LLCE_IPW_SW_PATCH_VERSION != LIN_LLCE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_43_LLCE_IPW.h and Lin_Llce.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#define    Lin_43_LLCE_Ipw_CheckWakeup(Controller)                  Lin_Llce_CheckWakeup(Controller)
#define    Lin_43_LLCE_Ipw_Init()                                   Lin_Llce_Init()

#if (LIN_43_LLCE_MASTER_NODE_USED == STD_ON)
    #define    Lin_43_LLCE_Ipw_SendFrame(Controller, PduInfo)           Lin_Llce_SendFrame(Controller, PduInfo)
    #define    Lin_43_LLCE_Ipw_GoToSleep(Controller)                    Lin_Llce_GoToSleep(Controller)
    #define    Lin_43_LLCE_Ipw_HardwareGetStatus(Controller, SduPtr)    Lin_Llce_HardwareGetStatus(Controller, SduPtr)
#endif /* #if LIN_43_LLCE_MASTER_NODE_USED == STD_ON */


#define    Lin_43_LLCE_Ipw_GoToSleepInternal(Controller)            Lin_Llce_GoToSleepInternal(Controller)
#define    Lin_43_LLCE_Ipw_WakeUp(Controller)                       Lin_Llce_WakeUp(Controller)
#define    Lin_43_LLCE_Ipw_WakeUpInternal(Controller)               Lin_Llce_WakeupInternal(Controller)

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LIN_43_LLCE_IPW_H */

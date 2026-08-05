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

#ifndef FLEXRAY_IP_TRUSTEDFUNCTIONS_H
#define FLEXRAY_IP_TRUSTEDFUNCTIONS_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "Flexray_43_LLCE_Ip_Types.h"
#include "Flexray_43_LLCE_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
 * @brief Parameters that shall be published within the driver header file and also in the
 *        module's description file
 */

#define FLEXRAY_IP_TRUSTEDFUNCTIONS_MODULE_ID                        81
#define FLEXRAY_IP_TRUSTEDFUNCTIONS_VENDOR_ID                        43
#define FLEXRAY_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION         4
#define FLEXRAY_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION         4
#define FLEXRAY_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION      0
#define FLEXRAY_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION                 1
#define FLEXRAY_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION                 0
#define FLEXRAY_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION                 7

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Flexray_43_LLCE_Ip_Types.h header file are of the same vendor */
#if (FLEXRAY_IP_TRUSTEDFUNCTIONS_VENDOR_ID != FLEXRAY_IP_TYPES_VENDOR_ID)
    #error "Flexray_Ip_TrustedFunctions.h and Flexray_43_LLCE_Ip_Types.h have different Vendor IDs"
#endif
/* Check if current file and Flexray_43_LLCE_Ip_Types.h header file are of the same Autosar version */
#if ((FLEXRAY_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION    != FLEXRAY_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXRAY_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION    != FLEXRAY_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FLEXRAY_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != FLEXRAY_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "Software Version Numbers of Flexray_Ip_TrustedFunctions.h and Flexray_43_LLCE_Ip_Types.h are different"
#endif
/* Check if current file and Flexray_43_LLCE_Ip_Types.h header file are of the same software version */
#if ((FLEXRAY_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != FLEXRAY_IP_TYPES_SW_MAJOR_VERSION) || \
     (FLEXRAY_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != FLEXRAY_IP_TYPES_SW_MINOR_VERSION) || \
     (FLEXRAY_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != FLEXRAY_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Autosar Version Numbers of Flexray_Ip_TrustedFunctions.h and Flexray_43_LLCE_Ip_Types.h are different"
#endif

/* Check if current file and Flexray_43_LLCE_Ip_Cfg.h header file are of the same vendor */
#if (FLEXRAY_IP_TRUSTEDFUNCTIONS_VENDOR_ID != FLEXRAY_IP_CFG_VENDOR_ID)
    #error "Flexray_Ip_TrustedFunctions.h and Flexray_43_LLCE_Ip_Cfg.h have different Vendor IDs"
#endif
/* Check if current file and Flexray_43_LLCE_Ip_Cfg.h header file are of the same Autosar version */
#if ((FLEXRAY_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION    != FLEXRAY_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXRAY_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION    != FLEXRAY_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (FLEXRAY_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != FLEXRAY_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "Software Version Numbers of Flexray_Ip_TrustedFunctions.h and Flexray_43_LLCE_Ip_Cfg.h are different"
#endif
/* Check if current file and Flexray_43_LLCE_Ip_Cfg.h header file are of the same software version */
#if ((FLEXRAY_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != FLEXRAY_IP_CFG_SW_MAJOR_VERSION) || \
     (FLEXRAY_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != FLEXRAY_IP_CFG_SW_MINOR_VERSION) || \
     (FLEXRAY_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != FLEXRAY_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Autosar Version Numbers of Flexray_Ip_TrustedFunctions.h and Flexray_43_LLCE_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes.h header file are of the same Autosar version */
    #if ((FLEXRAY_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXRAY_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Flexray_Ip_TrustedFunctions.h and StandardTypes.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                   FUNCTION PROTOTYPES
==================================================================================================*/
#define FR_43_LLCE_START_SEC_CODE
#include "Fr_43_LLCE_MemMap.h"

#ifdef FLEXRAY_43_LLCE_SET_USER_ACCESS_ALLOWED_AVAILABLE
#if (STD_ON == FLEXRAY_43_LLCE_SET_USER_ACCESS_ALLOWED_AVAILABLE)
extern void Flexray_43_LLCE_Ip_SetUserAccessAllowed(const FLEXRAY_Type *base);
extern void Flexray_43_LLCE_Ip_ClrUserAccessAllowed(const FLEXRAY_Type *base);
#endif
#endif

#define FR_43_LLCE_STOP_SEC_CODE
#include "Fr_43_LLCE_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXRAY_IP_TRUSTEDFUNCTIONS_H */

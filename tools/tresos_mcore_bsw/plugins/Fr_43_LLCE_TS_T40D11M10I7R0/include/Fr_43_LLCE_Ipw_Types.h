/**
*   @file    Fr_43_LLCE_Ipw_Types.h
*   @version 1.0.7
*
*   @brief   AUTOSAR Fr_43_LLCE - module interface.
*   @details Adds structures and other typedefs.
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
#ifndef FR_43_LLCE_IPW_TYPES_H
#define FR_43_LLCE_IPW_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Flexray_43_LLCE_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
 * @brief Parameters that shall be published within the driver header file and also in the
 *        module's description file
 */
#define FR_43_LLCE_IPW_TYPES_VENDOR_ID                        43
#define FR_43_LLCE_IPW_TYPES_AR_RELEASE_MAJOR_VERSION         4
#define FR_43_LLCE_IPW_TYPES_AR_RELEASE_MINOR_VERSION         4
#define FR_43_LLCE_IPW_TYPES_AR_RELEASE_REVISION_VERSION      0
#define FR_43_LLCE_IPW_TYPES_SW_MAJOR_VERSION                 1
#define FR_43_LLCE_IPW_TYPES_SW_MINOR_VERSION                 0
#define FR_43_LLCE_IPW_TYPES_SW_PATCH_VERSION                 7

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Flexray_Ip_Types.h header file are of the same vendor */
#if (FR_43_LLCE_IPW_TYPES_VENDOR_ID != FLEXRAY_IP_TYPES_VENDOR_ID)
    #error "Fr_43_LLCE_Ipw_Types.h and Flexray_Ip_Types.h have different Vendor IDs"
#endif
/* Check if current file and Flexray_Ip.h header file are of the same Autosar version */
#if ((FR_43_LLCE_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != FLEXRAY_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FR_43_LLCE_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != FLEXRAY_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FR_43_LLCE_IPW_TYPES_AR_RELEASE_REVISION_VERSION != FLEXRAY_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fr_43_LLCE_Ipw_Types.h and Flexray_Ip_Types.h are different"
#endif
/* Check if current file and Flexray_Ip.h header file are of the same software version */
#if ((FR_43_LLCE_IPW_TYPES_SW_MAJOR_VERSION != FLEXRAY_IP_TYPES_SW_MAJOR_VERSION) || \
     (FR_43_LLCE_IPW_TYPES_SW_MINOR_VERSION != FLEXRAY_IP_TYPES_SW_MINOR_VERSION) || \
     (FR_43_LLCE_IPW_TYPES_SW_PATCH_VERSION != FLEXRAY_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fr_43_LLCE_Ipw_Types.h and Flexray_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef Flexray_Ip_ConfigType Fr_43_LLCE_Ipw_Types_ConfigType;
typedef Flexray_Ip_StateAllocateType Fr_43_LLCE_Ipw_Types_StateAllocateType;

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FR_43_LLCE_IPW_TYPES_H */

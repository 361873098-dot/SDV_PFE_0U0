/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.0
*   Build Version        : S32_RTD_4_0_0_D2210_ASR_REL_4_4_REV_0000_20221031
*
*   (c) Copyright 2022 NXP Semiconductors
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

#ifndef MPU_M7_IP_CFG_H
#define MPU_M7_IP_CFG_H

/**
*   @file Mpu_M7_Ip_Cfg.h
*
*   @addtogroup Mpu_M7_Ip Mpu M7 IPV Driver
*   @{
*/


/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Mpu_M7_Ip_Types.h"
#include "Mpu_M7_Ip_Cfg_Defines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_MPU_M7_IP_CFG_VENDOR_ID                    43
#define RM_MPU_M7_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define RM_MPU_M7_IP_CFG_AR_RELEASE_MINOR_VERSION     4
#define RM_MPU_M7_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define RM_MPU_M7_IP_CFG_SW_MAJOR_VERSION             4
#define RM_MPU_M7_IP_CFG_SW_MINOR_VERSION             0
#define RM_MPU_M7_IP_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Mpu_M7_Ip_Types.h */
#if (RM_MPU_M7_IP_CFG_VENDOR_ID != RM_MPU_M7_IP_TYPES_VENDOR_ID)
    #error "Mpu_M7_Ip_Cfg.h and Mpu_M7_Ip_Types.h have different vendor ids"
#endif
#if (( RM_MPU_M7_IP_CFG_AR_RELEASE_MAJOR_VERSION    != RM_MPU_M7_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     ( RM_MPU_M7_IP_CFG_AR_RELEASE_MINOR_VERSION    != RM_MPU_M7_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     ( RM_MPU_M7_IP_CFG_AR_RELEASE_REVISION_VERSION != RM_MPU_M7_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Mpu_M7_Ip_Cfg.h and Mpu_M7_Ip_Types.h are different"
#endif
#if (( RM_MPU_M7_IP_CFG_SW_MAJOR_VERSION != RM_MPU_M7_IP_TYPES_SW_MAJOR_VERSION) || \
     ( RM_MPU_M7_IP_CFG_SW_MINOR_VERSION != RM_MPU_M7_IP_TYPES_SW_MINOR_VERSION) || \
     ( RM_MPU_M7_IP_CFG_SW_PATCH_VERSION != RM_MPU_M7_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mpu_M7_Ip_Cfg.h and Mpu_M7_Ip_Types.h are different"
#endif

/* Checks against Mpu_M7_Ip_Cfg_Defines.h */
#if (RM_MPU_M7_IP_CFG_VENDOR_ID != RM_MPU_M7_IP_CFG_DEFINES_VENDOR_ID)
    #error "Mpu_M7_Ip_Cfg.h and Mpu_M7_Ip_Cfg_Defines.h have different vendor ids"
#endif
#if (( RM_MPU_M7_IP_CFG_AR_RELEASE_MAJOR_VERSION    != RM_MPU_M7_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     ( RM_MPU_M7_IP_CFG_AR_RELEASE_MINOR_VERSION    != RM_MPU_M7_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     ( RM_MPU_M7_IP_CFG_AR_RELEASE_REVISION_VERSION != RM_MPU_M7_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Mpu_M7_Ip_Cfg.h and Mpu_M7_Ip_Cfg_Defines.h are different"
#endif
#if (( RM_MPU_M7_IP_CFG_SW_MAJOR_VERSION != RM_MPU_M7_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     ( RM_MPU_M7_IP_CFG_SW_MINOR_VERSION != RM_MPU_M7_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     ( RM_MPU_M7_IP_CFG_SW_PATCH_VERSION != RM_MPU_M7_IP_CFG_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mpu_M7_Ip_Cfg.h and Mpu_M7_Ip_Cfg_Defines.h are different"
#endif

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/



/** @} */

#endif /* MPU_M7_IP_CFG_H */


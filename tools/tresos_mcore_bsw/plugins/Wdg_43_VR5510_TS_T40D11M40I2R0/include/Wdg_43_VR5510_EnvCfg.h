/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : VR5510
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
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

#ifndef WDG_43_VR5510_ENVCFG_H
#define WDG_43_VR5510_ENVCFG_H

/**
*   @file Wdg_43_VR5510_EnvCfg.h
*
*   @addtogroup Wdg_VR5510_HLD
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDG_VR5510_ENVCFG_VENDOR_ID                        43
#define WDG_VR5510_ENVCFG_MODULE_ID                        102
#define WDG_VR5510_ENVCFG_AR_RELEASE_MAJOR_VERSION         4
#define WDG_VR5510_ENVCFG_AR_RELEASE_MINOR_VERSION         4
#define WDG_VR5510_ENVCFG_AR_RELEASE_REVISION_VERSION      0
#define WDG_VR5510_ENVCFG_SW_MAJOR_VERSION                 4
#define WDG_VR5510_ENVCFG_SW_MINOR_VERSION                 0
#define WDG_VR5510_ENVCFG_SW_PATCH_VERSION                 2
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

#define WDG_43_VR5510_VALIDATE_GLOBAL_CALL         (WDG_43_VR5510_DEV_ERROR_DETECT)
#define WDG_43_VR5510_VALIDATE_PARAMS              (WDG_43_VR5510_DEV_ERROR_DETECT)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* WDG_43_VR5510_ENVCFG_H */

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

#ifndef WDG_43_VR5510_CFG_EXT_H
#define WDG_43_VR5510_CFG_EXT_H

/**
*   @file     Wdg_43_VR5510_CfgExt.h
*
*   @addtogroup  Wdg_VR5510
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
#include "Wdg_43_VR5510.h"
#include "Mcal.h"
[!INCLUDE "Wdg_VR5510_PluginMacros.m"!][!//
[!INCLUDE "Wdg_VR5510_VersionCheck_Inc.m"!][!//
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDG_43_VR5510_CFG_EXT_VENDOR_ID                    43
#define WDG_43_VR5510_CFG_EXT_MODULE_ID                    102
#define WDG_43_VR5510_CFG_EXT_AR_RELEASE_MAJOR_VERSION     4
#define WDG_43_VR5510_CFG_EXT_AR_RELEASE_MINOR_VERSION     4
#define WDG_43_VR5510_CFG_EXT_AR_RELEASE_REVISION_VERSION  0
#define WDG_43_VR5510_CFG_EXT_SW_MAJOR_VERSION             4
#define WDG_43_VR5510_CFG_EXT_SW_MINOR_VERSION             0
#define WDG_43_VR5510_CFG_EXT_SW_PATCH_VERSION             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Wdg_43_VR5510 header file are of the same vendor */
#if (WDG_43_VR5510_CFG_EXT_VENDOR_ID != WDG_43_VR5510_VENDOR_ID)
    #error "Wdg_VR5510_CfgExt.h and Wdg_43_VR5510.h have different vendor ids"
#endif

/* Check if current file and Wdg_43_VR5510 header file are of the same Autosar version */
#if ((WDG_43_VR5510_CFG_EXT_AR_RELEASE_MAJOR_VERSION    != WDG_43_VR5510_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_43_VR5510_CFG_EXT_AR_RELEASE_MINOR_VERSION    != WDG_43_VR5510_AR_RELEASE_MINOR_VERSION) || \
     (WDG_43_VR5510_CFG_EXT_AR_RELEASE_REVISION_VERSION != WDG_43_VR5510_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AutoSar Version Numbers of Wdg_VR5510_CfgExt.h and Wdg_43_VR5510.h are different"
#endif
/* Check if current file and Wdg_43_VR5510 header file are of the same Software version */
#if ((WDG_43_VR5510_CFG_EXT_SW_MAJOR_VERSION != WDG_43_VR5510_SW_MAJOR_VERSION) || \
     (WDG_43_VR5510_CFG_EXT_SW_MINOR_VERSION != WDG_43_VR5510_SW_MINOR_VERSION) || \
     (WDG_43_VR5510_CFG_EXT_SW_PATCH_VERSION != WDG_43_VR5510_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Wdg_VR5510_CfgExt.h and Wdg_43_VR5510.h are different"
#endif

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/
#define WDG_43_VR5510_START_SEC_CONST_UNSPECIFIED
#include "Wdg_43_VR5510_MemMap.h"

[!NOCODE!]
[!IF "IMPLEMENTATION_CONFIG_VARIANT='VariantPreCompile' or IMPLEMENTATION_CONFIG_VARIANT='VariantLinkTime' "!]
  [!IF "variant:size()<=1"!]
[!CODE!]
#if (WDG_43_VR5510_PRECOMPILE_SUPPORT == STD_ON)[!CR!]
extern const Wdg_43_VR5510_ConfigType Wdg_VR5510_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!];

#define Wdg_VR5510_PBCfgVariantPredefined Wdg_VR5510_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!];
#endif
[!ENDCODE!]
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

#if (STD_OFF == WDG_43_VR5510_DISABLE_DEM_REPORT_ERROR_STATUS)
extern const Wdg_VR5510_DemConfigType Wdg_VR5510_DemConfig;
#endif

#define WDG_43_VR5510_STOP_SEC_CONST_UNSPECIFIED
#include "Wdg_43_VR5510_MemMap.h"
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

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
*                                   FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* WDG_43_VR5510_CFG_EXT_H */

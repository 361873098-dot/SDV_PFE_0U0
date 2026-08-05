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

#ifndef Wdg_43_VR5510[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H
#define Wdg_43_VR5510[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H

/**
*   @file Wdg_43_VR5510[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h
*
*   @addtogroup Wdg_VR5510
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
* 4) user callback header files
==================================================================================================*/

#include "Wdg_43_VR5510_IPW_Types.h"

/*==================================================================================================
                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WDG_43_VR5510_PBCFG_VENDOR_ID                    43
#define WDG_43_VR5510_PBCFG_MODULE_ID                    102
#define WDG_43_VR5510_PBCFG_AR_RELEASE_MAJOR_VERSION     4
#define WDG_43_VR5510_PBCFG_AR_RELEASE_MINOR_VERSION     4
#define WDG_43_VR5510_PBCFG_AR_RELEASE_REVISION_VERSION  0
#define WDG_43_VR5510_PBCFG_SW_MAJOR_VERSION             4
#define WDG_43_VR5510_PBCFG_SW_MINOR_VERSION             0
#define WDG_43_VR5510_PBCFG_SW_PATCH_VERSION             2

/*==================================================================================================
                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Wdg_43_VR5510 header file are of the same vendor */
#if (WDG_43_VR5510_PBCFG_VENDOR_ID != WDG_43_VR5510_IPW_TYPES_VENDOR_ID)
    #error "Wdg_43_VR5510_PBCfg.h and Wdg_43_IPW_Types.h have different vendor ids"
#endif

/* Check if source file and Wdg_43_VR5510 header file are of the same Autosar version */
#if ((WDG_43_VR5510_PBCFG_AR_RELEASE_MAJOR_VERSION != WDG_43_VR5510_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_43_VR5510_PBCFG_AR_RELEASE_MINOR_VERSION != WDG_43_VR5510_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (WDG_43_VR5510_PBCFG_AR_RELEASE_REVISION_VERSION != WDG_43_VR5510_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wdg_43_VR5510_PBCfg.h and Wdg_43_IPW_Types.h are different"
#endif
/* Check if source file and Wdg_43_VR5510 header file are of the same Software version */
#if ((WDG_43_VR5510_PBCFG_SW_MAJOR_VERSION != WDG_43_VR5510_IPW_TYPES_SW_MAJOR_VERSION) || \
     (WDG_43_VR5510_PBCFG_SW_MINOR_VERSION != WDG_43_VR5510_IPW_TYPES_SW_MINOR_VERSION) || \
     (WDG_43_VR5510_PBCFG_SW_PATCH_VERSION != WDG_43_VR5510_IPW_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Wdg_43_VR5510_PBCfg.h and Wdg_43_IPW_Types.h are different"
#endif


/*==================================================================================================
                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

[!NOCODE!]
[!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild' or (variant:size()>1))"!][!//
[!CODE!][!//
#define WDG_43_VR5510_START_SEC_CONFIG_DATA_UNSPECIFIED
 /**
 * @brief Include Memory mapping specification
 */
#include "Wdg_43_VR5510_MemMap.h"
[!ENDCODE!][!//
[!IF "var:defined('postBuildVariant')"!][!//
  [!VAR "postBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!][!//
[!CODE!]#define WDG_43_VR5510_CONFIG_[!"$postBuildVariant"!]_PB \[!CR!][!ENDCODE!]
[!ELSE!][!//
  [!VAR "postBuildVariantNameUnderscore" = "string(null)"!][!//
[!CODE!]#define WDG_43_VR5510_CONFIG_PB \[!CR!][!ENDCODE!]
[!ENDIF!][!//
[!CODE!]    extern const Wdg_43_VR5510_ConfigType Wdg_VR5510_Config[!"$postBuildVariantNameUnderscore"!];
#define WDG_43_VR5510_STOP_SEC_CONFIG_DATA_UNSPECIFIED
 /**
 * @brief Include Memory mapping specification
 */
#include "Wdg_43_VR5510_MemMap.h"
[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* Wdg_43_VR5510[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H */

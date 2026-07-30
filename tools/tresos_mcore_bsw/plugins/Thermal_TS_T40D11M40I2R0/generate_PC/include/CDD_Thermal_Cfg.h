[!CODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : TMU
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
*   Copyright 2020-2023 NXP Semiconductors
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

#ifndef CDD_THERMAL_CFG_H
#define CDD_THERMAL_CFG_H

/**
*   @file
*
*   @addtogroup thermal_driver_config Thermal Driver Configuration
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
[!NOCODE!][!//
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!]#include "CDD_Thermal_[!"."!]_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!]#include "CDD_Thermal_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDIF!]

[!INCLUDE "Thermal_VersionCheck_Inc.m"!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define THERMAL_VENDOR_ID_CFG                    43
#define THERMAL_MODULE_ID_CFG                    255
#define THERMAL_AR_RELEASE_MAJOR_VERSION_CFG     4
#define THERMAL_AR_RELEASE_MINOR_VERSION_CFG     4
#define THERMAL_AR_RELEASE_REVISION_VERSION_CFG  0
#define THERMAL_SW_MAJOR_VERSION_CFG             4
#define THERMAL_SW_MINOR_VERSION_CFG             0
#define THERMAL_SW_PATCH_VERSION_CFG             2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against StandardTypes.h */
    #if ((THERMAL_AR_RELEASE_MAJOR_VERSION_CFG != STD_AR_RELEASE_MAJOR_VERSION) || \
         (THERMAL_AR_RELEASE_MINOR_VERSION_CFG != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of CDD_Thermal_Cfg.h and StandardTypes.h are different"
    #endif
#endif

[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
#if ((THERMAL_AR_RELEASE_MAJOR_VERSION_CFG != THERMAL_AR_RELEASE_MAJOR_VERSION_[!"text:toupper(.)"!]_PBCFG_H) || \
     (THERMAL_AR_RELEASE_MINOR_VERSION_CFG != THERMAL_AR_RELEASE_MINOR_VERSION_[!"text:toupper(.)"!]_PBCFG_H) || \
     (THERMAL_AR_RELEASE_REVISION_VERSION_CFG != THERMAL_AR_RELEASE_REVISION_VERSION_[!"text:toupper(.)"!]_PBCFG_H) \
    )
    #error "AutoSar Version Numbers of CDD_Thermal_Cfg.h and CDD_Thermal_[!"."!]_PBcfg.h are different"
#endif

#if ((THERMAL_SW_MAJOR_VERSION_CFG != THERMAL_SW_MAJOR_VERSION_[!"text:toupper(.)"!]_PBCFG_H) || \
     (THERMAL_SW_MINOR_VERSION_CFG != THERMAL_SW_MINOR_VERSION_[!"text:toupper(.)"!]_PBCFG_H) || \
     (THERMAL_SW_PATCH_VERSION_CFG != THERMAL_SW_PATCH_VERSION_[!"text:toupper(.)"!]_PBCFG_H) \
    )
    #error "Software Version Numbers of CDD_Thermal_Cfg.h and CDD_Thermal_[!"."!]_PBcfg.h are different"
#endif

#if (THERMAL_VENDOR_ID_CFG != THERMAL_VENDOR_ID_[!"text:toupper(.)"!]_PBCFG_H)
    #error "CDD_Thermal_Cfg.h and CDD_Thermal_[!"."!]_PBcfg.h have different vendor ids"
#endif
[!ENDLOOP!][!//
[!ELSE!][!//
#if ((THERMAL_AR_RELEASE_MAJOR_VERSION_CFG != THERMAL_AR_RELEASE_MAJOR_VERSION_PBCFG_H) || \
     (THERMAL_AR_RELEASE_MINOR_VERSION_CFG != THERMAL_AR_RELEASE_MINOR_VERSION_PBCFG_H) || \
     (THERMAL_AR_RELEASE_REVISION_VERSION_CFG != THERMAL_AR_RELEASE_REVISION_VERSION_PBCFG_H) \
    )
    #error "AutoSar Version Numbers of CDD_Thermal_Cfg.h and CDD_Thermal_PBcfg.h are different"
#endif

#if ((THERMAL_SW_MAJOR_VERSION_CFG != THERMAL_SW_MAJOR_VERSION_PBCFG_H) || \
     (THERMAL_SW_MINOR_VERSION_CFG != THERMAL_SW_MINOR_VERSION_PBCFG_H) || \
     (THERMAL_SW_PATCH_VERSION_CFG != THERMAL_SW_PATCH_VERSION_PBCFG_H) \
    )
    #error "Software Version Numbers of CDD_Thermal_Cfg.h and CDD_Thermal_PBcfg.h are different"
#endif

#if (THERMAL_VENDOR_ID_CFG != THERMAL_VENDOR_ID_PBCFG_H)
    #error "CDD_Thermal_Cfg.h and CDD_Thermal_PBcfg.h have different vendor ids"
#endif
[!ENDIF!]
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!IF "not((IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and (variant:size() <= 1))"!][!//
#define THERMAL_CONFIG_EXT \
[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
THERMAL_CONFIG_[!"."!]_PB \
[!ENDLOOP!][!//
[!ELSE!][!//
THERMAL_CONFIG_PB
[!ENDIF!][!//
[!ENDIF!][!// Support for Post Build only
/*==================================================================================================
*                                              ENUMS
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

#endif /* CDD_THERMAL_CFG_H */
[!ENDCODE!][!//


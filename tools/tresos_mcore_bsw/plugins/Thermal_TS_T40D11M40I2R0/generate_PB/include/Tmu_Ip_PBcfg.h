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

#ifndef TMU_IP_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H
#define TMU_IP_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H

/**
*   @file
*
*   @addtogroup tmu_ip_config TMU IPL Configuration
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
#include "Tmu_Ip_Types.h"
[!NOCODE!][!//
[!INCLUDE "Thermal_VersionCheck_Src.m"!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define TMU_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H                    43
#define TMU_IP_MODULE_ID_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H                    255
#define TMU_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H     4
#define TMU_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H     4
#define TMU_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H  0
#define TMU_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H             4
#define TMU_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H             0
#define TMU_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H             2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#if ((TMU_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H != TMU_IP_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (TMU_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H != TMU_IP_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (TMU_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H != TMU_IP_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of Tmu_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Tmu_Ip_Types.h are different"
#endif

#if ((TMU_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H != TMU_IP_SW_MAJOR_VERSION_TYPES) || \
     (TMU_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H != TMU_IP_SW_MINOR_VERSION_TYPES) || \
     (TMU_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H != TMU_IP_SW_PATCH_VERSION_TYPES) \
    )
    #error "Software Version Numbers of Tmu_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Tmu_Ip_Types.h are different"
#endif

#if (TMU_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H != TMU_IP_VENDOR_ID_TYPES)
    #error "Tmu_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and Tmu_Ip_Types.h have different vendor ids"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define THERMAL_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Thermal_MemMap.h"

[!NOCODE!][!//
[!VAR "VariantsNo" = "variant:size()"!]
[!CODE!][!//
/**
* @brief          Tmu Ip configuration[!IF "var:defined('postBuildVariant')"!] for [!"$postBuildVariant"!] variant.[!ENDIF!]
*/
[!ENDCODE!][!//
    [!IF "(IMPLEMENTATION_CONFIG_VARIANT !='VariantPostBuild' and ($VariantsNo <= 1))"!][!//
[!CODE!][!//
/* VariantPreCompile/LinkTime and at most 1 configured variant */
extern const Tmu_Ip_ConfigType TmuIpConfig;
[!ENDCODE!][!//
[!ELSE!][!//
[!CODE!][!//
/* VariantPostBuild or more than 1 configured variant */
extern const Tmu_Ip_ConfigType TmuIpConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!];
[!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//

#define THERMAL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Thermal_MemMap.h"

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#define THERMAL_START_SEC_CODE
#include "Thermal_MemMap.h"

[!NOCODE!][!//
[!CODE!][!//
/**
* @brief          Tmu Ip Notification function prototypes
*/
[!ENDCODE!][!//
[!IF "ThermalConfigSet/TmuHwUnit/*/ThermalImmHighNotif != 'NULL_PTR'"!]
[!CODE!][!//
[!"concat('void ', ThermalConfigSet/TmuHwUnit/*/ThermalImmHighNotif,'(uint32 siteMask);')"!]
[!ENDCODE!]
[!ENDIF!]
[!IF "ThermalConfigSet/TmuHwUnit/*/ThermalAvgHighNotif != 'NULL_PTR'"!]
[!CODE!][!//
[!"concat('void ', ThermalConfigSet/TmuHwUnit/*/ThermalAvgHighNotif,'(uint32 siteMask);')"!]
[!ENDCODE!]
[!ENDIF!]
[!IF "ThermalConfigSet/TmuHwUnit/*/ThermalAvgHighCriticalNotif != 'NULL_PTR'"!]
[!CODE!][!//
[!"concat('void ', ThermalConfigSet/TmuHwUnit/*/ThermalAvgHighCriticalNotif,'(uint32 siteMask);')"!]
[!ENDCODE!]
[!ENDIF!]
[!IF "ThermalConfigSet/TmuHwUnit/*/ThermalImmLowNotif != 'NULL_PTR'"!]
[!CODE!][!//
[!"concat('void ', ThermalConfigSet/TmuHwUnit/*/ThermalImmLowNotif,'(uint32 siteMask);')"!]
[!ENDCODE!]
[!ENDIF!]
[!IF "ThermalConfigSet/TmuHwUnit/*/ThermalAvgLowNotif != 'NULL_PTR'"!]
[!CODE!][!//
[!"concat('void ', ThermalConfigSet/TmuHwUnit/*/ThermalAvgLowNotif,'(uint32 siteMask);')"!]
[!ENDCODE!]
[!ENDIF!]
[!IF "ThermalConfigSet/TmuHwUnit/*/ThermalAvgLowCriticalNotif != 'NULL_PTR'"!]
[!CODE!][!//
[!"concat('void ', ThermalConfigSet/TmuHwUnit/*/ThermalAvgLowCriticalNotif,'(uint32 siteMask);')"!]
[!ENDCODE!]
[!ENDIF!]
[!IF "ThermalConfigSet/TmuHwUnit/*/ThermalRisingRateNotif != 'NULL_PTR'"!]
[!CODE!][!//
[!"concat('void ', ThermalConfigSet/TmuHwUnit/*/ThermalRisingRateNotif,'(uint32 siteMask);')"!]
[!ENDCODE!]
[!ENDIF!]
[!IF "ThermalConfigSet/TmuHwUnit/*/ThermalFallingRateNotif != 'NULL_PTR'"!]
[!CODE!][!//
[!"concat('void ', ThermalConfigSet/TmuHwUnit/*/ThermalFallingRateNotif,'(uint32 siteMask);')"!]
[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!][!//

#define THERMAL_STOP_SEC_CODE
#include "Thermal_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* TMU_IP_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H */
[!ENDCODE!][!//


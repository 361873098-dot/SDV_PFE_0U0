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

#ifndef CDD_THERMAL_CFGDEFINES_H
#define CDD_THERMAL_CFGDEFINES_H

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
#include "OsIf.h"
[!NOCODE!][!//
[!INCLUDE "Thermal_VersionCheck_Src.m"!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define THERMAL_VENDOR_ID_CFGDEFINES                    43
#define THERMAL_MODULE_ID_CFGDEFINES                    255
#define THERMAL_AR_RELEASE_MAJOR_VERSION_CFGDEFINES     4
#define THERMAL_AR_RELEASE_MINOR_VERSION_CFGDEFINES     4
#define THERMAL_AR_RELEASE_REVISION_VERSION_CFGDEFINES  0
#define THERMAL_SW_MAJOR_VERSION_CFGDEFINES             4
#define THERMAL_SW_MINOR_VERSION_CFGDEFINES             0
#define THERMAL_SW_PATCH_VERSION_CFGDEFINES             2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against OsIf.h */
    #if ((THERMAL_AR_RELEASE_MAJOR_VERSION_CFGDEFINES != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (THERMAL_AR_RELEASE_MINOR_VERSION_CFGDEFINES != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of CDD_Thermal_CfgDefines.h and OsIf.h are different"
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/


/**
* @brief          Development error detection enabled/disabled ((STD_ON)/(STD_OFF)).
*/
#define THERMAL_DEV_ERROR_DETECT                        [!IF "ThermalGeneral/ThermalDevErrorDetect"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief          Thermal configuration type.
*/
#define THERMAL_CONFIG_TYPE                             TMU_IP_CONFIG_TYPE

/**
* @brief          Configuration Precompile variant.
* @details        Configuration Precompile variant.
*/
#define THERMAL_PRECOMPILE_SUPPORT                      [!IF "(IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() <= 1)"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

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

#endif /* CDD_THERMAL_CFGDEFINES_H */
[!ENDCODE!][!//

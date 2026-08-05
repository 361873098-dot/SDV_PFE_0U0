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

#ifndef WDG_43_VR5510_CFG_H
#define WDG_43_VR5510_CFG_H

/**
*   @file     Wdg_43_VR5510_Cfg.h
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
#include "Mcal.h"
[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
#include "Wdg_43_VR5510_[!"."!]_PBcfg.h"
[!ENDLOOP!][!//
[!ELSE!][!//
#include "Wdg_43_VR5510_PBcfg.h"
[!ENDIF!][!//
[!IF "WdgGeneral/WdgDisableDemReportErrorStatus = 'false'"!][!//
#include "Dem.h"
[!ENDIF!][!//
[!INCLUDE "Wdg_VR5510_VersionCheck_Inc.m"!][!//
[!INCLUDE "Wdg_VR5510_PluginMacros.m"!][!//
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDG_43_VR5510_CFG_VENDOR_ID                    43
#define WDG_43_VR5510_CFG_MODULE_ID                    102
#define WDG_43_VR5510_CFG_AR_RELEASE_MAJOR_VERSION     4
#define WDG_43_VR5510_CFG_AR_RELEASE_MINOR_VERSION     4
#define WDG_43_VR5510_CFG_AR_RELEASE_REVISION_VERSION  0
#define WDG_43_VR5510_CFG_SW_MAJOR_VERSION             4
#define WDG_43_VR5510_CFG_SW_MINOR_VERSION             0
#define WDG_43_VR5510_CFG_SW_PATCH_VERSION             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

[!IF "WdgGeneral/WdgDisableDemReportErrorStatus = 'false'"!][!//
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Wdg_43_VR5510_Cfg header file are of the same Autosar version */
    #if (( WDG_43_VR5510_CFG_AR_RELEASE_MAJOR_VERSION != DEM_AR_RELEASE_MAJOR_VERSION) || \
         ( WDG_43_VR5510_CFG_AR_RELEASE_MINOR_VERSION != DEM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Wdg_43_VR5510_Cfg.h and Dem.h are different"
    #endif
#endif
[!ENDIF!]
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!IF "not((IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile' or IMPLEMENTATION_CONFIG_VARIANT='VariantLinkTime') and (variant:size() <= 1))"!][!//
/**
* @brief  macro contains all PB configuration macros.
*/
#define WDG_43_VR5510_CONFIG_EXT \
[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
    WDG_43_VR5510_CONFIG_[!"."!]_PB \
[!ENDLOOP!][!//
[!ELSE!][!//
    WDG_43_VR5510_CONFIG_PB
[!ENDIF!]
[!ENDIF!]

[!CALL "WdgCheckCbkNotification"!][!//
[!CALL "WdgCheckGptConfig"!][!//
/**
* @brief This define indicate the number of HW IPs available on the Platform
*/
#define WDG_43_VR5510_NO_OF_INSTANCES            (1U)

/**
* @brief Compile switch to enable/disable development error detection for this module
*/
#define WDG_43_VR5510_DEV_ERROR_DETECT   ([!IF "WdgGeneral/WdgDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief Compile switch to enable/disable Ip development error detection for this module
*/
#define WDG_43_VR5510_IP_DEV_ERROR_DETECT   ([!IF "WdgGeneral/WdgDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief Compile switch to allow/forbid disabling the watchdog during runtime
*/
#define WDG_43_VR5510_DISABLE_ALLOWED           ([!IF "WdgGeneral/WdgDisableAllowed"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief Switch to globaly enable/disable the production error reporting.
*/
#define WDG_43_VR5510_DISABLE_DEM_REPORT_ERROR_STATUS           [!IF "WdgGeneral/WdgDisableDemReportErrorStatus"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief This define indicate that the type of watchdog external.
*/
#define WDG_43_VR5510_[!"node:value(WdgGeneral/WdgType)"!]_USED

/**
* @brief This variable will indicate the max Timeout duration.
*/
#define WDG_43_VR5510_TIMEOUT_DURATION_U32 ((uint32)[!"num:i(WdgGeneral/WdgTimeoutDuration)"!]U)

/**
* @brief This variable will indicate the Wdg Initial Timeout parameter in miliseconds
*/
#define WDG_43_VR5510_INITIAL_TIMEOUT_U16 ((uint16)[!"num:i(WdgGeneral/WdgInitialTimeout * 1000)"!])

/**
* @brief This variable will indicate the Wdg Max Timeout parameter in miliseconds
*/
#define WDG_43_VR5510_MAX_TIMEOUT_U16     ((uint16)[!"num:i(WdgGeneral/WdgMaxTimeout * 1000)"!])

/**
* @brief Adds or removes the service Wdg_43_VR5510_GetVersionInfo() from the code.
*/
#define WDG_43_VR5510_VERSION_INFO_API                 ([!IF "WdgGeneral/WdgVersionInfoApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
*   @brief  Wdg_VR5510 timeout type used for Osif timeout implementation.
*
*/
#define WDG_VR5510_TIMEOUT_TYPE ((OsIf_CounterType) [!"(WdgGeneral/WdgTimeoutMethod)"!])

/**
* @brief           Support for the user mode.
*/
#define WDG_VR5510_ENABLE_USER_MODE_SUPPORT     [!IF "WdgGeneral/WdgEnableUserModeSupport"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief This variable will indicate RAM/ROM execution
*/
[!NOCODE!]
[!IF "WdgGeneral/WdgRunArea = 'ROM'"!]
[!CODE!]#define WDG_43_VR5510_ROM (1U)[!ENDCODE!]
[!ELSEIF "WdgGeneral/WdgRunArea = 'RAM'"!]
[!CODE!]#define WDG_43_VR5510_RAM (0U)[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

#define WDG_43_VR5510_PRECOMPILE_SUPPORT                   ([!IF "(IMPLEMENTATION_CONFIG_VARIANT ='VariantPreCompile' or IMPLEMENTATION_CONFIG_VARIANT='VariantLinkTime') and (variant:size()<=1)"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
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

#endif /* WDG_43_VR5510_CFG_H */

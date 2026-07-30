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
/**
* @file    Wdg_VR5510_CfgExt.c
*
* @addtogroup  Wdg_VR5510
* @{
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

#include "Wdg_43_VR5510_Cfg.h"
#include "Wdg_43_VR5510.h"
#include "Wdg_43_VR5510_CfgExt.h"

[!INCLUDE "Wdg_VR5510_VersionCheck_Src.m"!][!//
[!INCLUDE "Wdg_VR5510_PluginMacros.m"!][!//
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDG_43_VR5510_CFG_EXT_VENDOR_ID_C                    43
#define WDG_43_VR5510_CFG_EXT_AR_RELEASE_MAJOR_VERSION_C     4
#define WDG_43_VR5510_CFG_EXT_AR_RELEASE_MINOR_VERSION_C     4
#define WDG_43_VR5510_CFG_EXT_AR_RELEASE_REVISION_VERSION_C  0
#define WDG_43_VR5510_CFG_EXT_SW_MAJOR_VERSION_C             4
#define WDG_43_VR5510_CFG_EXT_SW_MINOR_VERSION_C             0
#define WDG_43_VR5510_CFG_EXT_SW_PATCH_VERSION_C             2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Wdg_VR5510_CfgExt header file are of the same vendor */
#if (WDG_43_VR5510_CFG_EXT_VENDOR_ID_C != WDG_43_VR5510_CFG_EXT_VENDOR_ID)
    #error "Wdg_VR5510_CfgExt.c and Wdg_VR5510_CfgExt.h have different vendor ids"
#endif

/* Check if source file Wdg_VR5510_CfgExt Wdg header file are of the same Autosar version */
#if ((WDG_43_VR5510_CFG_EXT_AR_RELEASE_MAJOR_VERSION_C != WDG_43_VR5510_CFG_EXT_AR_RELEASE_MAJOR_VERSION) || \
    (WDG_43_VR5510_CFG_EXT_AR_RELEASE_MINOR_VERSION_C != WDG_43_VR5510_CFG_EXT_AR_RELEASE_MINOR_VERSION) || \
    (WDG_43_VR5510_CFG_EXT_AR_RELEASE_REVISION_VERSION_C != WDG_43_VR5510_CFG_EXT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wdg_VR5510_CfgExt.c and Wdg_VR5510_CfgExt.h are different"
#endif
/* Check if source file Wdg_VR5510_CfgExt Wdg header file are of the same Software version */
#if ((WDG_43_VR5510_CFG_EXT_SW_MAJOR_VERSION_C != WDG_43_VR5510_CFG_EXT_SW_MAJOR_VERSION) || \
    (WDG_43_VR5510_CFG_EXT_SW_MINOR_VERSION_C != WDG_43_VR5510_CFG_EXT_SW_MINOR_VERSION) || \
    (WDG_43_VR5510_CFG_EXT_SW_PATCH_VERSION_C != WDG_43_VR5510_CFG_EXT_SW_PATCH_VERSION))
    #error "Software Version Numbers of Wdg_VR5510_CfgExt.c and Wdg_VR5510_CfgExt.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

#if (WDG_43_VR5510_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#define WDG_43_VR5510_START_SEC_CONST_UNSPECIFIED
#include "Wdg_43_VR5510_MemMap.h"

/**
* @brief        DEM error reporting configuration
* @details      Set the state and id for Mcal_DemErrorType.
*/
[!LOOP "WdgGeneral"!][!//
const Wdg_VR5510_DemConfigType Wdg_VR5510_DemConfig=
{
[!IF "node:exists(./../WdgDemEventParameterRefs)"!][!//
    /* DEM error reporting WDG_E_DISABLE_REJECTED */
    {[!IF "node:exists(./../WdgDemEventParameterRefs/WDG_E_DISABLE_REJECTED)"!](uint32)STD_ON, (uint16)DemConf_DemEventParameter_[!"node:ref(./../WdgDemEventParameterRefs/WDG_E_DISABLE_REJECTED)/@name"!][!ELSE!](uint32)STD_OFF, (uint32)0U[!ENDIF!]},

    /* DEM error reporting WDG_E_MODE_FAILED */
    {[!IF "node:exists(./../WdgDemEventParameterRefs/WDG_E_MODE_FAILED)"!](uint32)STD_ON, (uint32)DemConf_DemEventParameter_[!"node:ref(./../WdgDemEventParameterRefs/WDG_E_MODE_FAILED)/@name"!][!ELSE!](uint32)STD_OFF, (uint32)0U[!ENDIF!]}
[!ELSE!][!//
    /* DEM error reporting WDG_E_DISABLE_REJECTED */
    {(uint32)STD_OFF, (uint32)0U},

    /* DEM error reporting WDG_E_MODE_FAILED */
    {(uint32)STD_OFF, (uint32)0U}
[!ENDIF!][!//
};
[!ENDLOOP!][!//

#define WDG_43_VR5510_STOP_SEC_CONST_UNSPECIFIED
#include "Wdg_43_VR5510_MemMap.h"
#endif

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

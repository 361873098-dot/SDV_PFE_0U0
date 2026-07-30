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
#include "CDD_Thermal.h"
[!NOCODE!][!//
[!INCLUDE "Thermal_VersionCheck_Src.m"!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define THERMAL_VENDOR_ID_CFG_C                      43
#define THERMAL_AR_RELEASE_MAJOR_VERSION_CFG_C       4
#define THERMAL_AR_RELEASE_MINOR_VERSION_CFG_C       4
#define THERMAL_AR_RELEASE_REVISION_VERSION_CFG_C    0
#define THERMAL_SW_MAJOR_VERSION_CFG_C               4
#define THERMAL_SW_MINOR_VERSION_CFG_C               0
#define THERMAL_SW_PATCH_VERSION_CFG_C               2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#if ((THERMAL_AR_RELEASE_MAJOR_VERSION_CFG_C != THERMAL_AR_RELEASE_MAJOR_VERSION) || \
     (THERMAL_AR_RELEASE_MINOR_VERSION_CFG_C != THERMAL_AR_RELEASE_MINOR_VERSION) || \
     (THERMAL_AR_RELEASE_REVISION_VERSION_CFG_C != THERMAL_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Thermal_Cfg.c and CDD_Thermal.h are different"
#endif

#if ((THERMAL_SW_MAJOR_VERSION_CFG_C != THERMAL_SW_MAJOR_VERSION) || \
     (THERMAL_SW_MINOR_VERSION_CFG_C != THERMAL_SW_MINOR_VERSION) || \
     (THERMAL_SW_PATCH_VERSION_CFG_C != THERMAL_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Thermal_Cfg.c and CDD_Thermal.h are different"
#endif

#if (THERMAL_VENDOR_ID_CFG_C != THERMAL_VENDOR_ID)
    #error "CDD_Thermal_Cfg.c and CDD_Thermal.h have different vendor ids"
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
[!ENDCODE!][!//


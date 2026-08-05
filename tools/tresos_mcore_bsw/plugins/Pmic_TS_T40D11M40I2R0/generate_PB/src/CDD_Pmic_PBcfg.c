/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Pmic_VR55XX
*   Dependencies         : MCU,DET,DEM,RTE,I2C,PORT,DIO,OCOTP
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
*   @file    Pmic[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c
*
*   @addtogroup PMIC_DRIVER_CONFIGURATION PMIC Driver Configurations
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                                          INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Pmic_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PMIC[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C                     43
#define PMIC[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define PMIC[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C      4
#define PMIC[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define PMIC[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C              4
#define PMIC[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C              0
#define PMIC[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C              2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if the files CDD_Pmic[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Pmic_Types.h are of the same vendor */
#if (PMIC[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C != PMIC_TYPES_VENDOR_ID)
    #error "CDD_Pmic[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Pmic_Types.h have different vendor ids"
#endif
/* Check if the files CDD_Pmic[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Pmic_Types.h are of the same Autosar version */
#if ((PMIC[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != PMIC_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C    != PMIC_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PMIC[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != PMIC_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Pmic[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Pmic_Types.h are different"
#endif
/* Check if the files CDD_Pmic[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Pmic_Types.h are of the same software version */
#if ((PMIC[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C != PMIC_TYPES_SW_MAJOR_VERSION) || \
     (PMIC[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C != PMIC_TYPES_SW_MINOR_VERSION) || \
     (PMIC[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C != PMIC_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Pmic[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Pmic_Types.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
[!NOCODE!][!//
[!INCLUDE "CDD_Pmic_VersionCheck_Src_PB.m"!][!//
[!INCLUDE "CDD_Pmic_RegOperations.m"!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define PMIC_START_SEC_CONST_UNSPECIFIED
#include "Pmic_MemMap.h"
#if (STD_OFF == PMIC_DISABLE_DEM_REPORT_ERROR_STATUS)
extern const Pmic_DemConfigType Pmic_DemConfig;
#endif
#define PMIC_STOP_SEC_CONST_UNSPECIFIED
#include "Pmic_MemMap.h"
/*==================================================================================================
                                       FUNCTION PROTOTYPES
==================================================================================================*/
[!IF "node:exists(PmicGeneralConfiguration/PmicWatchdogTaskNotification)"!]
#define PMIC_START_SEC_CODE
#include "Pmic_MemMap.h"


[!CALL "Pmic_ExportUserCallback"!]


#define PMIC_STOP_SEC_CODE
#include "Pmic_MemMap.h"
[!ENDIF!][!//

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

#define PMIC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pmic_MemMap.h"

[!CALL "Pmic_Reaction_Config", "Type" = "'PB'"!][!//
[!CALL "Pmic_Mode_Config", "Type" = "'PB'"!][!//
[!CALL "Pmic_Clock_Config", "Type" = "'PB'"!][!//
[!CALL "Pmic_Amux_Config", "Type" = "'PB'"!][!//
[!CALL "Pmic_SVS_Config", "Type" = "'PB'"!][!//
[!CALL "Pmic_Watchdog_Config", "Type" = "'PB'"!][!//
[!CALL "Pmic_Init_Config", "Type" = "'PB'"!][!//
[!CALL "Pmic_Otp_Config", "Type" = "'PB'"!][!//
[!CALL "Pmic_Ipw_Config", "Type" = "'PB'"!][!//
[!CALL "Pmic_InterfaceUnit_Config", "Type" = "'PB'"!][!//
[!CALL "Pmic_Device_Config", "Type" = "'PB'"!][!//
[!CALL "Pmic_Config", "Type" = "'PB'"!][!//
#define PMIC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pmic_MemMap.h"

/*==================================================================================================
*                                         LOCAL VARIABLES
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


/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : SERDES_SS
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
*   Copyright 2020-2023 NXP Semiconductors

*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef SERDES_CFG_H
#define SERDES_CFG_H

/**
*   @file
*
*   @addtogroup SERDES_DRIVER_CONFIGURATION Serdes Driver Configuration
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

#include "Mcal.h"

[!NOCODE!][!//
[!INCLUDE "Serdes_VersionCheck_Inc.m"!][!//
[!ENDNOCODE!][!//
[!AUTOSPACING!][!//

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SERDES_VENDOR_ID_CFG                       43
#define SERDES_AR_RELEASE_MAJOR_VERSION_CFG        4
#define SERDES_AR_RELEASE_MINOR_VERSION_CFG        4
#define SERDES_AR_RELEASE_REVISION_VERSION_CFG     0
#define SERDES_SW_MAJOR_VERSION_CFG                4
#define SERDES_SW_MINOR_VERSION_CFG                0
#define SERDES_SW_PATCH_VERSION_CFG                2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h file are of the same Autosar version */
    #if ((SERDES_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (SERDES_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Serdes_Cfg.h and Mcal.h are different"
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/**
* @brief          Precompile Support On.
* @details        VARIANT-PRE-COMPILE: Only parameters with "Pre-compile time"
*                 configuration are allowed in this variant.
*
* @api
*/
#define SERDES_PRECOMPILE_SUPPORT       ([!IF "(IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size() <= 1)"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief Enable/Disable multicore function from the driver
*/
#define SERDES_MULTICORE_ENABLED        ([!IF "node:exists(SerdesGeneral/SerdesMulticoreSupport) and (SerdesGeneral/SerdesMulticoreSupport = 'true')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief   Total number of Serdes channel configured.
*/
#define SERDES_HW_MAX_CONFIG           ([!"num:i(count(SerdesGlobalConfig/SerdesChannel/*))"!]U)
/**
* @brief   Total number of available hardware Serdes channels.
*/
#define SERDES_HW_MAX_MODULES          ([!"num:i(count(ecu:list('Serdes.SerdesGlobalConfig.SerdesChannel.SerdesHwChannel')))"!]U)

/* Pre-processor switch to enable/disable development error detection for Serdes API */
#define SERDES_DEV_ERROR_DETECT                         ([!IF "SerdesGeneral/SerdesDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Pre-processor switch to enable/disable the API to read out the modules version information */
#define SERDES_SET_MODE_API                             ([!IF "SerdesGeneral/SerdesSetModeApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Pre-processor switch to enable/disable the API to read out the modules version information */
#define SERDES_VERSION_INFO_API                         ([!IF "SerdesGeneral/SerdesVersionInfoApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

[!NOCODE!][!//
[!VAR "maxPartition" = "num:i(0)"!]
[!IF "node:exists(SerdesGeneral/SerdesMulticoreSupport) and node:value(SerdesGeneral/SerdesMulticoreSupport)='true'"!]
[!IF "node:exists(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition)"!]
    [!VAR "maxPartition" = "num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!]
[!ENDIF!]
[!ENDIF!]
[!IF "$maxPartition = 0"!][!VAR "maxPartition" = "num:i(1)"!][!ENDIF!]
[!ENDNOCODE!][!//
/**
* @brief          Number of configured partitions.
*/
#define SERDES_MAX_PARTITIONS                  ([!"num:i($maxPartition)"!]U)

/* Hardware channel id */
[!CODE!]
[!LOOP "SerdesGlobalConfig/SerdesChannel/*"!]
#define SERDES_IP_SS_BASE_ADDR_[!"substring-after(SerdesHwChannel, '_')"!]                         [!"substring-after(SerdesHwChannel, '_')"!]U
[!ENDLOOP!]
[!ENDCODE!]


[!IF "node:exists(SerdesGeneral/SerdesJobDone)"!]
/**
* @brief            The callback configured by the user for Serdes initialization job completed.
*/
#define SERDES_JOB_DONE_CALLBACK(Channel) ([!"normalize-space(SerdesGeneral/SerdesJobDone)"!](Channel))

#define SERDES_START_SEC_CODE
#include "Serdes_MemMap.h"

/**
* @brief            The callback configured by the user for Serdes initialization job completed.
*/
extern void SERDES_JOB_DONE_CALLBACK(uint8 Channel);

#define SERDES_STOP_SEC_CODE
#include "Serdes_MemMap.h"
[!ENDIF!]

[!IF "node:exists(SerdesGeneral/SerdesJobFailed)"!]
/**
* @brief            The callback configured by the user for Serdes initialization job failed.
*/
#define SERDES_JOB_FAILED_CALLBACK(Channel) ([!"normalize-space(SerdesGeneral/SerdesJobFailed)"!](Channel))

#define SERDES_START_SEC_CODE
#include "Serdes_MemMap.h"

/**
* @brief            The callback configured by the user for Serdes initialization job failed.
*/
extern void SERDES_JOB_FAILED_CALLBACK(uint8 Channel);

#define SERDES_STOP_SEC_CODE
#include "Serdes_MemMap.h"
[!ENDIF!]

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/


/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL CONSTANTS DECLARATIONS
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

#endif /* SERDES_CFG_H */

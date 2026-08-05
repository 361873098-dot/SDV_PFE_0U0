/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : IIC
*   Dependencies         : MCU,PORT,DET,RTE
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
/*==================================================================================================
==================================================================================================*/

#ifndef CDD_I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H
#define CDD_I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H

/**
*   @file
*
*   @addtogroup I2C_DRIVER_CONFIGURATION I2c Driver Configurations
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
#include "I2c_Types.h"

/*==================================================================================================
                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_MODULE_ID                     255
#define I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID                     43
#define I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION      4
#define I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION              4
#define I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION              0
#define I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION              2

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and I2c_Types.h header file are of the same vendor */
#if (I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID != I2C_TYPES_VENDOR_ID)
    #error "CDD_I2c[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and I2c_Types.h have different vendor ids"
#endif
/* Check if current file and I2c_Types.h header file are of the same module */
#if (I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_MODULE_ID != I2C_TYPES_MODULE_ID)
    #error "CDD_I2c[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and I2c_Types.h have different module ids"
#endif
/* Check if current file and I2c_Types.h header file are of the same Autosar version */
#if ((I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION    != I2C_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION    != I2C_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION != I2C_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_I2c[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and I2c_Types.h are different"
#endif
/* Check if current file and I2c_Types.h header file are of the same Software version */
#if ((I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION != I2C_TYPES_SW_MAJOR_VERSION) || \
     (I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION != I2C_TYPES_SW_MINOR_VERSION) || \
     (I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION != I2C_TYPES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_I2c[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h and I2c_Types.h are different"
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/
[!NOCODE!]
[!IF "variant:size()>1"!][!//
[!CODE!]
/**
* @brief          Link I2c channels symbolic names with I2c channel IDs.
* @details        Link I2c channels symbolic names with I2c channel IDs.
*
* @api
*/
[!ENDCODE!]
[!FOR "index" = "0" TO "num:i(ecu:get('I2c.I2cGlobalConfig.I2cChannel'))-1"!]
    [!VAR "I2cEcuHwChannel" = "string((ecu:list('I2c.I2cGlobalConfig.I2cChannel.I2cHwChannel'))[$index+1])"!]
    [!VAR "ChannelFound" = "0"!]
    [!LOOP "I2cGlobalConfig/I2cChannel/*"!]
        [!VAR "HardwareChannel" = "string(I2cHwChannel)"!]
        [!IF "$I2cEcuHwChannel = $HardwareChannel"!]
            [!IF "$ChannelFound = 0"!]
                [!CODE!]
#ifndef I2C_[!"$I2cEcuHwChannel"!]
    #define I2C_[!"$I2cEcuHwChannel"!]    [!"substring-after(I2cHwChannel,'_')"!]U
#endif[!//
                [!ENDCODE!]
                [!VAR "ChannelFound" = "1"!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDFOR!]
[!ENDIF!]
[!ENDNOCODE!]
/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

[!NOCODE!]
[!IF "not(IMPLEMENTATION_CONFIG_VARIANT !='VariantPostBuild' and (variant:size()<=1))"!] [!//
[!IF "var:defined('postBuildVariant')"!][!//
  [!VAR "postBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!][!//
[!CODE!]#define I2C_CONFIG_[!"$postBuildVariant"!]_PB \[!CR!][!ENDCODE!]
[!ELSE!][!//
  [!VAR "postBuildVariantNameUnderscore" = "string(null)"!][!//
[!CODE!]#define I2C_CONFIG_PB \[!CR!][!ENDCODE!]
[!ENDIF!][!//
[!VAR "I2cConfiguredPartitions" = "num:i(count(I2cGlobalConfig/I2cEcucPartitionRef/*))"!][!//
    [!IF "$I2cConfiguredPartitions > 0"!][!//
        [!VAR "PartitionIndex" = "0"!][!//
        [!LOOP "I2cGlobalConfig/I2cEcucPartitionRef/*"!][!//
            [!VAR "PartitionIndex"="$PartitionIndex + 1"!][!//
            [!VAR "currentPartition" = "substring-after(substring-after(substring-after(substring-after(.,'/'),'/'),'/'),'/')"!][!//
            [!CODE!][!WS4!]extern const I2c_ConfigType I2c_Config[!"$postBuildVariantNameUnderscore"!]_[!"$currentPartition"!];[!IF "$PartitionIndex < $I2cConfiguredPartitions"!]\[!ENDIF!][!CR!][!ENDCODE!]
        [!ENDLOOP!][!//
    [!ELSE!][!//
            [!CODE!][!WS4!]extern const I2c_ConfigType I2c_Config[!"$postBuildVariantNameUnderscore"!];[!CR!][!ENDCODE!]
    [!ENDIF!][!//
[!ENDIF!]
[!ENDNOCODE!]
/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CDD_I2C[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H */

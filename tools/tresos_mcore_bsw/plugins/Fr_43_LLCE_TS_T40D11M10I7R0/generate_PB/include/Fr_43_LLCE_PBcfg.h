[!AUTOSPACING!]
[!NOCODE!]
    [!VAR "postBuildVariantNameUnderscore" = "''"!]
    [!IF "var:defined('postBuildVariant')"!]
        [!VAR "postBuildVariantNameUnderscore" = "concat('_', $postBuildVariant)"!]
    [!ENDIF!]

    [!VAR "FRConfiguredPartitions" = "num:i((count(./FrGeneral/FrEcucPartitionRef/*)))"!]
[!ENDNOCODE!]
[!CODE!]
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : LLCE
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 1.0.7
*   Build Version        : S32_RTD_1_0_7_D2909_ASR_REL_4_4_REV_0000_20230630
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

#ifndef FR_43_LLCE[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H
#define FR_43_LLCE[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H

/**
*   @file Fr_43_LLCE_PBcfg.h
*   @implements  Fr_PBcfg.h_Artifact
*   @addtogroup FR_43_LLCE_HLD
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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FR_43_LLCE[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID                    43
#define FR_43_LLCE[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_MODULE_ID                    81
#define FR_43_LLCE[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION     4
#define FR_43_LLCE[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION     4
#define FR_43_LLCE[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION  0
#define FR_43_LLCE[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION             1
#define FR_43_LLCE[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION             0
#define FR_43_LLCE[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION             7

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define FR_43_LLCE_CONFIG[!"$postBuildVariantNameUnderscore"!]_PB \
    [!IF "(IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild' and (variant:size() <= 1))"!]
        [!IF "$FRConfiguredPartitions > 0"!]
            [!VAR "partitionIdx" = "0"!]
            [!LOOP "./FrGeneral/FrEcucPartitionRef/*"!]
                [!VAR "partitionIdx" = "$partitionIdx + 1"!]
                [!VAR "currentPartition" = "substring-after(substring-after(substring-after(substring-after(.,'/'),'/'),'/'),'/')"!]
                [!WS "4"!]extern const Fr_43_LLCE_ConfigurationType Fr_43_LLCE_Config_[!"$currentPartition"!];[!IF "$partitionIdx < $FRConfiguredPartitions"!] \[!ENDIF!]
            [!ENDLOOP!]
        [!ELSE!]
                [!WS "4"!]extern const Fr_43_LLCE_ConfigurationType Fr_43_LLCE_Config;
        [!ENDIF!]
    [!ELSE!]
        [!IF "$FRConfiguredPartitions > 0"!]
            [!VAR "partitionIdx" = "0"!]
            [!LOOP "./FrGeneral/FrEcucPartitionRef/*"!]
                [!VAR "partitionIdx" = "$partitionIdx + 1"!]
                [!VAR "currentPartition" = "substring-after(substring-after(substring-after(substring-after(.,'/'),'/'),'/'),'/')"!]
                [!WS "4"!]extern const Fr_43_LLCE_ConfigurationType Fr_43_LLCE_Config[!"$postBuildVariantNameUnderscore"!]_[!"$currentPartition"!];[!IF "$partitionIdx < $FRConfiguredPartitions"!] \[!ENDIF!]
            [!ENDLOOP!]
        [!ELSE!]
                [!WS "4"!]extern const Fr_43_LLCE_ConfigurationType Fr_43_LLCE_Config[!"$postBuildVariantNameUnderscore"!];
        [!ENDIF!]
    [!ENDIF!]

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

#endif /* FR_43_LLCE[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H */

[!ENDCODE!]

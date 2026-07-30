/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : IPV_USDHC
*   Dependencies         : 
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
[!VAR "variantName" = "''"!][!//
[!VAR "variantNameUpperCase" = "''"!][!//
[!IF "var:defined('postBuildVariant')"!][!//
[!VAR "variantName" = "concat('_', $postBuildVariant)"!][!//
[!VAR "variantNameUpperCase" = "toUpperCase(string($variantName))"!][!//
[!ENDIF!][!//
#ifndef EEP[!"$variantNameUpperCase"!]_PBCFG_H
#define EEP[!"$variantNameUpperCase"!]_PBCFG_H

/**
*   @file Eep[!"$variantName"!]_PBcfg.h
*
*   @addtogroup EEP
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EEP[!"$variantNameUpperCase"!]_PBCFG_VENDOR_ID                    43
#define EEP[!"$variantNameUpperCase"!]_PBCFG_AR_RELEASE_MAJOR_VERSION     4
#define EEP[!"$variantNameUpperCase"!]_PBCFG_AR_RELEASE_MINOR_VERSION     4
#define EEP[!"$variantNameUpperCase"!]_PBCFG_AR_RELEASE_REVISION_VERSION  0
#define EEP[!"$variantNameUpperCase"!]_PBCFG_SW_MAJOR_VERSION             4
#define EEP[!"$variantNameUpperCase"!]_PBCFG_SW_MINOR_VERSION             0
#define EEP[!"$variantNameUpperCase"!]_PBCFG_SW_PATCH_VERSION             2
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

[!NOCODE!]
    [!CODE!]#define EEP_CONFIG[!"$variantNameUpperCase"!]_PB \[!CR!][!ENDCODE!]
[!IF "not((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()<=1))"!] [!//
    [!CODE!][!WS "4"!]extern const Eep_ConfigType Eep_Config[!"$variantName"!];[!ENDCODE!]
[!ENDIF!][!//
[!ENDNOCODE!]

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif    /* #ifndef EEP[!"$variantNameUpperCase"!]_PBCFG_H */
/**@}*/


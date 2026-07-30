[!AUTOSPACING!]
[!CODE!]
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : FLEXRAY
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

#ifndef FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H
#define FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H

/**
*   @file Flexray_Ip_PBcfg.h
*
*   @addtogroup flexray_ip FlexRay IPL
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
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID                         43
#define FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_MODULE_ID                         81
#define FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION          4
#define FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION          4
#define FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION       0
#define FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION                  4
#define FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION                  0
#define FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION                  2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!WS "0"!][!// Go through all Fr multiple configurations
[!LOOP "node:order(FrMultipleConfiguration,'node:name(.)')"!][!//Sort the multiple configurations by their name at first
    [!VAR "FrConfigName" = "as:name(.)"!][!//Store the name of Fr controller multiple configuration
    [!VAR "FrConfigIdx" = "position()"!][!//Store the index of Fr controller multiple configuration
    [!VAR "CfgVariant" = "string('PB')"!]
    [!WS "0"!][!// Go through all controllers in the Fr multiple configuration
    [!LOOP "node:order(FrController/*,'FrCtrlIdx','node:name(.)')"!][!//Sort the controllers by their name at first
        [!VAR "FrController" = "node:path(.)"!]
        [!WS "0"!]#define FLEXRAY_IP_STATEALLOC_FRMC[!"$FrConfigIdx"!]_CTRL[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_[!"string($CfgVariant)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!"' '"!]\
        [!WS "4"!]extern Flexray_Ip_StateAllocateType Fr_MC[!"$FrConfigIdx"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_StateAlloc_[!"string($CfgVariant)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!];
        [!WS "0"!][!CR!]
        [!WS "0"!]#define FLEXRAY_IP_CFG_FRMC[!"$FrConfigIdx"!]_CTRL[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_[!"string($CfgVariant)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!"' '"!]\
        [!WS "4"!]extern Flexray_Ip_ConfigType Fr_MC[!"$FrConfigIdx"!]_Ctrl[!"num:i(node:ref($FrController)/FrCtrlIdx)"!]_Cfg_[!"string($CfgVariant)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!];
        [!WS "0"!][!CR!]
    [!ENDLOOP!][!//FrController
[!ENDLOOP!][!//FrMultipleConfiguration
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

#endif /* FLEXRAY_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_H */

[!ENDCODE!]

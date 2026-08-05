[!AUTOSPACING!]
[!NOCODE!]
    [!INCLUDE "Fr_VersionCheck.m"!]
[!ENDNOCODE!]
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

#ifndef FLEXRAY_IP_CFG_H
#define FLEXRAY_IP_CFG_H

/**
*   @file Flexray_Ip_Cfg.h
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
#include "Mcal.h"
#include "[!"ecu:get('FR.IncludeHeader')"!]"
[!IF "var:defined('postBuildVariant')"!]
    [!LOOP "variant:all()"!]
        [!WS "0"!]#include "Flexray_Ip_[!"."!]_PBcfg.h"
    [!ENDLOOP!]
[!ELSE!]
    [!WS "0"!]#include "Flexray_Ip_PBcfg.h"
[!ENDIF!]

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXRAY_IP_CFG_VENDOR_ID                        43
#define FLEXRAY_IP_CFG_MODULE_ID                        81
#define FLEXRAY_IP_CFG_AR_RELEASE_MAJOR_VERSION         4
#define FLEXRAY_IP_CFG_AR_RELEASE_MINOR_VERSION         4
#define FLEXRAY_IP_CFG_AR_RELEASE_REVISION_VERSION      0
#define FLEXRAY_IP_CFG_SW_MAJOR_VERSION                 4
#define FLEXRAY_IP_CFG_SW_MINOR_VERSION                 0
#define FLEXRAY_IP_CFG_SW_PATCH_VERSION                 2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
[!IF "var:defined('postBuildVariant')"!]
    [!LOOP "variant:all()"!]
        [!WS "0"!]/* Check if current file and Flexray_Ip_[!"."!]_PBcfg.h header file are of the same vendor */
        [!WS "0"!]#if(FLEXRAY_IP_CFG_VENDOR_ID != FLEXRAY_IP_[!"."!]_PBCFG_VENDOR_ID)
        [!WS "0"!]    #error "Flexray_Ip_Cfg.h and Flexray_Ip_[!"."!]_PBcfg.h have different Vendor IDs"
        [!WS "0"!]#endif
        [!WS "0"!]/* Check if current file and Flexray_Ip_[!"."!]_PBcfg.h header file are of the same Autosar version */
        [!WS "0"!]#if((FLEXRAY_IP_CFG_AR_RELEASE_MAJOR_VERSION    != FLEXRAY_IP_[!"."!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
        [!WS "0"!]    (FLEXRAY_IP_CFG_AR_RELEASE_MINOR_VERSION    != FLEXRAY_IP_[!"."!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
        [!WS "0"!]    (FLEXRAY_IP_CFG_AR_RELEASE_REVISION_VERSION != FLEXRAY_IP_[!"."!]_PBCFG_AR_RELEASE_REVISION_VERSION))
        [!WS "0"!]    #error "Software Version Numbers of Flexray_Ip_Cfg.h and Flexray_Ip_[!"."!]_PBcfg.h are different"
        [!WS "0"!]#endif
        [!WS "0"!]/* Check if current file and Flexray_Ip_[!"."!]_PBcfg.h header file are of the same software version */
        [!WS "0"!]#if((FLEXRAY_IP_CFG_SW_MAJOR_VERSION != FLEXRAY_IP_[!"."!]_PBCFG_SW_MAJOR_VERSION) || \
        [!WS "0"!]    (FLEXRAY_IP_CFG_SW_MINOR_VERSION != FLEXRAY_IP_[!"."!]_PBCFG_SW_MINOR_VERSION) || \
        [!WS "0"!]    (FLEXRAY_IP_CFG_SW_PATCH_VERSION != FLEXRAY_IP_[!"."!]_PBCFG_SW_PATCH_VERSION))
        [!WS "0"!]    #error "Autosar Version Numbers of Flexray_Ip_Cfg.h and Flexray_Ip_[!"."!]_PBcfg.h are different"
        [!WS "0"!]#endif
        [!WS "0"!]
    [!ENDLOOP!]
[!ELSE!]
[!WS "0"!]/* Check if current file and Flexray_Ip_PBcfg.h header file are of the same vendor */
    [!WS "0"!]#if(FLEXRAY_IP_CFG_VENDOR_ID != FLEXRAY_IP_PBCFG_VENDOR_ID)
    [!WS "0"!]    #error "Flexray_Ip_Cfg.h and Flexray_Ip_PBcfg.h have different Vendor IDs"
    [!WS "0"!]#endif
    [!WS "0"!]/* Check if current file and Flexray_Ip_PBcfg.h header file are of the same Autosar version */
    [!WS "0"!]#if((FLEXRAY_IP_CFG_AR_RELEASE_MAJOR_VERSION    != FLEXRAY_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
    [!WS "0"!]    (FLEXRAY_IP_CFG_AR_RELEASE_MINOR_VERSION    != FLEXRAY_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
    [!WS "0"!]    (FLEXRAY_IP_CFG_AR_RELEASE_REVISION_VERSION != FLEXRAY_IP_PBCFG_AR_RELEASE_REVISION_VERSION))
    [!WS "0"!]    #error "Software Version Numbers of Flexray_Ip_Cfg.h and Flexray_Ip_PBcfg.h are different"
    [!WS "0"!]#endif
    [!WS "0"!]/* Check if current file and Flexray_Ip_PBcfg.h header file are of the same software version */
    [!WS "0"!]#if((FLEXRAY_IP_CFG_SW_MAJOR_VERSION != FLEXRAY_IP_PBCFG_SW_MAJOR_VERSION) || \
    [!WS "0"!]    (FLEXRAY_IP_CFG_SW_MINOR_VERSION != FLEXRAY_IP_PBCFG_SW_MINOR_VERSION) || \
    [!WS "0"!]    (FLEXRAY_IP_CFG_SW_PATCH_VERSION != FLEXRAY_IP_PBCFG_SW_PATCH_VERSION))
    [!WS "0"!]    #error "Autosar Version Numbers of Flexray_Ip_Cfg.h and Flexray_Ip_PBcfg.h are different"
    [!WS "0"!]#endif
    [!WS "0"!]
[!ENDIF!]
[!WS "0"!][!CR!]
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if((FLEXRAY_IP_CFG_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        (FLEXRAY_IP_CFG_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Flexray_Ip_Cfg.h and Mcal.h are different"
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define FLEXRAY_HW_VERSION    ([!"ecu:get('FR.ModuleVersion')"!])
#define FLEXRAY_AUTOSAR_MODE_USED

/*! @brief Enables / Disables user mode support */
#define FLEXRAY_ENABLE_USER_MODE_SUPPORT    ([!IF "FrGeneral/VendorSpecific/FrEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == FLEXRAY_ENABLE_USER_MODE_SUPPORT)
        #error "MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running FLEXRAY in user mode, MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined."
    #endif /* (STD_ON == FLEXRAY_ENABLE_USER_MODE_SUPPORT */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

#if ((STD_ON == FLEXRAY_ENABLE_USER_MODE_SUPPORT) && defined(MCAL_FLEXRAY_REG_PROT_AVAILABLE))
    #if (STD_ON == MCAL_FLEXRAY_REG_PROT_AVAILABLE)
        #define FLEXRAY_SET_USER_ACCESS_ALLOWED_AVAILABLE      (STD_ON)
    #else
        #define FLEXRAY_SET_USER_ACCESS_ALLOWED_AVAILABLE      (STD_OFF)
    #endif
#else
    #define FLEXRAY_SET_USER_ACCESS_ALLOWED_AVAILABLE      (STD_OFF)
#endif

    [!IF "'true' = text:tolower(node:exists(FrGeneral/VendorSpecific/FrUnusedBitValue))"!]
        [!WS "0"!]/* FLEXRAY_UNUSED_BIT_VALUE_U8 definition */
        [!IF "0 = number(FrGeneral/VendorSpecific/FrUnusedBitValue)"!]
            [!WS "0"!]/* Copy of FrUnusedBitValue parameter from Fr General\VendorSpecific container in 8bit format */
            [!WS "0"!]#define FLEXRAY_UNUSED_BIT_VALUE_U8                ((uint8)0x00U)
            [!WS "0"!]/* Copy of FrUnusedBitValue parameter from Fr General\VendorSpecific container in 16bit format */
            [!WS "0"!]#define FLEXRAY_UNUSED_BIT_VALUE_U16               ((uint16)0x0000U)
            [!WS "0"!][!CR!]
        [!ELSE!]
            [!WS "0"!]/* Copy of FrUnusedBitValue parameter from Fr General\VendorSpecific container in 8bit format */
            [!WS "0"!]#define FLEXRAY_UNUSED_BIT_VALUE_U8                ((uint8)0xFFU)
            [!WS "0"!]/* Copy of FrUnusedBitValue parameter from Fr General\VendorSpecific container in 16bit format */
            [!WS "0"!]#define FLEXRAY_UNUSED_BIT_VALUE_U16               ((uint16)0xFFFFU)
            [!WS "0"!][!CR!]
        [!ENDIF!]
    [!ENDIF!]
    [!LOOP "node:order(FrMultipleConfiguration,'node:name(.)')"!]
        [!VAR "FrConfigName" = "as:name(.)"!]
        [!VAR "FrConfigIdx" = "position()"!]
        [!VAR "CfgVariant" = "string('PB')"!]
        [!VAR "FrNumCtrlSupported" = "num:i(count(FrController/*))"!]
        [!WS "0"!][!//
        [!WS "0"!]#define FLEXRAY_IP_STATEALLOC_EXT \
        [!LOOP "node:order(FrController/*,'FrCtrlIdx','node:name(.)')"!]
            [!VAR "FrController" = "node:path(.)"!]
            [!VAR "FrCtrlIdx" = "num:i(node:ref($FrController)/FrCtrlIdx)"!]
            [!IF "var:defined('postBuildVariant')"!]
                [!VAR "variantCount" = "count(variant:all())"!]
                [!VAR "variantIdx" = "0"!]
                [!LOOP "variant:all()"!]
                    [!VAR "variantIdx" = "$variantIdx + 1"!]
                    [!WS "4"!]FLEXRAY_IP_STATEALLOC_FRMC[!"$FrConfigIdx"!]_CTRL[!"$FrCtrlIdx"!]_[!"string($CfgVariant)"!]_[!"."!][!IF "($variantIdx < $variantCount) or ($FrCtrlIdx < ($FrNumCtrlSupported -1))"!] \[!ENDIF!][!CR!]
                [!ENDLOOP!]
            [!ELSE!]
                [!WS "4"!]FLEXRAY_IP_STATEALLOC_FRMC[!"$FrConfigIdx"!]_CTRL[!"$FrCtrlIdx"!]_[!"string($CfgVariant)"!][!IF "($FrCtrlIdx < ($FrNumCtrlSupported -1))"!] \[!ENDIF!][!CR!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!WS "0"!][!CR!]
        [!WS "0"!]#define FLEXRAY_IP_CFG_EXT \
        [!LOOP "node:order(FrController/*,'FrCtrlIdx','node:name(.)')"!]
            [!VAR "FrController" = "node:path(.)"!]
            [!VAR "FrCtrlIdx" = "num:i(node:ref($FrController)/FrCtrlIdx)"!]
            [!IF "var:defined('postBuildVariant')"!]
                [!VAR "variantCount" = "count(variant:all())"!]
                [!VAR "variantIdx" = "0"!]
                [!LOOP "variant:all()"!]
                    [!VAR "variantIdx" = "$variantIdx + 1"!]
                    [!WS "4"!]FLEXRAY_IP_CFG_FRMC[!"$FrConfigIdx"!]_CTRL[!"$FrCtrlIdx"!]_[!"string($CfgVariant)"!]_[!"."!][!IF "($variantIdx < $variantCount) or ($FrCtrlIdx < ($FrNumCtrlSupported -1))"!] \[!ENDIF!][!CR!]
                [!ENDLOOP!]
            [!ELSE!]
                [!WS "4"!]FLEXRAY_IP_CFG_FRMC[!"$FrConfigIdx"!]_CTRL[!"$FrCtrlIdx"!]_[!"string($CfgVariant)"!][!IF "($FrCtrlIdx < ($FrNumCtrlSupported -1))"!] \[!ENDIF!][!CR!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDLOOP!]

#define FLEXRAY_NUMBER_MB           ([!"num:i(ecu:get('FR.AvailableBuffers'))"!]U)

    [!SELECT "FrGeneral"!]
        [!WS "0"!]#define FLEXRAY_TIMEOUT_TYPE                ([!"VendorSpecific/FrTimeoutMethod"!])
        [!WS "0"!]#define FLEXRAY_TIMEOUT_DURATION_US         ([!"VendorSpecific/FrTimeoutDuration"!]U)
        [!WS "0"!]#define FLEXRAY_DEV_ERROR_DETECT            ([!IF "'true' = ./FrDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

        [!WS "0"!]#define FLEXRAY_PREPARE_LPDU_SUPPORT        ([!IF "'true' = ./FrPrepareLPduSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
        [!WS "0"!]#define FLEXRAY_DISABLE_LPDU_SUPPORT        ([!IF "'true' = ./FrDisableLPduSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
        [!WS "0"!]#define FLEXRAY_EXTENDED_LPDU_REPORTING     ([!IF "'true' = ./FrExtendedLPduReporting"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
        [!WS "0"!]#define FLEXRAY_RECONFIG_LPDU_SUPPORT       ([!IF "'true' = ./FrReconfigLPduSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

        [!WS "0"!]#define FLEXRAY_RXSTRINGENTCHECK            ([!IF "'true' = ./FrRxStringentCheck"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
        [!WS "0"!]#define FLEXRAY_RXSTRINGENTLENGTHCHECK      ([!IF "'true' = ./FrRxStringentLengthCheck"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
    [!ENDSELECT!]

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

#endif /* FLEXRAY_IP_CFG_H */

[!ENDCODE!]

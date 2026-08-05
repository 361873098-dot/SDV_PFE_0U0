[!AUTOSPACING!]
[!NOCODE!]
    [!INCLUDE "Fr_43_LLCE_VersionCheck.m"!]
    [!VAR "variantCount" = "count(variant:all())"!]
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

#ifndef FR_43_LLCE_CFG_H
#define FR_43_LLCE_CFG_H

/**
*   @file Fr_43_LLCE_Cfg.h
*   @implements  Fr_Cfg.h_Artifact
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
#include "Mcal.h"
    [!IF "var:defined('postBuildVariant')"!]
        [!LOOP "variant:all()"!]
            [!WS "0"!]#include "Fr_43_LLCE_[!"."!]_PBcfg.h"
        [!ENDLOOP!]
    [!ELSE!]
        [!WS "0"!]#include "Fr_43_LLCE_PBcfg.h"
    [!ENDIF!]

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FR_43_LLCE_CFG_VENDOR_ID                    43
#define FR_43_LLCE_CFG_MODULE_ID                    81
#define FR_43_LLCE_CFG_AR_RELEASE_MAJOR_VERSION     4
#define FR_43_LLCE_CFG_AR_RELEASE_MINOR_VERSION     4
#define FR_43_LLCE_CFG_AR_RELEASE_REVISION_VERSION  0
#define FR_43_LLCE_CFG_SW_MAJOR_VERSION             1
#define FR_43_LLCE_CFG_SW_MINOR_VERSION             0
#define FR_43_LLCE_CFG_SW_PATCH_VERSION             7

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if((FR_43_LLCE_CFG_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        (FR_43_LLCE_CFG_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Fr_43_LLCE_Cfg.h and Mcal.h are different"
    #endif
#endif

    [!IF "var:defined('postBuildVariant')"!]
        [!LOOP "variant:all()"!]
/* Check if current file and Fr_43_LLCE_[!"."!]_PBcfg.h header file are of the same vendor */
#if (FR_43_LLCE_[!"."!]_PBCFG_VENDOR_ID != FR_43_LLCE_CFG_VENDOR_ID)
    #error "Fr_43_LLCE_[!"."!]_PBcfg.h and Fr_43_LLCE_Cfg.h have different vendor IDs"
#endif
/* Check if current file and Fr_43_LLCE_[!"."!]_PBcfg.h header file are of the same Autosar version */
#if ((FR_43_LLCE_[!"."!]_PBCFG_AR_RELEASE_MAJOR_VERSION != FR_43_LLCE_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (FR_43_LLCE_[!"."!]_PBCFG_AR_RELEASE_MINOR_VERSION != FR_43_LLCE_CFG_AR_RELEASE_MINOR_VERSION) || \
    (FR_43_LLCE_[!"."!]_PBCFG_AR_RELEASE_REVISION_VERSION != FR_43_LLCE_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Fr_43_LLCE_[!"."!]_PBcfg.h and Fr_43_LLCE_Cfg.h are different"
#endif
/* Check if current file and Fr_43_LLCE_[!"."!]_PBcfg.h header file are of the same software version */
#if ((FR_43_LLCE_[!"."!]_PBCFG_SW_MAJOR_VERSION != FR_43_LLCE_CFG_SW_MAJOR_VERSION) || \
    (FR_43_LLCE_[!"."!]_PBCFG_SW_MINOR_VERSION != FR_43_LLCE_CFG_SW_MINOR_VERSION) || \
    (FR_43_LLCE_[!"."!]_PBCFG_SW_PATCH_VERSION != FR_43_LLCE_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fr_43_LLCE_[!"."!]_PBcfg.h and Fr_43_LLCE_Cfg.h are different"
#endif
        [!ENDLOOP!]
    [!ELSE!]
/* Check if current file and Fr_43_LLCE_PBcfg.h header file are of the same vendor */
#if (FR_43_LLCE_PBCFG_VENDOR_ID != FR_43_LLCE_CFG_VENDOR_ID)
    #error "Fr_43_LLCE_PBcfg.h and Fr_43_LLCE_Cfg.h have different vendor IDs"
#endif
/* Check if current file and Fr_43_LLCE_PBcfg.h header file are of the same Autosar version */
#if ((FR_43_LLCE_PBCFG_AR_RELEASE_MAJOR_VERSION != FR_43_LLCE_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (FR_43_LLCE_PBCFG_AR_RELEASE_MINOR_VERSION != FR_43_LLCE_CFG_AR_RELEASE_MINOR_VERSION) || \
    (FR_43_LLCE_PBCFG_AR_RELEASE_REVISION_VERSION != FR_43_LLCE_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Fr_43_LLCE_PBcfg.h and Fr_43_LLCE_Cfg.h are different"
#endif
/* Check if current file and Fr_43_LLCE_PBcfg.h header file are of the same software version */
#if ((FR_43_LLCE_PBCFG_SW_MAJOR_VERSION != FR_43_LLCE_CFG_SW_MAJOR_VERSION) || \
    (FR_43_LLCE_PBCFG_SW_MINOR_VERSION != FR_43_LLCE_CFG_SW_MINOR_VERSION) || \
    (FR_43_LLCE_PBCFG_SW_PATCH_VERSION != FR_43_LLCE_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fr_43_LLCE_PBcfg.h and Fr_43_LLCE_Cfg.h are different"
#endif
    [!ENDIF!]

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
    [!WS "0"!]/* On/Off PreCompile switches */
    [!WS "0"!]#define FR_43_LLCE_CONFIG_EXT \
    [!IF "var:defined('postBuildVariant')"!]
        [!VAR "variantIdx" = "0"!]
        [!LOOP "variant:all()"!]
            [!VAR "variantIdx" = "$variantIdx + 1"!]
            [!WS "4"!]FR_43_LLCE_CONFIG_[!"."!]_PB[!IF "$variantIdx < $variantCount"!] \[!ENDIF!][!CR!]
        [!ENDLOOP!]
    [!ELSE!]
        [!WS "4"!]FR_43_LLCE_CONFIG_PB
    [!ENDIF!]

    [!IF "((IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and (variant:size()<=1)) or (IMPLEMENTATION_CONFIG_VARIANT = 'VariantLinkTime')"!]
        [!WS "0"!]#define FR_43_LLCE_VARIANT_PRECOMPILE                 (STD_ON)
    [!ELSE!]
        [!WS "0"!]#define FR_43_LLCE_VARIANT_PRECOMPILE                 (STD_OFF)
    [!ENDIF!]
    [!SELECT "FrGeneral"!]
        [!WS "0"!]/* time out config (need move to ip_cfg.h) */
        [!WS "0"!]#define FLEXRAY_43_LLCE_TIMEOUT_TYPE                  ([!"VendorSpecific/FrTimeoutMethod"!])
        [!WS "0"!]#define FLEXRAY_43_LLCE_TIMEOUT_DURATION_US           ([!"VendorSpecific/FrTimeoutDuration"!]U)
        [!WS "0"!]/* end time out config */
        [!WS "0"!][!//Check Partition configuration is selected or not
        [!WS "0"!]#define FR_43_LLCE_MULTICORE_ENABLED                  [!IF "VendorSpecific/FrEnableMulticoreSupport = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!]
        [!WS "0"!]#define FR_43_LLCE_DEV_ERROR_DETECT                   ([!IF "'true' = text:tolower(node:value(FrDevErrorDetect))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
        [!WS "0"!]#define FR_43_LLCE_VERSION_INFO_API                   ([!IF "'true' = text:tolower(node:value(FrVersionInfoApi))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
        [!WS "0"!][!CR!]
        [!WS "0"!]#define FR_43_LLCE_PREPARE_LPDU_SUPPORT               ([!IF "'true' = text:tolower(node:value(FrPrepareLPduSupport))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
        [!WS "0"!]#define FR_43_LLCE_DISABLE_LPDU_SUPPORT               ([!IF "'true' = text:tolower(node:value(FrDisableLPduSupport))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
        [!WS "0"!]#define FR_43_LLCE_EXTENDED_LPDU_REPORTING            ([!IF "'true' = text:tolower(node:value(FrExtendedLPduReporting))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
        [!WS "0"!]#define FR_43_LLCE_RECONFIG_LPDU_SUPPORT              ([!IF "'true' = text:tolower(node:value(FrReconfigLPduSupport))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
        [!WS "0"!]#define FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS    ([!IF "VendorSpecific/FrDisableDemReportErrorStatus = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
        [!WS "0"!][!CR!]
        [!WS "0"!]/* Constants */
        [!WS "0"!]#define FR_43_LLCE_INSTANCE_ID_U8                     ((uint8)[!"FrIndex"!]U)
        [!WS "0"!]/* Maximum number of communication controllers that the driver supports */
        [!VAR "FrNumCtrlSupport" = "num:i(1)"!]
        [!WS "0"!]#define FR_43_LLCE_NUM_CTRL_SUPPORTED                 ([!"$FrNumCtrlSupport"!]U)
        [!WS "0"!]/* Maximum number of available message buffers */
        [!WS "0"!]#define FR_43_LLCE_NUMBER_MB                          (256U)
        [!WS "0"!]/* Maxmimum number of test iterations during controller initialization */
        [!WS "0"!]#define FR_43_LLCE_CTRL_TEST_COUNT                    ([!"num:i(FrCtrlTestCount)"!]U)
        [!VAR "FrEcucPartition" = "num:i(count(as:modconf('EcuC')[1]/EcucHardware/*[1]/EcucCoreDefinition/*))"!]
        [!WS "0"!]/* Maxmimum number of EcuC partition */
        [!IF "num:i(count(./FrEcucPartitionRef/*)) = '0'"!]
            [!VAR "FrEcucPartition" = "1"!]
            [!WS "0"!]#define FR_43_LLCE_ECUC_PARTITION                     (1U)
        [!ELSE!]
            [!WS "0"!]#define FR_43_LLCE_ECUC_PARTITION                     ([!"$FrEcucPartition"!]U)
        [!ENDIF!]
        [!WS "0"!][!CR!]
        [!WS "0"!]#define FR_43_LLCE_apInternalCfg \
            [!WS "4"!]static const Fr_43_LLCE_ConfigurationType* Fr_43_LLCE_apInternalCfg[FR_43_LLCE_ECUC_PARTITION] = \
            [!WS "4"!]{ \
        [!FOR "i" = "1" TO "$FrEcucPartition"!]
            [!WS "8"!]NULL_PTR[!IF " $i < $FrEcucPartition "!],[!ENDIF!] \[!CR!]
        [!ENDFOR!]
            [!WS "4"!]};
        [!WS "0"!][!CR!]
        [!WS "0"!]#define FR_43_LLCE_aeDriverStates \
            [!WS "4"!]Fr_43_LLCE_SoftwareStatesType Fr_43_LLCE_aeDriverStates[FR_43_LLCE_ECUC_PARTITION] = \
            [!WS "4"!]{ \
        [!FOR "i" = "1" TO "$FrEcucPartition"!]
            [!WS "8"!]FR_43_LLCE_STATE_UNINIT[!IF " $i < $FrEcucPartition "!],[!ENDIF!] \[!CR!]
        [!ENDFOR!]
            [!WS "4"!]};
        [!WS "0"!][!CR!]
        [!WS "0"!]#define FR_43_LLCE_abModuleEnablePermission \
            [!WS "4"!]boolean Fr_43_LLCE_abModuleEnablePermission[FR_43_LLCE_ECUC_PARTITION] = \
            [!WS "4"!]{ \
        [!FOR "i" = "1" TO "$FrEcucPartition"!]
            [!WS "8"!](boolean)TRUE[!IF " $i < $FrEcucPartition "!],[!ENDIF!] \[!CR!]
        [!ENDFOR!]
            [!WS "4"!]};
        [!WS "0"!][!CR!]
        [!WS "0"!]#define FR_43_LLCE_abCCActive \
            [!WS "4"!]boolean Fr_43_LLCE_abCCActive[FR_43_LLCE_NUM_CTRL_SUPPORTED] = \
            [!WS "4"!]{ \
        [!FOR "i" = "1" TO "$FrNumCtrlSupport"!]
            [!WS "8"!](boolean)FALSE[!IF " $i < $FrNumCtrlSupport "!],[!ENDIF!] \[!CR!]
        [!ENDFOR!]
            [!WS "4"!]};
        [!WS "0"!][!CR!]
    [!ENDSELECT!]
    [!WS "0"!][!//Sort the multiple configurations by their name at first
    [!LOOP "node:order(FrMultipleConfiguration,'node:name(.)')"!]
        [!WS "0"!][!//Sort the controllers by their name at first
        [!WS "0"!]/* Symbolic name for FrController and FrAbsoluteTimer */
        [!LOOP "node:order(FrController/*,'FrCtrlIdx','node:name(.)')"!]
            [!WS "0"!]#define FrConf_FrController_[!"node:name(.)"!]            ([!"node:value(FrCtrlIdx)"!]U)
            [!WS "0"!][!//Sort the timers by their name at first
            [!LOOP "node:order(FrAbsoluteTimer/*,'FrAbsTimerIdx','node:name(.)')"!]
                [!WS "0"!]#define FrConf_FrAbsoluteTimer_[!"node:name(.)"!]            ([!"node:value(FrAbsTimerIdx)"!]U)
            [!ENDLOOP!]
        [!ENDLOOP!]
    [!ENDLOOP!]
    [!WS "0"!][!CR!]
    [!WS "0"!]/* Extern declarations for configuration structures */
    [!WS "0"!]#define FR_43_LLCE_DEINIT_API                         (STD_ON)

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

#endif /* FR_43_LLCE_CFG_H */

[!ENDCODE!]

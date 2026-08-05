/**
*   @file    Can_43_LLCE_HeadlessCfg.c
*   @version 1.0.7
*
*   @brief   AUTOSAR Can_43_LLCE - module interface
*   @details Configuration Structures for PostBuild.
*
*   @addtogroup CAN_LLCE
*   @{
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : LLCE
*   Dependencies         : 
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 1.0.7
*   Build Version        : S32_RTD_1_0_7_D2909_ASR_REL_4_4_REV_0000_20230630
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
[!IF "not((node:exists(CanGeneral/CanLlceHeadlessModeUsed)) and (CanGeneral/CanLlceHeadlessModeUsed ='true'))"!]
    [!SKIPFILE!]
    /* Headless option not activated in driver. This file is not used */
[!ELSE!]
#ifdef __cplusplus
extern "C"{
#endif

#include "Llce_InterfaceCanTypes.h"
#include "Llce_Headless.h"

[!AUTOSPACING!]
[!INDENT "0"!]
[!NOCODE!]
[!INCLUDE "Can_43_LLCE_Macros.m"!][!//
[!ENDNOCODE!]

#define CAN_43_LLCE_MAX_IDMASK    (uint32)0x1FFFFFFFU
[!NOCODE!]
[!CALL "CountFilters"!]
[!VAR "AdvancedDestinationCount" = "count(as:modconf('Llce_Af')/LlceAfGeneral/CanAdvancedFeature/*)"!],
[!SELECT "CanConfigSet"!]
[!VAR "RegularFilterCount" = "0"!]
[!VAR "AdvancedFilterCount" = "0"!]
[!FOR "i" = "0" TO "15"!] 
    [!VAR "RegularFilterCount" = "num:i($RegularFilterCount) + num:i(text:split($GLOBAL_RX_FILTERCOUNT_LIST)[num:i($i+1)])"!]
    [!VAR "AdvancedFilterCount" = "num:i($AdvancedFilterCount) + num:i(text:split($GLOBAL_RXAF_FILTERCOUNT_LIST)[num:i($i+1)])"!]
[!ENDFOR!]
[!VAR "CONFIGURED_CONTROLLERS_COUNT" = "num:i(0)"!]
[!LOOP "CanController/*"!]
    [!IF "CanControllerActivation = 'true'"!]
        [!VAR "CONFIGURED_CONTROLLERS_COUNT"="num:i($CONFIGURED_CONTROLLERS_COUNT) + 1"!]
    [!ENDIF!]
[!ENDLOOP!]
[!ENDSELECT!]
[!ENDNOCODE!]

__attribute__((section(".llce_headlessconfig")))
volatile struct {
[!INDENT "2"!]
    Llce_Headless_Descriptor descriptor;
    Llce_Can_InitPlatformCmdType initPlatform;
    Llce_Can_InitCmdType initChannels[[!"num:i($CONFIGURED_CONTROLLERS_COUNT)"!]];
    Llce_Can_SetBaudrateCmdType baudrates[[!"num:i($CONFIGURED_CONTROLLERS_COUNT)"!]];
    [!IF "num:i($AdvancedDestinationCount) > 0"!]
    Can_Af_DestRulesType advancedDestinations[[!"num:i($AdvancedDestinationCount)"!]];
    [!ENDIF!]
    [!IF "num:i($RegularFilterCount) > 0"!]
    Llce_Can_ReceiveFilterType regularFilters[[!"num:i($RegularFilterCount)"!]];
    [!ENDIF!]
    [!IF "num:i($AdvancedFilterCount) > 0"!]
    Llce_Can_AdvancedFilterType advancedFilters[[!"num:i($AdvancedFilterCount)"!]];
    [!ENDIF!]
[!ENDINDENT!]
} LLCE__ALIGNED__PACKED Can_43_LLCE_HeadlessCfg = {
[!INDENT "2"!]
    /* Headless config descriptor */
    {
        [!INDENT "4"!]
        /** "Magic number" used to detect headless mode */
        LLCE_HEADLESSMODE_MAGICVALUE,
        /** Number of channels used */
        [!"num:i($CONFIGURED_CONTROLLERS_COUNT)"!]U, 
        /** Number of routing destinations used. Used for advanced filters */
        [!"num:i($AdvancedDestinationCount)"!]U, 
        /** Number of regular filters used */
        {[!//
        [!FOR "i" = "0" TO "15"!] 
            [!"num:i(text:split($GLOBAL_RX_FILTERCOUNT_LIST)[num:i($i+1)])"!]U, [!//
        [!ENDFOR!]
        },
        /** Number of advanced filters used */
        {[!//
        [!FOR "i" = "0" TO "15"!] 
            [!"num:i(text:split($GLOBAL_RXAF_FILTERCOUNT_LIST)[num:i($i+1)])"!]U, [!//
        [!ENDFOR!]
        }
        [!ENDINDENT!]
    },
    /* Platform init */
    {
        [!CALL "GeneratePlatformInit"!]
    },
    /* Channel init */
    {
        [!CALL "GenerateChannelInit", "SkipGenerateEmpty" = "1"!]
    },
    /* Default Baudrates */
    {
        [!FOR "crtBcan"="0" TO "15"!]
            [!LOOP "node:order(CanConfigSet/CanController/*,'node:value(CanControllerId)')"!][!//
                [!IF "substring-after(./CanHwChannel,'BCAN_') = $crtBcan "!]
                    [!VAR "CanClockSrc"="0"!]
                    [!IF "(node:exists(./CanCpuClockRef)) = 'true'"!]
                        [!VAR "CanClockSrc" = "node:ref(./CanCpuClockRef)/McuClockReferencePointFrequency"!]
                    [!ELSE!]
                        [!VAR "CanClockSrc" = "num:i(40000000)"!] [!/* Default Can Clock value 40 Mhz */!]
                    [!ENDIF!]
                    [!SELECT "node:ref(CanControllerDefaultBaudrate)"!]
                        [!CALL "GenerateBaudrate"!]
                    [!ENDSELECT!]
                [!ENDIF!]
            [!ENDLOOP!]
        [!ENDFOR!]
    },
    [!IF "num:i($AdvancedDestinationCount) > 0"!]
    /* Advanced destinations */
    {
        [!SELECT "as:modconf('Llce_Af')/LlceAfGeneral"!][!//
        [!CALL "GenerateAdvancedDestinations"!]    
        [!ENDSELECT!][!//
    },    
    [!ENDIF!]
    [!IF "num:i($RegularFilterCount) > 0"!]
    /* Regular filters */
    {
        [!FOR "crtCtrl" = "0" TO "15"!] 
        [!IF "text:split($GLOBAL_RX_FILTERCOUNT_LIST)[num:i($crtCtrl+1)] > 0"!]
            [!VAR "crtFilter" = "0"!]
            [!INDENT "4"!]     
                [!LOOP "node:order(CanConfigSet/CanHardwareObject/*,'node:value(CanObjectId)')"!]
                    [!IF "(node:ref(CanControllerRef)/CanControllerActivation = 'true') and (CanObjectType = 'RECEIVE') and (substring-after(node:ref(CanControllerRef)/CanHwChannel,'BCAN_') = num:i($crtCtrl)) and not(node:exists(CanAdvancedFeature))"!]
                        { /* Regular filter [!"num:i($crtFilter)"!] for BCAN_[!"num:i($crtCtrl)"!] */
                        [!CALL "GenerateFilterConfig"!]
                        },
                        [!VAR "crtFilter" = "$crtFilter+1"!]
                    [!ENDIF!]
                [!ENDLOOP!]
            [!ENDINDENT!]
        [!ENDIF!]
        [!ENDFOR!]
    },
    [!ENDIF!]
    [!IF "num:i($AdvancedFilterCount) > 0"!]  
    /* Advanced filters */
    {
        [!FOR "crtCtrl" = "0" TO "15"!] 
        [!IF "text:split($GLOBAL_RXAF_FILTERCOUNT_LIST)[num:i($crtCtrl+1)] > 0"!]
            [!VAR "crtFilter" = "0"!]
            [!INDENT "4"!]     
                [!LOOP "node:order(CanConfigSet/CanHardwareObject/*,'node:value(CanObjectId)')"!]
                    [!IF "(node:ref(CanControllerRef)/CanControllerActivation = 'true') and (CanObjectType = 'RECEIVE') and (substring-after(node:ref(CanControllerRef)/CanHwChannel,'BCAN_') = num:i($crtCtrl)) and node:exists(CanAdvancedFeature)"!]
                        [!CALL "GenerateAdvancedFilterConfig"!],
                        [!VAR "crtFilter" = "$crtFilter+1"!]
                    [!ENDIF!]
                [!ENDLOOP!]
            [!ENDINDENT!]
        [!ENDIF!]
        [!ENDFOR!]
    }
    [!ENDIF!]
[!ENDINDENT!]
};

[!ENDINDENT!]
#ifdef __cplusplus
}
#endif
[!ENDIF!]

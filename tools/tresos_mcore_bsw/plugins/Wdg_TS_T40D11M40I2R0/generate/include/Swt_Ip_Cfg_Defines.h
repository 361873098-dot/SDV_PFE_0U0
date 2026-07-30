/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Swt
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

#ifndef SWT_IP_CFG_DEFINES_H
#define SWT_IP_CFG_DEFINES_H

/**
*   @file
*
*   @addtogroup Swt
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

#include "StandardTypes.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SWT_IP_CFG_DEFINES_VENDOR_ID                    43
#define SWT_IP_CFG_DEFINES_MODULE_ID                    102
#define SWT_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define SWT_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     4
#define SWT_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define SWT_IP_CFG_DEFINES_SW_MAJOR_VERSION             4
#define SWT_IP_CFG_DEFINES_SW_MINOR_VERSION             0
#define SWT_IP_CFG_DEFINES_SW_PATCH_VERSION             2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and SchM_Wdg header file are of the same Autosar version */
    #if ((SWT_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
        (SWT_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Swt_Ip_Cfg_Defines.h and StandardTypes.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!INCLUDE "Wdg_PluginMacros.m"!][!//
[!VAR "CheckMultiCore" = "0"!][!//
[!VAR "WdgInstanceCount" = "0"!][!//
[!VAR "SwtClearResetRequest" = "0"!][!//

/**
* @brief  This constant specifies if the instance of the WDG is selected or not
*/
[!NOCODE!]
[!INDENT "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('./../../../Wdg','_43_Instance',$i)"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('./../../../','Wdg')"!]
    [!ENDIF!]

    [!IF "node:exists(concat($xPathModule,'/ELEMENTS/Wdg'))"!]
        [!VAR "WdgInstanceCount" = "$WdgInstanceCount+1"!]
        [!IF "node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgEnableMultiCoreSupport'))"!]
            [!VAR "CheckMultiCore" = "$CheckMultiCore+1"!]
        [!ENDIF!]
        [!CODE!]#define SWT_IP_ENABLE_INSTANCE[!"$i"!] (STD_ON)[!ENDCODE!][!CR!]
    [!ELSE!]
        [!CODE!]#define SWT_IP_ENABLE_INSTANCE[!"$i"!] (STD_OFF)[!ENDCODE!][!CR!]
    [!ENDIF!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

[!NOCODE!][!//
[!INDENT "0"!]
    [!VAR "isDirectServiceAvailable" = "1"!]
    [!VAR "checkVersionInforAPI" = "1"!]
    [!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
        [!IF "num:i($i) > 0"!]
            [!VAR "xPathModule" = "concat('./../../../Wdg','_43_Instance',$i)"!]
        [!ELSE!]
            [!VAR "xPathModule" = "concat('./../../../','Wdg')"!]
        [!ENDIF!]
        [!IF "node:exists(concat($xPathModule,'/ELEMENTS/Wdg'))"!]
            [!IF "node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgVersionInfoApi'))"!]
                [!VAR "checkVersionInforAPI" = "0"!]
            [!ENDIF!]

            [!VAR "getInitialTimeoutValue" = "node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgInitialTimeout'))"!]
            [!VAR "getTimeoutMaxValue" = "node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgMaxTimeout'))"!]

            [!IF "node:exists(concat($xPathModule,'/ELEMENTS/Wdg/WdgSettingsConfig/WdgExternalTriggerCounterRef'))"!]
                [!IF "node:ref(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgEnableDirectService'))='false'"!]
                    [!CALL "WdgCheckCbkNotification","WdgNo" = "$xPathModule","WdgName" = "$i"!]
                    [!VAR "isDirectServiceAvailable" = "0"!]
                    [!VAR "GptChannelInitialTickValue" = "(node:ref(node:value(node:ref(concat($xPathModule,'/ELEMENTS/Wdg/WdgSettingsConfig/WdgExternalTriggerCounterRef'))))/GptChannelTickFrequency)"!]
                    [!VAR "GptChannelTickValueMax" = "(node:ref(node:value(node:ref(concat($xPathModule,'/ELEMENTS/Wdg/WdgSettingsConfig/WdgExternalTriggerCounterRef'))))/GptChannelTickValueMax)"!]
                    [!IF "$getTimeoutMaxValue > ($GptChannelTickValueMax div $GptChannelInitialTickValue)"!]
                        [!ERROR!][!//
                        [!"'Must set Wdg Max Timeout [s] lest than or equal to '"!][!"$GptChannelTickValueMax div $GptChannelInitialTickValue"!]
                        [!ENDERROR!][!//
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
            [!CODE!]
            /**
            * @brief  These variables will indicate the Wdg Initial Timeout and Wdg Max Timeout parameters in miliseconds for Wdg module [!"$i"!]
            */
            #define SWT_IP_INSTANCE[!"$i"!]_INITIAL_TIMEOUT_U16 ((uint16)[!"num:i(node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgInitialTimeout')) * 1000)"!])
            #define SWT_IP_INSTANCE[!"$i"!]_MAX_TIMEOUT_U16 ((uint16)[!"num:i(node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgMaxTimeout')) * 1000)"!])
            [!ENDCODE!]
        [!ENDIF!]
    [!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

[!NOCODE!][!//
[!INDENT "0"!]

[!VAR "isWdgDevErrorDetectEnabled" = "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('./../../../Wdg','_43_Instance',$i)"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('./../../../','Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists(concat($xPathModule,'/ELEMENTS/Wdg'))"!]
        [!IF "node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgDevErrorDetect'))"!]
            [!VAR "isWdgDevErrorDetectEnabled" = "1"!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]

[!IF "num:i($isDirectServiceAvailable)=0"!]
    [!IF "num:i($isWdgDevErrorDetectEnabled)=1"!]
        [!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
            [!IF "num:i($i) > 0"!]
                [!VAR "xPathModule" = "concat('./../../../Wdg','_43_Instance',$i)"!]
            [!ELSE!]
                [!VAR "xPathModule" = "concat('./../../../','Wdg')"!]
            [!ENDIF!]
            [!IF "node:exists(concat($xPathModule,'/ELEMENTS/Wdg'))"!]
    
                [!VAR "getWdgSlowModeTimeoutValue" = "num:i(node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgSettingsConfig/WdgSettingsSlow/WdgTimeoutPeriod')) *1000)"!]
                [!VAR "getWdgFastModeTimeoutValue" = "num:i(node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgSettingsConfig/WdgSettingsFast/WdgTimeoutPeriod')) *1000)"!]
                [!VAR "getWdgOffModeTimeoutValue" = "num:i(0)"!]
    
            [!ELSE!]
                [!VAR "getWdgSlowModeTimeoutValue" = "num:i(0)"!]
                [!VAR "getWdgFastModeTimeoutValue" = "num:i(0)"!]
                [!VAR "getWdgOffModeTimeoutValue" = "num:i(0)"!]
            [!ENDIF!]
            [!IF "num:i($i)=0"!]
               [!CODE!][!//
               /**
               * @brief  This macros indicate the Wdg timeout value for Wdg module.
               */
               #define SWT_TIMEOUT_VALUE_ARRAY { {(uint32)[!"$getWdgOffModeTimeoutValue"!],(uint32)[!"$getWdgSlowModeTimeoutValue"!], (uint32)[!"$getWdgFastModeTimeoutValue"!]} \
               [!ENDCODE!]
            [!ELSE!]
               [!CODE!][!//
                   ,{(uint32)[!"$getWdgOffModeTimeoutValue"!],(uint32)[!"$getWdgSlowModeTimeoutValue"!], (uint32)[!"$getWdgFastModeTimeoutValue"!]} \
               [!ENDCODE!]
            [!ENDIF!]
        [!ENDFOR!]
        [!CODE!][!//
            }
        [!ENDCODE!]
    [!ENDIF!]
[!ENDIF!]
[!ENDINDENT!]
[!ENDNOCODE!][!//


/**
* @brief  Compile switch to allow/forbid disabling the Swt during runtime
*/
[!NOCODE!]
[!INDENT "0"!]
[!VAR "isWdgDisableForbid"     = "0"!]
[!VAR "isWdgDisableAllowed"    = "0"!][!//
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('./../../../Wdg','_43_Instance',$i)"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('./../../../','Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists(concat($xPathModule,'/ELEMENTS/Wdg'))"!]
        [!IF "node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgDisableAllowed'))"!]
            [!VAR "isWdgDisableAllowed" = "1"!]
            [!IF "num:i($isWdgDisableForbid) = 1"!]
                [!ERROR!]The "Wdg Disable Allowed" node must be enabled or disabled for all instances[!ENDERROR!]
                [!BREAK!]
            [!ENDIF!]
        [!ELSE!]
            [!VAR "isWdgDisableForbid" = "1"!]
            [!IF "num:i($isWdgDisableAllowed) = 1"!]
                [!ERROR!]The "Wdg Disable Allowed" node must be enabled or disabled for all instances[!ENDERROR!]
                [!BREAK!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]
[!CODE!]
/**
* @brief  This variable will indicate if the Wdg Disable Allowed feature is activated
*/
#define SWT_IP_DEINIT ([!IF "$isWdgDisableAllowed = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])[!ENDCODE!][!CR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

/**
* @brief  Defines indicating for which Swt instances the Direct Service Mode is supported
*/
[!NOCODE!]
[!INDENT "0"!]
[!VAR "isEnableDirectService"     = "0"!]
[!VAR "isDisableDirectService"    = "0"!][!//
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('./../../../Wdg','_43_Instance',$i)"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('./../../../','Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists(concat($xPathModule,'/ELEMENTS/Wdg'))"!]
        [!IF "node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgEnableDirectService'))"!]
            [!CODE!]#define SWT_IP_ENABLE_DIRECT_SERVICE_INSTANCE[!"$i"!] (STD_ON)[!ENDCODE!][!CR!]
            [!VAR "isEnableDirectService" = "1"!]
            [!IF "num:i($isDisableDirectService) = 1"!]
                [!ERROR!]The "Wdg Enable Direct Service" node must be enabled or disabled for all instances[!ENDERROR!]
                [!BREAK!]
            [!ENDIF!]
        [!ELSE!]
            [!CODE!]#define SWT_IP_ENABLE_DIRECT_SERVICE_INSTANCE[!"$i"!] (STD_OFF)[!ENDCODE!][!CR!]
            [!VAR "isDisableDirectService" = "1"!]
            [!IF "num:i($isEnableDirectService) = 1"!]
                [!ERROR!]The "Wdg Enable Direct Service" node must be enabled or disabled for all instances[!ENDERROR!]
                [!BREAK!]
            [!ENDIF!]
        [!ENDIF!]
    [!ELSE!]
        [!CODE!]#define SWT_IP_ENABLE_DIRECT_SERVICE_INSTANCE[!"$i"!] (STD_OFF)[!ENDCODE!][!CR!]
    [!ENDIF!]
[!ENDFOR!]
[!CODE!]
/**
* @brief  This variable will indicate if the Swt Direct Service feature is activated
*/
#define SWT_IP_ENABLE_DIRECT_SERVICE ([!IF "$isEnableDirectService = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])[!ENDCODE!][!CR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

/**
* @brief  This variable will indicate if the Wdg Development Error Detect feature is activated
*/
[!NOCODE!]
[!INDENT "0"!]
[!VAR "isEnableDevErrorDetect"     = "0"!]
[!VAR "isDisableDevErrorDetect"    = "0"!][!//
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('./../../../Wdg','_43_Instance',$i)"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('./../../../','Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists(concat($xPathModule,'/ELEMENTS/Wdg'))"!]
        [!IF "node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgDevErrorDetect'))"!]
            [!VAR "isEnableDevErrorDetect" = "1"!]
            [!IF "num:i($isDisableDevErrorDetect) = 1"!]
                [!ERROR!]The "Wdg Development Error Detect" node must be enabled or disabled for all instances[!ENDERROR!]
                [!BREAK!]
            [!ENDIF!]
        [!ELSE!]
            [!VAR "isDisableDevErrorDetect" = "1"!]
            [!IF "num:i($isEnableDevErrorDetect) = 1"!]
                [!ERROR!]The "Wdg Development Error Detect" node must be enabled or disabled for all instances[!ENDERROR!]
                [!BREAK!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]
[!CODE!]
#define SWT_IP_DEV_ERROR_DETECT ([!IF "$isEnableDevErrorDetect = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])[!ENDCODE!][!CR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//


/**
* @brief  Defines indicating for which Swt instances the Clear Reset Request feature is supported
*/
[!NOCODE!]
[!INDENT "0"!]
[!VAR "swtEnableClearResetRequest" = "0"!]
[!VAR "swtDisableClearResetRequest" = "0"!][!//
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('./../../../Wdg','_43_Instance',$i)"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('./../../../','Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists(concat($xPathModule,'/ELEMENTS/Wdg'))"!]
        [!IF "node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgDisableAllowed'))"!]
            [!IF "node:exists(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgEnableClearResetRequest'))"!]
                [!IF "node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgEnableClearResetRequest'))"!]
                    [!VAR "swtEnableClearResetRequest" = "1"!]
                    [!CODE!]#define SWT_IP_CLEAR_RESET_REQUEST_INSTANCE[!"$i"!] (STD_ON)[!ENDCODE!][!CR!]
                    [!IF "num:i($swtDisableClearResetRequest) = 1"!]
                        [!ERROR!]The "Wdg Enable Clear Reset Request" node must be enabled or disabled for all instances[!ENDERROR!]
                        [!BREAK!]
                    [!ENDIF!]
                [!ELSE!]
                    [!VAR "swtDisableClearResetRequest" = "1"!]
                    [!CODE!]#define SWT_IP_CLEAR_RESET_REQUEST_INSTANCE[!"$i"!] (STD_OFF)[!ENDCODE!][!CR!]
                    [!IF "num:i($swtEnableClearResetRequest) = 1"!]
                        [!ERROR!]The "Wdg Enable Clear Reset Request" node must be enabled or disabled for all instances[!ENDERROR!]
                        [!BREAK!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ELSE!]
                [!CODE!]#define SWT_IP_CLEAR_RESET_REQUEST_INSTANCE[!"$i"!] (STD_OFF)[!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ELSE!]
            [!CODE!]#define SWT_IP_CLEAR_RESET_REQUEST_INSTANCE[!"$i"!] (STD_OFF)[!ENDCODE!][!CR!]
        [!ENDIF!]
    [!ELSE!]
        [!CODE!]#define SWT_IP_CLEAR_RESET_REQUEST_INSTANCE[!"$i"!] (STD_OFF)[!ENDCODE!][!CR!]
    [!ENDIF!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//
[!CODE!]
/**
* @brief  This variable will indicate if the Clear Reset Request feature is activated
*/
#define SWT_IP_CLEAR_RESET_REQUEST ([!IF "$swtEnableClearResetRequest = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])[!ENDCODE!][!CR!]

[!CODE!][!CR!]
/**
* @brief  This variable will indicate if the ISR for SWT instances is used
*/[!ENDCODE!][!CR!]
[!NOCODE!]
[!INDENT "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('./../../../Wdg','_43_Instance',$i)"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('./../../../','Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists(concat($xPathModule,'/ELEMENTS/Wdg'))"!]
       [!IF "node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgSettingsConfig/WdgInterruptContentEnable'))"!]
           [!IF "node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgSettingsConfig/WdgSettingsFast/WdgOperationMode'))= 'Interrupt'"!]
               [!CODE!]#define SWT_IP_ISR[!"$i"!]_USED (STD_ON)[!ENDCODE!][!CR!]
           [!ELSEIF "node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgSettingsConfig/WdgSettingsSlow/WdgOperationMode'))= 'Interrupt'"!]
               [!CODE!]#define SWT_IP_ISR[!"$i"!]_USED (STD_ON)[!ENDCODE!][!CR!]
           [!ELSE!]
               [!CODE!]#define SWT_IP_ISR[!"$i"!]_USED (STD_OFF)[!ENDCODE!][!CR!]
           [!ENDIF!]
       [!ELSE!]
           [!CODE!]#define SWT_IP_ISR[!"$i"!]_USED (STD_OFF)[!ENDCODE!][!CR!]
       [!ENDIF!]        
    [!ELSE!]
        [!CODE!]#define SWT_IP_ISR[!"$i"!]_USED (STD_OFF)[!ENDCODE!][!CR!]
    [!ENDIF!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

[!NOCODE!]
[!INDENT "0"!]
[!VAR "isWdgTimeoutMethod1"     = "0"!]
[!VAR "isWdgTimeoutMethod2"     = "0"!]
[!VAR "isWdgTimeoutMethod3"     = "0"!]
[!VAR "isWdgOsifTimeoutVal0"     = "num:i(WdgGeneral/WdgOsifTimeoutVal)"!]
[!VAR "isWdgTimeoutMethod"     = "'OSIF_COUNTER_DUMMY'"!]
[!VAR "isWdgOsifTimeoutVal1"     = "3000"!]
[!VAR "isInstances"    = "0"!][!//

[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('./../../../Wdg','_43_Instance',$i)"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('./../../../','Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists(concat($xPathModule,'/ELEMENTS/Wdg'))"!]
        [!VAR "isWdgOsifTimeoutVal1"     = "num:i(node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgOsifTimeoutVal')))"!]
        [!IF "$isWdgOsifTimeoutVal1 != $isWdgOsifTimeoutVal0"!]
            [!ERROR!]The "Wdg Osif timeout value" node should be equal for all instances[!ENDERROR!]
            [!BREAK!]
        [!ENDIF!]
        [!VAR "isInstances" = "$isInstances+1"!]
        [!IF "node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgTimeoutMethod'))= 'OSIF_COUNTER_DUMMY'"!]
            [!VAR "isWdgTimeoutMethod"     = "'OSIF_COUNTER_DUMMY'"!]
            [!VAR "isWdgTimeoutMethod1" = "$isWdgTimeoutMethod1+1"!]
            [!IF "$isWdgTimeoutMethod1 != $isInstances"!]
                [!ERROR!]The "Wdg Osif Timeout Method" node must be enabled or disabled for all instances[!ENDERROR!]
                [!BREAK!]
            [!ENDIF!]
        [!ELSEIF "node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgTimeoutMethod'))= 'OSIF_COUNTER_SYSTEM'"!]
            [!VAR "isWdgTimeoutMethod"     = "'OSIF_COUNTER_SYSTEM'"!]
            [!VAR "isWdgTimeoutMethod2" = "$isWdgTimeoutMethod2+1"!]  
            [!IF "$isWdgTimeoutMethod2 != $isInstances"!]
                [!ERROR!]The "Wdg Osif Timeout Method" node must be enabled or disabled for all instances[!ENDERROR!]
                [!BREAK!]
            [!ENDIF!]
        [!ELSEIF "node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgTimeoutMethod'))= 'OSIF_COUNTER_CUSTOM'"!]
            [!VAR "isWdgTimeoutMethod"     = "'OSIF_COUNTER_CUSTOM'"!]
            [!VAR "isWdgTimeoutMethod3" = "$isWdgTimeoutMethod3+1"!]
            [!IF "$isWdgTimeoutMethod3 != $isInstances"!]
                [!ERROR!]The "Wdg Osif Timeout Method" node must be enabled or disabled for all instances[!ENDERROR!]
                [!BREAK!]
            [!ENDIF!]
        [!ELSE!]
                /* Do Nothing*/
        [!ENDIF!]
        [!VAR "isWdgOsifTimeoutVal($i)" = "node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgOsifTimeoutVal'))"!]
    [!ENDIF!]
[!ENDFOR!]
[!CODE!]
    /**
    * @brief  Define a certain timeout method from OsIf will be used in the driver.
    */
    #define SWT_IP_TIMEOUT_METHOD ([!"$isWdgTimeoutMethod"!])

    /**
    * @brief  This variable will indicate Wdg Osif timeout value for SWT instances is used
    */
    #define SWT_IP_OSIF_TIMEOUT_VAL        ([!"$isWdgOsifTimeoutVal1"!])

[!ENDCODE!]
[!ENDINDENT!]
[!ENDNOCODE!][!//


/**
* @brief  This variable will indicate RAM/ROM execution
*/

[!NOCODE!]
[!VAR "RunAreaROM" = "0"!]
[!VAR "RunAreaRAM" = "0"!]

[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('./../../../Wdg','_43_Instance',$i)"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('./../../../','Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists(concat($xPathModule,'/ELEMENTS/Wdg'))"!]
        [!IF "node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgRunArea')) = 'ROM'"!]
            [!VAR "RunAreaROM" = "1"!]
            [!IF "num:i($RunAreaRAM) = 1"!]
                [!ERROR!]The "WdgRunArea" must be either ROM or RAM for both enabled Wdg Instances[!ENDERROR!]
                [!BREAK!]
            [!ENDIF!]
        [!ELSE!]
            [!VAR "RunAreaRAM" = "1"!]
            [!IF "num:i($RunAreaROM) = 1"!]
                [!ERROR!]The "WdgRunArea" must be either ROM or RAM for both enabled Wdg Instances[!ENDERROR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]

[!IF "num:i($RunAreaROM) = 1"!]
    [!CODE!]#define WDG_ROM (1U)[!ENDCODE!]
[!ELSE!]
    [!CODE!]#define WDG_RAM (0U)[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

/**
 * @brief This constant specifies the minimum value that will be set in the SWT timeout register
 */
#define SWT_MIN_VALUE_TIMEOUT_U32 ((uint32)[!"num:inttohex(ecu:get('Swt.MinVal.TimeOut'))"!])

/**
 * @brief This constant define value of SWT_IP_RRR_SUPPORT
 */
[!NOCODE!]
[!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32g2') or contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32r45')"!][!// 
    [!CODE!]#define SWT_IP_RRR_SUPPORT_INSTANCE  (0x0000007EUL)[!ENDCODE!][!// 
[!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32g3')"!][!// 
    [!CODE!]#define SWT_IP_RRR_SUPPORT_INSTANCE  (0x00000FFEUL)[!ENDCODE!][!// 
[!ELSE!]
     /* Do Nothing*/
[!ENDIF!][!//
[!ENDNOCODE!] 
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

#endif /* SWT_IP_CFG_DEFINES_H */

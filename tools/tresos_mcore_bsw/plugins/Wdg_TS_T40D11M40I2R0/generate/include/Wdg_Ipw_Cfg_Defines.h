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


#ifndef WDG_IPW_CFG_DEFINES_H
#define WDG_IPW_CFG_DEFINES_H

/**
*   @file
*
*   @addtogroup  Wdg
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

#include "Swt_Ip_Cfg_Defines.h"

/*==================================================================================================
                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WDG_IPW_CFG_DEFINES_VENDOR_ID                    43
#define WDG_IPW_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define WDG_IPW_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     4
#define WDG_IPW_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define WDG_IPW_CFG_DEFINES_SW_MAJOR_VERSION             4
#define WDG_IPW_CFG_DEFINES_SW_MINOR_VERSION             0
#define WDG_IPW_CFG_DEFINES_SW_PATCH_VERSION             2

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

#if (WDG_IPW_CFG_DEFINES_VENDOR_ID != SWT_IP_CFG_DEFINES_VENDOR_ID)
#error "Wdg_Ipw_Cfg_Defines.h and Swt_Ip_Cfg_Defines.h have different vendor ids"
#endif

/* Check if current file and Swt_Ip_Cfg_Defines header file are of the same Autosar version */
#if ((WDG_IPW_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION   != SWT_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
    (WDG_IPW_CFG_DEFINES_AR_RELEASE_MINOR_VERSION    != SWT_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
    (WDG_IPW_CFG_DEFINES_AR_RELEASE_REVISION_VERSION != SWT_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Wdg_Ipw_Cfg_Defines.h and Swt_Ip_Cfg_Defines.h are different"
#endif

/* Check if current file and Swt_Ip_Cfg_Defines header file are of the same software version */
#if ((WDG_IPW_CFG_DEFINES_SW_MAJOR_VERSION != SWT_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
    (WDG_IPW_CFG_DEFINES_SW_MINOR_VERSION  != SWT_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
    (WDG_IPW_CFG_DEFINES_SW_PATCH_VERSION  != SWT_IP_CFG_DEFINES_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg_Ipw_Cfg_Defines.h and Swt_Ip_Cfg_Defines.h are different"
#endif

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

[!VAR "CheckMultiCore" = "0"!][!//
[!VAR "WdgInstanceCount" = "0"!][!//
/**
  * @brief  This constant specifies if the instance of the WDG is selected or not
  */
[!NOCODE!]
[!INDENT "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!CODE!]#define WDG_IPW_ENABLE_INSTANCE[!"$i"!]      (SWT_IP_ENABLE_INSTANCE[!"$i"!])[!ENDCODE!][!CR!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

/**
* @brief  Compile switch to allow/forbid disabling the watchdog driver during runtime
*/
#define WDG_IPW_DEINIT    (SWT_IP_DEINIT)

/**
* @brief  This variable will which Wdg instances can be serviced directly
*/
[!NOCODE!]
[!INDENT "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!CODE!]#define WDG_IPW_ENABLE_DIRECT_SERVICE_INSTANCE[!"$i"!] (SWT_IP_ENABLE_DIRECT_SERVICE_INSTANCE[!"$i"!])[!ENDCODE!][!CR!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

#define WDG_IPW_DIRECT_SERVICE (SWT_IP_ENABLE_DIRECT_SERVICE)

/**
* @brief  This variable will indicate if the ISR for WDG instances is used
*/
[!NOCODE!]
[!INDENT "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!CODE!]#define WDG_IPW_ISR[!"$i"!]_USED (SWT_IP_ISR[!"$i"!]_USED)[!ENDCODE!][!CR!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

/**
* @brief  This variable will indicate which Wdg instance support the Clear Reset Request feature
*/
[!NOCODE!]
[!INDENT "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!CODE!]#define WDG_IPW_CLEAR_RESET_REQUEST_INSTANCE[!"$i"!] (SWT_IP_CLEAR_RESET_REQUEST_INSTANCE[!"$i"!])[!ENDCODE!][!CR!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

#define WDG_IPW_CLEAR_RESET_REQUEST (SWT_IP_CLEAR_RESET_REQUEST)

/**
* @brief  Compile switch to enable development error detection
*/
#define WDG_IPW_DEV_ERROR_DETECT (SWT_IP_DEV_ERROR_DETECT)


[!NOCODE!][!//
[!INDENT "0"!]
    [!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
        [!IF "num:i($i) > 0"!]
            [!VAR "xPathModule" = "concat('./../../../Wdg','_43_Instance',$i)"!]
        [!ELSE!]
            [!VAR "xPathModule" = "concat('./../../../','Wdg')"!]
        [!ENDIF!]
        [!IF "node:exists(concat($xPathModule,'/ELEMENTS/Wdg'))"!]
            [!CODE!]
            /**
            * @brief  These variables will indicate the Wdg Initial Timeout and Wdg Max Timeout parameters in miliseconds for Wdg module [!"$i"!]
            */
            #define WDG_IPW_INSTANCE[!"$i"!]_INITIAL_TIMEOUT_U16 (SWT_IP_INSTANCE[!"$i"!]_INITIAL_TIMEOUT_U16)
            #define WDG_IPW_INSTANCE[!"$i"!]_MAX_TIMEOUT_U16 (SWT_IP_INSTANCE[!"$i"!]_MAX_TIMEOUT_U16)
            [!ENDCODE!]
        [!ENDIF!]
    [!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

[!NOCODE!]
[!INDENT "0"!]
    [!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
        [!IF "num:i($i) > 0"!]
            [!VAR "xPathModule" = "concat('./../../../Wdg','_43_Instance',$i)"!]
        [!ELSE!]
            [!VAR "xPathModule" = "concat('./../../../','Wdg')"!]
        [!ENDIF!]
        [!IF "node:exists(concat($xPathModule,'/ELEMENTS/Wdg'))"!]
            [!IF "node:ref(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgEnableDirectService'))='false' and node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgDevErrorDetect'))='true'"!]
                [!CODE!]
                /**
                * @brief  This macros indicate the Wdg timeout value for Wdg module.
                */
                #define WDG_IPW_TIMEOUT_VALUE_ARRAY SWT_TIMEOUT_VALUE_ARRAY
                [!ENDCODE!]
                [!BREAK!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDFOR!]
[!ENDINDENT!]
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

#endif /* WDG_IPW_CFG_DEFINES_H */

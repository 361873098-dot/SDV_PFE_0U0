/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : SIUL2
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

/**
*   @file    Siul2_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!][!ENDIF!]_PBcfg.c
*
*   @addtogroup Port_CFG
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
#include "Siul2_Port_Ip.h"
[!NOCODE!][!//
[!/* Include package file in order to get valid Pins */!][!//
[!IF "((ecu:get('Port.Derivative'))='S32G2')"!][!//
    [!INCLUDE "Port_S32G2_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='S32G3')"!][!//
    [!INCLUDE "Port_S32G3_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='S32R')"!][!//
    [!INCLUDE "Port_S32R_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Derivative'))='S32V')"!][!//
    [!INCLUDE "Port_S32V_Resource.m"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_PORT_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C                       43
#define SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C        4
#define SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C        4
#define SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C     0
#define SIUL2_PORT_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C                4
#define SIUL2_PORT_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C                0
#define SIUL2_PORT_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C                2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Siul2_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Siul2_Port_Ip.h are of the same vendor */
#if (SIUL2_PORT_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != SIUL2_PORT_IP_VENDOR_ID_H)
    #error "Siul2_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Siul2_Port_Ip.h have different vendor ids"
#endif
/* Check if Siul2_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Siul2_Port_Ip.h are of the same Autosar version */
#if ((SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C    != SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C    != SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Siul2_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Siul2_Port_Ip.h are different"
#endif

/* Check if Siul2_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Siul2_Port_Ip.h are of the same software version */
#if ((SIUL2_PORT_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != SIUL2_PORT_IP_SW_MAJOR_VERSION_H) || \
     (SIUL2_PORT_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != SIUL2_PORT_IP_SW_MINOR_VERSION_H) || \
     (SIUL2_PORT_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != SIUL2_PORT_IP_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Siul2_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Siul2_Port_Ip.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

[!VAR "base_IP" = "0"!][!//
[!VAR "pinSiul2Instance_IP" = "'0'"!][!//
[!VAR "pinPortIdx_IP" = "0"!][!//
[!VAR "mux_value_IP" = "0"!][!//
[!VAR "mux_IP" = "'PORT_MUX_AS_GPIO'"!][!//
[!VAR "safeMode_IP" = "'PORT_SAFE_MODE_DISABLED'"!][!//
[!VAR "pullConfig_IP" = "'PORT_INTERNAL_PULL_NOT_ENABLED'"!][!//
[!VAR "pullKeep_IP" = "'PORT_PULL_KEEP_DISABLED'"!][!//
[!VAR "invert_IP" = "'PORT_INVERT_DISABLED'"!][!//
[!VAR "slewRateCtrlSel_IP" = "'PORT_SLEW_RATE_CONTROL0'"!][!//
[!VAR "receiverSel_IP" = "'PORT_RECEIVER_ENABLE_DIFFERENTIAL_VREF'"!][!//
[!VAR "openDrain_IP" = "'PORT_OPEN_DRAIN_DISABLED'"!][!//
[!VAR "inputBuffer_IP" = "'PORT_INPUT_BUFFER_DISABLED'"!][!//
[!VAR "outputBuffer_IP" = "'PORT_OUTPUT_BUFFER_DISABLED'"!][!//
[!VAR "initValue_IP" = "'0'"!][!//
[!VAR "inputMuxReg_IP" = "'0'"!][!//
[!VAR "inputMux0_IP" = "'PORT_INPUT_MUX_NO_INIT'"!][!//
[!VAR "inputMux1_IP" = "'PORT_INPUT_MUX_NO_INIT'"!][!//
[!VAR "inputMux2_IP" = "'PORT_INPUT_MUX_NO_INIT'"!][!//
[!VAR "inputMux3_IP" = "'PORT_INPUT_MUX_NO_INIT'"!][!//
[!VAR "inputMux4_IP" = "'PORT_INPUT_MUX_NO_INIT'"!][!//
[!VAR "inputMux5_IP" = "'PORT_INPUT_MUX_NO_INIT'"!][!//
[!VAR "inputMux6_IP" = "'PORT_INPUT_MUX_NO_INIT'"!][!//
[!VAR "inputMux7_IP" = "'PORT_INPUT_MUX_NO_INIT'"!][!//

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

[!MACRO "GetAltConf_IP"!][!//
[!NOCODE!][!//
[!/* Alternative Mode 0 is the GPIO */!][!//
[!IF "text:match(./PortPinMode,'GPIO')"!][!//
    [!VAR "OutPinAltFunc_IP"="0"!]!//
[!ELSE!][!//
    [!VAR "MacPinMode_IP"="concat(./PortPinSiul2Instance, '_PORT',number(./PortPinPcr), '_', ./PortPinMode,';')"!][!//
    [!VAR "OutPinAltFunc_IP"="number(substring-before(substring-after($PinMap,$MacPinMode_IP),':'))"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!MACRO "GetAltInputConf_IP"!][!//
[!NOCODE!][!//
[!/* Alternative Mode 0 is the GPIO */!][!//
[!IF "text:match(./PortPinMode,'GPIO')"!][!//
    [!VAR "inputMuxReg_IP" = "'0'"!][!//
    [!VAR "inputMux0_IP" = "'PORT_INPUT_MUX_NO_INIT'"!][!//
[!ELSE!][!//
    [!VAR "MacPinMode_IP"="concat(./PortPinSiul2Instance, '_PORT',number(./PortPinPcr), '_', ./PortPinMode,';')"!][!//

    [!VAR "InPinImcrSiulNumber_IP"="number(substring-after(substring-before((substring-after($PinMap,$MacPinMode_IP)),'@'),':'))"!][!//
    [!VAR "InPinImcrRegNumber_IP"="number(substring-after(substring-before((substring-after($PinMap,$MacPinMode_IP)),'^'),'@'))"!][!//
    [!VAR "OutPinAltFunc_IP"="number(substring-before(substring-after($PinMap,$MacPinMode_IP),':'))"!][!//
    [!IF "($InPinImcrSiulNumber_IP = 65535)"!][!//
        [!VAR "inputMuxReg_IP" = "'0'"!][!//
        [!VAR "inputMux0_IP" = "'PORT_INPUT_MUX_NO_INIT'"!][!//
    [!ELSE!][!//
        [!VAR "InPinAltFunc_IP"="number(substring-after(substring-before((substring-after($PinMap,$MacPinMode_IP)),'~'),'^'))"!][!//
        [!VAR "inputMux0_IP" = "concat('PORT_INPUT_MUX_ALT',num:i($InPinAltFunc_IP))"!][!//
        [!IF "($InPinImcrSiulNumber_IP = 1)"!][!//
        [!VAR "inputMuxReg_IP" = "num:i($InPinImcrRegNumber_IP + 512)"!][!//
        [!ELSE!][!//
        [!VAR "inputMuxReg_IP" = "num:i($InPinImcrRegNumber_IP)"!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!MACRO "CalculateSSS_IO_IP"!][!//
[!NOCODE!][!//
[!CALL "GetAltConf_IP"!][!//
[!IF "($OutPinAltFunc_IP >= 15)"!][!//
    [!/* Pin is in input/output mode */!][!//
    [!VAR "mux_value_IP" = "$OutPinAltFunc_IP - 14"!][!//
    [!VAR "outputBuffer_IP" = "'PORT_OUTPUT_BUFFER_ENABLED'"!][!//
    [!VAR "inputBuffer_IP" = "'PORT_INPUT_BUFFER_ENABLED'"!][!//
[!ELSEIF "($OutPinAltFunc_IP >= 7)"!][!//
    [!/* Pin is in 'input' mode. Set IBE bit */!][!//
    [!VAR "mux_value_IP" = "0"!][!//
    [!VAR "outputBuffer_IP" = "'PORT_OUTPUT_BUFFER_DISABLED'"!][!//
    [!VAR "inputBuffer_IP" = "'PORT_INPUT_BUFFER_ENABLED'"!][!//
[!ELSEIF "($OutPinAltFunc_IP > 0)"!][!//
    [!/* Pin is output. Set output params: SSS field in MSCR and Safe Mode */!][!//
    [!VAR "mux_value_IP" = "$OutPinAltFunc_IP"!][!//
    [!VAR "outputBuffer_IP" = "'PORT_OUTPUT_BUFFER_ENABLED'"!][!//
    [!VAR "inputBuffer_IP" = "'PORT_INPUT_BUFFER_DISABLED'"!][!//
[!ELSE!][!//
    [!/* The pin is configured as GPIO. Look in the PortPinDirection combo for port direction */!][!//
    [!VAR "mux_value_IP" = "0"!][!//
    [!IF "text:match(./PortPinDirection,'PORT_PIN_INOUT')"!][!//
        [!VAR "outputBuffer_IP" = "'PORT_OUTPUT_BUFFER_ENABLED'"!][!//
        [!VAR "inputBuffer_IP" = "'PORT_INPUT_BUFFER_ENABLED'"!][!//
    [!ELSEIF "text:match(./PortPinDirection,'PORT_PIN_OUT')"!][!//
        [!VAR "outputBuffer_IP" = "'PORT_OUTPUT_BUFFER_ENABLED'"!][!//
        [!VAR "inputBuffer_IP" = "'PORT_INPUT_BUFFER_DISABLED'"!][!//
    [!ELSEIF "text:match(./PortPinDirection,'PORT_PIN_IN')"!][!//
        [!VAR "outputBuffer_IP" = "'PORT_OUTPUT_BUFFER_DISABLED'"!][!//
        [!VAR "inputBuffer_IP" = "'PORT_INPUT_BUFFER_ENABLED'"!][!//
    [!ELSE!][!//
        [!/* Pad is configured as high-z. Clear IBE and OBE bit */!][!//
        [!VAR "outputBuffer_IP" = "'PORT_OUTPUT_BUFFER_DISABLED'"!][!//
        [!VAR "inputBuffer_IP" = "'PORT_INPUT_BUFFER_DISABLED'"!][!//
    [!ENDIF!][!//
[!ENDIF!][!//

[!/* Check if read status is enabled */!][!//
[!IF "./PortPinWithReadBack"!][!//
    [!VAR "inputBuffer_IP" = "'PORT_INPUT_BUFFER_ENABLED'"!][!//
[!ENDIF!][!//

[!IF "($mux_value_IP = 0)"!][!//
[!VAR "mux_IP" = "'PORT_MUX_AS_GPIO'"!][!//
[!ELSEIF "($mux_value_IP = 1)"!][!//
[!VAR "mux_IP" = "'PORT_MUX_ALT1'"!][!//
[!ELSEIF "($mux_value_IP = 2)"!][!//
[!VAR "mux_IP" = "'PORT_MUX_ALT2'"!][!//
[!ELSEIF "($mux_value_IP = 3)"!][!//
[!VAR "mux_IP" = "'PORT_MUX_ALT3'"!][!//
[!ELSEIF "($mux_value_IP = 4)"!][!//
[!VAR "mux_IP" = "'PORT_MUX_ALT4'"!][!//
[!ELSEIF "($mux_value_IP = 5)"!][!//
[!VAR "mux_IP" = "'PORT_MUX_ALT5'"!][!//
[!ELSEIF "($mux_value_IP = 6)"!][!//
[!VAR "mux_IP" = "'PORT_MUX_ALT6'"!][!//
[!ELSEIF "($mux_value_IP = 7)"!][!//
[!VAR "mux_IP" = "'PORT_MUX_ALT7'"!][!//
[!ENDIF!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!MACRO "GetPDO_IP"!][!//
[!NOCODE!][!//
[!IF "not(contains(node:fallback(./PortPinMode,'ADC'),'ADC'))"!][!//
    [!IF "text:match(./PortPinLevelValue,'PORT_PIN_LEVEL_LOW')"!][!//
        [!VAR "MacPinPDO_IP"="'0'"!][!//
    [!ELSEIF "text:match(./PortPinLevelValue,'PORT_PIN_LEVEL_HIGH')"!][!//
        [!VAR "MacPinPDO_IP"="'1'"!][!//
    [!ELSEIF "text:match(./PortPinLevelValue,'PORT_PIN_LEVEL_NOTCHANGED')"!][!//
        [!VAR "MacPinPDO_IP"="'2'"!][!//
    [!ELSE!]
        [!/*don't anything*/!]
    [!ENDIF!][!//
[!ELSE!][!//
    [!VAR "MacPinPDO_IP"="'2'"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!VAR "initValue_IP" = "$MacPinPDO_IP"!][!//
[!ENDMACRO!][!//
[!MACRO "GetPinData_IP"!][!//
[!NOCODE!][!//
[!VAR "base_IP" = "./PortPinSiul2Instance"!][!//
[!IF "($base_IP = 'SIUL2_0')"!][!//
    [!VAR "pinSiul2Instance_IP" ="'0'"!][!//
[!ELSEIF "($base_IP = 'SIUL2_1')"!][!//
    [!VAR "pinSiul2Instance_IP" ="'1'"!][!//
[!ELSEIF "($base_IP = 'SIUL2_AE')"!][!//
    [!VAR "pinSiul2Instance_IP" ="'2'"!][!//
[!ENDIF!][!//
[!VAR "pinPortIdx_IP" = "./PortPinPcr"!][!//
[!CALL "CalculateSSS_IO_IP"!][!//
[!IF "./PortPinSafeMode"!][!//
    [!VAR "safeMode_IP" = "'PORT_SAFE_MODE_ENABLED'"!][!//
[!ELSE!][!//
    [!VAR "safeMode_IP" = "'PORT_SAFE_MODE_DISABLED'"!][!//
[!ENDIF!][!//
[!/* RCVR bit */!][!//
[!/* The 1833 and GPIO33 pad types do not support Receiver Select in S32R platform */!][!//
[!IF "((ecu:get('Port.Derivative'))='S32R')"!]
    [!/* If the pad types is GPIO18 */!][!//
    [!IF "text:match(./PortPinSlewRate,'SRE_1_8V_208MHZ') or text:match(./PortPinSlewRate,'SRE_1_8V_150MHZ') or text:match(./PortPinSlewRate,'SRE_1_8V_133MHZ') or text:match(./PortPinSlewRate,'SRE_1_8V_100MHZ') or text:match(./PortPinSlewRate,'SRE_1_8V_50MHZ')"!][!//
        [!IF "./PortPinRcvr"!][!//
            [!VAR "receiverSel_IP"="'PORT_RECEIVER_ENABLE_SINGLE_ENDED'"!][!//
        [!ELSE!][!//
            [!VAR "receiverSel_IP"="'PORT_RECEIVER_ENABLE_DIFFERENTIAL_VREF'"!][!//
        [!ENDIF!][!//
    [!/* The pad types is 1833 or GPIO33 */!][!//
    [!ELSE!][!//
        [!VAR "receiverSel_IP"="'PORT_RECEIVER_ENABLE_DIFFERENTIAL_VREF'"!][!//
    [!ENDIF!][!//
[!ELSE!][!//
    [!VAR "receiverSel_IP"="'PORT_RECEIVER_ENABLE_DIFFERENTIAL_VREF'"!][!//
[!ENDIF!][!//
[!/* ODE bit */!][!//
[!IF "./PortPinOde"!][!//
    [!VAR "openDrain_IP" = "'PORT_OPEN_DRAIN_ENABLED'"!][!//
[!ELSE!][!//
    [!VAR "openDrain_IP" = "'PORT_OPEN_DRAIN_DISABLED'"!][!//
[!ENDIF!][!//
[!IF "./PortPinPue"!][!//
    [!IF "./PortPinPus"!][!//
        [!VAR "pullConfig_IP" = "'PORT_INTERNAL_PULL_UP_ENABLED'"!][!//
    [!ELSE!][!//
        [!VAR "pullConfig_IP" = "'PORT_INTERNAL_PULL_DOWN_ENABLED'"!][!//
    [!ENDIF!][!//
[!ELSE!][!//
    [!VAR "pullConfig_IP" = "'PORT_INTERNAL_PULL_NOT_ENABLED'"!][!//
[!ENDIF!][!//
[!VAR "pullKeep_IP" = "'PORT_PULL_KEEP_DISABLED'"!][!//
[!VAR "invert_IP" = "'PORT_INVERT_DISABLED'"!][!//

[!/* SRE bits */!][!//
[!IF "text:match(./PortPinSlewRate,'SRE_208MHZ_1_8V_166MHZ_3_3V')"!][!//
    [!VAR "slewRateCtrlSel_IP" = "'PORT_SLEW_RATE_CONTROL0'"!][!//
[!ELSEIF "text:match(./PortPinSlewRate,'SRE_166MHZ_1_8V_150MHZ_3_3V')"!][!//
    [!VAR "slewRateCtrlSel_IP" = "'PORT_SLEW_RATE_CONTROL4'"!][!//
[!ELSEIF "text:match(./PortPinSlewRate,'SRE_150MHZ_1_8V_133MHZ_3_3V')"!][!//
    [!VAR "slewRateCtrlSel_IP" = "'PORT_SLEW_RATE_CONTROL5'"!][!//
[!ELSEIF "text:match(./PortPinSlewRate,'SRE_133MHZ_1_8V_100MHZ_3_3V')"!][!//
    [!VAR "slewRateCtrlSel_IP" = "'PORT_SLEW_RATE_CONTROL6'"!][!//
[!ELSEIF "text:match(./PortPinSlewRate,'SRE_100MHZ_1_8V_83MHZ_3_3V')"!][!//
    [!VAR "slewRateCtrlSel_IP" = "'PORT_SLEW_RATE_CONTROL7'"!][!//
[!ELSEIF "text:match(./PortPinSlewRate,'SRE_1_8V_208MHZ')"!][!//
    [!VAR "slewRateCtrlSel_IP" = "'PORT_SLEW_RATE_CONTROL0'"!][!//
[!ELSEIF "text:match(./PortPinSlewRate,'SRE_1_8V_150MHZ')"!][!//
    [!VAR "slewRateCtrlSel_IP" = "'PORT_SLEW_RATE_CONTROL4'"!][!//
[!ELSEIF "text:match(./PortPinSlewRate,'SRE_1_8V_133MHZ')"!][!//
    [!VAR "slewRateCtrlSel_IP" = "'PORT_SLEW_RATE_CONTROL5'"!][!//
[!ELSEIF "text:match(./PortPinSlewRate,'SRE_1_8V_100MHZ')"!][!//
    [!VAR "slewRateCtrlSel_IP" = "'PORT_SLEW_RATE_CONTROL6'"!][!//
[!ELSEIF "text:match(./PortPinSlewRate,'SRE_1_8V_50MHZ')"!][!//
    [!VAR "slewRateCtrlSel_IP" = "'PORT_SLEW_RATE_CONTROL7'"!][!//
[!ELSEIF "./PortPinSlewRate = 'SRE_3_3V_50MHZ_b100'"!][!//
    [!VAR "slewRateCtrlSel_IP" = "'PORT_SLEW_RATE_CONTROL4'"!][!//
[!ELSEIF "./PortPinSlewRate = 'SRE_3_3V_50MHZ_b101'"!][!//
    [!VAR "slewRateCtrlSel_IP" = "'PORT_SLEW_RATE_CONTROL5'"!][!//
[!ELSEIF "./PortPinSlewRate = 'SRE_3_3V_50MHZ_b110'"!][!//
    [!VAR "slewRateCtrlSel_IP" = "'PORT_SLEW_RATE_CONTROL6'"!][!//
[!ELSEIF "text:match(./PortPinSlewRate,'SRE_3_3V_1MHZ')"!][!//
    [!VAR "slewRateCtrlSel_IP" = "'PORT_SLEW_RATE_CONTROL7'"!][!//
[!ENDIF!][!//

[!CALL "GetAltInputConf_IP"!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

[!INDENT "0"!][!//
    const Siul2_Port_Ip_PinSettingsConfig g_pin_mux_InitConfigArr[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][NUM_OF_CONFIGURED_PINS] =
[!ENDINDENT!][!//
{
[!SELECT "PortConfigSet"!][!//
[!VAR "count"= "1"!][!//
[!VAR "Maxcount"= "num:i(count(PortContainer/*/PortPin/*))-1"!][!//
[!LOOP "PortContainer/*/PortPin/*"!][!//
[!CALL "GetPinData_IP"!][!//
[!CALL "GetPDO_IP"!][!//
[!IF "$Maxcount>=$count"!][!//
    {
        .base                        = [!"concat('IP_',$base_IP)"!],
        .pinPortIdx                  = [!"$pinPortIdx_IP"!],
        .mux                         = [!"$mux_IP"!],
        .safeMode                    = [!"$safeMode_IP"!],
        .pullConfig                  = [!"$pullConfig_IP"!],
        .slewRateCtrlSel             = [!"$slewRateCtrlSel_IP"!],
[!IF "((ecu:get('Port.Derivative'))='S32R')"!][!//
        .receiverSel                 = [!"$receiverSel_IP"!],
[!ENDIF!][!//
        .openDrain                   = [!"$openDrain_IP"!],
        .inputBuffer                 = [!"$inputBuffer_IP"!],
        .outputBuffer                = [!"$outputBuffer_IP"!],
        .initValue                   = [!"$initValue_IP"!],
        .inputMuxReg                 = {
                                         [!"$inputMuxReg_IP"!]
                                       },
        .inputMux                    = {
                                         [!"$inputMux0_IP"!],
                                         [!"$inputMux1_IP"!],
                                         [!"$inputMux2_IP"!],
                                         [!"$inputMux3_IP"!],
                                         [!"$inputMux4_IP"!],
                                         [!"$inputMux5_IP"!],
                                         [!"$inputMux6_IP"!],
                                         [!"$inputMux7_IP"!]
                                       }
    },
[!ELSE!][!//
    {
        .base                        = [!"concat('IP_',$base_IP)"!],
        .pinPortIdx                  = [!"$pinPortIdx_IP"!],
        .mux                         = [!"$mux_IP"!],
        .safeMode                    = [!"$safeMode_IP"!],
        .pullConfig                  = [!"$pullConfig_IP"!],
        .slewRateCtrlSel             = [!"$slewRateCtrlSel_IP"!],
[!IF "((ecu:get('Port.Derivative'))='S32R')"!][!//
        .receiverSel                 = [!"$receiverSel_IP"!],
[!ENDIF!][!//
        .openDrain                   = [!"$openDrain_IP"!],
        .inputBuffer                 = [!"$inputBuffer_IP"!],
        .outputBuffer                = [!"$outputBuffer_IP"!],
        .initValue                   = [!"$initValue_IP"!],
        .inputMuxReg                 = {
                                         [!"$inputMuxReg_IP"!]
                                       },
        .inputMux                    = {
                                         [!"$inputMux0_IP"!],
                                         [!"$inputMux1_IP"!],
                                         [!"$inputMux2_IP"!],
                                         [!"$inputMux3_IP"!],
                                         [!"$inputMux4_IP"!],
                                         [!"$inputMux5_IP"!],
                                         [!"$inputMux6_IP"!],
                                         [!"$inputMux7_IP"!]
                                       }
    }
[!ENDIF!][!//
[!VAR "count"= "$count+1"!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
};

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
[!CODE!][!//
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
*   @file    Port_PBcfg.c
*
*   @implements Port_PBcfg.c_Artifact
*   @addtogroup Port_CFG
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/
#include "Port.h"
[!NOCODE!][!//
[!INCLUDE "Port_VersionCheck_Src_PB.m"!][!//
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

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
#define PORT_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C 43
#define PORT_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C 4
#define PORT_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C 4
#define PORT_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C 0
#define PORT_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C 4
#define PORT_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C 0
#define PORT_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C 2

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/
/* Check if Port_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Port.h are of the same vendor */
#if (PORT_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != PORT_VENDOR_ID)
    #error "Port_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Port.h have different vendor ids"
#endif
/* Check if Port_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Port.h are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C    != PORT_AR_RELEASE_MAJOR_VERSION) || \
     (PORT_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C    != PORT_AR_RELEASE_MINOR_VERSION) || \
     (PORT_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != PORT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Port_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Port.h are different"
#endif

/* Check if Port_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Port.h are of the same software version */
#if ((PORT_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != PORT_SW_MAJOR_VERSION) || \
     (PORT_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != PORT_SW_MINOR_VERSION) || \
     (PORT_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != PORT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Port_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Port.h are different"
#endif
/*=================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
=================================================================================================*/

/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/

/*=================================================================================================
*                                      LOCAL CONSTANTS
=================================================================================================*/
[!NOCODE!][!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO GetAltConf                                 */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the Alternative Mode configuration for selected pin */!][!//
[!MACRO "GetAltConf"!][!//
[!NOCODE!][!//
[!/* Alternative Mode 0 is the GPIO */!][!//
[!IF "text:match(./PortPinMode,'GPIO')"!][!//
    [!VAR "OutPinAltFunc"="0"!]
[!ELSE!][!//
    [!VAR "MacPinMode"="concat(./PortPinSiul2Instance, '_PORT',number(./PortPinPcr), '_', ./PortPinMode,';')"!][!//
    [!VAR "OutPinAltFunc"="number(substring-before(substring-after($PinMap,$MacPinMode),':'))"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO GetMscrSiul2Instance                       */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the Siul instance for MSCR */!][!//
[!MACRO "GetMscrSiul2Instance"!][!//
[!NOCODE!][!//
[!VAR "OutPinMscrSiul2Instance"="0"!][!//
[!FOR "LoopCounter" = "1" TO "num:i(count(ecu:list('Port.Siul2Instances')))"!][!//
    [!VAR "MacCurSiul2InstanceName"="ecu:list('Port.Siul2Instances')[num:i($LoopCounter)]"!][!//
    [!IF "text:match(./PortPinSiul2Instance,$MacCurSiul2InstanceName)"!][!//
        [!BREAK!][!//
    [!ENDIF!][!//
    [!VAR "OutPinMscrSiul2Instance"="$OutPinMscrSiul2Instance + 1"!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
PORT_[!"ecu:list('Port.Siul2Instances')[num:i($OutPinMscrSiul2Instance + 1)]"!]_U8[!//
[!ENDMACRO!][!//
[!//
[!/*****************************************************************************/!][!//
[!/*                            MACRO GetMSCR                                  */!][!//
[!/*****************************************************************************/!][!//
[!/* Fill the MSCR register for the selected pin */!][!//
[!MACRO "GetMSCR"!][!//
[!NOCODE!][!//
[!/* OBE bit */!][!//
[!VAR "MacMscrObe"="bit:shl(1,21)"!][!//
[!/* IBE bit */!][!//
[!VAR "MacMscrIbe"="bit:shl(1,19)"!][!//
[!/* ODE bit. Check if ODE is enabled */!][!//
[!IF "./PortPinOde"!][!//
    [!VAR "MacMscrOde"="bit:shl(1,20)"!][!//
[!ELSE!][!//
    [!VAR "MacMscrOde"="0"!][!//
[!ENDIF!][!//
[!/* PUE bit. Check if PUE is enabled */!][!//
[!IF "./PortPinPue"!][!//
    [!VAR "MacMscrPue"="bit:shl(1,13)"!][!//
[!ELSE!][!//
    [!VAR "MacMscrPue"="0"!][!//
[!ENDIF!][!//
[!/* PUS bit. Check if PUS is enabled */!][!//
[!IF "./PortPinPus"!][!//
    [!VAR "MacMscrPus"="bit:shl(1,12)"!][!//
[!ELSE!][!//
    [!VAR "MacMscrPus"="0"!][!//
[!ENDIF!][!//
[!/* SMC bit. Check if SMC is enabled */!][!//
[!IF "./PortPinSafeMode"!][!//
    [!VAR "MacMscrSmc"="bit:shl(1,5)"!][!//
[!ELSE!][!//
    [!VAR "MacMscrSmc"="0"!][!//
[!ENDIF!][!//

[!/* SRE bitfield. Get the selected value */!][!//
[!IF "text:match(./PortPinSlewRate,'SRE_208MHZ_1_8V_166MHZ_3_3V')"!][!//
    [!VAR "MacMscrSre"="bit:shl(0,14)"!][!//
[!ELSEIF "text:match(./PortPinSlewRate,'SRE_166MHZ_1_8V_150MHZ_3_3V')"!][!//
    [!VAR "MacMscrSre"="bit:shl(4,14)"!][!//
[!ELSEIF "text:match(./PortPinSlewRate,'SRE_150MHZ_1_8V_133MHZ_3_3V')"!][!//
    [!VAR "MacMscrSre"="bit:shl(5,14)"!][!//
[!ELSEIF "text:match(./PortPinSlewRate,'SRE_133MHZ_1_8V_100MHZ_3_3V')"!][!//
    [!VAR "MacMscrSre"="bit:shl(6,14)"!][!//
[!ELSEIF "text:match(./PortPinSlewRate,'SRE_100MHZ_1_8V_83MHZ_3_3V')"!][!//
    [!VAR "MacMscrSre"="bit:shl(7,14)"!][!//
[!ELSEIF "text:match(./PortPinSlewRate,'SRE_1_8V_208MHZ')"!][!//
    [!VAR "MacMscrSre"="bit:shl(0,14)"!][!//
[!ELSEIF "text:match(./PortPinSlewRate,'SRE_1_8V_150MHZ')"!][!//
    [!VAR "MacMscrSre"="bit:shl(4,14)"!][!//
[!ELSEIF "text:match(./PortPinSlewRate,'SRE_1_8V_133MHZ')"!][!//
    [!VAR "MacMscrSre"="bit:shl(5,14)"!][!//
[!ELSEIF "text:match(./PortPinSlewRate,'SRE_1_8V_100MHZ')"!][!//
    [!VAR "MacMscrSre"="bit:shl(6,14)"!][!//
[!ELSEIF "text:match(./PortPinSlewRate,'SRE_1_8V_50MHZ')"!][!//
    [!VAR "MacMscrSre"="bit:shl(7,14)"!][!//
[!ELSEIF "./PortPinSlewRate = 'SRE_3_3V_50MHZ_b100'"!][!//
    [!VAR "MacMscrSre"="bit:shl(4,14)"!][!//
[!ELSEIF "./PortPinSlewRate = 'SRE_3_3V_50MHZ_b101'"!][!//
    [!VAR "MacMscrSre"="bit:shl(5,14)"!][!//
[!ELSEIF "./PortPinSlewRate = 'SRE_3_3V_50MHZ_b110'"!][!//
    [!VAR "MacMscrSre"="bit:shl(6,14)"!][!//
[!ELSEIF "text:match(./PortPinSlewRate,'SRE_3_3V_1MHZ')"!][!//
    [!VAR "MacMscrSre"="bit:shl(7,14)"!][!//
[!ENDIF!][!//

[!/* RCVR bit */!][!//
[!/* The 1833 and GPIO33 pad types do not support Receiver Select in S32R platform */!][!//
[!IF "((ecu:get('Port.Derivative'))='S32R')"!]
    [!/* If the pad types is GPIO18 */!][!//
    [!IF "text:match(./PortPinSlewRate,'SRE_1_8V_208MHZ') or text:match(./PortPinSlewRate,'SRE_1_8V_150MHZ') or text:match(./PortPinSlewRate,'SRE_1_8V_133MHZ') or text:match(./PortPinSlewRate,'SRE_1_8V_100MHZ') or text:match(./PortPinSlewRate,'SRE_1_8V_50MHZ')"!][!//
        [!IF "./PortPinRcvr"!][!//
            [!VAR "MacMscrRcvr"="bit:shl(1,10)"!][!//
        [!ELSE!][!//
            [!VAR "MacMscrRcvr"="0"!][!//
        [!ENDIF!][!//
    [!/* The pad types is 1833 or GPIO33 */!][!//
    [!ELSE!][!//
        [!VAR "MacMscrRcvr"="0"!][!//
    [!ENDIF!][!//
[!ELSE!][!//
    [!VAR "MacMscrRcvr"="0"!][!//
[!ENDIF!][!//

[!VAR "MacPinMSCR"="num:i(0)"!][!//
[!/* Get the Alternative Mode configuration and fill the PCR */!][!//
[!CALL "GetAltConf"!][!//
[!IF "($OutPinAltFunc >= 15)"!][!//
    [!/* Pin is in input/output mode */!][!//
    [!/* Set first output params: SSS field in MSCR, Safe Mode and OBE */!][!//
    [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl($OutPinAltFunc - 14,0))"!][!//
    [!/* Set SafeMode bit for pin */!][!//
    [!VAR "MacPinMSCR"="bit:or($MacPinMSCR, $MacMscrSmc)"!][!//
    [!/* Set then input params: IBE */!][!//
    [!VAR "MacPinMSCR"="bit:or($MacPinMSCR, $MacMscrIbe)"!][!//
    [!/* Set then output params: OBE */!][!//
    [!VAR "MacPinMSCR"="bit:or($MacPinMSCR, $MacMscrObe)"!][!//
[!ELSEIF "($OutPinAltFunc >= 7)"!][!//
    [!/* Pin is in 'only input' or 'input' mode. Set IBE bit */!][!//
    [!VAR "MacPinMSCR"="bit:or($MacPinMSCR, $MacMscrIbe)"!][!//
[!ELSEIF "($OutPinAltFunc = 7)"!][!//
    [!/* Pin is in 'only input' or 'input' mode. Set IBE bit */!][!//
    [!VAR "MacPinMSCR"="bit:or($MacPinMSCR, $MacMscrIbe)"!][!//
    [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(0,21))"!][!//
[!ELSEIF "($OutPinAltFunc > 0)"!][!//
    [!/* Pin is output. Set output params: SSS field in MSCR, Safe Mode and OBE */!][!//
    [!VAR "MacPinMSCR"="bit:or($MacPinMSCR, $OutPinAltFunc)"!][!//
    [!/* Set SafeMode bit for pin */!][!//
    [!VAR "MacPinMSCR"="bit:or($MacPinMSCR, $MacMscrSmc)"!][!//
    [!/* Set then output params: OBE */!][!//
    [!VAR "MacPinMSCR"="bit:or($MacPinMSCR, $MacMscrObe)"!][!//
[!ELSE!][!//
    [!/* The pin is configured as GPIO. Look in the PortPinDirection combo for port direction */!][!//
    [!IF "text:match(./PortPinDirection,'PORT_PIN_INOUT')"!][!//
        [!/* Pad is configured as input-output. Set IBE and OBE */!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR, $MacMscrIbe)"!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR, $MacMscrObe)"!][!//
        [!/* Set SafeMode bit for pin */!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR, $MacMscrSmc)"!][!//
    [!ELSEIF "text:match(./PortPinDirection,'PORT_PIN_OUT')"!][!//
        [!/* Pad is configured as output. Set OBE */!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR, $MacMscrObe)"!][!//
        [!/* Set SafeMode bit for pin */!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR, $MacMscrSmc)"!][!//
    [!ELSEIF "text:match(./PortPinDirection,'PORT_PIN_IN')"!][!//
        [!/* Pad is configured as input. Set IBE bit */!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR, $MacMscrIbe)"!][!//
    [!ELSE!][!//
        [!/* Pad is configured as high-z. Clear IBE and OBE bit */!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(0,19))"!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(0,21))"!][!//
    [!ENDIF!][!//
[!ENDIF!][!//

[!/* Check if read status is enabled */!][!//
[!IF "./PortPinWithReadBack"!][!//
    [!VAR "MacPinMSCR"="bit:or($MacPinMSCR, $MacMscrIbe)"!][!//
[!ENDIF!][!//

[!IF "./PortPinOde"!][!//
    [!VAR "MacPinMSCR"="bit:or($MacPinMSCR, $MacMscrOde)"!][!//
    [!/* OBE bit field also is set to enable open drain.*/!][!//
    [!VAR "MacPinMSCR"="bit:or($MacPinMSCR, $MacMscrObe)"!][!//
[!ENDIF!][!//
[!VAR "MacPinMSCR"="bit:or($MacPinMSCR, $MacMscrPue)"!][!//
[!VAR "MacPinMSCR"="bit:or($MacPinMSCR, $MacMscrPus)"!][!//
[!VAR "MacPinMSCR"="bit:or($MacPinMSCR, $MacMscrSre)"!][!//
[!VAR "MacPinMSCR"="bit:or($MacPinMSCR, $MacMscrRcvr)"!][!//
[!ENDNOCODE!][!//
[!"num:inttohex($MacPinMSCR,8)"!][!//
[!ENDMACRO!][!//

[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                            MACRO GetUnusedMSCR                            */!][!//
[!/*****************************************************************************/!][!//
[!/* Fill the MSCR register for the unused pins */!][!//
[!MACRO "GetUnusedMSCR"!][!//
[!NOCODE!][!//
[!VAR "MacConfigREG"="num:i(0)"!][!//
[!/* Check if the pin is configured as input or output */!][!//
[!IF "text:match(./PortPinDirection,'PORT_PIN_OUT')"!][!//
    [!VAR "MacConfigREG"="bit:or($MacConfigREG,bit:shl(1,21))"!][!//
[!ELSEIF "text:match(./PortPinDirection,'PORT_PIN_IN')"!][!//
    [!VAR "MacConfigREG"="bit:or($MacConfigREG,bit:shl(1,19))"!][!//
[!ENDIF!][!//

[!/* Check if weak pull up/down is enabled */!][!//
[!IF "./PortPinPue"!][!//
    [!VAR "MacConfigREG"="bit:or($MacConfigREG,bit:shl(1,13))"!][!//
[!ENDIF!][!//

[!/* Check whether weak pull-up or weak pull-down is selected */!][!//
[!IF "./PortPinPus"!][!//
    [!VAR "MacConfigREG"="bit:or($MacConfigREG,bit:shl(1,12))"!][!//
[!ENDIF!][!//

[!ENDNOCODE!][!//
[!"num:inttohex($MacConfigREG,8)"!][!//
[!ENDMACRO!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                            MACRO GetPDO                                   */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the output status for selected pin */!][!//
[!MACRO "GetPDO"!][!//
[!NOCODE!][!//
[!IF "not(contains(node:fallback(./PortPinMode,'ADC'),'ADC'))"!][!//
    [!IF "text:match(./PortPinLevelValue,'PORT_PIN_LEVEL_LOW')"!][!//
        [!VAR "MacPinPDO"="num:i(0)"!][!//
    [!ELSEIF "text:match(./PortPinLevelValue,'PORT_PIN_LEVEL_HIGH')"!][!//
        [!VAR "MacPinPDO"="num:i(1)"!][!//
    [!ELSEIF "text:match(./PortPinLevelValue,'PORT_PIN_LEVEL_NOTCHANGED')"!][!//
        [!VAR "MacPinPDO"="num:i(2)"!][!//
    [!ELSE!]
        [!/*don't anything*/!]
    [!ENDIF!][!//
[!ELSE!][!//
    [!VAR "MacPinPDO"="num:i(2)"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$MacPinPDO"!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                            MACRO GetPDDir                                 */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the direction to be set for selected pin */!][!//
[!MACRO "GetPDDir"!][!//
[!NOCODE!][!//
[!IF "text:match(./PortPinMode,'ADC')"!][!//
    [!VAR "MacPinPDDir"="'PORT_PIN_IN'"!][!//
[!ELSE!][!//
    [!VAR "MacPinPDDir"="./PortPinDirection"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$MacPinPDDir"!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO GetGPIO                                    */!][!//
[!/*****************************************************************************/!][!//
[!/* Set the initial GPIO Mode for selected pin */!][!//
[!MACRO "GetGPIO"!][!//
[!NOCODE!][!//
[!IF "text:match(./PortPinMode,'GPIO')"!][!//
    [!VAR "MacGPIOMode"= "string('(boolean)TRUE')"!][!//
[!ELSE!][!//
    [!VAR "MacGPIOMode"= "string('(boolean)FALSE')"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$MacGPIOMode"!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO GetDirConf                                 */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the Alternative Mode configuration for selected pin */!][!//
[!MACRO "GetDirConf"!][!//
[!NOCODE!][!//
[!IF "(./PortPinMode = 'GPIO')"!][!//
    [!IF "./PortPinDirectionChangeable"!][!//
        [!VAR "MacDirection"= "string('(boolean)TRUE')"!][!//
    [!ELSE!][!//
        [!VAR "MacDirection"= "string('(boolean)FALSE')"!][!//
    [!ENDIF!][!//
[!ELSE!][!//
    [!VAR "MacDirection"= "string('(boolean)FALSE')"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$MacDirection"!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO GetModeChang                               */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "GetModeChang"!][!//
[!NOCODE!][!//
[!IF "./PortPinModeChangeable"!][!//
    [!VAR "MacModeChang"= "string('(boolean)TRUE')"!][!//
[!ELSE!][!//
    [!VAR "MacModeChang"= "string('(boolean)FALSE')"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$MacModeChang"!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO IsImcrAvailable                               */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "IsImcrAvailable"!][!//
[!NOCODE!][!//
[!CALL "GetAltConf"!][!//
[!IF "($OutPinAltFunc >= 8)"!][!//
    [!VAR "TempImcrAvail"= "string('(boolean)TRUE')"!][!//
[!ELSE!][!//
    [!VAR "TempImcrAvail"= "string('(boolean)FALSE')"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$TempImcrAvail"!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO GetIMCR                               */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "GetIMCR"!][!//
[!NOCODE!][!//
[!IF "text:match(./PortPinMode,'GPIO')"!][!//
    [!VAR "OutImcrIndex"="num:i(65535)"!]
[!ELSE!][!//
    [!VAR "TempPinMap"="concat(./PortPinSiul2Instance, '_PORT',number(./PortPinPcr), '_', ./PortPinMode)"!][!//
    [!VAR "OutImcrIndex"="num:i(substring-after(substring-before((substring-after($PinMap,concat($TempPinMap,';'))),'^'),'@'))"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$OutImcrIndex"!][!//
[!ENDMACRO!][!//
[!ENDNOCODE!][!//
[!/*****************************************************************************/!][!//
[!SELECT "PortConfigSet"!][!//
#define PORT_START_SEC_CONFIG_DATA_8
#include "Port_MemMap.h"

[!/* The number of configured partition on the platform */!][!//
[!NOCODE!][!//
[!VAR "maxPartition" = "num:i(0)"!][!//
[!IF "node:value(../PortGeneral/PortMulticoreSupport)='true'"!]
    [!IF "node:exists(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition)"!][!//
        [!VAR "maxPartition" = "num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!IF "$maxPartition = 0"!][!//
    [!VAR "maxPartition" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
/**
* @brief Array containing list of partition which used in driver
*/
const uint8 au8Port_PartitionList[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PORT_MAX_PARTITION] =
{
[!INDENT "4"!][!//
[!VAR "CounterPortEcucPartitionRef"="num:i(count(../PortGeneral/PortEcucPartitionRef/*))"!][!//
[!FOR "index" = "0" TO "num:i($maxPartition) - 1"!][!//
    [!VAR "PartitionExist"="0"!][!//
    [!LOOP "../PortGeneral/PortEcucPartitionRef/*"!][!//
        [!VAR "PortCrtPart" = "node:value(.)"!][!//
        [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
            [!IF "$PortCrtPart = node:value(./OsAppEcucPartitionRef)"!][!//
                [!SELECT "node:ref(./OsApplicationCoreRef)"!][!//
                [!IF "$index = node:value(./EcucCoreId)"!][!//
                    [!VAR "PartitionExist"="1"!][!//
                [!ENDIF!][!//
                [!ENDSELECT!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ENDLOOP!][!//
    [!IF "$CounterPortEcucPartitionRef = 0"!][!//
        [!VAR "PartitionExist"="1"!][!//
        [!VAR "CounterPortEcucPartitionRef"="num:i($CounterPortEcucPartitionRef + 1)"!][!//
    [!ENDIF!][!//
    [!CODE!][!//
        [!"num:i($PartitionExist)"!][!IF "$index < num:i($maxPartition) - 1"!],[!ENDIF!]
    [!ENDCODE!][!//
[!ENDFOR!][!//
[!ENDINDENT!][!//
};

#define PORT_STOP_SEC_CONFIG_DATA_8
#include "Port_MemMap.h"

#define PORT_START_SEC_CONFIG_DATA_32
#include "Port_MemMap.h"
/**
* @brief Array containing list of mapping information for mappable elements
*/
static const uint32 au32Port_PinToPartitionMap[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PORT_MAX_CONFIGURED_PADS_U16] =
{
[!INDENT "4"!][!//
[!FOR "x" = "1" TO "num:i(count(PortContainer/*/PortPin/*))"!][!//
    [!VAR "CounterPortEcucPartitionRef"="num:i(count(../PortGeneral/PortEcucPartitionRef/*))"!][!//
    [!VAR "PartitionValue"="0"!][!//
    [!VAR "GetThePartitionNumber"="0"!][!//
    [!LOOP "PortContainer/*/PortPin/*"!][!//
        [!IF "PortPinId = $x"!][!//
            [!LOOP "PortPinEcucPartitionRef/*"!][!//
                [!VAR "PortCrtPart" = "node:value(.)"!][!//
                [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
                    [!IF "$PortCrtPart = node:value(./OsAppEcucPartitionRef)"!][!//
                        [!SELECT "node:ref(./OsApplicationCoreRef)"!][!//
                            [!VAR "GetThePartitionNumber"="node:value(./EcucCoreId)"!][!//
                            [!VAR "PartitionValue"="bit:or($PartitionValue,(bit:shl(1,$GetThePartitionNumber)))"!][!//
                        [!ENDSELECT!][!//
                    [!ENDIF!][!//
                [!ENDLOOP!][!//
            [!ENDLOOP!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!IF "$CounterPortEcucPartitionRef = 0"!][!//
        [!VAR "PartitionValue"="1"!][!//
        [!VAR "CounterPortEcucPartitionRef"="num:i($CounterPortEcucPartitionRef + 1)"!][!//
    [!ENDIF!][!//
    [!CODE!][!//
        (uint32)[!"num:inttohex($PartitionValue, 8)"!][!IF "$x < num:i(count(PortContainer/*/PortPin/*))"!],[!ENDIF!]
    [!ENDCODE!][!//
[!ENDFOR!][!//
[!ENDINDENT!][!//
};

#define PORT_STOP_SEC_CONFIG_DATA_32
#include "Port_MemMap.h"

#if (PORT_MAX_UNUSED_PADS_U16 != 0U)

#define PORT_START_SEC_CONFIG_DATA_16
#include "Port_MemMap.h"

/**
* @brief Array containing list of MSCRs that are not used and should be configured with values from NotUsedPortPin container
*/
static const Port_Siul2_UnUsedPinType Port_aUnusedPads[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PORT_MAX_UNUSED_PADS_U16] =
{
[!NOCODE!]
[!VAR "counter"="0"!][!//
[!FOR "LoopCounter" = "1" TO "num:i(count(ecu:list('Port.Siul2Instances')))"!][!//
    [!VAR "MscrIdxStart"="ecu:list('Port.Siul2InstanceMscrIdxStart')[num:i($LoopCounter)]"!][!//
    [!VAR "MscrIdxEnd"="ecu:list('Port.Siul2InstanceMscrIdxEnd')[num:i($LoopCounter)]"!][!//
    [!FOR "x" = "$MscrIdxStart" TO "$MscrIdxEnd"!][!//
        [!VAR "PinUsed"="0"!][!//
        [!LOOP "PortContainer/*/PortPin/*"!][!//
            [!IF "$PinUsed=0"!][!//
                [!IF "num:i(./PortPinPcr)=$x and ./PortPinSiul2Instance = ecu:list('Port.Siul2Instances')[num:i($LoopCounter)]"!][!//
                    [!VAR "PinUsed"="$PinUsed + 1"!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
        [!LOOP "UnTouchedPortPin/*"!][!//
            [!IF "$PinUsed=0"!][!//
                [!IF "num:i(./PortPinPcr)=$x and ./PortPinSiul2Instance = ecu:list('Port.Siul2Instances')[num:i($LoopCounter)]"!][!//
                    [!VAR "PinUsed"="$PinUsed + 1"!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
        [!IF "$PinUsed=0"!][!//
            [!VAR "resourceName" = "concat('Port.Siul2Instance',num:i($LoopCounter - 1),'NotImplementedMscrs')"!][!//
            [!IF "contains(concat(',',string(ecu:get($resourceName)),','),concat(',',$x,','))"!][!//
                [!VAR "PinUsed"="$PinUsed + 1"!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
        [!IF "$PinUsed=0"!][!//
            [!VAR "resourceName" = "concat('Port.Siul2Instance',num:i($LoopCounter - 1),'AdcPins')"!][!//
            [!IF "contains(concat(',',string(ecu:get($resourceName)),','),concat(',',$x,','))"!][!//
                [!VAR "PinUsed"="$PinUsed + 1"!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
        [!IF "$PinUsed=0"!][!//
            [!IF "$counter=0"!][!//
[!CODE!][!//
    { (uint16)[!"$x"!], PORT_[!"ecu:list('Port.Siul2Instances')[num:i($LoopCounter)]"!]_U8 }[!//
[!ENDCODE!][!//
            [!ELSE!][!//
[!CODE!][!//
,
    { (uint16)[!"$x"!], PORT_[!"ecu:list('Port.Siul2Instances')[num:i($LoopCounter)]"!]_U8 }[!//
[!ENDCODE!][!//
            [!ENDIF!][!//
            [!VAR "counter"= "$counter+1"!][!//
        [!ENDIF!][!//
    [!ENDFOR!][!//
[!ENDFOR!][!//
[!ENDNOCODE!]
};

#define PORT_STOP_SEC_CONFIG_DATA_16
#include "Port_MemMap.h"

#endif /* (PORT_MAX_UNUSED_PADS_U16 != 0) */
[!ENDSELECT!][!//


#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

[!/*****************************************************************************/!][!//
[!SELECT "PortConfigSet"!][!//
[!VAR "counter"="0"!][!//
/**
 * @brief Default Configuration for Pins not initialized
 */
static const Port_Siul2_UnUsedPinConfigType Port_UnusedPinConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /**
    * @note: Configuration of Default pin
    */
    [!LOOP "NotUsedPortPin"!][!/*
        */!](uint32)[!CALL "GetUnusedMSCR"!], (uint8)[!CALL "GetPDO"!]
    [!ENDLOOP!]
};
[!ENDSELECT!][!//

[!/*****************************************************************************/!][!//
[!SELECT "PortConfigSet"!][!//
[!VAR "count"= "1"!][!//
[!VAR "Maxcount"= "num:i(count(PortContainer/*/PortPin/*))-1"!][!//
[!VAR "LoopVar"="1"!][!//
[!VAR "counter"="0"!][!//
/**
* @brief Pin default configuration data for configPB
*/
static const Port_Siul2_PinConfigType Port_aUsedPinConfigs[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PORT_MAX_CONFIGURED_PADS_U16]=
{
[!NOCODE!]
[!FOR "x" = "0" TO "num:i(count(PortContainer/*/PortPin/*))"!][!//
    [!LOOP "PortContainer/*/PortPin/*"!][!//
        [!VAR "Loop"="num:i($LoopVar)"!][!//
        [!IF "PortPinId = $Loop"!][!//
            [!IF "$Maxcount>=$count"!][!//
[!CODE!][!//
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    {(uint16)[!"./PortPinPcr"!], (uint32)[!CALL "GetMSCR"!], (uint8)[!CALL "GetMscrSiul2Instance"!], (uint8)[!CALL "GetPDO"!], [!CALL "GetPDDir"!], [!CALL "GetGPIO"!], [!CALL "GetDirConf"!], [!CALL "GetModeChang"!], [!CALL "IsImcrAvailable"!], [!CALL "GetIMCR"!]},
[!ENDCODE!][!//
            [!ELSE!][!//
[!CODE!][!//
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    {(uint16)[!"./PortPinPcr"!], (uint32)[!CALL "GetMSCR"!], (uint8)[!CALL "GetMscrSiul2Instance"!], (uint8)[!CALL "GetPDO"!], [!CALL "GetPDDir"!], [!CALL "GetGPIO"!], [!CALL "GetDirConf"!], [!CALL "GetModeChang"!], [!CALL "IsImcrAvailable"!], [!CALL "GetIMCR"!]}
[!ENDCODE!][!//
            [!ENDIF!][!//
            [!VAR "count"= "$count+1"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!VAR "LoopVar"="$LoopVar + 1"!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
};
[!ENDSELECT!][!//


[!/*****************************************************************************/!][!//
[!SELECT "PortConfigSet"!][!//
[!IF "num:i(count(ecu:list('Port.Siul2Instances'))) > 0"!][!//
/* SIUL2_0 */
[!VAR "siul2Instance"="1"!][!//
/**
* @brief IMCR configuration set by Port_Init() for SIUL2 instance: [!"ecu:list('Port.Siul2Instances')[num:i($siul2Instance)]"!]
*/
static const Port_Siul2_ImcrConfigType Port_a[!"ecu:list('Port.Siul2Instances')[num:i($siul2Instance)]"!]_ImcrInitConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PORT_[!"ecu:list('Port.Siul2Instances')[num:i($siul2Instance)]"!]_NUM_IMCRS_U16]=
{
[!NOCODE!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 0)"!][!VAR "cINMUX0"="255"!][!ELSE!][!VAR "cINMUX0"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 1)"!][!VAR "cINMUX1"="255"!][!ELSE!][!VAR "cINMUX1"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 2)"!][!VAR "cINMUX2"="255"!][!ELSE!][!VAR "cINMUX2"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 3)"!][!VAR "cINMUX3"="255"!][!ELSE!][!VAR "cINMUX3"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 4)"!][!VAR "cINMUX4"="255"!][!ELSE!][!VAR "cINMUX4"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 5)"!][!VAR "cINMUX5"="255"!][!ELSE!][!VAR "cINMUX5"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 6)"!][!VAR "cINMUX6"="255"!][!ELSE!][!VAR "cINMUX6"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 7)"!][!VAR "cINMUX7"="255"!][!ELSE!][!VAR "cINMUX7"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 8)"!][!VAR "cINMUX8"="255"!][!ELSE!][!VAR "cINMUX8"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 9)"!][!VAR "cINMUX9"="255"!][!ELSE!][!VAR "cINMUX9"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 10)"!][!VAR "cINMUX10"="255"!][!ELSE!][!VAR "cINMUX10"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 11)"!][!VAR "cINMUX11"="255"!][!ELSE!][!VAR "cINMUX11"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 12)"!][!VAR "cINMUX12"="255"!][!ELSE!][!VAR "cINMUX12"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 13)"!][!VAR "cINMUX13"="255"!][!ELSE!][!VAR "cINMUX13"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 14)"!][!VAR "cINMUX14"="255"!][!ELSE!][!VAR "cINMUX14"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 15)"!][!VAR "cINMUX15"="255"!][!ELSE!][!VAR "cINMUX15"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 16)"!][!VAR "cINMUX16"="255"!][!ELSE!][!VAR "cINMUX16"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 17)"!][!VAR "cINMUX17"="255"!][!ELSE!][!VAR "cINMUX17"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 18)"!][!VAR "cINMUX18"="255"!][!ELSE!][!VAR "cINMUX18"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 19)"!][!VAR "cINMUX19"="255"!][!ELSE!][!VAR "cINMUX19"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 20)"!][!VAR "cINMUX20"="255"!][!ELSE!][!VAR "cINMUX20"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 21)"!][!VAR "cINMUX21"="255"!][!ELSE!][!VAR "cINMUX21"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 22)"!][!VAR "cINMUX22"="255"!][!ELSE!][!VAR "cINMUX22"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 23)"!][!VAR "cINMUX23"="255"!][!ELSE!][!VAR "cINMUX23"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 24)"!][!VAR "cINMUX24"="255"!][!ELSE!][!VAR "cINMUX24"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 25)"!][!VAR "cINMUX25"="255"!][!ELSE!][!VAR "cINMUX25"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 26)"!][!VAR "cINMUX26"="255"!][!ELSE!][!VAR "cINMUX26"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 27)"!][!VAR "cINMUX27"="255"!][!ELSE!][!VAR "cINMUX27"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 28)"!][!VAR "cINMUX28"="255"!][!ELSE!][!VAR "cINMUX28"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 29)"!][!VAR "cINMUX29"="255"!][!ELSE!][!VAR "cINMUX29"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 30)"!][!VAR "cINMUX30"="255"!][!ELSE!][!VAR "cINMUX30"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 31)"!][!VAR "cINMUX31"="255"!][!ELSE!][!VAR "cINMUX31"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 32)"!][!VAR "cINMUX32"="255"!][!ELSE!][!VAR "cINMUX32"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 33)"!][!VAR "cINMUX33"="255"!][!ELSE!][!VAR "cINMUX33"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 34)"!][!VAR "cINMUX34"="255"!][!ELSE!][!VAR "cINMUX34"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 35)"!][!VAR "cINMUX35"="255"!][!ELSE!][!VAR "cINMUX35"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 36)"!][!VAR "cINMUX36"="255"!][!ELSE!][!VAR "cINMUX36"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 37)"!][!VAR "cINMUX37"="255"!][!ELSE!][!VAR "cINMUX37"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 38)"!][!VAR "cINMUX38"="255"!][!ELSE!][!VAR "cINMUX38"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 39)"!][!VAR "cINMUX39"="255"!][!ELSE!][!VAR "cINMUX39"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 40)"!][!VAR "cINMUX40"="255"!][!ELSE!][!VAR "cINMUX40"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 41)"!][!VAR "cINMUX41"="255"!][!ELSE!][!VAR "cINMUX41"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 42)"!][!VAR "cINMUX42"="255"!][!ELSE!][!VAR "cINMUX42"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 43)"!][!VAR "cINMUX43"="255"!][!ELSE!][!VAR "cINMUX43"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 44)"!][!VAR "cINMUX44"="255"!][!ELSE!][!VAR "cINMUX44"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 45)"!][!VAR "cINMUX45"="255"!][!ELSE!][!VAR "cINMUX45"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 46)"!][!VAR "cINMUX46"="255"!][!ELSE!][!VAR "cINMUX46"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 47)"!][!VAR "cINMUX47"="255"!][!ELSE!][!VAR "cINMUX47"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 48)"!][!VAR "cINMUX48"="255"!][!ELSE!][!VAR "cINMUX48"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 49)"!][!VAR "cINMUX49"="255"!][!ELSE!][!VAR "cINMUX49"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 50)"!][!VAR "cINMUX50"="255"!][!ELSE!][!VAR "cINMUX50"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 51)"!][!VAR "cINMUX51"="255"!][!ELSE!][!VAR "cINMUX51"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 52)"!][!VAR "cINMUX52"="255"!][!ELSE!][!VAR "cINMUX52"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 53)"!][!VAR "cINMUX53"="255"!][!ELSE!][!VAR "cINMUX53"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 54)"!][!VAR "cINMUX54"="255"!][!ELSE!][!VAR "cINMUX54"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 55)"!][!VAR "cINMUX55"="255"!][!ELSE!][!VAR "cINMUX55"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 56)"!][!VAR "cINMUX56"="255"!][!ELSE!][!VAR "cINMUX56"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 57)"!][!VAR "cINMUX57"="255"!][!ELSE!][!VAR "cINMUX57"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 58)"!][!VAR "cINMUX58"="255"!][!ELSE!][!VAR "cINMUX58"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 59)"!][!VAR "cINMUX59"="255"!][!ELSE!][!VAR "cINMUX59"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 60)"!][!VAR "cINMUX60"="255"!][!ELSE!][!VAR "cINMUX60"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 61)"!][!VAR "cINMUX61"="255"!][!ELSE!][!VAR "cINMUX61"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 62)"!][!VAR "cINMUX62"="255"!][!ELSE!][!VAR "cINMUX62"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 63)"!][!VAR "cINMUX63"="255"!][!ELSE!][!VAR "cINMUX63"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 64)"!][!VAR "cINMUX64"="255"!][!ELSE!][!VAR "cINMUX64"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 65)"!][!VAR "cINMUX65"="255"!][!ELSE!][!VAR "cINMUX65"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 66)"!][!VAR "cINMUX66"="255"!][!ELSE!][!VAR "cINMUX66"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 67)"!][!VAR "cINMUX67"="255"!][!ELSE!][!VAR "cINMUX67"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 68)"!][!VAR "cINMUX68"="255"!][!ELSE!][!VAR "cINMUX68"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 69)"!][!VAR "cINMUX69"="255"!][!ELSE!][!VAR "cINMUX69"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 70)"!][!VAR "cINMUX70"="255"!][!ELSE!][!VAR "cINMUX70"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 71)"!][!VAR "cINMUX71"="255"!][!ELSE!][!VAR "cINMUX71"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 72)"!][!VAR "cINMUX72"="255"!][!ELSE!][!VAR "cINMUX72"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 73)"!][!VAR "cINMUX73"="255"!][!ELSE!][!VAR "cINMUX73"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 74)"!][!VAR "cINMUX74"="255"!][!ELSE!][!VAR "cINMUX74"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 75)"!][!VAR "cINMUX75"="255"!][!ELSE!][!VAR "cINMUX75"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 76)"!][!VAR "cINMUX76"="255"!][!ELSE!][!VAR "cINMUX76"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 77)"!][!VAR "cINMUX77"="255"!][!ELSE!][!VAR "cINMUX77"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 78)"!][!VAR "cINMUX78"="255"!][!ELSE!][!VAR "cINMUX78"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 79)"!][!VAR "cINMUX79"="255"!][!ELSE!][!VAR "cINMUX79"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 80)"!][!VAR "cINMUX80"="255"!][!ELSE!][!VAR "cINMUX80"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 81)"!][!VAR "cINMUX81"="255"!][!ELSE!][!VAR "cINMUX81"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 82)"!][!VAR "cINMUX82"="255"!][!ELSE!][!VAR "cINMUX82"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_0') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 83)"!][!VAR "cINMUX83"="255"!][!ELSE!][!VAR "cINMUX83"="0"!][!ENDIF!][!//

[!VAR "mode_pin"="0"!][!//
[!LOOP "PortContainer/*"!][!//
[!VAR "UntouchedImcr"="0"!][!//
[!VAR "count" = "0"!][!//
[!LOOP "PortPin/*"!][!//
[!VAR "mode_pin"="concat('MSCR_ON_', ./PortPinSiul2Instance, '_IMCR_ON_', ecu:list('Port.Siul2Instances')[num:i($siul2Instance)], '_PORT',number(./PortPinPcr), '_', ./PortPinMode,';')"!][!//
[!VAR "ModeConfigured"="concat(./PortPinSiul2Instance, '_PORT',number(./PortPinPcr),'_',./PortPinMode,';')"!][!//
[!VAR "IMCRnumber"="substring-after(substring-before(substring-after($PinMap,$ModeConfigured),'^'),'@')"!][!//
[!IF "node:exists(../../../../UntouchedIMCR/*/UntouchedPortPinImcr)"!][!//
    [!IF "node:fallback(../../../../UntouchedIMCR/*/UntouchedPortPinImcr ,65535) != 65535"!][!//
        [!LOOP "../../../../UntouchedIMCR/*"!][!//
            [!VAR "UntouchedImcr"="./UntouchedPortPinImcr"!][!//
            [!/* If the IMCR configured is the same as the IMCR in UntouchedIMCR list*/!][!//
            [!IF "$IMCRnumber = $UntouchedImcr"!][!//
                [!/* Normally, we can print the error right here, but we cannot get the PortPinMode exactly. So we need a count variable */!][!//
                [!VAR "count"= "$count+1"!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
        [!IF "$count = 1"!][!//
            [!ERROR!][!//
                Error: The IMCR [!"$IMCRnumber"!] and mode [!"(./PortPinMode)"!] from MSCR [!"(./PortPinPcr)"!] in [!"(./PortPinSiul2Instance)"!] instance appears in both UntouchedIMCR list and the list of configured pins . Please remove it from one of the 2 lists[!//
            [!ENDERROR!][!//
            [!VAR "count" = "0"!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDIF!][!//

[!/* INMUX 0 */!]
[!IF "contains($INMUX0, $mode_pin)"!][!//
    [!VAR "cINMUX0"="number(substring-before(substring-after($INMUX0,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 1 */!]
[!IF "contains($INMUX1, $mode_pin)"!][!//
    [!VAR "cINMUX1"="number(substring-before(substring-after($INMUX1,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 2 */!]
[!IF "contains($INMUX2, $mode_pin)"!][!//
    [!VAR "cINMUX2"="number(substring-before(substring-after($INMUX2,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 3 */!]
[!IF "contains($INMUX3, $mode_pin)"!][!//
    [!VAR "cINMUX3"="number(substring-before(substring-after($INMUX3,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 4 */!]
[!IF "contains($INMUX4, $mode_pin)"!][!//
    [!VAR "cINMUX4"="number(substring-before(substring-after($INMUX4,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 5 */!]
[!IF "contains($INMUX5, $mode_pin)"!][!//
    [!VAR "cINMUX5"="number(substring-before(substring-after($INMUX5,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 6 */!]
[!IF "contains($INMUX6, $mode_pin)"!][!//
    [!VAR "cINMUX6"="number(substring-before(substring-after($INMUX6,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 7 */!]
[!IF "contains($INMUX7, $mode_pin)"!][!//
    [!VAR "cINMUX7"="number(substring-before(substring-after($INMUX7,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 8 */!]
[!IF "contains($INMUX8, $mode_pin)"!][!//
    [!VAR "cINMUX8"="number(substring-before(substring-after($INMUX8,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 9 */!]
[!IF "contains($INMUX9, $mode_pin)"!][!//
    [!VAR "cINMUX9"="number(substring-before(substring-after($INMUX9,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 10 */!]
[!IF "contains($INMUX10, $mode_pin)"!][!//
    [!VAR "cINMUX10"="number(substring-before(substring-after($INMUX10,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 11 */!]
[!IF "contains($INMUX11, $mode_pin)"!][!//
    [!VAR "cINMUX11"="number(substring-before(substring-after($INMUX11,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 12 */!]
[!IF "contains($INMUX12, $mode_pin)"!][!//
    [!VAR "cINMUX12"="number(substring-before(substring-after($INMUX12,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 13 */!]
[!IF "contains($INMUX13, $mode_pin)"!][!//
    [!VAR "cINMUX13"="number(substring-before(substring-after($INMUX13,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 14 */!]
[!IF "contains($INMUX14, $mode_pin)"!][!//
    [!VAR "cINMUX14"="number(substring-before(substring-after($INMUX14,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 15 */!]
[!IF "contains($INMUX15, $mode_pin)"!][!//
    [!VAR "cINMUX15"="number(substring-before(substring-after($INMUX15,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 16 */!]
[!IF "contains($INMUX16, $mode_pin)"!][!//
    [!VAR "cINMUX16"="number(substring-before(substring-after($INMUX16,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 17 */!]
[!IF "contains($INMUX17, $mode_pin)"!][!//
    [!VAR "cINMUX17"="number(substring-before(substring-after($INMUX17,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 18 */!]
[!IF "contains($INMUX18, $mode_pin)"!][!//
    [!VAR "cINMUX18"="number(substring-before(substring-after($INMUX18,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 19 */!]
[!IF "contains($INMUX19, $mode_pin)"!][!//
    [!VAR "cINMUX19"="number(substring-before(substring-after($INMUX19,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 20 */!]
[!IF "contains($INMUX20, $mode_pin)"!][!//
    [!VAR "cINMUX20"="number(substring-before(substring-after($INMUX20,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 21 */!]
[!IF "contains($INMUX21, $mode_pin)"!][!//
    [!VAR "cINMUX21"="number(substring-before(substring-after($INMUX21,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 22 */!]
[!IF "contains($INMUX22, $mode_pin)"!][!//
    [!VAR "cINMUX22"="number(substring-before(substring-after($INMUX22,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 23 */!]
[!IF "contains($INMUX23, $mode_pin)"!][!//
    [!VAR "cINMUX23"="number(substring-before(substring-after($INMUX23,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 24 */!]
[!IF "contains($INMUX24, $mode_pin)"!][!//
    [!VAR "cINMUX24"="number(substring-before(substring-after($INMUX24,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 25 */!]
[!IF "contains($INMUX25, $mode_pin)"!][!//
    [!VAR "cINMUX25"="number(substring-before(substring-after($INMUX25,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 26 */!]
[!IF "contains($INMUX26, $mode_pin)"!][!//
    [!VAR "cINMUX26"="number(substring-before(substring-after($INMUX26,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 27 */!]
[!IF "contains($INMUX27, $mode_pin)"!][!//
    [!VAR "cINMUX27"="number(substring-before(substring-after($INMUX27,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 28 */!]
[!IF "contains($INMUX28, $mode_pin)"!][!//
    [!VAR "cINMUX28"="number(substring-before(substring-after($INMUX28,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 29 */!]
[!IF "contains($INMUX29, $mode_pin)"!][!//
    [!VAR "cINMUX29"="number(substring-before(substring-after($INMUX29,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 30 */!]
[!IF "contains($INMUX30, $mode_pin)"!][!//
    [!VAR "cINMUX30"="number(substring-before(substring-after($INMUX30,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 31 */!]
[!IF "contains($INMUX31, $mode_pin)"!][!//
    [!VAR "cINMUX31"="number(substring-before(substring-after($INMUX31,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 32 */!]
[!IF "contains($INMUX32, $mode_pin)"!][!//
    [!VAR "cINMUX32"="number(substring-before(substring-after($INMUX32,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 33 */!]
[!IF "contains($INMUX33, $mode_pin)"!][!//
    [!VAR "cINMUX33"="number(substring-before(substring-after($INMUX33,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 34 */!]
[!IF "contains($INMUX34, $mode_pin)"!][!//
    [!VAR "cINMUX34"="number(substring-before(substring-after($INMUX34,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 35 */!]
[!IF "contains($INMUX35, $mode_pin)"!][!//
    [!VAR "cINMUX35"="number(substring-before(substring-after($INMUX35,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 36 */!]
[!IF "contains($INMUX36, $mode_pin)"!][!//
    [!VAR "cINMUX36"="number(substring-before(substring-after($INMUX36,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 37 */!]
[!IF "contains($INMUX37, $mode_pin)"!][!//
    [!VAR "cINMUX37"="number(substring-before(substring-after($INMUX37,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 38 */!]
[!IF "contains($INMUX38, $mode_pin)"!][!//
    [!VAR "cINMUX38"="number(substring-before(substring-after($INMUX38,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 39 */!]
[!IF "contains($INMUX39, $mode_pin)"!][!//
    [!VAR "cINMUX39"="number(substring-before(substring-after($INMUX39,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 40 */!]
[!IF "contains($INMUX40, $mode_pin)"!][!//
    [!VAR "cINMUX40"="number(substring-before(substring-after($INMUX40,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 41 */!]
[!IF "contains($INMUX41, $mode_pin)"!][!//
    [!VAR "cINMUX41"="number(substring-before(substring-after($INMUX41,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 42 */!]
[!IF "contains($INMUX42, $mode_pin)"!][!//
    [!VAR "cINMUX42"="number(substring-before(substring-after($INMUX42,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 43 */!]
[!IF "contains($INMUX43, $mode_pin)"!][!//
    [!VAR "cINMUX43"="number(substring-before(substring-after($INMUX43,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 44 */!]
[!IF "contains($INMUX44, $mode_pin)"!][!//
    [!VAR "cINMUX44"="number(substring-before(substring-after($INMUX44,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 45 */!]
[!IF "contains($INMUX45, $mode_pin)"!][!//
    [!VAR "cINMUX45"="number(substring-before(substring-after($INMUX45,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 46 */!]
[!IF "contains($INMUX46, $mode_pin)"!][!//
    [!VAR "cINMUX46"="number(substring-before(substring-after($INMUX46,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 47 */!]
[!IF "contains($INMUX47, $mode_pin)"!][!//
    [!VAR "cINMUX47"="number(substring-before(substring-after($INMUX47,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 48 */!]
[!IF "contains($INMUX48, $mode_pin)"!][!//
    [!VAR "cINMUX48"="number(substring-before(substring-after($INMUX48,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 49 */!]
[!IF "contains($INMUX49, $mode_pin)"!][!//
    [!VAR "cINMUX49"="number(substring-before(substring-after($INMUX49,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 50 */!]
[!IF "contains($INMUX50, $mode_pin)"!][!//
    [!VAR "cINMUX50"="number(substring-before(substring-after($INMUX50,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 51 */!]
[!IF "contains($INMUX51, $mode_pin)"!][!//
    [!VAR "cINMUX51"="number(substring-before(substring-after($INMUX51,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 52 */!]
[!IF "contains($INMUX52, $mode_pin)"!][!//
    [!VAR "cINMUX52"="number(substring-before(substring-after($INMUX52,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 53 */!]
[!IF "contains($INMUX53, $mode_pin)"!][!//
    [!VAR "cINMUX53"="number(substring-before(substring-after($INMUX53,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 54 */!]
[!IF "contains($INMUX54, $mode_pin)"!][!//
    [!VAR "cINMUX54"="number(substring-before(substring-after($INMUX54,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 55 */!]
[!IF "contains($INMUX55, $mode_pin)"!][!//
    [!VAR "cINMUX55"="number(substring-before(substring-after($INMUX55,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 56 */!]
[!IF "contains($INMUX56, $mode_pin)"!][!//
    [!VAR "cINMUX56"="number(substring-before(substring-after($INMUX56,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 57 */!]
[!IF "contains($INMUX57, $mode_pin)"!][!//
    [!VAR "cINMUX57"="number(substring-before(substring-after($INMUX57,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 58 */!]
[!IF "contains($INMUX58, $mode_pin)"!][!//
    [!VAR "cINMUX58"="number(substring-before(substring-after($INMUX58,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 59 */!]
[!IF "contains($INMUX59, $mode_pin)"!][!//
    [!VAR "cINMUX59"="number(substring-before(substring-after($INMUX59,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 60 */!]
[!IF "contains($INMUX60, $mode_pin)"!][!//
    [!VAR "cINMUX60"="number(substring-before(substring-after($INMUX60,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 61 */!]
[!IF "contains($INMUX61, $mode_pin)"!][!//
    [!VAR "cINMUX61"="number(substring-before(substring-after($INMUX61,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 62 */!]
[!IF "contains($INMUX62, $mode_pin)"!][!//
    [!VAR "cINMUX62"="number(substring-before(substring-after($INMUX62,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 63 */!]
[!IF "contains($INMUX63, $mode_pin)"!][!//
    [!VAR "cINMUX63"="number(substring-before(substring-after($INMUX63,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 64 */!]
[!IF "contains($INMUX64, $mode_pin)"!][!//
    [!VAR "cINMUX64"="number(substring-before(substring-after($INMUX64,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 65 */!]
[!IF "contains($INMUX65, $mode_pin)"!][!//
    [!VAR "cINMUX65"="number(substring-before(substring-after($INMUX65,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 66 */!]
[!IF "contains($INMUX66, $mode_pin)"!][!//
    [!VAR "cINMUX66"="number(substring-before(substring-after($INMUX66,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 67 */!]
[!IF "contains($INMUX67, $mode_pin)"!][!//
    [!VAR "cINMUX67"="number(substring-before(substring-after($INMUX67,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 68 */!]
[!IF "contains($INMUX68, $mode_pin)"!][!//
    [!VAR "cINMUX68"="number(substring-before(substring-after($INMUX68,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 69 */!]
[!IF "contains($INMUX69, $mode_pin)"!][!//
    [!VAR "cINMUX69"="number(substring-before(substring-after($INMUX69,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 70 */!]
[!IF "contains($INMUX70, $mode_pin)"!][!//
    [!VAR "cINMUX70"="number(substring-before(substring-after($INMUX70,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 71 */!]
[!IF "contains($INMUX71, $mode_pin)"!][!//
    [!VAR "cINMUX71"="number(substring-before(substring-after($INMUX71,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 72 */!]
[!IF "contains($INMUX72, $mode_pin)"!][!//
    [!VAR "cINMUX72"="number(substring-before(substring-after($INMUX72,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 73 */!]
[!IF "contains($INMUX73, $mode_pin)"!][!//
    [!VAR "cINMUX73"="number(substring-before(substring-after($INMUX73,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 74 */!]
[!IF "contains($INMUX74, $mode_pin)"!][!//
    [!VAR "cINMUX74"="number(substring-before(substring-after($INMUX74,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 75 */!]
[!IF "contains($INMUX75, $mode_pin)"!][!//
    [!VAR "cINMUX75"="number(substring-before(substring-after($INMUX75,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 76 */!]
[!IF "contains($INMUX76, $mode_pin)"!][!//
    [!VAR "cINMUX76"="number(substring-before(substring-after($INMUX76,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 77 */!]
[!IF "contains($INMUX77, $mode_pin)"!][!//
    [!VAR "cINMUX77"="number(substring-before(substring-after($INMUX77,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 78 */!]
[!IF "contains($INMUX78, $mode_pin)"!][!//
    [!VAR "cINMUX78"="number(substring-before(substring-after($INMUX78,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 79 */!]
[!IF "contains($INMUX79, $mode_pin)"!][!//
    [!VAR "cINMUX79"="number(substring-before(substring-after($INMUX79,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 80 */!]
[!IF "contains($INMUX80, $mode_pin)"!][!//
    [!VAR "cINMUX80"="number(substring-before(substring-after($INMUX80,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 81 */!]
[!IF "contains($INMUX81, $mode_pin)"!][!//
    [!VAR "cINMUX81"="number(substring-before(substring-after($INMUX81,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 82 */!]
[!IF "contains($INMUX82, $mode_pin)"!][!//
    [!VAR "cINMUX82"="number(substring-before(substring-after($INMUX82,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!/* INMUX 83 */!]
[!IF "contains($INMUX83, $mode_pin)"!][!//
    [!VAR "cINMUX83"="number(substring-before(substring-after($INMUX83,$mode_pin),':'))"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
    (uint8)[!"num:inttohex($cINMUX0, 2)"!],
    (uint8)[!"num:inttohex($cINMUX1, 2)"!],
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX3, 2)"!],
    (uint8)[!"num:inttohex($cINMUX4, 2)"!],
    (uint8)[!"num:inttohex($cINMUX5, 2)"!],
    (uint8)[!"num:inttohex($cINMUX6, 2)"!],
    (uint8)[!"num:inttohex($cINMUX7, 2)"!],
    (uint8)[!"num:inttohex($cINMUX8, 2)"!],
    (uint8)[!"num:inttohex($cINMUX9, 2)"!],
    (uint8)[!"num:inttohex($cINMUX10, 2)"!],
    (uint8)[!"num:inttohex($cINMUX11, 2)"!],
    (uint8)[!"num:inttohex($cINMUX12, 2)"!],
    (uint8)[!"num:inttohex($cINMUX13, 2)"!],
    (uint8)[!"num:inttohex($cINMUX14, 2)"!],
    (uint8)[!"num:inttohex($cINMUX15, 2)"!],
    (uint8)[!"num:inttohex($cINMUX16, 2)"!],
    (uint8)[!"num:inttohex($cINMUX17, 2)"!],
    (uint8)[!"num:inttohex($cINMUX18, 2)"!],
    (uint8)[!"num:inttohex($cINMUX19, 2)"!],
    (uint8)[!"num:inttohex($cINMUX20, 2)"!],
    (uint8)[!"num:inttohex($cINMUX21, 2)"!],
    (uint8)[!"num:inttohex($cINMUX22, 2)"!],
    (uint8)[!"num:inttohex($cINMUX23, 2)"!],
    (uint8)[!"num:inttohex($cINMUX24, 2)"!],
    (uint8)[!"num:inttohex($cINMUX25, 2)"!],
    (uint8)[!"num:inttohex($cINMUX26, 2)"!],
    (uint8)[!"num:inttohex($cINMUX27, 2)"!],
    (uint8)[!"num:inttohex($cINMUX28, 2)"!],
    (uint8)[!"num:inttohex($cINMUX29, 2)"!],
    (uint8)[!"num:inttohex($cINMUX30, 2)"!],
    (uint8)[!"num:inttohex($cINMUX31, 2)"!],
    (uint8)[!"num:inttohex($cINMUX32, 2)"!],
    (uint8)[!"num:inttohex($cINMUX33, 2)"!],
    (uint8)[!"num:inttohex($cINMUX34, 2)"!],
    (uint8)[!"num:inttohex($cINMUX35, 2)"!],
    (uint8)[!"num:inttohex($cINMUX36, 2)"!],
    (uint8)[!"num:inttohex($cINMUX37, 2)"!],
    (uint8)[!"num:inttohex($cINMUX38, 2)"!],
    (uint8)[!"num:inttohex($cINMUX39, 2)"!],
    (uint8)[!"num:inttohex($cINMUX40, 2)"!],
    (uint8)[!"num:inttohex($cINMUX41, 2)"!],
    (uint8)[!"num:inttohex($cINMUX42, 2)"!],
    (uint8)[!"num:inttohex($cINMUX43, 2)"!],
    (uint8)[!"num:inttohex($cINMUX44, 2)"!],
    (uint8)[!"num:inttohex($cINMUX45, 2)"!],
    (uint8)[!"num:inttohex($cINMUX46, 2)"!],
    (uint8)[!"num:inttohex($cINMUX47, 2)"!],
    (uint8)[!"num:inttohex($cINMUX48, 2)"!],
    (uint8)[!"num:inttohex($cINMUX49, 2)"!],
    (uint8)[!"num:inttohex($cINMUX50, 2)"!],
    (uint8)[!"num:inttohex($cINMUX51, 2)"!],
    (uint8)[!"num:inttohex($cINMUX52, 2)"!],
    (uint8)[!"num:inttohex($cINMUX53, 2)"!],
    (uint8)[!"num:inttohex($cINMUX54, 2)"!],
    (uint8)[!"num:inttohex($cINMUX55, 2)"!],
    (uint8)[!"num:inttohex($cINMUX56, 2)"!],
    (uint8)[!"num:inttohex($cINMUX57, 2)"!],
    (uint8)[!"num:inttohex($cINMUX58, 2)"!],
    (uint8)[!"num:inttohex($cINMUX59, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX68, 2)"!],
    (uint8)[!"num:inttohex($cINMUX69, 2)"!],
    (uint8)[!"num:inttohex($cINMUX70, 2)"!],
    (uint8)[!"num:inttohex($cINMUX71, 2)"!],
    (uint8)[!"num:inttohex($cINMUX72, 2)"!],
    (uint8)[!"num:inttohex($cINMUX73, 2)"!],
    (uint8)[!"num:inttohex($cINMUX74, 2)"!],
    (uint8)[!"num:inttohex($cINMUX75, 2)"!],
    (uint8)[!"num:inttohex($cINMUX76, 2)"!],
    (uint8)[!"num:inttohex($cINMUX77, 2)"!],
    (uint8)[!"num:inttohex($cINMUX78, 2)"!],
    (uint8)[!"num:inttohex($cINMUX79, 2)"!],
    (uint8)[!"num:inttohex($cINMUX80, 2)"!],
    (uint8)[!"num:inttohex($cINMUX81, 2)"!],
    (uint8)[!"num:inttohex($cINMUX82, 2)"!],
    (uint8)[!"num:inttohex($cINMUX83, 2)"!]
};
[!ENDIF!][!//

[!IF "num:i(count(ecu:list('Port.Siul2Instances'))) > 1"!][!//
/* SIUL2_1 */
[!VAR "siul2Instance"="2"!][!//
/**
* @brief IMCR configuration set by Port_Init() for SIUL2 instance: [!"ecu:list('Port.Siul2Instances')[num:i($siul2Instance)]"!]
*/
static const Port_Siul2_ImcrConfigType Port_a[!"ecu:list('Port.Siul2Instances')[num:i($siul2Instance)]"!]_ImcrInitConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PORT_[!"ecu:list('Port.Siul2Instances')[num:i($siul2Instance)]"!]_NUM_IMCRS_U16]=
{
[!NOCODE!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 0)"!][!VAR "cINMUX0"="255"!][!ELSE!][!VAR "cINMUX0"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 1)"!][!VAR "cINMUX1"="255"!][!ELSE!][!VAR "cINMUX1"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 2)"!][!VAR "cINMUX2"="255"!][!ELSE!][!VAR "cINMUX2"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 3)"!][!VAR "cINMUX3"="255"!][!ELSE!][!VAR "cINMUX3"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 4)"!][!VAR "cINMUX4"="255"!][!ELSE!][!VAR "cINMUX4"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 5)"!][!VAR "cINMUX5"="255"!][!ELSE!][!VAR "cINMUX5"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 6)"!][!VAR "cINMUX6"="255"!][!ELSE!][!VAR "cINMUX6"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 7)"!][!VAR "cINMUX7"="255"!][!ELSE!][!VAR "cINMUX7"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 8)"!][!VAR "cINMUX8"="255"!][!ELSE!][!VAR "cINMUX8"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 9)"!][!VAR "cINMUX9"="255"!][!ELSE!][!VAR "cINMUX9"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 10)"!][!VAR "cINMUX10"="255"!][!ELSE!][!VAR "cINMUX10"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 11)"!][!VAR "cINMUX11"="255"!][!ELSE!][!VAR "cINMUX11"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 12)"!][!VAR "cINMUX12"="255"!][!ELSE!][!VAR "cINMUX12"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 13)"!][!VAR "cINMUX13"="255"!][!ELSE!][!VAR "cINMUX13"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 14)"!][!VAR "cINMUX14"="255"!][!ELSE!][!VAR "cINMUX14"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 15)"!][!VAR "cINMUX15"="255"!][!ELSE!][!VAR "cINMUX15"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 16)"!][!VAR "cINMUX16"="255"!][!ELSE!][!VAR "cINMUX16"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 17)"!][!VAR "cINMUX17"="255"!][!ELSE!][!VAR "cINMUX17"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 18)"!][!VAR "cINMUX18"="255"!][!ELSE!][!VAR "cINMUX18"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 19)"!][!VAR "cINMUX19"="255"!][!ELSE!][!VAR "cINMUX19"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 20)"!][!VAR "cINMUX20"="255"!][!ELSE!][!VAR "cINMUX20"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 21)"!][!VAR "cINMUX21"="255"!][!ELSE!][!VAR "cINMUX21"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 22)"!][!VAR "cINMUX22"="255"!][!ELSE!][!VAR "cINMUX22"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 23)"!][!VAR "cINMUX23"="255"!][!ELSE!][!VAR "cINMUX23"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 24)"!][!VAR "cINMUX24"="255"!][!ELSE!][!VAR "cINMUX24"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 25)"!][!VAR "cINMUX25"="255"!][!ELSE!][!VAR "cINMUX25"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 26)"!][!VAR "cINMUX26"="255"!][!ELSE!][!VAR "cINMUX26"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 27)"!][!VAR "cINMUX27"="255"!][!ELSE!][!VAR "cINMUX27"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 28)"!][!VAR "cINMUX28"="255"!][!ELSE!][!VAR "cINMUX28"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 29)"!][!VAR "cINMUX29"="255"!][!ELSE!][!VAR "cINMUX29"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 30)"!][!VAR "cINMUX30"="255"!][!ELSE!][!VAR "cINMUX30"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 31)"!][!VAR "cINMUX31"="255"!][!ELSE!][!VAR "cINMUX31"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 32)"!][!VAR "cINMUX32"="255"!][!ELSE!][!VAR "cINMUX32"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 33)"!][!VAR "cINMUX33"="255"!][!ELSE!][!VAR "cINMUX33"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 34)"!][!VAR "cINMUX34"="255"!][!ELSE!][!VAR "cINMUX34"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 35)"!][!VAR "cINMUX35"="255"!][!ELSE!][!VAR "cINMUX35"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 36)"!][!VAR "cINMUX36"="255"!][!ELSE!][!VAR "cINMUX36"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 37)"!][!VAR "cINMUX37"="255"!][!ELSE!][!VAR "cINMUX37"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 38)"!][!VAR "cINMUX38"="255"!][!ELSE!][!VAR "cINMUX38"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 39)"!][!VAR "cINMUX39"="255"!][!ELSE!][!VAR "cINMUX39"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 40)"!][!VAR "cINMUX40"="255"!][!ELSE!][!VAR "cINMUX40"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 41)"!][!VAR "cINMUX41"="255"!][!ELSE!][!VAR "cINMUX41"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 42)"!][!VAR "cINMUX42"="255"!][!ELSE!][!VAR "cINMUX42"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 43)"!][!VAR "cINMUX43"="255"!][!ELSE!][!VAR "cINMUX43"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 44)"!][!VAR "cINMUX44"="255"!][!ELSE!][!VAR "cINMUX44"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 45)"!][!VAR "cINMUX45"="255"!][!ELSE!][!VAR "cINMUX45"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 46)"!][!VAR "cINMUX46"="255"!][!ELSE!][!VAR "cINMUX46"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 47)"!][!VAR "cINMUX47"="255"!][!ELSE!][!VAR "cINMUX47"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 48)"!][!VAR "cINMUX48"="255"!][!ELSE!][!VAR "cINMUX48"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 49)"!][!VAR "cINMUX49"="255"!][!ELSE!][!VAR "cINMUX49"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 50)"!][!VAR "cINMUX50"="255"!][!ELSE!][!VAR "cINMUX50"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 51)"!][!VAR "cINMUX51"="255"!][!ELSE!][!VAR "cINMUX51"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 52)"!][!VAR "cINMUX52"="255"!][!ELSE!][!VAR "cINMUX52"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 53)"!][!VAR "cINMUX53"="255"!][!ELSE!][!VAR "cINMUX53"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 54)"!][!VAR "cINMUX54"="255"!][!ELSE!][!VAR "cINMUX54"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 55)"!][!VAR "cINMUX55"="255"!][!ELSE!][!VAR "cINMUX55"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 56)"!][!VAR "cINMUX56"="255"!][!ELSE!][!VAR "cINMUX56"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 57)"!][!VAR "cINMUX57"="255"!][!ELSE!][!VAR "cINMUX57"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 58)"!][!VAR "cINMUX58"="255"!][!ELSE!][!VAR "cINMUX58"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 59)"!][!VAR "cINMUX59"="255"!][!ELSE!][!VAR "cINMUX59"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 60)"!][!VAR "cINMUX60"="255"!][!ELSE!][!VAR "cINMUX60"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 61)"!][!VAR "cINMUX61"="255"!][!ELSE!][!VAR "cINMUX61"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 62)"!][!VAR "cINMUX62"="255"!][!ELSE!][!VAR "cINMUX62"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 63)"!][!VAR "cINMUX63"="255"!][!ELSE!][!VAR "cINMUX63"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 64)"!][!VAR "cINMUX64"="255"!][!ELSE!][!VAR "cINMUX64"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 65)"!][!VAR "cINMUX65"="255"!][!ELSE!][!VAR "cINMUX65"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 66)"!][!VAR "cINMUX66"="255"!][!ELSE!][!VAR "cINMUX66"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 67)"!][!VAR "cINMUX67"="255"!][!ELSE!][!VAR "cINMUX67"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 68)"!][!VAR "cINMUX68"="255"!][!ELSE!][!VAR "cINMUX68"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 69)"!][!VAR "cINMUX69"="255"!][!ELSE!][!VAR "cINMUX69"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 70)"!][!VAR "cINMUX70"="255"!][!ELSE!][!VAR "cINMUX70"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 71)"!][!VAR "cINMUX71"="255"!][!ELSE!][!VAR "cINMUX71"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 72)"!][!VAR "cINMUX72"="255"!][!ELSE!][!VAR "cINMUX72"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 73)"!][!VAR "cINMUX73"="255"!][!ELSE!][!VAR "cINMUX73"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 74)"!][!VAR "cINMUX74"="255"!][!ELSE!][!VAR "cINMUX74"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 75)"!][!VAR "cINMUX75"="255"!][!ELSE!][!VAR "cINMUX75"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 76)"!][!VAR "cINMUX76"="255"!][!ELSE!][!VAR "cINMUX76"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 77)"!][!VAR "cINMUX77"="255"!][!ELSE!][!VAR "cINMUX77"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 78)"!][!VAR "cINMUX78"="255"!][!ELSE!][!VAR "cINMUX78"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 79)"!][!VAR "cINMUX79"="255"!][!ELSE!][!VAR "cINMUX79"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 80)"!][!VAR "cINMUX80"="255"!][!ELSE!][!VAR "cINMUX80"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 81)"!][!VAR "cINMUX81"="255"!][!ELSE!][!VAR "cINMUX81"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 82)"!][!VAR "cINMUX82"="255"!][!ELSE!][!VAR "cINMUX82"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 83)"!][!VAR "cINMUX83"="255"!][!ELSE!][!VAR "cINMUX83"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 84)"!][!VAR "cINMUX84"="255"!][!ELSE!][!VAR "cINMUX84"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 85)"!][!VAR "cINMUX85"="255"!][!ELSE!][!VAR "cINMUX85"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 86)"!][!VAR "cINMUX86"="255"!][!ELSE!][!VAR "cINMUX86"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 87)"!][!VAR "cINMUX87"="255"!][!ELSE!][!VAR "cINMUX87"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 88)"!][!VAR "cINMUX88"="255"!][!ELSE!][!VAR "cINMUX88"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 89)"!][!VAR "cINMUX89"="255"!][!ELSE!][!VAR "cINMUX89"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 90)"!][!VAR "cINMUX90"="255"!][!ELSE!][!VAR "cINMUX90"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 91)"!][!VAR "cINMUX91"="255"!][!ELSE!][!VAR "cINMUX91"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 92)"!][!VAR "cINMUX92"="255"!][!ELSE!][!VAR "cINMUX92"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 93)"!][!VAR "cINMUX93"="255"!][!ELSE!][!VAR "cINMUX93"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 94)"!][!VAR "cINMUX94"="255"!][!ELSE!][!VAR "cINMUX94"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 95)"!][!VAR "cINMUX95"="255"!][!ELSE!][!VAR "cINMUX95"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 96)"!][!VAR "cINMUX96"="255"!][!ELSE!][!VAR "cINMUX96"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 97)"!][!VAR "cINMUX97"="255"!][!ELSE!][!VAR "cINMUX97"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 98)"!][!VAR "cINMUX98"="255"!][!ELSE!][!VAR "cINMUX98"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 99)"!][!VAR "cINMUX99"="255"!][!ELSE!][!VAR "cINMUX99"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 100)"!][!VAR "cINMUX100"="255"!][!ELSE!][!VAR "cINMUX100"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 101)"!][!VAR "cINMUX101"="255"!][!ELSE!][!VAR "cINMUX101"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 102)"!][!VAR "cINMUX102"="255"!][!ELSE!][!VAR "cINMUX102"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 103)"!][!VAR "cINMUX103"="255"!][!ELSE!][!VAR "cINMUX103"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 104)"!][!VAR "cINMUX104"="255"!][!ELSE!][!VAR "cINMUX104"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 105)"!][!VAR "cINMUX105"="255"!][!ELSE!][!VAR "cINMUX105"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 106)"!][!VAR "cINMUX106"="255"!][!ELSE!][!VAR "cINMUX106"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 107)"!][!VAR "cINMUX107"="255"!][!ELSE!][!VAR "cINMUX107"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 108)"!][!VAR "cINMUX108"="255"!][!ELSE!][!VAR "cINMUX108"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 109)"!][!VAR "cINMUX109"="255"!][!ELSE!][!VAR "cINMUX109"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 110)"!][!VAR "cINMUX110"="255"!][!ELSE!][!VAR "cINMUX110"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 111)"!][!VAR "cINMUX111"="255"!][!ELSE!][!VAR "cINMUX111"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 112)"!][!VAR "cINMUX112"="255"!][!ELSE!][!VAR "cINMUX112"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 113)"!][!VAR "cINMUX113"="255"!][!ELSE!][!VAR "cINMUX113"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 114)"!][!VAR "cINMUX114"="255"!][!ELSE!][!VAR "cINMUX114"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 115)"!][!VAR "cINMUX115"="255"!][!ELSE!][!VAR "cINMUX115"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 116)"!][!VAR "cINMUX116"="255"!][!ELSE!][!VAR "cINMUX116"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 117)"!][!VAR "cINMUX117"="255"!][!ELSE!][!VAR "cINMUX117"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 118)"!][!VAR "cINMUX118"="255"!][!ELSE!][!VAR "cINMUX118"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 119)"!][!VAR "cINMUX119"="255"!][!ELSE!][!VAR "cINMUX119"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 120)"!][!VAR "cINMUX120"="255"!][!ELSE!][!VAR "cINMUX120"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 121)"!][!VAR "cINMUX121"="255"!][!ELSE!][!VAR "cINMUX121"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 122)"!][!VAR "cINMUX122"="255"!][!ELSE!][!VAR "cINMUX122"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 123)"!][!VAR "cINMUX123"="255"!][!ELSE!][!VAR "cINMUX123"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 124)"!][!VAR "cINMUX124"="255"!][!ELSE!][!VAR "cINMUX124"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 125)"!][!VAR "cINMUX125"="255"!][!ELSE!][!VAR "cINMUX125"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 126)"!][!VAR "cINMUX126"="255"!][!ELSE!][!VAR "cINMUX126"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 127)"!][!VAR "cINMUX127"="255"!][!ELSE!][!VAR "cINMUX127"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 128)"!][!VAR "cINMUX128"="255"!][!ELSE!][!VAR "cINMUX128"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 129)"!][!VAR "cINMUX129"="255"!][!ELSE!][!VAR "cINMUX129"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 130)"!][!VAR "cINMUX130"="255"!][!ELSE!][!VAR "cINMUX130"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 131)"!][!VAR "cINMUX131"="255"!][!ELSE!][!VAR "cINMUX131"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 132)"!][!VAR "cINMUX132"="255"!][!ELSE!][!VAR "cINMUX132"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 133)"!][!VAR "cINMUX133"="255"!][!ELSE!][!VAR "cINMUX133"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 134)"!][!VAR "cINMUX134"="255"!][!ELSE!][!VAR "cINMUX134"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 135)"!][!VAR "cINMUX135"="255"!][!ELSE!][!VAR "cINMUX135"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 136)"!][!VAR "cINMUX136"="255"!][!ELSE!][!VAR "cINMUX136"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 137)"!][!VAR "cINMUX137"="255"!][!ELSE!][!VAR "cINMUX137"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 138)"!][!VAR "cINMUX138"="255"!][!ELSE!][!VAR "cINMUX138"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 139)"!][!VAR "cINMUX139"="255"!][!ELSE!][!VAR "cINMUX139"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 140)"!][!VAR "cINMUX140"="255"!][!ELSE!][!VAR "cINMUX140"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 141)"!][!VAR "cINMUX141"="255"!][!ELSE!][!VAR "cINMUX141"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 142)"!][!VAR "cINMUX142"="255"!][!ELSE!][!VAR "cINMUX142"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 143)"!][!VAR "cINMUX143"="255"!][!ELSE!][!VAR "cINMUX143"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 144)"!][!VAR "cINMUX144"="255"!][!ELSE!][!VAR "cINMUX144"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 145)"!][!VAR "cINMUX145"="255"!][!ELSE!][!VAR "cINMUX145"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 146)"!][!VAR "cINMUX146"="255"!][!ELSE!][!VAR "cINMUX146"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 147)"!][!VAR "cINMUX147"="255"!][!ELSE!][!VAR "cINMUX147"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 148)"!][!VAR "cINMUX148"="255"!][!ELSE!][!VAR "cINMUX148"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 149)"!][!VAR "cINMUX149"="255"!][!ELSE!][!VAR "cINMUX149"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 150)"!][!VAR "cINMUX150"="255"!][!ELSE!][!VAR "cINMUX150"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 151)"!][!VAR "cINMUX151"="255"!][!ELSE!][!VAR "cINMUX151"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 152)"!][!VAR "cINMUX152"="255"!][!ELSE!][!VAR "cINMUX152"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 153)"!][!VAR "cINMUX153"="255"!][!ELSE!][!VAR "cINMUX153"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 154)"!][!VAR "cINMUX154"="255"!][!ELSE!][!VAR "cINMUX154"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 155)"!][!VAR "cINMUX155"="255"!][!ELSE!][!VAR "cINMUX155"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 156)"!][!VAR "cINMUX156"="255"!][!ELSE!][!VAR "cINMUX156"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 157)"!][!VAR "cINMUX157"="255"!][!ELSE!][!VAR "cINMUX157"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 158)"!][!VAR "cINMUX158"="255"!][!ELSE!][!VAR "cINMUX158"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 159)"!][!VAR "cINMUX159"="255"!][!ELSE!][!VAR "cINMUX159"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 160)"!][!VAR "cINMUX160"="255"!][!ELSE!][!VAR "cINMUX160"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 161)"!][!VAR "cINMUX161"="255"!][!ELSE!][!VAR "cINMUX161"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 162)"!][!VAR "cINMUX162"="255"!][!ELSE!][!VAR "cINMUX162"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 163)"!][!VAR "cINMUX163"="255"!][!ELSE!][!VAR "cINMUX163"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 164)"!][!VAR "cINMUX164"="255"!][!ELSE!][!VAR "cINMUX164"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 165)"!][!VAR "cINMUX165"="255"!][!ELSE!][!VAR "cINMUX165"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 166)"!][!VAR "cINMUX166"="255"!][!ELSE!][!VAR "cINMUX166"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 167)"!][!VAR "cINMUX167"="255"!][!ELSE!][!VAR "cINMUX167"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 168)"!][!VAR "cINMUX168"="255"!][!ELSE!][!VAR "cINMUX168"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 169)"!][!VAR "cINMUX169"="255"!][!ELSE!][!VAR "cINMUX169"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 170)"!][!VAR "cINMUX170"="255"!][!ELSE!][!VAR "cINMUX170"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 171)"!][!VAR "cINMUX171"="255"!][!ELSE!][!VAR "cINMUX171"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 172)"!][!VAR "cINMUX172"="255"!][!ELSE!][!VAR "cINMUX172"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 173)"!][!VAR "cINMUX173"="255"!][!ELSE!][!VAR "cINMUX173"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 174)"!][!VAR "cINMUX174"="255"!][!ELSE!][!VAR "cINMUX174"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 175)"!][!VAR "cINMUX175"="255"!][!ELSE!][!VAR "cINMUX175"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 176)"!][!VAR "cINMUX176"="255"!][!ELSE!][!VAR "cINMUX176"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 177)"!][!VAR "cINMUX177"="255"!][!ELSE!][!VAR "cINMUX177"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 178)"!][!VAR "cINMUX178"="255"!][!ELSE!][!VAR "cINMUX178"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 179)"!][!VAR "cINMUX179"="255"!][!ELSE!][!VAR "cINMUX179"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 180)"!][!VAR "cINMUX180"="255"!][!ELSE!][!VAR "cINMUX180"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 181)"!][!VAR "cINMUX181"="255"!][!ELSE!][!VAR "cINMUX181"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 182)"!][!VAR "cINMUX182"="255"!][!ELSE!][!VAR "cINMUX182"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 183)"!][!VAR "cINMUX183"="255"!][!ELSE!][!VAR "cINMUX183"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 184)"!][!VAR "cINMUX184"="255"!][!ELSE!][!VAR "cINMUX184"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 185)"!][!VAR "cINMUX185"="255"!][!ELSE!][!VAR "cINMUX185"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 186)"!][!VAR "cINMUX186"="255"!][!ELSE!][!VAR "cINMUX186"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 187)"!][!VAR "cINMUX187"="255"!][!ELSE!][!VAR "cINMUX187"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 188)"!][!VAR "cINMUX188"="255"!][!ELSE!][!VAR "cINMUX188"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 189)"!][!VAR "cINMUX189"="255"!][!ELSE!][!VAR "cINMUX189"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 190)"!][!VAR "cINMUX190"="255"!][!ELSE!][!VAR "cINMUX190"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 191)"!][!VAR "cINMUX191"="255"!][!ELSE!][!VAR "cINMUX191"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 192)"!][!VAR "cINMUX192"="255"!][!ELSE!][!VAR "cINMUX192"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 193)"!][!VAR "cINMUX193"="255"!][!ELSE!][!VAR "cINMUX193"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 194)"!][!VAR "cINMUX194"="255"!][!ELSE!][!VAR "cINMUX194"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 195)"!][!VAR "cINMUX195"="255"!][!ELSE!][!VAR "cINMUX195"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 196)"!][!VAR "cINMUX196"="255"!][!ELSE!][!VAR "cINMUX196"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 197)"!][!VAR "cINMUX197"="255"!][!ELSE!][!VAR "cINMUX197"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 198)"!][!VAR "cINMUX198"="255"!][!ELSE!][!VAR "cINMUX198"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 199)"!][!VAR "cINMUX199"="255"!][!ELSE!][!VAR "cINMUX199"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 200)"!][!VAR "cINMUX200"="255"!][!ELSE!][!VAR "cINMUX200"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 201)"!][!VAR "cINMUX201"="255"!][!ELSE!][!VAR "cINMUX201"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 202)"!][!VAR "cINMUX202"="255"!][!ELSE!][!VAR "cINMUX202"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 203)"!][!VAR "cINMUX203"="255"!][!ELSE!][!VAR "cINMUX203"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 204)"!][!VAR "cINMUX204"="255"!][!ELSE!][!VAR "cINMUX204"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 205)"!][!VAR "cINMUX205"="255"!][!ELSE!][!VAR "cINMUX205"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 206)"!][!VAR "cINMUX206"="255"!][!ELSE!][!VAR "cINMUX206"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 207)"!][!VAR "cINMUX207"="255"!][!ELSE!][!VAR "cINMUX207"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 208)"!][!VAR "cINMUX208"="255"!][!ELSE!][!VAR "cINMUX208"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 209)"!][!VAR "cINMUX209"="255"!][!ELSE!][!VAR "cINMUX209"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 210)"!][!VAR "cINMUX210"="255"!][!ELSE!][!VAR "cINMUX210"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 211)"!][!VAR "cINMUX211"="255"!][!ELSE!][!VAR "cINMUX211"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 212)"!][!VAR "cINMUX212"="255"!][!ELSE!][!VAR "cINMUX212"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 213)"!][!VAR "cINMUX213"="255"!][!ELSE!][!VAR "cINMUX213"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 214)"!][!VAR "cINMUX214"="255"!][!ELSE!][!VAR "cINMUX214"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 215)"!][!VAR "cINMUX215"="255"!][!ELSE!][!VAR "cINMUX215"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 216)"!][!VAR "cINMUX216"="255"!][!ELSE!][!VAR "cINMUX216"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 217)"!][!VAR "cINMUX217"="255"!][!ELSE!][!VAR "cINMUX217"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 218)"!][!VAR "cINMUX218"="255"!][!ELSE!][!VAR "cINMUX218"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 219)"!][!VAR "cINMUX219"="255"!][!ELSE!][!VAR "cINMUX219"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 220)"!][!VAR "cINMUX220"="255"!][!ELSE!][!VAR "cINMUX220"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 221)"!][!VAR "cINMUX221"="255"!][!ELSE!][!VAR "cINMUX221"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 222)"!][!VAR "cINMUX222"="255"!][!ELSE!][!VAR "cINMUX222"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 223)"!][!VAR "cINMUX223"="255"!][!ELSE!][!VAR "cINMUX223"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 224)"!][!VAR "cINMUX224"="255"!][!ELSE!][!VAR "cINMUX224"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 225)"!][!VAR "cINMUX225"="255"!][!ELSE!][!VAR "cINMUX225"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 226)"!][!VAR "cINMUX226"="255"!][!ELSE!][!VAR "cINMUX226"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 227)"!][!VAR "cINMUX227"="255"!][!ELSE!][!VAR "cINMUX227"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 228)"!][!VAR "cINMUX228"="255"!][!ELSE!][!VAR "cINMUX228"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 229)"!][!VAR "cINMUX229"="255"!][!ELSE!][!VAR "cINMUX229"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 230)"!][!VAR "cINMUX230"="255"!][!ELSE!][!VAR "cINMUX230"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 231)"!][!VAR "cINMUX231"="255"!][!ELSE!][!VAR "cINMUX231"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 232)"!][!VAR "cINMUX232"="255"!][!ELSE!][!VAR "cINMUX232"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 233)"!][!VAR "cINMUX233"="255"!][!ELSE!][!VAR "cINMUX233"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 234)"!][!VAR "cINMUX234"="255"!][!ELSE!][!VAR "cINMUX234"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 235)"!][!VAR "cINMUX235"="255"!][!ELSE!][!VAR "cINMUX235"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 236)"!][!VAR "cINMUX236"="255"!][!ELSE!][!VAR "cINMUX236"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 237)"!][!VAR "cINMUX237"="255"!][!ELSE!][!VAR "cINMUX237"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 238)"!][!VAR "cINMUX238"="255"!][!ELSE!][!VAR "cINMUX238"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 239)"!][!VAR "cINMUX239"="255"!][!ELSE!][!VAR "cINMUX239"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 240)"!][!VAR "cINMUX240"="255"!][!ELSE!][!VAR "cINMUX240"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 241)"!][!VAR "cINMUX241"="255"!][!ELSE!][!VAR "cINMUX241"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 242)"!][!VAR "cINMUX242"="255"!][!ELSE!][!VAR "cINMUX242"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 243)"!][!VAR "cINMUX243"="255"!][!ELSE!][!VAR "cINMUX243"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 244)"!][!VAR "cINMUX244"="255"!][!ELSE!][!VAR "cINMUX244"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 245)"!][!VAR "cINMUX245"="255"!][!ELSE!][!VAR "cINMUX245"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 246)"!][!VAR "cINMUX246"="255"!][!ELSE!][!VAR "cINMUX246"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 247)"!][!VAR "cINMUX247"="255"!][!ELSE!][!VAR "cINMUX247"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 248)"!][!VAR "cINMUX248"="255"!][!ELSE!][!VAR "cINMUX248"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 249)"!][!VAR "cINMUX249"="255"!][!ELSE!][!VAR "cINMUX249"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 250)"!][!VAR "cINMUX250"="255"!][!ELSE!][!VAR "cINMUX250"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 251)"!][!VAR "cINMUX251"="255"!][!ELSE!][!VAR "cINMUX251"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 252)"!][!VAR "cINMUX252"="255"!][!ELSE!][!VAR "cINMUX252"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 253)"!][!VAR "cINMUX253"="255"!][!ELSE!][!VAR "cINMUX253"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 254)"!][!VAR "cINMUX254"="255"!][!ELSE!][!VAR "cINMUX254"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 255)"!][!VAR "cINMUX255"="255"!][!ELSE!][!VAR "cINMUX255"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 256)"!][!VAR "cINMUX256"="255"!][!ELSE!][!VAR "cINMUX256"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 257)"!][!VAR "cINMUX257"="255"!][!ELSE!][!VAR "cINMUX257"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 258)"!][!VAR "cINMUX258"="255"!][!ELSE!][!VAR "cINMUX258"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 259)"!][!VAR "cINMUX259"="255"!][!ELSE!][!VAR "cINMUX259"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 260)"!][!VAR "cINMUX260"="255"!][!ELSE!][!VAR "cINMUX260"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 261)"!][!VAR "cINMUX261"="255"!][!ELSE!][!VAR "cINMUX261"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 262)"!][!VAR "cINMUX262"="255"!][!ELSE!][!VAR "cINMUX262"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 263)"!][!VAR "cINMUX263"="255"!][!ELSE!][!VAR "cINMUX263"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 264)"!][!VAR "cINMUX264"="255"!][!ELSE!][!VAR "cINMUX264"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 265)"!][!VAR "cINMUX265"="255"!][!ELSE!][!VAR "cINMUX265"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 266)"!][!VAR "cINMUX266"="255"!][!ELSE!][!VAR "cINMUX266"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 267)"!][!VAR "cINMUX267"="255"!][!ELSE!][!VAR "cINMUX267"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 268)"!][!VAR "cINMUX268"="255"!][!ELSE!][!VAR "cINMUX268"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 269)"!][!VAR "cINMUX269"="255"!][!ELSE!][!VAR "cINMUX269"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 270)"!][!VAR "cINMUX270"="255"!][!ELSE!][!VAR "cINMUX270"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 271)"!][!VAR "cINMUX271"="255"!][!ELSE!][!VAR "cINMUX271"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 272)"!][!VAR "cINMUX272"="255"!][!ELSE!][!VAR "cINMUX272"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 273)"!][!VAR "cINMUX273"="255"!][!ELSE!][!VAR "cINMUX273"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 274)"!][!VAR "cINMUX274"="255"!][!ELSE!][!VAR "cINMUX274"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 275)"!][!VAR "cINMUX275"="255"!][!ELSE!][!VAR "cINMUX275"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 276)"!][!VAR "cINMUX276"="255"!][!ELSE!][!VAR "cINMUX276"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 277)"!][!VAR "cINMUX277"="255"!][!ELSE!][!VAR "cINMUX277"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 278)"!][!VAR "cINMUX278"="255"!][!ELSE!][!VAR "cINMUX278"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 279)"!][!VAR "cINMUX279"="255"!][!ELSE!][!VAR "cINMUX279"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 280)"!][!VAR "cINMUX280"="255"!][!ELSE!][!VAR "cINMUX280"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 281)"!][!VAR "cINMUX281"="255"!][!ELSE!][!VAR "cINMUX281"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 282)"!][!VAR "cINMUX282"="255"!][!ELSE!][!VAR "cINMUX282"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 283)"!][!VAR "cINMUX283"="255"!][!ELSE!][!VAR "cINMUX283"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 284)"!][!VAR "cINMUX284"="255"!][!ELSE!][!VAR "cINMUX284"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 285)"!][!VAR "cINMUX285"="255"!][!ELSE!][!VAR "cINMUX285"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 286)"!][!VAR "cINMUX286"="255"!][!ELSE!][!VAR "cINMUX286"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 287)"!][!VAR "cINMUX287"="255"!][!ELSE!][!VAR "cINMUX287"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 288)"!][!VAR "cINMUX288"="255"!][!ELSE!][!VAR "cINMUX288"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 289)"!][!VAR "cINMUX289"="255"!][!ELSE!][!VAR "cINMUX289"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 290)"!][!VAR "cINMUX290"="255"!][!ELSE!][!VAR "cINMUX290"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 291)"!][!VAR "cINMUX291"="255"!][!ELSE!][!VAR "cINMUX291"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 292)"!][!VAR "cINMUX292"="255"!][!ELSE!][!VAR "cINMUX292"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 293)"!][!VAR "cINMUX293"="255"!][!ELSE!][!VAR "cINMUX293"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 294)"!][!VAR "cINMUX294"="255"!][!ELSE!][!VAR "cINMUX294"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 295)"!][!VAR "cINMUX295"="255"!][!ELSE!][!VAR "cINMUX295"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 296)"!][!VAR "cINMUX296"="255"!][!ELSE!][!VAR "cINMUX296"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 297)"!][!VAR "cINMUX297"="255"!][!ELSE!][!VAR "cINMUX297"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 298)"!][!VAR "cINMUX298"="255"!][!ELSE!][!VAR "cINMUX298"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 299)"!][!VAR "cINMUX299"="255"!][!ELSE!][!VAR "cINMUX299"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 300)"!][!VAR "cINMUX300"="255"!][!ELSE!][!VAR "cINMUX300"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 301)"!][!VAR "cINMUX301"="255"!][!ELSE!][!VAR "cINMUX301"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 302)"!][!VAR "cINMUX302"="255"!][!ELSE!][!VAR "cINMUX302"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 303)"!][!VAR "cINMUX303"="255"!][!ELSE!][!VAR "cINMUX303"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 304)"!][!VAR "cINMUX304"="255"!][!ELSE!][!VAR "cINMUX304"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 305)"!][!VAR "cINMUX305"="255"!][!ELSE!][!VAR "cINMUX305"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 306)"!][!VAR "cINMUX306"="255"!][!ELSE!][!VAR "cINMUX306"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 307)"!][!VAR "cINMUX307"="255"!][!ELSE!][!VAR "cINMUX307"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 308)"!][!VAR "cINMUX308"="255"!][!ELSE!][!VAR "cINMUX308"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 309)"!][!VAR "cINMUX309"="255"!][!ELSE!][!VAR "cINMUX309"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 310)"!][!VAR "cINMUX310"="255"!][!ELSE!][!VAR "cINMUX310"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 311)"!][!VAR "cINMUX311"="255"!][!ELSE!][!VAR "cINMUX311"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 312)"!][!VAR "cINMUX312"="255"!][!ELSE!][!VAR "cINMUX312"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 313)"!][!VAR "cINMUX313"="255"!][!ELSE!][!VAR "cINMUX313"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 314)"!][!VAR "cINMUX314"="255"!][!ELSE!][!VAR "cINMUX314"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 315)"!][!VAR "cINMUX315"="255"!][!ELSE!][!VAR "cINMUX315"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 316)"!][!VAR "cINMUX316"="255"!][!ELSE!][!VAR "cINMUX316"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 317)"!][!VAR "cINMUX317"="255"!][!ELSE!][!VAR "cINMUX317"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 318)"!][!VAR "cINMUX318"="255"!][!ELSE!][!VAR "cINMUX318"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 319)"!][!VAR "cINMUX319"="255"!][!ELSE!][!VAR "cINMUX319"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 320)"!][!VAR "cINMUX320"="255"!][!ELSE!][!VAR "cINMUX320"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 321)"!][!VAR "cINMUX321"="255"!][!ELSE!][!VAR "cINMUX321"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 322)"!][!VAR "cINMUX322"="255"!][!ELSE!][!VAR "cINMUX322"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 323)"!][!VAR "cINMUX323"="255"!][!ELSE!][!VAR "cINMUX323"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 324)"!][!VAR "cINMUX324"="255"!][!ELSE!][!VAR "cINMUX324"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 325)"!][!VAR "cINMUX325"="255"!][!ELSE!][!VAR "cINMUX325"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 326)"!][!VAR "cINMUX326"="255"!][!ELSE!][!VAR "cINMUX326"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 327)"!][!VAR "cINMUX327"="255"!][!ELSE!][!VAR "cINMUX327"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 328)"!][!VAR "cINMUX328"="255"!][!ELSE!][!VAR "cINMUX328"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 329)"!][!VAR "cINMUX329"="255"!][!ELSE!][!VAR "cINMUX329"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 330)"!][!VAR "cINMUX330"="255"!][!ELSE!][!VAR "cINMUX330"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 331)"!][!VAR "cINMUX331"="255"!][!ELSE!][!VAR "cINMUX331"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 332)"!][!VAR "cINMUX332"="255"!][!ELSE!][!VAR "cINMUX332"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 333)"!][!VAR "cINMUX333"="255"!][!ELSE!][!VAR "cINMUX333"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 334)"!][!VAR "cINMUX334"="255"!][!ELSE!][!VAR "cINMUX334"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 335)"!][!VAR "cINMUX335"="255"!][!ELSE!][!VAR "cINMUX335"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 336)"!][!VAR "cINMUX336"="255"!][!ELSE!][!VAR "cINMUX336"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 337)"!][!VAR "cINMUX337"="255"!][!ELSE!][!VAR "cINMUX337"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 338)"!][!VAR "cINMUX338"="255"!][!ELSE!][!VAR "cINMUX338"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 339)"!][!VAR "cINMUX339"="255"!][!ELSE!][!VAR "cINMUX339"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 340)"!][!VAR "cINMUX340"="255"!][!ELSE!][!VAR "cINMUX340"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 341)"!][!VAR "cINMUX341"="255"!][!ELSE!][!VAR "cINMUX341"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 342)"!][!VAR "cINMUX342"="255"!][!ELSE!][!VAR "cINMUX342"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 343)"!][!VAR "cINMUX343"="255"!][!ELSE!][!VAR "cINMUX343"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 344)"!][!VAR "cINMUX344"="255"!][!ELSE!][!VAR "cINMUX344"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 345)"!][!VAR "cINMUX345"="255"!][!ELSE!][!VAR "cINMUX345"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 346)"!][!VAR "cINMUX346"="255"!][!ELSE!][!VAR "cINMUX346"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 347)"!][!VAR "cINMUX347"="255"!][!ELSE!][!VAR "cINMUX347"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 348)"!][!VAR "cINMUX348"="255"!][!ELSE!][!VAR "cINMUX348"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 349)"!][!VAR "cINMUX349"="255"!][!ELSE!][!VAR "cINMUX349"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 350)"!][!VAR "cINMUX350"="255"!][!ELSE!][!VAR "cINMUX350"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 351)"!][!VAR "cINMUX351"="255"!][!ELSE!][!VAR "cINMUX351"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 352)"!][!VAR "cINMUX352"="255"!][!ELSE!][!VAR "cINMUX352"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 353)"!][!VAR "cINMUX353"="255"!][!ELSE!][!VAR "cINMUX353"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 354)"!][!VAR "cINMUX354"="255"!][!ELSE!][!VAR "cINMUX354"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 355)"!][!VAR "cINMUX355"="255"!][!ELSE!][!VAR "cINMUX355"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 356)"!][!VAR "cINMUX356"="255"!][!ELSE!][!VAR "cINMUX356"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 357)"!][!VAR "cINMUX357"="255"!][!ELSE!][!VAR "cINMUX357"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 358)"!][!VAR "cINMUX358"="255"!][!ELSE!][!VAR "cINMUX358"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 359)"!][!VAR "cINMUX359"="255"!][!ELSE!][!VAR "cINMUX359"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 360)"!][!VAR "cINMUX360"="255"!][!ELSE!][!VAR "cINMUX360"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 361)"!][!VAR "cINMUX361"="255"!][!ELSE!][!VAR "cINMUX361"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 362)"!][!VAR "cINMUX362"="255"!][!ELSE!][!VAR "cINMUX362"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 363)"!][!VAR "cINMUX363"="255"!][!ELSE!][!VAR "cINMUX363"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 364)"!][!VAR "cINMUX364"="255"!][!ELSE!][!VAR "cINMUX364"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 365)"!][!VAR "cINMUX365"="255"!][!ELSE!][!VAR "cINMUX365"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 366)"!][!VAR "cINMUX366"="255"!][!ELSE!][!VAR "cINMUX366"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 367)"!][!VAR "cINMUX367"="255"!][!ELSE!][!VAR "cINMUX367"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 368)"!][!VAR "cINMUX368"="255"!][!ELSE!][!VAR "cINMUX368"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 369)"!][!VAR "cINMUX369"="255"!][!ELSE!][!VAR "cINMUX369"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 370)"!][!VAR "cINMUX370"="255"!][!ELSE!][!VAR "cINMUX370"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 371)"!][!VAR "cINMUX371"="255"!][!ELSE!][!VAR "cINMUX371"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 372)"!][!VAR "cINMUX372"="255"!][!ELSE!][!VAR "cINMUX372"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 373)"!][!VAR "cINMUX373"="255"!][!ELSE!][!VAR "cINMUX373"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 374)"!][!VAR "cINMUX374"="255"!][!ELSE!][!VAR "cINMUX374"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 375)"!][!VAR "cINMUX375"="255"!][!ELSE!][!VAR "cINMUX375"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 376)"!][!VAR "cINMUX376"="255"!][!ELSE!][!VAR "cINMUX376"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 377)"!][!VAR "cINMUX377"="255"!][!ELSE!][!VAR "cINMUX377"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 378)"!][!VAR "cINMUX378"="255"!][!ELSE!][!VAR "cINMUX378"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 379)"!][!VAR "cINMUX379"="255"!][!ELSE!][!VAR "cINMUX379"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 380)"!][!VAR "cINMUX380"="255"!][!ELSE!][!VAR "cINMUX380"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 381)"!][!VAR "cINMUX381"="255"!][!ELSE!][!VAR "cINMUX381"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 382)"!][!VAR "cINMUX382"="255"!][!ELSE!][!VAR "cINMUX382"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 383)"!][!VAR "cINMUX383"="255"!][!ELSE!][!VAR "cINMUX383"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 384)"!][!VAR "cINMUX384"="255"!][!ELSE!][!VAR "cINMUX384"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 385)"!][!VAR "cINMUX385"="255"!][!ELSE!][!VAR "cINMUX385"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 386)"!][!VAR "cINMUX386"="255"!][!ELSE!][!VAR "cINMUX386"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 387)"!][!VAR "cINMUX387"="255"!][!ELSE!][!VAR "cINMUX387"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 388)"!][!VAR "cINMUX388"="255"!][!ELSE!][!VAR "cINMUX388"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 389)"!][!VAR "cINMUX389"="255"!][!ELSE!][!VAR "cINMUX389"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 390)"!][!VAR "cINMUX390"="255"!][!ELSE!][!VAR "cINMUX390"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 391)"!][!VAR "cINMUX391"="255"!][!ELSE!][!VAR "cINMUX391"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 392)"!][!VAR "cINMUX392"="255"!][!ELSE!][!VAR "cINMUX392"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 393)"!][!VAR "cINMUX393"="255"!][!ELSE!][!VAR "cINMUX393"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 394)"!][!VAR "cINMUX394"="255"!][!ELSE!][!VAR "cINMUX394"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 395)"!][!VAR "cINMUX395"="255"!][!ELSE!][!VAR "cINMUX395"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 396)"!][!VAR "cINMUX396"="255"!][!ELSE!][!VAR "cINMUX396"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 397)"!][!VAR "cINMUX397"="255"!][!ELSE!][!VAR "cINMUX397"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 398)"!][!VAR "cINMUX398"="255"!][!ELSE!][!VAR "cINMUX398"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 399)"!][!VAR "cINMUX399"="255"!][!ELSE!][!VAR "cINMUX399"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 400)"!][!VAR "cINMUX400"="255"!][!ELSE!][!VAR "cINMUX400"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 401)"!][!VAR "cINMUX401"="255"!][!ELSE!][!VAR "cINMUX401"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 402)"!][!VAR "cINMUX402"="255"!][!ELSE!][!VAR "cINMUX402"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 403)"!][!VAR "cINMUX403"="255"!][!ELSE!][!VAR "cINMUX403"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 404)"!][!VAR "cINMUX404"="255"!][!ELSE!][!VAR "cINMUX404"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 405)"!][!VAR "cINMUX405"="255"!][!ELSE!][!VAR "cINMUX405"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 406)"!][!VAR "cINMUX406"="255"!][!ELSE!][!VAR "cINMUX406"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 407)"!][!VAR "cINMUX407"="255"!][!ELSE!][!VAR "cINMUX407"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 408)"!][!VAR "cINMUX408"="255"!][!ELSE!][!VAR "cINMUX408"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 409)"!][!VAR "cINMUX409"="255"!][!ELSE!][!VAR "cINMUX409"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 410)"!][!VAR "cINMUX410"="255"!][!ELSE!][!VAR "cINMUX410"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 411)"!][!VAR "cINMUX411"="255"!][!ELSE!][!VAR "cINMUX411"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 412)"!][!VAR "cINMUX412"="255"!][!ELSE!][!VAR "cINMUX412"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 413)"!][!VAR "cINMUX413"="255"!][!ELSE!][!VAR "cINMUX413"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 414)"!][!VAR "cINMUX414"="255"!][!ELSE!][!VAR "cINMUX414"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 415)"!][!VAR "cINMUX415"="255"!][!ELSE!][!VAR "cINMUX415"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 416)"!][!VAR "cINMUX416"="255"!][!ELSE!][!VAR "cINMUX416"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 417)"!][!VAR "cINMUX417"="255"!][!ELSE!][!VAR "cINMUX417"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 418)"!][!VAR "cINMUX418"="255"!][!ELSE!][!VAR "cINMUX418"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 419)"!][!VAR "cINMUX419"="255"!][!ELSE!][!VAR "cINMUX419"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 420)"!][!VAR "cINMUX420"="255"!][!ELSE!][!VAR "cINMUX420"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 421)"!][!VAR "cINMUX421"="255"!][!ELSE!][!VAR "cINMUX421"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 422)"!][!VAR "cINMUX422"="255"!][!ELSE!][!VAR "cINMUX422"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 423)"!][!VAR "cINMUX423"="255"!][!ELSE!][!VAR "cINMUX423"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 424)"!][!VAR "cINMUX424"="255"!][!ELSE!][!VAR "cINMUX424"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 425)"!][!VAR "cINMUX425"="255"!][!ELSE!][!VAR "cINMUX425"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 426)"!][!VAR "cINMUX426"="255"!][!ELSE!][!VAR "cINMUX426"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 427)"!][!VAR "cINMUX427"="255"!][!ELSE!][!VAR "cINMUX427"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 428)"!][!VAR "cINMUX428"="255"!][!ELSE!][!VAR "cINMUX428"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 429)"!][!VAR "cINMUX429"="255"!][!ELSE!][!VAR "cINMUX429"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 430)"!][!VAR "cINMUX430"="255"!][!ELSE!][!VAR "cINMUX430"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 431)"!][!VAR "cINMUX431"="255"!][!ELSE!][!VAR "cINMUX431"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 432)"!][!VAR "cINMUX432"="255"!][!ELSE!][!VAR "cINMUX432"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 433)"!][!VAR "cINMUX433"="255"!][!ELSE!][!VAR "cINMUX433"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 434)"!][!VAR "cINMUX434"="255"!][!ELSE!][!VAR "cINMUX434"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 435)"!][!VAR "cINMUX435"="255"!][!ELSE!][!VAR "cINMUX435"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 436)"!][!VAR "cINMUX436"="255"!][!ELSE!][!VAR "cINMUX436"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 437)"!][!VAR "cINMUX437"="255"!][!ELSE!][!VAR "cINMUX437"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 438)"!][!VAR "cINMUX438"="255"!][!ELSE!][!VAR "cINMUX438"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 439)"!][!VAR "cINMUX439"="255"!][!ELSE!][!VAR "cINMUX439"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 440)"!][!VAR "cINMUX440"="255"!][!ELSE!][!VAR "cINMUX440"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 441)"!][!VAR "cINMUX441"="255"!][!ELSE!][!VAR "cINMUX441"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 442)"!][!VAR "cINMUX442"="255"!][!ELSE!][!VAR "cINMUX442"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 443)"!][!VAR "cINMUX443"="255"!][!ELSE!][!VAR "cINMUX443"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 444)"!][!VAR "cINMUX444"="255"!][!ELSE!][!VAR "cINMUX444"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 445)"!][!VAR "cINMUX445"="255"!][!ELSE!][!VAR "cINMUX445"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 446)"!][!VAR "cINMUX446"="255"!][!ELSE!][!VAR "cINMUX446"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 447)"!][!VAR "cINMUX447"="255"!][!ELSE!][!VAR "cINMUX447"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 448)"!][!VAR "cINMUX448"="255"!][!ELSE!][!VAR "cINMUX448"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 449)"!][!VAR "cINMUX449"="255"!][!ELSE!][!VAR "cINMUX449"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 450)"!][!VAR "cINMUX450"="255"!][!ELSE!][!VAR "cINMUX450"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 451)"!][!VAR "cINMUX451"="255"!][!ELSE!][!VAR "cINMUX451"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 452)"!][!VAR "cINMUX452"="255"!][!ELSE!][!VAR "cINMUX452"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 453)"!][!VAR "cINMUX453"="255"!][!ELSE!][!VAR "cINMUX453"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 454)"!][!VAR "cINMUX454"="255"!][!ELSE!][!VAR "cINMUX454"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 455)"!][!VAR "cINMUX455"="255"!][!ELSE!][!VAR "cINMUX455"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 456)"!][!VAR "cINMUX456"="255"!][!ELSE!][!VAR "cINMUX456"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 457)"!][!VAR "cINMUX457"="255"!][!ELSE!][!VAR "cINMUX457"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 458)"!][!VAR "cINMUX458"="255"!][!ELSE!][!VAR "cINMUX458"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 459)"!][!VAR "cINMUX459"="255"!][!ELSE!][!VAR "cINMUX459"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 460)"!][!VAR "cINMUX460"="255"!][!ELSE!][!VAR "cINMUX460"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 461)"!][!VAR "cINMUX461"="255"!][!ELSE!][!VAR "cINMUX461"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 462)"!][!VAR "cINMUX462"="255"!][!ELSE!][!VAR "cINMUX462"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 463)"!][!VAR "cINMUX463"="255"!][!ELSE!][!VAR "cINMUX463"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 464)"!][!VAR "cINMUX464"="255"!][!ELSE!][!VAR "cINMUX464"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 465)"!][!VAR "cINMUX465"="255"!][!ELSE!][!VAR "cINMUX465"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 466)"!][!VAR "cINMUX466"="255"!][!ELSE!][!VAR "cINMUX466"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 467)"!][!VAR "cINMUX467"="255"!][!ELSE!][!VAR "cINMUX467"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 468)"!][!VAR "cINMUX468"="255"!][!ELSE!][!VAR "cINMUX468"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 469)"!][!VAR "cINMUX469"="255"!][!ELSE!][!VAR "cINMUX469"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 470)"!][!VAR "cINMUX470"="255"!][!ELSE!][!VAR "cINMUX470"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 471)"!][!VAR "cINMUX471"="255"!][!ELSE!][!VAR "cINMUX471"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 472)"!][!VAR "cINMUX472"="255"!][!ELSE!][!VAR "cINMUX472"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 473)"!][!VAR "cINMUX473"="255"!][!ELSE!][!VAR "cINMUX473"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 474)"!][!VAR "cINMUX474"="255"!][!ELSE!][!VAR "cINMUX474"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 475)"!][!VAR "cINMUX475"="255"!][!ELSE!][!VAR "cINMUX475"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 476)"!][!VAR "cINMUX476"="255"!][!ELSE!][!VAR "cINMUX476"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 477)"!][!VAR "cINMUX477"="255"!][!ELSE!][!VAR "cINMUX477"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 478)"!][!VAR "cINMUX478"="255"!][!ELSE!][!VAR "cINMUX478"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 479)"!][!VAR "cINMUX479"="255"!][!ELSE!][!VAR "cINMUX479"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 480)"!][!VAR "cINMUX480"="255"!][!ELSE!][!VAR "cINMUX480"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 481)"!][!VAR "cINMUX481"="255"!][!ELSE!][!VAR "cINMUX481"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 482)"!][!VAR "cINMUX482"="255"!][!ELSE!][!VAR "cINMUX482"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 483)"!][!VAR "cINMUX483"="255"!][!ELSE!][!VAR "cINMUX483"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 484)"!][!VAR "cINMUX484"="255"!][!ELSE!][!VAR "cINMUX484"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 485)"!][!VAR "cINMUX485"="255"!][!ELSE!][!VAR "cINMUX485"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 486)"!][!VAR "cINMUX486"="255"!][!ELSE!][!VAR "cINMUX486"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 487)"!][!VAR "cINMUX487"="255"!][!ELSE!][!VAR "cINMUX487"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 488)"!][!VAR "cINMUX488"="255"!][!ELSE!][!VAR "cINMUX488"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 489)"!][!VAR "cINMUX489"="255"!][!ELSE!][!VAR "cINMUX489"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 490)"!][!VAR "cINMUX490"="255"!][!ELSE!][!VAR "cINMUX490"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 491)"!][!VAR "cINMUX491"="255"!][!ELSE!][!VAR "cINMUX491"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 492)"!][!VAR "cINMUX492"="255"!][!ELSE!][!VAR "cINMUX492"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 493)"!][!VAR "cINMUX493"="255"!][!ELSE!][!VAR "cINMUX493"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 494)"!][!VAR "cINMUX494"="255"!][!ELSE!][!VAR "cINMUX494"="0"!][!ENDIF!][!//
[!IF "((./UntouchedIMCR/*/IMCRSiul2Instance) = 'SIUL2_1') and ((./UntouchedIMCR/*/UntouchedPortPinImcr) = 495)"!][!VAR "cINMUX495"="255"!][!ELSE!][!VAR "cINMUX495"="0"!][!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "contains((ecu:get('Port.Derivative')),'S32G')"!][!//
    [!NOCODE!][!//
    [!LOOP "PortContainer/*"!][!//
    [!LOOP "PortPin/*"!][!//
    [!VAR "mode_pin"="concat('MSCR_ON_', ./PortPinSiul2Instance, '_IMCR_ON_', ecu:list('Port.Siul2Instances')[num:i($siul2Instance)], '_PORT',number(./PortPinPcr), '_', ./PortPinMode,';')"!][!//
    [!/* INMUX 0 */!]
    [!IF "contains($INMUX0, $mode_pin)"!][!//
        [!VAR "cINMUX0"="number(substring-before(substring-after($INMUX0,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 1 */!]
    [!IF "contains($INMUX1, $mode_pin)"!][!//
        [!VAR "cINMUX1"="number(substring-before(substring-after($INMUX1,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 2 */!]
    [!IF "contains($INMUX2, $mode_pin)"!][!//
        [!VAR "cINMUX2"="number(substring-before(substring-after($INMUX2,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 3 */!]
    [!IF "contains($INMUX3, $mode_pin)"!][!//
        [!VAR "cINMUX3"="number(substring-before(substring-after($INMUX3,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 4 */!]
    [!IF "contains($INMUX4, $mode_pin)"!][!//
        [!VAR "cINMUX4"="number(substring-before(substring-after($INMUX4,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 5 */!]
    [!IF "contains($INMUX5, $mode_pin)"!][!//
        [!VAR "cINMUX5"="number(substring-before(substring-after($INMUX5,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 6 */!]
    [!IF "contains($INMUX6, $mode_pin)"!][!//
        [!VAR "cINMUX6"="number(substring-before(substring-after($INMUX6,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 7 */!]
    [!IF "contains($INMUX7, $mode_pin)"!][!//
        [!VAR "cINMUX7"="number(substring-before(substring-after($INMUX7,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 8 */!]
    [!IF "contains($INMUX8, $mode_pin)"!][!//
        [!VAR "cINMUX8"="number(substring-before(substring-after($INMUX8,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 9 */!]
    [!IF "contains($INMUX9, $mode_pin)"!][!//
        [!VAR "cINMUX9"="number(substring-before(substring-after($INMUX9,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 10 */!]
    [!IF "contains($INMUX10, $mode_pin)"!][!//
        [!VAR "cINMUX10"="number(substring-before(substring-after($INMUX10,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 11 */!]
    [!IF "contains($INMUX11, $mode_pin)"!][!//
        [!VAR "cINMUX11"="number(substring-before(substring-after($INMUX11,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 12 */!]
    [!IF "contains($INMUX12, $mode_pin)"!][!//
        [!VAR "cINMUX12"="number(substring-before(substring-after($INMUX12,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 13 */!]
    [!IF "contains($INMUX13, $mode_pin)"!][!//
        [!VAR "cINMUX13"="number(substring-before(substring-after($INMUX13,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 14 */!]
    [!IF "contains($INMUX14, $mode_pin)"!][!//
        [!VAR "cINMUX14"="number(substring-before(substring-after($INMUX14,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 15 */!]
    [!IF "contains($INMUX15, $mode_pin)"!][!//
        [!VAR "cINMUX15"="number(substring-before(substring-after($INMUX15,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 16 */!]
    [!IF "contains($INMUX16, $mode_pin)"!][!//
        [!VAR "cINMUX16"="number(substring-before(substring-after($INMUX16,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 17 */!]
    [!IF "contains($INMUX17, $mode_pin)"!][!//
        [!VAR "cINMUX17"="number(substring-before(substring-after($INMUX17,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 18 */!]
    [!IF "contains($INMUX18, $mode_pin)"!][!//
        [!VAR "cINMUX18"="number(substring-before(substring-after($INMUX18,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 19 */!]
    [!IF "contains($INMUX19, $mode_pin)"!][!//
        [!VAR "cINMUX19"="number(substring-before(substring-after($INMUX19,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 20 */!]
    [!IF "contains($INMUX20, $mode_pin)"!][!//
        [!VAR "cINMUX20"="number(substring-before(substring-after($INMUX20,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 21 */!]
    [!IF "contains($INMUX21, $mode_pin)"!][!//
        [!VAR "cINMUX21"="number(substring-before(substring-after($INMUX21,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 22 */!]
    [!IF "contains($INMUX22, $mode_pin)"!][!//
        [!VAR "cINMUX22"="number(substring-before(substring-after($INMUX22,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 23 */!]
    [!IF "contains($INMUX23, $mode_pin)"!][!//
        [!VAR "cINMUX23"="number(substring-before(substring-after($INMUX23,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 24 */!]
    [!IF "contains($INMUX24, $mode_pin)"!][!//
        [!VAR "cINMUX24"="number(substring-before(substring-after($INMUX24,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 25 */!]
    [!IF "contains($INMUX25, $mode_pin)"!][!//
        [!VAR "cINMUX25"="number(substring-before(substring-after($INMUX25,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 26 */!]
    [!IF "contains($INMUX26, $mode_pin)"!][!//
        [!VAR "cINMUX26"="number(substring-before(substring-after($INMUX26,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 27 */!]
    [!IF "contains($INMUX27, $mode_pin)"!][!//
        [!VAR "cINMUX27"="number(substring-before(substring-after($INMUX27,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 28 */!]
    [!IF "contains($INMUX28, $mode_pin)"!][!//
        [!VAR "cINMUX28"="number(substring-before(substring-after($INMUX28,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 29 */!]
    [!IF "contains($INMUX29, $mode_pin)"!][!//
        [!VAR "cINMUX29"="number(substring-before(substring-after($INMUX29,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 30 */!]
    [!IF "contains($INMUX30, $mode_pin)"!][!//
        [!VAR "cINMUX30"="number(substring-before(substring-after($INMUX30,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 31 */!]
    [!IF "contains($INMUX31, $mode_pin)"!][!//
        [!VAR "cINMUX31"="number(substring-before(substring-after($INMUX31,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 32 */!]
    [!IF "contains($INMUX32, $mode_pin)"!][!//
        [!VAR "cINMUX32"="number(substring-before(substring-after($INMUX32,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 33 */!]
    [!IF "contains($INMUX33, $mode_pin)"!][!//
        [!VAR "cINMUX33"="number(substring-before(substring-after($INMUX33,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 34 */!]
    [!IF "contains($INMUX34, $mode_pin)"!][!//
        [!VAR "cINMUX34"="number(substring-before(substring-after($INMUX34,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 35 */!]
    [!IF "contains($INMUX35, $mode_pin)"!][!//
        [!VAR "cINMUX35"="number(substring-before(substring-after($INMUX35,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 36 */!]
    [!IF "contains($INMUX36, $mode_pin)"!][!//
        [!VAR "cINMUX36"="number(substring-before(substring-after($INMUX36,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 37 */!]
    [!IF "contains($INMUX37, $mode_pin)"!][!//
        [!VAR "cINMUX37"="number(substring-before(substring-after($INMUX37,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 38 */!]
    [!IF "contains($INMUX38, $mode_pin)"!][!//
        [!VAR "cINMUX38"="number(substring-before(substring-after($INMUX38,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 39 */!]
    [!IF "contains($INMUX39, $mode_pin)"!][!//
        [!VAR "cINMUX39"="number(substring-before(substring-after($INMUX39,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 40 */!]
    [!IF "contains($INMUX40, $mode_pin)"!][!//
        [!VAR "cINMUX40"="number(substring-before(substring-after($INMUX40,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 41 */!]
    [!IF "contains($INMUX41, $mode_pin)"!][!//
        [!VAR "cINMUX41"="number(substring-before(substring-after($INMUX41,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 42 */!]
    [!IF "contains($INMUX42, $mode_pin)"!][!//
        [!VAR "cINMUX42"="number(substring-before(substring-after($INMUX42,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 43 */!]
    [!IF "contains($INMUX43, $mode_pin)"!][!//
        [!VAR "cINMUX43"="number(substring-before(substring-after($INMUX43,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 44 */!]
    [!IF "contains($INMUX44, $mode_pin)"!][!//
        [!VAR "cINMUX44"="number(substring-before(substring-after($INMUX44,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 45 */!]
    [!IF "contains($INMUX45, $mode_pin)"!][!//
        [!VAR "cINMUX45"="number(substring-before(substring-after($INMUX45,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 46 */!]
    [!IF "contains($INMUX46, $mode_pin)"!][!//
        [!VAR "cINMUX46"="number(substring-before(substring-after($INMUX46,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 47 */!]
    [!IF "contains($INMUX47, $mode_pin)"!][!//
        [!VAR "cINMUX47"="number(substring-before(substring-after($INMUX47,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 48 */!]
    [!IF "contains($INMUX48, $mode_pin)"!][!//
        [!VAR "cINMUX48"="number(substring-before(substring-after($INMUX48,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 49 */!]
    [!IF "contains($INMUX49, $mode_pin)"!][!//
        [!VAR "cINMUX49"="number(substring-before(substring-after($INMUX49,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 50 */!]
    [!IF "contains($INMUX50, $mode_pin)"!][!//
        [!VAR "cINMUX50"="number(substring-before(substring-after($INMUX50,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 51 */!]
    [!IF "contains($INMUX51, $mode_pin)"!][!//
        [!VAR "cINMUX51"="number(substring-before(substring-after($INMUX51,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 52 */!]
    [!IF "contains($INMUX52, $mode_pin)"!][!//
        [!VAR "cINMUX52"="number(substring-before(substring-after($INMUX52,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 53 */!]
    [!IF "contains($INMUX53, $mode_pin)"!][!//
        [!VAR "cINMUX53"="number(substring-before(substring-after($INMUX53,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 54 */!]
    [!IF "contains($INMUX54, $mode_pin)"!][!//
        [!VAR "cINMUX54"="number(substring-before(substring-after($INMUX54,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 55 */!]
    [!IF "contains($INMUX55, $mode_pin)"!][!//
        [!VAR "cINMUX55"="number(substring-before(substring-after($INMUX55,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 56 */!]
    [!IF "contains($INMUX56, $mode_pin)"!][!//
        [!VAR "cINMUX56"="number(substring-before(substring-after($INMUX56,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 57 */!]
    [!IF "contains($INMUX57, $mode_pin)"!][!//
        [!VAR "cINMUX57"="number(substring-before(substring-after($INMUX57,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 58 */!]
    [!IF "contains($INMUX58, $mode_pin)"!][!//
        [!VAR "cINMUX58"="number(substring-before(substring-after($INMUX58,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 59 */!]
    [!IF "contains($INMUX59, $mode_pin)"!][!//
        [!VAR "cINMUX59"="number(substring-before(substring-after($INMUX59,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 60 */!]
    [!IF "contains($INMUX60, $mode_pin)"!][!//
        [!VAR "cINMUX60"="number(substring-before(substring-after($INMUX60,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 61 */!]
    [!IF "contains($INMUX61, $mode_pin)"!][!//
        [!VAR "cINMUX61"="number(substring-before(substring-after($INMUX61,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 62 */!]
    [!IF "contains($INMUX62, $mode_pin)"!][!//
        [!VAR "cINMUX62"="number(substring-before(substring-after($INMUX62,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 63 */!]
    [!IF "contains($INMUX63, $mode_pin)"!][!//
        [!VAR "cINMUX63"="number(substring-before(substring-after($INMUX63,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 64 */!]
    [!IF "contains($INMUX64, $mode_pin)"!][!//
        [!VAR "cINMUX64"="number(substring-before(substring-after($INMUX64,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 65 */!]
    [!IF "contains($INMUX65, $mode_pin)"!][!//
        [!VAR "cINMUX65"="number(substring-before(substring-after($INMUX65,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 66 */!]
    [!IF "contains($INMUX66, $mode_pin)"!][!//
        [!VAR "cINMUX66"="number(substring-before(substring-after($INMUX66,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 67 */!]
    [!IF "contains($INMUX67, $mode_pin)"!][!//
        [!VAR "cINMUX67"="number(substring-before(substring-after($INMUX67,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 68 */!]
    [!IF "contains($INMUX68, $mode_pin)"!][!//
        [!VAR "cINMUX68"="number(substring-before(substring-after($INMUX68,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 69 */!]
    [!IF "contains($INMUX69, $mode_pin)"!][!//
        [!VAR "cINMUX69"="number(substring-before(substring-after($INMUX69,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 70 */!]
    [!IF "contains($INMUX70, $mode_pin)"!][!//
        [!VAR "cINMUX70"="number(substring-before(substring-after($INMUX70,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 71 */!]
    [!IF "contains($INMUX71, $mode_pin)"!][!//
        [!VAR "cINMUX71"="number(substring-before(substring-after($INMUX71,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 72 */!]
    [!IF "contains($INMUX72, $mode_pin)"!][!//
        [!VAR "cINMUX72"="number(substring-before(substring-after($INMUX72,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 73 */!]
    [!IF "contains($INMUX73, $mode_pin)"!][!//
        [!VAR "cINMUX73"="number(substring-before(substring-after($INMUX73,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 74 */!]
    [!IF "contains($INMUX74, $mode_pin)"!][!//
        [!VAR "cINMUX74"="number(substring-before(substring-after($INMUX74,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 75 */!]
    [!IF "contains($INMUX75, $mode_pin)"!][!//
        [!VAR "cINMUX75"="number(substring-before(substring-after($INMUX75,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 76 */!]
    [!IF "contains($INMUX76, $mode_pin)"!][!//
        [!VAR "cINMUX76"="number(substring-before(substring-after($INMUX76,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 77 */!]
    [!IF "contains($INMUX77, $mode_pin)"!][!//
        [!VAR "cINMUX77"="number(substring-before(substring-after($INMUX77,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 78 */!]
    [!IF "contains($INMUX78, $mode_pin)"!][!//
        [!VAR "cINMUX78"="number(substring-before(substring-after($INMUX78,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 79 */!]
    [!IF "contains($INMUX79, $mode_pin)"!][!//
        [!VAR "cINMUX79"="number(substring-before(substring-after($INMUX79,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 80 */!]
    [!IF "contains($INMUX80, $mode_pin)"!][!//
        [!VAR "cINMUX80"="number(substring-before(substring-after($INMUX80,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 81 */!]
    [!IF "contains($INMUX81, $mode_pin)"!][!//
        [!VAR "cINMUX81"="number(substring-before(substring-after($INMUX81,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 82 */!]
    [!IF "contains($INMUX82, $mode_pin)"!][!//
        [!VAR "cINMUX82"="number(substring-before(substring-after($INMUX82,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 83 */!]
    [!IF "contains($INMUX83, $mode_pin)"!][!//
        [!VAR "cINMUX83"="number(substring-before(substring-after($INMUX83,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 84 */!]
    [!IF "contains($INMUX84, $mode_pin)"!][!//
        [!VAR "cINMUX84"="number(substring-before(substring-after($INMUX84,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 85 */!]
    [!IF "contains($INMUX85, $mode_pin)"!][!//
        [!VAR "cINMUX85"="number(substring-before(substring-after($INMUX85,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 86 */!]
    [!IF "contains($INMUX86, $mode_pin)"!][!//
        [!VAR "cINMUX86"="number(substring-before(substring-after($INMUX86,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 87 */!]
    [!IF "contains($INMUX87, $mode_pin)"!][!//
        [!VAR "cINMUX87"="number(substring-before(substring-after($INMUX87,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 88 */!]
    [!IF "contains($INMUX88, $mode_pin)"!][!//
        [!VAR "cINMUX88"="number(substring-before(substring-after($INMUX88,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 89 */!]
    [!IF "contains($INMUX89, $mode_pin)"!][!//
        [!VAR "cINMUX89"="number(substring-before(substring-after($INMUX89,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 90 */!]
    [!IF "contains($INMUX90, $mode_pin)"!][!//
        [!VAR "cINMUX90"="number(substring-before(substring-after($INMUX90,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 91 */!]
    [!IF "contains($INMUX91, $mode_pin)"!][!//
        [!VAR "cINMUX91"="number(substring-before(substring-after($INMUX91,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 92 */!]
    [!IF "contains($INMUX92, $mode_pin)"!][!//
        [!VAR "cINMUX92"="number(substring-before(substring-after($INMUX92,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 93 */!]
    [!IF "contains($INMUX93, $mode_pin)"!][!//
        [!VAR "cINMUX93"="number(substring-before(substring-after($INMUX93,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 94 */!]
    [!IF "contains($INMUX94, $mode_pin)"!][!//
        [!VAR "cINMUX94"="number(substring-before(substring-after($INMUX94,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 95 */!]
    [!IF "contains($INMUX95, $mode_pin)"!][!//
        [!VAR "cINMUX95"="number(substring-before(substring-after($INMUX95,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 96 */!]
    [!IF "contains($INMUX96, $mode_pin)"!][!//
        [!VAR "cINMUX96"="number(substring-before(substring-after($INMUX96,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 97 */!]
    [!IF "contains($INMUX97, $mode_pin)"!][!//
        [!VAR "cINMUX97"="number(substring-before(substring-after($INMUX97,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 98 */!]
    [!IF "contains($INMUX98, $mode_pin)"!][!//
        [!VAR "cINMUX98"="number(substring-before(substring-after($INMUX98,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 99 */!]
    [!IF "contains($INMUX99, $mode_pin)"!][!//
        [!VAR "cINMUX99"="number(substring-before(substring-after($INMUX99,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 100 */!]
    [!IF "contains($INMUX100, $mode_pin)"!][!//
        [!VAR "cINMUX100"="number(substring-before(substring-after($INMUX100,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 101 */!]
    [!IF "contains($INMUX101, $mode_pin)"!][!//
        [!VAR "cINMUX101"="number(substring-before(substring-after($INMUX101,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 102 */!]
    [!IF "contains($INMUX102, $mode_pin)"!][!//
        [!VAR "cINMUX102"="number(substring-before(substring-after($INMUX102,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 103 */!]
    [!IF "contains($INMUX103, $mode_pin)"!][!//
        [!VAR "cINMUX103"="number(substring-before(substring-after($INMUX103,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 104 */!]
    [!IF "contains($INMUX104, $mode_pin)"!][!//
        [!VAR "cINMUX104"="number(substring-before(substring-after($INMUX104,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 105 */!]
    [!IF "contains($INMUX105, $mode_pin)"!][!//
        [!VAR "cINMUX105"="number(substring-before(substring-after($INMUX105,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 106 */!]
    [!IF "contains($INMUX106, $mode_pin)"!][!//
        [!VAR "cINMUX106"="number(substring-before(substring-after($INMUX106,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 107 */!]
    [!IF "contains($INMUX107, $mode_pin)"!][!//
        [!VAR "cINMUX107"="number(substring-before(substring-after($INMUX107,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 108 */!]
    [!IF "contains($INMUX108, $mode_pin)"!][!//
        [!VAR "cINMUX108"="number(substring-before(substring-after($INMUX108,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 109 */!]
    [!IF "contains($INMUX109, $mode_pin)"!][!//
        [!VAR "cINMUX109"="number(substring-before(substring-after($INMUX109,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 110 */!]
    [!IF "contains($INMUX110, $mode_pin)"!][!//
        [!VAR "cINMUX110"="number(substring-before(substring-after($INMUX110,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 111 */!]
    [!IF "contains($INMUX111, $mode_pin)"!][!//
        [!VAR "cINMUX111"="number(substring-before(substring-after($INMUX111,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 112 */!]
    [!IF "contains($INMUX112, $mode_pin)"!][!//
        [!VAR "cINMUX112"="number(substring-before(substring-after($INMUX112,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 113 */!]
    [!IF "contains($INMUX113, $mode_pin)"!][!//
        [!VAR "cINMUX113"="number(substring-before(substring-after($INMUX113,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 114 */!]
    [!IF "contains($INMUX114, $mode_pin)"!][!//
        [!VAR "cINMUX114"="number(substring-before(substring-after($INMUX114,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 115 */!]
    [!IF "contains($INMUX115, $mode_pin)"!][!//
        [!VAR "cINMUX115"="number(substring-before(substring-after($INMUX115,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 116 */!]
    [!IF "contains($INMUX116, $mode_pin)"!][!//
        [!VAR "cINMUX116"="number(substring-before(substring-after($INMUX116,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 117 */!]
    [!IF "contains($INMUX117, $mode_pin)"!][!//
        [!VAR "cINMUX117"="number(substring-before(substring-after($INMUX117,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 118 */!]
    [!IF "contains($INMUX118, $mode_pin)"!][!//
        [!VAR "cINMUX118"="number(substring-before(substring-after($INMUX118,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 119 */!]
    [!IF "contains($INMUX119, $mode_pin)"!][!//
        [!VAR "cINMUX119"="number(substring-before(substring-after($INMUX119,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 120 */!]
    [!IF "contains($INMUX120, $mode_pin)"!][!//
        [!VAR "cINMUX120"="number(substring-before(substring-after($INMUX120,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 121 */!]
    [!IF "contains($INMUX121, $mode_pin)"!][!//
        [!VAR "cINMUX121"="number(substring-before(substring-after($INMUX121,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 122 */!]
    [!IF "contains($INMUX122, $mode_pin)"!][!//
        [!VAR "cINMUX122"="number(substring-before(substring-after($INMUX122,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 123 */!]
    [!IF "contains($INMUX123, $mode_pin)"!][!//
        [!VAR "cINMUX123"="number(substring-before(substring-after($INMUX123,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 124 */!]
    [!IF "contains($INMUX124, $mode_pin)"!][!//
        [!VAR "cINMUX124"="number(substring-before(substring-after($INMUX124,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 125 */!]
    [!IF "contains($INMUX125, $mode_pin)"!][!//
        [!VAR "cINMUX125"="number(substring-before(substring-after($INMUX125,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 126 */!]
    [!IF "contains($INMUX126, $mode_pin)"!][!//
        [!VAR "cINMUX126"="number(substring-before(substring-after($INMUX126,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 127 */!]
    [!IF "contains($INMUX127, $mode_pin)"!][!//
        [!VAR "cINMUX127"="number(substring-before(substring-after($INMUX127,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 128 */!]
    [!IF "contains($INMUX128, $mode_pin)"!][!//
        [!VAR "cINMUX128"="number(substring-before(substring-after($INMUX128,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 129 */!]
    [!IF "contains($INMUX129, $mode_pin)"!][!//
        [!VAR "cINMUX129"="number(substring-before(substring-after($INMUX129,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 130 */!]
    [!IF "contains($INMUX130, $mode_pin)"!][!//
        [!VAR "cINMUX130"="number(substring-before(substring-after($INMUX130,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 131 */!]
    [!IF "contains($INMUX131, $mode_pin)"!][!//
        [!VAR "cINMUX131"="number(substring-before(substring-after($INMUX131,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 132 */!]
    [!IF "contains($INMUX132, $mode_pin)"!][!//
        [!VAR "cINMUX132"="number(substring-before(substring-after($INMUX132,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 133 */!]
    [!IF "contains($INMUX133, $mode_pin)"!][!//
        [!VAR "cINMUX133"="number(substring-before(substring-after($INMUX133,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 134 */!]
    [!IF "contains($INMUX134, $mode_pin)"!][!//
        [!VAR "cINMUX134"="number(substring-before(substring-after($INMUX134,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 135 */!]
    [!IF "contains($INMUX135, $mode_pin)"!][!//
        [!VAR "cINMUX135"="number(substring-before(substring-after($INMUX135,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 136 */!]
    [!IF "contains($INMUX136, $mode_pin)"!][!//
        [!VAR "cINMUX136"="number(substring-before(substring-after($INMUX136,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 137 */!]
    [!IF "contains($INMUX137, $mode_pin)"!][!//
        [!VAR "cINMUX137"="number(substring-before(substring-after($INMUX137,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 138 */!]
    [!IF "contains($INMUX138, $mode_pin)"!][!//
        [!VAR "cINMUX138"="number(substring-before(substring-after($INMUX138,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 139 */!]
    [!IF "contains($INMUX139, $mode_pin)"!][!//
        [!VAR "cINMUX139"="number(substring-before(substring-after($INMUX139,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 140 */!]
    [!IF "contains($INMUX140, $mode_pin)"!][!//
        [!VAR "cINMUX140"="number(substring-before(substring-after($INMUX140,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 141 */!]
    [!IF "contains($INMUX141, $mode_pin)"!][!//
        [!VAR "cINMUX141"="number(substring-before(substring-after($INMUX141,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 142 */!]
    [!IF "contains($INMUX142, $mode_pin)"!][!//
        [!VAR "cINMUX142"="number(substring-before(substring-after($INMUX142,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 143 */!]
    [!IF "contains($INMUX143, $mode_pin)"!][!//
        [!VAR "cINMUX143"="number(substring-before(substring-after($INMUX143,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 144 */!]
    [!IF "contains($INMUX144, $mode_pin)"!][!//
        [!VAR "cINMUX144"="number(substring-before(substring-after($INMUX144,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 145 */!]
    [!IF "contains($INMUX145, $mode_pin)"!][!//
        [!VAR "cINMUX145"="number(substring-before(substring-after($INMUX145,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 146 */!]
    [!IF "contains($INMUX146, $mode_pin)"!][!//
        [!VAR "cINMUX146"="number(substring-before(substring-after($INMUX146,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 147 */!]
    [!IF "contains($INMUX147, $mode_pin)"!][!//
        [!VAR "cINMUX147"="number(substring-before(substring-after($INMUX147,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 148 */!]
    [!IF "contains($INMUX148, $mode_pin)"!][!//
        [!VAR "cINMUX148"="number(substring-before(substring-after($INMUX148,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 149 */!]
    [!IF "contains($INMUX149, $mode_pin)"!][!//
        [!VAR "cINMUX149"="number(substring-before(substring-after($INMUX149,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 150 */!]
    [!IF "contains($INMUX150, $mode_pin)"!][!//
        [!VAR "cINMUX150"="number(substring-before(substring-after($INMUX150,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 151 */!]
    [!IF "contains($INMUX151, $mode_pin)"!][!//
        [!VAR "cINMUX151"="number(substring-before(substring-after($INMUX151,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 152 */!]
    [!IF "contains($INMUX152, $mode_pin)"!][!//
        [!VAR "cINMUX152"="number(substring-before(substring-after($INMUX152,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 153 */!]
    [!IF "contains($INMUX153, $mode_pin)"!][!//
        [!VAR "cINMUX153"="number(substring-before(substring-after($INMUX153,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 154 */!]
    [!IF "contains($INMUX154, $mode_pin)"!][!//
        [!VAR "cINMUX154"="number(substring-before(substring-after($INMUX154,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 155 */!]
    [!IF "contains($INMUX155, $mode_pin)"!][!//
        [!VAR "cINMUX155"="number(substring-before(substring-after($INMUX155,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 156 */!]
    [!IF "contains($INMUX156, $mode_pin)"!][!//
        [!VAR "cINMUX156"="number(substring-before(substring-after($INMUX156,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 157 */!]
    [!IF "contains($INMUX157, $mode_pin)"!][!//
        [!VAR "cINMUX157"="number(substring-before(substring-after($INMUX157,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 158 */!]
    [!IF "contains($INMUX158, $mode_pin)"!][!//
        [!VAR "cINMUX158"="number(substring-before(substring-after($INMUX158,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 159 */!]
    [!IF "contains($INMUX159, $mode_pin)"!][!//
        [!VAR "cINMUX159"="number(substring-before(substring-after($INMUX159,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 160 */!]
    [!IF "contains($INMUX160, $mode_pin)"!][!//
        [!VAR "cINMUX160"="number(substring-before(substring-after($INMUX160,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 161 */!]
    [!IF "contains($INMUX161, $mode_pin)"!][!//
        [!VAR "cINMUX161"="number(substring-before(substring-after($INMUX161,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 162 */!]
    [!IF "contains($INMUX162, $mode_pin)"!][!//
        [!VAR "cINMUX162"="number(substring-before(substring-after($INMUX162,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 163 */!]
    [!IF "contains($INMUX163, $mode_pin)"!][!//
        [!VAR "cINMUX163"="number(substring-before(substring-after($INMUX163,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 164 */!]
    [!IF "contains($INMUX164, $mode_pin)"!][!//
        [!VAR "cINMUX164"="number(substring-before(substring-after($INMUX164,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 165 */!]
    [!IF "contains($INMUX165, $mode_pin)"!][!//
        [!VAR "cINMUX165"="number(substring-before(substring-after($INMUX165,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 166 */!]
    [!IF "contains($INMUX166, $mode_pin)"!][!//
        [!VAR "cINMUX166"="number(substring-before(substring-after($INMUX166,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 167 */!]
    [!IF "contains($INMUX167, $mode_pin)"!][!//
        [!VAR "cINMUX167"="number(substring-before(substring-after($INMUX167,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 168 */!]
    [!IF "contains($INMUX168, $mode_pin)"!][!//
        [!VAR "cINMUX168"="number(substring-before(substring-after($INMUX168,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 169 */!]
    [!IF "contains($INMUX169, $mode_pin)"!][!//
        [!VAR "cINMUX169"="number(substring-before(substring-after($INMUX169,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 170 */!]
    [!IF "contains($INMUX170, $mode_pin)"!][!//
        [!VAR "cINMUX170"="number(substring-before(substring-after($INMUX170,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 171 */!]
    [!IF "contains($INMUX171, $mode_pin)"!][!//
        [!VAR "cINMUX171"="number(substring-before(substring-after($INMUX171,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 172 */!]
    [!IF "contains($INMUX172, $mode_pin)"!][!//
        [!VAR "cINMUX172"="number(substring-before(substring-after($INMUX172,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 173 */!]
    [!IF "contains($INMUX173, $mode_pin)"!][!//
        [!VAR "cINMUX173"="number(substring-before(substring-after($INMUX173,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 174 */!]
    [!IF "contains($INMUX174, $mode_pin)"!][!//
        [!VAR "cINMUX174"="number(substring-before(substring-after($INMUX174,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 175 */!]
    [!IF "contains($INMUX175, $mode_pin)"!][!//
        [!VAR "cINMUX175"="number(substring-before(substring-after($INMUX175,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 176 */!]
    [!IF "contains($INMUX176, $mode_pin)"!][!//
        [!VAR "cINMUX176"="number(substring-before(substring-after($INMUX176,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 177 */!]
    [!IF "contains($INMUX177, $mode_pin)"!][!//
        [!VAR "cINMUX177"="number(substring-before(substring-after($INMUX177,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 178 */!]
    [!IF "contains($INMUX178, $mode_pin)"!][!//
        [!VAR "cINMUX178"="number(substring-before(substring-after($INMUX178,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 179 */!]
    [!IF "contains($INMUX179, $mode_pin)"!][!//
        [!VAR "cINMUX179"="number(substring-before(substring-after($INMUX179,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 180 */!]
    [!IF "contains($INMUX180, $mode_pin)"!][!//
        [!VAR "cINMUX180"="number(substring-before(substring-after($INMUX180,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 181 */!]
    [!IF "contains($INMUX181, $mode_pin)"!][!//
        [!VAR "cINMUX181"="number(substring-before(substring-after($INMUX181,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 182 */!]
    [!IF "contains($INMUX182, $mode_pin)"!][!//
        [!VAR "cINMUX182"="number(substring-before(substring-after($INMUX182,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 183 */!]
    [!IF "contains($INMUX183, $mode_pin)"!][!//
        [!VAR "cINMUX183"="number(substring-before(substring-after($INMUX183,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 184 */!]
    [!IF "contains($INMUX184, $mode_pin)"!][!//
        [!VAR "cINMUX184"="number(substring-before(substring-after($INMUX184,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 185 */!]
    [!IF "contains($INMUX185, $mode_pin)"!][!//
        [!VAR "cINMUX185"="number(substring-before(substring-after($INMUX185,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 186 */!]
    [!IF "contains($INMUX186, $mode_pin)"!][!//
        [!VAR "cINMUX186"="number(substring-before(substring-after($INMUX186,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 187 */!]
    [!IF "contains($INMUX187, $mode_pin)"!][!//
        [!VAR "cINMUX187"="number(substring-before(substring-after($INMUX187,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 188 */!]
    [!IF "contains($INMUX188, $mode_pin)"!][!//
        [!VAR "cINMUX188"="number(substring-before(substring-after($INMUX188,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 189 */!]
    [!IF "contains($INMUX189, $mode_pin)"!][!//
        [!VAR "cINMUX189"="number(substring-before(substring-after($INMUX189,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 190 */!]
    [!IF "contains($INMUX190, $mode_pin)"!][!//
        [!VAR "cINMUX190"="number(substring-before(substring-after($INMUX190,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 191 */!]
    [!IF "contains($INMUX191, $mode_pin)"!][!//
        [!VAR "cINMUX191"="number(substring-before(substring-after($INMUX191,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 192 */!]
    [!IF "contains($INMUX192, $mode_pin)"!][!//
        [!VAR "cINMUX192"="number(substring-before(substring-after($INMUX192,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 193 */!]
    [!IF "contains($INMUX193, $mode_pin)"!][!//
        [!VAR "cINMUX193"="number(substring-before(substring-after($INMUX193,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 194 */!]
    [!IF "contains($INMUX194, $mode_pin)"!][!//
        [!VAR "cINMUX194"="number(substring-before(substring-after($INMUX194,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 195 */!]
    [!IF "contains($INMUX195, $mode_pin)"!][!//
        [!VAR "cINMUX195"="number(substring-before(substring-after($INMUX195,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 196 */!]
    [!IF "contains($INMUX196, $mode_pin)"!][!//
        [!VAR "cINMUX196"="number(substring-before(substring-after($INMUX196,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 197 */!]
    [!IF "contains($INMUX197, $mode_pin)"!][!//
        [!VAR "cINMUX197"="number(substring-before(substring-after($INMUX197,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 198 */!]
    [!IF "contains($INMUX198, $mode_pin)"!][!//
        [!VAR "cINMUX198"="number(substring-before(substring-after($INMUX198,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 199 */!]
    [!IF "contains($INMUX199, $mode_pin)"!][!//
        [!VAR "cINMUX199"="number(substring-before(substring-after($INMUX199,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 200 */!]
    [!IF "contains($INMUX200, $mode_pin)"!][!//
        [!VAR "cINMUX200"="number(substring-before(substring-after($INMUX200,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 201 */!]
    [!IF "contains($INMUX201, $mode_pin)"!][!//
        [!VAR "cINMUX201"="number(substring-before(substring-after($INMUX201,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 202 */!]
    [!IF "contains($INMUX202, $mode_pin)"!][!//
        [!VAR "cINMUX202"="number(substring-before(substring-after($INMUX202,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 203 */!]
    [!IF "contains($INMUX203, $mode_pin)"!][!//
        [!VAR "cINMUX203"="number(substring-before(substring-after($INMUX203,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 204 */!]
    [!IF "contains($INMUX204, $mode_pin)"!][!//
        [!VAR "cINMUX204"="number(substring-before(substring-after($INMUX204,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 205 */!]
    [!IF "contains($INMUX205, $mode_pin)"!][!//
        [!VAR "cINMUX205"="number(substring-before(substring-after($INMUX205,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 206 */!]
    [!IF "contains($INMUX206, $mode_pin)"!][!//
        [!VAR "cINMUX206"="number(substring-before(substring-after($INMUX206,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 207 */!]
    [!IF "contains($INMUX207, $mode_pin)"!][!//
        [!VAR "cINMUX207"="number(substring-before(substring-after($INMUX207,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 208 */!]
    [!IF "contains($INMUX208, $mode_pin)"!][!//
        [!VAR "cINMUX208"="number(substring-before(substring-after($INMUX208,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 209 */!]
    [!IF "contains($INMUX209, $mode_pin)"!][!//
        [!VAR "cINMUX209"="number(substring-before(substring-after($INMUX209,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 210 */!]
    [!IF "contains($INMUX210, $mode_pin)"!][!//
        [!VAR "cINMUX210"="number(substring-before(substring-after($INMUX210,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 211 */!]
    [!IF "contains($INMUX211, $mode_pin)"!][!//
        [!VAR "cINMUX211"="number(substring-before(substring-after($INMUX211,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 212 */!]
    [!IF "contains($INMUX212, $mode_pin)"!][!//
        [!VAR "cINMUX212"="number(substring-before(substring-after($INMUX212,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 213 */!]
    [!IF "contains($INMUX213, $mode_pin)"!][!//
        [!VAR "cINMUX213"="number(substring-before(substring-after($INMUX213,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 214 */!]
    [!IF "contains($INMUX214, $mode_pin)"!][!//
        [!VAR "cINMUX214"="number(substring-before(substring-after($INMUX214,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 215 */!]
    [!IF "contains($INMUX215, $mode_pin)"!][!//
        [!VAR "cINMUX215"="number(substring-before(substring-after($INMUX215,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 216 */!]
    [!IF "contains($INMUX216, $mode_pin)"!][!//
        [!VAR "cINMUX216"="number(substring-before(substring-after($INMUX216,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 217 */!]
    [!IF "contains($INMUX217, $mode_pin)"!][!//
        [!VAR "cINMUX217"="number(substring-before(substring-after($INMUX217,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 218 */!]
    [!IF "contains($INMUX218, $mode_pin)"!][!//
        [!VAR "cINMUX218"="number(substring-before(substring-after($INMUX218,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 219 */!]
    [!IF "contains($INMUX219, $mode_pin)"!][!//
        [!VAR "cINMUX219"="number(substring-before(substring-after($INMUX219,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 220 */!]
    [!IF "contains($INMUX220, $mode_pin)"!][!//
        [!VAR "cINMUX220"="number(substring-before(substring-after($INMUX220,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 221 */!]
    [!IF "contains($INMUX221, $mode_pin)"!][!//
        [!VAR "cINMUX221"="number(substring-before(substring-after($INMUX221,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 222 */!]
    [!IF "contains($INMUX222, $mode_pin)"!][!//
        [!VAR "cINMUX222"="number(substring-before(substring-after($INMUX222,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 223 */!]
    [!IF "contains($INMUX223, $mode_pin)"!][!//
        [!VAR "cINMUX223"="number(substring-before(substring-after($INMUX223,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 224 */!]
    [!IF "contains($INMUX224, $mode_pin)"!][!//
        [!VAR "cINMUX224"="number(substring-before(substring-after($INMUX224,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 225 */!]
    [!IF "contains($INMUX225, $mode_pin)"!][!//
        [!VAR "cINMUX225"="number(substring-before(substring-after($INMUX225,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 226 */!]
    [!IF "contains($INMUX226, $mode_pin)"!][!//
        [!VAR "cINMUX226"="number(substring-before(substring-after($INMUX226,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 227 */!]
    [!IF "contains($INMUX227, $mode_pin)"!][!//
        [!VAR "cINMUX227"="number(substring-before(substring-after($INMUX227,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 228 */!]
    [!IF "contains($INMUX228, $mode_pin)"!][!//
        [!VAR "cINMUX228"="number(substring-before(substring-after($INMUX228,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 229 */!]
    [!IF "contains($INMUX229, $mode_pin)"!][!//
        [!VAR "cINMUX229"="number(substring-before(substring-after($INMUX229,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 230 */!]
    [!IF "contains($INMUX230, $mode_pin)"!][!//
        [!VAR "cINMUX230"="number(substring-before(substring-after($INMUX230,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 231 */!]
    [!IF "contains($INMUX231, $mode_pin)"!][!//
        [!VAR "cINMUX231"="number(substring-before(substring-after($INMUX231,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 232 */!]
    [!IF "contains($INMUX232, $mode_pin)"!][!//
        [!VAR "cINMUX232"="number(substring-before(substring-after($INMUX232,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 233 */!]
    [!IF "contains($INMUX233, $mode_pin)"!][!//
        [!VAR "cINMUX233"="number(substring-before(substring-after($INMUX233,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 234 */!]
    [!IF "contains($INMUX234, $mode_pin)"!][!//
        [!VAR "cINMUX234"="number(substring-before(substring-after($INMUX234,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 235 */!]
    [!IF "contains($INMUX235, $mode_pin)"!][!//
        [!VAR "cINMUX235"="number(substring-before(substring-after($INMUX235,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 236 */!]
    [!IF "contains($INMUX236, $mode_pin)"!][!//
        [!VAR "cINMUX236"="number(substring-before(substring-after($INMUX236,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 237 */!]
    [!IF "contains($INMUX237, $mode_pin)"!][!//
        [!VAR "cINMUX237"="number(substring-before(substring-after($INMUX237,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 238 */!]
    [!IF "contains($INMUX238, $mode_pin)"!][!//
        [!VAR "cINMUX238"="number(substring-before(substring-after($INMUX238,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 239 */!]
    [!IF "contains($INMUX239, $mode_pin)"!][!//
        [!VAR "cINMUX239"="number(substring-before(substring-after($INMUX239,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 240 */!]
    [!IF "contains($INMUX240, $mode_pin)"!][!//
        [!VAR "cINMUX240"="number(substring-before(substring-after($INMUX240,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 241 */!]
    [!IF "contains($INMUX241, $mode_pin)"!][!//
        [!VAR "cINMUX241"="number(substring-before(substring-after($INMUX241,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 242 */!]
    [!IF "contains($INMUX242, $mode_pin)"!][!//
        [!VAR "cINMUX242"="number(substring-before(substring-after($INMUX242,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 243 */!]
    [!IF "contains($INMUX243, $mode_pin)"!][!//
        [!VAR "cINMUX243"="number(substring-before(substring-after($INMUX243,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 244 */!]
    [!IF "contains($INMUX244, $mode_pin)"!][!//
        [!VAR "cINMUX244"="number(substring-before(substring-after($INMUX244,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 245 */!]
    [!IF "contains($INMUX245, $mode_pin)"!][!//
        [!VAR "cINMUX245"="number(substring-before(substring-after($INMUX245,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 246 */!]
    [!IF "contains($INMUX246, $mode_pin)"!][!//
        [!VAR "cINMUX246"="number(substring-before(substring-after($INMUX246,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 247 */!]
    [!IF "contains($INMUX247, $mode_pin)"!][!//
        [!VAR "cINMUX247"="number(substring-before(substring-after($INMUX247,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 248 */!]
    [!IF "contains($INMUX248, $mode_pin)"!][!//
        [!VAR "cINMUX248"="number(substring-before(substring-after($INMUX248,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 249 */!]
    [!IF "contains($INMUX249, $mode_pin)"!][!//
        [!VAR "cINMUX249"="number(substring-before(substring-after($INMUX249,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 250 */!]
    [!IF "contains($INMUX250, $mode_pin)"!][!//
        [!VAR "cINMUX250"="number(substring-before(substring-after($INMUX250,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 251 */!]
    [!IF "contains($INMUX251, $mode_pin)"!][!//
        [!VAR "cINMUX251"="number(substring-before(substring-after($INMUX251,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 252 */!]
    [!IF "contains($INMUX252, $mode_pin)"!][!//
        [!VAR "cINMUX252"="number(substring-before(substring-after($INMUX252,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 253 */!]
    [!IF "contains($INMUX253, $mode_pin)"!][!//
        [!VAR "cINMUX253"="number(substring-before(substring-after($INMUX253,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 254 */!]
    [!IF "contains($INMUX254, $mode_pin)"!][!//
        [!VAR "cINMUX254"="number(substring-before(substring-after($INMUX254,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 255 */!]
    [!IF "contains($INMUX255, $mode_pin)"!][!//
        [!VAR "cINMUX255"="number(substring-before(substring-after($INMUX255,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 256 */!]
    [!IF "contains($INMUX256, $mode_pin)"!][!//
        [!VAR "cINMUX256"="number(substring-before(substring-after($INMUX256,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 257 */!]
    [!IF "contains($INMUX257, $mode_pin)"!][!//
        [!VAR "cINMUX257"="number(substring-before(substring-after($INMUX257,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 258 */!]
    [!IF "contains($INMUX258, $mode_pin)"!][!//
        [!VAR "cINMUX258"="number(substring-before(substring-after($INMUX258,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 259 */!]
    [!IF "contains($INMUX259, $mode_pin)"!][!//
        [!VAR "cINMUX259"="number(substring-before(substring-after($INMUX259,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 260 */!]
    [!IF "contains($INMUX260, $mode_pin)"!][!//
        [!VAR "cINMUX260"="number(substring-before(substring-after($INMUX260,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 261 */!]
    [!IF "contains($INMUX261, $mode_pin)"!][!//
        [!VAR "cINMUX261"="number(substring-before(substring-after($INMUX261,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 262 */!]
    [!IF "contains($INMUX262, $mode_pin)"!][!//
        [!VAR "cINMUX262"="number(substring-before(substring-after($INMUX262,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 263 */!]
    [!IF "contains($INMUX263, $mode_pin)"!][!//
        [!VAR "cINMUX263"="number(substring-before(substring-after($INMUX263,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 264 */!]
    [!IF "contains($INMUX264, $mode_pin)"!][!//
        [!VAR "cINMUX264"="number(substring-before(substring-after($INMUX264,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 265 */!]
    [!IF "contains($INMUX265, $mode_pin)"!][!//
        [!VAR "cINMUX265"="number(substring-before(substring-after($INMUX265,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 266 */!]
    [!IF "contains($INMUX266, $mode_pin)"!][!//
        [!VAR "cINMUX266"="number(substring-before(substring-after($INMUX266,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 267 */!]
    [!IF "contains($INMUX267, $mode_pin)"!][!//
        [!VAR "cINMUX267"="number(substring-before(substring-after($INMUX267,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 268 */!]
    [!IF "contains($INMUX268, $mode_pin)"!][!//
        [!VAR "cINMUX268"="number(substring-before(substring-after($INMUX268,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 269 */!]
    [!IF "contains($INMUX269, $mode_pin)"!][!//
        [!VAR "cINMUX269"="number(substring-before(substring-after($INMUX269,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 270 */!]
    [!IF "contains($INMUX270, $mode_pin)"!][!//
        [!VAR "cINMUX270"="number(substring-before(substring-after($INMUX270,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 271 */!]
    [!IF "contains($INMUX271, $mode_pin)"!][!//
        [!VAR "cINMUX271"="number(substring-before(substring-after($INMUX271,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 272 */!]
    [!IF "contains($INMUX272, $mode_pin)"!][!//
        [!VAR "cINMUX272"="number(substring-before(substring-after($INMUX272,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 273 */!]
    [!IF "contains($INMUX273, $mode_pin)"!][!//
        [!VAR "cINMUX273"="number(substring-before(substring-after($INMUX273,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 274 */!]
    [!IF "contains($INMUX274, $mode_pin)"!][!//
        [!VAR "cINMUX274"="number(substring-before(substring-after($INMUX274,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 275 */!]
    [!IF "contains($INMUX275, $mode_pin)"!][!//
        [!VAR "cINMUX275"="number(substring-before(substring-after($INMUX275,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 276 */!]
    [!IF "contains($INMUX276, $mode_pin)"!][!//
        [!VAR "cINMUX276"="number(substring-before(substring-after($INMUX276,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 277 */!]
    [!IF "contains($INMUX277, $mode_pin)"!][!//
        [!VAR "cINMUX277"="number(substring-before(substring-after($INMUX277,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 278 */!]
    [!IF "contains($INMUX278, $mode_pin)"!][!//
        [!VAR "cINMUX278"="number(substring-before(substring-after($INMUX278,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 279 */!]
    [!IF "contains($INMUX279, $mode_pin)"!][!//
        [!VAR "cINMUX279"="number(substring-before(substring-after($INMUX279,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 280 */!]
    [!IF "contains($INMUX280, $mode_pin)"!][!//
        [!VAR "cINMUX280"="number(substring-before(substring-after($INMUX280,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 281 */!]
    [!IF "contains($INMUX281, $mode_pin)"!][!//
        [!VAR "cINMUX281"="number(substring-before(substring-after($INMUX281,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 282 */!]
    [!IF "contains($INMUX282, $mode_pin)"!][!//
        [!VAR "cINMUX282"="number(substring-before(substring-after($INMUX282,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 283 */!]
    [!IF "contains($INMUX283, $mode_pin)"!][!//
        [!VAR "cINMUX283"="number(substring-before(substring-after($INMUX283,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 284 */!]
    [!IF "contains($INMUX284, $mode_pin)"!][!//
        [!VAR "cINMUX284"="number(substring-before(substring-after($INMUX284,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 285 */!]
    [!IF "contains($INMUX285, $mode_pin)"!][!//
        [!VAR "cINMUX285"="number(substring-before(substring-after($INMUX285,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 286 */!]
    [!IF "contains($INMUX286, $mode_pin)"!][!//
        [!VAR "cINMUX286"="number(substring-before(substring-after($INMUX286,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 287 */!]
    [!IF "contains($INMUX287, $mode_pin)"!][!//
        [!VAR "cINMUX287"="number(substring-before(substring-after($INMUX287,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 288 */!]
    [!IF "contains($INMUX288, $mode_pin)"!][!//
        [!VAR "cINMUX288"="number(substring-before(substring-after($INMUX288,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 289 */!]
    [!IF "contains($INMUX289, $mode_pin)"!][!//
        [!VAR "cINMUX289"="number(substring-before(substring-after($INMUX289,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 290 */!]
    [!IF "contains($INMUX290, $mode_pin)"!][!//
        [!VAR "cINMUX290"="number(substring-before(substring-after($INMUX290,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 291 */!]
    [!IF "contains($INMUX291, $mode_pin)"!][!//
        [!VAR "cINMUX291"="number(substring-before(substring-after($INMUX291,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 292 */!]
    [!IF "contains($INMUX292, $mode_pin)"!][!//
        [!VAR "cINMUX292"="number(substring-before(substring-after($INMUX292,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 293 */!]
    [!IF "contains($INMUX293, $mode_pin)"!][!//
        [!VAR "cINMUX293"="number(substring-before(substring-after($INMUX293,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 294 */!]
    [!IF "contains($INMUX294, $mode_pin)"!][!//
        [!VAR "cINMUX294"="number(substring-before(substring-after($INMUX294,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 295 */!]
    [!IF "contains($INMUX295, $mode_pin)"!][!//
        [!VAR "cINMUX295"="number(substring-before(substring-after($INMUX295,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 296 */!]
    [!IF "contains($INMUX296, $mode_pin)"!][!//
        [!VAR "cINMUX296"="number(substring-before(substring-after($INMUX296,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 297 */!]
    [!IF "contains($INMUX297, $mode_pin)"!][!//
        [!VAR "cINMUX297"="number(substring-before(substring-after($INMUX297,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 298 */!]
    [!IF "contains($INMUX298, $mode_pin)"!][!//
        [!VAR "cINMUX298"="number(substring-before(substring-after($INMUX298,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 299 */!]
    [!IF "contains($INMUX299, $mode_pin)"!][!//
        [!VAR "cINMUX299"="number(substring-before(substring-after($INMUX299,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 300 */!]
    [!IF "contains($INMUX300, $mode_pin)"!][!//
        [!VAR "cINMUX300"="number(substring-before(substring-after($INMUX300,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 301 */!]
    [!IF "contains($INMUX301, $mode_pin)"!][!//
        [!VAR "cINMUX301"="number(substring-before(substring-after($INMUX301,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 302 */!]
    [!IF "contains($INMUX302, $mode_pin)"!][!//
        [!VAR "cINMUX302"="number(substring-before(substring-after($INMUX302,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 303 */!]
    [!IF "contains($INMUX303, $mode_pin)"!][!//
        [!VAR "cINMUX303"="number(substring-before(substring-after($INMUX303,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 304 */!]
    [!IF "contains($INMUX304, $mode_pin)"!][!//
        [!VAR "cINMUX304"="number(substring-before(substring-after($INMUX304,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 305 */!]
    [!IF "contains($INMUX305, $mode_pin)"!][!//
        [!VAR "cINMUX305"="number(substring-before(substring-after($INMUX305,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 306 */!]
    [!IF "contains($INMUX306, $mode_pin)"!][!//
        [!VAR "cINMUX306"="number(substring-before(substring-after($INMUX306,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 307 */!]
    [!IF "contains($INMUX307, $mode_pin)"!][!//
        [!VAR "cINMUX307"="number(substring-before(substring-after($INMUX307,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 308 */!]
    [!IF "contains($INMUX308, $mode_pin)"!][!//
        [!VAR "cINMUX308"="number(substring-before(substring-after($INMUX308,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 309 */!]
    [!IF "contains($INMUX309, $mode_pin)"!][!//
        [!VAR "cINMUX309"="number(substring-before(substring-after($INMUX309,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 310 */!]
    [!IF "contains($INMUX310, $mode_pin)"!][!//
        [!VAR "cINMUX310"="number(substring-before(substring-after($INMUX310,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 311 */!]
    [!IF "contains($INMUX311, $mode_pin)"!][!//
        [!VAR "cINMUX311"="number(substring-before(substring-after($INMUX311,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 312 */!]
    [!IF "contains($INMUX312, $mode_pin)"!][!//
        [!VAR "cINMUX312"="number(substring-before(substring-after($INMUX312,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 313 */!]
    [!IF "contains($INMUX313, $mode_pin)"!][!//
        [!VAR "cINMUX313"="number(substring-before(substring-after($INMUX313,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 314 */!]
    [!IF "contains($INMUX314, $mode_pin)"!][!//
        [!VAR "cINMUX314"="number(substring-before(substring-after($INMUX314,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 315 */!]
    [!IF "contains($INMUX315, $mode_pin)"!][!//
        [!VAR "cINMUX315"="number(substring-before(substring-after($INMUX315,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 316 */!]
    [!IF "contains($INMUX316, $mode_pin)"!][!//
        [!VAR "cINMUX316"="number(substring-before(substring-after($INMUX316,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 317 */!]
    [!IF "contains($INMUX317, $mode_pin)"!][!//
        [!VAR "cINMUX317"="number(substring-before(substring-after($INMUX317,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 318 */!]
    [!IF "contains($INMUX318, $mode_pin)"!][!//
        [!VAR "cINMUX318"="number(substring-before(substring-after($INMUX318,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 319 */!]
    [!IF "contains($INMUX319, $mode_pin)"!][!//
        [!VAR "cINMUX319"="number(substring-before(substring-after($INMUX319,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 320 */!]
    [!IF "contains($INMUX320, $mode_pin)"!][!//
        [!VAR "cINMUX320"="number(substring-before(substring-after($INMUX320,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 321 */!]
    [!IF "contains($INMUX321, $mode_pin)"!][!//
        [!VAR "cINMUX321"="number(substring-before(substring-after($INMUX321,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 322 */!]
    [!IF "contains($INMUX322, $mode_pin)"!][!//
        [!VAR "cINMUX322"="number(substring-before(substring-after($INMUX322,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 323 */!]
    [!IF "contains($INMUX323, $mode_pin)"!][!//
        [!VAR "cINMUX323"="number(substring-before(substring-after($INMUX323,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 324 */!]
    [!IF "contains($INMUX324, $mode_pin)"!][!//
        [!VAR "cINMUX324"="number(substring-before(substring-after($INMUX324,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 325 */!]
    [!IF "contains($INMUX325, $mode_pin)"!][!//
        [!VAR "cINMUX325"="number(substring-before(substring-after($INMUX325,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 326 */!]
    [!IF "contains($INMUX326, $mode_pin)"!][!//
        [!VAR "cINMUX326"="number(substring-before(substring-after($INMUX326,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 327 */!]
    [!IF "contains($INMUX327, $mode_pin)"!][!//
        [!VAR "cINMUX327"="number(substring-before(substring-after($INMUX327,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 328 */!]
    [!IF "contains($INMUX328, $mode_pin)"!][!//
        [!VAR "cINMUX328"="number(substring-before(substring-after($INMUX328,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 329 */!]
    [!IF "contains($INMUX329, $mode_pin)"!][!//
        [!VAR "cINMUX329"="number(substring-before(substring-after($INMUX329,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 330 */!]
    [!IF "contains($INMUX330, $mode_pin)"!][!//
        [!VAR "cINMUX330"="number(substring-before(substring-after($INMUX330,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 331 */!]
    [!IF "contains($INMUX331, $mode_pin)"!][!//
        [!VAR "cINMUX331"="number(substring-before(substring-after($INMUX331,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 332 */!]
    [!IF "contains($INMUX332, $mode_pin)"!][!//
        [!VAR "cINMUX332"="number(substring-before(substring-after($INMUX332,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 333 */!]
    [!IF "contains($INMUX333, $mode_pin)"!][!//
        [!VAR "cINMUX333"="number(substring-before(substring-after($INMUX333,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 334 */!]
    [!IF "contains($INMUX334, $mode_pin)"!][!//
        [!VAR "cINMUX334"="number(substring-before(substring-after($INMUX334,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 335 */!]
    [!IF "contains($INMUX335, $mode_pin)"!][!//
        [!VAR "cINMUX335"="number(substring-before(substring-after($INMUX335,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 336 */!]
    [!IF "contains($INMUX336, $mode_pin)"!][!//
        [!VAR "cINMUX336"="number(substring-before(substring-after($INMUX336,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 337 */!]
    [!IF "contains($INMUX337, $mode_pin)"!][!//
        [!VAR "cINMUX337"="number(substring-before(substring-after($INMUX337,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 338 */!]
    [!IF "contains($INMUX338, $mode_pin)"!][!//
        [!VAR "cINMUX338"="number(substring-before(substring-after($INMUX338,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 339 */!]
    [!IF "contains($INMUX339, $mode_pin)"!][!//
        [!VAR "cINMUX339"="number(substring-before(substring-after($INMUX339,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 340 */!]
    [!IF "contains($INMUX340, $mode_pin)"!][!//
        [!VAR "cINMUX340"="number(substring-before(substring-after($INMUX340,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 341 */!]
    [!IF "contains($INMUX341, $mode_pin)"!][!//
        [!VAR "cINMUX341"="number(substring-before(substring-after($INMUX341,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 342 */!]
    [!IF "contains($INMUX342, $mode_pin)"!][!//
        [!VAR "cINMUX342"="number(substring-before(substring-after($INMUX342,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 343 */!]
    [!IF "contains($INMUX343, $mode_pin)"!][!//
        [!VAR "cINMUX343"="number(substring-before(substring-after($INMUX343,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 344 */!]
    [!IF "contains($INMUX344, $mode_pin)"!][!//
        [!VAR "cINMUX344"="number(substring-before(substring-after($INMUX344,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 345 */!]
    [!IF "contains($INMUX345, $mode_pin)"!][!//
        [!VAR "cINMUX345"="number(substring-before(substring-after($INMUX345,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 346 */!]
    [!IF "contains($INMUX346, $mode_pin)"!][!//
        [!VAR "cINMUX346"="number(substring-before(substring-after($INMUX346,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 347 */!]
    [!IF "contains($INMUX347, $mode_pin)"!][!//
        [!VAR "cINMUX347"="number(substring-before(substring-after($INMUX347,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 348 */!]
    [!IF "contains($INMUX348, $mode_pin)"!][!//
        [!VAR "cINMUX348"="number(substring-before(substring-after($INMUX348,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 349 */!]
    [!IF "contains($INMUX349, $mode_pin)"!][!//
        [!VAR "cINMUX349"="number(substring-before(substring-after($INMUX349,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 350 */!]
    [!IF "contains($INMUX350, $mode_pin)"!][!//
        [!VAR "cINMUX350"="number(substring-before(substring-after($INMUX350,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 351 */!]
    [!IF "contains($INMUX351, $mode_pin)"!][!//
        [!VAR "cINMUX351"="number(substring-before(substring-after($INMUX351,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 352 */!]
    [!IF "contains($INMUX352, $mode_pin)"!][!//
        [!VAR "cINMUX352"="number(substring-before(substring-after($INMUX352,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 353 */!]
    [!IF "contains($INMUX353, $mode_pin)"!][!//
        [!VAR "cINMUX353"="number(substring-before(substring-after($INMUX353,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 354 */!]
    [!IF "contains($INMUX354, $mode_pin)"!][!//
        [!VAR "cINMUX354"="number(substring-before(substring-after($INMUX354,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 355 */!]
    [!IF "contains($INMUX355, $mode_pin)"!][!//
        [!VAR "cINMUX355"="number(substring-before(substring-after($INMUX355,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 356 */!]
    [!IF "contains($INMUX356, $mode_pin)"!][!//
        [!VAR "cINMUX356"="number(substring-before(substring-after($INMUX356,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 357 */!]
    [!IF "contains($INMUX357, $mode_pin)"!][!//
        [!VAR "cINMUX357"="number(substring-before(substring-after($INMUX357,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 358 */!]
    [!IF "contains($INMUX358, $mode_pin)"!][!//
        [!VAR "cINMUX358"="number(substring-before(substring-after($INMUX358,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 359 */!]
    [!IF "contains($INMUX359, $mode_pin)"!][!//
        [!VAR "cINMUX359"="number(substring-before(substring-after($INMUX359,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 360 */!]
    [!IF "contains($INMUX360, $mode_pin)"!][!//
        [!VAR "cINMUX360"="number(substring-before(substring-after($INMUX360,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 361 */!]
    [!IF "contains($INMUX361, $mode_pin)"!][!//
        [!VAR "cINMUX361"="number(substring-before(substring-after($INMUX361,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 362 */!]
    [!IF "contains($INMUX362, $mode_pin)"!][!//
        [!VAR "cINMUX362"="number(substring-before(substring-after($INMUX362,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 363 */!]
    [!IF "contains($INMUX363, $mode_pin)"!][!//
        [!VAR "cINMUX363"="number(substring-before(substring-after($INMUX363,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 364 */!]
    [!IF "contains($INMUX364, $mode_pin)"!][!//
        [!VAR "cINMUX364"="number(substring-before(substring-after($INMUX364,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 365 */!]
    [!IF "contains($INMUX365, $mode_pin)"!][!//
        [!VAR "cINMUX365"="number(substring-before(substring-after($INMUX365,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 366 */!]
    [!IF "contains($INMUX366, $mode_pin)"!][!//
        [!VAR "cINMUX366"="number(substring-before(substring-after($INMUX366,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 367 */!]
    [!IF "contains($INMUX367, $mode_pin)"!][!//
        [!VAR "cINMUX367"="number(substring-before(substring-after($INMUX367,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 368 */!]
    [!IF "contains($INMUX368, $mode_pin)"!][!//
        [!VAR "cINMUX368"="number(substring-before(substring-after($INMUX368,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 369 */!]
    [!IF "contains($INMUX369, $mode_pin)"!][!//
        [!VAR "cINMUX369"="number(substring-before(substring-after($INMUX369,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 370 */!]
    [!IF "contains($INMUX370, $mode_pin)"!][!//
        [!VAR "cINMUX370"="number(substring-before(substring-after($INMUX370,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 371 */!]
    [!IF "contains($INMUX371, $mode_pin)"!][!//
        [!VAR "cINMUX371"="number(substring-before(substring-after($INMUX371,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 372 */!]
    [!IF "contains($INMUX372, $mode_pin)"!][!//
        [!VAR "cINMUX372"="number(substring-before(substring-after($INMUX372,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 373 */!]
    [!IF "contains($INMUX373, $mode_pin)"!][!//
        [!VAR "cINMUX373"="number(substring-before(substring-after($INMUX373,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 374 */!]
    [!IF "contains($INMUX374, $mode_pin)"!][!//
        [!VAR "cINMUX374"="number(substring-before(substring-after($INMUX374,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 375 */!]
    [!IF "contains($INMUX375, $mode_pin)"!][!//
        [!VAR "cINMUX375"="number(substring-before(substring-after($INMUX375,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 376 */!]
    [!IF "contains($INMUX376, $mode_pin)"!][!//
        [!VAR "cINMUX376"="number(substring-before(substring-after($INMUX376,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 377 */!]
    [!IF "contains($INMUX377, $mode_pin)"!][!//
        [!VAR "cINMUX377"="number(substring-before(substring-after($INMUX377,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 378 */!]
    [!IF "contains($INMUX378, $mode_pin)"!][!//
        [!VAR "cINMUX378"="number(substring-before(substring-after($INMUX378,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 379 */!]
    [!IF "contains($INMUX379, $mode_pin)"!][!//
        [!VAR "cINMUX379"="number(substring-before(substring-after($INMUX379,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 380 */!]
    [!IF "contains($INMUX380, $mode_pin)"!][!//
        [!VAR "cINMUX380"="number(substring-before(substring-after($INMUX380,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 381 */!]
    [!IF "contains($INMUX381, $mode_pin)"!][!//
        [!VAR "cINMUX381"="number(substring-before(substring-after($INMUX381,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 382 */!]
    [!IF "contains($INMUX382, $mode_pin)"!][!//
        [!VAR "cINMUX382"="number(substring-before(substring-after($INMUX382,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 383 */!]
    [!IF "contains($INMUX383, $mode_pin)"!][!//
        [!VAR "cINMUX383"="number(substring-before(substring-after($INMUX383,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 384 */!]
    [!IF "contains($INMUX384, $mode_pin)"!][!//
        [!VAR "cINMUX384"="number(substring-before(substring-after($INMUX384,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 385 */!]
    [!IF "contains($INMUX385, $mode_pin)"!][!//
        [!VAR "cINMUX385"="number(substring-before(substring-after($INMUX385,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 386 */!]
    [!IF "contains($INMUX386, $mode_pin)"!][!//
        [!VAR "cINMUX386"="number(substring-before(substring-after($INMUX386,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 387 */!]
    [!IF "contains($INMUX387, $mode_pin)"!][!//
        [!VAR "cINMUX387"="number(substring-before(substring-after($INMUX387,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 388 */!]
    [!IF "contains($INMUX388, $mode_pin)"!][!//
        [!VAR "cINMUX388"="number(substring-before(substring-after($INMUX388,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 389 */!]
    [!IF "contains($INMUX389, $mode_pin)"!][!//
        [!VAR "cINMUX389"="number(substring-before(substring-after($INMUX389,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 390 */!]
    [!IF "contains($INMUX390, $mode_pin)"!][!//
        [!VAR "cINMUX390"="number(substring-before(substring-after($INMUX390,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 391 */!]
    [!IF "contains($INMUX391, $mode_pin)"!][!//
        [!VAR "cINMUX391"="number(substring-before(substring-after($INMUX391,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 392 */!]
    [!IF "contains($INMUX392, $mode_pin)"!][!//
        [!VAR "cINMUX392"="number(substring-before(substring-after($INMUX392,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 393 */!]
    [!IF "contains($INMUX393, $mode_pin)"!][!//
        [!VAR "cINMUX393"="number(substring-before(substring-after($INMUX393,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 394 */!]
    [!IF "contains($INMUX394, $mode_pin)"!][!//
        [!VAR "cINMUX394"="number(substring-before(substring-after($INMUX394,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 395 */!]
    [!IF "contains($INMUX395, $mode_pin)"!][!//
        [!VAR "cINMUX395"="number(substring-before(substring-after($INMUX395,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 396 */!]
    [!IF "contains($INMUX396, $mode_pin)"!][!//
        [!VAR "cINMUX396"="number(substring-before(substring-after($INMUX396,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 397 */!]
    [!IF "contains($INMUX397, $mode_pin)"!][!//
        [!VAR "cINMUX397"="number(substring-before(substring-after($INMUX397,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 398 */!]
    [!IF "contains($INMUX398, $mode_pin)"!][!//
        [!VAR "cINMUX398"="number(substring-before(substring-after($INMUX398,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 399 */!]
    [!IF "contains($INMUX399, $mode_pin)"!][!//
        [!VAR "cINMUX399"="number(substring-before(substring-after($INMUX399,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 400 */!]
    [!IF "contains($INMUX400, $mode_pin)"!][!//
        [!VAR "cINMUX400"="number(substring-before(substring-after($INMUX400,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 401 */!]
    [!IF "contains($INMUX401, $mode_pin)"!][!//
        [!VAR "cINMUX401"="number(substring-before(substring-after($INMUX401,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 402 */!]
    [!IF "contains($INMUX402, $mode_pin)"!][!//
        [!VAR "cINMUX402"="number(substring-before(substring-after($INMUX402,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 403 */!]
    [!IF "contains($INMUX403, $mode_pin)"!][!//
        [!VAR "cINMUX403"="number(substring-before(substring-after($INMUX403,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 404 */!]
    [!IF "contains($INMUX404, $mode_pin)"!][!//
        [!VAR "cINMUX404"="number(substring-before(substring-after($INMUX404,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 405 */!]
    [!IF "contains($INMUX405, $mode_pin)"!][!//
        [!VAR "cINMUX405"="number(substring-before(substring-after($INMUX405,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 406 */!]
    [!IF "contains($INMUX406, $mode_pin)"!][!//
        [!VAR "cINMUX406"="number(substring-before(substring-after($INMUX406,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 407 */!]
    [!IF "contains($INMUX407, $mode_pin)"!][!//
        [!VAR "cINMUX407"="number(substring-before(substring-after($INMUX407,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 408 */!]
    [!IF "contains($INMUX408, $mode_pin)"!][!//
        [!VAR "cINMUX408"="number(substring-before(substring-after($INMUX408,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 409 */!]
    [!IF "contains($INMUX409, $mode_pin)"!][!//
        [!VAR "cINMUX409"="number(substring-before(substring-after($INMUX409,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 410 */!]
    [!IF "contains($INMUX410, $mode_pin)"!][!//
        [!VAR "cINMUX410"="number(substring-before(substring-after($INMUX410,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 411 */!]
    [!IF "contains($INMUX411, $mode_pin)"!][!//
        [!VAR "cINMUX411"="number(substring-before(substring-after($INMUX411,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 412 */!]
    [!IF "contains($INMUX412, $mode_pin)"!][!//
        [!VAR "cINMUX412"="number(substring-before(substring-after($INMUX412,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 413 */!]
    [!IF "contains($INMUX413, $mode_pin)"!][!//
        [!VAR "cINMUX413"="number(substring-before(substring-after($INMUX413,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 414 */!]
    [!IF "contains($INMUX414, $mode_pin)"!][!//
        [!VAR "cINMUX414"="number(substring-before(substring-after($INMUX414,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 415 */!]
    [!IF "contains($INMUX415, $mode_pin)"!][!//
        [!VAR "cINMUX415"="number(substring-before(substring-after($INMUX415,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 416 */!]
    [!IF "contains($INMUX416, $mode_pin)"!][!//
        [!VAR "cINMUX416"="number(substring-before(substring-after($INMUX416,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 417 */!]
    [!IF "contains($INMUX417, $mode_pin)"!][!//
        [!VAR "cINMUX417"="number(substring-before(substring-after($INMUX417,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 418 */!]
    [!IF "contains($INMUX418, $mode_pin)"!][!//
        [!VAR "cINMUX418"="number(substring-before(substring-after($INMUX418,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 419 */!]
    [!IF "contains($INMUX419, $mode_pin)"!][!//
        [!VAR "cINMUX419"="number(substring-before(substring-after($INMUX419,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 420 */!]
    [!IF "contains($INMUX420, $mode_pin)"!][!//
        [!VAR "cINMUX420"="number(substring-before(substring-after($INMUX420,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 421 */!]
    [!IF "contains($INMUX421, $mode_pin)"!][!//
        [!VAR "cINMUX421"="number(substring-before(substring-after($INMUX421,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 422 */!]
    [!IF "contains($INMUX422, $mode_pin)"!][!//
        [!VAR "cINMUX422"="number(substring-before(substring-after($INMUX422,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 423 */!]
    [!IF "contains($INMUX423, $mode_pin)"!][!//
        [!VAR "cINMUX423"="number(substring-before(substring-after($INMUX423,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 424 */!]
    [!IF "contains($INMUX424, $mode_pin)"!][!//
        [!VAR "cINMUX424"="number(substring-before(substring-after($INMUX424,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 425 */!]
    [!IF "contains($INMUX425, $mode_pin)"!][!//
        [!VAR "cINMUX425"="number(substring-before(substring-after($INMUX425,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 426 */!]
    [!IF "contains($INMUX426, $mode_pin)"!][!//
        [!VAR "cINMUX426"="number(substring-before(substring-after($INMUX426,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 427 */!]
    [!IF "contains($INMUX427, $mode_pin)"!][!//
        [!VAR "cINMUX427"="number(substring-before(substring-after($INMUX427,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 428 */!]
    [!IF "contains($INMUX428, $mode_pin)"!][!//
        [!VAR "cINMUX428"="number(substring-before(substring-after($INMUX428,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 429 */!]
    [!IF "contains($INMUX429, $mode_pin)"!][!//
        [!VAR "cINMUX429"="number(substring-before(substring-after($INMUX429,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 430 */!]
    [!IF "contains($INMUX430, $mode_pin)"!][!//
        [!VAR "cINMUX430"="number(substring-before(substring-after($INMUX430,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 431 */!]
    [!IF "contains($INMUX431, $mode_pin)"!][!//
        [!VAR "cINMUX431"="number(substring-before(substring-after($INMUX431,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 432 */!]
    [!IF "contains($INMUX432, $mode_pin)"!][!//
        [!VAR "cINMUX432"="number(substring-before(substring-after($INMUX432,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 433 */!]
    [!IF "contains($INMUX433, $mode_pin)"!][!//
        [!VAR "cINMUX433"="number(substring-before(substring-after($INMUX433,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 434 */!]
    [!IF "contains($INMUX434, $mode_pin)"!][!//
        [!VAR "cINMUX434"="number(substring-before(substring-after($INMUX434,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 435 */!]
    [!IF "contains($INMUX435, $mode_pin)"!][!//
        [!VAR "cINMUX435"="number(substring-before(substring-after($INMUX435,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 436 */!]
    [!IF "contains($INMUX436, $mode_pin)"!][!//
        [!VAR "cINMUX436"="number(substring-before(substring-after($INMUX436,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 437 */!]
    [!IF "contains($INMUX437, $mode_pin)"!][!//
        [!VAR "cINMUX437"="number(substring-before(substring-after($INMUX437,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 438 */!]
    [!IF "contains($INMUX438, $mode_pin)"!][!//
        [!VAR "cINMUX438"="number(substring-before(substring-after($INMUX438,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 439 */!]
    [!IF "contains($INMUX439, $mode_pin)"!][!//
        [!VAR "cINMUX439"="number(substring-before(substring-after($INMUX439,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 440 */!]
    [!IF "contains($INMUX440, $mode_pin)"!][!//
        [!VAR "cINMUX440"="number(substring-before(substring-after($INMUX440,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 441 */!]
    [!IF "contains($INMUX441, $mode_pin)"!][!//
        [!VAR "cINMUX441"="number(substring-before(substring-after($INMUX441,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 442 */!]
    [!IF "contains($INMUX442, $mode_pin)"!][!//
        [!VAR "cINMUX442"="number(substring-before(substring-after($INMUX442,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 443 */!]
    [!IF "contains($INMUX443, $mode_pin)"!][!//
        [!VAR "cINMUX443"="number(substring-before(substring-after($INMUX443,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 444 */!]
    [!IF "contains($INMUX444, $mode_pin)"!][!//
        [!VAR "cINMUX444"="number(substring-before(substring-after($INMUX444,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 445 */!]
    [!IF "contains($INMUX445, $mode_pin)"!][!//
        [!VAR "cINMUX445"="number(substring-before(substring-after($INMUX445,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 446 */!]
    [!IF "contains($INMUX446, $mode_pin)"!][!//
        [!VAR "cINMUX446"="number(substring-before(substring-after($INMUX446,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 447 */!]
    [!IF "contains($INMUX447, $mode_pin)"!][!//
        [!VAR "cINMUX447"="number(substring-before(substring-after($INMUX447,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 448 */!]
    [!IF "contains($INMUX448, $mode_pin)"!][!//
        [!VAR "cINMUX448"="number(substring-before(substring-after($INMUX448,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 449 */!]
    [!IF "contains($INMUX449, $mode_pin)"!][!//
        [!VAR "cINMUX449"="number(substring-before(substring-after($INMUX449,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 450 */!]
    [!IF "contains($INMUX450, $mode_pin)"!][!//
        [!VAR "cINMUX450"="number(substring-before(substring-after($INMUX450,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 451 */!]
    [!IF "contains($INMUX451, $mode_pin)"!][!//
        [!VAR "cINMUX451"="number(substring-before(substring-after($INMUX451,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 452 */!]
    [!IF "contains($INMUX452, $mode_pin)"!][!//
        [!VAR "cINMUX452"="number(substring-before(substring-after($INMUX452,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 453 */!]
    [!IF "contains($INMUX453, $mode_pin)"!][!//
        [!VAR "cINMUX453"="number(substring-before(substring-after($INMUX453,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 454 */!]
    [!IF "contains($INMUX454, $mode_pin)"!][!//
        [!VAR "cINMUX454"="number(substring-before(substring-after($INMUX454,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 455 */!]
    [!IF "contains($INMUX455, $mode_pin)"!][!//
        [!VAR "cINMUX455"="number(substring-before(substring-after($INMUX455,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 456 */!]
    [!IF "contains($INMUX456, $mode_pin)"!][!//
        [!VAR "cINMUX456"="number(substring-before(substring-after($INMUX456,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 457 */!]
    [!IF "contains($INMUX457, $mode_pin)"!][!//
        [!VAR "cINMUX457"="number(substring-before(substring-after($INMUX457,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 458 */!]
    [!IF "contains($INMUX458, $mode_pin)"!][!//
        [!VAR "cINMUX458"="number(substring-before(substring-after($INMUX458,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 459 */!]
    [!IF "contains($INMUX459, $mode_pin)"!][!//
        [!VAR "cINMUX459"="number(substring-before(substring-after($INMUX459,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 460 */!]
    [!IF "contains($INMUX460, $mode_pin)"!][!//
        [!VAR "cINMUX460"="number(substring-before(substring-after($INMUX460,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 461 */!]
    [!IF "contains($INMUX461, $mode_pin)"!][!//
        [!VAR "cINMUX461"="number(substring-before(substring-after($INMUX461,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 462 */!]
    [!IF "contains($INMUX462, $mode_pin)"!][!//
        [!VAR "cINMUX462"="number(substring-before(substring-after($INMUX462,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 463 */!]
    [!IF "contains($INMUX463, $mode_pin)"!][!//
        [!VAR "cINMUX463"="number(substring-before(substring-after($INMUX463,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 464 */!]
    [!IF "contains($INMUX464, $mode_pin)"!][!//
        [!VAR "cINMUX464"="number(substring-before(substring-after($INMUX464,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 465 */!]
    [!IF "contains($INMUX465, $mode_pin)"!][!//
        [!VAR "cINMUX465"="number(substring-before(substring-after($INMUX465,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 466 */!]
    [!IF "contains($INMUX466, $mode_pin)"!][!//
        [!VAR "cINMUX466"="number(substring-before(substring-after($INMUX466,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 467 */!]
    [!IF "contains($INMUX467, $mode_pin)"!][!//
        [!VAR "cINMUX467"="number(substring-before(substring-after($INMUX467,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 468 */!]
    [!IF "contains($INMUX468, $mode_pin)"!][!//
        [!VAR "cINMUX468"="number(substring-before(substring-after($INMUX468,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 469 */!]
    [!IF "contains($INMUX469, $mode_pin)"!][!//
        [!VAR "cINMUX469"="number(substring-before(substring-after($INMUX469,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 470 */!]
    [!IF "contains($INMUX470, $mode_pin)"!][!//
        [!VAR "cINMUX470"="number(substring-before(substring-after($INMUX470,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 471 */!]
    [!IF "contains($INMUX471, $mode_pin)"!][!//
        [!VAR "cINMUX471"="number(substring-before(substring-after($INMUX471,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 472 */!]
    [!IF "contains($INMUX472, $mode_pin)"!][!//
        [!VAR "cINMUX472"="number(substring-before(substring-after($INMUX472,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 473 */!]
    [!IF "contains($INMUX473, $mode_pin)"!][!//
        [!VAR "cINMUX473"="number(substring-before(substring-after($INMUX473,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 474 */!]
    [!IF "contains($INMUX474, $mode_pin)"!][!//
        [!VAR "cINMUX474"="number(substring-before(substring-after($INMUX474,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 475 */!]
    [!IF "contains($INMUX475, $mode_pin)"!][!//
        [!VAR "cINMUX475"="number(substring-before(substring-after($INMUX475,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 476 */!]
    [!IF "contains($INMUX476, $mode_pin)"!][!//
        [!VAR "cINMUX476"="number(substring-before(substring-after($INMUX476,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 477 */!]
    [!IF "contains($INMUX477, $mode_pin)"!][!//
        [!VAR "cINMUX477"="number(substring-before(substring-after($INMUX477,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 478 */!]
    [!IF "contains($INMUX478, $mode_pin)"!][!//
        [!VAR "cINMUX478"="number(substring-before(substring-after($INMUX478,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 479 */!]
    [!IF "contains($INMUX479, $mode_pin)"!][!//
        [!VAR "cINMUX479"="number(substring-before(substring-after($INMUX479,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 480 */!]
    [!IF "contains($INMUX480, $mode_pin)"!][!//
        [!VAR "cINMUX480"="number(substring-before(substring-after($INMUX480,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 481 */!]
    [!IF "contains($INMUX481, $mode_pin)"!][!//
        [!VAR "cINMUX481"="number(substring-before(substring-after($INMUX481,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 482 */!]
    [!IF "contains($INMUX482, $mode_pin)"!][!//
        [!VAR "cINMUX482"="number(substring-before(substring-after($INMUX482,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 483 */!]
    [!IF "contains($INMUX483, $mode_pin)"!][!//
        [!VAR "cINMUX483"="number(substring-before(substring-after($INMUX483,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 484 */!]
    [!IF "contains($INMUX484, $mode_pin)"!][!//
        [!VAR "cINMUX484"="number(substring-before(substring-after($INMUX484,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 485 */!]
    [!IF "contains($INMUX485, $mode_pin)"!][!//
        [!VAR "cINMUX485"="number(substring-before(substring-after($INMUX485,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 486 */!]
    [!IF "contains($INMUX486, $mode_pin)"!][!//
        [!VAR "cINMUX486"="number(substring-before(substring-after($INMUX486,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 487 */!]
    [!IF "contains($INMUX487, $mode_pin)"!][!//
        [!VAR "cINMUX487"="number(substring-before(substring-after($INMUX487,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 488 */!]
    [!IF "contains($INMUX488, $mode_pin)"!][!//
        [!VAR "cINMUX488"="number(substring-before(substring-after($INMUX488,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 489 */!]
    [!IF "contains($INMUX489, $mode_pin)"!][!//
        [!VAR "cINMUX489"="number(substring-before(substring-after($INMUX489,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 490 */!]
    [!IF "contains($INMUX490, $mode_pin)"!][!//
        [!VAR "cINMUX490"="number(substring-before(substring-after($INMUX490,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 491 */!]
    [!IF "contains($INMUX491, $mode_pin)"!][!//
        [!VAR "cINMUX491"="number(substring-before(substring-after($INMUX491,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 492 */!]
    [!IF "contains($INMUX492, $mode_pin)"!][!//
        [!VAR "cINMUX492"="number(substring-before(substring-after($INMUX492,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 493 */!]
    [!IF "contains($INMUX493, $mode_pin)"!][!//
        [!VAR "cINMUX493"="number(substring-before(substring-after($INMUX493,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 494 */!]
    [!IF "contains($INMUX494, $mode_pin)"!][!//
        [!VAR "cINMUX494"="number(substring-before(substring-after($INMUX494,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 495 */!]
    [!IF "contains($INMUX495, $mode_pin)"!][!//
        [!VAR "cINMUX495"="number(substring-before(substring-after($INMUX495,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!ENDLOOP!][!//
    [!ENDNOCODE!][!//
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX119, 2)"!],
    (uint8)[!"num:inttohex($cINMUX120, 2)"!],
    (uint8)[!"num:inttohex($cINMUX121, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX128, 2)"!],
    (uint8)[!"num:inttohex($cINMUX129, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX143, 2)"!],
    (uint8)[!"num:inttohex($cINMUX144, 2)"!],
    (uint8)[!"num:inttohex($cINMUX145, 2)"!],
    (uint8)[!"num:inttohex($cINMUX146, 2)"!],
    (uint8)[!"num:inttohex($cINMUX147, 2)"!],
    (uint8)[!"num:inttohex($cINMUX148, 2)"!],
    (uint8)[!"num:inttohex($cINMUX149, 2)"!],
    (uint8)[!"num:inttohex($cINMUX150, 2)"!],
    (uint8)[!"num:inttohex($cINMUX151, 2)"!],
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX153, 2)"!],
    (uint8)[!"num:inttohex($cINMUX154, 2)"!],
    (uint8)[!"num:inttohex($cINMUX155, 2)"!],
    (uint8)[!"num:inttohex($cINMUX156, 2)"!],
    (uint8)[!"num:inttohex($cINMUX157, 2)"!],
    (uint8)[!"num:inttohex($cINMUX158, 2)"!],
    (uint8)[!"num:inttohex($cINMUX159, 2)"!],
    (uint8)[!"num:inttohex($cINMUX160, 2)"!],
    (uint8)[!"num:inttohex($cINMUX161, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX205, 2)"!],
    (uint8)[!"num:inttohex($cINMUX206, 2)"!],
    (uint8)[!"num:inttohex($cINMUX207, 2)"!],
    (uint8)[!"num:inttohex($cINMUX208, 2)"!],
    (uint8)[!"num:inttohex($cINMUX209, 2)"!],
    (uint8)[!"num:inttohex($cINMUX210, 2)"!],
    (uint8)[!"num:inttohex($cINMUX211, 2)"!],
    (uint8)[!"num:inttohex($cINMUX212, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX224, 2)"!],
    (uint8)[!"num:inttohex($cINMUX225, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX233, 2)"!],
    (uint8)[!"num:inttohex($cINMUX234, 2)"!],
    (uint8)[!"num:inttohex($cINMUX235, 2)"!],
    (uint8)[!"num:inttohex($cINMUX236, 2)"!],
    (uint8)[!"num:inttohex($cINMUX237, 2)"!],
    (uint8)[!"num:inttohex($cINMUX238, 2)"!],
    (uint8)[!"num:inttohex($cINMUX239, 2)"!],
    (uint8)[!"num:inttohex($cINMUX240, 2)"!],
    (uint8)[!"num:inttohex($cINMUX241, 2)"!],
    (uint8)[!"num:inttohex($cINMUX242, 2)"!],
    (uint8)[!"num:inttohex($cINMUX243, 2)"!],
    (uint8)[!"num:inttohex($cINMUX244, 2)"!],
    (uint8)[!"num:inttohex($cINMUX245, 2)"!],
    (uint8)[!"num:inttohex($cINMUX246, 2)"!],
    (uint8)[!"num:inttohex($cINMUX247, 2)"!],
    (uint8)[!"num:inttohex($cINMUX248, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX273, 2)"!],
    (uint8)[!"num:inttohex($cINMUX274, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX278, 2)"!],
    (uint8)[!"num:inttohex($cINMUX279, 2)"!],
    (uint8)[!"num:inttohex($cINMUX280, 2)"!],
    (uint8)[!"num:inttohex($cINMUX281, 2)"!],
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX283, 2)"!],
    (uint8)[!"num:inttohex($cINMUX284, 2)"!],
    (uint8)[!"num:inttohex($cINMUX285, 2)"!],
    (uint8)[!"num:inttohex($cINMUX286, 2)"!],
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX288, 2)"!],
    (uint8)[!"num:inttohex($cINMUX289, 2)"!],
    (uint8)[!"num:inttohex($cINMUX290, 2)"!],
    (uint8)[!"num:inttohex($cINMUX291, 2)"!],
    (uint8)[!"num:inttohex($cINMUX292, 2)"!],
    (uint8)[!"num:inttohex($cINMUX293, 2)"!],
    (uint8)[!"num:inttohex($cINMUX294, 2)"!],
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX296, 2)"!],
    (uint8)[!"num:inttohex($cINMUX297, 2)"!],
    (uint8)[!"num:inttohex($cINMUX298, 2)"!],
    (uint8)[!"num:inttohex($cINMUX299, 2)"!],
    (uint8)[!"num:inttohex($cINMUX300, 2)"!],
    (uint8)[!"num:inttohex($cINMUX301, 2)"!],
    (uint8)[!"num:inttohex($cINMUX302, 2)"!],
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX304, 2)"!],
    (uint8)[!"num:inttohex($cINMUX305, 2)"!],
    (uint8)[!"num:inttohex($cINMUX306, 2)"!],
    (uint8)[!"num:inttohex($cINMUX307, 2)"!],
    (uint8)[!"num:inttohex($cINMUX308, 2)"!],
    (uint8)[!"num:inttohex($cINMUX309, 2)"!],
    (uint8)[!"num:inttohex($cINMUX310, 2)"!],
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX312, 2)"!],
    (uint8)[!"num:inttohex($cINMUX313, 2)"!],
    (uint8)[!"num:inttohex($cINMUX314, 2)"!],
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX316, 2)"!],
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX318, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX322, 2)"!],
    (uint8)[!"num:inttohex($cINMUX323, 2)"!],
    (uint8)[!"num:inttohex($cINMUX324, 2)"!],
    (uint8)[!"num:inttohex($cINMUX325, 2)"!],
    (uint8)[!"num:inttohex($cINMUX326, 2)"!],
    (uint8)[!"num:inttohex($cINMUX327, 2)"!],
    (uint8)[!"num:inttohex($cINMUX328, 2)"!],
    (uint8)[!"num:inttohex($cINMUX329, 2)"!],
    (uint8)[!"num:inttohex($cINMUX330, 2)"!],
    (uint8)[!"num:inttohex($cINMUX331, 2)"!],
    (uint8)[!"num:inttohex($cINMUX332, 2)"!],
    (uint8)[!"num:inttohex($cINMUX333, 2)"!],
    (uint8)[!"num:inttohex($cINMUX334, 2)"!],
    (uint8)[!"num:inttohex($cINMUX335, 2)"!],
    (uint8)[!"num:inttohex($cINMUX336, 2)"!],
    (uint8)[!"num:inttohex($cINMUX337, 2)"!],
    (uint8)[!"num:inttohex($cINMUX338, 2)"!],
    (uint8)[!"num:inttohex($cINMUX339, 2)"!],
    (uint8)[!"num:inttohex($cINMUX340, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX343, 2)"!],
    (uint8)[!"num:inttohex($cINMUX344, 2)"!],
    (uint8)[!"num:inttohex($cINMUX345, 2)"!],
    (uint8)[!"num:inttohex($cINMUX346, 2)"!],
    (uint8)[!"num:inttohex($cINMUX347, 2)"!],
    (uint8)[!"num:inttohex($cINMUX348, 2)"!],
    (uint8)[!"num:inttohex($cINMUX349, 2)"!],
    (uint8)[!"num:inttohex($cINMUX350, 2)"!],
    (uint8)[!"num:inttohex($cINMUX351, 2)"!],
    (uint8)[!"num:inttohex($cINMUX352, 2)"!],
    (uint8)[!"num:inttohex($cINMUX353, 2)"!],
    (uint8)[!"num:inttohex($cINMUX354, 2)"!],
    (uint8)[!"num:inttohex($cINMUX355, 2)"!],
    (uint8)[!"num:inttohex($cINMUX356, 2)"!],
    (uint8)[!"num:inttohex($cINMUX357, 2)"!],
    (uint8)[!"num:inttohex($cINMUX358, 2)"!],
    (uint8)[!"num:inttohex($cINMUX359, 2)"!],
    (uint8)[!"num:inttohex($cINMUX360, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX363, 2)"!],
    (uint8)[!"num:inttohex($cINMUX364, 2)"!],
    (uint8)[!"num:inttohex($cINMUX365, 2)"!],
    (uint8)[!"num:inttohex($cINMUX366, 2)"!],
    (uint8)[!"num:inttohex($cINMUX367, 2)"!],
    (uint8)[!"num:inttohex($cINMUX368, 2)"!],
    (uint8)[!"num:inttohex($cINMUX369, 2)"!],
    (uint8)[!"num:inttohex($cINMUX370, 2)"!],
    (uint8)[!"num:inttohex($cINMUX371, 2)"!],
    (uint8)[!"num:inttohex($cINMUX372, 2)"!],
    (uint8)[!"num:inttohex($cINMUX373, 2)"!],
    (uint8)[!"num:inttohex($cINMUX374, 2)"!],
    (uint8)[!"num:inttohex($cINMUX375, 2)"!],
    (uint8)[!"num:inttohex($cINMUX376, 2)"!],
    (uint8)[!"num:inttohex($cINMUX377, 2)"!],
    (uint8)[!"num:inttohex($cINMUX378, 2)"!],
    (uint8)[!"num:inttohex($cINMUX379, 2)"!],
    (uint8)[!"num:inttohex($cINMUX380, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX383, 2)"!],
    (uint8)[!"num:inttohex($cINMUX384, 2)"!],
    (uint8)[!"num:inttohex($cINMUX385, 2)"!],
    (uint8)[!"num:inttohex($cINMUX386, 2)"!],
    (uint8)[!"num:inttohex($cINMUX387, 2)"!],
    (uint8)[!"num:inttohex($cINMUX388, 2)"!],
    (uint8)[!"num:inttohex($cINMUX389, 2)"!],
    (uint8)[!"num:inttohex($cINMUX390, 2)"!],
    (uint8)[!"num:inttohex($cINMUX391, 2)"!],
    (uint8)[!"num:inttohex($cINMUX392, 2)"!],
    (uint8)[!"num:inttohex($cINMUX393, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX398, 2)"!],
    (uint8)[!"num:inttohex($cINMUX399, 2)"!],
    (uint8)[!"num:inttohex($cINMUX400, 2)"!],
    (uint8)[!"num:inttohex($cINMUX401, 2)"!],
    (uint8)[!"num:inttohex($cINMUX402, 2)"!],
    (uint8)[!"num:inttohex($cINMUX403, 2)"!],
    (uint8)[!"num:inttohex($cINMUX404, 2)"!],
    (uint8)[!"num:inttohex($cINMUX405, 2)"!],
    (uint8)[!"num:inttohex($cINMUX406, 2)"!],
    (uint8)[!"num:inttohex($cINMUX407, 2)"!],
    (uint8)[!"num:inttohex($cINMUX408, 2)"!],
    (uint8)[!"num:inttohex($cINMUX409, 2)"!],
    (uint8)[!"num:inttohex($cINMUX410, 2)"!],
    (uint8)[!"num:inttohex($cINMUX411, 2)"!],
    (uint8)[!"num:inttohex($cINMUX412, 2)"!],
    (uint8)[!"num:inttohex($cINMUX413, 2)"!],
    (uint8)[!"num:inttohex($cINMUX414, 2)"!],
    (uint8)[!"num:inttohex($cINMUX415, 2)"!],
    (uint8)[!"num:inttohex($cINMUX416, 2)"!],
    (uint8)[!"num:inttohex($cINMUX417, 2)"!],
    (uint8)[!"num:inttohex($cINMUX418, 2)"!],
    (uint8)[!"num:inttohex($cINMUX419, 2)"!],
    (uint8)[!"num:inttohex($cINMUX420, 2)"!],
    (uint8)[!"num:inttohex($cINMUX421, 2)"!],
    (uint8)[!"num:inttohex($cINMUX422, 2)"!],
    (uint8)[!"num:inttohex($cINMUX423, 2)"!],
    (uint8)[!"num:inttohex($cINMUX424, 2)"!],
    (uint8)[!"num:inttohex($cINMUX425, 2)"!],
    (uint8)[!"num:inttohex($cINMUX426, 2)"!],
    (uint8)[!"num:inttohex($cINMUX427, 2)"!],
    (uint8)[!"num:inttohex($cINMUX428, 2)"!],
    (uint8)[!"num:inttohex($cINMUX429, 2)"!],
    (uint8)[!"num:inttohex($cINMUX430, 2)"!],
    (uint8)[!"num:inttohex($cINMUX431, 2)"!],
    (uint8)[!"num:inttohex($cINMUX432, 2)"!],
    (uint8)[!"num:inttohex($cINMUX433, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX467, 2)"!],
    (uint8)[!"num:inttohex($cINMUX468, 2)"!],
    (uint8)[!"num:inttohex($cINMUX469, 2)"!],
    (uint8)[!"num:inttohex($cINMUX470, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX473, 2)"!],
    (uint8)[!"num:inttohex($cINMUX474, 2)"!],
    (uint8)[!"num:inttohex($cINMUX475, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX478, 2)"!],
    (uint8)[!"num:inttohex($cINMUX479, 2)"!],
    (uint8)[!"num:inttohex($cINMUX480, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX483, 2)"!],
    (uint8)[!"num:inttohex($cINMUX484, 2)"!],
    (uint8)[!"num:inttohex($cINMUX485, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX488, 2)"!],
    (uint8)[!"num:inttohex($cINMUX489, 2)"!],
    (uint8)[!"num:inttohex($cINMUX490, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX493, 2)"!],
    (uint8)[!"num:inttohex($cINMUX494, 2)"!],
    (uint8)[!"num:inttohex($cINMUX495, 2)"!]
[!ELSEIF "((ecu:get('Port.Derivative'))='S32R')"!][!//
    [!NOCODE!][!//
    [!LOOP "PortContainer/*"!][!//
    [!LOOP "PortPin/*"!][!//
    [!VAR "mode_pin"="concat('MSCR_ON_', ./PortPinSiul2Instance, '_IMCR_ON_', ecu:list('Port.Siul2Instances')[num:i($siul2Instance)], '_PORT',number(./PortPinPcr), '_', ./PortPinMode,';')"!][!//
    [!/* INMUX 0 */!]
    [!IF "contains($INMUX0, $mode_pin)"!][!//
        [!VAR "cINMUX0"="number(substring-before(substring-after($INMUX0,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 1 */!]
    [!IF "contains($INMUX1, $mode_pin)"!][!//
        [!VAR "cINMUX1"="number(substring-before(substring-after($INMUX1,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 2 */!]
    [!IF "contains($INMUX2, $mode_pin)"!][!//
        [!VAR "cINMUX2"="number(substring-before(substring-after($INMUX2,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 3 */!]
    [!IF "contains($INMUX3, $mode_pin)"!][!//
        [!VAR "cINMUX3"="number(substring-before(substring-after($INMUX3,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 4 */!]
    [!IF "contains($INMUX4, $mode_pin)"!][!//
        [!VAR "cINMUX4"="number(substring-before(substring-after($INMUX4,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 5 */!]
    [!IF "contains($INMUX5, $mode_pin)"!][!//
        [!VAR "cINMUX5"="number(substring-before(substring-after($INMUX5,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 6 */!]
    [!IF "contains($INMUX6, $mode_pin)"!][!//
        [!VAR "cINMUX6"="number(substring-before(substring-after($INMUX6,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 7 */!]
    [!IF "contains($INMUX7, $mode_pin)"!][!//
        [!VAR "cINMUX7"="number(substring-before(substring-after($INMUX7,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 8 */!]
    [!IF "contains($INMUX8, $mode_pin)"!][!//
        [!VAR "cINMUX8"="number(substring-before(substring-after($INMUX8,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 9 */!]
    [!IF "contains($INMUX9, $mode_pin)"!][!//
        [!VAR "cINMUX9"="number(substring-before(substring-after($INMUX9,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 10 */!]
    [!IF "contains($INMUX10, $mode_pin)"!][!//
        [!VAR "cINMUX10"="number(substring-before(substring-after($INMUX10,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 11 */!]
    [!IF "contains($INMUX11, $mode_pin)"!][!//
        [!VAR "cINMUX11"="number(substring-before(substring-after($INMUX11,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 12 */!]
    [!IF "contains($INMUX12, $mode_pin)"!][!//
        [!VAR "cINMUX12"="number(substring-before(substring-after($INMUX12,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 13 */!]
    [!IF "contains($INMUX13, $mode_pin)"!][!//
        [!VAR "cINMUX13"="number(substring-before(substring-after($INMUX13,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 14 */!]
    [!IF "contains($INMUX14, $mode_pin)"!][!//
        [!VAR "cINMUX14"="number(substring-before(substring-after($INMUX14,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 15 */!]
    [!IF "contains($INMUX15, $mode_pin)"!][!//
        [!VAR "cINMUX15"="number(substring-before(substring-after($INMUX15,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 16 */!]
    [!IF "contains($INMUX16, $mode_pin)"!][!//
        [!VAR "cINMUX16"="number(substring-before(substring-after($INMUX16,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 17 */!]
    [!IF "contains($INMUX17, $mode_pin)"!][!//
        [!VAR "cINMUX17"="number(substring-before(substring-after($INMUX17,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 18 */!]
    [!IF "contains($INMUX18, $mode_pin)"!][!//
        [!VAR "cINMUX18"="number(substring-before(substring-after($INMUX18,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 19 */!]
    [!IF "contains($INMUX19, $mode_pin)"!][!//
        [!VAR "cINMUX19"="number(substring-before(substring-after($INMUX19,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 20 */!]
    [!IF "contains($INMUX20, $mode_pin)"!][!//
        [!VAR "cINMUX20"="number(substring-before(substring-after($INMUX20,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 21 */!]
    [!IF "contains($INMUX21, $mode_pin)"!][!//
        [!VAR "cINMUX21"="number(substring-before(substring-after($INMUX21,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 22 */!]
    [!IF "contains($INMUX22, $mode_pin)"!][!//
        [!VAR "cINMUX22"="number(substring-before(substring-after($INMUX22,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 23 */!]
    [!IF "contains($INMUX23, $mode_pin)"!][!//
        [!VAR "cINMUX23"="number(substring-before(substring-after($INMUX23,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 24 */!]
    [!IF "contains($INMUX24, $mode_pin)"!][!//
        [!VAR "cINMUX24"="number(substring-before(substring-after($INMUX24,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 25 */!]
    [!IF "contains($INMUX25, $mode_pin)"!][!//
        [!VAR "cINMUX25"="number(substring-before(substring-after($INMUX25,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 26 */!]
    [!IF "contains($INMUX26, $mode_pin)"!][!//
        [!VAR "cINMUX26"="number(substring-before(substring-after($INMUX26,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 27 */!]
    [!IF "contains($INMUX27, $mode_pin)"!][!//
        [!VAR "cINMUX27"="number(substring-before(substring-after($INMUX27,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 28 */!]
    [!IF "contains($INMUX28, $mode_pin)"!][!//
        [!VAR "cINMUX28"="number(substring-before(substring-after($INMUX28,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 29 */!]
    [!IF "contains($INMUX29, $mode_pin)"!][!//
        [!VAR "cINMUX29"="number(substring-before(substring-after($INMUX29,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 30 */!]
    [!IF "contains($INMUX30, $mode_pin)"!][!//
        [!VAR "cINMUX30"="number(substring-before(substring-after($INMUX30,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 31 */!]
    [!IF "contains($INMUX31, $mode_pin)"!][!//
        [!VAR "cINMUX31"="number(substring-before(substring-after($INMUX31,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 32 */!]
    [!IF "contains($INMUX32, $mode_pin)"!][!//
        [!VAR "cINMUX32"="number(substring-before(substring-after($INMUX32,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 33 */!]
    [!IF "contains($INMUX33, $mode_pin)"!][!//
        [!VAR "cINMUX33"="number(substring-before(substring-after($INMUX33,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 34 */!]
    [!IF "contains($INMUX34, $mode_pin)"!][!//
        [!VAR "cINMUX34"="number(substring-before(substring-after($INMUX34,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 35 */!]
    [!IF "contains($INMUX35, $mode_pin)"!][!//
        [!VAR "cINMUX35"="number(substring-before(substring-after($INMUX35,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 36 */!]
    [!IF "contains($INMUX36, $mode_pin)"!][!//
        [!VAR "cINMUX36"="number(substring-before(substring-after($INMUX36,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 37 */!]
    [!IF "contains($INMUX37, $mode_pin)"!][!//
        [!VAR "cINMUX37"="number(substring-before(substring-after($INMUX37,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 38 */!]
    [!IF "contains($INMUX38, $mode_pin)"!][!//
        [!VAR "cINMUX38"="number(substring-before(substring-after($INMUX38,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 39 */!]
    [!IF "contains($INMUX39, $mode_pin)"!][!//
        [!VAR "cINMUX39"="number(substring-before(substring-after($INMUX39,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 40 */!]
    [!IF "contains($INMUX40, $mode_pin)"!][!//
        [!VAR "cINMUX40"="number(substring-before(substring-after($INMUX40,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 41 */!]
    [!IF "contains($INMUX41, $mode_pin)"!][!//
        [!VAR "cINMUX41"="number(substring-before(substring-after($INMUX41,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 42 */!]
    [!IF "contains($INMUX42, $mode_pin)"!][!//
        [!VAR "cINMUX42"="number(substring-before(substring-after($INMUX42,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 43 */!]
    [!IF "contains($INMUX43, $mode_pin)"!][!//
        [!VAR "cINMUX43"="number(substring-before(substring-after($INMUX43,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 44 */!]
    [!IF "contains($INMUX44, $mode_pin)"!][!//
        [!VAR "cINMUX44"="number(substring-before(substring-after($INMUX44,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 45 */!]
    [!IF "contains($INMUX45, $mode_pin)"!][!//
        [!VAR "cINMUX45"="number(substring-before(substring-after($INMUX45,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 46 */!]
    [!IF "contains($INMUX46, $mode_pin)"!][!//
        [!VAR "cINMUX46"="number(substring-before(substring-after($INMUX46,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 47 */!]
    [!IF "contains($INMUX47, $mode_pin)"!][!//
        [!VAR "cINMUX47"="number(substring-before(substring-after($INMUX47,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 48 */!]
    [!IF "contains($INMUX48, $mode_pin)"!][!//
        [!VAR "cINMUX48"="number(substring-before(substring-after($INMUX48,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 49 */!]
    [!IF "contains($INMUX49, $mode_pin)"!][!//
        [!VAR "cINMUX49"="number(substring-before(substring-after($INMUX49,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 50 */!]
    [!IF "contains($INMUX50, $mode_pin)"!][!//
        [!VAR "cINMUX50"="number(substring-before(substring-after($INMUX50,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 51 */!]
    [!IF "contains($INMUX51, $mode_pin)"!][!//
        [!VAR "cINMUX51"="number(substring-before(substring-after($INMUX51,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 52 */!]
    [!IF "contains($INMUX52, $mode_pin)"!][!//
        [!VAR "cINMUX52"="number(substring-before(substring-after($INMUX52,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 53 */!]
    [!IF "contains($INMUX53, $mode_pin)"!][!//
        [!VAR "cINMUX53"="number(substring-before(substring-after($INMUX53,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 54 */!]
    [!IF "contains($INMUX54, $mode_pin)"!][!//
        [!VAR "cINMUX54"="number(substring-before(substring-after($INMUX54,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 55 */!]
    [!IF "contains($INMUX55, $mode_pin)"!][!//
        [!VAR "cINMUX55"="number(substring-before(substring-after($INMUX55,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 56 */!]
    [!IF "contains($INMUX56, $mode_pin)"!][!//
        [!VAR "cINMUX56"="number(substring-before(substring-after($INMUX56,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 57 */!]
    [!IF "contains($INMUX57, $mode_pin)"!][!//
        [!VAR "cINMUX57"="number(substring-before(substring-after($INMUX57,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 58 */!]
    [!IF "contains($INMUX58, $mode_pin)"!][!//
        [!VAR "cINMUX58"="number(substring-before(substring-after($INMUX58,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 59 */!]
    [!IF "contains($INMUX59, $mode_pin)"!][!//
        [!VAR "cINMUX59"="number(substring-before(substring-after($INMUX59,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 60 */!]
    [!IF "contains($INMUX60, $mode_pin)"!][!//
        [!VAR "cINMUX60"="number(substring-before(substring-after($INMUX60,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 61 */!]
    [!IF "contains($INMUX61, $mode_pin)"!][!//
        [!VAR "cINMUX61"="number(substring-before(substring-after($INMUX61,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 62 */!]
    [!IF "contains($INMUX62, $mode_pin)"!][!//
        [!VAR "cINMUX62"="number(substring-before(substring-after($INMUX62,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 63 */!]
    [!IF "contains($INMUX63, $mode_pin)"!][!//
        [!VAR "cINMUX63"="number(substring-before(substring-after($INMUX63,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 64 */!]
    [!IF "contains($INMUX64, $mode_pin)"!][!//
        [!VAR "cINMUX64"="number(substring-before(substring-after($INMUX64,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 65 */!]
    [!IF "contains($INMUX65, $mode_pin)"!][!//
        [!VAR "cINMUX65"="number(substring-before(substring-after($INMUX65,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 66 */!]
    [!IF "contains($INMUX66, $mode_pin)"!][!//
        [!VAR "cINMUX66"="number(substring-before(substring-after($INMUX66,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 67 */!]
    [!IF "contains($INMUX67, $mode_pin)"!][!//
        [!VAR "cINMUX67"="number(substring-before(substring-after($INMUX67,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 68 */!]
    [!IF "contains($INMUX68, $mode_pin)"!][!//
        [!VAR "cINMUX68"="number(substring-before(substring-after($INMUX68,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 69 */!]
    [!IF "contains($INMUX69, $mode_pin)"!][!//
        [!VAR "cINMUX69"="number(substring-before(substring-after($INMUX69,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 70 */!]
    [!IF "contains($INMUX70, $mode_pin)"!][!//
        [!VAR "cINMUX70"="number(substring-before(substring-after($INMUX70,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 71 */!]
    [!IF "contains($INMUX71, $mode_pin)"!][!//
        [!VAR "cINMUX71"="number(substring-before(substring-after($INMUX71,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 72 */!]
    [!IF "contains($INMUX72, $mode_pin)"!][!//
        [!VAR "cINMUX72"="number(substring-before(substring-after($INMUX72,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 73 */!]
    [!IF "contains($INMUX73, $mode_pin)"!][!//
        [!VAR "cINMUX73"="number(substring-before(substring-after($INMUX73,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 74 */!]
    [!IF "contains($INMUX74, $mode_pin)"!][!//
        [!VAR "cINMUX74"="number(substring-before(substring-after($INMUX74,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 75 */!]
    [!IF "contains($INMUX75, $mode_pin)"!][!//
        [!VAR "cINMUX75"="number(substring-before(substring-after($INMUX75,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 76 */!]
    [!IF "contains($INMUX76, $mode_pin)"!][!//
        [!VAR "cINMUX76"="number(substring-before(substring-after($INMUX76,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 77 */!]
    [!IF "contains($INMUX77, $mode_pin)"!][!//
        [!VAR "cINMUX77"="number(substring-before(substring-after($INMUX77,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 78 */!]
    [!IF "contains($INMUX78, $mode_pin)"!][!//
        [!VAR "cINMUX78"="number(substring-before(substring-after($INMUX78,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 79 */!]
    [!IF "contains($INMUX79, $mode_pin)"!][!//
        [!VAR "cINMUX79"="number(substring-before(substring-after($INMUX79,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 80 */!]
    [!IF "contains($INMUX80, $mode_pin)"!][!//
        [!VAR "cINMUX80"="number(substring-before(substring-after($INMUX80,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 81 */!]
    [!IF "contains($INMUX81, $mode_pin)"!][!//
        [!VAR "cINMUX81"="number(substring-before(substring-after($INMUX81,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 82 */!]
    [!IF "contains($INMUX82, $mode_pin)"!][!//
        [!VAR "cINMUX82"="number(substring-before(substring-after($INMUX82,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 83 */!]
    [!IF "contains($INMUX83, $mode_pin)"!][!//
        [!VAR "cINMUX83"="number(substring-before(substring-after($INMUX83,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 84 */!]
    [!IF "contains($INMUX84, $mode_pin)"!][!//
        [!VAR "cINMUX84"="number(substring-before(substring-after($INMUX84,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 85 */!]
    [!IF "contains($INMUX85, $mode_pin)"!][!//
        [!VAR "cINMUX85"="number(substring-before(substring-after($INMUX85,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 86 */!]
    [!IF "contains($INMUX86, $mode_pin)"!][!//
        [!VAR "cINMUX86"="number(substring-before(substring-after($INMUX86,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 87 */!]
    [!IF "contains($INMUX87, $mode_pin)"!][!//
        [!VAR "cINMUX87"="number(substring-before(substring-after($INMUX87,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 88 */!]
    [!IF "contains($INMUX88, $mode_pin)"!][!//
        [!VAR "cINMUX88"="number(substring-before(substring-after($INMUX88,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 89 */!]
    [!IF "contains($INMUX89, $mode_pin)"!][!//
        [!VAR "cINMUX89"="number(substring-before(substring-after($INMUX89,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 90 */!]
    [!IF "contains($INMUX90, $mode_pin)"!][!//
        [!VAR "cINMUX90"="number(substring-before(substring-after($INMUX90,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 91 */!]
    [!IF "contains($INMUX91, $mode_pin)"!][!//
        [!VAR "cINMUX91"="number(substring-before(substring-after($INMUX91,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 92 */!]
    [!IF "contains($INMUX92, $mode_pin)"!][!//
        [!VAR "cINMUX92"="number(substring-before(substring-after($INMUX92,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 93 */!]
    [!IF "contains($INMUX93, $mode_pin)"!][!//
        [!VAR "cINMUX93"="number(substring-before(substring-after($INMUX93,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 94 */!]
    [!IF "contains($INMUX94, $mode_pin)"!][!//
        [!VAR "cINMUX94"="number(substring-before(substring-after($INMUX94,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 95 */!]
    [!IF "contains($INMUX95, $mode_pin)"!][!//
        [!VAR "cINMUX95"="number(substring-before(substring-after($INMUX95,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 96 */!]
    [!IF "contains($INMUX96, $mode_pin)"!][!//
        [!VAR "cINMUX96"="number(substring-before(substring-after($INMUX96,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 97 */!]
    [!IF "contains($INMUX97, $mode_pin)"!][!//
        [!VAR "cINMUX97"="number(substring-before(substring-after($INMUX97,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 98 */!]
    [!IF "contains($INMUX98, $mode_pin)"!][!//
        [!VAR "cINMUX98"="number(substring-before(substring-after($INMUX98,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 99 */!]
    [!IF "contains($INMUX99, $mode_pin)"!][!//
        [!VAR "cINMUX99"="number(substring-before(substring-after($INMUX99,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 100 */!]
    [!IF "contains($INMUX100, $mode_pin)"!][!//
        [!VAR "cINMUX100"="number(substring-before(substring-after($INMUX100,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 101 */!]
    [!IF "contains($INMUX101, $mode_pin)"!][!//
        [!VAR "cINMUX101"="number(substring-before(substring-after($INMUX101,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 102 */!]
    [!IF "contains($INMUX102, $mode_pin)"!][!//
        [!VAR "cINMUX102"="number(substring-before(substring-after($INMUX102,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 103 */!]
    [!IF "contains($INMUX103, $mode_pin)"!][!//
        [!VAR "cINMUX103"="number(substring-before(substring-after($INMUX103,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 104 */!]
    [!IF "contains($INMUX104, $mode_pin)"!][!//
        [!VAR "cINMUX104"="number(substring-before(substring-after($INMUX104,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 105 */!]
    [!IF "contains($INMUX105, $mode_pin)"!][!//
        [!VAR "cINMUX105"="number(substring-before(substring-after($INMUX105,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 106 */!]
    [!IF "contains($INMUX106, $mode_pin)"!][!//
        [!VAR "cINMUX106"="number(substring-before(substring-after($INMUX106,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 107 */!]
    [!IF "contains($INMUX107, $mode_pin)"!][!//
        [!VAR "cINMUX107"="number(substring-before(substring-after($INMUX107,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 108 */!]
    [!IF "contains($INMUX108, $mode_pin)"!][!//
        [!VAR "cINMUX108"="number(substring-before(substring-after($INMUX108,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 109 */!]
    [!IF "contains($INMUX109, $mode_pin)"!][!//
        [!VAR "cINMUX109"="number(substring-before(substring-after($INMUX109,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 110 */!]
    [!IF "contains($INMUX110, $mode_pin)"!][!//
        [!VAR "cINMUX110"="number(substring-before(substring-after($INMUX110,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 111 */!]
    [!IF "contains($INMUX111, $mode_pin)"!][!//
        [!VAR "cINMUX111"="number(substring-before(substring-after($INMUX111,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 112 */!]
    [!IF "contains($INMUX112, $mode_pin)"!][!//
        [!VAR "cINMUX112"="number(substring-before(substring-after($INMUX112,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 113 */!]
    [!IF "contains($INMUX113, $mode_pin)"!][!//
        [!VAR "cINMUX113"="number(substring-before(substring-after($INMUX113,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 114 */!]
    [!IF "contains($INMUX114, $mode_pin)"!][!//
        [!VAR "cINMUX114"="number(substring-before(substring-after($INMUX114,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 115 */!]
    [!IF "contains($INMUX115, $mode_pin)"!][!//
        [!VAR "cINMUX115"="number(substring-before(substring-after($INMUX115,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 116 */!]
    [!IF "contains($INMUX116, $mode_pin)"!][!//
        [!VAR "cINMUX116"="number(substring-before(substring-after($INMUX116,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 117 */!]
    [!IF "contains($INMUX117, $mode_pin)"!][!//
        [!VAR "cINMUX117"="number(substring-before(substring-after($INMUX117,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 118 */!]
    [!IF "contains($INMUX118, $mode_pin)"!][!//
        [!VAR "cINMUX118"="number(substring-before(substring-after($INMUX118,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 119 */!]
    [!IF "contains($INMUX119, $mode_pin)"!][!//
        [!VAR "cINMUX119"="number(substring-before(substring-after($INMUX119,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 120 */!]
    [!IF "contains($INMUX120, $mode_pin)"!][!//
        [!VAR "cINMUX120"="number(substring-before(substring-after($INMUX120,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 121 */!]
    [!IF "contains($INMUX121, $mode_pin)"!][!//
        [!VAR "cINMUX121"="number(substring-before(substring-after($INMUX121,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 122 */!]
    [!IF "contains($INMUX122, $mode_pin)"!][!//
        [!VAR "cINMUX122"="number(substring-before(substring-after($INMUX122,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 123 */!]
    [!IF "contains($INMUX123, $mode_pin)"!][!//
        [!VAR "cINMUX123"="number(substring-before(substring-after($INMUX123,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 124 */!]
    [!IF "contains($INMUX124, $mode_pin)"!][!//
        [!VAR "cINMUX124"="number(substring-before(substring-after($INMUX124,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 125 */!]
    [!IF "contains($INMUX125, $mode_pin)"!][!//
        [!VAR "cINMUX125"="number(substring-before(substring-after($INMUX125,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 126 */!]
    [!IF "contains($INMUX126, $mode_pin)"!][!//
        [!VAR "cINMUX126"="number(substring-before(substring-after($INMUX126,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 127 */!]
    [!IF "contains($INMUX127, $mode_pin)"!][!//
        [!VAR "cINMUX127"="number(substring-before(substring-after($INMUX127,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 128 */!]
    [!IF "contains($INMUX128, $mode_pin)"!][!//
        [!VAR "cINMUX128"="number(substring-before(substring-after($INMUX128,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 129 */!]
    [!IF "contains($INMUX129, $mode_pin)"!][!//
        [!VAR "cINMUX129"="number(substring-before(substring-after($INMUX129,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 130 */!]
    [!IF "contains($INMUX130, $mode_pin)"!][!//
        [!VAR "cINMUX130"="number(substring-before(substring-after($INMUX130,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 131 */!]
    [!IF "contains($INMUX131, $mode_pin)"!][!//
        [!VAR "cINMUX131"="number(substring-before(substring-after($INMUX131,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 132 */!]
    [!IF "contains($INMUX132, $mode_pin)"!][!//
        [!VAR "cINMUX132"="number(substring-before(substring-after($INMUX132,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 133 */!]
    [!IF "contains($INMUX133, $mode_pin)"!][!//
        [!VAR "cINMUX133"="number(substring-before(substring-after($INMUX133,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 134 */!]
    [!IF "contains($INMUX134, $mode_pin)"!][!//
        [!VAR "cINMUX134"="number(substring-before(substring-after($INMUX134,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 135 */!]
    [!IF "contains($INMUX135, $mode_pin)"!][!//
        [!VAR "cINMUX135"="number(substring-before(substring-after($INMUX135,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 136 */!]
    [!IF "contains($INMUX136, $mode_pin)"!][!//
        [!VAR "cINMUX136"="number(substring-before(substring-after($INMUX136,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 137 */!]
    [!IF "contains($INMUX137, $mode_pin)"!][!//
        [!VAR "cINMUX137"="number(substring-before(substring-after($INMUX137,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 138 */!]
    [!IF "contains($INMUX138, $mode_pin)"!][!//
        [!VAR "cINMUX138"="number(substring-before(substring-after($INMUX138,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 139 */!]
    [!IF "contains($INMUX139, $mode_pin)"!][!//
        [!VAR "cINMUX139"="number(substring-before(substring-after($INMUX139,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 140 */!]
    [!IF "contains($INMUX140, $mode_pin)"!][!//
        [!VAR "cINMUX140"="number(substring-before(substring-after($INMUX140,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 141 */!]
    [!IF "contains($INMUX141, $mode_pin)"!][!//
        [!VAR "cINMUX141"="number(substring-before(substring-after($INMUX141,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 142 */!]
    [!IF "contains($INMUX142, $mode_pin)"!][!//
        [!VAR "cINMUX142"="number(substring-before(substring-after($INMUX142,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 143 */!]
    [!IF "contains($INMUX143, $mode_pin)"!][!//
        [!VAR "cINMUX143"="number(substring-before(substring-after($INMUX143,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 144 */!]
    [!IF "contains($INMUX144, $mode_pin)"!][!//
        [!VAR "cINMUX144"="number(substring-before(substring-after($INMUX144,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 145 */!]
    [!IF "contains($INMUX145, $mode_pin)"!][!//
        [!VAR "cINMUX145"="number(substring-before(substring-after($INMUX145,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 146 */!]
    [!IF "contains($INMUX146, $mode_pin)"!][!//
        [!VAR "cINMUX146"="number(substring-before(substring-after($INMUX146,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 147 */!]
    [!IF "contains($INMUX147, $mode_pin)"!][!//
        [!VAR "cINMUX147"="number(substring-before(substring-after($INMUX147,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 148 */!]
    [!IF "contains($INMUX148, $mode_pin)"!][!//
        [!VAR "cINMUX148"="number(substring-before(substring-after($INMUX148,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 149 */!]
    [!IF "contains($INMUX149, $mode_pin)"!][!//
        [!VAR "cINMUX149"="number(substring-before(substring-after($INMUX149,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 150 */!]
    [!IF "contains($INMUX150, $mode_pin)"!][!//
        [!VAR "cINMUX150"="number(substring-before(substring-after($INMUX150,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 151 */!]
    [!IF "contains($INMUX151, $mode_pin)"!][!//
        [!VAR "cINMUX151"="number(substring-before(substring-after($INMUX151,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 152 */!]
    [!IF "contains($INMUX152, $mode_pin)"!][!//
        [!VAR "cINMUX152"="number(substring-before(substring-after($INMUX152,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 153 */!]
    [!IF "contains($INMUX153, $mode_pin)"!][!//
        [!VAR "cINMUX153"="number(substring-before(substring-after($INMUX153,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 154 */!]
    [!IF "contains($INMUX154, $mode_pin)"!][!//
        [!VAR "cINMUX154"="number(substring-before(substring-after($INMUX154,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 155 */!]
    [!IF "contains($INMUX155, $mode_pin)"!][!//
        [!VAR "cINMUX155"="number(substring-before(substring-after($INMUX155,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 156 */!]
    [!IF "contains($INMUX156, $mode_pin)"!][!//
        [!VAR "cINMUX156"="number(substring-before(substring-after($INMUX156,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 157 */!]
    [!IF "contains($INMUX157, $mode_pin)"!][!//
        [!VAR "cINMUX157"="number(substring-before(substring-after($INMUX157,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 158 */!]
    [!IF "contains($INMUX158, $mode_pin)"!][!//
        [!VAR "cINMUX158"="number(substring-before(substring-after($INMUX158,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 159 */!]
    [!IF "contains($INMUX159, $mode_pin)"!][!//
        [!VAR "cINMUX159"="number(substring-before(substring-after($INMUX159,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 160 */!]
    [!IF "contains($INMUX160, $mode_pin)"!][!//
        [!VAR "cINMUX160"="number(substring-before(substring-after($INMUX160,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 161 */!]
    [!IF "contains($INMUX161, $mode_pin)"!][!//
        [!VAR "cINMUX161"="number(substring-before(substring-after($INMUX161,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 162 */!]
    [!IF "contains($INMUX162, $mode_pin)"!][!//
        [!VAR "cINMUX162"="number(substring-before(substring-after($INMUX162,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 163 */!]
    [!IF "contains($INMUX163, $mode_pin)"!][!//
        [!VAR "cINMUX163"="number(substring-before(substring-after($INMUX163,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 164 */!]
    [!IF "contains($INMUX164, $mode_pin)"!][!//
        [!VAR "cINMUX164"="number(substring-before(substring-after($INMUX164,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 165 */!]
    [!IF "contains($INMUX165, $mode_pin)"!][!//
        [!VAR "cINMUX165"="number(substring-before(substring-after($INMUX165,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 166 */!]
    [!IF "contains($INMUX166, $mode_pin)"!][!//
        [!VAR "cINMUX166"="number(substring-before(substring-after($INMUX166,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 167 */!]
    [!IF "contains($INMUX167, $mode_pin)"!][!//
        [!VAR "cINMUX167"="number(substring-before(substring-after($INMUX167,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 168 */!]
    [!IF "contains($INMUX168, $mode_pin)"!][!//
        [!VAR "cINMUX168"="number(substring-before(substring-after($INMUX168,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 169 */!]
    [!IF "contains($INMUX169, $mode_pin)"!][!//
        [!VAR "cINMUX169"="number(substring-before(substring-after($INMUX169,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 170 */!]
    [!IF "contains($INMUX170, $mode_pin)"!][!//
        [!VAR "cINMUX170"="number(substring-before(substring-after($INMUX170,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 171 */!]
    [!IF "contains($INMUX171, $mode_pin)"!][!//
        [!VAR "cINMUX171"="number(substring-before(substring-after($INMUX171,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 172 */!]
    [!IF "contains($INMUX172, $mode_pin)"!][!//
        [!VAR "cINMUX172"="number(substring-before(substring-after($INMUX172,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 173 */!]
    [!IF "contains($INMUX173, $mode_pin)"!][!//
        [!VAR "cINMUX173"="number(substring-before(substring-after($INMUX173,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 174 */!]
    [!IF "contains($INMUX174, $mode_pin)"!][!//
        [!VAR "cINMUX174"="number(substring-before(substring-after($INMUX174,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 175 */!]
    [!IF "contains($INMUX175, $mode_pin)"!][!//
        [!VAR "cINMUX175"="number(substring-before(substring-after($INMUX175,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 176 */!]
    [!IF "contains($INMUX176, $mode_pin)"!][!//
        [!VAR "cINMUX176"="number(substring-before(substring-after($INMUX176,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 177 */!]
    [!IF "contains($INMUX177, $mode_pin)"!][!//
        [!VAR "cINMUX177"="number(substring-before(substring-after($INMUX177,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 178 */!]
    [!IF "contains($INMUX178, $mode_pin)"!][!//
        [!VAR "cINMUX178"="number(substring-before(substring-after($INMUX178,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 179 */!]
    [!IF "contains($INMUX179, $mode_pin)"!][!//
        [!VAR "cINMUX179"="number(substring-before(substring-after($INMUX179,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 180 */!]
    [!IF "contains($INMUX180, $mode_pin)"!][!//
        [!VAR "cINMUX180"="number(substring-before(substring-after($INMUX180,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 181 */!]
    [!IF "contains($INMUX181, $mode_pin)"!][!//
        [!VAR "cINMUX181"="number(substring-before(substring-after($INMUX181,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 182 */!]
    [!IF "contains($INMUX182, $mode_pin)"!][!//
        [!VAR "cINMUX182"="number(substring-before(substring-after($INMUX182,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 183 */!]
    [!IF "contains($INMUX183, $mode_pin)"!][!//
        [!VAR "cINMUX183"="number(substring-before(substring-after($INMUX183,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 184 */!]
    [!IF "contains($INMUX184, $mode_pin)"!][!//
        [!VAR "cINMUX184"="number(substring-before(substring-after($INMUX184,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 185 */!]
    [!IF "contains($INMUX185, $mode_pin)"!][!//
        [!VAR "cINMUX185"="number(substring-before(substring-after($INMUX185,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 186 */!]
    [!IF "contains($INMUX186, $mode_pin)"!][!//
        [!VAR "cINMUX186"="number(substring-before(substring-after($INMUX186,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 187 */!]
    [!IF "contains($INMUX187, $mode_pin)"!][!//
        [!VAR "cINMUX187"="number(substring-before(substring-after($INMUX187,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 188 */!]
    [!IF "contains($INMUX188, $mode_pin)"!][!//
        [!VAR "cINMUX188"="number(substring-before(substring-after($INMUX188,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 189 */!]
    [!IF "contains($INMUX189, $mode_pin)"!][!//
        [!VAR "cINMUX189"="number(substring-before(substring-after($INMUX189,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 190 */!]
    [!IF "contains($INMUX190, $mode_pin)"!][!//
        [!VAR "cINMUX190"="number(substring-before(substring-after($INMUX190,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 191 */!]
    [!IF "contains($INMUX191, $mode_pin)"!][!//
        [!VAR "cINMUX191"="number(substring-before(substring-after($INMUX191,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 192 */!]
    [!IF "contains($INMUX192, $mode_pin)"!][!//
        [!VAR "cINMUX192"="number(substring-before(substring-after($INMUX192,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 193 */!]
    [!IF "contains($INMUX193, $mode_pin)"!][!//
        [!VAR "cINMUX193"="number(substring-before(substring-after($INMUX193,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 194 */!]
    [!IF "contains($INMUX194, $mode_pin)"!][!//
        [!VAR "cINMUX194"="number(substring-before(substring-after($INMUX194,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 195 */!]
    [!IF "contains($INMUX195, $mode_pin)"!][!//
        [!VAR "cINMUX195"="number(substring-before(substring-after($INMUX195,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 196 */!]
    [!IF "contains($INMUX196, $mode_pin)"!][!//
        [!VAR "cINMUX196"="number(substring-before(substring-after($INMUX196,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 197 */!]
    [!IF "contains($INMUX197, $mode_pin)"!][!//
        [!VAR "cINMUX197"="number(substring-before(substring-after($INMUX197,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 198 */!]
    [!IF "contains($INMUX198, $mode_pin)"!][!//
        [!VAR "cINMUX198"="number(substring-before(substring-after($INMUX198,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 199 */!]
    [!IF "contains($INMUX199, $mode_pin)"!][!//
        [!VAR "cINMUX199"="number(substring-before(substring-after($INMUX199,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 200 */!]
    [!IF "contains($INMUX200, $mode_pin)"!][!//
        [!VAR "cINMUX200"="number(substring-before(substring-after($INMUX200,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 201 */!]
    [!IF "contains($INMUX201, $mode_pin)"!][!//
        [!VAR "cINMUX201"="number(substring-before(substring-after($INMUX201,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 202 */!]
    [!IF "contains($INMUX202, $mode_pin)"!][!//
        [!VAR "cINMUX202"="number(substring-before(substring-after($INMUX202,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 203 */!]
    [!IF "contains($INMUX203, $mode_pin)"!][!//
        [!VAR "cINMUX203"="number(substring-before(substring-after($INMUX203,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 204 */!]
    [!IF "contains($INMUX204, $mode_pin)"!][!//
        [!VAR "cINMUX204"="number(substring-before(substring-after($INMUX204,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 205 */!]
    [!IF "contains($INMUX205, $mode_pin)"!][!//
        [!VAR "cINMUX205"="number(substring-before(substring-after($INMUX205,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 206 */!]
    [!IF "contains($INMUX206, $mode_pin)"!][!//
        [!VAR "cINMUX206"="number(substring-before(substring-after($INMUX206,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 207 */!]
    [!IF "contains($INMUX207, $mode_pin)"!][!//
        [!VAR "cINMUX207"="number(substring-before(substring-after($INMUX207,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 208 */!]
    [!IF "contains($INMUX208, $mode_pin)"!][!//
        [!VAR "cINMUX208"="number(substring-before(substring-after($INMUX208,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 209 */!]
    [!IF "contains($INMUX209, $mode_pin)"!][!//
        [!VAR "cINMUX209"="number(substring-before(substring-after($INMUX209,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 210 */!]
    [!IF "contains($INMUX210, $mode_pin)"!][!//
        [!VAR "cINMUX210"="number(substring-before(substring-after($INMUX210,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 211 */!]
    [!IF "contains($INMUX211, $mode_pin)"!][!//
        [!VAR "cINMUX211"="number(substring-before(substring-after($INMUX211,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 212 */!]
    [!IF "contains($INMUX212, $mode_pin)"!][!//
        [!VAR "cINMUX212"="number(substring-before(substring-after($INMUX212,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 213 */!]
    [!IF "contains($INMUX213, $mode_pin)"!][!//
        [!VAR "cINMUX213"="number(substring-before(substring-after($INMUX213,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 214 */!]
    [!IF "contains($INMUX214, $mode_pin)"!][!//
        [!VAR "cINMUX214"="number(substring-before(substring-after($INMUX214,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 215 */!]
    [!IF "contains($INMUX215, $mode_pin)"!][!//
        [!VAR "cINMUX215"="number(substring-before(substring-after($INMUX215,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 216 */!]
    [!IF "contains($INMUX216, $mode_pin)"!][!//
        [!VAR "cINMUX216"="number(substring-before(substring-after($INMUX216,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 217 */!]
    [!IF "contains($INMUX217, $mode_pin)"!][!//
        [!VAR "cINMUX217"="number(substring-before(substring-after($INMUX217,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 218 */!]
    [!IF "contains($INMUX218, $mode_pin)"!][!//
        [!VAR "cINMUX218"="number(substring-before(substring-after($INMUX218,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 219 */!]
    [!IF "contains($INMUX219, $mode_pin)"!][!//
        [!VAR "cINMUX219"="number(substring-before(substring-after($INMUX219,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 220 */!]
    [!IF "contains($INMUX220, $mode_pin)"!][!//
        [!VAR "cINMUX220"="number(substring-before(substring-after($INMUX220,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 221 */!]
    [!IF "contains($INMUX221, $mode_pin)"!][!//
        [!VAR "cINMUX221"="number(substring-before(substring-after($INMUX221,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 222 */!]
    [!IF "contains($INMUX222, $mode_pin)"!][!//
        [!VAR "cINMUX222"="number(substring-before(substring-after($INMUX222,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 223 */!]
    [!IF "contains($INMUX223, $mode_pin)"!][!//
        [!VAR "cINMUX223"="number(substring-before(substring-after($INMUX223,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 224 */!]
    [!IF "contains($INMUX224, $mode_pin)"!][!//
        [!VAR "cINMUX224"="number(substring-before(substring-after($INMUX224,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 225 */!]
    [!IF "contains($INMUX225, $mode_pin)"!][!//
        [!VAR "cINMUX225"="number(substring-before(substring-after($INMUX225,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 226 */!]
    [!IF "contains($INMUX226, $mode_pin)"!][!//
        [!VAR "cINMUX226"="number(substring-before(substring-after($INMUX226,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 227 */!]
    [!IF "contains($INMUX227, $mode_pin)"!][!//
        [!VAR "cINMUX227"="number(substring-before(substring-after($INMUX227,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 228 */!]
    [!IF "contains($INMUX228, $mode_pin)"!][!//
        [!VAR "cINMUX228"="number(substring-before(substring-after($INMUX228,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 229 */!]
    [!IF "contains($INMUX229, $mode_pin)"!][!//
        [!VAR "cINMUX229"="number(substring-before(substring-after($INMUX229,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 230 */!]
    [!IF "contains($INMUX230, $mode_pin)"!][!//
        [!VAR "cINMUX230"="number(substring-before(substring-after($INMUX230,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 231 */!]
    [!IF "contains($INMUX231, $mode_pin)"!][!//
        [!VAR "cINMUX231"="number(substring-before(substring-after($INMUX231,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 232 */!]
    [!IF "contains($INMUX232, $mode_pin)"!][!//
        [!VAR "cINMUX232"="number(substring-before(substring-after($INMUX232,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 233 */!]
    [!IF "contains($INMUX233, $mode_pin)"!][!//
        [!VAR "cINMUX233"="number(substring-before(substring-after($INMUX233,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 234 */!]
    [!IF "contains($INMUX234, $mode_pin)"!][!//
        [!VAR "cINMUX234"="number(substring-before(substring-after($INMUX234,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 235 */!]
    [!IF "contains($INMUX235, $mode_pin)"!][!//
        [!VAR "cINMUX235"="number(substring-before(substring-after($INMUX235,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 236 */!]
    [!IF "contains($INMUX236, $mode_pin)"!][!//
        [!VAR "cINMUX236"="number(substring-before(substring-after($INMUX236,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 237 */!]
    [!IF "contains($INMUX237, $mode_pin)"!][!//
        [!VAR "cINMUX237"="number(substring-before(substring-after($INMUX237,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 238 */!]
    [!IF "contains($INMUX238, $mode_pin)"!][!//
        [!VAR "cINMUX238"="number(substring-before(substring-after($INMUX238,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 239 */!]
    [!IF "contains($INMUX239, $mode_pin)"!][!//
        [!VAR "cINMUX239"="number(substring-before(substring-after($INMUX239,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 240 */!]
    [!IF "contains($INMUX240, $mode_pin)"!][!//
        [!VAR "cINMUX240"="number(substring-before(substring-after($INMUX240,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 241 */!]
    [!IF "contains($INMUX241, $mode_pin)"!][!//
        [!VAR "cINMUX241"="number(substring-before(substring-after($INMUX241,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 242 */!]
    [!IF "contains($INMUX242, $mode_pin)"!][!//
        [!VAR "cINMUX242"="number(substring-before(substring-after($INMUX242,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 243 */!]
    [!IF "contains($INMUX243, $mode_pin)"!][!//
        [!VAR "cINMUX243"="number(substring-before(substring-after($INMUX243,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 244 */!]
    [!IF "contains($INMUX244, $mode_pin)"!][!//
        [!VAR "cINMUX244"="number(substring-before(substring-after($INMUX244,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 245 */!]
    [!IF "contains($INMUX245, $mode_pin)"!][!//
        [!VAR "cINMUX245"="number(substring-before(substring-after($INMUX245,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 246 */!]
    [!IF "contains($INMUX246, $mode_pin)"!][!//
        [!VAR "cINMUX246"="number(substring-before(substring-after($INMUX246,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 247 */!]
    [!IF "contains($INMUX247, $mode_pin)"!][!//
        [!VAR "cINMUX247"="number(substring-before(substring-after($INMUX247,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 248 */!]
    [!IF "contains($INMUX248, $mode_pin)"!][!//
        [!VAR "cINMUX248"="number(substring-before(substring-after($INMUX248,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 249 */!]
    [!IF "contains($INMUX249, $mode_pin)"!][!//
        [!VAR "cINMUX249"="number(substring-before(substring-after($INMUX249,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 250 */!]
    [!IF "contains($INMUX250, $mode_pin)"!][!//
        [!VAR "cINMUX250"="number(substring-before(substring-after($INMUX250,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 251 */!]
    [!IF "contains($INMUX251, $mode_pin)"!][!//
        [!VAR "cINMUX251"="number(substring-before(substring-after($INMUX251,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 252 */!]
    [!IF "contains($INMUX252, $mode_pin)"!][!//
        [!VAR "cINMUX252"="number(substring-before(substring-after($INMUX252,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 253 */!]
    [!IF "contains($INMUX253, $mode_pin)"!][!//
        [!VAR "cINMUX253"="number(substring-before(substring-after($INMUX253,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 254 */!]
    [!IF "contains($INMUX254, $mode_pin)"!][!//
        [!VAR "cINMUX254"="number(substring-before(substring-after($INMUX254,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 255 */!]
    [!IF "contains($INMUX255, $mode_pin)"!][!//
        [!VAR "cINMUX255"="number(substring-before(substring-after($INMUX255,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 256 */!]
    [!IF "contains($INMUX256, $mode_pin)"!][!//
        [!VAR "cINMUX256"="number(substring-before(substring-after($INMUX256,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 257 */!]
    [!IF "contains($INMUX257, $mode_pin)"!][!//
        [!VAR "cINMUX257"="number(substring-before(substring-after($INMUX257,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 258 */!]
    [!IF "contains($INMUX258, $mode_pin)"!][!//
        [!VAR "cINMUX258"="number(substring-before(substring-after($INMUX258,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 259 */!]
    [!IF "contains($INMUX259, $mode_pin)"!][!//
        [!VAR "cINMUX259"="number(substring-before(substring-after($INMUX259,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 260 */!]
    [!IF "contains($INMUX260, $mode_pin)"!][!//
        [!VAR "cINMUX260"="number(substring-before(substring-after($INMUX260,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 261 */!]
    [!IF "contains($INMUX261, $mode_pin)"!][!//
        [!VAR "cINMUX261"="number(substring-before(substring-after($INMUX261,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 262 */!]
    [!IF "contains($INMUX262, $mode_pin)"!][!//
        [!VAR "cINMUX262"="number(substring-before(substring-after($INMUX262,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 263 */!]
    [!IF "contains($INMUX263, $mode_pin)"!][!//
        [!VAR "cINMUX263"="number(substring-before(substring-after($INMUX263,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 264 */!]
    [!IF "contains($INMUX264, $mode_pin)"!][!//
        [!VAR "cINMUX264"="number(substring-before(substring-after($INMUX264,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 265 */!]
    [!IF "contains($INMUX265, $mode_pin)"!][!//
        [!VAR "cINMUX265"="number(substring-before(substring-after($INMUX265,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 266 */!]
    [!IF "contains($INMUX266, $mode_pin)"!][!//
        [!VAR "cINMUX266"="number(substring-before(substring-after($INMUX266,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 267 */!]
    [!IF "contains($INMUX267, $mode_pin)"!][!//
        [!VAR "cINMUX267"="number(substring-before(substring-after($INMUX267,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 268 */!]
    [!IF "contains($INMUX268, $mode_pin)"!][!//
        [!VAR "cINMUX268"="number(substring-before(substring-after($INMUX268,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 269 */!]
    [!IF "contains($INMUX269, $mode_pin)"!][!//
        [!VAR "cINMUX269"="number(substring-before(substring-after($INMUX269,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 270 */!]
    [!IF "contains($INMUX270, $mode_pin)"!][!//
        [!VAR "cINMUX270"="number(substring-before(substring-after($INMUX270,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 271 */!]
    [!IF "contains($INMUX271, $mode_pin)"!][!//
        [!VAR "cINMUX271"="number(substring-before(substring-after($INMUX271,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 272 */!]
    [!IF "contains($INMUX272, $mode_pin)"!][!//
        [!VAR "cINMUX272"="number(substring-before(substring-after($INMUX272,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 273 */!]
    [!IF "contains($INMUX273, $mode_pin)"!][!//
        [!VAR "cINMUX273"="number(substring-before(substring-after($INMUX273,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!ENDLOOP!][!//
    [!ENDNOCODE!][!//
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX91, 2)"!],
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX93, 2)"!],
    (uint8)[!"num:inttohex($cINMUX94, 2)"!],
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX96, 2)"!],
    (uint8)[!"num:inttohex($cINMUX97, 2)"!],
    (uint8)[!"num:inttohex($cINMUX98, 2)"!],
    (uint8)[!"num:inttohex($cINMUX99, 2)"!],
    (uint8)[!"num:inttohex($cINMUX100, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX103, 2)"!],
    (uint8)[!"num:inttohex($cINMUX104, 2)"!],
    (uint8)[!"num:inttohex($cINMUX105, 2)"!],
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX107, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX110, 2)"!],
    (uint8)[!"num:inttohex($cINMUX111, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX114, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX120, 2)"!],
    (uint8)[!"num:inttohex($cINMUX121, 2)"!],
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX123, 2)"!],
    (uint8)[!"num:inttohex($cINMUX124, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX131, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX134, 2)"!],
    (uint8)[!"num:inttohex($cINMUX135, 2)"!],
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX137, 2)"!],
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX139, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX142, 2)"!],
    (uint8)[!"num:inttohex($cINMUX143, 2)"!],
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX145, 2)"!],
    (uint8)[!"num:inttohex($cINMUX146, 2)"!],
    (uint8)[!"num:inttohex($cINMUX147, 2)"!],
    (uint8)[!"num:inttohex($cINMUX148, 2)"!],
    (uint8)[!"num:inttohex($cINMUX149, 2)"!],
    (uint8)[!"num:inttohex($cINMUX150, 2)"!],
    (uint8)[!"num:inttohex($cINMUX151, 2)"!],
    (uint8)[!"num:inttohex($cINMUX152, 2)"!],
    (uint8)[!"num:inttohex($cINMUX153, 2)"!],
    (uint8)[!"num:inttohex($cINMUX154, 2)"!],
    (uint8)[!"num:inttohex($cINMUX155, 2)"!],
    (uint8)[!"num:inttohex($cINMUX156, 2)"!],
    (uint8)[!"num:inttohex($cINMUX157, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX160, 2)"!],
    (uint8)[!"num:inttohex($cINMUX161, 2)"!],
    (uint8)[!"num:inttohex($cINMUX162, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX169, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX173, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX182, 2)"!],
    (uint8)[!"num:inttohex($cINMUX183, 2)"!],
    (uint8)[!"num:inttohex($cINMUX184, 2)"!],
    (uint8)[!"num:inttohex($cINMUX185, 2)"!],
    (uint8)[!"num:inttohex($cINMUX186, 2)"!],
    (uint8)[!"num:inttohex($cINMUX187, 2)"!],
    (uint8)[!"num:inttohex($cINMUX188, 2)"!],
    (uint8)[!"num:inttohex($cINMUX189, 2)"!],
    (uint8)[!"num:inttohex($cINMUX190, 2)"!],
    (uint8)[!"num:inttohex($cINMUX191, 2)"!],
    (uint8)[!"num:inttohex($cINMUX192, 2)"!],
    (uint8)[!"num:inttohex($cINMUX193, 2)"!],
    (uint8)[!"num:inttohex($cINMUX194, 2)"!],
    (uint8)[!"num:inttohex($cINMUX195, 2)"!],
    (uint8)[!"num:inttohex($cINMUX196, 2)"!],
    (uint8)[!"num:inttohex($cINMUX197, 2)"!],
    (uint8)[!"num:inttohex($cINMUX198, 2)"!],
    (uint8)[!"num:inttohex($cINMUX199, 2)"!],
    (uint8)[!"num:inttohex($cINMUX200, 2)"!],
    (uint8)[!"num:inttohex($cINMUX201, 2)"!],
    (uint8)[!"num:inttohex($cINMUX202, 2)"!],
    (uint8)[!"num:inttohex($cINMUX203, 2)"!],
    (uint8)[!"num:inttohex($cINMUX204, 2)"!],
    (uint8)[!"num:inttohex($cINMUX205, 2)"!],
    (uint8)[!"num:inttohex($cINMUX206, 2)"!],
    (uint8)[!"num:inttohex($cINMUX207, 2)"!],
    (uint8)[!"num:inttohex($cINMUX208, 2)"!],
    (uint8)[!"num:inttohex($cINMUX209, 2)"!],
    (uint8)[!"num:inttohex($cINMUX210, 2)"!],
    (uint8)[!"num:inttohex($cINMUX211, 2)"!],
    (uint8)[!"num:inttohex($cINMUX212, 2)"!],
    (uint8)[!"num:inttohex($cINMUX213, 2)"!],
    (uint8)[!"num:inttohex($cINMUX214, 2)"!],
    (uint8)[!"num:inttohex($cINMUX215, 2)"!],
    (uint8)[!"num:inttohex($cINMUX216, 2)"!],
    (uint8)[!"num:inttohex($cINMUX217, 2)"!],
    (uint8)[!"num:inttohex($cINMUX218, 2)"!],
    (uint8)[!"num:inttohex($cINMUX219, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX237, 2)"!],
    (uint8)[!"num:inttohex($cINMUX238, 2)"!],
    (uint8)[!"num:inttohex($cINMUX239, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX242, 2)"!],
    (uint8)[!"num:inttohex($cINMUX243, 2)"!],
    (uint8)[!"num:inttohex($cINMUX244, 2)"!],
    (uint8)[!"num:inttohex($cINMUX245, 2)"!],
    (uint8)[!"num:inttohex($cINMUX246, 2)"!],
    (uint8)[!"num:inttohex($cINMUX247, 2)"!],
    (uint8)[!"num:inttohex($cINMUX248, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX259, 2)"!],
    (uint8)[!"num:inttohex($cINMUX260, 2)"!],
    (uint8)[!"num:inttohex($cINMUX261, 2)"!],
    (uint8)[!"num:inttohex($cINMUX262, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX265, 2)"!],
    (uint8)[!"num:inttohex($cINMUX266, 2)"!],
    (uint8)[!"num:inttohex($cINMUX267, 2)"!],
    (uint8)[!"num:inttohex($cINMUX268, 2)"!],
    (uint8)[!"num:inttohex($cINMUX269, 2)"!],
    (uint8)[!"num:inttohex($cINMUX270, 2)"!],
    (uint8)[!"num:inttohex($cINMUX271, 2)"!],
    (uint8)[!"num:inttohex($cINMUX272, 2)"!],
    (uint8)[!"num:inttohex($cINMUX273, 2)"!]
[!ELSEIF "((ecu:get('Port.Derivative'))='S32V')"!][!//
    [!NOCODE!][!//
    [!LOOP "PortContainer/*"!][!//
    [!LOOP "PortPin/*"!][!//
    [!VAR "mode_pin"="concat('MSCR_ON_', ./PortPinSiul2Instance, '_IMCR_ON_', ecu:list('Port.Siul2Instances')[num:i($siul2Instance)], '_PORT',number(./PortPinPcr), '_', ./PortPinMode,';')"!][!//
    [!/* INMUX 0 */!]
    [!IF "contains($INMUX0, $mode_pin)"!][!//
        [!VAR "cINMUX0"="number(substring-before(substring-after($INMUX0,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 1 */!]
    [!IF "contains($INMUX1, $mode_pin)"!][!//
        [!VAR "cINMUX1"="number(substring-before(substring-after($INMUX1,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 2 */!]
    [!IF "contains($INMUX2, $mode_pin)"!][!//
        [!VAR "cINMUX2"="number(substring-before(substring-after($INMUX2,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 3 */!]
    [!IF "contains($INMUX3, $mode_pin)"!][!//
        [!VAR "cINMUX3"="number(substring-before(substring-after($INMUX3,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 4 */!]
    [!IF "contains($INMUX4, $mode_pin)"!][!//
        [!VAR "cINMUX4"="number(substring-before(substring-after($INMUX4,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 5 */!]
    [!IF "contains($INMUX5, $mode_pin)"!][!//
        [!VAR "cINMUX5"="number(substring-before(substring-after($INMUX5,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 6 */!]
    [!IF "contains($INMUX6, $mode_pin)"!][!//
        [!VAR "cINMUX6"="number(substring-before(substring-after($INMUX6,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 7 */!]
    [!IF "contains($INMUX7, $mode_pin)"!][!//
        [!VAR "cINMUX7"="number(substring-before(substring-after($INMUX7,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 8 */!]
    [!IF "contains($INMUX8, $mode_pin)"!][!//
        [!VAR "cINMUX8"="number(substring-before(substring-after($INMUX8,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 9 */!]
    [!IF "contains($INMUX9, $mode_pin)"!][!//
        [!VAR "cINMUX9"="number(substring-before(substring-after($INMUX9,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 10 */!]
    [!IF "contains($INMUX10, $mode_pin)"!][!//
        [!VAR "cINMUX10"="number(substring-before(substring-after($INMUX10,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 11 */!]
    [!IF "contains($INMUX11, $mode_pin)"!][!//
        [!VAR "cINMUX11"="number(substring-before(substring-after($INMUX11,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 12 */!]
    [!IF "contains($INMUX12, $mode_pin)"!][!//
        [!VAR "cINMUX12"="number(substring-before(substring-after($INMUX12,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 13 */!]
    [!IF "contains($INMUX13, $mode_pin)"!][!//
        [!VAR "cINMUX13"="number(substring-before(substring-after($INMUX13,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 14 */!]
    [!IF "contains($INMUX14, $mode_pin)"!][!//
        [!VAR "cINMUX14"="number(substring-before(substring-after($INMUX14,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 15 */!]
    [!IF "contains($INMUX15, $mode_pin)"!][!//
        [!VAR "cINMUX15"="number(substring-before(substring-after($INMUX15,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 16 */!]
    [!IF "contains($INMUX16, $mode_pin)"!][!//
        [!VAR "cINMUX16"="number(substring-before(substring-after($INMUX16,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 17 */!]
    [!IF "contains($INMUX17, $mode_pin)"!][!//
        [!VAR "cINMUX17"="number(substring-before(substring-after($INMUX17,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 18 */!]
    [!IF "contains($INMUX18, $mode_pin)"!][!//
        [!VAR "cINMUX18"="number(substring-before(substring-after($INMUX18,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 19 */!]
    [!IF "contains($INMUX19, $mode_pin)"!][!//
        [!VAR "cINMUX19"="number(substring-before(substring-after($INMUX19,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 20 */!]
    [!IF "contains($INMUX20, $mode_pin)"!][!//
        [!VAR "cINMUX20"="number(substring-before(substring-after($INMUX20,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 21 */!]
    [!IF "contains($INMUX21, $mode_pin)"!][!//
        [!VAR "cINMUX21"="number(substring-before(substring-after($INMUX21,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 22 */!]
    [!IF "contains($INMUX22, $mode_pin)"!][!//
        [!VAR "cINMUX22"="number(substring-before(substring-after($INMUX22,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 23 */!]
    [!IF "contains($INMUX23, $mode_pin)"!][!//
        [!VAR "cINMUX23"="number(substring-before(substring-after($INMUX23,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 24 */!]
    [!IF "contains($INMUX24, $mode_pin)"!][!//
        [!VAR "cINMUX24"="number(substring-before(substring-after($INMUX24,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 25 */!]
    [!IF "contains($INMUX25, $mode_pin)"!][!//
        [!VAR "cINMUX25"="number(substring-before(substring-after($INMUX25,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 26 */!]
    [!IF "contains($INMUX26, $mode_pin)"!][!//
        [!VAR "cINMUX26"="number(substring-before(substring-after($INMUX26,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 27 */!]
    [!IF "contains($INMUX27, $mode_pin)"!][!//
        [!VAR "cINMUX27"="number(substring-before(substring-after($INMUX27,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 28 */!]
    [!IF "contains($INMUX28, $mode_pin)"!][!//
        [!VAR "cINMUX28"="number(substring-before(substring-after($INMUX28,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 29 */!]
    [!IF "contains($INMUX29, $mode_pin)"!][!//
        [!VAR "cINMUX29"="number(substring-before(substring-after($INMUX29,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 30 */!]
    [!IF "contains($INMUX30, $mode_pin)"!][!//
        [!VAR "cINMUX30"="number(substring-before(substring-after($INMUX30,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 31 */!]
    [!IF "contains($INMUX31, $mode_pin)"!][!//
        [!VAR "cINMUX31"="number(substring-before(substring-after($INMUX31,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 32 */!]
    [!IF "contains($INMUX32, $mode_pin)"!][!//
        [!VAR "cINMUX32"="number(substring-before(substring-after($INMUX32,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 33 */!]
    [!IF "contains($INMUX33, $mode_pin)"!][!//
        [!VAR "cINMUX33"="number(substring-before(substring-after($INMUX33,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 34 */!]
    [!IF "contains($INMUX34, $mode_pin)"!][!//
        [!VAR "cINMUX34"="number(substring-before(substring-after($INMUX34,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 35 */!]
    [!IF "contains($INMUX35, $mode_pin)"!][!//
        [!VAR "cINMUX35"="number(substring-before(substring-after($INMUX35,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 36 */!]
    [!IF "contains($INMUX36, $mode_pin)"!][!//
        [!VAR "cINMUX36"="number(substring-before(substring-after($INMUX36,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 37 */!]
    [!IF "contains($INMUX37, $mode_pin)"!][!//
        [!VAR "cINMUX37"="number(substring-before(substring-after($INMUX37,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 38 */!]
    [!IF "contains($INMUX38, $mode_pin)"!][!//
        [!VAR "cINMUX38"="number(substring-before(substring-after($INMUX38,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 39 */!]
    [!IF "contains($INMUX39, $mode_pin)"!][!//
        [!VAR "cINMUX39"="number(substring-before(substring-after($INMUX39,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 40 */!]
    [!IF "contains($INMUX40, $mode_pin)"!][!//
        [!VAR "cINMUX40"="number(substring-before(substring-after($INMUX40,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 41 */!]
    [!IF "contains($INMUX41, $mode_pin)"!][!//
        [!VAR "cINMUX41"="number(substring-before(substring-after($INMUX41,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 42 */!]
    [!IF "contains($INMUX42, $mode_pin)"!][!//
        [!VAR "cINMUX42"="number(substring-before(substring-after($INMUX42,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 43 */!]
    [!IF "contains($INMUX43, $mode_pin)"!][!//
        [!VAR "cINMUX43"="number(substring-before(substring-after($INMUX43,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 44 */!]
    [!IF "contains($INMUX44, $mode_pin)"!][!//
        [!VAR "cINMUX44"="number(substring-before(substring-after($INMUX44,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 45 */!]
    [!IF "contains($INMUX45, $mode_pin)"!][!//
        [!VAR "cINMUX45"="number(substring-before(substring-after($INMUX45,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 46 */!]
    [!IF "contains($INMUX46, $mode_pin)"!][!//
        [!VAR "cINMUX46"="number(substring-before(substring-after($INMUX46,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 47 */!]
    [!IF "contains($INMUX47, $mode_pin)"!][!//
        [!VAR "cINMUX47"="number(substring-before(substring-after($INMUX47,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 48 */!]
    [!IF "contains($INMUX48, $mode_pin)"!][!//
        [!VAR "cINMUX48"="number(substring-before(substring-after($INMUX48,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 49 */!]
    [!IF "contains($INMUX49, $mode_pin)"!][!//
        [!VAR "cINMUX49"="number(substring-before(substring-after($INMUX49,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 50 */!]
    [!IF "contains($INMUX50, $mode_pin)"!][!//
        [!VAR "cINMUX50"="number(substring-before(substring-after($INMUX50,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 51 */!]
    [!IF "contains($INMUX51, $mode_pin)"!][!//
        [!VAR "cINMUX51"="number(substring-before(substring-after($INMUX51,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 52 */!]
    [!IF "contains($INMUX52, $mode_pin)"!][!//
        [!VAR "cINMUX52"="number(substring-before(substring-after($INMUX52,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 53 */!]
    [!IF "contains($INMUX53, $mode_pin)"!][!//
        [!VAR "cINMUX53"="number(substring-before(substring-after($INMUX53,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 54 */!]
    [!IF "contains($INMUX54, $mode_pin)"!][!//
        [!VAR "cINMUX54"="number(substring-before(substring-after($INMUX54,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 55 */!]
    [!IF "contains($INMUX55, $mode_pin)"!][!//
        [!VAR "cINMUX55"="number(substring-before(substring-after($INMUX55,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 56 */!]
    [!IF "contains($INMUX56, $mode_pin)"!][!//
        [!VAR "cINMUX56"="number(substring-before(substring-after($INMUX56,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 57 */!]
    [!IF "contains($INMUX57, $mode_pin)"!][!//
        [!VAR "cINMUX57"="number(substring-before(substring-after($INMUX57,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 58 */!]
    [!IF "contains($INMUX58, $mode_pin)"!][!//
        [!VAR "cINMUX58"="number(substring-before(substring-after($INMUX58,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 59 */!]
    [!IF "contains($INMUX59, $mode_pin)"!][!//
        [!VAR "cINMUX59"="number(substring-before(substring-after($INMUX59,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 60 */!]
    [!IF "contains($INMUX60, $mode_pin)"!][!//
        [!VAR "cINMUX60"="number(substring-before(substring-after($INMUX60,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 61 */!]
    [!IF "contains($INMUX61, $mode_pin)"!][!//
        [!VAR "cINMUX61"="number(substring-before(substring-after($INMUX61,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 62 */!]
    [!IF "contains($INMUX62, $mode_pin)"!][!//
        [!VAR "cINMUX62"="number(substring-before(substring-after($INMUX62,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 63 */!]
    [!IF "contains($INMUX63, $mode_pin)"!][!//
        [!VAR "cINMUX63"="number(substring-before(substring-after($INMUX63,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 64 */!]
    [!IF "contains($INMUX64, $mode_pin)"!][!//
        [!VAR "cINMUX64"="number(substring-before(substring-after($INMUX64,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 65 */!]
    [!IF "contains($INMUX65, $mode_pin)"!][!//
        [!VAR "cINMUX65"="number(substring-before(substring-after($INMUX65,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 66 */!]
    [!IF "contains($INMUX66, $mode_pin)"!][!//
        [!VAR "cINMUX66"="number(substring-before(substring-after($INMUX66,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 67 */!]
    [!IF "contains($INMUX67, $mode_pin)"!][!//
        [!VAR "cINMUX67"="number(substring-before(substring-after($INMUX67,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 68 */!]
    [!IF "contains($INMUX68, $mode_pin)"!][!//
        [!VAR "cINMUX68"="number(substring-before(substring-after($INMUX68,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 69 */!]
    [!IF "contains($INMUX69, $mode_pin)"!][!//
        [!VAR "cINMUX69"="number(substring-before(substring-after($INMUX69,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 70 */!]
    [!IF "contains($INMUX70, $mode_pin)"!][!//
        [!VAR "cINMUX70"="number(substring-before(substring-after($INMUX70,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 71 */!]
    [!IF "contains($INMUX71, $mode_pin)"!][!//
        [!VAR "cINMUX71"="number(substring-before(substring-after($INMUX71,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 72 */!]
    [!IF "contains($INMUX72, $mode_pin)"!][!//
        [!VAR "cINMUX72"="number(substring-before(substring-after($INMUX72,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 73 */!]
    [!IF "contains($INMUX73, $mode_pin)"!][!//
        [!VAR "cINMUX73"="number(substring-before(substring-after($INMUX73,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 74 */!]
    [!IF "contains($INMUX74, $mode_pin)"!][!//
        [!VAR "cINMUX74"="number(substring-before(substring-after($INMUX74,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 75 */!]
    [!IF "contains($INMUX75, $mode_pin)"!][!//
        [!VAR "cINMUX75"="number(substring-before(substring-after($INMUX75,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 76 */!]
    [!IF "contains($INMUX76, $mode_pin)"!][!//
        [!VAR "cINMUX76"="number(substring-before(substring-after($INMUX76,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 77 */!]
    [!IF "contains($INMUX77, $mode_pin)"!][!//
        [!VAR "cINMUX77"="number(substring-before(substring-after($INMUX77,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 78 */!]
    [!IF "contains($INMUX78, $mode_pin)"!][!//
        [!VAR "cINMUX78"="number(substring-before(substring-after($INMUX78,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 79 */!]
    [!IF "contains($INMUX79, $mode_pin)"!][!//
        [!VAR "cINMUX79"="number(substring-before(substring-after($INMUX79,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 80 */!]
    [!IF "contains($INMUX80, $mode_pin)"!][!//
        [!VAR "cINMUX80"="number(substring-before(substring-after($INMUX80,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 81 */!]
    [!IF "contains($INMUX81, $mode_pin)"!][!//
        [!VAR "cINMUX81"="number(substring-before(substring-after($INMUX81,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 82 */!]
    [!IF "contains($INMUX82, $mode_pin)"!][!//
        [!VAR "cINMUX82"="number(substring-before(substring-after($INMUX82,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 83 */!]
    [!IF "contains($INMUX83, $mode_pin)"!][!//
        [!VAR "cINMUX83"="number(substring-before(substring-after($INMUX83,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 84 */!]
    [!IF "contains($INMUX84, $mode_pin)"!][!//
        [!VAR "cINMUX84"="number(substring-before(substring-after($INMUX84,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 85 */!]
    [!IF "contains($INMUX85, $mode_pin)"!][!//
        [!VAR "cINMUX85"="number(substring-before(substring-after($INMUX85,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 86 */!]
    [!IF "contains($INMUX86, $mode_pin)"!][!//
        [!VAR "cINMUX86"="number(substring-before(substring-after($INMUX86,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 87 */!]
    [!IF "contains($INMUX87, $mode_pin)"!][!//
        [!VAR "cINMUX87"="number(substring-before(substring-after($INMUX87,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 88 */!]
    [!IF "contains($INMUX88, $mode_pin)"!][!//
        [!VAR "cINMUX88"="number(substring-before(substring-after($INMUX88,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 89 */!]
    [!IF "contains($INMUX89, $mode_pin)"!][!//
        [!VAR "cINMUX89"="number(substring-before(substring-after($INMUX89,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 90 */!]
    [!IF "contains($INMUX90, $mode_pin)"!][!//
        [!VAR "cINMUX90"="number(substring-before(substring-after($INMUX90,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 91 */!]
    [!IF "contains($INMUX91, $mode_pin)"!][!//
        [!VAR "cINMUX91"="number(substring-before(substring-after($INMUX91,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 92 */!]
    [!IF "contains($INMUX92, $mode_pin)"!][!//
        [!VAR "cINMUX92"="number(substring-before(substring-after($INMUX92,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 93 */!]
    [!IF "contains($INMUX93, $mode_pin)"!][!//
        [!VAR "cINMUX93"="number(substring-before(substring-after($INMUX93,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 94 */!]
    [!IF "contains($INMUX94, $mode_pin)"!][!//
        [!VAR "cINMUX94"="number(substring-before(substring-after($INMUX94,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 95 */!]
    [!IF "contains($INMUX95, $mode_pin)"!][!//
        [!VAR "cINMUX95"="number(substring-before(substring-after($INMUX95,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 96 */!]
    [!IF "contains($INMUX96, $mode_pin)"!][!//
        [!VAR "cINMUX96"="number(substring-before(substring-after($INMUX96,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 97 */!]
    [!IF "contains($INMUX97, $mode_pin)"!][!//
        [!VAR "cINMUX97"="number(substring-before(substring-after($INMUX97,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 98 */!]
    [!IF "contains($INMUX98, $mode_pin)"!][!//
        [!VAR "cINMUX98"="number(substring-before(substring-after($INMUX98,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 99 */!]
    [!IF "contains($INMUX99, $mode_pin)"!][!//
        [!VAR "cINMUX99"="number(substring-before(substring-after($INMUX99,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 100 */!]
    [!IF "contains($INMUX100, $mode_pin)"!][!//
        [!VAR "cINMUX100"="number(substring-before(substring-after($INMUX100,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 101 */!]
    [!IF "contains($INMUX101, $mode_pin)"!][!//
        [!VAR "cINMUX101"="number(substring-before(substring-after($INMUX101,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 102 */!]
    [!IF "contains($INMUX102, $mode_pin)"!][!//
        [!VAR "cINMUX102"="number(substring-before(substring-after($INMUX102,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 103 */!]
    [!IF "contains($INMUX103, $mode_pin)"!][!//
        [!VAR "cINMUX103"="number(substring-before(substring-after($INMUX103,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 104 */!]
    [!IF "contains($INMUX104, $mode_pin)"!][!//
        [!VAR "cINMUX104"="number(substring-before(substring-after($INMUX104,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 105 */!]
    [!IF "contains($INMUX105, $mode_pin)"!][!//
        [!VAR "cINMUX105"="number(substring-before(substring-after($INMUX105,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 106 */!]
    [!IF "contains($INMUX106, $mode_pin)"!][!//
        [!VAR "cINMUX106"="number(substring-before(substring-after($INMUX106,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 107 */!]
    [!IF "contains($INMUX107, $mode_pin)"!][!//
        [!VAR "cINMUX107"="number(substring-before(substring-after($INMUX107,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 108 */!]
    [!IF "contains($INMUX108, $mode_pin)"!][!//
        [!VAR "cINMUX108"="number(substring-before(substring-after($INMUX108,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 109 */!]
    [!IF "contains($INMUX109, $mode_pin)"!][!//
        [!VAR "cINMUX109"="number(substring-before(substring-after($INMUX109,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 110 */!]
    [!IF "contains($INMUX110, $mode_pin)"!][!//
        [!VAR "cINMUX110"="number(substring-before(substring-after($INMUX110,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 111 */!]
    [!IF "contains($INMUX111, $mode_pin)"!][!//
        [!VAR "cINMUX111"="number(substring-before(substring-after($INMUX111,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 112 */!]
    [!IF "contains($INMUX112, $mode_pin)"!][!//
        [!VAR "cINMUX112"="number(substring-before(substring-after($INMUX112,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 113 */!]
    [!IF "contains($INMUX113, $mode_pin)"!][!//
        [!VAR "cINMUX113"="number(substring-before(substring-after($INMUX113,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 114 */!]
    [!IF "contains($INMUX114, $mode_pin)"!][!//
        [!VAR "cINMUX114"="number(substring-before(substring-after($INMUX114,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 115 */!]
    [!IF "contains($INMUX115, $mode_pin)"!][!//
        [!VAR "cINMUX115"="number(substring-before(substring-after($INMUX115,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 116 */!]
    [!IF "contains($INMUX116, $mode_pin)"!][!//
        [!VAR "cINMUX116"="number(substring-before(substring-after($INMUX116,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 117 */!]
    [!IF "contains($INMUX117, $mode_pin)"!][!//
        [!VAR "cINMUX117"="number(substring-before(substring-after($INMUX117,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 118 */!]
    [!IF "contains($INMUX118, $mode_pin)"!][!//
        [!VAR "cINMUX118"="number(substring-before(substring-after($INMUX118,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 119 */!]
    [!IF "contains($INMUX119, $mode_pin)"!][!//
        [!VAR "cINMUX119"="number(substring-before(substring-after($INMUX119,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 120 */!]
    [!IF "contains($INMUX120, $mode_pin)"!][!//
        [!VAR "cINMUX120"="number(substring-before(substring-after($INMUX120,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 121 */!]
    [!IF "contains($INMUX121, $mode_pin)"!][!//
        [!VAR "cINMUX121"="number(substring-before(substring-after($INMUX121,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 122 */!]
    [!IF "contains($INMUX122, $mode_pin)"!][!//
        [!VAR "cINMUX122"="number(substring-before(substring-after($INMUX122,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 123 */!]
    [!IF "contains($INMUX123, $mode_pin)"!][!//
        [!VAR "cINMUX123"="number(substring-before(substring-after($INMUX123,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 124 */!]
    [!IF "contains($INMUX124, $mode_pin)"!][!//
        [!VAR "cINMUX124"="number(substring-before(substring-after($INMUX124,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 125 */!]
    [!IF "contains($INMUX125, $mode_pin)"!][!//
        [!VAR "cINMUX125"="number(substring-before(substring-after($INMUX125,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 126 */!]
    [!IF "contains($INMUX126, $mode_pin)"!][!//
        [!VAR "cINMUX126"="number(substring-before(substring-after($INMUX126,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 127 */!]
    [!IF "contains($INMUX127, $mode_pin)"!][!//
        [!VAR "cINMUX127"="number(substring-before(substring-after($INMUX127,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 128 */!]
    [!IF "contains($INMUX128, $mode_pin)"!][!//
        [!VAR "cINMUX128"="number(substring-before(substring-after($INMUX128,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 129 */!]
    [!IF "contains($INMUX129, $mode_pin)"!][!//
        [!VAR "cINMUX129"="number(substring-before(substring-after($INMUX129,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 130 */!]
    [!IF "contains($INMUX130, $mode_pin)"!][!//
        [!VAR "cINMUX130"="number(substring-before(substring-after($INMUX130,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 131 */!]
    [!IF "contains($INMUX131, $mode_pin)"!][!//
        [!VAR "cINMUX131"="number(substring-before(substring-after($INMUX131,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 132 */!]
    [!IF "contains($INMUX132, $mode_pin)"!][!//
        [!VAR "cINMUX132"="number(substring-before(substring-after($INMUX132,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 133 */!]
    [!IF "contains($INMUX133, $mode_pin)"!][!//
        [!VAR "cINMUX133"="number(substring-before(substring-after($INMUX133,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 134 */!]
    [!IF "contains($INMUX134, $mode_pin)"!][!//
        [!VAR "cINMUX134"="number(substring-before(substring-after($INMUX134,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 135 */!]
    [!IF "contains($INMUX135, $mode_pin)"!][!//
        [!VAR "cINMUX135"="number(substring-before(substring-after($INMUX135,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 136 */!]
    [!IF "contains($INMUX136, $mode_pin)"!][!//
        [!VAR "cINMUX136"="number(substring-before(substring-after($INMUX136,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 137 */!]
    [!IF "contains($INMUX137, $mode_pin)"!][!//
        [!VAR "cINMUX137"="number(substring-before(substring-after($INMUX137,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 138 */!]
    [!IF "contains($INMUX138, $mode_pin)"!][!//
        [!VAR "cINMUX138"="number(substring-before(substring-after($INMUX138,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 139 */!]
    [!IF "contains($INMUX139, $mode_pin)"!][!//
        [!VAR "cINMUX139"="number(substring-before(substring-after($INMUX139,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 140 */!]
    [!IF "contains($INMUX140, $mode_pin)"!][!//
        [!VAR "cINMUX140"="number(substring-before(substring-after($INMUX140,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 141 */!]
    [!IF "contains($INMUX141, $mode_pin)"!][!//
        [!VAR "cINMUX141"="number(substring-before(substring-after($INMUX141,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 142 */!]
    [!IF "contains($INMUX142, $mode_pin)"!][!//
        [!VAR "cINMUX142"="number(substring-before(substring-after($INMUX142,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 143 */!]
    [!IF "contains($INMUX143, $mode_pin)"!][!//
        [!VAR "cINMUX143"="number(substring-before(substring-after($INMUX143,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!/* INMUX 144 */!]
    [!IF "contains($INMUX144, $mode_pin)"!][!//
        [!VAR "cINMUX144"="number(substring-before(substring-after($INMUX144,$mode_pin),':'))"!][!//
    [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!ENDLOOP!][!//
    [!ENDNOCODE!][!//
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX49, 2)"!],
    (uint8)[!"num:inttohex($cINMUX50, 2)"!],
    (uint8)[!"num:inttohex($cINMUX51, 2)"!],
    (uint8)[!"num:inttohex($cINMUX52, 2)"!],
    (uint8)[!"num:inttohex($cINMUX53, 2)"!],
    (uint8)[!"num:inttohex($cINMUX54, 2)"!],
    (uint8)[!"num:inttohex($cINMUX55, 2)"!],
    (uint8)[!"num:inttohex($cINMUX56, 2)"!],
    (uint8)[!"num:inttohex($cINMUX57, 2)"!],
    (uint8)[!"num:inttohex($cINMUX58, 2)"!],
    (uint8)[!"num:inttohex($cINMUX59, 2)"!],
    (uint8)[!"num:inttohex($cINMUX60, 2)"!],
    (uint8)[!"num:inttohex($cINMUX61, 2)"!],
    (uint8)[!"num:inttohex($cINMUX62, 2)"!],
    (uint8)[!"num:inttohex($cINMUX63, 2)"!],
    (uint8)[!"num:inttohex($cINMUX64, 2)"!],
    (uint8)[!"num:inttohex($cINMUX65, 2)"!],
    (uint8)[!"num:inttohex($cINMUX66, 2)"!],
    (uint8)[!"num:inttohex($cINMUX67, 2)"!],
    (uint8)[!"num:inttohex($cINMUX68, 2)"!],
    (uint8)[!"num:inttohex($cINMUX69, 2)"!],
    (uint8)[!"num:inttohex($cINMUX70, 2)"!],
    (uint8)[!"num:inttohex($cINMUX71, 2)"!],
    (uint8)[!"num:inttohex($cINMUX72, 2)"!],
    (uint8)[!"num:inttohex($cINMUX73, 2)"!],
    (uint8)[!"num:inttohex($cINMUX74, 2)"!],
    (uint8)[!"num:inttohex($cINMUX75, 2)"!],
    (uint8)[!"num:inttohex($cINMUX76, 2)"!],
    (uint8)[!"num:inttohex($cINMUX77, 2)"!],
    (uint8)[!"num:inttohex($cINMUX78, 2)"!],
    (uint8)[!"num:inttohex($cINMUX79, 2)"!],
    (uint8)[!"num:inttohex($cINMUX80, 2)"!],
    (uint8)[!"num:inttohex($cINMUX81, 2)"!],
    (uint8)[!"num:inttohex($cINMUX82, 2)"!],
    (uint8)[!"num:inttohex($cINMUX83, 2)"!],
    (uint8)[!"num:inttohex($cINMUX84, 2)"!],
    (uint8)[!"num:inttohex($cINMUX85, 2)"!],
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)[!"num:inttohex($cINMUX88, 2)"!],
    (uint8)[!"num:inttohex($cINMUX89, 2)"!],
    (uint8)[!"num:inttohex($cINMUX90, 2)"!],
    (uint8)[!"num:inttohex($cINMUX91, 2)"!],
    (uint8)[!"num:inttohex($cINMUX92, 2)"!],
    (uint8)[!"num:inttohex($cINMUX93, 2)"!],
    (uint8)[!"num:inttohex($cINMUX94, 2)"!],
    (uint8)[!"num:inttohex($cINMUX95, 2)"!],
    (uint8)[!"num:inttohex($cINMUX96, 2)"!],
    (uint8)[!"num:inttohex($cINMUX97, 2)"!],
    (uint8)[!"num:inttohex($cINMUX98, 2)"!],
    (uint8)[!"num:inttohex($cINMUX99, 2)"!],
    (uint8)[!"num:inttohex($cINMUX100, 2)"!],
    (uint8)[!"num:inttohex($cINMUX101, 2)"!],
    (uint8)[!"num:inttohex($cINMUX102, 2)"!],
    (uint8)[!"num:inttohex($cINMUX103, 2)"!],
    (uint8)[!"num:inttohex($cINMUX104, 2)"!],
    (uint8)[!"num:inttohex($cINMUX105, 2)"!],
    (uint8)[!"num:inttohex($cINMUX106, 2)"!],
    (uint8)[!"num:inttohex($cINMUX107, 2)"!],
    (uint8)[!"num:inttohex($cINMUX108, 2)"!],
    (uint8)[!"num:inttohex($cINMUX109, 2)"!],
    (uint8)[!"num:inttohex($cINMUX110, 2)"!],
    (uint8)[!"num:inttohex($cINMUX111, 2)"!],
    (uint8)[!"num:inttohex($cINMUX112, 2)"!],
    (uint8)[!"num:inttohex($cINMUX113, 2)"!],
    (uint8)[!"num:inttohex($cINMUX114, 2)"!],
    (uint8)[!"num:inttohex($cINMUX115, 2)"!],
    (uint8)[!"num:inttohex($cINMUX116, 2)"!],
    (uint8)[!"num:inttohex($cINMUX117, 2)"!],
    (uint8)[!"num:inttohex($cINMUX118, 2)"!],
    (uint8)[!"num:inttohex($cINMUX119, 2)"!],
    (uint8)[!"num:inttohex($cINMUX120, 2)"!],
    (uint8)[!"num:inttohex($cINMUX121, 2)"!],
    (uint8)[!"num:inttohex($cINMUX122, 2)"!],
    (uint8)[!"num:inttohex($cINMUX123, 2)"!],
    (uint8)[!"num:inttohex($cINMUX124, 2)"!],
    (uint8)[!"num:inttohex($cINMUX125, 2)"!],
    (uint8)[!"num:inttohex($cINMUX126, 2)"!],
    (uint8)[!"num:inttohex($cINMUX127, 2)"!],
    (uint8)[!"num:inttohex($cINMUX128, 2)"!],
    (uint8)[!"num:inttohex($cINMUX129, 2)"!],
    (uint8)[!"num:inttohex($cINMUX130, 2)"!],
    (uint8)[!"num:inttohex($cINMUX131, 2)"!],
    (uint8)[!"num:inttohex($cINMUX132, 2)"!],
    (uint8)[!"num:inttohex($cINMUX133, 2)"!],
    (uint8)[!"num:inttohex($cINMUX134, 2)"!],
    (uint8)[!"num:inttohex($cINMUX135, 2)"!],
    (uint8)[!"num:inttohex($cINMUX136, 2)"!],
    (uint8)[!"num:inttohex($cINMUX137, 2)"!],
    (uint8)[!"num:inttohex($cINMUX138, 2)"!],
    (uint8)[!"num:inttohex($cINMUX139, 2)"!],
    (uint8)[!"num:inttohex($cINMUX140, 2)"!],
    (uint8)[!"num:inttohex($cINMUX141, 2)"!],
    (uint8)[!"num:inttohex($cINMUX142, 2)"!],
    (uint8)[!"num:inttohex($cINMUX143, 2)"!],
    (uint8)[!"num:inttohex($cINMUX144, 2)"!]
[!ENDIF!][!//
};
[!ENDIF!][!//

[!ENDSELECT!][!//

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/*=================================================================================================
*                                      LOCAL VARIABLES
=================================================================================================*/

/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/
#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

[!/*****************************************************************************/!][!//
[!SELECT "PortConfigSet"!][!//
[!VAR "counter"="0"!][!//
/**
* @brief This table contains all the Configured Port Pin parameters and the
*        number of Port Pins configured by the tool for the post-build mode
*/
[!INDENT "0"!][!//
[!/* VariantPreCompile/LinkTime and at most 1 configured variant */!][!//
[!IF "((../IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and (variant:size()<=1))"!][!//
    const Port_ConfigType Port_Config =
[!/* VariantPostBuild or more than 1 configured variant */!][!//
[!ELSE!][!//
    [!/* If ECUC exists or there is at least one  */!][!//
    [!IF "variant:size()>0"!][!//
        const Port_ConfigType Port_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
    [!/* VariantPostBuild with no variants or no ECUC configured*/!][!//
    [!ELSE!][!//
        const Port_ConfigType Port_Config =
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDINDENT!][!//
{
    PORT_MAX_CONFIGURED_PADS_U16,
    PORT_MAX_UNUSED_PADS_U16,
    {
[!NOCODE!][!//
    [!VAR "counter"="0"!][!//
    [!FOR "LoopCounter" = "1" TO "num:i(count(ecu:list('Port.Siul2Instances')))"!][!//
        [!VAR "CurInstanceName"="ecu:list('Port.Siul2Instances')[num:i($LoopCounter)]"!][!//
        [!IF "$counter=0"!][!//
[!CODE!][!//
        PORT_[!"$CurInstanceName"!]_NUM_IMCRS_U16[!//
[!ENDCODE!][!//
        [!ELSE!][!//
[!CODE!][!//
,
        PORT_[!"$CurInstanceName"!]_NUM_IMCRS_U16[!//
[!ENDCODE!][!//
        [!ENDIF!][!//
        [!VAR "counter"= "$counter+1"!][!//
    [!ENDFOR!][!//
[!ENDNOCODE!]
    },
#if (PORT_MAX_UNUSED_PADS_U16 != 0U)
    Port_aUnusedPads[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
#else
    NULL_PTR,
#endif
    &Port_UnusedPinConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    Port_aUsedPinConfigs[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    {
[!NOCODE!][!//
    [!VAR "counter"="0"!][!//
    [!FOR "LoopCounter" = "1" TO "num:i(count(ecu:list('Port.Siul2Instances')))"!][!//
        [!VAR "CurInstanceName"="ecu:list('Port.Siul2Instances')[num:i($LoopCounter)]"!][!//
        [!IF "$counter=0"!][!//
[!CODE!][!//
        Port_a[!"$CurInstanceName"!]_ImcrInitConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!//
[!ENDCODE!][!//
        [!ELSE!][!//
[!CODE!][!//
,
        Port_a[!"$CurInstanceName"!]_ImcrInitConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!//
[!ENDCODE!][!//
        [!ENDIF!][!//
        [!VAR "counter"= "$counter+1"!][!//
    [!ENDFOR!][!//
[!ENDNOCODE!]
    },
    au32Port_PinToPartitionMap[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    au8Port_PartitionList[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    g_pin_mux_InitConfigArr[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
};
[!ENDSELECT!][!//

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/*=================================================================================================
*                                      GLOBAL VARIABLES
=================================================================================================*/

/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/

/*=================================================================================================
*                                       LOCAL FUNCTIONS
=================================================================================================*/

/*=================================================================================================
*                                       GLOBAL FUNCTIONS
=================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

/* End of File */
[!ENDCODE!][!//
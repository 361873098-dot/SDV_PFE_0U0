[!CODE!][!//
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

/**
* @file Eep[!"$variantNameUpperCase"!]_PBcfg.c
*
* @addtogroup EEP
* @{
*/

#ifdef __cplusplus
extern "C"{
#endif

[!INDENT "0"!][!//
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Eep.h"

/* If SD Emmc IP is present on the platform */
#include "Sd_Emmc_Ip_Cfg.h"

[!IF "AutosarExt/EepDisableDemReportErrorStatus ='false'"!][!//
    #include "Dem.h"
[!ENDIF!][!//
[!ENDINDENT!][!//

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EEP[!"$variantNameUpperCase"!]_VENDOR_ID_PBCFG_C                      43
#define EEP[!"$variantNameUpperCase"!]_AR_RELEASE_MAJOR_VERSION_PBCFG_C       4
#define EEP[!"$variantNameUpperCase"!]_AR_RELEASE_MINOR_VERSION_PBCFG_C       4
#define EEP[!"$variantNameUpperCase"!]_AR_RELEASE_REVISION_VERSION_PBCFG_C    0
#define EEP[!"$variantNameUpperCase"!]_SW_MAJOR_VERSION_PBCFG_C               4
#define EEP[!"$variantNameUpperCase"!]_SW_MINOR_VERSION_PBCFG_C               0
#define EEP[!"$variantNameUpperCase"!]_SW_PATCH_VERSION_PBCFG_C               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Eep header file are of the same vendor */
#if (EEP[!"$variantNameUpperCase"!]_VENDOR_ID_PBCFG_C != EEP_VENDOR_ID)
    #error "AutoSar Version Numbers of Eep[!"$variantName"!]_PBcfg.c and Eep.h have different vendor ids"
#endif
/* Check if current file and Eep header file are of the same Autosar version */
#if ((EEP[!"$variantNameUpperCase"!]_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != EEP_AR_RELEASE_MAJOR_VERSION) || \
     (EEP[!"$variantNameUpperCase"!]_AR_RELEASE_MINOR_VERSION_PBCFG_C    != EEP_AR_RELEASE_MINOR_VERSION) || \
     (EEP[!"$variantNameUpperCase"!]_AR_RELEASE_REVISION_VERSION_PBCFG_C != EEP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Eep[!"$variantName"!]_PBcfg.c and Eep.h are different"
#endif
/* Check if current file and Eep header file are of the same Software version */
#if ((EEP[!"$variantNameUpperCase"!]_SW_MAJOR_VERSION_PBCFG_C != EEP_SW_MAJOR_VERSION) || \
     (EEP[!"$variantNameUpperCase"!]_SW_MINOR_VERSION_PBCFG_C != EEP_SW_MINOR_VERSION) || \
     (EEP[!"$variantNameUpperCase"!]_SW_PATCH_VERSION_PBCFG_C != EEP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eep[!"$variantName"!]_PBcfg.c and Eep.h are different"
#endif

/* Check if current file and Sd_Emmc_Ip_Cfg header file are of the same vendor */
#if (EEP[!"$variantNameUpperCase"!]_VENDOR_ID_PBCFG_C != SD_EMMC_VENDOR_ID_IP_CFG)
    #error "AutoSar Version Numbers of Eep[!"$variantName"!]_PBcfg.c and Sd_Emmc_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Sd_Emmc_Ip_Cfg header file are of the same Autosar version */
#if ((EEP[!"$variantNameUpperCase"!]_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != SD_EMMC_AR_RELEASE_MAJOR_VERSION_IP_CFG) || \
     (EEP[!"$variantNameUpperCase"!]_AR_RELEASE_MINOR_VERSION_PBCFG_C    != SD_EMMC_AR_RELEASE_MINOR_VERSION_IP_CFG) || \
     (EEP[!"$variantNameUpperCase"!]_AR_RELEASE_REVISION_VERSION_PBCFG_C != SD_EMMC_AR_RELEASE_REVISION_VERSION_IP_CFG) \
    )
    #error "AutoSar Version Numbers of Eep[!"$variantName"!]_PBcfg.c and Sd_Emmc_Ip_Cfg.h are different"
#endif
/* Check if current file and Sd_Emmc_Ip_Cfg header file are of the same Software version */
#if ((EEP[!"$variantNameUpperCase"!]_SW_MAJOR_VERSION_PBCFG_C != SD_EMMC_SW_MAJOR_VERSION_IP_CFG) || \
     (EEP[!"$variantNameUpperCase"!]_SW_MINOR_VERSION_PBCFG_C != SD_EMMC_SW_MINOR_VERSION_IP_CFG) || \
     (EEP[!"$variantNameUpperCase"!]_SW_PATCH_VERSION_PBCFG_C != SD_EMMC_SW_PATCH_VERSION_IP_CFG) \
    )
    #error "Software Version Numbers of Eep[!"$variantName"!]_PBcfg.c and Sd_Emmc_Ip_Cfg.h are different"
#endif

[!IF "AutosarExt/EepDisableDemReportErrorStatus ='false'"!][!//
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Dem header file are of the same Autosar version */
    #if ((EEP[!"$variantNameUpperCase"!]_AR_RELEASE_MAJOR_VERSION_PBCFG_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (EEP[!"$variantNameUpperCase"!]_AR_RELEASE_MINOR_VERSION_PBCFG_C != DEM_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Eep[!"$variantName"!]_PBcfg.c and Dem.h are different"
    #endif
#endif
[!ENDIF!][!//

[!INCLUDE "Eep_VersionCheck.m"!][!//
/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
[!NOCODE!][!//
[!VAR "EepIndex0" = "0"!][!//
[!VAR "EepIndex1" = "0"!][!//
[!VAR "EepIndex2" = "0"!][!//
[!VAR "EepIndex3" = "0"!][!//
[!VAR "EepIndex4" = "0"!][!//

[!LOOP "EepInitConfiguration"!][!//
    [!IF "node:exists(EepJobEndNotification)"!][!//
        [!VAR "EepIndex0" = "1"!][!//
    [!ENDIF!][!//
    [!IF "node:exists(EepJobErrorNotification)"!][!//
        [!VAR "EepIndex1" = "1"!][!//
    [!ENDIF!][!//

[!ENDLOOP!][!//

[!ENDNOCODE!][!//
[!IF "$EepIndex0 = '1.0' or $EepIndex1 = '1.0'"!][!//
    [!INDENT "0"!]

    #define EEP_START_SEC_CODE
     #include "Eep_MemMap.h"
    [!LOOP "text:order(text:split(normalize-space(text:join(EepInitConfiguration/EepJobEndNotification | EepInitConfiguration/EepJobErrorNotification))))"!][!//

    /* Declaration of Eep notification function ([!"."!]())*/
    extern void [!"."!]( void );

    [!ENDLOOP!][!//
    #define EEP_STOP_SEC_CODE
    #include "Eep_MemMap.h"
    [!ENDINDENT!][!//
[!ENDIF!][!//

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/
[!INDENT "0"!][!//
[!NOCODE!][!//
[!VAR "EepDemErrorEnable" = "'false'"!][!//
[!IF "AutosarExt/EepDisableDemReportErrorStatus ='false'"!][!//
    [!VAR "EepDemErrorEnable" = "'true'"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!NOCODE!][!//
[!/* *** multiple inclusion protection *** */!][!//
[!IF "not(var:defined('EEP_CFG_GENERIC_MACROS_M4'))"!][!//
    [!VAR "EEP_CFG_GENERIC_MACROS_M4"="'true'"!][!//
    [!//
    [!MACRO "EepAccCrc","EepData32"!][!//
        [!NOCODE!][!//
        [!IF "65535 < $EepData32"!][!//
            [!VAR "EepCrcReminder" = "bit:or(bit:shl($EepCrcReminder,16),bit:shr($EepData32,16))"!][!//
            [!CALL "EepCalcCrcRemainder16bit"!][!//
        [!ENDIF!][!//
        [!IF "255 < $EepData32"!][!//
            [!VAR "EepCrcReminder" = "bit:or(bit:shl($EepCrcReminder,16),bit:and($EepData32,65535))"!][!//
            [!CALL "EepCalcCrcRemainder16bit"!][!//
        [!ELSE!][!//
            [!VAR "EepCrcReminder" = "bit:or(bit:shl($EepCrcReminder,8),bit:and($EepData32,255))"!][!//
            [!CALL "EepCalcCrcRemainder8bit"!][!//
        [!ENDIF!][!//
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "EepFinishCrc"!][!//
        [!NOCODE!][!//
        [!VAR "EepCrcReminder" = "bit:shl($EepCrcReminder,16)"!][!//
        [!CALL "EepCalcCrcRemainder16bit"!][!//
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "EepCalcCrcRemainder16bit"!][!//
        [!NOCODE!][!//
        [!VAR "Rem16CrcPolynomSft" = "2282782720"!][!//
        [!VAR "Rem16LeadingOne" = "2147483648"!][!//
        [!FOR "Rem16Counter"="31" TO "16" STEP "-1"!][!//
            [!IF "bit:and($Rem16LeadingOne,$EepCrcReminder) = $Rem16LeadingOne"!][!//
                [!VAR "EepCrcReminder"="bit:xor($EepCrcReminder,$Rem16CrcPolynomSft)"!][!//
            [!ENDIF!][!//
            [!VAR "Rem16CrcPolynomSft"="bit:shr($Rem16CrcPolynomSft,1)"!][!//
            [!VAR "Rem16LeadingOne"="bit:shr($Rem16LeadingOne,1)"!][!//
        [!ENDFOR!][!//
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "EepCalcCrcRemainder8bit"!][!//
        [!NOCODE!][!//
            [!VAR "Rem8CrcPolynomSft" = "8917120"!][!//
            [!VAR "Rem8LeadingOne" = "8388608"!][!//
            [!FOR "Rem8Counter"="23" TO "16" STEP "-1"!][!//
                [!IF "bit:and($Rem8LeadingOne,$EepCrcReminder) = $Rem8LeadingOne"!][!//
                    [!VAR "EepCrcReminder"="bit:xor($EepCrcReminder,$Rem8CrcPolynomSft)"!][!//
                [!ENDIF!][!//
                [!VAR "Rem8CrcPolynomSft"="bit:shr($Rem8CrcPolynomSft,1)"!][!//
                [!VAR "Rem8LeadingOne"="bit:shr($Rem8LeadingOne,1)"!][!//
            [!ENDFOR!][!//
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "GetDemErrorValue", "DemRefPath"!][!//
        [!NOCODE!][!//
        [!VAR "DemEventIdOut" = "node:value(node:ref($DemRefPath)/DemEventId)"!]
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "GetBooleanValue", "Boolean"!][!//
        [!NOCODE!][!//
        [!IF "($Boolean) = 'true'"!]
            [!VAR "BooleanValueOut" = "1"!]
        [!ELSE!]
            [!VAR "BooleanValueOut" = "0"!]
        [!ENDIF!]
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "EepGetMemifModeValue","EepEnumName"!][!//
        [!NOCODE!][!//
        [!IF "$EepEnumName='MEMIF_MODE_SLOW'"!][!//
            [!VAR "OutMemifModeValue" = "0"!][!//
        [!ELSEIF "$EepEnumName='MEMIF_MODE_FAST'"!][!//
            [!VAR "OutMemifModeValue" = "1"!][!//
        [!ELSE!][!//
            [!VAR "OutMemifModeValue" = "4294967295"!][!//
        [!ENDIF!][!//
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "EepDemEventCfg","EepDemEventName","EepDelimiter"!][!//
        [!NOCODE!][!//
        [!VAR "DemNodeFound" = "'false'"!][!//
        [!LOOP "./EepDemEventParameterRefs/*"!][!//
            [!VAR "EepDemEventNameTemp" = "substring-before($EepDemEventName, ' ')"!][!//
            [!IF "node:name(.)=$EepDemEventNameTemp"!][!//
                [!VAR "DemNodeFound" = "'true'"!][!//
                [!IF "not(node:empty(.))"!][!//
                    [!IF "node:exists(node:ref(.))"!][!//
                        [!IF "node:refvalid(.)"!][!//
                            [!VAR "DemRefName" = "(text:split(normalize-space(node:value(.)),'/'))[last()]"!][!//
                            [!CODE!]/* [!"$EepDemEventName"!] */{(uint32)STD_ON, DemConf_DemEventParameter_[!"$DemRefName"!]}[!"$EepDelimiter"!][!CR!][!ENDCODE!][!//
                        [!ELSE!][!//
                            [!ERROR "Invalid reference for $EepDemEventName"!][!//
                        [!ENDIF!][!//
                    [!ELSE!][!//
                        [!ERROR "Invalid reference for $EepDemEventName"!]
                    [!ENDIF!][!//
                [!ELSE!][!//
                    [!CODE!]/* [!"$EepDemEventName"!] */ {(uint32)STD_OFF, 0U}[!"$EepDelimiter"!][!CR!][!ENDCODE!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
        [!IF "$DemNodeFound='false'"!]
            [!CODE!]/* [!"$EepDemEventName"!] */ {(uint32)STD_OFF, 0U}[!"$EepDelimiter"!][!CR!][!ENDCODE!][!//
        [!ENDIF!]
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!//
[!/* *** multiple inclusion protection *** */!]
[!IF "not(var:defined('EEP_CFG_SPECIFIC_MACROS_M4'))"!][!//
    [!VAR "EEP_CFG_SPECIFIC_MACROS_M4"="'true'"!][!//

    [!MACRO "GetEndianModeValue", "EndianMode"!][!//
        [!NOCODE!][!//
            [!IF "($EndianMode) = 'USDHC_ENDIAN_MODE_BIG'"!]
                [!VAR "EndianModeValueOut" = "0"!]
            [!ELSEIF "($EndianMode) = 'USDHC_ENDIAN_MODE_HALF_WORD_BIG'"!]
                [!VAR "EndianModeValueOut" = "1"!]
            [!ELSE!]
                [!VAR "EndianModeValueOut" = "2"!]
            [!ENDIF!]
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "GetDmaModeValue", "DmaMode"!][!//
        [!NOCODE!][!//
            [!IF "($DmaMode) = 'USDHC_DMA_MODE_NO_DMA'"!]
                [!VAR "DmaModeValueOut" = "0"!]
            [!ELSEIF "($DmaMode) = 'USDHC_DMA_MODE_ADMA1'"!]
                [!VAR "DmaModeValueOut" = "1"!]
            [!ELSE!]
                [!VAR "DmaModeValueOut" = "2"!]
            [!ENDIF!]
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "GetBootModeValue", "BootMode"!][!//
        [!NOCODE!][!//
            [!IF "($BootMode) = 'USDHC_NORMAL_MMC_BOOT'"!]
                [!VAR "BootModeValueOut" = "0"!]
            [!ELSE!]
                [!VAR "BootModeValueOut" = "1"!]
            [!ENDIF!]
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "GetBootFlagsValue"!][!//
        [!NOCODE!][!//
            [!IF "node:value(./BootHostConfig/ackFlag) = 'true'"!]
                [!VAR "BootFlagsValueOut" = "16"!]
            [!ELSE!]
                [!VAR "BootFlagsValueOut" = "0"!]
            [!ENDIF!]
            [!IF "node:value(./BootHostConfig/disChkTimeout) = 'true'"!]
                [!VAR "BootFlagsValueOut" = "bit:or($BootFlagsValueOut,256)"!]
            [!ENDIF!]
            [!IF "node:value(./BootHostConfig/autoBlkGap) = 'true'"!]
                [!VAR "BootFlagsValueOut" = "bit:or($BootFlagsValueOut,128)"!]
            [!ENDIF!]
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "GetCardTypeValue"!][!//
        [!NOCODE!][!//
            [!IF "node:value(./EepEnableOperationsOnEmmc) = 'true'"!]
                [!VAR "CardTypeValueOut" = "1"!]
            [!ELSE!]
                [!VAR "CardTypeValueOut" = "0"!]
            [!ENDIF!]
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "EepCalcCrc"!][!//
        [!NOCODE!][!//
        [!VAR "EepCrcReminder" = "0"!][!// reset CRC reminder
            // Calculate CRC for EepInitConfiguration
            [!LOOP "as:modconf('Eep')[1]/EepInitConfiguration"!]
                // CRC - Accumulate eDefaultMode
                [!CALL "EepGetMemifModeValue","EepEnumName"="./EepDefaultMode"!][!//
                [!CALL "EepAccCrc","EepData32"="$OutMemifModeValue"!][!//
                // CRC - Accumulate u32MaxReadFastMode
                [!CALL "EepAccCrc","EepData32"="./EepFastReadBlockSize"!][!//
                // CRC - Accumulate u32MaxReadNormalMode
                [!CALL "EepAccCrc","EepData32"="./EepNormalReadBlockSize"!][!//
                // CRC - Accumulate u32MaxWriteFastMode
                [!CALL "EepAccCrc","EepData32"="./EepFastWriteBlockSize"!][!//
                // CRC - Accumulate u32MaxWriteNormalMode
                [!CALL "EepAccCrc","EepData32"="./EepNormalWriteBlockSize"!][!//
                [!IF "node:value(../AutosarExt/EepDisableDemReportErrorStatus) = 'false'"!]
                    // CRC - Accumulate EEP_E_COMPARE_FAILED
                    [!IF "node:exists(./EepDemEventParameterRefs/EEP_E_COMPARE_FAILED)"!]
                        [!CALL "EepAccCrc","EepData32"="1"!]
                        [!CALL "GetDemErrorValue","DemRefPath"="./EepDemEventParameterRefs/EEP_E_COMPARE_FAILED"!]
                        [!CALL "EepAccCrc","EepData32"="$DemEventIdOut"!]
                    [!ELSE!]
                        [!CALL "EepAccCrc","EepData32"="0"!]
                        [!CALL "EepAccCrc","EepData32"="0"!]
                    [!ENDIF!]
                    // CRC - Accumulate EEP_E_ERASE_FAILED
                    [!IF "node:exists(./EepDemEventParameterRefs/EEP_E_ERASE_FAILED)"!]
                        [!CALL "EepAccCrc","EepData32"="1"!]
                        [!CALL "GetDemErrorValue","DemRefPath"="./EepDemEventParameterRefs/EEP_E_ERASE_FAILED"!]
                        [!CALL "EepAccCrc","EepData32"="$DemEventIdOut"!]
                    [!ELSE!]
                        [!CALL "EepAccCrc","EepData32"="0"!]
                        [!CALL "EepAccCrc","EepData32"="0"!]
                    [!ENDIF!]
                    // CRC - Accumulate EEP_E_READ_FAILED
                    [!IF "node:exists(./EepDemEventParameterRefs/EEP_E_READ_FAILED)"!]
                        [!CALL "EepAccCrc","EepData32"="1"!]
                        [!CALL "GetDemErrorValue","DemRefPath"="./EepDemEventParameterRefs/EEP_E_READ_FAILED"!]
                        [!CALL "EepAccCrc","EepData32"="$DemEventIdOut"!]
                    [!ELSE!]
                        [!CALL "EepAccCrc","EepData32"="0"!]
                        [!CALL "EepAccCrc","EepData32"="0"!]
                    [!ENDIF!]
                    // CRC - Accumulate EEP_E_WRITE_FAILED
                    [!IF "node:exists(./EepDemEventParameterRefs/EEP_E_WRITE_FAILED)"!]
                        [!CALL "EepAccCrc","EepData32"="1"!]
                        [!CALL "GetDemErrorValue","DemRefPath"="./EepDemEventParameterRefs/EEP_E_WRITE_FAILED"!]
                        [!CALL "EepAccCrc","EepData32"="$DemEventIdOut"!]
                    [!ELSE!]
                        [!CALL "EepAccCrc","EepData32"="0"!]
                        [!CALL "EepAccCrc","EepData32"="0"!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!][!//
            // Calculate CRC for EepUsdhcControllerCfg
            [!LOOP "as:modconf('Eep')[1]/EepUsdhcControllerCfg/*[1]"!]
                // CRC - Accumulate Instance number
                [!CALL "EepAccCrc","EepData32"="0"!]
                // CRC - Accumulate cardDetectDat3
                [!CALL "GetBooleanValue","Boolean"="node:value(./cardDetectDat3)"!]
                [!CALL "EepAccCrc","EepData32"="$BooleanValueOut"!]
                // CRC - Accumulate EepEnableAutoCMD12
                [!CALL "GetBooleanValue","Boolean"="node:value(./EepEnableAutoCMD12)"!]
                [!CALL "EepAccCrc","EepData32"="$BooleanValueOut"!]
                // CRC - Accumulate endianMode
                [!CALL "GetEndianModeValue","EndianMode"="node:value(./endianMode)"!]
                [!CALL "EepAccCrc","EepData32"="$EndianModeValueOut"!]
                // CRC - Accumulate dmaMode
                [!CALL "GetDmaModeValue","DmaMode"="node:value(./dmaMode)"!]
                [!CALL "EepAccCrc","EepData32"="$DmaModeValueOut"!]
                // CRC - Accumulate admaTableSize
                [!CALL "EepAccCrc","EepData32"="node:value(./admaTableSize)"!]
                // CRC - Accumulate WriteWatermarkLevel
                [!CALL "EepAccCrc","EepData32"="node:value(./WriteWatermarkLevel)"!]
                // CRC - Accumulate ReadWatermarkLevel
                [!CALL "EepAccCrc","EepData32"="node:value(./ReadWatermarkLevel)"!]
                [!IF "node:exists(BootHostConfig)"!]
                    // CRC - Accumulate ackTimeout
                    [!CALL "EepAccCrc","EepData32"="node:value(./BootHostConfig/ackTimeout)"!]
                    // CRC - Accumulate bootMode
                    [!CALL "GetBootModeValue","BootMode"="node:value(./BootHostConfig/bootMode)"!]
                    [!CALL "EepAccCrc","EepData32"="$BootModeValueOut"!]
                    // CRC - Accumulate stopBlockGapCount
                    [!CALL "EepAccCrc","EepData32"="node:value(./BootHostConfig/stopBlockGapCount)"!]
                    // CRC - Accumulate bootFlags
                    [!CALL "GetBootFlagsValue"!]
                    [!CALL "EepAccCrc","EepData32"="$BootFlagsValueOut"!]
                    // CRC - Accumulate bootSdClock
                    [!CALL "EepAccCrc","EepData32"="node:value(./BootHostConfig/bootSdClock)"!]
                [!ENDIF!][!//
            [!ENDLOOP!]
            // Calculate CRC for EepSdCfg
            [!LOOP "as:modconf('Eep')[1]/EepSdCfg/*[1]"!]
                // CRC - Accumulate SdConfigClock
                [!CALL "EepAccCrc","EepData32"="node:value(./afrequencyTable)"!]
                // CRC - Accumulate SdClockReference
                [!CALL "EepAccCrc","EepData32"="node:value(node:ref(./SdClockReference)/McuClockReferencePointFrequency)"!]
            [!ENDLOOP!]
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    
[!ENDIF!][!//

[!LOOP "EepInitConfiguration"!][!//
    #define EEP_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Eep_MemMap.h"

    [!NOCODE!][!//
    [!IF "./../EepGeneral/EepEnableCheckCfgCrc"!]
        [!CALL "EepCalcCrc"!][!//
    [!ENDIF!][!//
    [!ENDNOCODE!][!//
    /**
    * @brief       Structure used to set function pointers notification, working mode
    */
    const Eep_ConfigType Eep_Config[!"$variantName"!][!WS "1"!] =
    {
        [!WS "4"!]/* EepJobEndNotification             */ [!IF "node:exists(EepJobEndNotification)"!]&[!"./EepJobEndNotification"!][!ELSE!]NULL_PTR[!ENDIF!],
        [!WS "4"!]/* EepJobErrorNotification           */ [!IF "node:exists(EepJobErrorNotification)"!]&[!"./EepJobErrorNotification"!][!ELSE!]NULL_PTR[!ENDIF!],
        [!WS "4"!]/* EepDefaultMode                    */ [!"./EepDefaultMode"!],
        [!WS "4"!]/* EepFastReadBlockSize              */ [!"./EepFastReadBlockSize"!]U,
        [!WS "4"!]/* EepNormalReadBlockSize            */ [!"./EepNormalReadBlockSize"!]U,
        [!WS "4"!]/* EepFastWriteBlockSize             */ [!"./EepFastWriteBlockSize"!]U,
        [!WS "4"!]/* EepNormalWriteBlockSize           */ [!"./EepNormalWriteBlockSize"!]U,
    [!IF "$EepDemErrorEnable"!][!//
        [!WS "4"!]/**
        [!WS "4"!]* @brief   DEM error parameters
        [!WS "4"!]*/
        [!WS "4"!][!CALL "EepDemEventCfg","EepDemEventName"="'EEP_E_COMPARE_FAILED parameters  '","EepDelimiter"="','"!][!//
        [!WS "4"!][!CALL "EepDemEventCfg","EepDemEventName"="'EEP_E_ERASE_FAILED parameters    '","EepDelimiter"="','"!][!//
        [!WS "4"!][!CALL "EepDemEventCfg","EepDemEventName"="'EEP_E_READ_FAILED parameters     '","EepDelimiter"="','"!][!//
        [!WS "4"!][!CALL "EepDemEventCfg","EepDemEventName"="'EEP_E_WRITE_FAILED parameters    '","EepDelimiter"="','"!][!//
    [!ENDIF!][!//
    [!IF "./../EepGeneral/EepEnableCheckCfgCrc"!]
    [!CALL "EepFinishCrc"!][!//
        [!AUTOSPACING!][!WS "4"!]/* EEP Config Set CRC checksum       */ [!"$EepCrcReminder"!]U,
    [!ENDIF!][!//
        [!WS "4"!]&[!"node:name(../EepSdCfg/*)"!][!"$variantName"!]
    };

    #define EEP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Eep_MemMap.h"
[!ENDLOOP!][!//
[!ENDINDENT!][!//
[!ENDCODE!][!//

#ifdef __cplusplus
}
#endif

/** @}*/

[!NOCODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : SERDES_SS
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

[!VAR "PcieArMajorVersionTemplate"="4"!][!//
[!VAR "PcieArMinorVersionTemplate"="4"!][!//
[!VAR "PcieArPatchVersionTemplate"="0"!][!//
[!VAR "PcieSwMajorVersionTemplate"="4"!][!//     
[!VAR "PcieSwMinorVersionTemplate"="0"!][!//     

[!ENDNOCODE!][!//
[!SELECT "CommonPublishedInformation"!][!//
[!/*
[!IF "not(num:i(ArMajorVersion) = num:i($PcieArMajorVersionTemplate))"!]
    [!ERROR!]
        "AUTOSAR major version number of the Basic Software Module Description file (Pcie.epd version [!"ArMajorVersion"!]) and the Code template file (Pcie_Cfg.c version [!"num:i($PcieArMajorVersionTemplate)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(ArMinorVersion)  = num:i($PcieArMinorVersionTemplate))"!]
    [!ERROR!]
        "AUTOSAR minor version number of the Basic Software Module Description file (Pcie.epd version [!"ArMinorVersion"!]) and the Code template file (Pcie_Cfg.c version [!"num:i($PcieArMinorVersionTemplate)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(ArPatchVersion)  = num:i($PcieArPatchVersionTemplate))"!]
    [!ERROR!]
        "AUTOSAR patch version number of the Basic Software Module Description file (Pcie.epd version [!"ArPatchVersion"!]) and the Code template file (Pcie_Cfg.c version [!"num:i($PcieArPatchVersionTemplate)"!]) are different
    [!ENDERROR!]
[!ENDIF!][!//
*/!]
[!IF "not(num:i(SwMajorVersion) = num:i($PcieSwMajorVersionTemplate))"!]
    [!ERROR!]
        "The software major number of the Basic Software Module Description file (Pcie.epd version [!"SwMajorVersion"!]) and the Code template file (Pcie_Cfg.c version [!"num:i($PcieSwMajorVersionTemplate)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(SwMinorVersion) = num:i($PcieSwMinorVersionTemplate))"!]
    [!ERROR!]
        "The software minor number of the Basic Software Module Description file (Pcie.epd version [!"SwMinorVersion"!]) and the Code template file (Pcie_Cfg.c version [!"num:i($PcieSwMinorVersionTemplate)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!ENDSELECT!][!//
[!NOCODE!][!//

[!ENDNOCODE!][!//

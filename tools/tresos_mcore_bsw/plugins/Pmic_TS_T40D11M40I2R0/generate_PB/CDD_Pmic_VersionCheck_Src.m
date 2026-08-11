[!NOCODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Pmic_VR55XX
*   Dependencies         : MCU,DET,DEM,RTE,I2C,PORT,DIO,OCOTP
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
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

[!/* *** Multiple inclusion protection *** */!]
[!IF "not(var:defined('CDD_PMIC_VERSION_CHECK_SRC_M'))"!][!//
[!VAR "CDD_PMIC_VERSION_CHECK_SRC_M"="'true'"!][!//
    [!VAR "PmicArReleaseMajorVersionTemplate"="4"!][!//
    [!VAR "PmicArReleaseMinorVersionTemplate"="4"!][!//
    [!VAR "PmicArReleaseRevisionVersionTemplate"="0"!][!//
    [!VAR "PmicSwMajorVersionTemplate"="4"!][!//
    [!VAR "PmicSwMinorVersionTemplate"="0"!][!//
    [!VAR "PmicSwPatchVersionTemplate"="2"!][!//

    [!SELECT "CommonPublishedInformation"!][!//
    [!IF "not(num:i(ArReleaseMajorVersion) = num:i($PmicArReleaseMajorVersionTemplate))"!]
        [!ERROR!]
            "AUTOSAR major version number of the Basic Software Module Description file (Pmic.epd version [!"ArReleaseMajorVersion"!]) and the Code template file (CDD_Pmic_Cfg.c version [!"num:i($PmicArReleaseMajorVersionTemplate)"!]) are different"
        [!ENDERROR!]
    [!ENDIF!][!//
    [!IF "not(num:i(ArReleaseMinorVersion)  = num:i($PmicArReleaseMinorVersionTemplate))"!]
        [!ERROR!]
            "AUTOSAR minor version number of the Basic Software Module Description file (Pmic.epd version [!"ArReleaseMinorVersion"!]) and the Code template file (CDD_Pmic_Cfg.c version [!"num:i($PmicArReleaseMinorVersionTemplate)"!]) are different"
        [!ENDERROR!]
    [!ENDIF!][!//
    [!IF "not(num:i(ArReleaseRevisionVersion)  = num:i($PmicArReleaseRevisionVersionTemplate))"!]
        [!ERROR!]
            "AUTOSAR revision version number of the Basic Software Module Description file (Pmic.epd version [!"ArReleaseRevisionVersion"!]) and the Code template file (CDD_Pmic_Cfg.c version [!"num:i($PmicArReleaseRevisionVersionTemplate)"!]) are different"
        [!ENDERROR!]
    [!ENDIF!][!//

    [!IF "not(num:i(SwMajorVersion) = num:i($PmicSwMajorVersionTemplate))"!]
        [!ERROR!]
            "The software major number of the Basic Software Module Description file (Pmic.epd version [!"SwMajorVersion"!]) and the Code template file (CDD_Pmic_Cfg.c version [!"num:i($PmicSwMajorVersionTemplate)"!]) are different"
        [!ENDERROR!]
    [!ENDIF!][!//
    [!IF "not(num:i(SwMinorVersion) = num:i($PmicSwMinorVersionTemplate))"!]
        [!ERROR!]
            "The software minor number of the Basic Software Module Description file (Pmic.epd version [!"SwMinorVersion"!]) and the Code template file (CDD_Pmic_Cfg.c version [!"num:i($PmicSwMinorVersionTemplate)"!]) are different"
        [!ENDERROR!]
    [!ENDIF!][!//
    [!IF "not(num:i(SwPatchVersion) = num:i($PmicSwPatchVersionTemplate))"!]
        [!ERROR!]
            "The software patch number of the Basic Software Module Description file (Pmic.epd version [!"SwPatchVersion"!]) and the Code template file (CDD_Pmic_Cfg.c version [!"num:i($PmicSwPatchVersionTemplate)"!]) are different"
        [!ENDERROR!]
    [!ENDIF!]
    [!ENDSELECT!][!//
[!ENDIF!][!// Avoid multiple inclusion ENDIF
[!ENDNOCODE!][!//

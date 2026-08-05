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

[!VAR "SerdesArMajorVersionTemplate"="4"!][!//
[!VAR "SerdesArMinorVersionTemplate"="4"!][!//
[!VAR "SerdesArPatchVersionTemplate"="0"!][!//
[!VAR "SerdesSwMajorVersionTemplate"="4"!][!//
[!VAR "SerdesSwMinorVersionTemplate"="0"!][!//

[!ENDNOCODE!][!//
[!SELECT "CommonPublishedInformation"!][!//
[!/*
[!IF "not(num:i(ArMajorVersion) = num:i($SerdesArMajorVersionTemplate))"!]
    [!ERROR!]
        "AUTOSAR major version number of the Basic Software Module Description file (Serdes.epd version [!"ArMajorVersion"!]) and the Code template file (Serdes_Cfg.h version [!"num:i($SerdesArMajorVersionTemplate)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(ArMinorVersion)  = num:i($SerdesArMinorVersionTemplate))"!]
     [!ERROR!]
        "AUTOSAR minor version number of the Basic Software Module Description file (Serdes.epd version [!"ArMinorVersion"!]) and the Code template file (Serdes_Cfg.h version [!"num:i($SerdesArMinorVersionTemplate)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(ArPatchVersion)  = num:i($SerdesArPatchVersionTemplate))"!]
    [!ERROR!]
        "AUTOSAR patch version number of the Basic Software Module Description file (Serdes.epd version [!"ArPatchVersion"!]) and the Code template file (Serdes_Cfg.h version [!"num:i($SerdesArPatchVersionTemplate)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
*/!]
[!IF "not(num:i(SwMajorVersion) = num:i($SerdesSwMajorVersionTemplate))"!]
    [!ERROR!]
        "The software major number of the Basic Software Module Description file (Serdes.epd version [!"SwMajorVersion"!]) and the Code template file (Serdes_Cfg.h version [!"num:i($SerdesSwMajorVersionTemplate)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(SwMinorVersion) = num:i($SerdesSwMinorVersionTemplate))"!]
    [!ERROR!]
        "The software minor number of the Basic Software Module Description file (Serdes.epd version [!"SwMinorVersion"!]) and the Code template file (Serdes_Cfg.h version [!"num:i($SerdesSwMinorVersionTemplate)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!ENDSELECT!][!//
[!NOCODE!][!//

[!ENDNOCODE!][!//

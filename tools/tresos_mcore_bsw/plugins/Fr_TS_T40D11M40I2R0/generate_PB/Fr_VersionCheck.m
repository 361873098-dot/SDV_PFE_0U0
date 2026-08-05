[!NOCODE!]
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : FLEXRAY
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
 *  @file     Fr_VersionCheck.m
 *  @version  4.0.2
 *
 *  @brief    AUTOSAR Fr - plugin check.
 *  @details  Fr plugin generation templates version checks
 */

[!/* *** multiple inclusion protection *** */!]
    [!IF "not(var:defined('FR_VERSIONCHECKMACROS_M'))"!]
        [!VAR "FR_VERSIONCHECKMACROS_M"="'true'"!]
        [!VAR "FR_AR_MAJOR_VERSION_TEMPLATE"="4"!]
        [!VAR "FR_AR_MINOR_VERSION_TEMPLATE"="4"!]
        [!VAR "FR_AR_PATCH_VERSION_TEMPLATE"="0"!]
        [!VAR "FR_SW_MAJOR_VERSION_TEMPLATE"="4"!]
        [!VAR "FR_SW_MINOR_VERSION_TEMPLATE"="0"!]
        [!VAR "FR_SW_PATCH_VERSION_TEMPLATE"="2"!]
        [!VAR "FR_VENDOR_ID_TEMPLATE"="43"!]
        [!VAR "FR_MODULE_ID_TEMPLATE"="81"!]
        [!SELECT "CommonPublishedInformation"!]
            [!IF "num:i(ArReleaseMajorVersion) != num:i($FR_AR_MAJOR_VERSION_TEMPLATE)"!]
                [!ERROR!]
                    [!WS "0"!]Error 001: AUTOSAR major version number of the Basic Software Module Description file ([!"ArReleaseMajorVersion"!]) and the Code Template files ([!"num:i($FR_AR_MAJOR_VERSION_TEMPLATE)"!]) are different.
                [!ENDERROR!]
            [!ENDIF!]
            [!IF "num:i(ArReleaseMinorVersion) != num:i($FR_AR_MINOR_VERSION_TEMPLATE)"!]
                [!ERROR!]
                    [!WS "0"!]Error 002: AUTOSAR minor version number of the Basic Software Module Description file ([!"ArReleaseMajorVersion"!]) and  Code Template files ([!"num:i($FR_AR_MINOR_VERSION_TEMPLATE)"!]) are different.
                [!ENDERROR!]
            [!ENDIF!]
            [!IF "num:i(ArReleaseRevisionVersion) != num:i($FR_AR_PATCH_VERSION_TEMPLATE)"!]
                [!ERROR!]
                    [!WS "0"!]Error 003: AUTOSAR release revision version numbers of the Basic Software Module Description file ([!"ArReleaseRevisionVersion"!]) and the Code Template files version ([!"num:i($FR_AR_PATCH_VERSION_TEMPLATE)"!]) are different.
                [!ENDERROR!]
            [!ENDIF!]
            [!IF "num:i(SwMajorVersion) != num:i($FR_SW_MAJOR_VERSION_TEMPLATE)"!]
                [!ERROR!]
                    [!WS "0"!]Error 004: The software major number of the Basic Software Module Description file ([!"SwMajorVersion"!]) and the Code Template files version ([!"num:i($FR_SW_MAJOR_VERSION_TEMPLATE)"!]) are different.
                [!ENDERROR!]
            [!ENDIF!]
            [!IF "num:i(SwMinorVersion) != num:i($FR_SW_MINOR_VERSION_TEMPLATE)"!]
                [!ERROR!]
                    [!WS "0"!]Error 005: The software minor number of the Basic Software Module Description file ([!"SwMinorVersion"!]) and the Code Template files version ([!"num:i($FR_SW_MINOR_VERSION_TEMPLATE)"!]) are different.
                [!ENDERROR!]
            [!ENDIF!]
            [!IF "num:i(SwPatchVersion) != num:i($FR_SW_PATCH_VERSION_TEMPLATE)"!]
                [!ERROR!]
                    [!WS "0"!]Error 006:  The software patch number of the Basic Software Module Description file ([!"SwPatchVersion"!]) and the Code Template files version ([!"num:i($FR_SW_PATCH_VERSION_TEMPLATE)"!]) are different.
                [!ENDERROR!]
            [!ENDIF!]
            [!IF "num:i(VendorId) != num:i($FR_VENDOR_ID_TEMPLATE)"!]
                [!ERROR!]
                    [!WS "0"!]Error 007: The vendor ID of the Basic Software Module Description file ([!"VendorId"!]) and the Code Template files vendor ID ([!"num:i($FR_VENDOR_ID_TEMPLATE)"!]) are different.
                [!ENDERROR!]
            [!ENDIF!]
            [!IF "num:i(ModuleId) != num:i($FR_MODULE_ID_TEMPLATE)"!]
                [!ERROR!]
                    [!WS "0"!]Error 008: The module ID of the Basic Software Module Description file ([!"ModuleId"!]) and the Code Template files ([!"num:i($FR_MODULE_ID_TEMPLATE)"!]) are different.
                [!ENDERROR!]
            [!ENDIF!]
        [!ENDSELECT!]
    [!ENDIF!]
[!ENDNOCODE!]

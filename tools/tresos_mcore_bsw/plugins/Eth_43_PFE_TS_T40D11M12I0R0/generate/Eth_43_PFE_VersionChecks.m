[!NOCODE!][!//Do not generate any output, only warnigs and errors
/*
 *  \file    Eth_VersionChecks_Inc.m
 *
 *  \brief   AUTOSAR Eth_43_PFE - version check macro.
 *  \details Version checks.
 *  
 *  Project              : AUTOSAR 4.4 MCAL
 *  Platform             : CORTEXM
 *  Peripheral           : PFE
 *  Dependencies         : none
 *
 *  Autosar Version      : 4.4.0
 *  Autosar Revision     : ASR_REL_4_4_REV_0000
 *  Autosar Conf.Variant :
 *  SW Version           : 1.2.0
 *  Build Version        : PFE-DRV_S32G_M7_MCAL_1.2.0_D2307_ASR_REL_4_4_REV_0000_20230728
 *
 *  (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
 *      Copyright 2017-2020, 2022 NXP
 *
 *  NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only
 *  be used strictly in accordance with the applicable license terms. By
 *  expressly accepting such terms or by downloading, installing, activating
 *  and/or otherwise using the software, you are agreeing that you have read,
 *  and that you agree to comply with and are bound by, such license terms. If
 *  you do not agree to be bound by the applicable license terms, then you may
 *  not retain, install, activate or otherwise use the software.
 *  <<< PFE Restricted Software >>>
 *
 */

[!/* Multiple Inclusion Protection *** */!][!//
[!IF "not(var:defined('ETH_VERSIONCHECKS_M'))"!][!//
    [!VAR "ETH_VERSIONCHECKS_M"="true()"!][!//
    
    [!VAR "ETH_AR_MAJOR_VERSION_TEMPLATE"="4"!][!//
    [!VAR "ETH_AR_MINOR_VERSION_TEMPLATE"="4"!][!//
    [!VAR "ETH_AR_PATCH_VERSION_TEMPLATE"="0"!][!//
    [!VAR "ETH_SW_MAJOR_VERSION_TEMPLATE"="1"!][!//
    [!VAR "ETH_SW_MINOR_VERSION_TEMPLATE"="2"!][!//
    [!VAR "ETH_SW_PATCH_VERSION_TEMPLATE"="0"!][!//
    [!VAR "ETH_VENDOR_ID_TEMPLATE"="43"!][!//
    [!VAR "ETH_MODULE_ID_TEMPLATE"="88"!][!//
    
    [!SELECT "CommonPublishedInformation"!][!//
        [!IF "ArReleaseMajorVersion != num:i($ETH_AR_MAJOR_VERSION_TEMPLATE)"!]
            [!ERROR!]AUTOSAR major version number of the Basic Software Module Description file ([!"ArReleaseMajorVersion"!]) and the Code Template files ([!"num:i($ETH_AR_MAJOR_VERSION_TEMPLATE)"!]) are different.[!ENDERROR!]
        [!ENDIF!][!//
        [!IF "ArReleaseMinorVersion != num:i($ETH_AR_MINOR_VERSION_TEMPLATE)"!]
            [!ERROR!]AUTOSAR minor version number of the Basic Software Module Description file ([!"ArReleaseMinorVersion"!]) and the Code Template files ([!"num:i($ETH_AR_MINOR_VERSION_TEMPLATE)"!]) are different.[!ENDERROR!]
        [!ENDIF!][!//
        [!IF "ArReleaseRevisionVersion != num:i($ETH_AR_PATCH_VERSION_TEMPLATE)"!]
            [!ERROR!]AUTOSAR patch version number of the Basic Software Module Description file ([!"ArReleaseRevisionVersion"!]) and the Code Template files ([!"num:i($ETH_AR_PATCH_VERSION_TEMPLATE)"!]) are different.[!ENDERROR!]
        [!ENDIF!][!//
        [!IF "SwMajorVersion != num:i($ETH_SW_MAJOR_VERSION_TEMPLATE)"!]
            [!ERROR!]The software major number of the Basic Software Module Description file ([!"SwMajorVersion"!]) and the Code Template files ([!"num:i($ETH_SW_MAJOR_VERSION_TEMPLATE)"!]) are different.[!ENDERROR!]
        [!ENDIF!][!//
        [!IF "SwMinorVersion != num:i($ETH_SW_MINOR_VERSION_TEMPLATE)"!]
            [!ERROR!]The software minor number of the Basic Software Module Description file ([!"SwMinorVersion"!]) and the Code Template files ([!"num:i($ETH_SW_MINOR_VERSION_TEMPLATE)"!]) are different.[!ENDERROR!]
        [!ENDIF!][!//
        [!IF "SwPatchVersion != num:i($ETH_SW_PATCH_VERSION_TEMPLATE)"!]
            [!ERROR!]The software patch number of the Basic Software Module Description file ([!"SwPatchVersion"!]) and the Code Template files ([!"num:i($ETH_SW_PATCH_VERSION_TEMPLATE)"!]) are different.[!ENDERROR!]
        [!ENDIF!][!//
        [!IF "VendorId != num:i($ETH_VENDOR_ID_TEMPLATE)"!]
            [!ERROR!]The vendor ID of the Basic Software Module Description file ([!"VendorId"!]) and the Code Template files ([!"num:i($ETH_VENDOR_ID_TEMPLATE)"!]) are different.[!ENDERROR!]
        [!ENDIF!][!//
        [!IF "ModuleId != num:i($ETH_MODULE_ID_TEMPLATE)"!]
            [!ERROR!]The module ID of the Basic Software Module Description file ([!"ModuleId"!]) and the Code Template files ([!"num:i($ETH_MODULE_ID_TEMPLATE)"!]) are different.[!ENDERROR!]
        [!ENDIF!][!//
    [!ENDSELECT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

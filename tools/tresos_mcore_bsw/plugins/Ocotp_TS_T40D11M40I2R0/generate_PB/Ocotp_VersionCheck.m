[!NOCODE!][!//

[!/* *** multiple inclusion protection *** */!]
[!IF "not(var:defined('OCOTP_VERSIONCHECK_M'))"!]
[!VAR "OCOTP_VERSIONCHECK_M"="'true'"!]

/**
*   @file    Ocotp_VersionCheck_Src_PB.m
*   @version 4.0.2
*
*   @brief   AUTOSAR Ocotp - version check macro.
*   @details Version checks.
*
*   @addtogroup OCOTP
*   @{
*/
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : OCOTP_IP
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
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

[!VAR "OCOTP_AR_RELEASE_MAJOR_VERSION_TEMPLATE"="4"!][!//
[!VAR "OCOTP_AR_RELEASE_MINOR_VERSION_TEMPLATE"="4"!][!//
[!VAR "OCOTP_AR_RELEASE_REVISION_VERSION_TEMPLATE"="0"!][!//
[!VAR "OCOTP_SW_MAJOR_VERSION_TEMPLATE"="4"!][!//
[!VAR "OCOTP_SW_MINOR_VERSION_TEMPLATE"="0"!][!//
[!VAR "OCOTP_SW_PATCH_VERSION_TEMPLATE"="2"!][!//

[!SELECT "CommonPublishedInformation"!][!//

[!ASSERT "ArReleaseMajorVersion = num:i($OCOTP_AR_RELEASE_MAJOR_VERSION_TEMPLATE)"!]
        **** AUTOSAR release major version number of the Basic Software Module Description file (version [!"ArReleaseMajorVersion "!]) and the Code template file (version [!"num:i($OCOTP_AR_RELEASE_MAJOR_VERSION_TEMPLATE)"!]) are different ****
[!ENDASSERT!][!//
[!ASSERT "ArReleaseMinorVersion  = num:i($OCOTP_AR_RELEASE_MINOR_VERSION_TEMPLATE)"!]
        **** AUTOSAR release minor version number of the Basic Software Module Description file (version [!"ArReleaseMinorVersion"!]) and the Code template files (version [!"num:i($OCOTP_AR_RELEASE_MINOR_VERSION_TEMPLATE)"!]) are different ****
[!ENDASSERT!][!//
[!ASSERT "ArReleaseRevisionVersion  = num:i($OCOTP_AR_RELEASE_REVISION_VERSION_TEMPLATE)"!]
        **** AUTOSAR release revision version number of the Basic Software Module Description file (version [!"ArReleaseRevisionVersion"!]) and the Code template files (version [!"num:i($OCOTP_AR_RELEASE_REVISION_VERSION_TEMPLATE)"!]) are different ****
[!ENDASSERT!][!//
[!ASSERT "SwMajorVersion = num:i($OCOTP_SW_MAJOR_VERSION_TEMPLATE)"!]
        **** The software major number of the Basic Software Module Description file (version [!"SwMajorVersion"!]) and the Code template files (version [!"num:i($OCOTP_SW_MAJOR_VERSION_TEMPLATE)"!]) are different ****
[!ENDASSERT!][!//
[!ASSERT "SwMinorVersion = num:i($OCOTP_SW_MINOR_VERSION_TEMPLATE)"!]
        **** The software minor number of the Basic Software Module Description file (version [!"SwMinorVersion"!]) and the Code template files (version [!"num:i($OCOTP_SW_MINOR_VERSION_TEMPLATE)"!]) are different ****
[!ENDASSERT!][!//
[!ASSERT "SwPatchVersion = num:i($OCOTP_SW_PATCH_VERSION_TEMPLATE)"!]
        **** The software minor number of the Basic Software Module Description file (version [!"SwPatchVersion"!]) and the Code template files (version [!"num:i($OCOTP_SW_PATCH_VERSION_TEMPLATE)"!]) are different ****
[!ENDASSERT!][!//

[!ENDSELECT!][!//
[!ENDIF!]

[!ENDNOCODE!][!//
[!NOCODE!][!//

/*!
*   @file    Ocu_VersionCheck_Inc.m
*   @version 4.0.2
*
*   @brief   AUTOSAR Ocu macro to check for notification config, variant post-build
*   @details    macro to check for notification config, variant pre-compile
*
*   @addtogroup   ocu_driver Ocu Driver
*   @{
*/
/*!==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Ftm
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
*   Copyright 2020-2023 NXP Semiconductors
==================================================================================================*/
[!ENDNOCODE!][!//


[!/* avoid multiple inclusion */!]
[!IF "not(var:defined('OCU_VERSION_CHECK_INC_M'))"!]
[!VAR "OCU_VERSION_CHECK_INC_M"="'true'"!]


[!VAR "OCU_AR_MAJOR_VERSION_TEMPLATE"="4"!][!//
[!VAR "OCU_AR_MINOR_VERSION_TEMPLATE"="4"!][!//
[!VAR "OCU_AR_PATCH_VERSION_TEMPLATE"="0"!][!//
[!VAR "OCU_SW_MAJOR_VERSION_TEMPLATE"="4"!][!//
[!VAR "OCU_SW_MINOR_VERSION_TEMPLATE"="0"!][!//

[!SELECT "CommonPublishedInformation"!][!//
[!IF "not(num:i(ArReleaseMajorVersion) = num:i($OCU_AR_MAJOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
    **** AUTOSAR major version number of the Basic Software Module Description file (Ocu.epd version [!"ArReleaseMajorVersion "!]) and the Code template files (Ocu_Cfg.h version [!"num:i($OCU_AR_MAJOR_VERSION_TEMPLATE)"!]) are different ****
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(ArReleaseMinorVersion)  = num:i($OCU_AR_MINOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
    **** AUTOSAR minor version number of the Basic Software Module Description file (Ocu.epd version [!"ArReleaseMinorVersion"!]) and the Code template files (Ocu_Cfg.h version [!"num:i($OCU_AR_MINOR_VERSION_TEMPLATE)"!]) are different ****
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(ArReleasePatchVersion)  = num:i($OCU_AR_PATCH_VERSION_TEMPLATE))"!]
    [!ERROR!]
        **** AUTOSAR patch version number of the Basic Software Module Description file (Ocu.epd version [!"ArReleasePatchVersion"!]) and the Code template files (Ocu_Cfg.h version [!"num:i($OCU_AR_PATCH_VERSION_TEMPLATE)"!]) are different ****
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(SwMajorVersion) = num:i($OCU_SW_MAJOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        **** The software major number of the Basic Software Module Description file (Ocu.epd version [!"SwMajorVersion"!]) and the Code template files (Ocu_Cfg.h version [!"num:i($OCU_SW_MAJOR_VERSION_TEMPLATE)"!]) are different ****
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(SwMinorVersion) = num:i($OCU_SW_MINOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        **** The software minor number of the Basic Software Module Description file (Ocu.epd version [!"SwMinorVersion"!]) and the Code template files (Ocu_Cfg.h version [!"num:i($OCU_SW_MINOR_VERSION_TEMPLATE)"!]) are different ****
    [!ENDERROR!]
[!ENDIF!][!//
[!ENDSELECT!][!//
[!NOCODE!][!//
[!ENDNOCODE!][!//


[!ENDIF!][!// avoid multiple inclusion ENDIF


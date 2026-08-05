[!NOCODE!][!//
/**
  @file    Port_VersionCheck_Inc.m
  @version 4.0.2

  @brief   AUTOSAR Port - version check macro.
  @details Version checks.
  
  Project RTD AUTOSAR 4.4
  Patform CORTEXM
  Peripheral SIUL2
  Dependencies none
  
  ARVersion 4.4.0
  ARRevision ASR_REL_4_4_REV_0000
  ARConfVariant
  SWVersion 4.0.2
  BuildVersion S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630

  Copyright 2020-2023 NXP Semiconductors
*/

[!/* avoid multiple inclusion */!]
[!IF "not(var:defined('PORT_VERSION_CHECK_INC_M'))"!]
[!VAR "PORT_VERSION_CHECK_INC_M"="'true'"!]

[!VAR "PORT_AR_RELEASE_MAJOR_VERSION_TEMPLATE"="4"!][!// 
[!VAR "PORT_AR_RELEASE_MINOR_VERSION_TEMPLATE"="4"!][!// 
[!VAR "PORT_AR_RELEASE_REVISION_VERSION_TEMPLATE"="0"!][!// 
[!VAR "PORT_SW_MAJOR_VERSION_TEMPLATE"="4"!][!//      
[!VAR "PORT_SW_MINOR_VERSION_TEMPLATE"="0"!][!//
[!VAR "PORT_SW_PATCH_VERSION_TEMPLATE"="2"!][!//      

[!SELECT "CommonPublishedInformation"!][!//
[!IF "not(num:i(ArReleaseMajorVersion) = num:i($PORT_AR_RELEASE_MAJOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR release major version number of the Basic Software Module Description file (Port.epd version [!"ArReleaseMajorVersion"!]) and the Code template file (Port_Cfg.h version [!"num:i($PORT_AR_RELEASE_MAJOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(ArReleaseMinorVersion) = num:i($PORT_AR_RELEASE_MINOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR release minor version number of the Basic Software Module Description file (Port.epd version [!"ArReleaseMinorVersion"!]) and the Code template file (Port_Cfg.h version [!"num:i($PORT_AR_RELEASE_MINOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(ArReleaseRevisionVersion) = num:i($PORT_AR_RELEASE_REVISION_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR release revision version number of the Basic Software Module Description file (Port.epd version [!"ArReleaseRevisionVersion"!]) and the Code template file (Port_Cfg.h version [!"num:i($PORT_AR_RELEASE_REVISION_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(SwMajorVersion) = num:i($PORT_SW_MAJOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software major number of the Basic Software Module Description file (Port.epd version [!"SwMajorVersion"!]) and the Code template file (Port_Cfg.h version [!"num:i($PORT_SW_MAJOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(SwMinorVersion) = num:i($PORT_SW_MINOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software minor number of the Basic Software Module Description file (Port.epd version [!"SwMinorVersion"!]) and the Code template file (Port_Cfg.h version [!"num:i($PORT_SW_MINOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(SwPatchVersion) = num:i($PORT_SW_PATCH_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software patch number of the Basic Software Module Description file (Port.epd version [!"SwPatchVersion"!]) and the Code template file (Port_Cfg.h version [!"num:i($PORT_SW_PATCH_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!ENDSELECT!][!//

[!ENDIF!][!// avoid multiple inclusion ENDIF

[!ENDNOCODE!][!//

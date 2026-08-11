[!NOCODE!][!//
/**
  @file    Wdg_VersionCheck_Inc.m
  @version 4.0.2

  @brief   AUTOSAR Wdg_43_VR5510 - version check macro.
  @details Version checks.
  
  Project RTD AUTOSAR 4.4
  Patform CORTEXM
  Peripheral VR5510
  Dependencies none
  
  ARVersion 4.4.0
  ARRevision ASR_REL_4_4_REV_0000
  ARConfVariant
  SWVersion 4.0.2
  BuildVersion S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630

  (c) Copyright 2020-2023 NXP Semiconductors
  All Rights Reserved.
*/

[!VAR "WdgVr5510ArReleaseMajorVersionTemplate"="4"!][!//
[!VAR "WdgVr5510ArReleaseMinorVersionTemplate"="4"!][!//
[!VAR "WdgVr5510ArReleasePatchVersionTemplate"="0"!][!//
[!VAR "WdgVr5510SwMajorVersionTemplate"="4"!][!//     
[!VAR "WdgVr5510SwMinorVersionTemplate"="0"!][!//
[!VAR "WdgVr55110SwPatchVersionTemplate"="2"!][!// 

[!ENDNOCODE!][!//
[!SELECT "CommonPublishedInformation"!][!//
[!IF "not(num:i(ArReleaseMajorVersion) = num:i($WdgVr5510ArReleaseMajorVersionTemplate))"!]
    [!ERROR!]
        "AUTOSAR major version number of the Basic Software Module Description file (Wdg_Vr5510.epd version [!"ArReleaseMajorVersion"!]) and the Code template file (Wdg_Vr5510_Cfg.h version [!"num:i($WdgVr5510ArReleaseMajorVersionTemplate)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(ArReleaseMinorVersion)  = num:i($WdgVr5510ArReleaseMinorVersionTemplate))"!]
     [!ERROR!]
        "AUTOSAR minor version number of the Basic Software Module Description file (Wdg_Vr5510.epd version [!"ArReleaseMinorVersion"!]) and the Code template file (Wdg_Vr5510_Cfg.h version [!"num:i($WdgVr5510ArReleaseMinorVersionTemplate)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(ArReleaseRevisionVersion)  = num:i($WdgVr5510ArReleasePatchVersionTemplate))"!]
    [!ERROR!]
        "AUTOSAR patch version number of the Basic Software Module Description file (Wdg_Vr5510.epd version [!"ArReleaseRevisionVersion"!]) and the Code template file (Wdg_Vr5510_Cfg.h version [!"num:i($WdgVr5510ArReleasePatchVersionTemplate)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(SwMajorVersion) = num:i($WdgVr5510SwMajorVersionTemplate))"!]
    [!ERROR!]
        "The software major number of the Basic Software Module Description file (Wdg_Vr5510.epd version [!"SwMajorVersion"!]) and the Code template file (Wdg_Vr5510_Cfg.h version [!"num:i($WdgVr5510SwMajorVersionTemplate)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(SwMinorVersion) = num:i($WdgVr5510SwMinorVersionTemplate))"!]
    [!ERROR!]   
        "The software minor number of the Basic Software Module Description file (Wdg_Vr5510.epd version [!"SwMinorVersion"!]) and the Code template file (Wdg_Vr5510_Cfg.h version [!"num:i($WdgVr5510SwMinorVersionTemplate)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(SwPatchVersion) = num:i($WdgVr55110SwPatchVersionTemplate))"!]
    [!ERROR!]
        "The software patch number of the Basic Software Module Description file (Wdg_Vr5510.epd version [!"SwPatchVersion"!]) and the Code template file (Wdg_Vr5510_Cfg.h version [!"num:i($WdgVr55110SwPatchVersionTemplate)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!ENDSELECT!][!//
[!NOCODE!][!//

[!ENDNOCODE!][!//

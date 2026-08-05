[!NOCODE!][!//
/**
  @file    Wdg_PluginMacros.m
  @version 4.0.2

  @brief   AUTOSAR Wdg_43_VR5510 - plugin check.
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

[!// MACRO for checking that the Gpt callback has been set
[!MACRO "WdgCheckCbkNotification"!]
[!NOCODE!]
    [!VAR "CheckGptChannel" = "node:value(node:ref(./WdgSettingsConfig/WdgExternalTriggerCounterRef)/GptChannelId)"!][!//
    [!IF "node:exists(node:ref(./WdgSettingsConfig/WdgExternalTriggerCounterRef)/GptNotification)"!]
        [!IF "node:ref(./WdgSettingsConfig/WdgExternalTriggerCounterRef)/GptNotification != 'Wdg_VR5510_Cbk_GptNotification0'"!]
            [!ERROR!] The notification handler for Wdg_VR5510 must be Wdg_VR5510_Cbk_GptNotification0[!ENDERROR!]
        [!ENDIF!]
    [!ELSE!]
        [!ERROR!] The channel notification for Wdg_VR5510 must be set up and the notification handler must be Wdg_VR5510_Cbk_GptNotification0[!ENDERROR!]
    [!ENDIF!]
    [!LOOP "as:modconf('Gpt')[1]/GptHwConfiguration/*"!]
        [!IF "node:value(./GptIsrHwId) = $CheckGptChannel"!]
            [!IF "node:value(./GptIsrEnable)='false'"!]
                [!ERROR!]The channel [!"$CheckGptChannel"!] must enable GptIsrEnable.[!ENDERROR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDNOCODE!]
[!ENDMACRO!]

[!// MACRO for checking Gpt config
[!MACRO "WdgCheckGptConfig"!]
[!NOCODE!]
    [!LOOP "as:modconf('Gpt')[1]/GptAutosarExt"!]
        [!IF "node:value(./GptChangeNextTimeoutValueApi) = 'false'"!]
            [!ERROR!]The GptChangeNextTimeoutValueApi must be enabled.[!ENDERROR!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDNOCODE!]
[!ENDMACRO!]

[!// MACRO for defining mode configuration
[!MACRO "WdgModeConfig","WdgMode","isDefautMode"!][!//
[!NOCODE!][!//
        [!VAR "pathSetting" = "./WdgSettingsConfig"!]
        [!VAR "pathMode" = "concat('./WdgSettingsConfig/',$WdgMode)"!]
        [!IF "node:value(./WdgSettingsConfig/WdgWindowPeriodEnable) = 'false'"!]
            [!IF "$isDefautMode = 'false'"!]
                [!VAR "CheckWindowPeriod" = "substring-before(substring-after(node:value(concat($pathMode,'/WdgWindowPeriod')),'TIME_'),'MS')"!]
            [!ELSE!]
                [!VAR "CheckWindowPeriod"="substring-before(substring-after(ecu:list('WdgVr5510.WindowPeriod.Default'),'TIME_'),'MS')"!]
            [!ENDIF!]
        [!ELSE!]
            [!VAR "CheckWindowPeriod" = "substring-before(substring-after(node:value(concat($pathMode,'/WdgWindowPeriod')),'TIME_'),'MS')"!]
        [!ENDIF!]
        [!VAR "CheckCloseWindowDutyCycle" = "text:replace(substring-after(node:value(concat($pathMode,'/WdgClosedWindowDutyCycle')),'DUTY_'),'_','.')"!]
        [!VAR "TimerClock" = "node:value(node:ref(./WdgSettingsConfig/WdgExternalTriggerCounterRef)/GptChannelTickFrequency)"!]
        [!VAR "CloseWindowSpan" = "num:f(num:f($CheckWindowPeriod) * num:f(num:f($CheckCloseWindowDutyCycle) div 100))"!]
        [!VAR "OpenWindowSpan"  = "num:f(num:f($CheckWindowPeriod) - num:f($CloseWindowSpan))"!]
        [!VAR "MiddleOpenWindowPoint" = "num:f(num:f($CloseWindowSpan) + num:f(num:f($OpenWindowSpan) div 2))"!]
[!ENDNOCODE!][!//
    /* The FS_I_WD_CFG configuration. */
    (((uint16)0x0000U)
        | PMIC_VR55XX_FS_I_WD_CFG_WD_ERR_LIMIT_U16((uint16)[!"num:i(num:negate(num:i((num:i(substring-after(node:value(./WdgSettingsConfig/WdgErrorCounterLimit),'MAX_')) - num:i(8)) div num:i(2))))"!]U)
        | PMIC_VR55XX_FS_I_WD_CFG_WD_RFR_LIMIT_U16((uint16)[!"num:i(num:negate(num:i((num:i(substring-after(node:value(./WdgSettingsConfig/WdgRefreshCounterLimit),'MAX_')) - num:i(7)) div num:i(2))))"!]U)
        | PMIC_VR55XX_FS_I_WD_CFG_WD_FS_IMPACT_U16(PMIC_VR55XX_FS_I_WD_CFG_WD_FS_IMPACT_[!"node:value(./WdgSettingsConfig/WdgErrorImpact)"!]_SELECT_U16)
    ),
    /* The FS_WD_WINDOW_DUR register configuration. */
    (((uint16)0x0000U)
        | PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_U16(PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_[!"substring-before($CheckCloseWindowDutyCycle,'.')"!]_[!"substring-after($CheckCloseWindowDutyCycle,'.')"!]_SELECT_U16)
        | PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_U16(PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_[!IF "node:value(./WdgSettingsConfig/WdgRecoveryWindowPeriod) = 'DISABLE'"!]DISABLE_SELECT_U16[!ELSE!][!"substring-after(node:value(./WdgSettingsConfig/WdgRecoveryWindowPeriod),'TIME_')"!]_SELECT_U16[!ENDIF!])
        | PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_U16([!IF "node:value(./WdgSettingsConfig/WdgWindowPeriodEnable) = 'false'"!]PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_DISABLE_SELECT_U16[!ELSE!]PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_[!"$CheckWindowPeriod"!]MS_SELECT_U16[!ENDIF!])
    ),
    /* The FS_WD_SEED configuration. */
    ((uint16)[!"num:inttohex(./WdgSettingsConfig/WdgServiceKeyValue)"!]U),
    /* The timer value */
    (uint32)[!"num:inttohex(num:f(num:f($MiddleOpenWindowPoint) * (num:i($TimerClock) div 1000)))"!]U
[!ENDMACRO!][!// WdgModeConfig
[!ENDNOCODE!][!//

[!NOCODE!]
/**
    @file    CDD_Pmic_RegOperations.m
    @version 4.0.2

    @brief   AUTOSAR Pmic - Register operations.
    @details Register operations.

    Project RTD AUTOSAR 4.4
    Platform CORTEXM
    Peripheral Pmic_VR55XX
    Dependencies MCU,DET,DEM,RTE,I2C,PORT,DIO,OCOTP

    ARVersion 4.4.0
    ARRevision ASR_REL_4_4_REV_0000
    ARConfVariant
    SWVersion 4.0.2
    BuildVersion S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630

    (c) Copyright 2020-2023 NXP Semiconductors
    All Rights Reserved.
 */

[!/* *** Multiple inclusion protection *** */!]
[!IF "not(var:defined('CDD_PMIC_REG_OPERATIONS_M'))"!][!//
[!VAR "CDD_PMIC_REG_OPERATIONS_M"="'true'"!][!//


[!MACRO "Pmic_Dem_Config","Type"!][!//
[!NOCODE!]
    [!VAR "PmicDemEventParameter"!]PMIC_E_ACESS_FAILURE,PMIC_E_INTEGRITY_CORRUPTED,PMIC_E_SIGNAL_SHORTED,PMIC_E_CLOCK_FAILURE,PMIC_E_TIMEOUT_FAILURE[!ENDVAR!]
    [!VAR "DemErrorCount" = "num:i(count(text:split($PmicDemEventParameter, ',')))"!]
    [!VAR "ConfigIndex" = "0"!]
[!CODE!]
/**
* @brief        DEM error reporting configuration
* @details      Set the state and id for Mcal_DemErrorType.
*/
const Pmic_DemConfigType Pmic_DemConfig =
{
[!ENDCODE!]
    [!FOR "Index" = "1" TO "num:i($DemErrorCount)"!]
        [!VAR "ErrorName" = "normalize-space(text:split($PmicDemEventParameter, ',')[num:i($Index)])"!]
        [!IF "node:exists(PmicGlobalConfig/PmicDemEventParameterRefs)"!]
            [!VAR "DemRefNode" = "concat('PmicGlobalConfig/PmicDemEventParameterRefs/',$ErrorName)"!]
            [!IF "node:exists($DemRefNode)"!]
                [!IF "node:refvalid($DemRefNode)"!]
[!CODE!]
    /* DEM error reporting [!"$ErrorName"!] */
    {(uint32)STD_ON, DemConf_DemEventParameter_[!"node:ref(node:value($DemRefNode))/@name"!]}[!IF "$Index < $DemErrorCount"!],[!ENDIF!]
[!ENDCODE!]
                [!ELSE!]
                     [!ERROR "Invalid reference for $ErrorName"!]
                [!ENDIF!]
            [!ELSE!]
[!CODE!]
    /* DEM error reporting [!"$ErrorName"!] */
    {(uint32)STD_OFF, 0U}[!IF "$Index < $DemErrorCount"!],[!ENDIF!]
[!ENDCODE!]
            [!ENDIF!]
        [!ELSE!]
[!CODE!]
    /* DEM error reporting [!"$ErrorName"!] */
    {(uint32)STD_OFF, 0U}[!IF "$Index < $DemErrorCount"!],[!ENDIF!]
[!ENDCODE!]
        [!ENDIF!]
    [!ENDFOR!]
[!CODE!]
};
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDMACRO!][!//Pmic_Dem_Config


[!MACRO "Pmic_ExportUserCallback"!][!//
[!NOCODE!][!//
[!IF "node:exists(PmicGeneralConfiguration/PmicWatchdogTaskNotification)"!]
[!CODE!][!//
/**
* @brief            Export the watchdog task callout function configured by the user.
*/
extern void [!"normalize-space(PmicGeneralConfiguration/PmicWatchdogTaskNotification)"!](const Pmic_DeviceIndexType u8DeviceId, const uint8 u8WdWindowValue, const uint8 u8WdDcValue);
[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!MACRO "Pmic_Mode_Config","Type"!][!//
[!NOCODE!][!//
[!IF "num:i(count(PmicGlobalConfig/PmicDevice/*)) > 0"!][!//
[!LOOP "PmicGlobalConfig/PmicDevice/*"!][!//
[!VAR "Deviceindex" = "@index"!][!//
[!LOOP "PmicModeSettingConf/*"!][!//
[!CODE!][!//
static const Pmic_VR55XX_ModeConfigType Pmic_VR55XX_ModeConfig[!"$Type"!]_[!"$Deviceindex"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* The ID for Mode configuration. */
    (uint8)[!"num:i(PmicModeID)"!],
    /* The selected target mode.*/
    PMIC_[!"text:toupper(PmicModeSelection)"!]_MODE,
    /* The M_MODE register configuration. */
    ((uint16)0x0000U)
[!IF "PmicPWRON2DeepSleepModeEnable = 'true'"!][!//
    | PMIC_VR55XX_M_MODE_PWRON2_DSM_EN_MASK16
[!ENDIF!][!//
[!IF "PmicPWRON1WakeUpEnable = 'false'"!][!//
    | PMIC_VR55XX_M_MODE_PWRON1DIS_MASK16
[!ENDIF!][!//
[!IF "PmicPWRON2WakeUpEnable = 'false'"!][!//
    | PMIC_VR55XX_M_MODE_PWRON2DIS_MASK16
[!ENDIF!][!//
    ,
    /* The M_SM_CTRL1 register configuration. */
    ((uint16)0x0000U)
[!IF "PmicStandbyTimerEnable = 'true'"!][!//
    | PMIC_VR55XX_M_SM_CTRL1_STBY_TIMER_EN_MASK16|PMIC_VR55XX_M_SM_CTRL1_TIMER_STBY_WINDOW_U16(PMIC_VR55XX_M_SM_CTRL1_TIMER_STBY_WINDOW_[!"text:replace(PmicStandbyTimerWindowDuration,'TIME_','')"!]_SELECT_U16)
[!ENDIF!][!//
    ,
    /* The M_REG_CTRL1 register configuration. */
    ((uint16)0x0000U)
[!IF "PmicModeSelection = 'NORMAL'"!][!//
[!IF "PmicRegulatorsConfiguration/PmicLdo3Regulator/PmicLdo3EnableRegulator != 'NO_EFFECT'"!][!//
[!IF "PmicRegulatorsConfiguration/PmicLdo3Regulator/PmicLdo3EnableRegulator = 'ENABLE'"!][!//
    | PMIC_VR55XX_M_REG_CTRL1_LDO3EN_MASK16
[!ELSE!][!//
    | PMIC_VR55XX_M_REG_CTRL1_LDO3DIS_MASK16
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "PmicRegulatorsConfiguration/PmicLdo2Regulator/PmicLdo2EnableRegulator != 'NO_EFFECT'"!][!//
[!IF "PmicRegulatorsConfiguration/PmicLdo2Regulator/PmicLdo2EnableRegulator = 'ENABLE'"!][!//
    | PMIC_VR55XX_M_REG_CTRL1_LDO2EN_MASK16
[!ELSE!][!//
    | PMIC_VR55XX_M_REG_CTRL1_LDO2DIS_MASK16
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "PmicRegulatorsConfiguration/PmicLdo1Regulator/PmicLdo1EnableRegulator != 'NO_EFFECT'"!][!//
[!IF "PmicRegulatorsConfiguration/PmicLdo1Regulator/PmicLdo1EnableRegulator = 'ENABLE'"!][!//
    | PMIC_VR55XX_M_REG_CTRL1_LDO1EN_MASK16
[!ELSE!][!//
    | PMIC_VR55XX_M_REG_CTRL1_LDO1DIS_MASK16
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "PmicRegulatorsConfiguration/PmicBuck3Regulator/PmicBuck3EnableRegulator != 'NO_EFFECT'"!][!//
[!IF "PmicRegulatorsConfiguration/PmicBuck3Regulator/PmicBuck3EnableRegulator = 'ENABLE'"!][!//
    | PMIC_VR55XX_M_REG_CTRL1_BUCK3EN_MASK16
[!ELSE!][!//
    | PMIC_VR55XX_M_REG_CTRL1_BUCK3DIS_MASK16
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "PmicRegulatorsConfiguration/PmicBuck2Regulator/PmicBuck2EnableRegulator != 'NO_EFFECT'"!][!//
[!IF "PmicRegulatorsConfiguration/PmicBuck2Regulator/PmicBuck2EnableRegulator = 'ENABLE'"!][!//
    | PMIC_VR55XX_M_REG_CTRL1_BUCK2EN_MASK16
[!ELSE!][!//
    | PMIC_VR55XX_M_REG_CTRL1_BUCK2DIS_MASK16
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "PmicRegulatorsConfiguration/PmicBuck1Regulator/PmicBuck1EnableRegulator != 'NO_EFFECT'"!][!//
[!IF "PmicRegulatorsConfiguration/PmicBuck1Regulator/PmicBuck1EnableRegulator = 'ENABLE'"!][!//
    | PMIC_VR55XX_M_REG_CTRL1_BUCK1EN_MASK16
[!ELSE!][!//
    | PMIC_VR55XX_M_REG_CTRL1_BUCK1DIS_MASK16
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "PmicRegulatorsConfiguration/PmicVpreRegulator/PmicVpreEnableRegulator != 'NO_EFFECT'"!][!//
[!IF "PmicRegulatorsConfiguration/PmicVpreRegulator/PmicVpreEnableRegulator = 'ENABLE'"!][!//
    | PMIC_VR55XX_M_REG_CTRL1_VPREEN_MASK16
[!ELSE!][!//
    | PMIC_VR55XX_M_REG_CTRL1_VPREDIS_MASK16
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "PmicRegulatorsConfiguration/PmicVBoostRegulator/PmicBoostEnableRegulator != 'NO_EFFECT'"!][!//
[!IF "PmicRegulatorsConfiguration/PmicVBoostRegulator/PmicBoostEnableRegulator = 'ENABLE'"!][!//
    | PMIC_VR55XX_M_REG_CTRL1_BOOSTEN_MASK16
[!ELSE!][!//
    | PMIC_VR55XX_M_REG_CTRL1_BOOSTDIS_MASK16
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
    ,
    /* The M_REG_CTRL2 register configuration. */
    ((uint16)0x0000U)
[!IF "PmicModeSelection = 'NORMAL'"!][!//
[!IF "PmicRegulatorsConfiguration/PmicHVLdoRegulator/PmicHVLdoEnableRegulator != 'NO_EFFECT'"!][!//
[!IF "PmicRegulatorsConfiguration/PmicHVLdoRegulator/PmicHVLdoEnableRegulator = 'ENABLE'"!][!//
    | PMIC_VR55XX_M_REG_CTRL2_HVLDOEN_MASK16
[!ELSE!]
    | PMIC_VR55XX_M_REG_CTRL2_HVLDODIS_MASK16
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
    | PMIC_VR55XX_M_REG_CTRL2_VPRESRHS_U16(PMIC_VR55XX_M_REG_CTRL2_VPRESRHS_[!"substring-after(PmicRegulatorsConfiguration/PmicVpreRegulator/PmicVpreHsCurrentCapability,'I_')"!]_SELECT_U16)
    | PMIC_VR55XX_M_REG_CTRL2_VPRESRLS_U16(PMIC_VR55XX_M_REG_CTRL2_VPRESRLS_[!"substring-after(PmicRegulatorsConfiguration/PmicVpreRegulator/PmicVpreLsCurrentCapability,'I_')"!]_SELECT_U16)
    | PMIC_VR55XX_M_REG_CTRL2_VBSTSR_U16(PMIC_VR55XX_M_REG_CTRL2_VBSTSR_[!"substring-after(PmicRegulatorsConfiguration/PmicVBoostRegulator/PmicBoostSlewRate,'RATE_')"!]_SELECT_U16)
    ,
    /* The M_REG_CTRL3 register configuration. */
    ((uint16)0x0000U)
[!IF "PmicModeSelection = 'STANDBY'"!][!//
[!IF "PmicRegulatorsConfiguration/PmicBuck3Regulator/PmicBuck3StandbyEnableRegulator = 'true'"!][!//
    | PMIC_VR55XX_M_REG_CTRL3_BUCK3_STBY_MASK16
[!ENDIF!][!//
[!IF "PmicRegulatorsConfiguration/PmicBuck2Regulator/PmicBuck2StandbyEnableRegulator = 'true'"!][!//
    | PMIC_VR55XX_M_REG_CTRL3_BUCK2_STBY_MASK16
[!ENDIF!][!//
[!IF "PmicRegulatorsConfiguration/PmicBuck1Regulator/PmicBuck1StandbyEnableRegulator = 'true'"!][!//
    | PMIC_VR55XX_M_REG_CTRL3_BUCK1_STBY_MASK16
[!ENDIF!][!//
[!IF "PmicRegulatorsConfiguration/PmicVpreRegulator/PmicVpreStandbyOutputVoltage = 'OUT_3V0'"!][!//
    | PMIC_VR55XX_M_REG_CTRL3_VPREV_STBY_MASK16
[!ENDIF!][!//
[!IF "PmicRegulatorsConfiguration/PmicHVLdoRegulator/PmicHVLdoStandbyEnableRegulator = 'true'"!][!//
    | PMIC_VR55XX_M_REG_CTRL3_HVLDO_STBY_MASK16
[!ENDIF!][!//
[!IF "PmicRegulatorsConfiguration/PmicLdo1Regulator/PmicLdo1StandbyEnableRegulator = 'true'"!][!//
    | PMIC_VR55XX_M_REG_CTRL3_LDO1_STBY_MASK16
[!ENDIF!][!//
[!IF "PmicRegulatorsConfiguration/PmicLdo2Regulator/PmicLdo2StandbyEnableRegulator = 'true'"!][!//
    | PMIC_VR55XX_M_REG_CTRL3_LDO2_STBY_MASK16
[!ENDIF!][!//
[!IF "PmicRegulatorsConfiguration/PmicLdo3Regulator/PmicLdo3StandbyEnableRegulator = 'true'"!][!//
    | PMIC_VR55XX_M_REG_CTRL3_LDO3_STBY_MASK16
[!ENDIF!][!//
[!ENDIF!][!//
    ,
    /* The M_VMON_REGx register configuration. */
    ((uint16)0x0000U)
    | PMIC_VR55XX_M_VMON_REGx_VMON1_REG_ASSIGN_U16(PMIC_VR55XX_M_VMON_REGx_VMON_1_REG_ASSIGN_[!"PmicVMONConfiguration/PmicVMON1RegulatorAssignment"!]_SELECT_U16)
    | PMIC_VR55XX_M_VMON_REGx_VMON2_REG_ASSIGN_U16(PMIC_VR55XX_M_VMON_REGx_VMON_2_REG_ASSIGN_[!"PmicVMONConfiguration/PmicVMON2RegulatorAssignment"!]_SELECT_U16)
    | PMIC_VR55XX_M_VMON_REGx_VMON3_REG_ASSIGN_U16(PMIC_VR55XX_M_VMON_REGx_VMON_3_REG_ASSIGN_[!"PmicVMONConfiguration/PmicVMON3RegulatorAssignment"!]_SELECT_U16)
    | PMIC_VR55XX_M_VMON_REGx_VMON4_REG_ASSIGN_U16(PMIC_VR55XX_M_VMON_REGx_VMON_4_REG_ASSIGN_[!"PmicVMONConfiguration/PmicVMON4RegulatorAssignment"!]_SELECT_U16)
};
[!ENDCODE!][!//
[!ENDLOOP!][!//"PmicModeSettingConf/*"
[!ENDLOOP!][!//"PmicGlobalConfig/PmicDevice/*"
[!ENDIF!][!//"num:i(count(PmicGlobalConfig/PmicDevice/*)) > 0"
[!ENDNOCODE!][!//
[!ENDMACRO!][!//Pmic_Mode_Config

[!MACRO "Pmic_Clock_Config","Type"!][!//
[!NOCODE!][!//
    [!IF "num:i(count(PmicGlobalConfig/PmicDevice/*)) > 0"!][!//
    [!LOOP "PmicGlobalConfig/PmicDevice/*"!][!//
        [!VAR "Deviceindex" = "@index"!][!//
        [!LOOP "PmicClockSettingConfig/*"!][!//
[!CODE!][!//
static const Pmic_VR55XX_ClockConfigType Pmic_VR55XX_ClockConfig[!"$Type"!]_[!"$Deviceindex"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* The ID for clock configuration. */
    (uint8)[!"num:i(PmicClockSettingId)"!],
    /* External FIN selection at PLL input */
    [!IF "PmicFinEnable = 'true'"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!],    /* The M_CLOCK1 register configuration. */
    ((uint16)0x0000U)
    | PMIC_VR55XX_M_CLOCK1_CLK_INT_FREQ_U16(PMIC_VR55XX_M_CLOCK1_CLK_INT_FREQ_[!"substring-after(PmicIrcoscFrequencyHz,'F_')"!]_SELECT_U16)
[!IF "PmicSpectrumModulationEnable = 'true'"!][!//
    | PMIC_VR55XX_M_CLOCK1_MOD_EN_MASK16
[!ENDIF!][!//
[!IF "num:f(PmicExternalPIN_Fin_FrequencyHz) >= num:f(2000000)"!][!//
    | PMIC_VR55XX_M_CLOCK1_FIN_DIV_MASK16
[!ENDIF!][!//
[!IF "PmicPllClockSelection = 'FIN_CLK'"!][!//
    | PMIC_VR55XX_M_CLOCK1_EXT_FIN_SEL_MASK16
[!ENDIF!][!//
[!IF "PmicFoutClockSelection = 'CLK2'"!][!//
    | PMIC_VR55XX_M_CLOCK1_FOUT_SEL_MASK16
[!ENDIF!][!//
    | PMIC_VR55XX_M_CLOCK1_FOUT_PHASE_U16((uint16)[!"num:i(PmicFoutPhaseDelay)"!]U)
    | PMIC_VR55XX_M_CLOCK1_FOUT_MUX_SEL_U16(PMIC_VR55XX_M_CLOCK1_FOUT_MUX_SEL_[!"PmicFoutMuxSelection"!]_SELECT_U16)
[!IF "PmicTriangularCarrierFrequencyHz = 'F_92600'"!][!//
    |PMIC_VR55XX_M_CLOCK1_MOD_CONF_MASK16
[!ENDIF!][!//
    ,
    /* The M_CLOCK2 register configuration. */
    ((uint16)0x0000U)
    | PMIC_VR55XX_M_CLOCK2_LOW_POWER_CLK_U16(PMIC_VR55XX_M_CLOCK2_LOW_POWER_CLK_[!"substring-after(PmicLowPowerOscFrequencyHz,'F_')"!]_SELECT_U16)
};
[!ENDCODE!][!//
        [!ENDLOOP!][!//"PmicClockSettingConfig/*"
    [!ENDLOOP!][!//"PmicGlobalConfig/PmicDevice/*"
    [!ENDIF!][!//"num:i(count(PmicGlobalConfig/PmicDevice/*)) > 0"
[!ENDNOCODE!][!//
[!ENDMACRO!][!//Pmic_Clock_Config


[!MACRO "Pmic_Reaction_Config","Type"!][!//
[!NOCODE!][!//
    [!IF "num:i(count(PmicGlobalConfig/PmicDevice/*)) > 0"!][!//
    [!LOOP "PmicGlobalConfig/PmicDevice/*"!][!//
        [!VAR "Deviceindex" = "@index"!][!//
        [!LOOP "PmicReactionsSettingConf/*"!][!//
[!CODE!][!//
static const Pmic_VR55XX_ReactionConfigType Pmic_VR55XX_ReactionConfig[!"$Type"!]_[!"$Deviceindex"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* The ID for Reaction configuration. */
    (uint8)[!"num:i(PmicReactionsSettingId)"!]
    ,
    /* The M_INT_MASK1 register configuration.*/
    ((uint16)0x0000U)
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicLdo3TempShutdownIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK1_LDO3_TSDFLG_M_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicLdo2TempShutdownIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK1_LDO2_TSDFLG_M_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicLdo1TempShutdownIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK1_LDO1_TSDFLG_M_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicBuck3TempShutdownIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK1_BUCK3_TSDFLG_M_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicBuck2TempShutdownIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK1_BUCK2_TSDFLG_M_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicBuck1TempShutdownIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK1_BUCK1_TSDFLG_M_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicBoostTempShutdownIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK1_BOOST_TSDFLG_M_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicHvldoTempShutdownIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK1_HVLDO_TSDFLG_M_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicLdo3OverCurrentIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK1_LDO3OC_M_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicLdo2OverCurrentIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK1_LDO2OC_M_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicLdo1OverCurrentIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK1_LDO1OC_M_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicBuck3OverCurrentIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK1_BUCK3OC_M_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicBuck2OverCurrentIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK1_BUCK2OC_M_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicBuck1OverCurrentIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK1_BUCK1OC_M_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicHvldoOverCurrentIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK1_HVLDOOC_M_MASK16
[!ENDIF!][!//
    ,
    /* The M_INT_MASK2 register configuration.*/
    ((uint16)0x0000U)
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicPwron1TransitionIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK2_PWRON1FLG_M_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicPwron2TransitionIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK2_PWRON2FLG_M_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicVsupUndervoltageHighIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK2_VSUPUVH_M_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicVsupUndervoltageLowIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK2_VSUPUVL_M_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicVsupUndervoltage7VIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK2_VSUPUV7_M_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicVpreUndervoltageHighIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK2_VPREUVH_M_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicVpreUndervoltageLowIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK2_VPREUVL_M_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicVpreOvercurrentIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK2_VPREOC_M_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicVpreOvervoltageIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK2_VPREOV2_M_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicHvldoInputUndervoltageLowIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK2_HVLDO_INPUT_UVL_M_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicBistTempShutdownIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK2_TSD_BIST_ERR_FLG_M_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicBoostOvervoltageHighIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK2_VBOOSTOV_M_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicBoostUndervoltageHighIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK2_VBOOSTUVH_M_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicBosUndervoltageHighIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK2_VBOSUVH_M_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicCommunicationErrorIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK2_COM_ERR_M_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainInterruptMasks/PmicCenterDieTempIntDisable = 'true'"!][!//
    | PMIC_VR55XX_M_INT_MASK2_DIE_CENTER_TEMPFLG_M_MASK16
[!ENDIF!][!//
    ,
    /* The M_TSD_CFG register configuration.*/
    ((uint16)0x0000U)
[!IF "PmicMainUnitReactionsConf/PmicMainThermalShutdownBehaviors/PmicLHVLdoTsdBehavior = 'SHUTDOWN_AND_DFS'"!][!//
    | PMIC_VR55XX_M_TSD_CFG_HVLDO_TSDCFG_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainThermalShutdownBehaviors/PmicLdo3TsdBehavior = 'SHUTDOWN_AND_DFS'"!][!//
    | PMIC_VR55XX_M_TSD_CFG_LDO3_TSDCFG_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainThermalShutdownBehaviors/PmicLdo2TsdBehavior = 'SHUTDOWN_AND_DFS'"!][!//
    | PMIC_VR55XX_M_TSD_CFG_LDO2_TSDCFG_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainThermalShutdownBehaviors/PmicLdo1TsdBehavior = 'SHUTDOWN_AND_DFS'"!][!//
    | PMIC_VR55XX_M_TSD_CFG_LDO1_TSDCFG_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainThermalShutdownBehaviors/PmicBuck3TsdBehavior = 'SHUTDOWN_AND_DFS'"!][!//
    | PMIC_VR55XX_M_TSD_CFG_BUCK3_TSDCFG_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainThermalShutdownBehaviors/PmicBuck2TsdBehavior = 'SHUTDOWN_AND_DFS'"!][!//
    | PMIC_VR55XX_M_TSD_CFG_BUCK2_TSDCFG_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainThermalShutdownBehaviors/PmicBuck1TsdBehavior = 'SHUTDOWN_AND_DFS'"!][!//
    | PMIC_VR55XX_M_TSD_CFG_BUCK1_TSDCFG_MASK16
[!ENDIF!][!//
[!IF "PmicMainUnitReactionsConf/PmicMainThermalShutdownBehaviors/PmicBoostTsdBehavior = 'SHUTDOWN_AND_DFS'"!][!//
    | PMIC_VR55XX_M_TSD_CFG_BOOST_TSDCFG_MASK16
[!ENDIF!][!//
    | PMIC_VR55XX_M_TSD_CFG_DIE_CENTER_TEMP_U16(PMIC_VR55XX_M_TSD_CFG_DIE_CENTER_TEMP_[!"substring-after(substring-before(PmicMainUnitReactionsConf/PmicMainThermalShutdownBehaviors/PmicCenterDieTempThreshold,'_oC'),'TEMP_')"!]_SELECT_U16)
    ,
    /* The FS_INTB_MASK register configuration.*/
    ((uint16)0x0000U)
[!IF "PmicFailSafeUnitReactionsConf/PmicFailSafeInterruptMasks/PmicFccu1EventIntDisable = 'true'"!][!//
    | PMIC_VR55XX_FS_INTB_MASK_INT_INH_FCCU1_MASK16
[!ENDIF!][!//
[!IF "PmicFailSafeUnitReactionsConf/PmicFailSafeInterruptMasks/PmicFccu2EventIntDisable = 'true'"!][!//
    | PMIC_VR55XX_FS_INTB_MASK_INT_INH_FCCU2_MASK16
[!ENDIF!][!//
[!IF "PmicFailSafeUnitReactionsConf/PmicFailSafeInterruptMasks/PmicHvldoOverUnderVoltageIntDisable = 'true'"!][!//
    | PMIC_VR55XX_FS_INTB_MASK_INT_INH_HVLDO_VMON_OV_UV_MASK16
[!ENDIF!][!//
[!IF "PmicFailSafeUnitReactionsConf/PmicFailSafeInterruptMasks/PmicWatchdogBadRefreshIntDisable = 'true'"!][!//
    | PMIC_VR55XX_FS_INTB_MASK_INT_INH_BAD_WD_REFRESH_MASK16
[!ENDIF!][!//
[!IF "PmicFailSafeUnitReactionsConf/PmicFailSafeInterruptMasks/PmicVcoremonOverUnderVoltageIntDisable = 'true'"!][!//
    | PMIC_VR55XX_FS_INTB_MASK_INT_INH_VCOREMON_OV_UV_MASK16
[!ENDIF!][!//
[!IF "PmicFailSafeUnitReactionsConf/PmicFailSafeInterruptMasks/PmicVddioOverUnderVoltageIntDisable = 'true'"!][!//
    | PMIC_VR55XX_FS_INTB_MASK_INT_INH_VDDIO_OV_UV_MASK16
[!ENDIF!][!//
[!IF "PmicFailSafeUnitReactionsConf/PmicFailSafeInterruptMasks/PmicVmon1OverUnderVoltageIntDisable = 'true'"!][!//
    | PMIC_VR55XX_FS_INTB_MASK_INT_INH_VMON1_OV_UV_MASK16
[!ENDIF!][!//
[!IF "PmicFailSafeUnitReactionsConf/PmicFailSafeInterruptMasks/PmicVmon2OverUnderVoltageIntDisable = 'true'"!][!//
    | PMIC_VR55XX_FS_INTB_MASK_INT_INH_VMON2_OV_UV_MASK16
[!ENDIF!][!//
[!IF "PmicFailSafeUnitReactionsConf/PmicFailSafeInterruptMasks/PmicVmon3OverUnderVoltageIntDisable = 'true'"!][!//
    | PMIC_VR55XX_FS_INTB_MASK_INT_INH_VMON3_OV_UV_MASK16
[!ENDIF!][!//
[!IF "PmicFailSafeUnitReactionsConf/PmicFailSafeInterruptMasks/PmicVmon4OverUnderVoltageIntDisable = 'true'"!][!//
    | PMIC_VR55XX_FS_INTB_MASK_INT_INH_VMON4_OV_UV_MASK16
[!ENDIF!][!//
};
[!ENDCODE!]
        [!ENDLOOP!][!//"PmicReactionsSettingConf/*"
    [!ENDLOOP!][!//"PmicGlobalConfig/PmicDevice/*"
    [!ENDIF!][!//"num:i(count(PmicGlobalConfig/PmicDevice/*)) > 0"
[!ENDNOCODE!]
[!ENDMACRO!][!//Pmic_Reaction_Config



[!MACRO "Pmic_Amux_Config","Type"!][!//
[!NOCODE!][!//
    [!IF "num:i(count(PmicGlobalConfig/PmicDevice/*)) > 0"!][!//
    [!LOOP "PmicGlobalConfig/PmicDevice/*"!][!//
            [!VAR "Deviceindex" = "@index"!][!//
            [!IF "num:i(count(PmicAMUXConfiguration/PmicAmuxChannel/*)) > 0"!][!//
[!CODE!][!//
#if (STD_ON == PMIC_SET_ANALOG_MUX_API)
[!ENDCODE!][!//
            [!LOOP "PmicAMUXConfiguration/PmicAmuxChannel/*"!][!//
[!CODE!]
static const Pmic_VR55XX_AmuxChannelConfigType Pmic_VR55XX_AmuxConfig[!"$Type"!]_[!"$Deviceindex"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* The ID for Amux configuration. */
    (uint8)[!"num:i(PmicAmuxChannelId)"!],
    /* The M_AMUX register configuration. */
    ((uint16)0x0000U)
    | PMIC_VR55XX_M_AMUX_AMUX_U16(PMIC_VR55XX_M_AMUX_AMUX_[!"PmicAmuxChannelSelect"!]_SELECT_U16)
[!IF "PmicAmuxRatio = 'RATIO_34'"!][!//
    | PMIC_VR55XX_M_AMUX_RATIO_MASK16
[!ENDIF!][!//
};
[!ENDCODE!][!//
            [!ENDLOOP!][!//"PmicAMUXConfiguration/PmicAmuxChannel/*"
[!CODE!][!//
#endif
[!ENDCODE!][!//
            [!ENDIF!][!//
    [!ENDLOOP!][!//"PmicGlobalConfig/PmicDevice/*"
    [!ENDIF!][!//"num:i(count(PmicGlobalConfig/PmicDevice/*)) > 0"
[!ENDNOCODE!]
[!ENDMACRO!][!//Pmic_Amux_Config

[!MACRO "Pmic_SVS_Config","Type"!][!//
[!NOCODE!][!//
    [!IF "num:i(count(PmicGlobalConfig/PmicDevice/*)) > 0"!][!//
    [!LOOP "PmicGlobalConfig/PmicDevice/*"!][!//
        [!IF "num:i(count(PmicFailSafeConfiguration/PmicSVSConfiguration/PmicSVSSettingConf/*)) > 0"!][!//
[!CODE!][!//
#if (STD_ON == PMIC_SWITCH_SVS_API)
[!ENDCODE!][!//
        [!VAR "Deviceindex" = "@index"!]
        [!LOOP "PmicFailSafeConfiguration/PmicSVSConfiguration/PmicSVSSettingConf/*"!]
[!CODE!]
static const Pmic_VR55XX_SVSConfigType Pmic_VR55XX_SVSConfig[!"$Type"!]_[!"$Deviceindex"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* The ID for SVS configuration. */
    (uint8)[!"num:i(PmicSVSSettingId)"!],
    /* The FS_I_SVS register configuration. */
    ((uint16)0x0000U)
[!IF "PmicSVSOffsetSignSetting = 'POSITIVE_OFFSET'"!][!//
    |PMIC_VR55XX_FS_I_SVS_SVS_OFFSET_SIGN_MASK16
[!ENDIF!][!//
    | PMIC_VR55XX_FS_I_SVS_SVS_OFFSET_U16((uint16)[!"num:i(num:div(text:replace(substring-after(PmicSVSOffsetSetting,'OFFSET_'),'_','.'),'6.25'))"!]U)
};
[!ENDCODE!][!//
        [!ENDLOOP!][!//""PmicFailSafeConfiguration/PmicSVSConfiguration/PmicSVSSettingConf/*"
[!CODE!][!//
#endif
[!ENDCODE!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//"PmicGlobalConfig/PmicDevice/*"
    [!ENDIF!][!//"num:i(count(PmicGlobalConfig/PmicDevice/*)) > 0"
[!ENDNOCODE!][!//
[!ENDMACRO!][!//Pmic_SVS_Config

[!MACRO "Pmic_Watchdog_Config","Type"!][!//
[!NOCODE!][!//
    [!IF "num:i(count(PmicGlobalConfig/PmicDevice/*)) > 0"!][!//
[!CODE!]
#if (STD_ON == PMIC_WATCHDOG_API)
[!ENDCODE!][!//
    [!LOOP "PmicGlobalConfig/PmicDevice/*"!][!//
        [!IF "PmicFailSafeConfiguration/PmicWatchdogConfiguration/PmicWatchdogApi = 'true'"!][!//
        [!VAR "Deviceindex" = "@index"!][!//
        [!LOOP "PmicFailSafeConfiguration/PmicWatchdogConfiguration/PmicWatchdogSettingConf/*"!][!//
[!CODE!]
static const Pmic_VR55XX_WatchdogConfigType Pmic_VR55XX_WatchdogConfig[!"$Type"!]_[!"$Deviceindex"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* The ID for watchdog configuration. */
    (uint8)[!"num:i(PmicWatchdogSettingId)"!],
    /* The FS_WD_WINDOW_DUR register configuration. */
    ((uint16)0x0000U)
    | PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_U16(PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_[!"substring-after(PmicWatchdogClosedWindowDutyCycle,'DUTY_')"!]_SELECT_U16)
    | PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_U16(PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_[!"substring-after(PmicWatchdogWindowPeriod,'TIME_')"!]_SELECT_U16)
    | PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_U16(PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_[!IF "node:value(../../PmicWatchdogRecoveryWindowPeriod) = 'DISABLE'"!]DISABLE[!ELSE!][!"substring-after(../../PmicWatchdogRecoveryWindowPeriod,'TIME_')"!][!ENDIF!]_SELECT_U16)
};
[!ENDCODE!][!//
        [!ENDLOOP!][!//"PmicFailSafeConfiguration/PmicWatchdogConfiguration/PmicWatchdogSettingConf/*"
        [!ENDIF!][!//"PmicFailSafeConfiguration/PmicWatchdogConfiguration/PmicWatchdogApi = 'true'"
    [!ENDLOOP!][!//"PmicGlobalConfig/PmicDevice/*"
[!CODE!][!//
#endif
[!ENDCODE!][!//
    [!ENDIF!][!//"num:i(count(PmicGlobalConfig/PmicDevice/*)) > 0"
[!ENDNOCODE!][!//
[!ENDMACRO!][!//Pmic_Watchdog_Config


[!MACRO "Pmic_Init_Config","Type"!][!//
[!NOCODE!][!//
    [!IF "num:i(count(PmicGlobalConfig/PmicDevice/*)) > 0"!][!//
    [!LOOP "PmicGlobalConfig/PmicDevice/*"!][!//
[!CODE!]
static const Pmic_VR55XX_InitConfigType Pmic_VR55XX_InitConfig[!"$Type"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
[!ENDCODE!][!//
[!CODE!][!//
    /* The FS_I_SVS register configuration. */
    ((uint16)0x0000U)
[!IF "PmicFailSafeConfiguration/PmicSVSConfiguration/PmicSVSOffsetSign = 'POSITIVE_OFFSET'"!][!//
    | PMIC_VR55XX_FS_I_SVS_SVS_OFFSET_SIGN_MASK16
[!ENDIF!][!//
    | PMIC_VR55XX_FS_I_SVS_SVS_OFFSET_U16((uint16)[!"num:i(num:div(text:replace(substring-after(PmicFailSafeConfiguration/PmicSVSConfiguration/PmicSVSOffset,'OFFSET_'),'_','.'),'6.25'))"!]U)
    ,

    /* The FS_I_OVUV_SAFE_REACTION1 register configuration. */
    ((uint16)0x0000U)
    | PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_VDDIO_UV_U16(PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_[!"PmicFailSafeConfiguration/PmicFailSafePinReactions/PmicVddioUndervoltageImpact"!]_SELECT_U16)
    | PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_VDDIO_OV_U16(PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_[!"PmicFailSafeConfiguration/PmicFailSafePinReactions/PmicVddioOvervoltageImpact"!]_SELECT_U16)
    | PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_HVLDO_VMON_UV_U16(PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_[!"PmicFailSafeConfiguration/PmicFailSafePinReactions/PmicHvldoUndervoltageImpact"!]_SELECT_U16)
    | PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_HVLDO_VMON_OV_U16(PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_[!"PmicFailSafeConfiguration/PmicFailSafePinReactions/PmicHvldoOvervoltageImpact"!]_SELECT_U16)
    | PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_VCOREMON_UV_U16(PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_[!"PmicFailSafeConfiguration/PmicFailSafePinReactions/PmicVcoremonUndervoltageImpact"!]_SELECT_U16)
    | PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_VCOREMON_OV_U16(PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_[!"PmicFailSafeConfiguration/PmicFailSafePinReactions/PmicVcoremonOvervoltageImpact"!]_SELECT_U16)
    ,

    /* The FS_I_OVUV_SAFE_REACTION2 register configuration. */
    ((uint16)0x0000U)
    | PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON1_UV_U16(PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_[!"PmicFailSafeConfiguration/PmicFailSafePinReactions/PmicVmon1UndervoltageImpact"!]_SELECT_U16)
    | PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON1_OV_U16(PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_[!"PmicFailSafeConfiguration/PmicFailSafePinReactions/PmicVmon1OvervoltageImpact"!]_SELECT_U16)
    | PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON2_UV_U16(PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_[!"PmicFailSafeConfiguration/PmicFailSafePinReactions/PmicVmon2UndervoltageImpact"!]_SELECT_U16)
    | PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON2_OV_U16(PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_[!"PmicFailSafeConfiguration/PmicFailSafePinReactions/PmicVmon2OvervoltageImpact"!]_SELECT_U16)
    | PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON3_UV_U16(PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_[!"PmicFailSafeConfiguration/PmicFailSafePinReactions/PmicVmon3UndervoltageImpact"!]_SELECT_U16)
    | PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON3_OV_U16(PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_[!"PmicFailSafeConfiguration/PmicFailSafePinReactions/PmicVmon3OvervoltageImpact"!]_SELECT_U16)
    | PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON4_UV_U16(PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_[!"PmicFailSafeConfiguration/PmicFailSafePinReactions/PmicVmon4UndervoltageImpact"!]_SELECT_U16)
    | PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON4_OV_U16(PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_[!"PmicFailSafeConfiguration/PmicFailSafePinReactions/PmicVmon4OvervoltageImpact"!]_SELECT_U16)
    ,

    /* The FS_I_WD_CFG configuration. */
    ((uint16)0x0000U)
    | PMIC_VR55XX_FS_I_WD_CFG_WD_ERR_LIMIT_U16((uint16)[!"num:i(num:negate(num:i((num:i(substring-after(PmicFailSafeConfiguration/PmicWatchdogConfiguration/PmicWatchdogErrorCounterLimit,'MAX_')) - num:i(8)) div num:i(2))))"!]U)
    | PMIC_VR55XX_FS_I_WD_CFG_WD_RFR_LIMIT_U16((uint16)[!"num:i(num:negate(num:i((num:i(substring-after(PmicFailSafeConfiguration/PmicWatchdogConfiguration/PmicWatchdogRefreshCounterLimit,'MAX_')) - num:i(7)) div num:i(2))))"!]U)
    | PMIC_VR55XX_FS_I_WD_CFG_WD_FS_IMPACT_U16(PMIC_VR55XX_FS_I_WD_CFG_WD_FS_IMPACT_[!"PmicFailSafeConfiguration/PmicWatchdogConfiguration/PmicWatchdogErrorImpact"!]_SELECT_U16)
    ,

    /* The FS_WD_WINDOW_DUR configuration. */
[!NOCODE!][!//
    [!IF "PmicFailSafeConfiguration/PmicWatchdogConfiguration/PmicWatchdogApi = 'true'"!][!//
    [!IF "PmicFailSafeConfiguration/PmicWatchdogConfiguration/PmicWatchdogWindowPeriodEnable = 'false'"!][!//
[!CODE!][!//
    ((uint16)0x0000U)
    | PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_U16(PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_DISABLE_SELECT_U16)
    | PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_U16(PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_50_0_SELECT_U16)
    | PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_U16(PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_[!IF "node:value(PmicFailSafeConfiguration/PmicWatchdogConfiguration/PmicWatchdogRecoveryWindowPeriod) = 'DISABLE'"!]DISABLE[!ELSE!][!"substring-after(PmicFailSafeConfiguration/PmicWatchdogConfiguration/PmicWatchdogRecoveryWindowPeriod,'TIME_')"!][!ENDIF!]_SELECT_U16)
[!ENDCODE!][!//
    [!ELSE!][!//
        [!VAR "Wdw_dc" = "node:value(PmicFailSafeConfiguration/PmicWatchdogConfiguration/PmicWatchdogClosedWindowDutyCycle_Setting)"!][!//
        [!VAR "Wdw_pe" = "node:value(PmicFailSafeConfiguration/PmicWatchdogConfiguration/PmicWatchdogWindowPeriod_Setting)"!][!//
[!CODE!][!//
    ((uint16)0x0000U)
    | PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_U16(PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_[!"substring-after($Wdw_dc,'DUTY_')"!]_SELECT_U16)
    | PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_U16(PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_[!"substring-after($Wdw_pe,'TIME_')"!]_SELECT_U16)
    | PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_U16(PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_[!IF "node:value(PmicFailSafeConfiguration/PmicWatchdogConfiguration/PmicWatchdogRecoveryWindowPeriod) = 'DISABLE'"!]DISABLE[!ELSE!][!"substring-after(PmicFailSafeConfiguration/PmicWatchdogConfiguration/PmicWatchdogRecoveryWindowPeriod,'TIME_')"!][!ENDIF!]_SELECT_U16)
[!ENDCODE!][!//
    [!ENDIF!][!//
    [!ELSE!][!//
[!CODE!][!//
    ((uint16)0x0000U)
    | PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_U16(PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_DISABLE_SELECT_U16)
    | PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_U16(PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_50_0_SELECT_U16)
    | PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_U16(PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_[!IF "node:value(PmicFailSafeConfiguration/PmicWatchdogConfiguration/PmicWatchdogRecoveryWindowPeriod) = 'DISABLE'"!]DISABLE[!ELSE!][!"substring-after(PmicFailSafeConfiguration/PmicWatchdogConfiguration/PmicWatchdogRecoveryWindowPeriod,'TIME_')"!][!ENDIF!]_SELECT_U16)
[!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//
    ,
    /* The FS_WD_SEED configuration. */
    ((uint16)[!"num:inttohex(PmicFailSafeConfiguration/PmicWatchdogConfiguration/PmicWatchdogSeed)"!]U)
    ,
    /* The FS_I_ABIST2_CTRL configuration. */
    ((uint16)0x0000U)
[!IF "PmicFailSafeConfiguration/PmicABIST2Configuration/PmicVddioMonitorABIST2Enable = 'true'"!][!//
    | PMIC_VR55XX_FS_I_ABIST2_CTRL_VDDIO_ABIST2_MASK16
[!ENDIF!][!//
[!IF "PmicFailSafeConfiguration/PmicABIST2Configuration/PmicVcoreMonitorABIST2Enable = 'true'"!][!//
    | PMIC_VR55XX_FS_I_ABIST2_CTRL_VCORE_ABIST2_MASK16
[!ENDIF!][!//
[!IF "PmicFailSafeConfiguration/PmicABIST2Configuration/PmicHVLdoMonitorABIST2Enable = 'true'"!][!//
    | PMIC_VR55XX_FS_I_ABIST2_CTRL_HVLDO_VMON_ABIST2_MASK16
[!ENDIF!][!//
[!IF "PmicFailSafeConfiguration/PmicABIST2Configuration/PmicVmon1MonitorABIST2Enable = 'true'"!][!//
    | PMIC_VR55XX_FS_I_ABIST2_CTRL_VMON1_ABIST2_MASK16
[!ENDIF!][!//
[!IF "PmicFailSafeConfiguration/PmicABIST2Configuration/PmicVmon2MonitorABIST2Enable = 'true'"!][!//
    | PMIC_VR55XX_FS_I_ABIST2_CTRL_VMON2_ABIST2_MASK16
[!ENDIF!][!//
[!IF "PmicFailSafeConfiguration/PmicABIST2Configuration/PmicVmon3MonitorABIST2Enable = 'true'"!][!//
    | PMIC_VR55XX_FS_I_ABIST2_CTRL_VMON3_ABIST2_MASK16
[!ENDIF!][!//
[!IF "PmicFailSafeConfiguration/PmicABIST2Configuration/PmicVmon4MonitorABIST2Enable = 'true'"!][!//
    | PMIC_VR55XX_FS_I_ABIST2_CTRL_VMON4_ABIST2_MASK16
[!ENDIF!][!//
    ,

    /* The FS_I_SAFE_INPUTS configuration. */
    ((uint16)0x0000U)
    | PMIC_VR55XX_FS_I_SAFE_INPUTS_TIMING_WINDOW_STBY_U16(PMIC_VR55XX_FS_I_SAFE_INPUTS_TIMING_WINDOW_STBY_[!IF "node:value(PmicFailSafeConfiguration/PmicSafeInputsConfiguration/PmicSafetyStandbyWindowDuration) = 'DISABLED'"!]DISABLED[!ELSE!][!"substring-after(PmicFailSafeConfiguration/PmicSafeInputsConfiguration/PmicSafetyStandbyWindowDuration,'TIME_')"!][!ENDIF!]_SELECT_U16)
[!IF "PmicFailSafeConfiguration/PmicSafeInputsConfiguration/PmicFccu2FaultImpact = 'FS0B_AND_RSTB_ASSERT'"!][!//
    | PMIC_VR55XX_FS_I_SAFE_INPUTS_FCCU2_FS_IMPACT_MASK16
[!ENDIF!][!//
[!IF "PmicFailSafeConfiguration/PmicSafeInputsConfiguration/PmicFccu1FaultImpact = 'FS0B_AND_RSTB_ASSERT'"!][!//
    | PMIC_VR55XX_FS_I_SAFE_INPUTS_FCCU1_FS_IMPACT_MASK16
[!ENDIF!][!//
[!IF "PmicFailSafeConfiguration/PmicSafeInputsConfiguration/PmicFccu12FaultImpact = 'FS0B_AND_RSTB_ASSERT'"!][!//
    | PMIC_VR55XX_FS_I_SAFE_INPUTS_FCCU12_FS_IMPACT_MASK16
[!ENDIF!][!//
[!IF "PmicFailSafeConfiguration/PmicSafeInputsConfiguration/PmicFccu2FaultPolarity = 'HIGH_LEVEL_IS_FAULT'"!][!//
    | PMIC_VR55XX_FS_I_SAFE_INPUTS_FCCU2_FLT_POL_MASK16
[!ENDIF!][!//
[!IF "PmicFailSafeConfiguration/PmicSafeInputsConfiguration/PmicFccu1FaultPolarity = 'HIGH_LEVEL_IS_FAULT'"!][!//
    | PMIC_VR55XX_FS_I_SAFE_INPUTS_FCCU1_FLT_POL_MASK16
[!ENDIF!][!//
[!IF "PmicFailSafeConfiguration/PmicSafeInputsConfiguration/PmicFccu12FaultPolarity = 'FCCU1_HIGH_OR_FCCU2_LOW_IS_FAULT'"!][!//
    | PMIC_VR55XX_FS_I_SAFE_INPUTS_FCCU12_FLT_POL_MASK16
[!ENDIF!][!//
    | PMIC_VR55XX_FS_I_SAFE_INPUTS_FCCU_CFG_U16(PMIC_VR55XX_FS_I_SAFE_INPUTS_FCCU_CFG_[!"PmicFailSafeConfiguration/PmicSafeInputsConfiguration/PmicFccuMonitoringConfiguration"!]_SELECT_U16)
    ,

    /* The FS_I_FSSM configuration. */
    ((uint16)0x0000U)
[!IF "PmicFailSafeConfiguration/PmicStateMachineConfiguration/PmicRSTBTimerEnable = 'false'"!][!//
    | PMIC_VR55XX_FS_I_FSSM_CLK_DIS8S_MASK16
[!ENDIF!][!//
[!IF "PmicFailSafeConfiguration/PmicStateMachineConfiguration/PmicClockMonitoringEnable = 'false'"!][!//
    | PMIC_VR55XX_FS_I_FSSM_CLK_MON_DIS_MASK16
[!ENDIF!][!//
[!IF "PmicFailSafeConfiguration/PmicStateMachineConfiguration/PmicLowPowerClockMonitoringEnable = 'false'"!][!//
    | PMIC_VR55XX_FS_I_FSSM_LPCLK_MON_DIS_MASK16
[!ENDIF!][!//
[!IF "PmicFailSafeConfiguration/PmicStateMachineConfiguration/PmicBackupSafetyPath = 'RSTB_ASSERT'"!][!//
    | PMIC_VR55XX_FS_I_FSSM_BACKUP_SAFETY_PATH_MASK16
[!ENDIF!][!//
[!IF "PmicFailSafeConfiguration/PmicStateMachineConfiguration/PmicResetDuration = 'TIME_1MS'"!][!//
    | PMIC_VR55XX_FS_I_FSSM_RSTB_DUR_MASK16
[!ENDIF!][!//
    | PMIC_VR55XX_FS_I_FSSM_FLT_ERR_IMPACT_U16(PMIC_VR55XX_FS_I_FSSM_FLT_ERR_IMPACT_[!"PmicFailSafeConfiguration/PmicStateMachineConfiguration/PmicFaultErrorCounterImpact"!]_SELECT_U16)
    | PMIC_VR55XX_FS_I_FSSM_FLT_ERR_CNT_LIMIT_U16(PMIC_VR55XX_FS_I_FSSM_FLT_ERR_CNT_LIMIT_[!"substring-after(PmicFailSafeConfiguration/PmicStateMachineConfiguration/PmicFaultErrorCounterLimit,'MAX_')"!]_SELECT_U16)
};
[!ENDCODE!][!//
    [!ENDLOOP!][!//"PmicGlobalConfig/PmicDevice/*"
    [!ENDIF!][!//"num:i(count(PmicGlobalConfig/PmicDevice/*)) > 0"
[!ENDNOCODE!][!//
[!ENDMACRO!][!//Pmic_Init_Config

[!MACRO "Pmic_Otp_Config","Type"!]
[!NOCODE!]
    [!IF "num:i(count(PmicGlobalConfig/PmicDevice/*)) > 0"!]
    [!LOOP "PmicGlobalConfig/PmicDevice/*"!]
        [!VAR "Deviceindex" = "@index"!]
        [!LOOP "PmicOtpConfiguration/*[1]"!]
[!CODE!][!//
static const Pmic_VR55XX_Otp_RegisterConfigType Pmic_VR55XX_aOtpMainRegisterConfig[!"$Type"!]_[!"$Deviceindex"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PMIC_VR55XX_NUMBER_OF_OTP_MAIN_REGISTER] =
{
    /*The CFG_VPRE_1_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_VPRE_1_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_VPRE_1_OTP_VPREV_OTP_U8(PMIC_VR55XX_CFG_VPRE_1_OTP_VPREV_OTP_[!"text:replace(substring-after(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicVpreRegulator/PmicVpreOutputVoltage,'OUT_'),'V','_')"!]_V_SELECT_U8)
    },

    /*The CFG_VPRE_2_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_VPRE_2_OTP_ADDR8,
        ((uint8)0x00U)
[!IF "PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicVpreRegulator/PmicVpreEnableRegulator = 'false'"!][!//
        | PMIC_VR55XX_CFG_VPRE_2_OTP_VPREDIS_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicVpreRegulator/PmicVpreStdbyVoltageControlEnable = 'true'"!][!//
        | PMIC_VR55XX_CFG_VPRE_2_OTP_VPREV_STBY_EN_OTP_MASK8
[!ENDIF!][!//
        | PMIC_VR55XX_CFG_VPRE_2_OTP_VPRESC_OTP_U8(PMIC_VR55XX_CFG_VPRE_2_OTP_VPRESC_OTP_[!"substring-after(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicVpreRegulator/PmicVpreSlopeCompensation,'SLOPE_')"!]_SELECT_U8)
    },

    /*The CFG_VPRE_3_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_VPRE_3_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_VPRE_3_OTP_VPRESRHS_OTP_U8(PMIC_VR55XX_CFG_VPRE_3_OTP_VPRESRHS_OTP_[!"substring-after(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicVpreRegulator/PmicVpreHsCurrentCapability, 'I_')"!]_SELECT_U8)
        | PMIC_VR55XX_CFG_VPRE_3_OTP_VPRESRLS_OTP_U8(PMIC_VR55XX_CFG_VPRE_3_OTP_VPRESRLS_OTP_[!"substring-after(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicVpreRegulator/PmicVpreLsCurrentCapability, 'I_')"!]_SELECT_U8)
        | PMIC_VR55XX_CFG_VPRE_3_OTP_VPRETOFF_OTP_U8(PMIC_VR55XX_CFG_VPRE_3_OTP_VPRETOFF_OTP_[!"substring-after(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicVpreRegulator/PmicVpreHsOffTime,'TIME_')"!]_SELECT_U8)
        | PMIC_VR55XX_CFG_VPRE_3_OTP_VPREILIM_OTP_U8(PMIC_VR55XX_CFG_VPRE_3_OTP_VPREILIM_OTP_[!"substring-after(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicVpreRegulator/PmicVpreCsaThreshold,'MAX_')"!]_SELECT_U8)
    },

    /*The CFG_BOOST_1_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_BOOST_1_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_BOOST_1_OTP_VBSTV_OTP_U8(PMIC_VR55XX_CFG_BOOST_1_OTP_VBSTV_OTP_[!"text:replace(substring-after(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicVBoostRegulator/PmicVBoostOutputVoltage,'OUT_'),'V','_')"!]_V_SELECT_U8)
[!IF "PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicVBoostRegulator/PmicVBoostToVBos = 'false' "!][!//
        | PMIC_VR55XX_CFG_BOOST_1_OTP_VBOS_VBOOST_OTP_MASK8
[!ENDIF!][!//
    },

    /*The CFG_BOOST_2_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_BOOST_2_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_BOOST_2_OTP_VBSTSC_OTP_U8(PMIC_VR55XX_CFG_BOOST_2_OTP_VBSTSC_OTP_[!"substring-after(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicVBoostRegulator/PmicVBoostSlopeCompensation,'SLOPE_')"!]_SELECT_U8 )
        | PMIC_VR55XX_CFG_BOOST_2_OTP_VBSTTONTIME_OTP_U8(PMIC_VR55XX_CFG_BOOST_2_OTP_VBSTTONTIME_OTP_[!"substring-after(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicVBoostRegulator/PmicVBoostLsOnTime,'TIME_')"!]_SELECT_U8)
        [!IF "PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicBoostRegulator/PmicBoostEnableRegulator = 'true'"!]| PMIC_VR55XX_CFG_BOOST_2_OTP_BOOSTEN_OTP_MASK8[!ENDIF!]
    },

    /*The CFG_BOOST_3_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_BOOST_3_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTSR_OTP_U8(PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTSR_OTP_[!"substring-after(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicVBoostRegulator/PmicVBoostSlewRate,'RATE_')"!]_SELECT_U8)
        | PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTILIM_OTP_U8(PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTILIM_OTP_[!"substring-after(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicVBoostRegulator/PmicVBoostCurrentLimit,'I_')"!]_SELECT_U8)
        | PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTCCOMP_OTP_U8(PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTCCOMP_OTP_[!"substring-after(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicVBoostRegulator/PmicVBoostCompensationCapacitor,'C_')"!]_SELECT_U8)
        | PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTRCOMP_OTP_U8(PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTCCOMP_OTP_[!"substring-after(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicVBoostRegulator/PmicVBoostCompensationResistor,'R_')"!]_SELECT_U8)
    },

    /*The CFG_BUCK1_1_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_BUCK1_1_OTP_ADDR8,
        ((uint8)0x00U)
[!IF "num:f(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicBuck1Regulator/PmicBuck1OutputVoltage) = num:f(1.8)"!][!//
        | PMIC_VR55XX_CFG_BUCK1_1_OTP_BUCK1V_OTP_U8(PMIC_VR55XX_CFG_BUCK_X_X_OTP_BUCK_X_V_OTP_1_8_V_SELECT_U8)
[!ELSE!][!//
        | PMIC_VR55XX_CFG_BUCK1_1_OTP_BUCK1V_OTP_U8((uint8)[!"num:i(num:i (num:f(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicBuck1Regulator/PmicBuck1OutputVoltage) div num:f(0.00625) ) - num:i(64))"!]U)
[!ENDIF!][!//
    },

    /*The CFG_BUCK1_2_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_BUCK1_2_OTP_ADDR8,
        ((uint8)0x00U)
[!IF "PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicBuck1Regulator/PmicBuck1PhaseMode = 'DUAL_PHASE_MODE'"!][!//
        | PMIC_VR55XX_CFG_BUCK1_2_OTP_VB12MULTIPH_OTP_MASK8
[!ENDIF!][!//
        | PMIC_VR55XX_CFG_BUCK1_2_OTP_BUCK1_ILIM_OTP_U8(PMIC_VR55XX_CFG_BUCK_X_X_OTP_BUCK_X_ILIM_OTP_[!"substring-after(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicBuck1Regulator/PmicBuck1CurrentLimit,'I_')"!]_SELECT_U8)
        | PMIC_VR55XX_CFG_BUCK1_2_OTP_BUCK1_LSELECT_OTP_U8(PMIC_VR55XX_CFG_BUCK_X_X_OTP_BUCK_X_LSELECT_OTP_[!"substring-after(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicBuck1Regulator/PmicBuck1InductorSelect,'L_')"!]_SELECT_U8)
[!IF "PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicBuck1Regulator/PmicBuck1DVSRamp = 'DVS_15_6'"!][!//
        | PMIC_VR55XX_CFG_BUCK1_2_OTP_BUCK1DVS_RAMP_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpMainIOConfiguration/PmicPwron2GateEnable = 'true'"!][!//
        | PMIC_VR55XX_CFG_BUCK1_2_OTP_PWRON2_GATE_EN_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpMainIOConfiguration/PmicPsyncPowerDownControlEnable = 'true'"!][!//
        | PMIC_VR55XX_CFG_BUCK1_2_OTP_PSYNC_PWRDWN_EN_OTP_MASK8
[!ENDIF!][!//
    },

    /*The CFG_BUCK2_1_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_BUCK2_1_OTP_ADDR8,
        ((uint8)0x00U)
[!IF "num:f(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicBuck2Regulator/PmicBuck2OutputVoltage) = num:f(1.8)"!][!//
        | PMIC_VR55XX_CFG_BUCK2_1_OTP_BUCK2V_OTP_U8(PMIC_VR55XX_CFG_BUCK_X_X_OTP_BUCK_X_V_OTP_1_8_V_SELECT_U8)
[!ELSE!][!//
        | PMIC_VR55XX_CFG_BUCK2_1_OTP_BUCK2V_OTP_U8((uint8)[!"num:i(num:i (num:f(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicBuck2Regulator/PmicBuck2OutputVoltage) div num:f(0.00625) ) - num:i(64))"!]U)
[!ENDIF!][!//
    },

    /*The CFG_BUCK2_2_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_BUCK2_2_OTP_ADDR8,
        ((uint8)0x00U)
[!IF "PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicBuck3Regulator/PmicBuck3Transconductance = 'TRANS_32_5_uMho'"!][!//
        | PMIC_VR55XX_CFG_BUCK2_2_OTP_BUCK3_GM_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicBuck3Regulator/PmicBuck3CompensationResistor = 'R_106_KOHM'"!][!//
        | PMIC_VR55XX_CFG_BUCK2_2_OTP_BUCK3_RC_OTP_MASK8
[!ENDIF!][!//
        | PMIC_VR55XX_CFG_BUCK2_2_OTP_BUCK2_ILIM_OTP_U8(PMIC_VR55XX_CFG_BUCK_X_X_OTP_BUCK_X_ILIM_OTP_[!"substring-after(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicBuck2Regulator/PmicBuck2CurrentLimit,'I_')"!]_SELECT_U8)
[!IF "PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicBuck2Regulator/PmicBuck2EnableRegulator = 'true'"!][!//
        | PMIC_VR55XX_CFG_BUCK2_2_OTP_BUCK2EN_OTP_MASK8
[!ENDIF!][!//
        | PMIC_VR55XX_CFG_BUCK2_2_OTP_BUCK2_LSELECT_OTP_U8(PMIC_VR55XX_CFG_BUCK_X_X_OTP_BUCK_X_LSELECT_OTP_[!"substring-after(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicBuck2Regulator/PmicBuck2InductorSelect,'L_')"!]_SELECT_U8)
[!IF "PmicOtpMainUnitConfiguration/PmicOtpMainIOConfiguration/PmicAmuxFoutPinMode = 'FOUT_MODE'"!][!//
        | PMIC_VR55XX_CFG_BUCK2_2_OTP_AMUX_FOUT_OTP_MASK8
[!ENDIF!][!//
    },

    /*The CFG_BUCK3_1_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_BUCK3_1_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_U8(PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_[!"text:replace(substring-after(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicBuck3Regulator/PmicBuck3OutputVoltage,'OUT_'),'V','_')"!]_V_SELECT_U8)
        | PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3_LSELECT_OTP_U8(PMIC_VR55XX_CFG_BUCK_X_X_OTP_BUCK_X_LSELECT_OTP_[!"substring-after(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicBuck3Regulator/PmicBuck3InductorSelect,'L_')"!]_SELECT_U8)
[!IF "PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicBuck3Regulator/PmicBuck3EnableRegulator = 'true' "!][!//
        | PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3EN_OTP_MASK8
[!ENDIF!][!//
    },

    /*The CFG_BUCK3_2_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_BUCK3_2_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_BUCK3_2_OTP_BUCK3_ILIM_OTP_U8(PMIC_VR55XX_CFG_BUCK_X_X_OTP_BUCK_X_ILIM_OTP_[!"substring-after(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicBuck3Regulator/PmicBuck3CurrentLimit,'I_')"!]_SELECT_U8)
        | PMIC_VR55XX_CFG_BUCK3_2_OTP_BUCK1_COMP_OTP_U8((uint8)[!"num:i( num:f( text:replace(substring-before(substring-after(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicBuck1Regulator/PmicBuck1Transconductance,'TRANS_'),'_uMho'),'_','.')) div num:f(16.25) )"!]U)
        | PMIC_VR55XX_CFG_BUCK3_2_OTP_BUCK2_COMP_OTP_U8((uint8)[!"num:i( num:f( text:replace(substring-before(substring-after(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicBuck2Regulator/PmicBuck2Transconductance,'TRANS_'),'_uMho'),'_','.')) div num:f(16.25) )"!]U)
    },

    /*The CFG_LDO_ALL1_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_LDO_ALL1_OTP_ADDR8,
        ((uint8)0x00U)
[!IF "PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicLdo1Regulator/PmicLdo1EnableRegulator = 'true' "!][!//
        | PMIC_VR55XX_CFG_LDO_ALL1_OTP_LDO1EN_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicLdo2Regulator/PmicLdo2EnableRegulator = 'true' "!][!//
        | PMIC_VR55XX_CFG_LDO_ALL1_OTP_LDO2EN_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicLdo3Regulator/PmicLdo3EnableRegulator = 'true' "!][!//
        | PMIC_VR55XX_CFG_LDO_ALL1_OTP_LDO3EN_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicHVLdoRegulator/PmicHVLdoEnableRegulator = 'true' "!][!//
        | PMIC_VR55XX_CFG_LDO_ALL1_OTP_HVLDOEN_OTP_MASK8
[!ENDIF!][!//
        | PMIC_VR55XX_CFG_LDO_ALL1_OTP_LDO3V_OTP_U8(PMIC_VR55XX_CFG_LDO_ALL_X_OTP_LDO_X_V_OTP_[!"text:replace(substring-after(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicLdo3Regulator/PmicLdo3OutputVoltage,'OUT_'),'V','_')"!]_V_SELECT_U8)
    },

    /*The CFG_LDO_ALL2_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_LDO_ALL2_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_LDO_ALL2_OTP_LDO1V_OTP_U8(PMIC_VR55XX_CFG_LDO_ALL2_OTP_LDO1V_OTP_[!"text:replace(substring-after(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicLdo1Regulator/PmicLdo1OutputVoltage,'OUT_'),'V','_')"!]_V_SELECT_U8)
[!IF "PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicLdo1Regulator/PmicLdo1CurrentLimit = 'I_150_MA'"!][!//
        | PMIC_VR55XX_CFG_LDO_ALL2_OTP_LDO1ILIM_OTP_MASK8
[!ENDIF!][!//
        | PMIC_VR55XX_CFG_LDO_ALL2_OTP_LDO2V_OTP_U8(PMIC_VR55XX_CFG_LDO_ALL_X_OTP_LDO_X_V_OTP_[!"text:replace(substring-after(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicLdo2Regulator/PmicLdo2OutputVoltage,'OUT_'),'V','_')"!]_V_SELECT_U8)
    },

    /*The CFG_SEQ_1_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_SEQ_1_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_SEQ_1_OTP_BUCK2S_OTP_U8((uint8)[!"substring-after(PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicBuck2Regulator/PmicBuck2SlotSelect,'_')"!]U)
        | PMIC_VR55XX_CFG_SEQ_1_OTP_BUCK3S_OTP_U8((uint8)[!"substring-after(PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicBuck3Regulator/PmicBuck3SlotSelect,'_')"!]U)
[!IF "PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicLdo2Regulator/PmicLdo2OperatingMode = 'LOAD_SWITCH_MODE'"!][!//
        | PMIC_VR55XX_CFG_SEQ_1_OTP_LDO2_LS_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicLdo3Regulator/PmicLdo3OperatingMode = 'LOAD_SWITCH_MODE'"!][!//
        | PMIC_VR55XX_CFG_SEQ_1_OTP_LDO3_LS_OTP_MASK8
[!ENDIF!][!//
    },

    /*The CFG_SEQ_2_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_SEQ_2_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_SEQ_2_OTP_LDO3S_OTP_U8((uint8)[!"substring-after(PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicLdo3Regulator/PmicLdo3SlotSelect,'_')"!]U)
        | PMIC_VR55XX_CFG_SEQ_2_OTP_BUCK1S_OTP_U8((uint8)[!"substring-after(PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicBuck1Regulator/PmicBuck1SlotSelect,'_')"!]U)
        | PMIC_VR55XX_CFG_SEQ_2_OTP_HVLDOV_OTP_U8(PMIC_VR55XX_CFG_SEQ_2_OTP_HVLDOV_OTP_[!"text:replace(substring-after(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicHVLdoRegulator/PmicHVLdoOutputVoltage,'OUT_'),'V','_')"!]_V_SELECT_U8)
    },

    /*The CFG_SEQ_3_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_SEQ_3_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_SEQ_3_OTP_LDO1S_OTP_U8((uint8)[!"substring-after(PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicLdo1Regulator/PmicLdo1SlotSelect,'_')"!]U)
        | PMIC_VR55XX_CFG_SEQ_3_OTP_LDO2S_OTP_U8((uint8)[!"substring-after(PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicLdo2Regulator/PmicLdo2SlotSelect,'_')"!]U)
        | PMIC_VR55XX_CFG_SEQ_3_OTP_SLOT_WIDTH_OTP_U8(PMIC_VR55XX_CFG_SEQ_3_OTP_SLOT_WIDTH_OTP_[!"substring-after(PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicSlotWidth,'TIME_')"!]_SELECT_U8)
    },

    /*The CFG_SEQ_4_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_SEQ_4_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_SEQ_4_OTP_BOOSTS_OTP_U8((uint8)[!"substring-after(PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicBoostRegulator/PmicBoostSlotSelect,'_')"!]U)
        | PMIC_VR55XX_CFG_SEQ_4_OTP_HVLDOS_OTP_U8((uint8)[!"substring-after(PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicHVLdoRegulator/PmicHVLdoSlotSelect,'_')"!]U)
[!IF "PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicHVLdoRegulator/PmicHVLdoSequenceControl = 'START_IN_SLOT'"!][!//
        | PMIC_VR55XX_CFG_SEQ_4_OTP_HVLDO_SLOT_EN_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicHVLdoRegulator/PmicHVLdoTransitionMode = 'SWITCH_NORMAL_LDO_STDBY'"!][!//
        | PMIC_VR55XX_CFG_SEQ_4_OTP_HVLDO_TRANS_MODE_OTP_MASK8
[!ENDIF!][!//
    },

    /*The CFG_CLOCK_1_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_CLOCK_1_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_CLOCK_1_OTP_CLK_DIV2_OTP_U8(PMIC_VR55XX_CFG_CLOCK_1_OTP_CLK_DIV2_OTP_[!"substring-after(PmicOtpMainUnitConfiguration/PmicOtpDeviceConfiguration/PmicClk2Divider,'DIV_')"!]_SELECT_U8)
        | PMIC_VR55XX_CFG_CLOCK_1_OTP_VPRE_PH_OTP_U8((uint8)[!"PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicVpreRegulator/PmicVprePhaseDelay"!]U)
        | PMIC_VR55XX_CFG_CLOCK_1_OTP_VPRE_PFM_TON_OTP_U8(PMIC_VR55XX_CFG_CLOCK_1_OTP_VPRE_PFM_TON_OTP_[!"substring-after(PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicVpreRegulator/PmicVpreHsOnTime,'TIME_')"!]_SELECT_U8)
    },

    /*The CFG_CLOCK_2_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_CLOCK_2_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_CLOCK_2_OTP_VBST_PH_OTP_U8((uint8)[!"PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicBoostRegulator/PmicBoostPhaseDelay"!]U)
        | PMIC_VR55XX_CFG_CLOCK_2_OTP_BUCK1_PH_OTP_U8((uint8)[!"PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicBuck1Regulator/PmicBuck1PhaseDelay"!]U)
[!IF "PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicVpreRegulator/PmicVpreSoftStartRamp = '2'"!][!//
        | PMIC_VR55XX_CFG_CLOCK_2_OTP_VPRE_SSRAMP_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicVpreRegulator/PmicVprePowerupMode = 'AUTO_ENABLED'"!][!//
        | PMIC_VR55XX_CFG_CLOCK_2_OTP_VPRE_AUTO_ON_OTP_MASK8
[!ENDIF!][!//
    },

    /*The CFG_CLOCK_3_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_CLOCK_3_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_CLOCK_3_OTP_BUCK2_PH_OTP_U8((uint8)[!"PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicBuck2Regulator/PmicBuck2PhaseDelay"!]U)
        | PMIC_VR55XX_CFG_CLOCK_3_OTP_BUCK3_PH_OTP_U8((uint8)[!"PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicBuck3Regulator/PmicBuck3PhaseDelay"!]U)
[!IF "PmicOtpMainUnitConfiguration/PmicOtpDeviceConfiguration/PmicAutoRetryTimeout = 'TIME_100MS'"!][!//
        | PMIC_VR55XX_CFG_CLOCK_3_OTP_AUTORETRY_TIMEOUT_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpDeviceConfiguration/PmicDeepSleepEnable = 'true'"!][!//
        | PMIC_VR55XX_CFG_CLOCK_3_OTP_DSM_EN_OTP_MASK8
[!ENDIF!][!//
    },

    /*The CFG_CLOCK_4_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_CLOCK_4_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_CLOCK_4_OTP_CLK_DIV1_OTP_U8(PMIC_VR55XX_CFG_CLOCK_4_OTP_CLK_DIV1_OTP_[!"substring-after(PmicOtpMainUnitConfiguration/PmicOtpDeviceConfiguration/PmicClk1Divider,'DIV_')"!]_SELECT_U8)
[!IF "PmicOtpMainUnitConfiguration/PmicOtpDeviceConfiguration/PmicPllEnable = 'true'"!][!//
        | PMIC_VR55XX_CFG_CLOCK_4_OTP_PLL_SEL_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicVpreRegulator/PmicVpreClockSelect = 'CLK2'"!][!//
        | PMIC_VR55XX_CFG_CLOCK_4_OTP_VPRE_CLK_SEL_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicBoostRegulator/PmicBoostClockSelect = 'CLK2'"!][!//
        | PMIC_VR55XX_CFG_CLOCK_4_OTP_VBST_CLK_SEL_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicBuck1Regulator/PmicBuck1ClockSelect = 'CLK2'"!][!//
        | PMIC_VR55XX_CFG_CLOCK_4_OTP_BUCK1_CLK_SEL_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicBuck2Regulator/PmicBuck2ClockSelect = 'CLK2'"!][!//
        | PMIC_VR55XX_CFG_CLOCK_4_OTP_BUCK2_CLK_SEL_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicBuck3Regulator/PmicBuck3ClockSelect = 'CLK2'"!][!//
        | PMIC_VR55XX_CFG_CLOCK_4_OTP_BUCK3_CLK_SEL_OTP_MASK8
[!ENDIF!][!//
    },

    /*The CFG_SM_1_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_SM_1_OTP_ADDR8,
        ((uint8)0x00U)
[!IF "PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicHVLdoRegulator/PmicHVLdoTsdBehavior = 'SHUTDOWN_AND_DFS' "!][!//
        | PMIC_VR55XX_CFG_SM_1_OTP_HVLDO_TSDCFG_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicLdo3Regulator/PmicLdo3TsdBehavior = 'SHUTDOWN_AND_DFS' "!][!//
        | PMIC_VR55XX_CFG_SM_1_OTP_LDO3_TSDCFG_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicLdo2Regulator/PmicLdo2TsdBehavior = 'SHUTDOWN_AND_DFS' "!][!//
        | PMIC_VR55XX_CFG_SM_1_OTP_LDO2_TSDCFG_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicLdo1Regulator/PmicLdo1TsdBehavior = 'SHUTDOWN_AND_DFS' "!][!//
        | PMIC_VR55XX_CFG_SM_1_OTP_LDO1_TSDCFG_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicBuck3Regulator/PmicBuck3TsdBehavior = 'SHUTDOWN_AND_DFS' "!][!//
        | PMIC_VR55XX_CFG_SM_1_OTP_BUCK3_TSDCFG_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicBuck2Regulator/PmicBuck2TsdBehavior = 'SHUTDOWN_AND_DFS' "!][!//
        | PMIC_VR55XX_CFG_SM_1_OTP_BUCK2_TSDCFG_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicBuck1Regulator/PmicBuck1TsdBehavior = 'SHUTDOWN_AND_DFS' "!][!//
        | PMIC_VR55XX_CFG_SM_1_OTP_BUCK1_TSDCFG_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpPowerSequenceConfiguration/PmicBoostRegulator/PmicBoostTsdBehavior = 'SHUTDOWN_AND_DFS' "!][!//
        | PMIC_VR55XX_CFG_SM_1_OTP_BOOST_TSDCFG_OTP_MASK8
[!ENDIF!][!//
    },

    /*The CFG_SM_2_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_SM_2_OTP_ADDR8,
        ((uint8)0x00U)
[!IF "PmicOtpMainUnitConfiguration/PmicOtpMainIOConfiguration/PmicPsyncEnable = 'true'"!][!//
        | PMIC_VR55XX_CFG_SM_2_OTP_PSYNC_EN_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpMainIOConfiguration/PmicPsyncMode = 'SYNC_VR5510_AND_PF82'"!][!//
        | PMIC_VR55XX_CFG_SM_2_OTP_PSYNC_CFG_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpDeviceConfiguration/PmicAutoRetryEnable = 'true'"!][!//
        | PMIC_VR55XX_CFG_SM_2_OTP_AUTORETRY_EN_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpDeviceConfiguration/PmicAutoRetryLimit = 'NO_LIMIT'"!][!//
        | PMIC_VR55XX_CFG_SM_2_OTP_AUTORETRY_INFINITE_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpRegulatorsConfiguration/PmicVpreRegulator/PmicVpreShutdownDelay = 'TIME_32MS'"!][!//
        | PMIC_VR55XX_CFG_SM_2_OTP_VPRE_OFF_DLY_OTP_MASK8
[!ENDIF!][!//
        | PMIC_VR55XX_CFG_SM_2_OTP_DIE_CENTER_TEMP_OTP_U8((uint8)[!"num:i( num:i( num:i( substring-after(substring-before(PmicOtpMainUnitConfiguration/PmicOtpDeviceConfiguration/PmicCenterDieTempThreshold,'_o'),'TEMP_') ) - num:i(75) ) div num:i(15) )"!])
    },

    /*The CFG_I2C_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_I2C_OTP_ADDR8,
        ((uint8)0x00U)
[!IF "PmicOtpMainUnitConfiguration/PmicOtpDeviceConfiguration/PmicVsupLockoutThreshold = 'HIGH_VOLTAGE_THRESHOLD' "!][!//
        | PMIC_VR55XX_CFG_I2C_OTP_VSUPCFG_OTP_MASK8
[!ENDIF!][!//
        | PMIC_VR55XX_CFG_I2C_OTP_I2CDEVADDR_OTP_U8((uint8)[!"num:i( num:hextoint(substring-after(PmicOtpMainUnitConfiguration/PmicOtpDeviceConfiguration/PmicMainI2cAddress,'A_')) div num:i(2) - num:i(16))"!]U)
        | PMIC_VR55XX_CFG_I2C_OTP_VDDIO_REG_ASSIGN_OTP_U8(PMIC_VR55XX_CFG_I2C_OTP_VDDIO_REG_ASSIGN_OTP_[!"PmicOtpMainUnitConfiguration/PmicOtpMainIOConfiguration/PmicVddioSupplySelect"!]_SELECT_U8)
    },

    /*The CFG_DEVID_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_DEVID_OTP_ADDR8,
        ((uint8)0x00U)
[!IF "PmicOtpMainUnitConfiguration/PmicOtpMainIOConfiguration/PmicStandbyTimerEnable = 'true'"!][!//
        | PMIC_VR55XX_CFG_DEVID_OTP_STBY_TIMER_EN_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpMainIOConfiguration/PmicStandbyDischargeThreshold = 'MAX_150_MV'"!][!//
        | PMIC_VR55XX_CFG_DEVID_OTP_STBY_DISCH_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpMainIOConfiguration/PmicStandbyPolarity = 'LOW_IN_NORMAL_HIGH_IN_STANDBY'"!][!//
        | PMIC_VR55XX_CFG_DEVID_OTP_STBY_POLARITY_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpMainUnitConfiguration/PmicOtpMainIOConfiguration/PmicStandbyPGoodEnable = 'true'"!][!//
        | PMIC_VR55XX_CFG_DEVID_OTP_STBY_PGOOD_EN_OTP_MASK8
[!ENDIF!][!//
    }
};

static const Pmic_VR55XX_Otp_RegisterConfigType Pmic_VR55XX_aOtpFailSafeRegisterConfig[!"$Type"!]_[!"$Deviceindex"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PMIC_VR55XX_NUMBER_OF_OTP_FAIL_SAFE_REGISTER] =
{
    /*The CFG_UVOV_1_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_UVOV_1_OTP_ADDR8,
        ((uint8)0x00U)
[!IF "num:f(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVcoreMonitor/PmicVcoreMonitorVoltage) = num:f(1.8)"!][!//
        | PMIC_VR55XX_CFG_UVOV_1_OTP_VCORE_V_OTP_U8(PMIC_VR55XX_CFG_UVOV_1_OTP_VCORE_V_OTP_1_8_V_SELECT_U8)
[!ELSE!][!//
        | PMIC_VR55XX_CFG_UVOV_1_OTP_VCORE_V_OTP_U8((uint8)[!"num:i(num:i (num:f(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVcoreMonitor/PmicVcoreMonitorVoltage) div num:f(0.00625) ) - num:i(64))"!]U)
[!ENDIF!][!//
    },

    /*The CFG_UVOV_2_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_UVOV_2_OTP_ADDR8,
        ((uint8)0x00U)
[!IF "num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVcoreMonitor/PmicVcoreMonitorOVThreshold,'MAX_'),'_','.')) < num:f(104.5)"!][!//
        | PMIC_VR55XX_CFG_UVOV_2_OTP_VCOREOVTH_OTP_U8((uint8)[!"num:i(num:i((num:i(num:f(num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVcoreMonitor/PmicVcoreMonitorOVThreshold,'MAX_'),'_','.')) - num:f(102.5)) div num:f(0.5)))) + num:i(12))"!]U)
[!ELSE!][!//
        | PMIC_VR55XX_CFG_UVOV_2_OTP_VCOREOVTH_OTP_U8((uint8)[!"num:i(num:f(num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVcoreMonitor/PmicVcoreMonitorOVThreshold,'MAX_'),'_','.')) - num:f(104.5)) div num:f(0.5))"!]U)
[!ENDIF!][!//
[!IF "num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVddioMonitor/PmicVddioMonitorOVThreshold,'MAX_'),'_','.')) < num:f(104.5)"!][!//
        | PMIC_VR55XX_CFG_UVOV_2_OTP_VDDIOOVTH_OTP_U8((uint8)[!"num:i(num:i((num:i(num:f(num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVddioMonitor/PmicVddioMonitorOVThreshold,'MAX_'),'_','.')) - num:f(102.5)) div num:f(0.5)))) + num:i(12))"!]U)
[!ELSE!][!//
        | PMIC_VR55XX_CFG_UVOV_2_OTP_VDDIOOVTH_OTP_U8((uint8)[!"num:i(num:f(num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVddioMonitor/PmicVddioMonitorOVThreshold,'MAX_'),'_','.')) - num:f(104.5)) div num:f(0.5))"!]U)
[!ENDIF!][!//
    },

    /*The CFG_UVOV_3_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_UVOV_3_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_UVOV_3_OTP_VCORE_SVS_CLAMP_OTP_U8(PMIC_VR55XX_CFG_UVOV_3_OTP_VCORE_SVS_CLAMP_OTP_[!"substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpSafetyConfiguration/PmicSVSLimit,'STEP_')"!]_STEPS_AVAILABLE_SELECT_U8)
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpSafetyConfiguration/PmicSVSOffsetType = 'NEGATIVE_AND_POSITIVE_OFFSET'"!][!//
        | PMIC_VR55XX_CFG_UVOV_3_OTP_VCORE_SVS_FULL_OFFSET_OTP_MASK8
[!ENDIF!][!//
    },

    /*The CFG_UVOV_4_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_UVOV_4_OTP_ADDR8,
        ((uint8)0x00U)
[!IF "num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon1Monitor/PmicVmon1MonitorOVThreshold,'MAX_'),'_','.')) < num:f(104.5)"!][!//
        | PMIC_VR55XX_CFG_UVOV_4_OTP_VMON1OVTH_OTP_U8((uint8)[!"num:i(num:i((num:i(num:f(num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon1Monitor/PmicVmon1MonitorOVThreshold,'MAX_'),'_','.')) - num:f(102.5)) div num:f(0.5)))) + num:i(12))"!]U)
[!ELSE!][!//
        | PMIC_VR55XX_CFG_UVOV_4_OTP_VMON1OVTH_OTP_U8((uint8)[!"num:i(num:f(num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon1Monitor/PmicVmon1MonitorOVThreshold,'MAX_'),'_','.')) - num:f(104.5)) div num:f(0.5))"!]U)
[!ENDIF!][!//
[!IF "num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon2Monitor/PmicVmon2MonitorOVThreshold,'MAX_'),'_','.')) < num:f(104.5)"!][!//
        | PMIC_VR55XX_CFG_UVOV_4_OTP_VMON2OVTH_OTP_U8((uint8)[!"num:i(num:i((num:i(num:f(num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon2Monitor/PmicVmon2MonitorOVThreshold,'MAX_'),'_','.')) - num:f(102.5)) div num:f(0.5)))) + num:i(12))"!]U)
[!ELSE!][!//
        | PMIC_VR55XX_CFG_UVOV_4_OTP_VMON2OVTH_OTP_U8((uint8)[!"num:i(num:f(num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon2Monitor/PmicVmon2MonitorOVThreshold,'MAX_'),'_','.')) - num:f(104.5)) div num:f(0.5))"!]U)
[!ENDIF!][!//
    },

    /*The CFG_UVOV_5_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_UVOV_5_OTP_ADDR8,
        ((uint8)0x00U)
[!IF "num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon3Monitor/PmicVmon3MonitorOVThreshold,'MAX_'),'_','.')) < num:f(104.5)"!][!//
        | PMIC_VR55XX_CFG_UVOV_5_OTP_VMON3OVTH_OTP_U8((uint8)[!"num:i(num:i((num:i(num:f(num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon3Monitor/PmicVmon3MonitorOVThreshold,'MAX_'),'_','.')) - num:f(102.5)) div num:f(0.5)))) + num:i(12))"!]U)
[!ELSE!][!//
        | PMIC_VR55XX_CFG_UVOV_5_OTP_VMON3OVTH_OTP_U8((uint8)[!"num:i(num:f(num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon3Monitor/PmicVmon3MonitorOVThreshold,'MAX_'),'_','.')) - num:f(104.5)) div num:f(0.5))"!]U)
[!ENDIF!][!//
[!IF "num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon4Monitor/PmicVmon4MonitorOVThreshold,'MAX_'),'_','.')) < num:f(104.5)"!][!//
        | PMIC_VR55XX_CFG_UVOV_5_OTP_VMON4OVTH_OTP_U8((uint8)[!"num:i(num:i((num:i(num:f(num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon4Monitor/PmicVmon4MonitorOVThreshold,'MAX_'),'_','.')) - num:f(102.5)) div num:f(0.5)))) + num:i(12))"!]U)
[!ELSE!][!//
        | PMIC_VR55XX_CFG_UVOV_5_OTP_VMON4OVTH_OTP_U8((uint8)[!"num:i(num:f(num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon4Monitor/PmicVmon4MonitorOVThreshold,'MAX_'),'_','.')) - num:f(104.5)) div num:f(0.5))"!]U)
[!ENDIF!][!//
    },

    /*The CFG_UVOV_6_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_UVOV_6_OTP_ADDR8,
        ((uint8)0x00U)
[!IF "num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVcoreMonitor/PmicVcoreMonitorUVThreshold,'MIN_'),'_','.')) > num:f(95.5)"!][!//
        | PMIC_VR55XX_CFG_UVOV_6_OTP_VCOREUVTH_OTP_U8((uint8)[!"num:i(num:i((num:i(num:f(num:f(97.5) - num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVcoreMonitor/PmicVcoreMonitorUVThreshold,'MIN_'),'_','.')) ) div num:f(0.5)))) + num:i(12))"!]U)
[!ELSE!][!//
        | PMIC_VR55XX_CFG_UVOV_6_OTP_VCOREUVTH_OTP_U8((uint8)[!"num:i(num:negate(num:i(num:f(num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVcoreMonitor/PmicVcoreMonitorUVThreshold,'MIN_'),'_','.')) - num:f(95.5)) div num:f(0.5))))"!]U)
[!ENDIF!][!//
[!IF "num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVddioMonitor/PmicVddioMonitorUVThreshold,'MIN_'),'_','.')) > num:f(95.5)"!][!//
        | PMIC_VR55XX_CFG_UVOV_6_OTP_VDDIOUVTH_OTP_U8((uint8)[!"num:i(num:i((num:i(num:f(num:f(97.5) - num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVddioMonitor/PmicVddioMonitorUVThreshold,'MIN_'),'_','.')) ) div num:f(0.5)))) + num:i(12))"!]U)
[!ELSE!][!//
        | PMIC_VR55XX_CFG_UVOV_6_OTP_VDDIOUVTH_OTP_U8((uint8)[!"num:i(num:negate(num:i(num:f(num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVddioMonitor/PmicVddioMonitorUVThreshold,'MIN_'),'_','.')) - num:f(95.5)) div num:f(0.5))))"!]U)
[!ENDIF!][!//
    },

    /*The CFG_UVOV_7_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_UVOV_7_OTP_ADDR8,
        ((uint8)0x00U)
[!IF "num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon1Monitor/PmicVmon1MonitorUVThreshold,'MIN_'),'_','.')) > num:f(95.5)"!][!//
        | PMIC_VR55XX_CFG_UVOV_7_OTP_VMON1UVTH_OTP_U8((uint8)[!"num:i(num:i((num:i(num:f(num:f(97.5) - num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon1Monitor/PmicVmon1MonitorUVThreshold,'MIN_'),'_','.')) ) div num:f(0.5)))) + num:i(12))"!]U)
[!ELSE!][!//
        | PMIC_VR55XX_CFG_UVOV_7_OTP_VMON1UVTH_OTP_U8((uint8)[!"num:i(num:negate(num:i(num:f(num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon1Monitor/PmicVmon1MonitorUVThreshold,'MIN_'),'_','.')) - num:f(95.5)) div num:f(0.5))))"!]U)
[!ENDIF!][!//
[!IF "num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon2Monitor/PmicVmon2MonitorUVThreshold,'MIN_'),'_','.')) > num:f(95.5)"!][!//
        | PMIC_VR55XX_CFG_UVOV_7_OTP_VMON2UVTH_OTP_U8((uint8)[!"num:i(num:i((num:i(num:f(num:f(97.5) - num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon2Monitor/PmicVmon2MonitorUVThreshold,'MIN_'),'_','.')) ) div num:f(0.5)))) + num:i(12))"!]U)
[!ELSE!][!//
        | PMIC_VR55XX_CFG_UVOV_7_OTP_VMON2UVTH_OTP_U8((uint8)[!"num:i(num:negate(num:i(num:f(num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon2Monitor/PmicVmon2MonitorUVThreshold,'MIN_'),'_','.')) - num:f(95.5)) div num:f(0.5))))"!]U)
[!ENDIF!][!//
    },

    /*The CFG_UVOV_8_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_UVOV_8_OTP_ADDR8,
        ((uint8)0x00U)
[!IF "num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon3Monitor/PmicVmon3MonitorUVThreshold,'MIN_'),'_','.')) > num:f(95.5)"!][!//
        | PMIC_VR55XX_CFG_UVOV_8_OTP_VMON3UVTH_OTP_U8((uint8)[!"num:i(num:i((num:i(num:f(num:f(97.5) - num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon3Monitor/PmicVmon3MonitorUVThreshold,'MIN_'),'_','.')) ) div num:f(0.5)))) + num:i(12))"!]U)
[!ELSE!][!//
        | PMIC_VR55XX_CFG_UVOV_8_OTP_VMON3UVTH_OTP_U8((uint8)[!"num:i(num:negate(num:i(num:f(num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon3Monitor/PmicVmon3MonitorUVThreshold,'MIN_'),'_','.')) - num:f(95.5)) div num:f(0.5))))"!]U)
[!ENDIF!][!//
[!IF "num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon4Monitor/PmicVmon4MonitorUVThreshold,'MIN_'),'_','.')) > num:f(95.5)"!][!//
        | PMIC_VR55XX_CFG_UVOV_8_OTP_VMON4UVTH_OTP_U8((uint8)[!"num:i(num:i((num:i(num:f(num:f(97.5) - num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon4Monitor/PmicVmon4MonitorUVThreshold,'MIN_'),'_','.')) ) div num:f(0.5)))) + num:i(12))"!]U)
[!ELSE!][!//
        | PMIC_VR55XX_CFG_UVOV_8_OTP_VMON4UVTH_OTP_U8((uint8)[!"num:i(num:negate(num:i(num:f(num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon4Monitor/PmicVmon4MonitorUVThreshold,'MIN_'),'_','.')) - num:f(95.5)) div num:f(0.5))))"!]U)
[!ENDIF!][!//
    },

    /*The CFG_UVOV_9_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_UVOV_9_OTP_ADDR8,
        ((uint8)0x00U)
[!IF "num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicHVLdoMonitor/PmicHVLdoMonitorOVThreshold,'MAX_'),'_','.')) < num:f(104.5)"!][!//
        | PMIC_VR55XX_CFG_UVOV_9_OTP_HVLDO_VMON_OVTH_OTP_U8((uint8)[!"num:i(num:i((num:i(num:f(num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicHVLdoMonitor/PmicHVLdoMonitorOVThreshold,'MAX_'),'_','.')) - num:f(102.5)) div num:f(0.5)))) + num:i(12))"!]U)
[!ELSE!][!//
        | PMIC_VR55XX_CFG_UVOV_9_OTP_HVLDO_VMON_OVTH_OTP_U8((uint8)[!"num:i(num:f(num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicHVLdoMonitor/PmicHVLdoMonitorOVThreshold,'MAX_'),'_','.')) - num:f(104.5)) div num:f(0.5))"!]U)
[!ENDIF!][!//
[!IF "num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicHVLdoMonitor/PmicHVLdoMonitorUVThreshold,'MIN_'),'_','.')) > num:f(95.5)"!][!//
        | PMIC_VR55XX_CFG_UVOV_9_OTP_HVLDO_VMON_UVTH_OTP_U8((uint8)[!"num:i(num:i((num:i(num:f(num:f(97.5) - num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicHVLdoMonitor/PmicHVLdoMonitorUVThreshold,'MIN_'),'_','.')) ) div num:f(0.5)))) + num:i(12))"!]U)
[!ELSE!][!//
        | PMIC_VR55XX_CFG_UVOV_9_OTP_HVLDO_VMON_UVTH_OTP_U8((uint8)[!"num:i(num:negate(num:i(num:f(num:f(text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicHVLdoMonitor/PmicHVLdoMonitorUVThreshold,'MIN_'),'_','.')) - num:f(95.5)) div num:f(0.5))))"!]U)
[!ENDIF!][!//
    },

    /*The CFG_PGOOD_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_PGOOD_OTP_ADDR8,
        ((uint8)0x00U)
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVcoreMonitor/PmicVcoreMonitorPGOODAssert = 'true'"!][!//
        | PMIC_VR55XX_CFG_PGOOD_OTP_PGOOD_VCORE_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVddioMonitor/PmicVddioMonitorPGOODAssert = 'true'"!][!//
        | PMIC_VR55XX_CFG_PGOOD_OTP_PGOOD_VDDIO_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon1Monitor/PmicVmon1MonitorPGOODAssert = 'true'"!][!//
        | PMIC_VR55XX_CFG_PGOOD_OTP_PGOOD_VMON1_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon2Monitor/PmicVmon2MonitorPGOODAssert = 'true'"!][!//
        | PMIC_VR55XX_CFG_PGOOD_OTP_PGOOD_VMON2_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon3Monitor/PmicVmon3MonitorPGOODAssert = 'true'"!][!//
        | PMIC_VR55XX_CFG_PGOOD_OTP_PGOOD_VMON3_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon4Monitor/PmicVmon4MonitorPGOODAssert = 'true'"!][!//
        | PMIC_VR55XX_CFG_PGOOD_OTP_PGOOD_VMON4_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpSafetyConfiguration/PmicRSTBAssertPGOOD = 'true'"!][!//
        | PMIC_VR55XX_CFG_PGOOD_OTP_PGOOD_RSTB2PGOOD_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicHVLdoMonitor/PmicHVLdoMonitorPGOODAssert = 'true'"!][!//
        | PMIC_VR55XX_CFG_PGOOD_OTP_PGOOD_HVLDO_VMON_OTP_MASK8
[!ENDIF!][!//
    },

    /*The CFG_ABIST1_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_ABIST1_OTP_ADDR8,
        ((uint8)0x00U)
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVcoreMonitor/PmicVcoreMonitorABIST1Enable = 'true'"!][!//
        | PMIC_VR55XX_CFG_ABIST1_OTP_ABIST1_VCORE_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVddioMonitor/PmicVddioMonitorABIST1Enable = 'true'"!][!//
        | PMIC_VR55XX_CFG_ABIST1_OTP_ABIST1_VDDIO_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon1Monitor/PmicVmon1MonitorABIST1Enable = 'true'"!][!//
        | PMIC_VR55XX_CFG_ABIST1_OTP_ABIST1_VMON1_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon2Monitor/PmicVmon2MonitorABIST1Enable = 'true'"!][!//
        | PMIC_VR55XX_CFG_ABIST1_OTP_ABIST1_VMON2_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon3Monitor/PmicVmon3MonitorABIST1Enable = 'true'"!][!//
        | PMIC_VR55XX_CFG_ABIST1_OTP_ABIST1_VMON3_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon4Monitor/PmicVmon4MonitorABIST1Enable = 'true'"!][!//
        | PMIC_VR55XX_CFG_ABIST1_OTP_ABIST1_VMON4_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicHVLdoMonitor/PmicHVLdoMonitorABIST1Enable = 'true'"!][!//
        | PMIC_VR55XX_CFG_ABIST1_OTP_ABIST1_HVLDO_VMON_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpSafetyConfiguration/PmicRSTBTimerEnable = 'false'"!][!//
        | PMIC_VR55XX_CFG_ABIST1_OTP_DIS8S_OTP_MASK8
[!ENDIF!][!//
    },
    /*The CFG_ASIL_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_ASIL_OTP_ADDR8,
        ((uint8)0x00U)
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon1Monitor/PmicVmon1EnableMonitor = 'true'"!][!//
        | PMIC_VR55XX_CFG_ASIL_OTP_VMON1_EN_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon2Monitor/PmicVmon2EnableMonitor = 'true'"!][!//
        | PMIC_VR55XX_CFG_ASIL_OTP_VMON2_EN_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon3Monitor/PmicVmon3EnableMonitor = 'true'"!][!//
        | PMIC_VR55XX_CFG_ASIL_OTP_VMON3_EN_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon4Monitor/PmicVmon4EnableMonitor = 'true'"!][!//
        | PMIC_VR55XX_CFG_ASIL_OTP_VMON4_EN_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicHVLdoMonitor/PmicHVLdoEnableMonitor = 'true'"!][!//
        | PMIC_VR55XX_CFG_ASIL_OTP_HVLDO_VMON_EN_OTP_MASK8
[!ENDIF!][!//
    },
    /*The CFG_I2C_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_I2C_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_I2C_OTP_I2CDEVID_OTP_U8((uint8)[!"num:i( (num:hextoint(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpSafetyConfiguration/PmicSafetyI2cAddress,'A_')) - num:i(1))div num:i(2) - num:i(16))"!]U)
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpSafetyIOConfiguration/PmicWdiPolarity = 'RISING_EDGE'"!][!//
        | PMIC_VR55XX_CFG_I2C_OTP_WDI_POL_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVddioMonitor/PmicVddioEnableMonitor = 'true'"!][!//
        | PMIC_VR55XX_CFG_I2C_OTP_VDDIO_VMON_EN_OTP_MASK8
[!ENDIF!][!//
    },
    /*The CFG_1_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_1_OTP_ADDR8,
        ((uint8)0x00U)
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVddioMonitor/PmicVddioMonitorVoltage = 'OUT_3V3'"!][!//
        | PMIC_VR55XX_CFG_1_OTP_VDDIO_V_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpSafetyIOConfiguration/PmicFccu1OperatingMode = 'WDI_MODE'"!][!//
        | PMIC_VR55XX_CFG_1_OTP_FCCU_OR_WDI_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpSafetyConfiguration/PmicHVLDOMONMode = 'LDO_MODE'"!][!//
        | PMIC_VR55XX_CFG_1_OTP_HVLDO_MODE_OTP_MASK8
[!ENDIF!][!//
        | PMIC_VR55XX_CFG_1_OTP_HVLDO_V_OTP_U8(PMIC_VR55XX_CFG_1_OTP_HVLDO_V_OTP_[!"text:replace(substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicHVLdoMonitor/PmicHVLdoMonitorVoltage,'OUT_'),'V','_')"!]_V_SELECT_U8)
    },
    /*The CFG_2_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_2_OTP_ADDR8,
        ((uint8)0x00U)
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpSafetyConfiguration/PmicRstbDelay = 'DELAY_5MS'"!][!//
        | PMIC_VR55XX_CFG_2_OTP_RSTB_DELAY_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpSafetyIOConfiguration/PmicStandbyModeEnable = 'true'"!][!//
        | PMIC_VR55XX_CFG_2_OTP_STBY_EN_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpSafetyIOConfiguration/PmicStandbyPolarity = 'LOW_IN_NORMAL_HIGH_IN_STANDBY'"!][!//
        | PMIC_VR55XX_CFG_2_OTP_STBY_POLARITY_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpSafetyIOConfiguration/PmicStandbyEntryControl = 'PIN_CONTROL_ONLY'"!][!//
        | PMIC_VR55XX_CFG_2_OTP_STBY_SAFE_DIS_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpSafetyIOConfiguration/PmicSafetyStandbyWindowEnable = 'true'"!][!//
        | PMIC_VR55XX_CFG_2_OTP_STBY_WINDOW_EN_OTP_MASK8
[!ENDIF!][!//
        | PMIC_VR55XX_CFG_2_OTP_WD_INIT_TIMEOUT_OTP_U8(PMIC_VR55XX_CFG_2_OTP_WD_INIT_TIMEOUT_OTP_[!"substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpSafetyIOConfiguration/PmicSafetyWindowInitTimeout,'TIME_')"!]_SELECT_U8)
    },
    /*The CFG_DEGLITCH1_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_DEGLITCH1_OTP_ADDR8,
        ((uint8)0x00U)
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVcoreMonitor/PmicVcoreMonitorOVDebounce = 'TIME_45US'"!][!//
        | PMIC_VR55XX_CFG_DEGLITCH1_OTP_OV_MCU_OTP_MASK8
[!ENDIF!][!//
        | PMIC_VR55XX_CFG_DEGLITCH1_OTP_UV_MCU_OTP_U8(PMIC_VR55XX_CFG_DEGLITCH1_OTP_UV_MCU_OTP_[!"substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVcoreMonitor/PmicVcoreMonitorUVDebounce, 'TIME_')"!]_SELECT_U8)
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVddioMonitor/PmicVddioMonitorOVDebounce = 'TIME_45US'"!][!//
        | PMIC_VR55XX_CFG_DEGLITCH1_OTP_OV_VDDIO_OTP_MASK8
[!ENDIF!][!//
        | PMIC_VR55XX_CFG_DEGLITCH1_OTP_UV_VDDIO_OTP_U8(PMIC_VR55XX_CFG_DEGLITCH1_OTP_UV_VDDIO_OTP_[!"substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVddioMonitor/PmicVddioMonitorUVDebounce, 'TIME_')"!]_SELECT_U8)
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicHVLdoMonitor/PmicHVLdoMonitorOVDebounce = 'TIME_45US'"!][!//
        | PMIC_VR55XX_CFG_DEGLITCH1_OTP_OV_HVLDO_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon1Monitor/PmicVmon1MonitorOVDebounce = 'TIME_45US'"!][!//
        | PMIC_VR55XX_CFG_DEGLITCH1_OTP_OV_VMON1_OTP_MASK8
[!ENDIF!][!//
    },
    /*The CFG_DEGLITCH2_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_DEGLITCH2_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_HVLDO_OTP_U8(PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_HVLDO_OTP_[!"substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicHVLdoMonitor/PmicHVLdoMonitorUVDebounce, 'TIME_')"!]_SELECT_U8)
        | PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_VMON1_OTP_U8(PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_VMON1_OTP_[!"substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon1Monitor/PmicVmon1MonitorUVDebounce, 'TIME_')"!]_SELECT_U8)
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon2Monitor/PmicVmon2MonitorOVDebounce = 'TIME_45US'"!][!//
        | PMIC_VR55XX_CFG_DEGLITCH2_OTP_OV_VMON2_OTP_MASK8
[!ENDIF!][!//
        | PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_VMON2_OTP_U8(PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_VMON2_OTP_[!"substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon2Monitor/PmicVmon2MonitorUVDebounce, 'TIME_')"!]_SELECT_U8)
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon3Monitor/PmicVmon3MonitorOVDebounce = 'TIME_45US'"!][!//
        | PMIC_VR55XX_CFG_DEGLITCH2_OTP_OV_VMON3_OTP_MASK8
[!ENDIF!][!//
    },
    /*The CFG_DEGLITCH3_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_DEGLITCH3_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_DEGLITCH3_OTP_UV_VMON3_OTP_U8(PMIC_VR55XX_CFG_DEGLITCH3_OTP_UV_VMON3_OTP_[!"substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon3Monitor/PmicVmon3MonitorUVDebounce, 'TIME_')"!]_SELECT_U8)
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon4Monitor/PmicVmon4MonitorOVDebounce = 'TIME_45US'"!][!//
        | PMIC_VR55XX_CFG_DEGLITCH3_OTP_OV_VMON4_OTP_MASK8
[!ENDIF!][!//
        | PMIC_VR55XX_CFG_DEGLITCH3_OTP_UV_VMON4_OTP_U8(PMIC_VR55XX_CFG_DEGLITCH3_OTP_UV_VMON4_OTP_[!"substring-after(PmicOtpFailSafeUnitConfiguration/PmicOtpVoltageMonitorConfiguration/PmicVmon4Monitor/PmicVmon4MonitorUVDebounce, 'TIME_')"!]_SELECT_U8)
    },
    /*The CFG_ASIL_LEVEL_OTP_ADDR8 register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_ASIL_LEVEL_OTP_ADDR8,
        ((uint8)0x00U)
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpSafetyIOConfiguration/PmicFccuEnable = 'true'"!][!//
        | PMIC_VR55XX_CFG_ASIL_LEVEL_OTP_FCCU_EN_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpSafetyIOConfiguration/PmicWatchdogEnable = 'false'"!][!//
        | PMIC_VR55XX_CFG_ASIL_LEVEL_OTP_WD_DIS_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpSafetyIOConfiguration/PmicWatchdogType = 'CHALLENGER_WATCHDOG'"!][!//
        | PMIC_VR55XX_CFG_ASIL_LEVEL_OTP_WD_SELECTION_OTP_MASK8
[!ENDIF!][!//
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpSafetyConfiguration/PmicFaultRecoveryEnable = 'true'"!][!//
        | PMIC_VR55XX_CFG_ASIL_LEVEL_OTP_FLT_RECOVERY_EN_OTP_MASK8
[!ENDIF!][!//
    },
    /*The CFG_LBIST_BYP_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_LBIST_BYP_OTP_ADDR8,
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpSafetyConfiguration/PmicLBISTEnable = 'false'"!][!//
        PMIC_VR55XX_CFG_LBIST_BYP_OTP_LBIST_DIS_OTP_DISABLE_SELECT_U8
[!ELSE!][!//
        PMIC_VR55XX_CFG_LBIST_BYP_OTP_LBIST_DIS_OTP_ENABLE_SELECT_U8
[!ENDIF!][!//
    },
    /*The CFG_LBIST_BYP_NOT_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_LBIST_BYP_NOT_OTP_ADDR8,
[!IF "PmicOtpFailSafeUnitConfiguration/PmicOtpSafetyConfiguration/PmicLBISTEnable = 'false'"!][!//
        PMIC_VR55XX_CFG_LBIST_BYP_NOT_OTP_LBIST_DIS_NOT_OTP_DISABLE_SELECT_U8
[!ELSE!][!//
        PMIC_VR55XX_CFG_LBIST_BYP_OTP_LBIST_DIS_OTP_ENABLE_SELECT_U8
[!ENDIF!][!//
    }
};
[!ENDCODE!][!//
        [!ENDLOOP!][!//"PmicOtpConfiguration/*[1]"
    [!ENDLOOP!][!//"PmicGlobalConfig/PmicDevice/*"
    [!ENDIF!][!//"num:i(count(PmicGlobalConfig/PmicDevice/*)) > 0"
[!ENDNOCODE!][!//

[!NOCODE!][!//
    [!IF "num:i(count(PmicGlobalConfig/PmicDevice/*)) > 0"!][!//
    [!LOOP "PmicGlobalConfig/PmicDevice/*"!][!//
[!CODE!][!//
static const Pmic_VR55XX_OtpConfigType Pmic_VR55XX_OtpConfig[!"$Type"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    PMIC_VR55XX_NUMBER_OF_OTP_MAIN_REGISTER,
    &Pmic_VR55XX_aOtpMainRegisterConfig[!"$Type"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],

    PMIC_VR55XX_NUMBER_OF_OTP_FAIL_SAFE_REGISTER,
    &Pmic_VR55XX_aOtpFailSafeRegisterConfig[!"$Type"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
};
[!ENDCODE!][!//
    [!ENDLOOP!][!//"PmicGlobalConfig/PmicDevice/*"
    [!ENDIF!][!//"num:i(count(PmicGlobalConfig/PmicDevice/*)) > 0"
[!ENDNOCODE!][!//
[!ENDMACRO!][!//Pmic_Otp_Config


[!MACRO "Pmic_Ipw_Config","Type"!][!//
[!NOCODE!][!//
    [!IF "num:i(count(PmicGlobalConfig/PmicDevice/*)) > 0"!][!//
    [!LOOP "PmicGlobalConfig/PmicDevice/*"!][!//
    [!VAR "Deviceindex" = "@index"!][!//
[!CODE!][!//

static const Pmic_Ipw_ModeConfigType Pmic_Ipw_ModeConfig[!"$Type"!]_[!"$Deviceindex"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i(count(PmicModeSettingConf/*))"!]U] =
{
[!ENDCODE!][!//
    [!VAR "NumberOfModes" = "num:i(count(PmicModeSettingConf/*)) - 1"!][!//
    [!LOOP "PmicModeSettingConf/*"!][!//
        [!VAR "PCindex" = "@index"!][!//
[!CODE!][!//
    /* Start of Pmic_Ipw_ModeConfig[!"$Type"!]_[!"$Deviceindex"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"@index"!]] */
    {
        &Pmic_VR55XX_ModeConfig[!"$Type"!]_[!"$Deviceindex"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
    }[!IF "$PCindex < $NumberOfModes"!],[!ENDIF!] /* End of Pmic_Ipw_ModeConfig[!"$Type"!]_[!"$Deviceindex"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"@index"!]]. */
[!ENDCODE!][!//
    [!ENDLOOP!][!//"PmicModeSettingConf/*"
[!CODE!][!//
};
[!ENDCODE!][!//

[!CODE!]
static const Pmic_Ipw_ClockConfigType Pmic_Ipw_ClockConfig[!"$Type"!]_[!"$Deviceindex"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i(count(PmicClockSettingConfig/*))"!]U] =
{
[!ENDCODE!][!//
    [!VAR "NumberOfClocks" = "num:i(count(PmicClockSettingConfig/*)) - 1"!][!//
    [!LOOP "PmicClockSettingConfig/*"!][!//
        [!VAR "PCindex" = "@index"!][!//
[!CODE!][!//
    /* Start of Pmic_Ipw_ClockConfig[!"$Type"!]_[!"$Deviceindex"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"@index"!]] */
    {
        &Pmic_VR55XX_ClockConfig[!"$Type"!]_[!"$Deviceindex"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
    }[!IF "$PCindex < $NumberOfClocks"!],[!ENDIF!] /* End of Pmic_Ipw_ClockConfig[!"$Type"!]_[!"$Deviceindex"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"@index"!]]. */
[!ENDCODE!][!//
    [!ENDLOOP!][!//"PmicClockSettingConfig/*"
[!CODE!][!//
};
[!ENDCODE!][!//

[!CODE!]
static const Pmic_Ipw_ReactionConfigType Pmic_Ipw_ReactionConfig[!"$Type"!]_[!"$Deviceindex"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i(count(PmicReactionsSettingConf/*))"!]U] =
{
[!ENDCODE!][!//
    [!VAR "NumberOfReactions" = "num:i(count(PmicReactionsSettingConf/*)) - 1"!][!//
    [!LOOP "PmicReactionsSettingConf/*"!][!//
        [!VAR "PCindex" = "@index"!][!//
[!CODE!][!//
    /* Start of Pmic_Ipw_ReactionConfig[!"$Type"!]_[!"$Deviceindex"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"@index"!]] */
    {
        &Pmic_VR55XX_ReactionConfig[!"$Type"!]_[!"$Deviceindex"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
    }[!IF "$PCindex < $NumberOfReactions"!],[!ENDIF!] /* End of Pmic_Ipw_ReactionConfig[!"$Type"!]_[!"$Deviceindex"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"@index"!]]. */
[!ENDCODE!][!//
    [!ENDLOOP!][!//"PmicReactionsSettingConf/*"
[!CODE!][!//
};
[!ENDCODE!][!//

[!IF "PmicAMUXConfiguration/PmicSetAnalogMuxApi = 'true'"!][!//
[!CODE!]
#if (STD_ON == PMIC_SET_ANALOG_MUX_API)
static const Pmic_Ipw_AmuxChannelConfigType Pmic_Ipw_AmuxConfig[!"$Type"!]_[!"$Deviceindex"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i(count(PmicAMUXConfiguration/PmicAmuxChannel/*))"!]U] =
{
[!ENDCODE!][!//
    [!VAR "NumberOfAmuxs" = "num:i(count(PmicAMUXConfiguration/PmicAmuxChannel/*)) - 1"!]
    [!LOOP "PmicAMUXConfiguration/PmicAmuxChannel/*"!]
        [!VAR "PCindex" = "@index"!]
[!CODE!][!//
    /* Start of Pmic_Ipw_AmuxConfig[!"$Type"!]_[!"$Deviceindex"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"@index"!]] */
    {
        &Pmic_VR55XX_AmuxConfig[!"$Type"!]_[!"$Deviceindex"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
    }[!IF "$PCindex < $NumberOfAmuxs"!],[!ENDIF!] /* End of Pmic_Ipw_AmuxConfig[!"$Type"!]_[!"$Deviceindex"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"@index"!]] */
[!ENDCODE!][!//
    [!ENDLOOP!][!//"PmicAMUXConfiguration/PmicAmuxChannel/*"
[!CODE!][!//
};
#endif
[!ENDCODE!][!//
[!ENDIF!][!//"PmicAMUXConfiguration/PmicSetAnalogMuxApi = 'true'""

[!IF "PmicFailSafeConfiguration/PmicSVSConfiguration/PmicSwitchSVSApi = 'true'"!][!//
[!CODE!][!//
#if (STD_ON == PMIC_SWITCH_SVS_API)
static const Pmic_Ipw_SVSConfigType Pmic_Ipw_SVSConfig[!"$Type"!]_[!"$Deviceindex"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i(count(PmicFailSafeConfiguration/PmicSVSConfiguration/PmicSVSSettingConf/*))"!]U] =
{
[!ENDCODE!][!//
    [!VAR "NumberOfSVS" = "num:i(count(PmicFailSafeConfiguration/PmicSVSConfiguration/PmicSVSSettingConf/*)) - 1"!][!//
    [!LOOP "PmicFailSafeConfiguration/PmicSVSConfiguration/PmicSVSSettingConf/*"!][!//
        [!VAR "PCindex" = "@index"!][!//
[!CODE!][!//
    /* Start of Pmic_Ipw_SVSConfig[!"$Type"!]_[!"$Deviceindex"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"@index"!]] */
    {
        &Pmic_VR55XX_SVSConfig[!"$Type"!]_[!"$Deviceindex"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
    }[!IF "$PCindex < $NumberOfSVS"!],[!ENDIF!] /* End of Pmic_Ipw_SVSConfig[!"$Type"!]_[!"$Deviceindex"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"@index"!]]. */
[!ENDCODE!][!//
    [!ENDLOOP!][!//"PmicFailSafeConfiguration/PmicSVSConfiguration/PmicSVSSettingConf/*"
[!CODE!][!//
};
#endif
[!ENDCODE!][!//
[!ENDIF!][!//"PmicFailSafeConfiguration/PmicSVSConfiguration/PmicSwitchSVSApi = 'true'""

[!IF "PmicFailSafeConfiguration/PmicWatchdogConfiguration/PmicWatchdogApi ='true'"!]
[!CODE!][!//
#if (STD_ON == PMIC_WATCHDOG_API)
static const Pmic_Ipw_WatchdogConfigType Pmic_Ipw_WatchdogConfig[!"$Type"!]_[!"$Deviceindex"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i(count(PmicFailSafeConfiguration/PmicWatchdogConfiguration/PmicWatchdogSettingConf/*))"!]U] =
{
[!ENDCODE!][!//
    [!VAR "NumberOfWatchdogs" = "num:i(count(PmicFailSafeConfiguration/PmicWatchdogConfiguration/PmicWatchdogSettingConf/*)) - 1"!][!//
    [!LOOP "PmicFailSafeConfiguration/PmicWatchdogConfiguration/PmicWatchdogSettingConf/*"!][!//
        [!VAR "PCindex" = "@index"!][!//
[!CODE!][!//
    /* Start of Pmic_Ipw_WatchdogConfig[!"$Type"!]_[!"$Deviceindex"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"@index"!]] */
    {
        &Pmic_VR55XX_WatchdogConfig[!"$Type"!]_[!"$Deviceindex"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
    }[!IF "$PCindex < $NumberOfWatchdogs"!],[!ENDIF!] /* End of Pmic_Ipw_WatchdogConfig[!"$Type"!]_[!"$Deviceindex"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"@index"!]]. */
[!ENDCODE!][!//
    [!ENDLOOP!][!//"PmicFailSafeConfiguration/PmicWatchdogConfiguration/PmicWatchdogSettingConf/*"
[!CODE!][!//
};
#endif
[!ENDCODE!][!//
[!ENDIF!][!//"PmicFailSafeConfiguration/PmicWatchdogConfiguration/PmicWatchdogApi ='true'"
[!CODE!]
static const Pmic_VR55XX_ConfigType Pmic_VR55XX_DeviceInitConfig[!"$Type"!]_[!"$Deviceindex"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    &Pmic_VR55XX_OtpConfig[!"$Type"!]_[!"$Deviceindex"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    &Pmic_VR55XX_InitConfig[!"$Type"!]_[!"$Deviceindex"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
};
[!ENDCODE!]

[!CODE!]
static const Pmic_Ipw_HwDeviceConfigType Pmic_Ipw_HwDeviceConfig[!"$Type"!]_[!"$Deviceindex"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    &Pmic_VR55XX_DeviceInitConfig[!"$Type"!]_[!"$Deviceindex"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
};
[!ENDCODE!][!//
    [!ENDLOOP!][!//"PmicGlobalConfig/PmicDevice/*"
    [!ENDIF!][!//"num:i(count(PmicGlobalConfig/PmicDevice/*)) > 0"
[!ENDNOCODE!][!//
[!ENDMACRO!][!//Pmic_Ipw_Config

[!MACRO "Pmic_InterfaceUnit_Config","Type"!][!//
[!NOCODE!][!//
    [!IF "num:i(count(PmicGlobalConfig/PmicDevice/*)) > 0"!][!//
    [!LOOP "PmicGlobalConfig/PmicDevice/*"!][!//
[!CODE!][!//
static const Pmic_InterfaceUnitConfigType Pmic_InterfaceUnitConfig[!"$Type"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]=
{
    /* The type of the interface. */
    PMIC_INTERFACE_I2C,
    /* The I2C channel*/
    (uint8)[!"num:i(node:ref(PmicCommunicationConfiguration/PmicI2cChannelRef)/I2cChannelId)"!]U,
    /*The device's main I2c address*/
    (uint8)[!"substring-after(PmicDeviceMainI2cAddress,'A_')"!]U,
    /*The device's fail-safe unit I2c address*/
    (uint8)[!"substring-after(PmicDeviceSafetyI2cAddress,'A_')"!]U,
    /* The scl pin index */
    (uint32)[!"num:i(num:i(node:ref(PmicCommunicationConfiguration/PmicI2CSCLPinRef)/PortPinId) - 1)"!]U,
    /* device's i2c scl pin - initial mode */
    (uint8)[!"node:ref(PmicCommunicationConfiguration/PmicI2CSCLPinRef)/PortPinInitialMode"!],
    /* device's i2c scl pin - mode */
    (uint8)[!"concat(node:ref(PmicCommunicationConfiguration/PmicI2CSCLPinRef)/PortPinSiul2Instance,'_PORT',node:ref(PmicCommunicationConfiguration/PmicI2CSCLPinRef)/PortPinPcr,'_',node:ref(PmicCommunicationConfiguration/PmicI2CSCLPinRef)/PortPinMode)"!],
    /* device's operating frequency */
    (uint32)[!"num:i(node:ref(node:ref(PmicCommunicationConfiguration/PmicI2cChannelRef)/I2cMasterConfiguration/I2cClockRef)/McuClockReferencePointFrequency)"!]U,
    /*device's i2c channel frequency */
    (uint32)[!"num:i(node:ref(PmicCommunicationConfiguration/PmicI2cChannelRef)/I2cMasterConfiguration/I2cBaudRate)"!]U,
    /*device's dio channel id */
    (uint16)[!"num:i(node:ref(PmicCommunicationConfiguration/PmicI2CSCLDioRef)/DioChannelId + (node:ref(PmicCommunicationConfiguration/PmicI2CSCLDioRef)/../../DioPortId * 16))"!]U
};
[!ENDCODE!][!//
    [!ENDLOOP!][!//"PmicGlobalConfig/PmicDevice/*"
    [!ENDIF!][!//"num:i(count(PmicGlobalConfig/PmicDevice/*)) > 0"
[!ENDNOCODE!][!//
[!ENDMACRO!][!//Pmic_InterfaceUnit_Config

[!MACRO "Pmic_Device_Config","Type"!][!//
[!NOCODE!][!//
    [!IF "num:i(count(PmicGlobalConfig/PmicDevice/*)) > 0"!][!//
[!CODE!][!//
static const Pmic_DeviceConfigType Pmic_DeviceConfig[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i(count(PmicGlobalConfig/PmicDevice/*))"!]U] =
{
[!ENDCODE!][!//
    [!VAR "NumberOfDeviceConfigs" = "num:i(count(PmicGlobalConfig/PmicDevice/*)) - 1"!][!//
    [!LOOP "PmicGlobalConfig/PmicDevice/*"!][!//
    [!VAR "PCindex" = "@index"!][!//
[!CODE!][!//
    /* Start of Pmic_DeviceConfig[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"@index"!]] */
    {
    /* ID of device */
    (uint8)[!"num:i(PmicDeviceId)"!]U,
    /* The number mode setting configuration of device */
    [!"num:i(count(PmicModeSettingConf/*))"!]U,
    /* The number clock setting configuration of device */
    [!"num:i(count(PmicClockSettingConfig/*))"!]U,
    /* The number reaction setting configuration of device */
    [!"num:i(count(PmicReactionsSettingConf/*))"!]U,
#if (STD_ON == PMIC_SET_ANALOG_MUX_API)
    /* The number amux setting configuration of device */
    [!"num:i(count(PmicAMUXConfiguration/PmicAmuxChannel/*))"!]U,
#endif
#if (STD_ON == PMIC_SWITCH_SVS_API)
    /* The number svs setting configuration of device */
    [!"num:i(count(PmicFailSafeConfiguration/PmicSVSConfiguration/PmicSVSSettingConf/*))"!]U,
#endif
#if (STD_ON == PMIC_WATCHDOG_API)
    /* The number watchdog setting configuration of device */
    [!"num:i(count(PmicFailSafeConfiguration/PmicWatchdogConfiguration/PmicWatchdogSettingConf/*))"!]U,
#endif
    /* Pointer to device's mode configuration structure*/
    &Pmic_Ipw_ModeConfig[!"$Type"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    /* Pointer to device's clock configuration structure*/
    &Pmic_Ipw_ClockConfig[!"$Type"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    /* Pointer to device's reaction configuration structure*/
    &Pmic_Ipw_ReactionConfig[!"$Type"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
#if (STD_ON == PMIC_SET_ANALOG_MUX_API)
    /* Pointer to device's amux configuration structure*/
    [!IF "PmicAMUXConfiguration/PmicSetAnalogMuxApi = 'false'"!]NULL_PTR,[!ELSE!]&Pmic_Ipw_AmuxConfig[!"$Type"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],[!ENDIF!]
#endif
#if (STD_ON == PMIC_SWITCH_SVS_API)
    /* Pointer to device's svs configuration structure*/
    [!IF "PmicFailSafeConfiguration/PmicSVSConfiguration/PmicSwitchSVSApi = 'false'"!]NULL_PTR,[!ELSE!]&Pmic_Ipw_SVSConfig[!"$Type"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],[!ENDIF!]
#endif
#if (STD_ON == PMIC_WATCHDOG_API)
    /* Pointer to device's watchdog configuration structure*/
    [!IF "PmicFailSafeConfiguration/PmicWatchdogConfiguration/PmicWatchdogApi ='false'"!]NULL_PTR,[!ELSE!]&Pmic_Ipw_WatchdogConfig[!"$Type"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],[!ENDIF!]
#endif
    /* Pointer to device's interface unit configuration structure*/
    &Pmic_InterfaceUnitConfig[!"$Type"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    /* Pointer to device's HW configuration structure*/
    &Pmic_Ipw_HwDeviceConfig[!"$Type"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
    }[!IF "$PCindex < $NumberOfDeviceConfigs"!],[!ENDIF!]
    /* End of Pmic_DeviceConfig[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"@index"!]]. */
[!ENDCODE!][!//
    [!ENDLOOP!][!//"PmicGlobalConfig/PmicDevice/*"
[!CODE!][!//
};
[!ENDCODE!][!//
    [!ENDIF!][!//"num:i(count(PmicGlobalConfig/PmicDevice/*)) > 0"
[!ENDNOCODE!][!//
[!ENDMACRO!][!//Pmic_Device_Config


[!MACRO "Pmic_Config","Type"!][!//
[!NOCODE!][!//
[!CODE!][!//
/**
* @brief          Initialization data for the PMIC driver.
* @details        A pointer to such a structure is provided to the PMIC initialization routines for configuration.
*
*/
const Pmic_ConfigType [!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and (variant:size() <= 1)"!]Pmic_Config[!ELSE!]Pmic_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!] =
{
#if (STD_ON == PMIC_DIE_PROCESS_ENABLE)
    /* Index of Ocotp channel read eFuse Word OCOTP_BANK0_WORD6. */
[!ENDCODE!][!//
[!IF "PmicGeneralConfiguration/PmicDieProcessEnable = 'true'"!][!//
[!IF "node:ref(PmicGeneralConfiguration/PmicOcotplink)/OcotpWord != 'OCOTP_BANK0_WORD6'"!]
[!ERROR!] PMIC requires the eFuse Word of OCOTP which must be OCOTP_BANK0_WORD6. This bank is used to check DIE_PROCESS. Refer Mcu reference manual to know information[!ENDERROR!]
[!ELSE!][!//
[!CODE!][!//
    (uint32)[!"num:i(node:ref(PmicGeneralConfiguration/PmicOcotplink)/OcotpChannelNumber)"!]U,
[!ENDCODE!][!//
[!ENDIF!]
[!ELSE!][!//
[!CODE!][!//
    (uint32)0U,
[!ENDCODE!][!//
[!ENDIF!][!//
[!CODE!][!//
#endif
    /* Total number of configured PMIC devices. */
    (uint8)PMIC_MAX_DEVICECONFIGS,
#if (STD_OFF == PMIC_EXTERNAL_WATCHDOG_API)
    /* Pointer to callout configured by user for watchdog task notifications. */
    [!IF "node:exists(PmicGeneralConfiguration/PmicWatchdogTaskNotification)"!]&[!"normalize-space(PmicGeneralConfiguration/PmicWatchdogTaskNotification)"!][!ELSE!]NULL_PTR[!ENDIF!],
#endif
    /* Pointer to list of PMIC device configurations. */
    &Pmic_DeviceConfig[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
#if (STD_OFF == PMIC_DISABLE_DEM_REPORT_ERROR_STATUS)
    /* Pointer to DEM error reporting configurations. */
    &Pmic_DemConfig
#endif
};
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDMACRO!][!//

[!ENDIF!][!// Avoid multiple inclusion ENDIF
[!ENDNOCODE!]

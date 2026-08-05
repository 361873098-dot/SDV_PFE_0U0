[!CODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : TMU
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
*   Copyright 2020-2023 NXP Semiconductors
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

/**
*   @file
*
*   @addtogroup tmu_ip_config TMU IPL Configuration
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
[!NOCODE!][!//
[!CODE!]#include "Tmu_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDNOCODE!][!//

[!NOCODE!][!//
[!INCLUDE "Thermal_VersionCheck_Src.m"!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define TMU_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C                      43
#define TMU_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C       4
#define TMU_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C       4
#define TMU_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C    0
#define TMU_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C               4
#define TMU_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C               0
#define TMU_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C               2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#if ((TMU_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C != TMU_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H) || \
     (TMU_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C != TMU_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H) || \
     (TMU_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C != TMU_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H) \
    )
    #error "AutoSar Version Numbers of Tmu_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Tmu_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h are different"
#endif

#if ((TMU_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C != TMU_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H) || \
     (TMU_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C != TMU_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H) || \
     (TMU_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C != TMU_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H) \
    )
    #error "Software Version Numbers of Tmu_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Tmu_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h are different"
#endif

#if (TMU_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_C != TMU_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"text:toupper($postBuildVariant)"!]_[!ENDIF!]PBCFG_H)
    #error "Tmu_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Tmu_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h have different vendor ids"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

#define THERMAL_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Thermal_MemMap.h"

[!NOCODE!][!//
[!IF "num:i(count(ThermalConfigSet/TmuHwUnit/*/TmuCalibConfig/*)) > 0"!][!//
[!CODE!][!//
/**
* @brief          Tmu Ip Calibration Configurations[!IF "var:defined('postBuildVariant')"!] for [!"$postBuildVariant"!] variant.[!ENDIF!]
*/
static const Tmu_Ip_CalibrationConfigType TmuIpCalibrationConfigs[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][] =
{
[!ENDCODE!][!//
[!VAR "MAX_NUM"="num:i(count(ThermalConfigSet/TmuHwUnit/*/TmuCalibConfig/*))"!]
[!LOOP "ThermalConfigSet/TmuHwUnit/*/TmuCalibConfig/*"!]
    [!VAR "CRT_NUM"="0"!]
    [!FOR "CRT_NUM" = "0" TO "$MAX_NUM"!]
        [!IF "@index = $CRT_NUM"!][!//
[!CODE!][!//
    {
        .SensorValue = [!"ThermalSensorValue"!]U,
        .TempRange   = [!"ThermalTempRange"!]U /* Temperature in Kelvin. */
[!IF "$CRT_NUM < $MAX_NUM - 1"!]    },[!//
[!ELSE!]    }[!//
[!ENDIF!]
[!ENDCODE!][!//
        [!ENDIF!]
    [!ENDFOR!]
[!ENDLOOP!]
[!CODE!][!//
};
[!ENDCODE!][!//
[!ENDIF!][!//
[!CODE!]
/**
* @brief          Tmu Ip Threshold Configurations[!IF "var:defined('postBuildVariant')"!] for [!"$postBuildVariant"!] variant.[!ENDIF!]
*/
static const Tmu_Ip_ThresholdConfigType TmuIpThresholdConfigs[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][] =
{
[!ENDCODE!][!//
[!VAR "MAX_NUM"="num:i(count(ThermalConfigSet/TmuHwUnit/*/TmuThresholdConfig/*))"!]
[!LOOP "ThermalConfigSet/TmuHwUnit/*/TmuThresholdConfig/*"!]
    [!VAR "CRT_NUM"="0"!]
    [!FOR "CRT_NUM" = "0" TO "$MAX_NUM"!]
        [!IF "@index = $CRT_NUM"!][!//
[!CODE!][!//
    {
        .Enable           = [!IF "ThermalThrEnable = 'true'"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!],
        .ThresholdType    = [!"ThermalThresholdType"!],
        .ThresholdValue   = [!"ThermalThresholdValue"!]U, /* Temperature in Kelvin. */
        .InterruptEnable  = [!IF "ThermalInterruptEnable = 'true'"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!]
[!IF "$CRT_NUM < $MAX_NUM - 1"!]    },[!//
[!ELSE!]    }[!//
[!ENDIF!]
[!ENDCODE!][!//
            [!ENDIF!]
        [!ENDFOR!]
    [!ENDLOOP!]
[!CODE!][!//
};

/**
* @brief          Tmu Ip Notification Configuration[!IF "var:defined('postBuildVariant')"!] for [!"$postBuildVariant"!] variant.[!ENDIF!]
*/
static const Tmu_Ip_NotificationsType TmuIpNotificationConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    .ImmediateHighTemp       = [!IF "ThermalConfigSet/TmuHwUnit/*/ThermalImmHighNotif != 'NULL_PTR'"!]&[!"ThermalConfigSet/TmuHwUnit/*/ThermalImmHighNotif"!],[!ELSE!]NULL_PTR,[!ENDIF!]
    .AverageHighTemp         = [!IF "ThermalConfigSet/TmuHwUnit/*/ThermalAvgHighNotif != 'NULL_PTR'"!]&[!"ThermalConfigSet/TmuHwUnit/*/ThermalAvgHighNotif"!],[!ELSE!]NULL_PTR,[!ENDIF!]
    .AverageHighTempCritical = [!IF "ThermalConfigSet/TmuHwUnit/*/ThermalAvgHighCriticalNotif != 'NULL_PTR'"!]&[!"ThermalConfigSet/TmuHwUnit/*/ThermalAvgHighCriticalNotif"!],[!ELSE!]NULL_PTR,[!ENDIF!]
    .ImmediateLowTemp        = [!IF "ThermalConfigSet/TmuHwUnit/*/ThermalImmLowNotif != 'NULL_PTR'"!]&[!"ThermalConfigSet/TmuHwUnit/*/ThermalImmLowNotif"!],[!ELSE!]NULL_PTR,[!ENDIF!]
    .AverageLowTemp          = [!IF "ThermalConfigSet/TmuHwUnit/*/ThermalAvgLowNotif != 'NULL_PTR'"!]&[!"ThermalConfigSet/TmuHwUnit/*/ThermalAvgLowNotif"!],[!ELSE!]NULL_PTR,[!ENDIF!]
    .AverageLowTempCritical  = [!IF "ThermalConfigSet/TmuHwUnit/*/ThermalAvgLowCriticalNotif != 'NULL_PTR'"!]&[!"ThermalConfigSet/TmuHwUnit/*/ThermalAvgLowCriticalNotif"!],[!ELSE!]NULL_PTR,[!ENDIF!]
    .RisingTempRateCritical  = [!IF "ThermalConfigSet/TmuHwUnit/*/ThermalRisingRateNotif != 'NULL_PTR'"!]&[!"ThermalConfigSet/TmuHwUnit/*/ThermalRisingRateNotif"!],[!ELSE!]NULL_PTR,[!ENDIF!]
    .FallingTempRateCritical = [!IF "ThermalConfigSet/TmuHwUnit/*/ThermalFallingRateNotif != 'NULL_PTR'"!]&[!"ThermalConfigSet/TmuHwUnit/*/ThermalFallingRateNotif"!],[!ELSE!]NULL_PTR,[!ENDIF!]
};
[!ENDCODE!][!//
[!ENDNOCODE!][!//

#define THERMAL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Thermal_MemMap.h"

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

#define THERMAL_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Thermal_MemMap.h"

[!NOCODE!][!//

[!VAR "VariantsNo" = "variant:size()"!]
[!CODE!][!//
/**
* @brief          Tmu Ip Configuration[!IF "var:defined('postBuildVariant')"!] for [!"$postBuildVariant"!] variant.[!ENDIF!]
*/
[!ENDCODE!][!//
    [!IF "(IMPLEMENTATION_CONFIG_VARIANT !='VariantPostBuild' and ($VariantsNo <= 1))"!][!//
[!CODE!][!//
/* VariantPreCompile/LinkTime and at most 1 configured variant */
const Tmu_Ip_ConfigType TmuIpConfig =
{
[!ENDCODE!][!//
[!ELSE!][!//
[!CODE!][!//
/* VariantPostBuild or more than 1 configured variant */
const Tmu_Ip_ConfigType TmuIpConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
[!ENDCODE!][!//
[!ENDIF!][!//
[!VAR "NumOfCalibrations" = "num:i(count(ThermalConfigSet/TmuHwUnit/*/TmuCalibConfig/*))"!][!//
[!VAR "NumOfThresholds" = "num:i(count(ThermalConfigSet/TmuHwUnit/*/TmuThresholdConfig/*))"!][!//

[!VAR "MonitoringMask"="0"!][!//
[!VAR "NumOfSites" = "count(ecu:list('Thermal.TmuConfigSet.TmuHwUnit.MonitoringSitePlacement'))"!]
[!FOR "Index" = "0" TO "num:i($NumOfSites)"!][!//
    [!LOOP "ThermalConfigSet/TmuHwUnit/*/TmuMonitoringSite/*"!][!//
        [!IF "(TmuEnableSite = 'true') and (TmuSitePlacement = ecu:list('Thermal.TmuConfigSet.TmuHwUnit.MonitoringSitePlacement')[num:i($Index)])"!][!//
            [!VAR "MonitoringMask"="num:i(bit:or($MonitoringMask, bit:shl(1,$Index - 1)))"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDFOR!][!//

[!CODE!][!//
    .MonitoringSitesMask    = 0x0[!"$MonitoringMask"!]U,
    .LowPassFilter          = [!"ThermalConfigSet/TmuHwUnit/*/ThermalAverageLowPassFilterType"!],
    .CentralModuleDisable   = [!IF "ThermalConfigSet/TmuHwUnit/*/ThermalCentralModuleDisable = 'true'"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!],
    .OffsetCancellation     = [!IF "ThermalConfigSet/TmuHwUnit/*/ThermalOffsetCancellation = 'true'"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!],
    .DynamicMatchAvrg       = [!IF "ThermalConfigSet/TmuHwUnit/*/ThermalDynamicMatchAvg = 'true'"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!],
    .MeasurementInterval    = [!"ThermalConfigSet/TmuHwUnit/*/ThermalMeasurementInterval"!],
    .NumCalibrationConfigs  = [!"$NumOfCalibrations"!]U,
    .CalibrationConfig      = [!IF "$NumOfCalibrations > 0"!]TmuIpCalibrationConfigs[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],[!ELSE!]NULL_PTR,[!ENDIF!]
    .NumThresholds          = [!"$NumOfThresholds"!]U,
    .ThresholdConfig        = TmuIpThresholdConfigs[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    .Notifications          = &TmuIpNotificationConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
};
[!ENDCODE!][!//
[!ENDNOCODE!][!//

#define THERMAL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Thermal_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */
[!ENDCODE!][!//


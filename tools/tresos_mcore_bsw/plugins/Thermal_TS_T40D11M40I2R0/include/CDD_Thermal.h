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

#ifndef CDD_THERMAL_H
#define CDD_THERMAL_H

/**
*   @file
*
*   @addtogroup thermal_driver
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
#include "CDD_Thermal_Cfg.h"
#include "CDD_Thermal_Types.h"
#include "Tmu_Ip.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define THERMAL_VENDOR_ID                    43
#define THERMAL_MODULE_ID                    255
#define THERMAL_AR_RELEASE_MAJOR_VERSION     4
#define THERMAL_AR_RELEASE_MINOR_VERSION     4
#define THERMAL_AR_RELEASE_REVISION_VERSION  0
#define THERMAL_SW_MAJOR_VERSION             4
#define THERMAL_SW_MINOR_VERSION             0
#define THERMAL_SW_PATCH_VERSION             2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#if ((THERMAL_AR_RELEASE_MAJOR_VERSION != THERMAL_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (THERMAL_AR_RELEASE_MINOR_VERSION != THERMAL_AR_RELEASE_MINOR_VERSION_CFG) || \
     (THERMAL_AR_RELEASE_REVISION_VERSION != THERMAL_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of CDD_Thermal.h and CDD_Thermal_Cfg.h are different"
#endif

#if ((THERMAL_SW_MAJOR_VERSION != THERMAL_SW_MAJOR_VERSION_CFG) || \
     (THERMAL_SW_MINOR_VERSION != THERMAL_SW_MINOR_VERSION_CFG) || \
     (THERMAL_SW_PATCH_VERSION != THERMAL_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of CDD_Thermal.h and CDD_Thermal_Cfg.h are different"
#endif

#if (THERMAL_VENDOR_ID != THERMAL_VENDOR_ID_CFG)
    #error "CDD_Thermal.h and CDD_Thermal_Cfg.h have different vendor ids"
#endif

#if ((THERMAL_AR_RELEASE_MAJOR_VERSION != THERMAL_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (THERMAL_AR_RELEASE_MINOR_VERSION != THERMAL_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (THERMAL_AR_RELEASE_REVISION_VERSION != THERMAL_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of CDD_Thermal.h and CDD_Thermal_Types.h are different"
#endif

#if ((THERMAL_SW_MAJOR_VERSION != THERMAL_SW_MAJOR_VERSION_TYPES) || \
     (THERMAL_SW_MINOR_VERSION != THERMAL_SW_MINOR_VERSION_TYPES) || \
     (THERMAL_SW_PATCH_VERSION != THERMAL_SW_PATCH_VERSION_TYPES) \
    )
    #error "Software Version Numbers of CDD_Thermal.h and CDD_Thermal_Types.h are different"
#endif

#if (THERMAL_VENDOR_ID != THERMAL_VENDOR_ID_TYPES)
    #error "CDD_Thermal.h and CDD_Thermal_Types.h have different vendor ids"
#endif

#if ((THERMAL_AR_RELEASE_MAJOR_VERSION != TMU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (THERMAL_AR_RELEASE_MINOR_VERSION != TMU_IP_AR_RELEASE_MINOR_VERSION) || \
     (THERMAL_AR_RELEASE_REVISION_VERSION != TMU_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Thermal.h and Tmu_Ip.h are different"
#endif

#if ((THERMAL_SW_MAJOR_VERSION != TMU_IP_SW_MAJOR_VERSION) || \
     (THERMAL_SW_MINOR_VERSION != TMU_IP_SW_MINOR_VERSION) || \
     (THERMAL_SW_PATCH_VERSION != TMU_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Thermal.h and Tmu_Ip.h are different"
#endif

#if (THERMAL_VENDOR_ID != TMU_IP_VENDOR_ID)
    #error "CDD_Thermal.h and Tmu_Ip.h have different vendor ids"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*! @brief Value that represents an invalid temperature.
 * This value is returned by functions in case a measurement is not yet completed in hardware.
 */
#define THERMAL_INVALID_TEMP                ((Thermal_TempValueType)TMU_IP_INVALID_TEMPERATURE)

/*! @brief Value that represents an invalid temperature rate.
 * This value is returned by functions in case this information is not yet available in hardware.
 */
#define THERMAL_INVALID_TEMP_RATE           ((Thermal_TempRateValueType)TMU_IP_INVALID_TEMPERATURE_RATE)

/*! Various error codes that this Thermal driver uses for generating Det errors. */
#define THERMAL_E_NEED_LOW_POWER_MODE       10
#define THERMAL_E_NEED_MONITORING_MODE      11
#define THERMAL_E_NOT_INITIALIZED           12
#define THERMAL_E_ALREADY_INITIALIZED       13
#define THERMAL_E_NOTIF_NOT_CONFIGURED      14
#define THERMAL_E_WRONG_SITE                15
#define THERMAL_E_SITE_MASK_NOT_VALID       16
#define THERMAL_E_INIT_FAILED               17

/*! Various service IDs that this Thermal driver uses for generating Det errors. */
#define THERMAL_INIT_ID                     0x00U
#define THERMAL_DEINIT_ID                   0x01U
#define THERMAL_SETPOWERMODE_ID             0x02U
#define THERMAL_ENABLEMONITORINGSITE_ID     0x03U
#define THERMAL_DISABLEMONITORINGSITE_ID    0x04U
#define THERMAL_SETTEMPTHRESHOLD_ID         0x05U
#define THERMAL_GETTEMPMINMAXLEVEL_ID       0x06U
#define THERMAL_GETTEMPMAXRATE_ID           0x07U
#define THERMAL_GETTEMP_ID                  0x08U
#define THERMAL_ENABLENOTIFICATIONS_ID      0x09U
#define THERMAL_DISABLENOTIFICATIONS_ID     0x0AU
#define THERMAL_SETMEASUREMENTINTERVAL_ID   0x0BU

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#if (THERMAL_PRECOMPILE_SUPPORT == STD_ON)
    #define THERMAL_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Thermal_MemMap.h"
    extern const Thermal_ConfigType * const Thermal_ConfigVariantPredefined[1];
    #define THERMAL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Thermal_MemMap.h"
#else
    #define THERMAL_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Thermal_MemMap.h"

    THERMAL_CONFIG_EXT

    #define THERMAL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Thermal_MemMap.h"
#endif /* THERMAL_PRECOMPILE_SUPPORT == STD_ON */

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#define THERMAL_START_SEC_CODE
#include "Thermal_MemMap.h"

/**
 * @brief This function initializes the Thermal CDD.
 * @param[in] ConfigPtr Pointer to the configuration structure.
 *
 * @implements Thermal_Init_Activity
 */
void Thermal_Init (const Thermal_ConfigType * const ConfigPtr);

/**
 * @brief Un-initializes the Thermal CDD by undoing the work done by Thermal_Init().
 *
 * @implements Thermal_Deinit_Activity
 */
void Thermal_Deinit(void);

/*!
 * @brief Enables monitoring on specified sites.
 *
 * @param[in] SiteMask A combination of THERMAL_MONITORING_SITE_ values
 *
 * @implements Thermal_EnableMonitoringSite_Activity
 */
void Thermal_EnableMonitoringSite(Thermal_MonitoringSiteType SiteMask);

/*!
 * @brief Disables monitoring on specified sites.
 *
 * @param[in] SiteMask A combination of THERMAL_MONITORING_SITE_ values
 *
 * @implements Thermal_DisableMonitoringSite_Activity
 */
void Thermal_DisableMonitoringSite (Thermal_MonitoringSiteType SiteMask);

/*!
 * @brief Sets the peripheral's power mode.
 *
 * @param[in] Mode one of THERMAL_POWERMODE_NORMAL / THERMAL_POWERMODE_LOWPOWER.
 *
 * @implements Thermal_SetPowerMode_Activity
 */
void Thermal_SetPowerMode(Thermal_PowerModeType Mode);

/*!
 * @brief Retrieves the maximum or minimum temperature recorded, and optionally clears this information in hardware.
 *
 * @param[in] TempLevelType specifies whether to retrieve the maximum or minimum.
 * @param[in] ClearValidFlag TRUE to clear the recorded temperature.
 *
 * @return Thermal_TempValueType: Tmperature value
 * @implements Thermal_GetTempMinMaxLevel_Activity
 */
Thermal_TempValueType Thermal_GetTempMinMaxLevel(Thermal_TempLevelType TempLevelType,
                                                 boolean ClearValidFlag);

/*!
 * @brief Retrieves the maximum or minimum temperature rate recorded, and optionally clears this information in hardware.
 *
 * @param[in] TempRateType specifies whether to retrieve the rising or the falling rate.
 * @param[in] ClearValidFlag TRUE to clear the recorded temperature.
 *
 * @return Thermal_TempRateValueType: Temperature rate value
 * @implements Thermal_GetTempMaxRate_Activity
 */
Thermal_TempRateValueType Thermal_GetTempMaxRate(Thermal_TempRateType TempRateType,
                                                 boolean ClearValidFlag);

/*!
 * @brief Retrieves the current temperature at a single site.
 *
 * @param[in] SiteIndex 0 for the first site, 1 for the second site, 2 for the third site.
 * @param[in] ReportType specifies whether to retrieve the immediate or the average temperature.
 * @return temperature value.
 *
 * @return Thermal_TempValueType: Temperature value
 * @implements Thermal_GetTemp_Activity
 */
Thermal_TempValueType Thermal_GetTemp(uint8 SiteIndex,
                                      Thermal_ReportType ReportType);

/*!
 * @brief Sets the threshold temperature for a given type of threshold.
 *
 * @param[in] ThresholdType type of threshold.
 * @param[in] ThresholdValue temperature in degrees Kelvin, with each unit representing half a degree.
 *
 * @implements Thermal_SetTempThreshold_Activity
 */
void Thermal_SetTempThreshold(Thermal_ThresholdType ThresholdType,
                              uint16 ThresholdValue);

/**
 * @brief Enables selected notifications.
 * @param[in] NotificationsMask combination of TMU_IP_INTERRUPT_ values
 *
 * @implements Thermal_EnableNotifications_Activity
 */
void Thermal_EnableNotifications (uint32 NotificationsMask);

/**
 * @brief Disables selected notifications.
 * @param[in] NotificationsMask combination of TMU_IP_INTERRUPT_ values
 *
 * @implements Thermal_DisableNotifications_Activity
 */
void Thermal_DisableNotifications (uint32 NotificationsMask);

/**
 * @brief Sets measurement interval. Can be called only while in idle power mode.
 * @param[in] MonitoringInterval value. See the description of each enum value for more information.
 *
 * @implements Thermal_SetMeasurementInterval_Activity
 */
void Thermal_SetMeasurementInterval(Thermal_MonitoringIntervalType MonitoringInterval);

#define THERMAL_STOP_SEC_CODE
#include "Thermal_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CDD_THERMAL_H */

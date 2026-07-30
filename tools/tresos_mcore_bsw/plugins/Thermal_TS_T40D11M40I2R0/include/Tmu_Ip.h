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

#ifndef TMU_IP_H
#define TMU_IP_H

/**
*   @file
*
*   @addtogroup tmu_ip Tmu IPL
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
#include "Tmu_Ip_Cfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define TMU_IP_VENDOR_ID                    43
#define TMU_IP_MODULE_ID                    255
#define TMU_IP_AR_RELEASE_MAJOR_VERSION     4
#define TMU_IP_AR_RELEASE_MINOR_VERSION     4
#define TMU_IP_AR_RELEASE_REVISION_VERSION  0
#define TMU_IP_SW_MAJOR_VERSION             4
#define TMU_IP_SW_MINOR_VERSION             0
#define TMU_IP_SW_PATCH_VERSION             2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if Tmu_Ip.h file and Tmu_Ip_Cfg.h file are of the same vendor */
#if (TMU_IP_VENDOR_ID != TMU_IP_VENDOR_ID_CFG)
    #error "Tmu_Ip.h and Tmu_Ip_Cfg.h have different vendor ids"
#endif

/* Check if Tmu_Ip.h file and Tmu_Ip_Cfg.h file are of the same Autosar version */
#if ((TMU_IP_AR_RELEASE_MAJOR_VERSION != TMU_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (TMU_IP_AR_RELEASE_MINOR_VERSION != TMU_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (TMU_IP_AR_RELEASE_REVISION_VERSION != TMU_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Tmu_Ip.h and Tmu_Ip_Cfg.h are different"
#endif

/* Check if Tmu_Ip.h file and Tmu_Ip_Cfg.h file are of the same Software version */
#if ((TMU_IP_SW_MAJOR_VERSION != TMU_IP_SW_MAJOR_VERSION_CFG) || \
     (TMU_IP_SW_MINOR_VERSION != TMU_IP_SW_MINOR_VERSION_CFG) || \
     (TMU_IP_SW_PATCH_VERSION != TMU_IP_SW_PATCH_VERSION_CFG) \
    )
  #error "Software Version Numbers of Tmu_Ip.h and Tmu_Ip_Cfg.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define THERMAL_START_SEC_CODE
#include "Thermal_MemMap.h"

/* @} */

/*!
 * @name Initialization and De-initialization
 * @{
 */

/*!
 * @brief This function initializes ...
 *
 * @param[in] Instance      The number of the TMU instance used.
 * @param[in] ConfigPtr     Pointer to the user's configuration structure
 * @return status:
 *              - TMU_IP_STATUS_SUCCESS: SAR ready to receive command
 *              - TMU_IP_STATUS_TIMEOUT: SAR not ready to receive command
 *
 * @implements Tmu_Ip_Init_Activity
 */
Tmu_Ip_StatusType Tmu_Ip_Init(const uint32 Instance,
                              const Tmu_Ip_ConfigType* const ConfigPtr);

/*!
 * @brief This function shall De-Init the TMU for all registers to default value.
 *
 * @param[in] Instance The number of the TMU instance used
 * @implements Tmu_Ip_Deinit_Activity
 */
void Tmu_Ip_Deinit(const uint32 Instance);

/* @} */

/*!
 * @name Temperature monitoring
 * @{
 */

/*!
 * @brief This function starts monitoring the temperature on sites
 * previously selected with Tmu_Ip_Init or Tmu_Ip_EnableMonitoringSite.
 * This function should be called after TMU initialization is done.
 *
 * @param[in] Instance The number of the TMU instance used
 *
 * @implements Tmu_Ip_StartMonitoring_Activity
 */
void Tmu_Ip_StartMonitoring(const uint32 Instance);

/*!
 * @brief This function stop monitoring the temperature on sites.
 *
 * @param[in] Instance The number of the TMU instance used
 *
 * @implements Tmu_Ip_StopMonitoring_Activity
 */
void Tmu_Ip_StopMonitoring(const uint32 Instance);

/*!
 * @brief This function shall enable the site which will be monitored.
 * The site mask input value can be set using TMU_IP_MONITORING_SITE_ defines
 *
 * @param[in] Instance The number of the TMU instance used
 * @param[in] TmuSiteMask The masked value of site will be enabled
 *
 * @implements Tmu_Ip_EnableMonitoringSite_Activity
 */
void Tmu_Ip_EnableMonitoringSite(const uint32 Instance,
                                 const uint8 TmuSiteMask);

/*!
 * @brief This function shall disable the selected site from monitoring.
 * The site mask input value can be set using TMU_IP_MONITORING_SITE_ defines
 *
 * @param[in] Instance      The number of the TMU instance used
 * @param[in] TmuSiteMask      The masked value of site will be disabled
 *
 * @implements Tmu_Ip_DisableMonitoringSite_Activity
 */
void Tmu_Ip_DisableMonitoringSite(const uint32 Instance,
                                  const uint8 TmuSiteMask);

/*!
 * @brief This function shall set the temperature threshold.
 *
 * @param[in] Instance              The number of the TMU instance used
 * @param[in] ThresholdType         Threshold type
 * @param[in] ThresholdValue        Threshold value
 *
 * @implements Tmu_Ip_SetTempThreshold_Activity
 */
void Tmu_Ip_SetTempThreshold(const uint32 Instance,
                             const Tmu_Ip_ThresholdType ThresholdType,
                             const uint16 ThresholdValue);

/*!
 * @brief This function reads the minimum or maximum temperature recorded at one site.
 * If the temperature is invalid, it will return TMU_IP_INVALID_TEMPERATURE value.
 * The return value is Q9.1 format: 9 bits for highest temperature recorded
 * and 1 bit for 0.5 degrees resolution. User can clear the current temperature
 * value by setting ClearValidFlag parameter.
 *
 * @param[in] Instance          The number of the TMU instance used
 * @param[in] TempLevelType     Temperature level to be retrieved: min or max
 * @param[in] ClearValidFlag    Allow clear the current temperature value
 * @return The highest temperature recorded
 *  - For example:
 *        - if return value is 1100011100, the actual temperature is 398K
 *        - if return value is 1100011101, the actual temperature is 398.5K
 *
 * @return uint16: Minimum or Maximum measured temperature value.
 * @implements Tmu_Ip_GetTempMinMaxLevel_Activity
 */
uint16 Tmu_Ip_GetTempMinMaxLevel(const uint32 Instance,
                                 const Tmu_Ip_TempLevelType TempLevelType,
                                 const boolean ClearValidFlag);

/*!
 * @brief Retrieves the maximum rate the temperature has risen or fallen,
 * and clears that rate if ClearValidFlag is TRUE.
 * If the temperature is invalid (cleared), it will return TMU_IP_INVALID_TEMPERATURE_RATE value.
 *
 * @param[in] Instance          The number of the TMU instance used
 * @param[in] TempRateType      Specifies whether to retrieve the rising or falling rate.
 * @param[in] ClearValidFlag    TRUE to clear the rate.
 * @return The rising temperature rate
 *
 * @return uint8: Minimum or Maximum measured temperature rate value.
 * @implements Tmu_Ip_GetTempMaxRate_Activity
 */
uint8 Tmu_Ip_GetTempMaxRate(const uint32 Instance,
                            const Tmu_Ip_TempRateType TempRateType,
                            const boolean ClearValidFlag);

/*!
 * @brief This function shall read the last temperature at the selected site
 * If the temperature is invalid, it will return TMU_IP_INVALID_TEMPERATURE value.
 * The return value is Q9.1 format : 9 bits for highest temperature recorded
 * and 1 bit for 0.5 degrees resolution.
 *
 * @param[in] Instance              The number of the TMU instance used
 * @param[in] TmuMonitoringSite     The monitored site index (0, 1, 2)
 * @param[in] TmuTempType           The type of output temperature reported
 * @param[out] TmuTempVal           The measured temperature value.
 *
 * @implements Tmu_Ip_GetTemp_Activity
 */
void Tmu_Ip_GetTemp(const uint32 Instance,
                    const uint8 TmuMonitoringSite,
                    const Tmu_Ip_ReportTempType TmuTempType,
                    uint16 * const TmuTempVal);


/* @} */

/*!
 * @name Interrupt and flags
 * @{
 */

/*!
 * @brief This function enables the notifications for the selected types of thresholds.
 * The interrupt mask input value can be set using TMU_IP_INTERRUPT_ defines.
 *
 * @param[in] Instance          The number of the TMU instance used
 * @param[in] NotificationsMask The masked value of notifications to enable
 *  - For example:
 *        - With mask = TMU_IP_INTERRUPT_IMMEDIATE_HIGH_TEMP to enable immediate high temperature
 *                      threshold interrupt(IHTTIE).
 *        - With mask = (TMU_IP_INTERRUPT_IMMEDIATE_HIGH_TEMP | TMU_IP_INTERRUPT_AVERAGE_HIGH_TEMP)
 *                      to enable immediate high temperature threshold exceeded(IHTTIE) and average
 *                      high temperature threshold exceeded(AHTTIE).
 *
 * @implements Tmu_Ip_EnableNotifications_Activity
 */
void Tmu_Ip_EnableNotifications(const uint32 Instance,
                                const uint32 NotificationsMask);

/*!
 * @brief This function disables the notifications for the selected types of thresholds.
 * The interrupt mask input value can be set using TMU_IP_INTERRUPT_ defines.
 *
 * @param[in] Instance          The number of the TMU instance used
 * @param[in] NotificationsMask  The masked value of notifications to disable
 *  - For example:
 *        - With mask = TMU_IP_INTERRUPT_IMMEDIATE_HIGH_TEMP to disable immediate high temperature
 *                      threshold interrupt(IHTTIE).
 *        - With mask = (TMU_IP_INTERRUPT_IMMEDIATE_HIGH_TEMP | TMU_IP_INTERRUPT_AVERAGE_HIGH_TEMP)
 *                      to disable immediate high temperature threshold exceeded(IHTTIE) and average
 *                      high temperature threshold exceeded(AHTTIE).
 *
 * @implements Tmu_Ip_DisableNotifications_Activity
 */
void Tmu_Ip_DisableNotifications(const uint32 Instance,
                                 const uint32 NotificationsMask);

/* @} */


/* @} */

/*!
 * @name Measurement interval
 * @{
 */

/*!
 * @brief This function shall set the interval for the temperature
 * monitoring. It should only be changed when monitoring is disabled.
 *
 * @param[in] Instance                  The number of the TMU instance used
 * @param[in] TmuMonitoringInterval     The measurement interval
 *
 * @implements Tmu_Ip_SetMeasurementInterval_Activity
 */
void Tmu_Ip_SetMeasurementInterval(const uint32 Instance,
                                   const Tmu_Ip_TempMonitoringIntervalType TmuMonitoringInterval);

/**
 * @brief Retrieves the current mode.
 * (TMU_IP_MODE_MONITORING after a call to Tmu_Ip_StartMonitoring, otherwise TMU_IP_MODE_IDLE_LOW_POWER)
 *
 * @param[in] Instance      The number of the TMU instance used
 *
 * @return Tmu_Ip_ModeType: Mode, low power or monitoring.
 * @implements Tmu_Ip_GetMode_Activity
 */
Tmu_Ip_ModeType Tmu_Ip_GetMode (const uint32 Instance);

#define THERMAL_STOP_SEC_CODE
#include "Thermal_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* TMU_IP_H */

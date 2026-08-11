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

#ifndef TMU_IP_TYPES
#define TMU_IP_TYPES

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
#include "Tmu_Ip_CfgDefines.h"
#include "StandardTypes.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define TMU_IP_VENDOR_ID_TYPES                    43
#define TMU_IP_MODULE_ID_TYPES                    255
#define TMU_IP_AR_RELEASE_MAJOR_VERSION_TYPES     4
#define TMU_IP_AR_RELEASE_MINOR_VERSION_TYPES     4
#define TMU_IP_AR_RELEASE_REVISION_VERSION_TYPES  0
#define TMU_IP_SW_MAJOR_VERSION_TYPES             4
#define TMU_IP_SW_MINOR_VERSION_TYPES             0
#define TMU_IP_SW_PATCH_VERSION_TYPES             2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Tmu_Ip_Types.h file and Tmu_Ip_CfgDefines.h file are of the same vendor */
#if (TMU_IP_VENDOR_ID_TYPES != TMU_IP_VENDOR_ID_CFGDEFINES)
    #error "Tmu_Ip_Types.h and Tmu_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if Tmu_Ip_Types.h file and Tmu_Ip_CfgDefines.h file are of the same Autosar version */
#if ((TMU_IP_AR_RELEASE_MAJOR_VERSION_TYPES != TMU_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (TMU_IP_AR_RELEASE_MINOR_VERSION_TYPES != TMU_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (TMU_IP_AR_RELEASE_REVISION_VERSION_TYPES != TMU_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of Tmu_Ip_Types.h and Tmu_Ip_CfgDefines.h are different"
#endif

/* Check if Tmu_Ip_Types.h file and Tmu_Ip_CfgDefines.h file are of the same Software version */
#if ((TMU_IP_SW_MAJOR_VERSION_TYPES != TMU_IP_SW_MAJOR_VERSION_CFGDEFINES) || \
     (TMU_IP_SW_MINOR_VERSION_TYPES != TMU_IP_SW_MINOR_VERSION_CFGDEFINES) || \
     (TMU_IP_SW_PATCH_VERSION_TYPES != TMU_IP_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of Tmu_Ip_Types.h and Tmu_Ip_CfgDefines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Tmu_Ip_Types.h file and StandardTypes.h file are of the same Autosar version */
#if ((TMU_IP_AR_RELEASE_MAJOR_VERSION_TYPES != STD_AR_RELEASE_MAJOR_VERSION) || \
     (TMU_IP_AR_RELEASE_MINOR_VERSION_TYPES != STD_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Tmu_Ip_Types.h and StandardTypes.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/*! @brief Ivalid temperature value.
 * Invalid temperature and temperature rate values.
 */
#define TMU_IP_INVALID_TEMPERATURE           (0xFFFFU)
#define TMU_IP_INVALID_TEMPERATURE_RATE      (0xFFU)

/*! @brief Site masks.
 * Use these masks wherever you want to select the site.
 *
 * Implements : TMU_IP_MONITORING_SITE_BITMASK_Class
 */
#define TMU_IP_MONITORING_SITE_0                            (0x01U)
#define TMU_IP_MONITORING_SITE_1                            (0x02U)
#define TMU_IP_MONITORING_SITE_2                            (0x04U)
#define TMU_IP_MONITORING_SITE_ALL                          (0x07U)

/**
 * @brief The temperature threshold interrupt source masks.
 *
 * These defines contains all TMU interrupt sources to be enabled or disabled.
 *
 * Implements : TMU_IP_INTERRUPT_SOURCE_BITMASK_Class
 */
#define TMU_IP_INTERRUPT_IMMEDIATE_HIGH_TEMP                   (TMU_TIER_IHTTIE_MASK)     /*!< The immediate high temperature threshold interrupt source */
#define TMU_IP_INTERRUPT_AVERAGE_HIGH_TEMP                     (TMU_TIER_AHTTIE_MASK)     /*!< The average high temperature threshold interrupt source */
#define TMU_IP_INTERRUPT_AVERAGE_HIGH_TEMP_CRITICAL            (TMU_TIER_AHTCTIE_MASK)    /*!< The average high temperature critical threshold interrupt source */
#define TMU_IP_INTERRUPT_IMMEDIATE_LOW_TEMP                    (TMU_TIER_ILTTIE_MASK)     /*!< The immediate low temperature threshold interrupt source */
#define TMU_IP_INTERRUPT_AVERAGE_LOW_TEMP                      (TMU_TIER_ALTTIE_MASK)     /*!< The average low temperature threshold interrupt source */
#define TMU_IP_INTERRUPT_AVERAGE_LOW_TEMP_CRITICAL             (TMU_TIER_ALTCTIE_MASK)    /*!< The average low temperature critical threshold interrupt source */
#define TMU_IP_INTERRUPT_RISING_TEMP_RATE_CRITICAL             (TMU_TIER_RTRCTIE_MASK)    /*!< The rising temperature rate critical threshold interrupt source */
#define TMU_IP_INTERRUPT_FALLING_TEMP_RATE_CRITICAL            (TMU_TIER_FTRCTIE_MASK)    /*!< The falling temperature rate critical threshold interrupt source */
#define TMU_IP_INTERRUPT_SOURCE_ALL                            (TMU_TIER_IHTTIE_MASK | TMU_TIER_AHTTIE_MASK | TMU_TIER_AHTCTIE_MASK | \
                                                                TMU_TIER_ILTTIE_MASK | TMU_TIER_ALTTIE_MASK | TMU_TIER_ALTCTIE_MASK | \
                                                                TMU_TIER_RTRCTIE_MASK | TMU_TIER_FTRCTIE_MASK)

/**
 * @brief The monitoring status flag masks.
 *
 * Monitoring and calibration status during operation.
 *
 * Implements : TMU_IP_STATUS_FLAG_BITMASK_Class
 */
#define TMU_IP_STATUS_TIME_INTERVAL_EXCEEDED                     (TMU_TSR_MIE_MASK)         /*!< The monitoring interval exceeded flag */
#define TMU_IP_STATUS_OUT_OF_RANGE_LOW_TEMP                      (TMU_TSR_ORL_MASK)         /*!< The out-of-range low temperature measurement */
#define TMU_IP_STATUS_OUT_OF_RANGE_HIGH_TEMP                     (TMU_TSR_ORH_MASK)         /*!< The out-of-range high temperature measurement */
#define TMU_IP_STATUS_ALL                                        (TMU_TSR_MIE_MASK | TMU_TSR_ORL_MASK | TMU_TSR_ORH_MASK)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/*!
 * @brief Average low pass filter setting.
 *
 * This is used to set the average low pass filter
 * The average temperature is calculated using this
 * formula: ALPF x Current_Temp + (1 - ALPF) x Average_Temp
 *
 */
typedef enum
{
    TMU_IP_AVERAGE_LOW_PASS_FILTER_1         = 0x00U,    /*!< Average low pass filter 1.0 */
    TMU_IP_AVERAGE_LOW_PASS_FILTER_0_5       = 0x01U,    /*!< Average low pass filter 0.5 */
    TMU_IP_AVERAGE_LOW_PASS_FILTER_0_25      = 0x02U,    /*!< Average low pass filter 0.25 */
    TMU_IP_AVERAGE_LOW_PASS_FILTER_0_125     = 0x03U     /*!< Average low pass filter 0.125 */
} Tmu_Ip_AverageLowPassFilterType;

/*!
 * @brief Temperature monitoring interval setting.
 *
 * This enum is used to set temperature monitoring interval in seconds.
 * The time interval depends on TMU clock frequency and is determined using
 * this formula: [2 ^ (23 + TMI)] x TMU clock period in seconds, where TMI
 * is Temperature Monitoring Interval
 *
 */
typedef enum
{
    TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_0             = 0x00U,
    TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_1             = 0x01U,
    TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_2             = 0x02U,
    TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_3             = 0x03U,
    TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_4             = 0x04U,
    TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_5             = 0x05U,
    TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_6             = 0x06U,
    TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_7             = 0x07U,
    TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_8             = 0x08U,
    TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_9             = 0x09U,
    TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_10            = 0x0AU,
    TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_11            = 0x0BU,
    TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_12            = 0x0CU,
    TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_13            = 0x0DU,
    TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_14            = 0x0EU,
    TMU_IP_TEMP_MONITORING_INTERVAL_CONTINUOUS                  = 0x0FU     /*!< Disable temperature monitoring interval in seconds, monitoring is continuous */
} Tmu_Ip_TempMonitoringIntervalType;

/*!
 * @brief Report temperature settings.
 *
 * This is used to choose immediate temperature report or average report.
 *
 */
typedef enum
{
    TMU_IP_REPORT_IMMEDIATE_TEMPERATURE  = 0U,      /*!< Report immediate temperature */
    TMU_IP_REPORT_AVERAGE_TEMPERATURE    = 1U       /*!< Report average temperature */
} Tmu_Ip_ReportTempType;

/*!
 * @brief Temperature threshold settings.
 *
 * This is used to select type of threshold value.
 *
 */
typedef enum
{
    TMU_IP_THRESHOLD_HIGH_TEMP_IMMEDIATE          = 0U,     /*!< The high temperature immediate threshold */
    TMU_IP_THRESHOLD_HIGH_TEMP_AVERAGE            = 1U,     /*!< The high temperature average threshold */
    TMU_IP_THRESHOLD_HIGH_TEMP_AVERAGE_CRITICAL   = 2U,     /*!< The high temperature average critical threshold */
    TMU_IP_THRESHOLD_LOW_TEMP_IMMEDIATE           = 3U,     /*!< The low temperature immediate threshold */
    TMU_IP_THRESHOLD_LOW_TEMP_AVERAGE             = 4U,     /*!< The low temperature average threshold */
    TMU_IP_THRESHOLD_LOW_TEMP_AVERAGE_CRITICAL    = 5U,     /*!< The low temperature average critical threshold */
    TMU_IP_THRESHOLD_RISING_TEMP_RATE_CRITICAL    = 6U,     /*!< The rising temperature difference between two measurements */
    TMU_IP_THRESHOLD_FALLING_TEMP_RATE_CRITICAL   = 7U,     /*!< The falling temperature difference between two measurements */
} Tmu_Ip_ThresholdType;

typedef enum
{
    TMU_IP_TEMP_LEVEL_MAX = 0,
    TMU_IP_TEMP_LEVEL_MIN = 1,
} Tmu_Ip_TempLevelType;

typedef enum
{
    TMU_IP_TEMP_RATE_RISING  = 0,
    TMU_IP_TEMP_RATE_FALLING = 1,
} Tmu_Ip_TempRateType;

/**
 * @brief Working mode of the TMU peripheral. Values correspond to those in the MODE field of of the TMR register.
 *
 */
typedef enum
{
    TMU_IP_MODE_IDLE_LOW_POWER = 0,
    TMU_IP_MODE_MONITORING     = 2,
} Tmu_Ip_ModeType;

/**
 * @brief Defines the Tmu status values
 *
 */
typedef enum {
    TMU_IP_STATUS_SUCCESS   = 0U,  /*!< Function completed successfully */
    TMU_IP_STATUS_ERROR     = 1U,  /*!< Function didn't complete successfully */
    TMU_IP_STATUS_TIMEOUT   = 2U,   /*!< Function timed out */
    TMU_IP_STATUS_BUSY      = 3U    /*!< Function busy*/
} Tmu_Ip_StatusType;
/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/*!
 * @brief Structure to configure the calibration point and temperature range control.
 *
 * This is used to setup calibration point, each calibration point is related to the Temperature range control register.
 *
 */
typedef struct
{
    uint16  SensorValue;         /*!< The sensor value */
    uint16  TempRange;           /*!< The temperature range */
} Tmu_Ip_CalibrationConfigType;

/*!
 * @brief Structure to configure the temperature threshold.
 *
 * This structure holds the configuration settings for the threshold value of TMU.
 *
 */
typedef struct
{
    boolean               Enable;                 /*!< Enable threshold */
    Tmu_Ip_ThresholdType  ThresholdType;          /*!< Type of threshold value */
    uint16                ThresholdValue;         /*!< Temperature threshold value */
    boolean               InterruptEnable;        /*!< Enable interrupt */
} Tmu_Ip_ThresholdConfigType;

typedef void (*Tmu_Ip_NotificationType)(uint32 siteMask);

typedef struct
{
    Tmu_Ip_NotificationType ImmediateHighTemp;
    Tmu_Ip_NotificationType AverageHighTemp;
    Tmu_Ip_NotificationType AverageHighTempCritical;
    Tmu_Ip_NotificationType ImmediateLowTemp;
    Tmu_Ip_NotificationType AverageLowTemp;
    Tmu_Ip_NotificationType AverageLowTempCritical;
    Tmu_Ip_NotificationType RisingTempRateCritical;
    Tmu_Ip_NotificationType FallingTempRateCritical;
} Tmu_Ip_NotificationsType;

/*!
 * @brief TMU configuration structure
 *
 */
typedef struct
{
    uint8                               MonitoringSitesMask;    /*!< Zero or more TMU_IP_MONITORING_SITE_ values, OR-ed together. */
    Tmu_Ip_AverageLowPassFilterType     LowPassFilter;          /*!< The average low pass filter */
    boolean                             CentralModuleDisable;   /*!< The configuration of central module mode, false/true - enabled/disabled */
    boolean                             OffsetCancellation;     /*!< Configure offset cancellation mode, false/true - disable/enable */
    boolean                             DynamicMatchAvrg;       /*!< Configure dynamic element match averaging mode, false/true - disable/enable */
    Tmu_Ip_TempMonitoringIntervalType   MeasurementInterval;    /*!< The temperature monitoring interval value */
    uint8                               NumCalibrationConfigs;  /*!< The number of calibration point */
    const Tmu_Ip_CalibrationConfigType* CalibrationConfig;     /*!< The calibration configuration */
    uint8                               NumThresholds;          /*!< Number of threshold configuration */
    const Tmu_Ip_ThresholdConfigType*   ThresholdConfig;       /*!< The pointer point to threshold configuration structure */
    const Tmu_Ip_NotificationsType*     Notifications;
} Tmu_Ip_ConfigType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* TMU_IP_TYPES */

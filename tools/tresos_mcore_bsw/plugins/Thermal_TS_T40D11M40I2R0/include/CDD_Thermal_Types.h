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

#ifndef CDD_THERMAL_TYPES_H
#define CDD_THERMAL_TYPES_H

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
#include "CDD_Thermal_CfgDefines.h"
#include "Tmu_Ip_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define THERMAL_VENDOR_ID_TYPES                    43
#define THERMAL_MODULE_ID_TYPES                    255
#define THERMAL_AR_RELEASE_MAJOR_VERSION_TYPES     4
#define THERMAL_AR_RELEASE_MINOR_VERSION_TYPES     4
#define THERMAL_AR_RELEASE_REVISION_VERSION_TYPES  0
#define THERMAL_SW_MAJOR_VERSION_TYPES             4
#define THERMAL_SW_MINOR_VERSION_TYPES             0
#define THERMAL_SW_PATCH_VERSION_TYPES             2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#if ((THERMAL_AR_RELEASE_MAJOR_VERSION_TYPES != THERMAL_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (THERMAL_AR_RELEASE_MINOR_VERSION_TYPES != THERMAL_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (THERMAL_AR_RELEASE_REVISION_VERSION_TYPES != THERMAL_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of CDD_Thermal_Types.h and CDD_Thermal_CfgDefines.h are different"
#endif

#if ((THERMAL_SW_MAJOR_VERSION_TYPES != THERMAL_SW_MAJOR_VERSION_CFGDEFINES) || \
     (THERMAL_SW_MINOR_VERSION_TYPES != THERMAL_SW_MINOR_VERSION_CFGDEFINES) || \
     (THERMAL_SW_PATCH_VERSION_TYPES != THERMAL_SW_PATCH_VERSION_CFGDEFINES) \
    )
    #error "Software Version Numbers of CDD_Thermal_Types.h and CDD_Thermal_CfgDefines.h are different"
#endif

#if (THERMAL_VENDOR_ID_TYPES != THERMAL_VENDOR_ID_CFGDEFINES)
    #error "CDD_Thermal_Types.h and CDD_Thermal_CfgDefines.h have different vendor ids"
#endif

#if ((THERMAL_AR_RELEASE_MAJOR_VERSION_TYPES != TMU_IP_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (THERMAL_AR_RELEASE_MINOR_VERSION_TYPES != TMU_IP_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (THERMAL_AR_RELEASE_REVISION_VERSION_TYPES != TMU_IP_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of CDD_Thermal_Types.h and Tmu_Ip_Types.h are different"
#endif

#if ((THERMAL_SW_MAJOR_VERSION_TYPES != TMU_IP_SW_MAJOR_VERSION_TYPES) || \
     (THERMAL_SW_MINOR_VERSION_TYPES != TMU_IP_SW_MINOR_VERSION_TYPES) || \
     (THERMAL_SW_PATCH_VERSION_TYPES != TMU_IP_SW_PATCH_VERSION_TYPES) \
    )
    #error "Software Version Numbers of CDD_Thermal_Types.h and Tmu_Ip_Types.h are different"
#endif

#if (THERMAL_VENDOR_ID_TYPES != TMU_IP_VENDOR_ID_TYPES)
    #error "CDD_Thermal_Types.h and Tmu_Ip_Types.h have different vendor ids"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/** @brief Monitoring sites. Can be OR-ed together. */
#define THERMAL_MONITORING_SITE_0       TMU_IP_MONITORING_SITE_0
#define THERMAL_MONITORING_SITE_1       TMU_IP_MONITORING_SITE_1
#define THERMAL_MONITORING_SITE_2       TMU_IP_MONITORING_SITE_2
#define THERMAL_MONITORING_SITE_ALL     TMU_IP_MONITORING_SITE_ALL

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

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
    THERMAL_MONITORING_INTERVAL_TYPE_0  = TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_0,
    THERMAL_MONITORING_INTERVAL_TYPE_1  = TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_1,
    THERMAL_MONITORING_INTERVAL_TYPE_2  = TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_2,
    THERMAL_MONITORING_INTERVAL_TYPE_3  = TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_3,
    THERMAL_MONITORING_INTERVAL_TYPE_4  = TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_4,
    THERMAL_MONITORING_INTERVAL_TYPE_5  = TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_5,
    THERMAL_MONITORING_INTERVAL_TYPE_6  = TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_6,
    THERMAL_MONITORING_INTERVAL_TYPE_7  = TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_7,
    THERMAL_MONITORING_INTERVAL_TYPE_8  = TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_8,
    THERMAL_MONITORING_INTERVAL_TYPE_9  = TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_9,
    THERMAL_MONITORING_INTERVAL_TYPE_10 = TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_10,
    THERMAL_MONITORING_INTERVAL_TYPE_11 = TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_11,
    THERMAL_MONITORING_INTERVAL_TYPE_12 = TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_12,
    THERMAL_MONITORING_INTERVAL_TYPE_13 = TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_13,
    THERMAL_MONITORING_INTERVAL_TYPE_14 = TMU_IP_TEMP_MONITORING_INTERVAL_SECOND_SELECT_14,
    THERMAL_MONITORING_INTERVAL_TYPE_CONTINUOUS = TMU_IP_TEMP_MONITORING_INTERVAL_CONTINUOUS, /*!< Disable temperature monitoring interval in seconds, monitoring is continuous */
} Thermal_MonitoringIntervalType;

/*!
 * @brief Temperature threshold type.
 *
 */
typedef enum
{
    THERMAL_THRESHOLD_TYPE_HIGH_TEMP_IMMEDIATE          = TMU_IP_THRESHOLD_HIGH_TEMP_IMMEDIATE,        /* 0 */
    THERMAL_THRESHOLD_TYPE_HIGH_TEMP_AVERAGE            = TMU_IP_THRESHOLD_HIGH_TEMP_AVERAGE,          /* 1 */
    THERMAL_THRESHOLD_TYPE_HIGH_TEMP_AVERAGE_CRITICAL   = TMU_IP_THRESHOLD_HIGH_TEMP_AVERAGE_CRITICAL, /* 2 */
    THERMAL_THRESHOLD_TYPE_LOW_TEMP_IMMEDIATE           = TMU_IP_THRESHOLD_LOW_TEMP_IMMEDIATE,         /* 3 */
    THERMAL_THRESHOLD_TYPE_LOW_TEMP_AVERAGE             = TMU_IP_THRESHOLD_LOW_TEMP_AVERAGE,           /* 4 */
    THERMAL_THRESHOLD_TYPE_LOW_TEMP_AVERAGE_CRITICAL    = TMU_IP_THRESHOLD_LOW_TEMP_AVERAGE_CRITICAL,  /* 5 */
    THERMAL_THRESHOLD_TYPE_RISING_TEMP_RATE_CRITICAL    = TMU_IP_THRESHOLD_RISING_TEMP_RATE_CRITICAL,  /* 6 */
    THERMAL_THRESHOLD_TYPE_FALLING_TEMP_RATE_CRITICAL   = TMU_IP_THRESHOLD_FALLING_TEMP_RATE_CRITICAL, /* 7 */
} Thermal_ThresholdType;

/*!
 * @brief Working mode of the Thermal peripheral
 *
 */
typedef enum
{
    THERMAL_POWERMODE_LOWPOWER  = TMU_IP_MODE_IDLE_LOW_POWER,
    THERMAL_POWERMODE_NORMAL    = TMU_IP_MODE_MONITORING,
} Thermal_PowerModeType;

/*!
 * @brief Enum that specifies either a low or a high temperature setting.
 *
 * Used by functions such as Thermal_GetTempMinMaxLevel.
 *
 */
typedef enum
{
    THERMAL_TEMP_LEVEL_TYPE_LOW,
    THERMAL_TEMP_LEVEL_TYPE_HIGH,
} Thermal_TempLevelType;

/*!
 * @brief Enum that specifies either a rising or a falling temperature.
 *
 * Used by functions such as Thermal_GetTempMaxRate.
 *
 */
typedef enum
{
    THERMAL_TEMP_RATE_TYPE_RISING,
    THERMAL_TEMP_RATE_TYPE_FALLING,
} Thermal_TempRateType;

/*!
 * @brief Enum that specifies either an immediate or an average temperature.
 *
 * Used by functions such as Thermal_GetTemp.
 *
 */
typedef enum
{
    THERMAL_REPORT_TYPE_IMMEDIATE = TMU_IP_REPORT_IMMEDIATE_TEMPERATURE,
    THERMAL_REPORT_TYPE_AVERAGE   = TMU_IP_REPORT_AVERAGE_TEMPERATURE,
} Thermal_ReportType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*!
 * @brief Data type used for holding a temperature value.
 * One unit represents half a degree Kelvin, starting from zero Kelvin.
 *
 */
typedef uint16 Thermal_TempValueType;

/*!
 * @brief Data type used for holding a temperature rise or fall rate.
 * One unit represents half a degree Kelvin.
 *
 */
typedef uint8 Thermal_TempRateValueType;

/*!
 * @brief Structure that holds configuring information required for initializing the peripheral.
 *
 */
typedef Tmu_Ip_ConfigType Thermal_ConfigType;

/*!
 * @brief Bitmask value that specifies which measuring sites should be affected by certain operations.
 * Bit 0 represents the first site, bit 1 the second site, bit 2 the third site.
 *
 */
typedef uint8 Thermal_MonitoringSiteType;

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

#endif /* CDD_THERMAL_TYPES_H */

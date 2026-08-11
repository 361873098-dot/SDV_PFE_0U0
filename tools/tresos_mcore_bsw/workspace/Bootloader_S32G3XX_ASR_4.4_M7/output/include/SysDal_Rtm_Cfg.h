/*===================================================================================================*/
/*
*   @file              SysDal_Rtm_Cfg.h
*   project            AUTOSAR 4.4 MCAL
*   platform           CORTEXM

*   @version           23.02.0
*
*   @brief             Configuration of SysDal RTM software component.
*   @details           None
*
*   Autosar Version    4.4.0
*   Build Version      S32G3XX_PLATFORM INTEGRATION_23_02_0_RTM_ASR_REL_4_4_REV_0000_20230224
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. Copyright 2017-2021 NXP
*   All Rights Reserved.
*/
/*===================================================================================================*/

#ifndef SYSDAL_RTM_CFG_H
#define SYSDAL_RTM_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*===================================================================================================*/
/*                                         INCLUDE FILES
   1) system and project includes
   2) needed interfaces from external units
   3) internal and external interfaces from this unit
*/
/*===================================================================================================*/
#include "Std_Types.h"

/*===================================================================================================*/
/*                              SOURCE FILE VERSION INFORMATION                                      */
/*===================================================================================================*/
#define SYSDAL_RTM_CFG_VENDOR_ID                        43

#define SYSDAL_RTM_CFG_AR_RELEASE_MAJOR_VERSION         4
#define SYSDAL_RTM_CFG_AR_RELEASE_MINOR_VERSION         4
#define SYSDAL_RTM_CFG_AR_RELEASE_REVISION_VERSION      0

#define SYSDAL_RTM_CFG_SW_MAJOR_VERSION                 23
#define SYSDAL_RTM_CFG_SW_MINOR_VERSION                 02
#define SYSDAL_RTM_CFG_SW_PATCH_VERSION                 0

/*===================================================================================================*/
/*                                       DEFINES AND MACROS                                          */
/*===================================================================================================*/

/* Enable the RTM component */
#define SYSDAL_RTM_ENABLED                      STD_ON 

/* Maximum number of oneshot measurements */
#define SYSDAL_RTM_ONESHOT_MEAS_NUMBER          1U

/* Maximum number of continuous measurements */
#define SYSDAL_RTM_CONTINUOUS_MEAS_NUMBER       0U

/* Maximum number of measurements */
#define SYSDAL_RTM_MAX_MEAS_NUMBER              1U

/* Enable the SysTick for RTM measurements */
#define SYSDAL_RTM_USE_SYSTICK                  STD_ON 

/* RTM timer clock frequency */
#define SYSDAL_RTM_CLOCK_FREQUENCY              400000000UL

/* RTM timer events period */
#define SYSDAL_RTM_TIMER_PERIOD                 16777215UL

/* RTM Timer ID */
#define SYSDAL_RTM_TIMER_ID                     0U

/* Measurement timestamp status */
#define SYSDAL_RTM_TIMESTAMP_ENABLED            STD_OFF 

/* Number of ticks per microsecond */
#define SYSDAL_RTM_TICKS_PER_MICROSECONDS       400ULL

/* Number of ticks per millisecond */
#define SYSDAL_RTM_TICKS_PER_MILLISECONDS       400000ULL

/* Number of ticks per second */
#define SYSDAL_RTM_TICKS_PER_SECONDS            400000000ULL

/* Number of ticks per minute */
#define SYSDAL_RTM_TICKS_PER_MINUTE             24000000000ULL

/* Number of ticks per hour */
#define SYSDAL_RTM_TICKS_PER_HOUR               1440000000000ULL

/* The number of last runtime measurements used to calculate the moving average value */
#define RTM_MOVAVG_SERIES_SIZE                  4U

/* List of measurements ID's */
#define LOADANDAUTHM7            0

/*===================================================================================================*/
/*                               LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)                          */
/*===================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* SYSDAL_RTM_CFG_H */



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
#include "CDD_Thermal.h"
#include "Tmu_Ip.h"
#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define THERMAL_VENDOR_ID_C                      43
#define THERMAL_AR_RELEASE_MAJOR_VERSION_C       4
#define THERMAL_AR_RELEASE_MINOR_VERSION_C       4
#define THERMAL_AR_RELEASE_REVISION_VERSION_C    0
#define THERMAL_SW_MAJOR_VERSION_C               4
#define THERMAL_SW_MINOR_VERSION_C               0
#define THERMAL_SW_PATCH_VERSION_C               2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and THERMAL header file are of the same vendor */
#if (THERMAL_VENDOR_ID_C != THERMAL_VENDOR_ID)
#error "CDD_Thermal.c and CDD_Thermal.h have different vendor ids"
#endif

/* Check if source file and THERMAL header file are of the same Autosar version */
#if ((THERMAL_AR_RELEASE_MAJOR_VERSION_C != THERMAL_AR_RELEASE_MAJOR_VERSION) || \
     (THERMAL_AR_RELEASE_MINOR_VERSION_C != THERMAL_AR_RELEASE_MINOR_VERSION) || \
     (THERMAL_AR_RELEASE_REVISION_VERSION_C != THERMAL_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of CDD_Thermal.c and CDD_Thermal.h are different"
#endif

/* Check if source file and THERMAL header file are of the same Software version */
#if ((THERMAL_SW_MAJOR_VERSION_C != THERMAL_SW_MAJOR_VERSION) || \
     (THERMAL_SW_MINOR_VERSION_C != THERMAL_SW_MINOR_VERSION) || \
     (THERMAL_SW_PATCH_VERSION_C != THERMAL_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of CDD_Thermal.c and CDD_Thermal.h are different"
#endif

/* Check if source file and Tmu_Ip header file are of the same vendor */
#if (THERMAL_VENDOR_ID_C != TMU_IP_VENDOR_ID)
    #error "CDD_Thermal.c and Tmu_Ip.h have different vendor ids"
#endif

/* Check if source file and Tmu_Ip header file are of the same Autosar version */
#if ((THERMAL_AR_RELEASE_MAJOR_VERSION_C != TMU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (THERMAL_AR_RELEASE_MINOR_VERSION_C != TMU_IP_AR_RELEASE_MINOR_VERSION) || \
     (THERMAL_AR_RELEASE_REVISION_VERSION_C != TMU_IP_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of CDD_Thermal.c and Tmu_Ip.h are different"
#endif

/* Check if source file and Tmu_Ip header file are of the same Software version */
#if ((THERMAL_SW_MAJOR_VERSION_C != TMU_IP_SW_MAJOR_VERSION) || \
     (THERMAL_SW_MINOR_VERSION_C != TMU_IP_SW_MINOR_VERSION) || \
     (THERMAL_SW_PATCH_VERSION_C != TMU_IP_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of CDD_Thermal.c and Tmu_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (THERMAL_DEV_ERROR_DETECT == STD_ON)
        /* Check if source file and DET header file are of the same version */
        #if ((THERMAL_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (THERMAL_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of CDD_Thermal.c and Det.h are different"
        #endif
    #endif /* (THERMAL_DEV_ERROR_DETECT == STD_ON) */
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/
#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
#define THERMAL_START_SEC_VAR_CLEARED_BOOLEAN
#include "Thermal_MemMap.h"
static boolean Thermal_bInitialized;
#define THERMAL_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Thermal_MemMap.h"
#endif /* THERMAL_DEV_ERROR_DETECT == STD_ON */

#define THERMAL_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Thermal_MemMap.h"
static const Thermal_ConfigType * Thermal_pxInitConfig;
#define THERMAL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Thermal_MemMap.h"

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define THERMAL_START_SEC_CODE
#include "Thermal_MemMap.h"

#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
static inline void Thermal_ReportDetError(uint8 ServiceId,
                                          uint8 ErrorId);

static inline Std_ReturnType Thermal_CheckInit(const uint8 ServiceId);

static inline Std_ReturnType Thermal_ValidatePtrInit(const Thermal_ConfigType * ConfigPtr);

static inline Std_ReturnType Thermal_CheckInitAndPowerMode(const Thermal_PowerModeType PowerMode,
                                                           const uint8 ServiceId);

static uint32 Thermal_GetConfiguredNotifications(void);
#endif /* (THERMAL_DEV_ERROR_DETECT == STD_ON) */

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
/**
* @brief      Report DET error.
* @details    Report DET error.
*
* @param[in]  ServiceId         Service Id
* @param[in]  ErrorId           Error Id
*
*/
static inline void Thermal_ReportDetError(uint8 ServiceId,
                                          uint8 ErrorId)
{
    (void)Det_ReportError((uint16)THERMAL_MODULE_ID, (uint8)0U, ServiceId, ErrorId);
}

/**
* @brief      Check if Thermal was initialized and report det error if not.
* @details    Check if Thermal was initialized and report det error if not.
*
* @param[in]  ServiceId       Service Id
*
* @return     Std_ReturnType
*/
static inline Std_ReturnType Thermal_CheckInit(const uint8 ServiceId)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_OK;

    if (!Thermal_bInitialized)
    {
        ReturnValue = (Std_ReturnType)E_NOT_OK;
        Thermal_ReportDetError(ServiceId, THERMAL_E_NOT_INITIALIZED);
    }
    return ReturnValue;
}

/**
* @brief      Validate Pointer Configuration before initial.
* @details    Validate Pointer Configuration before initial.
*
* @param[in]  ConfigPtr         Pointer to the configuration structure
*/
static inline Std_ReturnType Thermal_ValidatePtrInit(const Thermal_ConfigType * ConfigPtr)
{
    Std_ReturnType ValidPtr = (Std_ReturnType)E_OK;

#if (THERMAL_PRECOMPILE_SUPPORT == STD_ON)
    if (NULL_PTR != ConfigPtr)
#else
    if (NULL_PTR == ConfigPtr)
#endif
    {
        ValidPtr = (Std_ReturnType)E_NOT_OK;
        Thermal_ReportDetError((uint8)THERMAL_INIT_ID, (uint8)THERMAL_E_INIT_FAILED);
    }
    return ValidPtr;
}

/**
* @brief      Check if Thermal power mode is IDLE or MONITORING and report det error if conflict.
* @details    Check if Thermal power mode is IDLE or MONITORING and report det error if conflict.
*
* @param[in]  PowerMode         Power Mode
* @param[in]  ServiceId       Service Id
*
* @return     Std_ReturnType
*/
static inline Std_ReturnType Thermal_CheckInitAndPowerMode(const Thermal_PowerModeType PowerMode,
                                                           const uint8 ServiceId)
{
    Std_ReturnType ReturnValue = Thermal_CheckInit(ServiceId);

    if ((Std_ReturnType)E_OK == ReturnValue)
    {
        if (PowerMode == THERMAL_POWERMODE_NORMAL)
        {
            if (Tmu_Ip_GetMode(0U) != TMU_IP_MODE_IDLE_LOW_POWER)
            {
                ReturnValue = (Std_ReturnType)E_NOT_OK;
                Thermal_ReportDetError(ServiceId, THERMAL_E_NEED_LOW_POWER_MODE);
            }
        }
        else
        {
            if (Tmu_Ip_GetMode(0U) != TMU_IP_MODE_MONITORING)
            {
                ReturnValue = (Std_ReturnType)E_NOT_OK;
                Thermal_ReportDetError(ServiceId, THERMAL_E_NEED_MONITORING_MODE);
            }
        }
    }
    return ReturnValue;
}

/**
* @brief      Get the configured notifications.
* @details    Get the configured notifications.
*
* @return     uint32
*/
static uint32 Thermal_GetConfiguredNotifications(void)
{
    const Tmu_Ip_NotificationsType* Notifs = Thermal_pxInitConfig->Notifications;
    uint32 Res;

    Res =
          ((NULL_PTR == Notifs->ImmediateHighTemp)          ? 0U: TMU_IP_INTERRUPT_IMMEDIATE_HIGH_TEMP)
        | ((NULL_PTR == Notifs->AverageHighTemp)            ? 0U: TMU_IP_INTERRUPT_AVERAGE_HIGH_TEMP)
        | ((NULL_PTR == Notifs->AverageHighTempCritical)    ? 0U: TMU_IP_INTERRUPT_AVERAGE_HIGH_TEMP_CRITICAL)
        | ((NULL_PTR == Notifs->ImmediateLowTemp)           ? 0U: TMU_IP_INTERRUPT_IMMEDIATE_LOW_TEMP)
        | ((NULL_PTR == Notifs->AverageLowTemp)             ? 0U: TMU_IP_INTERRUPT_AVERAGE_LOW_TEMP)
        | ((NULL_PTR == Notifs->AverageLowTempCritical)     ? 0U: TMU_IP_INTERRUPT_AVERAGE_LOW_TEMP_CRITICAL)
        | ((NULL_PTR == Notifs->RisingTempRateCritical)     ? 0U: TMU_IP_INTERRUPT_RISING_TEMP_RATE_CRITICAL)
        | ((NULL_PTR == Notifs->FallingTempRateCritical)    ? 0U: TMU_IP_INTERRUPT_FALLING_TEMP_RATE_CRITICAL);
    return Res;
}
#endif /* (THERMAL_DEV_ERROR_DETECT == STD_ON) */

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @implements  Thermal_Init_Activity
*/
void Thermal_Init(const Thermal_ConfigType * const ConfigPtr)
{
    /* No need for exclusive areas in Init/Deinit, as they wouldn't be enough
       to guarantee correct operation if the user happens to call either of them
       simultaneously with any other Tmu_Ip_XXX function on different threads.
       It is user's responsibility to avoid such scenarios. */
#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType ValidStatus;
#endif
#if (THERMAL_PRECOMPILE_SUPPORT == STD_ON)
    const Thermal_ConfigType * PreDefined;
#endif
    Tmu_Ip_StatusType InitStatus;

#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
    ValidStatus = Thermal_ValidatePtrInit(ConfigPtr);
    if ((Std_ReturnType)E_OK == ValidStatus)
    {
        if (TRUE == Thermal_bInitialized)
        {
            /* SWS_Thermal_013003 */
            Thermal_ReportDetError(THERMAL_INIT_ID, THERMAL_E_ALREADY_INITIALIZED);
        }
        else
        {
#endif /* THERMAL_DEV_ERROR_DETECT == STD_ON */
#if (THERMAL_PRECOMPILE_SUPPORT == STD_ON)
            (void)ConfigPtr;
            PreDefined = Thermal_ConfigVariantPredefined[0];
            Thermal_pxInitConfig = PreDefined;
#else
            Thermal_pxInitConfig = ConfigPtr;
#endif
            InitStatus = Tmu_Ip_Init(0, Thermal_pxInitConfig);
#if (THERMAL_DEV_ERROR_DETECT == STD_OFF)
            /* Cast to void to avoid compiler warning */
            (void)InitStatus;
#else
            Thermal_bInitialized = (InitStatus == TMU_IP_STATUS_SUCCESS) ? TRUE : FALSE;
            if (FALSE == Thermal_bInitialized)
            {
                /* SWS_Thermal_013003 */
                Thermal_ReportDetError(THERMAL_INIT_ID, THERMAL_E_INIT_FAILED);
            }
        }
    }
#endif /* THERMAL_DEV_ERROR_DETECT == STD_ON */
}

/**
* @implements  Thermal_Deinit_Activity
*/
void Thermal_Deinit(void)
{
    /* See comment about exclusive areas in Thermal_Init(). */
#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType ReturnValue = Thermal_CheckInit(THERMAL_DEINIT_ID);

    if ((Std_ReturnType)E_OK == ReturnValue)
    {
#endif /* THERMAL_DEV_ERROR_DETECT == STD_ON */
        Thermal_pxInitConfig = NULL_PTR;
        Tmu_Ip_Deinit(0U);
#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
        Thermal_bInitialized = FALSE;
    }
#endif /* THERMAL_DEV_ERROR_DETECT == STD_ON */
}

/**
* @implements  Thermal_EnableMonitoringSite_Activity
*/
void Thermal_EnableMonitoringSite(Thermal_MonitoringSiteType SiteMask)
{
#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType Status = Thermal_CheckInitAndPowerMode(THERMAL_POWERMODE_NORMAL, THERMAL_ENABLEMONITORINGSITE_ID);

    if ((Std_ReturnType)E_OK == Status)
    {
        if ((SiteMask & (~THERMAL_MONITORING_SITE_ALL)) != 0U)
        {
            /* Invalid site mask */
            Thermal_ReportDetError(THERMAL_ENABLEMONITORINGSITE_ID, THERMAL_E_SITE_MASK_NOT_VALID);
        }
        else
        {
#endif /* THERMAL_DEV_ERROR_DETECT == STD_ON */
            /* EA_RTD_00103 */
            Tmu_Ip_EnableMonitoringSite(0U, (uint8)SiteMask);
#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif /* THERMAL_DEV_ERROR_DETECT == STD_ON */
}

/**
* @implements  Thermal_DisableMonitoringSite_Activity
*/
void Thermal_DisableMonitoringSite(Thermal_MonitoringSiteType SiteMask)
{
#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType Status = Thermal_CheckInitAndPowerMode(THERMAL_POWERMODE_NORMAL, THERMAL_DISABLEMONITORINGSITE_ID);

    if ((Std_ReturnType)E_OK == Status)
    {
        if ((SiteMask & (~THERMAL_MONITORING_SITE_ALL)) != 0U)
        {
            /* Invalid site mask */
            Thermal_ReportDetError(THERMAL_DISABLEMONITORINGSITE_ID, THERMAL_E_SITE_MASK_NOT_VALID);
        }
        else
        {
#endif /* THERMAL_DEV_ERROR_DETECT == STD_ON */
            Tmu_Ip_DisableMonitoringSite(0U, (uint8)SiteMask);
#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif /* THERMAL_DEV_ERROR_DETECT == STD_ON */
}

/**
* @implements  Thermal_SetPowerMode_Activity
*/
void Thermal_SetPowerMode(Thermal_PowerModeType Mode)
{
#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType Status = Thermal_CheckInitAndPowerMode(Mode, THERMAL_SETPOWERMODE_ID);

    if ((Std_ReturnType)E_OK == Status)
    {
#endif /* THERMAL_DEV_ERROR_DETECT == STD_ON */
        if (THERMAL_POWERMODE_NORMAL == Mode)
        {
            Tmu_Ip_StartMonitoring(0U);
        }
        else
        {
            Tmu_Ip_StopMonitoring(0U);
        }
#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* THERMAL_DEV_ERROR_DETECT == STD_ON */
}

/**
* @implements  Thermal_GetTempMinMaxLevel_Activity
*/
Thermal_TempValueType Thermal_GetTempMinMaxLevel(Thermal_TempLevelType TempLevelType,
                                                 boolean ClearValidFlag)
{
#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType Status;
#endif /* THERMAL_DEV_ERROR_DETECT == STD_ON */
    Thermal_TempValueType TempValue = THERMAL_INVALID_TEMP;
    Tmu_Ip_TempLevelType TempType;

#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
    Status = Thermal_CheckInitAndPowerMode(THERMAL_POWERMODE_LOWPOWER, THERMAL_GETTEMPMINMAXLEVEL_ID);
    if ((Std_ReturnType)E_OK == Status)
    {
#endif /* THERMAL_DEV_ERROR_DETECT == STD_ON */
        TempType = (TempLevelType == THERMAL_TEMP_LEVEL_TYPE_HIGH) ? TMU_IP_TEMP_LEVEL_MAX : TMU_IP_TEMP_LEVEL_MIN;
        TempValue = Tmu_Ip_GetTempMinMaxLevel(0U, TempType, ClearValidFlag);
#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* THERMAL_DEV_ERROR_DETECT == STD_ON */
    return TempValue;
}

/**
* @implements  Thermal_GetTempMaxRate_Activity
*/
Thermal_TempRateValueType Thermal_GetTempMaxRate(Thermal_TempRateType TempRateType,
                                                 boolean ClearValidFlag)
{
#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType Status;
#endif /* THERMAL_DEV_ERROR_DETECT == STD_ON */
    Thermal_TempRateValueType TempRateValue = THERMAL_INVALID_TEMP_RATE;
    Tmu_Ip_TempRateType TempType;

#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
    Status =  Thermal_CheckInitAndPowerMode(THERMAL_POWERMODE_LOWPOWER, THERMAL_GETTEMPMAXRATE_ID);
    if ((Std_ReturnType)E_OK == Status)
    {
#endif /* THERMAL_DEV_ERROR_DETECT == STD_ON */
        TempType = (TempRateType == THERMAL_TEMP_RATE_TYPE_RISING) ? TMU_IP_TEMP_RATE_RISING : TMU_IP_TEMP_RATE_FALLING;
        TempRateValue = Tmu_Ip_GetTempMaxRate(0U, TempType, ClearValidFlag);
#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* THERMAL_DEV_ERROR_DETECT == STD_ON */
    return TempRateValue;
}

/**
* @implements  Thermal_GetTemp_Activity
*/
Thermal_TempValueType Thermal_GetTemp(uint8 SiteIndex,
                                      Thermal_ReportType ReportType)
{
#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType Status;
#endif /* THERMAL_DEV_ERROR_DETECT == STD_ON */
    Thermal_TempValueType TempValue = THERMAL_INVALID_TEMP;

#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
    Status = Thermal_CheckInitAndPowerMode(THERMAL_POWERMODE_LOWPOWER, THERMAL_GETTEMP_ID);
    if ((Std_ReturnType)E_OK == Status)
    {
#endif /* THERMAL_DEV_ERROR_DETECT == STD_ON */
        if (SiteIndex < TMU_TRITRATSR_COUNT)
        {
            Tmu_Ip_GetTemp(0U, SiteIndex, (Tmu_Ip_ReportTempType)ReportType, &TempValue);
        }
#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
        else
        {
            /* Site index out of range */
            Thermal_ReportDetError(THERMAL_GETTEMP_ID, THERMAL_E_WRONG_SITE);
        }
    }
#endif /* THERMAL_DEV_ERROR_DETECT == STD_ON */
    return TempValue;
}

/**
* @implements  Thermal_SetTempThreshold_Activity
*/
void Thermal_SetTempThreshold(Thermal_ThresholdType ThresholdType,
                              uint16 ThresholdValue)
{
#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType Status = Thermal_CheckInitAndPowerMode(THERMAL_POWERMODE_LOWPOWER, THERMAL_SETTEMPTHRESHOLD_ID);

    if ((Std_ReturnType)E_OK == Status)
    {
#endif /* THERMAL_DEV_ERROR_DETECT == STD_ON */
        Tmu_Ip_SetTempThreshold(0U, (Tmu_Ip_ThresholdType)ThresholdType, ThresholdValue);
#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* THERMAL_DEV_ERROR_DETECT == STD_ON */
}

/**
* @implements  Thermal_EnableNotifications_Activity
*/
void Thermal_EnableNotifications(uint32 NotificationsMask)
{
#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType ReturnValue = Thermal_CheckInit(THERMAL_ENABLENOTIFICATIONS_ID);

    if ((Std_ReturnType)E_OK == ReturnValue)
    {
        if ((NotificationsMask & (~Thermal_GetConfiguredNotifications())) != 0U)
        {
            /* Invalid notification mask or notification not configured */
            Thermal_ReportDetError(THERMAL_ENABLENOTIFICATIONS_ID, THERMAL_E_NOTIF_NOT_CONFIGURED);
        }
        else
        {
#endif /* THERMAL_DEV_ERROR_DETECT == STD_ON */
            /* No use for exclusive area here, since the configured notifications are set only
               by Thermal_Init(), which itself has no use for exclusive area (see comment there). */
            Tmu_Ip_EnableNotifications(0U, NotificationsMask);
#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif /* THERMAL_DEV_ERROR_DETECT == STD_ON */
}

/**
* @implements  Thermal_DisableNotifications_Activity
*/
void Thermal_DisableNotifications(uint32 NotificationsMask)
{
#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType ReturnValue = Thermal_CheckInit(THERMAL_DISABLENOTIFICATIONS_ID);

    if ((Std_ReturnType)E_OK == ReturnValue)
    {
        if ((NotificationsMask & (~Thermal_GetConfiguredNotifications())) != 0U)
        {
            /* Invalid notification mask or notification not configured */
            Thermal_ReportDetError(THERMAL_DISABLENOTIFICATIONS_ID, THERMAL_E_NOTIF_NOT_CONFIGURED);
        }
        else
        {
#endif /* THERMAL_DEV_ERROR_DETECT == STD_ON */
        Tmu_Ip_DisableNotifications(0U, NotificationsMask);
#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif /* THERMAL_DEV_ERROR_DETECT == STD_ON */
}

/**
* @implements  Thermal_SetMeasurementInterval_Activity
*/
void Thermal_SetMeasurementInterval(Thermal_MonitoringIntervalType MonitoringInterval)
{
#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType Status = Thermal_CheckInitAndPowerMode(THERMAL_POWERMODE_NORMAL, THERMAL_SETMEASUREMENTINTERVAL_ID);

    if ((Std_ReturnType)E_OK == Status)
    {
#endif /* THERMAL_DEV_ERROR_DETECT == STD_ON */
        Tmu_Ip_SetMeasurementInterval(0U, (Tmu_Ip_TempMonitoringIntervalType)MonitoringInterval);
#if (THERMAL_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* THERMAL_DEV_ERROR_DETECT == STD_ON */
}

#define THERMAL_STOP_SEC_CODE
#include "Thermal_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

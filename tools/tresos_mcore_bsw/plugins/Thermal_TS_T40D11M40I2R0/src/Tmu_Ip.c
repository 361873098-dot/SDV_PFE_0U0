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
#include "Tmu_Ip.h"
#include "Tmu_Ip_TrustedFunctions.h"
#include "Tmu_Ip_Irq.h"

#if (STD_ON == TMU_IP_ENABLE_USER_MODE_SUPPORT)
    #include "Reg_eSys.h"
    #include "RegLockMacros.h"
    #include "OsIf_Internal.h"
#endif /* (STD_ON == TMU_IP_ENABLE_USER_MODE_SUPPORT) */

#if (TMU_IP_LOAD_DAC_TRIM_FROM_OCOTP == STD_ON)
    #include "Ocotp_Ip.h"
#endif /*TMU_IP_LOAD_DAC_TRIM_FROM_OCOTP == STD_ON*/

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define TMU_IP_VENDOR_ID_C                      43
#define TMU_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define TMU_IP_AR_RELEASE_MINOR_VERSION_C       4
#define TMU_IP_AR_RELEASE_REVISION_VERSION_C    0
#define TMU_IP_SW_MAJOR_VERSION_C               4
#define TMU_IP_SW_MINOR_VERSION_C               0
#define TMU_IP_SW_PATCH_VERSION_C               2

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

#if defined(TMU_IP_DEV_ERROR_DETECT) && (TMU_IP_DEV_ERROR_DETECT == STD_ON)
    #include "Devassert.h"
    #define DEV_ASSERT(x) DevAssert(x)
#else
    #define DEV_ASSERT(x) ((void)0)
#endif /* defined(TMU_IP_DEV_ERROR_DETECT) && (TMU_IP_DEV_ERROR_DETECT == STD_ON) */

#if (TMU_IP_LOAD_DAC_TRIM_FROM_OCOTP == STD_ON)
    #define TMU_IP_DAC_TRIM_TWO_COMPLEMENT_2_DECIMAL(x)    ( (uint16)((~((x) - 1U)) & TMU_IP_CFG_DAC_TRIM_DATA_MASK) )
#endif

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Tmu_Ip.c file and Tmu_Ip.h file are of the same vendor */
#if (TMU_IP_VENDOR_ID_C != TMU_IP_VENDOR_ID)
    #error "Tmu_Ip.c and Tmu_Ip.h have different vendor ids"
#endif

/* Check if Tmu_Ip.c file and Tmu_Ip.h file are of the same Autosar version */
#if ((TMU_IP_AR_RELEASE_MAJOR_VERSION_C != TMU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (TMU_IP_AR_RELEASE_MINOR_VERSION_C != TMU_IP_AR_RELEASE_MINOR_VERSION) || \
     (TMU_IP_AR_RELEASE_REVISION_VERSION_C != TMU_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Tmu_Ip.c and Tmu_Ip.h are different"
#endif

/* Check if Tmu_Ip.c file and Tmu_Ip.h file are of the same Software version */
#if ((TMU_IP_SW_MAJOR_VERSION_C != TMU_IP_SW_MAJOR_VERSION) || \
     (TMU_IP_SW_MINOR_VERSION_C != TMU_IP_SW_MINOR_VERSION) || \
     (TMU_IP_SW_PATCH_VERSION_C != TMU_IP_SW_PATCH_VERSION) \
    )
  #error "Software Version Numbers of Tmu_Ip.c and Tmu_Ip.h are different"
#endif

/* Check if Tmu_Ip.c file and Tmu_Ip_Irq.h file are of the same vendor */
#if (TMU_IP_VENDOR_ID_C != TMU_IP_VENDOR_ID_IRQ)
    #error "Tmu_Ip.c and Tmu_Ip_Irq.h have different vendor ids"
#endif

/* Check if Tmu_Ip.c file and Tmu_Ip_Irq.h file are of the same Autosar version */
#if ((TMU_IP_AR_RELEASE_MAJOR_VERSION_C != TMU_IP_AR_RELEASE_MAJOR_VERSION_IRQ) || \
     (TMU_IP_AR_RELEASE_MINOR_VERSION_C != TMU_IP_AR_RELEASE_MINOR_VERSION_IRQ) || \
     (TMU_IP_AR_RELEASE_REVISION_VERSION_C != TMU_IP_AR_RELEASE_REVISION_VERSION_IRQ) \
    )
    #error "AutoSar Version Numbers of Tmu_Ip.c and Tmu_Ip_Irq.h are different"
#endif

/* Check if Tmu_Ip.c file and Tmu_Ip_Irq.h file are of the same Software version */
#if ((TMU_IP_SW_MAJOR_VERSION_C != TMU_IP_SW_MAJOR_VERSION_IRQ) || \
     (TMU_IP_SW_MINOR_VERSION_C != TMU_IP_SW_MINOR_VERSION_IRQ) || \
     (TMU_IP_SW_PATCH_VERSION_C != TMU_IP_SW_PATCH_VERSION_IRQ) \
    )
  #error "Software Version Numbers of Tmu_Ip.c and Tmu_Ip_Irq.h are different"
#endif

/* Check if Tmu_Ip.c file and Tmu_Ip_TrustedFunctions.h file are of the same vendor */
#if (TMU_IP_VENDOR_ID_C != TMU_IP_VENDOR_ID_TRUSTEDFUNCTIONS)
    #error "Tmu_Ip.c and Tmu_Ip_TrustedFunctions.h have different vendor ids"
#endif

/* Check if Tmu_Ip.c file and Tmu_Ip_TrustedFunctions.h file are of the same Autosar version */
#if ((TMU_IP_AR_RELEASE_MAJOR_VERSION_C != TMU_IP_AR_RELEASE_MAJOR_VERSION_TRUSTEDFUNCTIONS) || \
     (TMU_IP_AR_RELEASE_MINOR_VERSION_C != TMU_IP_AR_RELEASE_MINOR_VERSION_TRUSTEDFUNCTIONS) || \
     (TMU_IP_AR_RELEASE_REVISION_VERSION_C != TMU_IP_AR_RELEASE_REVISION_VERSION_TRUSTEDFUNCTIONS) \
    )
    #error "AutoSar Version Numbers of Tmu_Ip.c and Tmu_Ip_TrustedFunctions.h are different"
#endif

/* Check if Tmu_Ip.c file and Tmu_Ip_TrustedFunctions.h file are of the same Software version */
#if ((TMU_IP_SW_MAJOR_VERSION_C != TMU_IP_SW_MAJOR_VERSION_TRUSTEDFUNCTIONS) || \
     (TMU_IP_SW_MINOR_VERSION_C != TMU_IP_SW_MINOR_VERSION_TRUSTEDFUNCTIONS) || \
     (TMU_IP_SW_PATCH_VERSION_C != TMU_IP_SW_PATCH_VERSION_TRUSTEDFUNCTIONS) \
    )
  #error "Software Version Numbers of Tmu_Ip.c and Tmu_Ip_TrustedFunctions.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (STD_ON == TMU_IP_ENABLE_USER_MODE_SUPPORT)
        /* Check if Tmu_Ip.c file and Reg_eSys.h file are of the same Autosar version */
        #if ((TMU_IP_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
             (TMU_IP_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_AR_RELEASE_MINOR_VERSION)    \
            )
            #error "AutoSar Version Numbers of Tmu_Ip.c and Reg_eSys.h are different"
        #endif

        /* Check if Tmu_Ip.c file and OsIf_Internal.h file are of the same Autosar version */
        #if ((TMU_IP_AR_RELEASE_MAJOR_VERSION_C != OSIF_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
             (TMU_IP_AR_RELEASE_MINOR_VERSION_C != OSIF_INTERNAL_AR_RELEASE_MINOR_VERSION)    \
            )
            #error "AutoSar Version Numbers of Tmu_Ip.c and OsIf_Internal.h are different"
        #endif

        /* Check if Tmu_Ip.c file and RegLockMacros.h file are of the same Autosar version */
        #if ((TMU_IP_AR_RELEASE_MAJOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
             (TMU_IP_AR_RELEASE_MINOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
            #error "AUTOSAR Version Numbers of Tmu_Ip.c and RegLockMacros.h are different"
        #endif
    #endif /* (STD_ON == TMU_IP_ENABLE_USER_MODE_SUPPORT) */

    #if defined(TMU_IP_DEV_ERROR_DETECT) && (TMU_IP_DEV_ERROR_DETECT == STD_ON)
        /* Checks against Devassert.h */
        #if ((TMU_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
             (TMU_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION))
            #error "AUTOSAR Version Numbers of Tmu_Ip.c and RegLockMacros.h are different"
        #endif
    #endif /* defined(TMU_IP_DEV_ERROR_DETECT) && (TMU_IP_DEV_ERROR_DETECT == STD_ON) */
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK  */

#if (TMU_IP_LOAD_DAC_TRIM_FROM_OCOTP == STD_ON)
        /* Check if Tmu_Ip.c file and Ocotp_Ip.h file are of the same Autosar version */
        #if ((TMU_IP_AR_RELEASE_MAJOR_VERSION_C != OCOTP_IP_AR_RELEASE_MAJOR_VERSION) || \
             (TMU_IP_AR_RELEASE_MINOR_VERSION_C != OCOTP_IP_AR_RELEASE_MINOR_VERSION)    \
            )
            #error "AutoSar Version Numbers of Tmu_Ip.c and Ocotp_Ip.h are different"
        #endif
#endif /*TMU_IP_LOAD_DAC_TRIM_FROM_OCOTP == STD_ON*/

/*==================================================================================================
*                                       PRE-CHECK
==================================================================================================*/
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == TMU_IP_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running THERMAL in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif /* (STD_ON == TMU_IP_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT*/
/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

#define THERMAL_START_SEC_CONST_UNSPECIFIED
#include "Thermal_MemMap.h"
/*! @brief  Table of base addresses for TMU instances. */
static TMU_Type * const Tmu_Ip_pBase[TMU_INSTANCE_COUNT] = IP_TMU_BASE_PTRS;
#define THERMAL_STOP_SEC_CONST_UNSPECIFIED
#include "Thermal_MemMap.h"

#define THERMAL_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Thermal_MemMap.h"
static Tmu_Ip_NotificationsType Tmu_Ip_aNotifications[TMU_INSTANCE_COUNT];
#define THERMAL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Thermal_MemMap.h"

#define THERMAL_START_SEC_VAR_CLEARED_BOOLEAN
#include "Thermal_MemMap.h"
static boolean Tmu_Ip_bInitialized[TMU_INSTANCE_COUNT];
#define THERMAL_STOP_SEC_VAR_CLEARED_BOOLEAN
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

static inline void Tmu_CheckAndCallCriticalNotification(const uint32 Instance,
                                                        const uint32 InterruptDetectMask,
                                                        const uint32 InterruptEnableMask,
                                                        void (*pfCallback)(uint32 TmuSiteMask));

static inline void Tmu_CheckAndCallAverageNotification(const uint32 Instance,
                                                       const uint32 InterruptDetectMask,
                                                       const uint32 InterruptEnableMask,
                                                       void (*pfCallback)(uint32 TmuSiteMask));

static inline void Tmu_CheckAndCallImmNotification(const uint32 Instance,
                                                   const uint32 InterruptDetectMask,
                                                   const uint32 InterruptEnableMask,
                                                   void (*pfCallback)(uint32 TmuSiteMask));

static inline void Tmu_CriticalNotification(const uint32 Instance);

static inline void Tmu_NonCriticalNotification(const uint32 Instance);

static inline void Tmu_MonitorTempThreshold(TMU_Type * const Base,
                                            const Tmu_Ip_ThresholdConfigType * const ThrConfigPtr,
                                            const uint8 MonitorEn);

static inline Tmu_Ip_StatusType Tmu_CheckSarReady(const TMU_Type * const Base);

static inline void TMU_SetSensorAndTempValue(TMU_Type * const Base,
                                             const uint32 Index,
                                             const uint16 SensorValue,
                                             const uint16 TempValue);
static inline void TMU_ConfigCorrespondingThresholdInterrupt(TMU_Type * const Base,
                                                             const boolean IrqEn,
                                                             const Tmu_Ip_ThresholdType ThrType);
#if (TMU_IP_LOAD_DAC_TRIM_FROM_OCOTP == STD_ON)
static Tmu_Ip_StatusType Tmu_AddOcotpTrimsValueToSensorValue(uint16* const DefaultSensorValue);
#endif /*TMU_IP_LOAD_DAC_TRIM_FROM_OCOTP == STD_ON*/

#define THERMAL_STOP_SEC_CODE
#include "Thermal_MemMap.h"
/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

#define THERMAL_START_SEC_CODE
#include "Thermal_MemMap.h"

/**
* @brief      Check which interrupt was triggered, clear it and call the associated callback
* @details    Check which interrupt was triggered, clear it and call the associated callback
*
* @param[in]  Instance              Tmu instance
* @param[in]  InterruptDetectMask   Interrupt detect mask of the notification
* @param[in]  InterruptEnableMask   Interrupt enable mask of the notification
* @param[in]  pfCallback            Pointer to the notification function
*
* @return     void
*/
static inline void Tmu_CheckAndCallCriticalNotification(const uint32 Instance,
                                                        const uint32 InterruptDetectMask,
                                                        const uint32 InterruptEnableMask,
                                                        void (*pfCallback)(uint32 TmuSiteMask))
{
    TMU_Type * Base = Tmu_Ip_pBase[Instance];
    uint32 TmuSiteMask;

    if ((Base->TIDR & InterruptDetectMask) != 0U)
    {
        /* Check if the interrupt was spurious */
        if ((Base->TIER & InterruptEnableMask) != 0U)
        {
            TmuSiteMask = (Base->TICSCR & TMU_TICSCR_SITE_MASK) >> TMU_TICSCR_SITE_SHIFT;
            /* W1C the detected condition */
            Base->TIDR = InterruptDetectMask;
            Base->TICSCR &= ~TMU_TICSCR_SITE_MASK;
            pfCallback(TmuSiteMask);
        }
    }
}

static inline void Tmu_CheckAndCallAverageNotification(const uint32 Instance,
                                                       const uint32 InterruptDetectMask,
                                                       const uint32 InterruptEnableMask,
                                                       void (*pfCallback)(uint32 TmuSiteMask))
{
    TMU_Type * Base = Tmu_Ip_pBase[Instance];
    uint32 TmuSiteMask;

    if ((Base->TIDR & InterruptDetectMask) != 0U)
    {
        /* Check if the interrupt was spurious */
        if ((Base->TIER & InterruptEnableMask) != 0U)
        {
            TmuSiteMask = (Base->TIASCR & TMU_TIASCR_SITE_MASK) >> TMU_TIASCR_SITE_SHIFT;
            /* W1C the detected condition */
            Base->TIDR = InterruptDetectMask;
            Base->TIASCR &= ~TMU_TIASCR_SITE_MASK;
            pfCallback(TmuSiteMask);
        }
    }
}

static inline void Tmu_CheckAndCallImmNotification(const uint32 Instance,
                                                   const uint32 InterruptDetectMask,
                                                   const uint32 InterruptEnableMask,
                                                   void (*pfCallback)(uint32 TmuSiteMask))
{
    TMU_Type * Base = Tmu_Ip_pBase[Instance];
    uint32 TmuSiteMask;

    if ((Base->TIDR & InterruptDetectMask) != 0U)
    {
        /* Check if the interrupt was spurious */
        if ((Base->TIER & InterruptEnableMask) != 0U)
        {
            TmuSiteMask = (Base->TIISCR & TMU_TIISCR_SITE_MASK) >> TMU_TIISCR_SITE_SHIFT;
            /* W1C the detected condition */
            Base->TIDR = InterruptDetectMask;
            Base->TIISCR &= ~TMU_TIISCR_SITE_MASK;
            pfCallback(TmuSiteMask);
        }
    }
}

static inline void Tmu_CriticalNotification(const uint32 Instance)
{
    /* AverageHighTempCritical */
    Tmu_CheckAndCallCriticalNotification(Instance, TMU_TIDR_AHTCT_MASK, TMU_IP_INTERRUPT_AVERAGE_HIGH_TEMP_CRITICAL, Tmu_Ip_aNotifications[Instance].AverageHighTempCritical);
    /* AverageLowTempCritical */
    Tmu_CheckAndCallCriticalNotification(Instance, TMU_TIDR_ALTCT_MASK, TMU_IP_INTERRUPT_AVERAGE_LOW_TEMP_CRITICAL, Tmu_Ip_aNotifications[Instance].AverageLowTempCritical);
    /* RisingTempRateCritical */
    Tmu_CheckAndCallCriticalNotification(Instance, TMU_TIDR_RTRCT_MASK, TMU_IP_INTERRUPT_RISING_TEMP_RATE_CRITICAL, Tmu_Ip_aNotifications[Instance].RisingTempRateCritical);
    /* FallingTempRateCritical */
    Tmu_CheckAndCallCriticalNotification(Instance, TMU_TIDR_FTRCT_MASK, TMU_IP_INTERRUPT_FALLING_TEMP_RATE_CRITICAL, Tmu_Ip_aNotifications[Instance].FallingTempRateCritical);
}

static inline void Tmu_NonCriticalNotification(const uint32 Instance)
{
    /* AverageHighTemp */
    Tmu_CheckAndCallAverageNotification(Instance, TMU_TIDR_AHTT_MASK, TMU_IP_INTERRUPT_AVERAGE_HIGH_TEMP, Tmu_Ip_aNotifications[Instance].AverageHighTemp);
    /* AverageLowTemp */
    Tmu_CheckAndCallAverageNotification(Instance, TMU_TIDR_ALTT_MASK, TMU_IP_INTERRUPT_AVERAGE_LOW_TEMP, Tmu_Ip_aNotifications[Instance].AverageLowTemp);
    /* ImmediateHighTemp */
    Tmu_CheckAndCallImmNotification(Instance, TMU_TIDR_IHTT_MASK, TMU_IP_INTERRUPT_IMMEDIATE_HIGH_TEMP, Tmu_Ip_aNotifications[Instance].ImmediateHighTemp);
    /* ImmediateLowTemp */
    Tmu_CheckAndCallImmNotification(Instance, TMU_TIDR_ILTT_MASK, TMU_IP_INTERRUPT_IMMEDIATE_LOW_TEMP, Tmu_Ip_aNotifications[Instance].ImmediateLowTemp);
}

/*!
 * @brief Threshold interrupt configuration.
 * This function shall configure threshold interrupt.
 *
 * @param[in] Base          The TMU peripheral base address
 * @param[in] IrqEnable     Enable interrupt
 * @param[in] Mask          The interrupt mask
 */
static void TMU_ConfigThresholdInterrupt(TMU_Type * const Base,
                                         const boolean IrqEnable,
                                         const uint32 Mask)
{
    if (TRUE == IrqEnable)
    {
        Base->TIER |= Mask;
    }
    else
    {
        Base->TIER &= ~Mask;
    }
}

/**
* @brief      Monitor temperature thresholds.
* @details    Monitor temperature thresholds.
*
* @param[in]  Base              Table of base addresses for TMU instances
* @param[in]  ThrConfigPtr      Threshold configuration address
* @param[in]  MonitorEn         This param is 1u if threshold is enabled, 0u otherwise
*
* @return     void
*/
static inline void Tmu_MonitorTempThreshold(TMU_Type * const Base,
                                            const Tmu_Ip_ThresholdConfigType * const ThrConfigPtr,
                                            const uint8 MonitorEn)
{
    uint16 ThrValue = ThrConfigPtr->ThresholdValue;
    Tmu_Ip_ThresholdType ThrType = ThrConfigPtr->ThresholdType;

    switch (ThrType)
    {
        case TMU_IP_THRESHOLD_HIGH_TEMP_IMMEDIATE:
            /* Monitor high temperature immediate threshold */
            Base->TMHTITR = TMU_TMHTITR_EN(MonitorEn) | TMU_TMHTITR_TEMP(ThrValue);
            break;
        case TMU_IP_THRESHOLD_HIGH_TEMP_AVERAGE:
            /* Monitor high temperature average threshold */
            Base->TMHTATR = TMU_TMHTATR_EN(MonitorEn) | TMU_TMHTATR_TEMP(ThrValue);
            break;
        case TMU_IP_THRESHOLD_HIGH_TEMP_AVERAGE_CRITICAL:
            /* Monitor high temperature average critical threshold */
            Base->TMHTACTR = TMU_TMHTACTR_EN(MonitorEn) | TMU_TMHTACTR_TEMP(ThrValue);
            break;
        case TMU_IP_THRESHOLD_LOW_TEMP_IMMEDIATE:
            /* Monitor low temperature immediate threshold */
            Base->TMLTITR = TMU_TMLTITR_EN(MonitorEn) | TMU_TMLTITR_TEMP(ThrValue);
            break;
        case TMU_IP_THRESHOLD_LOW_TEMP_AVERAGE:
            /* Monitor low temperature average threshold */
            Base->TMLTATR = TMU_TMLTATR_EN(MonitorEn) | TMU_TMLTATR_TEMP(ThrValue);
            break;
        case TMU_IP_THRESHOLD_LOW_TEMP_AVERAGE_CRITICAL:
            /* Monitor low temperature average critical threshold */
            Base->TMLTACTR = TMU_TMLTACTR_EN(MonitorEn) | TMU_TMLTACTR_TEMP(ThrValue);
            break;
        case TMU_IP_THRESHOLD_RISING_TEMP_RATE_CRITICAL:
            /* Monitor rising temperature rate critical threshold */
            Base->TMRTRCTR = TMU_TMRTRCTR_EN(MonitorEn) | TMU_TMRTRCTR_TEMP(ThrValue);
            break;
        case TMU_IP_THRESHOLD_FALLING_TEMP_RATE_CRITICAL:
            /* Monitor falling temperature rate critical threshold */
            Base->TMFTRCTR = TMU_TMFTRCTR_EN(MonitorEn) | TMU_TMFTRCTR_TEMP(ThrValue);
            break;
        default:
            /* Nothing to do */
            break;
    }
}

/**
* @brief      Check if SAR module is ready to receive user commands.
* @details    Check if SAR module is ready to receive user commands.
*
* @param[in]  Base              Table of base addresses for TMU instances
*
* @return     Tmu_Ip_StatusType
*/
static inline Tmu_Ip_StatusType Tmu_CheckSarReady(const TMU_Type * const Base)
{
    uint32 TimeoutTicks = OsIf_MicrosToTicks(TMU_IP_TIMEOUT_VAL, TMU_IP_TIMEOUT_TYPE);
    uint32 CurrentTicks = OsIf_GetCounter(TMU_IP_TIMEOUT_TYPE);
    uint32 ElapsedTicks = 0U;
    /* Wait until the hardware sets TCMCFG.SAR_RDY. */
    uint32 TcmCfg = Base->TCMCFG;
    Tmu_Ip_StatusType eStatus = TMU_IP_STATUS_SUCCESS;

    while ((0U == (TcmCfg & TMU_TCMCFG_SAR_RDY_MASK)) && (ElapsedTicks < TimeoutTicks))
    {
        TcmCfg = Base->TCMCFG;
        ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, TMU_IP_TIMEOUT_TYPE);
    }
    if (ElapsedTicks >= TimeoutTicks)
    {
        eStatus = TMU_IP_STATUS_TIMEOUT;
    }

    return eStatus;

}

/**
 * @details    This function handles Tmu interrupt request.
 * @implements Tmu_IRQHandler_Activity
 */
void Tmu_IRQHandler(const uint32 Instance
#if (STD_ON == TMU_IP_HAS_SEPARATED_IRQ)
                  , const boolean FromSeparatedCriticalIrq
#endif /* (STD_ON == TMU_IP_HAS_SEPARATED_IRQ) */
                    )
{
    TMU_Type * Base = Tmu_Ip_pBase[Instance];
    Std_ReturnType ReturnValue = (Std_ReturnType)E_OK;

    if (FALSE == Tmu_Ip_bInitialized[Instance])
    {
        Base->TIDR = TMU_IP_INTERRUPT_SOURCE_ALL;
        ReturnValue = (Std_ReturnType)E_NOT_OK;
    }

    if ((Std_ReturnType)E_OK == ReturnValue)
    {
        /* Check which interrupt was triggered, clear it and call the associated callback */
    #if (STD_ON == TMU_IP_HAS_SEPARATED_IRQ)
        if (TRUE == FromSeparatedCriticalIrq)
        {
            Tmu_CriticalNotification(Instance);
        }
        else
        {
            Tmu_NonCriticalNotification(Instance);
        }
    #else
        Tmu_CriticalNotification(Instance);
        Tmu_NonCriticalNotification(Instance);
    #endif /* (STD_ON == TMU_IP_HAS_SEPARATED_IRQ) */
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : TMU_ClearInterruptRegister
 * Description   : This function shall clear all the detected interrupts.
 *
 *END**************************************************************************/
static void TMU_ClearInterruptRegister(TMU_Type * const Base)
{
    /* Clear the interrupt detect register */
    Base->TIDR = TMU_IP_INTERRUPT_SOURCE_ALL;

    /* Clear the interrupt capture registers */
    Base->TIISCR &= ~TMU_TIISCR_SITE_MASK;

    /* Clear the interrupt average site registers */
    Base->TIASCR &= ~TMU_TIASCR_SITE_MASK;

    /* Clear the interrupt critical site registers */
    Base->TICSCR &= ~TMU_TICSCR_SITE_MASK;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : TMU_Reset
 * Description   : This function shall reset all registers to default value.
 *
 *END**************************************************************************/
static void TMU_Reset(TMU_Type * const Base)
{
    uint8 i;

    /* Reset all register to default value */
    Base->TMR = 0x0U;
    Base->TSR |= 0x70000000U;
    Base->TMSR = 0x0U;
    Base->TMTMIR = 0x0U;
    Base->TIER = 0x0U;
    Base->TMHTITR = 0x0U;
    Base->TMHTATR = 0x0U;
    Base->TMHTACTR = 0x0U;
    Base->TMLTITR = 0x0U;
    Base->TMLTATR = 0x0U;
    Base->TMLTACTR = 0x0U;
    Base->TMRTRCTR = 0x0U;
    Base->TMFTRCTR = 0x0U;
    /* Important note: DAC_OFFSET initial value is sampled during POR from fuses, is partspecific, and should not be changed by the user. */
    Base->TCMCFG &= ~(TMU_TCMCFG_DPM_MASK | TMU_TCMCFG_OCM_MASK | \
                      TMU_TCMCFG_OCS_MASK | TMU_TCMCFG_DEMA_MASK | \
                      TMU_TCMCFG_RCTC_MASK | TMU_TCMCFG_CLK_DIV_MASK | \
                      TMU_TCMCFG_DFD_MASK | TMU_TCMCFG_CMET_MASK);
    Base->TCMCFG |= TMU_IP_DEFAULT_CENTRAL_MODULE_REG;

    /* Clear all temperature point */
    for (i = 0U; i < TMU_NUM_SITE_RC_COUNT; i++)
    {
        Base->TTRCR[i] = 0x0U;
        Base->TTCFGR = i;
        Base->TSCFGR = 0x0U;
    }
    Base->TTCFGR = 0x0U;

    /* Clear all interrupt register */
    TMU_ClearInterruptRegister(Base);
    /* Clear monitor high temperature capture */
    Base->TMHTCR |= TMU_TMHTCR_V_MASK;
    /* Clear monitor low temperature capture */
    Base->TMLTCR |= TMU_TMLTCR_V_MASK;
    /* Clear monitor rising temperature capture */
    Base->TMRTRCR |= TMU_TMRTRCR_V_MASK;
    /* Clear monitor falling temperature capture */
    Base->TMFTRCR |= TMU_TMFTRCR_V_MASK;
}

#if (TMU_IP_LOAD_DAC_TRIM_FROM_OCOTP == STD_ON)
/*FUNCTION**********************************************************************
 *
 * Function Name : Tmu_AddOcotpTrimsValueToSensorValue
 * Description   : This function shall add the DAC Trim values to default sensor value .
 *
 *END**************************************************************************/
static Tmu_Ip_StatusType Tmu_AddOcotpTrimsValueToSensorValue(uint16* const DefaultSensorValue)
{
    /* Array of trim index for each sensor */
    const uint8 SensorTrimIndex[TMU_IP_DEFAULT_CALIB_POINT_COUNT] = TMU_IP_SENSOR_DAC_TRIM_INDEX;
    /* Trim arrays information to extract trim values from the FUSE */
    const uint32 DacTrimShifts[TMU_IP_CFG_DAC_TRIM_COUNT] = TMU_IP_CFG_DAC_TRIM_SHIFT;

    /* Array to store the trim values.
    Note: Add one additional element at the end to be used for the sensors which do not need to add trim values */
    uint16 DacTrimValues[TMU_IP_CFG_DAC_TRIM_COUNT + 1U];
    uint32 Index;

    Tmu_Ip_StatusType ReturnVal = TMU_IP_STATUS_ERROR;
    uint32 FuseValue = 0U;
    uint32 TrimValue;
    uint16 TrimRawValue;

    /* Read FUSE value from OCOTP instance 0 (Note: there is only one OCOTP instance) */
    if (STATUS_OCOTP_IP_SUCCESS == Ocotp_Ip_ReadEFuse(0U, TMU_IP_CFG_DAC_TRIM_ADDRESS , &FuseValue))
    {
        /* Extract FUSE to array of trim values */
        for (Index = 0U; Index < TMU_IP_CFG_DAC_TRIM_COUNT; Index ++)
        {
            /* Clear to default value as 0 */
            DacTrimValues[Index] = 0U;
            /* Shift to the current TRIM */
            TrimValue = FuseValue >> DacTrimShifts[Index];
            /* Check for valid bit */
            if (0U != (TrimValue & TMU_IP_CFG_DAC_TRIM_VALID_MASK))
            {
                /* Trim is valid, extract its value */
                DacTrimValues[Index] = (uint16)(TrimValue & TMU_IP_CFG_DAC_TRIM_DATA_MASK);
            }
        }
        /* Mark the last additional element as zero to be used for sensors do not need to add trim values */
        DacTrimValues[TMU_IP_CFG_DAC_TRIM_COUNT] = 0U;

        /* As the Reference Manual states, the value of the trim value from fuse is added to sensor value list base on the trim index */
        for (Index = 0U; Index < TMU_IP_DEFAULT_CALIB_POINT_COUNT; Index ++)
        {
            /* DacTrimValues are zero means that those trims are invalid or the according sensors do not need to add trim values */
            TrimRawValue = DacTrimValues[ SensorTrimIndex[Index] ];
            /*the TRIM values are in the 2's complement format,so need to check the sign bit before they can be added to or
            subtracted from a calibration point*/
            if (0U != (TrimRawValue & TMU_IP_CFG_DAC_TRIM_SIGN_MASK))
            {
                /*TrimRawValue is Negative*/
                DefaultSensorValue[Index] -= TMU_IP_DAC_TRIM_TWO_COMPLEMENT_2_DECIMAL(TrimRawValue);
            }
            else
            {
                /*TrimRawValue is Positive*/
                DefaultSensorValue[Index] += TrimRawValue;
            }
        }

        ReturnVal = TMU_IP_STATUS_SUCCESS;
    }

    return ReturnVal;
}
#endif /*TMU_IP_LOAD_DAC_TRIM_FROM_OCOTP == STD_ON*/

/*FUNCTION**********************************************************************
 *
 * Function Name : TMU_SetCalibrationPoints
 * Description   : This function shall setup the calibration point to read temperature from sensor.
 *
 *END**************************************************************************/
static Tmu_Ip_StatusType TMU_SetCalibrationPoints(TMU_Type * const Base,
                                     uint8 const NumCalibrationConfigs,
                                     const Tmu_Ip_CalibrationConfigType* const CalibConfigPtr)
{
    DEV_ASSERT(NumCalibrationConfigs <= TMU_NUM_SITE_RC_COUNT);
    uint8 Index;
    Tmu_Ip_StatusType RetStatus = TMU_IP_STATUS_SUCCESS;
    /* Table to save sensor values and temperature range values */
    uint16 SensorValue[TMU_IP_DEFAULT_CALIB_POINT_COUNT] = TMU_IP_DEFAULT_SENSOR_VALUE;
    static const uint16 TempValue[TMU_IP_DEFAULT_CALIB_POINT_COUNT] = TMU_IP_DEFAULT_TEMPERATURE_VALUE;

    /* Check if user not initialize calibration point, driver will set some calibration points by default,
       The number of default calibration points will be noted in the driver manual */
    if ((0U == NumCalibrationConfigs) && (NULL_PTR == CalibConfigPtr))
    {
#if (TMU_IP_LOAD_DAC_TRIM_FROM_OCOTP == STD_ON)
        /*Add trims value from Ocotp to Sensor value*/
        RetStatus = Tmu_AddOcotpTrimsValueToSensorValue(SensorValue);
        if (TMU_IP_STATUS_SUCCESS == RetStatus)
#endif
        {
            for (Index = 0U; Index < TMU_IP_DEFAULT_CALIB_POINT_COUNT; Index ++)
            {
                TMU_SetSensorAndTempValue(Base, Index, SensorValue[Index], TempValue[Index]);
            }
        }
    }
    else
    {
        DEV_ASSERT(CalibConfigPtr != NULL_PTR);
        DEV_ASSERT(NumCalibrationConfigs != 0U);
        /* Set the calibration point */
        for (Index = 0U; Index < NumCalibrationConfigs; Index++)
        {
            TMU_SetSensorAndTempValue(Base, Index, CalibConfigPtr[Index].SensorValue, CalibConfigPtr[Index].TempRange);
        }
    }
    return RetStatus;
}

static inline void TMU_SetSensorAndTempValue(TMU_Type * const Base,
                                             const uint32 Index,
                                             const uint16 SensorValue,
                                             const uint16 TempValue)
{
    /* write 1 for cancellation mode and dynamic element match averaging mode */
    Base->TCMCFG |= TMU_TCMCFG_OCM(1U) | TMU_TCMCFG_DEMA(1U);
    /* Configure calibration point */
    Base->TTCFGR = (Base->TTCFGR & ~TMU_TTCFGR_CAL_PT_MASK) | TMU_TTCFGR_CAL_PT(Index);
    /* Configure sensor value */
    Base->TSCFGR = (Base->TSCFGR & ~TMU_TSCFGR_SENSOR_MASK) | TMU_TSCFGR_SENSOR(SensorValue);
    /* Configure temperature range and valid bitfield */
    Base->TTRCR[Index] = TMU_TTRCR_V(1U) | TMU_TTRCR_TEMP(TempValue);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : TMU_SetTemperatureThreshold
 * Description   : This function shall setup the threshold for monitoring temperature
 * and configure interrupt enable/disable for each type of threshold.
 *
 *END**************************************************************************/
static void TMU_SetTemperatureThreshold(TMU_Type * const Base,
                                        const Tmu_Ip_ThresholdConfigType * const ThrConfigPtr)
{
    boolean ThrEnable;
    uint8 MonitorEn;

    ThrEnable = ThrConfigPtr->Enable;
    MonitorEn = (TRUE == ThrEnable) ? 1U : 0U;
    Tmu_MonitorTempThreshold(Base, ThrConfigPtr, MonitorEn);
}

/* Monitor temperature measurement interval */
/*!
 * @brief Set the temperature monitoring interval.
 * This function shall set the value of the temperature monitoring interval.
 *
 * @param[in] Base The TMU peripheral base address
 * @param[in] Interval The time interval value
 */
static void TMU_SetIntervalValue(TMU_Type * const Base,
                                 Tmu_Ip_TempMonitoringIntervalType const Interval)
{
    Base->TMTMIR = (Base->TMTMIR & ~TMU_TMTMIR_TMI_MASK) | TMU_TMTMIR_TMI(Interval);
}

/* Monitoring */
/*!
 * @brief Get the TMU mode.
 * This function get the mode of operation.
 *
 * @param[in] Base The TMU peripheral base address
 */
static Tmu_Ip_ModeType TMU_GetMode(const TMU_Type * const Base)
{
    uint32 Mode = (Base->TMR & TMU_TMR_MODE_MASK) >> TMU_TMR_MODE_SHIFT;
    return ((0U == Mode) ? TMU_IP_MODE_IDLE_LOW_POWER : TMU_IP_MODE_MONITORING);
}

/* Avoid compiler warning */
#if defined(TMU_IP_DEV_ERROR_DETECT) && (TMU_IP_DEV_ERROR_DETECT == STD_ON)
/*!
 * @brief Get the configured notifications
 *
 * @param[in,out] Instance   Tmu instance
 */
static uint32 Tmu_Ip_GetConfiguredNotifications(const uint32 Instance)
{
    DEV_ASSERT(Instance < TMU_INSTANCE_COUNT);
    const Tmu_Ip_NotificationsType * Notifs = &Tmu_Ip_aNotifications[Instance];
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
#endif

static inline void TMU_ConfigCorrespondingThresholdInterrupt(TMU_Type * const Base,
                                                             const boolean IrqEn,
                                                             const Tmu_Ip_ThresholdType ThrType)
{
    const uint32 ThresholdInterruptMask[] =
    {
        TMU_IP_INTERRUPT_IMMEDIATE_HIGH_TEMP,           /* TMU_IP_THRESHOLD_HIGH_TEMP_IMMEDIATE */
        TMU_IP_INTERRUPT_AVERAGE_HIGH_TEMP,             /* TMU_IP_THRESHOLD_HIGH_TEMP_AVERAGE */
        TMU_IP_INTERRUPT_AVERAGE_HIGH_TEMP_CRITICAL,    /* TMU_IP_THRESHOLD_HIGH_TEMP_AVERAGE_CRITICAL */
        TMU_IP_INTERRUPT_IMMEDIATE_LOW_TEMP,            /* TMU_IP_THRESHOLD_LOW_TEMP_IMMEDIATE */
        TMU_IP_INTERRUPT_AVERAGE_LOW_TEMP,              /* TMU_IP_THRESHOLD_LOW_TEMP_AVERAGE */
        TMU_IP_INTERRUPT_AVERAGE_LOW_TEMP_CRITICAL,     /* TMU_IP_THRESHOLD_LOW_TEMP_AVERAGE_CRITICAL */
        TMU_IP_INTERRUPT_RISING_TEMP_RATE_CRITICAL,     /* TMU_IP_THRESHOLD_RISING_TEMP_RATE_CRITICAL */
        TMU_IP_INTERRUPT_FALLING_TEMP_RATE_CRITICAL,    /* TMU_IP_THRESHOLD_FALLING_TEMP_RATE_CRITICAL */
    };

    /* Configure interrupt */
    TMU_ConfigThresholdInterrupt(Base, IrqEn, ThresholdInterruptMask[ (uint32)ThrType ]);
}
/* Configure temperature for monitor site */
static inline void TMU_ConfigTemperatureMonitor(const uint32 Instance,
                                                const Tmu_Ip_ConfigType * const ConfigPtr)
{
    uint32 Index;
    TMU_Type * Base = Tmu_Ip_pBase[Instance];

    for (Index = 0U; Index < ConfigPtr->NumThresholds; Index++)
    {
        /*configure corresponding interrupt*/
        TMU_ConfigCorrespondingThresholdInterrupt(Base, ConfigPtr->ThresholdConfig[Index].InterruptEnable, ConfigPtr->ThresholdConfig[Index].ThresholdType);
        /* Set temperature threshold for monitor site */
        TMU_SetTemperatureThreshold(Base, &ConfigPtr->ThresholdConfig[Index]);
    }
    /* Configure temperature monitoring interval */
    TMU_SetIntervalValue(Base, ConfigPtr->MeasurementInterval);

    if (ConfigPtr->Notifications != NULL_PTR)
    {
        Tmu_Ip_aNotifications[Instance] = *ConfigPtr->Notifications;
    }
}

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*FUNCTION**********************************************************************
 *
 * Function Name : Tmu_Ip_Init
 * Description   : This function shall initialize the temperature threshold with
 * the appropriate value, the temperature monitoring interval. It also configure
 * the calibration for the temperature sensor value. Two default calibration points
 * are used if the calibrationConfig is NULL_PTR.
 * This function shall return STATUS_ERROR if monitoring mode is not disabled
 * otherwise return STATUS_SUCCESS.
 *
 *  @implements Tmu_Ip_Init_Activity
 *END**************************************************************************/
Tmu_Ip_StatusType Tmu_Ip_Init(const uint32 Instance,
                              const Tmu_Ip_ConfigType * const ConfigPtr)
{
    DEV_ASSERT(Instance < TMU_INSTANCE_COUNT);
    DEV_ASSERT(!Tmu_Ip_bInitialized[Instance]);
    DEV_ASSERT(ConfigPtr != NULL_PTR);
    TMU_Type * Base = Tmu_Ip_pBase[Instance];
    uint32 Tmr;
    Tmu_Ip_StatusType Status;
    DEV_ASSERT(TMU_GetMode(Base) == TMU_IP_MODE_IDLE_LOW_POWER);

    #if (STD_ON == TMU_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Tmu_SetUserAccessAllowed, (uint32)Base);
    #endif /* (STD_ON == TMU_IP_ENABLE_USER_MODE_SUPPORT) */

    /* Disable monitoring mode */
    Base->TMR &= ~TMU_TMR_MODE_MASK;

    /* Important note: DAC_OFFSET initial value is sampled during POR from fuses, is partspecific, and should not be changed by the user. */
    Base->TCMCFG &= ~(TMU_TCMCFG_DPM_MASK | TMU_TCMCFG_OCM_MASK | \
                      TMU_TCMCFG_OCS_MASK | TMU_TCMCFG_DEMA_MASK | \
                      TMU_TCMCFG_RCTC_MASK | TMU_TCMCFG_CLK_DIV_MASK | \
                      TMU_TCMCFG_DFD_MASK | TMU_TCMCFG_CMET_MASK);
    Base->TCMCFG |= TMU_IP_DEFAULT_CENTRAL_MODULE_REG;

    /* Clear all interrupt registers */
    TMU_ClearInterruptRegister(Base);

    /* Configure central module */
    if (TRUE == ConfigPtr->CentralModuleDisable)
    {
        /* Disable central module mode */
        Tmr = TMU_TMR_CMD(1U);
    }
    else
    {
        /* Enable central module mode */
        Tmr = TMU_TMR_CMD(0U);
    }
    /* Configure average low pass filter */
    Tmr |= TMU_TMR_ALPF(ConfigPtr->LowPassFilter);

    /* Set monitoring site */
    DEV_ASSERT((ConfigPtr->MonitoringSitesMask <= TMU_IP_MONITORING_SITE_ALL) && (ConfigPtr->MonitoringSitesMask > 0U));
    Tmu_Ip_EnableMonitoringSite(Instance, ConfigPtr->MonitoringSitesMask);
    /* Set calibration point, sensor value and temperature range control */
    Status = TMU_SetCalibrationPoints(Base, ConfigPtr->NumCalibrationConfigs, ConfigPtr->CalibrationConfig);
    /* Set offset cancellation mode and dynamic element match averaging mode */
    Base->TCMCFG |= TMU_TCMCFG_OCM(ConfigPtr->OffsetCancellation ? 1UL : 0UL) | TMU_TCMCFG_DEMA(ConfigPtr->DynamicMatchAvrg ? 1UL : 0UL);
    
    if (TMU_IP_STATUS_SUCCESS == Status)
    {
        /* Check if SAR module is ready to receive user commands */
        Status = Tmu_CheckSarReady(Base);
        /* Configure temperature for monitor site */
        TMU_ConfigTemperatureMonitor(Instance, ConfigPtr);

        /* Enable monitoring */
        Base->TMR = Tmr | TMU_TMR_MODE(2U);

        Tmu_Ip_bInitialized[Instance] = TRUE;
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Tmu_Ip_Deinit
 * Description   : This function shall De-Init the TMU for all registers to default value.
 *
 *  @implements Tmu_Ip_Deinit_Activity
 *END**************************************************************************/
void Tmu_Ip_Deinit(const uint32 Instance)
{
    DEV_ASSERT(Instance < TMU_INSTANCE_COUNT);
    DEV_ASSERT(Tmu_Ip_bInitialized[Instance]);
    Tmu_Ip_bInitialized[Instance] = FALSE;
    TMU_Type * Base = Tmu_Ip_pBase[Instance];
    TMU_Reset(Base);

    #if (STD_ON == TMU_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Tmu_ClearUserAccessAllowed, (uint32)Base);
    #endif /* (STD_ON == TMU_IP_ENABLE_USER_MODE_SUPPORT) */
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Tmu_Ip_StartMonitoring
 * Description   : This function shall start monitoring temperature on selected site.
 * This function should be called after TMU initialization is done.
 * User must wait at least 500 us before changing modes.
 *
 * @implements Tmu_Ip_StartMonitoring_Activity
 *END**************************************************************************/
void Tmu_Ip_StartMonitoring(const uint32 Instance)
{
    DEV_ASSERT(Instance < TMU_INSTANCE_COUNT);
    TMU_Type * Base = Tmu_Ip_pBase[Instance];
    DEV_ASSERT(TMU_IP_MODE_IDLE_LOW_POWER == TMU_GetMode(Base));

    Base->TMR |= TMU_TMR_MODE(2U);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Tmu_Ip_StopMonitoring
 * Description   : This function shall stop monitoring temperature on selected site.
 * User must wait at least 500 us before changing modes.
 *
 * @implements Tmu_Ip_StopMonitoring_Activity
 *END**************************************************************************/
void Tmu_Ip_StopMonitoring(const uint32 Instance)
{
    DEV_ASSERT(Instance < TMU_INSTANCE_COUNT);
    TMU_Type * Base = Tmu_Ip_pBase[Instance];
    DEV_ASSERT(TMU_IP_MODE_MONITORING == TMU_GetMode(Base));

    Base->TMR &= ~TMU_TMR_MODE_MASK;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Tmu_Ip_EnableMonitoringSite
 * Description   : This function shall enable the site which will be monitored.
 * The site mask input value can be set using TMU_IP_MONITORING_SITE_ defines.
 *
 * @implements Tmu_Ip_EnableMonitoringSite_Activity
 *END**************************************************************************/
void Tmu_Ip_EnableMonitoringSite(const uint32 Instance,
                                 const uint8 TmuSiteMask)
{
    DEV_ASSERT(Instance < TMU_INSTANCE_COUNT);
    TMU_Type * Base = Tmu_Ip_pBase[Instance];
    DEV_ASSERT(TMU_IP_MODE_IDLE_LOW_POWER == TMU_GetMode(Base));

    Base->TMSR = TMU_TMSR_SITE(TmuSiteMask);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Tmu_Ip_DisableMonitoringSite
 * Description   : This function shall disable the selected site from monitoring.
 * The site mask input value can be set using TMU_IP_MONITORING_SITE_ defines.
 *
 * @implements Tmu_Ip_DisableMonitoringSite_Activity
 *END**************************************************************************/
void Tmu_Ip_DisableMonitoringSite(const uint32 Instance,
                                  const uint8 TmuSiteMask)
{
    DEV_ASSERT(Instance < TMU_INSTANCE_COUNT);
    TMU_Type * Base = Tmu_Ip_pBase[Instance];
    DEV_ASSERT(TMU_IP_MODE_IDLE_LOW_POWER == TMU_GetMode(Base));

    Base->TMSR &= TMU_TMSR_SITE(~(uint32)(TmuSiteMask));
}

 /*FUNCTION**********************************************************************
 *
 * Function Name : Tmu_Ip_SetTempThreshold
 * Description   : This function shall set the temperature threshold.
 *
 * @implements Tmu_Ip_SetTempThreshold_Activity
 *END**************************************************************************/
void Tmu_Ip_SetTempThreshold(const uint32 Instance,
                             const Tmu_Ip_ThresholdType ThresholdType,
                             const uint16 ThresholdValue)
{
    DEV_ASSERT(Instance < TMU_INSTANCE_COUNT);
    TMU_Type * Base = Tmu_Ip_pBase[Instance];
    Tmu_Ip_ThresholdConfigType ThrConfig;

    ThrConfig.Enable = TRUE;
    ThrConfig.ThresholdType = ThresholdType;
    ThrConfig.ThresholdValue = ThresholdValue;
    /*this function does not modify the interrupt enable state for the threshold*/
    TMU_SetTemperatureThreshold(Base, &ThrConfig);
}

/*FUNCTION**********************************************************************
 *
 * Function Name :  Tmu_Ip_GetTempMinMaxLevel
 * Description   :  This function reads the minimum or maximum temperature recorded at one site.
 *                  If the temperature is invalid, it will return TMU_IP_INVALID_TEMPERATURE value.
 *                  The return value is Q9.1 format: 9 bits for highest temperature recorded
 *                  and 1 bit for 0.5 degrees resolution. User can clear the current temperature
 *                  value by setting ClearValidFlag parameter.
 *
 * @implements Tmu_Ip_GetTempMinMaxLevel_Activity
 *END**************************************************************************/
uint16 Tmu_Ip_GetTempMinMaxLevel(const uint32 Instance,
                                 const Tmu_Ip_TempLevelType TempLevelType,
                                 const boolean ClearValidFlag)
{
    DEV_ASSERT(Instance < TMU_INSTANCE_COUNT);
    TMU_Type * Base = Tmu_Ip_pBase[Instance];
    uint16 TempValue = (uint16)TMU_IP_INVALID_TEMPERATURE;
    uint16 Tp5Value;

    if (TMU_IP_TEMP_LEVEL_MAX == TempLevelType)
    {
        /* Check the temperature is valid to reading */
        if ((Base->TMHTCR & TMU_TMHTCR_V_MASK) != 0U)
        {

            /* Read highest temperature */
            TempValue = (uint16)(Base->TMHTCR & TMU_TMHTCR_TEMP_MASK);
            /* Read TP5 bitfield indicates a 0.5K temp */
            Tp5Value = (uint16)((Base->TMHTCR & TMU_TMHTCR_TP5_MASK) >> TMU_TMHTCR_TP5_SHIFT);
            /* calculate actual highest temperature */
            TempValue = (TempValue << 1U) + Tp5Value;
        }
        /* Check to clear the temperature */
        if (TRUE == ClearValidFlag)
        {
            Base->TMHTCR |= TMU_TMHTCR_V_MASK;
        }
    }
    else
    {
        /* Check the temperature is valid to reading */
        if ((Base->TMLTCR & TMU_TMLTCR_V_MASK) != 0U)
        {
            /* Read lowest temperature */
            TempValue = (uint16)(Base->TMLTCR & TMU_TMLTCR_TEMP_MASK);
            /* Read TP5 bitfield indicates a 0.5K temp */
            Tp5Value = (uint16)((Base->TMLTCR & TMU_TMLTCR_TP5_MASK) >> TMU_TMLTCR_TP5_SHIFT);
            /* calculate actual lowest temperature */
            TempValue = (TempValue << 1U) + Tp5Value;
        }
        /* Check to clear the temperature */
        if (TRUE == ClearValidFlag)
        {
            Base->TMLTCR |= TMU_TMLTCR_V_MASK;
        }
    }
    return TempValue;
}

/*FUNCTION**********************************************************************
 *
 * Function Name :  Tmu_Ip_GetTempMaxRate
 * Description   :  Retrieves the maximum rate the temperature has risen or fallen,
 *                  and clears that rate if ClearValidFlag is TRUE.
 *                  If the temperature is invalid (cleared), it will return TMU_IP_INVALID_TEMPERATURE_RATE value.
 *
 * @implements Tmu_Ip_GetTempMaxRate_Activity
 *END**************************************************************************/
uint8 Tmu_Ip_GetTempMaxRate(const uint32 Instance,
                            const Tmu_Ip_TempRateType TempRateType,
                            const boolean ClearValidFlag)
{
    DEV_ASSERT(Instance < TMU_INSTANCE_COUNT);
    TMU_Type * Base = Tmu_Ip_pBase[Instance];
    uint8 TempRate = (uint8)TMU_IP_INVALID_TEMPERATURE_RATE;

    if (TMU_IP_TEMP_RATE_RISING == TempRateType)
    {
        /* Check the temperature is valid to reading */
        if ((Base->TMRTRCR & TMU_TMRTRCR_V_MASK) != 0U)
        {
            /* Read rising temperature */
            TempRate = (uint8)(Base->TMRTRCR & TMU_TMRTRCR_TEMP_MASK);
        }
        /* Check to clear the temperature */
        if (TRUE == ClearValidFlag)
        {
            Base->TMRTRCR |= TMU_TMRTRCR_V_MASK;
        }
    }
    else
    {
        /* Check the temperature is valid to reading */
        if ((Base->TMFTRCR & TMU_TMFTRCR_V_MASK) != 0U)
        {
            /* Read falling temperature */
            TempRate = (uint8)(Base->TMFTRCR & TMU_TMFTRCR_TEMP_MASK);
        }
        /* Check to clear the temperature */
        if (TRUE == ClearValidFlag)
        {
            Base->TMFTRCR |= TMU_TMFTRCR_V_MASK;
        }
    }
    return TempRate;
}

/*FUNCTION**********************************************************************
 *
 * Function Name :  Tmu_Ip_GetTemp
 * Description   :  This function shall read the last temperature at the selected site
 *                  If the temperature is invalid, it will return TMU_IP_INVALID_TEMPERATURE value.
 *                  The return value is Q9.1 format : 9 bits for highest temperature recorded
 *                  and 1 bit for 0.5 degrees resolution.
 *
 * @implements Tmu_Ip_GetTemp_Activity
 *END**************************************************************************/
void Tmu_Ip_GetTemp(const uint32 Instance,
                    const uint8 TmuMonitoringSite,
                    const Tmu_Ip_ReportTempType TmuTempType,
                    uint16 * const TmuTempVal)
{
    DEV_ASSERT(Instance < TMU_INSTANCE_COUNT);
    DEV_ASSERT(TmuMonitoringSite < TMU_TRITRATSR_COUNT);
    DEV_ASSERT(TmuTempVal != NULL_PTR);
    const TMU_Type * Base = Tmu_Ip_pBase[Instance];
    uint16 ReportTemp = TMU_IP_INVALID_TEMPERATURE;
    uint16 Tp5Value;

    switch (TmuTempType)
    {
    case TMU_IP_REPORT_IMMEDIATE_TEMPERATURE:
        /* Check the temperature is valid to reading */
        if ((Base->TRITRATSR[TmuMonitoringSite].TRITSR & TMU_TRITSR_V_MASK) != 0U)
        {
            /* Read report immediate temperature at selected site */
            ReportTemp = (uint16)(Base->TRITRATSR[TmuMonitoringSite].TRITSR & TMU_TRITSR_TEMP_MASK);
            /* Read TP5 bitfield indicates a 0.5K temp */
            Tp5Value = (uint16)((Base->TRITRATSR[TmuMonitoringSite].TRITSR & TMU_TRITSR_TP5_MASK) >> TMU_TRITSR_TP5_SHIFT);
            /* calculate actual report immediate temperature */
            ReportTemp = (ReportTemp << 1U) + Tp5Value;
        }
        break;
    case TMU_IP_REPORT_AVERAGE_TEMPERATURE:
        /* Check the temperature is valid to reading */
        if ((Base->TRITRATSR[TmuMonitoringSite].TRATSR & TMU_TRATSR_V_MASK) != 0U)
        {
            /* Read report average temperature at selected site */
            ReportTemp = (uint16)(Base->TRITRATSR[TmuMonitoringSite].TRATSR & TMU_TRATSR_TEMP_MASK);
            ReportTemp = (ReportTemp << 1U);
        }
        break;
    default:
        /* Do nothing */
        break;
    }

    *TmuTempVal = ReportTemp;
}

/*FUNCTION**********************************************************************
 *
 * Function Name :  Tmu_Ip_EnableNotifications
 * Description   :  This function enables the notifications for the selected types of thresholds.
 *                  The interrupt mask input value can be set using TMU_IP_INTERRUPT_ defines.
 *                  The masked value of notifications to enable
 *                  - For example:
 *                      - With mask = TMU_IP_INTERRUPT_IMMEDIATE_HIGH_TEMP to enable immediate high temperature
 *                          threshold interrupt(IHTTIE).
 *                      - With mask = (TMU_IP_INTERRUPT_IMMEDIATE_HIGH_TEMP | TMU_IP_INTERRUPT_AVERAGE_HIGH_TEMP)
 *                          to enable immediate high temperature threshold exceeded(IHTTIE) and average
 *                          high temperature threshold exceeded(AHTTIE).
 *
 * @implements Tmu_Ip_EnableNotifications_Activity
 *END**************************************************************************/
void Tmu_Ip_EnableNotifications(const uint32 Instance,
                                const uint32 NotificationsMask)
{
    DEV_ASSERT(Instance < TMU_INSTANCE_COUNT);
    /* Avoid compiler warning */
#if defined(TMU_IP_DEV_ERROR_DETECT) && (TMU_IP_DEV_ERROR_DETECT == STD_ON)
    /* trying to enable a notification for which there's no configured handler? */
    DEV_ASSERT((NotificationsMask & ~Tmu_Ip_GetConfiguredNotifications(Instance)) == 0U);
#endif
    TMU_Type * Base = Tmu_Ip_pBase[Instance];

    Base->TIER |= NotificationsMask;
}

/*FUNCTION**********************************************************************
 *
 * Function Name :  Tmu_Ip_DisableNotifications
 * Description   :  This function disables the notifications for the selected types of thresholds.
 *                  The interrupt mask input value can be set using TMU_IP_INTERRUPT_ defines.
 *                  The masked value of notifications to disable
 *                  - For example:
 *                      - With mask = TMU_IP_INTERRUPT_IMMEDIATE_HIGH_TEMP to disable immediate high temperature
 *                        threshold interrupt(IHTTIE).
 *                      - With mask = (TMU_IP_INTERRUPT_IMMEDIATE_HIGH_TEMP | TMU_IP_INTERRUPT_AVERAGE_HIGH_TEMP)
 *                        to disable immediate high temperature threshold exceeded(IHTTIE) and average
 *                        high temperature threshold exceeded(AHTTIE).
 *
 * @implements Tmu_Ip_DisableNotifications_Activity
 *END**************************************************************************/
void Tmu_Ip_DisableNotifications(const uint32 Instance,
                                 const uint32 NotificationsMask)
{
    DEV_ASSERT(Instance < TMU_INSTANCE_COUNT);
    TMU_Type * Base = Tmu_Ip_pBase[Instance];

    Base->TIER &= ~NotificationsMask;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Tmu_Ip_SetMeasurementInterval
 * Description   : This function shall set the interval for the temperature
 * monitoring. It should only be changed when monitoring is disabled.
 *
 * @implements Tmu_Ip_SetMeasurementInterval_Activity
 *END**************************************************************************/
void Tmu_Ip_SetMeasurementInterval(const uint32 Instance,
                                   const Tmu_Ip_TempMonitoringIntervalType TmuMonitoringInterval)
{
    DEV_ASSERT(Instance < TMU_INSTANCE_COUNT);
    TMU_Type * const Base = Tmu_Ip_pBase[Instance];

    DEV_ASSERT(TMU_IP_MODE_IDLE_LOW_POWER == TMU_GetMode(Base));
    TMU_SetIntervalValue(Base, TmuMonitoringInterval);
}

/*FUNCTION**********************************************************************
 *
 * Function Name :  Tmu_Ip_GetMode
 * Description   :  Retrieves the current mode.
 *                  (TMU_IP_MODE_MONITORING after a call to Tmu_Ip_StartMonitoring, otherwise TMU_IP_MODE_IDLE_LOW_POWER)
 *
 * @implements Tmu_Ip_GetMode_Activity
 *END**************************************************************************/
Tmu_Ip_ModeType Tmu_Ip_GetMode(const uint32 Instance)
{
    const TMU_Type * const Base = Tmu_Ip_pBase[Instance];

    return TMU_GetMode(Base);
}

#if (STD_ON == TMU_IP_ENABLE_USER_MODE_SUPPORT)
/*FUNCTION**********************************************************************
 *
 * Function Name : Tmu_SetUserAccessAllowed
 * Description   : Sets the UAA bit in REG_PROT to make the instance accessible in user mode.
 *
 *END**************************************************************************/
void Tmu_SetUserAccessAllowed(uint32 TmuBaseAddr)
{
    SET_USER_ACCESS_ALLOWED(TmuBaseAddr, TMU_PROT_MEM_U32);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Tmu_ClearUserAccessAllowed
 * Description   : Clears the UAA bit in REG_PROT to make the instance inaccessible in user mode.
 *
 *END**************************************************************************/
void Tmu_ClearUserAccessAllowed(uint32 TmuBaseAddr)
{
    CLR_USER_ACCESS_ALLOWED(TmuBaseAddr, TMU_PROT_MEM_U32);
}
#endif /* (STD_ON == TMU_IP_ENABLE_USER_MODE_SUPPORT) */

#define THERMAL_STOP_SEC_CODE
#include "Thermal_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

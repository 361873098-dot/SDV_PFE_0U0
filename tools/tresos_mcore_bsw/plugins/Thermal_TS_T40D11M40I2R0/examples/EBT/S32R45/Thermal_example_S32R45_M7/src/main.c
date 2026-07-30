
/*
*   Copyright 2021 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms.  By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms.  If you do not agree to
*   be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
*
*   This file contains sample code only. It is not part of the production code deliverables.
*/

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu.h"
#include "CDD_Thermal.h"
#include "Platform.h"

#include "check_example.h"
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define MIN_AMBIENT_TEMPERATURE         20
#define MAX_AMBIENT_TEMPERATURE         60
/*==================================================================================================
*                                      EXTERN DECLARATIONS
==================================================================================================*/
extern ISR(Tmu_Isr);

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
static volatile boolean Notification = FALSE;
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/


/* Converts temp value read from the TMU into Celsius degrees.
   The value is in same format as returned by driver: Q9.1 format 9 bits for temperature recorded and 1 bit for 0.5 degrees resolution. */
static int K2C(Thermal_TempValueType k)
{
    return k / 2 - 273;
}

void ImmediateHighTempNotification(uint32 siteMask)
{
    (void)siteMask;
    Notification = TRUE;
}

int main(void)
{
    volatile Thermal_TempValueType TempSite_0 = THERMAL_INVALID_TEMP;
    volatile Thermal_TempValueType TempSite_1 = THERMAL_INVALID_TEMP;
    volatile Thermal_TempValueType TempSite_2 = THERMAL_INVALID_TEMP;
    volatile Thermal_TempValueType MinTemp = THERMAL_INVALID_TEMP;
    volatile Thermal_TempValueType MaxTemp = THERMAL_INVALID_TEMP;
    volatile boolean bStatus = TRUE;

    /* Initialize Mcu Driver */
#if (MCU_PRECOMPILE_SUPPORT == STD_ON)
    Mcu_Init(NULL_PTR);
#else
    Mcu_Init(&Mcu_Config_VS_0);
#endif /* MCU_PRECOMPILE_SUPPORT == STD_ON */
    Mcu_InitClock(McuClockSettingConfig_0);
    while(MCU_PLL_LOCKED != Mcu_GetPllStatus())
    {
        /* Busy wait until the System PLL is locked */
    }
    Mcu_DistributePllClock();
    Mcu_SetMode(McuModeSettingConf_0);

    /* Initialize Platform Driver */
    Platform_Init(NULL_PTR);
    Platform_InstallIrqHandler(TMU_ALARM_IRQn, Tmu_Isr, NULL_PTR);
    Platform_SetIrq(TMU_ALARM_IRQn, TRUE);

#if (THERMAL_PRECOMPILE_SUPPORT == STD_ON)
    Thermal_Init(NULL_PTR);
#else
    Thermal_Init (&ThermalConfig_VS_0);
#endif /* THERMAL_PRECOMPILE_SUPPORT == STD_ON */

    /* A high temperature threshold is set to a value lower than the normal ambient temperature, to trigger the high temperature interrupt notification */
    Thermal_EnableNotifications(TMU_IP_INTERRUPT_IMMEDIATE_HIGH_TEMP);

    while (FALSE == Notification)
    {
        /* Wait until report temperature can be obtained */
    }

    Thermal_DisableNotifications(TMU_IP_INTERRUPT_IMMEDIATE_HIGH_TEMP);

    while (THERMAL_INVALID_TEMP == TempSite_0)
    {
        TempSite_0 = Thermal_GetTemp(TmuMonitoringSite_0, THERMAL_REPORT_TYPE_IMMEDIATE);
    }
    while (THERMAL_INVALID_TEMP == TempSite_1)
    {
        TempSite_1 = Thermal_GetTemp(TmuMonitoringSite_1, THERMAL_REPORT_TYPE_IMMEDIATE);
    }
    while (THERMAL_INVALID_TEMP == TempSite_2)
    {
        TempSite_2 = Thermal_GetTemp(TmuMonitoringSite_2, THERMAL_REPORT_TYPE_IMMEDIATE);
    }

     /* Wait for the hardware to write the minimum registered temperature... */
    while (THERMAL_INVALID_TEMP == MinTemp)
    {
        MinTemp = Thermal_GetTempMinMaxLevel(THERMAL_TEMP_LEVEL_TYPE_LOW, TRUE);
    }

    /* ... and the maximum. */
    while (THERMAL_INVALID_TEMP == MaxTemp)
    {
        MaxTemp = Thermal_GetTempMinMaxLevel(THERMAL_TEMP_LEVEL_TYPE_HIGH, TRUE);
    }

    if ((K2C(TempSite_0) < MIN_AMBIENT_TEMPERATURE) || \
        (K2C(TempSite_0) > MAX_AMBIENT_TEMPERATURE) || \
        (K2C(TempSite_1) < MIN_AMBIENT_TEMPERATURE) || \
        (K2C(TempSite_1) > MAX_AMBIENT_TEMPERATURE) || \
        (K2C(TempSite_2) < MIN_AMBIENT_TEMPERATURE) || \
        (K2C(TempSite_2) > MAX_AMBIENT_TEMPERATURE) || \
        (TempSite_0 < MinTemp)  || \
        (TempSite_0 > MaxTemp)  || \
        (TempSite_1 < MinTemp)  || \
        (TempSite_1 > MaxTemp)  || \
        (TempSite_2 < MinTemp)  || \
        (TempSite_2 > MaxTemp))
    {
        bStatus = FALSE;
    }

    Thermal_Deinit();

    Exit_Example(bStatus);

    return 0;
}

#ifdef __cplusplus
}
#endif

/** @} */

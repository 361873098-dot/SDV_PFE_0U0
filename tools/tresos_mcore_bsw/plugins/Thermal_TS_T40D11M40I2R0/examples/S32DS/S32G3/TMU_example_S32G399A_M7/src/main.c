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
#include "Clock_Ip.h"
#include "IntCtrl_Ip.h"
#include "Tmu_Ip.h"

#include "check_example.h"
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define TMU_IP_INSTANCE                 0U
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
static int K2C (uint16 k)
{
    return k / 2 - 273;
}

void AverageLowTempNotification(uint32 siteMask)
{
    (void)siteMask;
    Notification = TRUE;
}

int main(void)
{
    uint16 TempSite_0 = TMU_IP_INVALID_TEMPERATURE;
    uint16 TempSite_1 = TMU_IP_INVALID_TEMPERATURE;
    uint16 TempSite_2 = TMU_IP_INVALID_TEMPERATURE;
    uint16 MinTemp = TMU_IP_INVALID_TEMPERATURE;
    uint16 MaxTemp = TMU_IP_INVALID_TEMPERATURE;
    Tmu_Ip_StatusType InitStatus = TMU_IP_STATUS_ERROR;
    volatile boolean bStatus = TRUE;

    /* Initialize and configure drivers */
    Clock_Ip_Init(&Mcu_aClockConfigPB[0]);
    IntCtrl_Ip_Init(&IntCtrlConfig_0);
    InitStatus = Tmu_Ip_Init(TMU_IP_INSTANCE, &TmuHwUnit_0_VS_0);
    if (InitStatus != TMU_IP_STATUS_SUCCESS)
    {
        DevAssert(FALSE);
    }

    /* Install and enable interrupt handlers */
    IntCtrl_Ip_InstallHandler(TMU_ALARM_IRQn, Tmu_Isr, NULL_PTR);
    IntCtrl_Ip_EnableIrq(TMU_ALARM_IRQn);

    /* A low temperature threshold is set to a value higher than the normal ambient temperature, to trigger the low temperature interrupt notification */
    Tmu_Ip_EnableNotifications(TMU_IP_INSTANCE, TMU_IP_INTERRUPT_AVERAGE_LOW_TEMP);

    while (FALSE == Notification)
    {
        /* Wait until report temperature can be obtained */
    }

    Tmu_Ip_DisableNotifications(TMU_IP_INSTANCE, TMU_IP_INTERRUPT_AVERAGE_LOW_TEMP);

    while (TMU_IP_INVALID_TEMPERATURE == TempSite_0)
    {
        Tmu_Ip_GetTemp(TMU_IP_INSTANCE, TmuMonitoringSite_0, TMU_IP_REPORT_AVERAGE_TEMPERATURE, &TempSite_0);
    }

    while (TMU_IP_INVALID_TEMPERATURE == TempSite_1)
    {
        Tmu_Ip_GetTemp(TMU_IP_INSTANCE, TmuMonitoringSite_1, TMU_IP_REPORT_AVERAGE_TEMPERATURE, &TempSite_1);
    }

    while (TMU_IP_INVALID_TEMPERATURE == TempSite_2)
    {
        Tmu_Ip_GetTemp(TMU_IP_INSTANCE, TmuMonitoringSite_2, TMU_IP_REPORT_AVERAGE_TEMPERATURE, &TempSite_2);
    }

    /* Wait for the hardware to write the minimum registered temperature... */
    while (TMU_IP_INVALID_TEMPERATURE == MinTemp)
    {
        MinTemp = Tmu_Ip_GetTempMinMaxLevel(TMU_IP_INSTANCE, TMU_IP_TEMP_LEVEL_MIN, TRUE);
    }

    /* ... and the maximum. */
    while (TMU_IP_INVALID_TEMPERATURE == MaxTemp)
    {
        MaxTemp = Tmu_Ip_GetTempMinMaxLevel(TMU_IP_INSTANCE, TMU_IP_TEMP_LEVEL_MAX, TRUE);
    }

    if ((K2C(TempSite_0) < MIN_AMBIENT_TEMPERATURE) || \
        (K2C(TempSite_0) > MAX_AMBIENT_TEMPERATURE) || \
        (K2C(TempSite_1) < MIN_AMBIENT_TEMPERATURE) || \
        (K2C(TempSite_1) > MAX_AMBIENT_TEMPERATURE) || \
        (K2C(TempSite_2) < MIN_AMBIENT_TEMPERATURE) || \
        (K2C(TempSite_2) > MAX_AMBIENT_TEMPERATURE))
    {
        bStatus = FALSE;
    }

    Tmu_Ip_Deinit(TMU_IP_INSTANCE);

    Exit_Example(bStatus);

    return 0;
}

#ifdef __cplusplus
}
#endif

/** @} */

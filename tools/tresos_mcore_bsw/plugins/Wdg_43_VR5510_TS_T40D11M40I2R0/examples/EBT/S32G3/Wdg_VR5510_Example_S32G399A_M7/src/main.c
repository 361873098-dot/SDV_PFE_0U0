/*
*   (c) Copyright 2020-2023 NXP
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
#include "Wdg_43_VR5510.h"
#include "Gpt.h"
#include "CDD_I2c.h"
#include "CDD_Pmic.h"
#include "Osif.h"
#include "Mcu.h"
#include "Port.h"
#include "Platform.h"

#include "check_example.h"

/*==================================================================================================
*                                      EXTERN DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
volatile uint16 u16GlobalRegisterValue = 0U;
/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/* The check fault status notification
This function will be called by Wdg_VR5510_Cbk_GptNotification0 after each watchdog refresh.
It will be used if user enables the notification in the user configuration.
API will expose the FS_G_FLAG register value to user and they can be use to do something witch each bit field state.
*/
void Wdg_VR5510_CheckFaultStatusNotify(const uint16 u16RegValue)
{
    /* Where customer can using FS_G_Flag value to do something */

    /* Copy value to out wdg_vr5510 site */
    u16GlobalRegisterValue = u16RegValue;
}

void CDD_Gd3162_OsifSystemTimeDelay(uint32 DelayUs)
{
    uint32 DeltaTime = 0U;
    uint32 TimeoutTick = OsIf_MicrosToTicks(DelayUs, OSIF_COUNTER_SYSTEM);
    uint32 StartTime = OsIf_GetCounter(OSIF_COUNTER_SYSTEM);

    while (DeltaTime <= TimeoutTick)
    {
        DeltaTime += OsIf_GetElapsed(&StartTime, OSIF_COUNTER_SYSTEM);
    }
}

int main(void)
{
    Std_ReturnType eInternalStatus;

    /* Initialize the Mcu driver */
    Mcu_Init(NULL_PTR);

    /* Configure the clock settings */
    Mcu_InitClock(McuClockSettingConfig_0);
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() )
    {
        /* Busy wait until the System PLL is locked */
    }

    Mcu_DistributePllClock();

    Mcu_SetMode(McuModeRun);

    /* Initialize Platform driver */
    Platform_Init(NULL_PTR);

    /* Initialize the Osif driver */
    OsIf_Init(NULL_PTR);

    /* Initialize the Pins used */
    Port_Init(NULL_PTR);

    /* Initialize the I2C driver */
    I2c_Init(NULL_PTR);

    /* Initialize the Gpt driver */
    Gpt_Init(NULL_PTR);

    /* Initialize the Pmic driver */
    Pmic_Init(NULL_PTR);

    /* Initialize the Wdg_VR5510 driver */
    Wdg_43_VR5510_Init(NULL_PTR);

    /* Initialize the Pmic device */
    eInternalStatus = Pmic_InitDevice(PmicConf_PmicDevice_PmicDevice_0);

    if (eInternalStatus == E_OK)
    {
        /* Set the Wdg_VR5510 operation mode to Fast Mode */
        Wdg_43_VR5510_SetMode(WDGIF_FAST_MODE);

        /* Delay after switch another mode */
        CDD_Gd3162_OsifSystemTimeDelay(5000000);

        /* Set the Wdg_VR5510 operation mode to OFF Mode */
        Wdg_43_VR5510_SetMode(WDGIF_OFF_MODE);

        Exit_Example(TRUE);
    }
    else
    {
        Exit_Example(FALSE);
    }

    return 0;
}


#ifdef __cplusplus
}
#endif

/** @} */

/*
*   (c) Copyright 2021-2023 NXP
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


int main(void)
{
    Std_ReturnType eInternalStatus;
    /* Initialize the Mcu driver */
    Mcu_Init(NULL_PTR);

    /* Configure the clock settings */
    Mcu_InitClock(BOARD_InitPeripherals);

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

        /* Set the Wdg_VR5510 trigger condition */
        Wdg_43_VR5510_SetTriggerCondition(5000);

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

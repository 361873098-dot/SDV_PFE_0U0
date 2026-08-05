/*
*   (c) Copyright 2021 NXP
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

/*!
**  @addtogroup main_module main module documentation
**  @{
*/
/* MODULE main */


/* Including necessary configuration files. */
#include "Mcal.h"
#include "CDD_Pmic.h"
#include "Mcu.h"
#include "CDD_I2c.h"
#include "Port.h"
#include "Dio.h"
#include "check_example.h"
#include "Osif.h"

/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
    Std_ReturnType CheckStatus;

    /* Initialize the Mcu driver */
    Mcu_Init(NULL_PTR);

    /* Configure the clock settings */
    Mcu_InitClock(BOARD_InitPeripherals);

    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() )
    {
        /* Busy wait until the System PLL is locked */
    }
    /* Apply the PLL clock to system */
    Mcu_DistributePllClock();

    /* Initialize the Osif driver */
    OsIf_Init(NULL_PTR);

    /* Initialize the Pins used */
    Port_Init(NULL_PTR);

    /* Initialize the I2C driver */
    I2c_Init(NULL_PTR);

    /* Initialize the Pmic driver */
    Pmic_Init(NULL_PTR);

    /* Initialize the Pmic device */
    CheckStatus = Pmic_InitDevice(PmicConf_PmicDevice_PmicDevice_0);

    if ((Std_ReturnType) E_OK == CheckStatus)
    {
        Exit_Example(TRUE);
    }
    else
    {
        Exit_Example(FALSE);
    }

    return (0U);
}

/* END main */
/*!
** @}
*/

/*
*   Copyright 2022 NXP
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
#include "Clock_Ip.h"
#include "Clock_Ip_Cfg.h"
#include "check_example.h"

#define XBAR_CLOCK_CFG0_FREQ   24000000U
#define XBAR_CLOCK_CFG1_FREQ   400000000U

/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
    boolean Result = TRUE;
    Clock_Ip_StatusType clockStatus;

    clockStatus = Clock_Ip_Init(&Mcu_aClockConfigPB[0]);

    if (clockStatus != CLOCK_IP_SUCCESS)
    {
        Result = FALSE;
    }
    else
    {
        if (Clock_Ip_GetClockFrequency(XBAR_CLK) != XBAR_CLOCK_CFG0_FREQ)
        {
            Result = FALSE;
        }
    }

    clockStatus = Clock_Ip_Init(&Mcu_aClockConfigPB[1]);

    if (clockStatus != CLOCK_IP_SUCCESS)
    {
        Result = FALSE;
    }
    else
    {
        if (Clock_Ip_GetClockFrequency(XBAR_CLK) != XBAR_CLOCK_CFG1_FREQ)
        {
            Result = FALSE;
        }
    }

    Exit_Example(Result);
    return (0U);
}

/* END main */
/*!
** @}
*/

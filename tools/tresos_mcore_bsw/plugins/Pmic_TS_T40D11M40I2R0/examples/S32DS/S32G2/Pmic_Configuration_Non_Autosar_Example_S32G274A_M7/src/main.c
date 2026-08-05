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

/*!
**  @addtogroup main_module main module documentation
**  @{
*/
/* MODULE main */


/* Including necessary configuration files. */
#include "Mcal.h"
#include "CDD_Pmic.h"
#include "S32G274A.h"
#include "IntCtrl_Ip.h"
#include "I2c_Ip.h"
#include "Clock_Ip.h"
#include "Clock_Ip_Cfg.h"
#include "Siul2_Port_Ip.h"
#include "Siul2_Port_Ip_Cfg.h"
#include "I2c_Ip_PBcfg.h"
#include "check_example.h"
#include "Osif.h"

#define I2C4_MASTER   4U
/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
    Std_ReturnType eCheckStatus;

    /* Setup clocks */
    Clock_Ip_Init(Mcu_aClockConfigPB);
    /* Init Osif */
    OsIf_Init(NULL_PTR);
    /* Setup pins */
    Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);
    /* Init I2C master device */
    I2c_Ip_MasterInit(I2C4_MASTER, &I2c_IICMasterChannel0);
    /* Initialize Pmic driver */
    Pmic_Init(NULL_PTR);

    /* Initialize VR5510 device */
    eCheckStatus = Pmic_InitDevice(PmicConf_PmicDevice_PmicDevice_0);

    if ((Std_ReturnType) E_OK == eCheckStatus)
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

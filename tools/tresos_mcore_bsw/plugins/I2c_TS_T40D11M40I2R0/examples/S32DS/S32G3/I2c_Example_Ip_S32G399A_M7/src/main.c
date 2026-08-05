/*
*   Copyright M4_SRC_YEAR_ID M4_SRC_COPYRIGHTED_TO
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

/**
*   @file main.c
*
*   @addtogroup main_module main module documentation
*   @{
*/


#ifdef __cplusplus
extern "C" {
#endif

/* Including necessary configuration files. */
#include "IntCtrl_Ip.h"
#include "I2c_Ip.h"
#include "Clock_Ip.h"
#include "Siul2_Port_Ip.h"
#include "I2c_Ip_VS_0_PBcfg.h"
#include "check_example.h"

volatile int exit_code = 0;

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/**
* @brief        Define transfer size
*/
#define TRANSFER_SIZE 8U

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/**
* @brief        Define data buffers
*/
uint8 rxBufferSlave[TRANSFER_SIZE] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
uint8 txBuffer[TRANSFER_SIZE] = {0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7};

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

void I2c_SlaveCallback(I2c_Ip_SlaveEventType event, uint8 userData)
{
	uint8 instance = userData;

    switch(event)
    {
        case I2C_SLAVE_EVENT_TX_REQ:
            I2c_Ip_SlaveSetBuffer(instance, txBuffer, TRANSFER_SIZE);
            break;

        case I2C_SLAVE_EVENT_RX_REQ:
        	I2c_Ip_SlaveSetBuffer(instance, rxBufferSlave, TRANSFER_SIZE);
            break;

        default:
            /* Cast to void to avoid compiler warnings */
            (void) instance;
    }
}

/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
    /* Write your code here */

	uint32 timeout = 0xFFFF;
	uint32 i;
	boolean checkOk = TRUE;

	/* Setup pins */
	Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

 	/* Setup clocks */
 	Clock_Ip_Init(Mcu_aClockConfigPB);

	/* Enable I2C interrupts */
	IntCtrl_Ip_Init(&IntCtrlConfig_0);
    IntCtrl_Ip_EnableIrq(I2C4_IRQn);
	IntCtrl_Ip_InstallHandler(I2C4_IRQn, I2c_Ip_IRQHandler4, NULL_PTR);
	IntCtrl_Ip_EnableIrq(I2C2_IRQn);
	IntCtrl_Ip_InstallHandler(I2C2_IRQn, I2c_Ip_IRQHandler2, NULL_PTR);
	/* Init I2C master device */

    I2c_Ip_MasterInit(I2cChannel_0, &I2c_IICMasterChannel0_VS_0);

    /* Init I2C slave device */
    I2c_Ip_SlaveInit(I2cChannel_1, &I2c_IICSlaveChannel1_VS_0);

	/* Send data non-blocking */
	I2c_Ip_MasterSendData(I2cChannel_0, txBuffer, TRANSFER_SIZE, true);

	/* Wait master transfer to finish */
	while(((I2c_Ip_MasterGetTransferStatus(I2cChannel_0)) == I2C_IP_BUSY_STATUS) && (timeout > 0))
	{
		timeout--;
	}

	timeout = 0xFFFF;

	/* Wait slave module to finish */
	while(((I2c_Ip_SlaveGetTransferStatus(I2cChannel_1)) == I2C_IP_BUSY_STATUS) && (timeout > 0))
	{
		timeout--;
	}

    /* Verify data received */
    for (i = 0; i < TRANSFER_SIZE; i ++)
    {
        if( txBuffer[i] != rxBufferSlave[i])
        {
            checkOk = FALSE;
        }
    }

    /* Check if transfer was successful */
    Exit_Example(checkOk);

    return exit_code;
}

#ifdef __cplusplus
}
#endif


/** @} */

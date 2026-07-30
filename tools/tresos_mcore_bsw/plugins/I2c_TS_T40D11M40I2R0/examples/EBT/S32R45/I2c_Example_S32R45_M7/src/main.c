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

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_I2c.h"
#include "Mcu.h"
#include "Mcal.h"
#include "Platform.h"
#include "Port.h"

#include "check_example.h"

#ifdef SEMIHOSTING
#include <stdio.h>
#endif

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
I2c_DataType rxBufferSlave[TRANSFER_SIZE] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
I2c_DataType txBuffer[TRANSFER_SIZE] = {0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7};


I2c_RequestType pRequestSend =
{
  /* Slave address */ /*10 bit address*/ /*high speed */ /* expect Nack */ /*repeated start */ /*buffer size */ /*Data direction */ /*Buffer*/
  0x38,               FALSE,             FALSE,          FALSE,            FALSE,              8U,              I2C_SEND_DATA,      txBuffer
};

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief        Callback for all i2c instances
*/
void I2c_Callback(uint8 u8Event, uint8 u8Channel)
{
    switch(u8Event)
    {
        case I2C_SLAVE_EVENT_RX_REQ:
            I2c_PrepareSlaveBuffer(u8Channel, TRANSFER_SIZE, rxBufferSlave);
            break;

        case I2C_SLAVE_EVENT_TX_REQ:
            I2c_PrepareSlaveBuffer(u8Channel, TRANSFER_SIZE, txBuffer);
            break;

        default:
            (void) u8Channel;
    }
}

int main(void)
{

    uint8 i;
    uint32 timeout = 0xFFFF;
    boolean checkOk = TRUE;
    I2c_StatusType status;

    /* Init system clock */
    Mcu_Init(NULL_PTR);

    /* Initialize the clock tree and apply PLL as system clock */
    Mcu_InitClock(McuClockSettingConfig_0);

    /* Initialize Port driver */
    Port_Init(NULL_PTR);

    /* Initialize Platform driver */
    Platform_Init(NULL_PTR);

    /* Init i2c instances */
    I2c_Init(&I2c_Config_VS_0);

    /* Master send data */
    I2c_AsyncTransmit(0U, &pRequestSend);

    /* Wait until master is ready */
    while(((status = I2c_GetStatus(I2cChannel_0)) == I2C_CH_SEND) && (timeout > 0))
    {
        timeout--;
    }

    /* Wait until slave is ready */
    while(((status = I2c_GetStatus(I2cChannel_1)) == I2C_CH_RECEIVE) && (timeout > 0))
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

    Exit_Example(checkOk);

    return (0U);
}

#ifdef __cplusplus
}
#endif



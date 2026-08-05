/*
*   Copyright 2020 NXP
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
#include "Siul2_Port_Ip.h"
#include "Spi_Ip.h"
#include "Dma_Ip.h"
#include "IntCtrl_Ip.h"
#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/* Time to transfer all frame data */
#define NUMBER_OF_BYTES     (10)

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
#define MASTER_EXTERNAL_DEVICE              (Spi_Ip_DeviceAttributes_SpiExternalDevice_0_Instance_1)

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define SPI_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Spi_MemMap.h"
uint8 RxBuffer[NUMBER_OF_BYTES];
#define SPI_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Spi_MemMap.h"
uint8 TxBuffer[NUMBER_OF_BYTES] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09};
#define SPI_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Spi_MemMap.h"

/**
* @brief        Main function of the example
*/
int main(void)
{
    /* Write your code here */
    uint8 Count = 0;
    boolean Passed = TRUE;
    uint32 Counter = 0xFFFFFF;
    Spi_Ip_HwStatusType Status;
    /* Initialize clock */
    Clock_Ip_Init(&Mcu_aClockConfigPB[0]);

    /* Configure pins */
    Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

    /* Initialize Dma */
    Dma_Ip_Init(&Dma_Ip_xDmaInitPB);
    /* Initialize interrupt */
    IntCtrl_Ip_Init(&IntCtrlConfig_0);

    /* Initialize each Spi hardware units using*/
    Spi_Ip_Init(&Spi_Ip_PhyUnitConfig_SpiPhyUnit_0_Instance_1);

    /* Update Framesize */
    Spi_Ip_UpdateFrameSize(&MASTER_EXTERNAL_DEVICE, 8U);

    /* Update Transfered Bit order */
    Spi_Ip_UpdateLsb(&MASTER_EXTERNAL_DEVICE, FALSE);

    /* Update Transfer Mode */
    Spi_Ip_UpdateTransferMode(MASTER_EXTERNAL_DEVICE.Instance, SPI_IP_INTERRUPT);

    /* Master starts transfer, async method is used */
    Spi_Ip_AsyncTransmit(&MASTER_EXTERNAL_DEVICE, TxBuffer, RxBuffer, NUMBER_OF_BYTES, NULL_PTR);

    do
    {
        Counter --;
        Status = Spi_Ip_GetStatus(MASTER_EXTERNAL_DEVICE.Instance);
    }
    while ( (Counter > 0UL) && (Status != SPI_IP_IDLE) );

    for (Count = 0u; Count < 10u; Count++)
    {
        if (TxBuffer[Count] != RxBuffer[Count])
        {
            Passed = FALSE;
            break;
        }
    }

    Exit_Example(Passed);

    return 0;
}

#ifdef __cplusplus
}
#endif

/** @} */

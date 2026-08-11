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
#include "Lpspi_Ip.h"
#include "IntCtrl_Ip.h"
#include "Llce_Firmware_Load.h"
#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/* Time to transfer all frame data */
#define TIMEOUT             ((uint32)1000000UL)
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
#define MASTER_EXTERNAL_DEVICE              (Lpspi_Ip_DeviceAttributes_SpiExternalDevice_0_Instance_2)

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
    /* Initialize clock */
    Clock_Ip_Init(&Mcu_aClockConfigPB[0]);

    /* Configure pins */
    Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

    /* Initialize interrupt */
    IntCtrl_Ip_Init(&IntCtrlConfig_0);

    /* Load LLCE firmware */
    Llce_Firmware_Load();

    /* Initialize each Spi hardware units using*/
    Lpspi_Ip_Init(&Lpspi_Ip_PhyUnitConfig_SpiPhyUnit_0_Instance_2);

    /* Update Framesize */
    Lpspi_Ip_UpdateFrameSize(&MASTER_EXTERNAL_DEVICE, 8U);

    /* Update Transfered Bit order */
    Lpspi_Ip_UpdateLsb(&MASTER_EXTERNAL_DEVICE, FALSE);

    /* Master starts transfer, async method is used */
    Lpspi_Ip_SyncTransmit(&MASTER_EXTERNAL_DEVICE, TxBuffer, RxBuffer, NUMBER_OF_BYTES, TIMEOUT);

    return 0;
}

#ifdef __cplusplus
}
#endif

/** @} */

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
#include "Mcu.h"
#include "Spi.h"
#include "Platform.h"
#include "Port.h"
#include "Llce_Firmware_Load.h"
#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Spi_MemMap.h"
static  Spi_DataBufferType RxChBuf[20];
#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#include "Spi_MemMap.h"
static Spi_DataBufferType TxChBuf[20] = {0,11,0,12,0,13,0,14,0,15,0,16,0,17,0,18,0,19,0,20};
#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#include "Spi_MemMap.h"

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
int main(void);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Main function of the example
*/
int main(void)
{
    /* Initialize the Mcu driver */
    Mcu_Init(NULL_PTR);
    Mcu_InitClock(McuClockSettingConfig_0);
#if (MCU_NO_PLL == STD_OFF)
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() )
    {
        /* Busy wait until the System PLL is locked */
    }

    Mcu_DistributePllClock();
#endif
    Mcu_SetMode(McuModeSettingConf_0);

    /* Initialize Port driver */
    Port_Init(NULL_PTR);
    /* Initialize Interrupt */
    Platform_Init(NULL_PTR);

    /* Load LLCE firmware */
    Llce_Firmware_Load();

    Spi_Init(NULL_PTR);

    /* Set up external buffer to transmission and reception */
    Spi_SetupEB(0u, TxChBuf, RxChBuf, 20u);

    /* This sequence transferring 10 frame 16 bits using synchronous method*/
    Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_0);

    return (0U);
}


#ifdef __cplusplus
}
#endif

/** @} */

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

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "S32R45_SIUL2.h"
#include "S32R45_NVIC.h"

#include "Sd_Emmc_Ip.h"
#include "Usdhc_Ip.h"
#include "Sd_Emmc_Ip_Cfg.h"
#include "Clock_Ip.h"
#include "Power_Ip.h"

#include "check_example.h"

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/* Test Erase/Write/Read: 10 blocks from block 1 */
#define EEP_BLOCK_START             (1U)
#define EEP_BLOCK_COUNT             (10U)      /* 10 blocks */

#define EEP_BLOCK_SIZE              (512U)    /* 512 bytes */
#define EEP_TEST_SIZE               (EEP_BLOCK_SIZE * EEP_BLOCK_COUNT)

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
/* Data buffers to test */
VAR_ALIGN(uint8 TxBuffer[EEP_TEST_SIZE],4U)
VAR_ALIGN(uint8 RxBuffer[EEP_TEST_SIZE],4U)

uint8 TxBuffer[EEP_TEST_SIZE];
uint8 RxBuffer[EEP_TEST_SIZE];


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

void BufferInit(void)
{
    uint32 Count;

    /* Initialize data to default value */
    for (Count = 0U; Count < EEP_TEST_SIZE; Count++)
    {
        TxBuffer[Count] = (uint8)Count;
        RxBuffer[Count] = 0U;
    }
}


/* Enable Usdhc interrupts */
void Init_INTC(void)
{
    S32_NVIC->ISER[36UL >> 5UL] = 1UL << (36UL & 0x1FUL);
    *(volatile uint32*)((*(volatile uint32*)(0xE000ED08UL)) + ((16UL + 36UL) << 2UL)) = (uint32)uSDHC0_Isr;
}

void Enable_Irq(void)
{
    /* Enable external interrupts */
    OsIf_ResumeAllInterrupts() ;
}

void PinInit(void)
{
    /*  For speed mode switch like from High Speed mode to HS200 mode or HS400(enhanced) mode,
        you must calibrate the right configuration of slew rate and drive strength for chip pad that are used for uSDHC
        For "3.3 V/1.8 V" FAST pads:
            000b: Fmax=208 MHz (at 1.8V), 166 MHz (at 3.3V)
            100b: Fmax=166 MHz (at 1.8V), 150 MHz (at 3.3V)
            101b: Fmax=150 MHz (at 1.8V), 133 MHz (at 3.3V)
            110b: Fmax=133 MHz (at 1.8V), 100 MHz (at 3.3V)
            111b, Fmax= 83 MHz (at 1.8V),  63 MHz (at 3.3V)
    */
    const uint32 SREValue = 4U;

    /* PC_14 - SD_CLK */
    IP_SIUL2_0->MSCR[46U] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_SRE(SREValue) | SIUL2_MSCR_SSS(1U);

    /* PC_15 - SD_CMD */
    IP_SIUL2_0->MSCR[47U] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_PUE(1U) | SIUL2_MSCR_PUS(1U) | SIUL2_MSCR_SRE(SREValue) | SIUL2_MSCR_SSS(1U);
    IP_SIUL2_0->IMCR[515U - 512U] = SIUL2_IMCR_SSS(2U);

    /* PD_00 - SD_DATA_0 */
    IP_SIUL2_0->MSCR[48U] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_PUE(1U) | SIUL2_MSCR_PUS(1U) | SIUL2_MSCR_SRE(SREValue) | SIUL2_MSCR_SSS(1U);
    IP_SIUL2_0->IMCR[516U - 512U] = SIUL2_IMCR_SSS(2U);
    /* PD_01 - SD_DATA_1 */
    IP_SIUL2_0->MSCR[49U] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_PUE(1U) | SIUL2_MSCR_PUS(1U) | SIUL2_MSCR_SRE(SREValue) | SIUL2_MSCR_SSS(1U);
    IP_SIUL2_0->IMCR[517U - 512U] = SIUL2_IMCR_SSS(2U);
    /* PD_02 - SD_DATA_2 */
    IP_SIUL2_0->MSCR[50U] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_PUE(1U) | SIUL2_MSCR_PUS(1U) | SIUL2_MSCR_SRE(SREValue) | SIUL2_MSCR_SSS(1U);
    IP_SIUL2_0->IMCR[520U - 512U] = SIUL2_IMCR_SSS(2U);
    /* PD_03 - SD_DATA_3 */
    IP_SIUL2_0->MSCR[51U] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_PUE(1U) | SIUL2_MSCR_PUS(1U) | SIUL2_MSCR_SRE(SREValue) | SIUL2_MSCR_SSS(1U);
    IP_SIUL2_0->IMCR[521U - 512U] = SIUL2_IMCR_SSS(2U);

    /* PD_08 - SD Card Reset */
    IP_SIUL2_0->MSCR[56U] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_SRE(SREValue) | SIUL2_MSCR_SSS(1U);;

    /* PD_09 - SD IO Power Voltage Selection */
    IP_SIUL2_0->MSCR[57U] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_SRE(SREValue) | SIUL2_MSCR_SSS(1U);
}

/* Implement a simple assert macro */
void ExampleAssert(boolean Condition)
{
    if (!Condition)
    {
        for (;;)
        {
            /* Loop forever */
        }
    }
}

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Main function of the example
* @details      Initializez the used drivers
*/
int main(void)
{
    uint32 Count;
    Usdhc_Ip_StateType ControllerState;
    Sd_Emmc_Ip_StatusType SdStatus;
    Usdhc_Ip_StatusType ControllerStatus;

    /* Initialize clock module */
    Clock_Ip_InitClock(&Mcu_aClockConfigPB[0]);
    while ( CLOCK_IP_PLL_LOCKED != Clock_Ip_GetPllStatus() )
    {
        /* Busy wait until the System PLL is locked */
    }
    /* Distribute the PLL across the clock tree */
    Clock_Ip_DistributePll();

    /* Enable uSDHC clock in IP_MC_ME */
    Power_Ip_SetMode(&Power_Ip_aModeConfigPB[0]);

    /* Enable Usdhc interrupts */
    Init_INTC();
    Enable_Irq();

    /* Initialize uSDHC controller pins */
    PinInit();

    /* Initialize Tx and Rx buffer */
    BufferInit();

    /* DeInit if controller is already initialized */
    (void)uSDHC_Ip_Deinit(0U);
    /* Init controller */
    ControllerStatus = uSDHC_Ip_Init(&ControllerState, &UsdhcControllerCfg_0, 0U);
    ExampleAssert(STATUS_USDHC_IP_SUCCESS == ControllerStatus);
    /* Init card */
    SdStatus = Sd_Emmc_Ip_Init(&EepSdCfg_0);
    ExampleAssert(SD_IP_STATUS_SUCCESS == SdStatus);

    /* Test Erase/Write/Read syn mode: EEP_BLOCK_COUNT from EEP_BLOCK_START */

    /* Erase block with syn mode */
    SdStatus = Sd_Emmc_Ip_EraseBlocks(&EepSdCfg_0, EEP_BLOCK_START, EEP_BLOCK_COUNT, (boolean)FALSE);
    ExampleAssert(SD_IP_STATUS_SUCCESS == SdStatus);
    /* Read block */
    SdStatus = Sd_Emmc_Ip_ReadBlocks(&EepSdCfg_0, RxBuffer, EEP_BLOCK_START, EEP_BLOCK_COUNT);
    ExampleAssert(SD_IP_STATUS_SUCCESS == SdStatus);
    /* Blank check */
    for (Count = 0; Count < EEP_TEST_SIZE; Count++)
    {
        ExampleAssert(0U == RxBuffer[Count]);
    }

    /* Write block */
    SdStatus = Sd_Emmc_Ip_WriteBlocks(&EepSdCfg_0, TxBuffer, EEP_BLOCK_START, EEP_BLOCK_COUNT, (boolean)FALSE);
    ExampleAssert(SD_IP_STATUS_SUCCESS == SdStatus);
    /* Read block */
    SdStatus = Sd_Emmc_Ip_ReadBlocks(&EepSdCfg_0, RxBuffer, EEP_BLOCK_START, EEP_BLOCK_COUNT);
    ExampleAssert(SD_IP_STATUS_SUCCESS == SdStatus);
    /* Verify received data */
    for (Count = 0; Count < EEP_TEST_SIZE; Count++)
    {
        ExampleAssert(TxBuffer[Count] == RxBuffer[Count]);
    }

    Exit_Example(TRUE);
    return (0U);
}


#ifdef __cplusplus
}
#endif

/** @} */

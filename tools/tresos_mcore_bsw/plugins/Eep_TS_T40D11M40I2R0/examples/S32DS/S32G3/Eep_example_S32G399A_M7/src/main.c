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
#include "S32G399A_SIUL2.h"
#include "S32G399A_NVIC.h"
#include "Mcu.h"
#include "Eep.h"
#include "Eep_IPW.h"
#include "check_example.h"


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define EEP_TEST_ADDRESS            (512U)         /* Start at block 1 */
#define EEP_TEST_SIZE               (512U * 100U)  /* 100 block counts with each block Count = 512 bytes */


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


/*==================================================================================================
*                                       LOCAL FUNCTIONS
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
    /* PD_04 - SD_DATA_4 */
    IP_SIUL2_0->MSCR[52U] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_PUE(1U) | SIUL2_MSCR_PUS(1U) | SIUL2_MSCR_SRE(SREValue) | SIUL2_MSCR_SSS(1U);
    IP_SIUL2_0->IMCR[522U - 512U] = SIUL2_IMCR_SSS(2U);
    /* PD_05 - SD_DATA_5 */
    IP_SIUL2_0->MSCR[53U] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_PUE(1U) | SIUL2_MSCR_PUS(1U) | SIUL2_MSCR_SRE(SREValue) | SIUL2_MSCR_SSS(1U);
    IP_SIUL2_0->IMCR[523U - 512U] = SIUL2_IMCR_SSS(2U);
    /* PD_06 - SD_DATA_6 */
    IP_SIUL2_0->MSCR[54U] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_PUE(1U) | SIUL2_MSCR_PUS(1U) | SIUL2_MSCR_SRE(SREValue) | SIUL2_MSCR_SSS(1U);
    IP_SIUL2_0->IMCR[519U - 512U] = SIUL2_IMCR_SSS(2U);
    /* PD_07 - SD_DATA_7 */
    IP_SIUL2_0->MSCR[55U] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_PUE(1U) | SIUL2_MSCR_PUS(1U) | SIUL2_MSCR_SRE(SREValue) | SIUL2_MSCR_SSS(1U);
    IP_SIUL2_0->IMCR[518U - 512U] = SIUL2_IMCR_SSS(2U);

    /* PD_08 - SD Card Reset */
    IP_SIUL2_0->MSCR[56U] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_SRE(SREValue) | SIUL2_MSCR_SSS(1U);;

    /* PD_09 - SD IO Power Voltage Selection */
    IP_SIUL2_0->MSCR[57U] = SIUL2_MSCR_OBE(1U) | SIUL2_MSCR_SRE(SREValue) | SIUL2_MSCR_SSS(1U);

    /* PD_10 - SD Data Strobe Input */
    IP_SIUL2_0->MSCR[58U] = SIUL2_MSCR_IBE(1U) | SIUL2_MSCR_SRE(SREValue) | SIUL2_MSCR_SSS(2U);
    IP_SIUL2_0->IMCR[524U - 512U] = SIUL2_IMCR_SSS(2U);
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
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Main function of the example
* @details      Initializez the used drivers
*/
int main(void)
{
    uint16 Count = 0;
    Std_ReturnType Status;

    /* Initialize clock module */
    #if (MCU_PRECOMPILE_SUPPORT == STD_ON)
    Mcu_Init(NULL_PTR);
    #elif (MCU_PRECOMPILE_SUPPORT == STD_OFF)
    Mcu_Init(&Mcu_Config_VS_0);
    #endif

    /* Initialize the clock tree and apply PLL as system clock */
    Mcu_InitClock(McuClockSettingConfig_0);

    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() )
    {
        /* Busy wait until the System PLL is locked */
    }
    /* Distribute the PLL across the clock tree */
    Mcu_DistributePllClock();

    /* Enable uSDHC clock in IP_MC_ME */
    Mcu_SetMode(McuModeSettingConf_0);

    /* Enable Usdhc interrupts */
    Init_INTC();
    Enable_Irq();

    /* Initialize uSDHC controller pins */
    PinInit();

    /* Initialize Tx and Rx buffer */
    BufferInit();

    /* Init Eep driver */
    Eep_Init(NULL_PTR);
    ExampleAssert(MEMIF_IDLE == Eep_GetStatus());


    /* Erase memory */
    Status = Eep_Erase(EEP_TEST_ADDRESS, EEP_TEST_SIZE);
    ExampleAssert(E_OK == Status);
    /* Perform the job */
    while (MEMIF_IDLE != Eep_GetStatus())
    {
        Eep_MainFunction();
    }
    /* Check job result */
    ExampleAssert(MEMIF_JOB_OK == Eep_GetJobResult());


    /* Write one or more complete eeprom pages to the eeprom device */
    Status = Eep_Write(EEP_TEST_ADDRESS, TxBuffer, EEP_TEST_SIZE);
    ExampleAssert(E_OK == Status);
    /* Perform the job */
    while (MEMIF_IDLE != Eep_GetStatus())
    {
        Eep_MainFunction();
    }
    /* Check job result */
    ExampleAssert(MEMIF_JOB_OK == Eep_GetJobResult());


    /* Compare eeprom memory area with an application data buffer */
    Status = Eep_Compare(EEP_TEST_ADDRESS, TxBuffer, EEP_TEST_SIZE);
    ExampleAssert(E_OK == Status);
    /* Perform the job */
    while (MEMIF_IDLE != Eep_GetStatus())
    {
        Eep_MainFunction();
    }
    /* Check job result */
    ExampleAssert(MEMIF_JOB_OK == Eep_GetJobResult());


    /* Read data from eeprom memory */
    Status = Eep_Read(EEP_TEST_ADDRESS, RxBuffer, EEP_TEST_SIZE);
    ExampleAssert(E_OK == Status);
    /* Perform the job */
    while (MEMIF_IDLE != Eep_GetStatus())
    {
        Eep_MainFunction();
    }
    /* Check job result */
    ExampleAssert(MEMIF_JOB_OK == Eep_GetJobResult());

    /* Check received data */
    for (Count = 0; Count < EEP_TEST_SIZE; Count++)
    {
        ExampleAssert(RxBuffer[Count] == TxBuffer[Count]);
    }

    /* If we get here it means the test has passed */
    Exit_Example(TRUE);
    return (0U);
}


#ifdef __cplusplus
}
#endif

/** @} */

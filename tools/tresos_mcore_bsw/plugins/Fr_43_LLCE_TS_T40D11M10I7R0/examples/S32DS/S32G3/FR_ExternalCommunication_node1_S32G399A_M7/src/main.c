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
#include "Mcu.h"
#include "Port.h"
#include "Platform.h"
#include "OsIf.h"
#include "Fr_43_LLCE.h"
#include "Flexray_43_LLCE_Ip.h"
#include "check_example.h"
#include "OsIf_Internal.h"
#include "IntCtrl_Ip.h"
#include "Llce_RegAccess.h"
#include "Llce_InterfaceCore2Core.h"
#include "StandardTypes.h"
#include "Llce_InterfaceFwMgr.h"
#include "Llce_Firmware_Load.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define NVIC_HOST_IRQ_OFFSET    170

#define LLCE_FR_GIFER   ((uint32)(IP_FR_LLCE_0_BASE + 0x16U))	  
#define LLCE_FR_PIFR0	((uint32)(IP_FR_LLCE_0_BASE + 0x18U))
#define LLCE_FR_PIFR1	((uint32)(IP_FR_LLCE_0_BASE + 0x1AU))
#define LLCE_FR_PIER0	((uint32)(IP_FR_LLCE_0_BASE + 0x1CU))
#define LLCE_FR_CHIERFR	((uint32)(IP_FR_LLCE_0_BASE + 0x20U))
#define LLCE_FR_TICCR   ((uint32)(IP_FR_LLCE_0_BASE + 0x5AU))
#define LLCE_FR_TI1CYSR ((uint32)(IP_FR_LLCE_0_BASE + 0x5CU))
#define LLCE_FR_TI1MTOR ((uint32)(IP_FR_LLCE_0_BASE + 0x5EU))

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
volatile uint8 timer_1_Irq;

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
void Fr_llce_interrupt(uint8 Ctr_index);
void WaitForTime(uint8 Ctr_index, int cycle, int macrotick);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
void WaitForTime(uint8 Ctr_index, int cycle, int macrotick)
{
    /* Stop the timer if running */
	Reg_Bit_Set16(LLCE_FR_TICCR, 0x0004U);
    /* Initialize state variable */
    timer_1_Irq = 0;
    /* Enable absolute timer 1 interrupt (FR_PIER0) */
	Reg_Bit_Set16(LLCE_FR_PIER0, 0x0002U);
    /* Enable protocol interrupts (FR_GIFER) */
	Reg_Bit_Set16(LLCE_FR_GIFER, 0x0040U);
    /* Setup cycle value for timer 1 (FR_TI1CYSR) */
	Reg_Write16(LLCE_FR_TI1CYSR, (uint16)((cycle << 8U) | 0x3fU));
    /* Setup macrotick value for timer 1 (FR_TI1MTOR) */
	Reg_Write16(LLCE_FR_TI1MTOR, (uint16)(macrotick & 0x3fffU));
    /* Configure timer as non-repetitive (FR_TICCR) */
	Reg_Bit_Clear16(LLCE_FR_TICCR, 0x0010);
    /* Start the timer (FR_TICCR) */
	Reg_Bit_Set16(LLCE_FR_TICCR, 0x0002U);
    /* Wait for interrupt occurred */
    /* while((fr_CCRegPtr[Ctr_index][0x19] != cycle)||(fr_CCRegPtr[Ctr_index][0x18] != macrotick)) {} */
    while(timer_1_Irq != 1) {}
    /* Disable absolute timer 1 interrupt (FR_PIER0) */
	Reg_Bit_Clear16(LLCE_FR_PIER0, 0xfff2);
    /* Disable protocol interrups */
	Reg_Bit_Clear16(LLCE_FR_GIFER, 0xff40U);
}

/* FR INTERRUPTS HANDLER */
void Fr_llce_interrupt(uint8 Ctr_index)
{
    /* Check if protocol interrupt was occurred (FR_GIFER) */
    if(Reg_Bit_Get16(LLCE_FR_GIFER, 0x4000U) == 0x4000U)
    {
        /* Check if timer 1 or 2 is expired (FR_PIFR0) */
        timer_1_Irq = (Reg_Bit_Get16(LLCE_FR_PIFR0, 0x0002U) == 0x0002U);
        /* Clear both flags (FR_PIFR0) */
		Reg_Bit_Set16(LLCE_FR_PIFR0, 0x0006U);
    }
    /* Clear all interrupt flags */
	Reg_Bit_Set16(LLCE_FR_PIFR0, 0xffffU);
	Reg_Bit_Set16(LLCE_FR_PIFR1, 0xffffU);
	Reg_Bit_Set16(LLCE_FR_CHIERFR, 0xffffU);
    
    Flexray_Llce_AckFrpeIRQ();
}

ISR(Flexray_Llce_Frpe_IRQHandler)
{
    Fr_llce_interrupt(0);
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief        Transmit and receive the frame between two nodes.
* @details
*/
int main(void)
{
    uint8 count = 50U;
    uint8 cycle = 0U;
    boolean bPass = (boolean)FALSE;
    uint8 TxData[255U];
    Fr_POCStatusType POCStatus;
    Fr_TxLPduStatusType TxStatus1;
    Fr_TxLPduStatusType TxStatus2;
    Fr_SlotAssignmentType Fr_Tx_SlotAssignment;
    Fr_SlotAssignmentType Fr_Tx_CheckStatus;

    /* Initialize the Mcu driver */
    Mcu_Init(NULL_PTR);

    /* Initialize the clock tree and apply PLL as system clock */
    Mcu_InitClock(McuClockSettingConfig_0);

    /* Wait until PLL is locked */
    while (Mcu_GetPllStatus() != MCU_PLL_LOCKED){}

    /* Use PLL clock */
    Mcu_DistributePllClock();

    Mcu_SetMode(McuModeSettingConf_0);

    /* Initialize all pins using the Port driver */
    Port_Init(NULL_PTR);

    /* Initialize the OsIf driver to use timeout */
    OsIf_Init(NULL_PTR);

	Llce_Firmware_Load();
	
	LLCE_HOST2FRPE_ENABLE_INTERRUPT(0U);
    LLCE_HOST2FRPE_ASSERT_INTERRUPT(0U);
	
    /* Initialize the Fr driver */
    Fr_43_LLCE_Init(NULL_PTR);

    Fr_43_LLCE_ControllerInit(FrConf_FrController_FrController_0);
	
	/* IntCtrl_Ip_EnableIrq(NVIC_HOST_IRQ_OFFSET + 3);
	IntCtrl_Ip_InstallHandler(NVIC_HOST_IRQ_OFFSET + 3, Flexray_Llce_Frpe_IRQHandler, NULL_PTR); */
	
	/* Configurations for IRQ routing, priority and enable through Platform plugin. */
    Platform_Init(NULL_PTR);

    Fr_43_LLCE_AllowColdstart(FrConf_FrController_FrController_0);

    Fr_43_LLCE_StartCommunication(FrConf_FrController_FrController_0);

    while (POCStatus.State!=FR_POCSTATE_NORMAL_ACTIVE)
    {
        Fr_43_LLCE_GetPOCStatus(FrConf_FrController_FrController_0, &POCStatus);
    }

    while (bPass == (boolean)FALSE && count-- )
    {
        for (cycle=0U; cycle < 64U; cycle++)
        {
            WaitForTime(FrConf_FrController_FrController_0 , cycle, 0U);

            Fr_43_LLCE_TransmitTxLPdu(FrConf_FrController_FrController_0, 0U , &TxData[0], 20U , &Fr_Tx_SlotAssignment);

            Fr_43_LLCE_CheckTxLPduStatus(FrConf_FrController_FrController_0, 0U, &TxStatus1, &Fr_Tx_CheckStatus);

            WaitForTime(FrConf_FrController_FrController_0, cycle, 4444U);

            Fr_43_LLCE_CheckTxLPduStatus(FrConf_FrController_FrController_0, 0U, &TxStatus2, &Fr_Tx_CheckStatus);

            if(TxStatus1 == FR_NOT_TRANSMITTED && TxStatus2 == FR_TRANSMITTED)
            {
                bPass = (boolean)TRUE;
                    break;
            }
        }

    }

    WaitForTime(FrConf_FrController_FrController_0, 63, 0);
    Fr_43_LLCE_AbortCommunication(FrConf_FrController_FrController_0);

    Exit_Example(bPass);

    return 0U;
}

#ifdef __cplusplus
}
#endif

/** @} */

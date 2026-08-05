/*
*   Copyright 2023 NXP Semiconductors
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

#include "Mcal.h"
#include "Clock_Ip.h"
#include "Siul2_Port_Ip.h"
#include "IntCtrl_Ip.h"
#include "Flexray_Ip.h"
#include "OsIf.h"
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


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
Flexray_Ip_PocStateType pocState;
Flexray_Ip_FrameHeaderType headerOut;
boolean bPass = FALSE;
uint8 transmitData[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08 , 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};
uint8 receiveData[16] = {0};
Flexray_Ip_StatusType state;

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief        Transmit and receive the frame between two nodes.
* @details
*/

int main(void)
{
    /* Initialize the clock */
    Clock_Ip_Init(&Mcu_aClockConfigPB_BOARD_InitPeripherals[0]);

    /* Initialize all pins using the Port driver */
    Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

    /* Initialize the OsIf driver to use timeout */
    OsIf_Init(NULL_PTR);

    /* Initialize Flexray */
    Flexray_Ip_Init(INST_FLEXRAY_0, &Fr_MC0_Ctrl0_UserCfg_PB, &Fr_MC0_Ctrl0_StateAlloc_PB);

    pocState = Flexray_Ip_GetCurrentState(INST_FLEXRAY_0);
    while (FLEXRAY_STATE_READY != pocState)
    {
        pocState = Flexray_Ip_GetCurrentState(INST_FLEXRAY_0);
    }

    /* Send protocol control run command */
    Flexray_Ip_SendCHICommand(INST_FLEXRAY_0, FLEXRAY_CHI_CMD_RUN);

    /* Wait for normal active state */
    pocState = Flexray_Ip_GetCurrentState(INST_FLEXRAY_0);
    while (FLEXRAY_STATE_NORMAL_ACTIVE != pocState)
    {
        pocState = Flexray_Ip_GetCurrentState(INST_FLEXRAY_0);
    }

    /* Send data to the other board */
    Flexray_Ip_Send(INST_FLEXRAY_0, 0, transmitData, 16);
    /* Loop untill the received data is complete */
    while (bPass == FALSE)
    {
    	Flexray_Ip_ReceiveInd(INST_FLEXRAY_0, 1, &headerOut, receiveData, 16);
        while(( state == FLEXRAY_STATUS_BUSY))
        {
        	state = Flexray_Ip_GetTransferStatus(INST_FLEXRAY_0, 1u);
        	if(state == FLEXRAY_STATUS_ERROR)
        	{
        		continue;
        	}
        }
    	for (int u8idx = 1; u8idx < 15; u8idx ++)
    	{
    	    if (transmitData[u8idx] == receiveData[u8idx])
    	    {
    	        	bPass = TRUE;
    	    }
    	}
    }

    if((Flexray_Ip_GetTransferStatus(INST_FLEXRAY_0, 1u) == FLEXRAY_STATUS_SUCCESS))
    {
        bPass = TRUE;
    }

    /* De-initialize Flexray */
    Flexray_Ip_Deinit(INST_FLEXRAY_0);
    Exit_Example(bPass);
}

#ifdef __cplusplus
}
#endif

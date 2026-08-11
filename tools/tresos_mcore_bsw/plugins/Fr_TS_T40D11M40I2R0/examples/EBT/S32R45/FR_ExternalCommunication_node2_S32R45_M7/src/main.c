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
#include "Mcu.h"
#include "Port.h"
#include "Platform.h"
#include "OsIf.h"
#include "Fr.h"
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

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
void WaitForTime(int ctrIndex, int AbsTimer_Idx, int cycle, int macrotick)
{
    boolean IRQStatusPtr = FALSE;
    uint8 InterrupStatus=0U;
    Fr_CancelAbsoluteTimer(ctrIndex, AbsTimer_Idx);
    Fr_SetAbsoluteTimer(ctrIndex, AbsTimer_Idx,cycle,macrotick);

    while (InterrupStatus == 0U)
    {
        Fr_GetAbsoluteTimerIRQStatus(ctrIndex, AbsTimer_Idx,&IRQStatusPtr);
        if (IRQStatusPtr==(boolean)TRUE)
        {
            InterrupStatus=1U;
            Fr_AckAbsoluteTimerIRQ(ctrIndex, AbsTimer_Idx);        
        }
    }
    return;
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
    boolean bPass = FALSE;
    uint8 RxData[255U];
    uint8 RxLength;
    Fr_POCStatusType POCStatus;
    Fr_RxLPduStatusType RxStatus;
    Fr_SlotAssignmentType Fr_Rx_SlotAssignment;

#if (MCU_PRECOMPILE_SUPPORT == STD_ON)
    Mcu_Init(NULL_PTR);
#elif (MCU_PRECOMPILE_SUPPORT == STD_OFF)
    Mcu_Init(&Mcu_Config_BOARD_InitPeripherals);
#endif /* (MCU_PRECOMPILE_SUPPORT == STD_ON) */

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

    /* Initialize the Fr driver */
    Fr_Init(NULL_PTR);

    Fr_ControllerInit(FrConf_FrController_FrController_0);

    Fr_AllowColdstart(FrConf_FrController_FrController_0);
    
    Fr_StartCommunication(FrConf_FrController_FrController_0);

    while (POCStatus.State!=FR_POCSTATE_NORMAL_ACTIVE)
    {
        Fr_GetPOCStatus(FrConf_FrController_FrController_0, &POCStatus);
    }
    
    while (bPass == FALSE && count-- )
    {
        for (cycle=0U; cycle < 64U; cycle++)
        {
            WaitForTime(FrConf_FrController_FrController_0, FrConf_FrAbsoluteTimer_FrAbsoluteTimer_0, cycle, 4444U);
            
            Fr_ReceiveRxLPdu(FrConf_FrController_FrController_0, 0U, &RxData[0], &RxStatus, &RxLength, &Fr_Rx_SlotAssignment);
            
            if(RxStatus == FR_RECEIVED )
            {
                bPass = TRUE;
                    break;
            }
        }
        
        Fr_GetPOCStatus(FrConf_FrController_FrController_0, &POCStatus);
    }
    
    WaitForTime(FrConf_FrController_FrController_0, FrConf_FrAbsoluteTimer_FrAbsoluteTimer_0, 63, 0);

    Fr_AbortCommunication(FrConf_FrController_FrController_0);
    
    Exit_Example(bPass);
    
    return 0U;
}


#ifdef __cplusplus
}
#endif

/** @} */

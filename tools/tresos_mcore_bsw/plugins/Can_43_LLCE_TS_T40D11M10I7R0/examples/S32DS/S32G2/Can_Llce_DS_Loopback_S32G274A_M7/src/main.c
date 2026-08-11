/*==================================================================================================
*
* Copyright 2018-2023 NXP  
*
* NXP Confidential. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms.
* By expressly accepting such terms or by downloading, installing, activating and/or otherwise using
* the software, you are agreeing that you have read, and that you agree to comply with and are bound
* by, such license terms.  If you do not agree to be bound by the applicable license terms, then you
* may not retain, install, activate or otherwise use the software.
==================================================================================================*/

#include "stubs.h"
#include "Can_43_LLCE.h"
#include "PlatformInit.h"
#include "Llce_Firmware_Load.h"
#include "can_common.h"
#include "Core_Heartbeat.h"

#define CHANNELS_TO_TEST    16 /* RDB_V2 and EVB */

#define FRAMES_TO_SEND      100

void Can_Driver_Sample_Test(void)
{
    Can_ErrorStateType ErrorState;
    Std_ReturnType can_retval = E_NOT_OK;
    static uint8 can_fd_data[CAN_FD_FRAME_LEN];
    Can_PduType CanMessage[CHANNELS_TO_TEST];
    uint16 u16FrameCount[CHANNELS_TO_TEST];
    uint8 u8StopFlag = 0U;

    uint16 u16MbGlobalIndex = 0U;
    uint8 u8CtrlIdx = 0U;

    const Can_43_LLCE_ConfigType *Can_Cfg1 = &Can_43_LLCE_Config_VS_0;

    Can_43_LLCE_Init(Can_Cfg1);

    /* Reset global flags and counters. */
    Can_CallBackSetUp();

    /*Initialize transmission data buffer with a Can Fd frame.*/
    for (u16MbGlobalIndex = 0; u16MbGlobalIndex < CAN_FD_FRAME_LEN; u16MbGlobalIndex++)
    {
        can_fd_data[u16MbGlobalIndex] = u16MbGlobalIndex;
    }

     /* Set-up CAN frame data with different CAN IDs */
    for (u8CtrlIdx = 0; u8CtrlIdx < CHANNELS_TO_TEST; u8CtrlIdx++)
    {
        u16FrameCount[u8CtrlIdx] = 0;

        CanMessage[u8CtrlIdx].length = CAN_FD_FRAME_LEN;
        CanMessage[u8CtrlIdx].swPduHandle = u8CtrlIdx;
        CanMessage[u8CtrlIdx].sdu = can_fd_data;
        CanMessage[u8CtrlIdx].id = u8CtrlIdx;
        CanMessage[u8CtrlIdx].id |=CAN_LPDU_FD_U32; /*This is a CAN FD frame*/

        Can_Tx_No[u8CtrlIdx] = 0;
    }

    /* Start controllers */
    for (u8CtrlIdx = 0; u8CtrlIdx < CHANNELS_TO_TEST; u8CtrlIdx++)
    {
        can_retval = Can_43_LLCE_SetBaudrate(u8CtrlIdx, 1);
        ASSERT(E_OK == can_retval);
        can_retval = Can_43_LLCE_SetControllerMode(u8CtrlIdx, CAN_CS_STARTED);
        ASSERT(E_OK == can_retval);
        can_retval = Can_43_LLCE_GetControllerErrorState(u8CtrlIdx, &ErrorState);
        ASSERT(E_OK == can_retval);
    }
    
    (void)can_retval;

    while (!u8StopFlag)
    {
        u8StopFlag = 1;
        for (u8CtrlIdx = 0; u8CtrlIdx < CHANNELS_TO_TEST; u8CtrlIdx++)
        {   
            if ((u16FrameCount[u8CtrlIdx] - Can_Tx_No[u8CtrlIdx] < 16) && (u16FrameCount[u8CtrlIdx] < FRAMES_TO_SEND))
            {
                u16FrameCount[u8CtrlIdx]++;
                
                switch (u8CtrlIdx) {
                        case 0: can_retval = Can_43_LLCE_Write( CanHO_Config1_TX0, &CanMessage[u8CtrlIdx]);
                                ASSERT(E_OK == can_retval);
                                break;
                        case 1: can_retval = Can_43_LLCE_Write( CanHO_Config1_TX1, &CanMessage[u8CtrlIdx]);
                                ASSERT(E_OK == can_retval);
                                break;
                        case 2: can_retval = Can_43_LLCE_Write( CanHO_Config1_TX2, &CanMessage[u8CtrlIdx]);
                                ASSERT(E_OK == can_retval);
                                break;
                        case 3: can_retval = Can_43_LLCE_Write( CanHO_Config1_TX3, &CanMessage[u8CtrlIdx]);
                                ASSERT(E_OK == can_retval);
                                break;
                        case 4: can_retval = Can_43_LLCE_Write( CanHO_Config1_TX4, &CanMessage[u8CtrlIdx]);
                                ASSERT(E_OK == can_retval);
                                break;
                        case 5: can_retval = Can_43_LLCE_Write( CanHO_Config1_TX5, &CanMessage[u8CtrlIdx]);
                                ASSERT(E_OK == can_retval);
                                break;
                        case 6: can_retval = Can_43_LLCE_Write( CanHO_Config1_TX6, &CanMessage[u8CtrlIdx]);
                                ASSERT(E_OK == can_retval);
                                break;
                        case 7: can_retval = Can_43_LLCE_Write( CanHO_Config1_TX7, &CanMessage[u8CtrlIdx]);
                                ASSERT(E_OK == can_retval);
                                break;
                        case 8: can_retval = Can_43_LLCE_Write( CanHO_Config1_TX8, &CanMessage[u8CtrlIdx]);
                                ASSERT(E_OK == can_retval);
                                break;
                        case 9: can_retval = Can_43_LLCE_Write( CanHO_Config1_TX9, &CanMessage[u8CtrlIdx]);
                                ASSERT(E_OK == can_retval);
                                break;
                        case 10: can_retval = Can_43_LLCE_Write( CanHO_Config1_TX10, &CanMessage[u8CtrlIdx]);
                                ASSERT(E_OK == can_retval);
                                break;
                        case 11: can_retval = Can_43_LLCE_Write( CanHO_Config1_TX11, &CanMessage[u8CtrlIdx]);
                                ASSERT(E_OK == can_retval);
                                break;
                        case 12: can_retval = Can_43_LLCE_Write( CanHO_Config1_TX12, &CanMessage[u8CtrlIdx]);
                                ASSERT(E_OK == can_retval);
                                break;
                        case 13: can_retval = Can_43_LLCE_Write( CanHO_Config1_TX13, &CanMessage[u8CtrlIdx]);
                                ASSERT(E_OK == can_retval);
                                break;
                        case 14: can_retval = Can_43_LLCE_Write( CanHO_Config1_TX14, &CanMessage[u8CtrlIdx]);
                                ASSERT(E_OK == can_retval);
                                break;
                        case 15: can_retval = Can_43_LLCE_Write( CanHO_Config1_TX15, &CanMessage[u8CtrlIdx]);
                                ASSERT(E_OK == can_retval);
                                break;
                        default:
                                break;
                }
            }

            Core_Heartbeat_Check();
        }

        for (u8CtrlIdx = 0; u8CtrlIdx < CHANNELS_TO_TEST; u8CtrlIdx++)
        {   
            u8StopFlag &= (Can_Tx_No[u8CtrlIdx] == FRAMES_TO_SEND);
        }
   
    }

    while ((Can_RxIndication < FRAMES_TO_SEND*CHANNELS_TO_TEST))
    {
    }

    /* Check eventual errors configured to be reported in polling. This will trigger CanErrorNotification. */
    Can_43_LLCE_MainFunction_ErrorNotification();

    /* Stop controllers */
    for (u8CtrlIdx = 0; u8CtrlIdx < CHANNELS_TO_TEST; u8CtrlIdx++)
    {
        can_retval = Can_43_LLCE_SetControllerMode(u8CtrlIdx, CAN_CS_STOPPED);
        ASSERT(E_OK == can_retval);
    }

    ASSERT(CHANNELS_TO_TEST * FRAMES_TO_SEND == Can_RxIndication);
    ASSERT(CHANNELS_TO_TEST * FRAMES_TO_SEND == Can_TxConfirmation);

    Can_43_LLCE_DeInit();
}

int main(void)
{
    PlatformInit();
    
    Llce_Firmware_Load();
    Can_Driver_Sample_Test();

    while (1);
}



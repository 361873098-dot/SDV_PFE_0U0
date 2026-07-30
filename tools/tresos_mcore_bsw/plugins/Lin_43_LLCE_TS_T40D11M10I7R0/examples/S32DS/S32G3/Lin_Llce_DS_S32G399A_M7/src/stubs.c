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


uint8 wakeUpConfirm;
volatile uint8 TxConfirmation;
volatile uint8 RxConfirmation;
volatile uint8 RxBuffer[8u];
volatile uint8 HeaderIndication;
volatile Lin_SlaveErrorType ErrorType;
volatile uint8 SlaveRuleNr;
volatile uint8 fail;

uint8 T_Lin_Data00[1] = {0xAA};
uint8 T_Lin_Data01[3] = {0x11, 0x12, 0x13};
uint8 T_Lin_Data02[4] = {0x12, 0x13, 0x14, 0x15};
uint8 T_Lin_Data03[5] = {0x10, 0x20, 0x30, 0x40, 0x50};
uint8 T_Lin_Data04[6] = {0x10, 0x20, 0x30, 0x40, 0x50, 0x60};
uint8 T_Lin_Data05[8] = {0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80};


Lin_PduType T_Lin_Table_Schedule[SCHEDULE_RULES_NR] =
{
    {50, LIN_ENHANCED_CS, LIN_FRAMERESPONSE_RX, 1u, T_Lin_Data00},
    {10, LIN_ENHANCED_CS, LIN_FRAMERESPONSE_TX, 3u, T_Lin_Data01},
    {11, LIN_ENHANCED_CS, LIN_FRAMERESPONSE_TX, 4u, T_Lin_Data02},
    {51, LIN_ENHANCED_CS, LIN_FRAMERESPONSE_TX, 5u, T_Lin_Data03},
    {12, LIN_ENHANCED_CS, LIN_FRAMERESPONSE_TX, 6u, T_Lin_Data04},
    {13, LIN_ENHANCED_CS, LIN_FRAMERESPONSE_RX, 8u, T_Lin_Data05},
    {14, LIN_ENHANCED_CS, LIN_FRAMERESPONSE_IGNORE, 8u, T_Lin_Data05}
};


Std_ReturnType LinIf_HeaderIndication(NetworkHandleType Channel, Lin_PduType* PduPtr)
{
    uint8 u8Rule = 0;
    uint8 u8Match_flag = 0;
    uint8 rawPid;

    rawPid = PduPtr->Pid & RAW_PID_MASK; /* check parity bits and discard them */

    (void)Channel; /* We have configured a single slave node, so we'll search in a single schedule table */
	
	HeaderIndication++;

    for(u8Rule = 0; u8Rule < SCHEDULE_RULES_NR; u8Rule++)
    {
        if (T_Lin_Table_Schedule[u8Rule].Pid == rawPid)
        {
            /* Consult the Schedule Table and Publish(Drc=TX) a response, Subscribe(Drc=RX) to the frame, or Ignore the frame */
            PduPtr->Drc = T_Lin_Table_Schedule[u8Rule].Drc;
            PduPtr->Cs = T_Lin_Table_Schedule[u8Rule].Cs;
            PduPtr->Dl = T_Lin_Table_Schedule[u8Rule].Dl;
            PduPtr->SduPtr = T_Lin_Table_Schedule[u8Rule].SduPtr;
            
            /* Save the slave rule number in the schedule table in order to further check the response got by the master node. */
            SlaveRuleNr = u8Rule;
            u8Match_flag = 1;
            break;
        }
   
    }

    if (u8Match_flag == 0)
    {
        return E_NOT_OK; /* This frame Pid is unexpected according to the Schedule table */
    }

    return E_OK;
}
void LinIf_WakeupConfirmation(EcuM_WakeupSourceType WakeupSource)
{
    (void)WakeupSource;
    wakeUpConfirm++;
}

Std_ReturnType LinIf_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
    (void)WakeupSource;
    return E_OK;
}


void LinIf_RxIndication(NetworkHandleType Channel, uint8* Lin_SduPtr)
{
    (void)Channel;
    RxConfirmation++;

    for (uint8 i = 0; i < 8; i++)
    {
        RxBuffer[i] = Lin_SduPtr[i];
    }
    
}

void LinIf_TxConfirmation(NetworkHandleType Channel)
{
    (void)Channel;
    TxConfirmation++;
}

void LinIf_LinErrorIndication(NetworkHandleType Channel, Lin_SlaveErrorType ErrorStatus)
{
    (void)Channel;
     ErrorType = ErrorStatus;
}

void ResetCounters(void)
{
    TxConfirmation = 0;
    wakeUpConfirm=0;
    RxConfirmation=0;
    HeaderIndication=0;
    SlaveRuleNr = 0;

    for (uint8 i = 0; i < 8; i++)
    {
        RxBuffer[i] = 0;
    }
}


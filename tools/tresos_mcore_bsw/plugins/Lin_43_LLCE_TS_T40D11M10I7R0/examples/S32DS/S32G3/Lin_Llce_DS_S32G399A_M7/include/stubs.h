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

#ifndef STUBS_H
#define STUBS_H

#include "Lin_43_LLCE.h"
#include "Platform_Types.h"

#define RAW_PID_MASK (uint8)0x3F /* Pid is 6bits length */
#define SCHEDULE_RULES_NR   7 /* Number of frames for test */

/* Stub functions */
Std_ReturnType LinIf_HeaderIndication(NetworkHandleType Channel, Lin_PduType* PduPtr);
void LinIf_WakeupConfirmation(EcuM_WakeupSourceType WakeupSource);
Std_ReturnType LinIf_CheckWakeup(EcuM_WakeupSourceType WakeupSource);
void LinIf_RxIndication(NetworkHandleType Channel, uint8* Lin_SduPtr);
void LinIf_TxConfirmation(NetworkHandleType Channel);
void LinIf_LinErrorIndication(NetworkHandleType Channel, Lin_SlaveErrorType ErrorStatus);
void ResetCounters(void);

extern uint8 wakeUpConfirm;
extern volatile uint8 TxConfirmation;
extern volatile uint8 RxConfirmation;
extern volatile uint8 HeaderIndication;
extern volatile Lin_SlaveErrorType ErrorType;
extern volatile uint8 SlaveRuleNr;
extern volatile uint8 fail;

extern Lin_PduType T_Lin_Table_Schedule[SCHEDULE_RULES_NR];
#endif /* STUBS_H */

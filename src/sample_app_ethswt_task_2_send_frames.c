/*
 *  (c) Copyright 2006-2016 Freescale Semiconductor, Inc.
 *  Copyright 2017, 2019-2023 NXP
 *
 *  NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only
 *  be used strictly in accordance with the applicable license terms. By
 *  expressly accepting such terms or by downloading, installing, activating
 *  and/or otherwise using the software, you are agreeing that you have read,
 *  and that you agree to comply with and are bound by, such license terms. If
 *  you do not agree to be bound by the applicable license terms, then you may
 *  not retain, install, activate or otherwise use the software.
 *
 *  This file contains sample code only. It is not part of the production code deliverables.
 */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "sample_app_ethswt_task_2_send_frames.h"
#include "sample_app_ethswt_eth.h"

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

void SimpleDelay(uint32 timeout);

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

void SimpleDelay(uint32 timeout)
{
    while (timeout-- > 0)
    {
        ASM_KEYWORD("nop");
    }
}

/**
@brief      SampleAppTask2 - Task2 function
@details    This function is called periodically by the OS or by the main() function.

@return     Returns the value of success
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
Std_ReturnType SampleAppTask2(void)
{
    Std_ReturnType tempRet     = E_OK;
    uint8 CtrlIndex;
    frame_type_t frmType = FRAME_TYPE_ARP;

#ifdef LOOPBACK_TEST
    /* Stop after sending 100 frames */
    static uint8 frameCount = 100U;
    if (frameCount == 0U)
    {
        return E_OK;
    }
    frameCount--;
#endif

    /* Send a test frame from all the PFE controllers */
    for (CtrlIndex = 0U; CtrlIndex < NUM_TX_CONTROLLER_USED; CtrlIndex++)
    {
#if defined(FCI_RTABLE_TEST)
        if (CtrlIndex == (NUM_TX_CONTROLLER_USED - 1U))
        {
            frmType = FRAME_TYPE_IPV;
        }
#endif /* defined(FCI_RTABLE_TEST) */
        tempRet |= Tst_Pfe_SendDummyFrame(CtrlIndex, broadcastMac, frmType);
        if (STD_OFF == ETH_43_PFE_CFG_ENABLERXINTERRUPT(CtrlIndex))
        {
            Eth_RxStatusType RxStatus;
            Eth_43_PFE_Receive(CtrlIndex, 0U, &RxStatus);
        }
        if (STD_OFF == ETH_43_PFE_CFG_ENABLETXINTERRUPT(CtrlIndex))
        {
            Eth_43_PFE_TxConfirmation(CtrlIndex);
        }
    }

    return tempRet;
}

/*================================================================================================*/

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#ifdef __cplusplus
}
#endif

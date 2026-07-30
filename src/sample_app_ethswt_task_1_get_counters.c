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
#include "sample_app_ethswt_task_1_get_counters.h"

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


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef USE_SJA1105P_DRIVER
/*================================================================================================*/
/**
@brief      SampleAppTask1 - Task1 function
@details    This function is called periodically by the OS or by the main() function.

@return     Returns the value of success
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
Std_ReturnType SampleAppTask1(void)
{
    Std_ReturnType  tempRet = E_OK;
    uint8           switchIndex = 0U;
    uint8           portIndex = 0U;

    for (switchIndex = 0U; switchIndex < ETHSWT_43_SJA1105P_SWITCHES; switchIndex++)
    {
        for (portIndex = 0U; portIndex < ETHSWT_43_SJA1105P_MAX_SWITCH_PORTS; portIndex++)
        {
            tempRet |= EthSwt_43_SJA1105P_GetRxStats(switchIndex, portIndex, &rxStats_sja1105p[switchIndex][portIndex]);
            tempRet |= EthSwt_43_SJA1105P_GetTxStats(switchIndex, portIndex, &txStats_sja1105p[switchIndex][portIndex]);
        }
    }
    
    return (tempRet);
}
#endif /* USE_SJA1105P_DRIVER */

/*================================================================================================*/

#ifdef __cplusplus
}
#endif

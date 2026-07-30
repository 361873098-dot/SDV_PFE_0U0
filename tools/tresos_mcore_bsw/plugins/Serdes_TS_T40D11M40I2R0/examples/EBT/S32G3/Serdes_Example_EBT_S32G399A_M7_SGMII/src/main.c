/*
*   Copyright 2023 NXP
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
extern "C"{
#endif
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Mcal.h"
#include "S32G399A.h"
#include "Mcu.h"
#include "Platform.h"
#include "Port.h"
#include "Eth.h"
#include "Serdes.h"
#include "check_example.h"
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/* Function-like macros to set and get the status of the example run */
#define App_SetSuccessStatus(value)         (u32NumFailedApiCalls += ((value) ? 0U : 1U))
#define App_GetSuccessStatus()              (0U == u32NumFailedApiCalls)
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

extern void Serdes_MainFunction(void);

int main(void)
{
    static volatile uint32 u32NumFailedApiCalls = 0U; 

    Eth_BufIdxType bufferIndex;
    Eth_RxStatusType Status = ETH_NOT_RECEIVED;
    uint8 *payloadBuffer;
    uint16 payloadLength;
    uint8 gmac_0_macAddr[6U] = {0};

    /* Init GMAC pins */
    Port_Init(NULL_PTR);

    /* Configure MCU */
    Mcu_Init(NULL_PTR);
    Mcu_InitClock(McuClockSettingConfig_0);
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() ){}
    Mcu_DistributePllClock();
    Mcu_SetMode(McuModeSettingConf_0);

    /* Enable GMAC0 PHY MODE */
    IP_SRC->GMAC_0_CTRL_STS = (IP_SRC->GMAC_0_CTRL_STS & ~SRC_GMAC_0_CTRL_STS_PHY_MODE_MASK) | SRC_GMAC_0_CTRL_STS_PHY_MODE(1U);

    /* Initi Serdes in SGMII mode 3 
    Note: You have to reinitialize MCU after Serdes_Init */
    (void) Serdes_Init(NULL_PTR);
    
    while (SERDES_INIT_PENDING == Serdes_GetJobResult())
    {
        Serdes_MainFunction();
    }

    Platform_Init(NULL_PTR);

    /* Reinitialize clocks */
    Mcu_InitClock(McuClockSettingConfig_0);
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() ){}
    Mcu_DistributePllClock();

    /* GMAC interfaces initialization */
/******************************************************************************/
    Eth_Init(NULL_PTR);
    Eth_SetControllerMode(EthConf_EthCtrlConfig_EthCtrlConfig_0, ETH_MODE_ACTIVE);
/******************************************************************************/

    Eth_ProvideTxBuffer(EthConf_EthCtrlConfig_EthCtrlConfig_0, 0U, &bufferIndex, &payloadBuffer, &payloadLength);
    
    Eth_GetPhysAddr(EthConf_EthCtrlConfig_EthCtrlConfig_0, gmac_0_macAddr);
    
    Eth_Transmit(EthConf_EthCtrlConfig_EthCtrlConfig_0, bufferIndex, (Eth_FrameType)46U, TRUE, 46U, gmac_0_macAddr);
    
    Eth_TxConfirmation(EthConf_EthCtrlConfig_EthCtrlConfig_0);
    
    Eth_Receive(EthConf_EthCtrlConfig_EthCtrlConfig_0, 0U, &Status);
    
    App_SetSuccessStatus(ETH_RECEIVED == Status);
    
    /* =============================================================================================================================== */
    /*    Finish application execution, signaling the status                                                                           */ 
    /* =============================================================================================================================== */
    Exit_Example(App_GetSuccessStatus());

    return (0U);

}

#ifdef __cplusplus
}
#endif

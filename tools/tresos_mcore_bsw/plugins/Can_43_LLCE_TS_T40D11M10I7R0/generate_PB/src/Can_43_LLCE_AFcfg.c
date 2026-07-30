/**
*   @file    Can_43_LLCE_AFcfg.c
*   @version 1.0.7
*
*   @brief   AUTOSAR Can_43_LLCE - module interface
*   @details Configuration Structures for PostBuild.
*
*   @addtogroup CAN_LLCE
*   @{
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : LLCE
*   Dependencies         : 
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 1.0.7
*   Build Version        : S32_RTD_1_0_7_D2909_ASR_REL_4_4_REV_0000_20230630
*
*   Copyright 2020-2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/**
* @file           Can_43_LLCE_AFcfg.c
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Llce_InterfaceCanTypes.h"
#include "Mcal.h"
#include "Can_43_LLCE_AFcfg.h"

[!AUTOSPACING!]
[!INDENT "0"!]
[!NOCODE!]
[!INCLUDE "Can_43_LLCE_Macros.m"!][!//
[!ENDNOCODE!]
/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
#include "Can_43_LLCE_MemMap.h"

[!SELECT "as:modconf('Llce_Af')/LlceAfGeneral"!]
[!IF "node:exists(CAN2ETHWithExternalRingBuffer) and (CAN2ETHWithExternalRingBuffer = 'true')"!]

VAR_ALIGN(volatile uint8 Llce_PfeIf_RxRing  [LLCE_PFE_BD_RING_SIZE]     , 16U)
VAR_ALIGN(volatile uint8 Llce_PfeIf_RxWbRing[LLCE_PFE_BD_WB_RING_SIZE]  , 16U)
VAR_ALIGN(volatile uint8 Llce_PfeIf_TxRing  [LLCE_PFE_BD_RING_SIZE]     , 16U)
VAR_ALIGN(volatile uint8 Llce_PfeIf_TxWbRing[LLCE_PFE_BD_WB_RING_SIZE]  , 16U)
VAR_ALIGN(volatile uint8 Llce_PfeIf_Hdr     [LLCE_PFE_TX_HDR_SIZE]      , 16U)

[!ENDIF!]
[!ENDSELECT!]

[!SELECT "as:modconf('Llce_Af')/LlceAfGeneral"!]
    [!VAR "C2E_CNT" = "num:i(count(Can2EthRoutingTable/*))"!]
    [!IF "$C2E_CNT > 0"!]
        /**
        * @brief Can2Eth buffers
        * @details Memory space to be used by the LLCE Can2Eth feature. All buffers must be 16-bit aligned.
        *
        */
        [!VAR "crtIdx" = "0"!]
        [!LOOP "Can2EthRoutingTable/*"!]
            VAR_ALIGN(static uint8 Llce_Can2Eth_Buffer[!"num:i($crtIdx)"!][[!"Can2EthBufferCount"!]][[!"num:i(Can2EthBufferSize + (Can2EthBufferSize mod 2))"!]] , 2U)
            [!VAR "crtIdx" = "$crtIdx+1"!]
        [!ENDLOOP!]
    [!ENDIF!]
[!ENDSELECT!]

[!SELECT "as:modconf('Llce_Af')/LlceAfGeneral"!]
    [!VAR "crtIdx" = "0"!]
    [!LOOP "Can2OtherRoutingTable/*"!]
      [!IF "RoutingType = 'PCIe'"!]
        VAR_ALIGN(static uint8 Llce_Can2Pcie_Buffer[!"num:i($crtIdx)"!][[!"BufferCount"!]][[!"num:i(BufferSize + (BufferSize mod 2))"!]] , 2U)
        [!VAR "crtIdx" = "$crtIdx+1"!]
      [!ENDIF!]
    [!ENDLOOP!]
[!ENDSELECT!]

[!SELECT "as:modconf('Llce_Af')/LlceAfGeneral/Eth2Can"!]
    [!IF "Eth2CanEnable"!]
        /**
        * @brief Eth2Can RX buffers
        * @details Memory space to be used by PFE to store incoming Eth2Can frames. All buffers must be 16-bit aligned.
        */
        VAR_ALIGN( uint8 Llce_Eth2Can_Buffer[LLCE_CAN_ADVANCED_FEATURE_ETH2CAN_BUF_CNT][LLCE_CAN_ADVANCED_FEATURE_ETH2CAN_BUF_SIZE] , 2U)

        Llce_Can_EthEncapsulationFormat Llce_Eth2Can_EnabledFormats[LLCE_CAN_ADVANCED_FEATURE_ETH2CAN_FORMAT_CNT] =
        {
            [!INDENT "4"!]
            [!LOOP "Eth2CanEnabledFormats/*"!]
                LLCE_AF_CAN2[!"."!][!IF "not(node:islast(.))"!], [!ENDIF!][!CR!]
            [!ENDLOOP!]
            [!ENDINDENT!]
        };
    [!ENDIF!]
[!ENDSELECT!]

#define CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
#include "Can_43_LLCE_MemMap.h"
[!ENDINDENT!]

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
#define CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_43_LLCE_MemMap.h"

[!SELECT "as:modconf('Llce_Af')/LlceAfGeneral"!][!//
[!VAR "C2C_CNT" = "num:i(count(Can2CanRoutingTable/*))"!][!//
[!VAR "C2E_CNT" = "num:i(count(Can2EthRoutingTable/*))"!][!//

[!CALL "CountCan2Other"!]
[!IF "num:i($C2E_CNT + $C2PCIE_CNT) > 0"!]
const uint8* pLlce_Can_AfBuffer[LLCE_CAN_ADVANCED_FEATURE_CAN2CAN_CNT + LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT + LLCE_CAN_ADVANCED_FEATURE_CAN2OTHER_CNT] = {
    [!LOOP "Can2CanRoutingTable/*"!][!//
        [!WS "4"!]NULL_PTR,
    [!ENDLOOP!][!//
    [!VAR "Idx" = "0"!][!//
    [!LOOP "Can2EthRoutingTable/*"!][!//
        [!WS "4"!]&Llce_Can2Eth_Buffer[!"num:i($Idx)"!][0][0],
        [!VAR "Idx" = "$Idx+1"!][!//
    [!ENDLOOP!][!//
    [!VAR "Idx" = "0"!][!//
    [!LOOP "Can2OtherRoutingTable/*"!][!//
        [!IF "RoutingType = 'PCIe'"!]
            [!WS "4"!]&Llce_Can2Pcie_Buffer[!"num:i($Idx)"!][0][0],
            [!VAR "Idx" = "$Idx+1"!][!//
        [!ENDIF!]
    [!ENDLOOP!][!//
};
[!ENDIF!][!//
[!IF "num:i($C2C_CNT + $C2E_CNT + $C2O_CNT) > 0"!][!//
/* Configuration for Can2Can and Can2Eth and Can2Other routing */
const Can_Af_DestRulesType Llce_Can_AfRoutingTable[LLCE_CAN_ADVANCED_FEATURE_CAN2CAN_CNT + LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT + LLCE_CAN_ADVANCED_FEATURE_CAN2OTHER_CNT] =
{
    [!CALL "GenerateAdvancedDestinations"!]    
};
[!ENDIF!][!//
[!ENDSELECT!][!//

#define CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_43_LLCE_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

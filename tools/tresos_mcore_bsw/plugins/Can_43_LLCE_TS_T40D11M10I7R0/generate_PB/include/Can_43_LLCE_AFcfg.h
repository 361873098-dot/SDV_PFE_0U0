/**
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
#ifndef CAN_AFCFG_H
#define CAN_AFCFG_H

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Can_43_LLCE_Cfg.h"
[!NOCODE!]
[!INCLUDE "Can_43_LLCE_Macros.m"!][!//
[!ENDNOCODE!]
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!AUTOSPACING!][!//
[!VAR "AF_CNT"  = "num:i(0)"!][!//
[!VAR "C2C_CNT" = "num:i(0)"!][!//
[!VAR "C2E_CNT" = "num:i(0)"!][!//
[!VAR "ETH2CAN_BUF_CNT" = "num:i(0)"!][!//
[!VAR "ETH2CAN_BUF_SIZE" = "num:i(0)"!][!//
[!VAR "ETH2CAN_FORMAT_CNT" = "num:i(0)"!][!//
[!VAR "ETH2CAN_ENABLED" = "'STD_OFF'"!][!//
[!INDENT "0"!][!//
[!SELECT "as:modconf('Llce_Af')/LlceAfGeneral"!][!//
    [!CALL "CountCan2Other"!]
[!ENDSELECT!]
    [!WS "0"!]#define LLCE_CAN_ADVANCED_FEATURE_AF_CNT          [!"$AF_CNT"!]U
    [!WS "0"!]#define LLCE_CAN_ADVANCED_FEATURE_CAN2CAN_CNT     [!"$C2C_CNT"!]U
    [!WS "0"!]#define LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT     [!"$C2E_CNT"!]U
    [!WS "0"!]#define LLCE_CAN_ADVANCED_FEATURE_CAN2PCIE_CNT    [!"num:i($C2PCIE_CNT)"!]U
    [!WS "0"!]#define LLCE_CAN_ADVANCED_FEATURE_CAN2OTHER_CNT   [!"num:i($C2O_CNT)"!]U

[!SELECT "as:modconf('Llce_Af')/LlceAfGeneral/Eth2Can"!]
    [!IF "Eth2CanEnable"!]
        [!VAR "ETH2CAN_ENABLED" = "'STD_ON'"!]
        [!VAR "ETH2CAN_BUF_CNT" = "num:i(Eth2CanBufferCount)"!]
        [!VAR "ETH2CAN_BUF_SIZE" = "num:i(Eth2CanBufferSize + (Eth2CanBufferSize mod 2))"!]
        [!VAR "ETH2CAN_FORMAT_CNT" = "num:i(count(Eth2CanEnabledFormats/*))"!]

        #define LLCE_CAN_ADVANCED_FEATURE_ETH2CAN_BUF_CNT       [!"$ETH2CAN_BUF_CNT"!]U
        #define LLCE_CAN_ADVANCED_FEATURE_ETH2CAN_BUF_SIZE      [!"$ETH2CAN_BUF_SIZE"!]U
        #define LLCE_CAN_ADVANCED_FEATURE_ETH2CAN_FORMAT_CNT    [!"$ETH2CAN_FORMAT_CNT"!]U
    [!ENDIF!]
[!ENDSELECT!]
#define LLCE_CAN_ADVANCED_FEATURE_ETH2CAN_ENABLED       [!"$ETH2CAN_ENABLED"!]

#if(LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT > 0)
/*
* @brief          CAN2ETH with external buffer
* @details        User shall use the external rings instead of internal ones.
*
*/
[!SELECT "as:modconf('Llce_Af')/LlceAfGeneral"!]
[!IF "node:exists(CAN2ETHWithExternalRingBuffer) and (CAN2ETHWithExternalRingBuffer = 'true')"!]
#define LLCE_USE_EXTERNAL_RING_BUF (STD_ON)

#define LLCE_PFE_HIF_RING_CFG_LENGTH         128U /*number of BD*/

#define LLCE_PFE_BD_SIZE                     16U /*bytes*/
#define LLCE_PFE_BD_RING_SIZE                (LLCE_PFE_BD_SIZE * LLCE_PFE_HIF_RING_CFG_LENGTH)

#define LLCE_PFE_BD_WB_SIZE                  8U /*bytes*/
#define LLCE_PFE_BD_WB_RING_SIZE             (LLCE_PFE_BD_WB_SIZE * LLCE_PFE_HIF_RING_CFG_LENGTH)

#define LLCE_PFE_TX_HDR_EACH_SIZE            16U /*bytes*/
#define LLCE_PFE_TX_HDR_COUNT                LLCE_PFE_HIF_RING_CFG_LENGTH /*required by LLCE driver*/
#define LLCE_PFE_TX_HDR_SIZE                 (LLCE_PFE_TX_HDR_EACH_SIZE * LLCE_PFE_TX_HDR_COUNT)

#define LLCEIF_MIN_NUM_RX_BUF                72U
[!ELSE!]
    #define LLCE_USE_EXTERNAL_RING_BUF (STD_OFF)
[!ENDIF!]
[!ENDSELECT!]
#endif
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
[!IF "$AF_CNT > 0"!]
/* Configuration for advanced features */
extern const Llce_Can_AdvancedFeatureType Can_Llce_AdvancedFeature[LLCE_CAN_ADVANCED_FEATURE_AF_CNT];
[!ENDIF!]


[!IF "num:i($C2E_CNT + $C2PCIE_CNT) > 0"!]
/* Array with ETH and PCIE buffer addresses */
extern const uint8* pLlce_Can_AfBuffer[LLCE_CAN_ADVANCED_FEATURE_CAN2CAN_CNT + LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT + LLCE_CAN_ADVANCED_FEATURE_CAN2OTHER_CNT];
[!ENDIF!]
[!IF "num:i($C2C_CNT + $C2E_CNT + $C2O_CNT) > 0"!]
/* Configuration for Routing Rules (CAN2CAN, CAN2ETH, CAN2OTHER)  */
extern const Can_Af_DestRulesType Llce_Can_AfRoutingTable[LLCE_CAN_ADVANCED_FEATURE_CAN2CAN_CNT + LLCE_CAN_ADVANCED_FEATURE_CAN2ETH_CNT + LLCE_CAN_ADVANCED_FEATURE_CAN2OTHER_CNT];
[!ENDIF!]
    
[!SELECT "as:modconf('Llce_Af')/LlceAfGeneral/Eth2Can"!]
    [!IF "Eth2CanEnable"!]
        extern uint8 Llce_Eth2Can_Buffer[LLCE_CAN_ADVANCED_FEATURE_ETH2CAN_BUF_CNT][LLCE_CAN_ADVANCED_FEATURE_ETH2CAN_BUF_SIZE];
        extern Llce_Can_EthEncapsulationFormat Llce_Eth2Can_EnabledFormats[LLCE_CAN_ADVANCED_FEATURE_ETH2CAN_FORMAT_CNT];
    [!ENDIF!]
[!ENDSELECT!]

[!SELECT "as:modconf('Llce_Af')/LlceAfGeneral"!]
[!IF "node:exists(CAN2ETHWithExternalRingBuffer) and (CAN2ETHWithExternalRingBuffer = 'true')"!]
    extern volatile uint8 Llce_PfeIf_RxRing  [LLCE_PFE_BD_RING_SIZE];
    extern volatile uint8 Llce_PfeIf_RxWbRing[LLCE_PFE_BD_WB_RING_SIZE];
    extern volatile uint8 Llce_PfeIf_TxRing  [LLCE_PFE_BD_RING_SIZE];
    extern volatile uint8 Llce_PfeIf_TxWbRing[LLCE_PFE_BD_WB_RING_SIZE];
    extern volatile uint8 Llce_PfeIf_Hdr     [LLCE_PFE_TX_HDR_SIZE];
[!ENDIF!]
[!ENDSELECT!]
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

[!ENDINDENT!]
#ifdef __cplusplus
}
#endif

#endif /* CAN_AFCFG_H */

/** @} */

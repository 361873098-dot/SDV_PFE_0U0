/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
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

/* Prevention from multiple including the same header */
#ifndef CRC_IP_HW_ACCESS_H
#define CRC_IP_HW_ACCESS_H

/**
*   @file    Crc_Ip_Hw_Access.h
*
*   @version 4.0.2
*
*   @brief   AUTOSAR Crc - Crc Ip driver source file.
*   @details
*
*   @addtogroup CRC_IP_DRIVER CRC IP Configure Register
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Crc_Ip_CfgDefines.h"

#if (STD_ON == CRC_IP_HARDWARE_IS_AVAILABLE)
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
#endif  /* STD_ON == CRC_IP_HARDWARE_IS_AVAILABLE */



#if (STD_ON == CRC_IP_HARDWARE_IS_AVAILABLE)
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @brief Parameters that shall be published within the driver header file and also in the
* module's description file
*/
#define CRC_IP_HW_ACCESS_VENDOR_ID                      43
#define CRC_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION       4
#define CRC_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION       4
#define CRC_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION    0
#define CRC_IP_HW_ACCESS_SW_MAJOR_VERSION               4
#define CRC_IP_HW_ACCESS_SW_MINOR_VERSION               0
#define CRC_IP_HW_ACCESS_SW_PATCH_VERSION               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Crc_Ip_Hw_Access.h file and Mcal.h header file are of the same Autosar version */
#if ((CRC_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Crc_Ip_Hw_Access.h and Mcal.h are different"
#endif
#endif

/* Check if source file and Crc_Ip_CfgDefines.h file are of the same vendor */
#if (CRC_IP_HW_ACCESS_VENDOR_ID != CRC_IP_CFG_DEFINES_VENDOR_ID)
    #error "Crc_Ip_Hw_Access.h and Crc_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if source file and Crc_Ip_CfgDefines.h file are of the same Autosar version */
#if ((CRC_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION    != CRC_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION    != CRC_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION != CRC_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Ip_Hw_Access.h and Crc_Ip_CfgDefines.h are different"
#endif

/* Check if source file and Crc_Ip_CfgDefines.h header file are of the same Software version */
#if ((CRC_IP_HW_ACCESS_SW_MAJOR_VERSION != CRC_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (CRC_IP_HW_ACCESS_SW_MINOR_VERSION != CRC_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (CRC_IP_HW_ACCESS_SW_PATCH_VERSION != CRC_IP_CFG_DEFINES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crc_Ip_Hw_Access.h and Crc_Ip_CfgDefines.h are different"
#endif
/*==================================================================================================
 * CRC CHANNEL CONFIGURATION FUNCTION - REGISTER ACCESSCFG
==================================================================================================*/
#if (STD_ON == CRC_IP_HARDWARE_PROTOCOL_IS_AVAILABLE)
/**
 * @brief   Sets the CRC protocol width
 * @details This function sets the CRC protocol width
 *
 * @param[in]  pxCrcBase     - The CRC peripheral base address
 * @param[in]  HwChannel     - Hardware Channel
 * @param[in]  Protocol      - CRC protocol width:
 *                             + CRC_PROTOCOL_8BIT:     8-bit CRC protocol.
 *                             + CRC_PROTOCOL_8BIT_H2F: 8-bit CRC protocol.
 *                             + CRC_PROTOCOL_16BIT:    16-bit CRC protocol.
 *                             + CRC_PROTOCOL_32BIT:    32-bit CRC protocol.
 *                             + ...
 *
 * @return void
 **/
static inline void hwAccCrc_SetCrcProtocol(CRC_Type *const pxCrcBase,
                                           const uint8 HwChannel,
                                           const Crc_Ip_ProtocolType Protocol
                                          )
{
    uint32 RegValue = 0U;
    uint32 Reg = 0U;

    switch (Protocol)
    {
        case CRC_PROTOCOL_16BIT_CCITT_FALSE:
            RegValue = 0U;
            break;
        case CRC_PROTOCOL_32BIT_ETHERNET:
            RegValue = 1U;
            break;
        case CRC_PROTOCOL_8BIT_SAE_J1850:
            RegValue = 2U;
            break;
        case CRC_PROTOCOL_8BIT_H2F:
            RegValue = 3U;
            break;
        default:
            /* Set CRC width default is CRC16 */
            RegValue = 0U;
            break;
    }

    Reg = pxCrcBase->CHANNEL[HwChannel].CFG;
    Reg = ((Reg & (~(CRC_CFG_POLYG_MASK))) | (CRC_CFG_POLYG(RegValue)));
    pxCrcBase->CHANNEL[HwChannel].CFG = Reg;
}
#endif /* #if (STD_ON == CRC_IP_HARDWARE_PROTOCOL_IS_AVAILABLE) */

#if (STD_ON == CRC_IP_HARDWARE_INITIAL_SEED_VALUE_IS_AVAILABLE)
/**
 * @brief    Sets seed of the CRC data register
 * @details  This function sets seed of the CRC data register
 *
 * @param[in]  pxCrcBase          - The CRC peripheral base address
 * @param[in]  HwChannel          - Hardware Channel
 * @param[in]  InitialSeedValue   - new start (seed) Value for CRC computation
 *
 * @return void
 **/
static inline void hwAccCrc_SetInitialSeedValue(CRC_Type *const pxCrcBase,
                                                uint8 HwChannel,
                                                uint32 InitialSeedValue
                                               )
{
    pxCrcBase->CHANNEL[HwChannel].CSTAT = InitialSeedValue;
}
#endif /* #if (STD_ON == CRC_IP_HARDWARE_INITIAL_SEED_VALUE_IS_AVAILABLE) */


/**
 * @brief    Sets the CRC Swap Data Write
 * @details  This function sets swap option when write data
 *
 * @param[in]  pxCrcBase          - The CRC peripheral base address
 * @param[in]  HwChannel          - Hardware Channel
 * @param[in]  WriteBitSwap       - Option set BitSwap
 * @param[in]  WriteByteSwap      - Option set ByteSwap
 *
 * @return void
 **/
static inline void hwAccCrc_SetWriteSwap(CRC_Type *const pxCrcBase,
                                         uint8 HwChannel,
                                         boolean WriteBitSwap,
                                         boolean WriteByteSwap
                                        )
{
    uint32 Reg = pxCrcBase->CHANNEL[HwChannel].CFG;

#if (STD_ON == CRC_IP_HARDWARE_WRITE_BIT_SWAP_IS_AVAILABLE)
    Reg = ((Reg & (~(CRC_CFG_SWAP_BITWISE_MASK))) | (CRC_CFG_SWAP_BITWISE(WriteBitSwap ? 1UL : 0UL)));
#endif /* #if (STD_ON == CRC_IP_HARDWARE_WRITE_BIT_SWAP_IS_AVAILABLE) */

#if (STD_ON == CRC_IP_HARDWARE_WRITE_BYTE_SWAP_IS_AVAILABLE)
    Reg = ((Reg & (~(CRC_CFG_SWAP_BYTEWISE_MASK))) | (CRC_CFG_SWAP_BYTEWISE(WriteByteSwap ? 1UL : 0UL)));
#endif /* #if (STD_ON == CRC_IP_HARDWARE_WRITE_BYTE_SWAP_IS_AVAILABLE) */

    pxCrcBase->CHANNEL[HwChannel].CFG = Reg;
}

#if (STD_ON == CRC_IP_HARDWARE_READ_BIT_SWAP_IS_AVAILABLE)
/**
 * @brief    Sets the CRC Swap Data Read
 * @details  This function sets swap option when read data
 *
 * @param[in]  pxCrcBase         - The CRC peripheral base address
 * @param[in]  HwChannel         - Hardware Channel
 * @param[in]  ReadBitSwap       - Option set BitSwap
 * @param[in]  ReadByteSwap      - Option set ByteSwap
 *
 * @return void
 **/
static inline void hwAccCrc_SetReadSwap(CRC_Type *const pxCrcBase,
                                        uint8 HwChannel,
                                        boolean ReadBitSwap,
                                        boolean ReadByteSwap
                                       )
{
    uint32 Reg = pxCrcBase->CHANNEL[HwChannel].CFG;

    Reg = ((Reg & (~(CRC_CFG_SWAP_MASK))) | (CRC_CFG_SWAP(ReadBitSwap ? 1UL : 0UL)));
    pxCrcBase->CHANNEL[HwChannel].CFG = Reg;
    (void)ReadByteSwap;
}
#endif /* #if (STD_ON == CRC_IP_HARDWARE_READ_BIT_SWAP_IS_AVAILABLE) */


#if (STD_ON == CRC_IP_HARDWARE_INVERSE_BIT_IS_AVAILABLE)
/**
 * @brief    Sets the CRC Inversion content (XOR)
 * @details  This function sets Inversion CRC_OUTP content
 *
 * @param[in]  pxCrcBase    - The CRC peripheral base address
 * @param[in]  HwChannel    - Hardware Channel
 * @param[in]  InverseBit - Inverse Value XOR complement (or negation)
 *
 * @return void
 **/
static inline void hwAccCrc_SetInverseResult(CRC_Type *const pxCrcBase,
                                             const uint8 HwChannel,
                                             const boolean InverseBit
                                            )
{
    uint32 Reg = pxCrcBase->CHANNEL[HwChannel].CFG;

    Reg = ((Reg & (~(CRC_CFG_INV_MASK))) | (CRC_CFG_INV(InverseBit ? 1UL : 0UL)));
    pxCrcBase->CHANNEL[HwChannel].CFG = Reg;
}
#endif /* #if (STD_ON == CRC_IP_HARDWARE_INVERSE_BIT_IS_AVAILABLE) */


/**
 * @brief    Sets the CRC Data Input
 * @details  This function sets CRC Data Input into CRC_INP register
 *
 * @param[in]  pxCrcBase    - The CRC peripheral base address
 * @param[in]  HwChannel    - Hardware Channel
 * @param[in]  Value        - New data for CRC computation
 *
 * @return void
 **/
static inline void hwAccCrc_SetInputData(CRC_Type *const pxCrcBase,
                                         const uint8 HwChannel,
                                         const uint8 Value
                                        )
{
    *(volatile uint8 *)&pxCrcBase->CHANNEL[HwChannel].INP = Value;
}

/*==================================================================================================
 * CRC GET PARAMETER - REGISTER ACCESS
==================================================================================================*/
#if (STD_ON == CRC_IP_DMA_IS_AVAILABLE)
/**
 * @brief   Returns the address of data input area
 * @details This function returns the address of data input area
 *
 * @param[in]  pxCrcBase    - The CRC peripheral base address
 * @param[in]  HwChannel    - Hardware Channel
 *
 * @return     Address of data input area
 **/
static inline uint32 hwAccCRC_GetDataInputAddress(const CRC_Type *const pxCrcBase, const uint8 HwChannel)
{
    return (uint32)&pxCrcBase->CHANNEL[HwChannel].INP;
}
#endif /* #if (STD_ON == CRC_IP_DMA_IS_AVAILABLE) */

/**
 * @brief   Returns the current result of the CRC calculation
 * @details This function returns the current result of the CRC calculation
 *
 * @param[in]  pxCrcBase    - The CRC peripheral base address
 * @param[in]  HwChannel    - Hardware Channel
 *
 * @return     Result of CRC calculation
 **/
static inline uint32 hwAccCRC_GetResult(const CRC_Type *const pxCrcBase, const uint8 HwChannel)
{
    uint32 CrcPolynomial = 0U;
    uint32 CrcResult = 0;

    /* Get CRC polynomial */
    CrcPolynomial = (pxCrcBase->CHANNEL[HwChannel].CFG & CRC_CFG_POLYG_MASK) >> CRC_CFG_POLYG_SHIFT;

    switch (CrcPolynomial)
    {
        case (uint32)CRC_IP_HARDWARE_32BIT_ETHERNET_POLYG:
            CrcResult = pxCrcBase->CHANNEL[HwChannel].OUTP;
            break;
        case (uint32)CRC_IP_HARDWARE_8BIT_SAE_J1850_POLYG:
        case (uint32)CRC_IP_HARDWARE_8BIT_H2F_POLYG:
            CrcResult = pxCrcBase->CHANNEL[HwChannel].OUTP & CRC_IP_HARDWARE_8BIT_OUTP_MASK;
            break;
        default:
            /* For CRC_IP_HARDWARE_16BIT_CCITT_FALSE_POLYG polynomial */
            CrcResult = pxCrcBase->CHANNEL[HwChannel].OUTP & CRC_IP_HARDWARE_16BIT_OUTP_MASK;
            break;
    }

    return CrcResult;
}


#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#endif /* #if (STD_ON == CRC_IP_HARDWARE_IS_AVAILABLE) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* #ifndef CRC_IP_HW_ACCESS_H */

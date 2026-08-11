/**
 *   @file    Llce_InterfaceCore2Core.h
 *
 *   @brief   This file contains defines used for accessing LLCE core2core hw
 *            module
 *   @details This file contains defines used for accessing LLCE core2core hw
 *            module
 *
 *   @addtogroup LLCE_CAN_firmware_interface LLCE CAN firmware interface
 *   @{
 */
/*==================================================================================================
 *
 * Copyright 2018-2023 NXP
 *
 * NXP Confidential. This software is owned or controlled by NXP and may only be
 * used strictly in accordance with the applicable license terms. By expressly
 * accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that
 * you agree to comply with and are bound by, such license terms.  If you do not
 * agree to be bound by the applicable license terms, then you may not retain,
 * install, activate or otherwise use the software.
 ==================================================================================================*/

#ifndef LLCE_INTERFACECORE2CORE_H
#define LLCE_INTERFACECORE2CORE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __DOXYGEN__
/**
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 4.9, A function should be used in
 * preference to a function-like macro where they are interchangeable. Function
 * like macro are used to reduce code complexity
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 2.5, A project should not contain unused
 * macro declarations Some macros are used either in FW or driver, or provided
 * as API
 *
 */
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
 ==================================================================================================*/
#include "Llce_RegAccess.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 ==================================================================================================*/

/*==================================================================================================
 *                                     FILE VERSION CHECKS
 ==================================================================================================*/

/*==================================================================================================
 *                                          CONSTANTS
 ==================================================================================================*/

/*==================================================================================================
 *                                      DEFINES AND MACROS
 ==================================================================================================*/
/*==================================================================================================
                  CORE2CORE COMMON DEFINES AND ADDRESS CALCULATION
 MACROS DTE=C0, RXPPE=C1, TXPPE=C2, FR=C3
 =================================================================================================*/
 /** @brief Base address for the CORE2CORE module. */
#define LLCE_CORE2CORE_BASEADDR ((uint32)0x43C26000UL)

#define LLCE_CORE2CORE_HINTC0R ((uint32)LLCE_CORE2CORE_BASEADDR)
#define LLCE_CORE2CORE_HINTC1R ((uint32)LLCE_CORE2CORE_BASEADDR + 0x04U)
#define LLCE_CORE2CORE_HINTC2R ((uint32)LLCE_CORE2CORE_BASEADDR + 0x08U)
#define LLCE_CORE2CORE_HINTC3R ((uint32)LLCE_CORE2CORE_BASEADDR + 0x0CU)

#define LLCE_CORE2CORE_C0INTHR ((uint32)LLCE_CORE2CORE_BASEADDR + 0x20U)
#define LLCE_CORE2CORE_C1INTHR ((uint32)LLCE_CORE2CORE_BASEADDR + 0x24U)
#define LLCE_CORE2CORE_C2INTHR ((uint32)LLCE_CORE2CORE_BASEADDR + 0x28U)
#define LLCE_CORE2CORE_C3INTHR ((uint32)LLCE_CORE2CORE_BASEADDR + 0x2CU)

#define LLCE_CORE2CORE_C0INTCR ((uint32)LLCE_CORE2CORE_BASEADDR + 0x40U)
#define LLCE_CORE2CORE_C1INTCR ((uint32)LLCE_CORE2CORE_BASEADDR + 0x44U)
#define LLCE_CORE2CORE_C2INTCR ((uint32)LLCE_CORE2CORE_BASEADDR + 0x48U)
#define LLCE_CORE2CORE_C3INTCR ((uint32)LLCE_CORE2CORE_BASEADDR + 0x4CU)

#define LLCE_CORE2CORE_HINTC0ER ((uint32)LLCE_CORE2CORE_BASEADDR + 0x60U)
#define LLCE_CORE2CORE_HINTC1ER ((uint32)LLCE_CORE2CORE_BASEADDR + 0x64U)
#define LLCE_CORE2CORE_HINTC2ER ((uint32)LLCE_CORE2CORE_BASEADDR + 0x68U)
#define LLCE_CORE2CORE_HINTC3ER ((uint32)LLCE_CORE2CORE_BASEADDR + 0x6CU)

#define LLCE_CORE2CORE_C0INTHER ((uint32)LLCE_CORE2CORE_BASEADDR + 0x80U)
#define LLCE_CORE2CORE_C1INTHER ((uint32)LLCE_CORE2CORE_BASEADDR + 0x84U)
#define LLCE_CORE2CORE_C2INTHER ((uint32)LLCE_CORE2CORE_BASEADDR + 0x88U)
#define LLCE_CORE2CORE_C3INTHER ((uint32)LLCE_CORE2CORE_BASEADDR + 0x8CU)

#define LLCE_CORE2CORE_C0INTCER ((uint32)LLCE_CORE2CORE_BASEADDR + 0xA0U)
#define LLCE_CORE2CORE_C1INTCER ((uint32)LLCE_CORE2CORE_BASEADDR + 0xA4U)
#define LLCE_CORE2CORE_C2INTCER ((uint32)LLCE_CORE2CORE_BASEADDR + 0xA8U)
#define LLCE_CORE2CORE_C3INTCER ((uint32)LLCE_CORE2CORE_BASEADDR + 0xACU)

#define LLCE_CORE2CORE_C1INTHR_RXLUT_FLAG     ((uint32)0x01U)
#define LLCE_CORE2CORE_HINTC1R_RXLUT_FLAG     ((uint32)0x04U) 

#define LLCE_CORE2DTE_ASSERT_INTERRUPT(u8HwCtrl)                               \
    Reg_Bit_Set32(LLCE_CORE2CORE_C0INTCR,                                      \
                  (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_CORE2DTE_GET_STATUS_INTERRUPT(u8HwCtrl)                           \
    (Reg_Read32(LLCE_CORE2CORE_C0INTCR) &                                      \
     (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_CORE2DTE_CLEAR_INTERRUPT(u8HwCtrl)                                \
    Reg_Write32(LLCE_CORE2CORE_C0INTCR, (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_CORE2DTE_ENABLE_INTERRUPT(u8HwCtrl)                               \
    Reg_Bit_Set32(LLCE_CORE2CORE_C0INTCER,                                     \
                  (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_CORE2DTE_DISABLE_INTERRUPT(u8HwCtrl)                              \
    Reg_Bit_Clear32(LLCE_CORE2CORE_C0INTCER,                                   \
                    (((uint32)0x01U) << ((uint32)u8HwCtrl)))


#define LLCE_CORE2RX_ASSERT_INTERRUPT(u8HwCtrl)                                \
    Reg_Bit_Set32(LLCE_CORE2CORE_C1INTCR,                                      \
                  (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_CORE2RX_GET_STATUS_INTERRUPT(u8HwCtrl)                            \
    (Reg_Read32(LLCE_CORE2CORE_C1INTCR) &                                      \
     (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_CORE2RX_CLEAR_INTERRUPT(u8HwCtrl)                                 \
    Reg_Write32(LLCE_CORE2CORE_C1INTCR, (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_CORE2RX_ENABLE_INTERRUPT(u8HwCtrl)                                \
    Reg_Bit_Set32(LLCE_CORE2CORE_C1INTCER,                                     \
                  (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_CORE2RX_DISABLE_INTERRUPT(u8HwCtrl)                               \
    Reg_Bit_Clear32(LLCE_CORE2CORE_C1INTCER,                                   \
                    (((uint32)0x01U) << ((uint32)u8HwCtrl)))

#define LLCE_CORE2TX_ASSERT_INTERRUPT(u8HwCtrl)                                \
    Reg_Bit_Set32(LLCE_CORE2CORE_C2INTCR,                                      \
                  (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_CORE2TX_GET_STATUS_INTERRUPT(u8HwCtrl)                            \
    (Reg_Read32(LLCE_CORE2CORE_C2INTCR) &                                      \
     (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_CORE2TX_CLEAR_INTERRUPT(u8HwCtrl)                                 \
    Reg_Write32(LLCE_CORE2CORE_C2INTCR, (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_CORE2TX_ENABLE_INTERRUPT(u8HwCtrl)                                \
    Reg_Bit_Set32(LLCE_CORE2CORE_C2INTCER,                                     \
                  (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_CORE2TX_DISABLE_INTERRUPT(u8HwCtrl)                               \
    Reg_Bit_Clear32(LLCE_CORE2CORE_C2INTCER,                                   \
                    (((uint32)0x01U) << ((uint32)u8HwCtrl)))

#define LLCE_CORE2FRPE_ASSERT_INTERRUPT(u8HwCtrl)                              \
    Reg_Bit_Set32(LLCE_CORE2CORE_C3INTCR,                                      \
                  (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_CORE2FRPE_GET_STATUS_INTERRUPT(u8HwCtrl)                          \
    (Reg_Read32(LLCE_CORE2CORE_C3INTCR) &                                      \
     (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_CORE2FRPE_CLEAR_INTERRUPT(u8HwCtrl)                               \
    Reg_Write32(LLCE_CORE2CORE_C3INTCR, (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_CORE2FRPE_ENABLE_INTERRUPT(u8HwCtrl)                              \
    Reg_Bit_Set32(LLCE_CORE2CORE_C3INTCER,                                     \
                  (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_CORE2FRPE_DISABLE_INTERRUPT(u8HwCtrl)                             \
    Reg_Bit_Clear32(LLCE_CORE2CORE_C3INTCER,                                   \
                    (((uint32)0x01U) << ((uint32)u8HwCtrl)))

#define LLCE_HOST2RX_ASSERT_INTERRUPT(u8HwCtrl)                                \
    Reg_Bit_Set32(LLCE_CORE2CORE_C1INTHR,                                      \
                  (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_HOST2RX_GET_STATUS_INTERRUPT(u8HwCtrl)                            \
    (Reg_Read32(LLCE_CORE2CORE_C1INTHR) &                                      \
     (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_HOST2RX_CLEAR_INTERRUPT(u8HwCtrl)                                 \
    Reg_Write32(LLCE_CORE2CORE_C1INTHR, (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_HOST2RX_ENABLE_INTERRUPT(u8HwCtrl)                                \
    Reg_Bit_Set32(LLCE_CORE2CORE_C1INTHER,                                     \
                  (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_HOST2RX_DISABLE_INTERRUPT(u8HwCtrl)                               \
    Reg_Bit_Clear32(LLCE_CORE2CORE_C1INTHER,                                   \
                    (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_RX2HOST_ASSERT_INTERRUPT(u8HwCtrl)                                \
    Reg_Bit_Set32(LLCE_CORE2CORE_HINTC1R,                                      \
                  (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_RX2HOST_GET_STATUS_INTERRUPT(u8HwCtrl)                            \
    (Reg_Read32(LLCE_CORE2CORE_HINTC1R) &                                      \
     (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_RX2HOST_CLEAR_INTERRUPT(u8HwCtrl)                                 \
    Reg_Write32(LLCE_CORE2CORE_HINTC1R, (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_RX2HOST_ENABLE_INTERRUPT(u8HwCtrl)                                \
    Reg_Bit_Set32(LLCE_CORE2CORE_HINTC1ER,                                     \
                  (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_RX2HOST_DISABLE_INTERRUPT(u8HwCtrl)                               \
    Reg_Bit_Clear32(LLCE_CORE2CORE_HINTC1ER,                                   \
                    (((uint32)0x01U) << ((uint32)u8HwCtrl)))

#define LLCE_HOST2TX_ASSERT_INTERRUPT(u8HwCtrl)                                \
    Reg_Bit_Set32(LLCE_CORE2CORE_C2INTHR,                                      \
                  (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_HOST2TX_GET_STATUS_INTERRUPT(u8HwCtrl)                            \
    (Reg_Read32(LLCE_CORE2CORE_C2INTHR) &                                      \
     (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_HOST2TX_CLEAR_INTERRUPT(u8HwCtrl)                                 \
    Reg_Write32(LLCE_CORE2CORE_C2INTHR, (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_HOST2TX_ENABLE_INTERRUPT(u8HwCtrl)                                \
    Reg_Bit_Set32(LLCE_CORE2CORE_C2INTHER,                                     \
                  (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_HOST2TX_DISABLE_INTERRUPT(u8HwCtrl)                               \
    Reg_Bit_Clear32(LLCE_CORE2CORE_C2INTHER,                                   \
                    (((uint32)0x01U) << ((uint32)u8HwCtrl)))

#define LLCE_TX2HOST_ASSERT_INTERRUPT(u8HwCtrl)                                \
    Reg_Bit_Set32(LLCE_CORE2CORE_HINTC2R,                                      \
                  (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_TX2HOST_GET_STATUS_INTERRUPT(u8HwCtrl)                            \
    (Reg_Read32(LLCE_CORE2CORE_HINTC2R) &                                      \
     (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_TX2HOST_CLEAR_INTERRUPT(u8HwCtrl)                                 \
    Reg_Write32(LLCE_CORE2CORE_HINTC2R, (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_TX2HOST_ENABLE_INTERRUPT(u8HwCtrl)                                \
    Reg_Bit_Set32(LLCE_CORE2CORE_HINTC2ER,                                     \
                  (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_TX2HOST_DISABLE_INTERRUPT(u8HwCtrl)                               \
    Reg_Bit_Clear32(LLCE_CORE2CORE_HINTC2ER,                                   \
                    (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_TX2HOST_GET_ENABLE_STATUS_INTERRUPT(u8HwCtrl)                     \
    (Reg_Read32(LLCE_CORE2CORE_HINTC2ER) &                                     \
     (((uint32)0x01U) << ((uint32)u8HwCtrl)))

#define LLCE_HOST2FRPE_ASSERT_INTERRUPT(u8HwCtrl)                              \
    Reg_Bit_Set32(LLCE_CORE2CORE_C3INTHR,                                      \
                  (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_HOST2FRPE_GET_STATUS_INTERRUPT(u8HwCtrl)                          \
    (Reg_Read32(LLCE_CORE2CORE_C3INTHR) &                                      \
     (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_HOST2FRPE_CLEAR_INTERRUPT(u8HwCtrl)                               \
    Reg_Write32(LLCE_CORE2CORE_C3INTHR, (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_HOST2FRPE_ENABLE_INTERRUPT(u8HwCtrl)                              \
    Reg_Bit_Set32(LLCE_CORE2CORE_C3INTHER,                                     \
                  (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_HOST2FRPE_DISABLE_INTERRUPT(u8HwCtrl)                             \
    Reg_Bit_Clear32(LLCE_CORE2CORE_C3INTHER,                                   \
                    (((uint32)0x01U) << ((uint32)u8HwCtrl)))

#define LLCE_FRPE2HOST_ASSERT_INTERRUPT(u8HwCtrl)                              \
    Reg_Bit_Set32(LLCE_CORE2CORE_HINTC3R,                                      \
                  (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_FRPE2HOST_GET_STATUS_INTERRUPT(u8HwCtrl)                          \
    (Reg_Read32(LLCE_CORE2CORE_HINTC3R) &                                      \
     (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_FRPE2HOST_CLEAR_INTERRUPT(u8HwCtrl)                               \
    Reg_Write32(LLCE_CORE2CORE_HINTC3R, (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_FRPE2HOST_ENABLE_INTERRUPT(u8HwCtrl)                              \
    Reg_Bit_Set32(LLCE_CORE2CORE_HINTC3ER,                                     \
                  (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_FRPE2HOST_DISABLE_INTERRUPT(u8HwCtrl)                             \
    Reg_Bit_Clear32(LLCE_CORE2CORE_HINTC3ER,                                   \
                    (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_FRPE2HOST_GET_ENABLE_STATUS_INTERRUPT(u8HwCtrl)                   \
    (Reg_Read32(LLCE_CORE2CORE_HINTC3ER) &                                     \
     (((uint32)0x01U) << ((uint32)u8HwCtrl)))

#define LLCE_CORE2CORE_ASSERT_INTERRUPT(u32BaseAddr, u8HwCtrl)                 \
    Reg_Bit_Set32(u32BaseAddr, (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_CORE2CORE_GET_STATUS_INTERRUPT(u32BaseAddr, u8HwCtrl)             \
    (Reg_Read32(u32BaseAddr) & (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_CORE2CORE_CLEAR_INTERRUPT(u32BaseAddr, u8HwCtrl)                  \
    Reg_Write32(u32BaseAddr, (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_CORE2CORE_ENABLE_INTERRUPT(u32BaseAddr, u8HwCtrl)                 \
    Reg_Bit_Set32(u32BaseAddr, (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_CORE2CORE_DISABLE_INTERRUPT(u32BaseAddr, u8HwCtrl)                \
    Reg_Bit_Clear32(u32BaseAddr, (((uint32)0x01U) << ((uint32)u8HwCtrl)))
#define LLCE_CORE2CORE_GET_ENABLE_STATUS_INTERRUPT(u32BaseAddr, u8HwCtrl)      \
    (Reg_Read32(u32BaseAddr) & (((uint32)0x01U) << ((uint32)u8HwCtrl)))

/*==================================================================================================
 *                                      Interrupts
 ==================================================================================================*/

/*==================================================================================================
 *                                             ENUMS
 ==================================================================================================*/

/*==================================================================================================
 *                                STRUCTURES AND OTHER TYPEDEFS
 ==================================================================================================*/

/*==================================================================================================
 *                                GLOBAL VARIABLE DECLARATIONS
 ==================================================================================================*/

/*==================================================================================================
 *                                    FUNCTION PROTOTYPES
 ==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* LLCE_INTERFACECORE2CORE_H */

/** @} */

/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : FLEXRAY
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

/**
*   @file Flexray_Ip_Irq.c
*   @implements Flexray_Ip_Irq.c_Artifact
*
*   @addtogroup Flexray
*   @{
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
#include"Flexray_Ip_Irq.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
 * @brief Parameters that shall be published within the driver header file and also in the
 *        module's description file
 */

#define FLEXRAY_IP_IRQ_VENDOR_ID_C                        43
#define FLEXRAY_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C         4
#define FLEXRAY_IP_IRQ_AR_RELEASE_MINOR_VERSION_C         4
#define FLEXRAY_IP_IRQ_AR_RELEASE_REVISION_VERSION_C      0
#define FLEXRAY_IP_IRQ_SW_MAJOR_VERSION_C                 4
#define FLEXRAY_IP_IRQ_SW_MINOR_VERSION_C                 0
#define FLEXRAY_IP_IRQ_SW_PATCH_VERSION_C                 2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Flexray_Ip_Irq.h header file are of the same vendor */
#if(FLEXRAY_IP_IRQ_VENDOR_ID_C != FLEXRAY_IP_IRQ_VENDOR_ID)
    #error "Flexray_Ip_Irq.c and Flexray_Ip_Irq.h have different Vendor IDs"
#endif
/* Check if current file and Flexray_Ip_Irq.h header file are of the same Autosar version */
#if((FLEXRAY_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != FLEXRAY_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
    (FLEXRAY_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != FLEXRAY_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
    (FLEXRAY_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != FLEXRAY_IP_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Flexray_Ip_Irq.c and Flexray_Ip_Irq.h are different"
#endif
/* Check if current file and Flexray_Ip_Irq.h header file are of the same software version */
#if((FLEXRAY_IP_IRQ_SW_MAJOR_VERSION_C != FLEXRAY_IP_IRQ_SW_MAJOR_VERSION) || \
    (FLEXRAY_IP_IRQ_SW_MINOR_VERSION_C != FLEXRAY_IP_IRQ_SW_MINOR_VERSION) || \
    (FLEXRAY_IP_IRQ_SW_PATCH_VERSION_C != FLEXRAY_IP_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of Flexray_Ip_Irq.c and Flexray_Ip_Irq.h are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"

#ifndef FLEXRAY_AUTOSAR_MODE_USED
    #if (FLEXRAY_INSTANCE_COUNT > 0U)
    ISR(FLEXRAY0_TX_BUFF_IRQHandler);
    ISR(FLEXRAY0_RX_BUFF_IRQHandler);
    ISR(FLEXRAY0_STATUS_IRQHandler);
    ISR(FLEXRAY0_CERR_IRQHandler);
    ISR(FLEXRAY0_WKUP_IRQHandler);
    ISR(FLEXRAY0_CH0_RX_FIFO_IRQHandler);
    ISR(FLEXRAY0_CH1_RX_FIFO_IRQHandler);
    #endif /* (FLEXRAY_INSTANCE_COUNT > 0U) */

    #if (FLEXRAY_INSTANCE_COUNT > 1U)
    ISR(FLEXRAY1_TX_BUFF_IRQHandler);
    ISR(FLEXRAY1_RX_BUFF_IRQHandler);
    ISR(FLEXRAY1_STATUS_IRQHandler);
    ISR(FLEXRAY1_CERR_IRQHandler);
    ISR(FLEXRAY1_WKUP_IRQHandler);
    ISR(FLEXRAY1_CH0_RX_FIFO_IRQHandler);
    ISR(FLEXRAY1_CH1_RX_FIFO_IRQHandler);

    #endif /* (FLEXRAY_INSTANCE_COUNT > 1U) */
#endif
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"

#ifndef FLEXRAY_AUTOSAR_MODE_USED
    #if (FLEXRAY_INSTANCE_COUNT > 0U)
    /* Implementation of FR0 IRQ handler for transmit interrupts. */
    ISR(FLEXRAY0_TX_BUFF_IRQHandler)
    {
        Flexray_Ip_TxIrq(0U);
    }

    /* Implementation of FR0 IRQ handler for receive interrupts. */
    ISR(FLEXRAY0_RX_BUFF_IRQHandler)
    {
        Flexray_Ip_RxIrq(0U);
    }

    /* Implementation of FR0 IRQ handler for protocol interrupts. */
    ISR(FLEXRAY0_STATUS_IRQHandler)
    {
        Flexray_Ip_PrIrq(0U);
    }

    /* Implementation of FR0 IRQ handler for CHI interrupts. */
    ISR(FLEXRAY0_CERR_IRQHandler)
    {
        Flexray_Ip_ChiIrq(0U);
    }

    /* Implementation of FR0 IRQ handler for Wakeup interrupts. */
    ISR(FLEXRAY0_WKUP_IRQHandler)
    {
        Flexray_Ip_WupIrq(0U);
    }

    /* Implementation of FR0 IRQ handler for receive FIFO Channel A Almost Full interrupts. */
    ISR(FLEXRAY0_CH0_RX_FIFO_IRQHandler)
    {
        Flexray_Ip_FAFAIrq(0U);
    }

    /* Implementation of FR0 IRQ handler for receive FIFO Channel B Almost Full interrupts. */
    ISR(FLEXRAY0_CH1_RX_FIFO_IRQHandler)
    {
        Flexray_Ip_FAFBIrq(0U);
    }

    #endif /* (FLEXRAY_INSTANCE_COUNT > 0U) */

    #if (FLEXRAY_INSTANCE_COUNT > 1U)
    /* Implementation of FR1 IRQ handler for transmit interrupts. */
    ISR(FLEXRAY1_TX_BUFF_IRQHandler)
    {
        Flexray_Ip_TxIrq(1U);
    }

    /* Implementation of FR1 IRQ handler for receive interrupts. */
    ISR(FLEXRAY1_RX_BUFF_IRQHandler)
    {
        Flexray_Ip_RxIrq(1U);
    }

    /* Implementation of FR1 IRQ handler for protocol interrupts. */
    ISR(FLEXRAY1_STATUS_IRQHandler)
    {
        Flexray_Ip_PrIrq(1U);
    }

    /* Implementation of FR1 IRQ handler for CHI interrupts. */
    ISR(FLEXRAY1_CERR_IRQHandler)
    {
        Flexray_Ip_ChiIrq(1U);
    }

    /* Implementation of FR1 IRQ handler for Wakeup interrupts. */
    ISR(FLEXRAY1_WKUP_IRQHandler)
    {
        Flexray_Ip_WupIrq(1U);
    }

    /* Implementation of FR1 IRQ handler for receive FIFO Channel A Almost Full interrupts. */
    ISR(FLEXRAY1_CH0_RX_FIFO_IRQHandler)
    {
        Flexray_Ip_FAFAIrq(1U);
    }

    /* Implementation of FR1 IRQ handler for receive FIFO Channel B Almost Full interrupts. */
    ISR(FLEXRAY1_CH1_RX_FIFO_IRQHandler)
    {
        Flexray_Ip_FAFBIrq(1U);
    }
    #endif /* (FLEXRAY_INSTANCE_COUNT > 1U) */

#endif

#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#ifdef __cplusplus
}
#endif

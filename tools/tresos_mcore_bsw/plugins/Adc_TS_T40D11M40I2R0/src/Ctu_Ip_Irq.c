/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : ADC_SAR
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
*   @file
*
*   @addtogroup ctu_ip
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
#include "OsIf.h"
#include "Ctu_Ip_Irq.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CTU_IP_VENDOR_ID_IRQ_C                      43
#define CTU_IP_AR_RELEASE_MAJOR_VERSION_IRQ_C       4
#define CTU_IP_AR_RELEASE_MINOR_VERSION_IRQ_C       4
#define CTU_IP_AR_RELEASE_REVISION_VERSION_IRQ_C    0
#define CTU_IP_SW_MAJOR_VERSION_IRQ_C               4
#define CTU_IP_SW_MINOR_VERSION_IRQ_C               0
#define CTU_IP_SW_PATCH_VERSION_IRQ_C               2

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Ctu_Ip_Irq.c file and OsIf.h file are of the same Autosar version */
#if ((CTU_IP_AR_RELEASE_MAJOR_VERSION_IRQ_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (CTU_IP_AR_RELEASE_MINOR_VERSION_IRQ_C != OSIF_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Ctu_Ip_Irq.c and OsIf.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if Ctu_Ip_Irq.c file and Ctu_Ip_Irq.h file are of the same vendor */
#if (CTU_IP_VENDOR_ID_IRQ_C != CTU_IP_VENDOR_ID_IRQ)
    #error "Ctu_Ip_Irq.c and Ctu_Ip_Irq.h have different vendor ids"
#endif

/* Check if Ctu_Ip_Irq.c file and Ctu_Ip_Irq.h file are of the same Autosar version */
#if ((CTU_IP_AR_RELEASE_MAJOR_VERSION_IRQ_C != CTU_IP_AR_RELEASE_MAJOR_VERSION_IRQ) || \
     (CTU_IP_AR_RELEASE_MINOR_VERSION_IRQ_C != CTU_IP_AR_RELEASE_MINOR_VERSION_IRQ) || \
     (CTU_IP_AR_RELEASE_REVISION_VERSION_IRQ_C != CTU_IP_AR_RELEASE_REVISION_VERSION_IRQ) \
    )
    #error "AutoSar Version Numbers of Ctu_Ip_Irq.c and Ctu_Ip_Irq.h are different"
#endif

/* Check if Ctu_Ip_Irq.c file and Ctu_Ip_Irq.h file are of the same Software version */
#if ((CTU_IP_SW_MAJOR_VERSION_IRQ_C != CTU_IP_SW_MAJOR_VERSION_IRQ) || \
     (CTU_IP_SW_MINOR_VERSION_IRQ_C != CTU_IP_SW_MINOR_VERSION_IRQ) || \
     (CTU_IP_SW_PATCH_VERSION_IRQ_C != CTU_IP_SW_PATCH_VERSION_IRQ) \
    )
  #error "Software Version Numbers of Ctu_Ip_Irq.c and Ctu_Ip_Irq.h are different"
#endif

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

#if (FEATURE_CTU_HAS_FIFO_IRQ_ROLLED)
ISR(Ctu_FIFO_Isr)
{
    /* Call IRQ handler */
    Ctu_Ip_IRQHandler(0u, CTU_IP_IRQ_FIFO, 0u);
}
#else
ISR(Ctu_FIFO0_Isr)
{
    /* Call IRQ handler for the correct FIFO */
    Ctu_Ip_IRQHandler(0u, CTU_IP_IRQ_FIFO, 0u);
}
ISR(Ctu_FIFO1_Isr)
{
    /* Call IRQ handler for the correct FIFO */
    Ctu_Ip_IRQHandler(0u, CTU_IP_IRQ_FIFO, 1u);
}
ISR(Ctu_FIFO2_Isr)
{
    /* Call IRQ handler for the correct FIFO */
    Ctu_Ip_IRQHandler(0u, CTU_IP_IRQ_FIFO, 2u);
}
ISR(Ctu_FIFO3_Isr)
{
    /* Call IRQ handler for the correct FIFO */
    Ctu_Ip_IRQHandler(0u, CTU_IP_IRQ_FIFO, 3u);
}
#endif /* FEATURE_CTU_HAS_FIFO_IRQ_ROLLED */
ISR(Ctu_Trig_Isr)
{
    /* Call IRQ handler */
    Ctu_Ip_IRQHandler(0u, CTU_IP_IRQ_TRIG, 0u);
}
ISR(Ctu_Error_Isr)
{
    /* Call IRQ handler */
    Ctu_Ip_IRQHandler(0u, CTU_IP_IRQ_ERROR, 0u);
}

#ifdef CTU_IP_DMA_SUPPORTED
void Ctu_Ip_Fifo0DmaComplete(void)
{
    /* Call IRQ handler for the correct FIFO */
    Ctu_Ip_FifoDmaHandler(0U, 0U);
}

void Ctu_Ip_Fifo1DmaComplete(void)
{
    /* Call IRQ handler for the correct FIFO */
    Ctu_Ip_FifoDmaHandler(0U, 1U);
}

void Ctu_Ip_Fifo2DmaComplete(void)
{
    /* Call IRQ handler for the correct FIFO */
    Ctu_Ip_FifoDmaHandler(0U, 2U);
}

void Ctu_Ip_Fifo3DmaComplete(void)
{
    /* Call IRQ handler for the correct FIFO */
    Ctu_Ip_FifoDmaHandler(0U, 3U);
}
#endif /* CTU_IP_DMA_SUPPORTED */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

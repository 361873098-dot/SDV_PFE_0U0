/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : SERDES_SS
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

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Pcie_Ip_Irq.h"
#include "Pcie_Ip.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Pcie_Ip_Irq.c
* @requirements   BSW00374, BSW00318
* @implements     DESIGN001, DESIGN002
*/
#define PCIE_IP_IRQ_VENDOR_ID_C                      43
#define PCIE_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define PCIE_IP_IRQ_AR_RELEASE_MINOR_VERSION_C       4
#define PCIE_IP_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define PCIE_IP_IRQ_SW_MAJOR_VERSION_C               4
#define PCIE_IP_IRQ_SW_MINOR_VERSION_C               0
#define PCIE_IP_IRQ_SW_PATCH_VERSION_C               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Pcie_Ip header file are of the same vendor */
#if (PCIE_IP_IRQ_VENDOR_ID_C != PCIE_IP_VENDOR_ID)
    #error "Pcie_Ip_Irq.c and Pcie_Ip.h have different vendor ids"
#endif
/* Check if current file and Pcie_Ip header file are of the same Autosar version */
#if ((PCIE_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != PCIE_IP_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != PCIE_IP_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != PCIE_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pcie_Ip_Irq.c and Pcie_Ip.h are different"
#endif
/* Check if current file and Pcie_Ip header file are of the same Software version */
#if ((PCIE_IP_IRQ_SW_MAJOR_VERSION_C != PCIE_IP_SW_MAJOR_VERSION) || \
     (PCIE_IP_IRQ_SW_MINOR_VERSION_C != PCIE_IP_SW_MINOR_VERSION) || \
     (PCIE_IP_IRQ_SW_PATCH_VERSION_C != PCIE_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pcie_Ip_Irq.c and Pcie_Ip.h are different"
#endif

/* Check if current file and Pcie_Ip header file are of the same vendor */
#if (PCIE_IP_IRQ_VENDOR_ID_C != PCIE_IP_IRQ_VENDOR_ID)
    #error "Pcie_Ip_Irq.c and Pcie_Ip_Irq.h have different vendor ids"
#endif
/* Check if current file and Pcie_Ip header file are of the same Autosar version */
#if ((PCIE_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != PCIE_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != PCIE_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != PCIE_IP_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pcie_Ip_Irq.c and Pcie_Ip_Irq.h are different"
#endif
/* Check if current file and Pcie_Ip header file are of the same Software version */
#if ((PCIE_IP_IRQ_SW_MAJOR_VERSION_C != PCIE_IP_IRQ_SW_MAJOR_VERSION) || \
     (PCIE_IP_IRQ_SW_MINOR_VERSION_C != PCIE_IP_IRQ_SW_MINOR_VERSION) || \
     (PCIE_IP_IRQ_SW_PATCH_VERSION_C != PCIE_IP_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pcie_Ip_Irq.c and Pcie_Ip_Irq.h are different"
#endif


/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/



/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#define PCIE_START_SEC_CODE
#include "Pcie_MemMap.h"



#ifdef PCIE_IP_0_ENABLED
#if (PCIE_IP_0_ENABLED == STD_ON)
/**
* @brief        PCIe0 IRQ handler
* @details      This function should be installed as IRQ handler for PCIe instance 0.
*/
ISR(Pcie_Ip_PCIE_0_DmaIRQHandler)
{
    Pcie_Ip_DmaIRQHandler(0U);
}
#endif
#endif

#ifdef PCIE_IP_1_ENABLED
#if (PCIE_IP_1_ENABLED == STD_ON)
/**
* @brief        PCIe1 IRQ handler
* @details      This function should be installed as IRQ handler for PCIe instance 1.
*/
ISR(Pcie_Ip_PCIE_1_DmaIRQHandler)
{
    Pcie_Ip_DmaIRQHandler(1U);
}
#endif
#endif



#define PCIE_STOP_SEC_CODE
#include "Pcie_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */


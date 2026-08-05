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

#ifndef PCIE_IP_IRQ_H
#define PCIE_IP_IRQ_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDES
==================================================================================================*/

#include "Mcal.h"
#include "Pcie_Types.h"
#include "Pcie_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Pcie_Ip_Irq.h
* @requirements   BSW00374, BSW00379, BSW00318
* @implements     DESIGN001, DESIGN002
*/
#define PCIE_IP_IRQ_VENDOR_ID                    43
#define PCIE_IP_IRQ_AR_RELEASE_MAJOR_VERSION     4
#define PCIE_IP_IRQ_AR_RELEASE_MINOR_VERSION     4
#define PCIE_IP_IRQ_AR_RELEASE_REVISION_VERSION  0
#define PCIE_IP_IRQ_SW_MAJOR_VERSION             4
#define PCIE_IP_IRQ_SW_MINOR_VERSION             0
#define PCIE_IP_IRQ_SW_PATCH_VERSION             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Pcie_Ip_Irq.h file and Mcal.h header file are of the same Autosar version */
    #if ((PCIE_IP_IRQ_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (PCIE_IP_IRQ_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Pcie_Ip_Irq.h.h and Mcal.h are different"
    #endif
#endif

/* Check if current file and Pcie types header file are of the same vendor */
#if (PCIE_IP_IRQ_VENDOR_ID != PCIE_TYPES_VENDOR_ID)
#error "Pcie_Ip_Irq.h and Pcie_Types.h have different vendor ids"
#endif
/* Check if current file and Pcie types header file are of the same Autosar version */
#if ((PCIE_IP_IRQ_AR_RELEASE_MAJOR_VERSION    != PCIE_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_IP_IRQ_AR_RELEASE_MINOR_VERSION    != PCIE_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_IP_IRQ_AR_RELEASE_REVISION_VERSION != PCIE_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pcie_Ip_Irq.h and Pcie_Types.h are different"
#endif
/* Check if current file and Pcie types header file are of the same software version */
#if ((PCIE_IP_IRQ_SW_MAJOR_VERSION != PCIE_TYPES_SW_MAJOR_VERSION) || \
     (PCIE_IP_IRQ_SW_MINOR_VERSION != PCIE_TYPES_SW_MINOR_VERSION) || \
     (PCIE_IP_IRQ_SW_PATCH_VERSION != PCIE_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Pcie_Ip_Irq.h and Pcie_Types.h are different"
#endif

/* Check if current file and Pcie Ip config header file are of the same vendor */
#if (PCIE_IP_IRQ_VENDOR_ID != PCIE_IP_CFG_VENDOR_ID)
#error "Pcie_Ip_Irq.h and Pcie_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Pcie Ip config header file are of the same Autosar version */
#if ((PCIE_IP_IRQ_AR_RELEASE_MAJOR_VERSION    != PCIE_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_IP_IRQ_AR_RELEASE_MINOR_VERSION    != PCIE_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_IP_IRQ_AR_RELEASE_REVISION_VERSION != PCIE_IP_CFG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pcie_Ip_Irq.h and Pcie_Ip_Cfg.h are different"
#endif
/* Check if current file and Pcie Ip config header file are of the same software version */
#if ((PCIE_IP_IRQ_SW_MAJOR_VERSION != PCIE_IP_CFG_SW_MAJOR_VERSION) || \
     (PCIE_IP_IRQ_SW_MINOR_VERSION != PCIE_IP_CFG_SW_MINOR_VERSION) || \
     (PCIE_IP_IRQ_SW_PATCH_VERSION != PCIE_IP_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Pcie_Ip_Irq.h and Pcie_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
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


#ifdef PCIE_IP_0_ENABLED
#if (PCIE_IP_0_ENABLED == STD_ON)
ISR(Pcie_Ip_PCIE_0_DmaIRQHandler);
#endif
#endif

#ifdef PCIE_IP_1_ENABLED
#if (PCIE_IP_1_ENABLED == STD_ON)
ISR(Pcie_Ip_PCIE_1_DmaIRQHandler);
#endif
#endif



#ifdef __cplusplus
}
#endif

#endif /* PCIE_IP_IRQ_H */

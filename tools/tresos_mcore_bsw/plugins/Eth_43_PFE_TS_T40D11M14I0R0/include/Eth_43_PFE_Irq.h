/**
 *  @file    Eth_43_PFE_Irq.h
 *
 *  @brief AUTOSAR Eth driver interrupt handlers prototypes
 *  @details Prototypes of interrupt handling routines for the Ethernet driver.
 *
 *  @addtogroup ETH_43_PFE_DRIVER
 *  @{
 */
/*==================================================================================================
 *  Project              : AUTOSAR 4.4 MCAL
 *  Platform             : CORTEXM
 *  Peripheral           : PFE
 *  Dependencies         : none
 *
 *  Autosar Version      : 4.4.0
 *  Autosar Revision     : ASR_REL_4_4_REV_0000
 *  Autosar Conf.Variant :
 *  SW Version           : 1.4.0
 *  Build Version        : PFE-DRV_S32G_M7_MCAL_1.4.0_D2405_ASR_REL_4_4_REV_0000_20240528
 *
 *  (c) Copyright 2006-2016 Freescale Semiconductor, Inc.
 *      Copyright 2017-2022 NXP
 *
 *  NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only
 *  be used strictly in accordance with the applicable license terms. By
 *  expressly accepting such terms or by downloading, installing, activating
 *  and/or otherwise using the software, you are agreeing that you have read,
 *  and that you agree to comply with and are bound by, such license terms. If
 *  you do not agree to be bound by the applicable license terms, then you may
 *  not retain, install, activate or otherwise use the software.
 *  <<< PFE Restricted Software >>>
 *
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
#ifndef ETH_43_PFE_IRQ_H
#define ETH_43_PFE_IRQ_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                     FILE VERSION CHECK
==================================================================================================*/
#ifdef PFE_SRC_VERSION_CHECK
    #if (PFE_SRC_VERSION_CHECK != 43140440)
        #error "This header file was included from incompatible source file (different SW version)"
    #endif
#else
    #define PFE_SRC_VERSION_CHECK 43140440
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "pfe_cfg.h"

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
#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
#if (TRUE == ETH_43_PFE_USINGHIF0)
extern ISR(Eth_43_PFE_HifIrqHdlr_0);
#endif /* ETH_43_PFE_USINGHIF0 */
#if (TRUE == ETH_43_PFE_USINGHIF1)
extern ISR(Eth_43_PFE_HifIrqHdlr_1);
#endif /* ETH_43_PFE_USINGHIF1 */
#if (TRUE == ETH_43_PFE_USINGHIF2)
extern ISR(Eth_43_PFE_HifIrqHdlr_2);
#endif /* ETH_43_PFE_USINGHIF2 */
#if (TRUE == ETH_43_PFE_USINGHIF3)
extern ISR(Eth_43_PFE_HifIrqHdlr_3);
#endif /* ETH_43_PFE_USINGHIF3 */
#if (TRUE == ETH_43_PFE_USINGHIF_NOCPY)
extern ISR(Eth_43_PFE_HifNoCpyIrqHdlr);
#endif /* ETH_43_PFE_USINGHIF_NOCPY */
#endif /* PFE_CFG_HIF_IRQ_ENABLED */
#if (TRUE == PFE_CFG_BMU_IRQ_ENABLED)
extern ISR(Eth_43_PFE_BmuIrqHdlr);
#endif /* PFE_CFG_BMU_IRQ_ENABLED */

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* ETH_43_PFE_IRQ_H */

/** @} */

/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : TMU
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
*   Copyright 2020-2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef TMU_IP_IRQ_H
#define TMU_IP_IRQ_H

/**
*   @file
*
*   @addtogroup tmu_ip Tmu IPL
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

#include "StandardTypes.h"
#include "Tmu_Ip_CfgDefines.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define TMU_IP_VENDOR_ID_IRQ                      43
#define TMU_IP_AR_RELEASE_MAJOR_VERSION_IRQ       4
#define TMU_IP_AR_RELEASE_MINOR_VERSION_IRQ       4
#define TMU_IP_AR_RELEASE_REVISION_VERSION_IRQ    0
#define TMU_IP_SW_MAJOR_VERSION_IRQ               4
#define TMU_IP_SW_MINOR_VERSION_IRQ               0
#define TMU_IP_SW_PATCH_VERSION_IRQ               2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Tmu_Ip_Cfg_Defines configuration header file are of the same vendor */
#if (TMU_IP_VENDOR_ID_IRQ != TMU_IP_VENDOR_ID_CFGDEFINES)
#error "Tmu_Ip_Irq.h and Tmu_Ip_Cfg_Defines.h have different vendor ids"
#endif

#if ((TMU_IP_AR_RELEASE_MAJOR_VERSION_IRQ    != TMU_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (TMU_IP_AR_RELEASE_MINOR_VERSION_IRQ    != TMU_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (TMU_IP_AR_RELEASE_REVISION_VERSION_IRQ != TMU_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES))
#error "AutoSar Version Numbers of Tmu_Ip_Irq.h and Tmu_Ip_Cfg_Defines.h are different"
#endif

#if ((TMU_IP_SW_MAJOR_VERSION_IRQ != TMU_IP_SW_MAJOR_VERSION_CFGDEFINES) || \
     (TMU_IP_SW_MINOR_VERSION_IRQ != TMU_IP_SW_MINOR_VERSION_CFGDEFINES) || \
     (TMU_IP_SW_PATCH_VERSION_IRQ != TMU_IP_SW_PATCH_VERSION_CFGDEFINES))
#error "Software Version Numbers of Tmu_Ip_Irq.h and Tmu_Ip_Cfg_Defines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Tmu_Ip_Irq.h file and StandardTypes.h file are of the same Autosar version */
    #if ((TMU_IP_AR_RELEASE_MAJOR_VERSION_IRQ != STD_AR_RELEASE_MAJOR_VERSION) || \
         (TMU_IP_AR_RELEASE_MINOR_VERSION_IRQ != STD_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Tmu_Ip_Irq.h and StandardTypes.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#define THERMAL_START_SEC_CODE
#include "Thermal_MemMap.h"

void Tmu_IRQHandler(const uint32 Instance
#if (STD_ON == TMU_IP_HAS_SEPARATED_IRQ)
                  , const boolean FromSeparatedCriticalIrq
#endif /* (STD_ON == TMU_IP_HAS_SEPARATED_IRQ) */
                   );

ISR(Tmu_Isr);
#if (STD_ON == TMU_IP_HAS_SEPARATED_IRQ)

ISR(Tmu_Critical_Isr);
#endif /* (STD_ON == TMU_IP_HAS_SEPARATED_IRQ) */


#define THERMAL_STOP_SEC_CODE
#include "Thermal_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /*TMU_IP_IRQ_H */


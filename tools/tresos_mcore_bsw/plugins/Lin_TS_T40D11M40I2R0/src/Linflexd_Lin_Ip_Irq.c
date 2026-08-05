/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : LINFLEXD
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
*   (c) Copyright 2020-2023 NXP Semiconductors
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

/**
*   @file Linflexd_Lin_Ip_Irq.c
*    @implements    Linflexd_Lin_Ip_Irq.c_Artifact
*
*   @internal 
*   @addtogroup LINFLEXD_IP
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
#include "Linflexd_Lin_Ip.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LINFLEXD_LIN_IP_IRQ_VENDOR_ID_C                      43
#define LINFLEXD_LIN_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define LINFLEXD_LIN_IP_IRQ_AR_RELEASE_MINOR_VERSION_C       4
#define LINFLEXD_LIN_IP_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define LINFLEXD_LIN_IP_IRQ_SW_MAJOR_VERSION_C               4
#define LINFLEXD_LIN_IP_IRQ_SW_MINOR_VERSION_C               0
#define LINFLEXD_LIN_IP_IRQ_SW_PATCH_VERSION_C               2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Linflexd_Lin_Ip header file are of the same Autosar version */
#if (LINFLEXD_LIN_IP_IRQ_VENDOR_ID_C != LINFLEXD_LIN_IP_VENDOR_ID)
    #error "Linflexd_Lin_Ip_Irq.c and Linflexd_Lin_Ip.h have different vendor ids"
#endif
#if ((LINFLEXD_LIN_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != LINFLEXD_LIN_IP_AR_RELEASE_MAJOR_VERSION) || \
     (LINFLEXD_LIN_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != LINFLEXD_LIN_IP_AR_RELEASE_MINOR_VERSION) || \
     (LINFLEXD_LIN_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != LINFLEXD_LIN_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Linflexd_Lin_Ip_Irq.c and Linflexd_Lin_Ip.h are different"
#endif
/* Check if current file and Linflexd_Lin_Ip header file are of the same Software version */
#if ((LINFLEXD_LIN_IP_IRQ_SW_MAJOR_VERSION_C != LINFLEXD_LIN_IP_SW_MAJOR_VERSION) || \
     (LINFLEXD_LIN_IP_IRQ_SW_MINOR_VERSION_C != LINFLEXD_LIN_IP_SW_MINOR_VERSION) || \
     (LINFLEXD_LIN_IP_IRQ_SW_PATCH_VERSION_C != LINFLEXD_LIN_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Linflexd_Lin_Ip_Irq.c and Linflexd_Lin_Ip.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"

#if (LINFLEXD_INSTANCE_COUNT > 0U)
ISR(LIN_LINFLEXD0_IRQHandler);
#endif /* if (LINFLEXD_INSTANCE_COUNT > 0U) */

#if (LINFLEXD_INSTANCE_COUNT > 1U)
ISR(LIN_LINFLEXD1_IRQHandler);
#endif /* if (LINFLEXD_INSTANCE_COUNT > 1U) */

#if (LINFLEXD_INSTANCE_COUNT > 2U)
ISR(LIN_LINFLEXD2_IRQHandler);
#endif /* if (LINFLEXD_INSTANCE_COUNT > 2U) */

#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"

#if (LINFLEXD_INSTANCE_COUNT > 0U)
ISR(LIN_LINFLEXD0_IRQHandler)
{
    Linflexd_Lin_Ip_TxRx_IRQHandler(0U);
    Linflexd_Lin_Ip_Error_IRQHandler(0U);
}
#endif /* if (LINFLEXD_INSTANCE_COUNT > 0U) */

#if (LINFLEXD_INSTANCE_COUNT > 1U)
ISR(LIN_LINFLEXD1_IRQHandler)
{
    Linflexd_Lin_Ip_TxRx_IRQHandler(1U);
    Linflexd_Lin_Ip_Error_IRQHandler(1U);
}
#endif /* if (LINFLEXD_INSTANCE_COUNT > 1U) */

#if (LINFLEXD_INSTANCE_COUNT > 2U)
ISR(LIN_LINFLEXD2_IRQHandler)
{
    Linflexd_Lin_Ip_TxRx_IRQHandler(2U);
    Linflexd_Lin_Ip_Error_IRQHandler(2U);
}
#endif /* if (LINFLEXD_INSTANCE_COUNT > 2U) */

#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

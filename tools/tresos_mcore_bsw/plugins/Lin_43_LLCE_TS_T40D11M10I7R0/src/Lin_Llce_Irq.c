/**
*   @file    Lin_Llce_Irq.c
*   @implements Lin_Llce_Irq.c_Artifact
*   @version 1.0.7
*
*   @brief   AUTOSAR Lin - File used by LIN that contain the ISRs.
*   @details This file contains the ISR functions used to serve the LIN interrupts.
*
*   @addtogroup LIN_LLCE
*   @{
*/
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : LLCE
*   Dependencies         : 
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 1.0.7
*   Build Version        : S32_RTD_1_0_7_D2909_ASR_REL_4_4_REV_0000_20230630
*
*   Copyright 2006-2016 Freescale Semiconductor, Inc.
*   Copyright 2020-2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly in
*   accordance with the applicable license terms.
*   By expressly accepting such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to comply with and are bound
*   by, such license terms.  If you do not agree to be bound by the applicable license terms, then you
*   may not retain, install, activate or otherwise use the software.
==================================================================================================*/
/*==================================================================================================
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
/**
* @file           Lin_Irq.c
*/
#include "Lin_43_LLCE.h"
#include "Lin_Llce.h"
#include "Llce_InterfaceCore2Core.h"
#include "Llce_InterfaceLinTypes.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Lin_Irq.c
*/
#define LIN_LLCE_IRQ_VENDOR_ID_C                    43
#define LIN_LLCE_IRQ_AR_RELEASE_MAJOR_VERSION_C     4
#define LIN_LLCE_IRQ_AR_RELEASE_MINOR_VERSION_C     4
#define LIN_LLCE_IRQ_AR_RELEASE_REVISION_VERSION_C  0
#define LIN_LLCE_IRQ_SW_MAJOR_VERSION_C             1
#define LIN_LLCE_IRQ_SW_MINOR_VERSION_C             0
#define LIN_LLCE_IRQ_SW_PATCH_VERSION_C             7

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Lin header file are of the same vendor */
#if (LIN_LLCE_IRQ_VENDOR_ID_C != LIN_43_LLCE_VENDOR_ID)
    #error "Lin_Irq.c and Lin_43_LLCE.h have different vendor ids"
#endif
/* Check if current file and Lin_43_LLCE.h header file are of the same Autosar version */
#if (((LIN_LLCE_IRQ_AR_RELEASE_MAJOR_VERSION_C   != LIN_43_LLCE_AR_RELEASE_MAJOR_VERSION) || \
      (LIN_LLCE_IRQ_AR_RELEASE_MINOR_VERSION_C    != LIN_43_LLCE_AR_RELEASE_MINOR_VERSION)) || \
     (LIN_LLCE_IRQ_AR_RELEASE_REVISION_VERSION_C != LIN_43_LLCE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_Irq.c and Lin_43_LLCE.h are different"
#endif
/* Check if current file and Lin_43_LLCE.h header file are of the same Software version */
#if ((LIN_LLCE_IRQ_SW_MAJOR_VERSION_C != LIN_43_LLCE_SW_MAJOR_VERSION) || \
     (LIN_LLCE_IRQ_SW_MINOR_VERSION_C != LIN_43_LLCE_SW_MINOR_VERSION) || \
     (LIN_LLCE_IRQ_SW_PATCH_VERSION_C != LIN_43_LLCE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_Irq.c and Lin_43_LLCE.h are different"
#endif
/* Check if current file and Lin_Llce header file are of the same vendor */
#if (LIN_LLCE_IRQ_VENDOR_ID_C != LIN_LLCE_VENDOR_ID)
    #error "Lin_Irq.c and Lin_Llce.h have different vendor ids"
#endif
/* Check if current file and Lin_Llce header file are of the same Autosar version */
#if ((LIN_LLCE_IRQ_AR_RELEASE_MAJOR_VERSION_C    != LIN_LLCE_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_LLCE_IRQ_AR_RELEASE_MINOR_VERSION_C    != LIN_LLCE_AR_RELEASE_MINOR_VERSION) || \
     (LIN_LLCE_IRQ_AR_RELEASE_REVISION_VERSION_C != LIN_LLCE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_Irq.c and Lin_Llce.h are different"
#endif
/* Check if current file and Lin_Llce header file are of the same Software version */
#if ((LIN_LLCE_IRQ_SW_MAJOR_VERSION_C != LIN_LLCE_SW_MAJOR_VERSION) || \
     (LIN_LLCE_IRQ_SW_MINOR_VERSION_C != LIN_LLCE_SW_MINOR_VERSION) || \
     (LIN_LLCE_IRQ_SW_PATCH_VERSION_C != LIN_LLCE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_Irq.c and Lin_Llce.h are different"
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


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define LIN_43_LLCE_START_SEC_CODE
#include "Lin_43_LLCE_MemMap.h"

ISR(Lin_CmdFromLlceIsr);

/**
* @brief   This is the interrupt service routine used for notifications from LLCE.
* @details This is the interrupt service routine used for notifications from LLCE.
*
* @implements Lin_CmdFromLlceIsr_Activity
*
*/
ISR(Lin_CmdFromLlceIsr)
{
    uint8  u8HwCtrl;
    uint32 u32TempFlag;
    uint32 u32IntrStatusFlags;
    uint32 u32IntrEnable;

    /*Read contents of interrupt concentrator register.*/
    u32IntrStatusFlags = Reg_Read32(LLCE_CORE2CORE_HINTC2R);

    u32IntrEnable = Reg_Read32(LLCE_CORE2CORE_HINTC2ER);

    /*Check all bit fields from interrupt concentrator register. */
    for (u8HwCtrl=0; u8HwCtrl < LLCE_LIN_MAXCTRL_COUNT; u8HwCtrl++)
    {
        u32TempFlag = (((uint32)0x1U) << ((uint32)u8HwCtrl));

        /* Check if the value of the concentrator status flag. */
        if (u32TempFlag == (u32IntrStatusFlags & u32TempFlag))
        {
            /* Check if it is a spurious interrupt */
            if (u32TempFlag == (u32IntrEnable & u32TempFlag))
            {
                Lin_Llce_ProcessCmdFromLlce(u8HwCtrl);
              
              	/* Clear the interrupt status flag. */
            	LLCE_TX2HOST_CLEAR_INTERRUPT(u8HwCtrl);
            }
        }
    }
}

#define LIN_43_LLCE_STOP_SEC_CODE
#include "Lin_43_LLCE_MemMap.h"

#ifdef __cplusplus
}
#endif

/*! @} */

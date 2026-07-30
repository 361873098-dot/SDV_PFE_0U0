/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,FTM
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
extern "C"
{
#endif

/**
*   @file    Dma_Ip_Irq.c
*
*   @version 4.0.2
*
*   @brief   AUTOSAR Mcl - Dma Ip driver source file.
*   @details
*
*   @addtogroup DMA_IP_DRIVER DMA IP Driver
*   @{
*/

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Dma_Ip_Cfg.h"
#include "Dma_Ip_Irq.h"
#include "Dma_Ip_Hw_Access.h"
#include "Dma_Ip_Driver_State.h"

#if (STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE)
#include "Dma_Ip_Multicore.h"
#endif /* STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE */

#if (STD_ON == DMA_IP_IS_AVAILABLE)
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DMA_IP_IRQ_VENDOR_ID_C                       43
#define DMA_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C        4
#define DMA_IP_IRQ_AR_RELEASE_MINOR_VERSION_C        4
#define DMA_IP_IRQ_AR_RELEASE_REVISION_VERSION_C     0
#define DMA_IP_IRQ_SW_MAJOR_VERSION_C                4
#define DMA_IP_IRQ_SW_MINOR_VERSION_C                0
#define DMA_IP_IRQ_SW_PATCH_VERSION_C                2

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Dma_Ip_Irq.c file and Dma_Ip_Cfg.h file are of the same vendor */
#if (DMA_IP_IRQ_VENDOR_ID_C != DMA_IP_CFG_VENDOR_ID)
    #error "Dma_Ip_Irq.c and Dma_Ip_Cfg.h have different vendor ids"
#endif

/* Check if Dma_Ip_Irq.c file and Dma_Ip_Cfg.h file are of the same Autosar version */
#if ((DMA_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != DMA_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != DMA_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dma_Ip_Irq.c and Dma_Ip_Cfg.h are different"
#endif

/* Check if Dma_Ip_Irq.c file and Dma_Ip_Cfg.h file are of the same Software version */
#if ((DMA_IP_IRQ_SW_MAJOR_VERSION_C != DMA_IP_CFG_SW_MAJOR_VERSION) || \
     (DMA_IP_IRQ_SW_MINOR_VERSION_C != DMA_IP_CFG_SW_MINOR_VERSION) || \
     (DMA_IP_IRQ_SW_PATCH_VERSION_C != DMA_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Ip_Irq.c and Dma_Ip_Cfg.h are different"
#endif

/* Check if Dma_Ip_Irq.c file and Dma_Ip_Irq.h file are of the same vendor */
#if (DMA_IP_IRQ_VENDOR_ID_C != DMA_IP_IRQ_VENDOR_ID)
    #error "Dma_Ip_Irq.c and Dma_Ip_Irq.h have different vendor ids"
#endif

/* Check if Dma_Ip_Irq.c file and Dma_Ip_Irq.h file are of the same Autosar version */
#if ((DMA_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != DMA_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != DMA_IP_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dma_Ip_Irq.c and Dma_Ip_Irq.h are different"
#endif

/* Check if Dma_Ip_Irq.c file and Dma_Ip_Irq.h file are of the same Software version */
#if ((DMA_IP_IRQ_SW_MAJOR_VERSION_C != DMA_IP_IRQ_SW_MAJOR_VERSION) || \
     (DMA_IP_IRQ_SW_MINOR_VERSION_C != DMA_IP_IRQ_SW_MINOR_VERSION) || \
     (DMA_IP_IRQ_SW_PATCH_VERSION_C != DMA_IP_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Ip_Irq.c and Dma_Ip_Irq.h are different"
#endif

/* Check if Dma_Ip_Irq.c file and Dma_Ip_Hw_Access.h file are of the same vendor */
#if (DMA_IP_IRQ_VENDOR_ID_C != DMA_IP_HW_ACCESS_VENDOR_ID)
    #error "Dma_Ip_Irq.c and Dma_Ip_Hw_Access.h have different vendor ids"
#endif

/* Check if Dma_Ip_Irq.c file and Dma_Ip_Hw_Access.h file are of the same Autosar version */
#if ((DMA_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != DMA_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != DMA_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dma_Ip_Irq.c and Dma_Ip_Hw_Access.h are different"
#endif

/* Check if Dma_Ip_Irq.c file and Dma_Ip_Hw_Access.h file are of the same Software version */
#if ((DMA_IP_IRQ_SW_MAJOR_VERSION_C != DMA_IP_HW_ACCESS_SW_MAJOR_VERSION) || \
     (DMA_IP_IRQ_SW_MINOR_VERSION_C != DMA_IP_HW_ACCESS_SW_MINOR_VERSION) || \
     (DMA_IP_IRQ_SW_PATCH_VERSION_C != DMA_IP_HW_ACCESS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Ip_Irq.c and Dma_Ip_Hw_Access.h are different"
#endif

/* Check if Dma_Ip_Irq.c file and Dma_Ip_Driver_State.h file are of the same vendor */
#if (DMA_IP_IRQ_VENDOR_ID_C != DMA_IP_DRIVER_STATE_VENDOR_ID)
    #error "Dma_Ip_Irq.c and Dma_Ip_Driver_State.h have different vendor ids"
#endif

/* Check if Dma_Ip_Irq.c file and Dma_Ip_Driver_State.h file are of the same Autosar version */
#if ((DMA_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_DRIVER_STATE_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != DMA_IP_DRIVER_STATE_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != DMA_IP_DRIVER_STATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dma_Ip_Irq.c and Dma_Ip_Driver_State.h are different"
#endif

/* Check if Dma_Ip_Irq.c file and Dma_Ip_Driver_State.h file are of the same Software version */
#if ((DMA_IP_IRQ_SW_MAJOR_VERSION_C != DMA_IP_DRIVER_STATE_SW_MAJOR_VERSION) || \
     (DMA_IP_IRQ_SW_MINOR_VERSION_C != DMA_IP_DRIVER_STATE_SW_MINOR_VERSION) || \
     (DMA_IP_IRQ_SW_PATCH_VERSION_C != DMA_IP_DRIVER_STATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Ip_Irq.c and Dma_Ip_Driver_State.h are different"
#endif

#if (STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE)
/* Check if Dma_Ip_Irq.c file and Dma_Ip_Multicore.h file are of the same vendor */
#if (DMA_IP_IRQ_VENDOR_ID_C != DMA_IP_MULTICORE_VENDOR_ID)
    #error "Dma_Ip_Irq.c and Dma_Ip_Multicore.h have different vendor ids"
#endif

/* Check if Dma_Ip_Irq.c file and Dma_Ip_Multicore.h file are of the same Autosar version */
#if ((DMA_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_MULTICORE_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != DMA_IP_MULTICORE_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != DMA_IP_MULTICORE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dma_Ip_Irq.c and Dma_Ip_Multicore.h are different"
#endif

/* Check if Dma_Ip_Irq.c file and Dma_Ip_Multicore.h file are of the same Software version */
#if ((DMA_IP_IRQ_SW_MAJOR_VERSION_C != DMA_IP_MULTICORE_SW_MAJOR_VERSION) || \
     (DMA_IP_IRQ_SW_MINOR_VERSION_C != DMA_IP_MULTICORE_SW_MINOR_VERSION) || \
     (DMA_IP_IRQ_SW_PATCH_VERSION_C != DMA_IP_MULTICORE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Ip_Irq.c and Dma_Ip_Multicore.h are different"
#endif
#endif /* STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE */

#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"

/*==================================================================================================
 *                                            FUNCTION
==================================================================================================*/
/**
 * @brief This function Dma Irq Dispatcher
 * @details This function that shall Handle DMA interrupt.
 *
 * @param[in]  LocHwVers           Specifies the Logic Hw Version defined by the user.
 * @param[in]  LocHwInst           Specifies the Logic Hw Instance defined by the user.
 *
 * @return void
 *
 * @implements Dma_IrqDispatcher_Activity
 * */
static void Dma_Ch0_Ch15_IrqDispatcher(const uint32 LocHwVers, const uint32 LocHwInst)
{
    uint32 LocHwCh = 0U;
    uint32 chIntStatus = 0U;
    uint16 chIntEnable = 0U;
#if (STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE)
    Dma_Ip_ReturnType MulticoreStatus;
    const Dma_Ip_HwChannelStateType * HwChannelStatePtr = NULL_PTR;
#endif /* STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE */

    for(LocHwCh = 0U; LocHwCh < 16U; LocHwCh++)
    {
        chIntStatus = (uint32)(DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh).reg_CH_INT & DMA_IP_TCD_CH_INT_INT_MASK);
        chIntEnable = (uint16)(DMA_IP_HWV3_TCD_TCD_VALUE(LocHwInst, LocHwCh).reg_CSR & (DMA_IP_TCD_CSR_INTMAJOR_MASK | DMA_IP_TCD_CSR_INTHALF_MASK));
    #if (STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE)
        HwChannelStatePtr = Dma_Ip_GetHwChannelStatePointer(LocHwVers, LocHwInst, LocHwCh);
        if (NULL_PTR != HwChannelStatePtr)
        {
            MulticoreStatus = Dma_Ip_ValidateMultiCoreChannelCall(HwChannelStatePtr->LogicChId->LogicChId);
            if (DMA_IP_STATUS_SUCCESS == MulticoreStatus)
            {
    #endif /* STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE */
                if(0U != chIntStatus)
                {
                    if(0U != chIntEnable)
                    {
                        DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh).reg_CH_INT = DMA_IP_TCD_CH_INT_INT_MASK;
                        Dma_Ip_IntIrqHandler(LocHwVers, LocHwInst, LocHwCh);
                    }
                }
        #if (STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE)
            }
        }
    #endif /* STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE */
    }
}

/**
 * @brief This function Dma Irq Dispatcher
 * @details This function that shall Handle DMA interrupt.
 *
 * @param[in]  LocHwVers           Specifies the Logic Hw Version defined by the user.
 * @param[in]  LocHwInst           Specifies the Logic Hw Instance defined by the user.
 *
 * @return void
 *
 * */
static void Dma_Ch16_Ch31_IrqDispatcher(const uint32 LocHwVers, const uint32 LocHwInst)
{
    uint32 LocHwCh = 0U;
    uint32 chIntStatus = 0U;
    uint16 chIntEnable = 0U;
#if (STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE)
    Dma_Ip_ReturnType MulticoreStatus;
    const Dma_Ip_HwChannelStateType * HwChannelStatePtr = NULL_PTR;
#endif /* STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE */

    for(LocHwCh = 16U; LocHwCh < 32U; LocHwCh++)
    {
        chIntStatus = (uint32)(DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh).reg_CH_INT & DMA_IP_TCD_CH_INT_INT_MASK);
        chIntEnable = (uint16)(DMA_IP_HWV3_TCD_TCD_VALUE(LocHwInst, LocHwCh).reg_CSR & (DMA_IP_TCD_CSR_INTMAJOR_MASK | DMA_IP_TCD_CSR_INTHALF_MASK));
    #if (STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE)
        HwChannelStatePtr = Dma_Ip_GetHwChannelStatePointer(LocHwVers, LocHwInst, LocHwCh);
        if (NULL_PTR != HwChannelStatePtr)
        {
            MulticoreStatus = Dma_Ip_ValidateMultiCoreChannelCall(HwChannelStatePtr->LogicChId->LogicChId);
            if (DMA_IP_STATUS_SUCCESS == MulticoreStatus)
            {
    #endif /* STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE */
                if(0U != chIntStatus)
                {
                    if(0U != chIntEnable)
                    {
                        DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh).reg_CH_INT = DMA_IP_TCD_CH_INT_INT_MASK;
                        Dma_Ip_IntIrqHandler(LocHwVers, LocHwInst, LocHwCh);
                    }
                }
    #if (STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE)
            }
        }
    #endif /* STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE */
    }
}

ISR(Dma0_Ch0_Ch15_IrqHandler)
{
    /* Dma0 Handler for channel 0 to channel 15 */
    Dma_Ch0_Ch15_IrqDispatcher(3U, 0U);
}
ISR(Dma0_Ch16_Ch31_IrqHandler)
{
    /* Dma0 Handler for channel 16 to channel 31 */
    Dma_Ch16_Ch31_IrqDispatcher(3U, 0U);
}
ISR(Dma1_Ch0_Ch15_IrqHandler)
{
    /* Dma1 Handler for channel 0 to channel 15 */
    Dma_Ch0_Ch15_IrqDispatcher(3U, 1U);
}
ISR(Dma1_Ch16_Ch31_IrqHandler)
{
    /* Dma1 Handler for channel 16 to channel 31 */
    Dma_Ch16_Ch31_IrqDispatcher(3U, 1U);
}

/* CHANNEL ERROR INTERRUPTS */

/**
* @brief This function Dma Error Irq Dispatcher
* @details This function that shall Handle DMA interrupt.
*
* @param[in] LocHwVers Specifies the Logic Hw Version defined by the user.
* @param[in] LocHwInst Specifies the Logic Hw Instance defined by the user.
*
* @return void
*
* */
static void Dma_Ch0_Ch31_ErrorIrqDispatcher(const uint32 LocHwVers, const uint32 LocHwInst)
{
    uint32 LocHwCh = 0U;
    uint32 chErrStatus = 0U;
    uint32 chErrEnable = 0U;
#if (STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE)
    Dma_Ip_ReturnType MulticoreStatus;
    const Dma_Ip_HwChannelStateType * HwChannelStatePtr = NULL_PTR;
#endif /* STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE */

    for(LocHwCh = 0U; LocHwCh < 32U; LocHwCh++)
    {
        chErrStatus = (uint32)(DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh).reg_CH_ES & DMA_IP_TCD_CH_ES_ERR_MASK);
        chErrEnable = (uint32)(DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh).reg_CH_CSR & DMA_IP_TCD_CH_CSR_EEI_MASK);
    #if (STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE)
        HwChannelStatePtr = Dma_Ip_GetHwChannelStatePointer(LocHwVers, LocHwInst, LocHwCh);
        if (NULL_PTR != HwChannelStatePtr)
        {
            MulticoreStatus = Dma_Ip_ValidateMultiCoreChannelCall(HwChannelStatePtr->LogicChId->LogicChId);
            if (DMA_IP_STATUS_SUCCESS == MulticoreStatus)
            {
    #endif /* STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE */
                if(0U != chErrStatus)
                {
                    if(0U != chErrEnable)
                    {
                        Dma_Ip_ErrorIrqHandler(LocHwVers, LocHwInst, LocHwCh);
                        /* The event status flag is cleared after execution of the irq handler sue to requirement exception. */
                        DMA_IP_HWV3_TCD_CH_VALUE(LocHwInst, LocHwCh).reg_CH_ES = DMA_IP_TCD_CH_ES_ERR_MASK;
                    }
                }
    #if (STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE)
            }
        }
    #endif /* STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE */
    }
}

ISR(Dma0_Error_IrqHandler)
{
    /* Dma Error Handler for channel 0 to channel 31 */
    Dma_Ch0_Ch31_ErrorIrqDispatcher(3U, 0U);
}
ISR(Dma1_Error_IrqHandler)
{
    /* Dma Error Handler for channel 0 to channel 31 */
    Dma_Ch0_Ch31_ErrorIrqDispatcher(3U, 1U);
}

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

#endif /* #if (STD_ON == DMA_IP_IS_AVAILABLE) */

/** @} */

#ifdef __cplusplus
}
#endif
/*******************************************************************************
 * EOF
 ******************************************************************************/

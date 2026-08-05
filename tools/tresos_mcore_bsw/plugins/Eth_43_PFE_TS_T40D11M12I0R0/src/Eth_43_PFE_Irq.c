/**
 *  @file    Eth_43_PFE_Irq.c
 *
 *  @brief    AUTOSAR Eth driver interrupt handlers
 *  @details  Implementation of interrupt handling routines for the Ethernet
 *            Driver.
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
 *  SW Version           : 1.2.0
 *  Build Version        : PFE-DRV_S32G_M7_MCAL_1.2.0_D2307_ASR_REL_4_4_REV_0000_20230728
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

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43120440

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "pfe_cfg.h"
#include "Eth_43_PFE.h" /* Includes also Eth_GeneralTypes.h, Eth_43_PFE_Cfg.h,
                    Eth_43_PFE_ComStack_Types.h, Dem.h, Det.h and Mcal.h */
#include "Eth_PFE_LLD.h"     /* LowLevelDriver API */
#include "Eth_43_PFE_Irq.h"     /* Own interface */
#include "oal_irq.h"            /* Callbacks */
#include "pfe_cbus.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_AR_RELEASE_MAJOR_VERSION_C       4
#define ETH_AR_RELEASE_MINOR_VERSION_C       4

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if STD_ON == ETH_43_PFE_DEM_EVENT_DETECT
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        /* Check if current file and Dem header file are of the same version */
        #if ((ETH_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
             (ETH_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Eth_43_PFE_Irq.c and Dem.h are different"
        #endif
    #endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and DET header file are of the same version */
    #if (ETH_43_PFE_DEV_ERROR_DETECT == STD_ON)
        #if ((ETH_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (ETH_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Eth_43_PFE_Irq.c and Det.h are different"
        #endif
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
#define ETH_43_PFE_START_SEC_CONST_32
#include "Eth_43_PFE_MemMap.h"
static const addr_t cbus_hif_int_en_var_addr[5] = 
{
    PFE_CFG_CBUS_PHYS_BASE_ADDR_CPU + CBUS_HIF_BASE_ADDR + HIF_CHn_INT_EN(0),
    PFE_CFG_CBUS_PHYS_BASE_ADDR_CPU + CBUS_HIF_BASE_ADDR + HIF_CHn_INT_EN(1),
    PFE_CFG_CBUS_PHYS_BASE_ADDR_CPU + CBUS_HIF_BASE_ADDR + HIF_CHn_INT_EN(2),
    PFE_CFG_CBUS_PHYS_BASE_ADDR_CPU + CBUS_HIF_BASE_ADDR + HIF_CHn_INT_EN(3),
    PFE_CFG_CBUS_PHYS_BASE_ADDR_CPU + CBUS_HIF_NOCPY_BASE_ADDR + HIF_NOCPY_INT_EN
};

static const addr_t cbus_hif_int_src_var_addr[5] = 
{
    PFE_CFG_CBUS_PHYS_BASE_ADDR_CPU + CBUS_HIF_BASE_ADDR + HIF_CHn_INT_SRC(0),
    PFE_CFG_CBUS_PHYS_BASE_ADDR_CPU + CBUS_HIF_BASE_ADDR + HIF_CHn_INT_SRC(1),
    PFE_CFG_CBUS_PHYS_BASE_ADDR_CPU + CBUS_HIF_BASE_ADDR + HIF_CHn_INT_SRC(2),
    PFE_CFG_CBUS_PHYS_BASE_ADDR_CPU + CBUS_HIF_BASE_ADDR + HIF_CHn_INT_SRC(3),
    PFE_CFG_CBUS_PHYS_BASE_ADDR_CPU + CBUS_HIF_NOCPY_BASE_ADDR + HIF_NOCPY_INT_SRC
};
#define ETH_43_PFE_STOP_SEC_CONST_32
#include "Eth_43_PFE_MemMap.h"
#endif

/*==================================================================================================
*                                      LOCAL VARIABLES
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
#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#if ((TRUE == PFE_CFG_HIF_IRQ_ENABLED) || (TRUE == PFE_CFG_BMU_IRQ_ENABLED))
static inline bool_t oal_irq_check_driver_init_status(void);
#endif
#if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
static inline bool_t oal_irq_detect_hif_spurious_interrupt(oal_irq_idx_t idx);
static inline void oal_irq_clear_hif_interrupt_status_flag(const addr_t int_src_var_addr);
#endif
#if (TRUE == PFE_CFG_BMU_IRQ_ENABLED)
static inline void oal_irq_detect_handle_bmu_spurious_interrupt(bool_t *bDetectSpuriousIsrBmu1, bool_t *bDetectSpuriousIsrBmu2);
static inline void oal_irq_clear_bmu_interrupt_status_flag(void);
#endif

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#if ((TRUE == PFE_CFG_HIF_IRQ_ENABLED) || (TRUE == PFE_CFG_BMU_IRQ_ENABLED))
/* Check whether driver was initialized successfully or not.
   When running multiple instances, we will check whether IP-ready is TRUE or not;
   Because we have interrupts to handle RPCs */
static inline bool_t oal_irq_check_driver_init_status(void)
{
    bool_t bInitStatus;
#ifndef PFE_CFG_MULTI_INSTANCE_SUPPORT
    uint8 u8CtrlCount;
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */

#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
    bInitStatus = (uint32_t)Local_Macro_hal_ip_ready_get();
#else
    bInitStatus = TRUE;
    for (u8CtrlCount = 0U; u8CtrlCount < (uint8)ETH_43_PFE_NUM_CONTROLLER_CFG; u8CtrlCount++)
    {
        if (ETH_STATE_UNINIT == Eth_43_PFE_CtrlState[u8CtrlCount])
        {
            bInitStatus = FALSE;
            break;
        }
    }
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */

    return bInitStatus;
}
#endif

#if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
/* Check whether hif interrupts are spurious interrupts or not */
static inline bool_t oal_irq_detect_hif_spurious_interrupt(oal_irq_idx_t idx)
{
    bool_t bRet = FALSE;
    uint32 int_en;
    uint32 int_src;

    int_en = hal_read32(cbus_hif_int_en_var_addr[idx]);
    int_src = hal_read32(cbus_hif_int_src_var_addr[idx]);

    if (0U == (int_en & int_src))
    {
        bRet = TRUE;
    }
    return bRet;
}

/* Clear interrupt status flag for hif */
static inline void oal_irq_clear_hif_interrupt_status_flag(const addr_t int_src_var_addr)
{
    uint32 interrupt_src;

    /* Get interrupt status flag */
    interrupt_src = hal_read32(int_src_var_addr);
    /* Write 1 to clear */
    hal_write32(interrupt_src, int_src_var_addr);
}
#endif

#if (TRUE == PFE_CFG_BMU_IRQ_ENABLED)
/* Check whether the bmu interrupts are spurious interrupts or not.
   If spurious interrupts are detected, interrupt status flags will be cleared */
static inline void oal_irq_detect_handle_bmu_spurious_interrupt(bool_t *bDetectSpuriousIsrBmu1, bool_t *bDetectSpuriousIsrBmu2)
{
    uint32 int_en;
    uint32 int_src;

    int_en = hal_read32(PFE_CFG_CBUS_PHYS_BASE_ADDR_CPU + CBUS_BMU1_BASE_ADDR + BMU_INT_ENABLE);
    int_src = hal_read32(PFE_CFG_CBUS_PHYS_BASE_ADDR_CPU + CBUS_BMU1_BASE_ADDR + BMU_INT_SRC);
    if (0U == (int_en & int_src))
    {
        /* Write 1 to clear */
        hal_write32(int_src, PFE_CFG_CBUS_PHYS_BASE_ADDR_CPU + CBUS_BMU1_BASE_ADDR + BMU_INT_SRC);
        *bDetectSpuriousIsrBmu1 = TRUE;
    }

    int_en = hal_read32(PFE_CFG_CBUS_PHYS_BASE_ADDR_CPU + CBUS_BMU2_BASE_ADDR + BMU_INT_ENABLE);
    int_src = hal_read32(PFE_CFG_CBUS_PHYS_BASE_ADDR_CPU + CBUS_BMU2_BASE_ADDR + BMU_INT_SRC);
    if (0U == (int_en & int_src))
    {
        /* Write 1 to clear */
        hal_write32(int_src, PFE_CFG_CBUS_PHYS_BASE_ADDR_CPU + CBUS_BMU2_BASE_ADDR + BMU_INT_SRC);
        *bDetectSpuriousIsrBmu2 = TRUE;
    }
}

/* Clear interrupt status flag for bmu */
static inline void oal_irq_clear_bmu_interrupt_status_flag(void)
{
    uint32 interrupt_src;

    /* Get triggered interrupts of bmu1 */
    interrupt_src = hal_read32(PFE_CFG_CBUS_PHYS_BASE_ADDR_CPU + CBUS_BMU1_BASE_ADDR + BMU_INT_SRC);
    /* Write 1 to clear */
    hal_write32(interrupt_src, PFE_CFG_CBUS_PHYS_BASE_ADDR_CPU + CBUS_BMU1_BASE_ADDR + BMU_INT_SRC);
    /* Get triggered interrupts of bmu2 */
    interrupt_src = hal_read32(PFE_CFG_CBUS_PHYS_BASE_ADDR_CPU + CBUS_BMU2_BASE_ADDR + BMU_INT_SRC);
    /* Write 1 to clear */
    hal_write32(interrupt_src, PFE_CFG_CBUS_PHYS_BASE_ADDR_CPU + CBUS_BMU2_BASE_ADDR + BMU_INT_SRC);
}
#endif

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
/* Either put these handlers to HW vector table or call from AUTOSAR OS ISR handlers */
/**
* @brief        Interrupt handler for HIF0 channel IRQ
* @details      This interrupt is shared between all interfaces that are connected through HIF0.
*               It handles both received frames and Tx confirmations. Also it should handle
*               all other channel interrupts (out of buffers, high Rx watermark), which is not
*               supported in this version.
* @note         In current version this interrupt must be enabled, otherwise receptions and Tx
*               confirmations will not work. This limitation will be removed in next versions.
*/
#if (TRUE == ETH_43_PFE_USINGHIF0)
ISR(Eth_43_PFE_HifIrqHdlr_0)
{
    bool_t bDriverInitStatus;

    bDriverInitStatus = oal_irq_check_driver_init_status();

    if (TRUE == bDriverInitStatus)
    {
        if (FALSE == oal_irq_detect_hif_spurious_interrupt(Eth_43_PFE_IRQ_IDX_HIF0))
        {
            oal_irq_common_handler(Eth_43_PFE_IRQ_IDX_HIF0);
        }
        else
        {
            /* If the spurious interrupt is detected, the ISR shall only clear interrupt status flag and return immediately */
            oal_irq_clear_hif_interrupt_status_flag(cbus_hif_int_src_var_addr[Eth_43_PFE_IRQ_IDX_HIF0]);
        }
    }
    else
    {
        /* If the driver was not initialized, the ISR shall only clear interrupt status flag and return immediately */
        oal_irq_clear_hif_interrupt_status_flag(cbus_hif_int_src_var_addr[Eth_43_PFE_IRQ_IDX_HIF0]);
    }
}
#endif /* ETH_43_PFE_USINGHIF0 */
#if (TRUE == ETH_43_PFE_USINGHIF1)
ISR(Eth_43_PFE_HifIrqHdlr_1)
{
    bool_t bDriverInitStatus;

    bDriverInitStatus = oal_irq_check_driver_init_status();

    if (TRUE == bDriverInitStatus)
    {
        if (FALSE == oal_irq_detect_hif_spurious_interrupt(Eth_43_PFE_IRQ_IDX_HIF1))
        {
            oal_irq_common_handler(Eth_43_PFE_IRQ_IDX_HIF1);
        }
        else
        {
            /* If the spurious interrupt is detected, the ISR shall only clear interrupt status flag and return immediately */
            oal_irq_clear_hif_interrupt_status_flag(cbus_hif_int_src_var_addr[Eth_43_PFE_IRQ_IDX_HIF1]);
        }
    }
    else
    {
        /* If the driver was not initialized, the ISR shall only clear interrupt status flag and return immediately */
        oal_irq_clear_hif_interrupt_status_flag(cbus_hif_int_src_var_addr[Eth_43_PFE_IRQ_IDX_HIF1]);
    }
}
#endif /* ETH_43_PFE_USINGHIF1 */
#if (TRUE == ETH_43_PFE_USINGHIF2)
ISR(Eth_43_PFE_HifIrqHdlr_2)
{
    bool_t bDriverInitStatus;

    bDriverInitStatus = oal_irq_check_driver_init_status();

    if (TRUE == bDriverInitStatus)
    {
        if (FALSE == oal_irq_detect_hif_spurious_interrupt(Eth_43_PFE_IRQ_IDX_HIF2))
        {
            oal_irq_common_handler(Eth_43_PFE_IRQ_IDX_HIF2);
        }
        else
        {
            /* If the spurious interrupt is detected, the ISR shall only clear interrupt status flag and return immediately */
            oal_irq_clear_hif_interrupt_status_flag(cbus_hif_int_src_var_addr[Eth_43_PFE_IRQ_IDX_HIF2]);
        }
    }
    else
    {
        /* If the driver was not initialized, the ISR shall only clear interrupt status flag and return immediately */
        oal_irq_clear_hif_interrupt_status_flag(cbus_hif_int_src_var_addr[Eth_43_PFE_IRQ_IDX_HIF2]);
    }
}
#endif /* ETH_43_PFE_USINGHIF2 */
#if (TRUE == ETH_43_PFE_USINGHIF3)
ISR(Eth_43_PFE_HifIrqHdlr_3)
{
    bool_t bDriverInitStatus;

    bDriverInitStatus = oal_irq_check_driver_init_status();

    if (TRUE == bDriverInitStatus)
    {
        if (FALSE == oal_irq_detect_hif_spurious_interrupt(Eth_43_PFE_IRQ_IDX_HIF3))
        {
            oal_irq_common_handler(Eth_43_PFE_IRQ_IDX_HIF3);
        }
        else
        {
            /* If the spurious interrupt is detected, the ISR shall only clear interrupt status flag and return immediately */
            oal_irq_clear_hif_interrupt_status_flag(cbus_hif_int_src_var_addr[Eth_43_PFE_IRQ_IDX_HIF3]);
        }
    }
    else
    {
        /* If the driver was not initialized, the ISR shall only clear interrupt status flag and return immediately */
        oal_irq_clear_hif_interrupt_status_flag(cbus_hif_int_src_var_addr[Eth_43_PFE_IRQ_IDX_HIF3]);
    }
}
#endif /* ETH_43_PFE_USINGHIF3 */
#if (TRUE == ETH_43_PFE_USINGHIF_NOCPY)
ISR(Eth_43_PFE_HifNoCpyIrqHdlr)
{
    bool_t bDriverInitStatus;

    bDriverInitStatus = oal_irq_check_driver_init_status();

    if (TRUE == bDriverInitStatus)
    {
        if (FALSE == oal_irq_detect_hif_spurious_interrupt(Eth_43_PFE_IRQ_IDX_HIFNOCPY))
        {
            oal_irq_common_handler(Eth_43_PFE_IRQ_IDX_HIFNOCPY);
        }
        else
        {
            /* If the spurious interrupt is detected, the ISR shall only clear interrupt status flag and return immediately */
            oal_irq_clear_hif_interrupt_status_flag(cbus_hif_int_src_var_addr[Eth_43_PFE_IRQ_IDX_HIFNOCPY]);
        }
    }
    else
    {
        /* If the driver was not initialized, the ISR shall only clear interrupt status flag and return immediately */
        oal_irq_clear_hif_interrupt_status_flag(cbus_hif_int_src_var_addr[Eth_43_PFE_IRQ_IDX_HIFNOCPY]);
    }
}
#endif /* ETH_43_PFE_USINGHIF_NOCPY */
#endif /* PFE_CFG_HIF_IRQ_ENABLED */

#if (TRUE == PFE_CFG_BMU_IRQ_ENABLED)
/**
* @brief        Interrupt handler for BMUs
* @details      This interrupt is shared between both BMUs.
* @note         In current version this interrupt shall be enabled. An option to disable this
*               interrupt will be added in next versions.
*/
ISR(Eth_43_PFE_BmuIrqHdlr)
{
    bool_t bDriverInitStatus;
    bool_t bDetectSpuriousIsrBmu1 = FALSE;
    bool_t bDetectSpuriousIsrBmu2 = FALSE;

    bDriverInitStatus = oal_irq_check_driver_init_status();

    if (TRUE == bDriverInitStatus)
    {
        oal_irq_detect_handle_bmu_spurious_interrupt(&bDetectSpuriousIsrBmu1, &bDetectSpuriousIsrBmu2);
        if ((FALSE == bDetectSpuriousIsrBmu1) || (FALSE == bDetectSpuriousIsrBmu2))
        {
            oal_irq_common_handler(Eth_43_PFE_IRQ_IDX_BMU);
        }
    }
    else
    {
        if (TRUE == bDetectBmuInit)
        {
            /* If the driver was not initialized and interrupt has not happened from BMU initialization, the ISR shall only clear interrupt status flag and return immediately */
            oal_irq_clear_bmu_interrupt_status_flag();
        }
        else
        {
            /* In case of interrupt occured during BMU initialization, handling interrupt normally */
            oal_irq_common_handler(Eth_43_PFE_IRQ_IDX_BMU);
        }
    }
}
#endif /* PFE_CFG_BMU_IRQ_ENABLED */

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
/*================================================================================================*/

#ifdef __cplusplus
}
#endif
/** @} */

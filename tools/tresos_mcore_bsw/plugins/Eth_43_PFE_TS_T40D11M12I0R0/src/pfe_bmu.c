/* =========================================================================
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
 *  This code (or certain portions of it) is released for use under license
 *  from Imagination Technologies Limited.
 *  Copyright (c) 2019 Imagination Technologies Limited
 *  Copyright (c) 2020-2021 Imagination Technologies Limited
 *  Copyright 2018-2023 NXP
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
 * ========================================================================= */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43120440

#include "pfe_cfg.h"
#include "oal.h"
#include "hal.h"
#ifdef PFE_CFG_PFE_MASTER
#include "pfe_cbus.h"
#include "pfe_platform_cfg.h"
#include "pfe_bmu.h"
#include "pfe_bmu_csr.h"

/* Configuration check */
#if ((PFE_CFG_BMU1_LMEM_BASEADDR + PFE_CFG_BMU1_LMEM_SIZE) > CBUS_LMEM_SIZE)
    #error BMU1 buffers exceed LMEM capacity
#endif

struct pfe_bmu_tag
{
    addr_t cbus_base_va;        /*    CBUS base virtual address */
    addr_t bmu_base_va;        /*    BMU base address (virtual) */
    addr_t pool_va_offset;    /*    Pre-calculated VA-PA conversion offset */
    addr_t pool_base_va;
    addr_t pool_base_pa;
    addr_t pool_size;
    addr_t bmu_base_offset;    /*    BMU base offset within CBUS space */
    uint32_t buf_size;
};

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
static pfe_bmu_t bmu_instance[PFE_BMU_INSTANCES];
#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/**
 * @brief       BMU ISR
 * @param[in]   bmu The BMU instance
 * @return      EOK if interrupt has been handled
 */
__attribute__((cold)) errno_t pfe_bmu_isr(pfe_bmu_t *bmu)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == bmu))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  Run the low-level ISR to identify and process the interrupt */
        ret = pfe_bmu_cfg_isr(bmu->bmu_base_va, bmu->cbus_base_va);
    }

    return ret;
}

/**
 * @brief       Mask BMU interrupts
 * @param[in]   bmu The BMU instance
 */
void pfe_bmu_irq_mask(pfe_bmu_t *bmu)
{
    pfe_bmu_cfg_irq_mask(bmu->bmu_base_va);
}

/**
 * @brief       Unmask BMU interrupts
 * @param[in]   hif The BMU instance
 */
void pfe_bmu_irq_unmask(pfe_bmu_t *bmu)
{
    pfe_bmu_cfg_irq_unmask(bmu->bmu_base_va);
}

/**
 * @brief       Create new BMU instance
 * @details     Creates and initializes BMU instance. New instance is disabled and needs
 *              to be enabled by pfe_bmu_enable().
 * @param[in]   cbus_base_va CBUS base virtual address
 * @param[in]   bmu_base BMU base address offset within CBUS address space
 * @param[in]   cfg The BMU block configuration
 * @param[in]   bmu_index The BMU index to be initialized
 * @return      The BMU instance or NULL if failed
 */
__attribute__((cold)) pfe_bmu_t *pfe_bmu_create(addr_t cbus_base_va, addr_t bmu_base, const pfe_bmu_cfg_t *cfg, uint32_t bmu_index)
{
    pfe_bmu_t *bmu;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == cfg) || (NULL_ADDR == cbus_base_va)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        bmu = NULL;
    }
    else if (unlikely(NULL_ADDR == cfg->pool_pa))
    {
        NXP_LOG_ERROR("Buffer pool base is NULL\n");
        bmu = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (unlikely(PFE_BMU_INSTANCES <= bmu_index))
        {
            NXP_LOG_ERROR("BMU index out of range\n");
            bmu = NULL;
        }
        else
        {
            bmu = &bmu_instance[bmu_index];
            (void)autolibc_memset(bmu, 0, sizeof(pfe_bmu_t));
            bmu->cbus_base_va = cbus_base_va;
            bmu->bmu_base_offset = bmu_base;
            bmu->bmu_base_va = (bmu->cbus_base_va + bmu->bmu_base_offset);
            bmu->pool_base_pa = cfg->pool_pa;
            bmu->pool_base_va = cfg->pool_va;
            bmu->pool_va_offset = bmu->pool_base_va - bmu->pool_base_pa;
            bmu->pool_size = cfg->buf_size * cfg->max_buf_cnt;
            bmu->buf_size = cfg->buf_size;

            pfe_bmu_reset(bmu);

            pfe_bmu_cfg_disable(bmu->bmu_base_va);
            pfe_bmu_cfg_init(bmu->bmu_base_va, cfg);
        }
    }

    return bmu;
}

/**
 * @brief       Reset the BMU block
 * @param[in]   bmu The BMU instance
 */
__attribute__((cold)) void pfe_bmu_reset(pfe_bmu_t *bmu)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == bmu))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ret = pfe_bmu_cfg_reset(bmu->bmu_base_va);

        if (ETIMEDOUT == ret)
        {
            NXP_LOG_WARNING("BMU reset timed-out\n");
        }
        else if (EOK != ret)
        {
            NXP_LOG_WARNING("BMU reset failed: 0x%x\n", ret);
        }
        else
        {
            /*Do Nothing*/
            ;
        }
    }
}

/**
 * @brief       Enable the BMU block
 * @param[in]   bmu The BMU instance
 */
__attribute__((cold)) void pfe_bmu_enable(pfe_bmu_t *bmu)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == bmu))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_bmu_cfg_enable(bmu->bmu_base_va);
    }
}

/**
 * @brief       Disable the BMU block
 * @param[in]   bmu The BMU instance
 */
__attribute__((cold)) void pfe_bmu_disable(pfe_bmu_t *bmu)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == bmu))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_bmu_cfg_disable(bmu->bmu_base_va);
    }
}

/**
 * @brief       Allocate buffer via BMU
 * @param[in]   bmu The BMU instance
 * @return      Allocated buffer pointer (physical)
 * @note        Thread safe
 */
__attribute__((hot)) void *pfe_bmu_alloc_buf(const pfe_bmu_t *bmu)
{
    void *ret;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == bmu))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  No resource protection here since it is done by register read */
        ret = (void *)pfe_bmu_cfg_alloc_buf(bmu->bmu_base_va);
    }

    return ret;
}

/**
 * @brief       Convert physical buffer address to virtual one
 * @param[in]   bmu The BMU instance
 * @param[in]   pa The address to be converted
 * @return      Associated virtual address or NULL if failed
 */
__attribute__((hot, pure)) void *pfe_bmu_get_va(const pfe_bmu_t *bmu, addr_t pa)
{
    void * ret;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == bmu))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if ((bmu->pool_base_pa + bmu->pool_size) < pa)
        {
            /*  TODO: The condition is not sufficient and need to consider buffer size... */
            NXP_LOG_DEBUG("PA out of range\n");
        }
        ret = (void *)(pa + bmu->pool_va_offset);
    }

    return ret;
}

/**
 * @brief       Convert virtual buffer address to physical one
 * @param[in]   bmu The BMU instance
 * @param[in]   pa The address to be converted
 * @return      Associated virtual address or NULL if failed
 */
__attribute__((hot, pure)) void *pfe_bmu_get_pa(const pfe_bmu_t *bmu, addr_t va)
{
    void * ret;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == bmu))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if ((bmu->pool_base_va + bmu->pool_size) < va)
        {
            /*  TODO: The condition is not sufficient and need to consider buffer size... */
            NXP_LOG_DEBUG("VA out of range\n");
        }
        ret = (void *)(va - bmu->pool_va_offset);
    }

    return ret;
}

/**
 * @brief       Get BMU buffer
 * @param[in]   bmu The BMU instance
 * @return      Buffer size in number of bytes
 */
__attribute__((cold, pure)) uint32_t pfe_bmu_get_buf_size(const pfe_bmu_t *bmu)
{
    uint32_t len;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == bmu))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        len = 0U;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        len = bmu->buf_size;
    }
    return len;
}

/**
 * @brief       Free buffer via BMU
 * @param[in]   bmu The BMU instance
 * @param[in]   buffer Pointer (physical) to the buffer to be freed.
 * @note        Thread safe
 */
__attribute__((hot)) void pfe_bmu_free_buf(const pfe_bmu_t *bmu, addr_t buffer)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == bmu) || (NULL_ADDR == buffer)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  No resource protection here since it is done by register write */
        pfe_bmu_cfg_free_buf(bmu->bmu_base_va, PFE_CFG_MEMORY_PHYS_TO_PFE(buffer));
    }
}

/**
 * @brief       Destroy BMU instance
 * @param[in]   bmu The BMU instance
 */
__attribute__((cold)) void pfe_bmu_destroy(pfe_bmu_t *bmu)
{
    if (NULL != bmu)
    {
        pfe_bmu_cfg_disable(bmu->bmu_base_va);
        pfe_bmu_cfg_fini(bmu->bmu_base_va);
    }
}

#if defined(PFE_CFG_TEXT_STATS)
/**
 * @brief       Return BMU runtime statistics in text form
 * @details     Function writes formatted text into given buffer.
 * @param[in]   bmu         The BMU instance
 * @param[in]   buf         Pointer to the buffer to write to
 * @param[in]   buf_len     Buffer length
 * @param[in]   verb_level  Verbosity level
 * @return      Number of bytes written to the buffer
 */
__attribute__((cold)) uint32_t pfe_bmu_get_text_statistics(const pfe_bmu_t *bmu, char_t *buf, uint32_t buf_len, uint8_t verb_level)
{
    uint32_t len = 0U;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == bmu))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        len = 0U;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        len += pfe_bmu_cfg_get_text_stat(bmu->bmu_base_va, buf, buf_len, verb_level);
    }
    return len;
}
#endif /* defined(PFE_CFG_TEXT_STATS) */

/**
 * @brief       Get BMU statistic in numeric form
 * @details     This is a HW-specific function providing single statistic
 *              value from the bmu block.
 * @param[in]   bmu   The BMU instance
 * @param[in]   stat_id  required statistic (offset or register)
 * @return      if possible to get statistics, otherwise return PFE_INVALID_STAT
 *              when bmu is NULL
 */
uint32_t pfe_bmu_get_stat_value(const pfe_bmu_t* bmu, uint32_t stat_id)
{
    uint32_t stat_value;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == bmu))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        stat_value = PFE_INVALID_STAT;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        stat_value = pfe_bmu_cfg_get_stat_value(bmu->bmu_base_va, stat_id);
    }
    return stat_value;
}

/**
 * @brief       Get BMU statistic in numeric form for special registers
 * @details     This is a HW-specific function providing single statistic
 *              value from the bmu block.
 * @param[in]   bmu   The BMU instance
 * @param[out]  special_stats special statistic
 * @return      EOK if possible to get special statistics, otherwise return EINVAL
 *              when bmu or special_stats is NULL 
 */
errno_t pfe_bmu_get_special_stats(const pfe_bmu_t* bmu, pfe_bmu_stats_special_t* special_stats)
{
    errno_t ret = EOK;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == bmu) || unlikely(NULL == special_stats))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_bmu_cfg_get_special_stats(bmu->bmu_base_va, special_stats);
    }

    return ret;
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_PFE_MASTER */

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

#include "pfe_platform_cfg.h"
#include "pfe_cbus.h"
#include "pfe_pe.h"
#include "pfe_class.h"
#include "pfe_class_csr.h"
#include "blalloc.h"
#include "fci.h"
#include "fpp.h"
#include "fpp_ext.h"

/* Configures size of the dmem heap allocator chunk (the smallest allocated memory size)
* The size is actually 2^configured value: 1 means 2, 2 means 4, 3 means 8, 4 means 16 etc.
* Do not configure less than 8 bytes (value 3) to avoid alignment problems when allocating structures
* containing uint64_t.
*/
#define PFE_CLASS_HEAP_CHUNK_SIZE 4

struct pfe_classifier_tag
{
    bool_t             is_fw_loaded;   /*   Flag indicating that firmware has been loaded */
    bool_t             enabled;        /*   Flag indicating that classifier has been enabled */
    addr_t             cbus_base_va;   /*   CBUS base virtual address */
    uint32_t           pe_num;         /*   Number of PEs */
    pfe_pe_t           pe[PFE_CLASS_PE_COUNT]; /*    List of particular PEs */
    blalloc_t *        heap_context;   /* Heap manager context */
    uint32_t           dmem_heap_base; /* DMEM base address of the heap */
    bool_t             miflock_pe;     /* Shared 'miflock' diagnostic flag for CLASS PE cores */
    uint32_t           current_feature;   /* Index of the feature to return by pfe_class_get_feature_next() */
    pfe_fw_feature_t   fw_features[PFE_CFG_CLASS_FW_FEATURES_COUNT]; /* List of all features*/
    uint32_t           fw_features_count; /* Number of items in fw_features */
    uint32_t           phy_if_bitmap_br_modes;  /* Bitmap list of PHY interfaces with enabled bridge mode, used to control HW bridge lookup */
};

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
static pfe_class_t classifier_instance;
#if defined(PFE_CFG_TEXT_STATS)
static pfe_ct_pe_stats_t pfe_pe_stats[PFE_CLASS_PE_COUNT + 1U];
#endif /* defined(PFE_CFG_TEXT_STATS) */
static pfe_ct_classify_stats_t pfe_class_stats[PFE_CLASS_PE_COUNT];
#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

static errno_t  pfe_class_dmem_heap_init(pfe_class_t *class);
static errno_t  pfe_class_load_fw_features(pfe_class_t *class);
static errno_t  pfe_class_load_fw_process(pfe_class_t *class);


static void     pfe_class_alg_stats_endian(pfe_ct_class_algo_stats_t *stat);
static void     pfe_class_ihc_stats_endian(pfe_ct_class_ihc_stats_t *stat);
static void     pfe_class_sum_pe_algo_stats(pfe_ct_class_algo_stats_t *sum, const pfe_ct_class_algo_stats_t *val);
static void     pfe_class_sum_pe_ihc_stats(pfe_ct_class_ihc_stats_t *sum, const pfe_ct_class_ihc_stats_t *val);
static void pfe_class_cal_total_stats(pfe_class_t *class, pfe_ct_classify_stats_t *total_stat, pfe_ct_classify_stats_t *stats);

#if defined(PFE_CFG_TEXT_STATS)
static void     pfe_class_pe_stats_endian(pfe_ct_pe_stats_t *stat);
static uint32_t pfe_class_stat_to_str(const pfe_ct_class_algo_stats_t *stat, char *buf, uint32_t buf_len, uint8_t verb_level);
static uint32_t pfe_class_ihc_stat_to_str(const pfe_ct_class_ihc_stats_t *stat, char *buf, uint32_t buf_len, uint8_t verb_level);
static errno_t pfe_class_create_pe(pfe_class_t *class, addr_t cbus_base_va, uint32_t pe_num);
#endif /* defined(PFE_CFG_TEXT_STATS) */

/**
 * @brief CLASS ISR
 * @details Checks all PEs whether they report a firmware error
 * @param[in] class The CLASS instance
 */
errno_t pfe_class_isr(pfe_class_t *class)
{
    uint32_t i;
    errno_t  ret;
#ifdef PFE_CFG_FCI_ENABLE
    pfe_ct_buffer_t buf;
    fci_msg_t       msg;
#endif /* PFE_CFG_FCI_ENABLE */

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (NULL == class)
    {
        NXP_LOG_ERROR("NULL argument\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  Allow safe use of _nolock() functions. We don't call the _mem_lock()
            here as we don't need to have coherent accesses. */
        oal_mutex_lock(PFE_CLASS_PE_MUTEX_03);
        pfe_pe_lock_family(class->pe);
        for (i = 0U; i < class->pe_num; i++)
        {
            /*  Read and print the error record from each PE */
            (void)pfe_pe_get_fw_messages_nolock(&class->pe[i]);
            /* Check the PE core for stalled state */
            (void)pfe_pe_check_stalled_nolock(&class->pe[i]);

#ifdef PFE_CFG_FCI_ENABLE
            /*  Check if there is new message */
            if (EOK == pfe_pe_get_data_nolock(&class->pe[i], &buf))
            {
                /*  Provide data to user via FCI */
                msg.msg_cmd.code   = FPP_CMD_DATA_BUF_AVAIL;
                msg.msg_cmd.length = buf.len;
                msg.msg_cmd.sender = 0U;
                msg.client = NULL;

                if (msg.msg_cmd.length > (uint32_t)sizeof(msg.msg_cmd.payload))
                {
                    NXP_LOG_ERROR("FCI buffer is too small\n");
                }
                else
                {
                    (void)autolibc_memcpy(&msg.msg_cmd.payload, buf.payload, buf.len);
                    ret = fci_core_client_send_broadcast(&msg, NULL);
                    if (EOK != ret)
                    {
                        NXP_LOG_ERROR("fci_core_client_send_broadcast() failed: %d\n", ret);
                    }
                }
            }
#endif /* PFE_CFG_FCI_ENABLE */
        }
        pfe_pe_unlock_family(class->pe);
        oal_mutex_unlock(PFE_CLASS_PE_MUTEX_03);
        ret = EOK;
    }

    return ret;
}

/**
 * @brief       Mask CLASS interrupts
 * @param[in]   class The CLASS instance
 */
void pfe_class_irq_mask(const pfe_class_t *class)
{
    /*  Intentionally empty */
    (void)class;
}

/**
 * @brief       Unmask CLASS interrupts
 * @param[in]   class The CLASS instance
 */
void pfe_class_irq_unmask(const pfe_class_t *class)
{
    /*  Intentionally empty */
    (void)class;
}

/**
 * @brief       Create all PEs instance for new classifier
 * @param[in]   class The class instance
 * @param[in]   cbus_base_va CBUS base virtual address
 * @param[in]   pe_num Number of PEs to be included
 */
static errno_t pfe_class_create_pe(pfe_class_t *class, addr_t cbus_base_va, uint32_t pe_num)
{
    pfe_pe_t *pe;
    uint32_t  ii;
    errno_t ret = EOK;

    /*  Create PEs */
    for (ii = 0U; ii < pe_num; ii++)
    {
        pe = pfe_pe_create(cbus_base_va, PE_TYPE_CLASS, (uint8_t)ii, &class->pe[ii], &class->miflock_pe);

        if (NULL == pe)
        {
            ret = ENOENT;
            break;
        }
        else
        {
            pfe_pe_set_iaccess(pe, CLASS_MEM_ACCESS_WDATA, CLASS_MEM_ACCESS_RDATA, CLASS_MEM_ACCESS_ADDR);
            pfe_pe_set_dmem(pe, PFE_CFG_CLASS_ELF_DMEM_BASE, PFE_CFG_CLASS_DMEM_SIZE);
            pfe_pe_set_imem(pe, PFE_CFG_CLASS_ELF_IMEM_BASE, PFE_CFG_CLASS_IMEM_SIZE);
            pfe_pe_set_lmem(pe, (PFE_CFG_CBUS_PHYS_BASE_ADDR + PFE_CFG_PE_LMEM_BASE), PFE_CFG_PE_LMEM_SIZE);
            class->pe_num++;
            ret = EOK;
        }
    }

    return ret;
}

/**
 * @brief       Create new classifier instance
 * @param[in]   cbus_base_va CBUS base virtual address
 * @param[in]   pe_num Number of PEs to be included
 * @param[in]   cfg The classifier block configuration
 * @return      The classifier instance or NULL if failed
 */
pfe_class_t *pfe_class_create(addr_t cbus_base_va, uint32_t pe_num, const pfe_class_cfg_t *cfg)
{
    pfe_class_t *class;
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL_ADDR == cbus_base_va) || (NULL == cfg)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        class = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        class = &classifier_instance;
        (void)autolibc_memset(class, 0, sizeof(pfe_class_t));
        class->cbus_base_va = cbus_base_va;

        if (pe_num > 0U)
        {
           ret = pfe_class_create_pe(class, cbus_base_va, pe_num);

           if(EOK != ret)
           {
               pfe_class_destroy(class);
               class = NULL;
           }

           if (NULL != class)
           {
               /*   Issue block reset */
               pfe_class_reset(class);

               /* After soft reset, need to wait for 10us to perform another CSR write/read */
               oal_time_usleep(10);

               /*   Disable the classifier */
               pfe_class_disable(class);

               /*   Set new configuration */
               pfe_class_cfg_set_config(class->cbus_base_va, cfg);
           }
        }
        else
        {
            class = NULL_PTR;
        }
    }

    return class;
}

/**
 * @brief       Initializes the DMEM heap manager
 * @param[in]   class The classifier instance
 */
static errno_t pfe_class_dmem_heap_init(pfe_class_t *class)
{
    pfe_ct_pe_mmap_t mmap;
    errno_t          ret;

    ret = pfe_pe_get_mmap(&class->pe[0U], &mmap);

    if (EOK == ret)
    {

        class->heap_context = blalloc_create(oal_ntohl(mmap.class_pe.dmem_heap_size), PFE_CLASS_HEAP_CHUNK_SIZE);
        if (NULL_PTR == class->heap_context)
        {
            ret = ENOMEM;
        }
        else
        {
            class->dmem_heap_base = oal_ntohl(mmap.class_pe.dmem_heap_base);
            ret = EOK;
        }
    }

    return ret;
}

/**
 * @brief       Allocates memory from the DMEM heap
 * @param[in]   class The classifier instance
 * @param[in]   size Requested memory size
 * @return      Address of the allocated memory or value 0 on failure.
 */
addr_t pfe_class_dmem_heap_alloc(const pfe_class_t *class, uint32_t size)
{
    addr_t  addr;
    errno_t ret;

    ret = blalloc_alloc_offs(class->heap_context, size, 0, &addr);

    if (EOK == ret)
    {
        addr = addr + class->dmem_heap_base;
    }
    else
    { /* Allocation failed - return "NULL" */
        NXP_LOG_DEBUG("Failed to allocate memory (size %u)\n", (uint_t)size);
        addr = 0U;
    }

    return addr;
}

/**
 * @brief       Returns previously allocated memory to the DMEM heap
 * @param[in]   class The classifier instance
 * @param[in]   addr Address of the previously allocated memory by pfe_class_dmem_heap_alloc()
 */
void pfe_class_dmem_heap_free(const pfe_class_t *class, addr_t addr)
{
    if (0U == addr)
    { /* Ignore "NULL" */
    }
    else if (addr < class->dmem_heap_base)
    {
        NXP_LOG_ERROR("Impossible address 0x%" PRINTADDR_T " (base is 0x%x)\n", addr, (uint_t) class->dmem_heap_base);
    }
    else
    {
        blalloc_free_offs(class->heap_context, addr - class->dmem_heap_base);
    }
}

/**
 * @brief       Reset the classifier block
 * @param[in]   class The classifier instance
 */
void pfe_class_reset(pfe_class_t *class)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == class))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_class_disable(class);
        pfe_class_cfg_reset(class->cbus_base_va);
        class->enabled = FALSE;
    }
}

/**
 * @brief       Enable the classifier block
 * @details     Enable all classifier PEs
 * @param[in]   class The classifier instance
 */
void pfe_class_enable(pfe_class_t *class)
{
    uint16_t             timeout = 50U;
    pfe_ct_pe_sw_state_t state;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == class))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (unlikely(FALSE == class->is_fw_loaded))
        {
            NXP_LOG_WARNING("Attempt to enable classifier without previous firmware upload\n");
        }

        pfe_class_cfg_enable(class->cbus_base_va);

        do
        {
            oal_time_usleep(5U);
            timeout--;
            state = pfe_pe_get_fw_state(&class->pe[0U]);
        } while ((state < PFE_FW_STATE_INIT) && (timeout > 0U));

        if (timeout == 0U)
        {
            NXP_LOG_ERROR("Time-out waiting for classifier to init\n");
        }
        else
        {
            class->enabled = TRUE;
        }
    }
}

/**
 * @brief       Disable the classifier block
 * @details     Disable all classifier PEs
 * @param[in]   class The classifier instance
 */
void pfe_class_disable(pfe_class_t *class)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == class))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_class_cfg_disable(class->cbus_base_va);
    }
}

/**
 * @brief       Load firmware elf into PEs memories
 * @param[in]   class The classifier instance
 * @param[in]   elf The elf file object to be uploaded
 * @return      EOK when success or error code otherwise
 */
errno_t pfe_class_load_firmware(pfe_class_t *class, const void *elf)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == class) || (NULL == elf)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ret = pfe_pe_load_firmware(class->pe, class->pe_num, elf);
        if (EOK != ret)
        {
            NXP_LOG_ERROR("Classifier firmware loading the PE failed: %d\n", ret);
        }

        if (EOK == ret)
        {
            class->is_fw_loaded = TRUE;

            /* Check the memory map whether it is correct */
            /* All PEs have the same map therefore it is sufficient to check one */
            ret = pfe_pe_check_mmap(&class->pe[0U]);

            if (EOK == ret)
            {
                /* Firmware has been loaded and the DMEM heap is known - initialize the allocator */
                ret = pfe_class_dmem_heap_init(class);
                if (EOK != ret)
                {
                    NXP_LOG_ERROR("Dmem heap allocator initialization failed\n");
                }
            }

            ret = pfe_class_load_fw_features(class);
            if (EOK != ret)
            {
                NXP_LOG_ERROR("Failed to initialize FW features\n");
            }
        }
    }

    return ret;
}

static errno_t pfe_class_load_fw_process(pfe_class_t *class)
{
    errno_t                ret = EINVAL;
    uint32_t               i, j;
    pfe_ct_feature_desc_t *entry;
    bool_t                 val_break = FALSE;
    pfe_fw_feature_t       *fw_features;

    /* Initialize current_feature */
    class->current_feature = 0U;
    for (i = 0U; i < class->fw_features_count; i++)
    {
        fw_features = pfe_fw_feature_create(&class->fw_features[i]);
        if (NULL == fw_features)
        {
            NXP_LOG_ERROR("Failed to create feature %u\n", (uint_t)i);
            /* Destroy previously created and return failure */
            for (j = 0U; j < i; j++)
            {
                pfe_fw_feature_destroy(&class->fw_features[j]);
            }
            ret       = ENOMEM;
            val_break = TRUE;
        }
        else
        {
            /* Get feature low level data */
            ret = pfe_pe_get_fw_feature_entry(&class->pe[0U], i, &entry);
            if (EOK != ret)
            {
                NXP_LOG_ERROR("Failed get ll data for feature %u\n", (uint_t)i);
                /* Destroy previously created and return failure */
                for (j = 0U; j < i; j++)
                {
                    pfe_fw_feature_destroy(&class->fw_features[j]);
                }
                ret       = EINVAL;
                val_break = TRUE;
            }
            else
            {
                /* Set the low level data in the feature */
                (void)pfe_fw_feature_set_ll_data(fw_features, entry, pfe_class_get_num_of_pes(class));
                /* Set the feature string base */
                ret = pfe_fw_feature_set_string_base(fw_features, pfe_pe_get_fw_feature_str_base(&class->pe[0U]));
                if (EOK != ret)
                {
                    NXP_LOG_ERROR("Failed to set string base for feature %u\n", (uint_t)i);
                    /* Destroy previously created and return failure */
                    for (j = 0U; j < i; j++)
                    {
                        pfe_fw_feature_destroy(&class->fw_features[j]);
                    }
                    ret       = EINVAL;
                    val_break = TRUE;
                }
                else
                {
                    /* Set functions to read/write DMEM and their data */
                    (void)pfe_fw_feature_set_dmem_funcs(fw_features, pfe_class_read_dmem, pfe_class_write_dmem, (void *)class);
                }
            }
        }
        if (TRUE == val_break)
        {
            break;
        }
    }

    if (EOK != ret)
    {
        class->fw_features_count = 0U;
    }

    return ret;
}

static errno_t pfe_class_load_fw_features(pfe_class_t *class)
{
    pfe_ct_pe_mmap_t       mmap;
    errno_t                ret;

    ret = pfe_pe_get_mmap(&class->pe[0U], &mmap);
    if (EOK == ret)
    {
        class->fw_features_count = oal_ntohl(mmap.common.version.features_count);
        if (class->fw_features_count > 0U)
        {
            if (class->fw_features_count > PFE_CFG_CLASS_FW_FEATURES_COUNT)
            {
                NXP_LOG_ERROR("Insufficient class features storage for %u entries\n", (uint_t)class->fw_features_count);
                class->fw_features_count = 0U;
                ret = ENOMEM;
            }
            else
            {
                ret = pfe_class_load_fw_process(class);
                if (EOK != ret)
                {
                    NXP_LOG_ERROR("Errors during load FW features\n");
                }
            }
        } /* Else is OK too */
    }
    return ret;
}

/**
 * @brief       Get pointer to PE's memory where memory map data is stored
 * @param[in]   class The classifier instance
 * @param[in]   pe_idx PE index
 * @param[out]  mmap Pointer where memory map data shall be written
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 */
errno_t pfe_class_get_mmap(pfe_class_t *class, int32_t pe_idx, pfe_ct_class_mmap_t *mmap)
{
    errno_t          ret;
    pfe_ct_pe_mmap_t mmap_tmp = {0};

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == class) || (NULL == mmap)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (pe_idx >= (int32_t) class->pe_num)
        {
            ret = EINVAL;
        }
        else
        {
            ret = pfe_pe_get_mmap(&class->pe[pe_idx], &mmap_tmp);
            (void)autolibc_memcpy(mmap, &mmap_tmp.class_pe, sizeof(pfe_ct_class_mmap_t));
        }
    }

    return ret;
}

/**
 * @brief       Write data from host memory to DMEM
 * @param[in]   class_p The classifier instance
 * @param[in]   pe_idx PE index or -1 if all PEs shall be written
 * @param[in]   dst_addr Destination address within DMEM (physical)
 * @param[in]   src_ptr Pointer to data in host memory (virtual address)
 * @param[in]   len Number of bytes to be written
 * @return      EOK or error code in case of failure
 */
errno_t pfe_class_write_dmem(void *class_p, int32_t pe_idx, addr_t dst_addr, const void *src_ptr, uint32_t len)
{
    uint32_t ii;
    pfe_class_t *class = (pfe_class_t *)class_p;
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == class))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (pe_idx >= (int32_t) class->pe_num)
        {
            ret = EINVAL;
        }
        else
        {
            if (pe_idx >= 0)
            {
                /*  Single PE */
                pfe_pe_memcpy_from_host_to_dmem_32(&class->pe[pe_idx], dst_addr, src_ptr, len);
            }
            else
            {
                /*  All PEs */
                for (ii = 0U; ii < class->pe_num; ii++)
                {
                    pfe_pe_memcpy_from_host_to_dmem_32(&class->pe[ii], dst_addr, src_ptr, len);
                }
            }

            ret = EOK;
        }
    }

    return ret;
}

/**
 * @brief       Read data from DMEM to host memory
 * @param[in]   class_p The classifier instance
 * @param[in]   pe_idx PE index
 * @param[in]   dst_ptr Destination address within host memory (virtual)
 * @param[in]   src_addr Source address within DMEM (physical)
 * @param[in]   len Number of bytes to be read
 * @return      EOK or error code in case of failure
 */
errno_t pfe_class_read_dmem(void *class_p, int32_t pe_idx, void *dst_ptr, addr_t src_addr, uint32_t len)
{
    pfe_class_t *class = (pfe_class_t *)class_p;
    errno_t ret;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == class) || (NULL == dst_ptr)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (pe_idx >= (int32_t) class->pe_num)
        {
            NXP_LOG_ERROR("Wrong PE index\n");
            ret = EINVAL;
        }
        else
        {
            pfe_pe_memcpy_from_dmem_to_host_32(&class->pe[pe_idx], dst_ptr, src_addr, len);
            ret = EOK;
        }
    }

    return ret;
}

/**
 * @brief       Read data from DMEM from all PEs atomically to host memory
 * @param[in]   class The classifier instance (All PEs from given class are read)
 * @param[in]   dst_ptr Destination address within host memory (virtual) available memory has to be pe_count * len
 * @param[in]   src_addr Source address within DMEM (physical)
 * @param[in]   buffer_len Destination buffer size
 * @param[in]   read_len Number of bytes to be read (From one PE)
 * @return      EOK or error code in case of failure
 */
errno_t pfe_class_gather_read_dmem(pfe_class_t *class, void *dst_ptr, addr_t src_addr, uint32_t buffer_len, uint32_t read_len)
{
    errno_t ret;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == class) || (NULL == dst_ptr)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ret = pfe_pe_gather_memcpy_from_dmem_to_host_32(class->pe, (int32_t) class->pe_num, dst_ptr, (addr_t)src_addr, buffer_len, read_len);
    }

    return ret;
}

/**
 * @brief       Destroy classifier instance
 * @param[in]   class The classifier instance
 */
void pfe_class_destroy(pfe_class_t *class)
{
    uint32_t ii;

    if (NULL != class)
    {
        pfe_class_disable(class);

        pfe_pe_destroy(class->pe, class->pe_num);

        for (ii = 0U; ii < class->fw_features_count; ii++)
        {
            pfe_fw_feature_destroy(&class->fw_features[ii]);
        }
        class->fw_features_count = 0U;
        class->pe_num = 0U;

        if (NULL_PTR != class->heap_context)
        {
            blalloc_destroy(class->heap_context);
            class->heap_context = NULL_PTR;
        }
    }
}

/**
 * @brief       Set routing table parameters
 * @param[in]   class The classifier instance
 * @param[in]   rtable_pa Physical address of the routing table
 * @param[in]   rtable_len Number of entries in the table
 * @param[in]   entry_size Routing table entry size in number of bytes
 * @return      EOK if success, error code otherwise
 * @note        Must be called before the classifier is enabled.
 */
errno_t pfe_class_set_rtable(pfe_class_t *class, addr_t rtable_pa, uint32_t rtable_len, uint32_t entry_size)
{
    errno_t ret;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == class) || (NULL_ADDR == rtable_pa)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (class->enabled)
        {
            ret = EBUSY;
        }
        else
        {
            ret = pfe_class_cfg_set_rtable(class->cbus_base_va, rtable_pa, rtable_len, entry_size);
        }
    }

    return ret;
}

/**
 * @brief       Set default VLAN ID
 * @details     Every packet without VLAN tag set received via physical interface will
 *              be treated as packet with VLAN equal to this default VLAN ID.
 * @param[in]   class The classifier instance
 * @param[in]   vlan The default VLAN ID (12bit)
 * @return      EOK if success, error code otherwise
 */
errno_t pfe_class_set_default_vlan(const pfe_class_t *class, uint16_t vlan)
{
    errno_t ret;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == class))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_class_cfg_set_def_vlan(class->cbus_base_va, vlan);
        ret = EOK;
    }
    return ret;
}

/**
 * @brief       Returns number of PEs available
 * @param[in]   class The classifier instance
 * @return      Number of available PEs
 */

uint32_t pfe_class_get_num_of_pes(const pfe_class_t *class)
{
    uint32_t pe_num;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == class))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        pe_num = 0U;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pe_num = class->pe_num;
    }
    return pe_num;
}

/**
 * @brief Finds and returns Classifier FW feature by its name
 * @param[in] class The classifier instance
 * @param[out] feature Feature found (valid only if EOK is returned)
 * @param[in] name Name of the feature to be found
 * @return EOK when given entry is found, ENOENT when it is not found, error code otherwise
 */
errno_t pfe_class_get_feature(pfe_class_t *class, pfe_fw_feature_t **feature, const char *name)
{
    uint32_t    i;
    const char *fname;
    errno_t     ret = ENOENT;
    errno_t     ret_val = EOK;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == class) || (NULL == feature) || (NULL == name)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        for (i = 0U; i < class->fw_features_count; i++)
        {
            ret_val = pfe_fw_feature_get_name(&class->fw_features[i], &fname);
            if (EOK == ret_val)
            {
                if (0 == autolibc_strcmp(fname, name))
                {
                    *feature = &class->fw_features[i];
                    ret = EOK;
                    break;
                }
            }
        }
    }
    return ret;
}

/**
 * @brief Finds and returns the 1st Classifier FW feature by order of their discovery - used for listing all features
 * @param[in] class The classifier instance
 * @param[out] feature Feature found (valid only if EOK is returned)
 * @return EOK when given entry is found, ENOENT when it is not found, error code otherwise
 */
errno_t pfe_class_get_feature_first(pfe_class_t *class, pfe_fw_feature_t **feature)
{
    errno_t ret;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == class) || (NULL == feature)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (class->fw_features_count > 0U)
        {
            class->current_feature = 0U;
            *feature = &class->fw_features[class->current_feature];
            ret = EOK;
        }
        else
        {
            ret = ENOENT;
        }
    }

    return ret;
}

/**
 * @brief Finds and returns the next Classifier FW feature by order of their discovery - used for listing all features
 * @param[in] class The classifier instance
 * @param[out] feature Feature found (valid only if EOK is returned)
 * @return EOK when given entry is found, ENOENT when it is not found, error code otherwise
 */
errno_t pfe_class_get_feature_next(pfe_class_t *class, pfe_fw_feature_t **feature)
{
    errno_t ret = ENOENT;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == class) || (NULL == feature)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (class->fw_features_count > 0U)
        {
            /* Avoid going out of the array boundaries */
            if ((class->current_feature + 1U) < class->fw_features_count)
            {
                class->current_feature += 1U;
                *feature = &class->fw_features[class->current_feature];
                ret = EOK;
            }
        }
    }

    return ret;
}

/**
* @brief Converts endiannes of the whole structure containing statistics
* @param[in,out] stat Statistics which endiannes shall be converted
*/
static void pfe_class_alg_stats_endian(pfe_ct_class_algo_stats_t *stat)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == stat))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif
    {
        stat->processed = oal_ntohl(stat->processed);
        stat->accepted  = oal_ntohl(stat->accepted);
        stat->rejected  = oal_ntohl(stat->rejected);
        stat->discarded = oal_ntohl(stat->discarded);
    }
}

/**
* @brief Converts endiannes of the whole structure containing statistics
* @param[in,out] stat Statistics which endiannes shall be converted
*/
static void pfe_class_ihc_stats_endian(pfe_ct_class_ihc_stats_t *stat)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == stat))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif
    {
        stat->rx        = oal_ntohl(stat->rx);
        stat->tx        = oal_ntohl(stat->tx);
        stat->discarded = oal_ntohl(stat->discarded);
    }
}

void pfe_class_flexi_parser_stats_endian(pfe_ct_class_flexi_parser_stats_t *stats)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == stats))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif
    {
        stats->accepted = oal_ntohl(stats->accepted);
        stats->rejected = oal_ntohl(stats->rejected);
    }
}

void pfe_class_sum_flexi_parser_stats(pfe_ct_class_flexi_parser_stats_t *sum, const pfe_ct_class_flexi_parser_stats_t *val)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == sum) || (NULL == val)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif
    {
        sum->accepted += val->accepted;
        sum->rejected += val->rejected;
    }
}

#if defined(PFE_CFG_TEXT_STATS)
/**
* @brief Converts endiannes of the whole structure containing statistics
* @param[in,out] stat Statistics which endiannes shall be converted
*/
static void pfe_class_pe_stats_endian(pfe_ct_pe_stats_t *stat)
{
    uint32_t i;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == stat))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif
    {
        stat->processed = oal_ntohl(stat->processed);
        stat->discarded = oal_ntohl(stat->discarded);
        stat->injected  = oal_ntohl(stat->injected);
        for (i = 0U; i < ((uint32_t)PFE_PHY_IF_ID_MAX + 1U); i++)
        {
            stat->replicas[i] = oal_ntohl(stat->replicas[i]);
        }
    }
}
#endif

/**
* @brief Function adds statistics value to sum
* @param[in] sum Sum to add the value (results are in HOST endian)
* @param[in] val Value to be added to the sum (it is in HOST endian)
*/
static void pfe_class_sum_pe_algo_stats(pfe_ct_class_algo_stats_t *sum, const pfe_ct_class_algo_stats_t *val)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == sum) || (NULL == val)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif
    {
        sum->processed += val->processed;
        sum->accepted += val->accepted;
        sum->rejected += val->rejected;
        sum->discarded += val->discarded;
    }
}

/**
* @brief Function adds statistics value to sum
* @param[in] sum Sum to add the value (results are in HOST endian)
* @param[in] val Value to be added to the sum (it is in HOST endian)
*/
static void pfe_class_sum_pe_ihc_stats(pfe_ct_class_ihc_stats_t *sum, const pfe_ct_class_ihc_stats_t *val)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == sum) || (NULL == val)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif
    {
        sum->rx += val->rx;
        sum->tx += val->tx;
        sum->discarded += val->discarded;
    }
}

#if defined(PFE_CFG_TEXT_STATS)
/**
 * @brief                  Converts statistics of a logical interface or classification algorithm into a text form
 * @param[in]  stat        Statistics to convert - expected in HOST endian
 * @param[out] buf         Buffer where to write the text
 * @param[in]  buf_len     Buffer length
 * @param[in]  verb_level  Verbosity level
 * @return                 Number of bytes written into the output buffer
 */
static uint32_t pfe_class_stat_to_str(const pfe_ct_class_algo_stats_t *stat, char *buf, uint32_t buf_len, uint8_t verb_level)
{
    uint32_t len = 0U;

    (void)verb_level;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == stat) || (NULL == buf)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        len = 0U;
    }
    else
#endif
    {
        len += oal_util_snprintf(buf + len, buf_len - len, "Frames processed: %u\n", stat->processed);
        len += oal_util_snprintf(buf + len, buf_len - len, "Frames accepted:  %u\n", stat->accepted);
        len += oal_util_snprintf(buf + len, buf_len - len, "Frames rejected:  %u\n", stat->rejected);
        len += oal_util_snprintf(buf + len, buf_len - len, "Frames discarded: %u\n", stat->discarded);
    }
    return len;
}

/**
 * @brief                 Converts statistics of a logical interface or classification algorithm into a text form
 * @param[in]  stat       Statistics to convert - expected in HOST endian
 * @param[out] buf        Buffer where to write the text
 * @param[in]  buf_len    Buffer length
 * @param[in]  verb_level Verbosity level
 * @return                Number of bytes written into the output buffer
 */
static uint32_t pfe_class_ihc_stat_to_str(const pfe_ct_class_ihc_stats_t *stat, char *buf, uint32_t buf_len, uint8_t verb_level)
{
    uint32_t len = 0U;

    (void)verb_level;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == stat) || (NULL == buf)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        len = 0U;
    }
    else
#endif
    {
        len += oal_util_snprintf(buf + len, buf_len - len, "  Frames received:    %u\n", stat->rx);
        len += oal_util_snprintf(buf + len, buf_len - len, "  Frames transmitted: %u\n", stat->tx);
        len += oal_util_snprintf(buf + len, buf_len - len, "  Frames discarded:   %u\n", stat->discarded);
    }
    return len;
}

/**
 * @brief                  Converts statistics of a logical interface or classification algorithm into a text form
 * @param[in]   stat       Statistics to convert - expected in HOST endian
 * @param[out]  buf        Buffer where to write the text
 * @param[in]   buf_len    Buffer length
 * @param[in]   verb_level Verbosity level
 * @return                 Number of bytes written into the output buffer
 */
uint32_t pfe_class_fp_stat_to_str(const pfe_ct_class_flexi_parser_stats_t *stat, char *buf, uint32_t buf_len, uint8_t verb_level)
{
    uint32_t len = 0U;

    (void)verb_level;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == stat) || (NULL == buf)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        len = 0U;
    }
    else
#endif
    {
        len += oal_util_snprintf(buf + len, buf_len - len, "Frames accepted:  %u\n", stat->accepted);
        len += oal_util_snprintf(buf + len, buf_len - len, "Frames rejected:  %u\n", stat->rejected);
    }
    return len;
}

#endif /* defined(PFE_CFG_TEXT_STATS) */

/**
 * @brief       Send data buffer
 * @param[in]   class The CLASS instance
 * @param[in]   buf Buffer to be sent
 * @return      EOK success, error code otherwise
 */
errno_t pfe_class_put_data(pfe_class_t *class, pfe_ct_buffer_t *buf)
{
    uint32_t ii, tries;
    errno_t  ret = E_NOT_OK;

    /*  Allow safe use of _nolock() functions. We don't call the _mem_lock()
        here as we don't need to have coherent accesses. */
    oal_mutex_lock(PFE_CLASS_PE_MUTEX_04);
    pfe_pe_lock_family(class->pe);
    for (ii = 0U; ii < class->pe_num; ii++)
    {
        tries = 0U;
        do
        {
            ret = pfe_pe_put_data_nolock(&class->pe[ii], buf);
            if (EAGAIN == ret)
            {
                tries++;
                oal_time_usleep(200U);
            }
        } while ((ret == EAGAIN) && (tries < 10U));

        if (EOK != ret)
        {
            NXP_LOG_ERROR("Unable to update pe %u\n", (uint_t)ii);
            ret = EBUSY;
            break;
        }
    }
    pfe_pe_unlock_family(class->pe);
    oal_mutex_unlock(PFE_CLASS_PE_MUTEX_04);

    return ret;
}

/**
 * @brief           Calculate total statistics
 * @param[in]       class The CLASS instance
 * @param[out]      total_stat Total statistics
 * @param[in,out]   stats Statistic structure
 */
static void pfe_class_cal_total_stats(pfe_class_t *class, pfe_ct_classify_stats_t *total_stat, pfe_ct_classify_stats_t *stats)
{
    uint32_t                 i = 0U, j = 0U;

    /* Calculate total statistics */
    while (i < pfe_class_get_num_of_pes(class))
    {
        pfe_class_alg_stats_endian(&stats[i].flexible_router);
        pfe_class_alg_stats_endian(&stats[i].ip_router);
        pfe_class_alg_stats_endian(&stats[i].vlan_bridge);
        pfe_class_alg_stats_endian(&stats[i].log_if);

        for (j = 0U; j < ((uint32_t)PFE_PHY_IF_ID_MAX + 1U); j++)
        {
            pfe_class_ihc_stats_endian(&stats[i].hif_to_hif[j]);
        }
        pfe_class_sum_pe_algo_stats(&total_stat->flexible_router, &stats[i].flexible_router);
        pfe_class_sum_pe_algo_stats(&total_stat->ip_router, &stats[i].ip_router);
        pfe_class_sum_pe_algo_stats(&total_stat->vlan_bridge, &stats[i].vlan_bridge);
        pfe_class_sum_pe_algo_stats(&total_stat->log_if, &stats[i].log_if);

        for (j = 0U; j < ((uint32_t)PFE_PHY_IF_ID_MAX + 1U); j++)
        {
            pfe_class_sum_pe_ihc_stats(&total_stat->hif_to_hif[j], &stats[i].hif_to_hif[j]);
        }

        ++i;
    }
}

/**
 * @brief       Get class algo statistics
 * @param[in]   class
 * @param[out]  stat Statistic structure
 * @retval      EOK Success
 * @retval      NOMEM Not possible to allocate memory for read
 */
errno_t pfe_class_get_stats(pfe_class_t *class, pfe_ct_classify_stats_t *stat)
{
    pfe_ct_pe_mmap_t         mmap;
    errno_t                  ret      = EOK;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == class) || (NULL == stat)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        (void)autolibc_memset(stat, 0, sizeof(pfe_ct_classify_stats_t));

        /* Get the memory map - all PEs share the same memory map
        therefore we can read arbitrary one (in this case 0U) */
        ret = pfe_pe_get_mmap(&class->pe[0U], &mmap);

        if (EOK != ret)
        {
            NXP_LOG_ERROR("Cannot get PE memory map\n");
        }
        else
        {
            /* Gather memory from all PEs*/
            ret = pfe_class_gather_read_dmem(class, pfe_class_stats,
                oal_ntohl(mmap.class_pe.classification_stats),
                sizeof(pfe_class_stats), sizeof(pfe_ct_classify_stats_t));

            pfe_class_cal_total_stats(class, stat, pfe_class_stats);
        }
    }

    return ret;
}

#define HIF_CHANNELS_MASK (((uint32_t)1U << (uint32_t)PFE_PHY_IF_ID_HIF0)\
                          |((uint32_t)1U << (uint32_t)PFE_PHY_IF_ID_HIF1)\
                          |((uint32_t)1U << (uint32_t)PFE_PHY_IF_ID_HIF2)\
                          |((uint32_t)1U << (uint32_t)PFE_PHY_IF_ID_HIF3)\
                          |((uint32_t)1U << (uint32_t)PFE_PHY_IF_ID_HIF_NOCPY))

#if defined(PFE_CFG_TEXT_STATS)
/**
 * @brief       Return CLASS runtime statistics in text form
 * @details     Function writes formatted text into given buffer.
 * @param[in]   class       The CLASS instance
 * @param[in]   buf         Pointer to the buffer to write to
 * @param[in]   buf_len     Buffer length
 * @param[in]   verb_level  Verbosity level
 * @return      Number of bytes written to the buffer
 */
uint32_t pfe_class_get_text_statistics(pfe_class_t *class, char_t *buf, uint32_t buf_len, uint8_t verb_level)
{
    uint32_t len = 0U;
    pfe_ct_pe_mmap_t        mmap;
    errno_t                 ret = EOK;
    uint32_t                ii, j;
    pfe_ct_classify_stats_t c_alg_stats;
    pfe_ct_version_t        fw_ver;
    char_t                  phyif_name[][20] = {
        "EMAC0",
        "EMAC1",
        "EMAC2",
        "HIF",
        "HIF_NOCPY",
        "UTIL",
        "HIF0",
        "HIF1",
        "HIF2",
        "HIF3"
    };

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == class))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        len = 0U;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* FW version */
        if (EOK == pfe_class_get_fw_version(class, &fw_ver))
        {
            len += oal_util_snprintf(buf + len, buf_len - len, "FIRMWARE VERSION\t%u.%u.%u (api:%.32s)\n", fw_ver.major, fw_ver.minor, fw_ver.patch, fw_ver.cthdr);
        }
        else
        {
            len += oal_util_snprintf(buf + len, buf_len - len, "FIRMWARE VERSION <unknown>\n");
        }

        len += pfe_class_cfg_get_text_stat(class->cbus_base_va, buf + len, buf_len - len, verb_level);

        (void)autolibc_memset(&pfe_pe_stats, 0, sizeof(pfe_pe_stats));

        /* Get the memory map - all PEs share the same memory map
        therefore we can read arbitrary one (in this case 0U) */
        ret = pfe_pe_get_mmap(&class->pe[0U], &mmap);
        if (EOK != ret)
        {
            NXP_LOG_ERROR("Cannot get PE memory map\n");
        }
        else
        {
            /* Lock family */
            oal_mutex_lock(PFE_CLASS_PE_MUTEX_05);
            pfe_pe_lock_family(class->pe);

            /* Acquire memlock for all PE cores. They will stop processing frames and wait.
               This will ensure data coherence. */
            for (ii = 0U; ii < class->pe_num; ii++)
            {
                ret = pfe_pe_memlock_acquire_nolock(&class->pe[ii]);
                if (EOK != ret)
                {
                    NXP_LOG_ERROR("PE %u could not be locked\n", (uint_t)ii);
                    len += oal_util_snprintf(buf + len, buf_len - len, "PE %u could not be locked - statistics are not coherent\n", ii);
                }
            }

            /* Get PE info per PE
            - leave 1st position in allocated memory empty for sums */
            for (ii = 0U; ii < class->pe_num; ii++)
            {
                (void)pfe_pe_get_pe_stats_nolock(
                    &class->pe[ii],
                    oal_ntohl(mmap.class_pe.pe_stats),
                    &pfe_pe_stats[ii + 1U]);
            }

            /* Release memlock for all PE cores */
            for (ii = 0U; ii < class->pe_num; ii++)
            {
                ret = pfe_pe_memlock_release_nolock(&class->pe[ii]);
                if (EOK != ret)
                {
                    NXP_LOG_ERROR("PE %u could not be unlocked\n", (uint_t)ii);
                }
            }
            /* Unlock family */
            pfe_pe_unlock_family(class->pe);
            oal_mutex_unlock(PFE_CLASS_PE_MUTEX_05);

            ret = pfe_class_get_stats(class, &c_alg_stats);
            if (EOK != ret)
            {
                NXP_LOG_ERROR("Cannot get class statistics\n");
            }

            /* Process gathered info from all PEs
            - convert endians
            - done separately to minimize time when PEs are locked
            - create sums in the 1st set
            */
            for (ii = 0U; ii < class->pe_num; ii++)
            {
                pfe_class_pe_stats_endian(&pfe_pe_stats[ii + 1U]);

                /* Calculate sums */
                pfe_pe_stats[0].processed += pfe_pe_stats[ii + 1U].processed;
                pfe_pe_stats[0].discarded += pfe_pe_stats[ii + 1U].discarded;
                pfe_pe_stats[0].injected += pfe_pe_stats[ii + 1U].injected;

                for (j = 0U; j < ((uint32_t)PFE_PHY_IF_ID_MAX + 1U); j++)
                {
                    pfe_pe_stats[0].replicas[j] += pfe_pe_stats[ii + 1U].replicas[j];
                }
            }

            /* Print results */
            len += oal_util_snprintf(buf + len, buf_len - len, "-- Per PE statistics --\n");

            for (ii = 0U; ii < class->pe_num; ii++)
            {
                len += oal_util_snprintf(buf + len, buf_len - len, "PE %u Frames processed: %u\n", ii, pfe_pe_stats[ii + 1U].processed);
                len += oal_util_snprintf(buf + len, buf_len - len, "PE %u Frames discarded: %u\n", ii, pfe_pe_stats[ii + 1U].discarded);
            }

            len += oal_util_snprintf(buf + len, buf_len - len, "-- Summary statistics --\n");
            len += oal_util_snprintf(buf + len, buf_len - len, "Frames processed: %u\n", pfe_pe_stats[0].processed);
            len += oal_util_snprintf(buf + len, buf_len - len, "Frames discarded: %u\n", pfe_pe_stats[0].discarded);

            for (j = 0U; j < ((uint32_t)PFE_PHY_IF_ID_MAX + 1U); j++)
            {
                len += oal_util_snprintf(buf + len, buf_len - len, "Frames with %u replicas: %u\n", j + 1U, pfe_pe_stats[0].replicas[j]);
            }

            len += oal_util_snprintf(buf + len, buf_len - len, "Frames with HIF_TX_INJECT: %u\n", pfe_pe_stats[0].injected);

            len += oal_util_snprintf(buf + len, buf_len - len, "- Flexible router -\n");
            len += pfe_class_stat_to_str(&c_alg_stats.flexible_router, buf + len, buf_len - len, verb_level);
            len += oal_util_snprintf(buf + len, buf_len - len, "- IP Router -\n");
            len += pfe_class_stat_to_str(&c_alg_stats.ip_router, buf + len, buf_len - len, verb_level);
            len += oal_util_snprintf(buf + len, buf_len - len, "- VLAN Bridge -\n");
            len += pfe_class_stat_to_str(&c_alg_stats.vlan_bridge, buf + len, buf_len - len, verb_level);
            len += oal_util_snprintf(buf + len, buf_len - len, "- Logical Interfaces -\n");
            len += pfe_class_stat_to_str(&c_alg_stats.log_if, buf + len, buf_len - len, verb_level);
            len += oal_util_snprintf(buf + len, buf_len - len, "- InterHIF -\n");

            for (j = 0U; j < ((uint32_t)PFE_PHY_IF_ID_MAX + 1U); j++)
            {
                if (0U != (((uint32_t)1U << j) & (uint32_t)HIF_CHANNELS_MASK))
                {
                    len += oal_util_snprintf(buf + len, buf_len - len, "Interface: %s\n", phyif_name[j]);
                    len += pfe_class_ihc_stat_to_str(&c_alg_stats.hif_to_hif[j], buf + len, buf_len - len, verb_level);
                }
            }

            len += oal_util_snprintf(buf + len, buf_len - len, "\nDMEM heap\n---------\n");
            len += blalloc_get_text_statistics(class->heap_context, buf + len, buf_len - len, verb_level);
        }
    }

    return len;
}

#endif /* defined(PFE_CFG_TEXT_STATS) */

/**
 * @brief       Returns firmware versions
 * @param[in]   class The classifier instance
 * @return      ver Parsed firmware metadata
 */
errno_t pfe_class_get_fw_version(const pfe_class_t *class, pfe_ct_version_t *ver)
{
    pfe_ct_pe_mmap_t pfe_pe_mmap;
    errno_t          ret;

    /*  Get mmap base from PE[0] since all PEs have the same memory map */
    ret = pfe_pe_get_mmap(&class->pe[0], &pfe_pe_mmap);
    if ((class->pe_num == 0) || (EOK != ret))
    {
        ret = EINVAL;
    }
    else
    {
        (void)autolibc_memcpy(ver, &pfe_pe_mmap.class_pe.common.version, sizeof(pfe_ct_version_t));
        ret = EOK;
    }

    return ret;
}

/**
* @brief        Enable HW lookup of routing table
* @param[in]    class The classifier instance
*/
void pfe_class_rtable_lookup_enable(const pfe_class_t *class)
{  
    oal_mutex_lock(PFE_CLASS_MUTEX_01);
    pfe_class_cfg_rtable_lookup_enable(class->cbus_base_va);
    oal_mutex_unlock(PFE_CLASS_MUTEX_01);
}

/**
* @brief        Disable HW lookup of routing table
* @param[in]    class The classifier instance
*/
void pfe_class_rtable_lookup_disable(const pfe_class_t *class)
{
    oal_mutex_lock(PFE_CLASS_MUTEX_02);
    pfe_class_cfg_rtable_lookup_disable(class->cbus_base_va);
    oal_mutex_unlock(PFE_CLASS_MUTEX_02);
}

/**
* @brief        Control HW bridge lookup
* @param[in]    class The classifier instance
* @param[in]    if_bitmap The bitmap represnting PHY IF
* @param[in]    br_mode The bridge mode state of PHY IF
* @note         HW bridge lookup is enabled with the 1st PHY IF set to bridge mode,
*               disabled when the last PHY IF bridge mode is unset.
*/
void pfe_class_update_hw_bridge_lookup(pfe_class_t *class, uint32_t if_bitmap, bool_t br_mode)
{
    uint32_t if_bitmap_br_modes_before;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == class))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        oal_mutex_lock(PFE_CLASS_MUTEX_00);
        
        if_bitmap_br_modes_before = class->phy_if_bitmap_br_modes;
        if (TRUE == br_mode)
        {
            class->phy_if_bitmap_br_modes |= if_bitmap;
            if (0U == if_bitmap_br_modes_before)
            {
                /* Enable HW bridge lookup */
                pfe_class_cfg_bridge_lookup_enable(class->cbus_base_va);
            }
        }
        else
        {
            class->phy_if_bitmap_br_modes &= ~if_bitmap;
            if ((0U != if_bitmap_br_modes_before) && (0U == class->phy_if_bitmap_br_modes))
            {
                /* Disable HW bridge lookup */
                pfe_class_cfg_bridge_lookup_disable(class->cbus_base_va);
            }
        }
        
        oal_mutex_unlock(PFE_CLASS_MUTEX_00);
    }
}


#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

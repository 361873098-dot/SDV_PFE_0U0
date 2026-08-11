/* =========================================================================
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
 *  This code (or certain portions of it) is released for use under license
 *  from Imagination Technologies Limited.
 *  Copyright (c) 2019 Imagination Technologies Limited
 *  Copyright (c) 2020-2021 Imagination Technologies Limited
 *  Copyright 2018-2024 NXP
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
#define PFE_SRC_VERSION_CHECK 43140440

#include "pfe_cfg.h"
#include "oal.h"
#include "hal.h"

#include "pfe_platform.h"
#include "elf_cfg.h"
#include "elf.h"
#include "pfe_cbus.h"
#include "pfe_pe.h"
#include "pfe_hm.h"
#include "pfe_class_csr.h"
#include "Eth_43_PFE_Cfg.h"

#define BYTES_TO_4B_ALIGNMENT(x)    (4U - ((x) & 0x3U))
#define INVALID_FEATURES_BASE       0xFFFFFFFFU
#define ALIGNMENT_CHECKMASK         0x3U
#define ALIGNMENT_PACKEDNUMBER      4U

/**
 * @brief   Mutex protecting access to common mem_access_* registers
 */
#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"


/* usage scope: pfe_pe_load_firmware*/
static pfe_ct_pe_mmap_t tmp_mmap;
static uint8_t tmp_features[ETH_43_PFE_FEATURES_SECTION_BUFF_SIZE];
static uint8_t tmp_messages[ETH_43_PFE_MESSAGES_SECTION_BUFF_SIZE];

typedef struct
{
    pfe_pe_mem_t mem;       /*Memory to access*/
    uint32_t val;           /*Value to write (BE)*/
    addr_t addr;            /*Write address (should be aligned to 32 bits)*/
    uint8_t size;           /*Number of bytes to write (maximum 4)*/
    uint8_t offset;         /*Number of bytes the addr needs to be aligned (maximum 3)*/
}pfe_pe_mem_data_t;

#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

static errno_t pfe_pe_get_state_monitor_nolock(pfe_pe_t *pe, pfe_ct_pe_sw_state_monitor_t *state_monitor);
static bool_t pfe_pe_is_active_nolock(pfe_pe_t *pe);
static void pfe_pe_memcpy_from_host_to_dmem_32_nolock(
        pfe_pe_t *pe, addr_t dst_addr, const void *src_ptr, uint32_t len);
/* FW loading functions */
static void pfe_pe_fw_memcpy_bulk(pfe_pe_t *pe, pfe_pe_mem_t mem, addr_t dst_addr, const void *src_ptr, uint32_t len);
static void pfe_pe_fw_memset_bulk(pfe_pe_t *pe, pfe_pe_mem_t mem, uint32_t val, addr_t addr, uint32_t size);
static void pfe_pe_fw_memcpy_single(pfe_pe_t *pe, pfe_pe_mem_t mem, addr_t dst_addr, const void *src_ptr, uint32_t len);
static void pfe_pe_fw_memset_single(pfe_pe_t *pe, pfe_pe_mem_t mem, uint32_t val, addr_t addr, uint32_t size);
static void pfe_pe_free_mem(pfe_pe_t *pe, uint32_t pe_num);
static errno_t pfe_pe_upload_sections(pfe_pe_t *pe, uint32_t pe_num, const ELF_File_t *elf_file);
static void print_fw_issue(const pfe_ct_pe_mmap_t *fw_mmap);
static uint8_t pfe_pe_fw_load_cycles(const pfe_pe_t *pe, uint8_t pe_num);
static errno_t pfe_pe_load_elf_section(pfe_pe_t *pe, const void *sdata, addr_t load_addr, addr_t size, uint32_t type);
static addr_t pfe_pe_get_elf_sect_load_addr(const ELF_File_t *elf_file, const Elf32_Shdr *shdr);
static errno_t pfe_pe_fw_ops_valid(pfe_pe_t *pe1, const pfe_pe_t *pe2);
static errno_t pfe_pe_fw_install_ops(pfe_pe_t *pe, uint8_t pe_num);
static uint32_t pfe_pe_mem_read(pfe_pe_t *pe, pfe_pe_mem_t mem, addr_t addr, uint8_t size);
static void pfe_pe_mem_write(pfe_pe_t *pe, pfe_pe_mem_data_t memdata);
static inline uint32_t pfe_pe_get_u32_from_byteptr(const uint8_t *src_byteptr, uint32_t len);
static errno_t pfe_pe_load_dmem_section_nolock(pfe_pe_t *pe, const void *sdata, addr_t addr, addr_t size, uint32_t type);
static errno_t pfe_pe_load_imem_section_nolock(pfe_pe_t *pe, const void *data, addr_t addr, addr_t size, uint32_t type);
static bool_t pfe_pe_is_dmem(const pfe_pe_t *pe, addr_t addr, uint32_t size);
static bool_t pfe_pe_is_imem(const pfe_pe_t *pe, addr_t addr, uint32_t size);
static errno_t pfe_pe_mem_process_lock(pfe_pe_t *pe, PFE_PTR(pfe_ct_pe_misc_control_t) misc_dmem);
static inline bool_t pfe_pe_check_pe_times (pfe_pe_t *pe, uint32_t idx, uint8_t best_pe_loader_cnt, uint8_t pe_num);
static errno_t pfe_pe_load_firmware_aux(pfe_pe_t *pe, uint32_t pe_num, const void *elf);
static errno_t pfe_pe_copy_firmware_sections(const ELF_File_t *elf_file, uint32_t * features_size, uint32_t * messages_size);

#if defined(PFE_CFG_TEXT_STATS)
static inline const char_t *pfe_pe_get_fw_state_str(pfe_ct_pe_sw_state_t state);
static uint32_t pfe_pe_get_measurements_nolock(pfe_pe_t *pe, uint32_t count, uint32_t ptr, char_t *buf, uint32_t buf_len, uint8_t verb_level);
#endif /* defined(PFE_CFG_TEXT_STATS) */

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CONST_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"


static const fw_load_ops_t fw_load_ops[] =
{
    /* These OPs can load 8 CLASS cores only */
    {
        .pe_loaded_cnt = 8U,
        .can_load_util = (bool_t)FALSE,
        .pe_memset = pfe_pe_fw_memset_bulk,
        .pe_memcpy = pfe_pe_fw_memcpy_bulk,
    },
    /* These OPs can load  1 CLASS/UTIL core only */
    {
        .pe_loaded_cnt = 1U,
        .can_load_util = (bool_t)TRUE,
        .pe_memset = pfe_pe_fw_memset_single,
        .pe_memcpy = pfe_pe_fw_memcpy_single,
    },
};

#define ETH_43_PFE_STOP_SEC_CONST_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

static const pfe_hm_src_t hm_types[] = {
    HM_SRC_UNKNOWN,
    HM_SRC_PE_CLASS,
    HM_SRC_PE_TMU,
    HM_SRC_PE_UTIL
};

/**
 * @brief       Try to upload all sections of the .elf
 * @param[in]   pe The PE instances
 * @param[in]   pe_num Number of PE instances
 * @param[in]   elf_file The elf file object to be uploaded
 * @return      EOK if success, error code otherwise
 */
static errno_t pfe_pe_upload_sections(pfe_pe_t *pe, uint32_t pe_num, const ELF_File_t *elf_file)
{
    uint32_t ii, pe_idx;
    addr_t load_addr;
    const void *buf;
    errno_t ret = EOK;

    for (ii = 0U; ii < elf_file->Header.r32.e_shnum; ii++)
    {
        if (0U == (ENDIAN_SW_4B(elf_file->arSectHead32[ii].sh_flags) & (uint32_t)(((uint32_t)SHF_WRITE) | ((uint32_t)SHF_ALLOC) | ((uint32_t)SHF_EXECINSTR))))
        {
            /*  Skip the section */
            continue;
        }

        buf = (void*)((addr_t)elf_file->pvData + ENDIAN_SW_4B(elf_file->arSectHead32[ii].sh_offset));
        /* Translate elf virtual address to load address */
        load_addr = pfe_pe_get_elf_sect_load_addr(elf_file, &elf_file->arSectHead32[ii]);
        if(0U == load_addr)
        {   /* Failed */
            ret = EINVAL;
            pfe_pe_free_mem(pe, pe_num);
            break;
        }

        for(pe_idx = 0U; pe_idx < pfe_pe_fw_load_cycles(&pe[0], (uint8_t)(pe_num & UINT8_MAX)); ++pe_idx)
        {
        /*  Upload the section */
            const uint32_t sh_type = ENDIAN_SW_4B(elf_file->arSectHead32[ii].sh_type);
            const uint32_t sh_size = ENDIAN_SW_4B(elf_file->arSectHead32[ii].sh_size) & UINT32_MAX;
            ret = pfe_pe_load_elf_section(&pe[pe_idx], buf, load_addr, sh_size, sh_type);
            if (EOK != ret)
            {
                const uint32_t sh_addr = ENDIAN_SW_4B(elf_file->arSectHead32[ii].sh_addr);
                const uint32_t sh_name = ENDIAN_SW_4B(elf_file->arSectHead32[ii].sh_name) & UINT32_MAX;
                NXP_LOG_ERROR("Couldn't upload firmware section %s, %u bytes @ 0x%08x. Reason: %d\n",
                              &(elf_file->acSectNames[sh_name]), (uint_t)sh_size, (uint_t)sh_addr, ret);
                pfe_pe_free_mem(pe, pe_num);
                break;
            }
        }
        if (EOK != ret)
        {
            break;
        }
    }

    return ret;
}

/**
 * @brief       Free memory when see failed condition.
 * @param[in]   pe_num number of the PE instance
  * @param[in]  pe     the PE instance
 */
static void pfe_pe_free_mem(pfe_pe_t *pe, uint32_t pe_num)
{
    uint32_t ii;

    for (ii = 0; ii < pe_num; ++ii)
    {
        pe[ii].mmap_data = NULL;
        pe[ii].fw_msg_section = NULL;
        pe[ii].fw_msg_section_size = 0U;
        pe[ii].fw_feature_section = NULL;
        pe[ii].fw_feature_section_size = 0U;

    }
}

/**
 * @brief       Get state monitor of the PE
 * @param[in]   pe The PE instance
 * @param[out]  state_monitor Address to write the state monitor data to
 * @return      EOK if succeeded
 */
static errno_t pfe_pe_get_state_monitor_nolock(pfe_pe_t *pe, pfe_ct_pe_sw_state_monitor_t *state_monitor)
{
    errno_t ret;

    if(NULL == pe->mmap_data)
    {
        NXP_LOG_WARNING("PE %u: Firmware not loaded\n", pe->id);
        ret = EIO;
    }
    else
    {
    /*  Get state */
        pfe_pe_memcpy_from_dmem_to_host_32_nolock(
                pe,
                state_monitor,
                oal_ntohl(pe->mmap_data->common.state_monitor),
                sizeof(pfe_ct_pe_sw_state_monitor_t));
        ret = EOK;
    }

    return ret;
}

/**
 * @brief       Query if PE is active
 * @details     PE is active if it is running (executing firmware code) and is not gracefully stopped
 * @param[in]   pe The PE instance
 * @return      TRUE if PE is active, FALSE if not
 */
static bool_t pfe_pe_is_active_nolock(pfe_pe_t *pe)
{
    pfe_ct_pe_sw_state_monitor_t state_monitor = {0};
    bool_t ret = FALSE;

    if (pfe_pe_get_state_monitor_nolock(pe, &state_monitor) == EOK)
    {
        if ((PFE_FW_STATE_STOPPED != state_monitor.state) && (PFE_FW_STATE_UNINIT != state_monitor.state))
        {
            ret = TRUE;
        }
        /*  PFE_FW_STATE_INIT == state_monitor.state is considered as running because
        the transition to next state is short */
    }

    return ret;
}


/**
* @brief Lock PE access
* @param[in] pe PE which access shall be locked
*/
void pfe_pe_lock_family(pfe_pe_t *pe)
{
    if (unlikely(*(pe->miflock)))
    {
        NXP_LOG_ERROR("Lock already indicated.\n");
    }

    /*  Indicate the 'lock' status */
    *(pe->miflock) = TRUE;
}

/**
* @brief Unlock PE access
* @param[in] pe PE which access shall be unlocked
*/
void pfe_pe_unlock_family(pfe_pe_t *pe)
{
    /* Indicate the 'unlock' status */
    *(pe->miflock) = FALSE;
}

/**
 * @brief       Process to lock PE memory
 * @param[in]   pe The PE instance
 * @param[in]   misc_dmem The miscellaneous control command structure
 * @return      EOK if success, error code otherwise
 */
static errno_t pfe_pe_mem_process_lock(pfe_pe_t *pe, PFE_PTR(pfe_ct_pe_misc_control_t) misc_dmem)
{
    errno_t ret;
    pfe_ct_pe_misc_control_t misc_ctrl = {0};
    uint32_t timeout = 10;

    /*  Read the misc control structure from DMEM */
    pfe_pe_memcpy_from_dmem_to_host_32_nolock(pe, &misc_ctrl, misc_dmem, sizeof(pfe_ct_pe_misc_control_t));

    if (0U != misc_ctrl.graceful_stop_request)
    {
        if (0U != misc_ctrl.graceful_stop_confirmation)
        {
            NXP_LOG_ERROR("Locking locked memory\n");
        }
        else
        {
            NXP_LOG_ERROR("Duplicate stop request\n");
        }

        ret = EPERM;
    }
    else
    {
        /*  Writing the non-zero value triggers the request */
        misc_ctrl.graceful_stop_request = 0xffU;
        /*  PE will respond with setting this to non-zero value */
        misc_ctrl.graceful_stop_confirmation = 0x0U;
        /*  Use 'nolock' variant here. Accessing this data can't lead to conflicts. */
        pfe_pe_memcpy_from_host_to_dmem_32_nolock(
                pe, misc_dmem, &misc_ctrl, sizeof(pfe_ct_pe_misc_control_t));

        if (FALSE == pfe_pe_is_active_nolock(pe))
        {
            /*  Access to PE memories is considered to be safe. PE memory
                interface is locked. */
            ret = EOK;
        }
        else
        {
            ret = EOK;
            /*  Wait for response */
            do
            {
                if (0U == timeout)
                {
                    NXP_LOG_ERROR("Timed-out\n");

                    /*  Cancel the request */
                    misc_ctrl.graceful_stop_request = 0U;

                    /*  Use 'nolock' variant here. Accessing this data can't lead to conflicts. */
                    pfe_pe_memcpy_from_host_to_dmem_32_nolock(
                            pe, misc_dmem, &misc_ctrl, sizeof(pfe_ct_pe_misc_control_t));

                    ret = ETIME;
                    break;
                }

                oal_time_usleep(10U);
                timeout--;
                pfe_pe_memcpy_from_dmem_to_host_32_nolock(
                        pe, &misc_ctrl, misc_dmem, sizeof(pfe_ct_pe_misc_control_t));

            } while (0U == misc_ctrl.graceful_stop_confirmation);
            /*  Access to PE memory interface is locked */
        }
    }
    return ret;
}

/**
 * @brief       Acquire lock of PE memory
 * @details     While locked, the PE can't access internal memory. Invoke the PE graceful
 *              stop request and wait for confirmation. Also lock the PE memory interface.
 * @param[in]   pe The PE instance
 * @return      EOK if success, error code otherwise
 */
errno_t pfe_pe_memlock_acquire_nolock(pfe_pe_t *pe)
{
    errno_t ret;
    PFE_PTR(pfe_ct_pe_misc_control_t) misc_dmem;

    if (NULL == pe->mmap_data)
    {
        ret = ENOEXEC;
    }
    else
    {
        misc_dmem = oal_ntohl(pe->mmap_data->common.pe_misc_control);
        if (0U == misc_dmem)
        {
            ret = EINVAL;
        }
        else
        {
            ret = pfe_pe_mem_process_lock(pe, misc_dmem);
        }
    }

    return ret;
}

/**
 * @brief       Release lock of PE memory
 * @details     While locked, the PE can't access internal memory. Here the memory
 *              and the memory interface will be unlocked.
 * @param[in]   pe The PE instance
 * @return      EOK if success, error code otherwise
 */
errno_t pfe_pe_memlock_release_nolock(pfe_pe_t *pe)
{
    errno_t ret;
    PFE_PTR(pfe_ct_pe_misc_control_t) misc_dmem;
    pfe_ct_pe_misc_control_t misc_ctrl = {0};

    if (NULL == pe->mmap_data)
    {
        ret = ENOEXEC;
    }
    else
    {
        ret = EOK;
        misc_dmem = oal_ntohl(pe->mmap_data->common.pe_misc_control);
        if (0U == misc_dmem)
        {
            ret = EINVAL;
        }
        else
        {
            /*  Cancel the stop request */
            misc_ctrl.graceful_stop_request = 0U;

            /*  Use 'nolock' variant here. Accessing this data can't lead to conflicts. */
            pfe_pe_memcpy_from_host_to_dmem_32_nolock(
                    pe, misc_dmem, &misc_ctrl, sizeof(pfe_ct_pe_misc_control_t));
        }
    }

    return ret;
}

/**
 * @brief       Get number of cycles to load PEs with configured load ops
 * @param[in]   pe The PE instance
 * @param[in]   pe_num Number of PEs that are being loaded
 * @return      Number of cycles to load all PEs
 */
static uint8_t pfe_pe_fw_load_cycles(const pfe_pe_t *pe, uint8_t pe_num)
{
    uint8_t ret = 1U;

    if (NULL != pe->fw_load_ops)
    {
        if(pe_num >= pe->fw_load_ops->pe_loaded_cnt)
        {
            ret = pe_num/pe->fw_load_ops->pe_loaded_cnt;
        }
    }

    return ret;
}

/**
 * @brief       Compare two PEs with regards of FW loading
 * @param[in]   pe1 The PE instance
 * @param[in]   pe2 The PE instance
 * @return      EOK on success
 */
static errno_t pfe_pe_fw_ops_valid(pfe_pe_t *pe1, const pfe_pe_t *pe2)
{
    errno_t ret = EINVAL;

    if ((pe1->type == pe2->type) &&
        (pe1->mem_access_addr == pe2->mem_access_addr) &&
        (pe1->mem_access_rdata == pe2->mem_access_rdata) &&
        (pe1->mem_access_wdata == pe2->mem_access_wdata))
    {
        ret = EOK;
    }

    return ret;
}

/**
 * @brief       pfe_pe_fw_install_ops auxiliary function
 * @param[in]   pe The PE instance
 * @param[in]   idx index
 * @param[in]   best_pe_loader_cnt best PE loader count
 * @param[in]   pe_num Number of PEs that are being loaded
 * @return      TRUE if condition is true
 */
static inline bool_t pfe_pe_check_pe_times (pfe_pe_t *pe, uint32_t idx, uint8_t best_pe_loader_cnt, uint8_t pe_num)
{
    bool_t ret = FALSE;

    ret = (((pe_num == fw_load_ops[idx].pe_loaded_cnt) ||
            (1U == fw_load_ops[idx].pe_loaded_cnt)) &&
           (fw_load_ops[idx].pe_loaded_cnt > best_pe_loader_cnt) &&
           (((pe[0].type == PE_TYPE_UTIL) && (fw_load_ops[idx].can_load_util == TRUE)) ||
           (pe[0].type != PE_TYPE_UTIL)));

    return ret;
}

/**
 * @brief       Get fastest possible FW load operations
 * @param[in]   pe The PE instance
 * @param[in]   pe_num Number of PEs that are being loaded
 * @return      EOK on success
 */
static errno_t pfe_pe_fw_install_ops(pfe_pe_t *pe, uint8_t pe_num)
{
    errno_t ret;
    uint32_t idx = 0U, pe_idx = 0U;
    uint8_t best_pe_loader_cnt = 0U;
    const fw_load_ops_t* pe_loader = NULL;

    for (idx = 0U; idx < (sizeof(fw_load_ops)/sizeof(fw_load_ops[0U])); ++idx)
    {
        ret = EINVAL;
        if (pfe_pe_check_pe_times(pe, idx, best_pe_loader_cnt, pe_num))
        {
            if (1U < fw_load_ops[idx].pe_loaded_cnt)
            {
                for (pe_idx = 1U; pe_idx < pe_num; ++pe_idx)
                {
                    /* To be sure that PEs are equivalent compare them here */
                    ret = pfe_pe_fw_ops_valid(&pe[0], &pe[pe_idx]);

                    if (EOK != ret)
                    {
                        NXP_LOG_ERROR("PEs are not identical\n");
                        break;
                    }
                }

                if (EOK == ret)
                {
                    best_pe_loader_cnt = fw_load_ops[idx].pe_loaded_cnt;
                    pe_loader = &fw_load_ops[idx];
                }
            }
            else
            {
                best_pe_loader_cnt = fw_load_ops[idx].pe_loaded_cnt;
                pe_loader = &fw_load_ops[idx];
            }
        }
    }

    ret = ENODEV;
    for (pe_idx = 0U; pe_idx < pe_num; ++pe_idx)
    {
        pe[pe_idx].fw_load_ops = pe_loader;
    }

    if(NULL != pe_loader)
    {
        ret = EOK;
        NXP_LOG_INFO("Selected FW loading OPs to load %d PEs in parallel\n", pe_loader->pe_loaded_cnt);
    }

    return ret;
}

/**
 * @brief       Memcpy FW data to PEs
 * @warning     This is supposed to be called only during initial FW loading.
 *              Expectation is that everything is 4B aligned and size is divisible by 4.
 *              This function loads 8 PEs at the same time.
 * @param[in]   pe The PE instance
 * @param[in]   mem Memory type
 * @param[in]   dst_addr Destination PE address
 * @param[in]   src_ptr Source host address
 * @param[in]   len Copied length
 */
static void pfe_pe_fw_memcpy_bulk(pfe_pe_t *pe, pfe_pe_mem_t mem, addr_t dst_addr, const void *src_ptr, uint32_t len)
{
    uint32_t addr_temp;
    uint32_t *data = (uint32_t*)src_ptr;
    uint32_t memsel;

    if (PFE_PE_DMEM == mem)
    {
        memsel = PE_IBUS_ACCESS_DMEM;
    }
    else
    {
        memsel = PE_IBUS_ACCESS_IMEM;
    }

    /*  Sanity check if we can safely access the memory interface */
    if (unlikely(!(*(pe->miflock))))
    {
        NXP_LOG_ERROR("Accessing unlocked PE memory interface (write).\n");
    }

    addr_temp = PE_IBUS_WRITE | memsel | PE_IBUS_WREN(0xf);

    /*
     * IF we use gray code order in the unroll we will save very large number of instructions
     *  So optimal order is
     *  0 -> 1 -> 3 -> 2 -> 6 -> 7 -> 5 -> 4
     */

    for (uint32_t mem_offs = 0U; mem_offs < len; mem_offs += 4U)
    {
        const addr_t mem_addr = ADDR_BASE_OFFSET(dst_addr, mem_offs);
        hal_write32(oal_htonl(data[mem_offs / 4U]), pe->mem_access_wdata);
        /* Just do un-rool manually to save time */
        addr_temp &= (0xff060000U);
        addr_temp |= mem_addr;
        hal_write32((uint32_t)addr_temp, pe->mem_access_addr);
        addr_temp |= ((uint32_t)1U << 20U);
        hal_write32((uint32_t)addr_temp, pe->mem_access_addr);
        addr_temp |= ((uint32_t)1U << 21U);
        hal_write32((uint32_t)addr_temp, pe->mem_access_addr);
        addr_temp &= ~((uint32_t)1U << 20U);
        hal_write32((uint32_t)addr_temp, pe->mem_access_addr);
        addr_temp |= ((uint32_t)1U << 22U);
        hal_write32((uint32_t)addr_temp, pe->mem_access_addr);
        addr_temp |= ((uint32_t)1U << 20U);
        hal_write32((uint32_t)addr_temp, pe->mem_access_addr);
        addr_temp &= ~((uint32_t)1U << 21U);
        hal_write32((uint32_t)addr_temp, pe->mem_access_addr);
        addr_temp &= ~((uint32_t)1U << 20U);
        hal_write32((uint32_t)addr_temp, pe->mem_access_addr);
    }
}

/**
 * @brief       Memset PEs memory
 * @warning     This is supposed to be called only during initial FW loading.
 *              Expectation is that everything is 4B aligned and size is divisible by 4.
 *              This function loads 8 PEs at the same time.
 * @param[in]   pe The PE instance
 * @param[in]   mem Memory type
 * @param[in]   val Value to set the memory
 * @param[in]   addr Destination PE address
 * @param[in]   size Copied length
 */
static void pfe_pe_fw_memset_bulk(pfe_pe_t *pe, pfe_pe_mem_t mem, uint32_t val, addr_t addr, uint32_t size)
{
    uint32_t addr_temp;
    uint32_t memsel;

    if (PFE_PE_DMEM == mem)
    {
        memsel = PE_IBUS_ACCESS_DMEM;
    }
    else
    {
        memsel = PE_IBUS_ACCESS_IMEM;
    }

    /*  Sanity check if we can safely access the memory interface */
    if (unlikely(!(*(pe->miflock))))
    {
        NXP_LOG_ERROR("Accessing unlocked PE memory interface (write).\n");
    }

    hal_write32(oal_htonl(val), pe->mem_access_wdata);

    addr_temp = PE_IBUS_WRITE | memsel | PE_IBUS_WREN(0xf);

    /*
     * IF we use gray code order in the unroll we will save very large number of instructions
     *  So optimal order is
     *  0 -> 1 -> 3 -> 2 -> 6 -> 7 -> 5 -> 4
     */

    for (uint32_t mem_offs = 0U; mem_offs < size; mem_offs += 4U)
    {
        const addr_t mem_addr = ADDR_BASE_OFFSET(addr, mem_offs);
        /* Just do un-rool to save time manually to save time */
        addr_temp &= (0xff060000U);
        addr_temp |= mem_addr;
        hal_write32((uint32_t)addr_temp, pe->mem_access_addr);
        addr_temp |= ((uint32_t)1U << 20U);
        hal_write32((uint32_t)addr_temp, pe->mem_access_addr);
        addr_temp |= ((uint32_t)1U << 21U);
        hal_write32((uint32_t)addr_temp, pe->mem_access_addr);
        addr_temp &= ~((uint32_t)1U << 20U);
        hal_write32((uint32_t)addr_temp, pe->mem_access_addr);
        addr_temp |= ((uint32_t)1U << 22U);
        hal_write32((uint32_t)addr_temp, pe->mem_access_addr);
        addr_temp |= ((uint32_t)1U << 20U);
        hal_write32((uint32_t)addr_temp, pe->mem_access_addr);
        addr_temp &= ~((uint32_t)1U << 21U);
        hal_write32((uint32_t)addr_temp, pe->mem_access_addr);
        addr_temp &= ~((uint32_t)1U << 20U);
        hal_write32((uint32_t)addr_temp, pe->mem_access_addr);
    }
}

/**
 * @brief       Memset PEs memory
 * @warning     This is supposed to be called only during initial FW loading.
 *              Expectation is that everything is 4B aligned and size is divisible by 4.
 *              This function can load single PE only.
 * @param[in]   pe The PE instance
 * @param[in]   mem Memory type
 * @param[in]   dst_addr Destination PE address
 * @param[in]   src_ptr Source host address
 * @param[in]   len Copied length
 */
static void pfe_pe_fw_memcpy_single(pfe_pe_t *pe, pfe_pe_mem_t mem, addr_t dst_addr, const void *src_ptr, uint32_t len)
{
    uint32_t addr_temp;
    uint32_t *data = (uint32_t*)src_ptr;
    uint32_t memsel;

    if (PFE_PE_DMEM == mem)
    {
        memsel = PE_IBUS_ACCESS_DMEM;
    }
    else
    {
        memsel = PE_IBUS_ACCESS_IMEM;
    }

    /*  Sanity check if we can safely access the memory interface */
    if (unlikely(!(*(pe->miflock))))
    {
        NXP_LOG_ERROR("Accessing unlocked PE memory interface (write).\n");
    }

    addr_temp = PE_IBUS_WRITE | memsel | PE_IBUS_WREN(0xf) | PE_IBUS_PE_ID(pe->id);

    for (uint32_t mem_offs = 0U; mem_offs < len; mem_offs += 4U)
    {
        const addr_t mem_addr = ADDR_BASE_OFFSET(dst_addr, mem_offs);
        hal_write32(oal_htonl(data[mem_offs / 4U]), pe->mem_access_wdata);
        addr_temp &= (0xfff60000U);
        addr_temp |= mem_addr;
        hal_write32((uint32_t)addr_temp, pe->mem_access_addr);
    }
}

/**
 * @brief       Memset PEs memory
 * @warning     This is supposed to be called only during initial FW loading.
 *              Expectation is that everything is 4B aligned and size is divisible by 4.
 *              This function can load single PE only.
 * @param[in]   pe The PE instance
 * @param[in]   mem Memory type
 * @param[in]   val Value to set the memory
 * @param[in]   addr Destination PE address
 * @param[in]   size Copied length
 */
static void pfe_pe_fw_memset_single(pfe_pe_t *pe, pfe_pe_mem_t mem, uint32_t val, addr_t addr, uint32_t size)
{
    uint32_t addr_temp;
    uint32_t memsel;

    if (PFE_PE_DMEM == mem)
    {
        memsel = PE_IBUS_ACCESS_DMEM;
    }
    else
    {
        memsel = PE_IBUS_ACCESS_IMEM;
    }

    /*  Sanity check if we can safely access the memory interface */
    if (unlikely(!(*(pe->miflock))))
    {
        NXP_LOG_ERROR("Accessing unlocked PE memory interface (write).\n");
    }

    hal_write32(oal_htonl(val), pe->mem_access_wdata);

    addr_temp = PE_IBUS_WRITE | memsel | PE_IBUS_WREN(0xf) | PE_IBUS_PE_ID(pe->id);

    /* We could potentially do some manual unroll here */
    for (uint32_t mem_offs = 0U; mem_offs < size; mem_offs += 4U)
    {
        const addr_t mem_addr = ADDR_BASE_OFFSET(addr, mem_offs);
        addr_temp &= (0xfff60000U);
        addr_temp |= mem_addr;
        hal_write32((uint32_t)addr_temp, pe->mem_access_addr);
    }
}

/**
 * @brief       Read data from PE memory
 * @param[in]   pe The PE instance
 * @param[in]   mem Memory to access
 * @param[in]   addr Read address (should be aligned to 32 bits)
 * @param[in]   size Number of bytes to read (maximum 4)
 * @return      The data read (BE).
 */
static uint32_t pfe_pe_mem_read(pfe_pe_t *pe, pfe_pe_mem_t mem, addr_t addr, uint8_t size)
{
    uint32_t val;
    uint32_t mask;
    uint32_t memsel;
    uint8_t size_temp = size;
    addr_t adrr_temp = addr;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == pe))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        val = 0U;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (size_temp != 4U)
        {
            mask = ((uint32_t)1U << (size_temp * 8U)) - 1U;
        }
        else
        {
            mask = 0xffffffffU;
        }

        if (PFE_PE_DMEM == mem)
        {
            memsel = PE_IBUS_ACCESS_DMEM;
        }
        else
        {
            memsel = PE_IBUS_ACCESS_IMEM;
        }

        adrr_temp = (adrr_temp & 0xfffffU)
                    | PE_IBUS_READ
                    | memsel
                    | PE_IBUS_PE_ID(pe->id)
                    | PE_IBUS_WREN(0U);

        /*  Sanity check if we can safely access the memory interface */
        if (unlikely(!(*(pe->miflock))))
        {
            NXP_LOG_ERROR("Accessing unlocked PE memory interface (read).\n");
        }

        hal_write32((uint32_t)adrr_temp, pe->mem_access_addr);
        val = oal_ntohl(hal_read32(pe->mem_access_rdata));

        if (unlikely(adrr_temp & 0x3U))
        {
            /*  Move the value to the desired address offset */
            val = (val >> (8U * (adrr_temp & 0x3U)));
        }
        val = val & mask;
    }

    return val;
}

/**
 * @brief       Write data into PE memory
 * @param[in]   pe The PE instance
 * @param[in]   memdata Parameters of the memory to access
 */
static void pfe_pe_mem_write(pfe_pe_t *pe, pfe_pe_mem_data_t memdata)
{
    uint8_t bytesel = 0U;
    uint32_t memsel = 0U;
    uint8_t offset_temp = memdata.offset;
    uint32_t val_temp = memdata.val;
    uint8_t size_temp = memdata.size;
    addr_t addr_temp = memdata.addr;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == pe))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (unlikely((0U != offset_temp)))
        {
            PfeDevAssert(offset_temp >= size_temp);
            PfeDevAssert(offset_temp <= 3U);
            /* Move the value to the desired address offset */
            val_temp = memdata.val << (8U * (addr_temp & ALIGNMENT_CHECKMASK));
            /* Enable writes of depicted bytes */
            bytesel = (uint8_t)((1U << (offset_temp - size_temp)) & UINT8_MAX);
        }
        else
        {
            PfeDevAssert(size_temp <= 4U);
            /*  Destination is aligned */
            bytesel = (uint8_t)(PE_IBUS_BYTES(size_temp) & UINT8_MAX);
        }

        if (PFE_PE_DMEM == memdata.mem)
        {
            memsel = PE_IBUS_ACCESS_DMEM;
        }
        else
        {
            memsel = PE_IBUS_ACCESS_IMEM;
        }

        addr_temp = (addr_temp & 0xfffffU)
                | PE_IBUS_WRITE
                | memsel
                | PE_IBUS_PE_ID(pe->id)
                | PE_IBUS_WREN(bytesel);

        /*  Sanity check if we can safely access the memory interface */
        if (unlikely(!(*(pe->miflock))))
        {
            NXP_LOG_ERROR("Accessing unlocked PE memory interface (write).\n");
        }

        hal_write32(oal_htonl(val_temp), pe->mem_access_wdata);
        hal_write32((uint32_t)addr_temp, pe->mem_access_addr);
    }
}

/**
 * @brief       Read 'len' limited upto 4 bytes to uint32_t val
 * @note        Function expects the source data to be in host endian format
 *              and reads only required number of bytes to avoid out-of-bound issues
 * @param[in]   src_byteptr Buffer source address (virtual)
 * @param[in]   len Number of bytes to read
 * @return      The data read (LE).
 */
static inline uint32_t pfe_pe_get_u32_from_byteptr(const uint8_t *src_byteptr, uint32_t len)
{
    uint32_t val;

    switch (len)
    {
        case 1:
            val = *src_byteptr;
            break;
        case 2:
            val = *(uint16_t *)src_byteptr;
            break;
        case 3:
            val = *(uint16_t *)src_byteptr;
            val += ((uint32_t)*(src_byteptr + 2U)) << 16U;
            break;
        default:
            val = *(uint32_t *)src_byteptr;
            break;
    }

    return val;
}

/**
 * @brief       Write 'len' bytes to DMEM
 * @note        Function expects the source data to be in host endian format.
 * @param[in]   pe The PE instance
 * @param[in]   src_ptr Buffer source address (virtual)
 * @param[in]   dst_addr DMEM destination address (must be 32-bit aligned)
 * @param[in]   len Number of bytes to read
 */
static void pfe_pe_memcpy_from_host_to_dmem_32_nolock(
        pfe_pe_t *pe, addr_t dst_addr, const void *src_ptr, uint32_t len)
{
    /* Avoid void pointer arithmetics */
    const uint8_t *src_byteptr = src_ptr;
    uint32_t len_temp = len;
    pfe_pe_mem_data_t mem_data = {.mem = PFE_PE_DMEM, .addr = dst_addr, .val = 0, .offset = 0, .size = 0 };

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == pe))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* First loop is for the unaligned dst_addr */
        /* It fills the offset with one by one byte taken from src_ptr */
        while ((0U != (mem_data.addr & ALIGNMENT_CHECKMASK)) && (0U != len_temp))
        {
            mem_data.offset = BYTES_TO_4B_ALIGNMENT(mem_data.addr);
            mem_data.val = *src_byteptr;
            mem_data.size = 1U;
            pfe_pe_mem_write(pe, mem_data);
            mem_data.addr += 1U;
            src_byteptr += 1U;
            len_temp -= 1U;
        }
        /* Second loops if to write the data with 4 bytes each time to the aligned address */
        while (ALIGNMENT_PACKEDNUMBER <= len_temp)
        {
            /*  4-byte writes */
            mem_data.offset = 0U;
            mem_data.val = *(uint32_t *)src_byteptr;
            mem_data.size = 4U;
            pfe_pe_mem_write(pe, mem_data);
            len_temp -= 4U;
            src_byteptr += 4U;
            mem_data.addr += 4U;
        }
        /* The last step is to write the trailing last data to the aligned address */
        if (0U != len_temp)
        {
            /*  The rest */
            mem_data.offset = 0U;
            mem_data.val = pfe_pe_get_u32_from_byteptr(src_byteptr, len_temp);
            mem_data.size = len_temp;
            pfe_pe_mem_write(pe, mem_data);
        }
    }
}

/**
 * @brief       Write 'len' bytes to DMEM
 * @note        Function expects the source data to be in host endian format.
 * @param[in]   pe The PE instance
 * @param[in]   src_ptr Buffer source address (virtual)
 * @param[in]   dst_addr DMEM destination address (must be 32-bit aligned)
 * @param[in]   len Number of bytes to read
 */
void pfe_pe_memcpy_from_host_to_dmem_32(pfe_pe_t *pe, addr_t dst_addr, const void *src_ptr, uint32_t len)
{
    errno_t ret;

    /* Lock family */
    if (PE_TYPE_CLASS == pe->type)
    {
        oal_mutex_lock(PFE_CLASS_PE_MUTEX_00);
    }
    else
    {
        oal_mutex_lock(PFE_UTIL_PE_MUTEX_00);
    }
    pfe_pe_lock_family(pe);

    /* Acquire memlock for all PE cores. They will stop processing frames and wait.
       This will ensure data coherence. */
    ret = pfe_pe_memlock_acquire_nolock(pe);
    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Memory lock failed\n");
    }
    else
    {
        pfe_pe_memcpy_from_host_to_dmem_32_nolock(pe, dst_addr, src_ptr, len);

        if (EOK != pfe_pe_memlock_release_nolock(pe))
        {
            NXP_LOG_DEBUG("Memory unlock failed\n");
        }
    }
    /* Unlock family */
    pfe_pe_unlock_family(pe);
    if (PE_TYPE_CLASS == pe->type)
    {
        oal_mutex_unlock(PFE_CLASS_PE_MUTEX_00);
    }
    else
    {
        oal_mutex_unlock(PFE_UTIL_PE_MUTEX_00);
    }
}

/**
 * @brief       Read 'len' bytes from DMEM
 * @param[in]   pe The PE instance
 * @param[in]   src_addr DMEM source address (must be 32-bit aligned)
 * @param[in]   dst_ptr Destination address (virtual)
 * @param[in]   len Number of bytes to read
 *
 */
void pfe_pe_memcpy_from_dmem_to_host_32_nolock(pfe_pe_t *pe, void *dst_ptr, addr_t src_addr, uint32_t len)
{
    uint32_t val;
    /* Avoid void pointer arithmetics */
    uint8_t *dst_byteptr = dst_ptr;
    addr_t src_temp = src_addr;
    uint32_t len_temp = len;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == pe))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* First loop, read each byte until the src_temp is aligned with four */
        while ((0U != (src_temp & ALIGNMENT_CHECKMASK)) && (0U != len_temp))
        {
            /*  Read unaligned bytes to align the source address */
            val = pfe_pe_mem_read(pe, PFE_PE_DMEM, (uint32_t)src_temp, 1U);
            (void)autolibc_memcpy((void*)dst_byteptr, (const void*)&val, 1U);
            dst_byteptr += 1U;
            src_temp += 1U;
            len_temp -= 1U;
        }

        /* Second loop, read four bytes each time until the length of the data is under four */
        while (ALIGNMENT_PACKEDNUMBER <= len_temp)
        {
            /*  4-byte reads */
            val = pfe_pe_mem_read(pe, PFE_PE_DMEM, (uint32_t)src_temp, 4U);
            *((uint32_t *)dst_byteptr) = val;
            len_temp-=4U;
            src_temp+=4U;
            dst_byteptr+=4U;
        }

        /* The last step, read the trailing last bytes of the data length */
        if (0U != len_temp)
        {
            /*  The rest */
            val = pfe_pe_mem_read(pe, PFE_PE_DMEM, (uint32_t)src_temp, (uint8_t)len_temp);
            (void)autolibc_memcpy((void*)dst_byteptr, (const void*)&val, len_temp);
        }
    }
}

/**
 * @brief       Read 'len' bytes from DMEM
 * @param[in]   pe The PE instance
 * @param[in]   src_addr DMEM source address (must be 32-bit aligned)
 * @param[in]   dst_ptr Destination address (virtual)
 * @param[in]   len Number of bytes to read
 *
 */
void pfe_pe_memcpy_from_dmem_to_host_32(pfe_pe_t *pe, void *dst_ptr, addr_t src_addr, uint32_t len)
{
    errno_t ret;

    /* Lock family */
    if (PE_TYPE_CLASS == pe->type)
    {
        oal_mutex_lock(PFE_CLASS_PE_MUTEX_01);
    }
    else
    {
        oal_mutex_lock(PFE_UTIL_PE_MUTEX_01);
    }
    pfe_pe_lock_family(pe);

    /* Acquire memlock for all PE cores. They will stop processing frames and wait.
       This will ensure data coherence. */
    ret = pfe_pe_memlock_acquire_nolock(pe);
    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Memory lock failed\n");
    }
    else
    {
        pfe_pe_memcpy_from_dmem_to_host_32_nolock(pe, dst_ptr, src_addr, len);

        if (EOK != pfe_pe_memlock_release_nolock(pe))
        {
            NXP_LOG_DEBUG("Memory unlock failed\n");
        }
    }
    /* Unlock family */
    pfe_pe_unlock_family(pe);
    if (PE_TYPE_CLASS == pe->type)
    {
        oal_mutex_unlock(PFE_CLASS_PE_MUTEX_01);
    }
    else
    {
        oal_mutex_unlock(PFE_UTIL_PE_MUTEX_01);
    }
}

/**
 * @brief       Read 'len' bytes from DMEM from each PE
 * @details     Reads PE internal data memory (DMEM) into a host memory through indirect
 *              access registers. The result from each PE are stored consecutively in memory
 *              pointed by dst.
 * @param[in]   pe Array of the PE instances
 * @param[in]   src_addr DMEM source address (physical within PE, must be 32bit aligned)
 * @param[in]   dst_ptr Destination address (virtual) the size required to store the data is pe_count*len
 * @param[in]   buffer_len Destination buffer length
 * @param[in]   read_len Number of bytes to read (from one PE)
 *
 */
errno_t pfe_pe_gather_memcpy_from_dmem_to_host_32(pfe_pe_t *pe, int32_t pe_count, void *dst_ptr, addr_t src_addr, uint32_t buffer_len, uint32_t read_len)
{
    int32_t ii = 0U;
    boolean is_mem_lock_error = FALSE;
    errno_t ret = EOK;
    errno_t ret_store = EOK;

    /* Lock family */
    /* NOTE: Use the mutex lock for CLASS PE here because the pfe_pe_gather_memcpy_from_dmem_to_host_32() is only called from CLASS FW */
    oal_mutex_lock(PFE_CLASS_PE_MUTEX_06);
    pfe_pe_lock_family(pe);

    /* Acquire memlock for all PE cores. They will stop processing frames and wait.
       This will ensure data coherence. */
    for (ii = 0; ii < pe_count; ii++)
    {
        ret = pfe_pe_memlock_acquire_nolock(&pe[ii]);
        if (EOK != ret)
        {
            is_mem_lock_error = TRUE;
            NXP_LOG_ERROR("Memory lock failed for PE instance %d\n", (int_t)ii);
            /* Save the error */
            ret_store = ret;
        }
    }

    /* Only read from PEs if all PEs are locked */
    if (is_mem_lock_error == FALSE)
    {
        /* Perform the read from required PEs */
        for (ii = 0; ii < pe_count; ii++)
        {
            /* Check if there is still memory  */
            if (buffer_len >= ((read_len * (uint32_t)ii) + read_len))
            {
                pfe_pe_memcpy_from_dmem_to_host_32_nolock(&pe[ii],
                        (void *)((uint8_t*)dst_ptr + (read_len * (uint32_t)ii)),
                            src_addr, read_len);
            }
            else
            {
                /* Memory limit reached. Save the error. */
                ret_store = ENOMEM;
                break;
            }
        }
    }

    /* Release memlock for all PE cores */
    for (ii = 0; ii < pe_count; ii++)
    {
        ret = pfe_pe_memlock_release_nolock(&pe[ii]);
        if(EOK != ret)
        {
            NXP_LOG_ERROR("Memory unlock failed\n");
            /* Save the error */
            ret_store = ret;
        }
    }

    /* If there was any error during the whole process, then return it. */
    ret = ret_store;

    /* Unlock family */
    pfe_pe_unlock_family(pe);
    oal_mutex_unlock(PFE_CLASS_PE_MUTEX_06);

    return ret;
}

/**
 * @brief       Load an elf section into DMEM
 * @details     Size and load address need to be at least 32-bit aligned
 * @param[in]   pe The PE instance
 * @param[in]   sdata Pointer to the elf section data
 * @param[in]   addr Load address of the section
 * @param[in]   size Size of the section
 * @param[in]   type Section type
 * @retval      EOK Success
 * @retval      EINVAL Unsupported section type or wrong input address alignment
 */
static errno_t pfe_pe_load_dmem_section_nolock(pfe_pe_t *pe, const void *sdata, addr_t addr, addr_t size, uint32_t type)
{
    errno_t ret = EOK;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == pe) || (NULL == sdata)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
    {
#endif /* PFE_CFG_NULL_ARG_CHECK */

    if (((addr_t)(sdata) & 0x3U) != (addr & 0x3U))
    {
        NXP_LOG_ERROR("Load address 0x%p and elf file address 0x%p don't have the same alignment\n", (void *)addr, sdata);
        ret = EINVAL;
    }
    else
    {
        if ((addr & 0x3U) != 0U)
        {
            NXP_LOG_ERROR("Load address 0x%p is not 32bit aligned\n", (void *)addr);
            ret = EINVAL;
        }
        else
        {
            switch (type)
            {
                case 0x7000002aU: /* MIPS.abiflags */
                {
                    /* Skip the section */
                    break;
                }
                case (uint32_t)SHT_PROGBITS:
                {
                    /*  Write section data */
                    pe->fw_load_ops->pe_memcpy(pe, PFE_PE_DMEM, OFFSET_ADDR_BASE(addr, pe->dmem_elf_base_va), sdata, size);
                    break;
                }

                case (uint32_t)SHT_NOBITS:
                {
                    pe->fw_load_ops->pe_memset(pe, PFE_PE_DMEM, 0U, addr, size);
                    break;
                }

                default:
                {
                    NXP_LOG_ERROR("Unsupported section type: 0x%x\n", (uint_t)type);
                    ret = EINVAL;
                    break;
                }
            }
        }
    }
#if defined(PFE_CFG_NULL_ARG_CHECK)
    }
#endif

    return ret;
}

/**
 * @brief       Load an elf section into IMEM
 * @details     Code needs to be at least 16bit aligned and only PROGBITS sections are supported
 * @param[in]   pe The PE instance
 * @param[in]   data Pointer to the elf section data
 * @param[in]   addr Load address of the section
 * @param[in]   size Size of the section
 * @param[in]   type Type of the section
 * @retval      EOK Success
 * @retval      EFAULT Wrong input address alignment
 * @retval      EINVAL Unsupported section type
 */
static errno_t pfe_pe_load_imem_section_nolock(pfe_pe_t *pe, const void *data, addr_t addr, addr_t size, uint32_t type)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == pe) || (NULL == data)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ret = EOK;
        /*  Check alignment first */
        if (((addr_t)(data) & 0x3U) != (addr & 0x1U))
        {
            NXP_LOG_ERROR("Load address 0x%p and elf file address 0x%p) don't have the same alignment\n",
                    (void *)addr, data);
            ret = EFAULT;
        }
        else if ((addr & 0x1U) != 0U)
        {
            NXP_LOG_ERROR("Load address 0x%p is not 16bit aligned\n", (void *)addr);
            ret = EFAULT;
        }
        else if ((size & 0x1U) != 0U)
        {
            NXP_LOG_ERROR("Load size 0x%p is not 16bit aligned\n", (void *)size);
            ret = EFAULT;
        }
        else
        {
            switch (type)
            {
                case 0x7000002aU: /* MIPS.abiflags */
                {
                    /* Skip the section */
                    break;
                }
                case (uint32_t)SHT_PROGBITS:
                {
                    /*  Write section data */
                    pe->fw_load_ops->pe_memcpy(pe, PFE_PE_IMEM, OFFSET_ADDR_BASE(addr, pe->imem_elf_base_va), data, size);
                    break;
                }

                default:
                {
                    NXP_LOG_ERROR("Unsupported section type: 0x%x\n", (uint_t)type);
                    ret = EINVAL;
                    break;
                }
            }
        }
    }

    return ret;
}

/**
 * @brief       Check if memory region belongs to DMEM
 * @param[in]   pe The PE instance
 * @param[in]   addr Address to be checked
 * @param[in]   size Length of the region to be checked
 * @return      TRUE if given range belongs to DMEM
 */
static bool_t pfe_pe_is_dmem(const pfe_pe_t *pe, addr_t addr, uint32_t size)
{
    addr_t reg_end;
    bool_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == pe))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = FALSE;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        reg_end = ADDR_BASE_OFFSET(pe->dmem_elf_base_va, pe->dmem_size);

        if ((addr >= pe->dmem_elf_base_va) && (ADDR_BASE_OFFSET(addr, size) < reg_end))
        {
            ret = TRUE;
        }
        else
        {
            ret = FALSE;
        }
    }
    return ret;
}

/**
 * @brief       Check if memory region belongs to IMEM
 * @param[in]   pe The PE instance
 * @param[in]   addr Address to be checked
 * @param[in]   size Length of the region to be checked
 * @return      TRUE if given range belongs to IMEM
 */
static bool_t pfe_pe_is_imem(const pfe_pe_t *pe, addr_t addr, uint32_t size)
{
    addr_t reg_end;
    bool_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == pe))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = FALSE;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        reg_end = ADDR_BASE_OFFSET(pe->imem_elf_base_va, pe->imem_size);

        if ((addr >= pe->imem_elf_base_va) && (ADDR_BASE_OFFSET(addr, size) < reg_end))
        {
            ret = TRUE;
        }
        else
        {
            ret = FALSE;
        }
    }

    return ret;
}

/**
 * @brief       Write elf section to PE memory
 * @details     Function expects the section data is in host endian format
 * @param[in]   pe The PE instance
 * @param[in]   sdata Pointer to the data described by 'shdr'
 * @param[in]   load_addr Address where to load the section
 * @param[in]   size Size of the section to load
 * @param[in]   type Type of the section to load
 */
static errno_t pfe_pe_load_elf_section(pfe_pe_t *pe, const void *sdata, addr_t load_addr, addr_t size, uint32_t type)
{
    errno_t ret_val;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == pe) || (NULL == sdata)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret_val = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */

    if (pfe_pe_is_dmem(pe, load_addr, size))
    {
        /*  Section belongs to DMEM */
        ret_val = pfe_pe_load_dmem_section_nolock(pe, sdata, load_addr, size, type);
    }
    else if (pfe_pe_is_imem(pe, load_addr, size))
    {
        /*  Section belongs to IMEM */
        ret_val = pfe_pe_load_imem_section_nolock(pe, sdata, load_addr, size, type);
    }
    else
    {
        NXP_LOG_ERROR("Unsupported memory range %p\n", (void *)load_addr);
        ret_val = EINVAL;
    }

    return ret_val;
}

/**
 * @brief Translates section virtual address into load address
 * @param[in] elf_file Elf file containing the section to translate the address
 * @param[in] shdr Section header of the section to translate the address
 * @details Elf file section header contains only section virtual address which is used by the
 *          running software. The virtual address needs to be translated to load address which
 *          is address where the section is loaded into memory. In most cases the virtual and
 *          load address are equal.
 * @return Load address of the given section or 0 on failure.
 */
static addr_t pfe_pe_get_elf_sect_load_addr(const ELF_File_t *elf_file, const Elf32_Shdr *shdr)
{
    addr_t virt_addr = ENDIAN_SW_4B(shdr->sh_addr);
    addr_t load_addr = 0U;
    bool_t stt = FALSE;

    /* Go through all program headers to find one containing the section */
    for (uint_t ii=0U; ii<elf_file->Header.r32.e_phnum; ii++)
    {
        const Elf32_Phdr *phdr = &elf_file->arProgHead32[ii];
        if((virt_addr >= ENDIAN_SW_4B(phdr->p_vaddr)) &&
        (ADDR_BASE_OFFSET(virt_addr, ENDIAN_SW_4B(shdr->sh_size)) <= ADDR_BASE_OFFSET(ENDIAN_SW_4B(phdr->p_vaddr), ENDIAN_SW_4B(phdr->p_memsz))))
        {   /* Address belongs into this segment */
            /* Calculate the offset between segment load and virtual address */
            const uint32_t offset = OFFSET_ADDR_BASE(ENDIAN_SW_4B(phdr->p_paddr), ENDIAN_SW_4B(phdr->p_vaddr));
            /* Same offset applies also for sections in the segment */
            load_addr = ADDR_BASE_OFFSET(virt_addr, offset);
            stt = TRUE;
            break;
        }
    }

    if(FALSE == stt)
    {
        /* No segment containing the section was found ! */
        NXP_LOG_ERROR("Translation of 0x%"PRINTADDR_T"x failed, fallback used\n", virt_addr);
    }

    return load_addr;
}

/**
 * @brief         Create new PE instance
 * @param[in]     cbus_base_va CBUS base address (virtual)
 * @param[in]     type Type of PE to create @see pfe_pe_type_t
 * @param[in]     id PE ID
 * @param[in,out] pe The PE instance
 * @param[in]     miflock pointer to miflock diagnostic flag of this PE core
 * @return        The PE instance or NULL if failed
 */
pfe_pe_t * pfe_pe_create(addr_t cbus_base_va, pfe_ct_pe_type_t type, uint8_t id, pfe_pe_t *pe, bool_t *miflock)
{
    pfe_pe_t *tmp_pe = pe;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL_ADDR == cbus_base_va) || (NULL == pe) || (NULL == miflock)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        tmp_pe = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if ((type != PE_TYPE_INVALID) && (type < PE_TYPE_MAX))
        {
            (void)autolibc_memset(tmp_pe, 0, sizeof(pfe_pe_t));
            tmp_pe->type = type;
            tmp_pe->cbus_base_va = cbus_base_va;
            tmp_pe->id = id;
            tmp_pe->fw_msg_section = NULL;
            tmp_pe->mmap_data = NULL;
            tmp_pe->miflock = miflock;
        }
    }

    return tmp_pe;
}

/**
 * @brief       Set DMEM base address for .elf mapping
 * @warning     Not intended to be called when PE is running
 * @param[in]   pe The PE instance
 * @param[in]   elf_base DMEM base virtual address within .elf
 * @param[in]   len DMEM memory length
 */
void pfe_pe_set_dmem(pfe_pe_t *pe, addr_t elf_base, addr_t len)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == pe))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pe->dmem_elf_base_va = elf_base;
        pe->dmem_size = len;
    }
}

/**
 * @brief       Set IMEM base address for .elf mapping
 * @warning     Not intended to be called when PE is running
 * @param[in]   pe The PE instance
 * @param[in]   elf_base_va IMEM base virtual address within .elf
 * @param[in]   len IMEM memory length
 */
void pfe_pe_set_imem(pfe_pe_t *pe, addr_t elf_base, addr_t len)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == pe))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pe->imem_elf_base_va = elf_base;
        pe->imem_size = len;
    }
}

/**
 * @brief       Set LMEM base address
 * @param[in]   pe The PE instance
 * @param[in]   elf_base_va LMEM base virtual address within .elf
 * @param[in]   len LMEM memory length
 */
void pfe_pe_set_lmem(pfe_pe_t *pe, addr_t elf_base, addr_t len)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == pe))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pe->lmem_base_addr_pa = elf_base;
        pe->lmem_size = len;
    }
}

/**
 * @brief       Set indirect access registers
 * @param[in]   pe The PE instance
 * @param[in]   wdata_reg The WDATA register address as appears on CBUS
 * @param[in]   rdata_reg The RDATA register address as appears on CBUS
 * @param[in]   addr_reg The ADDR register address as appears on CBUS
 */
void pfe_pe_set_iaccess(pfe_pe_t *pe, uint32_t wdata_reg, uint32_t rdata_reg, uint32_t addr_reg)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == pe))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pe->mem_access_addr =  ADDR_BASE_OFFSET(pe->cbus_base_va, addr_reg);
        pe->mem_access_rdata = ADDR_BASE_OFFSET(pe->cbus_base_va, rdata_reg);
        pe->mem_access_wdata = ADDR_BASE_OFFSET(pe->cbus_base_va, wdata_reg);
    }
}

/*print firmware issues*/
static void print_fw_issue(const pfe_ct_pe_mmap_t *fw_mmap)
{
#ifdef NXP_LOG_ENABLED
    NXP_LOG_ERROR("Unsupported firmware detected: Found revision %d.%d.%d (fwAPI:%s), required fwAPI %s\n",
            fw_mmap->common.version.major, fw_mmap->common.version.minor, fw_mmap->common.version.patch, fw_mmap->common.version.cthdr,
            TOSTRING(PFE_CFG_PFE_CT_H_MD5));
#else
    (void)fw_mmap;
#endif
}

/**
 * @brief       Default Init PEs memory when no Firmware to load
 *              This is to avoid in case firmware class/util intenional no need to load
 *              PFs memory still need to be intialize properly to avoid FCC related errors
 * @param[in]   pe The PE instances
 * @param[in]   pe_num Number of PE instances
 * @return      EOK if success, error code otherwise
 */
errno_t pfe_pe_mem_default_init(pfe_pe_t *pe, uint32_t pe_num)
{
    uint32_t pe_idx;
    errno_t ret = EOK;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == pe)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* Lock family */
        /* NOTE: Use the mutex lock for UTIL PE here because the pfe_pe_mem_default_init() is only called from UTIL FW */
        oal_mutex_lock(PFE_UTIL_PE_MUTEX_03);
        pfe_pe_lock_family(pe);

        ret =  pfe_pe_fw_install_ops(pe, (uint8_t)(pe_num & UINT8_MAX));
        if (EOK != ret)
        {
            NXP_LOG_ERROR("Couldn't find PE load operations: %d\n", ret);
        }

        for (pe_idx = 0; pe_idx < pfe_pe_fw_load_cycles(&pe[0], (uint8_t)(pe_num & UINT8_MAX)); ++pe_idx)
        {
            /* Check that we have the ops */
            if(NULL == pe[pe_idx].fw_load_ops)
            {
                ret = ENODEV;
            }

            pe[pe_idx].fw_load_ops->pe_memset(&pe[pe_idx], PFE_PE_DMEM, 0, 0, pe[pe_idx].dmem_size);
            pe[pe_idx].fw_load_ops->pe_memset(&pe[pe_idx], PFE_PE_IMEM, 0, 0, pe[pe_idx].imem_size);
        }

        /* Unlock family */
        pfe_pe_unlock_family(pe);
        oal_mutex_unlock(PFE_UTIL_PE_MUTEX_03);
    }

    return ret;
}
/**
 * @brief       Auxiliary of pfe_pe_load_firmware function
 * @param[in]   pe The PE instances
 * @param[in]   pe_num Number of PE instances
 * @param[in]   elf The elf file object to be uploaded
 * @return      EOK if success, error code otherwise
 */
static errno_t pfe_pe_load_firmware_aux(pfe_pe_t *pe, uint32_t pe_num, const void *elf)
{
    errno_t ret = EOK;
    uint32_t section_idx = 0U;
    uint32_t ii, mask_sectIdx;
    uint32_t features_size = 0, messages_size = 0;
    void *features_mem = NULL, *messages_mem = NULL;
    const Elf32_Shdr *shdr = NULL;
    bool_t bFwVersionMatch = TRUE;
    bool_t bElfBigEndian = TRUE;
    uint32_t mmap_size = 0U;
    const ELF_File_t *elf_file = (ELF_File_t *)elf;

    /*  Attempt to get section containing firmware memory map data */
    if (TRUE == ELF_SectFindName(elf_file, ".pfe_pe_mmap", &section_idx, NULL, NULL))
    {
        /* Mask out the flag to get section id */
        mask_sectIdx = (~(ELF_NAMED_SECT_IDX_FLAG) & section_idx);

        /*  Load section to RAM */
        shdr = &elf_file->arSectHead32[mask_sectIdx];

        /* Get the mmap size, used to load correct data from FW file*/
        (void)autolibc_memcpy(
                (void*)&mmap_size,
                (const void*)((addr_t)elf_file->pvData + ENDIAN_SW_4B(shdr->sh_offset)),
                sizeof(uint32_t));

        /* Convert mmap size endian ! */
        mmap_size = oal_ntohl(mmap_size);

        /*  Firmware version check */
        static const char_t mmap_version_str[] = TOSTRING(PFE_CFG_PFE_CT_H_MD5);

        (void)autolibc_memcpy(
                (void*)&tmp_mmap,
                (const void*)((addr_t)elf_file->pvData + ENDIAN_SW_4B(shdr->sh_offset)),
                mmap_size);

        if(0 != autolibc_strcmp(mmap_version_str, tmp_mmap.common.version.cthdr))
        {
            bFwVersionMatch = FALSE;
            ret = EINVAL;
            print_fw_issue(&tmp_mmap);
            pfe_pe_free_mem(pe, pe_num);
        }
        else
        {
            NXP_LOG_INFO("pfe_ct.h file version\"%s\"\n", mmap_version_str);
        }
    }
    else
    {
        NXP_LOG_WARNING("Section not found (.pfe_pe_mmap). Memory map will not be available.\n");
    }

    if (TRUE == bFwVersionMatch)
    {
        /* Copy requested firmware sections */
        ret = pfe_pe_copy_firmware_sections(elf_file, &features_size, &messages_size);
        if (EOK == ret)
        {
            features_mem = &tmp_features;
            messages_mem = &tmp_messages;
            /*  .elf data must be in BIG ENDIAN */
            if (1U == elf_file->Header.e_ident[EI_DATA])
            {
                NXP_LOG_DEBUG("Unexpected .elf format (little endian)\n");
                bElfBigEndian = FALSE;
                ret = EINVAL;
                pfe_pe_free_mem(pe, pe_num);
            }

            if (TRUE == bElfBigEndian)
            {
                /*  Try to upload all sections of the .elf */
                ret = pfe_pe_upload_sections(pe, pe_num, elf_file);
                if (EOK == ret)
                {
                    for (ii = 0; ii < pe_num; ++ii)
                    {
                        /*  Indicate that mmap_data is available */
                        pe[ii].mmap_data = &tmp_mmap;

                        pe[ii].fw_msg_section_size = messages_size;
                        /*  Indicate that fw_msg_section is available */
                        pe[ii].fw_msg_section = messages_mem;

                        pe[ii].fw_feature_section_size = features_size;

                        /*  Indicate that fw_feature_section is available */
                        pe[ii].fw_feature_section = features_mem;
                        pe[ii].fw_features_base = INVALID_FEATURES_BASE; /* Invalid value */

                        /* Clear the internal copy of the index on each FW load because
                        FW will also start from 0 */
                        pe[ii].last_message_write_index = 0U;
                        pe[ii].message_record_addr = 0U;
                    }
                }
            }
        }
    }
    return ret;
}

/**
 * @brief       Auxiliary function to copy requested sectrions from fw elf file
 * @param[in]   elf_file The elf file object to be sections coppied from
 * @param[out]   features_size pointer to uint32_t to return readed features section size
 * @param[out]   messages_size pointer to uint32_t to return readed messages section size
 * @return      EOK if success, error code otherwise
 */
static errno_t pfe_pe_copy_firmware_sections(const ELF_File_t *elf_file, uint32_t * features_size, uint32_t * messages_size)
{
    errno_t ret = EOK;
    uint32_t section_idx = 0U;
    uint32_t mask_sectIdx;
    const Elf32_Shdr *shdr = NULL;    
    void *features_mem = NULL, *messages_mem = NULL;

     /*  Attempt to get section containing firmware diagnostic data */
    if (TRUE == ELF_SectFindName(elf_file, ".messages", &section_idx, NULL, NULL))
    {
        /* Mask out the flag to get section id */
        mask_sectIdx = (~(ELF_NAMED_SECT_IDX_FLAG)&section_idx);

        /*  Load section to RAM */
        shdr = &elf_file->arSectHead32[mask_sectIdx];
        messages_mem = (uint8_t *)elf_file->pvData + ENDIAN_SW_4B(shdr->sh_offset);
        *messages_size = ENDIAN_SW_4B(shdr->sh_size);
        if (*messages_size <= ETH_43_PFE_MESSAGES_SECTION_BUFF_SIZE)
        {
            /* Copy section data to RAM from FW file */
            (void)autolibc_memcpy(
                (void *)&tmp_messages,
                (const void *)messages_mem,
                *messages_size);
        }
        else
        {
            *messages_size = 0;
            NXP_LOG_ERROR("Not enougth memory for copy section .messages. Increase option FwFeaturesBufferSize to minimum value %u.\n", (uint_t) *messages_size);
            ret = EINVAL;
        }
    }
    else
    {
        NXP_LOG_WARNING("Section not found (.messages). FW error reporting will not be available.\n");
        ret = EINVAL;
    }
    /*  Attempt to get section containing firmware supported features */
    if (TRUE == ELF_SectFindName(elf_file, ".features", &section_idx, NULL, NULL))
    {
        /* Mask out the flag to get section id */
        mask_sectIdx = (~(ELF_NAMED_SECT_IDX_FLAG)&section_idx);

        /*  Load section to RAM */
        shdr = &elf_file->arSectHead32[mask_sectIdx];
        features_mem = (void *)((addr_t)elf_file->pvData + ENDIAN_SW_4B(shdr->sh_offset));
        *features_size = ENDIAN_SW_4B(shdr->sh_size);
        if (*features_size <= ETH_43_PFE_FEATURES_SECTION_BUFF_SIZE)
        {
            /* Copy section data to RAM from FW file */
            (void)autolibc_memcpy(
                (void *)&tmp_features,
                (const void *)features_mem,
                *features_size);
        }
        else
        {
            *features_size = 0;
            NXP_LOG_ERROR("Not enougth memory for copy section .features. Increase option FwMessagesBufferSize to minimum value %u.\n", (uint_t)*features_size);
            ret = EINVAL;
        }
    }
    else
    {
        NXP_LOG_WARNING("Section not found (.features). FW features management will not be available.\n");
        ret = EINVAL;
    }
    return ret;
}

/**
 * @brief       Upload firmware into PEs memory
 * @param[in]   pe The PE instances
 * @param[in]   pe_num Number of PE instances
 * @param[in]   elf The elf file object to be uploaded
 * @return      EOK if success, error code otherwise
 */
errno_t pfe_pe_load_firmware(pfe_pe_t *pe, uint32_t pe_num, const void *elf)
{
    uint32_t pe_idx;
    errno_t ret = EOK;
    bool_t bOpsExist = TRUE;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == pe) || (NULL == elf)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* Lock family */
        if (PE_TYPE_CLASS == pe->type)
        {
            oal_mutex_lock(PFE_CLASS_PE_MUTEX_02);
        }
        else
        {
            oal_mutex_lock(PFE_UTIL_PE_MUTEX_02);
        }
        pfe_pe_lock_family(pe);

        ret =  pfe_pe_fw_install_ops(pe, (uint8_t)(pe_num & UINT8_MAX));
        if (EOK != ret)
        {
            NXP_LOG_ERROR("Couldn't find PE load operations: %d\n", ret);
        }

        for(pe_idx = 0; pe_idx < pfe_pe_fw_load_cycles(&pe[0], (uint8_t)(pe_num & UINT8_MAX)); ++pe_idx)
        {
            /* Check that we have the ops */
            if(NULL == pe[pe_idx].fw_load_ops)
            {
                bOpsExist = FALSE;
                ret = ENODEV;
                break;
            }

            pe[pe_idx].fw_load_ops->pe_memset(&pe[pe_idx], PFE_PE_DMEM, 0, 0, pe[pe_idx].dmem_size);
            pe[pe_idx].fw_load_ops->pe_memset(&pe[pe_idx], PFE_PE_IMEM, 0, 0, pe[pe_idx].imem_size);
        }
        if (TRUE == bOpsExist)
        {
            ret = pfe_pe_load_firmware_aux(pe,pe_num,elf);
        }
        /* Unlock family */
        pfe_pe_unlock_family(pe);
        if (PE_TYPE_CLASS == pe->type)
        {
            oal_mutex_unlock(PFE_CLASS_PE_MUTEX_02);
        }
        else
        {
            oal_mutex_unlock(PFE_UTIL_PE_MUTEX_02);
        }

    }
    return ret;
}

/**
 * @brief       Get pointer to PE's memory where memory map data is stored
 * @param[in]   pe The PE instance
 * @param[out]  mmap Pointer where memory map shall be written (values are in network byte order)
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 * @retval      ENOENT Requested data not available
 */
errno_t pfe_pe_get_mmap(const pfe_pe_t *pe, pfe_ct_pe_mmap_t *mmap)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == pe) || (NULL == mmap)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (NULL != pe->mmap_data)
        {
            (void)autolibc_memcpy(mmap, (const void *)pe->mmap_data, sizeof(pfe_ct_pe_mmap_t));
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
 * @brief       Destroy PE instances
 * @param[in]   pe The list of PE instances
 * @param[in]   pe_num The number of PE instances
 */
void pfe_pe_destroy(pfe_pe_t *pe, uint32_t pe_num)
{
    uint32_t pe_idx;

    if ((NULL != pe) && (0U < pe_num))
    {
        for (pe_idx = 0 ; pe_idx < pe_num; ++pe_idx)
        {
            pe[pe_idx].mmap_data = NULL;
            pe[pe_idx].fw_msg_section = NULL;
            pe[pe_idx].fw_msg_section_size = 0U;
            pe[pe_idx].fw_feature_section = NULL;
            pe[pe_idx].fw_feature_section_size = 0U;
            pe[pe_idx].miflock = NULL;
        }
    }
}

/**
* @brief Returns a string base from the features description section
* @param[in] pe PE to be used
* @return Either the string base or NULL.
*/
char *pfe_pe_get_fw_feature_str_base(const pfe_pe_t *pe)
{
    char *str;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == pe))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        str = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        str = NULL;
        if(INVALID_FEATURES_BASE != pe->fw_features_base)
        {
            str = (char *)(pe->fw_feature_section);
        }
    }

    return str;
}

/**
* @brief Returns feature description from special .elf section
* @param[in] pe PE to be used
* @param[in] id Id of the feature - its position in the section.
* @param[out] entry Pointer to the description is stored here
* @retun Either error code on failure or EOK
*/
errno_t pfe_pe_get_fw_feature_entry(pfe_pe_t *pe, uint32_t id, pfe_ct_feature_desc_t **entry)
{
    uint32_t entry_ptr;
    errno_t ret = EOK;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == pe))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* Check whether the section with features description is available */
        if(NULL == pe->fw_feature_section)
        {   /* Avoid running uninitialized */
            ret = ENOENT;
        }
        else
        {
            /* Get the pointer to the descriptions and count of the features
               (do it only once and remember the values) */
            if(INVALID_FEATURES_BASE == pe->fw_features_base)
            {
                pfe_ct_pe_mmap_t pfe_pe_mmap = { 0U };

                /* The mmap has not been queried for error record yet. Query map for
                   the error record address. */
                if (EOK != pfe_pe_get_mmap(pe, &pfe_pe_mmap))
                {
                    NXP_LOG_ERROR("Could not get memory map\n");
                    ret = ENOENT;
                }
                else
                {
                    /* Remember the features record address and size */
                    pe->fw_features_base = oal_ntohl(pfe_pe_mmap.common.version.features);
                    if(pe->fw_features_base > pe->fw_feature_section_size)
                    {
                        NXP_LOG_ERROR("Invalid address of features record 0x%x\n", (uint_t)pe->fw_features_base);
                        pe->fw_features_base = INVALID_FEATURES_BASE;
                        ret = EIO;
                    }
                    else
                    {
                        pe->fw_features_size = oal_ntohl(pfe_pe_mmap.common.version.features_count);
                    }
                }
            }

            /* Check if the requested id does exist */
            if(EOK == ret)
            {
                if(id < pe->fw_features_size)
                {
                    /* Entry at given id does exist so return it */
                    entry_ptr = oal_ntohl(*(uint32_t *)ADDR_BASE_OFFSET((addr_t)pe->fw_feature_section, (uint64_t)id * sizeof(PFE_PTR(pfe_ct_feature_desc_t)) + pe->fw_features_base));

                    *entry = (pfe_ct_feature_desc_t *)((addr_t)pe->fw_feature_section + entry_ptr);

                    ret = EOK;
                }
                else
                {
                    ret = ENOENT;
                }
            }
        }
    }

    return ret;
}

/**
 * @brief       Reads out errors reported by the PE Firmware and prints them on debug console
 * @param[in]   pe PE which error report shall be read out
 * @return      EOK on success or error code
 */
errno_t pfe_pe_get_fw_messages_nolock(pfe_pe_t *pe)
{
#ifdef NXP_LOG_ENABLED
    pfe_ct_message_record_t message_record; /* Copy of the PE error record */
    uint32_t read_start;                /* Starting position in error record to read */
    uint32_t i;
    uint32_t message_count;
    pfe_ct_pe_mmap_t pfe_pe_mmap;

    if(NULL == pe->fw_msg_section)
    {
        /* Avoid running uninitialized */
        return ENOENT;
    }

    if(0U == pe->message_record_addr)
    {
        /* The memory map has not been queried for error record yet. Get
           the map and query it for the error record address. */
        if (EOK != pfe_pe_get_mmap(pe, &pfe_pe_mmap))
        {
            NXP_LOG_ERROR("Could not get memory map\n");
            return ENOENT;
        }

        /* Remember the error record address */
        pe->message_record_addr = oal_ntohl(pfe_pe_mmap.common.message_record);
    }

    pfe_pe_memcpy_from_dmem_to_host_32_nolock(
            pe, &message_record, pe->message_record_addr, sizeof(pfe_ct_message_record_t));

    /* Get the number of new errors */
    message_count = oal_ntohl(message_record.write_index) - pe->last_message_write_index;

    /* First unread error */
    read_start = pe->last_message_write_index;

    /* Where to continue next time */
    pe->last_message_write_index = oal_ntohl(message_record.write_index);
    if(0U != message_count)
    {
        /* New errors reported - go through them */
        if(message_count > FP_MESSAGE_RECORD_SIZE)
        {
            NXP_LOG_WARNING("FW message log overflow by %u\n",
                    (uint_t)message_count - FP_MESSAGE_RECORD_SIZE + 1U);

            /* Overflow has occurred - the write_index contains oldest record */
            read_start = oal_ntohl(message_record.write_index);
            message_count = FP_MESSAGE_RECORD_SIZE;
        }

        for(i = 0U; i < message_count; i++)
        {
            uint32_t message_addr;
            uint32_t message_line;
            const pfe_ct_message_t *message_ptr;
            const char_t *message_str;
            const char_t *message_file;
            uint32_t message_val;
            pfe_ct_message_level_t message_level;

            message_addr = oal_ntohl(message_record.messages[(read_start + i)
                                                      & (FP_MESSAGE_RECORD_SIZE - 1U)]);
            message_val = oal_ntohl(message_record.values[(read_start + i)
                                                      & (FP_MESSAGE_RECORD_SIZE - 1U)]);
            message_level = message_record.level[(read_start + i) & (FP_MESSAGE_RECORD_SIZE - 1U)];
            if(message_addr > pe->fw_msg_section_size)
            {
                NXP_LOG_ERROR("Invalid error address from FW 0x%x\n", (uint_t)message_addr);
                break;
            }

            /* Get to the error message through the .errors section */
            message_ptr = (pfe_ct_message_t *)((addr_t)pe->fw_msg_section + message_addr);
            if(oal_ntohl(message_ptr->message) > pe->fw_msg_section_size)
            {
                NXP_LOG_ERROR("Invalid error message from FW 0x%x",
                        (uint_t)oal_ntohl(message_ptr->message));
                break;
            }

            message_str = (char_t *)((addr_t)pe->fw_msg_section + oal_ntohl(message_ptr->message));
            if(oal_ntohl(message_ptr->file) > pe->fw_msg_section_size)
            {
                NXP_LOG_ERROR("Invalid file name from FW 0x%x",
                        (uint_t)oal_ntohl(message_ptr->file));
                break;
            }

            message_file =  (char_t *)((addr_t)pe->fw_msg_section + oal_ntohl(message_ptr->file));
            message_line = oal_ntohl(message_ptr->line);

            switch (message_level)
            {
                case PFE_MESSAGE_EXCEPTION:
                case PFE_MESSAGE_ERROR:
                    pfe_hm_report_error(hm_types[pe->type], HM_EVT_PE_ERROR,
                            "PE%d: %s line %u: %s (0x%x)\n",
                            pe->id, message_file, (uint_t)message_line, message_str, (uint_t)message_val);
#if(STD_ON == ETH_43_PFE_DEM_EVENT_DETECT)
                   (void)Dem_SetEventStatus((Dem_EventIdType)ETH_43_PFE_CFG_DEM_E_PE_FW_ERR, DEM_EVENT_STATUS_PREFAILED);
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */
                    break;
                case PFE_MESSAGE_WARNING:
                    NXP_LOG_WARNING("PE%d: %s line %u: %s (0x%x)\n",
                            pe->id, message_file, (uint_t)message_line, message_str, (uint_t)message_val);
                    break;
                case PFE_MESSAGE_INFO:
                    NXP_LOG_INFO("PE%d: %s line %u: %s (0x%x)\n",
                        pe->id, message_file, (uint_t)message_line, message_str, (uint_t)message_val);
                    break;
                case PFE_MESSAGE_DEBUG:
                    NXP_LOG_DEBUG("PE%d: %s line %u: %s (0x%x)\n",
                        pe->id, message_file, (uint_t)message_line, message_str, (uint_t)message_val);
                    break;
                default:
                    NXP_LOG_ERROR("Invalid error level from FW 0x%x\n",
                        message_level);
                    break;
            }
        }
    }
#else
    (void)pe;
#endif /* NXP_LOG_ENABLED */
    return EOK;
}

/**
 * @brief Reads and validates PE mmap
 * @param[in] pe The PE instance
 */
errno_t pfe_pe_check_mmap(const pfe_pe_t *pe)
{
    pfe_ct_pe_mmap_t pfe_pe_mmap;
    errno_t ret;

    /*  Get mmap base from PE[0] since all PEs have the same memory map */
    if (EOK != pfe_pe_get_mmap(pe, &pfe_pe_mmap))
    {
        NXP_LOG_ERROR("Could not get memory map\n");
        ret = ENOENT;
    }
    else
    {
        ret = EOK;
        NXP_LOG_INFO("[FW VERSION] %d.%d.%d, Build: %s, %s (%s), ID: 0x%x\n",
            pfe_pe_mmap.common.version.major,
            pfe_pe_mmap.common.version.minor,
            pfe_pe_mmap.common.version.patch,
            (char_t *)pfe_pe_mmap.common.version.build_date,
            (char_t *)pfe_pe_mmap.common.version.build_time,
            (char_t *)pfe_pe_mmap.common.version.vctrl,
            (uint_t)pfe_pe_mmap.common.version.id);
    }

    return ret;
}

/**
 * @brief       Copies PE (global) statistics into a prepared buffer
 * @param[in]   pe      PE which statistics shall be read
 * @param[in]   addr    Address within the PE DMEM where the statistics are located
 * @param[out]  stats   Buffer where to copy the statistics from the PE DMEM
 * @retval      EOK     Success
 * @retval      EINVAL  Invalid argument
 */
errno_t pfe_pe_get_pe_stats_nolock(pfe_pe_t *pe, uint32_t addr, pfe_ct_pe_stats_t *stats)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == pe) || (NULL == stats)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else if (unlikely(0U == addr))
    {
        NXP_LOG_ERROR("NULL argument for DMEM received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_pe_memcpy_from_dmem_to_host_32_nolock(pe, stats, addr, sizeof(pfe_ct_pe_stats_t));
        ret = EOK;
    }

    return ret;
}

/**
 * @brief       Check if PE is stalled
 * @details     PE is stalled when the firmware is running and the firmware state counter is not
 *              updated periodically. This function shouldn't be called very often so the
 *              PE can change state between calls.
 * @param[in]   pe The PE instance
 * @return      TRUE if PE is stalled, FALSE if not
 */
bool_t pfe_pe_check_stalled_nolock(pfe_pe_t *pe)
{
    pfe_ct_pe_sw_state_monitor_t state_monitor;
    bool_t ret = FALSE;
    static const char *states[] = {
        "UNINIT",
        "INIT",
        "FRAMEWAIT",
        "FRAMEPARSE",
        "FRAMECLASSIFY",
        "FRAMEDISCARD",
        "FRAMEMODIFY",
        "FRAMESEND",
        "STOPPED",
        "EXCEPTION",
        "FAIL_STOP"
    };

    if (pfe_pe_get_state_monitor_nolock(pe, &state_monitor) != EOK)
    {
        ret = FALSE;
    }
    else
    {
        if ((PFE_FW_STATE_EXCEPTION == state_monitor.state) && (state_monitor.state != pe->prev_state))
        {
            pfe_hm_report_error(hm_types[pe->type], HM_EVT_PE_EXCEPTION, "Core %d raised exception in state %s", pe->id, states[state_monitor.state]);
#if(STD_ON == ETH_43_PFE_DEM_EVENT_DETECT)
            (void)Dem_SetEventStatus((Dem_EventIdType)ETH_43_PFE_CFG_DEM_E_PE_EXCEPTION_ERR, DEM_EVENT_STATUS_PREFAILED);
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */
            ret = TRUE;
        }
        if ((FALSE == pe->stalled) && (state_monitor.state != PFE_FW_STATE_UNINIT) &&
                (state_monitor.counter == pe->counter))
        {
            pfe_hm_report_error(hm_types[pe->type], HM_EVT_PE_STALL, "Core %d stalled in state %s", pe->id, states[state_monitor.state]);
#if(STD_ON == ETH_43_PFE_DEM_EVENT_DETECT)
            (void)Dem_SetEventStatus((Dem_EventIdType)ETH_43_PFE_CFG_DEM_E_PE_STALL_ERR, DEM_EVENT_STATUS_PREFAILED);
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */
            pe->stalled = TRUE;
            ret = TRUE;
        }

        pe->counter = state_monitor.counter;
        pe->prev_state = state_monitor.state;
    }
    return ret;
}


/**
 * @brief       Copies PE classification algorithms statistics into a prepared buffer
 * @param[in]   pe      PE which statistics shall be read
 * @param[in]   addr    Address within the PE DMEM where the statistics are located
 * @param[out]  stats   Buffer where to copy the statistics from the PE DMEM
 * @retval      EOK     Success
 * @retval      EINVAL  Invalid argument
 */
errno_t pfe_pe_get_classify_stats_nolock(pfe_pe_t *pe, uint32_t addr, pfe_ct_classify_stats_t *stats)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == pe) || (NULL == stats)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else if (unlikely(0U == addr))
    {
        NXP_LOG_ERROR("NULL argument for DMEM received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_pe_memcpy_from_dmem_to_host_32_nolock(pe, stats, addr, sizeof(pfe_ct_classify_stats_t));
        ret = EOK;
    }

    return ret;
}

/**
 * @brief       Copies classification algorithm or logical interface statistics into a prepared buffer
 * @param[in]   pe      PE which statistics shall be read
 * @param[in]   addr    Address within the PE DMEM where the statistics are located
 * @param[out]  stats   Buffer where to copy the statistics from the PE DMEM
 * @retval      EOK     Success
 * @retval      EINVAL  Invalid argument
 */
errno_t pfe_pe_get_class_algo_stats_nolock(pfe_pe_t *pe, uint32_t addr, pfe_ct_class_algo_stats_t *stats)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == pe) || (NULL == stats)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else if (unlikely(0U == addr))
    {
        NXP_LOG_ERROR("NULL argument for DMEM received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_pe_memcpy_from_dmem_to_host_32_nolock(pe, stats, addr, sizeof(pfe_ct_class_algo_stats_t));
        ret = EOK;
    }

    return ret;
}

#if defined(PFE_CFG_TEXT_STATS)
/**
 * @brief Translates state pfe_ct_pe_sw_state_t to a string
 * @param[in] state State to be translated
 * @return String representation of the state
 */
static inline const char_t *pfe_pe_get_fw_state_str(pfe_ct_pe_sw_state_t state)
{
    const char *ret;
    switch(state)
    {
        case PFE_FW_STATE_UNINIT:
            ret = "UNINIT";
            break;
        case PFE_FW_STATE_INIT:
            ret = "INIT";
            break;
        case PFE_FW_STATE_FRAMEWAIT:
            ret = "FRAMEWAIT";
            break;
        case PFE_FW_STATE_FRAMEPARSE:
            ret = "FRAMEPARSE";
            break;
        case PFE_FW_STATE_FRAMECLASSIFY:
            ret = "FRAMECLASSIFY";
            break;
        case PFE_FW_STATE_FRAMEDISCARD:
            ret = "FRAMEDISCARD";
            break;
        case PFE_FW_STATE_FRAMEMODIFY:
            ret = "FRAMEMODIFY";
            break;
        case PFE_FW_STATE_FRAMESEND:
            ret = "FRAMESEND";
            break;
        case PFE_FW_STATE_STOPPED:
            ret = "STOPPED";
            break;
        default:
            ret = "Unknown";
            break;
    }
    return ret;
}

/**
* @brief Reads and prints measurements from the PE memory
* @param[in] pe PE which shall be read
* @param[in] count Number of measurements in the PE memory to be read
* @param[in] ptr Location of the measurements record in the PE memory
* @param[in] buf Output text data buffer
* @param[in] buf_len Size of the output text data buffer
* @param[in] verb_level Verbosity level
* @return Number of bytes written into the text buffer
*/
static uint32_t pfe_pe_get_measurements_nolock(pfe_pe_t *pe, uint32_t count, uint32_t ptr, char_t *buf, uint32_t buf_len, uint8_t verb_level)
{
    pfe_ct_measurement_t m;
    uint_t i;
    uint32_t len = 0U;

    (void)verb_level;

    if(0U == ptr)
    {   /* This shall not happen - FW did not initialize data correctly */
        NXP_LOG_ERROR("Inconsistent data in pfe_pe_mmap\n");
    }
    else
    {
        /* Print the data */
        for(i = 0U; i < count; i++)
        {
            /* Copy the data into the allocated buffer */
            pfe_pe_memcpy_from_dmem_to_host_32_nolock(pe, &m, ptr, sizeof(pfe_ct_measurement_t));
            ptr += sizeof(pfe_ct_measurement_t);

            /* Variables just to make code more readable */
            uint32_t avg = oal_ntohl(m.avg);
            uint32_t min = oal_ntohl(m.min);
            uint32_t max = oal_ntohl(m.max);
            uint32_t cnt = oal_ntohl(m.cnt);

            /* Just print the data without interpreting them */
            len += oal_util_snprintf(buf + len, buf_len - len,
                    "Measurement %u:\tmin %10u\tmax %10u\tavg %10u\tcnt %10u\n",
                        i, min, max, avg, cnt);
        }
    }

    return len;
}
#endif /* defined(PFE_CFG_TEXT_STATS) */

/**
 * @brief       Provides current state of PE firmware
 * @param[in]   pe          The PE instance
 * @return      Current state of PE firmware
 *
 */
pfe_ct_pe_sw_state_t pfe_pe_get_fw_state(pfe_pe_t *pe)
{
    pfe_ct_pe_sw_state_monitor_t state_monitor = { 0U };

    /* We don't need coherent data here so only lock the memory interface without locking the PE memory.
       NOTE: Use the mutex lock for CLASS PE here because the pfe_pe_get_fw_state() is only called from CLASS FW. */
    oal_mutex_lock(PFE_CLASS_PE_MUTEX_07);
    pfe_pe_lock_family(pe);
    if (pfe_pe_get_state_monitor_nolock(pe, &state_monitor) != EOK)
    {
        state_monitor.state = PFE_FW_STATE_UNINIT;
    }
    pfe_pe_unlock_family(pe);
    oal_mutex_unlock(PFE_CLASS_PE_MUTEX_07);

    return state_monitor.state;
}

/**
 * @brief       Read "put" buffer
 * @param[in]   pe The PE instance
 * @param[out]  buf Pointer to memory where buffer shall be written
 * @retval      EOK Success and buffer is valid
 * @retval      EAGAIN Buffer is invalid
 * @retval      ENOENT Buffer not found
 */
errno_t pfe_pe_get_data_nolock(pfe_pe_t *pe, pfe_ct_buffer_t *buf)
{
    uint8_t flags = 0U;
    errno_t ret = ENOENT;
    pfe_ct_pe_mmap_t mmap_data = { 0U };
    const pfe_ct_class_mmap_t *class_mmap_data;

    /*  Get mmap base from PE[0] since all PEs have the same memory map */
    if (EOK != pfe_pe_get_mmap(pe, &mmap_data))
    {
        NXP_LOG_ERROR("Could not get memory map\n");
    }
    else
    {
        class_mmap_data = &mmap_data.class_pe;

        if (0U != class_mmap_data->put_buffer)
        {
            /*  Get "put" buffer status */
            pfe_pe_memcpy_from_dmem_to_host_32_nolock(pe, &flags,
                    oal_ntohl(class_mmap_data->put_buffer) + offsetof(pfe_ct_buffer_t, flags),
                        sizeof(uint8_t));

            if (0U != flags)
            {
                /*  Copy buffer to local memory */
                pfe_pe_memcpy_from_dmem_to_host_32_nolock(pe, buf, oal_ntohl(class_mmap_data->put_buffer), sizeof(pfe_ct_buffer_t));

                /*  Clear flags */
                flags = 0U;

                pfe_pe_memcpy_from_host_to_dmem_32_nolock(pe,
                        oal_ntohl(class_mmap_data->put_buffer) + offsetof(pfe_ct_buffer_t, flags),
                            &flags, sizeof(uint8_t));

                ret = EOK;
            }
            else
            {
                ret = EAGAIN;
            }
        }
    }


    return ret;
}

/**
 * @brief       Write "get" buffer
 * @param[in]   pe The PE instance
 * @param[out]  buf Pointer to data to be written
 * @retval      EOK Success and buffer is valid
 * @retval      EAGAIN Buffer is occupied
 * @retval      ENOENT Buffer not found
 */
errno_t pfe_pe_put_data_nolock(pfe_pe_t *pe, pfe_ct_buffer_t *buf)
{
    uint8_t flags = 0U;
    errno_t ret = ENOENT;
    pfe_ct_pe_mmap_t mmap_data = { 0U };
    const pfe_ct_class_mmap_t *class_mmap_data;

    if (EOK != pfe_pe_get_mmap(pe, &mmap_data))
    {
        NXP_LOG_ERROR("Could not get memory map\n");
    }
    else
    {
        class_mmap_data = &mmap_data.class_pe;
        if (0U != class_mmap_data->get_buffer)
        {
            /*  Get "get" buffer status */
            pfe_pe_memcpy_from_dmem_to_host_32_nolock(pe, &flags,
                    oal_ntohl(class_mmap_data->get_buffer) + offsetof(pfe_ct_buffer_t, flags),
                        sizeof(uint8_t));

            if (0U == flags)
            {
                /*  Send data to PFE */
                buf->flags |= 1U;

                pfe_pe_memcpy_from_host_to_dmem_32_nolock(pe,
                        oal_ntohl(class_mmap_data->get_buffer), buf, sizeof(pfe_ct_buffer_t));

                ret = EOK;
            }
            else
            {
                ret = EAGAIN;
            }
        }
    }

    return ret;
}

#if defined(PFE_CFG_TEXT_STATS)
/**
 * @brief       Return PE runtime statistics in text form
 * @details     Function writes formatted text into given buffer.
 * @param[in]   pe          The PE instance
 * @param[in]   buf         Pointer to the buffer to write to
 * @param[in]   buf_len     Buffer length
 * @param[in]   verb_level  Verbosity level
 * @return      Number of bytes written to the buffer
 *
 */
uint32_t pfe_pe_get_text_statistics(pfe_pe_t *pe, char_t *buf, uint32_t buf_len, uint8_t verb_level)
{
    uint32_t len = 0U;
    pfe_ct_pe_sw_state_monitor_t state_monitor = {0};
    errno_t ret;

    if (NULL == pe->mmap_data)
    {
        return 0U;
    }

    len += oal_util_snprintf(buf + len, buf_len - len, "\nPE %u\n----\n", pe->id);
    len += oal_util_snprintf(buf + len, buf_len - len, "- PE state monitor -\n");

    /* Lock family */
    /* NOTE: Use the mutex lock for UTIL PE here because the pfe_pe_get_text_statistics() is only called from UTIL FW */
    oal_mutex_lock(PFE_UTIL_PE_MUTEX_04);
    pfe_pe_lock_family(pe);

    /* Acquire memlock for all PE cores. They will stop processing frames and wait.
       This will ensure data coherence. */
    ret = pfe_pe_memlock_acquire_nolock(pe);
    if (EOK != ret)
    {
        NXP_LOG_DEBUG("Memory lock failed\n");
        return 0;
    }

    pfe_pe_memcpy_from_dmem_to_host_32_nolock(pe, &state_monitor,
            oal_ntohl(pe->mmap_data->common.state_monitor), sizeof(pfe_ct_pe_sw_state_monitor_t));

    len += oal_util_snprintf(buf + len, buf_len - len, "FW State: %u (%s), counter %u\n",
            state_monitor.state, pfe_pe_get_fw_state_str(state_monitor.state),
                oal_ntohl(state_monitor.counter));

    /* This is a class PE therefore we may access the specific data */
    if (0U != oal_ntohl(pe->mmap_data->common.measurement_count))
    {
        len += oal_util_snprintf(buf + len, buf_len - len, "- Measurements -\n");

        /* Read processing time measurements */
        len += pfe_pe_get_measurements_nolock(pe, oal_ntohl(pe->mmap_data->common.measurement_count),
                oal_ntohl(pe->mmap_data->common.measurements), buf + len, buf_len - len, verb_level);
    }

    if (EOK != pfe_pe_memlock_release_nolock(pe))
    {
        NXP_LOG_DEBUG("Memory unlock failed\n");
        len = 0U;
    }
    pfe_pe_unlock_family(pe);
    oal_mutex_unlock(PFE_UTIL_PE_MUTEX_04);

    return len;
}
#endif /* defined(PFE_CFG_TEXT_STATS) */

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

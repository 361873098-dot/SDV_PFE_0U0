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
#include "pfe_l2br_table.h"
#include "pfe_l2br_table_csr.h"

/*  MAC address type must be 48-bits long */
ct_assert((sizeof(pfe_mac_addr_t) * 8) == 48);

/**
 * @brief HASH registers associated with a table
 */
typedef struct
{
    addr_t cmd_reg;             /* REQ1_CMD_REG */
    addr_t mac1_addr_reg;       /* REQ1_MAC1_ADDR_REG */
    addr_t mac2_addr_reg;       /* REQ1_MAC2_ADDR_REG */
    addr_t mac3_addr_reg;       /* REQ1_MAC3_ADDR_REG */
    addr_t mac4_addr_reg;       /* REQ1_MAC4_ADDR_REG */
    addr_t mac5_addr_reg;       /* REQ1_MAC5_ADDR_REG */
    addr_t entry_reg;           /* REQ1_ENTRY_REG */
    addr_t status_reg;          /* REQ1_STATUS_REG */
    addr_t direct_reg;          /* REQ1_DIRECT_REG */
    addr_t free_entries_reg;    /* FREE LIST ENTRIES */
    addr_t free_head_ptr_reg;   /* FREE LIST HEAD PTR */
    addr_t free_tail_ptr_reg;   /* FREE LIST TAIL PTR */
} pfe_mac_table_regs_t;

/**
 * @brief   The L2 Bridge table instance structure
 */
struct pfe_l2br_table_tag
{
    addr_t cbus_base_va;                        /*!< CBUS base virtual address                  */
    pfe_l2br_table_type_t type;                 /*!< Table type                                 */
    pfe_mac_table_regs_t regs;                  /*!< Registers (VA)                             */
    uint16_t hash_space_depth;                  /*!< Hash space depth in number of entries      */
    uint16_t coll_space_depth;                  /*!< Collision space depth in number of entries */
};

/**
 * @brief   Flags for 2-field MAC table entry (pfe_mac2f_table_entry_t.flags)
 */
typedef enum
{
    MAC2F_ENTRY_VALID_FLAG = (1U << 3),         /*!< MAC2F_ENTRY_VALID_FLAG         */
    MAC2F_ENTRY_COL_PTR_VALID_FLAG = (1U << 2), /*!< MAC2F_ENTRY_COL_PTR_VALID_FLAG */
    MAC2F_ENTRY_RESERVED1_FLAG = (1U << 1),     /*!< MAC2F_ENTRY_RESERVED1_FLAG     */
    MAC2F_ENTRY_RESERVED2_FLAG = (1U << 0)      /*!< MAC2F_ENTRY_RESERVED2_FLAG     */
} pfe_mac2f_table_entry_flags_t;

/**
 * @brief   Valid flags for 2-field MAC table entry (pfe_mac2f_table_entry_t.field_valids)
 */
typedef enum
{
    MAC2F_ENTRY_MAC_VALID = (1U << 0),          /*!< (Field1 = MAC Valid)   */
    MAC2F_ENTRY_VLAN_VALID = (1U << 1),         /*!< (Field2 = VLAN Valid)  */
    MAC2F_ENTRY_RESERVED1_VALID = (1U << 2),    /*!< RESERVED               */
    MAC2F_ENTRY_RESERVED2_VALID = (1U << 3),    /*!< RESERVED               */
    MAC2F_ENTRY_RESERVED3_VALID = (1U << 4),    /*!< RESERVED               */
    MAC2F_ENTRY_RESERVED4_VALID = (1U << 5),    /*!< RESERVED               */
    MAC2F_ENTRY_RESERVED5_VALID = (1U << 6),    /*!< RESERVED               */
    MAC2F_ENTRY_RESERVED6_VALID = (1U << 7),    /*!< RESERVED               */
} pfe_mac2f_table_entry_valid_bits_t;

/**
 * @brief   Flags for VLAN table entry (pfe_vlan_table_entry_t.flags)
 */
typedef enum
{
    VLAN_ENTRY_VALID_FLAG = (1U << 3),          /*!< VLAN_ENTRY_VALID_FLAG          */
    VLAN_ENTRY_COL_PTR_VALID_FLAG = (1U << 2),  /*!< VLAN_ENTRY_COL_PTR_VALID_FLAG  */
    VLAN_ENTRY_RESERVED1_FLAG = (1U << 1),      /*!< VLAN_ENTRY_RESERVED1_FLAG      */
    VLAN_ENTRY_RESERVED2_FLAG = (1U << 0)       /*!< VLAN_ENTRY_RESERVED2_FLAG      */
} pfe_vlan_table_entry_flags_t;

/**
 * @brief   Valid flags for VLAN table entry (pfe_vlan_table_entry_t.field_valids)
 */
typedef enum
{
    VLAN_ENTRY_VLAN_VALID = (1U << 0),      /*!< (Field1 = VLAN Valid)      */
    VLAN_ENTRY_RESERVED1_VALID = (1U << 1), /*!< RESERVED                   */
    VLAN_ENTRY_RESERVED2_VALID = (1U << 2), /*!< RESERVED                   */
    VLAN_ENTRY_RESERVED3_VALID = (1U << 3), /*!< RESERVED                   */
    VLAN_ENTRY_RESERVED4_VALID = (1U << 4), /*!< RESERVED                   */
    VLAN_ENTRY_RESERVED5_VALID = (1U << 5), /*!< RESERVED                   */
    VLAN_ENTRY_RESERVED6_VALID = (1U << 6), /*!< RESERVED                   */
    VLAN_ENTRY_RESERVED7_VALID = (1U << 7), /*!< RESERVED                   */
} pfe_vlan_table_entry_valid_bits_t;

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
static pfe_l2br_table_t mactab_instance;
static pfe_l2br_table_t vlantab_instance;
#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

static errno_t pfe_l2br_table_init_cmd(pfe_l2br_table_t *l2br);
static errno_t pfe_l2br_table_write_cmd(pfe_l2br_table_t *l2br, uint32_t addr, pfe_l2br_table_entry_t *entry);
static errno_t pfe_l2br_table_read_cmd(pfe_l2br_table_t *l2br, uint32_t addr, pfe_l2br_table_entry_t *entry);
static errno_t pfe_l2br_wait_for_cmd_done(const pfe_l2br_table_t *l2br, uint32_t *status_val);
static errno_t pfe_l2br_entry_to_cmd_args(const pfe_l2br_table_t *l2br, pfe_l2br_table_entry_t *entry);
static uint32_t pfe_l2br_table_get_col_ptr(const pfe_l2br_table_entry_t *entry);
static void pfe_l2br_get_data(const pfe_l2br_table_t *l2br, pfe_l2br_table_entry_t *entry);
static bool_t pfe_l2br_table_entry_match_criterion(const pfe_l2br_table_t *l2br, const pfe_l2br_table_iterator_t *l2t_iter, const pfe_l2br_table_entry_t *entry);
static errno_t pfe_l2br_table_do_update_entry_nolock(pfe_l2br_table_t *l2br, pfe_l2br_table_entry_t *entry);
static errno_t pfe_l2br_table_do_del_entry_nolock(pfe_l2br_table_t *l2br, pfe_l2br_table_entry_t *entry);
static errno_t pfe_l2br_table_do_add_entry_nolock(pfe_l2br_table_t *l2br, pfe_l2br_table_entry_t *entry);
static errno_t pfe_l2br_table_do_search_entry_nolock(pfe_l2br_table_t *l2br, pfe_l2br_table_entry_t *entry);
static errno_t pfe_l2br_table_flush_cmd(pfe_l2br_table_t *l2br);
static uint8_t pfe_l2br_entry_get_hash(const pfe_l2br_table_entry_t *entry);
static void pfe_l2br_iterator_save_macvlan(pfe_l2br_table_iterator_t *l2t_iter, const pfe_l2br_table_entry_t *entry);
static bool_t pfe_l2br_iterator_is_macvlan_match(const pfe_l2br_table_iterator_t *l2t_iter, const pfe_l2br_table_entry_t *entry);

/**
 * @brief       Match entry with latest criterion provided via pfe_l2br_table_get_first()
 * @param[in]   l2br The L2 Bridge Table instance
 * @param[in]   entry The entry to be matched
 * @retval      True Entry matches the criterion
 * @retval      False Entry does not match the criterion
 */
static bool_t pfe_l2br_table_entry_match_criterion(const pfe_l2br_table_t *l2br, const pfe_l2br_table_iterator_t *l2t_iter, const pfe_l2br_table_entry_t *entry)
{
    bool_t match = FALSE;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == l2br) || (NULL == entry)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        match = FALSE;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
    switch (l2t_iter->cur_crit)
    {
        case L2BR_TABLE_CRIT_ALL:
        {
            match = TRUE;
            break;
        }

        case L2BR_TABLE_CRIT_VALID:
        {
            switch (l2br->type)
            {
                case PFE_L2BR_TABLE_MAC2F:
                {
                    match = (0U != (entry->u.mac2f_entry.flags & (uint32_t)MAC2F_ENTRY_VALID_FLAG));
                    break;
                }

                case PFE_L2BR_TABLE_VLAN:
                {
                    match = (0U != (entry->u.vlan_entry.flags & (uint32_t)VLAN_ENTRY_VALID_FLAG));
                    break;
                }

                default:
                {
                    NXP_LOG_ERROR("Invalid table type\n");
                    break;
                }
            }

            break;
        }

        default:
        {
            NXP_LOG_ERROR("Unknown criterion\n");
            break;
        }
    }
    }
    return match;
}

/**
 * @brief       Get action data
 */
static void pfe_l2br_get_data(const pfe_l2br_table_t *l2br, pfe_l2br_table_entry_t *entry)
{
    uint64_t vlan_action_data;
    uint32_t mac_action_data;

    /*  Get action data */
    if (PFE_L2BR_TABLE_MAC2F == l2br->type)
    {
        mac_action_data = hal_read32(l2br->regs.entry_reg) & 0x7fffffffU;
        entry->u.mac2f_entry.action_data = mac_action_data;
    }
    else
    {
        vlan_action_data = (uint64_t)hal_read32(l2br->regs.entry_reg);
        vlan_action_data |= ((uint64_t)hal_read32(l2br->regs.direct_reg) << 32U);
        entry->u.vlan_entry.action_data = (vlan_action_data & 0x7fffffffffffffULL);
    }
}

/**
 * @brief       Get collision pointer
 * @param[in]   entry The table entry instance
 * @return      Collision pointer or 0 if not found
 */
static uint32_t pfe_l2br_table_get_col_ptr(const pfe_l2br_table_entry_t *entry)
{
    uint32_t ret = 0U;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == entry))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = 0U;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        switch (entry->type)
        {
            case PFE_L2BR_TABLE_MAC2F:
            {
                if (0U != (entry->u.mac2f_entry.flags & (uint32_t)MAC2F_ENTRY_COL_PTR_VALID_FLAG))
                {
                    ret = entry->u.mac2f_entry.col_ptr;
                }

                break;
            }

            case PFE_L2BR_TABLE_VLAN:
            {
                if (0U != (entry->u.vlan_entry.flags & (uint32_t)VLAN_ENTRY_COL_PTR_VALID_FLAG))
                {
                    ret = entry->u.vlan_entry.col_ptr;
                }

                break;
            }

            default:
            {
                NXP_LOG_ERROR("Invalid table type\n");
                ret = 0U;
                break;
            }
        }
    }

    return ret;
}

/**
 * @brief       Convert entry to command arguments
 * @details     Function will write necessary data to registers as preparation
 *              of subsequent command (ADD/DEL/UPDATE/SEARCH).
 * @param[in]   entry The entry
 * @retval      EOK Success
 * @retval      EINVAL Invalid/missing argument
 */
static errno_t pfe_l2br_entry_to_cmd_args(const pfe_l2br_table_t *l2br, pfe_l2br_table_entry_t *entry)
{
    uint32_t *entry32 = (uint32_t *)entry;
    uint64_t action_data = 0ULL;
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == l2br) || (NULL == entry)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  Prepare command arguments */
        if (PFE_L2BR_TABLE_MAC2F == l2br->type)
        {
            /*  Write MAC (in network byte order) and VLAN */
            hal_write32(oal_htonl(entry32[0]), l2br->regs.mac1_addr_reg);
            hal_write32((uint32_t)oal_htons(entry32[1] & 0x0000ffffU) | (entry32[1] & 0xffff0000U), l2br->regs.mac2_addr_reg);

            /*  Write action entry */
            hal_write32(entry->u.mac2f_entry.action_data & 0x7fffffffU, l2br->regs.entry_reg);
            ret = EOK;
        }
        else if (PFE_L2BR_TABLE_VLAN == l2br->type)
        {
            /*  Write VLAN */
            hal_write32(entry->u.vlan_entry.vlan, l2br->regs.mac1_addr_reg);

            /*  Write action entry */
            action_data = entry->u.vlan_entry.action_data & 0xffffffffU;
            hal_write32(action_data, l2br->regs.entry_reg);
            action_data = (entry->u.vlan_entry.action_data >> 32U) & 0x7fffffU;
            hal_write32(action_data, l2br->regs.direct_reg);
            ret = EOK;
        }
        else
        {
            NXP_LOG_ERROR("Invalid table type\n");
            ret = EINVAL;
        }
    }
    return ret;
}

/**
 * @brief       Update entry in table
 * @warning     This function shouldn't be called directly. Call equivalent function with register lock.
 */
static errno_t pfe_l2br_table_do_update_entry_nolock(pfe_l2br_table_t *l2br, pfe_l2br_table_entry_t *entry)
{
    uint32_t status, cmd;
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == l2br) || (NULL == entry)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    /*  Prepare command arguments */
    ret = pfe_l2br_entry_to_cmd_args(l2br, entry);
    if (EOK != ret)
    {
        NXP_LOG_ERROR("Entry-to-args conversion failed: %d\n", ret);
        return ret;
    }

    /*  Argument registers are prepared. Compile the UPDATE command. */
    if (PFE_L2BR_TABLE_MAC2F == l2br->type)
    {
        if ((FALSE == entry->mac_addr_set) && (FALSE == entry->vlan_set))
        {
            NXP_LOG_DEBUG("MAC or VLAN must be set\n");
            return EINVAL;
        }

        cmd = (uint32_t)L2BR_CMD_UPDATE | (((uint32_t)entry->u.mac2f_entry.field_valids & 0x1fU) << 8U);
    }
    else if (PFE_L2BR_TABLE_VLAN == l2br->type)
    {
        if (FALSE == entry->vlan_set)
        {
            NXP_LOG_DEBUG("VLAN must be set\n");
            return EINVAL;
        }

        cmd = (uint32_t)L2BR_CMD_UPDATE | (((uint32_t)entry->u.vlan_entry.field_valids & 0x1fU) << 8U);
    }
    else
    {
        NXP_LOG_ERROR("Invalid table type\n");
        return EINVAL;
    }

    /*  Issue the UPDATE command */
    hal_write32(cmd, l2br->regs.cmd_reg);

    ret = pfe_l2br_wait_for_cmd_done(l2br, &status);
    if (EOK != ret)
    {
        return ret;
    }

    if (0U != (status & STATUS_REG_SIG_ENTRY_NOT_FOUND))
    {
        NXP_LOG_DEBUG("Attempting to update non-existing entry\n");
        return ENOENT;
    }

    if (0U == (status & STATUS_REG_SIG_ENTRY_ADDED))
    {
        NXP_LOG_ERROR("Table entry UPDATE CMD failed\n");
        return ENOEXEC;
    }

    return EOK;
}

/**
 * @brief       Delete entry from table
 * @warning     This function shouldn't be called directly. Call equivalent function with register lock.
 */
static errno_t pfe_l2br_table_do_del_entry_nolock(pfe_l2br_table_t *l2br, pfe_l2br_table_entry_t *entry)
{
    uint32_t status, cmd;
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == l2br) || (NULL == entry)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    /*  Prepare command arguments */
    ret = pfe_l2br_entry_to_cmd_args(l2br, entry);
    if (EOK != ret)
    {
        NXP_LOG_ERROR("Entry-to-args conversion failed: %d\n", ret);
        return ret;
    }

    /*  Argument registers are prepared. Compile the DEL command. */
    if (PFE_L2BR_TABLE_MAC2F == l2br->type)
    {
        if ((FALSE == entry->mac_addr_set) && (FALSE == entry->vlan_set))
        {
            NXP_LOG_DEBUG("MAC or VLAN must be set\n");
            return EINVAL;
        }

        cmd = (uint32_t)L2BR_CMD_DELETE | (((uint32_t)entry->u.mac2f_entry.field_valids & 0x1fU) << 8U);
    }
    else if (PFE_L2BR_TABLE_VLAN == l2br->type)
    {
        if (FALSE == entry->vlan_set)
        {
            NXP_LOG_DEBUG("VLAN must be set\n");
            return EINVAL;
        }

        cmd = (uint32_t)L2BR_CMD_DELETE | (((uint32_t)entry->u.vlan_entry.field_valids & 0x1fU) << 8U);
    }
    else
    {
        NXP_LOG_ERROR("Invalid table type\n");
        return EINVAL;
    }

    /*  Issue the DEL command */
    hal_write32(cmd, l2br->regs.cmd_reg);

    ret = pfe_l2br_wait_for_cmd_done(l2br, &status);
    if (EOK != ret)
    {
        return ret;
    }

    if (0U != (status & STATUS_REG_SIG_ENTRY_NOT_FOUND))
    {
        NXP_LOG_DEBUG("Attempting to delete non-existing entry\n");
    }

    return EOK;
}

/**
 * @brief       Add entry to table
 * @warning     This function shouldn't be called directly. Call equivalent function with register lock.
 */
static errno_t pfe_l2br_table_do_add_entry_nolock(pfe_l2br_table_t *l2br, pfe_l2br_table_entry_t *entry)
{
    uint32_t status, cmd;
    errno_t ret = EINVAL;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == l2br) || (NULL == entry)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
    {
#endif /* PFE_CFG_NULL_ARG_CHECK */

        /*  Prepare command arguments */
        ret = pfe_l2br_entry_to_cmd_args(l2br, entry);
        if (EOK != ret)
        {
            NXP_LOG_ERROR("Entry-to-args conversion failed: %d\n", ret);
            return ret;
        }

        /*  Argument registers are prepared. Compile the ADD command. */
        if (PFE_L2BR_TABLE_MAC2F == l2br->type)
        {
            if (((FALSE == entry->mac_addr_set) && (FALSE == entry->vlan_set))
                    || (FALSE == entry->action_data_set))
            {
                NXP_LOG_DEBUG("MAC/VLAN and action must be set\n");
                return EINVAL;
            }

            cmd = (uint32_t)L2BR_CMD_ADD | ((entry->u.mac2f_entry.field_valids & 0x1fU) << 8U) | (entry->u.mac2f_entry.port << 16U);
        }
        else if (PFE_L2BR_TABLE_VLAN == l2br->type)
        {
            if ((FALSE == entry->vlan_set) || (FALSE == entry->action_data_set))
            {
                NXP_LOG_DEBUG("VLAN and action must be set\n");
                return EINVAL;
            }

            cmd = (uint32_t)L2BR_CMD_ADD | ((entry->u.vlan_entry.field_valids & 0x1fU) << 8U) | (entry->u.vlan_entry.port << 16U);
        }
        else
        {
            NXP_LOG_ERROR("Invalid table type\n");
            return EINVAL;
        }

        /*  Issue the ADD command */
        hal_write32(cmd, l2br->regs.cmd_reg);

        ret = pfe_l2br_wait_for_cmd_done(l2br, &status);
        if (EOK != ret)
        {
            return ret;
        }

        if (0U == (status & STATUS_REG_SIG_ENTRY_ADDED))
        {
            NXP_LOG_ERROR("Table entry ADD CMD failed\n");
            return ENOEXEC;
        }
#if defined(PFE_CFG_NULL_ARG_CHECK)
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    return ret;
}

/**
 * @brief       Search for entry in table
 * @warning     This function shouldn't be called directly. Call equivalent function with register lock.
 */
static errno_t pfe_l2br_table_do_search_entry_nolock(pfe_l2br_table_t *l2br, pfe_l2br_table_entry_t *entry)
{
    uint32_t status, cmd;
    errno_t ret = EINVAL;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == l2br) || (NULL == entry)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
    {
#endif /* PFE_CFG_NULL_ARG_CHECK */

        /*  Prepare command arguments */
        ret = pfe_l2br_entry_to_cmd_args(l2br, entry);
        if (EOK != ret)
        {
            NXP_LOG_ERROR("Entry-to-args conversion failed: %d\n", ret);
            return ret;
        }

        /*  Argument registers are prepared. Compile the SEARCH command. */
        if (PFE_L2BR_TABLE_MAC2F == l2br->type)
        {
            if ((FALSE == entry->mac_addr_set) && (FALSE == entry->vlan_set))
            {
                NXP_LOG_DEBUG("MAC or VLAN must be set\n");
                return EINVAL;
            }

            cmd = (uint32_t)L2BR_CMD_SEARCH | ((entry->u.mac2f_entry.field_valids & 0x1fU) << 8U) | (entry->u.mac2f_entry.port << 16U);
        }
        else if (PFE_L2BR_TABLE_VLAN == l2br->type)
        {
            if (FALSE == entry->vlan_set)
            {
                NXP_LOG_DEBUG("VLAN must be set\n");
                return EINVAL;
            }

            cmd = (uint32_t)L2BR_CMD_SEARCH | ((entry->u.vlan_entry.field_valids & 0x1fU) << 8U) | (entry->u.vlan_entry.port << 16U);
        }
        else
        {
            NXP_LOG_ERROR("Invalid table type\n");
            return EINVAL;
        }

        /*  Issue the SEARCH command */
        hal_write32(cmd, l2br->regs.cmd_reg);

        ret = pfe_l2br_wait_for_cmd_done(l2br, &status);
        if (EOK != ret)
        {
            return ret;
        }

        if (0U != (status & STATUS_REG_SIG_ENTRY_NOT_FOUND))
        {
            NXP_LOG_DEBUG("L2BR table entry not found\n");
            return ENOENT;
        }

        if (0U == (status & STATUS_REG_MATCH))
        {
            NXP_LOG_DEBUG("L2BR table entry mismatch\n");
            return ENOENT;
        }

        pfe_l2br_get_data(l2br, entry);
#if defined(PFE_CFG_NULL_ARG_CHECK)
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    return ret;
}


/**
 * @brief       Update table entry
 * @details     Associates new action data with the entry.
 * @param[in]   l2br The L2 Bridge Table instance
 * @param[in]   entry Entry to be updated
 * @retval      EOK Success
 * @retval      EINVAL Invalid/missing argument
 * @retval      ENOENT Entry not found
 * @retval      ENOEXEC Command failed
 * @retval      ETIMEDOUT Command timed-out
 */
errno_t pfe_l2br_table_update_entry(pfe_l2br_table_t *l2br, pfe_l2br_table_entry_t *entry)
{
    errno_t ret = EOK;

    ret = pfe_l2br_table_do_update_entry_nolock(l2br, entry);

    return ret;
}

/**
 * @brief       Delete entry from table
 * @details     Entry is removed from table if exists. If does not exist, the call
 *              returns success (EOK).
 * @param[in]   l2br The L2 Bridge Table instance
 * @param[in]   data Entry to be deleted
 * @retval      EOK Success
 * @retval      EINVAL Invalid/missing argument
 * @retval      ETIMEDOUT Command timed-out
 */
errno_t pfe_l2br_table_del_entry(pfe_l2br_table_t *l2br, pfe_l2br_table_entry_t *entry)
{
    errno_t ret = EOK;

    ret = pfe_l2br_table_do_del_entry_nolock(l2br, entry);

    return ret;
}

/**
 * @brief       Add entry to table
 * @param[in]   l2br The L2 Bridge Table instance
 * @param[in]   data Entry to be added
 * @retval      EOK Success
 * @retval      EINVAL Invalid/missing argument
 * @retval      ENOEXEC Command failed
 * @retval      ETIMEDOUT Command timed-out
 */
errno_t pfe_l2br_table_add_entry(pfe_l2br_table_t *l2br, pfe_l2br_table_entry_t *entry)
{
    errno_t ret = EOK;

    ret = pfe_l2br_table_do_add_entry_nolock(l2br, entry);

    return ret;
}

/**
 * @brief           Search entry in table
 * @param[in]       l2br The L2 Bridge Table instance
 * @param[in,out]   data Reference entry to be used for lookup. This entry will be updated by
 *                       values read from the table.
 * @retval          EOK Success
 * @retval          EINVAL Invalid/missing argument
 * @retval          ENOENT Entry not found
 * @retval          ETIMEDOUT Command timed-out
 */
errno_t pfe_l2br_table_search_entry(pfe_l2br_table_t *l2br, pfe_l2br_table_entry_t *entry)
{
    errno_t ret = EOK;

    ret = pfe_l2br_table_do_search_entry_nolock(l2br, entry);

    return ret;
}

/**
 * @brief           Create iterator instance to go through the table
 * @param[in]       loop_inst The iterator to be initialized
 * @return          iterator on success, NULL on failure
 */
pfe_l2br_table_iterator_t *pfe_l2br_iterator_create(pfe_l2br_table_iterator_t *loop_inst)
{
    if (NULL != loop_inst)
    {
        loop_inst->cur_hash_addr = 0;
        loop_inst->cur_coll_addr = 0;
        loop_inst->next_coll_addr = 0;
        loop_inst->cur_crit = L2BR_TABLE_CRIT_ALL;

        (void)autolibc_memset(&loop_inst->cur_macvlan, 0, sizeof(loop_inst->cur_macvlan));
    }

    return loop_inst;
}

/**
 * @brief           Destroy table iterator
 * @param[in]       inst Iterator instance to be destroyed
 * @retval          EOK on success
 */
errno_t pfe_l2br_iterator_destroy(const pfe_l2br_table_iterator_t *inst)
{
    (void)inst;
    return EOK;
}

/**
 * @brief           Compute hash of the entry.
 * @details         It is assumed that this function uses same algorithms as PFE HW.
 * @param[in]       entry Entry to be hashed
 * @param[out]      hash [passback] Hash of the entry
 * @retval          hash of the entry
 */
static uint8_t pfe_l2br_entry_get_hash(const pfe_l2br_table_entry_t *entry)
{
    uint16_t hash = 0U;
    
    #if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == entry))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        hash = EINVAL;
    }
    else
    #endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (PFE_L2BR_TABLE_MAC2F == entry->type)
        {
            /*  NOTE: It is assumed that MAC entry (as provided by pfe_l2br_table_read_cmd()) has reverse byte order of MAC address bytes */
            const uint16_t *p = (uint16_t*)(entry->u.mac2f_entry.mac);
            hash = oal_htons(p[0]) ^ oal_htons(p[1]) ^ oal_htons(p[2]) ^ (uint16_t)(entry->u.mac2f_entry.vlan);
            hash &= 0x00FFU;
        }
        else
        {
            hash = (uint16_t)entry->u.vlan_entry.vlan & 0x003FU; /* max hash value is 63 */
        }
    }
    return (uint8_t)hash;
}

/**
 * @brief           Save macvlan data to iterator
 * @param[in,out]   l2t_iter Iterator which shall be updated
 * @param[in]       entry Entry to be used as a source of macvlan data
 */
static void pfe_l2br_iterator_save_macvlan(pfe_l2br_table_iterator_t *l2t_iter, const pfe_l2br_table_entry_t *entry)
{
    #if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == l2t_iter) || (NULL == entry))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else 
    #endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (PFE_L2BR_TABLE_MAC2F == entry->type)
        {
            (void)autolibc_memcpy(l2t_iter->cur_macvlan.mac, entry->u.mac2f_entry.mac, sizeof(pfe_mac_addr_t));
            l2t_iter->cur_macvlan.vlan = (uint16_t)entry->u.mac2f_entry.vlan;
        }
        else
        {
            l2t_iter->cur_macvlan.vlan = (uint16_t)entry->u.vlan_entry.vlan;
        }
    }
}

/**
 * @brief           Check whether iterator macvlan data matches data of provided entry.
 * @param[in]       l2t_iter Iterator with macvlan data
 * @param[in]       entry Entry to be checked
 * @retval          TRUE Data match
 * @retval          FALSE Data don't match
 */
static bool_t pfe_l2br_iterator_is_macvlan_match(const pfe_l2br_table_iterator_t *l2t_iter, const pfe_l2br_table_entry_t *entry)
{
    bool_t is_match = FALSE;

    #if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == l2t_iter) || (NULL == entry))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        is_match = FALSE;
    }
    else
    #endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (PFE_L2BR_TABLE_MAC2F == entry->type)
        {
            if (0 == autolibc_memcmp(l2t_iter->cur_macvlan.mac, entry->u.mac2f_entry.mac, sizeof(pfe_mac_addr_t)))
            {
                if (l2t_iter->cur_macvlan.vlan == entry->u.mac2f_entry.vlan)
                {
                    is_match = TRUE;
                }
            }
        }
        else
        {
            if (l2t_iter->cur_macvlan.vlan == entry->u.vlan_entry.vlan)
            {
                is_match = TRUE;
            }
        }
    }
    return is_match;
}

/**
 * @brief           Get first entry from table
 * @param[in]       l2br The L2 Bridge Table instance
 * @param[in]       crit Get criterion
 * @param[out]      entry Entry will be written at this location
 * @retval          EOK Success
 * @retval          EINVAL Invalid/missing argument
 * @retval          ENOENT Entry not found
 * @retval          ETIMEDOUT Command timed-out
 */
errno_t pfe_l2br_table_get_first(pfe_l2br_table_t *l2br, pfe_l2br_table_iterator_t *l2t_iter, pfe_l2br_table_get_criterion_t crit, pfe_l2br_table_entry_t *entry)
{
    errno_t ret = ENOENT;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == l2br) || (NULL == entry)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  Remember criterion and argument for possible subsequent pfe_l2br_table_get_next() calls */
        l2t_iter->cur_crit = crit;

        /*  Get entries from address 0x0 */
        (void)autolibc_memset(&l2t_iter->cur_macvlan, 0, sizeof(l2t_iter->cur_macvlan)); 
        for (l2t_iter->cur_hash_addr=0U, l2t_iter->cur_coll_addr=0U; l2t_iter->cur_hash_addr<l2br->hash_space_depth; l2t_iter->cur_hash_addr++)
        {
            ret = pfe_l2br_table_read_cmd(l2br, l2t_iter->cur_hash_addr, entry);
            if (EOK != ret)
            {
                NXP_LOG_DEBUG("Can not read table entry from location %d\n", (int_t)l2t_iter->cur_hash_addr);
                ret = ENOENT;
                break;
            }
            else
            {
                l2t_iter->cur_coll_addr = l2t_iter->cur_hash_addr; /* cur_coll_addr is utilized to store address of previous valid MAC entry from HW, regardless of hash/coll space */
                pfe_l2br_iterator_save_macvlan(l2t_iter, entry);
                ret = ENOENT;
                if (TRUE == pfe_l2br_table_entry_match_criterion(l2br, l2t_iter, entry))
                {
                    /*  Remember entry to be processed next */
                    l2t_iter->next_coll_addr = pfe_l2br_table_get_col_ptr(entry);
                    l2t_iter->cur_hash_addr++;
                    ret = EOK;
                    break;
                }
            }
        }
    }

    return ret;
}

/**
 * @brief           Get next entry from table
 * @param[in]       l2br The L2 Bridge Table instance
 * @param[in]       addr Address within the table to read entry from
 * @param[out]      entry Entry will be written at this location
 * @retval          EOK Success
 * @retval          EINVAL Invalid/missing argument
 * @retval          ENOENT Entry not found
 * @retval          ETIMEDOUT Command timed-out
 */
errno_t pfe_l2br_table_get_next(pfe_l2br_table_t *l2br, pfe_l2br_table_iterator_t *l2t_iter, pfe_l2br_table_entry_t *entry)
{
    errno_t ret;
    errno_t RetVal = ENOENT;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == l2br) || (NULL == entry)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        RetVal = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  Get entries from last address */
        while ((l2t_iter->cur_hash_addr < l2br->hash_space_depth) || (0U != l2t_iter->next_coll_addr) )
        {
            if (0U == l2t_iter->next_coll_addr)
            {
                /*  Read from hash space */
                ret = pfe_l2br_table_read_cmd(l2br, l2t_iter->cur_hash_addr, entry);
                if (EOK == ret)
                {
                    /*  candidate MAC entry found */
                    l2t_iter->cur_coll_addr = l2t_iter->cur_hash_addr; /* cur_coll_addr is utilized to store address of previous valid MAC entry from HW, regardless of hash/coll space */
                    l2t_iter->cur_hash_addr++;
                    pfe_l2br_iterator_save_macvlan(l2t_iter, entry);
                }
            }
            else
            {
                /*  Read from collision space */
                ret = pfe_l2br_table_read_cmd(l2br, l2t_iter->next_coll_addr, entry);
                if (EOK == ret)
                {
                    /*  check hash ; by design of the lookup routine, iterator's actual cur_hash_addr is already +1 ahead */
                    if ((l2t_iter->cur_hash_addr - 1U) == pfe_l2br_entry_get_hash(entry))
                    {
                        /*  === hash OK === ; candidate MAC entry found */
                        l2t_iter->cur_coll_addr = l2t_iter->next_coll_addr; /* cur_coll_addr is utilized to store address of previous valid MAC entry from HW, regardless of hash/coll space */
                        pfe_l2br_iterator_save_macvlan(l2t_iter, entry);
                    }
                    else
                    {
                        /*  === hash NOT OK === ; try to re-read previous valid MAC entry */
                        ret = pfe_l2br_table_read_cmd(l2br, l2t_iter->cur_coll_addr, entry);
                        if (EOK == ret)
                        {
                            /*  check hash ; by design of the lookup routine, iterator's actual cur_hash_addr is already +1 ahead */
                            if ((l2t_iter->cur_hash_addr - 1U) == pfe_l2br_entry_get_hash(entry))
                            {
                                /* --- hash OK --- */
                                if (pfe_l2br_iterator_is_macvlan_match(l2t_iter, entry))
                                {
                                    /*  acquire new (hopefully valid) collision pointer from re-read previous MAC entry and go get data from the new collision pointer */
                                    l2t_iter->next_coll_addr = pfe_l2br_table_get_col_ptr(entry);
                                    continue;
                                }
                                else
                                {
                                    /*  previous MAC entry has different macvlan ; candidate MAC entry found */
                                    pfe_l2br_iterator_save_macvlan(l2t_iter, entry);
                                }
                            }
                            else
                            {
                                /* --- hash NOT OK --- ; collision list is compromised. Abandon it and move to the next hash space slot. */
                                l2t_iter->next_coll_addr = 0U;
                                continue;
                            }
                        }
                    }
                }
            }

            if (EOK != ret)
            {
                NXP_LOG_DEBUG("Can not read table entry\n");
                RetVal = EINVAL;
                break;
            }
            else
            {
                if (TRUE == pfe_l2br_table_entry_match_criterion(l2br, l2t_iter, entry))
                {
                    l2t_iter->next_coll_addr = pfe_l2br_table_get_col_ptr(entry);
                    RetVal = EOK;
                    break;
                }
                else
                {
                    RetVal = EINVAL;
                }
            }
        }
    }
    return RetVal;
}

/**
 * @brief       Wait for command completion
 * @details     Function will wait until previously issued command has completed.
 * @param[in]   l2br The L2 Bridge Table instance
 * @param[out]  status_val If not NULL, the function will write content of status register there.
 * @retval      EOK Success
 * @retval      ETIMEDOUT Timed out
 */
static errno_t pfe_l2br_wait_for_cmd_done(const pfe_l2br_table_t *l2br, uint32_t *status_val)
{
    uint32_t ii = 100U;
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == l2br))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  Wait for command completion */
        while (0U == (hal_read32(l2br->regs.status_reg) & STATUS_REG_CMD_DONE))
        {
            ii--;
            oal_time_usleep(10);

            if (0U == ii)
            {
                break;
            }
        }

        if (NULL != status_val)
        {
            *status_val = hal_read32(l2br->regs.status_reg);
        }

        /*  Clear the STATUS register */
        hal_write32(0xffffffffU, l2br->regs.status_reg);

        if (0U == ii)
        {
            ret = ETIMEDOUT;
        }
        else
        {
            ret = EOK;
        }
    }
    return ret;
}

/**
 * @brief       Direct MEM WRITE command
 * @param[in]   l2br The L2 Bridge table instance
 * @param[in]   addr Address within the table (index of entry to be written)
 * @param[in]   wdata Entry data. Shall match the table type. Shall be pfe_mac2f_table_entry_t
 *                    or pfe_vlan_table_entry_t.
 * @retval      EOK Success
 * @retval      EINVAL Invalid/missing argument
 * @retval      ETIMEDOUT Command timed-out
 */
static errno_t pfe_l2br_table_write_cmd(pfe_l2br_table_t *l2br, uint32_t addr, pfe_l2br_table_entry_t *entry)
{
    uint32_t *wdata = (uint32_t *)entry;
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == l2br) || (NULL == entry)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (addr >= ((uint32_t)l2br->hash_space_depth + l2br->coll_space_depth))
        {
            NXP_LOG_ERROR("Hash table address 0x%x is out of range\n",(uint_t)addr);
            ret = EINVAL;
        }
        else
        {
            if (PFE_L2BR_TABLE_MAC2F == l2br->type)
            {
                ct_assert(sizeof(pfe_mac2f_table_entry_t) == 16);
                wdata = (uint32_t *)&entry->u.mac2f_entry;
                ret = EOK;
            }
            else if (PFE_L2BR_TABLE_VLAN == l2br->type)
            {
                ct_assert(sizeof(pfe_vlan_table_entry_t) == 16);
                wdata = (uint32_t *)&entry->u.vlan_entry;
                ret = EOK;
            }
            else
            {
                NXP_LOG_ERROR("Invalid table type\n");
                ret = EINVAL;
            }

            if (EOK == ret)
            {
                /*  Issue the WRITE command */
                hal_write32(wdata[0], l2br->regs.mac1_addr_reg);    /* wdata[31:0]    */
                hal_write32(wdata[1], l2br->regs.mac2_addr_reg);    /* wdata[63:32]   */
                hal_write32(wdata[2], l2br->regs.mac3_addr_reg);    /* wdata[95:64]   */
                hal_write32(wdata[3], l2br->regs.mac4_addr_reg);    /* wdata[127:96]  */

                hal_write32((uint32_t)L2BR_CMD_MEM_WRITE | (addr << 16U), l2br->regs.cmd_reg);

                ret = pfe_l2br_wait_for_cmd_done(l2br, NULL);
            }
        }
    }
    return ret;
}

/**
 * @brief       Direct MEM READ command
 * @param[in]   l2br The L2 Bridge table instance
 * @param[in]   addr Address within the table (index of entry to be read)
 * @param[out]  data Pointer to memory where entry will be written. See pfe_mac_2f_table_entry_t
 *                   or pfe_vlan_table_entry_t.
 * @retval      EOK Success
 * @retval      EINVAL Invalid/missing argument
 * @retval      ETIMEDOUT Command timed-out
 */
static errno_t pfe_l2br_table_read_cmd(pfe_l2br_table_t *l2br, uint32_t addr, pfe_l2br_table_entry_t *entry)
{
    errno_t ret;
    uint32_t *rdata;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == l2br) || (NULL == entry)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    if (addr >= ((uint32_t)l2br->hash_space_depth + l2br->coll_space_depth))
    {
        NXP_LOG_ERROR("Hash table address 0x%x is out of range\n", (uint_t)addr);
        return EINVAL;
    }

    if (PFE_L2BR_TABLE_MAC2F == l2br->type)
    {
        ct_assert(sizeof(pfe_mac2f_table_entry_t) == 16);
        rdata = (uint32_t *)&entry->u.mac2f_entry;
    }
    else if (PFE_L2BR_TABLE_VLAN == l2br->type)
    {
        ct_assert(sizeof(pfe_vlan_table_entry_t) == 16);
        rdata = (uint32_t *)&entry->u.vlan_entry;
    }
    else
    {
        NXP_LOG_ERROR("Invalid table type\n");
        return EINVAL;
    }

    /*  Issue the READ command */
    hal_write32((uint32_t)L2BR_CMD_MEM_READ | ((uint32_t)addr << 16), l2br->regs.cmd_reg);

    ret = pfe_l2br_wait_for_cmd_done(l2br, NULL);
    if (EOK != ret)
    {
        NXP_LOG_ERROR("Table read failed: %d\n", ret);
        return ret;
    }

    rdata[0] = hal_read32(l2br->regs.mac1_addr_reg);
    rdata[1] = hal_read32(l2br->regs.mac2_addr_reg);
    rdata[2] = hal_read32(l2br->regs.mac3_addr_reg);
    rdata[3] = hal_read32(l2br->regs.mac4_addr_reg);

    if (PFE_L2BR_TABLE_MAC2F == l2br->type)
    {
        uint32_t data32 = oal_htonl(rdata[0]);
        uint16_t data16 = oal_htons(rdata[1] & 0xffffU);

        (void)autolibc_memcpy(&entry->u.mac2f_entry.mac[0], &data32, sizeof(uint32_t));
        (void)autolibc_memcpy(&entry->u.mac2f_entry.mac[4], &data16, sizeof(uint16_t));

        entry->mac_addr_set = TRUE;
    }

    entry->type = l2br->type;
    entry->vlan_set = TRUE;
    entry->action_data_set = TRUE;

    return EOK;
}

/**
 * @brief       Issue the INIT command
 * @param[in]   l2br The L2 bridge table instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid/missing argument
 * @retval      ENOEXEC Command failed
 * @retval      ETIMEDOUT Command timed-out
 */
static errno_t pfe_l2br_table_init_cmd(pfe_l2br_table_t *l2br)
{
    errno_t ret;
    uint32_t ii, status;
    pfe_l2br_table_entry_t entry = {0U};

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == l2br))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    /*  Issue the INIT command */
    hal_write32(L2BR_CMD_INIT, l2br->regs.cmd_reg);
    ret = pfe_l2br_wait_for_cmd_done(l2br, &status);
    if (EOK != ret)
    {
        return ret;
    }

    if (0U == (status & STATUS_REG_SIG_INIT_DONE))
    {
        NXP_LOG_ERROR("Table INIT CMD failed\n");
        return ENOEXEC;
    }

    hal_write32(0U, l2br->regs.mac1_addr_reg);
    hal_write32(0U, l2br->regs.mac2_addr_reg);
    hal_write32(0U, l2br->regs.mac3_addr_reg);
    hal_write32(0U, l2br->regs.mac4_addr_reg);
    hal_write32(0U, l2br->regs.mac5_addr_reg);

    for (ii=0U; ii<l2br->coll_space_depth; ii++)
    {
        if (PFE_L2BR_TABLE_MAC2F == l2br->type)
        {
            entry.u.mac2f_entry.col_ptr = l2br->hash_space_depth + ii + 1U;
            entry.u.mac2f_entry.flags = (uint32_t)MAC2F_ENTRY_COL_PTR_VALID_FLAG;
        }
        else if (PFE_L2BR_TABLE_VLAN == l2br->type)
        {
            entry.u.vlan_entry.col_ptr = l2br->hash_space_depth + ii + 1U;
            entry.u.vlan_entry.flags = (uint32_t)VLAN_ENTRY_COL_PTR_VALID_FLAG;
        }
        else
        {
            NXP_LOG_ERROR("Invalid table type\n");
            return EINVAL;
        }

        ret = pfe_l2br_table_write_cmd(l2br, l2br->hash_space_depth + ii, (void *)&entry);
        if (EOK != ret)
        {
            NXP_LOG_ERROR("Init failed: %d\n", ret);
            return ret;
        }
    }

    hal_write32(l2br->hash_space_depth, l2br->regs.free_head_ptr_reg);
    hal_write32((uint32_t)l2br->hash_space_depth + l2br->coll_space_depth - 1U, l2br->regs.free_tail_ptr_reg);
    hal_write32(l2br->coll_space_depth, l2br->regs.free_entries_reg);

    return EOK;
}

/**
 * @brief       Issue the FLUSH command
 * @details     It is possible to exted with option to flush only entries of certain VLAN
 * @param[in]   l2br The L2 bridge table instance
 * @retval      EOK Success
 * @retval      EINVAL Invalid/missing argument
 * @retval      ENOEXEC Command failed
 * @retval      ETIMEDOUT Command timed-out
 */
static errno_t pfe_l2br_table_flush_cmd(pfe_l2br_table_t *l2br)
{
    uint32_t cmd;
    errno_t ret;

    /*  Prepare command arguments */
    if ((PFE_L2BR_TABLE_MAC2F == l2br->type) || (PFE_L2BR_TABLE_VLAN == l2br->type))
    {
        cmd = (uint32_t)L2BR_CMD_FLUSH | ((uint32_t)1U << 14);

        hal_write32(0U, l2br->regs.mac1_addr_reg);
        hal_write32(0U, l2br->regs.mac2_addr_reg);
        hal_write32(0U, l2br->regs.mac3_addr_reg);
        hal_write32(0U, l2br->regs.mac4_addr_reg);
        hal_write32(0U, l2br->regs.mac5_addr_reg);

        /*  Issue the FLUSH command */
        hal_write32(cmd, l2br->regs.cmd_reg);

        ret = pfe_l2br_wait_for_cmd_done(l2br, NULL);
    }
    else
    {
        NXP_LOG_ERROR("Invalid table type\n");
        ret = EINVAL;
    }

    return ret;
}

/**
 * @brief       Create L2 bridge table instance
 * @param[in]   cbus_base_va CBUS base virtual address
 * @param[in]   type Type of the table. See pfe_l2br_table_type_t.
 * @return      The L2 Bridge table instance or NULL if failed
 */
pfe_l2br_table_t *pfe_l2br_table_create(addr_t cbus_base_va, pfe_l2br_table_type_t type)
{
    errno_t ret;
    pfe_l2br_table_t *l2br = NULL;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_ADDR == cbus_base_va))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        switch (type)
        {
            case PFE_L2BR_TABLE_MAC2F:
            {
                l2br = &mactab_instance;
                (void)autolibc_memset(l2br, 0, sizeof(pfe_l2br_table_t));
                l2br->regs.cmd_reg = cbus_base_va + HOST_MAC2F_CMD_REG;
                l2br->regs.mac1_addr_reg = cbus_base_va + HOST_MAC2F_MAC1_ADDR_REG;
                l2br->regs.mac2_addr_reg = cbus_base_va + HOST_MAC2F_MAC2_ADDR_REG;
                l2br->regs.mac3_addr_reg = cbus_base_va + HOST_MAC2F_MAC3_ADDR_REG;
                l2br->regs.mac4_addr_reg = cbus_base_va + HOST_MAC2F_MAC4_ADDR_REG;
                l2br->regs.mac5_addr_reg = cbus_base_va + HOST_MAC2F_MAC5_ADDR_REG;
                l2br->regs.entry_reg = cbus_base_va + HOST_MAC2F_ENTRY_REG;
                l2br->regs.status_reg = cbus_base_va + HOST_MAC2F_STATUS_REG;
                l2br->regs.direct_reg = cbus_base_va + HOST_MAC2F_DIRECT_REG;
                l2br->regs.free_entries_reg = cbus_base_va + HOST_MAC2F_FREE_LIST_ENTRIES;
                l2br->regs.free_head_ptr_reg = cbus_base_va + HOST_MAC2F_FREE_LIST_HEAD_PTR;
                l2br->regs.free_tail_ptr_reg = cbus_base_va + HOST_MAC2F_FREE_LIST_TAIL_PTR;
                l2br->hash_space_depth = MAC2F_TABLE_HASH_ENTRIES;
                l2br->coll_space_depth = MAC2F_TABLE_COLL_ENTRIES;
                break;
            }

            case PFE_L2BR_TABLE_VLAN:
            {
                l2br = &vlantab_instance;
                (void)autolibc_memset(l2br, 0, sizeof(pfe_l2br_table_t));
                l2br->regs.cmd_reg = cbus_base_va + HOST_VLAN_CMD_REG;
                l2br->regs.mac1_addr_reg = cbus_base_va + HOST_VLAN_MAC1_ADDR_REG;
                l2br->regs.mac2_addr_reg = cbus_base_va + HOST_VLAN_MAC2_ADDR_REG;
                l2br->regs.mac3_addr_reg = cbus_base_va + HOST_VLAN_MAC3_ADDR_REG;
                l2br->regs.mac4_addr_reg = cbus_base_va + HOST_VLAN_MAC4_ADDR_REG;
                l2br->regs.mac5_addr_reg = cbus_base_va + HOST_VLAN_MAC5_ADDR_REG;
                l2br->regs.entry_reg = cbus_base_va + HOST_VLAN_ENTRY_REG;
                l2br->regs.status_reg = cbus_base_va + HOST_VLAN_STATUS_REG;
                l2br->regs.direct_reg = cbus_base_va + HOST_VLAN_DIRECT_REG;
                l2br->regs.free_entries_reg = cbus_base_va + HOST_VLAN_FREE_LIST_ENTRIES;
                l2br->regs.free_head_ptr_reg = cbus_base_va + HOST_VLAN_FREE_LIST_HEAD_PTR;
                l2br->regs.free_tail_ptr_reg = cbus_base_va + HOST_VLAN_FREE_LIST_TAIL_PTR;
                l2br->hash_space_depth = VLAN_TABLE_HASH_ENTRIES;
                l2br->coll_space_depth = VLAN_TABLE_COLL_ENTRIES;
                break;
            }

            default:
            {
                NXP_LOG_ERROR("Invalid table type\n");
                break;
            }
        }

        if (NULL != l2br)
        {
            l2br->type = type;
            l2br->cbus_base_va = cbus_base_va;

            /*  Initialize the table */
            ret = pfe_l2br_table_init_cmd(l2br);
            if (EOK != ret)
            {
                NXP_LOG_ERROR("Table initialization failed: %d\n", ret);
                l2br = NULL;
            }
        }
    }

    return l2br;
}

/**
 * @brief       Initialize table
 * @details     Remove all table entries and prepare the table for usage
 * @param[in]   l2br The L2 bridge table instance
 * @retval      EOK if success, error code otherwise
 */
errno_t pfe_l2br_table_init(pfe_l2br_table_t *l2br)
{
    errno_t ret;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == l2br))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ret = pfe_l2br_table_init_cmd(l2br);
    }

    return ret;
}

/**
 * @brief       Flush table
 * @details     Remove all table entries
 * @param[in]   l2br The L2 bridge table instance
 * @retval      EOK if success, error code otherwise
 */
errno_t pfe_l2br_table_flush(pfe_l2br_table_t *l2br)
{
    errno_t ret;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == l2br))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ret = pfe_l2br_table_flush_cmd(l2br);
    }
    return ret;
}

/**
 * @brief       Create and initialize L2 bridge table entry instance
 * @note        When not needed entry shall be released by pfe_l2br_table_entry_destroy()
 * @param[in]   l2br The L2 bridge table instance
 * @param[in]   entry The bridge table entry instance to be initialized
 * @return      Bridge table entry instance or NULL if failed
 */
pfe_l2br_table_entry_t *pfe_l2br_table_entry_create(const pfe_l2br_table_t *l2br, pfe_l2br_table_entry_t *entry)
{
    pfe_l2br_table_entry_t *ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == l2br) || unlikely(NULL == entry))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (NULL != entry)
        {
            (void)autolibc_memset(entry, 0, sizeof(pfe_l2br_table_entry_t));
            entry->type = l2br->type;
            /*  TODO: Only for debug purposes */
            entry->action_data_set = FALSE;
            entry->mac_addr_set = FALSE;
            entry->vlan_set = FALSE;
        }
        ret = entry;
    }

    return ret;
}

/**
 * @brief       Destroy entry created by pfe_l2br_table_entry_create()
 * @param[in]   entry The entry to be destroyed
 * @retval      EOK Success
 * @retval      EINVAL Invalid/missing argument
 */
errno_t pfe_l2br_table_entry_destroy(const pfe_l2br_table_entry_t *entry)
{
    errno_t ret;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == entry))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
    (void)entry;
    ret = EOK;
    }
    return ret;
}

/**
 * @brief       Set MAC address
 * @param[in]   entry The entry
 * @param[in]   mac_addr MAC address to be associated with the entry
 * @retval      EOK Success
 * @retval      EINVAL Invalid/missing argument
 * @retval      EPERM Operation not permitted
 */
errno_t pfe_l2br_table_entry_set_mac_addr(pfe_l2br_table_entry_t *entry,const pfe_mac_addr_t mac_addr)
{
    errno_t ret;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == entry))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (PFE_L2BR_TABLE_MAC2F == entry->type)
        {
            (void)autolibc_memcpy(entry->u.mac2f_entry.mac, mac_addr, sizeof(pfe_mac_addr_t));
            entry->u.mac2f_entry.field_valids |= MAC2F_ENTRY_MAC_VALID;
            ret = EOK;
        }
        else if (PFE_L2BR_TABLE_VLAN == entry->type)
        {
            NXP_LOG_DEBUG("Unsupported entry type\n");
            ret = EPERM;
        }
        else
        {
            NXP_LOG_DEBUG("Invalid entry type\n");
            ret = EINVAL;
        }
        if (EOK == ret)
        {
            entry->mac_addr_set = TRUE;
        }
    }
    return ret;
}

/**
 * @brief       Set VLAN
 * @param[in]   entry The entry
 * @param[in]   mac_addr VLAN tag to be associated with the entry (13-bit)
 * @retval      EOK Success
 * @retval      EINVAL Invalid/missing argument
 */
errno_t pfe_l2br_table_entry_set_vlan(pfe_l2br_table_entry_t *entry, uint16_t vlan)
{
    errno_t ret;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == entry))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (PFE_L2BR_TABLE_MAC2F == entry->type)
        {
            entry->u.mac2f_entry.vlan = ((uint32_t)vlan & (uint32_t)0x1fffU);
            entry->u.mac2f_entry.field_valids |= MAC2F_ENTRY_VLAN_VALID;
            ret = EOK;
        }
        else if (PFE_L2BR_TABLE_VLAN == entry->type)
        {
            entry->u.vlan_entry.vlan = ((uint32_t)vlan & (uint32_t)0x1fffU);
            entry->u.vlan_entry.field_valids |= VLAN_ENTRY_VLAN_VALID;
            ret = EOK;
        }
        else
        {
            NXP_LOG_DEBUG("Invalid entry type\n");
            ret = EINVAL;
        }

        if (EOK == ret)
        {
            entry->vlan_set = TRUE;
        }
    }
    return ret;
}


/**
 * @brief       Get vlan from L2 table entry
 * @param[in]   pfe_l2br_table_entry_t table entry
 * @return      Vlan of table entry
 */
__attribute__((pure)) uint32_t pfe_l2br_table_entry_get_vlan(const pfe_l2br_table_entry_t *entry)
{
    return entry->u.mac2f_entry.vlan;
}

/**
 * @brief       Associate action data with table entry
 * @details     Action data vector is available as output of entry match event.
 * @param[in]   entry The entry
 * @param[in]   action The action data
 * @retval      EOK Success
 * @retval      EINVAL Invalid/missing argument
 */
errno_t pfe_l2br_table_entry_set_action_data(pfe_l2br_table_entry_t *entry, uint64_t action_data)
{
    errno_t ret;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == entry))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (PFE_L2BR_TABLE_MAC2F == entry->type)
        {
            if (action_data > 0x7fffffffU)
            {
                NXP_LOG_DEBUG("Action data too long. Max 31bits allowed for MAC table.\n");
            }

            entry->u.mac2f_entry.action_data = (uint32_t)(action_data & 0x7fffffffU);
            ret = EOK;
        }
        else if (PFE_L2BR_TABLE_VLAN == entry->type)
        {
            if (action_data > 0x7fffffffffffffULL)
            {
                NXP_LOG_DEBUG("Action data too long. Max 55bits allowed for VLAN table.\n");
            }

            entry->u.vlan_entry.action_data = (uint64_t)(action_data & 0x7fffffffffffffULL);
            ret = EOK;
        }
        else
        {
            NXP_LOG_DEBUG("Invalid entry type\n");
            ret = EINVAL;
        }
        if (EOK == ret)
        {
            entry->action_data_set = TRUE;
        }
    }
    return ret;
}

/**
 * @brief       Get action data from table entry
 * @details     Action data vector is available as output of entry match event.
 * @param[in]   entry The entry
 * @return      The action data
 */

__attribute__((pure)) uint64_t pfe_l2br_table_entry_get_action_data(const pfe_l2br_table_entry_t *entry)
{
    return entry->u.mac2f_entry.action_data;
}

/**
 * @brief       Set 'fresh' bit value
 * @param[in]   entry The entry
 * @param[in]   is_fresh The 'fresh' bit value to be set
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 * @retval      ENOENT Entry not found
 * @retval      ENOEXEC Command failed
 * @retval      ETIMEDOUT Command timed-out
 */
errno_t pfe_l2br_table_entry_set_fresh(const pfe_l2br_table_t *l2br, pfe_l2br_table_entry_t *entry, bool_t is_fresh)
{
    uint32_t action_data;
    pfe_ct_mac_table_result_t *mac_entry = (pfe_ct_mac_table_result_t *)&action_data;
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == l2br) || (NULL == entry)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if ((l2br->type != PFE_L2BR_TABLE_MAC2F) || (entry->type != PFE_L2BR_TABLE_MAC2F))
        {
            /*  Only MAC table entries can be currently 'fresh' */
            ret = EINVAL;
        }
        else
        {
            /*  Update the action entry */
            action_data = entry->u.mac2f_entry.action_data;
            mac_entry->item.fresh_flag = (TRUE == is_fresh) ? 1U : 0U;
            entry->u.mac2f_entry.action_data = action_data;

            ret = EOK;
        }
    }
    return ret;
}

/**
 * @brief       Get 'fresh' bit value
 * @details     Fresh bit within an entry indicates that entry is actively being
 *              used by packet classification process within the PFE. Can be used
 *              to measure time since the entry has been used last time.
 * @param[in]   entry The entry
 * @return      TRUE if entry is fresh, FALSE otherwise
 */
__attribute__((pure)) bool_t pfe_l2br_table_entry_is_fresh(const pfe_l2br_table_entry_t *entry)
{
    uint32_t action_data;
    pfe_ct_mac_table_result_t *mac_entry;
    bool_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == entry))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = FALSE;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        action_data = entry->u.mac2f_entry.action_data;
        mac_entry = (pfe_ct_mac_table_result_t *)&action_data;

        if (PFE_L2BR_TABLE_MAC2F == entry->type)
        {
            ret = (0U != mac_entry->item.fresh_flag);
        }
        else
        {
            NXP_LOG_DEBUG("Invalid entry type\n");
            ret = FALSE;
        }
    }
    return ret;
}

/**
 * @brief       Set 'static' bit value
 * @details     Setting the static bit makes the entry static meaning that it is not subject
 *              of aging.
 * @param[in]   entry The entry
 * @param[in]   is_static The 'static' bit value to be set
 * @retval      EOK Success
 * @retval      EINVAL Invalid or missing argument
 * @retval      ENOENT Entry not found
 * @retval      ENOEXEC Command failed
 * @retval      ETIMEDOUT Command timed-out
 */
errno_t pfe_l2br_table_entry_set_static(const pfe_l2br_table_t *l2br, pfe_l2br_table_entry_t *entry, bool_t is_static)
{
    uint32_t action_data;
    pfe_ct_mac_table_result_t *mac_entry = (pfe_ct_mac_table_result_t *)&action_data;
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == l2br) || (NULL == entry)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if ((l2br->type != PFE_L2BR_TABLE_MAC2F) || (entry->type != PFE_L2BR_TABLE_MAC2F))
        {
            /*  Only MAC table entries can be currently 'static' */
            ret = EINVAL;
        }
        else 
        {
            /*  Update the action entry */
            action_data = entry->u.mac2f_entry.action_data;
            mac_entry->item.static_flag = (TRUE == is_static) ? 1U : 0U;
            entry->u.mac2f_entry.action_data = action_data;

            ret = EOK;
        }
    }
    return ret;
}

/**
 * @brief       Get 'static' bit value
 * @details     Static bit indicates that entry is static and is not subject of aging.
 * @param[in]   entry The entry
 * @return      TRUE if entry is fresh, FALSE otherwise
 */
__attribute__((pure)) bool_t pfe_l2br_table_entry_is_static(const pfe_l2br_table_entry_t *entry)
{
    uint32_t action_data = entry->u.mac2f_entry.action_data;
    const pfe_ct_mac_table_result_t *mac_entry = (pfe_ct_mac_table_result_t *)&action_data;
    bool_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == entry))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = FALSE;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (PFE_L2BR_TABLE_MAC2F == entry->type)
        {
            ret = (0U != mac_entry->item.static_flag);
        }
        else
        {
            NXP_LOG_DEBUG("Invalid entry type\n");
            ret = FALSE;
        }
    }
    return ret;
}

#if defined(PFE_CFG_TEXT_STATS)
/**
 * @brief       Convert entry to string representation
 * @param[in]   entry The entry
 * @param[in]   buf Buffer to write the final string to
 * @param[in]   buf_len Buffer length
 */
uint32_t pfe_l2br_table_entry_to_str(const pfe_l2br_table_entry_t *entry, char_t *buf, uint32_t buf_len)
{
    uint32_t len = 0U;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == entry) || (NULL == buf)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return 0U;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    if (PFE_L2BR_TABLE_MAC2F == entry->type)
    {
        len += (uint32_t)snprintf(buf + len, buf_len - len, "[MAC+VLAN Table Entry]\n");
        len += (uint32_t)snprintf(buf + len, buf_len - len, "MAC Address: %02x:%02x:%02x:%02x:%02x:%02x\n",
                entry->u.mac2f_entry.mac[0],
                entry->u.mac2f_entry.mac[1],
                entry->u.mac2f_entry.mac[2],
                entry->u.mac2f_entry.mac[3],
                entry->u.mac2f_entry.mac[4],
                entry->u.mac2f_entry.mac[5]);
        len += (uint32_t)snprintf(buf + len, buf_len - len, "VLAN       : 0x%x\n", entry->u.mac2f_entry.vlan);
        len += (uint32_t)snprintf(buf + len, buf_len - len, "Action Data: 0x%x\n", entry->u.mac2f_entry.action_data);
#if 0
        /* Currently not used - action data stores the port information, FW does not have access to port field */
        len += (uint32_t)snprintf(buf + len, buf_len - len, "Port       : 0x%x\n", entry->u.mac2f_entry.port);
#endif
        len += (uint32_t)snprintf(buf + len, buf_len - len, "Col Ptr    : 0x%x\n", entry->u.mac2f_entry.col_ptr);
        len += (uint32_t)snprintf(buf + len, buf_len - len, "Flags      : 0x%x\n", entry->u.mac2f_entry.flags);
    }
    else if (PFE_L2BR_TABLE_VLAN == entry->type)
    {
        len += (uint32_t)snprintf(buf + len, buf_len - len, "[VLAN Table Entry]\n");
        len += (uint32_t)snprintf(buf + len, buf_len - len, "VLAN       : 0x%x\n", entry->u.vlan_entry.vlan);
        /*  Native type used to fix compiler warning */
        len += (uint32_t)snprintf(buf + len, buf_len - len, "Action Data: 0x%"PRINT64"x\n", (uint64_t)entry->u.vlan_entry.action_data);
#if 0
        /* Currently not used - action data stores the port information, FW does not have access to port field */
        len += (uint32_t)snprintf(buf + len, buf_len - len, "Port       : 0x%x\n", entry->u.vlan_entry.port);
#endif
        len += (uint32_t)snprintf(buf + len, buf_len - len, "Col Ptr    : 0x%x\n", entry->u.vlan_entry.col_ptr);
        len += (uint32_t)snprintf(buf + len, buf_len - len, "Flags      : 0x%x\n", entry->u.vlan_entry.flags);
    }
    else
    {
        len += (uint32_t)snprintf(buf + len, buf_len - len, "Invalid entry type\n");
    }
    return len;
}
#endif /* defined(PFE_CFG_TEXT_STATS) */

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

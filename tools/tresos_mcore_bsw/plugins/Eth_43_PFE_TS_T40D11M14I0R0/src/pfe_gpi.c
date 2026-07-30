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
#define PFE_SRC_VERSION_CHECK 43140440

#include "pfe_cfg.h"
#include "oal.h"
#include "hal.h"

#include "pfe_platform_cfg.h"
#include "pfe_cbus.h"
#include "pfe_gpi.h"
#include "pfe_gpi_csr.h"

/* PFE uses the value of 32 to represent the 6 bit encoding of the IP address mask of 0 */
#define IGQOS_IP_MASK_0 32U

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
static pfe_gpi_t xxgpi_instance[PFE_XXGPI_INSTANCES];
#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#define IGQOS_MAX_PORT_RANGE 0x7FFFU

static errno_t pfe_gpi_null_arg_check_return(const pfe_gpi_t *gpi, errno_t err);
static void igqos_class_clear_active_all(pfe_gpi_t *gpi);
static errno_t igqos_entry_ready_timeout(const pfe_gpi_t *gpi);
static errno_t igqos_class_clear_flow_entry_table(const pfe_gpi_t *gpi);
static errno_t igqos_class_clear_lru_entry_table(const pfe_gpi_t *gpi);
static void igqos_class_set_active(pfe_gpi_t *gpi, uint8_t id);
static void igqos_class_clear_active(pfe_gpi_t *gpi, uint8_t id);
static bool_t igqos_class_is_active(const pfe_gpi_t *gpi, uint8_t id);
static uint8_t igqos_class_find_entry(const pfe_gpi_t *gpi, uint8_t start, bool_t is_active);
static uint8_t igqos_class_find_first_free(const pfe_gpi_t *gpi);
static uint8_t igqos_class_get_first_active(pfe_gpi_t *gpi);
static uint8_t igqos_class_get_next_active(pfe_gpi_t *gpi);
static uint8_t igqos_ip_mask_hw_encode(uint8_t ip_m);
static uint8_t igqos_ip_mask_hw_decode(uint8_t ip_m);
static void igqos_convert_entry_to_flow(const uint32_t entry[], pfe_iqos_flow_spec_t *flow);
static void igqos_convert_flow_to_entry(const pfe_iqos_flow_spec_t *flow, uint32_t entry[]);
static errno_t pfe_gpi_shp_args_checks(const pfe_gpi_t *gpi, uint8_t id);
static uint32_t igqos_clk_div(uint32_t clk_div_log2);
static uint32_t igqos_convert_isl_to_weight(uint32_t isl, uint32_t clk_div_log2, uint32_t sys_clk_mhz, bool_t is_bps);
static uint32_t igqos_convert_weight_to_isl(uint32_t wgt, uint32_t clk_div_log2, uint32_t sys_clk_mhz, bool_t is_bps);
static uint32_t igqos_find_optimal_weight(uint32_t isl, uint32_t sys_clk_mhz, bool_t is_bps, uint32_t *wgt);
static void igqos_convert_flow_to_entry_reg0123(const pfe_iqos_flow_spec_t *flow, uint32_t entry[]);
static void igqos_convert_flow_to_entry_reg45(const pfe_iqos_flow_spec_t *flow, uint32_t entry[]);
static void igqos_flow_entry_fixup(pfe_iqos_flow_spec_t *flow);
static errno_t igqos_flow_entry_validate(const pfe_iqos_flow_spec_t *flow);
static errno_t igqos_flow_entry_validate_args(const pfe_iqos_flow_spec_t *flow);

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================*/
static errno_t pfe_gpi_null_arg_check_return(const pfe_gpi_t *gpi, errno_t err)
{
    errno_t ret = EOK;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == gpi))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = err;
    }
#else
    (void)gpi;
    (void)err;
#endif /* PFE_CFG_NULL_ARG_CHECK */

    return ret;
}

/*==================================================================================================*/
static void igqos_class_clear_active_all(pfe_gpi_t *gpi)
{
    uint32_t i;

    for (i = 0U; i < IGQOS_BITMAP_ARR_SZ; i++)
    {
        gpi->igqos_active_entries[i] = 0;
    }

    gpi->igqos_entry_iter = 0;
}

/*==================================================================================================*/
static errno_t igqos_entry_ready_timeout(const pfe_gpi_t *gpi)
{
    errno_t  ret     = EOK;
    uint32_t timeout = 200U;
    bool_t   ready;

    while (timeout > 0U)
    {
        ready = pfe_gpi_cfg_qos_entry_ready(gpi->gpi_base_va);
        if (TRUE == ready)
        {
            break;
        }
        oal_time_usleep(5U);
        timeout--;
    }

    if ((0U == timeout) && (FALSE == ready))
    {
        ready = pfe_gpi_cfg_qos_entry_ready(gpi->gpi_base_va);
    }

    if (FALSE == ready)
    {
        ret = ETIMEDOUT;
    }

    return ret;
}

/*==================================================================================================*/
static errno_t igqos_class_clear_flow_entry_table(const pfe_gpi_t *gpi)
{
    uint32_t ii;
    errno_t  ret;

    for (ii = 0U; ii < ENTRY_TABLE_SIZE; ii++)
    {
        pfe_gpi_cfg_qos_clear_flow_entry_req(gpi->gpi_base_va, ii);

        ret = igqos_entry_ready_timeout(gpi);
        if (EOK != ret)
        {
            break;
        }
    }

    return ret;
}

/*==================================================================================================*/
static errno_t igqos_class_clear_lru_entry_table(const pfe_gpi_t *gpi)
{
    uint32_t ii;
    errno_t  ret;

    for (ii = 0U; ii < ENTRY_TABLE_SIZE; ii++)
    {
        pfe_gpi_cfg_qos_clear_lru_entry_req(gpi->gpi_base_va, ii);

        ret = igqos_entry_ready_timeout(gpi);
        if (EOK != ret)
        {
            break;
        }
    }

    return ret;
}

/*==================================================================================================*/
static void igqos_class_set_active(pfe_gpi_t *gpi, uint8_t id)
{
    gpi->igqos_active_entries[id / BITMAP_BITS_U32] |= ((uint32_t)1 << (id % BITMAP_BITS_U32));
}

/*==================================================================================================*/
static void igqos_class_clear_active(pfe_gpi_t *gpi, uint8_t id)
{
    gpi->igqos_active_entries[id / BITMAP_BITS_U32] &= (uint32_t)(~((uint32_t)1 << (id % BITMAP_BITS_U32)));
}

/*==================================================================================================*/
static bool_t igqos_class_is_active(const pfe_gpi_t *gpi, uint8_t id)
{
    bool_t ret = TRUE;

    if ((gpi->igqos_active_entries[id / BITMAP_BITS_U32] & ((uint32_t)1 << (id % BITMAP_BITS_U32))) == 0U)
    {
        ret = FALSE;
    }

    return ret;
}

/*==================================================================================================*/
static uint8_t igqos_class_find_entry(const pfe_gpi_t *gpi, uint8_t start, bool_t is_active)
{
    uint8_t ii;
    uint8_t ret;

    if (unlikely(start > PFE_IQOS_FLOW_TABLE_SIZE))
    {
        ret = PFE_IQOS_FLOW_TABLE_SIZE;
    }
    else
    {
        for (ii = start; ii < PFE_IQOS_FLOW_TABLE_SIZE; ii++)
        {
            if (is_active == igqos_class_is_active(gpi, ii))
            {
                break;
            }
        }

        ret = ii; /* returns PFE_IQOS_FLOW_TABLE_SIZE if not found */
    }

    return ret;
}

/*==================================================================================================*/
static uint8_t igqos_class_find_first_free(const pfe_gpi_t *gpi)
{
    return igqos_class_find_entry(gpi, 0, FALSE);
}

/*==================================================================================================*/
static uint8_t igqos_class_get_first_active(pfe_gpi_t *gpi)
{
    gpi->igqos_entry_iter = igqos_class_find_entry(gpi, 0, TRUE);

    return gpi->igqos_entry_iter;
}

/*==================================================================================================*/
static uint8_t igqos_class_get_next_active(pfe_gpi_t *gpi)
{
    PfeDevAssert(gpi->igqos_entry_iter < UINT8_MAX);
    gpi->igqos_entry_iter = igqos_class_find_entry(gpi, gpi->igqos_entry_iter + 1U, TRUE);

    return gpi->igqos_entry_iter;
}

/*==================================================================================================*/
/*
 * convert from the stadard IP address mask encoding to the PFE hardware
 * representation
 */
static uint8_t igqos_ip_mask_hw_encode(uint8_t ip_m)
{
    uint8_t hw_encoded;
    if (0U != ip_m)
    {
        hw_encoded  = ip_m - 1U;
    }
    else
    {
        hw_encoded  = IGQOS_IP_MASK_0;
    }
    return hw_encoded ;
}

/*==================================================================================================*/
static uint8_t igqos_ip_mask_hw_decode(uint8_t ip_m)
{
    uint8_t hw_decoded;
    if (IGQOS_IP_MASK_0 > ip_m)
    {
        hw_decoded = ip_m + 1U;
    }
    else
    {
        hw_decoded = 0U;
    }
    return hw_decoded;
}

/*==================================================================================================*/
static void igqos_convert_entry_to_flow(const uint32_t entry[], pfe_iqos_flow_spec_t *flow)
{
    pfe_iqos_flow_args_t *args = &flow->args;
    uint32_t              val;

    /* entry reg0 */
    val             = entry[0];
    flow->type_mask = (pfe_iqos_flow_type_t)entry_arg_get(TYPE, val);
    args->vlan      = (uint16_t)entry_arg_get(VLAN_ID, val);
    args->tos       = (uint8_t)entry_arg_get(TOS, val);
    args->l4proto   = (uint8_t)entry_arg_get_lower(PROT, val);

    /* entry reg1 */
    val = entry[1];
    args->l4proto |= (uint8_t)(entry_arg_get_upper(PROT, val) & UINT8_MAX);
    args->sip = entry_arg_get_lower(SIP, val);

    /* entry reg2 */
    val = entry[2];
    args->sip |= entry_arg_get_upper(SIP, val);
    args->dip = entry_arg_get_lower(DIP, val);

    /* entry reg3 */
    val = entry[3];
    args->dip |= entry_arg_get_upper(DIP, val);
    args->sport_min = (uint16_t)entry_arg_get(SPORT_MIN, val);
    args->sport_max = (uint16_t)entry_arg_get_lower(SPORT_MAX, val);

    /* entry reg4 */
    val = entry[4];
    args->sport_max |= (uint16_t)entry_arg_get_upper(SPORT_MAX, val);
    args->dport_min = (uint16_t)entry_arg_get(DPORT_MIN, val);
    args->dport_max = (uint16_t)entry_arg_get_lower(DPORT_MAX, val);

    /* entry reg5 */
    val = entry[5];
    args->dport_max |= (uint16_t)entry_arg_get_upper(DPORT_MAX, val);
    args->vlan_m = (uint16_t)entry_arg_get(VLAN_ID_M, val);
    args->tos_m  = (uint8_t)entry_arg_get_lower(TOS_M, val);

    /* entry reg6 */
    val = entry[6];
    args->tos_m |= (uint8_t)entry_arg_get_upper(TOS_M, val);
    args->l4proto_m = (uint8_t)entry_arg_get(PROT_M, val);
    args->sip_m     = igqos_ip_mask_hw_decode((uint8_t)entry_arg_get(SIP_M, val));
    args->dip_m     = igqos_ip_mask_hw_decode((uint8_t)entry_arg_get(DIP_M, val));

    if (entry_arg_get(ACT_DROP, val) == 1U)
    {
        flow->action = PFE_IQOS_FLOW_DROP;
    }

    if (entry_arg_get(ACT_RES, val) == 1U)
    {
        flow->action = PFE_IQOS_FLOW_RESERVED;
    }

    /* revert h/w fixups from returned flow params */
    args->sport_max <<= 1; /* AAVB-5836 */
    args->dport_max <<= 1; /* AAVB-5836 */
}

/*==================================================================================================*/
static bool_t igqos_l4_port_range_is_valid(uint16_t min, uint16_t max)
{
    bool_t ret = TRUE;
    if (min > max)
    {
        ret = FALSE;
    }
    /* AAVB-5836 */
    else if (min > IGQOS_MAX_PORT_RANGE)
    {
        ret = FALSE;
    }
    else
    {
        ret = TRUE;
    }
    /* AAVB-5836 */
    if ((max > (IGQOS_MAX_PORT_RANGE-1U) ) || ((max & 0x1U) == 1U))
    {
        ret = FALSE;
    }
    else
    {
        ret = TRUE;
    }

    return ret;
}

/*==================================================================================================*/
static void igqos_flow_entry_fixup(pfe_iqos_flow_spec_t *flow)
{
    /* PFE_IQOS_ARG_VLAN */
    if (flow->args.vlan_m == 0U)
    {
        /* mask not specified */
        flow->args.vlan_m = PFE_IQOS_VLAN_ID_MASK;
    }

    /* PFE_IQOS_ARG_TOS */
    if (flow->args.tos_m == 0U)
    {
        /* mask not specified */
        flow->args.tos_m = PFE_IQOS_TOS_MASK;
    }

    /* PFE_IQOS_ARG_L4PROTO */
    if (flow->args.l4proto_m == 0U)
    {
        /* mask not specified */
        flow->args.l4proto_m = PFE_IQOS_L4PROTO_MASK;
    }

    /* PFE_IQOS_ARG_SPORT */
    flow->args.sport_max >>= 1;   /* AAVB-5836 */

    /* PFE_IQOS_ARG_DPORT */
    flow->args.dport_max >>= 1;   /* AAVB-5836 */
}

/*==================================================================================================*/
static errno_t igqos_flow_entry_validate_args(const pfe_iqos_flow_spec_t *flow)
{
    const pfe_iqos_flow_args_t *args = &flow->args;
    uint16_t arg_invalid_mask = 0u;

    if ((args->vlan > PFE_IQOS_VLAN_ID_MASK) || (args->vlan_m > PFE_IQOS_VLAN_ID_MASK))
    {
        arg_invalid_mask |= PFE_IQOS_ARG_VLAN;
    }

    if (args->sip_m > PFE_IQOS_SDIP_MASK)
    {
        arg_invalid_mask |= PFE_IQOS_ARG_SIP;
    }

    if (args->dip_m > PFE_IQOS_SDIP_MASK)
    {
        arg_invalid_mask |= PFE_IQOS_ARG_DIP;
    }

    if (!igqos_l4_port_range_is_valid(args->sport_min, args->sport_max)) 
    {
        arg_invalid_mask |= PFE_IQOS_ARG_SPORT;
    }

    if (!igqos_l4_port_range_is_valid(args->dport_min, args->dport_max)) 
    {
        arg_invalid_mask |= PFE_IQOS_ARG_DPORT;
    }

    return (0u != ((uint16_t)flow->arg_type_mask & arg_invalid_mask)) ? EINVAL : EOK;
}

/*==================================================================================================*/
static errno_t igqos_flow_entry_validate(const pfe_iqos_flow_spec_t *flow)
{
    errno_t ret = EINVAL;

    if ((flow->type_mask <= PFE_IQOS_FLOW_TYPE_MAX) &&
        (flow->arg_type_mask <= PFE_IQOS_ARG_MAX) &&
        (flow->action < PFE_IQOS_FLOW_COUNT))
    {
        ret = igqos_flow_entry_validate_args(flow);
    }

    return ret;
}

/*==================================================================================================*/
static void igqos_convert_flow_to_entry_reg0123(const pfe_iqos_flow_spec_t *flow, uint32_t entry[])
{
    const pfe_iqos_flow_args_t *args = &flow->args;
    uint32_t                    val;

    /* entry reg0 */
    val = entry_arg_set(TYPE, (uint32_t)flow->type_mask);
    if (0U != (flow->arg_type_mask & PFE_IQOS_ARG_VLAN))
    {
        val |= entry_arg_set(VLAN_ID, (uint32_t)args->vlan);
    }
    if (0U != (flow->arg_type_mask & PFE_IQOS_ARG_TOS))
    {
        val |= entry_arg_set(TOS, (uint32_t)args->tos);
    }
    if (0U != (flow->arg_type_mask & PFE_IQOS_ARG_L4PROTO))
    {
        val |= entry_arg_set_lower(PROT, (uint32_t)args->l4proto);
    }
    entry[0] = val;

    /* entry reg1 */
    val = 0;
    if (0U != (flow->arg_type_mask & PFE_IQOS_ARG_L4PROTO))
    {
        val |= entry_arg_set_upper(PROT, (uint32_t)args->l4proto);
    }
    if (0U != (flow->arg_type_mask & PFE_IQOS_ARG_SIP))
    {
        val |= entry_arg_set_lower(SIP, args->sip);
    }
    entry[1] = val;

    /* entry reg2 */
    val = 0;
    if (0U != (flow->arg_type_mask & PFE_IQOS_ARG_SIP))
    {
        val |= entry_arg_set_upper(SIP, args->sip);
    }
    if (0U != (flow->arg_type_mask & PFE_IQOS_ARG_DIP))
    {
        val |= entry_arg_set_lower(DIP, args->dip);
    }
    entry[2] = val;

    /* entry reg3 */
    val = 0;
    if (0U != (flow->arg_type_mask & PFE_IQOS_ARG_DIP))
    {
        val |= entry_arg_set_upper(DIP, args->dip);
    }
    if (0U != (flow->arg_type_mask & PFE_IQOS_ARG_SPORT))
    {
        val |= entry_arg_set(SPORT_MIN, (uint32_t)args->sport_min);
        val |= entry_arg_set_lower(SPORT_MAX, (uint32_t)args->sport_max);
    }
    entry[3] = val;
}

/*==================================================================================================*/
static void igqos_convert_flow_to_entry_reg45(const pfe_iqos_flow_spec_t *flow, uint32_t entry[])
{
    uint32_t              val;
    const pfe_iqos_flow_args_t *args = &flow->args;

    /* entry reg4 */
    val = 0;
    if (0U != (flow->arg_type_mask & PFE_IQOS_ARG_SPORT))
    {
        val |= entry_arg_set_upper(SPORT_MAX, (uint32_t)args->sport_max);
    }
    if (0U != (flow->arg_type_mask & PFE_IQOS_ARG_DPORT))
    {
        val |= entry_arg_set(DPORT_MIN, (uint32_t)args->dport_min);
        val |= entry_arg_set_lower(DPORT_MAX, (uint32_t)args->dport_max);
    }
    entry[4] = val;

    /* entry reg5 */
    /* the entry is valid by default */
    val = entry_arg_set(VALID_ENTRY, 1U);
    /* set the same as flow type flags */
    val |= entry_arg_set(TYPE_M, (uint32_t)flow->type_mask);

    if (0U != (flow->arg_type_mask & PFE_IQOS_ARG_DPORT))
    {
        val |= entry_arg_set_upper(DPORT_MAX, (uint32_t)args->dport_max);
    }

    if (0U != (flow->arg_type_mask & PFE_IQOS_ARG_VLAN))
    {
        val |= entry_arg_set(VLAN_ID_M, (uint32_t)args->vlan_m);
    }
    if (0U != (flow->arg_type_mask & PFE_IQOS_ARG_TOS))
    {
        val |= entry_arg_set_lower(TOS_M, (uint32_t)args->tos_m);
    }
    entry[5] = val;
}

/*==================================================================================================*/
static void igqos_convert_flow_to_entry(const pfe_iqos_flow_spec_t *flow, uint32_t entry[])
{
    const pfe_iqos_flow_args_t *args = &flow->args;
    uint32_t                    val;

    /* convert the entry reg 0-3 */
    igqos_convert_flow_to_entry_reg0123(flow, entry);

    /* convert the entry reg 4-5 */
    igqos_convert_flow_to_entry_reg45(flow, entry);

    /* entry reg6 */
    val = 0;
    if (0U != (flow->arg_type_mask & PFE_IQOS_ARG_TOS))
    {
        val |= entry_arg_set_upper(TOS_M, (uint32_t)args->tos_m);
    }
    if (0U != (flow->arg_type_mask & PFE_IQOS_ARG_L4PROTO))
    {
        val |= entry_arg_set(PROT_M, (uint32_t)args->l4proto_m);
    }

    if (0U != (flow->arg_type_mask & PFE_IQOS_ARG_SIP))
    {
        val |= entry_arg_set(SIP_M, (uint32_t)igqos_ip_mask_hw_encode(args->sip_m));
    }
    else
    {
        val |= entry_arg_set(SIP_M, (uint32_t)igqos_ip_mask_hw_encode(0));
    }

    if (0U != (flow->arg_type_mask & PFE_IQOS_ARG_DIP))
    {
        val |= entry_arg_set(DIP_M, (uint32_t)igqos_ip_mask_hw_encode(args->dip_m));
    }
    else
    {
        val |= entry_arg_set(DIP_M, (uint32_t)igqos_ip_mask_hw_encode(0));
    }

    if (0U != (flow->arg_type_mask & PFE_IQOS_ARG_SPORT))
    {
        /* set source port 'mask' to all '1', as not configurable */
        val |= entry_arg_set(SPORT_M, mask32(GPI_QOS_FLOW_SPORT_M_WIDTH));
    }
    if (0U != (flow->arg_type_mask & PFE_IQOS_ARG_DPORT))
    {
        /* set destination port 'mask' to all '1', as not configurable */
        val |= entry_arg_set(DPORT_M, mask32(GPI_QOS_FLOW_DPORT_M_WIDTH));
    }
    if (flow->action == PFE_IQOS_FLOW_DROP)
    {
        val |= entry_arg_set(ACT_DROP, 1U);
    }
    else if (flow->action == PFE_IQOS_FLOW_RESERVED)
    {
        val |= entry_arg_set(ACT_RES, 1U);
    }
    else
    {
        /* Required by Misra */
    }
    entry[6] = val;

    /* entry reg7 - unused */
    entry[7] = 0;
}

/*==================================================================================================*/
/* shaper configuration */
static errno_t pfe_gpi_shp_args_checks(const pfe_gpi_t *gpi, uint8_t id)
{
    errno_t ret = pfe_gpi_null_arg_check_return(gpi, EINVAL);

    if (ret == EOK)
    {
        if (id >= PFE_IQOS_SHP_COUNT)
        {
            ret = EINVAL;
        }
    }

    return ret;
}

/*==================================================================================================*/
static uint32_t igqos_clk_div(uint32_t clk_div_log2)
{
    PfeDevAssert(clk_div_log2 < 31U);
    return ((uint32_t)1U << (clk_div_log2 + 1U));
}

/*==================================================================================================*/
static uint32_t igqos_convert_isl_to_weight(uint32_t isl, uint32_t clk_div_log2, uint32_t sys_clk_mhz, bool_t is_bps)
{
    uint64_t wgt = (uint64_t)isl * igqos_clk_div(clk_div_log2);
    PfeDevAssert(wgt < (1ULL << (64U - IGQOS_PORT_SHP_FRACW_WIDTH)));
    wgt *= (1ULL << IGQOS_PORT_SHP_FRACW_WIDTH);
    wgt /= (uint64_t)sys_clk_mhz * 1000000ULL; /* sys clk in Hz */
    if (TRUE == is_bps)
    {
        wgt /= 8ULL;
    }

    PfeDevAssert(wgt <= UINT32_MAX);
    return (uint32_t)wgt;
}

/*==================================================================================================*/
static uint32_t igqos_convert_weight_to_isl(uint32_t wgt, uint32_t clk_div_log2, uint32_t sys_clk_mhz, bool_t is_bps)
{
    uint64_t clk_div = igqos_clk_div(clk_div_log2);
    uint64_t isl = (uint64_t)wgt;
    if (is_bps)
    {
        isl *= 8ULL;
    }
    PfeDevAssert(isl <= UINT32_MAX);
    PfeDevAssert(sys_clk_mhz <= (UINT32_MAX/1000000UL));
    isl *= (uint64_t)sys_clk_mhz * 1000000ULL; /* sys clk in Hz */
    isl /= (1ULL << IGQOS_PORT_SHP_FRACW_WIDTH);
    isl /= clk_div;

    return (uint32_t)isl;
}

/*==================================================================================================*/
static uint32_t igqos_find_optimal_weight(uint32_t isl, uint32_t sys_clk_mhz, bool_t is_bps, uint32_t *wgt)
{
    const uint32_t w_max = IGQOS_PORT_SHP_WEIGHT_MASK;
    uint32_t       w, l, r, k;
    uint32_t       ret;

    r = IGQOS_PORT_SHP_CLKDIV_MASK; /* max clk_div_log2 value */
    l = 0;                          /* min clk_div_log2 value */

    /* check if 'isl' is out-of-range */
    w = igqos_convert_isl_to_weight(isl, l, sys_clk_mhz, is_bps);
    if (w > w_max)
    {
        NXP_LOG_WARNING("Shaper idle slope too high, weight (%u) exceeds max value\n", (uint_t)w);
        *wgt = w;
        ret  = l;
    }
    else
    {

        w = igqos_convert_isl_to_weight(isl, r, sys_clk_mhz, is_bps);
        if (w == 0U)
        {
            NXP_LOG_WARNING("Shaper idle slope too small, computed weight is 0\n");
            *wgt = w;
            ret  = r;
        }
        else
        {

            if (w <= w_max)
            {
                *wgt = w;
                ret  = r; /* optimum found */
            }
            else
            {

                /* binary search, worst case 4 iterations for r == 15 */
                while (1U < (r-l))
                {
                    k = (l + r) / 2U;
                    w = igqos_convert_isl_to_weight(isl, k, sys_clk_mhz, is_bps);

                    if (w <= w_max)
                    {
                        l = k;
                    }
                    else
                    {
                        r = k;
                    }
                    PfeDevAssert(l <= r);
                }

                k = (l + r) / 2U;

                *wgt = igqos_convert_isl_to_weight(isl, k, sys_clk_mhz, is_bps);
                ret = k;
            }
        }
    }
    return ret;
}

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief       Create new GPI instance
 * @details     Creates and initializes GPI instance. The new instance is disabled and needs
 *              to be enabled by pfe_gpi_enable().
 * @param[in]   cbus_base_va CBUS base virtual address
 * @param[in]   gpi_base BMU base address offset within CBUS address space
 * @param[in]   cfg The BMU block configuration
 * @param[in]   xxgpi_id The ID for GPI instance to be initialized
 * @return      The BMU instance or NULL if failed
 */
pfe_gpi_t *pfe_gpi_create(addr_t cbus_base_va, addr_t gpi_base, const pfe_gpi_cfg_t *cfg, pfe_xxgpi_id_t xxgpi_id)
{
    pfe_gpi_t *gpi;
    errno_t    ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL_ADDR == cbus_base_va) || (NULL == cfg)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        gpi = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (unlikely(PFE_XXGPI_INSTANCES <= xxgpi_id))
        {
            NXP_LOG_ERROR("xxGPI id out of range\n");
            gpi = NULL;
        }
        else
        {
            gpi = &xxgpi_instance[xxgpi_id];
            (void)autolibc_memset(gpi, 0, sizeof(pfe_gpi_t));
            gpi->cbus_base_va    = cbus_base_va;
            gpi->gpi_base_offset = gpi_base;
            gpi->gpi_base_va     = ADDR_BASE_OFFSET(gpi->cbus_base_va, gpi->gpi_base_offset);
            gpi->sys_clk_mhz     = pfe_gpi_cfg_get_sys_clk_mhz(cbus_base_va);

            ret = pfe_gpi_reset(gpi);
            if (EOK != ret)
            {
                gpi = NULL;
            }
            else
            {
                switch (gpi_base)
                {
                    case CBUS_EGPI1_BASE_ADDR:
                    case CBUS_EGPI2_BASE_ADDR:
                    case CBUS_EGPI3_BASE_ADDR:
                        /*
                        * includes initialization of CLASS tables
                        * required by the ECC module init
                        */
                        ret = pfe_gpi_qos_reset(gpi);
                        if (EOK != ret)
                        {
                            NXP_LOG_ERROR("GPI QOS reset timed-out\n");
                            gpi = NULL;
                        }
                        break;
                    default:
                        /* Do Nothing */
                        break;
                }

                if (NULL != gpi)
                {
                    pfe_gpi_disable(gpi);

                    pfe_gpi_cfg_init(gpi->gpi_base_va, cfg);
                }
            }
        }
    }

    return gpi;
}

/**
 * @brief       Reset the GPI block
 * @param[in]   gpi The GPI instance
 */
errno_t pfe_gpi_reset(const pfe_gpi_t *gpi)
{
    errno_t ret = pfe_gpi_null_arg_check_return(gpi, EINVAL);
    if (ret == EOK)
    {
        ret = pfe_gpi_cfg_reset(gpi->gpi_base_va);
        if (EOK != ret)
        {
            NXP_LOG_ERROR("GPI reset timed-out\n");
        }
    }

    return ret;
}

/**
 * @brief       Enable the GPI block
 * @param[in]   gpi The GPI instance
 */
void pfe_gpi_enable(const pfe_gpi_t *gpi)
{
    errno_t ret = pfe_gpi_null_arg_check_return(gpi, EINVAL);
    if (ret == EOK)
    {
        pfe_gpi_cfg_enable(gpi->gpi_base_va);
    }
}

/**
 * @brief       Disable the GPI block
 * @param[in]   gpi The GPI instance
 */
void pfe_gpi_disable(const pfe_gpi_t *gpi)
{
    errno_t ret = pfe_gpi_null_arg_check_return(gpi, EINVAL);
    if (ret == EOK)
    {
        pfe_gpi_cfg_disable(gpi->gpi_base_va);
    }
}

/**
 * @brief       Destroy GPI instance
 * @param[in]   gpi The GPI instance
 */
void pfe_gpi_destroy(pfe_gpi_t *gpi)
{
    errno_t ret;
    if (NULL != gpi)
    {
        pfe_gpi_disable(gpi);

        if ((gpi->gpi_base_offset == CBUS_EGPI1_BASE_ADDR) || (gpi->gpi_base_offset == CBUS_EGPI2_BASE_ADDR) || (gpi->gpi_base_offset == CBUS_EGPI3_BASE_ADDR))
        {
            ret = pfe_gpi_qos_reset(gpi);
            if (EOK != ret)
            {
                NXP_LOG_ERROR("GPI QOS reset timed-out\n");
            }
        }

        ret = pfe_gpi_reset(gpi);
        if (EOK != ret)
        {
            NXP_LOG_ERROR("GPI reset timed-out\n");
        }
    }
}

/*==================================================================================================*/
/* Ingress QoS support */
bool_t pfe_gpi_qos_is_enabled(const pfe_gpi_t *gpi)
{
    bool_t  is_enabled;
    errno_t ret        = pfe_gpi_null_arg_check_return(gpi, EINVAL);

    if (ret == EOK)
    {
        is_enabled = pfe_gpi_cfg_qos_is_enabled(gpi->gpi_base_va);
    }
    else
    {
        is_enabled = FALSE;
    }

    return is_enabled;
}

/*==================================================================================================*/
errno_t pfe_gpi_qos_reset(pfe_gpi_t *gpi)
{
    errno_t ret = pfe_gpi_null_arg_check_return(gpi, EINVAL);
    if (ret == EOK)
    {
        ret = igqos_class_clear_flow_entry_table((const pfe_gpi_t *)gpi);
        if (EOK == ret)
        {
            ret = igqos_class_clear_lru_entry_table((const pfe_gpi_t *)gpi);
            if (EOK == ret)
            {
                pfe_gpi_cfg_qos_default_init(gpi->gpi_base_va);

                /* clear driver state */
                igqos_class_clear_active_all(gpi);
            }
        }
    }

    return ret;
}

/*==================================================================================================*/
errno_t pfe_gpi_qos_enable(pfe_gpi_t *gpi)
{
    errno_t ret = pfe_gpi_null_arg_check_return(gpi, EINVAL);
    if (ret == EOK)
    {
        if (TRUE != pfe_gpi_cfg_qos_is_enabled(gpi->gpi_base_va))
        {
            ret = pfe_gpi_qos_reset(gpi);
            if (EOK == ret)
            {
                pfe_gpi_cfg_qos_enable(gpi->gpi_base_va);
            }
        }
    }

    return ret;
}

/*==================================================================================================*/
errno_t pfe_gpi_qos_disable(const pfe_gpi_t *gpi)
{
    errno_t ret = pfe_gpi_null_arg_check_return(gpi, EINVAL);
    if (ret == EOK)
    {
        pfe_gpi_cfg_qos_disable(gpi->gpi_base_va);
    }

    return ret;
}

/*==================================================================================================*/
errno_t pfe_gpi_qos_get_flow(const pfe_gpi_t *gpi, uint8_t id, pfe_iqos_flow_spec_t *flow)
{
    uint32_t class_table_entry[8] = { 0U };
    errno_t  ret;

    if (id >= PFE_IQOS_FLOW_TABLE_SIZE)
    {
        ret = EINVAL;
    }
    else
    {
        pfe_gpi_cfg_qos_rd_fl_entry_req(gpi->gpi_base_va, id);
        ret = igqos_entry_ready_timeout(gpi);
        if (ret == EOK)
        {
            pfe_gpi_cfg_qos_rd_fl_entry_resp(gpi->gpi_base_va, class_table_entry);
            igqos_convert_entry_to_flow(class_table_entry, flow);
        }
    }

    return ret;
}

/*==================================================================================================*/
errno_t pfe_gpi_qos_rem_flow(pfe_gpi_t *gpi, uint8_t id)
{
    errno_t ret;

    if (id >= PFE_IQOS_FLOW_TABLE_SIZE)
    {
        ret = EINVAL;
    }
    else
    {
        if (igqos_class_is_active(gpi, id))
        {
            pfe_gpi_cfg_qos_clear_flow_entry_req(gpi->gpi_base_va, id);

            ret = igqos_entry_ready_timeout(gpi);
            if (EOK == ret)
            {
                igqos_class_clear_active(gpi, id);
            }
        }
        else
        {
            ret = EINVAL; /* already removed */
        }
    }

    return ret;
}

/*==================================================================================================*/
errno_t pfe_gpi_qos_add_flow(pfe_gpi_t *gpi, uint8_t id, pfe_iqos_flow_spec_t *flow)
{
    uint32_t class_table_entry[8];
    uint8_t  entry_id;
    errno_t  ret;

    if ((id >= PFE_IQOS_FLOW_TABLE_SIZE) && (id != PFE_IQOS_FLOW_TABLE_ENTRY_SKIP))
    {
        ret = EINVAL;
    }
    else if (EOK != igqos_flow_entry_validate(flow))
    {
        ret = EINVAL;
    }
    else
    {
        igqos_flow_entry_fixup(flow);

        if (id == PFE_IQOS_FLOW_TABLE_ENTRY_SKIP)
        {
            entry_id = igqos_class_find_first_free(gpi);
        }
        else
        {
            entry_id = id;
        }

        igqos_convert_flow_to_entry(flow, class_table_entry);

        pfe_gpi_cfg_qos_write_flow_entry_req(gpi->gpi_base_va, entry_id, class_table_entry);

        ret = igqos_entry_ready_timeout(gpi);
        if (EOK == ret)
        {
            igqos_class_set_active(gpi, entry_id);
        }
    }

    return ret;
}

/*==================================================================================================*/
errno_t pfe_gpi_qos_get_first_flow(pfe_gpi_t *gpi, uint8_t *id, pfe_iqos_flow_spec_t *flow)
{
    errno_t ret;
    uint8_t entry_id;

    entry_id = igqos_class_get_first_active(gpi);
    if (entry_id == PFE_IQOS_FLOW_TABLE_SIZE)
    {
        ret = EOVERFLOW;
    }
    else
    {
        *id = entry_id;
        ret = pfe_gpi_qos_get_flow(gpi, entry_id, flow);
    }

    return ret;
}

/*==================================================================================================*/
errno_t pfe_gpi_qos_get_next_flow(pfe_gpi_t *gpi, uint8_t *id, pfe_iqos_flow_spec_t *flow)
{
    errno_t ret;
    uint8_t entry_id;

    entry_id = igqos_class_get_next_active(gpi);
    if (entry_id == PFE_IQOS_FLOW_TABLE_SIZE)
    {
        ret = EOVERFLOW;
    }
    else
    {
        *id = entry_id;
        ret = pfe_gpi_qos_get_flow(gpi, entry_id, flow);
    }

    return ret;
}

/*==================================================================================================*/
/* WRED configuration */
bool_t pfe_gpi_wred_is_enabled(const pfe_gpi_t *gpi, pfe_iqos_queue_t queue)
{
    bool_t  is_enabled;
    errno_t ret = pfe_gpi_null_arg_check_return(gpi, EINVAL);
    if (ret != EOK)
    {
        is_enabled = FALSE;
    }
    else if (queue >= PFE_IQOS_Q_COUNT)
    {
        is_enabled = FALSE;
    }
    else
    {
        is_enabled = pfe_gpi_cfg_wred_is_enabled(gpi->gpi_base_va, queue);
    }

    return is_enabled;
}

/*==================================================================================================*/
errno_t pfe_gpi_wred_enable(const pfe_gpi_t *gpi, pfe_iqos_queue_t queue)
{
    errno_t ret = pfe_gpi_null_arg_check_return(gpi, EINVAL);
    if (ret == EOK)
    {
        if (queue >= PFE_IQOS_Q_COUNT)
        {
            ret = EINVAL;
        }
        else if (TRUE == pfe_gpi_cfg_wred_is_enabled(gpi->gpi_base_va, queue))
        {
            ret = EOK;
        }
        else
        {
            pfe_gpi_cfg_wred_enable(gpi->gpi_base_va, queue);
        }
    }

    return ret;
}

/*==================================================================================================*/
errno_t pfe_gpi_wred_disable(const pfe_gpi_t *gpi, pfe_iqos_queue_t queue)
{
    errno_t ret = pfe_gpi_null_arg_check_return(gpi, EINVAL);
    if (ret == EOK)
    {
        if (queue >= PFE_IQOS_Q_COUNT)
        {
            ret = EINVAL;
        }
        else
        {
            pfe_gpi_cfg_wred_disable(gpi->gpi_base_va, queue);
        }
    }

    return ret;
}

/*==================================================================================================*/
errno_t pfe_gpi_wred_set_prob(const pfe_gpi_t *gpi, pfe_iqos_queue_t queue, pfe_iqos_wred_zone_t zone, uint8_t val)
{
    errno_t ret = pfe_gpi_null_arg_check_return(gpi, EINVAL);
    if (ret == EOK)
    {
        if ((queue >= PFE_IQOS_Q_COUNT) || (zone >= PFE_IQOS_WRED_ZONES_COUNT) || (val > PFE_IQOS_WRED_ZONE_PROB_MAX))
        {
            ret = EINVAL;
        }
        else
        {
            pfe_gpi_cfg_wred_set_prob(gpi->gpi_base_va, queue, zone, val);
        }
    }

    return ret;
}

/*==================================================================================================*/
errno_t pfe_gpi_wred_get_prob(const pfe_gpi_t *gpi, pfe_iqos_queue_t queue, pfe_iqos_wred_zone_t zone, uint8_t *val)
{
    errno_t ret = pfe_gpi_null_arg_check_return(gpi, EINVAL);
    if (ret == EOK)
    {
        if ((queue >= PFE_IQOS_Q_COUNT) || (zone >= PFE_IQOS_WRED_ZONES_COUNT))
        {
            ret = EINVAL;
        }
        else
        {
            pfe_gpi_cfg_wred_get_prob(gpi->gpi_base_va, queue, zone, val);
        }
    }

    return ret;
}

/*==================================================================================================*/
errno_t pfe_gpi_wred_set_thr(const pfe_gpi_t *gpi, pfe_iqos_queue_t queue, pfe_iqos_wred_thr_t thr, uint16_t val)
{
    errno_t ret = pfe_gpi_null_arg_check_return(gpi, EINVAL);

    if (ret == EOK)
    {
        if ((queue >= PFE_IQOS_Q_COUNT) || (thr >= PFE_IQOS_WRED_THR_COUNT))
        {
            ret = EINVAL;
        }
        else if ((queue == PFE_IQOS_Q_DMEM) && (val > PFE_IQOS_WRED_DMEM_THR_MAX))
        {
            ret = EINVAL;
        }
        else if ((queue != PFE_IQOS_Q_DMEM) && (val > PFE_IQOS_WRED_THR_MAX))
        {
            ret = EINVAL;
        }
        else
        {
            pfe_gpi_cfg_wred_set_thr(gpi->gpi_base_va, queue, thr, val);
        }
    }

    return ret;
}

/*==================================================================================================*/
errno_t pfe_gpi_wred_get_thr(const pfe_gpi_t *gpi, pfe_iqos_queue_t queue, pfe_iqos_wred_thr_t thr, uint16_t *val)
{
    errno_t ret = pfe_gpi_null_arg_check_return(gpi, EINVAL);

    if (ret == EOK)
    {
        if ((queue >= PFE_IQOS_Q_COUNT) || (thr >= PFE_IQOS_WRED_THR_COUNT))
        {
            ret = EINVAL;
        }
        else
        {
            pfe_gpi_cfg_wred_get_thr(gpi->gpi_base_va, queue, thr, val);
        }
    }

    return ret;
}

/*==================================================================================================*/
bool_t pfe_gpi_shp_is_enabled(const pfe_gpi_t *gpi, uint8_t id)
{
    bool_t  is_enabled = FALSE;
    errno_t ret        = pfe_gpi_shp_args_checks(gpi, id);

    if (ret == EOK)
    {
        is_enabled = pfe_gpi_cfg_shp_is_enabled(gpi->gpi_base_va, id);
    }

    return is_enabled;
}

/*==================================================================================================*/
errno_t pfe_gpi_shp_enable(pfe_gpi_t *gpi, uint8_t id)
{
    errno_t ret = pfe_gpi_shp_args_checks(gpi, id);

    if (ret == EOK)
    {
        if (TRUE != pfe_gpi_cfg_shp_is_enabled(gpi->gpi_base_va, id))
        {
            gpi->sys_clk_mhz  = pfe_gpi_cfg_get_sys_clk_mhz(gpi->cbus_base_va);
            gpi->clk_div_log2 = 0;
            pfe_gpi_cfg_shp_default_init(gpi->gpi_base_va, id);
            pfe_gpi_cfg_shp_enable(gpi->gpi_base_va, id);
        }
    }

    return ret;
}

/*==================================================================================================*/
errno_t pfe_gpi_shp_disable(const pfe_gpi_t *gpi, uint8_t id)
{
    errno_t ret = pfe_gpi_shp_args_checks(gpi, id);

    if (ret == EOK)
    {
        pfe_gpi_cfg_shp_disable(gpi->gpi_base_va, id);
    }

    return ret;
}

/*==================================================================================================*/
errno_t pfe_gpi_shp_set_mode(const pfe_gpi_t *gpi, uint8_t id, pfe_iqos_shp_rate_mode_t mode)
{
    errno_t ret = pfe_gpi_shp_args_checks(gpi, id);

    if (ret == EOK)
    {
        if (mode >= PFE_IQOS_SHP_RATE_MODE_COUNT)
        {
            ret = EINVAL;
        }
        else
        {
            pfe_gpi_cfg_shp_set_mode(gpi->gpi_base_va, id, mode);
        }
    }

    return ret;
}

/*==================================================================================================*/
errno_t pfe_gpi_shp_get_mode(const pfe_gpi_t *gpi, uint8_t id, pfe_iqos_shp_rate_mode_t *mode)
{
    errno_t ret = pfe_gpi_shp_args_checks(gpi, id);

    if (ret == EOK)
    {
        pfe_gpi_cfg_shp_get_mode(gpi->gpi_base_va, id, mode);
    }

    return ret;
}

/*==================================================================================================*/
errno_t pfe_gpi_shp_set_type(const pfe_gpi_t *gpi, uint8_t id, pfe_iqos_shp_type_t type)
{
    errno_t ret = pfe_gpi_shp_args_checks(gpi, id);

    if (ret == EOK)
    {
        if (type >= PFE_IQOS_SHP_TYPE_COUNT)
        {
            ret = EINVAL;
        }
        else
        {
            pfe_gpi_cfg_shp_set_type(gpi->gpi_base_va, id, type);
        }
    }

    return ret;
}

/*==================================================================================================*/
errno_t pfe_gpi_shp_get_type(const pfe_gpi_t *gpi, uint8_t id, pfe_iqos_shp_type_t *type)
{
    errno_t ret = pfe_gpi_shp_args_checks(gpi, id);

    if (ret == EOK)
    {
        pfe_gpi_cfg_shp_get_type(gpi->gpi_base_va, id, type);
    }

    return ret;
}

/*==================================================================================================*/
errno_t pfe_gpi_shp_set_idle_slope(pfe_gpi_t *gpi, uint8_t id, uint32_t isl)
{
    pfe_iqos_shp_rate_mode_t mode = PFE_IQOS_SHP_BPS;
    uint32_t                 weight = 0U;
    bool_t                   is_bps;
    errno_t                  ret;

    ret = pfe_gpi_shp_args_checks(gpi, id);
    if (ret == EOK)
    {
        NXP_LOG_DEBUG("Shaper#%d - Set idle slope of: %u\n", id, (uint_t)isl);

        pfe_gpi_cfg_shp_get_mode(gpi->gpi_base_va, id, &mode);
        if (mode == PFE_IQOS_SHP_BPS)
        {
            is_bps = TRUE;
        }
        else
        {
            is_bps = FALSE;
        }

        gpi->clk_div_log2 = igqos_find_optimal_weight(isl, gpi->sys_clk_mhz, is_bps, &weight);

        NXP_LOG_DEBUG("Shaper#%d using PFE sys_clk value %u MHz, clkdiv: %u\n", id, (uint_t)(gpi->sys_clk_mhz), (uint_t)igqos_clk_div(gpi->clk_div_log2));
        NXP_LOG_DEBUG("Shaper#%d - Write weight of: %u\n", id, (uint_t)weight);

        pfe_gpi_cfg_shp_set_isl_weight(gpi->gpi_base_va, id, gpi->clk_div_log2, weight);
    }

    return ret;
}

/*==================================================================================================*/
errno_t pfe_gpi_shp_get_idle_slope(const pfe_gpi_t *gpi, uint8_t id, uint32_t *isl)
{
    pfe_iqos_shp_rate_mode_t mode = PFE_IQOS_SHP_BPS;
    uint32_t                 weight = 0U;
    bool_t                   is_bps;
    errno_t                  ret;

    ret = pfe_gpi_shp_args_checks(gpi, id);
    if (ret == EOK)
    {
        pfe_gpi_cfg_shp_get_mode(gpi->gpi_base_va, id, &mode);
        if (mode == PFE_IQOS_SHP_BPS)
        {
            is_bps = TRUE;
        }
        else
        {
            is_bps = FALSE;
        }

        NXP_LOG_DEBUG("Shaper#%d using PFE sys_clk value %u MHz, clkdiv: %u\n", id, (uint_t)(gpi->sys_clk_mhz), (uint_t)igqos_clk_div(gpi->clk_div_log2));

        pfe_gpi_cfg_shp_get_isl_weight(gpi->gpi_base_va, id, &weight);

        *isl = igqos_convert_weight_to_isl(weight, gpi->clk_div_log2, gpi->sys_clk_mhz, is_bps);

        NXP_LOG_DEBUG("Shaper#%d - Get idle slope of: %u\n", id, (uint_t)(*isl));
    }

    return ret;
}

/*==================================================================================================*/
errno_t pfe_gpi_shp_set_limits(const pfe_gpi_t *gpi, uint8_t id, int32_t max_credit, int32_t min_credit)
{
    errno_t ret;

    ret = pfe_gpi_shp_args_checks(gpi, id);
    if (ret == EOK)
    {
        if ((max_credit > IGQOS_PORT_SHP_CREDIT_MAX) || (max_credit < 0))
        {
            NXP_LOG_ERROR("Max credit value exceeded\n");
            ret = EINVAL;
        }
        else if ((min_credit < -IGQOS_PORT_SHP_CREDIT_MAX) || (min_credit > 0))
        {
            NXP_LOG_ERROR("Min credit value exceeded\n");
            ret = EINVAL;
        }
        else
        {
            pfe_gpi_cfg_shp_set_limits(gpi->gpi_base_va, id, (uint32_t)max_credit, (uint32_t)-min_credit);
        }
    }

    return ret;
}

/*==================================================================================================*/
errno_t pfe_gpi_shp_get_limits(const pfe_gpi_t *gpi, uint8_t id, int32_t *max_credit, int32_t *min_credit)
{
    uint32_t abs_max_cred = 0U, abs_min_cred = 0U;
    errno_t  ret;

    ret = pfe_gpi_shp_args_checks(gpi, id);
    if (ret == EOK)
    {
        pfe_gpi_cfg_shp_get_limits(gpi->gpi_base_va, id, &abs_max_cred, &abs_min_cred);
        PfeDevAssert(abs_max_cred <= INT32_MAX);
        PfeDevAssert(abs_min_cred <= INT32_MAX);
        *max_credit = (int32_t)abs_max_cred;
        *min_credit = -(int32_t)abs_min_cred;
    }

    return ret;
}

/*==================================================================================================*/
/* note - the counter is reset to 0 after read (clear on read) */
errno_t pfe_gpi_shp_get_drop_cnt(const pfe_gpi_t *gpi, uint8_t id, uint32_t *cnt)
{
    errno_t ret;

    ret = pfe_gpi_shp_args_checks(gpi, id);
    if (ret == EOK)
    {
        *cnt = pfe_gpi_cfg_shp_get_drop_cnt(gpi->gpi_base_va, id);
    }

    return ret;
}

#if defined(PFE_CFG_TEXT_STATS)
/**
 * @brief       Return GPI runtime statistics in text form
 * @details     Function writes formatted text into given buffer.
 * @param[in]   gpi         The GPI instance
 * @param[in]   buf         Pointer to the buffer to write to
 * @param[in]   buf_len     Buffer length
 * @param[in]   verb_level  Verbosity level
 * @return      Number of bytes written to the buffer
 */
uint32_t pfe_gpi_get_text_statistics(const pfe_gpi_t *gpi, char_t *buf, uint32_t buf_len, uint8_t verb_level)
{
    uint32_t len = 0U;
    errno_t  ret = pfe_gpi_null_arg_check_return(gpi, EINVAL);
    if (ret != EOK)
    {
        len = 0U;
    }
    else
    {
        len += pfe_gpi_cfg_get_text_stat(gpi->gpi_base_va, buf, buf_len, verb_level);
    }

    return len;
}
#endif /* defined(PFE_CFG_TEXT_STATS) */

/**
 * @brief       Get Gpi statistic in numeric form
 * @details     This is a HW-specific function providing single statistic
 *              value from the Gpi block.
 * @param[in]   Gpi        The GPI instance
 * @param[in]   stat_id     ID of required statistic (offset of register)
 * @return      Value of requested statistic
 */
uint32_t pfe_gpi_get_stat_value(const pfe_gpi_t * gpi, uint32_t stat_id)
{
    uint32_t stat_value;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == gpi))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        stat_value = 0xFFFFFFFFU;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        stat_value = pfe_gpi_cfg_get_stat_value(gpi->gpi_base_va, stat_id);
    }
    return stat_value;
}

/**
 * @brief       Get Gpi statistic in numeric form for special registers
 * @details     This is a HW-specific function providing single statistic
 *              value from the gpi block.
 * @param[in]   gpi   The gpi instance
 * @param[out]  special_stats special statistic
 * @return      EOK if possible to get special statistics, otherwise return EINVAL
 *              when gpi or special_stats is NULL 
 */
errno_t pfe_gpi_get_special_stats(const pfe_gpi_t* gpi, pfe_gpi_special_stats_t* special_stats)
{
    errno_t ret = EOK;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == gpi) || unlikely(NULL == special_stats))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_gpi_cfg_get_special_stats(gpi->gpi_base_va, special_stats);
    }

    return ret;
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

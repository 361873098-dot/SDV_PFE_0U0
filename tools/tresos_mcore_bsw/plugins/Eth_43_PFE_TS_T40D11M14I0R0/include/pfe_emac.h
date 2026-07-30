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

#ifndef PUBLIC_PFE_EMAC_H_
#define PUBLIC_PFE_EMAC_H_

/*==================================================================================================
*                                     FILE VERSION CHECK
==================================================================================================*/
#ifdef PFE_SRC_VERSION_CHECK
    #if (PFE_SRC_VERSION_CHECK != 43140440)
        #error "This header file was included from incompatible source file (different SW version)"
    #endif
#else
    #define PFE_SRC_VERSION_CHECK 43140440
#endif

#include "pfe_ct.h"
#include "pfe_gpi.h"
#include "pfe_mac_db.h"
#include "oal.h"

#define PFE_EMAC_INSTANCES 3U

typedef enum
{
    EMAC_MODE_INVALID,
    EMAC_MODE_MII,
    EMAC_MODE_RMII,
    EMAC_MODE_RGMII,
    EMAC_MODE_SGMII
} pfe_emac_mii_mode_t;

typedef enum
{
    EMAC_SPEED_INVALID,
    EMAC_SPEED_10_MBPS,
    EMAC_SPEED_100_MBPS,
    EMAC_SPEED_1000_MBPS,
    EMAC_SPEED_2500_MBPS
} pfe_emac_speed_t;

typedef enum
{
    EMAC_DUPLEX_INVALID,
    EMAC_DUPLEX_HALF,
    EMAC_DUPLEX_FULL
} pfe_emac_duplex_t;

typedef enum
{
    EMAC_LINK_SPEED_INVALID,
    EMAC_LINK_SPEED_2_5_MHZ,
    EMAC_LINK_SPEED_25_MHZ,
    EMAC_LINK_SPEED_125_MHZ
} pfe_emac_link_speed_t;

typedef enum
{
    PFE_FLUSH_MODE_ALL,
    PFE_FLUSH_MODE_UNI,
    PFE_FLUSH_MODE_MULTI
} pfe_flush_mode_t;

typedef struct
{
    addr_t cbus_base_va;            /*  CBUS base virtual address */
    addr_t emac_base_offset;        /*  MAC base offset within CBUS space */
    addr_t emac_base_va;            /*  MAC base address (virtual) */
    pfe_mac_db_t mac_db;            /* MAC database */
    uint8_t mac_addr_slots;     /*  Bitmask representing local address slots where '1' means 'slot is used' */
    pfe_emac_mii_mode_t mode;   /*  Current MII mode */
    pfe_emac_speed_t speed;     /*  Current speed */
    pfe_emac_duplex_t duplex;   /*  Current duplex */
    bool_t mdio_locked;         /*  If TRUE then MDIO access is locked and 'mdio_key' is valid */
    uint32_t mdio_key;
    uint32_t i_clk_hz;          /*  IEEE1588 input clock */
    uint32_t o_clk_hz;          /*  IEEE1588 desired output clock */
    uint32_t adj_ppb;           /*  IEEE1588 frequency adjustment value */
    bool_t adj_sign;            /*  IEEE1588 frequency adjustment sign (TRUE - positive, FALSE - negative) */
    pfe_gpi_t *gpi;             /* gpi handle, to export gpi services for this emac instance */
    pfe_ct_phy_if_id_t emac_id; /* EMAC id */
} pfe_emac_t;

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#if defined(PFE_CFG_TEXT_STATS)
static inline const char_t *
pfe_emac_mii_mode_to_str(pfe_emac_mii_mode_t mode)
{
    const char_t * ret;
    static const char_t * names[] =
        {"Invalid", "MII", "RMII", "RGMII", "SGMII"};

    if (mode <= EMAC_MODE_SGMII)
    {
        ret = names[mode];
    }
    else
    {
        ret = "out-of-range";
    }
    return ret;
}
#endif /* defined(PFE_CFG_TEXT_STATS) */

pfe_emac_t *pfe_emac_create(addr_t cbus_base_va, addr_t emac_base, pfe_emac_mii_mode_t mode, pfe_emac_speed_t speed, pfe_emac_duplex_t duplex);
uint8_t pfe_emac_get_index(const pfe_emac_t *emac);
errno_t pfe_emac_bind_gpi(pfe_emac_t *emac, pfe_gpi_t *gpi);
pfe_gpi_t *pfe_emac_get_gpi(const pfe_emac_t *emac);
void pfe_emac_enable(const pfe_emac_t *emac);
void pfe_emac_disable(const pfe_emac_t *emac);
errno_t pfe_emac_enable_ts(pfe_emac_t *emac, uint32_t i_clk_hz, uint32_t o_clk_hz);
errno_t pfe_emac_set_ts_freq_adjustment(pfe_emac_t *emac, uint32_t ppb, bool_t sgn);
errno_t pfe_emac_get_ts_freq_adjustment(pfe_emac_t *emac, uint32_t *ppb, bool_t *sgn);
errno_t pfe_emac_set_ts_time(pfe_emac_t *emac, uint32_t sec, uint32_t nsec, uint16_t sec_hi);
errno_t pfe_emac_adjust_ts_time(pfe_emac_t *emac, uint32_t sec, uint32_t nsec, bool_t sgn);
errno_t pfe_emac_get_ts_time(pfe_emac_t *emac, uint32_t *sec, uint32_t *nsec, uint16_t *sec_hi);
void pfe_emac_enable_loopback(const pfe_emac_t *emac);
void pfe_emac_disable_loopback(const pfe_emac_t *emac);
void pfe_emac_enable_promisc_mode(const pfe_emac_t *emac);
void pfe_emac_disable_promisc_mode(const pfe_emac_t *emac);
void pfe_emac_enable_allmulti_mode(const pfe_emac_t *emac);
void pfe_emac_disable_allmulti_mode(const pfe_emac_t *emac);
void pfe_emac_enable_broadcast(const pfe_emac_t *emac);
void pfe_emac_disable_broadcast(const pfe_emac_t *emac);
void pfe_emac_enable_tx_flow_control(const pfe_emac_t *emac);
void pfe_emac_disable_tx_flow_control(const pfe_emac_t *emac);
void pfe_emac_enable_rx_flow_control(const pfe_emac_t *emac);
void pfe_emac_disable_rx_flow_control(const pfe_emac_t *emac);
void pfe_emac_get_flow_control(const pfe_emac_t *emac, bool_t *tx_enable, bool_t *rx_enable);
errno_t pfe_emac_set_max_frame_length(const pfe_emac_t *emac, uint32_t len);
pfe_emac_mii_mode_t pfe_emac_get_mii_mode(const pfe_emac_t *emac);
errno_t pfe_emac_get_link_config(const pfe_emac_t *emac, pfe_emac_speed_t *speed, pfe_emac_duplex_t *duplex);
errno_t pfe_emac_get_link_status(const pfe_emac_t *emac, pfe_emac_link_speed_t *link_speed, pfe_emac_duplex_t *duplex, bool_t *link);
errno_t pfe_emac_set_link_speed(const pfe_emac_t *emac, pfe_emac_speed_t link_speed);
errno_t pfe_emac_set_link_duplex(const pfe_emac_t *emac, pfe_emac_duplex_t duplex);
errno_t pfe_emac_mdio_lock(pfe_emac_t *emac, uint32_t *key);
errno_t pfe_emac_mdio_unlock(pfe_emac_t *emac, uint32_t key);
errno_t pfe_emac_mdio_read22(pfe_emac_t *emac, uint8_t pa, uint8_t ra, uint16_t *val, uint32_t key);
errno_t pfe_emac_mdio_write22(pfe_emac_t *emac, uint8_t pa, uint8_t ra, uint16_t val, uint32_t key);
errno_t pfe_emac_mdio_read45(pfe_emac_t *emac, uint8_t pa, uint8_t dev, uint16_t ra, uint16_t *val, uint32_t key);
errno_t pfe_emac_mdio_write45(pfe_emac_t *emac, uint8_t pa, uint8_t dev, uint16_t ra, uint16_t val, uint32_t key);
errno_t pfe_emac_add_addr(pfe_emac_t *emac, const pfe_mac_addr_t addr, pfe_drv_id_t owner);
errno_t pfe_emac_flush_mac_addrs(pfe_emac_t *emac, pfe_mac_db_crit_t crit, pfe_mac_type_t type, pfe_drv_id_t owner);
errno_t pfe_emac_del_addr(pfe_emac_t *emac, const pfe_mac_addr_t addr, pfe_drv_id_t owner);
void pfe_emac_destroy(pfe_emac_t *emac);

#if defined(PFE_CFG_TEXT_STATS)
uint32_t pfe_emac_get_text_statistics(const pfe_emac_t *emac, char_t *buf, uint32_t buf_len, uint8_t verb_level);
#endif /* defined(PFE_CFG_TEXT_STATS) */

uint32_t pfe_emac_get_rx_cnt(const pfe_emac_t *emac);
uint32_t pfe_emac_get_tx_cnt(const pfe_emac_t *emac);
uint32_t pfe_emac_get_stat_value(const pfe_emac_t *emac, uint32_t stat_id);
errno_t pfe_emac_isr(pfe_emac_t *emac);
void pfe_emac_irq_mask(pfe_emac_t *emac);
void pfe_emac_irq_unmask(pfe_emac_t *emac);
errno_t pfe_emac_set_timer_ownership(pfe_emac_t *emac, pfe_drv_id_t drv_id);
errno_t pfe_emac_check_timer_ownership(pfe_emac_t *emac, bool_t *has_owner, pfe_drv_id_t *drv_id);
errno_t pfe_emac_clear_timer_ownership(pfe_emac_t *emac, pfe_drv_id_t drv_id);
errno_t pfe_emac_local_is_timer_owner(pfe_emac_t *emac, bool_t *is_owner);
errno_t pfe_emac_pps0_configure(pfe_emac_t *emac, bool_t enable, uint32_t period, uint32_t pulse_width);

#ifdef PFE_CFG_EMAC0_PPS0_ENABLE
void pfe_emac_pps0_resync(pfe_emac_t *emac);
#endif

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PUBLIC_PFE_EMAC_H_ */

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

#ifndef SRC_PFE_PLATFORM_H_
#define SRC_PFE_PLATFORM_H_

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

#include "pfe_platform_cfg.h"
#include "pfe_gpi.h"
#include "pfe_bmu.h"
#include "pfe_class.h"
#if defined(PFE_CFG_RTABLE_ENABLE)
    #include "pfe_rtable.h"
#endif /* PFE_CFG_RTABLE_ENABLE */
#include "pfe_tmu.h"
#include "pfe_util.h"
#include "pfe_hif.h"
#include "pfe_hif_nocpy.h"
#include "pfe_parity.h"
#include "pfe_emac.h"
#include "pfe_l2br_table.h"
#include "pfe_l2br.h"
#include "pfe_phy_if.h"
#include "pfe_log_if.h"
#include "pfe_if_db.h"
#include "pfe_wdt.h"
#include "pfe_bus_err.h"
#include "pfe_fw_fail_stop.h"
#include "pfe_host_fail_stop.h"
#include "pfe_fail_stop.h"
#include "pfe_ecc_err.h"
#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
#include "fci_ownership_mask.h"
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */

#define GEMAC0_MAC                      { 0x00U, 0x0AU, 0x0BU, 0x0CU, 0x0DU, 0x0EU }
#define GEMAC1_MAC                      { 0x00U, 0x1AU, 0x1BU, 0x1CU, 0x1DU, 0x1EU }
#define GEMAC2_MAC                      { 0x00U, 0x2AU, 0x2BU, 0x2CU, 0x2DU, 0x2EU }

typedef enum
{
    POLLER_STATE_DISABLED,
    POLLER_STATE_ENABLED,
    POLLER_STATE_STOPPED
} pfe_poller_state_t;

typedef struct
/*  The PFE firmware data type */
{
    char_t *version;        /* free text: version */
    char_t *source;         /* free text: filename, filepath, ... etc */
    const void *class_data; /* The CLASS fw data buffer */
    void *tmu_data;         /* The TMU fw data buffer */
    uint32_t tmu_size;      /* The TMU fw data size */
    const void *util_data;  /* The UTIL fw data buffer */
} pfe_fw_t;

/*  The PFE platform config */
typedef struct
{
    addr_t cbus_base;       /* PFE control bus base address */
    addr_t cbus_len;        /* PFE control bus size */
    char_t *fw_name;        /* FW name */
    pfe_fw_t *fw;           /* Required firmware, embedded */
    bool_t common_irq_mode; /* True if FPGA specific common irq is used */
#if (TRUE == PFE_CFG_BMU_IRQ_ENABLED)
    uint32_t irq_vector_bmu;        /* BMU IRQ number */
#endif /* PFE_CFG_BMU_IRQ_ENABLED */
    pfe_hif_chnl_id_t hif_chnls_mask; /* The bitmap list of the requested HIF channels */
#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
    pfe_fci_owner_hif_id_t hif_fci_owner_chnls_mask; /* The bitmap list of HIF channels that are allowed to take FCI ownership */
    pfe_ct_phy_if_id_t master_if; /* Interface where master driver is located */
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */
    uint32_t irq_vector_hif_chnls[HIF_CFG_MAX_CHANNELS];    /* HIF channels IRQ number */
    uint32_t irq_vector_hif_nocpy;  /* HIF nocopy channel IRQ number */
    uint32_t irq_vector_upe_gpt; /* UPE + GPT IRQ number */
    uint32_t irq_vector_safety; /* Safety IRQ number */
    bool_t enable_util;         /* Shall be UTIL enabled? */
    bool_t disable_master_detect;   /* Shall be Master-detect disabled? */
    pfe_ct_phy_if_id_t local_hif; /* ID of the local interface */
#if defined(PFE_CFG_RTABLE_ENABLE)
    uint32_t rtable_hash_size;  /* Size (number of entries) of hash area within routing table */
    uint32_t rtable_collision_size; /* Size (number of entries) of collision area within routing table */
#endif /* PFE_CFG_RTABLE_ENABLE */
    uint16_t vlan_id;   /* VLAN ID used for L2 Bridge configuration */
    uint16_t vlan_stats_size;   /*VLAN stats size(number of vlan entry) used to collect info from firmware */
    pfe_emac_mii_mode_t emac_mode[3]; /* MII mode per PFE EMAC */
    bool_t g2_ordered_class_writes; /* S32G2 ordered class writes switch */
    char_t *commit_hash; /* Driver commit hash */
    char_t *driver_version; /* PFE driver version */
} pfe_platform_config_t;

typedef struct
{
    volatile bool_t probed;
    addr_t cbus_baseaddr;
    void *bmu_buffers_va;
    addr_t bmu_buffers_size;
    void *rtable_va;
    addr_t rtable_size;
    oal_irq_t *irq_global;
    pfe_poller_state_t poller_state;
#if (TRUE == PFE_CFG_BMU_IRQ_ENABLED)
    oal_irq_t *irq_bmu;         /* BMU IRQ */
#endif /* PFE_CFG_BMU_IRQ_ENABLED */
    uint32_t hif_chnl_count;    /* Number of HIF channels */
    pfe_hif_nocpy_t *hif_nocpy; /* The HIF_NOCPY block */
    oal_irq_t *irq_hif_nocpy;   /* HIF nocopy channel IRQ */
    uint32_t emac_count;
    uint32_t gpi_count;
    uint32_t etgpi_count;
    uint32_t hgpi_count;
    uint32_t bmu_count;
    uint32_t class_pe_count;
    uint32_t util_pe_count;
    uint32_t tmu_pe_count;
    pfe_fw_t *fw;
#if defined(PFE_CFG_RTABLE_ENABLE)
    pfe_rtable_t *rtable;
#endif /* PFE_CFG_RTABLE_ENABLE */
#if defined(PFE_CFG_L2BRIDGE_ENABLE)
    pfe_l2br_table_t *mactab;
    pfe_l2br_table_t *vlantab;
#endif /* PFE_CFG_L2BRIDGE_ENABLE */
    pfe_l2br_t *l2_bridge;
    pfe_class_t *classifier;
    pfe_tmu_t *tmu;
    pfe_util_t *util;
    pfe_bmu_t *bmu[PFE_BMU_INSTANCES];
    pfe_gpi_t *gpi[PFE_GPI_INSTANCES];
    pfe_gpi_t *etgpi[PFE_ETGPI_INSTANCES];
    pfe_gpi_t *hgpi[PFE_HGPI_INSTANCES];
    pfe_hif_t *hif;
    pfe_emac_t *emac[PFE_EMAC_INSTANCES];
    pfe_parity_t *parity;
    pfe_wdt_t   *wdt;
    pfe_bus_err_t   *bus_err;
    pfe_fw_fail_stop_t  *fw_fail_stop;
    pfe_host_fail_stop_t    *host_fail_stop;
    pfe_fail_stop_t     *fail_stop;
    pfe_ecc_err_t   *ecc_err;
    pfe_if_db_t *phy_if_db;
#ifdef PFE_CFG_PFE_MASTER
    pfe_if_db_t *log_if_db;
#endif
#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
    pfe_fci_owner_hif_id_t hif_fci_owner_chnls_mask;
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */
    bool_t fci_created;
    uint32_t pfe_version;
} pfe_platform_t;

#ifdef PFE_CFG_PFE_MASTER
#if (TRUE == PFE_CFG_BMU_IRQ_ENABLED)
#define ETH_43_PFE_START_SEC_VAR_INIT_BOOLEAN
#include "Eth_43_PFE_MemMap.h"
extern volatile bool_t bDetectBmuInit;
#define ETH_43_PFE_STOP_SEC_VAR_INIT_BOOLEAN
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_BMU_IRQ_ENABLED */
#endif /* PFE_CFG_PFE_MASTER */

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

pfe_fw_t *pfe_fw_load(char_t *class_fw_name, char_t *util_fw_name);
errno_t pfe_platform_init(const pfe_platform_config_t *config);
errno_t pfe_platform_soft_reset(const pfe_platform_t *platform);
errno_t pfe_platform_remove(void);
pfe_platform_t *pfe_platform_get_instance(void);
pfe_phy_if_t *pfe_platform_get_phy_if_by_id(const pfe_platform_t *platform, pfe_ct_phy_if_id_t id);
#if defined(PFE_CFG_MULTI_INSTANCE_SUPPORT)
void pfe_platform_idex_rpc_cbk(pfe_ct_phy_if_id_t sender, uint32_t id, void *buf, uint16_t buf_len, void *arg);
#endif
errno_t pfe_platform_get_fw_versions(const pfe_platform_t *platform, pfe_ct_version_t *class_fw, pfe_ct_version_t *util_fw);
#ifdef PFE_CFG_PFE_SLAVE
void pfe_platform_destroy_ifaces(void);
#endif
void pfe_platform_remove_sw_if(void);

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* SRC_PFE_PLATFORM_H_ */

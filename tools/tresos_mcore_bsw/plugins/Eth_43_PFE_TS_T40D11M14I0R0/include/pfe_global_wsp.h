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
 *  Copyright 2019-2023 NXP
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

#ifndef PFE_GLOBAL_WSP_CSR_H_
#define PFE_GLOBAL_WSP_CSR_H_

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

#ifndef PFE_CBUS_H_
#error Missing cbus.h
#endif /* PFE_CBUS_H_ */

#define WSP_VERSION             (0x00U)
#define WSP_CLASS_PE_CNT        (0x04U)
#define WSP_PE_IMEM_DMEM_SIZE   (0x08U)
#define WSP_LMEM_SIZE           (0x0cU)
#define WSP_TMU_EMAC_PORT_COUNT (0x10U)
#define WSP_EGPIS_PHY_NO        (0x14U)
#define WSP_HIF_SUPPORT_PHY_NO  (0x18U)
#define WSP_CLASS_HW_SUPPORT    (0x1cU)
#define WSP_SYS_GENERIC_CONTROL (0x20U)
#define WSP_SYS_GENERIC_STATUS  (0x24U)
#define WSP_SYS_GEN_CON0        (0x28U)
#define WSP_SYS_GEN_CON1        (0x2cU)
#define WSP_SYS_GEN_CON2        (0x30U)
#define WSP_SYS_GEN_CON3        (0x34U)
#define WSP_SYS_GEN_CON4        (0x38U)
#define WSP_DBUG_BUS            (0x3cU)
#define WSP_CLK_FRQ             (0x40U)
#define WSP_EMAC_CLASS_CONFIG   (0x44U)
#define WSP_EGPIS_PHY_NO1       (0x48U)
#define WSP_PARITY_INT_SRC      (0x4cU)
#define WSP_PARITY_INT_EN       (0x50U)
#define WDT_INT_EN              (0x54U)

#define CLASS_WDT_INT_EN        (0x58U)
#define UPE_WDT_INT_EN          (0x5cU)
#define HGPI_WDT_INT_EN         (0x60U)
#define HIF_WDT_INT_EN          (0x64U)
#define TLITE_WDT_INT_EN        (0x68U)
#define HNCPY_WDT_INT_EN        (0x6cU)
#define BMU1_WDT_INT_EN         (0x70U)
#define BMU2_WDT_INT_EN         (0x74U)
#define EMAC0_WDT_INT_EN        (0x78U)
#define EMAC1_WDT_INT_EN        (0x7cU)
#define EMAC2_WDT_INT_EN        (0x80U)
#define EXT_GPT_WDT_INT_EN      (0x134U)
#define LMEM_WDT_INT_EN         (0x140U)

#define WDT_INT_SRC             (0x84U)

#define WDT_TIMER_VAL_UPE       (0x88U)
#define WDT_TIMER_VAL_BMU       (0x8cU)
#define WDT_TIMER_VAL_HIF       (0x90U)
#define WDT_TIMER_VAL_TLITE     (0x94U)
#define WSP_DBUG_BUS1           (0x98U)
#define WDT_TIMER_VAL_HIF_NCPY  (0x98U)
#define WDT_TIMER_VAL_CLASS     (0x9cU)
#define WDT_TIMER_VAL_GPI       (0xa0U)
#define WDT_TIMER_VAL_GPT       (0x138U)
#define WDT_TIMER_VAL_LMEM      (0x144U)
#define WDT_TIMER_VAL_ROUTE_LMEM    (0x148U)

#define WSP_DBUG_BUS1_G3        (0xA4U)

#define WSP_FAIL_STOP_MODE_EN   (0xb4U)
#define WSP_FAIL_STOP_MODE_INT_SRC  (0xbcU)
#define WSP_FAIL_STOP_MODE_INT_EN   (0xc0U)
#define WSP_FW_FAIL_STOP_MODE_INT_SRC (0xc8U)
#define WSP_FW_FAIL_STOP_MODE_INT_EN (0xccU)
#define WSP_BUS_ERR_INT_SRC     (0xd0U)
#define WSP_BUS_ERR_INT_EN      (0xd4U)
#define WSP_HOST_FORCE_DEBUG_FAIL_STOP_MODE_INT_SRC (0xe0U)
#define WSP_HOST_FORCE_DEBUG_FAIL_STOP_MODE_INT_EN (0xe4U)
#define WSP_FAILSTOP_INTERRUPT_SOURCE   (0x128U)
#define WSP_ECC_ERR_INT_SRC     (0x12cU)
#define WSP_ECC_ERR_INT_EN      (0x130U)

/* WSP_SYS_GENERIC_CONTROL bits */
#define WSP_SYS_GEN_SOFT_RST_BIT                    (1UL << 30U)

/* WSP_SYS_GENERIC_CONTROL bits (G3) */
#define WSP_SYS_GEN_SOFT_RST_DONE_CLR_BIT_G3        (1UL << 27U)
#define WSP_SYS_GEN_BMU1_SOFT_RST_DONE_CLR_BIT_G3   (1UL << 28U)
#define WSP_SYS_GEN_BMU2_SOFT_RST_DONE_CLR_BIT_G3   (1UL << 29U)
#define WSP_SYS_GEN_SOFT_RST_DONE_CLR_MASK_G3       (WSP_SYS_GEN_SOFT_RST_DONE_CLR_BIT_G3 | WSP_SYS_GEN_BMU1_SOFT_RST_DONE_CLR_BIT_G3 | WSP_SYS_GEN_BMU2_SOFT_RST_DONE_CLR_BIT_G3)

/* WSP_DBUG_BUS1_G3 bits (G3) */
#define WSP_DBUG_BUS1_SOFT_RST_DONE_BIT_G3          (1UL << 19U)
#define WSP_DBUG_BUS1_BMU1_SOFT_RST_DONE_BIT_G3     (1UL << 20U)
#define WSP_DBUG_BUS1_BMU2_SOFT_RST_DONE_BIT_G3     (1UL << 21U)

/* G2 WDT_INT_EN bits */
#define WDT_INT_EN_BIT_G2               (1UL << 0U)
#define WDT_CLASS_WDT_INT_EN_BIT_G2     (1UL << 1U)
#define WDT_UTIL_PE_WDT_INT_EN_BIT_G2   (1UL << 2U)
#define WDT_HIF_GPI_WDT_INT_EN_BIT_G2   (1UL << 3U)
#define WDT_HIF_WDT_INT_EN_BIT_G2       (1UL << 4U)
#define WDT_TLITE_WDT_INT_EN_BIT_G2     (1UL << 5U)
#define WDT_HIF_NOCPY_WDT_INT_EN_BIT_G2 (1UL << 6U)
#define WDT_BMU1_WDT_INT_EN_BIT_G2      (1UL << 7U)
#define WDT_BMU2_WDT_INT_EN_BIT_G2      (1UL << 8U)
#define WDT_EMAC0_GPI_WDT_INT_EN_BIT_G2 (1UL << 9U)
#define WDT_EMAC1_GPI_WDT_INT_EN_BIT_G2 (1UL << 10U)
#define WDT_EMAC2_GPI_WDT_INT_EN_BIT_G2 (1UL << 11U)

/* G2 WDT_INT_SRC bits*/
#define WDT_INT_G2                  (1UL << 0U)
#define WDT_BMU1_WDT_INT_G2         (1UL << 1U)
#define WDT_BMU2_WDT_INT_G2         (1UL << 2U)
#define WDT_CLASS_WDT_INT_G2        (1UL << 3U)
#define WDT_EMAC0_GPI_WDT_INT_G2    (1UL << 4U)
#define WDT_EMAC1_GPI_WDT_INT_G2    (1UL << 5U)
#define WDT_EMAC2_GPI_WDT_INT_G2    (1UL << 6U)
#define WDT_HIF_GPI_WDT_INT_G2      (1UL << 7U)
#define WDT_HIF_NOCPY_WDT_INT_G2    (1UL << 8U)
#define WDT_HIF_WDT_INT_G2          (1UL << 9U)
#define WDT_TLITE_WDT_INT_G2        (1UL << 10U)
#define WDT_UTIL_WDT_INT_G2         (1UL << 11U)

/* G3 WDT_INT_EN bits */
#define WDT_INT_EN_BIT                  (1UL << 0U)
#define WDT_BMU1_WDT_INT_EN_BIT         (1UL << 1U)
#define WDT_BMU2_WDT_INT_EN_BIT         (1UL << 2U)
#define WDT_CLASS_WDT_INT_EN_BIT        (1UL << 3U)
#define WDT_EMAC0_GPI_WDT_INT_EN_BIT    (1UL << 4U)
#define WDT_EMAC1_GPI_WDT_INT_EN_BIT    (1UL << 5U)
#define WDT_EMAC2_GPI_WDT_INT_EN_BIT    (1UL << 6U)
#define WDT_HIF_GPI_WDT_INT_EN_BIT      (1UL << 7U)
#define WDT_HIF_NOCPY_WDT_INT_EN_BIT    (1UL << 8U)
#define WDT_HIF_WDT_INT_EN_BIT          (1UL << 9U)
#define WDT_TLITE_WDT_INT_EN_BIT        (1UL << 10U)
#define WDT_UTIL_PE_WDT_INT_EN_BIT      (1UL << 11U)
#define WDT_EMAC0_ETGPI_WDT_INT_EN_BIT  (1UL << 12U)
#define WDT_EMAC1_ETGPI_WDT_INT_EN_BIT  (1UL << 13U)
#define WDT_EMAC2_ETGPI_WDT_INT_EN_BIT  (1UL << 14U)
#define WDT_EXT_GPT1_WDT_INT_EN_BIT     (1UL << 15U)
#define WDT_EXT_GPT2_WDT_INT_EN_BIT     (1UL << 16U)
#define WDT_LMEM_WDT_INT_EN_BIT         (1UL << 17U)
#define WDT_ROUTE_LMEM_WDT_INT_EN_BIT   (1UL << 18U)

/* G3 WDT_INT_SRC bits*/
#define WDT_INT                 (1UL << 0U)
#define WDT_BMU1_WDT_INT        (1UL << 1U)
#define WDT_BMU2_WDT_INT        (1UL << 2U)
#define WDT_CLASS_WDT_INT       (1UL << 3U)
#define WDT_EMAC0_GPI_WDT_INT   (1UL << 4U)
#define WDT_EMAC1_GPI_WDT_INT   (1UL << 5U)
#define WDT_EMAC2_GPI_WDT_INT   (1UL << 6U)
#define WDT_HIF_GPI_WDT_INT     (1UL << 7U)
#define WDT_HIF_NOCPY_WDT_INT   (1UL << 8U)
#define WDT_HIF_WDT_INT         (1UL << 9U)
#define WDT_TLITE_WDT_INT       (1UL << 10U)
#define WDT_UTIL_PE_WDT_INT     (1UL << 11U)
#define WDT_EMAC0_ETGPI_WDT_INT (1UL << 12U)
#define WDT_EMAC1_ETGPI_WDT_INT (1UL << 13U)
#define WDT_EMAC2_ETGPI_WDT_INT (1UL << 14U)
#define WDT_EXT_GPT1_WDT_INT    (1UL << 15U)
#define WDT_EXT_GPT2_WDT_INT    (1UL << 16U)
#define WDT_LMEM_WDT_INT        (1UL << 17U)
#define WDT_ROUTE_LMEM_WDT_INT  (1UL << 18U)

/* WSP_PARITY_INT_SRC bits*/
#define PARITY_INT              (1UL << 0U)
#define MASTER1_INT             (1UL << 1U)
#define MASTER2_INT             (1UL << 2U)
#define MASTER3_INT             (1UL << 3U)
#define MASTER4_INT             (1UL << 4U)
#define EMAC_CBUS_INT           (1UL << 5U)
#define EMAC_DBUS_INT           (1UL << 6U)
#define CLASS_CBUS_INT          (1UL << 7U)
#define CLASS_DBUS_INT          (1UL << 8U)
#define TMU_CBUS_INT            (1UL << 9U)
#define TMU_DBUS_INT            (1UL << 10U)
#define HIF_CBUS_INT            (1UL << 11U)
#define HIF_DBUS_INT            (1UL << 12U)
#define HIF_NOCPY_CBUS_INT      (1UL << 13U)
#define HIF_NOCPY_DBUS_INT      (1UL << 14U)
#define UPE_CBUS_INT            (1UL << 15U)
#define UPE_DBUS_INT            (1UL << 16U)
#define HRS_CBUS_INT            (1UL << 17U)
#define BRIDGE_CBUS_INT         (1UL << 18U)
#define EMAC_SLV_INT            (1UL << 19U)
#define BMU1_SLV_INT            (1UL << 20U)
#define BMU2_SLV_INT            (1UL << 21U)
#define CLASS_SLV_INT           (1UL << 22U)
#define HIF_SLV_INT             (1UL << 23U)
#define HIF_NOCPY_SLV_INT       (1UL << 24U)
#define LMEM_SLV_INT            (1UL << 25U)
#define TMU_SLV_INT             (1UL << 26U)
#define UPE_SLV_INT             (1UL << 27U)
#define WSP_GLOBAL_SLV_INT      (1UL << 28U)
#define GPT1_SLV_INT            (1UL << 29U)
#define GPT2_SLV_INT            (1UL << 30U)
#define ROUTEMEM_SLV_INT        (1UL << 31U)

/* WSP_PARITY_INT_EN bits*/
#define PARITY_INT_EN           (1UL << 0U)
#define MASTER1_INT_EN          (1UL << 1U)
#define MASTER2_INT_EN          (1UL << 2U)
#define MASTER3_INT_EN          (1UL << 3U)
#define MASTER4_INT_EN          (1UL << 4U)
#define EMAC_CBUS_INT_EN        (1UL << 5U)
#define EMAC_DBUS_INT_EN        (1UL << 6U)
#define CLASS_CBUS_INT_EN       (1UL << 7U)
#define CLASS_DBUS_INT_EN       (1UL << 8U)
#define TMU_CBUS_INT_EN         (1UL << 9U)
#define TMU_DBUS_INT_EN         (1UL << 10U)
#define HIF_CBUS_INT_EN         (1UL << 11U)
#define HIF_DBUS_INT_EN         (1UL << 12U)
#define HIF_NOCPY_CBUS_INT_EN   (1UL << 13U)
#define HIF_NOCPY_DBUS_INT_EN   (1UL << 14U)
#define UPE_CBUS_INT_EN         (1UL << 15U)
#define UPE_DBUS_INT_EN         (1UL << 16U)
#define HRS_CBUS_INT_EN         (1UL << 17U)
#define BRIDGE_CBUS_INT_EN      (1UL << 18U)
#define EMAC_SLV_INT_EN         (1UL << 19U)
#define BMU1_SLV_INT_EN         (1UL << 20U)
#define BMU2_SLV_INT_EN         (1UL << 21U)
#define CLASS_SLV_INT_EN        (1UL << 22U)
#define HIF_SLV_INT_EN          (1UL << 23U)
#define HIF_NOCPY_SLV_INT_EN    (1UL << 24U)
#define LMEM_SLV_INT_EN         (1UL << 25U)
#define TMU_SLV_INT_EN          (1UL << 26U)
#define UPE_SLV_INT_EN          (1UL << 27U)
#define WSP_GLOBAL_SLV_INT_EN   (1UL << 28U)
#define GPT1_SLV_INT_EN         (1UL << 29U)
#define GPT2_SLV_INT_EN         (1UL << 30U)
#define ROUTEMEM_SLV_INT_EN     (1UL << 31U)

#define PARITY_INT_ENABLE_ALL   0xFFFFFFFFU

/* WSP_BUS_ERR_INT_SRC bits*/
#define BUS_ERR_INT             (1UL << 0U)
#define M1_BUS_RD_ERR_INT       (1UL << 1U)
#define M2_BUS_WR_ERR_INT       (1UL << 2U)
#define M3_BUS_WR_ERR_INT       (1UL << 3U)
#define M4_BUS_RD_ERR_INT       (1UL << 4U)
#define HGPI_BUS_RD_ERR_INT     (1UL << 5U)
#define HGPI_BUS_WR_ERR_INT     (1UL << 6U)
#define EGPI0_BUS_RD_ERR_INT    (1UL << 7U)
#define EGPI0_BUS_WR_ERR_INT    (1UL << 8U)
#define EGPI1_BUS_RD_ERR_INT    (1UL << 9U)
#define EGPI1_BUS_WR_ERR_INT    (1UL << 10U)
#define EGPI2_BUS_RD_ERR_INT    (1UL << 11U)
#define EGPI2_BUS_WR_ERR_INT    (1UL << 12U)
#define CLASS_BUS_RD_ERR_INT    (1UL << 13U)
#define CLASS_BUS_WR_ERR_INT    (1UL << 14U)
#define HIF_NOCPY_BUS_RD_ERR_INT    (1UL << 15U)
#define HIF_NOCPY_BUS_WR_ERR_INT    (1UL << 16U)
#define TMU_BUS_RD_ERR_INT      (1UL << 17U)
#define FET_BUS_RD_ERR_INT      (1UL << 18U)
#define UPE_BUS_RD_ERR_INT      (1UL << 19U)
#define UPE_BUS_WR_ERR_INT      (1UL << 20U)

/* WSP_BUS_ERR_INT_EN bits*/
#define BUS_ERR_INT_EN          (1UL << 0U)
#define M1_BUS_RD_ERR_INT_EN    (1UL << 1U)
#define M2_BUS_WR_ERR_INT_EN    (1UL << 2U)
#define M3_BUS_WR_ERR_INT_EN    (1UL << 3U)
#define M4_BUS_RD_ERR_INT_EN    (1UL << 4U)
#define HGPI_BUS_RD_ERR_INT_EN  (1UL << 5U)
#define HGPI_BUS_WR_ERR_INT_EN  (1UL << 6U)
#define EGPI0_BUS_RD_ERR_INT_EN (1UL << 7U)
#define EGPI0_BUS_WR_ERR_INT_EN (1UL << 8U)
#define EGPI1_BUS_RD_ERR_INT_EN (1UL << 9U)
#define EGPI1_BUS_WR_ERR_INT_EN (1UL << 10U)
#define EGPI2_BUS_RD_ERR_INT_EN (1UL << 11U)
#define EGPI2_BUS_WR_ERR_INT_EN (1UL << 12U)
#define CLASS_BUS_RD_ERR_INT_EN (1UL << 13U)
#define CLASS_BUS_WR_ERR_INT_EN (1UL << 14U)
#define HIF_NOCPY_BUS_RD_ERR_INT_EN     (1UL << 15U)
#define HIF_NOCPY_BUS_WR_ERR_INT_EN     (1UL << 16U)
#define TMU_BUS_RD_ERR_INT_EN   (1UL << 17U)
#define FET_BUS_RD_ERR_INT_EN   (1UL << 18U)
#define UPE_BUS_RD_ERR_INT_EN   (1UL << 19U)
#define UPE_BUS_WR_ERR_INT_EN   (1UL << 20U)

#define BUS_ERR_INT_ENABLE_ALL  0x001FFFFFU

/* WSP_FW_FAIL_STOP_MODE_INT_SRC bits*/
#define FW_FAIL_STOP_INT        (1UL << 0U)
#define FW_FAIL_STOP_MODE_INT   (1UL << 1U)

/* WSP_FW_FAIL_STOP_MODE_INT_EN bits*/
#define FW_FAIL_STOP_INT_EN     (1UL << 0U)
#define FW_FAIL_STOP_MODE_INT_EN    (1UL << 1U)

#define FW_FAIL_STOP_INT_ENABLE_ALL 0x00000003U

/* WSP_HOST_FORCE_DEBUG_FAIL_STOP_MODE_INT_SRC bits*/
#define HOST_FORCE_DEBUG_FAIL_STOP_INT  (1UL << 0U)
#define HOST_FORCE_DEBUG_FAIL_STOP_MODE_INT     (1UL << 1U)

/* WSP_HOST_FORCE_DEBUG_FAIL_STOP_MODE_INT_EN bits*/
#define HOST_FORCE_DEBUG_FAIL_STOP_INT_EN   (1UL << 0U)
#define HOST_FORCE_DEBUG_FAIL_STOP_MODE_INT_EN  (1UL << 1U)

#define HOST_FORCE_DEBUG_FAIL_STOP_INT_ENABLE_ALL   0x00000003U

/* WSP_FAIL_STOP_MODE_INT_SRC bits*/
#define FAIL_STOP_INT           (1UL << 0U)
#define FAIL_STOP_MODE_INT      (1UL << 1U)

/* WSP_FAIL_STOP_MODE_INT_EN bits*/
#define FAIL_STOP_INT_EN        (1UL << 0U)
#define FAIL_STOP_MODE_INT_EN   (1UL << 1U)

#define FAIL_STOP_INT_ENABLE_ALL    0x00000003U

/* WSP_FAILSTOP_INTERRUPT_SOURCE bits */
#define PARITY_FS_INTERRUPT     (1UL << 0U)
#define WDT_FS_INTERRUPT        (1UL << 1U)
#define BUS_ERR_FS_INTERRUPT    (1UL << 2U)
#define ECC_FS_INTERRUPT        (1UL << 3U)
#define FW_FAIL_STOP_FS_INTERRUPT   (1UL << 4U)
#define HOST_FORCE_DEBUG_FAIL_STOP_FS_INTERRUPT (1UL << 5U)

#define WSP_FAILSTOP_INTERRUPT_SOURCE_ALL 0x0000003FU

/* WSP_FAIL_STOP_MODE_EN bits */
#define PARITY_FS_INTERRUPT_EN  (1UL << 0U)
#define WDT_FS_INTERRUPT_EN     (1UL << 1U)
#define BUS_ERR_FS_INTERRUPT_EN (1UL << 2U)
#define ECC_FS_INTERRUPT_EN     (1UL << 3U)
#define FW_FAIL_STOP_FS_INTERRUPT_EN    (1UL << 4U)
#define HOST_FORCE_DEBUG_FAIL_STOP_FS_INTERRUPT_EN  (1UL << 5U)

#define WSP_FAIL_STOP_MODE_ENABLE_ALL   0x0000003FU

/* WSP_ECC_ERR_INT_SRC: bits*/
#define ECC_ERR_INT             (1UL << 0U)
#define ECC_MULTI_ERR_INT       (1UL << 1U)

/* WSP_ECC_ERR_INT_EN bits*/
#define ECC_ERR_INT_EN          (1UL << 0U)
#define ECC_MULTI_ERR_INT_EN    (1UL << 1U)

#define ECC_ERR_INT_ENABLE_ALL  0x00000003U

#endif /* PFE_GLOBAL_WSP_CSR_H_ */

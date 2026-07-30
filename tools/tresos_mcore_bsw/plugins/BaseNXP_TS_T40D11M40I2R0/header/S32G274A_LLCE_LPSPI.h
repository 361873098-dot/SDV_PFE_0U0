/*
** ###################################################################
**     Processor:           S32G274A_LLCEM0
**     Compiler:            Keil ARM C/C++ Compiler
**     Reference manual:    LLCESSRM_S32G2xx Rev 3 Draft A
**     Version:             rev. 1.0, 2022-06-09
**     Build:               b220609
**
**     Abstract:
**         Peripheral Access Layer for S32G274A_LLCEM0
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2022 NXP
**
**     NXP Confidential. This software is owned or controlled by NXP and may only be
**     used strictly in accordance with the applicable license terms. By expressly
**     accepting such terms or by downloading, installing, activating and/or otherwise
**     using the software, you are agreeing that you have read, and that you agree to
**     comply with and are bound by, such license terms. If you do not agree to be
**     bound by the applicable license terms, then you may not retain, install,
**     activate or otherwise use the software. The production use license in
**     Section 2.3 is expressly granted for this software.
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
** ###################################################################
*/

/*!
 * @file S32G274A_LLCE_LPSPI.h
 * @version 1.0
 * @date 2022-06-09
 * @brief Peripheral Access Layer for S32G274A_LLCE_LPSPI
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.3, local typedef not referenced
* The SoC header defines typedef for all modules.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, local macro not referenced
* The SoC header defines macros for all modules and registers.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
* These are generated macros used for accessing the bit-fields from registers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 21.1, defined macro '__I' is reserved to the compiler
* This type qualifier is needed to ensure correct I/O access and addressing.
*/

/* Prevention from multiple including the same memory map */
#if !defined(S32G274A_LLCE_LPSPI_H_)  /* Check if memory map has not been already included */
#define S32G274A_LLCE_LPSPI_H_

#include "S32G274A_COMMON.h"

/* ----------------------------------------------------------------------------
   -- LLCE_LPSPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LLCE_LPSPI_Peripheral_Access_Layer LLCE_LPSPI Peripheral Access Layer
 * @{
 */

/** LLCE_LPSPI - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter, offset: 0x4 */
  uint8_t RESERVED_0[8];
  __IO uint32_t CR;                                /**< Control, offset: 0x10 */
  __IO uint32_t SR;                                /**< Status, offset: 0x14 */
  __IO uint32_t IER;                               /**< Interrupt Enable, offset: 0x18 */
  uint8_t RESERVED_1[4];
  __IO uint32_t CFGR0;                             /**< Configuration 0, offset: 0x20 */
  __IO uint32_t CFGR1;                             /**< Configuration 1, offset: 0x24 */
  uint8_t RESERVED_2[8];
  __IO uint32_t DMR0;                              /**< Data Match 0, offset: 0x30 */
  __IO uint32_t DMR1;                              /**< Data Match 1, offset: 0x34 */
  uint8_t RESERVED_3[8];
  __IO uint32_t CCR;                               /**< Clock Configuration, offset: 0x40 */
  uint8_t RESERVED_4[20];
  __IO uint32_t FCR;                               /**< FIFO Control, offset: 0x58 */
  __I  uint32_t FSR;                               /**< FIFO Status, offset: 0x5C */
  __IO uint32_t TCR;                               /**< Transmit Command, offset: 0x60 */
  __O  uint32_t TDR;                               /**< Transmit Data, offset: 0x64 */
  uint8_t RESERVED_5[8];
  __I  uint32_t RSR;                               /**< Receive Status, offset: 0x70 */
  __I  uint32_t RDR;                               /**< Receive Data, offset: 0x74 */
} LLCE_LPSPI_Type, *LLCE_LPSPI_MemMapPtr;

/** Number of instances of the LLCE_LPSPI module. */
#define LLCE_LPSPI_INSTANCE_COUNT                (4u)

/* LLCE_LPSPI - Peripheral instance base addresses */
/** Peripheral LLCE_LPSPI_0 base address */
#define IP_LLCE_LPSPI_0_BASE                     (0x43C00000u)
/** Peripheral LLCE_LPSPI_0 base pointer */
#define IP_LLCE_LPSPI_0                          ((LLCE_LPSPI_Type *)IP_LLCE_LPSPI_0_BASE)
/** Peripheral LLCE_LPSPI_1 base address */
#define IP_LLCE_LPSPI_1_BASE                     (0x43C01000u)
/** Peripheral LLCE_LPSPI_1 base pointer */
#define IP_LLCE_LPSPI_1                          ((LLCE_LPSPI_Type *)IP_LLCE_LPSPI_1_BASE)
/** Peripheral LLCE_LPSPI_2 base address */
#define IP_LLCE_LPSPI_2_BASE                     (0x43C02000u)
/** Peripheral LLCE_LPSPI_2 base pointer */
#define IP_LLCE_LPSPI_2                          ((LLCE_LPSPI_Type *)IP_LLCE_LPSPI_2_BASE)
/** Peripheral LLCE_LPSPI_3 base address */
#define IP_LLCE_LPSPI_3_BASE                     (0x43C03000u)
/** Peripheral LLCE_LPSPI_3 base pointer */
#define IP_LLCE_LPSPI_3                          ((LLCE_LPSPI_Type *)IP_LLCE_LPSPI_3_BASE)
/** Array initializer of LLCE_LPSPI peripheral base addresses */
#define IP_LLCE_LPSPI_BASE_ADDRS                 { IP_LLCE_LPSPI_0_BASE, IP_LLCE_LPSPI_1_BASE, IP_LLCE_LPSPI_2_BASE, IP_LLCE_LPSPI_3_BASE }
/** Array initializer of LLCE_LPSPI peripheral base pointers */
#define IP_LLCE_LPSPI_BASE_PTRS                  { IP_LLCE_LPSPI_0, IP_LLCE_LPSPI_1, IP_LLCE_LPSPI_2, IP_LLCE_LPSPI_3 }

/* ----------------------------------------------------------------------------
   -- LLCE_LPSPI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LLCE_LPSPI_Register_Masks LLCE_LPSPI Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define LLCE_LPSPI_VERID_FEATURE_MASK            (0xFFFFU)
#define LLCE_LPSPI_VERID_FEATURE_SHIFT           (0U)
#define LLCE_LPSPI_VERID_FEATURE_WIDTH           (16U)
#define LLCE_LPSPI_VERID_FEATURE(x)              (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_VERID_FEATURE_SHIFT)) & LLCE_LPSPI_VERID_FEATURE_MASK)

#define LLCE_LPSPI_VERID_MINOR_MASK              (0xFF0000U)
#define LLCE_LPSPI_VERID_MINOR_SHIFT             (16U)
#define LLCE_LPSPI_VERID_MINOR_WIDTH             (8U)
#define LLCE_LPSPI_VERID_MINOR(x)                (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_VERID_MINOR_SHIFT)) & LLCE_LPSPI_VERID_MINOR_MASK)

#define LLCE_LPSPI_VERID_MAJOR_MASK              (0xFF000000U)
#define LLCE_LPSPI_VERID_MAJOR_SHIFT             (24U)
#define LLCE_LPSPI_VERID_MAJOR_WIDTH             (8U)
#define LLCE_LPSPI_VERID_MAJOR(x)                (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_VERID_MAJOR_SHIFT)) & LLCE_LPSPI_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter */
/*! @{ */

#define LLCE_LPSPI_PARAM_TXFIFO_MASK             (0xFFU)
#define LLCE_LPSPI_PARAM_TXFIFO_SHIFT            (0U)
#define LLCE_LPSPI_PARAM_TXFIFO_WIDTH            (8U)
#define LLCE_LPSPI_PARAM_TXFIFO(x)               (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_PARAM_TXFIFO_SHIFT)) & LLCE_LPSPI_PARAM_TXFIFO_MASK)

#define LLCE_LPSPI_PARAM_RXFIFO_MASK             (0xFF00U)
#define LLCE_LPSPI_PARAM_RXFIFO_SHIFT            (8U)
#define LLCE_LPSPI_PARAM_RXFIFO_WIDTH            (8U)
#define LLCE_LPSPI_PARAM_RXFIFO(x)               (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_PARAM_RXFIFO_SHIFT)) & LLCE_LPSPI_PARAM_RXFIFO_MASK)

#define LLCE_LPSPI_PARAM_PCSNUM_MASK             (0xFF0000U)
#define LLCE_LPSPI_PARAM_PCSNUM_SHIFT            (16U)
#define LLCE_LPSPI_PARAM_PCSNUM_WIDTH            (8U)
#define LLCE_LPSPI_PARAM_PCSNUM(x)               (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_PARAM_PCSNUM_SHIFT)) & LLCE_LPSPI_PARAM_PCSNUM_MASK)
/*! @} */

/*! @name CR - Control */
/*! @{ */

#define LLCE_LPSPI_CR_MEN_MASK                   (0x1U)
#define LLCE_LPSPI_CR_MEN_SHIFT                  (0U)
#define LLCE_LPSPI_CR_MEN_WIDTH                  (1U)
#define LLCE_LPSPI_CR_MEN(x)                     (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_CR_MEN_SHIFT)) & LLCE_LPSPI_CR_MEN_MASK)

#define LLCE_LPSPI_CR_RST_MASK                   (0x2U)
#define LLCE_LPSPI_CR_RST_SHIFT                  (1U)
#define LLCE_LPSPI_CR_RST_WIDTH                  (1U)
#define LLCE_LPSPI_CR_RST(x)                     (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_CR_RST_SHIFT)) & LLCE_LPSPI_CR_RST_MASK)

#define LLCE_LPSPI_CR_DBGEN_MASK                 (0x8U)
#define LLCE_LPSPI_CR_DBGEN_SHIFT                (3U)
#define LLCE_LPSPI_CR_DBGEN_WIDTH                (1U)
#define LLCE_LPSPI_CR_DBGEN(x)                   (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_CR_DBGEN_SHIFT)) & LLCE_LPSPI_CR_DBGEN_MASK)

#define LLCE_LPSPI_CR_RTF_MASK                   (0x100U)
#define LLCE_LPSPI_CR_RTF_SHIFT                  (8U)
#define LLCE_LPSPI_CR_RTF_WIDTH                  (1U)
#define LLCE_LPSPI_CR_RTF(x)                     (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_CR_RTF_SHIFT)) & LLCE_LPSPI_CR_RTF_MASK)

#define LLCE_LPSPI_CR_RRF_MASK                   (0x200U)
#define LLCE_LPSPI_CR_RRF_SHIFT                  (9U)
#define LLCE_LPSPI_CR_RRF_WIDTH                  (1U)
#define LLCE_LPSPI_CR_RRF(x)                     (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_CR_RRF_SHIFT)) & LLCE_LPSPI_CR_RRF_MASK)
/*! @} */

/*! @name SR - Status */
/*! @{ */

#define LLCE_LPSPI_SR_TDF_MASK                   (0x1U)
#define LLCE_LPSPI_SR_TDF_SHIFT                  (0U)
#define LLCE_LPSPI_SR_TDF_WIDTH                  (1U)
#define LLCE_LPSPI_SR_TDF(x)                     (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_SR_TDF_SHIFT)) & LLCE_LPSPI_SR_TDF_MASK)

#define LLCE_LPSPI_SR_RDF_MASK                   (0x2U)
#define LLCE_LPSPI_SR_RDF_SHIFT                  (1U)
#define LLCE_LPSPI_SR_RDF_WIDTH                  (1U)
#define LLCE_LPSPI_SR_RDF(x)                     (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_SR_RDF_SHIFT)) & LLCE_LPSPI_SR_RDF_MASK)

#define LLCE_LPSPI_SR_WCF_MASK                   (0x100U)
#define LLCE_LPSPI_SR_WCF_SHIFT                  (8U)
#define LLCE_LPSPI_SR_WCF_WIDTH                  (1U)
#define LLCE_LPSPI_SR_WCF(x)                     (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_SR_WCF_SHIFT)) & LLCE_LPSPI_SR_WCF_MASK)

#define LLCE_LPSPI_SR_FCF_MASK                   (0x200U)
#define LLCE_LPSPI_SR_FCF_SHIFT                  (9U)
#define LLCE_LPSPI_SR_FCF_WIDTH                  (1U)
#define LLCE_LPSPI_SR_FCF(x)                     (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_SR_FCF_SHIFT)) & LLCE_LPSPI_SR_FCF_MASK)

#define LLCE_LPSPI_SR_TCF_MASK                   (0x400U)
#define LLCE_LPSPI_SR_TCF_SHIFT                  (10U)
#define LLCE_LPSPI_SR_TCF_WIDTH                  (1U)
#define LLCE_LPSPI_SR_TCF(x)                     (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_SR_TCF_SHIFT)) & LLCE_LPSPI_SR_TCF_MASK)

#define LLCE_LPSPI_SR_TEF_MASK                   (0x800U)
#define LLCE_LPSPI_SR_TEF_SHIFT                  (11U)
#define LLCE_LPSPI_SR_TEF_WIDTH                  (1U)
#define LLCE_LPSPI_SR_TEF(x)                     (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_SR_TEF_SHIFT)) & LLCE_LPSPI_SR_TEF_MASK)

#define LLCE_LPSPI_SR_REF_MASK                   (0x1000U)
#define LLCE_LPSPI_SR_REF_SHIFT                  (12U)
#define LLCE_LPSPI_SR_REF_WIDTH                  (1U)
#define LLCE_LPSPI_SR_REF(x)                     (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_SR_REF_SHIFT)) & LLCE_LPSPI_SR_REF_MASK)

#define LLCE_LPSPI_SR_DMF_MASK                   (0x2000U)
#define LLCE_LPSPI_SR_DMF_SHIFT                  (13U)
#define LLCE_LPSPI_SR_DMF_WIDTH                  (1U)
#define LLCE_LPSPI_SR_DMF(x)                     (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_SR_DMF_SHIFT)) & LLCE_LPSPI_SR_DMF_MASK)

#define LLCE_LPSPI_SR_MBF_MASK                   (0x1000000U)
#define LLCE_LPSPI_SR_MBF_SHIFT                  (24U)
#define LLCE_LPSPI_SR_MBF_WIDTH                  (1U)
#define LLCE_LPSPI_SR_MBF(x)                     (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_SR_MBF_SHIFT)) & LLCE_LPSPI_SR_MBF_MASK)
/*! @} */

/*! @name IER - Interrupt Enable */
/*! @{ */

#define LLCE_LPSPI_IER_TDIE_MASK                 (0x1U)
#define LLCE_LPSPI_IER_TDIE_SHIFT                (0U)
#define LLCE_LPSPI_IER_TDIE_WIDTH                (1U)
#define LLCE_LPSPI_IER_TDIE(x)                   (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_IER_TDIE_SHIFT)) & LLCE_LPSPI_IER_TDIE_MASK)

#define LLCE_LPSPI_IER_RDIE_MASK                 (0x2U)
#define LLCE_LPSPI_IER_RDIE_SHIFT                (1U)
#define LLCE_LPSPI_IER_RDIE_WIDTH                (1U)
#define LLCE_LPSPI_IER_RDIE(x)                   (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_IER_RDIE_SHIFT)) & LLCE_LPSPI_IER_RDIE_MASK)

#define LLCE_LPSPI_IER_WCIE_MASK                 (0x100U)
#define LLCE_LPSPI_IER_WCIE_SHIFT                (8U)
#define LLCE_LPSPI_IER_WCIE_WIDTH                (1U)
#define LLCE_LPSPI_IER_WCIE(x)                   (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_IER_WCIE_SHIFT)) & LLCE_LPSPI_IER_WCIE_MASK)

#define LLCE_LPSPI_IER_FCIE_MASK                 (0x200U)
#define LLCE_LPSPI_IER_FCIE_SHIFT                (9U)
#define LLCE_LPSPI_IER_FCIE_WIDTH                (1U)
#define LLCE_LPSPI_IER_FCIE(x)                   (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_IER_FCIE_SHIFT)) & LLCE_LPSPI_IER_FCIE_MASK)

#define LLCE_LPSPI_IER_TCIE_MASK                 (0x400U)
#define LLCE_LPSPI_IER_TCIE_SHIFT                (10U)
#define LLCE_LPSPI_IER_TCIE_WIDTH                (1U)
#define LLCE_LPSPI_IER_TCIE(x)                   (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_IER_TCIE_SHIFT)) & LLCE_LPSPI_IER_TCIE_MASK)

#define LLCE_LPSPI_IER_TEIE_MASK                 (0x800U)
#define LLCE_LPSPI_IER_TEIE_SHIFT                (11U)
#define LLCE_LPSPI_IER_TEIE_WIDTH                (1U)
#define LLCE_LPSPI_IER_TEIE(x)                   (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_IER_TEIE_SHIFT)) & LLCE_LPSPI_IER_TEIE_MASK)

#define LLCE_LPSPI_IER_REIE_MASK                 (0x1000U)
#define LLCE_LPSPI_IER_REIE_SHIFT                (12U)
#define LLCE_LPSPI_IER_REIE_WIDTH                (1U)
#define LLCE_LPSPI_IER_REIE(x)                   (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_IER_REIE_SHIFT)) & LLCE_LPSPI_IER_REIE_MASK)

#define LLCE_LPSPI_IER_DMIE_MASK                 (0x2000U)
#define LLCE_LPSPI_IER_DMIE_SHIFT                (13U)
#define LLCE_LPSPI_IER_DMIE_WIDTH                (1U)
#define LLCE_LPSPI_IER_DMIE(x)                   (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_IER_DMIE_SHIFT)) & LLCE_LPSPI_IER_DMIE_MASK)
/*! @} */

/*! @name CFGR0 - Configuration 0 */
/*! @{ */

#define LLCE_LPSPI_CFGR0_HREN_MASK               (0x1U)
#define LLCE_LPSPI_CFGR0_HREN_SHIFT              (0U)
#define LLCE_LPSPI_CFGR0_HREN_WIDTH              (1U)
#define LLCE_LPSPI_CFGR0_HREN(x)                 (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_CFGR0_HREN_SHIFT)) & LLCE_LPSPI_CFGR0_HREN_MASK)

#define LLCE_LPSPI_CFGR0_HRPOL_MASK              (0x2U)
#define LLCE_LPSPI_CFGR0_HRPOL_SHIFT             (1U)
#define LLCE_LPSPI_CFGR0_HRPOL_WIDTH             (1U)
#define LLCE_LPSPI_CFGR0_HRPOL(x)                (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_CFGR0_HRPOL_SHIFT)) & LLCE_LPSPI_CFGR0_HRPOL_MASK)

#define LLCE_LPSPI_CFGR0_HRSEL_MASK              (0x4U)
#define LLCE_LPSPI_CFGR0_HRSEL_SHIFT             (2U)
#define LLCE_LPSPI_CFGR0_HRSEL_WIDTH             (1U)
#define LLCE_LPSPI_CFGR0_HRSEL(x)                (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_CFGR0_HRSEL_SHIFT)) & LLCE_LPSPI_CFGR0_HRSEL_MASK)

#define LLCE_LPSPI_CFGR0_CIRFIFO_MASK            (0x100U)
#define LLCE_LPSPI_CFGR0_CIRFIFO_SHIFT           (8U)
#define LLCE_LPSPI_CFGR0_CIRFIFO_WIDTH           (1U)
#define LLCE_LPSPI_CFGR0_CIRFIFO(x)              (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_CFGR0_CIRFIFO_SHIFT)) & LLCE_LPSPI_CFGR0_CIRFIFO_MASK)

#define LLCE_LPSPI_CFGR0_RDMO_MASK               (0x200U)
#define LLCE_LPSPI_CFGR0_RDMO_SHIFT              (9U)
#define LLCE_LPSPI_CFGR0_RDMO_WIDTH              (1U)
#define LLCE_LPSPI_CFGR0_RDMO(x)                 (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_CFGR0_RDMO_SHIFT)) & LLCE_LPSPI_CFGR0_RDMO_MASK)
/*! @} */

/*! @name CFGR1 - Configuration 1 */
/*! @{ */

#define LLCE_LPSPI_CFGR1_MASTER_MASK             (0x1U)
#define LLCE_LPSPI_CFGR1_MASTER_SHIFT            (0U)
#define LLCE_LPSPI_CFGR1_MASTER_WIDTH            (1U)
#define LLCE_LPSPI_CFGR1_MASTER(x)               (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_CFGR1_MASTER_SHIFT)) & LLCE_LPSPI_CFGR1_MASTER_MASK)

#define LLCE_LPSPI_CFGR1_SAMPLE_MASK             (0x2U)
#define LLCE_LPSPI_CFGR1_SAMPLE_SHIFT            (1U)
#define LLCE_LPSPI_CFGR1_SAMPLE_WIDTH            (1U)
#define LLCE_LPSPI_CFGR1_SAMPLE(x)               (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_CFGR1_SAMPLE_SHIFT)) & LLCE_LPSPI_CFGR1_SAMPLE_MASK)

#define LLCE_LPSPI_CFGR1_AUTOPCS_MASK            (0x4U)
#define LLCE_LPSPI_CFGR1_AUTOPCS_SHIFT           (2U)
#define LLCE_LPSPI_CFGR1_AUTOPCS_WIDTH           (1U)
#define LLCE_LPSPI_CFGR1_AUTOPCS(x)              (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_CFGR1_AUTOPCS_SHIFT)) & LLCE_LPSPI_CFGR1_AUTOPCS_MASK)

#define LLCE_LPSPI_CFGR1_NOSTALL_MASK            (0x8U)
#define LLCE_LPSPI_CFGR1_NOSTALL_SHIFT           (3U)
#define LLCE_LPSPI_CFGR1_NOSTALL_WIDTH           (1U)
#define LLCE_LPSPI_CFGR1_NOSTALL(x)              (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_CFGR1_NOSTALL_SHIFT)) & LLCE_LPSPI_CFGR1_NOSTALL_MASK)

#define LLCE_LPSPI_CFGR1_PCSPOL_MASK             (0xF00U)
#define LLCE_LPSPI_CFGR1_PCSPOL_SHIFT            (8U)
#define LLCE_LPSPI_CFGR1_PCSPOL_WIDTH            (4U)
#define LLCE_LPSPI_CFGR1_PCSPOL(x)               (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_CFGR1_PCSPOL_SHIFT)) & LLCE_LPSPI_CFGR1_PCSPOL_MASK)

#define LLCE_LPSPI_CFGR1_MATCFG_MASK             (0x70000U)
#define LLCE_LPSPI_CFGR1_MATCFG_SHIFT            (16U)
#define LLCE_LPSPI_CFGR1_MATCFG_WIDTH            (3U)
#define LLCE_LPSPI_CFGR1_MATCFG(x)               (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_CFGR1_MATCFG_SHIFT)) & LLCE_LPSPI_CFGR1_MATCFG_MASK)

#define LLCE_LPSPI_CFGR1_PINCFG_MASK             (0x3000000U)
#define LLCE_LPSPI_CFGR1_PINCFG_SHIFT            (24U)
#define LLCE_LPSPI_CFGR1_PINCFG_WIDTH            (2U)
#define LLCE_LPSPI_CFGR1_PINCFG(x)               (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_CFGR1_PINCFG_SHIFT)) & LLCE_LPSPI_CFGR1_PINCFG_MASK)

#define LLCE_LPSPI_CFGR1_OUTCFG_MASK             (0x4000000U)
#define LLCE_LPSPI_CFGR1_OUTCFG_SHIFT            (26U)
#define LLCE_LPSPI_CFGR1_OUTCFG_WIDTH            (1U)
#define LLCE_LPSPI_CFGR1_OUTCFG(x)               (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_CFGR1_OUTCFG_SHIFT)) & LLCE_LPSPI_CFGR1_OUTCFG_MASK)

#define LLCE_LPSPI_CFGR1_PCSCFG_MASK             (0x8000000U)
#define LLCE_LPSPI_CFGR1_PCSCFG_SHIFT            (27U)
#define LLCE_LPSPI_CFGR1_PCSCFG_WIDTH            (1U)
#define LLCE_LPSPI_CFGR1_PCSCFG(x)               (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_CFGR1_PCSCFG_SHIFT)) & LLCE_LPSPI_CFGR1_PCSCFG_MASK)
/*! @} */

/*! @name DMR0 - Data Match 0 */
/*! @{ */

#define LLCE_LPSPI_DMR0_MATCH0_MASK              (0xFFFFFFFFU)
#define LLCE_LPSPI_DMR0_MATCH0_SHIFT             (0U)
#define LLCE_LPSPI_DMR0_MATCH0_WIDTH             (32U)
#define LLCE_LPSPI_DMR0_MATCH0(x)                (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_DMR0_MATCH0_SHIFT)) & LLCE_LPSPI_DMR0_MATCH0_MASK)
/*! @} */

/*! @name DMR1 - Data Match 1 */
/*! @{ */

#define LLCE_LPSPI_DMR1_MATCH1_MASK              (0xFFFFFFFFU)
#define LLCE_LPSPI_DMR1_MATCH1_SHIFT             (0U)
#define LLCE_LPSPI_DMR1_MATCH1_WIDTH             (32U)
#define LLCE_LPSPI_DMR1_MATCH1(x)                (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_DMR1_MATCH1_SHIFT)) & LLCE_LPSPI_DMR1_MATCH1_MASK)
/*! @} */

/*! @name CCR - Clock Configuration */
/*! @{ */

#define LLCE_LPSPI_CCR_SCKDIV_MASK               (0xFFU)
#define LLCE_LPSPI_CCR_SCKDIV_SHIFT              (0U)
#define LLCE_LPSPI_CCR_SCKDIV_WIDTH              (8U)
#define LLCE_LPSPI_CCR_SCKDIV(x)                 (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_CCR_SCKDIV_SHIFT)) & LLCE_LPSPI_CCR_SCKDIV_MASK)

#define LLCE_LPSPI_CCR_DBT_MASK                  (0xFF00U)
#define LLCE_LPSPI_CCR_DBT_SHIFT                 (8U)
#define LLCE_LPSPI_CCR_DBT_WIDTH                 (8U)
#define LLCE_LPSPI_CCR_DBT(x)                    (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_CCR_DBT_SHIFT)) & LLCE_LPSPI_CCR_DBT_MASK)

#define LLCE_LPSPI_CCR_PCSSCK_MASK               (0xFF0000U)
#define LLCE_LPSPI_CCR_PCSSCK_SHIFT              (16U)
#define LLCE_LPSPI_CCR_PCSSCK_WIDTH              (8U)
#define LLCE_LPSPI_CCR_PCSSCK(x)                 (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_CCR_PCSSCK_SHIFT)) & LLCE_LPSPI_CCR_PCSSCK_MASK)

#define LLCE_LPSPI_CCR_SCKPCS_MASK               (0xFF000000U)
#define LLCE_LPSPI_CCR_SCKPCS_SHIFT              (24U)
#define LLCE_LPSPI_CCR_SCKPCS_WIDTH              (8U)
#define LLCE_LPSPI_CCR_SCKPCS(x)                 (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_CCR_SCKPCS_SHIFT)) & LLCE_LPSPI_CCR_SCKPCS_MASK)
/*! @} */

/*! @name FCR - FIFO Control */
/*! @{ */

#define LLCE_LPSPI_FCR_TXWATER_MASK              (0x3U)
#define LLCE_LPSPI_FCR_TXWATER_SHIFT             (0U)
#define LLCE_LPSPI_FCR_TXWATER_WIDTH             (2U)
#define LLCE_LPSPI_FCR_TXWATER(x)                (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_FCR_TXWATER_SHIFT)) & LLCE_LPSPI_FCR_TXWATER_MASK)

#define LLCE_LPSPI_FCR_RXWATER_MASK              (0x30000U)
#define LLCE_LPSPI_FCR_RXWATER_SHIFT             (16U)
#define LLCE_LPSPI_FCR_RXWATER_WIDTH             (2U)
#define LLCE_LPSPI_FCR_RXWATER(x)                (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_FCR_RXWATER_SHIFT)) & LLCE_LPSPI_FCR_RXWATER_MASK)
/*! @} */

/*! @name FSR - FIFO Status */
/*! @{ */

#define LLCE_LPSPI_FSR_TXCOUNT_MASK              (0x7U)
#define LLCE_LPSPI_FSR_TXCOUNT_SHIFT             (0U)
#define LLCE_LPSPI_FSR_TXCOUNT_WIDTH             (3U)
#define LLCE_LPSPI_FSR_TXCOUNT(x)                (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_FSR_TXCOUNT_SHIFT)) & LLCE_LPSPI_FSR_TXCOUNT_MASK)

#define LLCE_LPSPI_FSR_RXCOUNT_MASK              (0x70000U)
#define LLCE_LPSPI_FSR_RXCOUNT_SHIFT             (16U)
#define LLCE_LPSPI_FSR_RXCOUNT_WIDTH             (3U)
#define LLCE_LPSPI_FSR_RXCOUNT(x)                (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_FSR_RXCOUNT_SHIFT)) & LLCE_LPSPI_FSR_RXCOUNT_MASK)
/*! @} */

/*! @name TCR - Transmit Command */
/*! @{ */

#define LLCE_LPSPI_TCR_FRAMESZ_MASK              (0xFFFU)
#define LLCE_LPSPI_TCR_FRAMESZ_SHIFT             (0U)
#define LLCE_LPSPI_TCR_FRAMESZ_WIDTH             (12U)
#define LLCE_LPSPI_TCR_FRAMESZ(x)                (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_TCR_FRAMESZ_SHIFT)) & LLCE_LPSPI_TCR_FRAMESZ_MASK)

#define LLCE_LPSPI_TCR_WIDTH_MASK                (0x30000U)
#define LLCE_LPSPI_TCR_WIDTH_SHIFT               (16U)
#define LLCE_LPSPI_TCR_WIDTH_WIDTH               (2U)
#define LLCE_LPSPI_TCR_WIDTH(x)                  (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_TCR_WIDTH_SHIFT)) & LLCE_LPSPI_TCR_WIDTH_MASK)

#define LLCE_LPSPI_TCR_TXMSK_MASK                (0x40000U)
#define LLCE_LPSPI_TCR_TXMSK_SHIFT               (18U)
#define LLCE_LPSPI_TCR_TXMSK_WIDTH               (1U)
#define LLCE_LPSPI_TCR_TXMSK(x)                  (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_TCR_TXMSK_SHIFT)) & LLCE_LPSPI_TCR_TXMSK_MASK)

#define LLCE_LPSPI_TCR_RXMSK_MASK                (0x80000U)
#define LLCE_LPSPI_TCR_RXMSK_SHIFT               (19U)
#define LLCE_LPSPI_TCR_RXMSK_WIDTH               (1U)
#define LLCE_LPSPI_TCR_RXMSK(x)                  (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_TCR_RXMSK_SHIFT)) & LLCE_LPSPI_TCR_RXMSK_MASK)

#define LLCE_LPSPI_TCR_CONTC_MASK                (0x100000U)
#define LLCE_LPSPI_TCR_CONTC_SHIFT               (20U)
#define LLCE_LPSPI_TCR_CONTC_WIDTH               (1U)
#define LLCE_LPSPI_TCR_CONTC(x)                  (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_TCR_CONTC_SHIFT)) & LLCE_LPSPI_TCR_CONTC_MASK)

#define LLCE_LPSPI_TCR_CONT_MASK                 (0x200000U)
#define LLCE_LPSPI_TCR_CONT_SHIFT                (21U)
#define LLCE_LPSPI_TCR_CONT_WIDTH                (1U)
#define LLCE_LPSPI_TCR_CONT(x)                   (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_TCR_CONT_SHIFT)) & LLCE_LPSPI_TCR_CONT_MASK)

#define LLCE_LPSPI_TCR_BYSW_MASK                 (0x400000U)
#define LLCE_LPSPI_TCR_BYSW_SHIFT                (22U)
#define LLCE_LPSPI_TCR_BYSW_WIDTH                (1U)
#define LLCE_LPSPI_TCR_BYSW(x)                   (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_TCR_BYSW_SHIFT)) & LLCE_LPSPI_TCR_BYSW_MASK)

#define LLCE_LPSPI_TCR_LSBF_MASK                 (0x800000U)
#define LLCE_LPSPI_TCR_LSBF_SHIFT                (23U)
#define LLCE_LPSPI_TCR_LSBF_WIDTH                (1U)
#define LLCE_LPSPI_TCR_LSBF(x)                   (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_TCR_LSBF_SHIFT)) & LLCE_LPSPI_TCR_LSBF_MASK)

#define LLCE_LPSPI_TCR_PCS_MASK                  (0x3000000U)
#define LLCE_LPSPI_TCR_PCS_SHIFT                 (24U)
#define LLCE_LPSPI_TCR_PCS_WIDTH                 (2U)
#define LLCE_LPSPI_TCR_PCS(x)                    (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_TCR_PCS_SHIFT)) & LLCE_LPSPI_TCR_PCS_MASK)

#define LLCE_LPSPI_TCR_PRESCALE_MASK             (0x38000000U)
#define LLCE_LPSPI_TCR_PRESCALE_SHIFT            (27U)
#define LLCE_LPSPI_TCR_PRESCALE_WIDTH            (3U)
#define LLCE_LPSPI_TCR_PRESCALE(x)               (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_TCR_PRESCALE_SHIFT)) & LLCE_LPSPI_TCR_PRESCALE_MASK)

#define LLCE_LPSPI_TCR_CPHA_MASK                 (0x40000000U)
#define LLCE_LPSPI_TCR_CPHA_SHIFT                (30U)
#define LLCE_LPSPI_TCR_CPHA_WIDTH                (1U)
#define LLCE_LPSPI_TCR_CPHA(x)                   (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_TCR_CPHA_SHIFT)) & LLCE_LPSPI_TCR_CPHA_MASK)

#define LLCE_LPSPI_TCR_CPOL_MASK                 (0x80000000U)
#define LLCE_LPSPI_TCR_CPOL_SHIFT                (31U)
#define LLCE_LPSPI_TCR_CPOL_WIDTH                (1U)
#define LLCE_LPSPI_TCR_CPOL(x)                   (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_TCR_CPOL_SHIFT)) & LLCE_LPSPI_TCR_CPOL_MASK)
/*! @} */

/*! @name TDR - Transmit Data */
/*! @{ */

#define LLCE_LPSPI_TDR_DATA_MASK                 (0xFFFFFFFFU)
#define LLCE_LPSPI_TDR_DATA_SHIFT                (0U)
#define LLCE_LPSPI_TDR_DATA_WIDTH                (32U)
#define LLCE_LPSPI_TDR_DATA(x)                   (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_TDR_DATA_SHIFT)) & LLCE_LPSPI_TDR_DATA_MASK)
/*! @} */

/*! @name RSR - Receive Status */
/*! @{ */

#define LLCE_LPSPI_RSR_SOF_MASK                  (0x1U)
#define LLCE_LPSPI_RSR_SOF_SHIFT                 (0U)
#define LLCE_LPSPI_RSR_SOF_WIDTH                 (1U)
#define LLCE_LPSPI_RSR_SOF(x)                    (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_RSR_SOF_SHIFT)) & LLCE_LPSPI_RSR_SOF_MASK)

#define LLCE_LPSPI_RSR_RXEMPTY_MASK              (0x2U)
#define LLCE_LPSPI_RSR_RXEMPTY_SHIFT             (1U)
#define LLCE_LPSPI_RSR_RXEMPTY_WIDTH             (1U)
#define LLCE_LPSPI_RSR_RXEMPTY(x)                (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_RSR_RXEMPTY_SHIFT)) & LLCE_LPSPI_RSR_RXEMPTY_MASK)
/*! @} */

/*! @name RDR - Receive Data */
/*! @{ */

#define LLCE_LPSPI_RDR_DATA_MASK                 (0xFFFFFFFFU)
#define LLCE_LPSPI_RDR_DATA_SHIFT                (0U)
#define LLCE_LPSPI_RDR_DATA_WIDTH                (32U)
#define LLCE_LPSPI_RDR_DATA(x)                   (((uint32_t)(((uint32_t)(x)) << LLCE_LPSPI_RDR_DATA_SHIFT)) & LLCE_LPSPI_RDR_DATA_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group LLCE_LPSPI_Register_Masks */

/*!
 * @}
 */ /* end of group LLCE_LPSPI_Peripheral_Access_Layer */

#endif  /* #if !defined(S32G274A_LLCE_LPSPI_H_) */

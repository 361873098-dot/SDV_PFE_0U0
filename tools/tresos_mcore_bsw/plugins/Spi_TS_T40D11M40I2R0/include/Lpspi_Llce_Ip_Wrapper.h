/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : DSPI
*   Dependencies         : 
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
*   (c) Copyright 2020-2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef LPSPI_LLCE_IP_WRAPPER_H
#define LPSPI_LLCE_IP_WRAPPER_H

/**
*   @file    Lpspi_Llce_Ip_Wrapper_Types.h
*
*   @brief   LPSPI IP driver types header file.
*   @details LPSPI IP driver types header file.

*   @addtogroup LPSPI_DRIVER Lpspi Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPSPI_LLCE_IP_WRAPPER_TYPES_VENDOR_ID                    43
#define LPSPI_LLCE_IP_WRAPPER_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define LPSPI_LLCE_IP_WRAPPER_TYPES_AR_RELEASE_MINOR_VERSION     4
#define LPSPI_LLCE_IP_WRAPPER_TYPES_AR_RELEASE_REVISION_VERSION  0
#define LPSPI_LLCE_IP_WRAPPER_TYPES_SW_MAJOR_VERSION             4
#define LPSPI_LLCE_IP_WRAPPER_TYPES_SW_MINOR_VERSION             0
#define LPSPI_LLCE_IP_WRAPPER_TYPES_SW_PATCH_VERSION             2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
typedef LLCE_LPSPI_Type LPSPI_Type;

/** Number of instances of the LLCE_LPSPI module. */
#define LPSPI_INSTANCE_COUNT                LLCE_LPSPI_INSTANCE_COUNT

/* LLCE_LPSPI - Peripheral instance base addresses */
/** Peripheral LLCE_LPSPI_0 base address */
#define IP_LPSPI_0_BASE                     IP_LLCE_LPSPI_0_BASE
/** Peripheral LLCE_LPSPI_0 base pointer */
#define IP_LPSPI_0                          IP_LLCE_LPSPI_0
/** Peripheral LLCE_LPSPI_1 base address */
#define IP_LPSPI_1_BASE                     IP_LLCE_LPSPI_1_BASE
/** Peripheral LLCE_LPSPI_1 base pointer */
#define IP_LPSPI_1                          IP_LLCE_LPSPI_1
/** Peripheral LLCE_LPSPI_2 base address */
#define IP_LPSPI_2_BASE                     IP_LLCE_LPSPI_2_BASE
/** Peripheral LLCE_LPSPI_2 base pointer */
#define IP_LPSPI_2                          IP_LLCE_LPSPI_2
/** Peripheral LLCE_LPSPI_3 base address */
#define IP_LPSPI_3_BASE                     IP_LLCE_LPSPI_3_BASE
/** Peripheral LLCE_LPSPI_3 base pointer */
#define IP_LPSPI_3                          IP_LLCE_LPSPI_3
/** Array initializer of LLCE_LPSPI peripheral base addresses */
#define IP_LPSPI_BASE_ADDRS                 IP_LLCE_LPSPI_BASE_ADDRS
/** Array initializer of LLCE_LPSPI peripheral base pointers */
#define IP_LPSPI_BASE_PTRS                  IP_LLCE_LPSPI_BASE_PTRS

#define LPSPI_VERID_FEATURE_MASK            LLCE_LPSPI_VERID_FEATURE_MASK 
#define LPSPI_VERID_FEATURE_SHIFT           LLCE_LPSPI_VERID_FEATURE_SHIFT
#define LPSPI_VERID_FEATURE_WIDTH           LLCE_LPSPI_VERID_FEATURE_WIDTH
#define LPSPI_VERID_FEATURE(x)              LLCE_LPSPI_VERID_FEATURE(x)   

#define LPSPI_VERID_MINOR_MASK              LLCE_LPSPI_VERID_MINOR_MASK 
#define LPSPI_VERID_MINOR_SHIFT             LLCE_LPSPI_VERID_MINOR_SHIFT
#define LPSPI_VERID_MINOR_WIDTH             LLCE_LPSPI_VERID_MINOR_WIDTH
#define LPSPI_VERID_MINOR(x)                LLCE_LPSPI_VERID_MINOR(x)   

#define LPSPI_VERID_MAJOR_MASK              LLCE_LPSPI_VERID_MAJOR_MASK 
#define LPSPI_VERID_MAJOR_SHIFT             LLCE_LPSPI_VERID_MAJOR_SHIFT
#define LPSPI_VERID_MAJOR_WIDTH             LLCE_LPSPI_VERID_MAJOR_WIDTH
#define LPSPI_VERID_MAJOR(x)                LLCE_LPSPI_VERID_MAJOR(x)   
/*! @} */

/*! @name PARAM - Parameter */
/*! @{ */

#define LPSPI_PARAM_TXFIFO_MASK             LLCE_LPSPI_PARAM_TXFIFO_MASK 
#define LPSPI_PARAM_TXFIFO_SHIFT            LLCE_LPSPI_PARAM_TXFIFO_SHIFT
#define LPSPI_PARAM_TXFIFO_WIDTH            LLCE_LPSPI_PARAM_TXFIFO_WIDTH
#define LPSPI_PARAM_TXFIFO(x)               LLCE_LPSPI_PARAM_TXFIFO(x)   

#define LPSPI_PARAM_RXFIFO_MASK             LLCE_LPSPI_PARAM_RXFIFO_MASK 
#define LPSPI_PARAM_RXFIFO_SHIFT            LLCE_LPSPI_PARAM_RXFIFO_SHIFT
#define LPSPI_PARAM_RXFIFO_WIDTH            LLCE_LPSPI_PARAM_RXFIFO_WIDTH
#define LPSPI_PARAM_RXFIFO(x)               LLCE_LPSPI_PARAM_RXFIFO(x) 
  
#define LPSPI_PARAM_PCSNUM_MASK             LLCE_LPSPI_PARAM_PCSNUM_MASK 
#define LPSPI_PARAM_PCSNUM_SHIFT            LLCE_LPSPI_PARAM_PCSNUM_SHIFT
#define LPSPI_PARAM_PCSNUM_WIDTH            LLCE_LPSPI_PARAM_PCSNUM_WIDTH
#define LPSPI_PARAM_PCSNUM(x)               LLCE_LPSPI_PARAM_PCSNUM(x)   
/*! @} */

/*! @name CR - Control */
/*! @{ */

#define LPSPI_CR_MEN_MASK                   LLCE_LPSPI_CR_MEN_MASK   
#define LPSPI_CR_MEN_SHIFT                  LLCE_LPSPI_CR_MEN_SHIFT  
#define LPSPI_CR_MEN_WIDTH                  LLCE_LPSPI_CR_MEN_WIDTH  
#define LPSPI_CR_MEN(x)                     LLCE_LPSPI_CR_MEN(x)     
#define LPSPI_CR_RST_MASK                   LLCE_LPSPI_CR_RST_MASK   
#define LPSPI_CR_RST_SHIFT                  LLCE_LPSPI_CR_RST_SHIFT  
#define LPSPI_CR_RST_WIDTH                  LLCE_LPSPI_CR_RST_WIDTH  
#define LPSPI_CR_RST(x)                     LLCE_LPSPI_CR_RST(x)     
#define LPSPI_CR_DBGEN_MASK                 LLCE_LPSPI_CR_DBGEN_MASK 
#define LPSPI_CR_DBGEN_SHIFT                LLCE_LPSPI_CR_DBGEN_SHIFT
#define LPSPI_CR_DBGEN_WIDTH                LLCE_LPSPI_CR_DBGEN_WIDTH
#define LPSPI_CR_DBGEN(x)                   LLCE_LPSPI_CR_DBGEN(x)   
#define LPSPI_CR_RTF_MASK                   LLCE_LPSPI_CR_RTF_MASK   
#define LPSPI_CR_RTF_SHIFT                  LLCE_LPSPI_CR_RTF_SHIFT  
#define LPSPI_CR_RTF_WIDTH                  LLCE_LPSPI_CR_RTF_WIDTH  
#define LPSPI_CR_RTF(x)                     LLCE_LPSPI_CR_RTF(x)     
#define LPSPI_CR_RRF_MASK                   LLCE_LPSPI_CR_RRF_MASK   
#define LPSPI_CR_RRF_SHIFT                  LLCE_LPSPI_CR_RRF_SHIFT  
#define LPSPI_CR_RRF_WIDTH                  LLCE_LPSPI_CR_RRF_WIDTH  
#define LPSPI_CR_RRF(x)                     LLCE_LPSPI_CR_RRF(x)     
/*! @} */

/*! @name SR - Status */
/*! @{ */

#define LPSPI_SR_TDF_MASK                   LLCE_LPSPI_SR_TDF_MASK 
#define LPSPI_SR_TDF_SHIFT                  LLCE_LPSPI_SR_TDF_SHIFT
#define LPSPI_SR_TDF_WIDTH                  LLCE_LPSPI_SR_TDF_WIDTH
#define LPSPI_SR_TDF(x)                     LLCE_LPSPI_SR_TDF(x)   
#define LPSPI_SR_RDF_MASK                   LLCE_LPSPI_SR_RDF_MASK 
#define LPSPI_SR_RDF_SHIFT                  LLCE_LPSPI_SR_RDF_SHIFT
#define LPSPI_SR_RDF_WIDTH                  LLCE_LPSPI_SR_RDF_WIDTH
#define LPSPI_SR_RDF(x)                     LLCE_LPSPI_SR_RDF(x)   
#define LPSPI_SR_WCF_MASK                   LLCE_LPSPI_SR_WCF_MASK 
#define LPSPI_SR_WCF_SHIFT                  LLCE_LPSPI_SR_WCF_SHIFT
#define LPSPI_SR_WCF_WIDTH                  LLCE_LPSPI_SR_WCF_WIDTH
#define LPSPI_SR_WCF(x)                     LLCE_LPSPI_SR_WCF(x)   
#define LPSPI_SR_FCF_MASK                   LLCE_LPSPI_SR_FCF_MASK 
#define LPSPI_SR_FCF_SHIFT                  LLCE_LPSPI_SR_FCF_SHIFT
#define LPSPI_SR_FCF_WIDTH                  LLCE_LPSPI_SR_FCF_WIDTH
#define LPSPI_SR_FCF(x)                     LLCE_LPSPI_SR_FCF(x)   
#define LPSPI_SR_TCF_MASK                   LLCE_LPSPI_SR_TCF_MASK 
#define LPSPI_SR_TCF_SHIFT                  LLCE_LPSPI_SR_TCF_SHIFT
#define LPSPI_SR_TCF_WIDTH                  LLCE_LPSPI_SR_TCF_WIDTH
#define LPSPI_SR_TCF(x)                     LLCE_LPSPI_SR_TCF(x)   
#define LPSPI_SR_TEF_MASK                   LLCE_LPSPI_SR_TEF_MASK 
#define LPSPI_SR_TEF_SHIFT                  LLCE_LPSPI_SR_TEF_SHIFT
#define LPSPI_SR_TEF_WIDTH                  LLCE_LPSPI_SR_TEF_WIDTH
#define LPSPI_SR_TEF(x)                     LLCE_LPSPI_SR_TEF(x)   
#define LPSPI_SR_REF_MASK                   LLCE_LPSPI_SR_REF_MASK 
#define LPSPI_SR_REF_SHIFT                  LLCE_LPSPI_SR_REF_SHIFT
#define LPSPI_SR_REF_WIDTH                  LLCE_LPSPI_SR_REF_WIDTH
#define LPSPI_SR_REF(x)                     LLCE_LPSPI_SR_REF(x)   
#define LPSPI_SR_DMF_MASK                   LLCE_LPSPI_SR_DMF_MASK 
#define LPSPI_SR_DMF_SHIFT                  LLCE_LPSPI_SR_DMF_SHIFT
#define LPSPI_SR_DMF_WIDTH                  LLCE_LPSPI_SR_DMF_WIDTH
#define LPSPI_SR_DMF(x)                     LLCE_LPSPI_SR_DMF(x)   
#define LPSPI_SR_MBF_MASK                   LLCE_LPSPI_SR_MBF_MASK 
#define LPSPI_SR_MBF_SHIFT                  LLCE_LPSPI_SR_MBF_SHIFT
#define LPSPI_SR_MBF_WIDTH                  LLCE_LPSPI_SR_MBF_WIDTH
#define LPSPI_SR_MBF(x)                     LLCE_LPSPI_SR_MBF(x)   
/*! @} */

/*! @name IER - Interrupt Enable */
/*! @{ */

#define LPSPI_IER_TDIE_MASK                 LLCE_LPSPI_IER_TDIE_MASK 
#define LPSPI_IER_TDIE_SHIFT                LLCE_LPSPI_IER_TDIE_SHIFT
#define LPSPI_IER_TDIE_WIDTH                LLCE_LPSPI_IER_TDIE_WIDTH
#define LPSPI_IER_TDIE(x)                   LLCE_LPSPI_IER_TDIE(x)   
#define LPSPI_IER_RDIE_MASK                 LLCE_LPSPI_IER_RDIE_MASK 
#define LPSPI_IER_RDIE_SHIFT                LLCE_LPSPI_IER_RDIE_SHIFT
#define LPSPI_IER_RDIE_WIDTH                LLCE_LPSPI_IER_RDIE_WIDTH
#define LPSPI_IER_RDIE(x)                   LLCE_LPSPI_IER_RDIE(x)   
#define LPSPI_IER_WCIE_MASK                 LLCE_LPSPI_IER_WCIE_MASK 
#define LPSPI_IER_WCIE_SHIFT                LLCE_LPSPI_IER_WCIE_SHIFT
#define LPSPI_IER_WCIE_WIDTH                LLCE_LPSPI_IER_WCIE_WIDTH
#define LPSPI_IER_WCIE(x)                   LLCE_LPSPI_IER_WCIE(x)   
#define LPSPI_IER_FCIE_MASK                 LLCE_LPSPI_IER_FCIE_MASK 
#define LPSPI_IER_FCIE_SHIFT                LLCE_LPSPI_IER_FCIE_SHIFT
#define LPSPI_IER_FCIE_WIDTH                LLCE_LPSPI_IER_FCIE_WIDTH
#define LPSPI_IER_FCIE(x)                   LLCE_LPSPI_IER_FCIE(x)   
#define LPSPI_IER_TCIE_MASK                 LLCE_LPSPI_IER_TCIE_MASK 
#define LPSPI_IER_TCIE_SHIFT                LLCE_LPSPI_IER_TCIE_SHIFT
#define LPSPI_IER_TCIE_WIDTH                LLCE_LPSPI_IER_TCIE_WIDTH
#define LPSPI_IER_TCIE(x)                   LLCE_LPSPI_IER_TCIE(x)   
#define LPSPI_IER_TEIE_MASK                 LLCE_LPSPI_IER_TEIE_MASK 
#define LPSPI_IER_TEIE_SHIFT                LLCE_LPSPI_IER_TEIE_SHIFT
#define LPSPI_IER_TEIE_WIDTH                LLCE_LPSPI_IER_TEIE_WIDTH
#define LPSPI_IER_TEIE(x)                   LLCE_LPSPI_IER_TEIE(x)   
#define LPSPI_IER_REIE_MASK                 LLCE_LPSPI_IER_REIE_MASK 
#define LPSPI_IER_REIE_SHIFT                LLCE_LPSPI_IER_REIE_SHIFT
#define LPSPI_IER_REIE_WIDTH                LLCE_LPSPI_IER_REIE_WIDTH
#define LPSPI_IER_REIE(x)                   LLCE_LPSPI_IER_REIE(x)   
#define LPSPI_IER_DMIE_MASK                 LLCE_LPSPI_IER_DMIE_MASK 
#define LPSPI_IER_DMIE_SHIFT                LLCE_LPSPI_IER_DMIE_SHIFT
#define LPSPI_IER_DMIE_WIDTH                LLCE_LPSPI_IER_DMIE_WIDTH
#define LPSPI_IER_DMIE(x)                   LLCE_LPSPI_IER_DMIE(x)   
/*! @} */

/*! @name CFGR0 - Configuration 0 */
/*! @{ */

#define LPSPI_CFGR0_HREN_MASK               LLCE_LPSPI_CFGR0_HREN_MASK    
#define LPSPI_CFGR0_HREN_SHIFT              LLCE_LPSPI_CFGR0_HREN_SHIFT   
#define LPSPI_CFGR0_HREN_WIDTH              LLCE_LPSPI_CFGR0_HREN_WIDTH   
#define LPSPI_CFGR0_HREN(x)                 LLCE_LPSPI_CFGR0_HREN(x)      
#define LPSPI_CFGR0_HRPOL_MASK              LLCE_LPSPI_CFGR0_HRPOL_MASK   
#define LPSPI_CFGR0_HRPOL_SHIFT             LLCE_LPSPI_CFGR0_HRPOL_SHIFT  
#define LPSPI_CFGR0_HRPOL_WIDTH             LLCE_LPSPI_CFGR0_HRPOL_WIDTH  
#define LPSPI_CFGR0_HRPOL(x)                LLCE_LPSPI_CFGR0_HRPOL(x)     
#define LPSPI_CFGR0_HRSEL_MASK              LLCE_LPSPI_CFGR0_HRSEL_MASK   
#define LPSPI_CFGR0_HRSEL_SHIFT             LLCE_LPSPI_CFGR0_HRSEL_SHIFT  
#define LPSPI_CFGR0_HRSEL_WIDTH             LLCE_LPSPI_CFGR0_HRSEL_WIDTH  
#define LPSPI_CFGR0_HRSEL(x)                LLCE_LPSPI_CFGR0_HRSEL(x)     
#define LPSPI_CFGR0_CIRFIFO_MASK            LLCE_LPSPI_CFGR0_CIRFIFO_MASK 
#define LPSPI_CFGR0_CIRFIFO_SHIFT           LLCE_LPSPI_CFGR0_CIRFIFO_SHIFT
#define LPSPI_CFGR0_CIRFIFO_WIDTH           LLCE_LPSPI_CFGR0_CIRFIFO_WIDTH
#define LPSPI_CFGR0_CIRFIFO(x)              LLCE_LPSPI_CFGR0_CIRFIFO(x)   
#define LPSPI_CFGR0_RDMO_MASK               LLCE_LPSPI_CFGR0_RDMO_MASK    
#define LPSPI_CFGR0_RDMO_SHIFT              LLCE_LPSPI_CFGR0_RDMO_SHIFT   
#define LPSPI_CFGR0_RDMO_WIDTH              LLCE_LPSPI_CFGR0_RDMO_WIDTH   
#define LPSPI_CFGR0_RDMO(x)                 LLCE_LPSPI_CFGR0_RDMO(x)      
/*! @} */

/*! @name CFGR1 - Configuration 1 */
/*! @{ */

#define LPSPI_CFGR1_MASTER_MASK             LLCE_LPSPI_CFGR1_MASTER_MASK  
#define LPSPI_CFGR1_MASTER_SHIFT            LLCE_LPSPI_CFGR1_MASTER_SHIFT 
#define LPSPI_CFGR1_MASTER_WIDTH            LLCE_LPSPI_CFGR1_MASTER_WIDTH 
#define LPSPI_CFGR1_MASTER(x)               LLCE_LPSPI_CFGR1_MASTER(x)    
#define LPSPI_CFGR1_SAMPLE_MASK             LLCE_LPSPI_CFGR1_SAMPLE_MASK  
#define LPSPI_CFGR1_SAMPLE_SHIFT            LLCE_LPSPI_CFGR1_SAMPLE_SHIFT 
#define LPSPI_CFGR1_SAMPLE_WIDTH            LLCE_LPSPI_CFGR1_SAMPLE_WIDTH 
#define LPSPI_CFGR1_SAMPLE(x)               LLCE_LPSPI_CFGR1_SAMPLE(x)    
#define LPSPI_CFGR1_AUTOPCS_MASK            LLCE_LPSPI_CFGR1_AUTOPCS_MASK 
#define LPSPI_CFGR1_AUTOPCS_SHIFT           LLCE_LPSPI_CFGR1_AUTOPCS_SHIFT
#define LPSPI_CFGR1_AUTOPCS_WIDTH           LLCE_LPSPI_CFGR1_AUTOPCS_WIDTH
#define LPSPI_CFGR1_AUTOPCS(x)              LLCE_LPSPI_CFGR1_AUTOPCS(x)   
#define LPSPI_CFGR1_NOSTALL_MASK            LLCE_LPSPI_CFGR1_NOSTALL_MASK 
#define LPSPI_CFGR1_NOSTALL_SHIFT           LLCE_LPSPI_CFGR1_NOSTALL_SHIFT
#define LPSPI_CFGR1_NOSTALL_WIDTH           LLCE_LPSPI_CFGR1_NOSTALL_WIDTH
#define LPSPI_CFGR1_NOSTALL(x)              LLCE_LPSPI_CFGR1_NOSTALL(x)   
#define LPSPI_CFGR1_PCSPOL_MASK             LLCE_LPSPI_CFGR1_PCSPOL_MASK  
#define LPSPI_CFGR1_PCSPOL_SHIFT            LLCE_LPSPI_CFGR1_PCSPOL_SHIFT 
#define LPSPI_CFGR1_PCSPOL_WIDTH            LLCE_LPSPI_CFGR1_PCSPOL_WIDTH 
#define LPSPI_CFGR1_PCSPOL(x)               LLCE_LPSPI_CFGR1_PCSPOL(x)    
#define LPSPI_CFGR1_MATCFG_MASK             LLCE_LPSPI_CFGR1_MATCFG_MASK  
#define LPSPI_CFGR1_MATCFG_SHIFT            LLCE_LPSPI_CFGR1_MATCFG_SHIFT 
#define LPSPI_CFGR1_MATCFG_WIDTH            LLCE_LPSPI_CFGR1_MATCFG_WIDTH 
#define LPSPI_CFGR1_MATCFG(x)               LLCE_LPSPI_CFGR1_MATCFG(x)    
#define LPSPI_CFGR1_PINCFG_MASK             LLCE_LPSPI_CFGR1_PINCFG_MASK  
#define LPSPI_CFGR1_PINCFG_SHIFT            LLCE_LPSPI_CFGR1_PINCFG_SHIFT 
#define LPSPI_CFGR1_PINCFG_WIDTH            LLCE_LPSPI_CFGR1_PINCFG_WIDTH 
#define LPSPI_CFGR1_PINCFG(x)               LLCE_LPSPI_CFGR1_PINCFG(x)    
#define LPSPI_CFGR1_OUTCFG_MASK             LLCE_LPSPI_CFGR1_OUTCFG_MASK  
#define LPSPI_CFGR1_OUTCFG_SHIFT            LLCE_LPSPI_CFGR1_OUTCFG_SHIFT 
#define LPSPI_CFGR1_OUTCFG_WIDTH            LLCE_LPSPI_CFGR1_OUTCFG_WIDTH 
#define LPSPI_CFGR1_OUTCFG(x)               LLCE_LPSPI_CFGR1_OUTCFG(x)    
#define LPSPI_CFGR1_PCSCFG_MASK             LLCE_LPSPI_CFGR1_PCSCFG_MASK  
#define LPSPI_CFGR1_PCSCFG_SHIFT            LLCE_LPSPI_CFGR1_PCSCFG_SHIFT 
#define LPSPI_CFGR1_PCSCFG_WIDTH            LLCE_LPSPI_CFGR1_PCSCFG_WIDTH 
#define LPSPI_CFGR1_PCSCFG(x)               LLCE_LPSPI_CFGR1_PCSCFG(x)    
/*! @} */

/*! @name DMR0 - Data Match 0 */
/*! @{ */

#define LPSPI_DMR0_MATCH0_MASK              LLCE_LPSPI_DMR0_MATCH0_MASK 
#define LPSPI_DMR0_MATCH0_SHIFT             LLCE_LPSPI_DMR0_MATCH0_SHIFT
#define LPSPI_DMR0_MATCH0_WIDTH             LLCE_LPSPI_DMR0_MATCH0_WIDTH
#define LPSPI_DMR0_MATCH0(x)                LLCE_LPSPI_DMR0_MATCH0(x)   
/*! @} */

/*! @name DMR1 - Data Match 1 */
/*! @{ */

#define LPSPI_DMR1_MATCH1_MASK              LLCE_LPSPI_DMR1_MATCH1_MASK 
#define LPSPI_DMR1_MATCH1_SHIFT             LLCE_LPSPI_DMR1_MATCH1_SHIFT
#define LPSPI_DMR1_MATCH1_WIDTH             LLCE_LPSPI_DMR1_MATCH1_WIDTH
#define LPSPI_DMR1_MATCH1(x)                LLCE_LPSPI_DMR1_MATCH1(x)   
/*! @} */

/*! @name CCR - Clock Configuration */
/*! @{ */

#define LPSPI_CCR_SCKDIV_MASK               LLCE_LPSPI_CCR_SCKDIV_MASK 
#define LPSPI_CCR_SCKDIV_SHIFT              LLCE_LPSPI_CCR_SCKDIV_SHIFT
#define LPSPI_CCR_SCKDIV_WIDTH              LLCE_LPSPI_CCR_SCKDIV_WIDTH
#define LPSPI_CCR_SCKDIV(x)                 LLCE_LPSPI_CCR_SCKDIV(x)   
#define LPSPI_CCR_DBT_MASK                  LLCE_LPSPI_CCR_DBT_MASK    
#define LPSPI_CCR_DBT_SHIFT                 LLCE_LPSPI_CCR_DBT_SHIFT   
#define LPSPI_CCR_DBT_WIDTH                 LLCE_LPSPI_CCR_DBT_WIDTH   
#define LPSPI_CCR_DBT(x)                    LLCE_LPSPI_CCR_DBT(x)      
#define LPSPI_CCR_PCSSCK_MASK               LLCE_LPSPI_CCR_PCSSCK_MASK 
#define LPSPI_CCR_PCSSCK_SHIFT              LLCE_LPSPI_CCR_PCSSCK_SHIFT
#define LPSPI_CCR_PCSSCK_WIDTH              LLCE_LPSPI_CCR_PCSSCK_WIDTH
#define LPSPI_CCR_PCSSCK(x)                 LLCE_LPSPI_CCR_PCSSCK(x)   
#define LPSPI_CCR_SCKPCS_MASK               LLCE_LPSPI_CCR_SCKPCS_MASK 
#define LPSPI_CCR_SCKPCS_SHIFT              LLCE_LPSPI_CCR_SCKPCS_SHIFT
#define LPSPI_CCR_SCKPCS_WIDTH              LLCE_LPSPI_CCR_SCKPCS_WIDTH
#define LPSPI_CCR_SCKPCS(x)                 LLCE_LPSPI_CCR_SCKPCS(x)   
/*! @} */

/*! @name FCR - FIFO Control */
/*! @{ */

#define LPSPI_FCR_TXWATER_MASK              LLCE_LPSPI_FCR_TXWATER_MASK 
#define LPSPI_FCR_TXWATER_SHIFT             LLCE_LPSPI_FCR_TXWATER_SHIFT
#define LPSPI_FCR_TXWATER_WIDTH             LLCE_LPSPI_FCR_TXWATER_WIDTH
#define LPSPI_FCR_TXWATER(x)                LLCE_LPSPI_FCR_TXWATER(x)   
#define LPSPI_FCR_RXWATER_MASK              LLCE_LPSPI_FCR_RXWATER_MASK 
#define LPSPI_FCR_RXWATER_SHIFT             LLCE_LPSPI_FCR_RXWATER_SHIFT
#define LPSPI_FCR_RXWATER_WIDTH             LLCE_LPSPI_FCR_RXWATER_WIDTH
#define LPSPI_FCR_RXWATER(x)                LLCE_LPSPI_FCR_RXWATER(x)   
/*! @} */

/*! @name FSR - FIFO Status */
/*! @{ */

#define LPSPI_FSR_TXCOUNT_MASK              LLCE_LPSPI_FSR_TXCOUNT_MASK 
#define LPSPI_FSR_TXCOUNT_SHIFT             LLCE_LPSPI_FSR_TXCOUNT_SHIFT
#define LPSPI_FSR_TXCOUNT_WIDTH             LLCE_LPSPI_FSR_TXCOUNT_WIDTH
#define LPSPI_FSR_TXCOUNT(x)                LLCE_LPSPI_FSR_TXCOUNT(x)   
#define LPSPI_FSR_RXCOUNT_MASK              LLCE_LPSPI_FSR_RXCOUNT_MASK 
#define LPSPI_FSR_RXCOUNT_SHIFT             LLCE_LPSPI_FSR_RXCOUNT_SHIFT
#define LPSPI_FSR_RXCOUNT_WIDTH             LLCE_LPSPI_FSR_RXCOUNT_WIDTH
#define LPSPI_FSR_RXCOUNT(x)                LLCE_LPSPI_FSR_RXCOUNT(x)   
/*! @} */

/*! @name TCR - Transmit Command */
/*! @{ */

#define LPSPI_TCR_FRAMESZ_MASK              LLCE_LPSPI_TCR_FRAMESZ_MASK  
#define LPSPI_TCR_FRAMESZ_SHIFT             LLCE_LPSPI_TCR_FRAMESZ_SHIFT 
#define LPSPI_TCR_FRAMESZ_WIDTH             LLCE_LPSPI_TCR_FRAMESZ_WIDTH 
#define LPSPI_TCR_FRAMESZ(x)                LLCE_LPSPI_TCR_FRAMESZ(x)    
#define LPSPI_TCR_WIDTH_MASK                LLCE_LPSPI_TCR_WIDTH_MASK    
#define LPSPI_TCR_WIDTH_SHIFT               LLCE_LPSPI_TCR_WIDTH_SHIFT   
#define LPSPI_TCR_WIDTH_WIDTH               LLCE_LPSPI_TCR_WIDTH_WIDTH   
#define LPSPI_TCR_WIDTH(x)                  LLCE_LPSPI_TCR_WIDTH(x)      
#define LPSPI_TCR_TXMSK_MASK                LLCE_LPSPI_TCR_TXMSK_MASK    
#define LPSPI_TCR_TXMSK_SHIFT               LLCE_LPSPI_TCR_TXMSK_SHIFT   
#define LPSPI_TCR_TXMSK_WIDTH               LLCE_LPSPI_TCR_TXMSK_WIDTH   
#define LPSPI_TCR_TXMSK(x)                  LLCE_LPSPI_TCR_TXMSK(x)      
#define LPSPI_TCR_RXMSK_MASK                LLCE_LPSPI_TCR_RXMSK_MASK    
#define LPSPI_TCR_RXMSK_SHIFT               LLCE_LPSPI_TCR_RXMSK_SHIFT   
#define LPSPI_TCR_RXMSK_WIDTH               LLCE_LPSPI_TCR_RXMSK_WIDTH   
#define LPSPI_TCR_RXMSK(x)                  LLCE_LPSPI_TCR_RXMSK(x)      
#define LPSPI_TCR_CONTC_MASK                LLCE_LPSPI_TCR_CONTC_MASK    
#define LPSPI_TCR_CONTC_SHIFT               LLCE_LPSPI_TCR_CONTC_SHIFT   
#define LPSPI_TCR_CONTC_WIDTH               LLCE_LPSPI_TCR_CONTC_WIDTH   
#define LPSPI_TCR_CONTC(x)                  LLCE_LPSPI_TCR_CONTC(x)      
#define LPSPI_TCR_CONT_MASK                 LLCE_LPSPI_TCR_CONT_MASK     
#define LPSPI_TCR_CONT_SHIFT                LLCE_LPSPI_TCR_CONT_SHIFT    
#define LPSPI_TCR_CONT_WIDTH                LLCE_LPSPI_TCR_CONT_WIDTH    
#define LPSPI_TCR_CONT(x)                   LLCE_LPSPI_TCR_CONT(x)       
#define LPSPI_TCR_BYSW_MASK                 LLCE_LPSPI_TCR_BYSW_MASK     
#define LPSPI_TCR_BYSW_SHIFT                LLCE_LPSPI_TCR_BYSW_SHIFT    
#define LPSPI_TCR_BYSW_WIDTH                LLCE_LPSPI_TCR_BYSW_WIDTH    
#define LPSPI_TCR_BYSW(x)                   LLCE_LPSPI_TCR_BYSW(x)       
#define LPSPI_TCR_LSBF_MASK                 LLCE_LPSPI_TCR_LSBF_MASK     
#define LPSPI_TCR_LSBF_SHIFT                LLCE_LPSPI_TCR_LSBF_SHIFT    
#define LPSPI_TCR_LSBF_WIDTH                LLCE_LPSPI_TCR_LSBF_WIDTH    
#define LPSPI_TCR_LSBF(x)                   LLCE_LPSPI_TCR_LSBF(x)       
#define LPSPI_TCR_PCS_MASK                  LLCE_LPSPI_TCR_PCS_MASK      
#define LPSPI_TCR_PCS_SHIFT                 LLCE_LPSPI_TCR_PCS_SHIFT     
#define LPSPI_TCR_PCS_WIDTH                 LLCE_LPSPI_TCR_PCS_WIDTH     
#define LPSPI_TCR_PCS(x)                    LLCE_LPSPI_TCR_PCS(x)        
#define LPSPI_TCR_PRESCALE_MASK             LLCE_LPSPI_TCR_PRESCALE_MASK 
#define LPSPI_TCR_PRESCALE_SHIFT            LLCE_LPSPI_TCR_PRESCALE_SHIFT
#define LPSPI_TCR_PRESCALE_WIDTH            LLCE_LPSPI_TCR_PRESCALE_WIDTH
#define LPSPI_TCR_PRESCALE(x)               LLCE_LPSPI_TCR_PRESCALE(x)   
#define LPSPI_TCR_CPHA_MASK                 LLCE_LPSPI_TCR_CPHA_MASK     
#define LPSPI_TCR_CPHA_SHIFT                LLCE_LPSPI_TCR_CPHA_SHIFT    
#define LPSPI_TCR_CPHA_WIDTH                LLCE_LPSPI_TCR_CPHA_WIDTH    
#define LPSPI_TCR_CPHA(x)                   LLCE_LPSPI_TCR_CPHA(x)       
#define LPSPI_TCR_CPOL_MASK                 LLCE_LPSPI_TCR_CPOL_MASK     
#define LPSPI_TCR_CPOL_SHIFT                LLCE_LPSPI_TCR_CPOL_SHIFT    
#define LPSPI_TCR_CPOL_WIDTH                LLCE_LPSPI_TCR_CPOL_WIDTH    
#define LPSPI_TCR_CPOL(x)                   LLCE_LPSPI_TCR_CPOL(x)       
/*! @} */

/*! @name TDR - Transmit Data */
/*! @{ */

#define LPSPI_TDR_DATA_MASK                 LLCE_LPSPI_TDR_DATA_MASK 
#define LPSPI_TDR_DATA_SHIFT                LLCE_LPSPI_TDR_DATA_SHIFT
#define LPSPI_TDR_DATA_WIDTH                LLCE_LPSPI_TDR_DATA_WIDTH
#define LPSPI_TDR_DATA(x)                   LLCE_LPSPI_TDR_DATA(x)   
/*! @} */

/*! @name RSR - Receive Status */
/*! @{ */

#define LPSPI_RSR_SOF_MASK                  LLCE_LPSPI_RSR_SOF_MASK     
#define LPSPI_RSR_SOF_SHIFT                 LLCE_LPSPI_RSR_SOF_SHIFT    
#define LPSPI_RSR_SOF_WIDTH                 LLCE_LPSPI_RSR_SOF_WIDTH    
#define LPSPI_RSR_SOF(x)                    LLCE_LPSPI_RSR_SOF(x)       
#define LPSPI_RSR_RXEMPTY_MASK              LLCE_LPSPI_RSR_RXEMPTY_MASK 
#define LPSPI_RSR_RXEMPTY_SHIFT             LLCE_LPSPI_RSR_RXEMPTY_SHIFT
#define LPSPI_RSR_RXEMPTY_WIDTH             LLCE_LPSPI_RSR_RXEMPTY_WIDTH
#define LPSPI_RSR_RXEMPTY(x)                LLCE_LPSPI_RSR_RXEMPTY(x)   
/*! @} */

/*! @name RDR - Receive Data */
/*! @{ */

#define LPSPI_RDR_DATA_MASK                 LLCE_LPSPI_RDR_DATA_MASK 
#define LPSPI_RDR_DATA_SHIFT                LLCE_LPSPI_RDR_DATA_SHIFT
#define LPSPI_RDR_DATA_WIDTH                LLCE_LPSPI_RDR_DATA_WIDTH
#define LPSPI_RDR_DATA(x)                   LLCE_LPSPI_RDR_DATA(x)   
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif

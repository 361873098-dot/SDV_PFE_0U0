/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.0
*   Build Version        : S32_RTD_4_0_0_D2210_ASR_REL_4_4_REV_0000_20221031
*
*   (c) Copyright 2022 NXP Semiconductors
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

#ifndef XRDC_IP_CFG_H
#define XRDC_IP_CFG_H

/**
*   @file Xrdc_Ip_Cfg.h
*
*   @addtogroup XRDC_IP XRDC IPV Driver
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"

#include "Xrdc_Ip_PBcfg.h"
#include "Xrdc_Ip_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_XRDC_IP_CFG_VENDOR_ID                    43
#define RM_XRDC_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define RM_XRDC_IP_CFG_AR_RELEASE_MINOR_VERSION     4
#define RM_XRDC_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define RM_XRDC_IP_CFG_SW_MAJOR_VERSION             4
#define RM_XRDC_IP_CFG_SW_MINOR_VERSION             0
#define RM_XRDC_IP_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                   FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Xrdc_Ip_PBcfg.h */
#if (RM_XRDC_IP_CFG_VENDOR_ID != RM_XRDC_IP_PBCFG_VENDOR_ID)
    #error "Xrdc_Ip_Cfg.h and Xrdc_Ip_PBcfg.h have different vendor ids"
#endif
#if ((RM_XRDC_IP_CFG_AR_RELEASE_MAJOR_VERSION    != RM_XRDC_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_XRDC_IP_CFG_AR_RELEASE_MINOR_VERSION    != RM_XRDC_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_XRDC_IP_CFG_AR_RELEASE_REVISION_VERSION != RM_XRDC_IP_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Xrdc_Ip_Cfg.h and Xrdc_Ip_PBcfg.h are different"
#endif
#if ((RM_XRDC_IP_CFG_SW_MAJOR_VERSION != RM_XRDC_IP_PBCFG_SW_MAJOR_VERSION) || \
     (RM_XRDC_IP_CFG_SW_MINOR_VERSION != RM_XRDC_IP_PBCFG_SW_MINOR_VERSION) || \
     (RM_XRDC_IP_CFG_SW_PATCH_VERSION != RM_XRDC_IP_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Xrdc_Ip_Cfg.h and Xrdc_Ip_PBcfg.h are different"
#endif


#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((RM_XRDC_IP_CFG_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (RM_XRDC_IP_CFG_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Xrdc_Ip_Cfg.h and Mcal.h are different"
    #endif
#endif

/* Checks against Xrdc_Ip_Types.h */
#if (RM_XRDC_IP_CFG_VENDOR_ID != RM_XRDC_IP_TYPES_VENDOR_ID)
    #error "Xrdc_Ip_Cfg.h and Xrdc_Ip_Types.h have different vendor ids"
#endif
#if ((RM_XRDC_IP_CFG_AR_RELEASE_MAJOR_VERSION    != RM_XRDC_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (RM_XRDC_IP_CFG_AR_RELEASE_MINOR_VERSION    != RM_XRDC_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (RM_XRDC_IP_CFG_AR_RELEASE_REVISION_VERSION != RM_XRDC_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Xrdc_Ip_Cfg.h and Xrdc_Ip_Types.h are different"
#endif
#if ((RM_XRDC_IP_CFG_SW_MAJOR_VERSION != RM_XRDC_IP_TYPES_SW_MAJOR_VERSION) || \
     (RM_XRDC_IP_CFG_SW_MINOR_VERSION != RM_XRDC_IP_TYPES_SW_MINOR_VERSION) || \
     (RM_XRDC_IP_CFG_SW_PATCH_VERSION != RM_XRDC_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Xrdc_Ip_Cfg.h and Xrdc_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/**
* @brief   Collection of all configuration structures declarations.
*/

#define XRDC_CONFIG_EXT \
    XRDC_CONFIG_PB

#define RM_IP_ENABLE_XRDC                               (STD_ON)

#define XRDC_IP_DEV_ERROR_DETECT                        (STD_ON)

#define XRDC_IP_REGISTER_LOCK                           (STD_OFF)

#define XRDC_NUM_MEM_DESCRIPTOR_CONFIG                  (23U)

#define XRDC_NUM_PERIPHERAL_DESCRIPTOR_CONFIG           (18U)

#define XRDC_NUM_DOMAIN_CONFIG                          (21U)

#define XRDC_IP_ADDRESS_SHIFT                           (4UL)

/* Peripherals of XRDC_INSTANCE0 */
#define XRDC_SELF_TEST                                  (31U)
#define XRDC_STCU2                                      (1U)
#define XRDC_MC_CGM_0                                   (9U)
#define XRDC_MC_CGM_1                                   (10U)
#define XRDC_CORE_PLL                                   (11U)
#define XRDC_PERIPHERAL_PLL                             (12U)
#define XRDC_ACCELERATOR_PLL                            (13U)
#define XRDC_DRAM_PLL                                   (14U)
#define XRDC_DEBUG_MUX                                  (15U)
#define XRDC_XOSC                                       (17U)
#define XRDC_CORE_DFS                                   (18U)
#define XRDC_PERIPH_DFS                                 (19U)
#define XRDC_CMU                                        (20U)
#define XRDC_RTC                                        (21U)
#define XRDC_MC_CGM_5                                   (30U)
#define XRDC_MC_RGM                                     (22U)
#define XRDC_GPR                                        (23U)
#define XRDC_RDC                                        (24U)
#define XRDC_MC_ME                                      (25U)
#define XRDC_PMC                                        (26U)
#define XRDC_WKPU                                       (27U)
#define XRDC_SIUL2_0                                    (28U)
#define XRDC_OCOTP                                      (29U)
#define XRDC_TMU                                        (5U)
#define XRDC_SWT_0                                      (128U)
#define XRDC_SWT_1                                      (129U)
#define XRDC_SWT_2                                      (130U)
#define XRDC_SWT_3                                      (157U)
#define XRDC_STM_0                                      (131U)
#define XRDC_STM_1                                      (132U)
#define XRDC_STM_2                                      (133U)
#define XRDC_STM_3                                      (158U)
#define XRDC_DMAMUX_0                                   (134U)
#define XRDC_DMAMUX_1                                   (135U)
#define XRDC_QUADSPI                                    (156U)
#define XRDC_DMACRC_0                                   (136U)
#define XRDC_EDMA_0_CONTROL                             (137U)
#define XRDC_EDMA_0_CHANNEL_0                           (160U)
#define XRDC_EDMA_0_CHANNEL_16                          (161U)
#define XRDC_PIT_0                                      (138U)
#define XRDC_CRC_0                                      (139U)
#define XRDC_MSCM                                       (140U)
#define XRDC_SRAMC_0                                    (141U)
#define XRDC_SRAMC_1                                    (159U)
#define XRDC_XRDC_0                                     (142U)
#define XRDC_CAN_0                                      (143U)
#define XRDC_CAN_1                                      (144U)
#define XRDC_LINFLEX_0                                  (145U)
#define XRDC_LINFLEX_1                                  (146U)
#define XRDC_SPI_0                                      (147U)
#define XRDC_SPI_1                                      (148U)
#define XRDC_SPI_2                                      (149U)
#define XRDC_I2C_0                                      (150U)
#define XRDC_I2C_1                                      (151U)
#define XRDC_I2C_2                                      (152U)
#define XRDC_FTM_0                                      (153U)
#define XRDC_SAR_ADC_0                                  (154U)
#define XRDC_CTU                                        (155U)
#define XRDC_SWT_4                                      (256U)
#define XRDC_SWT_5                                      (257U)
#define XRDC_SWT_6                                      (258U)
#define XRDC_SWT_7                                      (282U)
#define XRDC_HSE_MU0                                    (267U)
#define XRDC_HSE_MU1                                    (285U)
#define XRDC_HSE_MU2                                    (286U)
#define XRDC_HSE_MU3                                    (287U)
#define XRDC_STM_4                                      (259U)
#define XRDC_STM_5                                      (260U)
#define XRDC_STM_6                                      (261U)
#define XRDC_STM_7                                      (283U)
#define XRDC_DMAMUX_2                                   (262U)
#define XRDC_DMAMUX_3                                   (263U)
#define XRDC_DMACRC_1                                   (264U)
#define XRDC_EDMA_1_CONTROL                             (265U)
#define XRDC_EDMA_1_CHANNEL_0                           (288U)
#define XRDC_EDMA_1_CHANNEL_16                          (289U)
#define XRDC_PIT_1                                      (266U)
#define XRDC_SEMA42                                     (268U)
#define XRDC_CAN_2                                      (269U)
#define XRDC_CAN_3                                      (270U)
#define XRDC_LINFLEX_2                                  (271U)
#define XRDC_SPI_3                                      (272U)
#define XRDC_SPI_4                                      (273U)
#define XRDC_SPI_5                                      (274U)
#define XRDC_I2C_3                                      (275U)
#define XRDC_I2C_4                                      (276U)
#define XRDC_FTM_1                                      (277U)
#define XRDC_SAR_ADC_1                                  (278U)
#define XRDC_DIPORTSD_0                                 (279U)
#define XRDC_USDHC                                      (280U)
#define XRDC_JDC                                        (284U)
#define XRDC_FR_0                                       (281U)
#define XRDC_RCCU                                       (384U)
#define XRDC_EIM                                        (385U)
#define XRDC_FCCU                                       (387U)
#define XRDC_SBSW                                       (388U)
#define XRDC_ERM_PER_EDMA0_EDMA1_ERM_7                  (407U)
#define XRDC_ERM_CPU0_CPU1_CPU2_ERM_7                   (408U)
#define XRDC_EIMS                                       (401U)
#define XRDC_GMAC_0                                     (389U)
#define XRDC_DDRSS_0                                    (400U)
#define XRDC_PCIE_APB                                   (406U)
#define XRDC_SWT_8                                      (512U)
#define XRDC_SWT_9                                      (513U)
#define XRDC_SWT_10                                     (514U)
#define XRDC_SWT_11                                     (515U)
#define XRDC_STM_8                                      (520U)
#define XRDC_STM_9                                      (521U)
#define XRDC_STM_10                                     (522U)
#define XRDC_STM_11                                     (523U)
#define XRDC_MC_CGM_6                                   (527U)
#define XRDC_EIM_1                                      (528U)
#define XRDC_SRAMC_2                                    (541U)
#define XRDC_SRAMC_3                                    (542U)

/* Peripherals of XRDC_INSTANCE1 */
#define XRDC_XRDC_1                                     (1U)
#define XRDC_STM_TS                                     (2U)
#define XRDC_SIUL2                                      (0U)
#define XRDC_MC_CGM2                                    (3U)
#define XRDC_STDBY_SRAM_CFG                             (4U)
#define XRDC_ERM_LLCE                                   (8U)
#define XRDC_ERM_PFE0                                   (9U)
#define XRDC_ERM_STANDBY_RAM                            (13U)
#define XRDC_EIM_MISC                                   (10U)
#define XRDC_EIM_LLCE                                   (11U)
#define XRDC_EIM_PFE0                                   (12U)
#define XRDC_USB                                        (5U)
#define XRDC_PCIE_1                                     (6U)


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif /* __cplusplus */

/** @} */

#endif /* XRDC_IP_CFG_H */


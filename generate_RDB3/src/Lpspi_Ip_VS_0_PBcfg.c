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
*   Copyright 2020-2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file    Lpspi_Ip_VS_0_PBcfg.c
*   @version 4.0.2
*
*   @brief   AUTOSAR Spi - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup LPSPI_DRIVER_CONFIGURATION Lpspi Driver Configuration
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Lpspi_Ip.h"
#if (STD_ON == LPSPI_IP_SUPPORT)
#if (LPSPI_IP_DMA_USED == STD_ON)
#include "Dma_Ip.h"
#endif
#endif
/*==================================================================================================
*                                    SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LPSPI_IP_VS_0_VENDOR_ID_PBCFG_C                        43
#define LPSPI_IP_VS_0_AR_RELEASE_MAJOR_VERSION_PBCFG_C         4
#define LPSPI_IP_VS_0_AR_RELEASE_MINOR_VERSION_PBCFG_C         4
#define LPSPI_IP_VS_0_AR_RELEASE_REVISION_VERSION_PBCFG_C      0
#define LPSPI_IP_VS_0_SW_MAJOR_VERSION_PBCFG_C                 4
#define LPSPI_IP_VS_0_SW_MINOR_VERSION_PBCFG_C                 0
#define LPSPI_IP_VS_0_SW_PATCH_VERSION_PBCFG_C                 2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Lpspi_Ip.h and Lpspi_Ip_PBcfg.c are of the same vendor */
#if (LPSPI_IP_VENDOR_ID != LPSPI_IP_VS_0_VENDOR_ID_PBCFG_C)
    #error "Lpspi_Ip.h and Lpspi_Ip_PBcfg.c have different vendor ids"
#endif
/* Check if Lpspi_Ip.h file and Lpspi_Ip_PBcfg.c file are of the same Autosar version */
#if ((LPSPI_IP_AR_RELEASE_MAJOR_VERSION != LPSPI_IP_VS_0_AR_RELEASE_MAJOR_VERSION_PBCFG_C) || \
     (LPSPI_IP_AR_RELEASE_MINOR_VERSION != LPSPI_IP_VS_0_AR_RELEASE_MINOR_VERSION_PBCFG_C) || \
     (LPSPI_IP_AR_RELEASE_REVISION_VERSION != LPSPI_IP_VS_0_AR_RELEASE_REVISION_VERSION_PBCFG_C))
#error "AutoSar Version Numbers of Lpspi_Ip.h and Lpspi_Ip_PBcfg.c are different"
#endif
#if ((LPSPI_IP_SW_MAJOR_VERSION != LPSPI_IP_VS_0_SW_MAJOR_VERSION_PBCFG_C) || \
     (LPSPI_IP_SW_MINOR_VERSION != LPSPI_IP_VS_0_SW_MINOR_VERSION_PBCFG_C) || \
     (LPSPI_IP_SW_PATCH_VERSION != LPSPI_IP_VS_0_SW_PATCH_VERSION_PBCFG_C))
#error "Software Version Numbers of Lpspi_Ip.h and Lpspi_Ip_PBcfg.c are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (STD_ON == LPSPI_IP_SUPPORT)
    #if (LPSPI_IP_DMA_USED == STD_ON)
        /* Check if current file and Dma_Ip header file are of the same Autosar version */
        #if ((DMA_IP_AR_RELEASE_MAJOR_VERSION != LPSPI_IP_VS_0_AR_RELEASE_MAJOR_VERSION_PBCFG_C) || \
             (DMA_IP_AR_RELEASE_MINOR_VERSION != LPSPI_IP_VS_0_AR_RELEASE_MINOR_VERSION_PBCFG_C))
        #error "AutoSar Version Numbers of Lpspi_Ip_Cfg.h and Dma_Ip.h are different"
        #endif
    #endif
#endif
#endif
/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#if (STD_ON == LPSPI_IP_SUPPORT)


#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

#endif
/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,FTM
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_P04_D2312_ASR_REL_4_4_REV_0000_20231219
*
*   Copyright 2020-2023 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

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
#include "Dma_Ip_Cfg.h"

/*==================================================================================================
*                                    SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DMA_IP_VS_0_PBCFG_VENDOR_ID_C                        43
#define DMA_IP_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C         4
#define DMA_IP_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C         4
#define DMA_IP_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C      0
#define DMA_IP_VS_0_PBCFG_SW_MAJOR_VERSION_C                 4
#define DMA_IP_VS_0_PBCFG_SW_MINOR_VERSION_C                 0
#define DMA_IP_VS_0_PBCFG_SW_PATCH_VERSION_C                 2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Dma_Ip_VS_0_PBcfg.c file and Dma_Ip_Cfg.h file are of the same vendor */
#if (DMA_IP_VS_0_PBCFG_VENDOR_ID_C != DMA_IP_CFG_VENDOR_ID)
    #error "Dma_Ip_VS_0_PBcfg.c and Dma_Ip_Cfg.h have different vendor ids"
#endif

/* Check if Dma_Ip_VS_0_PBcfg.c file and Dma_Ip_Cfg.h file are of the same Autosar version */
#if ((DMA_IP_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C != DMA_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C != DMA_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dma_Ip_VS_0_PBcfg.c and Dma_Ip_Cfg.h are different"
#endif

/* Check if Dma_Ip_VS_0_PBcfg.c file and Dma_Ip_Cfg.h file are of the same Software version */
#if ((DMA_IP_VS_0_PBCFG_SW_MAJOR_VERSION_C != DMA_IP_CFG_SW_MAJOR_VERSION) || \
     (DMA_IP_VS_0_PBCFG_SW_MINOR_VERSION_C != DMA_IP_CFG_SW_MINOR_VERSION) || \
     (DMA_IP_VS_0_PBCFG_SW_PATCH_VERSION_C != DMA_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Ip_VS_0_PBcfg.c and Dma_Ip_Cfg.h are different"
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

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/

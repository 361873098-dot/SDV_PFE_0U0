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

#ifndef DMA_IP_CFG_H
#define DMA_IP_CFG_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Dma_Ip_Types.h"
#include "Dma_Ip_VS_0_PBcfg.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DMA_IP_CFG_VENDOR_ID                       43
#define DMA_IP_CFG_AR_RELEASE_MAJOR_VERSION        4
#define DMA_IP_CFG_AR_RELEASE_MINOR_VERSION        4
#define DMA_IP_CFG_AR_RELEASE_REVISION_VERSION     0
#define DMA_IP_CFG_SW_MAJOR_VERSION                4
#define DMA_IP_CFG_SW_MINOR_VERSION                0
#define DMA_IP_CFG_SW_PATCH_VERSION                2

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Dma_Ip_Types.h file are of the same vendor */
#if (DMA_IP_CFG_VENDOR_ID != DMA_IP_TYPES_VENDOR_ID)
    #error "Dma_Ip_Cfg.h and Dma_Ip_Types.h have different vendor ids"
#endif

/* Check if header file and Dma_Ip_Types.h file are of the same Autosar version */
#if ((DMA_IP_CFG_AR_RELEASE_MAJOR_VERSION != DMA_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_CFG_AR_RELEASE_MINOR_VERSION != DMA_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_CFG_AR_RELEASE_REVISION_VERSION != DMA_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dma_Ip_Cfg.h and Dma_Ip_Types.h are different"
#endif

/* Check if header file and Dma_Ip_Types.h file are of the same Software version */
#if ((DMA_IP_CFG_SW_MAJOR_VERSION != DMA_IP_TYPES_SW_MAJOR_VERSION) || \
     (DMA_IP_CFG_SW_MINOR_VERSION != DMA_IP_TYPES_SW_MINOR_VERSION) || \
     (DMA_IP_CFG_SW_PATCH_VERSION != DMA_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Ip_Cfg.h and Dma_Ip_Types.h are different"
#endif

/* Check if header file and Dma_Ip_VS_0_PBcfg.h file are of the same vendor */
#if (DMA_IP_CFG_VENDOR_ID != DMA_IP_VS_0_PBCFG_VENDOR_ID)
    #error "Dma_Ip_Cfg.h and Dma_Ip_VS_0_PBcfg.h have different vendor ids"
#endif

/* Check if header file and Dma_Ip_VS_0_PBcfg.h file are of the same Autosar version */
#if ((DMA_IP_CFG_AR_RELEASE_MAJOR_VERSION != DMA_IP_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_CFG_AR_RELEASE_MINOR_VERSION != DMA_IP_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_CFG_AR_RELEASE_REVISION_VERSION != DMA_IP_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dma_Ip_Cfg.h and Dma_Ip_VS_0_PBcfg.h are different"
#endif

/* Check if header file and Dma_Ip_VS_0_PBcfg.h file are of the same Software version */
#if ((DMA_IP_CFG_SW_MAJOR_VERSION != DMA_IP_VS_0_PBCFG_SW_MAJOR_VERSION) || \
     (DMA_IP_CFG_SW_MINOR_VERSION != DMA_IP_VS_0_PBCFG_SW_MINOR_VERSION) || \
     (DMA_IP_CFG_SW_PATCH_VERSION != DMA_IP_VS_0_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Ip_Cfg.h and Dma_Ip_VS_0_PBcfg.h are different"
#endif

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* DMA_IP_CFG_H_ */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/

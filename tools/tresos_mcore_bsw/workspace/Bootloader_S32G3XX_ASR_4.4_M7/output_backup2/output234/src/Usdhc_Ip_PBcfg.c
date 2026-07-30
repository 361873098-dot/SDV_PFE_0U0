/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : IPV_USDHC
*   Dependencies         : 
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

/**
* @file Usdhc_Ip__PBcfg.c
*
* @addtogroup Usdhc_Ip
* @{
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
#include "Usdhc_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define USDHC_VENDOR_ID_IP_PBCFG_C                      43
#define USDHC_AR_RELEASE_MAJOR_VERSION_IP_PBCFG_C       4
#define USDHC_AR_RELEASE_MINOR_VERSION_IP_PBCFG_C       4
#define USDHC_AR_RELEASE_REVISION_VERSION_IP_PBCFG_C    0
#define USDHC_SW_MAJOR_VERSION_IP_PBCFG_C               4
#define USDHC_SW_MINOR_VERSION_IP_PBCFG_C               0
#define USDHC_SW_PATCH_VERSION_IP_PBCFG_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Usdhc_Ip_Cfg header file are of the same vendor */
#if (USDHC_VENDOR_ID_IP_PBCFG_C != USDHC_VENDOR_ID_IP_CFG)
    #error "AutoSar Version Numbers of Usdhc_Ip_PBcfg.c and Usdhc_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Usdhc_Ip_Cfg header file are of the same Autosar version */
#if ((USDHC_AR_RELEASE_MAJOR_VERSION_IP_PBCFG_C    != USDHC_AR_RELEASE_MAJOR_VERSION_IP_CFG) || \
     (USDHC_AR_RELEASE_MINOR_VERSION_IP_PBCFG_C    != USDHC_AR_RELEASE_MINOR_VERSION_IP_CFG) || \
     (USDHC_AR_RELEASE_REVISION_VERSION_IP_PBCFG_C != USDHC_AR_RELEASE_REVISION_VERSION_IP_CFG) \
    )
    #error "AutoSar Version Numbers of Usdhc_Ip_PBcfg.c and Usdhc_Ip_Cfg.h are different"
#endif
/* Check if current file and Usdhc_Ip_Cfg header file are of the same Software version */
#if ((USDHC_SW_MAJOR_VERSION_IP_PBCFG_C != USDHC_SW_MAJOR_VERSION_IP_CFG) || \
     (USDHC_SW_MINOR_VERSION_IP_PBCFG_C != USDHC_SW_MINOR_VERSION_IP_CFG) || \
     (USDHC_SW_PATCH_VERSION_IP_PBCFG_C != USDHC_SW_PATCH_VERSION_IP_CFG) \
    )
    #error "Software Version Numbers of Usdhc_Ip_PBcfg.c and Usdhc_Ip_Cfg.h are different"
#endif
/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/
    
                    
#define EEP_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Eep_MemMap.h"
static uint32 usdhc1_admaTable0[32000U / 4U];
#define EEP_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Eep_MemMap.h"

#define EEP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eep_MemMap.h"

/* uSDHC User Configurations EepUsdhcControllerCfg_0 */
const Usdhc_Ip_ConfigType EepUsdhcControllerCfg_0 =
{
    0U, /* Instance number */
    (boolean)FALSE, /* cardDetectDat3 */
    (boolean)TRUE, /* EepEnableAutoCMD12 */
    USDHC_ENDIAN_MODE_LITTLE, /* endianMode */
    USDHC_DMA_MODE_ADMA2, /* dmaMode */
    usdhc1_admaTable0, /* admaTable */
    32000U, /* admaTableSize */
    128U, /* writeWatermarkLevel */
    16U, /* readWatermarkLevel */
    NULL_PTR, /* cardInsertCallback */
    NULL_PTR, /* cardRemoveCallback */
    NULL_PTR, /* transferCompleteCallback */
    NULL_PTR, /* transferErrorCallback */
    NULL_PTR, /* blockGapCallback */
    NULL_PTR, /* cardIntCallback */
NULL_PTR

};
#define EEP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eep_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @}*/

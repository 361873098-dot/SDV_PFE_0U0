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
* @file Sd_Emmc_Ip__PBcfg.c
*
* @addtogroup Sd_Emmc_Ip
* @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/**
*
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Sd_Emmc_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SD_EMMC_VENDOR_ID_IP_PBCFG_C                      43
#define SD_EMMC_AR_RELEASE_MAJOR_VERSION_IP_PBCFG_C       4
#define SD_EMMC_AR_RELEASE_MINOR_VERSION_IP_PBCFG_C       4
#define SD_EMMC_AR_RELEASE_REVISION_VERSION_IP_PBCFG_C    0
#define SD_EMMC_SW_MAJOR_VERSION_IP_PBCFG_C               4
#define SD_EMMC_SW_MINOR_VERSION_IP_PBCFG_C               0
#define SD_EMMC_SW_PATCH_VERSION_IP_PBCFG_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Sd_Emmc_Ip_Cfg header file are of the same vendor */
#if (SD_EMMC_VENDOR_ID_IP_PBCFG_C != SD_EMMC_VENDOR_ID_IP_CFG)
    #error "AutoSar Version Numbers of Sd_Emmc_Ip_PBcfg.c and Sd_Emmc_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Sd_Emmc_Ip_Cfg header file are of the same Autosar version */
#if ((SD_EMMC_AR_RELEASE_MAJOR_VERSION_IP_PBCFG_C    != SD_EMMC_AR_RELEASE_MAJOR_VERSION_IP_CFG) || \
     (SD_EMMC_AR_RELEASE_MINOR_VERSION_IP_PBCFG_C    != SD_EMMC_AR_RELEASE_MINOR_VERSION_IP_CFG) || \
     (SD_EMMC_AR_RELEASE_REVISION_VERSION_IP_PBCFG_C != SD_EMMC_AR_RELEASE_REVISION_VERSION_IP_CFG) \
    )
    #error "AutoSar Version Numbers of Sd_Emmc_Ip_PBcfg.c and Sd_Emmc_Ip_Cfg.h are different"
#endif
/* Check if current file and Sd_Emmc_Ip_Cfg header file are of the same Software version */
#if ((SD_EMMC_SW_MAJOR_VERSION_IP_PBCFG_C != SD_EMMC_SW_MAJOR_VERSION_IP_CFG) || \
     (SD_EMMC_SW_MINOR_VERSION_IP_PBCFG_C != SD_EMMC_SW_MINOR_VERSION_IP_CFG) || \
     (SD_EMMC_SW_PATCH_VERSION_IP_PBCFG_C != SD_EMMC_SW_PATCH_VERSION_IP_CFG) \
    )
    #error "Software Version Numbers of Sd_Emmc_Ip_PBcfg.c and Sd_Emmc_Ip_Cfg.h are different"
#endif

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


#define EEP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eep_MemMap.h"

/* SD Configurations */
const Sd_Emmc_Ip_ConfigType EepSdCfg_0 =
{
    &EepUsdhcControllerCfg_0,
    48000000UL, /* SdConfigClock */
    48000000UL, /* u32McuClock */
    0UL, /* flags */
    SD_IP_MEMORY_CARD_SD, /* cardType */
    SD_IP_DATABUSWIDTH_4BIT, /* Bus width mode */
    0U, /* Card driver strength */
    NULL_PTR   /* MMC boot configuration */
};

#define EEP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eep_MemMap.h"



#ifdef __cplusplus
}
#endif
/** @}*/

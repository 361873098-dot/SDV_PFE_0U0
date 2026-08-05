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

#ifndef SD_EMMC_IP_CFG_H
#define SD_EMMC_IP_CFG_H

/**
* @file Sd_Emmc_Ip_Cfg.h
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
#include "Usdhc_Ip_Cfg.h"
#include "Sd_Emmc_Ip_Types.h"
#include "StandardTypes.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SD_EMMC_VENDOR_ID_IP_CFG                          43
#define SD_EMMC_AR_RELEASE_MAJOR_VERSION_IP_CFG           4
#define SD_EMMC_AR_RELEASE_MINOR_VERSION_IP_CFG           4
#define SD_EMMC_AR_RELEASE_REVISION_VERSION_IP_CFG        0
#define SD_EMMC_SW_MAJOR_VERSION_IP_CFG                   4
#define SD_EMMC_SW_MINOR_VERSION_IP_CFG                   0
#define SD_EMMC_SW_PATCH_VERSION_IP_CFG                   0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Usdhc_Ip_Cfg header file are of the same vendor */
#if (SD_EMMC_VENDOR_ID_IP_CFG != USDHC_VENDOR_ID_IP_CFG)
    #error "Sd_Emmc_Ip_Cfg.h and Usdhc_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Usdhc_Ip_Cfg header file are of the same Autosar version */
#if ((SD_EMMC_AR_RELEASE_MAJOR_VERSION_IP_CFG    != USDHC_AR_RELEASE_MAJOR_VERSION_IP_CFG) || \
     (SD_EMMC_AR_RELEASE_MINOR_VERSION_IP_CFG    != USDHC_AR_RELEASE_MINOR_VERSION_IP_CFG) || \
     (SD_EMMC_AR_RELEASE_REVISION_VERSION_IP_CFG != USDHC_AR_RELEASE_REVISION_VERSION_IP_CFG) \
    )
    #error "AutoSar Version Numbers of Sd_Emmc_Ip_Cfg.h and Usdhc_Ip_Cfg.h are different"
#endif
/* Check if current file and Usdhc_Ip_Cfg header file are of the same software version */
#if ((SD_EMMC_SW_MAJOR_VERSION_IP_CFG != USDHC_SW_MAJOR_VERSION_IP_CFG) || \
     (SD_EMMC_SW_MINOR_VERSION_IP_CFG != USDHC_SW_MINOR_VERSION_IP_CFG) || \
     (SD_EMMC_SW_PATCH_VERSION_IP_CFG != USDHC_SW_PATCH_VERSION_IP_CFG) \
    )
    #error "Software Version Numbers of Sd_Emmc_Ip_Cfg.h and Usdhc_Ip_Cfg.h are different"
#endif

/* Check if current file and Sd_Emmc_Ip_Types header file are of the same vendor */
#if (SD_EMMC_VENDOR_ID_IP_CFG != SD_EMMC_IP_TYPES_VENDOR_ID)
    #error "Sd_Emmc_Ip_Cfg.h and Sd_Emmc_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Sd_Emmc_Ip_Types header file are of the same Autosar version */
#if ((SD_EMMC_AR_RELEASE_MAJOR_VERSION_IP_CFG    != SD_EMMC_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SD_EMMC_AR_RELEASE_MINOR_VERSION_IP_CFG    != SD_EMMC_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SD_EMMC_AR_RELEASE_REVISION_VERSION_IP_CFG != SD_EMMC_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Sd_Emmc_Ip_Cfg.h and Sd_Emmc_Ip_Types.h are different"
#endif
/* Check if current file and Sd_Emmc_Ip_Types header file are of the same software version */
#if ((SD_EMMC_SW_MAJOR_VERSION_IP_CFG != SD_EMMC_IP_TYPES_SW_MAJOR_VERSION) || \
     (SD_EMMC_SW_MINOR_VERSION_IP_CFG != SD_EMMC_IP_TYPES_SW_MINOR_VERSION) || \
     (SD_EMMC_SW_PATCH_VERSION_IP_CFG != SD_EMMC_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Sd_Emmc_Ip_Cfg.h and Sd_Emmc_Ip_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((SD_EMMC_AR_RELEASE_MAJOR_VERSION_IP_CFG != STD_AR_RELEASE_MAJOR_VERSION) || \
         (SD_EMMC_AR_RELEASE_MINOR_VERSION_IP_CFG != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Eep.c and StandardTypes.h are different"
    #endif
#endif
/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

#define SD_IP_INSTANCE_NO                   (1U)


#define SD_IP_DEV_ERROR_DETECT                 (STD_ON)

/* @brief SD_EMMC_IP development error detect enable/disable */
#define SD_IP_DEV_ASSERT(x)                    DevAssert((x))

/*! @brief Maximum loop count to check the card operation voltage range */
#define SD_IP_SDMMC_MAX_VOLTAGE_RETRIES        (100U)

/* ! @brief Block size of the SD/eMMC device */
#define SD_IP_SDMMC_DEFAULT_BLOCK_SIZE         (512U)

/* ! @brief Page size of the SD/eMMC device. Data must be alligned to page size in case ADMA2 is used */
#define SD_IP_PAGE_SIZE_4BYTES                 (4U)

/*! @brief Maximum loop count to check the SDHC card for cmd55 */
#define SD_IP_MAX_RETRIES                      (30U)

/*! @brief Maximum loop count to check the SDHC card for cmd55 */
#define SD_IP_SEND_STATUS_RETRIES_NO           (65535U)

/*! @brief SD automatically discover frequency */
#define SD_IP_AUTO_DISCOVER_FREQUENCY          (STD_OFF)

/* Pre-processor switch to enable and disable the API for configuring eMMC card for boot */
#define SD_IP_MMC_CONFIG_BOOT_ENABLED          (STD_OFF)




/* Should be set by configuration as STD_ON if
EepDevErrorDetect exists and is also set to ON */
#define EEP_SD_IP_DEV_ERROR_DETECT             (SD_IP_DEV_ERROR_DETECT)
/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL CONSTANT DECLARATIONS
==================================================================================================*/
 #define EEP_START_SEC_CONFIG_DATA_UNSPECIFIED
 #include "Eep_MemMap.h"
 
 /*! @brief SD configurations */
 extern const Sd_Emmc_Ip_ConfigType EepSdCfg_0;
 
 #define EEP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
 #include "Eep_MemMap.h"



#ifdef __cplusplus
}
#endif

#endif /* SD_EMMC_IP_CFG_H */

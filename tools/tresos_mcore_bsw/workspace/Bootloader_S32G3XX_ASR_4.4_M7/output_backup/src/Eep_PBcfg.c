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
* @file Eep__PBcfg.c
*
* @addtogroup EEP
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
#include "Eep.h"

/* If SD Emmc IP is present on the platform */
#include "Sd_Emmc_Ip_Cfg.h"



/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EEP_VENDOR_ID_PBCFG_C                      43
#define EEP_AR_RELEASE_MAJOR_VERSION_PBCFG_C       4
#define EEP_AR_RELEASE_MINOR_VERSION_PBCFG_C       4
#define EEP_AR_RELEASE_REVISION_VERSION_PBCFG_C    0
#define EEP_SW_MAJOR_VERSION_PBCFG_C               4
#define EEP_SW_MINOR_VERSION_PBCFG_C               0
#define EEP_SW_PATCH_VERSION_PBCFG_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Eep header file are of the same vendor */
#if (EEP_VENDOR_ID_PBCFG_C != EEP_VENDOR_ID)
    #error "AutoSar Version Numbers of Eep_PBcfg.c and Eep.h have different vendor ids"
#endif
/* Check if current file and Eep header file are of the same Autosar version */
#if ((EEP_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != EEP_AR_RELEASE_MAJOR_VERSION) || \
     (EEP_AR_RELEASE_MINOR_VERSION_PBCFG_C    != EEP_AR_RELEASE_MINOR_VERSION) || \
     (EEP_AR_RELEASE_REVISION_VERSION_PBCFG_C != EEP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Eep_PBcfg.c and Eep.h are different"
#endif
/* Check if current file and Eep header file are of the same Software version */
#if ((EEP_SW_MAJOR_VERSION_PBCFG_C != EEP_SW_MAJOR_VERSION) || \
     (EEP_SW_MINOR_VERSION_PBCFG_C != EEP_SW_MINOR_VERSION) || \
     (EEP_SW_PATCH_VERSION_PBCFG_C != EEP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eep_PBcfg.c and Eep.h are different"
#endif


/* If SD Emmc IP is present on the platform */
/* Check if current file and Sd_Emmc_Ip_Cfg header file are of the same vendor */
#if (EEP_VENDOR_ID_PBCFG_C != SD_EMMC_VENDOR_ID_IP_CFG)
    #error "AutoSar Version Numbers of Eep_PBcfg.c and Sd_Emmc_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Sd_Emmc_Ip_Cfg header file are of the same Autosar version */
#if ((EEP_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != SD_EMMC_AR_RELEASE_MAJOR_VERSION_IP_CFG) || \
     (EEP_AR_RELEASE_MINOR_VERSION_PBCFG_C    != SD_EMMC_AR_RELEASE_MINOR_VERSION_IP_CFG) || \
     (EEP_AR_RELEASE_REVISION_VERSION_PBCFG_C != SD_EMMC_AR_RELEASE_REVISION_VERSION_IP_CFG) \
    )
    #error "AutoSar Version Numbers of Eep_PBcfg.c and Sd_Emmc_Ip_Cfg.h are different"
#endif
/* Check if current file and Sd_Emmc_Ip_Cfg header file are of the same Software version */
#if ((EEP_SW_MAJOR_VERSION_PBCFG_C != SD_EMMC_SW_MAJOR_VERSION_IP_CFG) || \
     (EEP_SW_MINOR_VERSION_PBCFG_C != SD_EMMC_SW_MINOR_VERSION_IP_CFG) || \
     (EEP_SW_PATCH_VERSION_PBCFG_C != SD_EMMC_SW_PATCH_VERSION_IP_CFG) \
    )
    #error "Software Version Numbers of Eep_PBcfg.c and Sd_Emmc_Ip_Cfg.h are different"
#endif





/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


                        

#define EEP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eep_MemMap.h"

/**
* @brief       Structure used to set function pointers notification, working mode
*/
const Eep_ConfigType Eep_Config =
{
    /* EepJobEndNotification             */ NULL_PTR,
    /* EepJobErrorNotification           */ NULL_PTR,
    /* EepDefaultMode                    */ MEMIF_MODE_SLOW,
    /* EepFastReadBlockSize              */ 4096U,
    /* EepNormalReadBlockSize            */ 4096U,
    /* EepFastWriteBlockSize             */ 4096U,
    /* EepNormalWriteBlockSize           */ 4096U,
    /* EEP Config Set CRC checksum       */ 6699U,
    &EepSdCfg_0};

#define EEP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eep_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @}*/

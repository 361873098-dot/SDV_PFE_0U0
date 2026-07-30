
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
#ifndef EEP_CFG_H
#define EEP_CFG_H

/**
* @file Eep_Cfg.h
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
#include "Eep_Types.h"
#include "StandardTypes.h"
#include "Sd_Emmc_Ip_Types.h"
#include "Usdhc_Ip_Types.h"
#include "Mcal.h"

#include "Eep_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EEP_VENDOR_ID_CFG                    43
#define EEP_AR_RELEASE_MAJOR_VERSION_CFG     4
#define EEP_AR_RELEASE_MINOR_VERSION_CFG     4
#define EEP_AR_RELEASE_REVISION_VERSION_CFG  0
#define EEP_SW_MAJOR_VERSION_CFG             4
#define EEP_SW_MINOR_VERSION_CFG             0
#define EEP_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Eep configuration header file are of the same vendor */
#if (EEP_TYPES_VENDOR_ID != EEP_VENDOR_ID_CFG)
    #error "Eep_Types.h and Eep_Cfg.h have different vendor ids"
#endif
/* Check if current file and Eep configuration header file are of the same Autosar version */
#if ((EEP_TYPES_AR_RELEASE_MAJOR_VERSION    != EEP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (EEP_TYPES_AR_RELEASE_MINOR_VERSION    != EEP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (EEP_TYPES_AR_RELEASE_REVISION_VERSION != EEP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Eep_Types.h and Eep_Cfg.h are different"
#endif
/* Check if current file and Eep configuration header file are of the same software version */
#if ((EEP_TYPES_SW_MAJOR_VERSION != EEP_SW_MAJOR_VERSION_CFG) || \
     (EEP_TYPES_SW_MINOR_VERSION != EEP_SW_MINOR_VERSION_CFG) || \
     (EEP_TYPES_SW_PATCH_VERSION != EEP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Eep_Types.h and Eep_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((EEP_AR_RELEASE_MAJOR_VERSION_CFG != STD_AR_RELEASE_MAJOR_VERSION) || \
         (EEP_AR_RELEASE_MINOR_VERSION_CFG != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Eep_Cfg.h and StandardTypes.h are different"
    #endif
#endif

/* Check if current file and Sd_Emmc_Ip_Types header file are of the same vendor */
#if (EEP_VENDOR_ID_CFG != SD_EMMC_IP_TYPES_VENDOR_ID)
    #error "Eep_Cfg.h and Sd_Emmc_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Sd_Emmc_Ip_Types header file are of the same Autosar version */
#if ((EEP_AR_RELEASE_MAJOR_VERSION_CFG    != SD_EMMC_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (EEP_AR_RELEASE_MINOR_VERSION_CFG    != SD_EMMC_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (EEP_AR_RELEASE_REVISION_VERSION_CFG != SD_EMMC_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Eep_Cfg.h and Sd_Emmc_Ip_Types.h are different"
#endif
/* Check if current file and Sd_Emmc_Ip_Types header file are of the same software version */
#if ((EEP_SW_MAJOR_VERSION_CFG != SD_EMMC_IP_TYPES_SW_MAJOR_VERSION) || \
     (EEP_SW_MINOR_VERSION_CFG != SD_EMMC_IP_TYPES_SW_MINOR_VERSION) || \
     (EEP_SW_PATCH_VERSION_CFG != SD_EMMC_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eep_Cfg.h and Sd_Emmc_Ip_Types.h are different"
#endif

/* Check if current file and Usdhc_Ip_Types header file are of the same vendor */
#if (EEP_VENDOR_ID_CFG != USDHC_IP_TYPES_VENDOR_ID_H)
    #error "Eep_Cfg.h and Usdhc_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Usdhc_Ip_Types header file are of the same Autosar version */
#if ((EEP_AR_RELEASE_MAJOR_VERSION_CFG    != USDHC_IP_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (EEP_AR_RELEASE_MINOR_VERSION_CFG    != USDHC_IP_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (EEP_AR_RELEASE_REVISION_VERSION_CFG != USDHC_IP_TYPES_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Eep_Cfg.h and Usdhc_Ip_Types.h are different"
#endif
/* Check if current file and Usdhc_Ip_Types header file are of the same software version */
#if ((EEP_SW_MAJOR_VERSION_CFG != USDHC_IP_TYPES_SW_MAJOR_VERSION_H) || \
     (EEP_SW_MINOR_VERSION_CFG != USDHC_IP_TYPES_SW_MINOR_VERSION_H) || \
     (EEP_SW_PATCH_VERSION_CFG != USDHC_IP_TYPES_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Eep_Cfg.h and Usdhc_Ip_Types.h are different"
#endif


#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal header file are of the same version */
    #if ((EEP_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (EEP_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION)\
        )
        #error "AutoSar Version Numbers of Eep_Cfg.h and Mcal.h are different"
    #endif
#endif



/* Check if current file and Eep_PBcfg header file are of the same vendor */
#if (EEP_VENDOR_ID_CFG != EEP_PBCFG_VENDOR_ID)
    #error "Eep_Cfg.h and Eep_PBcfg.h have different vendor ids"
#endif
/* Check if current file and Eep_PBcfg header file are of the same Autosar version */
#if ((EEP_AR_RELEASE_MAJOR_VERSION_CFG    != EEP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (EEP_AR_RELEASE_MINOR_VERSION_CFG    != EEP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (EEP_AR_RELEASE_REVISION_VERSION_CFG != EEP_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Eep_Cfg.h and Eep_PBcfg.h are different"
#endif
/* Check if current file and Eep_PBcfg header file are of the same software version */
#if ((EEP_SW_MAJOR_VERSION_CFG != EEP_PBCFG_SW_MAJOR_VERSION) || \
     (EEP_SW_MINOR_VERSION_CFG != EEP_PBCFG_SW_MINOR_VERSION) || \
     (EEP_SW_PATCH_VERSION_CFG != EEP_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eep_Cfg.h and Eep_PBcfg.h are different"
#endif




/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/**
* @brief   Switches the Production Error Detection and Notification OFF
*/
#define EEP_DISABLE_DEM_REPORT_ERROR_STATUS      (STD_ON)


/* Compile switch to enable and disable the Eep_Cancel function */
#define EEP_CANCEL_API              (STD_ON)

#define EEP_COMPARE_API             (STD_ON)

/* Pre-processor switch to enable and disable development error detection */
#define EEP_DEV_ERROR_DETECT        (STD_ON)

/* Compile switch to enable and disable the Eep_GetJobResult function */
#define EEP_GET_JOB_RESULT_API      (STD_ON)

/* Compile switch to enable and disable the Eep_GetStatus function */
#define EEP_GET_STATUS_API          (STD_ON)

/* Compile switch to enable and disable the Eep_SetMode function */
#define EEP_SET_MODE_API            (STD_ON)

/* Pre-processor switch to enable / disable the API to read out the modules version information */
#define EEP_VERSION_INFO_API        (STD_ON)


/* Pre-processor switch to enable and disable the API for MMC boot feature */
#define EEP_MMC_BOOT_ENABLED                    (STD_OFF)

/* Pre-processor switch to enable and disable the API for configuring eMMC card for boot */
#define EEP_MMC_CONFIG_BOOT_ENABLED             (STD_OFF)

/* Pre-processor switch to enable / disable the Eep_SwitchPartitionAccess function */
#define EEP_SWITCHPARTITIONACCESS_API           (STD_OFF)

/* defines if the write operation will be executed in asynchronous mode or not*/
#define EEP_ASYNC_WRITE_OPERATIONS_ENABLED       (STD_OFF) 
/* defines if the Erase operation will be executed in asynchronous mode or not*/
#define EEP_ASYNC_ERASE_OPERATIONS_ENABLED       (STD_OFF) 

/* Enable multi cores feature. */
#define EEP_MCORE_ENABLED                     (STD_OFF)

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief          Eep Config Type
* @details        Eep module initialization data structure
* @implements     Eep_ConfigType_typedef
*
*/
typedef struct
{
    /**
    * @brief pointer to job end notification function
    */
    Eep_JobEndNotificationPtrType jobEndNotificationPtr;
    /**
    * @brief pointer to job error notification function
    */
    Eep_JobErrorNotificationPtrType jobErrorNotificationPtr;
    /**
    * @brief default EEP device mode after initialization (MEMIF_MODE_FAST, MEMIF_MODE_SLOW)
    */
    MemIf_ModeType eDefaultMode;
    /**
    * @brief max number of bytes to read in one cycle of Eep_MainFunction (fast mode)
    */
    Eep_LengthType u32MaxReadFastMode;
    /**
    * @brief max number of bytes to read in one cycle of  Eep_MainFunction (normal mode)
    */
    Eep_LengthType u32MaxReadNormalMode;
    /**
    * @brief max number of bytes to write in one cycle of Eep_MainFunction (fast mode)
    */
    Eep_LengthType u32MaxWriteFastMode;
    /**
    * @brief max number of bytes to write in one cycle of  Eep_MainFunction (normal mode)
    */
    Eep_LengthType u32MaxWriteNormalMode;

    /**
     * @brief EEP Config Set CRC checksum
     */
    Eep_CrcType u16ConfigCrc;
    /**
      * @brief SD Ip configuration pointer
    **/
    const Sd_Emmc_Ip_ConfigType * pEepSdConfig;

} Eep_ConfigType;

typedef Sd_Ip_MmcPartitionAccessType Eep_MmcPartitionAccessType;

/*==================================================================================================
                                 GLOBAL CONSTANT DECLARATIONS
==================================================================================================*/
#define EEP_CONFIG_EXT \
    EEP_CONFIG_PB


#ifdef __cplusplus
}
#endif

#endif /* EEP_CFG_H */

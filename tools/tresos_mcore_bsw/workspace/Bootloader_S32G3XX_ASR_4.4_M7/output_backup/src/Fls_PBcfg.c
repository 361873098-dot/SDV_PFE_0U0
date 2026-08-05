/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : IPV_QSPI
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

/**
*   @file Fls_PBcfg.c
*
*   @addtogroup FLS
*   @{
*/

/* implements Fls_PBcfg.c_Artifact */

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fls.h"
#include "Qspi_Ip_Features.h"
#include "Qspi_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_VENDOR_ID_CFG_C                      43
#define FLS_AR_RELEASE_MAJOR_VERSION_CFG_C       4
#define FLS_AR_RELEASE_MINOR_VERSION_CFG_C       4
#define FLS_AR_RELEASE_REVISION_VERSION_CFG_C    0
#define FLS_SW_MAJOR_VERSION_CFG_C               4
#define FLS_SW_MINOR_VERSION_CFG_C               0
#define FLS_SW_PATCH_VERSION_CFG_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls header file are of the same vendor */
#if (FLS_VENDOR_ID_CFG_C != FLS_VENDOR_ID)
    #error "Fls_PBcfg.c and Fls.h have different vendor ids"
#endif
/* Check if current file and Fls header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG_C    != FLS_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AR_RELEASE_MINOR_VERSION_CFG_C    != FLS_AR_RELEASE_MINOR_VERSION) || \
     (FLS_AR_RELEASE_REVISION_VERSION_CFG_C != FLS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fls_PBcfg.c and Fls.h are different"
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_CFG_C != FLS_SW_MAJOR_VERSION) || \
     (FLS_SW_MINOR_VERSION_CFG_C != FLS_SW_MINOR_VERSION) || \
     (FLS_SW_PATCH_VERSION_CFG_C != FLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_PBcfg.c and Fls.h are different"
#endif

/* Check if current file and Qspi_Ip_Features header file are of the same vendor */
#if (FLS_VENDOR_ID_CFG_C != QSPI_IP_FEATURES_VENDOR_ID_CFG)
    #error "Fls_PBcfg.c and Qspi_Ip_Features.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Features header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG_C    != QSPI_IP_FEATURES_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FLS_AR_RELEASE_MINOR_VERSION_CFG_C    != QSPI_IP_FEATURES_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FLS_AR_RELEASE_REVISION_VERSION_CFG_C != QSPI_IP_FEATURES_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Fls_PBcfg.c and Qspi_Ip_Features.h are different"
#endif
/* Check if current file and Qspi_Ip_Features header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_CFG_C != QSPI_IP_FEATURES_SW_MAJOR_VERSION_CFG) || \
     (FLS_SW_MINOR_VERSION_CFG_C != QSPI_IP_FEATURES_SW_MINOR_VERSION_CFG) || \
     (FLS_SW_PATCH_VERSION_CFG_C != QSPI_IP_FEATURES_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Fls_PBcfg.c and Qspi_Ip_Features.h are different"
#endif

/* Check if current file and Qspi_Ip_Cfg header file are of the same vendor */
#if (FLS_VENDOR_ID_CFG_C != QSPI_IP_VENDOR_ID_CFG)
    #error "Fls_PBcfg.c and Qspi_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Cfg header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG_C    != QSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FLS_AR_RELEASE_MINOR_VERSION_CFG_C    != QSPI_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FLS_AR_RELEASE_REVISION_VERSION_CFG_C != QSPI_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Fls_PBcfg.c and Qspi_Ip_Cfg.h are different"
#endif
/* Check if current file and Qspi_Ip_Cfg header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_CFG_C != QSPI_IP_SW_MAJOR_VERSION_CFG) || \
     (FLS_SW_MINOR_VERSION_CFG_C != QSPI_IP_SW_MINOR_VERSION_CFG) || \
     (FLS_SW_PATCH_VERSION_CFG_C != QSPI_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Fls_PBcfg.c and Qspi_Ip_Cfg.h are different"
#endif

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

            
        
#define FLS_START_SEC_CONFIG_DATA_8
#include "Fls_MemMap.h"

/* aFlsSectorFlags */
static const uint8 FlsConfigSet_aFlsSectorFlags[8U] =
{
    0U,  /* FlsSector_0 */
    0U,  /* FlsSector_1 */
    0U,  /* FlsSector_2 */
    0U,  /* FlsSector_3 */
    0U,  /* FlsSector_4 */
    0U,  /* FlsSector_5 */
    0U,  /* FlsSector_6 */
    0U   /* FlsSector_7 */
};

#define FLS_STOP_SEC_CONFIG_DATA_8
#include "Fls_MemMap.h"



#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"

/* aFlsSectorEndAddr */
static const Fls_AddressType FlsConfigSet_aFlsSectorEndAddr[8U] =
{
    (Fls_AddressType)4095U,  /* FlsSector_0 */
    (Fls_AddressType)786431U,  /* FlsSector_1 */
    (Fls_AddressType)790527U,  /* FlsSector_2 */
    (Fls_AddressType)794623U,  /* FlsSector_3 */
    (Fls_AddressType)798719U,  /* FlsSector_4 */
    (Fls_AddressType)802815U,  /* FlsSector_5 */
    (Fls_AddressType)806911U,  /* FlsSector_6 */
    (Fls_AddressType)811007U   /* FlsSector_7 */
};

/* paSectorSize */
static const Fls_LengthType FlsConfigSet_aFlsSectorSize[8U] =
{
    (Fls_LengthType)4096U,  /* FlsSector_0 */
    (Fls_LengthType)782336U,  /* FlsSector_1 */
    (Fls_LengthType)4096U,  /* FlsSector_2 */
    (Fls_LengthType)4096U,  /* FlsSector_3 */
    (Fls_LengthType)4096U,  /* FlsSector_4 */
    (Fls_LengthType)4096U,  /* FlsSector_5 */
    (Fls_LengthType)4096U,  /* FlsSector_6 */
    (Fls_LengthType)4096U   /* FlsSector_7 */
};

/* paSectorPageSize */
static const Fls_LengthType FlsConfigSet_aFlsSectorPageSize[8U] =
{
    (Fls_LengthType)16U,  /* FlsSector_0 */
    (Fls_LengthType)16U,  /* FlsSector_1 */
    (Fls_LengthType)16U,  /* FlsSector_2 */
    (Fls_LengthType)16U,  /* FlsSector_3 */
    (Fls_LengthType)16U,  /* FlsSector_4 */
    (Fls_LengthType)16U,  /* FlsSector_5 */
    (Fls_LengthType)16U,  /* FlsSector_6 */
    (Fls_LengthType)16U   /* FlsSector_7 */
};


/* paHwCh */
static const Fls_HwChType FlsConfigSet_paHwCh[8U] =
{
    FLS_CH_QSPI,  /* FlsSector_0 */
    FLS_CH_QSPI,  /* FlsSector_1 */
    FLS_CH_QSPI,  /* FlsSector_2 */
    FLS_CH_QSPI,  /* FlsSector_3 */
    FLS_CH_QSPI,  /* FlsSector_4 */
    FLS_CH_QSPI,  /* FlsSector_5 */
    FLS_CH_QSPI,  /* FlsSector_6 */
    FLS_CH_QSPI   /* FlsSector_7 */
};

/* paSectorHwAddress */
static const Fls_AddressType FlsConfigSet_paSectorHwAddress[8U] =
{
    (Fls_AddressType)0U,  /* FlsSector_0 */
    (Fls_AddressType)782336U,  /* FlsSector_1 */
    (Fls_AddressType)786432U,  /* FlsSector_2 */
    (Fls_AddressType)790528U,  /* FlsSector_3 */
    (Fls_AddressType)794624U,  /* FlsSector_4 */
    (Fls_AddressType)798720U,  /* FlsSector_5 */
    (Fls_AddressType)802816U,  /* FlsSector_6 */
    (Fls_AddressType)806912U   /* FlsSector_7 */
};

/* External QSPI flash parameters. */

/* u8SectFlashUnit */
static const uint8 FlsConfigSet_u8SectFlashUnit[8U] =
{
    (uint8)0U,  /* FlsSector_0 */
    (uint8)0U,  /* FlsSector_1 */
    (uint8)0U,  /* FlsSector_2 */
    (uint8)0U,  /* FlsSector_3 */
    (uint8)0U,  /* FlsSector_4 */
    (uint8)0U,  /* FlsSector_5 */
    (uint8)0U,  /* FlsSector_6 */
    (uint8)0U  /* FlsSector_7 */
};

/* u8QspiConfig */
static const uint8 FlsConfigSet_u8QspiConfig[1U] =
{
    1U
};

/* u8FlashConfig */
static const uint8 FlsConfigSet_u8FlashConfig[1U] =
{
    0U   /* uses FlsMemCfg */
};

/* paAHBReadCfg */
static const boolean FlsConfigSet_paAHBReadCfg[1U] =
{
    (boolean)TRUE
};

/* pFlsQspiCfgConfig */
static const Fls_QspiCfgConfigType Fls_QspiConfigSet =
{
    &FlsConfigSet_u8SectFlashUnit,                                    /* (*u8SectFlashUnit)[] */
    1U,                                                               /* u8FlashUnitsCount */
    &FlsConfigSet_paFlashConnectionCfg,                               /* (*paFlashConnectionCfg)[] */
    &FlsConfigSet_u8FlashConfig,                                      /* (*u8FlashConfig)[] */
    &FlsConfigSet_paAHBReadCfg,                                       /* (*paAHBReadCfg)[] */
    1U,                                                               /* u8FlashConfigCount */
    &FlsConfigSet_paFlashCfg,                                         /* (*paFlashCfg)[] */
    1U,                                                               /* u8QspiUnitsCount */
    &FlsConfigSet_u8QspiConfig,                                       /* (*u8QspiConfig)[] */
    2U,                                                               /* u8QspiConfigCount */
    &FlsConfigSet_paQspiUnitCfg                                       /* (*paQspiUnitCfg)[] */
};


/**
* @brief        Structure used to set function pointers notification, working mode
*/
/* Fls module initialization data (FlsConfigSet)*/
const Fls_ConfigType Fls_Config =
{
    NULL_PTR,                                                         /* FlsJobEndNotification */
    NULL_PTR,                                                         /* FlsJobErrorNotification */
    NULL_PTR,                                                         /* FlsMCoreTimeoutNotification */
    MEMIF_MODE_SLOW,                                                  /* FlsDefaultMode */
    1024U,                                                            /* FlsMaxReadFastMode */
    512U,                                                             /* FlsMaxReadNormalMode */
    1024U,                                                            /* FlsMaxWriteFastMode */
    320U,                                                             /* FlsMaxWriteNormalMode */
    8U,                                                               /* FlsSectorCount */
    &FlsConfigSet_aFlsSectorEndAddr,                                  /* (*paSectorEndAddr)[] */
    &FlsConfigSet_aFlsSectorSize,                                     /* (*paSectorSize)[] */
    &FlsConfigSet_aFlsSectorFlags,                                    /* (*paSectorFlags)[] */
    &FlsConfigSet_aFlsSectorPageSize,                                 /* (*paSectorPageSize)[] */
    &FlsConfigSet_paHwCh,                                             /* (*paHwCh)[] */
    &FlsConfigSet_paSectorHwAddress,                                  /* (*paSectorHwAddress)[] */
    &Fls_QspiConfigSet,                                               /* FlsQspiConfig */
    6875U                                                             /* configCrc */
};


#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @}*/


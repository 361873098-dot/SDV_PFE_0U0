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

/**   
*   @file    Spi_Ipw_VS_0_PBcfg.c
*   @version 4.0.2
*
*   @brief   AUTOSAR Spi - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup SPI_DRIVER_CONFIGURATION Spi Driver Configuration
*   @{
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
#include "Spi_Ipw_VS_0_PBcfg.h"
#include "Spi_Ip_Cfg.h"
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (STD_ON == LPSPI_IP_LLCE_SUPPORT)
#include "Lpspi_Ip_Cfg.h"
#endif
#endif
#include "Spi.h"


/*==================================================================================================
*                                    SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_IPW_VS_0_VENDOR_ID_PBCFG_C                        43
#define SPI_IPW_VS_0_AR_RELEASE_MAJOR_VERSION_PBCFG_C         4
#define SPI_IPW_VS_0_AR_RELEASE_MINOR_VERSION_PBCFG_C         4
#define SPI_IPW_VS_0_AR_RELEASE_REVISION_VERSION_PBCFG_C      0
#define SPI_IPW_VS_0_SW_MAJOR_VERSION_PBCFG_C                 4
#define SPI_IPW_VS_0_SW_MINOR_VERSION_PBCFG_C                 0
#define SPI_IPW_VS_0_SW_PATCH_VERSION_PBCFG_C                 2
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Spi_Ipw_PBcfg.h and Spi_Ipw_PBcfg.c are of the same vendor */
#if (SPI_IPW_VENDOR_ID_VS_0_PBCFG_H != SPI_IPW_VS_0_VENDOR_ID_PBCFG_C)
    #error "Spi_Ipw_PBcfg.h and Spi_Ipw_PBcfg.c have different vendor ids"
#endif
/* Check if Spi_Ipw_PBcfg.h file and Spi_Ipw_PBcfg.c file are of the same Autosar version */
#if ((SPI_IPW_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG_H != SPI_IPW_VS_0_AR_RELEASE_MAJOR_VERSION_PBCFG_C) || \
     (SPI_IPW_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG_H != SPI_IPW_VS_0_AR_RELEASE_MINOR_VERSION_PBCFG_C) || \
     (SPI_IPW_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG_H != SPI_IPW_VS_0_AR_RELEASE_REVISION_VERSION_PBCFG_C))
#error "AutoSar Version Numbers of Spi_Ipw_PBcfg.h and Spi_Ipw_PBcfg.c are different"
#endif
#if ((SPI_IPW_SW_MAJOR_VERSION_VS_0_PBCFG_H != SPI_IPW_VS_0_SW_MAJOR_VERSION_PBCFG_C) || \
     (SPI_IPW_SW_MINOR_VERSION_VS_0_PBCFG_H != SPI_IPW_VS_0_SW_MINOR_VERSION_PBCFG_C) || \
     (SPI_IPW_SW_PATCH_VERSION_VS_0_PBCFG_H != SPI_IPW_VS_0_SW_PATCH_VERSION_PBCFG_C))
#error "Software Version Numbers of Spi_Ipw_PBcfg.h and Spi_Ipw_PBcfg.c are different"
#endif

/* Check if Spi_Ip_Cfg.h and Spi_Ipw_PBcfg.c are of the same vendor */
#if (SPI_IP_VENDOR_ID_CFG != SPI_IPW_VS_0_VENDOR_ID_PBCFG_C)
    #error "Spi_Ip_Cfg.h and Spi_Ipw_PBcfg.c have different vendor ids"
#endif
/* Check if Spi_Ip_Cfg.h file and Spi_Ipw_PBcfg.c file are of the same Autosar version */
#if ((SPI_IP_AR_RELEASE_MAJOR_VERSION_CFG != SPI_IPW_VS_0_AR_RELEASE_MAJOR_VERSION_PBCFG_C) || \
     (SPI_IP_AR_RELEASE_MINOR_VERSION_CFG != SPI_IPW_VS_0_AR_RELEASE_MINOR_VERSION_PBCFG_C) || \
     (SPI_IP_AR_RELEASE_REVISION_VERSION_CFG != SPI_IPW_VS_0_AR_RELEASE_REVISION_VERSION_PBCFG_C))
#error "AutoSar Version Numbers of Spi_Ip_Cfg.h and Spi_Ipw_PBcfg.c are different"
#endif
#if ((SPI_IP_SW_MAJOR_VERSION_CFG != SPI_IPW_VS_0_SW_MAJOR_VERSION_PBCFG_C) || \
     (SPI_IP_SW_MINOR_VERSION_CFG != SPI_IPW_VS_0_SW_MINOR_VERSION_PBCFG_C) || \
     (SPI_IP_SW_PATCH_VERSION_CFG != SPI_IPW_VS_0_SW_PATCH_VERSION_PBCFG_C))
#error "Software Version Numbers of Spi_Ip_Cfg.h and Spi_Ipw_PBcfg.c are different"
#endif

/* Check if Spi.h and Spi_Ipw_PBcfg.c are of the same vendor */
#if (SPI_VENDOR_ID != SPI_IPW_VS_0_VENDOR_ID_PBCFG_C)
    #error "Spi.h and Spi_Ipw_PBcfg.c have different vendor ids"
#endif
/* Check if Spi.h file and Spi_Ipw_PBcfg.c file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION != SPI_IPW_VS_0_AR_RELEASE_MAJOR_VERSION_PBCFG_C) || \
     (SPI_AR_RELEASE_MINOR_VERSION != SPI_IPW_VS_0_AR_RELEASE_MINOR_VERSION_PBCFG_C) || \
     (SPI_AR_RELEASE_REVISION_VERSION != SPI_IPW_VS_0_AR_RELEASE_REVISION_VERSION_PBCFG_C))
#error "AutoSar Version Numbers of Spi.h and Spi_Ipw_PBcfg.c are different"
#endif
#if ((SPI_SW_MAJOR_VERSION != SPI_IPW_VS_0_SW_MAJOR_VERSION_PBCFG_C) || \
     (SPI_SW_MINOR_VERSION != SPI_IPW_VS_0_SW_MINOR_VERSION_PBCFG_C) || \
     (SPI_SW_PATCH_VERSION != SPI_IPW_VS_0_SW_PATCH_VERSION_PBCFG_C))
#error "Software Version Numbers of Spi.h and Spi_Ipw_PBcfg.c are different"
#endif
/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"


#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

/* External device Configuration of SpiExternalDevice_SJA1105Q*/
static const Spi_ExternalDeviceConfigType Spi_ExternalDeviceConfig_SpiExternalDevice_SJA1105Q_VS_0 =
{
        /* SpiExternalDevice_SJA1105Q*/
        SPI_OVER_SPI, /* IpType */
        5U,  /* Instance */
        
        {   /* ExternalDeviceConfig */
            &Spi_Ip_DeviceAttributes_SpiExternalDevice_SJA1105Q_VS_0 /* SPI ExternalDeviceConfig */
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (STD_ON == LPSPI_IP_LLCE_SUPPORT)
            ,NULL_PTR /* Don't have LPSPI ExternalDeviceConfig */       
#endif
#endif  
        },
        
        SPI_SPURIOUS_CORE_ID_U32};
/* External device Configuration of SpiExternalDevice_SJA1110a*/
static const Spi_ExternalDeviceConfigType Spi_ExternalDeviceConfig_SpiExternalDevice_SJA1110a_VS_0 =
{
        /* SpiExternalDevice_SJA1110a*/
        SPI_OVER_SPI, /* IpType */
        4U,  /* Instance */
        
        {   /* ExternalDeviceConfig */
            &Spi_Ip_DeviceAttributes_SpiExternalDevice_SJA1110a_VS_0 /* SPI ExternalDeviceConfig */
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (STD_ON == LPSPI_IP_LLCE_SUPPORT)
            ,NULL_PTR /* Don't have LPSPI ExternalDeviceConfig */       
#endif
#endif  
        },
        
        SPI_SPURIOUS_CORE_ID_U32};
/* External device Configuration of SpiExternalDevice_SJA1110b*/
static const Spi_ExternalDeviceConfigType Spi_ExternalDeviceConfig_SpiExternalDevice_SJA1110b_VS_0 =
{
        /* SpiExternalDevice_SJA1110b*/
        SPI_OVER_SPI, /* IpType */
        4U,  /* Instance */
        
        {   /* ExternalDeviceConfig */
            &Spi_Ip_DeviceAttributes_SpiExternalDevice_SJA1110b_VS_0 /* SPI ExternalDeviceConfig */
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (STD_ON == LPSPI_IP_LLCE_SUPPORT)
            ,NULL_PTR /* Don't have LPSPI ExternalDeviceConfig */       
#endif
#endif  
        },
        
        SPI_SPURIOUS_CORE_ID_U32};
/* Spi_apExternalDeviceConfigList_VS_0 External device Configuration of Spi*/
const Spi_ExDevicesConfigType Spi_aExternalDeviceConfigList_VS_0[3U] =
{
    {
    /* SpiExternalDevice_SJA1105Q */
    &Spi_ExternalDeviceConfig_SpiExternalDevice_SJA1105Q_VS_0
    },
    {
    /* SpiExternalDevice_SJA1110a */
    &Spi_ExternalDeviceConfig_SpiExternalDevice_SJA1110a_VS_0
    },
    {
    /* SpiExternalDevice_SJA1110b */
    &Spi_ExternalDeviceConfig_SpiExternalDevice_SJA1110b_VS_0
    }
};

/* Hardware Unit configuration for SpiPhyUnit_0 */
static const Spi_HWUnitConfigType Spi_HwUnitConfig_SpiPhyUnit_0_VS_0 =
{
        SPI_OVER_SPI, /* IpType */
        (uint8)5U, /* Instance */
        SPI_SPURIOUS_CORE_ID_U32, /* SpiCoreUse */
        {

            &Spi_Ip_PhyUnitConfig_SpiPhyUnit_0_VS_0 /* SPI IpConfig */
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (STD_ON == LPSPI_IP_LLCE_SUPPORT)
            ,NULL_PTR /* Don't have Ipconfig of Lpspi */
#endif
#endif
            #if ((SPI_IPW_DMA_USED == STD_ON) && (SPI_IPW_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
            ,NULL_PTR
            #endif
        },
        SPI_PHYUNIT_ASYNC_U32 /* IsSync */
};
/* Hardware Unit configuration for SpiPhyUnit_1 */
static const Spi_HWUnitConfigType Spi_HwUnitConfig_SpiPhyUnit_1_VS_0 =
{
        SPI_OVER_SPI, /* IpType */
        (uint8)4U, /* Instance */
        SPI_SPURIOUS_CORE_ID_U32, /* SpiCoreUse */
        {

            &Spi_Ip_PhyUnitConfig_SpiPhyUnit_1_VS_0 /* SPI IpConfig */
#ifdef LPSPI_IP_LLCE_SUPPORT
#if (STD_ON == LPSPI_IP_LLCE_SUPPORT)
            ,NULL_PTR /* Don't have Ipconfig of Lpspi */
#endif
#endif
            #if ((SPI_IPW_DMA_USED == STD_ON) && (SPI_IPW_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
            ,NULL_PTR
            #endif
        },
        SPI_PHYUNIT_ASYNC_U32 /* IsSync */
};
/* Array of Hardware Unit configurations */
const Spi_PhyUnitsConfigType Spi_aHwUnitConfigList_VS_0[SPI_MAX_HWUNIT] =
{
    /* SpiPhyUnit_0 */
    {
    &Spi_HwUnitConfig_SpiPhyUnit_0_VS_0
    },
    /* SpiPhyUnit_1 */
    {
    &Spi_HwUnitConfig_SpiPhyUnit_1_VS_0
    }
};

#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */


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
*   @file    Spi_Ip_VS_0_PBcfg.c
*   @version 4.0.2
*
*   @brief   AUTOSAR Spi - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup SPI_IP_DRIVER_CONFIGURATION Spi Ip Driver Configuration
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
#include "Spi_Ip.h"
#if (SPI_IP_DMA_USED == STD_ON)
#include "Dma_Ip.h"
#endif
/*==================================================================================================
*                                    SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SPI_IP_VS_0_MODULE_ID_PBCFG_C                        83
#define SPI_IP_VS_0_VENDOR_ID_PBCFG_C                        43
#define SPI_IP_VS_0_AR_RELEASE_MAJOR_VERSION_PBCFG_C         4
#define SPI_IP_VS_0_AR_RELEASE_MINOR_VERSION_PBCFG_C         4
#define SPI_IP_VS_0_AR_RELEASE_REVISION_VERSION_PBCFG_C      0
#define SPI_IP_VS_0_SW_MAJOR_VERSION_PBCFG_C                 4
#define SPI_IP_VS_0_SW_MINOR_VERSION_PBCFG_C                 0
#define SPI_IP_VS_0_SW_PATCH_VERSION_PBCFG_C                 2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Spi_Ip.h and Spi_Ip_PBcfg.c are of the same vendor */
#if (SPI_IP_VENDOR_ID != SPI_IP_VS_0_VENDOR_ID_PBCFG_C)
    #error "Spi_Ip.h and Spi_Ip_PBcfg.c have different vendor ids"
#endif
/* Check if Spi_Ip.h file and Spi_Ip_PBcfg.c file are of the same Autosar version */
#if ((SPI_IP_AR_RELEASE_MAJOR_VERSION != SPI_IP_VS_0_AR_RELEASE_MAJOR_VERSION_PBCFG_C) || \
     (SPI_IP_AR_RELEASE_MINOR_VERSION != SPI_IP_VS_0_AR_RELEASE_MINOR_VERSION_PBCFG_C) || \
     (SPI_IP_AR_RELEASE_REVISION_VERSION != SPI_IP_VS_0_AR_RELEASE_REVISION_VERSION_PBCFG_C))
#error "AutoSar Version Numbers of Spi_Ip.h and Spi_Ip_PBcfg.c are different"
#endif
#if ((SPI_IP_SW_MAJOR_VERSION != SPI_IP_VS_0_SW_MAJOR_VERSION_PBCFG_C) || \
     (SPI_IP_SW_MINOR_VERSION != SPI_IP_VS_0_SW_MINOR_VERSION_PBCFG_C) || \
     (SPI_IP_SW_PATCH_VERSION != SPI_IP_VS_0_SW_PATCH_VERSION_PBCFG_C))
#error "Software Version Numbers of Spi_Ip.h and Spi_Ip_PBcfg.c are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (SPI_IP_DMA_USED == STD_ON)
         /* Check if current file and Dma_Ip header file are of the same Autosar version */
        #if ((DMA_IP_AR_RELEASE_MAJOR_VERSION != SPI_IP_VS_0_AR_RELEASE_MAJOR_VERSION_PBCFG_C) || \
             (DMA_IP_AR_RELEASE_MINOR_VERSION != SPI_IP_VS_0_AR_RELEASE_MINOR_VERSION_PBCFG_C))
        #error "AutoSar Version Numbers of Spi_Ip_PBcfg.c and Dma_Ip.h are different"
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
#if (SPI_IP_DMA_USED == STD_ON)
    #define SPI_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#else
    #define SPI_START_SEC_VAR_INIT_UNSPECIFIED
#endif
#include "Spi_MemMap.h"

/* Spi_Ip_DeviceParamsCfg_VS_0 Device Attribute Configuration of Spi*/
static Spi_Ip_DeviceParamsType Spi_Ip_DeviceParamsCfg_VS_0[3U] =
{

    {
        (uint8)8UL, /* Frame size - dummy value */
        (boolean)TRUE, /*Lsb - dummy value */
        (uint32)1U  /* Default Data - dummy value */
    },        
    {
        (uint8)8UL, /* Frame size - dummy value */
        (boolean)TRUE, /*Lsb - dummy value */
        (uint32)1U  /* Default Data - dummy value */
    },        
    {
        (uint8)8UL, /* Frame size - dummy value */
        (boolean)TRUE, /*Lsb - dummy value */
        (uint32)1U  /* Default Data - dummy value */
    }        
};

#if (SPI_IP_DMA_USED == STD_ON)
    #define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#else
    #define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
#endif
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Spi_MemMap.h"


#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Spi_MemMap.h"

#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

/* Spi_Ip_DeviceAttributes_VS_0 Device Attribute Configuration of Spi*/
const Spi_Ip_ExternalDeviceType Spi_Ip_DeviceAttributes_SpiExternalDevice_SJA1105Q_VS_0 =
{
    
    5U,  /* Instance */
    /* ctar */
    (uint32)(SPI_CTAR_CPOL(0U) | /* Clock Polarity (Idle State) */
    SPI_CTAR_CPHA(1U) | /* Clock Phase */
    SPI_CTAR_PCSSCK(2U) | SPI_CTAR_CSSCK(3U) | /* TimeCs2Clk: Should=200ns, Is=201, Error=0.85% */
    SPI_CTAR_PASC(2U) | SPI_CTAR_ASC(3U) | /* TimeClk2Cs: Should=200ns, Is=201, Error=0.85% */
    SPI_CTAR_PDT(2U) | SPI_CTAR_DT(4U) | /* TimeCs2Cs: Should=400ns, Is=403, Error=0.85% */
    SPI_CTAR_PBR(2U) | SPI_CTAR_BR(4U) | SPI_CTAR_DBR(0u)), /* Baudrate: Should=5000000.0, Is=4957627, Error=-0.85% */
    (uint32)(SPI_CTARE_FMSZE(0U) | SPI_CTARE_DTCP(1U)), /* ctare */
    /* pushCmd */
    (uint16)((SPI_PUSHR_CTAS(0U)|    /* Use CTAR0 */
    SPI_PUSHR_PCS(1) | /* Chip Select Pin Via Peripheral Engine*/     
    SPI_PUSHR_CONT(1U) /* Continuous chip select */
    )>>16u),
    &Spi_Ip_DeviceParamsCfg_VS_0[0U]

};
/* Spi_Ip_DeviceAttributes_VS_0 Device Attribute Configuration of Spi*/
const Spi_Ip_ExternalDeviceType Spi_Ip_DeviceAttributes_SpiExternalDevice_SJA1110a_VS_0 =
{
    
    4U,  /* Instance */
    /* ctar */
    (uint32)(SPI_CTAR_CPOL(0U) | /* Clock Polarity (Idle State) */
    SPI_CTAR_CPHA(0U) | /* Clock Phase */
    SPI_CTAR_PCSSCK(2U) | SPI_CTAR_CSSCK(0U) | /* TimeCs2Clk: Should=200ns, Is=208, Error=4.17% */
    SPI_CTAR_PASC(2U) | SPI_CTAR_ASC(0U) | /* TimeClk2Cs: Should=200ns, Is=208, Error=4.17% */
    SPI_CTAR_PDT(2U) | SPI_CTAR_DT(1U) | /* TimeCs2Cs: Should=400ns, Is=416, Error=4.17% */
    SPI_CTAR_PBR(2U) | SPI_CTAR_BR(0U) | SPI_CTAR_DBR(0u)), /* Baudrate: Should=5000000.0, Is=4800000, Error=-4.0% */
    (uint32)(SPI_CTARE_FMSZE(0U) | SPI_CTARE_DTCP(1U)), /* ctare */
    /* pushCmd */
    (uint16)((SPI_PUSHR_CTAS(0U)|    /* Use CTAR0 */
    SPI_PUSHR_PCS(1) | /* Chip Select Pin Via Peripheral Engine*/     
    SPI_PUSHR_CONT(1U) /* Continuous chip select */
    )>>16u),
    &Spi_Ip_DeviceParamsCfg_VS_0[1U]

};
/* Spi_Ip_DeviceAttributes_VS_0 Device Attribute Configuration of Spi*/
const Spi_Ip_ExternalDeviceType Spi_Ip_DeviceAttributes_SpiExternalDevice_SJA1110b_VS_0 =
{
    
    4U,  /* Instance */
    /* ctar */
    (uint32)(SPI_CTAR_CPOL(1U) | /* Clock Polarity (Idle State) */
    SPI_CTAR_CPHA(0U) | /* Clock Phase */
    SPI_CTAR_PCSSCK(2U) | SPI_CTAR_CSSCK(0U) | /* TimeCs2Clk: Should=200ns, Is=208, Error=4.17% */
    SPI_CTAR_PASC(2U) | SPI_CTAR_ASC(0U) | /* TimeClk2Cs: Should=200ns, Is=208, Error=4.17% */
    SPI_CTAR_PDT(2U) | SPI_CTAR_DT(1U) | /* TimeCs2Cs: Should=400ns, Is=416, Error=4.17% */
    SPI_CTAR_PBR(2U) | SPI_CTAR_BR(0U) | SPI_CTAR_DBR(0u)), /* Baudrate: Should=5000000.0, Is=4800000, Error=-4.0% */
    (uint32)(SPI_CTARE_FMSZE(0U) | SPI_CTARE_DTCP(1U)), /* ctare */
    /* pushCmd */
    (uint16)((SPI_PUSHR_CTAS(0U)|    /* Use CTAR0 */
    SPI_PUSHR_PCS(2) | /* Chip Select Pin Via Peripheral Engine*/     
    SPI_PUSHR_CONT(1U) /* Continuous chip select */
    )>>16u),
    &Spi_Ip_DeviceParamsCfg_VS_0[2U]

};
/* The SPI Hw Unit configuration structures */
const Spi_Ip_ConfigType Spi_Ip_PhyUnitConfig_SpiPhyUnit_0_VS_0 =
{
    5U,  /* Instance */
    /* mcr */
    (uint32)(SPI_MCR_MSTR(1U) | SPI_MCR_CONT_SCKE(0U) | SPI_MCR_FRZ(0U) | SPI_MCR_MTFE(0U) | 
    SPI_MCR_PCSIS(1U) | SPI_MCR_MDIS(0U) | SPI_MCR_SMPL_PT(0) | SPI_MCR_XSPI(1U) | SPI_MCR_HALT(1U)),
    #if (SPI_IP_SLAVE_SUPPORT == STD_ON)
    (boolean)FALSE,
    #endif
    #if (SPI_IP_DMA_USED == STD_ON)
    (boolean)FALSE,
    (uint8)0U, /* txDmaChannel */
    (uint8)0U, /* txCmdDmaChannel */
    (uint8)0U, /* u8NumTxCmdDmsSGId */
    NULL_PTR, /* pu8TxCmdDmaSGId */
    (uint8)0U, /* rxDmaChannel */
    #if (SPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
    (uint8)0U, /* u8NumOfDmaFastTransfer */
    NULL_PTR, /* pCmdDmaFast */
    (uint8)0U,
    NULL_PTR, /* List of Tx SG Id */
    NULL_PTR, /* List of Rx SG Id */
    #endif
    #endif  /* (SPI_IP_DMA_USED == STD_ON) */
    SPI_IP_POLLING, /* Transfer mode */
    (uint8)0U /* State structure element from the array */
};
/* The SPI Hw Unit configuration structures */
const Spi_Ip_ConfigType Spi_Ip_PhyUnitConfig_SpiPhyUnit_1_VS_0 =
{
    4U,  /* Instance */
    /* mcr */
    (uint32)(SPI_MCR_MSTR(1U) | SPI_MCR_CONT_SCKE(0U) | SPI_MCR_FRZ(0U) | SPI_MCR_MTFE(0U) | 
    SPI_MCR_PCSIS(3U) | SPI_MCR_MDIS(0U) | SPI_MCR_SMPL_PT(0) | SPI_MCR_XSPI(1U) | SPI_MCR_HALT(1U)),
    #if (SPI_IP_SLAVE_SUPPORT == STD_ON)
    (boolean)FALSE,
    #endif
    #if (SPI_IP_DMA_USED == STD_ON)
    (boolean)FALSE,
    (uint8)0U, /* txDmaChannel */
    (uint8)0U, /* txCmdDmaChannel */
    (uint8)0U, /* u8NumTxCmdDmsSGId */
    NULL_PTR, /* pu8TxCmdDmaSGId */
    (uint8)0U, /* rxDmaChannel */
    #if (SPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
    (uint8)0U, /* u8NumOfDmaFastTransfer */
    NULL_PTR, /* pCmdDmaFast */
    (uint8)0U,
    NULL_PTR, /* List of Tx SG Id */
    NULL_PTR, /* List of Rx SG Id */
    #endif
    #endif  /* (SPI_IP_DMA_USED == STD_ON) */
    SPI_IP_POLLING, /* Transfer mode */
    (uint8)1U /* State structure element from the array */
};

#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"
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

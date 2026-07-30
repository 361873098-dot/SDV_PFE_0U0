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

#ifndef SPI_IP_VS_0_PBCFG_H
#define SPI_IP_VS_0_PBCFG_H

/**
*   @file    Spi_Ip_PBcfg.h
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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* Inclusion of incompatible header files shall be avoided */
#define SPI_IP_VS_0_VENDOR_ID_PBCFG                        43
#define SPI_IP_VS_0_AR_RELEASE_MAJOR_VERSION_PBCFG         4
#define SPI_IP_VS_0_AR_RELEASE_MINOR_VERSION_PBCFG         4
#define SPI_IP_VS_0_AR_RELEASE_REVISION_VERSION_PBCFG      0
#define SPI_IP_VS_0_SW_MAJOR_VERSION_PBCFG                 4
#define SPI_IP_VS_0_SW_MINOR_VERSION_PBCFG                 0
#define SPI_IP_VS_0_SW_PATCH_VERSION_PBCFG                 2

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define SPI_IP_CONFIG_VS_0_PB \
 extern const Spi_Ip_ExternalDeviceType Spi_Ip_DeviceAttributes_SpiExternalDevice_SJA1105Q_VS_0; \
 extern const Spi_Ip_ExternalDeviceType Spi_Ip_DeviceAttributes_SpiExternalDevice_SJA1110a_VS_0; \
 extern const Spi_Ip_ExternalDeviceType Spi_Ip_DeviceAttributes_SpiExternalDevice_SJA1110b_VS_0; \
 extern const Spi_Ip_ConfigType Spi_Ip_PhyUnitConfig_SpiPhyUnit_0_VS_0; \
 extern const Spi_Ip_ConfigType Spi_Ip_PhyUnitConfig_SpiPhyUnit_1_VS_0; \


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif
/** @} */


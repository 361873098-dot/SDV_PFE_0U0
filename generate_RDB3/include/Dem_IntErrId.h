/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : 
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
*   (c) Copyright 2020-2023 NXP Semiconductors
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

#ifndef DEM_INTERRID_H
#define DEM_INTERRID_H

/**
*   @file Dem_IntErrId.h
*
*   @addtogroup DEM_MODULE
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DEM_INTERRID_VENDOR_ID 43
#define DEM_INTERRID_MODULE_ID 54

#define DEM_INTERRID_AR_RELEASE_MAJOR_VERSION       4
#define DEM_INTERRID_AR_RELEASE_MINOR_VERSION       4
#define DEM_INTERRID_AR_RELEASE_REVISION_VERSION    0
#define DEM_INTERRID_SW_MAJOR_VERSION               4
#define DEM_INTERRID_SW_MINOR_VERSION               0
#define DEM_INTERRID_SW_PATCH_VERSION               2

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#include "Dem_Types.h"
#include "Rte_Dem_Type.h"

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
      
  
/** @brief Identifier for DEM error ETHSWT_E_ACCESS*/
#define DemConf_DemEventParameter_ETHSWT_E_ACCESS   ((Dem_EventIdType) 0x1)

/** @brief Identifier for DEM error ETHSWT_E_SYNCPORT2PHY*/
#define DemConf_DemEventParameter_ETHSWT_E_SYNCPORT2PHY   ((Dem_EventIdType) 0x2)

/** @brief Identifier for DEM error ETHSWT_E_TIMEOUT*/
#define DemConf_DemEventParameter_ETHSWT_E_TIMEOUT   ((Dem_EventIdType) 0x3)

/** @brief Identifier for DEM error ETH_E_ACCESS*/
#define DemConf_DemEventParameter_ETH_E_ACCESS   ((Dem_EventIdType) 0x4)

/** @brief Identifier for DEM error MCU_E_CLOCK_FAILURE*/
#define DemConf_DemEventParameter_MCU_E_CLOCK_FAILURE   ((Dem_EventIdType) 0x5)

/** @brief Identifier for DEM error MCU_E_DEFAULTCASE_FAILURE*/
#define DemConf_DemEventParameter_MCU_E_DEFAULTCASE_FAILURE   ((Dem_EventIdType) 0x6)

/** @brief Identifier for DEM error MCU_E_FORBIDDEN_INVOCATION*/
#define DemConf_DemEventParameter_MCU_E_FORBIDDEN_INVOCATION   ((Dem_EventIdType) 0x7)

/** @brief Identifier for DEM error MCU_E_FUNCRESET_FAILURE*/
#define DemConf_DemEventParameter_MCU_E_FUNCRESET_FAILURE   ((Dem_EventIdType) 0x8)

/** @brief Identifier for DEM error MCU_E_FXOSC_EOC*/
#define DemConf_DemEventParameter_MCU_E_FXOSC_EOC   ((Dem_EventIdType) 0x9)

/** @brief Identifier for DEM error MCU_E_GENERIC_ERROR*/
#define DemConf_DemEventParameter_MCU_E_GENERIC_ERROR   ((Dem_EventIdType) 0xa)

/** @brief Identifier for DEM error MCU_E_INVALID_PARAMETER*/
#define DemConf_DemEventParameter_MCU_E_INVALID_PARAMETER   ((Dem_EventIdType) 0xb)

/** @brief Identifier for DEM error MCU_E_LOCK_FAILURE*/
#define DemConf_DemEventParameter_MCU_E_LOCK_FAILURE   ((Dem_EventIdType) 0xc)

/** @brief Identifier for DEM error MCU_E_MEMORY_CORRUPTION*/
#define DemConf_DemEventParameter_MCU_E_MEMORY_CORRUPTION   ((Dem_EventIdType) 0xd)

/** @brief Identifier for DEM error MCU_E_PLLLOCK_FAILURE*/
#define DemConf_DemEventParameter_MCU_E_PLLLOCK_FAILURE   ((Dem_EventIdType) 0xe)

/** @brief Identifier for DEM error MCU_E_QUARTZ_FAILURE*/
#define DemConf_DemEventParameter_MCU_E_QUARTZ_FAILURE   ((Dem_EventIdType) 0xf)

/** @brief Identifier for DEM error MCU_E_SPURIOUSINT_FAILURE*/
#define DemConf_DemEventParameter_MCU_E_SPURIOUSINT_FAILURE   ((Dem_EventIdType) 0x10)

/** @brief Identifier for DEM error MCU_E_SWITCHMODE_FAILURE*/
#define DemConf_DemEventParameter_MCU_E_SWITCHMODE_FAILURE   ((Dem_EventIdType) 0x11)

/** @brief Identifier for DEM error MCU_E_SXOSC_EOC*/
#define DemConf_DemEventParameter_MCU_E_SXOSC_EOC   ((Dem_EventIdType) 0x12)

/** @brief Identifier for DEM error MCU_E_TIMEOUT_FAILURE*/
#define DemConf_DemEventParameter_MCU_E_TIMEOUT_FAILURE   ((Dem_EventIdType) 0x13)

/** @brief Identifier for DEM error MCU_E_TIMEOUT_TRANSITION*/
#define DemConf_DemEventParameter_MCU_E_TIMEOUT_TRANSITION   ((Dem_EventIdType) 0x14)

/** @brief Identifier for DEM error SPI_E_HARDWARE_ERROR*/
#define DemConf_DemEventParameter_SPI_E_HARDWARE_ERROR   ((Dem_EventIdType) 0x15)

/** @brief Identifier for DEM error SPI_E_TIMEOUT*/
#define DemConf_DemEventParameter_SPI_E_TIMEOUT   ((Dem_EventIdType) 0x16)

/** @brief Identifier for DEM error ETH_E_ALIGNMENT*/
#define DemConf_DemEventParameter_ETH_E_ALIGNMENT   ((Dem_EventIdType) 0x17)

/** @brief Identifier for DEM error ETH_E_CRC*/
#define DemConf_DemEventParameter_ETH_E_CRC   ((Dem_EventIdType) 0x18)

/** @brief Identifier for DEM error ETH_E_LATECOLLISION*/
#define DemConf_DemEventParameter_ETH_E_LATECOLLISION   ((Dem_EventIdType) 0x19)

/** @brief Identifier for DEM error ETH_E_MULTIPLECOLLISION*/
#define DemConf_DemEventParameter_ETH_E_MULTIPLECOLLISION   ((Dem_EventIdType) 0x1a)

/** @brief Identifier for DEM error ETH_E_OVERSIZEFRAME*/
#define DemConf_DemEventParameter_ETH_E_OVERSIZEFRAME   ((Dem_EventIdType) 0x1b)

/** @brief Identifier for DEM error ETH_E_RX_FRAMES_LOST*/
#define DemConf_DemEventParameter_ETH_E_RX_FRAMES_LOST   ((Dem_EventIdType) 0x1c)

/** @brief Identifier for DEM error ETH_E_SINGLECOLLISION*/
#define DemConf_DemEventParameter_ETH_E_SINGLECOLLISION   ((Dem_EventIdType) 0x1d)

/** @brief Identifier for DEM error ETH_E_UNDERSIZEFRAME*/
#define DemConf_DemEventParameter_ETH_E_UNDERSIZEFRAME   ((Dem_EventIdType) 0x1e)

/** @brief Identifier for DEM error ETH_E_DRIVER_RUNTIME_ERR_IP_READY*/
#define DemConf_DemEventParameter_ETH_E_DRIVER_RUNTIME_ERR_IP_READY   ((Dem_EventIdType) 0x1f)

/** @brief Identifier for DEM error ETH_E_DRIVER_RUNTIME_ERR_INTERNAL*/
#define DemConf_DemEventParameter_ETH_E_DRIVER_RUNTIME_ERR_INTERNAL   ((Dem_EventIdType) 0x20)

/** @brief Identifier for DEM error ETH_E_PFE_ECC_ERR*/
#define DemConf_DemEventParameter_ETH_E_PFE_ECC_ERR   ((Dem_EventIdType) 0x21)

/** @brief Identifier for DEM error ETH_E_PFE_WDT_ERR*/
#define DemConf_DemEventParameter_ETH_E_PFE_WDT_ERR   ((Dem_EventIdType) 0x22)

/** @brief Identifier for DEM error ETH_E_EMAC0_ECC_UNCORRECTABLE_ERR*/
#define DemConf_DemEventParameter_ETH_E_EMAC0_ECC_UNCORRECTABLE_ERR   ((Dem_EventIdType) 0x23)

/** @brief Identifier for DEM error ETH_E_EMAC0_ECC_ADDRESS_ERR*/
#define DemConf_DemEventParameter_ETH_E_EMAC0_ECC_ADDRESS_ERR   ((Dem_EventIdType) 0x24)

/** @brief Identifier for DEM error ETH_E_EMAC0_PARITY_ERR*/
#define DemConf_DemEventParameter_ETH_E_EMAC0_PARITY_ERR   ((Dem_EventIdType) 0x25)

/** @brief Identifier for DEM error ETH_E_EMAC0_WDT_ERR*/
#define DemConf_DemEventParameter_ETH_E_EMAC0_WDT_ERR   ((Dem_EventIdType) 0x26)

/** @brief Identifier for DEM error ETH_E_EMAC1_ECC_UNCORRECTABLE_ERR*/
#define DemConf_DemEventParameter_ETH_E_EMAC1_ECC_UNCORRECTABLE_ERR   ((Dem_EventIdType) 0x27)

/** @brief Identifier for DEM error ETH_E_EMAC1_ECC_ADDRESS_ERR*/
#define DemConf_DemEventParameter_ETH_E_EMAC1_ECC_ADDRESS_ERR   ((Dem_EventIdType) 0x28)

/** @brief Identifier for DEM error ETH_E_EMAC1_PARITY_ERR*/
#define DemConf_DemEventParameter_ETH_E_EMAC1_PARITY_ERR   ((Dem_EventIdType) 0x29)

/** @brief Identifier for DEM error ETH_E_EMAC1_WDT_ERR*/
#define DemConf_DemEventParameter_ETH_E_EMAC1_WDT_ERR   ((Dem_EventIdType) 0x2a)

/** @brief Identifier for DEM error ETH_E_EMAC2_ECC_UNCORRECTABLE_ERR*/
#define DemConf_DemEventParameter_ETH_E_EMAC2_ECC_UNCORRECTABLE_ERR   ((Dem_EventIdType) 0x2b)

/** @brief Identifier for DEM error ETH_E_EMAC2_ECC_ADDRESS_ERR*/
#define DemConf_DemEventParameter_ETH_E_EMAC2_ECC_ADDRESS_ERR   ((Dem_EventIdType) 0x2c)

/** @brief Identifier for DEM error ETH_E_EMAC2_PARITY_ERR*/
#define DemConf_DemEventParameter_ETH_E_EMAC2_PARITY_ERR   ((Dem_EventIdType) 0x2d)

/** @brief Identifier for DEM error ETH_E_EMAC2_WDT_ERR*/
#define DemConf_DemEventParameter_ETH_E_EMAC2_WDT_ERR   ((Dem_EventIdType) 0x2e)

/** @brief Identifier for DEM error ETH_E_BUS_ERR*/
#define DemConf_DemEventParameter_ETH_E_BUS_ERR   ((Dem_EventIdType) 0x2f)

/** @brief Identifier for DEM error ETH_E_PFE_PARITY_ERR*/
#define DemConf_DemEventParameter_ETH_E_PFE_PARITY_ERR   ((Dem_EventIdType) 0x30)

/** @brief Identifier for DEM error ETH_E_FAIL_STOP_HW_ERR*/
#define DemConf_DemEventParameter_ETH_E_FAIL_STOP_HW_ERR   ((Dem_EventIdType) 0x31)

/** @brief Identifier for DEM error ETH_E_FAIL_STOP_FW_ERR*/
#define DemConf_DemEventParameter_ETH_E_FAIL_STOP_FW_ERR   ((Dem_EventIdType) 0x32)

/** @brief Identifier for DEM error ETH_E_FAIL_STOP_SW_ERR*/
#define DemConf_DemEventParameter_ETH_E_FAIL_STOP_SW_ERR   ((Dem_EventIdType) 0x33)

/** @brief Identifier for DEM error ETH_E_BMU_FULL*/
#define DemConf_DemEventParameter_ETH_E_BMU_FULL   ((Dem_EventIdType) 0x34)

/** @brief Identifier for DEM error ETH_E_BMU_ERR*/
#define DemConf_DemEventParameter_ETH_E_BMU_ERR   ((Dem_EventIdType) 0x35)

/** @brief Identifier for DEM error ETH_E_PE_STALL_ERR*/
#define DemConf_DemEventParameter_ETH_E_PE_STALL_ERR   ((Dem_EventIdType) 0x36)

/** @brief Identifier for DEM error ETH_E_PE_EXCEPTION_ERR*/
#define DemConf_DemEventParameter_ETH_E_PE_EXCEPTION_ERR   ((Dem_EventIdType) 0x37)

/** @brief Identifier for DEM error ETH_E_PE_FW_ERR*/
#define DemConf_DemEventParameter_ETH_E_PE_FW_ERR   ((Dem_EventIdType) 0x38)

/** @brief Identifier for DEM error ETH_E_HIF_ERR*/
#define DemConf_DemEventParameter_ETH_E_HIF_ERR   ((Dem_EventIdType) 0x39)


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef __cplusplus
}
#endif

/** @} */

#endif /* DEM_INTERRID_H */

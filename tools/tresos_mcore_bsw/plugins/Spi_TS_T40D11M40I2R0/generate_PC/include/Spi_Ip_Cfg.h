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
[!CODE!][!//

#ifndef SPI_IP_CFG_H
#define SPI_IP_CFG_H

/**
*   @file    Spi_Ip_Cfg.h
*   @version 4.0.2
*
*   @brief   AUTOSAR Spi - Spi configuration header file.
*   @details This file is the header containing all the necessary information for SPI
*            module configuration(s).
*   @addtogroup SPI_IP_DRIVER_CONFIGURATION Spi Ip Driver Configuration
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
* 4) user callback header files
==================================================================================================*/
#include "Mcal.h"
#include "OsIf.h"
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!][!//
#include "Spi_Ip_[!"."!]_PBcfg.h"
[!ENDLOOP!][!//
[!ELSE!]
#include "Spi_Ip_PBcfg.h"
[!ENDIF!]
#include "[!"ecu:get('Spi.SpiHeaderName')"!].h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_IP_VENDOR_ID_CFG                       43
#define SPI_IP_AR_RELEASE_MAJOR_VERSION_CFG        4
#define SPI_IP_AR_RELEASE_MINOR_VERSION_CFG        4
#define SPI_IP_AR_RELEASE_REVISION_VERSION_CFG     0
#define SPI_IP_SW_MAJOR_VERSION_CFG                4
#define SPI_IP_SW_MINOR_VERSION_CFG                0
#define SPI_IP_SW_PATCH_VERSION_CFG                2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal header file are of the same Autosar version */
    #if ((SPI_IP_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (SPI_IP_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Spi_Ip_Cfg.h and Mcal.h are different"
    #endif

    /* Check if the current file and OsIf.h header file are of the same version */
    #if ((SPI_IP_AR_RELEASE_MAJOR_VERSION_CFG != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (SPI_IP_AR_RELEASE_MINOR_VERSION_CFG != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Spi_Ip_Cfg.h and OsIf.h are different"
    #endif
#endif

[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
/* Check if Spi_Ip_[!"."!]_PBcfg header file and Spi configuration header file are of the same vendor */
#if (SPI_IP_[!"."!]_VENDOR_ID_PBCFG != SPI_IP_VENDOR_ID_CFG)
    #error "Spi_Ip_[!"."!]_PBcfg.h and Spi_Ip_Cfg.h have different vendor IDs"
#endif
    /* Check if Spi_Ip_[!"."!]_PBcfg header file and Spi  configuration header file are of the same Autosar version */
#if ((SPI_IP_[!"."!]_AR_RELEASE_MAJOR_VERSION_PBCFG != SPI_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (SPI_IP_[!"."!]_AR_RELEASE_MINOR_VERSION_PBCFG != SPI_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (SPI_IP_[!"."!]_AR_RELEASE_REVISION_VERSION_PBCFG != SPI_IP_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Spi_Ip_[!"."!]_PBcfg.h and Spi_Ip_Cfg.h are different"
#endif
/* Check if Spi_Ip_[!"."!]_PBcfg header file and Spi configuration header file are of the same software version */
#if ((SPI_IP_[!"."!]_SW_MAJOR_VERSION_PBCFG != SPI_IP_SW_MAJOR_VERSION_CFG) || \
     (SPI_IP_[!"."!]_SW_MINOR_VERSION_PBCFG != SPI_IP_SW_MINOR_VERSION_CFG) || \
     (SPI_IP_[!"."!]_SW_PATCH_VERSION_PBCFG != SPI_IP_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Spi_Ip_[!"."!]_PBcfg.h and Spi_Ip_Cfg.h are different"
#endif
[!ENDLOOP!]

[!ELSE!]
/* Check if Spi_Ip_PBcfg header file and Spi configuration header file are of the same vendor */
#if (SPI_IP_VENDOR_ID_PBCFG != SPI_IP_VENDOR_ID_CFG)
    #error "Spi_Ip_PBcfg.h and Spi_Ip_Cfg.h have different vendor IDs"
#endif
    /* Check if Spi_Ip_PBcfg header file and Spi  configuration header file are of the same Autosar version */
#if ((SPI_IP_AR_RELEASE_MAJOR_VERSION_PBCFG != SPI_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (SPI_IP_AR_RELEASE_MINOR_VERSION_PBCFG != SPI_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (SPI_IP_AR_RELEASE_REVISION_VERSION_PBCFG != SPI_IP_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Spi_Ip_PBcfg.h and Spi_Ip_Cfg.h are different"
#endif
/* Check if Spi_Ip_PBcfg header file and Spi configuration header file are of the same software version */
#if ((SPI_IP_SW_MAJOR_VERSION_PBCFG != SPI_IP_SW_MAJOR_VERSION_CFG) || \
     (SPI_IP_SW_MINOR_VERSION_PBCFG != SPI_IP_SW_MINOR_VERSION_CFG) || \
     (SPI_IP_SW_PATCH_VERSION_PBCFG != SPI_IP_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Spi_Ip_PBcfg.h and Spi_Ip_Cfg.h are different"
#endif
[!ENDIF!]
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
[!NOCODE!][!//
[!VAR "HWtypeSpi" = "0"!]
[!VAR "SpiIpExist"="'true'"!]
[!LOOP "SpiGeneral/SpiPhyUnit/*"!]
[!IF "contains(node:value(SpiPhyUnitMapping),'LPSPI')"!]
[!ELSE!]
    [!VAR "HWtypeSpi" = "$HWtypeSpi + 1"!]
[!ENDIF!]
[!ENDLOOP!]
[!IF "num:i($HWtypeSpi) = 0"!]
    [!VAR "SpiIpExist"="'false'"!]
    [!VAR "HWtypeSpi" = "1"!]
[!ENDIF!]
[!ENDNOCODE!][!//

[!IF "$SpiIpExist = 'true'"!]
#define SPI_IP_CONFIG_EXT \
[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
[!WS8!]SPI_IP_CONFIG_[!"."!]_PB \
[!ENDLOOP!][!//
[!ELSE!][!//
[!WS8!]SPI_IP_CONFIG_PB
[!ENDIF!]
[!ELSE!]
#define SPI_IP_CONFIG_EXT
[!ENDIF!]

/** @brief Total number of SpiPhyUnit configured. */
#define SPI_IP_NUMBER_OF_INSTANCES           ([!"num:i($HWtypeSpi)"!]U)

/** @brief Number of FIFO entries supported */
#define SPI_IP_FIFO_SIZE_U16    ((uint16)[!"ecu:get('Spi.SpiFIFOSize')"!]U)

/** @brief HWUnits enabled/disabled */
[!NOCODE!]
[!VAR "SlaveSupport" = "'false'"!]
[!LOOP "SpiGeneral/SpiPhyUnit/*"!][!//
    [!VAR "unit"="substring-after(SpiPhyUnitMapping,'_')"!]
	[!IF "substring-before(SpiPhyUnitMapping,'_') = 'SPI'"!]
    [!CODE!]
#define SPI_IP_[!"$unit"!]_ENABLED  (STD_ON)
    [!ENDCODE!]
    [!IF "SpiPhyUnitMode = 'SPI_SLAVE'"!]
		[!VAR "SlaveSupport" = "'true'"!]
	[!ENDIF!]
    [!ENDIF!]
[!ENDLOOP!]
[!CODE!]
#define SPI_IP_SLAVE_SUPPORT  [!IF "$SlaveSupport = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
[!ENDCODE!]
[!ENDNOCODE!]

/**
* @brief Defines if transfers are made using DMA or FIFO.
* @details Defines if transfers are made using DMA or FIFO.
*/
#define SPI_IP_DMA_USED [!//
[!IF "ecu:get('Spi.SpiDMAPresent') = 'TRUE' and SpiGeneral/SpiGlobalDmaEnable = 'true'"!][!//
    (STD_ON)
[!ELSE!][!//
    (STD_OFF)
[!ENDIF!][!//

/**
* @brief If enabled, allows dual MCU clock configuration settings.
* @details If enabled, allows dual MCU clock configuration settings.
*/
[!NOCODE!][!//
[!VAR "DualClockSupport"= "'false'"!]
[!IF "(node:exists(SpiAutosarExt/SpiAlternateClockRef))"!][!//
    [!VAR "DualClockSupport"= "'true'"!]
[!ELSE!]
    [!LOOP "SpiGeneral/SpiPhyUnit/*"!][!//
        [!IF "(node:exists(SpiPhyUnitAlternateClockRef))"!][!//
            [!VAR "DualClockSupport"= "'true'"!]
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define SPI_IP_DUAL_CLOCK_MODE [!//
[!IF "$DualClockSupport = 'true'"!][!//
 (STD_ON)
[!ELSE!][!//
 (STD_OFF)
[!ENDIF!][!//

/**
* @brief          Enable Dma Fast transfer support.
* @details        When SpiAutosarExt/SpiEnableDmaFastTransferSupport = TRUE,
*                 the SPI driver can be supported to transfer multiple Jobs, Channels and CPU used only for processing end of Sequence transfer.
*/
#define SPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT   [!IF "(node:value(SpiAutosarExt/SpiEnableDmaFastTransferSupport) = 'true')"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief          Enable User Mode Support.
* @details        When SpiAutosarExt/SpiEnableUserModeSupport = TRUE,
*                 the SPI driver can be executed from both supervisor and user mode.
*
* @api
*/
#define SPI_IP_ENABLE_USER_MODE_SUPPORT   [!IF "(ecu:get('Spi.SpiRegProtectAvailable') = 'TRUE') and (node:value(SpiAutosarExt/SpiEnableUserModeSupport) = 'true')"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
 #ifdef SPI_IP_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == SPI_IP_ENABLE_USER_MODE_SUPPORT)
   #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running  Spi in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
  #endif /* (STD_ON == SPI_IP_ENABLE_USER_MODE_SUPPORT) */
 #endif /* ifdef MCAL_ENABLE_USER_MODE_SUPPORT */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT*/

/**
* @brief SPI registers is controlled by REG_PROT IP.
*/
#define SPI_IP_REG_PROT_AVAILABLE   [!IF "ecu:get('Spi.SpiRegProtectAvailable') = 'TRUE'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

#if (STD_ON == SPI_IP_REG_PROT_AVAILABLE)
/**
* @brief The protection size
*/
    #define SPI_IP_PROT_MEM_U32                           ((uint32)[!"ecu:get('Spi.SpiRegProtectMem')"!]U)
#endif

/**
* @brief Maximum of frame size supported.
*/
#define SPI_IP_FRAMESIZE_MAX_U8                              ((uint8)[!"ecu:get('Spi.SpiFrameSizeMax')"!]U)

/**
* @brief Minimum of frame size supported.
*/
#define SPI_IP_FRAMESIZE_MIN_U8                              ((uint8)[!"ecu:get('Spi.SpiFrameSizeMin')"!]U)

/**
* @brief Define Timeout Method.
* @details Define a certain timeout method from OsIf will be used in the driver.
*/
#define SPI_IP_TIMEOUT_METHOD       [!//
[!IF "SpiGeneral/SpiTimeoutMethod = 'OSIF_COUNTER_DUMMY'"!][!//
    (OSIF_COUNTER_DUMMY)
[!ELSEIF "SpiGeneral/SpiTimeoutMethod = 'OSIF_COUNTER_SYSTEM'"!][!//
    (OSIF_COUNTER_SYSTEM)
[!ELSEIF "SpiGeneral/SpiTimeoutMethod = 'OSIF_COUNTER_CUSTOM'"!][!//
    (OSIF_COUNTER_CUSTOM)
[!ENDIF!][!//

/**
* @brief Switches ON or OFF for the detection and reporting of development errors(API parameter checking) at IP level.
*/
/** @implements SPI_IP_DEV_ERROR_DETECT_define  */
#define SPI_IP_DEV_ERROR_DETECT     (STD_OFF)
/*==================================================================================================
 *                                     DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/


/*==================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif
#endif 

/** @} */
[!ENDCODE!][!//

/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 0.8.0
*   Build Version        : S32K3_RTD_0_8_0_D2305_ASR_REL_4_7_REV_0000_20230524
*
*   (c) Copyright 2020 - 2023 NXP Semiconductors
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
* @file         CanTrcv_tja1145a_Ip.h
* @version      0.8.0
*
* @brief        AUTOSAR CanTrcv_43_tja1145a - module interface.
*       		API header for TJA1145A driver.
*
* @addtogroup   CanTrcv_tja1145a_Driver
* @{
*/

#ifndef CANTRCV_TJA1145A_IP_H
#define CANTRCV_TJA1145A_IP_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.8, identifier is already used to represent an object with external linkage
* One reference to CanTrcv_tja1145a_SpiConfigType serves as an internal pointer to SPI configuration while the other
* serves as a parameter through which is address of SPI configuration passed to init function.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 20.1, #include directive preceded by code
* These directives determine memory sections of variables and code, therefore they surround the obejcts they describe.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CanTrcv_tja1145a_Ip_Regs.h"
#include "Can_GeneralTypes.h"
#include "StandardTypes.h"
#include "CanTrcv_43_tja1145a_Cfg.h"
#include "cantrcv_spi_external_access.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
    Internal micro-dependent versioning. Check of AUTOSAR & Vendor specification version.
*/
#define TJA1145A_VENDOR_ID                    43
#define TJA1145A_MODULE_ID                    70
#define TJA1145A_AR_RELEASE_MAJOR_VERSION     4
#define TJA1145A_AR_RELEASE_MINOR_VERSION     7
#define TJA1145A_AR_RELEASE_REVISION_VERSION  0
#define TJA1145A_SW_MAJOR_VERSION             0
#define TJA1145A_SW_MINOR_VERSION             8
#define TJA1145A_SW_PATCH_VERSION             0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CanTrcv_tja1145a_Ip_Regs header file are of the same vendor */
#if (TJA1145A_VENDOR_ID != TJA1145A_VENDOR_ID_REGMAP)
    #error "CanTrcv_tja1145a_Ip.h and CanTrcv_tja1145a_Ip_Regs.h have different vendor ids"
#endif
/* Check if current file and CanTrcv_tja1145a_Ip_Regs header file are of the same module */
#if (TJA1145A_MODULE_ID != TJA1145A_MODULE_ID_REGMAP)
    #error "CanTrcv_tja1145a_Ip.h and CanTrcv_tja1145a_Ip_Regs.h have different module ids"
#endif
/* Check if current file and CanTrcv_tja1145a_Ip_Regs header file are of the same Autosar version */
#if ((TJA1145A_AR_RELEASE_MAJOR_VERSION    != TJA1145A_AR_RELEASE_MAJOR_VERSION_REGMAP) || \
     (TJA1145A_AR_RELEASE_MINOR_VERSION    != TJA1145A_AR_RELEASE_MINOR_VERSION_REGMAP) || \
     (TJA1145A_AR_RELEASE_REVISION_VERSION != TJA1145A_AR_RELEASE_REVISION_VERSION_REGMAP))
    #error "AutoSar Version Numbers of CanTrcv_tja1145a_Ip.h and CanTrcv_tja1145a_Ip_Regs.h are different"
#endif
/* Check if current file and CanTrcv_tja1145a_Ip_Regs header file are of the same Software version */
#if ((TJA1145A_SW_MAJOR_VERSION != TJA1145A_SW_MAJOR_VERSION_REGMAP) || \
     (TJA1145A_SW_MINOR_VERSION != TJA1145A_SW_MINOR_VERSION_REGMAP) || \
     (TJA1145A_SW_PATCH_VERSION != TJA1145A_SW_PATCH_VERSION_REGMAP))
    #error "Software Version Numbers of CanTrcv_tja1145a_Ip.h and CanTrcv_tja1145a_Ip_Regs.h are different"
#endif

/* Check if current file and CanTrcv configuration header file are of the same vendor */
#if (TJA1145A_VENDOR_ID != CANTRCV_43_TJA1145A_VENDOR_ID_CFG_H)
#error "CanTrcv_tja1145a_Ip.h and CanTrcv_43_tja1145a_Cfg.h have different vendor ids"
#endif
/* Check if current file and CanTrcv configuration header file are of the same module */
#if (TJA1145A_MODULE_ID != CANTRCV_43_TJA1145A_MODULE_ID_CFG_H)
#error "CanTrcv_tja1145a_Ip.h and CanTrcv_43_tja1145a_Cfg.h have different module ids"
#endif
/* Check if current file and CanTrcv configuration header file are of the same Autosar version */
#if ((TJA1145A_AR_RELEASE_MAJOR_VERSION != CANTRCV_43_TJA1145A_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
     (TJA1145A_AR_RELEASE_MINOR_VERSION != CANTRCV_43_TJA1145A_AR_RELEASE_MINOR_VERSION_CFG_H) || \
     (TJA1145A_AR_RELEASE_REVISION_VERSION != CANTRCV_43_TJA1145A_AR_RELEASE_REVISION_VERSION_CFG_H))
  #error "AutoSar Version Numbers of CanTrcv_tja1145a_Ip.h and CanTrcv_43_tja1145a_Cfg.h are different"
#endif
/* Check if current file and CANTRCV configuration header file are of the same software version */
#if ((TJA1145A_SW_MAJOR_VERSION != CANTRCV_43_TJA1145A_SW_MAJOR_VERSION_CFG_H) || \
     (TJA1145A_SW_MINOR_VERSION != CANTRCV_43_TJA1145A_SW_MINOR_VERSION_CFG_H) || \
     (TJA1145A_SW_PATCH_VERSION != CANTRCV_43_TJA1145A_SW_PATCH_VERSION_CFG_H))
  #error "Software Version Numbers of CanTrcv_tja1145a_Ip.h and CanTrcv_43_tja1145a_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes header file are of the same version */
	#if ((TJA1145A_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
		 (TJA1145A_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
		#error "AutoSar Version Numbers of CanTrcv_tja1145a_Ip.h and StandardTypes.h are different"
	#endif

	/* Check if current file and Can_GeneralTypes header file are of the same version */
	#if ((TJA1145A_AR_RELEASE_MAJOR_VERSION != CAN_GENERALTYPES_AR_RELEASE_MAJOR_VERSION) || \
		(TJA1145A_AR_RELEASE_MINOR_VERSION != CAN_GENERALTYPES_AR_RELEASE_MINOR_VERSION))
		#error "AutoSar Version Numbers of CanTrcv_tja1145a_Ip.h and Can_GeneralTypes.h are different"
	#endif
#endif

/* Check if current file and spi external access header file are of the same version */
#if (CANTRCV_43_TJA1145A_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
  #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((TJA1145A_AR_RELEASE_MAJOR_VERSION != SPI_EXTERNAL_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
         (TJA1145A_AR_RELEASE_MINOR_VERSION != SPI_EXTERNAL_ACCESS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of CanTrcv_tja1145a_Ip.h and cantrcv_spi_external_access.h are different"
    #endif
  #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#define TJA1145A_NO_SYSTEM_ERROR		0U
#define TJA1145A_OVERTEMP_MASK			(1U << TJA1145A_OVERTEMP)
#define TJA1145A_PN_ERROR_MASK			(1U << TJA1145A_PN_ERROR)
#define TJA1145A_PN_STATUS_ERROR_MASK	(1U << TJA1145A_PN_STATUS_ERROR)
#define TJA1145A_CAN_OSC_STATUS_MASK	(1U << TJA1145A_CAN_OSC_STATUS)
#define TJA1145A_VCC_UNDERVOLTAGE_MASK	(1U << TJA1145A_VCC_UNDERVOLTAGE)
#define TJA1145A_CAN_FAILURE_MASK		(1U << TJA1145A_CAN_FAILURE)
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/**
* @brief Enumeration of possible results of command execution.
*
*/
typedef enum
{
	/** @brief No error. */
	TJA1145A_SUCCESS			= 0,
	/** @brief General error, command failed to execute task successfully. */
	TJA1145A_FAIL,
	/** @brief SPI communication error. */
	TJA1145A_ERR_SPI,
	/** @brief Corrupted Value returned from SPI. */
	TJA1145A_ERR_VALUE,
	/** @brief Wrong parameter. */
	TJA1145A_ERR_PARAM
} CanTrcv_tja1145a_StatusType;

/**
* @brief System error.
*
*/
typedef enum
{
	/** @brief  Overtemperature detected. */
	TJA1145A_OVERTEMP		= 0,
	/** @brief Partial networking error detected. */
	TJA1145A_PN_ERROR,
	/** @brief Partial networking configuration error. */
	TJA1145A_PN_STATUS_ERROR,
	/** @brief CAN oscillator not running at target frequency. */
	TJA1145A_CAN_OSC_STATUS,
	/** @brief VCC undervoltage detected. */
	TJA1145A_VCC_UNDERVOLTAGE,
	/** @brief CAN transmitter disabled due to a TXD dominant time-out event. */
	TJA1145A_CAN_FAILURE
} CanTrcv_tja1145a_SystemErrorType;

/**
* @brief Power on event flag.
*
*/
typedef enum
{
	/** @brief No power on event occurred. */
	TJA1145A_NO_POR_EVENT			= 0,
	/** @brief Power on event occurred. */
	TJA1145A_POR_EVENT_OCCURRED
} CanTrcv_tja1145a_PorEventType;

/**
* @brief Wake up source.
*
*/
typedef enum
{
	/** @brief No wake up event occurred. */
	TJA1145A_WU_NO_EVENT			= 0,
	/** @brief WAKE pin event. */
	TJA1145A_WU_PIN_WAKEUP,
	/** @brief CAN bus wake event. */
	TJA1145A_WU_CAN_BUS_WAKEUP,
	/** @brief SPI failure (triggers wake up only in standby mode). */
	TJA1145A_WU_SPI_FAILURE,
	/** @brief Partial networking frame error. */
	TJA1145A_WU_PN_FRAME_ERROR,
	/** @brief CAN bus wake up frame received. */
	TJA1145A_WU_CAN_BUS_SILENCE,
	/** @brief TJA1145A was put to normal mode via SPI command. */
	TJA1145A_WU_INTERNALLY
} CanTrcv_tja1145a_WuReasonType;

/**
* @brief WAKE pin wake up feature mode.
*
*/
typedef enum
{
	/** @brief WAKE pin functionality disabled. */
	TJA1145A_WU_PIN_DISABLED		= 0,
	/** @brief WAKE pin active on falling edge. */
	TJA1145A_WU_PIN_FALLING_EDGE	= TJA1145A_FS_WPFE_FALLING_EDGE_ENABLED,
	/** @brief WAKE pin active on rising edge. */
	TJA1145A_WU_PIN_RISING_EDGE		= TJA1145A_FS_WPRE_RISING_EDGE_ENABLED
} CanTrcv_tja1145a_WuPinModeType;

/**
* @brief CAN bus wake up feature mode.
*
*/
typedef enum
{
	/** @brief WAKE pin functionality disabled. */
	TJA1145A_WU_CAN_BUS_DISABLED		= 0,
	/** @brief WAKE pin functionality disabled. */
	TJA1145A_WU_CAN_BUS_ENABLED
} CanTrcv_tja1145a_WuCanModeType;

/**
* @brief CAN data rate.
*
*/
typedef enum
{
	/** @brief 50kBit/s */
	TJA1145A_DR_50KBITS		= 0,
	/** @brief 100kBit/s */
	TJA1145A_DR_100KBITS	= 1,
	/** @brief 125kBit/s */
	TJA1145A_DR_125KBITS	= 2,
	/** @brief 250kBit/s */
	TJA1145A_DR_250KBITS	= 3,
	/** @brief 500kBit/s */
	TJA1145A_DR_500KBITS	= 5,
	/** @brief 1000kBit/s */
	TJA1145A_DR_1000KBITS	= 7
} CanTrcv_tja1145a_CanDataRateType;

/**
* @brief Wake up frame identifier.
*
*/
typedef enum
{
	/** @brief Standard frame identifier (11 bit). */
	TJA1145A_11BIT_IDENTIFIER	= 0,
	/** @brief Extended frame identifier (29 bit). */
	TJA1145A_29BIT_IDENTIFIER	= 1
} CanTrcv_tja1145a_IdFormatType;

/**
* @brief There are 2 options of how a WUF can be evaluated:
* 1. Only ID of WUF is considered in evaluation.
* 2. ID, DLC and data bytes are included in WUF evaluation.
*
*/
typedef enum
{
	/** @brief Only ID is included in evaluation of wake up frame. */
	TJA1145A_WUF_ID					= 0,
	/** @brief ID, DLC and data is considered in evaluation of wake up frame. */
	TJA1145A_WUF_ID_DLC_DATA		= 1
} CanTrcv_tja1145a_WufEvalType;

/**
* @brief CAN controller modes.
*
*/
typedef enum
{
	/** @brief Offline mode. */
	TJA1145A_OFFLINE_MODE					= 0,
	/** @brief CAN controller active mode with VCC undervoltage detection active. */
	TJA1145A_ACTIVE_MODE_VCC_UV_ACTIVE		= 1,
	/** @brief CAN controller active mode with VCC undervoltage detection inactive. */
	TJA1145A_ACTIVE_MODE_VCC_UV_INACTIVE	= 2,
	/** @brief Listen only mode. */
	TJA1145A_LISTEN_ONLY_MODE				= 3,
} CanTrcv_tja1145a_CanControllerModeType;

/**
* @brief Flexible data rate (available for TJA1145AT/FD and TJA1145ATK/FD only).
*
*/
typedef enum
{
	/** @brief FD disabled. */
	TJA1145A_FD_DISABLED		= 0,
	/** @brief FD enabled. */
	TJA1145A_FD_ENABLED
} CanTrcv_tja1145a_FdModeType;

/**
* @brief VCC undervoltage detection in CAN active mode configuration.
* If enabled CAN controller will automatically switch to offline mode
* if VCC undervoltage is detected.
*
*/
typedef enum
{
	/** @brief VCC undervoltage detection in active mode disabled. */
	TJA1145A_VCC_UV_DISABLED	= 0,
	/** @brief VCC undervoltage detection in active mode enabled. */
	TJA1145A_VCC_UV_ENABLED		= 1
} CanTrcv_tja1145a_VccUvConfigType;

/**
* @brief Partial networking configuration.
*
*/
/** @implements	CanTrcv_tja1145a_PNActivationType_Enum */
typedef enum
{
	/** @brief Partial networking not active. */
	TJA1145A_PN_DISABLED		= 0,
	/** @brief Partial networking active. */
	TJA1145A_PN_ENABLED
} CanTrcv_tja1145a_PNActivationType;

/**
* @brief Indicates flag's state.
*
*/
/** @implements	CanTrcv_tja1145a_TrcvFlagStateType_Enum */
typedef enum
{
	/** @brief Flag set. */
	TJA1145A_FLAG_SET           = 0,
	/** @brief Flag cleared. */
	TJA1145A_FLAG_CLEARED
} CanTrcv_tja1145a_TrcvFlagStateType;

/**
* @brief List of general purpose memory registers.
*
*/
typedef enum
{
	/** @brief Memory register 0. */
	TJA1145A_MEMORY_0           = 0,
	/** @brief Memory register 1. */
	TJA1145A_MEMORY_1,
    /** @brief Memory register 2. */
	TJA1145A_MEMORY_2,
    /** @brief Memory register 3. */
	TJA1145A_MEMORY_3
} CanTrcv_tja1145a_MemoryRegisterType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief SPI configuration for access.
*
*/
typedef struct
{
    /** @brief SPI instance (non-AUTOSAR) / SPI channel (AUTOSAR). */
    uint32 SpiChannel;
    /** @brief SPI External Device (non-AUTOSAR) / SPI sequence (AUTOSAR). */
    const void* SpiExtension;
} CanTrcv_tja1145a_SpiConfigType;

/**
* @brief This data structure contains a configuration of wake functionality.
* Possible wake up sources are: CAN bus, WAKE pin (active on rising or falling edge).
*
*/
typedef struct
{
	/** @brief CAN bus wake up functionality mode (enabled/disabled) */
	CanTrcv_tja1145a_WuCanModeType CanBusWuMode;
	/** @brief WAKE pin wake up mode (disabled/active on rising edge/active on falling edge). */
	CanTrcv_tja1145a_WuPinModeType WuPinMode;
} CanTrcv_tja1145a_WuConfigType;

/**
* @brief System/CAN controller configuration structure.
* Enables/disables various system/CAN controller events.
*
*/
typedef struct
{
	/** @brief Overtemperature warning configuration. */
	boolean OvertempDetectionEnable;
	/** @brief SPI failure configuration. */
	boolean SpiFailureDetectionEnable;
	/** @brief CAN bus silence configuration. */
	boolean CanBusSilenceDetectionEnable;
	/** @brief CAN failure warning configuration. */
	boolean CanFailureDetectionEnable;
} CanTrcv_tja1145a_EventCaptureConfigType;

/**
* @brief CAN controller configuration structure.
*
*/
typedef struct
{
	/** @brief ID of wake up frame (WUF). Value stored in this item defines WUF ID
	 * which will be considered a valid wake up ID. 'WufId' in combination with
	 * 'WufIdMask' defines a range a valid IDs. */
	uint32 WufId;
	/** @brief ID Mask of wake up frame (WUF). 1s in this item mean 'don't care' state.
	 * For example a Mask b00000111 allows a range of 8 possible valid WUF IDs. See datasheet
	 * 'Wake-up frame' section for more details. */
	uint32 WufIdMask;
	/** @brief Data length code. The 'Dlc' item indicates how many data bytes (0 - 8 bytes)
	 * are expected in the data field of a wake up frame (WUF). If 'Dlc' = 0, a node will
	 * wake up if the WUF contains a valid identifier and length of received data is 0. */
	uint8 Dlc;
	/** @brief Data rate selection. */
	CanTrcv_tja1145a_CanDataRateType DataRate;
	/** @brief Determines whether only ID is considered in WUF evaluation or also DLC and
	 * data bytes along with ID are part of WUF evaluation. */
	CanTrcv_tja1145a_WufEvalType WufEval;
	/** @brief ID format: 11 or 29 bit ID format. */
	CanTrcv_tja1145a_IdFormatType IdFormat;
	/** @brief Data masks. */
	uint8 DataMasks[8U];
	/** @brief Partial networking mode (enable/disable). */
	CanTrcv_tja1145a_PNActivationType PnMode;
	/** @brief Flexible data rate configuration. */
	CanTrcv_tja1145a_FdModeType FdConfig;
} CanTrcv_tja1145a_CanConfigType;

/**
* @brief Lock control register configuration.
* Prevents registers from unintended write access.
*
*/
typedef struct
{
	/** @brief Locks register within address range 06h - 09h. */
	boolean LockRange06h09h;
	/** @brief Locks register within address range 10h - 1Fh. */
	boolean LockRange10h1Fh;
	/** @brief Locks register within address range 20h - 2Fh. */
	boolean LockRange20h2Fh;
	/** @brief Locks register within address range 30h - 3Fh. */
	boolean LockRange30h3Fh;
	/** @brief Locks register within address range 40h - 4Fh. */
	boolean LockRange40h4Fh;
	/** @brief Locks register within address range 50h - 5Fh. */
	boolean LockRange50h5Fh;
	/** @brief Locks register within address range 68h - 6Fh. */
	boolean LockRange68h6Fh;
} CanTrcv_tja1145a_LockRegistersType;

/**
* @brief System data of TJA1145A.
*
*/
typedef struct
{
	/** @brief Main status register content. */
	uint8 MainStatusReg;
	/** @brief Transceiver status register content. */
	uint8 TrcvStatusReg;
	/** @brief Global event status register content. */
	uint8 GlobalEventStatusReg;
	/** @brief System event status register content. */
	uint8 SysEventStatusReg;
	/** @brief Transceiver event status register content. */
	uint8 TrcvEventStatusReg;
	/** @brief WAKE pin event status register content. */
	uint8 WakePinEventStatusReg;
} CanTrcv_tja1145a_SysDataType;

/**
* @brief This data structure contains a configuration of the TJA1145A device.
* This structure is used as a parameter for TJA1145A_Init function.
*
*/
/** @implements	CanTrcv_tja1145a_DeviceConfigType_Struct */
typedef struct
{
    /** @brief CAN controller configuration. */
    CanTrcv_tja1145a_CanConfigType CanConfig;
    /** @brief Wake up functionality configuration. */
    CanTrcv_tja1145a_WuConfigType WuConfig;
    /** @brief System/CAN controller event configuration. */
    CanTrcv_tja1145a_EventCaptureConfigType EventConfig;
    /** @brief VCC undervoltage detection in active mode configuration. */
    CanTrcv_tja1145a_VccUvConfigType VccUvConfig;
    /** @brief Lock control register configuration. */
    CanTrcv_tja1145a_LockRegistersType LockControl;
	/** @brief Initial state. */
	CanTrcv_TrcvModeType InitState;
} CanTrcv_tja1145a_DeviceConfigType;

/**
* @brief	Contains a reference to configuration of TJA1145A and a reference to configuration
*			of SPI peripheral through which the driver communicates with the device.
*
*/
typedef struct
{
	/** @brief Pointer to SPI configuration. */
    const CanTrcv_tja1145a_SpiConfigType *SpiConfig;
	/** @brief Pointer to an array of device configuration structure. */
	const CanTrcv_tja1145a_DeviceConfigType* DeviceConfig;
} CanTrcv_tja1145a_ConfigurationDataType;

/**
* @brief Stores information about device's/driver's status and configuration.
*
*/
typedef struct
{
	/** @brief Pointer to SPI configuration. */
    const CanTrcv_tja1145a_SpiConfigType *SpiConfig;
	/** @brief Pointer to an array of device configuration structure. */
	const CanTrcv_tja1145a_DeviceConfigType* DeviceConfig;
	/** @brief Report of a wake up reason. */
	CanTrcv_tja1145a_WuReasonType WuReason;
	/** @brief Report of system error(s). */
	uint16 SystemError;
} CanTrcv_tja1145a_DriverDataType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#ifdef CANTRCV_TJA1145A_IP_CONFIG_EXT
/** @brief Device/driver configuration. */
CANTRCV_TJA1145A_IP_CONFIG_EXT
#endif
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define CANTRCV_43_TJA1145A_START_SEC_CODE
#include "CanTrcv_43_tja1145a_MemMap.h"

/**
* @brief        Initializes the TJA1145A driver. After driver initialization, function
*				TJA1145A_DRV_ConfigureDevice must be called to configure the transceiver
*				and finalize overall configuration. Having driver and device configuration
*				in separate functions enables TJA1145A reconfiguration on cold start (MCU
*				was off) only if POR or error event has been detected.
*
* @param		Transceiver		Which device to initialize.
* @param    	ConfigData		Pointer to configuration of the device and SPI.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
void TJA1145A_DRV_Init(uint8 Transceiver, const CanTrcv_tja1145a_ConfigurationDataType* ConfigData);

/**
* @brief		Configures the transceiver. Writes data from configuration structure to its registers.
*
* @param		Transceiver		Which device to configure.
* @param    	DeviceConfig    Pointer to TJA1145A configuration.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*/
CanTrcv_tja1145a_StatusType TJA1145A_DRV_ConfigureDevice(uint8 Transceiver, const CanTrcv_tja1145a_DeviceConfigType* DeviceConfig);

/**
* @brief        Performs a read from a single TJA1145A register.
*       		Reads a single TJA1145A register. Read out data is stored
* 				in a location pointed by pRxData.
*
* @param		Transceiver		Which device to read from.
* @param    	RegAddress      Register address.
* @param   		RxData          Pointer to memory location where read out data is stored.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
CanTrcv_tja1145a_StatusType TJA1145A_DRV_ReadRegister(uint8 Transceiver, uint8 RegAddress, uint8* RxData);

/**
* @brief        Performs a read from multiple TJA1145A registers.
*       		Reads up to three consecutive TJA1145A registers. Address of the first register
* 				must be provided via the 'Address' parameter. TJA1145A will then automatically increment
* 				addresses of following registers. Read out data is stored in a location pointed by pRxData.
* 				Note: it is important to allocate enough space to accommodate all read out data.
*
* @param		Transceiver		Which device to read from.
* @param    	RegAddress      Address of the first register. Addresses of following registers are
* 								incremented by TJA1145A.
* @param		NumRegisters	Number of registers to read.
* @param   		RxData          Pointer to memory location where read out data is stored.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
CanTrcv_tja1145a_StatusType TJA1145A_DRV_ReadMultipleRegisters(uint8 Transceiver, uint8 RegAddress, uint16 NumRegisters, uint8* RxData);

/**
* @brief        Writes a single TJA1145A register.
*
* @param		Transceiver		Device ID.
* @param    	RegAddress      Register address.
* @param    	TxData          Data to write.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
CanTrcv_tja1145a_StatusType TJA1145A_DRV_WriteRegister(uint8 Transceiver, uint8 RegAddress, uint8 TxData);

/**
* @brief        Writes multiple TJA1145A consecutive registers.
* 				Writes up to the three consecutive TJA1145A registers. The address of the first register
* 				must be provided via the 'Address' parameter. Addresses of following registers are
* 				automatically incremented by TJA1145A
*
* @param		Transceiver		Device ID.
* @param    	RegAddress      Address of the first register.
* @param		NumRegisters	Number of registers to write.
* @param    	TxData			Pointer to memory location with data to write.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
CanTrcv_tja1145a_StatusType TJA1145A_DRV_WriteMultipleRegisters(uint8 Transceiver, uint8 RegAddress, uint16 NumRegisters, const uint8* TxData);

/**
* @brief		Updates a bit/bit group in a register and leaves the rest of the register unchanged.
*
* @param    	Transceiver		Device ID.
* @param		RegAddress		Address of register to write.
* @param		Value			Data to write to register specified by RegAddress parameter.
* @param		Mask			Mask of the Value.
* @param		Shift			Value position within the register.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
CanTrcv_tja1145a_StatusType TJA1145A_DRV_UpdateRegister(uint8 Transceiver, uint8 RegAddress, uint8 Value, uint8 Mask, uint8 Shift);

/**
* @brief        Sets the mode of the transceiver to the Value OpMode.
*
* @param    	Transceiver		Device ID.
* @param		OpMode			Desired operational mode.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
CanTrcv_tja1145a_StatusType TJA1145A_DRV_SetMode(uint8 Transceiver, CanTrcv_TrcvModeType OpMode);

/**
* @brief        Reads the mode of the transceiver from 'Mode control register'
* 				and returns it in OpMode parameter.
*
* @param    	Transceiver		Device ID.
* @param		OpMode			Stores the mode of the Transceiver.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
CanTrcv_tja1145a_StatusType TJA1145A_DRV_GetMode(uint8 Transceiver, CanTrcv_TrcvModeType* OpMode);

/**
* @brief        Retrieves the wake up reason. Possible wake up sources are: CAN bus, wake pin
* 				(either rising or falling edge).
*
* @param    	Transceiver		Device ID.
* @param		WuReason		Stores the mode of the transceiver.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
CanTrcv_tja1145a_StatusType TJA1145A_DRV_GetWuReason(uint8 Transceiver, CanTrcv_tja1145a_WuReasonType* WuReason);

/**
* @brief        Writes system and CAN controller event capture configuration.
*
* @param    	Transceiver		Device ID.
* @param    	EventConfig		Event capture configuration.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
CanTrcv_tja1145a_StatusType TJA1145A_DRV_EventCaptureConfiguration(uint8 Transceiver, const CanTrcv_tja1145a_EventCaptureConfigType* EventConfig);

/**
* @brief		Enables/disables wake up mode according to WakeEnable parameter.
* 				
* @param    	Transceiver		Device ID.
* @param		WakeEnable		Wake up functionality configuration.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
CanTrcv_tja1145a_StatusType TJA1145A_DRV_WakeupModeConfig(uint8 Transceiver, boolean WakeEnable);

/**
* @brief		Enables/disables WAKE pin and CAN bus wake up feautre.
*
* @param    	Transceiver		Device ID.
* @param		WakeupConfig	Wake up configuration.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
CanTrcv_tja1145a_StatusType TJA1145A_DRV_WakeupConfiguration(uint8 Transceiver, const CanTrcv_tja1145a_WuConfigType* WakeupConfig);

/**
* @brief		Enables/disables partial networking functionality. If PN is activated, the device
* 				can be woken up by a remote frame. If PN is disabled, the device can be woken up
* 				only by a standard wake up pattern.
* 				It is expected that partial networking has been configured prior calling this
* 				function which only enables/disables the PN functionality.
*
* @param    	Transceiver		Device ID.
* @param		PnMode			Enable/disable PN functionality.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
CanTrcv_tja1145a_StatusType TJA1145A_DRV_SetPnMode(uint8 Transceiver, CanTrcv_tja1145a_PNActivationType PnMode);

/**
* @brief		Configures CAN controller.
*
* @param    	Transceiver		Device ID.
* @param		CanConfig		Partial networking configuration.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
CanTrcv_tja1145a_StatusType TJA1145A_DRV_SetCanConfig(uint8 Transceiver, const CanTrcv_tja1145a_CanConfigType* CanConfig);

/**
* @brief		Sets mode of CAN controller which may differ from mode of TJA1145A. These are two
*				entities, each with its own mode.
*
* @param    	Transceiver		Device ID.
* @param		CanMode			CAN controller mode.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
CanTrcv_tja1145a_StatusType TJA1145A_DRV_SetCanControllerMode(uint8 Transceiver, CanTrcv_tja1145a_CanControllerModeType CanMode);

/**
* @brief		Reads timeout flag.
*
* @param    	Transceiver		Device ID.
* @param		FlagState		Timeout flag value.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
CanTrcv_tja1145a_StatusType TJA1145A_DRV_ReadTimeoutFlag(uint8 Transceiver, CanTrcv_tja1145a_TrcvFlagStateType* FlagState);

/**
* @brief		Reads silence flag.
*
* @param    	Transceiver		Device ID.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
CanTrcv_tja1145a_StatusType TJA1145A_DRV_ReadSilenceFlag(uint8 Transceiver, CanTrcv_tja1145a_TrcvFlagStateType* FlagState);

/**
* @brief		Returns status of the transceiver (its mode, overtemperature flag) and status
* 				of CAN controller (PN status, CAN bus status, ...).
*
* @param    	Transceiver		Device ID.
* @param		TrcvSysData		Configuration/status data of the Transceiver.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
CanTrcv_tja1145a_StatusType TJA1145A_DRV_GetTrcvSystemData(uint8 Transceiver, CanTrcv_tja1145a_SysDataType* TrcvSysData);

/**
* @brief		Clears wake up flag.
*				Clears one of following wake up flags (interrupts can as well wake up the device):
*				WAKE pin flag, CAN bus wake up flag, SPI failure (this interrupt can wake up the device
*				only when it is in standby mode), partial networking frame error, CAN bus silence. 
*
* @param    	Transceiver		Device ID.
* @param		TrcvSysData		Configuration/status data of the transceiver.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
CanTrcv_tja1145a_StatusType TJA1145A_DRV_ClearTrcvWufFlag(uint8 Transceiver, CanTrcv_tja1145a_WuReasonType WuReason);

/**
* @brief		Reads power on event flag.
*
* @param    	Transceiver		Device ID.
* @param		PorEventStatus	POR event status.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
CanTrcv_tja1145a_StatusType TJA1145A_DRV_GetPorEventStatus(uint8 Transceiver, CanTrcv_tja1145a_PorEventType* PorEventStatus);

/**
* @brief		Clears power on event flag.
*
* @param    	Transceiver		Device ID.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
CanTrcv_tja1145a_StatusType TJA1145A_DRV_ClearPorFlag(uint8 Transceiver);

/**
* @brief		Returns system error status. This driver recognizes following system errors:
* 					- overtemperature, which forces the device to switch to overtemperature mode,
* 					- undervoltage on VCC and/or VIO, which forces the device to shift to sleep mode,
* 					- oscillator of CAN transceiver not running at targeted frequency,
* 					- VCC undervoltage detected by CAN transceiver.
*					- CAN failure
*					- CAN bus silence
*					- partial networking error
*					- partial networking configuration error
*
* @param    	Transceiver		Device ID.
* @param    	SystemError		Stores information about system error.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
CanTrcv_tja1145a_StatusType TJA1145A_DRV_GetSystemErrorStatus(uint8 Transceiver, uint16* SystemError);

/**
* @brief		Clears system error.
*				Important: it is not possible to clear all system errors. Following system errors
*				are read only flags: CAN oscillator status, VCC undervoltage, PN configuration error
*				(in this case PN must be reconfigured).
*				Note: TJA1145A_PN_ERROR flag can be set because of two reason:
*					- PN frame error was detected - the flag can be cleared
*					- PN configuration error was detected - PN must be reconfigured to clear the flag.	
*
* @param    	Transceiver		Device ID.
* @param    	SystemError		System error to clean.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
CanTrcv_tja1145a_StatusType TJA1145A_DRV_ClearSystemErrorStatus(uint8 Transceiver, CanTrcv_tja1145a_SystemErrorType SystemError);

/**
* @brief		Writes lock configuration to prevent unintended register access.
*
* @param    	Transceiver		Device ID.
* @param    	LockControl		Lock control configuration.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
CanTrcv_tja1145a_StatusType TJA1145A_DRV_SetLockControlRegister(uint8 Transceiver, const CanTrcv_tja1145a_LockRegistersType* LockControl);

/**
* @brief		Writes general purpose memory register.
*
* @param    	Transceiver		Device ID.
* @param    	MemRegister     Which memory register to access.
* @param    	Data            Data to write to given memory register.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
CanTrcv_tja1145a_StatusType TJA1145A_DRV_WriteMemoryRegister(uint8 Transceiver, CanTrcv_tja1145a_MemoryRegisterType MemRegister, uint8 Data);

/**
* @brief		Reads general purpose memory register.
*
* @param    	Transceiver		Device ID.
* @param    	MemRegister     Which memory register to access.
* @param    	Data            Data to store read out content of a memory register.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
CanTrcv_tja1145a_StatusType TJA1145A_DRV_ReadMemoryRegister(uint8 Transceiver, CanTrcv_tja1145a_MemoryRegisterType MemRegister, uint8* Data);

/**
* @brief        Deinitializes the TJA1145A driver. SID is 0x0F.
*       		Clears the internal run-time configuration and puts the device to standby mode.
*
* @param    	Transceiver		Device ID.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
CanTrcv_tja1145a_StatusType TJA1145A_DRV_Deinit(uint8 Transceiver);

#define CANTRCV_43_TJA1145A_STOP_SEC_CODE
#include "CanTrcv_43_tja1145a_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*CANTRCV_TJA1145A_IP_H*/

/** @} */

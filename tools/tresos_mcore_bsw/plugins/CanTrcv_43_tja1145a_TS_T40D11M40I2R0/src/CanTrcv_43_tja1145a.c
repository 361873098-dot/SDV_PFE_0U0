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
* @file         CanTrcv_43_tja1145a.c
* @version      0.8.0
*
* @brief        AUTOSAR CanTrcv_43_tja1145a - module interface
* @details      API implementation for TJA1145A driver.
*
*
* @addtogroup   CanTrcv_tja1145a_Driver
* @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Required Rule 16.4, the switch statement does not have a non-empty default clause
* There is nothing to do/report for default case.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, ambiguous declaration
* Function declaration is defined by Autosar.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 20.1, #include directive preceded by code
* These directives determine memory sections of variables and code, therefore they surround the obejcts they describe.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 8.7, external could be made static
* The function is defined for use by application code.
*
* @section [global]
* Violates MISRA 2012 Required Rule 14.2, the condition clause expression of the for loop has persistent side-effects
* Standard for loop usage.
*
* @section [global]
* Violates MISRA 2012 Required Rule 13.5, side effects on right hand of logical operator, ''&&''
* Evaluating a member of the CanTrcv_DeviceList array has no side effects.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "CanTrcv_43_tja1145a.h"
#include "CanIf_CanTrcv.h"
#include "Spi.h"

#ifdef CANTRCV_43_TJA1145A_WAKEUP_SUPPORT
    #if (CANTRCV_43_TJA1145A_WAKEUP_SUPPORT == STD_ON)
        #include "EcuM.h"
    #endif
#endif

#if (CANTRCV_43_TJA1145A_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif

#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           CanTrcv_43_tja1145a.c
*/
#define CANTRCV_43_TJA1145A_VENDOR_ID_C                      43
#define CANTRCV_43_TJA1145A_MODULE_ID_C                      70
#define CANTRCV_43_TJA1145A_AR_RELEASE_MAJOR_VERSION_C       4
#define CANTRCV_43_TJA1145A_AR_RELEASE_MINOR_VERSION_C       7
#define CANTRCV_43_TJA1145A_AR_RELEASE_REVISION_VERSION_C    0
#define CANTRCV_43_TJA1145A_SW_MAJOR_VERSION_C               0
#define CANTRCV_43_TJA1145A_SW_MINOR_VERSION_C               8
#define CANTRCV_43_TJA1145A_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CanTrcv_43_tja1145a header file are of the same vendor */
#if (CANTRCV_43_TJA1145A_VENDOR_ID_C != CANTRCV_43_TJA1145A_VENDOR_ID)
    #error "CanTrcv_43_tja1145a.c and CanTrcv_43_tja1145a.h have different vendor ids"
#endif
/* Check if current file and CanTrcv_43_tja1145a header file are of the same module */
#if (CANTRCV_43_TJA1145A_MODULE_ID_C != CANTRCV_43_TJA1145A_MODULE_ID)
    #error "CanTrcv_43_tja1145a.c and CanTrcv_43_tja1145a.h have different module ids"
#endif
/* Check if current file and CanTrcv_43_tja1145a header file are of the same Autosar version */
#if ((CANTRCV_43_TJA1145A_AR_RELEASE_MAJOR_VERSION_C    != CANTRCV_43_TJA1145A_AR_RELEASE_MAJOR_VERSION) || \
     (CANTRCV_43_TJA1145A_AR_RELEASE_MINOR_VERSION_C    != CANTRCV_43_TJA1145A_AR_RELEASE_MINOR_VERSION) || \
     (CANTRCV_43_TJA1145A_AR_RELEASE_REVISION_VERSION_C != CANTRCV_43_TJA1145A_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of CanTrcv_43_tja1145a.c and CanTrcv_43_tja1145a.h are different"
#endif
/* Check if current file and CanTrcv_43_tja1145a header file are of the same Software version */
#if ((CANTRCV_43_TJA1145A_SW_MAJOR_VERSION_C != CANTRCV_43_TJA1145A_SW_MAJOR_VERSION) || \
     (CANTRCV_43_TJA1145A_SW_MINOR_VERSION_C != CANTRCV_43_TJA1145A_SW_MINOR_VERSION) || \
     (CANTRCV_43_TJA1145A_SW_PATCH_VERSION_C != CANTRCV_43_TJA1145A_SW_PATCH_VERSION))
    #error "Software Version Numbers of CanTrcv_43_tja1145a.c and CanTrcv_43_tja1145a.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and DET header file are of the same version */
    #if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
        #if ((CANTRCV_43_TJA1145A_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (CANTRCV_43_TJA1145A_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of CanTrcv_43_tja1145a.c and Det.h are different"
        #endif
    #endif

	/* Check if current file and DEM header file are of the same version */
	#if (CANTRCV_43_TJA1145A_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
		#if ((CANTRCV_43_TJA1145A_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
            (CANTRCV_43_TJA1145A_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of CanTrcv_43_tja1145a.c and Dem.h are different"
        #endif
	#endif

    /* Check if current file and ECUM header file are of the same version */
    #if ((CANTRCV_43_TJA1145A_AR_RELEASE_MAJOR_VERSION_C != ECUM_AR_RELEASE_MAJOR_VERSION) || \
         (CANTRCV_43_TJA1145A_AR_RELEASE_MINOR_VERSION_C != ECUM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of CanTrcv_43_tja1145a.c and EcuM.h are different"
    #endif
	
	/* Check if current file and SPI header file are of the same version */
	#if ((CANTRCV_43_TJA1145A_AR_RELEASE_MAJOR_VERSION_C != SPI_AR_RELEASE_MAJOR_VERSION) || \
		(CANTRCV_43_TJA1145A_AR_RELEASE_MINOR_VERSION_C != SPI_AR_RELEASE_MINOR_VERSION))
		#error "AutoSar Version Numbers of CanTrcv_43_tja1145a.c and Spi.h are different"
	#endif
	
	/* Check if current file and CanIf_CanTrcv header file are of the same version */
	#if ((CANTRCV_43_TJA1145A_AR_RELEASE_MAJOR_VERSION_C != CANIF_CANTRCV_AR_RELEASE_MAJOR_VERSION) || \
		(CANTRCV_43_TJA1145A_AR_RELEASE_MINOR_VERSION_C != CANIF_CANTRCV_AR_RELEASE_MINOR_VERSION))
		#error "AutoSar Version Numbers of CanTrcv_43_tja1145a.c and CanIf_CanTrcv.h are different"
	#endif
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

#define CANTRCV_43_TJA1145A_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanTrcv_43_tja1145a_MemMap.h"

/**
* @brief          Pointer to the current Driver Configuration
* @details        Pointer to the current Driver Configuration (passed to the driver during
*                 initialization). Initialized by CanTrcv_43_tja1145a_Init().
*
*/
static const volatile CanTrcv_43_tja1145a_DriverConfigType* CanTrcv_43_tja1145a_pDriverConfig;

#define CANTRCV_43_TJA1145A_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanTrcv_43_tja1145a_MemMap.h"

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define CANTRCV_43_TJA1145A_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanTrcv_43_tja1145a_MemMap.h"
/**
* @brief Internal array of Transceiver units connected to MCU.
*/
extern CanTrcv_tja1145a_DriverDataType CanTrcv_DeviceList[CANTRCV_43_TJA1145A_MAX_DEVICES_NUM];

#define CANTRCV_43_TJA1145A_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanTrcv_43_tja1145a_MemMap.h"

#define CANTRCV_43_TJA1145A_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_43_tja1145a_MemMap.h"
/**
* @brief Configuration of wake up sources defined in ECU manager component.
*/
extern const CanTrcv_43_tja1145a_EcuMReportType CanTrcv_43_tja1145a_EcuMReportConfig[CANTRCV_43_TJA1145A_MAX_DEVICES_NUM];

#define CANTRCV_43_TJA1145A_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_43_tja1145a_MemMap.h"

#define CANTRCV_43_TJA1145A_START_SEC_VAR_INIT_UNSPECIFIED
#include "CanTrcv_43_tja1145a_MemMap.h"
/**
* @brief          Driver state.
* @details        This variable holds the state of the driver. Its default value after reset is UNINIT.
*				  The CanTrcv_43_tja1145a_Init() function (the first call only) should set this variable
*				  to READY state.
*                 CANTRCV_43_TJA1145A_UNINIT = The CAN transceiver is not initialized and it is not 
*				  participating on the CAN bus.
*/
volatile CanTrcv_43_tja1145a_eDriverStatusType CanTrcv_43_tja1145a_eDriverStatus = CANTRCV_43_TJA1145A_UNINIT;

#define CANTRCV_43_TJA1145A_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CanTrcv_43_tja1145a_MemMap.h"

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define CANTRCV_43_TJA1145A_START_SEC_CODE
#include "CanTrcv_43_tja1145a_MemMap.h"

/**
* @brief          Configures a single device.
* @details        Performs device initialization: reports wake up reason, error (if any),
*				  initializes device and sets it mode.
*
* @param[in]      Transceiver		Device ID to configure.
* @param[in]      ConfigData		Configuration data.
*
* @return         CanTrcv_tja1145a_StatusType	Result of the transition.
* @retval         TJA1145A_SUCCESS				No error.
* @retval         TJA1145A_FAIL					General error, command failed to execute task successfully.
* @retval         TJA1145A_ERR_SPI				SPI communication error.
* @retval         TJA1145A_ERR_VALUE			Corrupted value returned from SPI.
* @retval         TJA1145A_ERR_PARAM			Wrong parameter.
*
* @api
*/
/** @implements     CanTrcv_43_tja1145a_InitDevice_Activity */
static CanTrcv_tja1145a_StatusType CanTrcv_43_tja1145a_InitDevice(uint8 Transceiver, const CanTrcv_tja1145a_ConfigurationDataType* ConfigData);

/**
* @brief          Checks whether accessed memory register is valid.
* @details        Checks whether accessed memory register is 1 of 4 available general purpose memory registers.
*
* @param[in]      MemRegister		Memory register to check.
*
* @return         CanTrcv_tja1145a_StatusType	Result of the transition.
* @retval         TJA1145A_SUCCESS				No error.
* @retval         TJA1145A_FAIL					General error, command failed to execute task successfully.
* @retval         TJA1145A_ERR_SPI				SPI communication error.
* @retval         TJA1145A_ERR_VALUE			Corrupted value returned from SPI.
* @retval         TJA1145A_ERR_PARAM			Wrong parameter.
*
* @api
*/
/** @implements     CanTrcv_43_tja1145a_CheckMemoryRegister_Activity */
static inline CanTrcv_tja1145a_StatusType CanTrcv_43_tja1145a_CheckMemoryRegister(CanTrcv_tja1145a_MemoryRegisterType MemRegister);

/**
* @brief          Checks SPI communication between MCU and TJA1145A.
* @details        Reads Identification register of given device, its value must be one of following: 70h, 74h.
*
* @param[in]      Transceiver		ID of device.
*
* @return         CanTrcv_tja1145a_StatusType	Result of the transition.
* @retval         TJA1145A_SUCCESS				No error.
* @retval         TJA1145A_FAIL					General error, command failed to execute task successfully.
* @retval         TJA1145A_ERR_SPI				SPI communication error.
* @retval         TJA1145A_ERR_VALUE			Corrupted value returned from SPI.
* @retval         TJA1145A_ERR_PARAM			Wrong parameter.
*
* @api
*/
/** @implements     CanTrcv_43_tja1145a_CheckSpiCommunication_Activity */
static CanTrcv_tja1145a_StatusType CanTrcv_43_tja1145a_CheckSpiCommunication(uint8 Transceiver);

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/* Configures single device. */
static CanTrcv_tja1145a_StatusType CanTrcv_43_tja1145a_InitDevice(uint8 Transceiver, const CanTrcv_tja1145a_ConfigurationDataType* ConfigData)
{
	uint16 SystemError = 0U;
	CanTrcv_tja1145a_StatusType Status;
	CanTrcv_tja1145a_PorEventType PorEvent = TJA1145A_NO_POR_EVENT;
	CanTrcv_tja1145a_WuReasonType WakeupReason = TJA1145A_WU_NO_EVENT;
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
	CanTrcv_tja1145a_CanDataRateType dataRate = TJA1145A_DR_50KBITS;
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */

	/* Initialize IP layer. */
	CanTrcv_43_tja1145a_Ipw_Init(Transceiver, ConfigData);
    
    /* Check if SPI communication works. */
    Status = CanTrcv_43_tja1145a_CheckSpiCommunication(Transceiver);
	
    if (TJA1145A_SUCCESS == Status)
	{	
        /* Check whether there has been a wake up event due to transceiver activity.
         * If yes, report this event to ECU state manager. */
        Status = CanTrcv_43_tja1145a_Ipw_GetWuReason(Transceiver, &WakeupReason);

        if ((TJA1145A_WU_NO_EVENT != WakeupReason) &&
            (CanTrcv_43_tja1145a_EcuMReportConfig[Transceiver].WakeupSourceConfig.WakeupSourceEn) &&
            (TJA1145A_SUCCESS == Status))
        {
            /* [SWS_CanTrcv_00167] Report wake up event. */
            EcuM_SetWakeupEvent(CanTrcv_43_tja1145a_EcuMReportConfig[Transceiver].WakeupSourceConfig.EcuMWakeupSource);
        }
    }

	if (TJA1145A_SUCCESS == Status)
	{
		/* [SWS_CanTrcv_00181] Check POR event. */
		Status = CanTrcv_43_tja1145a_Ipw_GetPorEventStatus(Transceiver, &PorEvent);

		if ((TJA1145A_POR_EVENT_OCCURRED == PorEvent) &&
            (CanTrcv_43_tja1145a_EcuMReportConfig[Transceiver].PorWakeupSourceConfig.WakeupSourceEn) &&
            (TJA1145A_SUCCESS == Status))
		{
			/* [SWS_CanTrcv_00183] Report POR event. */
			EcuM_SetWakeupEvent(CanTrcv_43_tja1145a_EcuMReportConfig[Transceiver].PorWakeupSourceConfig.EcuMWakeupSource);
		}
	}
	
	if (TJA1145A_SUCCESS == Status)
	{
		/* [SWS_CanTrcv_00181] Check SYSERR. */
		Status = CanTrcv_43_tja1145a_Ipw_GetSystemErrorStatus(Transceiver, &SystemError);

		if ((TJA1145A_NO_SYSTEM_ERROR != SystemError) &&
            (CanTrcv_43_tja1145a_EcuMReportConfig[Transceiver].SysErrWakeupSourceConfig.WakeupSourceEn) &&
            (TJA1145A_SUCCESS == Status))
		{
			/* [SWS_CanTrcv_00184] Report SYSERR. */
			EcuM_SetWakeupEvent(CanTrcv_43_tja1145a_EcuMReportConfig[Transceiver].SysErrWakeupSourceConfig.EcuMWakeupSource);
		}
	}
	
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
	if (TJA1145A_SUCCESS == Status)
	{
		/* [SWS_CanTrcv_00168] Check baud rate and report an error if not supported. */
		dataRate = ConfigData->DeviceConfig->CanConfig.DataRate;
		if ((dataRate != TJA1145A_DR_50KBITS)  &&
			(dataRate != TJA1145A_DR_100KBITS) &&
			(dataRate != TJA1145A_DR_125KBITS) &&
			(dataRate != TJA1145A_DR_250KBITS) &&
			(dataRate != TJA1145A_DR_500KBITS) &&
			(dataRate != TJA1145A_DR_1000KBITS))
		{
			(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_INIT,
				(uint8) CANTRCV_43_TJA1145A_E_BAUDRATE_NOT_SUPPORTED);
				
			Status = TJA1145A_FAIL;
		}
	}
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	
	if ((TJA1145A_SUCCESS == Status) &&
		((TJA1145A_POR_EVENT_OCCURRED == PorEvent) || (TJA1145A_NO_SYSTEM_ERROR != SystemError)))
	{
		/* [SWS_CanTrcv_00180][SWS_CanTrcv_00182] Reconfigure transceiver if POR or SYSERR
		 * event occurred. If the POR flag or SYSERR flag is not set, the configuration
         * stored in the transceiver memory will be still valid and reconfiguration is not
         * necessary (the case of so-called cold start - MCU was off, CAN transceiver was
         * powered hence no reconfiguration is needed). */
		Status = CanTrcv_43_tja1145a_Ipw_ConfigureDevice(Transceiver,
			(const CanTrcv_tja1145a_DeviceConfigType*) ConfigData->DeviceConfig);
	}

	if (TJA1145A_SUCCESS == Status)
	{
		/* Set operation mode. */
		Status = CanTrcv_43_tja1145a_Ipw_SetOpMode(Transceiver, ConfigData->DeviceConfig->InitState);
	}
	
	return Status;
}

/* Check general purpose memory register. */
static inline CanTrcv_tja1145a_StatusType CanTrcv_43_tja1145a_CheckMemoryRegister(CanTrcv_tja1145a_MemoryRegisterType MemRegister)
{
    CanTrcv_tja1145a_StatusType status;
    
    switch (MemRegister)
    {
        case TJA1145A_MEMORY_0:
        case TJA1145A_MEMORY_1:
        case TJA1145A_MEMORY_2:
        case TJA1145A_MEMORY_3:
            status = TJA1145A_SUCCESS;
            break;
        default:
            status = TJA1145A_ERR_PARAM;
            break;
    }
    
    return status;
}

/* Checks if SPI communication betweeen MCU and TJA1145A works. */
static CanTrcv_tja1145a_StatusType CanTrcv_43_tja1145a_CheckSpiCommunication(uint8 Transceiver)
{
    uint8 RxData;
    CanTrcv_tja1145a_StatusType Status;
    
    Status = CanTrcv_43_tja1145a_Ipw_ReadRegister(Transceiver, TJA1145A_IDENTIFICATION_ADDR, &RxData);
    
    if (TJA1145A_SUCCESS == Status)
	{
		if ((RxData != TJA1145A_FS_IDS_TJA1145AATK) && (RxData != TJA1145A_FS_IDS_TJA1145AATK_FD))
        {
            Status = TJA1145A_ERR_SPI;
        }
	}
    
    return Status;
}

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief		Initializes CanTrcv module. SID 0x00.
* @details		Initializes all transceivers configured in ConfigPtr parameter.
*				The CANTRCV module shall be initialized by CanTrcv_43_tja1145a_Init() service call during the 
*				start-up.
*
* @param[in]    ConfigPtr		Pointer to driver configuration structure.
*
* @return       void
*
*
* @pre          CanTrcv_43_tja1145a_Init shall be called at most once during runtime.
* @post         CanTrcv_43_tja1145a_Init shall initialize all the transceivers and set the driver in READY state.
*
* @api
*/
/** @implements   CanTrcv_43_tja1145a_Init_Activity */
void CanTrcv_43_tja1145a_Init(const CanTrcv_43_tja1145a_DriverConfigType* ConfigPtr)
{
	uint8 Transceiver = 0U;
	CanTrcv_tja1145a_StatusType Status = TJA1145A_FAIL;

#if (CANTRCV_43_TJA1145A_PRECOMPILE_SUPPORT == STD_ON)
	CanTrcv_43_tja1145a_pDriverConfig = &CanTrcv_Config_Predefined;
#else
	CanTrcv_43_tja1145a_pDriverConfig = ConfigPtr;
#endif /* (CANTRCV_43_TJA1145A_PRECOMPILE_SUPPORT == STD_ON) */

#if (CANTRCV_43_TJA1145A_PRECOMPILE_SUPPORT == STD_ON)
	/* Check non-null configuration if precompile support is selected. */
	if (NULL_PTR != ConfigPtr)
	{
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_INIT,
				(uint8) CANTRCV_43_TJA1145A_E_PARAM_POINTER);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
#else
	if (NULL_PTR == CanTrcv_43_tja1145a_pDriverConfig)
	{
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_INIT,
				(uint8) CANTRCV_43_TJA1145A_E_PARAM_POINTER);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
#endif /* (CANTRCV_43_TJA1145A_PRECOMPILE_SUPPORT == STD_ON) */
	else if (CANTRCV_43_TJA1145A_READY == CanTrcv_43_tja1145a_eDriverStatus)
	{
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_INIT,
				(uint8) CANTRCV_43_TJA1145A_E_INIT_FAILED);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
	else if ((CANTRCV_43_TJA1145A_MAX_DEVICES_NUM < CanTrcv_43_tja1145a_pDriverConfig->DeviceNum) ||
			(0U == CanTrcv_43_tja1145a_pDriverConfig->DeviceNum))
	{
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_INIT,
				(uint8) CANTRCV_43_TJA1145A_E_INIT_FAILED);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
	/* Preconditions - check if SPI has been initialized [SWS_CanTrcv_00099]. */
	else if (SPI_UNINIT == Spi_GetStatus())
	{
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_INIT,
				(uint8) CANTRCV_43_TJA1145A_E_INIT_FAILED);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
	else
	{
		for (Transceiver = 0U;
			Transceiver < CanTrcv_43_tja1145a_pDriverConfig->DeviceNum;
			Transceiver++)
		{
            Status = CanTrcv_43_tja1145a_InitDevice(Transceiver, &(CanTrcv_43_tja1145a_pDriverConfig->ConfigData[Transceiver]));
            
			if (TJA1145A_SUCCESS != Status)
            {
				break;
			}
		}

		if (TJA1145A_SUCCESS == Status)
		{
			CanTrcv_43_tja1145a_eDriverStatus = CANTRCV_43_TJA1145A_READY;
		}
	}

#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
	if (TJA1145A_ERR_SPI == Status)
	{
		/* [SWS_CanTrcv_00113] Log no/incorrect SPI communication if any of previous SPI transfers failed. */
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_INIT,
				(uint8) CANTRCV_43_TJA1145A_E_NO_TRCV_CONTROL);
	}
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
}

/*================================================================================================*/
/**
* @brief		Sets the mode of the Transceiver to the value OpMode. SID 0x01.
* @details		Puts the device in one of following modes: normal, standby, sleep.
*
* @param[in]    Transceiver 		Index of the transceiver.
* @param[out]   OpMode      		Desired operating mode.
*
* @return       Std_ReturnType		Result of the transition.
* @retval       E_OK				Operation executed successfully.
* @retval       E_NOT_OK			Operation failed.
*
*
* @pre          CanTrcv module should be initialized before calling the CanTrcv_43_tja1145a_SetOpMode method.
* @post         CanTrcv_43_tja1145a_SetOpMode shall set the transceiver in the desired state.
*
* @api
*/
/** @implements   CanTrcv_43_tja1145a_SetOpMode_Activity */
Std_ReturnType CanTrcv_43_tja1145a_SetOpMode(uint8 Transceiver, CanTrcv_TrcvModeType OpMode)
{
	CanTrcv_tja1145a_StatusType Status = TJA1145A_FAIL;
	CanTrcv_TrcvModeType CurrentOpMode = CANTRCV_TRCVMODE_STANDBY;
	CanTrcv_tja1145a_PorEventType PorEventStatus;
	uint16 SystemError = 0U;

	if (CANTRCV_43_TJA1145A_UNINIT == CanTrcv_43_tja1145a_eDriverStatus)
	{
		/* [SWS_CanTrcv_00122] */
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_SET_OPMODE,
				(uint8) CANTRCV_43_TJA1145A_E_UNINIT);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
	else if (Transceiver >= CanTrcv_43_tja1145a_pDriverConfig->DeviceNum)
	{
		/* [SWS_CanTrcv_00123] */
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_SET_OPMODE,
				(uint8) CANTRCV_43_TJA1145A_E_INVALID_TRANSCEIVER);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
	/* [SWS_CanTrcv_00105] */
	else if ((CANTRCV_TRCVMODE_NORMAL  != (OpMode)) &&
	         (CANTRCV_TRCVMODE_STANDBY != (OpMode)) &&
	         (CANTRCV_TRCVMODE_SLEEP   != (OpMode)))
	{
		/* [SWS_CanTrcv_00087] */
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_SET_OPMODE,
				(uint8) CANTRCV_43_TJA1145A_E_PARAM_TRCV_OPMODE);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
	else
	{
		/* [SWS_CanTrcv_00186] Check POR event. */
		Status = CanTrcv_43_tja1145a_Ipw_GetPorEventStatus(Transceiver, &PorEventStatus);

		/* [SWS_CanTrcv_00187] Check POR event, if the flag is set, reconfigure the device. */
		if ((TJA1145A_POR_EVENT_OCCURRED == PorEventStatus) && (TJA1145A_SUCCESS == Status))
		{
			Status = CanTrcv_43_tja1145a_Ipw_ConfigureDevice(Transceiver,
				(const CanTrcv_tja1145a_DeviceConfigType*) CanTrcv_43_tja1145a_pDriverConfig->ConfigData[Transceiver].DeviceConfig);
		}

		if (TJA1145A_SUCCESS == Status)
		{
			Status = CanTrcv_43_tja1145a_Ipw_GetSystemErrorStatus(Transceiver, &SystemError);
			
			if (TJA1145A_SUCCESS == Status)
			{
				/* [SWS_CanTrcv_00188] */
				if ((TJA1145A_NO_SYSTEM_ERROR == SystemError) && (CANTRCV_TRCVMODE_NORMAL == OpMode))
				{
					CanIf_ConfirmPnAvailability(Transceiver);
				}

				/* Read current mode. */
				Status = CanTrcv_43_tja1145a_Ipw_GetOpMode(Transceiver, &CurrentOpMode);

				if (TJA1145A_SUCCESS == Status)
				{
					/* [SWS_CanTrcv_00104] */
					if ((CANTRCV_TRCVMODE_SLEEP == CurrentOpMode) && (CANTRCV_TRCVMODE_STANDBY == OpMode))
					{
						/* [SWS_CanTrcv_00120] */
				#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
						(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
								(uint8) CANTRCV_43_TJA1145A_INSTANCE,
								(uint8) CANTRCV_43_TJA1145A_SID_SET_OPMODE,
								(uint8) CANTRCV_43_TJA1145A_E_TRCV_NOT_NORMAL);
				#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
						Status = TJA1145A_ERR_PARAM;
					}
					/* [SWS_CanTrcv_00103] */
					else if ((CANTRCV_TRCVMODE_NORMAL == CurrentOpMode) && (CANTRCV_TRCVMODE_SLEEP == OpMode))
					{
						/* [SWS_CanTrcv_00121] */
				#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
						(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
								(uint8) CANTRCV_43_TJA1145A_INSTANCE,
								(uint8) CANTRCV_43_TJA1145A_SID_SET_OPMODE,
								(uint8) CANTRCV_43_TJA1145A_E_TRCV_NOT_STANDBY);
				#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
						Status = TJA1145A_ERR_PARAM;
					}
					else
					{
						/* [SWS_CanTrcv_00102] Set new operation mode. */
						Status = CanTrcv_43_tja1145a_Ipw_SetOpMode(Transceiver, OpMode);
						if (TJA1145A_SUCCESS == Status)
						{
                            /* [SWS_CanTrcv_00158] Indicate mode transition. */
							CanIf_TrcvModeIndication(Transceiver, OpMode);
						}
					}
				}
			}
		}

#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		if (TJA1145A_ERR_SPI == Status)
		{
			/* [SWS_CanTrcv_00114] Log no/incorrect SPI communication if any of previous SPI transfers failed. */
			(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
					(uint8) CANTRCV_43_TJA1145A_INSTANCE,
					(uint8) CANTRCV_43_TJA1145A_SID_SET_OPMODE,
					(uint8) CANTRCV_43_TJA1145A_E_NO_TRCV_CONTROL);
		}
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}

	return (Std_ReturnType)((TJA1145A_SUCCESS == Status) ? E_OK : E_NOT_OK);
}

/*================================================================================================*/
/**
* @brief		Gets current operation mode. SID 0x02.
* @details      Gets the mode of the Transceiver and returns it in OpMode. The device is in one
*				of following modes: normal, standby, sleep.
*
* @param[in]    Transceiver 		CAN transceiver ID.
* @param[out]   OpMode      		Current operating mode.
*
* @return       Std_ReturnType		Result of the transition.
* @retval       E_OK				Operation executed successfully.
* @retval       E_NOT_OK			Operation failed.
*
*
* @pre          CanTrcv module should be initialized before calling the CanTrcv_43_tja1145a_GetOpMode method.
* @post         CanTrcv_43_tja1145a_GetOpMode shall return the currently working mode of the transceiver.
*
* @api
*/
/** @implements   CanTrcv_43_tja1145a_GetOpMode_Activity */
Std_ReturnType CanTrcv_43_tja1145a_GetOpMode(uint8 Transceiver, CanTrcv_TrcvModeType* OpMode)
{
	CanTrcv_tja1145a_StatusType Status = TJA1145A_FAIL;

	if (CANTRCV_43_TJA1145A_UNINIT == CanTrcv_43_tja1145a_eDriverStatus)
	{
		/* [SWS_CanTrcv_00124] */
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_GET_OPMODE,
				(uint8) CANTRCV_43_TJA1145A_E_UNINIT);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
	else if (Transceiver >= CanTrcv_43_tja1145a_pDriverConfig->DeviceNum)
	{
		/* [SWS_CanTrcv_00129] */
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_GET_OPMODE,
				(uint8) CANTRCV_43_TJA1145A_E_INVALID_TRANSCEIVER);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
	else if (NULL_PTR == OpMode)
	{
		/* [SWS_CanTrcv_00132] */
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_GET_OPMODE,
				(uint8) CANTRCV_43_TJA1145A_E_PARAM_POINTER);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
	else
	{
		/* [SWS_CanTrcv_00106] */
		Status = CanTrcv_43_tja1145a_Ipw_GetOpMode(Transceiver, OpMode);
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		/* [SWS_CanTrcv_00115] */
		if (TJA1145A_ERR_SPI == Status)
		{
			(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
					(uint8) CANTRCV_43_TJA1145A_INSTANCE,
					(uint8) CANTRCV_43_TJA1145A_SID_GET_OPMODE,
					(uint8) CANTRCV_43_TJA1145A_E_NO_TRCV_CONTROL);
		}
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}

	return (Std_ReturnType)((TJA1145A_SUCCESS == Status) ? E_OK : E_NOT_OK);
}

/*================================================================================================*/
/**
* @brief		Gets the wakeup reason of the Transceiver and returns it in parameter Reason. SID 0x03.
* @details		The device can be woken up by:
*					- standard wake up sources: WAKE pin, CAN bus or internally
*					- interrupts: SPI failure, CAN bus silence and PN frame error. Interrupts 
*					  are collectively reported as CANTRCV_WU_BY_SYSERR.
*
* @param[in]	Transceiver			CAN transceiver to which API call has to be applied.
* @param[out]	Reason				Pointer to wake up reason.
*
* @return       Std_ReturnType		Result of the transition.
* @retval       E_OK				Operation executed successfully.
* @retval       E_NOT_OK			Operation failed.
*
*
* @pre			CanTrcv module should be initialized before calling the CanTrcv_43_tja1145a_GetBusWuReason method.
* @post         CanTrcv_43_tja1145a_GetBusWuReason shall return wake up reason.
*
* @api
*/
/** @implements   CanTrcv_43_tja1145a_GetBusWuReason_Activity */
Std_ReturnType CanTrcv_43_tja1145a_GetBusWuReason(uint8 Transceiver, CanTrcv_TrcvWakeupReasonType* Reason)
{
	CanTrcv_tja1145a_WuReasonType WuReason;
	CanTrcv_tja1145a_StatusType Status = TJA1145A_FAIL;

	if (CANTRCV_43_TJA1145A_UNINIT == CanTrcv_43_tja1145a_eDriverStatus)
	{
		/* [SWS_CanTrcv_00125] */
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_GET_BUS_WU_REASON,
				(uint8) CANTRCV_43_TJA1145A_E_UNINIT);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
	else if (Transceiver >= CanTrcv_43_tja1145a_pDriverConfig->DeviceNum)
	{
		/* [SWS_CanTrcv_00130] */
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_GET_BUS_WU_REASON,
				(uint8) CANTRCV_43_TJA1145A_E_INVALID_TRANSCEIVER);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
	else if (NULL_PTR == Reason)
	{
		/* [SWS_CanTrcv_00133] */
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_GET_BUS_WU_REASON,
				(uint8) CANTRCV_43_TJA1145A_E_PARAM_POINTER);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
	else
	{
		/* [SWS_CanTrcv_00107] Read wake up reason. */
		Status = CanTrcv_43_tja1145a_Ipw_GetWuReason(Transceiver, &WuReason);
		
		/* Map driver defined wake up reasons to AUTOSAR defined wake up reason. */
		switch (WuReason)
		{
		case TJA1145A_WU_NO_EVENT:
			*Reason = CANTRCV_WU_NOT_SUPPORTED;
			break;
	
		case TJA1145A_WU_PIN_WAKEUP:
			*Reason = CANTRCV_WU_BY_PIN;
			break;
		
		case TJA1145A_WU_CAN_BUS_WAKEUP:
			*Reason = CANTRCV_WU_BY_BUS;
			break;
					
		case TJA1145A_WU_INTERNALLY:
			*Reason = CANTRCV_WU_INTERNALLY;
			break;
		
		case TJA1145A_WU_SPI_FAILURE:
		case TJA1145A_WU_PN_FRAME_ERROR:
		case TJA1145A_WU_CAN_BUS_SILENCE:
			*Reason = CANTRCV_WU_BY_SYSERR;
			break;
			
		default: 
			*Reason = CANTRCV_WU_ERROR;
			break;
		}

#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		/* [SWS_CanTrcv_00116] */
		if (TJA1145A_ERR_SPI == Status)
		{
			(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
					(uint8) CANTRCV_43_TJA1145A_INSTANCE,
					(uint8) CANTRCV_43_TJA1145A_SID_GET_BUS_WU_REASON,
					(uint8) CANTRCV_43_TJA1145A_E_NO_TRCV_CONTROL);
		}
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}

	return (Std_ReturnType)((TJA1145A_SUCCESS == Status) ? E_OK : E_NOT_OK);
}

#if (CANTRCV_43_TJA1145A_VERSION_INFO_API == STD_ON)
/**
* @brief        CAN transceiver driver get version info function. SID is 0x04.
* @details      Returns the version information of this module.
*
* @param[out]   versioninfo     Pointer to where to store the version information of this module.
*
* @return       void
*
* @api
*/
/** @implements   CanTrcv_43_tja1145a_GetVersionInfo_Activity */
void CanTrcv_43_tja1145a_GetVersionInfo(Std_VersionInfoType* VersionInfo)
{
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == VersionInfo)
    {
        (void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
        		(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_GET_VERSION_INFO,
				(uint8) CANTRCV_43_TJA1145A_E_PARAM_POINTER);
    }
    else
    {
#endif /* CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON */
    	VersionInfo->vendorID = (uint16) CANTRCV_43_TJA1145A_VENDOR_ID;
    	VersionInfo->moduleID = (uint8) CANTRCV_43_TJA1145A_MODULE_ID;
    	VersionInfo->sw_major_version = (uint8) CANTRCV_43_TJA1145A_SW_MAJOR_VERSION;
    	VersionInfo->sw_minor_version = (uint8) CANTRCV_43_TJA1145A_SW_MINOR_VERSION;
    	VersionInfo->sw_patch_version = (uint8) CANTRCV_43_TJA1145A_SW_PATCH_VERSION;
#if(CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON */
}
#endif /* CANTRCV_43_TJA1145A_VERSION_INFO_API == STD_ON */

/*================================================================================================*/
/**
* @brief		Reads transceiver system data. SID 0x09.
* @details		Returns following information: transition to normal and sleep mode status, overtemperature
*				flag, CAN controller status, partial networking status, oscillator working properly status,
*				CAN bus silence flag, VCC supply status, CAN failure status.
*
* @param[in]	Transceiver			CAN transceiver to which API call has to be applied.
* @param[out]	TrcvSysData			Holds transceiver system status.
*
* @return       Std_ReturnType		Result of the transition.
* @retval       E_OK				Operation executed successfully.
* @retval       E_NOT_OK			Operation failed.
*
*
* @pre			CanTrcv module should be initialized before calling the CanTrcv_43_tja1145a_GetTrcvSystemData method.
* @post         CanTrcv_43_tja1145a_GetTrcvSystemData shall return status of the transceiver.
*
* @api
*/
/** @implements     CanTrcv_43_tja1145a_GetTrcvSystemData_Activity */
Std_ReturnType CanTrcv_43_tja1145a_GetTrcvSystemData(uint8 Transceiver, uint32* TrcvSysData)
{
	CanTrcv_tja1145a_SysDataType SysData = { 0U };
	CanTrcv_tja1145a_StatusType Status = TJA1145A_FAIL;
	
	if (CANTRCV_43_TJA1145A_UNINIT == CanTrcv_43_tja1145a_eDriverStatus)
	{
		/* [SWS_CanTrcv_00191] */
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_GET_TRCV_SYSTEM_DATA,
				(uint8) CANTRCV_43_TJA1145A_E_UNINIT);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
	else if (Transceiver >= CanTrcv_43_tja1145a_pDriverConfig->DeviceNum)
	{
		/* [SWS_CanTrcv_00192] */
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_GET_TRCV_SYSTEM_DATA,
				(uint8) CANTRCV_43_TJA1145A_E_INVALID_TRANSCEIVER);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
	else if (NULL_PTR == TrcvSysData)
	{
		/* [SWS_CanTrcv_00193] */
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_GET_TRCV_SYSTEM_DATA,
				(uint8) CANTRCV_43_TJA1145A_E_PARAM_POINTER);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
	else
	{
		/* [SWS_CanTrcv_00189] Read transceiver system data. */
		Status = CanTrcv_43_tja1145a_Ipw_GetTrcvSystemData(Transceiver, &SysData);
		
		TrcvSysData[0] = SysData.MainStatusReg;
		TrcvSysData[1] = SysData.TrcvStatusReg;
	
	#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		/* [SWS_CanTrcv_00190] */
		if (TJA1145A_ERR_SPI == Status)
		{
			(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
					(uint8) CANTRCV_43_TJA1145A_INSTANCE,
					(uint8) CANTRCV_43_TJA1145A_SID_GET_TRCV_SYSTEM_DATA,
					(uint8) CANTRCV_43_TJA1145A_E_NO_TRCV_CONTROL);
		}
	#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
	
	return (Std_ReturnType)((TJA1145A_SUCCESS == Status) ? E_OK : E_NOT_OK);
}

/*================================================================================================*/
/**
* @brief		Clears the WUF flag in the transceiver hardware. SID 0x0A.
* @details		Clears wake up flag and reports this event.
*
* @param[in]	Transceiver			CAN Transceiver ID.
*
* @return       Std_ReturnType		Result of the transition.
* @retval       E_OK				Operation executed successfully.
* @retval       E_NOT_OK			Operation failed.
*
*
* @pre			CanTrcv module should be initialized before calling the CanTrcv_43_tja1145a_ClearTrcvWufFlag method.
* @post         CanTrcv_43_tja1145a_ClearTrcvWufFlag shall return status of the transceiver.
*
* @api
*/
/** @implements   CanTrcv_43_tja1145a_ClearTrcvWufFlag_Activity */
Std_ReturnType CanTrcv_43_tja1145a_ClearTrcvWufFlag(uint8 Transceiver)
{
	CanTrcv_tja1145a_StatusType Status = TJA1145A_FAIL;
	
	if (CANTRCV_43_TJA1145A_UNINIT == CanTrcv_43_tja1145a_eDriverStatus)
	{
		/* [SWS_CanTrcv_00197] */
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_CLEAR_TRCV_WUF_FLAG,
				(uint8) CANTRCV_43_TJA1145A_E_UNINIT);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
	else if (Transceiver >= CanTrcv_43_tja1145a_pDriverConfig->DeviceNum)
	{
		/* [SWS_CanTrcv_00198] */
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_CLEAR_TRCV_WUF_FLAG,
				(uint8) CANTRCV_43_TJA1145A_E_INVALID_TRANSCEIVER);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
	else
	{
		/* [SWS_CanTrcv_00194] Clear wake up flag. */
		Status = CanTrcv_43_tja1145a_Ipw_ClearTrcvWufFlag(Transceiver, CanTrcv_DeviceList[Transceiver].WuReason);
		
		/* [SWS_CanTrcv_00195] Inform CanIf that wake up flag was cleared. */
		if (TJA1145A_SUCCESS == Status)
		{
			CanIf_ClearTrcvWufFlagIndication(Transceiver);
			
			/* [SWS_CanTrcv_00194] The transceiver shall be put into Standby mode after clearing WUF flag. */
			Status = CanTrcv_43_tja1145a_Ipw_SetOpMode(Transceiver, CANTRCV_TRCVMODE_STANDBY); 
		}
		
	#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		/* [SWS_CanTrcv_00196] */
		if (TJA1145A_ERR_SPI == Status)
		{
			(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
					(uint8) CANTRCV_43_TJA1145A_INSTANCE,
					(uint8) CANTRCV_43_TJA1145A_SID_CLEAR_TRCV_WUF_FLAG,
					(uint8) CANTRCV_43_TJA1145A_E_NO_TRCV_CONTROL);
		}
	#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
	
	return (Std_ReturnType)((TJA1145A_SUCCESS == Status) ? E_OK : E_NOT_OK);
}

/*================================================================================================*/
/**
* @brief		Enables, disables or clears wake up events of the Transceiver according to TrcvWakeupMode. SID 0x05.
* @details		Enables, disables or clears wake up functionality. If WU mode is disabled all wake up sources
*				and interrupts are off. If WU mode is enabled, all wake up sources and interrupts are set
*				according to configuration. If WU mode is clear, pending wake up flag is cleared.
*
* @param[in]	Transceiver			CAN Transceiver ID.
* @param[in]	TrcvWakeupMode		Mode of wake up functionality (enabled, disabled, cleared).
*
* @return       Std_ReturnType		Result of the transition.
* @retval       E_OK				Operation executed successfully.
* @retval       E_NOT_OK			Operation failed.
*
*
* @pre			CanTrcv module should be initialized before calling the CanTrcv_43_tja1145a_SetWakeupMode method.
* @post         CanTrcv_43_tja1145a_SetWakeupMode shall return status of the transceiver.
*
* @api
*/
/** @implements   CanTrcv_43_tja1145a_SetWakeupMode_Activity */
Std_ReturnType CanTrcv_43_tja1145a_SetWakeupMode(uint8 Transceiver, CanTrcv_TrcvWakeupModeType TrcvWakeupMode)
{
	CanTrcv_tja1145a_StatusType Status = TJA1145A_FAIL;

	if (CANTRCV_43_TJA1145A_UNINIT == CanTrcv_43_tja1145a_eDriverStatus)
	{
		/* [SWS_CanTrcv_00127] */
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_SET_WAKEUP_MODE,
				(uint8) CANTRCV_43_TJA1145A_E_UNINIT);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
	else if (Transceiver >= CanTrcv_43_tja1145a_pDriverConfig->DeviceNum)
	{
		/* [SWS_CanTrcv_00131] */
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_SET_WAKEUP_MODE,
				(uint8) CANTRCV_43_TJA1145A_E_INVALID_TRANSCEIVER);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
	else if ((CANTRCV_WUMODE_ENABLE != (TrcvWakeupMode)) &&
	        (CANTRCV_WUMODE_DISABLE != (TrcvWakeupMode)) &&
	        (CANTRCV_WUMODE_CLEAR   != (TrcvWakeupMode)))
	{
		/* [SWS_CanTrcv_00089] */
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_SET_WAKEUP_MODE,
				(uint8) CANTRCV_43_TJA1145A_E_PARAM_TRCV_WAKEUP_MODE);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
	else
	{		
		if (CANTRCV_WUMODE_DISABLE == TrcvWakeupMode)
		{
			CanTrcv_tja1145a_WuReasonType WakeupEvent;
			
			/* [SWS_CanTrcv_00093] The transceiver device and the transceiver driver are required to detect
			 * wakeup events and store them internally, in order to raise the wakeup events when the wakeup
			 * mode is enabled again. */
			Status = CanTrcv_43_tja1145a_Ipw_GetWuReason(Transceiver, &WakeupEvent);
			
			if (TJA1145A_SUCCESS == Status)
			{
				/* [SWS_CanTrcv_00093] Disable wake up mode. */
				Status = CanTrcv_43_tja1145a_Ipw_WakeupModeConfig(Transceiver, FALSE);
			}
		}

		if (CANTRCV_WUMODE_ENABLE == TrcvWakeupMode)
		{
            /* Check if there is any pending wake up event and if EcuM reporting is enabled. */
            if ((TJA1145A_WU_NO_EVENT != CanTrcv_DeviceList[Transceiver].WuReason) &&
                (CanTrcv_43_tja1145a_EcuMReportConfig[Transceiver].WakeupSourceConfig.WakeupSourceEn))
            {
                /* [SWS_CanTrcv_00111] Update pending wake up event. */
                EcuM_SetWakeupEvent(CanTrcv_43_tja1145a_EcuMReportConfig[Transceiver].WakeupSourceConfig.EcuMWakeupSource);
            }

			/* [SWS_CanTrcv_00111] Enable wake up mode. */
			Status = CanTrcv_43_tja1145a_Ipw_WakeupModeConfig(Transceiver, TRUE);
		}
		
		if (CANTRCV_WUMODE_CLEAR == TrcvWakeupMode)
		{
			/* [SWS_CanTrcv_00150] Clearing of wakeup events have to be used when the wake up
			 * notification is disabled to clear all stored wake up events */
			Status = CanTrcv_43_tja1145a_Ipw_WakeupModeConfig(Transceiver, FALSE);
			
			if (TJA1145A_SUCCESS == Status)
			{
				/* [SWS_CanTrcv_00094] [SWS_CanTrcv_00094] Clear pending wake up flags and wake up event report. */
				Status = CanTrcv_43_tja1145a_Ipw_ClearTrcvWufFlag(Transceiver, CanTrcv_DeviceList[Transceiver].WuReason);
			}
		}

#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		/* [SWS_CanTrcv_00117] */
		if (TJA1145A_ERR_SPI == Status)
		{
			(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
					(uint8) CANTRCV_43_TJA1145A_INSTANCE,
					(uint8) CANTRCV_43_TJA1145A_SID_SET_WAKEUP_MODE,
					(uint8) CANTRCV_43_TJA1145A_E_NO_TRCV_CONTROL);
		}
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}

	return (Std_ReturnType)((TJA1145A_SUCCESS == Status) ? E_OK : E_NOT_OK);
}

/*================================================================================================*/
/**
* @brief		Service is called by underlying CANIF in case a wake up interrupt is detected. SID 0x07.
* @details		Reads wake up source from the device and  reports it to ECUM.
*
* @param[in]    Transceiver			CAN transceiver ID.
*
* @return       Std_ReturnType		Result of the transition.
* @retval       E_OK				Operation executed successfully.
* @retval       E_NOT_OK			Operation failed.
*
*
* @pre			CanTrcv module should be initialized before calling the CanTrcv_43_tja1145a_CheckWakeup method.
* @post         CanTrcv_43_tja1145a_CheckWakeup shall read and report wake up reason.
*
* @api
*/
/** @implements   CanTrcv_43_tja1145a_CheckWakeup_Activity */
Std_ReturnType CanTrcv_43_tja1145a_CheckWakeup(uint8 Transceiver)
{
	CanTrcv_tja1145a_WuReasonType WakeupReason;
	CanTrcv_tja1145a_StatusType Status = TJA1145A_FAIL;

	if (CANTRCV_43_TJA1145A_UNINIT == CanTrcv_43_tja1145a_eDriverStatus)
	{
		/* [SWS_CanTrcv_00144] */
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_CHECK_WAKEUP,
				(uint8) CANTRCV_43_TJA1145A_E_UNINIT);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
	else if (Transceiver >= CanTrcv_43_tja1145a_pDriverConfig->DeviceNum)
	{
		/* [SWS_CanTrcv_00145] */
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_CHECK_WAKEUP,
				(uint8) CANTRCV_43_TJA1145A_E_INVALID_TRANSCEIVER);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
	else
	{
		/* Get wake up reason. */
		Status = CanTrcv_43_tja1145a_Ipw_GetWuReason(Transceiver, &WakeupReason);

		if ((TJA1145A_SUCCESS == Status) &&
            (TJA1145A_WU_NO_EVENT != WakeupReason) &&
            (CanTrcv_43_tja1145a_EcuMReportConfig[Transceiver].WakeupSourceConfig.WakeupSourceEn))
        {
            /* [SWS_CanTrcv_00146] Report wake up event. */
            EcuM_SetWakeupEvent(CanTrcv_43_tja1145a_EcuMReportConfig[Transceiver].WakeupSourceConfig.EcuMWakeupSource);
        }
	}

	return (Std_ReturnType)((TJA1145A_SUCCESS == Status) ? E_OK : E_NOT_OK);
}

/*================================================================================================*/
/**
* @brief		Requests to check the status of the wakeup flag from the transceiver hardware. SID 0x0E.
* @details		Checks wake up event and if WU occurred, reports it.
*
* @param[in]    Transceiver			CAN transceiver ID.
*
* @return       Std_ReturnType		Result of the transition.
* @retval       E_OK				Operation executed successfully.
* @retval       E_NOT_OK			Operation failed.
*
*
* @pre			CanTrcv module should be initialized before calling the CanTrcv_43_tja1145a_CheckWakeFlag method.
* @post         CanTrcv_43_tja1145a_CheckWakeFlag shall check for wake up event, and if such event occurred, report it.
*
* @api
*/
/** @implements   CanTrcv_43_tja1145a_CheckWakeFlag_Activity */
Std_ReturnType CanTrcv_43_tja1145a_CheckWakeFlag(uint8 Transceiver)
{
	CanTrcv_tja1145a_WuReasonType WakeupReason;
	CanTrcv_tja1145a_StatusType Status = TJA1145A_FAIL;

	if (CANTRCV_43_TJA1145A_UNINIT == CanTrcv_43_tja1145a_eDriverStatus)
	{
		Status = TJA1145A_FAIL;
	}
	else if (Transceiver >= CanTrcv_43_tja1145a_pDriverConfig->DeviceNum)
	{
		/* [SWS_CanTrcv_00225] */
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_CHECK_WAKE_FLAG,
				(uint8) CANTRCV_43_TJA1145A_E_INVALID_TRANSCEIVER);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
		Status = TJA1145A_FAIL;
	}
	else
	{
		/* Get wake up reason. */
		Status = CanTrcv_43_tja1145a_Ipw_GetWuReason(Transceiver, &WakeupReason);
		
		if ((TJA1145A_WU_NO_EVENT != WakeupReason) && (TJA1145A_SUCCESS == Status))
		{
			/* [SWS_CanTrcv_00224] */
			CanIf_CheckTrcvWakeFlagIndication(Transceiver);
		}
	}

	return (Std_ReturnType)((TJA1145A_SUCCESS == Status) ? E_OK : E_NOT_OK);
}

/*================================================================================================*/
/**
* @brief        Reads the status of the timeout flag from the transceiver hardware. SID 0x0B.
* @details		Reads and returns status of timeout flag.
*
* @param[in]    Transceiver			CAN transceiver ID.
* @param[out]	FlagState			State of the timeout flag.
*
* @return       Std_ReturnType		Result of the transition.
* @retval       E_OK				Operation executed successfully.
* @retval       E_NOT_OK			Operation failed.
*
*          
* @post			CanTrcv_43_tja1145a_ReadTrcvTimeoutFlag shall return timeout flag status.
*
* @api
*/
/** @implements   CanTrcv_43_tja1145a_ReadTrcvTimeoutFlag_Activity */
Std_ReturnType CanTrcv_43_tja1145a_ReadTrcvTimeoutFlag(uint8 Transceiver, CanTrcv_tja1145a_TrcvFlagStateType* FlagState)
{
	CanTrcv_tja1145a_StatusType Status = TJA1145A_FAIL;
	
	if (CANTRCV_43_TJA1145A_UNINIT == CanTrcv_43_tja1145a_eDriverStatus)
	{
		Status = TJA1145A_FAIL;
	}
	else if (Transceiver >= CanTrcv_43_tja1145a_pDriverConfig->DeviceNum)
	{
		/* [SWS_CanTrcv_00199] */
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_READ_TRCV_TIMEOUT_FLAG,
				(uint8) CANTRCV_43_TJA1145A_E_INVALID_TRANSCEIVER);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
		Status = TJA1145A_FAIL;
	}
	else if (NULL_PTR == FlagState)
	{
		/* [SWS_CanTrcv_00200] */
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_READ_TRCV_TIMEOUT_FLAG,
				(uint8) CANTRCV_43_TJA1145A_E_PARAM_POINTER);
#endif
		Status = TJA1145A_FAIL;
	}
	else
	{
		/* [SWS_CanTrcv_00215] Read timeout flag. */
		Status = CanTrcv_43_tja1145a_Ipw_ReadTimeoutFlag(Transceiver, FlagState);
	}
	
	return (Std_ReturnType)((TJA1145A_SUCCESS == Status) ? E_OK : E_NOT_OK);
}

/*================================================================================================*/
/**
* @brief		Clears the status of the timeout flag in the transceiver hardware. SID 0x0C.
* @details		Clears timeout flag.
*
* @param[in]    Transceiver			CAN transceiver ID.
*
* @return       Std_ReturnType		Result of the transition.
* @retval       E_OK				Operation executed successfully.
* @retval       E_NOT_OK			Operation failed.
*
*
* @post			CanTrcv_43_tja1145a_ClearTrcvTimeoutFlag shall clear timeout flag.			          
*
* @api
*/
/** @implements   CanTrcv_43_tja1145a_ClearTrcvTimeoutFlag_Activity */
Std_ReturnType CanTrcv_43_tja1145a_ClearTrcvTimeoutFlag(uint8 Transceiver)
{
	CanTrcv_tja1145a_StatusType Status = TJA1145A_FAIL;
	
	if (CANTRCV_43_TJA1145A_UNINIT == CanTrcv_43_tja1145a_eDriverStatus)
	{
		Status = TJA1145A_FAIL;
	}
	else if (Transceiver >= CanTrcv_43_tja1145a_pDriverConfig->DeviceNum)
	{
		/* [SWS_CanTrcv_00201] */
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_CLEAR_TRCV_TIMEOUT_FLAG,
				(uint8) CANTRCV_43_TJA1145A_E_INVALID_TRANSCEIVER);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
		Status = TJA1145A_FAIL;
	}
	else
	{
		/* [SWS_CanTrcv_00216] Clear timeout flag. */
		Status = CanTrcv_43_tja1145a_Ipw_ClearSystemErrorStatus(Transceiver, TJA1145A_CAN_FAILURE);
	}
	
	return (Std_ReturnType)((TJA1145A_SUCCESS == Status) ? E_OK : E_NOT_OK);
}

/*================================================================================================*/
/**
* @brief        Reads the status of the silence flag from the transceiver hardware. SID 0x0D.
* @details		Reads CAN bus silence flag.  
*
* @param[in]    Transceiver			CAN transceiver ID.
* @param[out]	FlagState			State of the silence flag.
*
* @return       Std_ReturnType		Result of the transition.
* @retval       E_OK				Operation executed successfully.
* @retval       E_NOT_OK			Operation failed.
*
*
* @post         CanTrcv_43_tja1145a_ReadTrcvSilenceFlag shall read CAN bus silence flag.
*
* @api
*/
/** @implements     CanTrcv_43_tja1145a_ReadTrcvSilenceFlag_Activity */
Std_ReturnType CanTrcv_43_tja1145a_ReadTrcvSilenceFlag(uint8 Transceiver, CanTrcv_tja1145a_TrcvFlagStateType* FlagState)
{
	CanTrcv_tja1145a_StatusType Status = TJA1145A_FAIL;
	
	if (CANTRCV_43_TJA1145A_UNINIT == CanTrcv_43_tja1145a_eDriverStatus)
	{
		Status = TJA1145A_FAIL;
	}
	else if (Transceiver >= CanTrcv_43_tja1145a_pDriverConfig->DeviceNum)
	{
		/* [SWS_CanTrcv_00202] */
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_READ_TRCV_SILENCE_FLAG,
				(uint8) CANTRCV_43_TJA1145A_E_INVALID_TRANSCEIVER);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
		Status = TJA1145A_FAIL;
	}
	else if (NULL_PTR == FlagState)
	{
		/* [SWS_CanTrcv_00203] */
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_READ_TRCV_SILENCE_FLAG,
				(uint8) CANTRCV_43_TJA1145A_E_PARAM_POINTER);
#endif
		Status = TJA1145A_FAIL;
	}
	else
	{
		/* [SWS_CanTrcv_00217] Read silence flag. */
		Status = CanTrcv_43_tja1145a_Ipw_ReadSilenceFlag(Transceiver, FlagState);
	}
	
	return (Std_ReturnType)((TJA1145A_SUCCESS == Status) ? E_OK : E_NOT_OK);
}

/*================================================================================================*/
/**
* @brief		Sets PN functionality state. SID 0x0F.
* @details		Enables/disables PN feature.
*
* @param[in]	ActivationState		Enables/disables PN wakeup functionality.
*
* @return       Std_ReturnType		Result of the transition.
* @retval       E_OK				Operation executed successfully.
* @retval       E_NOT_OK			Operation failed.
*
*
* @pre			CanTrcv module should be initialized before calling the CanTrcv_43_tja1145a_SetPNActivationState method.
* @post         CanTrcv_43_tja1145a_SetPNActivationState shall set mode of PN feature.          
*
* @api
*/
/** @implements     CanTrcv_43_tja1145a_SetPNActivationState_Activity */
Std_ReturnType CanTrcv_43_tja1145a_SetPNActivationState(CanTrcv_tja1145a_PNActivationType ActivationState)
{
	uint8 Transceiver = 0U;
	CanTrcv_tja1145a_StatusType Status = TJA1145A_SUCCESS;

	if (CANTRCV_43_TJA1145A_UNINIT == CanTrcv_43_tja1145a_eDriverStatus)
	{
		/* [SWS_CanTrcv_00220] */
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_SET_PN_ACTIVATION_STATE,
				(uint8) CANTRCV_43_TJA1145A_E_UNINIT);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */

		Status = TJA1145A_FAIL;
	}
	else
	{
		for (Transceiver = 0U;
			(Transceiver < CanTrcv_43_tja1145a_pDriverConfig->DeviceNum) && (TJA1145A_SUCCESS == Status);
			 Transceiver++)
		{
			Status = CanTrcv_43_tja1145a_Ipw_SetPnMode(Transceiver, ActivationState);
		}
	}
	
	return (Std_ReturnType)((TJA1145A_SUCCESS == Status) ? E_OK : E_NOT_OK);
}

/*================================================================================================*/
/**
* @brief		Clears POR flag.
* @details		Clears POR flag.  
*
* @param[in]    Transceiver			CAN transceiver ID.
*
* @return       Std_ReturnType		Result of the transition.
* @retval       E_OK				Operation executed successfully.
* @retval       E_NOT_OK			Operation failed.
*
*
* @pre			CanTrcv module should be initialized before calling the CanTrcv_43_tja1145a_Exts_ClearPorFlag method.
* @post         CanTrcv_43_tja1145a_Exts_ClearPorFlag shall clear POR flag.           
*
* @api
*/
/** @implements   CanTrcv_43_tja1145a_Exts_ClearPorFlag_Activity */
Std_ReturnType CanTrcv_43_tja1145a_Exts_ClearPorFlag(uint8 Transceiver)
{
	CanTrcv_tja1145a_StatusType Status = TJA1145A_FAIL;
	
	if (CANTRCV_43_TJA1145A_UNINIT == CanTrcv_43_tja1145a_eDriverStatus)
	{
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_CLEAR_POR_FLAG,
				(uint8) CANTRCV_43_TJA1145A_E_UNINIT);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
	else if (Transceiver >= CanTrcv_43_tja1145a_pDriverConfig->DeviceNum)
	{
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_CLEAR_POR_FLAG,
				(uint8) CANTRCV_43_TJA1145A_E_INVALID_TRANSCEIVER);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
	else
	{
		Status = CanTrcv_43_tja1145a_Ipw_ClearPorFlag(Transceiver);
	}
	
	return (Std_ReturnType)((TJA1145A_SUCCESS == Status) ? E_OK : E_NOT_OK);
}

/*================================================================================================*/
/**
* @brief		Clears system error.
* @details		Clears following system error flags: overtemperature, PN frame error, CAN bus silence,
*				can failure (Tx dominant timeout).
*				Following flags are read only: PN configuration status (if set, PN must be reconfigured),
*				VCC/VIO undervoltage, oscillator error. This functions fails on an attempt to clear any
*				of these read only flags.
*
* @param[in]    Transceiver			CAN transceiver ID.
* @param[out]	SystemError			Which system error to clear.
*
* @return       Std_ReturnType		Result of the transition
* @retval       E_OK				Operation executed successfully.
* @retval       E_NOT_OK			Operation failed.
*
*
* @pre			CanTrcv module should be initialized before calling the CanTrcv_43_tja1145a_Exts_ClearSystemError method.
* @post         CanTrcv_43_tja1145a_Exts_ClearSystemError shall clear system error flag.           
*
* @api
*/
/** @implements   CanTrcv_43_tja1145a_Exts_ClearSystemError_Activity */
Std_ReturnType CanTrcv_43_tja1145a_Exts_ClearSystemError(uint8 Transceiver, CanTrcv_tja1145a_SystemErrorType SystemError)
{
	CanTrcv_tja1145a_StatusType Status = TJA1145A_FAIL;
	
	if (CANTRCV_43_TJA1145A_UNINIT == CanTrcv_43_tja1145a_eDriverStatus)
	{
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_CLEAR_SYSTEM_ERROR,
				(uint8) CANTRCV_43_TJA1145A_E_UNINIT);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
	else if (Transceiver >= CanTrcv_43_tja1145a_pDriverConfig->DeviceNum)
	{
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_CLEAR_SYSTEM_ERROR,
				(uint8) CANTRCV_43_TJA1145A_E_INVALID_TRANSCEIVER);
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}
	else
	{
		Status = CanTrcv_43_tja1145a_Ipw_ClearSystemErrorStatus(Transceiver, SystemError);
	}
	
	return (Std_ReturnType)((TJA1145A_SUCCESS == Status) ? E_OK : E_NOT_OK);
}

/*================================================================================================*/
/**
* @brief		Writes general purpose memory register.
* @details		Writes one of 4 available general purpose memory registers.
*
* @param[in]    Transceiver			CAN transceiver ID.
* @param[in]    MemRegister			Which memory register to access.
* @param[in]    Data    			Data to write to given memory register.
*
* @return       Std_ReturnType		Result of the transition
* @retval       E_OK				Operation executed successfully.
* @retval       E_NOT_OK			Operation failed.
*
*
* @pre			CanTrcv module should be initialized before calling the CanTrcv_43_tja1145a_Exts_WriteMemoryRegister method.
* @post         CanTrcv_43_tja1145a_Exts_WriteMemoryRegister shall write data to given memory register.           
*
* @api
*/
/** @implements     CanTrcv_43_tja1145a_Exts_WriteMemoryRegister_Activity */
Std_ReturnType CanTrcv_43_tja1145a_Exts_WriteMemoryRegister(uint8 Transceiver, CanTrcv_tja1145a_MemoryRegisterType MemRegister, uint8 Data)
{
    CanTrcv_tja1145a_StatusType Status = TJA1145A_FAIL;
	
	if (CANTRCV_43_TJA1145A_UNINIT == CanTrcv_43_tja1145a_eDriverStatus)
	{
		Status = TJA1145A_FAIL;
	}
	else if (Transceiver >= CanTrcv_43_tja1145a_pDriverConfig->DeviceNum)
	{
		Status = TJA1145A_FAIL;
	}
    else if (TJA1145A_SUCCESS != CanTrcv_43_tja1145a_CheckMemoryRegister(MemRegister))
	{
		Status = TJA1145A_FAIL;
	}
	else
	{
		Status = CanTrcv_43_tja1145a_Ipw_WriteMemoryRegister(Transceiver, MemRegister, Data);
	}
	
    return (Std_ReturnType)((TJA1145A_SUCCESS == Status) ? E_OK : E_NOT_OK);
}

/*================================================================================================*/
/**
* @brief		Reads general purpose memory register.
* @details		Reads one of 4 available general purpose memory registers.
*
* @param[in]    Transceiver			CAN transceiver ID.
* @param[in]    MemRegister			Which memory register to access.
* @param[out]   Data    			Stores content of given memory register.
*
* @return       Std_ReturnType		Result of the transition
* @retval       E_OK				Operation executed successfully.
* @retval       E_NOT_OK			Operation failed.
*
*
* @pre			CanTrcv module should be initialized before calling the CanTrcv_43_tja1145a_Exts_ReadMemoryRegister method.
* @post         CanTrcv_43_tja1145a_Exts_ReadMemoryRegister shall read content of given memory register.           
*
* @api
*/
/** @implements     CanTrcv_43_tja1145a_Exts_ReadMemoryRegister_Activity */
Std_ReturnType CanTrcv_43_tja1145a_Exts_ReadMemoryRegister(uint8 Transceiver, CanTrcv_tja1145a_MemoryRegisterType MemRegister, uint8* Data)
{
    CanTrcv_tja1145a_StatusType Status = TJA1145A_FAIL;
	
	if (CANTRCV_43_TJA1145A_UNINIT == CanTrcv_43_tja1145a_eDriverStatus)
	{
		Status = TJA1145A_FAIL;
	}
	else if (Transceiver >= CanTrcv_43_tja1145a_pDriverConfig->DeviceNum)
	{
		Status = TJA1145A_FAIL;
	}
	else if (NULL_PTR == Data)
	{
		Status = TJA1145A_FAIL;
	}
    else if (TJA1145A_SUCCESS != CanTrcv_43_tja1145a_CheckMemoryRegister(MemRegister))
	{
		Status = TJA1145A_FAIL;
	}
	else
	{
		Status = CanTrcv_43_tja1145a_Ipw_ReadMemoryRegister(Transceiver, MemRegister, Data);
	}
	
    return (Std_ReturnType)((TJA1145A_SUCCESS == Status) ? E_OK : E_NOT_OK);
}

/*================================================================================================*/
/**
* @brief		Locks/unlocks register groups.
* @details		Each item in the configuration structure locks/unlocks respective register groups.
*               lockRange06h09h - locks/unlocks register within address range 06h - 09h,
*               lockRange10h1Fh - locks/unlocks register within address range 10h - 1Fh,
*               lockRange20h2Fh - locks/unlocks register within address range 20h - 2Fh,
*               lockRange30h3Fh - locks/unlocks register within address range 30h - 3Fh,
*               lockRange40h4Fh - locks/unlocks register within address range 40h - 4Fh,
*               lockRange50h5Fh - locks/unlocks register within address range 50h - 5Fh,
*               lockRange68h6Fh - locks/unlocks register within address range 68h - 6Fh.
*
* @param[in]    Transceiver			CAN transceiver ID.
* @param[in]    MemRegister			Which memory register to access.
* @param[out]   Data    			Stores content of given memory register.
*
* @return       Std_ReturnType		Result of the transition
* @retval       E_OK				Operation executed successfully.
* @retval       E_NOT_OK			Operation failed.
*
*
* @pre			CanTrcv module should be initialized before calling the CanTrcv_43_tja1145a_Exts_SetLockControlRegister method.
* @post         CanTrcv_43_tja1145a_Exts_SetLockControlRegister shall read content of given memory register.           
*
* @api
*/
/** @implements     CanTrcv_43_tja1145a_Exts_SetLockControlRegister_Activity */
Std_ReturnType CanTrcv_43_tja1145a_Exts_SetLockControlRegister(uint8 Transceiver, const CanTrcv_tja1145a_LockRegistersType* LockControl)
{
    CanTrcv_tja1145a_StatusType Status = TJA1145A_FAIL;
	
	if (CANTRCV_43_TJA1145A_UNINIT == CanTrcv_43_tja1145a_eDriverStatus)
	{
		Status = TJA1145A_FAIL;
	}
	else if (Transceiver >= CanTrcv_43_tja1145a_pDriverConfig->DeviceNum)
	{
		Status = TJA1145A_FAIL;
	}
	else if (NULL_PTR == LockControl)
	{
		Status = TJA1145A_FAIL;
	}
	else
	{
		Status = CanTrcv_43_tja1145a_Ipw_SetLockControlRegister(Transceiver, LockControl);
	}
	
    return (Std_ReturnType)((TJA1145A_SUCCESS == Status) ? E_OK : E_NOT_OK);
}

/*================================================================================================*/
/**
* @brief          De-initializes the CanTrcv module. SID 0x10.
* @details		  De-initialize all the transceivers.
*                 The CANTRCV module shall be de-initialized by CanTrcv_43_tja1145a_DeInit() service call.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      None
*
* @return         void
*
*
* @pre            Before transceiver de-initalization, the driver must be initialized and the transceivers must not be in Start state.
* @post           CanTrcv_43_tja1145a_DeInit shall de-initialize all the transceivers and set the driver in UNINIT state.
*
* @api
*/
/** @implements     CanTrcv_43_tja1145a_DeInit_Activity */
void CanTrcv_43_tja1145a_DeInit(void)
{
	CanTrcv_tja1145a_StatusType Status = TJA1145A_SUCCESS;
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
	CanTrcv_TrcvModeType CurrentOpMode = CANTRCV_TRCVMODE_STANDBY;
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	uint8 Transceiver = 0U;

	if (CANTRCV_43_TJA1145A_UNINIT == CanTrcv_43_tja1145a_eDriverStatus)
	{
		Status = TJA1145A_FAIL;
	}

	for (Transceiver = 0U;
		(Transceiver < CanTrcv_43_tja1145a_pDriverConfig->DeviceNum) && (TJA1145A_SUCCESS == Status);
		 Transceiver++)
	{
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
		/* [SWS_CanTrcv_91005] Check if the transceiver is in normal mode. */
		Status = CanTrcv_43_tja1145a_Ipw_GetOpMode(Transceiver, &CurrentOpMode);

		if (TJA1145A_SUCCESS == Status)
		{	
			if (CANTRCV_TRCVMODE_NORMAL != CurrentOpMode)
			{
				(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
					(uint8) CANTRCV_43_TJA1145A_INSTANCE,
					(uint8) CANTRCV_43_TJA1145A_SID_DEINIT,
					(uint8) CANTRCV_43_TJA1145A_E_TRCV_NOT_NORMAL);
					
				Status = TJA1145A_FAIL;
			}
			else
			{
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */

				/* [SWS_CanTrcv_91002] [SWS_CanTrcv_91003] Deinitialize each transceiver. */
				Status = CanTrcv_43_tja1145a_Ipw_Deinit(Transceiver);
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
			}
		}
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */
	}

#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
	/* [SWS_CanTrcv_91004] */
	if (TJA1145A_ERR_SPI == Status)
	{
		(void) Det_ReportError((uint16) CANTRCV_43_TJA1145A_MODULE_ID,
				(uint8) CANTRCV_43_TJA1145A_INSTANCE,
				(uint8) CANTRCV_43_TJA1145A_SID_DEINIT,
				(uint8) CANTRCV_43_TJA1145A_E_NO_TRCV_CONTROL);
	}
#endif /* (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON) */

	if (TJA1145A_SUCCESS == Status)
	{
		CanTrcv_43_tja1145a_eDriverStatus = CANTRCV_43_TJA1145A_UNINIT;
	}
}

/*================================================================================================*/
/**
* @brief          Service to scan all busses for wake up events and perform these event. SID 0x06.
* @details		  Scan transceivers for wake up event and reports such event.
*
* @param[in]      None
*
* @return         void
*
*
* @pre            
* @post           
*
* @api
*/
/** @implements     CanTrcv_43_tja1145a_MainFunction_Activity */
void CanTrcv_43_tja1145a_MainFunction(void)
{
	uint8 Transceiver;
	Std_ReturnType Status = (Std_ReturnType)E_OK;
	
	/* [SWS_CanTrcv_00112] Scan all buses in sleep and standby mode for wake up events. */
	for (Transceiver = 0U;
		(Transceiver < CanTrcv_43_tja1145a_pDriverConfig->DeviceNum) && ((Std_ReturnType)E_OK == Status);
		 Transceiver++)
	{
		Status = CanTrcv_43_tja1145a_CheckWakeup(Transceiver);
	}
}

/*================================================================================================*/
/**
* @brief          Reads the transceiver diagnostic status periodically and sets product/development accordingly. SID 0x08.
* @details		  Reads system error, and reports it if any.
*
* @param[in]      None
*
* @return         void
*
*
* @pre            
* @post           
*
* @api
*/
/** @implements     CanTrcv_43_tja1145a_MainFunctionDiagnostics_Activity */
void CanTrcv_43_tja1145a_MainFunctionDiagnostics(void)
{
	/* [SWS_CanTrcv_00204] Read transceiver status and report production/development errors accordingly. */
	uint8 Transceiver;
	uint16 SystemError = 0U;
	CanTrcv_tja1145a_StatusType Status = TJA1145A_SUCCESS;
	
	/* [SWS_CanTrcv_00112] Scan all buses in sleep and standby mode for wake up events. */
	for (Transceiver = 0U;
		(Transceiver < CanTrcv_43_tja1145a_pDriverConfig->DeviceNum) && (TJA1145A_SUCCESS == Status);
		 Transceiver++)
	{
		Status = CanTrcv_43_tja1145a_Ipw_GetSystemErrorStatus(Transceiver, &SystemError);

		if (TJA1145A_SUCCESS == Status)
		{
			if ((TJA1145A_NO_SYSTEM_ERROR != SystemError))
			{
			#if (CANTRCV_43_TJA1145A_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
				if ((uint32)STD_ON == CanTrcv_43_tja1145a_EcuMReportConfig[Transceiver].DemErrorReportConfig.state)
				{
					/* [SWS_CanTrcv_00206] Report event. */
					(void)Dem_SetEventStatus((Dem_EventIdType)CanTrcv_43_tja1145a_EcuMReportConfig[Transceiver].DemErrorReportConfig.id, DEM_EVENT_STATUS_FAILED);
				}
			#endif
			}
			else
			{
			#if (CANTRCV_43_TJA1145A_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
				if ((uint32)STD_ON == CanTrcv_43_tja1145a_EcuMReportConfig[Transceiver].DemErrorReportConfig.state)
				{
					/* [SWS_CanTrcv_00227] Report that no event took place. */
					(void)Dem_SetEventStatus((Dem_EventIdType)CanTrcv_43_tja1145a_EcuMReportConfig[Transceiver].DemErrorReportConfig.id, DEM_EVENT_STATUS_PASSED);
				}
			#endif
			}
		}
	}
}

#define CANTRCV_43_TJA1145A_STOP_SEC_CODE
#include "CanTrcv_43_tja1145a_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

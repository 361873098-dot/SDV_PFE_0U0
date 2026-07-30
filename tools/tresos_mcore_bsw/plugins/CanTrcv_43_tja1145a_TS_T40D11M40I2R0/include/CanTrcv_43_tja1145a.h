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
* @file         CanTrcv_43_tja1145a.h
* @version      0.8.0
*
* @brief        AUTOSAR CanTrcv_43_tja1145a - module interface.
*       		API header for TJA1145A driver.
*
*
* @addtogroup   CanTrcv_tja1145a_Driver
* @{
*/

#ifndef CANTRCV_CANTRCV_43_TJA1145A_H_
#define CANTRCV_CANTRCV_43_TJA1145A_H_

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Required Rule 8.5, symbol is declared more than once
* Symbol "CanTrcv_Config_VS_0" is declared in included header file, which is used in multiple locations.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 20.1, #include directive preceded by code
* These directives determine memory sections of variables and code, therefore they surround the obejcts they describe.
*
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "Can_GeneralTypes.h"
#include "CanTrcv_43_tja1145a_Ipw.h"
#include "CanIf.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
    Internal micro-dependent versioning. Check of AUTOSAR & Vendor specification version.
*/
#define CANTRCV_43_TJA1145A_VENDOR_ID                    43
#define CANTRCV_43_TJA1145A_MODULE_ID                    70
#define CANTRCV_43_TJA1145A_AR_RELEASE_MAJOR_VERSION     4
#define CANTRCV_43_TJA1145A_AR_RELEASE_MINOR_VERSION     7
#define CANTRCV_43_TJA1145A_AR_RELEASE_REVISION_VERSION  0
#define CANTRCV_43_TJA1145A_SW_MAJOR_VERSION             0
#define CANTRCV_43_TJA1145A_SW_MINOR_VERSION             8
#define CANTRCV_43_TJA1145A_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes header file are of the same version */
	#if ((CANTRCV_43_TJA1145A_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
		 (CANTRCV_43_TJA1145A_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
		#error "AutoSar Version Numbers of CanTrcv_43_tja1145a.h and StandardTypes.h are different"
	#endif

	/* Check if current file and Can_GeneralTypes header file are of the same version */
	#if ((CANTRCV_43_TJA1145A_AR_RELEASE_MAJOR_VERSION != CAN_GENERALTYPES_AR_RELEASE_MAJOR_VERSION) || \
		(CANTRCV_43_TJA1145A_AR_RELEASE_MINOR_VERSION != CAN_GENERALTYPES_AR_RELEASE_MINOR_VERSION))
		#error "AutoSar Version Numbers of CanTrcv_43_tja1145a.h and Can_GeneralTypes.h are different"
	#endif

    /* Check if current file and CanIf header file are of the same version */
    #if ((CANTRCV_43_TJA1145A_AR_RELEASE_MAJOR_VERSION != CANIF_AR_RELEASE_MAJOR_VERSION) || \
         (CANTRCV_43_TJA1145A_AR_RELEASE_MINOR_VERSION != CANIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of CanTrcv_43_tja1145a.h and CanIf.h are different"
    #endif
#endif

/* Check if current file and CanTrcv_43_tja1145a_Ipw header file are of the same vendor */
#if (CANTRCV_43_TJA1145A_VENDOR_ID != CANTRCV_43_TJA1145A_VENDOR_ID_IPW)
    #error "CanTrcv_43_tja1145a.h and CanTrcv_43_tja1145a_Ipw.h have different vendor ids"
#endif
/* Check if current file and CanTrcv_43_tja1145a_Ipw header file are of the same module */
#if (CANTRCV_43_TJA1145A_MODULE_ID != CANTRCV_43_TJA1145A_MODULE_ID_IPW)
    #error "CanTrcv_43_tja1145a.h and CanTrcv_43_tja1145a_Ipw.h have different module ids"
#endif
/* Check if current file and CanTrcv_43_tja1145a_Ipw header file are of the same Autosar version */
#if ((CANTRCV_43_TJA1145A_AR_RELEASE_MAJOR_VERSION    != CANTRCV_43_TJA1145A_AR_RELEASE_MAJOR_VERSION_IPW) || \
     (CANTRCV_43_TJA1145A_AR_RELEASE_MINOR_VERSION    != CANTRCV_43_TJA1145A_AR_RELEASE_MINOR_VERSION_IPW) || \
     (CANTRCV_43_TJA1145A_AR_RELEASE_REVISION_VERSION != CANTRCV_43_TJA1145A_AR_RELEASE_REVISION_VERSION_IPW))
    #error "AutoSar Version Numbers of CanTrcv_43_tja1145a.h and CanTrcv_43_tja1145a_Ipw.h are different"
#endif
/* Check if current file and CanTrcv_43_tja1145a_Ipw header file are of the same Software version */
#if ((CANTRCV_43_TJA1145A_SW_MAJOR_VERSION != CANTRCV_43_TJA1145A_SW_MAJOR_VERSION_IPW) || \
     (CANTRCV_43_TJA1145A_SW_MINOR_VERSION != CANTRCV_43_TJA1145A_SW_MINOR_VERSION_IPW) || \
     (CANTRCV_43_TJA1145A_SW_PATCH_VERSION != CANTRCV_43_TJA1145A_SW_PATCH_VERSION_IPW))
    #error "Software Version Numbers of CanTrcv_43_tja1145a.h and CanTrcv_43_tja1145a_Ipw.h are different"
#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#if (CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON)
/**
* @{
* @brief          Development errors.
* @details        The Can module shall be able to detect the following errors and exceptions depending
*				  on its configuration (development/production). Development Errors shall indicate errors
*				  that are caused by erroneous usage of the Can module API. This covers API parameter
*				  checks and call sequence errors.
*                 Development error values are of type uint8.
*
*/
#define  CANTRCV_43_TJA1145A_E_INVALID_TRANSCEIVER       (0x1U)
#define  CANTRCV_43_TJA1145A_E_PARAM_POINTER             (0x2U)
#define  CANTRCV_43_TJA1145A_E_UNINIT                    (0x11U)
#define  CANTRCV_43_TJA1145A_E_TRCV_NOT_STANDBY          (0x21U)
#define  CANTRCV_43_TJA1145A_E_TRCV_NOT_NORMAL           (0x22U)
#define  CANTRCV_43_TJA1145A_E_PARAM_TRCV_WAKEUP_MODE    (0x23U)
#define  CANTRCV_43_TJA1145A_E_PARAM_TRCV_OPMODE         (0x24U)
#define  CANTRCV_43_TJA1145A_E_BAUDRATE_NOT_SUPPORTED    (0x25U)
#define  CANTRCV_43_TJA1145A_E_NO_TRCV_CONTROL           (0x26U)
#define  CANTRCV_43_TJA1145A_E_INIT_FAILED               (0x27U)

/**
* @{
* @brief          Service ID (APIs) for Det reporting
* @details        Service ID (APIs) for Det reporting
*
*/
#define CANTRCV_43_TJA1145A_SID_INIT                          ((uint8)0x00U)
#define CANTRCV_43_TJA1145A_SID_SET_OPMODE                    ((uint8)0x01U)
#define CANTRCV_43_TJA1145A_SID_GET_OPMODE                    ((uint8)0x02U)
#define CANTRCV_43_TJA1145A_SID_GET_BUS_WU_REASON             ((uint8)0x03U)
#define CANTRCV_43_TJA1145A_SID_GET_VERSION_INFO              ((uint8)0x04U)
#define CANTRCV_43_TJA1145A_SID_SET_WAKEUP_MODE               ((uint8)0x05U)
#define CANTRCV_43_TJA1145A_SID_GET_TRCV_SYSTEM_DATA          ((uint8)0x09U)
#define CANTRCV_43_TJA1145A_SID_CLEAR_TRCV_WUF_FLAG           ((uint8)0x0AU)
#define CANTRCV_43_TJA1145A_SID_READ_TRCV_TIMEOUT_FLAG        ((uint8)0x0BU)
#define CANTRCV_43_TJA1145A_SID_CLEAR_TRCV_TIMEOUT_FLAG       ((uint8)0x0CU)
#define CANTRCV_43_TJA1145A_SID_READ_TRCV_SILENCE_FLAG        ((uint8)0x0DU)
#define CANTRCV_43_TJA1145A_SID_CHECK_WAKEUP                  ((uint8)0x07U)
#define CANTRCV_43_TJA1145A_SID_SET_PN_ACTIVATION_STATE       ((uint8)0x0FU)
#define CANTRCV_43_TJA1145A_SID_CHECK_WAKE_FLAG               ((uint8)0x0EU)
#define CANTRCV_43_TJA1145A_SID_DEINIT                        ((uint8)0x10U)

#define CANTRCV_43_TJA1145A_SID_CLEAR_POR_FLAG				  ((uint8)0x11U)
#define CANTRCV_43_TJA1145A_SID_CLEAR_SYSTEM_ERROR			  ((uint8)0x12U)

#endif /* CANTRCV_43_TJA1145A_DEV_ERROR_DETECT == STD_ON */

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/**
* @brief        CanTrcv_43_tja1145a_eDriverStatusType
* @details      Driver status helps to prevent double driver initialization.
*
*/
typedef enum
{
	/**< @brief Driver not initialized */
	CANTRCV_43_TJA1145A_UNINIT = 0x0U,
	/**< @brief Driver ready */
	CANTRCV_43_TJA1145A_READY  = 0x1U
} CanTrcv_43_tja1145a_eDriverStatusType;


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief		CanTrcv_43_tja1145a_DriverConfigType
* @details		Externally defined data structure containing the overall initialization
*               data for the CAN transceiver driver and settings of all transceivers.
*/
typedef struct
{
	/** @brief Number of devices controlled by the driver. The data type is uint8, 
	 * because Autosar API indexes connected devices with an index of type uint8. */
	uint8 DeviceNum;
	/** @brief Pointer to an array of device snd SPI configuration structures. */
	const CanTrcv_tja1145a_ConfigurationDataType* ConfigData;
} CanTrcv_43_tja1145a_DriverConfigType;

/**
* @brief		Wake up source reference configuration.
* @details		ECU manager defines wake up sources (POR, standard wake up and system error).
*               This structure stores configuration of such wake up source.
*/
typedef struct
{
    /** @brief Wake up source enabled/disabled. */
    boolean WakeupSourceEn;
    /** @brief Reference to the wake up source defined in the ECU state manager. */
    EcuM_WakeupSourceType EcuMWakeupSource;
} CanTrcv_43_tja1145a_WakeupSourceRefType;

/**
* @brief		Stores wake up sources deined by ECU manager.
* @details		ECU manager defines wake up sources which are used by the driver for reporting
*               wake up events to the ECU state manager.
*/
typedef struct
{
    /** @brief Configuration of standard wake up source used in reports to ECU manager. */
    CanTrcv_43_tja1145a_WakeupSourceRefType WakeupSourceConfig;
    /** @brief Configuration of POR wake up source used in reports to ECU manager. */
    CanTrcv_43_tja1145a_WakeupSourceRefType PorWakeupSourceConfig;
    /** @brief Configuration of SYSERR wake up source used in reports to ECU manager. */
    CanTrcv_43_tja1145a_WakeupSourceRefType SysErrWakeupSourceConfig;
#if (CANTRCV_43_TJA1145A_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
	/** @brief DEM reporting configuration. */
	Mcal_DemErrorType DemErrorReportConfig;
#endif
} CanTrcv_43_tja1145a_EcuMReportType;

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define CANTRCV_43_TJA1145A_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_43_tja1145a_MemMap.h"

#if (CANTRCV_43_TJA1145A_PRECOMPILE_SUPPORT == STD_ON)
/**
* @brief Default driver and device configuration.
*
*/
extern const CanTrcv_43_tja1145a_DriverConfigType CanTrcv_43_tja1145a_Config_Predefined;
#else
#ifdef CANTRCV_43_TJA1145A_CONFIG_EXT
/**
* @brief Extern driver and device configuration structures.
*/
CANTRCV_43_TJA1145A_CONFIG_EXT
#endif
#endif

#define CANTRCV_43_TJA1145A_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_43_tja1145a_MemMap.h"

#define CANTRCV_43_TJA1145A_START_SEC_VAR_INIT_UNSPECIFIED
#include "CanTrcv_43_tja1145a_MemMap.h"
/**
* @brief Holds current status/run-time of CANTRCV driver: CANTRCV_43_TJA1145A_UNINIT or
*        CANTRCV_43_TJA1145A_READY.
*
*/
extern volatile CanTrcv_43_tja1145a_eDriverStatusType CanTrcv_43_tja1145a_eDriverStatus;

#define CANTRCV_43_TJA1145A_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CanTrcv_43_tja1145a_MemMap.h"

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define CANTRCV_43_TJA1145A_START_SEC_CODE
#include "CanTrcv_43_tja1145a_MemMap.h"

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
void CanTrcv_43_tja1145a_Init(const CanTrcv_43_tja1145a_DriverConfigType* ConfigPtr);

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
Std_ReturnType CanTrcv_43_tja1145a_SetOpMode(uint8 Transceiver, CanTrcv_TrcvModeType OpMode);

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
Std_ReturnType CanTrcv_43_tja1145a_GetOpMode(uint8 Transceiver, CanTrcv_TrcvModeType* OpMode);

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
Std_ReturnType CanTrcv_43_tja1145a_GetBusWuReason(uint8 Transceiver, CanTrcv_TrcvWakeupReasonType* Reason);

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
void CanTrcv_43_tja1145a_GetVersionInfo(Std_VersionInfoType* VersionInfo);
#endif /* CANTRCV_43_TJA1145A_VERSION_INFO_API == STD_ON */

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
Std_ReturnType CanTrcv_43_tja1145a_GetTrcvSystemData(uint8 Transceiver, uint32* TrcvSysData);

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
Std_ReturnType CanTrcv_43_tja1145a_ClearTrcvWufFlag(uint8 Transceiver);

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
Std_ReturnType CanTrcv_43_tja1145a_SetWakeupMode(uint8 Transceiver, CanTrcv_TrcvWakeupModeType TrcvWakeupMode);

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
Std_ReturnType CanTrcv_43_tja1145a_CheckWakeup(uint8 Transceiver);

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
Std_ReturnType CanTrcv_43_tja1145a_CheckWakeFlag(uint8 Transceiver);

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
Std_ReturnType CanTrcv_43_tja1145a_ReadTrcvTimeoutFlag(uint8 Transceiver, CanTrcv_tja1145a_TrcvFlagStateType* FlagState);

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
Std_ReturnType CanTrcv_43_tja1145a_ClearTrcvTimeoutFlag(uint8 Transceiver);

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
Std_ReturnType CanTrcv_43_tja1145a_ReadTrcvSilenceFlag(uint8 Transceiver, CanTrcv_tja1145a_TrcvFlagStateType* FlagState);

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
Std_ReturnType CanTrcv_43_tja1145a_SetPNActivationState(CanTrcv_tja1145a_PNActivationType ActivationState);

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
Std_ReturnType CanTrcv_43_tja1145a_Exts_ClearPorFlag(uint8 Transceiver);

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
Std_ReturnType CanTrcv_43_tja1145a_Exts_ClearSystemError(uint8 Transceiver, CanTrcv_tja1145a_SystemErrorType SystemError);

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
Std_ReturnType CanTrcv_43_tja1145a_Exts_WriteMemoryRegister(uint8 Transceiver, CanTrcv_tja1145a_MemoryRegisterType MemRegister, uint8 Data);

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
Std_ReturnType CanTrcv_43_tja1145a_Exts_ReadMemoryRegister(uint8 Transceiver, CanTrcv_tja1145a_MemoryRegisterType MemRegister, uint8* Data);

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
Std_ReturnType CanTrcv_43_tja1145a_Exts_SetLockControlRegister(uint8 Transceiver, const CanTrcv_tja1145a_LockRegistersType* LockControl);

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
void CanTrcv_43_tja1145a_MainFunction(void);

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
void CanTrcv_43_tja1145a_MainFunctionDiagnostics(void);

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
void CanTrcv_43_tja1145a_DeInit(void);

#define CANTRCV_43_TJA1145A_STOP_SEC_CODE
#include "CanTrcv_43_tja1145a_MemMap.h"

#endif /* CANTRCV_CANTRCV_43_TJA1145A_H_ */

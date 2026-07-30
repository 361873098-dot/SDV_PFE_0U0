/**
*   @file    Fr.h
*   @version 4.0.2
*
*   @brief   AUTOSAR Fr - module interface.
*   @details API header for FR driver.
*   @implements Fr.h_Artifact
*
*   @addtogroup FR_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : FLEXRAY
*   Dependencies         : none
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

#ifndef FR_H
#define FR_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fr_GeneralTypes.h"
#include "Fr_Cfg.h"
#include "Fr_Ipw_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
 * @brief Parameters that shall be published within the driver header file and also in the
 *        module's description file
 */
#define FR_MODULE_ID                        81
#define FR_VENDOR_ID                        43
#define FR_AR_RELEASE_MAJOR_VERSION         4
#define FR_AR_RELEASE_MINOR_VERSION         4
#define FR_AR_RELEASE_REVISION_VERSION      0
#define FR_SW_MAJOR_VERSION                 4
#define FR_SW_MINOR_VERSION                 0
#define FR_SW_PATCH_VERSION                 2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fr_Cfg.h header file are of the same vendor */
#if(FR_VENDOR_ID != FR_CFG_VENDOR_ID)
    #error "Fr.h and Fr_Cfg.h have different Vendor IDs"
#endif
/* Check if current file and Fr_Cfg.h header file are of the same Autosar version */
#if((FR_AR_RELEASE_MAJOR_VERSION    != FR_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (FR_AR_RELEASE_MINOR_VERSION    != FR_CFG_AR_RELEASE_MINOR_VERSION) || \
    (FR_AR_RELEASE_REVISION_VERSION != FR_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Fr.h and Fr_Cfg.h are different"
#endif
/* Check if current file and Fr_Cfg.h header file are of the same software version */
#if((FR_SW_MAJOR_VERSION != FR_CFG_SW_MAJOR_VERSION) || \
    (FR_SW_MINOR_VERSION != FR_CFG_SW_MINOR_VERSION) || \
    (FR_SW_PATCH_VERSION != FR_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fr.h and Fr_Cfg.h are different"
#endif
/* Check if current file and Fr_Ipw_Types.h header file are of the same vendor */
#if(FR_VENDOR_ID != FR_IPW_TYPES_VENDOR_ID)
    #error "Fr.h and Fr_Ipw_Types.h have different Vendor IDs"
#endif
/* Check if current file and Fr_Ipw_Types.h header file are of the same Autosar version */
#if((FR_AR_RELEASE_MAJOR_VERSION    != FR_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
    (FR_AR_RELEASE_MINOR_VERSION    != FR_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
    (FR_AR_RELEASE_REVISION_VERSION != FR_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Fr.h and Fr_Ipw_Types.h are different"
#endif
/* Check if current file and Fr_Ipw_Types.h header file are of the same software version */
#if((FR_SW_MAJOR_VERSION != FR_IPW_TYPES_SW_MAJOR_VERSION) || \
    (FR_SW_MINOR_VERSION != FR_IPW_TYPES_SW_MINOR_VERSION) || \
    (FR_SW_PATCH_VERSION != FR_IPW_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fr.h and Fr_Ipw_Types.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Fr_GeneralTypes.h header file are of the same Autosar version */
    #if((FR_AR_RELEASE_MAJOR_VERSION != FR_GENERALTYPES_AR_RELEASE_MAJOR_VERSION) || \
        (FR_AR_RELEASE_MINOR_VERSION != FR_GENERALTYPES_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Fr.h and Fr_GeneralTypes.h are different"
    #endif
#endif /* CHECK_AUTOSAR_VERSION */
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief Error reported when parameter timer index exceeds number of available timers
* @implements  Fr_DetErrorIds_define
* */
#define FR_E_INV_TIMER_IDX                              ((uint8)0x01U)
/**
* @brief Error reported when invalid pointer in parameter list
* @implements  Fr_DetErrorIds_define
* */
#define FR_E_PARAM_POINTER                              ((uint8)0x02U)
/**
* @brief Error reported when parameter offset exceeds bounds
* @implements  Fr_DetErrorIds_define
* */
#define FR_E_INV_OFFSET                                 ((uint8)0x03U)
/**
* @brief Error reported when invalid controller index
* @implements  Fr_DetErrorIds_define
* */
#define FR_E_INV_CTRL_IDX                               ((uint8)0x04U)
/**
* @brief Error reported when invalid channel index
* @implements  Fr_DetErrorIds_define
* */
#define FR_E_INV_CHNL_IDX                               ((uint8)0x05U)
/**
* @brief Error reported when parameter cycle exceeds 63
* @implements  Fr_DetErrorIds_define
* */
#define FR_E_INV_CYCLE                                  ((uint8)0x06U)
/**
* @brief Error reported when Fr module was not initialized
* @implements  Fr_DetErrorIds_define
* */
#define FR_E_INIT_FAILED                                ((uint8)0x08U)
/**
* @brief Error reported when Fr CC is not in the expected POC state
* @implements  Fr_DetErrorIds_define
* */
#define FR_E_INV_POCSTATE                               ((uint8)0x09U)
/**
* @brief Error reported when Payload length parameter has an invalid value
* @implements  Fr_DetErrorIds_define
* */
#define FR_E_INV_LENGTH                                 ((uint8)0x0AU)
/**
* @brief Error reported when invalid LPdu index
* @implements  Fr_DetErrorIds_define
* */
#define FR_E_INV_LPDU_IDX                               ((uint8)0x0BU)
/**
* @brief Error reported when invalid FlexRay header CRC
* @implements  Fr_DetErrorIds_define
* */
#define FR_E_INV_HEADERCRC                              ((uint8)0x0CU)
/**
* @brief Error reported when invalid value passed as parameter Fr_ConfigParamIdx.
* @implements  Fr_DetErrorIds_define
* */
#define FR_E_INV_CONFIG_IDX                             ((uint8)0x0DU)
/**
* @brief Error reported when invalid framelist size value.
* @implements  Fr_DetErrorIds_define
* */
#define FR_E_INV_FRAMELIST_SIZE                         ((uint8)0x0EU)
/**
* @brief Error reported when requested resource is not configured to be available
* on the current core
* @implements  Fr_DetErrorIds_define
* */
#define FR_E_PARAM_CONFIG                               ((uint8)0x0FU)

/* Service ID for DET reporting */
#define FR_SID_INIT_U8                                  ((uint8)0x1CU)
#define FR_SID_CONTROLLERINIT_U8                        ((uint8)0x00U)
#define FR_SID_STARTCOMMUNICATION_U8                    ((uint8)0x03U)
#define FR_SID_HALTCOMMUNICATION_U8                     ((uint8)0x04U)
#define FR_SID_ABORTCOMMUNICATION_U8                    ((uint8)0x05U)
#define FR_SID_SENDWUP_U8                               ((uint8)0x06U)
#define FR_SID_SETWAKEUPCHANNEL_U8                      ((uint8)0x07U)
#define FR_SID_GETPOCSTATUS_U8                          ((uint8)0x0AU)
#define FR_SID_TRANSMITTXLPDU_U8                        ((uint8)0x0BU)
#define FR_SID_RECEIVERXLPDU_U8                         ((uint8)0x0CU)
#define FR_SID_CHECKTXLPDUSTATUS_U8                     ((uint8)0x0DU)
#define FR_SID_GETGLOBALTIME_U8                         ((uint8)0x10U)
#define FR_SID_SETABSTIMER_U8                           ((uint8)0x11U)
#define FR_SID_CANCELABSTIMER_U8                        ((uint8)0x13U)
#define FR_SID_ENABLEABSTIMERIRQ_U8                     ((uint8)0x15U)
#define FR_SID_ACKABSTIMERIRQ_U8                        ((uint8)0x17U)
#define FR_SID_DISABLEABSTIMERIRQ_U8                    ((uint8)0x19U)
#define FR_SID_GETVERSIONINFO_U8                        ((uint8)0x1BU)
#define FR_SID_PREPARELPDU_U8                           ((uint8)0x1FU)
#define FR_SID_GETABSTIMERIRQSTATUS_U8                  ((uint8)0x20U)
#define FR_SID_GETNMVECTOR_U8                           ((uint8)0x22U)
#define FR_SID_ALLOWCOLDSTART_U8                        ((uint8)0x23U)
#define FR_SID_ALLSLOTS_U8                              ((uint8)0x24U)
#define FR_SID_RECONFIGLPDU_U8                          ((uint8)0x25U)
#define FR_SID_DISABLELPDU_U8                           ((uint8)0x26U)
#define FR_SID_GETNUMOFSTARTUPFRAMES_U8                 ((uint8)0x27U)
#define FR_SID_GETCHANNELSTATUS_U8                      ((uint8)0x28U)
#define FR_SID_GETCLOCKCORRECTION_U8                    ((uint8)0x29U)
#define FR_SID_GETSYNCFRAMELIST_U8                      ((uint8)0x2AU)
#define FR_SID_GETWAKEUPRXSTATUS_U8                     ((uint8)0x2BU)
#define FR_SID_CANCELTXLPDU_U8                          ((uint8)0x2DU)
#define FR_SID_READCCCONFIG_U8                          ((uint8)0x2EU)
#if(FR_DEINIT_API == STD_ON)
#define FR_SID_DEINIT_U8                                ((uint8)0x2FU)
#endif
/* Halt command macro */
/* This value is used to enable/disable FR Controler disabled mode */
/* STD_ON means that hardware allows to enable FR CC (set MEN bit) only once */
/* STD_OFF means that hardware allows to re-enable FR CC (set and clear MEN bit) more than once */
#define FR_CC_ONCE_ENABLEONLYMODE (STD_OFF)

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/***************************************************************************************************
* @enum Fr_StorageType
*  @brief This type is used to specify type of the message buffer.
***************************************************************************************************/
typedef enum
{
    FR_FIFOA_BUFFER = 0U,  /* Use a FIFOA */
    FR_FIFOB_BUFFER = 1U,  /* Use a FIFOB */
    FR_IND_BUFFER       /* Use an independent MB*/
} Fr_StorageType;


#if(FR_DEV_ERROR_DETECT == STD_ON)
/***************************************************************************************************
* @enum Fr_SoftwareStatesType
*  @brief Type of software states.
***************************************************************************************************/
typedef enum
{
    FR_STATE_UNINIT = 0U,  /* Flexray un-init */
    FR_STATE_INIT          /* Flexray init */
#if(FR_DEINIT_API == STD_ON)
    ,FR_STATE_DEINIT_FALSE  /* De-init false */
#endif
} Fr_SoftwareStatesType;
#endif
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/***************************************************************************************************
* @struct Fr_CCLpduInfoType
*  @brief Each individual MB is configured through this structure
*  @details The instance of the type Fr_CCLpduInfoType is an array of configuration structures.
*   Each item in this array describes one LPdu and its connection to a buffer
***************************************************************************************************/
typedef struct
{
    /* Buffer type */
    const Fr_StorageType StorageType;
    /* Reference to buffer configuration structure */
    const uint8 BufferConfigIndex;
    /* Buffer is Reconfigurable */
    const boolean Reconfigurable;
    /* DemEventId */
    const uint16  DemFTSlotStatus;
    /* DemFTSlotSTatusRefExist exist */
    const boolean DemFTSlotSTatusRefExist;
} Fr_CCLpduInfoType;

/***************************************************************************************************
* @struct Fr_DemErrorType
*  @details The structure contains Configuration of DEM message
***************************************************************************************************/
typedef struct
{
    const uint32 state;  /* Enable/Disable reporting of DEM messages */
    const uint32 id;   /* ID of DEM message */
} Fr_DemErrorType;

/***************************************************************************************************
*  @struct Fr_CCLowLevelConfigSetType
*  @details The structure of the type Fr_CCLowLevelConfigSetType contains the FlexRay protocol
*   specific parameters. The configuration information corresponds with the contents of the FlexRay
*   module Protocol Configuration Registers (registers PCR0 to PCR30), the FlexRay Protocol
*   Specification, the AUTOSAR FlexRay Driver and the FlexRay Interface specifications. The FlexRay
*   Driver uses these values for Protocol Configuration Registers initialization and for internal
*   operations.
***************************************************************************************************/
typedef struct
{
    const uint32 RegPCR0_1;    /* Protocol Configuration Registers  0, 1 values */
    const uint32 RegPCR2_3;    /* Protocol Configuration Registers  2, 3 values */
    const uint32 RegPCR4_5;    /* Protocol Configuration Registers  4, 5 values */
    const uint32 RegPCR6_7;    /* Protocol Configuration Registers  6, 7 values */
    const uint32 RegPCR8_9;    /* Protocol Configuration Registers  8, 9 values */
    const uint32 RegPCR10_11;  /* Protocol Configuration Registers 10,11 values */
    const uint32 RegPCR12_13;  /* Protocol Configuration Registers 12,13 values */
    const uint32 RegPCR14_15;  /* Protocol Configuration Registers 14,15 values */
    const uint32 RegPCR16_17;  /* Protocol Configuration Registers 16,17 values */
    const uint32 RegPCR18_19;  /* Protocol Configuration Registers 18,19 values */
    const uint32 RegPCR20_21;  /* Protocol Configuration Registers 20,21 values */
    const uint32 RegPCR22_23;  /* Protocol Configuration Registers 22,23 values */
    const uint32 RegPCR24_25;  /* Protocol Configuration Registers 24,25 values */
    const uint32 RegPCR26_27;  /* Protocol Configuration Registers 26,27 values */
    const uint32 RegPCR28_29;  /* Protocol Configuration Registers 28,29 values */
    const uint16 RegPCR30;     /* Protocol Configuration Register 30 value */
    /* FlexRay parameter gNumberoftaticslots */
    const uint16 gNumberOfStaticSlots;
    /* pPayloadLengthDynMax */
    const uint8 pPayloadLengthDynMax;
    /* gPayloadLengthStatic */
    const uint8 gPayloadLengthStatic;
} Fr_CCLowLevelConfigSetType;

/***************************************************************************************************
* @struct Fr_CtrlCfgType
*  @details The structure of the type Fr_CtrlCfgType is a top level descriptor containing
*   possible configurations of one FlexRay driver and one multiple configuration..
***************************************************************************************************/
typedef struct
{
    /* Controller index of the FlexRay module */
    const uint8 CtrlIdx;
    /* Reference to SDK configuration */
    Fr_Ipw_Types_ConfigType* IpConfigPtr;
    /* reference to sdk buffers */
    Fr_Ipw_Types_StateAllocateType* IpStateAllocPtr;
    /* The total number of LPDU */
    const uint16 LpduConfiguredCount;
    /* Reference to array of message buffer configuration sets  */
    const Fr_CCLpduInfoType* LpduInfoPtr;
    /* Reference to array of Low Level Configuration structures */
    const Fr_CCLowLevelConfigSetType* LowLevelConfigSetPtr;
    /* Reference to array of FlexRay Protocol Configuration parameters */
    const uint32* CCReadBackConfigSetPtr;
    /* Referece to FrDemCtrlTestResult */
    const Fr_DemErrorType* FrDemCtrlTestResultPtr;
} Fr_CtrlCfgType;

/***************************************************************************************************
* @struct Fr_ConfigurationType
*  @details The structure of the type Fr_ConfigurationType is a top level descriptor containing
*   possible configurations of one FlexRay driver and one multiple configuration.The structure of
*   this type is passed via void pointer to the function Fr_Init().
***************************************************************************************************/
typedef struct
{
    const Fr_CtrlCfgType* Fr_pController[FR_NUM_CTRL_SUPPORTED];
    uint32 u32ParCoreId;
} Fr_ConfigurationType;

/***************************************************************************************************
* @typedef Fr_ConfigType
*  @brief   Basic configuration type. Pointer to this type is passed to the Fr_Init() function.
*  @implements  Fr_ConfigType_typedef
***************************************************************************************************/
typedef Fr_ConfigurationType Fr_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define FR_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fr_MemMap.h"
#if (FR_VARIANT_PRECOMPILE == STD_OFF)
    FR_CONFIG_EXT
#endif
#define FR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fr_MemMap.h"


#define FR_START_SEC_VAR_INIT_BOOLEAN
#include "Fr_MemMap.h"

/* The permission for enabling FR module */
extern boolean Fr_abModuleEnablePermission[FR_ECUC_PARTITION];

#define FR_STOP_SEC_VAR_INIT_BOOLEAN
#include "Fr_MemMap.h"
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
/**
* @brief         Software module version query.
* @details       [SWS_Fr_00341]: The function Fr_GetVersionInfo shall return the version information
*                of this module
* @param[out]    VersioninfoPtr Std_VersionInfoType type pointer where to store version numbers

* @return        void.
*
* @implements    Fr_GetVersionInfo_Activity
*/
void Fr_GetVersionInfo(Std_VersionInfoType* VersioninfoPtr);
/**
* @brief            Initializes the Fr.
* @details          [SWS_Fr_00137]: The function Fr_Init shall internally store the configuration address
*                   to enable subsequent API calls to access the configuration.
* @param[in]        Fr_ConfigPtr  Pointer to the Controller configuration
* @return           void.
*
* @implements       Fr_Init_Activity
*/
void Fr_Init(const Fr_ConfigType* Fr_ConfigPtr);
/*!
* @brief            CC configuration
* @details          [SWS_Fr_00148]: Switch CC into POC:Config, configures all FlexRay
*                   cluster and node configuration parameters, configures all
*                   transmit or receive resources and switch CC into POC:Ready
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @return           Std_ReturnType
*                       - E_OK      API API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_ControllerInit_Activity
*/
Std_ReturnType Fr_ControllerInit(uint8 Fr_CtrlIdx);
/**
* @brief            Selects which channel sends WUPs
* @details          [SWS_Fr_00202]: Change the CCs POCState to POC:Config by invoking the CHI command
*                   CONFIG, configure the wakeup channel according to parameter Fr_ChnlIdx and
*                   change the CCs POCState to POC:Ready again by invoking the CHI command
*                   CONFIG_COMPLETE
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_ChnlIdx Index of FlexRay channel within the context of the FlexRay CC
*                   Fr_CtrlIdx
* @return           Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_SetWakeupChannel_Activity
*/
Std_ReturnType Fr_SetWakeupChannel(uint8 Fr_CtrlIdx, Fr_ChannelType Fr_ChnlIdx);
/**
* @brief            Cancels the already pending transmission of a LPdu contained in a controllers
*                   physical transmit resource.
* @details          [SWS_Fr_00611]: Figure out the physical resource (e.g., a buffer) mapped to the
*                   transmission of the FlexRay frame identified by Fr_LPduIdx.
*                   If the physical resource figured out is actively pending for transmission,
*                   then the transmit request of this particular resource shall be terminated and
*                   E_OK returned. If no transmission is pending E_NOT_OK shall be returned,
*                   indicating that no such cancelation took place.
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_LPduIdx This index is used to uniquely identify a FlexRay frame
* @return           Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_CancelTxLPdu_Activity
*/
Std_ReturnType Fr_CancelTxLPdu(uint8 Fr_CtrlIdx, uint16 Fr_LPduIdx);
#if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
/**
* @brief            Prepares a LPdu.
* @details          [SWS_Fr_00249]: Figures out the physical resource mapped to the processing
*                   of the FlexRay frame identified by Fr_LPduIdx and configure the physical
*                   resource appropriate for LPduIdx operation if required by Fr configuration
* @warning          Only receive buffers and single transmit buffers reconfiguration is supported
*                   (not FIFO)
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_LPduIdx This index is used to uniquely identify a FlexRay frame
* @return           Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_PrepareLPdu_Activity
*/
Std_ReturnType Fr_PrepareLPdu(uint8 Fr_CtrlIdx, uint16 Fr_LPduIdx);
#endif
#if(FR_RECONFIG_LPDU_SUPPORT == STD_ON)
/**
* @brief            Reconfigures a given LPdu according to the parameters (FrameId, Channel,
*                   CycleRepetition, CycleOffset, PayloadLength, HeaderCRC) at runtime.
* @details          [SWS_Fr_00525]: Figure out the physical resource (e.g., a buffer) mapped to the
*                   processing of the FlexRay frame as identified by Fr_LPduIdx. Configure the
*                   physical resource (a buffer) according to the parameters given at the API.
*                   The Lpdu direction is statically associated with the Lpdu and cannot be
*                   changed by this service.
* @param[in]        Fr_CtrlIdx          Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_LPduIdx          This index is used to uniquely identify a FlexRay frame
* @param[in]        Fr_FrameId          FlexRay Frame ID the FrIf_LPdu shall be configured to
* @param[in]        Fr_ChnlIdx          FlexRay Channel the FrIf_LPdu shall be configured to
* @param[in]        Fr_CycleRepetition  Cycle Repetition part of the cycle filter mechanism
*                                       FrIf_LPdu shall be configured to.
* @param[in]        Fr_CycleOffset      Cycle Offset part of the cycle filter mechanism FrIf_LPdu shall
*                                       be configured to.
* @param[in]        Fr_PayloadLength    Payloadlength in units of bytes the FrIf_LPduIdx shall be
*                                       configured to.
* @param[in]        Fr_headerCrc        Header CRC the FrIf_LPdu shall be configured to.
* @return           Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_ReconfigLPdu_Activity
*/
Std_ReturnType Fr_ReconfigLPdu(uint8 Fr_CtrlIdx, uint16 Fr_LPduIdx, uint16 Fr_FrameId,
                                      Fr_ChannelType Fr_ChnlIdx, uint8 Fr_CycleRepetition,
                                      uint8 Fr_CycleOffset, uint8 Fr_PayloadLength, uint16 Fr_headerCrc
                                     );
#endif
#if(FR_DISABLE_LPDU_SUPPORT == STD_ON)
/**
* @brief            Disables the hardware resource of a LPdu for transmission/reception.
* @details          [SWS_Fr_00540]: Figure out the physical resource (e.g., a buffer) mapped to the
*                   processing of the FlexRay frame identified by Fr_LPduIdx. Configure the
*                   physical resource (a buffer) in a way that it does not take part in the
*                   transmission or reception process.
* @param[in]        Fr_CtrlIdx     Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_LPduIdx     This index is used to uniquely identify a FlexRay frame
* @return           Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_DisableLPdu_Activity
*/
Std_ReturnType Fr_DisableLPdu(uint8 Fr_CtrlIdx, uint16 Fr_LPduIdx);
#endif
/**
* @brief            Receives data from the FlexRay network.
* @details          [SWS_Fr_00233]:  This function figures out the physical resource mapped to the
*                   reception of the FlexRay frame identified by Fr_LPduIdx, figures out whether
*                   a new FlexRay frame has been received. If a new frame has been received,
*                   copies the received payload data to address Fr_LSduPtr, stores the number of
*                   bytes and the status #FR_RECEIVED. If a new frame has been received, FIFO code
*                   is enabled and Fr_LPduIdx is associated with FIFO A or FIFO B storage, the
*                   received payload data are copied to address Fr_LSduPtr, the number of bytes is
*                   stored and the status #FR_RECEIVED is returned. If no new frame has been
*                   received, the function doesnt copy any payload data to Fr_LSduPtr, writes 0 to
*                   parameter Fr_LSduLengthPtr and stores the status #FR_NOT_RECEIVED.
* @param[in]        Fr_CtrlIdx            Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_LPduIdx            This index is used to uniquely identify a FlexRay frame
* @param[out]       Fr_LSduPtr            Pointer to a buffer where the LSdu
* @param[out]       Fr_LPduStatusPtr      Pointer to the memory location where the status of the LPdu
*                                         shall be stored
* @param[out]       Fr_LSduLengthPtr      Pointer to the memory location where the length of the LSdu
*                                         (in bytes) shall be stored
* @param[out]       Fr_SlotAssignmentPtr  This reference points to the memory location where the
                                          actual cycle, slot ID, and channel of the frame identified by
                                          Fr_LPduIdx shall be stored. A NULL_PTR indicates that the
                                          information is not required by the caller.
* @return           Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_ReceiveRxLPdu_Activity
*/
Std_ReturnType Fr_ReceiveRxLPdu(uint8 Fr_CtrlIdx, uint16 Fr_LPduIdx,uint8* Fr_LSduPtr,
                                       Fr_RxLPduStatusType* Fr_LPduStatusPtr, uint8* Fr_LSduLengthPtr,
                                       Fr_SlotAssignmentType* Fr_SlotAssignmentPtr
                                      );
/**
* @brief            Transmits data on the FlexRay network.
* @details          [SWS_Fr_00224]: Figures out the physical resource mapped to the transmission
*                   of the FlexRay frame identified by Fr_LPduIdx, copies Fr_LSduLength
*                   bytes from address Fr_LSduPtr into the FlexRay  CCs transmission resource
*                   and activate it for transmission
* @param[in]        Fr_CtrlIdx             Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_LPduIdx             The index is used to uniquely identify a FlexRay frame
* @param[in]        Fr_LSduPtr             Pointer to a buffer where the assembled LSdu to be transmitted
*                                          within this LPdu is stored at
* @param[in]        Fr_LSduLength          Determines the length of the data (in Bytes) to be transmitted
* @param[out]       Fr_SlotAssignmentPtr   This reference points to the memory location where the
*                                          actual cycle, slot ID, and channel of the frame identified by
*                                          Fr_LPduIdx shall be stored. A NULL_PTR indicates that the
*                                          information is not required by the caller.
* @return           ::Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_TransmitTxLPdu_Activity
*/
Std_ReturnType Fr_TransmitTxLPdu(uint8 Fr_CtrlIdx, uint16 Fr_LPduIdx, const uint8* Fr_LSduPtr, uint8 Fr_LSduLength, Fr_SlotAssignmentType* Fr_SlotAssignmentPtr);
/**
* @brief            Invokes the CC CHI command WAKEUP.
* @details          [SWS_Fr_00196]: Invoke the CC CHI command WAKEUP, which initiates the Wakeup Symbol
*                   transmission procedure on the configured FlexRay channel
* @param[in]        Fr_CtrlIdx   Index of FlexRay CC within the context of the FlexRay Driver
* @return           Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_SendWUP_Activity
*/
Std_ReturnType Fr_SendWUP(uint8 Fr_CtrlIdx);
/**
* @brief            Gets the network management vector of the last communication cycle.
* @details          [SWS_Fr_00262]: Read the network management vector of the last communication cycle
*                   and write it to the output parameter Fr_NmVectorPtr. The number of bytes
*                   written to the output parameter is constant and known at configuration time
* @param[in]        Fr_CtrlIdx      Index of FlexRay CC within the context of the FlexRay Driver
* @param[out]       Fr_NmVectorPtr  Address where the NmVector of the last communication cycle
*                   shall be stored
* @return           Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_GetNmVector_Activity
*/
Std_ReturnType Fr_GetNmVector(uint8 Fr_CtrlIdx, uint8* Fr_NmVectorPtr);
/**
* @brief            Invokes the CC CHI command FREEZE.
* @details          [SWS_Fr_00191]: Invoke the CHI command FREEZE, which immediately
*                   aborts the communication and force the CC to the POC:Halt
* @param[in]        Fr_CtrlIdx     Index of FlexRay CC within the context of the FlexRay Driver
*
* @return           Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_AbortCommunication_Activity
*/
Std_ReturnType Fr_AbortCommunication(uint8 Fr_CtrlIdx);
/*!
* @brief            Invokes the CC CHI command ALLOW_COLDSTART
* @details          [SWS_Fr_00182]: Invokes the CC CHI command ALLOW_COLDSTART
*
* @param[in]        Fr_CtrlIdx   Index of FlexRay CC within the context of the FlexRay Driver
*
* @return           Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call in bad POC state or failure in access to the controller
*
* @implements       Fr_AllowColdstart_Activity
*/
Std_ReturnType Fr_AllowColdstart(uint8 Fr_CtrlIdx);
/**
* @brief            Invokes the CC CHI command DEFERRED_HALT.
* @details          [SWS_Fr_00187]: Invokes the CC CHI command HALT, which requests to halt the
*                   communication at the end of the current FlexRay communication cycle
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @return           Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call in bad POC state or failure in access to the controller
*
* @implements       Fr_HaltCommunication_Activity
*/
Std_ReturnType Fr_HaltCommunication(uint8 Fr_CtrlIdx);
/**
* @brief            Starts communication.
* @details          [SWS_Fr_00177]: Invoke the CC CHI command RUN, which initiates the startup
*                   procedure within the FlexRay CC
* @param[in]        Fr_CtrlIdx   Index of FlexRay CC within the context of the FlexRay Driver
* @return           Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_StartCommunication_Activity
*/
Std_ReturnType Fr_StartCommunication(uint8 Fr_CtrlIdx);
/*!
* @brief            Invokes the CC CHI command ALL_SLOTS.
* @details          [SWS_Fr_00518]: Invoke the CC CHI command ALL_SLOTS, which requests a switch from
*                   key slot only mode to all slots transmission mode at the beginning of the next
*                   communication cycle.
* @param[in]        Fr_CtrlIdx   Index of FlexRay CC within the context of the FlexRay Driver
* @return           Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call in bad POC state or failure in access to the controller
*
* @implements       Fr_AllSlots_Activity
*/
Std_ReturnType Fr_AllSlots(uint8 Fr_CtrlIdx);
/**
* @brief            Checks the transmit status of the LPdu.
* @details          [SWS_Fr_00244]: Figures out the physical resource mapped to the transmission
*                   of the FlexRay frame identified by Fr_LPduIdx and check whether
*                   the transmission resource is still pending for transmission or not
* @param[in]        Fr_CtrlIdx           Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_LPduIdx           This index is used to uniquely identify a FlexRay frame
* @param[out]       Fr_TxLPduStatusPtr   Pointer used to store the transmit status of the LSdu
* @param[out]       Fr_SlotAssignmentPtr Pointer used to store cycle, slot ID, and channel of the frame identified by Fr_LPduIdx
* @return           Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_CheckTxLPduStatus_Activity
*/
Std_ReturnType Fr_CheckTxLPduStatus(uint8 Fr_CtrlIdx, uint16 Fr_LPduIdx,Fr_TxLPduStatusType* Fr_TxLPduStatusPtr, Fr_SlotAssignmentType* Fr_SlotAssignmentPtr);
/*!
* @brief            Gets the POC status.
* @details          [SWS_Fr_00217]: Query the CCs actual POC status by reading the CHI variable vPOC
*                   and write the result to parameter Fr_POCStatusPtr.
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[out]       Fr_POCStatusPtr Address the output value is stored to
* @return           Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_GetPOCStatus_Activity
*/
Std_ReturnType Fr_GetPOCStatus(uint8 Fr_CtrlIdx, Fr_POCStatusType* Fr_POCStatusPtr);
/**
* @brief            Gets a list of syncframes received or transmitted on channel A and channel B via
*                   the even and odd communication cycle.
* @details          [SWS_Fr_00575]: Read the list of syncframes received in the last even communication
*                   cycle on channel A and write it as array to the memory location
*                   Fr_ChannelAEvenListPtr.
*                   Read the list of syncframes received in the last even communication cycle on
*                   channel B and write it as array to the memory location Fr_ChannelBEvenListPtr.
*                   Read the list of syncframes received in the last odd communication cycle on
*                   channel A and write it as array to the memory location Fr_ChannelAOddListPtr.
*                   Read the list of syncframes received in the last odd communication cycle on
*                   channel B and write it as array to the memory location Fr_ChannelBOddListPtr.
* @param[in]        Fr_CtrlIdx             Index of FlexRay CC within the context of the FlexRay Driver.
* @param[in]        Fr_ListSize            Size of the arrays passed via parameters:
*                                               Fr_ChannelAEvenListPtr, Fr_ChannelBEvenListPtr,
*                                               Fr_ChannelAOddListPtr Fr_ChannelBOddListPtr.
* @param[out]       Fr_ChannelAEvenListPtr Address the list of syncframes on channel A within the
*                                          even communication cycle is written to.
* @param[out]       Fr_ChannelBEvenListPtr Address the list of syncframes on channel B within the
*                                          even communication cycle is written to.
* @param[out]       Fr_ChannelAOddListPtr Address the list of syncframes on channel A within the
*                                         odd communication cycle is written to.
* @param[out]       Fr_ChannelBOddListPtr Address the list of syncframes on channel B within the
*                                         odd communication cycle is written to.
* @return           Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors or Fr_ListSize=0
*
* @implements       Fr_GetSyncFrameList_Activity
*/
Std_ReturnType Fr_GetSyncFrameList(uint8 Fr_CtrlIdx, uint8 Fr_ListSize,
                                          uint16* Fr_ChannelAEvenListPtr, uint16* Fr_ChannelBEvenListPtr,
                                          uint16* Fr_ChannelAOddListPtr, uint16* Fr_ChannelBOddListPtr
                                         );
/**
* @brief            Gets the channel status information.

* @details          [SWS_Fr_00558]: Read the aggregated channel status, NIT status, symbol window status
*                   and write it to the output parameter Fr_ChannelAStatusPtr, Fr_ChannelBStatusPtr.
* @param[in]        Fr_CtrlIdx            Index of FlexRay CC within the context of the FlexRay Driver
* @param[out]       Fr_ChannelAStatusPtr  Address where the bitcoded channel A status information
*                                         shall be stored.
* @param[out]       Fr_ChannelBStatusPtr  Address where the bitcoded channel B status information
*                                         shall be stored.
* @return           Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_GetChannelStatus_Activity
*/
Std_ReturnType Fr_GetChannelStatus(uint8 Fr_CtrlIdx, uint16* Fr_ChannelAStatusPtr, uint16* Fr_ChannelBStatusPtr);
/*!
* @brief            Gets the wakeup received information from the FlexRay controller.
* @details          [SWS_Fr_00588]: Read the wakeup pattern received indicators for channel A and channel
*                   B and write it to the output parameter Fr_WakeupRxStatusPtr.
* @param[in]        Fr_CtrlIdx            Index of FlexRay CC within the context of the FlexRay Driver.
*
* @param[out]       Fr_WakeupRxStatusPtr  Address where bitcoded wakeup reception status shall be
*                                          stored.
* @return           Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_GetWakeupRxStatus_Activity
*/
Std_ReturnType Fr_GetWakeupRxStatus(uint8 Fr_CtrlIdx, uint8* Fr_WakeupRxStatusPtr);
/**
* @brief            Gets the current global FlexRay time.
* @details          [SWS_Fr_00256]: Read the current global FlexRay time and writes it to
*                   the output parameters Fr_cyclePtr and Fr_MacrotickPtr
* @param[in]        Fr_CtrlIdx      Index of FlexRay CC within the context of the FlexRay Driver
* @param[out]       Fr_CyclePtr     Address where the current FlexRay communication cycle value
*                                   shall be stored
* @param[out]       Fr_MacroTickPtr Address where the current macrotick value shall be stored
* @return           Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_GetGlobalTime_Activity
*/
Std_ReturnType Fr_GetGlobalTime(uint8 Fr_CtrlIdx, uint8* Fr_CyclePtr, uint16* Fr_MacroTickPtr);
/**
* @brief            Gets the current clock correction values.
* @details          [SWS_Fr_00566]: Read the rate correction value (vInterimRateCorrection11) and write
*                   it as signed integer to the output parameter Fr_RateCorrectionPtr. Read the
*                   offset correction value (vInterimOffsetCorrection12) and write it as signed
*                   integer to the output parameter Fr_OffsetCorrectionPtr
* @param[in]        Fr_CtrlIdx               Index of FlexRay CC within the context of the FlexRay Driver
* @param[out]       Fr_RateCorrectionPtr     Address where the current rate correction value shall
*                                            be stored.
* @param[out]       Fr_OffsetCorrectionPtr   Address where the current offset correction value
*                                            shall be stored.
* @return           Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_GetClockCorrection_Activity
*/
Std_ReturnType Fr_GetClockCorrection(uint8 Fr_CtrlIdx, sint16* Fr_RateCorrectionPtr, sint32* Fr_OffsetCorrectionPtr);
/*!
* @brief            Sets the absolute FlexRay timer.
* @details          [SWS_Fr_00273]: Program the absolute FlexRay timer Fr_AbsTimerIdx according to the
*                   parameters Fr_Cycle and Fr_Offset
* @param[in]        Fr_CtrlIdx      Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_AbsTimerIdx  Index of absolute timer within the context of the FlexRay CC
* @param[in]        Fr_Cycle        Absolute cycle the timer shall elapse in
* @param[in]        Fr_Offset       Offset within cycle Fr_Cycle in units of macrotick the timer shall
*                                   elapse at
* @return           Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_SetAbsoluteTimer_Activity
*/
Std_ReturnType Fr_SetAbsoluteTimer(uint8 Fr_CtrlIdx, uint8 Fr_AbsTimerIdx, uint8 Fr_Cycle, uint16 Fr_Offset);
/**
* @brief            Stops an absolute timer.
* @details          [SWS_Fr_00287]: Stop the absolute timer Fr_AbsTimerIdx
* @param[in]        Fr_CtrlIdx      Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_AbsTimerIdx  Index of absolute timer within the context of the FlexRay CC
* @return           Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_CancelAbsoluteTimer_Activity
*/
Std_ReturnType Fr_CancelAbsoluteTimer(uint8 Fr_CtrlIdx, uint8 Fr_AbsTimerIdx);
/**
* @brief            Enables the interrupt line of an absolute timer.
* @details          [SWS_Fr_00298]: Enable the interrupt line related to timer Fr_AbsTimerIdx
* @param[in]        Fr_CtrlIdx      Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_AbsTimerIdx  Index of absolute timer within the context of the FlexRay C
* @return           Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_EnableAbsoluteTimerIRQ_Activity
*/
Std_ReturnType Fr_EnableAbsoluteTimerIRQ(uint8 Fr_CtrlIdx, uint8 Fr_AbsTimerIdx);
/**
* @brief            Resets the interrupt condition of an absolute timer.
* @details          [SWS_Fr_00309]: Reset the interrupt condition of absolute timer Fr_AbsTimerIdx
* @param[in]        Fr_CtrlIdx      Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_AbsTimerIdx  Index of absolute timer within the context of the FlexRay CC
* @return           Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_AckAbsoluteTimerIRQ_Activity
*/
Std_ReturnType Fr_AckAbsoluteTimerIRQ(uint8 Fr_CtrlIdx, uint8 Fr_AbsTimerIdx);
/**
* @brief            Disables the interrupt line of an absolute timer.
* @details          [SWS_Fr_00320]: Disable the interrupt line related to absolute timer Fr_AbsTimerIdx
* @param[in]        Fr_CtrlIdx      Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_AbsTimerIdx  Index of absolute timer within the context of the FlexRay CC
* @return           Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_DisableAbsoluteTimerIRQ_Activity
*/
Std_ReturnType Fr_DisableAbsoluteTimerIRQ(uint8 Fr_CtrlIdx, uint8 Fr_AbsTimerIdx);
/**
* @brief            Gets IRQ status of an absolute timer.
* @details          [SWS_Fr_00332]: Check whether the interrupt of absolute timer Fr_AbsTimerIdx
*                   is pending.
*                   Writes (boolean)TRUE to output parameter Fr_IRQStatusPtr in case
*                   the interrupt is pending, FALSE otherwise
* @param[in]        Fr_CtrlIdx      Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_AbsTimerIdx  Index of absolute timer within the context of the FlexRay CC
* @param[out]       Fr_IRQStatusPtr Address the output value is stored to
* @return           Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_GetAbsoluteTimerIRQStatus_Activity
*/
Std_ReturnType Fr_GetAbsoluteTimerIRQStatus(uint8 Fr_CtrlIdx,uint8 Fr_AbsTimerIdx, boolean* Fr_IRQStatusPtr);
/**
* @brief            Reads a FlexRay protocol configuration parameter for a particular FlexRay
*                   controller out of the module's configuration.
* @details          Read the value of the configuration parameter requested by Fr_ConfigParamIdx
*                   from the configuration and write it to output parameter *Fr_ConfigParamValuePtr.
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_ConfigParamIdx Index that identifies the configuration parameter
*                                          to read. See macros FR_CIDX_<config_parameter_name>.
* @param[out]       Fr_ConfigParamValuePtr Address the output value is stored to.
* @return           Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_ReadCCConfig_Activity
*/
Std_ReturnType Fr_ReadCCConfig(uint8 Fr_CtrlIdx, uint8 Fr_ConfigParamIdx, uint32* Fr_ConfigParamValuePtr);
/**
* @brief            Gets the current number of startup frames seen on the cluster.
* @details          [SWS_Fr_00549]: Read the number of aligned startup frame pairs received or transmitted
*                   during the previous double cycle, aggregated across both channels and write it
*                   to the output parameter Fr_NumOfStartupFramesPtr.
* @param[in]        Fr_CtrlIdx               Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_NumOfStartupFramesPtr Address where the number of startup frames seen
*                                            within the last even or odd cycle pair shall be stored.
* @param[out]       Fr_ConfigParamValuePtr   Address the output value is stored to.
* @return           Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_GetNumOfStartupFrames_Activity
*/
Std_ReturnType Fr_GetNumOfStartupFrames(uint8 Fr_CtrlIdx, uint8* Fr_NumOfStartupFramesPtr);
#if(FR_DEINIT_API == STD_ON)
/**
* @brief            De-initialize FR Module
* @details          De-initialize and reset Flexray registers
* @return           void.
*
* @implements       Fr_DeInit_Activity
*/
void Fr_DeInit(void);
#endif

#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* FR_H */
/** @} */
/* End of file */

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
/**
*   @file Flexray_Ip.h
*
*   @brief Flexray Ip Driver Header File
*   @details Flexray Ip Driver Header File contains the APIs and structures exported by Flexray Driver
*   @implements Flexray_Ip.h_Artifact
*
*   @addtogroup Flexray
*   @{
*/

#ifndef FLEXRAY_IP_H
#define FLEXRAY_IP_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "Flexray_Ip_Types.h"
#include "Flexray_Ip_Cfg.h"
#include "SchM_Fr.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
 * @brief Parameters that shall be published within the driver header file and also in the
 *        module's description file
 */

#define FLEXRAY_IP_MODULE_ID                        81
#define FLEXRAY_IP_VENDOR_ID                        43
#define FLEXRAY_IP_AR_RELEASE_MAJOR_VERSION         4
#define FLEXRAY_IP_AR_RELEASE_MINOR_VERSION         4
#define FLEXRAY_IP_AR_RELEASE_REVISION_VERSION      0
#define FLEXRAY_IP_SW_MAJOR_VERSION                 4
#define FLEXRAY_IP_SW_MINOR_VERSION                 0
#define FLEXRAY_IP_SW_PATCH_VERSION                 2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Flexray_Ip_Types.h header file are of the same vendor */
#if(FLEXRAY_IP_VENDOR_ID != FLEXRAY_IP_TYPES_VENDOR_ID)
    #error "Flexray_Ip.h and Flexray_Ip_Types.h have different Vendor IDs"
#endif
/* Check if current file and Flexray_Ip_Types.h header file are of the same Autosar version */
#if((FLEXRAY_IP_AR_RELEASE_MAJOR_VERSION    != FLEXRAY_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
   (FLEXRAY_IP_AR_RELEASE_MINOR_VERSION    != FLEXRAY_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
   (FLEXRAY_IP_AR_RELEASE_REVISION_VERSION != FLEXRAY_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "Software Version Numbers of Flexray_Ip.h and Flexray_Ip_Types.h are different"
#endif
/* Check if current file and Flexray_Ip_Types.h header file are of the same software version */
#if((FLEXRAY_IP_SW_MAJOR_VERSION != FLEXRAY_IP_TYPES_SW_MAJOR_VERSION) || \
   (FLEXRAY_IP_SW_MINOR_VERSION != FLEXRAY_IP_TYPES_SW_MINOR_VERSION) || \
   (FLEXRAY_IP_SW_PATCH_VERSION != FLEXRAY_IP_TYPES_SW_PATCH_VERSION))
    #error "Autosar Version Numbers of Flexray_Ip.h and Flexray_Ip_Types.h are different"
#endif

/* Check if current file and Flexray_Ip_Cfg.h header file are of the same vendor */
#if(FLEXRAY_IP_VENDOR_ID != FLEXRAY_IP_CFG_VENDOR_ID)
    #error "Flexray_Ip.h and Flexray_Ip_Cfg.h have different Vendor IDs"
#endif
/* Check if current file and Flexray_Ip_Cfg.h header file are of the same Autosar version */
#if((FLEXRAY_IP_AR_RELEASE_MAJOR_VERSION    != FLEXRAY_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
   (FLEXRAY_IP_AR_RELEASE_MINOR_VERSION    != FLEXRAY_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
   (FLEXRAY_IP_AR_RELEASE_REVISION_VERSION != FLEXRAY_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "Software Version Numbers of Flexray_Ip.h and Flexray_Ip_Cfg.h are different"
#endif
/* Check if current file and Flexray_Ip_Cfg.h header file are of the same software version */
#if((FLEXRAY_IP_SW_MAJOR_VERSION != FLEXRAY_IP_CFG_SW_MAJOR_VERSION) || \
   (FLEXRAY_IP_SW_MINOR_VERSION != FLEXRAY_IP_CFG_SW_MINOR_VERSION) || \
   (FLEXRAY_IP_SW_PATCH_VERSION != FLEXRAY_IP_CFG_SW_PATCH_VERSION))
    #error "Autosar Version Numbers of Flexray_Ip.h and Flexray_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes.h header file are of the same Autosar version */
    #if((FLEXRAY_IP_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
       (FLEXRAY_IP_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Flexray_Ip.h and StandardTypes.h are different"
    #endif
    /* Check if current file and SchM_Fr.h header file are of the same Autosar version */
    #if((FLEXRAY_IP_AR_RELEASE_MAJOR_VERSION != SCHM_FR_AR_RELEASE_MAJOR_VERSION) || \
       (FLEXRAY_IP_AR_RELEASE_MINOR_VERSION != SCHM_FR_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Flexray_Ip.h and SchM_Fr.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#if(FLEXRAY_RXSTRINGENTCHECK == STD_OFF)
    #define FLEXRAY_STRINGENT_MASK_A  0x0080U
    #define FLEXRAY_STRINGENT_MASK_B  0x8000U
#else
    #define FLEXRAY_STRINGENT_MASK_A  0x008EU
    #define FLEXRAY_STRINGENT_MASK_B  0x8E00U
#endif

/* Number of instances of the FLEXRAY module - infix based */
#ifndef FLEXRAY_INSTANCE_COUNT
#   define FLEXRAY_INSTANCE_COUNT(1U)
#endif

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define FR_START_SEC_CONST_UNSPECIFIED
#include "Fr_MemMap.h"

extern FLEXRAY_Type * const Flexray_Ip_apxBase[FLEXRAY_INSTANCE_COUNT];

#define FR_STOP_SEC_CONST_UNSPECIFIED
#include "Fr_MemMap.h"

#define FR_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fr_MemMap.h"

FLEXRAY_IP_STATEALLOC_EXT
FLEXRAY_IP_CFG_EXT

#define FR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fr_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"

Flexray_Ip_StatusType Flexray_Ip_SendCHICommand(uint8 instNum, Flexray_Ip_ChiCmdType cmd);

/*!
 * @brief Return current protocol state
 *
 * @param[in] instNum    Flexray instance number
 * @return  Current protocol state
 */
Flexray_Ip_PocStateType Flexray_Ip_GetCurrentState(uint8 instNum);

/*!
 * @brief Waits for the POC to change its state
 *
 * @param[in] instNum    Flexray instance number
 * @param[in] pocState   Current state of POC
 * @return  FLEXRAY_STATUS_SUCCESS/FLEXRAY_STATUS_TIMEOUT
 */
Flexray_Ip_StatusType Flexray_Ip_WaitPOCState(uint8 instNum, Flexray_Ip_PocStateType pocState);

/*!
 * @brief Config timer operation
 *
 * @param[in] instNum    Flexray instance number
 * @param[in] timerCfg   Contain all configuration of timer
 */
void Flexray_Ip_ConfigTimer(uint8 instNum, const Flexray_Ip_TimerConfigType* timerCfg);

/*!
 * @brief Start timer
 *
 * @param[in] instNum    Flexray instance number
 * @param[in] number     Determine which timer will start
 */
void Flexray_Ip_StartTimer(uint8 instNum, Flexray_Ip_TimerType timer);

/*!
 * @brief Stop timer
 *
 * @param[in] number determine which timer will stop
 */
void Flexray_Ip_StopTimer(uint8 instNum, Flexray_Ip_TimerType timer);

/*!
 * @brief Setup status counter.
 *
 * @param[in] instNum        Flexray instance number
 * @param[in] counterIndex   Select a status counter. Value must be in range 0-3.
 * @param[in] counterConfig  Counter configuration.
 */
void Flexray_Ip_SetStatusCounter(uint8 instNum,
                                 uint8 counterIndex,
                                 const Flexray_Ip_CounterConfigType* counterConfig);

/*!
 * @brief Get status counter.
 *
 * @param[in] instNum      Flexray instance number
 * @param[in] counterIndex Select a status counter. Value must be in range 0-3.
 *
 * @return The current value of the Slot Status Counter.
 */
uint16 Flexray_Ip_GetStatusCounter(uint8 instNum,
                                   uint8 counterIndex);
/*!
 * @brief Sets the chosen protocol interrupt.
 *
 * @param[in] instNum  FLEXRAY Hardware Interface instance number
 * @param[in] pInt     The protocol interrupt
 * @param[in] enable   true if enabled; false if disabled
 */
void Flexray_Ip_SetProtocolInterrupt(uint8 instNum,
                                     Flexray_Ip_ProtocolIntType pInt,
                                     boolean enable);
/*!
 * @brief Gets the chosen protocol interrupt flag value
 *
 *
 * @param[in] instNum  FLEXRAY Hardware Interface instance number
 * @param[in] pInt     The protocol interrupt
 *
 * @return true if flag is raised; false if flag isn't raised.
 */
boolean Flexray_Ip_GetProtocolInterruptFlag(uint8 instNum,
                                         Flexray_Ip_ProtocolIntType pInt);

/*!
 * @brief Clears the chosen protocol interrupt flag.
 *
 * @param[in] instNum   FLEXRAY Hardware Interface instance number
 * @param[in] pInt      The protocol interrupt
 */
void Flexray_Ip_ClearProtocolInterruptFlag(uint8 instNum,
                                            Flexray_Ip_ProtocolIntType pInt);
/*!
 * @brief Gets the chosen global interrupt flag value
 *
 *
 * @param[in] instNum FLEXRAY Hardware Interface instance number
 * @param[in] gInt    The global interrupt
 *
 * @return true if flag is raised; false if flag isn't raised.
 */
boolean Flexray_Ip_GetGlobalInterruptFlag(uint8 instNum,
                                       Flexray_Ip_GlobalIntType gInt);
/*!
 * @brief Sets the chosen global interrupt.
 *
 * @param[in] instNum FLEXRAY Hardware Interface instance number
 * @param[in] gInt    The global interrupt
 * @param[in] enable  true if enabled; false if disabled
 */
void Flexray_Ip_SetGlobalInterrupt(uint8 instNum,
                                   Flexray_Ip_GlobalIntType gInt,
                                   boolean enable);
/*!
 * @brief Clears the chosen global interrupt flag.
 *
 * @param[in] instNum FLEXRAY Hardware Interface instance number
 * @param[in] gInt    The global interrupt
 */
void Flexray_Ip_ClearGlobalInterruptFlag(uint8 instNum,
                                          Flexray_Ip_GlobalIntType gInt);

/*!
 * @brief Gets the chosen controller host interface interrupt flag value
 *
 *
 * @param[in] instNum FLEXRAY Hardware Interface instance number
 * @param[in] cInt    The chi interrupt
 *
 * @return true if flag is raised; false if flag isn't raised.
 */
boolean Flexray_Ip_GetCHIInterruptFlag(uint8 instNum,
                                     Flexray_Ip_ChiIntType cInt);

/*!
 * @brief Clears the chosen controller host interface interrupt flag.
 *
 * @param[in] instNum: FLEXRAY Hardware Interface instance number
 * @param[in] cInt:    The chi interrupt
 */
void Flexray_Ip_ClearCHIInterruptFlag(uint8 instNum,
                                       Flexray_Ip_ChiIntType cInt);

/*!
 * @brief Setup the slot status monitor
 *
 * Monitor the most recent status of a slot
 *
 * @param[in] instNum      Flexray instance number
 * @param[in] monitorIndex Select slot status monitor. Value must be in range 0-3.
 * @param[in] slotNumber   Select the slot to monitor. See Slot Status Monitoring in RM for details
 */
void Flexray_Ip_SetStatusMonitorSlot(uint8 instNum,
                                      uint8 monitorIndex,
                                      uint16 slotNumber);

/*!
 * @brief Get slot status from slot status monitor
 *
 * @param[in] instNum      Flexray instance number
 * @param[in] monitorIndex Select slot status monitor. Value must be in range 0-3.
 * @param[in] channelA     True: get slot status from channel A. False: get slot status from channel B
 * @param[in] evenCycle    True: get slot status from the last even cycle. False: get slot status from the last odd cycle.
 *
 * @return Slot status content. Each bit is a protocol related variable. See FR_SSRn field descriptions table in RM for details.
 */
uint8 Flexray_Ip_GetStatusMonitor(uint8 instNum,
                                     uint8 monitorIndex,
                                     boolean channelA,
                                     boolean evenCycle);


/*!
 * @brief Apply external rate or offset correction value.
 *
 * See External Clock Synchronization section in RM for details.
 *
 * @param[in] instNum    Flexray instance number
 * @param[in] rateCorrect true if correct rate, false if correct offset
 * @param[in] correctType Correction type
 */
void Flexray_Ip_SetExternalCorrection(uint8 instNum,
                                       boolean rateCorrect,
                                       Flexray_Ip_ExtClkCorrectType correctType);
/*!
 * @brief Enables or disables the generation of the MTS on
 * either channel
 *
 * @param[in] instNum    Flexray instance number
 * @param[in] channelA   True: Select channel A. False: channel B.
 * @param[in] enable     Enable or disable MTS transmission(True: enable/False: disable)
 *
 * @return FLEXRAY_STATUS_SUCCESS: Enable/disable generate MTS successfully
 *         FLEXRAY_STATUS_ERROR: When the POC state isn't POC:NORMAL ACTIVE state
 */
Flexray_Ip_StatusType Flexray_Ip_SetMTS(uint8 instNum,
                            boolean channelA,
                            boolean enable);

/*!
 * @brief Get current slot counter on channel
 *
 * @param[in] instNum     Flexray instance number
 * @param[in] channelA    True: Select channel A. False: channel B.
 *
 * @return Current slot counter value
 */
uint16 Flexray_Ip_GetCurrentSlotCounter(uint8 instNum, boolean channelA);

/*!
 * @brief Initialize CC, PE, message buffers and assign user callback
 *
 * After this function return, the module will be in POC:ready state.
 * The function wills send CONFIG, CONFIG_COMPLETE command and wait until state changed or time out.
 *
 * @param[in] instNum Instance number
 * @param[in] config User config structure
 * @param[in] stateAlloc
 *    Pointer to the array of state structure.
 *    Array size must be equal the number of message buffers used.
 *    This memory area for its internal logic. The application must make no
 *    assumptions about the content of this structure, and must not free this
 *    memory until the driver is de-initialized.
 *
 * @return FLEXRAY_STATUS_SUCCESS: Initialize successfully
 *         FLEXRAY_STATUS_TIMEOUT: Timed out while waiting for state change
 *         FLEXRAY_STATUS_FIFO_A_ERROR_CONFIG  : FiFo A will operate incorrectly if sum of the current fifo depth value and the previous start index value is
 *                                               smaller or equal than the previous read index on channel A.
 *         FLEXRAY_STATUS_FIFO_B_ERROR_CONFIG  : FiFo B will operate incorrectly if sum of the current fifo depth value and the previous start index value is
 *                                               smaller or equal than the previous read index on channel B.
 *         FLEXRAY_STATUS_FIFO_AB_ERROR_CONFIG : FiFo A & B will operate incorrectly if sum of the current fifo depth value and the previous start index value is
 *                                               smaller or equal than the previous read index on both two channel.
 *         FLEXRAY_STATUS_ERROR: When the POC state isn't POC:DEFAULT CONFIG state before initialize or
 *                       setup rx FiFo unsuccessfully
 */
Flexray_Ip_StatusType Flexray_Ip_Init(uint8 instNum,
                         const Flexray_Ip_ConfigType* config,
                         const Flexray_Ip_StateAllocateType *stateAlloc
                        );
/*!
 * @brief Execute shutdown sequence
 *
 * This function execute the shutdown sequence described in RM: Disable all enabled message buffers
 * and issue HALT command.
 * Note that this is blocking function since it poll for enabled/disabled bit in each individual
 * message buffer, and wait for POC:halt state before return.
 *
 * @param[in] instNum: FLEXRAY Hardware Interface instance number
 * @return FLEXRAY_STATUS_SUCCESS: shutdown successfully
 *         FLEXRAY_STATUS_TIMEOUT: Timed out while waiting for disabled status of individual buffer or while waiting for POC:halt
 */
Flexray_Ip_StatusType Flexray_Ip_Deinit(uint8 instNum);
/*!
 * @brief Receive an individual buffer. Return immediately.
 *
 * If message buffer have new unread content, this function read it immediately and GetTransferStatus shall return SUCCESS.
 * If message buffer have no unread content, this function shall not read the buffer and GetTransferStatus shall return BUSY,
 * transfer operation will success when a new frame is received.
 *
 * @param[in] instNum: FLEXRAY Hardware Interface instance number
 * @param[in] bufferId Individual buffer index
 * @param[out] hdr Pointer to a frame header structure
 * @param[out] data Payload data buffer to receive
 * @param[in] dataLength: data length of input buffer in 2-byte unit
 */
void Flexray_Ip_ReceiveInd(uint8 instNum,
                            uint8 bufferId,
                            Flexray_Ip_FrameHeaderType* frameHdr,
                            uint8* pData,
                            uint8 dataLength);
/*!
 * @brief Send an individual buffer. Return immediately.
 *
 * @param[in] instNum: FLEXRAY Hardware Interface instance number
 * @param[in] bufferId Individual buffer index
 * @param[in] data Payload data to transmit
 * @param[in] dataLength: data length of input buffer in 2-byte unit
 */
Flexray_Ip_StatusType Flexray_Ip_Send(uint8 instNum,
                      uint8 bufferId,
                      const uint8* pData,
                      uint8 dataLength);
 /*!
 * @brief Send an individual buffer, wait until the message is sent or time out
 *
 * @param[in] instNum: FLEXRAY Hardware Interface instance number
 * @param[in] bufferId Individual buffer index
 * @param[in] data Payload data to transmit
 * @param[in] dataLength: data length of input buffer in 2-byte unit
 * @param[in] timeout_ms: timeout value in milliseconds
 * @return
 *         FLEXRAY_STATUS_TX_CONFLICT_A: The transfer is completed and transmit conflict on channel A is reported by hardware
 *         FLEXRAY_STATUS_TX_CONFLICT_B: The transfer is completed and transmit conflict on channel B is reported by hardware
 *         FLEXRAY_STATUS_TX_CONFLICT_AB: The transfer is completed and transmit conflict on channel A & B is reported by hardware
 *         FLEXRAY_STATUS_SUCCESS : The transfer is completed and no transmit conflict is reported by hardware.
 *         FLEXRAY_STATUS_TIMEOUT: Timed out before the transmission complete
 */
Flexray_Ip_StatusType Flexray_Ip_SendBlocking(uint8 instNum,
                                  uint8 bufferId,
                                  const uint8* pData,
                                  uint8 dataLength,
                                  uint32 timeout_ms);



/*!
 * @brief Receive an individual buffer. Wait until message is received or time out
 *
 * @param[in] instNum: FLEXRAY Hardware Interface instance number
 * @param[in] bufferId Individual buffer index
 * @param[out] hdr Pointer to a frame header structure
 * @param[out] data Payload data buffer to receive
 * @param[in] dataLength: data length of input buffer in 2-byte unit
 * @param[in] timeout_ms: timeout value in milliseconds
 * @return FLEXRAY_STATUS_SUCCESS: The reception is successful.
 *         FLEXRAY_STATUS_TIMEOUT: Timed out before the reception complete
 */
Flexray_Ip_StatusType Flexray_Ip_ReceiveIndBlocking(uint8 instNum,
                                        uint8 bufferId,
                                        Flexray_Ip_FrameHeaderType* frameHdr,
                                        uint8* pData,
                                        uint8 dataLength,
                                        uint32 timeout_ms);
/*!
 * @brief Receive a buffer from fifo. Return immediately.
 *
 * @param[in] channel: access fifo channel A/B(false/true)
 * @param[out] frameHdr: pointer to output header structure
 * @param[out] data: pointer to output buffer data
 * @param[in] dataLength: data length of input buffer in 2-byte unit
 * @return FLEXRAY_STATUS_SUCCESS: Read from individual buffer successfully.
 *         FLEXRAY_STATUS_ERROR: No entry in fifo
 */
Flexray_Ip_StatusType Flexray_Ip_ReceiveFIFO(uint8 instNum,
                                 boolean channel,
                                 Flexray_Ip_FrameHeaderType* frameHdr,
                                 uint8* pData,
                                 uint8 dataLength);
/*!
 * @brief Get status of an individual buffer transfer
 *
 * @param[in] instNum: FLEXRAY Hardware Interface instance number
 * @param[in] bufferId: Individual buffer index
 * @return operation status:
 *         FLEXRAY_STATUS_TX_CONFLICT_A: The transfer is completed and transmit conflict on channel A is reported by hardware
 *         FLEXRAY_STATUS_TX_CONFLICT_B: The transfer is completed and transmit conflict on channel B is reported by hardware
 *         FLEXRAY_STATUS_TX_CONFLICT_AB: The transfer is completed and transmit conflict on channel A & B is reported by hardware
 *         FLEXRAY_STATUS_SUCCESS : The transfer is completed and no transmit conflict is reported by hardware.
 *         FLEXRAY_STATUS_BUSY    : The transfer is not completed
 *         FLEXRAY_STATUS_ABORTED: The transfer is aborted by user
 *         FLEXRAY_STATUS_TIMEOUT: A blocking transfer has timed out.
 */
Flexray_Ip_StatusType Flexray_Ip_GetTransferStatus(uint8 instNum,
                                       uint8 bufferId);
/*!
 * @brief Abort transfer of an individual buffer.
 * For Rx, If abort function is successful, memory of this buffer will be not updated about frame header and payload.
 * For Tx, If abort function is successful, tx message buffer will be not sent on bus.
 * If the application want to send/receive message buffer, please call again receive/send function.
 *
 * @param[in] instNum: FLEXRAY Hardware Interface instance number
 * @param[in] bufferId: Individual buffer index
 * @return FLEXRAY_STATUS_SUCCESS : The transfer is aborted.
 *         FLEXRAY_STATUS_ERROR : Cannot abort because the transfer is already completed/
 *                        Cannot trigger to lock with txMB/
                          Cannot trigger to disable rxMB
 */
Flexray_Ip_StatusType Flexray_Ip_Abort(uint8 instNum,
                                       uint8 bufferId);
Flexray_Ip_StatusType Flexray_Ip_CancelTxBuffer(uint8 instNum,
                                                uint8 bufferId,
                                                boolean* pendingStatus);
/*!
 * @brief Return startup status
 *
 * @param[in] instNum    Flexray instance number
 *
 * @return Startup status
 */
Flexray_Ip_StartupStatusType Flexray_Ip_GetStartupStatus(uint8 instNum);
/*!
 * @brief Return current cycle count
 *
 * @param[in] instNum    Flexray instance number
 */
uint8 Flexray_Ip_GetCurrentCycleCount(uint8 instNum);
Flexray_Ip_StatusType Flexray_Ip_SetWakeupChannel(uint8 instNum, boolean bChnA, boolean bChnB );

/*!
 * @brief Return wakeup channel
 *
 * @param[in] instNum    Flexray instance number
 *
 * @return Wake up channel
 */
Flexray_Ip_WakeUpChannelType Flexray_Ip_GetWakeupChannel(uint8 instNum);

/*!
 * @brief Return wakeup status
 *
 * @param[in] instNum    Flexray instance number
 *
 * @return Wake up status
 */
Flexray_Ip_WakeupStatusType Flexray_Ip_GetWakeupStatus(uint8 instNum);

/*!
 * @brief Get PE and CC default configuration
 *
 * @param[out] config    pointer to user configuration.
 */
void Flexray_Ip_GetDefaultConfig(const Flexray_Ip_ConfigType * config);

/*!
 * @brief Set PPI or payloadLength for Dynamic frame in individual buffer failed.
 *
 * @param[in] instNum    Flexray instance number
 * @param[in] MBIndex: Index of individual message buffer
 * @param[in] PPI: new PPI of transmitted dynamic frame
 * @param[in] payloadLength(unit is 2 bytes): new payloadLength of transmitted dynamic frame.
 */
void Flexray_Ip_SetBasicDynamicTxFrame(uint8 instNum, uint8 bufferId, boolean PPI, uint8 payloadLength);

/*!
 * @brief Reconfig an individual buffer. Return immediately.
 *        The field phyMBIndex in struct Flexray_Ip_IndConfigType cannot be reconfigured.
 *        The field MBIndex in struct Flexray_Ip_IndConfigType cannot be reconfigured.
 *
* @param[in] instNum: FLEXRAY Hardware Interface instance number
 * @param[in] pIndConfig Individual buffer configuration structure
 *
 * @return FLEXRAY_STATUS_SUCCESS: Setup successfully.
 *         FLEXRAY_STATUS_ERROR: the trigger to disable/enable individual buffer failed.
 */
Flexray_Ip_StatusType Flexray_Ip_ReConfigIndividual(uint8 instNum,
                                        Flexray_Ip_IndConfigType* pIndConfig);

/*!
 * @brief Return network management vector of last cycle.
 *
 *
 * @param[in] instNum: FLEXRAY Hardware Interface instance number
 * @param[out] data Memory to store network management vector data
 * @param[in] length Size in byte of memory provided by data
 *
 * @return Length of network management vector configured from POC:config
 */
Flexray_Ip_StatusType Flexray_Ip_GetNMVector(uint8 instNum,
                                             uint8* data,
                                             uint8* configLen );
/*!
 * @brief Return number of entries in fifo.
 *
 * @param[in] instNum    Flexray instance number
 * @param[in] isChnB     True: Fifo channel B. False: Fifo channel A.
 * @return Number of entries.
 */
uint8 Flexray_Ip_GetFifoLevel(uint8 instNum,
                              boolean isChnB);


/*  FLEXRAY_AUTOSAR_MODE_USED */
void Flexray_Ip_GetPocStatus(uint8 instNum, uint16* data);
Flexray_Ip_StatusType Flexray_Ip_CheckCCAccess(uint8 instNum, boolean Fr_CC_enabled, uint16 regMVR);
Flexray_Ip_StatusType Flexray_Ip_ClearDisableIRQs(uint8 instNum);
Flexray_Ip_StatusType Flexray_Ip_GetGlobalTime(uint8 instNum, uint8* cyclePtr, uint16* macroTickPtr);
void Flexray_Ip_GetChannelStatus(uint8 instNum, uint16* channelAStatusPtr, uint16* channelBStatusPtr);
Flexray_Ip_StatusType Flexray_Ip_GetClockCorrection(uint8 instNum, sint16* rateCorrectionPtr, sint32* offsetCorrectionPtr);
Flexray_Ip_StatusType Flexray_Ip_GetSyncFrameList(uint8 instNum, const Flexray_Ip_ConfigType * config, uint8 listSize, uint16* channelAEvenListPtr, uint16* channelBEvenListPtr, uint16* channelAOddListPtr, uint16* channelBOddListPtr);
Flexray_Ip_StatusType Flexray_Ip_GetNumOfStartFrames(uint8 instNum, uint8* numOfStartupFramesPtr);
Flexray_Ip_StatusType Flexray_Ip_ReadbackCCConfig(uint8 instNum, const Flexray_Ip_PeConfigType* peConfig);

#ifdef FLEXRAY_43_LLCE
void Flexray_Llce_AckFrpeIRQ(void);
#endif

#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* FLEXRAY_IP_H */
/** @} */


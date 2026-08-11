/**
 *   @file    Llce_InterfaceLinTypes.h
 *
 *   @brief   LLCE data structures used to implement the LLCE interface
 *   @details This file contains data structures used to implement the LLCE
 *            interface
 *
 *   @addtogroup LLCE_LIN_firmware_interface LLCE LIN firmware interface
 *   @{
 */
/*==================================================================================================
 *
 * Copyright 2018-2023 NXP
 *
 * NXP Confidential. This software is owned or controlled by NXP and may only be
 * used strictly in accordance with the applicable license terms. By expressly
 * accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that
 * you agree to comply with and are bound by, such license terms.  If you do not
 * agree to be bound by the applicable license terms, then you may not retain,
 * install, activate or otherwise use the software.
 ==================================================================================================*/

#ifndef LLCE_INTERFACELINTYPES_H
#define LLCE_INTERFACELINTYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __DOXYGEN__
/**
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 2.5, A project should not contain unused
 * macro declarations Some macros are used either in FW or driver, or provided
 * as API
 *
 * @section Llce_InterfaceLinTypes_h_REF_1
 * Violates MISRA 2012 Advisory Rule 4.9, A function should be used in
 * preference to a function-like macro where they are interchangeable. Function
 * like macro are used to reduce code complexity
 *
 */
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
 ==================================================================================================*/
#include "Llce_RegAccess.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 ==================================================================================================*/

/*==================================================================================================
 *                                     FILE VERSION CHECKS
 ==================================================================================================*/

/*==================================================================================================
 *                                          CONSTANTS
 ==================================================================================================*/

/*==================================================================================================
 *                                      DEFINES AND MACROS
 ==================================================================================================*/

/* LIN defines */
/** @brief Maximum number of hardware LIN controllers usable inside LLCE */
#define LLCE_LIN_MAXCTRL_COUNT              (4U)
/**< @brief   Maximum buffer size used to store the LIN frame payload */
#define LLCE_LIN_CONFIG_PAYLOAD_MAX_SIZE    (8U)                   

/*==================================================================================================
 *                                             ENUMS
 ==================================================================================================*/

/**
 * @brief Type of the LIN node.
 *
 * Type of the LIN node. Master or Slave.
 **/
typedef enum LLCE__PACKED
{
    /** @brief This is used for Master node */
    LLCE_LIN_MASTER_NODE = 0x0U,
    /** @brief This is used for Slave node */
    LLCE_LIN_SLAVE_NODE = 0x1U
} Llce_Lin_NodeType;

/**
 * @brief Lin Slave error codes.
 *
 * Lin Slave error codes.
 **/
typedef enum LLCE__PACKED
{
    /** @brief Error in header */
    LLCE_LIN_ERR_HEADER = 0,
    /** @brief Framing error in response */
    LLCE_LIN_ERR_RESP_STOPBIT,
    /** @brief Checksum error */
    LLCE_LIN_ERR_RESP_CHKSUM,
    /** @brief Monitoring error of transmitted data bit in response */
    LLCE_LIN_ERR_RESP_DATABIT,
    /** @brief No response */
    LLCE_LIN_ERR_NO_RESP,
    /** @brief Incomplete response */
    LLCE_LIN_ERR_INC_RESP
} Llce_Lin_SlaveErrorType;

/**
 * @brief Return status codes reported at the end of each command execution.
 *
 * Return status codes reported at the end of each command execution.
 * The meaning of these codes are command dependent.
 **/
typedef enum LLCE__PACKED
{
    /** @brief Default state of the command. */
    LLCE_LIN_NOTRUN = 0x11,
    /** @brief Command was executed successfully. */
    LLCE_LIN_SUCCESS = 0x55,
    /**
     * @brief During command execution it was detected an error
     * condition.
     */
    LLCE_LIN_ERROR = 0x56,
    /** @brief Command was executed, but a timeout was present. */
    LLCE_LIN_ERROR_TIMEOUT = 0x57,
    /** @brief Command was executed, but LIN channel is in wrong state. */
    LLCE_LIN_ERROR_STATE = 0x58,
    /**
     * @brief Command was executed, but LIN channel returned a
     * FALSE response.
     */
    LLCE_LIN_ERROR_FALSE = 0x59
} Llce_Lin_ReturnType;

/**
 * @brief LIN command IDs used to interface with LLCE.
 *
 * Some of these commands are sent by the host to LLCE module and others
 * are sent by LLCE module to the host.
 **/
typedef enum LLCE__PACKED
{
    /** @brief Host initializes LIN channels inside LLCE. */
    LLCE_LIN_CMD_INIT = 0UL,
    /** @brief Host sets LIN channel to sleep state. */
    LLCE_LIN_CMD_GOTOSLEEP,
    /** @brief Host sets LIN channel to internal sleep state. */
    LLCE_LIN_CMD_GOTOSLEEPINTERNAL,
    /** @brief Host sends wakeup command to LIN channel. */
    LLCE_LIN_CMD_WAKEUP,
    /** @brief Host sends internal wakeup command to LIN channel. */
    LLCE_LIN_CMD_WAKEUPINTERNAL,
    /** @brief Host requests the status of LIN channel. */
    LLCE_LIN_CMD_GETSTATUS,
    /** @brief Host sends a frame to a LIN channel. */
    LLCE_LIN_CMD_SENDFRAME,
    /** @brief LLCE notifies host about wakeup event. */
    LLCE_LIN_CMD_WAKEUP_CONFIRMATION,
    /**
     * @brief LLCE notifies host about Reception of a header.
     * Only for Slave nodes.
     */
    LLCE_LIN_CMD_HEADER_INDICATION,
    /**
     * @brief LLCE notifies host about an error occurred.
     * Only for Slave nodes.
     */
    LLCE_LIN_CMD_ERROR_INDICATION,
    /**
     * @brief LLCE notifies host about Reception event.
     * Only for Slave nodes.
     */
    LLCE_LIN_CMD_RX_INDICATION,
    /**
     * @brief LLCE notifies host about Transmission Event.
     * Only for Slave nodes.
     */
    LLCE_LIN_CMD_TX_CONFIRMATION,
    /** @brief Enables interrupt forwarding for all LIN Channels. */
    LLCE_LIN_CMD_ENABLEINTRFORWARD
} Llce_Lin_CommandIdType;

/**
 * @brief Checksum models for the LIN Frame.
 *
 * This type is used to specify the Checksum model to be used
 */
typedef enum LLCE__PACKED
{
    /** @brief Enhanced checksum model.*/
    LLCE_LIN_ENHANCED_CS,
    /** @brief Classic checksum model.*/
    LLCE_LIN_CLASSIC_CS
} Llce_Lin_FrameCsModelType;

/**
 * @brief Frame response types.
 *
 * This type is used to specify whether the frame processor is required to
 * transmit the response part of the LIN frame.
 */
typedef enum LLCE__PACKED
{
    /** @brief Response is generated from this (master) node.*/
    LLCE_LIN_FRAMERESPONSE_TX = 0,
    /** @brief Response is generated from a remote slave node.*/
    LLCE_LIN_FRAMERESPONSE_RX,
    /** @brief Response is generated from one slave to another slave.*/
    LLCE_LIN_FRAMERESPONSE_IGNORE
    /**
     * @brief For the master the response will be anonymous, it does not
     * have to receive the response.
     */
} Llce_Lin_FrameResponseType;

/**
 * @brief LIN Frame and Channel states operation.
 *
 * LIN operation states for a LIN channel or frame
 */

typedef enum LLCE__PACKED
{
    /** @brief Development or production error  occurred.*/
    LLCE_LIN_NOT_OK = 0,
    /** @brief Successful transmission.*/
    LLCE_LIN_TX_OK,
    /** @brief Ongoing transmission (Header or Response).*/
    LLCE_LIN_TX_BUSY,
    /**
     * @brief Erroneous header transmission such as:
     * - Mismatch between sent and read back data
     * - Identifier parity error
     * - Physical bus error.
     */
    LLCE_LIN_TX_HEADER_ERROR,
    /**
     * @brief Erroneous transmission such as:
     * - Mismatch between sent and read back data
     * - Physical bus error.
     */
    LLCE_LIN_TX_ERROR,
    /** @brief Reception of correct response.*/
    LLCE_LIN_RX_OK,
    /**
     * @brief Ongoing reception: at least one response byte has been
     * received, but the checksum byte has not been received.
     */
    LLCE_LIN_RX_BUSY,
    /**
     * @brief Erroneous reception such as:
     * - Framing error
     * - Overrun error
     * - Checksum error
     * - Short response.
     */
    LLCE_LIN_RX_ERROR,
    /**
     * @brief No response byte has been received so far.
     *
     * Frame status is mixed with channel status but it's kept here only
     * because of LIN168.
     */
    LLCE_LIN_RX_NO_RESPONSE,
    /**
     * @brief Normal operation:
     * - The related LIN channel is ready to transmit next header
     * - No data from previous frame available
     *   (e.g. after initialization).
     */
    LLCE_LIN_OPERATIONAL,
    /**
     * @brief Sleep mode operation:
     * - In this mode wake-up detection from slave
     *   nodes is enabled.
     */
    LLCE_LIN_CH_SLEEP,
} Llce_Lin_StatusType;

/*==================================================================================================
 *                                STRUCTURES AND OTHER TYPEDEFS
 ==================================================================================================*/
/**
 * @brief LIN channel configuration type structure.
 *
 * This is the type of the external data structure containing the overall
 * initialization data for one LIN Channel.
 */
typedef struct
{
    /** @brief LIN baud rate value.*/
    uint32 u32LinBaudRateRegValue;
    /** @brief Wakeup enable.*/
    uint8 u8LinChannelWakeupSupport;
    /** @brief Disable frame timeout. */
    uint8 u8LinChannelDisableFrameTimeout;
    /** @brief These bits indicate the Break length in Master mode.*/
    uint8 u8LinChannelBrkLengthMaster;
    /** @brief These bits indicate the Break length in Slave mode.*/
    uint8 u8LinChannelBrkLengthSlave;
    /** @brief Response timeout value LINTOCR[RTO] in bit time.*/
    uint8 u8ResponseTimeout;
    /** @brief Header timeout value LINTOCR[HTO].*/
    uint8 u8HeaderTimeout;
    /** @brief LIN Node Type.*/
    Llce_Lin_NodeType eLinNodeType;
} LLCE__ALIGNED__PACKED Llce_Lin_ChannelConfigType;

/**
 * @brief LIN initialization command.
 *
 * It is sent by the host to LLCE in order to load and configure all
 * needed parameters for the LIN channels inside LLCE.
 **/
typedef struct
{
    /** @brief INPUT: Configuration options for all hardware LIN
     * controllers. */
    Llce_Lin_ChannelConfigType CtrlConfig;
} LLCE__ALIGNED__PACKED Llce_Lin_InitCmdType;

/**
 * @brief Get LIN status command.
 *
 * It is sent by the host to LLCE in order to get the status of a LIN
 * controller.
 **/
typedef struct
{
    /** @brief OUTPUT: LIN channel state. */
    uint8 u8LinChStatus;
    /** @brief OUTPUT: LIN frame state. */
    uint8 u8LinChFrameStatus;
    /** @brief OUTPUT: LIN Frame error status. */
    uint8 u8LinChFrameErrorStatus;
    /** @brief OUTPUT: LIN header command type */
    uint8 Lin_u8TransmitHeaderCommand;
    /** @brief OUTPUT: LIN controller status */
    Llce_Lin_StatusType u8ControllerStatus;
} LLCE__ALIGNED__PACKED Llce_Lin_GetStatusCmdType;

/**
 * @brief LIN sleep/wakeup management commands.
 *
 * It is sent by the host to LLCE in order to manage sleep/wakeup
 * for a specific channel.
 **/
typedef struct
{
    /** @brief INPUT: Wake-up support enabled. */
    uint8 u8LinChannelWakeupSupport;
    /** @brief OUTPUT: LIN channel state. */
    uint8 u8LinChStatus;
} LLCE__ALIGNED__PACKED Llce_Lin_WakeupCmdType;

/**
 * @brief LIN send frame commands.
 *
 * It is sent by the host to LLCE in order to send a frame
 * on a specific channel. This Type is used to provide PID,
 * checksum model, data length and SDU pointer from the LIN Driver
 * to the LIN controllers inside LLCE.
 **/
typedef struct
{
    /** @brief Pointer to Sdu. */
    uint8 Sdu[LLCE_LIN_CONFIG_PAYLOAD_MAX_SIZE];
    /** @brief LIN frame identifier. */
    uint8 Pid;
    /** @brief Data length. */
    uint8 Dl;
    /** @brief Checksum model type. */
    Llce_Lin_FrameCsModelType Cs;
    /** @brief Response type. */
    Llce_Lin_FrameResponseType Drc;
} LLCE__ALIGNED__PACKED Llce_Lin_SendFrameCmdType;

typedef struct
{
    /** @brief LIN frame identifier. */
    uint8 Pid;
    /** @brief Data length. */
    uint8 Dl;
    /** @brief Checksum model type. */
    Llce_Lin_FrameCsModelType Cs;
    /** @brief Response type. */
    Llce_Lin_FrameResponseType Drc;
} LLCE__ALIGNED__PACKED Llce_Lin_HeaderIndicationCmdType;

typedef struct
{
    /** @brief Response type. */
    Llce_Lin_SlaveErrorType eSlaveError;
} LLCE__ALIGNED__PACKED Llce_Lin_ErrorIndicationCmdType;

/**
 * @brief List of commands used by host.
 *
 * It is used in order to use the same memory area for all commands send
 * from host to LLCE.
 **/
union Llce_Lin_CommandListType
{
    /** @brief Init Command. */
    Llce_Lin_InitCmdType Init;
    /** @brief Get Status Command. */
    Llce_Lin_GetStatusCmdType GetStatus;
    /** @brief Wakeup Command. */
    Llce_Lin_WakeupCmdType Wakeup;
    /** @brief Send Frame Command. */
    Llce_Lin_SendFrameCmdType SendFrame;
    /** @brief Header Indication Notification. */
    Llce_Lin_HeaderIndicationCmdType HeaderIndication;
    /** @brief Error Notification. */
    Llce_Lin_ErrorIndicationCmdType ErrorIndication;
};

/**
 * @brief Command used by host.
 *
 * It is used in order to send commands from host to LLCE using shared memory.
 **/
typedef struct
{
    /** @brief INPUT/OUTPUT: Command parameters. */
    union Llce_Lin_CommandListType CmdList;
    /** @brief INPUT: Command ID. */
    Llce_Lin_CommandIdType eCmdId;
    /** @brief OUTPUT: Return status code after command completion.*/
    Llce_Lin_ReturnType eReturnValue;
} LLCE__ALIGNED__PACKED Llce_Lin_CommandType;

/**
 * @brief Shared memory structure
 *
 * Structure that encapsulates all the shared memory with LlCE on the LIN side.
 **/
typedef struct
{
    /**
     * @brief Array used to exchange commands between host and firmware
     * for each LIN channel
     */
    Llce_Lin_CommandType Lin_aCmd[LLCE_LIN_MAXCTRL_COUNT];
    /**
     * @brief Array used to exchange commands between firmware and host
     * for each LIN channel
     */
    Llce_Lin_CommandType Lin_aNotif[LLCE_LIN_MAXCTRL_COUNT];
    /**
     * @brief Reception message buffers located in the shared
     * memory.
     */
    uint8 aLinMb[LLCE_LIN_MAXCTRL_COUNT][LLCE_LIN_CONFIG_PAYLOAD_MAX_SIZE];
} LLCE__ALIGNED__PACKED Llce_Lin_SharedMemoryType;

/*==================================================================================================
 *                                GLOBAL VARIABLE DECLARATIONS
 ==================================================================================================*/

/*==================================================================================================
 *                                    FUNCTION PROTOTYPES
 ==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /*LLCE_INTERFACELINTYPES_H*/

/** @} */

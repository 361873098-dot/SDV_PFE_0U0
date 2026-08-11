/**
 *   @file    Llce_InterfaceFwMgr.h
 *
 *   @brief   LLCE defines used to configure the LLCE firmware and interface
 *   @details LLCE defines used to configure the LLCE firmware and interface.
 *            Those configuration parameters are used both by LLCE firmware and
 *            host software.
 *
 *   @addtogroup Llce_configuration LLCE precompile configuration parameters
 *   @{
 */
/*==================================================================================================
 *
 * Copyright 2021 NXP Semiconductors
 *
 * NXP Confidential. This software is owned or controlled by NXP and may only be
 * used strictly in accordance with the applicable license terms. By expressly
 * accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that
 * you agree to comply with and are bound by, such license terms.  If you do not
 * agree to be bound by the applicable license terms, then you may not retain,
 * install, activate or otherwise use the software.
 ==================================================================================================*/

#ifndef LLCE_INTERFACEFWMGR_H
#define LLCE_INTERFACEFWMGR_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters.
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, Macro identifiers shall be distinct.
* This violation is due to the AUTOSAR requirement [SWS_BSW_00036] (perform inter module checks).
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, Identifiers declared in the same scope and name space shall be distinct.
* This rule does not apply if either identifier is a macro identifier, because this case is covered
* by Rule 5.4 and Rule 5.5.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, Identifiers shall be distinct from macro names.
* The identifier clash is between macro identifiers. Therefore, this rule is incorrectly reported by the tool.
*
* @section Llce_InterfaceFwMgr_h_REF_1
* Violates MISRA 2012 Required Rule 21.1, #define and #undef shall not be used on a reserved identifier or
* reserved macro name.
* Certain keywords are not recognized by tools such as PC-LINT and LDRA.
*
* @section Llce_InterfaceFwMgr_h_REF_2
* Violates MISRA 2012 Advisory Rule 4.9, A function should be used in
* preference to a function-like macro where they are interchangeable. Function
* like macro are used to reduce code complexity
*
* @section Llce_InterfaceFwMgr_h_REF_3
* Violates MISRA 2012 Advisory Rule 2.3, A project should not contain unused type declarations.
* False detection by lint tool.
*
*/

/*==================================================================================================
 *                                        INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
 ==================================================================================================*/


#include "Llce_RegAccess.h"

#ifdef CHECK_ABI_COMPATIBILITY
#pragma ABICHECK start
#endif
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

/*==================================================================================================
 *                                      Interrupts
 ==================================================================================================*/

/*==================================================================================================
 *                                             ENUMS
 ==================================================================================================*/
/**
 * @brief CAN firmware error values.
 *
 * CAN error values as they are reported by the LLCE firmware. Some of them are
 * channel related and other are platform related.
 **/
typedef enum LLCE__PACKED
{
    /** @brief CAN firmware error: TXACK FIFO is full. */
    LLCE_ERROR_TXACK_FIFO_FULL = 1U,
    /** @brief CAN firmware error: RXOUT FIFO is full. */
    LLCE_ERROR_RXOUT_FIFO_FULL,
    /** @brief CAN firmware error: HW FIFO inside LLCE is empty. */
    LLCE_ERROR_HW_FIFO_EMPTY,
    /** @brief CAN firmware error: HW FIFO inside LLCE is full. */
    LLCE_ERROR_HW_FIFO_FULL,
    /** @brief CAN firmware error: SW FIFO inside LLCE is empty. */
    LLCE_ERROR_SW_FIFO_EMPTY,
    /** @brief CAN firmware error: SW FIFO inside LLCE is full. */
    LLCE_ERROR_SW_FIFO_FULL,
    /** @brief CAN firmware error: Message buffer is not available. */
    LLCE_ERROR_MB_NOTAVAILABLE,
    /** @brief CAN firmware error: Short Message buffer is configured but a long frame is received. */
    LLCE_ERROR_SHORT_MB_NOTAVAILABLE,
    /**
     * @brief CAN firmware error: CAN protocol error due to inability to get
     * out from the freeze mode.
     */
    LLCE_ERROR_BCAN_FRZ_EXIT,
    /**
     * @brief CAN firmware error: CAN protocol error due to inability to
     * synchronize on the bus.
     */
    LLCE_ERROR_BCAN_SYNC,
    /**
     * @brief CAN firmware error: CAN protocol error due to inability to
     * enter in freeze mode.
     */
    LLCE_ERROR_BCAN_FRZ_ENTER,
    /**
     * @brief CAN firmware error: CAN protocol error due to inability to
     * enter in low-power mode.
     */
    LLCE_ERROR_BCAN_LPM_EXIT,
    /**
     * @brief CAN firmware error: CAN protocol error due to inability to
     * enter in soft reset.
     */
    LLCE_ERROR_BCAN_SRT_ENTER,
    /**
     * @brief CAN firmware error: unknown CAN protocol error 
     */
    LLCE_ERROR_BCAN_UNKNOWN_ERROR,
    /**
     * @brief CAN firmware error: ACKERR indicates that an acknowledge error
     * has been detected by the transmitter node.
     */
    LLCE_ERROR_BCAN_ACKERR,
    /**
     * @brief CAN firmware error: CRCERR indicates that a CRC error has been
     * detected by the receiver node in a CAN frame.
     */
    LLCE_ERROR_BCAN_CRCERR,
    /**
     * @brief CAN firmware error: BIT0ERR indicates when an inconsistency
     * occurs between the transmitted and the received bit in a CAN frame.
     */
    LLCE_ERROR_BCAN_BIT0ERR,
    /**
     * @brief CAN firmware error: BIT1ERR indicates when an inconsistency
     * occurs between the transmitted and the received bit in a CAN frame.
     */
    LLCE_ERROR_BCAN_BIT1ERR,
    /**
     * @brief CAN firmware error: DPBIT1ERR indicates when an inconsistency
     * occurs between the transmitted and the received bit in the data phase
     * of a CAN-FD frame.
     */
    LLCE_ERROR_BCAN_DPBIT1ERR,
    /**
     * @brief CAN firmware error: DPBIT0ERR indicates when an inconsistency
     * occurs between the transmitted and the received bit in the data phase
     * of a CAN-FD frame.
     */
    LLCE_ERROR_BCAN_DPBIT0ERR,
    /**
     * @brief CAN firmware error: DPSTFERR indicates that a stuffing error has
     * been detected by the receiver node in the data phase of a CAN-FD frame.
     */
    LLCE_ERROR_BCAN_DPSTFERR,
    /**
     * @brief CAN firmware error: DPFRMERR indicates that a form error has
     * been detected by the receiver node in the data phase of a CAN-FD frame
     * - a fixed-form bit field contains at least one illegal bit.
     */
    LLCE_ERROR_BCAN_DPFRMERR,
    /**
     * @brief CAN firmware error: DPCRCERR indicates that a CRC error has been
     * detected by the receiver node in the data phase of a CAN-FD frame
     */
    LLCE_ERROR_BCAN_DPCRCERR,
    /**
     * @brief CAN firmware error: FRMERR indicates that a form error has
     * been detected by the receiver node in a CAN frame - a fixed-form bit
     * field contains at least one illegal bit.
     */
    LLCE_ERROR_BCAN_FRMERR,
    /**
     * @brief CAN firmware error: STFERR indicates that a stuffing error has
     * been detected by the receiver node in a CAN frame.
     */
    LLCE_ERROR_BCAN_STFERR,
    /**
     * @brief CAN firmware error: TDC mechanism is out of range, 
     * unable to compensate the transceiver's loop delay.
     */
    LLCE_ERROR_BCAN_TDCFAIL,
    /**
     * @brief CAN firmware error: DataLost event caused by BCAN RX Fifo
     * Overrun.
     */
    LLCE_ERROR_BCAN_RXFIFO_OVERRUN,
    /**
     * @brief CAN firmware error: Reports data lost event due to resources
     * exceeded after the frame was received
     */
    LLCE_ERROR_DATA_LOST,
    /** @brief CAN firmware error: TXLUT accelerator is full. */
    LLCE_ERROR_TXLUT_FULL,
    /** @brief CAN firmware error: Error during command processing. */
    LLCE_ERROR_CMD_PROCESSING,
    /** @brief CAN firmware error: Error regarding RXLUT hardware. */
    LLCE_ERROR_RXLUT_SLOW_SEARCH,
    /** @brief CAN firmware error: Error regarding RXLUT hardware. */
    LLCE_ERROR_RXLUT_ACCESS_MODE,
    /** @brief CAN firmware error: Error regarding RXLUT hardware. */
    LLCE_ERROR_RXLUT_SEARCH_MODE,
    /** @brief CAN firmware error: Error regarding RXLUT hardware. */
    LLCE_ERROR_RXLUT_SLOW_OPERATION,
    /** @brief CAN firmware error: Error regarding RXLUT hardware. */
    LLCE_ERROR_RXLUT_INCOMPLETE_OP,
    /** @brief CAN firmware error: Error regarding RXLUT hardware. */
    LLCE_ERROR_RXLUT_OPERATING_MODE,
    /** @brief CAN firmware error: Error regarding RXLUT hardware. */
    LLCE_ERROR_RXLUT_INIT_SLOW_OP,
    /** @brief CAN firmware error: Error regarding RXLUT hardware. */
    LLCE_ERROR_RXLUT_DEINIT_SLOW_OP,
    /** @brief CAN firmware error: Error regarding RXLUT hardware. */
    LLCE_ERROR_RXLUT_INIT_OPERATING_MODE,
    /** @brief CAN firmware error: Error regarding RXLUT hardware. */
    LLCE_ERROR_RXLUT_DEINIT_OPERATING_MODE1,
    /** @brief CAN firmware error: Error regarding RXLUT hardware. */
    LLCE_ERROR_RXLUT_DEINIT_OPERATING_MODE2,
    /** @brief CAN firmware error: Error regarding bus off event. */
    LLCE_ERROR_HARDWARE_BUSOFF,
    /** @brief CAN firmware error: Controller is not ready. */
    LLCE_ERROR_CTRL_NOT_READY,
    /** @brief CAN firmware error: Error regarding bus off.
     * This notification is skipped in case of auto-recovery.
     */
    LLCE_ERROR_BUSOFF,
    /** @brief CAN firmware error: Logging fifo is full. */
    LLCE_ERROR_FIFO_LOG_FULL,
    /**
     * @brief CAN firmware error: Error reported due to CAN2CAN routing
     * error.
     */
    LLCE_ERROR_CAN2CAN,
    /**
     * @brief CAN firmware error: Error reported due to wrong command
     * parameters received from host.
     */
    LLCE_ERROR_COMMAND_PARAM,
    /**
     * @brief CAN firmware error: Error reported due to the rx core not
     * responding.
     */
    LLCE_ERROR_COMMAND_RXPPE_NORESPONSE,
    /**
     * @brief CAN firmware error: Error reported due to the AF core not
     * responding.
     */
    LLCE_ERROR_COMMAND_AF_NORESPONSE,
    /**
     * @brief CAN firmware error: Error reported because the controller is
     * not stopped.
     */
    LLCE_ERROR_COMMAND_DEINIT_NOTSTOP,
    /**
     * @brief CAN firmware error: Error reported because the host didn't
     * read all the RX tokens (indexes in fifos). LLCE waits for indexes
     * to be read and returned.
     */
    LLCE_ERROR_RXTOKENS_UNRETURNED,
    /**
     * @brief CAN firmware error: Error reported because the host didn't
     * read all the ACKs (indexes in fifos). LLCE waits for indexes to be
     * read.
     */
    LLCE_ERROR_TXACK_NOT_READ,
    /**
     * @brief CAN firmware error: Error reported because the requested
     * command is not in the list of supported commands.
     */
    LLCE_ERROR_COMMAND_NOTSUPPORTED,
    /**
     * @brief CAN firmware error: Error reported because command is not
     * validated by the command flow.
     */
    LLCE_ERROR_COMMAND_NOTVALIDATED,
    /**
     * @brief CAN firmware error: Error reported because the requested
     * command is correct but it not accepted.
     */
    LLCE_ERROR_COMMAND_NOTACCEPTED,
    /**
     * @brief CAN firmware error: Error reported because the requested
     * command parameters are invalid.
     */
    LLCE_ERROR_COMMAND_INVALID_PARAMS,
    /** @brief CAN firmware error: Controller is not started. */
    LLCE_ERROR_CTRL_NOT_STARTED,
    /**
     * @brief CAN firmware error: Reports frame accepted, but not delivered
     * to host because of filters misconfiguration.
     */
    LLCE_ERROR_FRAME_NOT_DELIVERED,
    /**
     * @brief CAN firmware error: Reports frame accepted, but not delivered
     * to AF destination because of full fifo.
     */
    LLCE_ERROR_FRAME_NOT_DELIVERED_TO_AF,
    /**
     * @brief CAN firmware error: Reports frame accepted, but not delivered
     * to host due to lack of descriptors in sw fifo.
     */
    LLCE_ERROR_FRAME_NOT_DELIVERED_TO_HOST,
    /**
     * @brief CAN firmware error: Reports detection of lost indexes in
     * RX-DTE subsystem.
     */
    LLCE_ERROR_LOST_INDEXES,
    /**
     * @brief CAN firmware error: Error reported because there are no
     * filters available to be set for a specific controller.
     */
    LLCE_ERROR_FILTERS_FULL,
    /**
     * @brief CAN firmware error: The filter pointed by the related address
     * is not used by the related controller.
     */
    LLCE_ERROR_FILTERS_NOTEXIST,
    /** @brief CAN firmware error: There are no free configuration filters.
     */
    LLCE_ERROR_FILTERS_MASK_EMPTY,
    /** @brief CAN firmware error: There are no free configuration filters.
     */
    LLCE_ERROR_FILTERS_RANGE_EMPTY,
    /** @brief CAN firmware error: There are no free exact match filters. */
    LLCE_ERROR_FILTERS_EM_EMPTY,
    /** @brief CAN firmware error: The index return by host is not valid. */
    LLCE_ERROR_IDX_NOT_VALID_HOST,
    /** @brief CAN firmware error: The index return by logging is not valid.
     */
    LLCE_ERROR_IDX_NOT_VALID_LOG,
    /**
     * @brief CAN firmware error: The host core which sent a free RX
     * descriptor index to LLLCE is invalid.
     */
    LLCE_ERROR_INVALID_HOST_CORE,
    /**
     * @brief CAN firmware error: Reports frame accepted, but not delivered
     * to HSE because of full fifo.
     */
    LLCE_ERROR_RXFRAME_NOT_DELIVERED_TO_HSE,
    /**
     * @brief CAN firmware error: TX frame was not delivered to HSE because
     * of full fifo.
     */
    LLCE_ERROR_TXFRAME_NOT_DELIVERED_TO_HSE,
    /**
     * @brief CAN firmware error: Rx frame was dropped because it is not
     * authentic.
     */
    LLCE_ERROR_RXFRAME_AUTH_ERROR,
    /**
     * @brief CAN firmware error: core received an invalid request from
     * TX core.
     */
    LLCE_ERROR_INVALID_REQUEST_FROM_TX,
    /**
     * @brief CAN firmware error: core received an invalid request from
     * RX core.
     */
    LLCE_ERROR_INVALID_REQUEST_FROM_RX,
    /** @brief CAN firmware error: RX Software FIFO is empty. */
    LLCE_ERROR_RX_SW_FIFO_EMPTY,
    /** @brief AF error : error communicating with PFE */
    LLCE_ERROR_PFEIF,
    /** @brief AF error : error communicating with HSE */
    LLCE_ERROR_HSEIF,
    /**
     * @brief Generic firmware code: Command was executed successfully by
     * LLCE Firmware.
     */
    LLCE_FW_SUCCESS,
    /**
     * @brief Generic firmware error: During command execution it was
     * detected an error condition.
     */
    LLCE_FW_ERROR,
    /**
     * @brief Generic firmware code: Default value of command return
     * status, set by the host before to send it to LLCE firmware.
     */
    LLCE_FW_NOTRUN,
    /**
     * @brief CAN firmware error: Internal Descriptor was not returned
     * to the source.
     */
    LLCE_ERROR_INTERNALDESC_NOT_RETURNED,
    /**
     * @brief CAN firmware error: Internal Descriptor was not delivered
     * to the destination.
     */
    LLCE_ERROR_INTERNALDESC_NOT_DELIVERED,
    /**
     * @brief CAN firmware error: Internal Descriptor is not available.
     */
    LLCE_ERROR_INTERNALDESC_NOTAVAIL,
    /**
     * @brief CAN firmware error: Internal Descriptor software FIFO is full.
     */
    LLCE_ERROR_INTERNALDESC_FIFO_FULL,
    /** @brief CAN firmware error: Message Buffer is not available. */
    LLCE_ERROR_MB_NOTAVAIL,
    /** @brief CAN firmware error: Message Buffer software FIFO is full. */
    LLCE_ERROR_MB_FIFO_FULL,
    /**
     * @brief CAN firmware error: Maximum number of Tx MB per controller for
     * AF is reached.
     */
    LLCE_ERROR_NO_MB_AVAILABLE,
    /** @brief CAN firmware error: Unknown source of the request. */
    LLCE_ERROR_UNKNOWN_SRC,
    /** @brief CAN firmware error: Unknown destination of the request. */
    LLCE_ERROR_UNKNOWN_DEST,
    /** @brief CAN firmware error: Unknown request. */
    LLCE_ERROR_UNKNOWN_REQUEST,
    /** @brief CAN firmware error: Conversion error for CAN2CAN. */
    LLCE_ERROR_CONVERSION,
    /**
     * @brief CAN firmware error: AbortMB request failed due to no pending
     * transmission that can be aborted.
     */
    LLCE_ERROR_NO_MB_TO_ABORT,
    /**
     * @brief CAN firmware error: Index not recovered from DTE after Stop
     * or busoff event.
     */
    LLCE_ERROR_INDEX_NOT_RECOVERED,
    /** @brief CAN firmware error: Controller is in reset pending state. */
    LLCE_ERROR_RESET_PENDING,
    /** @brief CAN firmware notification: BCAN is in automatic buss off
     * recovery from busoff state.
     */
    LLCE_NOTIF_BUSOFF_AUTO_RECOVERY_PENDING,
    /** @brief CAN firmware notification: BCAN is ready to leave bus-off
     * state after the automatic recovery procedure
     */
    LLCE_NOTIF_BUSOFF_DONE

} Llce_Fw_ReturnType;

/*==================================================================================================
 *                                STRUCTURES AND OTHER TYPEDEFS
 ==================================================================================================*/
/**
 * @brief Boot sequence data type.
 *
 * Data type used to access shared memory area for managing LLCE boot sequence
 **/

typedef struct
{
    /**
     * @brief OUTPUT: Boot Status of TXPPE. This can be NOTRUN, SUCCESS, or
     * a specific ERROR information
     */
    Llce_Fw_ReturnType eTxBootStatus;
    /**
     * @brief OUTPUT: Boot Status of RXPPE. This can be NOTRUN, SUCCESS, or
     * a specific ERROR information
     */
    Llce_Fw_ReturnType eRxBootStatus;
    /**
     * @brief OUTPUT: Boot Status of RXPPE. This can be NOTRUN, SUCCESS, or
     * a specific ERROR information
     */
    Llce_Fw_ReturnType eDteBootStatus;
    /**
     * @brief OUTPUT: Boot Status of RXPPE. This can be NOTRUN, SUCCESS, or
     * a specific ERROR information
     */
    Llce_Fw_ReturnType eFrpeBootStatus;
    /* @violates @ref Llce_InterfaceFwMgr_h_REF_3 Violates MISRA 2012 Advisory
    * Rule 2.3, False positive */
} LLCE__ALIGNED__PACKED Llce_Mgr_StatusType;



#ifdef CHECK_ABI_COMPATIBILITY
#pragma ABICHECK stop
#endif
/*==================================================================================================
 *                                GLOBAL VARIABLE DECLARATIONS
 ==================================================================================================*/

/*==================================================================================================
 *                                    FUNCTION PROTOTYPES
 ==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* LLCE_INTERFACEFWMGR_H */

/** @} */

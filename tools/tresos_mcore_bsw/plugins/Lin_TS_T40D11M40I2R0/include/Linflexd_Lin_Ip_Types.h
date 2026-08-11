/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : LINFLEXD
*   Dependencies         : none
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

#ifndef LINFLEXD_LIN_IP_TYPES_H
#define LINFLEXD_LIN_IP_TYPES_H

/**
*   @file Linflexd_Lin_Ip_Types.h
*
*   @addtogroup LINFLEXD_IP
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

#include "StandardTypes.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LINFLEXD_LIN_IP_TYPES_VENDOR_ID                    43
#define LINFLEXD_LIN_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define LINFLEXD_LIN_IP_TYPES_AR_RELEASE_MINOR_VERSION     4
#define LINFLEXD_LIN_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define LINFLEXD_LIN_IP_TYPES_SW_MAJOR_VERSION             4
#define LINFLEXD_LIN_IP_TYPES_SW_MINOR_VERSION             0
#define LINFLEXD_LIN_IP_TYPES_SW_PATCH_VERSION             2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes.h header file are of the same Autosar version */
    #if ((LINFLEXD_LIN_IP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (LINFLEXD_LIN_IP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Linflexd_Lin_Ip_Types.h and StandardTypes.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* Type of LIN node, Master or Slave */
#define LINFLEXD_LIN_IP_SLAVE  0U
#define LINFLEXD_LIN_IP_MASTER 1U

/* Type of frame command */
#define LINFLEXD_LIN_IP_TX_NO_COMMAND               ((uint8)0x00U)  /*!< There is no command requested after initialized or moved to IDLE from SLEEP */
#define LINFLEXD_LIN_IP_TX_MASTER_RES_COMMAND       ((uint8)0x01U)  /*!< Master send header and send response */
#define LINFLEXD_LIN_IP_TX_SLAVE_RES_COMMAND        ((uint8)0x02U)  /*!< Master send header and receive response */
#define LINFLEXD_LIN_IP_TX_SLAVE_TO_SLAVE_COMMAND   ((uint8)0x03U)  /*!< Master send header and ignore response */

/* Lin state value */
#define LINFLEXD_LIN_IP_LINS_SLEEP_MODE_U8             ((uint8)0x00U)    /*!< Sleep mode */
#define LINFLEXD_LIN_IP_LINS_INIT_MODE_U8              ((uint8)0x01U)    /*!< Initialization mode */
#define LINFLEXD_LIN_IP_LINS_IDLE_MODE_U8              ((uint8)0x02U)    /*!< Idle mode */
#define LINFLEXD_LIN_IP_LINS_SYNC_BREAK_U8             ((uint8)0x03U)    /*!< Receiving/transmitting sync break in slave/master respectively */
#define LINFLEXD_LIN_IP_LINS_SYNC_DEL_U8               ((uint8)0x04U)    /*!< Detected/Completed sync break in slave/master respectively */
#define LINFLEXD_LIN_IP_LINS_SYNC_FIELD_U8             ((uint8)0x05U)    /*!< Receiving/transmitting sync field in slave/master respectively */
#define LINFLEXD_LIN_IP_LINS_IDENTIFIER_FIELD_U8       ((uint8)0x06U)    /*!< Receiving/transmitting ID field in slave/master respectively */
#define LINFLEXD_LIN_IP_LINS_HEADER_RECEPT_TRANS_U8    ((uint8)0x07U)    /*!< Valid received/transmitted header in slave/master respectively */
#define LINFLEXD_LIN_IP_LINS_DATA_RECEPT_TRANS_U8      ((uint8)0x08U)    /*!< Receiving/transmitting data in receiver/transmitter respectively */
#define LINFLEXD_LIN_IP_LINS_CHECKSUM_U8               ((uint8)0x09U)    /*!< Checksum transmission/reception ongoing */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/*!
 * @brief Defines types for an enumerating event related to an Identifier.
 * @implements Linflexd_Lin_Ip_EventIdType_enum
 */
typedef enum
{
    LINFLEXD_LIN_IP_NO_EVENT               = 0x00U,    /*!< No event yet */
    LINFLEXD_LIN_IP_WAKEUP_SIGNAL          = 0x01U,    /*!< Received a wakeup signal */
    LINFLEXD_LIN_IP_RECV_HEADER_OK         = 0x03U,    /*!< Indicate that header was correctly received */
    LINFLEXD_LIN_IP_SEND_HEADER_OK         = 0x04U,    /*!< Indicate that header was correctly sent */
    LINFLEXD_LIN_IP_OVERRUN_ERROR          = 0x07U,    /*!< Overrun Error */
    LINFLEXD_LIN_IP_FRAME_ERROR            = 0x08U,    /*!< Framing Error */
    LINFLEXD_LIN_IP_READBACK_ERROR         = 0x09U,    /*!< Readback data is incorrect */
    LINFLEXD_LIN_IP_CHECKSUM_ERROR         = 0x0AU,    /*!< Checksum byte is incorrect */
    LINFLEXD_LIN_IP_TX_COMPLETED           = 0x0BU,    /*!< Sending data completed */
    LINFLEXD_LIN_IP_RX_COMPLETED           = 0x0CU,    /*!< Receiving data completed */
    LINFLEXD_LIN_IP_TIMEOUT_ERROR          = 0x0DU,    /*!< Timeout Error */
    LINFLEXD_LIN_IP_HEADER_RECEPT_ERROR    = 0x0EU     /*!< Header reception error */
} Linflexd_Lin_Ip_EventIdType;


/*!
 * @brief Define type for an enumerating LIN Node state.
 * @implements Linflexd_Lin_Ip_NodeStateType_enum
 */
typedef enum
{
    LINFLEXD_LIN_IP_NODE_STATE_UNINIT               = 0x00U, /*!< Uninitialized state */
    LINFLEXD_LIN_IP_NODE_STATE_SLEEP_MODE           = 0x01U, /*!< Sleep mode state */
    LINFLEXD_LIN_IP_NODE_STATE_IDLE                 = 0x02U, /*!< Idle state */
    LINFLEXD_LIN_IP_NODE_STATE_SEND_HEADER          = 0x03U, /*!< Send header state */
    LINFLEXD_LIN_IP_NODE_STATE_RECV_HEADER          = 0x04U, /*!< Receive header */
    LINFLEXD_LIN_IP_NODE_STATE_RECV_DATA            = 0x07U, /*!< Receive data state */
    LINFLEXD_LIN_IP_NODE_STATE_RECV_DATA_COMPLETED  = 0x08U, /*!< Receive data completed state */
    LINFLEXD_LIN_IP_NODE_STATE_SEND_DATA            = 0x09U, /*!< Send data state */
    LINFLEXD_LIN_IP_NODE_STATE_SEND_DATA_COMPLETED  = 0x0AU  /*!< Send data completed state */
} Linflexd_Lin_Ip_NodeStateType;

/*!
 * @brief This type defines a range of transfer status.
 * @implements Linflexd_Lin_Ip_TransferStatusType_enum
 */
typedef enum
{
    LINFLEXD_LIN_IP_STATUS_FAIL              = 0x00U, /*!< Command has not been accepted. */
    LINFLEXD_LIN_IP_STATUS_TX_OK                    , /*!< Master: Header or Response successful transmission. Slave: Response successful transmission. */
    LINFLEXD_LIN_IP_STATUS_TX_BUSY                  , /*!< Master: Ongoing transmission (Header or Response). */
    LINFLEXD_LIN_IP_STATUS_TX_HEADER_ERROR          , /*!< Master: Erroneous header transmission such as: Mismatch between sent and read back data or Physical bus error. */
    LINFLEXD_LIN_IP_STATUS_TX_ERROR                 , /*!< Master or Slave: Erroneous response transmission such as mismatch between sent and read back data, Physical bus error. */
    LINFLEXD_LIN_IP_STATUS_RX_OK                    , /*!< Master or Slave: Reception of correct response. */
    LINFLEXD_LIN_IP_STATUS_RX_BUSY                  , /*!< Master or Slave: Ongoing reception. At least one response byte has been received, but the checksum byte has not been received. */
    LINFLEXD_LIN_IP_STATUS_RX_ERROR                 , /*!< Master or Slave: Erroneous response reception such as: - Framing error - Overrun error - Checksum error or Short response(timeout occurred). */
    LINFLEXD_LIN_IP_STATUS_RX_NO_RESPONSE           , /*!< Master or Slave: No response byte has been received so far. */
    LINFLEXD_LIN_IP_STATUS_RX_HEADER_OK             , /*!< Slave: Reception of correct header.*/
    LINFLEXD_LIN_IP_STATUS_RX_HEADER_BUSY           , /*!< Ongoing header reception. */
    LINFLEXD_LIN_IP_STATUS_RX_HEADER_ERROR          , /*!< Slave: Erroneous header reception such as: Break field error, Sync field error, Identifier parity error, Framing error, timeout occurred or Physical bus error. */
    LINFLEXD_LIN_IP_STATUS_OPERATIONAL              , /*!< Normal operation; there is no data has been sent or received after channel initialized or switched to IDLE from SLEEP. */
    LINFLEXD_LIN_IP_STATUS_SLEEP                      /*!< Sleep state operation. */
} Linflexd_Lin_Ip_TransferStatusType;

/*!
 * @brief This type defines a range of specific status for return operation.
 * @implements Linflexd_Lin_Ip_StatusType_enum
 */
typedef enum
{
    LINFLEXD_LIN_IP_STATUS_SUCCESS = 0x00U,     /*!< Successful operation. */
    LINFLEXD_LIN_IP_STATUS_ERROR,               /*!< Failed operation. */
    LINFLEXD_LIN_IP_STATUS_BUSY,                /*!< LIN hardware instance is in busy. */
    LINFLEXD_LIN_IP_STATUS_TIMEOUT              /*!< Timeout error. */
} Linflexd_Lin_Ip_StatusType;

typedef enum
{
    LINFLEXD_LIN_IP_ENHANCED_CS,    /**< @brief Enhanced checksum model.*/
    LINFLEXD_LIN_IP_CLASSIC_CS      /**< @brief Classic checksum model.*/
} Linflexd_Lin_Ip_FrameCsModelType;

typedef enum
{
    LINFLEXD_LIN_IP_FRAMERESPONSE_TX = 0,    /**< @brief Response is generated from
                                        this (master) node.*/
    LINFLEXD_LIN_IP_FRAMERESPONSE_RX,     /**< @brief Response is generated from a
                                        remote slave node.*/
    LINFLEXD_LIN_IP_FRAMERESPONSE_IGNORE      /**< @brief Response is generated from one
                                        slave to another slave.*/
                            /**< @brief For the master the response
                                        will be anonymous, it does not
                                        have to receive the response.*/
} Linflexd_Lin_Ip_FrameResponseType;

/*==================================================================================================
*                                      STRUCTURES AND OTHERS
==================================================================================================*/
/*!
 * @brief Define type for an structure containing information regarding the LIN Frame .
 * @implements Linflexd_Lin_Ip_PduType_struct
 */
typedef struct
{
    uint8                               Pid;     /**< @brief LIN frame identifier.*/
    Linflexd_Lin_Ip_FrameCsModelType    Cs;      /**< @brief Checksum model type.*/
    Linflexd_Lin_Ip_FrameResponseType   Drc;     /**< @brief Response type.*/
    uint8                               Dl;      /**< @brief Data length.*/
    uint8*                              SduPtr;  /**< @brief Pointer to Sdu.*/
} Linflexd_Lin_Ip_PduType;

/*!
 * @brief Runtime state of the LIN driver.
 * @internal
 * Note that the caller provides memory for the driver state structures during
 * initialization because the driver does not statically allocate memory.
 *
 */
typedef struct
{
    volatile boolean IsBusBusy;                    /*!< True if there are data, frame headers being transferred on bus */
    volatile Linflexd_Lin_Ip_EventIdType CurrentEventId;     /*!< Current ID Event */
    volatile Linflexd_Lin_Ip_NodeStateType CurrentNodeState; /*!< Current Node state */
    Linflexd_Lin_Ip_PduType *SlavePduInfoPtr;                  /*!< pointer to PduInfo for slave node */
    uint8 FrameCommand;        /*!< Type of command base on response type when Master sends frame.*/
    volatile uint32 LinState;        /*!< Store the state of LINSR register for further process.*/
} Linflexd_Lin_Ip_StateStructType;

/*!
 * @brief LIN Driver callback function type
 * @implements Linflexd_Lin_Ip_CallbackType_Type
 */
typedef void (* Linflexd_Lin_Ip_CallbackType)(const uint8 Instance, const Linflexd_Lin_Ip_StateStructType * LinState);

typedef struct
{
    uint8 Instance;                               /*!< Lin hardware instance number */
    boolean WakeupDetectSupport;                   /*!< Support wakeup detection */
    boolean NodeFunction;                          /*!< Node function as Master or Slave */
    boolean AutobaudEnable;                         /*!< Enable Autobaud feature */
    uint8 BreakLength;                            /*!< Length of break character */
    Linflexd_Lin_Ip_CallbackType Callback;          /*!< Callback function to invoke after receiving a byte or transmitting a byte. */
    Linflexd_Lin_Ip_StateStructType *StateStructPtr;
    uint32 BaudrateRegValue;                    /*!< Integer Baud rates */
    uint8 ResponseTimeout;                        /*!< Response Timeout bit time */
    uint8 HeaderTimeout;                          /*!< Header Timeout bit time */
    uint8 SlaveSyncBreakLength;                   /*!< Slave sync break length */
    uint8 StopBitsCount;                          /*!< Number of stop bits */
    uint8 CsCalDisable;                           /*!< Enable or disable checksum calculate by hardware */
} Linflexd_Lin_Ip_UserConfigType;


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LINFLEXD_LIN_IP_TYPES_H */

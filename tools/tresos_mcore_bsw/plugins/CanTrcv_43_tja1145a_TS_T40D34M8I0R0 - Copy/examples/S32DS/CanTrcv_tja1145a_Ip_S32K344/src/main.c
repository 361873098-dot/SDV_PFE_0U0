/*
*   Copyright 2020 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms.  By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms.  If you do not agree to
*   be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
*
*   This file contains sample code only. It is not part of the production code deliverables.
*/

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "ComStack_Types.h"
#include "Siul2_Dio_Ip.h"
#include "Siul2_Port_Ip.h"
#include "FlexCAN_Ip.h"
#include "CanTrcv_tja1145a_Ip.h"
#include "Lpspi_Ip.h"
#include "Lpspi_Ip_Types.h"
#include "sys_init.h"
#include "Det_stub.h"
#include "Clock_Ip.h"
#include "IntCtrl_Ip.h"
#include "S32K344.h"
#include "S32K344_SIUL2.h"
#include "check_example.h"
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define SIUL2_0_INSTANT  (0U)
#define HW_SPI_USE  (1U)
#define SET_PIN_LEVEL(SIUL2_0_INSTANT, CHANEL_ID, LEVEL)  (*(uint8*)(SIUL2_DIO_IP_GPDO_ADDR32(SIUL2_0_INSTANT, CHANEL_ID)) = LEVEL)

/* Define for CanHW */
#define FLEXCAN_0_HW_INST INST_BOARD_INITPERIPHERALS_FLEXCAN_0
#define FLEXCAN_2_HW_INST INST_BOARD_INITPERIPHERALS_FLEXCAN_2

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define TJA115X_EN             (85U)
#define TJA115X_STB            (84U)

#define TJA115x_CMD60_CONFIG_ID_CANID  (0x18DA00F1U)
#define CANTRCV_TJA115X_AUTOBRDET_CANID (0x555U)
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
Flexcan_Ip_MsgBuffType rxBuff_Type;
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
typedef enum
{
    TJA115x_NOERROR = 0,     /**< No error - successful operation */
    TJA115x_ERR_NOACK,       /**< CAN message is not acknowleged */
    TJA115x_ERR_INVALID,     /**< Invalid parameter(s) */
    TJA115x_ERR_BAUDRATE,    /**< Failure during vanilla baudrate detection */
    TJA115x_ERR_REM_REQ,     /**< Failure to perform or initiate remote configuration request*/
    TJA115x_ERR_REM_CONF,    /**< Failure to confirm remote configuration request */
    TJA115x_ERR_LOC_REQ,     /**< Failure to perform or initiate local configuration request*/
    TJA115x_ERR_LOC_INIT,    /**< Failure to get the device into Standby due to init fails */
    TJA115x_ERR_MODE,        /**< Failure to confirm configuration mode, i.e.: TJA115x is not in expected mode */
    TJA115x_ERR_ELEMENT,     /**< Failure to transmit filter element command */
    TJA115x_ERR_WRONG_ELM,   /**< Filter element register verification failure */
    TJA115x_ERR_COMMAND,     /**< Failure to transmit non-FET command register */
    TJA115x_ERR_WRONG_CMD,   /**< Command (non-FET) register verification failure */
    TJA115x_ERR_LEAVE        /**< Failure to leave configuration mode */
} CanTrcv_tja115x_ErrorCodeType;

/**
* @brief Leave configuration modes
*
* @implements CanTrcv_tja115x_LeaveModeType_Class
*/
typedef enum
{
    TJA115x_LEAVE_VOLATILE  = 0x71U, /**< Development mode without lock, NO MTP programming. */
    TJA115x_LEAVE_OPEN_LOCK = 0x72U, /**< Programming configuration into nonvolatile
                                          and set 'open lock bit' */
    TJA115x_LEAVE_FULL_LOCK = 0x74U, /**< Programming configuration into nonvolatile
                                          and set 'full lock bit' */
    TJA115x_CLOSE_VOLATILE  = 0xF1U, /**< Same as TJA115x_LEAVE_VOLATILE with immediate
                                          close of configuration window */
    TJA115x_CLOSE_OPEN_LOCK = 0xF2U, /**< Same as TJA115x_LEAVE_OPEN_LOCK with immediate
                                          close of configuration window */
    TJA115x_CLOSE_FULL_LOCK = 0xF4U  /**< Same as TJA115x_LEAVE_FULL_LOCK with immediate
                                          close of configuration window */
} CanTrcv_tja115x_LeaveModeType;

/* Define struct of CanComParamsType */
typedef struct
{
    uint8  instance;   /**< Used CAN instance for configuration. */
    uint8  mb_idx;     /**< Index of the message buffer used for transmission. */
    uint32 timeout_ms; /**< A timeout for the transmission in milliseconds. */
} CanTrcv_tja115x_CanComParamsType;

/* Define can type */
typedef enum
{
    TJA115x_CANMSG_STD = 0U,
    TJA115x_CANMSG_EXT = 1U
} CanTrcv_tja115x_CanMsgType;

/* Define status of tja115x */
typedef enum
{
    TJA115x_NORMAL = 0U,
    TJA115x_STANDBY = 1U
} CanTrcv_tja115x_mode;

/* Create frame data */
Can_PduType Ip_Can_CreatePduInfo(Can_IdType id, PduIdType swPduHandle, uint8 length, uint8* sdu)
{
    Can_PduType PduInfo;

    PduInfo.id = id;
    PduInfo.swPduHandle = swPduHandle;
    PduInfo.length = length;
    PduInfo.sdu = sdu;

    return PduInfo;
}

/*brief CAN_0 (TJA1153ATK) configuration structure */
const CanTrcv_tja115x_CanComParamsType CanTrcv_tja115x_Params0 =
{
    .instance = 0u,
    .mb_idx = 2u,
    .timeout_ms = 100u
};

/* Set mode for tja115X */
void SetMode_TJA115X(CanTrcv_tja115x_mode mode)
{
    switch(mode)
    {
    case TJA115x_NORMAL:
        SET_PIN_LEVEL(SIUL2_0_INSTANT, TJA115X_EN, STD_HIGH);
        SET_PIN_LEVEL(SIUL2_0_INSTANT, TJA115X_STB, STD_HIGH);
        break;
    case TJA115x_STANDBY:
        SET_PIN_LEVEL(SIUL2_0_INSTANT, TJA115X_EN, STD_LOW);
        SET_PIN_LEVEL(SIUL2_0_INSTANT, TJA115X_STB, STD_LOW);
        break;
    default:
        break;
    }
}

/* Create a function to configure tja115x by send frames can */
static CanTrcv_tja115x_ErrorCodeType tja115x_drv_send(const uint32 CanId,
                                                      const CanTrcv_tja115x_CanComParamsType* CanComParams,
                                                      const CanTrcv_tja115x_CanMsgType CanMsgType,
                                                      const uint32 DataLen,
                                                      uint8* const Data)
{
    CanTrcv_tja115x_ErrorCodeType retVal = TJA115x_NOERROR;
    Flexcan_Ip_MsgBuffIdType msg_id_type;

    if (CanMsgType == TJA115x_CANMSG_EXT)
    {
        msg_id_type = FLEXCAN_MSG_ID_EXT;
    }
    else
    {
        msg_id_type = FLEXCAN_MSG_ID_STD;
    }

    /* Set information about the data to be sent
     *  - Message ID
     *  - Bit rate switch disabled
     *  - Flexible data rate disabled
     *  - Use zeros for FD padding
     *  - Standard frame
     *  - Not in polling mode
     */
    Flexcan_Ip_DataInfoType dataInfo =
    {
        .data_length = DataLen,
        .msg_id_type = msg_id_type,
        .enable_brs  = FALSE,
        .fd_enable   = FALSE,
        .fd_padding  = 0U,
        .is_remote = FALSE,
        .is_polling = FALSE
    };

    /* Execute send non-blocking */
    if ((FLEXCAN_STATUS_SUCCESS != FlexCAN_Ip_SendBlocking(CanComParams->instance,
                                                        CanComParams->mb_idx,
                                                        &dataInfo,
                                                        CanId,
                                                        Data,
                                                        CanComParams->timeout_ms)))
    {
        retVal = TJA115x_ERR_NOACK;
    }

    return retVal;
}

/* Support fucntion configure vanilla for device */
CanTrcv_tja115x_ErrorCodeType TJA115x_DRV_EnterConfigVanilla(const CanTrcv_tja115x_CanComParamsType* CanComParams)
{
    CanTrcv_tja115x_ErrorCodeType retVal = TJA115x_ERR_INVALID;

    /* Bitrate auto-detection */
        retVal = tja115x_drv_send(CANTRCV_TJA115X_AUTOBRDET_CANID, CanComParams, TJA115x_CANMSG_STD, 0U, NULL_PTR);
        if (TJA115x_ERR_NOACK == retVal)
        {
            retVal = TJA115x_ERR_BAUDRATE;
        }

    return retVal;
}

/* Support LeaveConfig for TJA115X */
CanTrcv_tja115x_ErrorCodeType TJA115x_DRV_LeaveConfig(const uint32 CanId,
                                                      const CanTrcv_tja115x_CanComParamsType* CanComParams,
                                                      const CanTrcv_tja115x_LeaveModeType LeaveMode)
{
    CanTrcv_tja115x_ErrorCodeType retVal = TJA115x_NOERROR;
    uint8 payload[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};

    /* Apply command to close configuration window (if present) */
    payload[1] |= (uint8)LeaveMode & 0x80U;
    payload[0] = (uint8)LeaveMode & 0x7FU;

    if (tja115x_drv_send(CanId, CanComParams, TJA115x_CANMSG_EXT, 8U, payload) != TJA115x_NOERROR)
    {
        retVal = TJA115x_ERR_LEAVE;
    }

    return retVal;
}


/**
* @brief        Main function of the example
*/
int main(void)
{
    boolean bPass = TRUE;
    uint8 Transceiver = 0;
    Clock_Ip_StatusType clockStatus;
    Siul2_Port_Ip_PortStatusType t_pinStatus;
    Lpspi_Ip_StatusType IpStatus;
    CanTrcv_tja115x_ErrorCodeType retVal = TJA115x_ERR_INVALID;
    CanTrcv_TrcvModeType OpMode;
    Flexcan_Ip_StatusType eResult_can = FLEXCAN_STATUS_ERROR;
    CanTrcv_tja1145a_StatusType drvStatus;
    uint8 index_data;
    uint8 payload[6U];

    /* Configuration for 0x40 register */
    uint32 register_config_tja1153ATK = (uint32)0x50020000;
    uint8 data_tja1145a[8] = {0x1C, 0x2C, 0x3C, 0x4C, 0x5C, 0x6C, 0x7C, 0x8C};

    /* Setup PDU */
    Can_PduType Can_PduInfo_TJA1145A = Ip_Can_CreatePduInfo(0x01, 0U, 8U, data_tja1145a);

    const Flexcan_Ip_DataInfoType tx_info =
    {
            .msg_id_type = FLEXCAN_MSG_ID_STD,
            .data_length = 8u,
            .is_polling = TRUE,
            .is_remote = FALSE
    };

    const Flexcan_Ip_DataInfoType rx_info =
    {
            .msg_id_type = FLEXCAN_MSG_ID_STD,
            .data_length = 8u,
            .is_polling = TRUE,
            .is_remote = FALSE
    };

    /* Initalized clock */
    clockStatus = Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);
    if(CLOCK_IP_SUCCESS == clockStatus)
    {
        /* Interrupt Init */
        IntCtrl_Ip_Init(&IntCtrlConfig_0);
        /* Init port driver */
        t_pinStatus = Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);
        if(t_pinStatus != SIUL2_PORT_SUCCESS)
        {
            bPass = FALSE;
        }
        /* Init Spi module */
        IpStatus = Lpspi_Ip_Init(&Lpspi_Ip_PhyUnitConfig_SpiPhyUnit_0_Instance_1_BOARD_InitPeripherals);
        if(IpStatus != LPSPI_IP_STATUS_SUCCESS)
        {
           bPass = FALSE;
        }
    }
    else
    {
        bPass = FALSE;
    }
    /* Init Can_0, Can_2 Instances */
    /* Initialize flexcan0 */
    eResult_can = FlexCAN_Ip_Init(FLEXCAN_0_HW_INST, &FlexCAN_BOARD_InitPeripherals_State0, &FlexCAN_Config0_BOARD_InitPeripherals);
    /* Initialize flexcan2 */
    eResult_can |= FlexCAN_Ip_Init(FLEXCAN_2_HW_INST, &FlexCAN_BOARD_InitPeripherals_State1, &FlexCAN_Config1_BOARD_InitPeripherals);
    if(eResult_can != FLEXCAN_STATUS_SUCCESS)
    {
        bPass = FALSE;
    }

    /* Call function TJA1145A_DRV_Init with configList */
    TJA1145A_DRV_Init(Transceiver, &configList_BOARD_InitPeripherals[0]);
    /* Call function TJA1145A_DRV_ConfigureDevice */
    drvStatus = TJA1145A_DRV_ConfigureDevice(Transceiver, configList_BOARD_InitPeripherals[0].DeviceConfig);
    if (drvStatus == E_OK)
    {
        drvStatus = TJA1145A_DRV_SetMode(Transceiver, OpMode);
        if(drvStatus == E_OK)
        {
            drvStatus = TJA1145A_DRV_GetMode(Transceiver, &OpMode);
        }
        else
        {
            bPass = FALSE;
        }
    }
    else
    {
        bPass = FALSE;
    }

    /* Configure TJA115X device through TXD, RXD */
    /* Put cantrcv_tja115x in standby mode by setting EN and STB pins in low level */
    SetMode_TJA115X(TJA115x_STANDBY);

    /* Config Vanilla for device */
    eResult_can = FlexCAN_Ip_SetStartMode(FLEXCAN_0_HW_INST);
    /* Check condition for mode */
    while(FALSE == FlexCAN_Ip_GetStartMode(FLEXCAN_0_HW_INST));

    retVal = TJA115x_DRV_EnterConfigVanilla(&CanTrcv_tja115x_Params0);
    /* Set flexcan to Stop mode */
    eResult_can = FlexCAN_Ip_SetStopMode(FLEXCAN_0_HW_INST);
    if(retVal == TJA115x_NOERROR)
    {
        payload[0] = (uint8)0x10U;
        payload[1] = (uint8)1U;
        payload[2] = (uint8)(0xFFU & (register_config_tja1153ATK >> 24U));
        payload[3] = (uint8)(0xFFU & (register_config_tja1153ATK >> 16U));
        payload[4] = (uint8)(0xFFU & (register_config_tja1153ATK >> 8U));
        payload[5] = (uint8)(0xFFU & (register_config_tja1153ATK >> 0U));

        /* Set flexcan to start mode */
        eResult_can = FlexCAN_Ip_SetStartMode(FLEXCAN_0_HW_INST);
        /* Use TJA115x_CMD60_CONFIG_ID_CANID default to configure of spoofing protection (command byte = 0x10) */
        if (tja115x_drv_send(TJA115x_CMD60_CONFIG_ID_CANID, &CanTrcv_tja115x_Params0, TJA115x_CANMSG_EXT, 6U, payload) != TJA115x_NOERROR)
        {
            retVal = TJA115x_ERR_ELEMENT;
        }
        /* Set flexcan to Stop mode */
        eResult_can = FlexCAN_Ip_SetStopMode(FLEXCAN_0_HW_INST);
        /* Set flexcan to start mode */
        eResult_can = FlexCAN_Ip_SetStartMode(FLEXCAN_0_HW_INST);
        retVal = TJA115x_DRV_LeaveConfig(TJA115x_CMD60_CONFIG_ID_CANID, &CanTrcv_tja115x_Params0, TJA115x_LEAVE_VOLATILE);
        /* Set flexcan to Stop mode */
        eResult_can = FlexCAN_Ip_SetStopMode(FLEXCAN_0_HW_INST);
        if(retVal == TJA115x_NOERROR)
        {
            /* Set TJA115X is in Normal mode */
            SetMode_TJA115X(TJA115x_NORMAL);
        }
    }
    else
    {
        retVal = TJA115x_ERR_INVALID;
    }

    /* Check communication between cantrcv_tja145a and cantrcv_tja1153atk */
    /* Set flexcan to Start mode */
    eResult_can = FlexCAN_Ip_SetStartMode(FLEXCAN_0_HW_INST);
    eResult_can |= FlexCAN_Ip_SetStartMode(FLEXCAN_2_HW_INST);

    /**
 *  @brief     FlexCAN receive message buffer field configuration
 *  @details   This function will config receive parameters form Flexcan_Ip_DataInfoType and
 *             the message Id, and can overwritte another MB status.
 *  @param[in] instance A FlexCAN instance number
 *  @param[in] mb_idx   Index of the message buffer
 *  @param[in] rx_info  Data info
 *  @param[in] msg_id   ID of the message to transmit
 *  @return    FLEXCAN_STATUS_SUCCESS if successful;<br>
 *             FLEXCAN_STATUS_BUFF_OUT_OF_RANGE if the index of a message buffer is invalid.
 *
 */
    eResult_can =  FlexCAN_Ip_ConfigRxMb(FLEXCAN_0_HW_INST, 1U, &rx_info, 0x01);
    if(eResult_can != FLEXCAN_STATUS_SUCCESS)
    {
        bPass = FALSE;
    }

/* Transmit information on CAN bus
Flexcan send a frame
- Hw_Instance: Hw instance
- u8TxMb: Index of the message buffer
- TxInfo: Data info
- u32TxMsgId: ID of the message to transmit.
- TxData: Data Bytes of the FlexCAN message.
*/
    /*@step Flexcan send a frame */
    eResult_can = FlexCAN_Ip_Send(FLEXCAN_2_HW_INST, 0U, &tx_info, Can_PduInfo_TJA1145A.id, Can_PduInfo_TJA1145A.sdu);
    if(eResult_can != FLEXCAN_STATUS_SUCCESS)
    {
        bPass = FALSE;
    }
    /* Wait for the transmission complete */
    eResult_can = FlexCAN_Ip_GetTransferStatus(FLEXCAN_2_HW_INST, 0U);
    if(eResult_can != FLEXCAN_STATUS_SUCCESS)
    {

    	/* Polling of the transmission */
    	do {
    		(void) FlexCAN_Ip_MainFunctionWrite(FLEXCAN_2_HW_INST, 0U);
    		eResult_can = FlexCAN_Ip_GetTransferStatus(FLEXCAN_2_HW_INST, 0U);
    	}
    	while (FLEXCAN_STATUS_BUSY == eResult_can);
    }
    /* Verification point: Tx was confirmed and flag was clear */
    if(eResult_can != FLEXCAN_STATUS_SUCCESS)
    {
        bPass = FALSE;
    }

    eResult_can = FlexCAN_Ip_Receive(FLEXCAN_0_HW_INST, 1U, &rxBuff_Type, TRUE);
    if(eResult_can != FLEXCAN_STATUS_SUCCESS)
    {
        bPass = FALSE;
    }

    while(FlexCAN_Ip_GetTransferStatus(FLEXCAN_0_HW_INST, 1U) != FLEXCAN_STATUS_SUCCESS)
    {
        FlexCAN_Ip_MainFunctionRead(FLEXCAN_0_HW_INST, 1U);
    }
    /* Check data receive*/
    for(index_data = 0; index_data < 8; index_data++)
    {
        if(Can_PduInfo_TJA1145A.sdu[index_data] != rxBuff_Type.data[index_data])
        {
             bPass = FALSE;
        }
    }

    /* Set flexcan to Stop mode */
    eResult_can = FlexCAN_Ip_SetStopMode(FLEXCAN_0_HW_INST);
    eResult_can |= FlexCAN_Ip_SetStopMode(FLEXCAN_2_HW_INST);
    if(eResult_can != FLEXCAN_STATUS_SUCCESS)
    {
        bPass = FALSE;
    }

    /* DeInit Spi */
    Lpspi_Ip_DeInit(HW_SPI_USE);

    Exit_Example(bPass);

    return 0;
}
#ifdef __cplusplus
}
#endif

/** @} */

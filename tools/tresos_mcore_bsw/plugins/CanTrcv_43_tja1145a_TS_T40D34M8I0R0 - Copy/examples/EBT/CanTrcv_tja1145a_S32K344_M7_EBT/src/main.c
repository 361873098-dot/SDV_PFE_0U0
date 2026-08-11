/*
*   (c) Copyright 2022 NXP
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
#include "Mcu.h"
#include "Mcu_Cfg.h"
#include "Dio.h"
#include "Dio_Cfg.h"
#include "Port.h"
#include "Port_Cfg.h"
#include "Spi.h"
#include "Spi_Cfg.h"
#include "Spi_VS_0_PBcfg.h"
#include "Can_43_FLEXCAN.h"
#include "Can_43_FLEXCAN_Cfg.h"
#include "Platform.h"
#include "SchM_Can_43_FLEXCAN.h"
#include "CanTrcv_43_tja1145a.h"
#include "CanTrcv_43_tja1145a_Cfg.h"
#include "CanTrcv_43_tja1145a_VS_0_PBcfg.h"

#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#define TJA115X_EN             DioConf_DioChannel_TJA115X_EN
#define TJA115X_STB            DioConf_DioChannel_TJA115X_STB

#define CANTRCV_TJA115X_ELEMENTS_COUNT  (1U)
#define TJA115x_CMD60_CONFIG_ID_CANID  (0x18DA00F1U)
#define CANTRCV_TJA115X_AUTOBRDET_CANID (0x555U)
#define TJA115x_CMD60_CONFIG_ID_RMASK    (0x1FFFFFFFU)
#define TJA115x_CMD60_CONFIG_ID_SHIFT    (0U)
#define	TJA115x_CMD60_CONFIG_ID(x_) (((uint32)(((uint32)(x_))<<TJA115x_CMD60_CONFIG_ID_SHIFT))&TJA115x_CMD60_CONFIG_ID_RMASK)






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


typedef struct
{
    uint8  instance;   /**< Used CAN instance for configuration. */
    uint8  mb_idx;     /**< Index of the message buffer used for transmission. */
    uint32 timeout_ms; /**< A timeout for the transmission in milliseconds. */
} CanTrcv_tja115x_CanComParamsType;


typedef enum
{
    TJA115x_CANMSG_STD = 0U,
    TJA115x_CANMSG_EXT = 1U
} CanTrcv_tja115x_CanMsgType;

typedef enum
{
    TJA115x_NORMAL = 0U,
    TJA115x_STANDBY = 1U
} CanTrcv_tja115x_mode;

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
uint8 CanIf_u8TxConfirmCnt = 0U;
uint8 CanIf_u8RxIndicationCnt = 0U;
boolean CanIf_bTxFlag = FALSE;
boolean CanIf_bRxFlag = FALSE;

uint8 Can_RxData[8U];

/*brief CAN_4 configuration structure */
const CanTrcv_tja115x_CanComParamsType CanTrcv_tja115x_Params0 =
{
    .instance = 0u,
    .mb_idx = 2u,
    .timeout_ms = 100u
};

const CanTrcv_tja115x_CanComParamsType CanTrcv_tja115x_Params1 =
{
    .instance = 2u,
    .mb_idx = 2u,
    .timeout_ms = 100u
};

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
void CanIf_TrcvModeIndication(uint8 Transceiver, CanTrcv_TrcvModeType TransceiverMode)
{
    (void)Transceiver;
    (void)TransceiverMode;
}

void CanIf_CheckTrcvWakeFlagIndication(uint8 TransceiverId)
{
    (void)TransceiverId;
}

void CanIf_ControllerBusOff(uint8 ControllerId)
{
    (void)ControllerId;
}

void CanIf_ConfirmPnAvailability(uint8 TransceiverId)
{
    (void)TransceiverId;
}

void CanIf_ClearTrcvWufFlagIndication(uint8 TransceiverId)
{
    (void)TransceiverId;
}

void CanIf_ControllerModeIndication(uint8 ControllerId, Can_ControllerStateType ControllerMode )
{
    (void)ControllerId;
    (void)ControllerMode;
}

void CanIf_TxConfirmation(PduIdType CanTxPduId)
{
    CanIf_u8TxConfirmCnt++;
    CanIf_bTxFlag = TRUE;
    (void)CanTxPduId;
}


void CanIf_RxIndication(const Can_HwType* Mailbox, const PduInfoType* PduInfoPtr )
{
    uint8 i;
    
    CanIf_u8RxIndicationCnt++;
    CanIf_bRxFlag = TRUE;
    
    (void)Mailbox;
    (void)PduInfoPtr;
    
    for (i = 0; i < PduInfoPtr->SduLength; i++)
    {
        /* Pointer to received L-SDU (payload) */
        Can_RxData[i] = PduInfoPtr->SduDataPtr[i];
    }
}

/* Create Delay Function */
void Can_43_FLEXCAN_DummyDelay(uint32 loops)
{
    volatile uint32 data = 0xAA55AA55;
    volatile uint32 cnt1 = 0;
    volatile uint32 cnt2 = loops;

    do
    {
        for (cnt1 = 0; cnt1 < 0x2FF; cnt1++)
        {
            data ^= (1 << cnt1) | (0xAAAAAA | cnt2);
        }
        cnt2--;
    } while( cnt2 > 0);
}

Can_PduType Can_CreatePduInfo(Can_IdType id, PduIdType swPduHandle, uint8 length, uint8* sdu)
{
    Can_PduType PduInfo;
    
    PduInfo.id = id;
    PduInfo.swPduHandle = swPduHandle;
    PduInfo.length = length;
    PduInfo.sdu = sdu;
    
    return PduInfo;
}

void SetMode_TJA115X(CanTrcv_tja115x_mode mode)
{
    switch(mode)
    {
    case TJA115x_NORMAL:
        Dio_WriteChannel(TJA115X_EN, STD_HIGH);
        Dio_WriteChannel(TJA115X_STB, STD_HIGH);
        break;
    case TJA115x_STANDBY:
        Dio_WriteChannel(TJA115X_EN, STD_LOW);
        Dio_WriteChannel(TJA115X_STB, STD_LOW);
        break;
    default:
        break;
    }
}


/**
* @brief        Main function of the example
* @details      Initializes the used drivers and uses the CanTrcv_43_tja104x
*               APIs
*/
CanTrcv_tja115x_ErrorCodeType Tja115x_Can_SendFct(const uint32 CanId,
                                                  const CanTrcv_tja115x_CanComParamsType* CanComParams,
                                                  const CanTrcv_tja115x_CanMsgType CanMsgType,
                                                  const uint32 Dlc,
                                                  uint8* const Payload)
{
    Std_ReturnType tempStat = E_NOT_OK;
    CanTrcv_tja115x_ErrorCodeType status;
    uint8 u8TimeOut = 100U;
    CanIf_bTxFlag = FALSE;  
    CanIf_bRxFlag = FALSE;
    static Can_PduType Can_PduInfo;
    uint8 nullData[1] = {0};
    
    if(Payload == NULL_PTR)
    {
        Can_PduInfo = Can_CreatePduInfo(CanId, 0U, Dlc, nullData);
    }
    else
    {
        Can_PduInfo = Can_CreatePduInfo(CanId, 0U, Dlc, Payload);
    }

    if(CanComParams->instance == 0)
    {
        Can_43_FLEXCAN_SetControllerMode(CanController_0, CAN_CS_STARTED);
        
        if(CanMsgType == TJA115x_CANMSG_STD)
        {
            tempStat = Can_43_FLEXCAN_Write(CanHardwareObject_4, &Can_PduInfo);
        }
        else
        {
            Can_PduInfo.id |= CAN_43_FLEXCAN_EXTENDED_ID_U32;
            tempStat = Can_43_FLEXCAN_Write(CanHardwareObject_5, &Can_PduInfo);
        }
    }
    
    if(tempStat == E_OK)
    {
        while((!CanIf_bTxFlag) && (u8TimeOut != 0U))
        {
            Can_43_FLEXCAN_MainFunction_Write();
            Can_43_FLEXCAN_DummyDelay(100U);
            u8TimeOut--;
        }
        
        if(CanComParams->instance == 0)
        {
            Can_43_FLEXCAN_SetControllerMode(CanController_0, CAN_CS_STOPPED);
        }

        if(CanIf_bTxFlag && (u8TimeOut != 0U))
        {
            status = TJA115x_NOERROR;
        }
        else
        {
            status = TJA115x_ERR_NOACK;
        }
    }
    else
    {
        status = TJA115x_ERR_NOACK;
    }
    
    return status;
}


/* Support fucntion configure vanilla for device */
CanTrcv_tja115x_ErrorCodeType TJA115x_DRV_EnterConfigVanilla(const CanTrcv_tja115x_CanComParamsType* CanComParams)
{
    CanTrcv_tja115x_ErrorCodeType retVal = TJA115x_ERR_INVALID;

    /* Bitrate auto-detection */
        retVal = Tja115x_Can_SendFct(CANTRCV_TJA115X_AUTOBRDET_CANID, CanComParams, TJA115x_CANMSG_STD, 0U, NULL_PTR);
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

    if (Tja115x_Can_SendFct(CanId, CanComParams, TJA115x_CANMSG_EXT, 8U, payload) != TJA115x_NOERROR)
    {
        retVal = TJA115x_ERR_LEAVE;
    }

    return retVal;
}


int main(void)
{
    /* Declare variables */
    boolean bPass = FALSE;
    CanTrcv_tja115x_ErrorCodeType retVal = TJA115x_ERR_INVALID;
    CanTrcv_TrcvModeType OpMode;
    uint8 drvStatus = E_NOT_OK;
    uint8 u8TimeOut = 100U;
    uint8 index_data;
    uint8 payload[6U];

/* Configuration for 0x40 register */
    uint32 register_config_tja1153ATK = (uint32)0x50020000;
    
    uint8 data_tja1145a[8] = {0x1B, 0x2B, 0x3B, 0x4B, 0x5B, 0x6B, 0x7B, 0x8B};

/* Setup PDU */
    Can_PduType Can_PduInfo_TJA1145A = Can_CreatePduInfo(0x01, 0U, 8U, data_tja1145a);
    
    /* Initialize all pins using the Port driver */
    Port_Init(NULL_PTR);
    
    Mcu_Init(NULL_PTR);
    Mcu_InitClock(McuClockSettingConfig_0);
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() )
    {
        /* Busy wait until the System PLL is locked */
    }

    Mcu_DistributePllClock();
    Mcu_SetMode(McuModeSettingConf_0);
  
    /* Initialize Platform driver */
    Platform_Init(NULL_PTR);

    /* Call function Spi_Init */
    Spi_Init(NULL_PTR);

    /* Init CAN controler */
    Can_43_FLEXCAN_Init(&Can_43_FLEXCAN_Config_VS_0);

    /* Call function CanTrcv_43_tja1145a_Init */
    CanTrcv_43_tja1145a_Init(&CanTrcv_43_tja1145a_Config_VS_0);

    drvStatus = CanTrcv_43_tja1145a_GetOpMode(0, &OpMode);
    if((drvStatus != E_OK) || (OpMode != CANTRCV_TRCVMODE_NORMAL))
    {
        bPass = FALSE;
    }

/* Configure TJA115X device through TXD, RXD */
/* Put cantrcv_tja115x in standby mode by setting EN and STB pins in low level */
    SetMode_TJA115X(TJA115x_STANDBY);
    
/* Config Vanilla for device */
    retVal = TJA115x_DRV_EnterConfigVanilla(&CanTrcv_tja115x_Params0);
    if(retVal == TJA115x_NOERROR)
    {
        payload[0] = (uint8)0x10U;
        payload[1] = (uint8)1U;
        payload[2] = (uint8)(0xFFU & (register_config_tja1153ATK >> 24U));
        payload[3] = (uint8)(0xFFU & (register_config_tja1153ATK >> 16U));
        payload[4] = (uint8)(0xFFU & (register_config_tja1153ATK >> 8U));
        payload[5] = (uint8)(0xFFU & (register_config_tja1153ATK >> 0U));

        if (Tja115x_Can_SendFct(TJA115x_CMD60_CONFIG_ID_CANID, &CanTrcv_tja115x_Params0, TJA115x_CANMSG_EXT, 6U, payload) != TJA115x_NOERROR)
        {
            retVal = TJA115x_ERR_ELEMENT;
        }

        retVal = TJA115x_DRV_LeaveConfig(TJA115x_CMD60_CONFIG_ID_CANID, &CanTrcv_tja115x_Params0, TJA115x_LEAVE_VOLATILE);
        if(retVal == TJA115x_NOERROR)
        {
            /* Put cantrcv_tja115x in normal mode by setting EN and STB pins in high level */
            SetMode_TJA115X(TJA115x_NORMAL);
        }
    }
    else
    {
        retVal = TJA115x_ERR_INVALID;
    }

/* Comunication */
/* Start CAN Controller to participate in the CAN network */
    drvStatus |= Can_43_FLEXCAN_SetControllerMode(CanController_0, CAN_CS_STARTED);
    drvStatus |= Can_43_FLEXCAN_SetControllerMode(CanController_1, CAN_CS_STARTED);

/* Transmit Can_4 (tja1145a) */
    if((Can_43_FLEXCAN_Write(CanHardwareObject_6, &Can_PduInfo_TJA1145A) == E_OK))
    while((!CanIf_bTxFlag) && (u8TimeOut != 0U))
    {
        Can_43_FLEXCAN_MainFunction_Write();
        Can_43_FLEXCAN_DummyDelay(100U);
        u8TimeOut--;
    }
    u8TimeOut = 100U;
    while((!CanIf_bRxFlag) && (u8TimeOut != 0U))
    {
        Can_43_FLEXCAN_MainFunction_Read();
        Can_43_FLEXCAN_DummyDelay(100U);
        u8TimeOut--;
    }
    /* Verify correction data */
    for (index_data = 0; index_data < 8; index_data++)
    {
        drvStatus = (data_tja1145a[index_data] == Can_RxData[index_data]) ? E_OK : E_NOT_OK;
    }

/* Stop CAN Controller to participate in the CAN network */
    drvStatus |= Can_43_FLEXCAN_SetControllerMode(CanController_0, CAN_CS_STOPPED);
    drvStatus |= Can_43_FLEXCAN_SetControllerMode(CanController_1, CAN_CS_STOPPED);
 
    /* Call function CanTrcv_43_tja1145a_DeInit */
    CanTrcv_43_tja1145a_DeInit();

    /* Call function Spi_DeInit */
    Spi_DeInit();
    
    bPass = (drvStatus == E_OK) ? TRUE : FALSE;
    
    Exit_Example(bPass);
    
    return (0U);
}

#ifdef __cplusplus
}
#endif

/** @} */
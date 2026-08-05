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
*   @file Lin_Ipw.c
* 
*   @addtogroup LIN_IPW
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
#include "Lin_Ipw.h"
#include "Linflexd_Lin_Ip.h"
#include "Linflexd_Lin_Ip_Autosar.h"
#include "Lin_Types.h"
#include "ComStackTypes.h"
#include "LinIf.h"
#include "Soc_Ips.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LIN_IPW_VENDOR_ID_C                    43
#define LIN_IPW_AR_RELEASE_MAJOR_VERSION_C     4
#define LIN_IPW_AR_RELEASE_MINOR_VERSION_C     4
#define LIN_IPW_AR_RELEASE_REVISION_VERSION_C  0
#define LIN_IPW_SW_MAJOR_VERSION_C             4
#define LIN_IPW_SW_MINOR_VERSION_C             0
#define LIN_IPW_SW_PATCH_VERSION_C             2

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Lin_Ipw.h */
#if (LIN_IPW_VENDOR_ID_C != LIN_IPW_VENDOR_ID)
    #error "Lin_Ipw.c and Lin_Ipw.h have different vendor ids"
#endif
/* Check if current file and Lin_Ipw header file are of the same Autosar version */
#if ((LIN_IPW_AR_RELEASE_MAJOR_VERSION_C    != LIN_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_IPW_AR_RELEASE_MINOR_VERSION_C    != LIN_IPW_AR_RELEASE_MINOR_VERSION) || \
     (LIN_IPW_AR_RELEASE_REVISION_VERSION_C != LIN_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_Ipw.c and Lin_Ipw.h are different"
#endif
/* Check if current file and Lin_Ipw header file are of the same Software version */
#if ((LIN_IPW_SW_MAJOR_VERSION_C != LIN_IPW_SW_MAJOR_VERSION) || \
     (LIN_IPW_SW_MINOR_VERSION_C != LIN_IPW_SW_MINOR_VERSION) || \
     (LIN_IPW_SW_PATCH_VERSION_C != LIN_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_Ipw.c and Lin_Ipw.h are different"
#endif

/* Checks against Lin_Types.h */
#if (LIN_IPW_VENDOR_ID_C != LIN_TYPES_VENDOR_ID)
    #error "Lin_Ipw.c and Lin_Types.h have different vendor ids"
#endif
/* Check if current file and Lin_Types header file are of the same Autosar version */
#if ((LIN_IPW_AR_RELEASE_MAJOR_VERSION_C    != LIN_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_IPW_AR_RELEASE_MINOR_VERSION_C    != LIN_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LIN_IPW_AR_RELEASE_REVISION_VERSION_C != LIN_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_Ipw.c and Lin_Types.h are different"
#endif
/* Check if current file and Lin_Types header file are of the same Software version */
#if ((LIN_IPW_SW_MAJOR_VERSION_C != LIN_TYPES_SW_MAJOR_VERSION) || \
     (LIN_IPW_SW_MINOR_VERSION_C != LIN_TYPES_SW_MINOR_VERSION) || \
     (LIN_IPW_SW_PATCH_VERSION_C != LIN_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_Ipw.c and Lin_Types.h are different"
#endif

/* Checks against Linflexd_Lin_Ip.h */
#if (LIN_IPW_VENDOR_ID_C != LINFLEXD_LIN_IP_VENDOR_ID)
    #error "Lin_Ipw.c and Linflexd_Lin_Ip.h have different vendor ids"
#endif
/* Check if current file and Linflexd_Lin_Ip header file are of the same Autosar version */
#if ((LIN_IPW_AR_RELEASE_MAJOR_VERSION_C    != LINFLEXD_LIN_IP_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_IPW_AR_RELEASE_MINOR_VERSION_C    != LINFLEXD_LIN_IP_AR_RELEASE_MINOR_VERSION) || \
     (LIN_IPW_AR_RELEASE_REVISION_VERSION_C != LINFLEXD_LIN_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_Ipw.c and Linflexd_Lin_Ip.h are different"
#endif
/* Check if current file and Linflexd_Lin_Ip header file are of the same Software version */
#if ((LIN_IPW_SW_MAJOR_VERSION_C != LINFLEXD_LIN_IP_SW_MAJOR_VERSION) || \
     (LIN_IPW_SW_MINOR_VERSION_C != LINFLEXD_LIN_IP_SW_MINOR_VERSION) || \
     (LIN_IPW_SW_PATCH_VERSION_C != LINFLEXD_LIN_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_Ipw.c and Linflexd_Lin_Ip.h are different"
#endif

/* Checks against Linflexd_Lin_Ip_Autosar.h */
#if (LIN_IPW_VENDOR_ID_C != LINFLEXD_LIN_IP_AUTOSAR_VENDOR_ID)
    #error "Lin_Ipw.c and Linflexd_Lin_Ip_Autosar.h have different vendor ids"
#endif
/* Check if current file and Linflexd_Lin_Ip_Autosar header file are of the same Autosar version */
#if ((LIN_IPW_AR_RELEASE_MAJOR_VERSION_C    != LINFLEXD_LIN_IP_AUTOSAR_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_IPW_AR_RELEASE_MINOR_VERSION_C    != LINFLEXD_LIN_IP_AUTOSAR_AR_RELEASE_MINOR_VERSION) || \
     (LIN_IPW_AR_RELEASE_REVISION_VERSION_C != LINFLEXD_LIN_IP_AUTOSAR_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_Ipw.c and Linflexd_Lin_Ip_Autosar.h are different"
#endif
/* Check if current file and Linflexd_Lin_Ip_Autosar header file are of the same Software version */
#if ((LIN_IPW_SW_MAJOR_VERSION_C != LINFLEXD_LIN_IP_AUTOSAR_SW_MAJOR_VERSION) || \
     (LIN_IPW_SW_MINOR_VERSION_C != LINFLEXD_LIN_IP_AUTOSAR_SW_MINOR_VERSION) || \
     (LIN_IPW_SW_PATCH_VERSION_C != LINFLEXD_LIN_IP_AUTOSAR_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_Ipw.c and Linflexd_Lin_Ip_Autosar.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Lin_GeneralTypes.h header file are of the same Autosar version */
    #if ((LIN_IPW_AR_RELEASE_MAJOR_VERSION_C != LIN_GENERALTYPES_AR_RELEASE_MAJOR_VERSION) || \
         (LIN_IPW_AR_RELEASE_MINOR_VERSION_C != LIN_GENERALTYPES_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Lin_Ipw.c and Lin_GeneralTypes.h are different"
    #endif
    /* Check if current file and LinIf.h header file are of the same Autosar version */
    #if ((LIN_IPW_AR_RELEASE_MAJOR_VERSION_C != LINIF_AR_RELEASE_MAJOR_VERSION) || \
         (LIN_IPW_AR_RELEASE_MINOR_VERSION_C != LINIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Lin_Ipw.c and LinIf.h are different"
    #endif
    /* Check if current file and Soc_Ips.h header file are of the same Autosar version */
    #if ((LIN_IPW_AR_RELEASE_MAJOR_VERSION_C != SOC_IPS_AR_RELEASE_MAJOR_VERSION) || \
         (LIN_IPW_AR_RELEASE_MINOR_VERSION_C !=  SOC_IPS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Lin_Ipw.c and Soc_Ips.h are different"
    #endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/
/**
* @brief        Sleep command frame: 0xFF data.
*
*/
#define LINFLEXD_DATA_255_U8            ((uint8)255U)

/**
* @brief        Sleep command frame: 0x00 data.
*
*/
#define LINFLEXD_DATA_0_U8              ((uint8)0U)

/**
* @brief        ID used in Gotosleep command transfer.
*
*/
#define SLEEP_COMMAND_ID                ((uint8)0x3CU)

/**
* @brief        ID used in Gotosleep command transfer.
*
*/
#define SLEEP_COMMAND_LENGTH            ((uint8)0x08U)

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
#define LIN_START_SEC_VAR_CLEARED_8
#include "Lin_MemMap.h"
/**
* @brief          Logic - Hw mapping
* @details        This array contains the mapping between logical channel and hw instance.
*/
static uint8 Lin_Ipw_au8HwMapping[LIN_HW_MAX_AVAILABLE_MODULES];

#define LIN_STOP_SEC_VAR_CLEARED_8
#include "Lin_MemMap.h"

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
#define LIN_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Lin_MemMap.h"
/**
* @brief          Global configuration array.
* @details        Array containing channel configurations.
*/
static const Lin_HwConfigType *Lin_Ipw_apChannelsConfig[LIN_HW_MAX_MODULES];

#define LIN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Lin_MemMap.h"

#define LIN_START_SEC_VAR_CLEARED_8
#include "Lin_MemMap.h"
/**
* @brief          LIN header command type variable.
* @details        LIN header command type.
*/
static volatile uint8 Lin_Ipw_au8TransmitHeaderCommand[LIN_HW_MAX_MODULES];

#define LIN_STOP_SEC_VAR_CLEARED_8
#include "Lin_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
static void Lin_Ipw_ErrorCallback(const uint8 Instance, const Linflexd_Lin_Ip_EventIdType CurrentEvent);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
* @brief   Update frame error status of driver.
*
* @param[in]   Channel LIN channel to be addressed
* @param[in]   CurrentEvent current event id of error.
*
* @return                  void.
*/
static void Lin_Ipw_ErrorCallback(const uint8 Instance, const Linflexd_Lin_Ip_EventIdType CurrentEvent)
{
    Lin_SlaveErrorType SlaveError;
    Linflexd_Lin_Ip_TransferStatusType TransferStatus;
    uint8 *Buffer;
    uint8 Channel = Lin_Ipw_au8HwMapping[Instance];
    
    TransferStatus = Linflexd_Lin_Ip_GetStatus(Instance, &Buffer);
    /* Don't care about Buffer */
    (void)Buffer;
    switch (CurrentEvent)
    {
        case LINFLEXD_LIN_IP_FRAME_ERROR:
            if (LINFLEXD_LIN_IP_STATUS_RX_HEADER_ERROR == TransferStatus)
            {
                SlaveError = LIN_ERR_HEADER;
            }
            else
            {
                SlaveError = LIN_ERR_RESP_STOPBIT;
            }
            /* Report an detected error event to Lin Interface */
            LinIf_LinErrorIndication((NetworkHandleType)Channel, SlaveError);
            break;
            
        case LINFLEXD_LIN_IP_READBACK_ERROR:
            /* Report an detected error event to Lin Interface */
            LinIf_LinErrorIndication((NetworkHandleType)Channel, LIN_ERR_RESP_DATABIT);
            break;
        
        case LINFLEXD_LIN_IP_TIMEOUT_ERROR:
            SlaveError = LIN_ERR_HEADER;
            #if (LINFLEXD_LIN_IP_DISABLE_FRAME_TIMEOUT == STD_OFF)
                switch(TransferStatus)
                {
                    case LINFLEXD_LIN_IP_STATUS_RX_HEADER_ERROR:
                        SlaveError = LIN_ERR_HEADER;
                        break;
                    case LINFLEXD_LIN_IP_STATUS_RX_ERROR:
                        SlaveError = LIN_ERR_INC_RESP;
                        break;
                    case LINFLEXD_LIN_IP_STATUS_RX_NO_RESPONSE:
                        SlaveError = LIN_ERR_NO_RESP;
                        break;
                    default:
                        /* will not jump here */
                        break;
                }
            #else
                /* @errata ERR_IPV_LINFLEXD_E007274 */
                #ifdef ERR_IPV_LINFLEXD_E007274
                    /* In errata case, timeout is enabled for Slave mode */
                    switch(TransferStatus)
                    {
                        case LINFLEXD_LIN_IP_STATUS_RX_HEADER_ERROR:
                            SlaveError = LIN_ERR_HEADER;
                            break;
                        case LINFLEXD_LIN_IP_STATUS_RX_ERROR:
                            SlaveError = LIN_ERR_INC_RESP;
                            break;
                        case LINFLEXD_LIN_IP_STATUS_RX_NO_RESPONSE:
                            SlaveError = LIN_ERR_NO_RESP;
                            break;
                        default:
                            /* will not jump here */
                            break;
                    }
                #endif /* ifdef ERR_IPV_LINFLEXD_E007274 */
            #endif /* (LINFLEXD_LIN_IP_DISABLE_FRAME_TIMEOUT == STD_OFF) */
            /* Report an detected error event to Lin Interface */
            LinIf_LinErrorIndication((NetworkHandleType)Channel, SlaveError);
            break;

        case LINFLEXD_LIN_IP_CHECKSUM_ERROR:
            /* Report an detected error event to Lin Interface */
            LinIf_LinErrorIndication((NetworkHandleType)Channel, LIN_ERR_RESP_CHKSUM);
            break;

        case LINFLEXD_LIN_IP_HEADER_RECEPT_ERROR:
            /* Report an detected error event to Lin Interface */
            LinIf_LinErrorIndication((NetworkHandleType)Channel, LIN_ERR_HEADER);
            break;

        case LINFLEXD_LIN_IP_OVERRUN_ERROR:
            /* Report an detected error event to Lin Interface */
            LinIf_LinErrorIndication((NetworkHandleType)Channel, LIN_ERR_INC_RESP);
            break;
            
        default:
            /* Should not enter here. Avoid to misra error */
            break;
    }
}
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief   Check if a LIN channel has been waked-up.
* @details This function identifies which LIN channel has been woken
*          up by the LIN bus transceiver This API is used when the
*          LIN channel wake up functionality is disabled (wake up
*          interrupt is disabled) it checks the wake up flag from
*          all LIN channels which are in sleep mode and which
*          have the wake up functionality disabled.
*
* @param[in] Channel LIN channel to be waked-up.
*
* @return            Std_ReturnType.
* @retval E_OK       If the LIN Channel has the wake
*                    up flag set and the wake up ISR disabled
* @retval E_NOT_OK   Otherwise.
*
*/
Std_ReturnType Lin_Ipw_CheckWakeup(const uint8 Channel)
{
    Std_ReturnType RetVal = E_NOT_OK;
    boolean IsWakeup;
    const Lin_HwConfigType *ChannelConfigPtr = Lin_Ipw_apChannelsConfig[Channel];

    IsWakeup = Linflexd_Lin_Ip_CheckWakeup((uint32)ChannelConfigPtr->LinHwChannel);

    if (TRUE == IsWakeup)
    {
        RetVal = E_OK;
    }

    return RetVal;
}

/**
* @brief   Initialize a LIN channel.
* @details This function initializes all hardware registers needed to
*          start the LIN functionality on the selected channel.
*
* @param[in] Channel LIN channel to be initialized.
* @param[in] ChannelConfigPtr LIN channel configurations.
*
* @return            void.
*
*/
void Lin_Ipw_InitChannel(const uint8 Channel, const Lin_HwConfigType* ChannelConfigPtr)
{
    uint8 HwUnit = ChannelConfigPtr->LinHwChannel;
    /* Initialization of the array which contain the mapping between hardware instances and logical channels */
    Lin_Ipw_au8HwMapping[HwUnit] = Channel;
    /* Save a pointer to the channel configuration structure */
    Lin_Ipw_apChannelsConfig[Channel] = ChannelConfigPtr;
    const Linflexd_Lin_Ip_UserConfigType *TempPointer;

    TempPointer = ChannelConfigPtr->LinFlexdConfig;
    (void)Linflexd_Lin_Ip_Init(HwUnit, TempPointer);

    /* Reset header command type */
    Lin_Ipw_au8TransmitHeaderCommand[Channel] = LIN_IPW_TX_NO_COMMAND;

    /* Set LIN channel state machine to LIN_CH_SLEEP_STATE */
    (void)Linflexd_Lin_Ip_GoToSleepMode(HwUnit);
}

#if (LIN_MASTER_NODE_USED == STD_ON)


/**
* @brief   Sends a LIN frame.
* @details Initiates the transmission of the header
*          part of the LIN frame on Channel using information
*          stored on PduInfoPtr pointer. 
*         
*
* @param[in]   Channel LIN channel to be addressed.
* @param[in]   PduInfoPtr pointer to PDU containing the PID, Checksum model,
*              Response type, Dl and SDU data pointer.
*
* @return            Std_ReturnType.
* @retval LIN_TIMEOUT_ERROR   In case of a timeout situation only.
* @retval E_NOT_OK   Other errors than timeout error.
* @retval E_OK       There is no error.
*
*
*/
Std_ReturnType Lin_Ipw_SendFrame(const uint8 Channel, const Lin_PduType *PduInfoPtr)
{
    Std_ReturnType TempReturn = E_NOT_OK;
    uint8 HwUnit = Lin_Ipw_apChannelsConfig[Channel]->LinHwChannel;
    
    /* Abort any ongoing transmission for any type of frame response */
    if (LINFLEXD_LIN_IP_STATUS_SUCCESS == Linflexd_Lin_Ip_AbortTransferData(HwUnit))
    {
        /* Check of the data length parameter */
        if ((0U < PduInfoPtr->Dl) && (8U >= PduInfoPtr->Dl))
        {
            if (LINFLEXD_LIN_IP_STATUS_SUCCESS == Linflexd_Lin_Ip_SendFrame(HwUnit, (const Linflexd_Lin_Ip_PduType *)PduInfoPtr))
            {   
                /* If Master waits for a response from a slave */
                if (LIN_FRAMERESPONSE_RX == PduInfoPtr->Drc)
                {
                    /* Set the response source (from a remote slave) */
                    Lin_Ipw_au8TransmitHeaderCommand[Channel] = LIN_IPW_TX_SLAVE_RES_COMMAND;
                }
                /* If Master generates the response*/
                else if (LIN_FRAMERESPONSE_TX == PduInfoPtr->Drc)
                {
                    Lin_Ipw_au8TransmitHeaderCommand[Channel] = LIN_IPW_TX_MASTER_RES_COMMAND;
                }
                /* It's a slave to slave response */
                else
                {
                    /* Set the response source (none - it is a slave to slave communication) */
                    Lin_Ipw_au8TransmitHeaderCommand[Channel] = LIN_IPW_TX_SLAVE_TO_SLAVE_COMMAND;
                }
                /* Mark the operation as successful*/
                TempReturn = E_OK;       
            }
            else
            {
                /* Error in send frame */
            }
        }
        else
        {
            /* Out of range */
        }
    }
    else
    {
        TempReturn = (uint8)LIN_TIMEOUT_ERROR;
    }
        
    return TempReturn;
}
#endif


#if (LIN_MASTER_NODE_USED == STD_ON)
/**
* @brief   Prepares and send a go-to-sleep-command
*          frame on Channel.
* @details This function stops any ongoing transmission and initiates
*          the transmission of the sleep command (master command frame with
*          ID = 0x3C and data = (0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF).
*
* @param[in] Channel LIN channel to be addressed.
*
* @return            Std_ReturnType.
* @retval LIN_TIMEOUT_ERROR   In case of a timeout situation only.
* @retval E_NOT_OK   Other errors than timeout error.
* @retval E_OK       There is no error.
*
*/
Std_ReturnType Lin_Ipw_GoToSleep(const uint8 Channel)
{
    Std_ReturnType TempReturn = E_NOT_OK;
    uint8 HwUnit = Lin_Ipw_apChannelsConfig[Channel]->LinHwChannel;
    uint8 Idx = 0U;
    Linflexd_Lin_Ip_PduType SleepFrame;
    uint8 SleepDataField[SLEEP_COMMAND_LENGTH];

    /* Abort any ongoing transmission for any type of frame response */
    if (LINFLEXD_LIN_IP_STATUS_SUCCESS == Linflexd_Lin_Ip_AbortTransferData(HwUnit))
    {
        /* Prepare sleep command data */
        SleepFrame.Dl = SLEEP_COMMAND_LENGTH;
        SleepFrame.Drc = LINFLEXD_LIN_IP_FRAMERESPONSE_TX;
        SleepFrame.Cs = LINFLEXD_LIN_IP_CLASSIC_CS;
        SleepFrame.Pid = SLEEP_COMMAND_ID;
        SleepFrame.SduPtr = SleepDataField;
        SleepDataField[0] = LINFLEXD_DATA_0_U8;

        for (Idx = 1U; Idx < 8U; Idx++)
        {
            SleepDataField[Idx] = LINFLEXD_DATA_255_U8;
        }

        /* Set the type of header command */
        Lin_Ipw_au8TransmitHeaderCommand[Channel] = LIN_IPW_TX_SLEEP_COMMAND;

        if (LINFLEXD_LIN_IP_STATUS_SUCCESS == Linflexd_Lin_Ip_SendFrame(HwUnit, (const Linflexd_Lin_Ip_PduType *)&SleepFrame))
        {
            TempReturn = E_OK;
        }
    }
    else
    {
        TempReturn = (uint8)LIN_TIMEOUT_ERROR;
    }

    return TempReturn;
}
#endif /* (LIN_MASTER_NODE_USED == STD_ON) */
 
/**
* @brief   Same function as Lin_Ipw_GoToSleep() but
*          without sending a go-to-sleep-command on the bus.
* @details This function stops any ongoing transmission and put the
*          Channel in sleep mode (then LIN hardware enters a
*          reduced power operation mode).
*
* @param[in] Channel LIN channel to be addressed.
*
* @return            Std_ReturnType.
* @retval LIN_TIMEOUT_ERROR   In case of a timeout situation only.
* @retval E_NOT_OK   Other errors than timeout error.
* @retval E_OK       There is no error.
*
*/
Std_ReturnType Lin_Ipw_GoToSleepInternal(const uint8 Channel)
{
    Std_ReturnType TempReturn = E_NOT_OK;
    uint8 HwUnit = Lin_Ipw_apChannelsConfig[Channel]->LinHwChannel;

    if (LINFLEXD_LIN_IP_STATUS_SUCCESS == Linflexd_Lin_Ip_AbortTransferData(HwUnit))
    {
        if (LINFLEXD_LIN_IP_STATUS_SUCCESS == Linflexd_Lin_Ip_GoToSleepMode(HwUnit))
        {
            /* Reset header command type */
            Lin_Ipw_au8TransmitHeaderCommand[Channel] = LIN_IPW_TX_NO_COMMAND;
            TempReturn = E_OK;
        }
        else
        {
            /* Timeout occured */
            TempReturn = E_NOT_OK;
        }
    }
    else
    {
        TempReturn = (uint8)LIN_TIMEOUT_ERROR;
    }

    return TempReturn;
}


#if (LIN_MASTER_NODE_USED == STD_ON)
/**
* @brief   Gets the status of the LIN driver when Channel is operating.
* @details This function returns the state of the current
*          transmission, reception or operation status.
*          If the reception of a Slave response was successful then
*          this service provides a pointer to the buffer where the
*          data is stored.
*
* @param[in]   Channel LIN channel to be addressed
* @param[out]  LinSduPtr pointer to pointer to a shadow buffer or memory
*              mapped LIN Hardware receive buffer where the current SDU is
*              stored
* @return                  Lin_StatusType.
* @retval LIN_NOT_OK       Development or production error rised
*                          none of the below conditions.
* @retval LIN_TX_OK        Successful transmission.
* @retval LIN_TX_BUSY      Ongoing transmission of header or response.
* @retval LIN_TX_HEADER_ERROR Error occurred during header
*                          transmission.
* @retval LIN_TX_ERROR     Error occurred during response
*                          transmission.
* @retval LIN_RX_OK        Reception of correct response.
* @retval LIN_RX_BUSY      Ongoing reception where at least one byte
*                          has been received.
* @retval LIN_RX_ERROR     Error occurred during reception.
* @retval LIN_RX_NO_REPONSE No data byte has been received yet.
* @retval LIN_OPERATIONAL  Channel is ready for next header.
*                          transmission and no data are available.
*
*/
Lin_StatusType Lin_Ipw_HardwareGetStatus(const uint8 Channel, uint8 **LinSduPtr)
{
    Lin_StatusType ReturnStatus = LIN_NOT_OK;
    uint8 HwUnit = Lin_Ipw_apChannelsConfig[Channel]->LinHwChannel;
    Linflexd_Lin_Ip_TransferStatusType TransferState;
    
    if (LIN_MASTER_NODE == Lin_Ipw_apChannelsConfig[Channel]->LinNodeType)
    {
        TransferState = Linflexd_Lin_Ip_GetStatus(HwUnit, LinSduPtr);
        switch (TransferState)
        {
            case LINFLEXD_LIN_IP_STATUS_TX_OK:
                ReturnStatus = LIN_TX_OK;
                break;
            case LINFLEXD_LIN_IP_STATUS_TX_BUSY:
                ReturnStatus = LIN_TX_BUSY;
                break;
            case LINFLEXD_LIN_IP_STATUS_TX_HEADER_ERROR:
                ReturnStatus = LIN_TX_HEADER_ERROR;
                break;
            case LINFLEXD_LIN_IP_STATUS_TX_ERROR:
                ReturnStatus = LIN_TX_ERROR;
                break;
            case LINFLEXD_LIN_IP_STATUS_RX_OK:
                ReturnStatus = LIN_RX_OK;
                break;
            case LINFLEXD_LIN_IP_STATUS_RX_BUSY:
                ReturnStatus = LIN_RX_BUSY;
                break;
            case LINFLEXD_LIN_IP_STATUS_RX_ERROR:
                ReturnStatus = LIN_RX_ERROR;
                break;
            case LINFLEXD_LIN_IP_STATUS_RX_NO_RESPONSE:
                ReturnStatus = LIN_RX_NO_RESPONSE;
                break;
            case LINFLEXD_LIN_IP_STATUS_OPERATIONAL:
                ReturnStatus = LIN_OPERATIONAL;
                break;
            case LINFLEXD_LIN_IP_STATUS_SLEEP:
                ReturnStatus = LIN_CH_SLEEP;
                break;
            case LINFLEXD_LIN_IP_STATUS_RX_HEADER_OK:
                /* Fall though, this state only applied Slave mode */
            case LINFLEXD_LIN_IP_STATUS_RX_HEADER_BUSY:
                /* Fall though, this state only applied Slave mode */
            case LINFLEXD_LIN_IP_STATUS_RX_HEADER_ERROR:
                /* Fall though, this state only applied Slave mode */
            case LINFLEXD_LIN_IP_STATUS_FAIL:
                ReturnStatus = LIN_NOT_OK;
                break;
            default:
                /* Should not enter here. Avoid to misra error. */
                break;
        }
    }
    
    return ReturnStatus;
}
#endif /* (LIN_MASTER_NODE_USED == STD_ON) */
 
/**
* @brief   Sends a wake up signal to the LIN bus.
* @details This function shall sent a wake up signal to the LIN bus
*          and put the LIN channel in LIN_CH_OPERATIONAL state.
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return            void.
*
*/
void Lin_Ipw_WakeUp(const uint8 Channel)
{
    uint8 HwUnit = Lin_Ipw_apChannelsConfig[Channel]->LinHwChannel;

    /* Send the wakeup pulse */
    (void)Linflexd_Lin_Ip_SendWakeupSignal(HwUnit);
}
/**
* @brief   Wake up the LIN channel.
* @details This function shall put the LIN channel in LIN_CH_OPERATIONAL_STATE_U8 state without
*          sending a wake up signal to the LIN bus
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return            void.
*
*/
void Lin_Ipw_WakeUpInternal(const uint8 Channel)
{
    uint8 HwUnit = Lin_Ipw_apChannelsConfig[Channel]->LinHwChannel;

    /* Put the  node in the idle state*/
    (void)Linflexd_Lin_Ip_GotoIdleState(HwUnit);
}

/* Callback only from master perspective */
void Lin_Ipw_Callback(const uint8 Instance, const Linflexd_Lin_Ip_StateStructType *LinflexdStateStruct)
{
    uint8 Channel = Lin_Ipw_au8HwMapping[Instance];
    Std_ReturnType TempReturn;

    switch (LinflexdStateStruct->CurrentEventId)
    {
        case LINFLEXD_LIN_IP_TX_COMPLETED:
            if (LIN_SLAVE_NODE == Lin_Ipw_apChannelsConfig[Channel]->LinNodeType)
            {
                /* Calling the LinIf_TxConfirmation function to confirmed to the LIN interface */
                LinIf_TxConfirmation((NetworkHandleType)Channel);
            }
            break;

        case LINFLEXD_LIN_IP_RX_COMPLETED:
            if (LIN_SLAVE_NODE == Lin_Ipw_apChannelsConfig[Channel]->LinNodeType)
            {
                /* Calling the LinIf_RxIndication function to send the received data available to the LIN interface */
                (void)LinIf_RxIndication((NetworkHandleType)Channel, LinflexdStateStruct->SlavePduInfoPtr->SduPtr);
            }
            break;

        case LINFLEXD_LIN_IP_WAKEUP_SIGNAL:
#if (LIN_WAKEUP_DETECTION == STD_ON)
            /* Call EcuM_Checkwakeup */
            if (FALSE != Lin_Ipw_apChannelsConfig[Channel]->LinChannelWakeupSupport)
            {
                EcuM_CheckWakeup(Lin_Ipw_apChannelsConfig[Channel]->LinChannelEcuMWakeupSource);
            }
#endif
            break;

        case LINFLEXD_LIN_IP_FRAME_ERROR:
            /* Fall-through */
        case LINFLEXD_LIN_IP_READBACK_ERROR:
            /* Fall-through */
        case LINFLEXD_LIN_IP_TIMEOUT_ERROR:
            /* Fall-through */
        case LINFLEXD_LIN_IP_CHECKSUM_ERROR:
            /* Fall-through */
        case LINFLEXD_LIN_IP_HEADER_RECEPT_ERROR:
            /* Fall-through */
        case LINFLEXD_LIN_IP_OVERRUN_ERROR:
            /* Handler error */
            if (LIN_SLAVE_NODE == Lin_Ipw_apChannelsConfig[Channel]->LinNodeType)
            {
                Lin_Ipw_ErrorCallback(Instance, LinflexdStateStruct->CurrentEventId);
            }
            break;

        case LINFLEXD_LIN_IP_RECV_HEADER_OK:
            /* Callback function LinIf_HeaderIndication */
            TempReturn = LinIf_HeaderIndication((NetworkHandleType)Channel, (Lin_PduType *)LinflexdStateStruct->SlavePduInfoPtr);
            if ((uint8)E_OK != TempReturn)
            {
                /* set response direction to ignore to discard current frame */
                LinflexdStateStruct->SlavePduInfoPtr->Drc = LINFLEXD_LIN_IP_FRAMERESPONSE_IGNORE;
                /* set Data Length to 1 as default value */
                LinflexdStateStruct->SlavePduInfoPtr->Dl = 1u;
            }
            /* Process response frame base on SlavePduInfo */
            (void)Linflexd_Lin_Ip_SendFrame(Instance, (const Linflexd_Lin_Ip_PduType *)LinflexdStateStruct->SlavePduInfoPtr);
            break;
            
        case LINFLEXD_LIN_IP_NO_EVENT:
            /* Fall-through */
        case LINFLEXD_LIN_IP_SEND_HEADER_OK:
        default:
            /* Should not enter here */
            break;
    }

    /* If gotoSleep command is sent */
    if (LIN_IPW_TX_SLEEP_COMMAND == Lin_Ipw_au8TransmitHeaderCommand[Channel])
    {
        (void)Linflexd_Lin_Ip_GoToSleepMode(Instance);
        /* Reset header command type */
        Lin_Ipw_au8TransmitHeaderCommand[Channel] = LIN_IPW_TX_NO_COMMAND;
    }
}

#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

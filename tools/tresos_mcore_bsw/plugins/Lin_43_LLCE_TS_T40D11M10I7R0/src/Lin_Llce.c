/**
*   @internal
*   @file    Lin_Llce.c
*   @implements Lin_Llce.c_Artifact
*   @version 1.0.7
*
*   @brief   AUTOSAR Lin - LLCE.
*   @details File containing the low level driver of the Llce IP.
*
*   @addtogroup LIN_LLCE
*   @{
*/
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : LLCE
*   Dependencies         : 
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 1.0.7
*   Build Version        : S32_RTD_1_0_7_D2909_ASR_REL_4_4_REV_0000_20230630
*
*   Copyright 2006-2016 Freescale Semiconductor, Inc.
*   Copyright 2020-2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly in
*   accordance with the applicable license terms.
*   By expressly accepting such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to comply with and are bound
*   by, such license terms.  If you do not agree to be bound by the applicable license terms, then you
*   may not retain, install, activate or otherwise use the software.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Lin_43_LLCE.h"
#include "Lin_Llce.h"
#include "Llce_InterfaceLinTypes.h"
#include "Llce_InterfaceCore2Core.h"
#include "StandardTypes.h"
#include "Lin_43_LLCE_Cfg.h"
#include "LinIf.h"

#if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif

#if(LIN_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    #include "Dem.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Lin_Llce.c
*/
#define LIN_LLCE_VENDOR_ID_C                    43
#define LIN_LLCE_AR_RELEASE_MAJOR_VERSION_C     4
#define LIN_LLCE_AR_RELEASE_MINOR_VERSION_C     4

#define LIN_LLCE_AR_RELEASE_REVISION_VERSION_C  0
#define LIN_LLCE_SW_MAJOR_VERSION_C             1
#define LIN_LLCE_SW_MINOR_VERSION_C             0
#define LIN_LLCE_SW_PATCH_VERSION_C             7
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Lin header file are of the same vendor */
#if (LIN_LLCE_VENDOR_ID_C != LIN_43_LLCE_VENDOR_ID)
    #error "Lin_Llce.c and Lin_43_LLCE.h have different vendor ids"
#endif
/* Check if current file and Lin_Llce header file are of the same vendor */
#if (LIN_LLCE_VENDOR_ID_C != LIN_LLCE_VENDOR_ID)
    #error "Lin_Llce.c and Lin_Llce.h have different vendor ids"
#endif
/* Check if current file and Lin_43_LLCE.h header file are of the same Autosar version */
#if ((LIN_LLCE_AR_RELEASE_MAJOR_VERSION_C    != LIN_43_LLCE_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_LLCE_AR_RELEASE_MINOR_VERSION_C    != LIN_43_LLCE_AR_RELEASE_MINOR_VERSION) || \
     (LIN_LLCE_AR_RELEASE_REVISION_VERSION_C != LIN_43_LLCE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_Llce.c and Lin_43_LLCE.h are different"
#endif
/* Check if current file and Lin_43_LLCE.h header file are of the same Software version */
#if ((LIN_LLCE_SW_MAJOR_VERSION_C != LIN_43_LLCE_SW_MAJOR_VERSION) || \
     (LIN_LLCE_SW_MINOR_VERSION_C != LIN_43_LLCE_SW_MINOR_VERSION) || \
     (LIN_LLCE_SW_PATCH_VERSION_C != LIN_43_LLCE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_Llce.c and Lin_43_LLCE.h are different"
#endif

/* Check if current file and Lin_Llce.h header file are of the same Autosar version */
#if ((LIN_LLCE_AR_RELEASE_MAJOR_VERSION_C    != LIN_LLCE_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_LLCE_AR_RELEASE_MINOR_VERSION_C    != LIN_LLCE_AR_RELEASE_MINOR_VERSION) || \
     (LIN_LLCE_AR_RELEASE_REVISION_VERSION_C != LIN_LLCE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_Llce.c and Lin_Llce.h are different"
#endif
/* Check if current file and Lin_Llce.h header file are of the same Software version */
#if ((LIN_LLCE_SW_MAJOR_VERSION_C != LIN_LLCE_SW_MAJOR_VERSION) || \
     (LIN_LLCE_SW_MINOR_VERSION_C != LIN_LLCE_SW_MINOR_VERSION) || \
     (LIN_LLCE_SW_PATCH_VERSION_C != LIN_LLCE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_Llce.c and Lin_Llce.h are different"
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

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
#define LIN_43_LLCE_START_SEC_VAR_CLEARED_8
#include "Lin_43_LLCE_MemMap.h"

/* State of the LIN State Machine when a BIT error occurs */
static volatile uint8 Lin_Llce_au8StateOfBEF[LIN_43_LLCE_HW_MAX_MODULES];

#define LIN_43_LLCE_STOP_SEC_VAR_CLEARED_8
#include "Lin_43_LLCE_MemMap.h"

#define LIN_43_LLCE_START_SEC_VAR_CLEARED_8
#include "Lin_43_LLCE_MemMap.h"

static uint8 Lin_au8Hw2LogicCtrlMap[LLCE_LIN_MAXCTRL_COUNT];

static uint8 au8WakeUpFlag[LLCE_LIN_MAXCTRL_COUNT];

#define LIN_43_LLCE_STOP_SEC_VAR_CLEARED_8
#include "Lin_43_LLCE_MemMap.h"

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
#define LIN_43_LLCE_START_SEC_SHAREDMEMORY
#include "Lin_43_LLCE_MemMap.h"

static volatile Llce_Lin_SharedMemoryType Lin_xSharedMemory;

#define LIN_43_LLCE_STOP_SEC_SHAREDMEMORY
#include "Lin_43_LLCE_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define LIN_43_LLCE_START_SEC_CODE
#include "Lin_43_LLCE_MemMap.h"

static Llce_Lin_ReturnType   Lin_Llce_ExecuteIfCommand(uint8 u8HwCtrl);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/**
* @internal
* @brief          Send a command to the LLCE in order to be executed
* @details        Send a prepared command to the LLCE in order to be executed and get the status code from LLCE
*                 This routine is called by:
*                 - Every function which does a specific command, from Lin_Llce.c file.
*
* @pre            Command should be put in shared memory
* @post           Get the status code returned by LLCE.
*
*
*/
static Llce_Lin_ReturnType Lin_Llce_ExecuteIfCommand(uint8 u8HwCtrl)
{
    /* Timeout counter. */
    uint32          u32TimeoutCount = 0U;
    uint32          u32temp = 0U;

    /* Variable for return status. */
    Llce_Lin_ReturnType eReturnValue = LLCE_LIN_ERROR_TIMEOUT;

    /* Trigger an interrupt to the LLCE */
    LLCE_HOST2TX_ASSERT_INTERRUPT(u8HwCtrl);

    /* Check in polling mode if the command was executed by the LLCE */
    u32TimeoutCount = (uint32)LIN_43_LLCE_TIMEOUT_DURATION;
    do
    {
        u32TimeoutCount--;
        u32temp = LLCE_HOST2TX_GET_STATUS_INTERRUPT(u8HwCtrl);
    }
    while ((u32TimeoutCount > (uint32)0x0U) && ((uint32)0x0U != u32temp));

    MCAL_FAULT_INJECTION_POINT(LIN_LLCE_FIP_4_T_TIME_OUT_4);

    if (u32TimeoutCount > (uint32)0x0U)
    {
        /* Read the status code returned by the LLCE. */
        eReturnValue = Lin_xSharedMemory.Lin_aCmd[u8HwCtrl].eReturnValue;

    }

    return eReturnValue;
}

/**
* @internal
* @brief   This function processes wakeup notification from Llce.
* @details This function processes wakeup notification from Llce
*          on the addressed channel.
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return       void.
*
* @note         Internal driver function.
*
* @implements Lin_Llce_WakeupConfirmation_Activity
*
*/
static void Lin_Llce_WakeupConfirmation(const uint8 u8HwCtrl)
{
    uint8  u8LogicCtrl;
    /* Calculate logic controller index. */
    u8LogicCtrl = Lin_au8Hw2LogicCtrlMap[u8HwCtrl];

    /* Set the wakeup flag to be checked later by CheckWakeup */
    au8WakeUpFlag[u8LogicCtrl] = (uint8)E_OK;

    /* Indicates a valid timer wakeup event to ECU State Manager */
    if ((uint8) STD_ON == Lin_43_LLCE_pxConfigPtr->pLin_Channel[u8LogicCtrl]->pChannelConfigPC->u8LinChannelWakeupSupport)
    {
        EcuM_CheckWakeup(Lin_43_LLCE_pxConfigPtr->pLin_Channel[u8LogicCtrl]->pChannelConfigPC->LinChannelEcuMWakeupSource);
    }
}

/**
* @internal
* @brief   This function processes error indication from Llce.
* @details This function processes error indication from Llce
*          on the addressed channel.
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return       void.
*
* @note         Internal driver function.
*
* @implements Lin_Llce_ErrorIndication_Activity
*
*/
#if (LIN_43_LLCE_SLAVE_NODE_USED == STD_ON)
static void Lin_Llce_ErrorIndication(const uint8 u8HwCtrl)
{
    uint8  u8LogicCtrl;
    Lin_SlaveErrorType eSlaveError;
    Llce_Lin_ReturnType eErrorFlag;

    /* Calculate logic controller index. */
    u8LogicCtrl = Lin_au8Hw2LogicCtrlMap[u8HwCtrl];

    eErrorFlag = LLCE_LIN_SUCCESS;

    /* Convert the Error reported by FW to ASR types and notify it to LinIf. */
    switch (Lin_xSharedMemory.Lin_aNotif[u8HwCtrl].CmdList.ErrorIndication.eSlaveError)
    {
        case LLCE_LIN_ERR_HEADER:
            eSlaveError = LIN_ERR_HEADER;
            break;
        case LLCE_LIN_ERR_RESP_STOPBIT:
            eSlaveError = LIN_ERR_RESP_STOPBIT;
            break;
        case LLCE_LIN_ERR_RESP_CHKSUM:
            eSlaveError = LIN_ERR_RESP_CHKSUM;
            break;
        case LLCE_LIN_ERR_RESP_DATABIT:
            eSlaveError = LIN_ERR_RESP_DATABIT;
            break;
        case LLCE_LIN_ERR_NO_RESP:
            eSlaveError = LIN_ERR_NO_RESP;
            break;
        case LLCE_LIN_ERR_INC_RESP:
            eSlaveError = LIN_ERR_INC_RESP;
            break;
        default:
            eSlaveError = LIN_ERR_HEADER;
            /* Conversion error. */
            eErrorFlag = LLCE_LIN_ERROR;
            break;
    }
    /* If the conversion was successfully */
    if (LLCE_LIN_SUCCESS == eErrorFlag)
    {
        LinIf_LinErrorIndication((NetworkHandleType)u8LogicCtrl, eSlaveError);
    }
}
#endif /* if (LIN_43_LLCE_SLAVE_NODE_USED == STD_ON) */

/**
* @internal
* @brief   This function processes header indication from Llce.
* @details This function processes header indication from Llce
*          on the addressed channel.
*          This function calls LinIf_HeaderIndication() to get
*          the information about what to do with the received Header.
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return       void.
*
* @note         Internal driver function.
*
* @implements Lin_Llce_HeaderIndication_Activity
*
*/
#if (LIN_43_LLCE_SLAVE_NODE_USED == STD_ON)
static void Lin_Llce_HeaderIndication(const uint8 u8HwCtrl)
{
    uint8  u8LogicCtrl;
    Llce_Lin_ReturnType eErrorFlag;
    Lin_PduType xPduInfo;
    uint8  u8Idx;

    /* Calculate logic controller index. */
    u8LogicCtrl = Lin_au8Hw2LogicCtrlMap[u8HwCtrl];

    eErrorFlag = LLCE_LIN_SUCCESS;

    /* Prepare the xPduInfo */
    xPduInfo.Pid = Lin_xSharedMemory.Lin_aNotif[u8HwCtrl].CmdList.HeaderIndication.Pid;
    xPduInfo.Dl = Lin_xSharedMemory.Lin_aNotif[u8HwCtrl].CmdList.HeaderIndication.Dl;

    switch (Lin_xSharedMemory.Lin_aNotif[u8HwCtrl].CmdList.HeaderIndication.Cs)
    {
        case LLCE_LIN_ENHANCED_CS:
            xPduInfo.Cs = LIN_ENHANCED_CS;
            break;
        case LLCE_LIN_CLASSIC_CS:
            xPduInfo.Cs = LIN_CLASSIC_CS;
            break;
        default:
            /* Conversion error. */
            eErrorFlag = LLCE_LIN_ERROR;
            break;
    }

    switch (Lin_xSharedMemory.Lin_aNotif[u8HwCtrl].CmdList.HeaderIndication.Drc)
    {
        case LLCE_LIN_FRAMERESPONSE_TX:
            xPduInfo.Drc = LIN_FRAMERESPONSE_TX;
            break;
        case LLCE_LIN_FRAMERESPONSE_RX:
            xPduInfo.Drc = LIN_FRAMERESPONSE_RX;
            break;
        case LLCE_LIN_FRAMERESPONSE_IGNORE:
            xPduInfo.Drc = LIN_FRAMERESPONSE_IGNORE;
            break;
        default:
            /* Conversion error. */
            eErrorFlag = LLCE_LIN_ERROR;
            break;
    }

    /* If the conversion was successfully */
    if (LLCE_LIN_SUCCESS == eErrorFlag)
    {
        /* Call LinIf to get the result */
        if ((uint8)E_OK == LinIf_HeaderIndication((NetworkHandleType)u8LogicCtrl, &xPduInfo))
        {
            /* Copy the new xPduInfo modified by LinIf to the FW */
            for (u8Idx = 0 ; u8Idx < xPduInfo.Dl ; u8Idx++)
            {
                Lin_xSharedMemory.aLinMb[u8HwCtrl][u8Idx] = xPduInfo.SduPtr[u8Idx];
            }

            Lin_xSharedMemory.Lin_aNotif[u8HwCtrl].CmdList.HeaderIndication.Dl = xPduInfo.Dl;

            switch (xPduInfo.Cs)
            {
                case LIN_ENHANCED_CS:
                    Lin_xSharedMemory.Lin_aNotif[u8HwCtrl].CmdList.HeaderIndication.Cs = LLCE_LIN_ENHANCED_CS;
                    break;
                case LIN_CLASSIC_CS:
                    Lin_xSharedMemory.Lin_aNotif[u8HwCtrl].CmdList.HeaderIndication.Cs = LLCE_LIN_CLASSIC_CS;
                    break;
                default:
                    /* Conversion error. */
                    eErrorFlag = LLCE_LIN_ERROR;
                    break;
            }

            switch (xPduInfo.Drc)
            {
                case LIN_FRAMERESPONSE_TX:
                    Lin_xSharedMemory.Lin_aNotif[u8HwCtrl].CmdList.HeaderIndication.Drc = LLCE_LIN_FRAMERESPONSE_TX;
                    break;
                case LIN_FRAMERESPONSE_RX:
                    Lin_xSharedMemory.Lin_aNotif[u8HwCtrl].CmdList.HeaderIndication.Drc = LLCE_LIN_FRAMERESPONSE_RX;
                    break;
                case LIN_FRAMERESPONSE_IGNORE:
                    Lin_xSharedMemory.Lin_aNotif[u8HwCtrl].CmdList.HeaderIndication.Drc = LLCE_LIN_FRAMERESPONSE_IGNORE;
                    break;
                default:
                    /* Conversion error. */
                    eErrorFlag = LLCE_LIN_ERROR;
                    break;
            }

            /* If the conversion was successfully */
            if (LLCE_LIN_SUCCESS == eErrorFlag)
            {
                /* Store the status for FW. */
                Lin_xSharedMemory.Lin_aNotif[u8HwCtrl].eReturnValue = LLCE_LIN_SUCCESS;
            }
            else
            {
                /* Store the status for FW. */
                Lin_xSharedMemory.Lin_aNotif[u8HwCtrl].eReturnValue = LLCE_LIN_ERROR;
            }
        }
        else
        {
            /* Store the status for FW. */
            Lin_xSharedMemory.Lin_aNotif[u8HwCtrl].eReturnValue = LLCE_LIN_ERROR;
        }
    }
}
#endif /* #if (LIN_43_LLCE_SLAVE_NODE_USED == STD_ON) */

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/

/**
* @internal
* @brief   Check if a LIN channel has been woken-up.
* @details This function identifies if the addressed LIN channel
*          has been woken up by the LIN bus transceiver.
*          This function returns E_OK only the first time
*          ater the wake up event.
*
* @param[in] Channel LIN channel to be checked.
*
* @return            Std_ReturnType.
* @retval E_OK       If the LIN Channel has been woken-up
* @retval E_NOT_OK   Otherwise.
*
* @implements Lin_Llce_CheckWakeup_Activity
*
*/
Std_ReturnType Lin_Llce_CheckWakeup(const uint8 u8Channel)
{
    Std_ReturnType u8TempReturn = (uint8)E_NOT_OK;

    if ((uint8)E_OK == au8WakeUpFlag[u8Channel])
    {
        u8TempReturn = (uint8)E_OK;

        au8WakeUpFlag[u8Channel] = (uint8)E_NOT_OK;
    }

    return u8TempReturn;
}

/**
* @internal
* @brief   Initialize a LIN channel.
* @details This function initializes all hardware registers needed to
*          start the LIN functionality on the selected channel.
*
* @param[in] Channel LIN channel to be initialized.
*
* @return            void.
*
* @implements Lin_Llce_Init_Activity
*
*/
void Lin_Llce_Init(void)
{
    volatile Llce_Lin_ChannelConfigType * pxHwCtrlConfig = NULL_PTR;
    const Lin_43_LLCE_ChannelConfigType * pxLinChannelConfig = NULL_PTR;

    /* Index LIN channel from configuration. */
    uint8 u8CtrlIndex = 0U;
    /* Controller hardware offset on chip. */
    uint8 u8HwCtrl = 0U;

    /* Initialize all the LIN controllers */
    for (u8CtrlIndex = 0U; u8CtrlIndex < LIN_43_LLCE_HW_MAX_MODULES; u8CtrlIndex++)
    {
        pxLinChannelConfig = Lin_43_LLCE_pxConfigPtr->pLin_Channel[u8CtrlIndex];
        u8HwCtrl = pxLinChannelConfig->pChannelConfigPC->u8LinHwChannel;

        /* Check if the command buffer is not already used by other command request. */
        if (0x0U == LLCE_HOST2TX_GET_STATUS_INTERRUPT(u8HwCtrl))
        {
            /* Configure the command id. */
            Lin_xSharedMemory.Lin_aCmd[u8HwCtrl].eCmdId = LLCE_LIN_CMD_INIT;

            /* Get a pointer to the shared memory. */
            pxHwCtrlConfig = &Lin_xSharedMemory.Lin_aCmd[u8HwCtrl].CmdList.Init.CtrlConfig;

            /* Store the configuration data related to hardware controller. e.g options, etc.*/
            pxHwCtrlConfig->eLinNodeType = pxLinChannelConfig->pChannelConfigPC->eLinNodeType;
            pxHwCtrlConfig->u8LinChannelWakeupSupport = pxLinChannelConfig->pChannelConfigPC->u8LinChannelWakeupSupport;
            pxHwCtrlConfig->u8LinChannelDisableFrameTimeout = pxLinChannelConfig->pChannelConfigPC->u8LinChannelDisableFrameTimeout;
            pxHwCtrlConfig->u32LinBaudRateRegValue = pxLinChannelConfig->u32LinBaudRateRegValue;
            pxHwCtrlConfig->u8LinChannelBrkLengthMaster = pxLinChannelConfig->u8LinChannelBrkLengthMaster;
            pxHwCtrlConfig->u8LinChannelBrkLengthSlave = pxLinChannelConfig->u8LinChannelBrkLengthSlave;
            pxHwCtrlConfig->u8ResponseTimeout = pxLinChannelConfig->u8ResponseTimeout;
            pxHwCtrlConfig->u8HeaderTimeout = pxLinChannelConfig->u8HeaderTimeout;

            /* Create a vector for Hw2Logic mapping */
            Lin_au8Hw2LogicCtrlMap[u8HwCtrl] = u8CtrlIndex;

            /* Initialize wake up status flag */
            au8WakeUpFlag[u8CtrlIndex] = (uint8)E_NOT_OK;

            /* Disable interrupts from rx core to host core for a specific channel.*/
            LLCE_TX2HOST_DISABLE_INTERRUPT(u8HwCtrl);

            /* Clear existing interrupts from rx core for a specific channel.*/
            LLCE_TX2HOST_CLEAR_INTERRUPT(u8HwCtrl);

            /* Enable interrupts from rx core to host core for a specific channel.*/
            LLCE_TX2HOST_ENABLE_INTERRUPT(u8HwCtrl);

            /* Send the command prepared above to the LLCE in order to be executed */
            if (LLCE_LIN_ERROR == Lin_Llce_ExecuteIfCommand(u8HwCtrl))
            {
                /*Report a DEM  error*/
            }

        } else
        {
            /*Report a DEM  error*/
        }
    }

}

#if (LIN_43_LLCE_MASTER_NODE_USED == STD_ON)
/**
* @internal
* @brief   Sends the header part of the LIN frame.
* @details Initiates the transmission of the header
*          part of the LIN frame on Channel using information
*          stored on PduInfoPtr pointer.
*          If response type is MASTER_RESPONSE then nothing is sent over the bus
*          the entire frame (including header) is sent with the Lin_LLCE_LIN_SendResponse
*
* @param[in]   Channel LIN channel to be addressed.
* @param[in]   PduInfoPtr pointer to PDU containing the PID, Checksum model,
*              Response type, Dl and SDU data pointer.
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a timeout situation only.
* @retval E_OK       Otherwise.
*
* @implements Lin_Llce_SendFrame_Activity
*
*/
Std_ReturnType Lin_Llce_SendFrame(const uint8 u8Channel, \
                                  const Lin_PduType * pPduInfoPtr \
                                 )

{
    /* Variable for return status. */
    Std_ReturnType u8TempReturn = (uint8)E_NOT_OK;
    /* Controller hardware offset on chip. */
    uint8          u8HwCtrl = 0U;
    /* Variable for byte index of the buffer data. */
    uint8          u8MbDataByte = 0U;

    Llce_Lin_ReturnType eLlceReturn = LLCE_LIN_ERROR;
    volatile Llce_Lin_SendFrameCmdType * pxLlceCmd = NULL_PTR;

    /* Get the hardware offset for this controller. */
    u8HwCtrl = Lin_43_LLCE_pChannelConfigPtr[u8Channel]->pChannelConfigPC->u8LinHwChannel;

    /* Check if the command buffer is not already used by other command request */
    if (0x0U == LLCE_HOST2TX_GET_STATUS_INTERRUPT(u8HwCtrl))
    {
        /* Get access to the command buffer. */
        pxLlceCmd = &Lin_xSharedMemory.Lin_aCmd[u8HwCtrl].CmdList.SendFrame;

        /* Configure the command id. */
        Lin_xSharedMemory.Lin_aCmd[u8HwCtrl].eCmdId = LLCE_LIN_CMD_SENDFRAME;
        pxLlceCmd->Pid = pPduInfoPtr->Pid;
        pxLlceCmd->Dl = pPduInfoPtr->Dl;

        switch (pPduInfoPtr->Cs)
        {
            case LIN_ENHANCED_CS:
                pxLlceCmd->Cs = LLCE_LIN_ENHANCED_CS;
                break;
            case LIN_CLASSIC_CS:
                pxLlceCmd->Cs = LLCE_LIN_CLASSIC_CS;
                break;
            default:
                /* Conversion error */
                break;
        }

        switch (pPduInfoPtr->Drc)
        {
            case LIN_FRAMERESPONSE_TX:
                pxLlceCmd->Drc = LLCE_LIN_FRAMERESPONSE_TX;
                break;
            case LIN_FRAMERESPONSE_RX:
                pxLlceCmd->Drc = LLCE_LIN_FRAMERESPONSE_RX;
                break;
            case LIN_FRAMERESPONSE_IGNORE:
                pxLlceCmd->Drc = LLCE_LIN_FRAMERESPONSE_IGNORE;
                break;
            default:
                /* Conversion error */
                break;
        }

        if (LIN_FRAMERESPONSE_TX == pPduInfoPtr->Drc)
        {
            /* Copy the data into the buff memory. The driver will not read from a null pointer SDU. */
            for (u8MbDataByte = (uint8)0U; u8MbDataByte < pPduInfoPtr->Dl; u8MbDataByte++)
            {
                pxLlceCmd->Sdu[u8MbDataByte] = (uint8)((pPduInfoPtr->SduPtr)[u8MbDataByte]);
            }
        }

        MCAL_FAULT_INJECTION_POINT(LIN_LLCE_FIP_1_T_TIME_OUT_1);

        /* Send the command prepared above to the LLCE in order to be executed */
        eLlceReturn = Lin_Llce_ExecuteIfCommand(u8HwCtrl);

        switch (eLlceReturn) {
            case LLCE_LIN_SUCCESS:
#if (LIN_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                if ((uint32)STD_ON == Lin_43_LLCE_E_TimeoutCfg.state)
                {
                    (void)Dem_SetEventStatus((Dem_EventIdType)Lin_43_LLCE_E_TimeoutCfg.id, \
                                            DEM_EVENT_STATUS_PASSED \
                                            );
                }
#endif /* (LIN_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
                u8TempReturn = (uint8)E_OK;
                break;
            case LLCE_LIN_ERROR_STATE:
                /* LIN channel is in sleep mode */
#if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
                /* Report error to development error tracer */
                (void)Det_ReportError((uint16)LIN_43_LLCE_MODULE_ID, \
                                      (uint8)0, \
                                      (uint8)LIN_43_LLCE_SENDFRAME_ID, \
                                      (uint8)LIN_43_LLCE_E_STATE_TRANSITION \
                                     );
#endif /* (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
                u8TempReturn = (uint8)E_NOT_OK;
                break;
            case LLCE_LIN_ERROR_TIMEOUT:
            /* Report Production error */
            #if (LIN_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                if ((uint32)STD_ON == Lin_43_LLCE_E_TimeoutCfg.state)
                {
                    (void)Dem_SetEventStatus((Dem_EventIdType)Lin_43_LLCE_E_TimeoutCfg.id, \
                                           DEM_EVENT_STATUS_FAILED \
                                            );
                }
                else
                {
            #endif  /* (LIN_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
                #if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
                    /* Report error to development error tracer */
                    (void)Det_ReportError((uint16)LIN_43_LLCE_MODULE_ID, \
                                          (uint8)0, \
                                          (uint8)LIN_43_LLCE_SENDFRAME_ID, \
                                          (uint8)LIN_43_LLCE_E_TIMEOUT \
                                         );
                #endif  /* (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
            #if (LIN_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                    ; /* Deliberately left here to avoid misra violation. */
                }
            #endif  /* (LIN_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
                u8TempReturn = (uint8)E_NOT_OK;
                break;
            default:
                u8TempReturn = (uint8)E_NOT_OK;
                break;
        }
    }

    return u8TempReturn;
}
#endif /* #if LIN_43_LLCE_MASTER_NODE_USED == STD_ON */

#if (LIN_43_LLCE_MASTER_NODE_USED == STD_ON)
/**
* @internal
* @brief   Prepares and sends a go-to-sleep-command
*          frame on Channel.
* @details This function stops any ongoing transmission and initiates
*          the transmission of the sleep command (master command frame with
*          ID = 0x3C and data = (0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF).
*
* @param[in] Channel LIN channel to be addressed.
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a timeout situation only.
* @retval E_OK       Otherwise.
*
* @implements Lin_Llce_GoToSleep_Activity
*
*/
Std_ReturnType Lin_Llce_GoToSleep(const uint8 u8Channel)
{
    uint8          u8HwCtrl = 0U;
    Std_ReturnType u8TmpReturn = (uint8)E_NOT_OK;
    Llce_Lin_ReturnType eLlceReturn = LLCE_LIN_ERROR;

    /* Get the hardware offset for this controller. */
    u8HwCtrl = Lin_43_LLCE_pChannelConfigPtr[u8Channel]->pChannelConfigPC->u8LinHwChannel;

    MCAL_FAULT_INJECTION_POINT(LIN_LLCE_FIP_2_T_TIME_OUT_2);

    /* Check if the command buffer is not already used by other command request */
    if (0x0U == LLCE_HOST2TX_GET_STATUS_INTERRUPT(u8HwCtrl))
    {
        /* Configure the command id. */
        Lin_xSharedMemory.Lin_aCmd[u8HwCtrl].eCmdId = LLCE_LIN_CMD_GOTOSLEEP;

         /* Send the command prepared above to the LLCE in order to be executed */
        eLlceReturn = Lin_Llce_ExecuteIfCommand(u8HwCtrl);

        /* Process llce return */
        switch (eLlceReturn)
        {
            case LLCE_LIN_SUCCESS:
                /* Report Production error */
                #if (LIN_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                    if ((uint32)STD_ON == Lin_43_LLCE_E_TimeoutCfg.state)
                    {
                        (void)Dem_SetEventStatus((Dem_EventIdType)Lin_43_LLCE_E_TimeoutCfg.id, \
                                                  DEM_EVENT_STATUS_PASSED \
                                                );
                    }
                #endif /* (LIN_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */

                /* Clear the wakeup flag */
                au8WakeUpFlag[u8Channel] = (uint8)E_NOT_OK;

                u8TmpReturn = (uint8)E_OK;
                break;
            case LLCE_LIN_ERROR_TIMEOUT:
                /* Report Production error */
                #if (LIN_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                    if ((uint32)STD_ON == Lin_43_LLCE_E_TimeoutCfg.state)
                    {
                        (void)Dem_SetEventStatus((Dem_EventIdType)Lin_43_LLCE_E_TimeoutCfg.id, \
                                                  DEM_EVENT_STATUS_FAILED \
                                                );
                    }
                    else
                    {
                #endif  /* (LIN_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
                        #if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
                        /* Report error to development error tracer */
                        (void)Det_ReportError((uint16)LIN_43_LLCE_MODULE_ID, \
                                              (uint8)0x0U, \
                                              (uint8)LIN_43_LLCE_GOTOSLEEP_ID, \
                                              (uint8)LIN_43_LLCE_E_TIMEOUT \
                                             );
                        #endif /* (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
                #if (LIN_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        ; /* Deliberately left here to avoid misra violation. */
                    }
                #endif  /* (LIN_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */

                u8TmpReturn = (uint8)E_NOT_OK;
                break;
            case LLCE_LIN_ERROR_STATE:
                /* Already into sleep state */
                u8TmpReturn = (uint8)E_OK;
                break;
            default:
                u8TmpReturn = (uint8)E_NOT_OK;
                break;
        }
    }

    return u8TmpReturn;
}
#endif /* #if LIN_43_LLCE_MASTER_NODE_USED == STD_ON */

/**
* @internal
* @brief   Same function as Lin_LLD_GoToSleep() but
*          without sending a go-to-sleep-command on the bus.
* @details This function stops any ongoing transmission and put the
*          Channel in sleep mode (then LIN hardware enters a
*          reduced power operation mode).
*
* @param[in] Channel LIN channel to be addressed.
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a timeout situation only.
* @retval E_OK       Otherwise.
*
* @implements Lin_Llce_GoToSleepInternal_Activity
*
*/
Std_ReturnType Lin_Llce_GoToSleepInternal(const uint8 u8Channel)
{
    uint8 u8HwCtrl = 0U;
    Std_ReturnType u8TmpReturn = (uint8)E_NOT_OK;
    Llce_Lin_ReturnType eLlceReturn = LLCE_LIN_ERROR;

    /* Get the hardware offset for this controller. */
    u8HwCtrl = Lin_43_LLCE_pChannelConfigPtr[u8Channel]->pChannelConfigPC->u8LinHwChannel;

    MCAL_FAULT_INJECTION_POINT(LIN_LLCE_FIP_3_T_TIME_OUT_3);

    /* Check if the command buffer is not already used by other command request */
    if (0x0U == LLCE_HOST2TX_GET_STATUS_INTERRUPT(u8HwCtrl))
    {
        /* Configure the command id. */
        Lin_xSharedMemory.Lin_aCmd[u8HwCtrl].eCmdId = LLCE_LIN_CMD_GOTOSLEEPINTERNAL;

        /* Send the command prepared above to the LLCE in order to be executed */
        eLlceReturn = Lin_Llce_ExecuteIfCommand(u8HwCtrl);

        /* Process llce return */
        switch (eLlceReturn)
        {
            case LLCE_LIN_SUCCESS:
                /* Report Production error */
                #if (LIN_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                    if ((uint32)STD_ON == Lin_43_LLCE_E_TimeoutCfg.state)
                    {
                        (void)Dem_SetEventStatus((Dem_EventIdType)Lin_43_LLCE_E_TimeoutCfg.id, \
                                                  DEM_EVENT_STATUS_PASSED \
                                                );
                    }
                #endif /* (LIN_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */

                /* Clear the wakeup flag */
                au8WakeUpFlag[u8Channel] = (uint8)E_NOT_OK;

                u8TmpReturn = (uint8)E_OK;
                break;
            case LLCE_LIN_ERROR_TIMEOUT:
                /* Report Production error */
                #if (LIN_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                    if ((uint32)STD_ON == Lin_43_LLCE_E_TimeoutCfg.state)
                    {
                        (void)Dem_SetEventStatus((Dem_EventIdType)Lin_43_LLCE_E_TimeoutCfg.id, \
                                                  DEM_EVENT_STATUS_FAILED \
                                                );
                    }
                    else
                    {
                #endif  /* (LIN_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
                        #if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
                        /* Report error to development error tracer */
                        (void)Det_ReportError((uint16)LIN_43_LLCE_MODULE_ID, \
                                              (uint8)0x0U, \
                                              (uint8)LIN_43_LLCE_GOTOSLEEPINTERNAL_ID, \
                                              (uint8)LIN_43_LLCE_E_TIMEOUT \
                                             );
                        #endif /* (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
                #if (LIN_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        ; /* Deliberately left here to avoid misra violation. */
                    }
                #endif  /* (LIN_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */

                u8TmpReturn = (uint8)E_NOT_OK;
                break;
            case LLCE_LIN_ERROR_STATE:
                /* Already into sleep state */
                u8TmpReturn = (uint8)E_OK;
                break;
            default:
                u8TmpReturn = (uint8)E_NOT_OK;
                break;
        }
    }

    return u8TmpReturn;
}

/**
* @internal
* @brief   Sends a wake up signal to the LIN bus.
* @details This function shall sent a wake up signal to the LIN bus
*          and put the LIN channel in LIN_CH_OPERATIONAL state.
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return            void.
*
* @implements Lin_Llce_WakeUp_Activity
*
*/
Std_ReturnType Lin_Llce_WakeUp(const uint8 u8Channel)
{
    uint8          u8HwCtrl = 0U;
    Std_ReturnType u8TmpReturn = (uint8)E_NOT_OK;
    Llce_Lin_ReturnType eLlceReturn = LLCE_LIN_ERROR;

    /* Get the hardware offset for this controller. */
    u8HwCtrl = Lin_43_LLCE_pChannelConfigPtr[u8Channel]->pChannelConfigPC->u8LinHwChannel;

    /* Check if the command buffer is not already used by other command request */
    if (0x0U == LLCE_HOST2TX_GET_STATUS_INTERRUPT(u8HwCtrl))
    {
        /* Configure the command id. */
       Lin_xSharedMemory.Lin_aCmd[u8HwCtrl].eCmdId = LLCE_LIN_CMD_WAKEUP;

        /* Send the command prepared above to the LLCE in order to be executed */
        eLlceReturn = Lin_Llce_ExecuteIfCommand(u8HwCtrl);

        switch (eLlceReturn)
        {
            case LLCE_LIN_SUCCESS:
                u8TmpReturn = (uint8)E_OK;
                break;
            case LLCE_LIN_ERROR_STATE:
#if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
                /* Report error to development error tracer */
                (void)Det_ReportError((uint16)LIN_43_LLCE_MODULE_ID, \
                                      (uint8)0x0U, \
                                      (uint8)LIN_43_LLCE_WAKEUP_ID, \
                                      (uint8)LIN_43_LLCE_E_STATE_TRANSITION \
                                     );
#endif /* (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
                u8TmpReturn = (uint8)E_NOT_OK;
                break;
            default:
                u8TmpReturn = (uint8)E_NOT_OK;
                break;
        }
    }

    return u8TmpReturn;
}

/**
* @internal
* @brief   Wake up the LIN channel.
* @details This function shall put the LIN channel in LIN_CH_OPERATIONAL state without
*          sending a wake up signal to the LIN bus
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return            void.
*
* @implements Lin_Llce_WakeupInternal_Activity
*
*/
Std_ReturnType Lin_Llce_WakeupInternal(const uint8 u8Channel)
{
    uint8          u8HwCtrl = 0U;
    Std_ReturnType u8TmpReturn = (uint8)E_NOT_OK;
    Llce_Lin_ReturnType eLlceReturn = LLCE_LIN_ERROR;

    /* Get the hardware offset for this controller. */
    u8HwCtrl = Lin_43_LLCE_pChannelConfigPtr[u8Channel]->pChannelConfigPC->u8LinHwChannel;

    /* Check if the command buffer is not already used by other command request */
    if (0x0U == LLCE_HOST2TX_GET_STATUS_INTERRUPT(u8HwCtrl))
    {
        /* Configure the command id. */
       Lin_xSharedMemory.Lin_aCmd[u8HwCtrl].eCmdId = LLCE_LIN_CMD_WAKEUPINTERNAL;

        /* Send the command prepared above to the LLCE in order to be executed */
        eLlceReturn = Lin_Llce_ExecuteIfCommand(u8HwCtrl);

        switch (eLlceReturn)
        {
            case LLCE_LIN_SUCCESS:
                u8TmpReturn = (uint8)E_OK;
                break;
            case LLCE_LIN_ERROR_STATE:
#if (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON)
                /* Report error to development error tracer */
                (void)Det_ReportError((uint16)LIN_43_LLCE_MODULE_ID, \
                                      (uint8)0x0U, \
                                      (uint8)LIN_43_LLCE_WAKEUPINTERNAL_ID, \
                                      (uint8)LIN_43_LLCE_E_STATE_TRANSITION \
                                     );
#endif /* (LIN_43_LLCE_DEV_ERROR_DETECT == STD_ON) */
                u8TmpReturn = (uint8)E_NOT_OK;
                break;
            default:
                u8TmpReturn = (uint8)E_NOT_OK;
                break;
        }
    }

    return u8TmpReturn;
}

#if (LIN_43_LLCE_MASTER_NODE_USED == STD_ON)
/**
* @internal
* @brief   Gets the status of the LIN driver when Channel is operating.
* @details This function returns the state of the current
*          transmission, reception or operation status.
*          If the reception of a Slave response was successful then
*          this service provides a pointer to the buffer where the
*          data is stored.
*
* @param[in]   Channel LIN channel to be addressed
* @param[out]  pu8LinSduPtr pointer to pointer to a shadow buffer or memory
*              mapped LIN Hardware receive buffer where the current SDU is
*              stored
* @return                  Lin_StatusType.
* @retval LIN_NOT_OK       Development or production error raised
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
* @retval LIN_RX_NO_RESPONSE No data byte has been received yet.
* @retval LIN_OPERATIONAL  Channel is ready for next header.
*                          transmission and no data is available.
* @retval LIN_CH_SLEEP     Channel is in sleep mode.
*
*
* @implements Lin_Llce_HardwareGetStatus_Activity
*
*/
Lin_StatusType Lin_Llce_HardwareGetStatus(const uint8 u8Channel, \
                                          uint8 ** pu8LinSduPtr \
                                         )
{
    uint8 u8HwCtrl = 0x0U;
    Lin_StatusType u8tempReturn = LIN_NOT_OK;
    Llce_Lin_StatusType u8LlceReturn = LLCE_LIN_NOT_OK;

    u8HwCtrl = Lin_43_LLCE_pChannelConfigPtr[u8Channel]->pChannelConfigPC->u8LinHwChannel;

    /* Check if the command buffer is not already used by other command request */
    if (0x0U == LLCE_HOST2TX_GET_STATUS_INTERRUPT(u8HwCtrl))
    {
        /* Configure the command id. */
        Lin_xSharedMemory.Lin_aCmd[u8HwCtrl].eCmdId = LLCE_LIN_CMD_GETSTATUS;

         /* Send the command prepared above to the LLCE in order to be executed */
        if (LLCE_LIN_SUCCESS == Lin_Llce_ExecuteIfCommand(u8HwCtrl))
        {
            u8LlceReturn = Lin_xSharedMemory.Lin_aCmd[u8HwCtrl].CmdList.GetStatus.u8ControllerStatus;

            switch (u8LlceReturn)
            {
                case LLCE_LIN_NOT_OK:
                    u8tempReturn = LIN_NOT_OK;
                    break;
                case LLCE_LIN_TX_OK:
                    u8tempReturn = LIN_TX_OK;
                    break;
                case LLCE_LIN_TX_BUSY:
                    u8tempReturn = LIN_TX_BUSY;
                    break;
                case LLCE_LIN_TX_HEADER_ERROR:
                    u8tempReturn = LIN_TX_HEADER_ERROR;
                    break;
                case LLCE_LIN_TX_ERROR:
                    u8tempReturn = LIN_TX_ERROR;
                    break;
                case LLCE_LIN_RX_OK:
                    u8tempReturn = LIN_RX_OK;
                    break;
                case LLCE_LIN_RX_BUSY:
                    u8tempReturn = LIN_RX_BUSY;
                    break;
                case LLCE_LIN_RX_ERROR:
                    u8tempReturn = LIN_RX_ERROR;
                    break;
                case LLCE_LIN_RX_NO_RESPONSE:
                    u8tempReturn = LIN_RX_NO_RESPONSE;
                    break;
                case LLCE_LIN_OPERATIONAL:
                    u8tempReturn = LIN_OPERATIONAL;
                    break;
                case LLCE_LIN_CH_SLEEP:
                    u8tempReturn = LIN_CH_SLEEP;
                    break;
                default:
                    u8tempReturn = LIN_NOT_OK;
                    break;
            }

            /* If the message was successfully received send the data to the upper layer. */
            if (LIN_RX_OK == u8tempReturn)
            {
                *pu8LinSduPtr = (uint8 *)Lin_xSharedMemory.aLinMb[u8HwCtrl];
            }
        }
    }

    return u8tempReturn;
}
#endif /* #if LIN_43_LLCE_MASTER_NODE_USED == STD_ON */

/**
* @internal
* @brief   This function processes notifications from Llce.
* @details This function shall manage all the ISRs from LLCE
*          on the addressed channel.
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return       void.
*
* @note         Internal driver function.
*
* @implements Lin_Llce_ProcessCmdFromLlce_Activity
*
*/
void Lin_Llce_ProcessCmdFromLlce(const uint8 u8HwCtrl)
{
#if (LIN_43_LLCE_SLAVE_NODE_USED == STD_ON)
    uint8  u8LogicCtrl;
#endif /* #if (LIN_43_LLCE_SLAVE_NODE_USED == STD_ON) */
    Llce_Lin_CommandIdType eCmdId;

    /* Check if the driver was initialized */
    if (LIN_43_LLCE_INIT == Lin_u8LinDrvStatus)
    {
        /* Read the command id. */
        eCmdId = Lin_xSharedMemory.Lin_aNotif[u8HwCtrl].eCmdId;
        
#if (LIN_43_LLCE_SLAVE_NODE_USED == STD_ON)
        /* Calculate logic controller index. */
        u8LogicCtrl = Lin_au8Hw2LogicCtrlMap[u8HwCtrl];
#endif /* #if (LIN_43_LLCE_SLAVE_NODE_USED == STD_ON) */

        switch (eCmdId)
        {
            /* Notify the wakeup to LinIf */
            case LLCE_LIN_CMD_WAKEUP_CONFIRMATION:
                Lin_Llce_WakeupConfirmation(u8HwCtrl);
                break;
#if (LIN_43_LLCE_SLAVE_NODE_USED == STD_ON)
            /* Convert the Error reported by FW to ASR types and notify it to LinIf. */
            case LLCE_LIN_CMD_ERROR_INDICATION:
                Lin_Llce_ErrorIndication(u8HwCtrl);
                break;
            /* Send the Header to LinIf and the return the result to the FW. FW will wait for the result. */
            case LLCE_LIN_CMD_HEADER_INDICATION:
                Lin_Llce_HeaderIndication(u8HwCtrl);
                break;
            /* Notify the RX event to LinIf. */
            case LLCE_LIN_CMD_RX_INDICATION:
                LinIf_RxIndication((NetworkHandleType)u8LogicCtrl, (uint8*)Lin_xSharedMemory.aLinMb[u8HwCtrl]);
                break;
            /* Notify the TX event to LinIf. */
            case LLCE_LIN_CMD_TX_CONFIRMATION:
                LinIf_TxConfirmation((NetworkHandleType)u8LogicCtrl);
                break;
#endif /* #if (LIN_43_LLCE_SLAVE_NODE_USED == STD_ON) */
            default:
                /* Unknown command. */
                break;
        }
    }
}

#define LIN_43_LLCE_STOP_SEC_CODE
#include "Lin_43_LLCE_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */

/*==================================================================================================
*   Project              : M4_SRC_PROJECT_NAME
*   Platform             : M4_SRC_MCU_FAMILY
*   Peripheral           : M4_SRC_USED_PERIPHERAL
*   Dependencies         : M4_SRC_AR_MODULE_DEPENDENCY
*
*   Autosar Version      : M4_SRC_AR_SPEC_VERSION_MAJOR.M4_SRC_AR_SPEC_VERSION_MINOR.M4_SRC_AR_SPEC_VERSION_PATCH
*   Autosar Revision     : M4_SRC_AR_RELEASE_REVISION
*   Autosar Conf.Variant :
*   SW Version           : M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
*   Build Version        : M4_SRC_BUILD_ID
*
   (c) Copyright M4_SRC_YEAR_ID M4_SRC_COPYRIGHTED_TO
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
*   @file
*
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
#include "Mcal.h"
#include "Clock_Ip.h"
#include "Linflexd_Lin_Ip.h"
#include "IntCtrl_Ip.h"
#include "Siul2_Port_Ip.h"
#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define LINFLEXD_LIN_INSTANCE        (0U)
#define BUFFER_SIZE                  (3U)
#define T_LIN_TIME_OUT               (400000U)
#define LINFLEX_PID                  (0x1A)
#define MASTER_ROLE                  (0U)
#define SLAVE_ROLE                   (1U)

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
uint8 LinflexdTxBuff[BUFFER_SIZE] = {0x01, 0x02, 0x03};

Linflexd_Lin_Ip_PduType LinflexdPdu[] =
{
    {
                .Pid = (uint8)LINFLEX_PID,
                .Cs = LINFLEXD_LIN_IP_ENHANCED_CS,
                .SduPtr = LinflexdTxBuff,
                .Drc = LINFLEXD_LIN_IP_FRAMERESPONSE_TX,
                .Dl = (uint8)BUFFER_SIZE
    },
    {
                .Pid = (uint8)LINFLEX_PID,
                .Cs = LINFLEXD_LIN_IP_ENHANCED_CS,
                .SduPtr = NULL_PTR,
                .Drc = LINFLEXD_LIN_IP_FRAMERESPONSE_RX,
                .Dl = (uint8)BUFFER_SIZE
    }
};

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
boolean CheckReceiveBuffer(uint8 *OriginalBuffer, uint8 * ReceiveBuffer)
{
    uint8 Index;
    volatile boolean RetVal = TRUE;
    for (Index = 0; Index < BUFFER_SIZE; Index++)
    {
        if (OriginalBuffer[Index] != *(ReceiveBuffer + Index))
        {
            RetVal = FALSE;
        }
    }
    return RetVal;
}

void LinflexdSlaveCallback (uint8 Instance, const Linflexd_Lin_Ip_StateStructType *LinflexdStateStruct)
{
    if (LinflexdStateStruct->CurrentEventId == LINFLEXD_LIN_IP_RECV_HEADER_OK)
    {
        (void)Linflexd_Lin_Ip_SendFrame(Instance, &LinflexdPdu[SLAVE_ROLE]);
    }
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/


/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
    uint8 *RecvBuffer[1];
    uint8 *DummyBuffer;
    uint32 TimeoutValue = 0u;
    volatile boolean LinflexdCheckData;
    volatile Linflexd_Lin_Ip_TransferStatusType LinflexdMasterStatus = LINFLEXD_LIN_IP_STATUS_OPERATIONAL;
    volatile Linflexd_Lin_Ip_TransferStatusType LinflexdSlaveStatus = LINFLEXD_LIN_IP_STATUS_OPERATIONAL;

    /* Clock initialization */
    Clock_Ip_Init(&Mcu_aClockConfigPB[0]);

    /* Interrupts controller initialization */
    IntCtrl_Ip_Init(&IntCtrlConfig_0);

    /* Pins initialization */
    Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

    /* Linflexd over Lin initialization */
    Linflexd_Lin_Ip_Init(Linflexd_Lin_Ip_Sa_pHwConfigPB_0_VS_0.Instance, &Linflexd_Lin_Ip_Sa_pHwConfigPB_0_VS_0);
    Linflexd_Lin_Ip_Init(Linflexd_Lin_Ip_Sa_pHwConfigPB_1_VS_0.Instance, &Linflexd_Lin_Ip_Sa_pHwConfigPB_1_VS_0);

    /* Start of the sending frame */
    (void)Linflexd_Lin_Ip_SendFrame(Linflexd_Lin_Ip_Sa_pHwConfigPB_0_VS_0.Instance, &LinflexdPdu[MASTER_ROLE]);

    /*Wait for the transmission done on Master*/
    TimeoutValue = 4*T_LIN_TIME_OUT;

    do
    {
        LinflexdMasterStatus = Linflexd_Lin_Ip_GetStatus(Linflexd_Lin_Ip_Sa_pHwConfigPB_0_VS_0.Instance, (uint8 **)&DummyBuffer);
    }
    while ((LINFLEXD_LIN_IP_STATUS_TX_OK != LinflexdMasterStatus) && (TimeoutValue-- > 1));
    
    /*Wait for the transmission done on Slave*/
    TimeoutValue = 4*T_LIN_TIME_OUT;
    
    do
    {
        LinflexdSlaveStatus = Linflexd_Lin_Ip_GetStatus(Linflexd_Lin_Ip_Sa_pHwConfigPB_1_VS_0.Instance, (uint8 **)&RecvBuffer[0]);
    }
    while ((LINFLEXD_LIN_IP_STATUS_RX_OK != LinflexdSlaveStatus) && (TimeoutValue-- > 1));
    
    /* Verify Data between Slave node and Master node */
    LinflexdCheckData = CheckReceiveBuffer(LinflexdPdu[MASTER_ROLE].SduPtr, RecvBuffer[0]);
    
    /* Linflexd over Lin driver de-initialization*/
    Linflexd_Lin_Ip_Deinit(Linflexd_Lin_Ip_Sa_pHwConfigPB_0_VS_0.Instance);
    Linflexd_Lin_Ip_Deinit(Linflexd_Lin_Ip_Sa_pHwConfigPB_1_VS_0.Instance);

    /* Check if all the frames have been sent */
    /* Check status */
    Exit_Example(LINFLEXD_LIN_IP_STATUS_TX_OK == LinflexdMasterStatus && LINFLEXD_LIN_IP_STATUS_RX_OK == LinflexdSlaveStatus && \
                 TRUE == LinflexdCheckData);

    return (0U);
}

#ifdef __cplusplus
}
#endif

/** @} */


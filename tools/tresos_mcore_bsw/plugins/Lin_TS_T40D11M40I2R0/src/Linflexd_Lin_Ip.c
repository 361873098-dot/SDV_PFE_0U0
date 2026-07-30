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

/**
*   @file Linflexd_Lin_Ip.c
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

#include "Linflexd_Lin_Ip.h"
#include "SchM_Lin.h"
#include "Soc_Ips.h"
#include "OsIf.h"
#if (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    #include "Devassert.h"
#endif /* (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON) */
#ifdef LINFLEXD_LIN_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE
    #define USER_MODE_REG_PROT_ENABLED      (STD_ON)
    #include "RegLockMacros.h"
#endif /* LINFLEXD_LIN_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE */
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LINFLEXD_LIN_IP_VENDOR_ID_C                      43
#define LINFLEXD_LIN_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define LINFLEXD_LIN_IP_AR_RELEASE_MINOR_VERSION_C       4
#define LINFLEXD_LIN_IP_AR_RELEASE_REVISION_VERSION_C    0
#define LINFLEXD_LIN_IP_SW_MAJOR_VERSION_C               4
#define LINFLEXD_LIN_IP_SW_MINOR_VERSION_C               0
#define LINFLEXD_LIN_IP_SW_PATCH_VERSION_C               2
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#if (LINFLEXD_LIN_IP_VENDOR_ID_C != LINFLEXD_LIN_IP_VENDOR_ID)
    #error "Linflexd_Lin_Ip.c and Linflexd_Lin_Ip.h have different vendor ids"
#endif
/* Check if current file and Linflexd_Lin_Ip header file are of the same Autosar version */
#if ((LINFLEXD_LIN_IP_AR_RELEASE_MAJOR_VERSION_C    != LINFLEXD_LIN_IP_AR_RELEASE_MAJOR_VERSION) || \
     (LINFLEXD_LIN_IP_AR_RELEASE_MINOR_VERSION_C    != LINFLEXD_LIN_IP_AR_RELEASE_MINOR_VERSION) || \
     (LINFLEXD_LIN_IP_AR_RELEASE_REVISION_VERSION_C != LINFLEXD_LIN_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Linflexd_Lin_Ip.c and Linflexd_Lin_Ip.h are different"
#endif
/* Check if current file and Linflexd_Lin_Ip header file are of the same Software version */
#if ((LINFLEXD_LIN_IP_SW_MAJOR_VERSION_C != LINFLEXD_LIN_IP_SW_MAJOR_VERSION) || \
     (LINFLEXD_LIN_IP_SW_MINOR_VERSION_C != LINFLEXD_LIN_IP_SW_MINOR_VERSION) || \
     (LINFLEXD_LIN_IP_SW_PATCH_VERSION_C != LINFLEXD_LIN_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Linflexd_Lin_Ip.c and Linflexd_Lin_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and SchM_Lin.h header file are of the same Autosar version */
    #if ((LINFLEXD_LIN_IP_AR_RELEASE_MAJOR_VERSION_C != SCHM_LIN_AR_RELEASE_MAJOR_VERSION) || \
         (LINFLEXD_LIN_IP_AR_RELEASE_MINOR_VERSION_C != SCHM_LIN_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Linflexd_Lin_Ip.h and SchM_Lin.h are different"
    #endif
    /* Check if current file and Soc_Ips.h header file are of the same Autosar version */
    #if ((LINFLEXD_LIN_IP_AR_RELEASE_MAJOR_VERSION_C != SOC_IPS_AR_RELEASE_MAJOR_VERSION) || \
         (LINFLEXD_LIN_IP_AR_RELEASE_MINOR_VERSION_C !=  SOC_IPS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Linflexd_Lin_Ip.h and Soc_Ips.h are different"
    #endif

    /* Check if current file and OsIf.h header file are of the same Autosar version */
    #if ((LINFLEXD_LIN_IP_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (LINFLEXD_LIN_IP_AR_RELEASE_MINOR_VERSION_C !=  OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Linflexd_Lin_Ip.h and OsIf.h are different"
    #endif

    #ifdef LINFLEXD_LIN_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE
        /* Check if current file and RegLockMacros.h header file are of the same Autosar version */
        #if ((LINFLEXD_LIN_IP_AR_RELEASE_MAJOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
             (LINFLEXD_LIN_IP_AR_RELEASE_MINOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of Linflexd_Lin_Ip.h and RegLockMacros.h are different"
        #endif
    #endif /* LINFLEXD_LIN_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE */

    #if (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON)
        /* Check if current file and Devassert.h header file are of the same Autosar version */
        #if ((LINFLEXD_LIN_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
             (LINFLEXD_LIN_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of Linflexd_Lin_Ip.h and Devassert.h are different"
        #endif
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#define LINFLEXD_LIN_IP_MAX_DATA_LENGTH                     ((uint8)8UL)
/* Sleep mode */
#define LINFLEXD_LIN_IP_LINSR_SLEEP_MODE_U32                ((uint32)0UL)
/* Init mode */
#define LINFLEXD_LIN_IP_LINSR_INIT_MODE_U32                 ((uint32)1UL)
/* Idle mode */
#define LINFLEXD_LIN_IP_LINSR_IDLE_MODE_U32                 ((uint32)2UL)
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
#define LIN_START_SEC_CONST_UNSPECIFIED
#include "Lin_MemMap.h"
/* Table of base addresses for LINFLEXD instances. */
LINFLEXD_Type * const Linflexd_Lin_Ip_apxBases[LINFLEXD_INSTANCE_COUNT] = IP_LINFLEXD_BASE_PTRS;

#define LIN_STOP_SEC_CONST_UNSPECIFIED
#include "Lin_MemMap.h"

#define LIN_START_SEC_VAR_CLEARED_8
#include "Lin_MemMap.h"

static uint8 Linflexd_Lin_Ip_au8SduBuffer[LINFLEXD_INSTANCE_COUNT][LINFLEXD_LIN_IP_MAX_DATA_LENGTH];

#define LIN_STOP_SEC_VAR_CLEARED_8
#include "Lin_MemMap.h"
 
#define LIN_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Lin_MemMap.h"

static Linflexd_Lin_Ip_PduType Linflexd_Lin_Ip_anPduInfo[LINFLEXD_INSTANCE_COUNT];

Linflexd_Lin_Ip_StateStructType Linflexd_Lin_Ip_axStateStructure[LINFLEXD_INSTANCE_COUNT];

/* Table to save LIN user config structure pointers */
static const Linflexd_Lin_Ip_UserConfigType *Linflexd_Lin_Ip_apUserConfigs[LINFLEXD_INSTANCE_COUNT];

static Linflexd_Lin_Ip_StateStructType *Linflexd_Lin_Ip_apxStateStructureArray[LINFLEXD_INSTANCE_COUNT];

#define LIN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Lin_MemMap.h"

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"

static void Linflexd_Lin_Ip_CopyData(const uint32 Instance, uint8* Buffer);
static uint8 Linflexd_Lin_Ip_CalculatePid(uint32 ReceptFrameID);
static void Linflexd_Lin_Ip_UpdateCurrentNodeState(const uint32 Instance);
static void Linflexd_Lin_Ip_CompleteTransfer(const uint32 Instance, uint32 StatusFlag);
static void Linflexd_Lin_Ip_ErrorsHandler(const uint32 Instance, uint32 ErrorFlag);
static boolean Linflexd_Lin_Ip_ReceiveErrorsHandler(const uint32 Instance, uint32 ErrorFlag);
static Linflexd_Lin_Ip_TransferStatusType Linflexd_Lin_Ip_GetNoEventStatus(const uint8 Instance);
static Linflexd_Lin_Ip_TransferStatusType Linflexd_Lin_Ip_GetTimeoutErrorStatus(const uint8 Instance);
static void Linflexd_Lin_Ip_StartTimeout(uint32 *StartTimeOut, uint32 *TimeoutTicksOut, uint32 TimeoutUs, OsIf_CounterType OsifCounter);
static boolean Linflexd_Lin_Ip_TimeoutExpired(uint32 * StartTime, uint32 * ElapsedTicks, uint32 TimeoutTicks, OsIf_CounterType OsifCounter);
static Linflexd_Lin_Ip_StatusType Linflexd_Lin_Ip_StateTimeoutMode(const uint8 Instance, uint32 TestFlag);
static void Linflexd_Lin_Ip_SetUpRegisterInInitMode(const uint8 Instance);
static void Linflexd_Lin_Ip_SetUpRegisterInNormalMode(const uint8 Instance);
#ifdef LINFLEXD_LIN_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE
void Linflexd_Lin_Ip_SetUserAccess(const uint8 Instance);
static void Linflexd_Lin_Ip_SetUserAccessAllowed(const uint8 Instance);
#endif /* LINFLEXD_LIN_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE */
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Lin_Ip_StartTimeout
 * Description   : Checks for timeout condition
 *
 *END**************************************************************************/
static void Linflexd_Lin_Ip_StartTimeout(uint32 *StartTimeOut, uint32 *TimeoutTicksOut, uint32 TimeoutUs, OsIf_CounterType OsifCounter)
{
    *StartTimeOut    = OsIf_GetCounter(OsifCounter);
    *TimeoutTicksOut = OsIf_MicrosToTicks(TimeoutUs, OsifCounter);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Lin_Ip_TimeoutExpired
 * Description   : Checks for timeout expiration condition
 *
 *END**************************************************************************/
static boolean Linflexd_Lin_Ip_TimeoutExpired(uint32 * StartTime, uint32 * ElapsedTicks, uint32 TimeoutTicks, OsIf_CounterType OsifCounter)
{
    uint32 CurrentElapsedTicks = OsIf_GetElapsed(StartTime, OsifCounter);
    *ElapsedTicks += CurrentElapsedTicks;
    return ((*ElapsedTicks >= TimeoutTicks) ? TRUE : FALSE);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Lin_Ip_StateTimeoutMode
 * Description   : Checks the Lin hardware state and compares it with the flag parameter.
 *
 *END**************************************************************************/
static Linflexd_Lin_Ip_StatusType Linflexd_Lin_Ip_StateTimeoutMode(const uint8 Instance, uint32 TestFlag)
{
    uint32 StartTime;
    uint32 TimeoutTicks;
    uint32 ElapsedTicks = 0;
    const LINFLEXD_Type *Base;
    Linflexd_Lin_Ip_StatusType RetVal = LINFLEXD_LIN_IP_STATUS_TIMEOUT;
    
    /* Get base value */
    Base = (const LINFLEXD_Type *)Linflexd_Lin_Ip_apxBases[Instance];
    Linflexd_Lin_Ip_StartTimeout(&StartTime, &TimeoutTicks, LINFLEXD_LIN_IP_TIMEOUT_VALUE_US, LINFLEXD_LIN_IP_TIMEOUT_TYPE);
    do
    {
        /* Check LIN State */
        if (TestFlag == ((Base->LINSR & LINFLEXD_LINSR_LINS_MASK) >>LINFLEXD_LINSR_LINS_SHIFT))
        {
            RetVal = LINFLEXD_LIN_IP_STATUS_SUCCESS;
            break;
        }
    }
    while (!Linflexd_Lin_Ip_TimeoutExpired(&StartTime, &ElapsedTicks, TimeoutTicks, LINFLEXD_LIN_IP_TIMEOUT_TYPE));
    
    return RetVal;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Lin_Ip_SetUpRegisterInInitMode
 * Description   : In Init mode, configure some registers for the Init function.
 *
 *END**************************************************************************/
static void Linflexd_Lin_Ip_SetUpRegisterInInitMode(const uint8 Instance)
{
    LINFLEXD_Type *Base;
    uint32 RegValue = 0;
    const Linflexd_Lin_Ip_UserConfigType *LinUserConfig;
    
     /* Get base address of the LINFLEXD Instance. */
    Base = Linflexd_Lin_Ip_apxBases[Instance];
    /* Get the current LIN user config structure of this LINFLEXD Instance. */
    LinUserConfig = Linflexd_Lin_Ip_apUserConfigs[Instance];
    
    /* Set to LIN mode */
    Base->UARTCR &= ~LINFLEXD_UARTCR_UART(1);
    
    /* Configure number of stop bits */
    Base->GCR &= ~LINFLEXD_GCR_STOP(1);
    Base->GCR |= LINFLEXD_GCR_STOP(LinUserConfig->StopBitsCount);
    
    RegValue = Base->LINCR1;
    /************************************************
    * Configurate Lin Control 1 register:
    *  - Lin state capture is enabled on Bit Error
    *  - Disable auto wake-up
    *  - Disable loop back mode
    *  - Receiver buffer not locked mode
    *  - Checksum filed is enabled
    ************************************************/
    
    /* Lin state captured whenever bit error occurred */
    RegValue |= LINFLEXD_LINCR1_NLSE(1);
    /* Checksum field send by hardware */
    /* Disable auto wake-up */
    /* Loop back mode disabled */
    /* Receiver buffer not locked */
    /* Exit sleep mode */
    RegValue &= ( (~LINFLEXD_LINCR1_CFD(1)) \
                & (~LINFLEXD_LINCR1_AUTOWU(1)) \
                & (~LINFLEXD_LINCR1_LBKM(1)) \
                & (~LINFLEXD_LINCR1_RBLM(1)) \
                );
    
    /* Clear master break length */
    RegValue &= ~((uint32)LINFLEXD_LINCR1_MBL_MASK);
    
    /* Select mode and set break length */
    if ((boolean)LINFLEXD_LIN_IP_MASTER == LinUserConfig->NodeFunction)
    {
        /* Set node to master mode */
        RegValue |= LINFLEXD_LINCR1_MME(1);
        /* Set break length of master */
        RegValue |= LINFLEXD_LINCR1_MBL(LinUserConfig->BreakLength);
    }
    else
    {
        /* Set node to slave mode */
        RegValue &= ~LINFLEXD_LINCR1_MME(1);
        /* Set sync break length */
        RegValue &= ~((uint32)LINFLEXD_LINCR1_SSBL_MASK);
        RegValue |= LINFLEXD_LINCR1_SSBL(LinUserConfig->SlaveSyncBreakLength);
    }
    
    /* Configure Calculate checksum disable */
    RegValue &= ~LINFLEXD_LINCR1_CCD(1);
    RegValue |= LINFLEXD_LINCR1_CCD(LinUserConfig->CsCalDisable);
    /* Set LINCR1 register */
    Base->LINCR1 = RegValue;
    
    /* Configure baudrate */
    Base->LINFBRR = LINFLEXD_LINFBRR_FBR(LinUserConfig->BaudrateRegValue);
    Base->LINIBRR = LINFLEXD_LINIBRR_IBR(LinUserConfig->BaudrateRegValue >> 8);
    
    #if (LINFLEXD_LIN_IP_DISABLE_FRAME_TIMEOUT == STD_ON)
        /* Output compare mode */
        /* Disable timeout counter for both slave and master */
        Base->LINTCSR |= LINFLEXD_LINTCSR_MODE_MASK;
    
        /* @errata ERR_IPV_LINFLEXD_E007274 */
        #ifdef ERR_IPV_LINFLEXD_E007274
            /* In errata case, for Slave mode, enable timeout */
            if ((boolean)LINFLEXD_LIN_IP_SLAVE == LinUserConfig->NodeFunction)
            {
                /* LIN mode -  Timeout counter is controlled by hardware */
                /* Does not reset state machine to idle on timeout, it will move to idle in timeout interrupt handler to backup LINS state. */
                Base->LINTCSR &= ((~LINFLEXD_LINTCSR_MODE_MASK) & (~LINFLEXD_LINTCSR_IOT_MASK));
            }
        #endif /* ifdef ERR_IPV_LINFLEXD_E007274 */
    #else /* (LINFLEXD_LIN_IP_DISABLE_FRAME_TIMEOUT == STD_OFF) */
    
        /* LIN mode -  Timeout counter is controlled by hardware */
        /* Enable timeout for both Master and Slave regardless the errata */
        /* Does not reset state machine to idle on timeout, it will move to idle in timeout interrupt handler to backup LINS state. */
        Base->LINTCSR &= ((~LINFLEXD_LINTCSR_MODE_MASK) & (~LINFLEXD_LINTCSR_IOT_MASK));
    #endif
    
    Base->LINTOCR = LINFLEXD_LINTOCR_RTO(LinUserConfig->ResponseTimeout);
    
    if ((boolean)LINFLEXD_LIN_IP_MASTER != LinUserConfig->NodeFunction)
    {
        /* Config header timeout value - HTO field is cleared to zero in previous RTO configuration */
        Base->LINTOCR |= LINFLEXD_LINTOCR_HTO(LinUserConfig->HeaderTimeout);
    }
    
    /*************************************************
    * Configure Lin control 2:
    *  - Delimiter length in break field is 2 bits
    *  - Bit Error does not reset LIN state machine
    *  - Parity Error does not reset LIN state machine
    ***************************************************/
    RegValue = Base->LINCR2;
    RegValue |= LINFLEXD_LINCR2_TBDE(1);
    RegValue &= ((~LINFLEXD_LINCR2_IOBE(1)) & (~LINFLEXD_LINCR2_IOPE(1)) );
    /* Set LINCR2 register */
    Base->LINCR2 = RegValue;    
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Lin_Ip_SetUpRegisterInNormalMode
 * Description   : In Normal mode, configure some registers for the Init function.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static void Linflexd_Lin_Ip_SetUpRegisterInNormalMode(const uint8 Instance)
{
    LINFLEXD_Type *Base;
    uint32 RegValue = 0;
    const Linflexd_Lin_Ip_UserConfigType *LinUserConfig;
    
     /* Get base address of the LINFLEXD Instance. */
    Base = Linflexd_Lin_Ip_apxBases[Instance];
    /* Get the current LIN user config structure of this LINFLEXD Instance. */
    LinUserConfig = Linflexd_Lin_Ip_apUserConfigs[Instance];
    
    /**************************************************
    * Configure error interrupt enable/disable
    **************************************************/
    RegValue = Base->LINIER;
    /* Enable error interrupts */
    /* Enable bit error interrupt */
    /* Enable checksum error interrupt */
    /* Enable frame error interrupt */
    /* Enable buffer overrun error interrupt */
    RegValue |= ( LINFLEXD_LINIER_BEIE(1) \
                | LINFLEXD_LINIER_CEIE(1) \
                | LINFLEXD_LINIER_FEIE(1) \
                | LINFLEXD_LINIER_BOIE(1) \
                );
    
    /*********************************
    * Configure other interrupts
    **********************************/
    /* Enable data reception complete interrupt */
    /* Enable data transmitted interrupt */
    RegValue |= ( LINFLEXD_LINIER_DRIE(1) \
                | LINFLEXD_LINIER_DTIE(1) \
                );
    /* Disable stuck at zero interrupt */
    /* Disable lin state interrupt */
    /* Disable wake-up interrupt */
    /* Disable timeout interrupt for uart mode */
    RegValue &= ( (~LINFLEXD_LINIER_SZIE(1)) \
                & (~LINFLEXD_LINIER_LSIE(1)) \
                & (~LINFLEXD_LINIER_WUIE(1)) \
                & (~LINFLEXD_LINIER_TOIE(1)) \
                );
    
    if ((boolean)LINFLEXD_LIN_IP_MASTER == LinUserConfig->NodeFunction)
    {
        /* Disable header received interrupt */
        RegValue &= ~LINFLEXD_LINIER_HRIE(1);
        /* Disable header error interrupt */
        RegValue &= ~LINFLEXD_LINIER_HEIE(1);
    }
    else
    {
        /* Enable header received interrupt */
        RegValue |= LINFLEXD_LINIER_HRIE(1);
        /* Enable header error interrupt */
        RegValue |= LINFLEXD_LINIER_HEIE(1);
    }

#if (LINFLEXD_LIN_IP_DISABLE_FRAME_TIMEOUT == STD_ON)
    /* Disable output compare interrupt */
    RegValue &= (~LINFLEXD_LINIER_OCIE_MASK);
    
    /* @errata ERR_IPV_LINFLEXD_E007274 */
    #ifdef ERR_IPV_LINFLEXD_E007274
        /* In case errata is available, enable this interrupt bit only for Slave */
        if ((boolean)LINFLEXD_LIN_IP_SLAVE == LinUserConfig->NodeFunction)
        {
            /* Enable output compare interrupt */
            RegValue |= LINFLEXD_LINIER_OCIE_MASK;
        }
    #endif
#else
    /* Enable output compare interrupt */
    RegValue |= LINFLEXD_LINIER_OCIE_MASK;
#endif /* (LINFLEXD_LIN_IP_DISABLE_FRAME_TIMEOUT == STD_ON) */
    
    Base->LINIER = RegValue;    
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Lin_Ip_GetTimeoutErrorStatus
 * Description   : This function returns the status of the current timeout during receive header or data.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
 static Linflexd_Lin_Ip_TransferStatusType Linflexd_Lin_Ip_GetTimeoutErrorStatus(const uint8 Instance)
 {
    Linflexd_Lin_Ip_TransferStatusType  RetVal = LINFLEXD_LIN_IP_STATUS_FAIL;
    const Linflexd_Lin_Ip_StateStructType *LinCurrentState;

    /* Get the current LIN state of this LINFLEXD instance. */
    LinCurrentState = (const Linflexd_Lin_Ip_StateStructType *)Linflexd_Lin_Ip_apxStateStructureArray[Instance];
    switch ((LinCurrentState->LinState & LINFLEXD_LINSR_LINS_MASK) >> LINFLEXD_LINSR_LINS_SHIFT)
    {
        case LINFLEXD_LIN_IP_LINS_SYNC_BREAK_U8:
            /* Fall-through */
        case LINFLEXD_LIN_IP_LINS_SYNC_DEL_U8:
            /* Fall-through */
        case LINFLEXD_LIN_IP_LINS_SYNC_FIELD_U8:
            /* header is receiving */
            RetVal = LINFLEXD_LIN_IP_STATUS_RX_HEADER_ERROR;
            break;
        case LINFLEXD_LIN_IP_LINS_IDENTIFIER_FIELD_U8:
            /* Fall-through */
        case LINFLEXD_LIN_IP_LINS_HEADER_RECEPT_TRANS_U8:
            /* Fall-through */
        case LINFLEXD_LIN_IP_LINS_DATA_RECEPT_TRANS_U8:
            /* Fall-through */
        case LINFLEXD_LIN_IP_LINS_CHECKSUM_U8:
            /* response is ongoing receive */
            if (0u != (LinCurrentState->LinState & LINFLEXD_LINSR_DRBNE_MASK))
            {
                RetVal = LINFLEXD_LIN_IP_STATUS_RX_ERROR;
            }
            else
            {
                RetVal = LINFLEXD_LIN_IP_STATUS_RX_NO_RESPONSE;
            }
            break;
        default:
            /* will not jump here */
            break;
    }
    return RetVal;
 }
/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Lin_Ip_GetNoEventStatus
 * Description   : This function returns the status of the current wakeup signal.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
 static Linflexd_Lin_Ip_TransferStatusType Linflexd_Lin_Ip_GetNoEventStatus(const uint8 Instance)
 {
    Linflexd_Lin_Ip_TransferStatusType  RetVal = LINFLEXD_LIN_IP_STATUS_FAIL;
    const Linflexd_Lin_Ip_StateStructType *LinCurrentState;
    const LINFLEXD_Type *Base;
    uint32 Linsr = 0u;
    Linflexd_Lin_Ip_NodeStateType CurrentNodeState;

    /* Get the current LIN state of this LINFLEXD instance. */
    LinCurrentState = (const Linflexd_Lin_Ip_StateStructType *)Linflexd_Lin_Ip_apxStateStructureArray[Instance];
    /* Get base value */
    Base = (const LINFLEXD_Type *)Linflexd_Lin_Ip_apxBases[Instance];
    /* Get hardware status */
    Linsr = Base->LINSR;
    CurrentNodeState = LinCurrentState->CurrentNodeState;

    /* check node state in sleep or not */
    switch (CurrentNodeState)
    {
        case LINFLEXD_LIN_IP_NODE_STATE_SLEEP_MODE:
            RetVal = LINFLEXD_LIN_IP_STATUS_SLEEP;
            break;
        case LINFLEXD_LIN_IP_NODE_STATE_IDLE:
            switch (LinCurrentState->FrameCommand)
            {
                case LINFLEXD_LIN_IP_TX_NO_COMMAND:
                    RetVal = LINFLEXD_LIN_IP_STATUS_OPERATIONAL;
                    break;
                case LINFLEXD_LIN_IP_TX_SLAVE_TO_SLAVE_COMMAND:
                    RetVal = LINFLEXD_LIN_IP_STATUS_TX_OK;
                    break;
                default:
                    /* Do nothing.
                    In the case of other command, if LINS moved to Idle after errors occurred: it is already covered by upper level.
                    */
                    break;
            }
            break;
        case LINFLEXD_LIN_IP_NODE_STATE_SEND_HEADER:
            RetVal = LINFLEXD_LIN_IP_STATUS_TX_BUSY;
            break;
        case LINFLEXD_LIN_IP_NODE_STATE_RECV_HEADER:
            RetVal = LINFLEXD_LIN_IP_STATUS_RX_HEADER_BUSY;
            break;
        case LINFLEXD_LIN_IP_NODE_STATE_RECV_DATA:
            if (0u != (Linsr & LINFLEXD_LINSR_DRBNE_MASK))
            {
                RetVal = LINFLEXD_LIN_IP_STATUS_RX_BUSY;
            }
            else
            {
                RetVal = LINFLEXD_LIN_IP_STATUS_RX_NO_RESPONSE;
            }
            break;
        case LINFLEXD_LIN_IP_NODE_STATE_SEND_DATA:
            RetVal = LINFLEXD_LIN_IP_STATUS_TX_BUSY;
            break;
        default:
            /* will not jump here */
            break;
    }

    return RetVal;
 }
/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Lin_Ip_ReceiveErrorsHandler
 * Description   : This function will handler to errors like as: overrun, checksum, frame, timeout.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
 static boolean Linflexd_Lin_Ip_ReceiveErrorsHandler(const uint32 Instance, uint32 ErrorFlag)
 {
    LINFLEXD_Type *Base;
    Linflexd_Lin_Ip_StateStructType *LinCurrentState;
    boolean IsErrorAvailable = TRUE;
    #if ((LINFLEXD_LIN_IP_DISABLE_FRAME_TIMEOUT == STD_ON) && (defined ERR_IPV_LINFLEXD_E007274))
    const Linflexd_Lin_Ip_UserConfigType *LinUserConfig = Linflexd_Lin_Ip_apUserConfigs[Instance];
    #endif

    /* Get the current LIN state of this LINFLEXD Instance. */
    LinCurrentState = Linflexd_Lin_Ip_apxStateStructureArray[Instance];
    /* Get base address of the LINFLEXD Instance. */
    Base = Linflexd_Lin_Ip_apxBases[Instance];
    if (0UL != (ErrorFlag & (uint32)LINFLEXD_LINESR_BOF_MASK))
    {
        /* Write 1 to clear overrun flag */
        Base->LINESR = LINFLEXD_LINESR_BOF(1);
        LinCurrentState->CurrentEventId = LINFLEXD_LIN_IP_OVERRUN_ERROR;
    }
    /* If checksum error occurred */
    else if (0UL != (ErrorFlag & (uint32)LINFLEXD_LINESR_CEF_MASK))
    {
        /* Write 1 to clear checksum error flag */
        Base->LINESR = LINFLEXD_LINESR_CEF(1);
        /* Set Event Id */
        LinCurrentState->CurrentEventId = LINFLEXD_LIN_IP_CHECKSUM_ERROR;
    }
    /* If frame error occurred */
    else if (0UL != (ErrorFlag & (uint32)LINFLEXD_LINESR_FEF_MASK))
    {
        /* Write 1 to clear frame error flag */
        Base->LINESR = LINFLEXD_LINESR_FEF(1);
        /* Set Event Id */
        LinCurrentState->CurrentEventId = LINFLEXD_LIN_IP_FRAME_ERROR;
        /* Clear data reception buffer not empty flag */
        Base->LINSR = LINFLEXD_LINSR_DRBNE(1);
    }
    /* If timeout error occurred */
    else if (0UL != (ErrorFlag & (uint32)LINFLEXD_LINESR_OCF_MASK))
    {
        /* Write 1 to clear frame error flag */
        Base->LINESR = LINFLEXD_LINESR_OCF(1);
        /* Store LINSR for further process */
        LinCurrentState->LinState = Base->LINSR;
        /* LINCR2[DDRQ] bit should not be used because it is not working correctly when timeout occurred and there is no any data byte received.
        Actually, after DDRQ set and lead to LINS moved to Idle but DDRQ will not clear. This problem will be raised to HW team to clarify.
        To move to Idle mode and stop current frame, move LINFLEXD to SLEEP and switch back as an workaround. */
        Base->LINCR1 |= LINFLEXD_LINCR1_SLEEP_MASK;
        Base->LINCR1 &= ~LINFLEXD_LINCR1_SLEEP_MASK;

        #if (LINFLEXD_LIN_IP_DISABLE_FRAME_TIMEOUT == STD_OFF)
        /* Set Event Id */
        LinCurrentState->CurrentEventId = LINFLEXD_LIN_IP_TIMEOUT_ERROR;
        #else
            /* @errata ERR_IPV_LINFLEXD_E007274 */
            #ifdef ERR_IPV_LINFLEXD_E007274
                /*In case Errata is available, the slave timeout is enabled regardless the LINFLEXD_LIN_IP_DISABLE_FRAME_TIMEOUT value*/
                if ((boolean)LINFLEXD_LIN_IP_SLAVE == LinUserConfig->NodeFunction)
                {
                    /* Set Event Id */
                    LinCurrentState->CurrentEventId = LINFLEXD_LIN_IP_TIMEOUT_ERROR;
                }
            #endif
        #endif /* (LINFLEXD_LIN_IP_DISABLE_FRAME_TIMEOUT == STD_OFF) */
    }
    else
    {
        /* Don't clear error flag in spurious anymore, report error status */
        IsErrorAvailable = FALSE;
    }

    return IsErrorAvailable;
 }
/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Lin_Ip_ErrorsHandler
 * Description   : This function will handler to errors
 * like as: bit, checksum, frame, timeout, Sync Delimiter, Sync Field, ID Parity, overrun.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
 static void Linflexd_Lin_Ip_ErrorsHandler(const uint32 Instance, uint32 ErrorFlag)
 {
    LINFLEXD_Type *Base;
    Linflexd_Lin_Ip_StateStructType *LinCurrentState;
    boolean IsErrorAvailable = TRUE;
    const Linflexd_Lin_Ip_UserConfigType *LinUserConfig = Linflexd_Lin_Ip_apUserConfigs[Instance];

    /* Get the current LIN state of this LINFLEXD Instance. */
    LinCurrentState = Linflexd_Lin_Ip_apxStateStructureArray[Instance];
    /* Get base address of the LINFLEXD Instance. */
    Base = Linflexd_Lin_Ip_apxBases[Instance];
    /* Sync Delimiter Error Flag */
    if (0UL != (ErrorFlag & (uint32)LINFLEXD_LINESR_SDEF_MASK))
    {
        /* Write 1 to clear Sync Delimiter Error Flag */
        Base->LINESR = LINFLEXD_LINESR_SDEF(1);
        LinCurrentState->CurrentEventId = LINFLEXD_LIN_IP_HEADER_RECEPT_ERROR;
    }
    /* Sync Field Error Flag */
    else if (0UL != (ErrorFlag & (uint32)LINFLEXD_LINESR_SFEF_MASK))
    {
        /* Write 1 to clear Sync Field Error Flag */
        Base->LINESR = LINFLEXD_LINESR_SFEF(1);
        LinCurrentState->CurrentEventId = LINFLEXD_LIN_IP_HEADER_RECEPT_ERROR;
    }
    /* ID Parity Error Flag */
    else if (0UL != (ErrorFlag & (uint32)LINFLEXD_LINESR_IDPEF_MASK))
    {
        /* Write 1 to clear Sync Field Error Flag */
        Base->LINESR = LINFLEXD_LINESR_IDPEF(1);
        LinCurrentState->CurrentEventId = LINFLEXD_LIN_IP_HEADER_RECEPT_ERROR;
    }
    /* If bit error occurred */
    else if (0UL != (ErrorFlag & (uint32)LINFLEXD_LINESR_BEF_MASK))
    {
        /* Write 1 to clear bit error flag */
        Base->LINESR = LINFLEXD_LINESR_BEF(1);
        /* Set Event Id */
        LinCurrentState->CurrentEventId = LINFLEXD_LIN_IP_READBACK_ERROR;
        /* Abort request */
        Base->LINCR2 |= LINFLEXD_LINCR2_ABRQ(1);
    }
    else
    {
        /*This function will handler to errors like as: overrun, checksum, frame, timeout. To avoid His_Level volatile */
        IsErrorAvailable = Linflexd_Lin_Ip_ReceiveErrorsHandler(Instance, ErrorFlag);
    }

    /* Call callback function to report error */
    if (FALSE != IsErrorAvailable)
    {
        /* Update bus state */
        LinCurrentState->IsBusBusy = FALSE;

        if (NULL_PTR != LinUserConfig->Callback)
        {
            LinUserConfig->Callback(Instance, LinCurrentState);
        }
    }
 }
/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Lin_Ip_CompleteTransfer
 * Description   : This function will handler to Transmit/receive by completing the process of Transmitting/receiving data.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
 static void Linflexd_Lin_Ip_CompleteTransfer(const uint32 Instance, uint32 StatusFlag)
 {
    LINFLEXD_Type *Base;
    Linflexd_Lin_Ip_StateStructType *LinCurrentState;
    const Linflexd_Lin_Ip_UserConfigType * LinUserConfig;

    /* Get the current LIN state of this LINFLEXD Instance. */
    LinCurrentState = Linflexd_Lin_Ip_apxStateStructureArray[Instance];
    /* Get base address of the LINFLEXD Instance. */
    Base = Linflexd_Lin_Ip_apxBases[Instance];
    /* Get user configuration */
    LinUserConfig = Linflexd_Lin_Ip_apUserConfigs[Instance];

       /* if data reception completed */
    if (0u != (StatusFlag & LINFLEXD_LINSR_DRF_MASK))
    {
        /* Write 1 to clear data reception completed flag */
        Base->LINSR = LINFLEXD_LINSR_DRF(1);
        /* Set current event to data reception completed */
        LinCurrentState->CurrentEventId = LINFLEXD_LIN_IP_RX_COMPLETED;
        /* Set state of Lin node to reception data completed */
        LinCurrentState->CurrentNodeState = LINFLEXD_LIN_IP_NODE_STATE_RECV_DATA_COMPLETED;
        /* Update bus state */
        LinCurrentState->IsBusBusy = FALSE;

        if ((boolean)LINFLEXD_LIN_IP_MASTER != LinUserConfig->NodeFunction)
        {
            /* Copy data */
            Linflexd_Lin_Ip_CopyData(Instance, LinCurrentState->SlavePduInfoPtr->SduPtr);
        }

        if (NULL_PTR != LinUserConfig->Callback)
        {
            LinUserConfig->Callback(Instance, LinCurrentState);
        }

        /* Check noise error */
        if (0UL != (Base->LINESR & LINFLEXD_LINESR_NF_MASK))
        {
            /* Write 1 to clear noise flag */
            Base->LINESR = LINFLEXD_LINESR_NF(1);
        }
    }
    /* if data transmission completed */
    else if (0u != (StatusFlag & LINFLEXD_LINSR_DTF_MASK))
    {
        /* Write 1 to clear data transmission completed flag */
        Base->LINSR = LINFLEXD_LINSR_DTF(1);
        /* Set current event to data transmission completed */
        LinCurrentState->CurrentEventId = LINFLEXD_LIN_IP_TX_COMPLETED;
        /* Set state of Lin node to transmission data completed */
        LinCurrentState->CurrentNodeState = LINFLEXD_LIN_IP_NODE_STATE_SEND_DATA_COMPLETED;
        /* Update bus state */
        LinCurrentState->IsBusBusy = FALSE;

        if (NULL_PTR != LinUserConfig->Callback)
        {
            LinUserConfig->Callback(Instance, LinCurrentState);
        }
    }
    else
    {
        /* Error condition - do nothing */
    }
 }

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Lin_Ip_CopyData
 * Description   : This function copys data from buffer registers to instance buffer.
 *
 *END**************************************************************************/
static void Linflexd_Lin_Ip_CopyData(const uint32 Instance, uint8* Buffer)
{
    uint8 DataLength;
    uint8 Loop;
    LINFLEXD_Type *Base = Linflexd_Lin_Ip_apxBases[Instance];

    DataLength = (uint8)((Base->BIDR & LINFLEXD_BIDR_DFL_MASK) >> LINFLEXD_BIDR_DFL_SHIFT) + 1u;

    /* Data Length Calculation */
    if (DataLength < 5U)
    {
        for (Loop = (uint8)0U; Loop < DataLength; Loop++)
        {
            Buffer[Loop] = (uint8)((Base->BDRL >> (Loop * 8u)) & LINFLEXD_BDRL_DATA0_MASK);
        }
    }

    if (DataLength > 4U)
    {
        for (Loop = 0U; Loop < 4U; Loop++)
        {
            /* Copy LSB data received in LinSdu[] buffer */
            Buffer[Loop] = (uint8)((Base->BDRL >> (Loop * 8u)) & LINFLEXD_BDRL_DATA0_MASK);
        }

        for (Loop = 4U; Loop < DataLength; Loop++)
        {
            /* Copy MSB data received in LinSdu[] buffer */
            Buffer[Loop] = (uint8)((Base->BDRM >> ((Loop - 4u) * 8u)) & LINFLEXD_BDRM_DATA4_MASK);
        }
    }

    /* Release Message Buffer */
    Base->LINSR = LINFLEXD_LINSR_RMB(1);
    /* Clear reception buffer not empty flag */
    Base->LINSR = LINFLEXD_LINSR_DRBNE(1);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Lin_Ip_CalculatePid
 * Description   : This function calculates Protected Identifier(PID) from the Frame ID.
 *
 *END**************************************************************************/
static uint8 Linflexd_Lin_Ip_CalculatePid(uint32 ReceptFrameID)
{
    uint32 Temp1;
    uint32 Temp2;

    Temp1 = ReceptFrameID;
    Temp2 = ReceptFrameID;

    /* Calculate parity bit P1 = !(ID1 ^ ID3 ^ ID4 ^ ID5) */
    Temp1 |= ( (~((Temp2 >> 1) ^ (Temp2 >> 3) ^ (Temp2 >> 4) ^ (Temp2 >> 5))) \
                  & ((uint32)1U) \
                ) << (uint32)7U;

    /* Calculate parity bit P0 = (ID0 ^ ID1 ^ ID2 ^ ID4) */
    Temp1 |= ( ( (Temp2) ^ (Temp2 >> 1U) ^ (Temp2 >> 2U) ^ (Temp2 >> 4U) ) \
                  & ((uint32)1U) \
                ) << (uint32)6U;

    return (uint8)Temp1;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Lin_Ip_UpdateCurrentNodeState
 * Description   : This function will capture lin state (LINSR[LINS]) to update
 * current node state.
 *
 *END**************************************************************************/
static void Linflexd_Lin_Ip_UpdateCurrentNodeState(const uint32 Instance)
{
    uint8 LinState;
    const LINFLEXD_Type *Base = (const LINFLEXD_Type *)Linflexd_Lin_Ip_apxBases[Instance];
    Linflexd_Lin_Ip_StateStructType *LinCurrentState = Linflexd_Lin_Ip_apxStateStructureArray[Instance];

    /* Get status */
    LinState = (uint8)((Base->LINSR & LINFLEXD_LINSR_LINS_MASK) >> LINFLEXD_LINSR_LINS_SHIFT);

    switch (LinState)
    {
        case LINFLEXD_LIN_IP_LINS_SLEEP_MODE_U8:
            LinCurrentState->CurrentNodeState = LINFLEXD_LIN_IP_NODE_STATE_SLEEP_MODE;
            break;

        case LINFLEXD_LIN_IP_LINS_INIT_MODE_U8:
            LinCurrentState->CurrentNodeState = LINFLEXD_LIN_IP_NODE_STATE_UNINIT;
            break;
        case LINFLEXD_LIN_IP_LINS_IDLE_MODE_U8:
            LinCurrentState->CurrentNodeState = LINFLEXD_LIN_IP_NODE_STATE_IDLE;
            break;

        case LINFLEXD_LIN_IP_LINS_SYNC_BREAK_U8:
            /* Through-out */
        case LINFLEXD_LIN_IP_LINS_SYNC_DEL_U8:
            /* Through-out */
        case LINFLEXD_LIN_IP_LINS_SYNC_FIELD_U8:
            /* Through-out */
        case LINFLEXD_LIN_IP_LINS_IDENTIFIER_FIELD_U8:
            /* As actual behavior, LINS will equal 6 when PID has been already sent.
            It is not matched with LINS field description. A ticket will be raised to HW team for checking this problem. */
            /* Check lin node is whether master or not */
            if (LINFLEXD_LINCR1_MME_MASK == (Base->LINCR1 & LINFLEXD_LINCR1_MME_MASK))
            {
                LinCurrentState->CurrentNodeState = LINFLEXD_LIN_IP_NODE_STATE_SEND_HEADER;
            }
            else
            {
                LinCurrentState->CurrentNodeState = LINFLEXD_LIN_IP_NODE_STATE_RECV_HEADER;
            }
            break;
        case LINFLEXD_LIN_IP_LINS_HEADER_RECEPT_TRANS_U8:
            /* Through-out */
        case LINFLEXD_LIN_IP_LINS_DATA_RECEPT_TRANS_U8:
            /* Through-out */
        case LINFLEXD_LIN_IP_LINS_CHECKSUM_U8:
            /* LINFLEXD transimitting data */
            if (LINFLEXD_BIDR_DIR_MASK == (Base->BIDR & LINFLEXD_BIDR_DIR_MASK))
            {
                LinCurrentState->CurrentNodeState = LINFLEXD_LIN_IP_NODE_STATE_SEND_DATA;
            }
            /* LINFLEXD receiving data */
            else
            {
                LinCurrentState->CurrentNodeState = LINFLEXD_LIN_IP_NODE_STATE_RECV_DATA;
            }
            break;

        default:
            /* Should not enter here */
            break;
    }
}
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#ifdef LINFLEXD_LIN_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE
void Linflexd_Lin_Ip_SetUserAccess(const uint8 Instance)
{
    LINFLEXD_Type * Base = Linflexd_Lin_Ip_apxBases[Instance];

    SET_USER_ACCESS_ALLOWED((uint32)Base, LINFLEX_PROT_MEM_U32);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Lin_Ip_SetUserAccessAllowed
 * Description   : This function can allow user access to protected module specific.
 *
 * Implements    : Linflexd_Lin_Ip_SetUserAccessAllowed_Activity
 *END**************************************************************************/
static void Linflexd_Lin_Ip_SetUserAccessAllowed(const uint8 Instance)
{
    /* User mode allowed */
    OsIf_Trusted_Call1param(Linflexd_Lin_Ip_SetUserAccess, Instance);
}
#endif /* LINFLEXD_LIN_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE */

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Lin_Ip_Init
 * Description   : This function initializes a LINFLEXD Instance for operation.
 * This function will initialize the run-time state structure to keep track of
 * the on-going transfers, initialize the module to user defined settings and
 * default settings, set break field length to be 13 bit times minimum, enable
 * the break detect interrupt, Rx complete interrupt, frame error detect interrupt,
 * and enable the LINFLEXD module transmitter and receiver.
 *
 * Implements    : Linflexd_Lin_Ip_Init_Activity
 *END**************************************************************************/
/**
* @implements Linflexd_Lin_Ip_Init_Activity
*/
Linflexd_Lin_Ip_StatusType Linflexd_Lin_Ip_Init(const uint8 Instance, const Linflexd_Lin_Ip_UserConfigType *LinUserConfig)
{
    LINFLEXD_Type *Base;
    Linflexd_Lin_Ip_StateStructType *CrtStateStruct;
    Linflexd_Lin_Ip_StatusType RetVal = LINFLEXD_LIN_IP_STATUS_SUCCESS;

#if (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LINFLEXD_LIN_IP_DEV_ASSERT(NULL_PTR != LinUserConfig);
    LINFLEXD_LIN_IP_DEV_ASSERT(Instance < LINFLEXD_INSTANCE_COUNT);
    LINFLEXD_LIN_IP_DEV_ASSERT(Instance == LinUserConfig->Instance);
    LINFLEXD_LIN_IP_DEV_ASSERT(NULL_PTR == Linflexd_Lin_Ip_apxStateStructureArray[Instance]);
#endif /* (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* Get base address of the LINFLEXD Instance. */
    Base = Linflexd_Lin_Ip_apxBases[Instance];
    /* Save runtime structure pointer. */
    Linflexd_Lin_Ip_apxStateStructureArray[Instance] = LinUserConfig->StateStructPtr;
    /* Get the pointer of the state structure  */
    CrtStateStruct = Linflexd_Lin_Ip_apxStateStructureArray[Instance];
    CrtStateStruct->CurrentNodeState = LINFLEXD_LIN_IP_NODE_STATE_UNINIT;
    /* Save LIN user config structure pointer. */
    Linflexd_Lin_Ip_apUserConfigs[Instance] = LinUserConfig;

    /*Allow user access to protected module specific when user mode is supported*/
#ifdef LINFLEXD_LIN_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE
    Linflexd_Lin_Ip_SetUserAccessAllowed(Instance);
#endif /* LINFLEXD_LIN_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE */

    /* Enter to init mode */
    Base->LINCR1 |= LINFLEXD_LINCR1_INIT(1);
    Base->LINCR1 &= ~LINFLEXD_LINCR1_SLEEP(1);
    /* Wait to enter init mode */
    RetVal = Linflexd_Lin_Ip_StateTimeoutMode(Instance, LINFLEXD_LIN_IP_LINSR_INIT_MODE_U32);
    /* Some bits written only in initialization mode */
    if(LINFLEXD_LIN_IP_STATUS_SUCCESS == RetVal)
    {
        /* Set to LIN mode, Configure LINCR1 and LINCR2 register */
        Linflexd_Lin_Ip_SetUpRegisterInInitMode(Instance);
        /* Exit init mode, enter normal mode */
        Base->LINCR1 &= ~LINFLEXD_LINCR1_INIT(1);
        /* Wait to enter normal mode */
        RetVal = Linflexd_Lin_Ip_StateTimeoutMode(Instance, LINFLEXD_LIN_IP_LINSR_IDLE_MODE_U32);
        if(LINFLEXD_LIN_IP_STATUS_SUCCESS == RetVal)
        {
            /* Configure interrupt enable/disable */
            Linflexd_Lin_Ip_SetUpRegisterInNormalMode(Instance);
            /* Clear flags in current LIN state structure */
            CrtStateStruct->IsBusBusy = FALSE;
            CrtStateStruct->CurrentNodeState = LINFLEXD_LIN_IP_NODE_STATE_IDLE;
            CrtStateStruct->FrameCommand = LINFLEXD_LIN_IP_TX_NO_COMMAND;
        }
        else
        {
            /* If timeout occurred, Init is not successfully, ERROR report will be raised */
            RetVal = LINFLEXD_LIN_IP_STATUS_ERROR;
        }
    
    }
    else
    {
        /* If timeout occurred, Init is not successfully, ERROR report will be raised */
        RetVal = LINFLEXD_LIN_IP_STATUS_ERROR;
    }
    
    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Lin_Ip_Deinit
 * Description   : This function shuts down the LINFLEXD by disabling interrupts and
 *                 transmitter/receiver.
 *
 * Implements    : Linflexd_Lin_Ip_Deinit_Activity
 *END**************************************************************************/
/**
* @implements Linflexd_Lin_Ip_Deinit_Activity
*/
Linflexd_Lin_Ip_StatusType Linflexd_Lin_Ip_Deinit(const uint8 Instance)
{
    LINFLEXD_Type *Base;
    Linflexd_Lin_Ip_StateStructType *LinCurrentState;
    Linflexd_Lin_Ip_StatusType RetVal = LINFLEXD_LIN_IP_STATUS_SUCCESS;

#if (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LINFLEXD_LIN_IP_DEV_ASSERT(Instance < LINFLEXD_INSTANCE_COUNT);
    LINFLEXD_LIN_IP_DEV_ASSERT(NULL_PTR != Linflexd_Lin_Ip_apxStateStructureArray[Instance]);
#endif /* (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON) */
    
    /* Get the current LIN state of this LINFLEXD Instance. */
    LinCurrentState = Linflexd_Lin_Ip_apxStateStructureArray[Instance];
    /* Get base address of the LINFLEXD Instance. */
    Base = Linflexd_Lin_Ip_apxBases[Instance];

    if (TRUE != LinCurrentState->IsBusBusy)
    {
        /* Disable all interrupts in the LINFLEXD */
        Base->LINIER = (uint32)0u;
        /* Change node's current state to UNINIT */
        LinCurrentState->CurrentNodeState = LINFLEXD_LIN_IP_NODE_STATE_UNINIT;
        /* Clear our saved pointer to the LIN state structure */
        Linflexd_Lin_Ip_apxStateStructureArray[Instance] = NULL_PTR;
      
    }
    else
    {
        /* Can't Deinit when IsBusBusy is true */
        RetVal = LINFLEXD_LIN_IP_STATUS_ERROR;
    }
    

    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Lin_Ip_AbortTransferData
 * Description   : Aborts an on-going non-blocking transmission.
 * While performing a non-blocking transferring data, users can call this
 * function to terminate immediately the current transferring.
 *
 *END**************************************************************************/
/**
* @implements Linflexd_Lin_Ip_AbortTransferData_Activity
*/
Linflexd_Lin_Ip_StatusType Linflexd_Lin_Ip_AbortTransferData(const uint8 Instance)
{
    Linflexd_Lin_Ip_StatusType RetVal = LINFLEXD_LIN_IP_STATUS_ERROR;
    Linflexd_Lin_Ip_StateStructType *LinCurrentState;
    LINFLEXD_Type *Base;
    uint32 TimeoutTicks;
    uint32 StartTime;
    uint32 ElapsedTicks = 0;
    volatile uint32 TestFlag = (uint32)LINFLEXD_LINCR2_ABRQ_MASK;


#if (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LINFLEXD_LIN_IP_DEV_ASSERT(Instance < LINFLEXD_INSTANCE_COUNT);
#endif /* (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* Get the current LIN state of this LINFLEXD Instance. */
    LinCurrentState = Linflexd_Lin_Ip_apxStateStructureArray[Instance];

#if (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LINFLEXD_LIN_IP_DEV_ASSERT(NULL_PTR != LinCurrentState);
#endif /* (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    Base = Linflexd_Lin_Ip_apxBases[Instance];

    if (TRUE == LinCurrentState->IsBusBusy)
    {
        /* Abort on-going transmission */
        Base->LINCR2 |= LINFLEXD_LINCR2_ABRQ(1);

        /* Set time for waiting loop */
        Linflexd_Lin_Ip_StartTimeout(&StartTime, &TimeoutTicks, LINFLEXD_LIN_IP_TIMEOUT_VALUE_US, LINFLEXD_LIN_IP_TIMEOUT_TYPE);
        /*Add label Fault Injection */
        MCAL_FAULT_INJECTION_POINT(LINFLEXD_FIP_1_T_TIME_OUT_1);
        /* Wait for abouting current transmission */
        do
        {
            if (TestFlag != (Base->LINCR2 & ((uint32)LINFLEXD_LINCR2_ABRQ_MASK)))
            {
                RetVal = LINFLEXD_LIN_IP_STATUS_SUCCESS;
                break;
            }
        }
        while (!Linflexd_Lin_Ip_TimeoutExpired(&StartTime, &ElapsedTicks, TimeoutTicks, LINFLEXD_LIN_IP_TIMEOUT_TYPE));
        
        /* Abort current transmission is successfully, set isBusBusy to FALSE */
        if(LINFLEXD_LIN_IP_STATUS_SUCCESS == RetVal)
        {
            SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_02();
            {
                /* Bus is idle */
                LinCurrentState->IsBusBusy = FALSE;
            }
            SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_02();
        }
        else
        {
            /* Timeout occurred */
            RetVal = LINFLEXD_LIN_IP_STATUS_ERROR;
        }
    }
    else
    {
        RetVal = LINFLEXD_LIN_IP_STATUS_SUCCESS;
    }

    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Lin_Ip_GetCurrentNodeState
 * Description   : This function is used to retrieve the current state of the lin node.
 *
 *END**************************************************************************/
/**
* @implements Linflexd_Lin_Ip_GetCurrentNodeState_Activity
*/
Linflexd_Lin_Ip_NodeStateType Linflexd_Lin_Ip_GetCurrentNodeState(const uint8 Instance)
{
    const Linflexd_Lin_Ip_StateStructType *LinCurrentState;

    #if (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LINFLEXD_LIN_IP_DEV_ASSERT(Instance < LINFLEXD_INSTANCE_COUNT);
    #endif /* (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* Updated current node state base on LINSR[LINS] */
    Linflexd_Lin_Ip_UpdateCurrentNodeState(Instance);
    /* Get the current LIN state of this LINFLEXD instance. */
    LinCurrentState = (const Linflexd_Lin_Ip_StateStructType *)Linflexd_Lin_Ip_apxStateStructureArray[Instance];

    return LinCurrentState->CurrentNodeState;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Lin_Ip_GetStatus
 * Description   : This function returns the status of the current non-blocking transfer.
 * If a response reception has been successfully received, Buffer will be referenced to receive buffer.
 *
 *END**************************************************************************/
/**
* @implements Linflexd_Lin_Ip_GetStatus_Activity
*/
Linflexd_Lin_Ip_TransferStatusType Linflexd_Lin_Ip_GetStatus(const uint8 Instance, uint8 **Buffer)
{
    Linflexd_Lin_Ip_TransferStatusType  RetVal = LINFLEXD_LIN_IP_STATUS_FAIL;
    const Linflexd_Lin_Ip_StateStructType *LinCurrentState;
    Linflexd_Lin_Ip_EventIdType CurrentEventId;
    Linflexd_Lin_Ip_NodeStateType CurrentNodeState;
    const LINFLEXD_Type *Base;
    uint32 Linsr = 0u;

    #if (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LINFLEXD_LIN_IP_DEV_ASSERT(Instance < LINFLEXD_INSTANCE_COUNT);
    LINFLEXD_LIN_IP_DEV_ASSERT(Buffer != NULL_PTR);
    #endif /* (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON) */
    /* Get the current LIN state of this LINFLEXD instance. */
    LinCurrentState = (const Linflexd_Lin_Ip_StateStructType *)Linflexd_Lin_Ip_apxStateStructureArray[Instance];
    #if (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LINFLEXD_LIN_IP_DEV_ASSERT(NULL_PTR != LinCurrentState);
    #endif /* (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON) */
    CurrentEventId = LinCurrentState->CurrentEventId;
    /* Updated current node state base on LINSR[LINS] */
    Linflexd_Lin_Ip_UpdateCurrentNodeState(Instance);
    CurrentNodeState = LinCurrentState->CurrentNodeState;
    /* Get base value */
    Base = (const LINFLEXD_Type *)Linflexd_Lin_Ip_apxBases[Instance];
    /* Get hardware status */
    Linsr = Base->LINSR;

    switch (CurrentEventId)
    {
        case LINFLEXD_LIN_IP_NO_EVENT:
            /* Fall-through */
        case LINFLEXD_LIN_IP_WAKEUP_SIGNAL:
            /* Returns the status of the current wakeup signal */
            RetVal = Linflexd_Lin_Ip_GetNoEventStatus(Instance);
            break;
        case LINFLEXD_LIN_IP_RECV_HEADER_OK:
            RetVal = LINFLEXD_LIN_IP_STATUS_RX_HEADER_OK;
            break;
        case LINFLEXD_LIN_IP_SEND_HEADER_OK:
            /* this case never occurred because CurrentEventId is not assigned to LINFLEXD_LIN_IP_SEND_HEADER_OK any where */
            break;
        case LINFLEXD_LIN_IP_OVERRUN_ERROR:
            RetVal = LINFLEXD_LIN_IP_STATUS_RX_ERROR;
            break;
        case LINFLEXD_LIN_IP_FRAME_ERROR:
            /* LINFlexD also takes the byte that caused the framing error and shifts it to the buffer.
               So, It is used to check frame error during receive header or data base on buffer status.*/
            if(0u != (Linsr & LINFLEXD_LINSR_DRBNE_MASK))
            {
                RetVal = LINFLEXD_LIN_IP_STATUS_RX_ERROR;
            }
            else
            {
                RetVal = LINFLEXD_LIN_IP_STATUS_RX_HEADER_ERROR;
            }
            break;
        case LINFLEXD_LIN_IP_READBACK_ERROR:
            /* check bit error during send header or data */
            switch (CurrentNodeState)
            {
                case LINFLEXD_LIN_IP_NODE_STATE_SEND_HEADER:
                    RetVal = LINFLEXD_LIN_IP_STATUS_TX_HEADER_ERROR;
                    break;
                case LINFLEXD_LIN_IP_NODE_STATE_SEND_DATA:
                    RetVal = LINFLEXD_LIN_IP_STATUS_TX_ERROR;
                    break;
                default:
                    /* will not jump here */
                    break;
            }
            break;
        case LINFLEXD_LIN_IP_CHECKSUM_ERROR:
            RetVal = LINFLEXD_LIN_IP_STATUS_RX_ERROR;
            break;
        case LINFLEXD_LIN_IP_TX_COMPLETED:
            RetVal = LINFLEXD_LIN_IP_STATUS_TX_OK;
            break;
        case LINFLEXD_LIN_IP_RX_COMPLETED:
            RetVal = LINFLEXD_LIN_IP_STATUS_RX_OK;
            /* get the address of the data receive buffer */
            *Buffer = Linflexd_Lin_Ip_au8SduBuffer[Instance];
            /* Copy data form buffer register */
            Linflexd_Lin_Ip_CopyData(Instance, Linflexd_Lin_Ip_au8SduBuffer[Instance]);
            break;
        case LINFLEXD_LIN_IP_TIMEOUT_ERROR:
            /* check timeout during receive header or data */
            RetVal = Linflexd_Lin_Ip_GetTimeoutErrorStatus(Instance);
            break;
        case LINFLEXD_LIN_IP_HEADER_RECEPT_ERROR:
            RetVal = LINFLEXD_LIN_IP_STATUS_RX_HEADER_ERROR;
            break;
        default:
            /* not jumped here */
            break;
    }

    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Lin_Ip_GoToSleepMode
 * Description   : This function puts current LIN node to sleep mode.
 * This function changes current node state to LINFLEXD_LIN_IP_NODE_STATE_SLEEP_MODE.
 *
 * Implements    : Linflexd_Lin_Ip_GoToSleepMode_Activity
 *END**************************************************************************/
/**
* @implements Linflexd_Lin_Ip_GoToSleepMode_Activity
*/
Linflexd_Lin_Ip_StatusType Linflexd_Lin_Ip_GoToSleepMode(const uint8 Instance)
{
    LINFLEXD_Type *Base;
    Linflexd_Lin_Ip_StateStructType *LinCurrentState;
    Linflexd_Lin_Ip_StatusType RetVal = LINFLEXD_LIN_IP_STATUS_ERROR;

#if (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LINFLEXD_LIN_IP_DEV_ASSERT(Instance < LINFLEXD_INSTANCE_COUNT);
    LINFLEXD_LIN_IP_DEV_ASSERT(NULL_PTR != Linflexd_Lin_Ip_apxStateStructureArray[Instance]);
#endif /* (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* Get base address of the LINFLEXD Instance. */
    Base = Linflexd_Lin_Ip_apxBases[Instance];
    /* Get the current LIN state of this LINFLEXD Instance. */
    LinCurrentState = Linflexd_Lin_Ip_apxStateStructureArray[Instance];
    if (LinCurrentState->IsBusBusy)
    {
        /* Can't enter sleep mode when on-going transmission */
        RetVal = LINFLEXD_LIN_IP_STATUS_ERROR;
    }
    else
    {
        /* Write 1 to clear wake-up flag. */
        Base->LINSR = LINFLEXD_LINSR_WUF(1);
        /* Write 1 to clear release message buffer flag */
        Base->LINSR = LINFLEXD_LINSR_RMB(1);
    
        SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_03();
        {
    
            if (TRUE == Linflexd_Lin_Ip_apUserConfigs[Instance]->WakeupDetectSupport)
            {
                /* Enable wakeup interrupt */
                Base->LINIER |= LINFLEXD_LINIER_WUIE(1);
            }
            else
            {
                /* Do nothing */
            }
    
            /* Set node to sleep mode */
            Base->LINCR1 |= LINFLEXD_LINCR1_SLEEP(1);
            /* Wait to enter sleep mode */
            RetVal = Linflexd_Lin_Ip_StateTimeoutMode(Instance, LINFLEXD_LIN_IP_LINSR_SLEEP_MODE_U32);
            
            if (LINFLEXD_LIN_IP_STATUS_SUCCESS == RetVal)
            {
                /* Update node's current state to SLEEP_MODE. */
                LinCurrentState->CurrentNodeState = LINFLEXD_LIN_IP_NODE_STATE_SLEEP_MODE;
                LinCurrentState->CurrentEventId = LINFLEXD_LIN_IP_NO_EVENT;
                LinCurrentState->FrameCommand = LINFLEXD_LIN_IP_TX_NO_COMMAND;        
            }
        }
        SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_03();
    }

    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Lin_Ip_GotoIdleState
 * Description   : This function puts the current node in idle mode.
 *
 * Implements    : Linflexd_Lin_Ip_GotoIdleState_Activity
 *END**************************************************************************/
/**
* @implements Linflexd_Lin_Ip_GotoIdleState_Activity
*/
Linflexd_Lin_Ip_StatusType Linflexd_Lin_Ip_GotoIdleState(const uint8 Instance)
{
    LINFLEXD_Type *Base;
    Linflexd_Lin_Ip_StateStructType *LinCurrentState;
    Linflexd_Lin_Ip_StatusType RetVal = LINFLEXD_LIN_IP_STATUS_SUCCESS;

#if (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LINFLEXD_LIN_IP_DEV_ASSERT(Instance < LINFLEXD_INSTANCE_COUNT);
#endif /* (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* Get base address of the LINFLEXD Instance. */
    Base = Linflexd_Lin_Ip_apxBases[Instance];
    /* Get the current LIN state of this LINFLEXD Instance. */
    LinCurrentState = Linflexd_Lin_Ip_apxStateStructureArray[Instance];

#if (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LINFLEXD_LIN_IP_DEV_ASSERT(NULL_PTR != LinCurrentState);
#endif /* (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* Write 1 to clear wake-up flag */
    Base->LINSR = LINFLEXD_LINSR_WUF(1);

    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_04();
    {
        /* Exit sleep mode, enter to idle mode */
        Base->LINCR1 &= ~LINFLEXD_LINCR1_SLEEP(1);
        /* Wait to enter idle mode */
        RetVal = Linflexd_Lin_Ip_StateTimeoutMode(Instance, LINFLEXD_LIN_IP_LINSR_IDLE_MODE_U32);
        if (LINFLEXD_LIN_IP_STATUS_SUCCESS == RetVal)
        {
            /* Clear wake-up interrupt */
            Base->LINIER &= ~LINFLEXD_LINIER_WUIE(1);
            /* Put the node in idle mode */
            LinCurrentState->CurrentEventId = LINFLEXD_LIN_IP_NO_EVENT;
            LinCurrentState->CurrentNodeState = LINFLEXD_LIN_IP_NODE_STATE_IDLE;
            LinCurrentState->FrameCommand = LINFLEXD_LIN_IP_TX_NO_COMMAND;
        }
        else
        {
            /* Can't go to Idle mode when timeout occurred */
            RetVal = LINFLEXD_LIN_IP_STATUS_ERROR;
        }
    }
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_04();

    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Lin_Ip_SendWakeupSignal
 * Description   : This function sends a wakeup signal through the LINFLEXD interface.
 *
 *END**************************************************************************/
/**
* @implements Linflexd_Lin_Ip_SendWakeupSignal_Activity
*/
Linflexd_Lin_Ip_StatusType Linflexd_Lin_Ip_SendWakeupSignal(const uint8 Instance)
{
    LINFLEXD_Type *Base;
    const Linflexd_Lin_Ip_StateStructType *LinCurrentState;
    Linflexd_Lin_Ip_StatusType RetVal = LINFLEXD_LIN_IP_STATUS_SUCCESS;

#if (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LINFLEXD_LIN_IP_DEV_ASSERT(Instance < LINFLEXD_INSTANCE_COUNT);
    LINFLEXD_LIN_IP_DEV_ASSERT(NULL_PTR != Linflexd_Lin_Ip_apxStateStructureArray[Instance]);
#endif /* (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* Get the current LIN state of this LINFLEXD Instance. */
    LinCurrentState = (const Linflexd_Lin_Ip_StateStructType *)Linflexd_Lin_Ip_apxStateStructureArray[Instance];

    /* Get base address of the LINFLEXD Instance. */
    Base = Linflexd_Lin_Ip_apxBases[Instance];

    /* Check if bus is not busy */
    if (FALSE == LinCurrentState->IsBusBusy)
    {
        /* Check if node is in sleep mode */
        if(LINFLEXD_LIN_IP_NODE_STATE_SLEEP_MODE == LinCurrentState->CurrentNodeState)
        {
            /* Before sending the wakeup signal, call Linflexd Lin Ip GotoIdleState to update the mode to normal mode */
            RetVal = Linflexd_Lin_Ip_GotoIdleState(Instance);
            if (LINFLEXD_LIN_IP_STATUS_SUCCESS == RetVal)
            {
                SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_05();
                {
                    /* Disable abort request */
                    Base->LINCR2 &= ~LINFLEXD_LINCR2_ABRQ(1);
                    /* Send a wakeup signal */
                    Base->LINCR2 |= LINFLEXD_LINCR2_WURQ(1);
                }
                SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_05();
            }
            else
            {
                /* Return Error when current node cannot enter Idle mode */
                RetVal = LINFLEXD_LIN_IP_STATUS_ERROR;
            }
        }
        else
        {
            /* Return Error when current node is not in sleep mode */
            RetVal = LINFLEXD_LIN_IP_STATUS_ERROR;
        }
    }
    else
    {
        RetVal = LINFLEXD_LIN_IP_STATUS_BUSY;
    }
    
    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Lin_Ip_SendFrame
 * Description   : This function sends frame header out through the LINFLEXD module
 * using a non-blocking method. Non-blocking  means that the function returns
 * immediately. This function sends LIN Break field, sync field then the ID with
 * correct parity. This function checks if the interface is Master, if not, it will
 * return LINFLEXD_LIN_IP_STATUS_ERROR. This function checks if id is in range from 0 to 0x3F, if not
 * it will return LINFLEXD_LIN_IP_STATUS_ERROR. This function also check node's current state is in
 * SLEEP mode then the function will return LINFLEXD_LIN_IP_STATUS_ERROR. And check if isBusBusy is
 * currently TRUE then the function will return LINFLEXD_LIN_IP_STATUS_BUSY.
 *
 * Implements    : Linflexd_Lin_Ip_SendFrame_Activity
 *END**************************************************************************/
/**
* @implements Linflexd_Lin_Ip_SendFrame_Activity
*/
Linflexd_Lin_Ip_StatusType Linflexd_Lin_Ip_SendFrame(const uint8 Instance, const Linflexd_Lin_Ip_PduType *PduInfoPtr)
{
    Linflexd_Lin_Ip_StatusType RetVal = LINFLEXD_LIN_IP_STATUS_SUCCESS;
    const Linflexd_Lin_Ip_UserConfigType *LinUserConfig;
    LINFLEXD_Type *Base;
    Linflexd_Lin_Ip_StateStructType *LinCurrentState;
    boolean CheckSleepMode;
    uint32 RegVal = (uint32)0;
    uint32 Temp;
    uint8 Loop;
    uint8 DataLength;

#if (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LINFLEXD_LIN_IP_DEV_ASSERT(Instance < LINFLEXD_INSTANCE_COUNT);
    LINFLEXD_LIN_IP_DEV_ASSERT(NULL_PTR != PduInfoPtr);
#endif /* (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* Get the current LIN state of this LINFLEXD Instance. */
    LinCurrentState = Linflexd_Lin_Ip_apxStateStructureArray[Instance];

#if (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check if current Instance is already de-initialized or is gated.*/
    LINFLEXD_LIN_IP_DEV_ASSERT(LinCurrentState != NULL_PTR);
#endif /* (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* Get the current LIN user config structure of this LINFLEXD Instance. */
    LinUserConfig = Linflexd_Lin_Ip_apUserConfigs[Instance];
    /* Get base address of the LINFLEXD Instance. */
    Base = Linflexd_Lin_Ip_apxBases[Instance];
    /* Check whether current mode is sleep mode */
    CheckSleepMode = (LINFLEXD_LIN_IP_NODE_STATE_SLEEP_MODE == LinCurrentState->CurrentNodeState);

    /* Check if the current node is slave or id is invalid or node's current state is in SLEEP state */
    if (CheckSleepMode)
    {
        RetVal = LINFLEXD_LIN_IP_STATUS_ERROR;
    }
    else
    {
        /* Check if the LIN bus is busy */
        if (TRUE == LinCurrentState->IsBusBusy)
        {
            RetVal = LINFLEXD_LIN_IP_STATUS_BUSY;
        }
        else
        {
            LinCurrentState->CurrentEventId = LINFLEXD_LIN_IP_NO_EVENT;
            /* Release message buffer */
            Base->LINSR = LINFLEXD_LINSR_RMB(1);
            /* Clear noise flag */
            Base->LINESR = LINFLEXD_LINESR_NF(1);
            /* Clear reception buffer not empty flag */
            Base->LINSR = LINFLEXD_LINSR_DRBNE(1);
            /* Reset previous data in data register */
            Base->BDRL = (uint32)0UL;
            Base->BDRM = (uint32)0UL;

            if ((boolean)LINFLEXD_LIN_IP_MASTER == LinUserConfig->NodeFunction)
            {
                /* Remove sduBuffer */
                for (Loop = 0u; Loop < LINFLEXD_LIN_IP_MAX_DATA_LENGTH; Loop++)
                {
                    Linflexd_Lin_Ip_au8SduBuffer[Instance][Loop] = 0u;
                }
            }
            /*************************************************
             * Configure PID of frame
             *************************************************/
            DataLength = PduInfoPtr->Dl - 1u;
            /* Set data lenth field */
            RegVal |= LINFLEXD_BIDR_DFL(DataLength);
            /* Set identifier field */
            RegVal |= LINFLEXD_BIDR_ID(PduInfoPtr->Pid);
            /* Classic check sum */
            if (LINFLEXD_LIN_IP_CLASSIC_CS == PduInfoPtr->Cs)
            {
                RegVal |= LINFLEXD_BIDR_CCS(1);
            }
            else
            {
                /* Enhanced check sum */
                RegVal &= ~LINFLEXD_BIDR_CCS(1);
            }

            /* RegVal is 0 before updating, so information of previous frame is removed */
            Base->BIDR = RegVal;

            /* Check response is sent by the lin node or not */
            if (LINFLEXD_LIN_IP_FRAMERESPONSE_TX == PduInfoPtr->Drc)
            {
                /* If data length is smaller than 5, data will be written to least significant data buffer */
                if (5u > PduInfoPtr->Dl)
                {
                    RegVal = (uint32)0x000000000;

                    /* Copy data to buffer register */
                    for (Loop = 0u; Loop < PduInfoPtr->Dl; Loop++)
                    {
                        Temp = PduInfoPtr->SduPtr[Loop];
                        RegVal |= ( (Temp & (uint32)LINFLEXD_BDRL_DATA0_MASK) << (Loop * (uint8)8u) );
                    }

                    Base->BDRL = RegVal;
                }
                /* Data length is greater than 4, data will be written to least and most significant data buffers */
                else
                {
                    /* Write the 4 first bytes to least significant data buffer */
                    RegVal = (uint32)0x00000000;

                    for (Loop = (uint8)0U; Loop < (uint8)4U; Loop++)
                    {
                        Temp = PduInfoPtr->SduPtr[Loop];
                        RegVal |= ( (Temp & (uint32)LINFLEXD_BDRL_DATA0_MASK) << (Loop * (uint8)8u) );
                    }

                    /* Write to BDRL register */
                    Base->BDRL = RegVal;
                    RegVal = (uint32)0x00000000;

                    for (Loop =  (uint8)4U; Loop < PduInfoPtr->Dl; Loop++)
                    {
                        Temp = PduInfoPtr->SduPtr[Loop];
                        RegVal |= ( (Temp & (uint32)LINFLEXD_BDRM_DATA4_MASK) << ((Loop - 4U) * (uint8)8U) );
                    }

                    /* Write to BDRM register */
                    Base->BDRM = RegVal;
                }

                /* Set direction filed, send data from BDR register */
                RegVal = LINFLEXD_BIDR_DIR(1);
                LinCurrentState->FrameCommand = LINFLEXD_LIN_IP_TX_MASTER_RES_COMMAND;
            }
            /* The Lin node will receive response */
            else if (LINFLEXD_LIN_IP_FRAMERESPONSE_RX == PduInfoPtr->Drc)
            {
                /* Set direction filed, receive data and copy them in BDR register */
                RegVal = LINFLEXD_BIDR_DIR(0);
                LinCurrentState->FrameCommand = LINFLEXD_LIN_IP_TX_SLAVE_RES_COMMAND;
                /* Write nothing to buffer */
            }
            /* The Lin node will ignore the response */
            else if(LINFLEXD_LIN_IP_FRAMERESPONSE_IGNORE == PduInfoPtr->Drc)
            {
                /* Ignore frame, so lin channel will discard data */
                Base->LINCR2 |= LINFLEXD_LINCR2_DDRQ(1);
                LinCurrentState->FrameCommand = LINFLEXD_LIN_IP_TX_SLAVE_TO_SLAVE_COMMAND;
            }
            else
            {
                /* Do nothing */
            }

            /* Update direction of frame */
            Base->BIDR |= RegVal;

            if ((boolean)LINFLEXD_LIN_IP_SLAVE != LinUserConfig->NodeFunction)
            {
                /* Set LIN current state to sending Break field */
                LinCurrentState->CurrentNodeState = LINFLEXD_LIN_IP_NODE_STATE_SEND_HEADER;
                /* Node is master task, start send header */
                RegVal = LINFLEXD_LINCR2_HTRQ(1);
                /* Bus is busy */
                LinCurrentState->IsBusBusy = TRUE;
            }
            else
            {
                if (LINFLEXD_LIN_IP_FRAMERESPONSE_TX == PduInfoPtr->Drc)
                {
                    LinCurrentState->CurrentNodeState = LINFLEXD_LIN_IP_NODE_STATE_SEND_DATA;
                    /* Lin node is slave task, start send data */
                    RegVal = LINFLEXD_LINCR2_DTRQ(1);
                    /* Bus is busy */
                    LinCurrentState->IsBusBusy = TRUE;
                }
                else if (LINFLEXD_LIN_IP_FRAMERESPONSE_RX == PduInfoPtr->Drc)
                {
                    LinCurrentState->CurrentNodeState = LINFLEXD_LIN_IP_NODE_STATE_RECV_DATA;
                    /* Bus is busy */
                    LinCurrentState->IsBusBusy = TRUE;
                }
                else
                {
                    /* Abort data reception request is proposed */
                }
            }

            SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_06();
            {
                /* Master/Slave starts transmitting respectively header/data field */
                Base->LINCR2 |= RegVal;
            }
            SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_06();
        }
    }

    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Lin_Ip_TxRx_IRQHandler
 * Description   : Interrupt handler for LINFLEXD.
 * This function shall manage all the RX and TX ISRs on the address channel.
 *
 * Implements    : Linflexd_Lin_Ip_IRQHandler_Activity
 *END**************************************************************************/
/**
* @implements Linflexd_Lin_Ip_TxRx_IRQHandler_Activity
*/
void Linflexd_Lin_Ip_TxRx_IRQHandler(const uint32 Instance)
{
    uint32 StatusFlag = 0;
    uint8 Pid = 0;
    LINFLEXD_Type *Base;
    Linflexd_Lin_Ip_StateStructType *LinCurrentState;
    const Linflexd_Lin_Ip_UserConfigType * LinUserConfig;

#if (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LINFLEXD_LIN_IP_DEV_ASSERT(Instance < LINFLEXD_INSTANCE_COUNT);
#endif /* (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* Get the current LIN state of this LINFLEXD Instance. */
    LinCurrentState = Linflexd_Lin_Ip_apxStateStructureArray[Instance];
    /* Get base address of the LINFLEXD Instance. */
    Base = Linflexd_Lin_Ip_apxBases[Instance];

    /* Check Instance was initialized or not */
    if ((NULL_PTR != LinCurrentState) && (LINFLEXD_LIN_IP_NODE_STATE_UNINIT != LinCurrentState->CurrentNodeState))
    {
        /* Get user configuration */
        LinUserConfig = Linflexd_Lin_Ip_apUserConfigs[Instance];
        /* Address PduInfo for slave */
        LinCurrentState->SlavePduInfoPtr = &Linflexd_Lin_Ip_anPduInfo[Instance];

        /* Get enabled interrupt information */
        StatusFlag = Base->LINIER;
        /* Get status flag */
        StatusFlag &= Base->LINSR;

        if (0u != StatusFlag)
        {
            /* If receive wake-up signal */
            if (0u != (StatusFlag & LINFLEXD_LINSR_WUF_MASK))
            {
                /* Disable wake-up interrupt */
                Base->LINIER &= ~LINFLEXD_LINIER_WUIE(1);
                LinCurrentState->CurrentEventId = LINFLEXD_LIN_IP_WAKEUP_SIGNAL;

                if (NULL_PTR != LinUserConfig->Callback)
                {
                    LinUserConfig->Callback(Instance, LinCurrentState);
                }

                /* Write 1 to clear wake-up flag */
                Base->LINSR = LINFLEXD_LINSR_WUF(1);
                /* Set state of Lin node to IDLE state */
                LinCurrentState->CurrentNodeState = LINFLEXD_LIN_IP_NODE_STATE_IDLE;
            }
            /* if header received */
            else if (0u != (StatusFlag & LINFLEXD_LINSR_HRF_MASK))
            {
                /* Set current event to header reception completed */
                LinCurrentState->CurrentEventId = LINFLEXD_LIN_IP_RECV_HEADER_OK;
                /* Calculation Pid */
                Pid = Linflexd_Lin_Ip_CalculatePid(Base->BIDR & (uint32)LINFLEXD_BIDR_ID_MASK);

                SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_07();
                {
                    LinCurrentState->SlavePduInfoPtr->Pid = Pid;
                }
                SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_07();

                if ((boolean)LINFLEXD_LIN_IP_SLAVE == LinUserConfig->NodeFunction)
                {
                    if (NULL_PTR != LinUserConfig->Callback)
                    {
                        LinUserConfig->Callback(Instance, LinCurrentState);
                    }
                }

                /* Write 1 to clear header reception completed flag */
                Base->LINSR = LINFLEXD_LINSR_HRF(1);
            }
            else
            {
                /*Handler to Transmit or Receive data and clear all flag when errors occurred */
                Linflexd_Lin_Ip_CompleteTransfer(Instance, StatusFlag);
            }
        }
        else
        {
            /* Spurious interrupt occurred, do nothing */
        }
    }
    else
    {
        /* Uninitilization state, clear all flags */
        Base->LINSR = LINFLEXD_LIN_IP_LINSR_W1C_ALL_FLAGS_U32;
    }

} /* End void Linflexd_Lin_Ip_TxRx_IRQHandler(const uint32 Instance) */

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Lin_Ip_Error_IRQHandler
 * Description   : Error interrupt handler for LINFLEXD.
 * This function shall manage all the Error ISRs on the addressed channel.
 *
 * Implements    : Linflexd_Lin_Ip_Error_IRQHandler_Activity
 *END**************************************************************************/
/**
* @implements Linflexd_Lin_Ip_Error_IRQHandler_Activity
*/
void Linflexd_Lin_Ip_Error_IRQHandler(const uint32 Instance)
{
    uint32 ErrorFlag;
    uint32 LinSyncErrorStatus;
    LINFLEXD_Type *Base;
    const Linflexd_Lin_Ip_StateStructType *LinCurrentState;

#if (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    /* Assert parameters. */
    LINFLEXD_LIN_IP_DEV_ASSERT(Instance < LINFLEXD_INSTANCE_COUNT);
#endif /* (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* Get the current LIN state of this LINFLEXD Instance. */
    LinCurrentState = Linflexd_Lin_Ip_apxStateStructureArray[Instance];
    /* Get base address of the LINFLEXD Instance. */
    Base = Linflexd_Lin_Ip_apxBases[Instance];

    /* Check Instance was initialized or not */
    if ((NULL_PTR != LinCurrentState) && (LINFLEXD_LIN_IP_NODE_STATE_UNINIT != LinCurrentState->CurrentNodeState))
    {
        /* Get error status */
        ErrorFlag = Base->LINESR;
        LinSyncErrorStatus = ErrorFlag & (LINFLEXD_LINESR_SFEF_MASK | LINFLEXD_LINESR_SDEF_MASK | LINFLEXD_LINESR_IDPEF_MASK);

        if (0U != LinSyncErrorStatus)
        {
            /* Set SFEF bit to check SFEF SDEF IDPEF flags are enabled interrupt or not in next step. */
            ErrorFlag |= LINFLEXD_LINESR_SFEF(1);
        }

        ErrorFlag &= Base->LINIER;

        /* Check at least a header error occurred,  */
        if (0UL != (ErrorFlag & LINFLEXD_LINIER_HEIE_MASK))
        {
            /* Clear SFEF after checking header error */
            ErrorFlag &= ~LINFLEXD_LINESR_SFEF(1);
            /* restore SFEF SDEF IDPEF flags if HEIE interrupt is enabled */
            ErrorFlag |= LinSyncErrorStatus;
        }

        if (0UL != ErrorFlag)
        {
            /*Handle to Errors*/
            Linflexd_Lin_Ip_ErrorsHandler(Instance, ErrorFlag);
        }
        else
        {
            /* Spurious interrupt - do nothing */
        }
    }
    else
    {
        /* Uninitilization state, clear all flags */
        Base->LINESR = LINFLEXD_LIN_IP_LINESR_W1C_ALL_FLAGS_U32;
    }
}

#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

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

#include "Xrdc_Ip.h"
#include "sys_init.h"
#include "check_example.h"
#include "S32G274A_SIUL2.h"
#include "S32G274A_SCB.h"


/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define FULL_ACCESS_PERIPHERAL      0x40100000u        /* SWT_0 */
#define NO_ACCESS_PERIPHERAL        0x40104000u        /* SWT_1 */

#define IP_XRDC_INSTANCE_NAME       IP_XRDC_0
#define IP_XRDC_INSTANCE_ID         (0U)
#define T_HF_VECTOR_OFFSET          (3U)

#if !defined(FULL_ACCESS_PERIPHERAL) || !defined(NO_ACCESS_PERIPHERAL)
    #error "Must be define FULL_ACCESS_PERIPHERAL and NO_ACCESS_PERIPHERAL!"
#endif

#define RM_WRITE(addr,data)                    *(uint32*)addr=data
#define DATA_PATTERN                        0x5A5A5A5AUL
#define WAIT_TIME                            0x1000UL
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
volatile Std_ReturnType gXrdcErrorDetected = E_NOT_OK;
Xrdc_Ip_DomainIDErrStatusType gXrdcErrorDetails;

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
/* Dummy delay function */
void Delay_Rm(volatile uint32 u32Cycles)
{
    while(u32Cycles--);
}

/* Disable XRDC Instance */
void XrdcDisable(void)
{
    IP_XRDC_INSTANCE_NAME->CR &= ~XRDC_CR_GVLD_MASK;
}

/* Hardfault Handler */
void HardFault_Handler_Rm(void)
{
    gXrdcErrorDetected = E_OK;
}

/* Install exception handlers */
uint32 SetHandler_Rm(uint32 offset, uint32 newHandler)
{
    uint32 * vector = (uint32 *)S32_SCB->VTOR;
    uint32 oldHandler = vector[offset];
    vector[offset] = newHandler;
    return oldHandler;
}

/* Validate Xrdc Error Details */
boolean CheckXrdcErrorOccurred(void)
{
    boolean bReturnCode = FALSE;
    uint32 u32DomainId;
    uint32 u32ErrorPort;
    /* Get current domain ID from XRDC */
    u32DomainId = Xrdc_Ip_GetDomainID(0);

    if(gXrdcErrorDetails.DomainIDAccessError != u32DomainId)
    {
        return FALSE;
    }

    for(u32ErrorPort = 0; u32ErrorPort < sizeof(gXrdcErrorDetails.ErrorStatus)/sizeof(Xrdc_Ip_ErrorStatusType); u32ErrorPort++)
    {
        /* Check Error if Hardfault occurred */
        if(gXrdcErrorDetails.ErrorStatus[u32ErrorPort].u32AddError == NO_ACCESS_PERIPHERAL)
        {
            bReturnCode = TRUE;
            /* Check that the error was only reported once */
            if(gXrdcErrorDetails.ErrorStatus[u32ErrorPort].ErrState != XRDC_IP_SINGLE_ACCESS)
            {
                bReturnCode = FALSE;
            }
            /* Check that the error was reported on a read operation */
            if(gXrdcErrorDetails.ErrorStatus[u32ErrorPort].ErrAccess != XRDC_IP_WRITE_ACCESS)
            {
                bReturnCode = FALSE;
            }
            /* Check that the error was reported on a secure data access */
            if(gXrdcErrorDetails.ErrorStatus[u32ErrorPort].ErrAttribute != XRDC_IP_SECUPRIV_DATA_ACCESS)
            {
                bReturnCode = FALSE;
            }
            break;
        }
    }

    return bReturnCode;
}

/* Verify NO Error occurred */
boolean CheckXrdcNoError(void)
{
    boolean bReturnCode = TRUE;
    uint32 u32ErrorPort;

    for(u32ErrorPort = 0; u32ErrorPort < sizeof(gXrdcErrorDetails.ErrorStatus)/sizeof(Xrdc_Ip_ErrorStatusType); u32ErrorPort++)
    {
        /* Check Error if Hardfault occurred */
        if(gXrdcErrorDetails.ErrorStatus[u32ErrorPort].u32AddError == 0)
        {
            bReturnCode = FALSE;
        }
    }

    return bReturnCode;
}

boolean CheckXrdcError(boolean bError)
{
    boolean retVal = TRUE;
    if (bError == TRUE)
    {
        retVal = CheckXrdcErrorOccurred();
    }
    else
    {
        retVal = CheckXrdcNoError();
    }
    return retVal;
}
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Main function of the example
* @details      Rm_Init to init XRDC
*               Example for XRDC:
*                   RM_Init configures XRDC with 1 domain and 2 peripherals of used XRDC instance.
*                   Also configures XRDC to have access right for the first PDAC and no access right for the second PDAC.
*                   Try to write data to register of the first PDAC
*                   Verify that no error is detected by XRDC.
*                   Try to write data to register of the second PDAC.
*                   Verify detail error is recorded by XRDC
*/
volatile boolean Status = TRUE;
int main(void)
{
    /* System Init for enable Peripheral Clock */
    sys_init();

    /* Initialize RM CDD */
    Xrdc_Ip_Init(&Xrdc_Config);

    /* Install exception handlers */
    (void)SetHandler_Rm(T_HF_VECTOR_OFFSET, (uint32)HardFault_Handler_Rm);

    /* Delay to waiting for new exception handlers available*/
    Delay_Rm(WAIT_TIME);

    /* Try to write to FULL_ACCESS Peripheral */
    RM_WRITE(FULL_ACCESS_PERIPHERAL,DATA_PATTERN);
    Delay_Rm(WAIT_TIME);

    /* Verify hardfault was not occurred */
    if(gXrdcErrorDetected == E_NOT_OK)
    {
        if(CheckXrdcError(FALSE) == TRUE)
        {
            Status = FALSE;
        }
    }
    else
    {
        Status = FALSE;
    }

    /* Try to write to NO_ACCESS Peripheral */
    RM_WRITE(NO_ACCESS_PERIPHERAL,DATA_PATTERN);
    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();
    Delay_Rm(WAIT_TIME);

    /* Check hardfault interrupt occurred and get error XRDC */
    if(gXrdcErrorDetected == E_OK)
    {
        /* Get Xrdc detail error */
        Xrdc_Ip_GetDomainIDErrorStatus(IP_XRDC_INSTANCE_ID, &gXrdcErrorDetails);
        XrdcDisable();

        if(CheckXrdcError(TRUE) == FALSE)
        {
            Status = FALSE;
        }
    }
    else
    {
        Status = FALSE;
    }
    
    Exit_Example(Status);

    return (0U);
}

#ifdef __cplusplus
}
#endif

/** @} */

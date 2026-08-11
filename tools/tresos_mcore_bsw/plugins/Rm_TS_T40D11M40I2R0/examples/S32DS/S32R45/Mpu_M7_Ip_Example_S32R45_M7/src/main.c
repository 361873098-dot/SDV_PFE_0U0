/*
*   (c) Copyright 2023 NXP
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
#include "Mpu_M7_Ip.h"
#include "Derivative_Cfg.h"
#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
volatile Std_ReturnType gMpuErrorDetected = E_NOT_OK;
volatile boolean gMpuMemfaultOccured = FALSE;
Mpu_M7_Ip_ErrorDetailsType gMpuErrorDetails = {0, MPU_M7_MEMMAN_ERROR_NONE};
volatile boolean Status = TRUE;

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
/* MemoryManagement Handler */
void MemManage_Handler_Rm(void)
{
    gMpuMemfaultOccured = TRUE;
    /* Get error details */
    gMpuErrorDetected =  Mpu_M7_Ip_GetErrorDetails(&gMpuErrorDetails);
    /* Clear all errors */
    S32_SCB->CFSR |= MPU_M7_IP_SCB_CFSR_MMFSR_MASK_WITHOUT_VALID;
    /* Restore access rights to the region */
    Mpu_M7_Ip_SetAccessRight(T_REGION, MPU_M7_PRIV_RWX_UNPRIV_RWX);
}

/* Install exception handlers */
uint32 SetHandler_Rm(uint32 offset, uint32 newHandler)
{
    uint32 * vector = (uint32 *)S32_SCB->VTOR;
    uint32 oldHandler = vector[offset];
    vector[offset] = newHandler;
    return oldHandler;
}

/* Dummy delay function */
void Delay_Rm(volatile uint32 u32Cycles)
{
    while(u32Cycles--);
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Main function of the example
*               Mpu_M7_Ip_Init configure MPU to have access right for PERIPHERAL_ADDR
*               Override exception handlers.
*               Try to write PATTERN to PERIPHERAL_ADDR.
*               Verify that no memfault handler occur.
*               Try to use Mpu_M7_Ip_SetAccessRight to take away right access of core for PERIPHERAL_ADDR and Try to write PATTERN to PERIPHERAL_ADDR. This should trigger an exception for memory management.
*               Verify that memfault handler occur and detail error for MPU is correct
*/
int main(void) 
{
    /* Initialize RM CDD */
    Mpu_M7_Ip_Init(&MPU_M7_ModuleConfig_0);
    
    /* Install exception handlers */
    (void)SetHandler_Rm(T_MEMMANAGE_VECTOR_OFFSET, (uint32)MemManage_Handler_Rm);

    /* Perform access by write to PERIPHERAL_ADDR*/
    PERIPHERAL_ADDR = PATTERN;
    Delay_Rm(0x1000UL);
    
    /*Check if memfault interrupt occurred. It should not occur*/
    if(gMpuMemfaultOccured == TRUE)
    {
       Status = FALSE;
    }
    
    /* Remove access rights of the MPU region */
    Mpu_M7_Ip_SetAccessRight(T_REGION, MPU_M7_PRIV_UNPRIV_NONE);
    
    /* Try to write at PERIPHERAL_ADDR, this should trigger an MPU error as the access is blocked */
    PERIPHERAL_ADDR = PATTERN;
    Delay_Rm(0x1000UL);
    
    /*Check if memfault interrupt occurred*/
    if(gMpuMemfaultOccured == TRUE)
    {
        /* Check if get error successfully*/
        if(gMpuErrorDetected == E_OK)
        {
            /*Check error address and error type*/
            if((gMpuErrorDetails.u32Address != TEST_PERIPHERAL_ADDR) || (gMpuErrorDetails.eType != MPU_M7_MEMMAN_ERROR_DATA_ACCESS))
            {
                Status = FALSE;
            }
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

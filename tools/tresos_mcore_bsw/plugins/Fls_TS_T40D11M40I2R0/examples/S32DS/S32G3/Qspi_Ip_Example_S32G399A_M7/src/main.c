/*
*   (c) Copyright 2021 NXP
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
#include "Clock_Ip.h"
#include "Siul2_Port_Ip.h"
#include "Mpu_M7_Ip.h"
#include "Qspi_Ip.h"
#include "Qspi_Ip_Cfg.h"
#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define FLS_TIME_OUT                 32768U

#define FLS_JOB_ADDRESS              4096U
#define FLS_SECTOR_SIZE              4096U
#define FLS_BUF_SIZE                 128U

#define FLS_CONFIG_QSPI_REGION_DEVICE_SHARE     STD_OFF   /* STD_ON to config AHB region as MEMORY DEVICE SHARED */

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
/* Data buffers to test */
#define FLS_START_SEC_VAR_INIT_8_NO_CACHEABLE
#include "Fls_MemMap.h"

uint8 TxBuffer[FLS_BUF_SIZE];
uint8 RxBuffer_IP[FLS_BUF_SIZE];
uint8 RxBuffer_AHB[FLS_BUF_SIZE];

#define FLS_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
#include "Fls_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static void ExampleAssert(boolean Condition);
static void Fls_InitBuffers(void);
static boolean Fls_VerifyBuffers(void);
static void Fls_GetAhbData(void);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/* Implement a simple assert macro */
static void ExampleAssert(boolean Condition)
{
    if (!Condition)
    {
        for(;;)
        {
            /* Loop forever */
        }
    }
}

static void Fls_InitBuffers(void)
{
    uint32 Index;

    /* Initialize data to default value */
    for (Index = 0U; Index < FLS_BUF_SIZE; Index++)
    {
        TxBuffer[Index] = (uint8)Index;
        RxBuffer_IP[Index] = 0U;
    }
}

static boolean Fls_VerifyBuffers(void)
{
    uint32 Index;

    for (Index = 0U; Index < FLS_BUF_SIZE; Index++)
    {
        if ( (RxBuffer_IP[Index] != TxBuffer[Index]) || (RxBuffer_AHB[Index] != TxBuffer[Index]) )
        {
            return FALSE;
        }
    }
    return TRUE;
}

static void Fls_GetAhbData(void)
{
    uint32 Index;

    /* Table of AHB addresses for QuadSPI instances */
    const uint32 Qspi_Ip_AhbAddress[QuadSPI_INSTANCE_COUNT] = QuadSPI_AHB_PTRS;
    /* Get AHB address of QSPI Instance 0 */
    uint8* pAHBExAddr = (uint8*)(Qspi_Ip_AhbAddress[0U] + FLS_JOB_ADDRESS);

    for (Index = 0U; Index < FLS_BUF_SIZE; Index++)
    {
        RxBuffer_AHB[Index] = pAHBExAddr[Index];
    }
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief        Main function of the example
* @details      Initialize IPV_QSPI driver and
*               erase, write, read external memory
*/
int main(void)
{
    uint32 TimeOut = FLS_TIME_OUT;
    uint32 QspiInstance = QspiConfigSet_VS_0_paFlashConnectionCfg[0].qspiInstance;
    Qspi_Ip_StatusType QspiStatus;
    Clock_Ip_StatusType clockStatus;

    /* Initialize for clock */
    clockStatus = Clock_Ip_Init(&Mcu_aClockConfigPB[0]);
    ExampleAssert(CLOCK_IP_SUCCESS == clockStatus);

    #if (STD_ON == FLS_CONFIG_QSPI_REGION_DEVICE_SHARE)
        /* Initialize MPU to configure the QSPI AHB address space as device memory. This prevents speculative reads in this region. */
        Mpu_M7_Ip_Init(&MPU_M7_ModuleConfig_0);
    #endif

    /* Pin setup for QSPI*/
    Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

    /* Initialize QSPI */
    QspiStatus = Qspi_Ip_ControllerInit(QspiInstance, QspiConfigSet_VS_0_paQspiUnitCfg);
    ExampleAssert(STATUS_QSPI_IP_SUCCESS == QspiStatus);

    QspiStatus = Qspi_Ip_Init(QspiInstance, QspiConfigSet_VS_0_paFlashCfg, QspiConfigSet_VS_0_paFlashConnectionCfg);
    ExampleAssert(STATUS_QSPI_IP_SUCCESS == QspiStatus);

    /* Initialize Tx and Rx Buffer */
    Fls_InitBuffers();

    /* Erase an external sector which has address is 4096 */
    QspiStatus = Qspi_Ip_EraseBlock(QspiInstance, FLS_JOB_ADDRESS, FLS_SECTOR_SIZE);
    ExampleAssert(STATUS_QSPI_IP_SUCCESS == QspiStatus);

    /* Check QspiStatus of external memory */
    while ((STATUS_QSPI_IP_BUSY == (QspiStatus = Qspi_Ip_GetMemoryStatus(QspiInstance))) && (TimeOut > 0))
    {
        TimeOut--;
    }
    ExampleAssert(STATUS_QSPI_IP_SUCCESS == QspiStatus);

    /* Verify erase */
    QspiStatus = Qspi_Ip_EraseVerify(QspiInstance, FLS_JOB_ADDRESS, FLS_SECTOR_SIZE);
    ExampleAssert(STATUS_QSPI_IP_SUCCESS == QspiStatus);

    /* Reset Timeout*/
    TimeOut = FLS_TIME_OUT;

    /* Write to external flash*/
    QspiStatus = Qspi_Ip_Program(QspiInstance, FLS_JOB_ADDRESS, TxBuffer, FLS_BUF_SIZE);
    ExampleAssert(STATUS_QSPI_IP_SUCCESS == QspiStatus);

    /* Check QspiStatus of external memory */
    while ((STATUS_QSPI_IP_BUSY == (QspiStatus = Qspi_Ip_GetMemoryStatus(QspiInstance))) && (TimeOut > 0))
    {
        TimeOut--;
    }
    ExampleAssert(STATUS_QSPI_IP_SUCCESS == QspiStatus);

    /* Read data from external flash
       Using IP command read into RxBuffer_IP buffer */
    QspiStatus = Qspi_Ip_Read(QspiInstance, FLS_JOB_ADDRESS, RxBuffer_IP, FLS_BUF_SIZE);
    ExampleAssert(STATUS_QSPI_IP_SUCCESS == QspiStatus);

    /* Using AHB command read into RxBuffer_AHB buffer */
    QspiStatus = Qspi_Ip_AhbReadEnable(QspiInstance);
    ExampleAssert(STATUS_QSPI_IP_SUCCESS == QspiStatus);

    if (STATUS_QSPI_IP_SUCCESS == QspiStatus)
    {
        Fls_GetAhbData();
    }

    /* Compare data between Tx and two Rx buffers (RxBuffer_IP and RxBuffer_AHB) */
    ExampleAssert(TRUE == Fls_VerifyBuffers());

    /* If we get here it means the test has passed */
    Exit_Example(TRUE);
    return (0U);
}

#ifdef __cplusplus
}
#endif

/** @} */
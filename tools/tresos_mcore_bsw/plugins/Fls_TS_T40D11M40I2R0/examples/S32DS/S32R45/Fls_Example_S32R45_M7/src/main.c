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
#include "Mcu.h"
#include "Siul2_Port_Ip.h"
#include "Mpu_M7_Ip.h"
#include "SchM_Fls.h"
#include "Fls.h"
#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define FLS_CONFIG_QSPI_REGION_DEVICE_SHARE     STD_OFF   /* STD_ON to config AHB region as MEMORY DEVICE SHARED */

#define LOGICAL_START_ADDR                      0U
#define PHYSICAL_START_ADDR                     0x11000U  /* The HW start address corresponding to the logical address 0 */
#define FLS_BUF_SIZE                            2000U
#define EXTERNAL_SECTOR_SIZE                    0x1000U
#define NUMBER_OF_EXTERNAL_SECTOR               8U        /* Total Fls Number Of Sector */
/*
    FlsSectorList     | Fls Sector Size | Fls Number Of Sector | Fls Logical Start Address  | Fls Physical Start Address |
    ----------------- | --------------: | -------------------: | -------------------------: | -------------------------: |
    FlsSector_0       | 4096 (0x1000)   |           3          |             0 (0x0000)     |         69632 (0x11000)    |
    FlsSector_1       | 4096 (0x1000)   |           2          |         12288 (0x3000)     |        131072 (0x20000)    |
    FlsSector_2       | 4096 (0x1000)   |           1          |         20480 (0x5000)     |        196608 (0x30000)    |
    FlsSector_3       | 4096 (0x1000)   |           1          |         24576 (0x6000)     |        204800 (0x32000)    |
    FlsSector_4       | 4096 (0x1000)   |           1          |         28672 (0x7000)     |        217088 (0x35000)    |
*/

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
    uint8* pAHBExAddr = (uint8*)(Qspi_Ip_AhbAddress[0U] + PHYSICAL_START_ADDR);

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
* @details      Initializes the used drivers and uses the Gpt
*               and Dio drivers to toggle a LED periodically
*/
int main(void)
{
    /* Initialize clock */
    #if (MCU_PRECOMPILE_SUPPORT == STD_ON)
    Mcu_Init(NULL_PTR);
    #elif (MCU_PRECOMPILE_SUPPORT == STD_OFF)
    Mcu_Init(&Mcu_Config);
    #endif /* (MCU_PRECOMPILE_SUPPORT == STD_ON) */
    Mcu_InitClock(McuClockSettingConfig_0);
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() )
    {
        /* Busy wait until the System PLL is locked */
    }
    Mcu_DistributePllClock();
    Mcu_SetMode(McuModeSettingConf_0);

    #if (STD_ON == FLS_CONFIG_QSPI_REGION_DEVICE_SHARE)
        /* Initialize RM CDD to use MPU M7 to forbid access to the QSPI AHB address space */
        Mpu_M7_Ip_Init(&MPU_M7_ModuleConfig_0);
    #endif

    /* Init Pin for Qspi */
	Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

    /* Initialize Fls driver */
    Fls_Init(NULL_PTR);
    ExampleAssert(MEMIF_IDLE == Fls_GetStatus());

    /* Initialize Tx and Rx Buffer */
    Fls_InitBuffers();

    /* Erase entire Fls sector configured */
    Fls_Erase(LOGICAL_START_ADDR, NUMBER_OF_EXTERNAL_SECTOR * EXTERNAL_SECTOR_SIZE);
    while (MEMIF_IDLE != Fls_GetStatus())
    {
        Fls_MainFunction();
    }
    /* Check last job */
    ExampleAssert(MEMIF_JOB_OK == Fls_GetJobResult());

    /* Write data to external sector */
    Fls_Write(LOGICAL_START_ADDR, TxBuffer, FLS_BUF_SIZE);
    while (MEMIF_IDLE != Fls_GetStatus())
    {
        Fls_MainFunction();
    }
    /* Check last job */
    ExampleAssert(MEMIF_JOB_OK == Fls_GetJobResult());

    /* Read data from external sector */
    Fls_Read(LOGICAL_START_ADDR, RxBuffer_IP, FLS_BUF_SIZE);
    while (MEMIF_IDLE != Fls_GetStatus())
    {
        Fls_MainFunction();
    }
    /* Check last job */
    ExampleAssert(MEMIF_JOB_OK == Fls_GetJobResult());

    /* Compare data in external sector to TxBuffer buffer */
    Fls_Compare(LOGICAL_START_ADDR, TxBuffer, FLS_BUF_SIZE);
    while (MEMIF_IDLE != Fls_GetStatus())
    {
        Fls_MainFunction();
    }
    /* Check last job */
    ExampleAssert(MEMIF_JOB_OK == Fls_GetJobResult());

    /* Read data from external sector via AHB command */
    Fls_GetAhbData();

    /* Compare data between Tx and Rx buffer */
    ExampleAssert(TRUE == Fls_VerifyBuffers());

    /* If we get here it means the test has passed */
    Exit_Example(TRUE);
    return (0U);
}

#ifdef __cplusplus
}
#endif

/** @} */
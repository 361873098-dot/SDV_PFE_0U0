/*
*   (c) Copyright 2020 NXP
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
#include "S32G274A_SIUL2.h"
#include "Schm_Fls.h"
#include "Schm_Fee.h"
#include "Fls.h"
#include "Fee.h"
#include "CDD_Rm.h"
#include "check_example.h"
#include "sys_init.h"

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


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
const uint8 DataBlock0[4] = {0x00,0x01,0x02,0x03};

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
uint8 DataReceive[2] = {0x0,0x0};

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static void QspiPinSetup(void);
static void ExampleAssert(boolean Condition);
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

static void QspiPinSetup(void)
{
    IP_SIUL2_0->MSCR[85] = 0x00280021U;        /*QSPI_A[0]*/
    IP_SIUL2_0->MSCR[86] = 0x00280021U;        /*QSPI_A[1]*/
    IP_SIUL2_0->MSCR[87] = 0x00280021U;        /*QSPI_A[2]*/
    IP_SIUL2_0->MSCR[88] = 0x00280021U;        /*QSPI_A[3]*/
    IP_SIUL2_0->MSCR[89] = 0x00280021U;        /*QSPI_A[4]*/
    IP_SIUL2_0->MSCR[90] = 0x00280021U;        /*QSPI_A[5]*/
    IP_SIUL2_0->MSCR[91] = 0x00280021U;        /*QSPI_A[6]*/
    IP_SIUL2_0->MSCR[92] = 0x00280021U;        /*QSPI_A[7]*/
    IP_SIUL2_0->MSCR[93] = 0x00280021U;        /*QSPI_A Data strobe*/
    IP_SIUL2_0->MSCR[96] = 0x00200021U;        /*QSPI_A Serial Clock*/
    IP_SIUL2_0->MSCR[97] = 0x00200021U;        /*QSPI_A Serial Clock*/
    IP_SIUL2_0->MSCR[98] = 0x00200021U;        /*QSPI_A Serial Clock*/
    IP_SIUL2_0->MSCR[99] = 0x00200021U;        /*QSPI_A Serial Clock*/
    IP_SIUL2_0->MSCR[100] = 0x00203021U;       /*QSPI_A Chip select*/
    IP_SIUL2_0->MSCR[101] = 0x00203021U;       /*QSPI_A Chip select*/

    IP_SIUL2_0->IMCR[28] = 0x00000002;
    IP_SIUL2_0->IMCR[29] = 0x00000002;
    IP_SIUL2_0->IMCR[30] = 0x00000002;
    IP_SIUL2_0->IMCR[31] = 0x00000002;
    IP_SIUL2_0->IMCR[32] = 0x00000002;
    IP_SIUL2_0->IMCR[33] = 0x00000002;
    IP_SIUL2_0->IMCR[34] = 0x00000002;
    IP_SIUL2_0->IMCR[35] = 0x00000002;
    IP_SIUL2_0->IMCR[36] = 0x00000002;

    /*QSPI_A INTERRUPT: ECC error signal, Flash Memory A drives this signal to active low value in case of an ECC error */
    IP_SIUL2_0->MSCR[94] = 0x00083020;  /* Disable OBE; Enable IBE; Enable pull-up */
    IP_SIUL2_0->IMCR[37] = 0x00000002;
}
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Main function of the example
* @details      Initializez the used drivers and uses the Gpt
*               and Dio drivers to toggle a LED periodically
*/
int main(void)
{
    MemIf_StatusType status = MEMIF_IDLE;

    /* Initialize for clock */
    sys_init();
    /* Initialize RM CDD to use MPU M7 to forbid access to the QSPI AHB address space */
    Rm_Init(NULL_PTR);
    /* Initialize PIN for Qspi */
    QspiPinSetup();
    /* Initialize Fls driver */
    Fls_Init(NULL_PTR);
    /* Initialize Fee driver */
    Fee_Init(NULL_PTR);
    /*Perform init Fee driver*/
    do
    {
        Fls_MainFunction();
        Fee_MainFunction();
        status = Fee_GetStatus();
    } while (status != MEMIF_IDLE);

    ExampleAssert(MEMIF_JOB_OK == Fee_GetJobResult());
    /*Write data to block 0*/
    Fee_Write(FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_0, DataBlock0);

    /*Perform write data to Block 0*/
    do
    {
        Fls_MainFunction();
        Fee_MainFunction();
        status = Fee_GetStatus();
    } while (status != MEMIF_IDLE);

    ExampleAssert(MEMIF_JOB_OK == Fee_GetJobResult());
    /*Read data block 0, from offset 2 and length is 2*/
    Fee_Read(FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_0, 2, DataReceive, 2);

    /*Perform read data form Block 0*/
    do
    {
        Fls_MainFunction();
        Fee_MainFunction();
        status = Fee_GetStatus();
    } while (status != MEMIF_IDLE);
    ExampleAssert(MEMIF_JOB_OK == Fee_GetJobResult());
    /*Check Data*/
    if((DataReceive[0] != DataBlock0[2])|| (DataReceive[1] != DataBlock0[3]))
    {
        Exit_Example(FALSE);
    }
    else
    {
        Exit_Example(TRUE);
    }

    return (0U);
}

#ifdef __cplusplus
}
#endif

/** @} */

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
#include "sys_init.h"
#include "Schm_Fls.h"
#include "Schm_Fee.h"
#include "CDD_Rm.h"
#include "Fls.h"
#include "Fee.h"
#include "check_example.h"
#include "S32G399A_SIUL2.h"
#include "Mcu.h"
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

/* Pin setup for QuadSPI on S32G3XX */
#define PG_00   96      /* QSPI_CLK_A    */
#define PG_01   97      /* QSPI_CLK_A_b  */
#define PG_02   98      /* QSPI_CLK_2A   */
#define PG_03   99      /* QSPI_CLK_2A_b */
#define PD_06   54      /* QSPI_CLK_B    */
#define PD_07   55      /* QSPI_CLK_B_b  */

#define PG_04   100     /* QSPI_A Chip Select 0 */
#define PG_05   101     /* QSPI_A Chip Select 1 */
#define PD_00   48      /* QSPI_B Chip Select 0 */
#define PD_01   49      /* QSPI_B Chip Select 1 */

#define PF_05   85      /* QSPOI_A  Data 0 */
#define PF_06   86      /* QSPOI_A  Data 1 */
#define PF_07   87      /* QSPOI_A  Data 2 */
#define PF_08   88      /* QSPOI_A  Data 3 */
#define PF_09   89      /* QSPOI_A  Data 4 */
#define PF_10   90      /* QSPOI_A  Data 5 */
#define PF_11   91      /* QSPOI_A  Data 6 */
#define PF_12   92      /* QSPOI_A  Data 7 */
#define PF_13   93      /* QSPOI_A  Data Strobe Input / FLASH_DATA_STROBE */
#define PF_14   94      /* QSPI A Interrupt */

/* #define A_DQS_IMCR            819 - 512 */
#define IMCR_A0                 (540 - 512)
#define IMCR_A1                 (541 - 512)
#define IMCR_A2                 (542 - 512)
#define IMCR_A3                 (543 - 512)
#define IMCR_A4                 (544 - 512)
#define IMCR_A5                 (545 - 512)
#define IMCR_A6                 (546 - 512)
#define IMCR_A7                 (547 - 512)
#define IMCR_DATA_STROBE_A      (548 - 512)
#define IMCR_QSPI_INTERRUPT_A   (549 - 512)
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
    /*Set up:  QSPI0_A1 : QSPI0_A_SCK/ QSPI0_A_CS0/QSPI0_A_D3 -> QSPI0_A_D0 */
    IP_SIUL2_0->MSCR[PG_00] = 0x00200021U;  /* QSPI_CLK_A     : Enable only OBE; Disable IBE */
    IP_SIUL2_0->MSCR[PG_01] = 0x00200021U;  /* QSPI_CLK_A_b   : Enable only OBE; Disable IBE */
    IP_SIUL2_0->MSCR[PG_02] = 0x00200021U;  /* QSPI_CLK_2A    : Enable only OBE; Disable IBE */
    IP_SIUL2_0->MSCR[PG_03] = 0x00200021U;  /* QSPI_CLK_2A_b  : Enable only OBE; Disable IBE */
    IP_SIUL2_0->MSCR[PD_06] = 0x00200002U;  /* QSPI_CLK_B     : Enable only OBE; Disable IBE */
    IP_SIUL2_0->MSCR[PD_07] = 0x00200002U;  /* QSPI_CLK_B_b   : Enable only OBE; Disable IBE */

    IP_SIUL2_0->MSCR[PG_04] = 0x00203021U;  /* QSPI_A Chip Select 0 Enable only OBE; Disable IBE */
    IP_SIUL2_0->MSCR[PG_05] = 0x00203021U;  /* QSPI_A Chip Select 1 Enable only OBE; Disable IBE */
    IP_SIUL2_0->MSCR[PD_00] = 0x00203002U;  /* QSPI_B Chip Select 0 Enable only OBE; Disable IBE */
    IP_SIUL2_0->MSCR[PD_01] = 0x00203002U;  /* QSPI_B Chip Select 1 Enable only OBE; Disable IBE */

    /* QSPI_A INTERRUPT: ECC error signal, Flash Memory A drives this signal to active low value in case of an ECC error */
    IP_SIUL2_0->MSCR[PF_14] = 0x00083020;  /* Disable OBE; Enable IBE; Enable pull-up */
    IP_SIUL2_0->IMCR[IMCR_QSPI_INTERRUPT_A] = 0x00000002;

    /* QSPI_A FLASH_DATA_STROBE */
    IP_SIUL2_0->MSCR[PF_13] = 0x00280021;
    IP_SIUL2_0->IMCR[IMCR_DATA_STROBE_A] = 0x00000002;

    /* QSPI0_A_D7 2CF701 */
    /* SIUL2.MSCR[PF_08] = 0x00293001; */
    IP_SIUL2_0->MSCR[PF_12] = 0x00280021;
    IP_SIUL2_0->IMCR[IMCR_A7] =  0x00000002;

    /* QSPI0_A_D6 2CF701 */
    /* SIUL2.MSCR[PF_11] = 0x00293001; */
    IP_SIUL2_0->MSCR[PF_11] = 0x00280021;
    IP_SIUL2_0->IMCR[IMCR_A6] = 0x00000002;

    /* QSPI0_A_D5 2CF701 */
    /* SIUL2.MSCR[PF_10] = 0x00293001; */
    IP_SIUL2_0->MSCR[PF_10] = 0x00280021;
    IP_SIUL2_0->IMCR[IMCR_A5] = 0x00000002;

    /* QSPI0_A_D4 2CF701 */
    /* SIUL2.MSCR[PF_09] = 0x00293001; */
    IP_SIUL2_0->MSCR[PF_09] = 0x00280021;
    IP_SIUL2_0->IMCR[IMCR_A4] = 0x00000002;

    /* QSPI0_A_D3 2CF701 */
    /* SIUL2.MSCR[PF_08] = 0x00293001; */
    IP_SIUL2_0->MSCR[PF_08] = 0x00280021;
    IP_SIUL2_0->IMCR[IMCR_A3] = 0x00000002;

    /* QSPI0_A_D2 */
    /* SIUL2.MSCR[PF_07] = 0x00293001; */
    IP_SIUL2_0->MSCR[PF_07] = 0x00280021;
    IP_SIUL2_0->IMCR[IMCR_A2] = 0x00000002;

    /* QSPI0_A_D1 */
    /* SIUL2.MSCR[PF_06] = 0x00293001; */
    IP_SIUL2_0->MSCR[PF_06] = 0x00280021;
    IP_SIUL2_0->IMCR[IMCR_A1] = 0x00000002;

    /* QSPI0_A_D0 */
    /* SIUL2.MSCR[PF_05] = 0x00293001; */
    IP_SIUL2_0->MSCR[PF_05] = 0x00280021;
    IP_SIUL2_0->IMCR[IMCR_A0] = 0x00000002;
}
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Main function of the example
* @details      Initialize the used drivers and uses functionality of Fee driver: write/read block data.
*/
int main(void) 
{
    MemIf_StatusType status = MEMIF_IDLE;

    /* Initialize for clock */
    /* Initialize the Mcu driver */
    Mcu_Init(NULL_PTR);
    Mcu_InitClock(0);
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() )
    {
        /* Busy wait until the System PLL is locked */
    }
    /* Distribute the PLL across the clock tree */
    Mcu_DistributePllClock();
    /* Initialize RM CDD */
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

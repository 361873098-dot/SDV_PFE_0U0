/*
*   (c) Copyright 2020-2021 NXP
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
#include "Adc.h"
#include "Mcu.h"
#include "Mcl.h"
#include "Platform.h"

#include "check_example.h"

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef ADC_GROUPS_BOARD_INITPERIPHERALS
#define ADC_CFGSET_VS_0_GROUP_0_CHANNELS ADC_CFGSET_BOARD_INITPERIPHERALS_GROUP_0_CHANNELS
#define ADC_CFGSET_VS_0_GROUP_1_CHANNELS ADC_CFGSET_BOARD_INITPERIPHERALS_GROUP_1_CHANNELS
#endif

/* Voltage level definition */
#define RESULT_ADC_VREFL        (0u)        /* VrefL is 0V */
#define RESULT_ADC_VREFH        (4096u)     /* VrefH is 1.8V */
#define RESULT_ADC_BANDGAP      (2626u)     /* Vbandgap ~ 1.15V at 1.8V reference */
#define RESULT_ADC_AVDD         (4096u)     /* AVDD corresponds to VDD_ADC. Vavdd is 1.8V */
#define RESULT_ADC_DVDD         (900u)      /* Vdvdd ~ 0.8V at 1.8V reference. This channel is a half of DVDD */
#define RESULT_TOLERANCE        (150u)

/*==================================================================================================
*                                      EXTERN DECLARATIONS
==================================================================================================*/
extern ISR(Adc_Sar_0_Isr);
extern ISR(Ctu_FIFO_Isr);
extern ISR(Dma0_Ch16_Ch31_IrqHandler);

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
Adc_ValueGroupType    ResultBuffer0[6] =  {0xaaaa, 0xaaaa, 0xaaaa, 0xaaaa, 0xaaaa, 0xaaaa};
uint16                CtuFifoResult[6] =  {0};
/* Used for ReadGroup */
Adc_ValueGroupType    AdcReadGroupBuffer0[6] =  {0xbbbb, 0xbbbb, 0xbbbb, 0xbbbb, 0xbbbb, 0xbbbb};
Adc_ValueGroupType    AdcReadGroupBufferDma[6] =  {0xbbbb, 0xbbbb, 0xbbbb, 0xbbbb, 0xbbbb, 0xbbbb};
const uint32 AdcExpectedValue[5] = {RESULT_ADC_VREFL, RESULT_ADC_VREFH, RESULT_ADC_BANDGAP, RESULT_ADC_AVDD, RESULT_ADC_DVDD};

#define ADC_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#include "Adc_MemMap.h"
__attribute__(( aligned(32) )) Adc_ValueGroupType    ResultBufferDma[6] =  {0xaaaa, 0xaaaa, 0xaaaa, 0xaaaa, 0xaaaa, 0xaaaa};
#define ADC_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#include "Adc_MemMap.h"

volatile uint32 VarNotification_0 = 0;
volatile uint32 VarNotification_1 = 0;
volatile uint32 CtuFifoThresholdNotif = 0;

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

boolean CheckResult(uint32 Result, uint32 Reference, uint32 Tolerance)
{
    boolean Status = FALSE;
    if(Result > Reference)
    {
        if((Result - Reference) < Tolerance)
        {
            Status = TRUE;
        }
    }
    else
    {
        if((Reference - Result) < Tolerance)
        {
            Status = TRUE;
        }
    }

    return Status;
}

void Notification_0(void)
{
    VarNotification_0++;
}
void Notification_1(void)
{
    VarNotification_1++;
}
void Notification_WDG_0(const uint8 Flags)
{
    (void)Flags;
}
void Notification_WDG_1(const uint8 Flags)
{
    (void)Flags;
}

#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
void Fifo0ThresholdNotification(void)
{
    CtuFifoThresholdNotif++;
    Adc_CtuReadFifoData(ADC_IPW_CTU_UNIT_USED, CtuFifoResult, 6);
}

void Fifo1ThresholdNotification(void){}
void Fifo2ThresholdNotification(void){}
void Fifo3ThresholdNotification(void){}
#endif /* (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) */


int main(void)
{
    Std_ReturnType StdReturn = E_NOT_OK;
    boolean bLocalStatus = TRUE;
    boolean bStatus = TRUE;
    Adc_CalibrationStatusType CalibStatus;
    uint8 i;
    uint8 Index;

    /* Initialize Mcu Driver */
 #if (MCU_PRECOMPILE_SUPPORT == STD_ON)
    Mcu_Init(NULL_PTR);
#else
    Mcu_Init(&Mcu_Config_VS_0);
#endif
    Mcu_InitClock(McuClockSettingConfig_0);
    while(MCU_PLL_LOCKED != Mcu_GetPllStatus())
    {
        /* Busy wait until the System PLL is locked */
    }
    Mcu_DistributePllClock();
    Mcu_SetMode(McuModeSettingConf_0);

    /* Initialize Platform Driver */
    Platform_Init(NULL_PTR);
    Platform_InstallIrqHandler(SAR_ADC0_INT_IRQn, Adc_Sar_0_Isr, NULL_PTR);
    Platform_InstallIrqHandler(CTU_FIFO_FULL_EMPTY_IRQn, Ctu_FIFO_Isr, NULL_PTR);
    Platform_InstallIrqHandler(DMA0_16_31_IRQn, Dma0_Ch16_Ch31_IrqHandler, NULL_PTR);
    Platform_SetIrq(SAR_ADC0_INT_IRQn, TRUE);
    Platform_SetIrq(CTU_FIFO_FULL_EMPTY_IRQn, TRUE);
    Platform_SetIrq(DMA0_16_31_IRQn, TRUE);

    /* Initialize Mcl Driver */
    Mcl_Init(NULL_PTR);

#if (ADC_PRECOMPILE_SUPPORT == STD_ON)
    Adc_Init(NULL_PTR);
#else
    Adc_Init(&Adc_Config_VS_0);
#endif /* (ADC_PRECOMPILE_SUPPORT == STD_ON) */

    /* Part 1: Example with SW Triggered One-Shot Conversion Mode, data conversion is updated by Interrupt.*/
    /*******************************************************************************************************/
    Adc_Calibrate(AdcHwUnit_0, &CalibStatus);
    if(CalibStatus.AdcUnitSelfTestStatus == E_NOT_OK)
    {
        bStatus = FALSE;
    }
    /* ResultBuffer0 is updated new data in Adc_Sar_0_Isr handler */
    Adc_SetupResultBuffer(AdcGroup_0, ResultBuffer0);
    Adc_EnableGroupNotification(AdcGroup_0);

    for(Index = 0; Index < 10; Index++)
    {
        VarNotification_0 = 0;
        Adc_StartGroupConversion(AdcGroup_0);

        /* Check if notification is called */
        while(VarNotification_0 == 0)
        {}

        StdReturn = Adc_ReadGroup(AdcGroup_0, AdcReadGroupBuffer0);
        if(E_OK != StdReturn)
        {
            bStatus = FALSE;
        }
        /* Check converted results */
        if((ResultBuffer0[0] != AdcReadGroupBuffer0[0]) || \
           (ResultBuffer0[1] != AdcReadGroupBuffer0[1]) || \
           (ResultBuffer0[2] != AdcReadGroupBuffer0[2]) || \
           (ResultBuffer0[3] != AdcReadGroupBuffer0[3]) || \
           (ResultBuffer0[4] != AdcReadGroupBuffer0[4]) || \
           (ResultBuffer0[5] != 0xaaaa) || \
           (AdcReadGroupBuffer0[5] != 0xbbbb) \
          )
        {
            bStatus = FALSE;
        }
        for (i = 0; i < ADC_CFGSET_VS_0_GROUP_0_CHANNELS; i++)
        {
            bLocalStatus = CheckResult(ResultBuffer0[i], AdcExpectedValue[i], RESULT_TOLERANCE);
            if(FALSE == bLocalStatus)
            {
                bStatus = FALSE;
            }
        }
    }

    /* Part 2: Example with SW Triggered One-Shot Conversion Mode, data conversion is updated by DMA.*/
    /*************************************************************************************************/
    Adc_Calibrate(AdcHwUnitDma, &CalibStatus);
    if(CalibStatus.AdcUnitSelfTestStatus == E_NOT_OK)
    {
        bStatus = FALSE;
    }

    /* ResultBufferDma is updated new data by DMA Transferring */
    Adc_SetupResultBuffer(AdcSwGroupWithDma, ResultBufferDma);
    Adc_EnableGroupNotification(AdcSwGroupWithDma);

    for(Index = 0; Index < 10; Index++)
    {
        VarNotification_1 = 0;
        Adc_StartGroupConversion(AdcSwGroupWithDma);
        /* Check if notification is called */
        while(VarNotification_1 == 0)
        {}

        StdReturn = Adc_ReadGroup(AdcSwGroupWithDma, AdcReadGroupBufferDma);
        if(E_OK != StdReturn)
        {
            bStatus = FALSE;
        }
        /* Check converted results */
        if((ResultBufferDma[0] != AdcReadGroupBufferDma[0]) || \
           (ResultBufferDma[1] != AdcReadGroupBufferDma[1]) || \
           (ResultBufferDma[2] != AdcReadGroupBufferDma[2]) || \
           (ResultBufferDma[3] != AdcReadGroupBufferDma[3]) || \
           (ResultBufferDma[4] != AdcReadGroupBufferDma[4]) || \
           (ResultBufferDma[5] != 0xaaaa) || \
           (AdcReadGroupBufferDma[5] != 0xbbbb) \
          )
        {
            bStatus = FALSE;
        }
        for (i = 0; i < ADC_CFGSET_VS_0_GROUP_1_CHANNELS; i++)
        {
            bLocalStatus = CheckResult(ResultBufferDma[i], AdcExpectedValue[i], RESULT_TOLERANCE);
            if(FALSE == bLocalStatus)
            {
                bStatus = FALSE;
            }
        }
    }

    /* Part 3: CTU Control Mode Example by Interrupt.*/
    /********************************************************************************************/
    Adc_EnableCtuControlMode(AdcHwUnit_0);
    /* Sw trigger MRS to load all double-buffered registers and start a new CTU control cycle.
     * The internal trigger will start the ADC command list when the CTU counter reaches the trigger compare value. */
    Adc_CtuMasterReload(ADC_IPW_CTU_UNIT_USED);
    /* Check if notification is called */
    while(CtuFifoThresholdNotif == 0)
    {}
    /* Verify data conversion in FIFO */
    if(0 != CtuFifoResult[5])
    {
        bStatus = FALSE;
    }

    Adc_DisableCtuControlMode(AdcHwUnit_0);

    Adc_DeInit();

    Exit_Example(bStatus);

    return 0;
}


#ifdef __cplusplus
}
#endif

/** @} */

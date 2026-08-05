/*==================================================================================================
* (c) Copyright 2020-2021 NXP
* All Rights Reserved.
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

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
#include "IntCtrl_Ip.h"
#include "Adc_Sar_Ip.h"
#include "Ctu_Ip.h"

#define ADC_SAR_USED_CH 32U /* Internal Bandgap Channel */
#define CTU_USED_FIFO_IDX 0U
#define CTU_FIFO_THRESHOLD 3U
#define ADC_BANDGAP 2626U /* Vbandgap ~ 1.15V at 1.8V reference */
#define ADC_TOLERANCE(x,y) ((x > y) ? (x - y) : (y - x))

volatile int exit_code = 0;
volatile boolean notif_triggered = FALSE;

uint16 data;
uint8 idx;

extern void Adc_Sar_0_Isr(void);
extern void Ctu_FIFO_Isr(void);

void AdcEndOfChainNotif(void)
{
    notif_triggered = TRUE;
    data = Adc_Sar_Ip_GetConvData(ADCHWUNIT_0_VS_0_INSTANCE, ADC_SAR_USED_CH);
    /* Checks the measured ADC data conversion */
    while (ADC_TOLERANCE(data, ADC_BANDGAP) > 100U);
}

void CtuThresholdNotif(void)
{
    notif_triggered = TRUE;
    for (idx = 0; idx < CTU_FIFO_THRESHOLD; idx++)
    {
        Ctu_Ip_GetFifoData(CTUHWUNIT_0_VS_0_INSTANCE, CTU_USED_FIFO_IDX, CTU_IP_RESULT_ALIGN_RIGHT_UNSIGNED, CTU_FIFO_THRESHOLD, &data);
        (void)data;
    }
}

int main(void)
{
    StatusType status;
    Clock_Ip_StatusType clockStatus;

    /* Initialize and configure drivers */
    clockStatus = Clock_Ip_Init(&Mcu_aClockConfigPB[0]);

    while (clockStatus != CLOCK_IP_SUCCESS)
    {
    	clockStatus = Clock_Ip_Init(&Mcu_aClockConfigPB[0]);
    }

    Ctu_Ip_Init(CTUHWUNIT_0_VS_0_INSTANCE, &CtuHwUnit_0_VS_0);
    status = (StatusType) Adc_Sar_Ip_Init(ADCHWUNIT_0_VS_0_INSTANCE, &AdcHwUnit_0_VS_0);
    while (status != E_OK)
    {
        status = (StatusType) Adc_Sar_Ip_Init(ADCHWUNIT_0_VS_0_INSTANCE, &AdcHwUnit_0_VS_0);
    }

    /* Install and enable interrupt handlers */
    IntCtrl_Ip_InstallHandler(SAR_ADC0_INT_IRQn, Adc_Sar_0_Isr, NULL_PTR);
    IntCtrl_Ip_InstallHandler(CTU_FIFO_FULL_EMPTY_IRQn, Ctu_FIFO_Isr, NULL_PTR);
    IntCtrl_Ip_EnableIrq(SAR_ADC0_INT_IRQn);
    IntCtrl_Ip_EnableIrq(CTU_FIFO_FULL_EMPTY_IRQn);

    /* Calibrate ADC */
    status = (StatusType) Adc_Sar_Ip_DoCalibration(ADCHWUNIT_0_VS_0_INSTANCE);
    while (status != E_OK)
    {
        status = (StatusType) Adc_Sar_Ip_DoCalibration(ADCHWUNIT_0_VS_0_INSTANCE);
    }

    /**** Part 1: Start ADC_SAR SW normal and Injected conversions ****/

    Adc_Sar_Ip_EnableNotifications(ADCHWUNIT_0_VS_0_INSTANCE, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN | ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN);

    /* Start a SW triggered normal conversion on ADC_SAR */
    Adc_Sar_Ip_StartConversion(ADCHWUNIT_0_VS_0_INSTANCE, ADC_SAR_IP_CONV_CHAIN_NORMAL);

    /* Wait for the notification to be triggered and read the data */
    while (notif_triggered != TRUE);
    notif_triggered = FALSE;

    /* Start a SW triggered injected conversion on ADC_SAR */
    Adc_Sar_Ip_StartConversion(ADCHWUNIT_0_VS_0_INSTANCE, ADC_SAR_IP_CONV_CHAIN_INJECTED);

    /* Wait for the notification to be triggered and read the data */
    while (notif_triggered != TRUE);
    notif_triggered = FALSE;

    /**** Part 2: Start CTU conversion list by enabling SW master reload ****/

    /* Mark that writes to double-buffered configuration registers have ended. */
    (void)Ctu_Ip_SetGeneralReloadEnable(CTUHWUNIT_0_VS_0_INSTANCE, TRUE);
    /* Sw trigger MRS to load all double-buffered registers and start a new CTU control cycle.
     * The internal trigger will start the ADC command list when the CTU counter reaches the trigger compare value. */
    Ctu_Ip_SwMasterReload(CTUHWUNIT_0_VS_0_INSTANCE);

    /* Wait for the threshold notification to be triggered and then read the data */
    while (notif_triggered != TRUE);

    /* De-initialize drivers */
    Ctu_Ip_Deinit(CTUHWUNIT_0_VS_0_INSTANCE);
    status = (StatusType) Adc_Sar_Ip_Deinit(ADCHWUNIT_0_VS_0_INSTANCE);
    while (status != E_OK)
    {
        status = (StatusType) Adc_Sar_Ip_Deinit(ADCHWUNIT_0_VS_0_INSTANCE);
    }

    for(;;)
    {
        if(exit_code != 0)
        {
            break;
        }
    }
    return exit_code;
}

#ifdef __cplusplus
}
#endif

/** @} */

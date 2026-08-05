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
#include "SchM_Ocotp.h"
#include "CDD_Ocotp.h"
#include "Mcal.h"
#include "check_example.h"
#include "S32G399A.h"
#include "Mcu.h"
#include "Port.h"
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define DATA_TEST_0       25U
#define DATA_TEST_1       0U
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

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Example for Ocotp
* @details      Programming the fuses should be followed steps :
*                1. Program the shadow register with the intended fuse value. If the functionality
*                is as expected then proceed with next steps.
*                2. Program the fuse with the above fuse value. If you want ECC protect for this
*                eFuse, you need enable ECC in channel configuration. You must sure that eFuse has not
*                yet been protected ECC before.
*                   Also you can set write/read Lock Protect in channel configuration. In case there are other fuse
*                words with same lock, then the fuse lock should be programmed after the last word.
*
*               In this example for Ocotp, we will take steps
*                1. Write to GP6_127_96 , GP6_159_128 Shadow registers.
*                2. Write to eFuse GP6_127_96.
*                3. Implement CRC test for GP6_127_96, GP6_159_128 on CRC0.
*/
int main(void)
{
    Std_ReturnType result;
    uint32 u32DataCheck;
   /* Data array which user want it is tested CRC */
    uint32 u32DataIsTestedCRC[2] = {DATA_TEST_0, DATA_TEST_1};

    /* Initialize the Mcu driver */
    Mcu_Init(NULL_PTR);
    /* Initialize the clock tree and apply PLL as system clock */
    Mcu_InitClock(McuClockSettingConfig_0);
    /* Apply a mode configuration */
    Mcu_SetMode(McuModeSettingConf_0);

    /* Initialize Port driver to set GPIO25 pin to enable VDD_EFUSE */
    Port_Init(NULL_PTR);

    /* Initialize Ocotp driver */
    Ocotp_Init(NULL_PTR);
    /* Step 1: Program the shadow registers with the intended fuse value. If the functionality is as expected then proceed with next steps.*/
    /* Write Shadow GP6_127_96 */
    Ocotp_WriteShadowRegister(OcotpConf_OcotpChannelConfiguration_OcotpChannel_0, DATA_TEST_0);
    /* Write Shadow GP6_159_128 */
    Ocotp_WriteShadowRegister(OcotpConf_OcotpChannelConfiguration_OcotpChannel_1, DATA_TEST_1);

    /* Step 2: Program the fuse with the above fuse value. If you want ECC protect for this eFuse Word, you
    need enable ECC in channel config. You must sure that eFuse has not yet been protected ECC before.
    Also you can set Read/Write Lock protect for eFuse/Shadown in channel config */
    /* Warning : Each eFuse bit cannot be cleared if set to 1 */
    /* Write data to GP6_127_96 */
    result = Ocotp_WriteEFuse(OcotpConf_OcotpChannelConfiguration_OcotpChannel_0, DATA_TEST_0);
    if(result != E_OK)
    {
        Exit_Example(FALSE);
        return (1U);
    }

    /* Step 3: Implement CRC test */
    /*In this example, we check CRC for GP6_127_96 and GP6_159_128*/
    /* Calculate And Write Crc Value from u32DataIsTestedCRC array to CRC0 eFuse */
    /*Warning : Each eFuse bit cannot be cleared if set to 1 */
    result = Ocotp_CalculateAndWriteCrcValue(OcotpConf_OcotpChannelConfiguration_OcotpChannel_2, u32DataIsTestedCRC, (uint32)2U);
    if(result != E_OK)
    {
        Exit_Example(FALSE);
        return (1U);
    }
    /* Update value CRC0 eFuse to CRC0 Shadow register. If MCU reset, you dont need update value for Shadow register*/
    Ocotp_ReadEFuse(OcotpConf_OcotpChannelConfiguration_OcotpChannel_2, &u32DataCheck);
    Ocotp_WriteShadowRegister(OcotpConf_OcotpChannelConfiguration_OcotpChannel_2, u32DataCheck);

    /* Test CRC */
    result = Ocotp_CrcValidate(OcotpConf_OcotpChannelConfiguration_OcotpChannel_2);
    /* Check result */
     if(result != E_OK)
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

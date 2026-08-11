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
#include "Ocotp_Ip.h"
#include "Ocotp_Ip_Types.h"
#include "check_example.h"
#include "Clock_Ip.h"
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define OCOTP_GP6_127_96                      0x384U
#define OCOTP_GP6_159_128                     0x388U
#define OCOTP_GP6_127_96_SHADOW_REGISTER      97U
#define OCOTP_GP6_159_128_SHADOW_REGISTER     98U
#define CRC0_EFUSE_ADD                        0x2DCU
#define CRC0_SHADOW_REGISTER                  55U
#define DATA_TEST_0                           25U
#define DATA_TEST_1                           0U
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
*               1. Program the shadow register with the intended fuse value. If the functionality
*               is as expected then proceed with next steps.
*               2. Program the fuse with the above fuse value. If you want ECC protect for this
*               eFuse, you need enable ECC in channel config. You must sure that eFuse has not yet
*               been protected ECC before.
*               3. Program the fuses lock so that fuses are protected from any spurious writes, in
*               case there are other fuse words with same lock, then the fuse lock should be
*               programmed after the last word.
*
*               In this example for Ocotp, we will take steps
*                1. Write to GP6_127_96 , GP6_159_128 Shadow registers.
*                2. Write to eFuse GP6_127_96.
*                4. Implement CRC test for GP6_127_96, GP6_159_128 on CRC2.
*
*/
int main(void)
{
    Ocotp_Ip_StatusType result;
    uint32 u32Data;
    /* Data array which user want it is tested CRC */
    uint32 u32DataIsTestedCRC[2] = {DATA_TEST_0, DATA_TEST_1};
    const uint32 instance_Cfg0 = Ocotp_ConfigSet_pHwConfig.ocotpInstance ;

    /* Initialize for clock */
    Clock_Ip_Init(Mcu_aClockConfigPB);

    /* Initialize Ocotp driver */
    Ocotp_Ip_Init(&Ocotp_ConfigSet_pHwConfig);
    /* Step 1. Program the shadow register with the intended fuse value. If the functionality is as expected then proceed with next steps.*/
    /* Write Shadow OCOTP_GP6_127_96 */
    Ocotp_Ip_WriteShadowRegister(instance_Cfg0, OCOTP_GP6_127_96_SHADOW_REGISTER, DATA_TEST_0);
    /* Write Shadow OCOTP_GP6_159_128 */
    Ocotp_Ip_WriteShadowRegister(instance_Cfg0, OCOTP_GP6_159_128_SHADOW_REGISTER, DATA_TEST_1);

    /* Step 2. Program the fuse with the above fuse value. If you want ECC protect for this eFuse, you
    need enable ECC in input parameter. You must sure that eFuse has not yet been protected ECC before.*/
    /*Warning : Each eFuse bit cannot be cleared if set to 1 */
    /* Write data to OCOTP_GP6_127_96 */
    result = Ocotp_Ip_WriteEFuse(instance_Cfg0, OCOTP_GP6_127_96, DATA_TEST_0, false, true);
    if(result != STATUS_OCOTP_IP_SUCCESS)
    {
        Exit_Example(FALSE);
        return (1U);
    }

    /* Step 3: Implement CRC test */
    /*In this example, we check CRC for GP6_127_96 , GP6_159_128*/
    /* Calculate And Write Crc Value from u32DataIsTestedCRC array to CRC0 eFuse */
    /*Warning : Each eFuse bit cannot be cleared if set to 1 */
    result = Ocotp_Ip_CalculateAndWriteCrcValue(instance_Cfg0, CRC0_EFUSE_ADD, u32DataIsTestedCRC, (uint32)2U);
    if(result != STATUS_OCOTP_IP_SUCCESS)
    {
        Exit_Example(FALSE);
        return (1U);
    }
    /*Update value CRC0 eFuse to CRC0 Shadow register. If MCU reset, you dont need this step*/
    Ocotp_Ip_ReadEFuse(instance_Cfg0, CRC0_EFUSE_ADD, &u32Data);
    Ocotp_Ip_WriteShadowRegister(instance_Cfg0, CRC0_SHADOW_REGISTER, u32Data);

    /* Test CRC */
    result = Ocotp_Ip_CrcTest(instance_Cfg0, CRC0_EFUSE_ADD, OCOTP_GP6_127_96, OCOTP_GP6_159_128);
    /* Check result */
     if(result != STATUS_OCOTP_IP_SUCCESS)
    {
        Exit_Example(FALSE);
        return (1U);
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

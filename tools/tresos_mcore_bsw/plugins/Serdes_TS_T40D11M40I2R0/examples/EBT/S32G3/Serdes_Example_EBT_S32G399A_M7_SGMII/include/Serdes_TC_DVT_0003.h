/**
*   @file    Serdes_TC_0003.h
*   @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
*
*   @brief   AUTOSAR M4_SRC_MODULE_NAME - test case 0003.
*   @details test case 0003. Ethernet transmission in loopback
*
*   @addtogroup SERDES_TESTS
*   @{
*/
/*==================================================================================================
*   Project              : M4_SRC_PROJECT_NAME
*   Platform             : M4_SRC_MCU_FAMILY
*   Peripheral           : M4_SRC_USED_PERIPHERAL
*   Dependencies         : M4_SRC_AR_MODULE_DEPENDENCY
*
*   Autosar Version      : M4_SRC_AR_SPEC_VERSION_MAJOR.M4_SRC_AR_SPEC_VERSION_MINOR.M4_SRC_AR_SPEC_VERSION_PATCH
*   Autosar Revision     : M4_SRC_AR_RELEASE_REVISION
*   Autosar Conf.Variant :
*   SW Version           : M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
*   Build Version        : M4_SRC_BUILD_ID
*
*   Copyright M4_SRC_YEAR_ID M4_SRC_COPYRIGHTED_TO

==================================================================================================*/

#ifndef SERDES_TC_DVT_0003_H
#define SERDES_TC_DVT_0003_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Eunit.h"
#include "Serdes_TC_Common.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define TEST_MCU_CORE_PLL_RFE           (1U<<0U)
#define TEST_MCU_CORE_PLL_LOCK          (1U<<1U)
#define TEST_MCU_SYS_CLK_CORE_PLL       (1U<<2U)
#define TEST_MCU_GMAC_SGMII_RX          (1U<<3U)
#define TEST_MCU_GMAC_SGMII_TX          (1U<<4U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
typedef enum {
    VALIDATION_RES = -2,
    VALIDATION_CGM_NULL = -1,
    VALIDATION_FIRC_CLK = 69,
    VALIDATION_FIRC_MUXED_CLK = 0,
    VALIDATION_FXOSC_CLK = 2,
    VALIDATION_RFE_CLOCK_PLL = 68,
    VALIDATION_CORE_PLL_PHI0 = 4,
    VALIDATION_CORE_PLL_PHI1 = 5,
    VALIDATION_CORE_PLL_PHI2 = 6,
    VALIDATION_CORE_PLL_PHI3 = 7,
    VALIDATION_CORE_PLL_PHI4 = 8,
    VALIDATION_CORE_PLL_PHI5 = 9,
    VALIDATION_CORE_PLL_PHI6 = 10,
    VALIDATION_CORE_PLL_PHI7 = 11,
    VALIDATION_CORE_PLL_PHI8 = 12,
    VALIDATION_CORE_PLL_PHI9 = 13,
    VALIDATION_PERIPH_PLL_PHI8 = 15,
    VALIDATION_PERIPH_PLL_PHI9 = 16,
    VALIDATION_PERIPH_PLL_PHI0 = 18,
    VALIDATION_PERIPH_PLL_PHI1 = 19,
    VALIDATION_PERIPH_PLL_PHI2 = 20,
    VALIDATION_PERIPH_PLL_PHI3 = 21,
    VALIDATION_PERIPH_PLL_PHI4 = 22,
    VALIDATION_PERIPH_PLL_PHI5 = 23,
    VALIDATION_PERIPH_PLL_PHI6 = 24,
    VALIDATION_PERIPH_PLL_PHI7 = 25,
    VALIDATION_FTM_0_EXT_REF = 34,
    VALIDATION_GMAC_0_EXT_TX = 37,
    VALIDATION_GMAC_0_EXT_RX = 38,
    VALIDATION_GMAC_0_EXT_REF = 39,
    VALIDATION_GMAC_0_EXT_TS = 44,
    VALIDATION_GMAC_0_REF_DIV = 45,
    VALIDATION_TEST_CLK_MUX_CLKOUT0 = 46,
    VALIDATION_TEST_CLK_MUX_CLKOUT1 = 47,
    VALIDATION_AURORA_PLL_PHI1 = 50,
    VALIDATION_GMAC_0_SGMII_TX = 59,
    VALIDATION_GMAC_0_SGMII_RX = 60,
    VALIDATION_GMAC_0_SGMII_REF = 61,
    VALIDATION_RFE_SPI_EXT_SCLK = 63,
}clk_sources_t;

typedef enum{
    VALIDATION_CLK_SW_OPERATION_WAS_NOT_REQUESTED = 0,
    VALIDATION_CLK_SW_OPERATION_WAS_REQUESTED = 1,
}clksw_status_t;

typedef enum{
    VALIDATION_SWITCHING_COMPLETED	= 0,
    VALIDATION_SWITCHING_IN_PROGRESS = 1,
}swip_status_t;

typedef enum{
    VALIDATION_NO_CLOCK_SWITCH_REQUEST_PENDING	= 0,
    VALIDATION_CLOCK_SWITCH_REQUEST = 1,
}clk_sw_bit_t;

typedef union
{
    uint8 R;
    struct {
        uint8 COREPLL_RFE:1;
        uint8 COREPLL_PLL_LOCK:1;
        uint8 SYSCLK_COREPLL:1;
        uint8 GMAC_SGMII_RX:1;
        uint8 GMAC_SGMII_TX:1;
        uint8 __unused_3:3;
    } B;
}test_mcu_flags_type;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
void Serdes_TC_DVT_0003(void);


#ifdef __cplusplus
}
#endif

#endif  /* SERDES_TC_DVT_0003_H */

/** @} */

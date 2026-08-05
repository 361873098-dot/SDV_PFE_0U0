/*==================================================================================================
* Project : RTD AUTOSAR 4.4
* Platform : CORTEXM
* Peripheral : 
* Dependencies : none
*
* Autosar Version : 4.4.0
* Autosar Revision : ASR_REL_4_4_REV_0000
* Autosar Conf.Variant :
* SW Version : 4.0.2
* Build Version : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
* Copyright 2020-2023 NXP Semiconductors
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

/**
*   @file       Clock_Ip_PBcfg.c
*   @version    4.0.2
*
*   @brief   AUTOSAR Mcu - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup CLOCK_DRIVER_CONFIGURATION Clock Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "Clock_Ip_Private.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_PBCFG_VENDOR_ID_C                      43
#define CLOCK_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C       4
#define CLOCK_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_PBCFG_SW_MAJOR_VERSION_C               4
#define CLOCK_IP_PBCFG_SW_MINOR_VERSION_C               0
#define CLOCK_IP_PBCFG_SW_PATCH_VERSION_C               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and StandardTypes.h file are of the same Autosar version */
#if ((CLOCK_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_PBcfg.c and StandardTypes.h are different"
#endif
#endif    /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if source file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_PBCFG_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_PBcfg.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if source file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_PBcfg.c and Clock_Ip_Private.h are different"
#endif

/* Check if source file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_PBCFG_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_PBCFG_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_PBCFG_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_PBcfg.c and Clock_Ip_Private.h are different"
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"


/* *************************************************************************
 * Configuration structure for Clock Configuration 
 * ************************************************************************* */
const Clock_Ip_ClockConfigType Mcu_aClockConfigPB[1] = {

    /*! @brief User Configuration structure clock_Cfg_0 */
    {
        0U,                          /* clkConfigId */

        0U,                       /* ircoscsCount */
        1U,                       /* xoscsCount */
        4U,                       /* pllsCount */
        23U,                       /* selectorsCount */
        28U,                       /* dividersCount */
        0U,                       /* dividerTriggersCount */
        12U,                       /* fracDivsCount */
        13U,                       /* extClksCount */
        3U,                       /* gatesCount */
        0U,                       /* pcfsCount */
        26U,                       /* cmusCount */
        4U,                       /* configureFrequenciesCount */


        /* IRCOSC initialization. */
        {
            {
                RESERVED_CLK,           /* name */
                0U,                     /* enable */
                0U,                     /* Enable regulator */
                0U,                     /* Ircosc range */
                0U,                     /* Ircosc enable in VLP mode */
                0U,                     /* Ircosc enable in STOP mode */
            },

            {
                RESERVED_CLK,           /* name */
                0U,                     /* enable */
                0U,                     /* Enable regulator */
                0U,                     /* Ircosc range */
                0U,                     /* Ircosc enable in VLP mode */
                0U,                     /* Ircosc enable in STOP mode */
            },

        },

        /* XOSC initialization. */
        {
            #if CLOCK_IP_XOSCS_NO > 0U
            {
                FXOSC_CLK,              /* Clock name associated to xosc */
                40000000U,              /* External oscillator frequency. */ 
                1U,                     /* Enable xosc. */
                157U,                    /* Startup stabilization time */
                0U,                     /* bypassOption: Xosc use crystal */ 
                1U,                     /* Comparator is enabled */ 
                12U,                    /* TransConductance */
                0U,                     /* Gain value */
                0U,                     /* Monitor type */
                0U,                     /* Automatic level controller */
            },
            #endif
        },


        /* PLL initialization. */
        {
            #if CLOCK_IP_PLLS_NO > 0U
            {
                COREPLL_CLK,                /* name */
                1U,                     /* enable */
                FXOSC_CLK,                     /* inputReference */
                0U,                     /* Bypass */
                1U,                      /* predivider */
                0U,                     /* numeratorFracLoopDiv */
                40U,                   /* mulFactorDiv */
                1U,                     /* ModulationBypass */
                0U,                     /* Modulation type: Spread spectrum modulation bypassed */ 
                0U,                     /* modulationPeriod */
                0U,                     /* incrementStep */
                0U,                     /* sigmaDelta */
                0U,                     /* ditherControl */
                0U,                     /* ditherControlValue */
                0U,                    /* Monitor type */
                {                      /* Dividers */
                        0U,
                        0U,
                        0U,
                },
            },
            #endif

            #if CLOCK_IP_PLLS_NO > 1U
            {
                PERIPHPLL_CLK,                /* name */
                1U,                     /* enable */
                FXOSC_CLK,                     /* inputReference */
                0U,                     /* Bypass */
                1U,                      /* predivider */
                0U,                     /* numeratorFracLoopDiv */
                50U,                   /* mulFactorDiv */
                0U,                     /* ModulationBypass */
                0U,                     /* Modulation type: Spread spectrum modulation bypassed */
                0U,                     /* modulationPeriod */
                0U,                     /* incrementStep */
                0U,                     /* sigmaDelta */
                0U,                     /* ditherControl */
                0U,                     /* ditherControlValue */
                0U,                    /* Monitor type */
                {                      /* Dividers */
                        0U,
                        0U,
                        0U,
                },
            },
            #endif

            #if CLOCK_IP_PLLS_NO > 2U
            {
                DDRPLL_CLK,                /* name */
                1U,                     /* enable */
                FXOSC_CLK,                     /* inputReference */
                0U,                     /* Bypass */
                1U,                      /* predivider */
                0U,                     /* numeratorFracLoopDiv */
                40U,                   /* mulFactorDiv */
                1U,                     /* ModulationBypass */
                0U,                     /* Modulation type: Spread spectrum modulation bypassed */ 
                0U,                     /* modulationPeriod */
                0U,                     /* incrementStep */
                0U,                     /* sigmaDelta */
                0U,                     /* ditherControl */
                0U,                     /* ditherControlValue */
                0U,                    /* Monitor type */
                {                      /* Dividers */
                        0U,
                        0U,
                        0U,
                },
            },
            #endif

            #if CLOCK_IP_PLLS_NO > 3U
            {
                ACCELPLL_CLK,                /* name */
                1U,                     /* enable */
                FXOSC_CLK,                     /* inputReference */
                0U,                     /* Bypass */
                1U,                      /* predivider */
                0U,                     /* numeratorFracLoopDiv */
                60U,                   /* mulFactorDiv */
                1U,                     /* ModulationBypass */
                0U,                     /* Modulation type: Spread spectrum modulation bypassed */ 
                0U,                     /* modulationPeriod */
                0U,                     /* incrementStep */
                0U,                     /* sigmaDelta */
                0U,                     /* ditherControl */
                0U,                     /* ditherControlValue */
                0U,                    /* Monitor type */
                {                      /* Dividers */
                        0U,
                        0U,
                        0U,
                },
            },
            #endif

        },



        /* SELECTOR initialization. */
        {

            #if CLOCK_IP_SELECTORS_NO > 0U
            {
                XBAR_2X_CLK,                    /* Clock name associated to selector */
                CORE_PLL_DFS1_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 1U
            {
                CLKOUT0_CLK,                    /* Clock name associated to selector */
                FXOSC_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 2U
            {
                CLKOUT1_CLK,                    /* Clock name associated to selector */
                FXOSC_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 3U
            {
                PER_CLK,                    /* Clock name associated to selector */
                FIRC_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 4U
            {
                FLEXTIMERA_CLK,                    /* Clock name associated to selector */
                FIRC_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 5U
            {
                FLEXTIMERB_CLK,                    /* Clock name associated to selector */
                FIRC_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 6U
            {
                FLEXRAY_CLK,                    /* Clock name associated to selector */
                FIRC_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 7U
            {
                FLEXCAN_CLK,                    /* Clock name associated to selector */
                FIRC_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 8U
            {
                LIN_BAUD_CLK,                    /* Clock name associated to selector */
                FIRC_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 9U
            {
                GMAC_TS_CLK,                    /* Clock name associated to selector */
                FIRC_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 10U
            {
                GMAC0_TX_CLK,                    /* Clock name associated to selector */
                FIRC_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 11U
            {
                GMAC0_RX_CLK,                    /* Clock name associated to selector */
                FIRC_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 12U
            {
                QSPI_2X_CLK,                    /* Clock name associated to selector */
                FIRC_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 13U
            {
                SDHC_CLK,                    /* Clock name associated to selector */
                FIRC_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 14U
            {
                GMAC0_REF_CLK,                    /* Clock name associated to selector */
                FIRC_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 15U
            {
                SPI_CLK,                    /* Clock name associated to selector */
                FIRC_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 16U
            {
                A53_CORE_CLK,                    /* Clock name associated to selector */
                FIRC_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 17U
            {
                ACCEL3_CLK,                    /* Clock name associated to selector */
                FIRC_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 18U
            {
                ACCEL4_CLK,                    /* Clock name associated to selector */
                FIRC_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 19U
            {
                GMAC1_TX_CLK,                    /* Clock name associated to selector */
                FIRC_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 20U
            {
                GMAC1_REF_DIV_CLK,                    /* Clock name associated to selector */
                FIRC_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 21U
            {
                GMAC1_RX_CLK,                    /* Clock name associated to selector */
                FIRC_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 22U
            {
                DDR_CLK,                    /* Clock name associated to selector */
                DDR_PLL_PHI0_CLK,                    /* Name of the selected input source */
            },
            #endif
        },


        /* DIVIDER initialization. */
        {

            #if CLOCK_IP_DIVIDERS_NO > 0U
            {
                CORE_PLL_PHI0_CLK,                    /* name */
                4U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 1U
            {
                CORE_PLL_PHI1_CLK,                    /* name */
                20U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 2U
            {
                PERIPH_PLL_PHI0_CLK,                    /* name */
                16U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 3U
            {
                PERIPH_PLL_PHI1_CLK,                    /* name */
                25U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 4U
            {
                PERIPH_PLL_PHI2_CLK,                    /* name */
                25U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 5U
            {
                PERIPH_PLL_PHI3_CLK,                    /* name */
                16U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 6U
            {
                PERIPH_PLL_PHI4_CLK,                    /* name */
                10U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 7U
            {
                PERIPH_PLL_PHI5_CLK,                    /* name */
                16U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 8U
            {
                PERIPH_PLL_PHI6_CLK,                    /* name */
                20U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 9U
            {
                PERIPH_PLL_PHI7_CLK,                    /* name */
                20U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 10U
            {
                DDR_PLL_PHI0_CLK,                    /* name */
                4U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 11U
            {
                ACCEL_PLL_PHI0_CLK,                    /* name */
                4U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 12U
            {
                LBIST_CLK,                    /* name */
                16U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 13U
            {
                GMAC0_REF_DIV_CLK,                    /* name */
                1U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 14U
            {
                CLKOUT0_CLK,                    /* name */
                13U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 15U
            {
                CLKOUT1_CLK,                    /* name */
                1U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 16U
            {
                PER_CLK,                    /* name */
                1U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 17U
            {
                FLEXTIMERA_CLK,                    /* name */
                1U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 18U
            {
                FLEXTIMERB_CLK,                    /* name */
                1U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 19U
            {
                FLEXRAY_CLK,                    /* name */
                2U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 20U
            {
                GMAC_TS_CLK,                    /* name */
                1U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 21U
            {
                GMAC0_TX_CLK,                    /* name */
                1U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 22U
            {
                QSPI_2X_CLK,                    /* name */
                1U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 23U
            {
                SDHC_CLK,                    /* name */
                1U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 24U
            {
                ACCEL3_CLK,                    /* name */
                1U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 25U
            {
                ACCEL4_CLK,                    /* name */
                1U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 26U
            {
                GMAC1_TX_CLK,                    /* name */
                1U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 27U
            {
                GMAC1_REF_DIV_CLK,                    /* name */
                1U,                              /* value */
                {
                    0U,
                }
            },
            #endif
        },


        /* TRIGGER DIVIDER Initialization. */
        {
            {
                RESERVED_CLK,             /* divider name */
                IMMEDIATE_DIVIDER_UPDATE, /* trigger value */
                RESERVED_CLK,             /* input source name */
            },
        },



        /* FRACTIONAL DIVIDER initialization. */
        {

            #if CLOCK_IP_FRACTIONAL_DIVIDERS_NO > 0U
            {
                CORE_PLL_DFS1_CLK,                    /* name */
                1U,          /* Enabled */
                {
                    1U,          /* integer part */
                    9U,          /* fractional part */
                },
            },
            #endif

            #if CLOCK_IP_FRACTIONAL_DIVIDERS_NO > 1U
            {
                CORE_PLL_DFS2_CLK,                    /* name */
                1U,          /* Enabled */
                {
                    1U,          /* integer part */
                    9U,          /* fractional part */
                },
            },
            #endif

            #if CLOCK_IP_FRACTIONAL_DIVIDERS_NO > 2U
            {
                CORE_PLL_DFS3_CLK,                    /* name */
                1U,          /* Enabled */
                {
                    2U,          /* integer part */
                    0U,          /* fractional part */
                },
            },
            #endif

            #if CLOCK_IP_FRACTIONAL_DIVIDERS_NO > 3U
            {
                CORE_PLL_DFS4_CLK,                    /* name */
                1U,          /* Enabled */
                {
                    3U,          /* integer part */
                    12U,          /* fractional part */
                },
            },
            #endif

            #if CLOCK_IP_FRACTIONAL_DIVIDERS_NO > 4U
            {
                CORE_PLL_DFS5_CLK,                    /* name */
                1U,          /* Enabled */
                {
                    1U,          /* integer part */
                    24U,          /* fractional part */
                },
            },
            #endif

            #if CLOCK_IP_FRACTIONAL_DIVIDERS_NO > 5U
            {
                CORE_PLL_DFS6_CLK,                    /* name */
                1U,          /* Enabled */
                {
                    1U,          /* integer part */
                    24U,          /* fractional part */
                },
            },
            #endif

            #if CLOCK_IP_FRACTIONAL_DIVIDERS_NO > 6U
            {
                PERIPH_PLL_DFS1_CLK,                    /* name */
                1U,          /* Enabled */
                {
                    2U,          /* integer part */
                    0U,          /* fractional part */
                },
            },
            #endif

            #if CLOCK_IP_FRACTIONAL_DIVIDERS_NO > 7U
            {
                PERIPH_PLL_DFS2_CLK,                    /* name */
                1U,          /* Enabled */
                {
                    2U,          /* integer part */
                    0U,          /* fractional part */
                },
            },
            #endif

            #if CLOCK_IP_FRACTIONAL_DIVIDERS_NO > 8U
            {
                PERIPH_PLL_DFS3_CLK,                    /* name */
                1U,          /* Enabled */
                {
                    5U,          /* integer part */
                    0U,          /* fractional part */
                },
            },
            #endif

            #if CLOCK_IP_FRACTIONAL_DIVIDERS_NO > 9U
            {
                PERIPH_PLL_DFS4_CLK,                    /* name */
                1U,          /* Enabled */
                {
                    2U,          /* integer part */
                    0U,          /* fractional part */
                },
            },
            #endif

            #if CLOCK_IP_FRACTIONAL_DIVIDERS_NO > 10U
            {
                PERIPH_PLL_DFS5_CLK,                    /* name */
                1U,          /* Enabled */
                {
                    12U,          /* integer part */
                    18U,          /* fractional part */
                },
            },
            #endif

            #if CLOCK_IP_FRACTIONAL_DIVIDERS_NO > 11U
            {
                PERIPH_PLL_DFS6_CLK,                    /* name */
                1U,          /* Enabled */
                {
                    2U,          /* integer part */
                    0U,          /* fractional part */
                },
            },
            #endif
        },



        /* EXTERNAL CLOCKS initialization. */
        {

            #if CLOCK_IP_EXT_CLKS_NO > 0U
            {
                FTM_0_EXT_REF_CLK,                    /* name */
                20000000U,                              /* value */
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO > 1U
            {
                FTM_1_EXT_REF_CLK,                    /* name */
                20000000U,                              /* value */
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO > 2U
            {
                GMAC_0_EXT_REF_CLK,                    /* name */
                40000000U,                              /* value */
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO > 3U
            {
                GMAC_0_EXT_RX_CLK,                    /* name */
                25000000U,                              /* value */
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO > 4U
            {
                GMAC_0_EXT_TX_CLK,                    /* name */
                25000000U,                              /* value */
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO > 5U
            {
                GMAC_EXT_TS_CLK,                    /* name */
                20000000U,                              /* value */
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO > 6U
            {
                GMAC_1_EXT_TX_CLK,                    /* name */
                25000000U,                              /* value */
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO > 7U
            {
                GMAC_1_EXT_RX_CLK,                    /* name */
                25000000U,                              /* value */
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO > 8U
            {
                GMAC_1_EXT_REF_CLK,                    /* name */
                40000000U,                              /* value */
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO > 9U
            {
                SERDES_0_LANE_0_TX,                    /* name */
                100000000U,                              /* value */
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO > 10U
            {
                SERDES_0_LANE_0_CDR,                    /* name */
                100000000U,                              /* value */
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO > 11U
            {
                SERDES_1_LANE_0_TX,                    /* name */
                125000000U,                              /* value */
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO > 12U
            {
                SERDES_1_LANE_0_CDR,                    /* name */
                125000000U,                              /* value */
            },
            #endif
        },



        /* CLOCK GATES initialization. */
        {

            #if CLOCK_IP_GATES_NO > 0U
            {
                DDR_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 1U
            {
                GMAC0_TS_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 2U
            {
                USDHC0_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif
        },
        /* PCFS initialization. */ 
        {
            {
                RESERVED_CLK,
                0U,
                0U,
                RESERVED_CLK,
                0U,
            },
            {
                RESERVED_CLK,
                0U,
                0U,
                RESERVED_CLK,
                0U,
            },
            {
                RESERVED_CLK,
                0U,
                0U,
                RESERVED_CLK,
                0U,
            },
            {
                RESERVED_CLK,
                0U,
                0U,
                RESERVED_CLK,
                0U,
            },
            {
                RESERVED_CLK,
                0U,
                0U,
                RESERVED_CLK,
                0U,
            },
        },
        /* Clock monitor */ 
        {
            #if CLOCK_IP_CMUS_NO > 0U
            {
                FXOSC_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_0 */
                (                                           /* IER for CMU_FC_0 */
                    CMU_FC_IER_FLLIE(0) |
                    CMU_FC_IER_FHHIE(0) |
                    CMU_FC_IER_FLLAIE(0) |
                    CMU_FC_IER_FHHAIE(0)
                ),
                40000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 1U
            {
                XBAR_DIV3_FAIL_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_5 */
                (                                           /* IER for CMU_FC_5 */
                    CMU_FC_IER_FLLIE(0) |
                    CMU_FC_IER_FHHIE(0) |
                    CMU_FC_IER_FLLAIE(0) |
                    CMU_FC_IER_FHHAIE(0)
                ),
                106666667U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 2U
            {
                CORE_M7_0_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_6 */
                (                                           /* IER for CMU_FC_6 */
                    CMU_FC_IER_FLLIE(0) |
                    CMU_FC_IER_FHHIE(0) |
                    CMU_FC_IER_FLLAIE(0) |
                    CMU_FC_IER_FHHAIE(0)
                ),
                320000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 3U
            {
                XBAR_DIV3_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_7 */
                (                                           /* IER for CMU_FC_7 */
                    CMU_FC_IER_FLLIE(0) |
                    CMU_FC_IER_FHHIE(0) |
                    CMU_FC_IER_FLLAIE(0) |
                    CMU_FC_IER_FHHAIE(0)
                ),
                106666667U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 4U
            {
                CORE_M7_1_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_8 */
                (                                           /* IER for CMU_FC_8 */
                    CMU_FC_IER_FLLIE(0) |
                    CMU_FC_IER_FHHIE(0) |
                    CMU_FC_IER_FLLAIE(0) |
                    CMU_FC_IER_FHHAIE(0)
                ),
                320000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 5U
            {
                CORE_M7_2_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_9 */
                (                                           /* IER for CMU_FC_9 */
                    CMU_FC_IER_FLLIE(0) |
                    CMU_FC_IER_FHHIE(0) |
                    CMU_FC_IER_FLLAIE(0) |
                    CMU_FC_IER_FHHAIE(0)
                ),
                320000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 6U
            {
                PER_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_10 */
                (                                           /* IER for CMU_FC_10 */
                    CMU_FC_IER_FLLIE(0) |
                    CMU_FC_IER_FHHIE(0) |
                    CMU_FC_IER_FLLAIE(0) |
                    CMU_FC_IER_FHHAIE(0)
                ),
                48000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 7U
            {
                SERDES0_REF_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_11 */
                (                                           /* IER for CMU_FC_11 */
                    CMU_FC_IER_FLLIE(0) |
                    CMU_FC_IER_FHHIE(0) |
                    CMU_FC_IER_FLLAIE(0) |
                    CMU_FC_IER_FHHAIE(0)
                ),
                125000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 8U
            {
                FLEXRAY_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_12 */
                (                                           /* IER for CMU_FC_12 */
                    CMU_FC_IER_FLLIE(0) |
                    CMU_FC_IER_FHHIE(0) |
                    CMU_FC_IER_FLLAIE(0) |
                    CMU_FC_IER_FHHAIE(0)
                ),
                24000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 9U
            {
                FLEXCAN_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_13 */
                (                                           /* IER for CMU_FC_13 */
                    CMU_FC_IER_FLLIE(0) |
                    CMU_FC_IER_FHHIE(0) |
                    CMU_FC_IER_FLLAIE(0) |
                    CMU_FC_IER_FHHAIE(0)
                ),
                48000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 10U
            {
                GMAC0_TX_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_14 */
                (                                           /* IER for CMU_FC_14 */
                    CMU_FC_IER_FLLIE(0) |
                    CMU_FC_IER_FHHIE(0) |
                    CMU_FC_IER_FLLAIE(0) |
                    CMU_FC_IER_FHHAIE(0)
                ),
                48000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 11U
            {
                GMAC_TS_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_15 */
                (                                           /* IER for CMU_FC_15 */
                    CMU_FC_IER_FLLIE(0) |
                    CMU_FC_IER_FHHIE(0) |
                    CMU_FC_IER_FLLAIE(0) |
                    CMU_FC_IER_FHHAIE(0)
                ),
                48000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 12U
            {
                LINFLEXD_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_16 */
                (                                           /* IER for CMU_FC_16 */
                    CMU_FC_IER_FLLIE(0) |
                    CMU_FC_IER_FHHIE(0) |
                    CMU_FC_IER_FLLAIE(0) |
                    CMU_FC_IER_FHHAIE(0)
                ),
                24000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 13U
            {
                QSPI_1X_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_17 */
                (                                           /* IER for CMU_FC_17 */
                    CMU_FC_IER_FLLIE(0) |
                    CMU_FC_IER_FHHIE(0) |
                    CMU_FC_IER_FLLAIE(0) |
                    CMU_FC_IER_FHHAIE(0)
                ),
                24000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 14U
            {
                SDHC_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_18 */
                (                                           /* IER for CMU_FC_18 */
                    CMU_FC_IER_FLLIE(0) |
                    CMU_FC_IER_FHHIE(0) |
                    CMU_FC_IER_FLLAIE(0) |
                    CMU_FC_IER_FHHAIE(0)
                ),
                48000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 15U
            {
                DDR_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_20 */
                (                                           /* IER for CMU_FC_20 */
                    CMU_FC_IER_FLLIE(0) |
                    CMU_FC_IER_FHHIE(0) |
                    CMU_FC_IER_FLLAIE(0) |
                    CMU_FC_IER_FHHAIE(0)
                ),
                400000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 16U
            {
                GMAC0_RX_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_21 */
                (                                           /* IER for CMU_FC_21 */
                    CMU_FC_IER_FLLIE(0) |
                    CMU_FC_IER_FHHIE(0) |
                    CMU_FC_IER_FLLAIE(0) |
                    CMU_FC_IER_FHHAIE(0)
                ),
                48000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 17U
            {
                SPI_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_22 */
                (                                           /* IER for CMU_FC_22 */
                    CMU_FC_IER_FLLIE(0) |
                    CMU_FC_IER_FHHIE(0) |
                    CMU_FC_IER_FLLAIE(0) |
                    CMU_FC_IER_FHHAIE(0)
                ),
                48000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 18U
            {
                ACCEL3_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_38 */
                (                                           /* IER for CMU_FC_38 */
                    CMU_FC_IER_FLLIE(0) |
                    CMU_FC_IER_FHHIE(0) |
                    CMU_FC_IER_FLLAIE(0) |
                    CMU_FC_IER_FHHAIE(0)
                ),
                48000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 19U
            {
                ACCEL4_LAX0_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_39 */
                (                                           /* IER for CMU_FC_39 */
                    CMU_FC_IER_FLLIE(0) |
                    CMU_FC_IER_FHHIE(0) |
                    CMU_FC_IER_FLLAIE(0) |
                    CMU_FC_IER_FHHAIE(0)
                ),
                48000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 20U
            {
                ACCEL4_LAX1_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_40 */
                (                                           /* IER for CMU_FC_40 */
                    CMU_FC_IER_FLLIE(0) |
                    CMU_FC_IER_FHHIE(0) |
                    CMU_FC_IER_FLLAIE(0) |
                    CMU_FC_IER_FHHAIE(0)
                ),
                48000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 21U
            {
                GMAC1_TX_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_46 */
                (                                           /* IER for CMU_FC_46 */
                    CMU_FC_IER_FLLIE(0) |
                    CMU_FC_IER_FHHIE(0) |
                    CMU_FC_IER_FLLAIE(0) |
                    CMU_FC_IER_FHHAIE(0)
                ),
                48000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 22U
            {
                GMAC1_RX_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_51 */
                (                                           /* IER for CMU_FC_51 */
                    CMU_FC_IER_FLLIE(0) |
                    CMU_FC_IER_FHHIE(0) |
                    CMU_FC_IER_FLLAIE(0) |
                    CMU_FC_IER_FHHAIE(0)
                ),
                48000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 23U
            {
                XBAR_MIPICSI201_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_52 */
                (                                           /* IER for CMU_FC_52 */
                    CMU_FC_IER_FLLIE(0) |
                    CMU_FC_IER_FHHIE(0) |
                    CMU_FC_IER_FLLAIE(0) |
                    CMU_FC_IER_FHHAIE(0)
                ),
                320000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 24U
            {
                XBAR_MIPICSI223_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_53 */
                (                                           /* IER for CMU_FC_53 */
                    CMU_FC_IER_FLLIE(0) |
                    CMU_FC_IER_FHHIE(0) |
                    CMU_FC_IER_FLLAIE(0) |
                    CMU_FC_IER_FHHAIE(0)
                ),
                320000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 25U
            {
                SERDES1_REF_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_54 */
                (                                           /* IER for CMU_FC_54 */
                    CMU_FC_IER_FLLIE(0) |
                    CMU_FC_IER_FHHIE(0) |
                    CMU_FC_IER_FLLAIE(0) |
                    CMU_FC_IER_FHHAIE(0)
                ),
                125000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 26U
            {
                RESERVED_CLK,
                0U,
                0U,
                0U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 27U
            {
                RESERVED_CLK,
                0U,
                0U,
                0U,
            },
            #endif
        },
        /* Specific peripheral initialization. */
        {
            0U,
            {
                {
                    RESERVED_VALUE,
                    0U,
                },
            },
        },
        /* Configured frequency values. */
        {
            #if CLOCK_IP_CONFIGURED_FREQUENCIES_NO > 0U
            {
                FIRC_CLK,
                48000000U,
            },
            #endif
            #if CLOCK_IP_CONFIGURED_FREQUENCIES_NO > 1U
            {
                FXOSC_CLK,
                40000000U,
            },
            #endif
            #if CLOCK_IP_CONFIGURED_FREQUENCIES_NO > 2U
            {
                XBAR_DIV3_CLK,
                106666667U,
            },
            #endif
            #if CLOCK_IP_CONFIGURED_FREQUENCIES_NO > 3U
            {
                XBAR_CLK,
                320000000U,
            },
            #endif
        },
    },
};


#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */



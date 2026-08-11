/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.0
*   Build Version        : S32_RTD_4_0_0_D2210_ASR_REL_4_4_REV_0000_20221031
*
*   (c) Copyright 2022 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file       Clock_Ip_PBcfg.c
*   @version    4.0.0
*
*   @brief   AUTOSAR Mcu - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup CLOCK_DRIVER_CONFIGURATION Clock Ip Driver
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
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_PBCFG_VENDOR_ID_C                      43
#define CLOCK_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C       4
#define CLOCK_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_PBCFG_SW_MAJOR_VERSION_C               4
#define CLOCK_IP_PBCFG_SW_MINOR_VERSION_C               0
#define CLOCK_IP_PBCFG_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_PBcfg.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_PBCFG_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_PBcfg.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip_PBcfg.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_PBcfg.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip_PBcfg.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_PBCFG_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_PBCFG_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_PBCFG_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_PBcfg.c and Clock_Ip_Private.h are different"
#endif


#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Clock_Ip_PBcfg.c file and StandardTypes.h file are of the same Autosar version */
#if ((CLOCK_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != STD_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C    != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Clock_Ip_PBcfg.c and StandardTypes.h are different"
#endif
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
 * Configuration structure for Clock Configuration 0
 * ************************************************************************* */
 /*! @brief User Configuration structure clock_Cfg_0 */
const Clock_Ip_ClockConfigType Mcu_aClockConfigPB[2U] = {

    {
        0U,                                 /* clkConfigId */

        0U,                                 /* ircoscsCount */
        1U,                                 /* xoscsCount */
        4U,                                 /* pllsCount */
        19U,                                /* selectorsCount */
        26U,                                /* dividersCount */
        0U,                                 /* dividerTriggersCount */
        6U,                                /* fracDivsCount */
        24U,                                /* extClksCount */
        0U,                                 /* gatesCount */
        0U,                                 /* pcfsCount */
        26U,                                /* cmusCount */
        4U,                                /* configureFrequenciesCount */

        /* IRCOSC initialization. */
        {
    
           #if CLOCK_IP_IRCOSCS_NO > 0U
           {
               RESERVED_CLK,           /* name */
               0U,                     /* enable */
               0U,                     /* Enable regulator */
               0U,                     /* Ircosc range */
               0U,                     /* Ircosc enable in VLP mode */
               0U,                     /* Ircosc enable in STOP mode */
           },
           #endif
    
           #if CLOCK_IP_IRCOSCS_NO > 1U
           {
               RESERVED_CLK,           /* name */
               0U,                     /* enable */
               0U,                     /* Enable regulator */
               0U,                     /* Ircosc range */
               0U,                     /* Ircosc enable in VLP mode */
               0U,                     /* Ircosc enable in STOP mode */
           },
           #endif
    
        },

        /* XOSC initialization. */
        {
            #if CLOCK_IP_XOSCS_NO > 0U
            {
                FXOSC_CLK,                    /* Clock name associated to xosc */
                40000000U,                    /* External oscillator frequency. */
                1U,                           /* Enable xosc. */
                157U,                         /* Startup stabilization time. */
                0U,                           /* XOSC bypass option */
                1U,                           /* Comparator enable */
                12U,                          /* Crystal overdrive protection */
                0U,                     /* Gain value */
                0U,                     /* Monitor type */
            },
            #endif

        },

        /* PLL initialization. */
        {
            #if CLOCK_IP_PLLS_NO > 0U
            {
                COREPLL_CLK,                  /*!<     name;                    */
                0U,                           /*!<     enable;                  */
                FIRC_CLK,                    /*!<     inputReference           */
                0U,                           /*!<     bypass;                  */
                2U,                           /*!<     predivider;              */
                0U,                           /*!<     numeratorFracLoopDiv;    */
                50U,                          /*!<     mulFactorDiv;            */
                0U,                           /*!<     modulation;              */
                1U,                           /*!<     modulationType;          */
                0U,                           /*!<     modulationPeriod;        */
                1U,                           /*!<     incrementStep;           */
                0U,                           /*!<     sigmaDelta;              */
                0U,                           /*!<     ditherControl;           */
                0U,                           /*!<     ditherControlValue;      */
                0U,                           /*!<     Monitor type */
                {                             /*!<     Dividers */
                        0U,
                        0U,
                        0U,
                },
            },
            #endif
            #if CLOCK_IP_PLLS_NO > 1U
            {
                PERIPHPLL_CLK,                  /*!<     name;                    */
                0U,                           /*!<     enable;                  */
                FIRC_CLK,                    /*!<     inputReference           */
                0U,                           /*!<     bypass;                  */
                2U,                           /*!<     predivider;              */
                0U,                           /*!<     numeratorFracLoopDiv;    */
                50U,                          /*!<     mulFactorDiv;            */
                0U,                           /*!<     modulation;              */
                1U,                           /*!<     modulationType;          */
                0U,                           /*!<     modulationPeriod;        */
                0U,                           /*!<     incrementStep;           */
                0U,                           /*!<     sigmaDelta;              */
                0U,                           /*!<     ditherControl;           */
                0U,                           /*!<     ditherControlValue;      */
                0U,                           /*!<     Monitor type */
                {                             /*!<     Dividers */
                        0U,
                        0U,
                        0U,
                },
            },
            #endif
            #if CLOCK_IP_PLLS_NO > 2U
            {
                DDRPLL_CLK,                  /*!<     name;                    */
                0U,                           /*!<     enable;                  */
                FIRC_CLK,                    /*!<     inputReference           */
                0U,                           /*!<     bypass;                  */
                2U,                           /*!<     predivider;              */
                0U,                           /*!<     numeratorFracLoopDiv;    */
                60U,                          /*!<     mulFactorDiv;            */
                0U,                           /*!<     modulation;              */
                1U,                           /*!<     modulationType;          */
                0U,                           /*!<     modulationPeriod;        */
                1U,                           /*!<     incrementStep;           */
                0U,                           /*!<     sigmaDelta;              */
                0U,                           /*!<     ditherControl;           */
                0U,                           /*!<     ditherControlValue;      */
                0U,                           /*!<     Monitor type */
                {                             /*!<     Dividers */
                        0U,
                        0U,
                        0U,
                },
            },
            #endif
            #if CLOCK_IP_PLLS_NO > 3U
            {
                ACCELPLL_CLK,                  /*!<     name;                    */
                0U,                           /*!<     enable;                  */
                FIRC_CLK,                    /*!<     inputReference           */
                0U,                           /*!<     bypass;                  */
                2U,                           /*!<     predivider;              */
                0U,                           /*!<     numeratorFracLoopDiv;    */
                50U,                          /*!<     mulFactorDiv;            */
                0U,                           /*!<     modulation;              */
                1U,                           /*!<     modulationType;          */
                0U,                           /*!<     modulationPeriod;        */
                1U,                           /*!<     incrementStep;           */
                0U,                           /*!<     sigmaDelta;              */
                0U,                           /*!<     ditherControl;           */
                0U,                           /*!<     ditherControlValue;      */
                0U,                           /*!<     Monitor type */
                {                             /*!<     Dividers */
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
                XBAR_2X_CLK,                     /* Clock name associated to selector */
                FIRC_CLK,                       /* Name of the selected input source */
            },
            #endif
        
            #if CLOCK_IP_SELECTORS_NO > 1U
            {
                CLKOUT0_CLK,                     /* Clock name associated to selector */
                FXOSC_CLK,                       /* Name of the selected input source */
            },
            #endif
        
            #if CLOCK_IP_SELECTORS_NO > 2U
            {
                CLKOUT1_CLK,                     /* Clock name associated to selector */
                FXOSC_CLK,                       /* Name of the selected input source */
            },
            #endif
        
            #if CLOCK_IP_SELECTORS_NO > 3U
            {
                PER_CLK,                     /* Clock name associated to selector */
                FIRC_CLK,                       /* Name of the selected input source */
            },
            #endif
        
            #if CLOCK_IP_SELECTORS_NO > 4U
            {
                FLEXTIMERA_CLK,                     /* Clock name associated to selector */
                FIRC_CLK,                       /* Name of the selected input source */
            },
            #endif
        
            #if CLOCK_IP_SELECTORS_NO > 5U
            {
                FLEXTIMERB_CLK,                     /* Clock name associated to selector */
                FIRC_CLK,                       /* Name of the selected input source */
            },
            #endif
        
            #if CLOCK_IP_SELECTORS_NO > 6U
            {
                FLEXRAY_CLK,                     /* Clock name associated to selector */
                FIRC_CLK,                       /* Name of the selected input source */
            },
            #endif
        
            #if CLOCK_IP_SELECTORS_NO > 7U
            {
                FLEXCAN_CLK,                     /* Clock name associated to selector */
                FIRC_CLK,                       /* Name of the selected input source */
            },
            #endif
        
            #if CLOCK_IP_SELECTORS_NO > 8U
            {
                LIN_BAUD_CLK,                     /* Clock name associated to selector */
                FIRC_CLK,                       /* Name of the selected input source */
            },
            #endif
        
            #if CLOCK_IP_SELECTORS_NO > 9U
            {
                QSPI_2X_CLK,                     /* Clock name associated to selector */
                FIRC_CLK,                       /* Name of the selected input source */
            },
            #endif
        
            #if CLOCK_IP_SELECTORS_NO > 10U
            {
                SDHC_CLK,                     /* Clock name associated to selector */
                FIRC_CLK,                       /* Name of the selected input source */
            },
            #endif
        
            #if CLOCK_IP_SELECTORS_NO > 11U
            {
                SPI_CLK,                     /* Clock name associated to selector */
                FIRC_CLK,                       /* Name of the selected input source */
            },
            #endif
        
            #if CLOCK_IP_SELECTORS_NO > 12U
            {
                A53_CORE_CLK,                     /* Clock name associated to selector */
                FIRC_CLK,                       /* Name of the selected input source */
            },
            #endif
        
            #if CLOCK_IP_SELECTORS_NO > 13U
            {
                DDR_CLK,                     /* Clock name associated to selector */
                FIRC_CLK,                       /* Name of the selected input source */
            },
            #endif
        
            #if CLOCK_IP_SELECTORS_NO > 14U
            {
                GMAC_TS_CLK,                     /* Clock name associated to selector */
                FIRC_CLK,                       /* Name of the selected input source */
            },
            #endif
        
            #if CLOCK_IP_SELECTORS_NO > 15U
            {
                GMAC0_TX_CLK,                     /* Clock name associated to selector */
                FIRC_CLK,                       /* Name of the selected input source */
            },
            #endif
        
            #if CLOCK_IP_SELECTORS_NO > 16U
            {
                GMAC0_RX_CLK,                     /* Clock name associated to selector */
                FIRC_CLK,                       /* Name of the selected input source */
            },
            #endif
        
            #if CLOCK_IP_SELECTORS_NO > 17U
            {
                GMAC0_REF_CLK,                     /* Clock name associated to selector */
                FIRC_CLK,                       /* Name of the selected input source */
            },
            #endif
        
            #if CLOCK_IP_SELECTORS_NO > 18U
            {
                RTC_CLK,                     /* Clock name associated to selector */
                FIRC_CLK,                       /* Name of the selected input source */
            },
            #endif
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
        },

        /* DIVIDER initialization. */
        {
        
            #if CLOCK_IP_DIVIDERS_NO > 0U
            {
                CORE_PLL_PHI0_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                    
            #if CLOCK_IP_DIVIDERS_NO > 1U
            {
                CORE_PLL_PHI1_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                    
            #if CLOCK_IP_DIVIDERS_NO > 2U
            {
                PERIPH_PLL_PHI0_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                    
            #if CLOCK_IP_DIVIDERS_NO > 3U
            {
                PERIPH_PLL_PHI1_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                    
            #if CLOCK_IP_DIVIDERS_NO > 4U
            {
                PERIPH_PLL_PHI2_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                    
            #if CLOCK_IP_DIVIDERS_NO > 5U
            {
                PERIPH_PLL_PHI3_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                    
            #if CLOCK_IP_DIVIDERS_NO > 6U
            {
                PERIPH_PLL_PHI4_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                    
            #if CLOCK_IP_DIVIDERS_NO > 7U
            {
                PERIPH_PLL_PHI5_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                    
            #if CLOCK_IP_DIVIDERS_NO > 8U
            {
                PERIPH_PLL_PHI6_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                    
            #if CLOCK_IP_DIVIDERS_NO > 9U
            {
                PERIPH_PLL_PHI7_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                    
            #if CLOCK_IP_DIVIDERS_NO > 10U
            {
                DDR_PLL_PHI0_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                    
            #if CLOCK_IP_DIVIDERS_NO > 11U
            {
                ACCEL_PLL_PHI0_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                    
            #if CLOCK_IP_DIVIDERS_NO > 12U
            {
                ACCEL_PLL_PHI1_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                    
            #if CLOCK_IP_DIVIDERS_NO > 13U
            {
                LBIST_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                        
            #if CLOCK_IP_DIVIDERS_NO > 14U
            {
                DAPB_CLK,
                6U,
                {
                    0U,
                }
            },
            #endif
                        
            #if CLOCK_IP_DIVIDERS_NO > 15U
            {
                CLKOUT0_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                        
            #if CLOCK_IP_DIVIDERS_NO > 16U
            {
                CLKOUT1_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                        
            #if CLOCK_IP_DIVIDERS_NO > 17U
            {
                PER_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                        
            #if CLOCK_IP_DIVIDERS_NO > 18U
            {
                FLEXTIMERA_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                        
            #if CLOCK_IP_DIVIDERS_NO > 19U
            {
                FLEXTIMERB_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                        
            #if CLOCK_IP_DIVIDERS_NO > 20U
            {
                FLEXRAY_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                        
            #if CLOCK_IP_DIVIDERS_NO > 21U
            {
                QSPI_2X_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                        
            #if CLOCK_IP_DIVIDERS_NO > 22U
            {
                SDHC_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                        
            #if CLOCK_IP_DIVIDERS_NO > 23U
            {
                GMAC_TS_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                        
            #if CLOCK_IP_DIVIDERS_NO > 24U
            {
                GMAC0_TX_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                        
            #if CLOCK_IP_DIVIDERS_NO > 25U
            {
                GMAC0_REF_DIV_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                        
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                },
            },
        
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                },
            },
        
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                },
            },
        
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                },
            },
        
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                },
            },
        
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                },
            },
        
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                },
            },
        
        },

        /* DIVIDER TRIGGER Initialization. */
        {
            {
                RESERVED_CLK,          /* divider name */
                IMMEDIATE_DIVIDER_UPDATE,                    /* trigger value */
                RESERVED_CLK,          /* input source name */
            },
        },

        /* FRACTIONAL DIVIDER initialization. */
        {
            #if CLOCK_IP_FRACTIONAL_DIVIDERS_NO  > 0U
            {
                CORE_PLL_DFS1_CLK,
                0U,
                {
                    1U,
                    0U,
                },
            },
            #endif

            #if CLOCK_IP_FRACTIONAL_DIVIDERS_NO  > 1U
            {
                CORE_PLL_DFS2_CLK,
                0U,
                {
                    1U,
                    0U,
                },
            },
            #endif

            #if CLOCK_IP_FRACTIONAL_DIVIDERS_NO  > 2U
            {
                PERIPH_PLL_DFS1_CLK,
                0U,
                {
                    1U,
                    0U,
                },
            },
            #endif

            #if CLOCK_IP_FRACTIONAL_DIVIDERS_NO  > 3U
            {
                PERIPH_PLL_DFS2_CLK,
                0U,
                {
                    1U,
                    0U,
                },
            },
            #endif

            #if CLOCK_IP_FRACTIONAL_DIVIDERS_NO  > 4U
            {
                PERIPH_PLL_DFS3_CLK,
                0U,
                {
                    1U,
                    0U,
                },
            },
            #endif

            #if CLOCK_IP_FRACTIONAL_DIVIDERS_NO  > 5U
            {
                PERIPH_PLL_DFS5_CLK,
                0U,
                {
                    1U,
                    0U,
                },
            },
            #endif

            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                    0U,
                },
            },
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                    0U,
                },
            },
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                    0U,
                },
            },
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                    0U,
                },
            },
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                    0U,
                },
            },
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                    0U,
                },
            },
        },

        /* EXTERNAL CLOCKS initialization. */
        {
            #if CLOCK_IP_EXT_CLKS_NO  > 0U
            {
                RTC_EXT_REF_CLK,
                48000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 1U
            {
                FTM_0_EXT_REF_CLK,
                20000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 2U
            {
                FTM_1_EXT_REF_CLK,
                20000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 3U
            {
                GMAC_0_EXT_REF_CLK,
                50000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 4U
            {
                GMAC_0_EXT_RX_CLK,
                125000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 5U
            {
                GMAC_0_EXT_TX_CLK,
                125000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 6U
            {
                GMAC_EXT_TS_CLK,
                200000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 7U
            {
                PFE_MAC_0_EXT_REF_CLK,
                50000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 8U
            {
                PFE_MAC_0_EXT_RX_CLK,
                312000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 9U
            {
                PFE_MAC_0_EXT_TX_CLK,
                312000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 10U
            {
                PFE_MAC_1_EXT_REF_CLK,
                50000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 11U
            {
                PFE_MAC_1_EXT_RX_CLK,
                125000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 12U
            {
                PFE_MAC_1_EXT_TX_CLK,
                125000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 13U
            {
                PFE_MAC_2_EXT_REF_CLK,
                50000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 14U
            {
                PFE_MAC_2_EXT_RX_CLK,
                125000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 15U
            {
                PFE_MAC_2_EXT_TX_CLK,
                125000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 16U
            {
                SERDES_0_XPCS_0_TX,
                125000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 17U
            {
                SERDES_0_XPCS_0_CDR,
                125000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 18U
            {
                SERDES_0_XPCS_1_TX,
                125000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 19U
            {
                SERDES_0_XPCS_1_CDR,
                125000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 20U
            {
                SERDES_1_XPCS_0_TX,
                125000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 21U
            {
                SERDES_1_XPCS_0_CDR,
                125000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 22U
            {
                SERDES_1_XPCS_1_TX,
                125000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 23U
            {
                SERDES_1_XPCS_1_CDR,
                125000000U,
            },
            #endif

        },

        /* CLOCK GATE initialization. */
        {
    
            {
                RESERVED_CLK,
                0U,
            },
    
            {
                RESERVED_CLK,
                0U,
            },
    
            {
                RESERVED_CLK,
                0U,
            },
    
            {
                RESERVED_CLK,
                0U,
            },
    
            {
                RESERVED_CLK,
                0U,
            },
    
            {
                RESERVED_CLK,
                0U,
            },
    
            {
                RESERVED_CLK,
                0U,
            },
    
            {
                RESERVED_CLK,
                0U,
            },
    
            {
                RESERVED_CLK,
                0U,
            },
    
        },

        /* PCFS initialization. */
        {
           #if CLOCK_IP_PCFS_NO > 0U
           {
                RESERVED_CLK,
                0U,
                0U,
                RESERVED_CLK,
                0U,
           },
           #endif
           #if CLOCK_IP_PCFS_NO > 1U
           {
                RESERVED_CLK,
                0U,
                0U,
                RESERVED_CLK,
                0U,
           },
           #endif
           #if CLOCK_IP_PCFS_NO > 2U
           {
                RESERVED_CLK,
                0U,
                0U,
                RESERVED_CLK,
                0U,
           },
           #endif
        },

        /* Clock monitor */ 
        {     
            #if CLOCK_IP_CMUS_NO > 0U
            {
                FXOSC_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_0_FXOSC_CLK */
                (                                           /* IER for CMU_FC_0_FXOSC_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                40000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 1U
            {
                XBAR_DIV3_FAIL_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_5_XBAR_DIV3_FAIL_CLK */
                (                                           /* IER for CMU_FC_5_XBAR_DIV3_FAIL_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                8000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 2U
            {
                CORE_M7_0_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_6_CORE_M7_0_CLK */
                (                                           /* IER for CMU_FC_6_CORE_M7_0_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                24000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 3U
            {
                XBAR_DIV3_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_7_XBAR_DIV3_CLK */
                (                                           /* IER for CMU_FC_7_XBAR_DIV3_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                8000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 4U
            {
                CORE_M7_1_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_8_CORE_M7_1_CLK */
                (                                           /* IER for CMU_FC_8_CORE_M7_1_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                24000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 5U
            {
                CORE_M7_2_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_9_CORE_M7_2_CLK */
                (                                           /* IER for CMU_FC_9_CORE_M7_2_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                24000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 6U
            {
                PER_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_10_PER_CLK */
                (                                           /* IER for CMU_FC_10_PER_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                0U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 7U
            {
                SERDES_REF_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_11_SERDES_REF_CLK */
                (                                           /* IER for CMU_FC_11_SERDES_REF_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                0U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 8U
            {
                FLEXRAY_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_12_FLEXRAY_CLK */
                (                                           /* IER for CMU_FC_12_FLEXRAY_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                0U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 9U
            {
                FLEXCAN_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_13_FLEXCAN_CLK */
                (                                           /* IER for CMU_FC_13_FLEXCAN_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                48000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 10U
            {
                GMAC0_TX_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_14_GMAC0_TX_CLK */
                (                                           /* IER for CMU_FC_14_GMAC0_TX_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                0U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 11U
            {
                GMAC_TS_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_15_GMAC_TS_CLK */
                (                                           /* IER for CMU_FC_15_GMAC_TS_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                0U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 12U
            {
                LINFLEXD_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_16_LINFLEXD_CLK */
                (                                           /* IER for CMU_FC_16_LINFLEXD_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                48000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 13U
            {
                QSPI_1X_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_17_QSPI_1X_CLK */
                (                                           /* IER for CMU_FC_17_QSPI_1X_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                0U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 14U
            {
                SDHC_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_18_SDHC_CLK */
                (                                           /* IER for CMU_FC_18_SDHC_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                0U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 15U
            {
                DDR_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_20_DDR_CLK */
                (                                           /* IER for CMU_FC_20_DDR_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                48000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 16U
            {
                GMAC0_RX_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_21_GMAC0_RX_CLK */
                (                                           /* IER for CMU_FC_21_GMAC0_RX_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                48000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 17U
            {
                SPI_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_22_SPI_CLK */
                (                                           /* IER for CMU_FC_22_SPI_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                48000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 18U
            {
                CORE_M7_3_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_24_CORE_M7_3_CLK */
                (                                           /* IER for CMU_FC_24_CORE_M7_3_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                24000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 19U
            {
                PFE_SYS_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_39_PFE_SYS_CLK */
                (                                           /* IER for CMU_FC_39_PFE_SYS_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                0U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 20U
            {
                PFEMAC0_TX_DIV_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_46_PFEMAC0_TX_DIV_CLK */
                (                                           /* IER for CMU_FC_46_PFEMAC0_TX_DIV_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                0U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 21U
            {
                PFEMAC0_RX_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_47_PFEMAC0_RX_CLK */
                (                                           /* IER for CMU_FC_47_PFEMAC0_RX_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                48000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 22U
            {
                PFEMAC1_TX_DIV_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_48_PFEMAC1_TX_DIV_CLK */
                (                                           /* IER for CMU_FC_48_PFEMAC1_TX_DIV_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                0U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 23U
            {
                PFEMAC1_RX_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_49_PFEMAC1_RX_CLK */
                (                                           /* IER for CMU_FC_49_PFEMAC1_RX_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                48000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 24U
            {
                PFEMAC2_TX_DIV_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_50_PFEMAC2_TX_DIV_CLK */
                (                                           /* IER for CMU_FC_50_PFEMAC2_TX_DIV_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                0U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 25U
            {
                PFEMAC2_RX_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_51_PFEMAC2_RX_CLK */
                (                                           /* IER for CMU_FC_51_PFEMAC2_RX_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                48000000U,
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
                8000000U,
            },
            #endif

            #if CLOCK_IP_CONFIGURED_FREQUENCIES_NO > 3U
            {
                XBAR_CLK,
                24000000U,
            },
            #endif

        },
    },

    {
        1U,                                 /* clkConfigId */

        0U,                                 /* ircoscsCount */
        1U,                                 /* xoscsCount */
        2U,                                 /* pllsCount */
        10U,                                /* selectorsCount */
        17U,                                /* dividersCount */
        0U,                                 /* dividerTriggersCount */
        6U,                                /* fracDivsCount */
        24U,                                /* extClksCount */
        0U,                                 /* gatesCount */
        0U,                                 /* pcfsCount */
        26U,                                /* cmusCount */
        4U,                                /* configureFrequenciesCount */

        /* IRCOSC initialization. */
        {
    
           #if CLOCK_IP_IRCOSCS_NO > 0U
           {
               RESERVED_CLK,           /* name */
               0U,                     /* enable */
               0U,                     /* Enable regulator */
               0U,                     /* Ircosc range */
               0U,                     /* Ircosc enable in VLP mode */
               0U,                     /* Ircosc enable in STOP mode */
           },
           #endif
    
           #if CLOCK_IP_IRCOSCS_NO > 1U
           {
               RESERVED_CLK,           /* name */
               0U,                     /* enable */
               0U,                     /* Enable regulator */
               0U,                     /* Ircosc range */
               0U,                     /* Ircosc enable in VLP mode */
               0U,                     /* Ircosc enable in STOP mode */
           },
           #endif
    
        },

        /* XOSC initialization. */
        {
            #if CLOCK_IP_XOSCS_NO > 0U
            {
                FXOSC_CLK,                    /* Clock name associated to xosc */
                40000000U,                    /* External oscillator frequency. */
                1U,                           /* Enable xosc. */
                157U,                         /* Startup stabilization time. */
                0U,                           /* XOSC bypass option */
                1U,                           /* Comparator enable */
                12U,                          /* Crystal overdrive protection */
                0U,                     /* Gain value */
                0U,                     /* Monitor type */
            },
            #endif

        },

        /* PLL initialization. */
        {
            #if CLOCK_IP_PLLS_NO > 0U
            {
                COREPLL_CLK,                  /*!<     name;                    */
                1U,                           /*!<     enable;                  */
                FXOSC_CLK,                    /*!<     inputReference           */
                0U,                           /*!<     bypass;                  */
                2U,                           /*!<     predivider;              */
                0U,                           /*!<     numeratorFracLoopDiv;    */
                80U,                          /*!<     mulFactorDiv;            */
                0U,                           /*!<     modulation;              */
                1U,                           /*!<     modulationType;          */
                0U,                           /*!<     modulationPeriod;        */
                1U,                           /*!<     incrementStep;           */
                0U,                           /*!<     sigmaDelta;              */
                0U,                           /*!<     ditherControl;           */
                0U,                           /*!<     ditherControlValue;      */
                0U,                           /*!<     Monitor type */
                {                             /*!<     Dividers */
                        0U,
                        0U,
                        0U,
                },
            },
            #endif
            #if CLOCK_IP_PLLS_NO > 1U
            {
                PERIPHPLL_CLK,                  /*!<     name;                    */
                1U,                           /*!<     enable;                  */
                FXOSC_CLK,                    /*!<     inputReference           */
                0U,                           /*!<     bypass;                  */
                1U,                           /*!<     predivider;              */
                0U,                           /*!<     numeratorFracLoopDiv;    */
                50U,                          /*!<     mulFactorDiv;            */
                0U,                           /*!<     modulation;              */
                1U,                           /*!<     modulationType;          */
                0U,                           /*!<     modulationPeriod;        */
                0U,                           /*!<     incrementStep;           */
                0U,                           /*!<     sigmaDelta;              */
                0U,                           /*!<     ditherControl;           */
                0U,                           /*!<     ditherControlValue;      */
                0U,                           /*!<     Monitor type */
                {                             /*!<     Dividers */
                        0U,
                        0U,
                        0U,
                },
            },
            #endif
            {
                RESERVED_CLK,           /* name */
                0U,                     /* enable */
                RESERVED_CLK,           /* inputReference */
                0U,                     /* Bypass */
                0U,                     /* predivider */
                0U,                     /* numeratorFracLoopDiv */
                0U,                     /* mulFactorDiv */
                0U,                     /* modulation */
                0U,                     /* Modulaton type: Spread spectrum modulation bypassed */
                0U,                     /* modulationPeriod */
                0U,                     /* incrementStep */
                0U,                     /* sigmaDelta */
                0U,                     /* ditherControl */
                0U,                     /* ditherControlValue */
                0U,                     /* monitor type */
                {                             /*!< Dividers */
                        0U,
                        0U,
                        0U,
                },
            },
            {
                RESERVED_CLK,           /* name */
                0U,                     /* enable */
                RESERVED_CLK,           /* inputReference */
                0U,                     /* Bypass */
                0U,                     /* predivider */
                0U,                     /* numeratorFracLoopDiv */
                0U,                     /* mulFactorDiv */
                0U,                     /* modulation */
                0U,                     /* Modulaton type: Spread spectrum modulation bypassed */
                0U,                     /* modulationPeriod */
                0U,                     /* incrementStep */
                0U,                     /* sigmaDelta */
                0U,                     /* ditherControl */
                0U,                     /* ditherControlValue */
                0U,                     /* monitor type */
                {                             /*!< Dividers */
                        0U,
                        0U,
                        0U,
                },
            },

        },


        /* SELECTOR initialization. */
        {

            #if CLOCK_IP_SELECTORS_NO > 0U
            {
                XBAR_2X_CLK,                     /* Clock name associated to selector */
                CORE_PLL_DFS1_CLK,                       /* Name of the selected input source */
            },
            #endif
        
            #if CLOCK_IP_SELECTORS_NO > 1U
            {
                PER_CLK,                     /* Clock name associated to selector */
                PERIPH_PLL_PHI1_CLK,                       /* Name of the selected input source */
            },
            #endif
        
            #if CLOCK_IP_SELECTORS_NO > 2U
            {
                FLEXCAN_CLK,                     /* Clock name associated to selector */
                PERIPH_PLL_PHI2_CLK,                       /* Name of the selected input source */
            },
            #endif
        
            #if CLOCK_IP_SELECTORS_NO > 3U
            {
                QSPI_2X_CLK,                     /* Clock name associated to selector */
                PERIPH_PLL_DFS1_CLK,                       /* Name of the selected input source */
            },
            #endif
        
            #if CLOCK_IP_SELECTORS_NO > 4U
            {
                SDHC_CLK,                     /* Clock name associated to selector */
                FIRC_CLK,                       /* Name of the selected input source */
            },
            #endif
        
            #if CLOCK_IP_SELECTORS_NO > 5U
            {
                A53_CORE_CLK,                     /* Clock name associated to selector */
                CORE_PLL_PHI0_CLK,                       /* Name of the selected input source */
            },
            #endif
        
            #if CLOCK_IP_SELECTORS_NO > 6U
            {
                GMAC_TS_CLK,                     /* Clock name associated to selector */
                GMAC_EXT_TS_CLK,                       /* Name of the selected input source */
            },
            #endif
        
            #if CLOCK_IP_SELECTORS_NO > 7U
            {
                GMAC0_TX_CLK,                     /* Clock name associated to selector */
                PERIPH_PLL_PHI5_CLK,                       /* Name of the selected input source */
            },
            #endif
        
            #if CLOCK_IP_SELECTORS_NO > 8U
            {
                GMAC0_RX_CLK,                     /* Clock name associated to selector */
                GMAC_0_EXT_RX_CLK,                       /* Name of the selected input source */
            },
            #endif
        
            #if CLOCK_IP_SELECTORS_NO > 9U
            {
                RTC_CLK,                     /* Clock name associated to selector */
                FIRC_CLK,                       /* Name of the selected input source */
            },
            #endif
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        
        },

        /* DIVIDER initialization. */
        {
        
            #if CLOCK_IP_DIVIDERS_NO > 0U
            {
                CORE_PLL_PHI0_CLK,
                2U,
                {
                    0U,
                }
            },
            #endif
                    
            #if CLOCK_IP_DIVIDERS_NO > 1U
            {
                CORE_PLL_PHI1_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                    
            #if CLOCK_IP_DIVIDERS_NO > 2U
            {
                PERIPH_PLL_PHI0_CLK,
                20U,
                {
                    0U,
                }
            },
            #endif
                    
            #if CLOCK_IP_DIVIDERS_NO > 3U
            {
                PERIPH_PLL_PHI1_CLK,
                25U,
                {
                    0U,
                }
            },
            #endif
                    
            #if CLOCK_IP_DIVIDERS_NO > 4U
            {
                PERIPH_PLL_PHI2_CLK,
                50U,
                {
                    0U,
                }
            },
            #endif
                    
            #if CLOCK_IP_DIVIDERS_NO > 5U
            {
                PERIPH_PLL_PHI3_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                    
            #if CLOCK_IP_DIVIDERS_NO > 6U
            {
                PERIPH_PLL_PHI4_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                    
            #if CLOCK_IP_DIVIDERS_NO > 7U
            {
                PERIPH_PLL_PHI5_CLK,
                16U,
                {
                    0U,
                }
            },
            #endif
                    
            #if CLOCK_IP_DIVIDERS_NO > 8U
            {
                PERIPH_PLL_PHI6_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                    
            #if CLOCK_IP_DIVIDERS_NO > 9U
            {
                PERIPH_PLL_PHI7_CLK,
                0U,
                {
                    0U,
                }
            },
            #endif
                    
            #if CLOCK_IP_DIVIDERS_NO > 10U
            {
                LBIST_CLK,
                16U,
                {
                    0U,
                }
            },
            #endif
                        
            #if CLOCK_IP_DIVIDERS_NO > 11U
            {
                DAPB_CLK,
                6U,
                {
                    0U,
                }
            },
            #endif
                        
            #if CLOCK_IP_DIVIDERS_NO > 12U
            {
                PER_CLK,
                1U,
                {
                    0U,
                }
            },
            #endif
                        
            #if CLOCK_IP_DIVIDERS_NO > 13U
            {
                QSPI_2X_CLK,
                3U,
                {
                    0U,
                }
            },
            #endif
                        
            #if CLOCK_IP_DIVIDERS_NO > 14U
            {
                SDHC_CLK,
                1U,
                {
                    0U,
                }
            },
            #endif
                        
            #if CLOCK_IP_DIVIDERS_NO > 15U
            {
                GMAC_TS_CLK,
                2U,
                {
                    0U,
                }
            },
            #endif
                        
            #if CLOCK_IP_DIVIDERS_NO > 16U
            {
                GMAC0_TX_CLK,
                1U,
                {
                    0U,
                }
            },
            #endif
                        
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                },
            },
        
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                },
            },
        
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                },
            },
        
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                },
            },
        
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                },
            },
        
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                },
            },
        
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                },
            },
        
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                },
            },
        
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                },
            },
        
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                },
            },
        
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                },
            },
        
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                },
            },
        
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                },
            },
        
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                },
            },
        
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                },
            },
        
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                },
            },
        
        },

        /* DIVIDER TRIGGER Initialization. */
        {
            {
                RESERVED_CLK,          /* divider name */
                IMMEDIATE_DIVIDER_UPDATE,                    /* trigger value */
                RESERVED_CLK,          /* input source name */
            },
        },

        /* FRACTIONAL DIVIDER initialization. */
        {
            #if CLOCK_IP_FRACTIONAL_DIVIDERS_NO  > 0U
            {
                CORE_PLL_DFS1_CLK,
                1U,
                {
                    1U,
                    0U,
                },
            },
            #endif

            #if CLOCK_IP_FRACTIONAL_DIVIDERS_NO  > 1U
            {
                CORE_PLL_DFS2_CLK,
                0U,
                {
                    1U,
                    0U,
                },
            },
            #endif

            #if CLOCK_IP_FRACTIONAL_DIVIDERS_NO  > 2U
            {
                PERIPH_PLL_DFS1_CLK,
                1U,
                {
                    1U,
                    9U,
                },
            },
            #endif

            #if CLOCK_IP_FRACTIONAL_DIVIDERS_NO  > 3U
            {
                PERIPH_PLL_DFS2_CLK,
                0U,
                {
                    1U,
                    9U,
                },
            },
            #endif

            #if CLOCK_IP_FRACTIONAL_DIVIDERS_NO  > 4U
            {
                PERIPH_PLL_DFS3_CLK,
                1U,
                {
                    1U,
                    9U,
                },
            },
            #endif

            #if CLOCK_IP_FRACTIONAL_DIVIDERS_NO  > 5U
            {
                PERIPH_PLL_DFS5_CLK,
                0U,
                {
                    1U,
                    0U,
                },
            },
            #endif

            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                    0U,
                },
            },
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                    0U,
                },
            },
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                    0U,
                },
            },
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                    0U,
                },
            },
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                    0U,
                },
            },
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                    0U,
                },
            },
        },

        /* EXTERNAL CLOCKS initialization. */
        {
            #if CLOCK_IP_EXT_CLKS_NO  > 0U
            {
                RTC_EXT_REF_CLK,
                48000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 1U
            {
                FTM_0_EXT_REF_CLK,
                20000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 2U
            {
                FTM_1_EXT_REF_CLK,
                20000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 3U
            {
                GMAC_0_EXT_REF_CLK,
                50000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 4U
            {
                GMAC_0_EXT_RX_CLK,
                125000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 5U
            {
                GMAC_0_EXT_TX_CLK,
                125000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 6U
            {
                GMAC_EXT_TS_CLK,
                200000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 7U
            {
                PFE_MAC_0_EXT_REF_CLK,
                50000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 8U
            {
                PFE_MAC_0_EXT_RX_CLK,
                312000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 9U
            {
                PFE_MAC_0_EXT_TX_CLK,
                312000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 10U
            {
                PFE_MAC_1_EXT_REF_CLK,
                50000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 11U
            {
                PFE_MAC_1_EXT_RX_CLK,
                125000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 12U
            {
                PFE_MAC_1_EXT_TX_CLK,
                125000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 13U
            {
                PFE_MAC_2_EXT_REF_CLK,
                50000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 14U
            {
                PFE_MAC_2_EXT_RX_CLK,
                125000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 15U
            {
                PFE_MAC_2_EXT_TX_CLK,
                125000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 16U
            {
                SERDES_0_XPCS_0_TX,
                125000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 17U
            {
                SERDES_0_XPCS_0_CDR,
                125000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 18U
            {
                SERDES_0_XPCS_1_TX,
                125000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 19U
            {
                SERDES_0_XPCS_1_CDR,
                125000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 20U
            {
                SERDES_1_XPCS_0_TX,
                125000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 21U
            {
                SERDES_1_XPCS_0_CDR,
                125000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 22U
            {
                SERDES_1_XPCS_1_TX,
                125000000U,
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO  > 23U
            {
                SERDES_1_XPCS_1_CDR,
                125000000U,
            },
            #endif

        },

        /* CLOCK GATE initialization. */
        {
    
            {
                RESERVED_CLK,
                0U,
            },
    
            {
                RESERVED_CLK,
                0U,
            },
    
            {
                RESERVED_CLK,
                0U,
            },
    
            {
                RESERVED_CLK,
                0U,
            },
    
            {
                RESERVED_CLK,
                0U,
            },
    
            {
                RESERVED_CLK,
                0U,
            },
    
            {
                RESERVED_CLK,
                0U,
            },
    
            {
                RESERVED_CLK,
                0U,
            },
    
            {
                RESERVED_CLK,
                0U,
            },
    
        },

        /* PCFS initialization. */
        {
           #if CLOCK_IP_PCFS_NO > 0U
           {
                RESERVED_CLK,
                0U,
                0U,
                RESERVED_CLK,
                0U,
           },
           #endif
           #if CLOCK_IP_PCFS_NO > 1U
           {
                RESERVED_CLK,
                0U,
                0U,
                RESERVED_CLK,
                0U,
           },
           #endif
           #if CLOCK_IP_PCFS_NO > 2U
           {
                RESERVED_CLK,
                0U,
                0U,
                RESERVED_CLK,
                0U,
           },
           #endif
        },

        /* Clock monitor */ 
        {     
            #if CLOCK_IP_CMUS_NO > 0U
            {
                FXOSC_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_0_FXOSC_CLK */
                (                                           /* IER for CMU_FC_0_FXOSC_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                40000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 1U
            {
                XBAR_DIV3_FAIL_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_5_XBAR_DIV3_FAIL_CLK */
                (                                           /* IER for CMU_FC_5_XBAR_DIV3_FAIL_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                133333333U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 2U
            {
                CORE_M7_0_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_6_CORE_M7_0_CLK */
                (                                           /* IER for CMU_FC_6_CORE_M7_0_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                400000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 3U
            {
                XBAR_DIV3_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_7_XBAR_DIV3_CLK */
                (                                           /* IER for CMU_FC_7_XBAR_DIV3_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                133333333U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 4U
            {
                CORE_M7_1_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_8_CORE_M7_1_CLK */
                (                                           /* IER for CMU_FC_8_CORE_M7_1_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                400000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 5U
            {
                CORE_M7_2_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_9_CORE_M7_2_CLK */
                (                                           /* IER for CMU_FC_9_CORE_M7_2_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                400000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 6U
            {
                PER_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_10_PER_CLK */
                (                                           /* IER for CMU_FC_10_PER_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                80000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 7U
            {
                SERDES_REF_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_11_SERDES_REF_CLK */
                (                                           /* IER for CMU_FC_11_SERDES_REF_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                100000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 8U
            {
                FLEXRAY_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_12_FLEXRAY_CLK */
                (                                           /* IER for CMU_FC_12_FLEXRAY_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                0U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 9U
            {
                FLEXCAN_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_13_FLEXCAN_CLK */
                (                                           /* IER for CMU_FC_13_FLEXCAN_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                40000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 10U
            {
                GMAC0_TX_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_14_GMAC0_TX_CLK */
                (                                           /* IER for CMU_FC_14_GMAC0_TX_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                125000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 11U
            {
                GMAC_TS_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_15_GMAC_TS_CLK */
                (                                           /* IER for CMU_FC_15_GMAC_TS_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                200000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 12U
            {
                LINFLEXD_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_16_LINFLEXD_CLK */
                (                                           /* IER for CMU_FC_16_LINFLEXD_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                48000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 13U
            {
                QSPI_1X_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_17_QSPI_1X_CLK */
                (                                           /* IER for CMU_FC_17_QSPI_1X_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                133333333U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 14U
            {
                SDHC_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_18_SDHC_CLK */
                (                                           /* IER for CMU_FC_18_SDHC_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                48000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 15U
            {
                DDR_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_20_DDR_CLK */
                (                                           /* IER for CMU_FC_20_DDR_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                48000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 16U
            {
                GMAC0_RX_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_21_GMAC0_RX_CLK */
                (                                           /* IER for CMU_FC_21_GMAC0_RX_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                125000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 17U
            {
                SPI_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_22_SPI_CLK */
                (                                           /* IER for CMU_FC_22_SPI_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                48000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 18U
            {
                CORE_M7_3_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_24_CORE_M7_3_CLK */
                (                                           /* IER for CMU_FC_24_CORE_M7_3_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                400000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 19U
            {
                PFE_SYS_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_39_PFE_SYS_CLK */
                (                                           /* IER for CMU_FC_39_PFE_SYS_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                0U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 20U
            {
                PFEMAC0_TX_DIV_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_46_PFEMAC0_TX_DIV_CLK */
                (                                           /* IER for CMU_FC_46_PFEMAC0_TX_DIV_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                0U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 21U
            {
                PFEMAC0_RX_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_47_PFEMAC0_RX_CLK */
                (                                           /* IER for CMU_FC_47_PFEMAC0_RX_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                48000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 22U
            {
                PFEMAC1_TX_DIV_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_48_PFEMAC1_TX_DIV_CLK */
                (                                           /* IER for CMU_FC_48_PFEMAC1_TX_DIV_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                0U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 23U
            {
                PFEMAC1_RX_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_49_PFEMAC1_RX_CLK */
                (                                           /* IER for CMU_FC_49_PFEMAC1_RX_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                48000000U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 24U
            {
                PFEMAC2_TX_DIV_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_50_PFEMAC2_TX_DIV_CLK */
                (                                           /* IER for CMU_FC_50_PFEMAC2_TX_DIV_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                0U,
            },
            #endif
            #if CLOCK_IP_CMUS_NO > 25U
            {
                PFEMAC2_RX_CLK,            /* Clock name associated to clock monitor. */
                0U,                   /*Enable/disable clock monitor CMU_FC_51_PFEMAC2_RX_CLK */
                (                                           /* IER for CMU_FC_51_PFEMAC2_RX_CLK */
                CMU_FC_IER_FLLIE(0U) |
                CMU_FC_IER_FHHIE(0U) |
                CMU_FC_IER_FLLAIE(0U) |
                CMU_FC_IER_FHHAIE(0U)
                ),
                48000000U,
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
                133333333U,
            },
            #endif

            #if CLOCK_IP_CONFIGURED_FREQUENCIES_NO > 3U
            {
                XBAR_CLK,
                400000000U,
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


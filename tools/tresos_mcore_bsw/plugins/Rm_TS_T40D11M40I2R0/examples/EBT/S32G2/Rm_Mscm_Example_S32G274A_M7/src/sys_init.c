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
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
*/
/*==================================================================================================
*   @file    sys_init.c
*   @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
*
*   @brief   AUTOSAR M4_SRC_MODULE_NAME - RTD auxiliary APIs used for RTD testing
*   @details RTD auxiliary APIs used for RTD testing
*            This file contains sample code only. It is not part of the production code deliverables
==================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "sys_init.h"
#include "Mcal.h"
#if defined(S32G2XX)
    #include "S32G274A_FXOSC.h"
    #include "S32G274A_PLLDIG.h"
    #include "S32G274A_DFS.h"
    #include "S32G274A_MC_CGM.h"
    #include "S32G274A_MC_CGM_1.h"
    #include "S32G274A_MC_CGM_2.h"
    #include "S32G274A_SYSTICK.h"
#elif defined(S32R45)
    #include "S32R45_FXOSC.h"
    #include "S32R45_PLLDIG.h"
    #include "S32R45_DFS.h"
    #include "S32R45_MC_CGM.h"
    #include "S32R45_MC_CGM_1.h"
    #include "S32R45_MC_CGM_2.h"
    #include "S32R45_SYSTICK.h"
#elif defined(S32G3XX)
    #include "S32G399A_FXOSC.h"
    #include "S32G399A_PLLDIG.h"
    #include "S32G399A_DFS.h"
    #include "S32G399A_MC_CGM.h"
    #include "S32G399A_MC_CGM_1.h"
    #include "S32G399A_MC_CGM_2.h"
    #include "S32G399A_SYSTICK.h"
#endif
#if (MCAL_PLATFORM_ARM  == MCAL_ARM_AARCH64)
#include "gic500.h"
#else
#include "nvic.h"
#endif
/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/
#define SYS_USE_FXOSC   (STD_ON)
#define SYS_USE_FIRC    (STD_OFF)

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

static int Init_FXOSC(void);
static int Init_Core_PLL(void);
static int Init_Peripheral_PLL(void);
static int Init_Core_DFS(void);
static int Init_Peripheral_DFS(void);
static int Init_MC_CGM(void);
static int Switch_Core_FIRC(void);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/** 
* @brief sys_enableAllInterrupts
* @details function used to enable all interrupts
*/
/*================================================================================================*/
void sys_enableAllInterrupts(void)
{
     OsIf_ResumeAllInterrupts() ;
}
/*================================================================================================*/
/** 
* @brief sys_disableAllInterrupts
* @details function used to disable all interrupts
*/
/*================================================================================================*/
void sys_disableAllInterrupts(void)
{
    OsIf_SuspendAllInterrupts() ;
}
/*================================================================================================*/
/** 
* @brief sys_disableIsrSource
* @details function used to disable the interrupt number id
*/
/*================================================================================================*/
void sys_disableIsrSource(uint8 id)
{
    
#if  (MCAL_PLATFORM_ARM  == MCAL_ARM_AARCH64)  
    gic500_disableIntID(id);
#else
    NVIC_DisableIRQ(id);
#endif
}
/*================================================================================================*/
/** 
* @brief sys_init
* @details function used to enable the interrupt number id and set up the priority
*/
/*================================================================================================*/
void sys_enableIsrSource(uint8 id, uint8 prio)
{
#if  (MCAL_PLATFORM_ARM  == MCAL_ARM_AARCH64)  
    gic500_enableIntID(id);
    gic500_setIntPriority(id, prio);
    gic500_makeIntGroup0(id);
    gic500_configureSPI(id, GIC_EDGE);
#else
    NVIC_SetPriority(id, prio);
    NVIC_EnableIRQ(id);
#endif    
}
/*================================================================================================*/
/** 
* @brief sys_init
* @details function used to register the interrupt handler in the interrupt vector
*/
/*================================================================================================*/
void sys_registerIsrHandler(uint8 irq_id, int_function_t isr_handler)
{
    OsIf_SuspendAllInterrupts() ;
#if  (MCAL_PLATFORM_ARM  == MCAL_ARM_AARCH64)
    g_INT_vectors[irq_id] = isr_handler;
#else
    *(volatile uint32*)((*(volatile uint32*)(0xE000ED08)) + ((16 + irq_id) << 2)) = (uint32)isr_handler;
#endif
    OsIf_ResumeAllInterrupts() ;  
}
/*================================================================================================*/
/** 
* @brief sys_init
* @details function used to clear pending interrupt
*/
/*================================================================================================*/
#if  (MCAL_PLATFORM_ARM  == MCAL_ARM_AARCH64)
void  sys_clearIntPending(uint8 irq_id)
{
    gic500_clearIntPending(irq_id);
}
#endif


/*================================================================================================*/
/*
 * system initialization : system clock, interrupt router ...
 */


/*-----------------------------------------------------------------------*/
/* Initialize & start the Xtal FXSOC=?MHz*/
/*-----------------------------------------------------------------------*/
static int Init_FXOSC(void)
{
    uint32 timeout = 0xFFFF;
    volatile int result = 0;
    /* IP_FXOSC Initialization */
    IP_FXOSC->CTRL &= ~FXOSC_CTRL_EOCV_MASK;
    IP_FXOSC->CTRL |= FXOSC_CTRL_EOCV(0x80);            /* EOCV value = 0x80 interrupt masked*/
    IP_FXOSC->CTRL &= ~FXOSC_CTRL_OSC_BYP_MASK;
    IP_FXOSC->CTRL |= FXOSC_CTRL_OSC_BYP(0);
    IP_FXOSC->CTRL &= ~FXOSC_CTRL_COMP_EN_MASK;
    IP_FXOSC->CTRL |= FXOSC_CTRL_COMP_EN(1);
    IP_FXOSC->CTRL &= ~FXOSC_CTRL_OSCON_MASK;
    IP_FXOSC->CTRL |= FXOSC_CTRL_OSCON(1);
    while((((IP_FXOSC->STAT & FXOSC_STAT_OSC_STAT_MASK) >> FXOSC_STAT_OSC_STAT_SHIFT) != 1) && (timeout--)) {}
    if(timeout == 0)
    {
        result = 1;/* FXOSC_TIMEOUT */
    }
    else
    {
        
    }
    return result; /*Success*/
}
/*-----------------------------------------------------------------------*/
/* Initialize the Core_PLL*/
/*XSOC =40MHz, Core=?MHz, VCO=2GHz*/
/*-----------------------------------------------------------------------*/
static int Init_Core_PLL(void)
{
    uint32 timeout = 0xFFFF;    
    volatile int result = 0;
    /* Analog PLL for Core
     * <SDMEN=0, SSCGBYP=1 => PLL in integer-only mode>
     * Fvco = Fref x (PLLDV[MFI] / PLLDV[RDIV])
     * Fclkout = Fvco / (PLLODIV_n[DIV] + 1)
     * Fvco(IP_CORE_PLL) = 2.0GHz
     * f(pll_ref) = 40d (40Mhz)
     * PLLDV[RDIV] = 1
     * PLLDV[MFI] = 50d (0x32)
     */
    IP_CORE_PLL->PLLCR &= ~PLLDIG_PLLCR_PLLPD_MASK;
    IP_CORE_PLL->PLLCR |= PLLDIG_PLLCR_PLLPD(1);                     /* Disable PLL */
    
    IP_CORE_PLL->PLLODIV[0] &= ~PLLDIG_PLLODIV_DE_MASK;
    IP_CORE_PLL->PLLODIV[0] |= PLLDIG_PLLODIV_DE(0);                   /* Disable PLL output for A53 core */
    IP_CORE_PLL->PLLODIV[1] &= ~PLLDIG_PLLODIV_DE_MASK;
    IP_CORE_PLL->PLLODIV[1] |= PLLDIG_PLLODIV_DE(0);                   /* not used */
    
    IP_CORE_PLL->PLLODIV[0] &= ~PLLDIG_PLLODIV_DIV_MASK;
    IP_CORE_PLL->PLLODIV[0] |= PLLDIG_PLLODIV_DIV(1);                  /* Core A53 DIV 2 = 1000 MHz */
               
    IP_CORE_PLL->PLLDV &= ~PLLDIG_PLLDV_RDIV_MASK;
    IP_CORE_PLL->PLLDV |= PLLDIG_PLLDV_RDIV(1);
    IP_CORE_PLL->PLLDV &= ~PLLDIG_PLLDV_MFI_MASK;
    IP_CORE_PLL->PLLDV |= PLLDIG_PLLDV_MFI(50);
    IP_CORE_PLL->PLLFD &= ~PLLDIG_PLLFD_MFN_MASK;
    IP_CORE_PLL->PLLFD |= PLLDIG_PLLFD_MFN(0);

#if ( SYS_USE_FXOSC == STD_ON )    
    IP_CORE_PLL->PLLCLKMUX &= ~PLLDIG_PLLCLKMUX_REFCLKSEL_MASK;
    IP_CORE_PLL->PLLCLKMUX |= PLLDIG_PLLCLKMUX_REFCLKSEL(1);                /* FXOSC_FREQ = 40MHz as source for PLL */
#endif
#if ( SYS_USE_FIRC == STD_ON )  
    IP_CORE_PLL->PLLCLKMUX &= ~PLLDIG_PLLCLKMUX_REFCLKSEL_MASK;
    IP_CORE_PLL->PLLCLKMUX |= PLLDIG_PLLCLKMUX_REFCLKSEL(0);              /* FIRC_FREQ = 48MHz (fixed) as source for PLL */
#endif        
    IP_CORE_PLL->PLLFD &= ~PLLDIG_PLLFD_SDMEN_MASK;
    IP_CORE_PLL->PLLFD |= PLLDIG_PLLFD_SDMEN(0);
    IP_CORE_PLL->PLLFM &= ~PLLDIG_PLLFM_SSCGBYP_MASK;
    IP_CORE_PLL->PLLFM |= PLLDIG_PLLFM_SSCGBYP(1);
    IP_CORE_PLL->PLLFM &= ~PLLDIG_PLLFM_STEPNO_MASK;
    IP_CORE_PLL->PLLFM |= PLLDIG_PLLFM_STEPNO(0);
    IP_CORE_PLL->PLLFM &= ~PLLDIG_PLLFM_STEPSIZE_MASK;
    IP_CORE_PLL->PLLFM |= PLLDIG_PLLFM_STEPSIZE(0);
                
    IP_CORE_PLL->PLLCR &= ~PLLDIG_PLLCR_PLLPD_MASK;
    IP_CORE_PLL->PLLCR |= PLLDIG_PLLCR_PLLPD(0);                     /* Enable PLL */
    IP_CORE_PLL->PLLODIV[0] &= ~PLLDIG_PLLODIV_DE_MASK;
    IP_CORE_PLL->PLLODIV[0] |= PLLDIG_PLLODIV_DE(1);                   /* Enable PLL output */

    while((((IP_CORE_PLL->PLLSR & PLLDIG_PLLSR_LOCK_MASK) >> PLLDIG_PLLSR_LOCK_SHIFT) != 1) && (timeout--)) {}
    if(timeout == 0) 
    {
        result = 1; /*CORE_PLL_TIMEOUT*/
    }
    else
    {
        
    }  
    return result; /*Success*/
}
/*-----------------------------------------------------------------------*/
/* Initialize the Peripheral_PLL*/
/*XSOC =40MHz, VCO=2GHz*/
/*-----------------------------------------------------------------------*/
static int Init_Peripheral_PLL(void)
{
    uint32 timeout = 0xFFFF;
    volatile int result = 0;
    /* Analog PLL for Peripherals
     * <SDMEN=0, SSCGBYP=1 => PLL in integer-only mode>
     * Fvco = Fref x (PLLDV[MFI] / PLLDV[RDIV])
     * Fclkout = Fvco / (PLLODIV_n[DIV] + 1)
     * Fvco = 2.0GHz
     * f(pll_ref) = 40d (40Mhz)
     * PLLDV[RDIV] = 1
     * PLLDV[MFI] = 50d (0x32)
     */
    IP_PERIPH_PLL->PLLCR &= ~PLLDIG_PLLCR_PLLPD_MASK;
    IP_PERIPH_PLL->PLLCR |= PLLDIG_PLLCR_PLLPD(1);               /* Disable PLL */
    IP_PERIPH_PLL->PLLODIV[0] &= ~PLLDIG_PLLODIV_DE_MASK;
    IP_PERIPH_PLL->PLLODIV[0] |= PLLDIG_PLLODIV_DE(0);             /* Disable all PLL outputs */
    IP_PERIPH_PLL->PLLODIV[1] &= ~PLLDIG_PLLODIV_DE_MASK;
    IP_PERIPH_PLL->PLLODIV[1] |= PLLDIG_PLLODIV_DE(0);
    IP_PERIPH_PLL->PLLODIV[2] &= ~PLLDIG_PLLODIV_DE_MASK;
    IP_PERIPH_PLL->PLLODIV[2] |= PLLDIG_PLLODIV_DE(0);
    IP_PERIPH_PLL->PLLODIV[3] &= ~PLLDIG_PLLODIV_DE_MASK;
    IP_PERIPH_PLL->PLLODIV[3] |= PLLDIG_PLLODIV_DE(0);
    IP_PERIPH_PLL->PLLODIV[4] &= ~PLLDIG_PLLODIV_DE_MASK;
    IP_PERIPH_PLL->PLLODIV[4] |= PLLDIG_PLLODIV_DE(0);
    IP_PERIPH_PLL->PLLODIV[5] &= ~PLLDIG_PLLODIV_DE_MASK;
    IP_PERIPH_PLL->PLLODIV[5] |= PLLDIG_PLLODIV_DE(0);
    IP_PERIPH_PLL->PLLODIV[6] &= ~PLLDIG_PLLODIV_DE_MASK;
    IP_PERIPH_PLL->PLLODIV[6] |= PLLDIG_PLLODIV_DE(0);
    IP_PERIPH_PLL->PLLODIV[7] &= ~PLLDIG_PLLODIV_DE_MASK;
    IP_PERIPH_PLL->PLLODIV[7] |= PLLDIG_PLLODIV_DE(0);
        
#if ( SYS_USE_FXOSC == STD_ON )    
    IP_PERIPH_PLL->PLLCLKMUX &= ~PLLDIG_PLLCLKMUX_REFCLKSEL_MASK;
    IP_PERIPH_PLL->PLLCLKMUX |= PLLDIG_PLLCLKMUX_REFCLKSEL(1);        /* FXOSC_FREQ = 40MHz as source for PLL */
#endif
#if ( SYS_USE_FIRC == STD_ON )  
    IP_PERIPH_PLL->PLLCLKMUX &= ~PLLDIG_PLLCLKMUX_REFCLKSEL_MASK;
    IP_PERIPH_PLL->PLLCLKMUX |= PLLDIG_PLLCLKMUX_REFCLKSEL(0);          /* FIRC_FREQ = 48MHz (fixed) as source for PLL */
#endif 
    
    IP_PERIPH_PLL->PLLDV &= ~PLLDIG_PLLDV_RDIV_MASK;
    IP_PERIPH_PLL->PLLDV |= PLLDIG_PLLDV_RDIV(1);
    IP_PERIPH_PLL->PLLDV &= ~PLLDIG_PLLDV_MFI_MASK;
    IP_PERIPH_PLL->PLLDV |= PLLDIG_PLLDV_MFI(50);
    IP_PERIPH_PLL->PLLFD &= ~PLLDIG_PLLFD_MFN_MASK;
    IP_PERIPH_PLL->PLLFD |= PLLDIG_PLLFD_MFN(0);
    
    /* CLOCK input = Fvco = 2 GHz*/
    IP_PERIPH_PLL->PLLODIV[0] &= ~PLLDIG_PLLODIV_DIV_MASK;
    IP_PERIPH_PLL->PLLODIV[0] |= PLLDIG_PLLODIV_DIV((50-1));     /* PERIPH_PLL_PHI0_CLK = 40 MHz. (PCIE_0_REF_CLK[100-125MHz]) */
    IP_PERIPH_PLL->PLLODIV[1] &= ~PLLDIG_PLLODIV_DIV_MASK;
    IP_PERIPH_PLL->PLLODIV[1] |= PLLDIG_PLLODIV_DIV((25-1));     /* PERIPH_PLL_PHI1_CLK = 80 MHz. (PER_CLK[<80MHz],FTM_0_REF_CLK[<20MHz],FTM_1_REF_CLK[<20MHz],FLEXRAY_PE_CLK[<40MHz]) */
    IP_PERIPH_PLL->PLLODIV[2] &= ~PLLDIG_PLLODIV_DIV_MASK;
    IP_PERIPH_PLL->PLLODIV[2] |= PLLDIG_PLLODIV_DIV((50-1));     /* PERIPH_PLL_PHI2_CLK = 40 MHz. (CAN_PE_CLK[40-80MHz]) */
    IP_PERIPH_PLL->PLLODIV[3] &= ~PLLDIG_PLLODIV_DIV_MASK;
    IP_PERIPH_PLL->PLLODIV[3] |= PLLDIG_PLLODIV_DIV((25-1));     /* PERIPH_PLL_PHI3_CLK = 80 MHz. (LINFLEXD_CLK[<66.7MHz], LIN_BAUD_CLK[<133MHz]) */
    IP_PERIPH_PLL->PLLODIV[4] &= ~PLLDIG_PLLODIV_DIV_MASK;
    IP_PERIPH_PLL->PLLODIV[4] |= PLLDIG_PLLODIV_DIV((50-1));     /* PERIPH_PLL_PHI4_CLK = 40 MHz. (GMAC_TS_CLK[5-200MHz])   */
    IP_PERIPH_PLL->PLLODIV[5] &= ~PLLDIG_PLLODIV_DIV_MASK;
    IP_PERIPH_PLL->PLLODIV[5] |= PLLDIG_PLLODIV_DIV((16-1));     /* PERIPH_PLL_PHI5_CLK = 125 MHz.(GMAC_0_TX_CLK[2.5-125MHz])  */
    /*((IP_PERIPH_PLL->PLLODIV & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) = ;*/       /* not used */
    IP_PERIPH_PLL->PLLODIV[7] &= ~PLLDIG_PLLODIV_DIV_MASK;
    IP_PERIPH_PLL->PLLODIV[7] |= PLLDIG_PLLODIV_DIV((50-1));     /* PERIPH_PLL_PHI7_CLK = 40 MHz (SPI_CLK[10-100MHz]) */
    
    IP_PERIPH_PLL->PLLCR &= ~PLLDIG_PLLCR_PLLPD_MASK;
    IP_PERIPH_PLL->PLLCR |= PLLDIG_PLLCR_PLLPD(0);             /* Enable PLL */
            
    while((((IP_PERIPH_PLL->PLLSR & PLLDIG_PLLSR_LOCK_MASK) >> PLLDIG_PLLSR_LOCK_SHIFT) != 1) && (timeout--)) {}
    if(timeout == 0) 
    {
        result = 1; /*CORE_PLL_TIMEOUT*/
    }
    else
    {
        
    }  
        
    /*((IP_PERIPH_PLL->PLLODIV & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT) = 1;*/             /* Enable all PLL outputs */
    IP_PERIPH_PLL->PLLODIV[1] &= ~PLLDIG_PLLODIV_DE_MASK;
    IP_PERIPH_PLL->PLLODIV[1] |= PLLDIG_PLLODIV_DE(1);
    IP_PERIPH_PLL->PLLODIV[2] &= ~PLLDIG_PLLODIV_DE_MASK;
    IP_PERIPH_PLL->PLLODIV[2] |= PLLDIG_PLLODIV_DE(1);
    IP_PERIPH_PLL->PLLODIV[3] &= ~PLLDIG_PLLODIV_DE_MASK;
    IP_PERIPH_PLL->PLLODIV[3] |= PLLDIG_PLLODIV_DE(1);
    /*((IP_PERIPH_PLL->PLLODIV & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT) = 1;*/
    IP_PERIPH_PLL->PLLODIV[5] &= ~PLLDIG_PLLODIV_DE_MASK;
    IP_PERIPH_PLL->PLLODIV[5] |= PLLDIG_PLLODIV_DE(1);
    /*((IP_PERIPH_PLL->PLLODIV & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT) = 1;*/
    IP_PERIPH_PLL->PLLODIV[7] &= ~PLLDIG_PLLODIV_DE_MASK;
    IP_PERIPH_PLL->PLLODIV[7] |= PLLDIG_PLLODIV_DE(1);
        
    return result; /*Success*/
}
/*-----------------------------------------------------------------------*/
/* Initialize the Core_DFS*/
/*XSOC =40MHz, Core=?MHz*/
/*-----------------------------------------------------------------------*/
static int Init_Core_DFS(void)
{
    uint32 timeout = 0xFFFF;    
    volatile int result = 0;
    /* Fdfs = PLLvco / (2* (MFI+(MFN/36)) ) */
    IP_CORE_DFS->PORTRESET = 0x3F;
    IP_CORE_DFS->CTL &= ~DFS_CTL_DFS_RESET_MASK;
    IP_CORE_DFS->CTL |= DFS_CTL_DFS_RESET(1);
    IP_CORE_DFS->DVPORT[0] &= ~DFS_DVPORT_MFI_MASK;
    IP_CORE_DFS->DVPORT[0] |= DFS_DVPORT_MFI(1);
    IP_CORE_DFS->DVPORT[0] &= ~DFS_DVPORT_MFN_MASK;
    IP_CORE_DFS->DVPORT[0] |= DFS_DVPORT_MFN(9);       /* CORE_DFS1_CLK[<800MHz] = 800MHz */
                                        /*  CORE_DFS1_CLK       -> XBAR_2X_CLK[?]           = 800MHz   
                                            CORE_DFS1_CLK/2     -> XBAR_CLK/M7[24-400MHz]   = 400MHz
                                            CORE_DFS1_CLK/4     -> XBAR_DIV2_CLK[12-200MHz] = 200MHz
                                            CORE_DFS1_CLK/4/2   -> XBAR_DIV4_CLK[?]         = 100MHZ
                                            CORE_DFS1_CLK/6     -> XBAR_DIV3_CLK[8-133MHz]  = 133MHz
                                            CORE_DFS1_CLK/12    -> XBAR_DIV6_CLK[?]         = 66MHz
                                        */
    IP_CORE_DFS->CTL &= ~DFS_CTL_DFS_RESET_MASK;
    IP_CORE_DFS->CTL |= DFS_CTL_DFS_RESET(0);
    IP_CORE_DFS->PORTRESET &= ~DFS_PORTRESET_RESET0_MASK;
    IP_CORE_DFS->PORTRESET |= DFS_PORTRESET_RESET0(0);    /* Deassert reset for CORE_DFS1_CLK to IP_MC_CGM_0 */
#if defined(S32G2XX)
    while(( (((IP_CORE_DFS->PORTSR & DFS_PORTSR_PORTSTAT_MASK) >> DFS_PORTSR_PORTSTAT_SHIFT) & 0x01) != 1) && (timeout--)) {}
#elif defined(S32R45)
    while(( (((IP_CORE_DFS->PORTSR & DFS_PORTSR_PORTSTAT0_MASK) >> DFS_PORTSR_PORTSTAT0_SHIFT) & 0x01) != 1) && (timeout--)) {}
#endif
    if(timeout == 0) 
    {
        result = 1;/* DFS_TIMEOUT */
    }
    else
    {
        
    }  
    return result; /*Success*/
}
/*-----------------------------------------------------------------------*/
/* Initialize the Core_DFS*/
/*XSOC =40MHz */
/*-----------------------------------------------------------------------*/
static int Init_Peripheral_DFS(void)
{
    uint32 timeout = 0xFFFF;
    volatile int result = 0;
    
    /* Fdfs = PLLvco / (2* (MFI+(MFN/36)) ) */
    IP_PERIPH_DFS->PORTRESET = 0x3F;
    IP_PERIPH_DFS->CTL &= ~DFS_CTL_DFS_RESET_MASK;
    IP_PERIPH_DFS->CTL |= DFS_CTL_DFS_RESET(1);
    IP_PERIPH_DFS->DVPORT[0] &= ~DFS_DVPORT_MFI_MASK;
    IP_PERIPH_DFS->DVPORT[0] |= DFS_DVPORT_MFI(1);
    IP_PERIPH_DFS->DVPORT[0] &= ~DFS_DVPORT_MFN_MASK;
    IP_PERIPH_DFS->DVPORT[0] |= DFS_DVPORT_MFN(9);       /* PERIPH_DFS1_CLK[<=800MHz] = 800MHz -> QSPI_1X_CLK, QSPI_2X_CLK*/
    IP_PERIPH_DFS->DVPORT[1] &= ~DFS_DVPORT_MFI_MASK;
    IP_PERIPH_DFS->DVPORT[1] |= DFS_DVPORT_MFI(5);
    IP_PERIPH_DFS->DVPORT[1] &= ~DFS_DVPORT_MFN_MASK;
    IP_PERIPH_DFS->DVPORT[1] |= DFS_DVPORT_MFN(0);       /* PERIPH_DFS2_CLK[<800MHz] = 200MHz -> CLKOUT*/
    IP_PERIPH_DFS->DVPORT[2] &= ~DFS_DVPORT_MFI_MASK;
    IP_PERIPH_DFS->DVPORT[2] |= DFS_DVPORT_MFI(2);
    IP_PERIPH_DFS->DVPORT[2] &= ~DFS_DVPORT_MFN_MASK;
    IP_PERIPH_DFS->DVPORT[2] |= DFS_DVPORT_MFN(18);       /* PERIPH_DFS3_CLK[<800MHz] = 400MHz -> SDHC_CLK*/
    IP_PERIPH_DFS->CTL &= ~DFS_CTL_DFS_RESET_MASK;
    IP_PERIPH_DFS->CTL |= DFS_CTL_DFS_RESET(0);
    IP_PERIPH_DFS->PORTRESET &= ~DFS_PORTRESET_RESET0_MASK;
    IP_PERIPH_DFS->PORTRESET |= DFS_PORTRESET_RESET0(0);    /* Deassert reset for PERIPH_DFS1_CLK to MC_CGM_12(QSPI) */
    IP_PERIPH_DFS->PORTRESET &= ~DFS_PORTRESET_RESET1_MASK;
    IP_PERIPH_DFS->PORTRESET |= DFS_PORTRESET_RESET1(0);    /* Deassert reset for PERIPH_DFS2_CLK to CLKOUT */
    IP_PERIPH_DFS->PORTRESET &= ~DFS_PORTRESET_RESET2_MASK;
    IP_PERIPH_DFS->PORTRESET |= DFS_PORTRESET_RESET2(0);    /* Deassert reset for PERIPH_DFS3_CLK to MC_CGM_14(SDHC) */

#if defined(S32G2XX)
    while(( (((IP_PERIPH_DFS->PORTSR & DFS_PORTSR_PORTSTAT_MASK) >> DFS_PORTSR_PORTSTAT_SHIFT) & 0x07) != 7) && (timeout--)) {}
#elif defined(S32R45)
    while(( (((IP_PERIPH_DFS->PORTSR & (DFS_PORTSR_PORTSTAT0_MASK|DFS_PORTSR_PORTSTAT1_MASK|DFS_PORTSR_PORTSTAT2_MASK)) >> DFS_PORTSR_PORTSTAT0_SHIFT) & 0x07) != 7) && (timeout--)) {}
#endif    
    /*while(( (((IP_PERIPH_DFS->PORTSR & DFS_PORTSR_PORTSTAT_MASK) >> DFS_PORTSR_PORTSTAT_SHIFT) & 0x05) != 5) && (timeout--)) {}*/
    if(timeout == 0) 
    {
        result = 1; /*DFS_TIMEOUT*/
    }
    else
    {
        
    }       
    return result; /*Success*/
}


/* Table 23-3. MC_CGM clock source mapping
Clock selector index    Clock source
0                       FIRC_CLK
1                       SIRC_CLK
2                       FXOSC_CLK (CLKOUT0/1)   
3                       SXOSC_CLK (Reserved)
4                       CORE_PLL_PHI0_CLK
5                       CORE_PLL_PHI1_CLK
6                       CORE_PLL_PHI2_CLK (Reserved)
7                       CORE_PLL_PHI3_CLK (Reserved)
8                       CORE_PLL_PHI4_CLK (Reserved)
9                       CORE_PLL_PHI5_CLK (Reserved)
10                      CORE_PLL_PHI6_CLK (Reserved)
11                      CORE_PLL_PHI7_CLK (Reserved)
12                      CORE_DFS1_CLK
13                      CORE_DFS2_CLK
14                      CORE_DFS3_CLK
15                      CORE_DFS4_CLK
16                      CORE_DFS5_CLK
17                      CORE_DFS6_CLK
18                      PERIPH_PLL_PHI0_CLK (CLKOUT0/1)
19                      PERIPH_PLL_PHI1_CLK
20                      PERIPH_PLL_PHI2_CLK
21                      PERIPH_PLL_PHI3_CLK
22                      PERIPH_PLL_PHI4_CLK
23                      PERIPH_PLL_PHI5_CLK
24                      PERIPH_PLL_PHI6_CLK
25                      PERIPH_PLL_PHI7_CLK
26                      PERIPH_DFS1_CLK
27                      PERIPH_DFS2_CLK (CLKOUT0/1)
28                      PERIPH_DFS3_CLK
29                      PERIPH_DFS4_CLK
30                      PERIPH_DFS5_CLK (CLKOUT0/1)
31                      PERIPH_DFS6_CLK
32                      ACCEL_PLL_PHI0_CLK
33                      ACCEL_PLL_PHI1_CLK
34                      FTM_0_EXT_REF_CLK
35                      FTM_1_EXT_REF_CLK
36                      DDR_PLL PHI0
37                      GMAC_0_EXT_TX_CLK
38                      GMAC_0_EXT_RX_CLK
39                      GMAC_0_EXT_REF_CLK
40                      SERDES_0_LANE_0_TX_CLK
41                      SERDES_0_LANE_0_CDR_CLK
44                      GMAC_EXT_TS_CLK
45                      GMAC_0_REF_DIV_CLK
46                      SERDES_0_LANE_1_TX_CLK (CLKOUT0/1)
47                      SERDES_0_LANE_1_CDR_CLK (CLKOUT1)
48                      PFE_MAC_0_EXT_TX_CLK
49                      PFE_MAC_0_EXT_RX_CLK
50                      PFE_MAC_0_EXT_REF_CLK
51                      PFE_MAC_1_EXT_TX_CLK
52                      PFE_MAC_1_EXT_RX_CLK
53                      PFE_MAC_1_EXT_REF_CLK
54                      PFE_MAC_2_EXT_TX_CLK
55                      PFE_MAC_2_EXT_RX_CLK
56                      PFE_MAC_2_EXT_REF_CLK
57                      SERDES_1_LANE_0_TX_CLK
58                      SERDES_1_LANE_0_CDR_CLK
59                      PFE_MAC_0_REF_DIV_CLK
60                      PFE_MAC_1_REF_DIV_CLK
61                      PFE_MAC_2_REF_DIV_CLK
62                      SERDES_1_LANE_1_TX_CLK
63                      SERDES_1_LANE_1_CDR_CLK
*/
/*-----------------------------------------------------------------------*/
/* Initialize the MC_CGM */
/*-----------------------------------------------------------------------*/
static int Init_MC_CGM(void)
{
   
    /* Disable all mux dividers */
    /*((IP_MC_CGM_0->MUX_0_DC_0 & MC_CGM_DC_DE_MASK) >> MC_CGM_DC_DE_SHIFT)  = 0;*/     /*LBIST_CLK - do not disable the core MUX0*/
    /*((IP_MC_CGM_0->MUX_0_DC_1 & MC_CGM_DC_DE_MASK) >> MC_CGM_DC_DE_SHIFT)  = 0;*/     /*DAPB_CLK - do not disable the core MUX0*/
    IP_MC_CGM_0->MUX_1_DC_0 &= ~MC_CGM_MUX_1_DC_0_DE_MASK;
    IP_MC_CGM_0->MUX_1_DC_0 |= MC_CGM_MUX_1_DC_0_DE(0);     /*CLKOUT0*/
    IP_MC_CGM_0->MUX_2_DC_0 &= ~MC_CGM_MUX_2_DC_0_DE_MASK;
    IP_MC_CGM_0->MUX_2_DC_0 |= MC_CGM_MUX_2_DC_0_DE(0);     /*CLKOUT1*/
    IP_MC_CGM_0->MUX_3_DC_0 &= ~MC_CGM_MUX_3_DC_0_DE_MASK;
    IP_MC_CGM_0->MUX_3_DC_0 |= MC_CGM_MUX_3_DC_0_DE(0);     /*PER_CLK*/
    IP_MC_CGM_0->MUX_4_DC_0 &= ~MC_CGM_MUX_4_DC_0_DE_MASK;
    IP_MC_CGM_0->MUX_4_DC_0 |= MC_CGM_MUX_4_DC_0_DE(0);     /*FTM_0_REF_CLK*/
    IP_MC_CGM_0->MUX_5_DC_0 &= ~MC_CGM_MUX_5_DC_0_DE_MASK;
    IP_MC_CGM_0->MUX_5_DC_0 |= MC_CGM_MUX_5_DC_0_DE(0);     /*FTM_1_REF_CLK*/
    IP_MC_CGM_0->MUX_6_DC_0 &= ~MC_CGM_MUX_6_DC_0_DE_MASK;
    IP_MC_CGM_0->MUX_6_DC_0 |= MC_CGM_MUX_6_DC_0_DE(0);     /*FLEXRAY_PE_CLK*/
#ifndef S32G3XX
    IP_MC_CGM_0->MUX_9_DC_0 &= ~MC_CGM_MUX_9_DC_0_DE_MASK;
    IP_MC_CGM_0->MUX_9_DC_0 |= MC_CGM_MUX_9_DC_0_DE(0);     /*GMAC_TS_CLK*/
    IP_MC_CGM_0->MUX_10_DC_0 &= ~MC_CGM_MUX_10_DC_0_DE_MASK;
    IP_MC_CGM_0->MUX_10_DC_0 |= MC_CGM_MUX_10_DC_0_DE(0);     /*GMAC_0_TX_CLK*/
    IP_MC_CGM_0->MUX_12_DC_0 &= ~MC_CGM_MUX_12_DC_0_DE_MASK;
    IP_MC_CGM_0->MUX_12_DC_0 |= MC_CGM_MUX_12_DC_0_DE(0);     /*QSPI_2X_CLK*/
    IP_MC_CGM_0->MUX_14_DC_0 &= ~MC_CGM_MUX_14_DC_0_DE_MASK;
    IP_MC_CGM_0->MUX_14_DC_0 |= MC_CGM_MUX_14_DC_0_DE(0);     /*SDHC_CLK*/
    IP_MC_CGM_0->MUX_15_DC_0 &= ~MC_CGM_MUX_15_DC_0_DE_MASK;
    IP_MC_CGM_0->MUX_15_DC_0 |= MC_CGM_MUX_15_DC_0_DE(0);     /*GMAC_0_REF_DIV_CLK*/
#endif
    while(((IP_MC_CGM_0->MUX_0_CSS & MC_CGM_MUX_0_CSS_SWIP_MASK) >> MC_CGM_MUX_0_CSS_SWIP_SHIFT)  != 0) {}    /* Verify that we don't have switching in progress*/
    while(((IP_MC_CGM_0->MUX_3_CSS & MC_CGM_MUX_3_CSS_SWIP_MASK) >> MC_CGM_MUX_3_CSS_SWIP_SHIFT)  != 0) {}    
    while(((IP_MC_CGM_0->MUX_4_CSS & MC_CGM_MUX_4_CSS_SWIP_MASK) >> MC_CGM_MUX_4_CSS_SWIP_SHIFT)  != 0) {}    
    while(((IP_MC_CGM_0->MUX_5_CSS & MC_CGM_MUX_5_CSS_SWIP_MASK) >> MC_CGM_MUX_5_CSS_SWIP_SHIFT)  != 0) {}    
    while(((IP_MC_CGM_0->MUX_6_CSS & MC_CGM_MUX_6_CSS_SWIP_MASK) >> MC_CGM_MUX_6_CSS_SWIP_SHIFT)  != 0) {}    
    while(((IP_MC_CGM_0->MUX_7_CSS & MC_CGM_MUX_7_CSS_SWIP_MASK) >> MC_CGM_MUX_7_CSS_SWIP_SHIFT)  != 0) {}    
    while(((IP_MC_CGM_0->MUX_8_CSS & MC_CGM_MUX_8_CSS_SWIP_MASK) >> MC_CGM_MUX_8_CSS_SWIP_SHIFT)  != 0) {}  
#ifndef S32G3XX    
    while(((IP_MC_CGM_0->MUX_9_CSS & MC_CGM_MUX_9_CSS_SWIP_MASK) >> MC_CGM_MUX_9_CSS_SWIP_SHIFT)  != 0) {}    
    while(((IP_MC_CGM_0->MUX_10_CSS & MC_CGM_MUX_10_CSS_SWIP_MASK) >> MC_CGM_MUX_10_CSS_SWIP_SHIFT) != 0) {}    
    while(((IP_MC_CGM_0->MUX_11_CSS & MC_CGM_MUX_11_CSS_SWIP_MASK) >> MC_CGM_MUX_11_CSS_SWIP_SHIFT) != 0) {}    
    while(((IP_MC_CGM_0->MUX_12_CSS & MC_CGM_MUX_12_CSS_SWIP_MASK) >> MC_CGM_MUX_12_CSS_SWIP_SHIFT) != 0) {}    
    while(((IP_MC_CGM_0->MUX_14_CSS & MC_CGM_MUX_14_CSS_SWIP_MASK) >> MC_CGM_MUX_14_CSS_SWIP_SHIFT) != 0) {}    
    while(((IP_MC_CGM_0->MUX_15_CSS & MC_CGM_MUX_15_CSS_SWIP_MASK) >> MC_CGM_MUX_15_CSS_SWIP_SHIFT) != 0) {}   
    while(((IP_MC_CGM_0->MUX_16_CSS & MC_CGM_MUX_16_CSS_SWIP_MASK) >> MC_CGM_MUX_16_CSS_SWIP_SHIFT) != 0) {}   
#endif
#if ( SYS_USE_FIRC == STD_ON )     
    IP_MC_CGM_0->MUX_0_CSC &= ~MC_CGM_MUX_0_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_0_CSC |= MC_CGM_MUX_0_CSC_SELCTL(0);    /*Select FIRC_CLK*/                 /*XBAR_CLK/M7*/
    
    IP_MC_CGM_0->MUX_1_CSC &= ~MC_CGM_MUX_1_CSC_CG_MASK;
    IP_MC_CGM_0->MUX_1_CSC |= MC_CGM_MUX_1_CSC_CG(1);      /*Enable ClockGate*/                 /*CLKOUT0*/
    while(((IP_MC_CGM_0->MUX_1_CSS & MC_CGM_MUX_1_CSS_CS_MASK) >> MC_CGM_MUX_1_CSS_CS_SHIFT) != 0) {}
    IP_MC_CGM_0->MUX_1_CSC &= ~MC_CGM_MUX_1_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_1_CSC |= MC_CGM_MUX_1_CSC_SELCTL(0);    /*Select FIRC_CLK*/                 /*CLKOUT0*/
    IP_MC_CGM_0->MUX_1_CSC &= ~MC_CGM_MUX_1_CSC_CG_MASK;
    IP_MC_CGM_0->MUX_1_CSC |= MC_CGM_MUX_1_CSC_CG(0);    /*Disable ClockGate*/          /*CLKOUT0*/
    
    IP_MC_CGM_0->MUX_2_CSC &= ~MC_CGM_MUX_2_CSC_CG_MASK;
    IP_MC_CGM_0->MUX_2_CSC |= MC_CGM_MUX_2_CSC_CG(1);      /*Enable ClockGate*/                 /*CLKOUT1*/
    while(((IP_MC_CGM_0->MUX_2_CSS & MC_CGM_MUX_2_CSS_CS_MASK) >> MC_CGM_MUX_2_CSS_CS_SHIFT) != 0) {}
    IP_MC_CGM_0->MUX_2_CSC &= ~MC_CGM_MUX_2_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_2_CSC |= MC_CGM_MUX_2_CSC_SELCTL(0);    /*Select FIRC_CLK*/                 /*CLKOUT1*/
    IP_MC_CGM_0->MUX_2_CSC &= ~MC_CGM_MUX_2_CSC_CG_MASK;
    IP_MC_CGM_0->MUX_2_CSC |= MC_CGM_MUX_2_CSC_CG(0);    /*Disable ClockGate*/          /*CLKOUT1*/
    
    IP_MC_CGM_0->MUX_3_CSC &= ~MC_CGM_MUX_3_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_3_CSC |= MC_CGM_MUX_3_CSC_SELCTL(0);    /*Select FIRC_CLK*/                 /*PER_CLK*/
    IP_MC_CGM_0->MUX_4_CSC &= ~MC_CGM_MUX_4_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_4_CSC |= MC_CGM_MUX_4_CSC_SELCTL(0);    /*Select FIRC_CLK*/                 /*FTM_0_REF_CLK*/
    IP_MC_CGM_0->MUX_5_CSC &= ~MC_CGM_MUX_5_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_5_CSC |= MC_CGM_MUX_5_CSC_SELCTL(0);    /*Select FIRC_CLK*/                 /*FTM_1_REF_CLK*/
    IP_MC_CGM_0->MUX_6_CSC &= ~MC_CGM_MUX_6_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_6_CSC |= MC_CGM_MUX_6_CSC_SELCTL(0);    /*Select FIRC_CLK*/                 /*FLEXRAY_PE_CLK*/
    IP_MC_CGM_0->MUX_7_CSC &= ~MC_CGM_MUX_7_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_7_CSC |= MC_CGM_MUX_7_CSC_SELCTL(0);    /*Select FIRC_CLK*/
    IP_MC_CGM_0->MUX_8_CSC &= ~MC_CGM_MUX_8_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_8_CSC |= MC_CGM_MUX_8_CSC_SELCTL(0);    /*Select FIRC_CLK*/
#ifndef S32G3XX
    IP_MC_CGM_0->MUX_9_CSC &= ~MC_CGM_MUX_9_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_9_CSC |= MC_CGM_MUX_9_CSC_SELCTL(0);    /*Select FIRC_CLK*/                 /*GMAC_TS_CLK*/
    IP_MC_CGM_0->MUX_10_CSC &= ~MC_CGM_MUX_10_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_10_CSC |= MC_CGM_MUX_10_CSC_SELCTL(0);    /*Select FIRC_CLK*/                 /*GMAC_0_TX_CLK*/
    IP_MC_CGM_0->MUX_11_CSC &= ~MC_CGM_MUX_11_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_11_CSC |= MC_CGM_MUX_11_CSC_SELCTL(0);    /*Select FIRC_CLK*/
    IP_MC_CGM_0->MUX_12_CSC &= ~MC_CGM_MUX_12_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_12_CSC |= MC_CGM_MUX_12_CSC_SELCTL(0);    /*Select FIRC_CLK*/                 /*QSPI_2X_CLK*/
    IP_MC_CGM_0->MUX_14_CSC &= ~MC_CGM_MUX_14_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_14_CSC |= MC_CGM_MUX_14_CSC_SELCTL(0);    /*Select FIRC_CLK*/                 /*SDHC_CLK*/
    IP_MC_CGM_0->MUX_15_CSC &= ~MC_CGM_MUX_15_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_15_CSC |= MC_CGM_MUX_15_CSC_SELCTL(0);    /*Select FIRC_CLK*/                 /*GMAC_0_REF_DIV_CLK*/
    IP_MC_CGM_0->MUX_16_CSC &= ~MC_CGM_MUX_16_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_16_CSC |= MC_CGM_MUX_16_CSC_SELCTL(0);    /*Select FIRC_CLK*/                 /*SPI_CLK*/
#endif
#endif    
#if ( SYS_USE_FXOSC == STD_ON )     
    IP_MC_CGM_0->MUX_0_CSC &= ~MC_CGM_MUX_0_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_0_CSC |= MC_CGM_MUX_0_CSC_SELCTL(12);    /*Select CORE_DFS1_CLK*/            /*XBAR_CLK/M7*/
    
    IP_MC_CGM_0->MUX_1_CSC &= ~MC_CGM_MUX_1_CSC_CG_MASK;
    IP_MC_CGM_0->MUX_1_CSC |= MC_CGM_MUX_1_CSC_CG(1);    /*Enable ClockGate*/      /*CLKOUT0*/
    while(((IP_MC_CGM_0->MUX_1_CSS & MC_CGM_MUX_1_CSS_CS_MASK) >> MC_CGM_MUX_1_CSS_CS_SHIFT) != 0) {}
    IP_MC_CGM_0->MUX_1_CSC &= ~MC_CGM_MUX_1_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_1_CSC |= MC_CGM_MUX_1_CSC_SELCTL(18);    /*Select PERIPH_PLL_PHI0_CLK*/      /*CLKOUT0*/
    IP_MC_CGM_0->MUX_1_CSC &= ~MC_CGM_MUX_1_CSC_CG_MASK;
    IP_MC_CGM_0->MUX_1_CSC |= MC_CGM_MUX_1_CSC_CG(0);    /*Disable ClockGate*/          /*CLKOUT0*/
    
    IP_MC_CGM_0->MUX_2_CSC &= ~MC_CGM_MUX_2_CSC_CG_MASK;
    IP_MC_CGM_0->MUX_2_CSC |= MC_CGM_MUX_2_CSC_CG(1);    /*Enable ClockGate*/          /*CLKOUT1*/
    while(((IP_MC_CGM_0->MUX_2_CSS & MC_CGM_MUX_2_CSS_CS_MASK) >> MC_CGM_MUX_2_CSS_CS_SHIFT) != 0) {}
    IP_MC_CGM_0->MUX_2_CSC &= ~MC_CGM_MUX_2_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_2_CSC |= MC_CGM_MUX_2_CSC_SELCTL(27);    /*Select PERIPH_DFS2_CLK*/          /*CLKOUT1*/
    IP_MC_CGM_0->MUX_2_CSC &= ~MC_CGM_MUX_2_CSC_CG_MASK;
    IP_MC_CGM_0->MUX_2_CSC |= MC_CGM_MUX_2_CSC_CG(0);    /*Disable ClockGate*/          /*CLKOUT1*/
    
    IP_MC_CGM_0->MUX_3_CSC &= ~MC_CGM_MUX_3_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_3_CSC |= MC_CGM_MUX_3_CSC_SELCTL(19);    /*Select PERIPH_PLL_PHI1_CLK*/      /*PER_CLK*/
    IP_MC_CGM_0->MUX_4_CSC &= ~MC_CGM_MUX_4_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_4_CSC |= MC_CGM_MUX_4_CSC_SELCTL(19);    /*Select PERIPH_PLL_PHI1_CLK*/      /*FTM_0_REF_CLK*/
    IP_MC_CGM_0->MUX_5_CSC &= ~MC_CGM_MUX_5_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_5_CSC |= MC_CGM_MUX_5_CSC_SELCTL(19);    /*Select PERIPH_PLL_PHI1_CLK*/      /*FTM_1_REF_CLK*/
    IP_MC_CGM_0->MUX_6_CSC &= ~MC_CGM_MUX_6_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_6_CSC |= MC_CGM_MUX_6_CSC_SELCTL(19);    /*Select PERIPH_PLL_PHI1_CLK*/      /*FLEXRAY_PE_CLK*/
    IP_MC_CGM_0->MUX_7_CSC &= ~MC_CGM_MUX_7_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_7_CSC |= MC_CGM_MUX_7_CSC_SELCTL(20);    /*Select PERIPH_PLL_PHI2_CLK*/
    IP_MC_CGM_0->MUX_8_CSC &= ~MC_CGM_MUX_8_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_8_CSC |= MC_CGM_MUX_8_CSC_SELCTL(21);    /*Select PERIPH_PLL_PHI3_CLK*/
#ifndef S32G3XX
    /*((IP_MC_CGM_0->MUX_9_CSC & MC_CGM_MUX_9_CSC_SELCTL_MASK) >> MC_CGM_MUX_9_CSC_SELCTL_SHIFT) = 22;*/    /*Select PERIPH_PLL_PHI4_CLK*/      /*GMAC_TS_CLK*/
    IP_MC_CGM_0->MUX_9_CSC &= ~MC_CGM_MUX_9_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_9_CSC |= MC_CGM_MUX_9_CSC_SELCTL(0);    /*Select FIRC_CLK*/                 /*GMAC_TS_CLK*/
    /*((IP_MC_CGM_0->MUX_10_CSC & MC_CGM_MUX_10_CSC_SELCTL_MASK) >> MC_CGM_MUX_10_CSC_SELCTL_SHIFT) = 23;*/    /*Select PERIPH_PLL_PHI5_CLK*/  /*GMAC_0_TX_CLK*/
    IP_MC_CGM_0->MUX_10_CSC &= ~MC_CGM_MUX_10_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_10_CSC |= MC_CGM_MUX_10_CSC_SELCTL(0);    /*Select FIRC_CLK*/                 /*GMAC_0_TX_CLK*/
    IP_MC_CGM_0->MUX_11_CSC &= ~MC_CGM_MUX_11_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_11_CSC |= MC_CGM_MUX_11_CSC_SELCTL(0);    /*Select FIRC_CLK*/                 /*GMAC_0_RX_CLK*/
    IP_MC_CGM_0->MUX_12_CSC &= ~MC_CGM_MUX_12_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_12_CSC |= MC_CGM_MUX_12_CSC_SELCTL(26);    /*Select PERIPH_DFS1_CLK*/          /*QSPI_2X_CLK*/
    IP_MC_CGM_0->MUX_14_CSC &= ~MC_CGM_MUX_14_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_14_CSC |= MC_CGM_MUX_14_CSC_SELCTL(28);    /*Select PERIPH_DFS3_CLK*/          /*SDHC_CLK*/
    IP_MC_CGM_0->MUX_15_CSC &= ~MC_CGM_MUX_15_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_15_CSC |= MC_CGM_MUX_15_CSC_SELCTL(0);    /*Select FIRC_CLK*/                 /*GMAC_0_REF_DIV_CLK*/
    IP_MC_CGM_0->MUX_16_CSC &= ~MC_CGM_MUX_16_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_16_CSC |= MC_CGM_MUX_16_CSC_SELCTL(25);    /*Select PERIPH_PLL_PHI7_CLK*/      /*SPI_CLK*/
#endif
#endif 
   
    IP_MC_CGM_0->MUX_0_CSC &= ~MC_CGM_MUX_0_CSC_CLK_SW_MASK;
    IP_MC_CGM_0->MUX_0_CSC |= MC_CGM_MUX_0_CSC_CLK_SW( 1);    /* Trigger the clock switch */   
    IP_MC_CGM_0->MUX_3_CSC &= ~MC_CGM_MUX_3_CSC_CLK_SW_MASK;
    IP_MC_CGM_0->MUX_3_CSC |= MC_CGM_MUX_3_CSC_CLK_SW( 1);            
    IP_MC_CGM_0->MUX_4_CSC &= ~MC_CGM_MUX_4_CSC_CLK_SW_MASK;
    IP_MC_CGM_0->MUX_4_CSC |= MC_CGM_MUX_4_CSC_CLK_SW( 1);            
    IP_MC_CGM_0->MUX_5_CSC &= ~MC_CGM_MUX_5_CSC_CLK_SW_MASK;
    IP_MC_CGM_0->MUX_5_CSC |= MC_CGM_MUX_5_CSC_CLK_SW( 1);            
    IP_MC_CGM_0->MUX_6_CSC &= ~MC_CGM_MUX_6_CSC_CLK_SW_MASK;
    IP_MC_CGM_0->MUX_6_CSC |= MC_CGM_MUX_6_CSC_CLK_SW( 1);            
    IP_MC_CGM_0->MUX_7_CSC &= ~MC_CGM_MUX_7_CSC_CLK_SW_MASK;
    IP_MC_CGM_0->MUX_7_CSC |= MC_CGM_MUX_7_CSC_CLK_SW( 1);            
    IP_MC_CGM_0->MUX_8_CSC &= ~MC_CGM_MUX_8_CSC_CLK_SW_MASK;
    IP_MC_CGM_0->MUX_8_CSC |= MC_CGM_MUX_8_CSC_CLK_SW( 1);      
#ifndef S32G3XX    
    IP_MC_CGM_0->MUX_9_CSC &= ~MC_CGM_MUX_9_CSC_CLK_SW_MASK;
    IP_MC_CGM_0->MUX_9_CSC |= MC_CGM_MUX_9_CSC_CLK_SW( 1);            
    IP_MC_CGM_0->MUX_10_CSC &= ~MC_CGM_MUX_10_CSC_CLK_SW_MASK;
    IP_MC_CGM_0->MUX_10_CSC |= MC_CGM_MUX_10_CSC_CLK_SW(1);           
    IP_MC_CGM_0->MUX_11_CSC &= ~MC_CGM_MUX_11_CSC_CLK_SW_MASK;
    IP_MC_CGM_0->MUX_11_CSC |= MC_CGM_MUX_11_CSC_CLK_SW(1);           
    IP_MC_CGM_0->MUX_12_CSC &= ~MC_CGM_MUX_12_CSC_CLK_SW_MASK;
    IP_MC_CGM_0->MUX_12_CSC |= MC_CGM_MUX_12_CSC_CLK_SW(1);           
    IP_MC_CGM_0->MUX_14_CSC &= ~MC_CGM_MUX_14_CSC_CLK_SW_MASK;
    IP_MC_CGM_0->MUX_14_CSC |= MC_CGM_MUX_14_CSC_CLK_SW(1);           
    IP_MC_CGM_0->MUX_15_CSC &= ~MC_CGM_MUX_15_CSC_CLK_SW_MASK;
    IP_MC_CGM_0->MUX_15_CSC |= MC_CGM_MUX_15_CSC_CLK_SW(1);           
    IP_MC_CGM_0->MUX_16_CSC &= ~MC_CGM_MUX_16_CSC_CLK_SW_MASK;
    IP_MC_CGM_0->MUX_16_CSC |= MC_CGM_MUX_16_CSC_CLK_SW(1);           
#endif  
    while(((IP_MC_CGM_0->MUX_0_CSS & MC_CGM_MUX_0_CSS_CLK_SW_MASK) >> MC_CGM_MUX_0_CSS_CLK_SW_SHIFT)  != 1) {}      /* Wait for acknowledge to be cleared*/
    while(((IP_MC_CGM_0->MUX_3_CSS & MC_CGM_MUX_3_CSS_CLK_SW_MASK) >> MC_CGM_MUX_3_CSS_CLK_SW_SHIFT)  != 1) {}
    while(((IP_MC_CGM_0->MUX_4_CSS & MC_CGM_MUX_4_CSS_CLK_SW_MASK) >> MC_CGM_MUX_4_CSS_CLK_SW_SHIFT)  != 1) {}      
    while(((IP_MC_CGM_0->MUX_5_CSS & MC_CGM_MUX_5_CSS_CLK_SW_MASK) >> MC_CGM_MUX_5_CSS_CLK_SW_SHIFT)  != 1) {}      
    while(((IP_MC_CGM_0->MUX_6_CSS & MC_CGM_MUX_6_CSS_CLK_SW_MASK) >> MC_CGM_MUX_6_CSS_CLK_SW_SHIFT)  != 1) {}      
    while(((IP_MC_CGM_0->MUX_7_CSS & MC_CGM_MUX_7_CSS_CLK_SW_MASK) >> MC_CGM_MUX_7_CSS_CLK_SW_SHIFT)  != 1) {}      
    while(((IP_MC_CGM_0->MUX_8_CSS & MC_CGM_MUX_8_CSS_CLK_SW_MASK) >> MC_CGM_MUX_8_CSS_CLK_SW_SHIFT)  != 1) {}    
#ifndef S32G3XX        
    while(((IP_MC_CGM_0->MUX_9_CSS & MC_CGM_MUX_9_CSS_CLK_SW_MASK) >> MC_CGM_MUX_9_CSS_CLK_SW_SHIFT)  != 1) {}  
    while(((IP_MC_CGM_0->MUX_10_CSS & MC_CGM_MUX_10_CSS_CLK_SW_MASK) >> MC_CGM_MUX_10_CSS_CLK_SW_SHIFT) != 1) {}     
    while(((IP_MC_CGM_0->MUX_11_CSS & MC_CGM_MUX_11_CSS_CLK_SW_MASK) >> MC_CGM_MUX_11_CSS_CLK_SW_SHIFT) != 1) {}     
    while(((IP_MC_CGM_0->MUX_12_CSS & MC_CGM_MUX_12_CSS_CLK_SW_MASK) >> MC_CGM_MUX_12_CSS_CLK_SW_SHIFT) != 1) {}     
    while(((IP_MC_CGM_0->MUX_14_CSS & MC_CGM_MUX_14_CSS_CLK_SW_MASK) >> MC_CGM_MUX_14_CSS_CLK_SW_SHIFT) != 1) {}     
    while(((IP_MC_CGM_0->MUX_15_CSS & MC_CGM_MUX_15_CSS_CLK_SW_MASK) >> MC_CGM_MUX_15_CSS_CLK_SW_SHIFT) != 1) {}     
    while(((IP_MC_CGM_0->MUX_16_CSS & MC_CGM_MUX_16_CSS_CLK_SW_MASK) >> MC_CGM_MUX_16_CSS_CLK_SW_SHIFT) != 1) {}     
#endif   
    while(((IP_MC_CGM_0->MUX_3_CSS & MC_CGM_MUX_3_CSS_SWIP_MASK) >> MC_CGM_MUX_3_CSS_SWIP_SHIFT)  != 0) {}       /* Verify that clock switch completed*/
    while(((IP_MC_CGM_0->MUX_4_CSS & MC_CGM_MUX_4_CSS_SWIP_MASK) >> MC_CGM_MUX_4_CSS_SWIP_SHIFT)  != 0) {}    
    while(((IP_MC_CGM_0->MUX_5_CSS & MC_CGM_MUX_5_CSS_SWIP_MASK) >> MC_CGM_MUX_5_CSS_SWIP_SHIFT)  != 0) {}    
    while(((IP_MC_CGM_0->MUX_6_CSS & MC_CGM_MUX_6_CSS_SWIP_MASK) >> MC_CGM_MUX_6_CSS_SWIP_SHIFT)  != 0) {}    
    while(((IP_MC_CGM_0->MUX_7_CSS & MC_CGM_MUX_7_CSS_SWIP_MASK) >> MC_CGM_MUX_7_CSS_SWIP_SHIFT)  != 0) {}    
    while(((IP_MC_CGM_0->MUX_8_CSS & MC_CGM_MUX_8_CSS_SWIP_MASK) >> MC_CGM_MUX_8_CSS_SWIP_SHIFT)  != 0) {}  
#ifndef S32G3XX    
    while(((IP_MC_CGM_0->MUX_9_CSS & MC_CGM_MUX_9_CSS_SWIP_MASK) >> MC_CGM_MUX_9_CSS_SWIP_SHIFT)  != 0) {}    
    while(((IP_MC_CGM_0->MUX_10_CSS & MC_CGM_MUX_10_CSS_SWIP_MASK) >> MC_CGM_MUX_10_CSS_SWIP_SHIFT) != 0) {}    
    while(((IP_MC_CGM_0->MUX_11_CSS & MC_CGM_MUX_11_CSS_SWIP_MASK) >> MC_CGM_MUX_11_CSS_SWIP_SHIFT) != 0) {}    
    while(((IP_MC_CGM_0->MUX_12_CSS & MC_CGM_MUX_12_CSS_SWIP_MASK) >> MC_CGM_MUX_12_CSS_SWIP_SHIFT) != 0) {}    
    while(((IP_MC_CGM_0->MUX_14_CSS & MC_CGM_MUX_14_CSS_SWIP_MASK) >> MC_CGM_MUX_14_CSS_SWIP_SHIFT) != 0) {}    
    while(((IP_MC_CGM_0->MUX_15_CSS & MC_CGM_MUX_15_CSS_SWIP_MASK) >> MC_CGM_MUX_15_CSS_SWIP_SHIFT) != 0) {}    
    while(((IP_MC_CGM_0->MUX_16_CSS & MC_CGM_MUX_16_CSS_SWIP_MASK) >> MC_CGM_MUX_16_CSS_SWIP_SHIFT) != 0) {}    
#endif
    IP_MC_CGM_0->MUX_0_DC_0 &= ~MC_CGM_MUX_0_DC_0_DIV_MASK;
    IP_MC_CGM_0->MUX_0_DC_0 |= MC_CGM_MUX_0_DC_0_DIV((16-1));    /*CORE_DFS1_CLK[800MHz] -> LBIST_CLK[7:0][<50MHz] = 50MHz */
    IP_MC_CGM_0->MUX_0_DC_1 &= ~MC_CGM_MUX_0_DC_1_DIV_MASK;
    IP_MC_CGM_0->MUX_0_DC_1 |= MC_CGM_MUX_0_DC_1_DIV((10-1));    /*CORE_DFS1_CLK[800MHz] -> DAPB_CLK[?] = 80MHz?*/
    IP_MC_CGM_0->MUX_1_DC_0 &= ~MC_CGM_MUX_1_DC_0_DIV_MASK;
    IP_MC_CGM_0->MUX_1_DC_0 |= MC_CGM_MUX_1_DC_0_DIV((80-1));    /*CORE_DFS1_CLK[800MHz] -> CLKOUT0 = 10MHz*/
    IP_MC_CGM_0->MUX_2_DC_0 &= ~MC_CGM_MUX_2_DC_0_DIV_MASK;
    IP_MC_CGM_0->MUX_2_DC_0 |= MC_CGM_MUX_2_DC_0_DIV((20-1));    /*PERIPH_DFS2_CLK[200MHz] -> CLKOUT1 = 10MHz*/
    IP_MC_CGM_0->MUX_3_DC_0 &= ~MC_CGM_MUX_3_DC_0_DIV_MASK;
    IP_MC_CGM_0->MUX_3_DC_0 |= MC_CGM_MUX_3_DC_0_DIV((1-1));     /*PERIPH_PLL_PHI1_CLK[80MHz] -> PER_CLK[<80MHz] = 80MHz */
    IP_MC_CGM_0->MUX_4_DC_0 &= ~MC_CGM_MUX_4_DC_0_DIV_MASK;
    IP_MC_CGM_0->MUX_4_DC_0 |= MC_CGM_MUX_4_DC_0_DIV((4-1));     /*PERIPH_PLL_PHI1_CLK[80MHz] -> FTM_0_REF_CLK[<20MHz] = 20MHz */
    IP_MC_CGM_0->MUX_5_DC_0 &= ~MC_CGM_MUX_5_DC_0_DIV_MASK;
    IP_MC_CGM_0->MUX_5_DC_0 |= MC_CGM_MUX_5_DC_0_DIV((4-1));     /*PERIPH_PLL_PHI1_CLK[80MHz] -> FTM_1_REF_CLK[<20MHz] = 20MHz */
    IP_MC_CGM_0->MUX_6_DC_0 &= ~MC_CGM_MUX_6_DC_0_DIV_MASK;
    IP_MC_CGM_0->MUX_6_DC_0 |= MC_CGM_MUX_6_DC_0_DIV((2-1));     /*PERIPH_PLL_PHI1_CLK[80MHz] -> FLEXRAY_PE_CLK[<40MHz] = 40MHz */
#ifndef S32G3XX
   IP_MC_CGM_0->MUX_9_DC_0 &= ~MC_CGM_MUX_9_DC_0_DIV_MASK;
    IP_MC_CGM_0->MUX_9_DC_0 |= MC_CGM_MUX_9_DC_0_DIV((1-1));     /*PERIPH_PLL_PHI4_CLK[40MHz] -> GMAC_TS_CLK[5-200MHz] = 40MHz */
    IP_MC_CGM_0->MUX_10_DC_0 &= ~MC_CGM_MUX_10_DC_0_DIV_MASK;
    IP_MC_CGM_0->MUX_10_DC_0 |= MC_CGM_MUX_10_DC_0_DIV((1-1));    /*PERIPH_PLL_PHI5_CLK[125MHz] -> GMAC_0_TX_CLK[2.5-125MHz] = 125MHz */
    IP_MC_CGM_0->MUX_12_DC_0 &= ~MC_CGM_MUX_12_DC_0_DIV_MASK;
    IP_MC_CGM_0->MUX_12_DC_0 |= MC_CGM_MUX_12_DC_0_DIV((4-1));    /*PERIPH_DFS1_CLK[800MHz] -> QSPI_2X_CLK[200,166,133,100,80,66MHz] = 200MHz, QSPI_1X_CLK = 100MHz */
    IP_MC_CGM_0->MUX_14_DC_0 &= ~MC_CGM_MUX_14_DC_0_DIV_MASK;
    IP_MC_CGM_0->MUX_14_DC_0 |= MC_CGM_MUX_14_DC_0_DIV((1-1));    /*PERIPH_DFS3_CLK[400MHz] -> SDHC_CLK[400,200,208,100,52MHz] = 400MHz */
    IP_MC_CGM_0->MUX_15_DC_0 &= ~MC_CGM_MUX_15_DC_0_DIV_MASK;
    IP_MC_CGM_0->MUX_15_DC_0 |= MC_CGM_MUX_15_DC_0_DIV((1-1));    /*GMAC_0_REF_DIV_CLK -> MUX11*/
                                           /* IP_MC_CGM_0.MUX_16  PERIPH_PLL_PHI7_CLK[40MHz] -> SPI_CLK[10-100MHz] = 40MHz*/
#endif  
    while(((IP_MC_CGM_0->MUX_0_DIV_UPD_STAT & MC_CGM_MUX_0_DIV_UPD_STAT_DIV_STAT_MASK) >> MC_CGM_MUX_0_DIV_UPD_STAT_DIV_STAT_SHIFT)  != 0) {}  /* Wait for acknowledge to be cleared*/
    /*while(((IP_MC_CGM_0->MUX_1_DIV_UPD_STAT & MC_CGM_DIV_UPD_STAT_DIV_STAT_MASK) >> MC_CGM_DIV_UPD_STAT_DIV_STAT_SHIFT)  != 0) {}  TODO: This clock source does not lock the mux, to check why.*/
#if defined(S32G2XX)
    while(((IP_MC_CGM_0->MUX_2_DIV_UPD_STAT & MC_CGM_MUX_2_DIV_UPD_STAT_DIV_STAT_MASK) >> MC_CGM_MUX_2_DIV_UPD_STAT_DIV_STAT_SHIFT)  != 0) {}  
#endif
    while(((IP_MC_CGM_0->MUX_3_DIV_UPD_STAT & MC_CGM_MUX_3_DIV_UPD_STAT_DIV_STAT_MASK) >> MC_CGM_MUX_3_DIV_UPD_STAT_DIV_STAT_SHIFT)  != 0) {}  
    while(((IP_MC_CGM_0->MUX_4_DIV_UPD_STAT & MC_CGM_MUX_4_DIV_UPD_STAT_DIV_STAT_MASK) >> MC_CGM_MUX_4_DIV_UPD_STAT_DIV_STAT_SHIFT)  != 0) {}  
    while(((IP_MC_CGM_0->MUX_5_DIV_UPD_STAT & MC_CGM_MUX_5_DIV_UPD_STAT_DIV_STAT_MASK) >> MC_CGM_MUX_5_DIV_UPD_STAT_DIV_STAT_SHIFT)  != 0) {}  
    while(((IP_MC_CGM_0->MUX_6_DIV_UPD_STAT & MC_CGM_MUX_6_DIV_UPD_STAT_DIV_STAT_MASK) >> MC_CGM_MUX_6_DIV_UPD_STAT_DIV_STAT_SHIFT)  != 0) {}  
#ifndef S32G3XX
    while(((IP_MC_CGM_0->MUX_9_DIV_UPD_STAT & MC_CGM_MUX_9_DIV_UPD_STAT_DIV_STAT_MASK) >> MC_CGM_MUX_9_DIV_UPD_STAT_DIV_STAT_SHIFT)  != 0) {}  
    while(((IP_MC_CGM_0->MUX_10_DIV_UPD_STAT & MC_CGM_MUX_10_DIV_UPD_STAT_DIV_STAT_MASK) >> MC_CGM_MUX_10_DIV_UPD_STAT_DIV_STAT_SHIFT) != 0) {}  
    while(((IP_MC_CGM_0->MUX_12_DIV_UPD_STAT & MC_CGM_MUX_12_DIV_UPD_STAT_DIV_STAT_MASK) >> MC_CGM_MUX_12_DIV_UPD_STAT_DIV_STAT_SHIFT) != 0) {}  
    while(((IP_MC_CGM_0->MUX_14_DIV_UPD_STAT & MC_CGM_MUX_14_DIV_UPD_STAT_DIV_STAT_MASK) >> MC_CGM_MUX_14_DIV_UPD_STAT_DIV_STAT_SHIFT) != 0) {}  
    while(((IP_MC_CGM_0->MUX_15_DIV_UPD_STAT & MC_CGM_MUX_15_DIV_UPD_STAT_DIV_STAT_MASK) >> MC_CGM_MUX_15_DIV_UPD_STAT_DIV_STAT_SHIFT) != 0) {}  
#endif  
    /* Enable all mux dividers */
    IP_MC_CGM_0->MUX_0_DC_0 &= ~MC_CGM_MUX_0_DC_0_DE_MASK;
    IP_MC_CGM_0->MUX_0_DC_0 |= MC_CGM_MUX_0_DC_0_DE(1);     /*LBIST_CLK*/
    IP_MC_CGM_0->MUX_0_DC_1 &= ~MC_CGM_MUX_0_DC_1_DE_MASK;
    IP_MC_CGM_0->MUX_0_DC_1 |= MC_CGM_MUX_0_DC_1_DE(1);     /*DAPB_CLK*/
    IP_MC_CGM_0->MUX_1_DC_0 &= ~MC_CGM_MUX_1_DC_0_DE_MASK;
    IP_MC_CGM_0->MUX_1_DC_0 |= MC_CGM_MUX_1_DC_0_DE(1);     /*CLKOUT0*/
    IP_MC_CGM_0->MUX_2_DC_0 &= ~MC_CGM_MUX_2_DC_0_DE_MASK;
    IP_MC_CGM_0->MUX_2_DC_0 |= MC_CGM_MUX_2_DC_0_DE(1);     /*CLKOUT1*/
    IP_MC_CGM_0->MUX_3_DC_0 &= ~MC_CGM_MUX_3_DC_0_DE_MASK;
    IP_MC_CGM_0->MUX_3_DC_0 |= MC_CGM_MUX_3_DC_0_DE(1);     /*PER_CLK*/
    IP_MC_CGM_0->MUX_4_DC_0 &= ~MC_CGM_MUX_4_DC_0_DE_MASK;
    IP_MC_CGM_0->MUX_4_DC_0 |= MC_CGM_MUX_4_DC_0_DE(1);     /*FTM_0_REF_CLK*/
    IP_MC_CGM_0->MUX_5_DC_0 &= ~MC_CGM_MUX_5_DC_0_DE_MASK;
    IP_MC_CGM_0->MUX_5_DC_0 |= MC_CGM_MUX_5_DC_0_DE(1);     /*FTM_1_REF_CLK*/
    IP_MC_CGM_0->MUX_6_DC_0 &= ~MC_CGM_MUX_6_DC_0_DE_MASK;
    IP_MC_CGM_0->MUX_6_DC_0 |= MC_CGM_MUX_6_DC_0_DE(1);     /*FLEXRAY_PE_CLK*/
#ifndef S32G3XX
    IP_MC_CGM_0->MUX_9_DC_0 &= ~MC_CGM_MUX_9_DC_0_DE_MASK;
    IP_MC_CGM_0->MUX_9_DC_0 |= MC_CGM_MUX_9_DC_0_DE(1);     /*GMAC_TS_CLK*/
    IP_MC_CGM_0->MUX_10_DC_0 &= ~MC_CGM_MUX_10_DC_0_DE_MASK;
    IP_MC_CGM_0->MUX_10_DC_0 |= MC_CGM_MUX_10_DC_0_DE(1);    /*GMAC_0_TX_CLK*/
    IP_MC_CGM_0->MUX_12_DC_0 &= ~MC_CGM_MUX_12_DC_0_DE_MASK;
    IP_MC_CGM_0->MUX_12_DC_0 |= MC_CGM_MUX_12_DC_0_DE(1);    /*QSPI_2X_CLK*/
    IP_MC_CGM_0->MUX_14_DC_0 &= ~MC_CGM_MUX_14_DC_0_DE_MASK;
    IP_MC_CGM_0->MUX_14_DC_0 |= MC_CGM_MUX_14_DC_0_DE(1);    /*SDHC_CLK*/
    IP_MC_CGM_0->MUX_15_DC_0 &= ~MC_CGM_MUX_15_DC_0_DE_MASK;
    IP_MC_CGM_0->MUX_15_DC_0 |= MC_CGM_MUX_15_DC_0_DE(1);    /*GMAC_0_REF_DIV_CLK*/
#endif
    return 0; /*Success*/
}

static int Switch_Core_FIRC(void)
{
    uint32 timeout = 0xFFFF;
    volatile int result = 0;
    /* Verify that we don't have switching in progress*/
    while(((IP_MC_CGM_0->MUX_0_CSS & MC_CGM_MUX_0_CSS_SWIP_MASK) >> MC_CGM_MUX_0_CSS_SWIP_SHIFT) != 0) {}
    IP_MC_CGM_0->MUX_0_CSC &= ~MC_CGM_MUX_0_CSC_SELCTL_MASK;
    IP_MC_CGM_0->MUX_0_CSC |= MC_CGM_MUX_0_CSC_SELCTL(0);    /*Select FIRC_CLK*/
    IP_MC_CGM_0->MUX_0_CSC &= ~MC_CGM_MUX_0_CSC_CLK_SW_MASK;
    IP_MC_CGM_0->MUX_0_CSC |= MC_CGM_MUX_0_CSC_CLK_SW(1);
    /* Wait for acknowledge to be cleared*/
    while(((IP_MC_CGM_0->MUX_0_CSS & MC_CGM_MUX_0_CSS_CLK_SW_MASK) >> MC_CGM_MUX_0_CSS_CLK_SW_SHIFT) != 1) {}
    /* Verify that clock switch completed*/
    while((((IP_MC_CGM_0->MUX_0_CSS & MC_CGM_MUX_0_CSS_SWIP_MASK) >> MC_CGM_MUX_0_CSS_SWIP_SHIFT) != 0) && (timeout--)) {}
    if(timeout == 0)
    {
        result = 1; /*MC_CGM_CLK_SWITCH_TIMEOUT*/
    }
    else
    {
        
    }
    return result;
}

/*================================================================================================*/
/**
* @brief sys_init
* @details function used to initiatialize clocks, system clock is system Pll 120 MHz
* @return E_NOT_OK/E_OK
*/
/*================================================================================================*/
Std_ReturnType sys_init(void)
{
    volatile uint32 status = 0UL;    
    
    status += Switch_Core_FIRC();
    
    status += Init_FXOSC();
    
    status += Init_Core_PLL();
    status += Init_Peripheral_PLL();
    
    status += Init_Core_DFS();
    status += Init_Peripheral_DFS();
    
    status += Init_MC_CGM(); 

    return E_OK;      
}

/*================================================================================================*/
/**
* @brief sys_halt
* @details function used to enter halt mode
*/
/*================================================================================================*/
void sys_halt(void)
{
 
    EXECUTE_WAIT();
}

/*================================================================================================*/
/**
* @brief sys_stop
* @details function used to enter stop mode
*/
/*================================================================================================*/
void sys_stop(void)
{
    EXECUTE_WAIT();
}

uint8 EUnit_GetCoreID(void)
{
    return OsIf_GetCoreID();
}


#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif

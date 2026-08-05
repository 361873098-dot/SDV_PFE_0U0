/**
*   @file    Llce_Firmware_Load.c
*   @version M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
*
*   @brief   AUTOSAR M4_SRC_MODULE_NAME - Function used to load the Llce firmware from host memory to LLCE internal memory
*   @details Function used to load the Llce firmware from host memory to LLCE internal memory
*            This file contains sample code only. It is not part of the production code deliverables.
*   @addtogroup TESTS
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
*   (c) Copyright M4_SRC_YEAR_ID M4_SRC_COPYRIGHTED_TO
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
ifdef(`M4_SRC_KEEP_REVISION_HISTORY', `dnl - DO NOT modify this M4 line!
Revision History:
                             Modification     Tracking
Author (core ID)              Date D/M/Y       Number     Description of Changes
---------------------------   ----------    ------------  ------------------------------------------
Daniel Spataru (nxf47223)     10/10/2019     AMNG-5743     Add Llce firmware loading API      
---------------------------   ----------    ------------  ------------------------------------------
',)dnl - DO NOT modify this M4 line!
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Llce_Firmware_Load.h"
#include "Llce_InterfaceFwMgr.h"
#include "Llce_RegAccess.h"


/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
typedef struct {
    uint8* const pu8MemLocation;
    const uint32 u32RAMSize;
    const uint8* const pu8CodeData;
    const uint32* u32CodeSize;
} Llce_CoreProgramType;

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#define LLCE_NUM_CORES              4U
#define LLCE_ENABLE_CORE_ADDR       ((uint32)0x43FF8000U)
#define LLCE_DATA_RAM_START_ADDR    0x43800000
#define LLCE_DATA_RAM_LENGTH        0x4FFFF
#define LLCE_FW_STARTUP_DURATION    1000000

/** @brief   STM timer used for LLCE performance measurements. */
#ifdef CAN_43_LLCE_STM_MEASUREMENT_LOAD
    #define LLCE_STM_BASEADDR          ((uint32)0x43C1A000UL)
    #define LLCE_STM_CR                 (LLCE_STM_BASEADDR)
    #define LLCE_STM_CNT                (LLCE_STM_BASEADDR + 4 )
#endif

#ifdef S32G3XX
    #define DTE_RAM_SIZE        0x4000
    #define PPE_RX_RAM_SIZE     0x18000
    #define PPE_TX_RAM_SIZE     0x8000
    #define FRPE_RAM_SIZE       0x40000
#else /* S32G2XX */
    #define DTE_RAM_SIZE        0x2000
    #define PPE_RX_RAM_SIZE     0x8000
    #define PPE_TX_RAM_SIZE     0x8000
    #define FRPE_RAM_SIZE       0x10000
#endif

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
__attribute__((section(".llce_boot_end"))) volatile Llce_Mgr_StatusType Llce_Mgr_Status;

/** @brief   STM timer used for performance measurements. */
#ifdef CAN_43_LLCE_STM_MEASUREMENT_ENABLE
__attribute__((section(".llce_meas_sharedmemory"))) volatile uint32 Stm_Measurement;
#endif

/** @violates @ref Can_Llce_c_REF_9 Size of the binary image for LLCE cores is variable. */
extern const uint8 dte_bin[];
extern const uint32 dte_bin_len;

/** @violates @ref Can_Llce_c_REF_9 Size of the binary image for LLCE cores is variable. */
extern const uint8 ppe_rx_bin[];
extern const uint32 ppe_rx_bin_len;

/** @violates @ref Can_Llce_c_REF_9 Size of the binary image for LLCE cores is variable. */
extern const uint8 ppe_tx_bin[];
extern const uint32 ppe_tx_bin_len;

/** @violates @ref Can_Llce_c_REF_9 Size of the binary image for LLCE cores is variable. */
extern const uint8 frpe_bin[];
extern const uint32 frpe_bin_len;

#ifdef LLCE_USE_HEADLESS
extern const uint8 LLCE_HeadlessConfig_bin[];
#endif

/** @violates @ref Can_Llce_c_REF_6 Global object that contains external variables. */
static const Llce_CoreProgramType Llce_CoreData[LLCE_NUM_CORES] = 
{
    /** @violates @ref Can_Llce_c_REF_3 False positive error */
    /** @violates @ref Can_Llce_c_REF_8 This conversion is used to access LLCE cores RAM in order to load the firmware.*/
    { (uint8*)0x43000000, DTE_RAM_SIZE,  dte_bin,    &dte_bin_len },
    /** @violates @ref Can_Llce_c_REF_3 False positive error */
    /** @violates @ref Can_Llce_c_REF_8 This conversion is used to access LLCE cores RAM in order to load the firmware.*/
    { (uint8*)0x43100000, PPE_RX_RAM_SIZE, ppe_rx_bin, &ppe_rx_bin_len},
    /** @violates @ref Can_Llce_c_REF_3 False positive error */
    /** @violates @ref Can_Llce_c_REF_8 This conversion is used to access LLCE cores RAM in order to load the firmware.*/
    { (uint8*)0x43200000, PPE_TX_RAM_SIZE, ppe_tx_bin, &ppe_tx_bin_len},
    /** @violates @ref Can_Llce_c_REF_3 False positive error */
    /** @violates @ref Can_Llce_c_REF_8 This conversion is used to access LLCE cores RAM in order to load the firmware.*/
    { (uint8*)0x43300000, FRPE_RAM_SIZE, frpe_bin,   &frpe_bin_len }
};
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
* @brief          Service routine used to load the firmware from host memory to LLCE internal memory and enable LLCE cores in order to start running.
* @details        This routine is called by:
*                  - Can_Llce_Init
*
* @param[in]      void
*
* @return
* @retval        E_OK  Timeout was not reached. LLCE internal cores started correctly
* @retval        E_NOT_OK  Timeout was reached. LLCE internal cores not started correctly
*/
Std_ReturnType Llce_Firmware_Load(void)
{   
    uint8 i;
    uint32 crtOffset;
    uint32 byteIndex;
    uint64 *u64MemPointer;
    uint64 *u64MemPointer2;
    const uint64 *u64DataPointer;
    
    Llce_Fw_ReturnType eTxBootStatus   = LLCE_FW_NOTRUN;
    Llce_Fw_ReturnType eRxBootStatus   = LLCE_FW_NOTRUN;
    Llce_Fw_ReturnType eDteBootStatus  = LLCE_FW_NOTRUN;
    Llce_Fw_ReturnType eFrpeBootStatus = LLCE_FW_NOTRUN; 
    /* Returns the result of CAN GetControllerErrorState */
    Std_ReturnType eReturnValue = (uint8)E_NOT_OK;
    uint32 u32Timeout;    

#ifdef CAN_43_LLCE_STM_MEASUREMENT_LOAD       
    Reg_Write32(LLCE_STM_CR,0x00);/* Disable STM counter. */ 
    Reg_Write32(LLCE_STM_CNT,0);/* Clear STM counter. */   
    Reg_Write32(LLCE_STM_CR,0x01);/* Enable STM counter. */ 
    Stm_Measurement = 0;
#endif

    /* Put all cores in reset*/
    /** @violates @ref Can_Llce_c_REF_3 False positive error */
    /** @violates @ref Can_Llce_c_REF_4 The cast is used to access memory mapped registers.*/
    Reg_Write32(LLCE_ENABLE_CORE_ADDR, 0x0);

    for (i = 0U; i < LLCE_NUM_CORES; i++) 
    {
        /* Move code to core's code section*/
        /* Performance optimisation: write 8 bytes at a time */
        u64MemPointer  = (uint64*)Llce_CoreData[i].pu8MemLocation;
        u64DataPointer = (uint64*)Llce_CoreData[i].pu8CodeData;

        /* Offset is in words (32 bit) */
        for (crtOffset = 0U; crtOffset <  (*(Llce_CoreData[i].u32CodeSize)) / 8; crtOffset++)
        {
            u64MemPointer[crtOffset] = u64DataPointer[crtOffset];
        }
        
        /* Write 2 words at a time before copying bytes */
        u64MemPointer[crtOffset] = (uint64)0;

        /* Back to 1 byte mode */
        for (byteIndex = crtOffset * 8U; byteIndex <  (*(Llce_CoreData[i].u32CodeSize)); byteIndex++)
        {
            Llce_CoreData[i].pu8MemLocation[byteIndex] = Llce_CoreData[i].pu8CodeData[byteIndex];
        }

        crtOffset++;

        /* Fill the rest of the core's RAM in order to enable ECC RAM */
        for ( ; crtOffset < (Llce_CoreData[i].u32RAMSize) / 8 ; crtOffset++)
        {
            u64MemPointer[crtOffset] = (uint64)0;
        }
    }

    /* Pointer to the first half of LLCE Shared RAM */
    u64MemPointer  = (uint64*)LLCE_DATA_RAM_START_ADDR;
    /* Pointer to the second half of LLCE Shared RAM */
    u64MemPointer2  = (uint64*)(LLCE_DATA_RAM_START_ADDR + (LLCE_DATA_RAM_LENGTH/2) + 1U);

    /* Write all the Shared Memory in order to enable ECC RAM: 8 bytes at a time */
    for (crtOffset = 0U; crtOffset <  LLCE_DATA_RAM_LENGTH / 16; crtOffset++)
    {
        u64MemPointer[crtOffset] = (uint64)0;
        u64MemPointer2[crtOffset] = (uint64)0;
    }

#ifdef LLCE_USE_HEADLESS
    /* Copy magic value from headless config */
    *((uint32*)LLCE_DATA_RAM_START_ADDR) = *((uint32*)LLCE_HeadlessConfig_bin);
    /* Set headless config address */
    *(((uint32*)LLCE_DATA_RAM_START_ADDR) + 1U) = (uint32)&LLCE_HeadlessConfig_bin;
#endif

#ifdef CAN_43_LLCE_STM_MEASUREMENT_LOAD           
    Stm_Measurement = Reg_Read32(LLCE_STM_CNT);
copy_end_label:
#endif

    /* Clear memory area where Llce notifies about boot ending */
    Llce_Mgr_Status.eTxBootStatus = LLCE_FW_NOTRUN;
    Llce_Mgr_Status.eRxBootStatus = LLCE_FW_NOTRUN;
    Llce_Mgr_Status.eDteBootStatus = LLCE_FW_NOTRUN;
    Llce_Mgr_Status.eFrpeBootStatus = LLCE_FW_NOTRUN;

    u32Timeout = LLCE_FW_STARTUP_DURATION;
    /** @violates @ref Can_Llce_c_REF_3 False positive error */
    /** @violates @ref Can_Llce_c_REF_4 The cast is used to access memory mapped registers.*/
    Reg_Write32(LLCE_ENABLE_CORE_ADDR, 0xF);      /*start all cores */


    /*Wait that the LLCE firmware cores to start running and boot.*/
    while (( (LLCE_FW_SUCCESS != eTxBootStatus) || (LLCE_FW_SUCCESS != eRxBootStatus) || \
            (LLCE_FW_SUCCESS != eDteBootStatus) || (LLCE_FW_SUCCESS != eFrpeBootStatus) ) && (u32Timeout > 0))
    {
        /* Volatile variables should be read separately */
        eTxBootStatus   = Llce_Mgr_Status.eTxBootStatus;
        eRxBootStatus   = Llce_Mgr_Status.eRxBootStatus;
        eDteBootStatus  = Llce_Mgr_Status.eDteBootStatus;
        eFrpeBootStatus = Llce_Mgr_Status.eFrpeBootStatus;
        u32Timeout--;
    }
    
    if (u32Timeout != 0)    
    {
        eReturnValue = E_OK;
    }
    
#ifdef CAN_43_LLCE_STM_MEASUREMENT_LOAD          
    Stm_Measurement = Reg_Read32(LLCE_STM_CNT);
boot_end_label:
#endif    
    
    return  eReturnValue;
}

#ifdef __cplusplus
}
#endif

/** @} */

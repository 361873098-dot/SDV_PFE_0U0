/*===================================================================================================*/
/*
*   @file              SysDal_Rtm_Cfg.c
*   project            AUTOSAR 4.4 MCAL
*   platform           CORTEXM
*
*   @brief             Configuration of SysDal RTM software component.
*   @details           This application performs code flows execution measurement
*
*   Autosar Version    4.4.0
*   Build Version      S32G3XX_PLATFORM INTEGRATION_23_02_0_RTM_ASR_REL_4_4_REV_0000_20230224
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. Copyright 2017-2021 NXP
*   All Rights Reserved.
*/
/*===================================================================================================*/
#ifdef __cplusplus
extern "C"{
#endif

/*===================================================================================================*/
/*                                         INCLUDE FILES                                             
   1) system and project includes
   2) needed interfaces from external units
   3) internal and external interfaces from this unit
*/   
/*===================================================================================================*/
#include "MemDal_Cfg.h"

/*===================================================================================================*/
/*                              SOURCE FILE VERSION INFORMATION                                      */
/*===================================================================================================*/
#define MEMDAL_CFG_VENDOR_ID_C                              43

#define MEMDAL_CFG_AR_RELEASE_MAJOR_VERSION_C               4
#define MEMDAL_CFG_AR_RELEASE_MINOR_VERSION_C               4
#define MEMDAL_CFG_AR_RELEASE_REVISION_VERSION_C            0

#define MEMDAL_CFG_SW_MAJOR_VERSION_C                       23
#define MEMDAL_CFG_SW_MINOR_VERSION_C                       02
#define MEMDAL_CFG_SW_PATCH_VERSION_C                       0

/*===================================================================================================*/
/*                                      FILE VERSION CHECKS                                          */
/*===================================================================================================*/

/* Check if MemDal configuration files are of the same vendor */
#if (MEMDAL_CFG_VENDOR_ID_C != MEMDAL_CFG_VENDOR_ID)
    #error "MemDal_Cfg.c and MemDal_Cfg.h have different vendor ids"
#endif

/* Check if MemDal configuration files are of the same Autosar version */
#if ((MEMDAL_CFG_AR_RELEASE_MAJOR_VERSION_C != MEMDAL_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (MEMDAL_CFG_AR_RELEASE_MINOR_VERSION_C != MEMDAL_CFG_AR_RELEASE_MINOR_VERSION) || \
     (MEMDAL_CFG_AR_RELEASE_REVISION_VERSION_C != MEMDAL_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of MemDal_Cfg.c and MemDal_Cfg.h are different"
#endif

/* Check if MemDal configuration files are of the same software version */
#if ((MEMDAL_CFG_SW_MAJOR_VERSION_C != MEMDAL_CFG_SW_MAJOR_VERSION) || \
     (MEMDAL_CFG_SW_MINOR_VERSION_C != MEMDAL_CFG_SW_MINOR_VERSION) || \
     (MEMDAL_CFG_SW_PATCH_VERSION_C != MEMDAL_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of MemDal_Cfg.c and MemDal_Cfg.h are different"
#endif

/*===================================================================================================*/
/*                               LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)                          */
/*===================================================================================================*/

/*===================================================================================================*/
/*                                       DEFINES AND MACROS                                          */
/*===================================================================================================*/

/*===================================================================================================*/
/*                                             LOCAL CONSTANTS                                       */
/*===================================================================================================*/

/*===================================================================================================*/
/*                                             LOCAL VARIABLES                                       */
/*===================================================================================================*/

/*===================================================================================================*/
/*                                            GLOBAL CONSTANTS                                       */   
/*===================================================================================================*/

/*===================================================================================================*/
/*                                            GLOBAL VARIABLES                                       */ 
/*===================================================================================================*/

/**
* @brief MemDal SDHC files
*/
static VAR(MemDal_Sdhc_FileDescriptorType, AUTOMATIC) MemDal_Sdhc_aFiles[1] =
{
    /* MemDalSdhcBlocks_0 */
    {"file.bin", 0U}
};

/**
* @brief List of MemDal blocks
*/
VAR(MemDal_BlockType, AUTOMATIC) MemDal_aBlocks[MEMDAL_BLOCKS_NUMBER] = 
{
    /* MemDalSdhcBlocks_0 */
    {
        /* BlockId */
        MEMDAL_MEMDALSDHCBLOCKS_0_ID,
        /* u32BlockSize */
        500224U,
        /* u16DrvBlockId */
        0U,
        /* eBlockStatus */
        MEMDAL_BLOCK_STATE_UNINIT,
        /* eMemory */
        MEMDAL_MEMORY_SDCARD,
        /* eWrite */
        MEMDAL_WRITE_ONREQUEST,
        /* u32RamBuffer */
        0U,
        /* bIsUpdated */
        FALSE,
    }
};

/**
* @brief MemDal configuration structure
*/
CONST(MemDal_ConfigType, AUTOMATIC) MemDal_Config =
{
    MEMDAL_BLOCKS_NUMBER_FEE,           /* u16FeeBlocksCount    */
    MEMDAL_BLOCKS_NUMBER_SDHC,          /* u16SdhcBlocksCount   */
    MemDal_Sdhc_aFiles,                 /* pSdhcFiles           */
    NULL_PTR,                           /* pSdhcBlockAddress    */
    MemDal_aBlocks                      /* pBlocks              */
};

#ifdef __cplusplus
}
#endif

/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : SIUL2
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
*   Copyright 2020-2023 NXP Semiconductors
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
*   @file    Port_PBcfg.c
*
*   @implements Port_PBcfg.c_Artifact
*   @addtogroup Port_CFG
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/
#include "Port.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
#define PORT_VENDOR_ID_VS_0_PBCFG_C 43
#define PORT_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG_C 4
#define PORT_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG_C 4
#define PORT_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG_C 0
#define PORT_SW_MAJOR_VERSION_VS_0_PBCFG_C 4
#define PORT_SW_MINOR_VERSION_VS_0_PBCFG_C 0
#define PORT_SW_PATCH_VERSION_VS_0_PBCFG_C 2

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/
/* Check if Port_VS_0_PBcfg.c and Port.h are of the same vendor */
#if (PORT_VENDOR_ID_VS_0_PBCFG_C != PORT_VENDOR_ID)
    #error "Port_VS_0_PBcfg.c and Port.h have different vendor ids"
#endif
/* Check if Port_VS_0_PBcfg.c and Port.h are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG_C    != PORT_AR_RELEASE_MAJOR_VERSION) || \
     (PORT_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG_C    != PORT_AR_RELEASE_MINOR_VERSION) || \
     (PORT_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG_C != PORT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Port_VS_0_PBcfg.c and Port.h are different"
#endif

/* Check if Port_VS_0_PBcfg.c and Port.h are of the same software version */
#if ((PORT_SW_MAJOR_VERSION_VS_0_PBCFG_C != PORT_SW_MAJOR_VERSION) || \
     (PORT_SW_MINOR_VERSION_VS_0_PBCFG_C != PORT_SW_MINOR_VERSION) || \
     (PORT_SW_PATCH_VERSION_VS_0_PBCFG_C != PORT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Port_VS_0_PBcfg.c and Port.h are different"
#endif
/*=================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
=================================================================================================*/

/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/

/*=================================================================================================
*                                      LOCAL CONSTANTS
=================================================================================================*/
#define PORT_START_SEC_CONFIG_DATA_8
#include "Port_MemMap.h"

/**
* @brief Array containing list of partition which used in driver
*/
const uint8 au8Port_PartitionList_VS_0[PORT_MAX_PARTITION] =
{
    1
};

#define PORT_STOP_SEC_CONFIG_DATA_8
#include "Port_MemMap.h"

#define PORT_START_SEC_CONFIG_DATA_32
#include "Port_MemMap.h"
/**
* @brief Array containing list of mapping information for mappable elements
*/
static const uint32 au32Port_PinToPartitionMap_VS_0[PORT_MAX_CONFIGURED_PADS_U16] =
{
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001
};

#define PORT_STOP_SEC_CONFIG_DATA_32
#include "Port_MemMap.h"

#if (PORT_MAX_UNUSED_PADS_U16 != 0U)

#define PORT_START_SEC_CONFIG_DATA_16
#include "Port_MemMap.h"

/**
* @brief Array containing list of MSCRs that are not used and should be configured with values from NotUsedPortPin container
*/
static const Port_Siul2_UnUsedPinType Port_aUnusedPads_VS_0[PORT_MAX_UNUSED_PADS_U16] =
{
    { (uint16)145, PORT_SIUL2_1_U8 },
    { (uint16)146, PORT_SIUL2_1_U8 },
    { (uint16)189, PORT_SIUL2_1_U8 }
};

#define PORT_STOP_SEC_CONFIG_DATA_16
#include "Port_MemMap.h"

#endif /* (PORT_MAX_UNUSED_PADS_U16 != 0) */


#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/**
 * @brief Default Configuration for Pins not initialized
 */
static const Port_Siul2_UnUsedPinConfigType Port_UnusedPinConfig_VS_0 =
{
    /**
    * @note: Configuration of Default pin
    */
    (uint32)0x00080000, (uint8)0
    
};

/**
* @brief Pin default configuration data for configPB
*/
static const Port_Siul2_PinConfigType Port_aUsedPinConfigs_VS_0[PORT_MAX_CONFIGURED_PADS_U16]=
{
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    {(uint16)122, (uint32)0x00200002, (uint8)PORT_SIUL2_1_U8, (uint8)0, PORT_PIN_OUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535},
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    {(uint16)78, (uint32)0x00200002, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535},
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    {(uint16)79, (uint32)0x00280002, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)TRUE, 365},
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    {(uint16)82, (uint32)0x00200002, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_INOUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535},
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    {(uint16)118, (uint32)0x00080000, (uint8)PORT_SIUL2_1_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)TRUE, 369},
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    {(uint16)119, (uint32)0x00080000, (uint8)PORT_SIUL2_1_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)TRUE, 370},
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    {(uint16)120, (uint32)0x00080000, (uint8)PORT_SIUL2_1_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)TRUE, 371},
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    {(uint16)121, (uint32)0x00080000, (uint8)PORT_SIUL2_1_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)TRUE, 372},
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    {(uint16)117, (uint32)0x00080000, (uint8)PORT_SIUL2_1_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)TRUE, 373},
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    {(uint16)116, (uint32)0x00080000, (uint8)PORT_SIUL2_1_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)TRUE, 367},
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    {(uint16)144, (uint32)0x00200002, (uint8)PORT_SIUL2_1_U8, (uint8)0, PORT_PIN_OUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535},
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    {(uint16)113, (uint32)0x00200002, (uint8)PORT_SIUL2_1_U8, (uint8)0, PORT_PIN_OUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535},
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    {(uint16)114, (uint32)0x00200002, (uint8)PORT_SIUL2_1_U8, (uint8)0, PORT_PIN_OUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535},
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    {(uint16)115, (uint32)0x00200002, (uint8)PORT_SIUL2_1_U8, (uint8)0, PORT_PIN_OUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535},
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    {(uint16)13, (uint32)0x00210000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535},
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    {(uint16)34, (uint32)0x00390002, (uint8)PORT_SIUL2_0_U8, (uint8)2, PORT_PIN_INOUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)TRUE, 211},
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    {(uint16)33, (uint32)0x00393001, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_INOUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)TRUE, 212},
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    {(uint16)57, (uint32)0x0009c000, (uint8)PORT_SIUL2_0_U8, (uint8)2, PORT_PIN_IN, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535},
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    {(uint16)167, (uint32)0x00210000, (uint8)PORT_SIUL2_1_U8, (uint8)1, PORT_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535},
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    {(uint16)43, (uint32)0x00093000, (uint8)PORT_SIUL2_0_U8, (uint8)1, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)TRUE, 1},
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    {(uint16)44, (uint32)0x00213001, (uint8)PORT_SIUL2_0_U8, (uint8)1, PORT_PIN_OUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535},
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    {(uint16)171, (uint32)0x00213005, (uint8)PORT_SIUL2_1_U8, (uint8)1, PORT_PIN_OUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535},
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    {(uint16)175, (uint32)0x00211004, (uint8)PORT_SIUL2_1_U8, (uint8)0, PORT_PIN_OUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535},
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    {(uint16)173, (uint32)0x00211003, (uint8)PORT_SIUL2_1_U8, (uint8)1, PORT_PIN_OUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535},
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    {(uint16)174, (uint32)0x00093000, (uint8)PORT_SIUL2_1_U8, (uint8)1, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)TRUE, 495},
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    {(uint16)16, (uint32)0x00393001, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_INOUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)TRUE, 53},
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    {(uint16)17, (uint32)0x00390001, (uint8)PORT_SIUL2_0_U8, (uint8)2, PORT_PIN_INOUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)TRUE, 54}
};


/* SIUL2_0 */
/**
* @brief IMCR configuration set by Port_Init() for SIUL2 instance: SIUL2_0
*/
static const Port_Siul2_ImcrConfigType Port_aSIUL2_0_ImcrInitConfig_VS_0[PORT_SIUL2_0_NUM_IMCRS_U16]=
{
    (uint8)0xff,
    (uint8)0x02,
    (uint8)0xFFU,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0x00,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0x00,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0x02,
    (uint8)0x02,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xff,
    (uint8)0x00,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff
};

/* SIUL2_1 */
/**
* @brief IMCR configuration set by Port_Init() for SIUL2 instance: SIUL2_1
*/
static const Port_Siul2_ImcrConfigType Port_aSIUL2_1_ImcrInitConfig_VS_0[PORT_SIUL2_1_NUM_IMCRS_U16]=
{
        (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0x00,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xFFU,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0x03,
    (uint8)0x03,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0x00,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xFFU,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xFFU,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xFFU,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xFFU,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xFFU,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xFFU,
    (uint8)0xff,
    (uint8)0xFFU,
    (uint8)0xff,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0x03,
    (uint8)0x00,
    (uint8)0x03,
    (uint8)0x00,
    (uint8)0x03,
    (uint8)0x03,
    (uint8)0x03,
    (uint8)0x03,
    (uint8)0x03,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xff,
    (uint8)0x00,
    (uint8)0xff,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0x03
};


#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/*=================================================================================================
*                                      LOCAL VARIABLES
=================================================================================================*/

/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/
#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/**
* @brief This table contains all the Configured Port Pin parameters and the
*        number of Port Pins configured by the tool for the post-build mode
*/
const Port_ConfigType Port_Config =
{
    PORT_MAX_CONFIGURED_PADS_U16,
    PORT_MAX_UNUSED_PADS_U16,
    {
        PORT_SIUL2_0_NUM_IMCRS_U16,
        PORT_SIUL2_1_NUM_IMCRS_U16
    },
#if (PORT_MAX_UNUSED_PADS_U16 != 0U)
    Port_aUnusedPads_VS_0,
#else
    NULL_PTR,
#endif
    &Port_UnusedPinConfig_VS_0,
    Port_aUsedPinConfigs_VS_0,
    {
        Port_aSIUL2_0_ImcrInitConfig_VS_0,
        Port_aSIUL2_1_ImcrInitConfig_VS_0
    },
    au32Port_PinToPartitionMap_VS_0,
    au8Port_PartitionList_VS_0,
    g_pin_mux_InitConfigArr_VS_0
};

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/*=================================================================================================
*                                      GLOBAL VARIABLES
=================================================================================================*/

/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/

/*=================================================================================================
*                                       LOCAL FUNCTIONS
=================================================================================================*/

/*=================================================================================================
*                                       GLOBAL FUNCTIONS
=================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

/* End of File */

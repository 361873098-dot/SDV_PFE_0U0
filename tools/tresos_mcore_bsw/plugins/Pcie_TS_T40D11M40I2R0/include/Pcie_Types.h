/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : SERDES_SS
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

#ifndef PCIE_TYPES_H
#define PCIE_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDES
==================================================================================================*/

#include "Std_Types.h"
#include "Pcie_Ipw_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define PCIE_TYPES_VENDOR_ID                    43
#define PCIE_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define PCIE_TYPES_AR_RELEASE_MINOR_VERSION     4
#define PCIE_TYPES_AR_RELEASE_REVISION_VERSION  0
#define PCIE_TYPES_SW_MAJOR_VERSION             4
#define PCIE_TYPES_SW_MINOR_VERSION             0
#define PCIE_TYPES_SW_PATCH_VERSION             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Std_TYpes header file are of the same vendor */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Pcie_Types.h file and Std_Types.h header file are of the same Autosar version */
    #if ((PCIE_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (PCIE_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Pcie_Types.h and Std_Types.h are different"
    #endif
#endif

#if (PCIE_TYPES_VENDOR_ID != PCIE_IPW_TYPES_VENDOR_ID)
#error "Pcie_Types.h and Pcie_Ipw_Types.h have different vendor ids"
#endif
/* Check if current file and Pcie configuration header file are of the same Autosar version */
#if ((PCIE_TYPES_AR_RELEASE_MAJOR_VERSION    != PCIE_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PCIE_TYPES_AR_RELEASE_MINOR_VERSION    != PCIE_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PCIE_TYPES_AR_RELEASE_REVISION_VERSION != PCIE_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pcie_Types.h and Pcie_Ipw_Types.h are different"
#endif
/* Check if current file and Pcie configuration header file are of the same software version */
#if ((PCIE_TYPES_SW_MAJOR_VERSION != PCIE_IPW_TYPES_SW_MAJOR_VERSION) || \
     (PCIE_TYPES_SW_MINOR_VERSION != PCIE_IPW_TYPES_SW_MINOR_VERSION) || \
     (PCIE_TYPES_SW_PATCH_VERSION != PCIE_IPW_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Pcie_Types.h and Pcie_Ipw_Types.h are different"
#endif



/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/**
 * @brief    PCIe driver status type.
 */
typedef  enum
{
    PCIE_SUCCESS = 0, 
    PCIE_ERROR,
    PCIE_BUSY
}Pcie_StatusType;

/**
 * @brief    Types of IATU regions.
 */
typedef enum
{
    PCIE_IATU_REG_TYPE_MEM        = 0U,     /* Memory window            */
    PCIE_IATU_REG_TYPE_IO         = 2U,     /* I/O window               */
    PCIE_IATU_REG_TYPE_CFG0       = 4U,     /* Config Type 0 window     */
    PCIE_IATU_REG_TYPE_CFG1       = 5U,     /* Config Type 0 window     */
}Pcie_IatuRegType;


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
 * @brief    Structure that contains Pcie Hw configuration.
 * @details  It contains the information specific to one Pcie Hw unit
 *
 */
typedef struct
{
    uint32 ctrl;                     /* Channel control          */
    uint32 size;                     /* Transfer size            */
    uint32 srcLow;                   /* Source address low       */
    uint32 srcHigh;                  /* Source address High      */
    uint32 destLow;                  /* Destination address low  */
    uint32 destHigh;                 /* Destination address High */
}Pcie_DmaLlElementType;

/**
 * @brief    Structure that contains Pcie Hw configuration.
 * @details  It contains the information specific to one Pcie Hw unit
 *
 */
typedef struct
{
    /**< @brief Numeric instance value of Pcie Hw Unit */
    const uint8                               Pcie_HwUnit;

    /**< @brief Numeric identifier of the core to which this hardware instance is allocated */
    const uint32                              CoreId;

    /**< @brief Structure containing the hardware specific configuration for the channel. */
    const Pcie_Ipw_HwChannelConfigType *      HwChannelConfig;

}Pcie_HwUnitConfigType;

/**
 * @brief This type contains initialization data.
 * @details This contains initialization data for the Pcie driver. It shall contain:
 *         - The number of Pcie modules to be configured
 *         - Pcie dependent properties for used HW units
*/
typedef struct
{
    /**< @brief Numeric identifier of the core to which this initialization structure is allocated */
    const uint32                              CoreId;

    /**< @brief Pointer to Pcie hardware unit configuration */
    const Pcie_HwUnitConfigType (*Pcie_HwConfig)[];
} Pcie_ConfigType;

/**
 * @brief Structure that contains description of an outbound region.
 * @details This contains initialization all parameters used to initialize an outbound region
*/
typedef struct
{
    /**< @brief IATU outbound region number to configure */
    uint32 regNo;
    /**< @brief Base address of address region to translate */        
    uint64 srcAddr;
    /**< @brief Limit of address region to translate. Replaces lower part of srcAddr to determine the last valid address */      
    uint32 srcAddrLim;
    /**< @brief Base address of translated address region */
    uint64 dstAddr;
    /**< @brief Type of IATU region.*/
    Pcie_IatuRegType type;
} Pcie_OutRegDescriptorType;

/**
 * @brief DMA read transfer descriptor
 * @details Structure that contains the parameters of a DMA read transfer
*/
typedef struct
{
    /**< @brief Source adress of the data to be transfered. This is a remote address (on the RC) */
    uint64 srcAddr;
    /**< @brief Destination adress where to transfer the data. This is a local address */
    uint32 dstAddr;
    /**< @brief Amount of data to transfer, in bytes */
    uint32 size;
    /**< @brief ID of the trasfer, to allow application to identify a completed transfer */
    uint16 transferId;
    /**< @brief Generate interrupt on completion of this transfer and call application callback configured for this channel */
    boolean interrupt;
} Pcie_DmaReadDescriptorType;

/**
 * @brief DMA write transfer descriptor
 * @details Structure that contains the parameters of a DMA write transfer
*/
typedef struct
{
    /**< @brief Source adress of the data to be transfered. This is a local address */
    uint32 srcAddr;
    /**< @brief Destination adress where to transfer the data. This is a remote address (on the RC) */
    uint64 dstAddr;
    /**< @brief Amount of data to transfer, in bytes */
    uint32 size;
    /**< @brief ID of the trasfer, to allow application to identify a completed transfer */
    uint16 transferId;
    /**< @brief Generate interrupt on completion of this transfer and call application callback configured for this channel */
    boolean interrupt;
} Pcie_DmaWriteDescriptorType;

#ifdef __cplusplus
}
#endif

#endif /* PCIE_TYPES_H */

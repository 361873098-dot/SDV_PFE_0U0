/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,FTM
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

/* Prevention from multiple including the same header */
#ifndef DMA_IP_CFG_DEFINES_H
#define DMA_IP_CFG_DEFINES_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "BasicTypes.h"
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
[!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!]
[!ENDIF!][!//

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DMA_IP_CFG_DEFINES_VENDOR_ID                       43
#define DMA_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define DMA_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION        4
#define DMA_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define DMA_IP_CFG_DEFINES_SW_MAJOR_VERSION                4
#define DMA_IP_CFG_DEFINES_SW_MINOR_VERSION                0
#define DMA_IP_CFG_DEFINES_SW_PATCH_VERSION                2

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and StandardTypes header file are of the same Autosar version */
#if ((DMA_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Dma_Ip_Cfg_Defines.h and StandardTypes.h are different"
#endif
#endif

/*===============================================================================================
                                       DEFINES AND MACROS
===============================================================================================*/
/*-----------------------------------------------/
/  DMA IP USER MODE SUPPORT                      /
/-----------------------------------------------*/
[!IF "node:value(./MclGeneral/MclEnableUserModeSupport)"!][!//
#define DMA_IP_USER_MODE_SUPPORT_IS_AVAILABLE      STD_ON
#define DMA_IP_REG_PROT_AVAILABLE                  STD_ON
#define DMA_CRC_IP_REG_PROT_AVAILABLE              STD_OFF
[!ELSE!][!//
#define DMA_IP_USER_MODE_SUPPORT_IS_AVAILABLE      STD_OFF
#define DMA_IP_REG_PROT_AVAILABLE                  STD_OFF
[!ENDIF!][!//

#define DMA_IP_MP_REG_PROT_AVAILABLE               STD_ON
#define DMA_IP_TCD_REG_PROT_AVAILABLE              STD_OFF
#define DMA_IP_DMAMUX_REG_PROT_AVAILABLE           STD_ON

/*-----------------------------------------------/
/  DMAMUX IP SUPPORT                             /
/-----------------------------------------------*/
#define DMA_IP_DMAMUX_IS_AVAILABLE                 STD_ON

/*-----------------------------------------------/
/  DMA IP SUPPORT                                /
/-----------------------------------------------*/
[!IF "node:value(./MclGeneral/MclDma/MclEnableDma)"!][!//
#define DMA_IP_IS_AVAILABLE                        STD_ON

[!IF "node:value(./MclGeneral/MclDma/MclEnableCrc)"!][!//
#define DMA_IP_DMACRC_IS_AVAILABLE                 STD_ON
[!ELSE!][!//
#define DMA_IP_DMACRC_IS_AVAILABLE                 STD_OFF
[!ENDIF!][!//

/*-----------------------------------------------/
/  DMA IP VIRTUAL ADDRESS MAPPING SUPPORT        /
/-----------------------------------------------*/
[!IF "node:value(./MclGeneral/MclEnableVirtualAddressMappingSupport)"!][!//
#define DMA_IP_VIRTUAL_ADDRESS_MAPPING_IS_AVAILABLE      STD_ON
[!ELSE!][!//
#define DMA_IP_VIRTUAL_ADDRESS_MAPPING_IS_AVAILABLE      STD_OFF
[!ENDIF!][!//

[!IF "node:value(./MclGeneral/MclEnableMulticoreSupport)='true' and (num:i(ecu:get('Mcl.MultiCore.Support')) = 1)"!][!//
#define DMA_IP_MULTICORE_IS_AVAILABLE              STD_ON
[!ELSE!][!//
#define DMA_IP_MULTICORE_IS_AVAILABLE              STD_OFF
[!ENDIF!][!//

#define DMA_IP_MASTER_ID_REPLICATION_IS_AVAILABLE  STD_ON

#define DMA_IP_BUFFERED_WRITES_IS_AVAILABLE        STD_ON

#define DMA_IP_STORE_DST_ADDR_IS_AVAILABLE         STD_ON

#define DMA_IP_END_OF_PACKET_SIGNAL_IS_AVAILABLE   STD_OFF

#define DMA_IP_PREEMPTION_IS_AVAILABLE             STD_ON

#define DMA_IP_DISABLE_PREEMPT_IS_AVAILABLE        STD_ON

#define DMA_IP_GROUP_PRIORITY_IS_AVAILABLE         STD_ON
[!ELSE!][!//
#define DMA_IP_IS_AVAILABLE                        STD_OFF

#define DMA_IP_DMACRC_IS_AVAILABLE                 STD_OFF

#define DMA_IP_VIRTUAL_ADDRESS_MAPPING_IS_AVAILABLE      STD_OFF

#define DMA_IP_MULTICORE_IS_AVAILABLE              STD_OFF

#define DMA_IP_MASTER_ID_REPLICATION_IS_AVAILABLE  STD_OFF

#define DMA_IP_BUFFERED_WRITES_IS_AVAILABLE        STD_OFF

#define DMA_IP_STORE_DST_ADDR_IS_AVAILABLE         STD_OFF

#define DMA_IP_END_OF_PACKET_SIGNAL_IS_AVAILABLE   STD_OFF

#define DMA_IP_PREEMPTION_IS_AVAILABLE             STD_OFF

#define DMA_IP_DISABLE_PREEMPT_IS_AVAILABLE        STD_OFF

#define DMA_IP_GROUP_PRIORITY_IS_AVAILABLE         STD_OFF
[!ENDIF!][!//

/*-----------------------------------------------/
/  DMA IP DEV ERROR DETECT SUPPORT               /
/-----------------------------------------------*/
#define DMA_IP_DEV_ERROR_DETECT                    STD_OFF

/*-----------------------------------------------/
/  DMAMUX NOT ALIGNED                            /
/-----------------------------------------------*/
#define DMAMUX_IP_NOT_ALIGNED                            STD_OFF

[!IF "node:value(./MclGeneral/MclDma/MclEnableDma)"!][!//
/*-----------------------------------------------/
/  DMA HARDWARE VERSION                          /
/-----------------------------------------------*/
#define DMA_IP_HWV2_IS_AVAILABLE                  STD_OFF
#define DMA_IP_HARDWARE_VERSION_2                 ((uint8)2U)
#define DMA_IP_HWV3_IS_AVAILABLE                  STD_ON
#define DMA_IP_HARDWARE_VERSION_3                 ((uint8)3U)

/*-----------------------------------------------/
/  DMA TOTAL NUMBER OF LOGIC INSTANCE            /
/-----------------------------------------------*/
[!CODE!]
[!VAR "TotalNumberOfLogicInstance"="num:i(count(as:modconf('Mcl')[1]/MclConfig/dmaLogicInstance_ConfigType/*))"!][!//
#define DMA_IP_DMA_TOTAL_NOF_LOGIC_INST             ((uint32)[!"num:i($TotalNumberOfLogicInstance)"!]U)
[!ENDCODE!]

/*-----------------------------------------------/
/  DMA TOTAL NUMBER OF LOGIC CHANNEL             /
/-----------------------------------------------*/
[!CODE!]
[!VAR "TotalNumberOfLogicChannel"="num:i(count(as:modconf('Mcl')[1]/MclConfig/dmaLogicChannel_Type/*))"!][!//
#define DMA_IP_DMA_TOTAL_NOF_LOGIC_CHANNEL          ((uint32)[!"num:i($TotalNumberOfLogicChannel)"!]U)
[!ENDCODE!]

/*-----------------------------------------------/
/  DMA HARDWARE INSTANCES                        /
/-----------------------------------------------*/
#define DMA_IP_HW_INST_0                        ((uint8)(0U))
#define DMA_IP_HW_INST_1                        ((uint8)(1U))

/*-----------------------------------------------/
/  DMA HARDWARE CHANNELS                         /
/-----------------------------------------------*/
#define DMA_IP_HW_CH_0                          ((uint8)(0U))
#define DMA_IP_HW_CH_1                          ((uint8)(1U))
#define DMA_IP_HW_CH_2                          ((uint8)(2U))
#define DMA_IP_HW_CH_3                          ((uint8)(3U))
#define DMA_IP_HW_CH_4                          ((uint8)(4U))
#define DMA_IP_HW_CH_5                          ((uint8)(5U))
#define DMA_IP_HW_CH_6                          ((uint8)(6U))
#define DMA_IP_HW_CH_7                          ((uint8)(7U))
#define DMA_IP_HW_CH_8                          ((uint8)(8U))
#define DMA_IP_HW_CH_9                          ((uint8)(9U))
#define DMA_IP_HW_CH_10                         ((uint8)(10U))
#define DMA_IP_HW_CH_11                         ((uint8)(11U))
#define DMA_IP_HW_CH_12                         ((uint8)(12U))
#define DMA_IP_HW_CH_13                         ((uint8)(13U))
#define DMA_IP_HW_CH_14                         ((uint8)(14U))
#define DMA_IP_HW_CH_15                         ((uint8)(15U))
#define DMA_IP_HW_CH_16                         ((uint8)(16U))
#define DMA_IP_HW_CH_17                         ((uint8)(17U))
#define DMA_IP_HW_CH_18                         ((uint8)(18U))
#define DMA_IP_HW_CH_19                         ((uint8)(19U))
#define DMA_IP_HW_CH_20                         ((uint8)(20U))
#define DMA_IP_HW_CH_21                         ((uint8)(21U))
#define DMA_IP_HW_CH_22                         ((uint8)(22U))
#define DMA_IP_HW_CH_23                         ((uint8)(23U))
#define DMA_IP_HW_CH_24                         ((uint8)(24U))
#define DMA_IP_HW_CH_25                         ((uint8)(25U))
#define DMA_IP_HW_CH_26                         ((uint8)(26U))
#define DMA_IP_HW_CH_27                         ((uint8)(27U))
#define DMA_IP_HW_CH_28                         ((uint8)(28U))
#define DMA_IP_HW_CH_29                         ((uint8)(29U))
#define DMA_IP_HW_CH_30                         ((uint8)(30U))
#define DMA_IP_HW_CH_31                         ((uint8)(31U))

/*-----------------------------------------------/
/  DMA REQUESTS                                  /
/-----------------------------------------------*/
[!INDENT "0"!][!//
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32g')"!][!//
#define DMA_IP_REQ_MUX0_DISABLED                ((uint8)0U)
#define DMA_IP_REQ_MUX0_CANFD0                  ((uint8)1U)
#define DMA_IP_REQ_MUX0_CANFD1                  ((uint8)2U)
#define DMA_IP_REQ_MUX0_LINFLEXD0_TX            ((uint8)3U)
#define DMA_IP_REQ_MUX0_LINFLEXD0_RX            ((uint8)4U)
#define DMA_IP_REQ_MUX0_LINFLEXD1_TX            ((uint8)5U)
#define DMA_IP_REQ_MUX0_LINFLEXD1_RX            ((uint8)6U)
#define DMA_IP_REQ_MUX0_DSPI0_TX                ((uint8)7U)
#define DMA_IP_REQ_MUX0_DSPI0_RX                ((uint8)8U)
#define DMA_IP_REQ_MUX0_DSPI0_CMD               ((uint8)9U)
#define DMA_IP_REQ_MUX0_DSPI1_TX                ((uint8)10U)
#define DMA_IP_REQ_MUX0_DSPI1_RX                ((uint8)11U)
#define DMA_IP_REQ_MUX0_DSPI1_CMD               ((uint8)12U)
#define DMA_IP_REQ_MUX0_DSPI2_TX                ((uint8)13U)
#define DMA_IP_REQ_MUX0_DSPI2_RX                ((uint8)14U)
#define DMA_IP_REQ_MUX0_DSPI2_CMD               ((uint8)15U)
#define DMA_IP_REQ_MUX0_I2C0_RX                 ((uint8)16U)
#define DMA_IP_REQ_MUX0_I2C0_TX                 ((uint8)17U)
#define DMA_IP_REQ_MUX0_I2C1_RX                 ((uint8)18U)
#define DMA_IP_REQ_MUX0_I2C1_TX                 ((uint8)19U)
#define DMA_IP_REQ_MUX0_CTU_FIFO0               ((uint8)20U)
#define DMA_IP_REQ_MUX0_CTU_FIFO1               ((uint8)21U)
#define DMA_IP_REQ_MUX0_CTU_FIFO2               ((uint8)22U)
#define DMA_IP_REQ_MUX0_CTU_FIFO3               ((uint8)23U)
#define DMA_IP_REQ_MUX0_CTU_CMD_REQ             ((uint8)24U)
#define DMA_IP_REQ_MUX0_SUIL0_0                 ((uint8)25U)
#define DMA_IP_REQ_MUX0_SUIL0_1                 ((uint8)26U)
#define DMA_IP_REQ_MUX0_SUIL0_4                 ((uint8)27U)
#define DMA_IP_REQ_MUX0_SUIL0_5                 ((uint8)28U)
#define DMA_IP_REQ_MUX0_SUIL0_8                 ((uint8)29U)
#define DMA_IP_REQ_MUX0_SUIL0_9                 ((uint8)30U)
#define DMA_IP_REQ_MUX0_SARADC0                 ((uint8)32U)
#define DMA_IP_REQ_MUX0_SUIL1_0                 ((uint8)47U)
#define DMA_IP_REQ_MUX0_SUIL1_1                 ((uint8)48U)
#define DMA_IP_REQ_MUX0_SUIL1_4                 ((uint8)49U)
#define DMA_IP_REQ_MUX0_SUIL1_5                 ((uint8)50U)
#define DMA_IP_REQ_MUX0_FTM0_CH0                ((uint8)52U)
#define DMA_IP_REQ_MUX0_FTM0_CH1                ((uint8)53U)
#define DMA_IP_REQ_MUX0_FTM0_CH2                ((uint8)54U)
#define DMA_IP_REQ_MUX0_FTM0_CH3                ((uint8)55U)
#define DMA_IP_REQ_MUX0_FTM0_CH4                ((uint8)56U)
#define DMA_IP_REQ_MUX0_FTM0_CH5                ((uint8)57U)
#define DMA_IP_REQ_MUX0_ALWAYS_ON0              ((uint8)60U)
#define DMA_IP_REQ_MUX0_ALWAYS_ON1              ((uint8)61U)
#define DMA_IP_REQ_MUX0_ALWAYS_ON2              ((uint8)62U)
#define DMA_IP_REQ_MUX0_ALWAYS_ON3              ((uint8)63U)

#define DMA_IP_REQ_MUX1_DISABLED                ((uint8)64U)
#define DMA_IP_REQ_MUX1_CANFD2                  ((uint8)65U)
#define DMA_IP_REQ_MUX1_CANFD3                  ((uint8)66U)
#define DMA_IP_REQ_MUX1_LINFLEXD2_TX            ((uint8)67U)
#define DMA_IP_REQ_MUX1_LINFLEXD2_RX            ((uint8)68U)
#define DMA_IP_REQ_MUX1_QUADSPI_TX              ((uint8)69U)
#define DMA_IP_REQ_MUX1_QUADSPI_RX              ((uint8)70U)
#define DMA_IP_REQ_MUX1_DSPI3_TX                ((uint8)71U)
#define DMA_IP_REQ_MUX1_DSPI3_RX                ((uint8)72U)
#define DMA_IP_REQ_MUX1_DSPI3_CMD               ((uint8)73U)
#define DMA_IP_REQ_MUX1_DSPI4_TX                ((uint8)74U)
#define DMA_IP_REQ_MUX1_DSPI4_RX                ((uint8)75U)
#define DMA_IP_REQ_MUX1_DSPI4_CMD               ((uint8)76U)
#define DMA_IP_REQ_MUX1_DSPI5_TX                ((uint8)77U)
#define DMA_IP_REQ_MUX1_DSPI5_RX                ((uint8)78U)
#define DMA_IP_REQ_MUX1_DSPI5_CMD               ((uint8)79U)
#define DMA_IP_REQ_MUX1_I2C2_RX                 ((uint8)80U)
#define DMA_IP_REQ_MUX1_I2C2_TX                 ((uint8)81U)
#define DMA_IP_REQ_MUX1_I2C3_RX                 ((uint8)82U)
#define DMA_IP_REQ_MUX1_I2C3_TX                 ((uint8)83U)
#define DMA_IP_REQ_MUX1_I2C4_RX                 ((uint8)84U)
#define DMA_IP_REQ_MUX1_I2C4_TX                 ((uint8)85U)
#define DMA_IP_REQ_MUX1_ETHERNET0_CH0           ((uint8)86U)
#define DMA_IP_REQ_MUX1_ETHERNET0_CH1           ((uint8)87U)
#define DMA_IP_REQ_MUX1_ETHERNET0_CH2           ((uint8)88U)
#define DMA_IP_REQ_MUX1_SIUL0_2                 ((uint8)89U)
#define DMA_IP_REQ_MUX1_SIUL0_3                 ((uint8)90U)
#define DMA_IP_REQ_MUX1_SIUL0_6                 ((uint8)91U)
#define DMA_IP_REQ_MUX1_SIUL0_7                 ((uint8)92U)
#define DMA_IP_REQ_MUX1_SIUL0_10                ((uint8)93U)
#define DMA_IP_REQ_MUX1_SIUL0_11                ((uint8)94U)
#define DMA_IP_REQ_MUX1_SARADC1                 ((uint8)96U)
#define DMA_IP_REQ_MUX1_ETHERNET0_CH3           ((uint8)97U)
#define DMA_IP_REQ_MUX1_PFE_MAC0                ((uint8)101U)
#define DMA_IP_REQ_MUX1_PFE_MAC1                ((uint8)102U)
#define DMA_IP_REQ_MUX1_PFE_MAC2                ((uint8)103U)
#define DMA_IP_REQ_MUX1_SIUL1_2                 ((uint8)111U)
#define DMA_IP_REQ_MUX1_SIUL1_3                 ((uint8)112U)
#define DMA_IP_REQ_MUX1_SIUL1_6                 ((uint8)113U)
#define DMA_IP_REQ_MUX1_SIUL1_7                 ((uint8)114U)
#define DMA_IP_REQ_MUX1_FTM1_CH0                ((uint8)116U)
#define DMA_IP_REQ_MUX1_FTM1_CH1                ((uint8)117U)
#define DMA_IP_REQ_MUX1_FTM1_CH2                ((uint8)118U)
#define DMA_IP_REQ_MUX1_FTM1_CH3                ((uint8)119U)
#define DMA_IP_REQ_MUX1_FTM1_CH4                ((uint8)120U)
#define DMA_IP_REQ_MUX1_FTM1_CH5                ((uint8)121U)
#define DMA_IP_REQ_MUX1_ALWAYS_ON0              ((uint8)124U)
#define DMA_IP_REQ_MUX1_ALWAYS_ON1              ((uint8)125U)
#define DMA_IP_REQ_MUX1_ALWAYS_ON2              ((uint8)126U)
#define DMA_IP_REQ_MUX1_ALWAYS_ON3              ((uint8)127U)

#define DMA_IP_REQ_MUX2_DISABLED                ((uint8)128U)
#define DMA_IP_REQ_MUX2_CANFD0                  ((uint8)129U)
#define DMA_IP_REQ_MUX2_CANFD1                  ((uint8)130U)
#define DMA_IP_REQ_MUX2_LINFLEXD0_TX            ((uint8)131U)
#define DMA_IP_REQ_MUX2_LINFLEXD0_RX            ((uint8)132U)
#define DMA_IP_REQ_MUX2_LINFLEXD1_TX            ((uint8)133U)
#define DMA_IP_REQ_MUX2_LINFLEXD1_RX            ((uint8)134U)
#define DMA_IP_REQ_MUX2_DSPI0_TX                ((uint8)135U)
#define DMA_IP_REQ_MUX2_DSPI0_RX                ((uint8)136U)
#define DMA_IP_REQ_MUX2_DSPI0_CMD               ((uint8)137U)
#define DMA_IP_REQ_MUX2_DSPI1_TX                ((uint8)138U)
#define DMA_IP_REQ_MUX2_DSPI1_RX                ((uint8)139U)
#define DMA_IP_REQ_MUX2_DSPI1_CMD               ((uint8)140U)
#define DMA_IP_REQ_MUX2_DSPI2_TX                ((uint8)141U)
#define DMA_IP_REQ_MUX2_DSPI2_RX                ((uint8)142U)
#define DMA_IP_REQ_MUX2_DSPI2_CMD               ((uint8)143U)
#define DMA_IP_REQ_MUX2_I2C0_RX                 ((uint8)144U)
#define DMA_IP_REQ_MUX2_I2C0_TX                 ((uint8)145U)
#define DMA_IP_REQ_MUX2_I2C1_RX                 ((uint8)146U)
#define DMA_IP_REQ_MUX2_I2C1_TX                 ((uint8)147U)
#define DMA_IP_REQ_MUX2_CTU_FIFO0               ((uint8)148U)
#define DMA_IP_REQ_MUX2_CTU_FIFO1               ((uint8)149U)
#define DMA_IP_REQ_MUX2_CTU_FIFO2               ((uint8)150U)
#define DMA_IP_REQ_MUX2_CTU_FIFO3               ((uint8)151U)
#define DMA_IP_REQ_MUX2_CTU_CMD_REQ             ((uint8)152U)
#define DMA_IP_REQ_MUX2_SUIL0_0                 ((uint8)153U)
#define DMA_IP_REQ_MUX2_SUIL0_1                 ((uint8)154U)
#define DMA_IP_REQ_MUX2_SUIL0_4                 ((uint8)155U)
#define DMA_IP_REQ_MUX2_SUIL0_5                 ((uint8)156U)
#define DMA_IP_REQ_MUX2_SUIL0_8                 ((uint8)157U)
#define DMA_IP_REQ_MUX2_SUIL0_9                 ((uint8)158U)
#define DMA_IP_REQ_MUX2_SARADC0                 ((uint8)160U)
#define DMA_IP_REQ_MUX2_SUIL1_0                 ((uint8)175U)
#define DMA_IP_REQ_MUX2_SUIL1_1                 ((uint8)176U)
#define DMA_IP_REQ_MUX2_SUIL1_4                 ((uint8)177U)
#define DMA_IP_REQ_MUX2_SUIL1_5                 ((uint8)178U)
#define DMA_IP_REQ_MUX2_FTM0_CH0                ((uint8)180U)
#define DMA_IP_REQ_MUX2_FTM0_CH1                ((uint8)181U)
#define DMA_IP_REQ_MUX2_FTM0_CH2                ((uint8)182U)
#define DMA_IP_REQ_MUX2_FTM0_CH3                ((uint8)183U)
#define DMA_IP_REQ_MUX2_FTM0_CH4                ((uint8)184U)
#define DMA_IP_REQ_MUX2_FTM0_CH5                ((uint8)185U)
#define DMA_IP_REQ_MUX2_ALWAYS_ON0              ((uint8)188U)
#define DMA_IP_REQ_MUX2_ALWAYS_ON1              ((uint8)189U)
#define DMA_IP_REQ_MUX2_ALWAYS_ON2              ((uint8)190U)
#define DMA_IP_REQ_MUX2_ALWAYS_ON3              ((uint8)191U)

#define DMA_IP_REQ_MUX3_DISABLED                ((uint8)192U)
#define DMA_IP_REQ_MUX3_CANFD2                  ((uint8)193U)
#define DMA_IP_REQ_MUX3_CANFD3                  ((uint8)194U)
#define DMA_IP_REQ_MUX3_LINFLEXD2_TX            ((uint8)195U)
#define DMA_IP_REQ_MUX3_LINFLEXD2_RX            ((uint8)196U)
#define DMA_IP_REQ_MUX3_QUADSPI_TX              ((uint8)197U)
#define DMA_IP_REQ_MUX3_QUADSPI_RX              ((uint8)198U)
#define DMA_IP_REQ_MUX3_DSPI3_TX                ((uint8)199U)
#define DMA_IP_REQ_MUX3_DSPI3_RX                ((uint8)200U)
#define DMA_IP_REQ_MUX3_DSPI3_CMD               ((uint8)201U)
#define DMA_IP_REQ_MUX3_DSPI4_TX                ((uint8)202U)
#define DMA_IP_REQ_MUX3_DSPI4_RX                ((uint8)203U)
#define DMA_IP_REQ_MUX3_DSPI4_CMD               ((uint8)204U)
#define DMA_IP_REQ_MUX3_DSPI5_TX                ((uint8)205U)
#define DMA_IP_REQ_MUX3_DSPI5_RX                ((uint8)206U)
#define DMA_IP_REQ_MUX3_DSPI5_CMD               ((uint8)207U)
#define DMA_IP_REQ_MUX3_I2C2_RX                 ((uint8)208U)
#define DMA_IP_REQ_MUX3_I2C2_TX                 ((uint8)209U)
#define DMA_IP_REQ_MUX3_I2C3_RX                 ((uint8)210U)
#define DMA_IP_REQ_MUX3_I2C3_TX                 ((uint8)211U)
#define DMA_IP_REQ_MUX3_I2C4_RX                 ((uint8)212U)
#define DMA_IP_REQ_MUX3_I2C4_TX                 ((uint8)213U)
#define DMA_IP_REQ_MUX3_ETHERNET0_CH0           ((uint8)214U)
#define DMA_IP_REQ_MUX3_ETHERNET0_CH1           ((uint8)215U)
#define DMA_IP_REQ_MUX3_ETHERNET0_CH2           ((uint8)216U)
#define DMA_IP_REQ_MUX3_SIUL0_2                 ((uint8)217U)
#define DMA_IP_REQ_MUX3_SIUL0_3                 ((uint8)218U)
#define DMA_IP_REQ_MUX3_SIUL0_6                 ((uint8)219U)
#define DMA_IP_REQ_MUX3_SIUL0_7                 ((uint8)220U)
#define DMA_IP_REQ_MUX3_SIUL0_10                ((uint8)221U)
#define DMA_IP_REQ_MUX3_SIUL0_11                ((uint8)222U)
#define DMA_IP_REQ_MUX3_SARADC1                 ((uint8)224U)
#define DMA_IP_REQ_MUX3_ETHERNET0_CH3           ((uint8)225U)
#define DMA_IP_REQ_MUX3_PFE_MAC0                ((uint8)229U)
#define DMA_IP_REQ_MUX3_PFE_MAC1                ((uint8)230U)
#define DMA_IP_REQ_MUX3_PFE_MAC2                ((uint8)231U)
#define DMA_IP_REQ_MUX3_SIUL1_2                 ((uint8)239U)
#define DMA_IP_REQ_MUX3_SIUL1_3                 ((uint8)240U)
#define DMA_IP_REQ_MUX3_SIUL1_6                 ((uint8)241U)
#define DMA_IP_REQ_MUX3_SIUL1_7                 ((uint8)242U)
#define DMA_IP_REQ_MUX3_FTM1_CH0                ((uint8)244U)
#define DMA_IP_REQ_MUX3_FTM1_CH1                ((uint8)245U)
#define DMA_IP_REQ_MUX3_FTM1_CH2                ((uint8)246U)
#define DMA_IP_REQ_MUX3_FTM1_CH3                ((uint8)247U)
#define DMA_IP_REQ_MUX3_FTM1_CH4                ((uint8)248U)
#define DMA_IP_REQ_MUX3_FTM1_CH5                ((uint8)249U)
#define DMA_IP_REQ_MUX3_ALWAYS_ON0              ((uint8)252U)
#define DMA_IP_REQ_MUX3_ALWAYS_ON1              ((uint8)253U)
#define DMA_IP_REQ_MUX3_ALWAYS_ON2              ((uint8)254U)
#define DMA_IP_REQ_MUX3_ALWAYS_ON3              ((uint8)255U)
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32r45')"!][!//
#define DMA_IP_REQ_MUX0_DISABLED                ((uint8)0U)
#define DMA_IP_REQ_MUX0_FLEXCAN0                ((uint8)1U)
#define DMA_IP_REQ_MUX0_FLEXCAN1                ((uint8)2U)
#define DMA_IP_REQ_MUX0_LINFLEXD0_TX            ((uint8)3U)
#define DMA_IP_REQ_MUX0_LINFLEXD0_RX            ((uint8)4U)
#define DMA_IP_REQ_MUX0_LINFLEXD1_TX            ((uint8)5U)
#define DMA_IP_REQ_MUX0_LINFLEXD1_RX            ((uint8)6U)
#define DMA_IP_REQ_MUX0_SPI0_TX                 ((uint8)7U)
#define DMA_IP_REQ_MUX0_SPI0_RX                 ((uint8)8U)
#define DMA_IP_REQ_MUX0_SPI0_CMD                ((uint8)9U)
#define DMA_IP_REQ_MUX0_SPI1_TX                 ((uint8)10U)
#define DMA_IP_REQ_MUX0_SPI1_RX                 ((uint8)11U)
#define DMA_IP_REQ_MUX0_SPI1_CMD                ((uint8)12U)
#define DMA_IP_REQ_MUX0_SPI2_TX                 ((uint8)13U)
#define DMA_IP_REQ_MUX0_SPI2_RX                 ((uint8)14U)
#define DMA_IP_REQ_MUX0_SPI2_CMD                ((uint8)15U)
#define DMA_IP_REQ_MUX0_I2C0_RX                 ((uint8)16U)
#define DMA_IP_REQ_MUX0_I2C0_TX                 ((uint8)17U)
#define DMA_IP_REQ_MUX0_I2C1_RX                 ((uint8)18U)
#define DMA_IP_REQ_MUX0_I2C1_TX                 ((uint8)19U)
#define DMA_IP_REQ_MUX0_CTU_FIFO0               ((uint8)20U)
#define DMA_IP_REQ_MUX0_CTU_FIFO1               ((uint8)21U)
#define DMA_IP_REQ_MUX0_CTU_FIFO2               ((uint8)22U)
#define DMA_IP_REQ_MUX0_CTU_FIFO3               ((uint8)23U)
#define DMA_IP_REQ_MUX0_CTU_CMD_REQ             ((uint8)24U)
#define DMA_IP_REQ_MUX0_SARADC0                 ((uint8)32U)
#define DMA_IP_REQ_MUX0_FTM0_CH0                ((uint8)36U)
#define DMA_IP_REQ_MUX0_FTM0_CH1                ((uint8)37U)
#define DMA_IP_REQ_MUX0_CTE                     ((uint8)38U)
#define DMA_IP_REQ_MUX0_FLEXCAN4                ((uint8)41U)
#define DMA_IP_REQ_MUX0_FLEXCAN5                ((uint8)42U)
#define DMA_IP_REQ_MUX0_SIUL2_ORED_3_0          ((uint8)43U)
#define DMA_IP_REQ_MUX0_SIUL2_ORED_7_4          ((uint8)44U)
#define DMA_IP_REQ_MUX0_SIUL2_ORED_11_8         ((uint8)45U)
#define DMA_IP_REQ_MUX0_SIUL2_ORED_15_12        ((uint8)46U)
#define DMA_IP_REQ_MUX0_CORESIGHT_DEBUG0        ((uint8)47U)
#define DMA_IP_REQ_MUX0_CORESIGHT_DEBUG1        ((uint8)48U)
#define DMA_IP_REQ_MUX0_MIPICSI2_0              ((uint8)49U)
#define DMA_IP_REQ_MUX0_MIPICSI2_1              ((uint8)50U)
#define DMA_IP_REQ_MUX0_MIPICSI2_2              ((uint8)51U)
#define DMA_IP_REQ_MUX0_MIPICSI2_3              ((uint8)52U)
#define DMA_IP_REQ_MUX0_FTM0_CH2                ((uint8)53U)
#define DMA_IP_REQ_MUX0_FTM0_CH3                ((uint8)54U)
#define DMA_IP_REQ_MUX0_FTM0_CH4                ((uint8)55U)
#define DMA_IP_REQ_MUX0_FTM0_CH5                ((uint8)56U)
#define DMA_IP_REQ_MUX0_ALWAYS_ON0              ((uint8)60U)
#define DMA_IP_REQ_MUX0_ALWAYS_ON1              ((uint8)61U)
#define DMA_IP_REQ_MUX0_ALWAYS_ON2              ((uint8)62U)
#define DMA_IP_REQ_MUX0_ALWAYS_ON3              ((uint8)63U)

#define DMA_IP_REQ_MUX1_DISABLED                ((uint8)64U)
#define DMA_IP_REQ_MUX1_FLEXCAN2                ((uint8)65U)
#define DMA_IP_REQ_MUX1_FLEXCAN3                ((uint8)66U)
#define DMA_IP_REQ_MUX1_QUADSPI_RX              ((uint8)68U)
#define DMA_IP_REQ_MUX1_QUADSPI_TX_BUFFER_F     ((uint8)69U)
#define DMA_IP_REQ_MUX1_QUADSPI_RX_BUFFER_D     ((uint8)70U)
#define DMA_IP_REQ_MUX1_SPI3_TX                 ((uint8)71U)
#define DMA_IP_REQ_MUX1_SPI3_RX                 ((uint8)72U)
#define DMA_IP_REQ_MUX1_SPI3_CMD                ((uint8)73U)
#define DMA_IP_REQ_MUX1_SPI4_TX                 ((uint8)74U)
#define DMA_IP_REQ_MUX1_SPI4_RX                 ((uint8)75U)
#define DMA_IP_REQ_MUX1_SPI4_CMD                ((uint8)76U)
#define DMA_IP_REQ_MUX1_SPI5_TX                 ((uint8)77U)
#define DMA_IP_REQ_MUX1_SPI5_RX                 ((uint8)78U)
#define DMA_IP_REQ_MUX1_SPI5_CMD                ((uint8)79U)
#define DMA_IP_REQ_MUX1_GMAC0_CH0               ((uint8)86U)
#define DMA_IP_REQ_MUX1_GMAC0_CH1               ((uint8)87U)
#define DMA_IP_REQ_MUX1_GMAC0_CH2               ((uint8)88U)
#define DMA_IP_REQ_MUX1_SARADC1                 ((uint8)96U)
#define DMA_IP_REQ_MUX1_GMAC0_CH3               ((uint8)97U)
#define DMA_IP_REQ_MUX1_FLEXCAN6                ((uint8)104U)
#define DMA_IP_REQ_MUX1_FLEXCAN7                ((uint8)105U)
#define DMA_IP_REQ_MUX1_GMAC1_CH0               ((uint8)106U)
#define DMA_IP_REQ_MUX1_GMAC1_CH1               ((uint8)107U)
#define DMA_IP_REQ_MUX1_GMAC1_CH2               ((uint8)108U)
#define DMA_IP_REQ_MUX1_GMAC1_CH3               ((uint8)109U)
#define DMA_IP_REQ_MUX1_SIUL2_ORED_19_16        ((uint8)110U)
#define DMA_IP_REQ_MUX1_SIUL2_ORED_23_20        ((uint8)111U)
#define DMA_IP_REQ_MUX1_SIUL2_ORED_27_24        ((uint8)112U)
#define DMA_IP_REQ_MUX1_SIUL2_ORED_31_28        ((uint8)113U)
#define DMA_IP_REQ_MUX1_FTM1_CH0                ((uint8)114U)
#define DMA_IP_REQ_MUX1_FTM1_CH1                ((uint8)115U)
#define DMA_IP_REQ_MUX1_ALWAYS_ON0              ((uint8)124U)
#define DMA_IP_REQ_MUX1_ALWAYS_ON1              ((uint8)125U)
#define DMA_IP_REQ_MUX1_ALWAYS_ON2              ((uint8)126U)
#define DMA_IP_REQ_MUX1_ALWAYS_ON3              ((uint8)127U)

#define DMA_IP_REQ_MUX2_DISABLED                ((uint8)128U)
#define DMA_IP_REQ_MUX2_FLEXCAN0                ((uint8)129U)
#define DMA_IP_REQ_MUX2_FLEXCAN1                ((uint8)130U)
#define DMA_IP_REQ_MUX2_LINFLEXD0_TX            ((uint8)131U)
#define DMA_IP_REQ_MUX2_LINFLEXD0_RX            ((uint8)132U)
#define DMA_IP_REQ_MUX2_LINFLEXD1_TX            ((uint8)133U)
#define DMA_IP_REQ_MUX2_LINFLEXD1_RX            ((uint8)134U)
#define DMA_IP_REQ_MUX2_SPI0_TX                 ((uint8)135U)
#define DMA_IP_REQ_MUX2_SPI0_RX                 ((uint8)136U)
#define DMA_IP_REQ_MUX2_SPI0_CMD                ((uint8)137U)
#define DMA_IP_REQ_MUX2_SPI1_TX                 ((uint8)138U)
#define DMA_IP_REQ_MUX2_SPI1_RX                 ((uint8)139U)
#define DMA_IP_REQ_MUX2_SPI1_CMD                ((uint8)140U)
#define DMA_IP_REQ_MUX2_SPI2_TX                 ((uint8)141U)
#define DMA_IP_REQ_MUX2_SPI2_RX                 ((uint8)142U)
#define DMA_IP_REQ_MUX2_SPI2_CMD                ((uint8)143U)
#define DMA_IP_REQ_MUX2_I2C0_RX                 ((uint8)144U)
#define DMA_IP_REQ_MUX2_I2C0_TX                 ((uint8)145U)
#define DMA_IP_REQ_MUX2_I2C1_RX                 ((uint8)146U)
#define DMA_IP_REQ_MUX2_I2C1_TX                 ((uint8)147U)
#define DMA_IP_REQ_MUX2_CTU_FIFO0               ((uint8)148U)
#define DMA_IP_REQ_MUX2_CTU_FIFO1               ((uint8)149U)
#define DMA_IP_REQ_MUX2_CTU_FIFO2               ((uint8)150U)
#define DMA_IP_REQ_MUX2_CTU_FIFO3               ((uint8)151U)
#define DMA_IP_REQ_MUX2_CTU_COMMAND_REQUEST     ((uint8)152U)
#define DMA_IP_REQ_MUX2_SARADC0                 ((uint8)160U)
#define DMA_IP_REQ_MUX2_FTM0_CH0                ((uint8)164U)
#define DMA_IP_REQ_MUX2_FTM0_CH1                ((uint8)165U)
#define DMA_IP_REQ_MUX2_CTE                     ((uint8)166U)
#define DMA_IP_REQ_MUX2_FLEXCAN4                ((uint8)169U)
#define DMA_IP_REQ_MUX2_FLEXCAN5                ((uint8)170U)
#define DMA_IP_REQ_MUX2_SIUL2_ORED_3_0          ((uint8)171U)
#define DMA_IP_REQ_MUX2_SIUL2_ORED_7_4          ((uint8)172U)
#define DMA_IP_REQ_MUX2_SIUL2_ORED_11_8         ((uint8)173U)
#define DMA_IP_REQ_MUX2_SIUL2_ORED_15_12        ((uint8)174U)
#define DMA_IP_REQ_MUX2_CORESIGHT_DEBUG0        ((uint8)175U)
#define DMA_IP_REQ_MUX2_CORESIGHT_DEBUG1        ((uint8)176U)
#define DMA_IP_REQ_MUX2_MIPICSI2_0              ((uint8)177U)
#define DMA_IP_REQ_MUX2_MIPICSI2_1              ((uint8)178U)
#define DMA_IP_REQ_MUX2_MIPICSI2_2              ((uint8)179U)
#define DMA_IP_REQ_MUX2_MIPICSI2_3              ((uint8)180U)
#define DMA_IP_REQ_MUX2_FTM0_CH2                ((uint8)181U)
#define DMA_IP_REQ_MUX2_FTM0_CH3                ((uint8)182U)
#define DMA_IP_REQ_MUX2_FTM0_CH4                ((uint8)183U)
#define DMA_IP_REQ_MUX2_FTM0_CH5                ((uint8)184U)
#define DMA_IP_REQ_MUX2_ALWAYS_ON0              ((uint8)188U)
#define DMA_IP_REQ_MUX2_ALWAYS_ON1              ((uint8)189U)
#define DMA_IP_REQ_MUX2_ALWAYS_ON2              ((uint8)190U)
#define DMA_IP_REQ_MUX2_ALWAYS_ON3              ((uint8)191U)

#define DMA_IP_REQ_MUX3_DISABLED                ((uint8)192U)
#define DMA_IP_REQ_MUX3_FLEXCAN2                ((uint8)193U)
#define DMA_IP_REQ_MUX3_FLEXCAN3                ((uint8)194U)
#define DMA_IP_REQ_MUX3_QUADSPI_TX_BUFFER_F     ((uint8)197U)
#define DMA_IP_REQ_MUX3_QUADSPI_RX_BUFFER_D     ((uint8)198U)
#define DMA_IP_REQ_MUX3_SPI3_TX                 ((uint8)199U)
#define DMA_IP_REQ_MUX3_SPI3_RX                 ((uint8)200U)
#define DMA_IP_REQ_MUX3_SPI3_CMD                ((uint8)201U)
#define DMA_IP_REQ_MUX3_SPI4_TX                 ((uint8)202U)
#define DMA_IP_REQ_MUX3_SPI4_RX                 ((uint8)203U)
#define DMA_IP_REQ_MUX3_SPI4_CMD                ((uint8)204U)
#define DMA_IP_REQ_MUX3_SPI5_TX                 ((uint8)205U)
#define DMA_IP_REQ_MUX3_SPI5_RX                 ((uint8)206U)
#define DMA_IP_REQ_MUX3_SPI5_CMD                ((uint8)207U)
#define DMA_IP_REQ_MUX3_GMAC0_CH0               ((uint8)214U)
#define DMA_IP_REQ_MUX3_GMAC0_CH1               ((uint8)215U)
#define DMA_IP_REQ_MUX3_GMAC0_CH2               ((uint8)216U)
#define DMA_IP_REQ_MUX3_SARADC1                 ((uint8)224U)
#define DMA_IP_REQ_MUX3_GMAC0_CH3               ((uint8)225U)
#define DMA_IP_REQ_MUX3_FLEXCAN6                ((uint8)232U)
#define DMA_IP_REQ_MUX3_FLEXCAN7                ((uint8)233U)
#define DMA_IP_REQ_MUX3_GMAC1_CH0               ((uint8)234U)
#define DMA_IP_REQ_MUX3_GMAC1_CH1               ((uint8)235U)
#define DMA_IP_REQ_MUX3_GMAC1_CH2               ((uint8)236U)
#define DMA_IP_REQ_MUX3_GMAC1_CH3               ((uint8)237U)
#define DMA_IP_REQ_MUX3_SIUL2_ORED_19_16        ((uint8)238U)
#define DMA_IP_REQ_MUX3_SIUL2_ORED_23_20        ((uint8)239U)
#define DMA_IP_REQ_MUX3_SIUL2_ORED_27_24        ((uint8)240U)
#define DMA_IP_REQ_MUX3_SIUL2_ORED_31_28        ((uint8)241U)
#define DMA_IP_REQ_MUX3_FTM1_CH0                ((uint8)242U)
#define DMA_IP_REQ_MUX3_FTM1_CH1                ((uint8)243U)
#define DMA_IP_REQ_MUX3_ALWAYS_ON0              ((uint8)252U)
#define DMA_IP_REQ_MUX3_ALWAYS_ON1              ((uint8)253U)
#define DMA_IP_REQ_MUX3_ALWAYS_ON2              ((uint8)254U)
#define DMA_IP_REQ_MUX3_ALWAYS_ON3              ((uint8)255U)
    [!ENDIF!][!//
[!ELSE!][!//
    [!ERROR "The Resource plugin or ResourceSubderivative field is not available for header file inclusion."!][!//
[!ENDIF!][!//
[!ENDINDENT!][!//

/*-----------------------------------------------/
/  DMA GROUP PRIORITY                            /
/-----------------------------------------------*/
#define DMA_IP_GROUP_PRIO0                      ((uint8)(0U))
#define DMA_IP_GROUP_PRIO1                      ((uint8)(1U))
#define DMA_IP_GROUP_PRIO2                      ((uint8)(2U))
#define DMA_IP_GROUP_PRIO3                      ((uint8)(3U))
#define DMA_IP_GROUP_PRIO4                      ((uint8)(4U))
#define DMA_IP_GROUP_PRIO5                      ((uint8)(5U))
#define DMA_IP_GROUP_PRIO6                      ((uint8)(6U))
#define DMA_IP_GROUP_PRIO7                      ((uint8)(7U))
#define DMA_IP_GROUP_PRIO8                      ((uint8)(8U))
#define DMA_IP_GROUP_PRIO9                      ((uint8)(9U))
#define DMA_IP_GROUP_PRIO10                     ((uint8)(10U))
#define DMA_IP_GROUP_PRIO11                     ((uint8)(11U))
#define DMA_IP_GROUP_PRIO12                     ((uint8)(12U))
#define DMA_IP_GROUP_PRIO13                     ((uint8)(13U))
#define DMA_IP_GROUP_PRIO14                     ((uint8)(14U))
#define DMA_IP_GROUP_PRIO15                     ((uint8)(15U))
#define DMA_IP_GROUP_PRIO16                     ((uint8)(16U))
#define DMA_IP_GROUP_PRIO17                     ((uint8)(17U))
#define DMA_IP_GROUP_PRIO18                     ((uint8)(18U))
#define DMA_IP_GROUP_PRIO19                     ((uint8)(19U))
#define DMA_IP_GROUP_PRIO20                     ((uint8)(20U))
#define DMA_IP_GROUP_PRIO21                     ((uint8)(21U))
#define DMA_IP_GROUP_PRIO22                     ((uint8)(22U))
#define DMA_IP_GROUP_PRIO23                     ((uint8)(23U))
#define DMA_IP_GROUP_PRIO24                     ((uint8)(24U))
#define DMA_IP_GROUP_PRIO25                     ((uint8)(25U))
#define DMA_IP_GROUP_PRIO26                     ((uint8)(26U))
#define DMA_IP_GROUP_PRIO27                     ((uint8)(27U))
#define DMA_IP_GROUP_PRIO28                     ((uint8)(28U))
#define DMA_IP_GROUP_PRIO29                     ((uint8)(29U))
#define DMA_IP_GROUP_PRIO30                     ((uint8)(30U))
#define DMA_IP_GROUP_PRIO31                     ((uint8)(31U))

/*-----------------------------------------------/
/  DMA CHANNEL PRIORITY                          /
/-----------------------------------------------*/
#define DMA_IP_LEVEL_PRIO0                      ((uint8)(0U))
#define DMA_IP_LEVEL_PRIO1                      ((uint8)(1U))
#define DMA_IP_LEVEL_PRIO2                      ((uint8)(2U))
#define DMA_IP_LEVEL_PRIO3                      ((uint8)(3U))
#define DMA_IP_LEVEL_PRIO4                      ((uint8)(4U))
#define DMA_IP_LEVEL_PRIO5                      ((uint8)(5U))
#define DMA_IP_LEVEL_PRIO6                      ((uint8)(6U))
#define DMA_IP_LEVEL_PRIO7                      ((uint8)(7U))

/*-----------------------------------------------/
/  DMA TRANSFER SIZE                             /
/-----------------------------------------------*/
#define DMA_IP_TRANSFER_SIZE_1_BYTE             ((uint8)(0U))
#define DMA_IP_TRANSFER_SIZE_2_BYTE             ((uint8)(1U))
#define DMA_IP_TRANSFER_SIZE_4_BYTE             ((uint8)(2U))
#define DMA_IP_TRANSFER_SIZE_8_BYTE             ((uint8)(3U))
#define DMA_IP_TRANSFER_SIZE_16_BYTE            ((uint8)(4U))
#define DMA_IP_TRANSFER_SIZE_32_BYTE            ((uint8)(5U))
#define DMA_IP_TRANSFER_SIZE_64_BYTE            ((uint8)(6U))

/*-----------------------------------------------/
/  DMA BANDWIDTH CONTROL                         /
/-----------------------------------------------*/
#define DMA_IP_BWC_ENGINE_NO_STALL              ((uint8)(0U))
#define DMA_IP_BWC_ENGINE_HPE                   ((uint8)(1U))
#define DMA_IP_BWC_ENGINE_4CYCLE_STALL          ((uint8)(2U))
#define DMA_IP_BWC_ENGINE_8CYCLE_STALL          ((uint8)(3U))

[!IF "node:value(./MclGeneral/MclDma/MclEnableDma)"!][!//
/*-----------------------------------------------/
/  DMA CRC INSTANCES                             /
/-----------------------------------------------*/
#define DMA_IP_CRC_HW_INST_0                    ((uint8)(0U))
#define DMA_IP_CRC_HW_INST_1                    ((uint8)(1U))

/*-----------------------------------------------/
/  DMA CRC CHANNELS                              /
/-----------------------------------------------*/
#define DMA_IP_HW_CRC_0_CH_0                    ((uint8)(0U))
#define DMA_IP_HW_CRC_0_CH_1                    ((uint8)(1U))
#define DMA_IP_HW_CRC_0_CH_2                    ((uint8)(2U))
#define DMA_IP_HW_CRC_0_CH_3                    ((uint8)(3U))
#define DMA_IP_HW_CRC_0_CH_4                    ((uint8)(4U))
#define DMA_IP_HW_CRC_0_CH_5                    ((uint8)(5U))
#define DMA_IP_HW_CRC_0_CH_6                    ((uint8)(6U))
#define DMA_IP_HW_CRC_0_CH_7                    ((uint8)(7U))

#define DMA_IP_HW_CRC_1_CH_0                    ((uint8)(0U))
#define DMA_IP_HW_CRC_1_CH_1                    ((uint8)(1U))
#define DMA_IP_HW_CRC_1_CH_2                    ((uint8)(2U))
#define DMA_IP_HW_CRC_1_CH_3                    ((uint8)(3U))
#define DMA_IP_HW_CRC_1_CH_4                    ((uint8)(4U))
#define DMA_IP_HW_CRC_1_CH_5                    ((uint8)(5U))
#define DMA_IP_HW_CRC_1_CH_6                    ((uint8)(6U))
#define DMA_IP_HW_CRC_1_CH_7                    ((uint8)(7U))

/*-----------------------------------------------/
/  DMA CRC MODE                                  /
/-----------------------------------------------*/
#define NORMAL_CRC_MODE                         ((uint8)(0U))

/*-----------------------------------------------/
/  DMA CRC POLYNOMIAL                            /
/-----------------------------------------------*/
#define ETHERNET_CCITT32_CRC32                  ((uint8)(0U))
#define CASTAGNOLI_ISCSICRC32C_CRC32            ((uint8)(1U))
#define E2E_PROFILE4_CRC32                      ((uint8)(2U))
#define X25_CCITT16_CRC16                       ((uint8)(3U))
#define H2F_AUTOSAR_4_0_CRC8                    ((uint8)(4U))
#define VDA_CAN_SAE_J1850_CRC8                  ((uint8)(5U))
[!ENDIF!][!//

/*-----------------------------------------------/
/  DMA CONVERT DCHPRI                            /
/-----------------------------------------------*/
#define DMA_CHN_TO_DCHPRI_INDEX(x)               (x)


[!ENDIF!][!//

#ifdef __cplusplus
}
#endif

#endif  /* #ifndef DMA_IP_CFG_DEFINES_H_ */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/

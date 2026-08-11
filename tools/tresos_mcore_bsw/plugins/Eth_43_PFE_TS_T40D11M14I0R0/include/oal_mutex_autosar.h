/* =========================================================================
 *  Project              : AUTOSAR 4.4 MCAL
 *  Platform             : CORTEXM
 *  Peripheral           : PFE
 *  Dependencies         : none
 *
 *  Autosar Version      : 4.4.0
 *  Autosar Revision     : ASR_REL_4_4_REV_0000
 *  Autosar Conf.Variant :
 *  SW Version           : 1.4.0
 *  Build Version        : PFE-DRV_S32G_M7_MCAL_1.4.0_D2405_ASR_REL_4_4_REV_0000_20240528
 * 
 *  Copyright 2018-2023 NXP
 *
 *  NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only
 *  be used strictly in accordance with the applicable license terms. By
 *  expressly accepting such terms or by downloading, installing, activating
 *  and/or otherwise using the software, you are agreeing that you have read,
 *  and that you agree to comply with and are bound by, such license terms. If
 *  you do not agree to be bound by the applicable license terms, then you may
 *  not retain, install, activate or otherwise use the software.
 *  <<< PFE Restricted Software >>>
 *
 * ========================================================================= */

/**
 * @addtogroup  dxgr_OAL_SYNC
 * @{
 *
 * @file        oal_mutex_autosar.h
 * @brief       The AUTOSAR-specific mutex implementation.
 * @details     This file contains AUTOSAR-specific mutex implementation.
 *
 */

#ifndef PUBLIC_OAL_MUTEX_AUTOSAR_H_
#define PUBLIC_OAL_MUTEX_AUTOSAR_H_

/*==================================================================================================
*                                     FILE VERSION CHECK
==================================================================================================*/
#ifdef PFE_SRC_VERSION_CHECK
    #if (PFE_SRC_VERSION_CHECK != 43140440)
        #error "This header file was included from incompatible source file (different SW version)"
    #endif
#else
    #define PFE_SRC_VERSION_CHECK 43140440
#endif

#include "SchM_Eth_43_PFE.h"
#include "oal_types.h"

#define MUTEX_POOL_SIZE      106U

enum
{
    MUTEX_ID_00  = 0,
    MUTEX_ID_01  = 1,
    MUTEX_ID_02  = 2,
    MUTEX_ID_03  = 3,
    MUTEX_ID_04  = 4,
    MUTEX_ID_05  = 5,
    MUTEX_ID_06  = 6,
    MUTEX_ID_07  = 7,
    MUTEX_ID_08  = 8,
    MUTEX_ID_09  = 9,
    MUTEX_ID_10  = 10,
    MUTEX_ID_11  = 11,
    MUTEX_ID_12  = 12,
    MUTEX_ID_13  = 13,
    MUTEX_ID_14  = 14,
    MUTEX_ID_15  = 15,
    MUTEX_ID_16  = 16,
    MUTEX_ID_17  = 17,
    MUTEX_ID_18  = 18,
    MUTEX_ID_19  = 19,
    MUTEX_ID_20  = 20,
    MUTEX_ID_21  = 21,
    MUTEX_ID_22  = 22,
    MUTEX_ID_23  = 23,
    MUTEX_ID_24  = 24,
    MUTEX_ID_25  = 25,
    MUTEX_ID_26  = 26,
    MUTEX_ID_27  = 27,
    MUTEX_ID_28  = 28,
    MUTEX_ID_29  = 29,
    MUTEX_ID_30  = 30,
    MUTEX_ID_31  = 31,
    MUTEX_ID_32  = 32,
    MUTEX_ID_33  = 33,
    MUTEX_ID_34  = 34,
    MUTEX_ID_35  = 35,
    MUTEX_ID_36  = 36,
    MUTEX_ID_37  = 37,
    MUTEX_ID_38  = 38,
    MUTEX_ID_39  = 39,
    MUTEX_ID_40  = 40,
    MUTEX_ID_41  = 41,
    MUTEX_ID_42  = 42,
    MUTEX_ID_43  = 43,
    MUTEX_ID_44  = 44,
    MUTEX_ID_45  = 45,
    MUTEX_ID_46  = 46,
    MUTEX_ID_47  = 47,
    MUTEX_ID_48  = 48,
    MUTEX_ID_49  = 49,
    MUTEX_ID_50  = 50,
    MUTEX_ID_51  = 51,
    MUTEX_ID_52  = 52,
    MUTEX_ID_53  = 53,
    MUTEX_ID_54  = 54,
    MUTEX_ID_55  = 55,
    MUTEX_ID_56  = 56,
    MUTEX_ID_57  = 57,
    MUTEX_ID_58  = 58,
    MUTEX_ID_59  = 59,
    MUTEX_ID_60  = 60,
    MUTEX_ID_61  = 61,
    MUTEX_ID_62  = 62,
    MUTEX_ID_63  = 63,
    MUTEX_ID_64  = 64,
    MUTEX_ID_65  = 65,
    MUTEX_ID_66  = 66,
    MUTEX_ID_67  = 67,
    MUTEX_ID_68  = 68,
    MUTEX_ID_69  = 69,
    MUTEX_ID_70  = 70,
    MUTEX_ID_71  = 71,
    MUTEX_ID_72  = 72,
    MUTEX_ID_73  = 73,
    MUTEX_ID_74  = 74,
    MUTEX_ID_75  = 75,
    MUTEX_ID_76  = 76,
    MUTEX_ID_77  = 77,
    MUTEX_ID_78  = 78,
    MUTEX_ID_79  = 79,
    MUTEX_ID_80  = 80,
    MUTEX_ID_81  = 81,
    MUTEX_ID_82  = 82,
    MUTEX_ID_83  = 83,
    MUTEX_ID_84  = 84,
    MUTEX_ID_85  = 85,
    MUTEX_ID_86  = 86,
    MUTEX_ID_87  = 87,
    MUTEX_ID_88  = 88,
    MUTEX_ID_89  = 89,
    MUTEX_ID_90  = 90,
    MUTEX_ID_91  = 91,
    MUTEX_ID_92  = 92,
    MUTEX_ID_93  = 93,
    MUTEX_ID_94  = 94,
    MUTEX_ID_95  = 95,
    MUTEX_ID_96  = 96,
    MUTEX_ID_97  = 97,
    MUTEX_ID_98  = 98,
    MUTEX_ID_99  = 99,
    MUTEX_ID_100 = 100,
    MUTEX_ID_101 = 101,
    MUTEX_ID_102 = 102,
    MUTEX_ID_103 = 103,
    MUTEX_ID_104 = 104,
    MUTEX_ID_105 = 105
};

typedef enum 
{
    PFE_BLALLOC_MUTEX_00            = MUTEX_ID_00,
    PFE_BLALLOC_MUTEX_01            = MUTEX_ID_01,
    PFE_BLALLOC_MUTEX_02            = MUTEX_ID_02,
    PFE_BLALLOC_MUTEX_03            = MUTEX_ID_03,
    PFE_LOG_IF_MUTEX_00             = MUTEX_ID_04,
    PFE_LOG_IF_MUTEX_01             = MUTEX_ID_05,
    PFE_LOG_IF_MUTEX_02             = MUTEX_ID_06,
    PFE_LOG_IF_MUTEX_03             = MUTEX_ID_07,
    PFE_LOG_IF_MUTEX_04             = MUTEX_ID_08,
    PFE_LOG_IF_MUTEX_05             = MUTEX_ID_09,
    PFE_LOG_IF_MUTEX_06             = MUTEX_ID_10,
    PFE_LOG_IF_MUTEX_07             = MUTEX_ID_11,
    PFE_LOG_IF_MUTEX_08             = MUTEX_ID_12,
    PFE_LOG_IF_MUTEX_09             = MUTEX_ID_13,
    PFE_LOG_IF_MUTEX_10             = MUTEX_ID_14,
    PFE_LOG_IF_MUTEX_11             = MUTEX_ID_15,
    PFE_LOG_IF_MUTEX_12             = MUTEX_ID_16,
    PFE_TS_QUEUE_WRITE_MUTEX        = MUTEX_ID_17,
    PFE_TS_QUEUE_READ_MUTEX         = MUTEX_ID_18,
    PFE_TX_BUFFER_POOL_MUTEX        = MUTEX_ID_19,
    PFE_ETHIF_TXCONFIR_API_MUTEX_00 = MUTEX_ID_20,
    PFE_ETHIF_TXCONFIR_API_MUTEX_01 = MUTEX_ID_21,
    PFE_CLASS_PE_MUTEX_00           = MUTEX_ID_22,
    PFE_CLASS_PE_MUTEX_01           = MUTEX_ID_23,
    PFE_CLASS_PE_MUTEX_02           = MUTEX_ID_24,
    PFE_CLASS_PE_MUTEX_03           = MUTEX_ID_25,
    PFE_CLASS_PE_MUTEX_04           = MUTEX_ID_26,
    PFE_CLASS_PE_MUTEX_05           = MUTEX_ID_27,
    PFE_CLASS_PE_MUTEX_06           = MUTEX_ID_28,
    PFE_CLASS_PE_MUTEX_07           = MUTEX_ID_29,
    PFE_UTIL_PE_MUTEX_00            = MUTEX_ID_30,
    PFE_UTIL_PE_MUTEX_01            = MUTEX_ID_31,
    PFE_UTIL_PE_MUTEX_02            = MUTEX_ID_32,
    PFE_UTIL_PE_MUTEX_03            = MUTEX_ID_33,
    PFE_UTIL_PE_MUTEX_04            = MUTEX_ID_34,
    PFE_UTIL_PE_MUTEX_05            = MUTEX_ID_35,
    PFE_HIF_PTP_TS_DB_MUTEX_00      = MUTEX_ID_36,
    PFE_HIF_PTP_TS_DB_MUTEX_01      = MUTEX_ID_37,
    PFE_HIF_PTP_TS_DB_MUTEX_02      = MUTEX_ID_38,
    PFE_HIF_PTP_TS_DB_MUTEX_03      = MUTEX_ID_39,
    PFE_HIF_PTP_TS_DB_MUTEX_04      = MUTEX_ID_40,
    PFE_CHNL_LOCK_MUTEX_00          = MUTEX_ID_41,
    PFE_CHNL_LOCK_MUTEX_01          = MUTEX_ID_42,
    PFE_CHNL_LOCK_MUTEX_02          = MUTEX_ID_43,
    PFE_CHNL_LOCK_MUTEX_03          = MUTEX_ID_44,
    PFE_CHNL_LOCK_MUTEX_04          = MUTEX_ID_45,
    PFE_CHNL_LOCK_MUTEX_05          = MUTEX_ID_46,
    PFE_CHNL_LOCK_MUTEX_06          = MUTEX_ID_47,
    PFE_CHNL_LOCK_MUTEX_07          = MUTEX_ID_48,
    PFE_CHNL_LOCK_MUTEX_08          = MUTEX_ID_49,
    PFE_CHNL_LOCK_MUTEX_09          = MUTEX_ID_50,
    PFE_CHNL_LOCK_MUTEX_10          = MUTEX_ID_51,
    PFE_CHNL_LOCK_MUTEX_11          = MUTEX_ID_52,
    PFE_CHNL_LOCK_MUTEX_12          = MUTEX_ID_53,
    PFE_CHNL_RX_LOCK_MUTEX          = MUTEX_ID_54,
    PFE_CHNL_A_LOCK_MUTEX_00        = MUTEX_ID_55,
    PFE_CHNL_A_LOCK_MUTEX_01        = MUTEX_ID_56,
    PFE_EMAC_MUTEX_00               = MUTEX_ID_57,
    PFE_EMAC_MUTEX_01               = MUTEX_ID_58,
    PFE_EMAC_MUTEX_02               = MUTEX_ID_59,
    PFE_EMAC_MUTEX_03               = MUTEX_ID_60,
    PFE_EMAC_TS_MUTEX_00            = MUTEX_ID_61,
    PFE_EMAC_TS_MUTEX_01            = MUTEX_ID_62,
    PFE_EMAC_TS_MUTEX_02            = MUTEX_ID_63,
    PFE_EMAC_TS_MUTEX_03            = MUTEX_ID_64,
    PFE_EMAC_TS_MUTEX_04            = MUTEX_ID_65,
    PFE_EMAC_TS_MUTEX_05            = MUTEX_ID_66,
    PFE_RTABLE_LOCK_MUTEX_00        = MUTEX_ID_67,
    PFE_RTABLE_LOCK_MUTEX_01        = MUTEX_ID_68,
    PFE_RTABLE_LOCK_MUTEX_02        = MUTEX_ID_69,
    PFE_RTABLE_LOCK_MUTEX_03        = MUTEX_ID_70,
    PFE_RTABLE_LOCK_MUTEX_04        = MUTEX_ID_71,
    PFE_RTABLE_LOCK_MUTEX_05        = MUTEX_ID_72,
    PFE_RTABLE_LOCK_MUTEX_06        = MUTEX_ID_73,
    PFE_RTABLE_LOCK_MUTEX_07        = MUTEX_ID_74,
    PFE_RTABLE_LOCK_MUTEX_08        = MUTEX_ID_75,
    PFE_RTABLE_LOCK_MUTEX_09        = MUTEX_ID_76,
    PFE_RTABLE_LOCK_MUTEX_10        = MUTEX_ID_77,
    PFE_RTABLE_LOCK_MUTEX_11        = MUTEX_ID_78,
    PFE_RTABLE_LOCK_MUTEX_12        = MUTEX_ID_79,
    PFE_RTABLE_LOCK_MUTEX_13        = MUTEX_ID_80,
    PFE_RTABLE_LOCK_MUTEX_14        = MUTEX_ID_81,
    PFE_RTABLE_LOCK_MUTEX_15        = MUTEX_ID_82,
    PFE_IF_DB_CONTEXT_MUTEX_00      = MUTEX_ID_83,
    PFE_IF_DB_CONTEXT_MUTEX_01      = MUTEX_ID_84,
    PFE_IF_DB_CONTEXT_MUTEX_02      = MUTEX_ID_85,
    PFE_IF_DB_CONTEXT_MUTEX_03      = MUTEX_ID_86,
    PFE_IF_DB_CONTEXT_MUTEX_04      = MUTEX_ID_87,
    PFE_IF_DB_CONTEXT_MUTEX_05      = MUTEX_ID_88,
    PFE_IF_DB_CONTEXT_MUTEX_06      = MUTEX_ID_89,
    PFE_IF_DB_CONTEXT_MUTEX_07      = MUTEX_ID_90,
    PFE_HIF_DRV_MUTEX_00            = MUTEX_ID_91,
    PFE_HIF_DRV_MUTEX_01            = MUTEX_ID_92,
    PFE_OAL_UTIL_SEQNUM_MUTEX       = MUTEX_ID_93,
    PFE_HIF_TX_JOB_MUTEX            = MUTEX_ID_94,
    PFE_FCI_FIFO_MUTEX_00           = MUTEX_ID_95,
    PFE_FCI_FIFO_MUTEX_01           = MUTEX_ID_96,
    PFE_FCI_CONTEXT_DB_MUTEX_00     = MUTEX_ID_97,
    PFE_FCI_CONTEXT_DB_MUTEX_01     = MUTEX_ID_98,
    PFE_FCI_OWNER_MUTEX             = MUTEX_ID_99, /* This mutex cannot be implemented as suspend all interrupts */
    PFE_HM_MUTEX_00                 = MUTEX_ID_100,
    PFE_HM_MUTEX_01                 = MUTEX_ID_101,
    PFE_CLASS_MUTEX_00              = MUTEX_ID_102,
    PFE_CLASS_MUTEX_01              = MUTEX_ID_103,
    PFE_CLASS_MUTEX_02              = MUTEX_ID_104
} oal_mutex_id_t;

typedef oal_mutex_id_t oal_mutex_t;

#define ETH_43_PFE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
static void (*SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID[MUTEX_POOL_SIZE])(void) =
{
    [MUTEX_ID_00]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00,
    [MUTEX_ID_01]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01,
    [MUTEX_ID_02]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02,
    [MUTEX_ID_03]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03,
    [MUTEX_ID_04]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04,
    [MUTEX_ID_05]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05,
    [MUTEX_ID_06]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06,
    [MUTEX_ID_07]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07,
    [MUTEX_ID_08]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08,
    [MUTEX_ID_09]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09,
    [MUTEX_ID_10]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10,
    [MUTEX_ID_11]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11,
    [MUTEX_ID_12]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12,
    [MUTEX_ID_13]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13,
    [MUTEX_ID_14]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14,
    [MUTEX_ID_15]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15,
    [MUTEX_ID_16]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16,
    [MUTEX_ID_17]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17,
    [MUTEX_ID_18]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18,
    [MUTEX_ID_19]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19,
    [MUTEX_ID_20]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20,
    [MUTEX_ID_21]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21,
    [MUTEX_ID_22]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22,
    [MUTEX_ID_23]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23,
    [MUTEX_ID_24]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24,
    [MUTEX_ID_25]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25,
    [MUTEX_ID_26]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26,
    [MUTEX_ID_27]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27,
    [MUTEX_ID_28]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28,
    [MUTEX_ID_29]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29,
    [MUTEX_ID_30]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30,
    [MUTEX_ID_31]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31,
    [MUTEX_ID_32]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32,
    [MUTEX_ID_33]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33,
    [MUTEX_ID_34]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34,
    [MUTEX_ID_35]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35,
    [MUTEX_ID_36]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36,
    [MUTEX_ID_37]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37,
    [MUTEX_ID_38]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38,
    [MUTEX_ID_39]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39,
    [MUTEX_ID_40]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40,
    [MUTEX_ID_41]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41,
    [MUTEX_ID_42]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42,
    [MUTEX_ID_43]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43,
    [MUTEX_ID_44]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44,
    [MUTEX_ID_45]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45,
    [MUTEX_ID_46]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46,
    [MUTEX_ID_47]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47,
    [MUTEX_ID_48]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48,
    [MUTEX_ID_49]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49,
    [MUTEX_ID_50]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50,
    [MUTEX_ID_51]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51,
    [MUTEX_ID_52]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52,
    [MUTEX_ID_53]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53,
    [MUTEX_ID_54]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54,
    [MUTEX_ID_55]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55,
    [MUTEX_ID_56]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56,
    [MUTEX_ID_57]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57,
    [MUTEX_ID_58]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58,
    [MUTEX_ID_59]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59,
    [MUTEX_ID_60]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60,
    [MUTEX_ID_61]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61,
    [MUTEX_ID_62]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62,
    [MUTEX_ID_63]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63,
    [MUTEX_ID_64]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64,
    [MUTEX_ID_65]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65,
    [MUTEX_ID_66]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66,
    [MUTEX_ID_67]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67,
    [MUTEX_ID_68]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68,
    [MUTEX_ID_69]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69,
    [MUTEX_ID_70]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70,
    [MUTEX_ID_71]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71,
    [MUTEX_ID_72]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72,
    [MUTEX_ID_73]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73,
    [MUTEX_ID_74]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74,
    [MUTEX_ID_75]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75,
    [MUTEX_ID_76]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76,
    [MUTEX_ID_77]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77,
    [MUTEX_ID_78]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78,
    [MUTEX_ID_79]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79,
    [MUTEX_ID_80]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80,
    [MUTEX_ID_81]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81,
    [MUTEX_ID_82]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82,
    [MUTEX_ID_83]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83,
    [MUTEX_ID_84]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84,
    [MUTEX_ID_85]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85,
    [MUTEX_ID_86]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86,
    [MUTEX_ID_87]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87,
    [MUTEX_ID_88]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88,
    [MUTEX_ID_89]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89,
    [MUTEX_ID_90]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90,
    [MUTEX_ID_91]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91,
    [MUTEX_ID_92]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92,
    [MUTEX_ID_93]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93,
    [MUTEX_ID_94]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94,
    [MUTEX_ID_95]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95,
    [MUTEX_ID_96]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96,
    [MUTEX_ID_97]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97,
    [MUTEX_ID_98]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98,
    [MUTEX_ID_99]  = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99,
    [MUTEX_ID_100] = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100,
    [MUTEX_ID_101] = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101,
    [MUTEX_ID_102] = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102,
    [MUTEX_ID_103] = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103,
    [MUTEX_ID_104] = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104
};

static void (*SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID[MUTEX_POOL_SIZE])(void) =
{
    [MUTEX_ID_00]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00,
    [MUTEX_ID_01]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01,
    [MUTEX_ID_02]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02,
    [MUTEX_ID_03]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03,
    [MUTEX_ID_04]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04,
    [MUTEX_ID_05]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05,
    [MUTEX_ID_06]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06,
    [MUTEX_ID_07]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07,
    [MUTEX_ID_08]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08,
    [MUTEX_ID_09]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09,
    [MUTEX_ID_10]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10,
    [MUTEX_ID_11]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11,
    [MUTEX_ID_12]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12,
    [MUTEX_ID_13]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13,
    [MUTEX_ID_14]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14,
    [MUTEX_ID_15]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15,
    [MUTEX_ID_16]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16,
    [MUTEX_ID_17]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17,
    [MUTEX_ID_18]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18,
    [MUTEX_ID_19]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19,
    [MUTEX_ID_20]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20,
    [MUTEX_ID_21]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21,
    [MUTEX_ID_22]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22,
    [MUTEX_ID_23]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23,
    [MUTEX_ID_24]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24,
    [MUTEX_ID_25]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25,
    [MUTEX_ID_26]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26,
    [MUTEX_ID_27]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27,
    [MUTEX_ID_28]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28,
    [MUTEX_ID_29]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29,
    [MUTEX_ID_30]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30,
    [MUTEX_ID_31]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31,
    [MUTEX_ID_32]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32,
    [MUTEX_ID_33]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33,
    [MUTEX_ID_34]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34,
    [MUTEX_ID_35]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35,
    [MUTEX_ID_36]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36,
    [MUTEX_ID_37]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37,
    [MUTEX_ID_38]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38,
    [MUTEX_ID_39]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39,
    [MUTEX_ID_40]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40,
    [MUTEX_ID_41]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41,
    [MUTEX_ID_42]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42,
    [MUTEX_ID_43]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43,
    [MUTEX_ID_44]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44,
    [MUTEX_ID_45]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45,
    [MUTEX_ID_46]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46,
    [MUTEX_ID_47]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47,
    [MUTEX_ID_48]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48,
    [MUTEX_ID_49]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49,
    [MUTEX_ID_50]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50,
    [MUTEX_ID_51]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51,
    [MUTEX_ID_52]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52,
    [MUTEX_ID_53]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53,
    [MUTEX_ID_54]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54,
    [MUTEX_ID_55]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55,
    [MUTEX_ID_56]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56,
    [MUTEX_ID_57]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57,
    [MUTEX_ID_58]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58,
    [MUTEX_ID_59]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59,
    [MUTEX_ID_60]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60,
    [MUTEX_ID_61]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61,
    [MUTEX_ID_62]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62,
    [MUTEX_ID_63]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63,
    [MUTEX_ID_64]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64,
    [MUTEX_ID_65]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65,
    [MUTEX_ID_66]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66,
    [MUTEX_ID_67]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67,
    [MUTEX_ID_68]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68,
    [MUTEX_ID_69]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69,
    [MUTEX_ID_70]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70,
    [MUTEX_ID_71]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71,
    [MUTEX_ID_72]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72,
    [MUTEX_ID_73]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73,
    [MUTEX_ID_74]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74,
    [MUTEX_ID_75]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75,
    [MUTEX_ID_76]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76,
    [MUTEX_ID_77]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77,
    [MUTEX_ID_78]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78,
    [MUTEX_ID_79]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79,
    [MUTEX_ID_80]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80,
    [MUTEX_ID_81]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81,
    [MUTEX_ID_82]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82,
    [MUTEX_ID_83]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83,
    [MUTEX_ID_84]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84,
    [MUTEX_ID_85]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85,
    [MUTEX_ID_86]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86,
    [MUTEX_ID_87]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87,
    [MUTEX_ID_88]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88,
    [MUTEX_ID_89]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89,
    [MUTEX_ID_90]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90,
    [MUTEX_ID_91]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91,
    [MUTEX_ID_92]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92,
    [MUTEX_ID_93]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93,
    [MUTEX_ID_94]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94,
    [MUTEX_ID_95]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95,
    [MUTEX_ID_96]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96,
    [MUTEX_ID_97]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97,
    [MUTEX_ID_98]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98,
    [MUTEX_ID_99]  = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99,
    [MUTEX_ID_100] = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100,
    [MUTEX_ID_101] = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101,
    [MUTEX_ID_102] = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102,
    [MUTEX_ID_103] = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103,
    [MUTEX_ID_104] = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104
};

#define ETH_43_PFE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/** @}*/
/* =========================================================================================== */
/*  Implementation continues below to ensure Doxygen will put the API description
    from oal_sync.h at right place (related to oal_sync.h header). */
static inline void oal_mutex_lock(const oal_mutex_t mutex)
{
    if (MUTEX_POOL_SIZE > mutex)
    {
        SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID[mutex]();
    }
    else
    {
        NXP_LOG_RAW_ERROR("Critical development Error !! Invalid mutex id: %u for oal_mutex_lock()\n", (uint_t)mutex);
    }
}

/* =========================================================================================== */
static inline void oal_mutex_unlock(const oal_mutex_t mutex)
{
    if (MUTEX_POOL_SIZE > mutex)
    {
        SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID[mutex]();
    }
    else
    {
        NXP_LOG_RAW_ERROR("Critical development Error !! Invalid mutex id: %u for oal_mutex_unlock()\n", (uint_t)mutex);
    }
}

/* =========================================================================================== */
#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PUBLIC_OAL_MUTEX_AUTOSAR_H_ */


/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : LLCE
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 1.0.7
*   Build Version        : S32_RTD_1_0_7_D2909_ASR_REL_4_4_REV_0000_20230630
*
*   (c) Copyright 2020-2023 NXP Semiconductors
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
* @file Flexray_43_LLCE_Ip_Types.h
*
* @brief Flexray Ip Types Header File
* @details This Files Contains the Flexray Ip data types used external by Flexray Ip Driver
*
* @addtogroup Flexray
* @{
*/
#ifndef FLEXRAY_IP_Types_H
#define FLEXRAY_IP_Types_H
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Flexray_43_LLCE_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
 * @brief Parameters that shall be published within the driver header file and also in the
 *        module's description file
 */

#define FLEXRAY_IP_TYPES_MODULE_ID                        81
#define FLEXRAY_IP_TYPES_VENDOR_ID                        43
#define FLEXRAY_IP_TYPES_AR_RELEASE_MAJOR_VERSION         4
#define FLEXRAY_IP_TYPES_AR_RELEASE_MINOR_VERSION         4
#define FLEXRAY_IP_TYPES_AR_RELEASE_REVISION_VERSION      0
#define FLEXRAY_IP_TYPES_SW_MAJOR_VERSION                 1
#define FLEXRAY_IP_TYPES_SW_MINOR_VERSION                 0
#define FLEXRAY_IP_TYPES_SW_PATCH_VERSION                 7

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Flexray_43_LLCE_Ip_Cfg.h header file are of the same vendor */
#if (FLEXRAY_IP_TYPES_VENDOR_ID != FLEXRAY_IP_CFG_VENDOR_ID )
    #error "Flexray_43_LLCE_Ip_Types.h and Flexray_43_LLCE_Ip_Cfg.h have different Vendor IDs"
#endif
/* Check if current file and Flexray_43_LLCE_Ip_Cfg.h header file are of the same Autosar version */
#if ((FLEXRAY_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != FLEXRAY_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXRAY_IP_TYPES_AR_RELEASE_MINOR_VERSION    != FLEXRAY_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (FLEXRAY_IP_TYPES_AR_RELEASE_REVISION_VERSION != FLEXRAY_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "Software Version Numbers of Flexray_43_LLCE_Ip_Types.h and Flexray_43_LLCE_Ip_Cfg.h are different"
#endif
/* Check if current file and Flexray_43_LLCE_Ip_Cfg.h header file are of the same software version */
#if ((FLEXRAY_IP_TYPES_SW_MAJOR_VERSION != FLEXRAY_IP_CFG_SW_MAJOR_VERSION) || \
     (FLEXRAY_IP_TYPES_SW_MINOR_VERSION != FLEXRAY_IP_CFG_SW_MINOR_VERSION) || \
     (FLEXRAY_IP_TYPES_SW_PATCH_VERSION != FLEXRAY_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Autosar Version Numbers of Flexray_43_LLCE_Ip_Types.h and Flexray_43_LLCE_Ip_Cfg.h are different"
#endif
/*==================================================================================================
*                                      DEFINES IP-VAULT VERSION
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/* This value is used for never-ending NMV reading protection */
#define FR_IPW_MAX_NMVREAD_U8                       ((uint8)5U)

/* Module Version Register value */
#define FLEXRAY_MVR_U16                                                 ((uint16)FLEXRAY_HW_VERSION)
/* FlexRay module register bitfields and values */
/* FLEXRAY_PSR0 slot mode */
#define FLEXRAY_PSR0_SLOTMODE_SINGLE_U16                                ((uint16)0x0000U)
#define FLEXRAY_PSR0_SLOTMODE_ALL_PENDING_U16                           ((uint16)0x1000U)
#define FLEXRAY_PSR0_SLOTMODE_ALL_U16                                   ((uint16)0x2000U)
/* FLEXRAY_PSR0 error mode */
#define FLEXRAY_PSR0_ERRMODE_ACTIVE_U16                                 ((uint16)0x0000U)
#define FLEXRAY_PSR0_ERRMODE_PASSIVE_U16                                ((uint16)0x4000U)
#define FLEXRAY_PSR0_ERRMODE_COMM_HALT_U16                              ((uint16)0x8000U)
/* FLEXRAY_PSR0 protocol state  */
#define FLEXRAY_PSR0_PROTSTATE_DEFAULT_CONFIG_U16                       ((uint16)0x0000U)
#define FLEXRAY_PSR0_PROTSTATE_CONFIG_U16                               ((uint16)0x0001U)
#define FLEXRAY_PSR0_PROTSTATE_WAKEUP_U16                               ((uint16)0x0002U)
#define FLEXRAY_PSR0_PROTSTATE_READY_U16                                ((uint16)0x0003U)
#define FLEXRAY_PSR0_PROTSTATE_NORMAL_PASSIVE_U16                       ((uint16)0x0004U)
#define FLEXRAY_PSR0_PROTSTATE_NORMAL_ACTIVE_U16                        ((uint16)0x0005U)
#define FLEXRAY_PSR0_PROTSTATE_HALT_U16                                 ((uint16)0x0006U)
#define FLEXRAY_PSR0_PROTSTATE_STARTUP_U16                              ((uint16)0x0007U)
/* FLEXRAY_PSR0 startup state */
#define FLEXRAY_PSR0_STARTUP_CCR_U16                                    ((uint16)0x002U)
#define FLEXRAY_PSR0_STARTUP_CL_U16                                     ((uint16)0x003U)
#define FLEXRAY_PSR0_STARTUP_ICOC_U16                                   ((uint16)0x004U)
#define FLEXRAY_PSR0_STARTUP_IL_U16                                     ((uint16)0x005U)
#define FLEXRAY_PSR0_STARTUP_IS_U16                                     ((uint16)0x007U)
#define FLEXRAY_PSR0_STARTUP_CCC_U16                                    ((uint16)0x00AU)
#define FLEXRAY_PSR0_STARTUP_ICLC_U16                                   ((uint16)0x00DU)
#define FLEXRAY_PSR0_STARTUP_CG_U16                                     ((uint16)0x00EU)
#define FLEXRAY_PSR0_STARTUP_CJ_U16                                     ((uint16)0x00FU)
/* FLEXRAY_PSR0 wakeup status */
#define FLEXRAY_PSR0_WUP_UD_U16                                         ((uint16)0x0000U)
#define FLEXRAY_PSR0_WUP_RH_U16                                         ((uint16)0x0001U)
#define FLEXRAY_PSR0_WUP_RW_U16                                         ((uint16)0x0002U)
#define FLEXRAY_PSR0_WUP_HC_U16                                         ((uint16)0x0003U)
#define FLEXRAY_PSR0_WUP_WC_U16                                         ((uint16)0x0004U)
#define FLEXRAY_PSR0_WUP_UC_U16                                         ((uint16)0x0005U)
#define FLEXRAY_PSR0_WUP_T_U16                                          ((uint16)0x0006U)
#define FLEXRAY_PSR0_WUP_RESERVED_U16                                   ((uint16)0x0007U)
/* FLEXRAY_PSR1 bitfields */
#define FLEXRAY_PSR1_CPN_U16                                            ((uint16)0x0080U)
#define FLEXRAY_PSR1_HHR_U16                                            ((uint16)0x0040U)
#define FLEXRAY_PSR1_FRZ_U16                                            ((uint16)0x0020U)
/* FLEXRAY_PSR2 bitfields */
#define FLEXRAY_PSR2_CHB_MASK_U16                                       ((uint16)0xFC00U)
#define FLEXRAY_PSR2_CHA_MASK_U16                                       ((uint16)0x03F0U)
#define FLEXRAY_PSR2_STCB_U16                                           ((uint16)0x2000U)
#define FLEXRAY_PSR2_STCA_U16                                           ((uint16)0x0080U)
/* FLEXRAY_PSR3 bitfields */
#define FLEXRAY_PSR3_CHB_MASK_U16                                       ((uint16)0x1F00U)
#define FLEXRAY_PSR3_CHA_MASK_U16                                       ((uint16)0x001FU)
/* FLEXRAY_MBCCSR bitfields */
#define FLEXRAY_MBCCSR0_CONFIG_MASK_U16                                 ((uint16)0x7900U)
/* FLEXRAY_MBFIDR bitfields */
#define FLEXRAY_FRAMEHEADER0_PPI_MASK_U16                               ((uint16)0x4000U)
#define FLEXRAY_FRAMEHEADER1_PLDLEN_MASK_U16                            ((uint16)0x007FU)
#define FLEXRAY_GIFER_INT_FLAGS_MASK_U16                                ((uint16)0xFF00U)

/*FR 16-bit registers mask */
#define FLEXRAY_REGISTER_MASK_HIGH_U32                                  ((uint32)0xFFFF0000U)
#define FLEXRAY_REGISTER_MASK_LOW_U32                                   ((uint32)0x0000FFFFU)
#define FLEXRAY_REGISTER_OFFSET_U8                                      ((uint8)16U)

/*FR payload data field mask */
#define FLEXRAY_EVEN_PAYLOAD_BYTE_MASK_U32                              ((uint32)0x00FF00FF00U)
#define FLEXRAY_ODD_PAYLOAD_BYTE_MASK_U32                               ((uint32)0x0000FF00FFU)
#define FLEXRAY_EVEN_PAYLOAD_BYTE_MASK_U16                              ((uint16)0xFF00U)
#define FLEXRAY_ODD_PAYLOAD_BYTE_MASK_U16                               ((uint16)0x00FFU)
#define FLEXRAY_PAYLOAD_BYTE_OFFSET_U32                                 ((uint32)8U)

/* Message buffer header size divided by 2 since memory access is 16-bit on autosar functions*/
#define FLEXRAY_HEADER_SIZE_U8                                       ((uint8)4U)
#define FLEXRAY_STATUS_SLOT_U8                                       ((uint8)3U)
/*==================================================================================================
*                                             ENUMS
====================================================================================================*/

/***************************************************************************************************
* @enum Flexray_Ip_StatusType
* @brief Flexray Ip-layer specific return types.
***************************************************************************************************/
typedef enum
{
    /* Generic error codes */
    FLEXRAY_STATUS_SUCCESS                         = 0x000U,    /*!< Generic operation success status */
    FLEXRAY_STATUS_ERROR                           = 0x001U,    /*!< Generic operation failure status */
    FLEXRAY_STATUS_BUSY                            = 0x002U,    /*!< Generic operation busy status */
    FLEXRAY_STATUS_TIMEOUT                         = 0x003U,    /*!< Generic operation timeout status */
    FLEXRAY_STATUS_UNSUPPORTED                     = 0x004U,    /*!< Generic operation unsupported status */

    /* FLEXRAY specific error codes */
    FLEXRAY_STATUS_ABORTED                 = 0x1203U, /*!< FLEXRAY aborted status */
    FLEXRAY_STATUS_TX_CONFLICT_A           = 0x1204U, /*!< FLEXRAY TX conflict reported by hardware on channel A */
    FLEXRAY_STATUS_TX_CONFLICT_B           = 0x1205U, /*!< FLEXRAY TX conflict reported by hardware on channel B */
    FLEXRAY_STATUS_TX_CONFLICT_AB          = 0x1206U, /*!< FLEXRAY TX conflict reported by hardware on channel A & B */
    FLEXRAY_STATUS_FIFO_A_ERROR_CONFIG     = 0x1207U, /*!< Start index is not equal than read index into FIFO A when initialize again */
    FLEXRAY_STATUS_FIFO_B_ERROR_CONFIG     = 0x1208U, /*!< Start index is not equal than read index into FIFO B when initialize again */
    FLEXRAY_STATUS_FIFO_AB_ERROR_CONFIG    = 0x1209U, /*!< Start index is not equal than read index into FIFO A & B when initialize again */

} Flexray_Ip_StatusType;

/***************************************************************************************************
* @enum Flexray_Ip_FifoChannelType
*  @brief Type channel definition for Receive FIFO storage
***************************************************************************************************/
typedef enum
{
    FLEXRAY_RECEIVE_FIFOA = 0U,  /* Receive FIFO A */
    FLEXRAY_RECEIVE_FIFOB        /* Receive FIFO B */
} Flexray_Ip_FifoChannelType;


/* start data types from sdk */

/*!
 * @brief Protocol Control Command
 *
 */
typedef enum
{
    FLEXRAY_CHI_CMD_ALLOW_COLDSTART = 0U,   /*!< Active cold start cluster */
    FLEXRAY_CHI_CMD_ALL_SLOTS       = 1U,   /*!< Delayed transition to the all slots transmission mode */
    FLEXRAY_CHI_CMD_CONFIG          = 2U,   /*!< Transition to the POC:config state */
    FLEXRAY_CHI_CMD_FREEZE          = 3U,   /*!< Transition to POC:halt state */
    FLEXRAY_CHI_CMD_READY           = 4U,   /*!< Transition to POC:ready state */
    FLEXRAY_CHI_CMD_CONFIG_COMPLETE = 4U,   /*!< Transition to POC:ready state */
    FLEXRAY_CHI_CMD_RUN             = 5U,   /*!< Transition to POC:startup start state */
    FLEXRAY_CHI_CMD_DEFAULT_CONFIG  = 6U,   /*!< Transition to POC:default config state */
    FLEXRAY_CHI_CMD_HALT            = 7U,   /*!< Delayed transition to the POC:halt state */
    FLEXRAY_CHI_CMD_WAKEUP          = 8U    /*!< Initiate the wakeup procedure */
} Flexray_Ip_ChiCmdType;

/*!
 * @brief Flexray Protocol State
 */
typedef enum
{
    FLEXRAY_STATE_CONFIG         = 0U,      /*!< POC:default config state */
    FLEXRAY_STATE_DEFAULT_CONFIG = 1U,      /*!< POC:config state */
    FLEXRAY_STATE_HALT           = 2U,      /*!< POC:halt state */
    FLEXRAY_STATE_NORMAL_ACTIVE  = 3U,      /*!< POC:normal active state */
    FLEXRAY_STATE_NORMAL_PASSIVE = 4U,      /*!< POC:normal passive state */
    FLEXRAY_STATE_READY          = 5U,      /*!< POC:ready state */
    FLEXRAY_STATE_STARTUP        = 6U,      /*!< POC:startup state */
    FLEXRAY_STATE_WAKEUP         = 7U       /*!< POC:wakeup state */
} Flexray_Ip_PocStateType;

/*!
 * @brief External Offset Correction Application
 * Using to trigger the application of the external offset correction value
 * defined in the Protocol Configuration
 *
 */
typedef enum
{
    FLEXRAY_EXT_CLK_NOT_APPLY = 0U,         /*!< do not apply external rate correction value */
    FLEXRAY_EXT_CLK_SUBTRACT  = 2U,         /*!< subtract external correction value */
    FLEXRAY_EXT_CLK_ADD       = 3U          /*!< add external correction value */
} Flexray_Ip_ExtClkCorrectType;

/*!
 * @brief Global interrupt flags
 *
 */
typedef enum
{
    FLEXRAY_MODULE_INTERRUPT   = FLEXRAY_GIFER_MIF_MASK,         /*!< set if at least one of the other interrupt flags is set */
    FLEXRAY_PROTOCOL_INTERRUPT = FLEXRAY_GIFER_PRIF_MASK,        /*!< set if at least one of the individual flags in the Protocol Interrupt Flags is set */
    FLEXRAY_CHI_INTERRUPT      = FLEXRAY_GIFER_CHIF_MASK,        /*!< set if at least one of the error flags in the CHI Error Flag Register is set  */
    FLEXRAY_WAKEUP_INTERRUPT   = FLEXRAY_GIFER_WUPIF_MASK,       /*!< set when the CC has received a wakeup symbol on the FlexRay bus */
    FLEXRAY_FIFOA_INTERRUPT    = FLEXRAY_GIFER_FAFAIF_MASK,      /*!< set if FIFO A almost full event has occurred */
    FLEXRAY_FIFOB_INTERRUPT    = FLEXRAY_GIFER_FAFBIF_MASK       /*!< set if FIFO B almost full event has occurred */
} Flexray_Ip_GlobalIntType;

/*!
 * @brief Flexray Wakeup Status
 *
 */
typedef enum
{
    FLEXRAY_UNDEFINED         = 0U,           /*!< undefined status */
    FLEXRAY_RECEIVED_HEADER   = 1U,           /*!< received header status */
    FLEXRAY_RECEIVED_WUP      = 2U,           /*!< received wakeup status */
    FLEXRAY_COLLISION_HEADER  = 3U,           /*!< collision header status */
    FLEXRAY_COLLISION_WUP     = 4U,           /*!< wakeup collision status */
    FLEXRAY_COLLISION_UNKNOWN = 5U,           /*!< unknown collision status */
    FLEXRAY_TRANSMITTED_WUP   = 6U            /*!< transmitted wakeup status */
} Flexray_Ip_WakeupStatusType;

/*!
 * @brief Flexray Startup Status, pegged to the AutoSAR enum, but uses SDK element names
 *
 */

typedef enum
{
    FLEXRAY_STARTUP_UNDEFINED         = 0U,      /* Unknown state - controller has not been in the
                                            POC:Startup state since POC:Default Config
                                            state.*/
    FLEXRAY_COLDSTART_LISTEN          = 1U,      /* Controller listens before it initiates CAS
                                            transmission.*/
    FLEXRAY_INTE_COLDSTART_CHECK      = 2U,      /* Node is synchronizing to leading coldstarter.*/
    FLEXRAY_COLDSTART_JOIN            = 3U,      /* Controller has joined the leading coldstarter
                                            in transmission of startup frames.*/
    FLEXRAY_COLDSTART_COLLISION       = 4U,      /* Leading coldstarter transmits startup frames.*/
    FLEXRAY_COLDSTART_CONS_CHECK      = 5U,      /* Leading coldstarter checks if another node
                                            transmits startup frames.*/
    FLEXRAY_INTE_LISTEN               = 6U,      /* Integrating node (non-coldstarter) listens.*/
    FLEXRAY_INIT_SCHEDULE             = 7U,      /* Schedule is being initialized.*/
    FLEXRAY_INTE_CHECK                = 8U,      /* Controller looks for 4 pairs of startup frames
                                            to integrate into cluster.*/
    FLEXRAY_COLDSTART_GAP             = 9U,      /* Pause between two attempts of coldstart.*/
    FLEXRAY_STARTUP_EXTERNAL_STARTUP  =10U

} Flexray_Ip_StartupStatusType;

/*!
 * @brief Protocol Interrupt Flags
 *
 * This is shift bit value for each protocol interrupt flag when
 * merging two registers: PIFR0 and PIFR1
 *
 */
typedef enum
{
    FLEXRAY_CYCLE_START                         = 0U,        /*!< set when a communication cycle starts */
    FLEXRAY_T1_EXPIRED                          = 1U,        /*!< set whenever timer 1 expires */
    FLEXRAY_T2_EXPIRED                          = 2U,        /*!< set whenever timer 2 expires */
    FLEXRAY_TX_ACROSS_BOUNDARY_A                = 3U,        /*!< set when the frame transmission on channel A crosses the slot boundary */
    FLEXRAY_TX_ACROSS_BOUNDARY_B                = 4U,        /*!< set when the frame transmission on channel B crosses the slot boundary */
    FLEXRAY_PLATESTTX_VIO_A                     = 5U,        /*!< set when the frame transmission on channel A
                                                                 in the dynamic segment exceeds the dynamic segment boundary.*/
    FLEXRAY_PLATESTTX_VIO_B                     = 6U,        /*!< set when the frame transmission on channel B
                                                                in the dynamic segment exceeds the dynamic segment boundary */
    FLEXRAY_MEDIA_ACCESS_TEST_SYMBOL_RECEIVED   = 7U,        /*!< set when the MTS symbol was received on channel A or channel B */
    FLEXRAY_MAX_SYNC_FRAMES                     = 8U,        /*!< set when more than node_sync_max sync frames detected*/
    FLEXRAY_CLOCK_CORRECTION_LIMIT              = 9U,        /*!< set when offset or rate correction limit reached */
    FLEXRAY_MISSING_OFFSET_CORRECTION           = 10U,       /*!< set when an insufficient number of measurements
                                                                is available for offset correction. */
    FLEXRAY_MISSING_RATE_CORRECTION             = 11U,       /*!< set when an insufficient number of measurements
                                                                is available for rate correction at the end of the communication cycle.*/
    FLEXRAY_COLD_START_ABORT                    = 12U,       /*!< set when the configured number of allowed cold start attempts
                                                                is reached and none of these attempts was successful */
    FLEXRAY_ILLEGAL_PROTOCOL_CONFIGURATION      = 13U,       /*!< set when the protocol engine has detected an illegal protocol configuration parameter setting */
    FLEXRAY_INTERNAL_PROTOCOL_ERR               = 14U,       /*!< set when the protocol engine has detected an internal protocol error */
    FLEXRAY_FATAL_PROTOCOL_ERR                  = 15U,       /*!< set when the protocol engine has detected a fatal protocol error */
    FLEXRAY_ODD_CYCLE_TABLE                     = 20U,       /*!< set if the CC has written the sync frame measurement / ID tables into the FlexRay memory area for the odd cycle.*/
    FLEXRAY_EVEN_CYCLE_TABLE                    = 21U,       /*!< set if the CC has written the sync frame measurement / ID tables into the FlexRay memory area for the even cycle.*/
    FLEXRAY_SSC0_INC                            = 24U,       /*!< set when the SLOTSTATUSCNT field in the corresponding Slot Status Counter Registers is incremented */
    FLEXRAY_SSC1_INC                            = 25U,       /*!< set when the SLOTSTATUSCNT field in the corresponding Slot Status Counter Registers is incremented */
    FLEXRAY_SSC2_INC                            = 26U,       /*!< set when the SLOTSTATUSCNT field in the corresponding Slot Status Counter Registers is incremented */
    FLEXRAY_SSC3_INC                            = 27U,       /*!< set when the SLOTSTATUSCNT field in the corresponding Slot Status Counter Registers is incremented */
    FLEXRAY_PROTOCOL_STATE_CHANGED              = 28U,       /*!< set when protocol state changed */
    FLEXRAY_PE_COMM_FAILURE                     = 29U,       /*!< set if the CC has detected a communication failure between the PE and the CHI. */
    FLEXRAY_ILLEGAL_CTRL_CMD                    = 30U,       /*!< set when illegal protocol control command detected */
    FLEXRAY_ERROR_MODE_CHANGED                  = 31U        /*!< set when ERRMODE field changed */
} Flexray_Ip_ProtocolIntType;

/*!
 * @brief CHI Error Flags
 *
 */
typedef enum
{
    FLEXRAY_FRAME_LOST_B        = FLEXRAY_CHIERFR_FRLB_EF_MASK,           /*!< set if frame lost on channel B detected */
    FLEXRAY_FRAME_LOST_A        = FLEXRAY_CHIERFR_FRLA_EF_MASK,           /*!< set if frame lost on channel A detected */
    FLEXRAY_CMD_IGNORED         = FLEXRAY_CHIERFR_PCMI_EF_MASK,           /*!< set if POC command ignored */
    FLEXRAY_FIFO_OVERRUN_B      = FLEXRAY_CHIERFR_FOVB_EF_MASK,           /*!< set if FIFO overrun on channel B has been detected */
    FLEXRAY_FIFO_OVERRUN_A      = FLEXRAY_CHIERFR_FOVA_EF_MASK,           /*!< set if FIFO overrun on channel A has been detected */
    FLEXRAY_MB_SEARCH_ERR       = FLEXRAY_CHIERFR_MBS_EF_MASK,            /*!< set if search engine active while search start appears or illegal message buffer index detected */
    FLEXRAY_MB_UTILIZE_ERR      = FLEXRAY_CHIERFR_MBU_EF_MASK,            /*!< asserted if the application writes to a message buffer control field that is beyond the number of utilized message buffers
                                                                     programmed in the Message Buffer Segment Size and Utilization Register */
    FLEXRAY_MB_LOCK_ERR         = FLEXRAY_CHIERFR_LCK_EF_MASK,            /*!< set if lock error detected */
    FLEXRAY_SYS_BUS_ERR         = FLEXRAY_CHIERFR_SBCF_EF_MASK,           /*!< set if system bus access not finished in time */
    FLEXRAY_FRAME_ID_ERR        = FLEXRAY_CHIERFR_FID_EF_MASK,            /*!< set if frame id error occurred */
    FLEXRAY_DYNAMIC_PAY_LEN_ERR = FLEXRAY_CHIERFR_DPL_EF_MASK,            /*!< set if dynamic payload length error occurred */
    FLEXRAY_STATIC_PAY_LEN_ERR  = FLEXRAY_CHIERFR_SPL_EF_MASK,            /*!< set if static payload length error occurred */
    FLEXRAY_NMV_LEN_ERR         = FLEXRAY_CHIERFR_NML_EF_MASK,            /*!< set if network management length error occurred */
    FLEXRAY_NM_FRAME_ERR        = FLEXRAY_CHIERFR_NMF_EF_MASK,            /*!< set if network management frame error occurred*/
    FLEXRAY_ILL_SYS_BUS_ADDR    = FLEXRAY_CHIERFR_ILSA_EF_MASK            /*!< set if the external system bus subsystem has detected an access
                                                                          to an illegal system bus address from the CC*/
} Flexray_Ip_ChiIntType;


/*!
 * @brief Choose wakeup for channel
 *
 */
typedef enum
{
    FLEXRAY_WUP_NO_WAKEUP = 0U,                                            /*!< No wake up both channel A & B*/
    FLEXRAY_WUP_A         = FLEXRAY_PSR3_WUA_MASK,                         /*!< Wake up signal on channel A */
    FLEXRAY_WUP_B         = FLEXRAY_PSR3_WUB_MASK,                         /*!< Wake up signal on channel B */
    FLEXRAY_WUP_AB        = FLEXRAY_PSR3_WUA_MASK | FLEXRAY_PSR3_WUB_MASK  /*!< Wake up signal on channel A & B*/
}Flexray_Ip_WakeUpChannelType;

/*!
 * @brief Layout for memory message buffer
 *
 */
typedef enum
{
    FLEXRAY_MEM_LAYOUT_MIXED     = 0U,  /*!< FIFO Base Address located in System Memory Base Address */
    FLEXRAY_MEM_LAYOUT_DEDICATED = 1U   /*!< FIFO Base Address located in Receive FIFO System Memory Base Address */
} Flexray_Ip_MemLayoutType;

/*!
 * @brief Enum for range filter type
 *
 */
typedef enum
{
    FR_ACCEPTANCE = 0U,  /*!< Fifo range filter accept mode */
    FR_REJECTION = 1U  /*!< Fifo range filter reject mode */
}Flexray_Ip_RangeFilterModeType;

/*!
 * @brief Enum for counter increment type
 *
 *
 */
typedef enum
{
    FLEXRAY_COUNTER_INC_BY_1_A,         /*!< increment by 1 if condition is fulfilled on channel A */
    FLEXRAY_COUNTER_INC_BY_1_B,         /*!< increment by 1 if condition is fulfilled on channel B */
    FLEXRAY_COUNTER_INC_BY_1_AB,        /*!< increment by 1 if condition is fulfilled on at least one channel. */
    FLEXRAY_COUNTER_INC_BY_1_2          /*!< increment by 2 if condition is fulfilled on both channels channel;
                                             increment by 1 if condition is fulfilled on only one channel. */
} Flexray_Ip_CounterIncType;

/*!
 * @brief Enum for choose timer
 *
 */
typedef enum
{
    FLEXRAY_TIMER1,
    FLEXRAY_TIMER2
} Flexray_Ip_TimerType;

/*!
 * @brief FlexRay Bus Bit Rate
 *
 */
typedef enum
{
    FLEXRAY_BITRATE_10  = 0U,       /*!< 10 Mbit/s */
    FLEXRAY_BITRATE_5   = 1U,       /*!< 5 Mbit/s */
    FLEXRAY_BITRATE_2_5 = 2U,       /*!< 2.5 Mbit/s */
    FLEXRAY_BITRATE_8   = 3U        /*!< 8.0 Mbit/s */
} Flexray_Ip_BitRateType;

/*!
 * @brief FlexRay software states.
 *
 */
typedef enum
{
    FLEXRAY_STATE_UNINIT = 0U,      /*!< Flexray un-init */
    FLEXRAY_STATE_INIT   = 1U       /*!< Flexray init */
} Flexray_Ip_SoftwareStatesType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#ifdef CPU_TYPE
    #if (CPU_TYPE == CPU_TYPE_64)
    /**
    * @brief size of pointer type. on CPU_TYPE_64, the size is 64bits.
    */
    typedef uint64 pointerSizeType;
    #elif (CPU_TYPE == CPU_TYPE_32)
    /**
    * @brief size of pointer type. on CPU_TYPE_32, the size is 32bits.
    */
    typedef uint32 pointerSizeType;
    #elif (CPU_TYPE == CPU_TYPE_16)
    /**
    * @brief size of pointer type. on CPU_TYPE_16, the size is 16bits.
    */
    typedef uint16 pointerSizeType;
    #endif
#endif



/*! @brief User irq
 *
 *  The individual tx, rx interrupts will be managed by driver. The other interrupt will be managed by user,
 *  user will use provided set/get/clear function for these interrupt.
 */

/*!
 * @brief Callback for wakeup ,receive FIFO Channel A Almost Full
 * receive FIFO Channel B Almost Full interrupt
 *
 * param[in] callbackParam    callback parameters for user
 *
 */
typedef void (*Flexray_Ip_CallbackType)(void *callbackParam);

/*!
 * @brief Callback for protocol interrupt
 *
 * param[in] prIntFlagValue   Used for get all protocol interrupt flags.
 * param[in] callbackParam    callback parameters for user
 *
 */
typedef void (*Flexray_Ip_PrCallbackType)(uint32 prIntFlagValue, void *callbackParam);

/*!
 * @brief Callback for CHI error interrupt
 *
 * param[in] chiErrorValue   Used for get all chi error flags.
 * param[in] callbackParam    callback parameters for user
 *
 */
typedef void (*Flexray_Ip_ChiCallbackType)(uint16 chiErrorValue, void *callbackParam);

/*!
 * @brief Callback for rx/tx message buffer interrupt
 *
 * param[in] bufferid  Used for process  each message buffer.
 * param[in] callbackParam    callback parameters for user
 *
 */
typedef void (*Flexray_Ip_IndCallbackType)(uint8 bufferId, void *callbackParam);

/*!
 * @brief User callback function
 *
 */
typedef struct
{
    Flexray_Ip_PrCallbackType protocolCallback;    /*!< Callback when protocol interrupt occurs */
    void * prCallbackParam;                    /*!< Parameter passed to the protocol callback */
    Flexray_Ip_ChiCallbackType chiCallback;        /*!< Callback when chi error interrupt occurs */
    void * chiCallbackParam;                   /*!< Parameter passed to the chi callback */
    Flexray_Ip_CallbackType wakeupCallback;         /*!< Callback when wakeup interrupt occurs */
    void * wakeupCallbackParam;                /*!< Parameter passed to the chi callback */
    Flexray_Ip_CallbackType fifoACallback;          /*!< Callback when receive FIFO Channel A Almost Full interrupt occurs */
    void * fifoACallbackParam;                 /*!< Parameter passed to the FIFO A callback */
    Flexray_Ip_CallbackType fifoBCallback;          /*!< Callback when receive FIFO Channel B Almost Full interrupt occurs */
    void * fifoBCallbackParam;                 /*!< Parameter passed to the FIFO B callback */
    Flexray_Ip_IndCallbackType rxMBCallback;       /*!< Callback when receive message buffer interrupt occurs */
    void * rxCallbackParam;                    /*!< Parameter passed to the RX callback */
    Flexray_Ip_IndCallbackType txMBCallback;       /*!< Callback when transmit message buffer interrupt occurs */
    void * txCallbackParam;                    /*!< Parameter passed to the TX callback */
} Flexray_Ip_UserCallbackType;

/*!
 * @brief Structure to configure Segment 1, 2 size.
 *
 *
 */
typedef struct
{
    uint8 S1DataSize;                 /* Size of message buffer data section for message buffers within segment 1, in 2-byte unit */
    uint8 S2DataSize;                 /* Size of message buffer data section for message buffers within segment 2, in 2-byte unit*/
    uint8 S1Size;                     /* Number of buffers in segment 1 */
    uint8 S2Size;                     /* number of buffers in segment 2 */
    uint8 TotalBuffers;               /* Total buffers*/
} Flexray_Ip_IndMemConfigType;

/*!
 * @brief Structure for all field of header
 *
 */
typedef struct
{
    boolean reservedBit;
    boolean payloadPreambleIndicator;
    boolean nullFrameIndicator;
    boolean syncFrameIndicator;
    boolean startupFrameIndicator;
    uint16 frameID;
    uint8 cycleCount;
    uint8 payloadLength;
    uint16 headerCrc;
    uint16 slotStatus;
} Flexray_Ip_FrameHeaderType;

/*!
 * @brief Structure to configure header frame, function and position of message buffer,
 *
 */
typedef struct
{
    uint8 MBIndex;           /*!< Message buffer index (index of registers such as FR_MBCCSRn, FR_MBCCFRn ...) */
    uint16 phyMBIndex;        /*!< Physical message buffer index */
    boolean firstInit;        /*!< Buffer should be used for the initialization */
    uint16 frameID;           /*!< Slot ID in which frame is transmitted/received */
    uint16 headerCrc;
    boolean PPI;
    uint8 payloadLength;      /*!< Length in 2-byte unit, only for dynamic slot transmission */
    boolean isTx;                  /*!< True: Tx buffer, false: Rx buffer */
    boolean channelA;              /*!< True: enable transfer on channel A, false otherwise */
    boolean channelB;              /*!< True: enable transfer on channel B, false otherwise.
                                    Note that different combinations of channelA and channelB fields shall have
                                    different effects. Please see Channel Assignment Description table in RM for details */
    boolean ccFilter;              /*!< True: enable cycle count filter, false otherwise */
    uint8 ccFilterVal;        /*!< Cycle count filter value */
    uint8 ccFilterMask;       /*!< Cycle count mask. This value is ANDed with current cycle count and compare with ccFilterVal */
    boolean repeatTx;              /*!< Only used if this is a tx individual buffer.
                                    True: buffer is transmited again automatically.
                                    False: buffer is trasmitted only once. */
    boolean allowVariableLength;     /* used by MCAL, default false?*/
    boolean enable;                /*!< True: Enable this message buffer. False: Disable this message buffer */

    Flexray_Ip_FrameHeaderType frameHdr;

} Flexray_Ip_IndConfigType;

/*!
 * @brief Structure to configure shadow buffer (physical message buffer index and position)
 *
 */
typedef struct
{
    uint8 phyMBIndex;       /*!< Physical message buffer index */
    boolean channelA;            /*!< True: receive shadow buffer for channel A. False: receive shadow buffer for channel B */
    boolean segment1;            /*!< True: receive shadow buffer for segment 1. False: receive shadow buffer for segment 2.
                                   Note that each combination of channel and segment can be assigned only one shadow buffer */
} Flexray_Ip_ShadowConfigType;

/*!
 * @brief Structure for configure range filter.
 *
 *
 */
typedef struct
{
    boolean rangeFilterEnable;                      /*!< Range filter enable. True: Enable. False: Disable */
    Flexray_Ip_RangeFilterModeType rangeFilterMode; /*!< Range filter mode */
    uint16 rangeFilterLower;                   /*!< Frame ID lower value for range filter */
    uint16 rangeFilterUpper;                   /*!< Frame ID upper value for range filter */

}Flexray_Ip_RangeFilterType;

/*!
 * @brief Structure for configure rx FIFO (size, filter and watermark)
 *
 *
 */
typedef struct
{
    Flexray_Ip_FifoChannelType FifoChannel;         /* Selects the receive FIFO (FIFO A, FIFO B). */
    uint8 startIndex;                       /*!< Physical message buffer index of the first message buffer in fifo */
    uint8 fifoDepth;                        /*!< Number of entries in fifo. Zero value shall disable fifo */
    uint8 entrySize;                       /*!< Size of frame data section. Must be an even number */
    uint16 fidRejMask;                      /*!< FRAME ID rejection Filter Mask. This is ANDed with FRAME ID and compare with fidRejVal */
    uint16 fidRejVal;                       /*!< FRAME ID rejection Filter Mask */
    uint16 midAccMask;                      /*!< MESSAGE ID Acceptance Filter Mask. This is ANDed with MESSAGE ID and compare with fidAccVal */
    uint16 midAccVal;                       /*!< MESSAGE ID Acceptance Filter Value */
    Flexray_Ip_RangeFilterType rangeFilter[4];      /*!< Frame ID range Filter. Maximum number of range filter is 4 */
    uint8 watermark;                        /*!< Wartermark value to used with channel A Almost Full Interrupt */
} Flexray_Ip_FifoConfigType;

/*!
 * @brief Structure for configure counter
 *
 */
typedef struct
{
    Flexray_Ip_CounterIncType counterInc;     /*!< Counter increment type */
    boolean multiCycle;                      /*!< True: count on all cycle. False: count on previous cycle only */
    boolean validFrameOnly;                  /*!< True: count valid frame only. False otherwise */
    boolean syncFrameOnly;                   /*!< True: count sync frame only. False otherwise */
    boolean nullFrameOnly;                   /*!< True: count valid frame only. False otherwise */
    boolean startupFrameOnly;                /*!< True: count startup frame only. False otherwise */
    boolean syntaxErr;                       /*!< True: count slots with the syntax error indicator bit set to 1. False otherwise */
    boolean contentErr;                      /*!< True: count slots with the content error indicator bit set to 1. False otherwise */
    boolean boundaryViolate;                 /*!< True: count slots with the boundary violation indicator bit set to 1. False otherwise */
    boolean transmitConflict;                /*!< True: count slots with the transmission conflict indicator bit set to 1. False otherwise */
} Flexray_Ip_CounterConfigType;

/*!
 * @brief Structure for configure communication controller.
 *
 *
 */
typedef struct
{
    boolean freezeMode;                 /*!< Transition to freeze mode or not(1/0) when system bus fail happen */
    boolean singleChnlMode;             /*!< Single Channel Device mode or not(true/false)
                                             True:   single channel device mode
                                             False:  dual channel device mode*/
    boolean channelA;                   /*!< True: use channel A/False: not use channel A */
    boolean channelB;                   /*!< True: use channel B/False: not use channel A */
    boolean syncFrameFilter;            /*!< Synchronization frame filtering(true/false)
                                             True:   Synchronization frame filtering enabled
                                             False:  Synchronization frame filtering disabled*/
    Flexray_Ip_BitRateType bitRate;     /*!< This field defines the FlexRay Bus Bit Rate */
    Flexray_Ip_MemLayoutType memLayout; /*!< Controls the location of the system memory base address for the FIFOs */
    uint8 timeout;                      /*!< System memory access timeout */
    uint8* pSysMem;                     /*!< Pointer to system memory area
                                             User located memory for flexray module to use. The size of this memory block is calculated by:
                                             (number of S1 buffers + number of S2 buffers + number of shadow buffer + fifo depth) * 8 +
                                             (number of S1 buffers + number of S1 shadow buffer) * S1 buffer size +
                                             (number of S2 buffers + number of S2 shadow buffer) * S2 buffer size)*/
    uint8* pFiFoSysMem;                 /*!< Only used if memLayout is FLEXRAY_MEM_LAYOUT_DEDICATED and pointer to fifo system memory area */
} Flexray_Ip_CcConfigType;

/*!
 * @brief Flexray protocol engine configuration
 * The structure is used as input parameters to configure all information of protocol engine.
 * Parameters with prefix "g" must have same value in all nodes of a cluster.
 * Parameters with prefix "p" may have different values in different nodes of a cluster.
 *
 */
typedef struct
{
    uint8 gColdstartAttempts;             /*!< Number of coldstart node in network (Range: 2->31) */
    uint8 gdActionPointOffset;            /*!< Number of macroticks the action point is offset from the beginning of a static slot
                                                 or symbol window; value into range: 1-63MT. */
    uint8 gdCASRxLowMax;                  /*!< Upper limit of the CAS acceptance window; value into range: 67-99 gdBit */
    uint8 gdDynamicSlotIdlePhase;         /*!< Duration of the idle phase within a dynamic slot. from 0 to 2 */
    uint8 gdMinislot;
    uint8 gdMinislotActionPointOffset;    /*!< Number of macroticks the minislot action point is offset from the beginning of a minislot
                                                value into range: 1-31MT */
    uint16 gdStaticSlot;                  /*!< Duration of a static slot (4->661 MT) */
    boolean gSymbolWindowExists;               /*!< Enable/Disable symbol window */
    uint8 gdSymbolWindow;
    uint8 gdTSSTransmitter;               /*!< number of bits in the Transmission Start Sequence(3-15gdBit) */
    uint8 gdWakeupSymbolRxIdle;           /*!< Number of bits used by the node to test the duration of
                                                 the 'idle' portion of a received wakeup symbol (14-59gdBit) */
    uint8 gdWakeupSymbolRxLow;            /*!< Number of bits used by the node to test
                                                 the LOW portion of a received wakeup symbol (11-59gdBit) */
    uint16 gdWakeupSymbolRxWindow;        /*!< The size of the window used to detect wakeup (76-301 gdBit) */
    uint8 gdWakeupSymbolTxIdle;           /*!< Number of bits used by the node to transmit the 'idle' part of a wakeup symbol (45-180 gdBit) */
    uint8 gdWakeupSymbolTxLow;              /*!< Number of bits used by the node to transmit the LOW part of a wakeup symbol (15-60 gdBit) */
    uint32 gListenNoise;
    uint16 gMacroPerCycle;                /*!< Number of macroticks in a communication cycle (10 - 16000MT) */
    uint8 gMaxWithoutClockCorrectionFatal;
    uint8 gMaxWithoutClockCorrectionPassive;
    boolean gMiniSlotExists;                    /*!< disable/enable minislot */
    uint16 gNumberOfMinislots;
    uint16 gNumberOfStaticSlots;
    uint16 gOffsetCorrectionStart;        /*!< Start of the offset correction phase within the NIT,
                                                 expressed as the number of macroticks from the start of cycle (9 - 15999 MT)
                                                 Note that this value should greater than
                                                 gdStaticSlot* gNumberOfStaticSlots + gdMinislot*gNumberOfMinislots + gdSymbolWindow */
    uint8 gPayloadLengthStatic;           /*!< Payload length of a static frame */
    uint8 gSyncNodeMax;                   /*!< Maximum number of nodes that may send frames with the sync frame indicator bit set to one. */
    uint32 pdListenTimeout;               /*!< Value for the startup listen timeout and wakeup listen timeout */
    uint8 pMacroInitialOffsetA;           /*!< 2-68MT */
    uint8 pMacroInitialOffsetB;           /*!< 2-68MT */
    uint8 pPayloadLengthDynMax;           /*!< Maximum payload length for dynamic frames */
    boolean pAllowHaltDueToClock;
    uint8 pAllowPassiveToActive;          /*!< If set to zero, the CC is not allowed to transition from normal passive to normal active */
    uint8 pClusterDriftDamping;            /*!< Local cluster drift damping factor used for rate correction (0-20uT) */
    uint16 pdAcceptedStartupRange;
    uint16 pDelayCompensationA;
    uint16 pDelayCompensationB;
    uint16 pKeySlotId;                    /*!< ID of the slot used to transmit the startup frame, sync frame, or designated single slot frame */
    boolean pKeySlotUsedForStartup;            /*!< key slot is startup frame or not ? */
    boolean pKeySlotUsedForSync;               /*!< key slot is sync frame or not ? */
    uint16 pLatestTx;                     /*!< Number of the last minislot in which a frame transmission can start in the dynamic segment */
    uint8 pMicroInitialOffsetA;
    uint8 pMicroInitialOffsetB;
    uint32 pMicroPerCycle;                /*!< Nominal number of microticks in the communication cycle of the local node (640-640000 uT) */
    uint32 pdMaxDrift;
    uint8 pMicroPerMacroNom;
    uint16 pRateCorrectionOut;            /*!< Magnitude of the maximum permissible rate correction value (2-1923 uT) */
    uint16 pOffsetCorrectionOut;          /*!< Magnitude of the maximum permissible offset correction value (13-15567 uT) */
    boolean pSingleSlotEnabled;                /*!< Flag indicating whether or not the node shall enter single slot mode following startup */
    boolean pWakeupChannel;                    /*!< Channel used by the node to send a wakeup pattern: false -> A, true -> B */
    uint8 pWakeupPattern;                 /*!< Number of repetitions of the wakeup symbol that are combined to form a wakeup pattern when the node
                                                 enters the POC:wakeup send state */
    uint16 pDecodingCorrection;
    uint16 keySlotHeaderCrc;              /*!< header CRC for key slot (0x00-0x7FF) */
    uint8 pExternOffsetCorrection;        /*!< Number of microticks added or subtracted to the NIT to carry out a host-requested external offset correction (0-7uT) */
    uint8 pExternRateCorrection;          /*!< Number of microticks added or subtracted to the cycle to carry out a host-requested external rate correction (0-7uT) */
    uint8 gNetworkManagementVectorLength; /*!< The length of the NMVector in byte */
    uint16 SyncFrameTableOffset;
} Flexray_Ip_PeConfigType;

/*! @brief Structure for internal use.
 *  This structure is used by the driver for its internal logic.
 *  It must be provided by the application through the initialize functions,
 *  then it cannot be freed until the driver is de-initialized using Deinit functions.
 *  The application should make no assumptions about the content of this structure.
 *
 */
typedef struct
{
    uint8 bufferId;
    uint8 mbId;
    Flexray_Ip_StatusType status;
    Flexray_Ip_FrameHeaderType* frameHdr;
    uint8* pData;
    uint8 dataLength;
    boolean PPI;
    boolean allowDynamicLength;
    boolean slotStatusError;
    boolean blocking;
} Flexray_Ip_BufferStateType;

/*!
 * @brief Structure for state of each instance.
 *
 *
 */
typedef struct
{
    Flexray_Ip_BufferStateType** mbStateMap;
    Flexray_Ip_BufferStateType* bufferState;
    Flexray_Ip_IndConfigType* indConfig;
    Flexray_Ip_UserCallbackType callback;
    uint8 numberOfMbUsed;
    uint8 numberOfBuffer;
    uint8 numShadowBuffer;
    uint32 sysMemSize;
    uint32 fifoSysMemSize;
} Flexray_Ip_StateType;

/*!
 * @brief Structure for filter cycle counter on Media access test symbol
 *
 */
typedef struct
{
    uint8 cycCountValue;      /* cycle counter value */
    uint8 cycCountMask;       /* cycle counter mask */
} Flexray_Ip_MtsFilterType;

/*!
 * @brief Structure for flexray user configuration
 *
 */
typedef struct
{
    Flexray_Ip_PeConfigType* peConfig;
    Flexray_Ip_CcConfigType* ccConfig;
    Flexray_Ip_UserCallbackType* cbConfig;
    Flexray_Ip_IndConfigType* indBufConfig;
    Flexray_Ip_ShadowConfigType* shadowConfig;
    uint8 numShadowConfig;                   /* Number of shadow buffer. Shadow buffer is needed if receiving individual buffers are present. */
    Flexray_Ip_IndMemConfigType* indMemConfig;
    Flexray_Ip_FifoConfigType* fifoConfigA;
    Flexray_Ip_FifoConfigType* fifoConfigB;
    uint16 fifoTimerDuration;                /*!< Timer duration in macroticks. See FIFO Periodic Timer section for details */
    boolean timer2IsRelative;                     /*!< True: TIMER2 is relative. False: TIMER2 is absolute */
    Flexray_Ip_MtsFilterType* mtsfilterChnA;       /*!< MTS cycle filter for Channel A */
    Flexray_Ip_MtsFilterType* mtsfilterChnB;       /*!< MTS cycle filter for Channel B */
} Flexray_Ip_ConfigType;

/*!
 * @brief Structure for allocate state
 * User needs to declare a variable with Flexray_Ip_StateAllocateType type
 * for initialize and assigned state.
 *
 */
typedef struct
{
    Flexray_Ip_StateType* state;
    Flexray_Ip_BufferStateType* bufferState;
    Flexray_Ip_BufferStateType** mbStateMap;
} Flexray_Ip_StateAllocateType;

/*!
 * @brief Structure for configure timer.
 *
 */
typedef struct
{
    Flexray_Ip_TimerType timer;    /* select timer number */
    uint8 cycVal;                 /* cycle value for timer */
    uint8 cycMask;                /* cycle mask for timer */
    uint32 macroTick;             /* for absolute timer this value defined offset of macro tick,
                                     * for relative timer this value define a countdown value of macro tick */
    boolean isRepetitive;
} Flexray_Ip_TimerConfigType;

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXRAY_IP_Types_H */

/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : ADC_SAR
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

#ifndef CTU_IP_TYPES_H
#define CTU_IP_TYPES_H

/**
*   @file
*
*   @addtogroup ctu_ip
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "Ctu_Ip_CfgDefines.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CTU_IP_VENDOR_ID_TYPES                      43
#define CTU_IP_AR_RELEASE_MAJOR_VERSION_TYPES       4
#define CTU_IP_AR_RELEASE_MINOR_VERSION_TYPES       4
#define CTU_IP_AR_RELEASE_REVISION_VERSION_TYPES    0
#define CTU_IP_SW_MAJOR_VERSION_TYPES               4
#define CTU_IP_SW_MINOR_VERSION_TYPES               0
#define CTU_IP_SW_PATCH_VERSION_TYPES               2
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Ctu_Ip_Types.h file and StandardTypes.h file are of the same Autosar version */
#if ((CTU_IP_AR_RELEASE_MAJOR_VERSION_TYPES != STD_AR_RELEASE_MAJOR_VERSION) || \
     (CTU_IP_AR_RELEASE_MINOR_VERSION_TYPES != STD_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Ctu_Ip_Types.h and StandardTypes.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if Ctu_Ip_Types.h file and Ctu_Ip_CfgDefines.h file are of the same vendor */
#if (CTU_IP_VENDOR_ID_TYPES != CTU_IP_VENDOR_ID_CFGDEFINES)
    #error "Ctu_Ip_Types.h and Ctu_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if Ctu_Ip_Types.h file and Ctu_Ip_CfgDefines.h file are of the same Autosar version */
#if ((CTU_IP_AR_RELEASE_MAJOR_VERSION_TYPES != CTU_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (CTU_IP_AR_RELEASE_MINOR_VERSION_TYPES != CTU_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (CTU_IP_AR_RELEASE_REVISION_VERSION_TYPES != CTU_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of Ctu_Ip_Types.h and Ctu_Ip_CfgDefines.h are different"
#endif

/* Check if Ctu_Ip_Types.h file and Ctu_Ip_CfgDefines.h file are of the same Software version */
#if ((CTU_IP_SW_MAJOR_VERSION_TYPES != CTU_IP_SW_MAJOR_VERSION_CFGDEFINES) || \
     (CTU_IP_SW_MINOR_VERSION_TYPES != CTU_IP_SW_MINOR_VERSION_CFGDEFINES) || \
     (CTU_IP_SW_PATCH_VERSION_TYPES != CTU_IP_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of Ctu_Ip_Types.h and Ctu_Ip_CfgDefines.h are different"
#endif

/*==================================================================================================
*                                      DEFINITIONS
==================================================================================================*/

 /*!
 * @brief Defines the CTU status values
 *
 * Implements : Ctu_Ip_StatusTypeType_Class
 */
typedef enum {
    CTU_IP_STATUS_SUCCESS   = 0u,  /*!< Function completed successfully */
    CTU_IP_STATUS_ERROR     = 1u,  /*!< Function didn't complete successfully */
    CTU_IP_STATUS_TIMEOUT   = 2u   /*!< Function timed out */
} Ctu_Ip_StatusType;

/*!
 * @brief Defines the CTU prescaler values
 *
 * Implements : Ctu_Ip_PrescalerType_Class
 */
typedef enum {
    CTU_IP_PRESCALER_1      = 0u,   /*!< CTU clock prescaler value of 1. */
    CTU_IP_PRESCALER_2      = 1u,   /*!< CTU clock prescaler value of 2. */
    CTU_IP_PRESCALER_3      = 2u,   /*!< CTU clock prescaler value of 3. */
    CTU_IP_PRESCALER_4      = 3u    /*!< CTU clock prescaler value of 4. */
} Ctu_Ip_PrescalerType;

/*!
 * @brief Defines the CTU Trigger Generator Subunit (TGS) operating modes
 *
 * Implements : Ctu_Ip_TGSModeType_Class
 */
typedef enum {
    CTU_IP_TGS_MODE_TRIGGERED   = 0u,   /*!< Trigger Generator Subunit (TGS) Triggered Mode. */
    CTU_IP_TGS_MODE_SEQUENTIAL  = 1u    /*!< Trigger Generator Subunit (TGS) Sequential Mode. */
} Ctu_Ip_TGSModeType;

#if FEATURE_CTU_EXT_TRIG_PRESENT
/*!
 * @brief Defines the CTU output external trigger mode
 *
 * Implements : Ctu_Ip_ExtTrigModeType_Class
 */
typedef enum {
    CTU_IP_EXT_TRIG_MODE_PULSE  = 0u,   /*!< Pulse mode for output external trigger */
    CTU_IP_EXT_TRIG_MODE_TOGGLE = 1u    /*!< Toggle mode for output external trigger */
} Ctu_Ip_ExtTrigModeType;
#endif /* FEATURE_CTU_EXT_TRIG_PRESENT */

/*!
 * @brief Defines the CTU ADC command list operating mode
 *
 * Implements : Ctu_Ip_AdcCmdListModeType_Class
 */
typedef enum {
    CTU_IP_ADC_CMD_LIST_MODE_STREAMING = 0u,   /*!< ADC Command List in streaming mode: no more than a list executing at a time. */
    CTU_IP_ADC_CMD_LIST_MODE_PARALLEL  = 1u    /*!< ADC Command List in parallel mode: lists may execute in parallel, if targeting different ADCs.  */
} Ctu_Ip_AdcCmdListModeType;

/*!
 * @brief Defines the CTU signal edges for input selection
 *
 * Implements : Ctu_Ip_InputEdgeType_Class
 */
typedef enum {
    CTU_IP_INPUT_EDGE_RISING           = 0u,   /*!< Input Selection Rising Edge */
    CTU_IP_INPUT_EDGE_FALLING          = 1u,   /*!< Input Selection Falling Edge */
    CTU_IP_INPUT_EDGE_BOTH             = 2u    /*!< Input Selection both rising and falling edges */
} Ctu_Ip_InputEdgeType;

/*!
 * @brief Defines the CTU input triggers
 *
 * This enumeration defines the CTU input triggers. Inputs may be assigned to
 * different trigger sources, depending on each CTU instance. Please refer
 * to device reference manual for actual assignments - chapter regarding TGSISR input assignments.
 *
 * Implements : Ctu_Ip_InputTrigType_Class
 */
typedef enum {
#if (FEATURE_CTU_INPUT_TRIG_PWM_REL)
    CTU_IP_INPUT_TRIG_PWM_REL          = 0u,   /*!< Input trigger PWM Reload */
#endif
#if (FEATURE_CTU_INPUT_TRIG_PWM_ODD_0)
    CTU_IP_INPUT_TRIG_PWM_ODD_0        = 1u,   /*!< Input trigger PWM ODD 0  */
#endif
#if (FEATURE_CTU_INPUT_TRIG_PWM_ODD_1)
    CTU_IP_INPUT_TRIG_PWM_ODD_1        = 2u,   /*!< Input trigger PWM ODD 1  */
#endif
#if (FEATURE_CTU_INPUT_TRIG_PWM_ODD_2)
    CTU_IP_INPUT_TRIG_PWM_ODD_2        = 3u,   /*!< Input trigger PWM ODD 2  */
#endif
#if (FEATURE_CTU_INPUT_TRIG_PWM_ODD_3)
    CTU_IP_INPUT_TRIG_PWM_ODD_3        = 4u,   /*!< Input trigger PWM ODD 3  */
#endif
#if (FEATURE_CTU_INPUT_TRIG_PWM_EVEN_0)
    CTU_IP_INPUT_TRIG_PWM_EVEN_0       = 5u,   /*!< Input trigger PWM EVEN 0 */
#endif
#if (FEATURE_CTU_INPUT_TRIG_PWM_EVEN_1)
    CTU_IP_INPUT_TRIG_PWM_EVEN_1       = 6u,   /*!< Input trigger PWM EVEN 1 */
#endif
#if (FEATURE_CTU_INPUT_TRIG_PWM_EVEN_2)
    CTU_IP_INPUT_TRIG_PWM_EVEN_2       = 7u,   /*!< Input trigger PWM EVEN 2 */
#endif
#if (FEATURE_CTU_INPUT_TRIG_PWM_EVEN_3)
    CTU_IP_INPUT_TRIG_PWM_EVEN_3       = 8u,   /*!< Input trigger PWM EVEN 3 */
#endif
#if (FEATURE_CTU_INPUT_TRIG_RPWM_0)
    CTU_IP_INPUT_TRIG_RPWM_0           = 9u,   /*!< Input trigger RPWM 0     */
#endif
#if (FEATURE_CTU_INPUT_TRIG_RPWM_1)
    CTU_IP_INPUT_TRIG_RPWM_1           = 10u,  /*!< Input trigger RPWM 1     */
#endif
#if (FEATURE_CTU_INPUT_TRIG_RPWM_2)
    CTU_IP_INPUT_TRIG_RPWM_2           = 11u,  /*!< Input trigger RPWM 2     */
#endif
#if (FEATURE_CTU_INPUT_TRIG_RPWM_3)
    CTU_IP_INPUT_TRIG_RPWM_3           = 12u,  /*!< Input trigger RPWM 3     */
#endif
#if (FEATURE_CTU_INPUT_TRIG_ETIMER_IN1)
    CTU_IP_INPUT_TRIG_ETIMER_IN1       = 13u,  /*!< Input trigger 1 for ETIMER - please refer to reference manual for the eTimer instance connected */
#endif
#if (FEATURE_CTU_INPUT_TRIG_ETIMER_IN2)
    CTU_IP_INPUT_TRIG_ETIMER_IN2       = 14u,  /*!< Input trigger 2 for ETIMER - please refer to reference manual for the eTimer instance connected */
#endif
#if (FEATURE_CTU_INPUT_TRIG_EXT_IN)
    CTU_IP_INPUT_TRIG_EXT_IN           = 15u   /*!< Input trigger EXTERNAL   */
#endif
} Ctu_Ip_InputTrigType;

/*!
 * @brief Defines the CTU conversion mode
 *
 * Implements : Ctu_Ip_ConvModeType_Class
 */
typedef enum {
    CTU_IP_CONV_MODE_SINGLE            = 0u,   /*!< Single conversion mode - conversion will run on a single ADC instance */
#if (FEATURE_CTU_NUM_ADC > 1)
    CTU_IP_CONV_MODE_DUAL              = 1u    /*!< Dual conversion mode - conversion will run on two ADC instances simultaneously */
#endif /* (FEATURE_CTU_NUM_ADC > 1) */
} Ctu_Ip_ConvModeType;

/*!
 * @brief Defines the available ADC ports connected to CTU
 *
 * Implements : Ctu_Ip_AdcPortType_Class
 */
typedef enum {
    CTU_IP_ADC_PORT_A                  = 0u,   /*!< ADC instance 0 */
#if (FEATURE_CTU_NUM_ADC > 1)
    CTU_IP_ADC_PORT_B                  = 1u    /*!< ADC instance 1 */
#endif /* (FEATURE_CTU_NUM_ADC > 1) */
} Ctu_Ip_AdcPortType;

/*!
 * @brief Defines the possible data alignment for ADC conversion results
 * available from CTU result FIFOs
 *
 * Implements : Ctu_Ip_DataAlignType_Class
 */
typedef enum
{
    CTU_IP_RESULT_ALIGN_RIGHT_UNSIGNED = 0u,   /*!< FRn: data is unsigned, right aligned */
    CTU_IP_RESULT_ALIGN_LEFT_SIGNED    = 1u    /*!< FLn: data is signed, left aligned - leftmost bit is sign bit. */
} Ctu_Ip_DataAlignType;

/*!
 * @brief Defines the available interrupt request types
 *
 * Implements : Ctu_Ip_InterruptType_Class
 */
typedef enum {
    CTU_IP_IRQ_ERROR   = 0u,   /*!< CTU error interrupt request. */
    CTU_IP_IRQ_TRIG    = 1u,   /*!< CTU trigger interrupt request. */
    CTU_IP_IRQ_FIFO    = 2u,   /*!< CTU FIFO interrupt request. */
} Ctu_Ip_IRQType;


/*!
 * @brief Defines the trigger notification header
 *
 * This header is used in individual trigger notification callbacks
 *
 * Implements : Ctu_Ip_TrgNotificationType_Class
 */
typedef void (*Ctu_Ip_TrgNotificationType)(void);

/*!
 * @brief Structure for configuring trigger generator subunit control.
 *
 * This structure for configuring trigger generator subunit control.
 *
 * Implements : Ctu_Ip_TrigGenSubType_Class
 */
typedef struct {
    Ctu_Ip_TGSModeType     TgsMode;             /*!< Trigger Generator Subunit (TGS) Mode - double-buffered (TGSCR.TGS_M) */
    Ctu_Ip_PrescalerType   Prescaler;           /*!< Input clock prescaler - double-buffered (TGSCR.PRES) */
    Ctu_Ip_InputTrigType   SeqModeMrsInput;     /*!< Select which input to be used for MRS when Sequential Mode is enabled (see tgsMode) - double-buffered (TGSCR.MRS_SM) */
    Ctu_Ip_InputEdgeType   SeqModeMrsInputEdge; /*!< Select which edge of the input signal (only rising or falling is allowed) to be used for MRS when SequenceMode is enabled - double-buffered (TGSCR.MRS_SM) */
#if FEATURE_CTU_EXT_TRIG_PRESENT
    Ctu_Ip_ExtTrigModeType ExtTrigMode;         /*!< Trigger mode for external triggers: eTimers and EXT_TRG - double-buffered (TGSCR.ET_TM) */
#endif /* FEATURE_CTU_EXT_TRIG_PRESENT */
} Ctu_Ip_TrigGenSubType;

/*!
 * @brief Structure for retrieving ADC command list status information.
 *
 * This structure is used for retrieving ADC command list status information.
 *
 * Implements : Ctu_Ip_ListStatusType_Class
 */
typedef struct {
    uint8 ListAddr;           /*!< Command address being executed when EFR.LIST_BE flag was set */
    boolean ListBlocked;       /*!< When set indicates that the address in listAddr had failed to issue an ADC cmd */
} Ctu_Ip_ListStatusType;

/*!
 * @brief Structure for retrieving full result information for a conversion.
 *
 * This structure is used for retrieving full result information for a conversion.
 *
 * Implements : Ctu_Ip_ConvResultType_Class
 */
typedef struct {
    Ctu_Ip_AdcPortType AdcPort;    /*!< ADC instance on which the conversion has executed */
    uint8 AdcChanNum;             /*!< ADC channel number on which the conversion has executed */
    uint16 ConvData;             /*!< ADC conversion data result */
} Ctu_Ip_ConvResultType;

/*!
 * @brief Structure for configuring a conversion command.
 *
 * This structure is used for configuring a conversion command.
 * The structure fields are a reunion of all fields available for the 3 command formats: A, B and C.
 *
 * Implements : Ctu_Ip_AdcCmdConfigType_Class
 */
typedef struct {
    boolean IntEn;                 /*!< Enable interrupt request for command execution */
    uint8 FifoIdx;                /*!< Select result FIFO to store the conversion result */
    Ctu_Ip_ConvModeType ConvMode;  /*!< Select conversion mode - if selfTestEn==false, selects between format A and B */
    Ctu_Ip_AdcPortType AdcPort;    /*!< Select ADC instance to run the conversion - used in format A and C */
    uint8 AdcChanA;               /*!< Select target channel number for ADC instance 0 (ADC port A) */
#if (FEATURE_CTU_NUM_ADC > 1)
    uint8 AdcChanB;               /*!< Select target channel number for ADC instance 1 (ADC port B) - used only in format B */
#endif /* (FEATURE_CTU_NUM_ADC > 1) */
    boolean bLastCmd;
} Ctu_Ip_AdcCmdConfigType;

/*!
 * @brief Structure for configuring a conversion command at runtime.
 *
 * This structure is used for configuring a conversion command at runtime.
 * The structure fields are a reunion of all fields available for the 3 command formats: A, B and C.
 *
 * Implements : Ctu_Ip_AdcCmdType_Class
 */
typedef struct {
    boolean IntEn;                 /*!< Enable interrupt request for command execution */
    uint8 FifoIdx;                /*!< Select result FIFO to store the conversion result */
    Ctu_Ip_ConvModeType ConvMode;  /*!< Select conversion mode - if selfTestEn==false, selects between format A and B */
    Ctu_Ip_AdcPortType AdcPort;    /*!< Select ADC instance to run the conversion - used in format A and C */
    uint8 AdcChanA;               /*!< Select target channel number for ADC instance 0 (ADC port A) */
#if (FEATURE_CTU_NUM_ADC > 1)
    uint8 AdcChanB;               /*!< Select target channel number for ADC instance 1 (ADC port B) - used only in format B */
#endif /* (FEATURE_CTU_NUM_ADC > 1) */
} Ctu_Ip_AdcCmdType;

/*!
 * @brief Structure for configuring an internal trigger (TGS output trigger, input for SU).
 *
 * This structure is used for configuring the properties of an internal trigger (TGS output trigger, input for SU).
 *
 * Implements : Ctu_Ip_TrigConfigType_Class
 */
typedef struct {
    uint8 TrigIndex;
    uint16 CompareVal;               /*!< Compare Value - double-buffered (TnCR) */
    uint8 CmdListStartAdr;            /*!< First address of the command list associated with the internal trigger - (CLCRx) */
    uint8 OutputTrigEnMask;           /*!< Select the CTU output triggers enabled for each SU input trigger. To be used with CTU_IP_OUTPUT_TRIG_ defines. - double-buffered (THCR) */
    Ctu_Ip_TrgNotificationType TrigNotification;
} Ctu_Ip_TrigConfigType;

/*!
 * @brief Structure for configuring a result FIFO.
 *
 * This structure is used for configuring a result FIFO.
 *
 * Implements : Ctu_Ip_FifoConfigType_Class
 */
typedef struct {
    uint8 FifoIndex;
    uint8 FifoThreshold;
    boolean FifoDmaEnable;
    uint32 FifoDmaChannel;
#ifdef CTU_IP_FIFO_DMA_RAW_EN
    uint32 * UserFifoBuffer;
#else
    uint16 * UserFifoBuffer;
#endif
    void (*ThresholdNotification)(void);
    void (*UnderrunNotification)(void);
    void (*OverrunNotification)(void);
    void (*FullNotification)(void);
} Ctu_Ip_FifoConfigType;

/*!
 * @brief Store result FIFO notifications.
 *
 * This structure is used to store notifications for a result FIFO.
 *
 * Implements : Ctu_Ip_FifoNotificationsType_Class
 */
typedef struct {
    void (*ThresholdNotification)(void);
    void (*UnderrunNotification)(void);
    void (*OverrunNotification)(void);
    void (*FullNotification)(void);
} Ctu_Ip_FifoNotificationsType;

/*!
* @brief Structure for configuring global CTU functionalities
*
* This structure is used for configuring global CTU functionalities
*
* Implements : Ctu_Ip_ConfigType_Class
*/
typedef struct {
    Ctu_Ip_TGSModeType TgsMode;                            /*!< Trigger Generator Subunit (TGS) Mode - double-buffered (TGSCR.TGS_M) */
    Ctu_Ip_PrescalerType Prescaler;                        /*!< Input clock prescaler - double-buffered (TGSCR.PRES) */
#if FEATURE_CTU_EXT_TRIG_PRESENT
    Ctu_Ip_ExtTrigModeType ExtTrigMode;                    /*!< Trigger mode for external triggers: eTimers and EXT_TRG - double-buffered (TGSCR.ET_TM). TODO: rename ExtTrigMode */
#endif /* FEATURE_CTU_EXT_TRIG_PRESENT */
    uint32 InputTrigSelectMask;                          /*!< Select input triggers: even/odd bits correspond to rising/falling edge. May be set using CTU_INPUT_TRIG_BITMASK_ macros. - double-buffered (TGSISR) */
    uint16 TgsCounterCompareVal;                         /*!< TGS Counter Compare Value - double-buffered (TGSCCR) */
    uint16 TgsCounterReloadVal;                          /*!< TGS Counter Reload Value - double-buffered (TGSCRR) */
    Ctu_Ip_AdcCmdListModeType AdcCmdListMode;              /*!< Select mode of execution for ADC Command List (LISTCSR.PAR_LIST) */
    Ctu_Ip_InputTrigType SeqModeMrsInput;                  /*!< Select which input to be used for MRS when Sequential Mode is enabled (see tgsMode) - double-buffered (TGSCR.MRS_SM) */
    Ctu_Ip_InputEdgeType SeqModeMrsInputEdge;              /*!< Select which edge of the input signal (only rising or falling is allowed) to be used for MRS when SequenceMode is enabled - double-buffered (TGSCR.MRS_SM) */
    boolean DmaDoneGRE;                                    /*!< Enable setting of General Reload Enable (GRE) when DMA-done occurs. (IR.DMA_DE) */
    boolean DmaReqMRS;                                     /*!< Enable issuing of DMA request when MRS occurs, if GRE is enabled. (IR.MRS_DMAE) */
    boolean DisableOutput;                                 /*!< True/false - disable/enable the CTU outputs: pulses to other peripherals/pins, ADC commands or command streams. */
    uint8 DigitalFilter;                                  /* Digital filter for external input signal (EXT_IN) */
    uint16 ConvDurationExpectedVal[FEATURE_CTU_NUM_ADC];   /* EXPAR, EXPBR */
    uint16 ConvDurationCounterRange;                     /* CNTRNGR */
    uint8 ControlOnTime;                                  /* COTGT */
    void (*ErrNotification)(uint32 Mask);              /*!< Error callback with triggered mask error as parameter, can check with CTU_IP_ERROR_FLAG defines. Interrupt error enabled (IR.IEE) 9 error types. */
    void (*MrsNotification)(void);
    void (*AdcCommandIssueNotification)(void);
    void (*ConvDurationExceedNotification[FEATURE_CTU_NUM_ADC])(void);

    uint8 NumTrigConfigs;
    const Ctu_Ip_TrigConfigType * TrigConfigs;

    uint8 NumAdcCmdConfigs;
    const Ctu_Ip_AdcCmdConfigType * AdcCmdConfigs;

    uint8 NumFifoConfigs;
    const Ctu_Ip_FifoConfigType * FifoConfigs;
} Ctu_Ip_ConfigType;

/*!
* @brief Structure for storing runtime info
*
* This structure is used to store CTU runtime info
*
* Implements : Ctu_Ip_StateStructType_Class
*/
typedef struct {
    boolean InitStatus; /*!< Check if the driver was initialized. */
    void (*ErrNotification)(uint32 Mask);
    void (*MrsNotification)(void);
    void (*AdcCommandIssueNotification)(void);
    void (*ConvDurationExceedNotification[FEATURE_CTU_NUM_ADC])(void);

    Ctu_Ip_TrgNotificationType TrigNotifications[FEATURE_CTU_NUM_TRG];
    uint32 FifoEnMask[CTU_IP_FIFO_COUNT];
    Ctu_Ip_FifoNotificationsType FifoNotifications[CTU_IP_FIFO_COUNT];
} Ctu_Ip_StateStructType;

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CTU_IP_TYPES_H */

/**
 * @file HpcCan_Driver.c
 * @brief HPC M7 CAN driver built on the EB-generated AUTOSAR Can module.
 *
 * The EB-generated Can module exclusively owns FlexCAN0; this file does not
 * perform direct FlexCAN initialization, transmission or reception.
 */

#include "HpcCan_Driver.h"

#include "Can.h"
#include "CanIf_Can.h"
#include "Clock_Ip.h"
#include "FlexCAN_Ip.h"
#include "TJA1145A_Spi_Baremetal.h"

#include <string.h>

#define HPC_CAN_CONTROLLER               CanController_0
#define HPC_CAN_RX_SLOT_COUNT            2U
#define HPC_CAN_TX_SLOT_COUNT            2U
#define HPC_CAN_FRAME_LENGTH             8U
#define HPC_CAN_MAIN_PERIOD_MS           10U
#define HPC_CAN_BUS_OFF_RETRY_MS         100U
#define HPC_CAN_BUS_OFF_RETRY_TICKS      \
  (HPC_CAN_BUS_OFF_RETRY_MS / HPC_CAN_MAIN_PERIOD_MS)
#define HPC_CAN_TRANSCEIVER_PERIOD_MS    100U
#define HPC_CAN_TRANSCEIVER_TICKS        \
  (HPC_CAN_TRANSCEIVER_PERIOD_MS / HPC_CAN_MAIN_PERIOD_MS)
#define HPC_CAN_TJA1145_SPI_BAUD_DIV     2U
#define HPC_CAN_TJA1145_CTS_MASK         0x80U

#define HPC_CAN_TX_PDU_0                 ((PduIdType)0U)
#define HPC_CAN_TX_PDU_1                 ((PduIdType)1U)

/* RTD 4.0.2 does not publish these polling prototypes in Can.h. The selected
 * names come directly from the generated CAN_MAINFUNCTION_* period macros. */
extern void Can_MainFunction_Read_0(void);
extern void Can_MainFunction_Write_1(void);
extern void Can_MainFunction_BusOff(void);
extern void Can_MainFunction_Mode(void);

typedef struct {
  uint8 data[HPC_CAN_FRAME_LENGTH];
  uint8 length;
  volatile uint32 generation;
  uint32 consumedGeneration;
} HpcCan_RxSlotType;

volatile uint32 g_hpcCanTxMailbox0Count = 0U;
volatile uint32 g_hpcCanTxMailbox1Count = 0U;
volatile uint32 g_hpcCanRxMailbox0Count = 0U;
volatile uint32 g_hpcCanRxMailbox1Count = 0U;
volatile uint32 g_hpcCanBusOffCount = 0U;
volatile uint32 g_hpcCanRecoveryCount = 0U;
volatile uint8 g_hpcCanInitStatus = HPC_CAN_STATUS_ERROR;

static HpcCan_RxSlotType s_hpcCanRxSlots[HPC_CAN_RX_SLOT_COUNT];
static volatile boolean s_hpcCanInitialized = FALSE;
static volatile boolean s_hpcCanControllerStarted = FALSE;
static volatile boolean s_hpcCanBusOff = FALSE;
static volatile boolean s_hpcCanTxPending[HPC_CAN_TX_SLOT_COUNT] = {FALSE, FALSE};
static uint16 s_hpcCanBusOffRetryTicks = 0U;
static uint16 s_hpcCanTransceiverTicks = 0U;
static uint8 s_hpcCanTxData1[HPC_CAN_FRAME_LENGTH] = {
  0x11U, 0x12U, 0x13U, 0x14U, 0x15U, 0x16U, 0x17U, 0x18U
};
static uint8 s_hpcCanRxData1[HPC_CAN_FRAME_LENGTH] = {0U};

static unsigned char HpcCan_GetTxConfig(uint8 logicalMailbox,
                                        Can_HwHandleType *hth,
                                        PduIdType *pduHandle,
                                        Can_IdType *canId)
{
  if ((hth == NULL_PTR) || (pduHandle == NULL_PTR) || (canId == NULL_PTR)) {
    return HPC_CAN_STATUS_ERROR;
  }

  if (logicalMailbox == HPC_CAN_TX_MAILBOX_0) {
    *hth = CanHardwareObject_Tx_100;
    *pduHandle = HPC_CAN_TX_PDU_0;
    *canId = (Can_IdType)HPC_CAN_TX_MESSAGE_ID_0;
    return HPC_CAN_STATUS_OK;
  }

  if (logicalMailbox == HPC_CAN_TX_MAILBOX_1) {
    *hth = CanHardwareObject_Tx_101;
    *pduHandle = HPC_CAN_TX_PDU_1;
    *canId = (Can_IdType)HPC_CAN_TX_MESSAGE_ID_1;
    return HPC_CAN_STATUS_OK;
  }

  return HPC_CAN_STATUS_ERROR;
}

static unsigned char HpcCan_GetRxSlot(uint8 logicalMailbox,
                                      uint8 *slotIndex)
{
  if (slotIndex == NULL_PTR) {
    return HPC_CAN_STATUS_ERROR;
  }

  if (logicalMailbox == HPC_CAN_RX_MAILBOX_0) {
    *slotIndex = 0U;
    return HPC_CAN_STATUS_OK;
  }

  if (logicalMailbox == HPC_CAN_RX_MAILBOX_1) {
    *slotIndex = 1U;
    return HPC_CAN_STATUS_OK;
  }

  return HPC_CAN_STATUS_ERROR;
}

static unsigned char HpcCan_GetTxMailboxById(uint32 messageId,
                                             uint8 *logicalMailbox)
{
  if (logicalMailbox == NULL_PTR) {
    return HPC_CAN_STATUS_ERROR;
  }

  if (messageId == HPC_CAN_TX_MESSAGE_ID_0) {
    *logicalMailbox = HPC_CAN_TX_MAILBOX_0;
    return HPC_CAN_STATUS_OK;
  }

  if (messageId == HPC_CAN_TX_MESSAGE_ID_1) {
    *logicalMailbox = HPC_CAN_TX_MAILBOX_1;
    return HPC_CAN_STATUS_OK;
  }

  return HPC_CAN_STATUS_ERROR;
}

static unsigned char HpcCan_GetRxMailboxById(uint32 messageId,
                                             uint8 *logicalMailbox)
{
  if (logicalMailbox == NULL_PTR) {
    return HPC_CAN_STATUS_ERROR;
  }

  if (messageId == HPC_CAN_RX_MESSAGE_ID_0) {
    *logicalMailbox = HPC_CAN_RX_MAILBOX_0;
    return HPC_CAN_STATUS_OK;
  }

  if (messageId == HPC_CAN_RX_MESSAGE_ID_1) {
    *logicalMailbox = HPC_CAN_RX_MAILBOX_1;
    return HPC_CAN_STATUS_OK;
  }

  return HPC_CAN_STATUS_ERROR;
}

unsigned char HpcCan_Init(void)
{
  uint8 slot;
  uint8 tjaInitResult;

  if (s_hpcCanInitialized != FALSE) {
    return g_hpcCanInitStatus;
  }

  for (slot = 0U; slot < HPC_CAN_RX_SLOT_COUNT; slot++) {
    (void)memset(s_hpcCanRxSlots[slot].data, 0, HPC_CAN_FRAME_LENGTH);
    s_hpcCanRxSlots[slot].length = 0U;
    s_hpcCanRxSlots[slot].generation = 0U;
    s_hpcCanRxSlots[slot].consumedGeneration = 0U;
  }

  g_hpcCanTxMailbox0Count = 0U;
  g_hpcCanTxMailbox1Count = 0U;
  g_hpcCanRxMailbox0Count = 0U;
  g_hpcCanRxMailbox1Count = 0U;
  g_hpcCanBusOffCount = 0U;
  g_hpcCanRecoveryCount = 0U;
  s_hpcCanBusOff = FALSE;
  s_hpcCanControllerStarted = FALSE;
  s_hpcCanTxPending[0] = FALSE;
  s_hpcCanTxPending[1] = FALSE;
  s_hpcCanBusOffRetryTicks = 0U;
  s_hpcCanTransceiverTicks = 0U;

  /* The TJA1145A is controlled through DSPI5. The reference project enables
   * the peripheral clock and initializes DSPI5 before the first register
   * access; omitting either step leaves the transceiver offline. */
  Clock_Ip_EnableModuleClock(SPI5_CLK);
  Spi_Baremetal_Init(HPC_CAN_TJA1145_SPI_BAUD_DIV);
  tjaInitResult = Spi_Baremetal_Tja1145_Init();

  /* Initialize and start FlexCAN only after the transceiver's SPI control
   * path is operational. */
  Can_Init(&Can_Config_VS_0);
  s_hpcCanInitialized = TRUE;

  if (Can_SetControllerMode(HPC_CAN_CONTROLLER, CAN_CS_STARTED) != E_OK) {
    g_hpcCanInitStatus = HPC_CAN_STATUS_ERROR;
    return HPC_CAN_STATUS_ERROR;
  }

  /* FlexCAN now drives TXD recessive while idle, so CAN Active can safely be
   * requested and verified through the TJA1145A CTS status bit. */
  Spi_Baremetal_Tja1145_SetCanActive();

  if ((g_Spi_Baremetal_Debug.init_ok == 0U) ||
      (g_Spi_Baremetal_Debug.error_code != 0U) ||
      (tjaInitResult != 0U) ||
      ((g_Spi_Baremetal_Debug.tja_R22_trans_status &
        HPC_CAN_TJA1145_CTS_MASK) == 0U)) {
    g_hpcCanInitStatus = HPC_CAN_STATUS_ERROR;
    return HPC_CAN_STATUS_ERROR;
  }

  g_hpcCanInitStatus = HPC_CAN_STATUS_OK;
  return HPC_CAN_STATUS_OK;
}

unsigned char HpcCan_RecoverBusOff(void)
{
  Std_ReturnType stopResult;
  Std_ReturnType startResult;

  if (s_hpcCanInitialized == FALSE) {
    return HPC_CAN_STATUS_ERROR;
  }

  stopResult = Can_SetControllerMode(HPC_CAN_CONTROLLER, CAN_CS_STOPPED);
  if (stopResult != E_OK) {
    return HPC_CAN_STATUS_ERROR;
  }

  startResult = Can_SetControllerMode(HPC_CAN_CONTROLLER, CAN_CS_STARTED);
  if (startResult != E_OK) {
    return HPC_CAN_STATUS_ERROR;
  }

  s_hpcCanBusOff = FALSE;
  s_hpcCanBusOffRetryTicks = 0U;
  g_hpcCanRecoveryCount++;
  return HPC_CAN_STATUS_OK;
}

unsigned char HpcCan_Transmit(unsigned char busId, unsigned char mailbox,
                              const unsigned char *frame)
{
  Can_HwHandleType hth;
  PduIdType pduHandle;
  Can_IdType canId;
  Can_PduType pduInfo;
  Std_ReturnType result;

  if ((busId != 0U) || (frame == NULL_PTR) ||
      (s_hpcCanInitialized == FALSE) ||
      (s_hpcCanControllerStarted == FALSE) ||
      (s_hpcCanBusOff != FALSE)) {
    return HPC_CAN_STATUS_ERROR;
  }

  if (HpcCan_GetTxConfig((uint8)mailbox, &hth, &pduHandle, &canId) !=
      HPC_CAN_STATUS_OK) {
    return HPC_CAN_STATUS_ERROR;
  }

  if (s_hpcCanTxPending[(uint8)mailbox] != FALSE) {
    return HPC_CAN_STATUS_BUSY;
  }

  pduInfo.id = canId;
  pduInfo.swPduHandle = pduHandle;
  pduInfo.length = HPC_CAN_FRAME_LENGTH;
  pduInfo.sdu = (uint8 *)frame;

  result = Can_Write(hth, &pduInfo);
  if (result == E_OK) {
    s_hpcCanTxPending[(uint8)mailbox] = TRUE;
    return HPC_CAN_STATUS_OK;
  }

  if (result == (Std_ReturnType)CAN_BUSY) {
    return HPC_CAN_STATUS_BUSY;
  }

  return HPC_CAN_STATUS_ERROR;
}

unsigned char HpcCan_Receive(unsigned char busId, unsigned char mailbox,
                             unsigned char *frame)
{
  uint8 slot;
  uint8 copyLength;
  uint32 generationBefore;
  uint32 generationAfter;

  if ((busId != 0U) || (frame == NULL_PTR) ||
      (s_hpcCanInitialized == FALSE)) {
    return HPC_CAN_STATUS_ERROR;
  }

  if (HpcCan_GetRxSlot((uint8)mailbox, &slot) != HPC_CAN_STATUS_OK) {
    return HPC_CAN_STATUS_ERROR;
  }

  generationBefore = s_hpcCanRxSlots[slot].generation;
  if (generationBefore == s_hpcCanRxSlots[slot].consumedGeneration) {
    return HPC_CAN_STATUS_NO_MSG;
  }

  copyLength = s_hpcCanRxSlots[slot].length;
  if (copyLength > HPC_CAN_FRAME_LENGTH) {
    copyLength = HPC_CAN_FRAME_LENGTH;
  }

  (void)memcpy(frame, s_hpcCanRxSlots[slot].data, copyLength);
  if (copyLength < HPC_CAN_FRAME_LENGTH) {
    (void)memset(&frame[copyLength], 0,
                 (size_t)(HPC_CAN_FRAME_LENGTH - copyLength));
  }

  generationAfter = s_hpcCanRxSlots[slot].generation;
  if (generationAfter != generationBefore) {
    return HPC_CAN_STATUS_BUSY;
  }

  s_hpcCanRxSlots[slot].consumedGeneration = generationBefore;
  return HPC_CAN_STATUS_OK;
}

unsigned char HpcCan_ReceiveDecoded(uint32 messageId, void *decodedMessage)
{
  uint8 logicalMailbox;
  uint8 rxData[HPC_CAN_FRAME_LENGTH];
  unsigned char result;

  if (decodedMessage == NULL_PTR) {
    return HPC_CAN_STATUS_ERROR;
  }

  if (HpcCan_GetRxMailboxById(messageId, &logicalMailbox) !=
      HPC_CAN_STATUS_OK) {
    return HPC_CAN_STATUS_ERROR;
  }

  result = HpcCan_Receive(0U, logicalMailbox, rxData);
  if (result != HPC_CAN_STATUS_OK) {
    return result;
  }

  if (Standard_Rx_unpack(messageId, decodedMessage, rxData,
                         HPC_CAN_FRAME_LENGTH) != 0) {
    return HPC_CAN_STATUS_ERROR;
  }

  return HPC_CAN_STATUS_OK;
}

unsigned char HpcCan_TransmitEncoded(uint32 messageId, const void *messageData)
{
  uint8 logicalMailbox;
  uint8 txData[HPC_CAN_FRAME_LENGTH] = {0U};

  if (messageData == NULL_PTR) {
    return HPC_CAN_STATUS_ERROR;
  }

  if (HpcCan_GetTxMailboxById(messageId, &logicalMailbox) !=
      HPC_CAN_STATUS_OK) {
    return HPC_CAN_STATUS_ERROR;
  }

  if (Standard_Tx_pack(messageId, txData, messageData,
                       HPC_CAN_FRAME_LENGTH) != 0) {
    return HPC_CAN_STATUS_ERROR;
  }

  return HpcCan_Transmit(0U, logicalMailbox, txData);
}

void HpcCan_MainFunction_10ms(void)
{
  if (s_hpcCanInitialized == FALSE) {
    return;
  }

  /* Service the EB AUTOSAR Can polling state machines in the same 10ms
   * periodic CAN bucket used by the reference project. Run these first so
   * RX indications and TX confirmations are visible to this cycle's
   * application processing. */
  Can_MainFunction_BusOff();
  Can_MainFunction_Mode();
  Can_MainFunction_Write_1();
  Can_MainFunction_Read_0();

  if (s_hpcCanBusOff != FALSE) {
    s_hpcCanBusOffRetryTicks++;
    if (s_hpcCanBusOffRetryTicks >= HPC_CAN_BUS_OFF_RETRY_TICKS) {
      (void)HpcCan_RecoverBusOff();
    }
  }

  /* Match the reference application's actual cyclic behavior: decode 0x200,
   * consume raw 0x201, and transmit the raw 0x101 counter frame. The DBC has
   * no typed mapping for 0x201/0x101. */
  (void)HpcCan_ReceiveDecoded(STANDARD_200_RX_ID, &g_rx_Standard_200_Rx);
  (void)HpcCan_Receive(0U, HPC_CAN_RX_MAILBOX_1, s_hpcCanRxData1);

  s_hpcCanTxData1[0] = (uint8)(g_hpcCanTxMailbox1Count & 0xFFU);
  s_hpcCanTxData1[1] = (uint8)((g_hpcCanTxMailbox1Count >> 8U) & 0xFFU);
  (void)HpcCan_Transmit(0U, HPC_CAN_TX_MAILBOX_1, s_hpcCanTxData1);

  s_hpcCanTransceiverTicks++;
  if (s_hpcCanTransceiverTicks >= HPC_CAN_TRANSCEIVER_TICKS) {
    Spi_Baremetal_Tja1145_PeriodicTest();

    /* PeriodicTest may recover the transceiver after a power dip or an
     * initially late VCC/VIO ramp. Reflect the current hardware state so
     * diagnostics do not remain latched at the boot-time result. */
    if (((g_Spi_Baremetal_Debug.tja_R03_main_status &
          TJA1145_MAIN_STATUS_NMS) == 0U) &&
        ((g_Spi_Baremetal_Debug.tja_R22_trans_status &
          HPC_CAN_TJA1145_CTS_MASK) != 0U)) {
      g_hpcCanInitStatus = HPC_CAN_STATUS_OK;
    } else {
      g_hpcCanInitStatus = HPC_CAN_STATUS_ERROR;
    }

    s_hpcCanTransceiverTicks = 0U;
  }
}

void CanIf_ControllerBusOff(uint8 ControllerId)
{
  if (ControllerId == HPC_CAN_CONTROLLER) {
    s_hpcCanBusOff = TRUE;
    s_hpcCanControllerStarted = FALSE;
    s_hpcCanTxPending[0] = FALSE;
    s_hpcCanTxPending[1] = FALSE;
    s_hpcCanBusOffRetryTicks = 0U;
    g_hpcCanBusOffCount++;
  }
}

void CanIf_ControllerModeIndication(uint8 ControllerId,
                                    Can_ControllerStateType ControllerMode)
{
  if (ControllerId == HPC_CAN_CONTROLLER) {
    s_hpcCanControllerStarted =
        (ControllerMode == CAN_CS_STARTED) ? TRUE : FALSE;
  }
}

void CanIf_TxConfirmation(PduIdType CanTxPduId)
{
  if (CanTxPduId == HPC_CAN_TX_PDU_0) {
    s_hpcCanTxPending[0] = FALSE;
    g_hpcCanTxMailbox0Count++;
  } else if (CanTxPduId == HPC_CAN_TX_PDU_1) {
    s_hpcCanTxPending[1] = FALSE;
    g_hpcCanTxMailbox1Count++;
  } else {
    /* Ignore confirmations not owned by this adapter. */
  }
}

void CanIf_RxIndication(const Can_HwType *Mailbox,
                        const PduInfoType *PduInfoPtr)
{
  uint8 slot;
  uint8 length;

  if ((Mailbox == NULL_PTR) || (PduInfoPtr == NULL_PTR) ||
      (PduInfoPtr->SduDataPtr == NULL_PTR)) {
    return;
  }

  if (Mailbox->Hoh == CanHardwareObject_Rx_200) {
    slot = 0U;
  } else if (Mailbox->Hoh == CanHardwareObject_Rx_201) {
    slot = 1U;
  } else {
    return;
  }

  length = (PduInfoPtr->SduLength > HPC_CAN_FRAME_LENGTH)
               ? HPC_CAN_FRAME_LENGTH
               : (uint8)PduInfoPtr->SduLength;

  (void)memcpy(s_hpcCanRxSlots[slot].data, PduInfoPtr->SduDataPtr, length);
  if (length < HPC_CAN_FRAME_LENGTH) {
    (void)memset(&s_hpcCanRxSlots[slot].data[length], 0,
                 (size_t)(HPC_CAN_FRAME_LENGTH - length));
  }
  s_hpcCanRxSlots[slot].length = length;
  s_hpcCanRxSlots[slot].generation++;

  if (slot == 0U) {
    g_hpcCanRxMailbox0Count++;
  } else {
    g_hpcCanRxMailbox1Count++;
  }
}

void CanIf_CurrentIcomConfiguration(uint8 ControllerId,
                                    IcomConfigIdType ConfigurationId,
                                    IcomSwitch_ErrorType Error)
{
  (void)ControllerId;
  (void)ConfigurationId;
  (void)Error;
}

/* ESR1 masks used by the existing health-monitoring API. */
#define HPC_CAN_ESR1_BIT1ERR_MASK   0x00008000U
#define HPC_CAN_ESR1_BIT0ERR_MASK   0x00004000U
#define HPC_CAN_ESR1_ACKERR_MASK    0x00002000U
#define HPC_CAN_ESR1_CRCERR_MASK    0x00001000U
#define HPC_CAN_ESR1_FRMERR_MASK    0x00000800U
#define HPC_CAN_ESR1_STFERR_MASK    0x00000400U
#define HPC_CAN_ESR1_TXWRN_MASK     0x00000200U
#define HPC_CAN_ESR1_RXWRN_MASK     0x00000100U
#define HPC_CAN_ESR1_FLTCONF_MASK   0x00000030U
#define HPC_CAN_ESR1_FLTCONF_SHIFT  4U
#define HPC_CAN_ESR1_BOFFINT_MASK   0x00000004U

unsigned char HpcCan_GetBusDiagnostics(HpcCan_DiagnosticInfoType *diagnostics)
{
  uint32 esr1;
  uint32 faultState;

  if ((diagnostics == NULL_PTR) || (s_hpcCanInitialized == FALSE)) {
    return HPC_CAN_STATUS_ERROR;
  }

  esr1 = FlexCAN_Ip_GetErrorStatus(0U);
  faultState = (esr1 & HPC_CAN_ESR1_FLTCONF_MASK) >>
               HPC_CAN_ESR1_FLTCONF_SHIFT;

  diagnostics->rawEsr1 = esr1;
  diagnostics->txErrorCounter = FlexCAN_Ip_GetControllerTxErrorCounter(0U);
  diagnostics->rxErrorCounter = FlexCAN_Ip_GetControllerRxErrorCounter(0U);

  if (faultState == 0U) {
    diagnostics->busState = HPC_CAN_BUS_STATE_ERROR_ACTIVE;
  } else if (faultState == 1U) {
    diagnostics->busState = HPC_CAN_BUS_STATE_ERROR_PASSIVE;
  } else {
    diagnostics->busState = HPC_CAN_BUS_STATE_BUS_OFF;
  }

  diagnostics->bitError =
      ((esr1 & (HPC_CAN_ESR1_BIT1ERR_MASK |
                HPC_CAN_ESR1_BIT0ERR_MASK)) != 0U) ? TRUE : FALSE;
  diagnostics->ackError =
      ((esr1 & HPC_CAN_ESR1_ACKERR_MASK) != 0U) ? TRUE : FALSE;
  diagnostics->crcError =
      ((esr1 & HPC_CAN_ESR1_CRCERR_MASK) != 0U) ? TRUE : FALSE;
  diagnostics->formError =
      ((esr1 & HPC_CAN_ESR1_FRMERR_MASK) != 0U) ? TRUE : FALSE;
  diagnostics->stuffError =
      ((esr1 & HPC_CAN_ESR1_STFERR_MASK) != 0U) ? TRUE : FALSE;
  diagnostics->txWarning =
      ((esr1 & HPC_CAN_ESR1_TXWRN_MASK) != 0U) ? TRUE : FALSE;
  diagnostics->rxWarning =
      ((esr1 & HPC_CAN_ESR1_RXWRN_MASK) != 0U) ? TRUE : FALSE;
  diagnostics->busOffInt =
      ((esr1 & HPC_CAN_ESR1_BOFFINT_MASK) != 0U) ? TRUE : FALSE;

  return HPC_CAN_STATUS_OK;
}

/**
 * @file HpcCan_Driver.h
 * @brief HPC M7 CAN driver built on the EB-generated AUTOSAR Can module.
 *
 * This is the active CAN implementation for this project. It uses Can_Init,
 * Can_Write and the standard CanIf callbacks. FlexCAN hardware ownership stays
 * inside the EB-generated MCAL Can driver.
 */

#ifndef HPCCAN_DRIVER_H
#define HPCCAN_DRIVER_H

#include "Can.h"
#include "CANdbc_Generated.h"

#ifdef __cplusplus
extern "C" {
#endif

#define HPC_CAN_STATUS_OK       0U
#define HPC_CAN_STATUS_BUSY     1U
#define HPC_CAN_STATUS_ERROR    2U
#define HPC_CAN_STATUS_NO_MSG   3U

/* Logical application mailboxes; these are not physical FlexCAN MB numbers. */
#define HPC_CAN_TX_MAILBOX_0    0U
#define HPC_CAN_TX_MAILBOX_1    1U
#define HPC_CAN_RX_MAILBOX_0    2U
#define HPC_CAN_RX_MAILBOX_1    3U

#define HPC_CAN_TX_MESSAGE_ID_0 0x100U
#define HPC_CAN_TX_MESSAGE_ID_1 0x101U
#define HPC_CAN_RX_MESSAGE_ID_0 0x200U
#define HPC_CAN_RX_MESSAGE_ID_1 0x201U

extern volatile uint32 g_hpcCanTxMailbox0Count;
extern volatile uint32 g_hpcCanTxMailbox1Count;
extern volatile uint32 g_hpcCanRxMailbox0Count;
extern volatile uint32 g_hpcCanRxMailbox1Count;
extern volatile uint32 g_hpcCanBusOffCount;
extern volatile uint32 g_hpcCanRecoveryCount;
extern volatile uint8 g_hpcCanInitStatus;

unsigned char HpcCan_Init(void);
void HpcCan_MainFunction_10ms(void);
unsigned char HpcCan_RecoverBusOff(void);

unsigned char HpcCan_Transmit(unsigned char busId, unsigned char mailbox,
                              const unsigned char *frame);
unsigned char HpcCan_Receive(unsigned char busId, unsigned char mailbox,
                             unsigned char *frame);

unsigned char HpcCan_ReceiveDecoded(uint32 messageId, void *decodedMessage);
unsigned char HpcCan_TransmitEncoded(uint32 messageId,
                                     const void *messageData);

typedef enum {
  HPC_CAN_BUS_STATE_ERROR_ACTIVE  = 0U,
  HPC_CAN_BUS_STATE_ERROR_PASSIVE = 1U,
  HPC_CAN_BUS_STATE_BUS_OFF       = 2U,
  HPC_CAN_BUS_STATE_UNKNOWN       = 3U
} HpcCan_BusStateType;

typedef struct {
  HpcCan_BusStateType busState;
  uint8 txErrorCounter;
  uint8 rxErrorCounter;
  uint32 rawEsr1;
  boolean bitError;
  boolean ackError;
  boolean crcError;
  boolean formError;
  boolean stuffError;
  boolean txWarning;
  boolean rxWarning;
  boolean busOffInt;
} HpcCan_DiagnosticInfoType;

unsigned char HpcCan_GetBusDiagnostics(HpcCan_DiagnosticInfoType *diagnostics);

#ifdef __cplusplus
}
#endif

#endif /* HPCCAN_DRIVER_H */

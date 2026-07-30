#include "stubs.h"
#include "Lin_43_LLCE.h"
#include "PlatformInit.h"
#include "Llce_Firmware_Load.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define LIN_CH3 3 /* SLAVE */
#define LIN_CH2 2 /* MASTER */
#define LIN_CH1 1
#define LIN_CH0 0

#define TP_TIMEOUT 800000U

#define OFF 0
#define ON 1

#define ASSERT(expr) \
    if (!(expr)) \
        fail = ON



/* From a LIN master node’s point of view, there exist 3 different directions of
   frames on the LIN bus: 
1. Response transmitted by the master, 
2. Response received by the master
3. Response transmitted by one slave and received by another slave.*/
/* 
   Configuration setup consists of a wired loopback connection between: 
   Lin Hw Channel 2 -- Master
   Lin Hw Channel 3 -- Slave
*/

void setParity(uint8* pid)
{
    uint32 u32Temp = ((uint32)(*pid)) & RAW_PID_MASK; /* only 6bits for PID */

    /* Calculate parity bit P1 = !(ID1 ^ ID3 ^ ID4 ^ ID5) */
    u32Temp |= ((((*pid >> 1) ^ \
                (*pid >> 3) ^ \
                (*pid >> 4) ^ \
                (*pid >> 5) \
                )& ((uint32)1U) \
                ) ^ ((uint32)1U) \
            ) << (uint32)7U;

    /* Calculate parity bit P0 = (ID0 ^ ID1 ^ ID2 ^ ID4) */
    u32Temp |= (((*pid) ^ \
                  (*pid >> 1U) ^ \
                  (*pid >> 2U) ^ \
                  (*pid >> 4U) \
                 ) & ((uint32)1U) \
                ) << (uint32)6U;

    *pid = (uint8)u32Temp;
}

 /* Check data published by the slave node */
void checkSlaveResponse(uint8* receivedDataPtr)
{
    uint8 length = T_Lin_Table_Schedule[SlaveRuleNr].Dl;
    for (uint8 i = 0; i < length; i++)
    {   
        /* Check received response by the master matches with the response published by the slave, by looking into the Schedule Table */
        ASSERT(receivedDataPtr[i] == T_Lin_Table_Schedule[SlaveRuleNr].SduPtr[i]); 
    }
    
}

void Lin_Driver_Sample_Test(void)
{
    uint8 linSdu[8] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
    uint8* linSduPtr = linSdu;
    uint8 T_Lin_Data_Receive[5] = {0x11, 0x21, 0x31, 0x41, 0x51};
    uint8 u8dataToReceive[8]  = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};

    uint8 *u8dataToReceivePtr = u8dataToReceive; /* Pointer to memory area where received data is stored */

    uint8 T_Lin_Data_Send[3] = {0x11, 0x22, 0x33};

    uint8 txPid = 50;
    uint8 rxPid = 51;

    uint32 lin_counter;
    
    setParity(&txPid);
    setParity(&rxPid); /* rxPid = 73. Parity bits will be discarded on the rx side, so that actual Pid is 73 & 3F = 51 */

    Lin_PduType T_Lin_Frame_Send = {txPid, LIN_ENHANCED_CS, LIN_FRAMERESPONSE_TX, 3u, T_Lin_Data_Send};
    Lin_PduType T_Lin_Frame_Receive = {rxPid, LIN_ENHANCED_CS, LIN_FRAMERESPONSE_RX, 5u, T_Lin_Data_Receive};

    Lin_PduType tosend_frame;
    Lin_PduType toreceive_frame;
    volatile Lin_StatusType LinStatus;

    ResetCounters();
    fail = OFF;
    (void)fail;
    Lin_43_LLCE_Init(NULL_PTR);

    /* Case 1: Master task + slave task */

    LinStatus = Lin_43_LLCE_GetStatus(LIN_CH2, &linSduPtr);
    ASSERT(LinStatus == LIN_CH_SLEEP);

    /* WakeUp only the Master Node */
    Lin_43_LLCE_WakeupInternal(LIN_CH2);
    LinStatus = Lin_43_LLCE_GetStatus(LIN_CH2, &linSduPtr);
    ASSERT(LinStatus == LIN_OPERATIONAL);
    /* Check Slave Node is still in sleep */
    LinStatus = Lin_43_LLCE_GetStatus(LIN_CH3, &linSduPtr);
    ASSERT(LinStatus == LIN_CH_SLEEP);

    /* Master Node sends a header with RESPONSE_TX. The master itself (slave task) will generate the response */
    tosend_frame = T_Lin_Frame_Send;
    Lin_43_LLCE_SendFrame(LIN_CH2, &tosend_frame);
    lin_counter = 0U;
    do {
        LinStatus = Lin_43_LLCE_GetStatus(LIN_CH2, &linSduPtr);
        lin_counter++;
    }
    while ((LinStatus != LIN_TX_OK) && (lin_counter < TP_TIMEOUT));
    ASSERT(LinStatus == LIN_TX_OK);

    /* Case 2: Master node + slave node */
    /* WakeUp the entire bus (Master and Slave nodes) */
    Lin_43_LLCE_Wakeup(LIN_CH3);
    LinStatus = Lin_43_LLCE_GetStatus(LIN_CH3, &linSduPtr);
    ASSERT(LinStatus == LIN_OPERATIONAL);


    tosend_frame = T_Lin_Frame_Send;
    /* Master Node sends a header with RESPONSE_TX. Because the slave node subscribes to the frame and no other slaves is on the bus 
       to publish a response, there will be an RX_ERROR, meaning that no response has been published on the bus. */
    Lin_43_LLCE_SendFrame(LIN_CH2, &tosend_frame);
    lin_counter = 0U;
    do {
        LinStatus = Lin_43_LLCE_GetStatus(LIN_CH2, &linSduPtr);
        lin_counter++;
    }
    while ((LinStatus != LIN_TX_OK) && (lin_counter < TP_TIMEOUT));
    ASSERT(LinStatus == LIN_TX_OK); /* Header sent */
    
    lin_counter = 0U;
    do {
        LinStatus = Lin_43_LLCE_GetStatus(LIN_CH3, &linSduPtr);
        lin_counter++;
    }
    while ((LinStatus != LIN_RX_ERROR) && (lin_counter < TP_TIMEOUT));
    ASSERT(LinStatus == LIN_RX_ERROR); /* No response published on the bus */

    Lin_43_LLCE_GoToSleepInternal(LIN_CH3);
    Lin_43_LLCE_WakeupInternal(LIN_CH3);
    LinStatus = Lin_43_LLCE_GetStatus(LIN_CH3, &linSduPtr);
    ASSERT(LinStatus == LIN_OPERATIONAL);

    /* Master Node sends a header with RESPONSE_RX. The master will read the response published by the slave node */
    toreceive_frame = T_Lin_Frame_Receive;
    Lin_43_LLCE_SendFrame(LIN_CH2, &toreceive_frame);
    lin_counter = 0U;
    do {
        LinStatus = Lin_43_LLCE_GetStatus(LIN_CH2, &u8dataToReceivePtr);
        lin_counter++;
    }
    while ((LinStatus != LIN_RX_OK) && (lin_counter < TP_TIMEOUT));
    ASSERT(LinStatus == LIN_RX_OK);

    lin_counter = 0U;
    do {
        LinStatus = Lin_43_LLCE_GetStatus(LIN_CH3, &linSduPtr);
        lin_counter++;
    }
    while ((LinStatus != LIN_OPERATIONAL) && (lin_counter < TP_TIMEOUT));
    ASSERT(LinStatus == LIN_OPERATIONAL);

    checkSlaveResponse(u8dataToReceivePtr);


    /* Case 3: Master node + 1st slave node + 2nd slave node. This is slave-to-slave communication. Not covered here due to the incomplete setup configuration*/
}

int main(void)
{
    PlatformInit();
    Llce_Firmware_Load();
    Lin_Driver_Sample_Test();

    while (1);
}

#ifdef __cplusplus
}
#endif

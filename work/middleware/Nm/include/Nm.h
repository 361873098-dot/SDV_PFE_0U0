#ifndef NM_H
#define NM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"

#define NM_UDP_LISTEN_PORT              5000U
#define NM_UDP_RX_BUFFER_SIZE           1472U
#define NM_PDU_LENGTH                   8U
#define NM_EXPECTED_NID                 0xCFU

typedef struct
{
    uint8 sourceNodeIdentifier;

    boolean activeWakeup;
    boolean partialNetworkInformation;

    boolean pncGlobal;
    boolean pncDownload;
    boolean wakeupSource;

    boolean otaClient;

    uint32 remoteAddress;
    uint16 remotePort;
} Nm_RxPduType;

/* 可在 Trace32 中监视 */
extern volatile Nm_RxPduType Nm_LastRxPdu;
extern volatile uint32 Nm_ValidRxCount;
extern volatile uint32 Nm_InvalidLengthCount;
extern volatile uint32 Nm_InvalidContentCount;

Std_ReturnType Nm_Init(void);

void Nm_UdpRxIndication(const uint8 *data,
                        uint16 length,
                        uint32 remoteAddress,
                        uint16 remotePort);

#ifdef __cplusplus
}
#endif

#endif /* NM_H */

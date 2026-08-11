#ifndef NM_H
#define NM_H
#include <stdint.h>

#define NM_UDP_PORT 30010

/*  NID */
typedef union Nm_NidUnion
{
    uint8_t Value;
} Nm_Nid_t;

typedef union Nm_ControlVectorUnion
{
    uint8_t Value;
    struct
    {
        uint8_t reserved0 : 4;
        uint8_t ActiveWakeupBit : 1;
        uint8_t reserved1 : 1;
        uint8_t PartialNetworkInfo  : 1;
        uint8_t reserved2 : 1;
    } bits;
} Nm_ControlBitVector_t;

typedef union Nm_PncInfoUnion
{
    uint8_t Value;
    struct
    {
        uint8_t PncGlobal : 1;
        uint8_t reserved0 : 1;
        uint8_t reserved1 : 1;
        uint8_t PncDownload : 1;
        uint8_t reserved2 : 3;
        uint8_t WakeupSource : 1;
    } bits;
} Nm_PncInfo_t;

typedef union Nm_AppInfoUnion
{
    uint8_t Value;
    struct
    {
        uint8_t reserved0 : 3;
        uint8_t OTACLT : 1;
        uint8_t reserved1 : 4;
    } bits;
} Nm_AppInfo_t;


typedef union
{
    uint8_t Byte[8];
    struct
    {
        Nm_Nid_t Nid;
        Nm_ControlBitVector_t ControlBitVector;
        uint8_t reserved0;
        Nm_PncInfo_t PncInfo;
        uint8_t reserved1;
        uint8_t reserved2;
        Nm_AppInfo_t AppInfo;
        uint8_t reserved3;
    } fields;
}Nm_UDPPayload_t;


void Nm_Init(void);

#endif /* NM_H */
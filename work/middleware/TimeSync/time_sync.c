/********************************************************************************
* COPYRIGHT (C) Vitesco Technologies 2025
* ALL RIGHTS RESERVED.
*********************************************************************************
*  File name:       time_sync.c
*  Module acronym:  TIMESYNC
*  Description:     IPCF time synchronization and wakeup appointment service.
*********************************************************************************/

#include "picc_api.h"
#include "time_sync.h"
#include "time_sync_cnf.h"
#include "calendar_cnf.h"

TimeSyncInfo_st g_timeSyncInfo_Event;
DateTime_st dateTime;
volatile TimeSync_Debug_st g_timeSyncDebug;

static uint16 TimeSync_ReadBe16(const uint8 *data)
{
    return (uint16)((((uint16)data[0]) << 8U) | ((uint16)data[1]));
}

static uint32 TimeSync_ReadBe32(const uint8 *data)
{
    return (((uint32)data[0]) << 24U) |
           (((uint32)data[1]) << 16U) |
           (((uint32)data[2]) << 8U) |
           ((uint32)data[3]);
}

static uint64 TimeSync_ReadBe64(const uint8 *data)
{
    uint64 value = 0ULL;
    uint8 index;

    for (index = 0U; index < 8U; index++)
    {
        value = (value << 8U) | (uint64)data[index];
    }
    return value;
}

static void TimeSync_WriteBe16(uint8 *data, uint16 value)
{
    data[0] = (uint8)(value >> 8U);
    data[1] = (uint8)value;
}

static void TimeSync_WriteBe32(uint8 *data, uint32 value)
{
    data[0] = (uint8)(value >> 24U);
    data[1] = (uint8)(value >> 16U);
    data[2] = (uint8)(value >> 8U);
    data[3] = (uint8)value;
}

static void TimeSync_WriteBe64(uint8 *data, uint64 value)
{
    sint8 index;

    for (index = 7; index >= 0; index--)
    {
        data[(uint8)index] = (uint8)value;
        value >>= 8U;
    }
}

static void TimeSync_ClearDateTime(DateTime_st *value)
{
    value->Year = 0U;
    value->Month = 0U;
    value->Day = 0U;
    value->Hour = 0U;
    value->Minute = 0U;
    value->Second = 0U;
}

static void TimeSync_ClearAppointments(void)
{
    uint16 index;

    for (index = 0U; index < APPOINTMENT_LIST_NUM; index++)
    {
        g_appointment_list[index].App_Id = 0U;
        g_appointment_list[index].ClockType = TIMESYNC_CLOCK_RELATIVE;
        g_appointment_list[index].IsValid = FALSE;
        TimeSync_ClearDateTime(&g_appointment_list[index].DateTime);
        g_appointment_list[index].RelativeSeconds = 0U;
    }
}

static sint16 TimeSync_FindAppointment(uint32 appId, uint8 clockType)
{
    uint16 index;

    for (index = 0U; index < APPOINTMENT_LIST_NUM; index++)
    {
        if ((g_appointment_list[index].IsValid == TRUE) &&
            (g_appointment_list[index].App_Id == appId) &&
            (g_appointment_list[index].ClockType == clockType))
        {
            return (sint16)index;
        }
    }
    return (sint16)-1;
}

static sint16 TimeSync_FindFreeAppointment(void)
{
    uint16 index;

    for (index = 0U; index < APPOINTMENT_LIST_NUM; index++)
    {
        if (g_appointment_list[index].IsValid == FALSE)
        {
            return (sint16)index;
        }
    }
    return (sint16)-1;
}

static boolean TimeSync_IsClockTypeValid(uint8 clockType)
{
    return (boolean)(((clockType == TIMESYNC_CLOCK_RELATIVE) ||
                      (clockType == TIMESYNC_CLOCK_ABSOLUTE)) ? TRUE : FALSE);
}

static void TimeSync_RecordTransaction(uint8 methodId, uint8 sessionId,
                                       uint8 result, uint16 rxLength,
                                       uint16 txLength)
{
    g_timeSyncDebug.LastMethodId = methodId;
    g_timeSyncDebug.LastSessionId = sessionId;
    g_timeSyncDebug.LastResult = result;
    g_timeSyncDebug.LastRxLength = rxLength;
    g_timeSyncDebug.LastTxLength = txLength;
}

void TimeSync_Init(void)
{
    static const PICC_AppConfig_t timeInfoCfg =
    {
        .localId = TIMESYNC_LOCAL_CLIENT_ID,
        .remoteId = TIMESYNC_REMOTE_SERVER_ID,
        .role = PICC_ROLE_CLIENT,
        .channelId = TIMESYNC_CHANNEL_ID,
        .Client_linkReq_PeriodMs = 0U,
        .methodHandler = NULL,
        .eventHandler = NULL
    };
    static const PICC_AppConfig_t wakeupCfg =
    {
        .localId = TIMESYNC_LOCAL_SERVER_ID,
        .remoteId = TIMESYNC_REMOTE_CLIENT_ID,
        .role = PICC_ROLE_SERVER,
        .channelId = TIMESYNC_CHANNEL_ID,
        .Client_linkReq_PeriodMs = 0U,
        .methodHandler = NULL,
        .eventHandler = NULL
    };

    g_timeSyncInfo_Event.Seconds = 0ULL;
    g_timeSyncInfo_Event.Nanoseconds = 0U;
    g_timeSyncInfo_Event.isGlobalTimeValid = 0U;
    g_timeSyncInfo_Event.LocalZone = 0U;
    g_timeSyncInfo_Event.LocalZoneDecimals = 0U;
    g_timeSyncInfo_Event.LocalZoneSymbol = 0U;
    g_timeSyncInfo_Event.isDst = 0U;
    TimeSync_ClearDateTime(&dateTime);
    TimeSync_ClearAppointments();

    g_timeSyncDebug.TimeValid = 0U;
    g_timeSyncDebug.LastMethodId = 0U;
    g_timeSyncDebug.LastSessionId = 0U;
    g_timeSyncDebug.LastResult = 0U;
    g_timeSyncDebug.LastRxLength = 0U;
    g_timeSyncDebug.LastTxLength = 0U;
    g_timeSyncDebug.TimeNoticeCount = 0U;
    g_timeSyncDebug.TimestampRequestCount = 0U;
    g_timeSyncDebug.AppointmentSetCount = 0U;
    g_timeSyncDebug.AppointmentListCount = 0U;

    g_timeSyncDebug.ClientInitResult = PICC_Init(PICC_APP_TIMESYNC_CLIENT, &timeInfoCfg);
    g_timeSyncDebug.ServerInitResult = PICC_Init(PICC_APP_TIMESYNC_SERVER, &wakeupCfg);
}

static void TimeSync_GetTimeInfo(void)
{
    uint8 rxBuffer[TIMESYNC_TIME_PAYLOAD_LEN];
    uint16 rxLength = 0U;

    if (PICC_GetEventData(PICC_APP_TIMESYNC_CLIENT,
                          TIMESYNC_EVENT_TIME_NOTICE,
                          rxBuffer, sizeof(rxBuffer), &rxLength,
                          NULL, NULL) == PICC_E_OK)
    {
        g_timeSyncDebug.TimeNoticeCount++;
        g_timeSyncDebug.LastRxLength = rxLength;

        if (rxLength == TIMESYNC_TIME_PAYLOAD_LEN)
        {
            g_timeSyncInfo_Event.Seconds = TimeSync_ReadBe64(&rxBuffer[0]);
            g_timeSyncInfo_Event.Nanoseconds = TimeSync_ReadBe32(&rxBuffer[8]);
            g_timeSyncInfo_Event.isGlobalTimeValid = rxBuffer[12];
            g_timeSyncInfo_Event.LocalZone = rxBuffer[13];
            g_timeSyncInfo_Event.LocalZoneDecimals = rxBuffer[14];
            g_timeSyncInfo_Event.LocalZoneSymbol = rxBuffer[15];
            g_timeSyncInfo_Event.isDst = rxBuffer[16];
            g_timeSyncDebug.TimeValid =
                (g_timeSyncInfo_Event.isGlobalTimeValid == 0x01U) ? 1U : 0U;

            if (g_timeSyncDebug.TimeValid == 1U)
            {
                (void)TimeSync_ConvertSecondsToDateTime(
                    g_timeSyncInfo_Event.Seconds, &dateTime);
            }
        }
        else
        {
            g_timeSyncDebug.TimeValid = 0U;
        }
    }
}

static void TimeSync_SendTime(void)
{
    uint8 sessionId = 0U;
    uint8 rxBuffer[1];
    uint16 rxLength = 0U;
    uint8 txBuffer[TIMESYNC_TIME_PAYLOAD_LEN];
    sint8 sendResult;

    if (PICC_GetMethodData(PICC_APP_TIMESYNC_SERVER,
                           TIMESYNC_METHOD_TIMESTAMP,
                           rxBuffer, sizeof(rxBuffer), &rxLength,
                           &sessionId, NULL, NULL) == PICC_E_OK)
    {
        TimeSync_WriteBe64(&txBuffer[0], g_timeSyncInfo_Event.Seconds);
        TimeSync_WriteBe32(&txBuffer[8], g_timeSyncInfo_Event.Nanoseconds);
        txBuffer[12] = g_timeSyncDebug.TimeValid;
        txBuffer[13] = g_timeSyncInfo_Event.LocalZone;
        txBuffer[14] = g_timeSyncInfo_Event.LocalZoneDecimals;
        txBuffer[15] = g_timeSyncInfo_Event.LocalZoneSymbol;
        txBuffer[16] = g_timeSyncInfo_Event.isDst;

        sendResult = PICC_MethodResponse(PICC_APP_TIMESYNC_SERVER,
                                         TIMESYNC_METHOD_TIMESTAMP,
                                         sessionId, 0x00U,
                                         txBuffer, sizeof(txBuffer));
        g_timeSyncDebug.TimestampRequestCount++;
        TimeSync_RecordTransaction(TIMESYNC_METHOD_TIMESTAMP, sessionId,
                                   (sendResult == PICC_E_OK) ? TIMESYNC_RESULT_OK : TIMESYNC_RESULT_INVALID,
                                   rxLength, sizeof(txBuffer));
    }
}

static uint8 TimeSync_GetOperationType(uint8 command, uint8 clockType)
{
    if ((clockType != TIMESYNC_CLOCK_RELATIVE) &&
        (clockType != TIMESYNC_CLOCK_ABSOLUTE))
    {
        return 0xFFU;
    }
    if (command == TIMESYNC_CMD_SET)
    {
        return clockType;
    }
    if (command == TIMESYNC_CMD_CLEAR)
    {
        return (uint8)(clockType + 2U);
    }
    return 0xFFU;
}

static uint8 TimeSync_UpdateAppointment(const uint8 *rxBuffer, uint32 appId,
                                        uint8 command, uint8 clockType)
{
    sint16 slot;
    DateTime_st requestedDate;
    uint64 ignoredSeconds;

    slot = TimeSync_FindAppointment(appId, clockType);

    if (command == TIMESYNC_CMD_CLEAR)
    {
        if (slot < 0)
        {
            return TIMESYNC_RESULT_NOT_FOUND_OR_FULL;
        }
        g_appointment_list[(uint16)slot].IsValid = FALSE;
        return TIMESYNC_RESULT_OK;
    }

    if (command != TIMESYNC_CMD_SET)
    {
        return TIMESYNC_RESULT_INVALID;
    }

    if (clockType == TIMESYNC_CLOCK_ABSOLUTE)
    {
        requestedDate.Year = TimeSync_ReadBe16(&rxBuffer[8]);
        requestedDate.Month = rxBuffer[10];
        requestedDate.Day = rxBuffer[11];
        requestedDate.Hour = rxBuffer[12];
        requestedDate.Minute = rxBuffer[13];
        requestedDate.Second = rxBuffer[14];
        if (TimeSync_ConvertDateTimeToSeconds(requestedDate, &ignoredSeconds) != E_OK)
        {
            return TIMESYNC_RESULT_INVALID;
        }
    }
    else
    {
        TimeSync_ClearDateTime(&requestedDate);
    }

    if (slot < 0)
    {
        slot = TimeSync_FindFreeAppointment();
    }
    if (slot < 0)
    {
        return TIMESYNC_RESULT_NOT_FOUND_OR_FULL;
    }

    g_appointment_list[(uint16)slot].App_Id = appId;
    g_appointment_list[(uint16)slot].ClockType = clockType;
    g_appointment_list[(uint16)slot].IsValid = TRUE;
    if (clockType == TIMESYNC_CLOCK_ABSOLUTE)
    {
        g_appointment_list[(uint16)slot].DateTime = requestedDate;
        g_appointment_list[(uint16)slot].RelativeSeconds = 0U;
    }
    else
    {
        TimeSync_ClearDateTime(&g_appointment_list[(uint16)slot].DateTime);
        g_appointment_list[(uint16)slot].RelativeSeconds = TimeSync_ReadBe32(&rxBuffer[8]);
    }
    return TIMESYNC_RESULT_OK;
}

static void TimeSync_CnfAppointment(void)
{
    uint8 sessionId = 0U;
    uint8 rxBuffer[TIMESYNC_APPOINTMENT_REQUEST_LEN];
    uint16 rxLength = 0U;
    uint8 txBuffer[TIMESYNC_APPOINTMENT_RESPONSE_LEN] = {0U};
    uint8 command = 0xFFU;
    uint8 clockType = 0xFFU;
    uint32 appId = 0U;
    uint8 result = TIMESYNC_RESULT_INVALID;

    if (PICC_GetMethodData(PICC_APP_TIMESYNC_SERVER,
                           TIMESYNC_METHOD_APPOINTMENT_SET,
                           rxBuffer, sizeof(rxBuffer), &rxLength,
                           &sessionId, NULL, NULL) == PICC_E_OK)
    {
        if (rxLength == TIMESYNC_APPOINTMENT_REQUEST_LEN)
        {
            command = rxBuffer[1];
            clockType = rxBuffer[2];
            appId = TimeSync_ReadBe32(&rxBuffer[3]);
            if ((rxBuffer[0] == TIMESYNC_PARTITION_VM1) &&
                (TimeSync_IsClockTypeValid(clockType) == TRUE))
            {
                result = TimeSync_UpdateAppointment(rxBuffer, appId,
                                                    command, clockType);
            }
        }

        txBuffer[0] = TIMESYNC_PARTITION_VM1;
        txBuffer[1] = TimeSync_GetOperationType(command, clockType);
        txBuffer[2] = result;
        if (result != TIMESYNC_RESULT_OK)
        {
            TimeSync_WriteBe32(&txBuffer[3], appId);
        }

        (void)PICC_MethodResponse(PICC_APP_TIMESYNC_SERVER,
                                  TIMESYNC_METHOD_APPOINTMENT_SET,
                                  sessionId, 0x00U,
                                  txBuffer, sizeof(txBuffer));
        g_timeSyncDebug.AppointmentSetCount++;
        TimeSync_RecordTransaction(TIMESYNC_METHOD_APPOINTMENT_SET,
                                   sessionId, result, rxLength,
                                   sizeof(txBuffer));
    }
}

static uint16 TimeSync_AppendAppointment(uint8 *txBuffer, uint16 offset,
                                         const Appt_st *appointment)
{
    txBuffer[offset] = TIMESYNC_PARTITION_VM1;
    txBuffer[offset + 1U] = appointment->ClockType;
    TimeSync_WriteBe32(&txBuffer[offset + 2U], appointment->App_Id);
    txBuffer[offset + 6U] = 0U;

    if (appointment->ClockType == TIMESYNC_CLOCK_ABSOLUTE)
    {
        TimeSync_WriteBe16(&txBuffer[offset + 7U], appointment->DateTime.Year);
        txBuffer[offset + 9U] = appointment->DateTime.Month;
        txBuffer[offset + 10U] = appointment->DateTime.Day;
        txBuffer[offset + 11U] = appointment->DateTime.Hour;
        txBuffer[offset + 12U] = appointment->DateTime.Minute;
        txBuffer[offset + 13U] = appointment->DateTime.Second;
    }
    else
    {
        TimeSync_WriteBe32(&txBuffer[offset + 7U], appointment->RelativeSeconds);
        txBuffer[offset + 11U] = 0U;
        txBuffer[offset + 12U] = 0U;
        txBuffer[offset + 13U] = 0U;
    }

    txBuffer[offset + 14U] = TIMESYNC_LIST_NOT_EMPTY;
    txBuffer[offset + 15U] = 0U;
    return (uint16)(offset + TIMESYNC_LIST_ITEM_LEN);
}

static void TimeSync_TxAppointment(void)
{
    uint8 sessionId = 0U;
    uint8 rxBuffer[TIMESYNC_LIST_REQUEST_LEN];
    uint16 rxLength = 0U;
    uint8 txBuffer[TIMESYNC_LIST_TX_MAX_LEN] = {0U};
    uint16 txLength = 0U;
    uint16 index;
    uint8 result = TIMESYNC_RESULT_INVALID;
    uint8 clockType = 0xFFU;

    if (PICC_GetMethodData(PICC_APP_TIMESYNC_SERVER,
                           TIMESYNC_METHOD_APPOINTMENT_LIST,
                           rxBuffer, sizeof(rxBuffer), &rxLength,
                           &sessionId, NULL, NULL) == PICC_E_OK)
    {
        if ((rxLength == TIMESYNC_LIST_REQUEST_LEN) &&
            (rxBuffer[0] == TIMESYNC_PARTITION_VM1) &&
            (TimeSync_IsClockTypeValid(rxBuffer[1]) == TRUE))
        {
            clockType = rxBuffer[1];
            for (index = 0U; index < APPOINTMENT_LIST_NUM; index++)
            {
                if ((g_appointment_list[index].IsValid == TRUE) &&
                    (g_appointment_list[index].ClockType == clockType))
                {
                    txLength = TimeSync_AppendAppointment(txBuffer, txLength,
                                                          &g_appointment_list[index]);
                }
            }

            if (txLength == 0U)
            {
                txBuffer[0] = TIMESYNC_PARTITION_VM1;
                txBuffer[1] = clockType;
                txBuffer[14] = TIMESYNC_LIST_EMPTY;
                txLength = TIMESYNC_LIST_ITEM_LEN;
            }
            result = TIMESYNC_RESULT_OK;
        }

        (void)PICC_MethodResponse(PICC_APP_TIMESYNC_SERVER,
                                  TIMESYNC_METHOD_APPOINTMENT_LIST,
                                  sessionId, result,
                                  txBuffer, txLength);
        g_timeSyncDebug.AppointmentListCount++;
        TimeSync_RecordTransaction(TIMESYNC_METHOD_APPOINTMENT_LIST,
                                   sessionId, result, rxLength, txLength);
    }
}

void TimeSync_Main(void)
{
    TimeSync_GetTimeInfo();
    TimeSync_SendTime();
    TimeSync_CnfAppointment();
    TimeSync_TxAppointment();
}

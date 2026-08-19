/********************************************************************************
* COPYRIGHT (C) Vitesco Technologies 2025
* ALL RIGHTS RESERVED.
*********************************************************************************
*  File name:       timesync.c
*  Module acronym:  TIMESYNC
*  Description:     IPCF time synchronization and wakeup appointment service.
*********************************************************************************/

#include "picc_api.h"
#include "timesync.h"
#include "timesync_cnf.h"
#include "timesync_calendar_cnf.h"

TimeSync_Info_t g_TimeSyncInfo;
TimeSync_DateTime_t g_TimeSyncDateTime;
volatile TimeSync_Debug_t g_TimeSyncDebug;

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

static void TimeSync_ClearDateTime(TimeSync_DateTime_t *value)
{
    value->year = 0U;
    value->month = 0U;
    value->day = 0U;
    value->hour = 0U;
    value->minute = 0U;
    value->second = 0U;
}

static void TimeSync_ClearAppointments(void)
{
    uint16 index;

    for (index = 0U; index < TIMESYNC_APPOINTMENT_LIST_SIZE; index++)
    {
        g_TimeSyncAppointmentList[index].appId = 0U;
        g_TimeSyncAppointmentList[index].clockType = TIMESYNC_CLOCK_RELATIVE;
        g_TimeSyncAppointmentList[index].isValid = FALSE;
        TimeSync_ClearDateTime(&g_TimeSyncAppointmentList[index].dateTime);
        g_TimeSyncAppointmentList[index].relativeSeconds = 0U;
    }
}

static sint16 TimeSync_FindAppointment(uint32 appId, uint8 clockType)
{
    uint16 index;

    for (index = 0U; index < TIMESYNC_APPOINTMENT_LIST_SIZE; index++)
    {
        if ((g_TimeSyncAppointmentList[index].isValid == TRUE) &&
            (g_TimeSyncAppointmentList[index].appId == appId) &&
            (g_TimeSyncAppointmentList[index].clockType == clockType))
        {
            return (sint16)index;
        }
    }
    return (sint16)-1;
}

static sint16 TimeSync_FindFreeAppointment(void)
{
    uint16 index;

    for (index = 0U; index < TIMESYNC_APPOINTMENT_LIST_SIZE; index++)
    {
        if (g_TimeSyncAppointmentList[index].isValid == FALSE)
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
    g_TimeSyncDebug.lastMethodId = methodId;
    g_TimeSyncDebug.lastSessionId = sessionId;
    g_TimeSyncDebug.lastResult = result;
    g_TimeSyncDebug.lastRxLength = rxLength;
    g_TimeSyncDebug.lastTxLength = txLength;
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

    g_TimeSyncInfo.seconds = 0ULL;
    g_TimeSyncInfo.nanoseconds = 0U;
    g_TimeSyncInfo.globalTimeValid = 0U;
    g_TimeSyncInfo.localZone = 0U;
    g_TimeSyncInfo.localZoneDecimals = 0U;
    g_TimeSyncInfo.localZoneSign = 0U;
    g_TimeSyncInfo.daylightSavingTime = 0U;
    TimeSync_ClearDateTime(&g_TimeSyncDateTime);
    TimeSync_ClearAppointments();

    g_TimeSyncDebug.timeValid = 0U;
    g_TimeSyncDebug.lastMethodId = 0U;
    g_TimeSyncDebug.lastSessionId = 0U;
    g_TimeSyncDebug.lastResult = 0U;
    g_TimeSyncDebug.lastRxLength = 0U;
    g_TimeSyncDebug.lastTxLength = 0U;
    g_TimeSyncDebug.timeNoticeCount = 0U;
    g_TimeSyncDebug.timestampRequestCount = 0U;
    g_TimeSyncDebug.appointmentSetCount = 0U;
    g_TimeSyncDebug.appointmentListCount = 0U;

    g_TimeSyncDebug.clientInitResult = PICC_Init(PICC_APP_TIMESYNC_CLI,
                                                &timeInfoCfg);
    g_TimeSyncDebug.serverInitResult = PICC_Init(PICC_APP_TIMESYNC_SRV,
                                                 &wakeupCfg);
}

static void TimeSync_ProcessTimeNotice(void)
{
    uint8 rxBuffer[TIMESYNC_TIME_PAYLOAD_LEN];
    uint16 rxLength = 0U;

    if (PICC_GetEventData(PICC_APP_TIMESYNC_CLI,
                          TIMESYNC_EVENT_TIME_NOTICE,
                          rxBuffer, sizeof(rxBuffer), &rxLength,
                          NULL, NULL) == PICC_E_OK)
    {
        g_TimeSyncDebug.timeNoticeCount++;
        g_TimeSyncDebug.lastRxLength = rxLength;

        if (rxLength == TIMESYNC_TIME_PAYLOAD_LEN)
        {
            g_TimeSyncInfo.seconds = TimeSync_ReadBe64(&rxBuffer[0]);
            g_TimeSyncInfo.nanoseconds = TimeSync_ReadBe32(&rxBuffer[8]);
            g_TimeSyncInfo.globalTimeValid = rxBuffer[12];
            g_TimeSyncInfo.localZone = rxBuffer[13];
            g_TimeSyncInfo.localZoneDecimals = rxBuffer[14];
            g_TimeSyncInfo.localZoneSign = rxBuffer[15];
            g_TimeSyncInfo.daylightSavingTime = rxBuffer[16];
            g_TimeSyncDebug.timeValid =
                (g_TimeSyncInfo.globalTimeValid == 0x01U) ? 1U : 0U;

            if (g_TimeSyncDebug.timeValid == 1U)
            {
                (void)TimeSync_ConvertSecondsToDateTime(
                    g_TimeSyncInfo.seconds, &g_TimeSyncDateTime);
            }
        }
        else
        {
            g_TimeSyncDebug.timeValid = 0U;
        }
    }
}

static void TimeSync_ProcessTimestampRequest(void)
{
    uint8 sessionId = 0U;
    uint8 rxBuffer[1];
    uint16 rxLength = 0U;
    uint8 txBuffer[TIMESYNC_TIME_PAYLOAD_LEN];
    sint8 sendResult;

    if (PICC_GetMethodData(PICC_APP_TIMESYNC_SRV,
                           TIMESYNC_METHOD_TIMESTAMP,
                           rxBuffer, sizeof(rxBuffer), &rxLength,
                           &sessionId, NULL, NULL) == PICC_E_OK)
    {
        TimeSync_WriteBe64(&txBuffer[0], g_TimeSyncInfo.seconds);
        TimeSync_WriteBe32(&txBuffer[8], g_TimeSyncInfo.nanoseconds);
        txBuffer[12] = g_TimeSyncDebug.timeValid;
        txBuffer[13] = g_TimeSyncInfo.localZone;
        txBuffer[14] = g_TimeSyncInfo.localZoneDecimals;
        txBuffer[15] = g_TimeSyncInfo.localZoneSign;
        txBuffer[16] = g_TimeSyncInfo.daylightSavingTime;

        sendResult = PICC_MethodResponse(PICC_APP_TIMESYNC_SRV,
                                         TIMESYNC_METHOD_TIMESTAMP,
                                         sessionId, 0x00U,
                                         txBuffer, sizeof(txBuffer));
        g_TimeSyncDebug.timestampRequestCount++;
        TimeSync_RecordTransaction(TIMESYNC_METHOD_TIMESTAMP, sessionId,
                                   (sendResult == PICC_E_OK) ?
                                       TIMESYNC_RESULT_OK : TIMESYNC_RESULT_INVALID,
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
    TimeSync_DateTime_t requestedDate;
    uint64 ignoredSeconds;

    slot = TimeSync_FindAppointment(appId, clockType);

    if (command == TIMESYNC_CMD_CLEAR)
    {
        if (slot < 0)
        {
            return TIMESYNC_RESULT_NOT_FOUND_OR_FULL;
        }
        g_TimeSyncAppointmentList[(uint16)slot].isValid = FALSE;
        return TIMESYNC_RESULT_OK;
    }

    if (command != TIMESYNC_CMD_SET)
    {
        return TIMESYNC_RESULT_INVALID;
    }

    if (clockType == TIMESYNC_CLOCK_ABSOLUTE)
    {
        requestedDate.year = TimeSync_ReadBe16(&rxBuffer[8]);
        requestedDate.month = rxBuffer[10];
        requestedDate.day = rxBuffer[11];
        requestedDate.hour = rxBuffer[12];
        requestedDate.minute = rxBuffer[13];
        requestedDate.second = rxBuffer[14];
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

    g_TimeSyncAppointmentList[(uint16)slot].appId = appId;
    g_TimeSyncAppointmentList[(uint16)slot].clockType = clockType;
    g_TimeSyncAppointmentList[(uint16)slot].isValid = TRUE;
    if (clockType == TIMESYNC_CLOCK_ABSOLUTE)
    {
        g_TimeSyncAppointmentList[(uint16)slot].dateTime = requestedDate;
        g_TimeSyncAppointmentList[(uint16)slot].relativeSeconds = 0U;
    }
    else
    {
        TimeSync_ClearDateTime(&g_TimeSyncAppointmentList[(uint16)slot].dateTime);
        g_TimeSyncAppointmentList[(uint16)slot].relativeSeconds =
            TimeSync_ReadBe32(&rxBuffer[8]);
    }
    return TIMESYNC_RESULT_OK;
}

static void TimeSync_ProcessAppointmentSetRequest(void)
{
    uint8 sessionId = 0U;
    uint8 rxBuffer[TIMESYNC_APPOINTMENT_REQUEST_LEN];
    uint16 rxLength = 0U;
    uint8 txBuffer[TIMESYNC_APPOINTMENT_RESPONSE_LEN] = {0U};
    uint8 command = 0xFFU;
    uint8 clockType = 0xFFU;
    uint32 appId = 0U;
    uint8 result = TIMESYNC_RESULT_INVALID;

    if (PICC_GetMethodData(PICC_APP_TIMESYNC_SRV,
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

        (void)PICC_MethodResponse(PICC_APP_TIMESYNC_SRV,
                                  TIMESYNC_METHOD_APPOINTMENT_SET,
                                  sessionId, 0x00U,
                                  txBuffer, sizeof(txBuffer));
        g_TimeSyncDebug.appointmentSetCount++;
        TimeSync_RecordTransaction(TIMESYNC_METHOD_APPOINTMENT_SET,
                                   sessionId, result, rxLength,
                                   sizeof(txBuffer));
    }
}

static uint16 TimeSync_AppendAppointment(uint8 *txBuffer, uint16 offset,
                                         const TimeSync_Appointment_t *appointment)
{
    txBuffer[offset] = TIMESYNC_PARTITION_VM1;
    txBuffer[offset + 1U] = appointment->clockType;
    TimeSync_WriteBe32(&txBuffer[offset + 2U], appointment->appId);
    txBuffer[offset + 6U] = 0U;

    if (appointment->clockType == TIMESYNC_CLOCK_ABSOLUTE)
    {
        TimeSync_WriteBe16(&txBuffer[offset + 7U], appointment->dateTime.year);
        txBuffer[offset + 9U] = appointment->dateTime.month;
        txBuffer[offset + 10U] = appointment->dateTime.day;
        txBuffer[offset + 11U] = appointment->dateTime.hour;
        txBuffer[offset + 12U] = appointment->dateTime.minute;
        txBuffer[offset + 13U] = appointment->dateTime.second;
    }
    else
    {
        TimeSync_WriteBe32(&txBuffer[offset + 7U], appointment->relativeSeconds);
        txBuffer[offset + 11U] = 0U;
        txBuffer[offset + 12U] = 0U;
        txBuffer[offset + 13U] = 0U;
    }

    txBuffer[offset + 14U] = TIMESYNC_LIST_NOT_EMPTY;
    txBuffer[offset + 15U] = 0U;
    return (uint16)(offset + TIMESYNC_LIST_ITEM_LEN);
}

static void TimeSync_ProcessAppointmentListRequest(void)
{
    uint8 sessionId = 0U;
    uint8 rxBuffer[TIMESYNC_LIST_REQUEST_LEN];
    uint16 rxLength = 0U;
    uint8 txBuffer[TIMESYNC_LIST_TX_MAX_LEN] = {0U};
    uint16 txLength = 0U;
    uint16 index;
    uint8 result = TIMESYNC_RESULT_INVALID;
    uint8 clockType = 0xFFU;

    if (PICC_GetMethodData(PICC_APP_TIMESYNC_SRV,
                           TIMESYNC_METHOD_APPOINTMENT_LIST,
                           rxBuffer, sizeof(rxBuffer), &rxLength,
                           &sessionId, NULL, NULL) == PICC_E_OK)
    {
        if ((rxLength == TIMESYNC_LIST_REQUEST_LEN) &&
            (rxBuffer[0] == TIMESYNC_PARTITION_VM1) &&
            (TimeSync_IsClockTypeValid(rxBuffer[1]) == TRUE))
        {
            clockType = rxBuffer[1];
            for (index = 0U; index < TIMESYNC_APPOINTMENT_LIST_SIZE; index++)
            {
                if ((g_TimeSyncAppointmentList[index].isValid == TRUE) &&
                    (g_TimeSyncAppointmentList[index].clockType == clockType))
                {
                    txLength = TimeSync_AppendAppointment(txBuffer, txLength,
                        &g_TimeSyncAppointmentList[index]);
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

        (void)PICC_MethodResponse(PICC_APP_TIMESYNC_SRV,
                                  TIMESYNC_METHOD_APPOINTMENT_LIST,
                                  sessionId, result,
                                  txBuffer, txLength);
        g_TimeSyncDebug.appointmentListCount++;
        TimeSync_RecordTransaction(TIMESYNC_METHOD_APPOINTMENT_LIST,
                                   sessionId, result, rxLength, txLength);
    }
}

void TimeSync_Main(void)
{
    TimeSync_ProcessTimeNotice();
    TimeSync_ProcessTimestampRequest();
    TimeSync_ProcessAppointmentSetRequest();
    TimeSync_ProcessAppointmentListRequest();
}

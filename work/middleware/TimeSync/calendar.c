/********************************************************************************
* COPYRIGHT (C) Vitesco Technologies 2025
* ALL RIGHTS RESERVED.
*
* The reproduction, transmission or use of this document or its
* contents is not permitted without express written authority.
* Offenders will be liable for damages. All rights, including rights
* created by patent grant or registration of a utility model or design,
* are reserved.
*********************************************************************************
*
*  File name:           $Source: Calendar.c $
*  Revision:            $Revision: 1.0 $
*  Author:              $Author: Li Song (uic59152)  $
*  Module acronym:      CALENDAR
*  Specification:
*  Date:                $Date: 2026/05/12  $
*
*  Description:     This Unit processes the Calendar module
*
*********************************************************************************
*
*  Changes:
*
*
*********************************************************************************/


/***********************************************************************************************************************
*  include files
***********************************************************************************************************************/
#include "calendar.h"
#include "calendar_cnf.h"

/***********************************************************************************************************************
*  local variable definitions (module local variables)
***********************************************************************************************************************/

/***********************************************************************************************************************
*  local function definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
 *  Function name    : TimeSync_IsLeapYear()
 *
 *  Description      : Check if a given year is a leap year.
 *
 *  List of arguments: year - The year to check.
 *
 *  Return value     : TRUE if the year is a leap year, FALSE otherwise.
 *
 ***********************************************************************************************************************/
static boolean TimeSync_IsLeapYear(const uint16 year)
{
    boolean isLeapYear = FALSE;

    if (((year % 4U) == 0U) && (((year % 100U) != 0U) || ((year % 400U) == 0U)))
    {
        isLeapYear = TRUE;
    }

    return isLeapYear;
}

/***********************************************************************************************************************
 *  Function name    : TimeSync_GetDaysInYear()
 *
 *  Description      : Get the number of days in a given year.
 *
 *  List of arguments: year - The year to check.
 *
 *  Return value     : The number of days in the year (365 or 366).
 *
 ***********************************************************************************************************************/
static uint16 TimeSync_GetDaysInYear(const uint16 year)
{
    return (TimeSync_IsLeapYear(year) == TRUE) ? 366U : 365U;
}

/***********************************************************************************************************************
 *  Function name    : TimeSync_GetDaysInMonth()
 *
 *  Description      : Get the number of days in a given month of a specific year.
 *
 *  List of arguments: year - The year of the month.
 *                     month - The month to check (1-12).
 *
 *  Return value     : The number of days in the month.
 *
 ***********************************************************************************************************************/
static uint8 TimeSync_GetDaysInMonth(const uint16 year, const uint8 month)
{
    static const uint8 daysInMonth[12] =
    {
        31U, 28U, 31U, 30U, 31U, 30U,
        31U, 31U, 30U, 31U, 30U, 31U
    };

    uint8 days = daysInMonth[month - 1U];

    if ((month == 2U) && (TimeSync_IsLeapYear(year) == TRUE))
    {
        days = 29U;
    }

    return days;
}


/***********************************************************************************************************************
*  global function definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
 *  Function name    : TimeSync_ConvertSecondsToDateTime()
 *
 *  Description      : Convert a given number of seconds since the epoch to a date and time.
 *
 *  List of arguments: seconds - The number of seconds since the epoch.
 *                     dateTime - Pointer to a DateTime_st structure to store the result.

 *  Return value     : E_OK if the conversion was successful, E_NOT_OK otherwise.
 *
 ***********************************************************************************************************************/
Std_ReturnType TimeSync_ConvertSecondsToDateTime(const uint64 seconds, DateTime_st *dateTime)
{
    uint64 days;
    uint64 secondsOfDay;
    uint16 year;
    uint8 month;

    if (dateTime == NULL_PTR)
    {
        return E_NOT_OK;
    }

    days = seconds / TIMESYNC_SECONDS_PER_DAY;
    secondsOfDay = seconds % TIMESYNC_SECONDS_PER_DAY;

    dateTime->Hour = (uint8)(secondsOfDay / TIMESYNC_SECONDS_PER_HOUR);
    secondsOfDay %= TIMESYNC_SECONDS_PER_HOUR;

    dateTime->Minute = (uint8)(secondsOfDay / TIMESYNC_SECONDS_PER_MINUTE);
    dateTime->Second = (uint8)(secondsOfDay % TIMESYNC_SECONDS_PER_MINUTE);

    year = TIMESYNC_EPOCH_YEAR;
    while (days >= (uint64)TimeSync_GetDaysInYear(year))
    {
        days -= (uint64)TimeSync_GetDaysInYear(year);
        year++;
    }

    month = 1U;
    while (days >= (uint64)TimeSync_GetDaysInMonth(year, month))
    {
        days -= (uint64)TimeSync_GetDaysInMonth(year, month);
        month++;
    }
        dateTime->Year = year;
    dateTime->Month = month;
    dateTime->Day = (uint8)(days + 1U);

    return E_OK;
}


/***********************************************************************************************************************
 *  Function name    : TimeSync_ConvertDateTimeToSeconds()
 *
 *  Description      : Convert a date and time to seconds since the epoch.
 *
 *  List of arguments: dateTime - Pointer to a DateTime_st structure containing the date and time.
 *                     seconds - Pointer to store the seconds since the epoch.
 *
 *  Return value     : E_OK if the conversion was successful, E_NOT_OK otherwise.
 *
 ***********************************************************************************************************************/
Std_ReturnType TimeSync_ConvertDateTimeToSeconds(const DateTime_st dateTime, uint64 *seconds)
{
    uint16 year;
    uint8 month;
    uint64 totalDays = 0U;

    if ((seconds == NULL_PTR) ||
        (dateTime.Year < TIMESYNC_EPOCH_YEAR) ||
        (dateTime.Month < 1U) || (dateTime.Month > 12U) ||
        (dateTime.Day < 1U) ||
        (dateTime.Hour > 23U) ||
        (dateTime.Minute > 59U) ||
        (dateTime.Second > 59U))
    {
        return E_NOT_OK;
    }

    if (dateTime.Day > TimeSync_GetDaysInMonth(dateTime.Year, dateTime.Month))
    {
        return E_NOT_OK;
    }

    for (year = TIMESYNC_EPOCH_YEAR; year < dateTime.Year; year++)
    {
        totalDays += (uint64)TimeSync_GetDaysInYear(year);
    }

    for (month = 1U; month < dateTime.Month; month++)
    {
        totalDays += (uint64)TimeSync_GetDaysInMonth(dateTime.Year, month);
    }

    totalDays += (uint64)(dateTime.Day - 1U);

    *seconds = (totalDays * TIMESYNC_SECONDS_PER_DAY) +
               ((uint64)dateTime.Hour * TIMESYNC_SECONDS_PER_HOUR) +
               ((uint64)dateTime.Minute * TIMESYNC_SECONDS_PER_MINUTE) +
               (uint64)dateTime.Second;

    return E_OK;
}

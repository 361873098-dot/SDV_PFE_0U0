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
*  File name:           $Source: timesync_calendar_cnf.c $
*  Revision:            $Revision: 1.0 $
*  Author:              $Author: Li Song (uic59152)  $
*  Module acronym:      TIMESYNC_CALENDAR_CNF
*  Specification:
*  Date:                $Date: 2026/05/12  $
*
*  Description:     This unit configures the TimeSync calendar module.
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
#include "timesync_calendar_cnf.h"

/***********************************************************************************************************************
*  local variable definitions 
***********************************************************************************************************************/

/***********************************************************************************************************************
*  global variable definitions
***********************************************************************************************************************/
TimeSync_Appointment_t
    g_TimeSyncAppointmentList[TIMESYNC_APPOINTMENT_LIST_SIZE] = {0};

/***********************************************************************************************************************
*  local function definitions
***********************************************************************************************************************/

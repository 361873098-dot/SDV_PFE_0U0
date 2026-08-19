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
*  File name:           $Source: timesync_cnf.h $
*  Revision:            $Revision: 1.0 $
*  Author:              $Author: Li Song (uic59152)  $
*  Module acronym:      TIMESYNC_CNF
*  Specification:
*  Date:                $Date: 2026/05/12  $
*
*  Description:     This Unit processes the TimeSync module
*********************************************************************************
*
*  Changes:
*
*
*********************************************************************************/

#ifndef TIMESYNC_CNF_H
#define TIMESYNC_CNF_H

/***********************************************************************************************************************
*  include files
***********************************************************************************************************************/
#include "timesync_calendar_cnf.h"

/***********************************************************************************************************************
*  define macros
***********************************************************************************************************************/

#define TIMESYNC_CHANNEL_ID                 (1U)

#define TIMESYNC_LOCAL_CLIENT_ID            (61U)
#define TIMESYNC_REMOTE_SERVER_ID           (66U)
#define TIMESYNC_LOCAL_SERVER_ID            (63U)
#define TIMESYNC_REMOTE_CLIENT_ID           (68U)

#define TIMESYNC_EVENT_TIME_NOTICE          (0x01U)
#define TIMESYNC_METHOD_APPOINTMENT_SET      (0x02U)
#define TIMESYNC_METHOD_APPOINTMENT_LIST     (0x03U)
#define TIMESYNC_METHOD_TIMESTAMP            (0x05U)

#define TIMESYNC_PARTITION_VM1              (0x03U)
#define TIMESYNC_CLOCK_RELATIVE              (0x00U)
#define TIMESYNC_CLOCK_ABSOLUTE              (0x01U)
#define TIMESYNC_CMD_SET                     (0x00U)
#define TIMESYNC_CMD_CLEAR                   (0x01U)

#define TIMESYNC_TIME_PAYLOAD_LEN            (17U)
#define TIMESYNC_APPOINTMENT_REQUEST_LEN     (16U)
#define TIMESYNC_APPOINTMENT_RESPONSE_LEN    (8U)
#define TIMESYNC_LIST_REQUEST_LEN            (2U)
#define TIMESYNC_LIST_ITEM_LEN               (16U)
#define TIMESYNC_LIST_TX_MAX_LEN             (TIMESYNC_APPOINTMENT_LIST_SIZE * TIMESYNC_LIST_ITEM_LEN)

#define TIMESYNC_LIST_EMPTY                  (0x01U)
#define TIMESYNC_LIST_NOT_EMPTY              (0x02U)
#define TIMESYNC_RESULT_OK                   (0x00U)
#define TIMESYNC_RESULT_INVALID              (0x01U)
#define TIMESYNC_RESULT_NOT_FOUND_OR_FULL    (0x02U)

/***********************************************************************************************************************
*  local variable definitions (module local variables)
***********************************************************************************************************************/



/***********************************************************************************************************************
*  global function definitions
***********************************************************************************************************************/



#endif /* TIMESYNC_CNF_H */

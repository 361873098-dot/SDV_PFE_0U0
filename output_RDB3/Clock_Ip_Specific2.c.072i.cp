
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Clock_Ip_ReportClockErrors/8:
  Jump functions of caller  Clock_Ip_TimeoutExpired/7:
  Jump functions of caller  Clock_Ip_StartTimeout/6:
  Jump functions of caller  Clock_Ip_ClockPowerModeChangeNotification/5:
  Jump functions of caller  Clock_Ip_ClockInitializeObjects/4:
  Jump functions of caller  Clock_Ip_SpecificPlatformInitClock/3:
    callsite  Clock_Ip_SpecificPlatformInitClock/3 -> Clock_Ip_PowerClockIpModules/0 : 
  Jump functions of caller  Clock_Ip_SpecificPeripheralClockInitialization/2:
  Jump functions of caller  Clock_Ip_McMeEnterKey/1:
  Jump functions of caller  Clock_Ip_PowerClockIpModules/0:
    callsite  Clock_Ip_PowerClockIpModules/0 -> Clock_Ip_McMeEnterKey/1 : 
    callsite  Clock_Ip_PowerClockIpModules/0 -> Clock_Ip_McMeEnterKey/1 : 

 Propagating constants:

Not considering Clock_Ip_ClockPowerModeChangeNotification for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_ClockInitializeObjects for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_SpecificPlatformInitClock for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_SpecificPeripheralClockInitialization for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_McMeEnterKey for cloning; -fipa-cp-clone disabled.

overall_size: 240, max_new_size: 11001
 - context independent values, size: 3, time_benefit: 2.000000
 - context independent values, size: 120, time_benefit: 1.000000
 - context independent values, size: 3, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: Clock_Ip_ClockPowerModeChangeNotification/5:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_ClockInitializeObjects/4:
  Node: Clock_Ip_SpecificPlatformInitClock/3:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_SpecificPeripheralClockInitialization/2:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_McMeEnterKey/1:
  Node: Clock_Ip_PowerClockIpModules/0:

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

Clock_Ip_ReportClockErrors/8 (Clock_Ip_ReportClockErrors) @071c7d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_PowerClockIpModules/0 (12508639 (estimated locally),0.11 per call) Clock_Ip_PowerClockIpModules/0 (37904965 (estimated locally),0.33 per call) Clock_Ip_PowerClockIpModules/0 (12508639 (estimated locally),0.11 per call) 
  Calls: 
Clock_Ip_TimeoutExpired/7 (Clock_Ip_TimeoutExpired) @071c7c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_PowerClockIpModules/0 (354334801 (estimated locally),3.08 per call) Clock_Ip_PowerClockIpModules/0 (1073741824 (estimated locally),9.35 per call) Clock_Ip_PowerClockIpModules/0 (354334803 (estimated locally),3.08 per call) 
  Calls: 
Clock_Ip_StartTimeout/6 (Clock_Ip_StartTimeout) @071c7b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_PowerClockIpModules/0 (37904965 (estimated locally),0.33 per call) Clock_Ip_PowerClockIpModules/0 (114863532 (estimated locally),1.00 per call) Clock_Ip_PowerClockIpModules/0 (37904966 (estimated locally),0.33 per call) 
  Calls: 
Clock_Ip_ClockPowerModeChangeNotification/5 (Clock_Ip_ClockPowerModeChangeNotification) @071c7460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_ClockInitializeObjects/4 (Clock_Ip_ClockInitializeObjects) @071c71c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_SpecificPlatformInitClock/3 (Clock_Ip_SpecificPlatformInitClock) @071c5ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_PowerClockIpModules/0 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_SpecificPeripheralClockInitialization/2 (Clock_Ip_SpecificPeripheralClockInitialization) @07151d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_McMeEnterKey/1 (Clock_Ip_McMeEnterKey) @07151a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: Clock_Ip_PowerClockIpModules/0 (37904965 (estimated locally),0.33 per call) Clock_Ip_PowerClockIpModules/0 (37904966 (estimated locally),0.33 per call) 
  Calls: 
Clock_Ip_PowerClockIpModules/0 (Clock_Ip_PowerClockIpModules) @071517e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) body local optimize_size
  Called by: Clock_Ip_SpecificPlatformInitClock/3 (1073741824 (estimated locally),1.00 per call) 
  Calls: Clock_Ip_ReportClockErrors/8 (12508639 (estimated locally),0.11 per call) Clock_Ip_TimeoutExpired/7 (354334801 (estimated locally),3.08 per call) Clock_Ip_StartTimeout/6 (37904965 (estimated locally),0.33 per call) Clock_Ip_McMeEnterKey/1 (37904965 (estimated locally),0.33 per call) Clock_Ip_ReportClockErrors/8 (37904965 (estimated locally),0.33 per call) Clock_Ip_TimeoutExpired/7 (1073741824 (estimated locally),9.35 per call) Clock_Ip_StartTimeout/6 (114863532 (estimated locally),1.00 per call) Clock_Ip_ReportClockErrors/8 (12508639 (estimated locally),0.11 per call) Clock_Ip_TimeoutExpired/7 (354334803 (estimated locally),3.08 per call) Clock_Ip_StartTimeout/6 (37904966 (estimated locally),0.33 per call) Clock_Ip_McMeEnterKey/1 (37904966 (estimated locally),0.33 per call) 

;; Function Clock_Ip_McMeEnterKey (Clock_Ip_McMeEnterKey, funcdef_no=1, decl_uid=6610, cgraph_uid=2, symbol_order=1)

Modification phase of node Clock_Ip_McMeEnterKey/1
Clock_Ip_McMeEnterKey ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  MEM[(struct MC_ME_Type *)1074298880B].CTL_KEY ={v} 23280;
  # DEBUG BEGIN_STMT
  MEM[(struct MC_ME_Type *)1074298880B].CTL_KEY ={v} 42255;
  return;

}



;; Function Clock_Ip_SpecificPeripheralClockInitialization (Clock_Ip_SpecificPeripheralClockInitialization, funcdef_no=2, decl_uid=6765, cgraph_uid=3, symbol_order=2)

Modification phase of node Clock_Ip_SpecificPeripheralClockInitialization/2
Clock_Ip_SpecificPeripheralClockInitialization (const struct Clock_IP_SpecificPeriphConfigType * Config)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Clock_Ip_SpecificPlatformInitClock (Clock_Ip_SpecificPlatformInitClock, funcdef_no=3, decl_uid=6767, cgraph_uid=4, symbol_order=3)

Modification phase of node Clock_Ip_SpecificPlatformInitClock/3
Clock_Ip_SpecificPlatformInitClock (const struct Clock_Ip_ClockConfigType * Config)
{
  uint32 RegValue;
  uint32 PeriphDfsIsInReset;
  uint32 CoreDfsIsInReset;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  signed int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  signed int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _24;
  long unsigned int _25;
  signed int _26;
  long unsigned int _27;
  long unsigned int _28;
  long unsigned int _29;
  long unsigned int _30;
  long unsigned int _31;
  long unsigned int _32;
  long unsigned int _33;
  long unsigned int _34;
  long unsigned int _35;
  long unsigned int _36;
  signed int _37;
  long unsigned int _38;
  long unsigned int _39;
  long unsigned int _40;
  long unsigned int _41;
  long unsigned int _42;
  long unsigned int _43;
  long unsigned int _44;
  long unsigned int _45;
  long unsigned int _46;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct DFS_Type *)1074085888B].CTL;
  CoreDfsIsInReset_53 = _1 & 2;
  # DEBUG CoreDfsIsInReset => CoreDfsIsInReset_53
  # DEBUG BEGIN_STMT
  _2 ={v} MEM[(struct DFS_Type *)1074102272B].CTL;
  PeriphDfsIsInReset_54 = _2 & 2;
  # DEBUG PeriphDfsIsInReset => PeriphDfsIsInReset_54
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Clock_Ip_PowerClockIpModules ();
  # DEBUG BEGIN_STMT
  if (CoreDfsIsInReset_53 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 3> [local count: 536870913]:
  if (PeriphDfsIsInReset_54 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 4> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  _3 ={v} MEM[(struct PLLDIG_Type *)1073971200B].PLLCR;
  _4 = (signed int) _3;
  if (_4 < 0)
    goto <bb 5>; [41.00%]
  else
    goto <bb 6>; [59.00%]

  <bb 5> [local count: 110058537]:
  # DEBUG BEGIN_STMT
  MEM[(struct PLLDIG_Type *)1073971200B].PLLCLKMUX ={v} 0;
  # DEBUG BEGIN_STMT
  RegValue_57 ={v} MEM[(struct PLLDIG_Type *)1073971200B].PLLDV;
  # DEBUG RegValue => RegValue_57
  # DEBUG BEGIN_STMT
  RegValue_58 = RegValue_57 & 4294938368;
  # DEBUG RegValue => RegValue_58
  # DEBUG BEGIN_STMT
  _5 = RegValue_58 | 4126;
  MEM[(struct PLLDIG_Type *)1073971200B].PLLDV ={v} _5;
  # DEBUG BEGIN_STMT
  _6 ={v} MEM[(struct PLLDIG_Type *)1073971200B].PLLFD;
  _7 = _6 & 3221192704;
  MEM[(struct PLLDIG_Type *)1073971200B].PLLFD ={v} _7;
  # DEBUG BEGIN_STMT
  _8 ={v} MEM[(struct PLLDIG_Type *)1073971200B].PLLCR;
  _9 = _8 & 2147483647;
  MEM[(struct PLLDIG_Type *)1073971200B].PLLCR ={v} _9;

  <bb 6> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  _10 ={v} MEM[(struct PLLDIG_Type *)1073987584B].PLLCR;
  _11 = (signed int) _10;
  if (_11 < 0)
    goto <bb 7>; [41.00%]
  else
    goto <bb 8>; [59.00%]

  <bb 7> [local count: 110058537]:
  # DEBUG BEGIN_STMT
  MEM[(struct PLLDIG_Type *)1073987584B].PLLCLKMUX ={v} 0;
  # DEBUG BEGIN_STMT
  RegValue_63 ={v} MEM[(struct PLLDIG_Type *)1073987584B].PLLDV;
  # DEBUG RegValue => RegValue_63
  # DEBUG BEGIN_STMT
  RegValue_64 = RegValue_63 & 4294938368;
  # DEBUG RegValue => RegValue_64
  # DEBUG BEGIN_STMT
  _12 = RegValue_64 | 4126;
  MEM[(struct PLLDIG_Type *)1073987584B].PLLDV ={v} _12;
  # DEBUG BEGIN_STMT
  _13 ={v} MEM[(struct PLLDIG_Type *)1073987584B].PLLFD;
  _14 = _13 & 3221192704;
  MEM[(struct PLLDIG_Type *)1073987584B].PLLFD ={v} _14;
  # DEBUG BEGIN_STMT
  _15 ={v} MEM[(struct PLLDIG_Type *)1073987584B].PLLCR;
  _16 = _15 & 2147483647;
  MEM[(struct PLLDIG_Type *)1073987584B].PLLCR ={v} _16;

  <bb 8> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  _17 ={v} MEM[(struct DFS_Type *)1074085888B].PORTRESET;
  _18 = _17 | 63;
  MEM[(struct DFS_Type *)1074085888B].PORTRESET ={v} _18;
  # DEBUG BEGIN_STMT
  MEM[(struct DFS_Type *)1074085888B].DVPORT[0] ={v} 256;
  # DEBUG BEGIN_STMT
  MEM[(struct DFS_Type *)1074085888B].DVPORT[1] ={v} 256;
  # DEBUG BEGIN_STMT
  MEM[(struct DFS_Type *)1074085888B].DVPORT[2] ={v} 256;
  # DEBUG BEGIN_STMT
  MEM[(struct DFS_Type *)1074085888B].DVPORT[3] ={v} 256;
  # DEBUG BEGIN_STMT
  MEM[(struct DFS_Type *)1074085888B].DVPORT[4] ={v} 256;
  # DEBUG BEGIN_STMT
  MEM[(struct DFS_Type *)1074085888B].DVPORT[5] ={v} 256;
  # DEBUG BEGIN_STMT
  _19 ={v} MEM[(struct DFS_Type *)1074085888B].CTL;
  _20 = _19 & 4294967293;
  MEM[(struct DFS_Type *)1074085888B].CTL ={v} _20;
  # DEBUG BEGIN_STMT
  _21 ={v} MEM[(struct DFS_Type *)1074102272B].PORTRESET;
  _22 = _21 | 63;
  MEM[(struct DFS_Type *)1074102272B].PORTRESET ={v} _22;
  # DEBUG BEGIN_STMT
  MEM[(struct DFS_Type *)1074102272B].DVPORT[0] ={v} 256;
  # DEBUG BEGIN_STMT
  MEM[(struct DFS_Type *)1074102272B].DVPORT[1] ={v} 256;
  # DEBUG BEGIN_STMT
  MEM[(struct DFS_Type *)1074102272B].DVPORT[2] ={v} 256;
  # DEBUG BEGIN_STMT
  MEM[(struct DFS_Type *)1074102272B].DVPORT[3] ={v} 256;
  # DEBUG BEGIN_STMT
  MEM[(struct DFS_Type *)1074102272B].DVPORT[4] ={v} 256;
  # DEBUG BEGIN_STMT
  MEM[(struct DFS_Type *)1074102272B].DVPORT[5] ={v} 256;
  # DEBUG BEGIN_STMT
  _23 ={v} MEM[(struct DFS_Type *)1074102272B].CTL;
  _24 = _23 & 4294967293;
  MEM[(struct DFS_Type *)1074102272B].CTL ={v} _24;
  goto <bb 17>; [100.00%]

  <bb 9> [local count: 805306369]:
  # DEBUG BEGIN_STMT
  if (CoreDfsIsInReset_53 != 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 10> [local count: 402653184]:
  # DEBUG BEGIN_STMT
  _25 ={v} MEM[(struct PLLDIG_Type *)1073971200B].PLLCR;
  _26 = (signed int) _25;
  if (_26 < 0)
    goto <bb 11>; [41.00%]
  else
    goto <bb 12>; [59.00%]

  <bb 11> [local count: 165087806]:
  # DEBUG BEGIN_STMT
  MEM[(struct PLLDIG_Type *)1073971200B].PLLCLKMUX ={v} 0;
  # DEBUG BEGIN_STMT
  RegValue_99 ={v} MEM[(struct PLLDIG_Type *)1073971200B].PLLDV;
  # DEBUG RegValue => RegValue_99
  # DEBUG BEGIN_STMT
  RegValue_100 = RegValue_99 & 4294938368;
  # DEBUG RegValue => RegValue_100
  # DEBUG BEGIN_STMT
  _27 = RegValue_100 | 4126;
  MEM[(struct PLLDIG_Type *)1073971200B].PLLDV ={v} _27;
  # DEBUG BEGIN_STMT
  _28 ={v} MEM[(struct PLLDIG_Type *)1073971200B].PLLFD;
  _29 = _28 & 3221192704;
  MEM[(struct PLLDIG_Type *)1073971200B].PLLFD ={v} _29;
  # DEBUG BEGIN_STMT
  _30 ={v} MEM[(struct PLLDIG_Type *)1073971200B].PLLCR;
  _31 = _30 & 2147483647;
  MEM[(struct PLLDIG_Type *)1073971200B].PLLCR ={v} _31;

  <bb 12> [local count: 402653184]:
  # DEBUG BEGIN_STMT
  _32 ={v} MEM[(struct DFS_Type *)1074085888B].PORTRESET;
  _33 = _32 | 63;
  MEM[(struct DFS_Type *)1074085888B].PORTRESET ={v} _33;
  # DEBUG BEGIN_STMT
  MEM[(struct DFS_Type *)1074085888B].DVPORT[0] ={v} 256;
  # DEBUG BEGIN_STMT
  MEM[(struct DFS_Type *)1074085888B].DVPORT[1] ={v} 256;
  # DEBUG BEGIN_STMT
  MEM[(struct DFS_Type *)1074085888B].DVPORT[2] ={v} 256;
  # DEBUG BEGIN_STMT
  MEM[(struct DFS_Type *)1074085888B].DVPORT[3] ={v} 256;
  # DEBUG BEGIN_STMT
  MEM[(struct DFS_Type *)1074085888B].DVPORT[4] ={v} 256;
  # DEBUG BEGIN_STMT
  MEM[(struct DFS_Type *)1074085888B].DVPORT[5] ={v} 256;
  # DEBUG BEGIN_STMT
  _34 ={v} MEM[(struct DFS_Type *)1074085888B].CTL;
  _35 = _34 & 4294967293;
  MEM[(struct DFS_Type *)1074085888B].CTL ={v} _35;
  goto <bb 17>; [100.00%]

  <bb 13> [local count: 402653184]:
  # DEBUG BEGIN_STMT
  if (PeriphDfsIsInReset_54 != 0)
    goto <bb 14>; [50.00%]
  else
    goto <bb 17>; [50.00%]

  <bb 14> [local count: 201326592]:
  # DEBUG BEGIN_STMT
  _36 ={v} MEM[(struct PLLDIG_Type *)1073987584B].PLLCR;
  _37 = (signed int) _36;
  if (_37 < 0)
    goto <bb 15>; [41.00%]
  else
    goto <bb 16>; [59.00%]

  <bb 15> [local count: 82543903]:
  # DEBUG BEGIN_STMT
  MEM[(struct PLLDIG_Type *)1073987584B].PLLCLKMUX ={v} 0;
  # DEBUG BEGIN_STMT
  RegValue_85 ={v} MEM[(struct PLLDIG_Type *)1073987584B].PLLDV;
  # DEBUG RegValue => RegValue_85
  # DEBUG BEGIN_STMT
  RegValue_86 = RegValue_85 & 4294938368;
  # DEBUG RegValue => RegValue_86
  # DEBUG BEGIN_STMT
  _38 = RegValue_86 | 4126;
  MEM[(struct PLLDIG_Type *)1073987584B].PLLDV ={v} _38;
  # DEBUG BEGIN_STMT
  _39 ={v} MEM[(struct PLLDIG_Type *)1073987584B].PLLFD;
  _40 = _39 & 3221192704;
  MEM[(struct PLLDIG_Type *)1073987584B].PLLFD ={v} _40;
  # DEBUG BEGIN_STMT
  _41 ={v} MEM[(struct PLLDIG_Type *)1073987584B].PLLCR;
  _42 = _41 & 2147483647;
  MEM[(struct PLLDIG_Type *)1073987584B].PLLCR ={v} _42;

  <bb 16> [local count: 201326592]:
  # DEBUG BEGIN_STMT
  _43 ={v} MEM[(struct DFS_Type *)1074102272B].PORTRESET;
  _44 = _43 | 63;
  MEM[(struct DFS_Type *)1074102272B].PORTRESET ={v} _44;
  # DEBUG BEGIN_STMT
  MEM[(struct DFS_Type *)1074102272B].DVPORT[0] ={v} 256;
  # DEBUG BEGIN_STMT
  MEM[(struct DFS_Type *)1074102272B].DVPORT[1] ={v} 256;
  # DEBUG BEGIN_STMT
  MEM[(struct DFS_Type *)1074102272B].DVPORT[2] ={v} 256;
  # DEBUG BEGIN_STMT
  MEM[(struct DFS_Type *)1074102272B].DVPORT[3] ={v} 256;
  # DEBUG BEGIN_STMT
  MEM[(struct DFS_Type *)1074102272B].DVPORT[4] ={v} 256;
  # DEBUG BEGIN_STMT
  MEM[(struct DFS_Type *)1074102272B].DVPORT[5] ={v} 256;
  # DEBUG BEGIN_STMT
  _45 ={v} MEM[(struct DFS_Type *)1074102272B].CTL;
  _46 = _45 & 4294967293;
  MEM[(struct DFS_Type *)1074102272B].CTL ={v} _46;

  <bb 17> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Clock_Ip_ClockInitializeObjects (Clock_Ip_ClockInitializeObjects, funcdef_no=4, decl_uid=6757, cgraph_uid=5, symbol_order=4)

Modification phase of node Clock_Ip_ClockInitializeObjects/4
Clock_Ip_ClockInitializeObjects ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Clock_Ip_ClockPowerModeChangeNotification (Clock_Ip_ClockPowerModeChangeNotification, funcdef_no=5, decl_uid=6760, cgraph_uid=6, symbol_order=5)

Modification phase of node Clock_Ip_ClockPowerModeChangeNotification/5
Clock_Ip_ClockPowerModeChangeNotification (Clock_Ip_PowerModesType PowerMode, Clock_Ip_PowerNotificationType Notification)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



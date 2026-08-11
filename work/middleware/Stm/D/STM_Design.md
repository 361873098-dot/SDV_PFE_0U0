# STM (Storage Middleware) - Software Design Document


| Number | Date | Author | Approver | Revision History | Status |
|--------|------|--------|----------|------------------|--------|
| V0.1 | 2026.5.28 | weizhichun | | create initial version | draft |
| V0.2 | 2026.6.3 | weizhichun | Li Yijie | Reviewed by lisong and Liyijie | Approved |

| Item | Description |
|------|-------------|
| Module Name | STM (Storage Middleware) |
| Target Platform | S32G399A M7 Core (FreeRTOS) |
---

## 1. Overview

### 1.1 Purpose

STM provides **non-volatile data management** and **M-core/A-core data synchronization** for the S32G3 M core. It bridges the following two domains:

- **Local persistence** - Data is stored in EEPROM, while a RAM image is maintained for zero-latency reads.
- **Inter-core synchronization** - Data changes are automatically propagated between the M core and A core through PICC (IPCF shared memory).

### 1.2 Key Features

| Attribute | Value |
| --------- | ----- |
| Task period | 10 ms, called in `TASK_M0_10MS` |
| Transport channel | IPCF channel 1, high priority, through the PICC middleware |
| PICC role | Dual role: **Provider (server)** + **Consumer (client)** |
| Persistence | I2C EEPROM, segmented writes (<=16 bytes per transfer) |
| Maximum data items | 5 |
| EEPROM data capacity limit | 64 bytes |
| Retry support | Method 0x04 only, 4 retries with stepped intervals |

### 1.3 File Structure

```text
SWC/Stm/
|-- stm.h            - Public APIs: Stm_Init, Stm_Main, Stm_WriteLocal, Stm_ReadLocal, Stm_RequestReadFromA(methodId, dataId)
|-- stm.c            - Core logic: state machine, 5 subtask handlers, and PICC interaction
|-- stm_cnf.h        - Configuration header: PICC IDs, Method IDs, NVM parameters, and state machine enums
|-- stm_cnf.c        - Configuration instances: data item table and retry interval table
|-- stm_nvm.h        - NVM management interface
`-- stm_nvm.c        - NVM implementation: EEPROM read/write, RAM image, and I2C segmented transfer
```

---

## 2. Architecture

### 2.1 Layered Diagram

```text
+-----------------------------------------------------+
|                  Application Layer (SWC)             |
|  Stm_WriteLocal() / Stm_ReadLocal() /                |
|  Stm_RequestReadFromA(methodId, dataId)              |
+---------------+----------------------+--------------+
                |                      |
+---------------v----------+  +--------v--------------+
|      stm.c (Core Layer)   |  |   stm_nvm.c (NVM)     |
|  +--------------------+   |  |  +-----------------+  |
|  | State machine      |   |  |  | RAM image       |  |
|  | (5 states)         |   |  |  | g_nvmBlocks[]   |  |
|  +--------------------+   |  |  +-----------------+  |
|  | Subtasks:          |   |  |  | EEPROM I/O      |  |
|  | - CheckLink        |   |  |  | segmented       |  |
|  | - ProcessRxFromA   |   |  |  | transfer        |  |
|  | - ProcessSyncToA   |   |  |  +-----------------+  |
|  | - ProcessAppRead   |   |  +-----------------------+
|  +--------------------+   |
+---------------+----------+
                |
+---------------v----------+
|            PICC Middleware |
|            IPCF channel 1  |
+--------------------------+
```

### 2.2 Dual-role PICC Registration

STM registers **two** PICC endpoints on channel 1:

| Role | PICC App Index | localId | remoteId | Purpose |
| ---- | -------------- | ------- | -------- | ------- |
| **Provider (server)** | `PICC_APP_STORAGE` | 41 (0x29) | 47 (0x2F) | Receives Method 0x01/0x02 from the A core |
| **Consumer (client)** | `PICC_APP_STM_CLI` | 42 (0x2A) | 46 (0x2E) | Sends Method 0x03/0x04/0x05 to the A core |

STM can run only after both links are connected successfully (`WAIT_LINK` -> `WAIT_CONSISTENCY`).

### 2.3 M/A-core Dual-endpoint Interaction Model and Mechanism

Based on the underlying high-priority IPCF channel 1, STM logically registers both Provider and Consumer endpoints, forming a **symmetric dual-channel interaction model**. This design supports A-core control and write requests to the M core, while also ensuring real-time M-core initiated synchronization and data reads.

#### 2.3.1 Logical Channels and Data Flow

The interaction model consists of two independent logical channels with clear and isolated data flows:

1. **Downlink control channel (A core -> M-core server)**:
   - **Channel mapping**: The M core binds as `PICC_APP_STORAGE` (localId: 41, role `PICC_ROLE_SERVER`) to the A-core client (remoteId: 47).
   - **Business characteristics**: The A core initiates control or write requests. This channel mainly carries **Method 0x01 (consistency check)** and **Method 0x02 (A-core data write to M core)**.
2. **Uplink data channel (M-core client -> A-core server)**:
   - **Channel mapping**: The M core binds as `PICC_APP_STM_CLI` (localId: 42, role `PICC_ROLE_CLIENT`) to the A-core server (remoteId: 46).
   - **Business characteristics**: The M core proactively synchronizes local data or initiates asynchronous readback. This channel mainly carries **Method 0x04 (M-core synchronization to A core)** and **Method 0x03/0x05 (M-core read from A core)**.

```text
       A Core (Application Core)              M Core (S32G3 M7 Core)
   +-----------------------------+        +-----------------------------+
   |  A-Core Client (Consumer)   |        |   M-Core Server (Provider)  |
   |  ID: 47                     |        |   ID: 41 (PICC_APP_STORAGE) |
   +--------------+--------------+        +--------------+--------------+
                  |   Downlink channel (Method 0x01/0x02) ^
                  +----------------------------------------+

   +-----------------------------+        +-----------------------------+
   |  A-Core Server (Provider)   |        |   M-Core Client (Consumer)  |
   |  ID: 46                     |        |   ID: 42 (PICC_APP_STM_CLI) |
   +--------------^--------------+        +--------------^--------------+
                  |   Uplink channel (Method 0x03/0x04/0x05) |
                  +-------------------------------------------+
```

#### 2.3.2 Interaction Mechanism and Link Lifecycle

1. **Time-sliced link handshake**:
   - As the **Server** on port 41, the M core stays in passive listening mode and does not actively issue link-establishment requests.
   - As the **Client** on port 42, after startup or when a disconnection is detected, the M core actively sends a `LINK_AVAILABLE` connection request to the A core every 10 ms until the A core returns an acceptance response (ReturnCode = 0x00).
   - **Strict dual-link gate**: The STM business layer forcibly checks both endpoint links in the main task. STM enters the subsequent consistency-check and data-synchronization states only when both logical channels are in `PICC_LINK_STATE_CONNECTED`. A single-direction connection cannot start business processing.
2. **Bidirectional heartbeat monitoring**:
   - After both channels are established, regardless of whether business reads or writes exist, the communication components on the M core and A core send and receive special `Ping/Pong` heartbeat frames on both ports of channel 1 every **2 seconds**. Ping is `ff 00 ff 00 ff 00 00 01 00`, and Pong is `ff 00 ff 00 ff 00 00 01 01`.
   - If no Pong response is received for three consecutive attempts on either logical port, the medium is considered interrupted, and the link-disconnection reset flow is triggered (`ResetOnDisconnect`).
3. **Stacked multi-packet transmission and data integrity check (CRC16)**:
   - To improve IPCF communication throughput, both transmitted and received M-core frames are **stacked frames**, which support merging and concatenating multiple Event/Method business packets for transmission.
   - Before all pending stacked data is delivered to the IPCF driver, global encapsulation is applied:
     - **First byte**: CRC enable flag, fixed to `0x00` to indicate enabled.
     - **Data body**: The merged N private-protocol packets.
     - **Tail field 1**: 2-byte channel-level transmit counter. Each channel accumulates independently, and the counter **is not reset** when the link disconnects or reconnects.
     - **Tail field 2**: Big-endian CRC16 checksum calculated over all previous data bytes, using the specified table-based method with `startValue=0xFFFF` and `xorValue=0x0000`. The 2-byte checksum is appended to the end of the frame to provide automotive-grade communication integrity.

---

## 3. State Machine

### 3.1 State Transition Diagram

```text
                    Stm_Init()
                        |
                        v
                +---------------+
                |   UNINIT      |
                +-------+-------+
                        |
                        v
                +---------------+    Link disconnected
                |  WAIT_LINK    |<--------------------------+--------------------------+
                +-------+-------+                           |                          |
                        | Both links connected              |                          |
                        v                                   |                          |
                +---------------+                           |                          |
                |WAIT_CONSISTENCY|------ Link disconnected --+                          |
                +-------+-------+                           |                          |
                        |                                   |                          |
                        v                                   |                          |
                +---------------+                           |                          |
                |  SYNC_TO_A    |---- Link disconnected ----+                          |
                +-------+-------+                                                      |
                        | All dirty data synchronized                                   |
                        v                                                              |
                +---------------+                                                      |
                |  RUNNING      |---- Link disconnected -------------------------------+
                +---------------+
```

### 3.2 State Description

| State | Entry Condition | Active Subtasks | Exit Condition |
| ----- | --------------- | --------------- | -------------- |
| `UNINIT` | Power-on default | None | Call `Stm_Init()` -> `WAIT_LINK` |
| `WAIT_LINK` | After initialization or after link disconnection | None; PICC handles link requests automatically | Provider and Consumer links are both connected -> `WAIT_CONSISTENCY` |
| `WAIT_CONSISTENCY` | Link established | Link activity monitoring + polling for Method 0x01 requests | Receive an A-core 0x01 request with payload `0x0000` -> respond with 0x0000 success, mark all local valid blocks dirty, and switch to `SYNC_TO_A` |
| `SYNC_TO_A` | Consistency check passed | Link activity monitoring + `Stm_ProcessSyncToA()` (0x04) | All dirty data (0x04) has been sent and no retry is in progress -> `RUNNING` |
| `RUNNING` | All data synchronized | Link activity monitoring + all four subtasks active, including periodic 0x01 consistency-check handling | Link disconnects due to heartbeat timeout or disconnect notification -> `WAIT_LINK` |

### 3.3 State Reset on Disconnection

When any PICC link is disconnected, the following reset operations are performed:

| Item | Operation | Reason |
| ---- | --------- | ------ |
| State | -> `WAIT_LINK` | Links must be re-established before operations can continue |
| `Stm_SessionId` | Reset to 0 | Protocol requirement: session ID is reset on disconnection |
| `Stm_RetryState.active` | Clear | Cancel ongoing synchronization |
| `Stm_PendingReadReq.active` | Clear | Cancel pending read request |
| `Stm_SyncScanIndex` | Reset to 0 | Restart round-robin scanning |
| NVM dirty flags | **Clear** | Abandon pending synchronization; data in RAM/EEPROM is retained |
| NVM data (RAM/EEPROM) | **Retain** | Local data is still valid |
| CRC/transmit counter | **Do not reset** | Managed by the PICC layer and retained after disconnection |

---

## 4. Method Protocol

### 4.1 Method Overview

| Method ID | Name | Direction | PICC Role | Retry | Description |
| --------- | ---- | --------- | --------- | ----- | ----------- |
| 0x01 | Consistency check | A -> M | Server | No | A core requests the M core to verify/send local data |
| 0x02 | A-core write | A -> M | Server | No | A core pushes data to M-core NVM |
| 0x03 | M-core read from A core | M -> A | Client | No | M core reads data from A core, synchronous |
| 0x04 | M-core synchronization to A core | M -> A | Client | **Yes**, 4 retries | M core pushes dirty data to A core |
| 0x05 | M-core asynchronous read from A core | M -> A | Client | No | M core reads data from A core, asynchronous |

### 4.2 Method 0x01 - Consistency Check (A -> M)

```text
Request from A core:
  Payload: [dataId_H][dataId_L]
  Length: 2 bytes

Response from M core:
  Payload: [dataId_H][dataId_L][status_H][status_H][data...]
  Length: 4 + dataLen bytes
  ReturnCode: 0x00 (OK) or 0x01 (NOT_OK)

  Status values:
    0x0000 = OK; data found and returned
    0x0001 = NOT_OK; dataId not found or block invalid
```

### 4.3 Method 0x02 - A-Core Write to M Core (A -> M)

```text
Request from A core:
  Payload: [dataId_H][dataId_L][data...]
  Length: 2 + dataLen bytes

Response from M core:
  Payload: [dataId_H][dataId_L][status_H][status_L]
  Length: 4 bytes
  ReturnCode: 0x00 (OK) or 0x01 (NOT_OK)

  Status values:
    0x0000 = OK; data has been written to NVM
    0x0001 = NOT_OK; invalid dataId, length mismatch, or EEPROM fault
```

### 4.4 Method 0x04 - M-Core Synchronization to A Core (M -> A, with Retry)

```text
Request from M core:
  Payload: [dataId_H][dataId_L][data...]
  Length: 2 + dataLen bytes
  PICC MethodType: PICC_METHOD_WITH_RESPONSE

Response from A core:
  ReturnCode + Payload, with an application-defined format

  M-core response handling policy, protocol section 2.2.2:
  +------------------------------+------------------------------------------------+
  | A-core response              | Action                                         |
  +------------------------------+------------------------------------------------+
  | ReturnCode=OK                | Synchronization succeeds: clear dirty and      |
  | + payload status OK          | release slot                                   |
  | ReturnCode=OK                | retryCount++; retry with stepped backoff       |
  | + payload status NOT_OK      | (100 -> 200 -> 400 -> 800 ms)                  |
  | ReturnCode!=OK               | retryCount++; retry with stepped backoff       |
  | (NOT_OK / NOT_READY)         |                                                |
  | No response (timeout)        | retryCount++; retry with stepped backoff       |
  | Retries exhausted            | Mark as failed: clear dirty + release slot.    |
  | (retryCount >= MAX)          | Do not reselect the same block in this cycle,  |
  |                              | preventing 10 ms storm-style retransmission.   |
  |                              | The A-core periodic consistency check (0x01)   |
  |                              | marks it dirty again and triggers a new sync.  |
  +------------------------------+------------------------------------------------+

Success criteria, data integrity:
  - Primary signal: protocol-layer ReturnCode in the IPC header == PICC_RET_OK
  - Secondary signal: payload business status == 0x0000. Two encodings are supported:
      * len >= 4: [dataId_H][dataId_L][status_H][status_L], echoing dataId
      * len = 2..3: [status_H][status_L], status only, matching protocol section 2.1 "response payload: 2-byte status"
      * len < 2: no business status; ReturnCode is used as the basis

Dirty flag lifecycle:
  - StmNvm_Write() sets dirty=TRUE, and dirty remains TRUE even if EEPROM write succeeds.
  - dirty is cleared by StmNvm_ClearDirty() after the A core acknowledges reception, with ReturnCode=OK and business status OK.
  - When retries are exhausted and the synchronization is marked failed, dirty is cleared to abandon this synchronization. A later consistency check marks it dirty again and retries.
  - On disconnection, dirty flags are cleared to abandon pending synchronization. After reconnection, consistency check can mark data dirty again.

Retry logic:
  - Only one 0x04 synchronization request can be in flight at a time.
  - Stepped retry intervals: 100 ms -> 200 ms -> 400 ms -> 800 ms.
  - Up to 4 retries. Timeouts and A-core failure responses are both counted as retries.
  - After retries are exhausted, the request is marked failed, dirty is cleared, and the slot is released. It is not resent immediately in the same cycle to prevent a retransmission storm.
  - Recovery path: The A-core periodic 0x01 consistency check calls StmNvm_SetAllValidDirty(), marking all valid blocks dirty and starting 0x04 synchronization again. Therefore, even if the A core keeps rejecting data, the retransmission rate is limited by the consistency-check period rather than once every 10 ms.
  - Storm prevention: At most 2 synchronization messages are sent in each 10 ms cycle.
```

### 4.5 Method 0x05 - M-Core Asynchronous Read from A Core (M -> A, No Retry)

```text
Request from M core:
  Payload: [dataId_H][dataId_L][0x00][0x00]
  Length: 4 bytes, including 2-byte dataId and 2 reserved bytes
  PICC MethodType: PICC_METHOD_WITH_RESPONSE

Response from A core:
  Processed in Stm_ProcessAppReadReq and matched by sessionId

Constraints:
  - Only one read request can be in flight at a time.
  - Failure or timeout is not retried.
  - STM must be in the RUNNING state.
```

---

## 5. NVM Layer Design

### 5.1 Storage Architecture

```text
+------------------------------------------------+
|              RAM image (g_nvmBlocks[])          |
|                                                |
|  Block 0: [data(64B)][dataLen][valid][dirty][eepromOffset] |
|  Block 1: [data(64B)][dataLen][valid][dirty][eepromOffset] |
|  Block 2: [data(64B)][dataLen][valid][dirty][eepromOffset] |
|  Block 3: [data(64B)][dataLen][valid][dirty][eepromOffset] |
|  Block 4: [data(64B)][dataLen][valid][dirty][eepromOffset] |
|                                                |
|  Read path: read directly from RAM, zero latency |
|  Write path: RAM image -> EEPROM, immediate      |
+----------------------+-------------------------+
                       | I2C, segmented transfer, <=16B each
                       v
+------------------------------------------------+
|                 I2C EEPROM                      |
|                                                |
|  Address 0x10: [magic = 0xA5]                  |
|  Address 0x11: [valid][len][data...] Block 0   |
|  Address 0x1B: [valid][len][data...] Block 1   |
|  Address 0x2D: [valid][len][data...] Block 2   |
|  Address 0x33: [valid][len][data...] Block 3   |
|  Address 0x41: [valid][len][data...] Block 4   |
|  Address 0x50: END                             |
+------------------------------------------------+
```

### 5.2 EEPROM Block Format

Each data block is stored in EEPROM with the following format:

```text
Offset   Field    Size   Description
------   -----    ----   -----------
+0       valid    1B     TRUE(1) means the block contains valid data; FALSE(0) means empty
+1       len      1B     Actual data length, 0..maxDataLen
+2       data     NB     Persistent data bytes, where N is maxDataLen in the configuration

Total size per block = 2 + maxDataLen bytes
```

### 5.3 EEPROM Address Mapping

| EEPROM Address | Content | Size |
| -------------- | ------- | ---- |
| `0x10` | Magic byte (0xA5) | 1B |
| `0x11` ~ `0x50` | Data area, 5 blocks | 64B |

### 5.4 Data Item Configuration

Current configuration: 5 data items, total 58B <= 64B.

| Index | dataId | maxDataLen | EEPROM Size | Example Use |
| ----- | ------ | ---------- | ----------- | ----------- |
| 0 | 0x0001 | 8 | 2+8=10 | Calibration data |
| 1 | 0x0002 | 16 | 2+16=18 | Configuration block |
| 2 | 0x0003 | 4 | 2+4=6 | Status flag |
| 3 | 0x0004 | 12 | 2+12=14 | Sensor offset |
| 4 | 0x0005 | 8 | 2+8=10 | Runtime parameter |
|   |        | **Total** | **58** | |

### 5.5 Initialization Flow

```text
StmNvm_Init()
     |
     +-- memset(g_nvmBlocks, 0)          <- Clear all RAM image blocks
     |
     +-- StmNvm_ComputeOffsets()         <- Allocate EEPROM offsets according to configuration
     |
     +-- Eeprom_ReadBytes(0x10, &magic)  <- Read magic byte
     |
     +-- magic != 0xA5 ?                 <- First power-on or EEPROM corrupted?
     |    |
     |    +-- Yes -> StmNvm_FormatEeprom() <- Write magic and clear all blocks
     |
     +-- magic == 0xA5                   <- EEPROM valid
          |
          +-- For each block: StmNvm_ReadBlockFromEeprom()
                        +-- Read [valid][len] header, 2B
                        +-- Check len <= maxDataLen
                        +-- If valid and len > 0: read data
```

### 5.6 Write Path: Local Write or Write from A Core

```text
StmNvm_Write() / StmNvm_WriteFromA()
     |
     +-- Check: NVM ready, data != NULL, len <= maxDataLen
     |
     +-- memcpy(data) to RAM image       <- Immediate update
     |
     +-- Set valid=TRUE, dirty=TRUE      <- Mark as pending synchronization to A core
     |
     +-- StmNvm_WriteBlockToEeprom()     <- Persist to EEPROM
     |    +-- Write [valid][len] header, 2B
     |    +-- Write data in <=16B segments <- I2C transaction size limit
     |
     +-- EEPROM success: dirty remains TRUE <- Data is locally persistent but still needs synchronization to A core
                                                dirty is cleared only after A-core acknowledgement by StmNvm_ClearDirty()
```

### 5.7 Read Path: Local Read

```text
StmNvm_Read()
     |
     +-- Check: NVM ready, data != NULL, block valid
     |
     +-- memcpy from RAM image           <- Zero latency, no EEPROM access required
```

### 5.8 Cooperative Management of Local RAM and EEPROM

To meet high real-time read requirements and ensure reliable persistence of key data, the STM module uses a cooperative management model of **"RAM image cache + real-time EEPROM persistence + asynchronous inter-core synchronization"**.

#### 5.8.1 RAM Image and Zero-Latency Reads

- **Design purpose**: I2C EEPROM is a slow peripheral. If every read triggers a hardware bus transfer, the task may block and incur very high latency.
- **Structure definition**: A static global RAM image array `g_nvmBlocks[STM_MAX_DATA_ITEMS]` of type `Stm_NvmBlock_t` is allocated. Each data block in memory contains local cached `data`, current `dataLen`, `valid` flag, `dirty` flag, and the automatically calculated `eepromOffset`.
- **Read mechanism**: All `StmNvm_Read()` operations access only the RAM image and return directly through `memcpy` at microsecond level, achieving **zero hardware latency**.

#### 5.8.2 Physical EEPROM Layout and Baseline Validation

- **Physical start address**: The magic byte is located at `0x10`, and the data area starts at `0x11`, with an upper limit of 64 bytes of data space.
- **Continuous automatic allocation**: During initialization, EEPROM address offsets are accumulated and allocated according to each `dataId` and its `maxDataLen` in the configuration table, using the format `[valid(1B)] + [len(1B)] + [data(NB)]`.
- **First power-on formatting**: `StmNvm_Init()` reads physical address `0x10`. If the magic byte is not `0xA5`, EEPROM is considered uninitialized or corrupted. `StmNvm_FormatEeprom()` is called automatically to write the magic byte and clear the EEPROM storage area and RAM image. If the value is `0xA5`, persistent data is loaded into the RAM image through `StmNvm_ReadBlockFromEeprom()`.

#### 5.8.3 Physical EEPROM Segmented Write

- **Hardware driver transaction limit**: The physical I2C EEPROM driver limits the maximum number of bytes in a single bus transaction (`EEPROM_WRITE_MAX_LEN` = 16 bytes), so a data packet cannot be sent in one transaction.
- **Two-stage segmented transfer**:
  1. **Stage 1, header**: Write the 2-byte `[valid, dataLen]` header to the physical start address of the corresponding EEPROM data block.
  2. **Stage 2, payload**: Calculate the actual data length, then use the static safe buffer `s_writeBuf[16]` to call the I2C write interface in segments of up to 16 bytes each until all data is written to the physical medium. This prevents stack overflow and matches the driver limit.

#### 5.8.4 Dirty Flag State and Lifecycle

The `dirty` flag is the key medium for **asymmetric data synchronization** between the M core and A core. Its state transitions follow strict rules:

1. **Local write (M -> EEPROM)**: When the application calls `Stm_WriteLocal()`, data is copied to RAM, `dirty` is set to `TRUE`, and physical EEPROM persistence starts immediately. After the EEPROM write succeeds, **`dirty` remains `TRUE`**, indicating that the data has been locally persisted but has not yet been sent to the A core through Method 0x04.
2. **Inter-core synchronization complete (Method 0x04 succeeds)**: When `Stm_ProcessSyncToA()` successfully sends dirty block data to the A core and receives an A-core response with protocol-layer `ReturnCode=OK` **and** business status `0x0000`, it calls `StmNvm_ClearDirty()` to set `dirty` to `FALSE`.

   **Synchronization failure handling, storm prevention**: If a timeout occurs or the A core returns failure, STM retries with stepped intervals (100 -> 200 -> 400 -> 800 ms), up to 4 retries. **After all retries are exhausted, the request is marked failed**, and `StmNvm_ClearDirty()` is also called to clear the block's dirty flag and release the in-flight slot. This is critical: if `dirty=TRUE` remains after retries are exhausted, the polling scan will immediately select the same block again in the next 10 ms cycle and issue `PICC_MethodRequest` again, creating an infinite storm when the A core continuously returns malformed data or non-OK responses. After a failure is marked, resynchronization is driven by the A-core **periodic consistency check (Method 0x01)**. `Stm_HandleConsistencyCheck()` calls `StmNvm_SetAllValidDirty()` after receiving a valid 0x01 request, marking data dirty again and limiting retransmission frequency to the consistency-check period.
3. **A-core active overwrite (WriteFromA)**: When the A core actively writes data to the M core through Method 0x02, the data originates from the A core. Therefore, after the M core successfully stores the data in RAM + EEPROM, it **explicitly clears the dirty flag immediately (`dirty = FALSE`)** to avoid unnecessary Method 0x04 synchronization back to the A core.
4. **Disconnection (ResetOnDisconnect)**: If the link disconnects or heartbeat times out, the M core calls `StmNvm_ResetOnDisconnect()` to **force all block `dirty` flags to zero** to prevent data-flow disorder after reconnection. The local data in the RAM image and physical EEPROM remains valid.

---

## 6. Subtask Design

### 6.1 Subtask Execution Matrix

| Subtask | SYNC_TO_A | RUNNING | Period | Description |
| ------- | --------- | ------- | ------ | ----------- |
| `Stm_CheckLinkState()` | No | Yes | 10 ms | Monitors both PICC links |
| `Stm_ProcessRxFromA()` | Yes | Yes | 10 ms | Handles Method 0x01/0x02 |
| `Stm_ProcessSyncToA()` | Yes | Yes | 10 ms | Synchronizes dirty data through Method 0x04 |
| `Stm_ProcessAppReadReq()` | No | Yes | 10 ms | Handles Method 0x03/0x05 responses |

### 6.2 Stm_ProcessSyncToA Retry Flow

```text
Stm_ProcessSyncToA()
     |
     +-- Is a retry in progress (Stm_RetryState.active)?
     |    |
     |    +-- retryCount >= MAX?
     |    |    +-- Mark failed: clear dirty + release slot, do not reselect immediately; wait for consistency check
     |    |
     |    +-- Response received?
     |    |    +-- ReturnCode=OK and payload status OK -> clear dirty, release slot
     |    |    +-- Otherwise, ReturnCode!=OK / status NOT_OK / invalid payload
     |    |        -> retryCount++, tickCounter=0, counted as retry with stepped backoff
     |    |
     |    +-- tickCounter < interval[retryCount]? -> Wait
     |    |
     |    +-- Interval elapsed? -> retryCount++, resend
     |
     +-- Storm prevention: syncCount >= 2? -> Skip this cycle
     |
     +-- Find the next dirty block, round-robin scan
          |
          +-- Found? -> Build payload, PICC_MethodRequest(0x04), set retry state, advance scan index
          |
          +-- Not found? -> Reset scan index to 0
```

### 6.3 Retry Interval Table

| Retry Index | Interval | Tick Count, 10 ms |
| ----------- | -------- | ----------------- |
| 0, first try | 100 ms | 10 |
| 1 | 200 ms | 20 |
| 2 | 400 ms | 40 |
| 3 | 800 ms | 80 |

Maximum retry count: **4 retries**. Timeouts and A-core failure responses are both counted. After retries are exhausted, the synchronization is **marked failed**: the block's dirty flag is cleared and the slot is released. The same block is not reselected immediately in the same cycle, preventing storm-style retransmission every 10 ms. Local RAM/EEPROM data is always retained. Resynchronization is triggered by the A-core **periodic consistency check (0x01)**, which marks data dirty again through `StmNvm_SetAllValidDirty()`.

---

## 7. Session ID Management

### 7.1 Rules

- **Range**: 0x01 to 0xFF. After reaching 0xFF, wrap around to 0x01. 0x00 is never used.
- **Scope**: Global within the STM module, not per Provider.
- **Reset on disconnection**: Yes, as required by the protocol.
- **Use case**: Asynchronous Method requests only, 0x03 and 0x05.

### 7.2 Matching Logic

```text
M core sends:   PICC_MethodRequest() -> returns sessionId
M core stores:  Stm_PendingReadReq.sessionId = sessionId
M core polls:   PICC_GetResponseData(sessionId) -> matches response
```

---

## 8. Integration Points

### 8.1 Initialization Sequence

In `EcuM_main_init.c` -> `App_Init_All()`:

```c
Hm_Init();
Stm_Init();    // Add after Hm_Init()
```

### 8.2 Task Integration

In `Ostask_main.c` -> `TASK_M0_10MS`:

```c
Hm_Main();
Stm_Main();    // Add after Hm_Main()
```

### 8.3 PICC App Index Mapping

| Index | Enum | Module |
| ----- | ---- | ------ |
| 0 | `PICC_APP_PWSM_SRV` | Power management server |
| 1 | `PICC_APP_PWSM_CLI` | Power management client |
| 2 | `PICC_APP_DIAG` | Diagnostics |
| **3** | **`PICC_APP_STM_CLI`** | **STM Consumer (client)** |
| 4 | `PICC_APP_STORAGE` | STM Provider (server) |

### 8.4 PICC Receive Buffer

In `picc_mailbox.c`, `PICC_RX_MAX_DATA_LEN` is increased from **32** to **80** bytes to support a maximum 64-byte NVM block plus protocol header overhead.

### 8.5 Task Stack

In `Ostask_main.c`, `OSTASK_10MS_STACK_SIZE` is increased from **256** to **320** words to accommodate `Stm_Main()` processing.

---

## 9. Data Flow Examples

### 9.1 Local Write + Synchronization to A Core

```text
Application calls Stm_WriteLocal(0x0003, data, 4)
     |
     +-- StmNvm_Write(0x0003, data, 4)
     |    +-- Update RAM image
     |    +-- dirty = TRUE
     |    +-- Write EEPROM, segmented
     |    +-- dirty remains TRUE after EEPROM success, because data still needs synchronization to A core
     |
     +-- In the next 10 ms cycle in Stm_Main()
        |
        +-- Stm_ProcessSyncToA() finds dirty block
           +-- Build payload: [0x00][0x03][data...]
           +-- PICC_MethodRequest(0x04)
           +-- Set retry state

     A-core response arrives
        |
        +-- StmNvm_ClearDirty(0x0003)
```

### 9.2 A-Core Write to M Core

```text
A core sends Method 0x02: [0x00][0x01][8 bytes of data]
     |
     +-- Stm_ProcessRxFromA()
        +-- Parse dataId=0x0001, dataLen=8
        +-- StmNvm_WriteFromA(0x0001, data, 8)
        |    +-- Update RAM image + EEPROM
        |    +-- dirty = TRUE, later synchronized back to A core
        |
        +-- PICC_MethodResponse(0x00, [0x00][0x01][0x00][0x00])
```

### 9.3 Disconnection -> Reconnection Sequence

```text
1. Link disconnects, caused by heartbeat timeout or disconnect notification.
2. Stm_CheckLinkState() detects the disconnected link.
3. State -> WAIT_LINK.
4. Reset operations:
   - StmNvm_ResetOnDisconnect() -> clear dirty flags and retain data.
   - Stm_ResetSessionId() -> sessionId = 0.
   - Cancel retry and pending requests.
5. PICC automatically sends link requests, client role.
6. Both links reconnect -> WAIT_CONSISTENCY.
7. A core sends Method 0x01 consistency-check request, Payload=0x0000.
8. M core passes readiness validation, replies with success response ([0x0000]+[0x0000]), and calls StmNvm_SetAllValidDirty() to mark all valid blocks dirty.
9. State -> SYNC_TO_A; M core actively synchronizes all dirty data through Method 0x04.
10. Synchronization completes; state -> RUNNING; normal operation begins.
```

---

## 10. Configuration Guide

### 10.1 Adding a New Data Item

1. **Increase `STM_MAX_DATA_ITEMS`** in `stm_cnf.h` if the number of items becomes greater than 5.
2. **Add an entry** in `g_StmDataItemCfg[]` in `stm_cnf.c`:

   ```c
   { 0x0006U, 4U  },  /* Data item 6: new data */
   ```

3. **Validate EEPROM capacity**: `SUM(2 + maxDataLen) <= 64`.
4. If more space is required, **adjust `STM_EEPROM_DATA_END_ADDR`**.
5. If the maximum payload exceeds 80 bytes, **increase `PICC_RX_MAX_DATA_LEN`**.

### 10.2 Modifying Retry Behavior

Modify the following parameters in `stm_cnf.h` / `stm_cnf.c`:

| Parameter | File | Default | Description |
| --------- | ---- | ------- | ----------- |
| `STM_RETRY_MAX_COUNT` | `stm_cnf.h` | 4 | Maximum retries for Method 0x04 |
| `g_StmRetryIntervals[]` | `stm_cnf.c` | {10,20,40,80} | Retry intervals in 10 ms ticks |
| `STM_SYNC_MAX_PER_CYCLE` | `stm_cnf.h` | 2 | Maximum synchronization messages per 10 ms cycle |

### 10.3 Modifying PICC IDs

Modify the following parameters in `stm_cnf.h`:

| Parameter | Default | Description |
| --------- | ------- | ----------- |
| `STM_PROVIDER_ID` | 41 (0x29) | M-core server ID, must be unique in the whole system |
| `STM_CONSUMER_ID` | 42 (0x2A) | M-core client ID, must be unique in the whole system |
| `STM_PROVIDER_REMOTE_ID` | 46 (0x2E) | A-core server ID for M-core client communication |
| `STM_CONSUMER_REMOTE_ID` | 47 (0x2F) | A-core client ID for communication with the M-core server |

---

## 11. Known Limitations and To-Do Items

| # | Item | Status | Description |
| - | ---- | ------ | ----------- |
| 1 | `WAIT_CONSISTENCY` state | **Implemented** | After link establishment, STM waits for the A core to issue the 0x01 consistency check. After validation passes, SetAllValidDirty is called to trigger 0x04 active synchronization. |
| 2 | Method 0x03, M-core synchronous read from A core | **Not fully implemented** | Currently only 0x05, asynchronous, is used. 0x03 response parsing remains to be implemented. |
| 3 | Read request timeout | **Implemented** | If the A core never responds, the request remains pending until disconnection. |
| 4 | EEPROM write error recovery | **Basic** | Returns E_NOT_OK, but EEPROM write is not retried. |
| 5 | After Method 0x04 maximum retries | **Marked failed** | Clears dirty and releases the slot to prevent a 10 ms storm. Local data is retained. Periodic 0x01 consistency check marks it dirty again and retries. |
| 6 | Multiple concurrent synchronization requests | **Not supported** | Only one 0x04 synchronization can be in flight at a time. |

---

## 12. Stack Usage Considerations

All large buffers in `stm.c` and `stm_nvm.c` are declared as `static` to avoid stack overflow:

| Variable | File | Size | Reason |
| -------- | ---- | ---- | ------ |
| `s_methodBuf` | stm.c | 68B | Method 0x01/0x02 receive buffer |
| `s_respBuf` | stm.c | 68B | Method 0x01/0x02 transmit buffer |
| `s_syncBuf` | stm.c | 68B | Synchronization 0x04 receive buffer |
| `s_txPayload` | stm.c | 66B | Synchronization 0x04 transmit payload |
| `s_reqPayload` | stm.c | 4B | Read 0x05 request payload |
| `s_readRspBuf` | stm.c | 68B | Read 0x03/0x05 response buffer |
| `s_writeBuf` | stm_nvm.c | 16B | EEPROM segmented-write buffer |

**Task stack**: `OSTASK_10MS_STACK_SIZE = 320 words (1.25 KB)`, sufficient for all STM processing.
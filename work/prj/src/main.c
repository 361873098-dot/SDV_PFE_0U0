/*
 *  (c) Copyright 2006-2016 Freescale Semiconductor, Inc.
 *  Copyright 2017, 2019-2024 NXP
 *
 *  NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only
 *  be used strictly in accordance with the applicable license terms. By
 *  expressly accepting such terms or by downloading, installing, activating
 *  and/or otherwise using the software, you are agreeing that you have read,
 *  and that you agree to comply with and are bound by, such license terms. If
 *  you do not agree to be bound by the applicable license terms, then you may
 *  not retain, install, activate or otherwise use the software.
 *
 *  This file contains sample code only. It is not part of the production code deliverables.
 */

#ifdef __cplusplus
extern "C"{
#endif
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "typedefs.h"

#include "sample_app_ethswt_data_definition.h"
#include "eth_init.h"
#include "sample_app_ethswt_task_2_send_frames.h"
#include "sample_app_ethswt_task_1_get_counters.h"
#include "Mcal.h"
#include "CDD_Mcl.h"
#include "oal_util_autosar.h"
#include "os_task.h"
#include "sys_init.h"
#include "Eth_43_PFE_Irq.h"
#include "Eth_43_PFE.h"
#include "Platform.h"
#include "Dio.h"
#include "Serdes.h"
#include "SchM_Serdes.h"


#ifdef PING_TEST
#include "eth_queue.h"
#endif
#ifdef LWIP
#include "lwip_main.h"
#endif

#ifdef PFE_CFG_FCI_ENABLE
#include "sample_app_fci.h"
#endif /* PFE_CFG_FCI_ENABLE */

#include "mpu_configuration.h"

#if STD_ON == ETH_43_GET_PFE_STATISTIC_API
#include "pfe_platform.h"
#endif /* ETH_43_GET_PFE_STATISTIC_API */

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef PING_TEST
/* Hardware type */
#define ARP_HARDWARE_TYPE_ETH   0x0001U
/* Protocol type */
#define ARP_PROTOCOL_TYPE_IPV4  0x0800U
/* Hardware address length */
#define ARP_HARDWARE_ADDR_LEN   0x06U
/* Protocol address length */
#define ARP_PROTOCOL_ADDR_LEN   0x04U
/* Opcode arp reply */
#define ARP_OPCODE_ARP_REPLY    0x02U
/* Echo reply type */
#define ICMP_TYPE_ECHO_REPLY    0U
/* Ethernet type IPv4 */
#define ETHER_TYPE_IPV4         0x0800U
/* Ethernet type ARP */
#define ETHER_TYPE_ARP          0x0806U
/* Protocol type ICMP */
#define PROTOCOL_TYPE_ICMP      0x01U
/* IPv4 Version */
#define IPV4_VERSION            0x04U
/* IPv4 header length */
#define IPV4_HEADER_LENGTH      0x05U
/* IPv4 type of service */
#define IPV4_TYPE_OF_SERVICE    0U
#endif

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#ifdef NXP_LOG_ENABLED

    #define ETH_43_PFE_START_SEC_VAR_CLEARED_8
    #include "Eth_43_PFE_MemMap.h"

    /* This array contains debug messages, one message on each line */
    /* In trace32, use this command to display them: data.dump debug_buff /ascii /nohex */
    VAR_ALIGN(char debug_buff[NXP_LOG_ASR_CFG_LINE_COUNT][NXP_LOG_ASR_CFG_LINE_SIZE] = {{0}}, NXP_LOG_ASR_CFG_LINE_SIZE)

    #define ETH_43_PFE_STOP_SEC_VAR_CLEARED_8
    #include "Eth_43_PFE_MemMap.h"

    #define ETH_43_PFE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    #include "Eth_43_PFE_MemMap.h"

    uint32 debug_line = 0U;

    #define ETH_43_PFE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    #include "Eth_43_PFE_MemMap.h"

#endif

#ifdef PING_TEST
/**
 * @brief ARP packet
 **/
typedef struct __attribute__((packed, aligned(4)))
{
   uint16_t hrd;                /* Hardware type */
   uint16_t pro;                /* Protocol type */
   uint8_t hln;                 /* Hardware address length */
   uint8_t pln;                 /* Protocol address length */
   uint16_t op;                 /* Opcode, 1 = ARP request, 2 = ARP reply */
   uint8_t sha[6];              /* Sender hardware address */
   uint32_t spa;                /* Sender protocol address */
   uint8_t tha[6];              /* Target hardware address */
   uint32_t tpa;                /* Target protocol address */
} arp_packet_t;

/**
 * @brief IPv4 header
 **/
typedef struct __attribute__((packed, aligned(4)))
{
   uint8_t header_length : 4;   /* Internet header length */
   uint8_t version : 4;         /* Version */
   uint8_t type_of_service;     /* Type of service */
   uint16_t total_length;       /* Total length */
   uint16_t identification;     /* Indentification */
   uint16_t fragment_offset;    /* Fragment offset */
   uint8_t time_to_live;        /* Time to live */
   uint8_t protocol;            /* Protocol */
   uint16_t header_checksum;    /* Header checksum */
   uint32_t src_addr;           /* Source IP adress */
   uint32_t dest_addr;          /* Destination address */
   uint8_t options[];           /* Options */
} ipv4_header_t;


/**
 * @brief ICMP Echo Request and Reply messages
 **/

typedef struct
{
   uint8_t type;                /* Type of message */
   uint8_t code;                /* Code */
   uint16_t checksum;           /* Checksum */
   uint16_t identifier;         /* Identifier */
   uint16_t sequence_number;    /* Sequence number */
   uint8_t payload[];           /* The payload of packet */
} icmp_echo_message_t;

#endif

/**
 * @brief debug log and statistics
 * @details rxCtr[] Number of received frames per controller
 *          txCtr[] Number of transmitted frames per controller
 *          tx_confCtr[] Number of successfully transmitted frames in case the interrupt is not used
 *          tx_errCtr[] Number of frames that cannot be transmitted
 **/
typedef struct{
    bool_t initialized;
    uint32_t version;
    struct{
        uint32_t addr;
        uint32_t line_write_addr;
        uint32_t line_len;
        uint32_t line_num;
    } debug_buf;
    struct{
        uint32_t rxCtr[8];
        uint32_t txCtr[8];
        uint32_t tx_confCtr[8];
        uint32_t tx_errCtr[8];
    } counter;
} app_debug_info_t;


#define ETH_43_PFE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

extern uint32 __SHARED_LOG_STATISTICS[];

volatile app_debug_info_t *app_debug_info_ptr = (volatile app_debug_info_t *) __SHARED_LOG_STATISTICS;

volatile uint32_t *pfeRxCtr;
volatile uint32_t *pfeTxCtr;
volatile uint32_t *pfeTxConfCtr;
volatile uint32_t *pfeTxErrorCtr;

#define ETH_43_PFE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

/* Structures for EMAC statistics */
#if STD_ON == ETH_43_GET_COUNTER_API
    Eth_CounterType pfeCounterValues;
#endif /* STD_ON == ETH_43_GET_COUNTER_API */
#if STD_ON == ETH_43_GET_RXSTATS_API
    Eth_RxStatsType pfeRxStats;
#endif /* STD_ON == ETH_43_GET_RXSTATS_API */
#if STD_ON == ETH_43_GET_TXSTATS_API
    Eth_TxStatsType pfeTxStats;
#endif /* STD_ON == ETH_43_GET_TXSTATS_API */
#if STD_ON == ETH_43_GET_TXERROR_COUNTER_API
    Eth_TxErrorCounterValuesType pfeTxErrorCounterValues;
#endif /* STD_ON == ETH_43_GET_TXERROR_COUNTER_API */

#if STD_ON == ETH_43_GET_CLASS_STATISTIC_API
static pfe_ct_classify_stats_t pfeStatsClass;
#endif /* ETH_43_GET_CLASS_STATISTIC_API */

#if STD_ON == ETH_43_GET_PFE_STATISTIC_API
static Eth_43_PFE_TmuStatsType pfeStatsTmu;
static pfe_ct_conntrack_stats_t pfeStatsConntrack;
static pfe_ct_vlan_stats_t pfeStatsVlan;
static Eth_43_PFE_L2BridgeStatsType pfeStatsL2Br;
static Eth_43_PFE_WdtStatsType pfeStatsWdt;
static Eth_43_PFE_GpiStatsType pfeStatsGpi[PFE_GPI_INSTANCES];
static Eth_43_PFE_BmuStatsType pfeStatsBmu[PFE_BMU_INSTANCES];
#endif /* ETH_43_GET_PFE_STATISTIC_API */

#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_VAR_INIT_8_NO_CACHEABLE
#include "Eth_43_PFE_MemMap.h"

/* Trigger for reading controller statistics. */
/* Set it with the debugger to the index of required controller. */
volatile uint8 getStatisticsFromCtrl = NUM_CONTROLLER_USED;

#define ETH_43_PFE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#ifdef LWIP
uint32_t g_sys_milliseconds;
#endif
/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#if defined(CONFIG_MINIHIF)
    extern void configure_minihif_hw(void);
#endif
void GetStatistics(void);
uint32_t ipv4_string_to_int(const char *p_ip_addr);
#if defined(PING_TEST)
static boolean send_frame(uint8_t *data, uint16_t ether_type, uint16_t data_length, uint8_t iface, uint8_t *target_mac);
#endif
/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
/* Convert an IPv4 address character string to an integer. */
uint32_t ipv4_string_to_int(const char *p_ip_addr)
{
    uint32_t val = 0;
    uint8_t i;          /* The count of the number of bytes processed. */
    const char *str;    /* A pointer to the next digit to process. */
    char c;             /* The digit being processed. */
    uint16_t n;         /* The value of this byte. */

    str = p_ip_addr;
    if (NULL != p_ip_addr)
    {
        for (i = 0; i < 4; i++)
        {
            n = 0;
            while (1)
            {
                c = *str;
                str++;
                if (c >= '0' && c <= '9')
                {
                    n *= 10;
                    n += c - '0';
                }
                else if ((i < 3 && c == '.') || i == 3)
                {
                    break;
                }
                else
                {
                    return 0;
                }
            }
            if (n >= 256)
            {
                return 0;
            }
            val *= 256;
            val += n;
        }
    }
    return val;
}

#if defined(PING_TEST)
static boolean send_frame(uint8_t *data, uint16_t ether_type, uint16_t data_length, uint8_t iface, uint8_t *target_mac)
{
    Eth_BufIdxType buf_idx;
    Eth_DataType *buf_ptr;
    uint16 temp_length = data_length;
    BufReq_ReturnType buf_status;
    uint32_t ctr;
    bool_t ret = TRUE;

    /* Get buffer */
    buf_status = Eth_43_PFE_ProvideTxBuffer(iface, 0U, &buf_idx, &buf_ptr, &temp_length);
    if (BUFREQ_OK != buf_status)
    {
        ret = FALSE;
    }
    if (temp_length < data_length)
    {
        ret = FALSE;
    }
    /* Fill buffer */
    for (ctr = 0U; ctr < data_length; ctr++)
    {
        buf_ptr[ctr] = (Eth_DataType)data[ctr];
    }

    /* Transmit the data */
    Eth_43_PFE_Transmit(iface, buf_idx, ether_type, TRUE, data_length, target_mac);
    NXP_LOG_INFO("Transmitted a frm on PFE%hhu, buffer 0x%lx", (uint8)iface, buf_idx);
    pfeTxCtr[iface]++;

    return ret;
}

void rx_process(uint8 ctrl_idx, uint8 *phys_addr_ptr, Eth_DataType *p_rx_data, uint16 len_byte)
{
    queue_elm_info_t new_data;
    Eth_FrameType ether_type;
    uint8_t Protocol = 0;
    arp_packet_t *p_arp_request;
    arp_packet_t *p_arp_reply;
    ipv4_header_t *p_packet;
    ipv4_header_t *p_ip_header;
    icmp_echo_message_t *p_icmp_request_header;
    icmp_echo_message_t *p_icmp_reply_header;
    uint8_t src_mac[6];
    static arp_packet_t arp_buffer;
    static uint8_t ipv4_header_buffer[1500];
    char *p_ip_addr = NULL;
    uint32_t ip_local_addr;
    uint32_t payload_length;

    /* Prepare the MAC address of this device */
    Eth_43_PFE_GetPhysAddr(ctrl_idx, &src_mac[0]);

    /* Local IP address for each controller */
    switch(ctrl_idx){
        case 0U: p_ip_addr = IPV4_LOCAL_IP_ADDR_0; break;
        case 1U: p_ip_addr = IPV4_LOCAL_IP_ADDR_1; break;
        case 2U: p_ip_addr = IPV4_LOCAL_IP_ADDR_2; break;
        default: p_ip_addr = NULL; break;
    }
    ip_local_addr = ipv4_string_to_int(p_ip_addr);

    if (NULL != p_rx_data)
    {
        ether_type = be16_to_cpu(*(Eth_FrameType *)(p_rx_data - 2U));
        /* Check if received frame is ARP */
        if (ether_type == ETHER_TYPE_ARP)
        {
            p_arp_request = (arp_packet_t *)p_rx_data;
            /* Check if dest ip address matches local ip address */
            if (ip_local_addr == oal_htonl(p_arp_request->tpa))
            {
                /*  Initialize the arp reply buffer */
                p_arp_reply = &arp_buffer;
                (void)autolibc_memset(p_arp_reply, 0, sizeof(arp_packet_t));
                /* Format ARP request */
                p_arp_reply->hrd = oal_htons(ARP_HARDWARE_TYPE_ETH);
                p_arp_reply->pro = oal_htons(ARP_PROTOCOL_TYPE_IPV4);
                p_arp_reply->hln = ARP_HARDWARE_ADDR_LEN;
                p_arp_reply->pln = ARP_PROTOCOL_ADDR_LEN;
                p_arp_reply->op = oal_htons(ARP_OPCODE_ARP_REPLY);
                p_arp_reply->spa = p_arp_request->tpa;
                p_arp_reply->tpa = p_arp_request->spa;
                (void)autolibc_memcpy(p_arp_reply->sha, src_mac, 6U);
                (void)autolibc_memcpy(p_arp_reply->tha, p_arp_request->sha, 6U);
                /* Update new data for sending ethernet frame */
                new_data.ctrl_idx = ctrl_idx;
                new_data.phys_addr_ptr = phys_addr_ptr;
                new_data.data_ptr = (Eth_DataType *)p_arp_reply;
                new_data.ether_type = ether_type;
                new_data.len_byte = len_byte;
                if (!queue_is_full())
                {
                    queue_push(new_data);
                }
            }
        }
        /* Check if received frame is IPv4 */
        if (ether_type == ETHER_TYPE_IPV4)
        {
            Protocol = (*(uint8_t *)(p_rx_data + 9U));
            /* Check if protocol of received frame is ICMP */
            if(Protocol == PROTOCOL_TYPE_ICMP)
            {
                p_ip_header = (ipv4_header_t *)p_rx_data;
                /* Check if dest ip address matches local ip address */
                if (ip_local_addr == oal_htonl(p_ip_header->dest_addr))
                {
                    /*  Initialize the ipv4 header buffer */
                    p_packet = (ipv4_header_t *)&ipv4_header_buffer;
                    (void)autolibc_memset(p_packet, 0, sizeof(ipv4_header_t));
                    /* Format IPv4 header */
                    p_packet->version = IPV4_VERSION;
                    p_packet->header_length = IPV4_HEADER_LENGTH;
                    p_packet->type_of_service = IPV4_TYPE_OF_SERVICE;
                    p_packet->total_length = oal_htons(len_byte);
                    p_packet->identification = p_ip_header->identification;
                    p_packet->fragment_offset = p_ip_header->fragment_offset;
                    p_packet->time_to_live = p_ip_header->time_to_live;
                    p_packet->protocol = p_ip_header->protocol;
                    p_packet->header_checksum = 0;
                    p_packet->src_addr = p_ip_header->dest_addr;
                    p_packet->dest_addr = p_ip_header->src_addr;

                    /* Get ICMP packet */
                    p_icmp_request_header = (icmp_echo_message_t *)( &p_rx_data[sizeof(ipv4_header_t)]);
                    /*  Initialize the ICMP reply header buffer */
                    p_icmp_reply_header = (icmp_echo_message_t *)&ipv4_header_buffer[sizeof(ipv4_header_t)];
                    (void)autolibc_memset(p_icmp_reply_header, 0, sizeof(icmp_echo_message_t));
                    /* Format Echo Reply header */
                    p_icmp_reply_header->type = ICMP_TYPE_ECHO_REPLY;
                    p_icmp_reply_header->code = 0;
                    p_icmp_reply_header->checksum = 0;
                    p_icmp_reply_header->identifier = p_icmp_request_header->identifier;
                    p_icmp_reply_header->sequence_number = p_icmp_request_header->sequence_number;
                    /* The length of the ICMP payload */
                    payload_length = len_byte - (sizeof(ipv4_header_t) + sizeof(icmp_echo_message_t));
                    (void)autolibc_memcpy(p_icmp_reply_header->payload, p_icmp_request_header->payload, payload_length);
                    /* Update new data for sending ethernet frame */
                    new_data.ctrl_idx = ctrl_idx;
                    new_data.phys_addr_ptr = phys_addr_ptr;
                    new_data.data_ptr = (Eth_DataType *)p_packet;
                    new_data.ether_type = ether_type;
                    new_data.len_byte = len_byte;
                    if (!queue_is_full())
                    {
                        queue_push(new_data);
                    }
                }
            }
        }
    }
}

void rx_callback(uint8 ctrl_idx, Eth_FrameType frame_type, boolean is_broadcast,
                    uint8 *phys_addr_ptr, Eth_DataType *p_rx_data, uint16 len_byte)
{
    (void)is_broadcast;
    (void)phys_addr_ptr;
    (void)frame_type;

#if (PFE_CFG_VERBOSITY_LEVEL >= 9)
    NXP_LOG_INFO("Received on PFE%hhu, type 0x%hx, length %hu, data %02hhx %02hhx %02hhx %02hhx %02hhx...", (uint8)ctrl_idx, (uint16)frame_type, len_byte, p_rx_data[0U], p_rx_data[1U], p_rx_data[2U], p_rx_data[3U], p_rx_data[4U]);
#endif
    rx_process(ctrl_idx, phys_addr_ptr, p_rx_data, len_byte);
}
#endif

int main(void)
{
    Std_ReturnType ret = E_OK;
#if defined(PING_TEST)
    queue_elm_info_t queue_data;
#endif
#ifdef LWIP
    uint32_t last_tick = 0;
#endif
    /* Fully configure the MPU. This needs to be disabled in startup code and done here
         as the startup code for MPU configuration is not compatible with new memory map */
#if (STD_ON == ETH_43_PFE_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call(Mpu_Configuration);
#else
    Mpu_Configuration();
#endif /* STD_ON == ETH_43_PFE_ENABLE_USER_MODE_SUPPORT */
    /* Initialize MCAL drivers */
    ret = SampleAppInitTask();
    /* Trap the application when there was an error during init */
    while (E_OK != ret)
    {
        ;
    }
//    Sys_Init();
#if defined(PING_TEST)
    /* Init queue */
    queue_init();
#endif

#if defined(CONFIG_MINIHIF)
    configure_minihif_hw();
#endif /*TEST_MINIHIF*/

#if ( defined(PFE_CFG_FCI_ENABLE) \
      && ( (defined(FCI_L2BR_TEST) && defined(PFE_CFG_PFE_MASTER)) /* Skip on SLAVE */ \
           || defined(FCI_RTABLE_TEST) \
         ) \
    )
    /* FCI test */
    SampleAppFciTestTask();
#endif
    /* Init the shared debug information */
    autolibc_memset((void *)app_debug_info_ptr, 0, sizeof(app_debug_info_t));
    app_debug_info_ptr->version = 1U;
#ifdef NXP_LOG_ENABLED
    app_debug_info_ptr->debug_buf.addr = (addr_t)&debug_buff;
    app_debug_info_ptr->debug_buf.line_write_addr = (addr_t)&debug_line;
    app_debug_info_ptr->debug_buf.line_len = NXP_LOG_ASR_CFG_LINE_SIZE;
    app_debug_info_ptr->debug_buf.line_num = NXP_LOG_ASR_CFG_LINE_COUNT;
#endif

    /* Make the app use counters in shared debug info */
    pfeRxCtr = app_debug_info_ptr->counter.rxCtr;
    pfeTxCtr = app_debug_info_ptr->counter.txCtr;
    pfeTxConfCtr = app_debug_info_ptr->counter.tx_confCtr;
    pfeTxErrorCtr = app_debug_info_ptr->counter.tx_errCtr;

    app_debug_info_ptr->initialized = TRUE;

#ifdef LWIP
    demo_lwip_init();
#endif

    creat_tasks_m7();

    while (1)
    {
        /* code */
    }
#if 0    
    while (E_OK == ret)
    {
#ifdef USE_SJA1105P_DRIVER
        if (switchMainFunction == 1U)
        {
            EthSwt_43_SJA1105P_MainFunction();
            switchMainFunction = 0U;
        }
#endif
#ifdef PING_TEST
        /* Wait for inbound traffic */
        if (!queue_is_empty())
        {
            queue_data = queue_pop();
            send_frame(queue_data.data_ptr, queue_data.ether_type, queue_data.len_byte, queue_data.ctrl_idx, queue_data.phys_addr_ptr);
        }
#elif defined(LWIP)
        /* switch context when a task returns or within the timer ISR */
        if (g_sys_milliseconds != last_tick)
        {
            last_tick = g_sys_milliseconds;
            demo_lwip_main();
        }
#endif
        if (pfeMainFunction == 1U)
        {
          //  Eth_43_PFE_MainFunction();
            pfeMainFunction = 0U;
        }
        if (sendFrames == 1U)
        {
          //  ret = SampleAppTask2();
            sendFrames = 0U;
        }
#ifdef NXP_LOG_ENABLED
        if (clearCacheMemory == 1U)
        {
            Mcl_CacheCleanByAddr(MCL_CACHE_DATA, FALSE, app_debug_info_ptr->debug_buf.addr, sizeof(debug_buff));
            clearCacheMemory = 0U;
        }
#endif
        /* Reading of statistics to be triggered by writing getStatisticsFromCtrl using debugger */
        if (getStatisticsFromCtrl < NUM_CONTROLLER_USED)
        {
            GetStatistics();
            getStatisticsFromCtrl = NUM_CONTROLLER_USED;
        }

#if defined(CONFIGURE_SOC)
        /* Restart partition 1 (A53 cores) - set RestartA53Req by debugger */
        if (1U == RestartA53Req)
        {
            *((uint32_t*)(0x4007CA00)) = 0U; /* Disable PFE_COH_EN */
            Mcu_InitClock(McuClockSettingA53FIRC);
            while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() ){}
            Mcu_DistributePllClock();
            Mcu_SetMode(McuModeOffPart1);
            Mcu_SetMode(McuModeOnPart1);
            RestartA53Req = 0U;
        }
#endif /* CONFIGURE_SOC */

#ifdef USE_SJA1105P_DRIVER
        if (getCounters == 1U)
        {
            ret = SampleAppTask1();
            getCounters = 0U;
        }
#endif
    }
  #endif  
        /* switch context when a task returns or within the timer ISR */
    return 0;

}

/**
* @brief      GetStatistics - Get EMAC statistics
* @details    This function is called periodically from the main loop when getStatisticsFromCtrl is set.
*             The flag is used also as an index of the controller which statistics are requested.
*
* @return     none
* @retval     none
*
* @pre None
* @post None
*/
void GetStatistics(void)
{
#if STD_ON == ETH_43_GET_COUNTER_API
    (void)Eth_43_PFE_GetCounterValues(getStatisticsFromCtrl, &pfeCounterValues);
#endif /* STD_ON == ETH_43_GET_COUNTER_API */
#if STD_ON == ETH_43_GET_RXSTATS_API
    (void)Eth_43_PFE_GetRxStats(getStatisticsFromCtrl, &pfeRxStats);
#endif /* STD_ON == ETH_43_GET_RXSTATS_API */
#if STD_ON == ETH_43_GET_TXSTATS_API
    (void)Eth_43_PFE_GetTxStats(getStatisticsFromCtrl, &pfeTxStats);
#endif /* STD_ON == ETH_43_GET_TXSTATS_API */
#if STD_ON == ETH_43_GET_TXERROR_COUNTER_API
    (void)Eth_43_PFE_GetTxErrorCounterValues(getStatisticsFromCtrl, &pfeTxErrorCounterValues);
#endif /* STD_ON == ETH_43_GET_TXERROR_COUNTER_API */
#if STD_ON == ETH_43_GET_CLASS_STATISTIC_API
    (void)Eth_43_PFE_GetClassStats(&pfeStatsClass);
#endif /* ETH_43_GET_CLASS_STATISTIC_API */
#if STD_ON == ETH_43_GET_PFE_STATISTIC_API
    (void)Eth_43_PFE_GetTmuStats((Eth_43_PFE_TmuStatsType *) &pfeStatsTmu);
    (void)Eth_43_PFE_GetRtableStats((pfe_ct_conntrack_stats_t *) &pfeStatsConntrack, 0U);
    (void)Eth_43_PFE_GetL2BridgeDomainStats((pfe_ct_vlan_stats_t *) &pfeStatsVlan, 0U);
    (void)Eth_43_PFE_GetL2BridgeStats((Eth_43_PFE_L2BridgeStatsType *) &pfeStatsL2Br, 0U);
    (void)Eth_43_PFE_GetWdtStats((Eth_43_PFE_WdtStatsType *) &pfeStatsWdt);

    for (uint8_t idxGpi = 0U; idxGpi < PFE_GPI_INSTANCES; idxGpi++) {
        (void)Eth_43_PFE_GetGpiStats(idxGpi, &pfeStatsGpi[idxGpi]);
    }

    for (uint8_t idxBmu = 0U; idxBmu < PFE_BMU_INSTANCES; idxBmu++) {
        (void)Eth_43_PFE_GetBmuStats(idxBmu, &pfeStatsBmu[idxBmu]);
    }
#endif /* ETH_43_GET_PFE_STATISTIC_API */
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#ifdef __cplusplus
}
#endif

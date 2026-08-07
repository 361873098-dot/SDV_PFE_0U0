#include "lwip/opt.h"
#include "lwip/igmp.h"
#include "lwip/debug.h"
#include "lwip/mld6.h"
#include "Nm.h"
#include "lwip/stats.h"
#include "lwip/udp.h"
#include <string.h>
#include "Nm.h"
#include "typedefs.h"
//#include "apps/netif_shutdown/netif_shutdown.h"
static struct udp_pcb *udpecho_raw_pcb;

Nm_Nid_t Nid;
Nm_ControlBitVector_t ControlBitVector;
Nm_PncInfo_t PncInfo;
Nm_AppInfo_t AppInfo;

void Nm_ParsingPayload(char *data_recv)
{
    memcpy(&Nid, data_recv, sizeof(Nm_Nid_t));
    memcpy(&ControlBitVector, data_recv + 1, sizeof(Nm_ControlBitVector_t));
    memcpy(&PncInfo, data_recv + 3, sizeof(Nm_PncInfo_t));
    memcpy(&AppInfo, data_recv + 5, sizeof(Nm_AppInfo_t));
}


static void nm_udp_rawapp_recv(void *arg, struct udp_pcb *upcb, struct pbuf *p,
                 const ip_addr_t *addr, u16_t port)
{
  LWIP_UNUSED_ARG(arg);
  if (p != NULL)
  {
    char *data_recv = NULL;
    data_recv = p->payload;

    Nm_ParsingPayload(data_recv);

    /* send received packet back to sender */
 //   udp_sendto(upcb, p, addr, port);
    /* free the pbuf */
    pbuf_free(p);
  }
}


static void nm_udp_rawapp_init(void)
{
  udpecho_raw_pcb = udp_new_ip_type(IPADDR_TYPE_ANY);
  if (udpecho_raw_pcb != NULL)
  {
    err_t err;

    err = udp_bind(udpecho_raw_pcb, IP_ANY_TYPE, NM_UDP_PORT);
    if (err == ERR_OK)
    {
      udp_recv(udpecho_raw_pcb, nm_udp_rawapp_recv, NULL);
    }
    else
    {
      /* abort? output diagnostic? */
    }
  }
  else
  {
    /* abort? output diagnostic? */
  }
}


void Nm_Init(void)
{
    nm_udp_rawapp_init();
}
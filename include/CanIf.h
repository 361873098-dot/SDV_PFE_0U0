/**
 * @file CanIf.h
 * @brief Minimal CanIf contract used by the NXP AUTOSAR Can driver.
 *
 * The project does not instantiate the complete CanIf BSW module. RX, TX,
 * controller-mode and bus-off callbacks are implemented by Can_App.c.
 */

#ifndef CANIF_H
#define CANIF_H

#include "CanIf_Types.h"

#define CANIF_VENDOR_ID                    43
#define CANIF_MODULE_ID                    60
#define CANIF_AR_RELEASE_MAJOR_VERSION     4
#define CANIF_AR_RELEASE_MINOR_VERSION     4
#define CANIF_AR_RELEASE_REVISION_VERSION  0
#define CANIF_SW_MAJOR_VERSION             4
#define CANIF_SW_MINOR_VERSION             0
#define CANIF_SW_PATCH_VERSION             2

#endif /* CANIF_H */

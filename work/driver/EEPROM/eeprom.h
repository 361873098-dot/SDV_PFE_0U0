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
*  File name:           $Source: eeprom.h $
*  Revision:            $Revision: 1.0 $
*  Author:              $Author: Li Song (uic59152)  $
*  Module acronym:      EEPROM
*  Specification:
*  Date:                $Date: 2026/05/12  $
*
*  Description:     This Unit processes the EEPROM module
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


#define EEPROM_I2C_CHANNEL          (I2cChannel_0)  /* Generated I2C logical channel 0 */
#define EEPROM_I2C_SLAVE_ADDR_7BIT  (0x50U)         /* CMM 0xA0 >> 1 */
#define EEPROM_8BYTE_LEN            (8U)
#define EEPROM_WRITE_MAX_LEN       (16U)          /* Maximum number of bytes to write in one I2C transfer, depends on the EEPROM device capability */

/**
 * EEPROM page size in bytes.
 * CRITICAL: All EEPROM writes MUST NOT cross a page boundary!
 * If a write spans two pages, the EEPROM wraps the address pointer
 * within the current page, silently overwriting data at the page start.
 *
 * Common values:
 *   24C02  = 8 bytes/page
 *   24C04  = 16 bytes/page
 *   24C08  = 16 bytes/page
 *   24C16  = 16 bytes/page
 *   24C32  = 32 bytes/page
 *   24C64  = 32 bytes/page
 *   24C128 = 64 bytes/page
 *   24C256 = 64 bytes/page
 *
 * Set this to match the actual EEPROM device on your hardware.
 * Using a value smaller than the actual page size is always safe.
 */
#define EEPROM_PAGE_SIZE            (8U)

/***********************************************************************************************************************
 *  Function name    : Eeprom_ReadBytes()
 *
 *  Description      : Read bytes from EEPROM.
 *
 *  List of arguments: address - EEPROM address to read from
 *                     data - Pointer to buffer to store read data
 *                     length - Number of bytes to read
 *
 *  Return value     : None
 *
 ***********************************************************************************************************************/
extern Std_ReturnType Eeprom_ReadBytes(uint8 address, uint8 *data, uint16 length);

/***********************************************************************************************************************
 *  Function name    : Eeprom_WriteBytes()
 *
 *  Description      : Write bytes to EEPROM.
 *
 *  List of arguments: address - EEPROM internal address to write to
 *                     data    - Pointer to buffer containing data to write
 *                     length  - Number of bytes to write
 *
 *  Return value     : E_OK     - Write request accepted by I2C driver
 *                     E_NOT_OK - Write request failed
 *
 ***********************************************************************************************************************/
extern Std_ReturnType Eeprom_WriteBytes(uint8 address, uint8 *data, uint16 length);

/***********************************************************************************************************************
 *  Function name    : Eeprom_WriteOnePage()
 *
 *  Description      : Write at most ONE EEPROM-page-aligned chunk (<= EEPROM_PAGE_SIZE
 *                     bytes) and return immediately WITHOUT the t_WR write-cycle delay.
 *
 *                     The chunk is clipped to the current page boundary so the EEPROM
 *                     never wraps its internal address pointer. The actual number of
 *                     bytes written is reported through writtenLen.
 *
 *                     CRITICAL: This function does NOT wait for the EEPROM internal
 *                     write cycle (t_WR). The caller MUST ensure at least ~10ms elapses
 *                     before the next write to the device (e.g. by issuing one chunk per
 *                     10ms task cycle).
 *
 *  List of arguments: address    - EEPROM internal start address
 *                     data       - Pointer to source buffer
 *                     length     - Requested write length
 *                     writtenLen - [out] Actual bytes written (<= EEPROM_PAGE_SIZE),
 *                                  set to 0 on failure (may be NULL)
 *
 *  Return value     : E_OK     - Chunk written (I2C transfer accepted)
 *                     E_NOT_OK - Invalid parameters or I2C transfer failed
 *
 ***********************************************************************************************************************/
extern Std_ReturnType Eeprom_WriteOnePage(uint8 address, uint8 *data,
                                          uint16 length, uint16 *writtenLen);

extern void Test_WrEeprom(void);
extern void Test_RdEeprom(void);
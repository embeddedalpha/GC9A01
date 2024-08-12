/*
 * SD_Commands.h
 *
 *  Created on: Jun 1, 2024
 *      Author: kunal
 */

#ifndef SD_COMMANDS_H_
#define SD_COMMANDS_H_

#include "main.h"

typedef struct {
    uint8_t commandIndex;
    uint32_t argument;
    uint8_t responseType;
} SDIO_Command;

static const struct SDIO_Commands {
    SDIO_Command GO_IDLE_STATE;         // CMD0
    SDIO_Command SEND_OP_COND;          // CMD1 (not typically used for SD cards)
    SDIO_Command ALL_SEND_CID;          // CMD2
    SDIO_Command SEND_RELATIVE_ADDR;    // CMD3
    SDIO_Command SET_DSR;               // CMD4 (not typically used)
    SDIO_Command SELECT_DESELECT_CARD;  // CMD7
    SDIO_Command SEND_IF_COND;          // CMD8
    SDIO_Command SEND_CSD;              // CMD9
    SDIO_Command SEND_CID;              // CMD10
    SDIO_Command VOLTAGE_SWITCH;        // CMD11 (only for UHS-I cards)
    SDIO_Command STOP_TRANSMISSION;     // CMD12
    SDIO_Command SEND_STATUS;           // CMD13
    SDIO_Command GO_INACTIVE_STATE;     // CMD15
    SDIO_Command SET_BLOCKLEN;          // CMD16
    SDIO_Command READ_SINGLE_BLOCK;     // CMD17
    SDIO_Command READ_MULTIPLE_BLOCK;   // CMD18
    SDIO_Command SEND_TUNING_BLOCK;     // CMD19 (only for UHS-I cards)
    SDIO_Command SPEED_CLASS_CONTROL;   // CMD20 (optional)
    SDIO_Command SET_BLOCK_COUNT;       // CMD23 (optional)
    SDIO_Command WRITE_BLOCK;           // CMD24
    SDIO_Command WRITE_MULTIPLE_BLOCK;  // CMD25
    SDIO_Command PROGRAM_CSD;           // CMD27 (optional)
    SDIO_Command ERASE_WR_BLK_START;    // CMD32
    SDIO_Command ERASE_WR_BLK_END;      // CMD33
    SDIO_Command ERASE;                 // CMD38
    SDIO_Command LOCK_UNLOCK;           // CMD42 (optional)
    SDIO_Command APP_CMD;               // CMD55
    SDIO_Command GEN_CMD;               // CMD56 (optional)
    SDIO_Command READ_OCR;              // CMD58
    SDIO_Command CRC_ON_OFF;            // CMD59

    // Application-specific commands (ACMD)
    SDIO_Command SET_BUS_WIDTH;         // ACMD6
    SDIO_Command SD_STATUS;             // ACMD13
    SDIO_Command SEND_NUM_WR_BLOCKS;    // ACMD22
    SDIO_Command SET_WR_BLK_ERASE_COUNT;// ACMD23
    SDIO_Command SD_SEND_OP_COND;       // ACMD41
    SDIO_Command SET_CLR_CARD_DETECT;   // ACMD42
    SDIO_Command SEND_SCR;              // ACMD51
} SDIO_Commands = {
    .GO_IDLE_STATE         = {0x00, 0x00000000, 0x00},  // CMD0, no response
    .SEND_OP_COND          = {0x01, 0x00FF8000, 0x40},  // CMD1, R3
    .ALL_SEND_CID          = {0x02, 0x00000000, 0xC0},  // CMD2, R2
    .SEND_RELATIVE_ADDR    = {0x03, 0x00000000, 0x40},  // CMD3, R6
    .SET_DSR               = {0x04, 0x00000000, 0x00},  // CMD4, no response
    .SELECT_DESELECT_CARD  = {0x07, 0x00000000, 0x40},  // CMD7, R1
    .SEND_IF_COND          = {0x08, 0x000001AA, 0x40},  // CMD8, R7
    .SEND_CSD              = {0x09, 0x00000000, 0xC0},  // CMD9, R2
    .SEND_CID              = {0x0A, 0x00000000, 0xC0},  // CMD10, R2
    .VOLTAGE_SWITCH        = {0x0B, 0x00000000, 0x40},  // CMD11, R1
    .STOP_TRANSMISSION     = {0x0C, 0x00000000, 0x40},  // CMD12, R1b
    .SEND_STATUS           = {0x0D, 0x00000000, 0x40},  // CMD13, R1
    .GO_INACTIVE_STATE     = {0x0F, 0x00000000, 0x00},  // CMD15, no response
    .SET_BLOCKLEN          = {0x10, 0x00000200, 0x40},  // CMD16, R1
    .READ_SINGLE_BLOCK     = {0x11, 0x00000000, 0x40},  // CMD17, R1
    .READ_MULTIPLE_BLOCK   = {0x12, 0x00000000, 0x40},  // CMD18, R1
    .SEND_TUNING_BLOCK     = {0x13, 0x00000000, 0x40},  // CMD19, R1
    .SPEED_CLASS_CONTROL   = {0x14, 0x00000000, 0x40},  // CMD20, R1
    .SET_BLOCK_COUNT       = {0x17, 0x00000000, 0x40},  // CMD23, R1
    .WRITE_BLOCK           = {0x18, 0x00000000, 0x40},  // CMD24, R1
    .WRITE_MULTIPLE_BLOCK  = {0x19, 0x00000000, 0x40},  // CMD25, R1
    .PROGRAM_CSD           = {0x1B, 0x00000000, 0x40},  // CMD27, R1
    .ERASE_WR_BLK_START    = {0x20, 0x00000000, 0x40},  // CMD32, R1
    .ERASE_WR_BLK_END      = {0x21, 0x00000000, 0x40},  // CMD33, R1
    .ERASE                 = {0x26, 0x00000000, 0x40},  // CMD38, R1b
    .LOCK_UNLOCK           = {0x2A, 0x00000000, 0x40},  // CMD42, R1
    .APP_CMD               = {0x37, 0x00000000, 0x40},  // CMD55, R1
    .GEN_CMD               = {0x38, 0x00000000, 0x40},  // CMD56, R1
    .READ_OCR              = {0x3A, 0x00000000, 0x40},  // CMD58, R3
    .CRC_ON_OFF            = {0x3B, 0x00000001, 0x40},  // CMD59, R1

    // Application-specific commands (ACMD)
    .SET_BUS_WIDTH         = {0x06, 0x00000002, 0x40},  // ACMD6, R1
    .SD_STATUS             = {0x0D, 0x00000000, 0x40},  // ACMD13, R1
    .SEND_NUM_WR_BLOCKS    = {0x16, 0x00000000, 0x40},  // ACMD22, R1
    .SET_WR_BLK_ERASE_COUNT= {0x17, 0x00000000, 0x40},  // ACMD23, R1
    .SD_SEND_OP_COND       = {0x29, 0x40FF8000, 0x40},  // ACMD41, R3
    .SET_CLR_CARD_DETECT   = {0x2A, 0x00000000, 0x40},  // ACMD42, R1
    .SEND_SCR              = {0x33, 0x00000000, 0x40}   // ACMD51, R1
};

static const struct SDIO_ResponseTypes {
    uint8_t NO_RESPONSE;       // No response
    uint8_t SHORT_RESPONSE;    // Short response (R1, R3, R6, R7)
    uint8_t LONG_RESPONSE;     // Long response (R2)
} SDIO_ResponseTypes = {
    .NO_RESPONSE      = 0x00,
    .SHORT_RESPONSE   = 0x40,
    .LONG_RESPONSE    = 0xC0
};

#endif /* SD_COMMANDS_H_ */

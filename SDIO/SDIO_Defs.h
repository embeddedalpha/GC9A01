/*
 * SDIO_Defs.h
 *
 *  Created on: May 31, 2024
 *      Author: kunal
 */

#ifndef SDIO_DEFS_H_
#define SDIO_DEFS_H_




static const struct SDIO_Bus_Mode
{
	uint16_t bit1;
	uint16_t bit4;
	uint16_t bit8;

}SDIO_Bus_Mode = {
		.bit1 = 0x00 << SDIO_CLKCR_WIDBUS_Pos,
		.bit4 = 0x01 << SDIO_CLKCR_WIDBUS_Pos,
		.bit8 = 0x02 << SDIO_CLKCR_WIDBUS_Pos,
};






#endif /* SDIO_DEFS_H_ */

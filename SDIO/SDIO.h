/*
 * SDIO.h
 *
 *  Created on: May 31, 2024
 *      Author: kunal
 */

#ifndef SDIO_H_
#define SDIO_H_

#include "main.h"
#include "GPIO.h"
#include "DMA.h"
#include "SDIO_Defs.h"
#include "SD_Commands.h"

typedef struct SDIO_Config
{
	uint8_t Power_Control;
	uint8_t Hardware_Flow_Control;
	uint8_t Clock_Dephasing;
	uint8_t Bus_Mode;
	uint8_t Power_Saving_Mode;
	uint8_t Clock_Division_Factor;


}SDIO_Config;

#endif /* SDIO_H_ */

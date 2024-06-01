/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include "main.h"
#include "Console.h"
#include "GC9A01.h"
#include "math.h"

GC9A01_Typedef display;

int main(void)
{
	MCU_Clock_Setup();
	Delay_Config();
	Console_Init(USART1, 9600);
	Delay_s(2);

	// test this part
//	GC9A01_DeInit(&display);

	display.SPI_Driver.NSS_Pin = 1;
	display.SPI_Driver.NSS_Port = GPIOA;
	display.SPI_Driver.Port = SPI1;
	display.SPI_Driver.clock_phase = SPI_Clock_Phase.Low_0;
	display.SPI_Driver.clock_pin = SPI1_CLK.PA5;
	display.SPI_Driver.clock_polarity = SPI_Clock_Polarity.Low_0;
	display.SPI_Driver.crc = SPI_CRC.Disable;
	display.SPI_Driver.data_format = SPI_Data_Format.Bit8;
	display.SPI_Driver.dma = SPI_DMA.RX_DMA_Disable;
	display.SPI_Driver.frame_format = SPI_Frame_Format.MSB_First;
	display.SPI_Driver.interrupt = SPI_Interrupt.Disable;
	display.SPI_Driver.miso_pin = SPI1_MISO.PA6;
	display.SPI_Driver.mode = SPI_Mode.Full_Duplex_Master;
	display.SPI_Driver.mosi_pin = SPI1_MOSI.PA7;
	display.SPI_Driver.prescaler = SPI_Prescaler.CLK_div_16;
	display.SPI_Driver.type = SPI_Type.Master;

	display.DC_Port = GPIOA;
	display.DC_Pin = 3;

	display.Reset_Port = GPIOA;
	display.Reset_Pin = 2;

	GC9A01_Init(&display);

    struct GC9A01_frame frame = {{0,0},{240,240}};
    GC9A01_Set_Frame(&display,frame);
    uint8_t color[3];








	for(;;)
	{
		color[0] = 0x12;
		color[1] = 0x67;
		color[2] = 0xa6;
		for (int x = 0; x < 240; x++) {
            for (int y = 0; y < 240; y++)
            {
                if (x == 0 && y == 0)
                {
                	GC9A01_Write(&display,color, sizeof(color));
                } else
                {
                	GC9A01_Write_Continue(&display,color, sizeof(color));
                }
            }
        }
//            Delay_s(2);

    		color[0] = 0xEa;
    		color[1] = 0x99;
    		color[2] = 0x99;
    		for (int x = 0; x < 240; x++) {
                for (int y = 0; y < 240; y++)
                {
                    if (x == 0 && y == 0) {
                    	GC9A01_Write(&display,color, sizeof(color));
                    } else {
                    	GC9A01_Write_Continue(&display,color, sizeof(color));
                    }
                }
            }
//                Delay_s(2);

        		color[0] = 0x59;
        		color[1] = 0xcc;
        		color[2] = 0x27;
        		for (int x = 0; x < 240; x++) {
                    for (int y = 0; y < 240; y++)
                    {
                        if (x == 0 && y == 0) {
                        	GC9A01_Write(&display,color, sizeof(color));
                        } else {
                        	GC9A01_Write_Continue(&display,color, sizeof(color));
                        }
                    }
                }
//                    Delay_s(2);


//	    float frequency = 0.026;
//	    for (int x = 0; x < 240; x++) {
//	        color[0] = 0xff;
//	        color[1] = 0x00;
//	        color[2] = 0xff;
//	        for (int y = 0; y < 240; y++) {
//	            if (x == 0 && y == 0) {
//	                GC9A01_Write(&display,color, sizeof(color));
//	            } else {
//	                GC9A01_Write_Continue(&display,color, sizeof(color));
//	            }
//	        }
//	    }

//	    Delay_us(1000);

//	    color[0] = 0x00;
//	        for (int x = 0; x < 240; x++) {
//	            for (int y = 0; y < 240; y++) {
//	                if ((x >= 1*48 && x < 4*48 && y >= 2*48 && y < 3*48) ||
//	                    (x >= 2*48 && x < 3*48 && y >= 1*48 && y < 4*48)) {
//	                    color[1] = 0xff;
//	                    color[2] = 0xff;
//	                } else {
//	                    color[1] = 0x00;
//	                    color[2] = 0x00;
//	                }
//	                if (x == 0 && y == 0) {
//	                	GC9A01_Write(&display,color, sizeof(color));
//	                } else {
//	                	GC9A01_Write_Continue(&display,color, sizeof(color));
//	                }
//	            }
//	        }
	}
}

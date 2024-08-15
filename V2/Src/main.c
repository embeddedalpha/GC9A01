/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Kunal Salvi
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 * All rights reserved.
 *
 ******************************************************************************
 */

#include "main.h"
#include "GC9A01.h"

SPI_Config x;

GC9A01_Typedef GC9A01_Driver;

int main(void)
{
	MCU_Clock_Setup();
	Delay_Config();




	GC9A01_Driver.SPI_Driver.NSS_Pin = 3;
	GC9A01_Driver.SPI_Driver.NSS_Port = GPIOA;
	GC9A01_Driver.SPI_Driver.clock_pin = SPI_Configurations.Pin._SPI1_.CLK1.PA5;
	GC9A01_Driver.SPI_Driver.miso_pin = SPI_Configurations.Pin._SPI1_.MISO1.PA6;
	GC9A01_Driver.SPI_Driver.mosi_pin = SPI_Configurations.Pin._SPI1_.MOSI1.PA7;
	GC9A01_Driver.DC_Pin = 2;
	GC9A01_Driver.DC_Port = GPIOA;
	GC9A01_Driver.Reset_Pin = 1;
	GC9A01_Driver.Reset_Port = GPIOA;

	GC9A01_Driver.SPI_Driver.Port = SPI1;
	GC9A01_Driver.SPI_Driver.clock_phase = SPI_Configurations.Clock_Phase.Low_0;
	GC9A01_Driver.SPI_Driver.clock_polarity = SPI_Configurations.Clock_Polarity.Low_0;
	GC9A01_Driver.SPI_Driver.crc = SPI_Configurations.CRC_Enable.Disable;
	GC9A01_Driver.SPI_Driver.data_format = SPI_Configurations.Data_Format.Bit8;
	GC9A01_Driver.SPI_Driver.dma = SPI_Configurations.DMA_Type.TX_DMA_Enable;
	GC9A01_Driver.SPI_Driver.frame_format = SPI_Configurations.Frame_Format.MSB_First;
	GC9A01_Driver.SPI_Driver.interrupt = SPI_Configurations.Interrupts.Disable;
	GC9A01_Driver.SPI_Driver.mode = SPI_Configurations.Mode.Full_Duplex_Master;
	GC9A01_Driver.SPI_Driver.prescaler = SPI_Configurations.Prescaler.CLK_div_2;
	GC9A01_Driver.SPI_Driver.type = SPI_Configurations.Type.Master;
	GC9A01_Init(&GC9A01_Driver);


	GC9A01_Splash_Screen(&GC9A01_Driver, 0xFf00);
	Delay_s(1);
	GC9A01_Splash_Screen(&GC9A01_Driver, 0x00FF);
	Delay_s(1);


//	uint16_t color;
//
//	uint16_t red = 0x00;
//	uint16_t green = 0x00;
//	uint16_t blue = 0x00;
//
//	int i  = 0;

	for(;;)
	{

//		if(i >= 65535)
//		{
//			i = 0;
//		}
//		color = i;
//		GC9A01_Splash_Screen(&GC9A01_Driver, color);
//		i += 1;
//		Delay_ms(100);



	}
}




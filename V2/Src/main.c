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
#include "SPI.h"

SPI_Config x;

int main(void)
{
	MCU_Clock_Setup();
	Delay_Config();




	x.NSS_Pin = 3;
	x.NSS_Port = GPIOA;
	x.Port = SPI1;
	x.clock_phase = SPI_Configurations.Clock_Phase.Low_0;
	x.clock_polarity = SPI_Configurations.Clock_Polarity.Low_0;
	x.clock_pin = SPI_Configurations.Pin._SPI1_.CLK1.PA5;
	x.crc = SPI_Configurations.CRC_Enable.Disable;
	x.data_format = SPI_Configurations.Data_Format.Bit8;
	x.dma = SPI_Configurations.DMA_Type.TX_DMA_Enable;
	x.frame_format = SPI_Configurations.Frame_Format.MSB_First;
	x.interrupt = SPI_Configurations.Interrupts.Disable;
	x.miso_pin = SPI_Configurations.Pin._SPI1_.MISO1.PA6;
	x.mode = SPI_Configurations.Mode.Full_Duplex_Master;
	x.mosi_pin = SPI_Configurations.Pin._SPI1_.MOSI1.PA7;
	x.prescaler = SPI_Configurations.Prescaler.CLK_div_32;
	x.type = SPI_Configurations.Type.Master;
	SPI_Init(&x);
	SPI_Enable(&x);

	uint8_t tx_buffer[240*240];
	for(int i = 0; i < 240*240; i++)
	{
		tx_buffer[i] = 0x01;
	}

	uint8_t rx_buffer[240*240];

	Delay_s(1);

//	SPI_NSS_High(&x);
//	SPI_NSS_Low(&x);
//	SPI_TRX_Buffer(&x, &tx_buffer, &rx_buffer, 240*240, 240*240);
//	SPI_NSS_High(&x);
//	Delay_s(1);
//	SPI_NSS_High(&x);
//	SPI_NSS_Low(&x);
//	SPI_TRX_Buffer(&x, &tx_buffer, &rx_buffer, 240*240, 240*240);
//	SPI_NSS_High(&x);

	for(;;)
	{

		SPI_NSS_Low(&x);
		SPI_TRX_Buffer(&x, &tx_buffer, &rx_buffer, 240*240, 240*240);
		SPI_NSS_High(&x);
		Delay_s(1);



//		Delay_s(1);





	}
}




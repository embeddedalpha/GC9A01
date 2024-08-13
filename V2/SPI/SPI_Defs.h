/*
 * SPI_Defs.h
 *
 *  Created on: Nov 12, 2023
 *      Author: kunal
 */

#ifndef SPI_DEFS_H_
#define SPI_DEFS_H_

#include "main.h"

typedef struct SPI_Mode
{
	uint8_t Full_Duplex_Master;
	uint8_t Full_Duplex_Slave;

	uint8_t Half_Duplex_Master;
	uint8_t Half_Duplex_Slave;

	uint8_t RX_Only_Master;
	uint8_t RX_Only_Slave;

	uint8_t TX_Only_Master;
	uint8_t TX_Only_Slave;

}SPI_Mode;

typedef struct SPI_CRC
{
	bool Enable;
	bool Disable;
}SPI_CRC;

typedef struct SPI_Data_Format
{
	uint8_t Bit8;
	uint8_t Bit16;
}SPI_Data_Format;

typedef struct SPI_Frame_Format
{
	uint8_t MSB_First;
	uint8_t LSB_First;
}SPI_Frame_Format;

typedef struct SPI_Clock_Phase_and_Polarity
{
	uint8_t High_1;
	uint8_t Low_0;
}SPI_Clock_Phase_and_Polarity;


typedef struct SPI_Type
{
	uint8_t Master;
	uint8_t Slave;
}SPI_Type ;

typedef struct SPI_Interrupt
{
	uint8_t Tx_Buffer_Empty;
	uint8_t RX_Buffer_not_Empty;
	uint8_t Error;
	uint8_t Disable;
}SPI_Interrupt;

typedef struct SPI_DMA
{
	uint8_t TX_DMA_Enable;
	uint8_t TX_DMA_Disable;
	uint8_t RX_DMA_Enable;
	uint8_t RX_DMA_Disable;
}SPI_DMA;

typedef struct SPI_Prescaler
{
	uint8_t CLK_div_2;
	uint8_t CLK_div_4;
	uint8_t CLK_div_8;
	uint8_t CLK_div_16;
	uint8_t CLK_div_32;
	uint8_t CLK_div_64;
	uint8_t CLK_div_128;
	uint8_t CLK_div_256;
}SPI_Prescaler ;

typedef struct SPI_Pin
{
	 struct _SPI1_{

		struct CLK1{
			uint8_t PA5;
			uint8_t PB3;
		}CLK1;

		struct MOSI1{
			uint8_t PA7;
			uint8_t PB5;
		}MOSI1;

		struct MISO1{
			uint8_t PA6;
			uint8_t PB4;
		}MISO1;

	}_SPI1_;

	 struct _SPI2_{

		struct CLK2{
			uint16_t PB10;
			uint16_t PB13;
		}CLK2;

		struct MOSI2{
			uint16_t PC3;
			uint16_t PB15;
		}MOSI2;

		struct MISO2{
			uint16_t PC2;
			uint16_t PB14;
		}MISO2;

	}_SPI2_;

	 struct _SPI3_{

		struct CLK3{
			uint16_t PC10;
			uint16_t PB3;
		}CLK3;

		struct MOSI3{
			uint16_t PC12;
			uint16_t PB5;
		}MOSI3;

		struct MISO3{
			uint16_t PC11;
			uint16_t PB4;
		}MISO3;

	}_SPI3_;

}SPI_Pin;


typedef struct SPI_Ports
{
	SPI_TypeDef *_SPI1_;
	SPI_TypeDef *_SPI2_;
	SPI_TypeDef *_SPI3_;

}SPI_Ports;


static const struct SPI_Configurations
{

	SPI_Mode Mode;
	SPI_CRC  CRC_Enable;
	SPI_Data_Format Data_Format;
	SPI_Frame_Format Frame_Format;
	SPI_Clock_Phase_and_Polarity Clock_Phase;
	SPI_Clock_Phase_and_Polarity Clock_Polarity;
	SPI_Type Type;
	SPI_Interrupt Interrupts;
	SPI_DMA DMA_Type;
	SPI_Prescaler Prescaler;
	SPI_Pin Pin;



}SPI_Configurations =
{
		.Mode = {
				.Full_Duplex_Master = 11,
				.Full_Duplex_Slave  = 12,
				.Half_Duplex_Master  = 13,
				.Half_Duplex_Slave = 14,
				.RX_Only_Master = 15,
				.RX_Only_Slave = 16,
				.TX_Only_Master = 17,
				.TX_Only_Slave = 18,
				},

		.CRC_Enable = {
			    .Enable = 1,
			    .Disable = 0,
		},

		.Data_Format = {
				.Bit8 = 11,
				.Bit16 = 12,
		},

		.Frame_Format = {
				.MSB_First = 23,
				.LSB_First = 24,
		},

		.Clock_Phase = {
				.High_1 = 22,
				.Low_0 = 23,
		},

		.Clock_Polarity = {
				.High_1 = 32,
				.Low_0 = 33,
		},

		.Type = {
				.Master = 50,
				.Slave = 51,
		},

		.Interrupts = {
				.Tx_Buffer_Empty = 73,
				.RX_Buffer_not_Empty = 72,
				.Error = 71,
				.Disable = 70,
		},

		.DMA_Type = {
				.TX_DMA_Enable  = 61,
				.TX_DMA_Disable = 62,
				.RX_DMA_Enable  = 63,
				.RX_DMA_Disable = 64,
		},

		.Prescaler = {

				.CLK_div_2 = 40,
				.CLK_div_4 = 41,
				.CLK_div_8 = 42,
				.CLK_div_16 = 43,
				.CLK_div_32 = 44,
				.CLK_div_64 = 45,
				.CLK_div_128 = 46,
				.CLK_div_256 = 47,
		},

		.Pin = {

				._SPI1_ = {

						.CLK1 = {
							.PA5 = 15,
							.PB3 = 33,
						},

						.MOSI1 = {
							.PA7 = 17,
							.PB5 = 35,
						},

						.MISO1 = {
							.PA6 = 16,
							.PB4 = 34,
						},

					},

				._SPI2_ = {

						.CLK2 = {
							.PB10 = 19,
							.PB13 = 23,
						},

						.MOSI2 = {
							.PC3 = 17,
							.PB15 = 29,
						},

						.MISO2 = {
							.PC2 = 32,
							.PB14 = 27,
						},

					},

				._SPI3_ = {

						.CLK3 = {
							.PC10 = 37,
							.PB3 = 23,
						},

						.MOSI3 = {
							.PC12 = 39,
							.PB5 = 25,
						},

						.MISO3 = {
							.PC11 = 39,
							.PB4 = 24,
						},

					},



		},





};






#endif /* SPI_DEFS_H_ */

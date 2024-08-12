/*
 * DMA_Defs.h
 *
 *  Created on: Jul 20, 2024
 *      Author: kunal
 */

#ifndef DMA_DEFS_H_
#define DMA_DEFS_H_

#include "main.h"

typedef struct DMA_Request {
	DMA_TypeDef *Controller;
	DMA_Stream_TypeDef *Stream;
	uint8_t channel;
} DMA_Request;

static const struct DMA_Configuration {

	struct Request{
		// SPI DMA
		DMA_Request SPI3_RX;
		DMA_Request SPI3_TX;

		DMA_Request SPI2_RX;
		DMA_Request SPI2_TX;

		DMA_Request SPI1_RX;
		DMA_Request SPI1_TX;

		// I2S DMA
		DMA_Request I2S2_RX;
		DMA_Request I2S2_TX;
		DMA_Request I2S3_RX;
		DMA_Request I2S3_TX;

		// I2C DMA
		DMA_Request I2C1_RX;
		DMA_Request I2C1_TX;
		DMA_Request I2C2_RX;
		DMA_Request I2C2_TX;
		DMA_Request I2C3_RX;
		DMA_Request I2C3_TX;

		// USART DMA
		DMA_Request USART1_RX;
		DMA_Request USART1_TX;
		DMA_Request USART2_RX;
		DMA_Request USART2_TX;
		DMA_Request USART3_RX;
		DMA_Request USART3_TX;
		DMA_Request UART4_RX;
		DMA_Request UART4_TX;
		DMA_Request UART5_RX;
		DMA_Request UART5_TX;
		DMA_Request UART6_RX;
		DMA_Request UART6_TX;
		DMA_Request UART7_RX;
		DMA_Request UART7_TX;
		DMA_Request UART8_RX;
		DMA_Request UART8_TX;

		// TIM DMA
		// TIM1 DMA
		DMA_Request TIM1_UP;
		DMA_Request TIM1_CH1;
		DMA_Request TIM1_CH2;
		DMA_Request TIM1_CH3;
		DMA_Request TIM1_CH4;
		DMA_Request TIM1_TRIG;
		DMA_Request TIM1_COM;

		// TIM8 DMA
		DMA_Request TIM8_UP;
		DMA_Request TIM8_CH1;
		DMA_Request TIM8_CH2;
		DMA_Request TIM8_CH3;
		DMA_Request TIM8_CH4;
		DMA_Request TIM8_TRIG;
		DMA_Request TIM8_COM;

		// TIM2 DMA
		DMA_Request TIM2_UP;
		DMA_Request TIM2_CH1;
		DMA_Request TIM2_CH2;
		DMA_Request TIM2_CH3;
		DMA_Request TIM2_CH4;

		// TIM3 DMA
		DMA_Request TIM3_CH1;
		DMA_Request TIM3_CH2;
		DMA_Request TIM3_CH3;
		DMA_Request TIM3_CH4;
		DMA_Request TIM3_UP;
		DMA_Request TIM3_TRIG;

		// TIM4 DMA
		DMA_Request TIM4_CH1;
		DMA_Request TIM4_CH2;
		DMA_Request TIM4_CH3;
		DMA_Request TIM4_UP;

		// TIM5 DMA
		DMA_Request TIM5_CH1;
		DMA_Request TIM5_CH2;
		DMA_Request TIM5_CH3;
		DMA_Request TIM5_CH4;
		DMA_Request TIM5_UP;
		DMA_Request TIM5_TRIG;

		DMA_Request TIM6_UP;

		DMA_Request TIM7_UP;



		// DAC DMA
		DMA_Request _DAC1;
		DMA_Request _DAC2;

		// SDIO DMA
		DMA_Request SDIO_RXTX;

		// Camera interface (DCMI) DMA
		DMA_Request _DCMI;

		// ADC DMA
		DMA_Request _ADC1;
		DMA_Request _ADC2;
		DMA_Request _ADC3;

	}Request;

	struct Flow_Control
	{
		uint32_t DMA_Control;
		uint32_t Peripheral_Control;

	}Flow_Control;

	struct Transfer_Direction
	{
		uint32_t Peripheral_to_memory;
		uint32_t Memory_to_peripheral;
		uint32_t Memory_to_memory;

	}Transfer_Direction;

	struct Priority_Level
	{
		uint32_t Low;
		uint32_t Medium;
		uint32_t High;
		uint32_t Very_high;

	}Priority_Level;

	struct Peripheral_Data_Size
	{
		uint32_t byte;
		uint32_t half_word;
		uint32_t word;
	}Peripheral_Data_Size;

	struct Memory_Data_Size
	{
		uint32_t byte;
		uint32_t half_word;
		uint32_t word;
	}Memory_Data_Size;

	struct Circular_Mode
	{
		uint32_t Enable;
		uint32_t Disable;
	}Circular_Mode;

	struct DMA_Interrupts
	{
		uint32_t Transfer_Complete;
		uint32_t Half_Transfer_Complete;
		uint32_t Transfer_Error;
		uint32_t Direct_Mode_Error;
		uint32_t Disable;

	}DMA_Interrupts;

	struct Memory_Pointer_Increment
	{
		uint32_t Enable;
		uint32_t Disable;

	}Memory_Pointer_Increment;

	struct Peripheral_Pointer_Increment
	{
		uint32_t Enable;
		uint32_t Disable;

	}Peripheral_Pointer_Increment;


} DMA_Configuration = {

		.Flow_Control = {
				.DMA_Control = 0 << 5,
				.Peripheral_Control = 1 << 5,
		},

		.Transfer_Direction =
		{
			.Peripheral_to_memory = 0 << 6,
			.Memory_to_peripheral = 1 << 6,
			.Memory_to_memory = 1 << 6,
		},

		.Priority_Level =
		{
			.Low = 0 << 16,
			.Medium = 1 << 16,
			.High = 2 << 16,
			.Very_high = 3 << 16,
		},

		.Request = {

				.SPI3_RX = {
						.Controller = DMA1,
						.Stream = DMA1_Stream0, // DMA1_Stream2
						.channel = 0,
				},

				.SPI3_TX = {
						.Controller = DMA1,
						.Stream = DMA1_Stream5, // DMA1_Stream7
						.channel = 0,
				},

				.SPI2_RX = {
						.Controller = DMA1,
						.Stream = DMA1_Stream3,
						.channel = 0,
				},

				.SPI2_TX = {
						.Controller = DMA1,
						.Stream = DMA1_Stream4,
						.channel = 0,
				},

				.SPI1_RX = {
						.Controller = DMA2,
						.Stream = DMA2_Stream0, // DMA2_Stream2
						.channel = 3,
				},

				.SPI1_TX = {
						.Controller = DMA2,
						.Stream = DMA2_Stream3, // DMA2_Stream5
						.channel = 3,
				},

				.I2S2_RX = {
						.Controller = DMA1,
						.Stream = DMA1_Stream3,
						.channel = 3,
				},

				.I2S2_TX = {
						.Controller = DMA1,
						.Stream = DMA1_Stream4,
						.channel = 3,
				},

				.I2S3_RX = {
						.Controller = DMA1,
						.Stream = DMA1_Stream2,
						.channel = 2,
				},

				.I2S3_TX = {
						.Controller = DMA1,
						.Stream = DMA1_Stream7,
						.channel = 0,
				},

				.I2C1_RX = {
						.Controller = DMA1,
						.Stream = DMA1_Stream0, // DMA1_Stream5
						.channel = 1,
				},

				.I2C1_TX = {
						.Controller = DMA1,
						.Stream = DMA1_Stream6, // DMA1_Stream7
						.channel = 1,
				},

				.I2C2_RX = {
						.Controller = DMA1,
						.Stream = DMA1_Stream2,
						.channel = 7,
				},

				.I2C2_TX = {
						.Controller = DMA1,
						.Stream = DMA1_Stream7,
						.channel = 7,
				},

				.I2C3_RX = {
						.Controller = DMA1,
						.Stream = DMA1_Stream2,
						.channel = 3,
				},

				.I2C3_TX = {
						.Controller = DMA1,
						.Stream = DMA1_Stream4,
						.channel = 3,
				},

				.USART1_RX = {
						.Controller = DMA2,
						.Stream = DMA2_Stream2,
						.channel = 4,
				},

				.USART1_TX = {
						.Controller = DMA2,
						.Stream = DMA2_Stream7,
						.channel = 4,
				},

				.USART2_RX = {
						.Controller = DMA1,
						.Stream = DMA1_Stream5,
						.channel = 4,
				},

				.USART2_TX = {
						.Controller = DMA1,
						.Stream = DMA1_Stream6,
						.channel = 4,
				},

				.USART3_RX = {
						.Controller = DMA1,
						.Stream = DMA1_Stream1,
						.channel = 4,
				},

				.USART3_TX = {
						.Controller = DMA1,
						.Stream = DMA1_Stream3,
						.channel = 4,
				},

				.UART4_RX = {
						.Controller = DMA1,
						.Stream = DMA1_Stream2,
						.channel = 4,
				},

				.UART4_TX = {
						.Controller = DMA1,
						.Stream = DMA1_Stream4,
						.channel = 4,
				},

				.UART5_RX = {
						.Controller = DMA1,
						.Stream = DMA1_Stream0,
						.channel = 4,
				},

				.UART5_TX = {
						.Controller = DMA1,
						.Stream = DMA1_Stream7,
						.channel = 4,
				},

				.UART6_RX = {
						.Controller = DMA2,
						.Stream = DMA2_Stream1,
						.channel = 5,
				},

				.UART6_TX = {
						.Controller = DMA2,
						.Stream = DMA2_Stream6,
						.channel = 5,
				},

				.UART7_RX = {
						.Controller = DMA1,
						.Stream = DMA1_Stream3,
						.channel = 5,
				},

				.UART7_TX = {
						.Controller = DMA1,
						.Stream = DMA1_Stream1,
						.channel = 5,
				},

				.UART8_RX = {
						.Controller = DMA1,
						.Stream = DMA1_Stream6,
						.channel = 5,
				},

				.UART8_TX = {
						.Controller = DMA1,
						.Stream = DMA1_Stream0,
						.channel = 5,
				},

				.TIM1_UP = {
						.Controller = DMA2,
						.Stream = DMA2_Stream5,
						.channel = 6,
				},

				.TIM2_UP = {
						.Controller = DMA1,
						.Stream = DMA1_Stream6,
						.channel = 3,
				},

				.TIM3_CH1 = {
						.Controller = DMA1,
						.Stream = DMA1_Stream4,
						.channel = 5,
				},

				.TIM3_CH2 = {
						.Controller = DMA1,
						.Stream = DMA1_Stream5,
						.channel = 5,
				},

				.TIM3_CH3 = {
						.Controller = DMA1,
						.Stream = DMA1_Stream6,
						.channel = 5,
				},

				.TIM3_CH4 = {
						.Controller = DMA1,
						.Stream = DMA1_Stream2,
						.channel = 5,
				},

				.TIM4_CH1 = {
						.Controller = DMA1,
						.Stream = DMA1_Stream0,
						.channel = 2,
				},

				.TIM4_CH2 = {
						.Controller = DMA1,
						.Stream = DMA1_Stream3,
						.channel = 2,
				},

				.TIM4_CH3 = {
						.Controller = DMA1,
						.Stream = DMA1_Stream7,
						.channel = 2,
				},

				.TIM4_UP = {
						.Controller = DMA1,
						.Stream = DMA1_Stream6,
						.channel = 2,
				},

				.TIM5_CH1 = {
						.Controller = DMA1,
						.Stream = DMA1_Stream2,
						.channel = 6,
				},

				.TIM5_CH2 = {
						.Controller = DMA1,
						.Stream = DMA1_Stream4,
						.channel = 6,
				},

				.TIM5_CH3 = {
						.Controller = DMA1,
						.Stream = DMA1_Stream0,
						.channel = 6,
				},

				.TIM5_UP = {
						.Controller = DMA1,
						.Stream = DMA1_Stream6,
						.channel = 6,
				},

				.TIM6_UP = {
						.Controller = DMA1,
						.Stream = DMA1_Stream1,
						.channel = 7,
				},

				.TIM7_UP = {
						.Controller = DMA1,
						.Stream = DMA1_Stream2,
						.channel = 1,
				},

				._DAC2 = {
						.Controller = DMA1,
						.Stream = DMA1_Stream5,
						.channel = 7,
				},

				._DAC2 = {
						.Controller = DMA1,
						.Stream = DMA1_Stream6,
						.channel = 7,
				},

				.SDIO_RXTX = {
						.Controller = DMA2,
						.Stream = DMA2_Stream3,
						.channel = 4,
				},

				._DCMI = {
						.Controller = DMA2,
						.Stream = DMA2_Stream1,
						.channel = 1,
				},

				._ADC1 = {
						.Controller = DMA2,
						.Stream = DMA2_Stream0,
						.channel = 0,
				},

				._ADC2 = {
						.Controller = DMA2,
						.Stream = DMA2_Stream2,
						.channel = 1,
				},

				._ADC3 = {
						.Controller = DMA2,
						.Stream = DMA2_Stream1,
						.channel = 2,
				},

				.TIM1_UP = {
						.Controller = DMA2,
						.Stream = DMA2_Stream5,
						.channel = 6,
				},

				.TIM1_CH1 = {
						.Controller = DMA2,
						.Stream = DMA2_Stream1,
						.channel = 6,
				},

				.TIM1_CH2 = {
						.Controller = DMA2,
						.Stream = DMA2_Stream6,
						.channel = 6,
				},

				.TIM1_CH3 = {
						.Controller = DMA2,
						.Stream = DMA2_Stream6,
						.channel = 6,
				},

				.TIM1_CH4 = {
						.Controller = DMA2,
						.Stream = DMA2_Stream4,
						.channel = 6,
				},

				.TIM1_TRIG = {
						.Controller = DMA2,
						.Stream = DMA2_Stream0,
						.channel = 6,
				},

				.TIM1_COM = {
						.Controller = DMA2,
						.Stream = DMA2_Stream0,
						.channel = 6,
				},

				.TIM8_UP = {
						.Controller = DMA2,
						.Stream = DMA2_Stream1,
						.channel = 7,
				},

				.TIM8_CH1 = {
						.Controller = DMA2,
						.Stream = DMA2_Stream2,
						.channel = 7,
				},

				.TIM8_CH2 = {
						.Controller = DMA2,
						.Stream = DMA2_Stream4,
						.channel = 7,
				},

				.TIM8_CH3 = {
						.Controller = DMA2,
						.Stream = DMA2_Stream6,
						.channel = 7,
				},

				.TIM8_CH4 = {
						.Controller = DMA2,
						.Stream = DMA2_Stream7,
						.channel = 7,
				},

				.TIM8_TRIG = {
						.Controller = DMA2,
						.Stream = DMA2_Stream1,
						.channel = 7,
				},

				.TIM8_COM = {
						.Controller = DMA2,
						.Stream = DMA2_Stream1,
						.channel = 7,
				},

				.TIM2_UP = {
						.Controller = DMA1,
						.Stream = DMA1_Stream6,
						.channel = 3,
				},

				.TIM2_CH1 = {
						.Controller = DMA1,
						.Stream = DMA1_Stream5,
						.channel = 3,
				},

				.TIM2_CH2 = {
						.Controller = DMA1,
						.Stream = DMA1_Stream7,
						.channel = 3,
				},

				.TIM2_CH3 = {
						.Controller = DMA1,
						.Stream = DMA1_Stream1,
						.channel = 3,
				},

				.TIM2_CH4 = {
						.Controller = DMA1,
						.Stream = DMA1_Stream7,
						.channel = 3,
				},

				.TIM3_CH1 = {
						.Controller = DMA1,
						.Stream = DMA1_Stream4,
						.channel = 5,
				},

				.TIM3_CH2 = {
						.Controller = DMA1,
						.Stream = DMA1_Stream5,
						.channel = 5,
				},

				.TIM3_CH3 = {
						.Controller = DMA1,
						.Stream = DMA1_Stream6,
						.channel = 5,
				},

				.TIM3_CH4 = {
						.Controller = DMA1,
						.Stream = DMA1_Stream2,
						.channel = 5,
				},

				.TIM3_UP = {
						.Controller = DMA1,
						.Stream = DMA1_Stream2,
						.channel = 5,
				},

				.TIM3_TRIG = {
						.Controller = DMA1,
						.Stream = DMA1_Stream5,
						.channel = 5,
				},

				.TIM4_CH1 = {
						.Controller = DMA1,
						.Stream = DMA1_Stream0,
						.channel = 2,
				},

				.TIM4_CH2 = {
						.Controller = DMA1,
						.Stream = DMA1_Stream3,
						.channel = 2,
				},

				.TIM4_CH3 = {
						.Controller = DMA1,
						.Stream = DMA1_Stream7,
						.channel = 2,
				},

				.TIM4_UP = {
						.Controller = DMA1,
						.Stream = DMA1_Stream6,
						.channel = 2,
				},

				.TIM5_CH1 = {
						.Controller = DMA1,
						.Stream = DMA1_Stream2,
						.channel = 6,
				},

				.TIM5_CH2 = {
						.Controller = DMA1,
						.Stream = DMA1_Stream4,
						.channel = 6,
				},

				.TIM5_CH3 = {
						.Controller = DMA1,
						.Stream = DMA1_Stream0,
						.channel = 6,
				},

				.TIM5_CH4 = {
						.Controller = DMA1,
						.Stream = DMA1_Stream6,
						.channel = 6,
				},

				.TIM5_UP = {
						.Controller = DMA1,
						.Stream = DMA1_Stream6,
						.channel = 6,
				},

				.TIM5_TRIG = {
						.Controller = DMA1,
						.Stream = DMA1_Stream3,
						.channel = 6,
				},


		},


};


#endif /* DMA_DEFS_H_ */

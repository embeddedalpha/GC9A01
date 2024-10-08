/*
 * GPIO_Defs.h
 *
 *  Created on: Oct 13, 2023
 *      Author: Kunal
 */

#ifndef GPIO_DEFS_H_
#define GPIO_DEFS_H_

#include "main.h"


typedef struct {

	uint8_t Input;
	uint8_t General_Purpose_Output;
	uint8_t Alternate_Function;
	uint8_t Analog;

}GPIO_Mode_Type;

typedef struct
{
	uint8_t Push_Pull;
	uint8_t Open_Drain;
}GPIO_Output_Type;

typedef struct 	{
	uint8_t Low_Speed;
	uint8_t Medium_Speed;
	uint8_t High_Speed;
	uint8_t Very_High_Speed;
}GPIO_Speed;

typedef struct 	{
	uint8_t No_Pull_Up_Down;
	uint8_t Pull_Up;
	uint8_t Pull_Down;
}GPIO_Pull;

typedef struct {
    uint8_t None;
    uint8_t Analog;
    uint8_t SYS;
    uint8_t MCO1;
    uint8_t MCO2;
    uint8_t RTC_REFIN;
    uint8_t TIM_1;
    uint8_t TIM_2;
    uint8_t TIM_3;
    uint8_t TIM_4;
    uint8_t TIM_5;
    uint8_t TIM_8;
    uint8_t TIM_9;
    uint8_t TIM_10;
    uint8_t TIM_11;
    uint8_t I2C_1;
    uint8_t I2C_2;
    uint8_t I2C_3;
    uint8_t SPI_1;
    uint8_t SPI_2;
    uint8_t I2S_2;
    uint8_t I2S_2EXT;
    uint8_t SPI_3;
    uint8_t I2S_EXT;
    uint8_t I2S_3;
    uint8_t USART_1;
    uint8_t USART_2;
    uint8_t USART_3;
    uint8_t I2S_3EXT;
    uint8_t USART_4;
    uint8_t UART_5;
    uint8_t USART_6;
    uint8_t CAN_1;
    uint8_t CAN_2;
    uint8_t TIM_12;
    uint8_t TIM_13;
    uint8_t TIM_14;
    uint8_t OTG_FS_1;
    uint8_t OYG_HS_1;
    uint8_t ETH_1;
    uint8_t FSMC_1;
    uint8_t SDIO_1;
    uint8_t OTG_FS_2;
    uint8_t DCMI_1;
    uint8_t EVENTOUT;

}GPIO_Alternate_Function;

typedef struct {
	uint8_t RISING_EDGE;
	uint8_t FALLING_EDGE;
	uint8_t RISING_FALLING_EDGE;
}GPIO_Interrupt_Edge;

static const struct GPIO_Configuration{

	GPIO_Mode_Type Mode;

	GPIO_Output_Type Output_Type;

	GPIO_Speed Speed;

	GPIO_Pull Pull;

	GPIO_Alternate_Function Alternate_Functions;

	GPIO_Interrupt_Edge Interrupt_Edge;


}GPIO_Configuration = {
		.Mode = {
				.Input = 0,
				.General_Purpose_Output = 1,
				.Alternate_Function = 2,
				.Analog = 3,
		},

		.Output_Type = {
			.Push_Pull = 0,
			.Open_Drain = 1,
		},

		.Speed = {
			.Low_Speed = 0,
			.Medium_Speed = 1,
			.High_Speed = 2,
			.Very_High_Speed = 3,
		},

		.Pull =
		{
			.No_Pull_Up_Down = 0,
			.Pull_Up =  1,
			.Pull_Down = 2,
		},

		.Alternate_Functions = {
			    .None = 0,
			    .Analog = 0,
			    .SYS = 0,
			    .MCO1 = 0,
			    .MCO2 = 0,
			    .RTC_REFIN = 1,
			    .TIM_1 = 1,
			    .TIM_2 = 1,
			    .TIM_3 = 2,
			    .TIM_4 = 2,
			    .TIM_5 = 2,
			    .TIM_8 = 3,
			    .TIM_9 = 3,
			    .TIM_10 = 3,
			    .TIM_11 = 3,
			    .I2C_1 = 4,
			    .I2C_2 = 4,
			    .I2C_3 = 4,
			    .SPI_1 = 5,
			    .SPI_2 = 5,
			    .I2S_2 = 5,
			    .I2S_2EXT = 5,
			    .SPI_3 = 6,
			    .I2S_EXT = 6,
			    .I2S_3 = 6,
			    .USART_1 = 7,
			    .USART_2 = 7,
			    .USART_3 = 7,
			    .I2S_3EXT = 7,
			    .USART_4 = 8,
			    .UART_5 = 8,
			    .USART_6 = 8,
			    .CAN_1 = 9,
			    .CAN_2 = 9,
			    .TIM_12 = 9,
			    .TIM_13 = 9,
			    .TIM_14 = 9,
			    .OTG_FS_1 = 10,
			    .OYG_HS_1 = 10,
			    .ETH_1 = 11,
			    .FSMC_1 = 12,
			    .SDIO_1 = 12,
			    .OTG_FS_2 = 12,
			    .DCMI_1 = 13,
			    .EVENTOUT = 15
			},

		.Interrupt_Edge =
		{
				.RISING_EDGE = 0,
				.FALLING_EDGE = 1,
				.RISING_FALLING_EDGE = 2,
		},
};






#endif /* GPIO_DEFS_H_ */

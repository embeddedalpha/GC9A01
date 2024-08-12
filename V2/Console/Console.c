/*
 * Console.c
 *
 *  Created on: Dec 19, 2023
 *      Author: kunal
 */


#include "Console.h"
#include "DMA.h"

USART_Config serial;
DMA_Config serial_DMA;


 void Console_Init(int32_t baudrate)
{
	 USART_Config_Reset(&serial);
	 serial.Port = USART1;
	 serial.baudrate = baudrate;
	 serial.mode = USART_Configuration.Mode.Asynchronous;
	 serial.stop_bits = USART_Configuration.Stop_Bits.Bit_1;
	 serial.TX_Pin = USART1_TX_Pin.PB6;
	 serial.RX_Pin = USART1_RX_Pin.PB7;
	 USART_Init(&serial);


}

 void printConsole(char *msg, ...)
{

char buff[10000];
//	#ifdef DEBUG_UART

	va_list args;
	va_start(args, msg);
	vsprintf(buff, msg, args);

	serial_DMA.Request = DMA_Configuration.Request.USART1_TX;
	serial_DMA.Flow_control = DMA_Configuration.Flow_Control.DMA_Control;
	serial_DMA.Transfer_direction = DMA_Configuration.Transfer_Direction.Memory_to_peripheral;
	serial_DMA.circular_mode = DMA_Configuration.Circular_Mode.Enable;
	serial_DMA.memory_data_size = DMA_Configuration.Memory_Data_Size.byte;
	serial_DMA.memory_pointer_increment = DMA_Configuration.Memory_Pointer_Increment.Enable;


	for(int i = 0; i<= strlen(buff)-1; i++)
	{
		serial.Port -> DR = buff[i];
		while (!(serial.Port -> SR & USART_SR_TXE));
	}
}

char readConsole(void)
{
	char retval = 0;
	while(!(serial.Port -> SR & USART_SR_RXNE));
	retval = serial.Port-> DR;

	return retval;
}



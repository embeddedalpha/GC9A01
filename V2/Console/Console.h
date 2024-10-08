/*
 * Console.h
 *
 *  Created on: Dec 19, 2023
 *      Author: kunal
 */

#ifndef CONSOLE_H_
#define CONSOLE_H_

#include "main.h"
#include "GPIO.h"
#include "USART.h"
#include "DMA.h"


void Console_Init(int32_t baudrate);
 void printConsole(char *msg, ...);
 char readConsole(void);


#endif /* CONSOLE_H_ */

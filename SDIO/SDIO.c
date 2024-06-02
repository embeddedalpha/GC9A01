/*
 * SDIO.c
 *
 *  Created on: May 31, 2024
 *      Author: kunal
 */

#include "SDIO.h"

void SDIO_Card_Power_Off(void)
{
	SDIO -> POWER = 0x00;
}

void SDIO_Card_Power_ON(void)
{
	SDIO -> POWER = 0x03;
}

void SDIO_SendCommand(uint32_t cmdIndex, uint32_t argument, uint32_t responseType) {
    // Clear the command flags
    SDIO->ICR = SDIO_ICR_CMDSENTC;

    // Configure the command
    SDIO->ARG = argument;
    SDIO->CMD = (cmdIndex & SDIO_CMD_CMDINDEX) | responseType | SDIO_CMD_CPSMEN;

    // Wait until the command is sent (CMDSENT flag)
    while (!(SDIO->STA & SDIO_STA_CMDSENT)) {
        // Optional: Add timeout mechanism to avoid infinite loop
    }
}

uint32_t SDIO_GetResponse(void) {
    // Wait until response is received (CMDREND or CCRCFAIL flag)
    while (!(SDIO->STA & (SDIO_STA_CMDREND | SDIO_STA_CCRCFAIL))) {
        // Optional: Add timeout mechanism to avoid infinite loop
    }

    // Check for CRC error
    if (SDIO->STA & SDIO_STA_CCRCFAIL) {
        SDIO->ICR = SDIO_ICR_CCRCFAILC; // Clear the CRC fail flag
        return 0xFFFFFFFF; // Indicate error
    }

    // Read and return the response
    return SDIO->RESP1;
}





int8_t SDIO_Init(SDIO_Config *config)
{
	RCC  -> APB2ENR |= RCC_APB2ENR_SDIOEN;
	SDIO -> CLKCR |= config->Bus_Mode;
	SDIO->CLKCR |= SDIO_CLKCR_CLKEN | (0x1 << SDIO_CLKCR_CLKDIV_Pos);

	if(config->Bus_Mode == SDIO_Bus_Mode.bit1)
	{
		GPIO_Pin_Init(GPIOC, 8, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
	}
	else if(config->Bus_Mode == SDIO_Bus_Mode.bit4)
	{
		GPIO_Pin_Init(GPIOC, 8, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
		GPIO_Pin_Init(GPIOC, 9, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
		GPIO_Pin_Init(GPIOC, 10, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
		GPIO_Pin_Init(GPIOC, 11, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
	}
	else if(config->Bus_Mode == SDIO_Bus_Mode.bit4)
	{
		GPIO_Pin_Init(GPIOC, 8, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
		GPIO_Pin_Init(GPIOC, 9, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
		GPIO_Pin_Init(GPIOC, 10, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
		GPIO_Pin_Init(GPIOC, 11, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
	}
	else
	{
		return -1;
	}

	SDIO_Card_Power_ON();

	SDIO->CLKCR = SDIO_CLKCR_CLKEN |  (0x76 << SDIO_CLKCR_CLKDIV_Pos); // Set Clock Divider (24MHz/(118+2) = 200kHz for init)

	SDIO->CLKCR |= SDIO_CLKCR_CLKEN;











	SDIO_SendCommand(SDIO_Commands.GO_IDLE_STATE.commandIndex, SDIO_Commands.GO_IDLE_STATE.argument, SDIO_Commands.GO_IDLE_STATE.responseType);

	return 1;
}

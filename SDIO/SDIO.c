///*
// * SDIO.c
// *
// *  Created on: May 31, 2024
// *      Author: kunal
// */
//
//#include "SDIO.h"
//
//void SDIO_Card_Power_Off(void)
//{
//	SDIO -> POWER = 0x00;
//}
//
//void SDIO_Card_Power_ON(void)
//{
//	SDIO -> POWER = 0x03;
//}
//
//void SDIO_SendCommand(SDIO_Command command)
////void SDIO_SendCommand(uint32_t cmdIndex, uint32_t argument, uint32_t responseType)
//{
//    // Clear the command flags
//    SDIO->ICR = SDIO_ICR_CMDSENTC;
//
//    // Configure the command
//    SDIO->ARG = command.argument;
//    SDIO->CMD = (command.commandIndex & SDIO_CMD_CMDINDEX) | command.responseType | SDIO_CMD_CPSMEN;
//
//    // Wait until the command is sent (CMDSENT flag)
//    while (!(SDIO->STA & SDIO_STA_CMDSENT)) {
//        // Optional: Add timeout mechanism to avoid infinite loop
//    }
//}
//
//uint32_t SDIO_GetResponse(void) {
//    // Wait until response is received (CMDREND or CCRCFAIL flag)
//    while (!(SDIO->STA & (SDIO_STA_CMDREND | SDIO_STA_CCRCFAIL))) {
//        // Optional: Add timeout mechanism to avoid infinite loop
//    }
//
//    // Check for CRC error
//    if (SDIO->STA & SDIO_STA_CCRCFAIL) {
//        SDIO->ICR = SDIO_ICR_CCRCFAILC; // Clear the CRC fail flag
//        return 0xFFFFFFFF; // Indicate error
//    }
//
//    // Read and return the response
//    return SDIO->RESP1;
//}
//
//
//
//
//
//int8_t SDIO_Init(SDIO_Config *config)
//{
//	RCC  -> APB2ENR |= RCC_APB2ENR_SDIOEN;
//	SDIO -> CLKCR |= config->Bus_Mode;
//	SDIO->CLKCR |= SDIO_CLKCR_CLKEN | (0x1 << SDIO_CLKCR_CLKDIV_Pos);
//
//	if(config->Bus_Mode == SDIO_Bus_Mode.bit1)
//	{
//		GPIO_Pin_Init(GPIOC, 8, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
//	}
//	else if(config->Bus_Mode == SDIO_Bus_Mode.bit4)
//	{
//		GPIO_Pin_Init(GPIOC, 8, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
//		GPIO_Pin_Init(GPIOC, 9, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
//		GPIO_Pin_Init(GPIOC, 10, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
//		GPIO_Pin_Init(GPIOC, 11, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
//	}
//	else if(config->Bus_Mode == SDIO_Bus_Mode.bit4)
//	{
//		GPIO_Pin_Init(GPIOC, 8, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
//		GPIO_Pin_Init(GPIOC, 9, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
//		GPIO_Pin_Init(GPIOC, 10, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
//		GPIO_Pin_Init(GPIOC, 11, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
//	}
//	else
//	{
//		return -1;
//	}
//
//	SDIO_Card_Power_ON();
//
//	SDIO->CLKCR = SDIO_CLKCR_CLKEN |  (0x76 << SDIO_CLKCR_CLKDIV_Pos); // Set Clock Divider (24MHz/(118+2) = 200kHz for init)
//
//	SDIO->CLKCR |= SDIO_CLKCR_CLKEN;
//
//
//	SDIO_SendCommand(SDIO_Commands.GO_IDLE_STATE);
////	SDIO_SendCommand(SDIO_Commands.GO_IDLE_STATE.commandIndex, SDIO_Commands.GO_IDLE_STATE.argument, SDIO_Commands.GO_IDLE_STATE.responseType);
//
//	SDIO_SendCommand(SDIO_Commands.SEND_IF_COND);
////	SDIO_SendCommand(SDIO_Commands.SEND_IF_COND.commandIndex, SDIO_Commands.SEND_IF_COND.argument, SDIO_Commands.SEND_IF_COND.responseType);
//    uint32_t response = SDIO_GetResponse();
//    if ((response & 0xFFF) != 0x1AA)
//    {
//        // Card does not support the required voltage range
//        return -2;
//    }
//
//    while (1) {
//    	SDIO_SendCommand(SDIO_Commands.APP_CMD);
////        SDIO_SendCommand(SDIO_Commands.APP_CMD.commandIndex, SDIO_Commands.APP_CMD.argument, SDIO_Commands.APP_CMD.responseType);
//        // Check response and proceed if CMD55 was successful
//        if (SDIO_GetResponse() & 0x20) { // Check APP_CMD bit
//        	SDIO_SendCommand(SDIO_Commands.SEND_OP_COND);
////            SDIO_SendCommand(SDIO_Commands.SEND_OP_COND.commandIndex, SDIO_Commands.SEND_OP_COND.argument, SDIO_Commands.SEND_OP_COND.responseType); // HCS (Host Capacity Support) set
//        }
//        response = SDIO_GetResponse();
//        if (response & 0x80000000) { // Check if card is ready
//            break;
//        }
//    }
//
//    SDIO_SendCommand(SDIO_Commands.ALL_SEND_CID);
////    SDIO_SendCommand(SDIO_Commands.ALL_SEND_CID.commandIndex, SDIO_Commands.ALL_SEND_CID.argument, SDIO_Commands.ALL_SEND_CID.responseType);
//    uint32_t cid[4];
//    cid[0] = SDIO->RESP1;
//    cid[1] = SDIO->RESP2;
//    cid[2] = SDIO->RESP3;
//    cid[3] = SDIO->RESP4;
//
//    SDIO_SendCommand(SDIO_Commands.SEND_RELATIVE_ADDR);
////    SDIO_SendCommand(SDIO_Commands.SEND_RELATIVE_ADDR.commandIndex, SDIO_Commands.SEND_RELATIVE_ADDR.argument, SDIO_Commands.SEND_RELATIVE_ADDR.responseType);
//    uint32_t rca = SDIO_GetResponse() & 0xFFFF0000;
//
//    // Select the card with CMD7
//    SDIO_SendCommand(SDIO_Commands.SELECT_DESELECT_CARD);
////    SDIO_SendCommand(SDIO_Commands.SELECT_DESELECT_CARD.commandIndex, rca, SDIO_Commands.SELECT_DESELECT_CARD.responseType);
//
//    // Set block length with CMD16
//    SDIO_SendCommand(SDIO_Commands.SET_BLOCKLEN);
////    SDIO_SendCommand(SDIO_Commands.SET_BLOCKLEN.commandIndex, SDIO_Commands.SET_BLOCKLEN.argument, SDIO_Commands.SET_BLOCKLEN.responseType);
//
//    // Card is now ready for data transfer
//
//	return 1;
//}
//
//void SDIO_WriteSingleBlock(uint32_t blockAddr, const uint8_t* buffer) {
//    // Set block length to 512 bytes
//    SDIO_SendCommand(SDIO_Commands.SET_BLOCKLEN);
//
//    // Set the block address to write to
//    SDIO_Commands.WRITE_BLOCK.argument = blockAddr;
//    SDIO_SendCommand(SDIO_Commands.WRITE_BLOCK);
//
//    // Wait for the card to be ready for data
//    while (!(SDIO->STA & SDIO_STA_TXACT)) {}
//
//    // Write the data from the buffer
//    for (uint32_t i = 0; i < 512 / 4; i++) {
//        while (!(SDIO->STA & SDIO_STA_TXFIFOHE)) {}
//        SDIO->FIFO = ((const uint32_t*)buffer)[i];
//    }
//
//    // Wait for the transfer to complete
//    while (!(SDIO->STA & SDIO_STA_DATAEND)) {}
//
//    // Clear data flags
//    SDIO->ICR = SDIO_ICR_DATAENDC | SDIO_ICR_DBCKENDC;
//}
//
//void SDIO_ReadSingleBlock(uint32_t blockAddr, uint8_t* buffer) {
//    // Set block length to 512 bytes
//    SDIO_SendCommand(SDIO_Commands.SET_BLOCKLEN);
//
//    // Set the block address to read from
//    SDIO_Commands.READ_SINGLE_BLOCK.argument = blockAddr;
//    SDIO_SendCommand(SDIO_Commands.READ_SINGLE_BLOCK);
//
//    // Wait for the data block to be received
//    while (!(SDIO->STA & SDIO_STA_RXACT)) {}
//
//    // Read the data into the buffer
//    for (uint32_t i = 0; i < 512 / 4; i++) {
//        while (!(SDIO->STA & SDIO_STA_RXDAVL)) {}
//        ((uint32_t*)buffer)[i] = SDIO->FIFO;
//    }
//
//    // Wait for the transfer to complete
//    while (!(SDIO->STA & SDIO_STA_DATAEND)) {}
//
//    // Clear data flags
//    SDIO->ICR = SDIO_ICR_DATAENDC | SDIO_ICR_DBCKENDC;
//}
//

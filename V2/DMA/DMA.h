/*
 * DMA.h
 *
 *  Created on: Jul 20, 2024
 *      Author: kunal
 */

#ifndef DMA_H_
#define DMA_H_

#include "main.h"
#include "DMA_Defs.h"

typedef struct DMA_Config
{
	DMA_Request Request;
	uint32_t Flow_control;                //Use DMA_Flow_Control
	uint32_t Transfer_direction;          //Use DMA_Transfer_Direction
	uint32_t flow_control;                //Use DMA_Flow_Control
	uint32_t transfer_direction;          //Use DMA_Transfer_Direction
	uint32_t priority_level;              //Use DMA_Priority_Level
	uint32_t peripheral_data_size;        //Use DMA_Peripheral_Data_Size
	uint32_t memory_data_size;            //Use DMA_Memory_Data_Size
	uint32_t circular_mode;               //Use DMA_Circular_Mode
	uint32_t interrupts;                  //Use DMA_Interrupts
	uint32_t peripheral_address;
	uint32_t memory_address;
	uint16_t buffer_length;
	uint16_t memory_pointer_increment;
	uint16_t peripheral_pointer_increment;

}DMA_Config;

void DMA_Clock_Enable(DMA_Config *config);
void DMA_Clock_Disable(DMA_Config *config);
void DMA_Reset(DMA_Config *config);

void DMA_Init(DMA_Config *config);
void DMA_Set_Target(DMA_Config *config);
void DMA_Set_Trigger(DMA_Config *config);


#endif /* DMA_H_ */

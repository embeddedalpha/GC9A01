/*
 * DMA.c
 *
 *  Created on: Jul 20, 2024
 *      Author: kunal
 */

#include "DMA.h"



void DMA_Clock_Enable(DMA_Config *config)
{
	if(config -> Request.Controller == DMA1) RCC -> AHB1ENR |= RCC_AHB1ENR_DMA1EN;
	if(config -> Request.Controller == DMA2) RCC -> AHB1ENR |= RCC_AHB1ENR_DMA2EN;
}
//

void DMA_Clock_Disable(DMA_Config *config)
{

	if(config -> Request.Controller == DMA1) RCC -> AHB1ENR &= ~RCC_AHB1ENR_DMA1EN;
	if(config -> Request.Controller == DMA2) RCC -> AHB1ENR &= ~RCC_AHB1ENR_DMA2EN;
}
//

void DMA_Reset(DMA_Config *config)
{
	if(config -> Request.Controller == DMA1) RCC -> AHB1RSTR |= RCC_AHB1RSTR_DMA1RST;
	if(config -> Request.Controller == DMA2) RCC -> AHB1RSTR |= RCC_AHB1RSTR_DMA2RST;
}

void DMA_Init(DMA_Config *config)
{
	DMA_Clock_Enable(config);
	config -> Request.Stream -> CR |= config -> Request.channel << DMA_SxCR_CHSEL_Pos;
	config -> Request.Stream -> CR |= config -> circular_mode;
	config -> Request.Stream -> CR |= config -> flow_control;
	config -> Request.Stream -> CR |= config -> priority_level;
	config -> Request.Stream -> CR |= config -> memory_data_size;
	config -> Request.Stream -> CR |= config -> peripheral_data_size;
	config -> Request.Stream -> CR |= config -> transfer_direction;
	config -> Request.Stream -> CR |= config -> interrupts;
	config -> Request.Stream -> CR |= config -> memory_pointer_increment;
	config -> Request.Stream -> CR |= config -> peripheral_pointer_increment;
}

void DMA_Set_Target(DMA_Config *config)
{
	config -> Request.Stream ->NDTR = config -> buffer_length;
	config -> Request.Stream ->M0AR = (uint32_t)config->memory_address;
	config -> Request.Stream ->PAR = (uint32_t)config->peripheral_address;
}


void DMA_Set_Trigger(DMA_Config *config)
{
    // Bit shift values for streams 0 to 7
    static const uint8_t LIFCR_Shifts[4] = {0, 6, 16, 22};
    static const uint8_t HIFCR_Shifts[4] = {0, 6, 16, 22};

    DMA_TypeDef *controller = config->Request.Controller;
    DMA_Stream_TypeDef *stream = config->Request.Stream;
    uint32_t shift;

    if (controller == DMA1 || controller == DMA2)   {
        if (stream >= DMA1_Stream0 && stream <= DMA1_Stream3)
        {
            shift = LIFCR_Shifts[stream - DMA1_Stream0];
            controller->LIFCR |= 0x3F << shift;
        }
        else if (stream >= DMA1_Stream4 && stream <= DMA1_Stream7)
        {
            shift = HIFCR_Shifts[stream - DMA1_Stream4];
            controller->HIFCR |= 0x3F << shift;
        }
        else if (stream >= DMA2_Stream0 && stream <= DMA2_Stream3)
        {
            shift = LIFCR_Shifts[stream - DMA2_Stream0];
            controller->LIFCR |= 0x3F << shift;
        }
        else if (stream >= DMA2_Stream4 && stream <= DMA2_Stream7)
        {
            shift = HIFCR_Shifts[stream - DMA2_Stream4];
            controller->HIFCR |= 0x3F << shift;
        }

        stream->CR |= DMA_SxCR_EN;
    }
}




//void DMA_Set_Trigger(DMA_Config *config)
//{
//	if(config->Request.Controller == DMA1)
//	{
//		if(config->Request.Stream == DMA1_Stream0)
//		{
//			config -> Request.Controller ->LIFCR |= 0x3F << 0;
//		}
//		else if(config->Request.Stream == DMA1_Stream1)
//		{
//			config -> Request.Controller ->LIFCR |= 0x3F << 6;
//		}
//		else if(config->Request.Stream == DMA1_Stream2)
//		{
//			config -> Request.Controller ->LIFCR |= 0x3F << 16;
//		}
//		else if(config->Request.Stream == DMA1_Stream3)
//		{
//			config -> Request.Controller ->LIFCR |= 0x3F << 22;
//		}
//		else if(config->Request.Stream == DMA1_Stream4)
//		{
//			config -> Request.Controller ->HIFCR |= 0x3F << 0;
//		}
//		else if(config->Request.Stream == DMA1_Stream5)
//		{
//			config -> Request.Controller ->HIFCR |= 0x3F << 6;
//		}
//		else if(config->Request.Stream == DMA1_Stream6)
//		{
//			config -> Request.Controller ->HIFCR |= 0x3F << 16;
//		}
//		else if(config->Request.Stream == DMA1_Stream7)
//		{
//			config -> Request.Controller ->HIFCR |= 0x3F << 22;
//		}
//
//	}
//	else
//	{
//		if(config->Request.Stream == DMA2_Stream0)
//		{
//			config -> Request.Controller ->LIFCR |= 0x3F << 0;
//		}
//		else if(config->Request.Stream == DMA2_Stream1)
//		{
//			config -> Request.Controller ->LIFCR |= 0x3F << 6;
//		}
//		else if(config->Request.Stream == DMA2_Stream2)
//		{
//			config -> Request.Controller ->LIFCR |= 0x3F << 16;
//		}
//		else if(config->Request.Stream == DMA2_Stream3)
//		{
//			config -> Request.Controller ->LIFCR |= 0x3F << 22;
//		}
//		else if(config->Request.Stream == DMA2_Stream4)
//		{
//			config -> Request.Controller ->HIFCR |= 0x3F << 0;
//		}
//		else if(config->Request.Stream == DMA2_Stream5)
//		{
//			config -> Request.Controller ->HIFCR |= 0x3F << 6;
//		}
//		else if(config->Request.Stream == DMA1_Stream6)
//		{
//			config -> Request.Controller ->HIFCR |= 0x3F << 16;
//		}
//		else if(config->Request.Stream == DMA2_Stream7)
//		{
//			config -> Request.Controller ->HIFCR |= 0x3F << 22;
//		}
//	}
//
//	config -> Request.Stream -> CR |= DMA_SxCR_EN;
//}

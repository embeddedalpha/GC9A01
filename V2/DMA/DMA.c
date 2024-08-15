/*
 * DMA.c
 *
 *  Created on: Jul 20, 2024
 *      Author: kunal
 */

#include "DMA.h"


DMA_Flags_Typedef DMA1_Stream0_Flag;
DMA_Flags_Typedef DMA1_Stream1_Flag;
DMA_Flags_Typedef DMA1_Stream2_Flag;
DMA_Flags_Typedef DMA1_Stream3_Flag;
DMA_Flags_Typedef DMA1_Stream4_Flag;
DMA_Flags_Typedef DMA1_Stream5_Flag;
DMA_Flags_Typedef DMA1_Stream6_Flag;
DMA_Flags_Typedef DMA1_Stream7_Flag;

DMA_Flags_Typedef DMA2_Stream0_Flag;
DMA_Flags_Typedef DMA2_Stream1_Flag;
DMA_Flags_Typedef DMA2_Stream2_Flag;
DMA_Flags_Typedef DMA2_Stream3_Flag;
DMA_Flags_Typedef DMA2_Stream4_Flag;
DMA_Flags_Typedef DMA2_Stream5_Flag;
DMA_Flags_Typedef DMA2_Stream6_Flag;
DMA_Flags_Typedef DMA2_Stream7_Flag;


void DMA1_Stream0_IRQHandler(void)
{
	if(DMA1 -> LISR & DMA_LISR_FEIF0)
	{
		DMA1_Stream0_Flag.Fifo_Error_Flag = true;
		DMA1 -> LIFCR |= DMA_LIFCR_CFEIF0;
	}
	/************************************************************************************************************/
	else if(DMA1 -> LISR & DMA_LISR_DMEIF0)
	{
		DMA1_Stream0_Flag.Direct_Mode_Error_Flag = true;
		DMA1 -> LIFCR |= DMA_LIFCR_CDMEIF0;
	}
	/************************************************************************************************************/
	else if(DMA1 -> LISR & DMA_LISR_TEIF0)
	{
		DMA1_Stream0_Flag.Transfer_Error_Flag = true;
		DMA1 -> LIFCR |= DMA_LIFCR_CTEIF0;
	}
	/************************************************************************************************************/
	else if(DMA1 -> LISR & DMA_LISR_HTIF0)
	{
		DMA1_Stream0_Flag.Half_Transfer_Complete_Flag = true;
		DMA1 -> LIFCR |= DMA_LIFCR_CHTIF0;
	}
	/************************************************************************************************************/
	else if(DMA1 -> LISR & DMA_LISR_TCIF0)
	{
		DMA1_Stream0_Flag.Transfer_Complete_Flag = true;
		DMA1 -> LIFCR |= DMA_LIFCR_CTCIF0;
	}
}

void DMA1_Stream1_IRQHandler(void)
{
	if(DMA1 -> LISR & DMA_LISR_FEIF1)
	{
		DMA1_Stream1_Flag.Fifo_Error_Flag = true;
		DMA1 -> LIFCR |= DMA_LIFCR_CFEIF1;
	}
	/************************************************************************************************************/
	else if(DMA1 -> LISR & DMA_LISR_DMEIF1)
	{
		DMA1_Stream1_Flag.Direct_Mode_Error_Flag = true;
		DMA1 -> LIFCR |= DMA_LIFCR_CDMEIF1;
	}
	/************************************************************************************************************/
	else if(DMA1 -> LISR & DMA_LISR_TEIF1)
	{
		DMA1_Stream1_Flag.Transfer_Error_Flag = true;
		DMA1 -> LIFCR |= DMA_LIFCR_CTEIF1;
	}
	/************************************************************************************************************/
	else if(DMA1 -> LISR & DMA_LISR_HTIF1)
	{
		DMA1_Stream1_Flag.Half_Transfer_Complete_Flag = true;
		DMA1 -> LIFCR |= DMA_LIFCR_CHTIF1;
	}
	/************************************************************************************************************/
	else if(DMA1 -> LISR & DMA_LISR_TCIF1)
	{
		DMA1_Stream1_Flag.Transfer_Complete_Flag = true;
		DMA1 -> LIFCR |= DMA_LIFCR_CTCIF1;
	}
}

void DMA1_Stream2_IRQHandler(void)
{
	if(DMA1 -> LISR & DMA_LISR_FEIF2)
	{
		DMA1_Stream2_Flag.Fifo_Error_Flag = true;
		DMA1 -> LIFCR |= DMA_LIFCR_CFEIF2;
	}
	/************************************************************************************************************/
	else if(DMA1 -> LISR & DMA_LISR_DMEIF2)
	{
		DMA1_Stream2_Flag.Direct_Mode_Error_Flag = true;
		DMA1 -> LIFCR |= DMA_LIFCR_CDMEIF2;
	}
	/************************************************************************************************************/
	else if(DMA1 -> LISR & DMA_LISR_TEIF2)
	{
		DMA1_Stream2_Flag.Transfer_Error_Flag = true;
		DMA1 -> LIFCR |= DMA_LIFCR_CTEIF2;
	}
	/************************************************************************************************************/
	else if(DMA1 -> LISR & DMA_LISR_HTIF2)
	{
		DMA1_Stream2_Flag.Half_Transfer_Complete_Flag = true;
		DMA1 -> LIFCR |= DMA_LIFCR_CHTIF2;
	}
	/************************************************************************************************************/
	else if(DMA1 -> LISR & DMA_LISR_TCIF2)
	{
		DMA1_Stream2_Flag.Transfer_Complete_Flag = true;
		DMA1 -> LIFCR |= DMA_LIFCR_CTCIF2;
	}
}

void DMA1_Stream3_IRQHandler(void)
{
	if(DMA1 -> LISR & DMA_LISR_FEIF3)
	{
		DMA1_Stream3_Flag.Fifo_Error_Flag = true;
		DMA1 -> LIFCR |= DMA_LIFCR_CFEIF3;
	}
	/************************************************************************************************************/
	else if(DMA1 -> LISR & DMA_LISR_DMEIF3)
	{
		DMA1_Stream3_Flag.Direct_Mode_Error_Flag = true;
		DMA1 -> LIFCR |= DMA_LIFCR_CDMEIF3;
	}
	/************************************************************************************************************/
	else if(DMA1 -> LISR & DMA_LISR_TEIF3)
	{
		DMA1_Stream3_Flag.Transfer_Error_Flag = true;
		DMA1 -> LIFCR |= DMA_LIFCR_CTEIF3;
	}
	/************************************************************************************************************/
	else if(DMA1 -> LISR & DMA_LISR_HTIF3)
	{
		DMA1_Stream3_Flag.Half_Transfer_Complete_Flag = true;
		DMA1 -> LIFCR |= DMA_LIFCR_CHTIF3;
	}
	/************************************************************************************************************/
	else if(DMA1 -> LISR & DMA_LISR_TCIF3)
	{
		DMA1_Stream3_Flag.Transfer_Complete_Flag = true;
		DMA1 -> LIFCR |= DMA_LIFCR_CTCIF3;
	}
}

void DMA1_Stream4_IRQHandler(void)
{
	if(DMA1 -> HISR & DMA_HISR_FEIF4)
	{
		DMA1_Stream4_Flag.Fifo_Error_Flag = true;
		DMA1 -> HIFCR |= DMA_HIFCR_CFEIF4;
	}
	/************************************************************************************************************/
	else if(DMA1 -> HISR & DMA_HISR_DMEIF4)
	{
		DMA1_Stream4_Flag.Direct_Mode_Error_Flag = true;
		DMA1 -> HIFCR |= DMA_HIFCR_CDMEIF4;
	}
	/************************************************************************************************************/
	else if(DMA1 -> HISR & DMA_HISR_TEIF4)
	{
		DMA1_Stream4_Flag.Transfer_Error_Flag = true;
		DMA1 -> HIFCR |= DMA_HIFCR_CTEIF4;
	}
	/************************************************************************************************************/
	else if(DMA1 -> HISR & DMA_HISR_HTIF4)
	{
		DMA1_Stream4_Flag.Half_Transfer_Complete_Flag = true;
		DMA1 -> HIFCR |= DMA_HIFCR_CHTIF4;
	}
	/************************************************************************************************************/
	else if(DMA1 -> HISR & DMA_HISR_TCIF4)
	{
		DMA1_Stream4_Flag.Transfer_Complete_Flag = true;
		DMA1 -> HIFCR |= DMA_HIFCR_CTCIF4;
	}
}

void DMA1_Stream5_IRQHandler(void)
{
	if(DMA1 -> HISR & DMA_HISR_FEIF5)
	{
		DMA1_Stream5_Flag.Fifo_Error_Flag = true;
		DMA1 -> HIFCR |= DMA_HIFCR_CFEIF5;
	}
	/************************************************************************************************************/
	else if(DMA1 -> HISR & DMA_HISR_DMEIF5)
	{
		DMA1_Stream5_Flag.Direct_Mode_Error_Flag = true;
		DMA1 -> HIFCR |= DMA_HIFCR_CDMEIF5;
	}
	/************************************************************************************************************/
	else if(DMA1 -> HISR & DMA_HISR_TEIF5)
	{
		DMA1_Stream5_Flag.Transfer_Error_Flag = true;
		DMA1 -> HIFCR |= DMA_HIFCR_CTEIF5;
	}
	/************************************************************************************************************/
	else if(DMA1 -> HISR & DMA_HISR_HTIF5)
	{
		DMA1_Stream5_Flag.Half_Transfer_Complete_Flag = true;
		DMA1 -> HIFCR |= DMA_HIFCR_CHTIF5;
	}
	/************************************************************************************************************/
	else if(DMA1 -> HISR & DMA_HISR_TCIF5)
	{
		DMA1_Stream5_Flag.Transfer_Complete_Flag = true;
		DMA1 -> HIFCR |= DMA_HIFCR_CTCIF5;
	}
}

void DMA1_Stream6_IRQHandler(void)
{
	if(DMA1 -> HISR & DMA_HISR_FEIF6)
	{
		DMA1_Stream6_Flag.Fifo_Error_Flag = true;
		DMA1 -> HIFCR |= DMA_HIFCR_CFEIF6;
	}
	/************************************************************************************************************/
	else if(DMA1 -> HISR & DMA_HISR_DMEIF6)
	{
		DMA1_Stream6_Flag.Direct_Mode_Error_Flag = true;
		DMA1 -> HIFCR |= DMA_HIFCR_CDMEIF6;
	}
	/************************************************************************************************************/
	else if(DMA1 -> HISR & DMA_HISR_TEIF6)
	{
		DMA1_Stream6_Flag.Transfer_Error_Flag = true;
		DMA1 -> HIFCR |= DMA_HIFCR_CTEIF6;
	}
	/************************************************************************************************************/
	else if(DMA1 -> HISR & DMA_HISR_HTIF6)
	{
		DMA1_Stream6_Flag.Half_Transfer_Complete_Flag = true;
		DMA1 -> HIFCR |= DMA_HIFCR_CHTIF6;
	}
	/************************************************************************************************************/
	else if(DMA1 -> HISR & DMA_HISR_TCIF6)
	{
		DMA1_Stream6_Flag.Transfer_Complete_Flag = true;
		DMA1 -> HIFCR |= DMA_HIFCR_CTCIF6;
	}
}

void DMA1_Stream7_IRQHandler(void)
{
	if(DMA1 -> HISR & DMA_HISR_FEIF7)
	{
		DMA1_Stream7_Flag.Fifo_Error_Flag = true;
		DMA1 -> HIFCR |= DMA_HIFCR_CFEIF7;
	}
	/************************************************************************************************************/
	else if(DMA1 -> HISR & DMA_HISR_DMEIF7)
	{
		DMA1_Stream7_Flag.Direct_Mode_Error_Flag = true;
		DMA1 -> HIFCR |= DMA_HIFCR_CDMEIF7;
	}
	/************************************************************************************************************/
	else if(DMA1 -> HISR & DMA_HISR_TEIF7)
	{
		DMA1_Stream7_Flag.Transfer_Error_Flag = true;
		DMA1 -> HIFCR |= DMA_HIFCR_CTEIF7;
	}
	/************************************************************************************************************/
	else if(DMA1 -> HISR & DMA_HISR_HTIF7)
	{
		DMA1_Stream7_Flag.Half_Transfer_Complete_Flag = true;
		DMA1 -> HIFCR |= DMA_HIFCR_CHTIF7;
	}
	/************************************************************************************************************/
	else if(DMA1 -> HISR & DMA_HISR_TCIF7)
	{
		DMA1_Stream7_Flag.Transfer_Complete_Flag = true;
		DMA1 -> HIFCR |= DMA_HIFCR_CTCIF7;
	}
}


void DMA2_Stream0_IRQHandler(void)
{
	if(DMA2 -> LISR & DMA_LISR_FEIF0)
	{
		DMA2_Stream0_Flag.Fifo_Error_Flag = true;
		DMA2 -> LIFCR |= DMA_LIFCR_CFEIF0;
	}
	/************************************************************************************************************/
	else if(DMA2 -> LISR & DMA_LISR_DMEIF0)
	{
		DMA2_Stream0_Flag.Direct_Mode_Error_Flag = true;
		DMA2 -> LIFCR |= DMA_LIFCR_CDMEIF0;
	}
	/************************************************************************************************************/
	else if(DMA2 -> LISR & DMA_LISR_TEIF0)
	{
		DMA2_Stream0_Flag.Transfer_Error_Flag = true;
		DMA2 -> LIFCR |= DMA_LIFCR_CTEIF0;
	}
	/************************************************************************************************************/
	else if(DMA2 -> LISR & DMA_LISR_HTIF0)
	{
		DMA2_Stream0_Flag.Half_Transfer_Complete_Flag = true;
		DMA2 -> LIFCR |= DMA_LIFCR_CHTIF0;
	}
	/************************************************************************************************************/
	else if(DMA2 -> LISR & DMA_LISR_TCIF0)
	{
		DMA2_Stream0_Flag.Transfer_Complete_Flag = true;
		DMA2 -> LIFCR |= DMA_LIFCR_CTCIF0;
	}
}

void DMA2_Stream1_IRQHandler(void)
{
	if(DMA2 -> LISR & DMA_LISR_FEIF1)
	{
		DMA2_Stream1_Flag.Fifo_Error_Flag = true;
		DMA2 -> LIFCR |= DMA_LIFCR_CFEIF1;
	}
	/************************************************************************************************************/
	else if(DMA2 -> LISR & DMA_LISR_DMEIF1)
	{
		DMA2_Stream1_Flag.Direct_Mode_Error_Flag = true;
		DMA2 -> LIFCR |= DMA_LIFCR_CDMEIF1;
	}
	/************************************************************************************************************/
	else if(DMA2 -> LISR & DMA_LISR_TEIF1)
	{
		DMA2_Stream1_Flag.Transfer_Error_Flag = true;
		DMA2 -> LIFCR |= DMA_LIFCR_CTEIF1;
	}
	/************************************************************************************************************/
	else if(DMA2 -> LISR & DMA_LISR_HTIF1)
	{
		DMA2_Stream1_Flag.Half_Transfer_Complete_Flag = true;
		DMA2 -> LIFCR |= DMA_LIFCR_CHTIF1;
	}
	/************************************************************************************************************/
	else if(DMA2 -> LISR & DMA_LISR_TCIF1)
	{
		DMA2_Stream1_Flag.Transfer_Complete_Flag = true;
		DMA2 -> LIFCR |= DMA_LIFCR_CTCIF1;
	}
}

void DMA2_Stream2_IRQHandler(void)
{
	if(DMA2 -> LISR & DMA_LISR_FEIF2)
	{
		DMA2_Stream2_Flag.Fifo_Error_Flag = true;
		DMA2 -> LIFCR |= DMA_LIFCR_CFEIF2;
	}
	/************************************************************************************************************/
	else if(DMA2 -> LISR & DMA_LISR_DMEIF2)
	{
		DMA2_Stream2_Flag.Direct_Mode_Error_Flag = true;
		DMA2 -> LIFCR |= DMA_LIFCR_CDMEIF2;
	}
	/************************************************************************************************************/
	else if(DMA2 -> LISR & DMA_LISR_TEIF2)
	{
		DMA2_Stream2_Flag.Transfer_Error_Flag = true;
		DMA2 -> LIFCR |= DMA_LIFCR_CTEIF2;
	}
	/************************************************************************************************************/
	else if(DMA2 -> LISR & DMA_LISR_HTIF2)
	{
		DMA2_Stream2_Flag.Half_Transfer_Complete_Flag = true;
		DMA2 -> LIFCR |= DMA_LIFCR_CHTIF2;
	}
	/************************************************************************************************************/
	else if(DMA2 -> LISR & DMA_LISR_TCIF2)
	{
		DMA2_Stream2_Flag.Transfer_Complete_Flag = true;
		DMA2 -> LIFCR |= DMA_LIFCR_CTCIF2;
	}
}

void DMA2_Stream3_IRQHandler(void)
{
	if(DMA2 -> LISR & DMA_LISR_FEIF3)
	{
		DMA2_Stream3_Flag.Fifo_Error_Flag = true;
		DMA2 -> LIFCR |= DMA_LIFCR_CFEIF3;
	}
	/************************************************************************************************************/
	else if(DMA2 -> LISR & DMA_LISR_DMEIF3)
	{
		DMA2_Stream3_Flag.Direct_Mode_Error_Flag = true;
		DMA2 -> LIFCR |= DMA_LIFCR_CDMEIF3;
	}
	/************************************************************************************************************/
	else if(DMA2 -> LISR & DMA_LISR_TEIF3)
	{
		DMA2_Stream3_Flag.Transfer_Error_Flag = true;
		DMA2 -> LIFCR |= DMA_LIFCR_CTEIF3;
	}
	/************************************************************************************************************/
	else if(DMA2 -> LISR & DMA_LISR_HTIF3)
	{
		DMA2_Stream3_Flag.Half_Transfer_Complete_Flag = true;
		DMA2 -> LIFCR |= DMA_LIFCR_CHTIF3;
	}
	/************************************************************************************************************/
	else if(DMA2 -> LISR & DMA_LISR_TCIF3)
	{
		DMA2_Stream3_Flag.Transfer_Complete_Flag = true;
		DMA2 -> LIFCR |= DMA_LIFCR_CTCIF3;
	}
}

void DMA2_Stream4_IRQHandler(void)
{
	if(DMA2 -> HISR & DMA_HISR_FEIF4)
	{
		DMA2_Stream4_Flag.Fifo_Error_Flag = true;
		DMA2 -> HIFCR |= DMA_HIFCR_CFEIF4;
	}
	/************************************************************************************************************/
	else if(DMA2 -> HISR & DMA_HISR_DMEIF4)
	{
		DMA2_Stream4_Flag.Direct_Mode_Error_Flag = true;
		DMA2 -> HIFCR |= DMA_HIFCR_CDMEIF4;
	}
	/************************************************************************************************************/
	else if(DMA2 -> HISR & DMA_HISR_TEIF4)
	{
		DMA2_Stream4_Flag.Transfer_Error_Flag = true;
		DMA2 -> HIFCR |= DMA_HIFCR_CTEIF4;
	}
	/************************************************************************************************************/
	else if(DMA2 -> HISR & DMA_HISR_HTIF4)
	{
		DMA2_Stream4_Flag.Half_Transfer_Complete_Flag = true;
		DMA2 -> HIFCR |= DMA_HIFCR_CHTIF4;
	}
	/************************************************************************************************************/
	else if(DMA2 -> HISR & DMA_HISR_TCIF4)
	{
		DMA2_Stream4_Flag.Transfer_Complete_Flag = true;
		DMA2 -> HIFCR |= DMA_HIFCR_CTCIF4;
	}
}

void DMA2_Stream5_IRQHandler(void)
{
	if(DMA2 -> HISR & DMA_HISR_FEIF5)
	{
		DMA2_Stream5_Flag.Fifo_Error_Flag = true;
		DMA2 -> HIFCR |= DMA_HIFCR_CFEIF5;
	}
	/************************************************************************************************************/
	else if(DMA2 -> HISR & DMA_HISR_DMEIF5)
	{
		DMA2_Stream5_Flag.Direct_Mode_Error_Flag = true;
		DMA2 -> HIFCR |= DMA_HIFCR_CDMEIF5;
	}
	/************************************************************************************************************/
	else if(DMA2 -> HISR & DMA_HISR_TEIF5)
	{
		DMA2_Stream5_Flag.Transfer_Error_Flag = true;
		DMA2 -> HIFCR |= DMA_HIFCR_CTEIF5;
	}
	/************************************************************************************************************/
	else if(DMA2 -> HISR & DMA_HISR_HTIF5)
	{
		DMA2_Stream5_Flag.Half_Transfer_Complete_Flag = true;
		DMA2 -> HIFCR |= DMA_HIFCR_CHTIF5;
	}
	/************************************************************************************************************/
	else if(DMA2 -> HISR & DMA_HISR_TCIF5)
	{
		DMA2_Stream5_Flag.Transfer_Complete_Flag = true;
		DMA2 -> HIFCR |= DMA_HIFCR_CTCIF5;
	}
}

void DMA2_Stream6_IRQHandler(void)
{
	if(DMA2 -> HISR & DMA_HISR_FEIF6)
	{
		DMA2_Stream6_Flag.Fifo_Error_Flag = true;
		DMA2 -> HIFCR |= DMA_HIFCR_CFEIF6;
	}
	/************************************************************************************************************/
	else if(DMA2 -> HISR & DMA_HISR_DMEIF6)
	{
		DMA2_Stream6_Flag.Direct_Mode_Error_Flag = true;
		DMA2 -> HIFCR |= DMA_HIFCR_CDMEIF6;
	}
	/************************************************************************************************************/
	else if(DMA2 -> HISR & DMA_HISR_TEIF6)
	{
		DMA2_Stream6_Flag.Transfer_Error_Flag = true;
		DMA2 -> HIFCR |= DMA_HIFCR_CTEIF6;
	}
	/************************************************************************************************************/
	else if(DMA2 -> HISR & DMA_HISR_HTIF6)
	{
		DMA2_Stream6_Flag.Half_Transfer_Complete_Flag = true;
		DMA2 -> HIFCR |= DMA_HIFCR_CHTIF6;
	}
	/************************************************************************************************************/
	else if(DMA2 -> HISR & DMA_HISR_TCIF6)
	{
		DMA2_Stream6_Flag.Transfer_Complete_Flag = true;
		DMA2 -> HIFCR |= DMA_HIFCR_CTCIF6;
	}
}

void DMA2_Stream7_IRQHandler(void)
{
	if(DMA2 -> HISR & DMA_HISR_FEIF7)
	{
		DMA2_Stream7_Flag.Fifo_Error_Flag = true;
		DMA2 -> HIFCR |= DMA_HIFCR_CFEIF7;
	}
	/************************************************************************************************************/
	else if(DMA2 -> HISR & DMA_HISR_DMEIF7)
	{
		DMA2_Stream7_Flag.Direct_Mode_Error_Flag = true;
		DMA2 -> HIFCR |= DMA_HIFCR_CDMEIF7;
	}
	/************************************************************************************************************/
	else if(DMA2 -> HISR & DMA_HISR_TEIF7)
	{
		DMA2_Stream7_Flag.Transfer_Error_Flag = true;
		DMA2 -> HIFCR |= DMA_HIFCR_CTEIF7;
	}
	/************************************************************************************************************/
	else if(DMA2 -> HISR & DMA_HISR_HTIF7)
	{
		DMA2_Stream7_Flag.Half_Transfer_Complete_Flag = true;
		DMA2 -> HIFCR |= DMA_HIFCR_CHTIF7;
	}
	/************************************************************************************************************/
	else if(DMA2 -> HISR & DMA_HISR_TCIF7)
	{
		DMA2_Stream7_Flag.Transfer_Complete_Flag = true;
		DMA2 -> HIFCR |= DMA_HIFCR_CTCIF7;
	}
}

void DMA_Reset_Flags(DMA_Flags_Typedef flag)
{
	flag.Direct_Mode_Error_Flag = false;
	flag.Fifo_Error_Flag = false;
	flag.Half_Transfer_Complete_Flag = false;
	flag.Transfer_Complete_Flag = false;
	flag.Transfer_Error_Flag = false;
}


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

	if( (config->interrupts == DMA_Configuration.DMA_Interrupts.Transfer_Complete) ||
		(config->interrupts == DMA_Configuration.DMA_Interrupts.Half_Transfer_Complete) ||
		(config->interrupts == DMA_Configuration.DMA_Interrupts.Transfer_Error) ||
		(config->interrupts == DMA_Configuration.DMA_Interrupts.Direct_Mode_Error) ||
		(config->interrupts == DMA_Configuration.DMA_Interrupts.Fifo_Error)
	  )
	{
		if(config->interrupts == DMA_Configuration.DMA_Interrupts.Fifo_Error)
		{
			config -> Request.Stream -> FCR |= config -> interrupts;
		}

		config -> Request.Stream -> CR |= config -> interrupts;

		if(config->Request.Controller == DMA1)
		{
			if(config->Request.Stream == DMA1_Stream0) 	        NVIC_EnableIRQ(DMA1_Stream0_IRQn);
			else if(config->Request.Stream == DMA1_Stream1) 	NVIC_EnableIRQ(DMA1_Stream1_IRQn);
			else if(config->Request.Stream == DMA1_Stream2) 	NVIC_EnableIRQ(DMA1_Stream2_IRQn);
			else if(config->Request.Stream == DMA1_Stream3) 	NVIC_EnableIRQ(DMA1_Stream3_IRQn);
			else if(config->Request.Stream == DMA1_Stream4) 	NVIC_EnableIRQ(DMA1_Stream4_IRQn);
			else if(config->Request.Stream == DMA1_Stream5) 	NVIC_EnableIRQ(DMA1_Stream5_IRQn);
			else if(config->Request.Stream == DMA1_Stream6) 	NVIC_EnableIRQ(DMA1_Stream6_IRQn);
			else if(config->Request.Stream == DMA1_Stream7) 	NVIC_EnableIRQ(DMA1_Stream7_IRQn);
		}
		else if(config->Request.Controller == DMA2)
		{
			if(config->Request.Stream == DMA2_Stream0) 	        NVIC_EnableIRQ(DMA2_Stream0_IRQn);
			else if(config->Request.Stream == DMA2_Stream1) 	NVIC_EnableIRQ(DMA2_Stream1_IRQn);
			else if(config->Request.Stream == DMA2_Stream2) 	NVIC_EnableIRQ(DMA2_Stream2_IRQn);
			else if(config->Request.Stream == DMA2_Stream3) 	NVIC_EnableIRQ(DMA2_Stream3_IRQn);
			else if(config->Request.Stream == DMA2_Stream4) 	NVIC_EnableIRQ(DMA2_Stream4_IRQn);
			else if(config->Request.Stream == DMA2_Stream5) 	NVIC_EnableIRQ(DMA2_Stream5_IRQn);
			else if(config->Request.Stream == DMA2_Stream6) 	NVIC_EnableIRQ(DMA2_Stream6_IRQn);
			else if(config->Request.Stream == DMA2_Stream7) 	NVIC_EnableIRQ(DMA2_Stream7_IRQn);
		}
	}

	config -> Request.Stream -> CR |= config -> memory_pointer_increment;
	config -> Request.Stream -> CR |= config -> peripheral_pointer_increment;
}

void DMA_Set_Target(DMA_Config *config)
{
	config -> Request.Stream -> CR &= ~(DMA_SxCR_MSIZE | DMA_SxCR_PSIZE);
	config -> Request.Stream -> CR |= config -> peripheral_data_size;
	config -> Request.Stream -> CR |= config -> memory_data_size;
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



void DMA_Memory_To_Memory_Transfer(uint32_t *source,
						  uint8_t source_data_size, uint8_t dest_data_size,
		                  uint32_t *destination, bool source_increment,
						  bool destination_increment, uint16_t length)
{

	RCC -> AHB1ENR |= RCC_AHB1ENR_DMA2EN;
	DMA2_Stream0->CR &= (DMA_SxCR_CHSEL);
	DMA2_Stream0->CR |= DMA_Configuration.Transfer_Direction.Memory_to_memory;
	DMA2_Stream0->CR |= (DMA_SxCR_TCIE | DMA_SxCR_PL);

	if(source_data_size == 32)
	{
		DMA2_Stream0->CR |= DMA_SxCR_PSIZE;
	}else if(source_data_size == 16)
	{
		DMA2_Stream0->CR |= DMA_SxCR_PSIZE_0;
		DMA2_Stream0->CR &= ~DMA_SxCR_PSIZE_1;
	}else
	{
		DMA2_Stream0->CR &= ~DMA_SxCR_PSIZE;
	}

	if(dest_data_size == 32)
	{
		DMA2_Stream0->CR |= DMA_SxCR_MSIZE;
	}else if(dest_data_size == 16)
	{
		DMA2_Stream0->CR |= DMA_SxCR_MSIZE_0;
		DMA2_Stream0->CR &= ~DMA_SxCR_MSIZE_1;
	}else
	{
		DMA2_Stream0->CR &= ~DMA_SxCR_MSIZE;
	}

	if(source_increment == 1)
	{
		DMA2_Stream0->CR |= DMA_SxCR_PINC;
	}
	else{
		DMA2_Stream0->CR &= ~DMA_SxCR_PINC;
	}

	if(destination_increment == 1)
	{
		DMA2_Stream0->CR |= DMA_SxCR_MINC;
	}
	else{
		DMA2_Stream0->CR &= ~DMA_SxCR_MINC;
	}

	DMA2_Stream0 -> PAR = (uint32_t)(source);
	DMA2_Stream0 -> M0AR = (uint32_t)(destination);
	DMA2_Stream0 -> NDTR = (uint16_t)length;
	DMA2_Stream0 -> CR |= DMA_SxCR_EN;

	while((DMA2 -> LISR & (DMA_LISR_TCIF0_Msk)) == 0){}
	DMA2 -> LIFCR |= DMA_LIFCR_CTCIF0;

	DMA2_Stream0 -> CR &= ~DMA_SxCR_EN;
}

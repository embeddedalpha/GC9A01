/*
 * GC9A01.c
 *
 *  Created on: May 28, 2024
 *      Author: kunal
 */

#include "GC9A01.h"



static void command_line_high(GC9A01_Typedef *config)
{
	GPIO_Pin_High(config->DC_Port, config->DC_Pin);
}

static void command_line_low(GC9A01_Typedef *config)
{
	GPIO_Pin_Low(config->DC_Port, config->DC_Pin);
}

static void reset_line_high(GC9A01_Typedef *config)
{
	GPIO_Pin_High(config->Reset_Port, config->Reset_Pin);
}

static void reset_line_low(GC9A01_Typedef *config)
{
	GPIO_Pin_Low(config->Reset_Port, config->Reset_Pin);
}

static void Command(GC9A01_Typedef *config,uint8_t command)
{
	command_line_low(config);
	SPI_NSS_Low(&(config->SPI_Driver));
	SPI_TRX_Byte(&(config->SPI_Driver), command);
	SPI_NSS_High(&(config->SPI_Driver));
}

static void Data(GC9A01_Typedef *config,uint8_t data)
{
	command_line_high(config);
	SPI_NSS_Low(&(config->SPI_Driver));
	SPI_TRX_Byte(&(config->SPI_Driver), data);
	SPI_NSS_High(&(config->SPI_Driver));
}

void GC9A01_DeInit(GC9A01_Typedef *config)
{
	SPI_DeInit(&(config->SPI_Driver)); //check this
	config->DC_Pin = -1;
	config->DC_Port = NULL;
	config->Reset_Pin = -1;
	config->Reset_Port = NULL;
}

void GC9A01_Init(GC9A01_Typedef *config)
{

	SPI_Init(&(config->SPI_Driver));
	SPI_Enable(&(config->SPI_Driver));

	GPIO_Pin_Init(config->DC_Port, config->DC_Pin, MODE.General_Purpose_Output, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.None);

	GPIO_Pin_Init(config->Reset_Port, config->Reset_Pin, MODE.General_Purpose_Output, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.None);


	SPI_NSS_High(&(config->SPI_Driver));
	Delay_ms(5);
	reset_line_low(config);
	Delay_ms(10);
	reset_line_high(config);
	Delay_ms(120);

		Command(config,0xEF);
	    Command(config,0xEB);
	    Data(config,0x14);

	    Command(config,0xFE);
	    Command(config,0xEF);

	    Command(config,0xEB);
	    Data(config,0x14);

	    Command(config,0x84);
	    Data(config,0x40);

	    Command(config,0x85);
	    Data(config,0xFF);

	    Command(config,0x86);
	    Data(config,0xFF);

	    Command(config,0x87);
	    Data(config,0xFF);

	    Command(config,0x88);
	    Data(config,0x0A);

	    Command(config,0x89);
	    Data(config,0x21);

	    Command(config,0x8A);
	    Data(config,0x00);

	    Command(config,0x8B);
	    Data(config,0x80);

	    Command(config,0x8C);
	    Data(config,0x01);

	    Command(config,0x8D);
	    Data(config,0x01);

	    Command(config,0x8E);
	    Data(config,0xFF);

	    Command(config,0x8F);
	    Data(config,0xFF);


	    Command(config,0xB6);
	    Data(config,0x00);
	    Data(config,0x00);

	    Command(config,0x36);

	#if ORIENTATION == 0
	    Data(config,0x18);
	#elif ORIENTATION == 1
	    Data(config,0x28);
	#elif ORIENTATION == 2
	    Data(config,0x48);
	#else
	    Data(config,0x88);
	#endif

	    Command(config,COLOR_MODE);
	    Data(config,COLOR_MODE__16_BIT);

	    Command(config,0x90);
	    Data(config,0x08);
	    Data(config,0x08);
	    Data(config,0x08);
	    Data(config,0x08);

	    Command(config,0xBD);
	    Data(config,0x06);

	    Command(config,0xBC);
	    Data(config,0x00);

	    Command(config,0xFF);
	    Data(config,0x60);
	    Data(config,0x01);
	    Data(config,0x04);

	    Command(config,0xC3);
	    Data(config,0x13);
	    Command(config,0xC4);
	    Data(config,0x13);

	    Command(config,0xC9);
	    Data(config,0x22);

	    Command(config,0xBE);
	    Data(config,0x11);

	    Command(config,0xE1);
	    Data(config,0x10);
	    Data(config,0x0E);

	    Command(config,0xDF);
	    Data(config,0x21);
	    Data(config,0x0c);
	    Data(config,0x02);

	    Command(config,0xF0);
	    Data(config,0x45);
	    Data(config,0x09);
	    Data(config,0x08);
	    Data(config,0x08);
	    Data(config,0x26);
	    Data(config,0x2A);

	    Command(config,0xF1);
	    Data(config,0x43);
	    Data(config,0x70);
	    Data(config,0x72);
	    Data(config,0x36);
	    Data(config,0x37);
	    Data(config,0x6F);

	    Command(config,0xF2);
	    Data(config,0x45);
	    Data(config,0x09);
	    Data(config,0x08);
	    Data(config,0x08);
	    Data(config,0x26);
	    Data(config,0x2A);

	    Command(config,0xF3);
	    Data(config,0x43);
	    Data(config,0x70);
	    Data(config,0x72);
	    Data(config,0x36);
	    Data(config,0x37);
	    Data(config,0x6F);

	    Command(config,0xED);
	    Data(config,0x1B);
	    Data(config,0x0B);

	    Command(config,0xAE);
	    Data(config,0x77);

	    Command(config,0xCD);
	    Data(config,0x63);

	    Command(config,0x70);
	    Data(config,0x07);
	    Data(config,0x07);
	    Data(config,0x04);
	    Data(config,0x0E);
	    Data(config,0x0F);
	    Data(config,0x09);
	    Data(config,0x07);
	    Data(config,0x08);
	    Data(config,0x03);

	    Command(config,0xE8);
	    Data(config,0x34);

	    Command(config,0x62);
	    Data(config,0x18);
	    Data(config,0x0D);
	    Data(config,0x71);
	    Data(config,0xED);
	    Data(config,0x70);
	    Data(config,0x70);
	    Data(config,0x18);
	    Data(config,0x0F);
	    Data(config,0x71);
	    Data(config,0xEF);
	    Data(config,0x70);
	    Data(config,0x70);

	    Command(config,0x63);
	    Data(config,0x18);
	    Data(config,0x11);
	    Data(config,0x71);
	    Data(config,0xF1);
	    Data(config,0x70);
	    Data(config,0x70);
	    Data(config,0x18);
	    Data(config,0x13);
	    Data(config,0x71);
	    Data(config,0xF3);
	    Data(config,0x70);
	    Data(config,0x70);

	    Command(config,0x64);
	    Data(config,0x28);
	    Data(config,0x29);
	    Data(config,0xF1);
	    Data(config,0x01);
	    Data(config,0xF1);
	    Data(config,0x00);
	    Data(config,0x07);

	    Command(config,0x66);
	    Data(config,0x3C);
	    Data(config,0x00);
	    Data(config,0xCD);
	    Data(config,0x67);
	    Data(config,0x45);
	    Data(config,0x45);
	    Data(config,0x10);
	    Data(config,0x00);
	    Data(config,0x00);
	    Data(config,0x00);

	    Command(config,0x67);
	    Data(config,0x00);
	    Data(config,0x3C);
	    Data(config,0x00);
	    Data(config,0x00);
	    Data(config,0x00);
	    Data(config,0x01);
	    Data(config,0x54);
	    Data(config,0x10);
	    Data(config,0x32);
	    Data(config,0x98);

	    Command(config,0x74);
	    Data(config,0x10);
	    Data(config,0x85);
	    Data(config,0x80);
	    Data(config,0x00);
	    Data(config,0x00);
	    Data(config,0x4E);
	    Data(config,0x00);

	    Command(config,0x98);
	    Data(config,0x3e);
	    Data(config,0x07);

	    Command(config,0x35);
	    Command(config,0x21);

	    Command(config,0x11);
	    Delay_ms(120);
	    Command(config,0x29);
	    Delay_ms(20);
}

void GC9A01_Write(GC9A01_Typedef *config,uint8_t *data, size_t len) {
    Command(config, MEM_WR);
	command_line_high(config);
	SPI_NSS_Low(&(config->SPI_Driver));
	for(int i = 0; i < len; i++)
	SPI_TRX_Byte(&(config->SPI_Driver), data[i]);
	SPI_NSS_High(&(config->SPI_Driver));
}

void GC9A01_Write_Continue(GC9A01_Typedef *config,uint8_t *data, size_t len)
{
    Command(config, MEM_WR_CONT);
	command_line_high(config);
	SPI_NSS_Low(&(config->SPI_Driver));
	for(int i = 0; i < len; i++)
	SPI_TRX_Byte(&(config->SPI_Driver), data[i]);
	SPI_NSS_High(&(config->SPI_Driver));
}

void GC9A01_Set_Frame(GC9A01_Typedef *config,struct GC9A01_frame frame)
{
	uint8_t data[4];
	Command(config, COL_ADDR_SET);
    data[0] = (frame.start.X >> 8) & 0xFF;
    data[1] = frame.start.X & 0xFF;
    data[2] = (frame.end.X >> 8) & 0xFF;
    data[3] = frame.end.X & 0xFF;
    GC9A01_Write(config, data, 4);

	Command(config, ROW_ADDR_SET);
    data[0] = (frame.start.Y >> 8) & 0xFF;
    data[1] = frame.start.Y & 0xFF;
    data[2] = (frame.end.Y >> 8) & 0xFF;
    data[3] = frame.end.Y & 0xFF;
    GC9A01_Write(config, data, 4);

}


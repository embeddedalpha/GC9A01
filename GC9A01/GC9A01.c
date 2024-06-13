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

static void Write_Command(GC9A01_Typedef *config,uint8_t command, bool data_command, uint8_t *data, uint8_t len)
{
	SPI_NSS_Low(&(config->SPI_Driver));
	command_line_low(config);
	SPI_TRX_Byte(&(config->SPI_Driver), command);
	if(data_command)
	{
		command_line_high(config);
		for(int i = 0; i < len; i++)
		{
			SPI_TRX_Byte(&(config->SPI_Driver), data[i]);
		}
	}
	SPI_NSS_High(&(config->SPI_Driver));
}


void GC9A01_Init(GC9A01_Typedef *config)
{

	SPI_Init(&(config->SPI_Driver));
	SPI_Enable(&(config->SPI_Driver));

	GPIO_Pin_Init(config->DC_Port, config->DC_Pin, MODE.General_Purpose_Output, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.None);

	GPIO_Pin_Init(config->Reset_Port, config->Reset_Pin, MODE.General_Purpose_Output, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.None);


	SPI_NSS_Low(&(config->SPI_Driver));
	reset_line_high(config);
	Delay_ms(50);
	reset_line_low(config);
	Delay_ms(50);
	reset_line_high(config);
	Delay_ms(150);
	SPI_NSS_High(&(config->SPI_Driver));
	Delay_ms(100);
//	SPI_NSS_High(&(config->SPI_Driver));
//	Delay_ms(5);
//	reset_line_low(config);
//	Delay_ms(10);
//	reset_line_high(config);
//	GPIOA -> BSRR |= 1 << 2;

//	Delay_ms(120);

	uint8_t data[15];

	Write_Command(config, 0xEF, 0, NULL, 0);
	data[0] = 0x14;
	Write_Command(config, 0xEB, 1, data, 1);

//		Command(config,0xEF);
//	    Command(config,0xEB);
//	    Data(config,0x14);

//	    Command(config,0xFE);
//	    Command(config,0xEF);

		Write_Command(config, 0xFE, 0, NULL, 0);
		Write_Command(config, 0xEF, 0, NULL, 0);

//	    Command(config,0xEB);
//	    Data(config,0x14);

		data[0] = 0x14;
		Write_Command(config, 0xEB, 1, data, 1);


//	    Command(config,0x84);
//	    Data(config,0x40);

		data[0] = 0x40;
		Write_Command(config, 0x84, 1, data, 1);


//	    Command(config,0x85);
//	    Data(config,0xFF);

		data[0] = 0xFF;
		Write_Command(config, 0x85, 1, data, 1);

//	    Command(config,0x86);
//	    Data(config,0xFF);

		data[0] = 0xFF;
		Write_Command(config, 0x86, 1, data, 1);

//	    Command(config,0x87);
//	    Data(config,0xFF);

		data[0] = 0xFF;
		Write_Command(config, 0x87, 1, data, 1);


//	    Command(config,0x88);
//	    Data(config,0x0A);

		data[0] = 0x0A;
		Write_Command(config, 0x88, 1, data, 1);

//	    Command(config,0x89);
//	    Data(config,0x21);

		data[0] = 0x21;
		Write_Command(config, 0x89, 1, data, 1);


//	    Command(config,0x8A);
//	    Data(config,0x00);
		data[0] = 0x00;
		Write_Command(config, 0x8A, 1, data, 1);


//	    Command(config,0x8B);
//	    Data(config,0x80);
		data[0] = 0x80;
		Write_Command(config, 0x8B, 1, data, 1);


//	    Command(config,0x8C);
//	    Data(config,0x01);
		data[0] = 0x01;
		Write_Command(config, 0x8C, 1, data, 1);

//	    Command(config,0x8D);
//	    Data(config,0x01);
		data[0] = 0x01;
		Write_Command(config, 0x8D, 1, data, 1);


//	    Command(config,0x8E);
//	    Data(config,0xFF);
		data[0] = 0xFF;
		Write_Command(config, 0x8E, 1, data, 1);

//	    Command(config,0x8F);
//	    Data(config,0xFF);
		data[0] = 0xFF;
		Write_Command(config, 0x8F, 1, data, 1);



//	    Command(config,0xB6);
//	    Data(config,0x00);
//	    Data(config,0x00);
		data[0] = 0x00;
		data[1] = 0x00;
		Write_Command(config, 0xb6, 1, data, 2);





	#if ORIENTATION == 0
	    Data(config,0x18);
	#elif ORIENTATION == 1
	    Data(config,0x28);
	#elif ORIENTATION == 2
//	    Command(config,0x36);
//	    Data(config,0x48);

	    data[0] = 0x48;
		Write_Command(config, 0x36, 1, data, 1);

	#else
	    Data(config,0x88);
	#endif

//	    Command(config,COLOR_MODE);
//	    Data(config,COLOR_MODE__18_BIT);
	    data[0] = COLOR_MODE__18_BIT;
		Write_Command(config, COLOR_MODE, 1, data, 1);


	    data[0] = 0x08;
	    data[1] = 0x08;
	    data[2] = 0x08;
	    data[3] = 0x08;
		Write_Command(config, 0x90, 1, data, 4);


	    data[0] = 0x06;
		Write_Command(config, 0xBD, 1, data, 1);

	    data[0] = 0x00;
		Write_Command(config, 0xBC, 1, data, 1);


	    data[0] = 0x60;
	    data[1] = 0x01;
	    data[2] = 0x04;
		Write_Command(config, 0xFF, 1, data, 3);


	    data[0] = 0x13;
		Write_Command(config, 0xC3, 1, data, 1);

	    data[0] = 0x13;
		Write_Command(config, 0xC4, 1, data, 1);

	    data[0] = 0x22;
		Write_Command(config, 0xC9, 1, data, 1);


	    data[0] = 0x11;
		Write_Command(config, 0xBE, 1, data, 1);

	    data[0] = 0x10;
	    data[1] = 0x0E;
		Write_Command(config, 0xE1, 1, data, 2);

	    data[0] = 0x21;
	    data[1] = 0x0c;
	    data[2] = 0x02;
		Write_Command(config, 0xDF, 1, data, 3);


	    data[0] = 0x45;
	    data[1] = 0x09;
	    data[2] = 0x08;
	    data[3] = 0x08;
	    data[4] = 0x26;
	    data[5] = 0x2A;
		Write_Command(config, 0xF0, 1, data, 6);

	    data[0] = 0x43;
	    data[1] = 0x70;
	    data[2] = 0x72;
	    data[3] = 0x36;
	    data[4] = 0x37;
	    data[5] = 0x6f;
		Write_Command(config, 0xF1, 1, data, 6);


	    data[0] = 0x45;
	    data[1] = 0x09;
	    data[2] = 0x08;
	    data[3] = 0x08;
	    data[4] = 0x26;
	    data[5] = 0x2A;
		Write_Command(config, 0xF2, 1, data, 6);


	    data[0] = 0x43;
	    data[1] = 0x70;
	    data[2] = 0x72;
	    data[3] = 0x36;
	    data[4] = 0x37;
	    data[5] = 0x6F;
		Write_Command(config, 0xF3, 1, data, 6);


	    data[0] = 0x1B;
	    data[1] = 0x0B;
		Write_Command(config, 0xED, 1, data, 2);


	    data[0] = 0x77;
		Write_Command(config, 0xAe, 1, data, 1);

	    data[0] = 0x63;
		Write_Command(config, 0xCD, 1, data, 1);


	    data[0] = 0x07;
	    data[1] = 0x07;
	    data[2] = 0x04;
	    data[3] = 0x0e;
	    data[4] = 0x0f;
	    data[5] = 0x09;
	    data[6] = 0x07;
	    data[7] = 0x08;
	    data[8] = 0x03;
		Write_Command(config, 0x70, 1, data, 9);


	    data[0] = 0x34;
		Write_Command(config, 0xE8, 1, data, 1);

	    data[0] = 0x18;
	    data[1] = 0x0D;
	    data[2] = 0x71;
	    data[3] = 0xED;
	    data[4] = 0x70;
	    data[5] = 0x70;
	    data[6] = 0x18;
	    data[7] = 0x0F;
	    data[8] = 0x71;
	    data[9] = 0xEF;
	    data[10] = 0x70;
	    data[11] = 0x70;
		Write_Command(config, 0x62, 1, data, 12);


	    //
	    data[0] = 0x18;
	    data[1] = 0x11;
	    data[2] = 0x71;
	    data[3] = 0xf1;
	    data[4] = 0x70;
	    data[5] = 0x70;
	    data[6] = 0x18;
	    data[7] = 0x13;
	    data[8] = 0x71;
	    data[9] = 0xf3;
	    data[10] = 0x70;
	    data[11] = 0x70;
		Write_Command(config, 0x63, 1, data, 12);


	    //
	    data[0] = 0x28;
	    data[1] = 0x29;
	    data[2] = 0xf1;
	    data[3] = 0x01;
	    data[4] = 0xf1;
	    data[5] = 0x00;
	    data[6] = 0x07;
		Write_Command(config, 0x64, 1, data, 7);

//	    Command(config,0x66);
//	    Data(config,0x3C);
//	    Data(config,0x00);
//	    Data(config,0xCD);
//	    Data(config,0x67);
//	    Data(config,0x45);
//	    Data(config,0x45);
//	    Data(config,0x10);
//	    Data(config,0x00);
//	    Data(config,0x00);
//	    Data(config,0x00);
	    //
	    data[0] = 0x3c;
	    data[1] = 0x00;
	    data[2] = 0xcd;
	    data[3] = 0x67;
	    data[4] = 0x45;
	    data[5] = 0x45;
	    data[6] = 0x10;
	    data[7] = 0x00;
	    data[8] = 0x00;
	    data[9] = 0x00;
		Write_Command(config, 0x66, 1, data, 10);

//	    Command(config,0x67);
//	    Data(config,0x00);
//	    Data(config,0x3C);
//	    Data(config,0x00);
//	    Data(config,0x00);
//	    Data(config,0x00);
//	    Data(config,0x01);
//	    Data(config,0x54);
//	    Data(config,0x10);
//	    Data(config,0x32);
//	    Data(config,0x98);
	    //
	    data[0] = 0x00;
	    data[1] = 0x3c;
	    data[2] = 0x00;
	    data[3] = 0x00;
	    data[4] = 0x00;
	    data[5] = 0x01;
	    data[6] = 0x54;
	    data[7] = 0x10;
	    data[8] = 0x32;
	    data[9] = 0x98;
		Write_Command(config, 0x67, 1, data, 10);

//	    Command(config,0x74);
//	    Data(config,0x10);
//	    Data(config,0x85);
//	    Data(config,0x80);
//	    Data(config,0x00);
//	    Data(config,0x00);
//	    Data(config,0x4E);
//	    Data(config,0x00);
	    //
	    data[0] = 0x10;
	    data[1] = 0x85;
	    data[2] = 0x80;
	    data[3] = 0x00;
	    data[4] = 0x00;
	    data[5] = 0x4e;
	    data[6] = 0x00;
		Write_Command(config, 0x74, 1, data, 7);

	    //
	    data[0] = 0x3e;
	    data[1] = 0x07;
		Write_Command(config, 0x98, 1, data, 2);

//	    Command(config,0x35);
	    Write_Command(config, 0x35, 0, NULL, 0);

//	    Command(config,0x21);
	    Write_Command(config, 0x21, 0, NULL, 0);


//	    Command(config,0x11);
	    Write_Command(config, 0x11, 0, NULL, 0);
	    Delay_ms(120);
//	    Command(config,0x29);
	    Write_Command(config, 0x29, 0, NULL, 0);
	    Delay_ms(20);
}

void GC9A01_Write(GC9A01_Typedef *config,uint8_t *data, size_t len) {
//    Command(config, MEM_WR);
    Write_Command(config, MEM_WR, 0, NULL, 0);
	command_line_high(config);
	SPI_NSS_Low(&(config->SPI_Driver));
	for(int i = 0; i < len; i++)
	SPI_TRX_Byte(&(config->SPI_Driver), data[i]);
	SPI_NSS_High(&(config->SPI_Driver));
}

void GC9A01_Write_Continue(GC9A01_Typedef *config,uint8_t *data, size_t len)
{
//    Command(config, MEM_WR_CONT);
	Write_Command(config, MEM_WR_CONT, 0, NULL, 0);
	command_line_high(config);
	SPI_NSS_Low(&(config->SPI_Driver));
	for(int i = 0; i < len; i++)
	SPI_TRX_Byte(&(config->SPI_Driver), data[i]);
	SPI_NSS_High(&(config->SPI_Driver));
}

void GC9A01_Set_Frame(GC9A01_Typedef *config,struct GC9A01_frame frame)
{
	uint8_t datax[4], datay[4];

    datax[0] = (frame.start.X >> 8) & 0xFF;
    datax[1] = frame.start.X & 0xFF;
    datax[2] = (frame.end.X >> 8) & 0xFF;
    datax[3] = frame.end.X & 0xFF;


    Write_Command(config, COL_ADDR_SET, 1, datax, 4);

//    SPI_NSS_Low(&(config->SPI_Driver));
//	command_line_low(config);
//	SPI_TRX_Byte(&(config->SPI_Driver), COL_ADDR_SET);
//	command_line_high(config);
//	SPI_TRX_Byte(&(config->SPI_Driver), datax[0]);
//	SPI_TRX_Byte(&(config->SPI_Driver), datax[1]);
//	SPI_TRX_Byte(&(config->SPI_Driver), datax[2]);
//	SPI_TRX_Byte(&(config->SPI_Driver), datax[3]);
//	SPI_NSS_High(&(config->SPI_Driver));


    datay[0] = (frame.start.Y >> 8) & 0xFF;
    datay[1] = frame.start.Y & 0xFF;
    datay[2] = (frame.end.Y >> 8) & 0xFF;
    datay[3] = frame.end.Y & 0xFF;
//    SPI_NSS_Low(&(config->SPI_Driver));
//	command_line_low(config);
//	SPI_TRX_Byte(&(config->SPI_Driver), ROW_ADDR_SET);
//	command_line_high(config);
//	SPI_TRX_Byte(&(config->SPI_Driver), datay[0]);
//	SPI_TRX_Byte(&(config->SPI_Driver), datay[1]);
//	SPI_TRX_Byte(&(config->SPI_Driver), datay[2]);
//	SPI_TRX_Byte(&(config->SPI_Driver), datay[3]);
//	SPI_NSS_High(&(config->SPI_Driver));

    Write_Command(config, ROW_ADDR_SET, 1, datay, 4);

//	Command(config, 0x2c);
//	Command(config, MEM_WR);
	Write_Command(config, MEM_WR, 0, NULL, 0);
}



void GC9A01_Draw_Pixel(GC9A01_Typedef *config,uint8_t x,uint8_t y, uint32_t color)
{
	uint8_t temp[3];
	struct GC9A01_frame frame;
	frame.start.X = x;
	frame.start.Y = y;
	frame.end.X = x+1;
	frame.end.Y = y+1;
	GC9A01_Set_Frame(config, frame);
	temp[0] = (color & 0xFF0000) >> 16;
	temp[1] = (color & 0x00FF00) >> 8;
	temp[2] = (color & 0x0000FF) >> 0;

	GC9A01_Write_Continue(config, temp, sizeof(temp));

//	SPI_NSS_Low(&(config->SPI_Driver));
//	command_line_high(config);
//	for(int i = 0; i < 3; i++)
//	SPI_TRX_Byte(&(config->SPI_Driver), temp[i]);
//	SPI_NSS_High(&(config->SPI_Driver));
}

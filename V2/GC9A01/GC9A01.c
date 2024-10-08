/*
 * GC9A01.c
 *
 *  Created on: May 28, 2024
 *      Author: kunal
 */

#include "GC9A01.h"
#include "Image.h"




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
	config->SPI_Driver.data_format = SPI_Configurations.Data_Format.Bit8;
	SPI_Data_Format_Update(&(config->SPI_Driver));

//	command_line_low(config);
//	SPI_NSS_Low(&(config->SPI_Driver));
//	SPI_TRX_Byte(&(config->SPI_Driver), command);
//
//	if(data_command)
//	{
//		command_line_high(config);
//		for(int i = 0; i < len; i++)
//		{
//			SPI_TRX_Byte(&(config->SPI_Driver), data[i]);
//		}
//	}
//	SPI_NSS_High(&(config->SPI_Driver));

	command_line_low(config);
	SPI_NSS_Low(&(config->SPI_Driver));
	SPI_TRX_Byte(&(config->SPI_Driver), command);
	SPI_NSS_High(&(config->SPI_Driver));

	if(data_command)
	{
		command_line_high(config);
		SPI_NSS_Low(&(config->SPI_Driver));
		for(int i = 0; i < len; i++)
		{
			SPI_TRX_Byte(&(config->SPI_Driver), data[i]);
		}
		SPI_NSS_High(&(config->SPI_Driver));
	}

}


void GC9A01_Init(GC9A01_Typedef *config)
{

	SPI_Init(&(config->SPI_Driver));
	SPI_Enable(&(config->SPI_Driver));

	GPIO_Pin_Init(config->DC_Port, config->DC_Pin, GPIO_Configuration.Mode.General_Purpose_Output, GPIO_Configuration.Output_Type.Push_Pull, GPIO_Configuration.Speed.Very_High_Speed, GPIO_Configuration.Pull.No_Pull_Up_Down, GPIO_Configuration.Alternate_Functions.None);

	GPIO_Pin_Init(config->Reset_Port, config->Reset_Pin, GPIO_Configuration.Mode.General_Purpose_Output, GPIO_Configuration.Output_Type.Push_Pull, GPIO_Configuration.Speed.Very_High_Speed, GPIO_Configuration.Pull.No_Pull_Up_Down, GPIO_Configuration.Alternate_Functions.None);

	//Display Initialization Starts Here

	SPI_NSS_High(&(config->SPI_Driver));
	Delay_milli(5);
	reset_line_low(config);
	Delay_milli(10);
	reset_line_high(config);
	Delay_milli(119);


	uint8_t data[15];

	Write_Command(config, 0xEF, 0, NULL, 0);

	data[0] = 0x14;
	Write_Command(config, 0xEB, 1, data, 1);

	Write_Command(config, 0xFE, 0, NULL, 0);
	Write_Command(config, 0xEF, 0, NULL, 0);

	data[0] = 0x14;
	Write_Command(config, 0xEB, 1, data, 1);

	data[0] = 0x40;
	Write_Command(config, 0x84, 1, data, 1);

	data[0] = 0xFF;
	Write_Command(config, 0x85, 1, data, 1);

	data[0] = 0xFF;
	Write_Command(config, 0x86, 1, data, 1);

	data[0] = 0xFF;
	Write_Command(config, 0x87, 1, data, 1);

	data[0] = 0x0A;
	Write_Command(config, 0x88, 1, data, 1);

	data[0] = 0x21;
	Write_Command(config, 0x89, 1, data, 1);

	data[0] = 0x00;
	Write_Command(config, 0x8A, 1, data, 1);

	data[0] = 0x80;
	Write_Command(config, 0x8B, 1, data, 1);

	data[0] = 0x01;
	Write_Command(config, 0x8C, 1, data, 1);

	data[0] = 0x01;
	Write_Command(config, 0x8D, 1, data, 1);

	data[0] = 0xFF;
	Write_Command(config, 0x8E, 1, data, 1);

	data[0] = 0xFF;
	Write_Command(config, 0x8F, 1, data, 1);

	data[0] = 0x00;
	data[1] = 0x00; //0x00
	Write_Command(config, 0xb6, 1, data, 2);

	data[0] = 0x18;
	Write_Command(config, 0x36, 1, data, 1);


	data[0] = COLOR_MODE__16_BIT;
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


	Write_Command(config, 0x11, 0, NULL, 0);
	Delay_milli(120-1);

	Write_Command(config, 0x29, 0, NULL, 0);
	Delay_milli(20);
}

void GC9A01_Set_Orientation(GC9A01_Typedef *config, uint8_t orientation)
{

	uint8_t data[2];
	data[0] = orientation;
	Write_Command(config, 0x36, 1, data, 1);
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

void GC9A01_Set_Window(GC9A01_Typedef *config,uint16_t x1, uint16_t y1, uint16_t w,
        uint16_t h)
{
	uint8_t data[2];
	data[0] = x1;
	data[1] = (x1 + w - 1);
	Write_Command(config, COL_ADDR_SET, 1, data, 2);

	data[0] = y1;
	data[1] = (y1 + h - 1);
	Write_Command(config, ROW_ADDR_SET, 1, data, 2);
	Write_Command(config, 0x2C, 0, NULL, 0);
}

void GC9A01_Draw_Point(GC9A01_Typedef *config,uint8_t x, uint8_t y, uint32_t color)
{
	uint8_t temp[3];
	temp[0] = (color & 0xFF0000) >> 16;
	temp[1] = (color & 0x00FF00) >> 8;
	temp[2] = (color & 0x0000FF) >> 0;
	GC9A01_Set_Window(config, x, y, 1, 1);
	GC9A01_Write_Continue(config, temp, sizeof(temp));
}

void GC9A01_Set_Frame(GC9A01_Typedef *config,struct GC9A01_frame frame)
{
	uint8_t datax[4], datay[4];

    datax[0] = (frame.start.X >> 8) & 0xFF;
    datax[1] = frame.start.X & 0xFF;
    datax[2] = (frame.end.X >> 8) & 0xFF;
    datax[3] = frame.end.X & 0xFF;

    Write_Command(config, COL_ADDR_SET, 1, datax, 4);

    datay[0] = (frame.start.Y >> 8) & 0xFF;
    datay[1] = frame.start.Y & 0xFF;
    datay[2] = (frame.end.Y >> 8) & 0xFF;
    datay[3] = frame.end.Y & 0xFF;

    Write_Command(config, ROW_ADDR_SET, 1, datay, 4);
    Write_Command(config, 0x2C, 0, NULL, 0);

}




void GC9A01_Draw_Pixel(GC9A01_Typedef *config,uint8_t x,uint8_t y, uint32_t color)
{
	uint8_t temp[3];
	GC9A01_frame frame;
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

void GC9A01_Splash_Screen(GC9A01_Typedef *config, uint16_t color)
{
	uint16_t length = (240*240);
	uint16_t buffer[length];
	uint16_t _color[2];
	_color[0]= color;


	DMA_Memory_To_Memory_Transfer((uint32_t)&_color[0], 16, 16, (uint32_t)&buffer[0], 0, 1, length);


	GC9A01_frame frame;
	frame.start.X = 0;
	frame.start.Y = 0;
	frame.end.X = 240;
	frame.end.Y = 240;
	GC9A01_Set_Frame(config, frame);


	Write_Command(config, MEM_WR_CONT, 0, NULL, 0);
	command_line_high(config);
	config -> SPI_Driver.data_format = SPI_Configurations.Data_Format.Bit16;
	SPI_Data_Format_Update(&(config->SPI_Driver));
	SPI_NSS_Low(&(config->SPI_Driver));
	SPI_TRX_Buffer(&(config->SPI_Driver), &buffer, NULL, length, 0);
	SPI_NSS_High(&(config->SPI_Driver));
}

void GC9A01_Draw_Mercury(GC9A01_Typedef *config)
{

	size_t buffer_size = sizeof(image_buffer);
	size_t num_elements = buffer_size / sizeof(uint16_t);


	GC9A01_frame frame;
	frame.start.X = 120-50;
	frame.start.Y = 120-50;
	frame.end.X = 120+50;
	frame.end.Y = 120+50;
	GC9A01_Set_Frame(config, frame);


	Write_Command(config, MEM_WR_CONT, 0, NULL, 0);
	command_line_high(config);
	config -> SPI_Driver.data_format = SPI_Configurations.Data_Format.Bit16;
	SPI_Data_Format_Update(&(config->SPI_Driver));
	SPI_NSS_Low(&(config->SPI_Driver));
	SPI_TRX_Buffer(&(config->SPI_Driver), (uint32_t)&image_buffer[0], NULL, num_elements, 0);
	SPI_NSS_High(&(config->SPI_Driver));
}

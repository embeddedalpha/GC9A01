/*
 * GC9A01.h
 *
 *  Created on: May 28, 2024
 *      Author: kunal
 */

#ifndef GC9A01_H_
#define GC9A01_H_

#include "main.h"
#include "SPI.h"
#include "DMA.h"
#include "GPIO.h"
#include "GC9A01_Defs.h"

#define ORIENTATION 2   // Set the display orientation 0,1,2,3

// Command codes:
#define COL_ADDR_SET        0x2A
#define ROW_ADDR_SET        0x2B
#define MEM_WR              0x2C
#define COLOR_MODE          0x3A
#define COLOR_MODE__12_BIT  0x03
#define COLOR_MODE__16_BIT  0x05
#define COLOR_MODE__18_BIT  0x06
#define MEM_WR_CONT         0x3C

typedef struct GC9A01_Typedef
{
	SPI_Config SPI_Driver;

	GPIO_TypeDef *DC_Port;
	int8_t DC_Pin;

	GPIO_TypeDef *Reset_Port;
	int8_t Reset_Pin;

}GC9A01_Typedef;

struct GC9A01_point {
    uint16_t X, Y;
};

typedef struct GC9A01_frame {
    struct GC9A01_point start, end;
}GC9A01_frame;

#define Orientation_1 0x18
#define Orientation_2 0x28
#define Orientation_3 0x48
#define Orientation_4 0x88

void GC9A01_Set_Orientation(GC9A01_Typedef *config, uint8_t orientation);
void GC9A01_DeInit(GC9A01_Typedef *config);
void GC9A01_Init(GC9A01_Typedef *config);
void GC9A01_Write(GC9A01_Typedef *config,uint8_t *data, size_t len);
void GC9A01_Write_Continue(GC9A01_Typedef *config,uint8_t *data, size_t len);
void GC9A01_Set_Frame(GC9A01_Typedef *config,struct GC9A01_frame frame);
void GC9A01_Draw_Pixel(GC9A01_Typedef *config,uint8_t x,uint8_t y, uint32_t color);
void GC9A01_Set_Window(GC9A01_Typedef *config,uint16_t x1, uint16_t y1, uint16_t w,
        uint16_t h);
void GC9A01_Draw_Point(GC9A01_Typedef *config,uint8_t x, uint8_t y, uint32_t color);
void GC9A01_Splash_Screen(GC9A01_Typedef *config, uint16_t color);
void GC9A01_Draw_Mercury(GC9A01_Typedef *config);
#endif /* GC9A01_H_ */

/*****************************************************************************
* | File      	:   LCD_APP.c
* | Author      :   Waveshare team
* | Function    :   Hardware underlying interface
* | Info        :
*                Used to shield the underlying layers of each master 
*                and enhance portability
*----------------
* |	This version:   V1.0
* | Date        :   2018-01-11
* | Info        :   Basic version
*
******************************************************************************/
#ifndef __LCD_1IN3_H
#define __LCD_1IN3_H	
	
#include "DEV_Config.h"
#include <stdint.h>

#include <stdlib.h>		//itoa()
#include <stdio.h>


#define LCD_HEIGHT 240
#define LCD_WIDTH 240

#define LCD_WIDTH_Byte 240

#define HORIZONTAL 0
#define VERTICAL   1


typedef struct{
	UWORD WIDTH;
	UWORD HEIGHT;
	UBYTE SCAN_DIR;
}LCD_ATTRIBUTES;
extern LCD_ATTRIBUTES LCD;

/********************************************************************************
function:	
			Macro definition variable name
********************************************************************************/
void LCD_1in3_Init(UBYTE Scan_dir);
void LCD_1in3_Clear(UWORD Color);
void LCD_1in3_Display(UWORD *Image);
void LCD_1in3_DisplayWindows(UWORD Xstart, UWORD Ystart, UWORD Xend, UWORD Yend, UWORD *Image);
void LCD_1in3_DisplayPoint(UWORD X, UWORD Y, UWORD Color);
void Handler_1in3_LCD(int signo);
#endif

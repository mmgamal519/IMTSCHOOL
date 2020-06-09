/*

 * main.c
 *
 *  Created on: May 30, 2020
 *      Author: MGIsmail
 */

// modify 199999

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Register.h"
#include "DIO_Interface.h"
#include "LED_Config.h"
#include "LED_Interface.h"
#include "SevSeg2x1_Config.h"
#include "SevSeg2x1_Register.h"
#include "SevSeg2x1_Interface.h"
#include "LCD_Config.h"
#include "LCD_Register.h"
#include "LCD_Interface.h"

#include <util/delay.h>


int main (void)
{
	LCD_VidInit();


	/*LCD_VidWriteData('A');
	LCD_VidWriteData('N');
	LCD_VidWriteData('A');
	LCD_VidWriteData('S');
	LCD_VidWriteData(' ');
	LCD_VidWriteData(' ');
	LCD_VidWriteData('M');
	LCD_VidWriteData('O');
	LCD_VidWriteData('S');
	LCD_VidWriteData('T');
	LCD_VidWriteData('A');
	LCD_VidWriteData('F');
	LCD_VidWriteData('A');
	LCD_VidWriteData(' ');*/
	/*

	LCD_VidWriteCommand(CursorOn);
	LCD_VidWriteCommand(CursorBlink);
	_delay_ms(5000);
	LCD_VidWriteCommand(DisplayOff);
	_delay_ms(2000);
	LCD_VidWriteCommand(DisplayOn);
	_delay_ms(2000);
	LCD_VidWriteCommand(CLRDisplay);
	_delay_ms(2000);
	LCD_VidWriteString("Mostafa Ismail");
	LCD_VidWriteCommand(CursorOn);
	LCD_VidWriteCommand(CursorNoBlink);
	_delay_ms(5000);
	LCD_VidWriteCommand(CursorOff);


	LCD_VidCursorOnOff(On);
	LCD_VidCursorBlinking(On);
	_delay_ms(5000);
	 */
	//LCD_VidArabic();
	//LCD_VidSetPosition(1, 4);

	while(1)
	{
		for (u32 i=10; i<20;i++)
			{
			u8 j=5;
			//	for (u32 j=1; j<20;j++)
				{
					LCD_VidWriteCommand(CLRDisplay);
					LCD_VidWriteEquation (i,'+',j);
					_delay_ms(2000);
					LCD_VidWriteCommand(CLRDisplay);
					LCD_VidWriteEquation (i,'-',j);
					_delay_ms(2000);
					LCD_VidWriteCommand(CLRDisplay);
					LCD_VidWriteEquation (i,'x',j);
					_delay_ms(2000);
					LCD_VidWriteCommand(CLRDisplay);
					LCD_VidWriteEquation (i,'/',j);
					_delay_ms(2000);
					LCD_VidWriteCommand(CLRDisplay);
					LCD_VidWriteEquation (i,'%',j);
					_delay_ms(2000);
				}
			}
		/*
		for (u32 i=5674788; i<23456789; i++)
		{
			LCD_VidWriteCommand(CLRDisplay);
			LCD_VidWriteNumber(i);
			_delay_ms(200);


		}
		/*	LCD_VidWriteString("Mostafa123");
		for (u8 i=0; i<16; i++)
		{
			LCD_VidWriteCommand(DisplayShiftR);
			_delay_ms(500);
		}
		LCD_VidWriteCommand(ReturnHome);
		 */
	}
	return 0;
}


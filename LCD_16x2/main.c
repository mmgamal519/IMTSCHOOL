/*
 * main.c
 *
 *  Created on: May 30, 2020
 *      Author: MGIsmail
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
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

	LCD_VidWriteString("Anas Mostafa");

	LCD_VidCursorOnOff(On);
	LCD_VidCursorBlinking(On);
	_delay_ms(5000);

	LCD_VidDisplayOff();
	_delay_ms(2000);
	LCD_VidDisplayOn();
	_delay_ms(2000);
	LCD_VidClrDisplay();
	_delay_ms(2000);
	LCD_VidWriteString("Mostafa Ismail");
	LCD_VidCursorOnOff(On);
	LCD_VidCursorBlinking(Off);
	_delay_ms(5000);
	LCD_VidCursorOnOff(Off);

	while(1)
	{

	}
	return 0;
}

/*
 * main.c
 *
 *  Created on: Jun 7, 2020
 *      Author: MGIsmail
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Register.h"
#include "DIO_Interface.h"
#include "KP4x4_Config.h"
#include "KP4x4_Interface.h"
#include "SevSeg2x1_Config.h"
#include "SevSeg2x1_Register.h"
#include "SevSeg2x1_Interface.h"
#include "LCD_Register.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"
#include "LCD_CustomChar.h"

#include <util/delay.h>

void  main (void)
{

	//	volatile u8 Button1 = 0;
	//	u8 Button2 = 0;

	LCD_VidInit();
	KeyPad_4x4_VidInit();
LCD_VidArabic();
_delay_ms(2000);
	while(1)
	{
		LCD_VidWriteCommand(CLRDisplay);
		LCD_VidDispCustomChar(customChar_HumanKilloneD,0,0,0);
		_delay_ms(5000);
		for(u8 Row=0; Row<2;Row++)
		{
			for (u8 Col=0; Col <8; Col++)
			{
				LCD_VidWriteCommand(CLRDisplay);
								LCD_VidDispArabicCharRighttoLeft(Mostafa_Arabic,0,Row,Col);
								_delay_ms(2000);
			}
		}


		LCD_VidWriteCommand(CLRDisplay);
				LCD_VidDispCustomChar(Running_graphics,0,0,0);
				_delay_ms(5000);

		/*
		Button1 = KeyPad_4x4_u8ButtonPressed();
		if (Button1 !=0)
		{
			LCD_VidSetPosition(1,0);
			LCD_VidWriteString("   ");
			LCD_VidSetPosition(1,0);
			LCD_VidWriteNumber(Button1);


		}
		 */

		KeyPad4x4_au8GetArray();
		_delay_ms (10000);
	}

}

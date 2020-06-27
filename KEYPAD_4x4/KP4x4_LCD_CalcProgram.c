/*
 * KP4x4_Program.c
 *
 *  Created on: Jun 7, 2020
 *      Author: MGIsmail
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Register.h"
#include "DIO_Interface.h"
#include "KP4x4_Register.h"
#include "KP4x4_Config.h"
#include "KP4x4_Interface.h"
#include "SevSeg2x1_Config.h"
#include "SevSeg2x1_Register.h"
#include "SevSeg2x1_Interface.h"
#include "LCD_Config.h"
#include "LCD_Register.h"
#include "LCD_Interface.h"

#include <util/delay.h>



/***************************************** Macros **************************************/
#define COL_INIT   0

#define COL_FIN    4

#define ROW_INIT   4

#define ROW_FIN    8

#define NOT_PRESSED    255
/***************************************************************************************/
void KeyPad4x4_VidFullcalculator(void)
{
	u8 keypressed=255;
	u8 operator = 0;
	s16 Num =0;
	s16 Num1=0;

	LCD_VidWriteCommand(CLRDisplay);
	LCD_VidSetPosition(0,0);
	LCD_VidWriteString("Calculator");
	LCD_VidSetPosition(1,0);
	while(keypressed != KeyB13)
	{
		keypressed = KeyPad_4x4_u8ButtonPressed();
		if (keypressed >=0 & keypressed <=9)
		{
			Num = Num * 10 +keypressed;
			LCD_VidWriteNumber(keypressed);
		}
		else if (keypressed >=10 & keypressed <=13)
		{
			operator = keypressed;
			Num1 = Num;
			Num = 0;
			switch (operator)
			{
			case 10: LCD_VidWriteData('+'); break;
			case 11: LCD_VidWriteData('-'); break;
			case 12: LCD_VidWriteData('x'); break;
			case 13: LCD_VidWriteData('/'); break;
			}
		}
		else if (keypressed =='#')
		{
			LCD_VidWriteData('=');
			switch (operator)
			{
			case 10: LCD_VidWriteNumber(Num1 + Num); break;
			case 11: Num = Num1 - Num;
				//LCD_VidWriteString("(");
				LCD_VidWriteNumber(Num);
				//LCD_VidWriteString(")");
				break;
			case 12: LCD_VidWriteNumber(Num1 * Num); break;
			case 13: LCD_VidWriteNumber(Num1 / Num);
			if ((Num1 % Num)>0)
				{LCD_VidWriteString(".");
				u16 Div = (1000* (Num1 % Num) )/ Num;
				LCD_VidWriteNumber(Div);
				}
			break;
			}
		}
	}
}

s8 KeyPad4x4_s83ButtonCalc(void)
{
	// Initialize up, down and next buttons
	u8 Up_Button = KeyB1;
	u8 Down_Button = KeyB5;
	u8 Next_Button = KeyB9;
	s8 Num1=0;
	u8 keypressed = NOT_PRESSED;
	u8 Row_postion=1;
	u8 Col_postion=0;

	LCD_VidWriteCommand(CLRDisplay);
	LCD_VidSetPosition(0,0);
	LCD_VidWriteString("Enter number");
	LCD_VidSetPosition(Row_postion,Col_postion);
	LCD_VidWriteCommand(CursorBlink);
	while (keypressed != Next_Button)
	{
		keypressed = KeyPad_4x4_u8ButtonPressed();
		if (keypressed == Up_Button)
		{
			Num1++;
		}
		else 	if (keypressed == Down_Button)
		{
			Num1--;
		}
		if  ((keypressed == Up_Button) | (keypressed == Down_Button) )
		{
			LCD_VidSetPosition(Row_postion,Col_postion);
			LCD_VidWriteString("                ");
			LCD_VidSetPosition(Row_postion,Col_postion);
			if (Num1 < 0)
			{
				//	LCD_VidWriteString("-ve not accepted");
				LCD_VidWriteData('-');
				LCD_VidWriteNumber(-Num1);

			}
			else if (Num1 >= 0)
			{
				LCD_VidWriteNumber(Num1);
			}

		}

	}
	return Num1;
}


u8 KeyPad4x4_s83ButtonOperator(void)
{
	// Initialize up, down and next buttons
	u8 Up_Button = KeyB1;
	u8 Down_Button = KeyB5;
	u8 Next_Button = KeyB9;
	u8 Operator=0;
	u8 Num1=0;
	u8 keypressed = NOT_PRESSED;
	u8 Row_postion=1;
	u8 Col_postion=0;

	LCD_VidWriteCommand(CLRDisplay);
	LCD_VidSetPosition(0,0);
	LCD_VidWriteString("Select Operator");
	LCD_VidSetPosition(Row_postion,Col_postion);
	LCD_VidWriteCommand(CursorBlink);
	while (keypressed != Next_Button)
	{
		keypressed = KeyPad_4x4_u8ButtonPressed();
		if (keypressed == Up_Button)
		{
			Num1++;
		}
		else 	if (keypressed == Down_Button)
		{
			Num1--;
		}
		if  ((keypressed == Up_Button) | (keypressed == Down_Button) )
		{
			LCD_VidSetPosition(Row_postion,Col_postion);
			LCD_VidWriteString("                ");
			LCD_VidSetPosition(Row_postion,Col_postion);
			switch (Num1)
			{
			case 0 : LCD_VidWriteData('+'); break;
			case 1 : LCD_VidWriteData('-'); 	break;
			case 2 : LCD_VidWriteData('x'); 	break;
			case 3 : LCD_VidWriteData('/'); 	break;
			case 4 : LCD_VidWriteData('%');	break;
			}
		}
	}
	return Num1;
}
void KeyPad4x4_Vid3ButtonCalcCall(void)
{
	s8 Num1 = KeyPad4x4_s83ButtonCalc();
	u8 Operator = KeyPad4x4_s83ButtonOperator();
	s8 Num2 = KeyPad4x4_s83ButtonCalc();
	LCD_VidWriteCommand(CLRDisplay);
	LCD_VidSetPosition(0,0);
	LCD_VidWriteString("Result");
	LCD_VidSetPosition(1,0);
	switch (Operator)
	{
	case 0 : LCD_VidWriteNumber(Num1+Num2); break;
	case 1 : LCD_VidWriteNumber(Num1-Num2); 	break;
	case 2 : LCD_VidWriteNumber(Num1*Num2); 	break;
	case 3 : LCD_VidWriteNumber(Num1/Num2); 	break;
	case 4 : LCD_VidWriteNumber(Num1%Num2);	break;
	}
}


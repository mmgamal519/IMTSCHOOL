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


/***************************************************************************************/

/************* KeyPad Key Index ***************/
/*         Col_1    Col_2   Col_3   Col_4    		 */
/*	                                         							 */
/* row_1      1        2       3       4      				*/
/*	                                         							 */
/* row_2  	  5        6       7       8     				 */
/*	                                          							*/
/* row_3	  9        10      11      12    				 */
/*	                                         							 */
/* row_4	  13       14      15      16    				 */
/**********************************************/


/*************************************** Constants *************************************/
/* Values of the Key Pad switches                                                      */
/* Matrix is not standard it depends on the connection between the Micro and KeyPad    */
u8 KPD_au8SwitchVal[4][4] =
{
		{
				KeyB4,    KeyB8,    KeyB12,    KeyB16 },
				{
						KeyB3,    KeyB7,    KeyB11,    KeyB15 },
						{
								KeyB2,    KeyB6,    KeyB10,    KeyB14 },
								{
										KeyB1,    KeyB5,    KeyB9,    KeyB13 }

};

/***************************************************************************************/


/***************************************** Macros **************************************/
//#define PORT DIO_PORTD

#define COL_INIT   0

#define COL_FIN    4

#define ROW_INIT   4

#define ROW_FIN    8

#define NOT_PRESSED    255
/***************************************************************************************/



void KeyPad_4x4_VidInit(void)
{
	DIO_VidSetPortDirection(KeyPadColRow_port, 0x0F);
	DIO_VidSetPortValue(KeyPadColRow_port, 0xFF);	// inactive all Columns C1-C4, and activate pull up resistor for R1-R4
}

u8 KeyPad_4x4_u8ButtonPressed(void)
{
	{
		/* Initialize the switch status to NOT Pressed                                                                     */
		volatile u8 LOC_u8Retrun = NOT_PRESSED;

		/* Looping on columns of the Key Pad                                                                               */
		for (u8 LOC_u8Column = 0 + COL_INIT; LOC_u8Column < COL_FIN; LOC_u8Column++)
		{
			/* Activate the Column                                                                                           */
			DIO_VidSetPinValue(KeyPadColRow_port, LOC_u8Column, OUT_LOW);

			/* Loop on the rows of the Key Pad                                                                               */
			for (u8 LOC_u8Row = 0 + ROW_INIT; LOC_u8Row < ROW_FIN; LOC_u8Row++)
			{
				/* Check the status of the switch                                                                              */
				if (!DIO_u8GetPinValue(KeyPadColRow_port, LOC_u8Row))
				{
					/* Get the value of the currently pressed switch                                                             */
					LOC_u8Retrun = KPD_au8SwitchVal[LOC_u8Column - COL_INIT][LOC_u8Row - ROW_INIT];

					/* Wait until the switch is released (Single Press)                                                          */
					while (!DIO_u8GetPinValue(KeyPadColRow_port, LOC_u8Row))
						;

					/* Delay to avoid bouncing                                                                                   */
					_delay_ms(	50);

				}
			}

			/* Deactivate the Column                                                                                         */
			DIO_VidSetPinValue(KeyPadColRow_port, LOC_u8Column, OUT_HIGH);
		}

		return LOC_u8Retrun;
	}
}

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


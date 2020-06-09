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

#define NOT_PRESSED    0
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

void KeyPad4x4_au8GetArray(void)
{
	LCD_VidWriteData(CLRDisplay);
	_delay_ms(100);
	LCD_VidSetPosition(0,0);
	LCD_VidWriteString("calculate");
	//u8 Array[10];
	volatile u8 Index = 0;
	volatile u8 Button = 0xFF;
	volatile u32 Num1 =0;
	volatile u32 Num2 =0;
	volatile u32 Result =0;
	volatile u32 Temp = 0;
	volatile u8 SignFlag = 0;
	// go to position will write at LCD
	LCD_VidSetPosition(1,0);
	LCD_VidWriteString("                            ");
	LCD_VidSetPosition(1,0);
	//LCD_VidWriteData(CursorOn);
	//loop and get all pressed keys then save it in array with limited length till press enter (ex keyBB15)

	while (Button  != KeyB13 )
	{
		Button = KeyPad_4x4_u8ButtonPressed();
		if (Button !=0)
		{
			//Array[Index]= Button;




			if (Button == KeyB4 )
			{
				LCD_VidWriteData('+');
				Num1 = Temp;
				Temp = 0;
				SignFlag = 1;
				Index = 0;
			}
			else if (Button == KeyB8 )
			{
				LCD_VidWriteData('-');
				Num1 = Temp;
				Temp = 0;
				SignFlag = 2;
				Index = 0;
			}
			else if (Button == KeyB12 )
			{
				LCD_VidWriteData('x');
				Num1 = Temp;
				Temp = 0;
				SignFlag = 3;
				Index = 0;
			}
			else if (Button == KeyB16 )
			{
				LCD_VidWriteData('/');
				Num1 = Temp;
				Temp = 0;
				SignFlag = 4;
				Index = 0;
			}
			else if (Button == KeyB15 )
			{
				LCD_VidWriteData('=');
				Num2 = Temp;
				break;
			}
			else if (Button == KeyB13 )
			{
				LCD_VidWriteData('=');
				Num2 = Temp;
				break;
			}
			else if (Button >0 && Button <=9 )
			{
				LCD_VidWriteNumber(Button);
				Temp = Temp*Index*10 + Button;
							Index++;

			}
		}

	}
	switch (SignFlag)
			{
			case 1 : Result = Num1 + Num2; LCD_VidWriteNumber(Result); break;
			case 2 : Result = Num1 - Num2; LCD_VidWriteNumber(Result); break;
			case 3 : Result = Num1 * Num2; LCD_VidWriteNumber(Result); break;
			case 4 : Result = Num1 / Num2; LCD_VidWriteNumber(Result); break;
			}
}


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

void LCD_VidInit(void)
{
	_delay_ms(50); // wait for LCD to initialize
	DIO_VidSetPortDirection(LCD_DataPort, 0xff ); //Data port direction output
	DIO_VidSetPinDirection(LCD_CTRLPort,  LCD_RS_PIN, OUT_HIGH); //RS
	DIO_VidSetPinDirection(LCD_CTRLPort,  LCD_RW_PIN, OUT_HIGH); //RW
	DIO_VidSetPinDirection(LCD_CTRLPort,  LCD_Enb_PIN, OUT_HIGH); //Enb    CTRL PINS direction output
	LCD_VidWriteCommand(FunctionSet_8bit); 	//function set
	_delay_ms(1); // wait for LCD to Function set
	LCD_VidWriteCommand(DisplayOn);	//Display On
	_delay_ms(1); // wait for LCD to Display On
	LCD_VidWriteCommand(CLRDisplay);	//Clear Display
	_delay_ms(2); // wait for LCD to Clear Display
}

void LCD_VidWriteCommand(u8 LOC_u8Command)
{
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_RS_PIN, OUT_LOW);  //RS = 0   register selection
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_RW_PIN, OUT_LOW);  //RW = 0
	DIO_VidSetPortValue(LCD_DataPort, LOC_u8Command);  // Write Command
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_Enb_PIN, OUT_HIGH);  //Enable = 1 high rise edge
	_delay_ms(1);	// required by LCD Datasheet
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_Enb_PIN, OUT_LOW);  //Enable = 0  Falling edge
	_delay_ms(1); // give the LCD time to wite / display
}

void LCD_VidWriteData(u8 LOC_u8Data)
{
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_RS_PIN, OUT_HIGH);  //RS = 1
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_RW_PIN, OUT_LOW);  //RW = 0
	DIO_VidSetPortValue(LCD_DataPort, LOC_u8Data);  // Write data
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_Enb_PIN, OUT_HIGH);  //Enable = 1 high rise edge
	_delay_ms(1);	// required by LCD Datasheet
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_Enb_PIN, OUT_LOW);  //Enable = 0  Falling edge
	_delay_ms(1); // give the LCD time to wite / display

}

void LCD_VidWriteString(u8 LOC_u8String[])
{


	for (u8 i=0; LOC_u8String[i] != '\0'; i++) 						// using Null character to stop
	{
		LCD_VidWriteData(LOC_u8String[i]);
	}
}

void LCD_VidWriteNumber(u32 LOC_u32Number)
{

	u8 digit = 0;
	u8 flag = 0;
	u32 reversed = 0;

	while (LOC_u32Number>0)
	{
		reversed = reversed * 10 + LOC_u32Number % 10;
		LOC_u32Number = LOC_u32Number / 10;
	}
	/*	while (reversed>0)
		{
			digit = reversed % 10 + 48;
			reversed = reversed / 10;
			LCD_VidWriteData(digit);
	 */
	LOC_u32Number = reversed;
	while (flag == 0)
	{
		if ( LOC_u32Number == 0 )
		{
			LCD_VidWriteData(48);
			LCD_VidWriteCommand(DisplayShiftR);
			flag = 1;
		}
		else if ( LOC_u32Number % 10 == 0)
		{
			LCD_VidWriteData(48);
			//	LCD_VidWriteCommand(DisplayShiftR);
			LOC_u32Number = LOC_u32Number /10;
		}
		else  // if (LOC_u32Number != 0 &&  )
		{
			digit = LOC_u32Number % 10;
			LCD_VidWriteData(digit + 48);
			//		LCD_VidWriteCommand(DisplayShiftR);
			LOC_u32Number = LOC_u32Number /10;
			if (LOC_u32Number >0 && LOC_u32Number <1)
			{
				flag = 1;
			}
		}
	}
	/*
	u32 reversed = 0;
	u8 digit = 0;
	while (LOC_u32Number>0)
	{
		reversed = reversed * 10 + LOC_u32Number % 10;
		LOC_u32Number = LOC_u32Number / 10;
	}
	while (reversed>0)
	{
		digit = reversed % 10 + 48;
		reversed = reversed / 10;
		LCD_VidWriteData(digit);
	}
	 */
}

void LCD_VidSetPosition(u8 LOC_u8Row, u8 LOC_u8Column)
{
	if (LOC_u8Row ==0)
	{
		LCD_VidWriteCommand(128+LOC_u8Column);
	}
	else if (LOC_u8Row == 1)
	{
		LCD_VidWriteCommand(128+64+LOC_u8Column);
	}
}

void LCD_VidArabic(void)
{
	LCD_VidWriteCommand(0b01000000);
	LCD_VidWriteData(0b00011110);
	LCD_VidWriteData(0b00111000);
	LCD_VidWriteData(0b01111110);
	LCD_VidWriteData(0b00000000);
	LCD_VidWriteData(0b00001100);
	LCD_VidWriteData(0b00001100);
	LCD_VidWriteData(0b00001100);
	LCD_VidWriteData(0b00001100);
	LCD_VidSetPosition(0,0);				// to back to DDRAM
	LCD_VidWriteData(0b00000000); // write address of of CGRAM instade of send data
}



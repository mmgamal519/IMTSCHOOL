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
//#include "LCD_CustomChar.h"
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

void LCD_VidWriteString(u8* LOC_u8String)
{


	for (u8 i=0; LOC_u8String[i] != '\0'; i++) 						// using Null character to stop
	{
		LCD_VidWriteData(LOC_u8String[i]);
	}
}

void LCD_VidWriteNumber(u32 LOC_u32Number)
{
	u8 Reversed_Number[Large_number_length];

	s8 Rev_Counter = 0;
	u8 Counter=0;
	u8 digit=0;
	if (LOC_u32Number ==0)
	{
		LCD_VidWriteData(48);
	}
	while(LOC_u32Number>0)
	{
		Reversed_Number [Counter] = LOC_u32Number % 10;
		LOC_u32Number = LOC_u32Number  / 10;
		Counter++;
	}
	Counter--;
	for (Rev_Counter=Counter;Rev_Counter>=0;Rev_Counter--)
	{
		digit = Reversed_Number[Rev_Counter]+48;
		LCD_VidWriteData(digit);
	}
	_delay_ms(10);
}
void LCD_VidWriteEquation(u32 LOC_u32Number1, u32 LOC_u8Op, u32 LOC_u32Number2)
{
	LCD_VidWriteNumber(LOC_u32Number1);
	LCD_VidWriteData(LOC_u8Op);
	LCD_VidWriteNumber(LOC_u32Number2);
	LCD_VidWriteData('=');
	switch (LOC_u8Op)
	{
	case '+' : LCD_VidWriteNumber(LOC_u32Number1 + LOC_u32Number2); break;
	case '-' : LCD_VidWriteNumber(LOC_u32Number1 - LOC_u32Number2); break;
	case 'x' : LCD_VidWriteNumber(LOC_u32Number1 * LOC_u32Number2); break;
	case '/' : LCD_VidWriteNumber(LOC_u32Number1 / LOC_u32Number2); break;
	case '%' : LCD_VidWriteNumber(LOC_u32Number1 %  LOC_u32Number2); break;
	}
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


void LCD_VidDispCustomChar(u8 *ptr, u8 LOC_u8CustomCharNum, u8 LOC_u8Row, u8 LOC_u8Column )
{
	volatile u8 LOC_a8CustomCharData=0;
	LCD_VidWriteCommand(CGRAM);  //Load location of CGRAM to Draw the custom char
	for (u8 i=0; i<64; i++)
	{
		LOC_a8CustomCharData =*(ptr+i);
		//ptr++;
		LCD_VidWriteData( LOC_a8CustomCharData);  //from 1st top row  to last bottom row
	}

	for (u8 i=0; i<8; i++)
	{
		LCD_VidSetPosition(LOC_u8Row, i);				// to back to DDRAM and set position
		LCD_VidWriteData(i); // write address of of CGRAM instade of send data , the adress of selected char we need to load
	}
}

void LCD_VidDispArabicCharRighttoLeft(u8 *ptr, u8 LOC_u8CustomCharNum, u8 LOC_u8Row, u8 LOC_u8Column )
{
	volatile u8 LOC_a8CustomCharData=0;
	LCD_VidWriteCommand(CGRAM);  //Load location of CGRAM to Draw the custom char
	for (u8 i=0; i<64; i++)
	{
		LOC_a8CustomCharData =*(ptr+i);
		//ptr++;
		LCD_VidWriteData( LOC_a8CustomCharData);  //from 1st top row  to last bottom row
	}

	for (s8 i=0; i<8; i++)
	{
		LCD_VidSetPosition(LOC_u8Row, i+LOC_u8Column);				// to back to DDRAM and set position
		LCD_VidWriteData(8-1-i); // write address of of CGRAM instade of send data , the adress of selected char we need to load
	}
}


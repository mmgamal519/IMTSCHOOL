#include "STD_TYPES.h"
#include "BIT_Math.h"
#include "avr/delay.h"
#include "DIO_Interface.h"

void LCD_VidInit(void)
{
	_delay_ms(50); // wait for LCD to initialize
	DIO_VidSetPortDirection(PORTD, 0xff );
	DIO_VidSetPortDirection(PORTB, 0b00111000 ); //RS RW E

	LCD_VidWriteCommand(0b00111000); 	//function set
	_delay_ms(1); // wait for LCD to Function set
	LCD_VidWriteCommand(0b00001100);	//Display On
	_delay_ms(1); // wait for LCD to Display On
	LCD_VidWriteCommand(0b00000001);	//Clear Display 
	_delay_ms(2); // wait for LCD to Clear Display

}

void LCD_VidWriteCommand(u8 LOC_u8Command)
{
	DIO_VidSetPinValue(PORTB, PIN3, OUT_LOW);  //RS = 0   register selection
	DIO_VidSetPinValue(PORTB, PIN4, OUT_LOW);  //RW = 0
	DIO_VidSetPortValue(PORTD, LOC_u8Command);  // Write Command
	DIO_VidSetPinValue(PORTB, PIN5, OUT_HIGH);  //Enable = 1 high rise edge
	_delay_ms(1);	// required by LCD Datasheet
	DIO_VidSetPinValue(PORTB, PIN5, OUT_LOW);  //Enable = 0  Falling edge
	_delay_ms(1); // give the LCD time to wite / display



}

void LCD_VidWriteData(u8 LOC_u8Data)
{
	DIO_VidSetPinValue(PORTB, PIN3, OUT_HIGH);  //RS = 0
	DIO_VidSetPinValue(PORTB, PIN4, OUT_LOW);  //RW = 0
	DIO_VidSetPortValue(PORTD, LOC_u8Data);  // Write data
	DIO_VidSetPinValue(PORTB, PIN5, OUT_HIGH);  //Enable = 1 high rise edge
	_delay_ms(1);	// required by LCD Datasheet
	DIO_VidSetPinValue(PORTB, PIN5, OUT_LOW);  //Enable = 0  Falling edge
	_delay_ms(1); // give the LCD time to wite / display

}

void LCD_VidWriteString(u8 LOC_u8String[16])
{
	for (u8 i=0; i<16; i++)
	{
		LCD_VidWriteData(LOC_u8String[i]);
	}
}

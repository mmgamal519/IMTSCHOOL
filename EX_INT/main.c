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
#include "LCD_Register.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"

#include "EXIT_Register.h"
#include "EXIT_Interface.h"
#include "GLOBALINT_Register.h"
#include "GLOBALINT_Interface.h"
#include "ADC_Interface.h"
#include "ADC_Config.h"

#include <util/delay.h>
void ADC_Function (u16 LOC_u16ADCValue);
void  main (void)
{
_delay_ms(100);
	ADC_SetCallBack(ADC_Function);
	ADC_VidInit();
	LCD_VidInit();
	LCD_VidWriteCommand(CLRDisplay);
	LCD_VidWriteString("ADC Conversion");
	GLOBALINT_VidEnable();
	ADC_VidInterrupt_Enable();
	ADC_VidStartConversionNonBlocking(ADC_Channel0);
	while(1)
	{
	}
}
void ADC_Function (u16 LOC_u16ADCValue)
{//( ADC_VidGetDigitalValue( ADC_Channel0 )
	u16 Value = LOC_u16ADCValue * 5000UL / 256 ;	//UL after integer to represent the number as unsigned long
	LCD_VidSetPosition(1,0);
	LCD_VidWriteString("Temp=");
	LCD_VidWriteString("     ");
	LCD_VidSetPosition(1,6);
	LCD_VidWriteNumber(Value/10);
	LCD_VidWriteString("C");
	_delay_ms(50);
}
/*void ADC_Function (u16 LOC_u16ADCValue)
{//( ADC_VidGetDigitalValue( ADC_Channel0 )
	u16 Value = LOC_u16ADCValue * 5000UL / 1024;	//UL after integer to represent the number as unsigned long
	LCD_VidSetPosition(1,0);
	LCD_VidWriteString("value=");
	LCD_VidWriteString("     ");
	LCD_VidSetPosition(1,8);
	//LCD_VidWriteNumber(Value);
	LCD_VidWriteNumber(Value);
	_delay_ms(50);
}
*/
//_delay_ms(500);		forbeden to use inside ISR
/*	if(Value <1500)
{
	DIO_VidSetPinValue(PORT_C,PIN0,1);
}
else if(Value >1500 && Value <3000)
{
	DIO_VidSetPinValue(PORT_C,PIN1,1);
}else if(Value >3000)
{
	DIO_VidSetPinValue(PORT_C,PIN2,1);
}
_delay_ms(1000);
*/
/*
	//	u16 Value =0;
		//_delay_ms(2000);
		//		LCD_VidWriteCommand(ReturnHome);


		//ADC_VidInterrupt_Enable();
		DIO_VidSetPinValue(PORT_C,PIN0,0);
		DIO_VidSetPinValue(PORT_C,PIN1,0);
		DIO_VidSetPinValue(PORT_C,PIN2,0);
#if ADC_Auto_Trigger ==	ADC_Auto_Trigger_Disable
		Value =( ADC_VidGetDigitalValue( ADC_Channel0 ) * 5000UL )/ 1024;	//UL after integer to represent the number as unsigned long
		LCD_VidSetPosition(1,0);
		LCD_VidWriteString("ADC = ");
		LCD_VidWriteNumber(Value);
		_delay_ms(50);
#endif
			if(Value <1500)
		{
			DIO_VidSetPinValue(PORT_C,PIN0,1);
		}
		else if(Value >1500 && Value <3000)
		{
			DIO_VidSetPinValue(PORT_C,PIN1,1);
		}else if(Value >3000)
		{
			DIO_VidSetPinValue(PORT_C,PIN2,1);
		}
 */

/*

	DIO_VidSetPinDirection(PORT_C,PIN0,OUTPUT);
	DIO_VidSetPinDirection(PORT_C,PIN1,OUTPUT);
	DIO_VidSetPinDirection(PORT_C,PIN2,OUTPUT);
	GLOBALINT_VidEnable();
	EXTINT0_VidInit();
	EXTINT0_VidEnable();
 */

/*			main for interrupt
 * DIO_VidSetPinDirection(PORT_C,PIN0,OUTPUT);
	DIO_VidSetPinDirection(PORT_C,PIN1,OUTPUT);
	DIO_VidSetPinDirection(PORT_C,PIN2,OUTPUT);
	GLOBALINT_VidEnable();
	EXTINT0_VidInit();
	EXTINT0_VidEnable();
	EXTINT1_VidInit();
	EXTINT1_VidEnable();
	EXTINT2_VidInit();
	EXTINT2_VidEnable();
	while(1)
	{
		DIO_VidSetPinValue(PORT_C,PIN0,0);
		DIO_VidSetPinValue(PORT_C,PIN1,0);
		DIO_VidSetPinValue(PORT_C,PIN2,0);
	}
 */


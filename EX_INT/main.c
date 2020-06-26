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

void  main (void)
{
	ADC_VidInit();
	//u16 Value=0;
	LCD_VidInit();


	DIO_VidSetPinDirection(PORT_C,PIN0,OUTPUT);
	DIO_VidSetPinDirection(PORT_C,PIN1,OUTPUT);
	DIO_VidSetPinDirection(PORT_C,PIN2,OUTPUT);
	GLOBALINT_VidEnable();
	EXTINT0_VidInit();
	EXTINT0_VidEnable();
	LCD_VidWriteCommand(CLRDisplay);
	LCD_VidWriteString("ADC Conversion");
	u16 Value =0;
	while(1)
	{



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
		 */
	}
}

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


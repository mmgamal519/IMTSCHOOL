/*
 * ADC_App_main.c
 *
 *  Created on: Jul 16, 2020
 *      Author: MGIsmail
 */


/*
 * main.c
 *
 *  Created on: Jun 7, 2020
 *      Author: MGIsmail
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_Interface.h"
//#include "../../MCAL/TIMERS/TIMER_Interface.h"
#include "../../MCAL/EXT_INT/EXIT_Interface.h"
#include "../../MCAL/GIP/GLOBALINT_Interface.h"
#include "../../MCAL/ADC/ADC_Interface.h"

#include "../../HAL/LCD16x2/LCD_Interface.h"
//#include "../../AppL/Smart_Home/Smart_Home_Interface.h"

#include <util/delay.h>
void ADC_Function (u16 LOC_u16ADCValue);
void TIMER0_Function (void);

//u8 volatile flag=0;
//u16 volatile Snap1=0, Snap2=0, Snap3=0;
//u8 OVF=0;



void  ADC_main (void)
{
	//	DIO_VidSetPinDirection(PORT_B, PIN3, OUT_HIGH);
	// ICP PIN PD6 as input
	//connect PB3 with PD6 wired
	// init Timer0		for PWM
	// OCR0 Timer0 == 128		/outpin =PB3
	//enable global interrupt GIE
	//Init Timer1	== normal mode
	//Enable Timer1 Input Capture ISR  and OVF INT
	//Init LCD

	while(1)
	{
		/*if (flag==3)
		{
			//dont reset `OVF during capture snap 1 2 3
			//duty = (Snap2-Snap1) / (Snap3-Snap1)
			//	freq = 1 /(Sanp3-Snap1);
			//LCD display Duty cycle;
			//LCD Display freq;
			//flag=0;
		}
*/
	}
}
/*
void  main (void)
{
	/*LCD_VidInit();
	ADC_VidInit();
	GLOBALINT_VidEnable();
	Smart_Home_Main ();

	DIO_VidSetPinDirection(PORT_B, PIN3, OUT_HIGH);
	TIMER_VidInit();
	while(1)
	{
		Set_Duty_Cycle(0);
		_delay_ms(1000);
		Set_Duty_Cycle(1000);
		_delay_ms(1000);
		Set_Duty_Cycle(2000);
		_delay_ms(1000);
		Set_Duty_Cycle(3000);
		_delay_ms(1000);
		Set_Duty_Cycle(4000);
		_delay_ms(1000);
		Set_Duty_Cycle(5000);
		_delay_ms(1000);

	}
}
 */
/*{
	_delay_ms(100);
	//ADC_SetCallBack(ADC_Function);
	TIMER_SetCallBack(TIMER0_Function);
	TIMER_VidInit();
	ADC_VidInit();
	LCD_VidInit();
	LCD_VidWriteCommand(CLRDisplay);
	//	LCD_VidWriteString("ADC Conversion");
	GLOBALINT_VidEnable();
	//	ADC_VidInterrupt_Enable();
	//	ADC_VidStartConversionNonBlocking(ADC_Channel0);
	LCD_VidSetPosition(0,0);
	LCD_VidWriteString("Clock Timer");

	_delay_ms(1000);
	LCD_VidWriteCommand(CLRDisplay);
	LCD_VidSetPosition(0,0);
	LCD_VidWriteString("HH:MM:SS");

	while(1)
	{
	}
}
 */
void TIMER0_Function (void)
{
	static u32 counter = 0;

	static u8 sec = 0;
	static u8 min = 0;
	static u8 Hours = 0;
	counter ++;
	if ((counter%3600) == 0)     //3906
	{
		LCD_VidSetPosition(1,0);
		LCD_VidWriteString("         ");
		LCD_VidSetPosition(1,0);
		if (Hours <= 9)
		{
			LCD_VidWriteData('0');
		}
		LCD_VidWriteNumber(Hours);

		LCD_VidSetPosition(1,2);
		LCD_VidWriteData(':');
		if (min <= 9)
		{
			LCD_VidWriteData('0');
		}
		LCD_VidWriteNumber(min);
		LCD_VidSetPosition(1,5);
		LCD_VidWriteData(':');
		if (sec <= 9)
		{
			LCD_VidWriteData('0');
		}
		LCD_VidWriteNumber(sec);
		sec++;
		if ((sec%60) == 0)
		{
			min++;
			sec =0;
			if ((min%60) == 0)
			{
				min=0;
				Hours++;
				//LCD_VidWriteNumber(counter/3906);
			}
		}
	}

}

void ADC_Function (u16 LOC_u16ADCValue)
{//( ADC_VidGetDigitalValue( ADC_Channel0 )
	/*
	 * u16 Value = LOC_u16ADCValue * 5000UL / 256 ;	//UL after integer to represent the number as unsigned long
	LCD_VidSetPosition(1,0);
	LCD_VidWriteString("Temp=");
	LCD_VidWriteString("     ");
	LCD_VidSetPosition(1,6);
	LCD_VidWriteNumber(Value/10);
	LCD_VidWriteString("C");
	_delay_ms(50);
	 */
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








































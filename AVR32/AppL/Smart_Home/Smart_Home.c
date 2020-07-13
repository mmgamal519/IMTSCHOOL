/*
 * Smart_Home.c
 *
 *  Created on: Jun 29, 2020
 *      Author: MGIsmail
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "../../MCAL/DIO/DIO_Interface.h"

#include "../../HAL/LCD16x2/LCD_Interface.h"
#include "../../MCAL/TIMERS/TIMER_Interface.h"

#include "../../MCAL/EXT_INT/EXIT_Interface.h"
#include "../../MCAL/GIP/GLOBALINT_Interface.h"
#include "../../MCAL/ADC/ADC_Interface.h"

#include "../../HAL/KeyPad4x4/KP4x4_Interface.h"

#include "Smart_Home_Config.h"
#include "Smart_Home_Interface.h"
#include <util/delay.h>

#define funcA			Welcome
#define funcB			Login
#define funcC			Menu
#define funcD			fnNull
#define funcE			fnNull
//Prototypes for functions that appear in the jump table

// Jump Table function implementation
void Smat_Home_Jump_Table(u8 const jump_index)
{
	static void (*pf[])(void) = {funcA, funcB, funcC, funcD, funcE};
	// Check pointer validation
	if (jump_index < sizeof(pf) / sizeof(*pf))
	{    // Call the function specified by jump_index
		pf[jump_index]();
	}
}
// Dummy function - used as an array filler
void fnNull(void)
{
	//  Do Nothing; or  return 0;
}
void Smart_Home_Main (void)
{
	static u8 login_status=0;
	u8 menu_select=0;
	Welcome ();
	if (login_status ==0)
	{
		login_status = Login ();
	}
	if (login_status ==1)
	{
		while (1)
		{
			menu_select = Menu ();
			switch (menu_select)
			{
			case 1:	Smart_Temp(); 	break;
			case 2:	Smart_Light();	break;
			case 3:	Smart_Motor();	break;
			case 4:	Smart_All();		break;
			}
		}
	}
}
//Welcome Screen
void Welcome (void)
{
	LCD_VidWriteCommand(CLRDisplay);
	LCD_VidSetPosition(0,5);
	LCD_VidWriteString("Welcome");
	LCD_VidSetPosition(1,3);
	LCD_VidWriteString("Smart Home");
	_delay_ms(2000);
}
//Login password
u8 Login (void)
{
	KeyPad_4x4_VidInit();
	u8 Password_accepted = 0;
	u32 User_Password=0;
	u8 keypressed = NOT_PRESSED;
	LCD_VidWriteCommand(CLRDisplay);
	LCD_VidSetPosition(0,0);
	LCD_VidWriteString("Enter Password");
	LCD_VidSetPosition(1,0);
	LCD_VidWriteString("then '#'");
	_delay_ms(1000);
	LCD_VidSetPosition(1,0);
	LCD_VidWriteString("        ");
	LCD_VidSetPosition(1,0);
	while(keypressed != KeyB12)
	{
		keypressed = KeyPad_4x4_u8ButtonPressed();
		if (keypressed >=0 && keypressed <=9)
		{
			User_Password=User_Password*10+keypressed;
			LCD_VidWriteString("*");
			//LCD_VidWriteNumber(keypressed);
			//	Col_postion ++;
		}
		/*	else if (keypressed ==Up_Button || keypressed ==Down_Button ||  keypressed ==Next_Button)
			{Password_char = 'a';
			do
			{

				// Initialize up, down and next buttons
				LCD_VidWriteNumber(Password_char);
				_delay_ms(100);
				LCD_VidSetPosition(Row_postion, Col_postion);
				LCD_VidWritedata('*');
				Col_postion ++;
				keypressed = KeyPad_4x4_u8ButtonPressed();
				if (keypressed == Up_Button)
				{
					if ((Password_char >='a') && (Password_char >='Z'))
					{
						Password_char++;
					}
				}
				else 	if (keypressed == Down_Button)
				{
					if ((Password_char >='a') && (Password_char >='Z'))
					{
						Password_char--;
					}
				}
			}while (keypressed !=Next_Button);
			}
		 */
	}
	if (User_Password == Login_Password)
	{
		LCD_VidSetPosition(1,0);
		LCD_VidWriteString("Access Allowed");
		_delay_ms(1000);
		Password_accepted = 1;
	}
	else
	{
		LCD_VidSetPosition(1,0);
		LCD_VidWriteString("Access Deny");
		_delay_ms(1000);
		Password_accepted = 0;
	}
	return Password_accepted;
}
//Option Menu
u8 Menu (void)
{
	u8 keypressed = NOT_PRESSED;
	LCD_VidWriteCommand(CLRDisplay);
	LCD_VidSetPosition(0,0);
	LCD_VidWriteString("1:Temp");
	LCD_VidSetPosition(0,10);
	LCD_VidWriteString("2:Light");
	LCD_VidSetPosition(1,0);
	LCD_VidWriteString("3:Motor");
	LCD_VidSetPosition(1,10);
	LCD_VidWriteString("4:All");
	while (!((keypressed >=1)&&(keypressed <=4)))
	{
		keypressed = KeyPad_4x4_u8ButtonPressed();
	}
	return keypressed;
}
//1-Temp
void Smart_Temp(void)
{
	LCD_VidWriteCommand(CLRDisplay);
	LCD_VidSetPosition(0,0);
	LCD_VidWriteString("Temp");
	_delay_ms(1000);
	ADC_VidInterrupt_Enable();
	ADC_VidStartConversionNonBlocking(ADC_Channel0);
	_delay_ms(1);
	u16 LOC_u16ADCValue = ADC_VidGetDigitalValue( ADC_Channel0 );
	u16 Value = (LOC_u16ADCValue * 500UL) / 1024UL ;	//UL after integer to represent the number as unsigned long
	LCD_VidSetPosition(1,0);
	LCD_VidWriteString("Temp=");
	LCD_VidWriteString("     ");
	LCD_VidSetPosition(1,6);
	LCD_VidWriteNumber(Value);
	LCD_VidWriteString("C");
	_delay_ms(2000);
/*
 * void update_analog_readings(void)
{
	//generate display strings

	// 1. temp reading
	u16 temp = (temp_reading*500UL)>>10 ; // (temp in mV) = (reading*5000)/(ADC_resoultion);
												// each 10 mv is 1 degC
											// T = (temp in mV)/10
	itoa(temp,temp_reading_string);
	strcat(temp_reading_string," C");

	//2. LDR reading
	u16 ldr = (LDR_reading);

	//update display strings
	strcpy(items_temp[1].name,temp_reading_string);
	strcpy(items_LDR[1].name, LDR_reading_string);
}

 */
}
//2-Light LDR
void Smart_Light(void)
{
	LCD_VidWriteCommand(CLRDisplay);
	LCD_VidSetPosition(0,0);
	LCD_VidWriteString("Smart_Light");
	_delay_ms(1000);
	ADC_VidInterrupt_Enable();
	ADC_VidStartConversionNonBlocking(ADC_Channel1);
	_delay_ms(1);
	u16 LOC_u16ADCValue = ADC_VidGetDigitalValue( ADC_Channel1 );
	u16 Value = (LOC_u16ADCValue * 100UL ) / 1024 ;	//UL after integer to represent the number as unsigned long
	LCD_VidSetPosition(1,0);
	LCD_VidWriteString("Light ");
	LCD_VidWriteString("     ");
	LCD_VidSetPosition(1,6);
	LCD_VidWriteNumber(Value);
	LCD_VidWriteString("%");
	_delay_ms(2000);
}
//3-Motor Control
void Smart_Motor(void)
{
	LCD_VidWriteCommand(CLRDisplay);
	LCD_VidSetPosition(0,0);
	LCD_VidWriteString("Smart_Motor");
	_delay_ms(1000);
}
//4-ALL
void Smart_All(void)
{
	//Over Temperature ADC INT -> Buzzer
	LCD_VidWriteCommand(CLRDisplay);
	LCD_VidSetPosition(0,0);
	LCD_VidWriteString("Smart_All");
	_delay_ms(1000);
	//Low Light LDR ADC INT ->LED on
}

/*
 * main.c
 *
 *  Created on: May 30, 2020
 *      Author: MGIsmail
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Register.h"
#include "DIO_Interface.h"
#include "UART_Interface.h"
#include "LCD_4BIT_Interface.h"
#include "GIE_Interface.h"
#include "TIMER_Interface.h"
#include "TIMER_Regster.h"
#include "EXI_Regster.h"

#include <util/delay.h>

//void func_1(void);
int main (void)
{
	DIO_VidSetPinDirection(PORTD,PIN0,INPUT);
	DIO_VidSetPinDirection(PORTD,PIN1,OUTPUT);
	DIO_VidSetPinDirection(PORTB,PIN7,OUTPUT);
	//lcd int
	LCD_Vid4Initialization();
	//UART int
	UART_VidInit();
while(1)
	{
      u8 data=receiv_Data( );
      if(data=='w')
      {
    	  DIO_VidSetPinValue(PORTB,PIN7,1);
    	  Send_Data('w');
      }
      else if(data=='s')
      {
    	  DIO_VidSetPinValue(PORTB,PIN7,0);
    	  Send_Data('s');
      }
      LCD_VidWrite4Data(data);
      LCD_Write4String("UART:",0,0);
  	LCD_VidDisp4Number(data);
  	LCD_Write4String("UART:",0,5);
	}
return 0;
}

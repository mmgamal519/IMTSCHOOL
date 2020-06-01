/*
 * main.c
 *
 *  Created on: May 15, 2020
 *      Author: MGIsmail
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"

#include <util/delay.h>

int main (void)
{
	DIO_VidSetPortDirection(PORTA, 0xff);

	DIO_VidSetPinDirection(PORTB, PIN2, INPUT);
	while (1)
	{
		for (u8 i=0; i<8; i++)
		{
			DIO_VidSetPinValue(PORTA, i, OUT_HIGH );
			_delay_ms(100);
			DIO_VidSetPinValue(PORTA, i, OUT_LOW );
			_delay_ms(100);
		}
		DIO_VidSetPinValue(PORTB,PIN2, OUT_HIGH); // to activate pull-up resistor
		if (DIO_u8GetPinValue(PORTB,PIN2)==1)
		{
			DIO_VidSetPinValue(PORTA, PIN0, OUT_LOW );
			_delay_ms(100);
		}
		else
		{
			DIO_VidSetPinValue(PORTA, PIN0, OUT_HIGH);
			_delay_ms(100);
		}

		DIO_VidSetPinValue(PORTB, PIN2, OUT_HIGH); // pull-up resistor

		if ((DIO_u8GetPinValue(PORTB, PIN2) & 0x01) ==1)
		{

			DIO_7Seg (0,10,10);

		}
		else if ((DIO_u8GetPinValue(PORTB, PIN2) & 0x01)==0)
		{
			loading_7seg(2);
		}
	}
	return 0;
}



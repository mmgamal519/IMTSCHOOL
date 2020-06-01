/*
 * main.c
 *
 *  Created on: May 17, 2020
 *      Author: MGIsmail
 */

#include <avr/io.h>
#include <util/delay.h>

#define SET_bit(var, bit_no)		var = (1<<bit_no)|var
#define CLR_bit(var, bit_no)		var = ~(1<<bit_no)&var

int main (void)
{
	DDRA=0xFF;
	PORTA=0x00;
	while(1)
	{


		for (char i=0; i<=3; i++)
		{
			SET_bit(PORTA, i);
			SET_bit(PORTA, (7-i));
			_delay_ms(400);
		}

		for ( int  i=3; i>=0; i--) //signed int also works
		{
			CLR_bit(PORTA, i);
			CLR_bit(PORTA, (7-i));
			_delay_ms(400);
		}

	}

}

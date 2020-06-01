/*
 * sevenSegment.c
 *
 *  Created on: May 16, 2020
 *      Author: mazen
 */


#include <avr/io.h>
#include <util/delay.h>


///  Connections
///  PORTx:  bit-7 bit-6 bit-5 bit-4 bit-3 bit-2 bit-1 bit-0
///  7-SEG:   dot     G     F     E     D     C     B     A

#define ZERO 0b00111111
#define ONE 0b00000110
#define TWO 0b01011011
#define THREE 0b01001111
#define FOUR 0b01100110
#define FIVE 0b01101101
#define SIX 0b01111101
#define SEVEN 0b00000111
#define EIGHT 0b011111111
#define NINE 0b01101111
#define DOT 0b10000000



int main(void)
{
	// init...
	DDRC = 0xff ; //use all port pins as outputs

	uint8_t seven_seg_digits[10] = {ZERO,ONE,TWO, THREE , FOUR , FIVE, SIX , SEVEN , EIGHT , NINE } ;

	// superloop
	while(1)
	{

		for(int i=0; i<10 ; i++)
		{
			PORTC = ~seven_seg_digits[i];
			_delay_ms(1000);
		}


	}

}

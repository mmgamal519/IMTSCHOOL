/*
 * main.c
 *
 *  Created on: May 15, 2020
 *      Author: MGIsmail
 */

#include <avr/io.h>
#include <util/delay.h>
#define SET_bit(var, bit_no)		var = (1<<bit_no)|var
#define CLR_bit(var, bit_no)		var = ~(1<<bit_no)&var
#define Zero		0b11000000//0
#define One			0b11111001//1
#define Two			0b10100100//2
#define Three		0b10110000//3
#define Four		0b10011001//4
#define Five		0b10010010//5
#define Six			0b10000010//6
#define Seven		0b11111000//7
#define Eight		0b10000000//8
#define Nine		0b10010000//9
void Traffic (int color, int delay);
char _7Seg_array[10]={Zero, One, Two, Three, Four, Five, Six, Seven, Eight, Nine};

int main (void)
{

	DDRA=255;
	DDRC=0xFF;
	DDRB=0b00000011;

	PORTB=0x00;

	while (1)
	{
		Traffic (1,60);
		Traffic (2,10);
		Traffic (3,60);
		Traffic (2,10);
	}

}

void Traffic (int color, int delay)
{
	if (color == 1)
	{
		PORTA=0x00;
		SET_bit(PORTA, 0);
	}
	else if (color == 2)
	{
		PORTA=0x00;
		SET_bit(PORTA, 1);
	}
	else if (color ==3)
	{
		PORTA=0x00;
		SET_bit(PORTA, 2);
	}
	else
	{
		PORTA=0x00;
	}
	int sec10=delay/10;
	int sec1=10;
	for (signed int i=sec10-1; i>=0; i--)
	{
		for (signed int j=sec1-1; j>=0; j--)
		{
			for (char z=0; z<30; z++)
			{
				SET_bit(PORTB, 0);
				PORTC=_7Seg_array[j];
				_delay_ms(10);
				CLR_bit(PORTB, 0);
				SET_bit(PORTB, 1);
				PORTC=_7Seg_array[i];
				_delay_ms(10);
				CLR_bit(PORTB, 1);
			}
		}
	}
}

/*
 * main.c
 *
 *  Created on: May 17, 2020
 *      Author: MGIsmail
 */

#include <avr/io.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
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
int _7Seg_array[10]={Zero, One, Two, Three, Four, Five, Six, Seven, Eight, Nine};
int _7Seg_loading_array_Right[4]={0b11111110, 0b11111101, 0b11111011, 0b11110111};
int _7Seg_loading_array_Left [4]={0b11110111, 0b11101111, 0b11011111, 0b11111110};
void DIO_VidCountUp_7SegViaOnePort	( u8 LOC_u8DataPort, u8 LOC_u8CTRLPort, u8 LOC_u8CTRLPinR, u8 LOC_u8CTRLPinL);
int main (void)
{
	while(1)
	{
		DIO_VidCountUp_7SegViaOnePort(PORTC, PORTB, PIN0, PIN1);
	}
return 0;
}
void DIO_VidCountUp_7SegViaOnePort	( u8 LOC_u8DataPort, u8 LOC_u8CTRLPort, u8 LOC_u8CTRLPinR, u8 LOC_u8CTRLPinL)
{

	 // set port direction as output
	/*switch (LOC_u8DataPort)
			{
				case 0: DDRA = 0xff; break;
				case 1: DDRB = 0xff; break;
				case 2: DDRC = 0xff; break;
				case 3: DDRD = 0xff; break;
			}*/
	DDRC = 0xff;
	u8 LOC_u8Intialvalue=5;
	u8 LOC_u8Endvalue=15;
	u8 LOC_u8Refresh=20;
	SET_BIT(LOC_u8CTRLPort,LOC_u8CTRLPinR); //set CTRL pins direction as output
	SET_BIT(LOC_u8CTRLPort,LOC_u8CTRLPinL);
	int L = 0;
	int R = 0;
	for (int count=LOC_u8Intialvalue; count<(LOC_u8Endvalue+1); count++)
	{
		L = count /10;
		R= count % 10;

		for (int z=0; z<LOC_u8Refresh; z++)
		{
			SET_BIT(LOC_u8CTRLPort, LOC_u8CTRLPinR);
			PORTC=_7Seg_array[R];
			_delay_ms(10);
			CLR_BIT(LOC_u8CTRLPort, LOC_u8CTRLPinR);
			SET_BIT(LOC_u8CTRLPort, LOC_u8CTRLPinL);
			PORTC=_7Seg_array[L];
			_delay_ms(10);
			CLR_BIT(LOC_u8CTRLPort, LOC_u8CTRLPinL);
		}
	}
}

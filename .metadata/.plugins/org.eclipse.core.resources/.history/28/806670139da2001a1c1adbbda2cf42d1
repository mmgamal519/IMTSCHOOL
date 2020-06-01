#include "STD_TYPES.h"
#include "DIO_Register.h"
#include "BIT_Math.h"


void DIO_VidSetPinDirection	( u8 LOC_u8Port, u8 LOC_u8Pin, u8 LOC_u8State)
{
	if ( OUTPUT==LOC_u8State)
	{
		switch (LOC_u8Port)
		{
			case 0: SET_BIT(DDRA, LOC_u8Pin); break;
			case 1: SET_BIT(DDRB, LOC_u8Pin); break;
			case 2: SET_BIT(DDRC, LOC_u8Pin); break;
			case 3: SET_BIT(DDRD, LOC_u8Pin); break;
		}
	}
	else if (INPUT==LOC_u8State)
		{
		switch (LOC_u8Port)
		{
			case 0: CLR_BIT(DDRA, LOC_u8Pin); break;
			case 1: CLR_BIT(DDRB, LOC_u8Pin); break;
			case 2: CLR_BIT(DDRC, LOC_u8Pin); break;
			case 3: CLR_BIT(DDRD, LOC_u8Pin); break;
		}
	}
}

void DIO_VidSetPinValue	( u8 LOC_u8Port, u8 LOC_u8Pin, u8 LOC_u8Value)
{
	if ( 1==LOC_u8Value)
	{
		switch (LOC_u8Port)
		{
			case 0: SET_BIT(PORTA, LOC_u8Pin); break;
			case 1: SET_BIT(PORTB, LOC_u8Pin); break;
			case 2: SET_BIT(PORTC, LOC_u8Pin); break;
			case 3: SET_BIT(PORTD, LOC_u8Pin); break;
		}
	}
	else if (0==LOC_u8Value)
		{
		switch (LOC_u8Port)
		{
			case 0: CLR_BIT(PORTA, LOC_u8Pin); break;
			case 1: CLR_BIT(PORTB, LOC_u8Pin); break;
			case 2: CLR_BIT(PORTC, LOC_u8Pin); break;
			case 3: CLR_BIT(PORTD, LOC_u8Pin); break;
		}
	}
}

/*void DIO_VidSetPortDirection( u8 LOC_u8Port, u8 LOC_u8State);

void DIO_VidSetPortValue	( u8 LOC_u8Port, u8 LOC_u8Value);

// Get Pin value from DIO_port and return u8
u8 	 DIO_u8GitPinValue		( u8 LOC_u8Port, u8 LOC_u8Pin);
*/

void DIO_VidSetPortDirection	( u8 LOC_u8Port, u8 LOC_u8State)
{
	if ( 1==LOC_u8State)
	{
		switch (LOC_u8Port)
		{
			case 0: DDRA = 0xff; break;
			case 1: DDRB = 0xff; break;
			case 2: DDRC = 0xff; break;
			case 3: DDRD = 0xff; break;
		}
	}
	else if (0==LOC_u8State)
	{
		switch (LOC_u8Port)
				{
					case 0: DDRA = 0x00; break;
					case 1: DDRB = 0x00; break;
					case 2: DDRC = 0x00; break;
					case 3: DDRD = 0x00; break;
				}
	}

}

void DIO_VidSetPortValue	( u8 LOC_u8Port, u8 LOC_u8Value)
{
	if ( 0xff==LOC_u8Value)
	{
		switch (LOC_u8Port)
		{
			case 0: PORTA = 0xff; break;
			case 1: PORTB = 0xff; break;
			case 2: PORTC = 0xff; break;
			case 3: PORTD = 0xff; break;
		}
	}
	else if (0x00==LOC_u8Value)
	{
		switch (LOC_u8Port)
		{
			case 0: PORTA = 0x00; break;
			case 1: PORTB = 0x00; break;
			case 2: PORTC = 0x00; break;
			case 3: PORTD = 0x00; break;
		}
	}
}

u8 	 DIO_u8GetPinValue	( u8 LOC_u8Port, u8 LOC_u8Pin)
{
	u8 x=0;
	switch (LOC_u8Port)
	{
		case 0: x = GET_BIT(PORTA, LOC_u8Pin); break;
		case 1: x = GET_BIT(PORTB, LOC_u8Pin); break;
		case 2: x = GET_BIT(PORTC, LOC_u8Pin); break;
		case 3: x = GET_BIT(PORTD, LOC_u8Pin); break;
	}
	return x;
}


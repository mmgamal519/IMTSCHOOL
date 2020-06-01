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

void DIO_VidSetPortDirection	( u8 LOC_u8Port, u8 LOC_u8Value)
{
	switch (LOC_u8Port)
	{
	case 0: DDRA = LOC_u8Value; break;
	case 1: DDRB = LOC_u8Value; break;
	case 2: DDRC = LOC_u8Value; break;
	case 3: DDRD = LOC_u8Value; break;
	}
}

void DIO_VidSetPortValue	( u8 LOC_u8Port, u8 LOC_u8Value)
{
	switch (LOC_u8Port)
	{
	case 0: PORTA = LOC_u8Value; break;
	case 1: PORTB = LOC_u8Value; break;
	case 2: PORTC = LOC_u8Value; break;
	case 3: PORTD = LOC_u8Value; break;
	}
}

u8 	 DIO_u8GetPinValue	( u8 LOC_u8Port, u8 LOC_u8Pin)
{
	u8 value;
	switch (LOC_u8Port)
	{
	case 0: value = GET_BIT(PINA, LOC_u8Pin); break;
	case 1: value = GET_BIT(PINB, LOC_u8Pin); break;
	case 2: value = GET_BIT(PINC, LOC_u8Pin); break;
	case 3: value = GET_BIT(PIND, LOC_u8Pin); break;
	}
	return value;
}


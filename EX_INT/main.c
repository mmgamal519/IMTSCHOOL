/*
 * main.c
 *
 *  Created on: Jun 7, 2020
 *      Author: MGIsmail
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Register.h"
#include "DIO_Interface.h"
#include "EXIT_Register.h"
#include "EXIT_Interface.h"
#include "GLOBALINT_Register.h"
#include "GLOBALINT_Interface.h"

#include <util/delay.h>

void  main (void)
{
	DIO_VidSetPinDirection(PORT_C,PIN0,OUTPUT);
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
}


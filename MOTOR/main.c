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

#include <util/delay.h>

void  main (void)
{
	DIO_VidSetPinDirection(PORT_B, PIN0,OUTPUT);
	DIO_VidSetPinDirection(PORT_B, PIN1,OUTPUT);
	_delay_ms(1000);
	while(1)
	{



				DIO_VidSetPinValue(PORT_B, PIN0,1);
				DIO_VidSetPinValue(PORT_B, PIN1,0);
				_delay_ms(3000);

				DIO_VidSetPinValue(PORT_B, PIN1,1);
				DIO_VidSetPinValue(PORT_B, PIN0,0);
				_delay_ms(3000);

/*	_delay_ms(1000);
		DIO_VidSetPinDirection(PORT_B, PIN0,1);
		DIO_VidSetPinValue(PORT_B, PIN0,1);
		_delay_ms(3000);
		DIO_VidSetPinValue(PORT_B, PIN0,0);
		_delay_ms(3000);
*/

	}

}

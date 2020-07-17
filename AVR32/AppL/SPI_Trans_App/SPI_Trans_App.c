/*
 * SPI_Trans_App.c
 *
 *  Created on: Jul 17, 2020
 *      Author: MGIsmail
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/SPI/SPI_Interface.h"
#include <util/delay.h>

void SPI_main (void)
{
	SPI_Init();
	u8 RD = 0;
	_delay_ms(500);
	DIO_VidSetPinDirection(PORT_A,PIN0,OUTPUT);
	DIO_VidSetPinValue(PORT_A,PIN0,1);
	_delay_ms(500);
	DIO_VidSetPinValue(PORT_A,PIN0,0);
	while(1)
	{
		RD = SPI_Trans(5);
		if (RD ==5)
		{
			_delay_ms(500);
			DIO_VidSetPinValue(PORT_A,PIN0,1);
			_delay_ms(500);
			DIO_VidSetPinValue(PORT_A,PIN0,0);
		}
		else
		{
			_delay_ms(500);
			DIO_VidSetPinValue(PORT_A,PIN0,1);
		}
	}
}

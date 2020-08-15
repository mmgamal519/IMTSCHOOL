/*
 * main.c
 *
 *  Created on: Jun 7, 2020
 *      Author: MGIsmail
 */

#include "MCAL/DIO/DIO_Interface.h"
#include <util/delay.h>
void WDT_ON(void);
void WDT_OFF(void);
int main(void)
{
	//UART();
	//
	//SPI_main ();
	WDT_ON();
	DIO_VidSetPinValue(PORT_A, PIN0,1);
	_delay_ms(500);
	DIO_VidSetPinValue(PORT_A, PIN0,0);
	_delay_ms(500);
	while (1)
	{

	}
	return 0;
}
#define WDTCR		*((volatile u8*)0x41)
#define WDTCR_WDTOE 				4
#define WDTCR_WDE 					3
#define WDTCR_WDP2 					2
#define WDTCR_WDP1 					1
#define WDTCR_WDP0 					0

void WDT_ON(void)
{
	WDTCR = (1<<WDTCR_WDTOE)|(1<<WDTCR_WDE)|(0x06); //110 prescaler
}
void WDT_OFF(void)
{
	WDTCR = 0x00; //110
}

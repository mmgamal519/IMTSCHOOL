/*
 * main.c
 *
 *  Created on: May 17, 2020
 *      Author: MGIsmail
 */

/*
 * main.c
 *
 *  Created on: Jun 7, 2020
 *      Author: MGIsmail
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
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
	WDT_OFF();
	DIO_VidSetPinValue(PORT_A, PIN0,0);
	_delay_ms(500);

	while (1)
	{
		DIO_VidSetPortValue(PORT_A, 0x01);
		_
		DIO_VidSetPortValue(PORT_A, 0x02);
		DIO_VidSetPortValue(PORT_A, 0x04);
		DIO_VidSetPortValue(PORT_A, 0x08);
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
	WDTCR = (1<<WDTCR_WDE)|(0x06); //110 prescaler
}
void WDT_OFF(void)
{
	WDTCR = 0xFF; //110

	WDTCR = 0x00; //110
}

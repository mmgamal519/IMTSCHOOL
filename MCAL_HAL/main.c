/*
 * main.c
 *
 *  Created on: May 30, 2020
 *      Author: MGIsmail
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Register.h"
#include "DIO_Interface.h"
#include "LED_Config.h"
#include "LED_Interface.h"
#include "SevSeg2x1_Config.h"
#include "SevSeg2x1_Register.h"
#include "SevSeg2x1_Interface.h"

#include <util/delay.h>
/*
 * main.c
 *
 *  Created on: May 15, 2020
 *      Author: MGIsmail
 */






int main (void)
{
	volatile u8* SW1 = 0;
	volatile u8* SW2 = 0;
	SevSeg2x1_VidInit();
	DIO_VidSetPinDirection(PORT_B, PIN6, INPUT); 			// SW1 as Input
	DIO_VidSetPinValue(PORT_B, PIN6, OUT_HIGH);					// SW1 enable pull up resistor
	DIO_VidSetPinDirection(PORT_B, PIN7, INPUT);			// SW2 as Input
	DIO_VidSetPinValue(PORT_B, PIN7, OUT_HIGH);					// SW2 enable pull up resistor
	DIO_VidSetPortDirection(PORT_A, 0xff);														// LED Port direction as output
	while (1)
	{

		SW1 = DIO_u8GetPinValue(PORT_B, PIN6);
		SW2 = DIO_u8GetPinValue(PORT_B, PIN7);
		_delay_ms(10);
/*
		SevSeg2x1_VidLoading(100);
		SevSeg2x1_VidCountUp(0,99);

		SevSeg2x1_VidCountDown(99,0);

		SevSeg2x1_VidLoading(100);

		LED_VidButterFly(10,100);
		*/
			if (SW1==0 && SW2==0)
		{
			SevSeg2x1_VidCountUp(0,99);
		}
		else if  ((SW1==1) && (SW2==0))
		{
			SevSeg2x1_VidCountDown(99,0);
		}
		else if  ((SW1==0) && (SW2==1))
		{
			SevSeg2x1_VidLoading(100);
		}
		else if  ((SW1==1) && (SW2==1))
		{
			LED_VidButterFly(10,100);
		}
	}
}

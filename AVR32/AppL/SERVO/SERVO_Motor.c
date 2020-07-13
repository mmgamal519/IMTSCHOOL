/*
 * SERVO_Motor.c
 *
 *  Created on: Jul 8, 2020
 *      Author: MGIsmail
 */

#include "SERVO_Interface.h"
u8 volatile flag=0;
u16 volatile Snap1=0, Snap2=0, Snap3=0;
u8 OVF=0;

void SERVO_VidInitHW(void)
{
	//	DIO_VidSetPinDirection(PORT_B, PIN3, OUT_HIGH);
		// ICP PIN PD6 as input
		//connect PB3 with PD6 wired
		// init Timer0		for PWM
		// OCR0 Timer0 == 128		/outpin =PB3
		//enable global interrupt GIE
		//Init Timer1	== normal mode
		//Enable Timer1 Input Capture ISR  and OVF INT
		//Init LCD
}
void SERVO_VidSetAngle(u16 Loc_u16Angle)
{

}

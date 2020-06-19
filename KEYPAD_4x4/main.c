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
#include "KP4x4_Config.h"
#include "KP4x4_Interface.h"
#include "SevSeg2x1_Config.h"
#include "SevSeg2x1_Register.h"
#include "SevSeg2x1_Interface.h"
#include "LCD_Register.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"
#include "LCD_CustomChar.h"

#include <util/delay.h>

void  main (void)
{


	LCD_VidInit();
	KeyPad_4x4_VidInit();

	while(1)
	{
		//	KeyPad4x4_Vid3ButtonCalcCall();
		KeyPad4x4_VidFullcalculator();
		_delay_ms (3000);
		//	KeyPad4x4_au8GetArray();
		//_delay_ms (2000);
	}

}


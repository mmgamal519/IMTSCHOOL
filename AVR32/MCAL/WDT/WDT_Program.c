/*
 * WDT_Program.c
 *
 *  Created on: Jul 28, 2020
 *      Author: MGIsmail
 */
#include "WDT_Register.h"
void WDT_ON(void)
{
	WDTCR = (1<<WDTCR_WDE)|(0x06); //110 prescaler
}
void WDT_OFF(void)
{
	WDTCR = 0xFF;
	WDTCR = 0x00;
}
void WDT_Refresh(void)
{
asm ("WDR");
}

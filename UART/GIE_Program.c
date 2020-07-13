
#include "STD_TYPES.h"
#include "GIE_Regster.h"
#include "BIT_MATH.h"

void GIE_Enable(void)

{
	SET_BIT(SREG,7);
}

void GIE_Disable(void)
{
    CLR_BIT(SREG,INT0);
}


/*
ISR(INT0_VECT)
{
	DIO_VidSitPintDirection(PORTC,PIN2, OUTPUT);
	DIO_VidSitPintDirection(PORTC,PIN2, HIGH);
	_delay_ms(2000);
	DIO_VidSitPintDirection(PORTC,PIN2, LOW);
	_delay_ms(2000);
}
*/

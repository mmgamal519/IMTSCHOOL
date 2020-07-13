#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXI_Regster.h"
#include "DIO_Register.h"
#include "DIO_Interface.h"
#include <avr/delay.h>
void EXI_Enable(void)

{
	SET_BIT(GICR,INT1);
}
void EXI_Disable(void)
{
    CLR_BIT(GICR,INT1);
}
void EXI_VidInt(void)
{
	DIO_VidSetPinDirection(PORTD,PIN3, INPUT);
	DIO_VidSetPinValue(PORTD,PIN3, 1);
	#if control_sens==falling
			CLR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
	#elif control_sens==rising
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
	#elif control_sens==io
			SET_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
	#elif control_sens==low_level
			CLR_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
	#else
		#error  "wrong choice"
	#endif

}


ISR (INT1_VECT)
{
		DIO_VidSetPinValue(PORTA,PIN0,1);
		_delay_ms(4000);
}

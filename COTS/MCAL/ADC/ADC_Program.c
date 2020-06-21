
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Register.h"
#include "DIO_Interface.h"

#include "ADC_Register.h"
#include "ADC_Interface.h"
#include <util/delay.h>


void ADC_VidInit(void)
{
	/*DIO_VidSetPinDirection(PORT_D, PIN2, INPUT);
	DIO_VidSetPinValue(PORT_D, PIN2, 1);
	//config driver pre compiler
#if Sense_Mood == Falling_Edge
	SET_BIT(MCUCR,1);
	CLR_BIT(MCUCR,0);
#elif	Sense_Mood == Rising_Edge
	SET_BIT(MCUCR,1);
	SET_BIT(MCUCR,0);
#elif	Sense_Mood == IOC
	CLR_BIT(MCUCR,1);
	SET_BIT(MCUCR,0);
#elif	Sense_Mood == Low_Level
	CLR_BIT(MCUCR,1);
	CLR_BIT(MCUCR,0);
#else
#error	"Wrong choice of sense mode"
#endif
*/
}
u16 ADC_VidGetValue(u8 LOC_u8channel)
{
	
}

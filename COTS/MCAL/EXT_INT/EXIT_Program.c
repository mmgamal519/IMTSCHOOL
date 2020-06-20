
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Register.h"
#include "DIO_Interface.h"

#include "EXIT_Register.h"
#include "EXIT_Interface.h"



void EXTINT0_VidInit(void)
{
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


}


void EXTINT0_VidEnable(void)
{
	SET_BIT(GICR,6);
}

void EXTINT0_VidDisable(void)
{
	CLR_BIT(GICR,6);
}


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO/DIO_Register.h"
#include "../DIO/DIO_Interface.h"

#include "EXIT_Register.h"
#include "EXIT_Interface.h"
#include <util/delay.h>


void EXTINT0_VidInit(void)
{
	DIO_VidSetPinDirection(PORT_D, PIN2, INPUT);
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
}
void EXTINT0_VidEnable(void)
{
	SET_BIT(GICR,6);
}
void EXTINT0_VidDisable(void)
{
	CLR_BIT(GICR,6);
}
void __vector_1(void) // ISR - Call vector table for interrupt 0
//call by hardware only so the compiler will remove it as nothing call it in code
//so we will write command to direct the compiler to keep it
{
	DIO_VidSetPinValue(PORT_C,PIN0,1);
	_delay_ms(1000);
}

// Int1
void EXTINT1_VidInit(void)
{
	DIO_VidSetPinDirection(PORT_D, PIN3, INPUT);
	DIO_VidSetPinValue(PORT_D, PIN3, 1);
	//config driver pre compiler
#if Sense_Mood == Falling_Edge
	SET_BIT(MCUCR,3);
	CLR_BIT(MCUCR,2);
#elif	Sense_Mood == Rising_Edge
	SET_BIT(MCUCR,3);
	SET_BIT(MCUCR,2);
#elif	Sense_Mood == IOC
	CLR_BIT(MCUCR,3);
	SET_BIT(MCUCR,2);
#elif	Sense_Mood == Low_Level
	CLR_BIT(MCUCR,3);
	CLR_BIT(MCUCR,2);
#else
#error	"Wrong choice of sense mode"
#endif
}
void EXTINT1_VidEnable(void)
{
	SET_BIT(GICR,7);
}
void EXTINT1_VidDisable(void)
{
	CLR_BIT(GICR,7);
}
void __vector_2(void) // ISR - Call vector table for interrupt 0
//call by hardware only so the compiler will remove it as nothing call it in code
//so we will write command to direct the compiler to keep it
{
	DIO_VidSetPinValue(PORT_C,PIN1,1);
	_delay_ms(1000);
}
// int2
void EXTINT2_VidInit(void)
{
	DIO_VidSetPinDirection(PORT_B, PIN2, INPUT);
	DIO_VidSetPinValue(PORT_B, PIN2, 1);
	//config driver pre compiler
#if Sense_Mood == Falling_Edge
	CLR_BIT(MCUCSR,1);

#elif	Sense_Mood == Rising_Edge
	SET_BIT(MCUCSR,1);


#else
#error	"Wrong choice of sense mode"
#endif
}
void EXTINT2_VidEnable(void)
{
	SET_BIT(GICR,5);
}
void EXTINT2_VidDisable(void)
{
	CLR_BIT(GICR,5);
}
void __vector_3(void) // ISR - Call vector table for interrupt 0
//call by hardware only so the compiler will remove it as nothing call it in code
//so we will write command to direct the compiler to keep it
{
	DIO_VidSetPinValue(PORT_C,PIN2,1);
	_delay_ms(1000);
}

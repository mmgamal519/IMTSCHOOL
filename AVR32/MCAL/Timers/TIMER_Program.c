
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMER_Register.h"
#include "TIMER_Config.h"
#include "TIMER_Interface.h"
#include <util/delay.h>

//Global Array Pointer to Function
static void (*TIMER_GAPF[])(void)={};
//Set Global Pointer to Function
void TIMER_SetCallBack(void(*LocalPF)(void), u8 ISR_Index) // Parameter is a *ptr_function
{
	//check pointer validation
	if (LocalPF != NULL)
	{
		TIMER_GAPF[ISR_Index] = LocalPF;
	}
}
#if TIMER0_Code_ENABLE	 == Enable
void TIMER0_VidInit(void)
{
	//Select Timer 0:2
	TCNT0=192;
	//Select Prescaler
#if Timer0_Clock_Select == Timer0_No_clock_source
	CLR_BIT(TCCR0, TCCR0_CS02);
	CLR_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS00);
#elif Timer0_Clock_Select == Timer0_clock_No_prescaling
	CLR_BIT(TCCR0, TCCR0_CS02);
	CLR_BIT(TCCR0, TCCR0_CS01);
	SET_BIT(TCCR0, TCCR0_CS00);
#elif Timer0_Clock_Select == Timer0_clock_from_prescaling8
	CLR_BIT(TCCR0, TCCR0_CS02);
	SET_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS00);
	//0 1 1 clkI/O/64 (From prescaler)
#elif Timer0_Clock_Select == Timer0_clock_from_prescaling64
	CLR_BIT(TCCR0, TCCR0_CS02);
	SET_BIT(TCCR0, TCCR0_CS01);
	SET_BIT(TCCR0, TCCR0_CS00);
	//1 0 0 clkI/O/256 (From prescaler)
#elif Timer0_Clock_Select == Timer0_clock_from_prescaling256
	SET_BIT(TCCR0, TCCR0_CS02);
	CLR_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS00);
	//1 0 1 clkI/O/1024 (From prescaler)
#elif Timer0_Clock_Select == Timer0_clock_from_prescaling1024
	SET_BIT(TCCR0, TCCR0_CS02);
	CLR_BIT(TCCR0, TCCR0_CS01);
	SET_BIT(TCCR0, TCCR0_CS00);
	//1 1 0 External clock source on T0 pin. Clock on falling edge.
#elif Timer0_Clock_Select ==  Timer0_External_clock_source_T0_FE
	SET_BIT(TCCR0, TCCR0_CS02);
	SET_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS00);
	//1 1 1 External clock source on T0 pin. Clock on rising edge.
#elif Timer0_Clock_Select == Timer0_External_clock_source_T0_RE
	SET_BIT(TCCR0, TCCR0_CS02);
	SET_BIT(TCCR0, TCCR0_CS01);
	SET_BIT(TCCR0, TCCR0_CS00);
#else
#error "Wrong Timer0_Clock_Select"
#endif //Timer0_Clock_Select
	//Enable Timer Interrupt
	SET_BIT(TIMSK, TIMSK_TOIE0);
	//Select Mode (Normal overflow, CTC)
#if Timer0_Waveform_Generation_Mode == Timer0_Normal_Overflow
	CLR_BIT(TCCR0, TCCR0_WGM01);
	CLR_BIT(TCCR0, TCCR0_WGM00);
#elif Timer0_Waveform_Generation_Mode == Timer0_PWM_Phase_Correct
	CLR_BIT(TCCR0, TCCR0_WGM01);
	SET_BIT(TCCR0, TCCR0_WGM00);
#elif Timer0_Waveform_Generation_Mode == Timer0_CTC
	SET_BIT(TCCR0, TCCR0_WGM01);
	CLR_BIT(TCCR0, TCCR0_WGM00);
#elif Timer0_Waveform_Generation_Mode == Timer0_Fast_PWM
	SET_BIT(TCCR0, TCCR0_WGM01);
	SET_BIT(TCCR0, TCCR0_WGM00);
#else
#error "Wrong Timer0_Waveform_Generation_Mode"
#endif //Timer0_Waveform_Generation_Mode
	//Table 39. Compare Output Mode, non-PWM Mode
	//mode Clear OC0 on compare match
#if Timer0_Compare_Output_Mode_non_PWM == Timer0_NonPWM_Normal_port_operation
	CLR_BIT(TCCR0, TCCR0_COM01);
	CLR_BIT(TCCR0, TCCR0_COM00);
#elif Timer0_Compare_Output_Mode_non_PWM == Timer0_NonPWM_Toggle_OC0
	CLR_BIT(TCCR0, TCCR0_COM01);
	SET_BIT(TCCR0, TCCR0_COM00);
#elif Timer0_Compare_Output_Mode_non_PWM == Timer0_NonPWM_Clear_OC0
	SET_BIT(TCCR0, TCCR0_COM01);
	CLR_BIT(TCCR0, TCCR0_COM00);
#elif Timer0_Compare_Output_Mode_non_PWM == Timer0_NonPWM_Set_OC0
	SET_BIT(TCCR0, TCCR0_COM01);
	SET_BIT(TCCR0, TCCR0_COM00);
#else
#error "Wrong selection of Timer0_Compare_Output_Mode_non_PWM"
#endif //Timer0_Compare_Output_Mode_non_PWM

	//ISR for Selected Mode

	//Table 40. Compare Output Mode, Fast PWM Mode(1)

}
void TIMER_VidStart(void)
{

}
void TIMER_VidStop(void)
{

}
u8 TIMER_VidOCR(void)
{

	return OCR0;
}
void Set_Duty_Cycle(u8 Vrms)
{

	OCR0 = (255 * (Vrms^2)) / 25;
}
#else
#endif // TIMER0_Code_ENABLE
#if TIMER1_Code_ENABLE	 == Enable
//Timer1 program Code
void TIMER_VidInit(void)
{

}
#else
#endif // TIMER1_Code_ENABLE
#if TIMER2_Code_ENABLE	 == Enable
//Timer2 program Code
#else
#endif // TIMER2_Code_ENABLE

//======================TIMERS ALL ISR =====================================

void __vector_4 (void)	//
{
	//check pointer validation
	if (TIMER_GAPF != NULL)
	{
		(TIMER_GAPF[0])();
	}
}
void __vector_5 (void)	//
{
	//check pointer validation
	if (TIMER_GAPF != NULL)
	{
		(TIMER_GAPF[1])();
	}
}
void __vector_6 (void)	//
{
	//check pointer validation
	if (TIMER_GAPF != NULL)
	{
		TIMER_GAPF[2]();
	}
}
void __vector_7 (void)	//
{
	//check pointer validation
	if (TIMER_GAPF != NULL)
	{
		TIMER_GAPF[3]();
	}
}
void __vector_8 (void)	//
{
	//check pointer validation
	if (TIMER_GAPF != NULL)
	{
		TIMER_GAPF[4]();
	}
}
void __vector_9 (void)	//
{
	//check pointer validation
	if (TIMER_GAPF != NULL)
	{
		TIMER_GAPF[5]();
	}
}


void __vector_10 (void)	//ISR 10 for 11 $014 TIMER0 COMP Timer/Counter0 Compare Match //Interrupt Vectors in ATmega32 Datasheet Page. 42//
{
	//check pointer validation
	if (TIMER_GAPF != NULL)
	{
		TIMER_GAPF[6]();
	}
}
void __vector_11 (void)	//ISR 11 for 12 $016 TIMER0 OVF Timer/Counter0 Overflow //Interrupt Vectors in ATmega32 Datasheet Page. 42//
{
	//check pointer validation
	if (TIMER_GAPF != NULL)
	{
		TIMER_GAPF[7]();
	}
}

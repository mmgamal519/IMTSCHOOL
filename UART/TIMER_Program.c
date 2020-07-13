
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER_Regster.h"
#include "EXI_Regster.h"
#include "DIO_Interface.h"

static void  (*CallBackFuncPtr)(void)= NULL;
//static void  (*CallBackFuncPtr_TIMER1)(void)= NULL;

void  TIMER_VidSetCallBack (void (*LOC_funcptr)(void) )
{
	if(LOC_funcptr  != NULL )
	{
		CallBackFuncPtr = LOC_funcptr ;
	}
}
/*
void  TIMER_1_VidSetCallBack (void (*LOC_funcptr_1)(void) )
{
	if(LOC_funcptr_1  != NULL )
	{
		CallBackFuncPtr = LOC_funcptr_1 ;
	}
}
*/
void TIMER_VidEnable(void)
{
	//SELECT MODE
#if	type_of__mode== Normal_mode
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
#elif type_of__mode== PWM_Phasw_correct_Mode
	SET_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
#elif type_of__mode== CTC_Mode
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
#elif type_of__mode== Fast_PWM_Mode
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
#else
	#error  "wrong choice"
#endif


	//SELECT OUTPUT MODE
#if	comper_mode== Compare_Output_Mode_1
	CLR_BIT(TCCR0,COM00);
	CLR_BIT(TCCR0,COM01);
#elif comper_mode== Compare_Output_Mode_2
	SET_BIT(TCCR0,COM00);
	CLR_BIT(TCCR0,COM01);
#elif comper_mode== Compare_Output_Mode_3
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
#elif comper_mode== Compare_Output_Mode_4
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
#else
	#error  "wrong choice"
#endif

	//CLOCK SELECT PRESCALER
#if	prescaler_mode== prescaler_0
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
#elif prescaler_mode== prescaler_8
		CLR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
#elif prescaler_mode== prescaler_64
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
#elif prescaler_mode== prescaler_256
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
#elif prescaler_mode== prescaler_1024
		SET_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
#else
	#error  "wrong choice"
#endif

	//ENABLE INTRRUPT OVERFLOW
#if	interrupt_overflow_enabled== enable
		SET_BIT(TIMSK,TOIEO);
#elif interrupt_overflow_enabled== disable
		CLR_BIT(TIMSK,TOIEO);
#else
	#error  "wrong choice"
#endif

	//OCR CTC MODE
#if	interrupt_Compare_Match_enabled== enable
		SET_BIT(TIMSK,OCIE0);
#elif interrupt_Compare_Match_enabled== disable   //OCR CTC MODE
		CLR_BIT(TIMSK,OCIE0);
#else
	#error  "wrong choice"
#endif

}
void TIMER_1_VidEnable(void)
{

		//NON INVERTER MODE
		CLR_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
#if  timer_1_mode== Normal_timer_1
		//overflow MODE
		CLR_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		CLR_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
#elif timer_1_mode== Fast_PWM_timer_1
		CLR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
	    SET_BIT(TCCR1B,WGM13);
#else
             #error  "wrong mode timer_1 choice"
#endif
	    //prescaler 156
	    CLR_BIT(TCCR1B,CS10);
		CLR_BIT(TCCR1B,CS11);
	    SET_BIT(TCCR1B,CS12);
		//intrrupt enable
		SET_BIT(TIMSK,TOIE1);
}

void TIMER_1_INPUT_CAPUER_VidEnable(void)
{

		//Input Capture Edge Select
	    SET_BIT(TCCR1B,ICES1);
	    //ENABLE INPUT CAPUTER INTRRUPT
	   SET_BIT(TIMSK,TICIE1);
}

void Tim1_Count0_ICR1(u16 Loc_u8TCNTvalue)
{
	ICR1=Loc_u8TCNTvalue;
}
void Tim1_Count0_OCR1A(u16 Loc_u8OCRvalue)
{
	OCR1A=Loc_u8OCRvalue;
}

void Tim_Count0_VidCounterReg(u8 Loc_u8TCNTvalue)
{
	TCNT0=Loc_u8TCNTvalue;
}
void Tim_Count0_VidCompareReg(u8 Loc_u8OCRvalue)
{
	OCR0=Loc_u8OCRvalue;
}
void Set_Duty_cycle(u8 Loc_u8OCRvalue)
{
	OCR0=Loc_u8OCRvalue;
}

u16 u16_return_ICR1(void)
{
	return ICR1;
}

void u8_TOGAL_ICES1(void)
{
	TOG_BIT(TCCR1B,ICES1);
}

//isr
ISR(TIMER_CTC_VECT)
{
	if(CallBackFuncPtr != NULL )
	{
		CallBackFuncPtr();
	}
 }
/*
ISR(TIMER_1_CAPT_VECT)
{
	if(CallBackFuncPtr_TIMER1 != NULL )
	{
		CallBackFuncPtr_TIMER1();
	}
 }*/

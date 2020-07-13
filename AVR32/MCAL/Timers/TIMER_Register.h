#ifndef _TIMER_REGISTER_H_
#define _TIMER_REGISTER_H_

//------------------AVR ATmega32------------------------

//-------------------------Timer/Counter Register ----------------
#define TIMSK		*((volatile u8*)0x59)  //Timer/Counter Interrupt Mask Register – OCIE2 TOIE2 TICIE1 OCIE1A OCIE1B TOIE1 OCIE0 TOIE0
#define TIFR			*((volatile u8*)0x58)  //Timer/Counter Interrupt Flag Register – OCF2 TOV2 ICF1 OCF1A OCF1B TOV1 OCF0 TOV0

//---------------------Timer 0---------------------------------
//(OC0/AIN1) PB3	PIN
#define TCCR0		*((volatile u8*)0x53)  	//Timer/Counter Control Register – FOC0 WGM00 COM01 COM00 WGM01 CS02 CS01 CS00
#define TCNT0		*((volatile u8*)0x52)  	//Timer/Counter Register – TCNT0[7:0]
#define OCR0		*((volatile u8*)0x5C)  	//Output Compare Register – OCR0[7:0] for preload in CTC mode
//---------------------Timer 1---------------------------------
//(OC1A) PD5 PIN
#define TCCR1A		*((volatile u8*)0x4F)
#define OCR1AL		*((volatile u8*)0x4A)			//Timer/Counter1 – Output Compare Register A Low Byte
#define OCR1AH		*((volatile u8*)0x4B)			//Timer/Counter1 – Output Compare Register A High Byte
#define OCR1A		*((volatile u16*)0x4A) 		//user defined  for preload in CTC mode
//#define TCNT1H		*((volatile u8*)0x4D)			//Timer/Counter1 – Counter Register High Byte
//#define TCNT1L		*((volatile u8*)0x4C)			//Timer/Counter1 – Counter Register Low Byte
//#define TCNT1			*((volatile u16*)0x4C) 		//user defined
//(OC1B) PD4 PIN
#define TCCR1B		*((volatile u8*)0x4E)
#define OCR1BL		*((volatile u8*)0x48)			//Timer/Counter1 – Output Compare Register B Low Byte
#define OCR1BH		*((volatile u8*)0x49)			//Timer/Counter1 – Output Compare Register B High Byte
#define OCR1B			*((volatile u16*)0x48) 		//user defined  for preload in CTC mode
//---------------------Timer 2---------------------------------
//(OC2) PD7	PIN
#define TCCR2		*((volatile u8*)0x45)		//Timer/Counter Control Register – FOC2 WGM20 COM21 COM20 WGM21 CS22 CS21 CS20
#define TCNT2		*((volatile u8*)0x44)  	//Timer/Counter Register – TCNT2[7:0]
#define OCR2		*((volatile u8*)0x43)  	//Output Compare Register – OCR2[7:0]	 for preload in CTC mode
// ------------------------------TIMERS ISR Vector Declaration------------------------------------------
void __vector_4(void)  __attribute__((signal));	//5 $008 TIMER2 COMP Timer/Counter2 Compare Match
void __vector_5(void)  __attribute__((signal));	//6 $00A TIMER2 OVF Timer/Counter2 Overflow
void __vector_6(void)  __attribute__((signal));	//7 $00C TIMER1 CAPT Timer/Counter1 Capture Event
void __vector_7(void)  __attribute__((signal));	//8 $00E TIMER1 COMPA Timer/Counter1 Compare Match A
void __vector_8(void)  __attribute__((signal));	//9 $010 TIMER1 COMPB Timer/Counter1 Compare Match B
void __vector_9(void)  __attribute__((signal));	//10 $012 TIMER1 OVF Timer/Counter1 Overflow
void __vector_10(void)  __attribute__((signal));	//11 $014 TIMER0 COMP Timer/Counter0 Compare Match    -  CTC
void __vector_11(void)  __attribute__((signal));	//12 $016 TIMER0 OVF Timer/Counter0 Overflow					-	Normal

#endif 	//_TIMER_REGISTER_H_ //

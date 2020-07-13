#ifndef _TIMER_INTERFACE_H_
#define _TIMER_INTERFACE_H_

//------------------AVR ATmega32------------------------
#if TIMER0_Code_ENABLE	 == Enable
//-------------------------Timer/Counter Control Register – TCCR0---------------
#define TCCR0_FOC0			7			//Bit 7 – FOC0: Force Output Compare
#define TCCR0_WGM00		6			//Bit 6, 3 – WGM01:0: Waveform Generation Mode
#define TCCR0_COM01		5			//Bit 5:4 – COM01:0: Compare Match Output Mode
#define TCCR0_COM00		4			//Bit 5:4 – COM01:0: Compare Match Output Mode
#define TCCR0_WGM01		3			//Bit 6, 3 – WGM01:0: Waveform Generation Mode
#define TCCR0_CS02			2			//Bit 2:0 – CS02:0: Clock Select
#define TCCR0_CS01			1			//Bit 2:0 – CS02:0: Clock Select
#define TCCR0_CS00			0			//Bit 2:0 – CS02:0: Clock Select
//#define TCNT0		*((volatile u8*)0x )  //Timer/Counter Register – TCNT0[7:0]
//#define OCR0		*((volatile u8*)0x )  //Output Compare Register – OCR0[7:0]
//Timer/Counter Interrupt Flag Register – TIFR
#define TIFR_OCF0 			1
#define TIFR_TOV0			0
//------------------------------------------
//TOIE0 (Timer/Counter0 Overflow Interrupt Enable)
#define TIMSK_OCIE0 			1 		// Timer/Counter0 Output Compare Match Interrupt Enable
#define TIMSK_TOIE0 			0		//Timer/Counter0 Overflow Interrupt Enable
#else
#endif // TIMER0_Code_ENABLE
#if TIMER1_Code_ENABLE	 == Enable
//---------Timer/Counter1 Control Register A – TCCR1A --------------
#define TCCR1A_COM1A1		7	//Compare Output Mode for Channel A
#define TCCR1A_COM1A0 		6	//Compare Output Mode for Channel A
#define TCCR1A_COM1B1 		5	//Compare Output Mode for Channel B
#define TCCR1A_COM1B0 		4	//Compare Output Mode for Channel B
#define TCCR1A_FOC1A 			3	//Force Output Compare for Channel A used by manufacturer (Not Used)
#define TCCR1A_FOC1B 			2	//Force Output Compare for Channel A used by manufacturer (Not Used)
#define TCCR1A_WGM11			1	//Waveform Generation Mode
#define TCCR1A_WGM10			0	//Waveform Generation Mode
#else
#endif // TIMER1_Code_ENABLE

#if TIMER2_Code_ENABLE	 == Enable
#define SFIOR_PSR2				1
//-------------------------Timer/Counter Control Register – TCCR0---------------
#define TCCR2_FOC2			7			//Bit 7 – FOC0: Force Output Compare
#define TCCR2_WGM20		6			//Bit 6, 3 – WGM21:0: Waveform Generation Mode
#define TCCR2_COM21		5			//Bit 5:4 – COM21:0: Compare Match Output Mode
#define TCCR2_COM20		4			//Bit 5:4 – COM21:0: Compare Match Output Mode
#define TCCR2_WGM01		3			//Bit 6, 3 – WGM21:0: Waveform Generation Mode
#define TCCR2_CS22			2			//Bit 2:0 – CS22:0: Clock Select
#define TCCR2_CS21			1			//Bit 2:0 – CS22:0: Clock Select
#define TCCR2_CS20			0			//Bit 2:0 – CS22:0: Clock Select
//#define TCNT2		*((volatile u8*)0x )  //Timer/Counter Register – TCNT2[7:0]
//#define OCR2			*((volatile u8*)0x )  //Output Compare Register – OCR2[7:0]
//Timer/Counter Interrupt Flag Register – TIFR
#define TIFR_OCF0 			1
#define TIFR_TOV0			0
//------------------------------------------
//TOIE0 (Timer/Counter0 Overflow Interrupt Enable)
#define TIMSK_OCIE0 			1 		// Timer/Counter0 Output Compare Match Interrupt Enable
#define TIMSK_TOIE0 			0		//Timer/Counter0 Overflow Interrupt Enable
#else
#endif // TIMER2_Code_ENABLE


//Functions declaration
void TIMER_SetCallBack(void(*LocalPF)(void), u8 ISR_Index);
void TIMER_VidInit(void);
void TIMER_VidStart(void);
void TIMER_VidStop(void);
u8 TIMER_VidOCR(void);
void Set_Duty_Cycle(u8 Value);


#endif

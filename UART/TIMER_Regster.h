

#ifndef COTS_MCAL_TIMER_TIMER_REGSTER_H_
#define COTS_MCAL_TIMER_TIMER_REGSTER_H_

//timer_1
#define COM1A1 7
#define COM1A0 6
#define TICIE1   5
#define WGM10 0
#define WGM11 1
#define WGM12 3
#define WGM13 4
#define ICES1     6
#define OCIE1A  4
#define TOIE1 2
#define Normal_timer_1           0
#define  Fast_PWM_timer_1     1
#define timer_1_mode  Normal_timer_1

//prescaler timer_1
#define CS10 0
#define CS11 1
#define CS12 2


//timer_0
//#define INT0  7
//select mode
#define Normal_mode         						      0              //Normal_mode
#define PWM_Phasw_correct_Mode              1             //PWM_Phasw_correct_Mode
#define CTC_Mode        								      2           //CTC_Mode
#define Fast_PWM_Mode					              3          //Fast_PWM_Mode


#define type_of__mode  Fast_PWM_Mode
//type of mode pin
#define WGM00 6
#define WGM01 3


//Compare Output Mode, non-PWM Mode
#define COM00 4
#define COM01 5
#define Compare_Output_Mode_1    1
#define Compare_Output_Mode_2    2
#define Compare_Output_Mode_3    3
#define Compare_Output_Mode_4    4
#define comper_mode    Compare_Output_Mode_3
//CLOCK SELECT PRESCALER
#define prescaler_0         0              //No prescaler
#define prescaler_8         8             //8 prescaler
#define prescaler_64       64           //64 prescaler
#define prescaler_256     256        //256 prescaler
#define prescaler_1024   1024      //1024 prescaler

#define prescaler_mode  prescaler_1024
//PRESCALER pins
#define CS00 0
#define CS01 1
#define CS02 2


//interrupt is enabled
#define  Compare_Match   0
#define  Overflow                1
#define  enable  1
#define  disable  0
#define  interrupt_overflow_enabled                        disable      //OVER FLOW MODE
#define  interrupt_Compare_Match_enabled          disable      //OCR CTC MOD
//pins of intrrupts

#define TOIEO  0
#define OCIE0  1


//regster TIMER 0
#define TCCR0 *((volatile unsigned char *)0x53)

#define TCNT0 *((volatile unsigned char *)0x52)

#define TIMSK  *((volatile unsigned char *)0x59)

#define TIFR  *((volatile unsigned char *)0x58)

#define SFIOR  *((volatile unsigned char *)0x50)

#define OCR0  *((volatile unsigned char *)0x5C)
//regster TIMER 1
#define TCCR1A *((volatile unsigned char *)0x4F)

#define TCCR1B *((volatile unsigned char *)0x4E)

#define ICR1L  *((volatile unsigned char *)0x46)

#define ICR1H  *((volatile unsigned char *)0x47)

#define ICR1  *((volatile u16 *)0x46)

#define OCR1AL  *((volatile unsigned char *)0x4A)

#define OCR1AH  *((volatile unsigned char *)0x4B)

#define OCR1A  *((volatile u16 *)0x4A)

#define OCR1BL  *((volatile unsigned char *)0x48)

#define OCR1BH  *((volatile unsigned char *)0x49)

#define OCR1B  *((volatile u16 *)0x48)

#define TCNT1  *((volatile u16 *)0x4C)

#endif /* COTS_MCAL_TIMER_TIMER_REGSTER_H_*/

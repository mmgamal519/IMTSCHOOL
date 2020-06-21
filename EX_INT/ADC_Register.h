#ifndef _ADC_REGISTER_H_
#define _ADC_REGISTER_H_


#define ADCSRA		*((volatile u8*)0x26)  //Page 299 AVR datasheet
#define ADMUX		*((volatile u8*)0x27)	// volatile to avoid program to cash
#define ADCH			*((volatile u8*)0x25)
#define ADCL			*((volatile u8*)0x24)
#define ADC10			*((volatile u16*)0x24)  // 16 bit to contain both ADCL-ADCH

#endif

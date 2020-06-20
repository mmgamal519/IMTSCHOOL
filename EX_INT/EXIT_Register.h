#ifndef _EXIT_REGISTER_H_
#define _EXIT_REGISTER_H_


#define MCUCSR		*((volatile u8*)0x54)  //Page 299 AVR datasheet
#define MCUCR		*((volatile u8*)0x55)	// volatile to avoid program to cash
#define GIFR		*((volatile u8*)0x5A) 	
#define GICR		*((volatile u8*)0x5B)	

void __vector_1(void)  __attribute__((signal));  //signal or used , used mean it will be used but signal mean it will be called by hardware
void __vector_2(void)  __attribute__((signal));
void __vector_3(void)  __attribute__((signal));

#endif

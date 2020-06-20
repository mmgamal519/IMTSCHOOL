#ifndef _EXIT_REGISTER_H_
#define _EXIT_REGISTER_H_


#define MCUCSR		*((volatile u8*)0x54)  //Page 299 AVR datasheet
#define MCUCR		*((volatile u8*)0x55)	// volatileto avoid program to cash
#define GIFR		*((volatile u8*)0x5A) 	
#define GICR		*((volatile u8*)0x5B)	


#endif

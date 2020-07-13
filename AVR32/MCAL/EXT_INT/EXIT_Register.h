#ifndef _EXIT_REGISTER_H_
#define _EXIT_REGISTER_H_

// volatile to avoid program to cash
#define MCUCSR		*((volatile u8*)0x54)  //MCU Control and Status Register – JTD ISC2 – JTRF WDRF BORF EXTRF PORF
#define MCUCR		*((volatile u8*)0x55)	//MCU Control Register – SE SM2 SM1 SM0 ISC11 ISC10 ISC01 ISC00
#define GIFR		*((volatile u8*)0x5A) 	  // General Interrupt Flag Register – INTF1 INTF0 INTF2 – – – – –
#define GICR		*((volatile u8*)0x5B)	//General Interrupt Control Register – INT1 INT0 INT2 – – – IVSEL IVCE

//signal or used , used mean it will be used but signal mean it will be called by hardware
//Interrupt Vectors in ATmega32 Datasheet Page. 42
void __vector_1(void)  __attribute__((signal));
void __vector_2(void)  __attribute__((signal));
void __vector_3(void)  __attribute__((signal));

#endif

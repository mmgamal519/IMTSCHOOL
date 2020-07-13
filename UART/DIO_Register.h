#ifndef _DIO_REGISTER_H_ //Guard
#define _DIO_REGISTER_H_

//FROM DATASHEET PAGE 299 
//USING ADRESSES OF MEMORY MAPPED NOT PORT MAPPED
//$1B ($3B) PORTA
#define PORTA_1		*((volatile u8*)0x3B)
#define DDRA		*((volatile u8*)0x3A)
#define PINA		*((volatile u8*)0x39)

#define PORTB_1		*((volatile u8*)0x38)
#define DDRB  		*((volatile u8*)0x37)
#define PINB  		*((volatile u8*)0x36)

#define PORTC_1  		*((volatile u8*)0x35)
#define DDRC  		*((volatile u8*)0x34)
#define PINC  		*((volatile u8*)0x33)

#define PORTD_1  		*((volatile u8*)0x32)
#define DDRD  		*((volatile u8*)0x31)
#define PIND  		*((volatile u8*)0x30)

#define OUTPUT 1
#define INPUT  0

#endif

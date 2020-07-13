// #define guard
#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

//avoid magic numbers
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define OUTPUT 1
#define INPUT  0
#define OUT_HIGH 1
#define OUT_LOW 0

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

//prototype of functions
// avoid magic numbers in declaration
//use standard naming convention even for arguments

void DIO_VidSetPinDirection	( u8 LOC_u8Port, u8 LOC_u8Pin, u8 LOC_u8State);
// function return void to set pin value
void DIO_VidSetPinValue	( u8 LOC_u8Port, u8 LOC_u8Pin, u8 LOC_u8Value);

void DIO_VidSetPortDirection( u8 LOC_u8Port, u8 LOC_u8State);

void DIO_VidSetPortValue	( u8 LOC_u8Port, u8 LOC_u8Value);

void DIO_VidToggPinValue( u8 LOC_u8Port, u8 LOC_u8Pin, u8 LOC_u8Value);

// Get Pin value from DIO_port and return u8 
u8 	 DIO_u8GetPinValue		( u8 LOC_u8Port, u8 LOC_u8Pin);










#endif

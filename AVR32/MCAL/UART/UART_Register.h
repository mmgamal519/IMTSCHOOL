/*
 * UART_Register.h
 *
 *  Created on: Jul 11, 2020
 *      Author: MGIsmail
 */

#ifndef MCAL_UART_UART_REGISTER_H_
#define MCAL_UART_UART_REGISTER_H_

#define UBRRH		*((volatile u8*)0x40)
#define UBRRL			*((volatile u8*)0x29)	//USART Baud Rate Register Low Byte
#define UDR			*((volatile u8*)0x2C)
#define UCSRA			*((volatile u8*)0x2B)
#define UCSRB			*((volatile u8*)0x2A)
#define UCSRC			*((volatile u8*)0x40)

#endif /* MCAL_UART_UART_REGISTER_H_ */

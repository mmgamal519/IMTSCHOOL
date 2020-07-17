/*
 * UART_Interface.h
 *
 *  Created on: Jul 11, 2020
 *      Author: MGIsmail
 */

#ifndef MCAL_USART_UART_INTERFACE_H_
#define MCAL_USART_UART_INTERFACE_H_



void USART_Init( u16 Loc_u16BaudRate );
void USART_Tx_Enable(void);
void USART_Rx_Enable(void);
void USART_Rx_INT_Enable(void);
void USART_Tx_Disable(void);
void USART_Rx_Disable(void);
void USART_Transmit( u16 data );
u16 USART_Receive( void );
u16 UART_u16BaudRate(void);
void USART_SetCallBack(void(*LocalPF)(void), u8 ISR_Index);

#endif /* MCAL_USART_UART_INTERFACE_H_ */

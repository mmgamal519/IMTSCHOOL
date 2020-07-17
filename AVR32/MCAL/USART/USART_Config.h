/*
 * UART_Config.h
 *
 *  Created on: Jul 11, 2020
 *      Author: MGIsmail
 */

#ifndef MCAL_USART_USART_CONFIG_H_
#define MCAL_USART_USART_CONFIG_H_


#define Baud_Rate_default			9600			//9600 bps -> u16 UBRR = 51
#define Baud_Rate						9600			//9600 bps
#define Crystal_CLK						8000000	//8MHz
#define Double_Speed					0				//U2X =0 for Normal  or 1 for Double rate
#define Enable_TxRx_Init				1				// enable at initialization
//-------------------
#define Frame_Size_5to8bits			0
#define Frame_Size_9bits				1
#define Frame_Size 						Frame_Size_5to8bits
//-------------------
#define Asynchronous					0
#define Synchronous					1
#define USART_Mode  					Asynchronous
//-------------------
#define ISR_USART_RxC				0
#define ISR_USART_UDRE 			1
#define ISR_USART_TxC				2
//-------------------
#define Parity_Mode_Disabled		0
#define Parity_Mode_Reserved		1
#define Parity_Mode_Even			2
#define Parity_Mode_Odd			3
#define Parity_Mode					Parity_Mode_Disabled
//-------------------
#define One_Stop_bit					0
#define Two_Stop_bits					1
#define Stop_Bit_Setting 				One_Stop_bit
//-------------------
#define Frame_Data_5bits				0
#define Frame_Data_6bits				1
#define Frame_Data_7bits				2
#define Frame_Data_8bits				3
#define Frame_Data_9bits				4
#define Frame_Data_bits				 Frame_Data_8bits
//-------------------
#endif /* MCAL_USART_USART_CONFIG_H_ */

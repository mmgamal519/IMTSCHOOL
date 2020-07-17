/*
 * UART_Program.c
 *
 *  Created on: Jul 11, 2020
 *      Author: MGIsmail
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../USART/USART_Interface.h"
#include "USART_Register.h"
#include "USART_Config.h"

void USART_Init( u16 Loc_u16BaudRate )
{
	u8 Loc_u8UCSRC=0;
	u16 UBRR=0;
	if (Loc_u16BaudRate == 0)
		UBRR= (u16)((Crystal_CLK / (16 * (u32) Baud_Rate_default))-1);
	else
		UBRR= (Crystal_CLK / (16 * (u32)Loc_u16BaudRate))-1;
	// Set baud rate
	CLR_BIT(UBRRH,UBRRH_URSEL); // to Select UBRRH register
	UBRRH =(u8)(UBRR>>8);
	UBRRL = (u8)UBRR;
	//transmission speed, not double
	CLR_BIT(UCSRA,UCSRA_U2X);
	//asynchronous operation using polling (no interrupts enabled)
#if USART_Mode == Asynchronous
	CLR_BIT(Loc_u8UCSRC, UCSRC_UMSEL);
#elif USART_Mode == Synchronous
	SET_BIT(UCSRC, UCSRC_UMSEL);
#else
#error "Wrong USART Mode (Synchronous / Asynchronous)"
#endif
#if Parity_Mode	 ==  Parity_Mode_Disabled
	CLR_BIT(Loc_u8UCSRC,UCSRC_UPM1);
	CLR_BIT(Loc_u8UCSRC,UCSRC_UPM0);
#elif Parity_Mode	 ==  Parity_Mode_Reserved
	CLR_BIT(Loc_u8UCSRC,UCSRC_UPM1);
	SET_BIT(Loc_u8UCSRC,UCSRC_UPM0);
#elif Parity_Mode	 ==  Parity_Mode_Even
	SET_BIT(Loc_u8UCSRC,UCSRC_UPM1);
	CLR_BIT(Loc_u8UCSRC,UCSRC_UPM0);
#elif Parity_Mode	 ==  Parity_Mode_Odd
	SET_BIT(Loc_u8UCSRC,UCSRC_UPM1);
	SET_BIT(Loc_u8UCSRC,UCSRC_UPM0);
#else
#error "Wrong Parity Mode"
#endif
	//Stop Bit
#if Stop_Bit_Setting == One_Stop_bit
	CLR_BIT(Loc_u8UCSRC,UCSRC_USBS);
#elif Stop_Bit_Setting == Two_Stop_bits
	SET_BIT(Loc_u8UCSRC,UCSRC_USBS);
#else
#error "Wrong Stop Bit Setting"
#endif
	// Set frame format: 8data, 1stop bit
	//UCSRC = (1<<UCSRC_URSEL)|(1<<UCSRC_USBS)|(3<<UCSRC_UCSZ0);
#if 	Frame_Data_bits	== Frame_Data_5bits
	CLR_BIT(Loc_u8UCSRC,UCSRC_UCSZ1);
	CLR_BIT(Loc_u8UCSRC,UCSRC_UCSZ0);
#elif Frame_Data_bits	== Frame_Data_6bits
	CLR_BIT(Loc_u8UCSRC,UCSRC_UCSZ1);
	SET_BIT(Loc_u8UCSRC,UCSRC_UCSZ0);
#elif Frame_Data_bits	== Frame_Data_7bits
	SET_BIT(Loc_u8UCSRC,UCSRC_UCSZ1);
	CLR_BIT(Loc_u8UCSRC,UCSRC_UCSZ0);
#elif Frame_Data_bits	== Frame_Data_8bits
	SET_BIT(Loc_u8UCSRC,UCSRC_UCSZ1);
	SET_BIT(Loc_u8UCSRC,UCSRC_UCSZ0);
#elif Frame_Data_bits	== Frame_Data_9bits
	SET_BIT(UCSRB,UCSRB_UCSZ2);
	SET_BIT(Loc_u8UCSRC,UCSRC_UCSZ1);
	SET_BIT(Loc_u8UCSRC,UCSRC_UCSZ0);
#else
#error "Wrong Frame_Data number of bits Setting"
#endif
	SET_BIT(Loc_u8UCSRC,UCSRC_URSEL); // to Select UCSRC register
	//More advanced initialization
	//frame format as parameters
	//Enable or disable interrupts
	//Asynchronous mode / Falling XCK Edge with Synchronous mode
	//	CLR_BIT(UCSRC, UCSRC_UCPOL);
	//Write all settings to UCSRC register
	UCSRC=Loc_u8UCSRC;

#if Enable_TxRx_Init	== 1
	// Enable receiver and transmitter
	//UCSRB = (1<<UCSRB_RXEN)|(1<<UCSRB_TXEN);
	SET_BIT(UCSRB,UCSRB_RXEN);
	SET_BIT(UCSRB,UCSRB_TXEN);
#endif

}
void USART_Tx_Enable(void)
{
	SET_BIT(UCSRB,UCSRB_TXEN);
}
void USART_Rx_Enable(void)
{
	SET_BIT(UCSRB,UCSRB_RXEN);
}
void USART_Tx_Disable(void)
{
	CLR_BIT(UCSRB,UCSRB_TXEN);
}
void USART_Rx_INT_Enable(void)
{
	SET_BIT(UCSRB,UCSRB_RXEN);
	SET_BIT(UCSRB,UCSRB_RXCIE);
}

void USART_Rx_Disable(void)
{
	CLR_BIT(UCSRB,UCSRB_RXEN);
}
void USART_Transmit( u16 data )
{
#if Frame_Size == Frame_Size_5to8bits
	/* Wait for empty transmit buffer */
	while ( !GET_BIT( UCSRA, UCSRA_UDRE)) ;
	/* Put data into buffer, sends the data */
	UDR = (u8)data;
#elif Frame_Size == Frame_Size_9bits
	/* Wait for empty transmit buffer */
	while ( !GET_BIT( UCSRA, UCSRA_UDRE)) ;
	/* Copy 9th bit to TXB8 */
	CLR_BIT(UCSRB,UCSRB_TXB8);
	if ( data & 0x0100 )
		SET_BIT(UCSRB, UCSRB_TXB8);
	/* Put data into buffer, sends the data */
	UDR = data;
#else
#error "Wrong Selection of Frame_Data_Size"
#endif
}
u16 USART_Receive( void )
{
#if Frame_Size == Frame_Size_5to8bits
	/* Wait for data to be received */
	while ( !GET_BIT(UCSRA,UCSRA_RXC));
	/* Get and return received data from buffer */
	/* If error, return -1 */
	if ( GET_BIT(UCSRA, UCSRA_FE) | GET_BIT(UCSRA, UCSRA_DOR) | GET_BIT(UCSRA, UCSRA_PE) )
		return -1;
	else
		return UDR;
#elif Frame_Size == Frame_Size_9bits
	u8 status, resh, resl;
	/* Wait for data to be received */
	while ( !GET_BIT(UCSRA,UCSRA_RXC));
	/* Get status and 9th bit, then data */
	/* from buffer */
	status = UCSRA;
	resh = UCSRB;
	resl = UDR;
	/* If error, return -1 */ //Frame Error, Data Over Run, Parity Error
	if ( GET_BIT(UCSRA, UCSRA_FE) | GET_BIT(UCSRA, UCSRA_DOR) | GET_BIT(UCSRA, UCSRA_PE) )
		return -1;	// should receive the value in s16 to check 1st
	/* Filter the 9th bit, then return */
	resh = (resh >> 1) & 0x01;
	return ((resh << 8) | resl);	// return the high and low bytes in u16
#else
#error "Wrong Selection of Frame_Data_Size"
#endif
}
u16 UART_u16BaudRate(void)
{
	u16 Loc_u16BaudRate=0;
	Loc_u16BaudRate = (Crystal_CLK / (16 * Baud_Rate))-1;
	return Loc_u16BaudRate;
}
static void (*USART_GPF[3])(void)={NULL, NULL, NULL};
void USART_SetCallBack(void(*LocalPF)(void), u8 ISR_Index)
{
	//check pointer validation
	if (LocalPF != NULL)
	{
		USART_GPF[ISR_Index] = LocalPF;
	}
}
void __vector_13 (void)	//14 $01A USART, RXC USART, Rx Complete
{
	//check pointer validation
	if (USART_GPF[ISR_USART_RxC] != NULL)
	{
		USART_GPF[ISR_USART_RxC]();
	}
}
void __vector_14(void) //15 $01C USART, UDRE USART Data Register Empty
{
	//check pointer validation
	if (USART_GPF[ISR_USART_UDRE] != NULL)
	{
		USART_GPF[ISR_USART_UDRE]();
	}
}
void __vector_15(void) //16 $01E USART, TXC USART, Tx Complete
{
	//check pointer validation
	if (USART_GPF[ISR_USART_TxC] != NULL)
	{
		USART_GPF[ISR_USART_TxC]();
	}
}

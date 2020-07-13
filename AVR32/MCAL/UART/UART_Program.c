/*
 * UART_Program.c
 *
 *  Created on: Jul 11, 2020
 *      Author: MGIsmail
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "UART_Interface.h"
void UART_VidInit(void)
{
	void USART_Init( unsigned int baud )
	{
	/* Set baud rate */
	UBRRH = (unsigned char)(baud>>8);
	UBRRL = (unsigned char)baud;
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 2stop bit */
	UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
	}
}
void UART_VidSendData(u8 Loc_u8Data)
{

}
u8 UART_u8ReceiveData(void)
{
	u8 Loc_u8Received_data=0;

	return Loc_u8Received_data;
}
u16 UART_u16BaudRate(void)
{
	u16 Loc_u16BaudRate=0;

	return Loc_u16BaudRate;
}

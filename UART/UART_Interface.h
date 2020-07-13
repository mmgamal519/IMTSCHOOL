

#ifndef COTS_MCAL_UART_UART_INTERFACE_H_
#define COTS_MCAL_UART_UART_INTERFACE_H_


void UART_VidInit(void);

void Send_Data(u8 data);

u8 receiv_Data( void);

void  UART_VidSetCallBack (void (*LOCUART_funcptr)(void) );


#endif /* COTS_MCAL_UART_UART_INTERFACE_H_ */

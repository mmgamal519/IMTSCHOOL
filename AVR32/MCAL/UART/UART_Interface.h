/*
 * UART_Interface.h
 *
 *  Created on: Jul 11, 2020
 *      Author: MGIsmail
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_
#include "UART_Register.h"
#include "UART_Config.h"

void UART_VidInit(void);
void UART_VidSendData(u8 Loc_u8Data);
u8 UART_u8ReceiveData(void);
u16 UART_u16BaudRate(void);

#endif /* MCAL_UART_UART_INTERFACE_H_ */

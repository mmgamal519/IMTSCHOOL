/*
 * KP4x4_Config.h
 *
 *  Created on: Jun 7, 2020
 *      Author: MGIsmail
 */

#ifndef _KP4X4_CONFIG_H_
#define _KP4X4_CONFIG_H_

// As is to show port as number from 0 to 3
#define PORT_A 		0
#define PORT_B 		1
#define PORT_C 		2
#define PORT_D 		3

#define KeyPadColRow_port	PORT_A		// connected KeyPad 4x4 C4-C1&R1-R4 to PINs from 0-7

#define Col_4		PIN0
#define Col_3		PIN1
#define Col_2		PIN2
#define Col_1		PIN3
#define Row_1		PIN4
#define Row_2		PIN5
#define Row_3		PIN6
#define Row_4		PIN7

// return key value when pressed
#define KeyB1 			1
#define KeyB2			2
#define KeyB3			3
#define KeyB4			10
#define KeyB5			4
#define KeyB6 			5
#define KeyB7			6
#define KeyB8			11
#define KeyB9			7
#define KeyB10		8
#define KeyB11		9
#define KeyB12		12
#define KeyB13		'#'
#define KeyB14		0
#define KeyB15		'*'
#define KeyB16		13
/*
  {
		0x04,    0x08,    0x0C,    0x10 },
	{
		0x03,    0x07,    0x0B,    0x0F },
	{
		0x02,    0x06,    0x0A,    0x0E },
	{
		0x01,    0x05,    0x09,    0x0D }
*/



#endif /* KP4X4_CONFIG_H_ */

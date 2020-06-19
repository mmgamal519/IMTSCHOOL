/*
 * LCD_Config.h
 *
 *  Created on: Jun 1, 2020
 *      Author: MGIsmail
 */

#ifndef _LCD_CONFIG_H_
#define _LCD_CONFIG_H_

#define LCD_DataPort			PORT_D		//as port number 0-3 PortA-D of Data port

#define LCD_CTRLPort 		PORT_C		//as  port number 0-3 PortA-D of CTRL port
#define LCD_RS_PIN 			PIN0
#define LCD_RW_PIN 			PIN1
#define LCD_Enb_PIN			PIN2

#define FunctionSet_8bit  0b00111000
#define FunctionSet_4bit  0b00101000 // not used till now

//#define LCD_MPU_Interface	      to config 4/8 bit with data port 4/8 pins

#endif /* LCD_CONFIG_H_ */

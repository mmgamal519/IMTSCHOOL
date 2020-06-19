/*
 * KP4x4_Interface.h
 *
 *  Created on: Jun 7, 2020
 *      Author: MGIsmail
 */

#ifndef _KP4X4_INTERFACE_H_
#define _KP4X4_INTERFACE_H_


void KeyPad_4x4_VidInit(void);
u8 KeyPad_4x4_u8ButtonPressed(void);
void KeyPad4x4_VidFullcalculator(void);
s8 KeyPad4x4_Vid3ButtonCalc(void);
u8 KeyPad4x4_s83ButtonOperator(void);
void KeyPad4x4_Vid3ButtonCalcCall(void);

#endif /* KP4X4_INTERFACE_H_ */

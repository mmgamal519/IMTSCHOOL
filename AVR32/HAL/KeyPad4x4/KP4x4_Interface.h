/*
 * KP4x4_Interface.h
 *
 *  Created on: Jun 7, 2020
 *      Author: MGIsmail
 */

#ifndef _KP4X4_INTERFACE_H_
#define _KP4X4_INTERFACE_H_

#include "KP4x4_Register.h"
#include "KP4x4_Config.h"

void KeyPad_4x4_VidInit(void);
u8 KeyPad_4x4_u8ButtonPressed(void);
void KeyPad4x4_TEST(void);

#endif /* KP4X4_INTERFACE_H_ */

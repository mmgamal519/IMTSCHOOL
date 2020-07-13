/*
 * SERVO_Interface.h
 *
 *  Created on: Jul 8, 2020
 *      Author: MGIsmail
 */

#ifndef APPL_SERVO_SERVO_INTERFACE_H_
#define APPL_SERVO_SERVO_INTERFACE_H_

#include "SERVO_Config.h"

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../HAL/LCD16x2/LCD_Interface.h"
#include "../../MCAL/TIMERS/TIMER_Interface.h"
#include "../../MCAL/EXT_INT/EXIT_Interface.h"
#include "../../MCAL/GIP/GLOBALINT_Interface.h"
#include "../../MCAL/ADC/ADC_Interface.h"
#include "../../HAL/KeyPad4x4/KP4x4_Interface.h"

void SERVO_VidInitHW(void);
void SERVO_VidSetAngle(u16 Loc_u16Angle);


#endif /* APPL_SERVO_SERVO_INTERFACE_H_ */

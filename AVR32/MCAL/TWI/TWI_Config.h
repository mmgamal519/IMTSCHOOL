/*
 * TWI_Config.h
 *
 *  Created on: Jul 19, 2020
 *      Author: MGIsmail
 */

#ifndef MCAL_TWI_TWI_CONFIG_H_
#define MCAL_TWI_TWI_CONFIG_H_
/*
 * SCL and SDA Pins are PC0 and PC1
 */
#define CPU_Clock_frequency		8000000 	//Hz
#define TWI_SCL_frequency			100000		//Hz Up to 400 kHz Data Transfer Speed
#define TWI_SCL_Prescaler				0
#define TWI_Node_SLA					0x02
//To calculate bit rates, see “Bit Rate Generator Unit” on page 173.
//The value of TWPS1..0 is used in the equation.
#define TWI_Prescaler_1					0
#define TWI_Prescaler_4					1
#define TWI_Prescaler_16				2
#define TWI_Prescaler_64				3
#define TWI_Prescaler_Value			TWI_Prescaler_1

#endif /* MCAL_TWI_TWI_CONFIG_H_ */

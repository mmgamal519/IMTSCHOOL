/*
 * TWI_Register.h
 *
 *  Created on: Jul 19, 2020
 *      Author: MGIsmail
 */

#ifndef MCAL_TWI_TWI_REGISTER_H_
#define MCAL_TWI_TWI_REGISTER_H_
//--------------------Two-wire Serial Interface / I2C-------------------
#define TWBR		*((volatile u8*)0x20) //TWI Bit Rate Register
#define TWCR		*((volatile u8*)0x56) //TWI Control Register
#define TWSR		*((volatile u8*)0x21) //TWI Status Register
#define TWDR		*((volatile u8*)0x23) //TWI Data Register / Slave address desired or designated
#define TWAR		*((volatile u8*)0x22) //TWI (Slave) Address Register (Node ID) in Slave mode<<1, and bit0 TWGCE
//-------------------------------TWI (Slave) Address Register-------------------------------------------
//TWAR Bits 7..1 – TWA: TWI (Slave) Address Register
#define TWAR_TWGCE:					0	//TWI General Call Recognition Enable Bit
//-------------------------------TWI Control Register-------------------------------------------
#define TWCR_TWINT 				7	//TWI Interrupt Flag
#define TWCR_TWEA 					6	//TWI Enable Acknowledge Bit
#define TWCR_TWSTA 				5	//TWI START Condition Bit
#define TWCR_TWSTO 				4	//TWI STOP Condition Bit
#define TWCR_TWWC 				3	//TWI Write Collision Flag
#define TWCR_TWEN 					2	//TWEN: TWI Enable Bit
#define TWCR_RES						1	//Reserved Bit - Not Used
#define TWCR_TWIE					0	//TWI Interrupt Enable
//-------------------------------TWI Status Register--------------------------------------------
#define TWSR_TWS7 					7 // Bits 7..3 – TWS: TWI Status
#define TWSR_TWS6 					6
#define TWSR_TWS5 					5
#define TWSR_TWS4 					4
#define TWSR_TWS3 					3 	// Bits 7..3 – TWS: TWI Status
#define TWSR_RES 						2	//Reserved Bit - Not Used
#define TWSR_TWPS1 				1	//Bits 1..0 – TWPS: TWI Prescaler Bits
#define TWSR_TWPS0					0	//Bits 1..0 – TWPS: TWI Prescaler Bits
//--------------------------------------------------------------------------------
/*#define TWSR_S								: START condition
#define TWSR_Rs: REPEATED START condition
#define TWSR_RB: Read bit (high level at SDA)
#define TWSR_W: Write bit (low level at SDA)
#define TWSR_A: Acknowledge bit (low level at SDA)
#define TWSR_NoA: Not acknowledge bit (high level at SDA)
#define TWSR_Data: 8-bit data byte
#define TWSR_P: STOP condition
#define TWSR_SLA: Slave Address
*/
//---------------------Table 74. Status Codes for Master Transmitter Mode---------------------------------
//A START condition is sent by writing the following value to TWCR:
//Table 74, 75, 76, 77
#define TWI_MT_START								0x08	//A START condition has been transmitted
#define TWI_MT_Rs										0x10	//A repeated START condition has been transmitted
#define TWI_MT_SLA_W_ACK					0x18	//SLA+W has been transmitted;ACK has been received
#define TWI_MT_SLA_W_NoACK				0x20 	//SLA+W has been transmitted; NOT ACK has been received
#define TWI_MT_Data_ACK						0x28	//Data byte has been transmitted; ACK has been received
#define TWI_MT_Data_NoACK					0x30	//Data byte has been transmitted; NOT ACK has been received
#define TWI_Arbitration_Lost 					0x38	//Arbitration lost in SLA+W or data bytes
//---------------------Table 75. Status Codes for Master Receiver Mode---------------------------------

#define TWI_MR_START								0x08	//A START condition has been transmitted
#define TWI_MR_Rs										0x10	//A repeated START condition has been transmitted
//#define TWI_MR_ALoss								0x38	//Arbitration lost in SLA+R or NOT ACK bit
#define TWI_MR_SLA_R_ACK						0x40 	//SLA+R has been transmitted; ACK has been received
#define TWI_MR_SLA_R_NoACK				0x48	//SLA+R has been transmitted; NOT ACK has been received
#define TWI_MR_Data_ACK						0x50	//Data byte has been received; ACK has been returned
#define TWI_MR_Data_NoACK					0x58	//Data byte has been received; NOT ACK has been returned

//---------------------Table 76. Status Codes for Slave Receiver Mode---------------------------------
#define TWI_SR_SLA_W_ACK								0x60	//Own SLA+W has been received;ACK has been returned
#define TWI_SR_SLA_ACK_Arbitration_Lost		0x68	//Arbitration lost in SLA+R/W as master;
																							//own SLA+W has been received; ACK has been returned
#define TWI_SR_GC_SLA_ACK							0x70	//General call address has been received; ACK has been returned
#define TWI_SR_GC_ACK_Arbitration_Lost		0x78	//Arbitration lost in SLA+R/W as master;
																							//General call address has been received; ACK has been returned
#define TWI_SR_Data_ACK									0x80	//Previously addressed with own SLA+W;
																							//data has been received; ACK has been returned
#define TWI_SR_Data_NoACK							0x88	//Previously addressed with own SLA+W;
																							//data has been received; NOT ACK has been returned
#define TWI_SR_GC_pSLA_ACK						    0x90	//Previously addressed with general call;
																							//data has been received; ACK has been returned
#define TWI_SR_GC_pSLA_NoACK					0x98	//Previously addressed with general call;
																							//data has been received; NOT ACK has been returned
#define TWI_SR_SLA_RsSTop						0xA0	//A STOP condition or repeated START condition
																							//has been received while still addressed as slave
//---------------------Table 77. Status Codes for Slave Transmitter Mode---------------------------------
#define TWI_ST_SLA_R_ACK								0xA8	//Own SLA+R has been received; ACK has been returned
#define TWI_ST_SLA_ACK_Arbitration_Lost		0xB0	//Arbitration lost in SLA+R/W as master;
																							//own SLA+R has been received; ACK has been returned
#define TWI_ST_Data_ACK									0xB8	//Data byte in TWDR has been transmitted; ACK has been received
#define TWI_ST_Data_NoACK							0xC0	//Data byte in TWDR has been transmitted;
																							//NOT ACK has been received
#define TWI_ST_ST_Data_EA_ACK						0xC8	//Last data byte in TWDR has been transmitted (TWEA = “0”); ACK has been received
//---------------------Table 78. Miscellaneous States---------------------------------
#define TWI_Misc_Unknown						0xF8	//No relevant state information available; TWINT = “0”
#define TWI_Misc_BusError_illegalOp						0x00	//Bus error due to an illegal START or STOP condition
//------------------------------------------------------------------------------------------


void __vector_19(void)  __attribute__((signal)); //20 $026 TWI Two-wire Serial Interface

#endif /* MCAL_TWI_TWI_REGISTER_H_ */

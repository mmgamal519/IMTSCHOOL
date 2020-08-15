/*
 * TWI_Program.c
 *
 *  Created on: Jul 19, 2020
 *      Author: MGIsmail
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <util/delay.h>

#include "../TWI/TWI_Config.h"
#include "../TWI/TWI_Register.h"
#include "../TWI/TWI_Interface.h"

//Initialization as Master & Slave standby
void TWI_VidInit(void)
{
	TWI_VidBitRateGenerator();		// TWI BitRateGenerator unit
	TWAR = (TWI_Node_SLA<<1) | 0x01;			//Set Node address as slave and TWGCE enable
	SET_BIT(TWCR,TWCR_TWEN); // TWI INT Enable
	SET_BIT(TWCR,TWCR_TWIE); 	// TWI Enable
}
void TWI_VidBitRateGenerator (void)
{
	u8 TWPS=0;
	TWPS = TWI_SCL_Prescaler;
	TWSR |= (TWPS & 0x03);
	TWBR =(u8) ((u32)(((CPU_Clock_frequency/TWI_SCL_frequency)-16)/(2*(4 ^ TWPS))));
}
void TWI_VidGenCallEnb(u8 status)
{
	if (status == 1)
		SET_BIT(TWAR, 0); //Enable
	else if (status == 0)
		CLR_BIT(TWAR, 0); //Disable
	SET_BIT(TWCR,TWCR_TWEN);
	CLR_BIT(TWCR,TWCR_TWSTA);
	CLR_BIT(TWCR,TWCR_TWSTO);
}
RtnErrorCode TWI_VidMTStartCondition(void)
{
	RtnErrorCode ErrorCode = 0;
	//1 Send START condition
	TWCR = (1<<TWCR_TWINT)|(1<<TWCR_TWSTA)|(1<<TWCR_TWEN);
	//2 Wait for TWINT Flag set. This indicates that the START condition has been transmitted
	while (!(TWCR & (1<<TWCR_TWINT)));
	//3 Check value of TWI Status Register. Mask prescaler bits.
	//If status different from START go to ERROR
	if ((TWSR & 0xF8) != TWI_MT_START)
		ErrorCode = TWI_MT_START;
	else if ((TWSR & 0xF8) != TWI_MT_Rs)
		ErrorCode = TWI_MT_Rs;
	return ErrorCode ;
}
void TWI_VidMTStopCondition(void)
{
	//Transmit STOP condition
	TWCR = (1<<TWCR_TWINT)|(1<<TWCR_TWEN)|(1<<TWCR_TWSTO);
}
RtnErrorCode TWI_VidMTSendSLA_W(u8 Loc_u8SLA_W)
{
	RtnErrorCode ErrorCode=0;
	//4 Load SLA_W into TWDR Register.
	//Clear TWINT bit in TWCR to start transmission of address
	TWDR = (Loc_u8SLA_W<<1) & 0xFE; // slave address with write bit 0
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);
	//5 Check value of TWI Status Register. Mask prescaler bits.
	//If status different from MT_SLA_ACK go to ERROR
	if ((TWSR & 0xF8) != TWI_MT_SLA_W_ACK)
		ErrorCode= TWI_MT_SLA_W_NoACK;
	else if ((TWSR & 0xF8) == TWI_Arbitration_Lost)
		ErrorCode= TWI_Arbitration_Lost;
	return ErrorCode;
}
RtnErrorCode TWI_VidMTSendData(u8 Loc_u8Data)
{
	RtnErrorCode ErrorCode=0;
	//Load DATA into TWDR Register.
	//Clear TWINT bit in TWCR to start transmission of data
	TWDR = Loc_u8Data;
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);
	//6 Wait for TWINT Flag set. This indicates that the DATA has been transmitted,
	//and ACK/NACK has been received.
	while (!(TWCR & (1<<TWCR_TWINT)));
	//7 Check value of TWI Status Register. Mask prescaler bits.
	//If status different from MT_DATA_ACK go to ERROR
	if ((TWSR & 0xF8) != TWI_MT_Data_ACK)
		ErrorCode= TWI_MT_Data_NoACK;
	else if ((TWSR & 0xF8) == TWI_Arbitration_Lost)
		ErrorCode= TWI_Arbitration_Lost;
	return ErrorCode;
}
RtnErrorCode TWI_VidMRSendSLA_R(u8 Loc_u8SLA_R)
{
	RtnErrorCode ErrorCode=0;
	//4 Load SLA_W into TWDR Register.
	//Clear TWINT bit in TWCR to start transmission of address
	TWDR = (Loc_u8SLA_R<<1) | 0x01; // slave address with Read bit 1
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);
	//5 Check value of TWI Status Register. Mask prescaler bits.
	//If status different from MR_SLA_ACK go to ERROR
	if ((TWSR & 0xF8) != TWI_MR_SLA_R_ACK)
		ErrorCode= TWI_MR_SLA_R_NoACK;
	else if ((TWSR & 0xF8) == TWI_Arbitration_Lost)
		ErrorCode= TWI_Arbitration_Lost;
	return ErrorCode;
}
Data_RtnErrorCode TWI_VidMRReceiveData(void)
{
	RtnErrorCode ErrorCode=0;
	//GET DATA from TWDR Register.
	//Clear TWINT bit in TWCR to start transmission of data
	while (!GET_BIT(TWCR,TWCR_TWINT));
	u8 Data = TWDR ;
	if ((TWSR & 0xF8) != TWI_MR_Data_ACK)
		if ((TWSR & 0xF8) == TWI_MR_Data_NoACK)
			ErrorCode= TWI_MR_Data_NoACK;

	return  (u16)((ErrorCode << 8) | Data);
}
RtnErrorCode TWI_VidMTSendString (u8 Loc_u8SLA_W, u8 * Loc_u8String)
{
	RtnErrorCode ErrorCode=0;
	for (u8 i=0; Loc_u8String[i] != '\0'; i++)
	{
		ErrorCode=TWI_VidMTStartCondition();
		if (ErrorCode!=0)
		{return ErrorCode; break;}
		ErrorCode=TWI_VidMTSendSLA_W(Loc_u8SLA_W);
		if (ErrorCode!=0)
		{return ErrorCode; break;}
		ErrorCode=TWI_VidMTSendData(Loc_u8String[i]);
		if (ErrorCode!=0)
		{return ErrorCode; break;}
	}
	TWI_VidMTStopCondition();
	return ErrorCode;
}
Data_RtnErrorCode TWI_u8MRReceivingString (u8 Loc_u8SLA_R, pu8  Loc_pu8String)
{
	RtnErrorCode ErrorCode=0;
	for (u8 i=0; Loc_pu8String[i] != '\0'; i++)
	{
		ErrorCode=TWI_VidMTStartCondition();
		if (ErrorCode!=0)
		{return ErrorCode; break;}
		ErrorCode=TWI_VidMRSendSLA_R(Loc_u8SLA_R);
		if (ErrorCode!=0)
		{return ErrorCode; break;}
		Data_RtnErrorCode Result = TWI_VidMRReceiveData();
		Loc_pu8String[i] = (u8) Result;
		ErrorCode= (u8)(Result >>8 );
		if (ErrorCode!=0)
		{return ErrorCode; break;}
	}
	TWI_VidMTStopCondition();
	return ErrorCode; // data return in *ptr Loc_u8String
}
//-------------Slave---------
RtnErrorCode TWI_VidSRReceiveSLA_W(void)
{
	RtnErrorCode ErrorCode=0;
	//Receive SLA_W into TWDR Register.
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEA);
	//5 Check value of TWI Status Register. Mask prescaler bits.
	//If status different from TWI_SR_SLA_W_ACK go to ERROR
	if ((TWSR & 0xF8) != TWI_SR_SLA_W_ACK)
		ErrorCode= TWI_SR_SLA_W_ACK;
	else if ((TWSR & 0xF8) == TWI_SR_SLA_ACK_Arbitration_Lost)
		ErrorCode= TWI_SR_SLA_ACK_Arbitration_Lost;
	return ErrorCode;
}
RtnErrorCode TWI_VidSTReceiveSLA_R(void)
{
	RtnErrorCode ErrorCode=0;
	//Receive SLA_W into TWDR Register.
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEA);
	//5 Check value of TWI Status Register. Mask prescaler bits.
	//If status different from TWI_SR_SLA_W_ACK go to ERROR
	if ((TWSR & 0xF8) != TWI_ST_SLA_R_ACK)
		ErrorCode= TWI_ST_SLA_R_ACK;
	else if ((TWSR & 0xF8) == TWI_ST_SLA_ACK_Arbitration_Lost)
		ErrorCode= TWI_ST_SLA_ACK_Arbitration_Lost;
	return ErrorCode;
}
RtnErrorCode TWI_VidSTSendData(u8 Loc_u8Data)
{
	RtnErrorCode ErrorCode=0;
	//Load DATA into TWDR Register.
	//Clear TWINT bit in TWCR to start transmission of data
	TWDR = Loc_u8Data;
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);
	//6 Wait for TWINT Flag set. This indicates that the DATA has been transmitted,
	//and ACK/NACK has been received.
	while (!(TWCR & (1<<TWCR_TWINT)));
	//7 Check value of TWI Status Register. Mask prescaler bits.
	//If status different from TWI_ST_Data_ACK go to ERROR
	switch (TWSR & 0xF8)
			{
	case TWI_ST_Data_ACK: ErrorCode= 0; break;
	case TWI_ST_Data_NoACK: ErrorCode= 1; break;
	case TWI_ST_ST_Data_EA_ACK: ErrorCode= 2; break;
	case TWI_ST_SLA_ACK_Arbitration_Lost: ErrorCode= 3; break;
	default: ErrorCode= 4;
			}
	return ErrorCode;
}
RtnErrorCode TWI_VidSRReceiveData (pu8 Loc_pu8Data)
{
	RtnErrorCode ErrorCode=0;
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);
	switch (TWSR & 0xF8)
				{
		case TWI_SR_Data_ACK: Loc_pu8Data= TWDR; ErrorCode= 0; break;
		case TWI_SR_Data_NoACK: Loc_pu8Data= TWDR; ErrorCode= 1; break;
		case TWI_SR_GC_pSLA_ACK: Loc_pu8Data= TWDR;  ErrorCode= 0; break;
		case TWI_SR_GC_pSLA_NoACK: Loc_pu8Data= TWDR;  ErrorCode= 1; break;
		case TWI_SR_SLA_RsSTop:  ErrorCode= 2; break;
		case TWI_SR_SLA_ACK_Arbitration_Lost: ErrorCode= 3; break;
		default: ErrorCode= 4;
				}
	return ErrorCode;
}

// implementation idea need development
/*
RtnErrorCode TWI_ERRORCheck(u8 OPCode)
{
	RtnErrorCode ErrorCode=0;
	switch (OPCode)
	{
	case TWI_Misc_Unknown: 		//condition check			break;
	case TWI_Misc_BusError_illegalOp: 								break;
	}
	return ErrorCode;
}
*/

static void (*TWI_GPF)(u8 RData)=NULL;
void TWI_SetCallBack(void(*LocalPF)(void))
{
	//check pointer validation
	if (LocalPF != NULL)
	{
		TWI_GPF = LocalPF;
	}
}
void __vector_19(void) //20 $026 TWI Two-wire Serial Interface
{
	//check pointer validation
	if (TWI_GPF != NULL)
	{
		TWI_GPF(TWDR);
	}
	SET_BIT(TWCR,TWCR_TWINT);
}

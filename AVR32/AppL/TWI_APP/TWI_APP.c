/*
 * TWI_APP.c
 *
 *  Created on: Jul 24, 2020
 *      Author: MGIsmail
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/GIP/GLOBALINT_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/TWI/TWI_Interface.h"
#include "../../MCAL/TWI/TWI_Config.h"

#include "TWI_APP_Interface.h"
//#include "../../MCAL/SPI/SPI_Interface.h"
void TWI_main(void)
{
	GLOBALINT_VidEnable( );
	//TWI_SetCallBack(Receive_data);
	//	u16 data=0;
	//TWI_INT_Enable();
	TWI_VidGenCallEnb(1);
//	TWI_VidMTSendString("MOSTAFA");


	while(1)
	{
	}
}
void Receive_data_TWI(u8 RData)
{
	u16 data=0;
	data=RData;

	if(data!=0)
	{
		DIO_VidSetPinValue(PORT_B,PIN7,1);

	}
	else if(data==0)
	{
		DIO_VidSetPinValue(PORT_B,PIN7,0);

	}
	//TWI_VidMTSendString(data + 1);
}

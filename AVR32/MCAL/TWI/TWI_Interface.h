/*
 * TWI_Interface.h
 *
 *  Created on: Jul 19, 2020
 *      Author: MGIsmail
 */

#ifndef MCAL_TWI_TWI_INTERFACE_H_
#define MCAL_TWI_TWI_INTERFACE_H_

/*---------------------------Features------------------------------
 * • Simple Yet Powerful and Flexible Communication Interface, Only Two Bus Lines Needed
 * • Both Master and Slave Operation Supported
 * • Device Can Operate as Transmitter or Receiver
 * • 7-bit Address Space allows up to 128 Different Slave Addresses
 * • Multi-master Arbitration Support
 * • Up to 400 kHz Data Transfer Speed
 * • Slew-rate Limited Output Drivers
 * • Noise Suppression Circuitry Rejects Spikes on Bus Lines
 * • Fully Programmable Slave Address with General Call Support
 * • Address Recognition causes Wake-up when AVR is in Sleep Mode
 */
#include "../../MCAL/TWI/TWI_Register.h"
void TWI_VidInit(void);
void TWI_VidBitRateGenerator (void);
void TWI_VidGenCallEnb(u8 status);
RtnErrorCode TWI_VidMTStartCondition(void);
void TWI_VidMTStopCondition(void);
RtnErrorCode TWI_VidMTSendSLA_W(u8 Loc_u8SLA_W);
RtnErrorCode TWI_VidMTSendData(u8 Loc_u8Data);
RtnErrorCode TWI_VidMRSendSLA_R(u8 Loc_u8SLA_R);
Data_RtnErrorCode TWI_VidMRReceiveData(void);
RtnErrorCode TWI_u8MTSendString (u8 Loc_u8SLA_W, u8 * Loc_u8String);
Data_RtnErrorCode TWI_u8MRReceivingString (u8 Loc_u8SLA_R, pu8  Loc_pu8String);
RtnErrorCode TWI_VidSRReceiveSLA_W(void);
RtnErrorCode TWI_VidSTReceiveSLA_R(void);
RtnErrorCode TWI_VidSTSendData(u8 Loc_u8Data);
RtnErrorCode TWI_VidSRReceiveData (pu8 Loc_pu8Data);
void TWI_SetCallBack(void(*LocalPF)(void));
//--------------------------------------------------------------------------
#endif /* MCAL_TWI_TWI_INTERFACE_H_ */

/*
 * SPI_Program.c
 *
 *  Created on: Jul 17, 2020
 *      Author: MGIsmail
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "SPI_Register.h"
void SPI_Init(void)
{
	/* Set MOSI and SCK output, all others input */
	DIO_VidSetPinDirection(PORT_B,PIN5, OUTPUT); //MOSI PB5
	DIO_VidSetPinDirection(PORT_B,PIN6, INPUT);//MISO PB6
	DIO_VidSetPinDirection(PORT_B,PIN7, OUTPUT);
	DIO_VidSetPinDirection(PORT_B,PIN4, OUTPUT);//
	/* Enable SPI, Master, set clock rate fck/16 */
	//SET_BIT(SPCR, SPCR_SPE); //Enable SPI
	//SET_BIT(SPCR, SPCR_DORD);//Shift Right LSB first
	//SET_BIT(SPCR, SPCR_MSTR); //Master Select
	//SET_BIT(SPCR, SPCR_CPOL); //Clock Polarity
	//SET_BIT(SPCR, SPCR_CPHA); //Clock Phase
	//SPI Clock Rate Select 1 and 0 //fclk/64
	//CLR_BIT(SPSR, SPSR_SPI2X);
	//	SET_BIT(SPCR, SPCR_SPR1);
	//SET_BIT(SPCR, SPCR_SPR0);
	SPCR = (1<<SPCR_SPE)|(1<<SPCR_MSTR)|(1<<SPCR_SPR0);

	//Full-duplex, Three-wire Synchronous Data Transfer
	//Master or Slave Operation
	//LSB First or MSB First Data Transfer
	//Seven Programmable Bit Rates
	//End of Transmission Interrupt Flag
	//Write Collision Flag Protection
	//Wake-up from Idle Mode
	//Double Speed (CK/2) Master SPI Mode

}

u8 SPI_Trans (u8 Data)
{

	SPDR = Data;
	while (!GET_BIT(SPSR, SPSR_SPIF));
	return SPDR;
}


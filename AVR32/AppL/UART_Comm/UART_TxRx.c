#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/GIP/GLOBALINT_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/USART/USART_Interface.h"
#include "../../MCAL/USART/USART_Config.h"
#include "../../MCAL/USART/USART_Register.h"
#include "UART_Comm_Interface.h"
#include "../../MCAL/SPI/SPI_Interface.h"
void UART(void)
{
	GLOBALINT_VidEnable( );

	DIO_VidSetPinDirection(PORT_D,PIN0,INPUT);
	DIO_VidSetPinDirection(PORT_D,PIN1,OUTPUT);
	DIO_VidSetPinDirection(PORT_B,PIN7,OUTPUT);
	USART_Init(9600);
	USART_SetCallBack(Receive_data, ISR_USART_RxC);
	USART_SetCallBack(Transmit_data, ISR_USART_TxC);
//	u16 data=0;
	USART_Rx_INT_Enable();
	SPI_Init();

while(1)
	{
    /*  data=USART_Receive();
      if(data=='w')
      {
    	  DIO_VidSetPinValue(PORT_B,PIN7,1);
    	  USART_Transmit((u16)'w');
      }
      else if(data=='s')
      {
    	  DIO_VidSetPinValue(PORT_B,PIN7,0);
    	  USART_Transmit((u16)'s');
      }
*/
	}

}

void Transmit_data()
{

}
void Receive_data()
{
	u16 data=0;
	data=UDR;
	u8 RD = SPI_Trans(data);
	 if(data=='w')
	      {
	    	  DIO_VidSetPinValue(PORT_B,PIN7,1);

	      }
	      else if(data=='s')
	      {
	    	  DIO_VidSetPinValue(PORT_B,PIN7,0);

	      }
	  USART_Transmit((u16)RD);
}

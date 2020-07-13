
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LCD_4BIT_Interface.h"
#include "UART_Regster.h"
#include "DIO_Interface.h"
#include "EXI_Regster.h"

static void  (*CallBackFuncPtr)(void)= NULL;

void  UART_VidSetCallBack (void (*LOCUART_funcptr)(void) )
{
	if(LOCUART_funcptr  != NULL )
	{
		CallBackFuncPtr = LOCUART_funcptr ;
	}
}
void UART_VidInit(void)
{
	u8 UCSRC_value=0;
	//BOUD rate
	UBRRH=0;
	UBRRL=51;
	//transmission speed
	CLR_BIT(UCSRA,U2X);
	//UCSRC active UCSRC and active 8 character size
	SET_BIT(UCSRC_value,URSEL);
	SET_BIT(UCSRC_value,UCSZ1);
	SET_BIT(UCSRC_value,UCSZ0);
	//ASYNC
	CLR_BIT(UCSRC_value,UMSEL);
	//NO PARITY
	CLR_BIT(UCSRC_value,UPM0);
	CLR_BIT(UCSRC_value,UPM1);
	//one stop mode
	CLR_BIT(UCSRC_value,USBS);
	UCSRC=UCSRC_value;

	//UCSRB enable Tx and Rx
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
}
void Send_Data(u8 data)
{
while(!GET_BIT(UCSRA,UDRE));

UDR_T=data;
}
u8 receiv_Data( void)
{
	//u8 result;
	while(!GET_BIT(UCSRA,RXC));
	return UDR_R;
}

ISR(ADC_VECT)
{
	if(CallBackFuncPtr != NULL )
	{
		CallBackFuncPtr();
	}
}

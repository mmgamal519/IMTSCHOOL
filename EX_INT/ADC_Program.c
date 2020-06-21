
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_Register.h"
#include "ADC_Interface.h"
#include <util/delay.h>


void ADC_VidInit(void)
{
	// select the voltage refernce AVCC
	CLR_BIT(ADMUX, ADMUX_REFS1);
	SET_BIT(ADMUX, ADMUX_REFS0);
	//Select Right Adjust
	CLR_BIT(ADMUX, ADMUX_ADLAR);
	//Select prescaler
	SET_BIT(ADCSRA, ADCSRA_ADPS2);
	SET_BIT(ADCSRA, ADCSRA_ADPS1);
	CLR_BIT(ADCSRA, ADCSRA_ADPS0);
	//Trigger off
	CLR_BIT(ADCSRA, ADCSRA_ADATE);
	//Enable ADC
	SET_BIT(ADCSRA,ADCSRA_ADEN);

}

u16 ADC_VidGetDigitalValue(u8 LOC_u8channel)
{
	u16 RESULT;
	// to select A0-A7
	ADMUX &=(0b11100000);
	ADMUX |=(LOC_u8channel & 0b00011111);
	//start conversion
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	while(GET_BIT(ADCSRA,ADCSRA_ADIF) ==0);
	RESULT = ADC10;
	SET_BIT(ADCSRA,ADCSRA_ADIF);
	return RESULT;
}

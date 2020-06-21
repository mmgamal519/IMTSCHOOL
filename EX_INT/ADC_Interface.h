#ifndef _ADC_INTERFACE_H_
#define _ADC_INTERFACE_H_


#define ADMUX_REFS1			7
#define ADMUX_REFS0			6
#define ADMUX_ADLAR 		5

#define ADCSRA_ADEN		7
#define ADCSRA_ADSC		6
#define ADCSRA_ADATE		5
#define ADCSRA_ADIF			4
#define ADCSRA_ADIE			3
#define ADCSRA_ADPS2		2
#define ADCSRA_ADPS1		1
#define ADCSRA_ADPS0		0

#define	ADC_Channel0		0
#define	ADC_Channel1		1
#define	ADC_Channel2		2
#define	ADC_Channel3		3
#define	ADC_Channel4		4
#define	ADC_Channel5		5
#define	ADC_Channel6		6
#define	ADC_Channel7		7

void ADC_VidInit(void);
u16 ADC_VidGetDigitalValue(u8 LOC_u8channel);

#endif

#ifndef COTS_MCAL_EXI_EXI_REGSTER_H_
#define COTS_MCAL_EXI_EXI_REGSTER_H_

 #define falling   0
  #define rising    1
  #define io        2
  #define low_level 3 
  #define control_sens rising

#define INT0 6 
#define INT1 7
#define ISC00 0
#define ISC01 1

#define INT1_VECT     __vector_2
#define INT2_VECT     __vector_3
#define ADC_VECT     __vector_16
#define TIMER_VECT     __vector_11
#define TIMER_CTC_VECT     __vector_10
#define TIMER_1_CAPT_VECT     __vector_6
#define TIMER_1_OVF_VECT     __vector_9
#define TIMER_1_COMPA_VECT     __vector_7

#define ISR(vector,...) \
	void vector(void)   __attribute__((signal)) __VA_ARGS__; \
	void vector(void)

#define GICR *((volatile unsigned char *)0x5B)

#define MCUCSR *((volatile unsigned char*) 0x54)

#define GIFR *((volatile unsigned char *)0x5A)

#define MCUCR *((volatile unsigned char *)0x55)




#endif /* COTS_MCAL_EXI_EXI_REGSTER_H_ */


#ifndef COTS_MCAL_UART_UART_CONFIG_H_
#define COTS_MCAL_UART_UART_CONFIG_H_
//Voltage Reference Selections for ADC
#define Voltage_Reference_off        	        	     0             //AREF, Internal Vref turned off
#define Voltage_Reference_vcc                            1            //AVCC with external capacitor at AREF pin
#define Voltage_Reference_Reserved     			         2           //Reserved
#define Voltage_Reference_2					             3          //Internal 2.56V Voltage Reference with external capacitor at AREF pin


#define Voltage_Reference__mode  Voltage_Reference_vcc
//Voltage Reference Selections for ADC pins
#define  REFS1 7
#define  REFS0 6

#define  enable  1
#define  disable  0

//ADC Left Adjust Result
#define  ADC_Left_Adjust   				0
#define  ADC_Right_Adjust               1

#define  ADC_Left_Adjust                enable        //disable and dis able wor left adjust
#define  ADC_Right_Adjust        	    enable       //enabe and enable work right adjust
//lift and right adjast pin
#define  ADLAR 5
//ADC Auto Trigger Source Selections....type of mode (Free Running mode, external intrrupt,....exc)
#define Free_Running_mode                   0                 //Free Running mode
#define Analog_Comparator                   1                //Analog Comparator
#define External_Interrupt_Request_0        2               //External Interrupt Request 0
#define Timer_Counter0_Compare_Match        3              //Timer/Counter0 Compare Match
#define Timer_Counter0_Overflow             4             //Timer/Counter0 Overflow
#define Timer_Counter_Compare_Match_B       5            //Timer/Counter Compare Match B
#define Timer_Counter1_Overflow             6           //Timer/Counter1 Overflow
#define Timer_Counter1_Capture_Event        7          //Timer/Counter1 Capture Event

#define Auto_Trigger_Source_Selections  Free_Running_mode
//mode selct
#define  ADTS0  5
#define ADTS1   6
#define ADTS2   7

#define  Auto_trigger    enable     //  another choice  disable

#define ADATE  5                   //Auto_trigger

#define  ADC_TRIGGER     enable   //  another choice  disable   //enable ADC when it's running in the initialization it's will running in sleep mode

#define  ADEN 7	  //ENABLE 1


#define  ADSC 6  //ENABLE  1
#define  ADIF 4

#define ADIE   3 //ENABLE FLAG



//CLOCK SELECT PRESCALER
#define prescaler_1        2                 //2 prescaler
#define prescaler_4        4                //4 prescaler
#define prescaler_8        8               //8 prescaler
#define prescaler_16      16              //16 prescaler
#define prescaler_32      32             //32 prescaler
#define prescaler_64      64            //64 prescaler
#define prescaler_128    128           //128prescaler

#define prescaler_mode  prescaler_64

//PRESCALER PIN
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2

//Single Ended Input
#define singel_ended   0b11100000

#endif /* COTS_MCAL_UART_UART_CONFIG_H_ */





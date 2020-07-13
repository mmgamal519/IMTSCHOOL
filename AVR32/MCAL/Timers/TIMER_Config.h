#ifndef _TIMER_CONFIG_H_
#define _TIMER_CONFIG_H_

#define Disable							0
#define Enable								1
#define TIMER0_Code_ENABLE		Disable
#define TIMER1_Code_ENABLE		Disable
#define TIMER2_Code_ENABLE		Disable

//======================== (((((( Timer0 ))))))===================================
#if TIMER0_Code_ENABLE	 == Enable
//Timer0

//-------------------------------------------------
//Compare Output Mode, non-PWM Mode
//COM01 COM00 Description
//0 0 Normal port operation, OC0 disconnected.
//0 1 Toggle OC0 on compare match
//1 0 Clear OC0 on compare match
//1 1 Set OC0 on compare match



//------------Timer0_Clock_Select prescaling-------------------------------------
#define Timer0_No_clock_source						0
#define Timer0_clock_No_prescaling					1
#define Timer0_clock_from_prescaling8				2
#define Timer0_clock_from_prescaling64			3
#define Timer0_clock_from_prescaling256 		4
#define Timer0_clock_from_prescaling1024		5
#define Timer0_External_clock_source_T0_FE		6
#define Timer0_External_clock_source_T0_RE		7
#define Timer0_Clock_Select 							Timer0_clock_from_prescaling256
//----------------Timer0_Waveform_Generation_Mode--------------------
//Table 38.
#define Timer0_Normal_Overflow						0
#define Timer0_PWM_Phase_Correct				1
#define Timer0_CTC											2
#define Timer0_Fast_PWM								3
#define Timer0_Waveform_Generation_Mode	Timer0_Fast_PWM
//------Timer0_Compare Output Mode, non-PWM Mode-------
//Table 39 shows the COM01:0 bit functionality COM01 COM00
//when the WGM01:0 bits are set to a normal or CTC mode (non-PWM).
#define Timer0_NonPWM_Normal_port_operation 			0		//0 0 Normal port operation, OC0 disconnected.
#define Timer0_NonPWM_Toggle_OC0								1		//0 1 Toggle OC0 on compare match
#define Timer0_NonPWM_Clear_OC0								2		//1 0 Clear OC0 on compare match
#define Timer0_NonPWM_Set_OC0									3		//1 1 Set OC0 on compare match
#define Timer0_Compare_Output_Mode_non_PWM 			Timer0_NonPWM_Clear_OC0
//----------Compare Output Mode, Fast PWM Mode(1)----------
//Table 40 shows the COM01:0 bit functionality when the WGM01:0 bits are set to fast PWM mode.
#define Timer0_Fast_PWM_Normal									0		//0 0 Normal port operation, OC0 disconnected.
#define Timer0_Fast_PWM_Reserved									1		//0 1 Reserved
#define Timer0_Fast_PWM_Clear_OC0								2		//1 0 Clear OC0 on compare match, set OC0 at TOP
#define Timer0_Fast_PWM_Set_OC0									3		//1 1 Set OC0 on compare match, clear OC0 at TOP
#define Timer0_Compare_Output_Mode_Fast_PWM			Timer0_Fast_PWM_Normal

#else //Timer 0 Disabled
#endif // TIMER0_Code_ENABLE
//======================== (((((( Timer1 ))))))===================================
#if TIMER1_Code_ENABLE	 == Enable
//Timer1 program Code
//----------------Compare Output Mode, non-PWM   --------------------------
//Table 44 shows the COM1x1:0 bit functionality
//when the WGM13:0 bits are set to a normal or a CTC mode (non-PWM).
//COM1A1/COM1B1 COM1A0/COM1B0
#define NonPWM_Normal_port_operation 			0					//0 0 Normal port operation, OC1A/OC1B disconnected.
#define NonPWM_Toggle										1					 //0 1 Toggle OC1A/OC1B on compare match
#define NonPWM_Clear_compare_match				2					//1 0 Clear OC1A/OC1B on compare match (Set output to low level)
#define NonPWM_Set_compare_match				3					//1 1 Set OC1A/OC1B on compare match (Set output to high level)
#define Compare_Output_Mode_non_PWM			NonPWM_Normal_port_operation

//------------Compare Output Mode, Fast PWM(1)-------------
//Table 45 shows the COM1x1:0 bit functionality
//when the WGM13:0 bits are set to the fast PWM mode.
//COM1A1/COM1B1 COM1A0/COM1B0
#define Fast_PWM_Normal_port_operation 			0					//0 0 Normal port operation, OC1A/OC1B disconnected.
#define Fast_PWM_Toggle									1					// 0 1 WGM13:0 = 15: Toggle OC1A on Compare Match, OC1B disconnected (normal port operation).
																								//For all other WGM13:0 settings, normal port operation, OC1A/OC1B disconnected.
#define Fast_PWM_Clear_compare_match				2					//1 0 Clear OC1A/OC1B on compare match, set OC1A/OC1B at TOP
#define Fast_PWM_Set_compare_match				3					//1 1 Set OC1A/OC1B on compare match, clear OC1A/OC1B at TOP
#define Compare_Output_Mode_Fast_PWM			Fast_PWM_Normal_port_operation

//----------Compare Output Mode, Phase Correct and Phase and Frequency Correct PWM----------------
//Table 46 shows the COM1x1:0 bit functionality
//when the WGM13:0 bits are set to the phase correct or the phase and frequency correct, PWM mode.
//COM1A1/COM1B1 COM1A0/COM1B0
#define PhaseC_PWM_Normal_port_operation 			0					//0 0 Normal port operation, OC1A/OC1B disconnected.
#define PhaseC_Toggle											1					//0 1 WGM13:0 = 9 or 14: Toggle OC1A on Compare Match, OC1B disconnected (normal port operation).
																									//For all other WGM13:0 settings, normal port operation, OC1A/OC1B disconnected.
#define PhaseC_Clear_compare_match						2					//1 0 Clear OC1A/OC1B on compare match when up-counting. Set OC1A/OC1B on compare match when down counting.
#define PhaseC_Set_compare_match						3					//1 1 Set OC1A/OC1B on compare match when up counting. Clear OC1A/OC1B on compare match when down counting.
#define Compare_Output_Mode_Phase_Frequency_Correct_PWM						PhaseC_PWM_Normal_port_operation

//Table 47. Waveform Generation Mode Bit Description(1)
///Mode //[(WGM13, WGM12 (CTC1), WGM11 (PWM11), WGM10 (PWM10))]//, Timer/Counter Mode of Operation, TOP, Update of OCR1x, TOV1 Flag Set on
#define WGM_Normal 														0	//0 0 0 0 0 Normal 0xFFFF Immediate MAX
#define WGM_PWM_Phase_Correct_8bit 							1	//1 0 0 0 1 PWM, Phase Correct, 8-bit 0x00FF TOP BOTTOM
#define WGM_PWM_Phase_Correct_9bit 		 					2  //2 0 0 1 0 PWM, Phase Correct, 9-bit 0x01FF TOP BOTTOM
#define WGM_PWM_Phase_Correct_10bit  						3	//3 0 0 1 1 PWM, Phase Correct, 10-bit 0x03FF TOP BOTTOM
#define WGM_CTC_OCR1A 												4	//4 0 1 0 0 CTC OCR1A Immediate MAX
#define WGM_Fast_PWM_8bit 											5	//5 0 1 0 1 Fast PWM, 8-bit 0x00FF TOP TOP
#define WGM_Fast_PWM_9bit 											6	//6 0 1 1 0 Fast PWM, 9-bit 0x01FF TOP TOP
#define WGM_Fast_PWM_10bit 										7	//7 0 1 1 1 Fast PWM, 10-bit 0x03FF TOP TOP
#define WGM_PWM_Phase_and_Frequency_Correct_ICR1 			8		//8 1 0 0 0 PWM, Phase and Frequency Correct ICR1 BOTTOM BOTTOM
#define WGM_PWM_Phase_and_Frequency_Correct_OCR1A			9		//9 1 0 0 1 PWM, Phase and Frequency Correct OCR1A BOTTOM BOTTOM
#define WGM_PWM_Phase_Correct_ICR1 										10 	//10 1 0 1 0 PWM, Phase Correct ICR1 TOP BOTTOM
#define WGM_PWM_Phase_Correct_OCR1A 									11		//11 1 0 1 1 PWM, Phase Correct OCR1A TOP BOTTOM
#define WGM_CTC_ICR1 																12		//12 1 1 0 0 CTC ICR1 Immediate MAX
#define WGM_Reserved 																13		//13 1 1 0 1 Reserved – – –
#define WGM_Fast_PWM_ICR1 													14		//14 1 1 1 0 Fast PWM ICR1 TOP TOP
#define WGM_Fast_PWM_OCR1A 												15		//15 1 1 1 1 Fast PWM OCR1A TOP TOP
#define Waveform_Generation_Mode						  WGM_Normal
#else //Timer 1 Disabled
#endif // TIMER1_Code_ENABLE
//======================== (((((( Timer2 ))))))===================================
#if TIMER2_Code_ENABLE	 == Enable
//Timer2 program Code
//------------Timer2_Clock_Select prescaling-------------------------------------
#define Timer2_No_clock_source						0
#define Timer2_clock_No_prescaling					1
#define Timer2_clock_from_prescaling8				2
#define Timer2_clock_from_prescaling64			3
#define Timer2_clock_from_prescaling256 		4
#define Timer2_clock_from_prescaling1024		5
#define Timer2_External_clock_source_T0_FE		6
#define Timer2_External_clock_source_T0_RE		7
#define Timer2_Clock_Select 							Timer2_clock_from_prescaling256
//----------------Timer2_Waveform_Generation_Mode--------------------
//Table 38.
#define Timer2_Normal_Overflow						0
#define Timer2_PWM_Phase_Correct				1
#define Timer2_CTC											2
#define Timer2_Fast_PWM								3
#define Timer2_Waveform_Generation_Mode	Timer2_Fast_PWM
//------Timer2_Compare Output Mode, non-PWM Mode-------
//Table 39 shows the COM01:0 bit functionality COM01 COM00
//when the WGM01:0 bits are set to a normal or CTC mode (non-PWM).
#define Timer2_NonPWM_Normal_port_operation 			0		//0 0 Normal port operation, OC0 disconnected.
#define Timer2_NonPWM_Toggle_OC0								1		//0 1 Toggle OC0 on compare match
#define Timer2_NonPWM_Clear_OC0								2		//1 0 Clear OC0 on compare match
#define Timer2_NonPWM_Set_OC0									3		//1 1 Set OC0 on compare match
#define Timer2_Compare_Output_Mode_non_PWM 			Timer2_NonPWM_Clear_OC0
//----------Compare Output Mode, Fast PWM Mode(1)----------
//Table 40 shows the COM01:0 bit functionality when the WGM01:0 bits are set to fast PWM mode.
#define Timer2_Fast_PWM_Normal									0		//0 0 Normal port operation, OC0 disconnected.
#define Timer2_Fast_PWM_Reserved									1		//0 1 Reserved
#define Timer2_Fast_PWM_Clear_OC0								2		//1 0 Clear OC0 on compare match, set OC0 at TOP
#define Timer2_Fast_PWM_Set_OC0									3		//1 1 Set OC0 on compare match, clear OC0 at TOP
#define Timer2_Compare_Output_Mode_Fast_PWM			Timer2_Fast_PWM_Normal

#else //Timer 2 Disabled
#endif // TIMER2_Code_ENABLE

#endif	//end guard _TIMER_CONFIG_H_//

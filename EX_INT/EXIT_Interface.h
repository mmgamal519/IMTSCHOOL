#ifndef _EXIT_INTERFACE_H_
#define _EXIT_INTERFACE_H_

#define Falling_Edge		0
#define Rising_Edge			1
#define IOC						2		//interrupt on change
#define Low_Level			3
#define Sense_Mood		Falling_Edge


void EXTINT0_VidInit(void);
void EXTINT0_VidEnable(void);
void EXTINT0_VidDisable(void);
void EXTINT1_VidInit(void);
void EXTINT1_VidEnable(void);
void EXTINT1_VidDisable(void);
void EXTINT2_VidInit(void);
void EXTINT2_VidEnable(void);
void EXTINT2_VidDisable(void);


#endif

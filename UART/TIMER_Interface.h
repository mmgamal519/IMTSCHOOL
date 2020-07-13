

#ifndef COTS_MCAL_TIMER_TIMER_INTERFACE_H_
#define COTS_MCAL_TIMER_TIMER_INTERFACE_H_
  

void TIMER_VidEnable(void);

void Tim_Count0_VidCounterReg(u8 Loc_u8TCNTvalue);

void Tim_Count0_VidCompareReg(u8 Loc_u8OCRvalue);

void TIMER_VidSetCallBack(void (*LOC_funcptr)(void)  );

void  TIMER_1_VidSetCallBack (void (*LOC_funcptr_1)(void) );

void Set_Duty_cycle(u8 Loc_u8OCRvalue);

u16 u16_return_ICR1(void);

void u8_TOGAL_ICES1(void);

void TIMER_1_INPUT_CAPUER_VidEnable(void);

void TIMER_1_VidEnable(void);

//TIMER_1
void Tim1_Count0_ICR1(u16 Loc_u8TCNTvalue);
void Tim1_Count0_OCR1A(u16 Loc_u8OCRvalue);

#endif /* COTS_MCAL_TIMER_TIMER_INTERFACE_H_ */

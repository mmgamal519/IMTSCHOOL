#ifndef _LCD_INTERFACE_H_ //Header guard if not defined
#define _LCD_INTERFACE_H_

#define On 1
#define Off 0



void LCD_VidInit(void);
/*
void LCD_VidDisplayOn (void);
void LCD_VidDisplayOff(void);
void LCD_VidClrDisplay(void);

void LCD_VidCursorOnOff(u8 LOC_u8State);

void LCD_VidCursorBlinking(u8 LOC_u8State);
*/

void LCD_VidWriteCommand(u8 LOC_u8Command);

void LCD_VidWriteData(u8 LOC_u8Data);

void LCD_VidWriteString(u8* LOC_u8String);

void LCD_VidWriteNumber(s32 LOC_u32Number);
void LCD_VidWriteEquation(u32 LOC_u32Number1, u32 LOC_u8Op, u32 LOC_u32Number2);

void LCD_VidSetPosition(u8 LOC_u8Row, u8 LOC_u8Column);

void LCD_VidArabic(void);
//void LCD_VidLoadCustomChar( )
void LCD_VidDispCustomChar(u8 *ptr, u8 LOC_u8CustomCharNum, u8 LOC_u8Row, u8 LOC_u8Column );

void LCD_VidDispArabicCharRighttoLeft(u8 *ptr, u8 LOC_u8CustomCharNum, u8 LOC_u8Row, u8 LOC_u8Column );

#endif

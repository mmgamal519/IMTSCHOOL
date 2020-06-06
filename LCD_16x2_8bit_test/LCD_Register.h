#ifndef _LCD_REGISTER_H_
#define _LCD_REGISTER_H_


#define DisplayOn				0b00001100 		//command data for 8-bit to Turn Display on
#define DisplayOff			 	0b00001000 		//command data for 8-bit to Turn Display off
#define CLRDisplay			 	0b00000001		//command data for 8-bit to CLR Display

#define CursorOn				0b00001110		//command data for 8-bit to Turn Cursor on
#define CursorOff				0b00001100		//command data for 8-bit to Turn Cursor off

#define CursorBlink				0b00001111		//command data for 8-bit to Turn Cursor Blinking
#define CursorNoBlink		0b00001110		//command data for 8-bit to stop Cursor Blinking

#define CursorShiftR			0b00010100		//command data for 8-bit to  Shift Cursor position to Right (increase by 1) DB7~DB0->(0b 0 0 0 1 S/C R/L - -)
#define CursorShiftL			0b00010000
#define DisplayShiftR			0b00011100		//command data for 8-bit to  Shift entire display to Right, & cursor follow the shift
#define DisplayShiftL			0b00011000

#define ReturnHome			0b00000010		//command data for 8-bit to  Return Home position




#endif

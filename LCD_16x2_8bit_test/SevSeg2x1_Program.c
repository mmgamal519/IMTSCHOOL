#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Register.h"
#include "DIO_Interface.h"
#include "LED_Config.h"
#include "LED_Interface.h"
#include "SevSeg2x1_Config.h"
#include "SevSeg2x1_Register.h"
#include "SevSeg2x1_Interface.h"

#include <util/delay.h>

void SevSeg2x1_VidInit(void)
{
	DIO_VidSetPortDirection(_7seg2x1_DataPort, 0xFF);	//enable Data port for Seven Segment to be output
	DIO_VidSetPinDirection(_7seg2x1_CTRLPort, _7seg2x1_CTRLLP, OUTPUT); //enable CTRL PIN for Left Seven Segment to be output
	DIO_VidSetPinDirection(_7seg2x1_CTRLPort, _7seg2x1_CTRLRP, OUTPUT); //enable CTRL PIN for Right Seven Segment to be output
}

void SevSeg2x1_VidDisplayRightDigit(u8 LOC_u8Digit)
{
	DIO_VidSetPinValue(_7seg2x1_CTRLPort, _7seg2x1_CTRLLP, Disable); //disable Left Seven Segment
	DIO_VidSetPinValue(_7seg2x1_CTRLPort, _7seg2x1_CTRLRP, Enable); //enable Right Seven Segment
	switch (LOC_u8Digit)
	{
	case 0: LOC_u8Digit=Zero; break;
	case 1: LOC_u8Digit=One; break;
	case 2: LOC_u8Digit=Two; break;
	case 3: LOC_u8Digit=Three; break;
	case 4: LOC_u8Digit=Four; break;
	case 5: LOC_u8Digit=Five; break;
	case 6: LOC_u8Digit=Six; break;
	case 7: LOC_u8Digit=Seven; break;
	case 8: LOC_u8Digit=Eight; break;
	case 9: LOC_u8Digit=Nine; break;
	}
	DIO_VidSetPortValue(_7seg2x1_DataPort, LOC_u8Digit);
}

void SevSeg2x1_VidDisplayLeftDigit(u8 LOC_u8Digit)
{
	DIO_VidSetPinValue(_7seg2x1_CTRLPort, _7seg2x1_CTRLRP, Disable); //disable Right Seven Segment
	DIO_VidSetPinValue(_7seg2x1_CTRLPort, _7seg2x1_CTRLLP, Enable); //enable Left Seven Segment
	switch (LOC_u8Digit)
	{
	case 0: LOC_u8Digit=Zero; break;
	case 1: LOC_u8Digit=One; break;
	case 2: LOC_u8Digit=Two; break;
	case 3: LOC_u8Digit=Three; break;
	case 4: LOC_u8Digit=Four; break;
	case 5: LOC_u8Digit=Five; break;
	case 6: LOC_u8Digit=Six; break;
	case 7: LOC_u8Digit=Seven; break;
	case 8: LOC_u8Digit=Eight; break;
	case 9: LOC_u8Digit=Nine; break;
	}
	DIO_VidSetPortValue(_7seg2x1_DataPort, LOC_u8Digit);
}

void SevSeg2x1_VidCountUp(u8 LOC_u8Start, u8 LOC_u8End)
{

	u8 LOC_LeftDigit = 0;
	u8 LOC_RightDigit = 0;
	for (u8 LOC_Count=LOC_u8Start; LOC_Count<(LOC_u8End+1); LOC_Count++)
	{
		LOC_LeftDigit = LOC_Count /10;
		LOC_RightDigit = LOC_Count % 10;

		for (u8 LOC_Refresh=0; LOC_Refresh<_7seg2x1_Refresh; LOC_Refresh++)
		{
			SevSeg2x1_VidDisplayRightDigit(LOC_RightDigit);
			_delay_ms(10);
			SevSeg2x1_VidDisplayLeftDigit(LOC_LeftDigit);
			_delay_ms(10);
		}
	}
}


void SevSeg2x1_VidCountDown(u8 LOC_u8Start, u8 LOC_u8End)
{
	u8 LOC_LeftDigit = 0;
	u8 LOC_RightDigit = 0;
	for (s8 LOC_Count=LOC_u8Start; LOC_Count>=(LOC_u8End); LOC_Count--)
	{
		LOC_LeftDigit = LOC_Count /10;
		LOC_RightDigit = LOC_Count % 10;

		for (u8 LOC_Refresh=0; LOC_Refresh<_7seg2x1_Refresh; LOC_Refresh++)
		{
			SevSeg2x1_VidDisplayRightDigit(LOC_RightDigit);
			_delay_ms(10);
			SevSeg2x1_VidDisplayLeftDigit(LOC_LeftDigit);
			_delay_ms(10);
		}
	}
}

void SevSeg2x1_VidLoading(u16 LOC_u8Speed)
{
	DIO_VidSetPinValue(_7seg2x1_CTRLPort, _7seg2x1_CTRLRP, Enable); //enable Right Seven Segment
	DIO_VidSetPortValue(_7seg2x1_DataPort, SevSeg_loadA);
	_delay_ms(LOC_u8Speed);
	DIO_VidSetPortValue(_7seg2x1_DataPort, SevSeg_loadB);
	_delay_ms(LOC_u8Speed);
	DIO_VidSetPortValue(_7seg2x1_DataPort, SevSeg_loadC);
	_delay_ms(LOC_u8Speed);
	DIO_VidSetPortValue(_7seg2x1_DataPort, SevSeg_loadD);
	_delay_ms(LOC_u8Speed);
	DIO_VidSetPinValue(_7seg2x1_CTRLPort, _7seg2x1_CTRLRP, Disable); //Disable Right Seven Segment

	DIO_VidSetPinValue(_7seg2x1_CTRLPort, _7seg2x1_CTRLLP, Enable); //enable Right Seven Segment
	DIO_VidSetPortValue(_7seg2x1_DataPort, SevSeg_loadD);
	_delay_ms(LOC_u8Speed);
	DIO_VidSetPortValue(_7seg2x1_DataPort, SevSeg_loadE);
	_delay_ms(LOC_u8Speed);
	DIO_VidSetPortValue(_7seg2x1_DataPort, SevSeg_loadF);
	_delay_ms(LOC_u8Speed);
	DIO_VidSetPortValue(_7seg2x1_DataPort, SevSeg_loadA);
	_delay_ms(LOC_u8Speed);
	DIO_VidSetPinValue(_7seg2x1_CTRLPort, _7seg2x1_CTRLLP, Disable); //Disable Right Seven Segment
}

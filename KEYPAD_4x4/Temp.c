void KeyPad4x4_VidFullcalculator(void)
{
LCD_VidWriteData(CLRDisplay);
	_delay_ms(100);
	LCD_VidSetPosition(0,0);
	LCD_VidWriteString("calculate");
	//u8 Array[10];
	volatile u8 Index = 0;
	volatile u8 Button = 0xFF;
	volatile u32 Num1 =0;
	volatile u32 Num2 =0;
	volatile u32 Result =0;
	volatile u32 Temp = 0;
	volatile u8 SignFlag = 0;
	// go to position will write at LCD
	LCD_VidSetPosition(1,0);
	LCD_VidWriteString("                ");
	LCD_VidSetPosition(1,0);
	//LCD_VidWriteData(CursorOn);
	//loop and get all pressed keys then save it in array with limited length till press enter (ex keyBB15)

	while (Button  != KeyB13 )
	{
		Button = KeyPad_4x4_u8ButtonPressed();
		if (Button !=0)
		{
			//Array[Index]= Button;
			if (Button == KeyB4 )
			{
				LCD_VidWriteData('+');
				Num1 = Temp;
				Temp = 0;
				SignFlag = 1;
				Index = 0;
			}
			else if (Button == KeyB8 )
			{
				LCD_VidWriteData('-');
				Num1 = Temp;
				Temp = 0;
				SignFlag = 2;
				Index = 0;
			}
			else if (Button == KeyB12 )
			{
				LCD_VidWriteData('x');
				Num1 = Temp;
				Temp = 0;
				SignFlag = 3;
				Index = 0;
			}
			else if (Button == KeyB16 )
			{
				LCD_VidWriteData('/');
				Num1 = Temp;
				Temp = 0;
				SignFlag = 4;
				Index = 0;
			}
			else if (Button == KeyB15 )
			{
				LCD_VidWriteData('=');
				Num2 = Temp;

			}
			else if (Button == KeyB13 )
			{
				LCD_VidWriteData('=');
				Num2 = Temp;

			}
			else if (Button >0 && Button <=9 )
			{
				LCD_VidWriteNumber(Button);
				Temp = Temp*Index*10 + Button;
				Index++;

			}
		}

	}
	switch (SignFlag)
	{
	case 1 : Result = Num1 + Num2; LCD_VidWriteNumber(Result); break;
	case 2 : Result = Num1 - Num2; LCD_VidWriteNumber(Result); break;
	case 3 : Result = Num1 * Num2; LCD_VidWriteNumber(Result); break;
	case 4 : Result = Num1 / Num2; LCD_VidWriteNumber(Result); break;
	}
	}
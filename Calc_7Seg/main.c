/*
 * main.c
 *
 *  Created on: May 15, 2020
 *      Author: MGIsmail
 */

#include <avr/io.h>
#include <util/delay.h>
#define SET_bit(var, bit_no)		var = (1<<bit_no)|var
#define CLR_bit(var, bit_no)		var =( ~(1<<bit_no))&var
#define Zero		0b11000000//0
#define One			0b11111001//1
#define Two			0b10100100//2
#define Three		0b10110000//3
#define Four		0b10011001//4
#define Five		0b10010010//5
#define Six			0b10000010//6
#define Seven		0b11111000//7
#define Eight		0b10000000//8
#define Nine		0b10010000//9

void Disp_7Seg_LED(int num,int LED);
void sub (int num1, int num2);
void add (int num1, int num2);
void mul (int num1, int num2);
void div (int num1, int num2);
char _7Seg_array[10]={Zero, One, Two, Three, Four, Five, Six, Seven, Eight, Nine};

int main (void)
{

	DDRA=0xFF;
	DDRC=0xFF;
	DDRB=0b00000011;

	PORTB=0x00;

	while (1)
	{
		add(22,33);
		sub(88,55);
		mul(7,8);
		div(99,3);
	}

}

void add (int num1, int num2)
{

	PORTA=0x00;
	SET_bit(PORTA, 7);
	Disp_7Seg_LED(num1,0);
	Disp_7Seg_LED(num2,1);
	int Sum = num1 + num2;
	Disp_7Seg_LED(Sum,2);
	PORTA=0x00;
}
void sub (int num1, int num2)
{

	PORTA=0x00;
	SET_bit(PORTA, 6);
	Disp_7Seg_LED(num1,0);
	Disp_7Seg_LED(num2,1);
	int Sub = num1 - num2;
	Disp_7Seg_LED(Sub,2);
	PORTA=0x00;
}
void mul (int num1, int num2)
{

	PORTA=0x00;
	SET_bit(PORTA, 5);
	Disp_7Seg_LED(num1,0);
	Disp_7Seg_LED(num2,1);
	int Mul = num1 * num2;
	if (Mul >99)
	{
		SET_bit(PORTA, 3);
		_delay_ms(500);
	}
	else
	{
		Disp_7Seg_LED(Mul,2);
	}

	PORTA=0x00;
}
void div (int num1, int num2)
{

	PORTA=0x00;
	SET_bit(PORTA, 4);
	Disp_7Seg_LED(num1,0);
	Disp_7Seg_LED(num2,1);
	int Div = num1 / num2;
	if (Div < 0)
	{
		SET_bit(PORTA, 3);
		_delay_ms(500);
	}
	else
	{
		Disp_7Seg_LED(Div,2);
	}

	PORTA=0x00;
}
void Disp_7Seg_LED(int num, int LED)
{
	SET_bit(PORTA, LED);
	int i = 0;
	int j = 0;
	if (num <=9)
	{
		i = 0;
		j = num;
	}
	else
	{
		i = num /10;
		j = num % 10;
	}

	for (char z=0; z<100; z++)
	{
		SET_bit(PORTB, 0);
		PORTC=_7Seg_array[j];
		_delay_ms(10);
		CLR_bit(PORTB, 0);
		SET_bit(PORTB, 1);
		PORTC=_7Seg_array[i];
		_delay_ms(10);
		CLR_bit(PORTB, 1);
	}
	CLR_bit(PORTA, LED);
}

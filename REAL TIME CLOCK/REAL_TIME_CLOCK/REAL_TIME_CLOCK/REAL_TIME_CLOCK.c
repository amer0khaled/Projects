/*
 * REAL_TIME_CLOCK.c
 *
 * Created: 2/19/2023 10:14:57 PM
 *  Author: amrkh
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"
#include "SEVEN-SEGMENT.h"
#include "KEYPAD.h"
#include "TIMER0.h"
#include "TIMER2.h"
#include "STD_MACROS.h"

volatile unsigned char second_counter = 0;
volatile unsigned char flag = 0;
unsigned char min_counter = 0;
unsigned char hour_counter = 0;

unsigned char value_keypad,first_digit,second_digit;

int main(void)
{
	LCD_INIT();
	SEVEN_SEGMENT_INIT('b');
	KEYPAD_INIT('d');

	SET_BIT(DDRC,0);
	SET_BIT(DDRC,1);
	SET_BIT(DDRC,2);
	SET_BIT(DDRC,3);
	SET_BIT(DDRC,4);
	SET_BIT(DDRC,5);

	LCD_SEND_STRING("Click 1 To Set");
	LCD_MOVE_CURSOR(2, 1);
	LCD_SEND_STRING("Click 2 To Reset");

	TIMER0_CTC_INIT_INTERRUPT();
	TIMER2_OVF_INTERRUPT_INIT();


	while(1)
	{
		value_keypad = KEYPAD_READ('d');

		if (value_keypad != NOT_PRESSED)
		{
			if (value_keypad == '1')
			{

				LCD_SEND_CMD(CLEAR_SCREEN);
				LCD_SEND_STRING("Enter The Hour :");
				LCD_MOVE_CURSOR(2, 1);
				_delay_ms(500);

				do
				{
					first_digit = KEYPAD_READ('d');

				}
				while (first_digit == NOT_PRESSED);

				LCD_SEND_CHAR(first_digit);
				_delay_ms(300);

				do
				{
					second_digit = KEYPAD_READ('d');

				}
				while (second_digit == NOT_PRESSED);

				LCD_SEND_CHAR(second_digit);
				_delay_ms(300);

				hour_counter = ((first_digit-48) * 10) + (second_digit-48);

				LCD_SEND_CMD(CLEAR_SCREEN);
				LCD_SEND_STRING("Enter The Minute :");
				LCD_MOVE_CURSOR(2, 1);
				_delay_ms(500);

				do
				{
					first_digit = KEYPAD_READ('d');

				}
				while (first_digit == NOT_PRESSED);

				LCD_SEND_CHAR(first_digit);
				_delay_ms(300);


				do
				{
					second_digit = KEYPAD_READ('d');

				}
				while (second_digit == NOT_PRESSED);

				LCD_SEND_CHAR(second_digit);
				_delay_ms(300);

				min_counter = ((first_digit-48) * 10) + (second_digit-48);

				LCD_SEND_CMD(CLEAR_SCREEN);
				LCD_SEND_STRING("Enter The Second :");
				LCD_MOVE_CURSOR(2, 1);
				_delay_ms(500);


				do
				{
					first_digit = KEYPAD_READ('d');

				}
				while (first_digit == NOT_PRESSED);

				LCD_SEND_CHAR(first_digit);
				_delay_ms(300);

				do
				{
					second_digit = KEYPAD_READ('d');

				}
				while (second_digit == NOT_PRESSED);

				LCD_SEND_CHAR(second_digit);
				_delay_ms(300);

				second_counter = ((first_digit-48) * 10) + (second_digit-48);

				LCD_SEND_CMD(CLEAR_SCREEN);
				LCD_SEND_STRING("Click 1 To Set");
				LCD_MOVE_CURSOR(2, 1);
				LCD_SEND_STRING("Click 2 To Reset");


			}
			else if (value_keypad == '2')
			{	
				second_counter = 0;
				min_counter = 0;
				hour_counter = 0;
				
				LCD_SEND_CMD(CLEAR_SCREEN);
				LCD_SEND_STRING("The Clock has");
				LCD_MOVE_CURSOR(2 , 1);
				LCD_SEND_STRING("been reset.");
				_delay_ms(500);
				LCD_SEND_CMD(CLEAR_SCREEN);
				LCD_SEND_STRING("Click 1 To Set");
				LCD_MOVE_CURSOR(2, 1);
				LCD_SEND_STRING("Click 2 To Reset");
			}
			else
			{
				LCD_SEND_CMD(CLEAR_SCREEN);
				LCD_SEND_STRING("Wrong Choice");
				_delay_ms(1000);
				LCD_SEND_CMD(CLEAR_SCREEN);
				LCD_SEND_STRING("Click 1 To Set");
				LCD_MOVE_CURSOR(2, 1);
				LCD_SEND_STRING("The Clock...");
			}

		}

		CLEAR_BIT(PORTC, 0);
		SET_BIT(PORTC, 1);
		SET_BIT(PORTC, 2);
		SET_BIT(PORTC, 3);
		SET_BIT(PORTC, 4);
		SET_BIT(PORTC, 5);
		SEVEN_SEGMENT_WRITE('B',second_counter%10);
		while(flag == 0);
		flag = 0;



		CLEAR_BIT(PORTC, 1);
		SET_BIT(PORTC, 0);
		SET_BIT(PORTC, 2);
		SET_BIT(PORTC, 3);
		SET_BIT(PORTC, 4);
		SET_BIT(PORTC, 5);
		SEVEN_SEGMENT_WRITE('B',second_counter/10);
		while(flag == 0);
		flag = 0;


		CLEAR_BIT(PORTC, 2);
		SET_BIT(PORTC, 0);
		SET_BIT(PORTC, 1);
		SET_BIT(PORTC, 3);
		SET_BIT(PORTC, 4);
		SET_BIT(PORTC, 5);
		SEVEN_SEGMENT_WRITE('B',min_counter%10);
		while(flag == 0);
		flag = 0;


		CLEAR_BIT(PORTC, 3);
		SET_BIT(PORTC, 0);
		SET_BIT(PORTC, 2);
		SET_BIT(PORTC, 1);
		SET_BIT(PORTC, 4);
		SET_BIT(PORTC, 5);
		SEVEN_SEGMENT_WRITE('B',min_counter/10);
		while(flag == 0);
		flag = 0;


		CLEAR_BIT(PORTC, 4);
		SET_BIT(PORTC, 0);
		SET_BIT(PORTC, 2);
		SET_BIT(PORTC, 3);
		SET_BIT(PORTC, 1);
		SET_BIT(PORTC, 5);
		SEVEN_SEGMENT_WRITE('B',hour_counter%10);
		while(flag == 0);
		flag = 0;


		CLEAR_BIT(PORTC, 5);
		SET_BIT(PORTC, 0);
		SET_BIT(PORTC, 2);
		SET_BIT(PORTC, 3);
		SET_BIT(PORTC, 4);
		SET_BIT(PORTC, 1);
		SEVEN_SEGMENT_WRITE('B',hour_counter/10);
		while(flag == 0);
		flag = 0;



		if (second_counter > 59)
		{
			second_counter = 0;
			min_counter++;
		}
		if (min_counter > 59)
		{
			min_counter = 0;
			hour_counter++;
		}
		if (hour_counter > 23)
		{
			hour_counter = 0;
		}


	}
}

ISR(TIMER2_OVF_vect)
{
	second_counter++;

}

ISR(TIMER0_COMP_vect)
{
	flag = 1;
}
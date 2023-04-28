/*
 * TRAFFIC_LIGHT.c
 *
 * Created: 2/17/2023 10:02:28 PM
 *  Author: amrkh
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "SEVEN-SEGMENT.h"
#include "LED.h"
#include "TIMER0.h"

volatile unsigned char flag_green = 10;
volatile unsigned char flag_yellow = 5;
volatile unsigned char flag_red = 7;
volatile unsigned char counter = 0;
unsigned char flag = 0;

int main(void)
{
	LED_INIT('d',0);
	LED_INIT('d',1);
	LED_INIT('d',2);
	TIMER0_CTC_INIT_INTERRUPT();
	SEVEN_SEGMENT_INIT('c');

	while(1)
	{
		if (flag == 0)
		{	
			LED_OFF('d',1);
			LED_OFF('d',2);
			LED_ON('d',0);

			if (counter >= 100)
			{
				flag_green--;
				counter = 0;
			}

			SEVEN_SEGMENT_WRITE('c',flag_green);

			if(flag_green == 0)
			{
				flag = 1;
				flag_green = 10;
			}

		}
		else if(flag == 1)
		{
			LED_OFF('d',0);
			LED_OFF('d',2);
			LED_ON('D',1);

			if(counter >= 100)
			{
				flag_yellow--;
				counter = 0;
			}

			SEVEN_SEGMENT_WRITE('c',flag_yellow);

			if (flag_yellow == 0)
			{
				flag = 2;
				flag_yellow = 5;

			}


		}
		else if (flag == 2)
		{	
			LED_OFF('d',0);
			LED_OFF('d',1);
			LED_ON('d',2);

			if (counter == 100)
			{
				flag_red--;
				counter = 0;
			}

			SEVEN_SEGMENT_WRITE('c',flag_red);

			if (flag_red == 0)
			{
				flag = 0;
				flag_red = 7;
			}

		}

	}
}

ISR(TIMER0_COMP_vect)
{
	counter++;
}


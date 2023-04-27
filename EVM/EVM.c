/*
 * EVM.c
 *
 * Created: 12/7/2022 6:16:01 AM
 *  Author: amrkh
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"


int main(void)
{	
	 /*lcd 4 bit initialization*/
	 
	 label:LCD_INIT();
	 
	/* button intialization and active internal pull up */
	
	button_init('d',3);
	button_init('d',4);
	button_init('d',5);
	button_init('d',6);
	button_init('d',7);
	
	unsigned short a=0,b=0,c=0,d=0; //as counters for 4 candidates
	
	LCD_SEND_STRING("A=0");
	LCD_MOVE_CURSOR(1,12);
	LCD_SEND_STRING("B=0");
	LCD_MOVE_CURSOR(2,1);
	LCD_SEND_STRING("C=0");
	LCD_MOVE_CURSOR(2,12);
	LCD_SEND_STRING("D=0");
	
    while(1)
    {	
			
		if (button_read('d',4) == 0)
		{
			a++;
			
			LCD_MOVE_CURSOR(1,3);
			if (a<10)
			{
				LCD_SEND_CHAR(' ');
				LCD_SEND_CHAR(' ');
				LCD_SEND_CHAR(a+48);
			}
			else if ((a<100)&&(a>9))
			{	
				LCD_SEND_CHAR(' ');
				LCD_SEND_CHAR((a/10)+48);
				LCD_SEND_CHAR((a%10)+48);
			}
			else if ((a<1000)&&(a>99))
			{
				LCD_SEND_CHAR((a/100)+48);
				LCD_SEND_CHAR(((a/10)%10)+48);
				LCD_SEND_CHAR((a%10)+48);
			}
			
			while(button_read('d',4) == 0);
		}
		
		else if (button_read('d',5) == 0)
		{
			b++;
			LCD_MOVE_CURSOR(1,14);
			
			if (b<10)
			{	
				LCD_SEND_CHAR(' ');
				LCD_SEND_CHAR(' ');
				LCD_SEND_CHAR(b+48);
			}
			else if ((b<100)&&(b>9))
			{	
				LCD_SEND_CHAR(' ');
				LCD_SEND_CHAR((b/10)+48);
				LCD_SEND_CHAR((b%10)+48);
			}
			else if ((b>99)&&(b<1000))
			{
				LCD_SEND_CHAR((b/100)+48);
				LCD_SEND_CHAR(((b/10)%10)+48);
				LCD_SEND_CHAR((b%10)+48);
			}
			
			while(button_read('d',5) == 0);
		}
		
		else if(button_read('d',6) == 0)
		{
			c++;
			LCD_MOVE_CURSOR(2,3);
			
			if (c<10)
			{	
				LCD_SEND_CHAR(' ');
				LCD_SEND_CHAR(' ');
				LCD_SEND_CHAR(c+48);
			}
			else if ((c<100)&&(c>9))
			{	
				LCD_SEND_CHAR(' ');
				LCD_SEND_CHAR((c/10)+48);
				LCD_SEND_CHAR((c%10)+48);
			}
			else if ((c>99)&&(c<1000))
			{
				LCD_SEND_CHAR((c/100)+48);
				LCD_SEND_CHAR(((c/10)%10)+48);
				LCD_SEND_CHAR((c%10)+48);
			}
			
			while(button_read('d',6) == 0);
		}
		
		else if (button_read('d',7) == 0)
		{
			d++;
			LCD_MOVE_CURSOR(2,14);
			
			if (d<10)
			{	
				LCD_SEND_CHAR(' ');
				LCD_SEND_CHAR(' ');
				LCD_SEND_CHAR(d+48);
			}
			else if ((d<100)&&(d>9))
			{	
				LCD_SEND_CHAR(' ');
				LCD_SEND_CHAR((d/10)+48);
				LCD_SEND_CHAR((d%10)+48);
			}
			else if ((d>99)&&(d<1000))
			{
				LCD_SEND_CHAR((d/100)+48);
				LCD_SEND_CHAR(((d/10)%10)+48);
				LCD_SEND_CHAR((d%10)+48);
			}
			
			while(button_read('d',7) == 0);
		}
		
		else if (button_read('d',3) == 0)
		{	
		
			goto label;
			
		}
		//_delay_ms(200);
        
    }
}
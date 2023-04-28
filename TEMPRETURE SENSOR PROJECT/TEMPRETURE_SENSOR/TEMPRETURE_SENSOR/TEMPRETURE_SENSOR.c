/*
 * TEMPRETURE_SENSOR.c
 *
 * Created: 2/14/2023 4:19:01 PM
 *  Author: amrkh
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"
#include "ADC.h"
#define STEP 0.0025

int main(void)
{	
	LCD_INIT();
	ADC_INIT();
	
	 int volt_in_mv;
	 int temp;
	
	LCD_SEND_STRING("tempreture=");
	
    while(1)
    {	
		LCD_SEND_CMD(DISPLAY_ON_CURSOR_OFF);
         volt_in_mv = ADC_READ() * STEP * 1000;
		 
		 if (volt_in_mv >= 1000)
		 {
			 temp = (volt_in_mv - 1000)/10;
			 
			 
			 if (temp <= 9)
			 {
				 LCD_MOVE_CURSOR(1 , 12);
				 LCD_SEND_CHAR(temp+48);
				 LCD_SEND_CHAR(0x10);
				 LCD_SEND_CHAR(0XDF);
				 LCD_SEND_CHAR('C');
				 LCD_SEND_CHAR(0x10);
				 
			 }
			 else if ((temp > 9)&&(temp < 100))
			 {
				 LCD_MOVE_CURSOR(1 , 12);
				 LCD_SEND_CHAR((temp/10)+48);
				 LCD_SEND_CHAR((temp%10)+48);
				 LCD_SEND_CHAR(' ');
				 LCD_SEND_CHAR(0XDF);
				 LCD_SEND_CHAR('C');
				 
			 }
			 else if (temp >99)
			 {
		
				 LCD_MOVE_CURSOR(1 , 12);
				 LCD_SEND_CHAR((temp/100)+48);
				 LCD_SEND_CHAR(((temp/10)%10)+48);
				 LCD_SEND_CHAR((temp%10)+48);
				 LCD_SEND_CHAR(0XDF);
				 LCD_SEND_CHAR('C');
				 
			 }
			 
		 }
		 else if (volt_in_mv < 1000)
		 {
			 temp = (1000 - volt_in_mv)/10;
			 
			 if (temp <= 9)
			 {	
				 LCD_MOVE_CURSOR(1 , 12);
				 LCD_SEND_CHAR('-');
				 LCD_SEND_CHAR(temp+48);
				 LCD_SEND_CHAR(0x10);
				 LCD_SEND_CHAR(0XDF);
				 LCD_SEND_CHAR('C');
				 LCD_SEND_CHAR(0x10);
				 
			 }
			 else if (temp > 9)
			 {	
				 LCD_MOVE_CURSOR(1 , 12);
				 LCD_SEND_CHAR('-');
				 LCD_SEND_CHAR((temp/10)+48);
				 LCD_SEND_CHAR((temp%10)+48);
				 
				 LCD_SEND_CHAR(0XDF);
				 LCD_SEND_CHAR('C');
				 
			 }
			
		 }
		 
    }
}
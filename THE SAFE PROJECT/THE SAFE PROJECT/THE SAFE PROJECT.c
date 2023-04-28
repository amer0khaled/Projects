/*
 * THE_SAFE_PROJECT.c
 *
 * Created: 12/8/2022 6:54:13 AM
 *  Author: amrkh
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "led.h"
#include "LCD.h"
#include "KEYPAD.h"
#include "EEPROM_DRIVER.h"

#define EEPROM_FLAG 0x0a
#define EEPROM_PASSWORD_LOCATION1 0x0b
#define EEPROM_PASSWORD_LOCATION2 0x0c
#define EEPROM_PASSWORD_LOCATION3 0x0d
#define EEPROM_PASSWORD_LOCATION4 0x0e
#define MAX_TRIES 3

unsigned char check_pass[4];
unsigned char correct_pass;
unsigned char i;
unsigned char try=MAX_TRIES;
int main(void)
{	
	LCD_INIT();
	KEYPAD_INIT();
	led_init('b',0);
	led_init('b',1);
	
	unsigned char val;
	
    while(1)
    {
        if (EEPROM_READ(EEPROM_FLAG) == 0xff) // set password for first time
        {
			LCD_SEND_STRING("SET PASS:");
			
			for(i=0;i<4;i++)
			{	
				do 
				{
					val=KEYPAD_READ();
					
				} while (val == NOT_PRESSED);
				
				EEPROM_WRITE(EEPROM_PASSWORD_LOCATION1+i , val);
				LCD_SEND_CHAR(val);
				_delay_ms(500);
				LCD_MOVE_CURSOR(1,10+i);
				LCD_SEND_CHAR('*');
				_delay_ms(500);
				
				EEPROM_WRITE(EEPROM_FLAG , 0x00);
				
			}
        }
		
		
		while (correct_pass == 0)
		{	
			LCD_CLEAR_SCREEN();
			LCD_SEND_STRING("check pass:");
			for (i=0;i<4;i++)
			{
				do 
				{
					check_pass[i]=KEYPAD_READ();
					
				} while (check_pass[i] == NOT_PRESSED);
				
				LCD_SEND_CHAR(check_pass[i]);
				_delay_ms(500);
				LCD_MOVE_CURSOR(1,12+i);
				LCD_SEND_CHAR('*');
				_delay_ms(500);
				
			}
			
			
			if ((check_pass[0]==EEPROM_READ(EEPROM_PASSWORD_LOCATION1))&&(check_pass[1]==EEPROM_READ(EEPROM_PASSWORD_LOCATION2))&&(check_pass[2]==EEPROM_READ(EEPROM_PASSWORD_LOCATION3))&&(check_pass[3]==EEPROM_READ(EEPROM_PASSWORD_LOCATION4)))
			{
				
				LCD_CLEAR_SCREEN();
				LCD_SEND_STRING("CORRECT PASS");
				LCD_MOVE_CURSOR(2,1);
				LCD_SEND_STRING("SAFE OPEN");
				led_on('b',0);
				_delay_ms(1000);
				led_off('b',0);
				correct_pass=1;
			}
			else
			{	
				try--;
				
				if(try>0)
				{
					LCD_CLEAR_SCREEN();
					LCD_SEND_STRING("WRONG PASS");
					LCD_MOVE_CURSOR(2,1);
					LCD_SEND_STRING("TRIES LEFT:");
					LCD_SEND_CHAR(try+48);
					led_on('b',1);
					_delay_ms(1500);
					led_off('b',1);
				}
				else
				{
					LCD_CLEAR_SCREEN();
					LCD_SEND_STRING("WRONG PASS");
					LCD_MOVE_CURSOR(2,1);
					LCD_SEND_STRING("SAFE CLOSED");
					correct_pass=1;
				}
				
				
				
				
				
				
			}
			
			
		}
		
		
		
		
		
    }
}
/*
 * LCD.c
 *
 * Created: 10/19/2022 7:09:54 PM
 *  Author: amrkh
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO.h"
#include "LCD.h"

void LCD_INIT(void)
{
	_delay_ms(100);
	
	#if defined EIGHT_BIT_MODE
	
	DIO_SET_PORT_DIR(DATA_PORT,0xff);
	
	DIO_SET_PIN_DIR(CTR_PORT,EN,1);
	DIO_SET_PIN_DIR(CTR_PORT,RW,1);
	DIO_SET_PIN_DIR(CTR_PORT,RS,1);
	
	DIO_WRITE_PIN(CTR_PORT,RW,0);
	
	
	LCD_SEND_CMD(EIGHT_BITS);
	_delay_ms(1);
	LCD_SEND_CMD(CURSOR_ON_DISPLAY_ON);
	_delay_ms(1);
	LCD_SEND_CMD(CLEAR_SCREEN);
	_delay_ms(5);
	LCD_SEND_CMD(ENTRY_MODE);
	_delay_ms(1);
	
	#elif defined FOUR_BIT_MODE
	
	DIO_SET_PIN_DIR(DATA_PORT,4,1);
	DIO_SET_PIN_DIR(DATA_PORT,5,1);
	DIO_SET_PIN_DIR(DATA_PORT,6,1);
	DIO_SET_PIN_DIR(DATA_PORT,7,1);
	
	DIO_SET_PIN_DIR(CTR_PORT,EN,1);
	DIO_SET_PIN_DIR(CTR_PORT,RW,1);
	DIO_SET_PIN_DIR(CTR_PORT,RS,1);
	
	DIO_WRITE_PIN(CTR_PORT,RW,0);
	
	
	LCD_SEND_CMD(RETURN_HOME);
	_delay_ms(10);
	LCD_SEND_CMD(FOUR_BITS);
	_delay_ms(1);
	LCD_SEND_CMD(CURSOR_ON_DISPLAY_ON);
	_delay_ms(1);
	LCD_SEND_CMD(CLEAR_SCREEN);
	_delay_ms(5);
	LCD_SEND_CMD(ENTRY_MODE);
	_delay_ms(1);
	#endif
	
	
}


void LCD_ENABLE(void)
{
	DIO_WRITE_PIN(CTR_PORT,EN,1);
	_delay_ms(2);
	DIO_WRITE_PIN(CTR_PORT,EN,0);
	_delay_ms(2);
}


void LCD_SEND_CHAR(unsigned char data)
{	
	#if defined EIGHT_BIT_MODE
	
	DIO_WRITE_PIN(CTR_PORT,RW,0);
	DIO_WRITE_PORT(DATA_PORT,data);
	DIO_WRITE_PIN(CTR_PORT,RS,1);
	LCD_ENABLE();

	#elif defined FOUR_BIT_MODE
	
	DIO_WRITE_PIN(CTR_PORT,RW,0);
	
	DIO_write_HIGH_nibble(DATA_PORT,data>>4);
	DIO_WRITE_PIN(CTR_PORT,RS,1);
	LCD_ENABLE();
	
	DIO_write_HIGH_nibble(DATA_PORT,data);
	DIO_SET_PIN_DIR(CTR_PORT,RS,1);
	LCD_ENABLE();
	#endif
	
	_delay_ms(1);

}


void LCD_SEND_CMD(unsigned char cmd)
{	
	#if defined EIGHT_BIT_MODE
	
	DIO_WRITE_PIN(CTR_PORT,RW,0);
	DIO_WRITE_PORT(DATA_PORT,cmd);
	DIO_WRITE_PIN(CTR_PORT,RS,0);
	LCD_ENABLE();
	_delay_ms(1);
	
	#elif defined FOUR_BIT_MODE

	DIO_SET_PIN_DIR(CTR_PORT,RW,0);
	DIO_write_HIGH_nibble(DATA_PORT,cmd>>4);
	DIO_WRITE_PIN(CTR_PORT,RS,0);
	LCD_ENABLE();
	
	DIO_write_HIGH_nibble(DATA_PORT,cmd);
	DIO_WRITE_PIN(CTR_PORT,RS,0);
	LCD_ENABLE();
	
	_delay_ms(1);
	#endif
}


void LCD_CLEAR_SCREEN(void)
{
	LCD_SEND_CMD(0x01);
}

void LCD_SEND_STRING(unsigned char *data)
{
	while(*data != '\0')
	{
		LCD_SEND_CHAR(*data);
		data++;
	}
	
}

void LCD_MOVE_CURSOR(unsigned char row, unsigned char col)
{
	unsigned data;
	
	if((row>2)||(row<1)||(col>16)||(col<1))
	{
		data=0x80;
	}
	else if(row==1)
	{
		data=0x80+col-1;
	}
	else if(row==2)
	{
		data=0xc0+col-1;
	}
	
	LCD_SEND_CMD(data);
	_delay_ms(1);
}

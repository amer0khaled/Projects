/*
 * LCD.h
 *
 * Created: 10/19/2022 8:39:06 PM
 *  Author: amrkh
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "LCD_CONFIGRATION.h"

#define  CLEAR_SCREEN 0x01

#define RETURN_HOME 0x02

#define ENTRY_MODE 0x06

#define CURSOR_ON_DISPLAY_ON 0x0e

#define CURSOR_OFF_DISPLAY_OFF 0x08

#define CURSOR_ON_DISPLAY_OFF 0x0a

#define CURSOR_OFF_DISPLAY_ON 0x0c

#define CURSOR_BLINKING_DISPLAY_ON 0x0f

#if defined EIGHT_BIT_MODE
#define EIGHT_BITS 0x38

#elif defined FOUR_BIT_MODE
#define FOUR_BITS 0x28

#endif
//////////////////////////////////////////////////

void LCD_INIT(void);

void LCD_ENABLE(void);

void LCD_SEND_CHAR(unsigned char data);

void LCD_SEND_CMD(unsigned char cmd);

void LCD_CLEAR_SCREEN(void);

void LCD_SEND_STRING(unsigned char *data);

void LCD_MOVE_CURSOR(unsigned char row, unsigned char col);

#endif /* LCD_H_ */
/*
 * KEYPAD.c
 *
 * Created: 2/9/2023 4:13:32 PM
 *  Author: amrkh
 */ 


#include "KEYPAD.h"

void KEYPAD_INIT(unsigned char port)
{	
	
	/*rows output*/
	DIO_SET_PIN_DIR(port , 0 , 1);
	DIO_SET_PIN_DIR(port , 1 , 1);
	DIO_SET_PIN_DIR(port , 2 , 1);
	DIO_SET_PIN_DIR(port , 3 , 1);
	
	/*col input*/
	DIO_SET_PIN_DIR(port , 4 , 0);
	DIO_SET_PIN_DIR(port , 5 , 0);
	DIO_SET_PIN_DIR(port , 6 , 0);
	DIO_SET_PIN_DIR(port , 7 , 0);
	
	/*active internal pull up for input col*/
	DIO_ACTIVE_INTERNAL_PULL_UP(port , 4);
	DIO_ACTIVE_INTERNAL_PULL_UP(port , 5);
	DIO_ACTIVE_INTERNAL_PULL_UP(port , 6);
	DIO_ACTIVE_INTERNAL_PULL_UP(port , 7);
	
}

unsigned char KEYPAD_READ(unsigned char port)
{
	unsigned char row,col;
	unsigned char return_value = NOT_PRESSED;
	
	unsigned char arr[4][4] = {{'7','8','9','/'} , {'4','5','6','*'} , {'1','2','3','-'} , {'A','0','=','+'}};
	
	for (row = 0; row < 4; row++)
	{
		DIO_WRITE_PIN(port , 0 , 1);
		DIO_WRITE_PIN(port , 1 , 1);
		DIO_WRITE_PIN(port , 2 , 1);
		DIO_WRITE_PIN(port , 3 , 1);
		
		DIO_WRITE_PIN(port , row , 0);
		
		for (col = 0; col < 4; col++)
		{
			if (DIO_READ_PIN(port , col+4) == 0)
			{
				return_value = arr[row][col];
				break;
			}
		}
		
		if (return_value != NOT_PRESSED)
		{
			break;
		}
		
	}
	
	
	return return_value;
	
}

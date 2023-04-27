/*
 * KEYPAD.c
 *
 * Created: 10/22/2022 3:57:32 PM
 *  Author: amrkh
 */ 

#include "DIO.h"

void KEYPAD_INIT(void)
{
	unsigned char i;
	
	for(i=0;i<4;i++)
	{
		DIO_SET_PIN_DIR(KEYPAD_PORT,i,1);
	}
	
	for(i=4;i<=7;i++)
	{
		DIO_SET_PIN_DIR(KEYPAD_PORT,i,0);
		DIO_CONNECT_PULL_UP(KEYPAD_PORT,i,1);
	}
}


unsigned char KEYPAD_READ(void)
{
	unsigned char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
		unsigned char row,col,x;
		unsigned char return_val=NOT_PRESSED;
		
		for(row=0;row<4;row++)
		{
			DIO_WRITE_PIN(KEYPAD_PORT,0,1);
			DIO_WRITE_PIN(KEYPAD_PORT,1,1);
			DIO_WRITE_PIN(KEYPAD_PORT,2,1);
			DIO_WRITE_PIN(KEYPAD_PORT,3,1);
			
			DIO_WRITE_PIN(KEYPAD_PORT,row,0);
			
			for(col=0;col<4;col++)
			{
				x=DIO_READ_PIN(KEYPAD_PORT,(col+4));
				
				if(x==0)
				{
					return_val=arr[row][col];
					break;
				}
			}
			
			if(x==1)
			{
				break;
			}
			
			
			
		}
		
		return return_val;
		
}
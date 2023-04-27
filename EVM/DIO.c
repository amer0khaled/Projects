/*
 * DIO.c
 *
 * Created: 9/20/2022 11:55:09 PM
 *  Author: amrkh
 */

#include <avr/io.h>
#include "STD_MACROS.h"

void DIO_SET_PIN_DIR(unsigned char port, unsigned char pin, unsigned char dir)
{
	switch(port)
	{
		case 'a':
		case 'A':
		if(dir==1)
		{
			SET_BIT(DDRA,pin);
		}
		else
		{
			CLR_BIT(DDRA,pin);
		}
		break;

		case 'b':
		case 'B':
		if(dir==1)
		{
			SET_BIT(DDRB,pin);
		}
		else
		{
			CLR_BIT(DDRB,pin);
		}
		break;

		case 'c':
		case 'C':
		if(dir==1)
		{
			SET_BIT(DDRC,pin);
		}
		else
		{
			CLR_BIT(DDRC,pin);
		}
		break;

		case 'd':
		case 'D':
		if(dir==1)
		{
			SET_BIT(DDRD,pin);
		}
		else
		{
			CLR_BIT(DDRD,pin);
		}
		break;


	}
}

void DIO_WRITE_PIN(unsigned char port, unsigned char pin, unsigned char val)
{
	switch(port)
	{
		case 'a':
		case 'A':
		if(val==1)
		{
			SET_BIT(PORTA,pin);
		}
		else
		{
			CLR_BIT(PORTA,pin);
		}
		break;

		case 'b':
		case 'B':
		if(val==1)
		{
			SET_BIT(PORTB,pin);
		}
		else
		{
			CLR_BIT(PORTB,pin);
		}
		break;

		case 'c':
		case 'C':
		if(val==1)
		{
			SET_BIT(PORTC,pin);
		}
		else
		{
			CLR_BIT(PORTC,pin);
		}
		break;

		case 'd':
		case 'D':
		if(val==1)
		{
			SET_BIT(PORTD,pin);
		}
		else
		{
			CLR_BIT(PORTD,pin);
		}
		break;
	}
}

void DIO_TOG_PIN(unsigned char port,unsigned pin)
{
	switch(port)
	{
		case 'a':
		case 'A':
		TOG_BIT(PORTA,pin);
		break;

		case 'b':
		case 'B':
		TOG_BIT(PORTB,pin);
		break;

		case 'c':
		case 'C':
		TOG_BIT(PORTC,pin);
		break;

		case 'D':
		case 'd':
		TOG_BIT(PORTD,pin);
		break;
	}
}

unsigned char DIO_READ_PIN(unsigned char port, unsigned char pin)
{
	unsigned char result;
	switch(port)
	{
		case 'a':
		case 'A':
		result=READ_BIT(PINA,pin);
		break;

		case 'b':
		case 'B':
		result=READ_BIT(PINB,pin);
		break;

		case 'c':
		case 'C':
		result=READ_BIT(PINC,pin);
		break;

		case 'd':
		case 'D':
		result=READ_BIT(PIND,pin);
		break;
	}

	return result;
}

void DIO_SET_PORT_DIR(unsigned char port, unsigned char dir)
{
	switch(port)
	{
		case 'a':
		case 'A':
		DDRA=dir;
		break;

		case 'b':
		case 'B':
		DDRB=dir;
		break;

		case 'c':
		case 'C':
		DDRC=dir;
		break;

		case 'd':
		case 'D':
		DDRD=dir;
		break;
	}
}

void DIO_WRITE_PORT(unsigned char port, unsigned char val)
{
	switch(port)
	{
		case 'a':
		case 'A':
		PORTA=val;
		break;

		case 'b':
		case 'B':
		PORTB=val;
		break;

		case 'c':
		case 'C':
		PORTC=val;
		break;

		case 'd':
		case 'D':
		PORTD=val;
		break;

	}
}

unsigned char DIO_READ_PORT(unsigned char port)
{
	unsigned char result;
	switch(port)
	{
		case 'a':
		case 'A':
		result=PINA;
		break;

		case 'b':
		case 'B':
		result=PINB;
		break;

		case 'c':
		case 'C':
		result=PINC;
		break;

		case 'd':
		case 'D':
		result=PIND;
		break;

	}

	return result;
}

void DIO_TOG_PORT(unsigned char port)
{
	switch(port)
	{
		case 'a':
		case 'A':
		PORTA=~PORTA;
		break;

		case 'b':
		case 'B':
		PORTB=~PORTB;
		break;

		case 'c':
		case 'C':
		PORTC=~PORTC;
		break;

		case 'D':
		case 'd':
		PORTD=~PORTD;
		break;
	}

}


void DIO_CONNECT_PULL_UP(unsigned char port, unsigned char pin, unsigned char val)
{
    switch(port)
    {
        case 'a':
		case 'A':
		if(val==1)
		{
			SET_BIT(PORTA,pin);
		}
		else
		{
			CLR_BIT(PORTA,pin);
		}
		break;

		case 'b':
		case 'B':
		if(val==1)
		{
			SET_BIT(PORTB,pin);
		}
		else
		{
			CLR_BIT(PORTB,pin);
		}
		break;

		case 'c':
		case 'C':
		if(val==1)
		{
			SET_BIT(PORTC,pin);
		}
		else
		{
			CLR_BIT(PORTC,pin);
		}
		break;

		case 'd':
		case 'D':
		if(val==1)
		{
			SET_BIT(PORTD,pin);
		}
		else
		{
			CLR_BIT(PORTD,pin);
		}
		break;
    }
}



void DIO_write_low_nibble(unsigned char port,unsigned val)
{
    val=val&0x0f;

	switch(port)
	{
		case 'a':
		case 'A':
		PORTA=PORTA&0xf0;
		PORTA=PORTA|val;
		break;

		case 'b':
		case 'B':
		PORTB=PORTB&0xf0;
		PORTB=PORTB|val;
		break;

		case 'c':
		case 'C':
		PORTC=PORTC&0xf0;
		PORTC=PORTC|val;
		break;

		case 'D':
		case 'd':
		PORTD=PORTD&0xf0;
		PORTD=PORTD|val;
		break;
	}
}

void DIO_write_HIGH_nibble(unsigned char port, unsigned char val)
{
    val=(val<<4);

    switch(port)
	{
		case 'a':
		case 'A':
		PORTA=PORTA&0x0f;
		PORTA=PORTA|val;
		break;

		case 'b':
		case 'B':
		PORTB=PORTB&0x0f;
		PORTB=PORTB|val;
		break;

		case 'c':
		case 'C':
		PORTC=PORTC&0x0f;
		PORTC=PORTC|val;
		break;

		case 'D':
		case 'd':
		PORTD=PORTD&0x0f;
		PORTD=PORTD|val;
		break;
	}

}


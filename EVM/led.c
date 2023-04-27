/*
 * led.c
 *
 * Created: 9/23/2022 1:55:42 PM
 *  Author: amrkh
 */ 
#include "DIO.h"

void led_init(unsigned char port, unsigned char pin)
{
	DIO_SET_PIN_DIR(port,pin,1);
}

void led_on(unsigned char port, unsigned char pin)
{
	DIO_WRITE_PIN(port,pin,1);
}

void led_off(unsigned char port, unsigned char pin)
{
	DIO_WRITE_PIN(port,pin,0);
}

void led_togg(unsigned char port, unsigned char pin)
{
	DIO_TOG_PIN(port,pin);
}

unsigned char led_read(unsigned char port, unsigned char pin)
{
	return DIO_READ_PIN(port,pin);
}

void led_init_port(unsigned char port)
{
	DIO_SET_PORT_DIR(port,0b11111111);
}

void led_on_port(unsigned char port)
{
	DIO_WRITE_PORT(port,0b11111111);
}

void led_off_port(unsigned char port)
{
	DIO_WRITE_PORT(port,0b00000000);
}

void led_togg_port(unsigned char port)
{
	DIO_TOG_PORT(port);
}

unsigned char led_read_port(unsigned char port)
{
	return DIO_READ_PORT(port);
}

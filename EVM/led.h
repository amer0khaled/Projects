/*
 * led.h
 *
 * Created: 9/23/2022 2:06:18 PM
 *  Author: amrkh
 */ 


#ifndef LED_H_
#define LED_H_

void led_init(unsigned char port, unsigned char pin);

void led_on(unsigned char port, unsigned char pin);

void led_off(unsigned char port, unsigned char pin);

void led_togg(unsigned char port, unsigned char pin);

unsigned char led_read(unsigned char port, unsigned char pin);

void led_init_port(unsigned char port);

void led_on_port(unsigned char port);

void led_off_port(unsigned char port);

void led_togg_port(unsigned char port);

unsigned char led_read_port(unsigned char port);


#endif /* LED_H_ */
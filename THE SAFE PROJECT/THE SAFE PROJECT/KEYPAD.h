/*
 * KEYPAD.h
 *
 * Created: 10/21/2022 7:23:29 PM
 *  Author: amrkh
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "DIO.h"

#define KEYPAD_PORT 'd'

#define NOT_PRESSED 0xff


/////////////////////////////////////////////////


void KEYPAD_INIT(void);

unsigned char KEYPAD_READ(void);


#endif /* KEYPAD_H_ */
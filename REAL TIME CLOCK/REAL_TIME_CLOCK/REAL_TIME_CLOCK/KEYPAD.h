/*
 * KEYPAD.h
 *
 * Created: 2/9/2023 4:13:47 PM
 *  Author: amrkh
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "DIO.h"

#define NOT_PRESSED 0xFF

void KEYPAD_INIT(unsigned char port);

unsigned char KEYPAD_READ(unsigned char port);


#endif /* KEYPAD_H_ */
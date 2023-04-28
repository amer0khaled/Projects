/*
 * EEPROM_DRIVER.h
 *
 * Created: 10/7/2022 7:46:01 PM
 *  Author: amrkh
 */ 


#ifndef EEPROM_DRIVER_H_
#define EEPROM_DRIVER_H_


void EEPROM_WRITE(unsigned short address, unsigned char data);

unsigned char EEPROM_READ(unsigned short address);

#endif /* EEPROM_DRIVER_H_ */
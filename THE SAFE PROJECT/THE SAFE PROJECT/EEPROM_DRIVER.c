/*
 * EEPROM_DRIVER.c
 *
 * Created: 10/7/2022 7:26:21 PM
 *  Author: amrkh
 */ 

#include <avr/io.h>
#include "STD_MACROS.h"

void EEPROM_WRITE(unsigned short address, unsigned char data)
{
	EEARL=(unsigned char)address;
	EEARH=(unsigned char)(address>>8);
	
	EEDR=data;
	
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR,EEWE);
	
	
	while(READ_BIT(EECR,EEWE)==1);
	
}


unsigned char EEPROM_READ(unsigned short address)
{	
	EEARL=(unsigned char)address;
	EEARH=(unsigned char)(address>>8);
	
	SET_BIT(EECR,EERE);
	
	return EEDR;
}
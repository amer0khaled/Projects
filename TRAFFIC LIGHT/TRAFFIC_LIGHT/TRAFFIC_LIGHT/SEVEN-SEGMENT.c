/*
 * _7_SEGMENT.c
 *
 * Created: 1/29/2023 12:35:06 PM
 *  Author: amrkh
 */ 

#include "DIO.h"
#include "SEVEN-SEGMENT.h"

void SEVEN_SEGMENT_INIT(unsigned char port)
{
	DIO_SET_PORT_DIR(port,0xff);
}

void SEVEN_SEGMENT_WRITE(unsigned char port, unsigned char number)
{
	unsigned char data[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x47, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};
	
	#if defined COMMON_CATHODE
	
	DIO_WRITE_PORT(port, data[number]);
	
	#elif defined COMMON_ANODE
	
	DIO_WRITE_PORT(port, ~data[number]);
	
	#endif
	
}
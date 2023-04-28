/*
 * _7_SEGMENT.h
 *
 * Created: 1/29/2023 12:35:31 PM
 *  Author: amrkh
 */ 


#ifndef SEVEN-SEGMENT_H_
#define SEVEN-SEGMENT_H_

#define COMMON_CATHODE

void SEVEN_SEGMENT_INIT(unsigned char port);

void SEVEN_SEGMENT_WRITE(unsigned char port, unsigned char number);

#endif /* SEVEN-SEGMENT_H_ */
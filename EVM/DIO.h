/*
 * DIO.h
 *
 * Created: 9/21/2022 12:46:56 AM
 *  Author: amrkh
 */


#ifndef DIO_H_
#define DIO_H_

void DIO_SET_PIN_DIR(unsigned char port, unsigned char pin, unsigned char dir);

void DIO_WRITE_PIN(unsigned char port, unsigned char pin, unsigned char val);

void DIO_TOG_PIN(unsigned char port,unsigned pin);

unsigned char DIO_READ_PIN(unsigned char port, unsigned char pin);

void DIO_SET_PORT_DIR(unsigned char port, unsigned char dir);

void DIO_WRITE_PORT(unsigned char port, unsigned char val);

unsigned char DIO_READ_PORT(unsigned char port);

void DIO_TOG_PORT(unsigned char port);

void DIO_CONNECT_PULL_UP(unsigned char port, unsigned char pin, unsigned char val);

void DIO_write_low_nibble(unsigned char port,unsigned val);

void DIO_write_HIGH_nibble(unsigned char port, unsigned char val);

#endif /* DIO_H_ */

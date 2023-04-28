/*
 * TIMER2.c
 *
 * Created: 2/19/2023 10:17:11 PM
 *  Author: amrkh
 */ 

#include <avr/io.h>
#include "TIMER2.h"

void TIMER2_OVF_INTERRUPT_INIT()
{
	/*SELECT TIMER CLOCK*/
	SET_BIT(ASSR , AS2);
	
	/*CONF. FREQ TO 128 HZ*/
	SET_BIT(TCCR2 , CS20);
	SET_BIT(TCCR2 , CS22);
	
	/*ENABLE TIMER2 OVERFLOW INTERRUPT*/
	SET_BIT(SREG , I_BIT);
	SET_BIT(TIMSK , TOIE2);
	
	
	
}
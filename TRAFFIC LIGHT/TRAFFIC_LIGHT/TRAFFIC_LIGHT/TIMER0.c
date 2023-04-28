/*
 * TIMER0.c
 *
 * Created: 2/17/2023 4:19:59 PM
 *  Author: amrkh
 */ 

#include "TIMER0.h"
#include <avr/io.h>

void TIMER0_CTC_INIT_INTERRUPT()
{	
	/*CTC MODE ENABLE*/
	SET_BIT(TCCR0 , WGM01);
	
	OCR0 = 80;
	
	/*CONFIGURE CLOCK SELECT PINS*/
	SET_BIT(TCCR0 , CS00);
	SET_BIT(TCCR0 , CS02);
	
	/*SET I BIT*/
	SET_BIT(SREG , I_BIT);
	
	/*SET OUTPUT COMPARE MATCH ENABLE BIT FOR TIMER0*/
	SET_BIT(TIMSK , OCIE0);
	
	
}
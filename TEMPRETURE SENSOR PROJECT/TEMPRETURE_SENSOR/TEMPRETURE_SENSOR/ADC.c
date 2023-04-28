/*
 * ADC.c
 *
 * Created: 2/12/2023 9:01:09 PM
 *  Author: amrkh
 */ 


#include "ADC.h"

void ADC_INIT()
{	
	/*SET VCC TO INTERNAL ADC SUPPLIER 2.56 V*/
	SET_BIT(ADMUX , REFS0);
	SET_BIT(ADMUX , REFS1);
	
	/*DIFFRIENTIAL MODE*/
	SET_BIT(ADMUX , MUX4);
	
	/*SET ADC ENABLE*/
	SET_BIT(ADCSRA , ADEN);
	
	/*CONFIGURE ADC CLOCK TO GET MAX. RESELUTION*/
	SET_BIT(ADCSRA , ADPS1);
	SET_BIT(ADCSRA , ADPS2);
	
}

unsigned short ADC_READ()
{
	unsigned short return_value;
	
	/*set ADC start conversion*/
	SET_BIT(ADCSRA , ADSC);
	
	/*STUCK UNTILL FINISH THE COVERSION*/
	while(READ_BIT(ADCSRA , ADSC) == 1);
	
	return_value = ADCL;
	
	return_value|=(ADCH << 8);
	
	return return_value;
	
}
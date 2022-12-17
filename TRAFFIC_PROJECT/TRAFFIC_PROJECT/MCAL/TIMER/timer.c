/*
 * timer.c
 *
 * Created: 12/7/2022 1:50:51 AM
 *  Author: TAHER ELSHEIKH
 */ 
#include "../MCAL/TIMER/timer.h"
#include <math.h>
//set timer0 in normal mode
void timer0_init(void)
{
	TCCR0=0x00;
}
//    5 SECONEDS delay function with 1024 prescaler 
void timer0_delay_5s(void)
{
	int counter_ovf=0;
	TCNT0=0x00;
	TCCR0 |= (1<<0)| (1<<2);
	while(counter_ovf<19)
	{
		while ((TIFR&(1<<0))==0);
		TIFR |= (1<<0);
		counter_ovf++;
	}
	TCCR0=0x00;
}
//    200m SECONEDS delay function with 1024 prescaler
void timer0_delay_200ms(void)
{
	TCNT0=0x3D;
	TCCR0 |= (1<<0)| (1<<2);
	
		while ((TIFR&(1<<0))==0);
		TIFR |= (1<<0);
		
	TCCR0=0x00;
}
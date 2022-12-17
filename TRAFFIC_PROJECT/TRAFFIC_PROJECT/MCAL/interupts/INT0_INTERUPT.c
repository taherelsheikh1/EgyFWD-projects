/*
 * INT0_INTERUPT.c
 *
 * Created: 12/12/2022 1:18:42 PM
 *  Author: TAHER ELSHEIKH
 */ 
#include "../MCAL/interupts/INT0_INTERUPT.h"
void interupt_INT0_EN(void)
{
	SREG |= (1<<7);//GLOBAL INTERUPS ENABLE
	MCUCR|= (1<<0)|(1<<1);//INTERUPTS SENSE RISING EDGE
	GICR|=(1<<6);//ENABLE INT0 INTERUPT
	 
}

/*
 * INT0_INTERUPT.h
 *
 * Created: 12/12/2022 1:17:53 PM
 *  Author: TAHER ELSHEIKH
 */ 
#include "../UTILITIES/Registers.h"

#ifndef INT0_INTERUPT_H_
#define INT0_INTERUPT_H_

#define EXT_INT_0  __vector_1
#define ISR(INT_VECT) void INT_VECT(void)__attribute__ ((signal,used));\
void INT_VECT (void)

void interupt_INT0_EN(void);

#endif /* INT0_INTERUPT_H_ */
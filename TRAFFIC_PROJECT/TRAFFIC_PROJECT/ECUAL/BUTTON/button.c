/*
 * button.c
 *
 * Created: 12/7/2022 1:52:01 AM
 *  Author: TAHER ELSHEIKH
 */ 
#include "../ECUAL/BUTTON/button.h"


void button_init(uint8_t buttonport,uint8_t buttonpin)
{
	DIO_init(buttonport,buttonpin,IN);
}

void button_state(uint8_t buttonport,uint8_t buttonpin,uint8_t *value)
{
	DIO_read(buttonport,buttonpin,value);
}
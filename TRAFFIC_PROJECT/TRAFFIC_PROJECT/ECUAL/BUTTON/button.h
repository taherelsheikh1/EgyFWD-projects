/*
 * button.h
 *
 * Created: 12/7/2022 1:52:15 AM
 *  Author: TAHER ELSHEIKH
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../MCAL/DIO/DIO.h"

void button_init(uint8_t buttonport,uint8_t buttonpin);

void button_state(uint8_t buttonport,uint8_t buttonpin,uint8_t *value);



#endif /* BUTTON_H_ */
/*
 * led.h
 *
 * Created: 12/7/2022 1:51:38 AM
 *  Author: TAHER ELSHEIKH
 */ 


#ifndef LED_H_
#define LED_H_
#include "../MCAL/DIO/DIO.h"

void led_init(uint8_t ledport ,uint8_t ledpin);
void led_on(uint8_t ledport ,uint8_t ledpin);
void led_off(uint8_t ledport ,uint8_t ledpin);
void led_toggle(uint8_t ledport ,uint8_t ledpin);


#endif /* LED_H_ */
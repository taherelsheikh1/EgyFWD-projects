/*
 * CFile1.c
 *
 * Created: 12/7/2022 1:51:15 AM
 *  Author: TAHER ELSHEIKH
 */ 
#include "../ECUAL/LED/led.h"
#include "../MCAL/DIO/DIO.h"

void led_init(uint8_t ledport ,uint8_t ledpin)
{
	DIO_init(ledport,ledpin,OUT);
}
void led_on(uint8_t ledport ,uint8_t ledpin)
{
	DIO_write(ledport,ledpin,HIGH);
}
void led_off(uint8_t ledport ,uint8_t ledpin)
{
	DIO_write(ledport,ledpin,LOW);
}
void led_toggle(uint8_t ledport ,uint8_t ledpin)
{
	DIO_toggle(ledport,ledpin);
}
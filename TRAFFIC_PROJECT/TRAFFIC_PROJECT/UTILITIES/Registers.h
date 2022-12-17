/*
 * Registers.h
 *
 * Created: 12/7/2022 2:23:37 AM
 *  Author: TAHER ELSHEIKH
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "../UTILITIES/types.h"

                                /*************************************************************************/
								/*                             DIO REGISTERs                             */
								/*************************************************************************/
//PORTA registerS								
#define PORTA *((volatile uint8_t*)0x3B)
#define DDRA *((volatile uint8_t*)0x3A)
#define PINA *((volatile uint8_t*)0x39)
//PORTB registerS
#define PORTB *((volatile uint8_t*)0x38)
#define DDRB *((volatile uint8_t*)0x37)
#define PINB *((volatile uint8_t*)0x36)
//PORTC registerS
#define PORTC *((volatile uint8_t*)0x35)
#define DDRC *((volatile uint8_t*)0x34)
#define PINC *((volatile uint8_t*)0x33)
//PORTD registerS
#define PORTD *((volatile uint8_t*)0x32)
#define DDRD *((volatile uint8_t*)0x31)
#define PIND *((volatile uint8_t*)0x30)

/*************************************************************************/
/*                             timer REGISTERs                             */
/*************************************************************************/

//timer0 registers
#define TCNT0 *((volatile uint8_t*)0x52)
#define TCCR0 *((volatile uint8_t*)0x53)
#define TIFR *((volatile uint8_t*)0x58)
#define TIMSK *((volatile uint8_t*)0x59)

/*************************************************************************/
/*                             SREG REGISTER                            */
/*************************************************************************/
#define SREG *((volatile uint8_t*)0x5F)

/*************************************************************************/
/*                             INT0 (CONTROL-STATUS-FLAG) REGISTERS                            */
/*************************************************************************/
#define MCUCR *((volatile uint8_t*)0x55)
	

#define GICR *((volatile uint8_t*)0x5B)
	

#define GIFR *((volatile uint8_t*)0x5A)

#endif /* REGISTERS_H_ */
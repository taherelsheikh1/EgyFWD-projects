/*
 * DIO.c
 *
 * Created: 12/7/2022 1:50:06 AM
 *  Author: TAHER ELSHEIKH
 */ 
#include "../DIO/DIO.h"

void DIO_init(uint8_t portnumber,uint8_t pinnumber,uint8_t direction)
{
	
	switch(portnumber)
	{
		
		case PORT_A:
		     if(direction==OUT)
		{
			
		    DDRA |=(1<<pinnumber);//SET PIN TO OUTPUT
		
		}
		else if(direction==IN)
		{
		    DDRA &=~(1<<pinnumber);//SET PIN TO input

		}
		else
		{
			//error handling 
		}
		break;
		case PORT_B:
		if(direction==OUT)
		{
			
			DDRB |=(1<<pinnumber);//SET PIN TO OUTPUT
			
		}
		else if(direction==IN)
		{
			DDRB &=~(1<<pinnumber);//SET PIN TO OUTPUT

		}
		else
		{
			//error handling
		}
				break;

		case PORT_C:
		if(direction==OUT)
		{
			
			DDRC |=(1<<pinnumber);//SET PIN TO OUTPUT
			
		}
		else if(direction==IN)
		{
			DDRC &=~(1<<pinnumber);//SET PIN TO OUTPUT

		}
		else
		{
			//error handling
		}
				break;

		case PORT_D:
		if(direction==OUT)
		{
			
			DDRD |=(1<<pinnumber);//SET PIN TO OUTPUT
			
		}
		else if(direction==IN)
		{
			DDRD &=~(1<<pinnumber);//SET PIN TO OUTPUT

		}
		else
		{
			//error handling
		}
				break;

	}
}


void DIO_write(uint8_t portnumber,uint8_t pinnumber,uint8_t value)
{
	
		
		switch(portnumber)
		{
			
			case PORT_A:
			    if(value==HIGH)
			    {
				
				PORTA |=(1<<pinnumber);//SET PIN TO 1
				
			    }
			    else if(value==LOW)
			   {
				PORTA &=~(1<<pinnumber);//SET PIN TO 0
    		   }
			   else
			   {
				//error handling
			   }
			break;
			
			case PORT_B:
			if(value==HIGH)
			{
				
				PORTB |=(1<<pinnumber);//SET PIN TO 1
				
			}
			else if(value==LOW)
			{
				PORTB &=~(1<<pinnumber);//SET PIN TO 0

			}
			else
			{
				//error handling
			}
			break;

			case PORT_C:
			if(value==HIGH)
			{
				
				PORTC |=(1<<pinnumber);//SET PIN TO 1
				
			}
			else if(value==LOW)
			{
				PORTC &=~(1<<pinnumber);//SET PIN TO 0

			}
			else
			{
				//error handling
			}
			break;

			case PORT_D:
			if(value==HIGH)
			{
				
				PORTD |=(1<<pinnumber);//SET PIN TO 1
				
			}
			else if(value==LOW)
			{
				PORTD &=~(1<<pinnumber);//SET PIN TO 0

			}
			else
			{
				//error handling
			}
			break;

		}
	
}

void DIO_toggle(uint8_t portnumber,uint8_t pinnumber)
{
	switch(portnumber)
	{
		case PORT_A:
			PORTA^=(1<<pinnumber);//TOGGLE
			break;
		case PORT_B:
			PORTB^=(1<<pinnumber);//TOGGLE
			break;
		case PORT_C:
			PORTC^=(1<<pinnumber);//TOGGLE
			break;
		case PORT_D:
			PORTD^=(1<<pinnumber);//TOGGLE
			break;
		default:
			//error handling
			break;
	}
}

void DIO_read(uint8_t portnumber,uint8_t pinnumber,uint8_t *value)
{
	switch(portnumber)
	{
		case PORT_A :
		    *value=(PINA & (1<<pinnumber))>>pinnumber;
		    break;
		case PORT_B :
		    *value=(PINB & (1<<pinnumber))>>pinnumber;
		    break;
		case PORT_C :
		    *value=(PINC & (1<<pinnumber))>>pinnumber;
		    break;
		case PORT_D :
		    *value=(PIND & (1<<pinnumber))>>pinnumber;
		    break;
		default:
		//error handling
		    break;
	}
}

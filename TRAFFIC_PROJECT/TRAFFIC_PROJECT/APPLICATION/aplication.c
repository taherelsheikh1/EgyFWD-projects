/*
 * aplication.c
 *
 * Created: 12/7/2022 1:49:15 AM
 *  Author: TAHER ELSHEIKH
 */ 
#include "../APPLICATION/application.h"
#include "../ECUAL/BUTTON/button.h"
#include "../ECUAL/LED/led.h"
#include "../MCAL/interupts/INT0_INTERUPT.h"
#include "../MCAL/TIMER/timer.h"
uint8_t i ,car_led_state=0;
uint8_t normal_mode =1;
uint8_t	car_y_state=0;

void app_init(void)
{
	
	    //  CARS TRAFFIC LIGHTS INITILIZATION
	led_init(PORT_A,PIN0);
	led_init(PORT_A,PIN1);
	led_init(PORT_A,PIN2);
		//  PEDESTRIAN TRAFFIC LIGHTS INITILIZATION
	led_init(PORT_B,PIN0);
	led_init(PORT_B,PIN1);
	led_init(PORT_B,PIN2);
	    //  PUSH BUTTON INITIALAIZATION
    button_init(PORT_D,PIN2);
        //  ENABLE GLOBAL INTERUPS AND INTO INTERUPT WITH RISING EDGE 
	interupt_INT0_EN();
        //  TIMER0 INITIALIZATION IN NORMAL MODE 
	timer0_init();
}
void app_start(void)
{
	// #################################      normal mode    ######################################//
	if ((normal_mode==1)&&(car_led_state==0))
	{
		switch(car_led_state)
		{
			case 0:
			//  car green led is on and ped red is on
				led_on(car_port,car_green);
				led_on(ped_port,ped_red);
				led_off(car_port,car_red);
				led_off(car_port,car_yellow);
				// car green led is on for 5 s
                for (i=0;i<=25;i++)
                {
					// checking if button is pressed 
					if (normal_mode==0)
					break;
					timer0_delay_200ms();

                }
				// car yellow led is blinking for 5s
                for (i=0;i<=25;i++)
				{
					led_toggle(car_port,car_yellow);
					timer0_delay_200ms();
					
					// checking if button is pressed
					if (normal_mode==0)
					break;
				}
				// turn off car green and yellow leds
				led_off(car_port,car_green);
				led_off(car_port,car_yellow);
				led_on(car_port,car_red);
				// car red led is on for 5s
                for (i=0;i<=25;i++)
                {
	                timer0_delay_200ms();			
					// checking if button is pressed
	                if (normal_mode==0)
	                break;
                }
				// car yellow led is blinking for 5s
				for (i=0;i<=25;i++)
				{
					led_toggle(car_port,car_yellow);
					timer0_delay_200ms();
					if (normal_mode==0)
					break;
				}
				// turn of red and yellow leds and break to start over
				led_off(car_port,car_red);
				led_off(car_port,car_yellow);
				break;
		}
	}
		// #################################      pedestrians mode    ######################################//
         
		 // *************   if button pressed while car red led is on   ********************************//
		 
	if ((normal_mode==0)&&(car_led_state==1))
	{
		switch(car_led_state)
		{
			case 1:
			// turn off ca red led and turn on ped green led
		led_off(ped_port,ped_red);
		led_on(ped_port,ped_green);
		led_on(car_port,car_red);
				// wait for 5s
		timer0_delay_5s();
						// car-ped yellow leds is blinking for 5s
		for (i=0;i<=25;i++)
		{
			led_toggle(car_port,car_yellow);
			led_toggle(ped_port,ped_yellow);
			timer0_delay_200ms();
		}
		// turn off car-ped yellow leds and ped green led
		led_off(car_port,car_yellow);
		led_off(ped_port,ped_yellow);
		led_off(ped_port,ped_green);
		// set to normal mode and break to start over
		car_led_state=0;
		normal_mode=1;
		break;
	    }
	}
			 // *************   if button pressed while car green or yellow leds is on   ********************************//

	if (((normal_mode==0)&&(car_led_state==2)) || ( (normal_mode==0)&&(car_led_state==2)&&(car_y_state==1) ))
	{
		switch(car_led_state)
		{
			case 2:
			// car green led and ped red led is on
			led_on(ped_port,ped_red);
			led_on(car_port,car_green);
									// car-ped yellow leds is blinking for 5s
			for (i=0;i<=25;i++)
			{
				led_toggle(car_port,car_yellow);
				led_toggle(ped_port,ped_yellow);
				timer0_delay_200ms();
			}
			// turn off all leds except car red led and ped green led
			led_off(car_port,car_yellow);
			led_off(ped_port,ped_yellow);
			led_off(car_port,car_green);
			led_off(ped_port,ped_red);
			led_on(car_port,car_red);
			led_on(ped_port,ped_green);
			// wait for 5s
			timer0_delay_5s();
									// car-ped yellow leds is blinking for 5s
			for (i=0;i<=25;i++)
			{
				led_toggle(car_port,car_yellow);
				led_toggle(ped_port,ped_yellow);
				timer0_delay_200ms();
			}
			// turn of car-ped yellow leds and ped green led 
			led_off(car_port,car_yellow);
			led_off(ped_port,ped_yellow);
			led_off(ped_port,ped_green);
					// set to normal mode and break to start over
			car_led_state=0;
			normal_mode=1;
			break;
		}
	}
				 // *************   if button pressed while car red and yellow leds is on   ********************************//

	if ( (normal_mode==0)&&(car_led_state==1)&&(car_y_state==1) )
	{
		switch(car_led_state)
		{
			case 2:
			// turn on car-ped red leds 
			led_on(ped_port,ped_red);
			led_on(car_port,car_red);
									// car-ped yellow leds is blinking for 5s
			for (i=0;i<=25;i++)
			{
				led_toggle(car_port,car_yellow);
				led_toggle(ped_port,ped_yellow);
				timer0_delay_200ms();
			}
			// turn off all leds except car red and ped green leds
			led_off(car_port,car_yellow);
			led_off(ped_port,ped_yellow);
			led_off(car_port,car_green);
			led_off(ped_port,ped_red);
			led_on(car_port,car_red);
			led_on(ped_port,ped_green);
			// wait for 5s 
			timer0_delay_5s();
								// car-ped yellow leds is blinking for 5s
			for (i=0;i<=25;i++)
			{
				led_toggle(car_port,car_yellow);
				led_toggle(ped_port,ped_yellow);
				timer0_delay_200ms();
			}
			// tun of car-ped yellow and ped green leds
			led_off(car_port,car_yellow);
			led_off(ped_port,ped_yellow);
			led_off(ped_port,ped_green);
				// set to normal mode and break to start over
			car_led_state=0;
			normal_mode=1;
			break;
		}
	}
}
		// #################################      ISR     ######################################//
ISR(EXT_INT_0)
{
	if((((PINA & (1<<car_red))>>car_red)==1))  // READ CAR_RED LED IS ON WHILE BUTTON IS PRESSED
	{
		car_led_state=1;// SET CAR LED STATE TO 1 (RED)
		normal_mode=0;// SET PEDSTRIAN MODE
	}
	if ((((PINA & (1<<car_green))>>car_green)==1))// READ CAR_GREEN LED IS ON WHILE BUTTON IS PRESSED
	{
		car_led_state=2;// SET CAR LED STATE TO 1 (GREEN)
		normal_mode=0;// SET PEDSTRIAN MODE

	}
	if ((((PINA & (1<<car_yellow))>>car_yellow)==1))// READ CAR_YELLOW LED IS ON WHILE BUTTON IS PRESSED
	{
		car_y_state=1;// SET CAR LED STATE TO 1 (YELLOW)
		normal_mode=0;// SET PEDSTRIAN MODE

	}
}

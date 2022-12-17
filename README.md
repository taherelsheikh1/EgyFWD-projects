Contents :

1.1 System description .

        1.1.1 Normal mode .  
        
        1.1.2 Pedestrians mode .
        
1.2 System design .

       1.2.1 System requirements .
       
       1.2.2 Simulation design .
       
1.3 system flow chart .

1.4 system constrains .


1.1 System description :

1.1.1 Normal mode :

1.Cars' LEDs will be changed every five seconds starting from Green 
then yellow then red then yellow then Green.
2.The Yellow LED will blink for five seconds before moving to
 Green or Red LEDs.
 
1.1.1 Pedestrians mode :

1.Change from normal mode to pedestrian mode when the pedestrian button is pressed.
2.If pressed when the cars' Red LED is on, the pedestrian's Green LED and the cars' Red LEDs will be on for five seconds, this means that pedestrians can cross the street while the pedestrian's Green LED is on.
3.If pressed when the cars' Green LED is on or the cars' Yellow LED is blinking, the pedestrian Red LED will be on then both Yellow LEDs start to blink for five seconds, then the cars' Red LED and pedestrian Green LEDs are on for five seconds, this means that pedestrian must wait until the Green LED is on.
4.At the end of the two states, the cars' Red LED will be off and both Yellow LEDs start blinking for 5 seconds and the pedestrian's Green LED is still on.
5.After the five seconds the pedestrian Green LED will be off and both the pedestrian Red LED and the cars' Green LED will be on.
6.Traffic lights signals are going to the normal mode again.

1.2 System design :

1.2.1 system requirements :

1. 2 x Red leds .
2. 2 x Yellow leds .
3. 2 x Green leds 
4. Push button .
5. 6 x 300Ω resistors .
6. 1 x 10 kΩ resistor .
5. Atmega32a microcontroller .

1.2.2 Simulation design :

![image](https://user-images.githubusercontent.com/120778208/208250068-221ecd2c-98fd-45a7-a9f3-3ead969fca4a.png)


1.3 system flow chart :

![image](https://user-images.githubusercontent.com/120778208/208250111-173e8468-6ca2-4f4f-b110-34d37b5e344e.png)

1.4 System constraints :

1. Double press on button does the interrupts for one time and
    ignoring the second press .
2. Long press does not effects on program cycle .

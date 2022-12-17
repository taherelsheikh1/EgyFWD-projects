/*
 * DIO.h
 *
 * Created: 12/7/2022 1:50:13 AM
 *  Author: TAHER ELSHEIKH
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../UTILITIES/Registers.h"

//dio functions prototypes
void DIO_init(uint8_t portnumber,uint8_t pinnumber,uint8_t direction);// dio initialization

void DIO_read(uint8_t portnumber,uint8_t pinnumber,uint8_t *value);//  read dio state

void DIO_write(uint8_t portnumber,uint8_t pinnumber,uint8_t value);// write data to dio

void DIO_toggle(uint8_t portnumber,uint8_t pinnumber);// dio toggle



#endif /* DIO_H_ */
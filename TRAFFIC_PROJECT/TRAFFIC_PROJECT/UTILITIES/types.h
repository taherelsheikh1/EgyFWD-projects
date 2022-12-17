/*
 * types.h
 *
 * Created: 12/7/2022 2:32:30 AM
 *  Author: TAHER ELSHEIKH
 */ 


#ifndef TYPES_H_
#define TYPES_H_
// MC FREQUANCY
#define F_CPU 1000000U
//macros for prescaler
#define prescaler 1024

// values macros for writing to dio
#define HIGH 1
#define LOW 0
// directions macros for dio initialization
#define IN 0
#define OUT 1
// macros for i/o registers
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'
// macros for pin number
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
//macros for ped and cars led pins
#define car_red 0
#define car_yellow 1
#define car_green 2
#define ped_red 0
#define ped_yellow 1
#define ped_green 2
//macros for ped and cars led ports
#define car_port 'A'
#define ped_port 'B'
//unsigned
typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long long uint32_t;
//signed
typedef  char int8_t;
typedef  int int16_t;
typedef  long long int32_t;


#endif /* TYPES_H_ */
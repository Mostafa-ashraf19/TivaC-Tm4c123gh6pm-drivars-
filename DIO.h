/*
//  This file have all HAL layes and API's to be familer with 
//	Tiva C ports and pins configrations
//  Author: Mostafa Ashraf
//  Date: 26/02/2020
*/
#ifndef DIO_H_
#define DIO_H_
#include "StabdardTypes.h"
#include "tm4c123gh6pm.h"
/* macro like function to be familer 
	 with ports Pins in 
	 (HardWare abstraction Layer "HAL")layer
*/
#define SET_BIT(REG,BIT) REG|=(1<<BIT) 
#define	CLEAR_BIT(REG,BIT) REG = REG & ~(1<<BIT)
#define TOGGLE(REG,BIT)	(REG ^= (1<<BIT))
#define IS_BIT_SET(REG,BIT) ((REG &(1<<(BIT)))>>(BIT))
#define IS_BIT_CLREAR(REG,BIT) !(IS_BIT_SET(REG,BIT))

// Magic number for unlock certin port
#define MAGIC_NUMBER 0x4C4F434B

typedef enum {PORTA,PORTB,PORTC,PORTD,PORTE,PORTF,}PortName;

typedef enum {PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7}PinNum;

typedef enum {LOW,HIGH}Signal;
	
typedef enum {INPUT,OUTPUT,INTERNAL_PULL_UP,INTERNAL_PULL_DOWN}Mode;


//#define GPIO_PORTA_AHB_DIR_R    (*((volatile unsigned long *)0x40058400))
//#define GPIO_PORTA_AHB_DATA_R   (*((volatile unsigned long *)0x400583FC))
void Dio_config(PortName portname,PinNum pinnumber,Mode mode);
void Dio_Write_Pin(PortName portname,PinNum pinnum,Signal type);
void Dio_Wite_Port(PortName portname,uint_8 value);
void Dio_Clear_Port(PortName portname);
uint_16 Dio_Read_Pin(PortName portname,PinNum pinnum);
void Dio_Toggle_Pin(PortName portname,PinNum pinnum);
//void Dio_config_altfun()
#endif

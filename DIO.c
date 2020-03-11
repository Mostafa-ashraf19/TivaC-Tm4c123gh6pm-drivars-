/*
//  This file have implemntions for prototype functions in dio.h 
//  Author: Mostafa Ashraf
//  Date: 7/03/2020
*/
#include "DIO.h"
/*
	Function Name        : Dio_config
	Function Returns     : void
	Function Arguments   : PortName portname,PinNum pinnumber,Mode mode
	Function Description : modified port critria depend on some operations and modes for each pin 
*/
void Dio_config(PortName portname,PinNum pinnumber,Mode mode)
{
	SET_BIT(SYSCTL_RCGC2_R,portname);
	// access clock for certin port depend on it's name
	while(IS_BIT_SET(SYSCTL_PRGPIO_R,portname) == 0);
	// check for PORT_n Ready
	switch(portname)
	{
		case PORTA:
			GPIO_PORTA_LOCK_R= MAGIC_NUMBER; // for un lock port
			// should her put commit reg but default value if (FF) maybe putted next time or new virsion  
			SET_BIT(GPIO_PORTA_DEN_R,pinnumber);// enable digital mode
			CLEAR_BIT(GPIO_PORTA_AFSEL_R,pinnumber); // disable altenate function
			// should her put port control reg but default value is (0-) maybe putted next time or new virsion 
			CLEAR_BIT(GPIO_PORTA_AMSEL_R,pinnumber);//disable analog mode
			switch(mode)
			{
				case INPUT:
					CLEAR_BIT(GPIO_PORTA_DIR_R,pinnumber);
					break;
				case OUTPUT:
					SET_BIT(GPIO_PORTA_DIR_R,pinnumber);
					break;
				
				case INTERNAL_PULL_UP:
					break;
				
				case INTERNAL_PULL_DOWN:
					break;
				
				default:
					break;
			}
		break;
			
		case PORTB:
			GPIO_PORTB_LOCK_R= MAGIC_NUMBER; // for un lock port
			// should her put commit reg but default value if (FF) maybe putted next time or new virsion  
			SET_BIT(GPIO_PORTB_DEN_R,pinnumber);// enable digital mode
			CLEAR_BIT(GPIO_PORTB_AFSEL_R,pinnumber); // disable altenate function
			// should her put port control reg but default value is (0-) maybe putted next time or new virsion 
			CLEAR_BIT(GPIO_PORTB_AMSEL_R,pinnumber);//disable analog mode
			switch(mode)
			{
				case INPUT:
					CLEAR_BIT(GPIO_PORTB_DIR_R,pinnumber);
					break;
				case OUTPUT:
					SET_BIT(GPIO_PORTB_DIR_R,pinnumber);
					break;
				
				case INTERNAL_PULL_UP:
					break;
				
				case INTERNAL_PULL_DOWN:
					break;
				
				default:
					break;
			}
			break;
			case PORTC:
				
			//not use to port c	GPIO_PORTC_LOCK_R= MAGIC_NUMBER; // for un lock port
			// should her put commit reg but default value if (FF) maybe putted next time or new virsion  
			SET_BIT(GPIO_PORTC_DEN_R,pinnumber);// enable digital mode
			CLEAR_BIT(GPIO_PORTC_AFSEL_R,pinnumber); // disable altenate function
			// should her put port control reg but default value is (0-) maybe putted next time or new virsion 
			CLEAR_BIT(GPIO_PORTC_AMSEL_R,pinnumber);//disable analog mode
			switch(mode)
			{
				case INPUT:
					CLEAR_BIT(GPIO_PORTC_DIR_R,pinnumber);
					break;
				case OUTPUT:
					SET_BIT(GPIO_PORTC_DIR_R,pinnumber);
					break;
				
				case INTERNAL_PULL_UP:
					break;
				
				case INTERNAL_PULL_DOWN:
					break;
				
				default:
					break;
			}
			break;		
			case PORTD:
				GPIO_PORTD_LOCK_R= MAGIC_NUMBER; // for un lock port
			// should her put commit reg but default value if (FF) maybe putted next time or new virsion  
			SET_BIT(GPIO_PORTD_DEN_R,pinnumber);// enable digital mode
			CLEAR_BIT(GPIO_PORTD_AFSEL_R,pinnumber); // disable altenate function
			// should her put port control reg but default value is (0-) maybe putted next time or new virsion 
			CLEAR_BIT(GPIO_PORTD_AMSEL_R,pinnumber);//disable analog mode
			switch(mode)
			{
				case INPUT:
					CLEAR_BIT(GPIO_PORTD_DIR_R,pinnumber);
					break;
				case OUTPUT:
					SET_BIT(GPIO_PORTD_DIR_R,pinnumber);
					break;
				
				case INTERNAL_PULL_UP:
					break;
				
				case INTERNAL_PULL_DOWN:
					break;
				
				default:
					break;
			}
			break;
			case PORTE:
				GPIO_PORTE_LOCK_R= MAGIC_NUMBER; // for un lock port
			// should her put commit reg but default value if (FF) maybe putted next time or new virsion  
			SET_BIT(GPIO_PORTE_DEN_R,pinnumber);// enable digital mode
			CLEAR_BIT(GPIO_PORTE_AFSEL_R,pinnumber); // disable altenate function
			// should her put port control reg but default value is (0-) maybe putted next time or new virsion 
			CLEAR_BIT(GPIO_PORTE_AMSEL_R,pinnumber);//disable analog mode
			switch(mode)
			{
				case INPUT:
					CLEAR_BIT(GPIO_PORTE_DIR_R,pinnumber);
					break;
				case OUTPUT:
					SET_BIT(GPIO_PORTE_DIR_R,pinnumber);
					break;
				
				case INTERNAL_PULL_UP:
					break;
				
				case INTERNAL_PULL_DOWN:
					break;
				
				default:
					break;
			}
			break;
			case PORTF:
							GPIO_PORTF_LOCK_R= MAGIC_NUMBER; // for un lock port
			// should her put commit reg but default value if (FF) maybe putted next time or new virsion  
			SET_BIT(GPIO_PORTF_DEN_R,pinnumber);// enable digital mode
			CLEAR_BIT(GPIO_PORTF_AFSEL_R,pinnumber); // disable altenate function
			// should her put port control reg but default value is (0-) maybe putted next time or new virsion 
			CLEAR_BIT(GPIO_PORTF_AMSEL_R,pinnumber);//disable analog mode
			switch(mode)
			{
				case INPUT:
					CLEAR_BIT(GPIO_PORTF_DIR_R,pinnumber);
					break;
				case OUTPUT:
					SET_BIT(GPIO_PORTF_DIR_R,pinnumber);
					break;
				
				case INTERNAL_PULL_UP:
					break;
				
				case INTERNAL_PULL_DOWN:
					break;
				
				default:
					break;
			}
			break;		
			
		default:
			break;
	}
}
/*
	Function Name        : Dio_Write_Pin
	Function Returns     : void
	Function Arguments   : PortName portname,PinNum pinnum,Signal type
	Function Description : Set the value of the given pin in the given port (outputvalue LOW=0,HIGH=1) 
*/
void Dio_Write_Pin(PortName portname,PinNum pinnum,Signal type)
{
	switch (portname)
			{
				case PORTA:
					if ( type == HIGH )
					SET_BIT(GPIO_PORTA_DATA_R,pinnum);
					else 
					CLEAR_BIT(GPIO_PORTA_DATA_R,pinnum);
					break;
					
				case PORTB:
					if ( type == HIGH )
					SET_BIT(GPIO_PORTB_DATA_R,pinnum);
					else 
					CLEAR_BIT(GPIO_PORTB_DATA_R,pinnum);
					break;
					
				case PORTC:
					if ( type == HIGH )
					SET_BIT(GPIO_PORTC_DATA_R,pinnum);
					else 
					CLEAR_BIT(GPIO_PORTC_DATA_R,pinnum);
					break;
					
				case PORTD:
					if ( type == HIGH )
					SET_BIT(GPIO_PORTD_DATA_R,pinnum);
					else 
					CLEAR_BIT(GPIO_PORTD_DATA_R,pinnum);
					break;
					
				case PORTE:
					if ( type == HIGH )
					SET_BIT(GPIO_PORTE_DATA_R,pinnum);
					else 
					CLEAR_BIT(GPIO_PORTE_DATA_R,pinnum);
					break;	
					
				case PORTF:
					if ( type == HIGH )
					SET_BIT(GPIO_PORTF_DATA_R,pinnum);
					else 
					CLEAR_BIT(GPIO_PORTF_DATA_R,pinnum);
					break;
				default:
						break;
			}
}
/*
	Function Name        : Dio_Wite_Port
	Function Returns     : void
	Function Arguments   : PortName portname,uint_8 value
	Function Description : Set the value given in port  
*/
void Dio_Wite_Port(PortName portname,uint_8 value)
{
		switch (portname)
			{
				case PORTA:
					GPIO_PORTA_DATA_R=value;
					break;
					
				case PORTB:
					GPIO_PORTB_DATA_R=value;
					break;
					
				case PORTC:
				GPIO_PORTC_DATA_R=value;
					break;
					
				case PORTD:
				GPIO_PORTD_DATA_R=value;
					break;
					
				case PORTE:
					GPIO_PORTE_DATA_R=value;
					break;	
					
				case PORTF:
					GPIO_PORTF_DATA_R=value;
					break;
				
				default:
						break;
			}
}
/*
	Function Name        : Dio_Clear_Port
	Function Returns     : void
	Function Arguments   : PortName portname
	Function Description : Clear data in given port  
*/
void Dio_Clear_Port(PortName portname)
{
	switch (portname)
			{
				case PORTA:
					GPIO_PORTA_DATA_R=0;
					break;
					
				case PORTB:
					GPIO_PORTB_DATA_R=0;
					break;
					
				case PORTC:
				GPIO_PORTC_DATA_R=0;
					break;
					
				case PORTD:
				GPIO_PORTD_DATA_R=0;
					break;
					
				case PORTE:
					GPIO_PORTE_DATA_R=0;
					break;	
					
				case PORTF:
					GPIO_PORTF_DATA_R=0;
					break;
				
				default:
						break;
			}
}
/*
	Function Name        : Dio_Read_Pin
	Function Returns     : unsigned char
	Function Arguments   : PortName portname,PinNum pinnum
	Function Description : Returns 1 if the value of the given pin is high and zero if the value is low
*/
uint_16 Dio_Read_Pin(PortName portname,PinNum pinnum)
	{
			switch(portname)
			{
				case PORTA:
					return IS_BIT_SET(GPIO_PORTA_DATA_R,pinnum);
				case PORTB:
					return IS_BIT_SET(GPIO_PORTB_DATA_R,pinnum);
				case PORTC:
					return IS_BIT_SET(GPIO_PORTC_DATA_R,pinnum);
				case PORTD:
					return IS_BIT_SET(GPIO_PORTD_DATA_R,pinnum);
				case PORTE:
					return IS_BIT_SET(GPIO_PORTE_DATA_R,pinnum);
				case PORTF:
					return IS_BIT_SET(GPIO_PORTF_DATA_R,pinnum);
				default:
					return 0;
			}
	}
	/*
	Function Name        : Dio_Toggle_Pin
	Function Returns     : void
	Function Arguments   : PortName portname,PinNum pinnum
	Function Description : Reverse the value of the given pin in the given port.
*/
	void Dio_Toggle_Pin(PortName portname,PinNum pinnum)
{
	switch(portname)
			{
				case PORTA:
					 TOGGLE(GPIO_PORTA_DATA_R,pinnum);
				case PORTB:
					TOGGLE(GPIO_PORTB_DATA_R,pinnum);
				case PORTC:
					TOGGLE(GPIO_PORTC_DATA_R,pinnum);
				case PORTD:
					TOGGLE(GPIO_PORTD_DATA_R,pinnum);
				case PORTE:
					TOGGLE(GPIO_PORTE_DATA_R,pinnum);
				case PORTF:
					TOGGLE(GPIO_PORTF_DATA_R,pinnum);
				default:
					return;
			}
}

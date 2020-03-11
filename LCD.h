#ifndef LCD_H_
#define LCD_H_
#include "DIO.h"
#include "StabdardTypes.h"

typedef enum {COMMAND,DATA}Register_Select;

#define LCD_DATA_PORT	PORTA
#define LCD_CTRL_PORT PORTB
#define RS PIN0
#define EN PIN1
// read/write pin connect to ground for write only write=0
//typedef enum {WRITE,READ}LCD_Mode;

typedef enum {CLEAR_DISPLAY=0x01,
							RETURN_HOME=0x02,
							DISPLAY_ON_CURSOR_ON=0x0f,
							DISPLAY_ON_CURSOR_OF=0x0c,}Commands;

void LcDInit(PortName pn);
void Send_Commands(Commands cmd);
void Send_character(uint_8 character);
void Send_string(uint_8 * pc);
void set_cursor(); // not implement 							
void delay()
{}	
void High2Low()
{
	Dio_Write_Pin(LCD_CTRL_PORT,EN,HIGH);
	delay(); // not impemented yet 
	Dio_Write_Pin(LCD_CTRL_PORT,EN,LOW);
}
#endif

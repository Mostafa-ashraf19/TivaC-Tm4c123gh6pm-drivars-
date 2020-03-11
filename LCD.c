#include "LCD.h"

void LcDInit(PortName pn)
{
	Dio_config(LCD_CTRL_PORT,RS,OUTPUT);
	Dio_config(LCD_CTRL_PORT,EN,OUTPUT);
	Dio_config(pn,PIN0,OUTPUT);
	Dio_config(pn,PIN1,OUTPUT);
	Dio_config(pn,PIN2,OUTPUT);
	Dio_config(pn,PIN3,OUTPUT);
	Dio_config(pn,PIN4,OUTPUT);
	Dio_config(pn,PIN5,OUTPUT);
	Dio_config(pn,PIN6,OUTPUT);
	Dio_config(pn,PIN7,OUTPUT);
	/* from pin0 to pin7 will update to one function only  */
	Send_Commands(CLEAR_DISPLAY);
	Send_Commands(RETURN_HOME);
	Send_Commands(DISPLAY_ON_CURSOR_ON);
}
void Send_Commands(Commands cmd)
{
	Dio_Write_Pin(LCD_CTRL_PORT,RS,LOW);
	Dio_Wite_Port(LCD_DATA_PORT,cmd);
	High2Low();// delay not implemented yet
}
void Send_character(uint_8 character)
{
	Dio_Write_Pin(LCD_CTRL_PORT,RS,HIGH);
	Dio_Wite_Port(LCD_DATA_PORT,character);
	High2Low();
}
void Send_string(uint_8 * pc)
{
	int i=0;
	while (pc[i] != '\0')
		Send_character(pc[i++]);
}
void set_cursor()
{
}

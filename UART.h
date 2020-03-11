#ifndef UART_H_
#define UART_H_
#include"DIO.h"

typedef enum {_5_Bits=0,_6_Bits=1,
							_7_Bits=2,_8_Bits=3,}wordLength;

void UART_Config(PortName);


#endif
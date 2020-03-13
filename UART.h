#ifndef UART_H_
#define UART_H_

#include"DIO.h"


typedef enum {_5_Bits=0,_6_Bits=1,
							_7_Bits=2,_8_Bits=3,}wordLength;

typedef enum {FALSE,TRUE}LOGICAL_BOOL;	
typedef enum {TXFF,RXFF}Q_BIT;

void UART_Config(PortName);

LOGICAL_BOOL UART_Check_Tx_Rx_Queue(Q_BIT);

void UART_Send_Char(uint_8);

uint_8 UART_Receive_Char();

void UART_Send_String(uint_8 *);

// have 8 uart
#endif

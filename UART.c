#include "UART.h"
#include	"tm4c123gh6pm.h"


//SYSCTL_RCGCUART_R

void UART_config(PortName portname)
{
	//SYSCTL_RCGCUART_R.
	SET_BIT(SYSCTL_RCGCUART_R,portname);
}

void UART_Send_Char(uint_8 Data)
{
	while(UART_Check_T_R_Queue(TXFF)){};
		UART0_DR_R = Data; // send data 
}

LOGICAL_BOOL UART_Check_Tx_Rx_Queue(Q_REG reg)
{
	if( reg == TXFF )// return bit
		return IS_BIT_SET(,PIN5);
	else if ( reg == RXFF)
		
		// return 
}

void UART_Send_String(uint_8 * Data)
{
	uint_8 i = 0;
	while(Data[i++] != '\0')
		UART_Send_Char(Data[i]);
}
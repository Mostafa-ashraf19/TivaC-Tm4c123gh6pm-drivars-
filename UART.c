#include "UART.h"
#include	"tm4c123gh6pm.h"


//SYSCTL_RCGCUART_R

void UART_config(PortName portname)
{
	//SYSCTL_RCGCUART_R .
	SET_BIT(SYSCTL_RCGCUART_R,portname);
}
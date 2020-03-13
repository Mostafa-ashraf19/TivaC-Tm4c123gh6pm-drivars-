#include 	"UART.h"
#include	"UART_Config.h"

/*
	Function Name        : UART_config
	Function Returns     : void
	Function Arguments   : PortName portname
	Function Description : set configuration of UARTn for certin port  
*/
void UART_config(PortName portname)
{
	//SYSCTL_RCGCUART_R.
	SET_BIT(SYSCTL_RCGCUART_R,portname);
}

/*
	Function Name        : UART_Send_Char
	Function Returns     : void
	Function Arguments   : uint_8 Data
	Function Description : send char by put it in data reg, depend on FIFO transmitter full or not  
*/
void UART_Send_Char(uint_8 Data)
{
	while(UART_Check_Tx_Rx_Queue(TXFF)){};
		UARTn_DATA_REG = Data; // send char
}
/*
	Function Name        : UART_Check_Tx_Rx_Queue
	Function Returns     : LOGICAL_BOOL (TRUE or FALSE)
	Function Arguments   : Q_REG bit ( TXFF bit or RXFF bit)
	Function Description : return TXFF full or not in case of send or RXFF empty or not in case of receive 
*/
LOGICAL_BOOL UART_Check_Tx_Rx_Queue(Q_BIT bit)
{
	if( bit == TXFF )// return bit
		return IS_BIT_SET(UARTn_FLAG_REG,PIN5);
	else if ( bit == RXFF)
		return IS_BIT_SET(UARTn_FLAG_REG,PIN4);
}
/*
	Function Name        : UART_Receive_Char
	Function Returns     : uint_8
	Function Arguments   : Void
	Function Description : receive uint_8 data from data reg then return it   
*/
uint_8 UART_Receive_Char()
{
	while(UART_Check_Tx_Rx_Queue(RXFF)){};
		return	(UARTn_DATA_REG);
}
/*
	Function Name        : UART_Send_String
	Function Returns     : void
	Function Arguments   : uint_8 * Data
	Function Description : Send Block of data like "string" 
*/
void UART_Send_String(uint_8 * Data)
{
	uint_8 i = 0;
	while(Data[i++] != '\0')
		UART_Send_Char(Data[i]);// send string
}
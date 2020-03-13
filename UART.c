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
	GPIO_PORTA_LOCK_R= MAGIC_NUMBER;
	SET_BIT(GPIO_PORTA_DEN_R,PIN0);// enable digital mode
	SET_BIT(GPIO_PORTA_DEN_R,PIN1);// enable digital mode
	SET_BIT(GPIO_PORTA_AFSEL_R,PIN0);// set af fun
	SET_BIT(GPIO_PORTA_AFSEL_R,PIN1);// set af fun
	CLEAR_BIT(GPIO_PORTA_AMSEL_R,PIN0);//disable analog mode
	CLEAR_BIT(GPIO_PORTA_AMSEL_R,PIN1);//disable analog mode
	GPIO_PORTA_PCTL_R = (GPIO_PCTL_PA0_U0RX | GPIO_PCTL_PA1_U0TX);// receiver and transimter for PA0,PA1
	
	CLEAR_BIT(UARTn_CTL_REG,PIN0); // disable n uart
	SET_BIT(SYSCTL_RCGCUART_R,portname); // set clock for n UART
	UARTn_INTBD_REG = UARTnBR_INTEGER_VALUE; // put integer value in DIVINT reg
	UARTn_FRACBR_REG = UARTnBR_FRACTIONAL_VALUE; // put fractional value in DIVFRAC reg
	
	SET_BIT(UARTn_CTL_REG,8); //  enable  TXE
	SET_BIT(UARTn_CTL_REG,9); //  enable  RXE 
	SET_BIT(UARTn_CTL_REG,PIN0); // enable n uart
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
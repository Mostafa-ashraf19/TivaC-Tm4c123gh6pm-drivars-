#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_
#include	"tm4c123gh6pm.h"
#include	"StabdardTypes.h"

#define SYSTEM_CLOCK	16000000
#define DESIRED_BAUD_RATE	9600

#define BRC_DIVSIOR		(float_32)(SYSTEM_CLOCK/(float_32)(16*(float_32)DESIRED_BAUD_RATE))

#define UARTnBR_INTEGER_VALUE		((int_32)BRC_DIVSIOR)

#define UARTnBR_FRACTIONAL_VALUE  (int_32)((((float_32)BRC_DIVSIOR-(float_32)UARTnBR_INTEGER_VALUE)*(float_32)64)+(float_32).5)

#define UART_NUM  0


#if  UART_NUM == 0
			#define UARTn_FLAG_REG	 	UART0_FR_R 
			#define UARTn_DATA_REG		UART0_DR_R
			#define UARTn_INTBD_REG		UART0_IBRD_R
			#define UARTn_FRACBR_REG	UART0_FBRD_R 
			#define UARTn_CTL_REG			UART0_CTL_R
			
#elif UART_NUM == 1
	`		#define UARTn_FLAG_REG	 	UART0_FR_R 
			#define UARTn_DATA_REG		UART0_DR_R
			#define UARTn_INTBD_REG		UART0_IBRD_R
			#define UARTn_FRACBR_REG	UART0_FBRD_R 
			#define UARTn_CTL_REG			UART0_CTL_R

#elif UART_NUM == 2
			#define UARTn_FLAG_REG	 	UART0_FR_R 
			#define UARTn_DATA_REG		UART0_DR_R
			#define UARTn_INTBD_REG		UART0_IBRD_R
			#define UARTn_FRACBR_REG	UART0_FBRD_R 
			#define UARTn_CTL_REG			UART0_CTL_R
#elif UART_NUM == 3
			#define UARTn_FLAG_REG	 	UART0_FR_R 
			#define UARTn_DATA_REG		UART0_DR_R
			#define UARTn_INTBD_REG		UART0_IBRD_R
			#define UARTn_FRACBR_REG	UART0_FBRD_R 
			#define UARTn_CTL_REG			UART0_CTL_R
#elif UART_NUM == 4
			#define UARTn_FLAG_REG	 	UART0_FR_R 
			#define UARTn_DATA_REG		UART0_DR_R
			#define UARTn_INTBD_REG		UART0_IBRD_R
			#define UARTn_FRACBR_REG	UART0_FBRD_R 
			#define UARTn_CTL_REG			UART0_CTL_R
#elif UART_NUM == 5
			#define UARTn_FLAG_REG	 	UART0_FR_R 
			#define UARTn_DATA_REG		UART0_DR_R
			#define UARTn_INTBD_REG		UART0_IBRD_R
			#define UARTn_FRACBR_REG	UART0_FBRD_R 
			#define UARTn_CTL_REG			UART0_CTL_R
#elif UART_NUM == 6
			#define UARTn_FLAG_REG	 	UART0_FR_R 
			#define UARTn_DATA_REG		UART0_DR_R
			#define UARTn_INTBD_REG		UART0_IBRD_R
			#define UARTn_FRACBR_REG	UART0_FBRD_R 
			#define UARTn_CTL_REG			UART0_CTL_R
#elif UART_NUM == 7
			#define UARTn_FLAG_REG	 	UART0_FR_R 
			#define UARTn_DATA_REG		UART0_DR_R
			#define UARTn_INTBD_REG		UART0_IBRD_R
			#define UARTn_FRACBR_REG	UART0_FBRD_R 
			#define UARTn_CTL_REG			UART0_CTL_R

#endif
 





#endif
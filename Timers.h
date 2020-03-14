#ifndef	TIMERS_H_
#define TIMERS_H_
#include "tm4c123gh6pm.h"
#include "DIO.h"
	/* SysTic Timer Modules	 Start */
		#define CTRL 		NVIC_ST_CTRL_R // CTRL reg en(RW) , INTEN(RW) , CLK_SRC(RW) , COUNT(RO)
		#define RELOAD	NVIC_ST_RELOAD_R // RW reg
		#define CURRENT	NVIC_ST_CURRENT_R  // RW reg

		void SYSTIC_inti(void)
		{
			CLEAR_BIT(NVIC_ST_CTRL_R,PIN0); // disble systic
			NVIC_ST_RELOAD_R = NVIC_ST_RELOAD_M; // RW reg
			NVIC_ST_CURRENT_R  = NVIC_ST_RELOAD_S; // RW reg
			SET_BIT(NVIC_ST_CTRL_R,PIN2); // user system clock 80 MHZ
			CLEAR_BIT(NVIC_ST_CTRL_R,PIN1); // disable interupt genrator
			SET_BIT(NVIC_ST_CTRL_R,PIN0);	// enable systick
		}
	/* SysTic Timer Modules	 End */
	
	
	/*	General Purpose Timers Modules	Start */
	
	/*	General Purpose Timers Modules	end */

#endif 
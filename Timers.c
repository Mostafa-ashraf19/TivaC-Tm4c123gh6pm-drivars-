#include "Timers.h"	
	/* SysTic Timer Modules	 Start */

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
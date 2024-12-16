
/******************************************************************************************************
 ******************************************************************************************************
 ******************************** AUTHOR  : Mahmoud Rabea  ********************************************
 ******************************** MICRO   : STM32F401CCU6  ********************************************
 ******************************** LAYER   : MCAL           ********************************************
 ******************************** DRIVER  : SYSTICK_Driver ********************************************
 ******************************** File    : private File   ********************************************
 ******************************** Date    : 3/9/2023       ********************************************
 ******************************** Version : 1.0            ********************************************
 ******************************************************************************************************
 ******************************************************************************************************/

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_

typedef struct
{
	volatile u32 STK_CTRL                      	    ;
	volatile u32 STK_LOAD                      	    ;
	volatile u32 STK_VAL                       	    ;
	volatile u32 STK_CALIB                     	    ;

}SYSTICK_T;

#define SYSTICK_BASE_ADDRESS                    	0xE000E010
#define SYSTICK                                 	((volatile SYSTICK_T*)SYSTICK_BASE_ADDRESS)

#define SYSTICK_CLOCK_SOURCE_AHB   	                1
#define SYSTICK_CLOCK_SOURCE_AHB_DIVIDED_BY_8   	2

#define SYSTICK_INTERRUPT_ENABLE                    3
#define SYSTICK_INTERRUPT_DISABLE                   4

#define SYSTICK_CTRL_ENABLE                         0
#define SYSTICK_CTRL_TICKINT                        1
#define SYSTICK_CTRL_CLKSOURCE                      2
#define SYSTICK_CTRL_COUNTFLAG                      16

#define SYSTICK_MSECOND_COUNTS_AHB                  15000
#define SYSTICK_MSECOND_COUNTS_AHB_DIV_8            1500

#define SYSTICK_USECOND_COUNTS_AHB                  12
#define SYSTICK_USECOND_COUNTS_AHB_DIV_8            1

#endif /* SYSTICK_PRIVATE_H_ */

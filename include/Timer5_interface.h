
/******************************************************************************************************
 ******************************************************************************************************
 ******************************** AUTHOR  : Mahmoud Rabea   *******************************************
 ******************************** MICRO   : STM32F401CCU6   *******************************************
 ******************************** LAYER   : MCAL            *******************************************
 ******************************** DRIVER  : TIMER_Driver    *******************************************
 ******************************** File    : interface File  *******************************************
 ******************************** Date    : 25/4/2024       *******************************************
 ******************************** Version : 1.0             *******************************************
 ******************************************************************************************************
 ******************************************************************************************************/

#ifndef TIMER5_INTERFACE_H_
#define TIMER5_INTERFACE_H_

/* Function to initialize the Timer5 for Input capture mode
 * */

void Timer5_voidInit(void);

/* Function to enable the counter
 * */

void Timer5_voidEnableCounter(void);

/* Function to disable the counter
 * */

void Timer5_voidDisableCounter(void);

/* Function to capture the value
 * */

u32 Timer5_u32CaptureValue(void);

/* Function to configure rising edge
 * */

void Timer5_voidConfiguringRisingEdge(void);

/* Function to configure falling edge
 * */

void Timer5_voidConfiguringFallingEdge(void);

/* Function to clear the counter
 * */

void Timer5_voidClearCounter(void);

void callbaICUCallbackck(void(*ptr)(void));



#endif /* TIMER5_INTERFACE_H_ */

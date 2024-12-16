
/******************************************************************************************************
 ******************************************************************************************************
 ******************************** AUTHOR  : Mahmoud Rabea   *******************************************
 ******************************** MICRO   : STM32F401CCU6   *******************************************
 ******************************** LAYER   : MCAL            *******************************************
 ******************************** DRIVER  : TIMER_Driver    *******************************************
 ******************************** File    : interface File  *******************************************
 ******************************** Date    : 12/7/2024       *******************************************
 ******************************** Version : 1.0             *******************************************
 ******************************************************************************************************
 ******************************************************************************************************/

#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_

/* Function to initialize the Timer2
 * */

void Timer2_voidInit(void);

/* Function to enable the counter
 * */

void Timer2_voidEnableCounter(void);

/* Function to disable the counter
 * */

void Timer2_voidDisableCounter(void);

///* Function to capture the value
// * */
//
//u32 Timer2_u32CaptureValue(void);
//
///* Function to configure rising edge
// * */
//
//void Timer2_voidConfiguringRisingEdge(void);
//
///* Function to configure falling edge
// * */
//
//void Timer2_voidConfiguringFallingEdge(void);

/* Function to clear the counter
 * */

void Timer2_voidClearCounter(void);

void UpdateEventCallback(void(*ptr)(void));



#endif /* TIMER2_INTERFACE_H_ */

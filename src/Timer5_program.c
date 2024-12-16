
/******************************************************************************************************
 ******************************************************************************************************
 ******************************** AUTHOR  : Mahmoud Rabea *********************************************
 ******************************** MICRO   : STM32F401CCU6 *********************************************
 ******************************** LAYER   : MCAL          *********************************************
 ******************************** DRIVER  : TIMER_Driver  *********************************************
 ******************************** File    : program File  *********************************************
 ******************************** Date    : 25/4/2024     *********************************************
 ******************************** Version : 1.0           *********************************************
 ******************************************************************************************************
 ******************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "Timer5_configuration.h"
#include "Timer5_interface.h"
#include "Timer5_private.h"

void (*ptr1)(void) = NULL;

/* Function to initialize the Timer5 for Input capture mode
 * */

void Timer5_voidInit(void)
{



	/*The division ratio between the timer clock (CK_INT) frequency and sampling clock used by the digital filters = 1 */
	CLEAR_BIT(TIMER5->TIMx_CR1,TIMER5_TIMx_CR1_CKD) ;
	CLEAR_BIT(TIMER5->TIMx_CR1,( TIMER5_TIMx_CR1_CKD + 1 )) ;

	/* To use the counter as up-counter*/
	CLEAR_BIT(TIMER5->TIMx_CR1,TIMER5_TIMx_CR1_DIR);

	/*The TIMx_CH1 pin is connected to TI1 input*/
	CLEAR_BIT(TIMER5->TIMx_CR2,TIMER5_TIMx_CR2_TI1S);

	/*To select the internal clock source*/
	CLEAR_BIT(TIMER5->TIMx_SMCR,0);
	CLEAR_BIT(TIMER5->TIMx_SMCR,1);
	CLEAR_BIT(TIMER5->TIMx_SMCR,2);

	/*The counter clock frequency CK_CNT is equal to frequency CK_PSC / ( TIMER5->TIMx_PSC + 1 ) */
	TIMER5->TIMx_PSC = 15;

	/*Select both edges*/
	SET_BIT(TIMER5->TIMx_CCER,1);
	SET_BIT(TIMER5->TIMx_CCER,3);

	/*Select rising edge*/
//	CLEAR_BIT(TIMER5->TIMx_CCER,1);
//	CLEAR_BIT(TIMER5->TIMx_CCER,3);

	/*CC1 channel is configured as input, IC1 is mapped on TI*/
	TIMER5->TIMx_CCMR1 &= 0xFFFFFFFC;
	TIMER5->TIMx_CCMR1 |= 1;

	/*Eight consecutive samples with the new level have been detected*/
	TIMER5->TIMx_CCMR1 &= 0xFFFFFF0F;
	TIMER5->TIMx_CCMR1 |= 3<<4;

	/*Capture is done each time an edge is detected on the capture input*/
	TIMER5->TIMx_CCMR1 &= 0xFFFFFFF3;

	/*The CCR1 register capture the value of register*/
	SET_BIT(TIMER5->TIMx_CCER,0);

	/*To reload the value in the auto-reload register*/
	TIMER5->TIMx_ARR = 65500;

	/*Enabling the interrupt*/
	SET_BIT(TIMER5->TIMx_DIER,1);

}

/* Function to enable the counter
 * */

void Timer5_voidEnableCounter(void)
{
	SET_BIT(TIMER5->TIMx_CR1,TIMER5_TIMx_CR1_CEN);
}

/* Function to disable the counter
 * */

void Timer5_voidDisableCounter(void)
{
	CLEAR_BIT(TIMER5->TIMx_CR1,TIMER5_TIMx_CR1_CEN);
}

/* Function to capture the value
 * */

u32 Timer5_u32CaptureValue(void)
{
	return TIMER5->TIMx_CCR1 ;
}

/* Function to configure rising edge
 * */

void Timer5_voidConfiguringRisingEdge(void)
{
	/*Select rising edge*/
	CLEAR_BIT(TIMER5->TIMx_CCER,1);
	CLEAR_BIT(TIMER5->TIMx_CCER,3);
}

/* Function to configure falling edge
 * */

void Timer5_voidConfiguringFallingEdge(void)
{
	/*Select falling edge*/
	SET_BIT(TIMER5->TIMx_CCER,1);
	CLEAR_BIT(TIMER5->TIMx_CCER,3);
}

/* Function to clear the counter
 * */

void Timer5_voidClearCounter(void)
{
	/*Clear the counter*/
	TIMER5->TIMx_CNT = 0;
}
void ICUCallback(void(*ptr)(void)){
	if(ptr != NULL){
		ptr1 = ptr;
	}
}
void TIM5_IRQHandler(void){
	CLEAR_BIT(TIMER5->TIMx_SR,TIMER5_TIMx_SR_CC1IF);
	if(ptr1 != NULL){
		ptr1();
	}
}


/******************************************************************************************************
 ******************************************************************************************************
 ******************************** AUTHOR  : Mahmoud Rabea *********************************************
 ******************************** MICRO   : STM32F401CCU6 *********************************************
 ******************************** LAYER   : MCAL          *********************************************
 ******************************** DRIVER  : TIMER_Driver  *********************************************
 ******************************** File    : program File  *********************************************
 ******************************** Date    : 12/7/2024     *********************************************
 ******************************** Version : 1.0           *********************************************
 ******************************************************************************************************
 ******************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "Timer2_private.h"
#include "Timer2_interface.h"


void (*ptr3)(void) = NULL;

/* Function to initialize the Timer2
 * */

void Timer2_voidInit(void)
{

	/*The division ratio between the timer clock (CK_INT) frequency and sampling clock used by the digital filters = 1 */
	CLEAR_BIT(TIMER2->TIMx_CR1,TIMER2_TIMx_CR1_CKD) ;
	CLEAR_BIT(TIMER2->TIMx_CR1,( TIMER2_TIMx_CR1_CKD + 1 )) ;

	/* To use the counter as up-counter*/
	CLEAR_BIT(TIMER2->TIMx_CR1,TIMER2_TIMx_CR1_DIR);

	/*The TIMx_CH1 pin is connected to TI1 input*/
	CLEAR_BIT(TIMER2->TIMx_CR2,TIMER2_TIMx_CR2_TI1S);

	/*To select the internal clock source*/
	CLEAR_BIT(TIMER2->TIMx_SMCR,0);
	CLEAR_BIT(TIMER2->TIMx_SMCR,1);
	CLEAR_BIT(TIMER2->TIMx_SMCR,2);

	/*The counter clock frequency CK_CNT is equal to frequency CK_PSC / ( TIMER2->TIMx_PSC + 1 ) */
	TIMER2->TIMx_PSC = 488;

	/*Select both edges*/
	SET_BIT(TIMER2->TIMx_CCER,1);
	SET_BIT(TIMER2->TIMx_CCER,3);

	/*Select rising edge*/
	//	CLEAR_BIT(TIMER5->TIMx_CCER,1);
	//	CLEAR_BIT(TIMER5->TIMx_CCER,3);

	//	/*CC1 channel is configured as input, IC1 is mapped on TI*/
	//	TIMER5->TIMx_CCMR1 &= 0xFFFFFFFC;
	//	TIMER5->TIMx_CCMR1 |= 1;

	/*Eight consecutive samples with the new level have been detected*/
	TIMER2->TIMx_CCMR1 &= 0xFFFFFF0F;
	TIMER2->TIMx_CCMR1 |= 3<<4;

	//	/*Capture is done each time an edge is detected on the capture input*/
	//	TIMER5->TIMx_CCMR1 &= 0xFFFFFFF3;

	/*The CCR1 register capture the value of register*/
	SET_BIT(TIMER2->TIMx_CCER,0);

	/*To reload the value in the auto-reload register*/
	TIMER2->TIMx_ARR = 65500;

	/*Enabling the interrupt*/
	//	SET_BIT(TIMER5->TIMx_DIER,1);
	SET_BIT(TIMER2->TIMx_CR1,TIMER2_TIMx_CR1_URS);
	CLEAR_BIT(TIMER2->TIMx_CR1,TIMER2_TIMx_CR1_UDIS);
	SET_BIT(TIMER2->TIMx_EGR,TIMER2_TIMx_EGR_UG);
	SET_BIT(TIMER2->TIMx_DIER,TIMER2_TIMx_DIER_UIE);

}

/* Function to enable the counter
 * */

void Timer2_voidEnableCounter(void)
{
	SET_BIT(TIMER2->TIMx_CR1,TIMER2_TIMx_CR1_CEN);
}

/* Function to clear the counter
 * */

void Timer2_voidClearCounter(void)
{
	/*Clear the counter*/
	TIMER2->TIMx_CNT = 0;
}

/* Function to disable the counter
 * */

void Timer2_voidDisableCounter(void)
{
	CLEAR_BIT(TIMER2->TIMx_CR1,TIMER2_TIMx_CR1_CEN);
}

void UpdateEventCallback(void(*ptr)(void))
{
	if(ptr != NULL){
		ptr3 = ptr;
	}
}

void TIM2_IRQHandler(void){
	CLEAR_BIT(TIMER2->TIMx_SR,TIMER2_TIMx_SR_UIF);
	if(ptr3 != NULL){
		ptr3();
	}
}

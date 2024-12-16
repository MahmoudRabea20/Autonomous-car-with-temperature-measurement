
/******************************************************************************************************
 ******************************************************************************************************
 ******************************** AUTHOR  : Mahmoud Rabea *********************************************
 ******************************** MICRO   : STM32F401CCU6 *********************************************
 ******************************** LAYER   : MCAL          *********************************************
 ******************************** DRIVER  : TIMER_Driver  *********************************************
 ******************************** File    : private File  *********************************************
 ******************************** Date    : 12/7/2024     *********************************************
 ******************************** Version : 1.0           *********************************************
 ******************************************************************************************************
 ******************************************************************************************************/

#ifndef TIMER2_PRIVATE_H_
#define TIMER2_PRIVATE_H_

typedef struct
{
	volatile u32 TIMx_CR1;
	volatile u32 TIMx_CR2;
	volatile u32 TIMx_SMCR;
	volatile u32 TIMx_DIER;
	volatile u32 TIMx_SR;
	volatile u32 TIMx_EGR;
	volatile u32 TIMx_CCMR1;
	volatile u32 TIMx_CCMR2;
	volatile u32 TIMx_CCER;
	volatile u32 TIMx_CNT;
	volatile u32 TIMx_PSC;
	volatile u32 TIMx_ARR;
	volatile u32 Reserved0;
	volatile u32 TIMx_CCR1;
	volatile u32 TIMx_CCR2;
	volatile u32 TIMx_CCR3;
	volatile u32 TIMx_CCR4;
	volatile u32 Reserved1;
	volatile u32 TIMx_DCR;
	volatile u32 TIMx_DMAR;
	volatile u32 TIM2_OR;
}TIMERS_T;


#define TIMER2_BASE_ADDRESS                  0x40000000
#define TIMER2                               ((volatile TIMERS_T*)TIMER2_BASE_ADDRESS)


#define TIMER2_TIMx_CR1_CKD                  8
#define TIMER2_TIMx_CR1_DIR                  4
#define TIMER2_TIMx_CR1_CEN                  0
#define TIMER2_TIMx_CR2_TI1S                 7
#define TIMER2_TIMx_CR1_URS                  2
#define TIMER2_TIMx_CR1_UDIS                 1
#define TIMER2_TIMx_EGR_UG                   0
#define TIMER2_TIMx_EGR_UG                   0
#define TIMER2_TIMx_DIER_UIE                 0
#define TIMER2_TIMx_SR_UIF                   0

//#define TIMER5_TIMx_SR_CC1IF               1



#endif /* TIMER2_PRIVATE_H_ */

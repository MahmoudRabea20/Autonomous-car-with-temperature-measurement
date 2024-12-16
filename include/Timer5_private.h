
/******************************************************************************************************
 ******************************************************************************************************
 ******************************** AUTHOR  : Mahmoud Rabea *********************************************
 ******************************** MICRO   : STM32F401CCU6 *********************************************
 ******************************** LAYER   : MCAL          *********************************************
 ******************************** DRIVER  : TIMER_Driver  *********************************************
 ******************************** File    : private File  *********************************************
 ******************************** Date    : 25/4/2024     *********************************************
 ******************************** Version : 1.0           *********************************************
 ******************************************************************************************************
 ******************************************************************************************************/

#ifndef TIMER5_PRIVATE_H_
#define TIMER5_PRIVATE_H_


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

#define TIMER3_BASE_ADDRESS                  0x40000400
#define TIMER3                               ((volatile TIMERS_T*)TIMER3_BASE_ADDRESS)

#define TIMER4_BASE_ADDRESS                  0x40000800
#define TIMER4                               ((volatile TIMERS_T*)TIMER4_BASE_ADDRESS)

#define TIMER5_BASE_ADDRESS                  0x40000C00
#define TIMER5                               ((volatile TIMERS_T*)TIMER5_BASE_ADDRESS)

#define TIMER5_TIMx_CR1_CKD                  8
#define TIMER5_TIMx_CR1_DIR                  4
#define TIMER5_TIMx_CR1_CEN                  0

#define TIMER5_TIMx_CR2_TI1S                 7

#define TIMER5_TIMx_SR_CC1IF                 1

#endif /* TIMER5_PRIVATE_H_ */

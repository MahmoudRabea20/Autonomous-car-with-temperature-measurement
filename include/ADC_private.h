
/******************************************************************************************************
 ******************************************************************************************************
 ******************************** AUTHOR  : Mahmoud Rabea *********************************************
 ******************************** MICRO   : STM32F401CCU6 *********************************************
 ******************************** LAYER   : MCAL          *********************************************
 ******************************** DRIVER  : ADC_Driver    *********************************************
 ******************************** File    : private File  *********************************************
 ******************************** Date    : 27/6/2024     *********************************************
 ******************************** Version : 1.0           *********************************************
 ******************************************************************************************************
 ******************************************************************************************************/

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

typedef struct
{
	volatile u32 ADC_SR                     ;
	volatile u32 ADC_CR1                    ;
	volatile u32 ADC_CR2                    ;
	volatile u32 ADC_SMPR1                  ;
	volatile u32 ADC_SMPR2                  ;
	volatile u32 ADC_JOFR1                  ;
	volatile u32 ADC_JOFR2                  ;
	volatile u32 ADC_JOFR3                  ;
	volatile u32 ADC_JOFR4                  ;
	volatile u32 ADC_HTR                    ;
	volatile u32 ADC_LTR                    ;
	volatile u32 ADC_SQR1                   ;
	volatile u32 ADC_SQR2                   ;
	volatile u32 ADC_SQR3                   ;
	volatile u32 ADC_JSQR                   ;
	volatile u32 ADC_JDR1                   ;
	volatile u32 ADC_JDR2                   ;
	volatile u32 ADC_JDR3                   ;
	volatile u32 ADC_JDR4                   ;
	volatile u32 ADC_DR                     ;
}ADC_T;

#define ADC1_BASE_ADDRESS                    0x40012000
#define ADC                                 ((volatile ADC_T*)ADC1_BASE_ADDRESS)

#define ADC_COMM_REG_BASE_ADDRESSS          0x40012304
#define ADC_CCR                             (*((volatile u32 *)ADC_COMM_REG_BASE_ADDRESSS))

#define ADC_SR_EOC                          1
#define ADC_CR2_SWSTART                     30
#define ADC_CR2_ADON                        0
#define ADC_CR2_ALIGN                       11
#define ADC_CR2_CONT                        1
#define ADC_CR1_EOCIE                       5



#endif /* ADC_PRIVATE_H_ */


/******************************************************************************************************
 ******************************************************************************************************
 ******************************** AUTHOR  : Mahmoud Rabea  ********************************************
 ******************************** MICRO   : STM32F401CCU6  ********************************************
 ******************************** LAYER   : MCAL           ********************************************
 ******************************** DRIVER  : RCC_Driver     ********************************************
 ******************************** File    : interface File ********************************************
 ******************************** Date    : 19/8/2023      ********************************************
 ******************************** Version : 1.0            ********************************************
 ******************************************************************************************************
 ******************************************************************************************************/


#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

void MRCC_voidInit(void);
ES_t MRCC_enuEnablePeripheral(u8 Copy_u8BusName,u8 Copy_u8PeripheralName);
ES_t MRCC_enuDisablePeripheral(u8 Copy_u8BusName,u8 Copy_u8PeripheralName);


#define RCC_AHB1_BUS		    0

/*      Peripheral of AHB1 bus  */
#define RCC_AHB1ENR_GPIOA	    0
#define RCC_AHB1ENR_GPIOB	    1
#define RCC_AHB1ENR_GPIOC	    2
#define RCC_AHB1ENR_GPIOD	    3
#define RCC_AHB1ENR_GPIOE	    4
#define RCC_AHB1ENR_GPIOH	    7
#define RCC_AHB1ENR_CRC		    12
#define RCC_AHB1ENR_DMA1	    21
#define RCC_AHB1ENR_DMA2		22

/********************************/

#define RCC_AHB2_BUS	     	1

/*      Peripheral of AHB2 bus  */
#define RCC_AHB2ENR_OTGFS       7

/*******************************/

#define RCC_APB1_BUS		   2

/*      Peripheral of APB1 bus */
#define RCC_APB1ENR_TIM2       0
#define RCC_APB1ENR_TIM3       1
#define RCC_APB1ENR_TIM4       2
#define RCC_APB1ENR_TIM5       3
#define RCC_APB1ENR_WWDG       11
#define RCC_APB1ENR_SPI2       14
#define RCC_APB1ENR_SPI3       15
#define RCC_APB1ENR_USART2     17
#define RCC_APB1ENR_I2C1       21
#define RCC_APB1ENR_I2C2       22
#define RCC_APB1ENR_I2C3       23
#define RCC_APB1ENR_PWR        28

/********************************/

#define RCC_APB2_BUS	     	3

/*      Peripheral of APB2 bus  */
#define RCC_APB2ENR_TIM1        0
#define RCC_APB2ENR_USAER1      4
#define RCC_APB2ENR_USAERT6     5
#define RCC_APB2ENR_ADC1        8
#define RCC_APB2ENR_SDIO        11
#define RCC_APB2ENR_SPI1        12
#define RCC_APB2ENR_SPI4        13
#define RCC_APB2ENR_SYSCFG      14
#define RCC_APB2ENR_TIM9        16
#define RCC_APB2ENR_TIM10       17
#define RCC_APB2ENR_TIM11       18


#endif /* RCC_INTERFACE_H_ */

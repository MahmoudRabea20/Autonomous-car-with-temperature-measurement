
/******************************************************************************************************
 ******************************************************************************************************
 ******************************** AUTHOR  : Mahmoud Rabea *********************************************
 ******************************** MICRO   : STM32F401CCU6 *********************************************
 ******************************** LAYER   : MCAL          *********************************************
 ******************************** DRIVER  : GPIO_Driver   *********************************************
 ******************************** File    : private File  *********************************************
 ******************************** Date    : 20/8/2023     *********************************************
 ******************************** Version : 1.0           *********************************************
 ******************************************************************************************************
 ******************************************************************************************************/

#include "BIT_MATHS.h"
#include "STD_TYPES.h"

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

typedef struct{
	volatile u32 GPIO_MODER ;
	volatile u32 GPIO_OTYPER;
	volatile u32 GPIO_OSPEEDR;
	volatile u32 GPIO_PUPDR;
	volatile u32 GPIO_IDR;
	volatile u32 GPIO_ODR;
	volatile u32 GPIO_BSRR;
	volatile u32 GPIO_LCKR;
	volatile u32 GPIO_AFRL;
	volatile u32 GPIO_AFRH;
}GPIO_T;

#define GPIOA_BASE_ADDRESS             0x40020000
#define GPIOB_BASE_ADDRESS             0x40020400
#define GPIOC_BASE_ADDRESS             0x40020800

#define GPIOA                         ((volatile GPIO_T*)GPIOA_BASE_ADDRESS)
#define GPIOB                         ((volatile GPIO_T*)GPIOB_BASE_ADDRESS)
#define GPIOC                         ((volatile GPIO_T*)GPIOC_BASE_ADDRESS)

#define MGPIO_ONE_BIT_MASK            1
#define MGPIO_TWO_BIT_MASK            3
#define MGPIO_FOUR_BIT_MASK           15
#define MGPIO_BIT_SIXTEEN             16
#define MGPIO_PIN_EIGHT               8
#define MGPIO_MODER_BITS              2
#define MGPIO_AF_SELEION_BITS         4



#endif /* GPIO_PRIVATE_H_ */


/******************************************************************************************************
 ******************************************************************************************************
 ******************************** AUTHOR  : Mahmoud Rabea  ********************************************
 ******************************** MICRO   : STM32F401CCU6  ********************************************
 ******************************** LAYER   : MCAL           ********************************************
 ******************************** DRIVER  : RCC_Driver     ********************************************
 ******************************** File    : private File   ********************************************
 ******************************** Date    : 19/8/2023      ********************************************
 ******************************** Version : 1.0            ********************************************
 ******************************************************************************************************
 ******************************************************************************************************/


#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

typedef struct{
	volatile u32 RCC_CR;
	volatile u32 RCC_PLLCFGR;
	volatile u32 RCC_CFGR;
	volatile u32 RCC_CIR;
	volatile u32 RCC_AHB1RST;
	volatile u32 RCC_AHB2RST;
	volatile u32 Reserved1;
	volatile u32 Reserved2;
	volatile u32 RCC_APB1RST;
	volatile u32 RCC_APB2RST;
	volatile u32 Reserved3;
	volatile u32 Reserved4;
	volatile u32 RCC_AHB1ENR;
	volatile u32 RCC_AHB2ENR;
	volatile u32 Reserved5;
	volatile u32 Reserved6;
	volatile u32 RCC_APB1ENR;
	volatile u32 RCC_APB2ENR;
	volatile u32 Reserved7;
	volatile u32 Reserved8;
	volatile u32 RCC_AHB1LPENR;
	volatile u32 RCC_AHB2LPENR;
	volatile u32 Reserved9;
	volatile u32 Reserved10;
	volatile u32 RCC_APB1LPENR;
	volatile u32 RCC_APB2LPENR;
	volatile u32 Reserved11;
	volatile u32 Reserved12;
	volatile u32 RCC_BDCR;
	volatile u32 RCC_CSR;
	volatile u32 Reserved13;
	volatile u32 Reserved14;
	volatile u32 RCC_SSCGR;
	volatile u32 RCC_PLLI2SCFGR;
	volatile u32 Reserved15;
	volatile u32 RCC_DCKCFGR;
}RCC_T;

#define RCC_BASE_ADDRESS                  0x40023800
#define RCC                               ((volatile RCC_T*)RCC_BASE_ADDRESS)

#define RCC_SYSCLK_SOURCE_HSE             1
#define RCC_SYSCLK_SOURCE_HSI             2
#define RCC_SYSCLK_SOURCE_PLL             3

#define RCC_CFGR_SW0                      0
#define RCC_CFGR_SW1                      1

#define RCC_CR_HSI_ON                     0
#define RCC_CR_HSI_RDY                    1

#define RCC_SYSCLK_HSE_BYPASS             1
#define RCC_SYSCLK_HSE_CRYSTAL            2

#define RCC_CR_HSE_ON                     16
#define RCC_CR_HSE_RDY                    17
#define RCC_CR_HSE_BYP					  18

#define RCC_CR_PLL_ON                     24
#define RCC_CR_PLL_RDY                    25

#define RCC_SYSCLK_PLL_HSI                1
#define RCC_SYSCLK_PLL_HSE                2

#define RCC_PLLCFGR_PLLSRC                22

#define RCC_SYSCLK_PLL_PLLN2               2
#define RCC_SYSCLK_PLL_PLLN3               3
#define RCC_SYSCLK_PLL_PLLN4               4
#define RCC_SYSCLK_PLL_PLLN5               5
#define RCC_SYSCLK_PLL_PLLN6               6
#define RCC_SYSCLK_PLL_PLLN7               7
#define RCC_SYSCLK_PLL_PLLN8               8
#define RCC_SYSCLK_PLL_PLLN9               9
#define RCC_SYSCLK_PLL_PLLN10              10
/******************************************/
#define RCC_SYSCLK_PLL_PLLN160             160
/******************************************/
#define RCC_SYSCLK_PLL_PLLN429             429
#define RCC_SYSCLK_PLL_PLLN430             430
#define RCC_SYSCLK_PLL_PLLN431             431
#define RCC_SYSCLK_PLL_PLLN432             432


#define RCC_SYSCLK_PLL_PLLM2               2
#define RCC_SYSCLK_PLL_PLLM3               3
#define RCC_SYSCLK_PLL_PLLM4               4
#define RCC_SYSCLK_PLL_PLLM5               5
#define RCC_SYSCLK_PLL_PLLM6               6
#define RCC_SYSCLK_PLL_PLLM7               7
#define RCC_SYSCLK_PLL_PLLM8               8
#define RCC_SYSCLK_PLL_PLLM9               9
#define RCC_SYSCLK_PLL_PLLM10              10
/******************************************/
#define RCC_SYSCLK_PLL_PLLM30              30
/******************************************/
#define RCC_SYSCLK_PLL_PLLM61              61
#define RCC_SYSCLK_PLL_PLLM62              62
#define RCC_SYSCLK_PLL_PLLM63              63


#define RCC_SYSCLK_PLL_PLLP2              2
#define RCC_SYSCLK_PLL_PLLP4              4
#define RCC_SYSCLK_PLL_PLLP6              6
#define RCC_SYSCLK_PLL_PLLP8              8

#define RCC_PLLCFGR_PLLM0                 0
#define RCC_PLLCFGR_PLLN6                 6
#define RCC_PLLCFGR_PLLP16                16

#endif /* RCC_PRIVATE_H_ */

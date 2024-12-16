
/******************************************************************************************************
 ******************************************************************************************************
 ******************************** AUTHOR  : Mahmoud Rabea *********************************************
 ******************************** MICRO   : STM32F401CCU6 *********************************************
 ******************************** LAYER   : MCAL          *********************************************
 ******************************** DRIVER  : RCC_Driver    *********************************************
 ******************************** File    : config File   *********************************************
 ******************************** Date    : 19/8/2023     *********************************************
 ******************************** Version : 1.0           *********************************************
 ******************************************************************************************************
 ******************************************************************************************************/


#ifndef RCC_CONFIGURATION_H_
#define RCC_CONFIGURATION_H_

/* RCC_SYSCLK_SOURCE =
 *        Options :
 *                1- RCC_SYSCLK_SOURCE_HSE
 *                2- RCC_SYSCLK_SOURCE_HSI
 *                3- RCC_SYSCLK_SOURCE_PLL
 * */

#define RCC_SYSCLK_SOURCE  RCC_SYSCLK_SOURCE_HSI

/* RCC_SYSCLK_HSE =
 *        Options :
 *                1- RCC_SYSCLK_HSE_BYPASS
 *                2- RCC_SYSCLK_HSE_CRYSTAL
 * */


#define RCC_SYSCLK_HSE  RCC_SYSCLK_HSE_BYPASS

/* RCC_SYSCLK_PLL =
 *        Options :
 *                1- RCC_SYSCLK_PLL_HSI
 *                2- RCC_SYSCLK_PLL_HSE
 * */

#define RCC_SYSCLK_PLL RCC_SYSCLK_PLL_HSI

/* RCC_SYSCLK_PLL_PLLN =
 *          Options : From RCC_SYSCLK_PLL_PLLN2  ----->    RCC_SYSCLK_PLL_PLLN432
 * */

#define RCC_SYSCLK_PLL_PLLN  RCC_SYSCLK_PLL_PLLN160

/* RCC_SYSCLK_PLL_PLLM =
 *          Options : From RCC_SYSCLK_PLL_PLLM2  ----->    RCC_SYSCLK_PLL_PLLM63
 * */

#define RCC_SYSCLK_PLL_PLLM  RCC_SYSCLK_PLL_PLLM8

/* RCC_SYSCLK_PLL_PLLP =
 *          Options : From RCC_SYSCLK_PLL_PLLP2  - RCC_SYSCLK_PLL_PLLP4 - RCC_SYSCLK_PLL_PLLP6 - RCC_SYSCLK_PLL_PLLP8
 * */

#define RCC_SYSCLK_PLL_PLLP  RCC_SYSCLK_PLL_PLLP8

#endif /* RCC_CONFIGURATION_H_ */


/******************************************************************************************************
 ******************************************************************************************************
 ******************************** AUTHOR  : Mahmoud Rabea  ********************************************
 ******************************** MICRO   : STM32F401CCU6  ********************************************
 ******************************** LAYER   : MCAL           ********************************************
 ******************************** DRIVER  : UART_Driver    ********************************************
 ******************************** File    : config File    ********************************************
 ******************************** Date    : 4/9/2023       ********************************************
 ******************************** Version : 1.0            ********************************************
 ******************************************************************************************************
 ******************************************************************************************************/

#ifndef UART_COMFIGURATION_H_
#define UART_COMFIGURATION_H_

/* MUART_UART1_ENABLING =
 *             Options  : 1- MUART_UART1_ENABLING_ENABLE
 *                        2- MUART_UART1_ENABLING_DISABLE
 * */

#define MUART_UART1_ENABLING	MUART_UART1_ENABLING_DISABLE

/* MUART_UART2_ENABLING =
 *             Options  : 1- MUART_UART2_ENABLING_ENABLE
 *                        2- MUART_UART2_ENABLING_DISABLE
 * */

#define MUART_UART2_ENABLING	MUART_UART2_ENABLING_ENABLE

/* MUART_UART6_ENABLING =
 *             Options  : 1- MUART_UART6_ENABLING_ENABLE
 *                        2- MUART_UART6_ENABLING_DISABLE
 * */

#define MUART_UART6_ENABLING	MUART_UART6_ENABLING_DISABLE

#endif /* UART_COMFIGURATION_H_ */

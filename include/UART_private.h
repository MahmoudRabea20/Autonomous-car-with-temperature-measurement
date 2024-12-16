
/******************************************************************************************************
 ******************************************************************************************************
 ******************************** AUTHOR  : Mahmoud Rabea  ********************************************
 ******************************** MICRO   : STM32F401CCU6  ********************************************
 ******************************** LAYER   : MCAL           ********************************************
 ******************************** DRIVER  : UART_Driver    ********************************************
 ******************************** File    : private File   ********************************************
 ******************************** Date    : 4/9/2023       ********************************************
 ******************************** Version : 1.0            ********************************************
 ******************************************************************************************************
 ******************************************************************************************************/

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

typedef struct
{
	volatile u32 USART_SR                 ;
	volatile u32 USART_DR                 ;
	volatile u32 USART_BRR                ;
	volatile u32 USART_CR1                ;
	volatile u32 USART_CR2                ;
	volatile u32 USART_CR3                ;
	volatile u32 USART_GTPR               ;
}UART_T;


#define UART1_BASE_ADDRESS                0x40011000
#define UART2_BASE_ADDRESS                0x40004400
#define UART6_BASE_ADDRESS                0x40011400

#define UART1                             ((volatile UART_T*)UART1_BASE_ADDRESS)
#define UART2                             ((volatile UART_T*)UART2_BASE_ADDRESS)
#define UART6                             ((volatile UART_T*)UART6_BASE_ADDRESS)

#define MUART_UART1_ENABLING_ENABLE       1
#define MUART_UART1_ENABLING_DISABLE      2

#define MUART_UART2_ENABLING_ENABLE       3
#define MUART_UART2_ENABLING_DISABLE      4

#define MUART_UART6_ENABLING_ENABLE       5
#define MUART_UART6_ENABLING_DISABLE      6

#define MUART_USART_SR_TC                 6
#define MUART_USART_SR_TXE                7
#define MUART_USART_SR_RXNE               5
#define MUART_USART_CR1_OVER8             15
#define MUART_USART_CR1_UE                13
#define MUART_USART_CR1_M                 12
#define MUART_USART_CR1_PCE               10
#define MUART_USART_CR1_TE                3
#define MUART_USART_CR1_RE                2
#define MUART_USART_CR2_STOP_BIT1         12
#define MUART_USART_CR2_STOP_BIT2         13

#endif /* UART_PRIVATE_H_ */

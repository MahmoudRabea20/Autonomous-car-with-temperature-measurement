
/******************************************************************************************************
 ******************************************************************************************************
 ******************************** AUTHOR  : Mahmoud Rabea  ********************************************
 ******************************** MICRO   : STM32F401CCU6  ********************************************
 ******************************** LAYER   : MCAL           ********************************************
 ******************************** DRIVER  : UART_Driver    ********************************************
 ******************************** File    : program File   ********************************************
 ******************************** Date    : 4/9/2023       ********************************************
 ******************************** Version : 1.0            ********************************************
 ******************************************************************************************************
 ******************************************************************************************************/

#include "BIT_MATHS.h"
#include "STD_TYPES.h"

#include "UART_private.h"
#include "UART_configuration.h"
#include "UART_interface.h"

/* Argument   : Nothing
 * Return     : Nothing
 * Operations : To initialize the UART
 * */

void MUART_voidInit(void)
{

#if MUART_UART1_ENABLING == MUART_UART1_ENABLING_ENABLE

	/* Clear ALL */
	UART1->USART_CR1 = 0x00;

	/* Let baud rate = 19.2 KBps, clock = 12MHz and OVER8 = 0 */
	UART1->USART_BRR = 0x00000271 ;

	/*Over sampling mode by 8*/
	SET_BIT(UART1->USART_CR1,MUART_USART_CR1_OVER8);

	/* Select Word length 8 data bit*/
	CLEAR_BIT(UART1->USART_CR1,MUART_USART_CR1_M);

	/* Disable parity bit */
	CLEAR_BIT(UART1->USART_CR1,MUART_USART_CR1_PCE);

	/* 0 stop bit */
	CLEAR_BIT(UART1->USART_CR2,MUART_USART_CR2_STOP_BIT1);
	CLEAR_BIT(UART1->USART_CR2,MUART_USART_CR2_STOP_BIT2);

	/* Enable the transmitter */
	SET_BIT(UART1->USART_CR1,MUART_USART_CR1_TE);

	/* Enable the receiver */
	SET_BIT(UART1->USART_CR1,MUART_USART_CR1_RE);

	/* Enable UART */
	SET_BIT(UART1->USART_CR1,MUART_USART_CR1_UE);

#endif

#if MUART_UART2_ENABLING == MUART_UART2_ENABLING_ENABLE

	/* Clear ALL */
	UART2->USART_CR1 = 0x00;

	/* Let baud rate = 19.2 KBps, clock = 12MHz and OVER8 = 0 */
	UART2->USART_BRR = 0x00000271 ;

	/*Over sampling mode by 8*/
	SET_BIT(UART2->USART_CR1,MUART_USART_CR1_OVER8);

	/* Select Word length 8 data bit*/
	CLEAR_BIT(UART2->USART_CR1,MUART_USART_CR1_M);

	/* Disable parity bit */
	CLEAR_BIT(UART2->USART_CR1,MUART_USART_CR1_PCE);

	/* 0 stop bit */
	CLEAR_BIT(UART2->USART_CR2,MUART_USART_CR2_STOP_BIT1);
	CLEAR_BIT(UART2->USART_CR2,MUART_USART_CR2_STOP_BIT2);

	/* Enable the transmitter */
	SET_BIT(UART2->USART_CR1,MUART_USART_CR1_TE);

	/* Enable the receiver */
	SET_BIT(UART2->USART_CR1,MUART_USART_CR1_RE);

	/* Enable UART */
	SET_BIT(UART2->USART_CR1,MUART_USART_CR1_UE);

#endif

#if MUART_UART6_ENABLING == MUART_UART6_ENABLING_ENABLE

	/* Clear ALL */
	UART6->USART_CR1 = 0x00;

	/* Let baud rate = 19.2 KBps, clock = 12MHz and OVER8 = 0 */
	UART6->USART_BRR = 0x00000271 ;

	/*Over sampling mode by 8*/
	SET_BIT(UART6->USART_CR1,MUART_USART_CR1_OVER8);

	/* Select Word length 8 data bit*/
	CLRAR_BIT(UART6->USART_CR1,MUART_USART_CR1_M);

	/* Disable parity bit */
	CLEAR_BIT(UART6->USART_CR1,MUART_USART_CR1_PCE);

	/* 0 stop bit */
	CLEAR_BIT(UART6->USART_CR2,MUART_USART_CR2_STOP_BIT1);
	CLEAR_BIT(UART6->USART_CR2,MUART_USART_CR2_STOP_BIT2);

	/* Enable the transmitter */
	SET_BIT(UART6->USART_CR1,MUART_USART_CR1_TE);

	/* Enable the receiver */
	SET_BIT(UART6->USART_CR1,MUART_USART_CR1_RE);

	/* Enable UART */
	SET_BIT(UART6->USART_CR1,MUART_USART_CR1_UE);

#endif

}

/* Argument   : The character that will be transmitted
 * Return     : Nothing
 * Operations : To send character from this device to an another device
 * */

void MUART_voidSendCharacter(u16 Copy_u16TransmittedCharacter)
{
#if MUART_UART1_ENABLING == MUART_UART1_ENABLING_ENABLE

	UART1->USART_DR = Copy_u16TransmittedCharacter ;
	while(GET_BIT(UART1->USART_SR,MUART_USART_SR_TC) == 0 );

#endif

#if MUART_UART2_ENABLING == MUART_UART2_ENABLING_ENABLE

	UART2->USART_DR = Copy_u16TransmittedCharacter ;
	while(GET_BIT(UART2->USART_SR,MUART_USART_SR_TC) == 0 );

#endif

#if MUART_UART6_ENABLING == MUART_UART6_ENABLING_ENABLE

	UART6->USART_DR = Copy_u16TransmittedCharacter ;
	while(GET_BIT(UART6->USART_SR,MUART_USART_SR_TC) == 0 );

#endif

}

/* Argument   : Nothing
 * Return     : The character that will be received
 * Operations : To receive character from an another device
 * */

u16 MUART_u16ReceiveCharacter(void)
{
#if MUART_UART1_ENABLING == MUART_UART1_ENABLING_ENABLE

	while(GET_BIT(UART1->USART_SR,MUART_USART_SR_RXNE) == 0 );
	return UART1->USART_DR ;

#endif

#if MUART_UART2_ENABLING == MUART_UART2_ENABLING_ENABLE

	while(GET_BIT(UART2->USART_SR,MUART_USART_SR_RXNE) == 0 );
	return UART2->USART_DR ;

#endif

#if MUART_UART6_ENABLING == MUART_UART6_ENABLING_ENABLE

	while(GET_BIT(UART6->USART_SR,MUART_USART_SR_RXNE) == 0 );
	return UART6->USART_DR ;

#endif

}

/* Argument   : String
 * Return     : Error State
 * Operations : To send string to an another device
 * */

ES_t MUART_enuSendString(const char* Copy_pchString)
{
	ES_t Local_enuErrorState = ES_OK;
	u8 Local_u8Counter = 0;

#if MUART_UART1_ENABLING == MUART_UART1_ENABLING_ENABLE

	if(Copy_pchString != NULL)
	{
		while(Copy_pchString[Local_u8Counter] !='\0')
		{
			MUART_voidSendCharacter(Copy_pchString[Local_u8Counter]);
			Local_u8Counter++ ;
		}
	}
	else
	{
		Local_enuErrorState = NULL_POINTER;
	}

#endif

#if MUART_UART2_ENABLING == MUART_UART2_ENABLING_ENABLE

	if(Copy_pchString != NULL)
	{
		while(Copy_pchString[Local_u8Counter] !='\0')
		{
			MUART_voidSendCharacter(Copy_pchString[Local_u8Counter]);
			Local_u8Counter++ ;
		}
	}
	else
	{
		Local_enuErrorState = NULL_POINTER;
	}

#endif

#if MUART_UART6_ENABLING == MUART_UART6_ENABLING_ENABLE

	if(Copy_pchString != NULL)
	{
		while(Copy_pchString[Local_u8Counter] !='\0')
		{
			MUART_voidSendCharacter(Copy_pchString[Local_u8Counter]);
			Local_u8Counter++ ;
		}
	}
	else
	{
		Local_enuErrorState = NULL_POINTER;
	}

#endif

	return Local_enuErrorState;
}

/* Argument   : Nothing
 * Return     : The string that will be received
 * Operations : To receive string from an another device
 * */

ES_t MUART_enuReceiveString(u8* Copy_Au8ArrayOfCharacter)
{
	ES_t Local_enuErrorState = ES_OK ;
	s8 Local_u8Counter = -1 ;

#if MUART_UART1_ENABLING == MUART_UART1_ENABLING_ENABLE

	while(GET_BIT(UART1->USART_SR,MUART_USART_SR_RXNE) == 0 );
	return UART1->USART_DR ;

#endif

#if MUART_UART2_ENABLING == MUART_UART2_ENABLING_ENABLE

	do
	{
		Local_u8Counter++ ;
		while(GET_BIT(UART2->USART_SR,MUART_USART_SR_RXNE) == 0 );
		Copy_Au8ArrayOfCharacter[Local_u8Counter] = UART2->USART_DR ;

	}while(Copy_Au8ArrayOfCharacter[Local_u8Counter] != '#');


#endif

#if MUART_UART6_ENABLING == MUART_UART6_ENABLING_ENABLE

	while(GET_BIT(UART6->USART_SR,MUART_USART_SR_RXNE) == 0 );
	return UART6->USART_DR ;

#endif

	return Local_enuErrorState;
}


/******************************************************************************************************
 ******************************************************************************************************
 ******************************** AUTHOR  : Mahmoud Rabea *********************************************
 ******************************** MICRO   : STM32F401CCU6 *********************************************
 ******************************** LAYER   : MCAL          *********************************************
 ******************************** DRIVER  : GPIO_Driver   *********************************************
 ******************************** File    : program File  *********************************************
 ******************************** Date    : 20/8/2023     *********************************************
 ******************************** Version : 1.0           *********************************************
 ******************************************************************************************************
 ******************************************************************************************************/


#include "BIT_MATHS.h"
#include "STD_TYPES.h"

#include "GPIO_private.h"
#include "GPIO_configuration.h"
#include "GPIO_interface.h"

/* Argument  : Port Id   ,  Pin Id   ,  Pin Direction Mode
 * Return    : Error State (enum)
 * Operation : To set pin direction mode
 * */

ES_t MGPIO_enuSetPinDirectionMode(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinDirectionMode)
{
	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_u8PortId <= MGPIO_PORTC ) && (Copy_u8PinId <= MGPIO_PIN15) && (Copy_u8PinDirectionMode <= MGPIO_ANALOG) )
	{
		if((Copy_u8PortId == MGPIO_PORTC ) && ((Copy_u8PinId != MGPIO_PIN13 ) && (Copy_u8PinId != MGPIO_PIN14) && ((Copy_u8PinId != MGPIO_PIN15 ))))
		{
			return Local_enuErrorState;
		}

		switch(Copy_u8PortId)
		{
		case MGPIO_PORTA:
			GPIOA->GPIO_MODER &= ~( MGPIO_TWO_BIT_MASK << ( Copy_u8PinId * MGPIO_MODER_BITS) );
			GPIOA->GPIO_MODER |= Copy_u8PinDirectionMode << ( Copy_u8PinId * MGPIO_MODER_BITS) ;
			break;
		case MGPIO_PORTB:
			GPIOB->GPIO_MODER &= ~( MGPIO_TWO_BIT_MASK << ( Copy_u8PinId * MGPIO_MODER_BITS) );
			GPIOB->GPIO_MODER |= Copy_u8PinDirectionMode << ( Copy_u8PinId * MGPIO_MODER_BITS) ;
			break;
		case MGPIO_PORTC:
			GPIOC->GPIO_MODER &= ~( MGPIO_TWO_BIT_MASK << ( Copy_u8PinId * MGPIO_MODER_BITS) );
			GPIOC->GPIO_MODER |= Copy_u8PinDirectionMode << ( Copy_u8PinId * MGPIO_MODER_BITS) ;
			break;
		default :
			break;
		}

		Local_enuErrorState = ES_OK;
	}

	return Local_enuErrorState;
}

/* Argument  : Port Id  ,  Port Direction Mode
 * Return    : Error State (enum)
 * Operation : To set port direction mode
 * */

ES_t MGPIO_enuSetPortDirectionMode(u8 Copy_u8PortId, u8 Copy_u8PinDirectionMode)
{
	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_u8PortId <= MGPIO_PORTC ) && (Copy_u8PinDirectionMode <= MGPIO_ANALOG) )
	{
		switch(Copy_u8PortId)
		{
		case MGPIO_PORTA:
			for(u8 Local_u8Iter = 0 ; Local_u8Iter < 32 ; Local_u8Iter += 2)
			{
				GPIOA->GPIO_MODER &= ~( MGPIO_TWO_BIT_MASK << Local_u8Iter );
				GPIOA->GPIO_MODER |= Copy_u8PinDirectionMode << Local_u8Iter ;
			}
			break;
		case MGPIO_PORTB:
			for(u8 Local_u8Iter = 0 ; Local_u8Iter < 32 ; Local_u8Iter += 2)
			{
				GPIOB->GPIO_MODER &= ~( MGPIO_TWO_BIT_MASK << Local_u8Iter );
				GPIOB->GPIO_MODER |= Copy_u8PinDirectionMode << Local_u8Iter ;
			}
			break;
		case MGPIO_PORTC:
			for(u8 Local_u8Iter = 0 ; Local_u8Iter < 32 ; Local_u8Iter += 2)
			{
				GPIOC->GPIO_MODER &= ~( MGPIO_TWO_BIT_MASK << Local_u8Iter );
				GPIOC->GPIO_MODER |= Copy_u8PinDirectionMode << Local_u8Iter ;
			}
			break;
		default :
			break;
		}

		Local_enuErrorState = ES_OK;
	}

	return Local_enuErrorState;
}

/* Argument  : Port Id   ,  Pin Id   , Pin Output Type
 * Return    : Error State (enum)
 * Operation : To set pin output type
 * */

ES_t MGPIO_enuSetOutputType(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinOutputType)
{
	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_u8PortId <= MGPIO_PORTC ) && (Copy_u8PinId <= MGPIO_PIN15) && (Copy_u8PinOutputType <= MGPIO_OPEN_DRAIN) )
	{
		if((Copy_u8PortId == MGPIO_PORTC ) && ((Copy_u8PinId != MGPIO_PIN13 ) && (Copy_u8PinId != MGPIO_PIN14) && ((Copy_u8PinId != MGPIO_PIN15 ))))
		{
			return Local_enuErrorState;
		}

		switch(Copy_u8PortId)
		{
		case MGPIO_PORTA:
			GPIOA->GPIO_OTYPER &= ~( MGPIO_ONE_BIT_MASK <<  Copy_u8PinId );
			GPIOA->GPIO_OTYPER |= Copy_u8PinOutputType <<  Copy_u8PinId ;
			break;
		case MGPIO_PORTB:
			GPIOB->GPIO_OTYPER &= ~( MGPIO_ONE_BIT_MASK <<  Copy_u8PinId );
			GPIOB->GPIO_OTYPER |= Copy_u8PinOutputType <<  Copy_u8PinId ;
			break;
		case MGPIO_PORTC:
			GPIOC->GPIO_OTYPER &= ~( MGPIO_ONE_BIT_MASK <<  Copy_u8PinId );
			GPIOC->GPIO_OTYPER |= Copy_u8PinOutputType <<  Copy_u8PinId ;
			break;
		default :
			break;
		}

		Local_enuErrorState = ES_OK;
	}

	return Local_enuErrorState;
}

/* Argument  : Port Id   ,  Pin Id   ,  Output speed type
 * Return    : Error State (enum)
 * Operation : To set pin output speed type
 * */

ES_t MGPIO_enuSetOutputSpeed(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8OutputSpeedType)
{
	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_u8PortId <= MGPIO_PORTC ) && (Copy_u8PinId <= MGPIO_PIN15) && (Copy_u8OutputSpeedType <= MGPIO_VERY_HIGH_SPEED) )
	{
		if((Copy_u8PortId == MGPIO_PORTC ) && ((Copy_u8PinId != MGPIO_PIN13 ) && (Copy_u8PinId != MGPIO_PIN14) && ((Copy_u8PinId != MGPIO_PIN15 ))))
		{
			return Local_enuErrorState;
		}

		switch(Copy_u8PortId)
		{
		case MGPIO_PORTA:
			GPIOA->GPIO_OSPEEDR &= ~( MGPIO_TWO_BIT_MASK << ( Copy_u8PinId * MGPIO_MODER_BITS) );
			GPIOA->GPIO_OSPEEDR |= Copy_u8OutputSpeedType << ( Copy_u8PinId * MGPIO_MODER_BITS);
			break;
		case MGPIO_PORTB:
			GPIOB->GPIO_OSPEEDR &= ~( MGPIO_TWO_BIT_MASK << ( Copy_u8PinId * MGPIO_MODER_BITS) );
			GPIOB->GPIO_OSPEEDR |= Copy_u8OutputSpeedType << ( Copy_u8PinId * MGPIO_MODER_BITS) ;
			break;
		case MGPIO_PORTC:
			GPIOC->GPIO_OSPEEDR &= ~( MGPIO_TWO_BIT_MASK << ( Copy_u8PinId * MGPIO_MODER_BITS) );
			GPIOC->GPIO_OSPEEDR |= Copy_u8OutputSpeedType << ( Copy_u8PinId * MGPIO_MODER_BITS) ;
			break;
		default :
			break;
		}

		Local_enuErrorState = ES_OK;
	}

	return Local_enuErrorState;
}

/* Argument  : Port Id   ,  Pin Id   ,  Pin Pulling Mode
 * Return    : Error State (enum)
 * Operation : To set Pin Pulling Mode
 * */

ES_t MGPIO_enuSetPinPullingMode(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinPullingType)
{
	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_u8PortId <= MGPIO_PORTC ) && (Copy_u8PinId <= MGPIO_PIN15) && (Copy_u8PinPullingType <= MGPIO_PULL_DOWN) )
	{
		if((Copy_u8PortId == MGPIO_PORTC ) && ((Copy_u8PinId != MGPIO_PIN13 ) && (Copy_u8PinId != MGPIO_PIN14) && ((Copy_u8PinId != MGPIO_PIN15 ))))
		{
			return Local_enuErrorState;
		}

		switch(Copy_u8PortId)
		{
		case MGPIO_PORTA:
			GPIOA->GPIO_PUPDR &= ~( MGPIO_TWO_BIT_MASK << ( Copy_u8PinId * MGPIO_MODER_BITS) );
			GPIOA->GPIO_PUPDR |= Copy_u8PinPullingType << ( Copy_u8PinId * MGPIO_MODER_BITS) ;
			break;
		case MGPIO_PORTB:
			GPIOB->GPIO_PUPDR &= ~( MGPIO_TWO_BIT_MASK << ( Copy_u8PinId * MGPIO_MODER_BITS) );
			GPIOB->GPIO_PUPDR |= Copy_u8PinPullingType << ( Copy_u8PinId * MGPIO_MODER_BITS) ;
			break;
		case MGPIO_PORTC:
			GPIOC->GPIO_PUPDR &= ~( MGPIO_TWO_BIT_MASK << ( Copy_u8PinId * MGPIO_MODER_BITS) );
			GPIOC->GPIO_PUPDR |= Copy_u8PinPullingType << ( Copy_u8PinId * MGPIO_MODER_BITS) ;
			break;
		default :
			break;
		}

		Local_enuErrorState = ES_OK;
	}

	return Local_enuErrorState;
}

/* Argument  : Port Id   ,  Pin Id   ,  Pin Value
 * Return    : Error State (enum)
 * Operation : To set pin value
 * */

ES_t MGPIO_enuSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue)
{
	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_u8PortId <= MGPIO_PORTC ) && (Copy_u8PinId <= MGPIO_PIN15) && (Copy_u8PinValue <= MGPIO_HIGH_OUTPUT) )
	{
		if((Copy_u8PortId == MGPIO_PORTC ) && ((Copy_u8PinId != MGPIO_PIN13 ) && (Copy_u8PinId != MGPIO_PIN14) && ((Copy_u8PinId != MGPIO_PIN15 ))))
		{
			return Local_enuErrorState;
		}

		switch(Copy_u8PortId)
		{
		case MGPIO_PORTA:
			GPIOA->GPIO_ODR &= ~( MGPIO_ONE_BIT_MASK <<  Copy_u8PinId );
			GPIOA->GPIO_ODR |= Copy_u8PinValue <<  Copy_u8PinId ;
			break;
		case MGPIO_PORTB:
			GPIOB->GPIO_ODR &= ~( MGPIO_ONE_BIT_MASK <<  Copy_u8PinId );
			GPIOB->GPIO_ODR |= Copy_u8PinValue <<  Copy_u8PinId ;
			break;
		case MGPIO_PORTC:
			GPIOC->GPIO_ODR &= ~( MGPIO_ONE_BIT_MASK <<  Copy_u8PinId );
			GPIOC->GPIO_ODR |= Copy_u8PinValue <<  Copy_u8PinId ;
			break;
		default :
			break;
		}

		Local_enuErrorState = ES_OK;
	}

	return Local_enuErrorState;
}

/* Argument  : Port Id   ,  Pin Id
 * Return    : Error State (enum)
 * Operation : To toghle pin value
 * */

ES_t MGPIO_enuTogglePinValue(u8 Copy_u8PortId, u8 Copy_u8PinId)
{
	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_u8PortId <= MGPIO_PORTC ) && (Copy_u8PinId <= MGPIO_PIN15) )
	{
		if((Copy_u8PortId == MGPIO_PORTC ) && ((Copy_u8PinId != MGPIO_PIN13 ) && (Copy_u8PinId != MGPIO_PIN14) && ((Copy_u8PinId != MGPIO_PIN15 ))))
		{
			return Local_enuErrorState;
		}

		switch(Copy_u8PortId)
		{
		case MGPIO_PORTA:
			GPIOA->GPIO_ODR ^= MGPIO_ONE_BIT_MASK <<  Copy_u8PinId ;
			break;
		case MGPIO_PORTB:
			GPIOB->GPIO_ODR ^= MGPIO_ONE_BIT_MASK <<  Copy_u8PinId ;
			break;
		case MGPIO_PORTC:
			GPIOC->GPIO_ODR ^= MGPIO_ONE_BIT_MASK <<  Copy_u8PinId ;
			break;
		default :
			break;
		}

		Local_enuErrorState = ES_OK;
	}

	return Local_enuErrorState;
}

/* Argument  : Port Id  , port Value
 * Return    : Error State (enum)
 * Operation : To set port value
 * */

ES_t MGPIO_enuSetPortValue(u8 Copy_u8PortId, u8 Copy_u8PortValue)
{
	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_u8PortId <= MGPIO_PORTC ))
	{
		switch(Copy_u8PortId)
		{
		case MGPIO_PORTA:
			GPIOA->GPIO_ODR = Copy_u8PortValue ;
			break;
		case MGPIO_PORTB:
			GPIOB->GPIO_ODR = Copy_u8PortValue ;
			break;
		case MGPIO_PORTC:
			GPIOC->GPIO_ODR = Copy_u8PortValue ;
			break;
		default :
			break;
		}

		Local_enuErrorState = ES_OK;
	}

	return Local_enuErrorState;

}

/* Argument  : Port Id   ,  Pin Id
 * Return    : Error State (enum)
 * Operation : To get pin value
 * */

ES_t   MGPIO_enuGetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId,u8* Copy_pu8PinValue)
{
	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_u8PortId <= MGPIO_PORTC ) && (Copy_u8PinId <= MGPIO_PIN15) )
	{
		if((Copy_u8PortId == MGPIO_PORTC ) && ((Copy_u8PinId != MGPIO_PIN13 ) && (Copy_u8PinId != MGPIO_PIN14) && ((Copy_u8PinId != MGPIO_PIN15 ))))
		{
			return Local_enuErrorState;
		}

		switch(Copy_u8PortId)
		{
		case MGPIO_PORTA:
			*Copy_pu8PinValue = GET_BIT(GPIOA->GPIO_IDR,Copy_u8PinId);
			break;
		case MGPIO_PORTB:
			*Copy_pu8PinValue = GET_BIT(GPIOB->GPIO_IDR,Copy_u8PinId);
			break;
		case MGPIO_PORTC:
			*Copy_pu8PinValue = GET_BIT(GPIOC->GPIO_IDR,Copy_u8PinId);
			break;
		default :
			break;
		}

		Local_enuErrorState = ES_OK;
	}

	return Local_enuErrorState;
}

/* Argument  : Port Id   ,  Pin Id
 * Return    : Error State (enum)
 * Operation : To set pin value directly
 * */

ES_t MGPIO_enuSetPinValueDirectly(u8 Copy_u8PortId, u8 Copy_u8PinId)
{
	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_u8PortId <= MGPIO_PORTC ) && (Copy_u8PinId <= MGPIO_PIN15) )
	{
		if((Copy_u8PortId == MGPIO_PORTC ) && ((Copy_u8PinId != MGPIO_PIN13 ) && (Copy_u8PinId != MGPIO_PIN14) && ((Copy_u8PinId != MGPIO_PIN15 ))))
		{
			return Local_enuErrorState;
		}

		switch(Copy_u8PortId)
		{
		case MGPIO_PORTA:
			GPIOA->GPIO_BSRR = MGPIO_ONE_BIT_MASK << ( Copy_u8PinId + MGPIO_BIT_SIXTEEN) ;
			break;
		case MGPIO_PORTB:
			GPIOB->GPIO_BSRR = MGPIO_ONE_BIT_MASK << ( Copy_u8PinId + MGPIO_BIT_SIXTEEN ) ;
			break;
		case MGPIO_PORTC:
			GPIOC->GPIO_BSRR = MGPIO_ONE_BIT_MASK << ( Copy_u8PinId + MGPIO_BIT_SIXTEEN );
			break;
		default :
			break;
		}

		Local_enuErrorState = ES_OK;
	}

	return Local_enuErrorState;
}

/* Argument  : Port Id   ,  Pin Id
 * Return    : Error State (enum)
 * Operation : To reset pin value directly
 * */

ES_t MGPIO_enuResetPinValueDirectly(u8 Copy_u8PortId, u8 Copy_u8PinId)
{
	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_u8PortId <= MGPIO_PORTC ) && (Copy_u8PinId <= MGPIO_PIN15) )
	{
		if((Copy_u8PortId == MGPIO_PORTC ) && ((Copy_u8PinId != MGPIO_PIN13 ) && (Copy_u8PinId != MGPIO_PIN14) && ((Copy_u8PinId != MGPIO_PIN15 ))))
		{
			return Local_enuErrorState;
		}

		switch(Copy_u8PortId)
		{
		case MGPIO_PORTA:
			GPIOA->GPIO_BSRR = MGPIO_ONE_BIT_MASK << Copy_u8PinId ;
			break;
		case MGPIO_PORTB:
			GPIOB->GPIO_BSRR = MGPIO_ONE_BIT_MASK << Copy_u8PinId ;
			break;
		case MGPIO_PORTC:
			GPIOC->GPIO_BSRR = MGPIO_ONE_BIT_MASK << Copy_u8PinId ;
			break;
		default :
			break;
		}

		Local_enuErrorState = ES_OK;
	}

	return Local_enuErrorState;
}

/* Argument  : Port Id   ,  Pin Id  , Alternate function number
 * Return    : Error State (enum)
 * Operation : To select alternate function pin and number
 * */

ES_t MGPIO_enuSelectAlternateFunctionPin(u8 Copy_u8PortId, u8 Copy_u8PinId,u8 Copy_u8AltFunNumber)
{
	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_u8PortId <= MGPIO_PORTC ) && (Copy_u8PinId <= MGPIO_PIN15) && (Copy_u8AltFunNumber <= MGPIO_AF15))
	{
		if((Copy_u8PortId == MGPIO_PORTC ) && ((Copy_u8PinId != MGPIO_PIN13 ) && (Copy_u8PinId != MGPIO_PIN14) && ((Copy_u8PinId != MGPIO_PIN15 ))))
		{
			return Local_enuErrorState;
		}

		switch(Copy_u8PortId)
		{
		case MGPIO_PORTA:
			if(Copy_u8PinId < MGPIO_PIN_EIGHT )
			{
				GPIOA->GPIO_AFRL &= ~( (u32)MGPIO_FOUR_BIT_MASK << ( Copy_u8PinId * MGPIO_AF_SELEION_BITS) );
				GPIOA->GPIO_AFRL |= Copy_u8AltFunNumber << ( Copy_u8PinId * MGPIO_AF_SELEION_BITS) ;
			}
			else
			{
				GPIOA->GPIO_AFRH &= ~( (u32)MGPIO_FOUR_BIT_MASK << ( (Copy_u8PinId % MGPIO_PIN_EIGHT ) * MGPIO_AF_SELEION_BITS) );
				GPIOA->GPIO_AFRH |= Copy_u8AltFunNumber << ( (Copy_u8PinId % MGPIO_PIN_EIGHT ) * MGPIO_AF_SELEION_BITS) ;
			}

			break;
		case MGPIO_PORTB:
			if(Copy_u8PinId < MGPIO_PIN_EIGHT )
			{
				GPIOB->GPIO_AFRL &= ~( (u32)MGPIO_FOUR_BIT_MASK << ( Copy_u8PinId * MGPIO_AF_SELEION_BITS) );
				GPIOB->GPIO_AFRL |= Copy_u8AltFunNumber << ( Copy_u8PinId * MGPIO_AF_SELEION_BITS) ;
			}
			else
			{
				GPIOB->GPIO_AFRH &= ~( (u32)MGPIO_FOUR_BIT_MASK << ( (Copy_u8PinId % MGPIO_PIN_EIGHT ) * MGPIO_AF_SELEION_BITS) );
				GPIOB->GPIO_AFRH |= Copy_u8AltFunNumber << ( (Copy_u8PinId % MGPIO_PIN_EIGHT ) * MGPIO_AF_SELEION_BITS) ;
			}
			break;
		case MGPIO_PORTC:
			if(Copy_u8PinId < MGPIO_PIN_EIGHT )
			{
				GPIOC->GPIO_AFRL &= ~( (u32)MGPIO_FOUR_BIT_MASK << ( Copy_u8PinId * MGPIO_AF_SELEION_BITS) );
				GPIOC->GPIO_AFRL |= Copy_u8AltFunNumber << ( Copy_u8PinId * MGPIO_AF_SELEION_BITS) ;
			}
			else
			{
				GPIOC->GPIO_AFRH &= ~( (u32)MGPIO_FOUR_BIT_MASK << ( (Copy_u8PinId % MGPIO_PIN_EIGHT ) * MGPIO_AF_SELEION_BITS) );
				GPIOC->GPIO_AFRH |= Copy_u8AltFunNumber << ( (Copy_u8PinId % MGPIO_PIN_EIGHT ) * MGPIO_AF_SELEION_BITS) ;
			}
			break;
		default :
			break;
		}

		Local_enuErrorState = ES_OK;
	}

	return Local_enuErrorState;

}

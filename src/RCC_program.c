
/******************************************************************************************************
 ******************************************************************************************************
 ******************************** AUTHOR  : Mahmoud Rabea *********************************************
 ******************************** MICRO   : STM32F401CCU6 *********************************************
 ******************************** LAYER   : MCAL          *********************************************
 ******************************** DRIVER  : RCC_Driver    *********************************************
 ******************************** File    : program File  *********************************************
 ******************************** Date    : 19/8/2023     *********************************************
 ******************************** Version : 1.0           *********************************************
 ******************************************************************************************************
 ******************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "RCC_private.h"
#include "RCC_configuration.h"
#include "RCC_interface.h"

u32 Global_u32PLLMVALUE = RCC_SYSCLK_PLL_PLLM ;
u32 Global_u32PLLNVALUE = RCC_SYSCLK_PLL_PLLN ;
u32 Global_u32PLLPVALUE = RCC_SYSCLK_PLL_PLLP ;


/* Argument   : void
 * Return     : void
 * Operations : To select the system clock source
 * */

void MRCC_voidInit(void)
{

	CLEAR_BIT(RCC->RCC_CFGR,10);
	CLEAR_BIT(RCC->RCC_CFGR,11);
	SET_BIT(RCC->RCC_CFGR,12);
#if RCC_SYSCLK_SOURCE == RCC_SYSCLK_SOURCE_HSI

    /* Select HSI to be the system clock source */
	CLEAR_BIT(RCC->RCC_CFGR,RCC_CFGR_SW0);
	CLEAR_BIT(RCC->RCC_CFGR,RCC_CFGR_SW1);

	/*Enable HSI */
	SET_BIT(RCC->RCC_CR,RCC_CR_HSI_ON);

	/*Wait till the HSI oscillator is stable*/
	while(GET_BIT(RCC->RCC_CR,RCC_CR_HSI_RDY) == 0);

#elif RCC_SYSCLK_SOURCE == RCC_SYSCLK_SOURCE_HSE

	/*Select HSE to be the system clock source */
	SET_BIT(RCC->RCC_CFGR,RCC_CFGR_SW0);
	CLEAR_BIT(RCC->RCC_CFGR,RCC_CFGR_SW1);

	/*Select the source of HSE*/
	#if RCC_SYSCLK_HSE == RCC_SYSCLK_HSE_CRYSTAL
		CLEAR_BIT(RCC->RCC_CR,RCC_CR_HSE_BYP);

	#elif RCC_SYSCLK_HSE == RCC_SYSCLK_HSE_BYPASS
		SET_BIT(RCC->RCC_CR,RCC_CR_HSE_BYP);

	#else

	#error " HSE configuration is wrong "

	#endif

	/*Enable HSE */
	SET_BIT(RCC->RCC_CR,RCC_CR_HSE_ON);

	/*Wait till the HSE oscillator is stable*/
	while(GET_BIT(RCC->RCC_CR,RCC_CR_HSE_RDY) == 0);

#elif RCC_SYSCLK_SOURCE == RCC_SYSCLK_SOURCE_PLL

	/*Select PLL to be the system clock source */
	CLEAR_BIT(RCC->RCC_CFGR,RCC_CFGR_SW0);
	SET_BIT(RCC->RCC_CFGR,RCC_CFGR_SW1);

	/*Select the source of PLL*/
	#if RCC_SYSCLK_PLL == RCC_SYSCLK_PLL_HSI
		CLEAR_BIT(RCC->RCC_PLLCFGR,RCC_PLLCFGR_PLLSRC);

	#elif RCC_SYSCLK_PLL == RCC_SYSCLK_PLL_HSE

		/*Select the source of HSE*/
		#if RCC_SYSCLK_HSE == RCC_SYSCLK_HSE_CRYSTAL
			CLEAR_BIT(RCC->RCC_CR,RCC_CR_HSE_BYP);

		#elif RCC_SYSCLK_HSE == RCC_SYSCLK_HSE_BYPASS
			SET_BIT(RCC->RCC_CR,RCC_CR_HSE_BYP);

		#else

		#error " HSE configuration is wrong "

		#endif

	#else

	#error " PLL configuration is wrong "

	#endif

	/*Set the factors of PLL clock source */
	RCC->RCC_PLLCFGR &= 0xfffC8000 ;
	RCC->RCC_PLLCFGR |= (( Global_u32PLLNVALUE << RCC_PLLCFGR_PLLN6) | (Global_u32PLLMVALUE << RCC_PLLCFGR_PLLM0) | (Global_u32PLLPVALUE << RCC_PLLCFGR_PLLP16)) ;

	/*Enable PLL */
	SET_BIT(RCC->RCC_CR,RCC_CR_PLL_ON);

	/*Wait till the PLL oscillator is stable*/
	while(GET_BIT(RCC->RCC_CR,RCC_CR_PLL_RDY) == 0);
#else
#error "Configuration of system clock source is wrong "
#endif

}

/* Argument  : Peripheral name , Bus name
 * Return    : enum( LocalError State )
 * Operation : Enable the peripheral to the system bus
 * */

ES_t MRCC_enuEnablePeripheral(u8 Copy_u8BusName,u8 Copy_u8PeripheralName)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8BusName <= RCC_APB2_BUS )
	{
		switch(Copy_u8BusName)
		{
		case RCC_AHB1_BUS :
			SET_BIT(RCC->RCC_AHB1ENR,Copy_u8PeripheralName);
			break;
		case RCC_AHB2_BUS :
			SET_BIT(RCC->RCC_AHB2ENR,Copy_u8PeripheralName);
			break;
		case RCC_APB1_BUS :
			SET_BIT(RCC->RCC_APB1ENR,Copy_u8PeripheralName);
			break;
		case RCC_APB2_BUS :
			SET_BIT(RCC->RCC_APB2ENR,Copy_u8PeripheralName);
			break;
		default:
			break;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

/* Argument  : Peripheral name , Bus name
 * Return    : enum( LocalError State )
 * Operation : Disable the peripheral from the system bus
 * */

ES_t MRCC_enuDisablePeripheral(u8 Copy_u8BusName,u8 Copy_u8PeripheralName)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8BusName <= RCC_APB2_BUS )
	{
		switch(Copy_u8BusName)
		{
		case RCC_AHB1_BUS :
			CLEAR_BIT(RCC->RCC_AHB1ENR,Copy_u8PeripheralName);
			break;
		case RCC_AHB2_BUS :
			CLEAR_BIT(RCC->RCC_AHB2ENR,Copy_u8PeripheralName);
			break;
		case RCC_APB1_BUS :
			CLEAR_BIT(RCC->RCC_APB1ENR,Copy_u8PeripheralName);
			break;
		case RCC_APB2_BUS :
			CLEAR_BIT(RCC->RCC_APB2ENR,Copy_u8PeripheralName);
			break;
		default:
			break;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}


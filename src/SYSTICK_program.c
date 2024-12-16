
/******************************************************************************************************
 ******************************************************************************************************
 ******************************** AUTHOR  : Mahmoud Rabea  ********************************************
 ******************************** MICRO   : STM32F401CCU6  ********************************************
 ******************************** LAYER   : MCAL           ********************************************
 ******************************** DRIVER  : SYSTICK_Driver ********************************************
 ******************************** File    : program File   ********************************************
 ******************************** Date    : 3/9/2023       ********************************************
 ******************************** Version : 1.0            ********************************************
 ******************************************************************************************************
 ******************************************************************************************************/

#include "BIT_MATHS.h"
#include "STD_TYPES.h"

#include "SYSTICK_private.h"
#include "SYSTICK_configuration.h"
#include "SYSTICK_interface.h"

static void (*SYSTICK_Fun_Ptr)(void)=NULL;

/* Argument   : Nothing
 * Return     : Nothing
 * Operation  : To enable the interrupt and configure SYSTICK clock source
 * */

void MSYSTICK_enuInit(void)
{
	/* Select the SYSTICK clock source */
#if   SYSTICK_CLOCK_SOURCE == SYSTICK_CLOCK_SOURCE_AHB
	SET_BIT(SYSTICK->STK_CTRL,SYSTICK_CTRL_CLKSOURCE) ;
#elif SYSTICK_CLOCK_SOURCE == SYSTICK_CLOCK_SOURCE_AHB_DIVIDED_BY_8
	CLEAR_BIT(SYSTICK->STK_CTRL,SYSTICK_CTRL_CLKSOURCE) ;
#else
#error "The configuration is wrong "
#endif

	/* Enabling the interrupt */
#if   SYSTICK_INTERRUPT == SYSTICK_INTERRUPT_ENABLE
	SET_BIT(SYSTICK->STK_CTRL,SYSTICK_CTRL_TICKINT) ;
#elif SYSTICK_INTERRUPT == SYSTICK_INTERRUPT_DISABLE
	CLEAR_BIT(SYSTICK->STK_CTRL,SYSTICK_CTRL_TICKINT) ;
#else
#error "The configuration is wrong "
#endif

}

/* Argument   : The reloaded value
 * Return     : Nothing
 * Operation  : To load the value to the reload register
 * */


void MSYSTICK_voidLoadValue(u32 Copy_32RequiredValue)
{
	/* Load the value to reload Register */
	SYSTICK->STK_LOAD = Copy_32RequiredValue ;

	/* Clear the value register */
	SYSTICK->STK_VAL = 0 ;

	/* Enable the SYSTICK */
	SET_BIT(SYSTICK->STK_CTRL,SYSTICK_CTRL_ENABLE);
}

/* Argument   : Nothing
 * Return     : The remaining counts
 * Operation  : To get the remaining counts
 * */

u32 MSYSTICK_u32GetRemainingCounts(void)
{
	return SYSTICK->STK_VAL ;
}

/* Argument   : Nothing
 * Return     : The elapsed counts
 * Operation  : To get the elapsed counts
 * */

u32 MSYSTICK_u32GetElapsedCounts(void)
{
	return ( SYSTICK->STK_LOAD - SYSTICK->STK_VAL ) ;
}

/* Argument   : Nothing
 * Return     : The flag value
 * Operation  : To check weather the flag is set or not
 * */

u8 MSYSTICK_u8ReadFlag(void)
{
	return (GET_BIT(SYSTICK->STK_CTRL,SYSTICK_CTRL_COUNTFLAG)) ;
}

/* Argument   : The value of required delay
 * Return     : Nothing
 * Operation  : To make a delay in milliseceond
 * */

void MSYSTICK_voidDelayMsec(f32 Copy_u32DelayValue) /* AHB = 16MHz */
{
	/* Disable interrupt */
	CLEAR_BIT(SYSTICK->STK_CTRL,SYSTICK_CTRL_TICKINT);

	/* Load the value*/
#if SYSTICK_CLOCK_SOURCE == SYSTICK_CLOCK_SOURCE_AHB
	MSYSTICK_voidLoadValue(SYSTICK_MSECOND_COUNTS_AHB * Copy_u32DelayValue) ;
#elif SYSTICK_CLOCK_SOURCE == SYSTICK_CLOCK_SOURCE_AHB_DIVIDED_BY_8
	MSYSTICK_voidLoadValue(SYSTICK_MSECOND_COUNTS_AHB_DIV_8 * Copy_u32DelayValue) ;
#endif

	/* Wait till the flag is set */
	while((MSYSTICK_u8ReadFlag()) == 0);
}

/* Argument   : The value of required delay
 * Return     : Nothing
 * Operation  : To make a delay in microseceond
 * */

void MSYSTICK_voidDelayUsec(u32 Copy_u32DelayValue) /* AHB = 16MHz */
{
	/* Disable interrupt */
	CLEAR_BIT(SYSTICK->STK_CTRL,SYSTICK_CTRL_TICKINT);

	/* Load the value*/
#if SYSTICK_CLOCK_SOURCE == SYSTICK_CLOCK_SOURCE_AHB
	MSYSTICK_voidLoadValue( SYSTICK_USECOND_COUNTS_AHB * Copy_u32DelayValue) ;

#elif SYSTICK_CLOCK_SOURCE == SYSTICK_CLOCK_SOURCE_AHB_DIVIDED_BY_8
	MSYSTICK_voidLoadValue(SYSTICK_USECOND_COUNTS_AHB_DIV_8 * Copy_u32DelayValue) ;
#endif

	/* Wait till the flag is set */
	while( (MSYSTICK_u8ReadFlag) == 0);
}

/* Argument   : Pointer to function
 * Return     : Error State
 * Operation  : To call a function in the main
 * */

ES_t MSYSTICK_voidCallBackFunction(void (*Copy_pvPtrToFun)(void))
{
	ES_t Local_enuErrorState = ES_OK;
	if(Copy_pvPtrToFun != NULL)
	{

		SYSTICK_Fun_Ptr = Copy_pvPtrToFun;
	}
	else
	{
		/* Do Nothing */
		Local_enuErrorState = ES_NOK;
	}

	return Local_enuErrorState;
}

/* Argument : void
 * Return   : void
 * Function : To execute the Interrupt
 * */

void Systick_IRQHandler(void)
{
	SYSTICK_Fun_Ptr();
}

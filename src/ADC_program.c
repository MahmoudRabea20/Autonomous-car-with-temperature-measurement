
/******************************************************************************************************
 ******************************************************************************************************
 ******************************** AUTHOR  : Mahmoud Rabea *********************************************
 ******************************** MICRO   : STM32F401CCU6 *********************************************
 ******************************** LAYER   : MCAL          *********************************************
 ******************************** DRIVER  : ADC_Driver    *********************************************
 ******************************** File    : program File  *********************************************
 ******************************** Date    : 27/6/2024     *********************************************
 ******************************** Version : 1.0           *********************************************
 ******************************************************************************************************
 ******************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "ADC_interface.h"
#include "ADC_private.h"


void (*ptr2)(void) = NULL;

/* Description  : To initialize the ADC
 * Argument     : None
 * Return       : None
 * */

void ADC_voidInit()
{
	/*Enable the ADC*/
	SET_BIT(ADC->ADC_CR2,ADC_CR2_ADON);

    /*Wait for ADC to be ready */
	while ((( (ADC->ADC_CR2) >> ADC_CR2_ADON ) & (1)) == 0);

	/*Select Prescaler*/
	ADC_CCR |= 0x00030000 ;

	/*Select 12-bit resolution*/
	ADC->ADC_CR1 &= ~((0b11) << 24 );

	/*Select channel 1 regular*/
	ADC->ADC_SQR1 &= ~((0b1111) << 20 );
	ADC->ADC_SQR3 &= ~((0b11111));
	ADC->ADC_SQR3 |= 1;

	/*Select Right alignment*/
	CLEAR_BIT(ADC->ADC_CR2,ADC_CR2_ALIGN);

//	/*Select the continuous conversion mode*/
	SET_BIT(ADC->ADC_CR2,ADC_CR2_CONT);

	/*Select the single conversion mode*/
	//CLEAR_BIT(ADC->ADC_CR2,ADC_CR2_CONT);

	/*Enable interrupt*/
	SET_BIT(ADC->ADC_CR1,ADC_CR1_EOCIE);

}

/* Description  : To start the conversion
 * Argument     : None
 * Return       : None
 * */

void ADC_voidStartConversion(void)
{
	/* Start conversion of regular channels */
	SET_BIT(ADC->ADC_CR2,ADC_CR2_SWSTART);
}

/* Description  : To stop the conversion
 * Argument     : None
 * Return       : None
 * */

void ADC_voidStopConversion(void)
{
	/* Start conversion of regular channels */
	CLEAR_BIT(ADC->ADC_CR2,ADC_CR2_ADON);
}

/* Description  : To get the reading
 * Argument     : None
 * Return       : The value of reading
 * */

u16 ADC_u16GetReading(void)
{
	/*Return the value of reading existed in register*/
	return ADC->ADC_DR ;
}

/* Functions for interrupt*/

void ADCCallback(void(*ptr)(void))
{
	if(ptr != NULL)
	{
		ptr2 = ptr;
	}
}
void ADC_IRQHandler(void)
{
	/*Clear the flag by software*/
	CLEAR_BIT(ADC->ADC_SR,ADC_SR_EOC);

	if(ptr2 != NULL)
	{
		ptr2();
	}
}

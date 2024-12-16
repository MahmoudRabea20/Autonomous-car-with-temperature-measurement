/*
 * state_errors.h
 *
 *      Created on  : Oct 17, 2022
 *
 *      Author      : Mhmoud Gamal Ahmed
 *
 *      Description : this file contain on types of errors that expected to occur
 */

#ifndef STATE_ERRORS_H_
#define STATE_ERRORS_H_

typedef enum
{
	ES_OK,
	ES_NOK,
	ES_OUT_OF_RANGE,
	ES_NULL_POINTER,
	ES_GPIO_LOCKED_PORTA_AND_PIN,
	ES_GPIO_LOCKED_PORTB_AND_PIN,
	ES_GPIO_LOCKED_PORTC_AND_PIN,
    ES_GPIO_LOCKED_PORTD_AND_PIN,
    ES_GPIO_LOCKED_PORTE_AND_PIN,
	ES_GPIO_LOCKED_PORTH_AND_PIN,
	ES_GPIO_LOCKED_PIN_A,
    ES_GPIO_LOCKED_PIN_B,
	ES_GPIO_LOCKED_PIN_C,
    ES_GPIO_LOCKED_PIN_D,
	ES_GPIO_LOCKED_PIN_E,
	ES_GPIO_LOCKED_PIN_H,
	ES_GPIO_LOCKED_PORT,
	ES_GPIO_LOCKED_PIN,
	ES_GPIO_PERPHEIRAL_NOT_ENABLE
}ES_t;

#endif /* STATE_ERRORS_H_ */

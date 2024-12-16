
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "RCC_interface.h"
#include "NVIC_INTERFACE.h"
#include "SYSTICK_interface.h"
#include "GPIO_interface.h"
#include "Timer5_interface.h"
#include "ADC_interface.h"
#include "LCD_interface.h"
#include "UART_interface.h"

u8 Global_u8Distance      = 0;
u8 Global_u8Counter       = 0;
u16 Global_u16FirstValue  = 0;
u16 Global_16ReadingValue = 0;

void ISR_Icu(void);
void ISR_ADC(void);
void ISR_UPEV(void);

int main(void)
{
	u16 Local_u16AnalogValue = 0 ;
	u8 Local_u8Temperature   = 0 ;

	/*Passing the address of application to ISR */
	ICUCallback(ISR_Icu);
	ADCCallback(ISR_ADC);
	UpdateEventCallback(ISR_UPEV);

	/* Enabling the buses of Port A,B,UART2 and Timer_5*/
	MRCC_voidInit();
	MRCC_enuEnablePeripheral(RCC_APB1_BUS,RCC_APB1ENR_TIM5);
	MRCC_enuEnablePeripheral(RCC_APB1_BUS,RCC_APB1ENR_TIM2);
	MRCC_enuEnablePeripheral(RCC_AHB1_BUS,RCC_AHB1ENR_GPIOA);
	MRCC_enuEnablePeripheral(RCC_AHB1_BUS,RCC_AHB1ENR_GPIOB);
	MRCC_enuEnablePeripheral(RCC_APB2_BUS,RCC_APB2ENR_ADC1);
	MRCC_enuEnablePeripheral(RCC_APB1_BUS,RCC_APB1ENR_USART2);

	/* Initialization */
	NVIC_voidinit();
	MSYSTICK_enuInit();
	Timer5_voidInit();
	Timer2_voidInit();


	MUART_voidInit();

	/* Enabling the interrupt of Timer_5 and ADC*/
	NVIC_enumenable_interrupt(Tim5Global);
	NVIC_enumenable_interrupt(ADC);
	NVIC_enumenable_interrupt(Tim2Global);

	/*Configurung pins of UART2*/

	MGPIO_enuSetPinDirectionMode(MGPIO_PORTA,MGPIO_PIN2,MGPIO_AF);
	MGPIO_enuSetPinDirectionMode(MGPIO_PORTA,MGPIO_PIN3,MGPIO_AF);
	MGPIO_enuSelectAlternateFunctionPin(MGPIO_PORTA,MGPIO_PIN2,MGPIO_AF7);
	MGPIO_enuSelectAlternateFunctionPin(MGPIO_PORTA,MGPIO_PIN3,MGPIO_AF7);

	/*Configuring a pin to be analog for ADC*/
	MGPIO_enuSetPinDirectionMode(MGPIO_PORTA,MGPIO_PIN1,MGPIO_ANALOG);

	/*Configuring the pin of ECHO*/
	MGPIO_enuSetPinDirectionMode(MGPIO_PORTA,MGPIO_PIN0,MGPIO_AF);
	MGPIO_enuSelectAlternateFunctionPin(MGPIO_PORTA,MGPIO_PIN0,MGPIO_AF2);
	MGPIO_enuSetPinPullingMode(MGPIO_PORTA,MGPIO_PIN0,MGPIO_PULL_DOWN);

	/*Configuring the pin of Trigger*/
	MGPIO_enuSetPinDirectionMode(MGPIO_PORTB,MGPIO_PIN0,MGPIO_OUTPUT);
	MGPIO_enuSetOutputSpeed(MGPIO_PORTB,MGPIO_PIN0,MGPIO_LOW_SPEED);
	MGPIO_enuSetOutputType(MGPIO_PORTB,MGPIO_PIN0,MGPIO_PUSH_PULL);

	/* Configuring the pins of the Motor_1 output*/
	MGPIO_enuSetPinDirectionMode(MGPIO_PORTB,MGPIO_PIN6,MGPIO_OUTPUT);
	MGPIO_enuSetOutputSpeed(MGPIO_PORTB,MGPIO_PIN6,MGPIO_LOW_SPEED);
	MGPIO_enuSetOutputType(MGPIO_PORTB,MGPIO_PIN6,MGPIO_PUSH_PULL);

	MGPIO_enuSetPinDirectionMode(MGPIO_PORTB,MGPIO_PIN7,MGPIO_OUTPUT);
	MGPIO_enuSetOutputSpeed(MGPIO_PORTB,MGPIO_PIN7,MGPIO_LOW_SPEED);
	MGPIO_enuSetOutputType(MGPIO_PORTB,MGPIO_PIN7,MGPIO_PUSH_PULL);

	/* Configuring the pins of the Motor_2 output*/
	MGPIO_enuSetPinDirectionMode(MGPIO_PORTB,MGPIO_PIN2,MGPIO_OUTPUT);
	MGPIO_enuSetOutputSpeed(MGPIO_PORTB,MGPIO_PIN2,MGPIO_LOW_SPEED);
	MGPIO_enuSetOutputType(MGPIO_PORTB,MGPIO_PIN2,MGPIO_PUSH_PULL);

	MGPIO_enuSetPinDirectionMode(MGPIO_PORTB,MGPIO_PIN3,MGPIO_OUTPUT);
	MGPIO_enuSetOutputSpeed(MGPIO_PORTB,MGPIO_PIN3,MGPIO_LOW_SPEED);
	MGPIO_enuSetOutputType(MGPIO_PORTB,MGPIO_PIN3,MGPIO_PUSH_PULL);

	/* Configuring the pins of the Leds and buzzer */
	MGPIO_enuSetPinDirectionMode(MGPIO_PORTB,MGPIO_PIN1,MGPIO_OUTPUT);
	MGPIO_enuSetOutputSpeed(MGPIO_PORTB,MGPIO_PIN1,MGPIO_LOW_SPEED);
	MGPIO_enuSetOutputType(MGPIO_PORTB,MGPIO_PIN1,MGPIO_PUSH_PULL);

	MGPIO_enuSetPinDirectionMode(MGPIO_PORTB,MGPIO_PIN4,MGPIO_OUTPUT);
	MGPIO_enuSetOutputSpeed(MGPIO_PORTB,MGPIO_PIN4,MGPIO_LOW_SPEED);
	MGPIO_enuSetOutputType(MGPIO_PORTB,MGPIO_PIN4,MGPIO_PUSH_PULL);

	MGPIO_enuSetPinDirectionMode(MGPIO_PORTB,MGPIO_PIN5,MGPIO_OUTPUT);
	MGPIO_enuSetOutputSpeed(MGPIO_PORTB,MGPIO_PIN5,MGPIO_LOW_SPEED);
	MGPIO_enuSetOutputType(MGPIO_PORTB,MGPIO_PIN5,MGPIO_PUSH_PULL);

	MSYSTICK_voidDelayMsec(1000);
	MSYSTICK_voidDelayMsec(1000);
	MSYSTICK_voidDelayMsec(1000);

	/*Motor*/
	MGPIO_enuSetPinValue(MGPIO_PORTB,MGPIO_PIN6,MGPIO_LOW_OUTPUT);
	MGPIO_enuSetPinValue(MGPIO_PORTB,MGPIO_PIN7,MGPIO_LOW_OUTPUT);
	MGPIO_enuSetPinValue(MGPIO_PORTB,MGPIO_PIN2,MGPIO_LOW_OUTPUT);
	MGPIO_enuSetPinValue(MGPIO_PORTB,MGPIO_PIN3,MGPIO_LOW_OUTPUT);

	/*Turning off the leds and the buzzer*/
	MGPIO_enuSetPinValue(MGPIO_PORTB,MGPIO_PIN1,0);
	MGPIO_enuSetPinValue(MGPIO_PORTB,MGPIO_PIN4,0);
	MGPIO_enuSetPinValue(MGPIO_PORTB,MGPIO_PIN5,0);

	HLCD_enuInit();
	ADC_voidInit();
	ADC_voidStartConversion();

	/*Super Loop*/


	Timer2_voidEnableCounter();

	while(1)
	{
		MUART_voidSendCharacter('A');

		/*Enabling the counter*/
		Timer5_voidEnableCounter();

		/*Send a pulse to Trigger*/
		MGPIO_enuSetPinValue(MGPIO_PORTB,MGPIO_PIN0,1);
		MSYSTICK_voidDelayMsec(0.25);
		MGPIO_enuSetPinValue(MGPIO_PORTB,MGPIO_PIN0,0);

		/*Delay*/
		MSYSTICK_voidDelayMsec(10);

		/*Determining the value of the temperature*/
		Local_u16AnalogValue = ( Global_16ReadingValue * 3300UL ) / 4095 ;
		Local_u8Temperature  = Local_u16AnalogValue / 10 ;

		/*Display the distance in cm and temperature in celicius*/
		HLCD_enuWriteString("Distance = ");
		HLCD_enuWriteIntegerNumber(Global_u8Distance);
		HLCD_enuWriteString(" cm");

		HLCD_enuGoToXYPosition(0,1);

		HLCD_enuWriteString("Temp = ");
		HLCD_enuWriteIntegerNumber(Local_u8Temperature);
		HLCD_enuWriteString(" C");



		/*Disable the timer to clear the counter*/
		Timer5_voidDisableCounter();

		if(Global_u8Distance > 30)
		{
			MGPIO_enuSetPinValue(MGPIO_PORTB,MGPIO_PIN6,MGPIO_HIGH_OUTPUT);
			MGPIO_enuSetPinValue(MGPIO_PORTB,MGPIO_PIN7,MGPIO_LOW_OUTPUT);
			MGPIO_enuSetPinValue(MGPIO_PORTB,MGPIO_PIN2,MGPIO_HIGH_OUTPUT);
			MGPIO_enuSetPinValue(MGPIO_PORTB,MGPIO_PIN3,MGPIO_LOW_OUTPUT);

			MGPIO_enuSetPinValue(MGPIO_PORTB,MGPIO_PIN5,MGPIO_LOW_OUTPUT);
			MGPIO_enuSetPinValue(MGPIO_PORTB,MGPIO_PIN4,MGPIO_HIGH_OUTPUT);
		}
		else if(Global_u8Distance < 30)
		{
			MGPIO_enuSetPinValue(MGPIO_PORTB,MGPIO_PIN5,MGPIO_HIGH_OUTPUT);
			MGPIO_enuSetPinValue(MGPIO_PORTB,MGPIO_PIN4,MGPIO_LOW_OUTPUT);

			MGPIO_enuSetPinValue(MGPIO_PORTB,MGPIO_PIN6,MGPIO_LOW_OUTPUT);
			MGPIO_enuSetPinValue(MGPIO_PORTB,MGPIO_PIN7,MGPIO_LOW_OUTPUT);
			MGPIO_enuSetPinValue(MGPIO_PORTB,MGPIO_PIN2,MGPIO_LOW_OUTPUT);
			MGPIO_enuSetPinValue(MGPIO_PORTB,MGPIO_PIN3,MGPIO_LOW_OUTPUT);



			MGPIO_enuSetPinValue(MGPIO_PORTB,MGPIO_PIN6,MGPIO_HIGH_OUTPUT);
			MGPIO_enuSetPinValue(MGPIO_PORTB,MGPIO_PIN7,MGPIO_LOW_OUTPUT);
			MGPIO_enuSetPinValue(MGPIO_PORTB,MGPIO_PIN2,MGPIO_LOW_OUTPUT);
			MGPIO_enuSetPinValue(MGPIO_PORTB,MGPIO_PIN3,MGPIO_HIGH_OUTPUT);

		}
		HLCD_voidClear();
	}

}


void ISR_Icu(void)
{
	u16 Global_u16SecondValue;

	if(Global_u8Counter == 0)
	{
		Global_u8Counter = 1;
		Global_u16FirstValue = Timer5_u32CaptureValue();

	}
	else
	{
		Global_u8Counter = 0;
		Global_u16SecondValue = Timer5_u32CaptureValue();
		if(Global_u16SecondValue > Global_u16FirstValue)
		{
			Global_u8Distance = (u8)((Global_u16SecondValue - Global_u16FirstValue) * 0.0343 / 2);
		}
		else
		{
			Global_u8Distance = (u8)((65500 + Global_u16SecondValue - Global_u16FirstValue) * 0.0343 / 2);
		}


	}
}

void ISR_ADC()
{
	Global_16ReadingValue = ADC_u16GetReading();
}

void ISR_UPEV()
{
	MGPIO_enuTogglePinValue(MGPIO_PORTB,MGPIO_PIN1);
}

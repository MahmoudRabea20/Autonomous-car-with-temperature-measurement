
/******************************************************************************************************
 ******************************************************************************************************
 ******************************** AUTHOR  : Mahmoud Rabea  ********************************************
 ******************************** MICRO   : STM32F401CCU6  ********************************************
 ******************************** LAYER   : HAL            ********************************************
 ******************************** DRIVER  : LCD_Driver     ********************************************
 ******************************** File    : program File   ********************************************
 ******************************** Date    : 6/9/2023       ********************************************
 ******************************** Version : 1.0            ********************************************
 ******************************************************************************************************
 ******************************************************************************************************/

#include "BIT_MATHS.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"

#include "SYSTICK_interface.h"
#include "LCD_private.h"
#include "LCD_configuration.h"
#include "LCD_interface.h"

/* Argument  : Data that will be sent to pins
 * Return    : Nothing
 * Operation : To send data to pins
 * */

static void HLCD_voidSendHalfDataPort(u8 Copy_u8Data)
{
	u8 Local_Au8DataPins[4]={LCD_DATA_PIN4,LCD_DATA_PIN5,LCD_DATA_PIN6,LCD_DATA_PIN7};
	u8 Local_u8Iterator ;

	for(Local_u8Iterator = 0 ; Local_u8Iterator < 4 ;Local_u8Iterator++ )
	{
		MGPIO_enuSetPinValue(LCD_DATA_GRP,Local_Au8DataPins[Local_u8Iterator],(Copy_u8Data >> Local_u8Iterator) & 1);
	}

}

/* Argument  : Nothing
 * Return    : Nothing
 * Operation : To enable pulse
 * */

static void HLCD_voidSendEnablePulse()
{
	MGPIO_enuSetPinValue(LCD_EN_GRP,LCD_EN_PIN,MGPIO_HIGH_OUTPUT);

	/* Wait */
	MSYSTICK_enuInit();
	MSYSTICK_voidDelayMsec(1);

	MGPIO_enuSetPinValue(LCD_EN_GRP,LCD_EN_PIN,MGPIO_LOW_OUTPUT);

}

/* Argument  : Nothing
 * Return    : Error State (enum)
 * Operation : To configure the input and output pins
 * */

ES_t HLCD_enuSetAllDirection()
{
	ES_t Local_enuErrorState = ES_OK;

	/* Control Direction */
	MGPIO_enuSetPinDirectionMode(LCD_RS_GRP,LCD_RS_PIN,MGPIO_OUTPUT);
	MGPIO_enuSetOutputSpeed(LCD_RS_GRP,LCD_RS_PIN,MGPIO_LOW_SPEED);
	MGPIO_enuSetOutputType(LCD_RS_GRP,LCD_RS_PIN,MGPIO_PUSH_PULL);

	MGPIO_enuSetPinDirectionMode(LCD_RW_GRP,LCD_RW_PIN,MGPIO_OUTPUT);
	MGPIO_enuSetOutputSpeed(LCD_RW_GRP,LCD_RW_PIN,MGPIO_LOW_SPEED);
	MGPIO_enuSetOutputType(LCD_RW_GRP,LCD_RW_PIN,MGPIO_PUSH_PULL);

	MGPIO_enuSetPinDirectionMode(LCD_EN_GRP,LCD_EN_PIN,MGPIO_OUTPUT);
	MGPIO_enuSetOutputSpeed(LCD_EN_GRP,LCD_EN_PIN,MGPIO_LOW_SPEED);
	MGPIO_enuSetOutputType(LCD_EN_GRP,LCD_EN_PIN,MGPIO_PUSH_PULL);

	/* Data Direction */
#if LCD_MODE == LCD_EIGHT_BIT
	MGPIO_enuSetPortDirectionMode(LCD_DATA_GRP,MGPIO_OUTPUT);


#elif LCD_MODE == LCD_FOUR_BIT

	MGPIO_enuSetPinDirectionMode(LCD_DATA_GRP,LCD_DATA_PIN4,MGPIO_OUTPUT);
	MGPIO_enuSetOutputSpeed(LCD_DATA_GRP,LCD_DATA_PIN4,MGPIO_LOW_SPEED);
	MGPIO_enuSetOutputType(LCD_DATA_GRP,LCD_DATA_PIN4,MGPIO_PUSH_PULL);

	MGPIO_enuSetPinDirectionMode(LCD_DATA_GRP,LCD_DATA_PIN5,MGPIO_OUTPUT);
	MGPIO_enuSetOutputSpeed(LCD_DATA_GRP,LCD_DATA_PIN5,MGPIO_LOW_SPEED);
	MGPIO_enuSetOutputType(LCD_DATA_GRP,LCD_DATA_PIN5,MGPIO_PUSH_PULL);

	MGPIO_enuSetPinDirectionMode(LCD_DATA_GRP,LCD_DATA_PIN6,MGPIO_OUTPUT);
	MGPIO_enuSetOutputSpeed(LCD_DATA_GRP,LCD_DATA_PIN6,MGPIO_LOW_SPEED);
	MGPIO_enuSetOutputType(LCD_DATA_GRP,LCD_DATA_PIN6,MGPIO_PUSH_PULL);

	MGPIO_enuSetPinDirectionMode(LCD_DATA_GRP,LCD_DATA_PIN7,MGPIO_OUTPUT);
	MGPIO_enuSetOutputSpeed(LCD_DATA_GRP,LCD_DATA_PIN7,MGPIO_LOW_SPEED);
	MGPIO_enuSetOutputType(LCD_DATA_GRP,LCD_DATA_PIN7,MGPIO_PUSH_PULL);

#endif

	return Local_enuErrorState;
}

/* Argument  : Nothing
 * Return    : Error State(enum)
 * Operation : To initialize the LCD
 * */

ES_t HLCD_enuInit(void)
{
	ES_t Local_enuErrorState = ES_OK;

	MSYSTICK_enuInit();
	MSYSTICK_voidDelayMsec(40);
	HLCD_enuSetAllDirection();

	/* Wait after VDD rises to 4.5V  */
	MSYSTICK_voidDelayMsec(40);

#if LCD_MODE == LCD_EIGHT_BIT

	/* Function Set */
	HLCD_enuWriteCommand(0b00111000);

#elif LCD_MODE == LCD_FOUR_BIT

	/* Function Set */
	HLCD_voidSendHalfDataPort(0b0010);
	HLCD_voidSendEnablePulse();
	HLCD_voidSendHalfDataPort(0b0010);
	HLCD_voidSendEnablePulse();
	HLCD_voidSendHalfDataPort(0b1100);
	HLCD_voidSendEnablePulse();

#else
	Error : " The configuration is wrong "
#endif

	/* Display Control */
	HLCD_enuWriteCommand(0b00001111);

	/* Display Clear */
	HLCD_voidClear();

	return Local_enuErrorState;
}

/* Argument  : Nothing
 * Return    : Error State (enum)
 * Operation : To write command
 * */

ES_t HLCD_enuWriteCommand(u8 Copy_u8Command)
{
	ES_t Local_enuErrorState = ES_OK;

	/* Set RS to zero for writing command */
	MGPIO_enuSetPinValue(LCD_RS_GRP,LCD_RS_PIN,MGPIO_LOW_OUTPUT);

	/* Set RW to zero for writing */
	MGPIO_enuSetPinValue(LCD_RW_GRP,LCD_RW_PIN,MGPIO_LOW_OUTPUT);

#if LCD_MODE == LCD_EIGHT_BIT

	/* Write command to data pins */
	MGPIO_enuSetPortValue(LCD_DATA_GRP,Copy_u8Command);

	/*Set enable pulse */
	SendEnablePulse();

#elif LCD_MODE == LCD_FOUR_BIT

	/* Write higher command to data pins */
	HLCD_voidSendHalfDataPort(Copy_u8Command >> 4);

	/*Set enable pulse */
	HLCD_voidSendEnablePulse();

	/* Write lower command to data pins */
	HLCD_voidSendHalfDataPort(Copy_u8Command);

	/*Set enable pulse */
	HLCD_voidSendEnablePulse();

#endif



	return Local_enuErrorState;


}

/* Argument  : Nothing
 * Return    : Nothing
 * Operation : To clear the LCD
 * */

void HLCD_voidClear()
{
	MSYSTICK_enuInit();
	/* clear */
	HLCD_enuWriteCommand(0b00000001);

	/* Wait */
	MSYSTICK_voidDelayMsec(2);

}

/* Argument  : Data
 * Return    : Error state
 * Operation : To write data to LCD
 * */

ES_t HLCD_enuWriteData(u8 Copy_u8Data)
{
	ES_t Local_enuErrorState = ES_OK;

	/* Set RS to one for writing data */
	MGPIO_enuSetPinValue(LCD_RS_GRP,LCD_RS_PIN,MGPIO_HIGH_OUTPUT);

	/* Set RW to zero for writing */
	MGPIO_enuSetPinValue(LCD_RW_GRP,LCD_RW_PIN,MGPIO_LOW_OUTPUT);

#if LCD_MODE == LCD_EIGHT_BIT

	/* Write data to data pins */
	MGPIO_enuSetPortValue(LCD_DATA_GRP,Copy_u8Data);

	/*Set enable pulse */
	HLCD_voidSendEnablePulse();

#elif LCD_MODE == LCD_FOUR_BIT

	/* Write higher data to data pins */
	HLCD_voidSendHalfDataPort(Copy_u8Data >> 4);

	/*Set enable pulse */
	HLCD_voidSendEnablePulse();

	/* Write lower data to data pins */
	HLCD_voidSendHalfDataPort(Copy_u8Data);

	/*Set enable pulse */
	HLCD_voidSendEnablePulse();

#endif

	return Local_enuErrorState;

}

/* Argument  : String that will be written to LCD
 * Return    : Error state
 * Operation : To write sting to LCD
 * */

ES_t HLCD_enuWriteString(const char* Copy_pchString)
{
	ES_t Local_enuErrorState = ES_NOK;
	u8 Local_u8Counter = 0;

	if(Copy_pchString != NULL )
	{
		while(Copy_pchString[Local_u8Counter] != '\0')
		{
			HLCD_enuWriteData(Copy_pchString[Local_u8Counter]);
			Local_u8Counter++;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = NULL_POINTER;
	}

	return Local_enuErrorState;
}

/* Argument  : Integer Number that will be written to LCD
 * Return    : Error state
 * Operation : To write Integer number to LCD
 * */

ES_t HLCD_enuWriteIntegerNumber(s32 Copy_s32IntegerNumber)
{
	ES_t Local_enuErrorState = ES_OK;
	u32 Local_u32OppositedNumber = 0;
	u8 Local_u8CurrentDigit = 0;

	if(Copy_s32IntegerNumber < 0)
	{
		HLCD_enuWriteData('-');
		Copy_s32IntegerNumber *= -1;
	}

	while(Copy_s32IntegerNumber != 0)
	{
		Local_u32OppositedNumber = Local_u32OppositedNumber * 10 +  Copy_s32IntegerNumber % 10 ;
		Copy_s32IntegerNumber /= 10;
	}

	do
	{
		Local_u8CurrentDigit = Local_u32OppositedNumber % 10;
		HLCD_enuWriteData(Local_u8CurrentDigit + 48);
		Local_u32OppositedNumber /= 10;
	}while(Local_u32OppositedNumber != 0);


	return Local_enuErrorState;
}

/* Argument  : Float Number that will be written to LCD
 * Return    : Error state
 * Operation : To write float number to LCD
 * */

ES_t HLCD_enuWriteFloatNumber(f64 Copy_f64FloatNumber)
{
	ES_t Local_enuErrorState = ES_OK;
	u64 Local_u64IntegerNumber = 0;
	u8 Local_u8Decimal = 0;

	if(Copy_f64FloatNumber < 0)
	{
		HLCD_enuWriteData('-');
		Copy_f64FloatNumber *= -1;
	}

	Local_u64IntegerNumber = Copy_f64FloatNumber;
	Local_u8Decimal = (Copy_f64FloatNumber - (f64)Local_u64IntegerNumber) * 100;

	HLCD_enuWriteIntegerNumber(Local_u64IntegerNumber);
	HLCD_enuWriteData('.');
	HLCD_enuWriteIntegerNumber(Local_u8Decimal);

	return Local_enuErrorState;
}

/* Argument  : Nothing
 * Return    : Nothing
 * Operation : To return to home position
 * */

void HLCD_voidReturnHome()
{
	HLCD_enuWriteCommand(0b00000010);
}

/* Argument  : Position X and position Y
 * Return    : Error state
 * Operation : To move the cursor to (x,y) position
 * */

ES_t HLCD_enuGoToXYPosition(u8 Copy_u8XPosition,u8 Copy_u8YPosition)
{
	ES_t Local_enuErrorState = ES_NOK;
	u8 Local_u8DDRAMAddress;

	if( Copy_u8YPosition == 0 || Copy_u8YPosition == 1)
	{

		Local_u8DDRAMAddress = Copy_u8XPosition + Copy_u8YPosition * 0x40 ;
		Local_u8DDRAMAddress = Local_u8DDRAMAddress | (LCD_BIT_MASK << 7 );
		HLCD_enuWriteCommand(Local_u8DDRAMAddress);


		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

/* Argument  : Position X and position Y , array that equal to the special character and block number
 * Return    : Error state
 * Operation : To write special character not exist in the Rom
 * */

ES_t HLCD_enuWriteSpecialCharacter(u8 Copy_Au8LetterArray[] ,u8 Copy_u8BlockNumber,u8 Copy_u8XPosition ,u8 Copy_u8YPosition)
{
	ES_t Local_enuErrorState = ES_NOK;
	u8 Local_u8CGRAMAddress;
	u8 Local_u8Iterator;

	/* Calculate the starting address in CGRAM */
	Local_u8CGRAMAddress = Copy_u8BlockNumber * LCD_u8BLOCKBYTES ;
	Local_u8CGRAMAddress = Local_u8CGRAMAddress | (LCD_BIT_MASK << 6 );
	//Local_u8CGRAMAddress = Local_u8CGRAMAddress & (~(LCD_BIT_MASK << 7 ));

	/* Set CGRAM address command */
	HLCD_enuWriteCommand(Local_u8CGRAMAddress);

	/* Draw the pattern inside CGRAM */
	for(Local_u8Iterator = 0 ; Local_u8Iterator < 8 ; Local_u8Iterator ++)
	{
		HLCD_enuWriteData(Copy_Au8LetterArray[Local_u8Iterator] );
	}

	/* Go back to DDRAM to display the pattern */
	HLCD_enuGoToXYPosition(Copy_u8XPosition,Copy_u8YPosition);

	/* Display the drawn pattern */
	HLCD_enuWriteData(Copy_u8BlockNumber);

	return Local_enuErrorState;
}

/* Argument  : number of shifts that the cursor moves to it to delete the character
 * Return    : Nothing
 * Operation : To delete one character
 * */

void HLCD_voidDeleteCharacter(u8 Copy_u8ShiftedNumber)
{
	for(u8 Local_u8Iterator = 0 ; Local_u8Iterator < Copy_u8ShiftedNumber ; Local_u8Iterator ++)
	{
		HLCD_enuWriteCommand(0x10);
	}
	HLCD_enuWriteData(' ');
	HLCD_enuWriteCommand(0x10);

}

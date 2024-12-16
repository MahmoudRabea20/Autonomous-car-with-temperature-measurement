
/******************************************************************************************************
 ******************************************************************************************************
 ******************************** AUTHOR  : Mahmoud Rabea  ********************************************
 ******************************** MICRO   : STM32F401CCU6  ********************************************
 ******************************** LAYER   : HAL            ********************************************
 ******************************** DRIVER  : LCD_Driver     ********************************************
 ******************************** File    : interface File ********************************************
 ******************************** Date    : 6/9/2023       ********************************************
 ******************************** Version : 1.0            ********************************************
 ******************************************************************************************************
 ******************************************************************************************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


ES_t HLCD_enuInit(void);

ES_t HLCD_enuWriteCommand(u8 Copy_u8Command);

ES_t HLCD_enuWriteData(u8 Copy_u8Data);

void HLCD_voidClear();

ES_t HLCD_enuWriteString(const char* Copy_pchString);

ES_t HLCD_enuWriteIntegerNumber(s32 Copy_s32IntegerNumber);

ES_t HLCD_enuWriteFloatNumber(f64 Copy_f64FloatNumber);

void HLCD_voidReturnHome();

ES_t HLCD_enuGoToXYPosition(u8 Copy_u8XPosition,u8 Copy_u8YPosition);

ES_t HLCD_enuWriteSpecialCharacter(u8 Copy_Au8LetterArray[] ,u8 Copy_u8BlockNumber,u8 Copy_u8XPosition ,u8 Copy_u8YPosition);

void HLCD_voidDeleteCharacter(u8 Copy_u8ShiftedNumber);

#endif /* LCD_INTERFACE_H_ */

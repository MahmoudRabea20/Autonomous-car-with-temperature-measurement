
/******************************************************************************************************
 ******************************************************************************************************
 ******************************** AUTHOR  : Mahmoud Rabea  ********************************************
 ******************************** MICRO   : STM32F401CCU6  ********************************************
 ******************************** LAYER   : HAL            ********************************************
 ******************************** DRIVER  : LCD_Driver     ********************************************
 ******************************** File    : config File    ********************************************
 ******************************** Date    : 6/9/2023       ********************************************
 ******************************** Version : 1.0            ********************************************
 ******************************************************************************************************
 ******************************************************************************************************/

#ifndef LCD_CONFIGURATION_H_
#define LCD_CONFIGURATION_H_

/* LCD_MODE : 1- LCD_EIGHT_BIT
 *            2- LCD_FOUR_BIT
 * */

#define LCD_MODE      LCD_FOUR_BIT

          /* Control Pins */
#define LCD_RS_GRP        MGPIO_PORTA
#define LCD_RW_GRP        MGPIO_PORTA
#define LCD_EN_GRP        MGPIO_PORTA

#define LCD_RS_PIN        MGPIO_PIN8
#define LCD_RW_PIN        MGPIO_PIN9
#define LCD_EN_PIN        MGPIO_PIN10

          /* Data Pins */
#define LCD_DATA_GRP      MGPIO_PORTA
#define LCD_DATA_PIN0     MGPIO_PIN0
#define LCD_DATA_PIN1     MGPIO_PIN1
#define LCD_DATA_PIN2     MGPIO_PIN2
#define LCD_DATA_PIN3     MGPIO_PIN3
#define LCD_DATA_PIN4     MGPIO_PIN4
#define LCD_DATA_PIN5     MGPIO_PIN5
#define LCD_DATA_PIN6     MGPIO_PIN6
#define LCD_DATA_PIN7     MGPIO_PIN7


#endif /* LCD_CONFIGURATION_H_ */

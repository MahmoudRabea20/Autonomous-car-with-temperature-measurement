
/******************************************************************************************************
 ******************************************************************************************************
 ******************************** AUTHOR  : Mahmoud Rabea *********************************************
 ******************************** MICRO   : STM32F401CCU6 *********************************************
 ******************************** LAYER   : MCAL          *********************************************
 ******************************** DRIVER  : GPIO_Driver   *********************************************
 ******************************** File    : interface File*********************************************
 ******************************** Date    : 20/8/2023     *********************************************
 ******************************** Version : 1.0           *********************************************
 ******************************************************************************************************
 ******************************************************************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/* Copy_u8GroupId          : MGPIO_PORTA                   MGPIO_PORTB                 MGPIO_PORTC
 * Copy_u8PinId            : MGPIO_PIN0 --> MGPIO_PIN15    MGPIO_PIN0 --> MGPIO_PIN15  MGPIO_PIN13 --> MGPIO_PIN15
 * Copy_u8PinDirectionMode : MGPIO_INPUT	MGPIO_OUTPUT   MGPIO_AF      MGPIO_ANALOG
 * */


ES_t MGPIO_enuSetPinDirectionMode(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinDirectionMode);

/* Copy_u8GroupId          : MGPIO_PORTA                   MGPIO_PORTB                 MGPIO_PORTC
 * Copy_u8PinDirectionMode : MGPIO_INPUT	MGPIO_OUTPUT   MGPIO_AF      MGPIO_ANALOG
 * */

ES_t MGPIO_enuSetPortDirectionMode(u8 Copy_u8PortId, u8 Copy_u8PinDirectionMode);

/* Copy_u8GroupId        : MGPIO_PORTA                   MGPIO_PORTB                 MGPIO_PORTC
 * Copy_u8PinId          : MGPIO_PIN0 --> MGPIO_PIN15    MGPIO_PIN0 --> MGPIO_PIN15  MGPIO_PIN13 --> MGPIO_PIN15
 * Copy_u8PinOutputType  : MGPIO_PUSH_PULL               MGPIO_OPEN_DRAIN
 * */

ES_t MGPIO_enuSetOutputType(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinOutputType);

/* Copy_u8GroupId          : MGPIO_PORTA                   MGPIO_PORTB                 MGPIO_PORTC
 * Copy_u8PinId            : MGPIO_PIN0 --> MGPIO_PIN15    MGPIO_PIN0 --> MGPIO_PIN15  MGPIO_PIN13 --> MGPIO_PIN15
 * Copy_u8OutputSpeedType  : MGPIO_LOW_SPEED   MGPIO_MEDIUM_SPEED   MGPIO_HIGH_SPEED   MGPIO_VERY_HIGH_SPEED
 * */

ES_t MGPIO_enuSetOutputSpeed(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8OutputSpeedType);

/* Copy_u8GroupId         : MGPIO_PORTA                   MGPIO_PORTB                 MGPIO_PORTC
 * Copy_u8PinId           : MGPIO_PIN0 --> MGPIO_PIN15    MGPIO_PIN0 --> MGPIO_PIN15  MGPIO_PIN13 --> MGPIO_PIN15
 * Copy_u8PinPullingType  : MGPIO_PUlL_DOWN               MGPIO_PULL_UP
 * */

ES_t MGPIO_enuSetPinPullingMode(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinPullingType);

/* Copy_u8GroupId   : MGPIO_PORTA                   MGPIO_PORTB                 MGPIO_PORTC
 * Copy_u8PinId     : MGPIO_PIN0 --> MGPIO_PIN15    MGPIO_PIN0 --> MGPIO_PIN15  MGPIO_PIN13 --> MGPIO_PIN15
 * Copy_u8PinValue  : MGPIO_HIGH_OUTPUT             MGPIO_LOW_OUTPUT
 * */

ES_t MGPIO_enuSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue);

/* Copy_u8GroupId   : MGPIO_PORTA                   MGPIO_PORTB                 MGPIO_PORTC
 * Copy_u8PinId     : MGPIO_PIN0 --> MGPIO_PIN15    MGPIO_PIN0 --> MGPIO_PIN15  MGPIO_PIN13 --> MGPIO_PIN15
 * */

ES_t MGPIO_enuTogglePinValue(u8 Copy_u8PortId, u8 Copy_u8PinId);

/* Copy_u8GroupId   : MGPIO_PORTA                   MGPIO_PORTB                 MGPIO_PORTC
 * */

ES_t MGPIO_enuSetPortValue(u8 Copy_u8PortId, u8 Copy_u8PortValue);


/* Copy_u8GroupId   : MGPIO_PORTA                   MGPIO_PORTB                 MGPIO_PORTC
 * Copy_u8PinId     : MGPIO_PIN0 --> MGPIO_PIN15    MGPIO_PIN0 --> MGPIO_PIN15  MGPIO_PIN13 --> MGPIO_PIN15
 * */

ES_t   MGPIO_enuGetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId,u8* Copy_pu8PinValue);

/* Copy_u8GroupId   : MGPIO_PORTA                   MGPIO_PORTB                 MGPIO_PORTC
 * Copy_u8PinId     : MGPIO_PIN0 --> MGPIO_PIN15    MGPIO_PIN0 --> MGPIO_PIN15  MGPIO_PIN13 --> MGPIO_PIN15
 * Copy_u8PinValue  : MGPIO_HIGH_OUTPUT             MGPIO_LOW_OUTPUT
 * */

ES_t MGPIO_enuSetPinValueDirectly(u8 Copy_u8PortId, u8 Copy_u8PinId);

/* Copy_u8GroupId   : MGPIO_PORTA                   MGPIO_PORTB                 MGPIO_PORTC
 * Copy_u8PinId     : MGPIO_PIN0 --> MGPIO_PIN15    MGPIO_PIN0 --> MGPIO_PIN15  MGPIO_PIN13 --> MGPIO_PIN15
 * */

ES_t MGPIO_enuResetPinValueDirectly(u8 Copy_u8PortId, u8 Copy_u8PinId);

/* Copy_u8GroupId   : MGPIO_PORTA                   MGPIO_PORTB                 MGPIO_PORTC
 * Copy_u8PinId     : MGPIO_PIN0 --> MGPIO_PIN15    MGPIO_PIN0 --> MGPIO_PIN15  MGPIO_PIN13 --> MGPIO_PIN15
 * Copy_u8PinId     : MGPIO_AF0 --> MGPIO_AF15
 * */

ES_t MGPIO_enuSelectAlternateFunctionPin(u8 Copy_u8PortId, u8 Copy_u8PinId,u8 Copy_u8AltFunNumber);

/*****************************************************************************************************************/

#define MGPIO_PORTA                   0
#define MGPIO_PORTB                   1
#define MGPIO_PORTC                   2

#define MGPIO_PIN0                    0
#define MGPIO_PIN1                    1
#define MGPIO_PIN2                    2
#define MGPIO_PIN3                    3
#define MGPIO_PIN4                    4
#define MGPIO_PIN5                    5
#define MGPIO_PIN6                    6
#define MGPIO_PIN7                    7
#define MGPIO_PIN8                    8
#define MGPIO_PIN9                    9
#define MGPIO_PIN10                   10
#define MGPIO_PIN11                   11
#define MGPIO_PIN12                   12
#define MGPIO_PIN13                   13
#define MGPIO_PIN14                   14
#define MGPIO_PIN15                   15

#define MGPIO_INPUT	                  0x00000000
#define MGPIO_OUTPUT                  0x00000001
#define MGPIO_AF                      0x00000002
#define MGPIO_ANALOG                  0x00000003

#define MGPIO_PUSH_PULL               0x0000
#define MGPIO_OPEN_DRAIN              0x0001

#define MGPIO_LOW_SPEED               0x00000000
#define MGPIO_MEDIUM_SPEED            0x00000001
#define MGPIO_HIGH_SPEED              0x00000002
#define MGPIO_VERY_HIGH_SPEED         0x00000003

#define MGPIO_NO_PULL                 0x00000000
#define MGPIO_PULL_UP                 0x00000001
#define MGPIO_PULL_DOWN               0x00000002

#define MGPIO_LOW_OUTPUT              0x0000
#define MGPIO_HIGH_OUTPUT             0x0001

#define MGPIO_AF0                     0x00000000
#define MGPIO_AF1                     0x00000001
#define MGPIO_AF2                     0x00000002
#define MGPIO_AF3                     0x00000003
#define MGPIO_AF4                     0x00000004
#define MGPIO_AF5                     0x00000005
#define MGPIO_AF6                     0x00000006
#define MGPIO_AF7                     0x00000007
#define MGPIO_AF8                     0x00000008
#define MGPIO_AF9                     0x00000009
#define MGPIO_AF10                    0x0000000A
#define MGPIO_AF11                    0x0000000B
#define MGPIO_AF12                    0x0000000C
#define MGPIO_AF13                    0x0000000D
#define MGPIO_AF14                    0x0000000E
#define MGPIO_AF15                    0x0000000F


#endif /* GPIO_INTERFACE_H_ */

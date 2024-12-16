/*
 * NVIC_INTERFACE..h
 *
 *  Created on  : Aug 21, 2023
 *
 *  Author      : Mahmoud Gamal Ahmed
 *
 *  Description : this file contain on APIs for NVIC DRIVER
 *  and names of variables that we use it as inputs to this APIs
 */

  /* file guard*/
#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

/*#define MemManage                        0
#define BusFault                         1
#define UsageFault                       2
#define SVCall                           3
#define Debug_Monitor                    4
#define PendSv                           5
#define SysTick                          6*/
#define Watch_Dog                        0
#define EXTI16_PVD                       1
#define EXTI21_Tamp_Stamp                2
#define EXTI22_RTCWkup                   3
#define FLASH                            4
#define RCC                              5
#define EXTI0                            6
#define EXTI1                            7
#define EXTI2                            8
#define EXTI3                            9
#define EXTI4                            10
#define DMA1Stream0                      11
#define DMA1Stream1                      12
#define DMA1Stream2                      13
#define DMA1Stream3                      14
#define DMA1Stream4                      15
#define DMA1Stream5                      16
#define DMA1Stream6                      17
#define ADC                              18
#define EXTI5_9                          23
#define Tim1Break_Tim9Global             24
#define Tim1Update_Tim10Global           25
#define Tim1Trigger_Tim11Global          26
#define Tim1CapCompare                   27
#define Tim2Global                       28
#define Tim3Global                       29
#define Tim4Global                       30
#define I2C1Ev                           31
#define I2C1Er                           32
#define I2C2Ev                           33
#define I2C2Er                           34
#define SPI1Global                       35
#define SPI2Global                       36
#define USART1Global                     37
#define USART2Global                     38
#define EXTI10_15                        40
#define EXTI17_RTCAlarm                  41
#define EXTI18_OTG                       42
#define DMA1Stream7                      47
#define SDIOGlobal                       49
#define Tim5Global                       50
#define SPI3Global                       51
#define DMA2Stream0                      56
#define DMA2Stream1                      57
#define DMA2Stream2                      58
#define DMA2Stream3                      59
#define DMA2Stream4                      60
#define OTGGlobal                        67
#define DMA2Stream5                      68
#define DMA2Stream6                      69
#define DMA2Stream7                      70
#define USART6                           71
#define I2C3Ev                           72
#define I2C3Er                           73
#define FPU                              81
#define SPI4                             84

typedef struct {

	u8 group_pirority;
	u8 sub_priority;

}IRQ_PRIORITY;
/* this function make initialization for NVIC DRIVER*/
void NVIC_voidinit(void);


/* this function take interrupt name and enable it inside NVIC peripheral
 *
 * some names of interrupts are :
 * MemManage/BusFault/UsageFault/SVCall/Debug_Monitor/PendSv/SysTick/Watch_Dog/EXTI16_PVD/EXTI21_Tamp_Stamp/EXTI22_RTCWkup
 * FLASH/RCC/EXTI0/EXTI1/EXTI2/EXTI3/EXTI4/etc...
 *
 * */
ES_t NVIC_enumenable_interrupt(u8 copy_u8interrupt_id);



/* this function take interrupt name and disable it inside NVIC peripheral
 *
 * some names of interrupts are :
 * MemManage/BusFault/UsageFault/SVCall/Debug_Monitor/PendSv/SysTick/Watch_Dog/EXTI16_PVD/EXTI21_Tamp_Stamp/EXTI22_RTCWkup
 * FLASH/RCC/EXTI0/EXTI1/EXTI2/EXTI3/EXTI4/etc...
 *
 * */
ES_t NVIC_enumdisable_interrupt(u8 copy_u8interrupt_id);



/* this function take interrupt name and enable pending bit for it inside NVIC peripheral
 *
 * some names of interrupts are :
 * MemManage/BusFault/UsageFault/SVCall/Debug_Monitor/PendSv/SysTick/Watch_Dog/EXTI16_PVD/EXTI21_Tamp_Stamp/EXTI22_RTCWkup
 * FLASH/RCC/EXTI0/EXTI1/EXTI2/EXTI3/EXTI4/etc...
 *
 * */
ES_t NVIC_enumenable_pending(u8 copy_u8interrupt_id);



/* this function take interrupt name and disable pending bit for it inside NVIC peripheral
 *
 * some names of interrupts are :
 * MemManage/BusFault/UsageFault/SVCall/Debug_Monitor/PendSv/SysTick/Watch_Dog/EXTI16_PVD/EXTI21_Tamp_Stamp/EXTI22_RTCWkup
 * FLASH/RCC/EXTI0/EXTI1/EXTI2/EXTI3/EXTI4/etc...
 *
 * */
ES_t NVIC_enumdisable_pending(u8 copy_u8interrupt_id);


/* this function take interrupt name ,its group priority and its sub priority */
ES_t NVIC_enumset_pirority(u8 copy_u8interrupt_id, u8 copy_u8group_pirority, u8 copy_u8sub_pirority);


/* this function take interrupt name and return its pending state
 * some names of interrupts are :
 * MemManage/BusFault/UsageFault/SVCall/Debug_Monitor/PendSv/SysTick/Watch_Dog/EXTI16_PVD/EXTI21_Tamp_Stamp/EXTI22_RTCWkup
 * FLASH/RCC/EXTI0/EXTI1/EXTI2/EXTI3/EXTI4/etc...
 *
 * pending state is : NoPending or InPending
 * */
ES_t NVIC_enumgetpending_state(u8 copy_u8interrupt_id,u8* copy_u8value);


/* this function take interrupt name and return its priority
 * some names of interrupts are :
 * MemManage/BusFault/UsageFault/SVCall/Debug_Monitor/PendSv/SysTick/Watch_Dog/EXTI16_PVD/EXTI21_Tamp_Stamp/EXTI22_RTCWkup
 * FLASH/RCC/EXTI0/EXTI1/EXTI2/EXTI3/EXTI4/etc...
 *
 * */
ES_t NVIC_enumgetpriority(u8 copy_u8interrupt_id,IRQ_PRIORITY* copy_structvalue);

/* this function take interrupt name and return its active state
 *
 * some names of interrupts are :
 * MemManage/BusFault/UsageFault/SVCall/Debug_Monitor/PendSv/SysTick/Watch_Dog/EXTI16_PVD/EXTI21_Tamp_Stamp/EXTI22_RTCWkup
 * FLASH/RCC/EXTI0/EXTI1/EXTI2/EXTI3/EXTI4/etc...
 *
 * active state is : NoActive or InActive
 * */
ES_t NVIC_enumgetactive_state(u8 copy_u8interrupt_id,u8* copy_u8value );
#endif /* NVIC_INTERFACE_H_ */

/*
 * NVIC_PRIVATE.h
 *
 *  Created on : Aug 21, 2023
 *
 *  Author     : Mahmoud Gamal Ahmed
 *
 *  Description: this file contain on NVIC DRIVER registers names
 *  and some definitions we need it to we can implement this driver
 */

  /* file guard*/
#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

/*#define InPending                                          1
#define NoPending                                          0
#define InActive                                           1
#define NoActive                                           0*/


/* define five configuration form of  priority*/
#define FOUR_BITSPRIORITYGROUP_NON_BITSUBPRIORITY          3
#define THREE_BITSPRIORITYGROUP_ONE_BITSUBPRIORITY         4
#define TWO_BITSPRIORITYGROUP_TWO_BITSUBPRIORITY           5
#define ONE_BITSPRIORITYGROUP_THREE_BITSUBPRIORITY         6
#define NON_BITSPRIORITYGROUP_FOUR_BITSUBPRIORITY          7

/* base address for NVIC peripheral*/
#define NVIC_BASE_ADDRESS                                  0xE000E100

/* struct contain on NVIC registers except NVIC_STIR*/
typedef struct {
	volatile u32 NVIC_ISER [32];
	volatile u32 NVIC_ICER [32];
	volatile u32 NVIC_ISPR [32];
	volatile u32 NVIC_ICPR [32];
	volatile u32 NVIC_IABR [64];
	volatile u8  NVIC_IPR [240];
}NVIC_registers;

/* define Application interrupt and reset control register (AIRCR)*/
#define AIRCR                                              *((volatile u32*)0xE000ED0C)
/* define Configuration and control register (CCR)*/
#define CCR                                                *((volatile u32*)0xE000ED14)
/* define bit USERSETMPEND in CCR*/
#define USERSETMPEND                1

/* take object from struct NVIC_registers allocate start of this object NVIC_BASE_ADDRESS  */
#define NVIC                                               ((NVIC_registers*)NVIC_BASE_ADDRESS)

/* define Software trigger interrupt register (NVIC_STIR)*/
#define NVIC_STIR                                          *((volatile u32*)0xE000EF00)

#endif /* NVIC_PRIVATE_H_ */

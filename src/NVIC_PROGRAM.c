/*
 * NVIC_PROGRAM.c
 *
 *  Created on  : Aug 21, 2023
 *
 *  Author      : Mahmoud Gamal Ahmed
 *
 *  Description : this file contain on implementations for NVIC DRIVER functions
 *
 *
 */
#include "STD_datatypes.h"
#include "State_errors.h"
#include "NVIC_PRIVATE.h"
#include "NVIC_CONFIGURATION.h"
#include "NVIC_INTERFACE.h"
#include <math.h>

void NVIC_voidinit(){

	assign_xbits_value(AIRCR,7,PRIORITY_FORM,8);

}



/* this function take interrupt name and enable it inside NVIC peripheral
 *
 * some names of interrupts are :
 * MemManage/BusFault/UsageFault/SVCall/Debug_Monitor/PendSv/SysTick/Watch_Dog/EXTI16_PVD/EXTI21_Tamp_Stamp/EXTI22_RTCWkup
 * FLASH/RCC/EXTI0/EXTI1/EXTI2/EXTI3/EXTI4/etc...
 *
 * */
ES_t NVIC_enumenable_interrupt(u8 copy_u8interrupt_id){

	ES_t state_error=ES_NOK;
	if(copy_u8interrupt_id<=239){

		set_bit((NVIC->NVIC_ISER[copy_u8interrupt_id/32]),(copy_u8interrupt_id%32));
		state_error=ES_OK;
	}
	else{
		state_error=ES_OUT_OF_RANGE;
	}
    return state_error;

}



/* this function take interrupt name and disable it inside NVIC peripheral
 *
 * some names of interrupts are :
 * MemManage/BusFault/UsageFault/SVCall/Debug_Monitor/PendSv/SysTick/Watch_Dog/EXTI16_PVD/EXTI21_Tamp_Stamp/EXTI22_RTCWkup
 * FLASH/RCC/EXTI0/EXTI1/EXTI2/EXTI3/EXTI4/etc...
 *
 * */
ES_t NVIC_enumdisable_interrupt(u8 copy_u8interrupt_id){

    ES_t state_error=ES_NOK;
    if(copy_u8interrupt_id<=239){

    	set_bit((NVIC->NVIC_ICER[copy_u8interrupt_id/32]),(copy_u8interrupt_id%32));
		state_error=ES_OK;
	}
	else{
		state_error=ES_OUT_OF_RANGE;
	}
	   return state_error;
}



/* this function take interrupt name and enable pending bit for it inside NVIC peripheral
 *
 * some names of interrupts are :
 * MemManage/BusFault/UsageFault/SVCall/Debug_Monitor/PendSv/SysTick/Watch_Dog/EXTI16_PVD/EXTI21_Tamp_Stamp/EXTI22_RTCWkup
 * FLASH/RCC/EXTI0/EXTI1/EXTI2/EXTI3/EXTI4/etc...
 *
 * */
ES_t NVIC_enumenable_pending(u8 copy_u8interrupt_id){
	ES_t state_error=ES_NOK;
	if(copy_u8interrupt_id<=239){
	   	set_bit((NVIC->NVIC_ISPR[copy_u8interrupt_id/32]),(copy_u8interrupt_id%32));
		state_error=ES_OK;
	}
	else{
		state_error=ES_OUT_OF_RANGE;
	}
	    return state_error;


}



/* this function take interrupt name and disable pending bit for it inside NVIC peripheral
 *
 * some names of interrupts are :
 * MemManage/BusFault/UsageFault/SVCall/Debug_Monitor/PendSv/SysTick/Watch_Dog/EXTI16_PVD/EXTI21_Tamp_Stamp/EXTI22_RTCWkup
 * FLASH/RCC/EXTI0/EXTI1/EXTI2/EXTI3/EXTI4/etc...
 *
 * */
ES_t NVIC_enumdisable_pending(u8 copy_u8interrupt_id){
	ES_t state_error=ES_NOK;
		if(copy_u8interrupt_id<=239){
			set_bit((NVIC->NVIC_ICPR[copy_u8interrupt_id/32]),(copy_u8interrupt_id%32));
			state_error=ES_OK;
		}
		else{
			state_error=ES_OUT_OF_RANGE;
		}
		    return state_error;

}


/* this function take interrupt name ,its group priority and its sub priority */
ES_t NVIC_enumset_pirority(u8 copy_u8interrupt_id, u8 copy_u8group_pirority, u8 copy_u8sub_pirority){
	ES_t state_error=ES_NOK;
	if((copy_u8interrupt_id<=239)&&(copy_u8group_pirority<=(((u8)(pow(2,(7-PRIORITY_FORM))+1e-9))-1))&&(copy_u8sub_pirority<=(((u8)(pow(2,(PRIORITY_FORM-3))+1e-9))-1))){
		NVIC->NVIC_IPR[copy_u8interrupt_id]|=((copy_u8group_pirority<<(PRIORITY_FORM+1))|(copy_u8sub_pirority<<4));
		state_error=ES_OK;
    }
    else{
    	state_error=ES_OUT_OF_RANGE;
    }
    return state_error;
}


/* this function take interrupt name and return its pending state
 * some names of interrupts are :
 * MemManage/BusFault/UsageFault/SVCall/Debug_Monitor/PendSv/SysTick/Watch_Dog/EXTI16_PVD/EXTI21_Tamp_Stamp/EXTI22_RTCWkup
 * FLASH/RCC/EXTI0/EXTI1/EXTI2/EXTI3/EXTI4/etc...
 *
 * pending state is : NoPending or InPending
 * */
ES_t NVIC_enumgetpending_state(u8 copy_u8interrupt_id,u8* copy_u8value){
	ES_t state_error=ES_NOK;
	if((copy_u8interrupt_id<=239)&&(copy_u8value!=Null)){
		* copy_u8value=read_bit((NVIC->NVIC_ISPR[copy_u8interrupt_id/32]),(copy_u8interrupt_id%32));
		state_error=ES_OK;
	}
	else{
		state_error=ES_OUT_OF_RANGE;
	}
	return state_error;
}


/* this function take interrupt name and return its priority
 * some names of interrupts are :
 * MemManage/BusFault/UsageFault/SVCall/Debug_Monitor/PendSv/SysTick/Watch_Dog/EXTI16_PVD/EXTI21_Tamp_Stamp/EXTI22_RTCWkup
 * FLASH/RCC/EXTI0/EXTI1/EXTI2/EXTI3/EXTI4/etc...
 *
 * */
ES_t NVIC_enumgetpriority(u8 copy_u8interrupt_id,IRQ_PRIORITY* copy_structvalue){

	ES_t state_error=ES_NOK;
		if((copy_u8interrupt_id<=239)&&(copy_structvalue!=Null)){
			copy_structvalue->group_pirority=(NVIC->NVIC_IPR[copy_u8interrupt_id]>>(PRIORITY_FORM+1));
			copy_structvalue->sub_priority=((NVIC->NVIC_IPR[copy_u8interrupt_id]&~(15<<(PRIORITY_FORM+1)))>>4);
			state_error=ES_OK;
		}
		else{
			state_error=ES_OUT_OF_RANGE;
		}
		return state_error;
}

/* this function take interrupt name and return its active state
 *
 * some names of interrupts are :
 * MemManage/BusFault/UsageFault/SVCall/Debug_Monitor/PendSv/SysTick/Watch_Dog/EXTI16_PVD/EXTI21_Tamp_Stamp/EXTI22_RTCWkup
 * FLASH/RCC/EXTI0/EXTI1/EXTI2/EXTI3/EXTI4/etc...
 *
 * active state is : NoActive or InActive
 * */
ES_t NVIC_enumgetactive_state(u8 copy_u8interrupt_id,u8* copy_u8value){

	ES_t state_error=ES_NOK;
		if((copy_u8interrupt_id<=239)&&(copy_u8value!=Null)){
			* copy_u8value=read_bit((NVIC->NVIC_IABR[copy_u8interrupt_id/32]),(copy_u8interrupt_id%32));
			state_error=ES_OK;
		}
		else{
			state_error=ES_OUT_OF_RANGE;
		}
		return state_error;
}

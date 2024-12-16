/*
 * STD_TYPES.h
 *
 *  Created on: Feb 13, 2023
 *      Author: a-m-m
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned long long    u64  ;

typedef unsigned int u32;
typedef signed int s32;

typedef unsigned short int u16;
typedef signed short int s16;

typedef float f32;
typedef long f64;
typedef long double f96;

#define NULL ((void*)0)

typedef enum
{
	ES_NOK,
	ES_OK,
	OUT_OF_RANGE,
	NULL_POINTER
}ES_t;

typedef enum{
	FALSE,
	TRUE
}Bolean;



#endif /* _STD_TYPES_H_ */

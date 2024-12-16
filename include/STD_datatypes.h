/*
 * STD_datatypes.h
 *
 *      Created on     : Oct 17, 2022
 *
 *      Author         : Mahmoud Gamal Ahmed
 *
 *      Description    : this file contain on data types and other bit math
 */

#ifndef STD_DATATYPES_H_
#define STD_DATATYPES_H_

#define conc(w,e)                                                                      w##e
#define set_bit(regester_name,bit_number)                                              regester_name|=((u32)1<<bit_number)
#define clear_bit(regester_name,bit_number)                                            regester_name&=~((u32)1<<bit_number)
#define read_bit(regester_name,bit_number)                                             (((regester_name)>>bit_number)&(u32)1)
#define toggle_bit(regester_name,bit_number)                                           regester_name^=((u32)1<<bit_number)
#define assign_xbits_value(register_name,mask_value,xbits_value,shift_value);          register_name&=~((u32)mask_value<<shift_value);\
	                                                                                   register_name|=((u32)xbits_value<<shift_value);


typedef unsigned char      u8;
typedef unsigned short int u16;
typedef unsigned long int  u32;
typedef unsigned long long u64;

typedef signed char        s8;
typedef signed short int   s16;
typedef signed long int    s32;
typedef signed long long   s64;

typedef float              f32;
typedef double             f64;
typedef long double        f80;
#define Null               0

#endif /* STD_DATATYPES_H_ */

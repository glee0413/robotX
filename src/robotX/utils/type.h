/*
 * type.h
 *
 *  Created on: 2016年5月12日
 *      Author: light
 */

#ifndef SRC_UTILS_TYPE_H_
#define SRC_UTILS_TYPE_H_
#include <limits.h>

//refer to LP64
typedef unsigned char u8;
typedef char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;

#if __WORDSIZE == 64
typedef unsigned long u64;
typedef long s64;
#else
typedef unsigned long long u64;
typedef long long s64;
#endif



#endif /* SRC_UTILS_TYPE_H_ */

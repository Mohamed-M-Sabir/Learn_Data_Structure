/*
 * std_types.h
 *
 *  Created on: Oct 13, 2023
 *      Author: Mohamed Saber
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#define ZERO   0


/*
 * s stands for signed
 * u stands for unsigned
 * v stands for volatile
 */

typedef unsigned char 			uint8_t;
typedef unsigned short 			uint16_t;
typedef unsigned int 			uint32_t;
typedef unsigned long long 		uint64_t;
typedef float					float32_t;
typedef double 					float64_t;


typedef signed char 			sint8_t;
typedef signed short 			sint16_t;
typedef signed int 				sint32_t;
typedef signed long long 		sint64_t;



typedef volatile unsigned char 	vuint8_t;
typedef volatile unsigned short vuint16_t;
typedef volatile unsigned int 	vuint32_t;

typedef volatile signed char 	vsint8_t;
typedef volatile signed short 	vsint16_t;
typedef volatile signed int 	vsint32_t;

#endif /* STD_TYPES_H_ */

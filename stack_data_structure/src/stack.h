/*
 * stack.h
 *
 *  Created on: Oct 13, 2023
 *      Author: Mohamed Saber
 */

#ifndef STACK_H_
#define STACK_H_
#include "std_types.h"
#define STACK_MAX_SIZE 5
typedef struct {

	uint32_t stack_arr[STACK_MAX_SIZE];
	uint32_t stack_ptr;

}stack_type;


typedef enum
{
	OK,NOK
}ret_status;


typedef enum
{
	FULL,EMPTY,UTILIZED
}stack_status;

ret_status stack_init(stack_type *mystack);

ret_status stack_push(stack_type *mystack,uint32_t value);

ret_status stack_pop(stack_type *mystack,uint32_t *value);

ret_status stack_top(stack_type *mystack,uint32_t *value);

ret_status stack_size(stack_type *mystack,uint32_t *size);

ret_status stack_display(stack_type *mystack);

#endif /* STACK_H_ */

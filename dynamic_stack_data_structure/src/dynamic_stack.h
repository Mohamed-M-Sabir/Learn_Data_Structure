/*
 * dynamic_stack.h
 *
 *  Created on: Oct 14, 2023
 *      Author: Mohamed Saber
 */

#ifndef DYNAMIC_STACK_H_
#define DYNAMIC_STACK_H_

#include "std_types.h"

typedef struct
{
	void **stackArr;			/*points to the array that allocated in the heap*/
	sint32_t elementCount;		/*has the actual number of elements in the stack*/
	uint32_t stackMaxSize;		/*has the maximum number of elements in the stack*/
	sint32_t stackTop;			/*has the index of the top element in the stack*/

}d_stack_type;

typedef enum
{
	stack_ok,
	stack_nok,
	stack_full,
	stack_empty,
	stack_null

}stack_status_t;

d_stack_type* create_stack(uint32_t MaxSize, stack_status_t* ret_status);

d_stack_type* destroy_stack(d_stack_type* stack_obj, stack_status_t* ret_status);

stack_status_t stack_push(d_stack_type* stack_obj,uint32_t* item_ptr);

void *stack_pop(d_stack_type* stack_obj,stack_status_t* ret_status);

void *stack_top(d_stack_type* stack_obj,stack_status_t* ret_status);

stack_status_t stack_count(d_stack_type* stack_obj,uint32_t* count);

#endif /* DYNAMIC_STACK_H_ */

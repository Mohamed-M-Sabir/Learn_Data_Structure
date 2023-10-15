/*
 * dynamic_stack.c
 *
 *  Created on: Oct 14, 2023
 *      Author: Mohamed Saber
 */

#include <stdio.h>
#include "dynamic_stack.h"


static stack_status_t stack_status(d_stack_type* stack_obj)
{
	stack_status_t ret;
	if(stack_obj->stackMaxSize==stack_obj->elementCount)
	{
		ret=stack_full;
	}

	else if(stack_obj->elementCount==0)
	{
		ret=stack_empty;
	}
	else
	{
		ret=stack_ok;
	}

	return ret;
}

d_stack_type* create_stack(uint32_t MaxSize, stack_status_t *ret_status)
{
	d_stack_type *mystack;

	mystack=(d_stack_type*)malloc(sizeof(d_stack_type));

	if(!mystack)
	{
		*ret_status=stack_null;
	}

	else
	{
		mystack->stackTop=-1;
		mystack->stackMaxSize=MaxSize;
		mystack->elementCount=0;
		mystack->stackArr=(void**)calloc(mystack->stackMaxSize,sizeof(void*));
		if(!mystack->stackArr)
		{
			*ret_status=stack_null;
			free(mystack);
		}
		else
		{
			printf("stack is created\n");
			*ret_status=stack_ok;
		}
	}

	return mystack;
}



d_stack_type* destroy_stack(d_stack_type* stack_obj, stack_status_t *ret_status)
{
	if(NULL==stack_obj)
	{
		*ret_status=stack_null;
	}
	else
	{
		free(stack_obj);
		free(stack_obj->stackArr);
		*ret_status=stack_ok;
		printf("stack is destroyed\n");
	}

	return stack_obj;
}




stack_status_t stack_push(d_stack_type* stack_obj,uint32_t* item_ptr)
{
	stack_status_t ret;

	if(NULL==stack_obj || NULL==item_ptr)
	{
		ret = stack_null;
	}

	else
	{
		if(stack_full==stack_status(stack_obj))
		{
			ret = stack_full;
			printf("can't push to the stack, stack is full\n");
		}

		else
		{
			(stack_obj->stackTop)++;
			(stack_obj->elementCount)++;
			stack_obj->stackArr[stack_obj->stackTop]=item_ptr;

			printf("the value has pushed to the stack\n");
		}

		ret=stack_ok;
	}

	return ret;
}



void *stack_pop(d_stack_type* stack_obj,stack_status_t* ret_status)
{

	void *item;
		if(NULL==stack_obj)
		{
			*ret_status = stack_null;
		}

		else
		{
			if(stack_empty==stack_status(stack_obj))
			{
				*ret_status = stack_empty;
			}

			else
			{
				item=stack_obj->stackArr[stack_obj->stackTop];
				(stack_obj->stackTop)--;
				(stack_obj->elementCount)--;

			}

			*ret_status=stack_ok;
		}

		return item;
	}


void *stack_top(d_stack_type* stack_obj,stack_status_t* ret_status)
{

	    void *item;
		if(NULL==stack_obj)
		{
			*ret_status = stack_null;
		}

		else
		{
			if(stack_empty==stack_status(stack_obj))
			{
				*ret_status = stack_empty;
			}

			else
			{
				item=stack_obj->stackArr[stack_obj->stackTop];


			}

			*ret_status=stack_ok;
		}

		return item;
	}

stack_status_t stack_count(d_stack_type* stack_obj,uint32_t* count)
{
	stack_status_t ret_status;
	if(NULL==stack_obj)
			{
				ret_status = stack_null;
			}

			else
			{
				if(stack_empty==stack_status(stack_obj))
				{
					ret_status = stack_empty;
					*count=0;
				}

				else
				{
					*count=stack_obj->elementCount;


				}

				ret_status=stack_ok;
			}

			return ret_status;
		}


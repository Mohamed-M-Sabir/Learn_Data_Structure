/*
 ============================================================================
 Name        : stack_data_structure.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
int main(void) {

	stack_type stack1;
	uint32_t value;
	uint32_t size;
	stack_init(&stack1);

	stack_push(&stack1,5);
	stack_push(&stack1,23);
	stack_push(&stack1,33);
	stack_push(&stack1,10);
	stack_push(&stack1,12);
	stack_push(&stack1,13);
	stack_push(&stack1,14);
	stack_push(&stack1,15);
	stack_pop(&stack1,&value);
	stack_size(&stack1,&size);
	stack_top(&stack1,&value);

	stack_display(&stack1);


	return 0;
}

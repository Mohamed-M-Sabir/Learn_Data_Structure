/*
 ============================================================================
 Name        : dynamic_stack_data_structure.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "dynamic_stack.h"


int main(void) {

	d_stack_type *stack1;
	uint32_t size=5;
	uint32_t count;
	stack_status_t ret=stack_nok;

	uint32_t var1=43;
	//float32_t var2=32.43;
	//uint8_t var3='a';
	uint32_t ptr_out;
	stack1=create_stack(size,&ret);
	//destroy_stack(stack1,&ret);

	stack_push(stack1,&var1);
	//stack_push(stack1,&var2);
	//stack_push(stack1,&var3);


	ptr_out=*(uint32_t*)stack_pop(stack1,&ret);
	printf("the poped value is %d\n",ptr_out);
	ret=stack_count(stack1,&count);
	printf("the count is %d\n",count);

	return 0;
}

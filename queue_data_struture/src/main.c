/*
 ============================================================================
 Name        : queue_data_struture.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void) {


	uint32_t size=5;
	queue_status status=queue_nok;
	uint32_t var1=5;
	uint32_t var2=54;
	uint32_t var3=539;
	uint32_t var4=100;
	uint32_t var5=10440;
	uint32_t var6=1030;
	uint32_t var7=1030;

	sint32_t count;
	queue_t *queue1;

	void *front;
	void *rear;
	queue1=create_queue(&size,&status);

	enqueue(queue1,&var1);
	enqueue(queue1,&var2);
	enqueue(queue1,&var3);
	enqueue(queue1,&var4);
	enqueue(queue1,&var5);

	dequeue(queue1,&status);

	enqueue(queue1,&var6);

	dequeue(queue1,&status);
	//enqueue(queue1,&var6);
	//enqueue(queue1,&var7);

	queue_count(queue1,&count);

	front=queue_front(queue1,&status);
	rear=queue_rear(queue1,&status);

	printf("the front is %d , the rear is %d \n",*((uint32_t*)front),*((uint32_t*)rear));

	queue_destroy(queue1);


	return 0;
}

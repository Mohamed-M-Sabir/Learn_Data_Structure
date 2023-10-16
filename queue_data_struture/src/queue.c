/*
 * queue.c
 *
 *  Created on: Oct 15, 2023
 *      Author: Mohamed Saber
 */

#include "queue.h"
#include <stdio.h>


static uint8_t queue_full(queue_t *queue_obj)
{
	if((queue_obj->queueElementCount)==(queue_obj->queueMaxSize))
	{
		return 1;
	}

	else
	{
		return 0;
	}
}



static uint8_t queue_empty(queue_t *queue_obj)
{
	if((queue_obj->queueElementCount)==0)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

queue_t *create_queue(uint32_t *queueMaxSize,queue_status *status)
{
	queue_t *myqueue;

	myqueue=(queue_t*)malloc(sizeof(queue_t));

	if(NULL==myqueue)
	{
		*status=queue_nok;
		printf("failed to create queue\n");
		myqueue=NULL;
	}

	else
	{
		myqueue->queueMaxSize=*queueMaxSize;
		myqueue->queueElementCount=0;
		myqueue->queueFront=-1;
		myqueue->queueRear=-1;
		myqueue->queuearr=(void**)calloc(*queueMaxSize,sizeof(void*));

		if(NULL==(myqueue->queuearr))
		{
			*status=queue_nok;
			printf("failed to create queue\n");
			myqueue=NULL;
		}

		else
		{
			*status=queue_ok;
			printf("queue created successfully\n");
		}
	}
	return myqueue;
}


queue_status enqueue(queue_t *queue_obj,void *item_ptr)
{
	queue_status ret;

	if(NULL==queue_obj||NULL==item_ptr)
	{
		ret=queue_nok;
		printf("enqueue failed,null pointer\n");


	}

	else
	{

		if(queue_full(queue_obj))
		{
			ret=queue_nok;
			printf("queue is full can't enqueue !\n");
		}

		else
		{
			if((queue_obj->queueElementCount)==0)
			{
				queue_obj->queueFront++;
			}
			(queue_obj->queueElementCount)++;
			queue_obj->queueRear++;

			queue_obj->queuearr[queue_obj->queueRear]=item_ptr;
			printf("the value %d is enqueued \n",*((uint32_t*)item_ptr));


			if((queue_obj->queueRear)==(queue_obj->queueMaxSize)&&(queue_obj->queueElementCount)<(queue_obj->queueMaxSize))
			{
				queue_obj->queueRear=-1;
			}
		}

	}
	return ret;
}

void *dequeue(queue_t *queue_obj,queue_status *status)
{
	void* ptr_out;

	if(NULL==queue_obj)
	{
		*status=queue_nok;
	}

	else
	{
		if(queue_empty(queue_obj))
		{
			*status=queue_nok;
			printf("queue is empty can't dequeue ! \n");
		}

		else
		{
			ptr_out=queue_obj->queuearr[queue_obj->queueFront];
			if((queue_obj->queueFront)==(queue_obj->queueMaxSize))
			{
				queue_obj->queueFront=-1;
			}

			(queue_obj->queueFront)++;
			(queue_obj->queueElementCount)--;
			*status=queue_nok;
			printf("the value %d dequeued from the queue\n",*((uint32_t*)ptr_out));

			if(0==queue_obj->queueElementCount)
			{
				queue_obj->queueFront=-1;
				queue_obj->queueRear=-1;
			}


		}
	}
	return ptr_out;
}


void *queue_front(queue_t *queue_obj,queue_status *status)
{

	void *return_elem;
	if(NULL==queue_obj)
	{
		*status=queue_nok;
	}

	else
	{
		if(queue_empty(queue_obj))
		{
			*status=queue_nok;
			printf("queue is empty  ! \n");
		}

		else
		{
			return_elem=queue_obj->queuearr[queue_obj->queueFront];
			*status=queue_ok;
		}

	}
	return return_elem;
}


void *queue_rear(queue_t *queue_obj,queue_status *status)
{
	void *return_elem;
		if(NULL==queue_obj)
		{
			*status=queue_nok;
		}

		else
		{
			if(queue_empty(queue_obj))
			{
				*status=queue_nok;
				printf("queue is empty ! \n");
			}

			else
			{
				return_elem=queue_obj->queuearr[queue_obj->queueRear];
				*status=queue_ok;
			}

		}
		return return_elem;

}


queue_status *queue_count(queue_t *queue_obj,sint32_t *count)
{
	queue_status *status;
			if(NULL==queue_obj)
			{
				*status=queue_nok;
			}

			else
			{
				if(queue_empty(queue_obj))
				{
					*status=queue_nok;
					printf("queue is empty ! \n");
				}

				else
				{
					*count=queue_obj->queueElementCount;
					*status=queue_ok;

					printf("the count is %d \n",*count);
				}

			}
			return status;

}



queue_status queue_destroy(queue_t *queue_obj)
{
	       queue_status status;
	       status=queue_nok;
				if(NULL==queue_obj)
				{
					status=queue_nok;
				}

				else
				{
					free(queue_obj->queuearr);
					free(queue_obj);
					printf("the queue is destroyed\n");
					status=queue_ok;
				}

				return status;
}

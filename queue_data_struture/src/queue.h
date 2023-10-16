/*
 * queue.h
 *
 *  Created on: Oct 15, 2023
 *      Author: Mohamed Saber
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "std_types.h"

typedef struct
{
	void **queuearr;				/*pointer to array of void pointers*/
	uint32_t queueMaxSize;			/*maximum element in the queue*/
	sint32_t queueElementCount;		/*number of elements in the queue*/
	sint32_t queueFront;			/*index of the first element*/
	sint32_t queueRear;				/*index of the last element*/
}queue_t;


typedef enum
{
	queue_ok,
	queue_nok
}queue_status;


queue_t *create_queue(uint32_t *queueMaxSize,queue_status *status);

queue_status enqueue(queue_t *queue_obj,void *item_ptr);
void *dequeue(queue_t *queue_obj,queue_status *status);
void *queue_front(queue_t *queue_obj,queue_status *status);
void *queue_rear(queue_t *queue_obj,queue_status *status);
queue_status *queue_count(queue_t *queue_obj,sint32_t *count);
queue_status queue_destroy(queue_t *queue_obj);
#endif /* QUEUE_H_ */

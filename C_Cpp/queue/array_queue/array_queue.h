#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

typedef struct _array_queue
{
	int size;
	int num; 
	int head;
	int tail;
	int *array;
}array_queue;

#define array_queue_is_empty(array_queue) (array_queue->num == 0)
#define array_queue_is_full(array_queue)  ((array_queue->num) == (array_queue->size))

#endif
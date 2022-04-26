

#include "header.h"

void queue_init(Queue *queue)
{
	queue->_size = 0;
	queue->_front = NULL;
	queue->_rear = NULL;
}

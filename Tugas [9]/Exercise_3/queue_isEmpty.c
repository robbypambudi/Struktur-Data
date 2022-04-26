
#include "header.h"

bool queue_isEmpty(Queue *queue)
{
	return (queue->_front == NULL && queue->_rear == NULL);
}

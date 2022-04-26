
#include "header.h"

void queue_pop(Queue *queue)
{
    if (!queue_isEmpty(queue))
    {
        QueueNode *temp = queue->_front;
        queue->_front = queue->_front->next;
        free(temp);

        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
    }
}

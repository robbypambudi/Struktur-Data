
#include "header.h"

int queue_front(Queue *queue)
{
    if (!queue_isEmpty(queue))
    {
        return (queue->_front->data);
    }
    return (int)0;
}

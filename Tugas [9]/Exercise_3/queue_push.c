
#include "header.h"

void queue_push(Queue *queue, int value)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (newNode)
    {
        queue->_size++;
        newNode->data = value;
        newNode->next = NULL;

        if (queue_isEmpty(queue))
            queue->_front = queue->_rear = newNode;
        else
        {
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
}

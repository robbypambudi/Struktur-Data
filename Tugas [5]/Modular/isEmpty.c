#include "header.h"

// fungsi untuk mengecek apakah pqueue kosong atau tidak

bool pqueue_isEmpty(PriorityQueue *pqueue)
{
    return (pqueue->_top == NULL); // pqueue->_top = NULL;
}
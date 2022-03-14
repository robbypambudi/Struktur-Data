#include "header.h"

int pqueue_top(PriorityQueue *pqueue)
{                                  // fungsi untuk mengembalikan nilai data pada pqueue->_top
    if (!pqueue_isEmpty(pqueue))   // jika pqueue tidak kosong
        return pqueue->_top->data; // return data pada pqueue->_top
    else
        return 0; // jika pqueue kosong
}
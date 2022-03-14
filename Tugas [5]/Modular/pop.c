#include "header.h"

// fungsi untuk menghapus elemen pada pqueue
void pqueue_pop(PriorityQueue *pqueue)
{
    // jika pqueue kosong
    if (!pqueue_isEmpty(pqueue))
    {
        // deklarasi variabel temp
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next; // pqueue->_top = pqueue->_top->next
        free(temp);                        // menghapus elemen pada pqueue
    }
}
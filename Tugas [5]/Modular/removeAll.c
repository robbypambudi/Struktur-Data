#include "header.h"

// fungsi untuk menghapus semua elemen pada pqueue
void pqueue_RemoveAll(PriorityQueue *pqueue)
{
    while (!pqueue_isEmpty(pqueue))
    {                       // jika pqueue tidak kosong
        pqueue_pop(pqueue); // menghapus elemen pada pqueue
    }
}
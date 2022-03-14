#include "header.h"

// Fungsi untuk menginisialisasi variabel pada struct node
void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL; // pqueue->_top = NULL;
    pqueue->_size = 0;   // pqueue->_size = 0;
}
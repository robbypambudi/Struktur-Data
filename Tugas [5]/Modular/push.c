#include "header.h"

void pqueue_push(PriorityQueue *pqueue, int value, bool letak)
{                                    // fungsi untuk menambahkan elemen pada pqueue
    PQueueNode *temp = pqueue->_top; // deklarasi variabel temp
    PQueueNode *newNode =
        (PQueueNode *)malloc(sizeof(PQueueNode)); // deklarasi variabel newNode
    newNode->data = value;                        // mengisi data pada newNode dengan value
    newNode->letak = letak;                       // mengisi letak pada newNode dengan letak
    newNode->next = NULL;                         // mengisi next pada newNode dengan NULL

    if (pqueue_isEmpty(pqueue))
    {                           // jika pqueue kosong
        pqueue->_top = newNode; // maka pqueue->_top = newNode
        return;                 // keluar dari fungsi
    }

    if (value > pqueue->_top->data)
    {                                 // jika value lebih besar dari data pada pqueue->_top
        newNode->next = pqueue->_top; // maka next pada newNode = pqueue->_top
        pqueue->_top = newNode;       // maka pqueue->_top = newNode
    }
    else
    { // jika tidak
        while (temp->next != NULL &&
               temp->next->data > value) // perulangan selama temp->next != NULL dan data pada temp->next > value
            temp = temp->next;           // temp = temp->next
        newNode->next = temp->next;      // next pada newNode = temp->next
        temp->next = newNode;            // temp->next = newNode
    }
}
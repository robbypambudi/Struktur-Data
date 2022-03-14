#include "header.h"

// Fungsi untuk melihat data pada pqueue atau debuging
void pqueue_print(PriorityQueue *pqueue)
{
    PQueueNode *temp = pqueue->_top; // deklarasi variabel temp
    while (temp != NULL)
    {                                               // perulangan selama temp != NULL
        printf("%d ", temp->data);                  // mencetak data pada temp
        printf(temp->letak ? " True " : " False "); // mencetak letak pada temp
        temp = temp->next;                          // temp = temp->next
    }
    printf("\n");
}
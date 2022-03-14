#include "header.h"

// fungsi untuk menyelesaikan tugas
int solve(PriorityQueue *pqueue)
{
    // Check apakah data ada atau tidak
    if (pqueue_isEmpty(pqueue))
    {
        printf("Queue kosong\n");
        return -1;
    }

    PQueueNode *temp = pqueue->_top; // deklarasi variabel temp
    int time = 0;                    // deklarasi variabel time
    while (temp != NULL)
    {           // perulangan selama temp tidak kosong
        time++; // time = time + 1
        if (temp->letak)
        { // jika letak pada temp = true return nilai time
            return time;
        }
        temp = temp->next; // temp = temp->next
    }
    return -1;
}
#include "header.h"

void popAt(Clist *L, int index)
{
    CLinkedList *prev = L->first;       // mengambil pointer first
    CLinkedList *curr = L->first->next; // mengambil pointer next
    // printf("\n");
    for (int i = 0; i < index; i++)
    {                      // looping untuk mencari pointer sesuai index
        prev = curr;       // mengubah pointer prev menjadi pointer next
        curr = curr->next; // mengubah pointer curr menjadi pointer next
    }
    prev->next = curr->next; // mengubah pointer prev menjadi pointer next
    if (curr == L->last)
    {                   // jika pointer curr sama dengan pointer last
        L->last = prev; // mengubah pointer last menjadi pointer prev
    }
    free(curr); // menghapus pointer curr
    L->_size--; // mengurangi size
}
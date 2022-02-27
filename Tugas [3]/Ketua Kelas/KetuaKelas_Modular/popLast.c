#include "header.h"

void popLast(Clist *L)
{
    CLinkedList *curr = L->last;  // mengambil pointer last
    CLinkedList *prev = L->first; // mengambil pointer first
    while (prev->next != L->last)
    {                      // looping untuk mencari pointer last
        prev = prev->next; // mengubah pointer prev menjadi pointer next
    }
    prev->next = L->first; // mengubah pointer prev menjadi pointer first
    L->last = prev;        // mengubah pointer last menjadi pointer prev
    free(curr);            // menghapus pointer last
    L->_size--;            // mengurangi size
}
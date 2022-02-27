#include "header.h" // menambahkan header

void popFirst(Clist *L)
{
    L->first = L->first->next; // mengubah pointer first menjadi pointer next
    if (L->first == NULL)
    { // jika pointer next kosong
        L->last = NULL;
    }
    L->_size--; // mengurangi size
}
#include "header.h" // menambahkan header

void popFirst(Clist *L)
{
    L->first = L->first->next;
    printf("1 ");
    if (L->first == NULL)
    {
        L->last = NULL;
    }
    L->_size--;
}
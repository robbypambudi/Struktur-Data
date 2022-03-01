#include "header.h"

void popLast(Clist *L)
{
    CLinkedList *curr = L->last;
    CLinkedList *prev = L->first;
    while (prev->next != L->last)
    {
        prev = prev->next;
    }
    printf("%d ", prev->next->id);
    prev->next = L->first;
    L->last = prev;
    free(curr);
    L->_size--;
}
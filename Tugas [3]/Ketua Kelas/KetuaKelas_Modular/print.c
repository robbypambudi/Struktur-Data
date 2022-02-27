
#include "header.h"

void printAll(Clist *l)
{
    CLinkedList *curr = l->first;
    for (int i = 0; i < l->_size; i++)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}
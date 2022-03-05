#include "header.h"

void getTop(SList *list)
{
    if (list->_size == 0)
    { // Jika size = 0 maka return
        return;
    }
    else
    { // Jika tidak maka return data paling atas
        printf("%d\n", list->top->data);
    }
}
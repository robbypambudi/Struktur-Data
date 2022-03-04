#include "header.h"

void popFront(List *list)
{
    if (is_empty(list))
    { // Jika list kosong maka return
        return;
    }
    ListNode *temp = list->top;  // Menyimpan top dari list
    list->top = list->top->next; // Memindahkan top ke next
    free(temp);                  // Menghapus top
    list->_size--;               // Mengurangi _size
}
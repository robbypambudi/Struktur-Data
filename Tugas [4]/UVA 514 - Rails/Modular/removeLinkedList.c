#include "header.h"

void removeLinkedList(List *list)
{
    ListNode *current = list->top; // Current adalah pointer yang menunjuk ke node pertama
    while (current != NULL)
    { // Selama current tidak menunjuk ke NULL (berhenti ketika current menunjuk ke node terakhir)
        ListNode *temp = current;
        current = current->next;
        free(temp); // Menghapus node yang di-current
    }
    list->top = NULL; // Set top menunjuk ke NULL
    list->_size = 0;  // Set _size menunjuk ke 0
}
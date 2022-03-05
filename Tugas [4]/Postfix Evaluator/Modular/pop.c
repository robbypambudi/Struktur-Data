#include "header.h"

int pop(SList *list)
{ // Menghapus elemen paling atas dari list
    if (list->_size == 0)
    { // Jika size = 0 maka return -1
        return -1;
    }

    // Jika tidak maka return data paling atas
    SlinkedList *temp = list->top;
    list->top = list->top->next;
    list->_size--;
    int data = temp->data;
    free(temp); // Menghapus node paling atas
    return data;
}
#include "header.h"

void pushFront(List *list, int data)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode)); // Alokasi memori untuk node baru
    newNode->data = data;                                     // Isi Node dengan data
    newNode->next = list->top;
    list->top = newNode; // Terapkan node yang disi  sebagai top
    list->_size++;       // Tambahkan 1 pada size
}
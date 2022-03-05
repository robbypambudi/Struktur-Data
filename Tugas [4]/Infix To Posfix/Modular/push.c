#include "header.h"

void push(List *list, char data)
{                                                                      // Fungsi untuk menambahkan elemen pada list
    SLinkedList *newNode = (SLinkedList *)malloc(sizeof(SLinkedList)); // Membuat node baru
    newNode->data = data;
    newNode->next = list->top;
    list->top = newNode; // Menambahkan node baru pada top
    list->_size++;       // Menambahkan jumlah elemen pada list
}
#include "header.h"

void push(SList *list, int data)
{                                                                      // Menambahkan elemen baru pada bagian atas list
    SlinkedList *newNode = (SlinkedList *)malloc(sizeof(SlinkedList)); // Membuat node baru
    newNode->data = data;                                              // Inisialisasi data
    newNode->next = list->top;                                         // Inisialisasi next dengan top
    list->top = newNode;                                               // Inisialisasi top dengan node baru
    list->_size++;                                                     // Inisialisasi _size dengan _size + 1
}
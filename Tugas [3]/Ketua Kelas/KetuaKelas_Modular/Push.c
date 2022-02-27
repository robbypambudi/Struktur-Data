#include "header.h" // menambahkan header

void push(Clist *l, int data)
{
    CLinkedList *newNode = (CLinkedList *)malloc(sizeof(CLinkedList)); // membuat node baru
    newNode->data = data;                                              // mengisi data
    newNode->next = l->first;                                          // mengisi pointer next dengan pointer first

    if (l->first == NULL)
    {                       // jika pointer first kosong
        l->first = newNode; // mengubah pointer first menjadi pointer baru
        l->last = newNode;  // mengubah pointer last menjadi pointer baru
    }
    else
    {
        l->last->next = newNode; // mengubah pointer last menjadi pointer baru
        l->last = newNode;       // mengubah pointer last menjadi pointer baru
    }
    l->_size++; // menambahkan size
}
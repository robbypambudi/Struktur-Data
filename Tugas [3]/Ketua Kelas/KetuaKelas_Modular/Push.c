#include "header.h" // menambahkan header

void push(Clist *l, int data)
{
    CLinkedList *newNode = (CLinkedList *)malloc(sizeof(CLinkedList)); // membuat node baru
    newNode->data = data;                                              // mengisi data
    newNode->next = l->first;                                          // mengisi next dengan first
    newNode->id = DATA_SIZE++;                                         // mengisi id dengan data size

    if (l->first == NULL)
    {
        l->first = newNode; // jika first kosong, maka first dan last menjadi node baru
        l->last = newNode;  // jika first kosong, maka first dan last menjadi node baru
    }
    else
    {
        l->last->next = newNode; // jika first tidak kosong, maka last menjadi node baru
        l->last = newNode;       // jika first tidak kosong, maka last menjadi node baru
    }
    l->_size++; // menambahkan data size
}
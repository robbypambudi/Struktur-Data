#include "header.h"

char pop(List *list)
{ // Fungsi untuk menghapus elemen pada list dan menampilkan elemen tersebut
    if (list->_size == 0)
    { // Jika list kosong
        return -1;
    }
    SLinkedList *temp = list->top; // Membuat node baru untuk menyimpan elemen pertama
    list->top = list->top->next;   // Menghapus elemen pertama
    list->_size--;                 // Mengurangi jumlah elemen pada list
    char data = temp->data;        // Menyimpan elemen pertama
    free(temp);                    // Menghapus node baru
    return data;                   // Mengembalikan elemen pertama
}
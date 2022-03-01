#include "header.h"

void popAt(Clist *L, int index)
{
    CLinkedList *prev = L->first;       // mengambil node sebelum node yang akan dihapus
    CLinkedList *curr = L->first->next; // mengambil node yang akan dihapus
    // printf("\n");
    for (int i = 0; i < index; i++)
    {
        prev = curr;       // prev = node sebelum node yang akan dihapus
        curr = curr->next; // curr = node yang akan dihapus
    }
    printf("%d ", curr->id); // print id node yang akan dihapus
    prev->next = curr->next; // prev = node sebelum node yang akan dihapus
    if (curr == L->last)
    {                   // jika node yang akan dihapus adalah node terakhir
        L->last = prev; // maka node terakhir menjadi node sebelum node yang akan dihapus
    }
    free(curr); // hapus node yang akan dihapus
    L->_size--; // kurangi jumlah node
}
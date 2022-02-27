#include "header.h"

NodePtr makeNode(int n)
{
    NodePtr np = (NodePtr)malloc(sizeof(Node)); // Membuat node baru
    np->num = n;                                // Menyimpan data n ke dalam node
    np->next = NULL;                            // Next diinisialisasi Null
    return np;                                  // Mengembalikan node baru
} // end makeNode

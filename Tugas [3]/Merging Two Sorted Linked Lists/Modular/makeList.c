#include "header.h"

NodePtr makeList()
{
    NodePtr makeNode(int), np, top, last; // deklarasi pointer np, top, last
    int n;                                // deklarasi variabel n
    top = NULL;                           // inisialisasi top dengan NULL
    if (scanf("%d", &n) != 1)             // jika tidak ada input
        n = 0;                            // maka n = 0
    while (n != 0)
    {                             // selama n bukan 0
        np = makeNode(n);         // create a new node containing n
        if (top == NULL)          // if the list is empty
            top = np;             // set top if first node
        else                      // otherwise
            last->next = np;      // set last -> next for other nodes
        last = np;                // update last to new node
        if (scanf("%d", &n) != 1) // jika tidak ada input
            n = 0;                // maka n = 0
    }
    return top; // return the top of the list
} // end makeList
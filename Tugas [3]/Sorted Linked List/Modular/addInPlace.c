#include "header.h" // Header file

NodePtr addInPlace(NodePtr top, int n)
{
    // This functions inserts n in its ordered position in a (possibly empty)
    // list pointed to by top, and returns a pointer to the new list
    NodePtr np, curr, prev, makeNode(int);
    np = makeNode(n);
    prev = NULL; // Variavel prev ini diinisalaisasi Null
    curr = top;  // Variavel curr ini diinisalaisasi top
    while (curr != NULL && n > curr->num)
    {                      // Ketika curr tidak kosong dan n lebih besar dari curr->num
        prev = curr;       // prev diinisialisasi dengan curr
        curr = curr->next; // curr diinisialisasi dengan curr->next
    }
    if (prev == NULL)
    {                   // new number must be added at the top
        np->next = top; // np->next diinisialisasi dengan top
        return np;      // the top of the list has changed to the new node
    }
    np->next = curr; // np->next diinisialisasi dengan curr
    prev->next = np; // prev->next diinisialisasi dengan np
    return top;      // the top of the list has not changed
} // end addInPlace
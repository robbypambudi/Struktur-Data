#include "header.h" // include header file
NodePtr merge(NodePtr A, NodePtr B)
{
    NodePtr C = NULL, last = NULL; // deklarasi pointer C dan last
    // check if either A or B is empty
    if (A == NULL) // jika A kosong
        return B;  // return B
    if (B == NULL) // jika B kosong
        return A;  // return A
    // both lists are non-empty
    while (A != NULL && B != NULL)
    { // as long as there's a node in A and B
        if (A->num < B->num)
        {                       //  Jika A < B
            if (C == NULL)      // if C is empty
                C = A;          // set C to A
            else                // Jika C tidak kosong
                last->next = A; // set last -> next to A
            last = A;           // update last to A
            A = A->next;        // update A to A -> next
        }
        else
        {                       // A >= B
            if (C == NULL)      // Jika C kosong
                C = B;          // set C to B
            else                // Jika C tidak kosong
                last->next = B; // set last -> next to B
            last = B;           // update last to B
            B = B->next;        // update B to B -> next
        }
    }                   // end while
    if (A == NULL)      // jika A kosong
        last->next = B; // set last -> next to B
    else                // jika A tidak kosong
        last->next = A; // set last -> next to A
    return C;           // return C
} // end merge
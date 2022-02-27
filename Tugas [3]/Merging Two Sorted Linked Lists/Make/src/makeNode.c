#include "header.h"

NodePtr makeNode(int n)
{
    NodePtr np = (NodePtr)malloc(sizeof(Node)); // allocate memory for a new node
    np->num = n;                                // Set variabel num di dalam node dengan n
    np->next = NULL;                            // Set variabel next di dalam node dengan NULL
    return np;                                  // return the new node
} // end makeNode
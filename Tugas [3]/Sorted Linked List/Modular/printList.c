#include "header.h"

void printList(NodePtr np)
{
    while (np != NULL)
    {                            // as long as there's a node
        printf("%d\n", np->num); // print the number
        np = np->next;           // go on to the next node
    }
} // end printList
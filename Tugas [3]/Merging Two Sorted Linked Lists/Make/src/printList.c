#include "header.h" // include header file

void printList(NodePtr np)
{
    while (np != NULL)
    {                           // as long as there's a node
        printf("%d ", np->num); // print the number
        np = np->next;          // go on to the next node
    }
    printf("\n\n"); // print a new line
} // end printList
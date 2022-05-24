/*
Nama    : Robby Ulung Pambudi
NRp     : 5025211042
Dibuat  : 24 May 2024

Permasalaahan :


*/

// implement hashing with chaining is to use a single array and use array subscripts as links
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 13
#define Empty 0
#define MaxItems 100
typedef struct node
{
    int num;  // key
    int next; // array subscript of the next item in the list
} Node;

Node hash[MaxItems + 1];
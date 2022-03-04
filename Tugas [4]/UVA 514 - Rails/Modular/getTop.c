#include "header.h"

int getTop(List *list)
{ // Mengembalikan nilai top dari list (jika list kosong maka return -1)
    return list->top->data;
}
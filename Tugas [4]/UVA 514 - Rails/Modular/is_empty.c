#include "header.h"

bool is_empty(List *list)
{ // Jika list kosong maka return true
    return list->top == NULL;
}
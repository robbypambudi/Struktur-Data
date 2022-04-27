#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dynamicArray_t
{
    char *data;
    int size;
    int capacity;
} dynamicArray;

void init(dynamicArray *array);
void getString(dynamicArray *array);
void printString(dynamicArray *array);

void init(dynamicArray *array)
{
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
}

void getString(dynamicArray *array)
{
    char input[100];
    gets(input);
    int length = strlen(input);
    if (array->capacity < length)
    {
        array->capacity = length;
        array->data = (char *)realloc(array->data, array->capacity * sizeof(char));
    }
    for (int i = 0; i < length; i++)
    {
        array->data[i] = input[i];
    }
    array->size = length;
}
void printString(dynamicArray *array)
{
    for (int i = 0; i < array->size; i++)
    {
        printf("%c", array->data[i]);
    }
}
int main()
{
    dynamicArray array;
    init(&array);
    getString(&array);
    printString(&array);
    return 0;
}
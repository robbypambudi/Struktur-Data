#include <iostream>
using namespace std;

typedef struct dynamic_array_t
{
    int *data;
    int size;
    int capacity;
} dynamic_array;

void darray_init(dynamic_array *array);
void daray_isEmpty(dynamic_array *array);
void darray_pushBack(dynamic_array *array, int value);

void darray_init(dynamic_array *array)
{
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
}

bool darray_isEmpty(dynamic_array *array)
{
    return array->size == 0;
}

void darray_pushBack(dynamic_array *array, int value)
{
    if (array->size == array->capacity)
    {
        array->capacity *= 2;
        array->data = (int *)realloc(array->data, array->capacity * sizeof(int));
    }
    array->data[array->size] = value;
    array->size++;
}

void darray_insertAt(dynamic_array *array, int index, int value)
{
    if (index < 0 || index > array->size)
    {
        return;
    }
    if (array->size == array->capacity)
    {
        array->capacity *= 2;
        array->data = (int *)realloc(array->data, array->capacity * sizeof(int));
    }
    for (int i = array->size; i > index; i--)
    {
        array->data[i] = array->data[i - 1];
    }
    array->data[index] = value;
    array->size++;
}

void darray_removeAt(dynamic_array *array, int index)
{
    if (index < 0 || index >= array->size)
    {
        return;
    }
    for (int i = index; i < array->size - 1; i++)
    {
        array->data[i] = array->data[i + 1];
    }
    array->size--;
}
int darray_getAt(dynamic_array *array, int index)
{
    if (index < 0 || index >= array->size)
    {
        return -1;
    }
    return array->data[index];
}
void print_all(dynamic_array *array)
{
    for (int i = 0; i < array->size; i++)
    {
        cout << array->data[i] << " ";
    }
    cout << endl;
}

int main()
{
    dynamic_array array;
    darray_init(&array);
    darray_pushBack(&array, 1);
    darray_pushBack(&array, 2);
    darray_pushBack(&array, 3);
    darray_pushBack(&array, 4);
    darray_pushBack(&array, 5);
    print_all(&array);
    darray_insertAt(&array, 2, 6);
    print_all(&array);
    darray_removeAt(&array, 2);
    print_all(&array);
    cout << darray_getAt(&array, 2) << endl;
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SlinkedList_t
{
    int data;
    struct SlinkedList_t *next;
} SlinkedList;

typedef struct SList_t
{
    SlinkedList *top;
    int _size;
} SList;

// Prototpye
void init(SList *list);
void push(SList *list, int data);
int pop(SList *list);
void getTop(SList *list);
void parsingPostfix(SList *list, char *input);

// Function

void init(SList *list)
{
    list->top = NULL;
    list->_size = 0;
}
void push(SList *list, int data)
{

    SlinkedList *newNode = (SlinkedList *)malloc(sizeof(SlinkedList));
    newNode->data = data;
    newNode->next = list->top;
    list->top = newNode;
    list->_size++;
}
int pop(SList *list)
{
    if (list->_size == 0)
    {
        return -1;
    }
    SlinkedList *temp = list->top;
    list->top = list->top->next;
    list->_size--;
    int data = temp->data;
    free(temp);
    return data;
}
void getTop(SList *list)
{
    if (list->_size == 0)
    {
        return;
    }
    else
    {
        printf("%d\n", list->top->data);
    }
}
void parsingPostfix(SList *list, char *input)
{
    // printf("%lu\n", strlen(input));
    int size = strlen(input);
    for (int i = 0; i < size; i++)
    {
        if (input[i] >= '0' && input[i] <= '9')
        {
            int angka = input[i] - '0';
            push(list, angka);
        }
        else
        {
            int op1, op2;
            op2 = pop(list);
            op1 = pop(list);
            switch (input[i])
            {
            case '+':
                push(list, op1 + op2);
                break;
            case '-':
                push(list, op1 - op2);
                break;
            case '*':
                push(list, op1 * op2);
                break;
            case '/':
                push(list, op1 / op2);
                break;
            }
        }
    }
    getTop(list);
}

int main()
{
    SList list;
    init(&list);

    char input[100];
    scanf("%s", input);

    while (strlen(input) > 1)
    {
        parsingPostfix(&list, input);
        scanf("%s", input);
    }
}
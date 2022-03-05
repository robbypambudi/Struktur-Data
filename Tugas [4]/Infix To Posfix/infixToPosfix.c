#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct SLinkedList_t
{
    char data;
    struct SLinkedList_t *next;
} SLinkedList;

typedef struct SList
{
    SLinkedList *top;
    int _size;
} List;

// Portotipe
void init(List *list);
void push(List *list, char data);
char pop(List *list);
int is_operator(char data);
int precedence(char data);
void InfixtoPostfix(List *list, char *infix, char *postfix);

// Function
void init(List *list)
{
    list->top = NULL;
    list->_size = 0;
}
void push(List *list, char data)
{
    SLinkedList *newNode = (SLinkedList *)malloc(sizeof(SLinkedList));
    newNode->data = data;
    newNode->next = list->top;
    list->top = newNode;
    list->_size++;
}

char pop(List *list)
{
    if (list->_size == 0)
    {
        return -1;
    }
    SLinkedList *temp = list->top;
    list->top = list->top->next;
    list->_size--;
    char data = temp->data;
    free(temp);
    return data;
}

int is_operator(char data)
{
    if (data == '+' || data == '-' || data == '*' || data == '/' || data == '^')
    {
        return 1;
    }

    return 0;
}

int precedence(char data)
{
    if (data == '^')
    {
        return 3;
    }
    else if (data == '*' || data == '/')
    {
        return 2;
    }
    else if (data == '+' || data == '-')
    {
        return 1;
    }

    return 0;
}

void InfixtoPostfix(List *list, char *infix, char *postfix)
{
    int i, j;
    char item;
    char x;
    push(list, '(');
    strcat(infix, ")");
    i = 0;
    j = 0;
    item = infix[i];

    while (item != '\0')
    {
        if (item == '(')
        {
            push(list, item);
        }
        else if (isdigit(item) || isalpha(item))
        {
            postfix[j] = item;
            j++;
        }
        else if (is_operator(item) == 1)
        {
            x = pop(list);

            while (is_operator(item) == 1 && precedence(x) >= precedence(item))
            {
                postfix[j] = x;
                j++;
                x = pop(list);
            }
            push(list, x);
            push(list, item);
        }
        else if (item == ')')
        {
            x = pop(list);

            while (x != '(')
            {
                postfix[j] = x;
                j++;
                x = pop(list);
            }
        }
        else
        {
            printf("Invalid Input\n");
            return;
        }
        i++;
        item = infix[i];
    }
    if (list->_size != 0)
    {
        printf("Invalid Input\n");
        return;
    }
    postfix[j] = '\0';
}

int main()
{
    List list;
    init(&list);
    char infix[1001], postfix[1001];
    gets(infix);
    InfixtoPostfix(&list, infix, postfix);
    puts(postfix);

    return 0;
}
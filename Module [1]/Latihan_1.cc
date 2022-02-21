/*
Created By  : Robby Ulung Pambudi
NRP         : 5025211042

Date        : Monday, Januari 21 2022

Permasalahan :
Buatlah program untuk memeriksa apakah sebuah string merupakan palindrom atau bukan menggunakan stack.

Contoh Input :
kasur_rusak
Contoh Output :
polindrom

*/

#include <bits/stdc++.h>
using namespace std;

typedef struct snode_t
{
    char data;
    struct snode_t *next;
} SListNode;

typedef struct _stack
{
    SListNode *top;
    unsigned _size;
} SStack;

bool stack_is_empty(SStack *stack)
{
    return stack->top == NULL;
}

void push(SStack *stack, int data)
{
    SListNode *node = (SListNode *)malloc(sizeof(SListNode));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
    stack->_size++;
}

void getString(string &s, SStack *stack)
{
    getline(cin, s);
    int i = 0;
    while (s[i] != '\0')
    {
        push(stack, s[i]);
        i++;
    }
}

bool polindrome_check(string &s, SStack *stack)
{
    int i = 0;

    while (!stack_is_empty(stack))
    {

        if (s[i] != stack->top->data)
        {
            return false;
        }
        stack->top = stack->top->next;
        i++;
    }
    return true;
}

int main()
{
    SStack *stack = (SStack *)malloc(sizeof(SStack));
    stack->top = NULL;
    stack->_size = 0;
    string *str;
    getString(*str, stack);
    printf("%s\n", polindrome_check(*str, stack) ? "palindrom" : "mahal, eh bukan palindrom deh");
}

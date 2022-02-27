#include <iostream>

using namespace std;

typedef struct stackNode_t
{
    char data;
    struct stackNode_t *next;
} stackNode;

typedef struct Stack_t
{
    stackNode *head;
    int _size;
} stack;

bool isEmpty(stack *stack);
void init(stack *stack);
void push(stack *stack, char value);
void getString(stack *stack);
void printElement(stack *node);

void init(stack *stack)
{
    stack->head = NULL;
    stack->_size = 0;
}

bool isEmpty(stack *stack)
{
    return stack->_size == 0;
}

void push(stack *stack, char value)
{
    stackNode *node = new stackNode;
    node->data = value;
    node->next = NULL;
    if (stack->head == NULL)
    {
        stack->head = node;
    }
    else
    {
        stackNode *temp = stack->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
    }
    stack->_size++;
}

void printElement(stack *node)
{
    stackNode *temp = node->head;
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }
}

void getString(stack *stack)
{
    char input[1000];
    cin.getline(input, 1000);
    int length = strlen(input);
    for (int i = 0; i < length; i++)
    {
        push(stack, input[i]);
    }
}

int main()
{
    stack stack;
    init(&stack);
    getString(&stack);
    printElement(&stack);
    return 0;
}

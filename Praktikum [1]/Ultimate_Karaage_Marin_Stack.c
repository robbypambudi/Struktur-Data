#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct stackNode_t
{
    int data;
    struct stackNode_t *next, *prev;
} StackNode;

typedef struct stack_t
{
    StackNode *_top, *_rear, *_topp;
    unsigned _size;
} Stack;

void init(Stack *stack)
{
    stack->_size = 0;
    stack->_top = NULL;
    stack->_topp = NULL;
    stack->_rear = NULL;
}

bool isEmpty(Stack *stack)
{
    return (stack->_top == NULL && stack->_rear == NULL);
}

void push(Stack *stack, int value)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (newNode)
    {
        stack->_size++;
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (isEmpty(stack))
        {
            stack->_top = newNode;
            stack->_topp = newNode;
            stack->_rear = newNode;
        }
        else
        {
            stack->_rear->prev = newNode;
            newNode->next = stack->_rear;
            stack->_rear = newNode;
        }
    }
}

void down(Stack *stack)
{
    stack->_top = stack->_top->prev;
    return;
}

void up(Stack *stack)
{
    stack->_top = stack->_top->next;
    return;
}

void downn(Stack *stack)
{
    stack->_topp = stack->_topp->prev;
    return;
}

int top(Stack *stack)
{
    if (!isEmpty(stack))
        return stack->_top->data;
    return 0;
}

int topp(Stack *stack)
{
    if (!isEmpty(stack))
        return stack->_topp->data;
    return 0;
}

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int maximum, na, nb;
        scanf("%d %d %d", &maximum, &na, &nb);

        int na_dup = na;
        int nb_dup = nb;

        Stack stack1, stack2;
        init(&stack1);
        init(&stack2);

        for (int j = 0; j < na; j++)
        {
            int num;
            scanf("%d", &num);
            push(&stack1, num);
        }

        for (int j = 0; j < nb; j++)
        {
            int num;
            scanf("%d", &num);
            push(&stack2, num);
        }

        int total = 0, count = 0;

        while (na--)
        {
            if (top(&stack1) + total > maximum)
            {
                up(&stack1);
                break;
            }
            total += top(&stack1);
            count++;
            if (na != 0)
            {
                down(&stack1);
            }
        }

        int count_a = count;
        int result = count;

        while (nb--)
        {
            total += top(&stack2);
            count++;
            down(&stack2);

            while (total > maximum)
            {
                if (count_a > 0)
                {
                    total -= top(&stack1);
                    up(&stack1);
                    count--;
                    count_a--;
                }
                else
                {
                    break;
                }
            }

            if (total <= maximum && result < count)
            {
                result = count;
            }
        }

        printf("%d pitik\n", result);

        int ada = 0;
        if (!result)
        {
            ada = 1;
            printf("GOJOOO-kunn wetengku lesu :(\n");
        }
        else if (result % 2 == 0)
        {
            while (na_dup--)
            {
                if (topp(&stack1) % 2 == 0)
                {
                    ada++;
                    if (ada == 1)
                    {
                        printf("NUM =>");
                    }
                    printf("%d ", topp(&stack1));
                }
                downn(&stack1);
                if (ada && na_dup == 0)
                {
                    printf("\n");
                }
            }
        }
        else
        {
            while (nb_dup--)
            {
                if (topp(&stack2) % 2 != 0)
                {
                    ada++;
                    if (ada == 1)
                    {
                        printf("NUM =>");
                    }
                    printf("%d ", topp(&stack2));
                }
                downn(&stack2);
                if (ada && nb_dup == 0)
                {
                    printf("\n");
                }
            }
        }

        if (!ada)
        {
            printf("Nihil\n");
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct SListNode
{
    int data;
    struct SListNode *next;
} ListNode;

typedef struct SList
{
    ListNode *top;
    int _size;

} List;

void init(List *list);
void pushFront(List *list, int data);
void popFront(List *list);
bool solve(List *list, int *arr, int train);
void removeLinkedList(List *list);
void printList(List *list);
bool is_empty(List *list);

void init(List *list)
{
    list->top = NULL;
    list->_size = 0;
}

bool is_empty(List *list)
{
    return list->top == NULL;
}

void pushFront(List *list, int data)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->data = data;
    newNode->next = list->top;
    list->top = newNode;
    list->_size++;
}

void removeLinkedList(List *list)
{
    ListNode *current = list->top;
    while (current != NULL)
    {
        ListNode *temp = current;
        current = current->next;
        free(temp);
    }
    list->top = NULL;
    list->_size = 0;
}

void popFront(List *list)
{
    if (is_empty(list))
    {
        return;
    }
    ListNode *temp = list->top;
    list->top = list->top->next;
    free(temp);
    list->_size--;
}

int getTop(List *list)
{
    return list->top->data;
}
bool solve(List *list, int *arr, int train)
{
    int now = 1;
    for (int i = 0; i < train; i++)
    {
        if (is_empty(list) && now <= train)
        {
            pushFront(list, now);
            now++;
        }
        while (getTop(list) != arr[i])
        {
            pushFront(list, now);
            now++;
            if (now > train + 1)
            {
                return false;
            }
        }
        popFront(list);
    }
    return true;
}

void uav514(List *list, int train)
{
    int arr[1001];
    int out;
    scanf("%d", &out);
    while (out != 0)
    {
        arr[0] = out;
        for (int i = 1; i < train; i++)
        {
            scanf("%d", &arr[i]);
        }
        if (solve(list, arr, train))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        removeLinkedList(list);
        scanf("%d", &out);
    }
}

int main()
{
    List list;
    init(&list);

    int train;
    while (1)
    {
        scanf("%d", &train);
        if (train == 0)
        {
            break;
        }
        uav514(&list, train);
    }
    return 0;
}
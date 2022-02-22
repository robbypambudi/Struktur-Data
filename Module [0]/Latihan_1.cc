#include <iostream>

using namespace std;

typedef struct SListNode
{
    int data;
    struct SListNode *next;
    struct SListNode *prev;
} ListNode;

typedef struct SList
{
    ListNode *next;
    int _size;
} List;

void dlist_init(List *list)
{
    list->next = NULL;
    list->_size = 0;
}

// Print all data on linked list
void printElement(ListNode *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

// Create fungtion to multiply all data on linkedlist
void multiply2(ListNode *node)
{
    while (node != NULL)
    {
        cout << node->data * 2 << " ";
        node->data *= 2;
        node = node->next;
    }
}

// Print data from linked list in reverse order
void reverseEach(ListNode *node)
{
    if (node == NULL)
    {
        return;
    }
    reverseEach(node->next);
    cout << node->data << " ";
}

void forEachElement(List *list, void (*f)(ListNode *))
{
    ListNode *node = list->next;

    f(node);

    cout << endl;
}

// Function to sum every data on linked list with data on next node
void sumDigit(ListNode *node)
{
    if (node == NULL)
    {
        return;
    }
    if (node->next == NULL)
    {
        return;
    }
    node->data += node->next->data;
    sumDigit(node->next);
    cout << node->data << " ";
}

// Insert data to double linked list
void push(List *list, int data)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;
    node->next = list->next;
    node->prev = NULL;
    if (list->next != NULL)
    {
        list->next->prev = node;
    }
    list->next = node;
    list->_size++;
}
int main()
{
    List myList;
    dlist_init(&myList);
    push(&myList, 5);
    push(&myList, 4);
    push(&myList, 3);
    push(&myList, 2);
    push(&myList, 1);
    forEachElement(&myList, printElement);
    forEachElement(&myList, multiply2);
    forEachElement(&myList, reverseEach);
    forEachElement(&myList, sumDigit);
}
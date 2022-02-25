#include <iostream>

using namespace std;

typedef struct SListNode
{
    char data;
    struct SListNode *next;
} ListNode;

typedef struct SList
{
    ListNode *head;
    int _size;
} List;

void init(List *list);
bool isEmpty(List *list);
void pushBack(List *list, char value);
void getString(List *list);
void printElement(ListNode *node);

void init(List *list)
{
    list->head = NULL;
    list->_size = 0;
}
bool isEmpty(List *list)
{
    return list->_size == 0;
}

void getString(List *list)
{
    char input[1000];
    cin.getline(input, 1000);
    int length = strlen(input);
    for (int i = 0; i < length; i++)
    {
        pushBack(list, input[i]);
    }
}
// Save Char data to linkedList
void pushBack(List *list, char value)
{
    ListNode *node = new ListNode;
    node->data = value;
    node->next = NULL;
    if (list->head == NULL)
    {
        list->head = node;
    }
    else
    {
        ListNode *temp = list->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
    }
    list->_size++;
}

void printElement(List *list)
{
    ListNode *node = list->head;
    while (node != NULL)
    {
        cout << node->data;
        node = node->next;
    }
    cout << endl;
}

int main()
{
    List list;
    init(&list);
    getString(&list);
    printElement(&list);
    return 0;
}

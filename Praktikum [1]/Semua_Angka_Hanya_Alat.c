#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct dnode_t
{
    int data;
    struct dnode_t
        *next,
        *prev;
} DListNode;

/* Struktur ADT List */

typedef struct dlist_t
{
    int dec;
    int base;
    DListNode
        *_head,
        *_tail;
    unsigned _size;
} List;

DListNode *__dlist_createNode(int value)
{
    DListNode *newNode =
        (DListNode *)malloc(sizeof(DListNode));

    if (!newNode)
        return NULL;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return (DListNode *)newNode;
}

void dlist_init(List *list)
{
    list->_head = list->_tail = NULL;
    list->_size = (unsigned)0;
}

bool dlist_isEmpty(List *list)
{
    return (list->_head == NULL &&
            list->_tail == NULL);
}

void dlist_pushBack(List *list, int value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode)
    {
        list->_size++;
        if (dlist_isEmpty(list))
        {
            list->_head = newNode;
            list->_tail = newNode;
            return;
        }

        list->_tail->next = newNode;
        newNode->prev = list->_tail;
        list->_tail = newNode;
    }
}
void convertAnyBase(List *list, int dec, int base)
{
    if (dec == 0)
        return;
    int x = dec % base;
    dec /= base;
    if (x < 0)
        dec += 1;
    convertAnyBase(list, dec, base);
    dlist_pushBack(list, x < 0 ? x + (base * -1) : x);
}
void printList(List *list)
{
    // Check Null
    if (dlist_isEmpty(list))
    {
        printf("Out of range\n");
        return;
    }

    DListNode *temp = list->_head;
    printf("%d %d -> ", list->dec, list->base);
    while (temp != NULL)
    {
        if (temp->next == NULL)
        {
            printf("%d", temp->data);
            temp = temp->next;
            continue;
        }
        printf("%d-", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Check Polindrome
void checkPolindrome(List *list)
{
    // Check Null

    if (dlist_isEmpty(list))
        return;

    DListNode *temp = list->_head;
    DListNode *temp2 = list->_tail;
    while (temp != temp2)
    {
        if (temp->data != temp2->data)
        {
            printf("Tidak\n");
            return;
        }
        temp = temp->next;
        temp2 = temp2->prev;
    }
    printf("Ya\n");
}
int main()
{
    List list[10010];
    int i = 0; // List[i];
    int N, M;
    while (true)
    {

        scanf("%d %d", &N, &M);

        // Input -1 -1
        if (M == -1 && N == -1)
        {
            break; // AC
        }
        else if (N == 0)
        {
            dlist_init(&list[i]);
            list[i].base = M;
            list[i].dec = N;
            printf("Ya\n");
            dlist_pushBack(&list[i], 0);
            i++;
            continue;
        }
        // Input depan -1
        else if (N == -1)
        {
            if (M > i || M < 0 || M > 10000)
            {
                printf("Out of range\n");
            }
            else
            {
                printList(&list[M]);
            }
            continue;
        }

        // Untuk Nambahin misal input 5 2
        else if (N != -1 || N != 0)
        {

            dlist_init(&list[i]);
            list[i].base = M;
            list[i].dec = N;
            if (M == 1)
            {
                for (int X = 0; X < N; X++)
                {
                    dlist_pushBack(&list[i], 0);
                }
                printf("Ya\n");
                i++;
                continue;
            }
            else
            {
                convertAnyBase(&list[i], N, M);
            }
            // printList(&list[i]);
            checkPolindrome(&list[i]);
            i++;
        }
    }
}
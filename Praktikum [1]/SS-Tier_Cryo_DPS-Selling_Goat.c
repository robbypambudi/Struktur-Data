#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct snode_t
{
    char kambing[50];
    struct snode_t *next;
} SListNode;

/* Struktur ADT SinglyList */

typedef struct slist_t
{
    unsigned _size;
    SListNode *_head;
} SinglyList;

void slist_init(SinglyList *list)
{
    list->_head = NULL;
    list->_size = 0;
}

bool slist_isEmpty(SinglyList *list)
{
    return (list->_head == NULL);
}
void slist_pushBack(SinglyList *list, char *kambing)
{
    SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));
    if (newNode)
    {
        list->_size++;
        strcpy(newNode->kambing, kambing);
        newNode->next = NULL;

        if (slist_isEmpty(list))
            list->_head = newNode;
        else
        {
            SListNode *temp = list->_head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}
void slist_popFront(SinglyList *list)
{
    if (!slist_isEmpty(list))
    {
        SListNode *temp = list->_head;
        list->_head = list->_head->next;
        free(temp);
        list->_size--;
    }
}
void slist_popBack(SinglyList *list)
{
    if (!slist_isEmpty(list))
    {
        SListNode *nextNode = list->_head->next;
        SListNode *currNode = list->_head;

        if (currNode->next == NULL)
        {
            free(currNode);
            list->_head = NULL;
            return;
        }

        while (nextNode->next != NULL)
        {
            currNode = nextNode;
            nextNode = nextNode->next;
        }
        currNode->next = NULL;
        free(nextNode);
        list->_size--;
    }
}

void slist_removeAt(SinglyList *list, int index)
{
    if (!slist_isEmpty(list))
    {

        /* Kasus apabila posisinya melebihi batas */
        if (index >= list->_size)
        {
            slist_popBack(list);
            return;
        }
        else if (index == 0 || index < 0)
        {
            slist_popFront(list);
            return;
        }

        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index - 1)
        {
            temp = temp->next;
            _i++;
        }
        SListNode *nextTo = temp->next->next;
        free(temp->next);
        temp->next = nextTo;
        list->_size--;
    }
}
int slist_getAt(SinglyList *list, int index)
{
    // Jika list tidak kosng
    if (!slist_isEmpty(list))
    {
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index)
        {
            temp = temp->next;
            _i++;
        }
        if (_i != index)
        {
            printf("Mending gacha Ganyu\n");
            return 2;
        }
        else
        {
            printf("%s\n", temp->kambing);
            return 1;
        }
    }
    printf("Mending gacha Ganyu\n");

    return 2;
}
int main()
{
    SinglyList list[100000];
    for (int i = 0; i < 100000; i++)
    {
        slist_init(&list[i]);
    }

    int N;
    int j = 0;
    char kambing[50];
    scanf("%d", &N);
    while (N--)
    {
        int K1;
        scanf("%d", &K1);
        if (K1 == 1)
        {
            int K2;
            scanf("%d", &K2);
            while (K2--)
            {
                scanf("%s", kambing);
                slist_pushBack(&list[j], kambing);
            }
            j++;
        }
        else if (K1 == 2)
        {
            int K2, K3;
            scanf("%d %d", &K2, &K3);
            // Check data K2 apakah lebih dari 10000 kurang dari 0 atau k3 Kurang dari 0
            if (K2 > 100000 || K2 <= 0 || K3 <= 0 || K2 > j)
            {
                printf("Mending gacha Ganyu\n");
                continue;
            }

            if (slist_getAt(&list[K2 - 1], K3 - 1) == 2)
            {
                continue;
            }
            slist_removeAt(&list[K2 - 1], K3 - 1);
        }
        else
        {
            continue;
        }
    }
}
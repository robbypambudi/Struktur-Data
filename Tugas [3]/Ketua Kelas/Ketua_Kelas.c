#include <stdio.h>
#include <stdlib.h>

typedef struct CLinkedList_t
{
    int data;
    int id;
    struct CLinkedList_t *next;
} CLinkedList;

typedef struct Clist_t
{
    CLinkedList *first;
    CLinkedList *last;
    int _size;

} Clist;

int DATA_SIZE = 1;

// Portotipe
void init(Clist *l);
void push(Clist *l, int data);
void popAt(Clist *l, int index);
void popFirst(Clist *l);
void popLast(Clist *l);
void printAll(Clist *l);
void init(Clist *l)
{
    l->first = NULL;
    l->last = NULL;
    l->_size = 0;
}

void push(Clist *l, int data)
{
    CLinkedList *newNode = (CLinkedList *)malloc(sizeof(CLinkedList));
    newNode->data = data;
    newNode->next = l->first;
    newNode->id = DATA_SIZE++;

    if (l->first == NULL)
    {
        l->first = newNode;
        l->last = newNode;
    }
    else
    {
        l->last->next = newNode;
        l->last = newNode;
    }
    l->_size++;
}

void popAt(Clist *L, int index)
{
    CLinkedList *prev = L->first;
    CLinkedList *curr = L->first->next;
    // printf("\n");
    for (int i = 0; i < index; i++)
    {
        prev = curr;
        curr = curr->next;
    }
    printf("%d ", curr->id);
    prev->next = curr->next;
    if (curr == L->last)
    {
        L->last = prev;
    }
    free(curr);
    L->_size--;
}
void popFirst(Clist *L)
{
    L->first = L->first->next;
    printf("1 ");
    if (L->first == NULL)
    {
        L->last = NULL;
    }
    L->_size--;
}

void popLast(Clist *L)
{
    CLinkedList *curr = L->last;
    CLinkedList *prev = L->first;
    while (prev->next != L->last)
    {
        prev = prev->next;
    }
    printf("%d ", prev->next->id);
    prev->next = L->first;
    L->last = prev;
    free(curr);
    L->_size--;
}

void printAll(Clist *l)
{
    CLinkedList *curr = l->first;
    for (int i = 0; i < l->_size; i++)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void ketuaKelas(Clist *l)
{

    int n, lompat;

    scanf("%d %d", &n, &lompat);

    // Masukan Data kedalam Linked List
    for (int i = 1; i <= n; i++)
    {
        push(l, i);
    }
    // printOut(l->_size, lompat);

    // Poling Data
    int i = 1;
    int temp = 1;
    int N = 1;
    int size = l->_size;
    while (l->_size != 1)
    {
        temp += lompat; // menambahkan lompat ke variabel temp

        // printf("%d temp", temp);
        if (temp > l->_size)
        {
            temp -= l->_size;
        }
        if (l->_size == 2 && temp == 2)
        {
            temp = 1;
        }

        if (temp == 1)
        {
            if (l->_size == 2 && (size % 2 == 0))
            {
                popLast(l);
            }
            else
            {
                popFirst(l);
            }
        }
        else if (temp == l->_size)
        {

            popLast(l);
        }
        else
        {
            popAt(l, temp - 2);
        }
        N += 1;
        // printf("N = %d\n", N);
        if (N > l->_size && temp > N)
        {
            N -= 1;
        }

        else if (N > l->_size && temp < N)
        {
            N -= l->_size;
        }
        temp = N;
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    Clist L[N];
    int i = 0;
    while (N--)
    {
        init(&L[i]);
        ketuaKelas(&L[i]);

        printf("@\n");
        printAll(&L[i]);
        i++;
        DATA_SIZE = 1;
    }
    return 0;
}
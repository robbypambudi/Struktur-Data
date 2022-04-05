#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct pqueueNode_t
{
    char Country[20];
    int date;
    int month;
    struct pqueueNode_t *next;
} PQueueNode;

/* Struktur ADT PriorityQueue menggunakan Linked List */

// Prioritas default: nilai minimum
typedef struct pqueue_t
{
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

/* Function prototype */

void pqueue_init(PriorityQueue *pqueue);
bool pqueue_isEmpty(PriorityQueue *pqueue);
void pqueue_push(PriorityQueue *pqueue, char *country, int date, int month);
void pqueue_pop(PriorityQueue *pqueue);
void pqueue_top(PriorityQueue *pqueue);

/* Function definition below */

void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue)
{
    return (pqueue->_top == NULL);
}

void pqueue_push(PriorityQueue *pqueue, char *country, int date, int month)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode =
        (PQueueNode *)malloc(sizeof(PQueueNode));
    strcpy(newNode->Country, country);
    newNode->date = date;
    newNode->month = month;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue))
    {
        pqueue->_top = newNode;
        return;
    }

    if (month < pqueue->_top->month)
    {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
        return;
    }
    if (month == pqueue->_top->month)
    {
        if (date < pqueue->_top->date)
        {
            newNode->next = pqueue->_top;
            pqueue->_top = newNode;
            return;
        }
    }

    while (temp->next != NULL)
    {
        if (month < temp->next->month)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        else if (month == temp->next->month)
        {
            if (date <= temp->next->date)
            {
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
        }
        temp = temp->next;
    }
    temp->next = newNode;
}

void pqueue_pop(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue))
    {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

void pqueue_top(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue))
        printf("Negara selanjutnya yaitu: %s\n", pqueue->_top->Country);
    else
        return;
}
void pqueue_all(PriorityQueue *pqueue)
{
    PQueueNode *temp = pqueue->_top;
    while (temp != NULL)
    {
        printf("Negara selanjutnya yaitu: %s\n", temp->Country);
        temp = temp->next;
    }
}

int main(int argc, char const *argv[])
{
    // Buat objek PriorityQueue
    PriorityQueue myPque;

    // PENTING! Jangan lupa diinisialisasi
    pqueue_init(&myPque);

    // Operasi pada priority queue
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        char country[20];
        int date, month;
        scanf("%s %d %d", country, &date, &month);
        pqueue_push(&myPque, country, date, month);
    }

    // cetak isi pque
    for (int i = 0; i <= M; i++)
    {
        if (i == M)
        {
            if (pqueue_isEmpty(&myPque))
                printf("Projek Rumbling Berhasil\n");
            else
                pqueue_top(&myPque);
        }
        pqueue_pop(&myPque);
    }
    return 0;
}
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct pqueueNode_t
{
    int data;
    bool letak;
    struct pqueueNode_t *next;
} PQueueNode;

/* Struktur ADT PriorityQueue menggunakan Linked List */

// Prioritas default: nilai minimum
typedef struct pqueue_t
{
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue)
{
    return (pqueue->_top == NULL);
}

void pqueue_push(PriorityQueue *pqueue, int value, bool letak)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode =
        (PQueueNode *)malloc(sizeof(PQueueNode));
    newNode->data = value;
    newNode->letak = letak;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue))
    {
        pqueue->_top = newNode;
        return;
    }

    if (value > pqueue->_top->data)
    {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else
    {
        while (temp->next != NULL &&
               temp->next->data < value)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
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
int pqueue_top(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->data;
    else
        return 0;
}
void pqueue_print(PriorityQueue *pqueue)
{
    PQueueNode *temp = pqueue->_top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        printf(temp->letak ? " True " : " False ");
        temp = temp->next;
    }
    printf("\n");
}

int solve(PriorityQueue *pqueue)
{
    // Check apakah data ada atau tidak
    if (pqueue_isEmpty(pqueue))
    {
        printf("Queue kosong\n");
        return -1;
    }
    // Check apakah data ada atau tidak
    PQueueNode *temp = pqueue->_top;
    int time = 0; //
    while (temp != NULL)
    {
        time++;
        if (temp->letak)
        {
            return time;
        }
        temp = temp->next;
    }
    return -1;
}
void pqueue_RemoveAll(PriorityQueue *pqueue)
{
    while (!pqueue_isEmpty(pqueue))
    {
        pqueue_pop(pqueue);
    }
}

int main()
{
    PriorityQueue pqueue;
    pqueue_init(&pqueue);
    int N;
    printf("Masukkan banyak data: ");
    scanf("%d", &N);
    while (N--)
    {
        int job, letak;
        printf("Masukkan banyak job dan letak contoh -> (1 2): ");
        scanf("%d %d", &job, &letak);

        // Error handeling
        if (job < 0 || letak < 0 || letak > job)
        {
            printf("Input tidak valid\n");
            return 0;
        }

        int data;
        printf("Masukkan data: ");
        for (int i = 0; i < job; i++)
        {

            scanf("%d", &data);
            if (letak == i)
            {
                pqueue_push(&pqueue, data, true);
                continue;
            }
            pqueue_push(&pqueue, data, false);
        }
        printf("Waktu : %d\n", solve(&pqueue));
        puts("------------------------------\n");
        pqueue_RemoveAll(&pqueue);
    }
    return 0;
}
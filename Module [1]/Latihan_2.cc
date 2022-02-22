#include <iostream>
#include <string.h>

using namespace std;

typedef struct pqueueNode_t
{
    int id;
    int priority;
    struct pqueueNode_t *next;
} PQueueNode;

typedef struct pqueue_t
{
    PQueueNode *head;
    int _size;
} PQueue;

void push(PQueue *queue, int id, int priority)
{
    PQueueNode *newNode = new PQueueNode;
    newNode->id = id;
    newNode->priority = priority;
    newNode->next = NULL;

    if (queue->head == NULL)
    {
        queue->head = newNode;
    }
    else
    {
        PQueueNode *curr = queue->head;
        PQueueNode *prev = NULL;
        while (curr != NULL && curr->priority > priority)
        {
            prev = curr;
            curr = curr->next;
        }
        if (prev == NULL)
        {
            newNode->next = queue->head;
            queue->head = newNode;
        }
        else
        {
            prev->next = newNode;
            newNode->next = curr;
        }
    }
    queue->_size++;
}

// Remove top element from queue
void pop(PQueue *queue)
{
    if (queue->head == NULL)
    {
        return;
    }
    else
    {
        PQueueNode *curr = queue->head;
        queue->head = queue->head->next;
        int id = curr->id;
        delete curr;
        queue->_size--;
        return;
    }
}

// Print top element of queue
void printTopQueue(PQueue *queue)
{
    if (queue->head == NULL)
    {
        cout << "HORE" << endl;
    }
    else
    {
        cout << queue->head->id << endl;
    }
}

void printQueue(PQueue *queue)
{
    PQueueNode *temp = queue->head;
    while (temp != NULL)
    {
        cout << temp->id << " ";
        cout << temp->priority << endl;
        temp = temp->next;
    }
    cout << endl;
}

void init(PQueue *queue)
{
    queue->head = NULL;
    queue->_size = 0;
}

void getOrder(PQueue *queue)
{
    char order[10];
    int id, priority;
    cin >> order;
    if (strcmp(order, "MASUK") == 0)
    {
        cin >> id >> priority;
        push(queue, id, priority);
    }
    else if (strcmp(order, "LAYANI") == 0)
    {
        printTopQueue(queue);
        pop(queue);
    }
    else if (strcmp(order, "CETAK") == 0)
    {
        printQueue(queue);
    }
    else
    {
        cout << "Perintah tidak dikenali" << endl;
    }
}
int main()
{
    PQueue *pqueue = (PQueue *)malloc(sizeof(PQueue));
    init(pqueue);

    int N;
    cin >> N;
    while (N--)
    {
        getOrder(pqueue);
    }
    return 0;
}
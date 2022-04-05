#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int hasil;

typedef struct dnode_t
{
    int data;
    struct dnode_t *next, *prev;
} DListNode;

typedef struct deque_t
{
    DListNode *_head, *_tail;
    unsigned _size;
} Deque;

typedef struct bstnode_t
{
    int key;
    struct bstnode_t *left, *right;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
    unsigned int _size;
} BST;

// Deque
void deq_init(Deque *deque)
{
    deque->_head = deque->_tail = NULL;
    deque->_size = (unsigned)0;
}

void bst_init(BST *bst)
{
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst)
{
    return bst->_root == NULL;
}
bool deq_isEmpty(Deque *deque)
{
    return (deque->_head == NULL &&
            deque->_tail == NULL);
}

int deq_front(Deque *deque)
{
    if (!deq_isEmpty(deque))
    {
        return (deque->_head->data);
    }
    return 0;
}

void deq_pushBack(Deque *deque, int value)
{
    DListNode *newNode = (DListNode *)malloc(sizeof(DListNode));
    if (newNode)
    {
        newNode->data = value;
        newNode->next = NULL;
        deque->_size++;
        if (deq_isEmpty(deque))
        {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        deque->_tail->next = newNode;
        newNode->prev = deque->_tail;
        deque->_tail = newNode;
    }
}

void deq_popFront(Deque *deque)
{
    if (!deq_isEmpty(deque))
    {
        DListNode *temp = deque->_head;
        if (deque->_head == deque->_tail)
        {
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else
        {
            deque->_head = deque->_head->next;
            deque->_head->prev = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

void deq_popBack(Deque *deque)
{
    if (!deq_isEmpty(deque))
    {
        DListNode *temp;
        if (deque->_head == deque->_tail)
        {
            temp = deque->_head;
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else
        {
            temp = deque->_tail;
            deque->_tail = deque->_tail->prev;
            deque->_tail->next = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

BSTNode *__search(BSTNode *root, int value)
{
    while (root != NULL)
    {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

bool bst_find(BST *bst, int value)
{
    BSTNode *temp = __search(bst->_root, value);
    if (temp == NULL)
        return false;

    if (temp->key == value)
        return true;
    else
        return false;
}

BSTNode *createNode(int value)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode *insert(BSTNode *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->key)
        root->left = insert(root->left, value);
    else if (value > root->key)
        root->right = insert(root->right, value);

    return root;
}

void bst_insert(BST *bst, int value)
{
    if (!bst_find(bst, value))
    {
        bst->_root = insert(bst->_root, value);
        bst->_size++;
    }
}

bool findPath(BSTNode *root, Deque *deque, int k)
{
    if (root == NULL)
    {
        return false;
    }

    deq_pushBack(deque, root->key);

    if (root->key == k)
    {
        return true;
    }

    if ((root->left && findPath(root->left, deque, k)) ||
        (root->right && findPath(root->right, deque, k)))
        return true;

    deq_popBack(deque);
    return false;
}

int LCA(BST *bst, int n1, int n2)
{
    Deque s1, s2;
    deq_init(&s1);
    deq_init(&s2);

    if (!findPath(bst->_root, &s1, n1) || !findPath(bst->_root, &s2, n2))
    {
        return 0;
    }

    while (!deq_isEmpty(&s1))
    {
        if (deq_front(&s1) == deq_front(&s2))
        {
            hasil = deq_front(&s1);
            deq_popFront(&s1);
            deq_popFront(&s2);
        }
        else
        {
            break;
        }
    }
    return hasil;
}

int main()
{
    BST bst;
    bst_init(&bst);

    int n;
    int data1, data2;
    int a;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);

        if (a == 1)
        {
            int b;
            scanf("%d", &b);
            bst_insert(&bst, b);
        }
        else if (a == 2)
        {
            scanf("%d %d", &data1, &data2);
            if (!LCA(&bst, data1, data2))
            {
                printf("Data tidak valid.\n");
            }
            else
            {
                printf("%d\n", hasil);
            }
        }
        else
        {
            printf("Input tidak valid.\n");
        }
    }
}
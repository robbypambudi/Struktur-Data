#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int min[1024], max[1024];
int height = 0;

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

void bst_init(BST *bst)
{
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst)
{
    return bst->_root == NULL;
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

void findMinimumMax(BSTNode *root, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (root->key < min[level])
    {
        min[level] = root->key;
    }
    if (root->key > max[level])
    {
        max[level] = root->key;
    }

    if (height < level)
    {
        height = level;
    }

    findMinimumMax(root->left, level + 1);
    findMinimumMax(root->right, level + 1);
}

void bst_findminmax(BST *bst)
{
    findMinimumMax(bst->_root, 0);
}

int main()
{
    BST bst;
    bst_init(&bst);

    memset(min, 10000, sizeof(min));
    memset(max, 0, sizeof(max));

    int n;
    scanf("%d", &n);

    int a;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        bst_insert(&bst, a);
    }

    bst_findminmax(&bst);

    int temp = 1;
    for (int i = height; i >= 0; i--)
    {
        if (temp)
        {
            printf("%d ", min[i]);
        }
        else
        {
            printf("%d ", max[i]);
        }
        temp = !temp;
    }
}
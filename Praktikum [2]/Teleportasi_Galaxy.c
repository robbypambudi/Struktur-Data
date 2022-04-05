#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t
{
    int key;
    struct bstnode_t
        *left,
        *right;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode *__bst__createNode(int value)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode *__bst__insert(BSTNode *root, int value)
{
    if (root == NULL)
        return __bst__createNode(value);

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);

    return root;
}

BSTNode *__bst__search(BSTNode *root, int value)
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

BSTNode *__bst__findMinNode(BSTNode *node)
{
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;

    return currNode;
}

BSTNode *__bst__remove(BSTNode *root, int value)
{
    if (root == NULL)
        return NULL;

    if (value > root->key)
        root->right = __bst__remove(root->right, value);
    else if (value < root->key)
        root->left = __bst__remove(root->left, value);
    else
    {

        if (root->left == NULL)
        {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL)
        {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }

        BSTNode *temp = __bst__findMinNode(root->right);
        root->key = temp->key;
        root->right = __bst__remove(root->right, temp->key);
    }
    return root;
}

void __bst__inorder(BSTNode *root)
{
    if (root)
    {
        __bst__inorder(root->left);
        printf("%d ", root->key);
        __bst__inorder(root->right);
    }
}

void __bst__postorder(BSTNode *root)
{
    if (root)
    {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        printf("%d ", root->key);
    }
}

void __bst__preorder(BSTNode *root)
{
    if (root)
    {
        printf("%d ", root->key);
        __bst__preorder(root->left);
        __bst__preorder(root->right);
    }
}

/**
 * PRIMARY FUNCTION
 * ---------------------------
 * Accessible and safe to use.
 */

void bst_init(BST *bst)
{
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst)
{
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value)
{
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;

    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value)
{
    if (!bst_find(bst, value))
    {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

void bst_remove(BST *bst, int value)
{
    if (bst_find(bst, value))
    {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}
int findLevel(BSTNode *root, int value, int level)
{
    if (root == NULL)
        return 0;

    if (root->key == value)
        return level;

    int l = findLevel(root->left, value, level + 1);
    if (l != 0)
        return l;

    return findLevel(root->right, value, level + 1);
}
int bst_findLevel(BST *bst, int value)
{
    return findLevel(bst->_root, value, 0);
}

int main()
{
    int n;
    BST bst;
    int value;
    bst_init(&bst);
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        bst_insert(&bst, value);
    }

    scanf("%d", &n);
    int data1, data2;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &data1, &data2);
        if (bst_find(&bst, data1) && bst_find(&bst, data2))
        {
            int level1 = bst_findLevel(&bst, data1);
            int level2 = bst_findLevel(&bst, data2);
            if (level1 == level2)
            {
                printf("Galaxy berada pada tingkat yang sama\n");
                continue;
            }
            int selesih = abs(level1 - level2);
            printf("%d\n", selesih);
        }
        else
            continue;
    }
}

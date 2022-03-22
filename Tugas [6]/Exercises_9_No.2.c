/*
Each node of a binary tree has fields left, right, key, and parent.

Write a function to return the in-order successor of any given node x. hint: if the right
subtree of node x is empty and x has a successor y, then y is the lowest ancestor of x, which
contains x in its left subtree.

Write a function to return the pre-order successor of any given node x.

Write a function to return the post-order successor of any given node x.

using these functions, write functions to perform the in-order, pre-order, and post-order
traversals of a given binary tree
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct bstnode_t
{
    int key;
    struct bstnode_t *left, *right, *parent;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
    unsigned int _size;

} BST;

// Primary Function

/***********************************************
 *
 * Utility Functions
 *
 * ********************************************/

BSTNode *__bst_createNode(int value)
{
    BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
    node->key = value;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

BSTNode *__bst_insert(BSTNode *root, int key)
{
    if (root == NULL)
    {
        root = __bst_createNode(key);
        return root;
    }
    if (key < root->key)
    {
        root->left = __bst_insert(root->left, key);
        root->left->parent = root;
    }
    else if (key > root->key)
    {
        root->right = __bst_insert(root->right, key);
        root->right->parent = root;
    }
    return root;
}
BSTNode *__bst_search(BSTNode *root, int key)
{
    while (root != NULL)
    {
        if (key < root->key)
            root = root->left;
        else if (key > root->key)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

/* ********************************************
 * Primary Function
 * ********************************************/

void bst_init(BST *bst)
{
    bst->_root = NULL;
    bst->_size = 0;
}

bool bst_find(BST *bst, int key)
{
    BSTNode *temp = __bst_search(bst->_root, key);
    if (temp == NULL)
        return false;
    else if (temp->key == key)
        return true;
    else
        return false;
}

bool bst_empty(BST *bst)
{
    return bst->_root == NULL;
}

void bst_insert(BST *bst, int key)
{
    if (!bst_find(bst, key))
    {
        bst->_root = __bst_insert(bst->_root, key);
        bst->_size++;
    }
}
/**
 *
 * Tranversal
 *
 */
void bst_inOrder(BSTNode *root)
{
    if (root == NULL)
    {
        return;
    }
    bst_inOrder(root->left);
    printf("%d ", root->key);
    bst_inOrder(root->right);
}
void bst_postOrder(BSTNode *root)
{
    if (root == NULL)
    {
        return;
    }
    bst_postOrder(root->left);
    bst_postOrder(root->right);
    printf("%d ", root->key);
}
void bst_preOrder(BSTNode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->key);
    bst_preOrder(root->left);
    bst_preOrder(root->right);
}

void bst_print(BST *bst)
{
    BSTNode *node = bst->_root;
    if (node == NULL)
    {
        printf("Empty Tree\n");
        return;
    }
    printf("Inorder Traversal: ");
    bst_inOrder(node);
    printf("\n");
    printf("Preorder Traversal: ");
    bst_preOrder(node);
    printf("\n");
    printf("Postorder Traversal: ");
    bst_postOrder(node);
    printf("\n");
}

int main()
{
    BST set;
    bst_init(&set);

    printf("Masukan Banyak data : ");
    int N;
    scanf("%d", &N);
    printf("Masukan Data :");
    while (N--)
    {
        int data;
        scanf("%d", &data);
        bst_insert(&set, data);
    }

    bst_print(&set);
}

/*
1 3 6 7 8 12
6 1 3 8 7 12
3 1 7 12 8 6
*/
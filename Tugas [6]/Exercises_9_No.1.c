/*
a binary tree consists of an integer key field and pointers to the left subtree, right subtree, and
parent. Write the declarations required for building a tree and code to create an empty tree.
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
void bst_init(BST *bst)
{
    bst->_root = NULL;
    bst->_size = 0;
}

bool bst_empty(BST *bst)
{
    return bst->_root == NULL;
}
// Recursife Function to insert a node

int main()
{
    BST set;
    bst_init(&set);
}
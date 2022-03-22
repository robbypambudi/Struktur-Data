// Robby Ulung Pambudi
// 5025211042
// 22 Maret 2022

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

// Struct untuk binray tree node
typedef struct bstnode_t
{
    int key;                                 // tempat menyimpan nilai key
    struct bstnode_t *left, *right, *parent; // tempat menyimpan alamat left, right, dan parent
} BSTNode;

// tempat menyimpan alamat root
typedef struct bst_t
{
    BSTNode *_root;     // tempat menyimpan alamat root
    unsigned int _size; // tempat menyimpan ukuran
} BST;

// Prototipe fungsi
BSTNode *__bst_createNode(int value);
BSTNode *__bst_insert(BSTNode *root, int key);
BSTNode *__bst_search(BSTNode *root, int key);
void bst_init(BST *bst);
bool bst_find(BST *bst, int key);
bool bst_empty(BST *bst);
void bst_insert(BST *bst, int key);
void bst_inOrder(BSTNode *root);
void bst_postOrder(BSTNode *root);
void bst_preOrder(BSTNode *root);
void bst_print(BST *bst);

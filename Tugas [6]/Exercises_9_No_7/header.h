// Robby Ulung Pambudi
// 5025211042
// 22 Maret 2022

/*
Write a function that, given the root of a binary search tree, deletes the smallest node and
returns a pointer to the root of the reconstructed tree.
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
BSTNode *__bst_findMinNode(BSTNode *node);
BSTNode *__bst_findMaxNode(BSTNode *node);
BSTNode *__bst_remove(BSTNode *root, int key);
int __bst_width(BSTNode *node, int level);
void bst_init(BST *bst);
bool bst_find(BST *bst, int key);
bool bst_empty(BST *bst);
void bst_insert(BST *bst, int key);
void bst_inOrder(BSTNode *root);
void bst_postOrder(BSTNode *root);
void bst_preOrder(BSTNode *root);
void bst_print(BST *bst);
void bst_delMinNode(BST *bst);
void bst_remove(BST *bst, int key);
void bst_delMaxNode(BST *bst);
void bst_delRoot(BST *bst);
int bst_width(BST *bst);
int height(BSTNode *node);

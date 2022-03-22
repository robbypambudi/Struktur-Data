// Robby Ulung Pambudi
// 5025211042
// Created on : 22/03/2022

/*
a binary tree consists of an integer key field and pointers to the left subtree, right subtree, and
parent. Write the declarations required for building a tree and code to create an empty tree.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct bstnode_t
{
    int key;                                 // Integer untuk menyimpan nilai key
    struct bstnode_t *left, *right, *parent; // Pointer untuk menyimpan alamat node kiri, node kanan, dan node parent
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;     // Pointer untuk menyimpan alamat root
    unsigned int _size; // Integer untuk menyimpan ukuran tree

} BST;

bool bst_empty(BST *bst); // Prototype function
void bst_init(BST *bst);  // Prototype function

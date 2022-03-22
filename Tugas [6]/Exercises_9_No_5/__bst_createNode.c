#include "header.h"

// fungsi untuk membuat node baru
BSTNode *__bst_createNode(int value)
{
    // Inisialisaasi node baru
    BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
    node->key = value;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;

    // Mengembalikan node baru
    return node;
}
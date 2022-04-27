#include "header.h"

// Fungsi untuk memasukan node baru
BSTNode *__bst_insert(BSTNode *root, int key)
{
    if (root == NULL)
    { // Base Case
        root = __bst_createNode(key);
        return root;
    }
    if (key < root->key)
    {                                               // Jika key lebih kecil dari root
        root->left = __bst_insert(root->left, key); // Masukkan ke kiri
        root->left->parent = root;                  // Set parent
    }
    else if (key > root->key)
    {
        // Jika key lebih besar dari root
        root->right = __bst_insert(root->right, key); // Masukkan ke kanan
        root->right->parent = root;                   // Set parent
    }
    return root; // Mengembalikan root
}
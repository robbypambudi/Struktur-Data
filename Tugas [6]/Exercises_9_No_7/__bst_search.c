#include "header.h"

// Fungsi untuk mencari node dengan key tertentu
BSTNode *__bst_search(BSTNode *root, int key)
{
    while (root != NULL)
    {                             // Perulangan selama root tidak NULL
        if (key < root->key)      // Jika key lebih kecil dari root
            root = root->left;    // Cari di kiri
        else if (key > root->key) // Jika key lebih besar dari root
            root = root->right;   // Cari di kanan
        else                      // Jika key sama dengan root
            return root;          // Kembalikan root
    }
    return NULL; // Kembalikan NULL
}

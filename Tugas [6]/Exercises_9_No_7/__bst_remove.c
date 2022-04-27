#include "header.h"

// Utillity Function utnuk menghapus node
BSTNode *__bst_remove(BSTNode *root, int key)
{

    if (root == NULL) // Jika root kosong
        return NULL;

    if (key > root->key) // Jika key lebih besar dari root
        root->right = __bst_remove(root->right, key);
    else if (key < root->key) // Jika key lebih kecil dari root
        root->left = __bst_remove(root->left, key);
    else
    { // Jika key sama dengan root
        if (root->left == NULL)
        { // Jika root kosong
            BSTNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {                               // Jika root kosong
            BSTNode *temp = root->left; // Set temp = root->left
            free(root);                 // Hapus root
            return temp;                // Kembalikan root
        }
        else
        {                                                       // Jika root tidak kosong
            BSTNode *temp = __bst_findMinNode(root->right);     // Mencari node dengan key terkecil
            root->key = temp->key;                              // Set key root dengan key terkecil
            root->right = __bst_remove(root->right, temp->key); // Menghapus node dengan key terkecil
        }
    }
    return root; // Kembalikan root
}
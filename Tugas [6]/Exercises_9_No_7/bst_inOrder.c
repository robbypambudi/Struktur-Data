#include "header.h"

// Fungsi untuk mencetak node dalam bentuk inorder
void bst_inOrder(BSTNode *root)
{
    if (root == NULL)
    { // Jika root kosong
        return;
    }
    bst_inOrder(root->left);  // Cetak node di kiri
    printf("%d ", root->key); // Cetak node
    bst_inOrder(root->right); // Cetak node di kanan
}
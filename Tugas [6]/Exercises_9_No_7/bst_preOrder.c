#include "header.h"

// Primary function untuk memasukan node baru
void bst_preOrder(BSTNode *root)
{
    if (root == NULL)
    { // Jika root kosong
        return;
    }
    printf("%d ", root->key);  // Cetak node
    bst_preOrder(root->left);  // Cetak node di kiri
    bst_preOrder(root->right); // Cetak node di kanan
}
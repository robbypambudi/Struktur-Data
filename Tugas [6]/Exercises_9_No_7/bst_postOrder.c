#include "header.h"

// fungsi untuk mencetak node secara post Order
void bst_postOrder(BSTNode *root)
{
    if (root == NULL)
    { // Jika root kosong
        return;
    }
    bst_postOrder(root->left);  // Cetak node di kiri
    bst_postOrder(root->right); // Cetak node di kanan
    printf("%d ", root->key);   // Cetak node
}
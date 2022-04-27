#include "header.h"

// Fungsi untuk menghapus node max
void bst_delMaxNode(BST *bst)
{
    BSTNode *temp = __bst_findMaxNode(bst->_root);
    if (temp == NULL)
    { // Jika tidak ada node yang bisa dihapus
        printf("Tree is empty\n");
    }
    else
    { // Jika ada node yang bisa dihapus
        printf("Maximum node is %d\n", temp->key);
        bst_remove(bst, temp->key); // Hapus node
    }
}
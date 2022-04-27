#include "header.h"

void bst_delRoot(BST *bst)
{ // Fungsi untuk menghapus node root
    if (bst->_root == NULL)
    { // Jika tidak ada node root
        printf("Tree is empty\n");
    }
    else
    { // Jika ada node root
        printf("Root node is %d\n", bst->_root->key);
        bst_remove(bst, bst->_root->key);
    }
}
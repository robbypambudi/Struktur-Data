
// Fungsi untuk menghapus node min
#include "header.h"

void bst_delMinNode(BST *bst)
{
    BSTNode *temp = __bst_findMinNode(bst->_root);
    if (temp == NULL)
    {
        printf("Tree is empty\n");
    }
    else
    {
        printf("Minimum node is %d\n", temp->key);
        bst_remove(bst, temp->key);
    }
}
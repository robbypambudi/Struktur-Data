#include "header.h"

// Fungsi untuk menghapus node
void bst_remove(BST *bst, int key)
{
    if (bst_find(bst, key))
    { // Jika ditemukan key yang sama
        bst->_root = __bst_remove(bst->_root, key);
        bst->_size--;
    }
}
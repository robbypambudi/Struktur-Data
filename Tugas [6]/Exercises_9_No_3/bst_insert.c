#include "header.h"

// Primary function untuk memasukan node baru
void bst_insert(BST *bst, int key)
{
    if (!bst_find(bst, key))
    { // Jika tidak ditemukan key yang sama
        bst->_root = __bst_insert(bst->_root, key);
        bst->_size++;
    }
}
#include "header.h"

// Primary function untuk mencari
bool bst_find(BST *bst, int key)
{
    BSTNode *temp = __bst_search(bst->_root, key); // Mencari node dengan key tertentu
    if (temp == NULL)                              // Jika tidak ditemukan
        return false;                              // Kembalikan false
    else if (temp->key == key)                     // Jika ditemukan
        return true;                               // Kembalikan true
    else                                           // Jika tidak ditemukan
        return false;                              // Kembalikan false
}
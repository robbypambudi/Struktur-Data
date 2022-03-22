#include "header.h"

// Fungsi untuk mengecek apakah BST kosong atau tidak
bool bst_empty(BST *bst)
{                              // Fungsi untuk mengecek apakah BST kosong atau tidak
    return bst->_root == NULL; // Jika root kosong maka return true
}
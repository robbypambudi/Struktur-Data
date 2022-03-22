#include "header.h"

// Utility Fungsi untuk mencari node terbesar
BSTNode *__bst_findMaxNode(BSTNode *node)
{
    BSTNode *currNode = node; // Inisialisasi node saat ini
    while (currNode && currNode->right != NULL)
        currNode = currNode->right; // Perulangan selama node saat ini dan node kanan tidak NULL

    return currNode; // Kembalikan node terbesar
}
#include "header.h"

// Primary function untuk memasukan node baru
BSTNode *__bst_findMinNode(BSTNode *node)
{
    BSTNode *currNode = node; // Inisialisasi node
    while (currNode && currNode->left != NULL)
        currNode = currNode->left; // Perulangan sampai node kosong atau node kiri

    return currNode; //
}
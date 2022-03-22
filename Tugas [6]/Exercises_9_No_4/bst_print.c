#include "header.h"

void bst_print(BST *bst)
{                               // Primary function untuk mencetak node
    BSTNode *node = bst->_root; // Inisialisasi node
    if (node == NULL)
    { // Jika root kosong
        printf("Empty Tree\n");
        return;
    }
    // Inisialisasi stack
    printf("Inorder Traversal: ");
    bst_inOrder(node); // Cetak node dalam bentuk inorder
    printf("\n");
    printf("Preorder Traversal: ");
    bst_preOrder(node); // Cetak node dalam bentuk preorder
    printf("\n");
    printf("Postorder Traversal: ");
    bst_postOrder(node); // Cetak node dalam bentuk postorder
    printf("\n");
}
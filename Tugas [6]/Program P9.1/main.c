
#include "header.h"

int main()
{
    TreeNodePtr buildTree(FILE *);

    void preOrder(TreeNodePtr);
    void inOrder(TreeNodePtr);
    void postOrder(TreeNodePtr);

    FILE *in = fopen("btree.in", "r");
    BinaryTree bt;
    bt.root = buildTree(in);
    printf("\nThe pre-order traversal is: ");
    preOrder(bt.root);
    printf("\n\nThe in-order traversal is: ");
    inOrder(bt.root);
    printf("\n\nThe post-order traversal is: ");
    postOrder(bt.root);
    printf("\n\n");
    fclose(in);
} // end main
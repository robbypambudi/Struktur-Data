#include "header.h"

void inOrder(TreeNodePtr node)
{
    void visit(TreeNodePtr);
    if (node != NULL)
    {
        inOrder(node->left);
        visit(node);
        inOrder(node->right);
    }
} // end inOrder
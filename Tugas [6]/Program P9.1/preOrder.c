#include "header.h"

void preOrder(TreeNodePtr node)
{
    void visit(TreeNodePtr);
    if (node != NULL)
    {
        visit(node);
        preOrder(node->left);
        preOrder(node->right);
    }
} // end preOrder
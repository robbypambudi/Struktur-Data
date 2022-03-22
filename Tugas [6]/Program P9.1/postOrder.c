#include "header.h"

void postOrder(TreeNodePtr node)
{
    void visit(TreeNodePtr);
    if (node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        visit(node);
    }
} // end postOrder
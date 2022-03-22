#include "header.h"

TreeNodePtr newTreeNode(NodeData d)
{
    TreeNodePtr p = (TreeNodePtr)malloc(sizeof(TreeNode));
    p->data = d;
    p->left = p->right = NULL;
    return p;
} // end newTreeNode
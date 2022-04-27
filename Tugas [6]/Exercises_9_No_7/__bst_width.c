#include "header.h"

int __bst_width(BSTNode *node, int level)
{
    if (node == NULL)
        return 0;
    if (level == 1)
        return 1;
    return __bst_width(node->left, level - 1) + __bst_width(node->right, level - 1);
}
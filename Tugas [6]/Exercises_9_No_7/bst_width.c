#include "header.h"
int bst_width(BST *bst)
{
    int maxWidth = 0;
    int width = 0;
    int h = height(bst->_root);
    for (int i = 1; i <= h; i++)
    {
        width = __bst_width(bst->_root, i);
        if (width > maxWidth)
            maxWidth = width;
    }
    return maxWidth;
}
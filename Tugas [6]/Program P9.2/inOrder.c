#include "header.h"

void inOrder(FILE *out, TreeNodePtr node)
{
    if (node != NULL)
    {
        inOrder(out, node->left);
        fprintf(out, "%-15s %2d\n", node->data.word, node->data.freq);
        inOrder(out, node->right);
    }
} // end inOrder
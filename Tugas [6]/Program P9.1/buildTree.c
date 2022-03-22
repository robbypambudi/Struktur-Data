#include "header.h"

TreeNodePtr buildTree(FILE *in)
{
    char str[MaxWordSize + 1];
    fscanf(in, "%s", str);
    if (strcmp(str, "@") == 0)
        return NULL;
    TreeNodePtr p = (TreeNodePtr)malloc(sizeof(TreeNode));
    strcpy(p->data.word, str);
    p->left = buildTree(in);
    p->right = buildTree(in);
    return p;
} // end buildTree
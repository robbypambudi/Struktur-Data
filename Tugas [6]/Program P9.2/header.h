#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MaxWordSize 20

typedef struct
{
    char word[MaxWordSize + 1];
    int freq;
} NodeData;
typedef struct treeNode
{
    NodeData data;
    struct treeNode *left, *right;
} TreeNode, *TreeNodePtr;
typedef struct
{
    TreeNodePtr root;
} BinaryTree;
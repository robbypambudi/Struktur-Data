// Robby Ulung Pambudi
// NRP 5025211042
// 22 Maret 2022

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxWordSize 20 // maksimum panjang kata

typedef struct
{
    char word[MaxWordSize + 1]; // tempat menyimpan kata
} NodeData;

typedef struct treeNode
{
    NodeData data;                 // tempat menyimpan data
    struct treeNode *left, *right; // tempat menyimpan alamat left, right
} TreeNode, *TreeNodePtr;

typedef struct
{
    TreeNodePtr root; // tempat menyimpan alamat root
} BinaryTree;

// Prototipe fungsi
TreeNodePtr buildTree(FILE *in);
void inOrder(TreeNodePtr node);
void postOrder(TreeNodePtr node);
void visit(TreeNodePtr node);

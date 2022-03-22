#include "header.h"

int main()
{
    int getWord(FILE *, char[]);
    TreeNodePtr newTreeNode(NodeData);
    NodeData newNodeData(char[], int);
    TreeNodePtr findOrInsert(BinaryTree, NodeData);
    void inOrder(FILE *, TreeNodePtr);
    char word[MaxWordSize + 1];
    FILE *in = fopen("wordFreq.in", "r");
    FILE *out = fopen("wordFreq.out", "w");
    BinaryTree bst;
    bst.root = NULL;
    while (getWord(in, word) != 0)
    {
        if (bst.root == NULL)
            bst.root = newTreeNode(newNodeData(word, 1));
        else
        {
            TreeNodePtr node = findOrInsert(bst, newNodeData(word, 0));
            node->data.freq++;
        }
    }
    fprintf(out, "\nWords Frequency\n\n");
    inOrder(out, bst.root);
    fprintf(out, "\n\n");
    fclose(in);
    fclose(out);
} // end main
#include "header.h"

TreeNodePtr findOrInsert(BinaryTree bt, NodeData d)
{
    // searches for d; if found, return pointer to node containing d
    // else insert a node containing d and return pointer to new node
    TreeNodePtr newTreeNode(NodeData);
    if (bt.root == NULL)
        return newTreeNode(d);
    TreeNodePtr curr = bt.root;
    int cmp;
    while ((cmp = strcmp(d.word, curr->data.word)) != 0)
    {
        if (cmp < 0)
        { // try left
            if (curr->left == NULL)
                return curr->left = newTreeNode(d);
            curr = curr->left;
        }
        else
        { // try right
            if (curr->right == NULL)
                return curr->right = newTreeNode(d);
            curr = curr->right;
        }
    }
    // d is in the tree; return pointer to the node
    return curr;
} // end findOrInserts
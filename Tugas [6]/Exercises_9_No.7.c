/*
Write a function that, given the root of a binary search tree, deletes the smallest node and
returns a pointer to the root of the reconstructed tree.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct bstnode_t
{
    int key;
    struct bstnode_t *left, *right, *parent;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
    unsigned int _size;

} BST;

/***********************************************
 *
 * Utility Functions
 *
 * ********************************************/

BSTNode *__bst_createNode(int value)
{
    BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
    node->key = value;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

BSTNode *__bst_insert(BSTNode *root, int key)
{
    if (root == NULL)
    {
        root = __bst_createNode(key);
        return root;
    }
    if (key < root->key)
    {
        root->left = __bst_insert(root->left, key);
        root->left->parent = root;
    }
    else if (key > root->key)
    {
        root->right = __bst_insert(root->right, key);
        root->right->parent = root;
    }
    return root;
}
BSTNode *__bst_search(BSTNode *root, int key)
{
    while (root != NULL)
    {
        if (key < root->key)
            root = root->left;
        else if (key > root->key)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

BSTNode *__bst_findMinNode(BSTNode *node)
{
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;

    return currNode;
}
BSTNode *__bst_remove(BSTNode *root, int key)
{
    if (root == NULL)
        return NULL;

    if (key > root->key)
        root->right = __bst_remove(root->right, key);
    else if (key < root->key)
        root->left = __bst_remove(root->left, key);
    else
    {
        if (root->left == NULL)
        {
            BSTNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            BSTNode *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            BSTNode *temp = __bst_findMinNode(root->right);
            root->key = temp->key;
            root->right = __bst_remove(root->right, temp->key);
        }
    }
    return root;
}
BSTNode *__bst_findMaxNode(BSTNode *node)
{
    BSTNode *currNode = node;
    while (currNode && currNode->right != NULL)
        currNode = currNode->right;

    return currNode;
}
/* ********************************************
 * Primary Function
 * ********************************************/

void bst_init(BST *bst)
{
    bst->_root = NULL;
    bst->_size = 0;
}

bool bst_find(BST *bst, int key)
{
    BSTNode *temp = __bst_search(bst->_root, key);
    if (temp == NULL)
        return false;
    else if (temp->key == key)
        return true;
    else
        return false;
}

bool bst_empty(BST *bst)
{
    return bst->_root == NULL;
}

void bst_insert(BST *bst, int key)

{
    if (!bst_find(bst, key))
    {
        bst->_root = __bst_insert(bst->_root, key);
        bst->_size++;
    }
}

void bst_remove(BST *bst, int key)
{
    if (bst_find(bst, key))
    {
        bst->_root = __bst_remove(bst->_root, key);
        bst->_size--;
    }
}

void bst_findMinNode(BST *bst)
{
    BSTNode *temp = __bst_findMinNode(bst->_root);
    if (temp == NULL)
    {
        printf("Tree is empty\n");
    }
    else
    {
        printf("Minimum node is %d\n", temp->key);
    }
}

void bst_delMinNode(BST *bst)
{
    BSTNode *temp = __bst_findMinNode(bst->_root);
    if (temp == NULL)
    {
        printf("Tree is empty\n");
    }
    else
    {
        printf("Minimum node is %d\n", temp->key);
        bst_remove(bst, temp->key);
    }
}
void bst_delMaxNode(BST *bst)
{
    BSTNode *temp = __bst_findMaxNode(bst->_root);
    if (temp == NULL)
    {
        printf("Tree is empty\n");
    }
    else
    {
        printf("Maximum node is %d\n", temp->key);
        bst_remove(bst, temp->key);
    }
}
void bst_delRoot(BST *bst)
{
    if (bst->_root == NULL)
    {
        printf("Tree is empty\n");
    }
    else
    {
        printf("Root node is %d\n", bst->_root->key);
        bst_remove(bst, bst->_root->key);
    }
}
// Create Function to print Maximum number of nodes at any level
void bst_maxLevel(BST *bst)
{
    int maxLevel = 0;
    int level = 0;
    int count = 0;
    BSTNode *temp = bst->_root;
    while (temp != NULL)
    {
        if (temp->left != NULL)
        {
            temp = temp->left;
            level++;
        }
        else if (temp->right != NULL)
        {
            temp = temp->right;
            level++;
        }
        else
        {
            if (level > maxLevel)
                maxLevel = level;
            level = 0;
            temp = bst->_root;
        }
        printf("Maximum number of nodes at any level is %d\n", maxLevel);
    }
}

void bst_width(BST *bst)
{
    if (bst->_root == NULL)
    {
        printf("Tree is empty\n");
    }
    else
    {
        int height = 0;
        int width = 0;
        int maxWidth = 0;
        BSTNode *temp = bst->_root;
        BSTNode *currNode = bst->_root;
        BSTNode *prevNode = bst->_root;
        BSTNode *nextNode = bst->_root;
        while (temp != NULL)
        {
            height++;
            temp = temp->left;
        }
        for (int i = 0; i < height; i++)
        {
            currNode = bst->_root;
            prevNode = bst->_root;
            nextNode = bst->_root;
            while (currNode != NULL)
            {
                if (i == 0)
                {
                    nextNode = currNode->right;
                    width++;
                }
                else
                {
                    nextNode = currNode->left;
                    width++;
                }
                if (nextNode != NULL)
                {
                    prevNode = currNode;
                    currNode = nextNode;
                }
                else
                {
                    if (i == 0)
                    {
                        currNode = currNode->right;
                        width++;
                    }
                    else
                    {
                        currNode = currNode->left;
                        width++;
                    }
                }
            }
            if (width > maxWidth)
                maxWidth = width;
            width = 0;
        }
        printf("Maximum width of the tree is %d\n", maxWidth);
        bst_maxLevel(bst);
    }
}

/**
 * Tranversal
 */
void bst_inOrder(BSTNode *root)
{
    if (root == NULL)
    {
        return;
    }
    bst_inOrder(root->left);
    printf("%d ", root->key);
    bst_inOrder(root->right);
}
void bst_postOrder(BSTNode *root)
{
    if (root == NULL)
    {
        return;
    }
    bst_postOrder(root->left);
    bst_postOrder(root->right);
    printf("%d ", root->key);
}
void bst_preOrder(BSTNode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->key);
    bst_preOrder(root->left);
    bst_preOrder(root->right);
}

// Optional Functions
void bst_print(BST *bst)
{
    BSTNode *node = bst->_root;
    if (node == NULL)
    {
        printf("Empty Tree\n");
        return;
    }
    printf("Inorder Traversal: ");
    bst_inOrder(node);
    printf("\n");
    printf("Preorder Traversal: ");
    bst_preOrder(node);
    printf("\n");
    printf("Postorder Traversal: ");
    bst_postOrder(node);
    printf("\n");
}

int main()
{
    BST set;
    bst_init(&set);

    bst_insert(&set, 6);
    bst_insert(&set, 1);
    bst_insert(&set, 8);
    bst_insert(&set, 12);
    bst_insert(&set, 1);
    bst_insert(&set, 3);
    bst_insert(&set, 7);
    bst_width(&set);

    // bst_delMinNode(&set);
    // bst_print(&set);
    // bst_delMaxNode(&set);
    // bst_print(&set);
    // bst_delRoot(&set);
    // bst_print(&set);
    // bst_delRoot(&set);
}

/*
1 3 6 7 8 12
6 1 3 8 7 12
3 1 7 12 8 6
*/
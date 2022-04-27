/*
Write a function that, given the root of a binary search tree, deletes the smallest node and
returns a pointer to the root of the reconstructed tree.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
int maxLevel[10000];
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

int __bst_width(BSTNode *node, int level)
{
    if (node == NULL)
        return 0;
    if (level == 1)
        return 1;
    return __bst_width(node->left, level - 1) + __bst_width(node->right, level - 1);
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

int height(BSTNode *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}
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
void __maximumEachLevel(BSTNode *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->key);
    else
    {
        __maximumEachLevel(root->left, level + 1);
        __maximumEachLevel(root->right, level + 1);
    }
}

void maximumEachLevel(BST *bst)
{
    if (bst == NULL)
        return;
    int h = height(bst->_root);
    for (int i = 1; i <= h; i++)
    {
        __maximumEachLevel(bst->_root, i);
    }
}

int main()
{
    BST set;
    bst_init(&set);
    memset(maxLevel, -1, sizeof(maxLevel));
    printf("Masukan Banyak data : "); // Input banyak data
    int N;
    scanf("%d", &N); // Input banyak data
    printf("Masukan Data :");
    while (N--)
    {                           // Input data
        int data;               // Deklarasi variabel data
        scanf("%d", &data);     // Input data
        bst_insert(&set, data); // Input data
    }
    int width = bst_width(&set);
    printf("Width of the tree is %d\n", width);
    maximumEachLevel(&set);
    printf("Maximum each level : ");
    int count = sizeof(maxLevel) / sizeof(maxLevel[0]);
    for (int i = 1; i < count; i++)
    {
        printf("Level %d, Max Number is %d ", i, maxLevel[i]);
        if (maxLevel[i] == -1)
            break;
    }
    // bst_print(&set);
    // puts("----------------------");
    // puts("Deleted Min Node");
    // bst_delMinNode(&set);
    // bst_print(&set);
    // puts("----------------------");
    // puts("Deleted Max Node");
    // bst_delMaxNode(&set);
    // bst_print(&set);
    // puts("----------------------");
    // puts("Deleted Root Node");
    // bst_delRoot(&set);
    // bst_print(&set);
}

/*
1 3 6 7 8 12
6 1 3 8 7 12
3 1 7 12 8 6
*/
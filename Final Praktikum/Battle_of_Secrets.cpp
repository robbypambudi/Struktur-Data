#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Variabel Global
int level;
int maximum_level = 0;
int arr[25];

/**
 * Node structure and
 * uniqueBST structure
 */
typedef struct bstnode_t
{
    int key;
    int level;
    int index;
    struct bstnode_t
        *left,
        *right;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
    unsigned int _size;
} BST;

/**
 * !!! WARNING UTILITY FUNCTION !!!
 * Recognized by prefix "_bst_"
 * ---------------------------------------------
 * Note that you better never access these functions,
 * unless you need to modify or you know how these functions work.
 */

BSTNode *_bst_createNode(int value)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->level = level;
    arr[level]++;
    newNode->index = arr[level];
    newNode->left = newNode->right = NULL;

    if (level > maximum_level)
        maximum_level = level;

    return newNode;
}

BSTNode *_bst_insert(BSTNode *root, int value)
{
    if (root == NULL)
        return _bst_createNode(value);

    if (value < root->key)
    {
        level++;
        root->left = _bst_insert(root->left, value);
    }
    else if (value > root->key)
    {
        level++;
        root->right = _bst_insert(root->right, value);
    }

    return root;
}

BSTNode *_bst_search(BSTNode *root, int value)
{
    while (root != NULL)
    {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

BSTNode *_bst_findMinNode(BSTNode *node)
{
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;

    return currNode;
}

BSTNode *_bst_remove(BSTNode *root, int value)
{
    if (root == NULL)
        return NULL;

    if (value > root->key)
        root->right = _bst_remove(root->right, value);
    else if (value < root->key)
        root->left = _bst_remove(root->left, value);
    else
    {

        if (root->left == NULL)
        {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL)
        {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }

        BSTNode *temp = _bst_findMinNode(root->right);
        root->key = temp->key;
        root->right = _bst_remove(root->right, temp->key);
    }
    return root;
}

bool find = false;

void _bst_inorder(BSTNode *root)
{
    if (root)
    {
        _bst_inorder(root->left);

        if ((root->level != 0 && root->level != 1) && (root->left != 0 || root->right != 0))
        {
            if (root->index != 0 && root->index != arr[root->level])
            {
                printf("%d ", root->key);
                find = true;
            }
        }

        _bst_inorder(root->right);
    }
}

void _bst_postorder(BSTNode *root)
{
    if (root)
    {
        _bst_postorder(root->left);
        _bst_postorder(root->right);
        printf("%d ", root->key);
    }
}

void _bst_preorder(BSTNode *root)
{
    if (root)
    {
        printf("%d ", root->key);
        _bst_preorder(root->left);
        _bst_preorder(root->right);
    }
}

/**
 * PRIMARY FUNCTION
 * ---------------------------
 * Accessible and safe to use.
 */

void bst_init(BST *bst)
{
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst)
{
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value)
{
    BSTNode *temp = _bst_search(bst->_root, value);
    if (temp == NULL)
        return false;

    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value)
{
    if (!bst_find(bst, value))
    {
        bst->_root = _bst_insert(bst->_root, value);
        bst->_size++;
    }
}

void bst_remove(BST *bst, int value)
{
    if (bst_find(bst, value))
    {
        bst->_root = _bst_remove(bst->_root, value);
        bst->_size--;
    }
}

/**
 * Binary search tree traversal
 * - Inorder
 * - Postorder
 * - Preorder
 */

void bst_inorder(BST *bst)
{
    _bst_inorder(bst->_root);
}

void bst_postorder(BST *bst)
{
    _bst_postorder(bst->_root);
}

void bst_preorder(BST *bst)
{
    _bst_preorder(bst->_root);
}

int main()
{
    BST set;        // objek BST
    bst_init(&set); // inisialisasi BST

    int N;
    scanf("%d", &N);

    memset(arr, -1, sizeof(arr));
    for (int i = 0; i < N; i++)
    {
        int n;
        scanf("%d", &n);
        level = 0;
        bst_insert(&set, n);
    }

    bst_inorder(&set);

    if (!find)
        printf("It's not safe");

    puts("");

    return 0;
}
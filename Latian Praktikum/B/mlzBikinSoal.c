// Created By Robby Ulung Pambudi
// Disclaimer
// Dont Copy or Share this code

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct AVLNode_t
{
    int data;
    struct AVLNode_t *left, *right;
    int height;
} AVLNode;

typedef struct AVL_t
{
    AVLNode *_root;
    unsigned int _size;
} AVL;

AVLNode *_avl_createNode(int value)
{
    AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

AVLNode *_search(AVLNode *root, int value)
{
    while (root != NULL)
    {
        if (value < root->data)
            root = root->left;
        else if (value > root->data)
            root = root->right;
        else
            return root;
    }
    return root;
}

int _getHeight(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

int _max(int a, int b)
{
    return (a > b) ? a : b;
}

AVLNode *_rightRotate(AVLNode *pivotNode)
{

    AVLNode *newParrent = pivotNode->left;
    pivotNode->left = newParrent->right;
    newParrent->right = pivotNode;

    pivotNode->height = _max(_getHeight(pivotNode->left),
                             _getHeight(pivotNode->right)) +
                        1;
    newParrent->height = _max(_getHeight(newParrent->left),
                              _getHeight(newParrent->right)) +
                         1;

    return newParrent;
}

AVLNode *_leftRotate(AVLNode *pivotNode)
{

    AVLNode *newParrent = pivotNode->right;
    pivotNode->right = newParrent->left;
    newParrent->left = pivotNode;

    pivotNode->height = _max(_getHeight(pivotNode->left),
                             _getHeight(pivotNode->right)) +
                        1;
    newParrent->height = _max(_getHeight(newParrent->left),
                              _getHeight(newParrent->right)) +
                         1;

    return newParrent;
}

AVLNode *_leftCaseRotate(AVLNode *node)
{
    return _rightRotate(node);
}

AVLNode *_rightCaseRotate(AVLNode *node)
{
    return _leftRotate(node);
}

AVLNode *_leftRightCaseRotate(AVLNode *node)
{
    node->left = _leftRotate(node->left);
    return _rightRotate(node);
}

AVLNode *_rightLeftCaseRotate(AVLNode *node)
{
    node->right = _rightRotate(node->right);
    return _leftRotate(node);
}

int _getBalanceFactor(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return _getHeight(node->left) - _getHeight(node->right);
}

AVLNode *_insert_AVL(AVL *avl, AVLNode *node, int value)
{

    if (node == NULL) // udah mencapai leaf
        return _avl_createNode(value);
    if (value < node->data)
        node->left = _insert_AVL(avl, node->left, value);
    else if (value > node->data)
        node->right = _insert_AVL(avl, node->right, value);

    node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right));

    int balanceFactor = _getBalanceFactor(node);

    if (balanceFactor > 1 && value < node->left->data) // skewed kiri (left-left case)
        return _leftCaseRotate(node);
    if (balanceFactor > 1 && value > node->left->data) //
        return _leftRightCaseRotate(node);
    if (balanceFactor < -1 && value > node->right->data)
        return _rightCaseRotate(node);
    if (balanceFactor < -1 && value < node->right->data)
        return _rightLeftCaseRotate(node);

    return node;
}

AVLNode *_findMinNode(AVLNode *node)
{
    AVLNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    return currNode;
}

AVLNode *_remove_AVL(AVLNode *node, int value)
{
    if (node == NULL)
        return node;
    if (value > node->data)
        node->right = _remove_AVL(node->right, value);
    else if (value < node->data)
        node->left = _remove_AVL(node->left, value);
    else
    {
        AVLNode *temp;
        if ((node->left == NULL) || (node->right == NULL))
        {
            temp = NULL;
            if (node->left == NULL)
                temp = node->right;
            else if (node->right == NULL)
                temp = node->left;

            if (temp == NULL)
            {
                temp = node;
                node = NULL;
            }
            else
                *node = *temp;

            free(temp);
        }
        else
        {
            temp = _findMinNode(node->right);
            node->data = temp->data;
            node->right = _remove_AVL(node->right, temp->data);
        }
    }

    if (node == NULL)
        return node;

    node->height = _max(_getHeight(node->left), _getHeight(node->right)) + 1;

    int balanceFactor = _getBalanceFactor(node);

    if (balanceFactor > 1 && _getBalanceFactor(node->left) >= 0)
        return _leftCaseRotate(node);

    if (balanceFactor > 1 && _getBalanceFactor(node->left) < 0)
        return _leftRightCaseRotate(node);

    if (balanceFactor < -1 && _getBalanceFactor(node->right) <= 0)
        return _rightCaseRotate(node);

    if (balanceFactor < -1 && _getBalanceFactor(node->right) > 0)
        return _rightLeftCaseRotate(node);

    return node;
}

void avl_init(AVL *avl)
{
    avl->_root = NULL;
    avl->_size = 0u;
}

bool avl_isEmpty(AVL *avl)
{
    return avl->_root == NULL;
}

bool avl_find(AVL *avl, int value)
{
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL)
        return false;

    if (temp->data == value)
        return true;
    else
        return false;
}

void avl_insert(AVL *avl, int value)
{
    if (!avl_find(avl, value))
    {
        avl->_root = _insert_AVL(avl, avl->_root, value);
        avl->_size++;
    }
}

void avl_remove(AVL *avl, int value)
{
    if (avl_find(avl, value))
    {
        avl->_root = _remove_AVL(avl->_root, value);
        avl->_size--;
    }
}

void preorder(AVLNode *root)
{
    if (root)
    {
        preorder(root->left);
        printf("%d ", root->data);
        preorder(root->right);
    }
}

// MyCode
int avl_findParent(AVLNode *root, int value)
{
    if (root == NULL)
        return 0;
    if (root->data == value)
        return 0;
    if (root->left != NULL && root->left->data == value)
        return root->data;
    if (root->right != NULL && root->right->data == value)
        return root->data;
    if (value < root->data)
        return avl_findParent(root->left, value);
    else
        return avl_findParent(root->right, value);
}

int avl_findSibling(AVLNode *root, int value)
{
    if (root == NULL)
        return 0;
    if (root->data == value)
        return 0;
    if (root->left != NULL && root->left->data == value)
    {
        if (root->right != NULL)
            return root->right->data;
        else
            return 0;
    }
    if (root->right != NULL && root->right->data == value)
    {
        if (root->left != NULL)
            return root->left->data;
        else
            return 0;
    }
    if (value < root->data)
        return avl_findSibling(root->left, value);
    else
        return avl_findSibling(root->right, value);
}

int main()
{
    AVL avlku;
    avl_init(&avlku);
    int N, testcase;
    scanf("%d %d", &N, &testcase);
    for (int i = 0; i < N; i++)
    {
        int value;
        scanf("%d", &value);
        avl_insert(&avlku, value);
    }

    for (int i = 0; i < testcase; i++)
    {
        int value;
        scanf("%d", &value);
        int parent = avl_findParent(avlku._root, value);
        int sibling = avl_findSibling(avlku._root, parent);
        // printf("%d\n", avl_findParent(avlku._root, value));
        // printf("%d\n", avl_findSibling(avlku._root, parent));
        int res = abs(sibling - parent);
        printf("%d\n", res);
    }
}

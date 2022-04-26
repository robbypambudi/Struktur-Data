#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct AVLNode_t
{
    char *data;
    struct AVLNode_t *left;
    struct AVLNode_t *right;
    int height;
} AVLNode;

typedef struct AVL_t
{
    AVLNode *_root;
    unsigned int _size;
} AVL;

void avl_init(AVL *avl)
{
    avl->_root = NULL;
    avl->_size = 0u;
}

int _max(int a, int b)
{
    return (a > b) ? a : b;
}

int _getHeight(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

int _getBalanceFactor(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return _getHeight(node->left) - _getHeight(node->right);
}

AVLNode *_rightRotate(AVLNode *pivotNode)
{
    AVLNode *newParrent = pivotNode->left;
    pivotNode->left = newParrent->right;
    newParrent->right = pivotNode;

    pivotNode->height = _max(_getHeight(pivotNode->left), _getHeight(pivotNode->right)) + 1;
    newParrent->height = _max(_getHeight(newParrent->left), _getHeight(newParrent->right)) + 1;

    return newParrent;
}

AVLNode *_leftRotate(AVLNode *pivotNode)
{
    AVLNode *newParrent = pivotNode->right;
    pivotNode->right = newParrent->left;
    newParrent->left = pivotNode;

    pivotNode->height = _max(_getHeight(pivotNode->left), _getHeight(pivotNode->right)) + 1;
    newParrent->height = _max(_getHeight(newParrent->left), _getHeight(newParrent->right)) + 1;

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

AVLNode *_avl_createNode(char *value)
{
    AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));

    newNode->data = (char *)malloc(20 * sizeof(char));
    memcpy(newNode->data, value, 20 * sizeof(char));
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

AVLNode *_search(AVLNode *root, char *value)
{
    while (root != NULL)
    {
        if (strcmp(value, root->data) < 0)
            root = root->left;
        else if (strcmp(value, root->data) > 0)
            root = root->right;
        else
            return root;
    }
    return root;
}

AVLNode *_insert_AVL(AVL *avl, AVLNode *node, char *value)
{
    if (node == NULL)
        return _avl_createNode(value);
    if (strcmp(value, node->data) < 0)
        node->left = _insert_AVL(avl, node->left, value);
    else if (strcmp(value, node->data) > 0)
        node->right = _insert_AVL(avl, node->right, value);

    node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right));

    int balanceFactor = _getBalanceFactor(node);

    if (balanceFactor > 1 && strcmp(value, node->left->data) < 0)
        return _leftCaseRotate(node);
    if (balanceFactor > 1 && strcmp(value, node->left->data) > 0)
        return _leftRightCaseRotate(node);
    if (balanceFactor < -1 && strcmp(value, node->right->data) > 0)
        return _rightCaseRotate(node);
    if (balanceFactor < -1 && strcmp(value, node->right->data) < 0)
        return _rightLeftCaseRotate(node);

    return node;
}

bool avl_find(AVL *avl, char *value)
{
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL)
        return false;

    if (temp->data == value)
        return true;
    else
        return false;
}

void avl_insert(AVL *avl, char *value)
{
    if (!avl_find(avl, value))
    {
        avl->_root = _insert_AVL(avl, avl->_root, value);
        avl->_size++;
    }
}

void inorder(AVLNode *temp, int *index)
{
    if (temp)
    {
        inorder(temp->left, index);
        printf("%d. %s\n", (*index)++, temp->data);
        inorder(temp->right, index);
    }
}
void inorder2(AVLNode *temp, int *index)
{
    if (temp)
    {
        inorder2(temp->left, index);
        printf("%s", temp->data);
        if ((*index)-- != 1)
            printf("_");
        inorder2(temp->right, index);
    }
}
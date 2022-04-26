// Created By Robby Ulung Pambudi
// Disclaimer
// Dont Copy or Share this code

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct AVLNode_t
{
    int id;
    int harga;
    struct AVLNode_t *left, *right;
    int height;
} AVLNode;

typedef struct AVL_t
{
    AVLNode *_root;
    unsigned int _size;
} AVL;

AVLNode *_avl_createNode(int id, int harga)
{
    AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
    newNode->id = id;
    newNode->harga = harga;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

AVLNode *_search(AVLNode *root, int id)
{
    while (root != NULL)
    {
        if (id < root->id)
            root = root->left;
        else if (id > root->id)
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

AVLNode *_insert_AVL(AVL *avl, AVLNode *node, int id, int harga)
{

    if (node == NULL) // udah mencapai leaf
        return _avl_createNode(id, harga);
    if (id < node->id)
        node->left = _insert_AVL(avl, node->left, id, harga);
    else if (id > node->id)
        node->right = _insert_AVL(avl, node->right, id, harga);

    node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right));

    int balanceFactor = _getBalanceFactor(node);

    if (balanceFactor > 1 && id < node->left->id) // skewed kiri (left-left case)
        return _leftCaseRotate(node);
    if (balanceFactor > 1 && id > node->left->id) //
        return _leftRightCaseRotate(node);
    if (balanceFactor < -1 && id > node->right->id)
        return _rightCaseRotate(node);
    if (balanceFactor < -1 && id < node->right->id)
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

AVLNode *_remove_AVL(AVLNode *node, int id)
{
    if (node == NULL)
        return node;
    if (id > node->id)
        node->right = _remove_AVL(node->right, id);
    else if (id < node->id)
        node->left = _remove_AVL(node->left, id);
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
            node->id = temp->id;
            node->right = _remove_AVL(node->right, temp->id);
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

    if (temp->id == value)
        return true;
    else
        return false;
}

void avl_insert(AVL *avl, int value, int harga)
{
    if (!avl_find(avl, value))
    {
        avl->_root = _insert_AVL(avl, avl->_root, value, harga);
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
        printf("%d %d\n", root->id, root->harga);
        preorder(root->right);
    }
}
// Get Harga
int getHarga(AVLNode *root, int id)
{
    if (root == NULL)
        return 0;
    if (root->id == id)
        return root->harga;
    if (id < root->id)
        return getHarga(root->left, id);
    else
        return getHarga(root->right, id);
}

int main()
{
    AVL avlku;
    avl_init(&avlku);

    int id = 0, harga;
    int prev = 0;
    while (scanf("%d %d", &id, &harga), id != 0 && harga != 0)
    {
        if (prev != 0)
        {
            if (abs(prev - id) != 1)
            {
                printf("ID harus urut\n");
                return 0;
            }
        }
        avl_insert(&avlku, id, harga);
        prev = id;
    }

    int jumlah;
    int result = 0;
    while (scanf("%d %d", &jumlah, &id), id != 0 && jumlah != 0)
    {

        if (avl_find(&avlku, id))
        {
            int harga; // harga
            harga = getHarga(avlku._root, id);
            int temp = harga * jumlah;
            result += temp;
        }
        else
        {
            printf("Maaf barang tidak tersedia\n");
        }
    }
    printf("%d\n", result);
}

// Robby Ulung Pambudi
// Robby Ulung Pambudi

/*
Sample Input
7 3
XAXXDXC3
XBXBXBX2
XABXXXZ2
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct bstnode_t
{
    int key;
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
 * Recognized by prefix "__bst__"
 * ---------------------------------------------
 * Note that you better never access these functions,
 * unless you need to modify or you know how these functions work.
 */

BSTNode *__bst__createNode(int value)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode *__bst__insert(BSTNode *root, int value)
{
    if (root == NULL)
        return __bst__createNode(value);

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);

    return root;
}

BSTNode *__bst__search(BSTNode *root, int value)
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

BSTNode *__bst__findMinNode(BSTNode *node)
{
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;

    return currNode;
}

BSTNode *__bst__remove(BSTNode *root, int value)
{
    if (root == NULL)
        return NULL;

    if (value > root->key)
        root->right = __bst__remove(root->right, value);
    else if (value < root->key)
        root->left = __bst__remove(root->left, value);
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

        BSTNode *temp = __bst__findMinNode(root->right);
        root->key = temp->key;
        root->right = __bst__remove(root->right, temp->key);
    }
    return root;
}

void __bst__inorder(BSTNode *root)
{
    if (root)
    {
        __bst__inorder(root->left);
        printf("%d ", root->key);
        __bst__inorder(root->right);
    }
}

void __bst__postorder(BSTNode *root)
{
    if (root)
    {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        printf("%d ", root->key);
    }
}

void __bst__preorder(BSTNode *root)
{
    if (root)
    {
        printf("%d ", root->key);
        __bst__preorder(root->left);
        __bst__preorder(root->right);
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
    BSTNode *temp = __bst__search(bst->_root, value);
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
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

void bst_remove(BST *bst, int value)
{
    if (bst_find(bst, value))
    {
        bst->_root = __bst__remove(bst->_root, value);
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
    __bst__inorder(bst->_root);
}

void bst_postorder(BST *bst)
{
    __bst__postorder(bst->_root);
}

void bst_preorder(BST *bst)
{
    __bst__preorder(bst->_root);
}

// AVLL

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

// My CODE
int child[100000];

void getEachChildBST(BSTNode *root, int top)
{
    if (root)
    {
        // printf("%d ", top);
        getEachChildBST(root->left, top);
        if (root->key != top)
        {
            // printf("%d ", root->key);
            if (root->left != NULL)
            {
                child[root->key] = root->key;
            }
            if (root->right != NULL)
            {
                child[root->key] = root->key;
            }
        }
        getEachChildBST(root->right, top);
    }
}

void getChildAVL(AVLNode *root)
{
    if (root)
    {
        getChildAVL(root->left);
        if (root->left == NULL && root->right == NULL)
        {
            child[root->data] = root->data;
        }
        getChildAVL(root->right);
    }
}

int main()
{
    AVL avlku;
    BST bstku;
    bst_init(&bstku);
    avl_init(&avlku);
    memset(child, -1, sizeof(child));

    int X, Y;
    scanf("%d %d", &X, &Y);
    X += 2;
    char dat[Y][X];
    for (int i = 0; i < Y; i++)
    {
        for (int j = 0; j < X; j++)
        {
            scanf("%c", &dat[i][j]);
        }
    }

    // Get Data from Character Array
    int data = 0;
    for (int i = 0; i < Y; i++)
    {
        int times = dat[i][X - 1] - '0';
        // printf("%d", times);
        for (int j = 1; j < X - 1; j++)
        {
            if (dat[i][j] == 'X')
                continue;

            data += dat[i][j] - 'A' + 1;

            // data *= times;

            bst_insert(&bstku, data * times);
        }
        data = 0;
    }
    // bst_preorder(&bstku);

    // Get Each Child
    getEachChildBST(bstku._root, bstku._root->key);
    // preorder(avlku._root);

    // PRint CHild
    for (int i = 0; i < 100000; i++)
    {
        if (child[i] != -1)
            avl_insert(&avlku, child[i]);
    }

    // Restart
    memset(child, -1, sizeof(child));
    // Get Child
    getChildAVL(avlku._root);

    // New Arr
    int arr[10000];
    int _i = 0;
    for (int i = 0; i < 100000; i++)
    {
        if (child[i] != -1)
        {
            arr[_i] = child[i];
            _i++;
        }
    }

    if (_i == 0)
    {
        printf("Punten, inputnya kurang :D\n");
        return 0;
    }

    // Cek Genap Ganjil
    int genap = 0;
    int ganjil = 0;
    for (int i = 0; i < _i; i++)
    {
        if (arr[i] % 2 == 0)
            genap = 1;
        else if (arr[i] % 2 == 1)
            ganjil = 1;
    }

    if (genap == 1 && ganjil == 0)
    {
        printf("mantap");
        for (int i = 0; i < _i; i++)
        {
            printf("%d", arr[i]);
        }
        printf(".avl\n");
    }
    else if (genap == 0 && ganjil == 1)
    {
        printf("gokil");
        for (int i = 0; i < _i; i++)
        {
            printf("%d", arr[i]);
        }
        printf(".avl\n");
    }
    else
    {
        printf("goatapkil");
        for (int i = 0; i < _i; i++)
        {
            printf("%d", arr[i]);
        }
        printf(".avl\n");
    }
    return 0;
}
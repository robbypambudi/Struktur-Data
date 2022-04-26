
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#define ll long long int

typedef struct AVLNode_t
{
    ll data;
    struct AVLNode_t *left, *right;
    ll height;
} AVLNode;

typedef struct AVL_t
{
    AVLNode *_root;
    unsigned ll _size;
} AVL;

AVLNode *_avl_createNode(ll value)
{
    AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

AVLNode *_search(AVLNode *root, ll value)
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

ll _getHeight(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

ll _max(ll a, ll b)
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

ll _getBalanceFactor(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return _getHeight(node->left) - _getHeight(node->right);
}

AVLNode *_insert_AVL(AVL *avl, AVLNode *node, ll value)
{

    if (node == NULL) // udah mencapai leaf
        return _avl_createNode(value);
    if (value < node->data)
        node->left = _insert_AVL(avl, node->left, value);
    else if (value > node->data)
        node->right = _insert_AVL(avl, node->right, value);

    node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right));

    ll balanceFactor = _getBalanceFactor(node);

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

AVLNode *_remove_AVL(AVLNode *node, ll value)
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

    ll balanceFactor = _getBalanceFactor(node);

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

bool avl_find(AVL *avl, ll value)
{
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL)
        return false;

    if (temp->data == value)
        return true;
    else
        return false;
}

void avl_insert(AVL *avl, ll value)
{
    if (!avl_find(avl, value))
    {
        avl->_root = _insert_AVL(avl, avl->_root, value);
        avl->_size++;
    }
}

void avl_remove(AVL *avl, ll value)
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
        printf("%lld ", root->data);
        preorder(root->right);
    }
}

// MyCode
void FindPath(AVLNode *cur, AVLNode *temp, ll target, ll sum, bool *isFind, bool isCont)
{
    if (target == sum)
    {
        *isFind = true;
    }
    else if (!isCont)
    {
        if (cur)
        {
            if ((cur->left || cur->right) || (temp->left && temp->right))
            {
                sum += cur->data;

                if (sum == target)
                {
                    *isFind = true;
                    return;
                }

                if (sum > target)
                {
                    return;
                }

                if (!(*isFind))
                    FindPath(cur->left, temp, target, sum, isFind, false);
                if (!(*isFind))
                    FindPath(cur->right, temp, target, sum, isFind, false);

                if (temp->data > cur->data)
                {
                    if (!(*isFind))
                        FindPath(cur, temp->right, target, sum, isFind, true);
                }
                else if (temp->data < cur->data)
                {
                    if (!(*isFind))
                        FindPath(cur, temp->left, target, sum, isFind, true);
                }

                if (!(*isFind))
                    FindPath(cur->left, temp->left, target, 0, isFind, false);
                if (!(*isFind))
                    FindPath(cur->right, temp->right, target, 0, isFind, false);
            }
        }
    }
    else
    {
        if (temp)
        {
            if ((cur->left || cur->right) || (temp->left || temp->right))
            {
                sum += temp->data;

                if (sum == target)
                {
                    *isFind = true;
                    return;
                }
                if (sum > target)
                {
                    return;
                }

                if (temp->left != NULL)
                {
                    if (!(*isFind))
                        FindPath(cur, temp->left, target, sum, isFind, true);
                }
                if (temp->right != NULL)
                {
                    if (!(*isFind))
                        FindPath(cur, temp->right, target, sum, isFind, true);
                }
            }
        }
    }
}

int main()
{
    AVL avlku;
    avl_init(&avlku);

    ll N;
    scanf("%lld", &N);
    ll command, value;

    while (N--)
    {
        scanf("%lld %lld", &command, &value);

        if (command == 1)
        {
            avl_insert(&avlku, value);
        }
        else if (command == 2)
        {
            bool isFind = false;

            if (avlku._size <= 1)
            {
            }
            else if (avl_find(&avlku, value))
            {
                isFind = true;
            }
            else
            {
                FindPath(avlku._root, avlku._root, value, 0, &isFind, false);
            }

            if (!isFind)
                printf("<>\n");
            else
                printf("<3\n");
        }
    }
}

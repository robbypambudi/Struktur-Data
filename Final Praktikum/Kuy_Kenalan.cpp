// From Modul 3

#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode
{
    int data;
    struct AVLNode *left, *right, *parent;
    int height;
    int status;
} AVLNode;
void set_status(AVLNode *root);

AVLNode *init()
{
    return NULL;
}

AVLNode *avl_createNode(AVLNode *parent, int value)
{
    AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    newNode->parent = parent;
    newNode->status = 1;
    // printf("%d\n", newNode->data);
    return newNode;
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

int _getBalanceFactor(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return _getHeight(node->left) - _getHeight(node->right);
}

AVLNode *_rightRotate(AVLNode *pivotNode)
{

    AVLNode *newParrent = pivotNode->left;
    newParrent->parent = pivotNode->parent;
    // printf("%d\n", newParrent->data);
    pivotNode->left = newParrent->right;
    if (newParrent->right)
        newParrent->right->parent = pivotNode;
    newParrent->right = pivotNode;
    pivotNode->parent = newParrent;

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
    newParrent->parent = pivotNode->parent;
    pivotNode->right = newParrent->left;
    // printf("%d\n", pivotNode->right->data);
    if (newParrent->left)
        newParrent->left->parent = pivotNode;
    newParrent->left = pivotNode;
    pivotNode->parent = newParrent;

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
    AVLNode *temp = _leftRotate(node->left);
    node->left = temp;
    temp->parent = node;
    return _rightRotate(node);
}

AVLNode *_rightLeftCaseRotate(AVLNode *node)
{
    AVLNode *temp = _rightRotate(node->right);
    node->right = temp;
    temp->parent = node;
    return _leftRotate(node);
}
//--

AVLNode *_insert_AVL(AVLNode *root, AVLNode *parent, int value)
{
    if (root == NULL)
        return avl_createNode(parent, value);
    if (value < root->data)
        root->left = _insert_AVL(root->left, root, value);
    else if (value > root->data)
        root->right = _insert_AVL(root->right, root, value);
    root->height = 1 + _max(_getHeight(root->left), _getHeight(root->right));
    int balanceFactor = _getBalanceFactor(root);

    if (balanceFactor > 1 && value < root->left->data) // skewed kiri (left-left case)
        return _leftCaseRotate(root);
    if (balanceFactor > 1 && value > root->left->data) //
        return _leftRightCaseRotate(root);
    if (balanceFactor < -1 && value > root->right->data)
        return _rightCaseRotate(root);
    if (balanceFactor < -1 && value < root->right->data)
        return _rightLeftCaseRotate(root);
    // printf("%d\n", root->data);
    return root;
}

AVLNode *avl_find(AVLNode *root, int value)
{
    if (root)
    {
        if (value < root->data)
            return avl_find(root->left, value);
        if (value > root->data)
            return avl_find(root->right, value);
    }
    return root;
}

int count = 0, max_count, max_distance;

AVLNode *_prodecessor(AVLNode *root, int *distance)
{
    if (root->parent && *distance < max_distance)
    {
        root->status = -1;
        *distance += 1;
        // printf("%d ", root->data);
        // printf("%d\n", *distance);
        return _prodecessor(root->parent, distance);
    }
    return root;
}

void tranversal(AVLNode *root, int distance)
{
    if (root && distance <= max_distance)
    {
        if (count < max_count && root->right)
            tranversal(root->right, distance + root->right->status);
        if (count < max_count)
        {
            printf("%d ", root->data);
            count++;
        }
        if (count < max_count && root->left)
            tranversal(root->left, distance + root->left->status);
    }
}
void solve(AVLNode *root, int value)
{
    count = 0;
    AVLNode *starting = avl_find(root, value);
    if (starting == NULL)
    {
        puts("Eyyy lom dateng :)");
        return;
    }
    int distance = 0;
    AVLNode *predecessor = _prodecessor(starting, &distance);
    // printf("%d\n", predecessor->data);
    // max_count = distance;
    // printf("%d\n", max_count);
    // printf("%d\n", max_distance);
    tranversal(predecessor, distance);

    printf("\n");

    set_status(predecessor);
}

void set_status(AVLNode *root)
{
    if (root)
    {
        root->status = 1;
        if (root->left)
        {
            if (root->left->status == -1)
            {
                set_status(root->left);
            }
            else if (root->right)
            {
                if (root->right->status == -1)
                    set_status(root->right);
            }
            // printf("%d\n", root->data);
        }
    }
}

int main()
{

    AVLNode *root = init();

    int command, data, size = 0;
    while (1)
    {
        scanf("%d", &command);
        if (command == -1)
            break;
        if (command == 0)
        {
            scanf("%d %d %d", &data, &max_distance, &max_count);
            if (max_count == -1)
                max_count = size;
            solve(root, data);
        }
        else
        {
            while (command--)
            {
                size++;
                scanf("%d", &data);
                root = _insert_AVL(root, NULL, data);
                // cout << "Insert : " << data << endl;
            }
        }
    }
    puts("End");
}
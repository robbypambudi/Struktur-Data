#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct bstnode_t
{
    int key;
    int jarak;
    struct bstnode_t *left, *right;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode *__bst__createNode(int value, int jarak)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->jarak = jarak;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode *__bst__insert(BSTNode *root, int value, int jarak)
{
    if (root == NULL)
        return __bst__createNode(value, jarak);

    if (value < root->key)
        root->left = __bst__insert(root->left, value, jarak);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value, jarak);

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

BSTNode *lca(BSTNode *root, int n1, int n2)
{
    while (root != NULL)
    {

        if (root->key > n1 && root->key > n2)
            root = root->left;

        else if (root->key < n1 && root->key < n2)
            root = root->right;

        else
            break;
    }
    return root;
}

int findJarak(BSTNode *root, int value)
{
    int jarak = 0;
    while (root != NULL)
    {
        if (value < root->key)
        {
            root = root->left;
            jarak += root->jarak;
        }
        else if (value > root->key)
        {
            root = root->right;
            jarak += root->jarak;
        }
        else
            return jarak;
    }
    return jarak;
}

int min = 100005;
void __bst__inorder(BST *bst, BSTNode *root, int cari)
{
    if (root)
    {
        __bst__inorder(bst, root->left, cari);
        if (root->left == NULL && root->right == NULL)
        {
            BSTNode *temp = lca(bst->_root, root->key, cari);
            int jarak = findJarak(temp, root->key) + findJarak(temp, cari);
            if (jarak < min)
                min = jarak;
        }
        __bst__inorder(bst, root->right, cari);
    }
}

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

void bst_insert(BST *bst, int value, int jarak)
{
    if (!bst_find(bst, value))
    {
        bst->_root = __bst__insert(bst->_root, value, jarak);
        bst->_size++;
    }
}

void bst_inorder(BST *bst, int cari)
{
    __bst__inorder(bst, bst->_root, cari);
}

int main()
{
    BST set;
    bst_init(&set);
    int t, input, n, cari, jrk;
    scanf("%d %d", &t, &input);
    bst_insert(&set, input, 0);
    t--;
    while (t--)
    {
        scanf("%d %d", &input, &jrk);
        bst_insert(&set, input, jrk);
    }
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &cari);
        if (bst_find(&set, cari))
        {
            bst_inorder(&set, cari);
            printf("%d ", min);
            min = 100005;
        }
        else
        {
            puts("0");
        }
    }
}
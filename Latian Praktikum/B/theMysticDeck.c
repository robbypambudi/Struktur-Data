#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <assert.h>

struct avl_node_s
{
    struct avl_node_s *left;
    struct avl_node_s *right;
    char *value;
};

typedef struct avl_node_s avl_node_t;

struct avl_tree_s
{
    struct avl_node_s *root;
};

typedef struct avl_tree_s avl_tree_t;

/* Create a new AVL tree. */
avl_tree_t *avl_create()
{
    avl_tree_t *tree = NULL;

    if ((tree = malloc(sizeof(avl_tree_t))) == NULL)
    {
        return NULL;
    }

    tree->root = NULL;

    return tree;
}

/* Initialize a new node. */
avl_node_t *avl_create_node()
{
    avl_node_t *node = NULL;

    if ((node = malloc(sizeof(avl_node_t))) == NULL)
    {
        return NULL;
    }

    node->left = NULL;
    node->right = NULL;
    node->value = malloc(sizeof(char *) * 64);

    return node;
}

/* Find the height of an AVL node recursively */
int avl_node_height(avl_node_t *node)
{
    int height_left = 0;
    int height_right = 0;

    if (node->left)
        height_left = avl_node_height(node->left);
    if (node->right)
        height_right = avl_node_height(node->right);

    return height_right > height_left ? ++height_right : ++height_left;
}

/* Find the balance of an AVL node */
int avl_balance_factor(avl_node_t *node)
{
    int bf = 0;

    if (node->left)
        bf += avl_node_height(node->left);
    if (node->right)
        bf -= avl_node_height(node->right);

    return bf;
}

/* Left Left Rotate */
avl_node_t *avl_rotate_leftleft(avl_node_t *node)
{
    avl_node_t *a = node;
    avl_node_t *b = a->left;

    a->left = b->right;
    b->right = a;

    return (b);
}

/* Left Right Rotate */
avl_node_t *avl_rotate_leftright(avl_node_t *node)
{
    avl_node_t *a = node;
    avl_node_t *b = a->left;
    avl_node_t *c = b->right;

    a->left = c->right;
    b->right = c->left;
    c->left = b;
    c->right = a;

    return (c);
}

/* Right Left Rotate */
avl_node_t *avl_rotate_rightleft(avl_node_t *node)
{
    avl_node_t *a = node;
    avl_node_t *b = a->right;
    avl_node_t *c = b->left;

    a->right = c->left;
    b->left = c->right;
    c->right = b;
    c->left = a;

    return (c);
}

/* Right Right Rotate */
avl_node_t *avl_rotate_rightright(avl_node_t *node)
{
    avl_node_t *a = node;
    avl_node_t *b = a->right;

    a->right = b->left;
    b->left = a;

    return (b);
}

/* Balance a given node */
avl_node_t *avl_balance_node(avl_node_t *node)
{
    avl_node_t *newroot = NULL;

    /* Balance our children, if they exist. */
    if (node->left)
        node->left = avl_balance_node(node->left);
    if (node->right)
        node->right = avl_balance_node(node->right);

    int bf = avl_balance_factor(node);

    if (bf >= 2)
    {
        /* Left Heavy */

        if (avl_balance_factor(node->left) <= -1)
            newroot = avl_rotate_leftright(node);
        else
            newroot = avl_rotate_leftleft(node);
    }
    else if (bf <= -2)
    {
        /* Right Heavy */

        if (avl_balance_factor(node->right) >= 1)
            newroot = avl_rotate_rightleft(node);
        else
            newroot = avl_rotate_rightright(node);
    }
    else
    {
        /* This node is balanced -- no change. */

        newroot = node;
    }

    return (newroot);
}

/* Balance a given tree */
void avl_balance(avl_tree_t *tree)
{

    avl_node_t *newroot = NULL;

    newroot = avl_balance_node(tree->root);

    if (newroot != tree->root)
    {
        tree->root = newroot;
    }
}

/* Insert a new node. */
void avl_insert(avl_tree_t *tree, char *value)
{
    avl_node_t *node = NULL;
    avl_node_t *next = NULL;
    avl_node_t *last = NULL;

    /* Well, there must be a first case */
    if (tree->root == NULL)
    {
        node = avl_create_node();
        node->value = value;

        tree->root = node;

        /* Okay.  We have a root already.  Where do we put this? */
    }
    else
    {
        next = tree->root;

        while (next != NULL)
        {
            last = next;

            if (strcmp(value, next->value) < 0)
            {
                next = next->left;
            }
            else if (strcmp(value, next->value) > 0)
            {
                next = next->right;

                /* Have we already inserted this node? */
            }
            else if (strcmp(value, next->value) == 0)
            {
                return;
            }
        }

        node = avl_create_node();
        node->value = value;

        if (strcmp(value, last->value) < 0)
            last->left = node;
        if (strcmp(value, last->value) > 0)
            last->right = node;
    }

    avl_balance(tree);
}

/* Find the node containing a given value */
avl_node_t *avl_find(avl_tree_t *tree, char *value)
{
    avl_node_t *current = tree->root;

    while (current && (strcmp(current->value, value) != 0))
    {
        if (strcmp(value, current->value) > 0)
            current = current->right;
        else
            current = current->left;
    }
    return current;
}

/* Do a depth first traverse of a node. */
void avl_traverse_node_dfs(avl_node_t *node, int depth)
{
    int i = 0;

    if (node->left)
        avl_traverse_node_dfs(node->left, depth + 2);

    for (i = 0; i < depth; i++)
        putchar(' ');
    printf("%s: %d\n", node->value, avl_balance_factor(node));

    if (node->right)
        avl_traverse_node_dfs(node->right, depth + 2);
}

/* Do a depth first traverse of a tree. */
void avl_traverse_dfs(avl_tree_t *tree)
{
    avl_traverse_node_dfs(tree->root, 0);
}
int count = 0;
void avl_print_node(avl_node_t *node, char *fmt, int prnt)
{

    if (count == prnt)
        return;

    if (node->right)
        avl_print_node(node->right, fmt, prnt);

    printf(fmt, node->value);
    count += 1;

    if (node->left)
        avl_print_node(node->left, fmt, prnt);
}

void avl_print(avl_tree_t *tree, char *fmt, int print)
{
    avl_print_node(tree->root, fmt, print);
}

void avl_count_node(avl_node_t *node, int *res)
{
    if (node->left)
        avl_count_node(node->left, res);
    *res = *res + 1;
    if (node->right)
        avl_count_node(node->right, res);
}

void avl_count(avl_tree_t *tree, int *res)
{
    avl_count_node(tree->root, res);
}

avl_node_t *avl_find_parent(avl_tree_t *tree, char *value)
{
    avl_node_t *current = tree->root;
    avl_node_t *parent = NULL;

    while (current && (strcmp(current->value, value) != 0))
    {
        parent = current;
        if (strcmp(value, current->value) > 0)
            current = current->right;
        else
            current = current->left;
    }
    return parent;
}
avl_node_t *avl_free_node(avl_node_t *node)
{
    if (node->left)
        avl_free_node(node->left);
    if (node->right)
        avl_free_node(node->right);
    free(node);
    return NULL;
}

void avl_deleted(avl_tree_t *tree, char *value)
{
    avl_node_t *node = avl_find(tree, value);
    if (node)
    {
        avl_node_t *parent = avl_find_parent(tree, value);
        if (parent)
        {
            if (parent->left == node)
            {
                parent->left = NULL;
            }
            else
            {
                parent->right = NULL;
            }
        }
        else
        {
            tree->root = NULL;
        }
        avl_free_node(node);
    }
}

int main(int argc, char **argv)
{
    avl_tree_t *tree = NULL;
    int i = 0;
    char nama[100];
    char *aux;
    tree = avl_create();

    /* Insert 1-20 in random order -- this is suboptimal, but easy */
    srand(time(NULL));
    int n;
    int command;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &command);
        if (command == 1)
        {
            scanf("%s", nama);
            aux = strdup(nama);
            avl_insert(tree, aux);
        }
        else if (command == 2)
        {
            scanf("%s", nama);
            aux = strdup(nama);
            avl_deleted(tree, aux);
        }
        else if (command == 0)
        {
            int value;
            scanf("%d", &value);
            avl_print(tree, "%s\n", value);
        }
    }

    return 0;
}
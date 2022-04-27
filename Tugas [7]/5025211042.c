#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MaxWordSize 30
typedef struct bst_positions
{
    int pos;
    struct bst_positions *next;

} bst_posisi;
typedef struct bstnode_t
{
    char word[100];
    bst_posisi *posisi;
    struct bstnode_t
        *left,
        *right;
} BSTNode;
typedef struct bst_t
{
    BSTNode *root;
    int size;
} BST;
void convertToSmall(char *word)
{
    int i;
    for (i = 0; i < strlen(word); i++)
    {
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            word[i] += 32;
        }
    }
}
int check_word(char *word1, char *word2)
{
    int length_word1 = strlen(word1);
    int length_word2 = strlen(word2);
    // find min length
    int min;
    if (length_word1 < length_word2)
    {
        min = length_word1;
    }
    else
    {
        min = length_word2;
    }
    convertToSmall(word1);
    convertToSmall(word2);
    if (strcmp(word1, word2) == 0)
    {
        return 0;
    }

    if (length_word1 == 1 && word1[0] <= word2[0])
    {
        return 2;
    }
    else if (length_word1 == 1 && word1[0] > word2[0])
    {
        return 1;
    }

    for (int i = 0; i < min; i++)
    {
        if (word1[i] <= word2[i])
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

BSTNode *__bst_createNode(char *word)
{
    BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
    strcpy(node->word, word);
    node->left = NULL;
    node->right = NULL;
    node->posisi = NULL;
    return node;
}

bst_posisi *__create_Posisi(int pos)
{
    bst_posisi *posisi = (bst_posisi *)malloc(sizeof(bst_posisi));
    posisi->pos = pos;
    posisi->next = NULL;
    return posisi;
}
void __bst_insert_posisi(bst_posisi *root, char *word, int pos)
{
    if (root == NULL)
    {
        return;
    }
    if (root->pos == pos)
    {
        bst_posisi *new_posisi = __create_Posisi(pos);
        new_posisi->next = root->next;
        root->next = new_posisi;
        return;
    }
    __bst_insert_posisi(root->next, word, pos);
}

BSTNode *__bst_insert(BSTNode *root, char *word, int pos)
{
    if (root == NULL)
    {
        root = __bst_createNode(word);
        bst_posisi *posisi = __create_Posisi(pos);
        root->posisi = posisi;
    }
    else if (check_word(root->word, word) == 2)
    {
        root->right = __bst_insert(root->right, word, pos);
    } // else if (check_word(root->word, word) == 1)
    else if (check_word(root->word, word) == 1)
    {
        root->left = __bst_insert(root->left, word, pos);
    }
    else
    {
        bst_posisi *posisi = __create_Posisi(pos);
        posisi->next = root->posisi;
        root->posisi = posisi;
    }
    return root;
}
BSTNode *__bst_search(BSTNode *root, char *word)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (check_word(root->word, word) == 2)
    {
        return __bst_search(root->right, word);
    } // else if (check_word(root->word, word) == 1)
    else if (check_word(root->word, word) == 1)
    {
        return __bst_search(root->left, word);
    }
    else
    {
        return root;
    }
}

void __bst_inorder(BSTNode *root)
{
    if (root != NULL)
    {
        __bst_inorder(root->left);
        printf("%s ", root->word);
        bst_posisi *posisi = root->posisi;
        while (posisi != NULL)
        {
            printf("%d ", posisi->pos);
            posisi = posisi->next;
        }
        printf("\n");

        __bst_inorder(root->right);
    }
}

void bst_init(BST *bst)
{
    bst->root = NULL;
    bst->size = 0;
}

bool bst_isEmpty(BST *bst)
{
    return bst->size == 0;
}
bool bst_isExist(BST *bst, char *word)
{
    BSTNode *temp = __bst_search(bst->root, word);
    if (temp == NULL)
    {
        return false;
    }
    else if (strcmp(temp->word, word) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void insert_posisi(BST *bst, char *word, int pos)
{
    BSTNode *temp = __bst_search(bst->root, word);
    __bst_insert_posisi(temp->posisi, word, pos);
}
void bst_insert(BST *bst, char *word, int pos)
{
    bst->root = __bst_insert(bst->root, word, pos);
    bst->size++;
}

void bst_inorder(BST *bst)
{
    __bst_inorder(bst->root);
}
void remove_spaces(char *s)
{
    char *d = s;
    do
    {
        while (*d == ' ')
        {
            ++d;
        }
    } while (*s++ == *d++);
}

int getWord(FILE *in, char str[], int *line, int *cor)
{
    char temp;
    int n = 0;
    temp = getc(in);

    while (temp != EOF)
    {
        if (temp == '\n')
        {
            *line += 1;
        }
        if (isalpha(temp))
        {
            break;
        }
        temp = getc(in);
    }

    if (temp == EOF)
    {
        return 0;
    }
    str[n++] = tolower(temp);
    while (isalpha(temp = getc(in)) && temp != EOF)
    {
        if (n < MaxWordSize)
            str[n++] = tolower(temp);
    }
    str[n] = '\0';

    if (temp == '\n')
    {
        *cor = 1;
    }

    return 1;
}

int main()
{
    BST bst;
    bst_init(&bst);
    FILE *fp;
    int line = 1;
    int correction = 0;
    char word[MaxWordSize];
    char str[MaxWordSize];
    fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("File tidak dapat dibuka");
        exit(1);
    }
    while (getWord(fp, str, &line, &correction) != 0)
    {
        if (bst_isExist(&bst, str))
        {
            insert_posisi(&bst, str, line);
        }
        else
        {
            bst_insert(&bst, str, line);
        }
        if (correction == 1)
        {
            line++;
            correction = 0;
        }
    }
    bst_inorder(&bst);
}
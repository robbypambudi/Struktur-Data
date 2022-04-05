- [Praktikum 2](#praktikum-2)
  - [1. Jalur Perang Dunia](#1-jalur-perang-dunia)
    - [Deskripsi Soal](#deskripsi-soal)
    - [Input Format](#input-format)
    - [Constraints](#constraints)
    - [Output Format](#output-format)
    - [Sample Input](#sample-input)
    - [Sample Output 0](#sample-output-0)
    - [Kode](#kode)
  - [2.  Teleportasi Galaxy](#2--teleportasi-galaxy)
    - [Deskripsi Soal](#deskripsi-soal-1)
    - [Input Format](#input-format-1)
    - [Constraints](#constraints-1)
    - [Output Format](#output-format-1)
    - [Sample Input 0](#sample-input-0)
    - [Sample Output](#sample-output)
    - [Kode](#kode-1)
  - [3. Maaf, Siapa ya?](#3-maaf-siapa-ya)
    - [Deskripsi Soal](#deskripsi-soal-2)
    - [Input Format](#input-format-2)
    - [Constraints](#constraints-2)
    - [Output Format](#output-format-2)
    - [Output Format](#output-format-3)
    - [ample Input 0](#ample-input-0)
    - [Sample Output 0](#sample-output-0-1)
    - [Kode](#kode-2)
  - [Link Hackerank](#link-hackerank)

# Praktikum 2

## 1. Jalur Perang Dunia

### Deskripsi Soal
Setelah menyerang beberapa negara, Vradimir menghadapi sebuah hal yang sangat mengejutkan. Ia melihat bahwa negara-negara selanjutnya memiliki dinding yang sangat tinggi. Setiap negara memiliki tinggi yang berbeda. Tidak hanya itu, setelah diamati, ternyata setiap negara saling terhubung dan membentuk sebuah BST. Pada saat ini, Vradimir berada pada tingkat terbawah dari BST. Karena saling terhubung, maka Vradimir hanya perlu menyerang satu negara setiap tingkatnya. Untuk memaksimalkan penyerangan, Vradimir ingin menyerang negara berurutan berdasarkan tinggi dinding yang paling rendah terlebih dahulu, kemudian paling tinggi, lalu paling rendah, dst. Sebagai ahli strategi Vradimir, carilah tinggi dinding negara-negara yang akan diserang Vradimir sesuai ketentuan. 
### Input Format

    Baris pertama adalah N, banyak negara
    Baris kedua adalah N buah angka ketinggian dinding

### Constraints

    1 ≤ N ≤ 1024
    1 ≤ Tinggi Dinding ≤ 100000

### Output Format
Seperti ketentuan yang sudah dijelaskan ditambah newline
### Sample Input
```
15
100 50 150 25 75 125 175 15 35 65 85 115 135 165 185
```
### Sample Output 0
```
15 175 50 100
```
### Kode 
```
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int min[1024], max[1024];
int height = 0;

typedef struct bstnode_t
{
    int key;
    struct bstnode_t *left, *right;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
    unsigned int _size;
} BST;

void bst_init(BST *bst)
{
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst)
{
    return bst->_root == NULL;
}

BSTNode *__search(BSTNode *root, int value)
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

bool bst_find(BST *bst, int value)
{
    BSTNode *temp = __search(bst->_root, value);
    if (temp == NULL)
        return false;

    if (temp->key == value)
        return true;
    else
        return false;
}

BSTNode *createNode(int value)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode *insert(BSTNode *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->key)
        root->left = insert(root->left, value);
    else if (value > root->key)
        root->right = insert(root->right, value);

    return root;
}

void bst_insert(BST *bst, int value)
{
    if (!bst_find(bst, value))
    {
        bst->_root = insert(bst->_root, value);
        bst->_size++;
    }
}

void findMinimumMax(BSTNode *root, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (root->key < min[level])
    {
        min[level] = root->key;
    }
    if (root->key > max[level])
    {
        max[level] = root->key;
    }

    if (height < level)
    {
        height = level;
    }

    findMinimumMax(root->left, level + 1);
    findMinimumMax(root->right, level + 1);
}

void bst_findminmax(BST *bst)
{
    findMinimumMax(bst->_root, 0);
}

int main()
{
    BST bst;
    bst_init(&bst);

    memset(min, 10000, sizeof(min));
    memset(max, 0, sizeof(max));

    int n;
    scanf("%d", &n);

    int a;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        bst_insert(&bst, a);
    }

    bst_findminmax(&bst);

    int temp = 1;
    for (int i = height; i >= 0; i--)
    {
        if (temp)
        {
            printf("%d ", min[i]);
        }
        else
        {
            printf("%d ", max[i]);
        }
        temp = !temp;
    }
}
```

## 2.  Teleportasi Galaxy 
### Deskripsi Soal
Youshi merupakan seorang astronom. Ketika meneliti galaxy, ia melambangkan setiap galaxy dengan angka sehingga mudah diingat. Setelah meneliti sekian lama, ia menyadari bahwa galaxy-galaxy tersusun seperti sebuah binary search tree. Dari penemuan ini, Youshi termotivasi untuk membuat alat teleportasi antar galaxy. Karena jarak setiap galaxy yang sangat jauh, bahan bakar alat teleportasi dipengaruhi oleh perbedaan tingkat dari satu galaxy, ke galaxy lainnya. Sebagai teknisi alat teleportasi, carilah perbedaan tingkat dari satu galaxy ke galaxy lainnya. 

### Input Format

    Baris pertama yaitu banyaknya galaxy, N
    N baris berikutnya yaitu Ni yang melambangkan galaxy
    Baris selanjutnya yaitu M, yaitu banyaknya pasangan galaxy yang ingin dicek perbedaan tingkatnya
    M baris berikutnya berisi pasangan yang ingin dicek.
### Constraints

    2 ≤ N ≤ 100
    1 ≤ Ni ≤ 1000
    2 ≤ M ≤ 100
### Output Format
Untuk setiap pasangan galaxy, output perbedaan tingkatnya. Jika berada pada tingkat yang sama, keluarkan "Galaxy berada pada tingkat yang sama" tanpa tanda petik.

### Sample Input 0
```
10
655 159 533 998 808 165 359 333 910 653
4
655 533 
998 165 
165 910 
333 653
```
### Sample Output
```
2
2
Galaxy berada pada tingkat yang sama
2
```

### Kode
```
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * Node structure and
 * uniqueBST structure
 */

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
int findLevel(BSTNode *root, int value, int level)
{
    if (root == NULL)
        return 0;

    if (root->key == value)
        return level;

    int l = findLevel(root->left, value, level + 1);
    if (l != 0)
        return l;

    return findLevel(root->right, value, level + 1);
}
int bst_findLevel(BST *bst, int value)
{
    return findLevel(bst->_root, value, 0);
}

int main()
{
    int n;
    BST bst;
    int value;
    bst_init(&bst);
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        bst_insert(&bst, value);
    }

    scanf("%d", &n);
    int data1, data2;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &data1, &data2);
        if (bst_find(&bst, data1) && bst_find(&bst, data2))
        {
            int level1 = bst_findLevel(&bst, data1);
            int level2 = bst_findLevel(&bst, data2);
            if (level1 == level2)
            {
                printf("Galaxy berada pada tingkat yang sama\n");
                continue;
            }
            int selesih = abs(level1 - level2);
            printf("%d\n", selesih);
        }
        else
            continue;
    }
}
```

## 3. Maaf, Siapa ya? 
### Deskripsi Soal
Andi merupakan siswa yang sangat pandai. Ia selalu mendapat rank 1 baik di kelas maupun di perlombaan. Tentu saja pujian mengalir dari berbagai arah, termasuk keluarganya. Akan tetapi, Andi merupakan tipe orang yang mudah lupa. Segala hal yang dia anggap tidak penting, akan segera dilupakan. Awalnya, Andi mengira bahwa kebiasaannya tersebut adalah hal normal dan tidak akan terlalu berdampak dalam hidupnya.

Suatu hari, saat pertemuan keluarga besar, ia bertemu kembali dengan kerabat-kerabat jauhnya. Banyak dari mereka yang memberikan pujian kepada Andi karena mereka semua tau atas prestasi-prestasi yang telah ia raih. Namun, sayangnya Andi tidak mengenal satupun dari mereka, dan tentunya hal tersebut membuat mereka kecewa. Ia juga membuat orang tuanya marah karena tidak mengingat kerabat sendiri dianggap sebagai perbuatan yang mempermalukan keluarganya.

Setelah kejadian tersebut, Andi pun bertekad untuk menghafal silsilah keluarganya agar kelak ketika bertemu lagi, agar peristiwa yang sama tidak akan terulang kembali. Sebagai permulaan, ia ingin mencari buyut yang menghubungkannya dengan anggota keluarga lainnya. Karena silsilah keluarganya mirip dengan BST dan semua orang diwakili oleh sebuah angka, maka Andi ingin membuat program yang memudahkan pekerjaannya.

### Input Format
Baris pertama berisi sebuah bilangan N

N baris selanjutnya, berisi bilangan M

Jika M adalah 1, maka inputan selanjutnya adalah P, sebuah bilangan yang akan dimasukkan ke dalam pohon keluarga

Jika M adalah 2, maka inputan selanjutnya adalah P1 dan P2, dua bilangan yang akan dicek buyutnya

### Constraints

    2 ≤ N ≤ 10^6
    1 ≤ P ≤ 10^6

### Output Format

    2 ≤ N ≤ 10^6
    1 ≤ P ≤ 10^6

### Output Format

Jika M bukan bilangan 1 atau 2, keluarkan "Input tidak valid." tanpa tanda kutip

Jika M adalah 2:

    Jika dari kedua bilangan yang dimasukkan terdapat bilangan yang tidak ada di silsilah keluarga, maka cetak "Data tidak valid." tanpa tanda kutip
    Jika kedua bilangan tersebut memiliki buyut yang sama, maka cetak buyutnya.
    Jika kedua bilangan tersebut tidak memiliki buyut yang sama, maka cetak "Yah, ga ketemu.
    " tanpa tanda kutip

### ample Input 0
```
15
1 8
1 3
1 6
1 7
1 4
1 1
1 10
1 9
1 14
2 4 7
2 1 4
2 7 14
2 14 10
2 2 11
3 3 10
```
### Sample Output 0
```
6
3
8
10
Data tidak valid.
Input tidak valid.
```

### Kode
```
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int hasil;

typedef struct dnode_t
{
    int data;
    struct dnode_t *next, *prev;
} DListNode;

typedef struct deque_t
{
    DListNode *_head, *_tail;
    unsigned _size;
} Deque;

typedef struct bstnode_t
{
    int key;
    struct bstnode_t *left, *right;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
    unsigned int _size;
} BST;

// Deque
void deq_init(Deque *deque)
{
    deque->_head = deque->_tail = NULL;
    deque->_size = (unsigned)0;
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
bool deq_isEmpty(Deque *deque)
{
    return (deque->_head == NULL &&
            deque->_tail == NULL);
}

int deq_front(Deque *deque)
{
    if (!deq_isEmpty(deque))
    {
        return (deque->_head->data);
    }
    return 0;
}

void deq_pushBack(Deque *deque, int value)
{
    DListNode *newNode = (DListNode *)malloc(sizeof(DListNode));
    if (newNode)
    {
        newNode->data = value;
        newNode->next = NULL;
        deque->_size++;
        if (deq_isEmpty(deque))
        {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        deque->_tail->next = newNode;
        newNode->prev = deque->_tail;
        deque->_tail = newNode;
    }
}

void deq_popFront(Deque *deque)
{
    if (!deq_isEmpty(deque))
    {
        DListNode *temp = deque->_head;
        if (deque->_head == deque->_tail)
        {
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else
        {
            deque->_head = deque->_head->next;
            deque->_head->prev = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

void deq_popBack(Deque *deque)
{
    if (!deq_isEmpty(deque))
    {
        DListNode *temp;
        if (deque->_head == deque->_tail)
        {
            temp = deque->_head;
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else
        {
            temp = deque->_tail;
            deque->_tail = deque->_tail->prev;
            deque->_tail->next = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

BSTNode *__search(BSTNode *root, int value)
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

bool bst_find(BST *bst, int value)
{
    BSTNode *temp = __search(bst->_root, value);
    if (temp == NULL)
        return false;

    if (temp->key == value)
        return true;
    else
        return false;
}

BSTNode *createNode(int value)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode *insert(BSTNode *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->key)
        root->left = insert(root->left, value);
    else if (value > root->key)
        root->right = insert(root->right, value);

    return root;
}

void bst_insert(BST *bst, int value)
{
    if (!bst_find(bst, value))
    {
        bst->_root = insert(bst->_root, value);
        bst->_size++;
    }
}

bool findPath(BSTNode *root, Deque *deque, int k)
{
    if (root == NULL)
    {
        return false;
    }

    deq_pushBack(deque, root->key);

    if (root->key == k)
    {
        return true;
    }

    if ((root->left && findPath(root->left, deque, k)) ||
        (root->right && findPath(root->right, deque, k)))
        return true;

    deq_popBack(deque);
    return false;
}

int LCA(BST *bst, int n1, int n2)
{
    Deque s1, s2;
    deq_init(&s1);
    deq_init(&s2);

    if (!findPath(bst->_root, &s1, n1) || !findPath(bst->_root, &s2, n2))
    {
        return 0;
    }

    while (!deq_isEmpty(&s1))
    {
        if (deq_front(&s1) == deq_front(&s2))
        {
            hasil = deq_front(&s1);
            deq_popFront(&s1);
            deq_popFront(&s2);
        }
        else
        {
            break;
        }
    }
    return hasil;
}

int main()
{
    BST bst;
    bst_init(&bst);

    int n;
    int data1, data2;
    int a;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);

        if (a == 1)
        {
            int b;
            scanf("%d", &b);
            bst_insert(&bst, b);
        }
        else if (a == 2)
        {
            scanf("%d %d", &data1, &data2);
            if (!LCA(&bst, data1, data2))
            {
                printf("Data tidak valid.\n");
            }
            else
            {
                printf("%d\n", hasil);
            }
        }
        else
        {
            printf("Input tidak valid.\n");
        }
    }
}
```


## Link Hackerank 
- https://www.hackerrank.com/contests/alpro-its-sd-m2-f-2022/challenges
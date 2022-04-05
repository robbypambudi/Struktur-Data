- [Praktikum [1]](#praktikum-1)
  - [1. Rumbling Perang Dunia](#1-rumbling-perang-dunia)
    - [- Deskripsi Soal](#--deskripsi-soal)
    - [Input Format](#input-format)
    - [Constraints](#constraints)
    - [Output Format](#output-format)
    - [Sample Input 0](#sample-input-0)
    - [Sample Output 0](#sample-output-0)
    - [Kode](#kode)
  - [2. Semua Angka Hanyalah Alat](#2-semua-angka-hanyalah-alat)
    - [Deskripsi Soal](#deskripsi-soal)
    - [Contoh Input :](#contoh-input-)
    - [Contoh Output](#contoh-output)
    - [Input Format](#input-format-1)
    - [Constraints](#constraints-1)
    - [Output Format](#output-format-1)
    - [Kode](#kode-1)
  - [3. SS-Tier Cryo DPS Selling Goat](#3-ss-tier-cryo-dps-selling-goat)
    - [Deskripsi Soal](#deskripsi-soal-1)
    - [Input Format](#input-format-2)
    - [Constraints](#constraints-2)
    - [Output Format](#output-format-2)
    - [Sample Input 0](#sample-input-0-1)
    - [Sample Output 0](#sample-output-0-1)
    - [Explanation 0](#explanation-0)
    - [Kode](#kode-2)
  - [4.Ultimate Karaage Marin Stack](#4ultimate-karaage-marin-stack)
    - [Deskripsi Soal](#deskripsi-soal-2)
    - [Input Format](#input-format-3)
    - [Constraints](#constraints-3)
    - [Output Format](#output-format-3)
    - [Sample Input 0](#sample-input-0-2)
    - [Sample Output 0](#sample-output-0-2)
    - [Explanation 0](#explanation-0-1)
    - [Kode](#kode-3)
  - [5. Critical SSDB](#5-critical-ssdb)
    - [Input Format](#input-format-4)
    - [Constraints](#constraints-4)
    - [Output Format](#output-format-4)
    - [Sample Input 0](#sample-input-0-3)
    - [Sample Output 0](#sample-output-0-3)
    - [Kode](#kode-4)

# Praktikum [1]

## 1. Rumbling Perang Dunia

### - Deskripsi Soal

Vradimir Jeager sedang mempersiapkan diri untuk menjajah dunia menggunakan tubuh raksasanya. Asisten Vradimir, Mikoso, memiliki jadwal untuk menjajah negara. Ternyata, sebuah negara tidak dapat dijajah kapan saja, sehingga terdapat tanggal khusus dimana sebuah negara dapat dijajah. Karena sifat Vradimir yang sangat disiplin, ia ingin menjajah setiap negara secepat mungkin dan memulai dari tanggal yang paling dekat. Dari banyaknya negara yang dapat dijajah, Vradimir ingin menjajah sebanyak M negara. Karena terlalu sibuk memikirkan rencana dan terlalu lelah setelah menjadi raksasa, Vradimir tidak sempat untuk mencari tahu negara selanjutnya yang akan dijajah. Bantulah Vradimir untuk mengetahui negara yang akan dijajah berikutnya.

Dapat dipastikan Vradimir menjajah di tahun yang sama dan jadwal yang diberikan Mikoso merupakan jadwal dari saat itu.

### Input Format

    - Baris pertama adalah N dan M (banyak negara yang dapat dijajah dan banyak negara yang ingin dijajah)

    - N-baris berikutnya adalah nama negara, tanggal dan bulan negara tersebut dapat dijajah

### Constraints

`1 ≤ M ≤ N ≤ 1000`

### Output Format

Keluarkan negara selanjutnya yang akan dijajah dalam bentuk "Negara selanjutnya yaitu: (NamaNegara)" tanpa tanda petik dan ()

Jika tidak ada negara yang dapat diserang selanjutnya, maka keluarkan "Projek Rumbling Berhasil"

### Sample Input 0

```
5 3
Shiganshina 04 12
Maria 01 11
Eldia 08 12
Marley 31 12
Ukrain 30 12
```

### Sample Output 0

```
Negara selanjutnya yaitu: Ukrain
```

### Kode

```
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct pqueueNode_t
{
    char Country[20];
    int date;
    int month;
    struct pqueueNode_t *next;
} PQueueNode;

/* Struktur ADT PriorityQueue menggunakan Linked List */

// Prioritas default: nilai minimum
typedef struct pqueue_t
{
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

/* Function prototype */

void pqueue_init(PriorityQueue *pqueue);
bool pqueue_isEmpty(PriorityQueue *pqueue);
void pqueue_push(PriorityQueue *pqueue, char *country, int date, int month);
void pqueue_pop(PriorityQueue *pqueue);
void pqueue_top(PriorityQueue *pqueue);

/* Function definition below */

void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue)
{
    return (pqueue->_top == NULL);
}

void pqueue_push(PriorityQueue *pqueue, char *country, int date, int month)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode =
        (PQueueNode *)malloc(sizeof(PQueueNode));
    strcpy(newNode->Country, country);
    newNode->date = date;
    newNode->month = month;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue))
    {
        pqueue->_top = newNode;
        return;
    }

    if (month < pqueue->_top->month)
    {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
        return;
    }
    if (month == pqueue->_top->month)
    {
        if (date < pqueue->_top->date)
        {
            newNode->next = pqueue->_top;
            pqueue->_top = newNode;
            return;
        }
    }

    while (temp->next != NULL)
    {
        if (month < temp->next->month)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        else if (month == temp->next->month)
        {
            if (date <= temp->next->date)
            {
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
        }
        temp = temp->next;
    }
    temp->next = newNode;
}

void pqueue_pop(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue))
    {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

void pqueue_top(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue))
        printf("Negara selanjutnya yaitu: %s\n", pqueue->_top->Country);
    else
        return;
}
void pqueue_all(PriorityQueue *pqueue)
{
    PQueueNode *temp = pqueue->_top;
    while (temp != NULL)
    {
        printf("Negara selanjutnya yaitu: %s\n", temp->Country);
        temp = temp->next;
    }
}

int main(int argc, char const *argv[])
{
    // Buat objek PriorityQueue
    PriorityQueue myPque;

    // PENTING! Jangan lupa diinisialisasi
    pqueue_init(&myPque);

    // Operasi pada priority queue
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        char country[20];
        int date, month;
        scanf("%s %d %d", country, &date, &month);
        pqueue_push(&myPque, country, date, month);
    }

    // cetak isi pque
    for (int i = 0; i <= M; i++)
    {
        if (i == M)
        {
            if (pqueue_isEmpty(&myPque))
                printf("Projek Rumbling Berhasil\n");
            else
                pqueue_top(&myPque);
        }
        pqueue_pop(&myPque);
    }
    return 0;
}
```

## 2. Semua Angka Hanyalah Alat

### Deskripsi Soal

Setelah pertarungan sengitmu dengan Gojo, Ayano yang melihat pertarungan tersebut tertarik untuk memanfaatkanmu sebagai alat barunya dalam mengembangkan sihir baru dan Gojo sebagai tester. nanti, saat Gojo mengeluarkan sihir dengan besaran n di basis 10, Ayano ingin mengubahnya ke basis lain. Jika saat diubah ke basis lain angka tersebut menjadi palindrom, maka efektifitas sihirnya menjadi efektif. "Semua Angka Hanyalah Alat", Ayano mengatakan hal tersebut sembari menyuruhmu membuat program yang mengecek hal tersebut

Ayano perlu mengecek sihir apa yang Gojo telah keluarkan dan outputnya. Karena -1 angka yang tidak dibutuhkan oleh Ayano, dia menjadikan angka tersebut sebagai input di programmu dilanjutkan dengan index pencariannya

Jika angka == -1, input selanjutnya merupakan index pencarian (start dari 0) dan jika basis == -1 juga, Ayano telah selesai mengembangkan sihir baru dan program dihentikan

### Contoh Input :

```
10 2
20 3
63 64
-1 0
-1 2
-1 1
7 1
-1 3
-1 4
69 22
-1 4
-1 -1
```

### Contoh Output

```
Tidak
Ya
Ya
10 2 -> 1-0-1-0
63 64 -> 63
20 3 -> 2-0-2
Ya
7 1 -> 0-0-0-0-0-0-0
Out of range
Ya
69 22 -> 3-3
```

### Input Format

```
angka1 basis1
angka2 basis2
...
-1 -1
```

### Constraints

```
-1 <= angka <= 10000
0 < basis <= 128
```

### Output Format

```
Tidak/Ya saat angka != -1

outputkan angka-basis ke jika angka == -1, => "angka basis -> angkaDalamBasis"

hentikan program saat - 1 -1
```

### Kode

```
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct dnode_t
{
    int data;
    struct dnode_t
        *next,
        *prev;
} DListNode;

/* Struktur ADT List */

typedef struct dlist_t
{
    int dec;
    int base;
    DListNode
        *_head,
        *_tail;
    unsigned _size;
} List;

DListNode *__dlist_createNode(int value)
{
    DListNode *newNode =
        (DListNode *)malloc(sizeof(DListNode));

    if (!newNode)
        return NULL;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return (DListNode *)newNode;
}

void dlist_init(List *list)
{
    list->_head = list->_tail = NULL;
    list->_size = (unsigned)0;
}

bool dlist_isEmpty(List *list)
{
    return (list->_head == NULL &&
            list->_tail == NULL);
}

void dlist_pushBack(List *list, int value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode)
    {
        list->_size++;
        if (dlist_isEmpty(list))
        {
            list->_head = newNode;
            list->_tail = newNode;
            return;
        }

        list->_tail->next = newNode;
        newNode->prev = list->_tail;
        list->_tail = newNode;
    }
}
void convertAnyBase(List *list, int dec, int base)
{
    if (dec == 0)
        return;
    int x = dec % base;
    dec /= base;
    if (x < 0)
        dec += 1;
    convertAnyBase(list, dec, base);
    dlist_pushBack(list, x < 0 ? x + (base * -1) : x);
}
void printList(List *list)
{
    // Check Null
    if (dlist_isEmpty(list))
    {
        printf("Out of range\n");
        return;
    }

    DListNode *temp = list->_head;
    printf("%d %d -> ", list->dec, list->base);
    while (temp != NULL)
    {
        if (temp->next == NULL)
        {
            printf("%d", temp->data);
            temp = temp->next;
            continue;
        }
        printf("%d-", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Check Polindrome
void checkPolindrome(List *list)
{
    // Check Null

    if (dlist_isEmpty(list))
        return;

    DListNode *temp = list->_head;
    DListNode *temp2 = list->_tail;
    while (temp != temp2)
    {
        if (temp->data != temp2->data)
        {
            printf("Tidak\n");
            return;
        }
        temp = temp->next;
        temp2 = temp2->prev;
    }
    printf("Ya\n");
}
int main()
{
    List list[10010];
    int i = 0; // List[i];
    int N, M;
    while (true)
    {

        scanf("%d %d", &N, &M);

        // Input -1 -1
        if (M == -1 && N == -1)
        {
            break; // AC
        }
        else if (N == 0)
        {
            dlist_init(&list[i]);
            list[i].base = M;
            list[i].dec = N;
            printf("Ya\n");
            dlist_pushBack(&list[i], 0);
            i++;
            continue;
        }
        // Input depan -1
        else if (N == -1)
        {
            if (M > i || M < 0 || M > 10000)
            {
                printf("Out of range\n");
            }
            else
            {
                printList(&list[M]);
            }
            continue;
        }

        // Untuk Nambahin misal input 5 2
        else if (N != -1 || N != 0)
        {

            dlist_init(&list[i]);
            list[i].base = M;
            list[i].dec = N;
            if (M == 1)
            {
                for (int X = 0; X < N; X++)
                {
                    dlist_pushBack(&list[i], 0);
                }
                printf("Ya\n");
                i++;
                continue;
            }
            else
            {
                convertAnyBase(&list[i], N, M);
            }
            // printList(&list[i]);
            checkPolindrome(&list[i]);
            i++;
        }
    }
}
```

## 3. SS-Tier Cryo DPS Selling Goat

### Deskripsi Soal

Konon, katanya di atas langit masih ada langit. Desas-desus mengatakan bahwa para dewa (adeptus) hidup di sana. Ganyu, yang merupakan seseorang yang memiliki ras separuh adeptus sekaligus separuh manusia, menjual kambing. Setahun pertama bisnis jual kambingnya berjalan dengan lancar. Para adeptus sangat senang membeli kambing milik Ganyu. Akan tetapi, kini Ganyu memiliki masalah yang cukup serius karena para adeptus mulai tidak suka dengan cara Ganyu yang selalu menjual kambingnya dimulai pada urutan pertama, kedua, dan seterusnya. Para adeptus ingin memilih kambing sesuai keinginan mereka.

Ganyu, yang merasa bersalah sekaligus karena rasa sayang yang ada pada kambing-kambing miliknya, ia pun mulai mengelompokkan kambing-kambing yang lahir ataupun datang pada saat bersamaan lalu langsung memberikannya nama. Tidak peduli walaupun ganyu merupakan seorang separuh adeptus, ia tetap saja membutuhkan bantuanmu untuk mengelola bisnis jual kambing Ganyu, dengan membantu memberitahukan nama kambing yang diminta oleh para adeptus dan memberi tahu ganyu jika kambing yang diminta tidak ada. Dan tentu saja kambing yang sudah dibeli tidak bisa dijual kembali ke pelanggan lain.

Jika suatu kelompok kambing sudah habis, maka biarkan saja, namun jika ada yang membeli kambing pertama dari suatu kelompok maka kambing kedua akan menempati tempat kambing pertama dan seterusnya.

\*Hint : Soal ini bisa dikerjakan salah satunya dengan menggabungkan 2 struktur data yang terdapat pada modul 0 dan modul 1

### Input Format

Baris pertama berisi sebuah bilangan N yang menandakan banyak query untuk setiap query terdapat dua jenis input :

=> 1 K E1 E2 ... En. K merupakan banyak kambing pada yang datang pada saat itu dan Ei adalah nama kambing

=> 2 A B. beri tahu Ganyu nama kambing ke-B dari kelompok ke-A

### Constraints

```
0 < Q <= 10^5
0 < K <= 5
0 < |Ei| <= 10
```

### Output Format

Keluarkan nama kambing yang diminta jika kambing tersebut tidak ada keluarkan "Mending gacha Ganyu"

### Sample Input 0

```
5
1 4 nyenye nyenyenyeee nye nyinyinyi
1 3 haha xixi ha
2 1 3
2 1 3
2 1 3
```

### Sample Output 0

```
nye
nyinyinyi
Mending gacha Ganyu
```

### Explanation 0

Pada saat input 1 4 maka kelompok 1 berisi 4 kambing yaitu nyenye nyenyenyeee nye nyinyinyi. Pada input 2 1 3 pertama mengeluarkan nye karena itu kambing ke 3 lalu posisi nya diganti kambing berikut nya. Pada input 2 1 3 kedua mengeluarkan nyinyinyi. Pada input 2 1 3 ketika mengeluarkan "Mending gacha Ganyu" karena tidak ada kambing ke 3 lagi di kelompok 1

### Kode

```
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct snode_t
{
    char kambing[50];
    struct snode_t *next;
} SListNode;

/* Struktur ADT SinglyList */

typedef struct slist_t
{
    unsigned _size;
    SListNode *_head;
} SinglyList;

void slist_init(SinglyList *list)
{
    list->_head = NULL;
    list->_size = 0;
}

bool slist_isEmpty(SinglyList *list)
{
    return (list->_head == NULL);
}
void slist_pushBack(SinglyList *list, char *kambing)
{
    SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));
    if (newNode)
    {
        list->_size++;
        strcpy(newNode->kambing, kambing);
        newNode->next = NULL;

        if (slist_isEmpty(list))
            list->_head = newNode;
        else
        {
            SListNode *temp = list->_head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}
void slist_popFront(SinglyList *list)
{
    if (!slist_isEmpty(list))
    {
        SListNode *temp = list->_head;
        list->_head = list->_head->next;
        free(temp);
        list->_size--;
    }
}
void slist_popBack(SinglyList *list)
{
    if (!slist_isEmpty(list))
    {
        SListNode *nextNode = list->_head->next;
        SListNode *currNode = list->_head;

        if (currNode->next == NULL)
        {
            free(currNode);
            list->_head = NULL;
            return;
        }

        while (nextNode->next != NULL)
        {
            currNode = nextNode;
            nextNode = nextNode->next;
        }
        currNode->next = NULL;
        free(nextNode);
        list->_size--;
    }
}

void slist_removeAt(SinglyList *list, int index)
{
    if (!slist_isEmpty(list))
    {

        /* Kasus apabila posisinya melebihi batas */
        if (index >= list->_size)
        {
            slist_popBack(list);
            return;
        }
        else if (index == 0 || index < 0)
        {
            slist_popFront(list);
            return;
        }

        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index - 1)
        {
            temp = temp->next;
            _i++;
        }
        SListNode *nextTo = temp->next->next;
        free(temp->next);
        temp->next = nextTo;
        list->_size--;
    }
}
int slist_getAt(SinglyList *list, int index)
{
    // Jika list tidak kosng
    if (!slist_isEmpty(list))
    {
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index)
        {
            temp = temp->next;
            _i++;
        }
        if (_i != index)
        {
            printf("Mending gacha Ganyu\n");
            return 2;
        }
        else
        {
            printf("%s\n", temp->kambing);
            return 1;
        }
    }
    printf("Mending gacha Ganyu\n");

    return 2;
}
int main()
{
    SinglyList list[100000];
    for (int i = 0; i < 100000; i++)
    {
        slist_init(&list[i]);
    }

    int N;
    int j = 0;
    char kambing[50];
    scanf("%d", &N);
    while (N--)
    {
        int K1;
        scanf("%d", &K1);
        if (K1 == 1)
        {
            int K2;
            scanf("%d", &K2);
            while (K2--)
            {
                scanf("%s", kambing);
                slist_pushBack(&list[j], kambing);
            }
            j++;
        }
        else if (K1 == 2)
        {
            int K2, K3;
            scanf("%d %d", &K2, &K3);
            // Check data K2 apakah lebih dari 10000 kurang dari 0 atau k3 Kurang dari 0
            if (K2 > 100000 || K2 <= 0 || K3 <= 0 || K2 > j)
            {
                printf("Mending gacha Ganyu\n");
                continue;
            }

            if (slist_getAt(&list[K2 - 1], K3 - 1) == 2)
            {
                continue;
            }
            slist_removeAt(&list[K2 - 1], K3 - 1);
        }
        else
        {
            continue;
        }
    }
}
```

## 4.Ultimate Karaage Marin Stack

### Deskripsi Soal

Kitagawa Marin, atau panggil saja Marin, sedang berjalan pulang ke rumah. Sayangnya, Gojo, (cuman) temannya Marin, tidak ikut bersamanya sehingga itu membuat Marin sangat kesal. Ia berusaha mencari cara agar dirinya tidak lagi merasa kesal. Karena ia juga merasa lapar, iapun membayangkan ada 2 tumpukan ayam karaage sedang menunggunya di rumah. Tentu saja ayam karaage itu special. Masing-masing ayam karaage pada tumpukannya memiliki berat berupa integer yang berbeda-beda. Misalkan tumpukan karaage pertama KA dan tumpukan karaage kedua KB, maka

```
KA = {ka1, ka2, ka3, …, kan}
KB = {kb1, kb2, kb3, …, kbn}
```

Tentu saja sebagai seorang Marin yang merasa level kecantiknya sudah di tingkat ultimate, ia akan melahap semua ayam karaage yang ada. Tetapi tetap saja, Marin memiliki kapasitas perut yang terbatas dan ada aturan tertentu untuk memakan ayam-ayam tersebut

Tentu saja sebagai seorang Marin yang merasa level kecantiknya sudah di tingkat ultimate, ia akan melahap semua ayam karaage yang ada. Tetapi tetap saja, Marin memiliki kapasitas perut yang terbatas dan ada aturan tertentu untuk memakan ayam-ayam tersebut

    Marin hanya bisa memulai memakan karaage dari yang paling atas pada tumpukan
    Berat karaage yang dimakan akan mengurangi kapasitas perutnya sama besar
    Total berat karaage yang dimakan tidak boleh melebihi kapasitas perutnya

Sekarang Marin sudah sampai rumah dan tidak sabar untuk melahapnya, akan tetapi marin butuh bantuanmu untuk mencari tahu seberapa maksimal berat karaage yang dapat dia makan, serta baris NUM yang aturannya sebagai berikut :

    Jika banyak karaage yang dimakan adalah genap, maka NUM adalah baris data stack karaage A yang genap
    Jika banyak karaage yang dimakan adalah ganjil, maka NUM adalah baris data stack karaage B yang ganjil
    Jika tidak ada karaage yang dapat dimakan, maka outputkan "GOJOOO-kunn wetengku lesu :("
    Jika tidak ada data yang ditampilkan, maka outputkan "Nihil"

### Input Format

    - Baris pertama adalah N banyak testcase
    - Untuk setiap N testcase :
    - P nA nB, dimana P adalah nilai kapasitas perut serta nA dan nB adalah banyak tumpukan karaage A dan B berurutan
    - ai sebanyak nA yang merupakan elemen dari tumpukan A
    - bj sebanyak nB yang merupakan elemen dari tumpukan B

### Constraints

```
1 ≤ N ≤ 50
1 ≤ nA,nB ≤ 1000000
0 ≤ ai,bj ≤ 1000000
1 ≤ P ≤ 10^9
```

### Output Format

Untuk setiap testcase,

- baris pertama outputkan total berat karaage yang dimakan marin diikuti kata “pitik”
- baris selanjutnya adalah data NUM diikuti endline ('\n')

### Sample Input 0

```
1
1000 7 5
222 233 200 300 400 600 100
200 100 500 499 399
```

### Sample Output 0

```
5 pitik
NUM =>499 399
```

### Explanation 0

```
5 pitik
NUM =>499 399

Explanation 0

222                 Ada beberapa kemungkinan untuk memakan karaagenya yaitu
233                 1. 222 A, 233 A, 200 A, 200 B => 4 karaage (855 < 1000)
200       200       2. 200 B, 100 B, 222 A, 233 A, 200 A => 5 karaage (955 < 1000)
300       100       3. 222 A, 233 A, 200 A, 200 B, 100 B, 300 A => 6 karaage (1255 > 1000)
400       500
600       500       Pada kasus 3, total beratnya 1255 sehingga melebihi kapasitas perut
100       399       Jadi yang diambil terbanyak adalah kasus 2 yaitu 5 karaage
Stack A   Stack B
```

### Kode

```
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct stackNode_t
{
    int data;
    struct stackNode_t *next, *prev;
} StackNode;

typedef struct stack_t
{
    StackNode *_top, *_rear, *_topp;
    unsigned _size;
} Stack;

void init(Stack *stack)
{
    stack->_size = 0;
    stack->_top = NULL;
    stack->_topp = NULL;
    stack->_rear = NULL;
}

bool isEmpty(Stack *stack)
{
    return (stack->_top == NULL && stack->_rear == NULL);
}

void push(Stack *stack, int value)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (newNode)
    {
        stack->_size++;
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (isEmpty(stack))
        {
            stack->_top = newNode;
            stack->_topp = newNode;
            stack->_rear = newNode;
        }
        else
        {
            stack->_rear->prev = newNode;
            newNode->next = stack->_rear;
            stack->_rear = newNode;
        }
    }
}

void down(Stack *stack)
{
    stack->_top = stack->_top->prev;
    return;
}

void up(Stack *stack)
{
    stack->_top = stack->_top->next;
    return;
}

void downn(Stack *stack)
{
    stack->_topp = stack->_topp->prev;
    return;
}

int top(Stack *stack)
{
    if (!isEmpty(stack))
        return stack->_top->data;
    return 0;
}

int topp(Stack *stack)
{
    if (!isEmpty(stack))
        return stack->_topp->data;
    return 0;
}

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int maximum, na, nb;
        scanf("%d %d %d", &maximum, &na, &nb);

        int na_dup = na;
        int nb_dup = nb;

        Stack stack1, stack2;
        init(&stack1);
        init(&stack2);

        for (int j = 0; j < na; j++)
        {
            int num;
            scanf("%d", &num);
            push(&stack1, num);
        }

        for (int j = 0; j < nb; j++)
        {
            int num;
            scanf("%d", &num);
            push(&stack2, num);
        }

        int total = 0, count = 0;

        while (na--)
        {
            if (top(&stack1) + total > maximum)
            {
                up(&stack1);
                break;
            }
            total += top(&stack1);
            count++;
            if (na != 0)
            {
                down(&stack1);
            }
        }

        int count_a = count;
        int result = count;

        while (nb--)
        {
            total += top(&stack2);
            count++;
            down(&stack2);

            while (total > maximum)
            {
                if (count_a > 0)
                {
                    total -= top(&stack1);
                    up(&stack1);
                    count--;
                    count_a--;
                }
                else
                {
                    break;
                }
            }

            if (total <= maximum && result < count)
            {
                result = count;
            }
        }

        printf("%d pitik\n", result);

        int ada = 0;
        if (!result)
        {
            ada = 1;
            printf("GOJOOO-kunn wetengku lesu :(\n");
        }
        else if (result % 2 == 0)
        {
            while (na_dup--)
            {
                if (topp(&stack1) % 2 == 0)
                {
                    ada++;
                    if (ada == 1)
                    {
                        printf("NUM =>");
                    }
                    printf("%d ", topp(&stack1));
                }
                downn(&stack1);
                if (ada && na_dup == 0)
                {
                    printf("\n");
                }
            }
        }
        else
        {
            while (nb_dup--)
            {
                if (topp(&stack2) % 2 != 0)
                {
                    ada++;
                    if (ada == 1)
                    {
                        printf("NUM =>");
                    }
                    printf("%d ", topp(&stack2));
                }
                downn(&stack2);
                if (ada && nb_dup == 0)
                {
                    printf("\n");
                }
            }
        }

        if (!ada)
        {
            printf("Nihil\n");
        }
    }
}
```

## 5. Critical SSDB

Perang Rusia-Ukraina semakin bergejolak dalam beberapa hari terakhir. Missile yang dilontarkan oleh pesawat tempur Rusia berhasil menghancurkan pusat distrik Izium, dini hari. Akibatnya, data-data para penduduk distrik tersebut hancur. Sebelum melancarkan serangan balik, pemerintah ingin mendata seluruh penduduk distrik Izium yang tersisa. Sebagai programmer handal, kalian diminta untuk membuat sebuah Super Simple DataBase (SSDB) untuk membantu pendataan tersebut. Karena sifatnya mendesak, diharap SSDB yang kalian buat bisa bekerja secepat mungkin. Pendataan yang dilakukan pemerintah mencakup data firstname, lastname, umur serta berat dan tinggi badan yang kemudian diolah menjadi Body Mass Index (BMI). Selain itu, SSDB yang diminta dapat menerima input berupa command, antara lain:

- ADD - Menambah data baru
- CHG - Merubah data
- PRT - Mencetak semua data yang tersimpan

### Input Format

Terdapat N baris. Setiap baris berisi salah satu dari command:

    ADD fn ln a w h
    CHG fn ln a w h i
    PRT

dimana:

    fn adalah First Name
    ln adalah Last Name
    a adalah Age
    w adalah Body Weight in kg
    h adalah Body Height in cm
    dan i adalah 0-based index

### Constraints

    0 < Length of fn, ln < 15
    0 ≤ i < Amount of data stored

### Output Format

Setelah melakukan perintah ADD cetak "Data added successfully" tanpa tanda kutip

Setelah melakukan perintah CHG cetak "Data changed successfully" tanpa tanda kutip

Hasil dari perintah PRT, dengan format

i. ln, fn a b

dimana

    i adalah 1-based index
    b adalah Body Mass Index (BMI)

### Sample Input 0

```
ADD Helen Anderson 24 52 168
CHG Donald Jones 50 65 175 0
ADD Linda Robinson 52 63 163
ADD Elizabeth Clark 66 77 175
PRT
CHG Karen Jackson 18 45 155 1
ADD Paul Williams 52 62 167
CHG Elizabeth Moore 79 64 177 2
ADD Mark Garcia 38 58 164
PRT
```

### Sample Output 0

```
Data added successfully
Data changed successfully
Data added successfully
Data added successfully
1. Jones, Donald 50 21.22
2. Robinson, Linda 52 23.71
3. Clark, Elizabeth 66 25.14
Data changed successfully
Data added successfully
Data changed successfully
Data added successfully
1. Jones, Donald 50 21.22
2. Jackson, Karen 18 18.73
3. Moore, Elizabeth 79 20.43
4. Williams, Paul 52 22.23
5. Garcia, Mark 38 21.56
```

### Kode

```
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
/* Struktur Node */

typedef struct snode_t
{
    char Firstname[50];
    char Lastname[50];
    int Age;
    double Weight;
    double Height;
    struct snode_t *next;
} SListNode;

/* Struktur ADT SinglyList */

typedef struct slist_t
{
    unsigned _size;
    SListNode *_head;
} SinglyList;

void slist_init(SinglyList *list)
{
    list->_head = NULL;
    list->_size = 0;
}

void pushBack(SinglyList *list, char *firstname, char *lastname, int age, double weight, double height)
{
    SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));
    strcpy(newNode->Firstname, firstname);
    strcpy(newNode->Lastname, lastname);
    newNode->Age = age;
    newNode->Weight = weight;
    newNode->Height = height;
    newNode->next = NULL;

    if (list->_head == NULL)
    {
        list->_head = newNode;
        list->_size++;
        return;
    }

    SListNode *temp = list->_head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    list->_size++;
}
void updateAt(SinglyList *list, char *firstname, char *lastname, int age, double weight, double height, int index)
{
    if (index < 0 || index >= list->_size)
    {
        return;
    }

    SListNode *temp = list->_head;
    int i = 0;
    while (i < index)
    {
        temp = temp->next;
        i++;
    }
    strcpy(temp->Firstname, firstname);
    strcpy(temp->Lastname, lastname);
    temp->Age = age;
    temp->Weight = weight;
    temp->Height = height;
}
void printList(SinglyList *list)
{
    SListNode *temp = list->_head;
    int i = 1;
    double BMI;
    while (temp != NULL)
    {
        BMI = temp->Weight / (temp->Height * temp->Height) * 10000;
        // printf("%f %f %f \n", BMI, temp->Weight, temp->Height);
        printf("%d. %s, %s %d %.2f\n", i, temp->Lastname, temp->Firstname, temp->Age, BMI);
        temp = temp->next;
        i++;
    }
}

int main()
{
    SinglyList list;
    slist_init(&list);

    char perintah[100];
    char firstName[100];
    char lastName[100];
    int age;
    double weight;
    double height;
    int index;

    while (scanf("%s", perintah) != EOF)
    {
        if (strcmp(perintah, "ADD") == 0)
        {
            scanf("%s %s %d %lf %lf", firstName, lastName, &age, &weight, &height);
            pushBack(&list, firstName, lastName, age, weight, height);
            puts("Data added successfully");
        }
        else if (strcmp(perintah, "CHG") == 0)
        {
            scanf("%s %s %d %lf %lf %d", firstName, lastName, &age, &weight, &height, &index);
            updateAt(&list, firstName, lastName, age, weight, height, index);
            puts("Data changed successfully");
        }
        else if (strcmp(perintah, "PRT") == 0)
        {
            printList(&list);
        }
        else
        {
            return 0;
        }
    }
}

```

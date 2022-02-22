# MODULE [0]
- [MODULE [0]](#module-0)
  - [Soal 1](#soal-1)
    - [Deskripsi Soal](#deskripsi-soal)
    - [Code](#code)
---
## Soal 1

### Deskripsi Soal 
Implementasikanlah fungsi baru bernama `forEachElement` untuk Linked List (bisa diterapkan pada Singly Linked List atau Doubly Linked List). Fungsi `forEachElement` akan berfungsi layaknya iterator (mengiterasi) untuk setiap elemen dari awal hingga akhir pada Linked List yang mana setiap elemennya dikenakan operasi/fungsi lain untuk tujuan tertentu.

Misalkan, fungsi `forEachElement` untuk mencetak tiap elemen dalam Linked List.

**Contoh Implementasi :**
```
#include <stdio.h>
#include <stdlib.h>

/*
Linked list
.
.
*/

void printElement(int *elem) {
    .
    .
}

void multiply2(int *elem) {
    .
    .
}

int main()
{
    List myList;
    dlist_init(&myList);

    // Anggap isi linked list adalah [1,2,3,4,5]
    // .
    // .
    // .

    // contoh fungsi forEachElement untuk mencetak data pada list

    forEachElement(&myList, printElement);

    // contoh fungsi forEachElement untuk mengalikan setiap elemen
    // dengan 2

    forEachElement(&myList, multiply2);

    // isi list menjadi [2,4,6,8,10]
    return 0;
}
```
Selain itu, ujilah fungsi forEachElement yang kamu buat dengan beberapa fungsi berikut:

reverseEach -- yakni untuk membalikkan (reverse) setiap bilangan.
sumDigit -- yakni mengganti elemen dengan penjumlahan semua digit setiap bilangan.

### Code 

**Membuat Struct Double Linked list**
```
typedef struct SListNode
{
    int data;
    struct SListNode *next;
    struct SListNode *prev;
} ListNode;

typedef struct SList
{
    ListNode *next;
    int _size;
} List;
```
**Inisialiasasi Linked List**
```
void dlist_init(List *list)
{
    list->next = NULL;
    list->_size = 0;
}
```
**Print Element**
- Mencetak Data
```
void printElement(ListNode *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
```
**Multiply 2**
- Mengalikan data dengan 2
```
void multiply2(ListNode *node)
{
    while (node != NULL)
    {
        cout << node->data * 2 << " ";
        node->data *= 2;
        node = node->next;
    }
}
```

**reverseEach**
- Membalik data pada linked list dengan cara rekursif
```
void reverseEach(ListNode *node)
{
    if (node == NULL)
    {
        return;
    }
    reverseEach(node->next);
    cout << node->data << " ";
}
```

**forEachElement**
- Iterator
```
void forEachElement(List *list, void (*f)(ListNode *))
{
    ListNode *node = list->next;

    f(node);

    cout << endl;
}
```

**SumDigit**
- menambahakan setiap digit dengan digit didepanya
```
void sumDigit(ListNode *node)
{
    if (node == NULL)
    {
        return;
    }
    if (node->next == NULL)
    {
        return;
    }
    node->data += node->next->data;
    sumDigit(node->next);
    cout << node->data << " ";
}
```
**PUSH**
- Untuk memasukan data kedalam Struct
```
void push(List *list, int data)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;
    node->next = list->next;
    node->prev = NULL;
    if (list->next != NULL)
    {
        list->next->prev = node;
    }
    list->next = node;
    list->_size++;
}
```

**Main Function**
```
int main()
{
    List myList;
    dlist_init(&myList);
    push(&myList, 5);
    push(&myList, 4);
    push(&myList, 3);
    push(&myList, 2);
    push(&myList, 1);
    forEachElement(&myList, printElement);
    forEachElement(&myList, multiply2);
    forEachElement(&myList, reverseEach);
    forEachElement(&myList, sumDigit);
}
```

---
SOAL 2
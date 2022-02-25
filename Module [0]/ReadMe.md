# Module [0]
- [Module [0]](#module-0)
  - [Soal 1](#soal-1)
    - [Deskripsi Soal](#deskripsi-soal)
    - [Code](#code)
  - [SOAL 2](#soal-2)
    - [Deskripsi Soal](#deskripsi-soal-1)
    - [Code](#code-1)
  - [Soal 3 : Dynamic Array](#soal-3--dynamic-array)
    - [Deskripsi Soal](#deskripsi-soal-2)
    - [Code](#code-2)
  - [Soal 3 : Linked List](#soal-3--linked-list)
    - [Deskripsi Soal](#deskripsi-soal-3)
    - [Code](#code-3)
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
    forEachElement(&myList, sumDigit);- [MODULE [0]](#module-0)
  - [Soal 1](#soal-1)
    - [Deskripsi Soal](#deskripsi-soal)
    - [Code](#code)
  - [SOAL 2](#soal-2)
    - [Deskripsi Soal](#deskripsi-soal-1)
    - [Code](#code-1)
  - [Soal 3 : Dynamic Array](#soal-3--dynamic-array)
    - [Deskripsi Soal](#deskripsi-soal-2)
    - [Code](#code-2)
  - [Soal 3 : Linked List](#soal-3--linked-list)
    - [Deskripsi Soal](#deskripsi-soal-3)
    - [Code](#code-3)
}
```

---
## SOAL 2

### Deskripsi Soal 

Buatlah implementasi fungsi dArray_insertAt dan dArray_removeAt yang berguna untuk memasukkan elemen baru pada posisi yang diinginkan dan menghapus elemen pada posisi yang diinginkan. Prototipe fungsinya seperti berikut.
```
void dArray_insertAt(DynamicArray *darray, unsigned index, int value);
void dArray_removeAt(Dynamic *darray, unsigned index);
```
- `index` merupakan posisi/indeks yang diinginkan.
- `value` adalah nilai baru yang akan dimasukkan.

### Code

- **Struct**
```
typedef struct dynamic_array_t
{
    int *data;
    int size;
    int capacity;
} dynamic_array;
```
- **Fungsi Portotipe**
```
void darray_init(dynamic_array *array);
void daray_isEmpty(dynamic_array *array);
void darray_pushBack(dynamic_array *array, int value);
```

- **Dynamic Array Init**
  - Inisialisasi Pertama pada struct
```
void darray_init(dynamic_array *array)
{
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
}
```

- **darray_isEmpty**
  - Sebuah fungsi untuk mengetahui apakah dynamic array tersebut kosong atau tidak.
```
bool darray_isEmpty(dynamic_array *array)
{
    return array->size == 0;
}
```

- **darray_pushBack**
  - Fungsi untuk menambhakan array pada belakang
```
void darray_pushBack(dynamic_array *array, int value)
{
    if (array->size == array->capacity)
    {
        array->capacity *= 2;
        array->data = (int *)realloc(array->data, array->capacity * sizeof(int));
    }
    array->data[array->size] = value;
    array->size++;
}
```

- **darray_insertAt**
  - Fungsi untuk menambahakan array dengan data pada indek yang lebih spesifik.
```
void darray_insertAt(dynamic_array *array, int index, int value)
{
    if (index < 0 || index > array->size)
    {
        return;
    }
    if (array->size == array->capacity)
    {
        array->capacity *= 2;
        array->data = (int *)realloc(array->data, array->capacity * sizeof(int));
    }
    for (int i = array->size; i > index; i--)
    {
        array->data[i] = array->data[i - 1];
    }
    array->data[index] = value;
    array->size++;
}
```

- **darray_removeAt**
  - Fungsi untuk menghapus data array pada indek sang sudah ditentukan
```
void darray_removeAt(dynamic_array *array, int index)
{
    if (index < 0 || index >= array->size)
    {
        return;
    }
    for (int i = index; i < array->size - 1; i++)
    {
        array->data[i] = array->data[i + 1];
    }
    array->size--;
}
```

- **darray_getAt**
  - Fungi untuk mendapatkan array pada index yang telah ditentukan
```
int darray_getAt(dynamic_array *array, int index)
{
    if (index < 0 || index >= array->size)
    {
        return -1;
    }
    return array->data[index];
}
```
- **print_all**
  - Cetak seluruh data pada Dynamic Array
```
void print_all(dynamic_array *array)
{
    for (int i = 0; i < array->size; i++)
    {
        cout << array->data[i] << " ";
    }
    cout << endl;
}
```

- **Main Function**
```
int main()
{
    dynamic_array array;
    darray_init(&array);
    darray_pushBack(&array, 1);
    darray_pushBack(&array, 2);
    darray_pushBack(&array, 3);
    darray_pushBack(&array, 4);
    darray_pushBack(&array, 5);
    print_all(&array);
    darray_insertAt(&array, 2, 6);
    print_all(&array);
    darray_removeAt(&array, 2);
    print_all(&array);
    cout << darray_getAt(&array, 2) << endl;
    return 0;
}
```
---

## Soal 3 : Dynamic Array

### Deskripsi Soal 
Modifikasilah kode Dynamic Array dan Linked List (SinglyList) yang ada pada github agar menyimpan tipe string (asumsikan panjang string maks. adalah 100 karakter).

### Code
- **Struct**
```
typedef struct dynamicArray_t
{
    char *data;
    int size;
    int capacity;
} dynamicArray;
```

- **Init**
```
void init(dynamicArray *array)
{
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
}
```

- **GetString**
  - Sebuah fungsi untuk mendapatkan string yang kemudian data disimpan dalam Dynamic Array
```
void getString(dynamicArray *array)
{
    char input[100];
    cin.getline(input, 100);
    int length = strlen(input);
    if (array->capacity < length)
    {
        array->capacity = length;
        array->data = (char *)realloc(array->data, array->capacity * sizeof(char));
    }
    for (int i = 0; i < length; i++)
    {
        array->data[i] = input[i];
    }
    array->size = length;
}
```
- **PrintString**
```
void printString(dynamicArray *array)
{
    for (int i = 0; i < array->size; i++)
    {
        cout << array->data[i];
    }
}
```

- **Main Function**
```
int main()
{
    dynamicArray array;
    init(&array);
    getString(&array);
    printString(&array);
    return 0;
}
```

---
## Soal 3 : Linked List
### Deskripsi Soal
Modifikasilah kode Dynamic Array dan Linked List (SinglyList) yang ada pada github agar menyimpan tipe string (asumsikan panjang string maks. adalah 100 karakter).

### Code

- **Struct**
```
typedef struct SListNode
{
    char data;
    struct SListNode *next;
} ListNode;

typedef struct SList
{
    ListNode *head;
    int _size;
} List;
```

- **Portotipe Fungsi**
```
void init(List *list);
bool isEmpty(List *list);
void pushBack(List *list, char value);
void getString(List *list);
void printElement(ListNode *node);
```

- **Init**
```
void init(List *list)
{
    list->head = NULL;
    list->_size = 0;
}
```
- **isEmpty**
```
bool isEmpty(List *list)
{
    return list->_size == 0;
}
```

- **GetString**
  - Mendapatkan string dari inputan yang kemudian dimasukan kedalam Linked List

```
void getString(List *list)
{
    char input[1000];
    cin.getline(input, 1000);
    int length = strlen(input);
    for (int i = 0; i < length; i++)
    {
        pushBack(list, input[i]);
    }
}
```

- **pushBack**
  - Menyimpan data yang yang dikirimkan oleh fungsi `getString`.
```
void pushBack(List *list, char value)
{
    ListNode *node = new ListNode;
    node->data = value;
    node->next = NULL;
    if (list->head == NULL)
    {
        list->head = node;
    }
    else
    {
        ListNode *temp = list->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
    }
    list->_size++;
}
```

- **printElement**
  - Cetak semua element pada linked list.

```
int main()
{
    List list;
    init(&list);
    getString(&list);
    printElement(&list);
    return 0;
}
```

Terimakasih
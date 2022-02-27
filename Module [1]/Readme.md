# Module [1]
- [Module [1]](#module-1)
  - [SOAL 1](#soal-1)
    - [Deskripsi Soal](#deskripsi-soal)
    - [Code](#code)
  - [SOAL 2](#soal-2)
    - [Deskripsi Soal](#deskripsi-soal-1)
    - [Input](#input)
    - [Output](#output)
    - [Contoh Input](#contoh-input)
    - [Contoh Output](#contoh-output)
    - [Code](#code-1)
  - [SOAL 3](#soal-3)
    - [Deskripsi Soal](#deskripsi-soal-2)
    - [Code](#code-2)
---

## SOAL 1
### Deskripsi Soal 
Buatlah program untuk memeriksa apakah sebuah string merupakan palindrom atau bukan menggunakan stack.
**Contoh Input**
```
kasur_rusak
```

### Code 
**Inisiaisasi Struct data**
```
#include <bits/stdc++.h>
using namespace std;

typedef struct snode_t
{
    char data;
    struct snode_t *next;
} SListNode;

typedef struct _stack
{
    SListNode *top;
    unsigned _size;
} SStack;
```

**Mencari apakah sturct kosong atau tidak**
- Mengeluarkan nilai ``true`` apabila stack kosong
```
bool stack_is_empty(SStack *stack)
{
return stack->top == NULL;
}
```

**Push data to Struct**
- Mengalokasikan memory dan memasukan data.
```
void push(SStack *stack, int data)
{
    SListNode *node = (SListNode *)malloc(sizeof(SListNode));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
    stack->_size++;
}
```
**Mengabil string**
- Mengunakan fungsi `getline` untuk mendapatkan string sampai dengan `\n` atau enter.
- Memasukan setiap caracter dalam string kedalam struct
```
void getString(string &s, SStack *stack)
{
    getline(cin, s);
    int i = 0;
    while (s[i] != '\0')
    {
        push(stack, s[i]);
        i++;
    }
}
```

**Check Apakah Polindrome atau Tidak**
- Inisialisasi `int i = 0` sebagai cara untuk mengakses rangkain karakter pada string.
- Cek apakah terdapat data pada stack
- Dengan mengamati rangkai data pada tipe stack maka lakukan pengecekan terhadapat data pada string


```
bool polindrome_check(string &s, SStack *stack)
{
    int i = 0;

    while (!stack_is_empty(stack))
    {

        if (s[i] != stack->top->data)
        {
            return false;
        }
        stack->top = stack->top->next;
        i++;
    }
    return true;
}
```

**Fungsi Main**
```
int main()
{
    SStack *stack = (SStack *)malloc(sizeof(SStack));
    stack->top = NULL;
    stack->_size = 0;
    string *str;
    getString(*str, stack);
    printf("%s\n", polindrome_check(*str, stack) ? "palindrom" : "mahal, eh bukan palindrom deh");
}
```
--- 
## SOAL 2

### Deskripsi Soal 
Sebuah klinik TC sedang melayani antrian pasien. Setiap pasien mempunyai id dan level urgensi masing-masing yang direpresentasikan oleh sebuah bilangan. Buatlah program untuk mensimulasikan antrian pada klinik tersebut.

### Input 
Baris pertama adalah Q, banyaknya query. Setiap query dapat berupa:
- `MASUK id x` - id adalah id dari orang dan x adalah tingkat urgensinya.
- `LAYANI` - Cetak id orang yang akan dilayani sekarang.
  
### Output 
Untuk setiap query `LAYANI`, cetak id orang yang akan dilayani saat ini. Jika sudah tidak ada pasien yang antri, maka cetak `HORE`.

### Contoh Input 
```
9
MASUK 1 15
MASUK 3 2
MASUK 2 6
MASUK 7 15
LAYANI
LAYANI
MASUK 8 100
LAYANI
LAYANI
```
### Contoh Output
```
1
7
8
2
```

### Code 

**Deklarasi Struct**
- `int id ` sebagai variabel id pasien
- `int priority` sebagai variabel prioritas pasien
```
typedef struct pqueueNode_t
{
    int id;
    int priority;
    struct pqueueNode_t *next;
} PQueueNode;

typedef struct pqueue_t
{
    PQueueNode *head;
    int _size;
} PQueue;
```

**PUSH**
- Membuat fungsi untuk memasukan data kedalam Struct
```
void push(PQueue *queue, int id, int priority)
{
    PQueueNode *newNode = new PQueueNode;
    newNode->id = id;
    newNode->priority = priority;
    newNode->next = NULL;

    if (queue->head == NULL)
    {
        queue->head = newNode;
    }
    else
    {
        PQueueNode *curr = queue->head;
        PQueueNode *prev = NULL;
        while (curr != NULL && curr->priority > priority)
        {
            prev = curr;
            curr = curr->next;
        }
        if (prev == NULL)
        {
            newNode->next = queue->head;
            queue->head = newNode;
        }
        else
        {
            prev->next = newNode;
            newNode->next = curr;
        }
    }
    queue->_size++;
}
```

**POP**
- Fungsi untuk mengapus tumpukan paling atas
```
void pop(PQueue *queue)
{
    if (queue->head == NULL)
    {
        return;
    }
    else
    {
        PQueueNode *curr = queue->head;
        queue->head = queue->head->next;
        int id = curr->id;
        delete curr;
        queue->_size--;
        return;
    }
}
```
**Print Top Queue**
- Fungsi untuk menyetak data dengan prioritas paling tinggi.
  
```
void printTopQueue(PQueue *queue)
{
    if (queue->head == NULL)
    {
        cout << "HORE" << endl;
    }
    else
    {
        cout << queue->head->id << endl;
    }
}
```
**Print Semua Queue {Optional}**
- Mencetak semua data yang berada dalam queue
```
void printQueue(PQueue *queue)
{
    PQueueNode *temp = queue->head;
    while (temp != NULL)
    {
        cout << temp->id << " ";
        cout << temp->priority << endl;
        temp = temp->next;
    }
    cout << endl;
}
```

**INIT**
- Inisialisasi  struct
```
void init(PQueue *queue)
{
    queue->head = NULL;
    queue->_size = 0;
}
```
**Get Order**
- Fungsi yang menerima inputan dari user dan meneruskan ke fungsi fungsi lainya.
- Format Perintah Masuk ``MASUK ID PRIORITY``
- ``LAYANI`` akan mencetak data pasien paling atas dan menghapusnya
- ``CETAK`` akan mencetak semua data pasien yang terdapat pada data
- Apabila perintah tidak ada dalam daftar diatas maka akan mencetak ``Perintah tidak dikenali``
```
void getOrder(PQueue *queue)
{
    char order[10];
    int id, priority;
    cin >> order;
    if (strcmp(order, "MASUK") == 0)
    {
        cin >> id >> priority;
        push(queue, id, priority);
    }
    else if (strcmp(order, "LAYANI") == 0)
    {
        printTopQueue(queue);
        pop(queue);
    }
    else if (strcmp(order, "CETAK") == 0)
    {
        printQueue(queue);
    }
    else
    {
        cout << " Perintah tidak dikenali" << endl;
    }
}
```

**Main**
```
int main()
{
    PQueue *pqueue = (PQueue *)malloc(sizeof(PQueue));
    init(pqueue);

    int N;
    cin >> N;
    while (N--)
    {
        getOrder(pqueue);
    }
    return 0;
}
```

---

## SOAL 3 : STACK

### Deskripsi Soal 
Modifikasilah program stack, queue, deque dan priority queue pada github untuk menyimpan tipe string dengan maksimum karakter adalah 100 karakter.

### Code

**Struct**
```
typedef struct stackNode_t
{
    char data;
    struct stackNode_t *next;
} stackNode;

typedef struct Stack_t
{
    stackNode *head;
    int _size;
} stack;
```

**Prototipe Fungsi**
```
bool isEmpty(stack *stack);
void init(stack *stack);
void push(stack *stack, char value);
void getString(stack *stack);
void printElement(stack *node);
```

**Init**
```
void init(stack *stack)
{
    stack->head = NULL;
    stack->_size = 0;
}
```

**isEmpty**
```
bool isEmpty(stack *stack)
{
    return stack->_size == 0;
}
```

**Push**
```
void push(stack *stack, char value)
{
    stackNode *node = new stackNode;
    node->data = value;
    node->next = NULL;
    if (stack->head == NULL)
    {
        stack->head = node;
    }
    else
    {
        stackNode *temp = stack->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
    }
    stack->_size++;
}
```

**printElement**
```
void printElement(stack *node)
{
    stackNode *temp = node->head;
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }
}
```

**getString**
```
void getString(stack *stack)
{
    char input[1000];
    cin.getline(input, 1000);
    int length = strlen(input);
    for (int i = 0; i < length; i++)
    {
        push(stack, input[i]);
    }
}
```

**Main**
```
int main()
{
    stack stack;
    init(&stack);
    getString(&stack);
    printElement(&stack);
    return 0;
}
```
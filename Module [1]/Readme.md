# Module [1]
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

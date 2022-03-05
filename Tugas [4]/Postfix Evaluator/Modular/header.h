/*
Nama        : Robby Ulung Pambudi
NRP         : 5025211042
Dibuat      : Jumat 04 Maret 2022
*/

// Deskripsi
/*
Diberikan sebuah sintah postfix yang selanjutnya sintak tersebut
akan menghasilakan nilai sesuai dengan sintak tersebut.
*/

// Problem
/*
Bagaimana cara untuk menghasilkan nilai dari sintak tersebut?
*/

// Analysis
/*
Membuat fungsi struct dengan tipe linkedlist,
Selanjutnya membuat fungsi untuk memparsing postfix tersebut
data yang didapatkan dari inputan akan dimasukkan ke dalam linkedlist
Selanjutnya fungsi parsing postfix akan memproses data dari linkedlist
sesuai dengan operator yang diberikan.
Cetak data terakhir dari linkedlist
Selesai.
*/

// Design
/*
1. Inisial Struct
2. Membuat fungsi parsing postfix.
3. Membuat fungsi untuk memproses data dari linkedlist. (Pop, Push, getTop)
4. Cetak data terakhir dari linkedlist.
*/

// Testing
/*
Diberikan sebuah data sebagai berikut
82/
27+5*
275*+
62-54+*
495–2*+
0

Dari data tersbut akan dihasilkan output seperti berikut
4
45
37
36
12

0 Adalah tanda bahwa program sudah selesai
*/

#include <stdio.h>  // Standar Input/Output
#include <stdlib.h> // Standar Library Malloc dan Free
#include <string.h> // Standar Library String

typedef struct SlinkedList_t
{
    int data;
    struct SlinkedList_t *next;
} SlinkedList; // Struct LinkedList

typedef struct SList_t
{
    SlinkedList *top;
    int _size;
} SList; // Struct List

// Prototpye
void init(SList *list);                        // Inisialisasi List
void push(SList *list, int data);              // Push data ke dalam list
int pop(SList *list);                          // Pop data dari list
void getTop(SList *list);                      // Cetak data terakhir dari list
void parsingPostfix(SList *list, char *input); // Parsing postfix

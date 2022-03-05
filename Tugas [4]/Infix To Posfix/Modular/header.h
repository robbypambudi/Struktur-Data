/*
Nama            : Robby Ulung Pambudi
NRP             : 5025211042
Tanggal Dibuat  : 05-03-2022
*/

// Deskripsi
/*
Diberikan sebuah sytak infix yang akan dirubah menjadi syntak postfix.
*/

// Problem
/*
Bagaiaman cara untuk merubah syntak dari infix ke postfix mengunakan
dengan mengunakan tipe data linked list supaya dapat menghasilkan output sintak infix.
*/

// Analysis
/*
Mengunakan linked list untuk menampung data syntak infix.
Mengunakan char of array untuk menapung data dari pengguna yang selanjutnya dimasukan kedalam linkedlist
mengunakan char of array untuk menampung data postfix dari hasil fungsi infixtopostfix.
Memodifikasi linked list sesuai dengan algoritma stack
mengunakan if else untuk menentukan (operator atau bukan) dan menambahkan data ke linked list
mengunakan if else untuk menentukan apakah itu digit atau alpha yang kemudian menambahkan ke dalam array postfix
membuat fungsi untuk menentukan apakah itu * / + -
karena setiap operator memiliki hak prioritas yang berbeda maka kita menggunakan fungsi presendence untuk menentukan prioritas
Seteleh proses selesai, maka akan di print array postfix
*/

// Design
/*
1. Membuat struct untuk linked list
2. Membuat fungsi init untuk inisialasi linked list
3. Membuat fungsi push untuk menambahkan data ke linked list
4. membuat fungsi pop dengan tipe data char untuk menghapus sekaligus mendapatkan
    data yang dihapus dari linked list
5 membuat fungsi is_opertor untuk menentukan apakah itu operator atau bukan.
6. membuat fungsi presendence untuk menentukan prioritas operator
7. membuat fungsi infixtopostfix untuk mengubah infix ke postfix
8. membuat fungsi main sebagai main progaram.
*/

// Input & Output
/*
Input :
    A+(((B-C)*(D-E)+F)/G)^(H-I)
Output :
    ABC-DE-*F+G/HI-^+
*/

#include <stdio.h>  // Library untuk input output
#include <string.h> // Library untuk memanipulasi string
#include <stdlib.h> // Library untuk memanipulasi memory
#include <ctype.h>  // Library untuk memanipulasi char

typedef struct SLinkedList_t
{
    char data;
    struct SLinkedList_t *next;
} SLinkedList; // Definisi tipe data linked list

typedef struct SList
{
    SLinkedList *top;
    int _size;
} List; // Definisi tipe data Linked List

// Prototipe Fungsi

void init(List *list);                                       // Inisialisasi Linked List
void push(List *list, char data);                            // Menambahkan data ke linked list
char pop(List *list);                                        // Menghapus data dari linked list
int is_operator(char data);                                  // Menentukan apakah itu operator atau bukan
int precedence(char data);                                   // Menentukan prioritas operator
void InfixtoPostfix(List *list, char *infix, char *postfix); // Mengubah infix ke postfix

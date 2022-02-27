/*
Dibuat Oleh : Robby Ulung Pambudi
NRP         : 5025211042
Tanggal     : 27-02-2022
*/

// Deskripsi
/*
    Diberikan sebuah data int secara acak yang akan dimasukan kedalam linked list
    yang akan diurutkan secara ascending.
*/

// Analysis
/*
    Diberikan sebuah data dari user yang akan dimasukan kedalam linked list.
    Data diurutkan dalam fungsi addInPlace.
    Fungsi addInPlace akan menambahkan data yang dimasukan kedalam linked list
    secara ascending.
    Fungsi printList akan menampilkan data yang ada di linked list.
    Fungsi makeNode akan membuat node baru.
    Fungsi main akan memanggil fungsi-fungsi yang telah dibuat.
*/

// Design
/*
    Membuat fungsi makeNode untuk membuat node baru.
    Membuat fungsi addInPlace untuk menambahkan node baru ke linked list.
    Membuat fungsi printList untuk mencetak linked list.
*/

// Testing
/*
    Input
    36 15 52 23 0
    Output
    15 23 36 52

*/

#include <stdio.h>  // Library  standar input dan output
#include <stdlib.h> // Library standar
typedef struct node
{
    int num;
    struct node *next;
} Node, *NodePtr; // Deklarasi tipe data Node dan NodePtr

// Function prototypes
NodePtr addInPlace(NodePtr top, int n); // Fungsi untuk menambahkan node baru ke linked list secara ascending
void printList(NodePtr np);             // Fungsi untuk mencetak linked list
NodePtr makeNode(int n);                // Fungsi untuk membuat node baru

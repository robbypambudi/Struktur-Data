/*
Dibuat Oleh : Robby Ulung Pambudi
NRP         : 5025211042
Tanggal     : 27-02-2022
*/

// Deskripsi
/*
    Program ini berisi program untuk mendapatkan ketua kelas dari suatu kelas yang memiliki data
    yang ditampung dalam linked list.
*/

// Problem
/*
    Diberikan sebuah data int yang kemudian ditambung dalam linked list.
    Dari data tersebut akan dipilih ketua kelas, proses pemilihan tersebut berdasarkan ketentuan yang berlaku
    Ketua kelas adalah mahasiswa terakhir yang berada pada linked List tersebut
*/

// Analysis
/*
    Secara mengamati soal tersebut maka linked list bisa dimodifkasi untuk mengapus data pada urutan tertentu
    yang diatur oleh logic program.
    setalah data hanya tersisa 1 maka data tersebut merupakan ketua kelas dan harus ditampilkan.
    Linked list diatur secara circle yaiutu data terakhir akan menunjuk kepada data pertama.
*/

// Design

/*
    - Membuat struct untuk linked list
    - Membuat fungsi untuk menambahkan data ke linked list
    - Membuat fungsi untuk menghapus data pada linked list
    - Membuat fungsi untuk menghapus data pada linked list pada urutan tertentu
    - Membuat fungsi untuk menampilkan data pada linked list
    - Membuat fungsi untuk mengatur data mana yang akan dihapus.

*/

#include <stdio.h>  // standar library untuk input output
#include <stdlib.h> // standar library untuk memanggil fungsi-fungsi yang ada di dalamnya

typedef struct CLinkedList_t
{
    int data;
    int id;
    struct CLinkedList_t *next;
} CLinkedList; // struct untuk linked list

typedef struct Clist_t
{
    CLinkedList *first;
    CLinkedList *last;
    int _size;

} Clist; // struct untuk linked list

extern int DATA_SIZE;

// Portotipe
void init(Clist *l);             // fungsi untuk menginisialisasi linked list
void push(Clist *l, int data);   // fungsi untuk menambahkan data ke linked list
void ketuaKelas(Clist *l);       // fungsi untuk mencari ketua kelas
void popAt(Clist *l, int index); // fungsi untuk menghapus data pada linked list
void printAll(Clist *l);         // fungsi untuk menampilkan data pada linked list
void popFirst(Clist *l);         // fungsi untuk menghapus data pada linked list pada urutan pertama
void popLast(Clist *l);          // fungsi untuk menghapus data pada linked list pada urutan terakhir
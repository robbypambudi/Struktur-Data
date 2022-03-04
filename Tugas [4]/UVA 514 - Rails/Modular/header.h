/*
Nama            : Robby Ulung Pambudi
NRP             : 5025211042
Tanggal Dibuat  : 04-03-2022
*/

// Deskripsi
/*
Terdapat Stasiun KA dengan dua jalur yaitu jalur datang dan jalur pergi.
KA pada jalur datang selalu berurutan, sedangkan jalur pergi sesuai dengan kebutuhan
- KA pada jalur datang bisa langsung pergi
- KA pada jalur datang bisa menunggu dulu di stasiun baru pergi.
- Urutan keberangkatan kereta adalah LIFO ( Last in First Out).
*/

// Problem
/*
Diberikan sebuah data yang berisi jalur pergi kereta antara stasiun KA.
Data tersebut berisikan urutan kereta saat mau keluar dari stasiun.
Selanjutnya program akan cek apakah kereta yang keluar dari stasiun KA
Sesuai dengan ketetuan dari soal atau tidak.
*/

// Analysis
/*
Cara yang dapat dilakukan untuk menyelesaikan masalah ini adalah dengan mengunakan stack.
Namun pada kali ini printah adalah mengunakan Linked List, oleh karena itu maka linked list
dibawah ini akan dimodifikasi untuk menjadi stack.
*/

// Input
/*
5
1 2 3 4 5
5 4 1 2 3
0
6
6 5 4 3 2 1
0
0
*/

// Output
/*
YES
NO
YES
*/

// Design
/*
1. Membuat struct LinkedList dengan tipe data int.
2. Membuat fungsi init dan push untuk menambahkan data ke linked list.
3. Membuat fungsi popFront untuk menghapus data dari linked list.
4. membuat fungsi solve dengan tipe data boolean sebagai fungsi untuk mengecek apakah
   kereta yang keluar dari stasiun KA sesuai dengan ketetuan atau tidak.
5. membuat fungsi uav514 dengan tipe data void sebagai fungsi kedua setelah main.
6. Membuat fungsi removeLinkedList untuk mengosongkan Linked list.
7. Membuat fungsi is_empty untuk mengecek apakah ada data dalam linkedlist atau tidak.
8. Membuat fungsi main dengan tipe data void sebagai fungsi pertama.
9. membuat fungsi printList *Optional* untuk menampilkan linked list.


*/

#include <stdio.h>   // Standar Input/Output
#include <stdlib.h>  // Standar Library untuk memanggil fungsi-fungsi yang ada di dalamnya (malloc, free, exit, ...)
#include <stdbool.h> // Standar Library untuk memanggil fungsi-fungsi yang ada di dalamnya (bool, true, false, ...)

typedef struct SListNode
{
    int data;
    struct SListNode *next;
} ListNode; // struct untuk linked list

typedef struct SList
{
    ListNode *top;
    int _size;

} List; // Struct untuk Linked List

void init(List *list);                       // Membuat fungsi init untuk membuat linked list
void pushFront(List *list, int data);        // Membuat fungsi pushFront untuk menambahkan data ke linked list
void popFront(List *list);                   // Membuat fungsi popFront untuk menghapus data dari linked list
bool solve(List *list, int *arr, int train); // Membuat fungsi solve untuk mengecek apakah kereta yang keluar dari stasiun KA sesuai dengan ketetuan atau tidak.
void removeLinkedList(List *list);           // Membuat fungsi removeLinkedList untuk mengosongkan linked list
void uav514(List *list, int train);          // Membuat fungsi uav514 untuk menjalankan program utama
void printList(List *list);                  // Membuat fungsi printList untuk menampilkan linked list
bool is_empty(List *list);                   // Membuat fungsi is_empty untuk mengecek apakah ada data dalam linkedlist atau tidak.
int getTop(List *list);                      // Membuat fungsi getTop untuk mengembalikan nilai top dari list (jika list kosong maka return -1)

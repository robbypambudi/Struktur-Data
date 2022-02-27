/*
Dibuat oleh : Robby Ulung Pambudi
NRP         : 5025211042
Tanggal     : 27-02-2022
*/

// Deskripsi
/*
    Deberikan dua buah linked list yang diisi dengan angka-angka yang diberikan oleh user.
    Kemudian lakukan penggabungan dari kedua linked list tersebut.
    Kemudian tampilkan hasil penggabungan dari kedua linked list tersebut secara terurut.
*/

// Analysis
/*
    Dalam membuat program ini kita menggunakan algoritma merge sort.
    Algoritma merge sort adalah algoritma yang digunakan untuk mengurutkan data secara ascending.
    Kemudian diterapakan dalam structur data Linked List sebagai berikut
*/

// Design
/*
    Pada bagian ini kita akan membuat structur data Linked List.
    Kemudian kita akan membuat fungsi-fungsi yang akan digunakan untuk membuat linked list.
    Kemudian kita akan membuat fungsi-fungsi yang akan digunakan untuk menggabungkan dua linked list.
    Kemudian kita akan membuat fungsi-fungsi yang akan digunakan untuk menampilkan linked list.
*/

#include <stdio.h>  // Standard Library untuk membaca dan menulis data
#include <stdlib.h> // Standard Library untuk membuat data
typedef struct node
{
    int num;           // data yang akan dimasukkan ke dalam linked list
    struct node *next; // pointer yang akan menunjuk ke node berikutnya
} Node, *NodePtr;      // struct node digunakan untuk menyimpan data dan pointer untuk menyimpan alamat data

// Prototipe Fungsi
NodePtr makeNode(int n);             // Membuat node baru
NodePtr makeList(void);              // Membuat linked list
NodePtr merge(NodePtr A, NodePtr B); // Menggabungkan dua linked list
void printList(NodePtr np);          // Menampilkan linked list

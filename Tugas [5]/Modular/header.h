/*
Nama    : Robby Ulung Pambudi
NRP     : 5025211042
Tanggal : 12 Maret 2022
*/

// Deskripsi
/*
    Diberikan sebuah testcase yang didalamnya terdapat n buah bilangan bulat.
    dengan proiritas yang berbeda beda, masing-masing bilangan tersebut
    akan diproses sesuai dengan urutan tertinggi ke terendah.
    Untuk setiap proses akan memerlukan waktu 1 detik
    dan tugas yang dikerjakan adalah menghitung jumlah waktu yang dibutuhkan
*/

// Penyelesaian
/*
    Memasukan data dengan urutan tertinggi ke terendah berdasarkan prioritas yang diberikan
    selanjutnya memberikan nilai true pada variabel letak saat memasukan user berada.
    Progran akan menghitung waktu yang dibutuhkan untuk menyelesaikan tugas dengan cara
    menghapus satu per satu data sampai menemukan letak == true.
*/
#include <stdlib.h>  // Library untuk memanggil fungsi malloc()
#include <stdbool.h> // Library untuk memanggil fungsi bool
#include <stdio.h>   // Library untuk memanggil fungsi printf()

typedef struct pqueueNode_t
{
    int data;                  // data
    bool letak;                // Untuk mengetahui letak dari user
    struct pqueueNode_t *next; // Pointer ke next node
} PQueueNode;

typedef struct pqueue_t
{
    PQueueNode *_top; // Pointer ke node paling atas
    unsigned _size;   // Ukuran queue
} PriorityQueue;      // Nama struct

// Fungsi Prototype
void pqueue_init(PriorityQueue *pqueue);                        // Membuat PriorityQueue kosong
bool pqueue_isEmpty(PriorityQueue *pqueue);                     // Mengecek apakah PriorityQueue kosong
void pqueue_push(PriorityQueue *pqueue, int value, bool letak); // Menambahkan data ke dalam PriorityQueue
void pqueue_pop(PriorityQueue *pqueue);                         // Menghapus data teratas dari PriorityQueue
int pqueue_top(PriorityQueue *pqueue);                          // Mengembalikan nilai teratas dari PriorityQueue
void pqueue_print(PriorityQueue *pqueue);                       // Menampilkan isi PriorityQueue
int solve(PriorityQueue *pqueue);                               // Solve
void pqueue_RemoveAll(PriorityQueue *pqueue);                   // Menghapus semua data dari PriorityQueue

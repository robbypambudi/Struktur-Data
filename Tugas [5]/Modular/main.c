/*

Nama        : Robby Ulung Pambudi
NRP         : 5025211042
Tanggal     : 12 Maret 2020

*/

#include "header.h" // Header file

int main()
{
    PriorityQueue pqueue; // Deklarasi variabel pqueue
    pqueue_init(&pqueue); // Memanggil fungsi pqueue_init() untuk membuat PriorityQueue kosong
    int N;                // Deklarasi variabel N
    printf("Masukkan banyak test case: ");
    scanf("%d", &N); // Input banyak data
    while (N--)
    {                   // Loop sebanyak N
        int job, letak; // Deklarasi variabel job dan letak
        printf("Masukkan banyak job dan letak contoh -> (1 2): ");
        scanf("%d %d", &job, &letak); // Input banyak job dan letak

        // Error handeling
        if (job < 0 || letak < 0 || letak > job)
        { // Jika job < 0 atau letak < 0 atau letak > job maka tampilkan error
            printf("Input tidak valid\n");
            printf("job atau letak tidak boleh kurang dari 0 atau letak tidak boleh lebih dari job\n");
            return 0;
        }

        int data; // Deklarasi variabel data
        printf("Masukkan data: ");
        for (int i = 0; i < job; i++)
        { // Loop sebanyak job

            scanf("%d", &data);
            if (letak == i)
            {                                     // Jika letak = i maka masukkan data ke dalam pqueue
                pqueue_push(&pqueue, data, true); // Memanggil fungsi pqueue_push() untuk menambahkan data ke dalam pqueue
                continue;                         // Kembali ke loop selanjutnya
            }
            pqueue_push(&pqueue, data, false); // Memanggil fungsi pqueue_push() untuk menambahkan data ke dalam pqueue
        }
        int time = solve(&pqueue); // Memanggil fungsi solve() untuk menyelesaikan tugas
        if (time != -1)
        {
            printf("Waktu : %d\n", time); // Jika time tidak kosong maka tampilkan waktu
        }
        else
        {
            printf("Waktu : Invailid\n"); // Jika time kosong maka tampilkan -1
        }
        pqueue_print(&pqueue); // Memanggil fungsi pqueue_print() untuk menampilkan isi pqueue

        puts("------------------------------\n");
        pqueue_RemoveAll(&pqueue); // Memanggil fungsi pqueue_RemoveAll() untuk menghapus semua data dari pqueue
    }
    return 0;
}
/*

Nama        : Robby Ulung Pambudi
NRP         : 5025211042
Tanggal     : 12 Maret 2020

*/

#include "header.h" // Header file
void reverse(PriorityQueue *pqueue)
{
    PQueueNode *temp = pqueue->_top; // Deklarasi variabel temp
    PQueueNode *prev = NULL;         // Deklarasi variabel prev
    PQueueNode *next = NULL;         // Deklarasi variabel next

    while (temp != NULL)
    {                      // Perulangan selama temp != NULL
        next = temp->next; // next = temp->next
        temp->next = prev; // temp->next = prev
        prev = temp;       // prev = temp
        temp = next;       // temp = next
    }
    pqueue->_top = prev; // pqueue->_top = prev
}

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
        // check data is all same or not
        bool same = true;               // Deklarasi variabel same
        PQueueNode *temp = pqueue._top; // Deklarasi variabel temp
        while (temp->next != NULL)
        {
            if (temp->data != temp->next->data)
            { // Jika temp->data != temp->next->data maka same = false
                same = false;
                break;
            }
            temp = temp->next; // temp = temp->next
        }
        if (same)
        {
            pqueue_print(&pqueue); // Memanggil fungsi pqueue_print() untuk menampilkan isi pqueue
            reverse(&pqueue);      // Memanggil fungsi reverse() untuk membalikkan data
            pqueue_print(&pqueue); // Memanggil fungsi pqueue_print() untuk menampilkan isi pqueue
        }
        int time = solve(&pqueue); // Memanggil fungsi solve() untuk menyelesaikan tugas

        if (time != -1)
        {
            printf("Waktu : %d\n", time); // Jika time tidak kosong maka tampilkan waktu
        }
        else
        {
            printf("Waktu : 1\n"); // Jika time kosong maka tampilkan -1
        }
        // pqueue_print(&pqueue); // Memanggil fungsi pqueue_print() untuk menampilkan isi pqueue

        puts("------------------------------\n");
        pqueue_RemoveAll(&pqueue); // Memanggil fungsi pqueue_RemoveAll() untuk menghapus semua data dari pqueue
    }
    return 0;
}
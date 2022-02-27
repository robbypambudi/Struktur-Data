#include "header.h"

int main()
{
    Clist L;        // membuat linked list
    init(&L);       // menginisialisasi linked list
    ketuaKelas(&L); // Menjalankan fungsi untuk mendapatkan ketua kelas

    printf("Ketua Kelas : ");
    printAll(&L); // menampilkan data ketua kelas
    printf("\n");

    return 0;
}
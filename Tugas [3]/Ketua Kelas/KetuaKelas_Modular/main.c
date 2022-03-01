#include "header.h"

int DATA_SIZE = 1;
int main()
{
    int N;           // banyaknya node
    scanf("%d", &N); // input banyaknya node
    Clist L[N];      // membuat array list
    int i = 0;       // counter
    while (N--)
    {                      // looping untuk banyaknya node
        init(&L[i]);       // membuat node baru
        ketuaKelas(&L[i]); // memanggil fungsi ketuaKelas

        printf("@\n");   //   @
        printAll(&L[i]); // print semua node
        i++;             // counter
        DATA_SIZE = 1;   // reset DATA_SIZE
    }
    return 0;
}
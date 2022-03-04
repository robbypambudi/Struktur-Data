#include "header.h"

void uav514(List *list, int train)
{
    int arr[1001];
    int out;
    scanf("%d", &out); // Input kereta keluar
    while (out != 0)
    {                 // Selama kereta keluar tidak 0
        arr[0] = out; // Masukkan kereta keluar ke arr[0]
        for (int i = 1; i < train; i++)
        {
            scanf("%d", &arr[i]); // Masukkan kereta ke arr[i]
        }
        if (solve(list, arr, train))
        {
            printf("YES\n"); // Jika kereta keluar dapat ditempatkan
        }
        else
        {
            printf("NO\n"); // Jika kereta keluar tidak dapat ditempatkan
        }
        removeLinkedList(list); // Hapus list
        scanf("%d", &out);      // Input kereta keluar
    }
}
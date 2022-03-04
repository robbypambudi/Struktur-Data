#include "header.h"

bool solve(List *list, int *arr, int train)
{
    int now = 1; // Jumlah kereta yang sedang ditempati
    for (int i = 0; i < train; i++)
    { // Perulangan sebanyak jumlah kereta
        if (is_empty(list) && now <= train)
        {                         // Jika list kosong dan jumlah kereta yang sedang ditempati kurang dari jumlah kereta
            pushFront(list, now); // Masukkan kereta yang sedang ditempati ke list
            now++;                // Jumlah kereta yang sedang ditempati ditambah 1
        }
        while (getTop(list) != arr[i])
        {                         // Selama kereta yang ada di top tidak sama dengan kereta pada arr[i]
            pushFront(list, now); // Masukkan kereta yang akan menempati ke list
            now++;                // Jumlah kereta yang sedang ditempati ditambah 1
            if (now > train + 1)
            {                 // Jika jumlah kereta yang sedang ditempati lebih dari jumlah kereta + 1 maka kereta tidak dapat ditempatkan
                return false; // Kembalikan false
            }
        }
        popFront(list); // Hapus kereta yang terdepan dari list
    }
    return true; // Kembalikan true
}
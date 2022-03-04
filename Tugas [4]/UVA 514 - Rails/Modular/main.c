#include "header.h"

int main()
{
    List list;   // Deklarasi list
    init(&list); // Inisialisasi list

    int train; // Jumlah Kereta
    while (1)
    {
        scanf("%d", &train); // Input jumlah kereta
        if (train == 0)
        { // Jika jumlah kereta 0 maka break
            break;
        }
        uav514(&list, train); // Proses
    }
    return 0;
}
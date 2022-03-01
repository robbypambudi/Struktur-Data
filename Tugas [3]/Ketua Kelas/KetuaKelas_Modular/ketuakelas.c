#include "header.h" // menambahkan header

void ketuaKelas(Clist *l)
{

    int n, lompat;               // variabel untuk lompat
    scanf("%d %d", &n, &lompat); // input banyaknya node dan lompat

    // Masukan Data kedalam Linked List
    for (int i = 1; i <= n; i++)
    {               // looping untuk banyaknya node
        push(l, i); // memasukan data ke linked list
    }
    // printOut(l->_size, lompat);

    // Poling Data
    int i = 1;           // counter
    int temp = 1;        // variabel untuk lompat
    int N = 1;           // counter
    int size = l->_size; // variabel untuk size
    while (l->_size != 1)
    {
        temp += lompat; // menambahkan lompat ke variabel temp

        // printf("%d temp", temp);
        if (temp > l->_size)
        {
            temp -= l->_size; // jika temp lebih besar dari size maka temp dikurangi size
        }
        if (l->_size == 2 && temp == 2)
        {
            temp = 1; // jika size = 2 dan temp = 2 maka temp = 1
        }

        if (temp == 1)
        {
            if (l->_size == 2 && (size % 2 == 0))
            {
                popLast(l); // jika size = 2 dan temp = 1 maka popLast
            }
            else
            {
                popFirst(l); // jika size = 2 dan temp = 1 maka popFirst
            }
        }
        else if (temp == l->_size)
        {

            popLast(l);
        }
        else
        {
            popAt(l, temp - 2);
        }
        N += 1;
        // printf("N = %d\n", N);
        if (N > l->_size && temp > N)
        {
            N -= 1; //
        }

        else if (N > l->_size && temp < N)
        {
            N -= l->_size; // jika N lebih besar dari size maka N dikurangi size
        }
        temp = N;
    }
}
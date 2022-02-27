#include "header.h" // menambahkan header

void ketuaKelas(Clist *l)
{
    int n, lompat;               // n untuk menghitung jumlah data, lompat untuk menghitung jumlah data yang akan dilompat
    scanf("%d %d", &n, &lompat); // membaca inputan

    // Masukan Data kedalam Linked List
    for (int i = 0; i < n; i++)
    {
        int data;           // data untuk menyimpan data
        scanf("%d", &data); // membaca data
        push(l, data);      // memasukan data ke dalam linked list
    }

    // Poling Data
    int i = 1;           // i untuk menghitung jumlah data yang telah dilompat
    int temp = 1;        // temp untuk menghitung data yang akan dilompat
    int N = 1;           // Variabel Pembantu untuk menghitung jumlah data yang telah dilompat
    int size = l->_size; // Variabel Pembantu untuk menghitung jumlah data yang ada
    while (l->_size != 1)
    {
        temp += lompat; // menambahkan lompat ke variabel temp

        // Logika agar data yang diproses sesuai dengan data yang ada
        if (temp > l->_size)
        {
            temp -= l->_size;
        }
        // Logika agar data yang diproses sesuai dengan data yang ada
        if (l->_size == 2 && temp == 2)
        {
            temp = 1;
        }

        // Logika untuk menghapus data yang telah dilompat
        if (temp == 1)
        {
            if (l->_size == 2 && (size % 2 == 0))
            {
                popLast(l);
            }
            else
            {
                popFirst(l);
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

        // Logika untuk memproses data yang telah dilompat
        N += 1;

        // Logika agar data yang diproses sesuai dengan data yang ada
        if (N > l->_size && temp > N)
        {
            N -= 1;
        }

        // Logika agar data yang diproses sesuai dengan data yang ada
        else if (N > l->_size && temp < N)
        {
            N -= l->_size;
        }
        temp = N; // mengisi variabel temp dengan nilai N
    }
}
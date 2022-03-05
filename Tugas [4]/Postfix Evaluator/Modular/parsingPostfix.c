#include "header.h"

void parsingPostfix(SList *list, char *input)
{
    // printf("%lu\n", strlen(input));
    int size = strlen(input); // Menghitung jumlah karakter input
    for (int i = 0; i < size; i++)
    { // Melakukan perulangan sebanyak jumlah karakter input
        if (input[i] >= '0' && input[i] <= '9')
        { // Jika input[i] adalah angka maka push input[i] ke list
            int angka = input[i] - '0';
            push(list, angka);
        }
        else
        { // Jika input[i] bukan angka maka melakukan operasi
            int op1, op2;
            op2 = pop(list); // Menghapus data paling atas dari list
            op1 = pop(list); // Menghapus data paling atas dari list
            switch (input[i])
            { // Melakukan operasi sesuai dengan input[i]
            case '+':
                push(list, op1 + op2);
                break;
            case '-':
                push(list, op1 - op2);
                break;
            case '*':
                push(list, op1 * op2);
                break;
            case '/':
                push(list, op1 / op2);
                break;
            }
        }
    }
    getTop(list); // Menampilkan data paling atas dari list
}
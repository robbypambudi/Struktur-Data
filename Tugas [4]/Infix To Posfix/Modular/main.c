#include "header.h"

// Fungsi main disni hanya menginisalisasi memory yang akan digunakan
// Kemudian memory diparsing ke fungsi" selanjutnya untuk digunakan.
int main()
{
    List list;                             // Membuat list kosong
    init(&list);                           // Memanggil fungsi init untuk membuat list kosong
    char infix[1001], postfix[1001];       // Membuat array untuk menyimpan infix dan postfix
    gets(infix);                           // Membaca input infix
    InfixtoPostfix(&list, infix, postfix); // Memanggil fungsi InfixtoPostfix untuk mengkonversi infix ke postfix
    puts(postfix);                         // Menampilkan hasil postfix

    return 0;
}
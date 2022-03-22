#include "header.h"

int main()
{
    BST set;        // Deklarasi BST
    bst_init(&set); // Inisialisasi BST

    printf("Masukan Banyak data : "); // Input banyak data
    int N;
    scanf("%d", &N); // Input banyak data
    printf("Masukan Data :");
    while (N--)
    {                           // Input data
        int data;               // Deklarasi variabel data
        scanf("%d", &data);     // Input data
        bst_insert(&set, data); // Input data
    }

    bst_print(&set); // Print BST
}
#include "header.h"

int main()
{
    BST set;
    bst_init(&set);

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

    bst_print(&set);
    puts("----------------------");
    puts("Deleted Min Node");
    bst_delMinNode(&set);
    bst_print(&set);
    puts("----------------------");
    puts("Deleted Max Node");
    bst_delMaxNode(&set);
    bst_print(&set);
    puts("----------------------");
    puts("Deleted Root Node");
    bst_delRoot(&set);
    bst_print(&set);
}
// Robby Ulung Pambudi
// 5025211042
// Main program for modular postfix evaluator

#include "header.h"

int main()
{
    SList list;  // Deklarasi list
    init(&list); // Inisialisasi list

    char input[100]; // Deklarasi input
    printf("Masukan Input : ");
    scanf("%s", input); // Input input

    while (strlen(input) > 1)
    {                                 // Selama input lebih dari 1
        printf("Hasil : ");           // Print hasil
        parsingPostfix(&list, input); // Parsing input
        printf("Masukan Input : ");
        scanf("%s", input); // Input input
    }
}
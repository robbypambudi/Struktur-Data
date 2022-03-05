// Robby Ulung Pambudi
// 5025211042
// Main program for modular postfix evaluator

#include "header.h"

int main()
{
    SList list;  // Deklarasi list
    init(&list); // Inisialisasi list

    char input[100];    // Deklarasi input
    scanf("%s", input); // Input input

    while (strlen(input) > 1)
    {                                 // Selama input lebih dari 1
        parsingPostfix(&list, input); // Parsing input
        scanf("%s", input);           // Input input
    }
}
#define MaxWordSize 30
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

// Mengambil input kata
int getWord(FILE *in, char str[], int *line, int *cor)
{
    char temp;
    int n = 0;
    temp = getc(in);

    while (temp != EOF)
    {
        if (temp == '\n')
        {
            *line += 1;
        }
        if (isalpha(temp))
        {
            break;
        }
        temp = getc(in);
    }

    if (temp == EOF)
    {
        return 0;
    }
    str[n++] = tolower(temp);
    while (isalpha(temp = getc(in)) && temp != EOF)
    {
        if (n < MaxWordSize)
            str[n++] = tolower(temp);
    }
    str[n] = '\0';

    if (temp == '\n')
    {
        *cor = 1;
    }

    return 1;
}

int main()
{
    FILE *fp;
    int line = 1;
    int correction = 0;
    char word[MaxWordSize];
    char str[MaxWordSize];
    fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("File tidak dapat dibuka");
        exit(1);
    }
    while (getWord(fp, str, &line, &correction) != 0)
    {
        printf("%s\n", str);
    }
}
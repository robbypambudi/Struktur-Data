#include "header.h"

int getWord(FILE *in, char str[])
{
    // stores the next word, if any, in str; word is converted to lowercase
    // returns 1 if a word is found; 0, otherwise
    char ch;
    int n = 0;
    // read over non-letters
    while (!isalpha(ch = getc(in)) && ch != EOF)
        ; // empty while body
    if (ch == EOF)
        return 0;
    str[n++] = tolower(ch);
    while (isalpha(ch = getc(in)) && ch != EOF)
        if (n < MaxWordSize)
            str[n++] = tolower(ch);
    str[n] = '\0';
    return 1;
} // end getWord
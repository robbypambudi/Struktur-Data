#include "header.h"

int is_operator(char data)
{ // Fungsi untuk mengecek apakah data merupakan operator atau bukan (1 = true, 0 = false)
    if (data == '+' || data == '-' || data == '*' || data == '/' || data == '^')
    {
        return 1;
    }

    return 0;
}
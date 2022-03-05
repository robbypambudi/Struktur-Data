#include "header.h"

int precedence(char data)
{ // Fungsi untuk menghitung precedence dari operator
    if (data == '^')
    { // Operator ^ memiliki precedence tertinggi
        return 3;
    }
    else if (data == '*' || data == '/')
    { // Operator * dan / memiliki precedence yang sama dan memiliki nilai 2
        return 2;
    }
    else if (data == '+' || data == '-')
    { // Operator + dan - memiliki precedence yang sama dan memiliki nilai 1
        return 1;
    }

    return 0;
}
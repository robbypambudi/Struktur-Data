#include "header.h"

void InfixtoPostfix(List *list, char *infix, char *postfix)
{ // Fungsi untuk mengubah infix menjadi postfix
    int i, j;
    char item;
    char x;
    push(list, '(');    // Memasukkan '(' pada linked list
    strcat(infix, ")"); // Menambahkan ')' pada infix
    i = 0;
    j = 0;
    item = infix[i]; // variabel item menyimpan data dari infix[i]

    while (item != '\0')
    { // Selama item tidak sama dengan '\0' maka akan dilakukan perulangan
        if (item == '(')
        { // Jika item sama dengan '(' maka push item ke linked list
            push(list, item);
        }
        else if (isdigit(item) || isalpha(item))
        { // Jika item adalah number atau huruf maka akan postfik akan ditambahi dengan item
            postfix[j] = item;
            j++;
        }
        else if (is_operator(item) == 1)
        { // Jika item adalah operator maka data linked list pertama akan dihapus
            x = pop(list);

            while (is_operator(item) == 1 && precedence(x) >= precedence(item))
            {                   // Selama item adalah operator dan precedence x lebih besar dari precedence item maka akan dilakukan perulangan
                postfix[j] = x; // postfix akan ditambahkan dengan data x
                j++;
                x = pop(list); // data x akan sama dengan data yang pertama dihapus dari linked list
            }
            push(list, x);    // data x akan ditambahkan ke linked list
            push(list, item); // item akan ditambahkan ke linked list
        }
        else if (item == ')')
        { // Jika item sama dengan ')' maka data linked list pertama akan dihapus
            x = pop(list);

            while (x != '(')
            {                   // Selama x tidak sama dengan '(' maka akan dilakukan perulangan
                postfix[j] = x; // postfix akan ditambahkan dengan data x
                j++;
                x = pop(list); // data x akan sama dengan data yang pertama dihapus dari linked list
            }
        }
        else
        { // Jika lain maka perintah invalid
            printf("Invalid Input\n");
            return;
        }
        i++;             // i akan bertambah 1
        item = infix[i]; // item akan sama dengan data infix[i]
    }
    if (list->_size != 0)
    { // Jika linked list size tidak sama dengan 0 maka akan jalan perintah invalid
        printf("Invalid Input\n");
        return;
    }
    postfix[j] = '\0'; // postfix akan ditambahkan dengan '\0'
}
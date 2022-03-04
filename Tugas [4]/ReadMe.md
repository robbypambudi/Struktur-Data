# Tugas [4]
- [Tugas [4]](#tugas-4)
  - [Soal 1 : UVA 514 Rails](#soal-1--uva-514-rails)
    - [Deskripsi](#deskripsi)
    - [Code](#code)
  - [Soal 2 : Postfix Evaluator](#soal-2--postfix-evaluator)
    - [Deskripsi](#deskripsi-1)
    - [Input](#input)
    - [Output](#output)
    - [Code](#code-1)
  - [Soal 3 : Infix to Postfix](#soal-3--infix-to-postfix)
    - [Deskripsi](#deskripsi-2)
    - [Code](#code-2)

## Soal 1 : UVA 514 Rails 

### Deskripsi
Terdapat Stasiun KA dengan dua jalur yaitu jalur datang dan jalur pergi.
KA pada jalur datang selalu berurutan, sedangkan jalur pergi sesuai dengan kebutuhan
- KA pada jalur datang bisa langsung pergi
- KA pada jalur datang bisa menunggu dulu di stasiun baru pergi.
- Urutan keberangkatan kereta adalah LIFO ( Last in First Out).

### Code
- [Klik disini untuk melihat Modular Code](https://github.com/robbypambudi/Struktur-Data/tree/main/Tugas%20%5B4%5D/UVA%20514%20-%20Rails)

```
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct SListNode
{
    int data;
    struct SListNode *next;
} ListNode;

typedef struct SList
{
    ListNode *top;
    int _size;

} List;

void init(List *list);
void pushFront(List *list, int data);
void popFront(List *list);
bool solve(List *list, int *arr, int train);
void removeLinkedList(List *list);
void printList(List *list);
bool is_empty(List *list);

void init(List *list)
{
    list->top = NULL;
    list->_size = 0;
}

bool is_empty(List *list)
{
    return list->top == NULL;
}

void pushFront(List *list, int data)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->data = data;
    newNode->next = list->top;
    list->top = newNode;
    list->_size++;
}

void removeLinkedList(List *list)
{
    ListNode *current = list->top;
    while (current != NULL)
    {
        ListNode *temp = current;
        current = current->next;
        free(temp);
    }
    list->top = NULL;
    list->_size = 0;
}

void popFront(List *list)
{
    if (is_empty(list))
    {
        return;
    }
    ListNode *temp = list->top;
    list->top = list->top->next;
    free(temp);
    list->_size--;
}

int getTop(List *list)
{
    return list->top->data;
}
bool solve(List *list, int *arr, int train)
{
    int now = 1;
    for (int i = 0; i < train; i++)
    {
        if (is_empty(list) && now <= train)
        {
            pushFront(list, now);
            now++;
        }
        while (getTop(list) != arr[i])
        {
            pushFront(list, now);
            now++;
            if (now > train + 1)
            {
                return false;
            }
        }
        popFront(list);
    }
    return true;
}

void uav514(List *list, int train)
{
    int arr[1001];
    int out;
    scanf("%d", &out);
    while (out != 0)
    {
        arr[0] = out;
        for (int i = 1; i < train; i++)
        {
            scanf("%d", &arr[i]);
        }
        if (solve(list, arr, train))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        removeLinkedList(list);
        scanf("%d", &out);
    }
}

int main()
{
    List list;
    init(&list);

    int train;
    while (1)
    {
        scanf("%d", &train);
        if (train == 0)
        {
            break;
        }
        uav514(&list, train);
    }
    return 0;
}
```

## Soal 2 : Postfix Evaluator

### Deskripsi 
**Contoh sintaks postfix**

- `82/ = 8/2 = 4` 
- `27+5* = (2+7) * 5 = 45`
- `275*+ = 2 + 7*5 = 37`
- `62–54+* = ( 6 – 2 ) * ( 5 + 4 ) = 36`
- `495–2*+ = 4 + (9-5)*2 = 12`

Operand maksimal 9 (1 digit)

Input 0 berarti program selesai

Asumsi sintaks benar, tidak ada spasi

### Input 
```
82/
27+5*
275*+
62-54+*
495–2*+
0
```

### Output
```
4
45
37
36
12
```

### Code
- [Klik disini untuk melihat modular code](https://github.com/robbypambudi/Struktur-Data/tree/main/Tugas%20%5B4%5D/Postfix%20Evaluator)

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SlinkedList_t
{
    int data;
    struct SlinkedList_t *next;
} SlinkedList;

typedef struct SList_t
{
    SlinkedList *top;
    int _size;
} SList;

// Prototpye
void init(SList *list);
void push(SList *list, int data);
int pop(SList *list);

// Function

void init(SList *list)
{
    list->top = NULL;
    list->_size = 0;
}
void push(SList *list, int data)
{

    SlinkedList *newNode = (SlinkedList *)malloc(sizeof(SlinkedList));
    newNode->data = data;
    newNode->next = list->top;
    list->top = newNode;
    list->_size++;
}
int pop(SList *list)
{
    if (list->_size == 0)
    {
        return -1;
    }
    SlinkedList *temp = list->top;
    list->top = list->top->next;
    list->_size--;
    int data = temp->data;
    free(temp);
    return data;
}
void getTop(SList *list)
{
    if (list->_size == 0)
    {
        return;
    }
    else
    {
        printf("%d\n", list->top->data);
    }
}
void parsingPostfix(SList *list, char *input)
{
    // printf("%lu\n", strlen(input));
    int size = strlen(input);
    for (int i = 0; i < size; i++)
    {
        if (input[i] >= '0' && input[i] <= '9')
        {
            int angka = input[i] - '0';
            push(list, angka);
        }
        else
        {
            int op1, op2;
            op2 = pop(list);
            op1 = pop(list);
            switch (input[i])
            {
            case '+':
                push(list, op1 + op2);
                break;
            case '-':
                push(list, op1 - op2);
                break;
            case '*':
                push(list, op1 * op2);
                break;
            case '/':
                push(list, op1 / op2);
                break;
            }
        }
    }
    getTop(list);
}

int main()
{
    SList list;
    init(&list);

    char input[100];
    scanf("%s", input);

    while (strlen(input) > 1)
    {
        parsingPostfix(&list, input);
        scanf("%s", input);
    }
}
```
## Soal 3 : Infix to Postfix

### Deskripsi
Translasi ekspresi dalam bentuk infix ke bentuk postfix.

### Code
- [Klik disini untuk melihat modular code](https://github.com/robbypambudi/Struktur-Data/tree/main/Tugas%20%5B4%5D/Infix%20To%20Posfix)
```
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct SLinkedList_t
{
    char data;
    struct SLinkedList_t *next;
} SLinkedList;

typedef struct SList
{
    SLinkedList *top;
    int _size;
} List;

// Portotipe
void init(List *list);
void push(List *list, char data);
// Function
void init(List *list)
{
    list->top = NULL;
    list->_size = 0;
}
void push(List *list, char data)
{
    SLinkedList *newNode = (SLinkedList *)malloc(sizeof(SLinkedList));
    newNode->data = data;
    newNode->next = list->top;
    list->top = newNode;
    list->_size++;
}

char pop(List *list)
{
    if (list->_size == 0)
    {
        return -1;
    }
    SLinkedList *temp = list->top;
    list->top = list->top->next;
    list->_size--;
    char data = temp->data;
    free(temp);
    return data;
}

int is_operator(char data)
{
    if (data == '+' || data == '-' || data == '*' || data == '/' || data == '^')
    {
        return 1;
    }

    return 0;
}

int precedence(char data)
{
    if (data == '^')
    {
        return 3;
    }
    else if (data == '*' || data == '/')
    {
        return 2;
    }
    else if (data == '+' || data == '-')
    {
        return 1;
    }

    return 0;
}

void InfixtoPostfix(List *list, char *infix, char *postfix)
{
    int i, j;
    char item;
    char x;
    push(list, '(');
    strcat(infix, ")");
    i = 0;
    j = 0;
    item = infix[i];

    while (item != '\0')
    {
        if (item == '(')
        {
            push(list, item);
        }
        else if (isdigit(item) || isalpha(item))
        {
            postfix[j] = item;
            j++;
        }
        else if (is_operator(item) == 1)
        {
            x = pop(list);

            while (is_operator(item) == 1 && precedence(x) >= precedence(item))
            {
                postfix[j] = x;
                j++;
                x = pop(list);
            }
            push(list, x);
            push(list, item);
        }
        else if (item == ')')
        {
            x = pop(list);

            while (x != '(')
            {
                postfix[j] = x;
                j++;
                x = pop(list);
            }
        }
        else
        {
            printf("Invalid Input\n");
            return;
        }
        i++;
        item = infix[i];
    }
    if (list->_size != 0)
    {
        printf("Invalid Input\n");
        return;
    }
    postfix[j] = '\0';
}

int main()
{
    List list;
    init(&list);
    char infix[1001], postfix[1001];
    gets(infix);
    InfixtoPostfix(&list, infix, postfix);
    puts(postfix);

    return 0;
}
```

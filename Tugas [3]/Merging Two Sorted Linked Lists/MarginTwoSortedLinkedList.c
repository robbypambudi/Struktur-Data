#include <stdio.h>  // Standard Library untuk membaca dan menulis data
#include <stdlib.h> // Standard Library untuk membuat data
typedef struct node
{
    int num;           // data yang akan dimasukkan ke dalam linked list
    struct node *next; // pointer yang akan menunjuk ke node berikutnya
} Node, *NodePtr;      // struct node digunakan untuk menyimpan data dan pointer untuk menyimpan alamat data

// Prototipe Fungsi
NodePtr makeNode(int n);             // Membuat node baru
NodePtr makeList(void);              // Membuat linked list
NodePtr merge(NodePtr A, NodePtr B); // Menggabungkan dua linked list
void printList(NodePtr np);          // Menampilkan linked list

int main()
{

    NodePtr A, B; // deklarasi pointer A dan B
    printf("Enter numbers for the first list (0 to end)\n");
    A = makeList(); // memanggil fungsi makeList untuk membuat list A
    printf("Enter numbers for the second list (0 to end)\n");
    B = makeList(); // memanggil fungsi makeList untuk membuat list B
    printf("\nThe merged list is\n");
    printList(merge(A, B)); // memanggil fungsi merge untuk menggabungkan list A dan B
} // end main

NodePtr makeList()
{
    NodePtr makeNode(int), np, top, last; // deklarasi pointer np, top, last
    int n;                                // deklarasi variabel n
    top = NULL;                           // inisialisasi top dengan NULL
    if (scanf("%d", &n) != 1)             // jika tidak ada input
        n = 0;                            // maka n = 0
    while (n != 0)
    {                             // selama n bukan 0
        np = makeNode(n);         // create a new node containing n
        if (top == NULL)          // if the list is empty
            top = np;             // set top if first node
        else                      // otherwise
            last->next = np;      // set last -> next for other nodes
        last = np;                // update last to new node
        if (scanf("%d", &n) != 1) // jika tidak ada input
            n = 0;                // maka n = 0
    }
    return top; // return the top of the list
} // end makeList

NodePtr makeNode(int n)
{
    NodePtr np = (NodePtr)malloc(sizeof(Node)); // allocate memory for a new node
    np->num = n;                                // Set variabel num di dalam node dengan n
    np->next = NULL;                            // Set variabel next di dalam node dengan NULL
    return np;                                  // return the new node
} // end makeNode

NodePtr merge(NodePtr A, NodePtr B)
{
    NodePtr C = NULL, last = NULL; // deklarasi pointer C dan last
    // check if either A or B is empty
    if (A == NULL) // jika A kosong
        return B;  // return B
    if (B == NULL) // jika B kosong
        return A;  // return A
    // both lists are non-empty
    while (A != NULL && B != NULL)
    { // as long as there's a node in A and B
        if (A->num < B->num)
        {                       //  Jika A < B
            if (C == NULL)      // if C is empty
                C = A;          // set C to A
            else                // Jika C tidak kosong
                last->next = A; // set last -> next to A
            last = A;           // update last to A
            A = A->next;        // update A to A -> next
        }
        else
        {                       // A >= B
            if (C == NULL)      // Jika C kosong
                C = B;          // set C to B
            else                // Jika C tidak kosong
                last->next = B; // set last -> next to B
            last = B;           // update last to B
            B = B->next;        // update B to B -> next
        }
    }                   // end while
    if (A == NULL)      // jika A kosong
        last->next = B; // set last -> next to B
    else                // jika A tidak kosong
        last->next = A; // set last -> next to A
    return C;           // return C
} // end merge

void printList(NodePtr np)
{
    while (np != NULL)
    {                           // as long as there's a node
        printf("%d ", np->num); // print the number
        np = np->next;          // go on to the next node
    }
    printf("\n\n"); // print a new line
} // end printList
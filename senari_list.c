#include <stdio.h>
#include <string.h>

typedef struct
{
    char nim[10]; // Memory 23 Bit
    char nama[10];
    char nilai[3];
} nilaiMatkul;

typedef struct
{
    nilaiMatkul kontainer; // 23 Bit
    int next;              // 4 bit
} elemen;                  // Harusnya 27 tetapi muncul 28

typedef struct
{
    int first;         // Memory = 4 bit
    elemen data[1000]; // elemen 28 * 10 = 280
} list;                // 280 + 4

void createList(list *L)
{
    L->first = -1;
    int i;

    for (i = 0; i <= 1000; i++)
    {
        L->data[i].next = -2;
    }
}

int countElements(list L)
{
    int hasil = 0;
    if (L.first != -1)
    {
        int bantu;
        bantu = L.first;

        while (bantu != -1)
        {
            hasil += 1;
            bantu = L.data[bantu].next;
        }
    }
    return hasil;
}

int emptyElements(list L)
{
    int hasil = -1;
    if (countElements(L) < 1000)
    {
        int ketemu = 0;
        int i = 0;
        while ((ketemu == 0) && (i <= 1000))
        {
            if (L.data[i].next == -2)
            {
                hasil = i;
                ketemu = 1;
            }
            else
            {
                i += 1;
            }
        }
    }
    return hasil;
}

void addFirst(char nim[], char nama[], char nilai[], list *L)
{
    if (countElements(*L) < 1000)
    {
        int baru = emptyElements(*L);
        strcpy(L->data[baru].kontainer.nim, nim);
        strcpy(L->data[baru].kontainer.nama, nama);
        strcpy(L->data[baru].kontainer.nilai, nilai);

        if (L->first == -1) // Jika data kosong
        {
            L->data[baru].next = -1;
        }
        else // Jika data tidak kosong
        {
            L->data[baru].next = L->first;
        }
        L->first = baru;
    }
    else
    {
        printf("Data Sudah Penuh\n");
    }
}

void addAfter(int prev, char nim[], char nama[], char nilai[], list *L)
{
    if ((countElements(*L) < 1000) && (prev != -1))
    {
        int baru = emptyElements(*L);
        strcpy(L->data[baru].kontainer.nim, nim);
        strcpy(L->data[baru].kontainer.nama, nama);
        strcpy(L->data[baru].kontainer.nilai, nilai);

        if (L->data[prev].next == -1) // Jika Prev adalah elemen terakhir
        {
            L->data[baru].next = -1;
        }
        else
        {
            L->data[baru].next = L->data[prev].next;
        }
        L->data[prev].next = baru;
    }
    else
    {
        printf("Data sudah penuh\n");
    }
}

void addLast(char nim[], char nama[], char nilai[], list *L)

{
    if (L->first == -1)
    { // JIKA LIST MASIH KOSONG
        addFirst(nim, nama, nilai, L);
    }
    else
    {
        // Jika list pertama sudah diisi
        // cari elemen terakhir
        int last = L->first;
        while (L->data[last].next != -1)
        {
            last = L->data[last].next;
        }
        addAfter(last, nim, nama, nilai, L);
    }
}

void delFirst(list *L)

{
    if (L->first != -1)
    {
        int hapus = L->first;

        if (countElements(*L) == 1)
        {
            L->first = -1;
        }
        else
        {
            L->first = L->data[L->first].next;
        }
        L->data[hapus].next = -2;
    }
    else
    {
        printf("Data Kosong\n");
    }
}

void delAfter(int prev, list *L)
{
    if (prev != -1)
    {
        int hapus = L->data[prev].next;

        if (hapus != -1)
        {
            if (L->data[hapus].next == -1)
            {
                L->data[prev].next = -1;
            }
            else
            {
                L->data[prev].next = L->data[hapus].next;
            }
            // Pengosongan Elements
            L->data[hapus].next = -2;
        }
    }
}

void delLast(list *L)
{
    if (L->first != -1)
    {
        if (countElements(*L) == 1)
        {
            // Jika elemen hanya terdiri dari 1 baris
            delFirst(L);
        }
        else
        {
            int last = L->first;
            int beforelast;

            while (L->data[last].next != -1)
            {
                beforelast = last;
                last = L->data[last].next;
            }
            // Elemen sebelum elemen terakhir
            delAfter(beforelast, L);
        }
    }
    else
    {
        printf("Data Kosong\n");
    }
}

void printElements(list L)
{
    if (L.first != -1)
    {
        int bantu = L.first;
        int i = 1;
        while (bantu != -1)
        {
            printf("Elemen ke \t: %d\n", i);
            printf("Nim \t\t: %s\n", L.data[bantu].kontainer.nim);
            printf("Nama \t\t: %s\n", L.data[bantu].kontainer.nama);
            printf("Nilai \t\t: %s\n", L.data[bantu].kontainer.nilai);
            printf("Next \t\t: %d\n", L.data[bantu].next);
            printf("--------------------------------\n");

            bantu = L.data[bantu].next;
            i = i + 1;
        }
    }
    else
    {
        printf("list kosong\n");
    }
}

int main()
{
    list L;
    createList(&L);
    char perintah[20];
    char nim[15], nama[15], nilai[5];
    while (1)
    {
        scanf("%s", perintah);

        if (strcmp(perintah, "ADDFIRST") == 0)
        {
            scanf(" %s %s %s", nim, nama, nilai);
            addFirst(nim, nama, nilai, &L);
            printf("Data Telah Ditambahakan Ke Baris Pertama\n");
        }
        else if (strcmp(perintah, "ADDAFTER") == 0)
        {
            scanf(" %s %s %s", nim, nama, nilai);
            addAfter(L.first, nim, nama, nilai, &L);
            printf("Data Telah Ditambahakan Ke Baris Setelah Pertama\n");
        }
        else if (strcmp(perintah, "ADDLAST") == 0)
        {
            scanf(" %s %s %s", nim, nama, nilai);
            addLast(nim, nama, nilai, &L);
            printf("Data Telah Ditambahakan Ke Baris Terakhir\n");
        }
        else if (strcmp(perintah, "DELFIRST") == 0)
        {
            delFirst(&L);
            printf("Data Pertama Telah Dihapus\n");
        }
        else if (strcmp(perintah, "DELAFTER") == 0)
        {
            delAfter(L.first, &L);
            printf("Data After telah dihapus\n");
        }
        else if (strcmp(perintah, "DELLAST") == 0)
        {
            delLast(&L);
            printf("Data Terakhir Telah dihapus\n");
        }
        else if (strcmp(perintah, "PRINT") == 0)
        {
            printElements(L);
        }
        else if (strcmp(perintah, "EXIT") == 0)
        {
            break;
        }
    }

    return 0;
    // Debug
    // createList
    printf("%d", L.first);
    for (int i = 0; i < 1000; i++)
        printf("%d", L.data[i].next);
}
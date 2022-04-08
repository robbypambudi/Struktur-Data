#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MaxHeapSize 100000
void siftUp(int[], int);

void heapSort(FILE *in)
{
    int num[MaxHeapSize + 1];
    int n = 0, number;
    while (fscanf(in, "%d", &number) == 1)
    {
        if (n < MaxHeapSize)
        { // check if array has room
            num[++n] = number;
            siftUp(num, n);
        }
        else
        {
            printf("\nArray too small\n");
            exit(1);
        }
    }
    // for (int h = 1; h <= n; h++)
    //     printf("%d ", num[h]);
    // printf("\n");
}

int main()
{
    // Setting Time start
    FILE *out;
    FILE *fp;
    out = fopen("output.txt", "w");
    clock_t start = clock();
    // Untuk Input 10 Number
    fp = fopen("input10.txt", "r");
    heapSort(fp);
    fclose(fp);
    // Time end
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    fprintf(out, "1.\t10 data diporeleh waktu \t:");
    fprintf(out, "\t %f ms\n", time_spent);

    // Setting Time start
    start = clock();
    // Untuk Input 100 Number
    fp = fopen("input100.txt", "r");
    heapSort(fp);
    fclose(fp);
    // Time end
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    fprintf(out, "2.\t100 data diporeleh waktu \t:");
    fprintf(out, "\t %f ms\n", time_spent);

    // Setting Time start
    start = clock();
    // Untuk Input 1000 Number
    fp = fopen("input1000.txt", "r");
    heapSort(fp);
    fclose(fp);
    // Time end
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    fprintf(out, "3.\t1000 data diporeleh waktu \t:");
    fprintf(out, "\t %f ms\n", time_spent);

    // Setting Time start
    start = clock();
    // Untuk Input 10000 Number
    fp = fopen("input10000.txt", "r");
    heapSort(fp);
    fclose(fp);
    // Time end
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    fprintf(out, "4.\t10000 data diporeleh waktu \t:");
    fprintf(out, "\t %f ms\n", time_spent);

    // Setting Time start
    start = clock();
    // Untuk Input 100000 Number
    fp = fopen("input100000.txt", "r");
    heapSort(fp);
    fclose(fp);
    // Time end
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    fprintf(out, "5.\t100000 data diporeleh waktu :");
    fprintf(out, "\t %f ms\n", time_spent);
    fclose(out);

    return 0;

} // end main

void siftUp(int heap[], int n)
{
    // sifts up the value in heap[n] so that heap[1..n] contains a heap
    int siftItem = heap[n];
    int child = n;
    int parent = child / 2;
    while (parent > 0)
    {
        if (siftItem <= heap[parent])
            break;
        heap[child] = heap[parent]; // move down parent
        child = parent;
        parent = child / 2;
    }
    heap[child] = siftItem;
} // end siftUp

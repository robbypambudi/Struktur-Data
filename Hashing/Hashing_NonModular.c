/**
 * @file PercobaanHashing.c
 * @author RobbyPambudi
 * @brief
 * @version 0.1
 * @date 2022-05-25
 *
 * @copyright Copyright (c) 2022
 *
 */

/*
Problem
Saya masi mendapatkan data 40 ganda dalam numbers.out
yang seharausnya adalah 40 unik.
 */

// implement hashing with chaining is to use a single array and use array subscripts as links
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 13
#define Empty 0
#define MaxItems 100
typedef struct node
{
    int num;  // key
    int next; // array subscript of the next item in the list
} Node;

Node hash[MaxItems + 1];

int H(int key)
{
    return key % N + 1;
}

int main()
{
    FILE *in = fopen("numbers.in", "r");
    FILE *out = fopen("numbers.out", "w");

    for (int i = 1; i <= MaxItems; i++)
    {
        hash[i].num = 0;
        hash[i].next = 0;
    }
    int curr;
    int prev;
    int f = 14;
    int num;

    while (fscanf(in, "%d", &num) != EOF)
    {

        int k = H(num);
        if (hash[k].num == Empty)
        {
            hash[k].num = num;
            hash[k].next = -1;
        }
        else
        {
            if (hash[k].next == -1 && hash[k].num != num)
            {
                hash[f].num = num;
                hash[f].next = hash[k].next;
                hash[k].next = f;
            }
            else if (hash[k].next == -1 && hash[k].num == num)
                continue;

            else
            {
                bool sat = false;
                int curr = hash[k].next;
                while (hash[curr].next != -1)
                {
                    if (hash[curr].num == num)
                    {
                        sat = true;
                        break;
                    }
                    curr = hash[curr].next;
                }
                if (sat)
                    continue;

                hash[curr].next = f;
                hash[f].num = num;
                hash[f].next = -1;
            }
            f += 1;
        }
    }
    for (int i = 1; i <= MaxItems; i++)
    {
        printf("hash[%d] = %d -> hash{next} = %d\n", i, hash[i].num, hash[i].next);
    }
    // PRint hash
    for (int i = 1; i <= 13; i++)
    {
        if (hash[i].num != -1)
        {
            fprintf(out, "hash[%d]: ", i);
            fprintf(out, " %d", hash[i].num);
            int curr = hash[i].next;
            while (curr != -1)
            {
                fprintf(out, " %d", hash[curr].num);
                curr = hash[curr].next;
            }

            fprintf(out, "\n");
        }
    }
    fclose(in);
    fclose(out);
}
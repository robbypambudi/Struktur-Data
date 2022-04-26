#include "dft.h"

void print_outDegree(GraphPtr G)
{
    puts("Out-degree:"); // print the vertex names
    int i, j;            // loop counters
    GEdgePtr ep;         // edge pointer

    for (i = 1; i <= G->numV; i++)
    {                                    // print the vertex names
        printf("%s: ", G->vertex[i].id); // Cetak vertex
        ep = G->vertex[i].firstEdge;     // Mendapatkan pointer ke edge pertama
        while (ep != NULL)
        {
            printf("%s ", G->vertex[ep->child].id); // Cetak vertex
            ep = ep->nextEdge;                      // Mendapatkan pointer ke edge berikutnya
        }
        printf("\n"); // Cetak enter
    }
}
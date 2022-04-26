#include "dft.h"

void print_inDegree(GraphPtr G)
{
    puts("In-degree:"); // Cetak "In-degree:"
    int i, j, k;        // loop counters
    GEdgePtr ep;        // edge pointer

    for (i = 1; i <= G->numV; i++)
    {
        printf("%s: ", G->vertex[i].id); // Cetak vertex
        for (j = 1; j <= G->numV; j++)
        {                                // print the vertex names
            ep = G->vertex[j].firstEdge; // Mendapatkan pointer ke edge pertama
            while (ep != NULL)
            { // print the vertex names
                if (ep->child == i)
                { // Cetak vertex
                    printf("%s ", G->vertex[j].id);
                    break;
                }
                ep = ep->nextEdge; // Mendapatkan pointer ke edge berikutnya
            }
        }
        printf("\n");
    }
}
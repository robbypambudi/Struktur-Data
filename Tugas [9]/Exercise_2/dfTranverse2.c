#include "dft.h"

void dfTraverse2(GraphPtr G, int s)
{
    static int time = 0; // retains its value between calls
    GEdgePtr edge;

    G->vertex[s].colour = Gray;
    G->vertex[s].discover = ++time;
    edge = G->vertex[s].firstEdge;
    while (edge != NULL)
    {
        if (G->vertex[edge->child].colour == White)
        {
            printf("Tree edge :  %s -> %s\n", G->vertex[s].id, G->vertex[edge->child].id);
            G->vertex[edge->child].parent = s;
            dfTraverse(G, edge->child);
        }
        else
        {
            // when the parent node is traversed after the neighbour node
            if (G->vertex[edge->child].colour == Gray && G->vertex[s].discover < G->vertex[edge->child].discover)
            {
                printf("Back edge :  %s -> %s\n", G->vertex[s].id, G->vertex[edge->child].id);
            }
            else if (G->vertex[edge->child].colour == Gray && G->vertex[s].discover > G->vertex[edge->child].discover)
            {
                printf("Forward edge :  %s -> %s\n", G->vertex[s].id, G->vertex[edge->child].id);
            }
            else
            {
                printf("Cross edge :  %s -> %s\n", G->vertex[s].id, G->vertex[edge->child].id);
            }
        }
        edge = edge->nextEdge;
    }
    G->vertex[s].colour = Black;
    G->vertex[s].finish = ++time;
} // end dfTraverse

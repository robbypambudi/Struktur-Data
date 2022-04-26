#include "dft.h"

void printGraph(GraphPtr G)
{
	int j;
	GEdgePtr p;

	for (j = 1; j <= G->numV; j++)
	{
		printf("%s:", G->vertex[j].id);
		p = G->vertex[j].firstEdge;
		while (p != NULL)
		{
			printf(" %s %d", G->vertex[p->child].id, p->weight);
			p = p->nextEdge;
		}
		printf("\n");
	}
} // end printGraph

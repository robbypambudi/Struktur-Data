//#include "graph.h"
#include "dft.h"

void printPath(GraphPtr G, char D[])
{
	int j;
	/* find D in the list of nodes (location j) */
	for (j = 1; j <= G->numV; j++)
		if (strcmp(D, G->vertex[j].id) == 0)
			break;
	if (j > G->numV)
		printf("\nNo such node %s\n", D);
	else
	{
		printf("\nPath to %s: ", D);
		followPath(G, j);
		printf("\n");
	}
} /* end printPath */

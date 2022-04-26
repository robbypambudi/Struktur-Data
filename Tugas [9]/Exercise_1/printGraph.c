#include "dft.h"

void printGraph(GraphPtr G)
{
	int j; // loop counter

	printf("Print Verteks: ");

	for (j = 1; j <= G->numV; j++)
	{ // print the vertex names
		printf("%s ", G->vertex[j].id);
	}
} // end printGraph

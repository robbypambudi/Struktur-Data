#include "dft.h"

void depthFirstTraversal(GraphPtr G, int s)
{
	// do a depth first traversal of G starting from vertex s
	int j;

	for (j = 1; j <= G->numV; j++)
	{
		G->vertex[j].colour = White;
		G->vertex[j].parent = 0;
	}
	printf("\nDepth-first traversal starting from %s\n", G->vertex[s].id);
	dfTraverse(G, s); // start traversal from s
	// check if any White vertices remain; if so, start another traversal
	for (j = 1; j <= G->numV; j++)
		if (G->vertex[j].colour == White)
			dfTraverse(G, j);
	printf("\n");

	// do a depth first traversal of G starting from vertex s
	for (j = 1; j <= G->numV; j++)
	{
		G->vertex[j].colour = White;
		G->vertex[j].parent = 0;
	}

	dfTraverse2(G, s); // start traversal from s
					   // // check if any White vertices remain; if so, start another traversal
					   // // for (j = 1; j <= G->numV; j++)
					   // // 	if (G->vertex[j].colour == White)
					   // // 		dfTraverse2(G, j);
					   // printf("\n");

} // end depthFirstTraversal

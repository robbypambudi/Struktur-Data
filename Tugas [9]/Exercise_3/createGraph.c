
#include "header.h"
Graph *createGraph(int Vertices)
{
	// inisiasi graph
	Graph *g = (Graph *)malloc(sizeof(Graph));

	// inisiasi jumlah vertices
	g->Vertices = Vertices;

	// inisiasi array dengan ukuran sebanyak vertices
	g->array = (Ajlist *)malloc(Vertices * sizeof(Ajlist));

	// inisiasi array visited sebanyak vertices
	g->visitedBFT = (int *)malloc(Vertices * sizeof(int));
	g->visitedDFT = (int *)malloc(Vertices * sizeof(int));

	int i;

	// inisiasi adjacency list
	for (i = 0; i < Vertices; ++i)
	{
		g->array[i].head = NULL;

		g->visitedBFT[i] = 0;
		g->visitedDFT[i] = 0;
	}
	return g;
}

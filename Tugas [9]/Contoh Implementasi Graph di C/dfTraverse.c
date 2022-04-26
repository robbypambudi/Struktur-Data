#include "dft.h"

void dfTraverse(GraphPtr G, int s)
{
	static int time = 0; // retains its value between calls
	GEdgePtr edge;

	printf("%s ", G->vertex[s].id);
	G->vertex[s].colour = Gray;
	G->vertex[s].discover = ++time;
	edge = G->vertex[s].firstEdge;
	while (edge != NULL)
	{
		if (G->vertex[edge->child].colour == White)
		{
			G->vertex[edge->child].parent = s;
			dfTraverse(G, edge->child);
		}
		edge = edge->nextEdge;
	}
	G->vertex[s].colour = Black;
	G->vertex[s].finish = ++time;
} // end dfTraverse

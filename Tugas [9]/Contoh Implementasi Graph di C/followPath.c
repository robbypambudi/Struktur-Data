/*#include "graph.h"*/
#include "dft.h"
//#include "dijkstra.h"

void followPath(GraphPtr G, int c)
{
	int j;
	if (G->vertex[c].parent == 0)
		printf("%s ", G->vertex[c].id);
	else
	{
		followPath(G, G->vertex[c].parent);
		printf("%s ", G->vertex[c].id);
	}
} /* end followPath */

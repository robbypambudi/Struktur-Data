/*#include "graph.h"*/
#include "dft.h"
//#include "dijkstra.h"

void followPath(GraphPtr G, int c) {
	if(c != 0) {
		followPath(G, G->vertex[c].parent);
		printf("%s ", G->vertex[c].id);
	}
} /* end followPath */


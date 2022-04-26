#include "dft.h"

int main()
{
	int numVertices;
	GraphPtr G;
	FILE *in = fopen("graph3.in", "r");

	fscanf(in, "%d", &numVertices);
	G = newGraph(numVertices);
	buildGraph(in, G);
	depthFirstTraversal(G, 4);

	fclose(in);

	return 0;
} // end main
